//
// Created by max on 4/18/24.
//

#ifndef LAB_02_LIST_HPP
#define LAB_02_LIST_HPP


#include "List.h"


template <Assignable_comparable T>
List<T>::List()
{
    _size = 0;
    _head = nullptr;
    _tail = nullptr;
}


template <Assignable_comparable T>
List<T>::List(const List<T> &list)
{
    _size = 0;
    _head = nullptr;
    _tail = nullptr;

    for (auto node: list)
        push_back(node);
}


template <Assignable_comparable T>
template <typename U>
requires Convertable_to<U, T>
List<T>::List(const List<U> &list)
{
    for (const auto &value : list)
        push_back(T(value));
}


template<Assignable_comparable T>
List<T>::List(const T *arr, size_t size)
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


template<Assignable_comparable T>
List<T>::List(List<T> &&list) noexcept
{
    _size = list._size;
    _head = std::move(list._head);
    _tail = std::move(list._tail);
}


template<Assignable_comparable T>
List<T>::List(std::initializer_list<T> nodes)
{
    _size = 0;
    _head = nullptr;
    _tail = nullptr;

    for (auto node : nodes)
        push_back(node);
}


template<Assignable_comparable T>
template<typename C>
requires Container<C> && Convertable_to<typename C::value_type, T>
List<T>::List(const C &container)
{
    for (const auto &value : container)
        push_back(T(value));
}


template<Assignable_comparable T>
template<Iterator I>
requires Convertable_to<typename I::value_type, T>
List<T>::List(const I &begin, const I &end)
{
    for (auto it = begin; it != end; ++it)
        push_back(*it);
}


template<Assignable_comparable T>
template<Iterator I>
requires Convertable_to<typename I::value_type, T>
List<T>::List(const I &begin, List::size_type count)
{
    size_type i = 0;
    for (auto it = begin; i++ < count && it; ++it)
        push_back(*it);
}


template <Assignable_comparable T>
template <typename U>
requires Convertable_to<U, T>
List<T> &List<T>::operator=(const List<U> &list)
{
    clear();

    _size = 0;
    _head = nullptr;
    _tail = nullptr;

    push_back(list);

    return *this;
}


template<Assignable_comparable T>
List<T> &List<T>::operator=(const List<T> &list)
{
    clear();

    _size = 0;
    _head = nullptr;
    _tail = nullptr;

    push_back(list);

    return *this;
}


template<Assignable_comparable T>
List<T> &List<T>::operator=(List<T> &&list)
 noexcept {
    clear();
    _size = 0;
    _head = nullptr;
    _tail = nullptr;
    push_back(list);
    return *this;
}


template<Assignable_comparable T>
List<T> &List<T>::operator=(std::initializer_list<T> nodes)
{
    List<T> list_new(nodes);
    clear();
    push_back(list_new);

    return *this;
}


template<Assignable_comparable T>
template<typename C>
requires Container<C> && Convertable_to<typename C::value_type, T>
List<T> &List<T>::operator=(const C &container)
{
    List<T> list_new(container);
    clear();
    push_back(list_new);
    return *this;
}


template<Assignable_comparable T>
void List<T>::clear()
{
    while (_size) pop_front();
}


template<Assignable_comparable T>
bool List<T>::is_empty() const noexcept
{
    return !_size;
}


template<Assignable_comparable T>
List<T>::size_type List<T>::size()
{
    return _size;
}


template<Assignable_comparable T>
void List<T>::push_front(std::shared_ptr<List_node> &node)
{
    node->set_next(_head);
    _head = node;

    if (!_size)
        _tail = node;
    _size++;
}


template<Assignable_comparable T>
void List<T>::push_back(std::shared_ptr<List_node> &node)
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


