cmake_minimum_required(VERSION 3.26)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)

# Dont want a seperate .exe.manifest file, instead embed it into the .exe
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /MANIFEST:NO")

# GLFW config
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
set(GLFW_VULKAN_STATIC OFF CACHE BOOL "" FORCE)
set(GLFW_USE_HYBRID_HPG ON CACHE BOOL "" FORCE)
set(GLFW_USE_OPTIMUS_HPG ON CACHE BOOL "" FORCE)
set(GLFW_USE_OSMESA OFF CACHE BOOL "" FORCE)
set(GLFW_USE_WAYLAND OFF CACHE BOOL "" FORCE)
set(GLFW_USE_MIR OFF CACHE BOOL "" FORCE)
set(GLFW_USE_EGL OFF CACHE BOOL "" FORCE)
set(GLFW_USE_GLU OFF CACHE BOOL "" FORCE)

add_subdirectory(glfw)

project(Minimal_GUI)

add_executable(Minimal_GUI main.cpp)

target_link_libraries(Minimal_GUI glfw glad OpenGL::GL imgui)

target_include_directories(Minimal_GUI PUBLIC include)


# Disable console window for Release builds
if (CMAKE_BUILD_TYPE STREQUAL "Release")
    if (WIN32)
        set_target_properties(Minimal_GUI PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
    else (
            set_target_properties(Minimal_GUI PROPERTIES LINK_FLAGS "-mwindows")
    )
    endif ()


endif()
