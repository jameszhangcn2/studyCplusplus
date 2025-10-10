cmake_minimum_required(VERSION 3.10)

project(testSingleton)

set(CMAKE_CXX_STANDARD 14)

include_directories(inc)
#enable_testing()

#include_directories(src)
#include_directories(lib/googletest/include)

add_subdirectory(src)
#add_subdirectory(tst)
#add_subdirectory(lib/googletest)