template<Assignable_comparable T>
void List<T>::push_front(const T &data)
{
    std::shared_ptr<List_node> tmp_node = nullptr;

    try
    {
        tmp_node = std::make_shared<List_node>(data);
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


template<Assignable_comparable T>
void List<T>::push_back(const T &data)
{
    std::shared_ptr<List_node> tmp_node = nullptr;

    try
    {
        tmp_node = std::make_shared<List_node>(data);
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


template<Assignable_comparable T>
template <typename U>
requires Convertable_to<U, T>
void List<T>::push_back(const List<U> &list)
{
    List list_new(list);
    for (const auto data: list_new)
        push_back(data);
}


template<Assignable_comparable T>
template <typename U>
requires Convertable_to<U, T>
void List<T>::push_front(const List<U> &list)
{
    List list_new(list);
    insert(begin(), list);
}


template<Assignable_comparable T>
List<T>::value_type List<T>::back()
{
    return _tail;
}


template<Assignable_comparable T>
List<T>::value_type List<T>::front()
{
    return _head;
}


template<Assignable_comparable T>
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


template<Assignable_comparable T>
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
        std::shared_ptr<List_node> tmp_node = _head;
        while (tmp_node->get_next() != _tail) tmp_node = tmp_node->get_next();

        tmp_node->set_next(nullptr);
        _tail = tmp_node;
    }

    _size--;

    return data;
}


template<Assignable_comparable T>
List<T>::size_type List<T>::remove_all(const T &data)
{
    std::shared_ptr<List_node> tmp_node = _head;
    std::shared_ptr<List_node> tmp_node_prev = nullptr;
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
                std::shared_ptr<List_node> tmp_ptr = tmp_node->get_next();
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


template<Assignable_comparable T>
void List<T>::remove(const T &data)
{
    std::shared_ptr<List_node> tmp_node = _head;
    std::shared_ptr<List_node> tmp_node_prev = nullptr;
    size_t count = 0;

    if (!_size)
    {
        time_t time_error = time(nullptr);
        throw Empty_list_error(__FILE__,
                               typeid(*this).name(),
                               ctime(&time_error),
                               __LINE__);
    }

    while (tmp_node && !count)
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
                std::shared_ptr<List_node> tmp_ptr = tmp_node->get_next();
                tmp_node_prev->set_next(tmp_ptr);
                tmp_node->set_next(nullptr);
                tmp_node = tmp_ptr;
                count++;
            }
        }
        else
        {
            tmp_node_prev = tmp_node;
            tmp_node = tmp_node->get_next();
        }
    }
}


template<Assignable_comparable T>
void List<T>::remove(const List::iterator &iterator)
{
    if (iterator.is_invalid())
    {
        time_t time_error = time(nullptr);
        throw Iterator_error(__FILE__,
                             typeid(*this).name(),
                             ctime(&time_error),
                             __LINE__);
    }

    std::shared_ptr<List_node> cur_node = iterator.get_node();
    std::shared_ptr<List_node> tmp_node = iterator.get_node().get_next();
    std::shared_ptr<List_node> next_node = tmp_node->get_next();
    cur_node->set_next(next_node);
}


template<Assignable_comparable T>
void List<T>::remove(const List::iterator &start, const List::iterator &end)
{
    if (start.is_invalid())
    {
        time_t time_error = time(nullptr);
        throw Iterator_error(__FILE__,
                             typeid(*this).name(),
                             ctime(&time_error),
                             __LINE__);
    }

    if (end.is_invalid())
    {
        time_t time_error = time(nullptr);
        throw Iterator_error(__FILE__,
                             typeid(*this).name(),
                             ctime(&time_error),
                             __LINE__);
    }
    std::shared_ptr<List_node> cur_node = start.get_node();
    std::shared_ptr<List_node> next_node = end.get_node();
    cur_node->set_next(next_node);
}



template<Assignable_comparable T>
List<T>::size_type List<T>::remove_all(const iterator &iterator)
{
    size_t count = 0;
    while (!iterator.is_invalid()) count += remove_all(iterator++);

    return count;
}


