#include "n64c/models/nodes/BooleanData.hpp"

namespace n64c {

// ----------------------------------------------------------------------------
BooleanData::BooleanData() :
    value_(false)
{
}

// ----------------------------------------------------------------------------
BooleanData::BooleanData(bool value) :
    value_(value)
{
}

// ----------------------------------------------------------------------------
NodeDataType BooleanData::type() const
{
    return NodeDataType {"bool", "Bool"};
}

// ----------------------------------------------------------------------------
bool BooleanData::value() const
{
    return value_;
}

// ----------------------------------------------------------------------------
QString BooleanData::valueAsText() const
{
    return value_ ? QStringLiteral("True") : QStringLiteral("False");
}

}
