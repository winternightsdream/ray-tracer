#include "./ray.hpp"
#include "./geometric.hpp"

namespace math
{

ray::ray()
{}

ray::ray(const vec3& a, const vec3& b, const real& ti)
	: A{a}, B{b}, m_time{ti}
{}

vec3 ray::origin() const
{
	return A;
}

vec3 ray::direction() const
{
	return B;
}

real ray::time() const
{
	return m_time;
}

vec3 ray::point_at_parameter(const real& t) const 
{
	return A + t * B;
}

}//end math