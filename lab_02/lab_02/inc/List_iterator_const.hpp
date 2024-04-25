//
// Created by max on 4/21/24.
//

#ifndef LAB_02_LIST_ITERATOR_CONST_HPP
#define LAB_02_LIST_ITERATOR_CONST_HPP

#include <ctime>
#include "List_iterator_const.h"


template<typename T>
List_iterator_const<T>::List_iterator_const(const std::shared_ptr<List_node<T>> &node)
{
    _ptr_cur = node;
}


template<typename T>
List_iterator_const<T>::List_iterator_const(const List_iterator_const<T> &iterator)
{
    _ptr_cur = iterator._ptr_cur;
}


template<typename T>
List_iterator_const<T>::List_iterator_const()
{
    _ptr_cur.lock() = nullptr;
}


template<typename T>
List_iterator_const<T> List_iterator_const<T>::operator+(const int &size) const
{
    List_iterator_const<T> iterator_new(*this);
    iterator_new += size;
    return iterator_new;
}


template<typename T>
List_iterator_const<T> &List_iterator_const<T>::operator+=(const int &size)
{
    for (size_t i = 0; i < size; next(), ++i);
    return *this;
}


template<typename T>
List_iterator_const<T>::operator bool() const
{
    return !_ptr_cur.expired();
}


template<typename T>
List_iterator_const<T> &List_iterator_const<T>::operator=(const List_iterator_const<T> &iterator)
{
    if (iterator._ptr_cur.expired())
    {
        time_t time_error = time(nullptr);
        throw Pointer_error(__FILE__,
                             typeid(*this).name(),
                             ctime(&time_error),
                             __LINE__);
    }

    _ptr_cur = iterator._ptr_cur.lock();

    return *this;
}


template<typename T>
List_iterator_const<T> &List_iterator_const<T>::operator++()
{
    next();
    return *this;
}


template<typename T>
List_iterator_const<T> List_iterator_const<T>::operator++(int)
{
    List_iterator_const<T> iterator_new(*this);
    next();
    return iterator_new;
}


template<typename T>
List_iterator_const<T>::const_value_type List_iterator_const<T>::get() const
{
    if (_ptr_cur.expired())
    {
        time_t time_error = time(nullptr);
        throw Pointer_error(__FILE__,
                             typeid(*this).name(),
                             ctime(&time_error),
                             __LINE__);
    }

    return _ptr_cur.lock()->get_data();
}


template<typename T>
List_iterator_const<T>::const_reference List_iterator_const<T>::operator*() const
{
    if (_ptr_cur.expired())
    {
        time_t time_error = time(nullptr);
        throw Pointer_error(__FILE__,
                             typeid(*this).name(),
                             ctime(&time_error),
                             __LINE__);
    }

    return _ptr_cur.lock()->get_data();
}


template<typename T>
List_iterator_const<T>::const_pointer List_iterator_const<T>::operator->() const
{
    if (_ptr_cur.expired())
    {
        time_t time_error = time(nullptr);
        throw Pointer_error(__FILE__,
                             typeid(*this).name(),
                             ctime(&time_error),
                             __LINE__);
    }

    return std::shared_ptr(_ptr_cur.lock()->get_data());
}




template<typename T>
std::shared_ptr<List_node<T>> List_iterator_const<T>::get_node() const
{
    if (_ptr_cur.expired())
    {
        time_t time_error = time(nullptr);
        throw Pointer_error(__FILE__,
                             typeid(*this).name(),
                             ctime(&time_error),
                             __LINE__);
    }

    return _ptr_cur.lock();
}


template<typename T>
bool List_iterator_const<T>::is_invalid() const
{
    return _ptr_cur.lock() == nullptr;
}


template<typename T>
void List_iterator_const<T>::next()
{
    if (_ptr_cur.expired())
    {
        time_t time_error = time(nullptr);
        throw Pointer_error(__FILE__,
                             typeid(*this).name(),
                             ctime(&time_error),
                             __LINE__);
    }

    _ptr_cur = _ptr_cur.lock()->get_next();
}


template<typename T>
List_iterator_const<T>::List_iterator_const(const List<T> &list)
{
    _ptr_cur = list.begin()._ptr_cur.lock();
}


template<typename T>
bool List_iterator_const<T>::operator==(const List_iterator_const<T> &iterator) const
{
    return _ptr_cur.lock() == iterator._ptr_cur.lock();
}


template<typename T>
bool List_iterator_const<T>::operator!=(const List_iterator_const<T> &iterator) const
{
    return _ptr_cur.lock() != iterator._ptr_cur.lock();
}



#endif //LAB_02_LIST_ITERATOR_CONST_HPP
