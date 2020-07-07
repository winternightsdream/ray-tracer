#ifndef _RENDER_APPLICATION_RENDERER_HPP_
#define _RENDER_APPLICATION_RENDERER_HPP_
#include "./scene.hpp"
#include "./camera.hpp"
#include "utility/threading/task.hpp"
#include <stdint.h>
#include <queue>

namespace render_application
{

typedef std::queue<utility::threading::Task> TaskList;

class renderer
{
public:
	renderer();
	~renderer();
	int render();
	void trace_ray(const uint32_t h_pixel, const uint32_t w_pixel);

private:

	inline int colour_ftoi(math::real f) const
	{
		return int(255.99f * f);
	}

	TaskList	m_tasks;
	math::vec3*	m_colour_buffer;
	scene 		m_scene;
	camera		m_camera;
	int 		m_width;
	int 		m_height;
	int			m_sample_count;
};

}// end render_application

#endif// _RENDER_APPLICATION_RENDERER_HPP_