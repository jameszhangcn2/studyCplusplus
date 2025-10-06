set(BINARY ${CMAKE_PROJECT_NAME}_tst)

#add_esecutable(EampleProject main.cpp file1.cpp file1.h)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

set(SOURCES ${TEST_SOURCES})

add_executable(${BINARY} ${TEST_SOURCES})

#add_library(${BINARY}_lib STATIC ${SOURCES})

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)

#cmake .. -DCMAKE_BUILD_TYPE=Debug