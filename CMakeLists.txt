cmake_minimum_required(VERSION 3.10)

project(snake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

find_package(Curses REQUIRED)

set(LIBRARY_OUTPUT_PATH build/)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_subdirectory(Source)
include_directories(Include)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(snake ${SOURCE_FILES})
target_link_libraries(snake ${CURSES_LIBRARIES})