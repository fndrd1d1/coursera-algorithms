cmake_minimum_required(VERSION 3.5)

set(BIN_NAME "hash_chaining")

project(Hash_Chaining)

set(CMAKE_CXX_FLAGS "-Wall -pipe -O2 -std=c++14 -lm")

add_executable(${BIN_NAME} hash_chaining.cpp)

add_custom_target(run
    COMMAND ${BIN_NAME} < ../input.txt
    COMMAND ${BIN_NAME} < ../input2.txt
    COMMAND ${BIN_NAME} < ../input3.txt
    DEPENDS ${BIN_NAME} 
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
