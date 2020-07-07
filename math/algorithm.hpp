#ifndef _MATH_ALGORITHM_HPP_
#define _MATH_ALGORITHM_HPP_
#include "./constants.hpp"

namespace math
{

template<typename T>
inline const T& clamp(const T& v, const T& lo, const T& hi)
{
	return lo > v ? lo : hi < v ? hi : v;
}

template<typename T>
inline T schlick(T cosine, T ref_idx)
{
	T r0 = (T(1.0) - ref_idx) / (T(1.0) + ref_idx);
	r0 *= r0;
	return r0 + (T(1.0) - r0) * pow((T(1.0) - cosine), 5);
}

template<typename T>
constexpr T degree_to_radians(T angle)
{
	return angle * T(LD_PI) / T(180.0);
}

}//end math

#endif//end _MATH_ALGORITHM_HPP_