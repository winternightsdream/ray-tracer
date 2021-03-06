#ifndef MATH_VEC3_T_GEOMETRIC_HPP_
#define MATH_VEC3_T_GEOMETRIC_HPP_
#include <iostream>
#include "./vec3-t.hpp"

namespace math
{

template<typename T>
inline std::istream& operator>>(std::istream& is, vec3_t<T>& t);

template<typename T>
inline std::ostream& operator<<(std::ostream& os, const vec3_t<T>& t);

template<typename T>
inline vec3_t<T> operator+(const vec3_t<T>& v1, const vec3_t<T>& v2);

template<typename T>
inline vec3_t<T> operator-(const vec3_t<T>& v1, const vec3_t<T>& v2);

template<typename T>
inline vec3_t<T> operator*(const vec3_t<T>& v1, const vec3_t<T>& v2);

template<typename T>
inline vec3_t<T> operator/(const vec3_t<T>& v1, const vec3_t<T>& v2);

template<typename T>
inline vec3_t<T> operator*(const T& t, const vec3_t<T>& v);

template<typename T>
inline vec3_t<T> operator/(const vec3_t<T>& v, const T& t);

template<typename T>
inline vec3_t<T> operator*(const vec3_t<T>& v, const T& t);

template<typename T>
inline T dot(const vec3_t<T>& v1, const vec3_t<T>& v2);

template<typename T>
inline vec3_t<T> cross(const vec3_t<T>& v1, const vec3_t<T>& v2);

template<typename T>
inline vec3_t<T> normalize(const vec3_t<T>& v);

template<typename T>
inline vec3_t<T> reflect(const vec3_t<T>& v, const vec3_t<T>& n);

template<typename T>
inline bool refract(const vec3_t<T>& v, const vec3_t<T>& n, const T& ni_over_nt, vec3_t<T>& refracted);

}  // namespace math

#include "./vec3-t-geometric.inl"
#endif  // MATH_VEC3_T_GEOMETRIC_HPP_
