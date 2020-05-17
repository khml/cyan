//
// Created by KHML on 2020/04/15.
//

#include <iostream>
#include <sstream>
#include <utility>

#include <cyan/container/namespace.hpp>
#include <cyan/utilities.hpp>
#include <cyan/container/module.hpp>

namespace cyan
{
    Module::Module(std::string _name) :name(std::move(_name))
    {
        include2c(name + ".hpp");
    }

    Module::~Module() = default;

    void Module::dump() const
    {
        std::cout << codeGen() << std::endl;
    }

    std::string Module::codeGen() const
    {
        return std::move(declares() + impl());
    }

    std::string Module::impl() const
    {
        std::ostringstream code;

        for (auto& header : header2c)
            code << header << std::endl;
        code << std::endl;

        for (auto& line : lines)
            code << line << std::endl;

        return std::move(code.str());
    }

    std::string Module::declares() const
    {
        std::ostringstream code;
        const std::string guard = "CODEGEN_" + toUpper(name) + "_HPP";

        code << "#ifndef " << guard << std::endl;
        code << "#define " << guard << std::endl << std::endl;

        for (auto& header: header2h)
            code << header << std::endl;
        code << std::endl << std::endl;

        for (auto& declare : declarations)
            code << declare << "" << std::endl;
        code << std::endl;

        code << "#endif //" << guard << std::endl;

        return std::move(code.str());
    }

    Module& Module::includeFunc(const Function& func)
    {
        declarations.emplace_back(func.declaration());
        declarations.emplace_back("");
        mergeVector(lines, func.codeGen(indentSize));
        return *this;
    }

    Module& Module::includeEnum(const EnumBlock& enumBlock)
    {
        mergeVector(lines, enumBlock.codeGen(indentSize));
        return *this;
    }

    Module& Module::includeStruct(const StructBlock& structBlock)
    {
        mergeVector(declarations, structBlock.codeGen(indentSize));
        return *this;
    }

    Module& Module::includeNameSpace(const NameSpace& nameSpace)
    {
        mergeVector(lines, nameSpace.impl(indentSize));
        mergeVector(declarations, nameSpace.declares(indentSize));
        return *this;
    }

    void Module::include2c(const std::string& headerName)
    {
        header2c.emplace_back("#include <" + headerName + ">");
    }

    void Module::include2c(std::string&& headerName)
    {
        include2c(headerName);
    }

    void Module::include2c(const Module& module)
    {
        include2c(module.name + ".hpp");
    }

    void Module::include2h(const std::string& headerName)
    {
        header2h.emplace_back("#include <" + headerName + ">");
    }

    void Module::include2h(std::string&& headerName)
    {
        include2h(headerName);
    }

    void Module::include2h(const Module& module)
    {
        include2h(module.name + ".hpp");
    }

    Module& operator<<(Module& module, const Function& func)
    {
        module.includeFunc(func);
        return module;
    }

    Module& operator<<(Module& module, const EnumBlock& enumBlock)
    {
        module.includeEnum(enumBlock);
        return module;
    }

    Module& operator<<(Module& module, const StructBlock& structBlock)
    {
        module.includeStruct(structBlock);
        return module;
    }

    Module& operator<<(Module& module, const NameSpace& nameSpace)
    {
        module.includeNameSpace(nameSpace);
        return module;
    }
}
