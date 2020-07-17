#ifndef MATH_VEC3_T_HPP_
#define MATH_VEC3_T_HPP_

namespace math
{

template<typename T>
class vec3_t
{
 public:
    inline vec3_t();
    inline explicit vec3_t(const T& f);
    inline explicit vec3_t(const T& e0, const T& e1, const T& e2);
    inline vec3_t<T>& operator=(const vec3_t<T>& v);

    inline const vec3_t<T>& operator+() const;
    inline vec3_t<T> operator-() const;
    inline T operator[](const int& i) const;
    inline T& operator[](const int& i);

    inline vec3_t<T>& operator+=(const vec3_t<T>& v2);
    inline vec3_t<T>& operator-=(const vec3_t<T>& v2);
    inline vec3_t<T>& operator*=(const vec3_t<T>& v2);
    inline vec3_t<T>& operator/=(const vec3_t<T>& v2);
    inline vec3_t<T>& operator*=(const T& s);
    inline vec3_t<T>& operator/=(const T& s);

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

}  // namespace math

#include "./vec3-t.inl"
#endif  // MATH_VEC3_T_HPP_
