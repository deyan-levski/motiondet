# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /media/data/c/motiondet/smartmotion

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/data/c/motiondet/smartmotion

# Include any dependencies generated for this target.
include CMakeFiles/SmartMotion.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SmartMotion.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SmartMotion.dir/flags.make

CMakeFiles/SmartMotion.dir/main.cpp.o: CMakeFiles/SmartMotion.dir/flags.make
CMakeFiles/SmartMotion.dir/main.cpp.o: main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /media/data/c/motiondet/smartmotion/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/SmartMotion.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/SmartMotion.dir/main.cpp.o -c /media/data/c/motiondet/smartmotion/main.cpp

CMakeFiles/SmartMotion.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SmartMotion.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /media/data/c/motiondet/smartmotion/main.cpp > CMakeFiles/SmartMotion.dir/main.cpp.i

CMakeFiles/SmartMotion.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SmartMotion.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /media/data/c/motiondet/smartmotion/main.cpp -o CMakeFiles/SmartMotion.dir/main.cpp.s

CMakeFiles/SmartMotion.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/SmartMotion.dir/main.cpp.o.requires

CMakeFiles/SmartMotion.dir/main.cpp.o.provides: CMakeFiles/SmartMotion.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/SmartMotion.dir/build.make CMakeFiles/SmartMotion.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/SmartMotion.dir/main.cpp.o.provides

CMakeFiles/SmartMotion.dir/main.cpp.o.provides.build: CMakeFiles/SmartMotion.dir/main.cpp.o

# Object files for target SmartMotion
SmartMotion_OBJECTS = \
"CMakeFiles/SmartMotion.dir/main.cpp.o"

# External object files for target SmartMotion
SmartMotion_EXTERNAL_OBJECTS =

SmartMotion: CMakeFiles/SmartMotion.dir/main.cpp.o
SmartMotion: CMakeFiles/SmartMotion.dir/build.make
SmartMotion: /usr/local/lib/libopencv_videostab.so.2.4.9
SmartMotion: /usr/local/lib/libopencv_video.so.2.4.9
SmartMotion: /usr/local/lib/libopencv_ts.a
SmartMotion: /usr/local/lib/libopencv_superres.so.2.4.9
SmartMotion: /usr/local/lib/libopencv_stitching.so.2.4.9
SmartMotion: /usr/local/lib/libopencv_photo.so.2.4.9
SmartMotion: /usr/local/lib/libopencv_ocl.so.2.4.9
SmartMotion: /usr/local/lib/libopencv_objdetect.so.2.4.9
SmartMotion: /usr/local/lib/libopencv_nonfree.so.2.4.9
SmartMotion: /usr/local/lib/libopencv_ml.so.2.4.9
SmartMotion: /usr/local/lib/libopencv_legacy.so.2.4.9
SmartMotion: /usr/local/lib/libopencv_imgproc.so.2.4.9
SmartMotion: /usr/local/lib/libopencv_highgui.so.2.4.9
SmartMotion: /usr/local/lib/libopencv_gpu.so.2.4.9
SmartMotion: /usr/local/lib/libopencv_flann.so.2.4.9
SmartMotion: /usr/local/lib/libopencv_features2d.so.2.4.9
SmartMotion: /usr/local/lib/libopencv_core.so.2.4.9
SmartMotion: /usr/local/lib/libopencv_contrib.so.2.4.9
SmartMotion: /usr/local/lib/libopencv_calib3d.so.2.4.9
SmartMotion: /usr/lib/i386-linux-gnu/libGLU.so
SmartMotion: /usr/lib/i386-linux-gnu/libGL.so
SmartMotion: /usr/lib/i386-linux-gnu/libSM.so
SmartMotion: /usr/lib/i386-linux-gnu/libICE.so
SmartMotion: /usr/lib/i386-linux-gnu/libX11.so
SmartMotion: /usr/lib/i386-linux-gnu/libXext.so
SmartMotion: /usr/local/lib/libopencv_nonfree.so.2.4.9
SmartMotion: /usr/local/lib/libopencv_ocl.so.2.4.9
SmartMotion: /usr/local/lib/libopencv_gpu.so.2.4.9
SmartMotion: /usr/local/lib/libopencv_photo.so.2.4.9
SmartMotion: /usr/local/lib/libopencv_objdetect.so.2.4.9
SmartMotion: /usr/local/lib/libopencv_legacy.so.2.4.9
SmartMotion: /usr/local/lib/libopencv_video.so.2.4.9
SmartMotion: /usr/local/lib/libopencv_ml.so.2.4.9
SmartMotion: /usr/local/lib/libopencv_calib3d.so.2.4.9
SmartMotion: /usr/local/lib/libopencv_features2d.so.2.4.9
SmartMotion: /usr/local/lib/libopencv_highgui.so.2.4.9
SmartMotion: /usr/local/lib/libopencv_imgproc.so.2.4.9
SmartMotion: /usr/local/lib/libopencv_flann.so.2.4.9
SmartMotion: /usr/local/lib/libopencv_core.so.2.4.9
SmartMotion: CMakeFiles/SmartMotion.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable SmartMotion"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SmartMotion.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SmartMotion.dir/build: SmartMotion
.PHONY : CMakeFiles/SmartMotion.dir/build

CMakeFiles/SmartMotion.dir/requires: CMakeFiles/SmartMotion.dir/main.cpp.o.requires
.PHONY : CMakeFiles/SmartMotion.dir/requires

CMakeFiles/SmartMotion.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SmartMotion.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SmartMotion.dir/clean

CMakeFiles/SmartMotion.dir/depend:
	cd /media/data/c/motiondet/smartmotion && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/data/c/motiondet/smartmotion /media/data/c/motiondet/smartmotion /media/data/c/motiondet/smartmotion /media/data/c/motiondet/smartmotion /media/data/c/motiondet/smartmotion/CMakeFiles/SmartMotion.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SmartMotion.dir/depend

