//
// Created by KHML on 2020/04/23.
//

#include <utility>

#include <cyan/value/variables.hpp>

namespace cyan
{

    Variables::Variables() = default;

    Variables::~Variables() = default;

    std::string Variables::args() const
    {
        return "(" + _args + ")";
    }

    std::string Variables::implArgs() const
    {
        return "(" + _impl_args + ")";
    }

    std::string Variables::callee() const
    {
        return "(" + _callee + ")";
    }

    Variables& Variables::append(Variable& value)
    {
        if (variables.empty())
        {
            _args = value.arg();
            _impl_args = value.type.name + " " + value.name;
            _callee = value();
        }
        else
        {
            _args += ", " + value.arg();
            _impl_args += ", " + value.type.name + " " + value.name;
            _callee += ", " + value();
        }

        registerVariable(value);
        variables.emplace_back(value);

        return *this;
    }

    Variables& Variables::append(Variable&& value)
    {
        return append(value);
    }

    const Variable& Variables::operator[](const size_t idx) const
    {
        return variables[idx];
    }

    void Variables::clear()
    {
        variables.clear();
    }

    Variables& operator<<(Variables& variables, Variable& value)
    {
        variables.append(value);
        return variables;
    }

    Variables& operator<<(Variables& variables, Variable&& value)
    {
        variables.append(value);
        return variables;
    }
}