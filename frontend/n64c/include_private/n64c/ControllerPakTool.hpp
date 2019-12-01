#pragma once

#include <QWidget>

namespace Ui {
    class ControllerPakTool;
}

namespace n64c {

class ControllerPakTool : public QWidget
{
    Q_OBJECT

public:
    explicit ControllerPakTool(QWidget* parent=nullptr);
    ~ControllerPakTool();

private:
    Ui::ControllerPakTool* ui_;
};

}
