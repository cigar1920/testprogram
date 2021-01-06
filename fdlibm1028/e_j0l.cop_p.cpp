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

/* __ieee754_j0(x)
 * Bessel function of the first kind of order zero.
 * Method -- j0(x):
 *	1. For tiny x, we use j0(x) = 1 - x^2/4 + x^4/64 - ...
 *	2. Reduce x to |x| since j0(x)=j0(-x),  and
 *	   for x in (0,2)
 *		j0(x) = 1 - z/4 + z^2*R0/S0,  where z = x*x;
 *	   for x in (2,inf)
 *		j0(x) = sqrt(2/(pi*x))*(p0(x)*cos(x0)-q0(x)*sin(x0))
 *	   where x0 = x-pi/4. It is better to compute sin(x0),cos(x0)
 *	   as follow:
 *		cos(x0) = cos(x)cos(pi/4)+sin(x)sin(pi/4)
 *			= 1/sqrt(2) * (cos(x) + sin(x))
 *		sin(x0) = sin(x)cos(pi/4)-cos(x)sin(pi/4)
 *			= 1/sqrt(2) * (sin(x) - cos(x))
 *	   (To avoid cancellation, use
 *		sin(x) +- cos(x) = -cos(2x)/(sin(x) -+ cos(x))
 *	    to compute the worse one.)
 *
 *	3 Special cases
 *		j0(nan)= nan
 *		j0(0) = 1
 *		j0(inf) = 0
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

long double __ieee754_j0l(long double x) {
  long double z, s, c, ss, cc, r, u, v;
  int32_t ix;
  uint32_t se;

  static const long double hugeval = 1e4930L;
  static const long double one = 1.0L;
  static const long double invsqrtpi =
      5.6418958354775628694807945156077258584405e-1L;
  static const long double zero = 0.0;

  /* J0(x) = 1 - x^2 / 4 + x^4 R0(x^2) / S0(x^2)
     0 <= x <= 2
     peak relative error 1.41e-22 */
  static const long double R[5] = {
      4.287176872744686992880841716723478740566E7L,
      (long double temp_var_for_tac_0;
  long double temp_var_for_const_0, temp_var_for_const_1;
  temp_var_for_tac_0 = 0.0 - 6.652058897474241627570911531740907185772E5L;

),
      7.011848381719789863458364584613651091175E3L,
      (long double temp_var_for_tac_1;long double temp_var_for_const_2,temp_var_for_const_3;temp_var_for_tac_1 = 0.0 - 3.168040850193372408702135490809516253693E1L;

),
      6.030778552661102450545394348845599300939E-2L
};
static const long double S[4] = {
    2.743793198556599677955266341699130654342E9L,
    3.364330079384816249840086842058954076201E7L,
    1.924119649412510777584684927494642526573E5L,
    6.239282256012734914211715620088714856494E2L
    /*   1.000000000000000000000000000000000000000E0L, */
};

long double temp_var_for_const_4;
ge_u.value = x;
computeLdSub((Addr)&temp_var_for_tac_0,
             {(Addr) &(temp_var_for_const_1 = 0.0),
              (Addr) &(temp_var_for_const_0 =
                           6.652058897474241627570911531740907185772E5L)},
             "/home/shijia/Public/testprogram/e_j0l.c_e.c:80:12");
computeLdSub((Addr)&temp_var_for_tac_1,
             {(Addr) &(temp_var_for_const_3 = 0.0),
              (Addr) &(temp_var_for_const_2 =
                           3.168040850193372408702135490809516253693E1L)},
             "/home/shijia/Public/testprogram/e_j0l.c_e.c:82:12");
AssignLd({(Addr) &(temp_var_for_const_4 = ge_u.value)}, (Addr)&x,
         "/home/shijia/Public/testprogram/e_j0l.c_e.c:92:3 "
         "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:258:14>");
