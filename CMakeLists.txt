cmake_minimum_required(VERSION 3.26)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# No need for Finding OpenGL, because (gladly), glad does that
#find_package(OpenGL REQUIRED)


# GLFW config
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(imgui_DIR ${CMAKE_SOURCE_DIR}/imgui)

add_subdirectory(glfw)


project(Minimal_GUI)

file(GLOB_RECURSE IMGUI_HEADERS imgui/*.h)
file(GLOB_RECURSE IMGUI_SOURCES imgui/*.cpp)
# ImGUI config
add_library(imgui STATIC ${IMGUI_HEADERS} ${IMGUI_SOURCES})


add_executable(Minimal_GUI main.cpp)

#target_link_libraries(Minimal_GUI glfw OpenGL::GL)

target_include_directories(Minimal_GUI PUBLIC glfw/include)
target_include_directories(Minimal_GUI PUBLIC imgui)
target_include_directories(Minimal_GUI PUBLIC imgui/backends)
target_include_directories(Minimal_GUI PUBLIC glad/include)


