/**
 * @file expression.hpp
 * @brief Expression component
 * @author KHML
 */

#ifndef CYAN_EXPRESSION_HPP
#define CYAN_EXPRESSION_HPP

#include <string>

#include <cyan/type.hpp>
#include <cyan/value/value.hpp>
#include <cyan/value/variable.hpp>

namespace cyan
{
    class Arguments;

    class Variable;

    class Expression
    {
    public:
        Expression();

        template<typename Value>
        explicit Expression(Value& value);

        Expression(const Expression& orig);

        ~Expression();

        std::string operator()() const;

        Expression& set(Variable& value);

        Expression& set(Variable&& value);

        template<typename Value>
        Expression& assign(const Value& value);

        template<typename Value>
        Expression& assign(Value&& value);

        template<typename Value>
        Expression& add(const Value& value);

        template<typename Value>
        Expression& add(Value&& value);

        template<typename Value>
        Expression& sub(const Value& value);

        template<typename Value>
        Expression& sub(Value&& value);

        template<typename Value>
        Expression& mul(const Value& value);

        template<typename Value>
        Expression& mul(Value&& value);

        template<typename Value>
        Expression& div(const Value& value);

        template<typename Value>
        Expression& div(Value&& value);

        template<typename Value>
        Expression& mod(const Value& value);

        template<typename Value>
        Expression& mod(Value&& value);

        Expression& parenthesis();

        template<typename Value>
        Expression& equal(const Value& value);

        template<typename Value>
        Expression& equal(Value&& value);

        Expression& preIncrement();

        Expression& preDecrement();

        Expression& postIncrement();

        Expression& postDecrement();

        template<typename Value>
        Expression& andOp(const Value& value);

        template<typename Value>
        Expression& andOp(Value&& value);

        template<typename Value>
        Expression& orOp(const Value& value);

        template<typename Value>
        Expression& orOp(Value&& value);

        Expression& notOp();

        Expression& cast(const Type& type);

        Expression& cast(const Type&& type);

        template<typename Value>
        Expression& grater(const Value& value);

        template<typename Value>
        Expression& grater(Value&& value);

        template<typename Value>
        Expression& lesser(const Value& value);

        template<typename Value>
        Expression& lesser(Value&& value);

        template<typename Value>
        Expression& graterThan(const Value& value);

        template<typename Value>
        Expression& graterThan(Value&& value);

        template<typename Value>
        Expression& lesserThan(const Value& value);

        template<typename Value>
        Expression& lesserThan(Value&& value);

        Expression& move();

        Expression& dot(const std::string& memberName);

        Expression& dot(std::string&& memberName);

        Expression& arrow(const std::string& memberName);

        Expression& arrow(std::string&& memberName);

        template<typename Value>
        Expression& shiftLeft(const Value& value);

        template<typename Value>
        Expression& shiftLeft(Value&& value);

        template<typename Value>
        Expression& shiftRight(const Value& value);

        template<typename Value>
        Expression& shiftRight(Value&& value);

        Expression& cin();

        Expression& cout();

        Expression& cerr();

        Expression& endl();

        Expression& ret();

        template<typename Value>
        friend Expression xpr(Value& value);

        template<typename Value>
        friend Expression xpr(Value&& value);

        friend Expression createCallee(const std::string& funcName, const Arguments& args);

        friend Expression createCallee(const std::string& funcName, const Arguments& args, Variable& retVar);

        friend Arguments;

    private:
        explicit Expression(std::string value);

        std::string expression;

        void pre(std::string&& op);

        void post(std::string&& op);

        template<typename Value>
        constexpr void binaryOp(std::string&& op, const Value& value);
    };

    template<>
    Expression::Expression(Variable& value);

    Expression createCallee(const std::string& funcName, const Arguments& args);

    Expression createCallee(std::string&& funcName, const Arguments& args);

    Expression createCallee(const std::string& funcName, const Arguments& args, Variable& retVar);

    Expression createCallee(std::string&& funcName, const Arguments& args, Variable& retVar);

    template<typename Value>
    Expression xpr(Value& value);

    template<>
    Expression xpr<Variable>(Variable& value);

    template<typename Value>
    Expression xpr(Value&& value);

    template<typename Value>
    Expression& operator<<(Expression& expression, const Value& value);

    template<typename Value>
    Expression& operator<<(Expression& expression, Value&& value);

    template<typename Value>
    Expression& operator>>(Expression& expression, const Value& value);

    template<typename Value>
    Expression& operator>>(Expression& expression, Value&& value);
}

#include <cyan/impl/expression.hpp>

#endif //CYAN_EXPRESSION_HPP
