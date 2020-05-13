cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(simpleLogger)

include_directories(${PROJECT_SOURCE_DIR}/include)

set (SOURCE_FILES 
  src/logger.cpp
)


set(libraryName "slog")
add_library(${libraryName} ${SOURCE_FILES})


if(EXISTS ${PROJECT_SOURCE_DIR}/testing)
  add_subdirectory(${PROJECT_SOURCE_DIR}/testing)
endif(EXISTS ${PROJECT_SOURCE_DIR}/testing)