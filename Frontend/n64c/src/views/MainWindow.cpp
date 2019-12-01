#include "n64c/views/ControllerPakTool.hpp"
#include "n64c/views/DeviceSettings.hpp"
#include "n64c/views/ToolsPane.hpp"
#include "n64c/views/MainWindow.hpp"
#include "n64c/ui_MainWindow.h"
#include "n64c/views/ProfileView.hpp"

#include <QMdiArea>
#include <QToolBar>
#include <QDockWidget>
#include <QHBoxLayout>
#include <QTabWidget>
#include <QMdiSubWindow>
#include <QTabBar>

namespace n64c {

class MdiAreaWithBackgroundImage : public QMdiArea
{
public:
    explicit MdiAreaWithBackgroundImage(QWidget* parent = 0) : QMdiArea(parent)
    {
        setBackground(QBrush(QColor(190, 190, 190)));
    }
protected:
    virtual void paintEvent(QPaintEvent* e) override
    {
        QMdiArea::paintEvent(e);
/*
        QPainter painter(viewport());
        QPixmap pixmap = QPixmap(":/background/welcome.png").scaled(size(), Qt::KeepAspectRatio);
        painter.drawPixmap((size().width() - pixmap.width()) / 2, 0, pixmap);*/
    }
};

// ----------------------------------------------------------------------------
MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui_(new Ui::MainWindow),
    mdiArea_(new MdiAreaWithBackgroundImage),
    toolsPane_(new ToolsPane),
    activeContextPaneUser_(nullptr)
{
    ui_->setupUi(this);

    // Mdi area where multiple profile views can be loaded and edited
    mdiArea_->setViewMode(QMdiArea::TabbedView);
    mdiArea_->setTabsClosable(true);
    mdiArea_->setTabsMovable(true);
    setCentralWidget(mdiArea_);

    // Holds buttons for showing/hiding the different left-sided panes
    QToolBar* toolbar = new QToolBar;
    toolbar->setMovable(false);
    toolbar->setFloatable(false);
    addToolBar(Qt::LeftToolBarArea, toolbar);

    // Tools pane
    QDockWidget* dockWidget = new QDockWidget;
    dockWidget->setWidget(toolsPane_);
    dockWidget->setFeatures(QDockWidget::DockWidgetClosable);
    addDockWidget(Qt::LeftDockWidgetArea, dockWidget, Qt::Vertical);
    QAction* action = dockWidget->toggleViewAction();
    action->setText("Tools");
    toolbar->addAction(action);

    toolsPane_->addWidget(new DeviceSettings);

    connect(mdiArea_, SIGNAL(subWindowActivated(QMdiSubWindow*)), this, SLOT(onSubWindowActivated(QMdiSubWindow*)));
    connect(ui_->action_newProfile, SIGNAL(triggered()), this, SLOT(newProfile()));
    connect(ui_->action_controllerPakTool, SIGNAL(triggered()), this, SLOT(openControllerPakTool()));

    openControllerPakTool();
    newProfile();
    newProfile();
}

// ----------------------------------------------------------------------------
MainWindow::~MainWindow()
{
    delete ui_;
}

// ----------------------------------------------------------------------------
void MainWindow::newProfile()
{
    QWidget* dummy = new QWidget;
    QMdiSubWindow* dummyWindow = mdiArea_->addSubWindow(dummy);

    ProfileView* newProfileView = new ProfileView(toolsPane_);
    QMdiSubWindow* newSubWindow = mdiArea_->addSubWindow(newProfileView);
    newSubWindow->showMaximized();

    connect(newProfileView, SIGNAL(profileColorChanged(QColor)), this, SLOT(onProfileColorChanged(QColor)));
    connect(newProfileView, SIGNAL(profileNameChanged(const QString&)), this, SLOT(onProfileNameChanged(QString)));

    newProfileView->loadDefaultSettings();

    dummyWindow->close();
}

// ----------------------------------------------------------------------------
void MainWindow::openControllerPakTool()
{
    if (mdiArea_->findChild<ControllerPakTool*>())
        return;

    ControllerPakTool* controllerPakTool = new ControllerPakTool;
    QMdiSubWindow* subWindow = mdiArea_->addSubWindow(controllerPakTool);
    subWindow->showMaximized();
}

// ----------------------------------------------------------------------------
void MainWindow::onSubWindowActivated(QMdiSubWindow* subWindow)
{
    if (activeContextPaneUser_)
    {
        activeContextPaneUser_->onViewDeactivated();
        activeContextPaneUser_ = nullptr;
    }

    if (subWindow)
    {
        activeContextPaneUser_ = qobject_cast<ContextPaneUser*>(subWindow->widget());
        if (activeContextPaneUser_)
            activeContextPaneUser_->onViewActivated();
    }
}

// ----------------------------------------------------------------------------
void MainWindow::onProfileColorChanged(QColor color)
{
    QTabBar* tabBar = mdiArea_->findChild<QTabBar*>();
    tabBar->setTabTextColor(findTabBarIndexForSubWindowWidget(sender()), color);
}

// ----------------------------------------------------------------------------
void MainWindow::onProfileNameChanged(QString name)
{
    if (name.isEmpty())
        name = "Untitled Profile";

    QTabBar* tabBar = mdiArea_->findChild<QTabBar*>();
    tabBar->setTabText(findTabBarIndexForSubWindowWidget(sender()), name);
}

// ----------------------------------------------------------------------------
int MainWindow::findTabBarIndexForSubWindowWidget(QObject* w) const
{
    int index = 0;
    for (const auto& subWindow : mdiArea_->subWindowList())
    {
        if (subWindow->widget() == w)
            return index;
        index++;
    }
    return -1;
}

}
