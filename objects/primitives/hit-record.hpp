#ifndef OBJECTS_PRIMITIVES_HIT_RECORD_HPP_
#define OBJECTS_PRIMITIVES_HIT_RECORD_HPP_
#include "math/vec3.hpp"
#include "math/real.hpp"

namespace objects
{

namespace base
{
class material_interface;
}  // namespace base

namespace primitives
{

struct hit_record
{
    math::real                  m_t;
    math::vec3                  m_p;
    math::vec3                  m_normal;
    base::material_interface*   m_material;
};

}  // namespace primitives
}  // namespace objects

#endif  // OBJECTS_PRIMITIVES_HIT_RECORD_HPP_
