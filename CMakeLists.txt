cmake_minimum_required(VERSION 3.17)
project(PrettyPrint)

set(CMAKE_CXX_STANDARD 20)

add_executable(PrettyPrint main.cpp concepts.h prettifier.h person.h name.h)