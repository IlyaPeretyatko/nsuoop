# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/codespace/.local/lib/python3.10/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/codespace/.local/lib/python3.10/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /workspaces/nsuoop/task1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/nsuoop/task1

# Include any dependencies generated for this target.
include CMakeFiles/nsuoop-cpp-1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/nsuoop-cpp-1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/nsuoop-cpp-1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/nsuoop-cpp-1.dir/flags.make

CMakeFiles/nsuoop-cpp-1.dir/main.cpp.o: CMakeFiles/nsuoop-cpp-1.dir/flags.make
CMakeFiles/nsuoop-cpp-1.dir/main.cpp.o: main.cpp
CMakeFiles/nsuoop-cpp-1.dir/main.cpp.o: CMakeFiles/nsuoop-cpp-1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/workspaces/nsuoop/task1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/nsuoop-cpp-1.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/nsuoop-cpp-1.dir/main.cpp.o -MF CMakeFiles/nsuoop-cpp-1.dir/main.cpp.o.d -o CMakeFiles/nsuoop-cpp-1.dir/main.cpp.o -c /workspaces/nsuoop/task1/main.cpp

CMakeFiles/nsuoop-cpp-1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/nsuoop-cpp-1.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/nsuoop/task1/main.cpp > CMakeFiles/nsuoop-cpp-1.dir/main.cpp.i

CMakeFiles/nsuoop-cpp-1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/nsuoop-cpp-1.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/nsuoop/task1/main.cpp -o CMakeFiles/nsuoop-cpp-1.dir/main.cpp.s

# Object files for target nsuoop-cpp-1
nsuoop__cpp__1_OBJECTS = \
"CMakeFiles/nsuoop-cpp-1.dir/main.cpp.o"

# External object files for target nsuoop-cpp-1
nsuoop__cpp__1_EXTERNAL_OBJECTS = \
"/workspaces/nsuoop/task1/CMakeFiles/corelib.dir/module1.cpp.o" \
"/workspaces/nsuoop/task1/CMakeFiles/corelib.dir/module2.cpp.o"

nsuoop-cpp-1: CMakeFiles/nsuoop-cpp-1.dir/main.cpp.o
nsuoop-cpp-1: CMakeFiles/corelib.dir/module1.cpp.o
nsuoop-cpp-1: CMakeFiles/corelib.dir/module2.cpp.o
nsuoop-cpp-1: CMakeFiles/nsuoop-cpp-1.dir/build.make
nsuoop-cpp-1: CMakeFiles/nsuoop-cpp-1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/workspaces/nsuoop/task1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable nsuoop-cpp-1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/nsuoop-cpp-1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/nsuoop-cpp-1.dir/build: nsuoop-cpp-1
.PHONY : CMakeFiles/nsuoop-cpp-1.dir/build

CMakeFiles/nsuoop-cpp-1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/nsuoop-cpp-1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/nsuoop-cpp-1.dir/clean

CMakeFiles/nsuoop-cpp-1.dir/depend:
	cd /workspaces/nsuoop/task1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/nsuoop/task1 /workspaces/nsuoop/task1 /workspaces/nsuoop/task1 /workspaces/nsuoop/task1 /workspaces/nsuoop/task1/CMakeFiles/nsuoop-cpp-1.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/nsuoop-cpp-1.dir/depend

