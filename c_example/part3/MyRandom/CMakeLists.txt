cmake_minimum_required(VERSION 3.10)
project(MyRandom)

#include_directories(${CMAKE_CURRENT_LIST_DIR}/include)
set(
    SOURCES 
    MyRandom.c
    )
add_executable(MyRandom ${SOURCES})
