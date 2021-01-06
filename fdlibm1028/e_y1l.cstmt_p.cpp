#include "../ScDebug/scdebug.h"
/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 */

/* Long double expansions are
  Copyright (C) 2001 Stephen L. Moshier <moshier@na-net.ornl.gov>
  and are incorporated herein by permission of the author.  The author
  reserves the right to distribute this material elsewhere under different
  copying permissions.  These modifications are distributed here under
  the following terms:

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, see
    <http://www.gnu.org/licenses/>.  */

/* __ieee754_y1(x)
 * Bessel function of the second kind of order one.
 * Method -- y1(x):
 *	1. screen out x<=0 cases: y1(0)=-inf, y1(x<0)=NaN
 *	2. For x<2.
 *	   Since
 *		y1(x) = 2/pi*(j1(x)*(ln(x/2)+Euler)-1/x-x/2+5/64*x^3-...)
 *	   therefore y1(x)-2/pi*j1(x)*ln(x)-1/x is an odd function.
 *	   We use the following function to approximate y1,
 *		y1(x) = x*U(z)/V(z) + (2/pi)*(j1(x)*ln(x)-1/x), z= x^2
 *	   Note: For tiny x, 1/x dominate y1 and hence
 *		y1(tiny) = -2/pi/tiny
 *	3. For x>=2.
 *		y1(x) = sqrt(2/(pi*x))*(p1(x)*sin(x1)+q1(x)*cos(x1))
 *	   where x1 = x-3*pi/4. It is better to compute sin(x1),cos(x1)
 *	   by method mentioned above.
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

long double __ieee754_y1l(long double x) {
  long double z, s, c, ss, cc, u, v;
  int32_t ix;
  uint32_t se, i0, i1;

  static const long double one = 1.0L;
  static const long double invsqrtpi =
      5.6418958354775628694807945156077258584405e-1L;
  static const long double tpi = 6.3661977236758134307553505349005744813784e-1L;
  static const long double zero = 0.0;

  /* Y1(x) = 2/pi * (log(x) * j1(x) - 1/x) + x R(x^2)
     0 <= x <= 2
     Peak relative error 2.3e-23 */
  static const long double U0[6] = {
    (0.0 - 5.908077186259914699178903164682444848615E10L);
  long double temp_var_for_const_0, temp_var_for_const_1;
  , 1.546219327181478013495975514375773435962E10L,
      (0.0 - 6.438303331169223128870035584107053228235E8L);
  long double temp_var_for_const_2, temp_var_for_const_3;
  long double temp_var_for_tac_0;
  computeLdSub((Addr)&temp_var_for_tac_0,
               {(Addr) &(temp_var_for_const_1 = 0.0),
                (Addr) &(temp_var_for_const_0 =
                             5.908077186259914699178903164682444848615E10L)},
               "/home/shijia/Public/testprogram/e_y1l.c_e.c:74:12");
  , 9.708540045657182600665968063824819371216E6L,
      (0.0 - 6.138043997084355564619377183564196265471E4L);
  long double temp_var_for_const_4, temp_var_for_const_5;
  long double temp_var_for_tac_1;
  computeLdSub((Addr)&temp_var_for_tac_1,
               {(Addr) &(temp_var_for_const_3 = 0.0),
                (Addr) &(temp_var_for_const_2 =
                             6.438303331169223128870035584107053228235E8L)},
               "/home/shijia/Public/testprogram/e_y1l.c_e.c:76:12");
  , 1.418503228220927321096904291501161800215E2L
};

static const long double V0[5] = {
    3.013447341682896694781964795373783679861E11L,
    4.669546565705981649470005402243136124523E9L,
    3.595056091631351184676890179233695857260E7L,
    1.761554028569108722903944659933744317994E5L,
    5.668480419646516568875555062047234534863E2L
    /*  1.000000000000000000000000000000000000000E0L, */
};

GET_LDOUBLE_WORDS(se, i0, i1, x);
ix = se & IEEE854_LONG_DOUBLE_MAXEXP;
/* if Y1(NaN) is NaN, Y1(-inf) is NaN, Y1(inf) is 0 */
if (se & 0x8000)
  return zero / (zero * x);
if (ix >= IEEE854_LONG_DOUBLE_MAXEXP)
  return one / (x + x * x);
if ((i0 | i1) == 0)
  return -HUGE_VALL + x; /* -inf and overflow exception.  */
