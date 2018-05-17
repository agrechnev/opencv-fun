cmake_minimum_required(VERSION 3.0)
project( feat1 )
set (CMAKE_CXX_STANDARD 14)

file(COPY ../fun2/img DESTINATION .)

add_executable( ${PROJECT_NAME} main.cpp)
target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS} )