#ifndef RENDER_APPLICATION_CAMERA_HPP_
#define RENDER_APPLICATION_CAMERA_HPP_
#include "math/ray.hpp"

namespace render_application
{

class camera
{
public:
    camera();
    camera(const math::vec3& look_from, const math::vec3& look_to, const math::vec3& vup,
           const math::real& vfov, const math::real& aspect, const math::real& aperture, const math::real& focus_dist,
           const math::real& t0, const math::real& t1);
    math::ray get_ray(const math::real& u, const math::real& v) const;

private:
    math::vec3  m_origin;
    math::vec3  m_lower_left_corner;
    math::vec3  m_horizontal;
    math::vec3  m_vertical;
    math::vec3  m_u;
    math::vec3  m_v;
    math::vec3  m_w;
    math::real  m_lens_radius;
    math::real  m_start_time;
    math::real  m_end_time;
};

}  // namespace render_application

#endif  // RENDER_APPLICATION_CAMERA_HPP_
