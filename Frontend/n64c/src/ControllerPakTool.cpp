#include "n64c/ControllerPakTool.hpp"
#include "n64c/ui_ControllerPakTool.h"

namespace n64c {

// ----------------------------------------------------------------------------
ControllerPakTool::ControllerPakTool(QWidget* parent) :
    QWidget(parent),
    ui_(new Ui::ControllerPakTool)
{
    ui_->setupUi(this);
}

// ----------------------------------------------------------------------------
ControllerPakTool::~ControllerPakTool()
{
    delete ui_;
}

}
