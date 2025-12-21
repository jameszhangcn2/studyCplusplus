cmake_minimum_required(VERSION 3.10)

project(spdlog_examples CXX)

set(CMAKE_CXX_STANDARD 14)

if(NOT TARGET spdlog)
    # Stand-alone build
    find_package(spdlog REQUIRED)
endif()

include_directories(src)
add_subdirectory(src)

if(SPDLOG_BUILD_EXAMPLE_HO)
    add_executable(example_header_only example.cpp)
    target_link_libraries(example_header_only PRIVATE spdlog::spdlog_header_only)
endif()