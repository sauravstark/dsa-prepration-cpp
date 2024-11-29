cmake_minimum_required(VERSION 3.29)
project(DSA)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 23)

# Enable testing
enable_testing()

# Add the external googletest submodule
add_subdirectory(external/googletest)

# Include directories for googletest and other headers
include_directories(
        include
        ${gtest_SOURCE_DIR}/include
        ${gmock_SOURCE_DIR}/include
)

# Gather all .cpp files for the library from the 'src' directory
file(GLOB LIBRARY_SOURCES
        "src/library/leetcode/*.cpp"
        "src/library/leetcode/datatype/*.cpp"
        "src/library/codefores/*.cpp"
        "src/library/util/*.cpp"
)

# Gather all .cpp files for the tests from the 'tests' directory
file(GLOB TEST_SOURCES
        "src/tests/codefores/*.cpp"
        "src/tests/codefores/util/*.cpp"
        "src/tests/leetcode/*.cpp"
        "src/tests/leetcode/util/*.cpp"
        "src/tests/util/*.cpp"
)

# Create a static library 'DSA' from the source files
add_library(DSA ${LIBRARY_SOURCES})

# Create an executable for running tests
add_executable(RunAllTests ${TEST_SOURCES})

# Link the 'RunAllTests' executable with the necessary libraries
target_link_libraries(RunAllTests PRIVATE DSA gtest gmock gtest_main)

# Add tests to CTest
add_test(NAME RunAllTests COMMAND RunAllTests)

# Copy test cases from the external 'dsa-testcases' folder to the build directory
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/testcases)
file(COPY ${CMAKE_SOURCE_DIR}/external/dsa-testcases/
        DESTINATION ${CMAKE_BINARY_DIR}/testcases
        FILES_MATCHING PATTERN "*")
