cmake_minimum_required(VERSION 3.10)
project(MainProject)

# 내부 CMakeLists.txt 포함
#include(sqlQuery/CMakeLists.txt)
#include(c_example/part1/CMakeLists.txt)

# add_subdirectory(sqlQuery)
# add_subdirectory(c_example/part1)
# add_subdirectory(c_example/part2)
# add_subdirectory(c_example/part3)
add_subdirectory(stl)
add_subdirectory(smartpoint)
add_subdirectory(cpp)
add_subdirectory(network/ipc)
add_subdirectory(network/util)
add_subdirectory(network/tcp_udp)
add_subdirectory(network/multiProcess)
add_subdirectory(hs_practice)




