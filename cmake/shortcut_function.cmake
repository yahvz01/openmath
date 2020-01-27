include( ${CMAKE_SOURCE_DIR}/cmake/custom_add_test.cmake )
include( ${CMAKE_SOURCE_DIR}/cmake/global_set_up.cmake )

function( short_cut_add_test test_name target_binary)
    math( EXPR executable_argc "${ARGC} - 1")
    list( SUBLIST ARGV 1 -1 executable_list )
    # message("custom message [ ${ARGC} ]: ${ARGV}")
    custom_add_test( 
        ${test_name}
        ${CMAKE_SOURCE_DIR}/include
        ${executable_list}
    )
endfunction()

function( short_cut_add_library_test test_name target_link_libraries target_binary )
    math( EXPR executable_argc "${ARGC} - 3")
    list( SUBLIST ARGV 3 -1 executable_list )
    
    custom_add_library_test(
        ${test_name}
        ${CMAKE_SOURCE_DIR}/include
        "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${target_link_libraries}"
        ${target_binary}
        ${executable_list}
    )
endfunction()