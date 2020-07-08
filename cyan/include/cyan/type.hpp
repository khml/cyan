/**
 * @file type.hpp
 * @brief Type component. wrapper for std::string
 * @author KHML
 */

#ifndef CYAN_TYPE_HPP
#define CYAN_TYPE_HPP

#include <string>

namespace cyan
{
    class Type
    {
    public:
        /**
         * @fn
         * Type Constructor
         * @param name of type. e.g. int, std::string, etc
         */
        explicit Type(std::string name);

        ~Type();

        const std::string name;
    };

    namespace types
    {
        /**
         * @fn
         * utility function of getting void type Type
         * @return Type
         */
        const Type& voidType();

        /**
         * @fn
         * utility function of getting int type Type
         * @return Type
         */
        const Type& intType();

        /**
         * @fn
         * utility function of getting float type Type
         * @return Type
         */
        const Type& floatType();

        /**
         * @fn
         * utility function of getting double type Type
         * @return Type
         */
        const Type& doubleType();

        /**
         * @fn
         * utility function of getting std::string type Type
         * @return Type
         */
        const Type& stringType();
    }

    bool operator==(const Type& left, const Type& right);
}

#endif //CYAN_TYPE_HPP
