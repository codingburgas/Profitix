# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/cmake-build-debug-wsl

# Include any dependencies generated for this target.
include CMakeFiles/profitix.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/profitix.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/profitix.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/profitix.dir/flags.make

CMakeFiles/profitix.dir/main.cpp.o: CMakeFiles/profitix.dir/flags.make
CMakeFiles/profitix.dir/main.cpp.o: /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/main.cpp
CMakeFiles/profitix.dir/main.cpp.o: CMakeFiles/profitix.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/profitix.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/profitix.dir/main.cpp.o -MF CMakeFiles/profitix.dir/main.cpp.o.d -o CMakeFiles/profitix.dir/main.cpp.o -c /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/main.cpp

CMakeFiles/profitix.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/profitix.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/main.cpp > CMakeFiles/profitix.dir/main.cpp.i

CMakeFiles/profitix.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/profitix.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/main.cpp -o CMakeFiles/profitix.dir/main.cpp.s

CMakeFiles/profitix.dir/expense.cpp.o: CMakeFiles/profitix.dir/flags.make
CMakeFiles/profitix.dir/expense.cpp.o: /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/expense.cpp
CMakeFiles/profitix.dir/expense.cpp.o: CMakeFiles/profitix.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/profitix.dir/expense.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/profitix.dir/expense.cpp.o -MF CMakeFiles/profitix.dir/expense.cpp.o.d -o CMakeFiles/profitix.dir/expense.cpp.o -c /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/expense.cpp

CMakeFiles/profitix.dir/expense.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/profitix.dir/expense.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/expense.cpp > CMakeFiles/profitix.dir/expense.cpp.i

CMakeFiles/profitix.dir/expense.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/profitix.dir/expense.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/expense.cpp -o CMakeFiles/profitix.dir/expense.cpp.s

CMakeFiles/profitix.dir/report.cpp.o: CMakeFiles/profitix.dir/flags.make
CMakeFiles/profitix.dir/report.cpp.o: /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/report.cpp
CMakeFiles/profitix.dir/report.cpp.o: CMakeFiles/profitix.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/profitix.dir/report.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/profitix.dir/report.cpp.o -MF CMakeFiles/profitix.dir/report.cpp.o.d -o CMakeFiles/profitix.dir/report.cpp.o -c /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/report.cpp

CMakeFiles/profitix.dir/report.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/profitix.dir/report.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/report.cpp > CMakeFiles/profitix.dir/report.cpp.i

CMakeFiles/profitix.dir/report.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/profitix.dir/report.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/report.cpp -o CMakeFiles/profitix.dir/report.cpp.s

CMakeFiles/profitix.dir/user.cpp.o: CMakeFiles/profitix.dir/flags.make
CMakeFiles/profitix.dir/user.cpp.o: /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/user.cpp
CMakeFiles/profitix.dir/user.cpp.o: CMakeFiles/profitix.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/profitix.dir/user.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/profitix.dir/user.cpp.o -MF CMakeFiles/profitix.dir/user.cpp.o.d -o CMakeFiles/profitix.dir/user.cpp.o -c /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/user.cpp

CMakeFiles/profitix.dir/user.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/profitix.dir/user.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/user.cpp > CMakeFiles/profitix.dir/user.cpp.i

CMakeFiles/profitix.dir/user.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/profitix.dir/user.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/user.cpp -o CMakeFiles/profitix.dir/user.cpp.s

CMakeFiles/profitix.dir/income.cpp.o: CMakeFiles/profitix.dir/flags.make
CMakeFiles/profitix.dir/income.cpp.o: /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/income.cpp
CMakeFiles/profitix.dir/income.cpp.o: CMakeFiles/profitix.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/profitix.dir/income.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/profitix.dir/income.cpp.o -MF CMakeFiles/profitix.dir/income.cpp.o.d -o CMakeFiles/profitix.dir/income.cpp.o -c /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/income.cpp

CMakeFiles/profitix.dir/income.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/profitix.dir/income.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/income.cpp > CMakeFiles/profitix.dir/income.cpp.i

CMakeFiles/profitix.dir/income.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/profitix.dir/income.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/income.cpp -o CMakeFiles/profitix.dir/income.cpp.s

CMakeFiles/profitix.dir/clearScreen.cpp.o: CMakeFiles/profitix.dir/flags.make
CMakeFiles/profitix.dir/clearScreen.cpp.o: /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/clearScreen.cpp
CMakeFiles/profitix.dir/clearScreen.cpp.o: CMakeFiles/profitix.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/profitix.dir/clearScreen.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/profitix.dir/clearScreen.cpp.o -MF CMakeFiles/profitix.dir/clearScreen.cpp.o.d -o CMakeFiles/profitix.dir/clearScreen.cpp.o -c /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/clearScreen.cpp

CMakeFiles/profitix.dir/clearScreen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/profitix.dir/clearScreen.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/clearScreen.cpp > CMakeFiles/profitix.dir/clearScreen.cpp.i

