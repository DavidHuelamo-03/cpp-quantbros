cmake_minimum_required(VERSION 3.14)
project(QuantBros CXX)

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(include tests)

# Gather all source files automatically
file(GLOB SRC_FILES "src/*.cpp")

# Exclude main.cpp from tests library so main() doesn't conflict
list(REMOVE_ITEM SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")

# Main Executable
add_executable(quant_main src/main.cpp ${SRC_FILES})

# Test Executable
add_executable(run_tests tests/test_mc_pricer.cpp ${SRC_FILES})

add_executable(test_StandardShockGenerator 
    tests/test_StandardShockGenerator.cpp 
    src/StandardShockGenerator.cpp
)