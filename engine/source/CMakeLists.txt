cmake_minimum_required(VERSION 3.20)
set(CMAKE_LEGACY_CYGWIN_WIN32 OFF)

project(ventana_engine C CXX)

# Getting the parent directory twice
cmake_path(GET CMAKE_SOURCE_DIR PARENT_PATH EXAMPLE_DIR)
cmake_path(GET EXAMPLE_DIR PARENT_PATH REPO_DIR)

# SHARED library
#add_library(actor_lib SHARED
#)
#
#include(GenerateExportHeader)
#generate_export_header(actor_lib)

add_executable(ventana_engine "main.cpp")
set_property(TARGET ventana_engine PROPERTY CXX_STANDARD 20)
target_link_libraries(ventana_engine PRIVATE
    "${REPO_DIR}/libs/glad/opengl3.3/build/Release/glad.lib"
    "${REPO_DIR}/libs/glfw/build/src/Release/glfw3.lib"
)
target_include_directories(ventana_engine PRIVATE
    "${REPO_DIR}/libs/glad/opengl3.3/source/glad/include"
    "${REPO_DIR}/libs/glfw/source/glfw/include"
)