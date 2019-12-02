#pragma once

#include "nodes/NodeDataModel"

namespace n64c {

class FloatData;

using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeValidationState;
using QtNodes::PortIndex;
using QtNodes::PortType;

class MathOperationModel : public QtNodes::NodeDataModel
{
    Q_OBJECT

public:
#define OPERATION_LIST \
    X(Add) \
    X(Sub) \
    X(Mul) \
    X(Div)

    enum Operation
    {
#define X(op) op,
        OPERATION_LIST
#undef X
        OPERATION_COUNT
    };

public:
    MathOperationModel();

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
    bool allInputsValid() const;
    void updateResult();
#define X(op) void updateResult##op();
    OPERATION_LIST
#undef X

private:
    std::vector<std::weak_ptr<FloatData>> inputNumbers_;
    std::shared_ptr<FloatData> result_;
    QString validationMessage_;
    NodeValidationState validationState_;
    Operation operation_;

    typedef void (MathOperationModel::*OperationFunc)();
    OperationFunc opTable_[OPERATION_COUNT];
};

}
