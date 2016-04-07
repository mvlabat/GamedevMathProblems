cmake_minimum_required(VERSION 3.5)
project(GamedevMathProblems)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(lib/gtest-1.7.0)
add_subdirectory(My2D/src)
add_subdirectory(My3D/src)
add_subdirectory(main)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runtests
        My2D/tests/My2DTests.cpp
        My3D/tests/My3DTests.cpp
)

target_link_libraries(runtests My2D My3D gtest gtest_main)
