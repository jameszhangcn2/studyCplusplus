cmake_minimum_required(VERSION 3.20)

project(testSingleton)

set(CMAKE_CXX_STANDARD 14)
set(GOOGLETEST_VERSION 1.17.0)

include_directories(inc)
enable_testing()

include_directories(lib/googletest-1.17.0/googletest/include)

add_subdirectory(src)
add_subdirectory(tst)
add_subdirectory(lib/googletest-1.17.0/googletest)