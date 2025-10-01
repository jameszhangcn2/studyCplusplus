cmake_minimum_required(VERSION 3.20)
project(Hello)

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

add_executable(HELLO src/main.cpp)

add_executable(TEST test/test.cpp)

target_include_directories( HELLO
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries( HELLO
    PRIVATE
        ${PROJECT_SOURCE_DIR}/static_libs/libhello_library.a
)

target_link_libraries( TEST
    PRIVATE
        ${PROJECT_SOURCE_DIR}/static_libs/libhello_library.a
)

target_include_directories( HELLO
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)