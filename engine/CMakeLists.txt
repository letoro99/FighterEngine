set(FG_HEADERS
    source/models.h
    source/shaders.h
)

set(FG_SOURCES
    source/models.cpp
    source/shaders.cpp
)

add_library(FG_Engine STATIC ${FG_SOURCES} ${FG_HEADERS} FG_Engine.hpp)
if (MSVC)
    target_compile_options(FG_Engine PUBLIC /wd5033)
endif(MSVC)
target_include_directories(FG_Engine PRIVATE ${THIRD_PARTY_INCLUDE_DIRECTORIES} FG_ENGINE_INCLUDE_DIRECTORY)
target_link_libraries(FG_Engine PRIVATE ${THIRD_PARTY_LIBRARIES})
set_property(TARGET FG_Engine PROPERTY CXX_STANDARD 20)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${FG_SOURCES} ${FG_HEADERS})