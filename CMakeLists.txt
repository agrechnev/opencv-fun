cmake_minimum_required(VERSION 3.0)
project (opencvfun)

set (CMAKE_CXX_STANDARD 14)


# Put here opencv dir if needed
#if(WIN32)
# set(OpenCV_DIR d:/opencv)
#else()
# set(OpenCV_DIR  ~/opencv3/share/OpenCV)
#endif()


# Threads
find_package(Threads)


find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

# Build all examples
add_subdirectory(example)
add_subdirectory(fun-draw)
add_subdirectory(fun2)
#add_subdirectory(feat1)
#add_subdirectory(feat2)
add_subdirectory(getfps)
#add_subdirectory(getfps2)
add_subdirectory(grabcam)
#add_subdirectory(jpg1)
#add_subdirectory(jpg2)
#add_subdirectory(raw1)
#add_subdirectory(raw2)
add_subdirectory(show)
add_subdirectory(face)
