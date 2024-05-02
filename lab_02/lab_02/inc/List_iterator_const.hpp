//
// Created by max on 4/21/24.
//

#ifndef LAB_02_LIST_ITERATOR_CONST_HPP
#define LAB_02_LIST_ITERATOR_CONST_HPP

#include <ctime>
#include "List_iterator_const.h"


template<typename T>
List_iterator_const<T>::List_iterator_const(const std::shared_ptr<List_node> &node)
{
    this->_ptr_cur = node;
}


template<typename T>
List_iterator_const<T>::List_iterator_const(const List_iterator_const<T> &iterator)
{
    this->_ptr_cur = iterator._ptr_cur;
}


template<typename T>
List_iterator_const<T>::List_iterator_const()
{
    this->_ptr_cur.lock() = nullptr;
}


template<typename T>
List_iterator_const<T>::List_iterator_const(const List_iterator<T> &iterator)
{
    this->_ptr_cur = iterator._ptr_cur;
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
    for (size_t i = 0; i < size; this->next(), ++i);
    return *this;
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

    this->_ptr_cur = iterator._ptr_cur.lock();

    return *this;
}


template<typename T>
List_iterator_const<T> &List_iterator_const<T>::operator++()
{
    this->next();
    return *this;
}


template<typename T>
List_iterator_const<T> List_iterator_const<T>::operator++(int)
{
    List_iterator_const<T> iterator_new(*this);
    this->next();
    return iterator_new;
}


template<typename T>
List_iterator_const<T>::List_iterator_const(const List<T> &list)
{
    this->_ptr_cur = list.begin()._ptr_cur.lock();
}


template<typename T>
bool List_iterator_const<T>::operator==(const List_iterator_const<T> &iterator) const
{
    return this->_ptr_cur.lock() == iterator._ptr_cur.lock();
}


template<typename T>
bool List_iterator_const<T>::operator!=(const List_iterator_const<T> &iterator) const
{
    return this->_ptr_cur.lock() != iterator._ptr_cur.lock();
}



#endif //LAB_02_LIST_ITERATOR_CONST_HPP
