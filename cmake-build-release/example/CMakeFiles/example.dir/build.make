# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/seymour/CLION/clion-2017.3.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/seymour/CLION/clion-2017.3.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/seymour/w/0/opencv-fun

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/seymour/w/0/opencv-fun/cmake-build-release

# Include any dependencies generated for this target.
include example/CMakeFiles/example.dir/depend.make

# Include the progress variables for this target.
include example/CMakeFiles/example.dir/progress.make

# Include the compile flags for this target's objects.
include example/CMakeFiles/example.dir/flags.make

example/CMakeFiles/example.dir/example.cpp.o: example/CMakeFiles/example.dir/flags.make
example/CMakeFiles/example.dir/example.cpp.o: ../example/example.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/seymour/w/0/opencv-fun/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object example/CMakeFiles/example.dir/example.cpp.o"
	cd /home/seymour/w/0/opencv-fun/cmake-build-release/example && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/example.dir/example.cpp.o -c /home/seymour/w/0/opencv-fun/example/example.cpp

example/CMakeFiles/example.dir/example.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example.dir/example.cpp.i"
	cd /home/seymour/w/0/opencv-fun/cmake-build-release/example && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/seymour/w/0/opencv-fun/example/example.cpp > CMakeFiles/example.dir/example.cpp.i

example/CMakeFiles/example.dir/example.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example.dir/example.cpp.s"
	cd /home/seymour/w/0/opencv-fun/cmake-build-release/example && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/seymour/w/0/opencv-fun/example/example.cpp -o CMakeFiles/example.dir/example.cpp.s

example/CMakeFiles/example.dir/example.cpp.o.requires:

.PHONY : example/CMakeFiles/example.dir/example.cpp.o.requires

example/CMakeFiles/example.dir/example.cpp.o.provides: example/CMakeFiles/example.dir/example.cpp.o.requires
	$(MAKE) -f example/CMakeFiles/example.dir/build.make example/CMakeFiles/example.dir/example.cpp.o.provides.build
.PHONY : example/CMakeFiles/example.dir/example.cpp.o.provides

example/CMakeFiles/example.dir/example.cpp.o.provides.build: example/CMakeFiles/example.dir/example.cpp.o


# Object files for target example
example_OBJECTS = \
"CMakeFiles/example.dir/example.cpp.o"

# External object files for target example
example_EXTERNAL_OBJECTS =

example/example: example/CMakeFiles/example.dir/example.cpp.o
example/example: example/CMakeFiles/example.dir/build.make
example/example: /usr/lib/x86_64-linux-gnu/libopencv_shape.so.3.2.0
example/example: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.3.2.0
example/example: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.3.2.0
example/example: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.3.2.0
example/example: /usr/lib/x86_64-linux-gnu/libopencv_aruco.so.3.2.0
example/example: /usr/lib/x86_64-linux-gnu/libopencv_bgsegm.so.3.2.0
example/example: /usr/lib/x86_64-linux-gnu/libopencv_bioinspired.so.3.2.0
example/example: /usr/lib/x86_64-linux-gnu/libopencv_ccalib.so.3.2.0
example/example: /usr/lib/x86_64-linux-gnu/libopencv_datasets.so.3.2.0
example/example: /usr/lib/x86_64-linux-gnu/libopencv_dpm.so.3.2.0
example/example: /usr/lib/x86_64-linux-gnu/libopencv_face.so.3.2.0
example/example: /usr/lib/x86_64-linux-gnu/libopencv_freetype.so.3.2.0
example/example: /usr/lib/x86_64-linux-gnu/libopencv_fuzzy.so.3.2.0
example/example: /usr/lib/x86_64-linux-gnu/libopencv_hdf.so.3.2.0
example/example: /usr/lib/x86_64-linux-gnu/libopencv_line_descriptor.so.3.2.0
example/example: /usr/lib/x86_64-linux-gnu/libopencv_optflow.so.3.2.0
example/example: /usr/lib/x86_64-linux-gnu/libopencv_plot.so.3.2.0
example/example: /usr/lib/x86_64-linux-gnu/libopencv_reg.so.3.2.0
example/example: /usr/lib/x86_64-linux-gnu/libopencv_saliency.so.3.2.0
example/example: /usr/lib/x86_64-linux-gnu/libopencv_stereo.so.3.2.0
example/example: /usr/lib/x86_64-linux-gnu/libopencv_structured_light.so.3.2.0
example/example: /usr/lib/x86_64-linux-gnu/libopencv_surface_matching.so.3.2.0
example/example: /usr/lib/x86_64-linux-gnu/libopencv_text.so.3.2.0
example/example: /usr/lib/x86_64-linux-gnu/libopencv_ximgproc.so.3.2.0
example/example: /usr/lib/x86_64-linux-gnu/libopencv_xobjdetect.so.3.2.0
example/example: /usr/lib/x86_64-linux-gnu/libopencv_xphoto.so.3.2.0
example/example: /usr/lib/x86_64-linux-gnu/libopencv_video.so.3.2.0
example/example: /usr/lib/x86_64-linux-gnu/libopencv_viz.so.3.2.0
example/example: /usr/lib/x86_64-linux-gnu/libopencv_phase_unwrapping.so.3.2.0
example/example: /usr/lib/x86_64-linux-gnu/libopencv_rgbd.so.3.2.0
example/example: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.3.2.0
example/example: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.3.2.0
example/example: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.3.2.0
example/example: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.3.2.0
example/example: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.3.2.0
example/example: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.3.2.0
example/example: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.3.2.0
example/example: /usr/lib/x86_64-linux-gnu/libopencv_videoio.so.3.2.0
example/example: /usr/lib/x86_64-linux-gnu/libopencv_imgcodecs.so.3.2.0
example/example: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.3.2.0
example/example: /usr/lib/x86_64-linux-gnu/libopencv_core.so.3.2.0
example/example: example/CMakeFiles/example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/seymour/w/0/opencv-fun/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable example"
	cd /home/seymour/w/0/opencv-fun/cmake-build-release/example && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
example/CMakeFiles/example.dir/build: example/example

.PHONY : example/CMakeFiles/example.dir/build

example/CMakeFiles/example.dir/requires: example/CMakeFiles/example.dir/example.cpp.o.requires

.PHONY : example/CMakeFiles/example.dir/requires

example/CMakeFiles/example.dir/clean:
	cd /home/seymour/w/0/opencv-fun/cmake-build-release/example && $(CMAKE_COMMAND) -P CMakeFiles/example.dir/cmake_clean.cmake
.PHONY : example/CMakeFiles/example.dir/clean

example/CMakeFiles/example.dir/depend:
	cd /home/seymour/w/0/opencv-fun/cmake-build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/seymour/w/0/opencv-fun /home/seymour/w/0/opencv-fun/example /home/seymour/w/0/opencv-fun/cmake-build-release /home/seymour/w/0/opencv-fun/cmake-build-release/example /home/seymour/w/0/opencv-fun/cmake-build-release/example/CMakeFiles/example.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : example/CMakeFiles/example.dir/depend

