#ifndef _OBJECTS_BASE_HITABLE_INTERFACE_HPP_
#define _OBJECTS_BASE_HITABLE_INTERFACE_HPP_
#include "math/ray.hpp"
#include "objects/primitives/hit-record.hpp"

namespace objects
{
namespace base
{

class hitable_interface
{
public:
	virtual ~hitable_interface() {}
	virtual bool hit(const math::ray& r, const math::real& t_min, const math::real& t_max, primitives::hit_record& rec) const = 0;
};

}//end base
}//end objects

#endif//end _OBJECTS_BASE_HITABLE_INTERFACE_HPP_