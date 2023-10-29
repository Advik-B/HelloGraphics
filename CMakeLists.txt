cmake_minimum_required(VERSION 3.26)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)

# Dont want a seperate .exe.manifest file, instead embed it into the .exe
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /MANIFEST:NO")

project(Minimal_GUI)

add_executable(Minimal_GUI main.cpp)
target_link_directories(Minimal_GUI PUBLIC lib)
target_link_libraries(Minimal_GUI glfw3 glad OpenGL::GL imgui)
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
