//
// Created by KHML on 2020/04/18.
//

#include <utility>

#include <cyan/utilities.hpp>
#include <cyan/enum.hpp>

namespace cyan
{
    EnumBlock::EnumBlock(std::string tag) :type(std::move(tag))
    {}

    EnumBlock::EnumBlock(std::string tag, const std::vector<std::string>& items, const int initialValue) :EnumBlock(
        std::move(tag))
    {
        if (items.empty())
            return;

        lines.emplace_back(items.front() + " = " + std::to_string(initialValue) + ",");
        for (int idx = 1; idx < items.size(); idx++)
            lines.emplace_back(items[idx] + ",");
    }

    EnumBlock::EnumBlock(const std::string& tag, const std::vector<std::string>& items) :EnumBlock(tag, items, 0)
    {}

    EnumBlock::EnumBlock(std::string tag, const std::vector<std::tuple<std::string, int>>& items) :EnumBlock(
        std::move(tag))
    {
        for (auto& item :items)
            lines.emplace_back(std::get<0>(item) + " = " + std::to_string(std::get<1>(item)) + ",");
    }

    EnumBlock::~EnumBlock() = default;

    std::vector<std::string> EnumBlock::codeGen(size_t indentSize) const
    {
        std::vector<std::string> code;

        const auto indentSpace = indent(indentSize);
        const auto depth = indent(config::indentSize + indentSize);

        code.emplace_back(indentSpace + "enum " + type.name);
        code.emplace_back(indentSpace + "{");

        for (auto& line: lines)
            code.emplace_back(depth + line);

        code.emplace_back(indentSpace + "};");
        code.emplace_back("");

        return std::move(code);
    }

    EnumBlock& EnumBlock::append(const std::string& item)
    {
        if (lines.empty())
            lines.emplace_back(item + " = 0,");
        else
            lines.emplace_back(item + ",");
        return *this;
    }

    EnumBlock& EnumBlock::append(std::string&& item)
    {
        return append(item);
    }

    EnumBlock& EnumBlock::append(const std::string& item, int number)
    {
        lines.emplace_back(item + " = " + std::to_string(number) + ",");
        return *this;
    }

    EnumBlock& EnumBlock::append(const std::string&& item, int number)
    {
        return append(item, number);
    }

    EnumBlock& operator<<(EnumBlock& enumBlock, const std::string& item)
    {
        return enumBlock.append(item);
    }

    EnumBlock& operator<<(EnumBlock& enumBlock, std::string&& item)
    {
        return enumBlock.append(std::move(item));
    }
}