//
// Created by max on 4/21/24.
//

#ifndef LAB_02_BASE_ITERATOR_H
#define LAB_02_BASE_ITERATOR_H

#include "List_node.h"
#include "errors.h"


class Base_iterator
{
public:
    virtual ~Base_iterator() = default;

    virtual void next() = 0;
    virtual bool is_invalid() const = 0;
};


#endif //LAB_02_BASE_ITERATOR_H
