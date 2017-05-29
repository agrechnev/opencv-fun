cmake_minimum_required(VERSION 3.0)
project( getfps )
set (CMAKE_CXX_STANDARD 14)

add_executable( getfps getfps.cpp )
target_link_libraries( getfps ${OpenCV_LIBS} )