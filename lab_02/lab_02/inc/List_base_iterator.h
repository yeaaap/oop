//
// Created by max on 5/2/24.
//

#ifndef LAB_02_LIST_BASE_ITERATOR_H
#define LAB_02_LIST_BASE_ITERATOR_H


#include "concept.h"
#include "errors.h"


template <Assignable_comparable T>
class List;

template <typename T>
class List_base_iterator
{
public:
    using value_type = const T;
    using pointer = std::shared_ptr<const T>;
    using reference = const T&;
    using iterator_category = std::forward_iterator_tag;
    using difference_type = int;
    using List_node = List<T>::List_node;

    friend class List<T>;

    ~List_base_iterator() = default;

    void next();
    bool is_invalid() const;
    operator bool() const;

    pointer operator->() const;
    reference operator*() const;

    value_type get() const;

protected:
    List_base_iterator();
    std::shared_ptr<List_node> get_node() const;
    std::weak_ptr<List_node> _ptr_cur;
};



#include "List_base_iterator.hpp"


#endif //LAB_02_LIST_BASE_ITERATOR_H
