function(MakeExample TARGETNAME FILENAME)
    add_executable(${TARGETNAME} ${FILENAME})
    set_property(TARGET ${TARGETNAME} PROPERTY CXX_STANDARD 20)
    set_property(TARGET ${TARGETNAME} PROPERTY FOLDER app)
    target_include_directories(${TARGETNAME} PRIVATE ${FG_ENGINE_INCLUDE_DIRECTORY} ${THIRD_PARTY_INCLUDE_DIRECTORIES})
    target_link_libraries(${TARGETNAME} PRIVATE FG_Engine)
endfunction(MakeExample)

MakeExample(Demo main.cpp)