# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.2.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\yasir\Desktop\Proyectos UTN\utn-tp2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\yasir\Desktop\Proyectos UTN\utn-tp2\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/utn_tp2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/utn_tp2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/utn_tp2.dir/flags.make

CMakeFiles/utn_tp2.dir/functionsForProjects.c.obj: CMakeFiles/utn_tp2.dir/flags.make
CMakeFiles/utn_tp2.dir/functionsForProjects.c.obj: CMakeFiles/utn_tp2.dir/includes_C.rsp
CMakeFiles/utn_tp2.dir/functionsForProjects.c.obj: ../functionsForProjects.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\yasir\Desktop\Proyectos UTN\utn-tp2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/utn_tp2.dir/functionsForProjects.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\utn_tp2.dir\functionsForProjects.c.obj   -c "C:\Users\yasir\Desktop\Proyectos UTN\utn-tp2\functionsForProjects.c"

CMakeFiles/utn_tp2.dir/functionsForProjects.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/utn_tp2.dir/functionsForProjects.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\yasir\Desktop\Proyectos UTN\utn-tp2\functionsForProjects.c" > CMakeFiles\utn_tp2.dir\functionsForProjects.c.i

CMakeFiles/utn_tp2.dir/functionsForProjects.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/utn_tp2.dir/functionsForProjects.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\yasir\Desktop\Proyectos UTN\utn-tp2\functionsForProjects.c" -o CMakeFiles\utn_tp2.dir\functionsForProjects.c.s

CMakeFiles/utn_tp2.dir/main.c.obj: CMakeFiles/utn_tp2.dir/flags.make
CMakeFiles/utn_tp2.dir/main.c.obj: CMakeFiles/utn_tp2.dir/includes_C.rsp
CMakeFiles/utn_tp2.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\yasir\Desktop\Proyectos UTN\utn-tp2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/utn_tp2.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\utn_tp2.dir\main.c.obj   -c "C:\Users\yasir\Desktop\Proyectos UTN\utn-tp2\main.c"

CMakeFiles/utn_tp2.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/utn_tp2.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\yasir\Desktop\Proyectos UTN\utn-tp2\main.c" > CMakeFiles\utn_tp2.dir\main.c.i

CMakeFiles/utn_tp2.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/utn_tp2.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\yasir\Desktop\Proyectos UTN\utn-tp2\main.c" -o CMakeFiles\utn_tp2.dir\main.c.s

# Object files for target utn_tp2
utn_tp2_OBJECTS = \
"CMakeFiles/utn_tp2.dir/functionsForProjects.c.obj" \
"CMakeFiles/utn_tp2.dir/main.c.obj"

# External object files for target utn_tp2
utn_tp2_EXTERNAL_OBJECTS =

utn_tp2.exe: CMakeFiles/utn_tp2.dir/functionsForProjects.c.obj
utn_tp2.exe: CMakeFiles/utn_tp2.dir/main.c.obj
utn_tp2.exe: CMakeFiles/utn_tp2.dir/build.make
utn_tp2.exe: CMakeFiles/utn_tp2.dir/linklibs.rsp
utn_tp2.exe: CMakeFiles/utn_tp2.dir/objects1.rsp
utn_tp2.exe: CMakeFiles/utn_tp2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\yasir\Desktop\Proyectos UTN\utn-tp2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable utn_tp2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\utn_tp2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/utn_tp2.dir/build: utn_tp2.exe

.PHONY : CMakeFiles/utn_tp2.dir/build

CMakeFiles/utn_tp2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\utn_tp2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/utn_tp2.dir/clean

CMakeFiles/utn_tp2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\yasir\Desktop\Proyectos UTN\utn-tp2" "C:\Users\yasir\Desktop\Proyectos UTN\utn-tp2" "C:\Users\yasir\Desktop\Proyectos UTN\utn-tp2\cmake-build-debug" "C:\Users\yasir\Desktop\Proyectos UTN\utn-tp2\cmake-build-debug" "C:\Users\yasir\Desktop\Proyectos UTN\utn-tp2\cmake-build-debug\CMakeFiles\utn_tp2.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/utn_tp2.dir/depend

