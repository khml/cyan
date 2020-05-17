//
// Created by KHML on 2020/04/27.
//

#include <cyan/value/literal.hpp>

namespace cyan
{
    Literal::Literal(const int num) :type(Type("int")), text(std::to_string(num)), literal(std::to_string(num))
    {}

    Literal::Literal(const float num) :type(Type("int")), text(std::to_string(num)), literal(std::to_string(num))
    {}

    Literal::Literal(const double num) :type(Type("int")), text(std::to_string(num)), literal(std::to_string(num))
    {}

    Literal::Literal(const std::string& str) :type(Type("std::string")), text(str), literal("\"" + str + "\"")
    {}

    Literal::Literal(const std::string&& str) :Literal(str)
    {}

    Literal::Literal(const Type& _type, const std::string& literal) :type(_type), text(literal),
        literal(_type == types::stringType() ? ("\"" + literal + "\"") : literal)
    {}

    Literal::Literal(Type&& type, std::string&& literal) :type(type), text(literal), literal(literal)
    {}

    Literal::Literal(const Type& type, std::string&& literal) :Literal(type, literal)
    {}

    Literal::~Literal() = default;

    const std::string& Literal::operator()() const
    {
        return literal;
    }
}