cmake_minimum_required(VERSION 3.0)
project( face )
set (CMAKE_CXX_STANDARD 14)

file(GLOB XML_FILES "*.xml")
file(COPY ${XML_FILES} DESTINATION .)

add_executable( ${PROJECT_NAME} face.cpp )
target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS} )