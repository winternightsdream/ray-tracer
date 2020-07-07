set(render_app_source_files
	camera.cpp
	camera.hpp
	renderer.cpp
	renderer.hpp
	scene.cpp
	scene.hpp
)

add_library(renderer ${render_app_source_files})

target_link_libraries(renderer objects_hitables objects_materials threading)