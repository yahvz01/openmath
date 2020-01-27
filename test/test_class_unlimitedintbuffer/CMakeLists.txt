include( ${CMAKE_SOURCE_DIR}/cmake/shortcut_function.cmake )

custom_add_library_test(
    class_unlimitedintbuffer_ctor
    ${CMAKE_SOURCE_DIR}/include
    "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${target_link_libraries}"
    test_class_unlimitedintbuffer_ctor.cpp
    ${UNLIMITED_BUFFER_INT_CPP_FILE}
)

custom_add_library_test(
    class_unlimitedintbuffer_bit_opt
    ${CMAKE_SOURCE_DIR}/include
    "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${target_link_libraries}"
    test_class_unlimitedintbuffer_bit_opt.cpp
    ${UNLIMITED_BUFFER_INT_CPP_FILE}
)

custom_add_library_test(
    class_unlimitedintbuffer_bit_shift_opt
    ${CMAKE_SOURCE_DIR}/include
    "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${target_link_libraries}"
    test_class_unlimitedintbuffer_bit_shift_opt.cpp
    ${UNLIMITED_BUFFER_INT_CPP_FILE}
)

custom_add_library_test(
    class_unlimitedintbuffer_arithmetic_opt_sum
    ${CMAKE_SOURCE_DIR}/include
    "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${target_link_libraries}"
    test_class_unlimitedintbuffer_arithmetic_opt_sum.cpp
    ${UNLIMITED_BUFFER_INT_CPP_FILE}
)


custom_add_library_test(
    class_unlimitedintbuffer_arithmetic_opt_subtract
    ${CMAKE_SOURCE_DIR}/include
    "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${target_link_libraries}"
    test_class_unlimitedintbuffer_arithmetic_opt_subtract.cpp
    ${UNLIMITED_BUFFER_INT_CPP_FILE}
)

custom_add_library_test(
    class_unlimitedintbuffer_arithmetic_opt_multiply
    ${CMAKE_SOURCE_DIR}/include
    "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${target_link_libraries}"
    test_class_unlimitedintbuffer_arithmetic_opt_multiply.cpp
    ${UNLIMITED_BUFFER_INT_CPP_FILE}
)


custom_add_library_test(
    class_unlimitedintbuffer_arithmetic_opt_divide
    ${CMAKE_SOURCE_DIR}/include
    "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${target_link_libraries}"
    test_class_unlimitedintbuffer_arithmetic_opt_divide.cpp
    ${UNLIMITED_BUFFER_INT_CPP_FILE}
)

custom_add_library_test(
    class_unlimitedintbuffer_arithmetic_opt_remainder
    ${CMAKE_SOURCE_DIR}/include
    "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${target_link_libraries}"
    test_class_unlimitedintbuffer_arithmetic_opt_remainder.cpp
    ${UNLIMITED_BUFFER_INT_CPP_FILE}
)
