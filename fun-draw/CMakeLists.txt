cmake_minimum_required(VERSION 3.0)
project( fun-draw )
set (CMAKE_CXX_STANDARD 14)

add_executable( ${PROJECT_NAME} fun.cpp )
target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS} )