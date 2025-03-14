cmake_minimum_required(VERSION 3.10)
project(CarSerial)

#include_directories(${CMAKE_CURRENT_LIST_DIR}/include)
set(
    SOURCES 
    main.c 
    serial.c
    )
add_executable(CarSerial main.c serial.c)
