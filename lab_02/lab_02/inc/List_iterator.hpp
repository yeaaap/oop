//
// Created by max on 4/17/24.
//

#ifndef LAB_02_LIST_ITERATOR_HPP
#define LAB_02_LIST_ITERATOR_HPP


#include <ctime>
#include "List_iterator.h"


template<typename T>
List_iterator<T>::List_iterator(const std::shared_ptr<List_node<T>> &node)
{
    _ptr_cur = node;
}


template<typename T>
List_iterator<T>::List_iterator(const List_iterator<T> &iterator)
{
    _ptr_cur = iterator._ptr_cur;
}


template<typename T>
List_iterator<T>::List_iterator()
{
    _ptr_cur.lock() = nullptr;
}


template<typename T>
List_iterator<T>::List_iterator(List<T> &list)
{
    _ptr_cur = list.begin()._ptr_cur.lock();
}


template<typename T>
bool List_iterator<T>::is_invalid() const
{
    return _ptr_cur.lock() == nullptr;
}


template<typename T>
void List_iterator<T>::next()
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
List_iterator<T> &List_iterator<T>::operator+=(const int &size)
{
    for (size_t i = 0; i < size; next(), ++i);
    return *this;
}


template<typename T>
List_iterator<T> List_iterator<T>::operator+(const int &size) const
{
    List_iterator<T> iterator_new(*this);
    iterator_new += size;
    return iterator_new;
}


template<typename T>
List_iterator<T>::operator bool() const
{
    return !_ptr_cur.expired();
}


template<typename T>
bool List_iterator<T>::operator!=(const List_iterator<T> &iterator) const
{
    return _ptr_cur.lock() != iterator._ptr_cur.lock();
}


template<typename T>
bool List_iterator<T>::operator==(const List_iterator<T> &iterator) const
{
    return _ptr_cur.lock() == iterator._ptr_cur.lock();
}


template<typename T>
List_iterator<T> &List_iterator<T>::operator=(const List_iterator<T> &iterator)
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
List_iterator<T> &List_iterator<T>::operator++()
{
    next();
    return *this;
}


template<typename T>
List_iterator<T> List_iterator<T>::operator++(int)
{
    List_iterator<T> iterator_new(*this);
    next();
    return iterator_new;
}


template<typename T>
List_iterator<T>::const_value_type List_iterator<T>::get() const
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
List_iterator<T>::const_reference List_iterator<T>::operator*() const
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
List_iterator<T>::const_pointer List_iterator<T>::operator->() const
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
List_iterator<T>::value_type List_iterator<T>::get()
{
    if (this->_ptr_cur.expired())
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
List_iterator<T>::reference List_iterator<T>::operator*()
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
List_iterator<T>::pointer List_iterator<T>::operator->()
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
List_iterator<T>::pointer List_iterator<T>::get_node() const
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


#endif //LAB_02_LIST_ITERATOR_HPP
