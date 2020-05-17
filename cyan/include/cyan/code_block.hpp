//
// Created by KHML on 2020/04/17.
//

#ifndef CYAN_CODE_BLOCK_HPP
#define CYAN_CODE_BLOCK_HPP

#include <string>
#include <utility>
#include <vector>

#include <cyan/arguments.hpp>
#include <cyan/block/block.hpp>
#include <cyan/expression.hpp>
#include <cyan/value/value.hpp>
#include <cyan/value/variables.hpp>

namespace cyan
{
    class CodeBlock
    {
    public:
        CodeBlock();

        CodeBlock(const CodeBlock& orig);

        ~CodeBlock();

        std::vector<std::string> codeGen(size_t indentSize) const;

        bool empty() const;

        void declareVariable(Variable& var);

        CodeBlock& includeCode(const CodeBlock& codeBlock);

        CodeBlock& includeCode(CodeBlock&& codeBlock);

        CodeBlock& includeExpr(const Expression& expression);

        CodeBlock& includeExpr(Expression&& expression);

        template<typename Control>
        CodeBlock& includeCtrl(const Control& control);

        template<typename Control>
        CodeBlock& includeCtrl(Control&& control);

        CodeBlock& linkCode(CodeBlock& codeBlock);

        CodeBlock& linkCode(CodeBlock&& codeBlock);

        template<typename Value>
        void createAdd(Value& right, Value& left, Variable& result);

        template<typename Value>
        void createSub(Value& right, Value& left, Variable& result);

        template<typename Value>
        void createMul(Value& right, Value& left, Variable& result);

        template<typename Value>
        void createDiv(Value& right, Value& left, Variable& result);

        template<typename Value>
        void createMod(Value& right, Value& left, Variable& result);

        template<typename Value>
        void createRetValue(Value& value);

        template<typename Value>
        void createRetValue(Value&& value);

        template<typename Value>
        void createStdOut(const Value& value);

        template<typename Value>
        void createStdOut(Value&& value);

        void createStdOut(const Expression& value);

        void createStdOut(Expression&& value);

        template<typename Value>
        void createStdErrOut(const Value& value);

        template<typename Value>
        void createStdErrOut(Value&& value);

        void createStdErrOut(const Expression& value);

        void createStdErrOut(Expression&& value);

        void createCallee(const Function& function);

        void createCallee(const Function& function, const Arguments& args);

        void createCallee(const Function& function, const Variables& args);

        void createCallee(const Function& function, Variable& result);

        void createCallee(const Function& function, const Arguments& args, Variable& result);

        void createCallee(const Function& function, const Variables& args, Variable& result);

    protected:
        std::vector<std::string> lines;

        template<typename Value>
        void createArithmeticOp(std::string&& op, Value& right, Value& left, Variable& result);

        void createCallee(const Function& function, std::string&& calleeArgs, std::string&& prefix = "");
    };

    CodeBlock& operator<<(CodeBlock& codeBlock, Variable& var);

    CodeBlock& operator<<(CodeBlock& codeBlock, const CodeBlock& codeBlock_);

    CodeBlock& operator<<(CodeBlock& codeBlock, CodeBlock&& codeBlock_);

    CodeBlock& operator<<(CodeBlock& codeBlock, const Expression& expression);

    CodeBlock& operator<<(CodeBlock& codeBlock, Expression&& expression);

    CodeBlock& operator<<(CodeBlock& codeBlock, const ForControl& control);

    CodeBlock& operator<<(CodeBlock& codeBlock, ForControl&& control);

    CodeBlock& operator<<(CodeBlock& codeBlock, const IfControl& control);

    CodeBlock& operator<<(CodeBlock& codeBlock, IfControl&& control);

    CodeBlock& operator<<(CodeBlock& codeBlock, const WhileControl& control);

    CodeBlock& operator<<(CodeBlock& codeBlock, WhileControl&& control);

    CodeBlock& operator<<(CodeBlock& codeBlock, const DoWhileControl& control);

    CodeBlock& operator<<(CodeBlock& codeBlock, DoWhileControl&& control);

    CodeBlock& operator+(CodeBlock& up, CodeBlock& down);

    CodeBlock& operator+(CodeBlock& up, CodeBlock&& down);
}

#include <cyan/impl/code_block.hpp>

#endif //CYAN_CODE_BLOCK_HPP
