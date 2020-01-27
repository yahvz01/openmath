include( ${CMAKE_SOURCE_DIR}/cmake/shortcut_function.cmake )

# Binary.hpp
short_cut_add_test( 
    method_make_binary_complementary
    ${BINARY_CPP_FILE}
    test_method_make_binary_complementary.cpp )

short_cut_add_test(
    method_carry_out_lookahead
    ${BINARY_CPP_FILE}
    test_method_carry_out_lookahead.cpp
    )

short_cut_add_test(
    method_half_adder
    ${BINARY_CPP_FILE}
    test_method_half_adder.cpp
    )

short_cut_add_test(
    method_full_adder
    ${BINARY_CPP_FILE}
    test_method_full_adder.cpp
    )

short_cut_add_test(
    method_get_digit_binary_number
    ${BINARY_CPP_FILE}
    test_method_get_digit_binary_number.cpp
    )

short_cut_add_test(
    method_make_binary_complementary_ptr
    ${BINARY_CPP_FILE}
    test_method_make_binary_complementary_ptr.cpp
    )

short_cut_add_test(
    method_get_digit_binary_number_ptr
    ${BINARY_CPP_FILE}
    test_method_get_digit_binary_number_ptr.cpp
    )
short_cut_add_test(
    method_is_positive
    ${BINARY_CPP_FILE}
    test_method_is_positive.cpp
    )

short_cut_add_test(
    method_is_positive_ptr
    ${BINARY_CPP_FILE}
    test_method_is_positive_ptr.cpp
)

short_cut_add_test(
    method_carry_out_lookahead_ptr
    ${BINARY_CPP_FILE}
    test_method_carry_out_lookahead_ptr.cpp
)

short_cut_add_test(
    method_adder_ptr
    ${BINARY_CPP_FILE}
    test_method_adder_ptr.cpp
)

short_cut_add_test(
    method_multiply_ptr
    ${BINARY_CPP_FILE}
    test_method_multiply_ptr.cpp
)

short_cut_add_test(
    method_divide_ptr
    ${BINARY_CPP_FILE}
    test_method_divide_ptr.cpp
)

short_cut_add_test(
    method_remainder_ptr
    ${BINARY_CPP_FILE}
    test_method_remainder_ptr.cpp
)

short_cut_add_test(
    method_divide_remainder_ptr
    ${BINARY_CPP_FILE}
    test_method_divide_remainder_ptr.cpp
)

# Binary_Convert.cpp
short_cut_add_test(
    method_string_to_integar_ptr
    ${BINARY_CPP_FILE}
    test_method_string_to_integar_ptr.cpp
)


short_cut_add_test(
    method_integar_to_c_string_ptr
    ${BINARY_CPP_FILE}
    test_method_integar_to_c_string_ptr.cpp
)

