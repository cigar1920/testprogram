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
      (long double temp_var_for_tac_0;
  long double temp_var_for_const_0, temp_var_for_const_1;
  temp_var_for_tac_0 = 0.0 - 5.908077186259914699178903164682444848615E10L;

),
      1.546219327181478013495975514375773435962E10L,
      (long double temp_var_for_tac_1;long double temp_var_for_const_2,temp_var_for_const_3;temp_var_for_tac_1 = 0.0 - 6.438303331169223128870035584107053228235E8L;

),
      9.708540045657182600665968063824819371216E6L,
      (long double temp_var_for_tac_2;long double temp_var_for_const_4,temp_var_for_const_5;temp_var_for_tac_2 = 0.0 - 6.138043997084355564619377183564196265471E4L;

),
      1.418503228220927321096904291501161800215E2L
};

static const long double V0[5] = {
    3.013447341682896694781964795373783679861E11L,
    4.669546565705981649470005402243136124523E9L,
    3.595056091631351184676890179233695857260E7L,
    1.761554028569108722903944659933744317994E5L,
    5.668480419646516568875555062047234534863E2L
    /*  1.000000000000000000000000000000000000000E0L, */
};

long double temp_var_for_const_6;
ew_u.value = x;
computeLdSub((Addr)&temp_var_for_tac_0,
             {(Addr) &(temp_var_for_const_1 = 0.0),
              (Addr) &(temp_var_for_const_0 =
                           5.908077186259914699178903164682444848615E10L)},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:72:12");
computeLdSub((Addr)&temp_var_for_tac_1,
             {(Addr) &(temp_var_for_const_3 = 0.0),
              (Addr) &(temp_var_for_const_2 =
                           6.438303331169223128870035584107053228235E8L)},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:74:12");
computeLdSub((Addr)&temp_var_for_tac_2,
             {(Addr) &(temp_var_for_const_5 = 0.0),
              (Addr) &(temp_var_for_const_4 =
                           6.138043997084355564619377183564196265471E4L)},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:76:12");
AssignLd({(Addr) &(temp_var_for_const_6 = ew_u.value)}, (Addr)&x,
         "/home/shijia/Public/testprogram/e_y1l.c_e.c:88:3 "
         "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
;
ix = se & IEEE854_LONG_DOUBLE_MAXEXP;
/* if Y1(NaN) is NaN, Y1(-inf) is NaN, Y1(inf) is 0 */
if (se & 0x8000) {
  long double temp_var_for_ext_0;
  long double temp_var_for_tac_3, temp_var_for_tac_4;
  long double temp_var_for_const_7, temp_var_for_const_8;
  temp_var_for_tac_3 = zero * x;

  temp_var_for_tac_4 = zero / temp_var_for_tac_3;

  temp_var_for_ext_0 = temp_var_for_tac_4;
  computeLdMul((Addr)&temp_var_for_tac_3,
               {(Addr) &(temp_var_for_const_7 = zero), (Addr)&x},
               "/home/shijia/Public/testprogram/e_y1l.c_e.c:93:39");
  computeLdDiv(
      (Addr)&temp_var_for_tac_4,
      {(Addr) &(temp_var_for_const_8 = zero), (Addr)&temp_var_for_tac_3},
      "/home/shijia/Public/testprogram/e_y1l.c_e.c:93:31");
  AssignLd({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_4,
           "/home/shijia/Public/testprogram/e_y1l.c_e.c:93:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

if (ix >= IEEE854_LONG_DOUBLE_MAXEXP) {
  long double temp_var_for_ext_1;
  long double temp_var_for_tac_5, temp_var_for_tac_6, temp_var_for_tac_7;
  long double temp_var_for_const_9;
  temp_var_for_tac_5 = x * x;

  temp_var_for_tac_6 = x + temp_var_for_tac_5;

  temp_var_for_tac_7 = one / temp_var_for_tac_6;

  temp_var_for_ext_1 = temp_var_for_tac_7;
  computeLdMul((Addr)&temp_var_for_tac_5, {(Addr)&x, (Addr)&x},
               "/home/shijia/Public/testprogram/e_y1l.c_e.c:101:39");
  computeLdAdd((Addr)&temp_var_for_tac_6, {(Addr)&x, (Addr)&temp_var_for_tac_5},
               "/home/shijia/Public/testprogram/e_y1l.c_e.c:101:35");
  computeLdDiv((Addr)&temp_var_for_tac_7, {(Addr) &(temp_var_for_const_9 = one),
                                           (Addr)&temp_var_for_tac_6},
               "/home/shijia/Public/testprogram/e_y1l.c_e.c:101:30");
  AssignLd({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_7,
           "/home/shijia/Public/testprogram/e_y1l.c_e.c:101:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

if ((i0 | i1) == 0) {
  long double temp_var_for_ext_2;
  long double temp_var_for_tac_8;
  long double temp_var_for_const_10;
  temp_var_for_callexp_0 = __builtin_huge_vall();
  temp_var_for_tac_8 = (-(temp_var_for_callexp_0)) + x;

  temp_var_for_ext_2 = temp_var_for_tac_8;
  computeLdAdd(
      (Addr)&temp_var_for_tac_8,
      {(Addr) &(temp_var_for_const_10 = (-(temp_var_for_callexp_0))), (Addr)&x},
      "/home/shijia/Public/testprogram/e_y1l.c_e.c:109:37");
  AssignLd({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_8,
           "/home/shijia/Public/testprogram/e_y1l.c_e.c:109:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
  callExp++; /*identify the function is  add move tmpShadow*/
  return (0.0 - var_for_e)xt_2;
}
/* -inf and overflow exception.  */
if (ix >= 0x4000) { /* |x| >= 2.0 */
  __ieee754_sincosl(x, &s, &c);
  long double temp_var_for_tac_9, temp_var_for_tac_10;
  long double temp_var_for_const_11;
  temp_var_for_tac_9 = 0.0 - s;

  temp_var_for_tac_10 = temp_var_for_tac_9 - c;

  ss = temp_var_for_tac_10;
  computeLdSub((Addr)&temp_var_for_tac_9,
               {(Addr) &(temp_var_for_const_11 = 0.0), (Addr)&s},
               "/home/shijia/Public/testprogram/e_y1l.c_e.c:117:15");
  computeLdSub((Addr)&temp_var_for_tac_10,
               {(Addr)&temp_var_for_tac_9, (Addr)&c},
               "/home/shijia/Public/testprogram/e_y1l.c_e.c:117:20");
  AssignLd({(Addr)&ss}, (Addr)&temp_var_for_tac_10,
           "/home/shijia/Public/testprogram/e_y1l.c_e.c:117:8");
  ;
  long double temp_var_for_tac_11;
  temp_var_for_tac_11 = s - c;

  cc = temp_var_for_tac_11;
  computeLdSub((Addr)&temp_var_for_tac_11, {(Addr)&s, (Addr)&c},
               "/home/shijia/Public/testprogram/e_y1l.c_e.c:118:12");
  AssignLd({(Addr)&cc}, (Addr)&temp_var_for_tac_11,
           "/home/shijia/Public/testprogram/e_y1l.c_e.c:118:8");
  ;
  if (ix < 0x7ffe) { /* make sure x+x not overflow */
    long double temp_var_for_tac_12;
    long double temp_var_for_const_12;
    long double temp_var_for_callexp_1;

    temp_var_for_tac_12 = x + x;

    temp_var_for_callexp_1 = __ieee754_cosl(temp_var_for_tac_12);
    z = temp_var_for_callexp_1;
    computeLdAdd((Addr)&temp_var_for_tac_12, {(Addr)&x, (Addr)&x},
                 "/home/shijia/Public/testprogram/e_y1l.c_e.c:120:28");
    AssignLd({(Addr)&z},
             (Addr) &(temp_var_for_const_12 = temp_var_for_callexp_1),
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:120:9");
    ;
    if (int temp_var_for_tac_13, temp_var_for_tac_14; int temp_var_for_const_13;
        temp_var_for_tac_13 = s * c;

        temp_var_for_tac_14 = temp_var_for_tac_13 > zero;

        ) {
      long double temp_var_for_tac_15;
      temp_var_for_tac_15 = z / ss;

      cc = temp_var_for_tac_15;
      computeLdMul((Addr)&temp_var_for_tac_13, {(Addr)&s, (Addr)&c},
                   "/home/shijia/Public/testprogram/e_y1l.c_e.c:121:14");
      compute(
          (Addr)&temp_var_for_tac_14,
          {(Addr)&temp_var_for_tac_13, (Addr) &(temp_var_for_const_13 = zero)},
          "/home/shijia/Public/testprogram/e_y1l.c_e.c:121:19");
      computeLdDiv((Addr)&temp_var_for_tac_15, {(Addr)&z, (Addr)&ss},
                   "/home/shijia/Public/testprogram/e_y1l.c_e.c:122:16");
      AssignLd({(Addr)&cc}, (Addr)&temp_var_for_tac_15,
               "/home/shijia/Public/testprogram/e_y1l.c_e.c:122:12");
      ;
    }

    else {
      long double temp_var_for_ext_3;
      long double temp_var_for_tac_16;
      temp_var_for_tac_16 = z / cc;

      temp_var_for_ext_3 = temp_var_for_tac_16;
      computeLdDiv((Addr)&temp_var_for_tac_16, {(Addr)&z, (Addr)&cc},
                   "/home/shijia/Public/testprogram/e_y1l.c_e.c:127:32");
      AssignLd({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_16,
               "/home/shijia/Public/testprogram/e_y1l.c_e.c:127:28");
      ; // ss
      /*(ss)(z)(cc)(z)*/
      ss = temp_var_for_ext_3;
      AssignLd({(Addr)&ss}, (Addr)&temp_var_for_ext_3,
               "/home/shijia/Public/testprogram/e_y1l.c_e.c:129:12");
      ;
    }
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
  if (ix > 0x4080) {
    long double temp_var_for_ext_4;
    long double temp_var_for_tac_17, temp_var_for_tac_18;
    long double temp_var_for_const_14, temp_var_for_const_15;
    long double temp_var_for_callexp_2;

    temp_var_for_tac_17 = invsqrtpi * ss;

    temp_var_for_callexp_2 = __ieee754_sqrtl(x);
    temp_var_for_tac_18 = temp_var_for_tac_17 / temp_var_for_callexp_2;

    temp_var_for_ext_4 = temp_var_for_tac_18;
    computeLdMul((Addr)&temp_var_for_tac_17,
                 {(Addr) &(temp_var_for_const_14 = invsqrtpi), (Addr)&ss},
                 "/home/shijia/Public/testprogram/e_y1l.c_e.c:145:39");
    computeLdDiv((Addr)&temp_var_for_tac_18,
                 {(Addr)&temp_var_for_tac_17,
                  (Addr) &(temp_var_for_const_15 = temp_var_for_callexp_2)},
                 "/home/shijia/Public/testprogram/e_y1l.c_e.c:145:45");
    AssignLd({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_18,
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:145:26");
    ; // z
    /*(cc)(z)(__ieee754_sqrtl(x))(ss)(invsqrtpi)*/
    z = temp_var_for_ext_4;
    AssignLd({(Addr)&z}, (Addr)&temp_var_for_ext_4,
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:147:9");
    ;
  }

  else {
    long double temp_var_for_const_16;
    long double temp_var_for_callexp_3;

    temp_var_for_callexp_3 = __j1_y1_ponel(x);
    u = temp_var_for_callexp_3;
    AssignLd({(Addr)&u},
             (Addr) &(temp_var_for_const_16 = temp_var_for_callexp_3),
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:151:9");
    ;
    long double temp_var_for_const_17;
    long double temp_var_for_callexp_4;

    temp_var_for_callexp_4 = __j1_y1_qonel(x);
    v = temp_var_for_callexp_4;
    AssignLd({(Addr)&v},
             (Addr) &(temp_var_for_const_17 = temp_var_for_callexp_4),
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:152:9");
    ;
    long double temp_var_for_tac_19, temp_var_for_tac_20, temp_var_for_tac_21,
        temp_var_for_tac_22, temp_var_for_tac_23;
    long double temp_var_for_const_18, temp_var_for_const_19;
    long double temp_var_for_callexp_5;

    temp_var_for_tac_19 = u * ss;

    temp_var_for_tac_20 = v * cc;

    temp_var_for_tac_21 = temp_var_for_tac_19 + temp_var_for_tac_20;

    temp_var_for_tac_22 = invsqrtpi * temp_var_for_tac_21;

    temp_var_for_callexp_5 = __ieee754_sqrtl(x);
    temp_var_for_tac_23 = temp_var_for_tac_22 / temp_var_for_callexp_5;

    z = temp_var_for_tac_23;
    computeLdMul((Addr)&temp_var_for_tac_19, {(Addr)&u, (Addr)&ss},
                 "/home/shijia/Public/testprogram/e_y1l.c_e.c:153:26");
    computeLdMul((Addr)&temp_var_for_tac_20, {(Addr)&v, (Addr)&cc},
                 "/home/shijia/Public/testprogram/e_y1l.c_e.c:153:35");
    computeLdAdd((Addr)&temp_var_for_tac_21,
                 {(Addr)&temp_var_for_tac_19, (Addr)&temp_var_for_tac_20},
                 "/home/shijia/Public/testprogram/e_y1l.c_e.c:153:31");
    computeLdMul((Addr)&temp_var_for_tac_22,
                 {(Addr) &(temp_var_for_const_18 = invsqrtpi),
                  (Addr)&temp_var_for_tac_21},
                 "/home/shijia/Public/testprogram/e_y1l.c_e.c:153:21");
    computeLdDiv((Addr)&temp_var_for_tac_23,
                 {(Addr)&temp_var_for_tac_22,
                  (Addr) &(temp_var_for_const_19 = temp_var_for_callexp_5)},
                 "/home/shijia/Public/testprogram/e_y1l.c_e.c:153:41");
    AssignLd({(Addr)&z}, (Addr)&temp_var_for_tac_23,
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:153:9");
    ;
  }
  long double temp_var_for_ext_5;
  temp_var_for_ext_5 = z;
  AssignLd({(Addr)&temp_var_for_ext_5}, (Addr)&z,
           "/home/shijia/Public/testprogram/e_y1l.c_e.c:156:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_5;
}
if (ix <= 0x3fbe) { /* x < 2**-65 */
  long double temp_var_for_ext_6;
  long double temp_var_for_tac_24;
  long double temp_var_for_const_20;
  temp_var_for_tac_24 = (-(tpi)) / x;

  temp_var_for_ext_6 = temp_var_for_tac_24;
  computeLdDiv((Addr)&temp_var_for_tac_24,
               {(Addr) &(temp_var_for_const_20 = (-(tpi))), (Addr)&x},
               "/home/shijia/Public/testprogram/e_y1l.c_e.c:163:32");
  AssignLd({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_24,
           "/home/shijia/Public/testprogram/e_y1l.c_e.c:163:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_(0.0 - or_) ext_6;
}
long double temp_var_for_tac_25;
temp_var_for_tac_25 = x * x;

z = temp_var_for_tac_25;
computeLdMul((Addr)&temp_var_for_tac_25, {(Addr)&x, (Addr)&x},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:168:9");
AssignLd({(Addr)&z}, (Addr)&temp_var_for_tac_25,
         "/home/shijia/Public/testprogram/e_y1l.c_e.c:168:5");
;
long double temp_var_for_tac_26, temp_var_for_tac_27, temp_var_for_tac_28,
    temp_var_for_tac_29, temp_var_for_tac_30, temp_var_for_tac_31,
    temp_var_for_tac_32, temp_var_for_tac_33, temp_var_for_tac_34,
    temp_var_for_tac_35;
long double temp_var_for_const_21, temp_var_for_const_22, temp_var_for_const_23,
    temp_var_for_const_24, temp_var_for_const_25, temp_var_for_const_26;
temp_var_for_tac_26 = z * U0[5];

temp_var_for_tac_27 = U0[4] + temp_var_for_tac_26;

temp_var_for_tac_28 = z * temp_var_for_tac_27;

temp_var_for_tac_29 = U0[3] + temp_var_for_tac_28;

temp_var_for_tac_30 = z * temp_var_for_tac_29;

temp_var_for_tac_31 = U0[2] + temp_var_for_tac_30;

temp_var_for_tac_32 = z * temp_var_for_tac_31;

temp_var_for_tac_33 = U0[1] + temp_var_for_tac_32;

temp_var_for_tac_34 = z * temp_var_for_tac_33;

temp_var_for_tac_35 = U0[0] + temp_var_for_tac_34;

u = temp_var_for_tac_35;
computeLdMul((Addr)&temp_var_for_tac_26,
             {(Addr)&z, (Addr) &(temp_var_for_const_21 = U0[5])},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:169:69");
computeLdAdd((Addr)&temp_var_for_tac_27,
             {(Addr) &(temp_var_for_const_22 = U0[4]),
              (Addr)&temp_var_for_tac_26},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:169:65");
computeLdMul((Addr)&temp_var_for_tac_28, {(Addr)&z, (Addr)&temp_var_for_tac_27},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:169:56");
computeLdAdd((Addr)&temp_var_for_tac_29,
             {(Addr) &(temp_var_for_const_23 = U0[3]),
              (Addr)&temp_var_for_tac_28},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:169:52");
computeLdMul((Addr)&temp_var_for_tac_30, {(Addr)&z, (Addr)&temp_var_for_tac_29},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:169:43");
computeLdAdd((Addr)&temp_var_for_tac_31,
             {(Addr) &(temp_var_for_const_24 = U0[2]),
              (Addr)&temp_var_for_tac_30},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:169:39");
computeLdMul((Addr)&temp_var_for_tac_32, {(Addr)&z, (Addr)&temp_var_for_tac_31},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:169:30");
computeLdAdd((Addr)&temp_var_for_tac_33,
             {(Addr) &(temp_var_for_const_25 = U0[1]),
              (Addr)&temp_var_for_tac_32},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:169:26");
computeLdMul((Addr)&temp_var_for_tac_34, {(Addr)&z, (Addr)&temp_var_for_tac_33},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:169:17");
computeLdAdd((Addr)&temp_var_for_tac_35,
             {(Addr) &(temp_var_for_const_26 = U0[0]),
              (Addr)&temp_var_for_tac_34},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:169:13");
AssignLd({(Addr)&u}, (Addr)&temp_var_for_tac_35,
         "/home/shijia/Public/testprogram/e_y1l.c_e.c:169:5");
;
long double temp_var_for_tac_36, temp_var_for_tac_37, temp_var_for_tac_38,
    temp_var_for_tac_39, temp_var_for_tac_40, temp_var_for_tac_41,
    temp_var_for_tac_42, temp_var_for_tac_43, temp_var_for_tac_44;
long double temp_var_for_const_27, temp_var_for_const_28, temp_var_for_const_29,
    temp_var_for_const_30, temp_var_for_const_31;
temp_var_for_tac_36 = V0[4] + z;

temp_var_for_tac_37 = z * temp_var_for_tac_36;

temp_var_for_tac_38 = V0[3] + temp_var_for_tac_37;

temp_var_for_tac_39 = z * temp_var_for_tac_38;

temp_var_for_tac_40 = V0[2] + temp_var_for_tac_39;

temp_var_for_tac_41 = z * temp_var_for_tac_40;

temp_var_for_tac_42 = V0[1] + temp_var_for_tac_41;

temp_var_for_tac_43 = z * temp_var_for_tac_42;

temp_var_for_tac_44 = V0[0] + temp_var_for_tac_43;

v = temp_var_for_tac_44;
computeLdAdd((Addr)&temp_var_for_tac_36,
             {(Addr) &(temp_var_for_const_27 = V0[4]), (Addr)&z},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:170:65");
computeLdMul((Addr)&temp_var_for_tac_37, {(Addr)&z, (Addr)&temp_var_for_tac_36},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:170:56");
computeLdAdd((Addr)&temp_var_for_tac_38,
             {(Addr) &(temp_var_for_const_28 = V0[3]),
              (Addr)&temp_var_for_tac_37},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:170:52");
computeLdMul((Addr)&temp_var_for_tac_39, {(Addr)&z, (Addr)&temp_var_for_tac_38},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:170:43");
computeLdAdd((Addr)&temp_var_for_tac_40,
             {(Addr) &(temp_var_for_const_29 = V0[2]),
              (Addr)&temp_var_for_tac_39},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:170:39");
computeLdMul((Addr)&temp_var_for_tac_41, {(Addr)&z, (Addr)&temp_var_for_tac_40},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:170:30");
computeLdAdd((Addr)&temp_var_for_tac_42,
             {(Addr) &(temp_var_for_const_30 = V0[1]),
              (Addr)&temp_var_for_tac_41},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:170:26");
computeLdMul((Addr)&temp_var_for_tac_43, {(Addr)&z, (Addr)&temp_var_for_tac_42},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:170:17");
computeLdAdd((Addr)&temp_var_for_tac_44,
             {(Addr) &(temp_var_for_const_31 = V0[0]),
              (Addr)&temp_var_for_tac_43},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:170:13");
AssignLd({(Addr)&v}, (Addr)&temp_var_for_tac_44,
         "/home/shijia/Public/testprogram/e_y1l.c_e.c:170:5");
;
long double temp_var_for_ext_7;
long double temp_var_for_tac_45, temp_var_for_tac_46, temp_var_for_tac_47,
    temp_var_for_tac_48, temp_var_for_tac_49, temp_var_for_tac_50,
    temp_var_for_tac_51;
long double temp_var_for_const_32, temp_var_for_const_33, temp_var_for_const_34,
    temp_var_for_const_35;
long double temp_var_for_callexp_6;

long double temp_var_for_callexp_7;

temp_var_for_tac_45 = u / v;

temp_var_for_tac_46 = x * temp_var_for_tac_45;

temp_var_for_callexp_6 = __ieee754_j1l(x);
temp_var_for_callexp_7 = __ieee754_logl(x);
temp_var_for_tac_47 = temp_var_for_callexp_6 * temp_var_for_callexp_7;

temp_var_for_tac_48 = one / x;

temp_var_for_tac_49 = temp_var_for_tac_47 - temp_var_for_tac_48;

temp_var_for_tac_50 = tpi * temp_var_for_tac_49;

temp_var_for_tac_51 = temp_var_for_tac_46 + temp_var_for_tac_50;

temp_var_for_ext_7 = temp_var_for_tac_51;
computeLdDiv((Addr)&temp_var_for_tac_45, {(Addr)&u, (Addr)&v},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:173:15");
computeLdMul((Addr)&temp_var_for_tac_46, {(Addr)&x, (Addr)&temp_var_for_tac_45},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:173:10");
computeLdMul((Addr)&temp_var_for_tac_47,
             {(Addr) &(temp_var_for_const_33 = temp_var_for_callexp_6),
              (Addr) &(temp_var_for_const_32 = temp_var_for_callexp_7)},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:173:46");
computeLdDiv((Addr)&temp_var_for_tac_48,
             {(Addr) &(temp_var_for_const_34 = one), (Addr)&x},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:173:72");
computeLdSub((Addr)&temp_var_for_tac_49,
             {(Addr)&temp_var_for_tac_47, (Addr)&temp_var_for_tac_48},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:173:66");
computeLdMul((Addr)&temp_var_for_tac_50, {(Addr) &(temp_var_for_const_35 = tpi),
                                          (Addr)&temp_var_for_tac_49},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:173:26");
computeLdAdd((Addr)&temp_var_for_tac_51,
             {(Addr)&temp_var_for_tac_46, (Addr)&temp_var_for_tac_50},
             "/home/shijia/Public/testprogram/e_y1l.c_e.c:173:20");
AssignLd({(Addr)&temp_var_for_ext_7}, (Addr)&temp_var_for_tac_51,
         "/home/shijia/Public/testprogram/e_y1l.c_e.c:172:22");
;
callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
callExp++; /*identify the function is  add move tmpShadow*/
return temp_var_for_ext_7;
}

/* wrapper y1 */
long double __y1l(long double x) {
  if ((islessequal(x, 0.0) || isgreater(x, X_TLOSS)) &&
      _LIB_VERSION != _IEEE_) {
    if (int temp_var_for_tac_52; int temp_var_for_const_36;
        temp_var_for_tac_52 = x < 0.0;

        ) {
      /* d = zero/(x-x) */
      feraiseexcept(FE_INVALID);
      long double temp_var_for_ext_8;
      long double temp_var_for_const_37;
      long double temp_var_for_callexp_9;

      temp_var_for_callexp_8 = __builtin_huge_vall();
      temp_var_for_callexp_9 = __kernel_standard_l(
          x, x, (-(temp_var_for_callexp_8)), KMATHERRL_Y1_MINUS);
      temp_var_for_ext_8 = temp_var_for_callexp_9;
      compute((Addr)&temp_var_for_tac_52,
              {(Addr)&x, (Addr) &(temp_var_for_const_36 = 0.0)},
              "/home/shijia/Public/testprogram/e_y1l.c_e.c:183:11");
      AssignLd({(Addr)&temp_var_for_ext_8},
               (Addr) &(temp_var_for_const_37 = temp_var_for_callexp_9),
               "/home/shijia/Public/testprogram/e_y1l.c_e.c:187:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
      callExp++; /*identify the function is  add move tmpSha(0.0 - ow*/
retu)rn temp_var_for_ext_8;
    } else {
      if (int temp_var_for_tac_53; int temp_var_for_const_38;
          temp_var_for_tac_53 = x == 0.0;

          )
      /* d = -one/(x-x) */
      {
        long double temp_var_for_ext_9;
        long double temp_var_for_const_39;
        long double temp_var_for_callexp_11;

        temp_var_for_callexp_10 = __builtin_huge_vall();
        temp_var_for_callexp_11 = __kernel_standard_l(
            x, x, (-(temp_var_for_callexp_10)), KMATHERRL_Y1_ZERO);
        temp_var_for_ext_9 = temp_var_for_callexp_11;
        compute((Addr)&temp_var_for_tac_53,
                {(Addr)&x, (Addr) &(temp_var_for_const_38 = 0.0)},
                "/home/shijia/Public/testprogram/e_y1l.c_e.c:194:13");
        AssignLd({(Addr)&temp_var_for_ext_9},
                 (Addr) &(temp_var_for_const_39 = temp_var_for_callexp_11),
                 "/home/shijia/Public/testprogram/e_y1l.c_e.c:198:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
        callExp++; /*identify the function is  add move tmpShad(0.0 - w*/
retur)n temp_var_for_ext_9;
      }

      else {
        if (_LIB_VERSION != _POSIX_)
        /* y1(x>X_TLOSS) */
        {
          long double temp_var_for_ext_10;
          long double temp_var_for_const_40;
          long double temp_var_for_callexp_12;

          temp_var_for_callexp_12 =
              __kernel_standard_l(x, x, 0.0l, KMATHERRL_Y1_TLOSS);
          temp_var_for_ext_10 = temp_var_for_callexp_12;
          AssignLd({(Addr)&temp_var_for_ext_10},
                   (Addr) &(temp_var_for_const_40 = temp_var_for_callexp_12),
                   "/home/shijia/Public/testprogram/e_y1l.c_e.c:211:31");
          ;
          callExpStack.push(
              getReal("temp_var_for_ext_10", (Addr)&temp_var_for_ext_10));
          callExp++; /*identify the function is  add move tmpShadow*/
          return temp_var_for_ext_10;
        }
      }
    }
  }

  long double temp_var_for_ext_11;
  long double temp_var_for_const_41;
  long double temp_var_for_callexp_13;

  temp_var_for_callexp_13 = __ieee754_y1l(x);
  temp_var_for_ext_11 = temp_var_for_callexp_13;
  AssignLd({(Addr)&temp_var_for_ext_11},
           (Addr) &(temp_var_for_const_41 = temp_var_for_callexp_13),
           "/home/shijia/Public/testprogram/e_y1l.c_e.c:223:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_11", (Addr)&temp_var_for_ext_11));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_11;
}

__typeof(__y1l) y1l __attribute__((weak, alias("__y1l")));

#endif