template<Assignable_comparable T>
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

    std::shared_ptr<List_node> tmp_node = nullptr;

    try
    {
        tmp_node = std::make_shared<List_node>(data);
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


template<Assignable_comparable T>
template<typename C>
requires Container<C> && Convertable_to<typename C::value_type, T>
List<T>::iterator List<T>::insert(const List::const_iterator &iterator, const C &container)
{
    List<T> list_new(container);
    insert(iterator, list_new);
}


template<Assignable_comparable T>
template<typename C>
requires Container<C> && Convertable_to<typename C::value_type, T>
List<T>::iterator List<T>::insert(const List::iterator &iterator, const C &container)
{
    List<T> list_new(container);
    insert(iterator, list_new);
}


template<Assignable_comparable T>
List<T>::iterator List<T>::insert(const List::iterator &iterator, const T &data)
{
    if (iterator.is_invalid())
    {
        time_t time_error = time(nullptr);
        throw Iterator_error(__FILE__,
                             typeid(*this).name(),
                             ctime(&time_error),
                             __LINE__);
    }

    std::shared_ptr<List_node> tmp_node = nullptr;

    try
    {
        tmp_node = std::make_shared<List_node>(data);
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

    tmp_node->set_next(tmp_iterator.get_node()->get_next());
    tmp_iterator.get_node()->set_next(tmp_node);
    _size++;

    return List::iterator(tmp_node);
}


template<Assignable_comparable T>
void List<T>::reverse()
{
    std::shared_ptr<List_node> current= _head;
    std::shared_ptr<List_node> next = nullptr;
    std::shared_ptr<List_node> prev = nullptr;

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


template<Assignable_comparable T>
List<T> &List<T>::merge(const T &data)
{
    push_back(data);
    return *this;
}


template<Assignable_comparable T>
template<typename U>
requires Convertable_to<U, T>
List<T> &List<T>::merge(const List<U> &list)
{
    List list_new(list);
    push_back(list_new);
    return *this;
}


template<Assignable_comparable T>
List<T> &List<T>::merge(const List<T> &list)
{
    List list_new(list);
    push_back(list_new);
    return *this;
}


template<Assignable_comparable T>
List<T> &List<T>::operator+=(const T &data)
{
    return merge(data);
}


template<Assignable_comparable T>
template<typename U>
requires Convertable_to<U, T>
List<T> &List<T>::operator+=(const List<U> &list)
{
    List list_new(list);
    return merge(list_new);
}



template<Assignable_comparable T>
List<T> List<T>::operator+(const T &data)
{
    push_back(data);
    return List(cbegin());
}


template<Assignable_comparable T>
List<T> List<T>::operator+(const List<T> &list)
{
    List<T> tmp;
    tmp.push_back(*this);
    tmp.push_back(list);
    return tmp;
}


template<Assignable_comparable T>
template<typename U>
requires Convertable<U, T>
decltype(auto) List<T>::operator+(const List<U> &list)
{
    using type = std::common_type_t<T, U>;
    List<type> list_new(list);
    List<type> tmp;
    tmp.push_back(*this);
    tmp.push_back(list_new);
    return tmp;
}


template<Assignable_comparable T>
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


template<Assignable_comparable T>
bool List<T>::is_not_equal(const List<T> &list) const
{
    return operator!=(list);
}


template<Assignable_comparable T>
bool List<T>::operator!=(const List<T> &list) const
{
    return !operator==(list);
}


template<Assignable_comparable T>
bool List<T>::is_equal(const List<T> &list) const
{
    return operator==(list);
}


template<Assignable_comparable T>
List<T>::iterator List<T>::end() noexcept
{
    return ++List::iterator(_tail);
}


template<Assignable_comparable T>
List<T>::iterator List<T>::begin() noexcept
{
    return List::iterator(_head);
}


template<Assignable_comparable T>
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


template<Assignable_comparable T>
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


template<Assignable_comparable T>
List<T>::const_iterator List<T>::cend() const noexcept
{
    return ++List::const_iterator(_tail);
}


template<Assignable_comparable T>
List<T>::const_iterator List<T>::cbegin() const noexcept
{
    return List::const_iterator(_head);
}


template<Assignable_comparable T>
List<T>::const_iterator List<T>::end() const noexcept
{
    return ++List::const_iterator(_tail);
}


template<Assignable_comparable T>
List<T>::const_iterator List<T>::begin() const noexcept
{
    return List::const_iterator(_head);
}


#endif //LAB_02_LIST_HPP
