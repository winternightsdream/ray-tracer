#ifndef _OBJECTS_HITABLES_SPHERE_HPP_
#define _OBJECTS_HITABLES_SPHERE_HPP_
#include "objects/base/hitable-interface.hpp"

namespace objects
{
namespace hitables
{

class sphere : public base::hitable_interface
{
public:

	sphere();
	sphere(const math::vec3& cen, const math::real& r, base::material_interface* m);
	virtual ~sphere();

	virtual bool hit(const math::ray& r, const math::real& t_min, const math::real& t_max, primitives::hit_record& rec) const override;

private:

	math::vec3 m_center;
	math::real m_radius;

	base::material_interface*	m_material;
};

}//end hitables
}//end objects

#endif//end _OBJECTS_HITABLES_SPHERE_HPP_