//
// Created by KHML on 2020/05/02.
//

#ifndef CYAN_IMPL_EXPRESSION_HPP
#define CYAN_IMPL_EXPRESSION_HPP

namespace cyan
{
    template<typename Value>
    Expression xpr(Value& value)
    {
        return Expression(value());
    }

    template<typename Value>
    Expression xpr(Value&& value)
    {
        return Expression(value());
    }

    template<typename Value>
    Expression::Expression(Value& value) :expression(value())
    {}

    template<typename Value>
    constexpr void Expression::binaryOp(std::string&& op, const Value& value)
    {
        expression += op + value();
    }

    template<typename Value>
    Expression& Expression::assign(const Value& value)
    {
        binaryOp(" = ", value);
        return *this;
    }

    template<typename Value>
    Expression& Expression::assign(Value&& value)
    {
        binaryOp(" = ", value);
        return *this;
    }

    template<typename Value>
    Expression& Expression::add(const Value& value)
    {
        binaryOp(" + ", value);
        return *this;
    }

    template<typename Value>
    Expression& Expression::add(Value&& value)
    {
        binaryOp(" + ", value);
        return *this;
    }

    template<typename Value>
    Expression& Expression::sub(const Value& value)
    {
        binaryOp(" - ", value);
        return *this;
    }

    template<typename Value>
    Expression& Expression::sub(Value&& value)
    {
        binaryOp(" - ", value);
        return *this;
    }

    template<typename Value>
    Expression& Expression::mul(const Value& value)
    {
        binaryOp(" * ", value);
        return *this;
    }

    template<typename Value>
    Expression& Expression::mul(Value&& value)
    {
        binaryOp(" * ", value);
        return *this;
    }

    template<typename Value>
    Expression& Expression::div(const Value& value)
    {
        binaryOp(" / ", value);
        return *this;
    }

    template<typename Value>
    Expression& Expression::div(Value&& value)
    {
        binaryOp(" / ", value);
        return *this;
    }

    template<typename Value>
    Expression& Expression::mod(const Value& value)
    {
        binaryOp(" % ", value);
        return *this;
    }

    template<typename Value>
    Expression& Expression::mod(Value&& value)
    {
        binaryOp(" % ", value);
        return *this;
    }

    template<typename Value>
    Expression& Expression::equal(const Value& value)
    {
        binaryOp(" == ", value);
        return *this;
    }

    template<typename Value>
    Expression& Expression::equal(Value&& value)
    {
        binaryOp(" == ", value);
        return *this;
    }

    template<typename Value>
    Expression& Expression::andOp(const Value& value)
    {
        binaryOp(" && ", value);
        return *this;
    }

    template<typename Value>
    Expression& Expression::andOp(Value&& value)
    {
        binaryOp(" && ", value);
        return *this;
    }

    template<typename Value>
    Expression& Expression::orOp(const Value& value)
    {
        binaryOp(" || ", value);
        return *this;
    }

    template<typename Value>
    Expression& Expression::orOp(Value&& value)
    {
        binaryOp(" || ", value);
        return *this;
    }

    template<typename Value>
    Expression& Expression::grater(const Value& value)
    {
        binaryOp(" >= ", value);
        return *this;
    }

    template<typename Value>
    Expression& Expression::grater(Value&& value)
    {
        binaryOp(" >= ", value);
        return *this;
    }

    template<typename Value>
    Expression& Expression::lesser(const Value& value)
    {
        binaryOp(" <= ", value);
        return *this;
    }

    template<typename Value>
    Expression& Expression::lesser(Value&& value)
    {
        binaryOp(" <= ", value);
        return *this;
    }

    template<typename Value>
    Expression& Expression::graterThan(const Value& value)
    {
        binaryOp(" > ", value);
        return *this;
    }

    template<typename Value>
    Expression& Expression::graterThan(Value&& value)
    {
        binaryOp(" > ", value);
        return *this;
    }

    template<typename Value>
    Expression& Expression::lesserThan(const Value& value)
    {
        binaryOp(" < ", value);
        return *this;
    }

    template<typename Value>
    Expression& Expression::lesserThan(Value&& value)
    {
        binaryOp(" < ", value);
        return *this;
    }

    template<typename Value>
    Expression& Expression::shiftLeft(const Value& value)
    {
        binaryOp(" << ", value);
        return *this;
    }

    template<typename Value>
    Expression& Expression::shiftLeft(Value&& value)
    {
        binaryOp(" << ", value);
        return *this;
    }

    template<typename Value>
    Expression& Expression::shiftRight(const Value& value)
    {
        binaryOp(" >> ", value);
        return *this;
    }

    template<typename Value>
    Expression& Expression::shiftRight(Value&& value)
    {
        binaryOp(" >> ", value);
        return *this;
    }

    template<typename Value>
    Expression& operator<<(Expression& expression, const Value& value)
    {
        expression.shiftLeft(value);
        return expression;
    }

    template<typename Value>
    Expression& operator<<(Expression& expression, Value&& value)
    {
        expression.shiftLeft(value);
        return expression;
    }

    template<typename Value>
    Expression& operator>>(Expression& expression, const Value& value)
    {
        expression.shiftRight(value);
        return expression;
    }

    template<typename Value>
    Expression& operator>>(Expression& expression, Value&& value)
    {
        expression.shiftRight(value);
        return expression;
    }
}

#endif //CYAN_IMPL_EXPRESSION_HPP
