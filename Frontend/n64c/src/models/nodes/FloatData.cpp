#include "n64c/models/nodes/FloatData.hpp"

namespace n64c {

// ----------------------------------------------------------------------------
FloatData::FloatData() :
    number_(0.0)
{
}

// ----------------------------------------------------------------------------
FloatData::FloatData(double number) :
    number_(number)
{
}

// ----------------------------------------------------------------------------
NodeDataType FloatData::type() const
{
    return NodeDataType {"float", "Float"};
}

// ----------------------------------------------------------------------------
double FloatData::number() const
{
    return number_;
}

// ----------------------------------------------------------------------------
QString FloatData::numberAsText() const
{
    return QString::number(number_, 'f');
}

}
