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

#include "Neon.hpp"

#include <cmath>

#include "utest.h"

#define IGNORE_UNUSED(x) (void)(x)

#if (defined(__GNUC__) || defined(__clang__))
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

#define DEFINE_FIXTURE(FixtureName)\
  struct FixtureName {};\
  UTEST_F_SETUP(FixtureName) {}\
  UTEST_F_TEARDOWN(FixtureName) {}

#define EPSILON_F 1e-5
#define ASSERT_NEARLY_EQ_F(x, y) ASSERT_LT(std::abs(x - y), EPSILON_F)

#define ASSERT_EQ_V2F(v1, v2)\
  ASSERT_EQ(v1.x, v2.x);\
  ASSERT_EQ(v1.y, v2.y)

#define ASSERT_EQ_V3F(v1, v2)\
  ASSERT_EQ(v1.x, v2.x);\
  ASSERT_EQ(v1.y, v2.y);\
  ASSERT_EQ(v1.z, v2.z)

#define ASSERT_EQ_V4F(v1, v2)\
  ASSERT_EQ(v1.x, v2.x);\
  ASSERT_EQ(v1.y, v2.y);\
  ASSERT_EQ(v1.z, v2.z);\
  ASSERT_EQ(v1.w, v2.w)

#define ASSERT_NEARLY_EQ_V2F(v1, v2)\
  ASSERT_NEARLY_EQ_F(v1.x, v2.x);\
  ASSERT_NEARLY_EQ_F(v1.y, v2.y)

#define ASSERT_NEARLY_EQ_V3F(v1, v2)\
  ASSERT_NEARLY_EQ_F(v1.x, v2.x);\
  ASSERT_NEARLY_EQ_F(v1.y, v2.y);\
  ASSERT_NEARLY_EQ_F(v1.z, v2.z)

#define ASSERT_NEARLY_EQ_V4F(v1, v2)\
  ASSERT_NEARLY_EQ_F(v1.x, v2.x);\
  ASSERT_NEARLY_EQ_F(v1.y, v2.y);\
  ASSERT_NEARLY_EQ_F(v1.z, v2.z);\
  ASSERT_NEARLY_EQ_F(v1.w, v2.w)

#define ASSERT_EQ_M2F(m1, m2)\
  ASSERT_EQ(m1.d[0][0], m2.d[0][0]);\
  ASSERT_EQ(m1.d[0][1], m2.d[0][1]);\
  ASSERT_EQ(m1.d[1][0], m2.d[1][0]);\
  ASSERT_EQ(m1.d[1][1], m2.d[1][1])

#define ASSERT_EQ_M3F(m1, m2)\
  ASSERT_EQ(m1.d[0][0], m2.d[0][0]);\
  ASSERT_EQ(m1.d[0][1], m2.d[0][1]);\
  ASSERT_EQ(m1.d[0][2], m2.d[0][2]);\
  ASSERT_EQ(m1.d[1][0], m2.d[1][0]);\
  ASSERT_EQ(m1.d[1][1], m2.d[1][1]);\
  ASSERT_EQ(m1.d[1][2], m2.d[1][2]);\
  ASSERT_EQ(m1.d[2][0], m2.d[2][0]);\
  ASSERT_EQ(m1.d[2][1], m2.d[2][1]);\
  ASSERT_EQ(m1.d[2][2], m2.d[2][2])

#define ASSERT_EQ_M4F(m1, m2)\
  ASSERT_EQ(m1.d[0][0], m2.d[0][0]);\
  ASSERT_EQ(m1.d[0][1], m2.d[0][1]);\
  ASSERT_EQ(m1.d[0][2], m2.d[0][2]);\
  ASSERT_EQ(m1.d[0][3], m2.d[0][3]);\
  ASSERT_EQ(m1.d[1][0], m2.d[1][0]);\
  ASSERT_EQ(m1.d[1][1], m2.d[1][1]);\
  ASSERT_EQ(m1.d[1][2], m2.d[1][2]);\
  ASSERT_EQ(m1.d[1][3], m2.d[1][3]);\
  ASSERT_EQ(m1.d[2][0], m2.d[2][0]);\
  ASSERT_EQ(m1.d[2][1], m2.d[2][1]);\
  ASSERT_EQ(m1.d[2][2], m2.d[2][2]);\
  ASSERT_EQ(m1.d[2][3], m2.d[2][3]);\
  ASSERT_EQ(m1.d[3][0], m2.d[3][0]);\
  ASSERT_EQ(m1.d[3][1], m2.d[3][1]);\
  ASSERT_EQ(m1.d[3][2], m2.d[3][2]);\
  ASSERT_EQ(m1.d[3][3], m2.d[3][3])

#define ASSERT_NEARLY_EQ_M2F(m1, m2)\
  ASSERT_NEARLY_EQ_F(m1.d[0][0], m2.d[0][0]);\
  ASSERT_NEARLY_EQ_F(m1.d[0][1], m2.d[0][1]);\
  ASSERT_NEARLY_EQ_F(m1.d[1][0], m2.d[1][0]);\
  ASSERT_NEARLY_EQ_F(m1.d[1][1], m2.d[1][1])

#define ASSERT_NEARLY_EQ_M3F(m1, m2)\
  ASSERT_NEARLY_EQ_F(m1.d[0][0], m2.d[0][0]);\
  ASSERT_NEARLY_EQ_F(m1.d[0][1], m2.d[0][1]);\
  ASSERT_NEARLY_EQ_F(m1.d[0][2], m2.d[0][2]);\
  ASSERT_NEARLY_EQ_F(m1.d[1][0], m2.d[1][0]);\
  ASSERT_NEARLY_EQ_F(m1.d[1][1], m2.d[1][1]);\
  ASSERT_NEARLY_EQ_F(m1.d[1][2], m2.d[1][2]);\
  ASSERT_NEARLY_EQ_F(m1.d[2][0], m2.d[2][0]);\
  ASSERT_NEARLY_EQ_F(m1.d[2][1], m2.d[2][1]);\
  ASSERT_NEARLY_EQ_F(m1.d[2][2], m2.d[2][2])

