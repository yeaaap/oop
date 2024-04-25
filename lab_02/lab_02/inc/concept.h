//
// Created by max on 4/21/24.
//

#ifndef LAB_02_CONCEPT_H
#define LAB_02_CONCEPT_H


#include <concepts>


template <typename T>
concept Comparable = requires(T a, T b)
{
    {a == b} -> std::convertible_to<bool>;
};


#endif //LAB_02_CONCEPT_H
