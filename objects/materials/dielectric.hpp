#ifndef OBJECTS_MATERIALS_DIELECTRIC_HPP_
#define OBJECTS_MATERIALS_DIELECTRIC_HPP_
#include "objects/base/material-interface.hpp"

namespace objects
{
namespace materials
{

class dielectric : public base::material_interface
{
public:
    explicit dielectric(const math::real& ri);
    bool scatter(const math::ray& r_in, const primitives::hit_record& rec, math::vec3& attenuation, math::ray& scattered) const override;

private:
    math::real  m_ref_index;
};

}  // namespace materials
}  // namespace objects

#endif  // OBJECTS_MATERIALS_DIELECTRIC_HPP_
