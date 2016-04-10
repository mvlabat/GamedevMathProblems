set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set (main_src
        main.cpp
        DemoDrawer/DemoDrawer.cpp DemoDrawer/DemoDrawer.h
        DemoDrawer/Demos/DemoInterface.cpp DemoDrawer/Demos/DemoInterface.h
        DemoDrawer/Demos/PlainBezierCurveDemo/PlainBezierCurveDemo.cpp DemoDrawer/Demos/PlainBezierCurveDemo/PlainBezierCurveDemo.h
        )

add_executable(app
        ${main_src}
)

target_link_libraries(app
        My2D
        My3D)

# Linking SDL2.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake/Modules)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
target_link_libraries(app ${SDL2_LIBRARY})
