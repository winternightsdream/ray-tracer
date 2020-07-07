set(materials_source_files
	dielectric.cpp
	dielectric.hpp
	lambertian.cpp
	lambertian.hpp
	metal.cpp
	metal.hpp
)

add_library(objects_materials ${materials_source_files})

target_link_libraries(objects_materials math utility)