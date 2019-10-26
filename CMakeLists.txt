cmake_minimum_required(VERSION 3.9)
project(Number1)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(googletest-master)

include_directories(googletest-master/googletest/include)

add_executable(Number1 main.cpp Vector.h Base.h Matrix.h Matrix.cpp Vector.cpp)

target_link_libraries(Number1 gtest)