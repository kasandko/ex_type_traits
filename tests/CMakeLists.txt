cmake_minimum_required(VERSION 3.5.1)
project(tests)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(TEST_LIB
    main.cpp
    tests.cpp
    tests.h
    )

set(HEADERS
    test_op_traits.h
    )

set(SOURCES
    test_op_traits.cpp
    )

add_executable(tests ${SOURCES} ${HEADERS} ${TEST_LIB})
