cmake_minimum_required(VERSION 3.26)
project(HelloImGUI)

set(CMAKE_CXX_STANDARD 17)

# Set the DIR(s)
set(glfw3_DIR "D:/vcpkg/installed/x64-windows/share/glfw3")


find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)


# Add all the source files in the imgui directory
file(GLOB_RECURSE IMGUI_SOURCES "imgui/*.cpp")
# Add all the header files in the imgui directory
file(GLOB_RECURSE IMGUI_HEADERS "imgui/*.h")
# Add all the source files in the glad/src directory
file(GLOB_RECURSE GLAD_SOURCES "glad/src/*.c")
# Add all the header files in the glad/include directory
file(GLOB_RECURSE GLAD_HEADERS "glad/include/*.h")

add_executable(
    HelloImGUI
    main.cpp
    exit_codes.h
    ${IMGUI_SOURCES}
    ${IMGUI_HEADERS}
    ${GLAD_SOURCES}
    ${GLAD_HEADERS}
)

# Link the libraries

target_link_libraries(HelloImGUI PRIVATE ${OPENGL_LIBRARIES})
target_link_libraries(HelloImGUI PRIVATE glfw)
target_include_directories(HelloImGUI PRIVATE ${OPENGL_INCLUDE_DIR})
target_include_directories(HelloImGUI PRIVATE ${GLFW_INCLUDE_DIRS})
# Add ./glad/include to the include directories
target_include_directories(HelloImGUI PRIVATE ./glad/include)

# Add all the source files in the src directory
file(GLOB_RECURSE SOURCES "src/*.cpp")
target_sources(HelloImGUI PRIVATE ${SOURCES})

# Add all the header files
target_include_directories(HelloImGUI PRIVATE imgui)
