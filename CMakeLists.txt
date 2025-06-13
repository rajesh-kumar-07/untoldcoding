cmake_minimum_required(VERSION 3.10)
project(internship_api)

set(CMAKE_CXX_STANDARD 17)

add_executable(internship-api
    main.cpp
)

add_subdirectory(crow)
target_include_directories(internship-api PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/routes 
    ${CMAKE_CURRENT_SOURCE_DIR}/models 
    ${CMAKE_CURRENT_SOURCE_DIR}/db
)

target_link_libraries(internship-api crow)