//
// Created by max on 4/15/24.
//

#ifndef LAB_02_LIST_H
#define LAB_02_LIST_H

#include "Base_container.h"
#include "List_iterator.h"
#include "List_iterator_const.h"
#include "List_base_iterator.h"
#include "concept.h"


template <Comparable T>
class List : public Base_container
{
public:
    using value_type = T;
    using iterator = List_iterator<T>;
    using const_iterator = List_iterator_const<T>;
    using size_type = size_t;

    friend class List_iterator<T>;
    friend class List_iterator_const<T>;
    friend class List_base_iterator<T>;

    List();
    template <typename U>
    requires Convertable_to<U, T>
    explicit List(const List<U> &list);
    explicit List(const List<T> &list);
    List(List<T> &&list) noexcept;
    List(const T *arr, size_t size);
    List(std::initializer_list<T> nodes);

    template <Iterator I>
    List(const I &begin, const I &end);
    template <Iterator I>
    List(const I &begin, size_type count);

    template <typename C>
    requires Container<C> && Convertable_to<typename C::value_type, T>
    explicit List(const C &container);


    List<T> &operator=(List<T> &&list) noexcept;
    template <typename U>
    requires Convertable_to<U, T>
    List<T> &operator=(const List<U> &list);
    List<T> &operator=(const List<T> &list);

    ~List() override = default;

    bool is_empty() const noexcept override;
    void clear() override;

    size_type size();

    void push_front(const T &data);
    void push_back(const T &data);

    template <typename U>
    requires Convertable_to<U, T>
    void push_front(const List<U> &list);
    template <typename U>
    requires Convertable_to<U, T>
    void push_back(const List<U> &list);

    iterator insert(const const_iterator &iterator, const T &data);
    iterator insert(const iterator &iterator, const T &data);

    iterator insert(const const_iterator &iterator, const List<T> &list);
    iterator insert(const iterator &iterator, const List<T> &list);

    template <typename U>
    requires Convertable_to<U, T>
    iterator insert(const const_iterator &iterator, const List<U> &list);
    template <typename U>
    requires Convertable_to<U, T>
    iterator insert(const iterator &iterator, const List<U> &list);

    value_type pop_back();
    value_type pop_front();
    value_type front();
    value_type back();

    size_type remove(const iterator &iterator);
    size_type remove(const T &data);

    void reverse();

    List<T> &merge(const T &data);
    template <typename U>
    requires Convertable_to<U, T>
    List<T> &merge(const List<U> &list);
    List<T> &merge(const List<T> &list);

    List<T> &operator+=(const T &data);
    template <typename U>
    requires Convertable_to<U, T>
    List<T> &operator+=(const List<U> &list);

    List<T> operator+(const T &data);
    template <typename U>
    requires Convertable_to<U, T>
    List<T> operator+(const List<U> &list);
    List<T> operator+(const List<T> &list);

    List<T> &add(const T &data);
    template <typename U>
    requires Convertable_to<U, T>
    List<T> &add(const List<U> &list);
    List<T> &add(const List<T> &list);


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

protected:
    class List_node
    {
    public:
        template <Constructable_empty U>
        List_node();
        explicit List_node(const T &data);
        List_node(const T &data, std::shared_ptr<List_node> &next);
        explicit List_node(std::shared_ptr<List_node> &node);
        List_node(List_node &&node) noexcept;
        List_node(const List_node &node);

        ~List_node() = default;

        void set_data(const T &data);
        void set_next(const std::shared_ptr<List_node> &node);
        void set_next(const List_node &node);

        const T &get_data() const;
        T &get_ref();
        std::shared_ptr<List_node> get_next() const;

        bool operator == (const std::shared_ptr<List_node> &node) const;
        bool operator != (const std::shared_ptr<List_node> &node) const;
    private:
        T _data;
        std::shared_ptr<List_node> _next;
    };


protected:
    void push_back(std::shared_ptr<List_node> &node);
    void push_front(std::shared_ptr<List_node> &node);
private:
    std::shared_ptr<List_node> _head;
    std::shared_ptr<List_node> _tail;
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
#include "List_node.hpp"


#endif //LAB_02_LIST_H
