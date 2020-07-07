#ifndef _OBJECTS_BASE_MATERIAL_INTERFACE_HPP_
#define _OBJECTS_BASE_MATERIAL_INTERFACE_HPP_
#include "math/ray.hpp"
#include "objects/primitives/hit-record.hpp"

namespace objects
{
namespace base
{

class material_interface
{
public:
	virtual ~material_interface() {}
	virtual bool scatter(const math::ray& r_in, const primitives::hit_record& rec, math::vec3& attenuation, math::ray& scattered) const = 0;
};

}//end base
}//end objects

#endif//end _OBJECTS_BASE_MATERIAL_INTERFACE_HPP_