#pragma once

#include <QMainWindow>

class QMdiArea;

namespace Ui {
    class MainWindow;
}

namespace n64c {

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent=nullptr);
    ~MainWindow();

private:
    Ui::MainWindow* ui_;
    QMdiArea* mdiArea_;
};

}
