cmake_minimum_required(VERSION 3.15)
project( test_cmake )

function( test_func test_name)
	math(EXPR args "${ARGC} - 1")
	message("Message Vars : ${args}")
	list( SUBLIST ARGV 1 ARGC sublist)
	message( "Message : ${sublist} " )
endfunction()

test_func(print_message Hello World)
