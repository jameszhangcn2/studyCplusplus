cmake_minimum_required(VERSION 3.20)
project(Hello)
# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/static_libs)
set (EXECUTABLE_OUTPUT_PATH $(PROJECT_SOURCE_DIR)/bin)

set(SOURCES 
    src/main.cpp
    src/hello_world.cpp 
    )
include_directories(include)
add_library(hello_library STATIC 
    src/hello_world.cpp 
)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(HELLO src/main.cpp)

target_include_directories( HELLO
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries( HELLO
    PRIVATE
        ${PROJECT_SOURCE_DIR}/static_libs/libhello_library.a
)

target_include_directories( HELLO
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

enable_testing()
add_executable(TEST test/test.cpp)

target_link_libraries( TEST
    GTest::gtest_main
    #PRIVATE
    ${PROJECT_SOURCE_DIR}/static_libs/libhello_library.a
)
include(GoogleTest)
gtest_discover_tests(TEST)
