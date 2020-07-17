#include "objects/hitables/hitable-list.hpp"

namespace objects
{
namespace hitables
{

hitable_list::hitable_list()
{ }

hitable_list::hitable_list(hitable_interface** l, const int& s)
    : m_list{l}, m_list_size{s}
{ }

hitable_list::~hitable_list()
{ }

bool hitable_list::hit(const math::ray& r, const math::real& t_min, const math::real& t_max, primitives::hit_record& rec) const
{
    primitives::hit_record temp_rec;
    bool hit_anything = false;
    math::real closest_so_far = math::REAL_MAX;
    for (int i = 0; i < m_list_size; ++i)
    {
        if (m_list[i]->hit(r, t_min, closest_so_far, temp_rec))
        {
            hit_anything = true;
            closest_so_far = temp_rec.m_t;
            rec = temp_rec;
        }
    }
    return hit_anything;
}

}  // namespace hitables
}  // namespace objects
