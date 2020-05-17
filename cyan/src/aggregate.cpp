//
// Created by KHML on 2020/04/27.
//

#include <utility>

#include <cyan/value/aggregate.hpp>
#include <cyan/struct.hpp>

namespace cyan
{
    Aggregate::Aggregate(const Type& type) :type(type)
    {}

    Aggregate::Aggregate(const Type&& type) :type(type)
    {}

    Aggregate::Aggregate(const StructBlock& structBlock) :type(structBlock.type)
    {}

    Aggregate::~Aggregate() = default;

    std::string Aggregate::value() const
    {
        std::string itemList("{");

        for (size_t idx = 0; idx < items.size(); idx++)
        {
            itemList += items[idx];
            if (idx < items.size() - 1)
                itemList += ", ";
        }
        itemList += "}";

        return std::move(itemList);
    }
}
