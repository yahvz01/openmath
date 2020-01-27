include( ${CMAKE_SOURCE_DIR}/cmake/shortcut_function.cmake )

# Bitwise.hpp
short_cut_add_test(
    method_bitwise_left_shift_with_extend
    ${BINARY_CPP_FILE}
    test_method_bitwise_left_shift_with_extend.cpp
)

short_cut_add_test(
    method_bitwise_left_shift
    ${BINARY_CPP_FILE}
    test_method_bitwise_left_shift.cpp
)

short_cut_add_test(
    method_bitwise_right_shift
    ${BINARY_CPP_FILE}
    test_method_bitwise_right_shift.cpp
)