#define ASSERT_NEARLY_EQ_M4F(m1, m2)\
  ASSERT_NEARLY_EQ_F(m1.d[0][0], m2.d[0][0]);\
  ASSERT_NEARLY_EQ_F(m1.d[0][1], m2.d[0][1]);\
  ASSERT_NEARLY_EQ_F(m1.d[0][2], m2.d[0][2]);\
  ASSERT_NEARLY_EQ_F(m1.d[0][3], m2.d[0][3]);\
  ASSERT_NEARLY_EQ_F(m1.d[1][0], m2.d[1][0]);\
  ASSERT_NEARLY_EQ_F(m1.d[1][1], m2.d[1][1]);\
  ASSERT_NEARLY_EQ_F(m1.d[1][2], m2.d[1][2]);\
  ASSERT_NEARLY_EQ_F(m1.d[1][3], m2.d[1][3]);\
  ASSERT_NEARLY_EQ_F(m1.d[2][0], m2.d[2][0]);\
  ASSERT_NEARLY_EQ_F(m1.d[2][1], m2.d[2][1]);\
  ASSERT_NEARLY_EQ_F(m1.d[2][2], m2.d[2][2]);\
  ASSERT_NEARLY_EQ_F(m1.d[2][3], m2.d[2][3]);\
  ASSERT_NEARLY_EQ_F(m1.d[3][0], m2.d[3][0]);\
  ASSERT_NEARLY_EQ_F(m1.d[3][1], m2.d[3][1]);\
  ASSERT_NEARLY_EQ_F(m1.d[3][2], m2.d[3][2]);\
  ASSERT_NEARLY_EQ_F(m1.d[3][3], m2.d[3][3])

using namespace Neon;

DEFINE_FIXTURE(VecfTest)

UTEST_F(VecfTest, ctor)
{
  const Vec2f v{1, 2};
  ASSERT_EQ(1, v.x);
  ASSERT_EQ(2, v.y);
}

UTEST_F(VecfTest, subscriptRead)
{
  {
    const Vec2f v{1, 2};
    ASSERT_EQ(1, v[0]);
    ASSERT_EQ(2, v[1]);
  }
  {
    const Vec3f v{1, 2, 3};
    ASSERT_EQ(1, v[0]);
    ASSERT_EQ(2, v[1]);
    ASSERT_EQ(3, v[2]);
  }
  {
    const Vec4f v{1, 2, 3, 4};
    ASSERT_EQ(1, v[0]);
    ASSERT_EQ(2, v[1]);
    ASSERT_EQ(3, v[2]);
    ASSERT_EQ(4, v[3]);
  }
}

UTEST_F(VecfTest, subscriptWrite)
{
  {
    Vec2f v{1, 2};
    v[0] = 3;
    v[1] = 4;
    ASSERT_EQ(3, v[0]);
    ASSERT_EQ(4, v[1]);
  }
  {
    Vec3f v{1, 2, 3};
    v[0] = 3;
    v[1] = 4;
    v[2] = 5;
    ASSERT_EQ(3, v[0]);
    ASSERT_EQ(4, v[1]);
    ASSERT_EQ(5, v[2]);
  }
  {
    Vec4f v{1, 2, 3, 4};
    v[0] = 3;
    v[1] = 4;
    v[2] = 5;
    v[3] = 6;
    ASSERT_EQ(3, v[0]);
    ASSERT_EQ(4, v[1]);
    ASSERT_EQ(5, v[2]);
    ASSERT_EQ(6, v[3]);
  }
}

UTEST_F(VecfTest, addition)
{
  {
    const Vec2f v1{1, 2};
    const Vec2f v2{3, 4};
    const Vec2f result = v1 + v2;
    const Vec2f expected{4, 6};
    ASSERT_EQ_V2F(result, expected);
  }
  {
    const Vec3f v1{1, 2, 3};
    const Vec3f v2{4, 5, 6};
    const Vec3f result = v1 + v2;
    const Vec3f expected{5, 7, 9};
    ASSERT_EQ_V3F(result, expected);
  }
  {
    const Vec4f v1{1, 2, 3, 4};
    const Vec4f v2{5, 6, 7, 8};
    const Vec4f result = v1 + v2;
    const Vec4f expected{6, 8, 10, 12};
    ASSERT_EQ_V4F(result, expected);
  }
}

UTEST_F(VecfTest, increment)
{
  {
    Vec2f v1{1, 2};
    const Vec2f inc{3, 4};
    v1 += inc;
    ASSERT_EQ(v1.x, 4);
    ASSERT_EQ(v1.y, 6);
  }
  {
    Vec3f v1{1, 2, 3};
    const Vec3f inc{4, 5, 6};
    v1 += inc;
    ASSERT_EQ(v1.x, 5);
    ASSERT_EQ(v1.y, 7);
    ASSERT_EQ(v1.z, 9);
  }
  {
    Vec4f v1{1, 2, 3, 4};
    const Vec4f inc{5, 6, 7, 8};
    v1 += inc;
    ASSERT_EQ(v1.x, 6);
    ASSERT_EQ(v1.y, 8);
    ASSERT_EQ(v1.z, 10);
    ASSERT_EQ(v1.w, 12);
  }
}

