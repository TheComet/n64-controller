#include "n64c/DeviceSettings.hpp"
#include "n64c/ui_DeviceSettings.h"

namespace n64c {

// ----------------------------------------------------------------------------
DeviceSettings::DeviceSettings(QWidget* parent) :
    QWidget(parent),
    ui_(new Ui::DeviceSettings)
{
    ui_->setupUi(this);
}

// ----------------------------------------------------------------------------
DeviceSettings::~DeviceSettings()
{
    delete ui_;
}

}
