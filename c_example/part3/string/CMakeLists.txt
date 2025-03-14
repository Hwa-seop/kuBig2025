cmake_minimum_required(VERSION 3.10)
project(string)

#include_directories(${CMAKE_CURRENT_LIST_DIR}/include)
set(
    SOURCES 
    main.c 
    MyString.c
    )
add_executable(string main.c MyString.c)