UTEST_F(VecfTest, negate)
{
  {
    const Vec2f v1{1, 2};
    const Vec2f result = -v1;
    const Vec2f expected{-1, -2};
    ASSERT_EQ_V2F(result, expected);
  }
  {
    const Vec3f v1{1, 2, 3};
    const Vec3f result = -v1;
    const Vec3f expected{-1, -2, -3};
    ASSERT_EQ_V3F(result, expected);
  }
  {
    const Vec4f v1{1, 2, 3, 4};
    const Vec4f result = -v1;
    const Vec4f expected{-1, -2, -3, -4};
    ASSERT_EQ_V4F(result, expected);
  }
}

UTEST_F(VecfTest, subtraction)
{
  {
    const Vec2f v1{1, 2};
    const Vec2f v2{3, 4};
    const Vec2f result = v1 - v2;
    const Vec2f expected{-2, -2};
    ASSERT_EQ_V2F(result, expected);
  }
  {
    const Vec3f v1{1, 2, 3};
    const Vec3f v2{4, 5, 6};
    const Vec3f result = v1 - v2;
    const Vec3f expected{-3, -3, -3};
    ASSERT_EQ_V3F(result, expected);
  }
  {
    const Vec4f v1{1, 2, 3, 4};
    const Vec4f v2{5, 6, 7, 8};
    const Vec4f result = v1 - v2;
    const Vec4f expected{-4, -4, -4, -4};
    ASSERT_EQ_V4F(result, expected);
  }
}

UTEST_F(VecfTest, decrement)
{
  {
    Vec2f v1{3, 5};
    const Vec2f dec{1, 2};
    v1 -= dec;
    ASSERT_EQ(v1.x, 2);
    ASSERT_EQ(v1.y, 3);
  }
  {
    Vec3f v1{3, 5, 7};
    const Vec3f dec{1, 2, 3};
    v1 -= dec;
    ASSERT_EQ(v1.x, 2);
    ASSERT_EQ(v1.y, 3);
    ASSERT_EQ(v1.z, 4);
  }
  {
    Vec4f v1{3, 5, 7, 9};
    const Vec4f dec{1, 2, 3, 4};
    v1 -= dec;
    ASSERT_EQ(v1.x, 2);
    ASSERT_EQ(v1.y, 3);
    ASSERT_EQ(v1.z, 4);
    ASSERT_EQ(v1.w, 5);
  }
}

UTEST_F(VecfTest, scaleUp)
{
  {
    const Vec2f v1{1, 2};
    const Vec2f result = v1 * 10;
    const Vec2f expected{10, 20};
    ASSERT_EQ_V2F(result, expected);
  }
  {
    const Vec3f v1{1, 2, 3};
    const Vec3f result = v1 * 10;
    const Vec3f expected{10, 20, 30};
    ASSERT_EQ_V3F(result, expected);
  }
  {
    const Vec4f v1{1, 2, 3, 4};
    const Vec4f result = v1 * 10;
    const Vec4f expected{10, 20, 30, 40};
    ASSERT_EQ_V4F(result, expected);
  }
}

UTEST_F(VecfTest, scaleUpAssign)
{
  {
    Vec2f v1{1, 2};
    v1 = v1 * 10;
    ASSERT_EQ(v1.x, 10);
    ASSERT_EQ(v1.y, 20);
  }
  {
    Vec3f v1{1, 2, 3};
    v1 = v1 * 10;
    ASSERT_EQ(v1.x, 10);
    ASSERT_EQ(v1.y, 20);
    ASSERT_EQ(v1.z, 30);
  }
  {
    Vec4f v1{1, 2, 3, 4};
    v1 = v1 * 10;
    ASSERT_EQ(v1.x, 10);
    ASSERT_EQ(v1.y, 20);
    ASSERT_EQ(v1.z, 30);
    ASSERT_EQ(v1.w, 40);
  }
}

UTEST_F(VecfTest, multiplication)
{
  {
    const Vec2f v1{2, 3};
    const Vec2f v2{5, 6};
    const Vec2f expected{10, 18};
    const Vec2f result = v1 * v2;
    ASSERT_EQ_V2F(result, expected);
  }
  {
    const Vec3f v1{2, 3, 4};
    const Vec3f v2{5, 6, 7};
    const Vec3f expected{10, 18, 28};
    const Vec3f result = v1 * v2;
    ASSERT_EQ_V3F(result, expected);
  }
  {
    const Vec4f v1{2, 3, 4, 5};
    const Vec4f v2{5, 6, 7, 8};
    const Vec4f expected{10, 18, 28, 40};
    const Vec4f result = v1 * v2;
    ASSERT_EQ_V4F(result, expected);
  }
}

UTEST_F(VecfTest, multiplicationAssign)
{
  {
    Vec2f v1{2, 3};
    const Vec2f v2{5, 6};
    v1 *= v2;
    ASSERT_EQ(v1.x, 10);
    ASSERT_EQ(v1.y, 18);
  }
  {
    Vec3f v1{2, 3, 4};
    const Vec3f v2{5, 6, 7};
    v1 *= v2;
    ASSERT_EQ(v1.x, 10);
    ASSERT_EQ(v1.y, 18);
    ASSERT_EQ(v1.z, 28);
  }
  {
    Vec4f v1{2, 3, 4, 5};
    const Vec4f v2{5, 6, 7, 8};
    v1 *= v2;
    ASSERT_EQ(v1.x, 10);
    ASSERT_EQ(v1.y, 18);
    ASSERT_EQ(v1.z, 28);
    ASSERT_EQ(v1.w, 40);
  }
}

