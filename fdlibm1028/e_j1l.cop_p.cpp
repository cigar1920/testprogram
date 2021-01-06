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

/* __ieee754_j1(x), __ieee754_y1(x)
 * Bessel function of the first kind of order one.
 * Method -- j1(x):
 *	1. For tiny x, we use j1(x) = x/2 - x^3/16 + x^5/384 - ...
 *	2. Reduce x to |x| since j1(x)=-j1(-x),  and
 *	   for x in (0,2)
 *		j1(x) = x/2 + x*z*R0/S0,  where z = x*x;
 *	   for x in (2,inf)
 *		j1(x) = sqrt(2/(pi*x))*(p1(x)*cos(x1)-q1(x)*sin(x1))
 *		y1(x) = sqrt(2/(pi*x))*(p1(x)*sin(x1)+q1(x)*cos(x1))
 *	   where x1 = x-3*pi/4. It is better to compute sin(x1),cos(x1)
 *	   as follow:
 *		cos(x1) =  cos(x)cos(3pi/4)+sin(x)sin(3pi/4)
 *			=  1/sqrt(2) * (sin(x) - cos(x))
 *		sin(x1) =  sin(x)cos(3pi/4)-cos(x)sin(3pi/4)
 *			= -1/sqrt(2) * (sin(x) + cos(x))
 *	   (To avoid cancellation, use
 *		sin(x) +- cos(x) = -cos(2x)/(sin(x) -+ cos(x))
 *	    to compute the worse one.)
 *
 *	3 Special cases
 *		j1(nan)= nan
 *		j1(0) = 0
 *		j1(inf) = 0
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

long double __ieee754_j1l(long double x) {
  long double z, c, r, s, ss, cc, u, v, y;
  int32_t ix;
  uint32_t se;

  static const long double hugeval = 1e4930L;
  static const long double one = 1.0L;
  static const long double invsqrtpi =
      5.6418958354775628694807945156077258584405e-1L;
  static const long double zero = 0.0;

  /* J1(x) = .5 x + x x^2 R(x^2) / S(x^2)
     0 <= x <= 2
     Peak relative error 4.5e-21 */
  static const long double R[5] = {
      (long double temp_var_for_tac_0;
  long double temp_var_for_const_0, temp_var_for_const_1;
  temp_var_for_tac_0 = 0.0 - 9.647406112428107954753770469290757756814E7L;

),
      2.686288565865230690166454005558203955564E6L,
      (long double temp_var_for_tac_1;long double temp_var_for_const_2,temp_var_for_const_3;temp_var_for_tac_1 = 0.0 - 3.689682683905671185891885948692283776081E4L;

),
      2.195031194229176602851429567792676658146E2L,
      (long double temp_var_for_tac_2;long double temp_var_for_const_4,temp_var_for_const_5;temp_var_for_tac_2 = 0.0 - 5.124499848728030297902028238597308971319E-1L;

)
};
static const long double S[4] = {
    1.543584977988497274437410333029029035089E9L,
    2.133542369567701244002565983150952549520E7L,
    1.394077011298227346483732156167414670520E5L,
    5.252401789085732428842871556112108446506E2L
    /*  1.000000000000000000000000000000000000000E0L, */
};

long double temp_var_for_const_6;
ge_u.value = x;
computeLdSub((Addr)&temp_var_for_tac_0,
             {(Addr) &(temp_var_for_const_1 = 0.0),
              (Addr) &(temp_var_for_const_0 =
                           9.647406112428107954753770469290757756814E7L)},
             "/home/shijia/Public/testprogram/e_j1l.c_e.c:80:12");
computeLdSub((Addr)&temp_var_for_tac_1,
             {(Addr) &(temp_var_for_const_3 = 0.0),
              (Addr) &(temp_var_for_const_2 =
                           3.689682683905671185891885948692283776081E4L)},
             "/home/shijia/Public/testprogram/e_j1l.c_e.c:82:12");
