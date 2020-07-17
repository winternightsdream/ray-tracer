#ifndef OBJECTS_MATERIALS_LAMBERTIAN_HPP_
#define OBJECTS_MATERIALS_LAMBERTIAN_HPP_
#include "objects/base/material-interface.hpp"

namespace objects
{
namespace materials
{

class lambertian : public base::material_interface
{
public:
    explicit lambertian(const math::vec3& a);
    bool scatter(const math::ray& r_in, const primitives::hit_record& rec, math::vec3& attenuation, math::ray& scattered) const override;

private:
    math::vec3 m_albedo;
};

}  // namespace materials
}  // namespace objects

#endif  // OBJECTS_MATERIALS_LAMBERTIAN_HPP_
