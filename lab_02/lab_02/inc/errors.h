//
// Created by max on 4/17/24.
//

#ifndef LAB_02_ERRORS_H
#define LAB_02_ERRORS_H


#include <execution>
#include <string>


class Base_error : public std::exception
{
public:
    explicit Base_error(const std::string &file_name,
                        const std::string &class_name,
                        const std::string &time,
                        const int line,
                        const std::string &type = "Unknown error!")
    {
        _message = "\nERROR: " + type + \
                   "\nTime: " + time + \
                   "\nFile: " + file_name + \
                   "\nClass: " + class_name + \
                   "\nLine: " + std::to_string(line);
    }


    virtual const char* what() const noexcept override
    {
        return _message.c_str();
    }

protected:
    std::string _message;
};


class Memory_error: public Base_error
{
public:
    Memory_error(const std::string &file_name,
                 const std::string &class_name,
                 const std::string &time,
                 const int line,
                 const std::string &type = "Memory allocation error!") : Base_error(
                         file_name, class_name, time, line, type){}
};


class Empty_list_error : public Base_error
{
public:
    Empty_list_error(const std::string &file_name,
                 const std::string &class_name,
                 const std::string &time,
                 const int line,
                 const std::string &type = "List is empty!") : Base_error(
            file_name, class_name, time, line, type){}
};


class Iterator_error : public Base_error
{
public:
    Iterator_error(const std::string &file_name,
                     const std::string &class_name,
                     const std::string &time,
                     const int line,
                     const std::string &type = "Invalid iterator!") : Base_error(
            file_name, class_name, time, line, type){}
};


class Pointer_error : public Base_error
{
public:
    Pointer_error(const std::string &file_name,
                   const std::string &class_name,
                   const std::string &time,
                   const int line,
                   const std::string &type = "Invalid pointer!") : Base_error(
            file_name, class_name, time, line, type){}
};


#endif //LAB_02_ERRORS_H
