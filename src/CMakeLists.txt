#add_subdirectory(util)

add_executable(my-app main.cpp)

target_link_libraries(my-app)

target_link_libraries(my-app ${BLAS_LIB})
target_link_libraries(my-app ${LAPACK_LIB})
if (EXISTS ${LIBF2C_LIB})
  target_link_libraries(my-app ${LIBF2C_LIB})
endif(EXISTS ${LIBF2C_LIB})

set_target_properties(my-app
    PROPERTIES
    LINKER_LANGUAGE CXX)
