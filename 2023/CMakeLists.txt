cmake_minimum_required(VERSION 3.22.1)
project(AdventOfCode2023 VERSION 0.1.0)

# Set C++17 standard
set(CMAKE_CXX_STANDARD 17)

# Main source
set(SOURCES
    src/main.cpp src/main.hpp
    src/terminal/terminal.cpp src/terminal/terminal.hpp
)

# Advent of Code (day modules)
set(NUM_DAY_MODULES 2)
foreach(MODULE_ID RANGE 1 ${NUM_DAY_MODULES})
    set(MODULE_NAME day${MODULE_ID})
    
    set(SOURCES_${MODULE_NAME}
        src/${MODULE_NAME}/${MODULE_NAME}.cpp
        src/${MODULE_NAME}/${MODULE_NAME}.hpp
    )

    list(APPEND SOURCES ${SOURCES_${MODULE_NAME}})
endforeach()

# Create executeable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link ncurses lib
find_package(Curses REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE ${CURSES_LIBRARIES})

# Clean up build folder
add_custom_target(clean_target
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}
    COMMENT "Clean build directory"
)

# Build Advent of Code 2023
add_custom_target(build
    COMMAND ${CMAKE_COMMAND} -S ${CMAKE_SOURCE_DIR} -B ${CMAKE_BINARY_DIR}
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR}
    COMMENT "Build project"
)

# Run Advent of Code 2023
add_custom_target(run
    COMMAND ${CMAKE_BINARY_DIR}/AdventOfCode2023
    DEPENDS build
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Run Advent of Code 2023 (version ${PROJECT_VERSION})"
)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()
