#ifndef _MATH_RAY_HPP_
#define _MATH_RAY_HPP_
#include "./vec3.hpp"

namespace math
{

class ray
{
public:

	ray();
	ray(const vec3& a, const vec3& b, const real& ti = 0.0f);

	vec3 origin() const;
	vec3 direction() const;
	real time() const;
	vec3 point_at_parameter(const real& t) const;

	vec3  A;
	vec3  B;
	real m_time;
};

}//end math

#endif//end _MATH_RAY_HPP_