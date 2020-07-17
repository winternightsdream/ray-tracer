#ifndef OBJECTS_MATERIALS_METAL_HPP_
#define OBJECTS_MATERIALS_METAL_HPP_
#include "objects/base/material-interface.hpp"

namespace objects
{
namespace materials
{

class metal : public base::material_interface
{
public:
    metal(const math::vec3& a, const math::real& f);
    bool scatter(const math::ray& r_in, const primitives::hit_record& rec, math::vec3& attenuation, math::ray& scattered) const override;

private:
    math::vec3  m_albedo;
    math::real  m_fuzz;
};

}  // namespace materials
}  // namespace objects

#endif  // OBJECTS_MATERIALS_METAL_HPP_
