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

/* double erf(double x)
 * double erfc(double x)
 *			     x
 *		      2      |\
 *     erf(x)  =  ---------  | exp(-t*t)dt
 *		   sqrt(pi) \|
 *			     0
 *
 *     erfc(x) =  1-erf(x)
 *  Note that
 *		erf(-x) = -erf(x)
 *		erfc(-x) = 2 - erfc(x)
 *
 * Method:
 *	1. For |x| in [0, 0.84375]
 *	    erf(x)  = x + x*R(x^2)
 *          erfc(x) = 1 - erf(x)           if x in [-.84375,0.25]
 *                  = 0.5 + ((0.5-x)-x*R)  if x in [0.25,0.84375]
 *	   Remark. The formula is derived by noting
 *          erf(x) = (2/sqrt(pi))*(x - x^3/3 + x^5/10 - x^7/42 + ....)
 *	   and that
 *          2/sqrt(pi) = 1.128379167095512573896158903121545171688
 *	   is close to one. The interval is chosen because the fix
 *	   point of erf(x) is near 0.6174 (i.e., erf(x)=x when x is
 *	   near 0.6174), and by some experiment, 0.84375 is chosen to
 *	   guarantee the error is less than one ulp for erf.
 *
 *      2. For |x| in [0.84375,1.25], let s = |x| - 1, and
 *         c = 0.84506291151 rounded to single (24 bits)
 *	erf(x)  = sign(x) * (c  + P1(s)/Q1(s))
 *	erfc(x) = (1-c)  - P1(s)/Q1(s) if x > 0
 *			  1+(c+P1(s)/Q1(s))    if x < 0
 *	   Remark: here we use the taylor series expansion at x=1.
 *		erf(1+s) = erf(1) + s*Poly(s)
 *			 = 0.845.. + P1(s)/Q1(s)
 *	   Note that |P1/Q1|< 0.078 for x in [0.84375,1.25]
 *
 *      3. For x in [1.25,1/0.35(~2.857143)],
 *	erfc(x) = (1/x)*exp(-x*x-0.5625+R1(z)/S1(z))
 *              z=1/x^2
 *	erf(x)  = 1 - erfc(x)
 *
 *      4. For x in [1/0.35,107]
 *	erfc(x) = (1/x)*exp(-x*x-0.5625+R2/S2) if x > 0
 *			= 2.0 - (1/x)*exp(-x*x-0.5625+R2(z)/S2(z))
 *                             if -6.666<x<0
 *			= 2.0 - tiny		(if x <= -6.666)
 *              z=1/x^2
 *	erf(x)  = sign(x)*(1.0 - erfc(x)) if x < 6.666, else
 *	erf(x)  = sign(x)*(1.0 - tiny)
 *      Note1:
 *	   To compute exp(-x*x-0.5625+R/S), let s be a single
 *	   precision number and s := x; then
 *		-x*x = -s*s + (s-x)*(s+x)
 *	        exp(-x*x-0.5626+R/S) =
 *			exp(-s*s-0.5625)*exp((s-x)*(s+x)+R/S);
 *      Note2:
 *	   Here 4 and 5 make use of the asymptotic series
 *			  exp(-x*x)
 *		erfc(x) ~ ---------- * ( 1 + Poly(1/x^2) )
 *			  x*sqrt(pi)
 *
 *      5. For inf > x >= 107
 *	erf(x)  = sign(x) *(1 - tiny)  (raise inexact)
 *	erfc(x) = tiny*tiny (raise underflow) if x > 0
 *			= 2 - tiny if x<0
 *
 *      7. Special case:
 *	erf(0)  = 0, erf(inf)  = 1, erf(-inf) = -1,
 *	erfc(0) = 1, erfc(inf) = 0, erfc(-inf) = 2,
 *		erfc/erf(NaN) is NaN
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

long double __erfl(long double x) {
  long double R, S, P, Q, s, y, z, r;
  int32_t ix, i;
  uint32_t se, i0, i1;

  static const long double tiny = 1e-4931L;
  static const long double one = 1.0L;
  static const long double erx = 0.845062911510467529296875L;
  /* c = (float)0.84506291151 */
  /*
   * Coefficients for approximation to  erf on [0,0.84375]
   */
  /* 2/sqrt(pi) - 1 */
  static const long double efx = 1.2837916709551257389615890312154517168810E-1L;
  /* 8 * (2/sqrt(pi) - 1) */
  static const long double efx8 = 1.0270333367641005911692712249723613735048E0L;

