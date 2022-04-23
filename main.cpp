#include <iostream>
#include <memory>

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

    return 0;
}