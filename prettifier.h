//
// Created by Tomáš Petříček on 23.04.2022.
//

#ifndef PRETTYPRINT_PRETTIFIER_H
#define PRETTYPRINT_PRETTIFIER_H

#include <string>
#include <sstream>
#include <ostream>
#include "concepts.h"


class prettifier {
    char indent_;
    std::stringstream buff_;

public:
    const static char attr_sep{';'};
    const static char obj_sep{};

    explicit prettifier(char indent)
            :indent_(indent) { }

    template<class Prettifiable>
    prettifier& operator()(const Prettifiable& obj)
    {
        obj.prettify(*this);
        return *this;
    }

    void add_attr(const std::string& name, const fundamental auto& val)
    {
        buff_ << name << ": " << val << attr_sep;
    }

    void add_attr(const std::string& name, const object auto& obj)
    {
        buff_ << name << ": " << obj.pretify << obj_sep;
    }

    friend std::ostream& operator<<(std::ostream& os, prettifier& pret)
    {
        std::string line;

        while (std::getline(pret.buff_, line, prettifier::attr_sep)) {
            os << line << "\n";
        }

        return os;
    }
};

#endif //PRETTYPRINT_PRETTIFIER_H
