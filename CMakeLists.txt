cmake_minimum_required(VERSION 3.22)

set(DINOSAUR_PROJECT_NAME dinosaur)
set(DINOSAUR_SOURCE_DIR src)
set(DINOSAUR_SOURCE ${DINOSAUR_SOURCE_DIR}/main.cpp)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(DINOSAUR_PROJECT_VERSION 0.1)
set(DINOSAUR_LIBRARY_NAME core)
set(DINOSAUR_BINARY_NAME dinosaur)

include(cmake/UniversalAppleBuild.cmake)

project(
  ${DINOSAUR_PROJECT_NAME}
  VERSION ${DINOSAUR_PROJECT_VERSION}
  DESCRIPTION "A project for coding the book hands on cpp for machine learning"
  LANGUAGES CXX)

include(cmake/StandardProjectSettings.cmake)

#add_library(project_warnings INTERFACE)
#include(cmake/CompilerWarnings.cmake)
#set_project_warnings(project_warnings)


add_executable(${DINOSAUR_BINARY_NAME} src/main.cpp)
target_link_libraries(${DINOSAUR_BINARY_NAME} PUBLIC ${DINOSAUR_LIBRARY_NAME})
target_compile_features(${DINOSAUR_BINARY_NAME} PRIVATE cxx_std_20) 

include(packages.cmake)
add_subdirectory(src)
