cmake_minimum_required(VERSION 3.4)
set(CMAKE_LEGACY_CYGWIN_WIN32 OFF)

project(FigthersEngine C CXX)
find_package(OpenGL REQUIRED)

set(THIRD_PARTY_INCLUDE_DIRECTORIES 
    "${CMAKE_CURRENT_SOURCE_DIR}/libs/glad/opengl3.3/source/glad/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/libs/glfw/source/glfw/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/libs/glm/source/glm"
)

set(FG_ENGINE_INCLUDE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/engine")

if(MSVC)
    set(THIRD_PARTY_LIBRARIES glad glfw ${OPENGL_LIBRARIES})
else()
    set(THIRD_PARTY_LIBRARIES glad glfw ${OPENGL_LIBRARIES})
endif(MSVC)

# Include sub-projects.
# configure_file(CMakeConfigFiles/root_directory.h.in "${CMAKE_SOURCE_DIR}/engine/source/root_directory.h")
add_subdirectory(libs)
add_subdirectory(app)
add_subdirectory(engine)