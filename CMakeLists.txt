cmake_minimum_required(VERSION 3.26)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)

project(Minimal_GUI)
add_executable(Minimal_GUI main.cpp)


# Add ./include to the include directories
target_include_directories(Minimal_GUI PRIVATE include)
# Add glad/include to the include directories
target_include_directories(Minimal_GUI PRIVATE glad/include)
# Add glad/src to the include directories
target_include_directories(Minimal_GUI PRIVATE glad/src)
# Add GLFW and GLAD
target_link_libraries(Minimal_GUI PRIVATE glfw glad)

# Add OpenGL
target_link_libraries(Minimal_GUI PRIVATE OpenGL::GL)