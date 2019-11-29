#pragma once

#include <QWidget>

namespace Ui {
    class DeviceSettings;
}

namespace n64c {
    
class DeviceSettings : public QWidget
{
    Q_OBJECT
    
public:
    explicit DeviceSettings(QWidget* parent=nullptr);
    ~DeviceSettings();
    
private:
    Ui::DeviceSettings* ui_;
};

}
