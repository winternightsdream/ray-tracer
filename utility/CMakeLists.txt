set(utility_source_files
	random.cpp
	random.hpp
)

add_subdirectory(threading)

add_library(utility ${utility_source_files})