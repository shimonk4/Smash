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
CMAKE_COMMAND = "/cygdrive/c/Users/Shimon Korkus/.CLion2018.1/system/cygwin_cmake/bin/cmake.exe"

# The command to remove a file.
RM = "/cygdrive/c/Users/Shimon Korkus/.CLion2018.1/system/cygwin_cmake/bin/cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/CSProjects/Smash/Smash/Smash

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/CSProjects/Smash/Smash/Smash/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Smash.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Smash.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Smash.dir/flags.make

CMakeFiles/Smash.dir/main.cpp.o: CMakeFiles/Smash.dir/flags.make
CMakeFiles/Smash.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/CSProjects/Smash/Smash/Smash/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Smash.dir/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Smash.dir/main.cpp.o -c /cygdrive/c/CSProjects/Smash/Smash/Smash/main.cpp

CMakeFiles/Smash.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Smash.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/CSProjects/Smash/Smash/Smash/main.cpp > CMakeFiles/Smash.dir/main.cpp.i

CMakeFiles/Smash.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Smash.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/CSProjects/Smash/Smash/Smash/main.cpp -o CMakeFiles/Smash.dir/main.cpp.s

CMakeFiles/Smash.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Smash.dir/main.cpp.o.requires

CMakeFiles/Smash.dir/main.cpp.o.provides: CMakeFiles/Smash.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Smash.dir/build.make CMakeFiles/Smash.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Smash.dir/main.cpp.o.provides

CMakeFiles/Smash.dir/main.cpp.o.provides.build: CMakeFiles/Smash.dir/main.cpp.o


CMakeFiles/Smash.dir/Commands.cpp.o: CMakeFiles/Smash.dir/flags.make
CMakeFiles/Smash.dir/Commands.cpp.o: ../Commands.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/CSProjects/Smash/Smash/Smash/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Smash.dir/Commands.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Smash.dir/Commands.cpp.o -c /cygdrive/c/CSProjects/Smash/Smash/Smash/Commands.cpp

CMakeFiles/Smash.dir/Commands.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Smash.dir/Commands.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/CSProjects/Smash/Smash/Smash/Commands.cpp > CMakeFiles/Smash.dir/Commands.cpp.i

CMakeFiles/Smash.dir/Commands.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Smash.dir/Commands.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/CSProjects/Smash/Smash/Smash/Commands.cpp -o CMakeFiles/Smash.dir/Commands.cpp.s

CMakeFiles/Smash.dir/Commands.cpp.o.requires:

.PHONY : CMakeFiles/Smash.dir/Commands.cpp.o.requires

CMakeFiles/Smash.dir/Commands.cpp.o.provides: CMakeFiles/Smash.dir/Commands.cpp.o.requires
	$(MAKE) -f CMakeFiles/Smash.dir/build.make CMakeFiles/Smash.dir/Commands.cpp.o.provides.build
.PHONY : CMakeFiles/Smash.dir/Commands.cpp.o.provides

CMakeFiles/Smash.dir/Commands.cpp.o.provides.build: CMakeFiles/Smash.dir/Commands.cpp.o


CMakeFiles/Smash.dir/signals.cpp.o: CMakeFiles/Smash.dir/flags.make
CMakeFiles/Smash.dir/signals.cpp.o: ../signals.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/CSProjects/Smash/Smash/Smash/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Smash.dir/signals.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Smash.dir/signals.cpp.o -c /cygdrive/c/CSProjects/Smash/Smash/Smash/signals.cpp

CMakeFiles/Smash.dir/signals.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Smash.dir/signals.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/CSProjects/Smash/Smash/Smash/signals.cpp > CMakeFiles/Smash.dir/signals.cpp.i

CMakeFiles/Smash.dir/signals.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Smash.dir/signals.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/CSProjects/Smash/Smash/Smash/signals.cpp -o CMakeFiles/Smash.dir/signals.cpp.s

CMakeFiles/Smash.dir/signals.cpp.o.requires:

.PHONY : CMakeFiles/Smash.dir/signals.cpp.o.requires

CMakeFiles/Smash.dir/signals.cpp.o.provides: CMakeFiles/Smash.dir/signals.cpp.o.requires
	$(MAKE) -f CMakeFiles/Smash.dir/build.make CMakeFiles/Smash.dir/signals.cpp.o.provides.build
.PHONY : CMakeFiles/Smash.dir/signals.cpp.o.provides

CMakeFiles/Smash.dir/signals.cpp.o.provides.build: CMakeFiles/Smash.dir/signals.cpp.o


# Object files for target Smash
Smash_OBJECTS = \
"CMakeFiles/Smash.dir/main.cpp.o" \
"CMakeFiles/Smash.dir/Commands.cpp.o" \
"CMakeFiles/Smash.dir/signals.cpp.o"

# External object files for target Smash
Smash_EXTERNAL_OBJECTS =

Smash.exe: CMakeFiles/Smash.dir/main.cpp.o
Smash.exe: CMakeFiles/Smash.dir/Commands.cpp.o
Smash.exe: CMakeFiles/Smash.dir/signals.cpp.o
Smash.exe: CMakeFiles/Smash.dir/build.make
Smash.exe: CMakeFiles/Smash.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/CSProjects/Smash/Smash/Smash/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Smash.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Smash.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Smash.dir/build: Smash.exe

.PHONY : CMakeFiles/Smash.dir/build

CMakeFiles/Smash.dir/requires: CMakeFiles/Smash.dir/main.cpp.o.requires
CMakeFiles/Smash.dir/requires: CMakeFiles/Smash.dir/Commands.cpp.o.requires
CMakeFiles/Smash.dir/requires: CMakeFiles/Smash.dir/signals.cpp.o.requires

.PHONY : CMakeFiles/Smash.dir/requires

CMakeFiles/Smash.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Smash.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Smash.dir/clean

CMakeFiles/Smash.dir/depend:
	cd /cygdrive/c/CSProjects/Smash/Smash/Smash/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/CSProjects/Smash/Smash/Smash /cygdrive/c/CSProjects/Smash/Smash/Smash /cygdrive/c/CSProjects/Smash/Smash/Smash/cmake-build-debug /cygdrive/c/CSProjects/Smash/Smash/Smash/cmake-build-debug /cygdrive/c/CSProjects/Smash/Smash/Smash/cmake-build-debug/CMakeFiles/Smash.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Smash.dir/depend

