cmake_minimum_required(VERSION 3.0)
project( grabcam )

set (CMAKE_CXX_STANDARD 14)

add_executable( grabcam grabcam.cpp )
target_link_libraries( grabcam ${OpenCV_LIBS} )