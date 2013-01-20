#add_subdirectory(util)

set(SRC_DIR ${PI_QMC_SOURCE_DIR}/src)
set(TEST_DIR ${PI_QMC_SOURCE_DIR}/test/unit)

include_directories(${SRC_DIR} ${TEST_DIR} ${GTEST_SOURCE_DIR}/include)

add_executable(unittest_my_app EXCLUDE_FROM_ALL 
    unittest_main.cpp
    ${sources}
)

target_link_libraries(unittest_my_app)

target_link_libraries(unittest_my_app gtest -lpthread)
target_link_libraries(unittest_my_app ${BLAS_LIB})
target_link_libraries(unittest_my_app ${LAPACK_LIB})
if (EXISTS ${LIBF2C_LIB})
    target_link_libraries(unittest_my_app ${LIBF2C_LIB})
endif()

add_dependencies(unittest unittest_my_app)