UTEST_F(VecfTest, scaleDown)
{
  {
    const Vec2f v1{10, 20};
    const Vec2f result = v1 / 2;
    const Vec2f expected{5, 10};
    ASSERT_EQ_V2F(result, expected);
  }
  {
    const Vec3f v1{10, 20, 30};
    const Vec3f result = v1 / 2;
    const Vec3f expected{5, 10, 15};
    ASSERT_EQ_V3F(result, expected);
  }
  {
    const Vec4f v1{10, 20, 30, 40};
    const Vec4f result = v1 / 2;
    const Vec4f expected{5, 10, 15, 20};
    ASSERT_EQ_V4F(result, expected);
  }
}

UTEST_F(VecfTest, scaleDownAssign)
{
  {
    Vec2f v1{10, 20};
    v1 = v1 / 2;
    ASSERT_EQ(v1.x, 5);
    ASSERT_EQ(v1.y, 10);
  }
  {
    Vec3f v1{10, 20, 30};
    v1 = v1 / 2;
    ASSERT_EQ(v1.x, 5);
    ASSERT_EQ(v1.y, 10);
    ASSERT_EQ(v1.z, 15);
  }
  {
    Vec4f v1{10, 20, 30, 40};
    v1 = v1 / 2;
    ASSERT_EQ(v1.x, 5);
    ASSERT_EQ(v1.y, 10);
    ASSERT_EQ(v1.z, 15);
    ASSERT_EQ(v1.w, 20);
  }
}

UTEST_F(VecfTest, dot)
{
  {
    const Vec2f v1{1, 2};
    const Vec2f v2{3, 4};
    const float result = dot(v1, v2);
    ASSERT_EQ(result, 11);
  }
  {
    const Vec3f v1{1, 2, 3};
    const Vec3f v2{4, 5, 6};
    const float result = dot(v1, v2);
    ASSERT_EQ(result, 32);
  }
  {
    const Vec4f v1{1, 2, 3, 4};
    const Vec4f v2{5, 6, 7, 8};
    const float result = dot(v1, v2);
    ASSERT_EQ(result, 70);
  }
}

UTEST_F(VecfTest, mag)
{
  {
    const Vec2f v1{3, 4};
    const float result = mag(v1);
    ASSERT_NEARLY_EQ_F(result, 5);
  }
  {
    const Vec3f v1{3, 0, 4};
    const float result = mag(v1);
    ASSERT_NEARLY_EQ_F(result, 5);
  }
  {
    const Vec4f v1{3, 0, 4, 0};
    const float result = mag(v1);
    ASSERT_NEARLY_EQ_F(result, 5);
  }
}

UTEST_F(VecfTest, distance)
{
  {
    const Vec2f v1{3, 0};
    const Vec2f v2{0, 4};
    const float result = distance(v1, v2);
    ASSERT_NEARLY_EQ_F(result, 5);
  }
  {
    const Vec3f v1{3, 0, 0};
    const Vec3f v2{0, 0, 4};
    const float result = distance(v1, v2);
    ASSERT_NEARLY_EQ_F(result, 5);
  }
}

UTEST_F(VecfTest, normalize)
{
  {
    const Vec2f v1{1, 1};
    const Vec2f result = normalize(v1);
    const Vec2f expected{0.707106f, 0.707106f};
    ASSERT_NEARLY_EQ_V2F(result, expected);
  }
  {
    const Vec3f v1{1, 1, 1};
    const Vec3f result = normalize(v1);
    const Vec3f expected{0.57735f, 0.57735f, 0.57735f};
    ASSERT_NEARLY_EQ_V3F(result, expected);
  }
  {
    const Vec4f v1{1, 1, 1, 1};
    const Vec4f result = normalize(v1);
    const Vec4f expected{0.5f, 0.5f, 0.5f, 0.5f};
    ASSERT_NEARLY_EQ_V4F(result, expected);
  }
}

UTEST_F(VecfTest, project)
{
  const Vec2f v1{3, 4};
  const Vec2f v2{0, 1};
  const Vec2f result = project(v1, v2);
  const Vec2f expected{0, 4};
  ASSERT_NEARLY_EQ_V2F(result, expected);
}

UTEST_F(VecfTest, reflect)
{
  {
    const Vec2f v1{1, -1};
    const Vec2f v2{0, 1};
    const Vec2f result = reflect(v1, v2);
    const Vec2f expected{1, 1};
    ASSERT_NEARLY_EQ_V2F(result, expected);
  }
  {
    const Vec3f v1{1, -1, 0};
    const Vec3f v2{0, 1, 0};
    const Vec3f result = reflect(v1, v2);
    const Vec3f expected{1, 1, 0};
    ASSERT_NEARLY_EQ_V2F(result, expected);
  }
}

UTEST_F(VecfTest, refract)
{
  const Vec2f v1{0, -1};
  const Vec2f v2{0, 1};
  const float eta = 0.5f;
  const Vec2f result = refract(v1, v2, eta);
  const Vec2f expected{0.0, -1.0};
  ASSERT_NEARLY_EQ_V2F(result, expected);
}

UTEST_F(VecfTest, rotate)
{
  const Vec3f v{1, 0, 1};
  const Vec3f n{0, 1, 0};
  const float angle = static_cast<float>(degToRad * -45);
  const Vec3f result = rotate(v, n, angle);
  const Vec3f expected{0, 0, 1.414213f};
  ASSERT_NEARLY_EQ_V3F(result, expected);
}

DEFINE_FIXTURE(MatfTest)

