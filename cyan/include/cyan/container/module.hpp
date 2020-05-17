//
// Created by KHML on 2020/04/15.
//

#ifndef CYAN_CONTAINER_MODULE_HPP
#define CYAN_CONTAINER_MODULE_HPP

#include <cstddef>
#include <string>
#include <vector>

#include <cyan/function.hpp>
#include <cyan/enum.hpp>
#include <cyan/struct.hpp>

namespace cyan
{
    class NameSpace;

    class Module
    {
    public:
        explicit Module(std::string name);

        virtual ~Module();

        void dump() const;

        std::string impl() const;

        std::string declares() const;

        Module& includeFunc(const Function& func);

        Module& includeEnum(const EnumBlock& enumBlock);

        Module& includeStruct(const StructBlock& structBlock);

        Module& includeNameSpace(const NameSpace& nameSpace);

        void include2c(const std::string& headerName);

        void include2c(std::string&& headerName);

        void include2c(const Module& module);

        void include2h(const std::string& headerName);

        void include2h(std::string&& headerName);

        void include2h(const Module& module);

        const std::string name;

    protected:
        const size_t indentSize = 0;
        std::vector<std::string> lines;
        std::vector<std::string> header2c;
        std::vector<std::string> header2h;
        std::vector<std::string> declarations;

        std::string codeGen() const;
    };

    Module& operator<<(Module& module, const Function& func);

    Module& operator<<(Module& module, const EnumBlock& enumBlock);

    Module& operator<<(Module& module, const StructBlock& structBlock);

    Module& operator<<(Module& module, const NameSpace& nameSpace);
}

#endif //CYAN_CONTAINER_MODULE_HPP
