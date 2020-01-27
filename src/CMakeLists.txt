include( ${CMAKE_SOURCE_DIR}/cmake/global_set_up.cmake )

set( OPEN_MATH_LIBRARY unlimitedint )

add_library(
    ${OPEN_MATH_LIBRARY}
    STATIC
    ${UNLIMITED_INT_CPP_FILE}
    ${FIXED_BYTE_LENGTH_INT_BUFFER_CPP_FILE}
)

target_include_directories(
    ${OPEN_MATH_LIBRARY}
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_SOURCE_DIR}/src/include
)

# target_include_directories(
#     ${OPEN_MATH_LIBRARY}
#     PRIVATE
#         ${UNLIMITED_INT_CPP_FILE}
# )
