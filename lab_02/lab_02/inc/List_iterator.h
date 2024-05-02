//
// Created by max on 4/15/24.
//

#ifndef LAB_02_LIST_ITERATOR_H
#define LAB_02_LIST_ITERATOR_H

#include "errors.h"
#include "concept.h"
#include "List_base_iterator.h"


template <Comparable T>
class List;

template <typename T>
class List_iterator_const;


template <typename T>
class List_iterator : public List_base_iterator<T>
{
public:
    using value_type = T;
    using pointer = std::shared_ptr<T>;
    using reference = T&;
    using difference_type = int;
    using iterator_category = std::forward_iterator_tag;
    using List_node = List<T>::List_node;

    friend class List_iterator_const<T>;

public:
    List_iterator();
    List_iterator(const List_iterator<T> &iterator);
    explicit List_iterator(List<T> &list);
    explicit List_iterator(const std::shared_ptr<List_node> &node);

    List_iterator<T> &operator+=(const int &size);
    List_iterator<T> operator+(const int &size) const;
    List_iterator<T> &operator=(const List_iterator<T> &iterator);
    List_iterator<T> &operator++();
    List_iterator<T> operator++(int);

    pointer operator->();
    reference operator*();

    value_type get();

    bool operator!=(const List_iterator<T> &iterator) const;
    bool operator==(const List_iterator<T> &iterator) const;
};


#include "List_iterator.hpp"
#endif //LAB_02_LIST_ITERATOR_H
