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
include CMakeFiles/string_mgr.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/string_mgr.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/string_mgr.dir/flags.make

CMakeFiles/string_mgr.dir/StringMgr.cpp.o: CMakeFiles/string_mgr.dir/flags.make
CMakeFiles/string_mgr.dir/StringMgr.cpp.o: ../StringMgr.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/apple/CLionProjects/firstCpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/string_mgr.dir/StringMgr.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/string_mgr.dir/StringMgr.cpp.o -c /Users/apple/CLionProjects/firstCpp/StringMgr.cpp

CMakeFiles/string_mgr.dir/StringMgr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/string_mgr.dir/StringMgr.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/apple/CLionProjects/firstCpp/StringMgr.cpp > CMakeFiles/string_mgr.dir/StringMgr.cpp.i

CMakeFiles/string_mgr.dir/StringMgr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/string_mgr.dir/StringMgr.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/apple/CLionProjects/firstCpp/StringMgr.cpp -o CMakeFiles/string_mgr.dir/StringMgr.cpp.s

# Object files for target string_mgr
string_mgr_OBJECTS = \
"CMakeFiles/string_mgr.dir/StringMgr.cpp.o"

# External object files for target string_mgr
string_mgr_EXTERNAL_OBJECTS =

string_mgr: CMakeFiles/string_mgr.dir/StringMgr.cpp.o
string_mgr: CMakeFiles/string_mgr.dir/build.make
string_mgr: CMakeFiles/string_mgr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/apple/CLionProjects/firstCpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable string_mgr"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/string_mgr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/string_mgr.dir/build: string_mgr

.PHONY : CMakeFiles/string_mgr.dir/build

CMakeFiles/string_mgr.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/string_mgr.dir/cmake_clean.cmake
.PHONY : CMakeFiles/string_mgr.dir/clean

CMakeFiles/string_mgr.dir/depend:
	cd /Users/apple/CLionProjects/firstCpp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/apple/CLionProjects/firstCpp /Users/apple/CLionProjects/firstCpp /Users/apple/CLionProjects/firstCpp/cmake-build-debug /Users/apple/CLionProjects/firstCpp/cmake-build-debug /Users/apple/CLionProjects/firstCpp/cmake-build-debug/CMakeFiles/string_mgr.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/string_mgr.dir/depend

