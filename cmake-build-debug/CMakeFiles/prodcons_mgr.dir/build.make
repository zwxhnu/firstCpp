# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/apple/CLionProjects/firstCpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/apple/CLionProjects/firstCpp/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/prodcons_mgr.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/prodcons_mgr.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/prodcons_mgr.dir/flags.make

CMakeFiles/prodcons_mgr.dir/thread/Producer-consumer.cpp.o: CMakeFiles/prodcons_mgr.dir/flags.make
CMakeFiles/prodcons_mgr.dir/thread/Producer-consumer.cpp.o: ../thread/Producer-consumer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/apple/CLionProjects/firstCpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/prodcons_mgr.dir/thread/Producer-consumer.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/prodcons_mgr.dir/thread/Producer-consumer.cpp.o -c /Users/apple/CLionProjects/firstCpp/thread/Producer-consumer.cpp

CMakeFiles/prodcons_mgr.dir/thread/Producer-consumer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/prodcons_mgr.dir/thread/Producer-consumer.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/apple/CLionProjects/firstCpp/thread/Producer-consumer.cpp > CMakeFiles/prodcons_mgr.dir/thread/Producer-consumer.cpp.i

CMakeFiles/prodcons_mgr.dir/thread/Producer-consumer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/prodcons_mgr.dir/thread/Producer-consumer.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/apple/CLionProjects/firstCpp/thread/Producer-consumer.cpp -o CMakeFiles/prodcons_mgr.dir/thread/Producer-consumer.cpp.s

# Object files for target prodcons_mgr
prodcons_mgr_OBJECTS = \
"CMakeFiles/prodcons_mgr.dir/thread/Producer-consumer.cpp.o"

# External object files for target prodcons_mgr
prodcons_mgr_EXTERNAL_OBJECTS =

prodcons_mgr: CMakeFiles/prodcons_mgr.dir/thread/Producer-consumer.cpp.o
prodcons_mgr: CMakeFiles/prodcons_mgr.dir/build.make
prodcons_mgr: CMakeFiles/prodcons_mgr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/apple/CLionProjects/firstCpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable prodcons_mgr"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/prodcons_mgr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/prodcons_mgr.dir/build: prodcons_mgr

.PHONY : CMakeFiles/prodcons_mgr.dir/build

CMakeFiles/prodcons_mgr.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/prodcons_mgr.dir/cmake_clean.cmake
.PHONY : CMakeFiles/prodcons_mgr.dir/clean

CMakeFiles/prodcons_mgr.dir/depend:
	cd /Users/apple/CLionProjects/firstCpp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/apple/CLionProjects/firstCpp /Users/apple/CLionProjects/firstCpp /Users/apple/CLionProjects/firstCpp/cmake-build-debug /Users/apple/CLionProjects/firstCpp/cmake-build-debug /Users/apple/CLionProjects/firstCpp/cmake-build-debug/CMakeFiles/prodcons_mgr.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/prodcons_mgr.dir/depend

