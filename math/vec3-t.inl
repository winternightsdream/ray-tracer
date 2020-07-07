#ifndef _MATH_VEC3_T_INL_
#define _MATH_VEC3_T_INL_
#include <math.h>

namespace math
{

template<typename T>
inline vec3_t<T>::vec3_t() 
	: m_elements{T(0.0), T(0.0), T(0.0)}
{}

template<typename T>
inline vec3_t<T>::vec3_t(T f)
	: m_elements{f, f, f}
{}

template<typename T>
inline vec3_t<T>::vec3_t(T e0, T e1, T e2)
	: m_elements{e0, e1, e2}
{}

template<typename T>
inline vec3_t<T>& vec3_t<T>::operator=(const vec3_t<T>& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}

template<typename T>
inline const vec3_t<T>& vec3_t<T>::operator+() const
{
	return *this;
}

template<typename T>
inline vec3_t<T> vec3_t<T>::operator-() const
{
	return vec3_t<T>{-x, -y, -z};
}

template<typename T>
inline T vec3_t<T>::operator[](int i) const
{
	return m_elements[i];
}

template<typename T>
inline T& vec3_t<T>::operator[](int i)
{
	return m_elements[i];
}

template<typename T>
inline vec3_t<T>& vec3_t<T>::operator+=(const vec3_t<T>& v2)
{
	x += v2.x;
	y += v2.y;
	z += v2.z;
	return *this;
}

template<typename T>
inline vec3_t<T>& vec3_t<T>::operator-=(const vec3_t<T>& v2)
{
	x -= v2.x;
	y -= v2.y;
	z -= v2.z;
	return *this;
}

template<typename T>
inline vec3_t<T>& vec3_t<T>::operator*=(const vec3_t<T>& v2)
{
	x *= v2.x;
	y *= v2.y;
	z *= v2.z;
	return *this;
}

template<typename T>
inline vec3_t<T>& vec3_t<T>::operator/=(const vec3_t<T>& v2)
{
	x /= v2.x;
	y /= v2.y;
	z /= v2.z;
	return *this;
}

template<typename T>
inline vec3_t<T>& vec3_t<T>::operator*=(const T s)
{
	x *= s;
	y *= s;
	z *= s;
	return *this;
}

template<typename T>
inline vec3_t<T>& vec3_t<T>::operator/=(const T s)
{
	T k = T(1.0) / s;
	x *= k;
	y *= k;
	z *= k;
	return *this;
}

template<typename T>
inline T vec3_t<T>::length() const 
{
	return sqrt(x * x + y * y + z * z);
}

template<typename T>
inline T vec3_t<T>::squared_length() const 
{
	return x * x + y * y + z * z;
}

template<typename T>
inline void vec3_t<T>::normalize()
{
	T k = T(1.0) / length();
	x *= k;
	y *= k;
	z *= k;
}

}//end math

#endif//end _MATH_VEC3_T_INL_