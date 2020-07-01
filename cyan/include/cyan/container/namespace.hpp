/**
 * @file namespace.hpp
 * @brief NameSpace component
 * @author KHML
 */

#ifndef CYAN_CONTAINER_NAMESPACE_HPP
#define CYAN_CONTAINER_NAMESPACE_HPP

#include <cstddef>
#include <string>
#include <vector>

#include <cyan/function.hpp>
#include <cyan/enum.hpp>
#include <cyan/struct.hpp>

namespace cyan
{
    class NameSpace
    {
    public:
        explicit NameSpace(std::string name);

        ~NameSpace();

        NameSpace& includeFunc(const Function& func);

        NameSpace& includeEnum(const EnumBlock& enumBlock);

        NameSpace& includeStruct(const StructBlock& structBlock);

        NameSpace& includeNameSpace(const NameSpace& nameSpace);

        std::vector<std::string> impl(size_t indentSize) const;

        std::vector<std::string> declares(size_t indentSize) const;

        const std::string name;

    protected:
        std::vector<std::string> gen(size_t indentSize, const std::vector<std::string>& body) const;

        const size_t indentSize = 0;
        std::vector<std::string> lines;
        std::vector<std::string> declarations;
    };

    NameSpace& operator<<(NameSpace& nameSpace, const Function& func);

    NameSpace& operator<<(NameSpace& nameSpace, const EnumBlock& enumBlock);

    NameSpace& operator<<(NameSpace& nameSpace, const StructBlock& structBlock);

    NameSpace& operator<<(NameSpace& nameSpace, const NameSpace& nameSpace_);
}

#endif //CYAN_CONTAINER_NAMESPACE_HPP
