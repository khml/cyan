//
// Created by KHML on 2020/04/19.
//

#include <utility>

#include <cyan/utilities.hpp>
#include <cyan/value/variable.hpp>
#include <cyan/value/variables.hpp>
#include <cyan/struct.hpp>

namespace cyan
{
    StructBlock::StructBlock(std::string tag) :type(std::move(tag))
    {}

    StructBlock::StructBlock(std::string tag, const std::vector<Variable>& members) :type(std::move(tag))
    {
        for (auto& var : members)
            lines.emplace_back(var.type.name + " " + var.name + ";");
    }

    StructBlock::StructBlock(std::string tag, Variables& members) :type(std::move(tag))
    {
        for (auto& var : members.variables)
            lines.emplace_back(var.type.name + " " + var.name + ";");
    }

    StructBlock::~StructBlock() = default;

    std::vector<std::string> StructBlock::codeGen(size_t indentSize) const
    {
        const auto indentSpace = indent(indentSize);
        const auto depth = indent(indentSize + cyan::config::indentSize);
        std::vector<std::string> code;

        code.emplace_back(indentSpace + "struct " + type.name);
        code.emplace_back(indentSpace + "{");
        for (auto& line : lines)
            code.emplace_back(depth + line);
        code.emplace_back(indentSpace + "};");
        code.emplace_back("");

        return std::move(code);
    }

    void StructBlock::append(const Variable& member)
    {
        lines.emplace_back(member.type.name + " " + member.name + ";");
    }

    void StructBlock::append(Variable&& member)
    {
        append(member);
    }

    StructBlock& StructBlock::operator<<(const Variable& member)
    {
        append(member);
        return *this;
    }

    StructBlock& StructBlock::operator<<(Variable&& member)
    {
        append(std::move(member));
        return *this;
    }
}