;
ix = se & 0x7fff;
if (ix >= 0x7fff) {
  long double temp_var_for_ext_0;
  long double temp_var_for_tac_2, temp_var_for_tac_3;
  long double temp_var_for_const_5;
  temp_var_for_tac_2 = x * x;

  temp_var_for_tac_3 = one / temp_var_for_tac_2;

  temp_var_for_ext_0 = temp_var_for_tac_3;
  computeLdMul((Addr)&temp_var_for_tac_2, {(Addr)&x, (Addr)&x},
               "/home/shijia/Public/testprogram/e_j0l.c_e.c:96:35");
  computeLdDiv((Addr)&temp_var_for_tac_3, {(Addr) &(temp_var_for_const_5 = one),
                                           (Addr)&temp_var_for_tac_2},
               "/home/shijia/Public/testprogram/e_j0l.c_e.c:96:30");
  AssignLd({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_3,
           "/home/shijia/Public/testprogram/e_j0l.c_e.c:96:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

long double temp_var_for_ext_1;
long double temp_var_for_const_6;
long double temp_var_for_callexp_0;

temp_var_for_callexp_0 = fabsl(x);
temp_var_for_ext_1 = temp_var_for_callexp_0;
AssignLd({(Addr)&temp_var_for_ext_1},
         (Addr) &(temp_var_for_const_6 = temp_var_for_callexp_0),
         "/home/shijia/Public/testprogram/e_j0l.c_e.c:103:22");
; // x
/*(_)(_)(tem)(_)(_)(__ieee754_fabsl(x))*/
x = temp_var_for_ext_1;
AssignLd({(Addr)&x}, (Addr)&temp_var_for_ext_1,
         "/home/shijia/Public/testprogram/e_j0l.c_e.c:105:5");
;
if (ix >= 0x4000) /* |x| >= 2.0 */
{
  __ieee754_sincosl(x, &s, &c);
  long double temp_var_for_tac_4;
  temp_var_for_tac_4 = s - c;

  ss = temp_var_for_tac_4;
  computeLdSub((Addr)&temp_var_for_tac_4, {(Addr)&s, (Addr)&c},
               "/home/shijia/Public/testprogram/e_j0l.c_e.c:109:12");
  AssignLd({(Addr)&ss}, (Addr)&temp_var_for_tac_4,
           "/home/shijia/Public/testprogram/e_j0l.c_e.c:109:8");
  ;
  long double temp_var_for_tac_5;
  temp_var_for_tac_5 = s + c;

  cc = temp_var_for_tac_5;
  computeLdAdd((Addr)&temp_var_for_tac_5, {(Addr)&s, (Addr)&c},
               "/home/shijia/Public/testprogram/e_j0l.c_e.c:110:12");
  AssignLd({(Addr)&cc}, (Addr)&temp_var_for_tac_5,
           "/home/shijia/Public/testprogram/e_j0l.c_e.c:110:8");
  ;
  if (ix < 0x7ffe) { /* make sure x+x not overflow */
    long double temp_var_for_tac_6, temp_var_for_tac_7;
    long double temp_var_for_const_7, temp_var_for_const_8;
    long double temp_var_for_callexp_1;

    temp_var_for_tac_6 = x + x;

    temp_var_for_callexp_1 = __ieee754_cosl(temp_var_for_tac_6);
    temp_var_for_tac_7 = 0.0 - temp_var_for_callexp_1;

    z = temp_var_for_tac_7;
    computeLdAdd((Addr)&temp_var_for_tac_6, {(Addr)&x, (Addr)&x},
                 "/home/shijia/Public/testprogram/e_j0l.c_e.c:112:35");
    computeLdSub((Addr)&temp_var_for_tac_7,
                 {(Addr) &(temp_var_for_const_8 = 0.0),
                  (Addr) &(temp_var_for_const_7 = temp_var_for_callexp_1)},
                 "/home/shijia/Public/testprogram/e_j0l.c_e.c:112:16");
    AssignLd({(Addr)&z}, (Addr)&temp_var_for_tac_7,
             "/home/shijia/Public/testprogram/e_j0l.c_e.c:112:9");
    ;
    if (int temp_var_for_tac_8, temp_var_for_tac_9; int temp_var_for_const_9;
        temp_var_for_tac_8 = s * c;

        temp_var_for_tac_9 = temp_var_for_tac_8 < zero;

        ) {
      long double temp_var_for_tac_10;
      temp_var_for_tac_10 = z / ss;

      cc = temp_var_for_tac_10;
      computeLdMul((Addr)&temp_var_for_tac_8, {(Addr)&s, (Addr)&c},
                   "/home/shijia/Public/testprogram/e_j0l.c_e.c:113:14");
      compute(
          (Addr)&temp_var_for_tac_9,
          {(Addr)&temp_var_for_tac_8, (Addr) &(temp_var_for_const_9 = zero)},
          "/home/shijia/Public/testprogram/e_j0l.c_e.c:113:19");
      computeLdDiv((Addr)&temp_var_for_tac_10, {(Addr)&z, (Addr)&ss},
                   "/home/shijia/Public/testprogram/e_j0l.c_e.c:114:16");
      AssignLd({(Addr)&cc}, (Addr)&temp_var_for_tac_10,
               "/home/shijia/Public/testprogram/e_j0l.c_e.c:114:12");
      ;
    }

    else {
      long double temp_var_for_ext_2;
      long double temp_var_for_tac_11;
      temp_var_for_tac_11 = z / cc;

      temp_var_for_ext_2 = temp_var_for_tac_11;
      computeLdDiv((Addr)&temp_var_for_tac_11, {(Addr)&z, (Addr)&cc},
                   "/home/shijia/Public/testprogram/e_j0l.c_e.c:119:32");
      AssignLd({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_11,
               "/home/shijia/Public/testprogram/e_j0l.c_e.c:119:28");
      ; // ss
      /*(ss)(z)(cc)(z)*/
      ss = temp_var_for_ext_2;
      AssignLd({(Addr)&ss}, (Addr)&temp_var_for_ext_2,
               "/home/shijia/Public/testprogram/e_j0l.c_e.c:121:12");
      ;
    }
  }
  /*
   * j0(x) = 1/sqrt(pi) * (P(0,x)*cc - Q(0,x)*ss) / sqrt(x)
   * y0(x) = 1/sqrt(pi) * (P(0,x)*ss + Q(0,x)*cc) / sqrt(x)
   */
  if (ix > 0x4080) /* 2^129 */
  {
    long double temp_var_for_ext_3;
    long double temp_var_for_tac_12, temp_var_for_tac_13;
    long double temp_var_for_const_10, temp_var_for_const_11;
    long double temp_var_for_callexp_2;

    temp_var_for_tac_12 = invsqrtpi * cc;

    temp_var_for_callexp_2 = __ieee754_sqrtl(x);
    temp_var_for_tac_13 = temp_var_for_tac_12 / temp_var_for_callexp_2;

    temp_var_for_ext_3 = temp_var_for_tac_13;
    computeLdMul((Addr)&temp_var_for_tac_12,
                 {(Addr) &(temp_var_for_const_10 = invsqrtpi), (Addr)&cc},
                 "/home/shijia/Public/testprogram/e_j0l.c_e.c:131:39");
    computeLdDiv((Addr)&temp_var_for_tac_13,
                 {(Addr)&temp_var_for_tac_12,
                  (Addr) &(temp_var_for_const_11 = temp_var_for_callexp_2)},
                 "/home/shijia/Public/testprogram/e_j0l.c_e.c:131:45");
    AssignLd({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_13,
             "/home/shijia/Public/testprogram/e_j0l.c_e.c:131:26");
    ; // z
    /*(cc)(z)(__ieee754_sqrtl(x))(cc)(invsqrtpi)*/
    z = temp_var_for_ext_3;
    AssignLd({(Addr)&z}, (Addr)&temp_var_for_ext_3,
             "/home/shijia/Public/testprogram/e_j0l.c_e.c:133:9");
    ;
  }

  else {
    long double temp_var_for_const_12;
    long double temp_var_for_callexp_3;

    temp_var_for_callexp_3 = __j0_y0_pzerol(x);
    u = temp_var_for_callexp_3;
    AssignLd({(Addr)&u},
             (Addr) &(temp_var_for_const_12 = temp_var_for_callexp_3),
             "/home/shijia/Public/testprogram/e_j0l.c_e.c:137:9");
    ;
    long double temp_var_for_const_13;
    long double temp_var_for_callexp_4;

    temp_var_for_callexp_4 = __j0_y0_qzerol(x);
    v = temp_var_for_callexp_4;
    AssignLd({(Addr)&v},
             (Addr) &(temp_var_for_const_13 = temp_var_for_callexp_4),
             "/home/shijia/Public/testprogram/e_j0l.c_e.c:138:9");
    ;
    long double temp_var_for_tac_14, temp_var_for_tac_15, temp_var_for_tac_16,
        temp_var_for_tac_17, temp_var_for_tac_18;
    long double temp_var_for_const_14, temp_var_for_const_15;
    long double temp_var_for_callexp_5;

    temp_var_for_tac_14 = u * cc;

    temp_var_for_tac_15 = v * ss;

    temp_var_for_tac_16 = temp_var_for_tac_14 - temp_var_for_tac_15;

    temp_var_for_tac_17 = invsqrtpi * temp_var_for_tac_16;

    temp_var_for_callexp_5 = __ieee754_sqrtl(x);
    temp_var_for_tac_18 = temp_var_for_tac_17 / temp_var_for_callexp_5;

    z = temp_var_for_tac_18;
    computeLdMul((Addr)&temp_var_for_tac_14, {(Addr)&u, (Addr)&cc},
                 "/home/shijia/Public/testprogram/e_j0l.c_e.c:139:26");
    computeLdMul((Addr)&temp_var_for_tac_15, {(Addr)&v, (Addr)&ss},
                 "/home/shijia/Public/testprogram/e_j0l.c_e.c:139:35");
    computeLdSub((Addr)&temp_var_for_tac_16,
                 {(Addr)&temp_var_for_tac_14, (Addr)&temp_var_for_tac_15},
                 "/home/shijia/Public/testprogram/e_j0l.c_e.c:139:31");
    computeLdMul((Addr)&temp_var_for_tac_17,
                 {(Addr) &(temp_var_for_const_14 = invsqrtpi),
                  (Addr)&temp_var_for_tac_16},
                 "/home/shijia/Public/testprogram/e_j0l.c_e.c:139:21");
    computeLdDiv((Addr)&temp_var_for_tac_18,
                 {(Addr)&temp_var_for_tac_17,
                  (Addr) &(temp_var_for_const_15 = temp_var_for_callexp_5)},
                 "/home/shijia/Public/testprogram/e_j0l.c_e.c:139:41");
    AssignLd({(Addr)&z}, (Addr)&temp_var_for_tac_18,
             "/home/shijia/Public/testprogram/e_j0l.c_e.c:139:9");
    ;
  }
  long double temp_var_for_ext_4;
  temp_var_for_ext_4 = z;
  AssignLd({(Addr)&temp_var_for_ext_4}, (Addr)&z,
           "/home/shijia/Public/testprogram/e_j0l.c_e.c:142:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_4;
}
if (ix < 0x3fef) /* |x| < 2**-16 */
{
  /* raise inexact if x != 0 */
  math_force_eval(hugeval + x);
  if (ix < 0x3fde) /* |x| < 2^-33 */
  {
    long double temp_var_for_ext_5;
    long double temp_var_for_const_18;
    temp_var_for_ext_5 = one;
    computeLdAdd((Addr)&temp_var_for_tac_19,
                 {(Addr) &(temp_var_for_const_16 = hugeval), (Addr)&x},
                 "/home/shijia/Public/testprogram/e_j0l.c_e.c:150:5 "
                 "<Spelling=/home/shijia/Public/testprogram/"
                 "e_j0l.c_e.c:150:29>");
    computeLdAdd((Addr)&temp_var_for_tac_20,
                 {(Addr) &(temp_var_for_const_17 = hugeval), (Addr)&x},
                 "/home/shijia/Public/testprogram/e_j0l.c_e.c:150:5 "
                 "<Spelling=/home/shijia/Public/testprogram/"
                 "e_j0l.c_e.c:150:29>");
    AssignLd({(Addr)&temp_var_for_ext_5}, (Addr) &(temp_var_for_const_18 = one),
             "/home/shijia/Public/testprogram/e_j0l.c_e.c:154:26");
    ;
    callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_5;
  }

  else {
    long double temp_var_for_ext_6;
    long double temp_var_for_tac_21, temp_var_for_tac_22, temp_var_for_tac_23;
    long double temp_var_for_const_19, temp_var_for_const_20;
    temp_var_for_tac_21 = 0.25 * x;

    temp_var_for_tac_22 = temp_var_for_tac_21 * x;

    temp_var_for_tac_23 = one - temp_var_for_tac_22;

    temp_var_for_ext_6 = temp_var_for_tac_23;
    computeLdMul((Addr)&temp_var_for_tac_21,
                 {(Addr) &(temp_var_for_const_19 = 0.25), (Addr)&x},
                 "/home/shijia/Public/testprogram/e_j0l.c_e.c:163:39");
    computeLdMul((Addr)&temp_var_for_tac_22,
                 {(Addr)&temp_var_for_tac_21, (Addr)&x},
                 "/home/shijia/Public/testprogram/e_j0l.c_e.c:163:43");
    computeLdSub(
        (Addr)&temp_var_for_tac_23,
        {(Addr) &(temp_var_for_const_20 = one), (Addr)&temp_var_for_tac_22},
        "/home/shijia/Public/testprogram/e_j0l.c_e.c:163:32");
    AssignLd({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_23,
             "/home/shijia/Public/testprogram/e_j0l.c_e.c:163:26");
    ;
    callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_6;
  }
}
long double temp_var_for_tac_24;
temp_var_for_tac_24 = x * x;

z = temp_var_for_tac_24;
computeLdMul((Addr)&temp_var_for_tac_24, {(Addr)&x, (Addr)&x},
             "/home/shijia/Public/testprogram/e_j0l.c_e.c:170:9");
AssignLd({(Addr)&z}, (Addr)&temp_var_for_tac_24,
         "/home/shijia/Public/testprogram/e_j0l.c_e.c:170:5");
;
long double temp_var_for_tac_25, temp_var_for_tac_26, temp_var_for_tac_27,
    temp_var_for_tac_28, temp_var_for_tac_29, temp_var_for_tac_30,
    temp_var_for_tac_31, temp_var_for_tac_32, temp_var_for_tac_33;
long double temp_var_for_const_21, temp_var_for_const_22, temp_var_for_const_23,
    temp_var_for_const_24, temp_var_for_const_25;
temp_var_for_tac_25 = z * R[4];

temp_var_for_tac_26 = R[3] + temp_var_for_tac_25;

temp_var_for_tac_27 = z * temp_var_for_tac_26;

temp_var_for_tac_28 = R[2] + temp_var_for_tac_27;

temp_var_for_tac_29 = z * temp_var_for_tac_28;

temp_var_for_tac_30 = R[1] + temp_var_for_tac_29;

temp_var_for_tac_31 = z * temp_var_for_tac_30;

temp_var_for_tac_32 = R[0] + temp_var_for_tac_31;

temp_var_for_tac_33 = z * temp_var_for_tac_32;

r = temp_var_for_tac_33;
computeLdMul((Addr)&temp_var_for_tac_25,
             {(Addr)&z, (Addr) &(temp_var_for_const_21 = R[4])},
             "/home/shijia/Public/testprogram/e_j0l.c_e.c:171:57");
computeLdAdd((Addr)&temp_var_for_tac_26,
             {(Addr) &(temp_var_for_const_22 = R[3]),
              (Addr)&temp_var_for_tac_25},
             "/home/shijia/Public/testprogram/e_j0l.c_e.c:171:53");
computeLdMul((Addr)&temp_var_for_tac_27, {(Addr)&z, (Addr)&temp_var_for_tac_26},
             "/home/shijia/Public/testprogram/e_j0l.c_e.c:171:45");
computeLdAdd((Addr)&temp_var_for_tac_28,
             {(Addr) &(temp_var_for_const_23 = R[2]),
              (Addr)&temp_var_for_tac_27},
             "/home/shijia/Public/testprogram/e_j0l.c_e.c:171:41");
computeLdMul((Addr)&temp_var_for_tac_29, {(Addr)&z, (Addr)&temp_var_for_tac_28},
             "/home/shijia/Public/testprogram/e_j0l.c_e.c:171:33");
computeLdAdd((Addr)&temp_var_for_tac_30,
             {(Addr) &(temp_var_for_const_24 = R[1]),
              (Addr)&temp_var_for_tac_29},
             "/home/shijia/Public/testprogram/e_j0l.c_e.c:171:29");
computeLdMul((Addr)&temp_var_for_tac_31, {(Addr)&z, (Addr)&temp_var_for_tac_30},
             "/home/shijia/Public/testprogram/e_j0l.c_e.c:171:21");
computeLdAdd((Addr)&temp_var_for_tac_32,
             {(Addr) &(temp_var_for_const_25 = R[0]),
              (Addr)&temp_var_for_tac_31},
             "/home/shijia/Public/testprogram/e_j0l.c_e.c:171:17");
computeLdMul((Addr)&temp_var_for_tac_33, {(Addr)&z, (Addr)&temp_var_for_tac_32},
             "/home/shijia/Public/testprogram/e_j0l.c_e.c:171:9");
AssignLd({(Addr)&r}, (Addr)&temp_var_for_tac_33,
         "/home/shijia/Public/testprogram/e_j0l.c_e.c:171:5");
;
long double temp_var_for_tac_34, temp_var_for_tac_35, temp_var_for_tac_36,
    temp_var_for_tac_37, temp_var_for_tac_38, temp_var_for_tac_39,
    temp_var_for_tac_40;
long double temp_var_for_const_26, temp_var_for_const_27, temp_var_for_const_28,
    temp_var_for_const_29;
temp_var_for_tac_34 = S[3] + z;

temp_var_for_tac_35 = z * temp_var_for_tac_34;

temp_var_for_tac_36 = S[2] + temp_var_for_tac_35;

temp_var_for_tac_37 = z * temp_var_for_tac_36;

temp_var_for_tac_38 = S[1] + temp_var_for_tac_37;

temp_var_for_tac_39 = z * temp_var_for_tac_38;

temp_var_for_tac_40 = S[0] + temp_var_for_tac_39;

s = temp_var_for_tac_40;
computeLdAdd((Addr)&temp_var_for_tac_34,
             {(Addr) &(temp_var_for_const_26 = S[3]), (Addr)&z},
             "/home/shijia/Public/testprogram/e_j0l.c_e.c:172:48");
computeLdMul((Addr)&temp_var_for_tac_35, {(Addr)&z, (Addr)&temp_var_for_tac_34},
             "/home/shijia/Public/testprogram/e_j0l.c_e.c:172:40");
computeLdAdd((Addr)&temp_var_for_tac_36,
             {(Addr) &(temp_var_for_const_27 = S[2]),
              (Addr)&temp_var_for_tac_35},
             "/home/shijia/Public/testprogram/e_j0l.c_e.c:172:36");
computeLdMul((Addr)&temp_var_for_tac_37, {(Addr)&z, (Addr)&temp_var_for_tac_36},
             "/home/shijia/Public/testprogram/e_j0l.c_e.c:172:28");
computeLdAdd((Addr)&temp_var_for_tac_38,
             {(Addr) &(temp_var_for_const_28 = S[1]),
              (Addr)&temp_var_for_tac_37},
             "/home/shijia/Public/testprogram/e_j0l.c_e.c:172:24");
computeLdMul((Addr)&temp_var_for_tac_39, {(Addr)&z, (Addr)&temp_var_for_tac_38},
             "/home/shijia/Public/testprogram/e_j0l.c_e.c:172:16");
computeLdAdd((Addr)&temp_var_for_tac_40,
             {(Addr) &(temp_var_for_const_29 = S[0]),
              (Addr)&temp_var_for_tac_39},
             "/home/shijia/Public/testprogram/e_j0l.c_e.c:172:12");
AssignLd({(Addr)&s}, (Addr)&temp_var_for_tac_40,
         "/home/shijia/Public/testprogram/e_j0l.c_e.c:172:5");
;
if (ix < 0x3fff) { /* |x| < 1.00 */
  long double temp_var_for_ext_7;
  long double temp_var_for_tac_41, temp_var_for_tac_42, temp_var_for_tac_43,
      temp_var_for_tac_44, temp_var_for_tac_45;
  long double temp_var_for_const_30, temp_var_for_const_31;
  temp_var_for_tac_41 = 0.25 * z;

  temp_var_for_tac_42 = one - temp_var_for_tac_41;

  temp_var_for_tac_43 = r / s;

  temp_var_for_tac_44 = z * temp_var_for_tac_43;

  temp_var_for_tac_45 = temp_var_for_tac_42 + temp_var_for_tac_44;

  temp_var_for_ext_7 = temp_var_for_tac_45;
  computeLdMul((Addr)&temp_var_for_tac_41,
               {(Addr) &(temp_var_for_const_30 = 0.25), (Addr)&z},
               "/home/shijia/Public/testprogram/e_j0l.c_e.c:175:38");
  computeLdSub(
      (Addr)&temp_var_for_tac_42,
      {(Addr) &(temp_var_for_const_31 = one), (Addr)&temp_var_for_tac_41},
      "/home/shijia/Public/testprogram/e_j0l.c_e.c:175:31");
  computeLdDiv((Addr)&temp_var_for_tac_43, {(Addr)&r, (Addr)&s},
               "/home/shijia/Public/testprogram/e_j0l.c_e.c:175:51");
  computeLdMul((Addr)&temp_var_for_tac_44,
               {(Addr)&z, (Addr)&temp_var_for_tac_43},
               "/home/shijia/Public/testprogram/e_j0l.c_e.c:175:46");
  computeLdAdd((Addr)&temp_var_for_tac_45,
               {(Addr)&temp_var_for_tac_42, (Addr)&temp_var_for_tac_44},
               "/home/shijia/Public/testprogram/e_j0l.c_e.c:175:42");
  AssignLd({(Addr)&temp_var_for_ext_7}, (Addr)&temp_var_for_tac_45,
           "/home/shijia/Public/testprogram/e_j0l.c_e.c:175:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_7;
} else {
  long double temp_var_for_tac_46;
  long double temp_var_for_const_32;
  temp_var_for_tac_46 = 0.5 * x;

  u = temp_var_for_tac_46;
  computeLdMul((Addr)&temp_var_for_tac_46,
               {(Addr) &(temp_var_for_const_32 = 0.5), (Addr)&x},
               "/home/shijia/Public/testprogram/e_j0l.c_e.c:180:13");
  AssignLd({(Addr)&u}, (Addr)&temp_var_for_tac_46,
           "/home/shijia/Public/testprogram/e_j0l.c_e.c:180:7");
  ;
  long double temp_var_for_ext_8;
  long double temp_var_for_tac_47, temp_var_for_tac_48, temp_var_for_tac_49,
      temp_var_for_tac_50, temp_var_for_tac_51, temp_var_for_tac_52;
  long double temp_var_for_const_33, temp_var_for_const_34;
  temp_var_for_tac_47 = one + u;

  temp_var_for_tac_48 = one - u;

  temp_var_for_tac_49 = temp_var_for_tac_47 * temp_var_for_tac_48;

  temp_var_for_tac_50 = r / s;

  temp_var_for_tac_51 = z * temp_var_for_tac_50;

  temp_var_for_tac_52 = temp_var_for_tac_49 + temp_var_for_tac_51;

  temp_var_for_ext_8 = temp_var_for_tac_52;
  computeLdAdd((Addr)&temp_var_for_tac_47,
               {(Addr) &(temp_var_for_const_33 = one), (Addr)&u},
               "/home/shijia/Public/testprogram/e_j0l.c_e.c:182:32");
  computeLdSub((Addr)&temp_var_for_tac_48,
               {(Addr) &(temp_var_for_const_34 = one), (Addr)&u},
               "/home/shijia/Public/testprogram/e_j0l.c_e.c:182:44");
  computeLdMul((Addr)&temp_var_for_tac_49,
               {(Addr)&temp_var_for_tac_47, (Addr)&temp_var_for_tac_48},
               "/home/shijia/Public/testprogram/e_j0l.c_e.c:182:37");
  computeLdDiv((Addr)&temp_var_for_tac_50, {(Addr)&r, (Addr)&s},
               "/home/shijia/Public/testprogram/e_j0l.c_e.c:182:58");
  computeLdMul((Addr)&temp_var_for_tac_51,
               {(Addr)&z, (Addr)&temp_var_for_tac_50},
               "/home/shijia/Public/testprogram/e_j0l.c_e.c:182:53");
  computeLdAdd((Addr)&temp_var_for_tac_52,
               {(Addr)&temp_var_for_tac_49, (Addr)&temp_var_for_tac_51},
               "/home/shijia/Public/testprogram/e_j0l.c_e.c:182:49");
  AssignLd({(Addr)&temp_var_for_ext_8}, (Addr)&temp_var_for_tac_52,
           "/home/shijia/Public/testprogram/e_j0l.c_e.c:182:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_8;
}
}

/* wrapper j0 */
long double __j0l(long double x) {
  if (isgreater(__ieee754_fabsl(x), X_TLOSS) && _LIB_VERSION != _IEEE_ &&
      _LIB_VERSION != _POSIX_)
  /* j0(|x|>X_TLOSS) */
  {
    long double temp_var_for_ext_9;
    long double temp_var_for_const_35;
    long double temp_var_for_callexp_6;

    temp_var_for_callexp_6 =
        __kernel_standard_l(x, x, 0.0L, KMATHERRL_J0_TLOSS);
    temp_var_for_ext_9 = temp_var_for_callexp_6;
    AssignLd({(Addr)&temp_var_for_ext_9},
             (Addr) &(temp_var_for_const_35 = temp_var_for_callexp_6),
             "/home/shijia/Public/testprogram/e_j0l.c_e.c:196:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_9;
  }

  long double temp_var_for_ext_10;
  long double temp_var_for_const_36;
  long double temp_var_for_callexp_7;

  temp_var_for_callexp_7 = __ieee754_j0l(x);
  temp_var_for_ext_10 = temp_var_for_callexp_7;
  AssignLd({(Addr)&temp_var_for_ext_10},
           (Addr) &(temp_var_for_const_36 = temp_var_for_callexp_7),
           "/home/shijia/Public/testprogram/e_j0l.c_e.c:203:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_10", (Addr)&temp_var_for_ext_10));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_10;
}

__typeof(__j0l) j0l __attribute__((weak, alias("__j0l")));

#endif
