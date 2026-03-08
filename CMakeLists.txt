cmake_minimum_required(VERSION 3.16)

project(robosim LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(raylib REQUIRED)

add_executable(robotsim src/main.cpp src/shape.cpp src/sphere.cpp src/box.cpp src/cylinder.cpp)
target_link_libraries(robotsim PRIVATE raylib)