UTEST_F(MatfTest, defaultCtor)
{
  {
    const Mat2f m{42};
    ASSERT_EQ(m.d[0][0], 42);
    ASSERT_EQ(m.d[0][1], 0);
    ASSERT_EQ(m.d[1][0], 0);
    ASSERT_EQ(m.d[1][1], 42);
  }
  {
    const Mat3f m{42};
    ASSERT_EQ(m.d[0][0], 42);
    ASSERT_EQ(m.d[0][1], 0);
    ASSERT_EQ(m.d[0][2], 0);
    ASSERT_EQ(m.d[1][0], 0);
    ASSERT_EQ(m.d[1][1], 42);
    ASSERT_EQ(m.d[1][2], 0);
    ASSERT_EQ(m.d[2][0], 0);
    ASSERT_EQ(m.d[2][1], 0);
    ASSERT_EQ(m.d[2][2], 42);
  }
  {
    const Mat4f m{42};
    ASSERT_EQ(m.d[0][0], 42);
    ASSERT_EQ(m.d[0][1], 0);
    ASSERT_EQ(m.d[0][2], 0);
    ASSERT_EQ(m.d[0][3], 0);
    ASSERT_EQ(m.d[1][0], 0);
    ASSERT_EQ(m.d[1][1], 42);
    ASSERT_EQ(m.d[1][2], 0);
    ASSERT_EQ(m.d[1][3], 0);
    ASSERT_EQ(m.d[2][0], 0);
    ASSERT_EQ(m.d[2][1], 0);
    ASSERT_EQ(m.d[2][2], 42);
    ASSERT_EQ(m.d[2][3], 0);
    ASSERT_EQ(m.d[3][0], 0);
    ASSERT_EQ(m.d[3][1], 0);
    ASSERT_EQ(m.d[3][2], 0);
    ASSERT_EQ(m.d[3][3], 42);
  }
}

UTEST_F(MatfTest, vectorCtor)
{
  {
    const Vec2f v1{1, 2};
    const Vec2f v2{10, 20};
    const Mat2f m{v1, v2};
    ASSERT_EQ(m.d[0][0], 1);
    ASSERT_EQ(m.d[0][1], 2);
    ASSERT_EQ(m.d[1][0], 10);
    ASSERT_EQ(m.d[1][1], 20);
  }
  {
    const Vec3f v1{1, 2, 3};
    const Vec3f v2{10, 20, 30};
    const Vec3f v3{100, 200, 300};
    const Mat3f m{v1, v2, v3};
    ASSERT_EQ(m.d[0][0], 1);
    ASSERT_EQ(m.d[0][1], 2);
    ASSERT_EQ(m.d[0][2], 3);
    ASSERT_EQ(m.d[1][0], 10);
    ASSERT_EQ(m.d[1][1], 20);
    ASSERT_EQ(m.d[1][2], 30);
    ASSERT_EQ(m.d[2][0], 100);
    ASSERT_EQ(m.d[2][1], 200);
    ASSERT_EQ(m.d[2][2], 300);
  }
  {
    const Vec4f v1{1, 2, 3, 4};
    const Vec4f v2{10, 20, 30, 40};
    const Vec4f v3{100, 200, 300, 400};
    const Vec4f v4{1000, 2000, 3000, 4000};
    const Mat4f m{v1, v2, v3, v4};
    ASSERT_EQ(m.d[0][0], 1);
    ASSERT_EQ(m.d[0][1], 2);
    ASSERT_EQ(m.d[0][2], 3);
    ASSERT_EQ(m.d[0][3], 4);
    ASSERT_EQ(m.d[1][0], 10);
    ASSERT_EQ(m.d[1][1], 20);
    ASSERT_EQ(m.d[1][2], 30);
    ASSERT_EQ(m.d[1][3], 40);
    ASSERT_EQ(m.d[2][0], 100);
    ASSERT_EQ(m.d[2][1], 200);
    ASSERT_EQ(m.d[2][2], 300);
    ASSERT_EQ(m.d[2][3], 400);
    ASSERT_EQ(m.d[3][0], 1000);
    ASSERT_EQ(m.d[3][1], 2000);
    ASSERT_EQ(m.d[3][2], 3000);
    ASSERT_EQ(m.d[3][3], 4000);
  }
}

UTEST_F(MatfTest, entriesCtor)
{
  {
    const Mat2f m{1, 10,
                  2, 20};
    ASSERT_EQ(m.d[0][0], 1);
    ASSERT_EQ(m.d[0][1], 2);
    ASSERT_EQ(m.d[1][0], 10);
    ASSERT_EQ(m.d[1][1], 20);
  }
  {
    const Mat3f m{1, 10, 100,
                  2, 20, 200,
                  3, 30, 300};
    ASSERT_EQ(m.d[0][0], 1);
    ASSERT_EQ(m.d[0][1], 2);
    ASSERT_EQ(m.d[0][2], 3);
    ASSERT_EQ(m.d[1][0], 10);
    ASSERT_EQ(m.d[1][1], 20);
    ASSERT_EQ(m.d[1][2], 30);
    ASSERT_EQ(m.d[2][0], 100);
    ASSERT_EQ(m.d[2][1], 200);
    ASSERT_EQ(m.d[2][2], 300);
  }
  {
    const Mat4f m{1, 10, 100, 1000,
                  2, 20, 200, 2000,
                  3, 30, 300, 3000,
                  4, 40, 400, 4000};
    ASSERT_EQ(m.d[0][0], 1);
    ASSERT_EQ(m.d[0][1], 2);
    ASSERT_EQ(m.d[0][2], 3);
    ASSERT_EQ(m.d[0][3], 4);
    ASSERT_EQ(m.d[1][0], 10);
    ASSERT_EQ(m.d[1][1], 20);
    ASSERT_EQ(m.d[1][2], 30);
    ASSERT_EQ(m.d[1][3], 40);
    ASSERT_EQ(m.d[2][0], 100);
    ASSERT_EQ(m.d[2][1], 200);
    ASSERT_EQ(m.d[2][2], 300);
    ASSERT_EQ(m.d[2][3], 400);
    ASSERT_EQ(m.d[3][0], 1000);
    ASSERT_EQ(m.d[3][1], 2000);
    ASSERT_EQ(m.d[3][2], 3000);
    ASSERT_EQ(m.d[3][3], 4000);
  }
}

