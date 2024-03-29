cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 17)
project(ParserCSV)
set(exe_name ${PROJECT_NAME})
set(test_name test)

if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()


add_library(corelib OBJECT print_tuple.h parser_csv.h)

add_executable(${exe_name} main.cpp)
target_link_libraries(${exe_name} corelib)


include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/58d77fa8070e8cec2dc1ed015d66b454c8d78850.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(${test_name} test.cpp)
target_link_libraries(${test_name} gtest_main)
target_link_libraries(${test_name} corelib)