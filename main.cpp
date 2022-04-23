#include <iostream>
#include "prettifier.h"
#include "name.h"
#include "person.h"


int main()
{
    prettifier prettify{' '};

    pp::person me{{"Tomas", "Petricek"}, 23};

    std::cout << prettify(me) << std::endl;
    return 0;
}