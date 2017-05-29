cmake_minimum_required(VERSION 3.0)
project( raw2 )
set (CMAKE_CXX_STANDARD 14)

add_executable( raw2 raw2.cpp )
target_link_libraries( raw2 ${OpenCV_LIBS} )