UTEST_F(MatfTest, copyCtor)
{
  {
    const Mat2f other{1, 10,
                      2, 20};
    const Mat2f m{other};
    ASSERT_EQ_M2F(m, other);
  }
  {
    const Mat3f other{1, 10, 100,
                      2, 20, 200,
                      3, 30, 300};
    const Mat3f m{other};
    ASSERT_EQ_M3F(m, other);
  }
  {
    const Mat4f other{1, 10, 100, 1000,
                      2, 20, 200, 2000,
                      3, 30, 300, 3000,
                      4, 40, 400, 4000};
    const Mat4f m{other};
    ASSERT_EQ_M4F(m, other);
  }
}

UTEST_F(MatfTest, copyAssignment)
{
  {
    const Mat2f other{1, 10,
                      2, 20};
    Mat2f m{1, 2,
            3, 4};
    m = other;
    ASSERT_EQ_M2F(m, other);
  }
  {
    const Mat3f other{1, 10, 100,
                      2, 20, 200,
                      3, 30, 300};
    Mat3f m{1, 2, 3,
            4, 5, 6,
            7, 8, 9};
    m = other;
    ASSERT_EQ_M3F(m, other);
  }
  {
    const Mat4f other{1, 10, 100, 1000,
                      2, 20, 200, 2000,
                      3, 30, 300, 3000,
                      4, 40, 400, 4000};
    Mat4f m{1,  2,  3,  4,
            5,  6,  7,  8,
            9,  10, 11, 12,
            13, 14, 15, 16};
    m = other;
    ASSERT_EQ_M4F(m, other);
  }
}

UTEST_F(MatfTest, subscript)
{
  {
    // Read.
    const Vec2f v1{1, 2};
    const Vec2f v2{10, 20};
    Mat2f m{v1, v2};
    ASSERT_EQ_V2F(m[0], v1);
    ASSERT_EQ_V2F(m[1], v2);
    // Write
    const Vec2f nv1{-1, -2};
    const Vec2f nv2{-10, -20};
    m[0] = nv1;
    m[1] = nv2;
    ASSERT_EQ_V2F(m[0], nv1);
    ASSERT_EQ_V2F(m[1], nv2);
  }
  {
    // Read.
    const Vec3f v1{1, 2, 3};
    const Vec3f v2{10, 20, 30};
    const Vec3f v3{100, 200, 300};
    Mat3f m{v1, v2, v3};
    ASSERT_EQ_V2F(m[0], v1);
    ASSERT_EQ_V2F(m[1], v2);
    ASSERT_EQ_V2F(m[2], v3);
    // Write
    const Vec3f nv1{-1, -2, -3};
    const Vec3f nv2{-10, -20, -30};
    const Vec3f nv3{-100, -200, -300};
    m[0] = nv1;
    m[1] = nv2;
    m[2] = nv3;
    ASSERT_EQ_V2F(m[0], nv1);
    ASSERT_EQ_V2F(m[1], nv2);
    ASSERT_EQ_V2F(m[2], nv3);
  }
  {
    // Read.
    const Vec4f v1{1, 2, 3, 4};
    const Vec4f v2{10, 20, 30, 40};
    const Vec4f v3{100, 200, 300, 400};
    const Vec4f v4{1000, 2000, 3000, 4000};
    Mat4f m{v1, v2, v3, v4};
    ASSERT_EQ_V2F(m[0], v1);
    ASSERT_EQ_V2F(m[1], v2);
    ASSERT_EQ_V2F(m[2], v3);
    ASSERT_EQ_V2F(m[3], v4);
    // Write
    const Vec4f nv1{-1, -2, -3, -4};
    const Vec4f nv2{-10, -20, -30, -40};
    const Vec4f nv3{-100, -200, -300, -400};
    const Vec4f nv4{-1000, -2000, -3000, -4000};
    m[0] = nv1;
    m[1] = nv2;
    m[2] = nv3;
    m[3] = nv4;
    ASSERT_EQ_V2F(m[0], nv1);
    ASSERT_EQ_V2F(m[1], nv2);
    ASSERT_EQ_V2F(m[2], nv3);
    ASSERT_EQ_V2F(m[3], nv4);
  }
}

UTEST_F(MatfTest, access)
{
  // TODO
}

UTEST_F(MatfTest, addition)
{
  {
    const Mat2f inc{1, 1,
                    1, 1};
    const Mat2f m{1, 10,
                  2, 20};
    const Mat2f result = m + inc;
    const Mat2f expected{2, 11,
                         3, 21};
    ASSERT_EQ_M2F(result, expected);
  }
  {
    const Mat3f inc{1, 1, 1,
                    1, 1, 1,
                    1, 1, 1};
    const Mat3f m{1, 10, 100,
                  2, 20, 200,
                  3, 30, 300};
    const Mat3f result = m + inc;
    const Mat3f expected{2, 11, 101,
                         3, 21, 201,
                         4, 31, 301};
    ASSERT_EQ_M2F(result, expected);
  }
  {
    const Mat4f inc{1, 1, 1, 1,
                    1, 1, 1, 1,
                    1, 1, 1, 1,
                    1, 1, 1, 1};
    const Mat4f m{1, 10, 100, 1000,
                  2, 20, 200, 2000,
                  3, 30, 300, 3000,
                  4, 40, 400, 4000};
    const Mat4f result = m + inc;
    const Mat4f expected{2, 11, 101, 1001,
                         3, 21, 201, 2001,
                         4, 31, 301, 3001,
                         5, 41, 401, 4001};
    ASSERT_EQ_M2F(result, expected);
  }
}

