#pragma once

#include <QMainWindow>

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
};

}
