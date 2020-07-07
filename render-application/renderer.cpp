#include "./renderer.hpp"
#include <iostream>
#include <fstream>
#include "math/geometric.hpp"
#include "objects/hitables/sphere.hpp"
#include "utility/random.hpp"
#include "utility/threading/task.hpp"

namespace render_application
{

renderer::renderer()
	: m_colour_buffer{nullptr}, m_width{1920}, m_height{1080}, m_sample_count{20}
{
	math::vec3 look_from{-3.0f, 2.0f, 2.0f};
	math::vec3 look_at{0.0f, 0.0f, -1.0f};
	math::real dist_to_focus = (look_from - look_at).length();

	m_camera = camera{
		look_from,
		look_at,
		math::vec3{0.0f, 1.0f, 0.0f},
		90.0f,
		math::real(m_width)/math::real(m_height),
		0.25f,
		dist_to_focus,
		0.0,
		0.0
	};

	m_colour_buffer = new math::vec3[m_width * m_height];
}

renderer::~renderer()
{
	delete[] m_colour_buffer;
	m_colour_buffer = nullptr;
}

int renderer::render()
{
	int32_t height_index;
	int32_t width_index;
	//m_scene.init_material_spheres();
	//m_scene.init_test_spheres();
	m_scene.init_random_scene();
	for (height_index = m_height - 1; height_index >= 0; --height_index)
	{
		for (width_index = 0; width_index < m_width; ++width_index)
		{
			m_tasks.emplace(utility::threading::Task{[=]{ trace_ray(height_index, width_index); }});
			m_tasks.back().start();
		}
	}

	while (!m_tasks.empty())
	{
		if (m_tasks.front().is_done())
			m_tasks.pop();
	}

	std::ofstream out_file("image.ppm");
	if (!out_file.is_open())
	{
		std::cout << "error opening file, terminiating execution" << std::endl;
		return 1;
	}

	out_file << "P3\n" << m_width << " " << m_height <<"\n255\n";
	uint32_t num_pixels = m_height * m_width;
	for (uint32_t i = 0; i < num_pixels; ++i)
	{
		out_file << colour_ftoi(m_colour_buffer[i].r) << " " 
				 << colour_ftoi(m_colour_buffer[i].g) << " " 
				 << colour_ftoi(m_colour_buffer[i].b) << "\n";
	}
	out_file.close();
	return 0;
}

void renderer::trace_ray(const uint32_t h_pixel, const uint32_t w_pixel)
{
	uint32_t sample_index;
	math::real u;
	math::real v;
	math::ray r;
	math::vec3 colour{};

	for (sample_index = 0; sample_index < m_sample_count; ++sample_index)
	{
		u = math::real(w_pixel + math::random_real()) / math::real(m_width);
		v = math::real(h_pixel + math::random_real()) / math::real(m_height);

		r = m_camera.get_ray(u, v);
		colour += m_scene.colour(r);
	}
	colour /= math::real(m_sample_count);
	colour = math::vec3{sqrt(colour.r), sqrt(colour.g), sqrt(colour.b)};

	uint32_t h_index = (m_height - 1) - h_pixel;
	m_colour_buffer[(h_index * m_width) + w_pixel] = colour;
}

}// end render_application