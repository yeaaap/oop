//
// Created by max on 4/18/24.
//

#ifndef LAB_02_LIST_HPP
#define LAB_02_LIST_HPP


#include "List.h"


template<Comparable T>
List<T>::List()
{
    _size = 0;
    _head = nullptr;
    _tail = nullptr;
}


template<Comparable T>
List<T>::List(const List<T> &list)
{
    _size = 0;
    _head = nullptr;
    _tail = nullptr;

    for (auto node: list)
        push_back(node);
}


template<Comparable T>
List<T>::List(T *const arr, const size_t &size)
{
    if (!arr)
    {
        time_t time_error = time(nullptr);
        throw Pointer_error(__FILE__,
                            typeid(*this).name(),
                            ctime(&time_error),
                            __LINE__);
    }

    _size = 0;
    _head = nullptr;
    _tail = nullptr;

    for (size_t i = 0; i < size; ++i)
        push_back(arr[i]);
}


template<Comparable T>
List<T>::List(const std::initializer_list<T> &nodes)
{
    _size = 0;
    _head = nullptr;
    _tail = nullptr;

    for (auto node : nodes)
        push_back(node);
}


template<Comparable T>
List<T> &List<T>::operator=(const List<T> &list)
{
    clear();

    _size = 0;
    _head = nullptr;
    _tail = nullptr;

    push_back(list);

    return *this;
}


template<Comparable T>
void List<T>::clear()
{
    while (_size) pop_front();
}


template<Comparable T>
bool List<T>::is_empty() const noexcept
{
    return !_size;
}


template<Comparable T>
List<T>::size_type List<T>::size()
{
    return _size;
}


template<Comparable T>
void List<T>::push_front(const std::shared_ptr<List_node<T>> &node)
{
    node->set_next(_head);
    _head = node;

    if (!_size)
        _tail = node;
    _size++;
}


template<Comparable T>
void List<T>::push_back(const std::shared_ptr<List_node<T>> &node)
{
    if (!node)
    {
        time_t time_error = time(nullptr);
        throw Pointer_error(__FILE__,
                               typeid(*this).name(),
                               ctime(&time_error),
                               __LINE__);
    }

    node->set_next(nullptr);
    if (!_size)
    {
        _head = node;
        _tail = node;
    }
    else
    {
        _tail->set_next(node);
        _tail = node;
    }

    _size++;
}


template<Comparable T>
void List<T>::push_front(const T &data)
{
    std::shared_ptr<List_node<T>> tmp_node = nullptr;

    try
    {
        tmp_node = std::make_shared<List_node<T>>(data);
    }
    catch (std::bad_alloc &error)
    {
        time_t time_error = time(nullptr);
        throw Memory_error(__FILE__,
                           typeid(*this).name(),
                           ctime(&time_error),
                           __LINE__);
    }

    push_front(tmp_node);
}


template<Comparable T>
void List<T>::push_back(const T &data)
{
    std::shared_ptr<List_node<T>> tmp_node = nullptr;

    try
    {
        tmp_node = std::make_shared<List_node<T>>(data);
    }
    catch (std::bad_alloc &error)
    {
        time_t time_error = time(nullptr);
        throw Memory_error(__FILE__,
                           typeid(*this).name(),
                           ctime(&time_error),
                           __LINE__);
    }

    push_back(tmp_node);
}


template<Comparable T>
void List<T>::push_back(const List<T> &list)
{
    for (const auto data: list)
        push_back(data);
}


template<Comparable T>
void List<T>::push_front(const List<T> &list)
{
    insert(begin(), list);
}


template<Comparable T>
List<T>::value_type List<T>::back()
{
    return _tail;
}


template<Comparable T>
List<T>::value_type List<T>::front()
{
    return _head;
}


template<Comparable T>
List<T>::value_type List<T>::pop_front()
{
    if (!_size)
    {
        time_t time_error = time(nullptr);
        throw Empty_list_error(__FILE__,
                               typeid(*this).name(),
                               ctime(&time_error),
                               __LINE__);
    }

    value_type data = _head->get_data();
    if (_size == 1)
    {
        _head = nullptr;
        _tail = nullptr;
    }
    else
    {
        _head = _head->get_next();
    }

    _size--;

    return data;
}


