# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jovyan/CSPB2270/skip-list-project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jovyan/CSPB2270/skip-list-project/build

# Include any dependencies generated for this target.
include CMakeFiles/run_tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/run_tests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/run_tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/run_tests.dir/flags.make

CMakeFiles/run_tests.dir/tests/test_code.cpp.o: CMakeFiles/run_tests.dir/flags.make
CMakeFiles/run_tests.dir/tests/test_code.cpp.o: ../tests/test_code.cpp
CMakeFiles/run_tests.dir/tests/test_code.cpp.o: CMakeFiles/run_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jovyan/CSPB2270/skip-list-project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/run_tests.dir/tests/test_code.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/run_tests.dir/tests/test_code.cpp.o -MF CMakeFiles/run_tests.dir/tests/test_code.cpp.o.d -o CMakeFiles/run_tests.dir/tests/test_code.cpp.o -c /home/jovyan/CSPB2270/skip-list-project/tests/test_code.cpp

CMakeFiles/run_tests.dir/tests/test_code.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run_tests.dir/tests/test_code.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jovyan/CSPB2270/skip-list-project/tests/test_code.cpp > CMakeFiles/run_tests.dir/tests/test_code.cpp.i

CMakeFiles/run_tests.dir/tests/test_code.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run_tests.dir/tests/test_code.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jovyan/CSPB2270/skip-list-project/tests/test_code.cpp -o CMakeFiles/run_tests.dir/tests/test_code.cpp.s

CMakeFiles/run_tests.dir/code/Node.cpp.o: CMakeFiles/run_tests.dir/flags.make
CMakeFiles/run_tests.dir/code/Node.cpp.o: ../code/Node.cpp
CMakeFiles/run_tests.dir/code/Node.cpp.o: CMakeFiles/run_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jovyan/CSPB2270/skip-list-project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/run_tests.dir/code/Node.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/run_tests.dir/code/Node.cpp.o -MF CMakeFiles/run_tests.dir/code/Node.cpp.o.d -o CMakeFiles/run_tests.dir/code/Node.cpp.o -c /home/jovyan/CSPB2270/skip-list-project/code/Node.cpp

CMakeFiles/run_tests.dir/code/Node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run_tests.dir/code/Node.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jovyan/CSPB2270/skip-list-project/code/Node.cpp > CMakeFiles/run_tests.dir/code/Node.cpp.i

CMakeFiles/run_tests.dir/code/Node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run_tests.dir/code/Node.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jovyan/CSPB2270/skip-list-project/code/Node.cpp -o CMakeFiles/run_tests.dir/code/Node.cpp.s

CMakeFiles/run_tests.dir/code/SkipList.cpp.o: CMakeFiles/run_tests.dir/flags.make
CMakeFiles/run_tests.dir/code/SkipList.cpp.o: ../code/SkipList.cpp
CMakeFiles/run_tests.dir/code/SkipList.cpp.o: CMakeFiles/run_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jovyan/CSPB2270/skip-list-project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/run_tests.dir/code/SkipList.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/run_tests.dir/code/SkipList.cpp.o -MF CMakeFiles/run_tests.dir/code/SkipList.cpp.o.d -o CMakeFiles/run_tests.dir/code/SkipList.cpp.o -c /home/jovyan/CSPB2270/skip-list-project/code/SkipList.cpp

CMakeFiles/run_tests.dir/code/SkipList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run_tests.dir/code/SkipList.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jovyan/CSPB2270/skip-list-project/code/SkipList.cpp > CMakeFiles/run_tests.dir/code/SkipList.cpp.i

CMakeFiles/run_tests.dir/code/SkipList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run_tests.dir/code/SkipList.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jovyan/CSPB2270/skip-list-project/code/SkipList.cpp -o CMakeFiles/run_tests.dir/code/SkipList.cpp.s

# Object files for target run_tests
run_tests_OBJECTS = \
"CMakeFiles/run_tests.dir/tests/test_code.cpp.o" \
"CMakeFiles/run_tests.dir/code/Node.cpp.o" \
"CMakeFiles/run_tests.dir/code/SkipList.cpp.o"

# External object files for target run_tests
run_tests_EXTERNAL_OBJECTS =

run_tests: CMakeFiles/run_tests.dir/tests/test_code.cpp.o
run_tests: CMakeFiles/run_tests.dir/code/Node.cpp.o
run_tests: CMakeFiles/run_tests.dir/code/SkipList.cpp.o
run_tests: CMakeFiles/run_tests.dir/build.make
run_tests: /usr/lib/x86_64-linux-gnu/libgtest.a
run_tests: CMakeFiles/run_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jovyan/CSPB2270/skip-list-project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable run_tests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/run_tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/run_tests.dir/build: run_tests
.PHONY : CMakeFiles/run_tests.dir/build

CMakeFiles/run_tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/run_tests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/run_tests.dir/clean

CMakeFiles/run_tests.dir/depend:
	cd /home/jovyan/CSPB2270/skip-list-project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jovyan/CSPB2270/skip-list-project /home/jovyan/CSPB2270/skip-list-project /home/jovyan/CSPB2270/skip-list-project/build /home/jovyan/CSPB2270/skip-list-project/build /home/jovyan/CSPB2270/skip-list-project/build/CMakeFiles/run_tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/run_tests.dir/depend
