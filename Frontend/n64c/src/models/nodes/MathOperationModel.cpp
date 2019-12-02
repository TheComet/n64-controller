#include "n64c/models/nodes/MathOperationModel.hpp"
#include "n64c/models/nodes/FloatData.hpp"

namespace n64c {

// ----------------------------------------------------------------------------
MathOperationModel::MathOperationModel() :
    validationState_(NodeValidationState::Error),
    operation_(Add),
    opTable_{
#define X(op) &MathOperationModel::updateResult##op,
        OPERATION_LIST
#undef X
    }
{
    inputNumbers_.emplace_back();
    inputNumbers_.emplace_back();
}


// ----------------------------------------------------------------------------
unsigned MathOperationModel::nPorts(PortType portType) const
{
    switch (portType)
    {
        case PortType::In: return 2;
        case PortType::Out: return 1;
        default: return 0;
    }
}

// ----------------------------------------------------------------------------
NodeDataType MathOperationModel::dataType(QtNodes::PortType portType, QtNodes::PortIndex portIndex) const
{
    return FloatData().type();
}

// ----------------------------------------------------------------------------
std::shared_ptr<NodeData> MathOperationModel::outData(QtNodes::PortIndex port)
{
    return std::static_pointer_cast<NodeData>(result_);
}

// ----------------------------------------------------------------------------
void MathOperationModel::setInData(std::shared_ptr<NodeData> data, QtNodes::PortIndex portIndex)
{
    auto floatData = std::dynamic_pointer_cast<FloatData>(data);
    inputNumbers_[portIndex] = floatData;
    updateResult();
}

// ----------------------------------------------------------------------------
QWidget* MathOperationModel::embeddedWidget()
{
    return nullptr;
}

// ----------------------------------------------------------------------------
QtNodes::NodeValidationState MathOperationModel::validationState() const
{
    return allInputsValid() ? NodeValidationState::Valid : NodeValidationState::Warning;
}

// ----------------------------------------------------------------------------
QString MathOperationModel::validationMessage() const
{
    return allInputsValid() ? QStringLiteral("Missing or incorrect inputs") : QString();
}

// ----------------------------------------------------------------------------
QString MathOperationModel::caption() const
{
    const QString captions[] = {
#define X(op) QStringLiteral(#op),
        OPERATION_LIST
#undef X
    };

    return captions[operation_];
}

// ----------------------------------------------------------------------------
QString MathOperationModel::name() const
{
    const QString captions[] = {
#define X(op) QStringLiteral(#op),
        OPERATION_LIST
#undef X
    };

    return captions[operation_];
}

// ----------------------------------------------------------------------------
bool MathOperationModel::allInputsValid() const
{
    for (const auto& floatData : inputNumbers_)
        if (floatData.expired())
            return false;
    return true;
}

// ----------------------------------------------------------------------------
void MathOperationModel::updateResult()
{
    if (allInputsValid() == false)
        result_.reset();
    else
        (this->*opTable_[operation_])();
}

// ----------------------------------------------------------------------------
void MathOperationModel::updateResultAdd()
{
    double value = 0;
    for (const auto& floatData : inputNumbers_)
        value += floatData.lock()->number();
    result_ = std::make_shared<FloatData>(value);
}

// ----------------------------------------------------------------------------
void MathOperationModel::updateResultSub()
{
    double value = inputNumbers_[0].lock()->number();
    for (std::size_t i = 1; i < inputNumbers_.size(); ++i)
        value -= inputNumbers_[i].lock()->number();
    result_ = std::make_shared<FloatData>(value);
}

// ----------------------------------------------------------------------------
void MathOperationModel::updateResultMul()
{
    double value = inputNumbers_[0].lock()->number();
    for (std::size_t i = 1; i < inputNumbers_.size(); ++i)
        value *= inputNumbers_[i].lock()->number();
    result_ = std::make_shared<FloatData>(value);
}

// ----------------------------------------------------------------------------
void MathOperationModel::updateResultDiv()
{
    double value = inputNumbers_[0].lock()->number();
    for (std::size_t i = 1; i < inputNumbers_.size(); ++i)
        value /= inputNumbers_[i].lock()->number();
    result_ = std::make_shared<FloatData>(value);
}

}
