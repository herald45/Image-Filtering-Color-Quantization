# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/herald/Desktop/COURS/L3/S6/Computer Graphics/CG1_25L_01204477_Proj1-2/Project2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/herald/Desktop/COURS/L3/S6/Computer Graphics/CG1_25L_01204477_Proj1-2/Project2/build"

# Utility rule file for app_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/app_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/app_autogen.dir/progress.make

CMakeFiles/app_autogen: app_autogen/timestamp

app_autogen/timestamp: /opt/homebrew/share/qt/libexec/moc
app_autogen/timestamp: /opt/homebrew/share/qt/libexec/uic
app_autogen/timestamp: CMakeFiles/app_autogen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir="/Users/herald/Desktop/COURS/L3/S6/Computer Graphics/CG1_25L_01204477_Proj1-2/Project2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target app"
	/opt/homebrew/bin/cmake -E cmake_autogen "/Users/herald/Desktop/COURS/L3/S6/Computer Graphics/CG1_25L_01204477_Proj1-2/Project2/build/CMakeFiles/app_autogen.dir/AutogenInfo.json" ""
	/opt/homebrew/bin/cmake -E touch "/Users/herald/Desktop/COURS/L3/S6/Computer Graphics/CG1_25L_01204477_Proj1-2/Project2/build/app_autogen/timestamp"

CMakeFiles/app_autogen.dir/codegen:
.PHONY : CMakeFiles/app_autogen.dir/codegen

app_autogen: CMakeFiles/app_autogen
app_autogen: app_autogen/timestamp
app_autogen: CMakeFiles/app_autogen.dir/build.make
.PHONY : app_autogen

# Rule to build all files generated by this target.
CMakeFiles/app_autogen.dir/build: app_autogen
.PHONY : CMakeFiles/app_autogen.dir/build

CMakeFiles/app_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/app_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/app_autogen.dir/clean

CMakeFiles/app_autogen.dir/depend:
	cd "/Users/herald/Desktop/COURS/L3/S6/Computer Graphics/CG1_25L_01204477_Proj1-2/Project2/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/herald/Desktop/COURS/L3/S6/Computer Graphics/CG1_25L_01204477_Proj1-2/Project2" "/Users/herald/Desktop/COURS/L3/S6/Computer Graphics/CG1_25L_01204477_Proj1-2/Project2" "/Users/herald/Desktop/COURS/L3/S6/Computer Graphics/CG1_25L_01204477_Proj1-2/Project2/build" "/Users/herald/Desktop/COURS/L3/S6/Computer Graphics/CG1_25L_01204477_Proj1-2/Project2/build" "/Users/herald/Desktop/COURS/L3/S6/Computer Graphics/CG1_25L_01204477_Proj1-2/Project2/build/CMakeFiles/app_autogen.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/app_autogen.dir/depend

