//
// Created by KHML on 2020/04/23.
//

#include <utility>

#include <cyan/arguments.hpp>
#include <cyan/expression.hpp>

namespace cyan
{
    Arguments::Arguments() = default;

    Arguments::~Arguments() = default;

    std::string Arguments::operator()() const
    {
        std::string arguments;
        size_t idx{0};
        for (auto& value : args)
        {
            if (idx++ == 0)
                arguments = value;
            else
                arguments += ", " + value;
        }
        return std::move("(" + arguments + ")");
    }

    Arguments& Arguments::clear()
    {
        args.clear();
        return *this;
    }

    size_t Arguments::size()
    {
        return args.size();
    }

    Expression Arguments::operator[](size_t idx)
    {
        return Expression(args[idx]);
    }
}
