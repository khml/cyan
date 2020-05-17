//
// Created by KHML on 2020/04/17.
//

#include <algorithm>
#include <iterator>
#include <sys/stat.h>
#include <sstream>
#include <utility>
#include <vector>

#include <cyan/utilities.hpp>

namespace cyan
{
    std::string indent(size_t depth)
    {
        return std::move(std::string(depth, ' '));
    }

    bool isNumber(const Type& type)
    {
        static const std::vector<std::string> types = {"int", "float", "double"};
        auto result = std::find(types.begin(), types.end(), type.name);
        return !(result == types.end());
    }

    bool createDir(const std::string& directoryName)
    {
        return mkdir(directoryName.c_str(), S_IRWXU) >= 0;
    }

    bool createDir(std::string&& directoryName)
    {
        return createDir(directoryName);
    }

    std::string toUpper(const std::string& str)
    {
        std::string destination;
        destination.resize(str.size());
        std::transform(str.cbegin(), str.cend(), destination.begin(), toupper);
        return std::move(destination);
    }

    std::vector<std::string> splitByLine(const std::string& str)
    {
        std::stringstream ss(str);
        std::vector<std::string> lines;
        std::string line;

        while (std::getline(ss, line))
            lines.push_back(line);

        return std::move(lines);
    }

    std::vector<std::string> splitByLine(std::string&& str)
    {
        return std::move(splitByLine(str));
    }
}