CMakeFiles/profitix.dir/clearScreen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/profitix.dir/clearScreen.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/clearScreen.cpp -o CMakeFiles/profitix.dir/clearScreen.cpp.s

CMakeFiles/profitix.dir/mainMenu.cpp.o: CMakeFiles/profitix.dir/flags.make
CMakeFiles/profitix.dir/mainMenu.cpp.o: /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/mainMenu.cpp
CMakeFiles/profitix.dir/mainMenu.cpp.o: CMakeFiles/profitix.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/profitix.dir/mainMenu.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/profitix.dir/mainMenu.cpp.o -MF CMakeFiles/profitix.dir/mainMenu.cpp.o.d -o CMakeFiles/profitix.dir/mainMenu.cpp.o -c /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/mainMenu.cpp

CMakeFiles/profitix.dir/mainMenu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/profitix.dir/mainMenu.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/mainMenu.cpp > CMakeFiles/profitix.dir/mainMenu.cpp.i

CMakeFiles/profitix.dir/mainMenu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/profitix.dir/mainMenu.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/mainMenu.cpp -o CMakeFiles/profitix.dir/mainMenu.cpp.s

CMakeFiles/profitix.dir/dashboard.cpp.o: CMakeFiles/profitix.dir/flags.make
CMakeFiles/profitix.dir/dashboard.cpp.o: /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/dashboard.cpp
CMakeFiles/profitix.dir/dashboard.cpp.o: CMakeFiles/profitix.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/profitix.dir/dashboard.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/profitix.dir/dashboard.cpp.o -MF CMakeFiles/profitix.dir/dashboard.cpp.o.d -o CMakeFiles/profitix.dir/dashboard.cpp.o -c /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/dashboard.cpp

CMakeFiles/profitix.dir/dashboard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/profitix.dir/dashboard.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/dashboard.cpp > CMakeFiles/profitix.dir/dashboard.cpp.i

CMakeFiles/profitix.dir/dashboard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/profitix.dir/dashboard.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/dashboard.cpp -o CMakeFiles/profitix.dir/dashboard.cpp.s

CMakeFiles/profitix.dir/budget.cpp.o: CMakeFiles/profitix.dir/flags.make
CMakeFiles/profitix.dir/budget.cpp.o: /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/budget.cpp
CMakeFiles/profitix.dir/budget.cpp.o: CMakeFiles/profitix.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/profitix.dir/budget.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/profitix.dir/budget.cpp.o -MF CMakeFiles/profitix.dir/budget.cpp.o.d -o CMakeFiles/profitix.dir/budget.cpp.o -c /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/budget.cpp

CMakeFiles/profitix.dir/budget.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/profitix.dir/budget.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/budget.cpp > CMakeFiles/profitix.dir/budget.cpp.i

CMakeFiles/profitix.dir/budget.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/profitix.dir/budget.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/budget.cpp -o CMakeFiles/profitix.dir/budget.cpp.s

# Object files for target profitix
profitix_OBJECTS = \
"CMakeFiles/profitix.dir/main.cpp.o" \
"CMakeFiles/profitix.dir/expense.cpp.o" \
"CMakeFiles/profitix.dir/report.cpp.o" \
"CMakeFiles/profitix.dir/user.cpp.o" \
"CMakeFiles/profitix.dir/income.cpp.o" \
"CMakeFiles/profitix.dir/clearScreen.cpp.o" \
"CMakeFiles/profitix.dir/mainMenu.cpp.o" \
"CMakeFiles/profitix.dir/dashboard.cpp.o" \
"CMakeFiles/profitix.dir/budget.cpp.o"

# External object files for target profitix
profitix_EXTERNAL_OBJECTS =

profitix: CMakeFiles/profitix.dir/main.cpp.o
profitix: CMakeFiles/profitix.dir/expense.cpp.o
profitix: CMakeFiles/profitix.dir/report.cpp.o
profitix: CMakeFiles/profitix.dir/user.cpp.o
profitix: CMakeFiles/profitix.dir/income.cpp.o
profitix: CMakeFiles/profitix.dir/clearScreen.cpp.o
profitix: CMakeFiles/profitix.dir/mainMenu.cpp.o
profitix: CMakeFiles/profitix.dir/dashboard.cpp.o
profitix: CMakeFiles/profitix.dir/budget.cpp.o
profitix: CMakeFiles/profitix.dir/build.make
profitix: CMakeFiles/profitix.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable profitix"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/profitix.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/profitix.dir/build: profitix
.PHONY : CMakeFiles/profitix.dir/build

CMakeFiles/profitix.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/profitix.dir/cmake_clean.cmake
.PHONY : CMakeFiles/profitix.dir/clean

CMakeFiles/profitix.dir/depend:
	cd /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/cmake-build-debug-wsl && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/cmake-build-debug-wsl /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/cmake-build-debug-wsl /mnt/c/Users/yuant/CLionProjects/finance-challenge-profitix/profitix/cmake-build-debug-wsl/CMakeFiles/profitix.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/profitix.dir/depend

