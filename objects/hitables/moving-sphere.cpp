#include "objects/hitables/moving-sphere.hpp"
#include "math/geometric.hpp"

namespace objects
{
namespace hitables
{

moving_sphere::moving_sphere() : m_material_p{nullptr}
{ }

moving_sphere::moving_sphere(const math::vec3& cen0, const math::vec3& cen1,
                             const math::real& ti0, const math::real& ti1, const math::real& radius,
                             base::material_interface* mat_p)
                             : m_center0{cen0}, m_center1{cen1}, m_time0{ti0}, m_time1{ti1},
                               m_radius{radius}, m_material_p{mat_p}
{ }

bool moving_sphere::hit(const math::ray& r, const math::real& t_min, const math::real& t_max, primitives::hit_record& rec) const
{
    math::vec3 oc = r.origin() - center(r.time());
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
            rec.m_normal = (rec.m_p - center(r.time())) / m_radius;
            rec.m_material = m_material_p;
            return true;
        }
        temp = (-b + sqrt(discriminant)) / a;
        if (temp < t_max && temp > t_min)
        {
            rec.m_t = temp;
            rec.m_p = r.point_at_parameter(temp);
            rec.m_normal = (rec.m_p - center(r.time())) / m_radius;
            rec.m_material = m_material_p;
            return true;
        }
    }
    return false;
}

math::vec3 moving_sphere::center(const math::real& time) const
{
    return m_center0 + ((time - m_time0) / (m_time1 - m_time0)) * (m_center1 - m_center0);
}

}  // namespace hitables
}  // namespace objects
