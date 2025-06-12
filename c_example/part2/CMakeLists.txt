cmake_minimum_required(VERSION 3.10)
project(part2)


#모든 .c파일 감지

file(GLOB EXECUTABLES "${CMAKE_CURRENT_LIST_DIR}/*.c")

foreach(EXECUTABLE ${EXECUTABLES})
     get_filename_component(EXE_NAME ${EXECUTABLE} NAME_WE)
     add_executable(${EXE_NAME} ${EXECUTABLE})
endforeach()

# set(CMAKE_C_COMPILER "/usr/bin/gcc")
# set(CMAKE_C_STANDARD 99)
# set(CMAKE_C_STANDARD_REQUIRED ON)

# set(EXCUTABLES 
# c_example/part1/infinit.c