#pragma once

#include "nodes/NodeDataModel"

namespace n64c {

using QtNodes::NodeDataType;

class FloatData : public QtNodes::NodeData
{
public:
    FloatData();
    FloatData(double number);
    NodeDataType type() const override;
    double number() const;
    QString numberAsText() const;

private:
    double number_;
};

}
