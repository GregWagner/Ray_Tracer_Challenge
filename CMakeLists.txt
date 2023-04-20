cmake_minimum_required(VERSION 3.16.0)

project(
  RayTracerChallenge
  VERSION 0.1.0.0
  LANGUAGES CXX
  DESCRIPTION "TDD Ray Tracer")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++17")
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(dependencies)

set(source_dir "${PROJECT_SOURCE_DIR}/src/")
set(tests_dir "${PROJECT_SOURCE_DIR}/tests/")

file(GLOB source_files "${source_dir}/*.cpp")
file(GLOB test_files "${tests_dir}/*.cpp")

add_executable(ray_tracer ${source_files} ${test_files})
