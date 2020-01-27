include( ${CMAKE_SOURCE_DIR}/cmake/shortcut_function.cmake )

# fixedbytelengthintbuffer
custom_add_library_test(
    class_fixedbytelengthintbuffer_ctor
    ${CMAKE_SOURCE_DIR}/include
    "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${target_link_libraries}"
    test_class_fixedbytelengthintbuffer_ctor.cpp
    ${FIXED_BYTE_LENGTH_INT_BUFFER_CPP_FILE}
)

custom_add_library_test(
    class_fixedbytelengthintbuffer_bit_opt
    ${CMAKE_SOURCE_DIR}/include
    "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${target_link_libraries}"
    test_class_fixedbytelengthintbuffer_bit_opt.cpp
    ${FIXED_BYTE_LENGTH_INT_BUFFER_CPP_FILE}
)

custom_add_library_test(
    class_fixedbytelengthintbuffer_bit_shift_opt
    ${CMAKE_SOURCE_DIR}/include
    "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${target_link_libraries}"
    test_class_fixedbytelengthintbuffer_bit_shift_opt.cpp
    ${FIXED_BYTE_LENGTH_INT_BUFFER_CPP_FILE}
)

custom_add_library_test(
    class_fixedbytelengthintbuffer_arithmetic_opt_sum
    ${CMAKE_SOURCE_DIR}/include
    "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${target_link_libraries}"
    test_class_fixedbytelengthintbuffer_arithmetic_opt_sum.cpp
    ${FIXED_BYTE_LENGTH_INT_BUFFER_CPP_FILE}
)

custom_add_library_test(
    class_fixedbytelengthintbuffer_arithmetic_opt_subtract
    ${CMAKE_SOURCE_DIR}/include
    "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${target_link_libraries}"
    test_class_fixedbytelengthintbuffer_arithmetic_opt_subtract.cpp
    ${FIXED_BYTE_LENGTH_INT_BUFFER_CPP_FILE}
)

custom_add_library_test(
    class_fixedbytelengthintbuffer_arithmetic_opt_multiply
    ${CMAKE_SOURCE_DIR}/include
    "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${target_link_libraries}"
    test_class_fixedbytelengthintbuffer_arithmetic_opt_multiply.cpp
    ${FIXED_BYTE_LENGTH_INT_BUFFER_CPP_FILE}
)

custom_add_library_test(
    class_fixedbytelengthintbuffer_arithmetic_opt_divide
    ${CMAKE_SOURCE_DIR}/include
    "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${target_link_libraries}"
    test_class_fixedbytelengthintbuffer_arithmetic_opt_divide.cpp
    ${FIXED_BYTE_LENGTH_INT_BUFFER_CPP_FILE}
)

custom_add_library_test(
    class_fixedbytelengthintbuffer_arithmetic_opt_remainder
    ${CMAKE_SOURCE_DIR}/include
    "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${target_link_libraries}"
    test_class_fixedbytelengthintbuffer_arithmetic_opt_remainder.cpp
    ${FIXED_BYTE_LENGTH_INT_BUFFER_CPP_FILE}
)
