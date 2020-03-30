cmake_minimum_required(VERSION 3.14)

project(ov2math LANGUAGES CXX VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(build_config/version.hpp.in version.hpp)

add_library(ov2math 
	src/ov2math/ov2math.cpp
	src/ov2math/vector2.hpp
)

target_include_directories(ov2math PUBLIC
	"${PROJECT_BINARY_DIR}"
)

#--------------------------------------------------------------------------------------
project(ov2math_tests LANGUAGES CXX)

add_executable(ov2math_tests 
	./src/ov2math_tests/ov2math_tests.cpp
)

target_include_directories(ov2math_tests PUBLIC
	.
)







