#ifndef RENDER_APPLICATION_RENDERER_HPP_
#define RENDER_APPLICATION_RENDERER_HPP_
#include <stdint.h>
#include <queue>
#include "./scene.hpp"
#include "./camera.hpp"
#include "utility/threading/task.hpp"

namespace render_application
{

typedef std::queue<utility::threading::Task> TaskList;

class renderer
{
 public:
    renderer();
    ~renderer();
    int render();
    void trace_ray(const uint32_t& h_pixel, const uint32_t& w_pixel);

 private:
    inline int32_t colour_ftoi(const math::real& f) const
    {
        return static_cast<int32_t>(255.99f * f);
    }

    TaskList    m_tasks;
    math::vec3* m_colour_buffer;
    scene       m_scene;
    camera      m_camera;
    int         m_width;
    int         m_height;
    int         m_sample_count;
};

}  // namespace render_application

#endif  // RENDER_APPLICATION_RENDERER_HPP_
