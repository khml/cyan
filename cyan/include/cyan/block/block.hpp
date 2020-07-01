/**
 * @file block.hpp
 * @brief block component interface
 * @author KHML
 */

#ifndef CYAN_BLOCK_HPP
#define CYAN_BLOCK_HPP

/* Block Class
 *
 * member:
 *   CodeBlock codeBlock;
 *
 *   CodeBlock& operator()();
 *
 */

namespace cyan
{
    class CodeBlock;

    class Expression;

    class Function;

    class ForControl;

    class IfControl;

    class WhileControl;

    class DoWhileControl;

    template<typename Block>
    Block& includeExpr(Block& block, const Expression& expression)
    {
        block().includeExpr(expression);
        return block;
    }

    template<typename Block>
    Block& includeExpr(Block& block, Expression&& expression)
    {
        block().includeExpr(expression);
        return block;
    }

    template<typename Block>
    Block& includeCode(Block& block, const CodeBlock& codeBlock){
        block().includeCode(codeBlock);
        return block;
    }

    template<typename Block>
    Block& includeCode(Block& block, CodeBlock&& codeBlock){
        block().includeCode(codeBlock);
        return block;
    }

    template<typename Block, typename Control>
    Block& includeCtrl(Block& block, const Control& control){
        block().includeCtrl(control);
        return block;
    }

    template<typename Block, typename Control>
    Block& includeCtrl(Block& block, Control&& control){
        block().includeCtrl(control);
        return block;
    }
}

#endif //CYAN_BLOCK_HPP
