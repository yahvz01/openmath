include( ${CMAKE_SOURCE_DIR}/cmake/shortcut_function.cmake )

# unlimitedint

custom_add_library_test(
    class_unlimitedint_ctor
    ${CMAKE_SOURCE_DIR}/include
    "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${target_link_libraries}"
    test_class_unlimitedint_ctor.cpp
    ${UNLIMITED_INT_CPP_FILE}
)

custom_add_library_test(
    class_unlimitedint_speical_member
    ${CMAKE_SOURCE_DIR}/include
    "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${target_link_libraries}"
    test_class_unlimitedint_special_member.cpp
    ${UNLIMITED_INT_CPP_FILE}
)

custom_add_library_test(
    class_unlimitedint_abs
    ${CMAKE_SOURCE_DIR}/include
    "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${target_link_libraries}"
    test_class_unlimitedint_abs.cpp
    ${UNLIMITED_INT_CPP_FILE}
)


custom_add_library_test(
    class_unlimitedint_bit_opt
    ${CMAKE_SOURCE_DIR}/include
    "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${target_link_libraries}"
    test_class_unlimitedint_bit_opt.cpp
    ${UNLIMITED_INT_CPP_FILE}
)

custom_add_library_test(
    class_unlimitedint_bit_shift_opt
    ${CMAKE_SOURCE_DIR}/include
    "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${target_link_libraries}"
    test_class_unlimitedint_bit_shift_opt.cpp
    ${UNLIMITED_INT_CPP_FILE}
)

custom_add_library_test(
    class_unlimitedint_comp_opt
    ${CMAKE_SOURCE_DIR}/include
    "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${target_link_libraries}"
    test_class_unlimitedint_comp_opt.cpp
    ${UNLIMITED_INT_CPP_FILE}
)

custom_add_library_test(
    class_unlimitedint_arithmethic_sum_opt
    ${CMAKE_SOURCE_DIR}/include
    "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${target_link_libraries}"
    test_class_unlimitedint_arithmethic_opt_sum.cpp
    ${UNLIMITED_INT_CPP_FILE}
)

custom_add_library_test(
    class_unlimitedint_arithmethic_subtract_opt
    ${CMAKE_SOURCE_DIR}/include
    "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${target_link_libraries}"
    test_class_unlimitedint_arithmethic_opt_subtract.cpp
    ${UNLIMITED_INT_CPP_FILE}
)


custom_add_library_test(
    class_unlimitedint_arithmethic_multiply_opt
    ${CMAKE_SOURCE_DIR}/include
    "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${target_link_libraries}"
    test_class_unlimitedint_arithmethic_opt_multiply.cpp
    ${UNLIMITED_INT_CPP_FILE}
)

custom_add_library_test(
    class_unlimitedint_arithmethic_divide_opt
    ${CMAKE_SOURCE_DIR}/include
    "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${target_link_libraries}"
    test_class_unlimitedint_arithmethic_opt_divide.cpp
    ${UNLIMITED_INT_CPP_FILE}
)

custom_add_library_test(
    class_unlimitedint_arithmethic_remainder_opt
    ${CMAKE_SOURCE_DIR}/include
    "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${target_link_libraries}"
    test_class_unlimitedint_arithmethic_opt_remainder.cpp
    ${UNLIMITED_INT_CPP_FILE}
)