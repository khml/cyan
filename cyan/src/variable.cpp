//
// Created by KHML on 2020/04/27.
//

#include <utility>

#include <cyan/value/aggregate.hpp>
#include <cyan/utilities.hpp>
#include <cyan/value/variable.hpp>

namespace cyan
{
    Variable::Variable(std::string name, const Type& type) :type(type), name(std::move(name)), initValue(""),
        equalInitialization(isNumber(type))
    {}

    Variable::Variable(std::string name, const Literal& initValue) :type(initValue.type), name(std::move(name)),
        initValue(initValue()), equalInitialization(isNumber(type))
    {}

    Variable::Variable(std::string&& name, Literal&& initValue) :Variable(name, initValue)
    {}

    Variable::Variable(std::string&& name, const Aggregate& initValue) :type(initValue.type), name(name),
        initValue(initValue.value()), equalInitialization(true)
    {}

    Variable::~Variable() = default;

    std::string Variable::operator()() const
    {
        if (registered)
            return name;
        return initialization();
    }

    std::string Variable::declaration() const
    {
        return std::move(type.name + " " + name);
    }

    std::string Variable::initialization() const
    {
        if (initValue.empty())
            return std::move(declaration());

        if (equalInitialization)
            return std::move(declaration() + " = " + initValue);

        return std::move(declaration() + "(" + initValue + ")");
    }

    std::string Variable::arg() const
    {
        if (initValue.empty())
            return std::move(declaration());

        return std::move(declaration() + " = " + initValue);
    }

    void registerVariable(Variable& var)
    {
        var.registered = true;
    }
}
