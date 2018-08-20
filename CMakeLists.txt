cmake_minimum_required(VERSION 3.5)
project(file-descriptor)

option(FILE_DESCRIPTOR_TESTS "Run unit tests" OFF)
if(FILE_DESCRIPTOR_TESTS)
  add_subdirectory(test)
endif()

file(GLOB srcs src/*.cpp)
add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE include)
target_sources(${PROJECT_NAME} INTERFACE ${srcs})
