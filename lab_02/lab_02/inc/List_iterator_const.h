//
// Created by max on 4/21/24.
//

#ifndef LAB_02_LIST_ITERATOR_CONST_H
#define LAB_02_LIST_ITERATOR_CONST_H


#include "errors.h"
#include "concept.h"
#include "List_base_iterator.h"
#include "List_iterator.h"


template <Comparable T>
class List;


template <typename T>
class List_iterator_const : public List_base_iterator<T>
{
public:
    using value_type = const T;
    using pointer = std::shared_ptr<const T>;
    using reference = const T&;
    using iterator_category = std::forward_iterator_tag;
    using difference_type = int;
    using List_node = List<T>::List_node;

public:
    List_iterator_const();
    List_iterator_const(const List_iterator_const<T> &iterator);
    explicit List_iterator_const(const std::shared_ptr<List_node> &node);
    explicit List_iterator_const(const List<T> &list);
    explicit List_iterator_const(const List_iterator<T> &iterator);

    List_iterator_const<T> &operator+=(const int &size);
    List_iterator_const<T> operator+(const int &size) const;
    List_iterator_const<T> &operator=(const List_iterator_const<T> &iterator);
    List_iterator_const<T> &operator++();
    List_iterator_const<T> operator++(int);

    bool operator!=(const List_iterator_const<T> &iterator) const;
    bool operator==(const List_iterator_const<T> &iterator) const;
};


#include "List_iterator_const.hpp"

#endif //LAB_02_LIST_ITERATOR_CONST_H
