//
// Created by KHML on 2020/04/25.
//

#ifndef CYAN_VALUE_AGGREGATE_HPP
#define CYAN_VALUE_AGGREGATE_HPP

#include <vector>

#include <cyan/type.hpp>
#include <cyan/value/value.hpp>

namespace cyan
{
    class StructBlock;

    class Aggregate
    {
    public:
        explicit Aggregate(const Type& type);

        explicit Aggregate(const Type&& type);

        explicit Aggregate(const StructBlock& structBlock);

        ~Aggregate();

        std::string value() const;

        const Type type;

        template<typename Value>
        Aggregate& includeValue(Value& value);

        template<typename Value>
        Aggregate& includeValue(Value&& value);

    protected:
        std::vector<std::string> items;
    };

    template<typename Value>
    Aggregate& operator<<(Aggregate& aggregate, Value& value);

    template<typename Value>
    Aggregate& operator<<(Aggregate& aggregate, Value&& value);
}

#include <cyan/impl/value/aggregate.hpp>

#endif //CYAN_VALUE_AGGREGATE_HPP
