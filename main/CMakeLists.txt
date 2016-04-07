set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set (main_src
        main.cpp
    )

add_executable(app
        ${main_src}
)

target_link_libraries(app
        My2D
        My3D)
