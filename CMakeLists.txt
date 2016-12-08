cmake_minimum_required(VERSION 3.6)
set(BIN Delaunay-Tri)
project(${BIN})

set(CMAKE_CXX_STANDARD 11)
link_directories("freeglut")
include_directories("freeglut/include")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g3")

set(SOURCE_FILES main.cpp draw.cpp model.cpp)
add_executable(${BIN} ${SOURCE_FILES})

target_link_libraries(${BIN} libglut.a)
target_link_libraries(${BIN} GL X11 Xxf86vm Xrandr Xi)
