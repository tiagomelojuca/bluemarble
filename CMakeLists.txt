cmake_minimum_required(VERSION 3.12)

project(BlueMarble)

add_executable(BlueMarble src/main.cpp)

target_include_directories(BlueMarble PRIVATE deps/glm
                                              deps/stb)

if (WIN32)
    target_include_directories(BlueMarble PRIVATE deps/glfw/include
                                                  deps/glew/include)

    target_link_directories(BlueMarble PRIVATE deps/glfw/lib-vc2019
                                               deps/glew/lib/Release/x64)

    target_link_libraries(BlueMarble PRIVATE glfw3.lib glew32.lib)

    add_custom_command(TARGET BlueMarble POST_BUILD
                       COMMAND ${CMAKE_COMMAND} -E copy
                       "${CMAKE_SOURCE_DIR}/deps/glew/bin/Release/x64/glew32.dll"
                       "${CMAKE_BINARY_DIR}/RelWithDebInfo/glew32.dll")
else()
    find_package(glfw3 REQUIRED)
    find_package(GLEW REQUIRED)
    find_package(OpenGL REQUIRED)

    target_link_libraries(BlueMarble GLEW::glew
                                     glfw
                                     OpenGL::OpenGL)
endif()