template<Comparable T>
List<T>::value_type List<T>::pop_back()
{
    if (!_size)
    {
        time_t time_error = time(nullptr);
        throw Empty_list_error(__FILE__,
                               typeid(*this).name(),
                               ctime(&time_error),
                               __LINE__);
    }

    value_type data = _tail->get_data();

    if (_size == 1)
    {
        _head = nullptr;
        _tail = nullptr;
    }
    else
    {
        std::shared_ptr<List_node<T>> tmp_node = _head;
        while (tmp_node->get_next() != _tail) tmp_node = tmp_node->get_next();

        tmp_node->set_next(nullptr);
        _tail = tmp_node;
    }

    _size--;

    return data;
}


template<Comparable T>
List<T>::size_type List<T>::remove(const T &data)
{
    std::shared_ptr<List_node<T>> tmp_node = _head;
    std::shared_ptr<List_node<T>> tmp_node_prev = nullptr;
    size_t count = 0;

    if (!_size)
    {
        time_t time_error = time(nullptr);
        throw Empty_list_error(__FILE__,
                               typeid(*this).name(),
                               ctime(&time_error),
                               __LINE__);
    }

    while (tmp_node)
    {
        if (tmp_node->get_data() == data)
        {
            if (tmp_node == _head)
            {
                pop_front();
                tmp_node = _head;
            }
            else
            {
                std::shared_ptr<List_node<T>> tmp_ptr = tmp_node->get_next();
                tmp_node_prev->set_next(tmp_ptr);
                tmp_node->set_next(nullptr);
                tmp_node = tmp_ptr;
            }
            count++;
        }
        else
        {
            tmp_node_prev = tmp_node;
            tmp_node = tmp_node->get_next();
        }
    }

    return count;
}


template<Comparable T>
List<T>::iterator List<T>::insert(const List::const_iterator &iterator, const T &data)
{
    if (iterator.is_invalid())
    {
        time_t time_error = time(nullptr);
        throw Iterator_error(__FILE__,
                             typeid(*this).name(),
                             ctime(&time_error),
                             __LINE__);
    }

    std::shared_ptr<List_node<T>> tmp_node = nullptr;

    try
    {
        tmp_node = std::make_shared<List_node<T>>(data);
    }
    catch (std::bad_alloc &error)
    {
        time_t time_error = time(nullptr);
        throw Memory_error(__FILE__,
                           typeid(*this).name(),
                           ctime(&time_error),
                           __LINE__);
    }

    if (iterator == cbegin())
    {
        push_front(tmp_node);
        return List::iterator(tmp_node);
    }
    else if (iterator == cend())
    {
        push_back(tmp_node);
        return List::iterator(tmp_node);
    }

    List::const_iterator tmp_iterator = cbegin();
    while (tmp_iterator + 1 != iterator) tmp_iterator++;

    tmp_node->set_next(tmp_iterator.get_node()->get_next());
    tmp_iterator.get_node()->set_next(tmp_node);
    _size++;

    return List::iterator(tmp_node);
}


template<Comparable T>
List<T>::iterator List<T>::insert(const List::iterator &iterator, const T &data) {
    if (iterator.is_invalid())
    {
        time_t time_error = time(nullptr);
        throw Iterator_error(__FILE__,
                             typeid(*this).name(),
                             ctime(&time_error),
                             __LINE__);
    }

    std::shared_ptr<List_node<T>> tmp_node = nullptr;

    try
    {
        tmp_node = std::make_shared<List_node<T>>(data);
    }
    catch (std::bad_alloc &error)
    {
        time_t time_error = time(nullptr);
        throw Memory_error(__FILE__,
                           typeid(*this).name(),
                           ctime(&time_error),
                           __LINE__);
    }

    if (iterator == begin())
    {
        push_front(tmp_node);
        return List::iterator(tmp_node);
    }
    else if (iterator == end())
    {
        push_back(tmp_node);
        return List::iterator(tmp_node);
    }

    List::iterator tmp_iterator = begin();
    while (tmp_iterator + 1 != iterator) tmp_iterator++;

    tmp_node->set_next(tmp_iterator->get_next());
    tmp_iterator->set_next(tmp_node);
    _size++;

    return List::iterator(tmp_node);
}


