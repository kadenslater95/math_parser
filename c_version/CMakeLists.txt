cmake_minimum_required(VERSION 3.14)
project(math_parser)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
  main
  main.c
)

include_directories(src/include)

target_link_libraries(main math_parser)

add_subdirectory(src)
add_subdirectory(test)
