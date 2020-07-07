#include "./sphere.hpp"
#include "./math/geometric.hpp"

namespace objects
{
namespace hitables
{

sphere::sphere() : m_material{nullptr}
{ }

sphere::sphere(const math::vec3& cen, const math::real& r, base::material_interface* m)
	: m_center{cen}, m_radius{r}, m_material{m}
{ }

sphere::~sphere()
{ 
	m_material = nullptr;
}

bool sphere::hit(const math::ray& r, const math::real& t_min, const math::real& t_max, primitives::hit_record& rec) const
{
	math::vec3 oc = r.origin() - m_center;
	math::real a = math::dot(r.direction(), r.direction());
	math::real b = math::dot(oc, r.direction());
	math::real c = math::dot(oc, oc) - m_radius * m_radius;
	math::real discriminant = b * b - a * c;
	if (discriminant > 0.0f)
	{
		math::real temp = (-b - sqrt(discriminant)) / a;
		if (temp < t_max && temp > t_min)
		{
			rec.m_t = temp;
			rec.m_p = r.point_at_parameter(temp);
			rec.m_normal = (rec.m_p - m_center) / m_radius;
			rec.m_material = m_material;
			return true;
		}
		temp = (-b + sqrt(discriminant)) / a;
		if (temp < t_max && temp > t_min)
		{
			rec.m_t = temp;
			rec.m_p = r.point_at_parameter(temp);
			rec.m_normal = (rec.m_p - m_center) / m_radius;
			rec.m_material = m_material;
			return true;
		}
	}
	return false;
}

}//end hitables
}//end objects