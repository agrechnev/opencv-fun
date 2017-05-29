cmake_minimum_required(VERSION 3.0)
project( show )
set (CMAKE_CXX_STANDARD 14)

add_executable( show show.cpp )
target_link_libraries( show ${OpenCV_LIBS} )