#include <iostream>
#include <vector>
#include <memory>
#include "prettifier.h"
#include "name.h"
#include "person.h"

// Build docker image: sudo docker build . -t test:1
// Run docker image: docker run --rm -it test:1
int main()
{
    prettifier prettify{"  ", ": "};

    std::cout << "Pretty Printing" << std::endl;

    pp::person someone{pp::name{"Kody", "Coates"}, 17};
    std::cout << prettify("someone", someone) << std::endl;

    std::cout << prettify("temp", 70);

    std::shared_ptr<pp::person> someone_ptr = std::make_shared<pp::person>(someone);
    std::cout << prettify("someone", someone_ptr.get());

    return 0;
}