cmake_minimum_required (VERSION 3.1)

project (clparser VERSION 0.0.0.1 LANGUAGES CXX)

add_executable (${PROJECT_NAME})

target_sources (${PROJECT_NAME} 
	PUBLIC 
		${CMAKE_CURRENT_LIST_DIR}/main.cpp
		${CMAKE_CURRENT_LIST_DIR}/clparser.h
)
		

