cmake_minimum_required (VERSION 3.5)

project (RayTracerChallenge)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")
set (tests_dir "${PROJECT_SOURCE_DIR}/tests/")

file (GLOB source_files "${source_dir}/*.cpp")
file (GLOB test_files "${tests_dir}/*.cpp")

add_executable (ray_tracer ${source_files} ${test_files})
