//
// Created by KHML on 2020/04/17.
//

#include <cyan/utilities.hpp>
#include <cyan/code_block.hpp>
#include <cyan/control.hpp>
#include <cyan/function.hpp>

namespace cyan
{
    CodeBlock::CodeBlock() = default;

    CodeBlock::CodeBlock(const CodeBlock& orig) = default;

    CodeBlock::~CodeBlock() = default;;

    std::vector<std::string> CodeBlock::codeGen(size_t indentSize) const
    {
        const auto indentSpace = indent(indentSize);
        const auto depth = indent(config::indentSize + indentSize);
        std::vector<std::string> code;

        code.emplace_back(indentSpace + "{");

        for (auto& line : lines)
            code.emplace_back(depth + line);

        code.emplace_back(indentSpace + "}");

        return std::move(code);
    }

    bool CodeBlock::empty() const
    {
        return lines.empty();
    }

    void CodeBlock::createStdOut(const Expression& value)
    {
        lines.emplace_back("std::cout << " + value() + " << std::endl;");
    }

    void CodeBlock::createStdOut(Expression&& value)
    {
        createStdOut(value);
    }

    void CodeBlock::createStdErrOut(const Expression& value)
    {
        lines.emplace_back("std::cerr << " + value() + " << std::endl;");
    }

    void CodeBlock::createStdErrOut(Expression&& value)
    {
        createStdOut(value);
    }

    void CodeBlock::declareVariable(Variable& var)
    {
        lines.emplace_back(var.initialization() + ";");
        registerVariable(var);
    }

    CodeBlock& CodeBlock::includeCode(const CodeBlock& codeBlock)
    {
        mergeVector(lines, codeBlock.codeGen(0));
        return *this;
    }

    CodeBlock& CodeBlock::includeCode(CodeBlock&& codeBlock)
    {
        return includeCode(codeBlock);
    }

    CodeBlock& CodeBlock::includeExpr(const Expression& expression)
    {
        if (expression().empty())
            lines.emplace_back("");
        else
            lines.emplace_back(expression() + ";");
        return *this;
    }

    CodeBlock& CodeBlock::includeExpr(Expression&& expression)
    {
        return includeExpr(expression);
    }

    CodeBlock& CodeBlock::linkCode(CodeBlock& codeBlock)
    {
        mergeVector(lines, std::vector<std::string>(codeBlock.lines));
        return *this;
    }

    CodeBlock& CodeBlock::linkCode(CodeBlock&& codeBlock)
    {
        mergeVector(lines, std::move(codeBlock.lines));
        return *this;
    }

    void CodeBlock::createCallee(const Function& function, std::string&& calleeArgs, std::string&& prefix)
    {
        lines.emplace_back(std::move(prefix + function.name + calleeArgs + ";"));
    }

    void CodeBlock::createCallee(const Function& function)
    {
        createCallee(function, "()");
    }

    void CodeBlock::createCallee(const Function& function, const Arguments& args)
    {
        createCallee(function, args());
    }

    void CodeBlock::createCallee(const Function& function, const Variables& args)
    {
        createCallee(function, args.callee());
    }

    void CodeBlock::createCallee(const Function& function, Variable& result)
    {
        createCallee(function, "()", result() + " = ");
        registerVariable(result);
    }

    void CodeBlock::createCallee(const Function& function, const Arguments& args, Variable& result)
    {
        createCallee(function, args(), result() + " = ");
        registerVariable(result);
    }

    void CodeBlock::createCallee(const Function& function, const Variables& args, Variable& result)
    {
        createCallee(function, args.callee(), result() + " = ");
        registerVariable(result);
    }

    CodeBlock& operator<<(CodeBlock& codeBlock, Variable& var)
    {
        codeBlock.declareVariable(var);
        return codeBlock;
    }

    CodeBlock& operator<<(CodeBlock& codeBlock, const CodeBlock& codeBlock_)
    {
        codeBlock.includeCode(codeBlock_);
        return codeBlock;
    }

    CodeBlock& operator<<(CodeBlock& codeBlock, CodeBlock&& codeBlock_)
    {
        codeBlock.includeCode(codeBlock_);
        return codeBlock;
    }

    CodeBlock& operator<<(CodeBlock& codeBlock, const Expression& expression)
    {
        codeBlock.includeExpr(expression);
        return codeBlock;
    }

    CodeBlock& operator<<(CodeBlock& codeBlock, Expression&& expression)
    {
        codeBlock.includeExpr(expression);
        return codeBlock;
    }

    CodeBlock& operator<<(CodeBlock& codeBlock, const ForControl& control)
    {
        return codeBlock.includeCtrl(control);
    }

    CodeBlock& operator<<(CodeBlock& codeBlock, ForControl&& control)
    {
        return codeBlock.includeCtrl(control);
    }

    CodeBlock& operator<<(CodeBlock& codeBlock, const IfControl& control)
    {
        return codeBlock.includeCtrl(control);
    }

    CodeBlock& operator<<(CodeBlock& codeBlock, IfControl&& control)
    {
        return codeBlock.includeCtrl(control);
    }

    CodeBlock& operator<<(CodeBlock& codeBlock, const WhileControl& control)
    {
        return codeBlock.includeCtrl(control);
    }

    CodeBlock& operator<<(CodeBlock& codeBlock, WhileControl&& control)
    {
        return codeBlock.includeCtrl(control);
    }

    CodeBlock& operator<<(CodeBlock& codeBlock, const DoWhileControl& control)
    {
        return codeBlock.includeCtrl(control);
    }

    CodeBlock& operator<<(CodeBlock& codeBlock, DoWhileControl&& control)
    {
        return codeBlock.includeCtrl(control);
    }

    CodeBlock& operator+(CodeBlock& up, CodeBlock& down)
    {
        up.linkCode(down);
        return up;
    }

    CodeBlock& operator+(CodeBlock& up, CodeBlock&& down)
    {
        up.linkCode(std::move(down));
        return up;
    }
}