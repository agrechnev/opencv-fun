cmake_minimum_required(VERSION 3.0)
project (opencvfun)

set (CMAKE_CXX_STANDARD 14)

set(OpenCV_DIR d:/opencv)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

# Build all examples
add_subdirectory(example)
add_subdirectory(fun)
add_subdirectory(getfps)
add_subdirectory(grabcam)
add_subdirectory(jpg1)
add_subdirectory(jpg2)
add_subdirectory(raw1)
add_subdirectory(raw2)
add_subdirectory(show)
