get_filename_component(dir ${CMAKE_CURRENT_SOURCE_DIR} NAME)

file(GLOB TestSuites_CPP "*.cpp")

set(sources
    ${sources}
    ${TestSuites_CPP}
    PARENT_SCOPE
)
