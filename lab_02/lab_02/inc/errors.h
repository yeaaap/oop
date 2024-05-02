//
// Created by max on 4/17/24.
//

#ifndef LAB_02_ERRORS_H
#define LAB_02_ERRORS_H


#include <execution>
#include <cstdio>

#define LEN_MESSAGE 1023


class Base_error : public std::exception
{
public:
    explicit Base_error(const char *file_name,
                        const char *class_name,
                        const char *time,
                        const int line,
                        const char *type = "Unknown error!")
    {
        snprintf(_message, LEN_MESSAGE, "\nERROR: %s \
                   \nTime:  %s \
                   \nFile:  %s \
                   \nClass: %s \
                   \nLine:  %d",
                   type, time, file_name, class_name, line);
    }


    virtual const char* what() const noexcept override
    {
        return _message;
    }

protected:
    char _message[LEN_MESSAGE + 1];
};



class List_base_error : public Base_error
{
public:
    List_base_error(const char *file_name,
                              const char *class_name,
                              const char *time,
                              const int line,
                              const char *type = "Unknown error!")
                              : Base_error(file_name, class_name, time, line, type) {};
};


class Memory_error: public List_base_error
{
public:
    Memory_error(const char *file_name,
                 const char *class_name,
                 const char *time,
                 const int line,
                 const char *type = "Memory allocation error!") : List_base_error(
                         file_name, class_name, time, line, type){}
};


class Empty_list_error : public List_base_error
{
public:
    Empty_list_error(const char *file_name,
                     const char *class_name,
                     const char *time,
                     const int line,
                     const char *type = "List is empty!") : List_base_error(
            file_name, class_name, time, line, type){}
};


class Iterator_base_error : public Base_error
{
public:
    Iterator_base_error(const char *file_name,
                     const char *class_name,
                     const char *time,
                     const int line,
                     const char *type = "Iterator error!") : Base_error(
            file_name, class_name, time, line, type){}
};


class Iterator_error : public Iterator_base_error
{
public:
    Iterator_error(const char *file_name,
                   const char *class_name,
                   const char *time,
                   const int line,
                   const char *type = "Invalid iterator!") : Iterator_base_error(
            file_name, class_name, time, line, type){}
};


class Pointer_error : public Iterator_base_error
{
public:
    Pointer_error(const char *file_name,
                  const char *class_name,
                  const char *time,
                  const int line,
                  const char *type = "Invalid pointer!") : Iterator_base_error(
            file_name, class_name, time, line, type){}
};


#endif //LAB_02_ERRORS_H