computeLdSub((Addr)&temp_var_for_tac_2,
             {(Addr) &(temp_var_for_const_5 = 0.0),
              (Addr) &(temp_var_for_const_4 =
                           5.124499848728030297902028238597308971319E-1L)},
             "/home/shijia/Public/testprogram/e_j1l.c_e.c:84:12");
AssignLd({(Addr) &(temp_var_for_const_6 = ge_u.value)}, (Addr)&x,
         "/home/shijia/Public/testprogram/e_j1l.c_e.c:93:3 "
         "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:258:14>");
;
ix = se & 0x7fff;
if (ix >= 0x7fff) {
  long double temp_var_for_ext_0;
  long double temp_var_for_tac_3;
  long double temp_var_for_const_7;
  temp_var_for_tac_3 = one / x;

  temp_var_for_ext_0 = temp_var_for_tac_3;
  computeLdDiv((Addr)&temp_var_for_tac_3,
               {(Addr) &(temp_var_for_const_7 = one), (Addr)&x},
               "/home/shijia/Public/testprogram/e_j1l.c_e.c:97:30");
  AssignLd({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_3,
           "/home/shijia/Public/testprogram/e_j1l.c_e.c:97:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

long double temp_var_for_const_8;
long double temp_var_for_callexp_0;

temp_var_for_callexp_0 = fabsl(x);
y = temp_var_for_callexp_0;
AssignLd({(Addr)&y}, (Addr) &(temp_var_for_const_8 = temp_var_for_callexp_0),
         "/home/shijia/Public/testprogram/e_j1l.c_e.c:103:5");
;
if (ix >= 0x4000) { /* |x| >= 2.0 */
  __ieee754_sincosl(y, &s, &c);
  long double temp_var_for_tac_4, temp_var_for_tac_5;
  long double temp_var_for_const_9;
  temp_var_for_tac_4 = 0.0 - s;

  temp_var_for_tac_5 = temp_var_for_tac_4 - c;

  ss = temp_var_for_tac_5;
  computeLdSub((Addr)&temp_var_for_tac_4,
               {(Addr) &(temp_var_for_const_9 = 0.0), (Addr)&s},
               "/home/shijia/Public/testprogram/e_j1l.c_e.c:106:15");
  computeLdSub((Addr)&temp_var_for_tac_5, {(Addr)&temp_var_for_tac_4, (Addr)&c},
               "/home/shijia/Public/testprogram/e_j1l.c_e.c:106:20");
  AssignLd({(Addr)&ss}, (Addr)&temp_var_for_tac_5,
           "/home/shijia/Public/testprogram/e_j1l.c_e.c:106:8");
  ;
  long double temp_var_for_tac_6;
  temp_var_for_tac_6 = s - c;

  cc = temp_var_for_tac_6;
  computeLdSub((Addr)&temp_var_for_tac_6, {(Addr)&s, (Addr)&c},
               "/home/shijia/Public/testprogram/e_j1l.c_e.c:107:12");
  AssignLd({(Addr)&cc}, (Addr)&temp_var_for_tac_6,
           "/home/shijia/Public/testprogram/e_j1l.c_e.c:107:8");
  ;
  if (ix < 0x7ffe) { /* make sure y+y not overflow */
    long double temp_var_for_tac_7;
    long double temp_var_for_const_10;
    long double temp_var_for_callexp_1;

    temp_var_for_tac_7 = y + y;

    temp_var_for_callexp_1 = __ieee754_cosl(temp_var_for_tac_7);
    z = temp_var_for_callexp_1;
    computeLdAdd((Addr)&temp_var_for_tac_7, {(Addr)&y, (Addr)&y},
                 "/home/shijia/Public/testprogram/e_j1l.c_e.c:109:28");
    AssignLd({(Addr)&z},
             (Addr) &(temp_var_for_const_10 = temp_var_for_callexp_1),
             "/home/shijia/Public/testprogram/e_j1l.c_e.c:109:9");
    ;
    if (int temp_var_for_tac_8, temp_var_for_tac_9; int temp_var_for_const_11;
        temp_var_for_tac_8 = s * c;

        temp_var_for_tac_9 = temp_var_for_tac_8 > zero;

        ) {
      long double temp_var_for_tac_10;
      temp_var_for_tac_10 = z / ss;

      cc = temp_var_for_tac_10;
      computeLdMul((Addr)&temp_var_for_tac_8, {(Addr)&s, (Addr)&c},
                   "/home/shijia/Public/testprogram/e_j1l.c_e.c:110:14");
      compute(
          (Addr)&temp_var_for_tac_9,
          {(Addr)&temp_var_for_tac_8, (Addr) &(temp_var_for_const_11 = zero)},
          "/home/shijia/Public/testprogram/e_j1l.c_e.c:110:19");
      computeLdDiv((Addr)&temp_var_for_tac_10, {(Addr)&z, (Addr)&ss},
                   "/home/shijia/Public/testprogram/e_j1l.c_e.c:111:16");
      AssignLd({(Addr)&cc}, (Addr)&temp_var_for_tac_10,
               "/home/shijia/Public/testprogram/e_j1l.c_e.c:111:12");
      ;
    }

    else {
      long double temp_var_for_ext_1;
      long double temp_var_for_tac_11;
      temp_var_for_tac_11 = z / cc;

      temp_var_for_ext_1 = temp_var_for_tac_11;
      computeLdDiv((Addr)&temp_var_for_tac_11, {(Addr)&z, (Addr)&cc},
                   "/home/shijia/Public/testprogram/e_j1l.c_e.c:116:32");
      AssignLd({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_11,
               "/home/shijia/Public/testprogram/e_j1l.c_e.c:116:28");
      ; // ss
      /*(ss)(z)(cc)(z)*/
      ss = temp_var_for_ext_1;
      AssignLd({(Addr)&ss}, (Addr)&temp_var_for_ext_1,
               "/home/shijia/Public/testprogram/e_j1l.c_e.c:118:12");
      ;
    }
  }
  /*
   * j1(x) = 1/sqrt(pi) * (P(1,x)*cc - Q(1,x)*ss) / sqrt(x)
   * y1(x) = 1/sqrt(pi) * (P(1,x)*ss + Q(1,x)*cc) / sqrt(x)
   */
  if (ix > 0x4080) {
    long double temp_var_for_ext_2;
    long double temp_var_for_tac_12, temp_var_for_tac_13;
    long double temp_var_for_const_12, temp_var_for_const_13;
    long double temp_var_for_callexp_2;

    temp_var_for_tac_12 = invsqrtpi * cc;

    temp_var_for_callexp_2 = __ieee754_sqrtl(y);
    temp_var_for_tac_13 = temp_var_for_tac_12 / temp_var_for_callexp_2;

    temp_var_for_ext_2 = temp_var_for_tac_13;
    computeLdMul((Addr)&temp_var_for_tac_12,
                 {(Addr) &(temp_var_for_const_12 = invsqrtpi), (Addr)&cc},
                 "/home/shijia/Public/testprogram/e_j1l.c_e.c:127:39");
    computeLdDiv((Addr)&temp_var_for_tac_13,
                 {(Addr)&temp_var_for_tac_12,
                  (Addr) &(temp_var_for_const_13 = temp_var_for_callexp_2)},
                 "/home/shijia/Public/testprogram/e_j1l.c_e.c:127:45");
    AssignLd({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_13,
             "/home/shijia/Public/testprogram/e_j1l.c_e.c:127:26");
    ; // z
    /*(cc)(z)(__ieee754_sqrtl(y))(cc)(invsqrtpi)*/
    z = temp_var_for_ext_2;
    AssignLd({(Addr)&z}, (Addr)&temp_var_for_ext_2,
             "/home/shijia/Public/testprogram/e_j1l.c_e.c:129:9");
    ;
  }

  else {
    long double temp_var_for_const_14;
    long double temp_var_for_callexp_3;

    temp_var_for_callexp_3 = __j1_y1_ponel(y);
    u = temp_var_for_callexp_3;
    AssignLd({(Addr)&u},
             (Addr) &(temp_var_for_const_14 = temp_var_for_callexp_3),
             "/home/shijia/Public/testprogram/e_j1l.c_e.c:133:9");
    ;
    long double temp_var_for_const_15;
    long double temp_var_for_callexp_4;

    temp_var_for_callexp_4 = __j1_y1_qonel(y);
    v = temp_var_for_callexp_4;
    AssignLd({(Addr)&v},
             (Addr) &(temp_var_for_const_15 = temp_var_for_callexp_4),
             "/home/shijia/Public/testprogram/e_j1l.c_e.c:134:9");
    ;
    long double temp_var_for_tac_14, temp_var_for_tac_15, temp_var_for_tac_16,
        temp_var_for_tac_17, temp_var_for_tac_18;
    long double temp_var_for_const_16, temp_var_for_const_17;
    long double temp_var_for_callexp_5;

    temp_var_for_tac_14 = u * cc;

    temp_var_for_tac_15 = v * ss;

    temp_var_for_tac_16 = temp_var_for_tac_14 - temp_var_for_tac_15;

    temp_var_for_tac_17 = invsqrtpi * temp_var_for_tac_16;

    temp_var_for_callexp_5 = __ieee754_sqrtl(y);
    temp_var_for_tac_18 = temp_var_for_tac_17 / temp_var_for_callexp_5;

    z = temp_var_for_tac_18;
    computeLdMul((Addr)&temp_var_for_tac_14, {(Addr)&u, (Addr)&cc},
                 "/home/shijia/Public/testprogram/e_j1l.c_e.c:135:26");
    computeLdMul((Addr)&temp_var_for_tac_15, {(Addr)&v, (Addr)&ss},
                 "/home/shijia/Public/testprogram/e_j1l.c_e.c:135:35");
    computeLdSub((Addr)&temp_var_for_tac_16,
                 {(Addr)&temp_var_for_tac_14, (Addr)&temp_var_for_tac_15},
                 "/home/shijia/Public/testprogram/e_j1l.c_e.c:135:31");
    computeLdMul((Addr)&temp_var_for_tac_17,
                 {(Addr) &(temp_var_for_const_16 = invsqrtpi),
                  (Addr)&temp_var_for_tac_16},
                 "/home/shijia/Public/testprogram/e_j1l.c_e.c:135:21");
    computeLdDiv((Addr)&temp_var_for_tac_18,
                 {(Addr)&temp_var_for_tac_17,
                  (Addr) &(temp_var_for_const_17 = temp_var_for_callexp_5)},
                 "/home/shijia/Public/testprogram/e_j1l.c_e.c:135:41");
    AssignLd({(Addr)&z}, (Addr)&temp_var_for_tac_18,
             "/home/shijia/Public/testprogram/e_j1l.c_e.c:135:9");
    ;
  }
  if (se & 0x8000) {
    long double temp_var_for_ext_3;
    long double temp_var_for_const_18;
    temp_var_for_ext_3 = (-(z));
    AssignLd({(Addr)&temp_var_for_ext_3},
             (Addr) &(temp_var_for_const_18 = (-(z))),
             "/home/shijia/Public/testprogram/e_j1l.c_e.c:139:26");
    ;
    callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
    callExp++; /*identify the function is  add move tmpShadow*/
    return (double temp_var_for_tac_19;
            double temp_var_for_const_19, temp_var_for_const_20;
            temp_var_for_tac_19 = 0.0 - 3;

            );
  }

  else {
    long double temp_var_for_ext_4;
    temp_var_for_ext_4 = z;
    computeDSub((Addr)&temp_var_for_tac_19,
                {(Addr) &(temp_var_for_const_20 = 0.0),
                 (Addr) &(temp_var_for_const_19 = 3)},
                "/home/shijia/Public/testprogram/e_j1l.c_e.c:143:19");
    AssignLd({(Addr)&temp_var_for_ext_4}, (Addr)&z,
             "/home/shijia/Public/testprogram/e_j1l.c_e.c:148:26");
    ;
    callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_4;
  }
}
if (ix < 0x3fde) /* |x| < 2^-33 */
{
  if (int temp_var_for_tac_20, temp_var_for_tac_21;
      int temp_var_for_const_21, temp_var_for_const_22;
      temp_var_for_tac_20 = hugeval + x;

      temp_var_for_tac_21 = temp_var_for_tac_20 > one;

      ) {
    long double temp_var_for_ext_5;
    long double temp_var_for_tac_22;
    long double temp_var_for_const_23;
    temp_var_for_tac_22 = 0.5 * x;

    temp_var_for_ext_5 = temp_var_for_tac_22;
    computeLdAdd((Addr)&temp_var_for_tac_20,
                 {(Addr) &(temp_var_for_const_21 = hugeval), (Addr)&x},
                 "/home/shijia/Public/testprogram/e_j1l.c_e.c:157:17");
    compute((Addr)&temp_var_for_tac_21,
            {(Addr)&temp_var_for_tac_20, (Addr) &(temp_var_for_const_22 = one)},
            "/home/shijia/Public/testprogram/e_j1l.c_e.c:157:21");
    computeLdMul((Addr)&temp_var_for_tac_22,
                 {(Addr) &(temp_var_for_const_23 = 0.5), (Addr)&x},
                 "/home/shijia/Public/testprogram/e_j1l.c_e.c:159:32");
    AssignLd({(Addr)&temp_var_for_ext_5}, (Addr)&temp_var_for_tac_22,
             "/home/shijia/Public/testprogram/e_j1l.c_e.c:159:26");
    ;
    callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_5;
  }
  /* inexact if x!=0 necessary */
}
long double temp_var_for_tac_23;
temp_var_for_tac_23 = x * x;

z = temp_var_for_tac_23;
computeLdMul((Addr)&temp_var_for_tac_23, {(Addr)&x, (Addr)&x},
             "/home/shijia/Public/testprogram/e_j1l.c_e.c:167:9");
AssignLd({(Addr)&z}, (Addr)&temp_var_for_tac_23,
         "/home/shijia/Public/testprogram/e_j1l.c_e.c:167:5");
;
long double temp_var_for_tac_24, temp_var_for_tac_25, temp_var_for_tac_26,
    temp_var_for_tac_27, temp_var_for_tac_28, temp_var_for_tac_29,
    temp_var_for_tac_30, temp_var_for_tac_31, temp_var_for_tac_32;
long double temp_var_for_const_24, temp_var_for_const_25, temp_var_for_const_26,
    temp_var_for_const_27, temp_var_for_const_28;
temp_var_for_tac_24 = z * R[4];

temp_var_for_tac_25 = R[3] + temp_var_for_tac_24;

temp_var_for_tac_26 = z * temp_var_for_tac_25;

temp_var_for_tac_27 = R[2] + temp_var_for_tac_26;

temp_var_for_tac_28 = z * temp_var_for_tac_27;

temp_var_for_tac_29 = R[1] + temp_var_for_tac_28;

temp_var_for_tac_30 = z * temp_var_for_tac_29;

temp_var_for_tac_31 = R[0] + temp_var_for_tac_30;

temp_var_for_tac_32 = z * temp_var_for_tac_31;

r = temp_var_for_tac_32;
computeLdMul((Addr)&temp_var_for_tac_24,
             {(Addr)&z, (Addr) &(temp_var_for_const_24 = R[4])},
             "/home/shijia/Public/testprogram/e_j1l.c_e.c:168:57");
computeLdAdd((Addr)&temp_var_for_tac_25,
             {(Addr) &(temp_var_for_const_25 = R[3]),
              (Addr)&temp_var_for_tac_24},
             "/home/shijia/Public/testprogram/e_j1l.c_e.c:168:53");
computeLdMul((Addr)&temp_var_for_tac_26, {(Addr)&z, (Addr)&temp_var_for_tac_25},
             "/home/shijia/Public/testprogram/e_j1l.c_e.c:168:45");
computeLdAdd((Addr)&temp_var_for_tac_27,
             {(Addr) &(temp_var_for_const_26 = R[2]),
              (Addr)&temp_var_for_tac_26},
             "/home/shijia/Public/testprogram/e_j1l.c_e.c:168:41");
computeLdMul((Addr)&temp_var_for_tac_28, {(Addr)&z, (Addr)&temp_var_for_tac_27},
             "/home/shijia/Public/testprogram/e_j1l.c_e.c:168:33");
computeLdAdd((Addr)&temp_var_for_tac_29,
             {(Addr) &(temp_var_for_const_27 = R[1]),
              (Addr)&temp_var_for_tac_28},
             "/home/shijia/Public/testprogram/e_j1l.c_e.c:168:29");
computeLdMul((Addr)&temp_var_for_tac_30, {(Addr)&z, (Addr)&temp_var_for_tac_29},
             "/home/shijia/Public/testprogram/e_j1l.c_e.c:168:21");
computeLdAdd((Addr)&temp_var_for_tac_31,
             {(Addr) &(temp_var_for_const_28 = R[0]),
              (Addr)&temp_var_for_tac_30},
             "/home/shijia/Public/testprogram/e_j1l.c_e.c:168:17");
computeLdMul((Addr)&temp_var_for_tac_32, {(Addr)&z, (Addr)&temp_var_for_tac_31},
             "/home/shijia/Public/testprogram/e_j1l.c_e.c:168:9");
AssignLd({(Addr)&r}, (Addr)&temp_var_for_tac_32,
         "/home/shijia/Public/testprogram/e_j1l.c_e.c:168:5");
;
long double temp_var_for_tac_33, temp_var_for_tac_34, temp_var_for_tac_35,
    temp_var_for_tac_36, temp_var_for_tac_37, temp_var_for_tac_38,
    temp_var_for_tac_39;
long double temp_var_for_const_29, temp_var_for_const_30, temp_var_for_const_31,
    temp_var_for_const_32;
temp_var_for_tac_33 = S[3] + z;

temp_var_for_tac_34 = z * temp_var_for_tac_33;

temp_var_for_tac_35 = S[2] + temp_var_for_tac_34;

temp_var_for_tac_36 = z * temp_var_for_tac_35;

temp_var_for_tac_37 = S[1] + temp_var_for_tac_36;

temp_var_for_tac_38 = z * temp_var_for_tac_37;

temp_var_for_tac_39 = S[0] + temp_var_for_tac_38;

s = temp_var_for_tac_39;
computeLdAdd((Addr)&temp_var_for_tac_33,
             {(Addr) &(temp_var_for_const_29 = S[3]), (Addr)&z},
             "/home/shijia/Public/testprogram/e_j1l.c_e.c:169:48");
computeLdMul((Addr)&temp_var_for_tac_34, {(Addr)&z, (Addr)&temp_var_for_tac_33},
             "/home/shijia/Public/testprogram/e_j1l.c_e.c:169:40");
computeLdAdd((Addr)&temp_var_for_tac_35,
             {(Addr) &(temp_var_for_const_30 = S[2]),
              (Addr)&temp_var_for_tac_34},
             "/home/shijia/Public/testprogram/e_j1l.c_e.c:169:36");
computeLdMul((Addr)&temp_var_for_tac_36, {(Addr)&z, (Addr)&temp_var_for_tac_35},
             "/home/shijia/Public/testprogram/e_j1l.c_e.c:169:28");
computeLdAdd((Addr)&temp_var_for_tac_37,
             {(Addr) &(temp_var_for_const_31 = S[1]),
              (Addr)&temp_var_for_tac_36},
             "/home/shijia/Public/testprogram/e_j1l.c_e.c:169:24");
computeLdMul((Addr)&temp_var_for_tac_38, {(Addr)&z, (Addr)&temp_var_for_tac_37},
             "/home/shijia/Public/testprogram/e_j1l.c_e.c:169:16");
computeLdAdd((Addr)&temp_var_for_tac_39,
             {(Addr) &(temp_var_for_const_32 = S[0]),
              (Addr)&temp_var_for_tac_38},
             "/home/shijia/Public/testprogram/e_j1l.c_e.c:169:12");
AssignLd({(Addr)&s}, (Addr)&temp_var_for_tac_39,
         "/home/shijia/Public/testprogram/e_j1l.c_e.c:169:5");
;
r *= x;
;
long double temp_var_for_ext_6;
long double temp_var_for_tac_41, temp_var_for_tac_42, temp_var_for_tac_43;
long double temp_var_for_const_33;
temp_var_for_tac_41 = x * 0.5;

temp_var_for_tac_42 = r / s;

temp_var_for_tac_43 = temp_var_for_tac_41 + temp_var_for_tac_42;

temp_var_for_ext_6 = temp_var_for_tac_43;
computeLdMul((Addr)&temp_var_for_tac_41,
             {(Addr)&x, (Addr) &(temp_var_for_const_33 = 0.5)},
             "/home/shijia/Public/testprogram/e_j1l.c_e.c:172:27");
computeLdDiv((Addr)&temp_var_for_tac_42, {(Addr)&r, (Addr)&s},
             "/home/shijia/Public/testprogram/e_j1l.c_e.c:172:37");
computeLdAdd((Addr)&temp_var_for_tac_43,
             {(Addr)&temp_var_for_tac_41, (Addr)&temp_var_for_tac_42},
             "/home/shijia/Public/testprogram/e_j1l.c_e.c:172:33");
AssignLd({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_43,
         "/home/shijia/Public/testprogram/e_j1l.c_e.c:172:22");
;
callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
callExp++; /*identify the function is  add move tmpShadow*/
return temp_var_for_ext_6;
}

/* wrapper j1 */
long double __j1l(long double x) {
  if (isgreater(__ieee754_fabsl(x), X_TLOSS) && _LIB_VERSION != _IEEE_ &&
      _LIB_VERSION != _POSIX_)
  /* j1(|x|>X_TLOSS) */
  {
    long double temp_var_for_ext_7;
    long double temp_var_for_const_34;
    long double temp_var_for_callexp_6;

    temp_var_for_callexp_6 =
        __kernel_standard_l(x, x, 0.0L, KMATHERRL_J1_TLOSS);
    temp_var_for_ext_7 = temp_var_for_callexp_6;
    AssignLd({(Addr)&temp_var_for_ext_7},
             (Addr) &(temp_var_for_const_34 = temp_var_for_callexp_6),
             "/home/shijia/Public/testprogram/e_j1l.c_e.c:185:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_7;
  }

  long double temp_var_for_ext_8;
  long double temp_var_for_const_35;
  long double temp_var_for_callexp_7;

  temp_var_for_callexp_7 = __ieee754_j1l(x);
  temp_var_for_ext_8 = temp_var_for_callexp_7;
  AssignLd({(Addr)&temp_var_for_ext_8},
           (Addr) &(temp_var_for_const_35 = temp_var_for_callexp_7),
           "/home/shijia/Public/testprogram/e_j1l.c_e.c:192:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_8;
}

__typeof(__j1l) j1l __attribute__((weak, alias("__j1l")));

#endif
