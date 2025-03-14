cmake_minimum_required(VERSION 3.10)
project(part3)


#모든 .c파일 감지

file(GLOB EXECUTABLES "${CMAKE_CURRENT_LIST_DIR}/*.c")

foreach(EXECUTABLE ${EXECUTABLES})
     get_filename_component(EXE_NAME ${EXECUTABLE} NAME_WE)
     add_executable(${EXE_NAME} ${EXECUTABLE})
endforeach()

#하위 디렉토리 추가
add_subdirectory(CarSerial)
add_subdirectory(date)
#add_subdirectory(MyRandom)
add_subdirectory(string)


# set(CMAKE_C_COMPILER "/usr/bin/gcc")
# set(CMAKE_C_STANDARD 99)
# set(CMAKE_C_STANDARD_REQUIRED ON)

# set(EXCUTABLES 
# c_example/part1/infinit.c