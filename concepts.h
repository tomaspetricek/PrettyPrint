//
// Created by Tomáš Petříček on 23.04.2022.
//

#ifndef PRETTYPRINT_CONCEPTS_H
#define PRETTYPRINT_CONCEPTS_H

#include <type_traits>
#include <concepts>


template<typename T>
concept fundamental = std::is_fundamental<T>::value;

//template<typename T>
//concept basic = (fundamental<T> || std::is_same<T, const std::string&>::value);

template<class T>
concept object = std::is_class<T>::value;

template<typename T>
concept raw_pointer = std::is_pointer<T>::value;

//template<typename T>
//concept iterable = requires(T it)
//{
//    it.begin();
//    it.end();
//};

//template<typename T>
//concept prettifiable = requires(const T t, prettifier& pret) {
//    t.prettify(pret);
//};


#endif //PRETTYPRINT_CONCEPTS_H
