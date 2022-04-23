//
// Created by Tomáš Petříček on 23.04.2022.
//

#ifndef PRETTYPRINT_PERSON_H
#define PRETTYPRINT_PERSON_H

#include <utility>

#include "prettifier.h"
#include "name.h"

namespace pp {
    class person {
        name name_;
        int age_;

    public:
        person(pp::name name, int age)
                :name_(std::move(name)), age_(age) { }

        void prettify(prettifier& pret) const
        {
            pret.add_attr("name", name_);
            pret.add_attr("age", age_);
        }
    };
}

#endif //PRETTYPRINT_PERSON_H
