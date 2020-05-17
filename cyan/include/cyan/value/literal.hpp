//
// Created by KHML on 2020/04/25.
//

#ifndef CYAN_VALUE_LITERAL_HPP
#define CYAN_VALUE_LITERAL_HPP

#include <cyan/value/value.hpp>

namespace cyan
{
    class Literal
    {
    public:
        Literal(const Type& _type, const std::string& literal);

        Literal(const Type& type, std::string&& literal);

        Literal(Type&& type, std::string&& literal);

        explicit Literal(int num);

        explicit Literal(float num);

        explicit Literal(double num);

        explicit Literal(const std::string& str);

        explicit Literal(const std::string&& str);

        ~Literal();

        const std::string& operator()() const;

        const Type type;

    protected:
        const std::string literal;

        const std::string text;
    };
}

#endif //CYAN_VALUE_LITERAL_HPP
