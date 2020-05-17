//
// Created by KHML on 2020/04/25.
//

#include <utility>

#include <cyan/utilities.hpp>
#include <cyan/control/if_control.hpp>
#include <cyan/control/while_control.hpp>
#include <cyan/control/for_control.hpp>

namespace cyan
{
    ForControl::ForControl() :forSentence(";;")
    {}

    ForControl::ForControl(Expression& init, Expression& condition, Expression& iterExpr)
    {
        forSentence = init() + "; " + condition() + "; " + iterExpr();
    }

    ForControl::ForControl(Expression&& init, Expression& condition, Expression& iterExpr) :
        ForControl(init, condition, iterExpr)
    {}

    ForControl::ForControl(Variable& init, Expression& condition, Expression& iterExpr)
    {
        forSentence = init.arg();
        registerVariable(init);
        forSentence += "; " + condition() + "; " + iterExpr();
    }

    ForControl::ForControl(Variable& init, Expression& vectorExp)
    {
        forSentence = init() + " : " + vectorExp();
        registerVariable(init);
    }

    ForControl::ForControl(Variable& iter, Variable& vectorVar)
    {
        forSentence = iter() + " = " + vectorVar() + ".begin(); ";
        registerVariable(iter);
        forSentence += iter() + " != " + vectorVar() + ".end(); " + Expression(iter).postIncrement()();
    }

    ForControl::~ForControl() = default;

    std::vector<std::string> ForControl::codeGen(size_t indentSize) const
    {
        const auto indentSpace = indent(indentSize);
        const auto depth = indent(indentSize + cyan::config::indentSize);

        std::vector<std::string> code;
        code.emplace_back(indentSpace + "for(" + forSentence + ")");
        mergeVector(code, codeBlock.codeGen(indentSize));
        code.emplace_back("");

        return std::move(code);
    }

    CodeBlock& ForControl::operator()()
    {
        return codeBlock;
    }

    ForControl& ForControl::declareVariable(Variable& var)
    {
        codeBlock.declareVariable(var);
        return *this;
    }

    ForControl& operator<<(ForControl& forControl, Variable& var)
    {
        forControl.declareVariable(var);
        return forControl;
    }

    ForControl& operator<<(ForControl& forControl, const CodeBlock& codeBlock)
    {
        return includeCode(forControl, codeBlock);
    }

    ForControl& operator<<(ForControl& forControl, CodeBlock&& codeBlock)
    {
        return includeCode(forControl, codeBlock);
    }

    ForControl& operator<<(ForControl& forControl, const Expression& expression)
    {
        return includeExpr(forControl, expression);
    }

    ForControl& operator<<(ForControl& forControl, Expression&& expression)
    {
        return includeExpr(forControl, expression);
    }

    ForControl& operator<<(ForControl& forControl, const ForControl& control)
    {
        return includeCtrl(forControl, control);
    }

    ForControl& operator<<(ForControl& forControl, ForControl&& control)
    {
        return includeCtrl(forControl, control);
    }

    ForControl& operator<<(ForControl& forControl, const IfControl& control)
    {
        return includeCtrl(forControl, control);
    }

    ForControl& operator<<(ForControl& forControl, IfControl&& control)
    {
        return includeCtrl(forControl, control);
    }

    ForControl& operator<<(ForControl& forControl, const WhileControl& control)
    {
        return includeCtrl(forControl, control);
    }

    ForControl& operator<<(ForControl& forControl, WhileControl&& control)
    {
        return includeCtrl(forControl, control);
    }

    ForControl& operator<<(ForControl& forControl, const DoWhileControl& control)
    {
        return includeCtrl(forControl, control);
    }

    ForControl& operator<<(ForControl& forControl, DoWhileControl&& control)
    {
        return includeCtrl(forControl, control);
    }
}
