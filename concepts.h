//
// Created by Tomáš Petříček on 23.04.2022.
//

#ifndef PRETTYPRINT_CONCEPTS_H
#define PRETTYPRINT_CONCEPTS_H

#include <type_traits>
#include <concepts>
//#include <ranges>

template<typename T>
concept fundamental = std::is_fundamental<T>::value;

template <class T>
concept object = std::is_class<T>::value;

//template<typename T>
//concept iterable = std::ranges::range<T>;



#endif //PRETTYPRINT_CONCEPTS_H
