cmake_minimum_required(VERSION 3.13)
project(cyan)

set(CYAN_LIB cyan)
file(GLOB CYAN_SOURCES cyan/src/*.cpp)
set(CMAKE_CXX_STANDARD 14)
add_library(${CYAN_LIB} STATIC ${CYAN_SOURCES})
target_include_directories(${CYAN_LIB} PUBLIC cyan/include)

set(EXAMPLE_APP example)
add_executable(${EXAMPLE_APP} src/main.cpp)
target_include_directories(${EXAMPLE_APP} PUBLIC cyan/include)
target_link_libraries(example ${CYAN_LIB})
