//
// Created by KHML on 2020/04/20.
//

#include <utility>

#include <cyan/utilities.hpp>
#include <cyan/control/if_control.hpp>

namespace cyan
{

    IfControl::IfControl() = default;

    IfControl::~IfControl() = default;

    std::vector<std::string> IfControl::codeGen(size_t indentSize) const
    {
        std::vector<std::string> code;
        const auto indentSpace = indent(indentSize);

        code.emplace_back(indentSpace + "if(" + std::get<0>(_if)() + ")");
        mergeVector(code, std::get<1>(_if).codeGen(indentSize));

        for (auto& condition: _elseIfs)
        {
            code.emplace_back(indentSpace + "else if(" + std::get<0>(condition)() + ")");
            mergeVector(code, std::get<1>(condition).codeGen(indentSize));
        }

        if (!_else.empty())
        {
            code.emplace_back(indentSpace + "else");
            mergeVector(code, _else.codeGen(indentSize));
        }

        code.emplace_back("");

        return std::move(code);
    }

    IfControl& IfControl::if_(Expression& condition, CodeBlock& codeBlock)
    {
        _if = std::make_tuple(condition, codeBlock);
        return *this;
    }

    IfControl& IfControl::elseIf_(Expression& condition, CodeBlock& codeBlock)
    {
        _elseIfs.emplace_back(std::make_tuple(condition, codeBlock));
        return *this;
    }

    IfControl& IfControl::else_(CodeBlock& codeBlock)
    {
        _else = codeBlock;
        return *this;
    }
}