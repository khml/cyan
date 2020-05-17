//
// Created by KHML on 2020/04/24.
//

#ifndef CYAN_CONTROL_WHILE_CONTROL_HPP
#define CYAN_CONTROL_WHILE_CONTROL_HPP

#include <string>
#include <vector>

#include <cyan/control/control.hpp>
#include <cyan/code_block.hpp>
#include <cyan/expression.hpp>

namespace cyan
{
    class WhileControl
    {
    public:
        WhileControl();

        explicit WhileControl(const Expression& condition);

        explicit WhileControl(Expression&& condition);

        WhileControl(const Expression& condition, const CodeBlock& statements);

        ~WhileControl();

        std::vector<std::string> codeGen(size_t indentSize) const;

        CodeBlock& operator()();

    protected:
        Expression condition;
        CodeBlock statements;
    };

    class DoWhileControl
    {
    public:
        DoWhileControl();

        explicit DoWhileControl(const Expression& condition);

        explicit DoWhileControl(Expression&& condition);

        DoWhileControl(const Expression& condition, const CodeBlock& statements);

        ~DoWhileControl();

        std::vector<std::string> codeGen(size_t indentSize) const;

        CodeBlock& operator()();

    protected:
        Expression condition;
        CodeBlock statements;
    };

    WhileControl& operator<<(WhileControl& whileControl, const CodeBlock& codeBlock);

    WhileControl& operator<<(WhileControl& whileControl, CodeBlock&& codeBlock);

    WhileControl& operator<<(WhileControl& whileControl, const Expression& expression);

    WhileControl& operator<<(WhileControl& whileControl, Expression&& expression);

    WhileControl& operator<<(WhileControl& whileControl, const ForControl& control);

    WhileControl& operator<<(WhileControl& whileControl, ForControl&& control);

    WhileControl& operator<<(WhileControl& whileControl, const IfControl& control);

    WhileControl& operator<<(WhileControl& whileControl, IfControl&& control);

    WhileControl& operator<<(WhileControl& whileControl, const WhileControl& control);

    WhileControl& operator<<(WhileControl& whileControl, WhileControl&& control);

    WhileControl& operator<<(WhileControl& whileControl, const DoWhileControl& control);

    WhileControl& operator<<(WhileControl& whileControl, DoWhileControl&& control);

    DoWhileControl& operator<<(DoWhileControl& doWhileControl, const CodeBlock& codeBlock);

    DoWhileControl& operator<<(DoWhileControl& doWhileControl, CodeBlock&& codeBlock);

    DoWhileControl& operator<<(DoWhileControl& doWhileControl, const Expression& expression);

    DoWhileControl& operator<<(DoWhileControl& doWhileControl, Expression&& expression);

    DoWhileControl& operator<<(DoWhileControl& doWhileControl, const ForControl& control);

    DoWhileControl& operator<<(DoWhileControl& doWhileControl, ForControl&& control);

    DoWhileControl& operator<<(DoWhileControl& doWhileControl, const IfControl& control);

    DoWhileControl& operator<<(DoWhileControl& doWhileControl, IfControl&& control);

    DoWhileControl& operator<<(DoWhileControl& doWhileControl, const WhileControl& control);

    DoWhileControl& operator<<(DoWhileControl& doWhileControl, WhileControl&& control);

    DoWhileControl& operator<<(DoWhileControl& doWhileControl, const DoWhileControl& control);

    DoWhileControl& operator<<(DoWhileControl& doWhileControl, DoWhileControl&& control);

}

#endif //CYAN_CONTROL_WHILE_CONTROL_HPP
