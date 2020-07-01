/**
 * @file code_block.hpp
 * @brief impl CodeBlock template functions
 * @author KHML
 */

#ifndef CYAN_IMPL_CODE_BLOCK_HPP
#define CYAN_IMPL_CODE_BLOCK_HPP

namespace cyan
{
    template<typename Control>
    CodeBlock& CodeBlock::includeCtrl(const Control& control)
    {
        mergeVector(lines, control.codeGen(0));
        return *this;
    }

    template<typename Control>
    CodeBlock& CodeBlock::includeCtrl(Control&& control)
    {
        mergeVector(lines, control.codeGen(0));
        return *this;
    }

    template<typename Value>
    void CodeBlock::createArithmeticOp(std::string&& op, Value& right, Value& left, cyan::Variable& result)
    {
        lines.emplace_back(result() + " = " + right() + " " + op + " " + left() + ";");
        registerVariable(result);
    }

    template<typename Value>
    void CodeBlock::createAdd(Value& right, Value& left, Variable& result)
    {
        createArithmeticOp("+", right, left, result);
        registerVariable(result);
    }

    template<typename Value>
    void CodeBlock::createSub(Value& right, Value& left, Variable& result)
    {
        createArithmeticOp("-", right, left, result);
        registerVariable(result);
    }

    template<typename Value>
    void CodeBlock::createMul(Value& right, Value& left, Variable& result)
    {
        createArithmeticOp("*", right, left, result);
        registerVariable(result);
    }

    template<typename Value>
    void CodeBlock::createDiv(Value& right, Value& left, Variable& result)
    {
        createArithmeticOp("/", right, left, result);
        registerVariable(result);
    }

    template<typename Value>
    void CodeBlock::createMod(Value& right, Value& left, Variable& result)
    {
        createArithmeticOp("%", right, left, result);
        registerVariable(result);
    }

    template<typename Value>
    void CodeBlock::createRetValue(Value& value)
    {
        lines.emplace_back("return " + value() + ";");
    }

    template<typename Value>
    void CodeBlock::createRetValue(Value&& value)
    {
        lines.emplace_back("return " + value() + ";");
    }

    template<typename Value>
    void CodeBlock::createStdOut(const Value& value)
    {
        lines.emplace_back("std::cout << " + value() + " << std::endl;");
    }

    template<typename Value>
    void CodeBlock::createStdOut(Value&& value)
    {
        createStdOut(value);
    }

    template<typename Value>
    void CodeBlock::createStdErrOut(const Value& value)
    {
        lines.emplace_back("std::cerr << " + value() + " << std::endl;");
    }

    template<typename Value>
    void CodeBlock::createStdErrOut(Value&& value)
    {
        createStdErrOut(value);
    }
}

#endif //CYAN_CODE_BLOCK_HPP
