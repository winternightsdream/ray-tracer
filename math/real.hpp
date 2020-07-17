#ifndef MATH_REAL_HPP_
#define MATH_REAL_HPP_
#include "./vec3-t.hpp"
#include "./constants.hpp"

namespace math
{

#ifdef __DOUBLE_REAL
typedef double real;
#else  // __DOUBLE_REAL
#include <cfloat>
typedef float real;
constexpr real REAL_MAX = FLT_MAX;
constexpr real REAL_PI = F_PI;
#endif

/**
 * random real [0,1)
 */
real random_real();
real random_real(const real& max);
real random_real(const real& min, const math::real& max);

}  // namespace math

#endif  // MATH_REAL_HPP_
