#include "n64c/DeviceSettings.hpp"
#include "n64c/MainWindow.hpp"
#include "n64c/ui_MainWindow.h"

#include <QMdiArea>
#include <QToolBar>
#include <QDockWidget>
#include <QHBoxLayout>

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
    mdiArea_(new MdiAreaWithBackgroundImage)
{
    ui_->setupUi(this);
    setLayout(new QHBoxLayout);
    
    mdiArea_->setViewMode(QMdiArea::TabbedView);
    mdiArea_->setTabsClosable(true);
    mdiArea_->setTabsMovable(true);
    
    QToolBar* toolbar = new QToolBar;
    layout()->addWidget(toolbar);
    
    QDockWidget* dockWidget = new QDockWidget;
    DeviceSettings* deviceSettings = new DeviceSettings;
    dockWidget->setWidget(deviceSettings);
    dockWidget->setObjectName("dock");
    addDockWidget(Qt::LeftDockWidgetArea, dockWidget, Qt::Vertical);
    toolbar->addAction(dockWidget->toggleViewAction());
}

// ----------------------------------------------------------------------------
MainWindow::~MainWindow()
{
    delete ui_;
}

}
