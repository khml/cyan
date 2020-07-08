/**
 * @file arguments.hpp
 * @brief Arguments component
 * @author KHML
 */

#ifndef CYAN_ARGUMENTS_HPP
#define CYAN_ARGUMENTS_HPP

#include <string>
#include <memory>
#include <vector>

#include <cyan/value/value.hpp>

namespace cyan
{
    class Expression;

    class Arguments
    {
    public:
        Arguments();

        ~Arguments();

        std::string operator()() const;

        template<typename Value>
        Arguments& includeValue(const Value& value);

        template<typename Value>
        Arguments& includeValue(Value&& value);

        Arguments& clear();

        size_t size();

        Expression operator[](size_t idx);

    private:
        std::vector<std::string> args;
    };

    template<typename Value>
    Arguments& operator<<(Arguments& arguments, const Value& value);

    template<typename Value>
    Arguments& operator<<(Arguments& arguments, Value&& value);
}

#include <cyan/impl/arguments.hpp>

#endif //CYAN_ARGUMENTS_HPP
