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
CMAKE_SOURCE_DIR = /home/frenzy/cpp/quarter_one/last_lesson/last_lesson

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/frenzy/cpp/quarter_one/last_lesson/build-last_lesson-Desktop-Debug

# Include any dependencies generated for this target.
include CMakeFiles/SDL2Test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SDL2Test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SDL2Test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SDL2Test.dir/flags.make

CMakeFiles/SDL2Test.dir/main.cpp.o: CMakeFiles/SDL2Test.dir/flags.make
CMakeFiles/SDL2Test.dir/main.cpp.o: /home/frenzy/cpp/quarter_one/last_lesson/last_lesson/main.cpp
CMakeFiles/SDL2Test.dir/main.cpp.o: CMakeFiles/SDL2Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/frenzy/cpp/quarter_one/last_lesson/build-last_lesson-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SDL2Test.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SDL2Test.dir/main.cpp.o -MF CMakeFiles/SDL2Test.dir/main.cpp.o.d -o CMakeFiles/SDL2Test.dir/main.cpp.o -c /home/frenzy/cpp/quarter_one/last_lesson/last_lesson/main.cpp

CMakeFiles/SDL2Test.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SDL2Test.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/frenzy/cpp/quarter_one/last_lesson/last_lesson/main.cpp > CMakeFiles/SDL2Test.dir/main.cpp.i

CMakeFiles/SDL2Test.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SDL2Test.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/frenzy/cpp/quarter_one/last_lesson/last_lesson/main.cpp -o CMakeFiles/SDL2Test.dir/main.cpp.s

CMakeFiles/SDL2Test.dir/sdl2.cpp.o: CMakeFiles/SDL2Test.dir/flags.make
CMakeFiles/SDL2Test.dir/sdl2.cpp.o: /home/frenzy/cpp/quarter_one/last_lesson/last_lesson/sdl2.cpp
CMakeFiles/SDL2Test.dir/sdl2.cpp.o: CMakeFiles/SDL2Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/frenzy/cpp/quarter_one/last_lesson/build-last_lesson-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SDL2Test.dir/sdl2.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SDL2Test.dir/sdl2.cpp.o -MF CMakeFiles/SDL2Test.dir/sdl2.cpp.o.d -o CMakeFiles/SDL2Test.dir/sdl2.cpp.o -c /home/frenzy/cpp/quarter_one/last_lesson/last_lesson/sdl2.cpp

CMakeFiles/SDL2Test.dir/sdl2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SDL2Test.dir/sdl2.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/frenzy/cpp/quarter_one/last_lesson/last_lesson/sdl2.cpp > CMakeFiles/SDL2Test.dir/sdl2.cpp.i

CMakeFiles/SDL2Test.dir/sdl2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SDL2Test.dir/sdl2.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/frenzy/cpp/quarter_one/last_lesson/last_lesson/sdl2.cpp -o CMakeFiles/SDL2Test.dir/sdl2.cpp.s

CMakeFiles/SDL2Test.dir/colour.cpp.o: CMakeFiles/SDL2Test.dir/flags.make
CMakeFiles/SDL2Test.dir/colour.cpp.o: /home/frenzy/cpp/quarter_one/last_lesson/last_lesson/colour.cpp
CMakeFiles/SDL2Test.dir/colour.cpp.o: CMakeFiles/SDL2Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/frenzy/cpp/quarter_one/last_lesson/build-last_lesson-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SDL2Test.dir/colour.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SDL2Test.dir/colour.cpp.o -MF CMakeFiles/SDL2Test.dir/colour.cpp.o.d -o CMakeFiles/SDL2Test.dir/colour.cpp.o -c /home/frenzy/cpp/quarter_one/last_lesson/last_lesson/colour.cpp

CMakeFiles/SDL2Test.dir/colour.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SDL2Test.dir/colour.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/frenzy/cpp/quarter_one/last_lesson/last_lesson/colour.cpp > CMakeFiles/SDL2Test.dir/colour.cpp.i

CMakeFiles/SDL2Test.dir/colour.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SDL2Test.dir/colour.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/frenzy/cpp/quarter_one/last_lesson/last_lesson/colour.cpp -o CMakeFiles/SDL2Test.dir/colour.cpp.s

CMakeFiles/SDL2Test.dir/game.cpp.o: CMakeFiles/SDL2Test.dir/flags.make
CMakeFiles/SDL2Test.dir/game.cpp.o: /home/frenzy/cpp/quarter_one/last_lesson/last_lesson/game.cpp
CMakeFiles/SDL2Test.dir/game.cpp.o: CMakeFiles/SDL2Test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/frenzy/cpp/quarter_one/last_lesson/build-last_lesson-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SDL2Test.dir/game.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SDL2Test.dir/game.cpp.o -MF CMakeFiles/SDL2Test.dir/game.cpp.o.d -o CMakeFiles/SDL2Test.dir/game.cpp.o -c /home/frenzy/cpp/quarter_one/last_lesson/last_lesson/game.cpp

CMakeFiles/SDL2Test.dir/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SDL2Test.dir/game.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/frenzy/cpp/quarter_one/last_lesson/last_lesson/game.cpp > CMakeFiles/SDL2Test.dir/game.cpp.i

CMakeFiles/SDL2Test.dir/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SDL2Test.dir/game.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/frenzy/cpp/quarter_one/last_lesson/last_lesson/game.cpp -o CMakeFiles/SDL2Test.dir/game.cpp.s

# Object files for target SDL2Test
SDL2Test_OBJECTS = \
"CMakeFiles/SDL2Test.dir/main.cpp.o" \
"CMakeFiles/SDL2Test.dir/sdl2.cpp.o" \
"CMakeFiles/SDL2Test.dir/colour.cpp.o" \
"CMakeFiles/SDL2Test.dir/game.cpp.o"

# External object files for target SDL2Test
SDL2Test_EXTERNAL_OBJECTS =

SDL2Test: CMakeFiles/SDL2Test.dir/main.cpp.o
SDL2Test: CMakeFiles/SDL2Test.dir/sdl2.cpp.o
SDL2Test: CMakeFiles/SDL2Test.dir/colour.cpp.o
SDL2Test: CMakeFiles/SDL2Test.dir/game.cpp.o
SDL2Test: CMakeFiles/SDL2Test.dir/build.make
SDL2Test: /usr/lib64/libSDL2main.a
SDL2Test: /usr/lib64/libSDL2-2.0.so.0.22.0
SDL2Test: /usr/lib64/libSDL2_mixer.so
SDL2Test: /usr/lib64/libSDL2_image.so
SDL2Test: /usr/lib64/libSDL2.so
SDL2Test: CMakeFiles/SDL2Test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/frenzy/cpp/quarter_one/last_lesson/build-last_lesson-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable SDL2Test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SDL2Test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SDL2Test.dir/build: SDL2Test
.PHONY : CMakeFiles/SDL2Test.dir/build

CMakeFiles/SDL2Test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SDL2Test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SDL2Test.dir/clean

CMakeFiles/SDL2Test.dir/depend:
	cd /home/frenzy/cpp/quarter_one/last_lesson/build-last_lesson-Desktop-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/frenzy/cpp/quarter_one/last_lesson/last_lesson /home/frenzy/cpp/quarter_one/last_lesson/last_lesson /home/frenzy/cpp/quarter_one/last_lesson/build-last_lesson-Desktop-Debug /home/frenzy/cpp/quarter_one/last_lesson/build-last_lesson-Desktop-Debug /home/frenzy/cpp/quarter_one/last_lesson/build-last_lesson-Desktop-Debug/CMakeFiles/SDL2Test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SDL2Test.dir/depend

