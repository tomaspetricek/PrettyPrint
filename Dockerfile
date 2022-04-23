FROM gcc:latest

COPY ["main.cpp", "concepts.h", "name.h", "person.h", "prettifier.h", "color.hpp", "/usr/src/test/"]

WORKDIR /usr/src/test

RUN g++ -o PrettyPrint -std=c++20 main.cpp concepts.h name.h person.h prettifier.h

CMD ["./PrettyPrint"]