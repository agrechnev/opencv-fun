cmake_minimum_required(VERSION 3.0)
project( fun )
set (CMAKE_CXX_STANDARD 14)

file(COPY img DESTINATION .)

add_executable( fun fun.cpp )
target_link_libraries( fun ${OpenCV_LIBS} )