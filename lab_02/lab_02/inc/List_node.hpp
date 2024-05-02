//
// Created by max on 4/15/24.
//

#ifndef LAB_02_LIST_NODE_HPP
#define LAB_02_LIST_NODE_HPP

//con
template <Assignable_comparable T>
template <Constructable_empty U>
List<T>::List_node::List_node() : _data(U()), _next(nullptr){}


template <Assignable_comparable T>
List<T>::List_node::List_node(const T &data) : _data(data), _next(nullptr){}


template <Assignable_comparable T>
List<T>::List_node::List_node(const T &data, std::shared_ptr<List<T>::List_node> &next) : _data(data), _next(next){}


template <Assignable_comparable T>
List<T>::List_node::List_node(std::shared_ptr<List<T>::List_node> &node) : _data(node->_data), _next(node->_next){}


template <Assignable_comparable T>
List<T>::List_node::List_node(const List::List_node &node) : _data(node._data), _next(node._next){}


template <Assignable_comparable T>
List<T>::List_node::List_node(List::List_node &&node)  noexcept : _data(node._data), _next(node._next){}


template <Assignable_comparable T>
void List<T>::List_node::set_data(const T &data) { _data = data; }


template <Assignable_comparable T>
const T &List<T>::List_node::get_data() const { return _data; }


template <Assignable_comparable T>
void List<T>::List_node::set_next(const std::shared_ptr<List<T>::List_node> &node) { _next = node; }


template <Assignable_comparable T>
void List<T>::List_node::set_next(const List_node &node)
{
    std::shared_ptr<List<T>::List_node> ptr(node);
    _next = ptr;
}


template <Assignable_comparable T>
std::shared_ptr<typename List<T>::List_node> List<T>::List_node::get_next() const { return _next; }


template <Assignable_comparable T>
bool List<T>::List_node::operator!=(const std::shared_ptr<List<T>::List_node> &node) const { return this != node; }


template <Assignable_comparable T>
bool List<T>::List_node::operator==(const std::shared_ptr<List<T>::List_node> &node) const { return this == node; }


template <Assignable_comparable T>
T &List<T>::List_node::get_ref() { return _data; }


#endif //LAB_02_LIST_NODE_HPP
