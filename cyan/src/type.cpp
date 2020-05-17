//
// Created by KHML on 2020/04/15.
//

#include <utility>

#include <cyan/type.hpp>

namespace cyan
{
    Type::Type(std::string name) :name(std::move(name))
    {}

    Type::~Type() = default;

    namespace types
    {
        const Type& voidType()
        {
            static const Type voidTy("void");
            return voidTy;
        }

        const Type& intType()
        {
            static const Type intTy("int");
            return intTy;
        }

        const Type& floatType()
        {
            static const Type floatTy("float");
            return floatTy;
        }

        const Type& doubleType()
        {
            static const Type doubleTy("double");
            return doubleTy;
        }


        const Type& stringType()
        {
            static const Type stringTy("std::string");
            return stringTy;
        }
    }

    bool operator==(const Type& left, const Type& right)
    {
        return left.name == right.name;
    }
}
