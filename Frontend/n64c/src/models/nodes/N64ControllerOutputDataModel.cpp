#include "n64c/models/nodes/N64ControllerOutputDataModel.hpp"
#include "n64c/models/nodes/BooleanData.hpp"
#include "n64c/models/nodes/FloatData.hpp"

namespace n64c {

// ----------------------------------------------------------------------------
unsigned N64ControllerOutputDataModel::nPorts(PortType portType) const
{
    switch (portType)
    {
        case PortType::In : return 16;
        default : return 0;
    }
}

// ----------------------------------------------------------------------------
NodeDataType N64ControllerOutputDataModel::dataType(PortType portType, PortIndex portIndex) const
{
    if (portType == PortType::In)
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
std::shared_ptr<NodeData> N64ControllerOutputDataModel::outData(PortIndex port)
{
}

// ----------------------------------------------------------------------------
void N64ControllerOutputDataModel::setInData(std::shared_ptr<NodeData> data, PortIndex portIndex)
{
    switch (portIndex)
    {
        case 0 : buttonA_ = std::dynamic_pointer_cast<BooleanData>(data); break;
        case 1 : buttonB_ = std::dynamic_pointer_cast<BooleanData>(data); break;
        case 2 : buttonCUp_ = std::dynamic_pointer_cast<BooleanData>(data); break;
        case 3 : buttonCDown_ = std::dynamic_pointer_cast<BooleanData>(data); break;
        case 4 : buttonCLeft_ = std::dynamic_pointer_cast<BooleanData>(data); break;
        case 5 : buttonCRight_ = std::dynamic_pointer_cast<BooleanData>(data); break;
        case 6 : buttonDUp_ = std::dynamic_pointer_cast<BooleanData>(data); break;
        case 7 : buttonDDown_ = std::dynamic_pointer_cast<BooleanData>(data); break;
        case 8 : buttonDLeft_ = std::dynamic_pointer_cast<BooleanData>(data); break;
        case 9 : buttonDRight_ = std::dynamic_pointer_cast<BooleanData>(data); break;
        case 10 : buttonL_ = std::dynamic_pointer_cast<BooleanData>(data); break;
        case 11 : buttonR_ = std::dynamic_pointer_cast<BooleanData>(data); break;
        case 12 : buttonS_ = std::dynamic_pointer_cast<BooleanData>(data); break;
        case 13 : buttonZ_ = std::dynamic_pointer_cast<BooleanData>(data); break;
        case 14 : joyX_ = std::dynamic_pointer_cast<FloatData>(data); break;
        case 15 : joyY_ = std::dynamic_pointer_cast<FloatData>(data); break;
    }
}

// ----------------------------------------------------------------------------
QWidget* N64ControllerOutputDataModel::embeddedWidget()
{
    return nullptr;
}

// ----------------------------------------------------------------------------
NodeValidationState N64ControllerOutputDataModel::validationState() const
{
    return NodeValidationState::Valid;
}

// ----------------------------------------------------------------------------
QString N64ControllerOutputDataModel::validationMessage() const
{
    return QString();
}

// ----------------------------------------------------------------------------
QString N64ControllerOutputDataModel::caption() const
{
    return QStringLiteral("N64 Output");
}

// ----------------------------------------------------------------------------
QString N64ControllerOutputDataModel::name() const
{
    return QStringLiteral("N64 Output");
}

}
