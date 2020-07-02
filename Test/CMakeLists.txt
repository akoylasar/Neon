cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 11)

project(Neon.Test)

add_executable(${PROJECT_NAME}
  Test.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
  ${CMAKE_HOME_DIRECTORY}
  ${CMAKE_HOME_DIRECTORY}/../
)

if(MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
else()
  target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Werror -pedantic -Wconversion -pedantic-errors)
endif()
