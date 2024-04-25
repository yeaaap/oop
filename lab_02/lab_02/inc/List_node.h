//
// Created by max on 4/15/24.
//

#ifndef LAB_02_LIST_NODE_H
#define LAB_02_LIST_NODE_H

#include <memory>


template <typename T>
class List_node
{
public:
    List_node();
    List_node(const T &data);
    List_node(std::shared_ptr<List_node<T>> &node);

    ~List_node() = default;

    void set_data(const T &data);
    void set_next(const std::shared_ptr<List_node<T>> &node);
    void set_next(const List_node &node);

    const T &get_data() const;
    T &get_data();
    std::shared_ptr<List_node<T>> get_next() const;

    bool operator == (const std::shared_ptr<List_node<T>> &node) const;
    bool operator != (const std::shared_ptr<List_node<T>> &node) const;
private:
    T _data;
    std::shared_ptr<List_node<T>> _next;
};


#include "List_node.hpp"

#endif //LAB_02_LIST_NODE_H
