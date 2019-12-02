#include "n64c/models/nodes/N64ControllerInputDataModel.hpp"
#include "n64c/models/nodes/BooleanData.hpp"
#include "n64c/models/nodes/FloatData.hpp"

namespace n64c {

// ----------------------------------------------------------------------------
unsigned N64ControllerInputDataModel::nPorts(PortType portType) const
{
    switch (portType)
    {
        case PortType::Out : return 16;
        default : return 0;
    }
}

// ----------------------------------------------------------------------------
NodeDataType N64ControllerInputDataModel::dataType(PortType portType, PortIndex portIndex) const
{
    if (portType == PortType::Out)
    {
        switch (portIndex)
        {
            case 0 : return NodeDataType {"bool", "A"};
            case 1 : return NodeDataType {"bool", "B"};
            case 2 : return NodeDataType {"bool", "C Up"};
            case 3 : return NodeDataType {"bool", "C Down"};
            case 4 : return NodeDataType {"bool", "C Left"};
            case 5 : return NodeDataType {"bool", "C Right"};
            case 6 : return NodeDataType {"bool", "D Up"};
            case 7 : return NodeDataType {"bool", "D Down"};
            case 8 : return NodeDataType {"bool", "D Left"};
            case 9 : return NodeDataType {"bool", "D Right"};
            case 10 : return NodeDataType {"bool", "L"};
            case 11 : return NodeDataType {"bool", "R"};
            case 12 : return NodeDataType {"bool", "S"};
            case 13 : return NodeDataType {"bool", "Z"};
            case 14 : return NodeDataType {"float", "Joy X"};
            case 15 : return NodeDataType {"float", "Joy Y"};
        }
    }

    return NodeDataType();
}

// ----------------------------------------------------------------------------
std::shared_ptr<NodeData> N64ControllerInputDataModel::outData(PortIndex port)
{
    switch (port)
    {
        case 0 : return buttonA_;
        case 1 : return buttonB_;
        case 2 : return buttonCUp_;
        case 3 : return buttonCDown_;
        case 4 : return buttonCLeft_;
        case 5 : return buttonCRight_;
        case 6 : return buttonDUp_;
        case 7 : return buttonDDown_;
        case 8 : return buttonDLeft_;
        case 9 : return buttonDRight_;
        case 10 : return buttonL_;
        case 11 : return buttonR_;
        case 12 : return buttonS_;
        case 13 : return buttonZ_;
        case 14 : return joyX_;
        case 15 : return joyY_;
        default : return nullptr;
    }
}

// ----------------------------------------------------------------------------
void N64ControllerInputDataModel::setInData(std::shared_ptr<NodeData> data, PortIndex portIndex)
{
}

// ----------------------------------------------------------------------------
QWidget* N64ControllerInputDataModel::embeddedWidget()
{
    return nullptr;
}

// ----------------------------------------------------------------------------
NodeValidationState N64ControllerInputDataModel::validationState() const
{
    return NodeValidationState::Valid;
}

// ----------------------------------------------------------------------------
QString N64ControllerInputDataModel::validationMessage() const
{
    return QString();
}

// ----------------------------------------------------------------------------
QString N64ControllerInputDataModel::caption() const
{
    return QStringLiteral("N64 Input");
}

// ----------------------------------------------------------------------------
QString N64ControllerInputDataModel::name() const
{
    return QStringLiteral("N64 Input");
}

}
