find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

#[==[
This add another buil target, which is test for Makefile generators,
or RUN_TESTS for integrated development enviorments
]==]#

enable_testing()

function(custom_add_test test_name include_dir target_binary)
	
	math( EXPR executable_argc "${ARGC} - 2")
	
	#[==[
		list(SUBLIST <list> <begin> <length> <output varialbe>)

		Retures a sublist of the given list, if length is 0, an empty list will be returned.
		if length is a -1 or smaller than <begin>+<length> than
		the remaing elemnts of the list start at begin
	]==]#
	list( SUBLIST ARGV 2 -1 executable_list )
	#message( FATAL_ERROR "MSG : ${ARGV}")
	
	add_executable( ${test_name} ${executable_list})
	
	target_include_directories( ${test_name}
		PUBLIC
			${include_dir}
		PRIVATE
			${CMAKE_SOURCE_DIR}/src/include
	)
		

	target_link_libraries( ${test_name}
		${GTEST_BOTH_LIBRARIES}
		Threads::Threads
	)

	add_test(
		NAME ${test_name}
		COMMAND ${test_name}
	)
	
endfunction()

function(custom_add_library_test test_name include_dir target_libraries)
	
	math( EXPR executable_argc "${ARGC} - 3")
	list( SUBLIST ARGV 3 -1 executable_list )

	add_executable( ${test_name} ${executable_list})

	target_include_directories( ${test_name}
		PUBLIC
			${include_dir}
		PRIVATE
			${CMAKE_SOURCE_DIR}/src/include)


	target_link_libraries( ${test_name}
# 		PUBLIC
# 			${target_libraries}
		PUBLIC
			${GTEST_BOTH_LIBRARIES}
			Threads::Threads
	)

	add_test(
		NAME ${test_name}
		COMMAND ${test_name}
	)

endfunction()

function(custom_add_library_test test_name include_dir target_libraries)
	
	math( EXPR executable_argc "${ARGC} - 3")
	list( SUBLIST ARGV 3 -1 executable_list )

	add_executable( ${test_name} ${executable_list})

	target_include_directories( ${test_name}
		PUBLIC
			${include_dir}
		PRIVATE
			${CMAKE_SOURCE_DIR}/src/include)


	target_link_libraries( ${test_name}
# 		PUBLIC
# 			${target_libraries}
		PUBLIC
			${GTEST_BOTH_LIBRARIES}
			Threads::Threads
	)

	add_test(
		NAME ${test_name}
		COMMAND ${test_name}
	)

endfunction()