cmake_minimum_required(VERSION 3.0)
project( raw1 )
set (CMAKE_CXX_STANDARD 14)

add_executable( raw1 raw1.cpp )
target_link_libraries( raw1 ${OpenCV_LIBS} )