# Require latest cmake
cmake_minimum_required( VERSION 3.4 )

# Name the project
project( mesh )

# Enable C++11 goodness
set( CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++11 )

# Designate sources
set( mesh_sources main.cpp )

# Name the executable
add_executable( mesh ${cpp_sources} )

