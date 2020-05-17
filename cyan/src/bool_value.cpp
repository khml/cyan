//
// Created by KHML on 2020/04/27.
//

#include <cyan/value/bool_value.hpp>

namespace cyan
{
    BoolValue::BoolValue(bool value) :type(Type("bool")), literal(value ? "true" : "false")
    {}

    BoolValue::~BoolValue() = default;

    const std::string& BoolValue::operator()() const
    {
        return literal;
    }
}