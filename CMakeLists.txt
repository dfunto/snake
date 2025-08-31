cmake_minimum_required(VERSION 3.15)
project(Snake)

set(CMAKE_CXX_STANDARD 17)

# Find SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(Snake main.cpp)

target_link_libraries(Snake ${SDL2_LIBRARIES} "-framework OpenGL -Wdeprecated-declarations")
