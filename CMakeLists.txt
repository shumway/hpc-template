cmake_minimum_required (VERSION 2.6)

project (MY_APP)
set (MY_APP_VERSION_MAJOR 0)
set (MY_APP_VERSION_MINOR 1)
enable_language(CXX)

find_library(LAPACK_LIB
NAMES
    lapack
PATHS
    ENV LAPACK
    /usr/lib
    /usr/local/lib
    c:/libraries/lib
)

if(NOT EXISTS ${LAPACK_LIB})
    message("** Error finding MY_APP required library:")
    message("**   Try setting the LAPACK environtment variable")
    message("**   to the directory containing lapack")
    message(FATAL_ERROR "** MY_APP requires the LAPACK libary")
else()
    message("Found LAPACK: " ${LAPACK_LIB})
endif(NOT EXISTS ${LAPACK_LIB})

find_library(BLAS_LIB
NAMES
    blas
PATHS
    /usr/lib
    /usr/local/lib
    c:/libraries/lib
    ENV BLAS
PATHS_SUFFIXES
    lib
)

if(NOT EXISTS ${BLAS_LIB})
    message("** Error finding MY_APP required library:")
    message("**   Try setting the BLAS environtment variable")
    message("**   to the directory containing blas")
    message(FATAL_ERROR "** MY_APP requires the BLAS libary")
else()
    message("Found BLAS: " ${BLAS_LIB})    
endif(NOT EXISTS ${BLAS_LIB})

find_library(LIBF2C_LIB
NAMES
    libf2c
PATHS
    /usr/lib
    /usr/local/lib
    c:/libraries/lib
    ENV BLAS
PATHS_SUFFIXES
    lib
)

FIND_PACKAGE(LibXml2 REQUIRED)
INCLUDE_DIRECTORIES (SYSTEM "${LIBXML2_INCLUDE_DIR}")

find_library(HDF5_LIB
NAMES
    hdf5
PATHS
    /usr/lib
    /usr/local/lib
    c:/libraries/lib
    ENV HDF5
PATHS_SUFFIXES
    lib
)

include(CheckIncludeFiles)
CHECK_INCLUDE_FILES(getopt.h HAVE_GETOPT_H)

configure_file (
  "${MY_APP_SOURCE_DIR}/config_cmake.h.in"
  "${MY_APP_BINARY_DIR}/config.h"
)

INCLUDE_DIRECTORIES(
    ${MY_APP_BINARY_DIR}
    ${MY_APP_SOURCE_DIR}/lib
    ${MY_APP_SOURCE_DIR}/src
)

add_definitions(-DHAVE_CONFIG_H)

set(EXECUTABLE_OUTPUT_PATH ${MY_APP_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${MY_APP_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${MY_APP_BINARY_DIR}/lib)


add_custom_target(unittest)
set (GTEST_SOURCE_DIR ${MY_APP_SOURCE_DIR}/contrib/gtest-1.6.0)
add_subdirectory(${GTEST_SOURCE_DIR})

# add a target to generate API documentation with Doxygen
find_package(Doxygen)
if(DOXYGEN_FOUND)
    set (DOXYGEN_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/doc/doxygen)
    set (DOXYGEN_BIN_DIR ${CMAKE_CURRENT_BINARY_DIR}/doc/doxygen)
    configure_file(${DOXYGEN_SRC_DIR}/Doxyfile.in 
                   ${DOXYGEN_BIN_DIR}/Doxyfile @ONLY)
    add_custom_target(doxygen
        ${DOXYGEN_EXECUTABLE} ${DOXYGEN_BIN_DIR}/Doxyfile
        WORKING_DIRECTORY ${DOXYGEN_BIN_DIR}
        COMMENT "Generating API documentation with Doxygen" VERBATIM)
endif(DOXYGEN_FOUND)

add_subdirectory(src)
add_subdirectory(test)
