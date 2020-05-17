//
// Created by KHML on 2020/05/02.
//

#ifndef CYAN_IMPL_VALUE_ARGUMENTS_HPP
#define CYAN_IMPL_VALUE_ARGUMENTS_HPP

namespace cyan
{
    template<typename Value>
    Arguments& Arguments::includeValue(const Value& value)
    {
        args.emplace_back(value());
        return *this;
    }

    template<typename Value>
    Arguments& Arguments::includeValue(Value&& value)
    {
        args.emplace_back(value());
        return *this;
    }

    template<typename Value>
    Arguments& operator<<(Arguments& arguments, const Value& value)
    {
        arguments.includeValue(value);
        return arguments;
    }

    template<typename Value>
    Arguments& operator<<(Arguments& arguments, Value&& value)
    {
        arguments.includeValue(std::forward<Value>(value));
        return arguments;
    }
}

#endif //CYAN_IMPL_VALUE_ARGUMENTS_HPP
