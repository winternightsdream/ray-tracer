set(hitables_source_files
	hitable-list.cpp
	hitable-list.hpp
	moving-sphere.cpp
	moving-sphere.hpp
	sphere.cpp
	sphere.hpp
)

add_library(objects_hitables ${hitables_source_files})

target_link_libraries(objects_hitables math)