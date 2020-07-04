/*
The MIT License (MIT)

Copyright (c) Fouad Valadbeigi (akoylasar@gmail.com)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once

#include <cmath>
#include <type_traits>
#include <algorithm>

namespace Neon
{
  constexpr double kPi = 3.1415926535897932384626433832795;
  constexpr double radToDeg = 180.0 / kPi;
  constexpr double degToRad = kPi / 180.0;

  /* Vec2 */
  template <typename T>
  struct Vec2
  {
    T x, y;
    
    explicit Vec2(T t = 0) : x(t), y(t)
    {
    }
    
    Vec2(T _x, T _y) : x(_x), y(_y)
    {
    }
    
    inline T& operator[](unsigned int i)
    {
      return ((&x)[i]);
    }
    
    inline const T& operator[](unsigned int i) const
    {
      return ((&x)[i]);
    }
    
    friend inline Vec2<T> operator+(const Vec2<T>& lhs, const Vec2<T>& rhs)
    {
      return Vec2<T>{lhs.x + rhs.x, lhs.y + rhs.y};
    }
    
    inline Vec2<T>& operator+=(const Vec2<T>& v)
    {
      x += v.x;
      y += v.y;
      return *this;
    }
    
    friend inline Vec2<T> operator-(const Vec2<T>& v)
    {
      return Vec2<T>{-v.x, -v.y};
    }
    
    friend inline Vec2<T> operator-(const Vec2<T>& lhs, const Vec2<T>& rhs)
    {
      return Vec2<T>{lhs.x - rhs.x, lhs.y - rhs.y};
    }
    
    inline Vec2<T>& operator-=(const Vec2<T>& v)
    {
      x -= v.x;
      y -= v.y;
      return *this;
    }
    
    friend inline Vec2<T> operator*(const T t, const Vec2<T>& rhs)
    {
      return Vec2<T>{rhs.x * t, rhs.y * t};
    }
    
    friend inline Vec2<T> operator*(const Vec2<T>& lhs, const T t)
    {
      return t * lhs;
    }
    
    inline Vec2<T>& operator*=(const T t)
    {
      x *= t;
      y *= t;
      return *this;
    }
    
    friend inline Vec2<T> operator*(const Vec2<T>& lhs, const Vec2<T>& rhs)
    {
      return Vec2<T>{lhs.x * rhs.x, lhs.y * rhs.y};
    }
    
    inline Vec2<T>& operator*=(const Vec2<T>& v)
    {
      x *= v.x;
      y *= v.y;
      return *this;
    }
    
    friend inline Vec2<T> operator/(const Vec2<T>& lhs, const T t)
    {
      return Vec2<T>{lhs.x / t, lhs.y / t};
    }
    
    inline Vec2<T>& operator/=(const T t)
    {
      x /= t;
      y /= t;
      return *this;
    }
  };
  
  /* Vec3 */
  template <typename T>
  struct Vec3
  {
    T x, y, z;
    
    explicit Vec3(T t = 0) : x(t), y(t), z(t)
    {
    }
    
    Vec3(T _x, T _y, T _z) : x(_x), y(_y), z(_z)
    {
    }
    
    inline T& operator[](unsigned int i)
    {
      return ((&x)[i]);
    }
    
    inline const T& operator[](unsigned int i) const
    {
      return ((&x)[i]);
    }
    
    friend inline Vec3<T> operator+(const Vec3<T>& lhs, const Vec3<T>& rhs)
    {
      return Vec3<T>{lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z};
    }
    
    inline Vec3<T>& operator+=(const Vec3<T>& v)
    {
      x += v.x;
      y += v.y;
      z += v.z;
      return *this;
    }
    
    friend inline Vec3<T> operator-(const Vec3<T>& v)
    {
      return Vec3<T>{-v.x, -v.y, -v.z};
    }
    
    friend inline Vec3<T> operator-(const Vec3<T>& lhs, const Vec3<T>& rhs)
    {
      return Vec3<T>{lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z};
    }
    
    inline Vec3<T>& operator-=(const Vec3<T>& v)
    {
      x -= v.x;
      y -= v.y;
      z -= v.z;
      return *this;
    }
    
    friend inline Vec3<T> operator*(const Vec3<T>& v, const T t)
    {
      return Vec3<T>{v.x * t, v.y * t, v.z * t};
    }
    
    friend inline Vec3<T> operator*(const T t, const Vec3<T>& v)
    {
      return v * t;
    }
    
    inline Vec3<T>& operator*=(const T t)
    {
      x *= t;
      y *= t;
      z *= t;
      return *this;
    }
    
    friend inline Vec3<T> operator*(const Vec3<T>& lhs, const Vec3<T>& rhs)
    {
      return Vec3<T>{lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z};
    }
    
    inline Vec3<T>& operator*=(const Vec3<T>& v)
    {
      x *= v.x;
      y *= v.y;
      z *= v.z;
      return *this;
    }
    
    friend inline Vec3<T> operator/(const Vec3<T>& v, const T t)
    {
      return Vec3<T>{v.x / t, v.y / t, v.z / t};
    }
    
    inline Vec3<T>& operator/=(const T t)
    {
      x /= t;
      y /= t;
      z /= t;
      return *this;
    }
  };
  
  /* Vec4 */
  template <typename T>
  struct Vec4
  {
    T x, y, z, w;
    
    explicit Vec4(T t = 0) : x(t), y(t), z(t), w(t)
    {
    }
    
    Vec4(T _x, T _y, T _z, T _w) : x(_x), y(_y), z(_z), w(_w)
    {
    }
    
    inline T& operator[](unsigned int i)
    {
      return ((&x)[i]);
    }
    
    inline const T& operator[](unsigned int i) const
    {
      return ((&x)[i]);
    }
    
    friend inline Vec4<T> operator+(const Vec4<T>& lhs, const Vec4<T>& rhs)
    {
      return Vec4<T>{lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w};
    }
    
    inline Vec4<T>& operator+=(const Vec4<T>& v)
    {
      x += v.x;
      y += v.y;
      z += v.z;
      w += v.w;
      return *this;
    }
    
    friend inline Vec4<T> operator-(const Vec4<T>& v)
    {
      return Vec4<T>{-v.x, -v.y, -v.z, -v.w};
    }
    
    friend inline Vec4<T> operator-(const Vec4<T>& lhs, const Vec4<T>& rhs)
    {
      return Vec4<T>{lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w};
    }
    
    inline Vec4<T>& operator-=(const Vec4<T>& v)
    {
      x -= v.x;
      y -= v.y;
      z -= v.z;
      w -= v.w;
      return *this;
    }
    
    friend inline Vec4<T> operator*(const Vec4<T>& lhs, const T t)
    {
      return Vec4<T>{lhs.x * t, lhs.y * t, lhs.z * t, lhs.w * t};
    }
    
    friend inline Vec4<T> operator*(const T t, const Vec4<T>& rhs)
    {
      return rhs * t;
    }
    
    inline Vec4<T>& operator*=(const T t)
    {
      x *= t;
      y *= t;
      z *= t;
      w *= t;
      return *this;
    }
    
    friend inline Vec4<T> operator*(const Vec4<T>& lhs, const Vec4<T>& rhs)
    {
      return Vec4<T>{lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w};
    }
    
    inline Vec4<T>& operator*=(const Vec4<T>& v)
    {
      x *= v.x;
      y *= v.y;
      z *= v.z;
      w *= v.w;
      return *this;
    }
    
    friend inline Vec4<T> operator/(const Vec4<T>& lhs, const T t)
    {
      return Vec4<T>(lhs.x / t, lhs.y / t, lhs.z / t, lhs.w / t);
    }
    
    inline Vec4<T>& operator/=(const T t)
    {
      x /= t;
      y /= t;
      z /= t;
      w /= t;
      return *this;
    }
  };
  
  /* Common vector operations */
  
  template <typename T>
  inline T dot(const Vec2<T>& v1, const Vec2<T>& v2)
  {
    return v1.x * v2.x + v1.y * v2.y;
  }
  
  template <typename T>
  inline T mag(const Vec2<T>& v)
  {
    return std::sqrt(dot(v, v));
  }
  
  template <typename T>
  inline T distance(const Vec2<T>& v1, const Vec2<T>& v2)
  {
    const Vec2<T> v = v1 - v2;
    return std::sqrt(dot(v, v));
  }
  
  template <typename T>
  inline Vec2<T> normalize(const Vec2<T>& v)
  {
    return v / mag(v);
  }
  
  template <typename T>
  inline Vec2<T> project(const Vec2<T>& v1, const Vec2<T>& v2)
  {
    return (dot(v1, v2) / dot(v2, v2)) * v2;
  }
  
  template <typename T>
  inline Vec2<T> reflect(const Vec2<T>& v, const Vec2<T>& n)
  {
    const Vec2<T> p = dot(v, n) / dot(n, n) * n;
    return v - 2 * p;
  }
  
  template <typename T>
  inline Vec2<T> refract(const Vec2<T>& v, const Vec2<T>& n, T eta)
  {
    const T ctheta1 = dot(v, n);
    const T eta2 = eta * eta;
    const T k = 1 - eta2 * (1 - ctheta1 * ctheta1);
    if (k < 0)
      return Vec2<T>(0);
    else
      return eta * v - (eta * ctheta1 + std::sqrt(k)) * n;
  }
  
  template <typename T>
  inline T dot(const Vec3<T>& v1, const Vec3<T>& v2)
  {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
  }
  
  template <typename T>
  inline Vec3<T> cross(const Vec3<T>& v1, const Vec3<T>& v2)
  {
    return Vec3<T>{v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x};
  }
  
  template <typename T>
  inline T tripleProduct(const Vec3<T>& v1, const Vec3<T>& v2, const Vec3<T>& v3)
  {
    return dot(v1, cross(v2, v3));
  }
  
  template <typename T>
  inline T mag(const Vec3<T>& v)
  {
    return std::sqrt(dot(v, v));
  }
  
  template <typename T>
  inline T distance(const Vec3<T>& v1, const Vec3<T>& v2)
  {
    const Vec3<T> v = v1 - v2;
    return std::sqrt(dot(v, v));
  }
  
  template <typename T>
  inline Vec3<T> normalize(const Vec3<T>& v)
  {
    return v / mag(v);
  }
  
  template <typename T>
  inline Vec3<T> project(const Vec3<T>& v1, const Vec3<T>& v2)
  {
    return (dot(v1, v2) / dot(v2, v2)) * v2;
  }
  
  template <typename T>
  inline Vec3<T> reflect(const Vec3<T>& v, const Vec3<T>& n)
  {
    const Vec3<T> p = dot(v, n) / dot(n, n) * n;
    return v - 2 * p;
  }
  
  template <typename T>
  inline Vec3<T> refract(const Vec3<T>& v, const Vec3<T>& n, T eta)
  {
    const T ctheta1 = dot(v, n);
    const T ctheta2 = std::sqrt(1 - ((eta * eta) * (1 - ctheta1 * ctheta1)));
    const T vrefract = eta * v + (eta * ctheta1 - ctheta2) * n;
    return vrefract;
  }
  
  // Right-Handed.
  template <typename T>
  inline Vec3<T> rotate(const Vec3<T>& v, const Vec3<T>& n, T theta)
  {
    const Vec3<T> vproj = dot(v, n) * n;
    const Vec3<T> vrej = v - vproj;
    const T cos = std::cos(theta);
    const T sin = std::sin(theta);
    const Vec3<T> vcrossa = cross(n, v);
    return vproj + vrej * cos + vcrossa * sin;
  }
  
  template <typename T>
  inline T dot(const Vec4<T>& v1, const Vec4<T>& v2)
  {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
  }
  
  template <typename T>
  inline T mag(const Vec4<T>& v)
  {
    return std::sqrt(dot(v, v));
  }
  
  template <typename T>
  inline Vec4<T> normalize(const Vec4<T>& v)
  {
    return v / mag(v);
  }
  
  /* Mat2 */
  template <typename T>
  struct Mat2
  {
    static const unsigned short size = 2;
    T d[2][2];
  
    explicit Mat2(T t = 1)
    {
      d[0][0] = t; d[0][1] = 0;
      d[1][0] = 0; d[1][1] = t;
    }
    
    Mat2(const Vec2<T>& v1, const Vec2<T>& v2)
    {
      d[0][0] = v1.x; d[0][1] = v1.y;
      d[1][0] = v2.x; d[1][1] = v2.y;
    }
    
    Mat2(T v1x, T v2x,
         T v1y, T v2y)
    {
      d[0][0] = v1x; d[0][1] = v1y;
      d[1][0] = v2x; d[1][1] = v2y;
    }
    
    Mat2(const Mat2<T>& other)
    {
      d[0][0] = other(0, 0); d[1][0] = other(0, 1);
      d[0][1] = other(1, 0); d[1][1] = other(1, 1);
    }
    
    Mat2<T>& operator=(const Mat2<T>& other)
    {
      if (this != &other)
      {
        d[0][0] = other.d[0][0]; d[1][0] = other.d[1][0];
        d[0][1] = other.d[0][1]; d[1][1] = other.d[1][1];
      }
      return *this;
    }
    
    inline Vec2<T>& operator[](unsigned int column)
    {
      return *reinterpret_cast<Vec2<T>*>(d[column]);
    }
    
    inline const Vec2<T>& operator[](unsigned int column) const
    {
      return *reinterpret_cast<const Vec2<T>*>(d[column]);
    }
    
    inline T& operator()(unsigned int row, unsigned int col)
    {
      return d[col][row];
    }
    
    inline const T& operator()(unsigned int row, unsigned int col) const
    {
      return d[col][row];
    }
    
    friend inline Mat2<T> operator+(const Mat2<T>& lhs, const Mat2<T>& rhs)
    {
      return Mat2<T>(lhs[0] + rhs[0], lhs[1] + rhs[1]);
    }
    
    inline Mat2<T>& operator+=(const Mat2<T>& m)
    {
      d[0][0] += m.d[0][0]; d[1][0] += m.d[1][0];
      d[0][1] += m.d[0][1]; d[1][1] += m.d[1][1];
      return *this;
    }
    
    inline Mat2<T> operator-() const
    {
      return Mat2<T>(-d[0][0], -d[1][0],
                     -d[0][1], -d[1][1]);
    }
    
    friend inline Mat2<T> operator-(const Mat2<T>& lhs, const Mat2<T>& rhs)
    {
      return Mat2<T>(lhs[0] - rhs[0], lhs[1] - rhs[1]);
    }
    
    inline Mat2<T>& operator-=(const Mat2<T>& m)
    {
      d[0][0] -= m.d[0][0]; d[1][0] -= m.d[1][0];
      d[0][1] -= m.d[0][1]; d[1][1] -= m.d[1][1];
      return *this;
    }
    
    inline Mat2<T> operator*(const T t) const
    {
      return Mat2<T>(d[0][0] * t, d[1][0] * t,
                     d[0][1] * t, d[1][1] * t);
    }
    
    friend inline Mat2<T> operator*(const T t, const Mat2<T>& m)
    {
      return m * t;
    }
    
    inline Mat2<T>& operator*=(const T t)
    {
      d[0][0] *= t; d[1][0] *= t;
      d[0][1] *= t; d[1][1] *= t;
      return *this;
    }
    
    inline Vec2<T> operator*(const Vec2<T>& v) const
    {
      return Vec2<T>(d[0][0] * v.x + d[1][0] * v.y,
                     d[0][1] * v.x + d[1][1] * v.y);
    }
    
    friend inline Mat2<T> operator*(const Mat2<T>& lhs, const Mat2<T>& rhs)
    {
      const T v1x = lhs.d[0][0] * rhs.d[0][0] + lhs.d[1][0] * rhs.d[0][1];
      const T v2x = lhs.d[0][0] * rhs.d[1][0] + lhs.d[1][0] * rhs.d[1][1];
      const T v1y = lhs.d[0][1] * rhs.d[0][0] + lhs.d[1][1] * rhs.d[0][1];
      const T v2y = lhs.d[0][1] * rhs.d[1][0] + lhs.d[1][1] * rhs.d[1][1];
      return Mat2<T>(v1x, v2x,
                     v1y, v2y);
    }
    
    inline Mat2<T> operator/(const T t) const
    {
      const T d = 1 / t;
      return *this * d;
    }
    
    friend inline Mat2<T> operator/(const T t, const Mat2<T>& m)
    {
      return m * t;
    }
    
    inline Mat2<T>& operator/=(const T t)
    {
      const T d = 1 / t;
      return *this *= d;
    }
    
    inline T* data()
    {
      return d[0];
    }
  };
  
  /* Mat3 */
  template <typename T>
  struct Mat3
  {
    static const unsigned short size = 3;
    T d[3][3];
    
    explicit Mat3(T t = 1)
    {
      d[0][0] = t; d[0][1] = 0; d[0][2] = 0;
      d[1][0] = 0; d[1][1] = t; d[1][2] = 0;
      d[2][0] = 0; d[2][1] = 0; d[2][2] = t;
    }
    
    Mat3(const Vec3<T>& v1, const Vec3<T>& v2, const Vec3<T>& v3)
    {
      d[0][0] = v1.x; d[0][1] = v1.y; d[0][2] = v1.z;
      d[1][0] = v2.x; d[1][1] = v2.y; d[1][2] = v2.z;
      d[2][0] = v3.x; d[2][1] = v3.y; d[2][2] = v3.z;
    }
    
    Mat3(T v1x, T v2x, T v3x,
         T v1y, T v2y, T v3y,
         T v1z, T v2z, T v3z)
    {
      d[0][0] = v1x; d[0][1] = v1y; d[0][2] = v1z;
      d[1][0] = v2x; d[1][1] = v2y; d[1][2] = v2z;
      d[2][0] = v3x; d[2][1] = v3y; d[2][2] = v3z;
    }
    
    Mat3(const Mat3<T>& other)
    {
      d[0][0] = other.d[0][0]; d[1][0] = other.d[1][0]; d[2][0] = other.d[2][0];
      d[0][1] = other.d[0][1]; d[1][1] = other.d[1][1]; d[2][1] = other.d[2][1];
      d[0][2] = other.d[0][2]; d[1][2] = other.d[1][2]; d[2][2] = other.d[2][2];
    }
    
    Mat3(const Mat2<T>& other)
    {
      d[0][0] = other.d[0][0]; d[1][0] = other.d[1][0]; d[2][0] = 0;
      d[0][1] = other.d[0][1]; d[1][1] = other.d[1][1]; d[2][1] = 0;
      d[0][2] = 0;             d[1][2] = 0;             d[2][2] = 0;
    }
    
    Mat3<T>& operator=(const Mat3<T>& other)
    {
      if (this != &other)
      {
        d[0][0] = other.d[0][0]; d[1][0] = other.d[1][0]; d[2][0] = other.d[2][0];
        d[0][1] = other.d[0][1]; d[1][1] = other.d[1][1]; d[2][1] = other.d[2][1];
        d[0][2] = other.d[0][2]; d[1][2] = other.d[1][2]; d[2][2] = other.d[2][2];
      }
      return *this;
    }
    
    inline Vec3<T>& operator[](unsigned int column)
    {
      return *reinterpret_cast<Vec3<T>*>(d[column]);
    }
    
    inline const Vec3<T>& operator[](unsigned int column) const
    {
      return *reinterpret_cast<const Vec3<T>*>(d[column]);
    }
    
    inline T& operator()(unsigned int row, unsigned int col)
    {
      return d[col][row];
    }
    
    inline const T& operator()(unsigned int row, unsigned int col) const
    {
      return d[col][row];
    }
    
    friend inline Mat3<T> operator+(const Mat3<T>& lhs, const Mat3<T>& rhs)
    {
      return Mat3<T>(lhs[0] + rhs[0], lhs[1] + rhs[1], lhs[2] + rhs[2]);
    }
    
    inline Mat3<T>& operator+=(const Mat3<T>& m)
    {
      d[0][0] += m.d[0][0]; d[1][0] += m.d[1][0]; d[2][0] += m.d[2][0];
      d[0][1] += m.d[0][1]; d[1][1] += m.d[1][1]; d[2][1] += m.d[2][1];
      d[0][2] += m.d[0][2]; d[1][2] += m.d[1][2]; d[2][2] += m.d[2][2];
      return *this;
    }
    
    inline Mat3<T> operator-() const
    {
      return Mat3<T>(-d[0][0], -d[1][0], -d[2][0],
                     -d[0][1], -d[1][1], -d[2][1],
                     -d[0][2], -d[1][2], -d[2][2]);
    }
    
    friend inline Mat3<T> operator-(const Mat3<T>& lhs, const Mat3<T>& rhs)
    {
      return Mat3<T>(lhs[0] - rhs[0], lhs[1] - rhs[1], lhs[2] - rhs[2]);
    }
    
    inline Mat3<T>& operator-=(const Mat3<T>& m)
    {
      d[0][0] -= m.d[0][0]; d[1][0] -= m.d[1][0]; d[2][0] -= m.d[2][0];
      d[0][1] -= m.d[0][1]; d[1][1] -= m.d[1][1]; d[2][1] -= m.d[2][1];
      d[0][2] -= m.d[0][2]; d[1][2] -= m.d[1][2]; d[2][2] -= m.d[2][2];
      return *this;
    }
    
    inline Mat3<T> operator*(const T t) const
    {
      return Mat3<T>(d[0][0] * t, d[1][0] * t, d[2][0] * t,
                     d[0][1] * t, d[1][1] * t, d[2][1] * t,
                     d[0][2] * t, d[1][2] * t, d[2][2] * t);
    }
    
    friend inline Mat3<T> operator*(const T t, const Mat3<T>& m)
    {
      return m * t;
    }
    
    inline Mat3<T>& operator*=(const T t)
    {
      d[0][0] *= t; d[1][0] *= t; d[2][0] *= t;
      d[0][1] *= t; d[1][1] *= t; d[2][1] *= t;
      d[0][2] *= t; d[1][2] *= t; d[2][2] *= t;
      return *this;
    }
    
    inline Vec3<T> operator*(const Vec3<T>& v) const
    {
      return Vec3<T>(d[0][0] * v.x + d[1][0] * v.y + d[2][0] * v.z,
                     d[0][1] * v.x + d[1][1] * v.y + d[2][1] * v.z,
                     d[0][2] * v.x + d[1][2] * v.y + d[2][2] * v.z);
    }
    
    friend inline Mat3<T> operator*(const Mat3<T>& lhs, const Mat3<T>& rhs)
    {
      const T v1x = lhs.d[0][0] * rhs.d[0][0] + lhs.d[1][0] * rhs.d[0][1] + lhs.d[2][0] * rhs.d[0][2];
      const T v2x = lhs.d[0][0] * rhs.d[1][0] + lhs.d[1][0] * rhs.d[1][1] + lhs.d[2][0] * rhs.d[1][2];
      const T v3x = lhs.d[0][0] * rhs.d[2][0] + lhs.d[1][0] * rhs.d[2][1] + lhs.d[2][0] * rhs.d[2][2];
      const T v1y = lhs.d[0][1] * rhs.d[0][0] + lhs.d[1][1] * rhs.d[0][1] + lhs.d[2][1] * rhs.d[0][2];
      const T v2y = lhs.d[0][1] * rhs.d[1][0] + lhs.d[1][1] * rhs.d[1][1] + lhs.d[2][1] * rhs.d[1][2];
      const T v3y = lhs.d[0][1] * rhs.d[2][0] + lhs.d[1][1] * rhs.d[2][1] + lhs.d[2][1] * rhs.d[2][2];
      const T v1z = lhs.d[0][2] * rhs.d[0][0] + lhs.d[1][2] * rhs.d[0][1] + lhs.d[2][2] * rhs.d[0][2];
      const T v2z = lhs.d[0][2] * rhs.d[1][0] + lhs.d[1][2] * rhs.d[1][1] + lhs.d[2][2] * rhs.d[1][2];
      const T v3z = lhs.d[0][2] * rhs.d[2][0] + lhs.d[1][2] * rhs.d[2][1] + lhs.d[2][2] * rhs.d[2][2];
      return Mat3<T>{v1x, v2x, v3x,
                     v1y, v2y, v3y,
                     v1z, v2z, v3z};
    }
    
    inline Mat3<T> operator/(const T t) const
    {
      const T d = 1 / t;
      return *this * d;
    }
    
    friend inline Mat3<T> operator/(const T t, const Mat3<T>& m)
    {
      return m * t;
    }
    
    inline Mat3<T>& operator/=(const T t)
    {
      const T d = 1 / t;
      return *this *= d;
    }
    
    inline T* data()
    {
      return d[0];
    }
  };
  
  /* Mat4 */
  template <typename T>
  struct Mat4
  {
    static const unsigned short size = 4;
    T d[4][4];
    
    explicit Mat4(T t = 1)
    {
      d[0][0] = t; d[0][1] = 0; d[0][2] = 0; d[0][3] = 0;
      d[1][0] = 0; d[1][1] = t; d[1][2] = 0; d[1][3] = 0;
      d[2][0] = 0; d[2][1] = 0; d[2][2] = t; d[2][3] = 0;
      d[3][0] = 0; d[3][1] = 0; d[3][2] = 0; d[3][3] = t;
    }
    
    Mat4(const Vec4<T>& v1, const Vec4<T>& v2, const Vec4<T>& v3, const Vec4<T>& v4)
    {
      d[0][0] = v1.x; d[0][1] = v1.y; d[0][2] = v1.z; d[0][3] = v1.w;
      d[1][0] = v2.x; d[1][1] = v2.y; d[1][2] = v2.z; d[1][3] = v2.w;
      d[2][0] = v3.x; d[2][1] = v3.y; d[2][2] = v3.z; d[2][3] = v3.w;
      d[3][0] = v4.x; d[3][1] = v4.y; d[3][2] = v4.z; d[3][3] = v4.w;
    }
    
    Mat4(T v1x, T v2x, T v3x, T v4x,
         T v1y, T v2y, T v3y, T v4y,
         T v1z, T v2z, T v3z, T v4z,
         T v1w, T v2w, T v3w, T v4w)
    {
      d[0][0] = v1x; d[0][1] = v1y; d[0][2] = v1z; d[0][3] = v1w;
      d[1][0] = v2x; d[1][1] = v2y; d[1][2] = v2z; d[1][3] = v2w;
      d[2][0] = v3x; d[2][1] = v3y; d[2][2] = v3z; d[2][3] = v3w;
      d[3][0] = v4x; d[3][1] = v4y; d[3][2] = v4z; d[3][3] = v4w;
    }
    
    Mat4(const Mat4<T>& other)
    {
      d[0][0] = other.d[0][0]; d[1][0] = other.d[1][0]; d[2][0] = other.d[2][0]; d[3][0] = other.d[3][0];
      d[0][1] = other.d[0][1]; d[1][1] = other.d[1][1]; d[2][1] = other.d[2][1]; d[3][1] = other.d[3][1];
      d[0][2] = other.d[0][2]; d[1][2] = other.d[1][2]; d[2][2] = other.d[2][2]; d[3][2] = other.d[3][2];
      d[0][3] = other.d[0][3]; d[1][3] = other.d[1][3]; d[2][3] = other.d[2][3]; d[3][3] = other.d[3][3];
    }
    
    Mat4(const Mat2<T>& other)
    {
      d[0][0] = other.d[0][0]; d[1][0] = other.d[1][0]; d[2][0] = 0; d[3][0] = 0;
      d[0][1] = other.d[0][1]; d[1][1] = other.d[1][1]; d[2][1] = 0; d[3][1] = 0;
      d[0][2] = 0;             d[1][2] = 0;             d[2][2] = 0; d[3][2] = 0;
      d[0][3] = 0;             d[1][3] = 0;             d[2][3] = 0; d[3][3] = 0;
    }
    
    Mat4(const Mat3<T>& other)
    {
      d[0][0] = other.d[0][0]; d[1][0] = other.d[1][0]; d[2][0] = other.d[2][0]; d[3][0] = 0;
      d[0][1] = other.d[0][1]; d[1][1] = other.d[1][1]; d[2][1] = other.d[2][1]; d[3][1] = 0;
      d[0][2] = other.d[2][2]; d[1][2] = other.d[1][2]; d[2][2] = other.d[2][2]; d[3][2] = 0;
      d[0][3] = 0;             d[1][3] = 0;             d[2][3] = 0;             d[3][3] = 0;
    }
    
    Mat4<T>& operator=(const Mat4<T>& other)
    {
      if (this != &other)
      {
        d[0][0] = other.d[0][0]; d[1][0] = other.d[1][0]; d[2][0] = other.d[2][0]; d[3][0] = other.d[3][0];
        d[0][1] = other.d[0][1]; d[1][1] = other.d[1][1]; d[2][1] = other.d[2][1]; d[3][1] = other.d[3][1];
        d[0][2] = other.d[0][2]; d[1][2] = other.d[1][2]; d[2][2] = other.d[2][2]; d[3][2] = other.d[3][2];
        d[0][3] = other.d[0][3]; d[1][3] = other.d[1][3]; d[2][3] = other.d[2][3]; d[3][3] = other.d[3][3];
      }
      return *this;
    }
    
    inline Vec4<T>& operator[](unsigned int column)
    {
      return *reinterpret_cast<Vec4<T>*>(d[column]);
    }
    
    inline const Vec4<T>& operator[](unsigned int column) const
    {
      return *reinterpret_cast<const Vec4<T>*>(d[column]);
    }
    
    inline T& operator()(unsigned int row, unsigned int col)
    {
      return d[col][row];
    }
    
    inline const T& operator()(unsigned int row, unsigned int col) const
    {
      return d[col][row];
    }
    
    friend inline Mat4<T> operator+(const Mat4<T>& lhs, const Mat4<T>& rhs)
    {
      return Mat4<T>{lhs[0] + rhs[0], lhs[1] + rhs[1], lhs[2] + rhs[2], lhs[3] + rhs[3]};
    }
    
    inline Mat4<T>& operator+=(const Mat4<T>& m)
    {
      d[0][0] += m.d[0][0]; d[1][0] += m.d[1][0]; d[2][0] += m.d[2][0]; d[3][0] += m.d[3][0];
      d[0][1] += m.d[0][1]; d[1][1] += m.d[1][1]; d[2][1] += m.d[2][1]; d[3][1] += m.d[3][1];
      d[0][2] += m.d[0][2]; d[1][2] += m.d[1][2]; d[2][2] += m.d[2][2]; d[3][2] += m.d[3][2];
      d[0][3] += m.d[0][3]; d[1][3] += m.d[1][3]; d[2][3] += m.d[2][3]; d[3][3] += m.d[3][3];
      return *this;
    }
    
    inline Mat4<T> operator-() const
    {
      return Mat4<T>{-d[0][0], -d[1][0], -d[2][0], -d[3][0],
                     -d[0][1], -d[1][1], -d[2][1], -d[3][1],
                     -d[0][2], -d[1][2], -d[2][2], -d[3][2],
                     -d[0][3], -d[1][3], -d[2][3], -d[3][3]};
    }
    
    friend inline Mat4<T> operator-(const Mat4<T>& lhs, const Mat4<T>& rhs)
    {
      return Mat4<T>{lhs[0] - rhs[0], lhs[1] - rhs[1], lhs[2] - rhs[2], lhs[3] - rhs[3]};
    }
    
    inline Mat4<T>& operator-=(const Mat4<T>& m)
    {
      d[0][0] -= m.d[0][0]; d[1][0] -= m.d[1][0]; d[2][0] -= m.d[2][0]; d[3][0] -= m.d[3][0];
      d[0][1] -= m.d[0][1]; d[1][1] -= m.d[1][1]; d[2][1] -= m.d[2][1]; d[3][1] -= m.d[3][1];
      d[0][2] -= m.d[0][2]; d[1][2] -= m.d[1][2]; d[2][2] -= m.d[2][2]; d[3][2] -= m.d[3][2];
      d[0][3] -= m.d[0][3]; d[1][3] -= m.d[1][3]; d[2][3] -= m.d[2][3]; d[3][3] -= m.d[3][3];
      return *this;
    }
    
    inline Mat4<T> operator*(const T t) const
    {
      return Mat4<T>{d[0][0] * t, d[1][0] * t, d[2][0] * t, d[3][0] * t,
                     d[0][1] * t, d[1][1] * t, d[2][1] * t, d[3][1] * t,
                     d[0][2] * t, d[1][2] * t, d[2][2] * t, d[3][2] * t,
                     d[0][3] * t, d[1][3] * t, d[2][3] * t, d[3][3] * t};
    }
    
    friend inline Mat4<T> operator*(const T t, const Mat4<T>& m)
    {
      return m * t;
    }
    
    inline Mat4<T>& operator*=(const T t)
    {
      d[0][0] *= t; d[1][0] *= t; d[2][0] *= t; d[3][0] *= t;
      d[0][1] *= t; d[1][1] *= t; d[2][1] *= t; d[3][1] *= t;
      d[0][2] *= t; d[1][2] *= t; d[2][2] *= t; d[3][2] *= t;
      d[0][3] *= t; d[1][3] *= t; d[2][3] *= t; d[3][3] *= t;
      return *this;
    }
    
    inline Vec4<T> operator*(const Vec4<T>& v) const
    {
      return Vec4<T>{d[0][0] * v.x + d[1][0] * v.y + d[2][0] * v.z + d[3][0] * v.w,
                     d[0][1] * v.x + d[1][1] * v.y + d[2][1] * v.z + d[3][1] * v.w,
                     d[0][2] * v.x + d[1][2] * v.y + d[2][2] * v.z + d[3][2] * v.w,
                     d[0][3] * v.x + d[1][3] * v.y + d[2][3] * v.z + d[3][3] * v.w};
    }
    
    friend inline Mat4<T> operator*(const Mat4<T>& lhs, const Mat4<T>& rhs)
    {
      const T v1x = lhs.d[0][0] * rhs.d[0][0] + lhs.d[1][0] * rhs.d[0][1] + lhs.d[2][0] * rhs.d[0][2] + lhs.d[3][0] * rhs.d[0][3];
      const T v2x = lhs.d[0][0] * rhs.d[1][0] + lhs.d[1][0] * rhs.d[1][1] + lhs.d[2][0] * rhs.d[1][2] + lhs.d[3][0] * rhs.d[1][3];
      const T v3x = lhs.d[0][0] * rhs.d[2][0] + lhs.d[1][0] * rhs.d[2][1] + lhs.d[2][0] * rhs.d[2][2] + lhs.d[3][0] * rhs.d[2][3];
      const T v4x = lhs.d[0][0] * rhs.d[3][0] + lhs.d[1][0] * rhs.d[3][1] + lhs.d[2][0] * rhs.d[3][2] + lhs.d[3][0] * rhs.d[3][3];
      const T v1y = lhs.d[0][1] * rhs.d[0][0] + lhs.d[1][1] * rhs.d[0][1] + lhs.d[2][1] * rhs.d[0][2] + lhs.d[3][1] * rhs.d[0][3];
      const T v2y = lhs.d[0][1] * rhs.d[1][0] + lhs.d[1][1] * rhs.d[1][1] + lhs.d[2][1] * rhs.d[1][2] + lhs.d[3][1] * rhs.d[1][3];
      const T v3y = lhs.d[0][1] * rhs.d[2][0] + lhs.d[1][1] * rhs.d[2][1] + lhs.d[2][1] * rhs.d[2][2] + lhs.d[3][1] * rhs.d[2][3];
      const T v4y = lhs.d[0][1] * rhs.d[3][0] + lhs.d[1][1] * rhs.d[3][1] + lhs.d[2][1] * rhs.d[3][2] + lhs.d[3][1] * rhs.d[3][3];
      const T v1z = lhs.d[0][2] * rhs.d[0][0] + lhs.d[1][2] * rhs.d[0][1] + lhs.d[2][2] * rhs.d[0][2] + lhs.d[3][2] * rhs.d[0][3];
      const T v2z = lhs.d[0][2] * rhs.d[1][0] + lhs.d[1][2] * rhs.d[1][1] + lhs.d[2][2] * rhs.d[1][2] + lhs.d[3][2] * rhs.d[1][3];
      const T v3z = lhs.d[0][2] * rhs.d[2][0] + lhs.d[1][2] * rhs.d[2][1] + lhs.d[2][2] * rhs.d[2][2] + lhs.d[3][2] * rhs.d[2][3];
      const T v4z = lhs.d[0][2] * rhs.d[3][0] + lhs.d[1][2] * rhs.d[3][1] + lhs.d[2][2] * rhs.d[3][2] + lhs.d[3][2] * rhs.d[3][3];
      const T v1w = lhs.d[0][3] * rhs.d[0][0] + lhs.d[1][3] * rhs.d[0][1] + lhs.d[2][3] * rhs.d[0][2] + lhs.d[3][3] * rhs.d[0][3];
      const T v2w = lhs.d[0][3] * rhs.d[1][0] + lhs.d[1][3] * rhs.d[1][1] + lhs.d[2][3] * rhs.d[1][2] + lhs.d[3][3] * rhs.d[1][3];
      const T v3w = lhs.d[0][3] * rhs.d[2][0] + lhs.d[1][3] * rhs.d[2][1] + lhs.d[2][3] * rhs.d[2][2] + lhs.d[3][3] * rhs.d[2][3];
      const T v4w = lhs.d[0][3] * rhs.d[3][0] + lhs.d[1][3] * rhs.d[3][1] + lhs.d[2][3] * rhs.d[3][2] + lhs.d[3][3] * rhs.d[3][3];
      return Mat4<T>{v1x, v2x, v3x, v4x,
                     v1y, v2y, v3y, v4y,
                     v1z, v2z, v3z, v4z,
                     v1w, v2w, v3w, v4w};
    }
    
    inline Mat4<T> operator/(const T t) const
    {
      const T d = 1 / t;
      return *this * d;
    }
    
    friend inline Mat4<T> operator/(const T t, const Mat4<T>& m)
    {
      return m * t;
    }
    
    inline Mat4<T>& operator/=(const T t)
    {
      const T d = 1 / t;
      return *this *= d;
    }
    
    inline T* data()
    {
      return d[0];
    }
  };
  
  /* Common matrix operations */
  
  template <typename T>
  inline T determinant(const Mat2<T>& m)
  {
    return m.d[0][0] * m.d[1][1] - m.d[1][0] * m.d[0][1];
  }
  
  template <typename T>
  inline Mat2<T> inverse(const Mat2<T>& m)
  {
    const T di = 1 / determinant(m);
    return Mat2<T>{di * m.d[1][1], -di * m.d[1][0], -di * m.d[0][1], di * m.d[0][0]};
  }
  
  template <typename T>
  inline T determinant(const Mat3<T>& m)
  {
    const T x = m.d[0][0] * (m.d[1][1] * m.d[2][2] - m.d[2][1] * m.d[1][2]);
    const T y = m.d[1][0] * (m.d[0][1] * m.d[2][2] - m.d[2][1] * m.d[0][2]);
    const T z = m.d[2][0] * (m.d[0][1] * m.d[1][2] - m.d[1][1] * m.d[0][2]);
    return x - y + z;
  }
  
  template <typename T>
  inline Mat3<T> inverse(const Mat3<T>& m)
  {
    // https://en.wikipedia.org/wiki/Invertible_matrix#Inversion_of_3_%C3%97_3_matrices
    const Vec3<T>& v0 = m[0];
    const Vec3<T>& v1 = m[1];
    const Vec3<T>& v2 = m[2];
    Vec3<T> a = cross(v1, v2);
    Vec3<T> b = cross(v2, v0);
    Vec3<T> c = cross(v0, v1);
    const T detInv = 1 / dot(v0, a);
    a = a * detInv;
    b = b * detInv;
    c = c * detInv;
    return transpose(Mat3<T>(a, b, c));
  }
  
  template <typename T>
  inline T determinant(const Mat4<T>& m)
  {
    const Vec3<T> v1 = reinterpret_cast<const Vec3<T>&>(m[0]);
    const Vec3<T> v2 = reinterpret_cast<const Vec3<T>&>(m[1]);
    const Vec3<T> v3 = reinterpret_cast<const Vec3<T>&>(m[2]);
    const Vec3<T> v4 = reinterpret_cast<const Vec3<T>&>(m[3]);
    const T x = m.d[0][3];
    const T y = m.d[1][3];
    const T z = m.d[2][3];
    const T w = m.d[3][3];
    const Vec3<T> s = cross(v1, v2);
    const Vec3<T> t = cross(v3, v4);
    const Vec3<T> u = v1 * y - v2 * x;
    const Vec3<T> v = v3 * w - v4 * z;
    return dot(s, v) + dot(t, u);
  }
  
  template <typename T>
  inline Mat4<T> inverse(const Mat4<T>& m)
  {
    const Vec3<T> a = reinterpret_cast<const Vec3<T>&>(m[0]);
    const Vec3<T> b = reinterpret_cast<const Vec3<T>&>(m[1]);
    const Vec3<T> c = reinterpret_cast<const Vec3<T>&>(m[2]);
    const Vec3<T> d = reinterpret_cast<const Vec3<T>&>(m[3]);
    const T x = m.d[0][3];
    const T y = m.d[1][3];
    const T z = m.d[2][3];
    const T w = m.d[3][3];
    Vec3<T> s = cross(a, b);
    Vec3<T> t = cross(c, d);
    Vec3<T> u = a * y - b * x;
    Vec3<T> v = c * w - d * z;
    const T detInv = 1 / (dot(s, v) + dot(t, u));
    s *= detInv;
    t *= detInv;
    u *= detInv;
    v *= detInv;
    const Vec3<T> r0 = cross(b, v) + t * y;
    const Vec3<T> r1 = cross(v, a) - t * x;
    const Vec3<T> r2 = cross(d, u) + s * w;
    const Vec3<T> r3 = cross(u, c) - s * z;
    return Mat4<T>{r0.x, r0.y, r0.z, -dot(b, t),
                   r1.x, r1.y, r1.z, dot(a, t),
                   r2.x, r2.y, r2.z, -dot(d, s),
                   r3.x, r3.y, r3.z, dot(c, s)};
  }
  
  template <typename M>
  inline M& transpose(M& m)
  {
    for (unsigned int i = 0; i < M::size; i++)
      for (unsigned int j = i + 1; j < M::size; j++)
        std::swap(m.d[j][i], m.d[i][j]);
    return m;
  }
  
  template <typename M>
  inline M transpose(const M& m)
  {
    M mt(m);
    transpose(mt);
    return mt;
  }
  
  /* Common transformations */
  
  template <typename T>
  inline Mat2<T> makeRotation2D(const T angle)
  {
    const T s = std::sin(angle);
    const T c = std::cos(angle);
    return Mat2<T>{c, -s, s, c};
  }
  
  // This is yaw(y-axis) * pitch(x-axis) * roll(z-axis).
  template <typename T>
  inline Mat3<T> makeRotation3D(T yaw, T pitch, T roll)
  {
    const T sy = std::sin(yaw);
    const T cy = std::cos(yaw);
    const T sp = std::sin(pitch);
    const T cp = std::cos(pitch);
    const T sr = std::sin(roll);
    const T cr = std::cos(roll);
    const T v1x = cy * cr + sy * sp * sr;
    const T v1y = cp * sr;
    const T v1z = -sy * cr + cy * sp * sr;
    const T v2x = -cy * sr + sy * sp * cr;
    const T v2y = cp * cr;
    const T v2z = sy * sr + cy * sp * cr;
    const T v3x = sy * cp;
    const T v3y = -sp;
    const T v3z = cy * cp;
    return Mat3<T>{v1x, v2x, v3x,
                   v1y, v2y, v3y,
                   v1z, v2z, v3z};
  }
  
  template <typename T>
  inline Mat3<T> makeRotation3DX(T angle)
  {
    const T s = std::sin(angle);
    const T c = std::cos(angle);
    return Mat3<T>{1, 0, 0,
                   0, c, -s,
                   0, s, c};
  }
  
  template <typename T>
  inline Mat3<T> makeRotation3DY(T angle)
  {
    const T s = std::sin(angle);
    const T c = std::cos(angle);
    return Mat3<T>{c,  0, s,
                   0,  1, 0,
                   -s, 0, c};
  }
  
  template <typename T>
  inline Mat3<T> makeRotation3DZ(T angle)
  {
    const T s = std::sin(angle);
    const T c = std::cos(angle);
    return Mat3<T>{c, -s, 0,
                   s, c,  0,
                   0, 0,  1};
  }
  
  // Axis is assumed to be normalized.
  template <typename T>
  inline Mat3<T> makeRotation3D(const Vec3<T>& axis, T angle)
  {
    // https://en.wikipedia.org/wiki/Rotation_matrix#Rotation_matrix_from_axis_and_angle
    const T s = std::sin(angle);
    const T c = std::cos(angle);
    const T oneMinCos = 1 - c;
    const T xx = axis.x * axis.x;
    const T yy = axis.y * axis.y;
    const T zz = axis.z * axis.z;
    const T xy1c = axis.x * axis.y * oneMinCos;
    const T xz1c = axis.x * axis.z * oneMinCos;
    const T yz1c = axis.y * axis.z * oneMinCos;
    const T xs = axis.x * s;
    const T ys = axis.y * s;
    const T zs = axis.z * s;
    const T v1x = c + xx * oneMinCos;
    const T v2x = xy1c - zs;
    const T v3x = xz1c + ys;
    const T v1y = xy1c + zs;
    const T v2y = c + yy * oneMinCos;
    const T v3y = yz1c - xs;
    const T v1z = xz1c - ys;
    const T v2z = yz1c + xs;
    const T v3z = c + zz * oneMinCos;
    return Mat3<T>{v1x, v2x, v3x,
                   v1y, v2y, v3y,
                   v1z, v2z, v3z};
  }
  
  template <typename T>
  inline Mat4<T> makeRotation4D(T yaw, T pitch, T roll)
  {
    Mat4<T> result{makeRotation3D(yaw, pitch, roll)};
    result.d[3][3] = 1;
    return result;
  }
  
  template <typename T>
  inline Mat4<T> makeRotation4DX(T angle)
  {
    Mat4<T> result{makeRotation3DX(angle)};
    result.d[3][3] = 1;
    return result;
  }
  
  template <typename T>
  inline Mat4<T> makeRotation4DY(T angle)
  {
    Mat4<T> result{makeRotation3DY(angle)};
    result.d[3][3] = 1;
    return result;
  }
  
  template <typename T>
  inline Mat4<T> makeRotation4DZ(T angle)
  {
    Mat4<T> result{makeRotation3DZ(angle)};
    result.d[3][3] = 1;
    return result;
  }
  
  template<typename T>
  inline Mat4<T> makeRotation4D(const Vec3<T>& axis, T angle)
  {
    Mat4<T> result{makeRotation3D(axis, angle)};
    result.d[3][3] = 1;
    return result;
  }
  
  template <typename T>
  inline Mat2<T> makeScale2D(const Vec2<T>& s)
  {
    return Mat2<T>{s.x, 0,
                   0,   s.y};
  }
  
  template <typename T>
  inline Mat3<T> makeScale3D(const Vec3<T>& s)
  {
    return Mat3<T>{s.x, 0,   0,
                   0,   s.y, 0,
                   0,   0,   s.z};
  }
  
  template <typename T>
  inline Mat4<T> makeScale4D(const Vec3<T>& s)
  {
    return Mat3<T>{s.x, 0, 0,   0,
                   0, s.y, 0,   0,
                   0, 0,   s.z, 0,
                   0, 0,   0,   1};
  }

  template <typename T>
  inline void makeTranslation(const Vec3<T>& t)
  {
    return Mat4<T>{1, 0, 0,  t.x,
                   0, 1, 0,  t.y,
                   0, 0, 1,  t.z,
                   0, 0, 0,  1};
  }
  
  // Builds a Right-Handed look-at matrix.
  template<typename T = float>
  inline Mat4<T> makeLookAt(const Vec3<T>& origin, const Vec3<T>& lookAt, const Vec3<T>& worldUp)
  {
    const Vec3<T> w = normalize(lookAt - origin);
    const Vec3<T> u = normalize(Neon::cross(w, worldUp));
    const Vec3<T> v = cross(u, w);
    return Mat4<T>{u.x,  u.y,  u.z,  -Neon::dot(origin, u),
                   v.x,  v.y,  v.z,  -Neon::dot(origin, v),
                   -w.x, -w.y, -w.z, Neon::dot(origin, w),
                   0,    0,    0,    1.0};
  }
  
  /* Common projections (Right-Handed) */
  
  enum class NdcDepth
  {
    NegativeOneToOne,
    ZeroToOne
  };
  
  namespace Detail
  {
    template <typename T, NdcDepth D>
    inline typename std::enable_if<D == NdcDepth::ZeroToOne, Mat4<T>>::type
    makeFrustum(T near, T far, T left, T right, T top, T bottom)
    {
      const T rlInv = 1 / (right - left);
      const T n2 = 2 * near;
      const T tbInv = 1 / (top - bottom);
      const T nfInv = 1 / (near - far);
      return Mat4<T>{n2 * rlInv, 0,          (right + left) * rlInv, 0,
                     0,          n2 * tbInv, (top + bottom) * tbInv, 0,
                     0,          0,          far * nfInv,            far * near * nfInv,
                     0,          0,          -1,                     0};
    }
    
    template <typename T, NdcDepth D>
    inline typename std::enable_if<D == NdcDepth::NegativeOneToOne, Mat4<T>>::type
    makeFrustum(T near, T far, T left, T right, T top, T bottom)
    {
      const T rlInv = 1 / (right - left);
      const T n2 = 2 * near;
      const T tbInv = 1 / (top - bottom);
      const T nfInv = 1 / (near - far);
      return Mat4<T>{n2 * rlInv, 0,          (right + left) * rlInv, 0,
                     0,          n2 * tbInv, (top + bottom) * tbInv, 0,
                     0,          0,          (far + near) * nfInv,   2 * far * near * nfInv,
                     0,          0,          -1,                     0};
    }
    
    template <typename T, NdcDepth D>
    inline typename std::enable_if<D == NdcDepth::ZeroToOne, Mat4<T>>::type
    makeOrthographic(T near, T far, T left, T right, T top, T bottom)
    {
      const T rlInv = 1 / (right - left);
      const T tbInv = 1 / (top - bottom);
      const T nfInv = 1 / (near - far);
      return Mat4<T> {2 * rlInv, 0,         0,           -(left + right) * rlInv,
                      0,         2 * tbInv, 0,           -(bottom + top) * tbInv,
                      0,         0,         nfInv,       near * nfInv,
                      0,         0,         0,           1};
    }
    
    template <typename T, NdcDepth D>
    inline typename std::enable_if<D == NdcDepth::NegativeOneToOne, Mat4<T>>::type
    makeOrthographic(T near, T far, T left, T right, T top, T bottom)
    {
      const T rlInv = 1 / (right - left);
      const T tbInv = 1 / (top - bottom);
      const T nfInv = 1 / (near - far);
      return Mat4<T> {2 * rlInv, 0,         0,           -(left + right) * rlInv,
                      0,         2 * tbInv, 0,           -(bottom + top) * tbInv,
                      0,         0,         2 * nfInv,   (near + far) * nfInv,
                      0,         0,         0,           1};
    }
    
    template <typename T, NdcDepth D>
    inline typename std::enable_if<D == NdcDepth::ZeroToOne, Mat4<T>>::type
    makePerspective(T fovy, T aspect, T near, T far)
    {
      const T halfFovy = fovy / 2;
      const T tnInv = 1 / std::tan(halfFovy);
      const T nfInv = 1 / (near - far);
      T a = (far + near) * nfInv;
      T b = 2 * far * near * nfInv;
      return Mat4<T>{tnInv / aspect, 0,      0,           0,
                     0,              tnInv,  0,           0,
                     0,              0,      a,           b,
                     0,              0,      -1,          0};
    }
    
    template <typename T, NdcDepth D>
    inline typename std::enable_if<D == NdcDepth::NegativeOneToOne, Mat4<T>>::type
    makePerspective(T fovy, T aspect, T near, T far)
    {
      const T halfFovy = fovy / 2;
      const T tnInv = 1 / std::tan(halfFovy);
      const T nfInv = 1 / (near - far);
      T a = far * nfInv;
      T b = far * near * nfInv;
      return Mat4<T>{tnInv / aspect, 0,      0,           0,
                     0,              tnInv,  0,           0,
                     0,              0,      a,           b,
                     0,              0,      -1,          0};
    }
  }
  
  // https://www.scratchapixel.com/lessons/3d-basic-rendering/perspective-and-orthographic-projection-matrix/projection-matrix-GPU-rendering-pipeline-clipping
  // https://www.scratchapixel.com/lessons/3d-basic-rendering/perspective-and-orthographic-projection-matrix/building-basic-perspective-projection-matrix
  
  template <typename T = float, NdcDepth D = NdcDepth::ZeroToOne>
  inline Mat4<T> makeFrustum(T near, T far, T left, T right, T top, T bottom)
  {
    return Detail::makeFrustum<T, D>(near, far, left, right, top, bottom);
  }
  
  template <typename T = float, NdcDepth D = NdcDepth::ZeroToOne>
  inline Mat4<T> makeOrthographic(T near, T far, T left, T right, T top, T bottom)
  {
    return Detail::makeOrthographic<T, D>(near, far, left, right, top, bottom);
  }
  
  template <typename T, NdcDepth D = NdcDepth::ZeroToOne>
  inline Mat4<T> makePerspective(T fovy, T aspect, T near, T far)
  {
    return Detail::makePerspective<T, D>(fovy, aspect, near, far);
  }
  
  using Vec2f = Vec2<float>;
  using Vec3f = Vec3<float>;
  using Vec4f = Vec4<float>;
  using Vec2d = Vec2<double>;
  using Vec3d = Vec3<double>;
  using Vec4d = Vec4<double>;
  using Mat2f = Mat2<float>;
  using Mat3f = Mat3<float>;
  using Mat4f = Mat4<float>;
  using Mat2d = Mat2<double>;
  using Mat3d = Mat3<double>;
  using Mat4d = Mat4<double>;
}  // namespace Neon
