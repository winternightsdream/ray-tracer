#ifndef _MATH_VEC3_T_HPP_
#define _MATH_VEC3_T_HPP_

namespace math
{

template<typename T>
class vec3_t
{
public:

	inline vec3_t();
	inline vec3_t(T f);
	inline vec3_t(T e0, T e1, T e2);
	inline vec3_t<T>& operator=(const vec3_t<T>& v);

	inline const vec3_t<T>& operator+() const;
	inline vec3_t<T> operator-() const;
	inline T operator[](int i) const;
	inline T& operator[](int i);

	inline vec3_t<T>& operator+=(const vec3_t<T>& v2);
	inline vec3_t<T>& operator-=(const vec3_t<T>& v2);
	inline vec3_t<T>& operator*=(const vec3_t<T>& v2);
	inline vec3_t<T>& operator/=(const vec3_t<T>& v2);
	inline vec3_t<T>& operator*=(const T s);
	inline vec3_t<T>& operator/=(const T s);

	inline T length() const;
	inline T squared_length() const;
	inline void normalize();
	
	union 
	{
		struct { T x, y, z; };
		struct { T r, g, b; };
		struct { T m_elements[3]; };
	};
};

}//end math

#include "./vec3-t.inl"
#endif//end _MATH_VEC3_T_HPP_