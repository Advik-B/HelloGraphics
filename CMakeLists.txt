cmake_minimum_required(VERSION 3.26)
project(HelloImGUI)

set(CMAKE_CXX_STANDARD 17)

# Set the DIR(s)
set(glfw3_DIR "D:/vcpkg/installed/x64-windows/share/glfw3")


find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)



add_executable(
    HelloImGUI
    main.cpp
    exit_codes.h
)

# Link the libraries

target_link_libraries(HelloImGUI PRIVATE ${OPENGL_LIBRARIES})
target_link_libraries(HelloImGUI PRIVATE glfw)
target_include_directories(HelloImGUI PRIVATE ${OPENGL_INCLUDE_DIR})
target_include_directories(HelloImGUI PRIVATE ${GLFW_INCLUDE_DIRS})
# Add ./glad/include to the include directories
target_include_directories(HelloImGUI PRIVATE ./glad/include)
target_include_directories(HelloImGUI PRIVATE ./imgui)
target_include_directories(HelloImGUI PRIVATE ./imgui/backends)

#
## Add all .cpp files in ./imgui to the target
#file(GLOB IMGUI_SOURCES ./imgui/*.cpp)
#target_sources(HelloImGUI PRIVATE ${IMGUI_SOURCES})
