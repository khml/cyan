/**
 * @file if_control.hpp
 * @brief IF-Control component
 * @author KHML
 */

#ifndef CYAN_CONTROL_IF_CONTROL_HPP
#define CYAN_CONTROL_IF_CONTROL_HPP

#include <string>
#include <tuple>
#include <vector>

#include <cyan/control/control.hpp>
#include <cyan/code_block.hpp>
#include <cyan/expression.hpp>

namespace cyan
{
    class IfControl
    {
    public:
        IfControl();

        ~IfControl();

        std::vector<std::string> codeGen(size_t indentSize) const;

        IfControl& if_(Expression& condition, CodeBlock& codeBlock);

        IfControl& elseIf_(Expression& condition, CodeBlock& codeBlock);

        IfControl& else_(CodeBlock& codeBlock);

    protected:
        std::tuple<Expression, CodeBlock> _if;
        CodeBlock _else;
        std::vector<std::tuple<Expression, CodeBlock>> _elseIfs;
    };
}

#endif //CYAN_CONTROL_IF_CONTROL_HPP
