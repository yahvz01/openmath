if( NOT PROJECT_GLOBAL_SET_UP STREQUAL "TRUE")
    set( PROJECT_GLOBAL_SET_UP "TRUE" )
    set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )
    set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )
    set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )
endif()
set( BINARY_CPP_FILE
    ${CMAKE_SOURCE_DIR}/src/Binary.cpp
    ${CMAKE_SOURCE_DIR}/src/Binary_Ptr_Impl.cpp
    ${CMAKE_SOURCE_DIR}/src/Binary_Arithmetic_Sum_Opt.cpp
    ${CMAKE_SOURCE_DIR}/src/Binary_Arithmetic_Multiply_Opt.cpp
    ${CMAKE_SOURCE_DIR}/src/Binary_Arithmetic_Divide_Opt.cpp
    ${CMAKE_SOURCE_DIR}/src/Binary_Arithmetic_Remainder_Opt.cpp
    ${CMAKE_SOURCE_DIR}/src/Binary_Arithmetic_Divide_Remainder_Opt.cpp
    ${CMAKE_SOURCE_DIR}/src/Binary_Convert.cpp
    ${CMAKE_SOURCE_DIR}/src/Bitwise.cpp
)

set( TYPE_CLASS_HELPER_FILE
    ${CMAKE_SOURCE_DIR}/src/CompResult.cpp
)

set( UNLIMITED_INT_CLASS_HELPER_FILE
    ${CMAKE_SOURCE_DIR}/src/UnLimitedIntClassHelper.cpp
)



set( FIXED_BYTE_LENGTH_INT_BUFFER_CPP_FILE
    ${BINARY_CPP_FILE}
    ${TYPE_CLASS_HELPER_FILE}
    ${CMAKE_SOURCE_DIR}/src/fixedbytelengthintbuffer/FixedByteLengthIntBuffer_Arithmetic_Opt.cpp 
    ${CMAKE_SOURCE_DIR}/src/fixedbytelengthintbuffer/FixedByteLengthIntBuffer_Ctor.cpp 
    ${CMAKE_SOURCE_DIR}/src/fixedbytelengthintbuffer/FixedByteLengthIntBuffer_Bit_Opt.cpp 
    ${CMAKE_SOURCE_DIR}/src/fixedbytelengthintbuffer/FixedByteLengthIntBuffer_Bit_Shift_Opt.cpp
    ${CMAKE_SOURCE_DIR}/src/fixedbytelengthintbuffer/FixedByteLengthIntBuffer_Method.cpp
    ${CMAKE_SOURCE_DIR}/src/fixedbytelengthintbuffer/FixedByteLengthIntBuffer_Special_Memeber_And_Dtor.cpp
)

# fixedbytelengthint
set( FIXED_BYTE_LENGTH_INT_CPP_FILE
    ${BINARY_CPP_FILE}
    ${TYPE_CLASS_HELPER_FILE}
    ${CMAKE_SOURCE_DIR}/src/fixedbytelengthint/FixedByteLengthInt_Arithmetic_Opt.cpp 
    ${CMAKE_SOURCE_DIR}/src/fixedbytelengthint/FixedByteLengthInt_Ctor.cpp 
    ${CMAKE_SOURCE_DIR}/src/fixedbytelengthint/FixedByteLengthInt_Bit_Opt.cpp 
    ${CMAKE_SOURCE_DIR}/src/fixedbytelengthint/FixedByteLengthInt_Bit_Shift_Opt.cpp
    ${CMAKE_SOURCE_DIR}/src/fixedbytelengthint/FixedByteLengthInt_Method.cpp
    ${CMAKE_SOURCE_DIR}/src/fixedbytelengthint/FixedByteLengthInt_Comp_Opt.cpp
    ${CMAKE_SOURCE_DIR}/src/fixedbytelengthint/FixedByteLengthInt_Special_Memeber_And_Dtor.cpp
)

# unlimitedintbuffer
set( UNLIMITED_BUFFER_INT_CPP_FILE
    ${BINARY_CPP_FILE}
    ${TYPE_CLASS_HELPER_FILE}
    ${CMAKE_SOURCE_DIR}/src/unlimitedintbuffer/UnLimitedIntBuffer_Arithmetic_Opt.cpp 
    ${CMAKE_SOURCE_DIR}/src/unlimitedintbuffer/UnLimitedIntBuffer_Ctor.cpp
    ${CMAKE_SOURCE_DIR}/src/unlimitedintbuffer/UnLimitedIntBuffer_Method.cpp
    ${CMAKE_SOURCE_DIR}/src/unlimitedintbuffer/UnLimitedIntBuffer_Special_Member_And_Dtor.cpp
    ${CMAKE_SOURCE_DIR}/src/unlimitedintbuffer/UnLimitedIntBuffer_Bit_Opt.cpp
    ${CMAKE_SOURCE_DIR}/src/unlimitedintbuffer/UnLimitedIntBuffer_Bit_Shift_Opt.cpp )

# unlimitedint
set( UNLIMITED_INT_CPP_FILE
    ${BINARY_CPP_FILE}
    ${TYPE_CLASS_HELPER_FILE}
    ${UNLIMITED_INT_CLASS_HELPER_FILE}
    ${CMAKE_SOURCE_DIR}/src/unlimitedint/UnLimitedInt_Ctor.cpp
    ${CMAKE_SOURCE_DIR}/src/unlimitedint/UnLimitedInt_Method.cpp
    ${CMAKE_SOURCE_DIR}/src/unlimitedint/UnLimitedInt_Special_Member_And_Dtor.cpp
    ${CMAKE_SOURCE_DIR}/src/unlimitedint/UnLimitedInt_Bit_Opt.cpp
    ${CMAKE_SOURCE_DIR}/src/unlimitedint/UnLimitedInt_Bit_Shift_Opt.cpp
    ${CMAKE_SOURCE_DIR}/src/unlimitedint/UnLimitedInt_Comp_Opt.cpp
    ${CMAKE_SOURCE_DIR}/src/unlimitedint/UnLimitedInt_Arithmetic_Opt.cpp )
