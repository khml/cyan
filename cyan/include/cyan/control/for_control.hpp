/**
 * @file for_control.hpp
 * @brief For-Control component
 * @author KHML
 */

#ifndef CYAN_CONTROL_FOR_CONTROL_HPP
#define CYAN_CONTROL_FOR_CONTROL_HPP

#include <cyan/control/control.hpp>
#include <cyan/code_block.hpp>
#include <cyan/expression.hpp>
#include <cyan/value/variable.hpp>

namespace cyan
{
    class ForControl
    {
    public:
        ForControl();

        ForControl(Expression& init, Expression& condition, Expression& iterExpr);

        ForControl(Expression&& init, Expression& condition, Expression& iterExpr);

        ForControl(Variable& init, Expression& condition, Expression& iterExpr);

        ForControl(Variable& init, Expression& vectorExp);

        ForControl(Variable& iter, Variable& vectorVar);

        ~ForControl();

        std::vector<std::string> codeGen(size_t indentSize) const;

        CodeBlock& operator()();

        ForControl& declareVariable(Variable& var);

    protected:
        std::string forSentence;
        CodeBlock codeBlock;
    };

    ForControl& operator<<(ForControl& forControl, Variable& var);

    ForControl& operator<<(ForControl& forControl, const CodeBlock& codeBlock);

    ForControl& operator<<(ForControl& forControl, CodeBlock&& codeBlock);

    ForControl& operator<<(ForControl& forControl, const Expression& expression);

    ForControl& operator<<(ForControl& forControl, Expression&& expression);

    ForControl& operator<<(ForControl& forControl, const ForControl& control);

    ForControl& operator<<(ForControl& forControl, ForControl&& control);

    ForControl& operator<<(ForControl& forControl, const IfControl& control);

    ForControl& operator<<(ForControl& forControl, IfControl&& control);

    ForControl& operator<<(ForControl& forControl, const WhileControl& control);

    ForControl& operator<<(ForControl& forControl, WhileControl&& control);

    ForControl& operator<<(ForControl& forControl, const DoWhileControl& control);

    ForControl& operator<<(ForControl& forControl, DoWhileControl&& control);
}

#endif //CYAN_CONTROL_FOR_CONTROL_HPP
