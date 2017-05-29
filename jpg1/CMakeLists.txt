cmake_minimum_required(VERSION 3.0)
project( jpg1 )

set (CMAKE_CXX_STANDARD 14)

add_executable( jpg1 jpg1.cpp )
target_link_libraries( jpg1 ${OpenCV_LIBS} )