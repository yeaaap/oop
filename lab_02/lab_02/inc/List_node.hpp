//
// Created by max on 4/15/24.
//

#ifndef LAB_02_LIST_NODE_HPP
#define LAB_02_LIST_NODE_HPP

#include "List_node.h"


template <typename T>
List_node<T>::List_node()
{
    _next = nullptr;
}


template <typename T>
List_node<T>::List_node(const T &data)
{
    _next = nullptr;
    _data = data;
}


template<typename T>
List_node<T>::List_node(std::shared_ptr<List_node<T>> &node)
{
    _data = node._data;
    _next = node._next;
}


template<typename T>
void List_node<T>::set_data(const T &data)
{
    _data = data;
}


template<typename T>
const T &List_node<T>::get_data() const
{
    return _data;
}


template<typename T>
void List_node<T>::set_next(const std::shared_ptr<List_node<T>> &node)
{
    _next = node;
}


template<typename T>
void List_node<T>::set_next(const List_node &node)
{
    std::shared_ptr<List_node<T>> ptr(node);
    _next = ptr;
}


template<typename T>
std::shared_ptr<List_node<T>> List_node<T>::get_next() const
{
    return _next;
}


template<typename T>
bool List_node<T>::operator!=(const std::shared_ptr<List_node<T>> &node) const
{
    return this != node;
}


template<typename T>
bool List_node<T>::operator==(const std::shared_ptr<List_node<T>> &node) const
{
    return this == node;
}


template<typename T>
T &List_node<T>::get_data()
{
    return _data;
}


#endif //LAB_02_LIST_NODE_HPP
