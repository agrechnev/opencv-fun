cmake_minimum_required(VERSION 3.0)
project( example )

set (CMAKE_CXX_STANDARD 14)

# file(COPY img DESTINATION .)

add_executable( example example.cpp )
target_link_libraries( example ${OpenCV_LIBS} )