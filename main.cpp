#include <iostream>
#include <memory>
#include <vector>

#include "prettifier.h"
#include "name.h"
#include "person.h"
#include "color.hpp"

// Build docker image: sudo docker build . -t test:1
// Run docker image: docker run --rm -it test:1
int main()
{
    prettifier prettify{"  ", ": "};

    std::cout << "Pretty Printing" << std::endl;

    pp::person someone{pp::name{"Tomas", "Petricek"}, 23};
    std::cout << color::rize(prettify("me", someone).string(), "Yellow", "Dark Gray", "Default");

    std::cout << prettify("temp", 70);

    std::shared_ptr<pp::person> someone_ptr = std::make_shared<pp::person>(someone);
    std::cout << prettify("me ptr", someone_ptr.get());

    std::vector<pp::person> people {
        someone,
        someone,
    };

    std::cout << prettify("people", people);

    std::vector<int> nums{1, 2, 3, 4, 5};
    std::cout << prettify("nums", nums);

    std::vector<std::vector<int>> mat{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    std::cout << prettify("mat", mat);
    return 0;
}