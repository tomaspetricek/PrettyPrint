#include <iostream>
#include <vector>
#include "prettifier.h"
#include "name.h"
#include "person.h"


int main()
{
    prettifier prettify{' ', ": "};

    pp::person me{pp::name{"Tomas", "Petricek"}, 23};
    std::cout << prettify("me", me) << std::endl;

//    std::vector<pp::person> people{
//            {pp::name{"Tomas", "Petricek"}, 23},
//            {pp::name{"Jakub", "Petricek"}, 23},
//    };
//
//    std::cout << prettify(people) << std::endl;
    return 0;
}