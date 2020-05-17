//
// Created by KHML on 2020/04/30.
//

#include <cstdlib>
#include <fstream>

#include <cyan/utilities.hpp>
#include "cyan/builder.hpp"

namespace cyan
{
    Builder::Builder()
    {
        createDir(_dirname);
        createDir(_headers);
    }

    Builder::~Builder() = default;

    Builder& Builder::instance()
    {
        static Builder _instance;
        return _instance;
    }

    void Builder::append(const std::string& name)
    {
        sources.emplace_back(_dirname + name + ".cpp");
        headers.emplace_back(_headers + name + ".hpp");
        objs.emplace_back(std::move(_dirname + name + ".o"));
    }

    bool Builder::dump(const Module& module)
    {
        static Builder instance;

        append(module.name);
        std::ofstream impl(sources.back());
        std::ofstream header(headers.back());

        if (impl.fail() || header.fail())
            return false;

        impl << module.impl();
        header << module.declares();

        return true;
    }

    bool Builder::build(const std::string& name)
    {
        if (name.empty())
            return false;

        std::ofstream logfile(_dirname + "build.log");
        if(logfile.fail())
            return false;

        const std::string option = " -std=c++14 -I " + _headers + " ";
        std::string cmd;

        for (size_t idx = 0; idx < objs.size(); idx++)
        {
            cmd = "g++ -c -o " + objs[idx] + " " + option + sources[idx];
            logfile << cmd << std::endl;
            if(std::system(cmd.c_str()) != 0)
                return false;
        }

        cmd.clear();
        for (auto& obj : objs)
            cmd += obj + " ";

        cmd = "g++ -o " + name + option + cmd;
        logfile << cmd << std::endl;
        return std::system(cmd.c_str()) == 0;

    }

    bool Builder::build(std::string&& name)
    {
        return build(name);
    }
}
