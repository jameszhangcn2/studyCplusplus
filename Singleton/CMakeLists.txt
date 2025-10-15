cmake_minimum_required(VERSION 3.20)

project(testSingleton)

set(CMAKE_CXX_STANDARD 14)
set(GOOGLETEST_VERSION 1.17.0)


enable_testing()

OPTION(ENABLE_GCOV "Enable gcov" OFF)

IF (ENABLE_GCOV AND NOT WIN32 AND NOT APPLE)
    SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fprofile-arcs -ftest-coverage")
    SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -fprofile-arcs -ftest-coverage")
    SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -fprofile-arcs -ftest-coverage -lgcov")
ENDIF()

include_directories(inc)
include_directories(lib/googletest-1.17.0/googletest/include)

add_subdirectory(src)
add_subdirectory(tst)
add_subdirectory(lib/googletest-1.17.0/googletest)