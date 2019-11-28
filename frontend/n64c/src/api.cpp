#include "n64c/api.h"
#include "n64c/MainWindow.hpp"

#include <QApplication>

int n64c_run_gui(int argc, char** argv)
{
    QApplication app(argc, argv);
    n64c::MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}
