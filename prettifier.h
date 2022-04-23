//
// Created by Tomáš Petříček on 23.04.2022.
//

#ifndef PRETTYPRINT_PRETTIFIER_H
#define PRETTYPRINT_PRETTIFIER_H

#include <string>
#include <sstream>
#include <ostream>
#include <iostream>
#include <utility>

#include "concepts.h"

std::string operator*(const std::string& base, std::size_t times)
{
    std::string res;

    for (std::size_t i{0}; i<times; i++) {
        res += base;
    }

    return res;
}

class prettifier {
    std::string indent_;
    std::string attr_div_;
    std::stringstream buff_;
    const static char attr_sep_{'\n'};
    int depth_{0};

public:
    explicit prettifier(std::string indent, std::string attr_div)
            :indent_(std::move(indent)), attr_div_(std::move(attr_div)) { }

    template<typename prettifiable>
    prettifier& operator()(const std::string& name, const prettifiable& obj)
    {
        add_attr(name, obj);
        return *this;
    }

    void add_attr(const std::string& name, const fundamental auto& val)
    {
        buff_ << indent_*depth_ << name << attr_div_ << val << attr_sep_;
    }

    void add_attr(const std::string& name, const std::string& str)
    {
        buff_ << indent_*depth_ << name << attr_div_ << str << attr_sep_;
    }

    void add_attr(const std::string& name, const object auto& obj)
    {
        buff_ << indent_*depth_;
        depth_++;
        buff_ << name << attr_sep_;
        obj.prettify(*this);
        depth_--;
    }

    void add_attr(const std::string& name, const raw_pointer auto& ptr)
    {
        add_attr(name, *ptr);
    }

    std::string string() {
        return buff_.str();
    }

    friend std::ostream& operator<<(std::ostream& os, prettifier& pret)
    {
        return os << pret.buff_.rdbuf();
    }
};

#endif //PRETTYPRINT_PRETTIFIER_H
