//
// Created by KHML on 2020/04/25.
//

#ifndef CYAN_VALUE_BOOL_VALUE_HPP
#define CYAN_VALUE_BOOL_VALUE_HPP

#include <cyan/value/value.hpp>

namespace cyan
{
    class BoolValue
    {
    public:
        explicit BoolValue(bool value);

        ~BoolValue();

        const std::string& operator()() const;

        const Type type;

    protected:
        const std::string literal;
    };
}

#endif //CYAN_VALUE_BOOL_VALUE_HPP
