//
// Created by KHML on 2020/04/19.
//

#include <utility>

#include <cyan/arguments.hpp>
#include <cyan/value/variable.hpp>
#include <cyan/expression.hpp>

namespace cyan
{
    Expression::Expression() = default;

    template<>
    Expression::Expression(Variable& value) :expression(value())
    {
        registerVariable(value);
    }

    Expression::Expression(std::string value) :expression(std::move(value))
    {}

    Expression::Expression(const Expression& orig) = default;

    Expression::~Expression() = default;

    std::string Expression::operator()() const
    {
        return expression;
    }

    Expression& Expression::set(Variable& value)
    {
        expression = value();
        registerVariable(value);
        return *this;
    }

    Expression& Expression::set(Variable&& value)
    {
        expression = value();
        registerVariable(value);
        return *this;
    }

    void Expression::pre(std::string&& op)
    {
        expression = op + expression;
    }

    void Expression::post(std::string&& op)
    {
        expression += op;
    }

    Expression& Expression::parenthesis()
    {
        expression = "(" + expression + ")";
        return *this;
    }

    Expression& Expression::preIncrement()
    {
        pre("++");
        return *this;
    }

    Expression& Expression::preDecrement()
    {
        pre("--");
        return *this;
    }

    Expression& Expression::postIncrement()
    {
        post("++");
        return *this;
    }

    Expression& Expression::postDecrement()
    {
        post("--");
        return *this;
    }

    Expression& Expression::notOp()
    {
        post("!");
        return *this;
    }

    Expression& Expression::cast(const Type& type)
    {
        expression = "(" + type.name + ") " + expression;
        return *this;
    }

    Expression& Expression::cast(const Type&& type)
    {
        return cast(type);
    }

    Expression& Expression::move()
    {
        parenthesis();
        expression = "std::move" + expression;
        return *this;
    }

    Expression& Expression::dot(const std::string& memberName)
    {
        expression += "." + memberName;
        return *this;
    }

    Expression& Expression::dot(std::string&& memberName)
    {
        return dot(memberName);
    }

    Expression& Expression::arrow(const std::string& memberName)
    {
        expression += "->" + memberName;
        return *this;
    }

    Expression& Expression::arrow(std::string&& memberName)
    {
        return arrow(memberName);
    }

    Expression& Expression::cin()
    {
        pre("std::cin >> ");
        return *this;
    }

    Expression& Expression::cout()
    {
        pre("std::cout << ");
        return *this;
    }

    Expression& Expression::cerr()
    {
        pre("std::cerr << ");
        return *this;
    }

    Expression& Expression::endl()
    {
        post(" << std::endl");
        return *this;
    }

    Expression& Expression::ret()
    {
        pre("return ");
        return *this;
    }

    template<>
    Expression xpr<Variable>(Variable& value)
    {
        auto expression = Expression(value());
        registerVariable(value);
        return expression;
    }

    Expression createCallee(const std::string& funcName, const Arguments& args)
    {
        return Expression(funcName + args());
    }

    Expression createCallee(std::string&& funcName, const Arguments& args)
    {
        return createCallee(funcName, args);
    }

    Expression createCallee(const std::string& funcName, const Arguments& args, Variable& retVar)
    {
        auto expr = Expression(retVar);
        return expr.assign(createCallee(funcName, args));
    }

    Expression createCallee(std::string&& funcName, const Arguments& args, Variable& retVar)
    {
        return createCallee(funcName, args, retVar);
    }
}