#include "t_erfl.h"

  long double temp_var_for_const_0;
  ew_u.value = x;
  AssignLd({(Addr) &(temp_var_for_const_0 = ew_u.value)}, (Addr)&x,
           "/home/shijia/Public/testprogram/s_erfl.c_e.c:131:3 "
           "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
  ;
  ix = se & 0x7fff;

  if (ix >= 0x7fff) { /* erf(nan)=nan */
    i = ((se & 0xffff) >> 15) << 1;
    long double temp_var_for_ext_0;
    long double temp_var_for_tac_0, temp_var_for_tac_1, temp_var_for_tac_2;
    long double temp_var_for_const_1, temp_var_for_const_2,
        temp_var_for_const_3, temp_var_for_const_4;
    temp_var_for_tac_0 = 1 - i;

    temp_var_for_tac_1 = one / x;

    temp_var_for_tac_2 = ((long double)temp_var_for_tac_0) + temp_var_for_tac_1;

    temp_var_for_ext_0 = temp_var_for_tac_2;
    computeSub((Addr)&temp_var_for_tac_0, {(Addr) &(temp_var_for_const_2 = 1),
                                           (Addr) &(temp_var_for_const_1 = i)},
               "/home/shijia/Public/testprogram/s_erfl.c_e.c:137:42");
    computeLdDiv((Addr)&temp_var_for_tac_1,
                 {(Addr) &(temp_var_for_const_3 = one), (Addr)&x},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:137:53");
    computeLdAdd(
        (Addr)&temp_var_for_tac_2,
        {(Addr) &(temp_var_for_const_4 = ((long double)temp_var_for_tac_0)),
         (Addr)&temp_var_for_tac_1},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:137:47");
    AssignLd({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_2,
             "/home/shijia/Public/testprogram/s_erfl.c_e.c:137:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++;                 /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0; /* erf(+-inf)=+-1 */
  }

  ix = (ix << 16) | (i0 >> 16);
  if (ix < IC(0x3ffed800)) /* |x|<0.84375 */
  {
    if (ix < IC(0x3fde8000)) /* |x|<2**-33 */
    {
      if (ix < IC(0x00080000)) {
        long double temp_var_for_ext_1;
        temp_var_for_ext_1 = long double temp_var_for_tac_3, temp_var_for_tac_4,
        temp_var_for_tac_5, temp_var_for_tac_6;
        long double temp_var_for_const_5, temp_var_for_const_6,
            temp_var_for_const_7;
        temp_var_for_tac_3 = 8.0 * x;

        temp_var_for_tac_4 = efx8 * x;

        temp_var_for_tac_5 = temp_var_for_tac_3 + temp_var_for_tac_4;

        temp_var_for_tac_6 = 0.125 * temp_var_for_tac_5;

        ;
        callExpStack.push(
            getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_1;
      }
      /*avoid underflow */
      long double temp_var_for_ext_2;
      long double temp_var_for_tac_7, temp_var_for_tac_8;
      long double temp_var_for_const_8;
      temp_var_for_tac_7 = efx * x;

      temp_var_for_tac_8 = x + temp_var_for_tac_7;

      temp_var_for_ext_2 = temp_var_for_tac_8;
      computeLdMul((Addr)&temp_var_for_tac_3,
                   {(Addr) &(temp_var_for_const_5 = 8.0), (Addr)&x},
                   "/home/shijia/Public/testprogram/s_erfl.c_e.c:150:43");
      computeLdMul((Addr)&temp_var_for_tac_4,
                   {(Addr) &(temp_var_for_const_6 = efx8), (Addr)&x},
                   "/home/shijia/Public/testprogram/s_erfl.c_e.c:150:54");
      computeLdAdd((Addr)&temp_var_for_tac_5,
                   {(Addr)&temp_var_for_tac_3, (Addr)&temp_var_for_tac_4},
                   "/home/shijia/Public/testprogram/s_erfl.c_e.c:150:47");
      computeLdMul(
          (Addr)&temp_var_for_tac_6,
          {(Addr) &(temp_var_for_const_7 = 0.125), (Addr)&temp_var_for_tac_5},
          "/home/shijia/Public/testprogram/s_erfl.c_e.c:150:36");
      computeLdMul((Addr)&temp_var_for_tac_7,
                   {(Addr) &(temp_var_for_const_8 = efx), (Addr)&x},
                   "/home/shijia/Public/testprogram/s_erfl.c_e.c:158:36");
      computeLdAdd((Addr)&temp_var_for_tac_8,
                   {(Addr)&x, (Addr)&temp_var_for_tac_7},
                   "/home/shijia/Public/testprogram/s_erfl.c_e.c:158:30");
      AssignLd({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_8,
               "/home/shijia/Public/testprogram/s_erfl.c_e.c:158:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_2;
    }
    long double temp_var_for_tac_9;
    temp_var_for_tac_9 = x * x;

    z = temp_var_for_tac_9;
    computeLdMul((Addr)&temp_var_for_tac_9, {(Addr)&x, (Addr)&x},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:164:11");
    AssignLd({(Addr)&z}, (Addr)&temp_var_for_tac_9,
             "/home/shijia/Public/testprogram/s_erfl.c_e.c:164:7");
    ;
    long double temp_var_for_tac_10, temp_var_for_tac_11, temp_var_for_tac_12,
        temp_var_for_tac_13, temp_var_for_tac_14, temp_var_for_tac_15,
        temp_var_for_tac_16, temp_var_for_tac_17, temp_var_for_tac_18,
        temp_var_for_tac_19;
    long double temp_var_for_const_9, temp_var_for_const_10,
        temp_var_for_const_11, temp_var_for_const_12, temp_var_for_const_13,
        temp_var_for_const_14;
    temp_var_for_tac_10 = z * pp[5];

    temp_var_for_tac_11 = pp[4] + temp_var_for_tac_10;

    temp_var_for_tac_12 = z * temp_var_for_tac_11;

    temp_var_for_tac_13 = pp[3] + temp_var_for_tac_12;

    temp_var_for_tac_14 = z * temp_var_for_tac_13;

    temp_var_for_tac_15 = pp[2] + temp_var_for_tac_14;

    temp_var_for_tac_16 = z * temp_var_for_tac_15;

    temp_var_for_tac_17 = pp[1] + temp_var_for_tac_16;

    temp_var_for_tac_18 = z * temp_var_for_tac_17;

    temp_var_for_tac_19 = pp[0] + temp_var_for_tac_18;

    r = temp_var_for_tac_19;
    computeLdMul((Addr)&temp_var_for_tac_10,
                 {(Addr)&z, (Addr) &(temp_var_for_const_9 = pp[5])},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:166:63");
    computeLdAdd(
        (Addr)&temp_var_for_tac_11,
        {(Addr) &(temp_var_for_const_10 = pp[4]), (Addr)&temp_var_for_tac_10},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:166:59");
    computeLdMul((Addr)&temp_var_for_tac_12,
                 {(Addr)&z, (Addr)&temp_var_for_tac_11},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:166:50");
    computeLdAdd(
        (Addr)&temp_var_for_tac_13,
        {(Addr) &(temp_var_for_const_11 = pp[3]), (Addr)&temp_var_for_tac_12},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:166:46");
    computeLdMul((Addr)&temp_var_for_tac_14,
                 {(Addr)&z, (Addr)&temp_var_for_tac_13},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:166:37");
    computeLdAdd(
        (Addr)&temp_var_for_tac_15,
        {(Addr) &(temp_var_for_const_12 = pp[2]), (Addr)&temp_var_for_tac_14},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:166:33");
    computeLdMul((Addr)&temp_var_for_tac_16,
                 {(Addr)&z, (Addr)&temp_var_for_tac_15},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:166:24");
    computeLdAdd(
        (Addr)&temp_var_for_tac_17,
        {(Addr) &(temp_var_for_const_13 = pp[1]), (Addr)&temp_var_for_tac_16},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:166:20");
    computeLdMul((Addr)&temp_var_for_tac_18,
                 {(Addr)&z, (Addr)&temp_var_for_tac_17},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:166:11");
    computeLdAdd(
        (Addr)&temp_var_for_tac_19,
        {(Addr) &(temp_var_for_const_14 = pp[0]), (Addr)&temp_var_for_tac_18},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:165:15");
    AssignLd({(Addr)&r}, (Addr)&temp_var_for_tac_19,
             "/home/shijia/Public/testprogram/s_erfl.c_e.c:165:7");
    ;
    long double temp_var_for_tac_20, temp_var_for_tac_21, temp_var_for_tac_22,
        temp_var_for_tac_23, temp_var_for_tac_24, temp_var_for_tac_25,
        temp_var_for_tac_26, temp_var_for_tac_27, temp_var_for_tac_28,
        temp_var_for_tac_29, temp_var_for_tac_30;
    long double temp_var_for_const_15, temp_var_for_const_16,
        temp_var_for_const_17, temp_var_for_const_18, temp_var_for_const_19,
        temp_var_for_const_20;
    temp_var_for_tac_20 = qq[5] + z;

    temp_var_for_tac_21 = z * temp_var_for_tac_20;

    temp_var_for_tac_22 = qq[4] + temp_var_for_tac_21;

    temp_var_for_tac_23 = z * temp_var_for_tac_22;

    temp_var_for_tac_24 = qq[3] + temp_var_for_tac_23;

    temp_var_for_tac_25 = z * temp_var_for_tac_24;

    temp_var_for_tac_26 = qq[2] + temp_var_for_tac_25;

    temp_var_for_tac_27 = z * temp_var_for_tac_26;

    temp_var_for_tac_28 = qq[1] + temp_var_for_tac_27;

    temp_var_for_tac_29 = z * temp_var_for_tac_28;

    temp_var_for_tac_30 = qq[0] + temp_var_for_tac_29;

    s = temp_var_for_tac_30;
    computeLdAdd((Addr)&temp_var_for_tac_20,
                 {(Addr) &(temp_var_for_const_15 = qq[5]), (Addr)&z},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:168:72");
    computeLdMul((Addr)&temp_var_for_tac_21,
                 {(Addr)&z, (Addr)&temp_var_for_tac_20},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:168:63");
    computeLdAdd(
        (Addr)&temp_var_for_tac_22,
        {(Addr) &(temp_var_for_const_16 = qq[4]), (Addr)&temp_var_for_tac_21},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:168:59");
    computeLdMul((Addr)&temp_var_for_tac_23,
                 {(Addr)&z, (Addr)&temp_var_for_tac_22},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:168:50");
    computeLdAdd(
        (Addr)&temp_var_for_tac_24,
        {(Addr) &(temp_var_for_const_17 = qq[3]), (Addr)&temp_var_for_tac_23},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:168:46");
    computeLdMul((Addr)&temp_var_for_tac_25,
                 {(Addr)&z, (Addr)&temp_var_for_tac_24},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:168:37");
    computeLdAdd(
        (Addr)&temp_var_for_tac_26,
        {(Addr) &(temp_var_for_const_18 = qq[2]), (Addr)&temp_var_for_tac_25},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:168:33");
    computeLdMul((Addr)&temp_var_for_tac_27,
                 {(Addr)&z, (Addr)&temp_var_for_tac_26},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:168:24");
    computeLdAdd(
        (Addr)&temp_var_for_tac_28,
        {(Addr) &(temp_var_for_const_19 = qq[1]), (Addr)&temp_var_for_tac_27},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:168:20");
    computeLdMul((Addr)&temp_var_for_tac_29,
                 {(Addr)&z, (Addr)&temp_var_for_tac_28},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:168:11");
    computeLdAdd(
        (Addr)&temp_var_for_tac_30,
        {(Addr) &(temp_var_for_const_20 = qq[0]), (Addr)&temp_var_for_tac_29},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:167:15");
    AssignLd({(Addr)&s}, (Addr)&temp_var_for_tac_30,
             "/home/shijia/Public/testprogram/s_erfl.c_e.c:167:7");
    ;
    long double temp_var_for_tac_31;
    temp_var_for_tac_31 = r / s;

    y = temp_var_for_tac_31;
    computeLdDiv((Addr)&temp_var_for_tac_31, {(Addr)&r, (Addr)&s},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:169:11");
    AssignLd({(Addr)&y}, (Addr)&temp_var_for_tac_31,
             "/home/shijia/Public/testprogram/s_erfl.c_e.c:169:7");
    ;
    long double temp_var_for_ext_3;
    long double temp_var_for_tac_32, temp_var_for_tac_33;
    temp_var_for_tac_32 = x * y;

    temp_var_for_tac_33 = x + temp_var_for_tac_32;

    temp_var_for_ext_3 = temp_var_for_tac_33;
    computeLdMul((Addr)&temp_var_for_tac_32, {(Addr)&x, (Addr)&y},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:171:32");
    computeLdAdd((Addr)&temp_var_for_tac_33,
                 {(Addr)&x, (Addr)&temp_var_for_tac_32},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:171:28");
    AssignLd({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_33,
             "/home/shijia/Public/testprogram/s_erfl.c_e.c:171:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_3;
  }
  if (ix < IC(0x3fffa000)) /* 1.25 */
  {                        /* 0.84375 <= |x| < 1.25 */
    long double temp_var_for_ext_4;
    long double temp_var_for_tac_34;
    long double temp_var_for_const_21, temp_var_for_const_22;
    long double temp_var_for_callexp_0;

    temp_var_for_callexp_0 = fabsl(x);
    temp_var_for_tac_34 = temp_var_for_callexp_0 - one;

    temp_var_for_ext_4 = temp_var_for_tac_34;
    computeLdSub((Addr)&temp_var_for_tac_34,
                 {(Addr) &(temp_var_for_const_22 = temp_var_for_callexp_0),
                  (Addr) &(temp_var_for_const_21 = one)},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:179:45");
    AssignLd({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_34,
             "/home/shijia/Public/testprogram/s_erfl.c_e.c:179:24");
    ; // s
    /*(s)(r)(3)(e)(t)(3)(e)(one)(__ieee754_fabsl(x))*/
    s = temp_var_for_ext_4;
    AssignLd({(Addr)&s}, (Addr)&temp_var_for_ext_4,
             "/home/shijia/Public/testprogram/s_erfl.c_e.c:181:7");
    ;
    long double temp_var_for_tac_35, temp_var_for_tac_36, temp_var_for_tac_37,
        temp_var_for_tac_38, temp_var_for_tac_39, temp_var_for_tac_40,
        temp_var_for_tac_41, temp_var_for_tac_42, temp_var_for_tac_43,
        temp_var_for_tac_44, temp_var_for_tac_45, temp_var_for_tac_46,
        temp_var_for_tac_47, temp_var_for_tac_48;
    long double temp_var_for_const_23, temp_var_for_const_24,
        temp_var_for_const_25, temp_var_for_const_26, temp_var_for_const_27,
        temp_var_for_const_28, temp_var_for_const_29, temp_var_for_const_30;
    temp_var_for_tac_35 = s * pa[7];

    temp_var_for_tac_36 = pa[6] + temp_var_for_tac_35;

    temp_var_for_tac_37 = s * temp_var_for_tac_36;

    temp_var_for_tac_38 = pa[5] + temp_var_for_tac_37;

    temp_var_for_tac_39 = s * temp_var_for_tac_38;

    temp_var_for_tac_40 = pa[4] + temp_var_for_tac_39;

    temp_var_for_tac_41 = s * temp_var_for_tac_40;

    temp_var_for_tac_42 = pa[3] + temp_var_for_tac_41;

    temp_var_for_tac_43 = s * temp_var_for_tac_42;

    temp_var_for_tac_44 = pa[2] + temp_var_for_tac_43;

    temp_var_for_tac_45 = s * temp_var_for_tac_44;

    temp_var_for_tac_46 = pa[1] + temp_var_for_tac_45;

    temp_var_for_tac_47 = s * temp_var_for_tac_46;

    temp_var_for_tac_48 = pa[0] + temp_var_for_tac_47;

    P = temp_var_for_tac_48;
    computeLdMul((Addr)&temp_var_for_tac_35,
                 {(Addr)&s, (Addr) &(temp_var_for_const_23 = pa[7])},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:186:65");
    computeLdAdd(
        (Addr)&temp_var_for_tac_36,
        {(Addr) &(temp_var_for_const_24 = pa[6]), (Addr)&temp_var_for_tac_35},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:186:61");
    computeLdMul((Addr)&temp_var_for_tac_37,
                 {(Addr)&s, (Addr)&temp_var_for_tac_36},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:186:52");
    computeLdAdd(
        (Addr)&temp_var_for_tac_38,
        {(Addr) &(temp_var_for_const_25 = pa[5]), (Addr)&temp_var_for_tac_37},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:186:48");
    computeLdMul((Addr)&temp_var_for_tac_39,
                 {(Addr)&s, (Addr)&temp_var_for_tac_38},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:186:39");
    computeLdAdd(
        (Addr)&temp_var_for_tac_40,
        {(Addr) &(temp_var_for_const_26 = pa[4]), (Addr)&temp_var_for_tac_39},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:186:35");
    computeLdMul((Addr)&temp_var_for_tac_41,
                 {(Addr)&s, (Addr)&temp_var_for_tac_40},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:186:26");
    computeLdAdd(
        (Addr)&temp_var_for_tac_42,
        {(Addr) &(temp_var_for_const_27 = pa[3]), (Addr)&temp_var_for_tac_41},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:185:30");
    computeLdMul((Addr)&temp_var_for_tac_43,
                 {(Addr)&s, (Addr)&temp_var_for_tac_42},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:185:21");
    computeLdAdd(
        (Addr)&temp_var_for_tac_44,
        {(Addr) &(temp_var_for_const_28 = pa[2]), (Addr)&temp_var_for_tac_43},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:184:25");
    computeLdMul((Addr)&temp_var_for_tac_45,
                 {(Addr)&s, (Addr)&temp_var_for_tac_44},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:184:16");
    computeLdAdd(
        (Addr)&temp_var_for_tac_46,
        {(Addr) &(temp_var_for_const_29 = pa[1]), (Addr)&temp_var_for_tac_45},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:183:20");
    computeLdMul((Addr)&temp_var_for_tac_47,
                 {(Addr)&s, (Addr)&temp_var_for_tac_46},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:183:11");
    computeLdAdd(
        (Addr)&temp_var_for_tac_48,
        {(Addr) &(temp_var_for_const_30 = pa[0]), (Addr)&temp_var_for_tac_47},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:182:15");
    AssignLd({(Addr)&P}, (Addr)&temp_var_for_tac_48,
             "/home/shijia/Public/testprogram/s_erfl.c_e.c:182:7");
    ;
    long double temp_var_for_tac_49, temp_var_for_tac_50, temp_var_for_tac_51,
        temp_var_for_tac_52, temp_var_for_tac_53, temp_var_for_tac_54,
        temp_var_for_tac_55, temp_var_for_tac_56, temp_var_for_tac_57,
        temp_var_for_tac_58, temp_var_for_tac_59, temp_var_for_tac_60,
        temp_var_for_tac_61;
    long double temp_var_for_const_31, temp_var_for_const_32,
        temp_var_for_const_33, temp_var_for_const_34, temp_var_for_const_35,
        temp_var_for_const_36, temp_var_for_const_37;
    temp_var_for_tac_49 = qa[6] + s;

    temp_var_for_tac_50 = s * temp_var_for_tac_49;

    temp_var_for_tac_51 = qa[5] + temp_var_for_tac_50;

    temp_var_for_tac_52 = s * temp_var_for_tac_51;

    temp_var_for_tac_53 = qa[4] + temp_var_for_tac_52;

    temp_var_for_tac_54 = s * temp_var_for_tac_53;

    temp_var_for_tac_55 = qa[3] + temp_var_for_tac_54;

    temp_var_for_tac_56 = s * temp_var_for_tac_55;

    temp_var_for_tac_57 = qa[2] + temp_var_for_tac_56;

    temp_var_for_tac_58 = s * temp_var_for_tac_57;

    temp_var_for_tac_59 = qa[1] + temp_var_for_tac_58;

    temp_var_for_tac_60 = s * temp_var_for_tac_59;

    temp_var_for_tac_61 = qa[0] + temp_var_for_tac_60;

    Q = temp_var_for_tac_61;
    computeLdAdd((Addr)&temp_var_for_tac_49,
                 {(Addr) &(temp_var_for_const_31 = qa[6]), (Addr)&s},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:190:69");
    computeLdMul((Addr)&temp_var_for_tac_50,
                 {(Addr)&s, (Addr)&temp_var_for_tac_49},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:190:60");
    computeLdAdd(
        (Addr)&temp_var_for_tac_51,
        {(Addr) &(temp_var_for_const_32 = qa[5]), (Addr)&temp_var_for_tac_50},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:190:56");
    computeLdMul((Addr)&temp_var_for_tac_52,
                 {(Addr)&s, (Addr)&temp_var_for_tac_51},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:190:47");
    computeLdAdd(
        (Addr)&temp_var_for_tac_53,
        {(Addr) &(temp_var_for_const_33 = qa[4]), (Addr)&temp_var_for_tac_52},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:190:43");
    computeLdMul((Addr)&temp_var_for_tac_54,
                 {(Addr)&s, (Addr)&temp_var_for_tac_53},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:190:34");
    computeLdAdd(
        (Addr)&temp_var_for_tac_55,
        {(Addr) &(temp_var_for_const_34 = qa[3]), (Addr)&temp_var_for_tac_54},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:190:30");
    computeLdMul((Addr)&temp_var_for_tac_56,
                 {(Addr)&s, (Addr)&temp_var_for_tac_55},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:190:21");
    computeLdAdd(
        (Addr)&temp_var_for_tac_57,
        {(Addr) &(temp_var_for_const_35 = qa[2]), (Addr)&temp_var_for_tac_56},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:189:25");
    computeLdMul((Addr)&temp_var_for_tac_58,
                 {(Addr)&s, (Addr)&temp_var_for_tac_57},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:189:16");
    computeLdAdd(
        (Addr)&temp_var_for_tac_59,
        {(Addr) &(temp_var_for_const_36 = qa[1]), (Addr)&temp_var_for_tac_58},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:188:20");
    computeLdMul((Addr)&temp_var_for_tac_60,
                 {(Addr)&s, (Addr)&temp_var_for_tac_59},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:188:11");
    computeLdAdd(
        (Addr)&temp_var_for_tac_61,
        {(Addr) &(temp_var_for_const_37 = qa[0]), (Addr)&temp_var_for_tac_60},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:187:15");
    AssignLd({(Addr)&Q}, (Addr)&temp_var_for_tac_61,
             "/home/shijia/Public/testprogram/s_erfl.c_e.c:187:7");
    ;
    if ((se & 0x8000) == 0) {
      long double temp_var_for_ext_5;
      long double temp_var_for_tac_62, temp_var_for_tac_63;
      long double temp_var_for_const_38;
      temp_var_for_tac_62 = P / Q;

      temp_var_for_tac_63 = erx + temp_var_for_tac_62;

      temp_var_for_ext_5 = temp_var_for_tac_63;
      computeLdDiv((Addr)&temp_var_for_tac_62, {(Addr)&P, (Addr)&Q},
                   "/home/shijia/Public/testprogram/s_erfl.c_e.c:193:36");
      computeLdAdd(
          (Addr)&temp_var_for_tac_63,
          {(Addr) &(temp_var_for_const_38 = erx), (Addr)&temp_var_for_tac_62},
          "/home/shijia/Public/testprogram/s_erfl.c_e.c:193:32");
      AssignLd({(Addr)&temp_var_for_ext_5}, (Addr)&temp_var_for_tac_63,
               "/home/shijia/Public/testprogram/s_erfl.c_e.c:193:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_5;
    }

    else {
      long double temp_var_for_ext_6;
      long double temp_var_for_tac_64, temp_var_for_tac_65;
      long double temp_var_for_const_39;
      temp_var_for_tac_64 = P / Q;

      temp_var_for_tac_65 = (-(erx)) - temp_var_for_tac_64;

      temp_var_for_ext_6 = temp_var_for_tac_65;
      computeLdDiv((Addr)&temp_var_for_tac_64, {(Addr)&P, (Addr)&Q},
                   "/home/shijia/Public/testprogram/s_erfl.c_e.c:202:37");
      computeLdSub((Addr)&temp_var_for_tac_65,
                   {(Addr) &(temp_var_for_const_39 = (-(erx))),
                    (Addr)&temp_var_for_tac_64},
                   "/home/shijia/Public/testprogram/s_erfl.c_e.c:202:33");
      AssignLd({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_65,
               "/home/shijia/Public/testprogram/s_erfl.c_e.c:202:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
      callExp++; /*identify the function is  add move tmpShadow*/
      return (0.0 - r_f)or_ext_6;
    }
  }
  if (ix >= IC(0x4001d555)) /* 6.6666259765625 */
  {                         /* inf>|x|>=6.666 */
    if ((se & 0x8000) == 0) {
      long double temp_var_for_ext_7;
      long double temp_var_for_tac_66;
      long double temp_var_for_const_40, temp_var_for_const_41;
      temp_var_for_tac_66 = one - tiny;

      temp_var_for_ext_7 = temp_var_for_tac_66;
      computeLdSub((Addr)&temp_var_for_tac_66,
                   {(Addr) &(temp_var_for_const_41 = one),
                    (Addr) &(temp_var_for_const_40 = tiny)},
                   "/home/shijia/Public/testprogram/s_erfl.c_e.c:213:32");
      AssignLd({(Addr)&temp_var_for_ext_7}, (Addr)&temp_var_for_tac_66,
               "/home/shijia/Public/testprogram/s_erfl.c_e.c:213:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_7;
    }

    else {
      long double temp_var_for_ext_8;
      long double temp_var_for_tac_67;
      long double temp_var_for_const_42, temp_var_for_const_43;
      temp_var_for_tac_67 = tiny - one;

      temp_var_for_ext_8 = temp_var_for_tac_67;
      computeLdSub((Addr)&temp_var_for_tac_67,
                   {(Addr) &(temp_var_for_const_43 = tiny),
                    (Addr) &(temp_var_for_const_42 = one)},
                   "/home/shijia/Public/testprogram/s_erfl.c_e.c:222:33");
      AssignLd({(Addr)&temp_var_for_ext_8}, (Addr)&temp_var_for_tac_67,
               "/home/shijia/Public/testprogram/s_erfl.c_e.c:222:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_8;
    }
  }
  long double temp_var_for_ext_9;
  long double temp_var_for_const_44;
  long double temp_var_for_callexp_1;

  temp_var_for_callexp_1 = fabsl(x);
  temp_var_for_ext_9 = temp_var_for_callexp_1;
  AssignLd({(Addr)&temp_var_for_ext_9},
           (Addr) &(temp_var_for_const_44 = temp_var_for_callexp_1),
           "/home/shijia/Public/testprogram/s_erfl.c_e.c:230:22");
  ; // x
  /*(s)(qa)(6)(qa[6])(s)(qa)(5)(qa[5])(s)(qa)(4)(qa[4])(s)(qa)(3)(qa[3])(s)(qa)(2)(qa[2])(s)(qa)(1)(qa[1])(s)(qa)(0)(qa[0])(s)(qa)(6)(qa[6])(s)(qa)(5)(qa[5])(s)(qa)(4)(qa[4])(s)(qa)(3)(qa[3])(s)(qa)(2)(qa[2])(s)(qa)(1)(qa[1])(s)(s)(qa)(6)(qa[6])(s)(qa)(5)(qa[5])(s)(qa)(4)(qa[4])(s)(qa)(3)(qa[3])(s)(qa)(2)(qa[2])(s)(qa)(1)(qa[1])(s)(qa)(6)(qa[6])(s)(qa)(5)(qa[5])(s)(qa)(4)(qa[4])(s)(qa)(3)(qa[3])(s)(qa)(2)(qa[2])(s)(s)(qa)(6)(qa[6])(s)(qa)(5)(qa[5])(s)(qa)(4)(qa[4])(s)(qa)(3)(qa[3])(s)(qa)(2)(qa[2])(s)(qa)(6)(qa[6])(s)(qa)(5)(qa[5])(s)(qa)(4)(qa[4])(s)(qa)(3)(qa[3])(s)(s)(qa)(6)(qa[6])(s)(qa)(5)(qa[5])(s)(qa)(4)(qa[4])(s)(qa)(3)(qa[3])(s)(qa)(6)(qa[6])(s)(qa)(5)(qa[5])(s)(qa)(4)(qa[4])(s)(s)(qa)(6)(qa[6])(s)(qa)(5)(qa[5])(s)(qa)(4)(qa[4])(s)(qa)(6)(qa[6])(s)(qa)(5)(qa[5])(s)(s)(qa)(6)(qa[6])(s)(qa)(5)(qa[5])(s)(qa)(6)(qa[6])(s)(s)(qa)(6)(qa[6])(5)(e)(tem)(5)(e)(6)(e)(r_f)(r_f)(6)(e)(xt_7)(tem)(t_8)(temp)(__ieee754_fabsl(x))*/
  x = temp_var_for_ext_9;
  AssignLd({(Addr)&x}, (Addr)&temp_var_for_ext_9,
           "/home/shijia/Public/testprogram/s_erfl.c_e.c:232:5");
  ;
  long double temp_var_for_tac_68, temp_var_for_tac_69;
  long double temp_var_for_const_45;
  temp_var_for_tac_68 = x * x;

  temp_var_for_tac_69 = one / temp_var_for_tac_68;

  s = temp_var_for_tac_69;
  computeLdMul((Addr)&temp_var_for_tac_68, {(Addr)&x, (Addr)&x},
               "/home/shijia/Public/testprogram/s_erfl.c_e.c:233:16");
  computeLdDiv(
      (Addr)&temp_var_for_tac_69,
      {(Addr) &(temp_var_for_const_45 = one), (Addr)&temp_var_for_tac_68},
      "/home/shijia/Public/testprogram/s_erfl.c_e.c:233:11");
  AssignLd({(Addr)&s}, (Addr)&temp_var_for_tac_69,
           "/home/shijia/Public/testprogram/s_erfl.c_e.c:233:5");
  ;
  if (ix < IC(0x4000b6db)) /* 2.85711669921875 */
  {
    long double temp_var_for_tac_70, temp_var_for_tac_71, temp_var_for_tac_72,
        temp_var_for_tac_73, temp_var_for_tac_74, temp_var_for_tac_75,
        temp_var_for_tac_76, temp_var_for_tac_77, temp_var_for_tac_78,
        temp_var_for_tac_79, temp_var_for_tac_80, temp_var_for_tac_81,
        temp_var_for_tac_82, temp_var_for_tac_83, temp_var_for_tac_84,
        temp_var_for_tac_85;
    long double temp_var_for_const_46, temp_var_for_const_47,
        temp_var_for_const_48, temp_var_for_const_49, temp_var_for_const_50,
        temp_var_for_const_51, temp_var_for_const_52, temp_var_for_const_53,
        temp_var_for_const_54;
    temp_var_for_tac_70 = s * ra[8];

    temp_var_for_tac_71 = ra[7] + temp_var_for_tac_70;

    temp_var_for_tac_72 = s * temp_var_for_tac_71;

    temp_var_for_tac_73 = ra[6] + temp_var_for_tac_72;

    temp_var_for_tac_74 = s * temp_var_for_tac_73;

    temp_var_for_tac_75 = ra[5] + temp_var_for_tac_74;

    temp_var_for_tac_76 = s * temp_var_for_tac_75;

    temp_var_for_tac_77 = ra[4] + temp_var_for_tac_76;

    temp_var_for_tac_78 = s * temp_var_for_tac_77;

    temp_var_for_tac_79 = ra[3] + temp_var_for_tac_78;

    temp_var_for_tac_80 = s * temp_var_for_tac_79;

    temp_var_for_tac_81 = ra[2] + temp_var_for_tac_80;

    temp_var_for_tac_82 = s * temp_var_for_tac_81;

    temp_var_for_tac_83 = ra[1] + temp_var_for_tac_82;

    temp_var_for_tac_84 = s * temp_var_for_tac_83;

    temp_var_for_tac_85 = ra[0] + temp_var_for_tac_84;

    R = temp_var_for_tac_85;
    computeLdMul((Addr)&temp_var_for_tac_70,
                 {(Addr)&s, (Addr) &(temp_var_for_const_46 = ra[8])},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:242:62");
    computeLdAdd(
        (Addr)&temp_var_for_tac_71,
        {(Addr) &(temp_var_for_const_47 = ra[7]), (Addr)&temp_var_for_tac_70},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:242:58");
    computeLdMul((Addr)&temp_var_for_tac_72,
                 {(Addr)&s, (Addr)&temp_var_for_tac_71},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:242:49");
    computeLdAdd(
        (Addr)&temp_var_for_tac_73,
        {(Addr) &(temp_var_for_const_48 = ra[6]), (Addr)&temp_var_for_tac_72},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:242:45");
    computeLdMul((Addr)&temp_var_for_tac_74,
                 {(Addr)&s, (Addr)&temp_var_for_tac_73},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:242:36");
    computeLdAdd(
        (Addr)&temp_var_for_tac_75,
        {(Addr) &(temp_var_for_const_49 = ra[5]), (Addr)&temp_var_for_tac_74},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:241:40");
    computeLdMul((Addr)&temp_var_for_tac_76,
                 {(Addr)&s, (Addr)&temp_var_for_tac_75},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:241:31");
    computeLdAdd(
        (Addr)&temp_var_for_tac_77,
        {(Addr) &(temp_var_for_const_50 = ra[4]), (Addr)&temp_var_for_tac_76},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:240:35");
    computeLdMul((Addr)&temp_var_for_tac_78,
                 {(Addr)&s, (Addr)&temp_var_for_tac_77},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:240:26");
    computeLdAdd(
        (Addr)&temp_var_for_tac_79,
        {(Addr) &(temp_var_for_const_51 = ra[3]), (Addr)&temp_var_for_tac_78},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:239:30");
    computeLdMul((Addr)&temp_var_for_tac_80,
                 {(Addr)&s, (Addr)&temp_var_for_tac_79},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:239:21");
    computeLdAdd(
        (Addr)&temp_var_for_tac_81,
        {(Addr) &(temp_var_for_const_52 = ra[2]), (Addr)&temp_var_for_tac_80},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:238:25");
    computeLdMul((Addr)&temp_var_for_tac_82,
                 {(Addr)&s, (Addr)&temp_var_for_tac_81},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:238:16");
    computeLdAdd(
        (Addr)&temp_var_for_tac_83,
        {(Addr) &(temp_var_for_const_53 = ra[1]), (Addr)&temp_var_for_tac_82},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:237:20");
    computeLdMul((Addr)&temp_var_for_tac_84,
                 {(Addr)&s, (Addr)&temp_var_for_tac_83},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:237:11");
    computeLdAdd(
        (Addr)&temp_var_for_tac_85,
        {(Addr) &(temp_var_for_const_54 = ra[0]), (Addr)&temp_var_for_tac_84},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:236:15");
    AssignLd({(Addr)&R}, (Addr)&temp_var_for_tac_85,
             "/home/shijia/Public/testprogram/s_erfl.c_e.c:236:7");
    ;
    long double temp_var_for_tac_86, temp_var_for_tac_87, temp_var_for_tac_88,
        temp_var_for_tac_89, temp_var_for_tac_90, temp_var_for_tac_91,
        temp_var_for_tac_92, temp_var_for_tac_93, temp_var_for_tac_94,
        temp_var_for_tac_95, temp_var_for_tac_96, temp_var_for_tac_97,
        temp_var_for_tac_98, temp_var_for_tac_99, temp_var_for_tac_100,
        temp_var_for_tac_101, temp_var_for_tac_102;
    long double temp_var_for_const_55, temp_var_for_const_56,
        temp_var_for_const_57, temp_var_for_const_58, temp_var_for_const_59,
        temp_var_for_const_60, temp_var_for_const_61, temp_var_for_const_62,
        temp_var_for_const_63;
    temp_var_for_tac_86 = sa[8] + s;

    temp_var_for_tac_87 = s * temp_var_for_tac_86;

    temp_var_for_tac_88 = sa[7] + temp_var_for_tac_87;

    temp_var_for_tac_89 = s * temp_var_for_tac_88;

    temp_var_for_tac_90 = sa[6] + temp_var_for_tac_89;

    temp_var_for_tac_91 = s * temp_var_for_tac_90;

    temp_var_for_tac_92 = sa[5] + temp_var_for_tac_91;

    temp_var_for_tac_93 = s * temp_var_for_tac_92;

    temp_var_for_tac_94 = sa[4] + temp_var_for_tac_93;

    temp_var_for_tac_95 = s * temp_var_for_tac_94;

    temp_var_for_tac_96 = sa[3] + temp_var_for_tac_95;

    temp_var_for_tac_97 = s * temp_var_for_tac_96;

    temp_var_for_tac_98 = sa[2] + temp_var_for_tac_97;

    temp_var_for_tac_99 = s * temp_var_for_tac_98;

    temp_var_for_tac_100 = sa[1] + temp_var_for_tac_99;

    temp_var_for_tac_101 = s * temp_var_for_tac_100;

    temp_var_for_tac_102 = sa[0] + temp_var_for_tac_101;

    S = temp_var_for_tac_102;
    computeLdAdd((Addr)&temp_var_for_tac_86,
                 {(Addr) &(temp_var_for_const_55 = sa[8]), (Addr)&s},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:250:63");
    computeLdMul((Addr)&temp_var_for_tac_87,
                 {(Addr)&s, (Addr)&temp_var_for_tac_86},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:250:54");
    computeLdAdd(
        (Addr)&temp_var_for_tac_88,
        {(Addr) &(temp_var_for_const_56 = sa[7]), (Addr)&temp_var_for_tac_87},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:250:50");
    computeLdMul((Addr)&temp_var_for_tac_89,
                 {(Addr)&s, (Addr)&temp_var_for_tac_88},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:250:41");
    computeLdAdd(
        (Addr)&temp_var_for_tac_90,
        {(Addr) &(temp_var_for_const_57 = sa[6]), (Addr)&temp_var_for_tac_89},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:249:45");
    computeLdMul((Addr)&temp_var_for_tac_91,
                 {(Addr)&s, (Addr)&temp_var_for_tac_90},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:249:36");
    computeLdAdd(
        (Addr)&temp_var_for_tac_92,
        {(Addr) &(temp_var_for_const_58 = sa[5]), (Addr)&temp_var_for_tac_91},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:248:40");
    computeLdMul((Addr)&temp_var_for_tac_93,
                 {(Addr)&s, (Addr)&temp_var_for_tac_92},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:248:31");
    computeLdAdd(
        (Addr)&temp_var_for_tac_94,
        {(Addr) &(temp_var_for_const_59 = sa[4]), (Addr)&temp_var_for_tac_93},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:247:35");
    computeLdMul((Addr)&temp_var_for_tac_95,
                 {(Addr)&s, (Addr)&temp_var_for_tac_94},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:247:26");
    computeLdAdd(
        (Addr)&temp_var_for_tac_96,
        {(Addr) &(temp_var_for_const_60 = sa[3]), (Addr)&temp_var_for_tac_95},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:246:30");
    computeLdMul((Addr)&temp_var_for_tac_97,
                 {(Addr)&s, (Addr)&temp_var_for_tac_96},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:246:21");
    computeLdAdd(
        (Addr)&temp_var_for_tac_98,
        {(Addr) &(temp_var_for_const_61 = sa[2]), (Addr)&temp_var_for_tac_97},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:245:25");
    computeLdMul((Addr)&temp_var_for_tac_99,
                 {(Addr)&s, (Addr)&temp_var_for_tac_98},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:245:16");
    computeLdAdd(
        (Addr)&temp_var_for_tac_100,
        {(Addr) &(temp_var_for_const_62 = sa[1]), (Addr)&temp_var_for_tac_99},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:244:20");
    computeLdMul((Addr)&temp_var_for_tac_101,
                 {(Addr)&s, (Addr)&temp_var_for_tac_100},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:244:11");
    computeLdAdd(
        (Addr)&temp_var_for_tac_102,
        {(Addr) &(temp_var_for_const_63 = sa[0]), (Addr)&temp_var_for_tac_101},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:243:15");
    AssignLd({(Addr)&S}, (Addr)&temp_var_for_tac_102,
             "/home/shijia/Public/testprogram/s_erfl.c_e.c:243:7");
    ;
  } else { /* |x| >= 1/0.35 */
    long double temp_var_for_tac_103, temp_var_for_tac_104,
        temp_var_for_tac_105, temp_var_for_tac_106, temp_var_for_tac_107,
        temp_var_for_tac_108, temp_var_for_tac_109, temp_var_for_tac_110,
        temp_var_for_tac_111, temp_var_for_tac_112, temp_var_for_tac_113,
        temp_var_for_tac_114, temp_var_for_tac_115, temp_var_for_tac_116;
    long double temp_var_for_const_64, temp_var_for_const_65,
        temp_var_for_const_66, temp_var_for_const_67, temp_var_for_const_68,
        temp_var_for_const_69, temp_var_for_const_70, temp_var_for_const_71;
    temp_var_for_tac_103 = s * rb[7];

    temp_var_for_tac_104 = rb[6] + temp_var_for_tac_103;

    temp_var_for_tac_105 = s * temp_var_for_tac_104;

    temp_var_for_tac_106 = rb[5] + temp_var_for_tac_105;

    temp_var_for_tac_107 = s * temp_var_for_tac_106;

    temp_var_for_tac_108 = rb[4] + temp_var_for_tac_107;

    temp_var_for_tac_109 = s * temp_var_for_tac_108;

    temp_var_for_tac_110 = rb[3] + temp_var_for_tac_109;

    temp_var_for_tac_111 = s * temp_var_for_tac_110;

    temp_var_for_tac_112 = rb[2] + temp_var_for_tac_111;

    temp_var_for_tac_113 = s * temp_var_for_tac_112;

    temp_var_for_tac_114 = rb[1] + temp_var_for_tac_113;

    temp_var_for_tac_115 = s * temp_var_for_tac_114;

    temp_var_for_tac_116 = rb[0] + temp_var_for_tac_115;

    R = temp_var_for_tac_116;
    computeLdMul((Addr)&temp_var_for_tac_103,
                 {(Addr)&s, (Addr) &(temp_var_for_const_64 = rb[7])},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:256:65");
    computeLdAdd(
        (Addr)&temp_var_for_tac_104,
        {(Addr) &(temp_var_for_const_65 = rb[6]), (Addr)&temp_var_for_tac_103},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:256:61");
    computeLdMul((Addr)&temp_var_for_tac_105,
                 {(Addr)&s, (Addr)&temp_var_for_tac_104},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:256:52");
    computeLdAdd(
        (Addr)&temp_var_for_tac_106,
        {(Addr) &(temp_var_for_const_66 = rb[5]), (Addr)&temp_var_for_tac_105},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:256:48");
    computeLdMul((Addr)&temp_var_for_tac_107,
                 {(Addr)&s, (Addr)&temp_var_for_tac_106},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:256:39");
    computeLdAdd(
        (Addr)&temp_var_for_tac_108,
        {(Addr) &(temp_var_for_const_67 = rb[4]), (Addr)&temp_var_for_tac_107},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:256:35");
    computeLdMul((Addr)&temp_var_for_tac_109,
                 {(Addr)&s, (Addr)&temp_var_for_tac_108},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:256:26");
    computeLdAdd(
        (Addr)&temp_var_for_tac_110,
        {(Addr) &(temp_var_for_const_68 = rb[3]), (Addr)&temp_var_for_tac_109},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:255:30");
    computeLdMul((Addr)&temp_var_for_tac_111,
                 {(Addr)&s, (Addr)&temp_var_for_tac_110},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:255:21");
    computeLdAdd(
        (Addr)&temp_var_for_tac_112,
        {(Addr) &(temp_var_for_const_69 = rb[2]), (Addr)&temp_var_for_tac_111},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:254:25");
    computeLdMul((Addr)&temp_var_for_tac_113,
                 {(Addr)&s, (Addr)&temp_var_for_tac_112},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:254:16");
    computeLdAdd(
        (Addr)&temp_var_for_tac_114,
        {(Addr) &(temp_var_for_const_70 = rb[1]), (Addr)&temp_var_for_tac_113},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:253:20");
    computeLdMul((Addr)&temp_var_for_tac_115,
                 {(Addr)&s, (Addr)&temp_var_for_tac_114},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:253:11");
    computeLdAdd(
        (Addr)&temp_var_for_tac_116,
        {(Addr) &(temp_var_for_const_71 = rb[0]), (Addr)&temp_var_for_tac_115},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:252:15");
    AssignLd({(Addr)&R}, (Addr)&temp_var_for_tac_116,
             "/home/shijia/Public/testprogram/s_erfl.c_e.c:252:7");
    ;
    long double temp_var_for_tac_117, temp_var_for_tac_118,
        temp_var_for_tac_119, temp_var_for_tac_120, temp_var_for_tac_121,
        temp_var_for_tac_122, temp_var_for_tac_123, temp_var_for_tac_124,
        temp_var_for_tac_125, temp_var_for_tac_126, temp_var_for_tac_127,
        temp_var_for_tac_128, temp_var_for_tac_129;
    long double temp_var_for_const_72, temp_var_for_const_73,
        temp_var_for_const_74, temp_var_for_const_75, temp_var_for_const_76,
        temp_var_for_const_77, temp_var_for_const_78;
    temp_var_for_tac_117 = sb[6] + s;

    temp_var_for_tac_118 = s * temp_var_for_tac_117;

    temp_var_for_tac_119 = sb[5] + temp_var_for_tac_118;

    temp_var_for_tac_120 = s * temp_var_for_tac_119;

    temp_var_for_tac_121 = sb[4] + temp_var_for_tac_120;

    temp_var_for_tac_122 = s * temp_var_for_tac_121;

    temp_var_for_tac_123 = sb[3] + temp_var_for_tac_122;

    temp_var_for_tac_124 = s * temp_var_for_tac_123;

    temp_var_for_tac_125 = sb[2] + temp_var_for_tac_124;

    temp_var_for_tac_126 = s * temp_var_for_tac_125;

    temp_var_for_tac_127 = sb[1] + temp_var_for_tac_126;

    temp_var_for_tac_128 = s * temp_var_for_tac_127;

    temp_var_for_tac_129 = sb[0] + temp_var_for_tac_128;

    S = temp_var_for_tac_129;
    computeLdAdd((Addr)&temp_var_for_tac_117,
                 {(Addr) &(temp_var_for_const_72 = sb[6]), (Addr)&s},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:260:69");
    computeLdMul((Addr)&temp_var_for_tac_118,
                 {(Addr)&s, (Addr)&temp_var_for_tac_117},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:260:60");
    computeLdAdd(
        (Addr)&temp_var_for_tac_119,
        {(Addr) &(temp_var_for_const_73 = sb[5]), (Addr)&temp_var_for_tac_118},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:260:56");
    computeLdMul((Addr)&temp_var_for_tac_120,
                 {(Addr)&s, (Addr)&temp_var_for_tac_119},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:260:47");
    computeLdAdd(
        (Addr)&temp_var_for_tac_121,
        {(Addr) &(temp_var_for_const_74 = sb[4]), (Addr)&temp_var_for_tac_120},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:260:43");
    computeLdMul((Addr)&temp_var_for_tac_122,
                 {(Addr)&s, (Addr)&temp_var_for_tac_121},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:260:34");
    computeLdAdd(
        (Addr)&temp_var_for_tac_123,
        {(Addr) &(temp_var_for_const_75 = sb[3]), (Addr)&temp_var_for_tac_122},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:260:30");
    computeLdMul((Addr)&temp_var_for_tac_124,
                 {(Addr)&s, (Addr)&temp_var_for_tac_123},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:260:21");
    computeLdAdd(
        (Addr)&temp_var_for_tac_125,
        {(Addr) &(temp_var_for_const_76 = sb[2]), (Addr)&temp_var_for_tac_124},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:259:25");
    computeLdMul((Addr)&temp_var_for_tac_126,
                 {(Addr)&s, (Addr)&temp_var_for_tac_125},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:259:16");
    computeLdAdd(
        (Addr)&temp_var_for_tac_127,
        {(Addr) &(temp_var_for_const_77 = sb[1]), (Addr)&temp_var_for_tac_126},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:258:20");
    computeLdMul((Addr)&temp_var_for_tac_128,
                 {(Addr)&s, (Addr)&temp_var_for_tac_127},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:258:11");
    computeLdAdd(
        (Addr)&temp_var_for_tac_129,
        {(Addr) &(temp_var_for_const_78 = sb[0]), (Addr)&temp_var_for_tac_128},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:257:15");
    AssignLd({(Addr)&S}, (Addr)&temp_var_for_tac_129,
             "/home/shijia/Public/testprogram/s_erfl.c_e.c:257:7");
    ;
  }
  z = x;
  AssignLd({(Addr)&z}, (Addr)&x,
           "/home/shijia/Public/testprogram/s_erfl.c_e.c:262:5");
  ;
  long double temp_var_for_const_79;
  ew_u.value = z;
  AssignLd({(Addr) &(temp_var_for_const_79 = ew_u.value)}, (Addr)&z,
           "/home/shijia/Public/testprogram/s_erfl.c_e.c:263:3 "
           "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
  ;
  i1 = 0;
  long double temp_var_for_ext_10;
  temp_var_for_ext_10;
  long double temp_var_for_tac_130, temp_var_for_tac_131, temp_var_for_tac_132,
      temp_var_for_tac_133, temp_var_for_tac_134, temp_var_for_tac_135,
      temp_var_for_tac_136, temp_var_for_tac_137, temp_var_for_tac_138;
  long double temp_var_for_const_80, temp_var_for_const_81,
      temp_var_for_const_82, temp_var_for_const_83;
  long double temp_var_for_callexp_2;

  long double temp_var_for_callexp_3;

  temp_var_for_tac_130 = 0.0 - z;

  temp_var_for_tac_131 = temp_var_for_tac_130 * z;

  temp_var_for_tac_132 = temp_var_for_tac_131 - 0.5625;

  temp_var_for_callexp_2 = __ieee754_expl(temp_var_for_tac_132);
  temp_var_for_tac_133 = z - x;

  temp_var_for_tac_134 = z + x;

  temp_var_for_tac_135 = temp_var_for_tac_133 * temp_var_for_tac_134;

  temp_var_for_tac_136 = R / S;

  temp_var_for_tac_137 = temp_var_for_tac_135 + temp_var_for_tac_136;

  temp_var_for_callexp_3 = __ieee754_expl(temp_var_for_tac_137);
  temp_var_for_tac_138 = temp_var_for_callexp_2 * temp_var_for_callexp_3;

  r = temp_var_for_tac_138;
  computeLdSub((Addr)&temp_var_for_tac_130,
               {(Addr) &(temp_var_for_const_80 = 0.0), (Addr)&z},
               "/home/shijia/Public/testprogram/s_erfl.c_e.c:267:27");
  computeLdMul((Addr)&temp_var_for_tac_131,
               {(Addr)&temp_var_for_tac_130, (Addr)&z},
               "/home/shijia/Public/testprogram/s_erfl.c_e.c:267:32");
  computeLdSub(
      (Addr)&temp_var_for_tac_132,
      {(Addr)&temp_var_for_tac_131, (Addr) &(temp_var_for_const_81 = 0.5625)},
      "/home/shijia/Public/testprogram/s_erfl.c_e.c:267:36");
  computeLdSub((Addr)&temp_var_for_tac_133, {(Addr)&z, (Addr)&x},
               "/home/shijia/Public/testprogram/s_erfl.c_e.c:268:25");
  computeLdAdd((Addr)&temp_var_for_tac_134, {(Addr)&z, (Addr)&x},
               "/home/shijia/Public/testprogram/s_erfl.c_e.c:268:35");
  computeLdMul((Addr)&temp_var_for_tac_135,
               {(Addr)&temp_var_for_tac_133, (Addr)&temp_var_for_tac_134},
               "/home/shijia/Public/testprogram/s_erfl.c_e.c:268:30");
  computeLdDiv((Addr)&temp_var_for_tac_136, {(Addr)&R, (Addr)&S},
               "/home/shijia/Public/testprogram/s_erfl.c_e.c:268:44");
  computeLdAdd((Addr)&temp_var_for_tac_137,
               {(Addr)&temp_var_for_tac_135, (Addr)&temp_var_for_tac_136},
               "/home/shijia/Public/testprogram/s_erfl.c_e.c:268:40");
  computeLdMul((Addr)&temp_var_for_tac_138,
               {(Addr) &(temp_var_for_const_83 = temp_var_for_callexp_2),
                (Addr) &(temp_var_for_const_82 = temp_var_for_callexp_3)},
               "/home/shijia/Public/testprogram/s_erfl.c_e.c:267:46");
  AssignLd({(Addr)&r}, (Addr)&temp_var_for_tac_138,
           "/home/shijia/Public/testprogram/s_erfl.c_e.c:267:5");
  ;
  if ((se & 0x8000) == 0) {
    long double temp_var_for_ext_11;
    long double temp_var_for_tac_139, temp_var_for_tac_140;
    long double temp_var_for_const_84;
    temp_var_for_tac_139 = r / x;

    temp_var_for_tac_140 = one - temp_var_for_tac_139;

    temp_var_for_ext_11 = temp_var_for_tac_140;
    computeLdDiv((Addr)&temp_var_for_tac_139, {(Addr)&r, (Addr)&x},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:271:35");
    computeLdSub(
        (Addr)&temp_var_for_tac_140,
        {(Addr) &(temp_var_for_const_84 = one), (Addr)&temp_var_for_tac_139},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:271:31");
    AssignLd({(Addr)&temp_var_for_ext_11}, (Addr)&temp_var_for_tac_140,
             "/home/shijia/Public/testprogram/s_erfl.c_e.c:271:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_11", (Addr)&temp_var_for_ext_11));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_11;
  }

  else {
    long double temp_var_for_ext_12;
    long double temp_var_for_tac_141, temp_var_for_tac_142;
    long double temp_var_for_const_85;
    temp_var_for_tac_141 = r / x;

    temp_var_for_tac_142 = temp_var_for_tac_141 - one;

    temp_var_for_ext_12 = temp_var_for_tac_142;
    computeLdDiv((Addr)&temp_var_for_tac_141, {(Addr)&r, (Addr)&x},
                 "/home/shijia/Public/testprogram/s_erfl.c_e.c:280:29");
    computeLdSub(
        (Addr)&temp_var_for_tac_142,
        {(Addr)&temp_var_for_tac_141, (Addr) &(temp_var_for_const_85 = one)},
        "/home/shijia/Public/testprogram/s_erfl.c_e.c:280:33");
    AssignLd({(Addr)&temp_var_for_ext_12}, (Addr)&temp_var_for_tac_142,
             "/home/shijia/Public/testprogram/s_erfl.c_e.c:280:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_12", (Addr)&temp_var_for_ext_12));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_12;
  }
}

__typeof(__erfl) erfl __attribute__((weak, alias("__erfl")));

#endif
