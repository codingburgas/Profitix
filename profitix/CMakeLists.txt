# CMakeList.txt : CMake project for profitix, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

# Set source files for project

set(SOURCES
	    main.cpp
        precompiler.h
        expense.cpp
        report.cpp
        user.cpp
        income.cpp
        clearScreen.h
        clearScreen.cpp
        mainMenu.cpp
        mainMenu.h
        globals.h
        dashboard.cpp
        dashboard.h
        budget.cpp
        budget.h
        expense.h
)

project ("profitix")

# Add source to this project's executable.
add_executable (profitix ${SOURCES}
        budget.cpp
        budget.h
        expense.h)

# Someone please fucking peg me.
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET profitix PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
