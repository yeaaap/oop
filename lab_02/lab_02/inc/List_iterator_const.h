//
// Created by max on 4/21/24.
//

#ifndef LAB_02_LIST_ITERATOR_CONST_H
#define LAB_02_LIST_ITERATOR_CONST_H


#include "Base_iterator.h"
#include "List_node.h"
#include "errors.h"
#include "concept.h"


template <Comparable T>
class List;


template <typename T>
class List_iterator_const : Base_iterator
{
public:
    using const_value_type = const T;
    using const_pointer = std::shared_ptr<const T>;
    using const_reference = const T&;

    List_iterator_const();
    List_iterator_const(const List_iterator_const<T> &iterator);
    List_iterator_const(const std::shared_ptr<List_node<T>> &node);
    List_iterator_const(const List<T> &list);

    void next() override;
    bool is_invalid() const override;

    const_pointer operator->() const;
    const_reference operator*() const;

    List_iterator_const<T> &operator+=(const int &size);
    List_iterator_const<T> operator+(const int &size) const;
    List_iterator_const<T> &operator=(const List_iterator_const<T> &iterator);
    List_iterator_const<T> &operator++();
    List_iterator_const<T> operator++(int);

    explicit operator bool() const;

    const_value_type get() const;
    std::shared_ptr<List_node<T>> get_node() const;
    bool operator!=(const List_iterator_const<T> &iterator) const;
    bool operator==(const List_iterator_const<T> &iterator) const;
protected:
    std::weak_ptr<List_node<T>> _ptr_cur;
};


#include "List_iterator_const.hpp"

#endif //LAB_02_LIST_ITERATOR_CONST_H
