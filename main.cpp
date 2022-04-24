#include <iostream>
#include <memory>
#include <utility>
#include <vector>

#include "prettifier.h"
#include "name.h"
#include "person.h"

class package {
    std::string name_;
    std::vector<std::vector<std::vector<float>>> tensor_;
    pp::person someone_;

public:
    package(std::string name, std::vector<std::vector<std::vector<float>>> tensor, pp::person someone)
            :name_(std::move(name)), tensor_(std::move(tensor)), someone_(std::move(someone)) { }

    void prettify(prettifier& pret) const
    {
        pret.add_attr("title", name_);
        pret.add_attr("tensor", tensor_);
        pret.add_attr("someone", someone_);
    }
};

// Build docker image: sudo docker build . -t test:1
// Run docker image: docker run --rm -it test:1
int main()
{
    prettifier prettify{" ", ": "};

    std::cout << "Pretty Printing" << std::endl;

    pp::person someone{pp::name{"Tomas", "Petricek"}, 23};
    std::cout << "Object:" << std::endl
              << prettify("me", someone) << std::endl;

    std::cout << "Fundamental:" << std::endl
              << prettify("temp", 70) << std::endl;

    std::shared_ptr<pp::person> someone_ptr = std::make_shared<pp::person>(someone);
    std::cout << "Object pointer:" << std::endl
              << prettify("me ptr", someone_ptr.get()) << std::endl;

    std::vector<pp::person> people{
            someone,
            someone,
    };
    std::cout << "Object iterable:" << std::endl
              << prettify("people", people) << std::endl;

    std::vector<int> nums{1, 2, 3, 4, 5};
    std::cout << "Fundamental iterable:" << std::endl
              << prettify("nums", nums) << std::endl;

    std::vector<std::vector<float>> mat{
            {1.2, 2.5, 3.4},
            {4.1, 5.3, 6.9},
            {7.8, 8.1, 9.7}
    };
    std::cout << "Nested fundamental iterable:" << std::endl
              << prettify("mat", mat) << std::endl;

    std::vector<std::vector<std::vector<float>>> tensor{mat, mat, mat};
    std::cout << "Double nested fundamental iterable:" << std::endl
              << prettify("tensor", tensor) << std::endl;

    package pack{"christmas", tensor, someone};
    std::cout << "Combined object:" << std::endl
              << prettify("pack", pack) << std::endl;
    return 0;
}