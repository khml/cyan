//
// Created by KHML on 2020/04/15.
//

#include <utility>

#include <cyan/utilities.hpp>
#include <cyan/value.hpp>
#include <cyan/control.hpp>
#include <cyan/function.hpp>

namespace cyan
{
    Function::Function(std::string funcName, const Type& type) :name(std::move(funcName)), type(type)
    {}

    Function::Function(std::string funcName, const Type& type, Variable& arg) :name(std::move(funcName)), type(type)
    {
        arguments << arg;
    }

    Function::Function(std::string funcName, Type&& type, Variable& arg) :Function(std::move(funcName), type, arg)
    {}

    Function::Function(std::string funcName, const Type& type, std::vector<Variable>& args) :name(std::move(funcName)),
        type(type)
    {
        for (auto& arg : args)
            arguments << arg;
    }

    Function::Function(std::string funcName, Type&& type, std::vector<Variable>& args) :
        Function(std::move(funcName), type, args)
    {}

    Function::Function(std::string funcName, const Type& type, const Variables& variables) :name(std::move(funcName)),
        type(type), arguments(variables)
    {}

    Function::Function(std::string funcName, Type&& type, const Variables& variables) :
        Function(std::move(funcName), type, variables)
    {}

    Function::~Function() = default;

    std::vector<std::string> Function::codeGen(size_t indentSize) const
    {
        const auto indentSpace = indent(indentSize);
        const auto depth = indent(config::indentSize);

        std::vector<std::string> code;
        code.emplace_back(indentSpace + type.name + " " + name + arguments.implArgs());
        mergeVector(code, codeBlock.codeGen(indentSize));
        code.emplace_back("");

        return std::move(code);
    }

    std::string Function::declaration() const
    {
        return std::move(type.name + " " + name + arguments.args() + ";");
    }

    Variables& Function::args()
    {
        return arguments;
    }

    CodeBlock& Function::operator()()
    {
        return codeBlock;
    }

    Variables& Function::appendArg(Variable& value)
    {
        return arguments.append(value);
    }

    Variables& Function::appendArg(Variable&& value)
    {
        return arguments.append(value);
    }

    Function& operator<<(Function& function, Variable& value)
    {
        function.appendArg(value);
        return function;
    }

    Function& operator<<(Function& function, Variable&& value)
    {
        function.appendArg(value);
        return function;
    }

    Function& operator<<(Function& function, const Expression& expression)
    {
        return includeExpr(function, expression);
    }

    Function& operator<<(Function& function, Expression&& expression)
    {
        return includeExpr(function, expression);
    }

    Function& operator<<(Function& function, const CodeBlock& codeBlock)
    {
        return includeCode(function, codeBlock);
    }

    Function& operator<<(Function& function, CodeBlock&& codeBlock)
    {
        return includeCode(function, codeBlock);
    }

    Function& operator<<(Function& function, const ForControl& control)
    {
        return includeCtrl(function, control);
    }

    Function& operator<<(Function& function, ForControl&& control)
    {
        return includeCtrl(function, control);
    }

    Function& operator<<(Function& function, const IfControl& control)
    {
        return includeCtrl(function, control);
    }

    Function& operator<<(Function& function, IfControl&& control)
    {
        return includeCtrl(function, control);
    }

    Function& operator<<(Function& function, const WhileControl& control)
    {
        return includeCtrl(function, control);
    }

    Function& operator<<(Function& function, WhileControl&& control)
    {
        return includeCtrl(function, control);
    }

    Function& operator<<(Function& function, const DoWhileControl& control)
    {
        return includeCtrl(function, control);
    }

    Function& operator<<(Function& function, DoWhileControl&& control)
    {
        return includeCtrl(function, control);
    }
}
