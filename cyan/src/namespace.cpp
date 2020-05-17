//
// Created by KHML on 2020/04/27.
//

#include <utility>

#include <cyan/utilities.hpp>
#include "cyan/container/namespace.hpp"

namespace cyan
{

    NameSpace::NameSpace(std::string name) :name(std::move(name))
    {}

    NameSpace::~NameSpace() = default;

    NameSpace& NameSpace::includeFunc(const Function& func)
    {
        declarations.emplace_back(func.declaration());
        declarations.emplace_back("");
        mergeVector(lines, func.codeGen(indentSize));
        return *this;
    }

    NameSpace& NameSpace::includeEnum(const EnumBlock& enumBlock)
    {
        mergeVector(declarations, enumBlock.codeGen(indentSize));
        return *this;
    }

    NameSpace& NameSpace::includeStruct(const StructBlock& structBlock)
    {
        mergeVector(declarations, structBlock.codeGen(indentSize));
        return *this;
    }

    NameSpace& NameSpace::includeNameSpace(const NameSpace& nameSpace)
    {
        mergeVector(lines, nameSpace.impl(indentSize));
        mergeVector(declarations, nameSpace.declares(indentSize));
        return *this;
    }

    std::vector<std::string> NameSpace::gen(const size_t _indentSize, const std::vector<std::string>& body) const
    {
        const auto indentSpace = indent(_indentSize);
        const auto depth = indent(_indentSize + cyan::config::indentSize);

        std::vector<std::string> code;

        if (body.empty())
            return std::move(code);

        code.emplace_back(indentSpace + "namespace " + name);
        code.emplace_back(indentSpace + "{");

        for (auto& line : body)
            code.emplace_back(depth + line);

        code.emplace_back(indentSpace + "}");
        code.emplace_back(indentSpace + "");
        return std::move(code);
    }

    std::vector<std::string> NameSpace::impl(const size_t _indentSize) const
    {
        return gen(_indentSize, lines);
    }

    std::vector<std::string> NameSpace::declares(const size_t _indentSize) const
    {
        return gen(_indentSize, declarations);
    }

    NameSpace& operator<<(NameSpace& nameSpace, const Function& func)
    {
        nameSpace.includeFunc(func);
        return nameSpace;
    }

    NameSpace& operator<<(NameSpace& nameSpace, const EnumBlock& enumBlock)
    {
        nameSpace.includeEnum(enumBlock);
        return nameSpace;
    }

    NameSpace& operator<<(NameSpace& nameSpace, const StructBlock& structBlock)
    {
        nameSpace.includeStruct(structBlock);
        return nameSpace;
    }

    NameSpace& operator<<(NameSpace& nameSpace, const NameSpace& nameSpace_)
    {
        nameSpace.includeNameSpace(nameSpace_);
        return nameSpace;
    }
}
