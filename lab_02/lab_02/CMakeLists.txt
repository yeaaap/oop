cmake_minimum_required(VERSION 3.28)
project(lab_02)

set(CMAKE_CXX_STANDARD 23)

include_directories(inc)
add_executable(lab_02 main.cpp
        inc/Base_container.h
        inc/List_node.hpp
        inc/List.h
        inc/List_iterator.h
        inc/List_iterator.hpp
        inc/errors.h
        inc/List.hpp
        inc/concept.h
        inc/List_iterator_const.h
        inc/List_iterator_const.hpp
        inc/List_base_iterator.h
        inc/List_base_iterator.hpp
)
