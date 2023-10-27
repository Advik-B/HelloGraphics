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
