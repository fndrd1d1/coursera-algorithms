cmake_minimum_required(VERSION 3.5)

set(BIN_NAME "phone_book")

project(PhoneBook)

set(EXECUTABLE_OUTPUTPATH ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_CXX_FLAGS "-Wall -pipe -O2 -std=c++14 -lm")

add_executable(${BIN_NAME} phone_book.cpp)

add_custom_target(run
    COMMAND ${BIN_NAME} < ../input.txt
    DEPENDS ${BIN_NAME} 
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
