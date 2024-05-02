//
// Created by max on 5/2/24.
//

#ifndef LAB_02_LIST_BASE_ITERATOR_HPP
#define LAB_02_LIST_BASE_ITERATOR_HPP




template<typename T>
std::shared_ptr<typename List_base_iterator<T>::List_node> List_base_iterator<T>::get_node() const
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
bool List_base_iterator<T>::is_invalid() const
{
    return _ptr_cur.expired();
}


template<typename T>
void List_base_iterator<T>::next()
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
List_base_iterator<T>::operator bool() const
{
    return !_ptr_cur.expired();
}


template<typename T>
List_base_iterator<T>::const_reference List_base_iterator<T>::operator*() const
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
List_base_iterator<T>::const_pointer List_base_iterator<T>::operator->() const
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
List_base_iterator<T>::const_value_type List_base_iterator<T>::get() const
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


#endif //LAB_02_LIST_BASE_ITERATOR_HPP
