cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 17)

project(SoundProcessor)

set(exe_name ${PROJECT_NAME})

set(test_name test)

if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

add_library(corelib OBJECT lib/CommandParser.cpp lib/ConfigParser.cpp lib/WAV.cpp lib/Converters.cpp lib/SoundProcessor.cpp)

add_executable(${exe_name} main.cpp)
target_link_libraries(${exe_name} corelib)