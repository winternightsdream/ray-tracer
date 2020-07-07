#ifndef _OBJECTS_MATERIALS_LAMBERTIAN_H_
#define _OBJECTS_MATERIALS_LAMBERTIAN_H_
#include "objects/base/material-interface.hpp"

namespace objects
{
namespace materials
{

class lambertian : public base::material_interface
{
public:
	lambertian(const math::vec3& a);
	virtual bool scatter(const math::ray& r_in, const primitives::hit_record& rec, math::vec3& attenuation, math::ray& scattered) const;

private:
	math::vec3 m_albedo;
};

}//end materials
}//end objects

#endif//end _OBJECTS_MATERIALS_LAMBERTIAN_H_