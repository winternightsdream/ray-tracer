#include "./dielectric.hpp"
#include "math/algorithm.hpp"
#include "math/geometric.hpp"
#include "utility/random.hpp"

namespace objects
{
namespace materials
{

dielectric::dielectric(math::real ri)
	: m_ref_index{ri}
{}

bool dielectric::scatter(const math::ray& r_in, const primitives::hit_record& rec, math::vec3& attenuation, math::ray& scattered) const
{
	math::vec3 reflected = math::reflect(r_in.direction(), rec.m_normal);
	attenuation = math::vec3{1.0f};
	math::vec3 outward_normal;
	math::vec3 refracted;
	math::real ni_over_nt;
	math::real reflect_prob;
	math::real cosine;
	if (math::dot(r_in.direction(), rec.m_normal) > 0.0f)
	{
		outward_normal = -rec.m_normal;
		ni_over_nt = m_ref_index;
		cosine = m_ref_index * math::dot(r_in.direction(), rec.m_normal) / r_in.direction().length();
	}
	else
	{
		outward_normal = rec.m_normal;
		ni_over_nt = 1.0f / m_ref_index;
		cosine = -math::dot(r_in.direction(), rec.m_normal) /r_in.direction().length();
	}
	if (math::refract(r_in.direction(), outward_normal, ni_over_nt, refracted))
		reflect_prob = math::schlick(cosine, m_ref_index);
	else
		reflect_prob = 1.0f;
	if (math::random_real() < reflect_prob)
		scattered = math::ray{rec.m_p, reflected, r_in.time()};
	else
		scattered = math::ray{rec.m_p, refracted, r_in.time()};
	return true;
}

}//end materials
}//end objects