cmake_minimum_required(VERSION 3.0)
project(OpenCV_part1)

find_package(OpenCV REQUIRED)

file(GLOB SOURCES "*.cpp")

foreach(SOURCE ${SOURCES})
    get_filename_component(EXE_NAME ${SOURCE} NAME_WE)
    add_executable(${EXE_NAME} ${SOURCE})
    target_link_libraries(${EXE_NAME} ${OpenCV_LIBS})
endforeach()




# # add_executable(실행명, 이름)
# add_executable(hello 01_helloworld.cpp)
# target_link_libraries(hello ${OpenCV_LIBS})

# add_executable(basic_op 02_basicOp.cpp)
# target_link_libraries(basic_op ${OpenCV_LIBS})

# add_executable(mat_op 03_matOp.cpp)
# target_link_libraries(mat_op ${OpenCV_LIBS})