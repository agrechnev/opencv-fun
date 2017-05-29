cmake_minimum_required(VERSION 3.0)
project( jpg2 )
set (CMAKE_CXX_STANDARD 14)

add_executable( jpg2 jpg2.cpp )
target_link_libraries( jpg2 ${OpenCV_LIBS} )