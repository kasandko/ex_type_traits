cmake_minimum_required(VERSION 3.5.1)
project(ex_type_traits)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories("${PROJECT_SOURCE_DIR}/include")

add_subdirectory(tests)