template<Comparable T>
void List<T>::reverse()
{
    std::shared_ptr<List_node<T>> current= _head;
    std::shared_ptr<List_node<T>> next = nullptr;
    std::shared_ptr<List_node<T>> prev = nullptr;

    while (current)
    {
        next = current->get_next();
        current->set_next(prev);
        prev = current;
        current = next;
    }

    prev = _head;
    _head = _tail;
    _tail = prev;
    _tail->set_next(nullptr);
}


template<Comparable T>
List<T> &List<T>::merge(const T &data)
{
    push_back(data);
    return *this;
}


template<Comparable T>
List<T> &List<T>::merge(const List<T> &list)
{
    push_back(list);
    return *this;
}


template<Comparable T>
List<T> &List<T>::operator+=(const T &data)
{
    return merge(data);
}


template<Comparable T>
List<T> &List<T>::operator+=(const List<T> &list)
{
    return merge(list);
}


template<Comparable T>
List<T> &List<T>::operator+(const T &data)
{
    return operator+=(data);
}


template<Comparable T>
List<T> &List<T>::operator+(const List<T> &list)
{
    return operator+=(list);
}


template<Comparable T>
List<T> &List<T>::add(const T &data)
{
    return operator+(data);
}


template<Comparable T>
List<T> &List<T>::add(const List<T> &list)
{
    return operator+(list);
}


template<Comparable T>
bool List<T>::operator==(const List<T> &list) const
{
    const_iterator list_1 = cbegin();
    const_iterator list_2 = list.cbegin();

    while (list_1 != cend() && list_2 != list.cend())
    {
        if (list_1.get() != list_2.get())
            return false;
        ++list_1;
        ++list_2;
    }

    return _size == list._size;
}


template<Comparable T>
bool List<T>::is_not_equal(const List<T> &list) const
{
    return operator!=(list);
}


template<Comparable T>
bool List<T>::operator!=(const List<T> &list) const
{
    return !operator==(list);
}


template<Comparable T>
bool List<T>::is_equal(const List<T> &list) const
{
    return operator==(list);
}


template<Comparable T>
List<T>::iterator List<T>::end() noexcept
{
    return ++List::iterator(_tail);
}


template<Comparable T>
List<T>::iterator List<T>::begin() noexcept
{
    return List::iterator(_head);
}


template<Comparable T>
List<T>::iterator List<T>::insert(const List::iterator &iterator, const List<T> &list)
{
    if (iterator.is_invalid())
    {
        time_t time_error = time(nullptr);
        throw Iterator_error(__FILE__,
                             typeid(*this).name(),
                             ctime(&time_error),
                             __LINE__);
    }

    List_iterator<T> iter_insert;

    for (size_t i = 0; i < list._size; ++i)
        iter_insert = insert(iterator, *(list.cbegin() + i));

    return iter_insert;
}

template<Comparable T>
List<T>::iterator List<T>::insert(const List::const_iterator &iterator, const List<T> &list)
{
    if (iterator.is_invalid())
    {
        time_t time_error = time(nullptr);
        throw Iterator_error(__FILE__,
                             typeid(*this).name(),
                             ctime(&time_error),
                             __LINE__);
    }

    List_iterator<T> iter_insert;

    for (size_t i = 0; i < list._size; ++i)
        iter_insert = insert(iterator, *(list.cbegin() + i));

    return iter_insert;
}


template<Comparable T>
List<T>::const_iterator List<T>::cend() const noexcept
{
    return ++List::const_iterator(_tail);
}


template<Comparable T>
List<T>::const_iterator List<T>::cbegin() const noexcept
{
    return List::const_iterator(_head);
}


template<Comparable T>
List<T>::const_iterator List<T>::end() const noexcept
{
    return ++List::const_iterator(_tail);
}


template<Comparable T>
List<T>::const_iterator List<T>::begin() const noexcept
{
    return List::const_iterator(_head);
}


#endif //LAB_02_LIST_HPP
