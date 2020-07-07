cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(ray_tracer_exe)

set(CMAKE_GENERATOR_PLATFORM x64)
include_directories(${CMAKE_SOURCE_DIR})

add_subdirectory(math)
add_subdirectory(utility)
add_subdirectory(objects)
add_subdirectory(render-application)

set(main_source_files
	main.cpp
)

add_executable(ray-tracer ${main_source_files})

target_link_libraries(ray-tracer renderer)