//
// Created by max on 4/15/24.
//

#ifndef BASE_CONTAINER_H
#define BASE_CONTAINER_H


#include <cstddef>


class Base_container
{
public:
    virtual ~Base_container() = default;

    virtual bool is_empty() const noexcept = 0;
    virtual void clear() = 0;

protected:
    size_t _size = 0;
};


#endif //BASE_CONTAINER_H
