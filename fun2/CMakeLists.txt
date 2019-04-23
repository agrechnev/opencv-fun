cmake_minimum_required(VERSION 3.0)
project( fun2 )
set (CMAKE_CXX_STANDARD 14)

file(COPY img DESTINATION .)

add_executable( ${PROJECT_NAME} fun2.cpp )
target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS} ${CMAKE_THREAD_LIBS_INIT})