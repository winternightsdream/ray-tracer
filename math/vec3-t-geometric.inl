#ifndef _MATH_VEC3_T_GEOMETRIC_INL_ 
#define _MATH_VEC3_T_GEOMETRIC_INL_

namespace math
{

template<typename T>
inline std::istream& operator>>(std::istream& is, vec3_t<T>& t)
{
	is >> t.x >> t.y >> t.z;
	return is;
}

template<typename T>
inline std::ostream& operator<<(std::ostream& os, const vec3_t<T>& t)
{
	os << t.x << t.y << t.z;
	return os;
}

template<typename T>
inline vec3_t<T> operator+(const vec3_t<T>& v1, const vec3_t<T>& v2)
{
	return vec3_t<T>{v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
}

template<typename T>
inline vec3_t<T> operator-(const vec3_t<T>& v1, const vec3_t<T>& v2)
{
	return vec3_t<T>{v1.x - v2.x, v1.y - v2.y, v1.z - v2.z};
}

template<typename T>
inline vec3_t<T> operator*(const vec3_t<T>& v1, const vec3_t<T>& v2)
{
	return vec3_t<T>{v1.x * v2.x, v1.y * v2.y, v1.z * v2.z};
}

template<typename T>
inline vec3_t<T> operator/(const vec3_t<T>& v1, const vec3_t<T>& v2)
{
	return vec3_t<T>{v1.x / v2.x, v1.y / v2.y, v1.z / v2.z};
}

template<typename T>
inline vec3_t<T> operator*(T t, const vec3_t<T>& v)
{
	return vec3_t<T>{v.x * t, v.y * t, v.z * t};
}

template<typename T>
inline vec3_t<T> operator/(const vec3_t<T>& v, T t)
{
	return vec3_t<T>{v.x / t, v.y / t, v.z / t};
}

template<typename T>
inline vec3_t<T> operator*(const vec3_t<T>& v, T t)
{
	return vec3_t<T>{v.x * t, v.y * t, v.z * t};
}

template<typename T>
inline T dot(const vec3_t<T>& v1, const vec3_t<T>& v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

template<typename T>
inline vec3_t<T> cross(const vec3_t<T>& v1, const vec3_t<T>& v2)
{
	return vec3_t<T>{(v1.y * v2.z - v1.z * v2.z),
					(-(v1.x * v2.z - v1.z * v2.x)),
					(v1.x * v2.y - v1.y * v2.x)};
}

template<typename T>
inline vec3_t<T> normalize(const vec3_t<T>& v)
{
	return v / v.length();
}

template<typename T>
inline vec3_t<T> reflect(const vec3_t<T>& v, const vec3_t<T>& n)
{
	return v - T(2.0) * dot(v, n) * n;
}

template<typename T>
inline bool refract(const vec3_t<T>& v, const vec3_t<T>& n, T ni_over_nt, vec3_t<T>& refracted)
{
	vec3_t<T> uv = normalize(v);
	T dt = dot(uv, n);
	T discriminant = T(1.0) - ni_over_nt * ni_over_nt * (T(1.0) - dt * dt);
	if (discriminant > T(0.0))
	{
		refracted = ni_over_nt * (uv - n * dt) - n * std::sqrt(discriminant);
		return true;
	}
	return false;
}

}//end math

#endif//end _MATH_VEC3_T_GEOMETRIC_INL_