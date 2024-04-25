//
// Created by max on 4/15/24.
//

#ifndef LAB_02_LIST_ITERATOR_H
#define LAB_02_LIST_ITERATOR_H

#include "Base_iterator.h"
#include "List_node.h"
#include "errors.h"
#include "concept.h"


template <Comparable T>
class List;


template <typename T>
class List_iterator : public Base_iterator
{
    using value_type = T;
    using const_value_type = const T;
    using pointer = std::shared_ptr<List_node<T>>;
    using const_pointer = std::shared_ptr<const List_node<T>>;
    using reference = T&;
    using const_reference = const T&;
public:
    List_iterator();
    List_iterator(const List_iterator<T> &iterator);
    List_iterator(List<T> &list);
    List_iterator(const std::shared_ptr<List_node<T>> &node);

    void next() override;
    bool is_invalid() const override;

    List_iterator<T> &operator+=(const int &size);
    List_iterator<T> operator+(const int &size) const;
    List_iterator<T> &operator=(const List_iterator<T> &iterator);
    List_iterator<T> &operator++();
    List_iterator<T> operator++(int);

    explicit operator bool() const;

    pointer operator->();
    reference operator*();

    const_pointer operator->() const;
    const_reference operator*() const;

    const_value_type get() const;
    value_type get();

    std::shared_ptr<List_node<T>> get_node() const;
    bool operator!=(const List_iterator<T> &iterator) const;
    bool operator==(const List_iterator<T> &iterator) const;

protected:
    std::weak_ptr<List_node<T>> _ptr_cur;
};


#include "List_iterator.hpp"
#endif //LAB_02_LIST_ITERATOR_H
