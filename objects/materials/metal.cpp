#include "./metal.hpp"
#include <algorithm>
#include "math/algorithm.hpp"
#include "math/geometric.hpp"
#include "utility/random.hpp"

namespace objects
{
namespace materials
{

metal::metal(const math::vec3& a, math::real f)
	: m_albedo{a}
{
	m_fuzz = math::clamp(f, 0.0f, 1.0f);
}

bool metal::scatter(const math::ray& r_in, const primitives::hit_record& rec, math::vec3& attenuation, math::ray& scattered) const
{
	math::vec3 reflected = math::reflect(math::normalize(r_in.direction()), rec.m_normal);
	scattered = math::ray{rec.m_p, reflected + m_fuzz * utility::random::random_in_sphere(), r_in.time()};
	attenuation = m_albedo;
	return math::dot(scattered.direction(), rec.m_normal) > 0.0f;
}

}//end materials
}//end objects