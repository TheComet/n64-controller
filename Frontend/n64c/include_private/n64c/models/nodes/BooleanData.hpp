#pragma once

#include "nodes/NodeDataModel"

namespace n64c {

using QtNodes::NodeDataType;

class BooleanData : public QtNodes::NodeData
{
public:
    BooleanData();
    BooleanData(bool value);
    NodeDataType type() const override;
    bool value() const;
    QString valueAsText() const;

private:
    bool value_;
};

}
