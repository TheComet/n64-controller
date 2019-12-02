#pragma once

#include "nodes/NodeDataModel"

namespace n64c {

class BooleanData;
class FloatData;

using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeValidationState;
using QtNodes::PortIndex;
using QtNodes::PortType;

class N64ControllerInputDataModel : public QtNodes::NodeDataModel
{
    Q_OBJECT

public:
    unsigned nPorts(PortType portType) const override;
    NodeDataType dataType(PortType portType, PortIndex portIndex) const override;
    std::shared_ptr<NodeData> outData(PortIndex port) override;
    void setInData(std::shared_ptr<NodeData> data, PortIndex portIndex) override;
    QWidget* embeddedWidget() override;
    NodeValidationState validationState() const override;
    QString validationMessage() const override;
    QString caption() const override;
    QString name() const override;

private:
    std::shared_ptr<BooleanData> buttonA_;
    std::shared_ptr<BooleanData> buttonB_;
    std::shared_ptr<BooleanData> buttonCUp_;
    std::shared_ptr<BooleanData> buttonCDown_;
    std::shared_ptr<BooleanData> buttonCLeft_;
    std::shared_ptr<BooleanData> buttonCRight_;
    std::shared_ptr<BooleanData> buttonDUp_;
    std::shared_ptr<BooleanData> buttonDDown_;
    std::shared_ptr<BooleanData> buttonDLeft_;
    std::shared_ptr<BooleanData> buttonDRight_;
    std::shared_ptr<BooleanData> buttonL_;
    std::shared_ptr<BooleanData> buttonR_;
    std::shared_ptr<BooleanData> buttonS_;
    std::shared_ptr<BooleanData> buttonZ_;
    std::shared_ptr<FloatData> joyX_;
    std::shared_ptr<FloatData> joyY_;
};

}
