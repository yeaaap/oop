//
// Created by max on 4/15/24.
//

#ifndef LAB_02_LIST_H
#define LAB_02_LIST_H

#include "Base_container.h"
#include "List_node.h"
#include "List_iterator.h"
#include "List_iterator_const.h"
#include "concept.h"


template <Comparable T>
class List : public Base_container
{
public:
    using value_type = T;
    using iterator = List_iterator<T>;
    using const_iterator = List_iterator_const<T>;
    using size_type = size_t;

    List();
    List(const List<T> &list);

    List(T *const arr, const size_t &size);
    List(const std::initializer_list<T> &nodes);

    ~List() override = default;

    virtual bool is_empty() const noexcept override;
    virtual void clear() override;

    size_type size();

    void push_front(const T &data);
    void push_front(const List<T> &list);
    void push_back(const T &data);
    void push_back(const List<T> &list);

    iterator insert(const const_iterator &iterator, const T &data);
    iterator insert(const const_iterator &iterator, const List<T> &list);
    iterator insert(const iterator &iterator, const T &data);
    iterator insert(const iterator &iterator, const List<T> &list);

    value_type pop_back();
    value_type pop_front();
    value_type front();
    value_type back();
    size_type remove(const T &data);

    void reverse();

    List<T> &merge(const List<T> &list);
    List<T> &merge(const T &data);

    List<T> &operator+=(const List<T> &list);
    List<T> &operator+=(const T &data);

    List<T> &operator+(const List<T> &list);
    List<T> &operator+(const T &data);

    List<T> &add(const List<T> &list);
    List<T> &add(const T &data);

    List<T> &operator=(const List<T> &list);

    bool operator==(const List<T> &list) const;
    bool is_equal(const List<T> &list) const;
    bool operator!=(const List<T> &list) const;
    bool is_not_equal(const List<T> &list) const;

    iterator begin() noexcept;
    iterator end() noexcept;

    const_iterator begin() const noexcept;
    const_iterator end() const noexcept;

    const_iterator cbegin() const noexcept;
    const_iterator cend()const noexcept;

private:
    std::shared_ptr<List_node<T>> _head;
    std::shared_ptr<List_node<T>> _tail;
    void push_back(const std::shared_ptr<List_node<T>> &node);
    void push_front(const std::shared_ptr<List_node<T>> &node);
};


template <typename T>
std::ostream &operator<<(std::ostream &os, List<T> &list)
{
    List_iterator<T> iter(list);
    for (; iter; iter++)
        if (iter + 1)
            os << *iter << ", ";
        else
            os << *iter;

    return os;
}


template <typename T>
std::ostream &operator<<(std::ostream &os, const List<T> &list)
{
    List_iterator_const<T> iter(list);
    for (; iter; iter++)
        if (iter + 1)
            os << *iter << ", ";
        else
            os << *iter;

    return os;
}


#include "List.hpp"


#endif //LAB_02_LIST_H
