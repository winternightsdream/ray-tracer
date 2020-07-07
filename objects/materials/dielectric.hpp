#ifndef _OBJECTS_MATERIALS_DIELECTRIC_H_
#define _OBJECTS_MATERIALS_DIELECTRIC_H_
#include "objects/base/material-interface.hpp"

namespace objects
{
namespace materials
{

class dielectric : public base::material_interface
{
public:
	dielectric(math::real ri);
	virtual bool scatter(const math::ray& r_in, const primitives::hit_record& rec, math::vec3& attenuation, math::ray& scattered) const;

private:
	math::real	m_ref_index;
};

}//end materials
}//end objects

#endif//end _OBJECTS_MATERIALS_DIELECTRIC_H_