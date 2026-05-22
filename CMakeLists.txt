cmake_minimum_required(VERSION 3.20)

project(hi_3 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

function(add_utf8_executable target source)
    add_executable(${target} ${source})

    if (MSVC)
        target_compile_options(${target} PRIVATE /utf-8)
    else()
        target_compile_options(${target} PRIVATE -finput-charset=UTF-8 -fexec-charset=UTF-8)
    endif()
endfunction()

add_utf8_executable(record_app "1.cpp")
add_utf8_executable(school_app "school.cpp")
add_utf8_executable(test_app "test.cpp")
add_utf8_executable(text_app "text.cpp")

