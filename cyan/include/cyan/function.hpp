//
// Created by KHML on 2020/04/15.
//

#ifndef CYAN_FUNCTION_HPP
#define CYAN_FUNCTION_HPP

#include <string>
#include <vector>

#include <cyan/type.hpp>
#include <cyan/value.hpp>
#include <cyan/value/variables.hpp>
#include <cyan/code_block.hpp>

namespace cyan
{
    class Function
    {
    public:
        Function(std::string funcName, const Type& type);

        Function(std::string funcName, const Type& type, Variable& arg);

        Function(std::string funcName, Type&& type, Variable& arg);

        Function(std::string funcName, const Type& type, std::vector<Variable>& args);

        Function(std::string funcName, Type&& type, std::vector<Variable>& args);

        Function(std::string funcName, const Type& type, const Variables& variables);

        Function(std::string funcName, Type&& type, const Variables& variables);

        ~Function();

        std::vector<std::string> codeGen(size_t indentSize) const;

        std::string declaration() const;

        Variables& args();

        CodeBlock& operator()();

        Variables& appendArg(Variable& value);

        Variables& appendArg(Variable&& value);

        const Type type;
        const std::string name;

    protected:
        Variables arguments;
        CodeBlock codeBlock;
    };

    Function& operator<<(Function& function, Variable& value);

    Function& operator<<(Function& function, Variable&& value);

    Function& operator<<(Function& function, const Expression& expression);

    Function& operator<<(Function& function, Expression&& expression);

    Function& operator<<(Function& function, const CodeBlock& codeBlock);

    Function& operator<<(Function& function, CodeBlock&& codeBlock);

    Function& operator<<(Function& function, const ForControl& control);

    Function& operator<<(Function& function, ForControl&& control);

    Function& operator<<(Function& function, const IfControl& control);

    Function& operator<<(Function& function, IfControl&& control);

    Function& operator<<(Function& function, const WhileControl& control);

    Function& operator<<(Function& function, WhileControl&& control);

    Function& operator<<(Function& function, const DoWhileControl& control);

    Function& operator<<(Function& function, DoWhileControl&& control);
}

#endif //CYAN_FUNCTION_HPP
