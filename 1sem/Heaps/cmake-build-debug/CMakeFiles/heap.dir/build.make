# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\wtfal\CLionProjects\heap

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\wtfal\CLionProjects\heap\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/heap.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/heap.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/heap.dir/flags.make

CMakeFiles/heap.dir/heap.cpp.obj: CMakeFiles/heap.dir/flags.make
CMakeFiles/heap.dir/heap.cpp.obj: ../heap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\wtfal\CLionProjects\heap\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/heap.dir/heap.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\heap.dir\heap.cpp.obj -c C:\Users\wtfal\CLionProjects\heap\heap.cpp

CMakeFiles/heap.dir/heap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/heap.dir/heap.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\wtfal\CLionProjects\heap\heap.cpp > CMakeFiles\heap.dir\heap.cpp.i

CMakeFiles/heap.dir/heap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/heap.dir/heap.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\wtfal\CLionProjects\heap\heap.cpp -o CMakeFiles\heap.dir\heap.cpp.s

CMakeFiles/heap.dir/test.cpp.obj: CMakeFiles/heap.dir/flags.make
CMakeFiles/heap.dir/test.cpp.obj: ../test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\wtfal\CLionProjects\heap\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/heap.dir/test.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\heap.dir\test.cpp.obj -c C:\Users\wtfal\CLionProjects\heap\test.cpp

CMakeFiles/heap.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/heap.dir/test.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\wtfal\CLionProjects\heap\test.cpp > CMakeFiles\heap.dir\test.cpp.i

CMakeFiles/heap.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/heap.dir/test.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\wtfal\CLionProjects\heap\test.cpp -o CMakeFiles\heap.dir\test.cpp.s

# Object files for target heap
heap_OBJECTS = \
"CMakeFiles/heap.dir/heap.cpp.obj" \
"CMakeFiles/heap.dir/test.cpp.obj"

# External object files for target heap
heap_EXTERNAL_OBJECTS =

heap.exe: CMakeFiles/heap.dir/heap.cpp.obj
heap.exe: CMakeFiles/heap.dir/test.cpp.obj
heap.exe: CMakeFiles/heap.dir/build.make
heap.exe: CMakeFiles/heap.dir/linklibs.rsp
heap.exe: CMakeFiles/heap.dir/objects1.rsp
heap.exe: CMakeFiles/heap.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\wtfal\CLionProjects\heap\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable heap.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\heap.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/heap.dir/build: heap.exe

.PHONY : CMakeFiles/heap.dir/build

CMakeFiles/heap.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\heap.dir\cmake_clean.cmake
.PHONY : CMakeFiles/heap.dir/clean

CMakeFiles/heap.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\wtfal\CLionProjects\heap C:\Users\wtfal\CLionProjects\heap C:\Users\wtfal\CLionProjects\heap\cmake-build-debug C:\Users\wtfal\CLionProjects\heap\cmake-build-debug C:\Users\wtfal\CLionProjects\heap\cmake-build-debug\CMakeFiles\heap.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/heap.dir/depend
