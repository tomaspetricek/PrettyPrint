//
// Created by Tomáš Petříček on 23.04.2022.
//

#ifndef PRETTYPRINT_NAME_H
#define PRETTYPRINT_NAME_H

#include "prettifier.h"

namespace pp {
    class name {
        std::string first;
        std::string last;

    public:
        explicit name(std::string first, std::string last)
                :first(std::move(first)), last(std::move(last)) { }

        void prettify(prettifier& pret) const
        {
            pret.add_attr("first", first);
            pret.add_attr("last", last);
        }
    };
}

#endif //PRETTYPRINT_NAME_H
