cmake_minimum_required(VERSION 3.28)

# Set the project name and version
project(compiler VERSION 1.0)

# Specify the C++ standard (switching to C++20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable target, include only source files
add_executable(compiler main.cpp lexicalAnalyzer/lexicalAnalyzer.cpp
        testing/test.cpp
        syntaxAnalyzer/parser.h
        syntaxAnalyzer/syntaxAnalyzer.cpp
        main.cpp

)

# Optional: Include directories if needed (e.g., if you have headers in another directory)
# target_include_directories(compiler PUBLIC ${PROJECT_SOURCE_DIR}/include)
