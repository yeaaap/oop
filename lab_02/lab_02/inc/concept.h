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


template <typename T>
concept Assignable = requires(T a, T b)
{
    {a = b};
};


template <typename T>
concept Assignable_comparable = Assignable<T> && Comparable<T>;



template <typename T>
concept Constructable_empty = std::is_default_constructible_v<T>;


template <typename From, typename To>
concept Convertable_to = std::convertible_to<From, To> ;


template <typename From, typename To>
concept Convertable = std::convertible_to<From, To> || std::convertible_to<To, From> ;


template<typename Iter>
concept Iterator = requires()
{
    typename Iter::value_type;
    typename Iter::difference_type;
    typename Iter::pointer;
    typename Iter::reference;
};


template <typename C>
concept Container = requires (C c)
{
    typename C::value_type;
    typename C::size_type;

    typename C::iterator;
    typename C::const_iterator;

    { c.size() } noexcept -> std::same_as<typename C::size_type>;
    { c.end() } noexcept -> std::same_as<typename C::iterator>;
    { c.begin() } noexcept -> std::same_as<typename C::iterator>;
};

#endif //LAB_02_CONCEPT_H
