//
// Created by KHML on 2020/04/24.
//

#include <cyan/utilities.hpp>
#include <cyan/control/for_control.hpp>
#include <cyan/control/if_control.hpp>
#include <cyan/control/while_control.hpp>

namespace cyan
{

    WhileControl::WhileControl() = default;

    WhileControl::WhileControl(const Expression& condition) :condition(condition)
    {}

    WhileControl::WhileControl(Expression&& condition) :condition(condition)
    {}

    WhileControl::~WhileControl() = default;

    WhileControl::WhileControl(const Expression& condition, const CodeBlock& statements) :
        condition(condition), statements(statements)
    {}

    std::vector<std::string> WhileControl::codeGen(size_t indentSize) const
    {
        const auto indentSpace = indent(indentSize);
        std::vector<std::string> code;
        code.emplace_back(indentSpace + "while(" + condition() + ")");
        mergeVector(code, statements.codeGen(indentSize));
        code.emplace_back("");
        return std::move(code);
    }

    CodeBlock& WhileControl::operator()()
    {
        return statements;
    }

    DoWhileControl::DoWhileControl() = default;

    DoWhileControl::DoWhileControl(const Expression& condition) :condition(condition)
    {}

    DoWhileControl::DoWhileControl(Expression&& condition) :condition(condition)
    {}

    DoWhileControl::~DoWhileControl() = default;

    DoWhileControl::DoWhileControl(const Expression& condition, const CodeBlock& statements) :
        condition(condition), statements(statements)
    {}

    std::vector<std::string> DoWhileControl::codeGen(size_t indentSize) const
    {
        std::vector<std::string> code;
        const auto indentSpace = indent(indentSize);
        code.emplace_back(indentSpace + "do");
        mergeVector(code, statements.codeGen(indentSize));
        code.emplace_back(indentSpace + "while(" + condition() + ");");
        code.emplace_back("");
        return std::move(code);
    }

    CodeBlock& DoWhileControl::operator()()
    {
        return statements;
    }

    WhileControl& operator<<(WhileControl& whileControl, const CodeBlock& codeBlock)
    {
        return includeCode(whileControl, codeBlock);
    }

    WhileControl& operator<<(WhileControl& whileControl, CodeBlock&& codeBlock)
    {
        return includeCode(whileControl, codeBlock);
    }

    WhileControl& operator<<(WhileControl& whileControl, const Expression& expression)
    {
        return includeExpr(whileControl, expression);
    }

    WhileControl& operator<<(WhileControl& whileControl, Expression&& expression)
    {
        return includeExpr(whileControl, expression);
    }

    WhileControl& operator<<(WhileControl& whileControl, const ForControl& control)
    {
        return includeCtrl(whileControl, control);
    }

    WhileControl& operator<<(WhileControl& whileControl, ForControl&& control)
    {
        return includeCtrl(whileControl, control);
    }

    WhileControl& operator<<(WhileControl& whileControl, const IfControl& control)
    {
        return includeCtrl(whileControl, control);
    }

    WhileControl& operator<<(WhileControl& whileControl, IfControl&& control)
    {
        return includeCtrl(whileControl, control);
    }

    WhileControl& operator<<(WhileControl& whileControl, const WhileControl& control)
    {
        return includeCtrl(whileControl, control);
    }

    WhileControl& operator<<(WhileControl& whileControl, WhileControl&& control)
    {
        return includeCtrl(whileControl, control);
    }

    WhileControl& operator<<(WhileControl& whileControl, const DoWhileControl& control)
    {
        return includeCtrl(whileControl, control);
    }

    WhileControl& operator<<(WhileControl& whileControl, DoWhileControl&& control)
    {
        return includeCtrl(whileControl, control);
    }

    DoWhileControl& operator<<(DoWhileControl& doWhileControl, const CodeBlock& codeBlock)
    {
        return includeCode(doWhileControl, codeBlock);
    }

    DoWhileControl& operator<<(DoWhileControl& doWhileControl, CodeBlock&& codeBlock)
    {
        return includeCode(doWhileControl, codeBlock);
    }

    DoWhileControl& operator<<(DoWhileControl& doWhileControl, const Expression& expression)
    {
        return includeExpr(doWhileControl, expression);
    }

    DoWhileControl& operator<<(DoWhileControl& doWhileControl, Expression&& expression)
    {
        return includeExpr(doWhileControl, expression);
    }

    DoWhileControl& operator<<(DoWhileControl& doWhileControl, const ForControl& control)
    {
        return includeCtrl(doWhileControl, control);
    }

    DoWhileControl& operator<<(DoWhileControl& doWhileControl, ForControl&& control)
    {
        return includeCtrl(doWhileControl, control);
    }

    DoWhileControl& operator<<(DoWhileControl& doWhileControl, const IfControl& control)
    {
        return includeCtrl(doWhileControl, control);
    }

    DoWhileControl& operator<<(DoWhileControl& doWhileControl, IfControl&& control)
    {
        return includeCtrl(doWhileControl, control);
    }

    DoWhileControl& operator<<(DoWhileControl& doWhileControl, const WhileControl& control)
    {
        return includeCtrl(doWhileControl, control);
    }

    DoWhileControl& operator<<(DoWhileControl& doWhileControl, WhileControl&& control)
    {
        return includeCtrl(doWhileControl, control);
    }

    DoWhileControl& operator<<(DoWhileControl& doWhileControl, const DoWhileControl& control)
    {
        return includeCtrl(doWhileControl, control);
    }

    DoWhileControl& operator<<(DoWhileControl& doWhileControl, DoWhileControl&& control)
    {
        return includeCtrl(doWhileControl, control);
    }
}
