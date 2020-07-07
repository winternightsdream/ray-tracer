#ifndef _OBJECTS_MATERIALS_METAL_H_
#define _OBJECTS_MATERIALS_METAL_H_
#include "objects/base/material-interface.hpp"

namespace objects
{
namespace materials
{

class metal : public base::material_interface
{
public:
	metal(const math::vec3& a, math::real f);
	virtual bool scatter(const math::ray& r_in, const primitives::hit_record& rec, math::vec3& attenuation, math::ray& scattered) const;

private:
	math::vec3 	m_albedo;
	math::real	m_fuzz;
};

}//end materials
}//end objects

#endif//end _OBJECTS_MATERIALS_METAL_H_