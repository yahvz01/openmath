cmake_minimum_required( VERSION 3.10 )

project( openmath )

if( ${CMAKE_BINARY_DIR} STREQUAL ${CMAKE_SOURCE_DIR} )
    message( FATAL_ERROR "In-Source build is not allowed,
    You should create a seperated directory for build result")
endif() 

include( ${CMAKE_SOURCE_DIR}/cmake/global_set_up.cmake )

add_subdirectory( src )
add_subdirectory( test )