UTEST_F(MatfTest, negate)
{
  // TODO
}

UTEST_F(MatfTest, decrement)
{
  // TODO
}

UTEST_F(MatfTest, scaleUp)
{
  {
    const Mat2f m{1, 10,
                  2, 20};
    const Mat2f result = m * 2;
    const Mat2f expected{2, 20,
                         4, 40};
    ASSERT_EQ_M2F(result, expected);
  }
  {
    const Mat3f m{1, 10, 100,
                  2, 20, 200,
                  3, 30, 300};
    const Mat3f result = m * 2;
    const Mat3f expected{2, 20, 200,
                         4, 40, 400,
                         6, 60, 600};
    ASSERT_EQ_M2F(result, expected);
  }
  {
    const Mat4f m{1, 10, 100, 1000,
                  2, 20, 200, 2000,
                  3, 30, 300, 3000,
                  4, 40, 400, 4000};
    const Mat4f result = m * 2;
    const Mat4f expected{2, 20, 200, 2000,
                         4, 40, 400, 4000,
                         6, 60, 600, 6000,
                         8, 80, 800, 8000};
    ASSERT_EQ_M2F(result, expected);
  }
}

UTEST_F(MatfTest, scaleUpAssign)
{
  // TODO
}

UTEST_F(MatfTest, scaleDown)
{
  // TODO
}

UTEST_F(MatfTest, scaleDownAssign)
{
  // TODO
}

UTEST_F(MatfTest, multiplyVector)
{
  // Checked with https://www.wolframalpha.com/
  {
    const Mat2f m{1, 2,
                  3, 4};
    const Vec2f v{0.1f, 0.9f};
    const Vec2f result = m * v;
    const Vec2f expected{1.9f, 3.9f};
    ASSERT_NEARLY_EQ_V2F(result, expected);
  }
  {
    const Mat3f m{1, 2, 3,
                  4, 5, 6,
                  7, 8, 9};
    const Vec3f v{0.1f, 0.4f, 0.9f};
    const Vec3f result = m * v;
    const Vec3f expected{3.6f, 7.8f, 12.0f};
    ASSERT_NEARLY_EQ_V2F(result, expected);
  }
  {
    const Mat4f m{1,  2,  3,  4,
                  5,  6,  7,  8,
                  9,  10, 11, 12,
                  13, 14, 15, 16};
    const Vec4f v{0.1f, 0.4f, 0.6f, 0.9f};
    const Vec4f result = m * v;
    const Vec4f expected{6.3f, 14.3f, 22.3f, 30.3f};
    ASSERT_NEARLY_EQ_V2F(result, expected);
  }
}

UTEST_F(MatfTest, multiplyMatrix)
{
  // Checked with https://www.wolframalpha.com/
  {
    const Mat2f m1{1, 2,
                   3, 4};
    const Mat2f m2{2, 3,
                   4, 5};
    const Mat2f result = m1 * m2;
    const Mat2f expected{10, 13,
                         22, 29};
    ASSERT_NEARLY_EQ_M2F(result, expected);
  }
  {
    const Mat3f m1{1, 2, 3,
                   4, 5, 6,
                   7, 8, 9};
    const Mat3f m2{2, 3, 4,
                   5, 6, 7,
                   8, 9, 10};
    const Mat3f result = m1 * m2;
    const Mat3f expected{36,  42,   48,
                         81,  96,   111,
                         126, 150,  174};
    ASSERT_NEARLY_EQ_M3F(result, expected);
  }
  {
    const Mat4f m1{1,  2,  3,  4,
                   5,  6,  7,  8,
                   9,  10, 11, 12,
                   13, 14, 15, 16};
    const Mat4f m2{2,  3,  4, 5,
                   6,  7,  8, 9,
                   10, 11, 12, 13,
                   14, 15, 16, 17};
    const Mat4f result = m1 * m2;
    const Mat4f expected{100, 110, 120, 130,
                         228, 254, 280, 306,
                         356, 398, 440, 482,
                         484, 542, 600, 658};
    ASSERT_NEARLY_EQ_M4F(result, expected);
  }
}

UTEST_F(MatfTest, determinant)
{
  // Checked with https://www.wolframalpha.com/
  {
    const Mat2f m1{1, 2,
                   3, 4};
    const float d = determinant(m1);
    const float expected = -2;
    ASSERT_NEARLY_EQ_F(d, expected);
  }
  {
    const Mat3f m1{2,  3,  5,
                   7,  11, 13,
                   17, 19, 23};
    const float d = determinant(m1);
    const float expected = -78;
    ASSERT_NEARLY_EQ_F(d, expected);
  }
  {
    const Mat4f m1{2,   3,  5,  7,
                   11,  13, 17, 19,
                   23,  29, 31, 37,
                   41,  43, 47, 53};
    const float d = determinant(m1);
    const float expected = 880;
    ASSERT_NEARLY_EQ_F(d, expected);
  }
}

