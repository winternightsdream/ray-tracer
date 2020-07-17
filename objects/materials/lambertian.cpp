#include "objects/materials/lambertian.hpp"
#include "math/geometric.hpp"
#include "utility/random.hpp"

namespace objects
{
namespace materials
{

lambertian::lambertian(const math::vec3& a)
    : m_albedo{a}
{}

bool lambertian::scatter(const math::ray& r_in, const primitives::hit_record& rec, math::vec3& attenuation, math::ray& scattered) const
{
    math::vec3 target = rec.m_p + rec.m_normal + utility::random::random_in_sphere();
    scattered = math::ray{rec.m_p, target - rec.m_p, r_in.time()};
    attenuation = m_albedo;
    return true;
}

}  // namespace materials
}  // namespace objects