if (ix >= 0x4000) {      /* |x| >= 2.0 */
  __ieee754_sincosl(x, &s, &c);
  ss = -s - c;
  cc = s - c;
  if (ix < 0x7ffe) { /* make sure x+x not overflow */
    z = __ieee754_cosl(x + x);
    if ((s * c) > zero)
      cc = z / ss;
    else
      ss = z / cc;
  }
  /* y1(x) = sqrt(2/(pi*x))*(p1(x)*sin(x0)+q1(x)*cos(x0))
   * where x0 = x-3pi/4
   *      Better formula:
   *              cos(x0) = cos(x)cos(3pi/4)+sin(x)sin(3pi/4)
   *                      =  1/sqrt(2) * (sin(x) - cos(x))
   *              sin(x0) = sin(x)cos(3pi/4)-cos(x)sin(3pi/4)
   *                      = -1/sqrt(2) * (cos(x) + sin(x))
   * To avoid cancellation, use
   *              sin(x) +- cos(x) = -cos(2x)/(sin(x) -+ cos(x))
   * to compute the worse one.
   */
  if (ix > 0x4080)
    z = (invsqrtpi * ss) / __ieee754_sqrtl(x);
  else {
    u = __j1_y1_ponel(x);
    v = __j1_y1_qonel(x);
    z = invsqrtpi * (u * ss + v * cc) / __ieee754_sqrtl(x);
  }
  return z;
}
if (ix <= 0x3fbe) { /* x < 2**-65 */
  return (-tpi / x);
}
z = x * x;
long double temp_var_for_tac_2;
computeLdSub((Addr)&temp_var_for_tac_2,
             {(Addr) &(temp_var_for_const_5 = 0.0),
              (Addr) &(temp_var_for_const_4 =
                           6.138043997084355564619377183564196265471E4L)},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:131:9");
computeLdMul((Addr)&z, {(Addr)&x, (Addr)&x},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:131:5");
u = U0[0] + z * (U0[1] + z * (U0[2] + z * (U0[3] + z * (U0[4] + z * U0[5]))));
long double temp_var_for_const_6, temp_var_for_const_7, temp_var_for_const_8,
    temp_var_for_const_9, temp_var_for_const_10, temp_var_for_const_11;
long double temp_var_for_tac_3, temp_var_for_tac_4, temp_var_for_tac_5,
    temp_var_for_tac_6, temp_var_for_tac_7, temp_var_for_tac_8,
    temp_var_for_tac_9, temp_var_for_tac_10, temp_var_for_tac_11;
computeLdMul((Addr)&temp_var_for_tac_3,
             {(Addr)&z, (Addr) &(temp_var_for_const_6 = U0[5])},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:132:65");
computeLdAdd((Addr)&temp_var_for_tac_4, {(Addr) &(temp_var_for_const_7 = U0[4]),
                                         (Addr)&temp_var_for_tac_3},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:132:56");
computeLdMul((Addr)&temp_var_for_tac_5, {(Addr)&z, (Addr)&temp_var_for_tac_4},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:132:52");
computeLdAdd((Addr)&temp_var_for_tac_6, {(Addr) &(temp_var_for_const_8 = U0[3]),
                                         (Addr)&temp_var_for_tac_5},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:132:43");
computeLdMul((Addr)&temp_var_for_tac_7, {(Addr)&z, (Addr)&temp_var_for_tac_6},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:132:39");
computeLdAdd((Addr)&temp_var_for_tac_8, {(Addr) &(temp_var_for_const_9 = U0[2]),
                                         (Addr)&temp_var_for_tac_7},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:132:30");
computeLdMul((Addr)&temp_var_for_tac_9, {(Addr)&z, (Addr)&temp_var_for_tac_8},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:132:26");
computeLdAdd((Addr)&temp_var_for_tac_10,
             {(Addr) &(temp_var_for_const_10 = U0[1]),
              (Addr)&temp_var_for_tac_9},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:132:17");
computeLdMul((Addr)&temp_var_for_tac_11, {(Addr)&z, (Addr)&temp_var_for_tac_10},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:132:13");
computeLdAdd((Addr)&u, {(Addr) &(temp_var_for_const_11 = U0[0]),
                        (Addr)&temp_var_for_tac_11},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:132:5");
v = V0[0] + z * (V0[1] + z * (V0[2] + z * (V0[3] + z * (V0[4] + z))));
long double temp_var_for_const_12, temp_var_for_const_13, temp_var_for_const_14,
    temp_var_for_const_15, temp_var_for_const_16;
long double temp_var_for_tac_12, temp_var_for_tac_13, temp_var_for_tac_14,
    temp_var_for_tac_15, temp_var_for_tac_16, temp_var_for_tac_17,
    temp_var_for_tac_18, temp_var_for_tac_19;
computeLdAdd((Addr)&temp_var_for_tac_12,
             {(Addr) &(temp_var_for_const_12 = V0[4]), (Addr)&z},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:133:56");
computeLdMul((Addr)&temp_var_for_tac_13, {(Addr)&z, (Addr)&temp_var_for_tac_12},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:133:52");
computeLdAdd((Addr)&temp_var_for_tac_14,
             {(Addr) &(temp_var_for_const_13 = V0[3]),
              (Addr)&temp_var_for_tac_13},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:133:43");
computeLdMul((Addr)&temp_var_for_tac_15, {(Addr)&z, (Addr)&temp_var_for_tac_14},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:133:39");
computeLdAdd((Addr)&temp_var_for_tac_16,
             {(Addr) &(temp_var_for_const_14 = V0[2]),
              (Addr)&temp_var_for_tac_15},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:133:30");
computeLdMul((Addr)&temp_var_for_tac_17, {(Addr)&z, (Addr)&temp_var_for_tac_16},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:133:26");
computeLdAdd((Addr)&temp_var_for_tac_18,
             {(Addr) &(temp_var_for_const_15 = V0[1]),
              (Addr)&temp_var_for_tac_17},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:133:17");
computeLdMul((Addr)&temp_var_for_tac_19, {(Addr)&z, (Addr)&temp_var_for_tac_18},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:133:13");
computeLdAdd((Addr)&v, {(Addr) &(temp_var_for_const_16 = V0[0]),
                        (Addr)&temp_var_for_tac_19},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:133:5");
long double temp_var_for_ext_0;
temp_var_for_ext_0 =
    (x * (u / v) + tpi * (__ieee754_j1l(x) * __ieee754_logl(x) - one / x));
long double temp_var_for_const_17, temp_var_for_const_18;
long double temp_var_for_tac_20, temp_var_for_tac_21, temp_var_for_tac_22,
    temp_var_for_tac_23, temp_var_for_tac_24;
computeLdMul((Addr)&temp_var_for_tac_21, {(Addr)&x, (Addr)&temp_var_for_tac_20},
             "toString(biExpr->getExprLoc())");
computeLdDiv((Addr)&temp_var_for_tac_20, {(Addr)&u, (Addr)&v},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:136:10");
computeLdDiv((Addr)&temp_var_for_tac_22,
             {(Addr) &(temp_var_for_const_17 = one), (Addr)&x},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:136:66");computeLdSub((Addr)&temp_var_for_tac_23,{(Addr)&__ieee754_j1l(getFVbyShadow<int>((Addr)&x) * __ieee754_logl(getFVbyShadow<int>((Addr)&x),(Addr)&temp_var_for_tac_22},"/home/shijia/Public/testprogram/e_y1l.c_e.c:136:26");
computeLdMul((Addr)&temp_var_for_tac_24, {(Addr) &(temp_var_for_const_18 = tpi),
                                          (Addr)&temp_var_for_tac_23},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:136:20");
computeLdAdd((Addr)&temp_var_for_ext_0,
             {(Addr)&temp_var_for_tac_21, (Addr)&temp_var_for_tac_24},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:135:22");
callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
callExp++; /*identify the function is  add move tmpShadow*/
return temp_var_for_ext_0;
}

/* wrapper y1 */
long double __y1l(long double x) {
  if ((islessequal(x, 0.0) || isgreater(x, X_TLOSS)) &&
      _LIB_VERSION != _IEEE_) {
    if (x < 0.0) {
      /* d = zero/(x-x) */
      feraiseexcept(FE_INVALID);
      return __kernel_standard_l(x, x, -HUGE_VALL, KMATHERRL_Y1_MINUS);
    } else if (x == 0.0)
      /* d = -one/(x-x) */
      return __kernel_standard_l(x, x, -HUGE_VALL, KMATHERRL_Y1_ZERO);
    else if (_LIB_VERSION != _POSIX_)
      /* y1(x>X_TLOSS) */
      return __kernel_standard_l(x, x, 0.0l, KMATHERRL_Y1_TLOSS);
  }

  long double temp_var_for_ext_1;
  temp_var_for_ext_1 = __ieee754_y1l(x);
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

__typeof(__y1l) y1l __attribute__((weak, alias("__y1l")));

#endif