UTEST_F(MatfTest, inverse)
{
  // Checked with https://www.wolframalpha.com/
  {
    const Mat2f m1{1, 2,
                   3, 4};
    const Mat2f i = inverse(m1);
    const Mat2f expected{-2.0f, 1.0f,
                         1.5f,  -0.5f};
    ASSERT_NEARLY_EQ_M2F(i, expected);
  }
  {
    const Mat3f m1{2,  3,  5,
                   7,  11, 13,
                   17, 19, 23};
    const Mat3f i = inverse(m1);
    const Mat3f expected {-0.07692f, -0.33333f, 0.20512f,
                          -0.76923f, 0.5f,      -0.11538f,
                          0.69230f,  -0.16666f, -0.01282f};
    ASSERT_NEARLY_EQ_M3F(i, expected);
  }
  {
    const Mat4f m1{2,   3,  5,  7,
                   11,  13, 17, 19,
                   23,  29, 31, 37,
                   41,  43, 47, 53};
    const Mat4f i = inverse(m1);
    const Mat4f expected{0.27272f,  -0.21818f, -0.2f, 0.18181f,
                         -0.45454f, -0.03636f, 0.3f,  -0.13636f,
                         -0.59090f, 0.69772f,  -0.1f, -0.10227f,
                         0.68181f,  -0.42045f, 0.0f,  0.07954f};
    ASSERT_NEARLY_EQ_M4F(i, expected);
  }
}

UTEST_F(MatfTest, transpose)
{
  {
    const Mat2f m1{1, 2,
                   3, 4};
    const Mat2f result = transpose(m1);
    const Mat2f expected{1, 3,
                         2, 4};
    ASSERT_NEARLY_EQ_M2F(result, expected);
  }
  {
    const Mat3f m1{1, 2, 3,
                   4, 5, 6,
                   7, 8, 9};
    const Mat3f result = transpose(m1);
    const Mat3f expected{1, 4, 7,
                         2, 5, 8,
                         3, 6, 9};
    ASSERT_NEARLY_EQ_M3F(result, expected);
  }
  {
    const Mat4f m1{1,  2,  3,  4,
                   5,  6,  7,  8,
                   9,  10, 11, 12,
                   13, 14, 15, 16};
    const Mat4f result = transpose(m1);
    const Mat4f expected{1, 5, 9,  13,
                         2, 6, 10, 14,
                         3, 7, 11, 15,
                         4, 8, 12, 16};
    ASSERT_NEARLY_EQ_M4F(result, expected);
  }
}

DEFINE_FIXTURE(MatrixTransformations)

// TODO(Fouad): Test each function properly.
UTEST_F(MatrixTransformations, temporary)
{
  const float yaw = static_cast<float>(degToRad) * 45.0f;
  const float pitch = static_cast<float>(degToRad) * 45.0f;
  const float roll = static_cast<float>(degToRad) * 45.0f;

  const Mat2f mat2Rot2D = makeRotation2D(roll);
  IGNORE_UNUSED(mat2Rot2D);
  
  const Mat3f mat3Rot3D = makeRotation3D(yaw, pitch, roll);
  IGNORE_UNUSED(mat3Rot3D);
  
  const Mat3f mat3Rot3DX = makeRotation3DX(pitch);
  IGNORE_UNUSED(mat3Rot3DX);
  const Mat3f mat3Rot3DY = makeRotation3DY(yaw);
  IGNORE_UNUSED(mat3Rot3DY);
  const Mat3f mat3Rot3DZ = makeRotation3DX(roll);
  IGNORE_UNUSED(mat3Rot3DZ);
  
  const Vec3f axis {0, 0, 1};
  const Mat3f mat3Rot3DAxisAngle = makeRotation3D(axis, roll);
  IGNORE_UNUSED(mat3Rot3DAxisAngle);
  
  const Vec3f origin{0, 0, 10};
  const Vec3f lookAt{0};
  const Vec3f worldUp{0, 1, 0};
  const Mat4f mat4LookAt = makeLookAt(origin, lookAt, worldUp);
  IGNORE_UNUSED(mat4LookAt);
  
  const float near = 0.3f;
  const float far = 1e+5f;
  const float left = -100.0f;
  const float right = 100.0f;
  const float bottom = -100.0f;
  const float top = 100.0f;
  const Mat4f mat4Frustum = makeFrustum(near, far, left, right, top, bottom);
  IGNORE_UNUSED(mat4Frustum);
  const Mat4f mat4Ortho = makeFrustum(near, far, left, right, top, bottom);
  IGNORE_UNUSED(mat4Ortho);
  const float fovy = static_cast<float>(degToRad) * 75.f;
  const float aspect = 1.0f;
  const Mat4f mat4Pers = makePerspective(fovy, aspect, near, far);
  IGNORE_UNUSED(mat4Pers);
}

UTEST_F(MatrixTransformations, mvpInRhcToNdcInLhc)
{
  const Vec3f worldPoint{0};
  const Vec3f worldUp{0, 1, 0};
  const Vec3f cameraPoint{0, 0, 5};
  
  const float left = -1;
  const float right = 1;
  const float bottom = -1;
  const float top = 1;
  const float near = 0;
  const float far = 10;
  
  const Mat4f lookAt = makeLookAt(cameraPoint, worldPoint, worldUp);
  const Mat4f ortho = makeOrthographic(near, far, left, right, top, bottom);
  
  const Vec4f viewPoint = lookAt * Vec4f{worldPoint, 1};
  const Vec4f expectedViewPoint{0, 0, -5, 1};
  ASSERT_NEARLY_EQ_V4F(viewPoint, expectedViewPoint);
  
  const Vec4f vpPoint = ortho * viewPoint;
  const Vec4f expectedVpPoint{0, 0, 0.5, 1.0};
  ASSERT_NEARLY_EQ_V4F(vpPoint, expectedVpPoint);
}


UTEST_MAIN()
