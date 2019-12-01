#pragma once

#include <QMainWindow>

class QMdiArea;
class QMdiSubWindow;

namespace Ui {
    class MainWindow;
}

namespace n64c {

class ContextPaneUser;
class ToolsPane;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent=nullptr);
    ~MainWindow();

public slots:
    void newProfile();
    void openControllerPakTool();

private slots:
    void onSubWindowActivated(QMdiSubWindow* subWindow);
    void onProfileColorChanged(QColor color);
    void onProfileNameChanged(QString name);

private:
    int findTabBarIndexForSubWindowWidget(QObject* w) const;

private:
    Ui::MainWindow* ui_;
    QMdiArea* mdiArea_;
    ToolsPane* toolsPane_;
    ContextPaneUser* activeContextPaneUser_;
};

}
