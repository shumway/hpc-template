set(SYSTEM_TEST_SCRIPTS
)

foreach(_script ${SYSTEM_TEST_SCRIPTS})
    configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/${_script}
        ${CMAKE_CURRENT_BINARY_DIR}/${_script}
        COPYONLY
    )
endforeach()
