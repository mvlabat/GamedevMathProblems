set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(allTests
        My2DTests.cpp)

target_link_libraries(allTests My2D)
target_link_libraries(allTests gtest gtest_main)
