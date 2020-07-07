#include "./camera.hpp"
#include "math/algorithm.hpp"
#include "math/geometric.hpp"
#include "utility/random.hpp"

namespace render_application
{

camera::camera()
{}

camera::camera(const math::vec3& look_from, const math::vec3& look_to, const math::vec3& vup,
			   const math::real& vfov, const math::real& aspect, const math::real& aperture, const math::real& focus_dist,
			   const math::real& t0, const math::real& t1)
	: m_origin{look_from}, m_start_time{t0}, m_end_time{t1}
{
	m_lens_radius = aperture / 2.0f;

	math::real theta = math::degree_to_radians(vfov);
	math::real half_height = tan(theta / 2.0f);
	math::real half_width = aspect * half_height;

	m_w = math::normalize(look_from - look_to);
	m_u = math::normalize(math::cross(vup, m_w));
	m_v = math::cross(m_w, m_u);

	m_lower_left_corner = m_origin - half_width * focus_dist * m_u - half_height * focus_dist * m_v - focus_dist * m_w;
	m_horizontal = 2.0f * half_width * focus_dist * m_u;
	m_vertical = 2.0f * half_height * focus_dist * m_v;
}

math::ray camera::get_ray(const math::real& s, const math::real& t) const
{
	math::vec3 rd = m_lens_radius * utility::random::random_in_unit_disk();
	math::vec3 offset = m_u * rd.x + m_v * rd.y;
	math::real time = m_start_time + math::random_real() * (m_end_time - m_start_time);
	return math::ray{m_origin + offset, m_lower_left_corner + s * m_horizontal + t * m_vertical - m_origin - offset, time};
}

}// end render_application