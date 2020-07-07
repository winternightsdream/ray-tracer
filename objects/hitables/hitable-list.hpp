#ifndef _OBJECTS_HITABLES_HITABLE_LIST_HPP_
#define _OBJECTS_HITABLES_HITABLE_LIST_HPP_
#include "objects/base/hitable-interface.hpp"
#include "math/real.hpp"

namespace objects
{
namespace hitables
{

class hitable_list : public base::hitable_interface
{
public:

	hitable_list();
	hitable_list(base::hitable_interface** l, const int& s);
	virtual ~hitable_list();

	virtual bool hit(const math::ray& r, const math::real& t_min, const math::real& t_max, primitives::hit_record& rec) const override;

private:

	base::hitable_interface**	m_list;
	int							m_list_size;
};

}//end hitables
}//end objects

#endif//end _OBJECTS_HITABLES_HITABLE_LIST_HPP_