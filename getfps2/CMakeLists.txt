cmake_minimum_required(VERSION 3.0)
project( getfps2 )
set (CMAKE_CXX_STANDARD 14)

add_executable( getfps2 getfps2.cpp )
target_link_libraries( getfps2 ${OpenCV_LIBS} )