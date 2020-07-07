#ifndef _OBJECTS_HITABLES_MOVING_SPHERE_HPP_
#define _OBJECTS_HITABLES_MOVING_SPHERE_HPP_
#include "math/vec3.hpp"
#include "objects/base/hitable-interface.hpp"
#include "objects/base/material-interface.hpp"

namespace objects
{
namespace hitables
{

class moving_sphere : public base::hitable_interface
{
public:

	moving_sphere();
	moving_sphere(const math::vec3& cen0, const math::vec3& cen1, 
				  const math::real& ti0, const math::real& ti1, const math::real& radius, 
				  base::material_interface* mat_p);

	virtual bool hit(const math::ray& r, const math::real& t_min, const math::real& t_max, primitives::hit_record& rec) const;

	math::vec3 center(const math::real& time) const;

private:

	math::vec3 	m_center0;
	math::vec3 	m_center1;
	math::real	m_time0;
	math::real	m_time1;
	math::real	m_radius;

	base::material_interface* m_material_p;
};

}//end hitables
}//end objects

#endif// end _OBJECTS_HITABLES_MOVING_SPHERE_HPP_