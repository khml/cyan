//
// Created by KHML on 2020/05/03.
//

#ifndef CYAN_IMPL_VALUE_AGGREGATE_HPP
#define CYAN_IMPL_VALUE_AGGREGATE_HPP

namespace cyan
{
    template<typename Value>
    Aggregate& Aggregate::includeValue(Value& value)
    {
        items.emplace_back(value());
        return *this;
    }

    template<typename Value>
    Aggregate& Aggregate::includeValue(Value&& value)
    {
        items.emplace_back(value());
        return *this;
    }

    template<typename Value>
    Aggregate& operator<<(Aggregate& aggregate, Value& value)
    {
        aggregate.includeValue(value);
        return aggregate;
    }

    template<typename Value>
    Aggregate& operator<<(Aggregate& aggregate, Value&& value)
    {
        aggregate.includeValue(value);
        return aggregate;
    }
}

#endif //CYAN_IMPL_VALUE_AGGREGATE_HPP
