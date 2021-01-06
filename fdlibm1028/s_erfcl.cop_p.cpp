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

long double __erfcl(long double x) {
  int32_t hx, ix;
  long double R, S, P, Q, s, y, z, r;
  uint32_t se, i0, i1;

  static const long double tiny = 1e-4931L;
  static const long double half = 0.5L;
  static const long double one = 1.0L;
  static const long double two = 2.0L;
  /* c = (float)0.84506291151 */
  static const long double erx = 0.845062911510467529296875L;

#include "t_erfl.h"

  /* erfc(1/x) = x exp (-1/x^2 - 0.5625 + rc(x^2)/sc(x^2))
     1/107 <= 1/x <= 1/6.6666259765625
     Peak relative error 1.1e-21  */
  static const long double rc[] = {
      (long double temp_var_for_tac_0;
  long double temp_var_for_const_0, temp_var_for_const_1;
  temp_var_for_tac_0 = 0.0 - 8.299617545269701963973537248996670806850E-5L;

),
      (long double temp_var_for_tac_1;long double temp_var_for_const_2,temp_var_for_const_3;temp_var_for_tac_1 = 0.0 - 6.243845685115818513578933902532056244108E-3L;

),
      (long double temp_var_for_tac_2;long double temp_var_for_const_4,temp_var_for_const_5;temp_var_for_tac_2 = 0.0 - 1.141667210620380223113693474478394397230E-1L;

),
      (long double temp_var_for_tac_3;long double temp_var_for_const_6,temp_var_for_const_7;temp_var_for_tac_3 = 0.0 - 7.521343797212024245375240432734425789409E-1L;

),
      (long double temp_var_for_tac_4;long double temp_var_for_const_8,temp_var_for_const_9;temp_var_for_tac_4 = 0.0 - 1.765321928311155824664963633786967602934E0L;

),
      (long double temp_var_for_tac_5;long double temp_var_for_const_10,temp_var_for_const_11;temp_var_for_tac_5 = 0.0 - 1.029403473103215800456761180695263439188E0L;

)
};
static const long double sc[] = {
    8.413244363014929493035952542677768808601E-3L,
    2.065114333816877479753334599639158060979E-1L,
    1.639064941530797583766364412782135680148E0L,
    4.936788463787115555582319302981666347450E0L,
    5.005177727208955487404729933261347679090E0L
    /* 1.000000000000000000000000000000000000000E0 */
};

long double temp_var_for_const_12;
ew_u.value = x;
computeLdSub((Addr)&temp_var_for_tac_0,
             {(Addr) &(temp_var_for_const_1 = 0.0),
              (Addr) &(temp_var_for_const_0 =
                           8.299617545269701963973537248996670806850E-5L)},
             "/home/shijia/Public/testprogram/s_erfcl.c_e.c:130:12");
computeLdSub((Addr)&temp_var_for_tac_1,
             {(Addr) &(temp_var_for_const_3 = 0.0),
              (Addr) &(temp_var_for_const_2 =
                           6.243845685115818513578933902532056244108E-3L)},
             "/home/shijia/Public/testprogram/s_erfcl.c_e.c:131:12");
computeLdSub((Addr)&temp_var_for_tac_2,
             {(Addr) &(temp_var_for_const_5 = 0.0),
              (Addr) &(temp_var_for_const_4 =
                           1.141667210620380223113693474478394397230E-1L)},
             "/home/shijia/Public/testprogram/s_erfcl.c_e.c:132:12");
computeLdSub((Addr)&temp_var_for_tac_3,
             {(Addr) &(temp_var_for_const_7 = 0.0),
              (Addr) &(temp_var_for_const_6 =
                           7.521343797212024245375240432734425789409E-1L)},
             "/home/shijia/Public/testprogram/s_erfcl.c_e.c:133:12");
computeLdSub((Addr)&temp_var_for_tac_4,
             {(Addr) &(temp_var_for_const_9 = 0.0),
              (Addr) &(temp_var_for_const_8 =
                           1.765321928311155824664963633786967602934E0L)},
             "/home/shijia/Public/testprogram/s_erfcl.c_e.c:134:12");
computeLdSub((Addr)&temp_var_for_tac_5,
             {(Addr) &(temp_var_for_const_11 = 0.0),
              (Addr) &(temp_var_for_const_10 =
                           1.029403473103215800456761180695263439188E0L)},
             "/home/shijia/Public/testprogram/s_erfcl.c_e.c:135:12");
AssignLd({(Addr) &(temp_var_for_const_12 = ew_u.value)}, (Addr)&x,
         "/home/shijia/Public/testprogram/s_erfcl.c_e.c:145:3 "
         "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
;
ix = se & 0x7fff;
if (ix >= 0x7fff) { /* erfc(nan)=nan */
  /* erfc(+-inf)=0,2 */
  long double temp_var_for_ext_0;
  long double temp_var_for_tac_6, temp_var_for_tac_7, temp_var_for_tac_8,
      temp_var_for_tac_9, temp_var_for_tac_10;
  long double temp_var_for_const_13, temp_var_for_const_14,
      temp_var_for_const_15, temp_var_for_const_16, temp_var_for_const_17,
      temp_var_for_const_18;
  temp_var_for_tac_6 = se & 0xffff;

  temp_var_for_tac_7 = temp_var_for_tac_6 >> 15;

  temp_var_for_tac_8 = temp_var_for_tac_7 << 1;

  temp_var_for_tac_9 = one / x;

  temp_var_for_tac_10 = ((long double)temp_var_for_tac_8) + temp_var_for_tac_9;

  temp_var_for_ext_0 = temp_var_for_tac_10;
  compute((Addr)&temp_var_for_tac_6, {(Addr) &(temp_var_for_const_14 = se),
                                      (Addr) &(temp_var_for_const_13 = 0xffff)},
          "/home/shijia/Public/testprogram/s_erfcl.c_e.c:150:45");
  compute((Addr)&temp_var_for_tac_7,
          {(Addr)&temp_var_for_tac_6, (Addr) &(temp_var_for_const_15 = 15)},
          "/home/shijia/Public/testprogram/s_erfcl.c_e.c:150:55");
  compute((Addr)&temp_var_for_tac_8,
          {(Addr)&temp_var_for_tac_7, (Addr) &(temp_var_for_const_16 = 1)},
          "/home/shijia/Public/testprogram/s_erfcl.c_e.c:150:62");
  computeLdDiv((Addr)&temp_var_for_tac_9,
               {(Addr) &(temp_var_for_const_17 = one), (Addr)&x},
               "/home/shijia/Public/testprogram/s_erfcl.c_e.c:150:74");
  computeLdAdd(
      (Addr)&temp_var_for_tac_10,
      {(Addr) &(temp_var_for_const_18 = ((long double)temp_var_for_tac_8)),
       (Addr)&temp_var_for_tac_9},
      "/home/shijia/Public/testprogram/s_erfcl.c_e.c:150:68");
  AssignLd({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_10,
           "/home/shijia/Public/testprogram/s_erfcl.c_e.c:150:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

ix = (ix << 16) | (i0 >> 16);
if (ix < IC(0x3ffed800)) /* |x|<0.84375 */
{
  if (ix < IC(0x3fbe0000)) /* |x|<2**-65 */
  {
    long double temp_var_for_ext_1;
    temp_var_for_ext_1 = one - x;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }

  z = long double temp_var_for_tac_11;
  temp_var_for_tac_11 = x * x;

  ;
  long double temp_var_for_tac_12, temp_var_for_tac_13, temp_var_for_tac_14,
      temp_var_for_tac_15, temp_var_for_tac_16, temp_var_for_tac_17,
      temp_var_for_tac_18, temp_var_for_tac_19, temp_var_for_tac_20,
      temp_var_for_tac_21;
  long double temp_var_for_const_19, temp_var_for_const_20,
      temp_var_for_const_21, temp_var_for_const_22, temp_var_for_const_23,
      temp_var_for_const_24;
  temp_var_for_tac_12 = z * pp[5];

  temp_var_for_tac_13 = pp[4] + temp_var_for_tac_12;

  temp_var_for_tac_14 = z * temp_var_for_tac_13;

  temp_var_for_tac_15 = pp[3] + temp_var_for_tac_14;

  temp_var_for_tac_16 = z * temp_var_for_tac_15;

  temp_var_for_tac_17 = pp[2] + temp_var_for_tac_16;

  temp_var_for_tac_18 = z * temp_var_for_tac_17;

  temp_var_for_tac_19 = pp[1] + temp_var_for_tac_18;

  temp_var_for_tac_20 = z * temp_var_for_tac_19;

  temp_var_for_tac_21 = pp[0] + temp_var_for_tac_20;

  r = temp_var_for_tac_21;
  computeLdMul((Addr)&temp_var_for_tac_11, {(Addr)&x, (Addr)&x},
               "/home/shijia/Public/testprogram/s_erfcl.c_e.c:169:11");
  computeLdMul((Addr)&temp_var_for_tac_12,
               {(Addr)&z, (Addr) &(temp_var_for_const_19 = pp[5])},
               "/home/shijia/Public/testprogram/s_erfcl.c_e.c:171:63");
  computeLdAdd(
      (Addr)&temp_var_for_tac_13,
      {(Addr) &(temp_var_for_const_20 = pp[4]), (Addr)&temp_var_for_tac_12},
      "/home/shijia/Public/testprogram/s_erfcl.c_e.c:171:59");
  computeLdMul((Addr)&temp_var_for_tac_14,
               {(Addr)&z, (Addr)&temp_var_for_tac_13},
               "/home/shijia/Public/testprogram/s_erfcl.c_e.c:171:50");
  computeLdAdd(
      (Addr)&temp_var_for_tac_15,
      {(Addr) &(temp_var_for_const_21 = pp[3]), (Addr)&temp_var_for_tac_14},
      "/home/shijia/Public/testprogram/s_erfcl.c_e.c:171:46");
  computeLdMul((Addr)&temp_var_for_tac_16,
               {(Addr)&z, (Addr)&temp_var_for_tac_15},
               "/home/shijia/Public/testprogram/s_erfcl.c_e.c:171:37");
  computeLdAdd(
      (Addr)&temp_var_for_tac_17,
      {(Addr) &(temp_var_for_const_22 = pp[2]), (Addr)&temp_var_for_tac_16},
      "/home/shijia/Public/testprogram/s_erfcl.c_e.c:171:33");
  computeLdMul((Addr)&temp_var_for_tac_18,
               {(Addr)&z, (Addr)&temp_var_for_tac_17},
               "/home/shijia/Public/testprogram/s_erfcl.c_e.c:171:24");
  computeLdAdd(
      (Addr)&temp_var_for_tac_19,
      {(Addr) &(temp_var_for_const_23 = pp[1]), (Addr)&temp_var_for_tac_18},
      "/home/shijia/Public/testprogram/s_erfcl.c_e.c:171:20");
  computeLdMul((Addr)&temp_var_for_tac_20,
               {(Addr)&z, (Addr)&temp_var_for_tac_19},
               "/home/shijia/Public/testprogram/s_erfcl.c_e.c:171:11");
  computeLdAdd(
      (Addr)&temp_var_for_tac_21,
      {(Addr) &(temp_var_for_const_24 = pp[0]), (Addr)&temp_var_for_tac_20},
      "/home/shijia/Public/testprogram/s_erfcl.c_e.c:170:15");
  AssignLd({(Addr)&r}, (Addr)&temp_var_for_tac_21,
           "/home/shijia/Public/testprogram/s_erfcl.c_e.c:170:7");
  ;
  long double temp_var_for_tac_22, temp_var_for_tac_23, temp_var_for_tac_24,
      temp_var_for_tac_25, temp_var_for_tac_26, temp_var_for_tac_27,
      temp_var_for_tac_28, temp_var_for_tac_29, temp_var_for_tac_30,
      temp_var_for_tac_31, temp_var_for_tac_32;
  long double temp_var_for_const_25, temp_var_for_const_26,
      temp_var_for_const_27, temp_var_for_const_28, temp_var_for_const_29,
      temp_var_for_const_30;
  temp_var_for_tac_22 = qq[5] + z;

  temp_var_for_tac_23 = z * temp_var_for_tac_22;

  temp_var_for_tac_24 = qq[4] + temp_var_for_tac_23;

  temp_var_for_tac_25 = z * temp_var_for_tac_24;

  temp_var_for_tac_26 = qq[3] + temp_var_for_tac_25;

  temp_var_for_tac_27 = z * temp_var_for_tac_26;

  temp_var_for_tac_28 = qq[2] + temp_var_for_tac_27;

  temp_var_for_tac_29 = z * temp_var_for_tac_28;

  temp_var_for_tac_30 = qq[1] + temp_var_for_tac_29;

  temp_var_for_tac_31 = z * temp_var_for_tac_30;

  temp_var_for_tac_32 = qq[0] + temp_var_for_tac_31;

  s = temp_var_for_tac_32;
  computeLdAdd((Addr)&temp_var_for_tac_22,
               {(Addr) &(temp_var_for_const_25 = qq[5]), (Addr)&z},
               "/home/shijia/Public/testprogram/s_erfcl.c_e.c:173:72");
  computeLdMul((Addr)&temp_var_for_tac_23,
               {(Addr)&z, (Addr)&temp_var_for_tac_22},
               "/home/shijia/Public/testprogram/s_erfcl.c_e.c:173:63");
  computeLdAdd(
      (Addr)&temp_var_for_tac_24,
      {(Addr) &(temp_var_for_const_26 = qq[4]), (Addr)&temp_var_for_tac_23},
      "/home/shijia/Public/testprogram/s_erfcl.c_e.c:173:59");
  computeLdMul((Addr)&temp_var_for_tac_25,
               {(Addr)&z, (Addr)&temp_var_for_tac_24},
               "/home/shijia/Public/testprogram/s_erfcl.c_e.c:173:50");
  computeLdAdd(
      (Addr)&temp_var_for_tac_26,
      {(Addr) &(temp_var_for_const_27 = qq[3]), (Addr)&temp_var_for_tac_25},
      "/home/shijia/Public/testprogram/s_erfcl.c_e.c:173:46");
  computeLdMul((Addr)&temp_var_for_tac_27,
               {(Addr)&z, (Addr)&temp_var_for_tac_26},
               "/home/shijia/Public/testprogram/s_erfcl.c_e.c:173:37");
  computeLdAdd(
      (Addr)&temp_var_for_tac_28,
      {(Addr) &(temp_var_for_const_28 = qq[2]), (Addr)&temp_var_for_tac_27},
      "/home/shijia/Public/testprogram/s_erfcl.c_e.c:173:33");
  computeLdMul((Addr)&temp_var_for_tac_29,
               {(Addr)&z, (Addr)&temp_var_for_tac_28},
               "/home/shijia/Public/testprogram/s_erfcl.c_e.c:173:24");
  computeLdAdd(
      (Addr)&temp_var_for_tac_30,
      {(Addr) &(temp_var_for_const_29 = qq[1]), (Addr)&temp_var_for_tac_29},
      "/home/shijia/Public/testprogram/s_erfcl.c_e.c:173:20");
  computeLdMul((Addr)&temp_var_for_tac_31,
               {(Addr)&z, (Addr)&temp_var_for_tac_30},
               "/home/shijia/Public/testprogram/s_erfcl.c_e.c:173:11");
  computeLdAdd(
      (Addr)&temp_var_for_tac_32,
      {(Addr) &(temp_var_for_const_30 = qq[0]), (Addr)&temp_var_for_tac_31},
      "/home/shijia/Public/testprogram/s_erfcl.c_e.c:172:15");
  AssignLd({(Addr)&s}, (Addr)&temp_var_for_tac_32,
           "/home/shijia/Public/testprogram/s_erfcl.c_e.c:172:7");
  ;
  long double temp_var_for_tac_33;
  temp_var_for_tac_33 = r / s;

  y = temp_var_for_tac_33;
  computeLdDiv((Addr)&temp_var_for_tac_33, {(Addr)&r, (Addr)&s},
               "/home/shijia/Public/testprogram/s_erfcl.c_e.c:174:11");
  AssignLd({(Addr)&y}, (Addr)&temp_var_for_tac_33,
           "/home/shijia/Public/testprogram/s_erfcl.c_e.c:174:7");
  ;
  if (ix < IC(0x3ffd8000)) /* x<1/4 */
  {
    long double temp_var_for_ext_2;
    long double temp_var_for_tac_34, temp_var_for_tac_35, temp_var_for_tac_36;
    long double temp_var_for_const_31;
    temp_var_for_tac_34 = x * y;

    temp_var_for_tac_35 = x + temp_var_for_tac_34;

    temp_var_for_tac_36 = one - temp_var_for_tac_35;

    temp_var_for_ext_2 = temp_var_for_tac_36;
    computeLdMul((Addr)&temp_var_for_tac_34, {(Addr)&x, (Addr)&y},
                 "/home/shijia/Public/testprogram/s_erfcl.c_e.c:178:41");
    computeLdAdd((Addr)&temp_var_for_tac_35,
                 {(Addr)&x, (Addr)&temp_var_for_tac_34},
                 "/home/shijia/Public/testprogram/s_erfcl.c_e.c:178:37");
    computeLdSub(
        (Addr)&temp_var_for_tac_36,
        {(Addr) &(temp_var_for_const_31 = one), (Addr)&temp_var_for_tac_35},
        "/home/shijia/Public/testprogram/s_erfcl.c_e.c:178:32");
    AssignLd({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_36,
             "/home/shijia/Public/testprogram/s_erfcl.c_e.c:178:26");
    ;
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  } else {
    long double temp_var_for_ext_3;
    long double temp_var_for_tac_37;
    temp_var_for_tac_37 = x * y;

    temp_var_for_ext_3 = temp_var_for_tac_37;
    computeLdMul((Addr)&temp_var_for_tac_37, {(Addr)&x, (Addr)&y},
                 "/home/shijia/Public/testprogram/s_erfcl.c_e.c:185:30");
    AssignLd({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_37,
             "/home/shijia/Public/testprogram/s_erfcl.c_e.c:185:26");
    ; // r
    /*(s)(r)(_)(_)(_)(tem)(_)(_)(_)(_)(_)(y)(x)*/
    r = temp_var_for_ext_3;
    AssignLd({(Addr)&r}, (Addr)&temp_var_for_ext_3,
             "/home/shijia/Public/testprogram/s_erfcl.c_e.c:187:9");
    ;
    long double temp_var_for_tac_38;
    long double temp_var_for_const_32;
    temp_var_for_tac_38 = x - half;

    r += temp_var_for_tac_38;
    ;
    long double temp_var_for_ext_4;
    long double temp_var_for_tac_40;
    long double temp_var_for_const_33;
    temp_var_for_tac_40 = half - r;

    temp_var_for_ext_4 = temp_var_for_tac_40;
    computeLdSub((Addr)&temp_var_for_tac_38,
                 {(Addr)&x, (Addr) &(temp_var_for_const_32 = half)},
                 "/home/shijia/Public/testprogram/s_erfcl.c_e.c:188:15");
    computeLdSub((Addr)&temp_var_for_tac_40,
                 {(Addr) &(temp_var_for_const_33 = half), (Addr)&r},
                 "/home/shijia/Public/testprogram/s_erfcl.c_e.c:190:33");
    AssignLd({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_40,
             "/home/shijia/Public/testprogram/s_erfcl.c_e.c:190:26");
    ;
    callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_4;
  }
}
if (ix < IC(0x3fffa000)) /* 1.25 */
{                        /* 0.84375 <= |x| < 1.25 */
  long double temp_var_for_tac_41;
  long double temp_var_for_const_34, temp_var_for_const_35;
  long double temp_var_for_callexp_0;

  temp_var_for_callexp_0 = fabsl(x);
  temp_var_for_tac_41 = temp_var_for_callexp_0 - one;

  s = temp_var_for_tac_41;
  computeLdSub((Addr)&temp_var_for_tac_41,
               {(Addr) &(temp_var_for_const_35 = temp_var_for_callexp_0),
                (Addr) &(temp_var_for_const_34 = one)},
               "/home/shijia/Public/testprogram/s_erfcl.c_e.c:199:28");
  AssignLd({(Addr)&s}, (Addr)&temp_var_for_tac_41,
           "/home/shijia/Public/testprogram/s_erfcl.c_e.c:199:7");
  ;
  long double temp_var_for_tac_42, temp_var_for_tac_43, temp_var_for_tac_44,
      temp_var_for_tac_45, temp_var_for_tac_46, temp_var_for_tac_47,
      temp_var_for_tac_48, temp_var_for_tac_49, temp_var_for_tac_50,
      temp_var_for_tac_51, temp_var_for_tac_52, temp_var_for_tac_53,
      temp_var_for_tac_54, temp_var_for_tac_55;
  long double temp_var_for_const_36, temp_var_for_const_37,
      temp_var_for_const_38, temp_var_for_const_39, temp_var_for_const_40,
      temp_var_for_const_41, temp_var_for_const_42, temp_var_for_const_43;
  temp_var_for_tac_42 = s * pa[7];

  temp_var_for_tac_43 = pa[6] + temp_var_for_tac_42;

  temp_var_for_tac_44 = s * temp_var_for_tac_43;

  temp_var_for_tac_45 = pa[5] + temp_var_for_tac_44;

  temp_var_for_tac_46 = s * temp_var_for_tac_45;

  temp_var_for_tac_47 = pa[4] + temp_var_for_tac_46;

  temp_var_for_tac_48 = s * temp_var_for_tac_47;

  temp_var_for_tac_49 = pa[3] + temp_var_for_tac_48;

  temp_var_for_tac_50 = s * temp_var_for_tac_49;

  temp_var_for_tac_51 = pa[2] + temp_var_for_tac_50;

  temp_var_for_tac_52 = s * temp_var_for_tac_51;

  temp_var_for_tac_53 = pa[1] + temp_var_for_tac_52;

  temp_var_for_tac_54 = s * temp_var_for_tac_53;

  temp_var_for_tac_55 = pa[0] + temp_var_for_tac_54;

  P = temp_var_for_tac_55;
  computeLdMul((Addr)&temp_var_for_tac_42,
               {(Addr)&s, (Addr) &(temp_var_for_const_36 = pa[7])},
               "/home/shijia/Public/testprogram/s_erfcl.c_e.c:204:65");
  computeLdAdd(
      (Addr)&temp_var_for_tac_43,
      {(Addr) &(temp_var_for_const_37 = pa[6]), (Addr)&temp_var_for_tac_42},
      "/home/shijia/Public/testprogram/s_erfcl.c_e.c:204:61");
  computeLdMul((Addr)&temp_var_for_tac_44,
               {(Addr)&s, (Addr)&temp_var_for_tac_43},
               "/home/shijia/Public/testprogram/s_erfcl.c_e.c:204:52");
  computeLdAdd(
      (Addr)&temp_var_for_tac_45,
      {(Addr) &(temp_var_for_const_38 = pa[5]), (Addr)&temp_var_for_tac_44},
      "/home/shijia/Public/testprogram/s_erfcl.c_e.c:204:48");
  computeLdMul((Addr)&temp_var_for_tac_46,
               {(Addr)&s, (Addr)&temp_var_for_tac_45},
               "/home/shijia/Public/testprogram/s_erfcl.c_e.c:204:39");
  computeLdAdd(
      (Addr)&temp_var_for_tac_47,
      {(Addr) &(temp_var_for_const_39 = pa[4]), (Addr)&temp_var_for_tac_46},
      "/home/shijia/Public/testprogram/s_erfcl.c_e.c:204:35");
  computeLdMul((Addr)&temp_var_for_tac_48,
               {(Addr)&s, (Addr)&temp_var_for_tac_47},
               "/home/shijia/Public/testprogram/s_erfcl.c_e.c:204:26");
  computeLdAdd(
      (Addr)&temp_var_for_tac_49,
      {(Addr) &(temp_var_for_const_40 = pa[3]), (Addr)&temp_var_for_tac_48},
      "/home/shijia/Public/testprogram/s_erfcl.c_e.c:203:30");
  computeLdMul((Addr)&temp_var_for_tac_50,
               {(Addr)&s, (Addr)&temp_var_for_tac_49},
               "/home/shijia/Public/testprogram/s_erfcl.c_e.c:203:21");
  computeLdAdd(
      (Addr)&temp_var_for_tac_51,
      {(Addr) &(temp_var_for_const_41 = pa[2]), (Addr)&temp_var_for_tac_50},
      "/home/shijia/Public/testprogram/s_erfcl.c_e.c:202:25");
  computeLdMul((Addr)&temp_var_for_tac_52,
               {(Addr)&s, (Addr)&temp_var_for_tac_51},
               "/home/shijia/Public/testprogram/s_erfcl.c_e.c:202:16");
  computeLdAdd(
      (Addr)&temp_var_for_tac_53,
      {(Addr) &(temp_var_for_const_42 = pa[1]), (Addr)&temp_var_for_tac_52},
      "/home/shijia/Public/testprogram/s_erfcl.c_e.c:201:20");
  computeLdMul((Addr)&temp_var_for_tac_54,
               {(Addr)&s, (Addr)&temp_var_for_tac_53},
               "/home/shijia/Public/testprogram/s_erfcl.c_e.c:201:11");
  computeLdAdd(
      (Addr)&temp_var_for_tac_55,
      {(Addr) &(temp_var_for_const_43 = pa[0]), (Addr)&temp_var_for_tac_54},
      "/home/shijia/Public/testprogram/s_erfcl.c_e.c:200:15");
  AssignLd({(Addr)&P}, (Addr)&temp_var_for_tac_55,
           "/home/shijia/Public/testprogram/s_erfcl.c_e.c:200:7");
  ;
  long double temp_var_for_tac_56, temp_var_for_tac_57, temp_var_for_tac_58,
      temp_var_for_tac_59, temp_var_for_tac_60, temp_var_for_tac_61,
      temp_var_for_tac_62, temp_var_for_tac_63, temp_var_for_tac_64,
      temp_var_for_tac_65, temp_var_for_tac_66, temp_var_for_tac_67,
      temp_var_for_tac_68;
  long double temp_var_for_const_44, temp_var_for_const_45,
      temp_var_for_const_46, temp_var_for_const_47, temp_var_for_const_48,
      temp_var_for_const_49, temp_var_for_const_50;
  temp_var_for_tac_56 = qa[6] + s;

  temp_var_for_tac_57 = s * temp_var_for_tac_56;

  temp_var_for_tac_58 = qa[5] + temp_var_for_tac_57;

  temp_var_for_tac_59 = s * temp_var_for_tac_58;

  temp_var_for_tac_60 = qa[4] + temp_var_for_tac_59;

  temp_var_for_tac_61 = s * temp_var_for_tac_60;

  temp_var_for_tac_62 = qa[3] + temp_var_for_tac_61;

  temp_var_for_tac_63 = s * temp_var_for_tac_62;

  temp_var_for_tac_64 = qa[2] + temp_var_for_tac_63;

  temp_var_for_tac_65 = s * temp_var_for_tac_64;

  temp_var_for_tac_66 = qa[1] + temp_var_for_tac_65;

  temp_var_for_tac_67 = s * temp_var_for_tac_66;

  temp_var_for_tac_68 = qa[0] + temp_var_for_tac_67;

  Q = temp_var_for_tac_68;
  computeLdAdd((Addr)&temp_var_for_tac_56,
               {(Addr) &(temp_var_for_const_44 = qa[6]), (Addr)&s},
               "/home/shijia/Public/testprogram/s_erfcl.c_e.c:208:69");
  computeLdMul((Addr)&temp_var_for_tac_57,
               {(Addr)&s, (Addr)&temp_var_for_tac_56},
               "/home/shijia/Public/testprogram/s_erfcl.c_e.c:208:60");
  computeLdAdd(
      (Addr)&temp_var_for_tac_58,
      {(Addr) &(temp_var_for_const_45 = qa[5]), (Addr)&temp_var_for_tac_57},
      "/home/shijia/Public/testprogram/s_erfcl.c_e.c:208:56");
  computeLdMul((Addr)&temp_var_for_tac_59,
               {(Addr)&s, (Addr)&temp_var_for_tac_58},
               "/home/shijia/Public/testprogram/s_erfcl.c_e.c:208:47");
  computeLdAdd(
      (Addr)&temp_var_for_tac_60,
      {(Addr) &(temp_var_for_const_46 = qa[4]), (Addr)&temp_var_for_tac_59},
      "/home/shijia/Public/testprogram/s_erfcl.c_e.c:208:43");
  computeLdMul((Addr)&temp_var_for_tac_61,
               {(Addr)&s, (Addr)&temp_var_for_tac_60},
               "/home/shijia/Public/testprogram/s_erfcl.c_e.c:208:34");
  computeLdAdd(
      (Addr)&temp_var_for_tac_62,
      {(Addr) &(temp_var_for_const_47 = qa[3]), (Addr)&temp_var_for_tac_61},
      "/home/shijia/Public/testprogram/s_erfcl.c_e.c:208:30");
  computeLdMul((Addr)&temp_var_for_tac_63,
               {(Addr)&s, (Addr)&temp_var_for_tac_62},
               "/home/shijia/Public/testprogram/s_erfcl.c_e.c:208:21");
  computeLdAdd(
      (Addr)&temp_var_for_tac_64,
      {(Addr) &(temp_var_for_const_48 = qa[2]), (Addr)&temp_var_for_tac_63},
      "/home/shijia/Public/testprogram/s_erfcl.c_e.c:207:25");
  computeLdMul((Addr)&temp_var_for_tac_65,
               {(Addr)&s, (Addr)&temp_var_for_tac_64},
               "/home/shijia/Public/testprogram/s_erfcl.c_e.c:207:16");
  computeLdAdd(
      (Addr)&temp_var_for_tac_66,
      {(Addr) &(temp_var_for_const_49 = qa[1]), (Addr)&temp_var_for_tac_65},
      "/home/shijia/Public/testprogram/s_erfcl.c_e.c:206:20");
  computeLdMul((Addr)&temp_var_for_tac_67,
               {(Addr)&s, (Addr)&temp_var_for_tac_66},
               "/home/shijia/Public/testprogram/s_erfcl.c_e.c:206:11");
  computeLdAdd(
      (Addr)&temp_var_for_tac_68,
      {(Addr) &(temp_var_for_const_50 = qa[0]), (Addr)&temp_var_for_tac_67},
      "/home/shijia/Public/testprogram/s_erfcl.c_e.c:205:15");
  AssignLd({(Addr)&Q}, (Addr)&temp_var_for_tac_68,
           "/home/shijia/Public/testprogram/s_erfcl.c_e.c:205:7");
  ;
  if ((se & 0x8000) == 0) {
    long double temp_var_for_tac_69;
    long double temp_var_for_const_51, temp_var_for_const_52;
    temp_var_for_tac_69 = one - erx;

    z = temp_var_for_tac_69;
    computeLdSub((Addr)&temp_var_for_tac_69,
                 {(Addr) &(temp_var_for_const_52 = one),
                  (Addr) &(temp_var_for_const_51 = erx)},
                 "/home/shijia/Public/testprogram/s_erfcl.c_e.c:210:15");
    AssignLd({(Addr)&z}, (Addr)&temp_var_for_tac_69,
             "/home/shijia/Public/testprogram/s_erfcl.c_e.c:210:9");
    ;
    long double temp_var_for_ext_5;
    long double temp_var_for_tac_70, temp_var_for_tac_71;
    temp_var_for_tac_70 = P / Q;

    temp_var_for_tac_71 = z - temp_var_for_tac_70;

    temp_var_for_ext_5 = temp_var_for_tac_71;
    computeLdDiv((Addr)&temp_var_for_tac_70, {(Addr)&P, (Addr)&Q},
                 "/home/shijia/Public/testprogram/s_erfcl.c_e.c:212:34");
    computeLdSub((Addr)&temp_var_for_tac_71,
                 {(Addr)&z, (Addr)&temp_var_for_tac_70},
                 "/home/shijia/Public/testprogram/s_erfcl.c_e.c:212:30");
    AssignLd({(Addr)&temp_var_for_ext_5}, (Addr)&temp_var_for_tac_71,
             "/home/shijia/Public/testprogram/s_erfcl.c_e.c:212:26");
    ;
    callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_5;
  } else {
    long double temp_var_for_tac_72, temp_var_for_tac_73;
    long double temp_var_for_const_53;
    temp_var_for_tac_72 = P / Q;

    temp_var_for_tac_73 = erx + temp_var_for_tac_72;

    z = temp_var_for_tac_73;
    computeLdDiv((Addr)&temp_var_for_tac_72, {(Addr)&P, (Addr)&Q},
                 "/home/shijia/Public/testprogram/s_erfcl.c_e.c:218:19");
    computeLdAdd(
        (Addr)&temp_var_for_tac_73,
        {(Addr) &(temp_var_for_const_53 = erx), (Addr)&temp_var_for_tac_72},
        "/home/shijia/Public/testprogram/s_erfcl.c_e.c:218:15");
    AssignLd({(Addr)&z}, (Addr)&temp_var_for_tac_73,
             "/home/shijia/Public/testprogram/s_erfcl.c_e.c:218:9");
    ;
    long double temp_var_for_ext_6;
    long double temp_var_for_tac_74;
    long double temp_var_for_const_54;
    temp_var_for_tac_74 = one + z;

    temp_var_for_ext_6 = temp_var_for_tac_74;
    computeLdAdd((Addr)&temp_var_for_tac_74,
                 {(Addr) &(temp_var_for_const_54 = one), (Addr)&z},
                 "/home/shijia/Public/testprogram/s_erfcl.c_e.c:220:32");
    AssignLd({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_74,
             "/home/shijia/Public/testprogram/s_erfcl.c_e.c:220:26");
    ;
    callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_6;
  }
}
if (ix < IC(0x4005d600)) /* 107 */
{                        /* |x|<107 */
  long double temp_var_for_ext_7;
  long double temp_var_for_const_55;
  long double temp_var_for_callexp_1;

  temp_var_for_callexp_1 = fabsl(x);
  temp_var_for_ext_7 = temp_var_for_callexp_1;
  AssignLd({(Addr)&temp_var_for_ext_7},
           (Addr) &(temp_var_for_const_55 = temp_var_for_callexp_1),
           "/home/shijia/Public/testprogram/s_erfcl.c_e.c:230:24");
  ; // x
  /*(Q)(P)(erx)(Q)(P)(6)(tem)(__ieee754_fabsl(x))*/
  x = temp_var_for_ext_7;
  AssignLd({(Addr)&x}, (Addr)&temp_var_for_ext_7,
           "/home/shijia/Public/testprogram/s_erfcl.c_e.c:232:7");
  ;
  long double temp_var_for_tac_75, temp_var_for_tac_76;
  long double temp_var_for_const_56;
  temp_var_for_tac_75 = x * x;

  temp_var_for_tac_76 = one / temp_var_for_tac_75;

  s = temp_var_for_tac_76;
  computeLdMul((Addr)&temp_var_for_tac_75, {(Addr)&x, (Addr)&x},
               "/home/shijia/Public/testprogram/s_erfcl.c_e.c:233:18");
  computeLdDiv(
      (Addr)&temp_var_for_tac_76,
      {(Addr) &(temp_var_for_const_56 = one), (Addr)&temp_var_for_tac_75},
      "/home/shijia/Public/testprogram/s_erfcl.c_e.c:233:13");
  AssignLd({(Addr)&s}, (Addr)&temp_var_for_tac_76,
           "/home/shijia/Public/testprogram/s_erfcl.c_e.c:233:7");
  ;
  if (ix < IC(0x4000b6db)) /* 2.85711669921875 */
  {                        /* |x| < 1/.35 ~ 2.857143 */
    long double temp_var_for_tac_77, temp_var_for_tac_78, temp_var_for_tac_79,
        temp_var_for_tac_80, temp_var_for_tac_81, temp_var_for_tac_82,
        temp_var_for_tac_83, temp_var_for_tac_84, temp_var_for_tac_85,
        temp_var_for_tac_86, temp_var_for_tac_87, temp_var_for_tac_88,
        temp_var_for_tac_89, temp_var_for_tac_90, temp_var_for_tac_91,
        temp_var_for_tac_92;
    long double temp_var_for_const_57, temp_var_for_const_58,
        temp_var_for_const_59, temp_var_for_const_60, temp_var_for_const_61,
        temp_var_for_const_62, temp_var_for_const_63, temp_var_for_const_64,
        temp_var_for_const_65;
    temp_var_for_tac_77 = s * ra[8];

    temp_var_for_tac_78 = ra[7] + temp_var_for_tac_77;

    temp_var_for_tac_79 = s * temp_var_for_tac_78;

    temp_var_for_tac_80 = ra[6] + temp_var_for_tac_79;

    temp_var_for_tac_81 = s * temp_var_for_tac_80;

    temp_var_for_tac_82 = ra[5] + temp_var_for_tac_81;

    temp_var_for_tac_83 = s * temp_var_for_tac_82;

    temp_var_for_tac_84 = ra[4] + temp_var_for_tac_83;

    temp_var_for_tac_85 = s * temp_var_for_tac_84;

    temp_var_for_tac_86 = ra[3] + temp_var_for_tac_85;

    temp_var_for_tac_87 = s * temp_var_for_tac_86;

    temp_var_for_tac_88 = ra[2] + temp_var_for_tac_87;

    temp_var_for_tac_89 = s * temp_var_for_tac_88;

    temp_var_for_tac_90 = ra[1] + temp_var_for_tac_89;

    temp_var_for_tac_91 = s * temp_var_for_tac_90;

    temp_var_for_tac_92 = ra[0] + temp_var_for_tac_91;

    R = temp_var_for_tac_92;
    computeLdMul((Addr)&temp_var_for_tac_77,
                 {(Addr)&s, (Addr) &(temp_var_for_const_57 = ra[8])},
                 "/home/shijia/Public/testprogram/s_erfcl.c_e.c:242:64");
    computeLdAdd(
        (Addr)&temp_var_for_tac_78,
        {(Addr) &(temp_var_for_const_58 = ra[7]), (Addr)&temp_var_for_tac_77},
        "/home/shijia/Public/testprogram/s_erfcl.c_e.c:242:60");
    computeLdMul((Addr)&temp_var_for_tac_79,
                 {(Addr)&s, (Addr)&temp_var_for_tac_78},
                 "/home/shijia/Public/testprogram/s_erfcl.c_e.c:242:51");
    computeLdAdd(
        (Addr)&temp_var_for_tac_80,
        {(Addr) &(temp_var_for_const_59 = ra[6]), (Addr)&temp_var_for_tac_79},
        "/home/shijia/Public/testprogram/s_erfcl.c_e.c:242:47");
    computeLdMul((Addr)&temp_var_for_tac_81,
                 {(Addr)&s, (Addr)&temp_var_for_tac_80},
                 "/home/shijia/Public/testprogram/s_erfcl.c_e.c:242:38");
    computeLdAdd(
        (Addr)&temp_var_for_tac_82,
        {(Addr) &(temp_var_for_const_60 = ra[5]), (Addr)&temp_var_for_tac_81},
        "/home/shijia/Public/testprogram/s_erfcl.c_e.c:241:42");
    computeLdMul((Addr)&temp_var_for_tac_83,
                 {(Addr)&s, (Addr)&temp_var_for_tac_82},
                 "/home/shijia/Public/testprogram/s_erfcl.c_e.c:241:33");
    computeLdAdd(
        (Addr)&temp_var_for_tac_84,
        {(Addr) &(temp_var_for_const_61 = ra[4]), (Addr)&temp_var_for_tac_83},
        "/home/shijia/Public/testprogram/s_erfcl.c_e.c:240:37");
    computeLdMul((Addr)&temp_var_for_tac_85,
                 {(Addr)&s, (Addr)&temp_var_for_tac_84},
                 "/home/shijia/Public/testprogram/s_erfcl.c_e.c:240:28");
    computeLdAdd(
        (Addr)&temp_var_for_tac_86,
        {(Addr) &(temp_var_for_const_62 = ra[3]), (Addr)&temp_var_for_tac_85},
        "/home/shijia/Public/testprogram/s_erfcl.c_e.c:239:32");
    computeLdMul((Addr)&temp_var_for_tac_87,
                 {(Addr)&s, (Addr)&temp_var_for_tac_86},
                 "/home/shijia/Public/testprogram/s_erfcl.c_e.c:239:23");
    computeLdAdd(
        (Addr)&temp_var_for_tac_88,
        {(Addr) &(temp_var_for_const_63 = ra[2]), (Addr)&temp_var_for_tac_87},
        "/home/shijia/Public/testprogram/s_erfcl.c_e.c:238:27");
    computeLdMul((Addr)&temp_var_for_tac_89,
                 {(Addr)&s, (Addr)&temp_var_for_tac_88},
                 "/home/shijia/Public/testprogram/s_erfcl.c_e.c:238:18");
    computeLdAdd(
        (Addr)&temp_var_for_tac_90,
        {(Addr) &(temp_var_for_const_64 = ra[1]), (Addr)&temp_var_for_tac_89},
        "/home/shijia/Public/testprogram/s_erfcl.c_e.c:237:22");
    computeLdMul((Addr)&temp_var_for_tac_91,
                 {(Addr)&s, (Addr)&temp_var_for_tac_90},
                 "/home/shijia/Public/testprogram/s_erfcl.c_e.c:237:13");
    computeLdAdd(
        (Addr)&temp_var_for_tac_92,
        {(Addr) &(temp_var_for_const_65 = ra[0]), (Addr)&temp_var_for_tac_91},
        "/home/shijia/Public/testprogram/s_erfcl.c_e.c:236:17");
    AssignLd({(Addr)&R}, (Addr)&temp_var_for_tac_92,
             "/home/shijia/Public/testprogram/s_erfcl.c_e.c:236:9");
    ;
    long double temp_var_for_tac_93, temp_var_for_tac_94, temp_var_for_tac_95,
        temp_var_for_tac_96, temp_var_for_tac_97, temp_var_for_tac_98,
        temp_var_for_tac_99, temp_var_for_tac_100, temp_var_for_tac_101,
        temp_var_for_tac_102, temp_var_for_tac_103, temp_var_for_tac_104,
        temp_var_for_tac_105, temp_var_for_tac_106, temp_var_for_tac_107,
        temp_var_for_tac_108, temp_var_for_tac_109;
    long double temp_var_for_const_66, temp_var_for_const_67,
        temp_var_for_const_68, temp_var_for_const_69, temp_var_for_const_70,
        temp_var_for_const_71, temp_var_for_const_72, temp_var_for_const_73,
        temp_var_for_const_74;
    temp_var_for_tac_93 = sa[8] + s;

    temp_var_for_tac_94 = s * temp_var_for_tac_93;

    temp_var_for_tac_95 = sa[7] + temp_var_for_tac_94;

    temp_var_for_tac_96 = s * temp_var_for_tac_95;

    temp_var_for_tac_97 = sa[6] + temp_var_for_tac_96;

    temp_var_for_tac_98 = s * temp_var_for_tac_97;

    temp_var_for_tac_99 = sa[5] + temp_var_for_tac_98;

    temp_var_for_tac_100 = s * temp_var_for_tac_99;

    temp_var_for_tac_101 = sa[4] + temp_var_for_tac_100;

    temp_var_for_tac_102 = s * temp_var_for_tac_101;

    temp_var_for_tac_103 = sa[3] + temp_var_for_tac_102;

    temp_var_for_tac_104 = s * temp_var_for_tac_103;

    temp_var_for_tac_105 = sa[2] + temp_var_for_tac_104;

    temp_var_for_tac_106 = s * temp_var_for_tac_105;

    temp_var_for_tac_107 = sa[1] + temp_var_for_tac_106;

    temp_var_for_tac_108 = s * temp_var_for_tac_107;

    temp_var_for_tac_109 = sa[0] + temp_var_for_tac_108;

    S = temp_var_for_tac_109;
    computeLdAdd((Addr)&temp_var_for_tac_93,
                 {(Addr) &(temp_var_for_const_66 = sa[8]), (Addr)&s},
                 "/home/shijia/Public/testprogram/s_erfcl.c_e.c:250:65");
    computeLdMul((Addr)&temp_var_for_tac_94,
                 {(Addr)&s, (Addr)&temp_var_for_tac_93},
                 "/home/shijia/Public/testprogram/s_erfcl.c_e.c:250:56");
    computeLdAdd(
        (Addr)&temp_var_for_tac_95,
        {(Addr) &(temp_var_for_const_67 = sa[7]), (Addr)&temp_var_for_tac_94},
        "/home/shijia/Public/testprogram/s_erfcl.c_e.c:250:52");
    computeLdMul((Addr)&temp_var_for_tac_96,
                 {(Addr)&s, (Addr)&temp_var_for_tac_95},
                 "/home/shijia/Public/testprogram/s_erfcl.c_e.c:250:43");
    computeLdAdd(
        (Addr)&temp_var_for_tac_97,
        {(Addr) &(temp_var_for_const_68 = sa[6]), (Addr)&temp_var_for_tac_96},
        "/home/shijia/Public/testprogram/s_erfcl.c_e.c:249:47");
    computeLdMul((Addr)&temp_var_for_tac_98,
                 {(Addr)&s, (Addr)&temp_var_for_tac_97},
                 "/home/shijia/Public/testprogram/s_erfcl.c_e.c:249:38");
    computeLdAdd(
        (Addr)&temp_var_for_tac_99,
        {(Addr) &(temp_var_for_const_69 = sa[5]), (Addr)&temp_var_for_tac_98},
        "/home/shijia/Public/testprogram/s_erfcl.c_e.c:248:42");
    computeLdMul((Addr)&temp_var_for_tac_100,
                 {(Addr)&s, (Addr)&temp_var_for_tac_99},
                 "/home/shijia/Public/testprogram/s_erfcl.c_e.c:248:33");
    computeLdAdd(
        (Addr)&temp_var_for_tac_101,
        {(Addr) &(temp_var_for_const_70 = sa[4]), (Addr)&temp_var_for_tac_100},
        "/home/shijia/Public/testprogram/s_erfcl.c_e.c:247:37");
    computeLdMul((Addr)&temp_var_for_tac_102,
                 {(Addr)&s, (Addr)&temp_var_for_tac_101},
                 "/home/shijia/Public/testprogram/s_erfcl.c_e.c:247:28");
    computeLdAdd(
        (Addr)&temp_var_for_tac_103,
        {(Addr) &(temp_var_for_const_71 = sa[3]), (Addr)&temp_var_for_tac_102},
        "/home/shijia/Public/testprogram/s_erfcl.c_e.c:246:32");
    computeLdMul((Addr)&temp_var_for_tac_104,
                 {(Addr)&s, (Addr)&temp_var_for_tac_103},
                 "/home/shijia/Public/testprogram/s_erfcl.c_e.c:246:23");
    computeLdAdd(
        (Addr)&temp_var_for_tac_105,
        {(Addr) &(temp_var_for_const_72 = sa[2]), (Addr)&temp_var_for_tac_104},
        "/home/shijia/Public/testprogram/s_erfcl.c_e.c:245:27");
    computeLdMul((Addr)&temp_var_for_tac_106,
                 {(Addr)&s, (Addr)&temp_var_for_tac_105},
                 "/home/shijia/Public/testprogram/s_erfcl.c_e.c:245:18");
    computeLdAdd(
        (Addr)&temp_var_for_tac_107,
        {(Addr) &(temp_var_for_const_73 = sa[1]), (Addr)&temp_var_for_tac_106},
        "/home/shijia/Public/testprogram/s_erfcl.c_e.c:244:22");
    computeLdMul((Addr)&temp_var_for_tac_108,
                 {(Addr)&s, (Addr)&temp_var_for_tac_107},
                 "/home/shijia/Public/testprogram/s_erfcl.c_e.c:244:13");
    computeLdAdd(
        (Addr)&temp_var_for_tac_109,
        {(Addr) &(temp_var_for_const_74 = sa[0]), (Addr)&temp_var_for_tac_108},
        "/home/shijia/Public/testprogram/s_erfcl.c_e.c:243:17");
    AssignLd({(Addr)&S}, (Addr)&temp_var_for_tac_109,
             "/home/shijia/Public/testprogram/s_erfcl.c_e.c:243:9");
    ;
  } else {
    if (ix < IC(0x4001d555)) /* 6.6666259765625 */
    {                        /* 6.666 > |x| >= 1/.35 ~ 2.857143 */
      long double temp_var_for_tac_110, temp_var_for_tac_111,
          temp_var_for_tac_112, temp_var_for_tac_113, temp_var_for_tac_114,
          temp_var_for_tac_115, temp_var_for_tac_116, temp_var_for_tac_117,
          temp_var_for_tac_118, temp_var_for_tac_119, temp_var_for_tac_120,
          temp_var_for_tac_121, temp_var_for_tac_122, temp_var_for_tac_123;
      long double temp_var_for_const_75, temp_var_for_const_76,
          temp_var_for_const_77, temp_var_for_const_78, temp_var_for_const_79,
          temp_var_for_const_80, temp_var_for_const_81, temp_var_for_const_82;
      temp_var_for_tac_110 = s * rb[7];

      temp_var_for_tac_111 = rb[6] + temp_var_for_tac_110;

      temp_var_for_tac_112 = s * temp_var_for_tac_111;

      temp_var_for_tac_113 = rb[5] + temp_var_for_tac_112;

      temp_var_for_tac_114 = s * temp_var_for_tac_113;

      temp_var_for_tac_115 = rb[4] + temp_var_for_tac_114;

      temp_var_for_tac_116 = s * temp_var_for_tac_115;

      temp_var_for_tac_117 = rb[3] + temp_var_for_tac_116;

      temp_var_for_tac_118 = s * temp_var_for_tac_117;

      temp_var_for_tac_119 = rb[2] + temp_var_for_tac_118;

      temp_var_for_tac_120 = s * temp_var_for_tac_119;

      temp_var_for_tac_121 = rb[1] + temp_var_for_tac_120;

      temp_var_for_tac_122 = s * temp_var_for_tac_121;

      temp_var_for_tac_123 = rb[0] + temp_var_for_tac_122;

      R = temp_var_for_tac_123;
      computeLdMul((Addr)&temp_var_for_tac_110,
                   {(Addr)&s, (Addr) &(temp_var_for_const_75 = rb[7])},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:259:61");
      computeLdAdd((Addr)&temp_var_for_tac_111,
                   {(Addr) &(temp_var_for_const_76 = rb[6]),
                    (Addr)&temp_var_for_tac_110},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:259:57");
      computeLdMul((Addr)&temp_var_for_tac_112,
                   {(Addr)&s, (Addr)&temp_var_for_tac_111},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:259:48");
      computeLdAdd((Addr)&temp_var_for_tac_113,
                   {(Addr) &(temp_var_for_const_77 = rb[5]),
                    (Addr)&temp_var_for_tac_112},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:259:44");
      computeLdMul((Addr)&temp_var_for_tac_114,
                   {(Addr)&s, (Addr)&temp_var_for_tac_113},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:259:35");
      computeLdAdd((Addr)&temp_var_for_tac_115,
                   {(Addr) &(temp_var_for_const_78 = rb[4]),
                    (Addr)&temp_var_for_tac_114},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:258:39");
      computeLdMul((Addr)&temp_var_for_tac_116,
                   {(Addr)&s, (Addr)&temp_var_for_tac_115},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:258:30");
      computeLdAdd((Addr)&temp_var_for_tac_117,
                   {(Addr) &(temp_var_for_const_79 = rb[3]),
                    (Addr)&temp_var_for_tac_116},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:257:34");
      computeLdMul((Addr)&temp_var_for_tac_118,
                   {(Addr)&s, (Addr)&temp_var_for_tac_117},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:257:25");
      computeLdAdd((Addr)&temp_var_for_tac_119,
                   {(Addr) &(temp_var_for_const_80 = rb[2]),
                    (Addr)&temp_var_for_tac_118},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:256:29");
      computeLdMul((Addr)&temp_var_for_tac_120,
                   {(Addr)&s, (Addr)&temp_var_for_tac_119},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:256:20");
      computeLdAdd((Addr)&temp_var_for_tac_121,
                   {(Addr) &(temp_var_for_const_81 = rb[1]),
                    (Addr)&temp_var_for_tac_120},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:255:24");
      computeLdMul((Addr)&temp_var_for_tac_122,
                   {(Addr)&s, (Addr)&temp_var_for_tac_121},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:255:15");
      computeLdAdd((Addr)&temp_var_for_tac_123,
                   {(Addr) &(temp_var_for_const_82 = rb[0]),
                    (Addr)&temp_var_for_tac_122},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:254:19");
      AssignLd({(Addr)&R}, (Addr)&temp_var_for_tac_123,
               "/home/shijia/Public/testprogram/s_erfcl.c_e.c:254:11");
      ;
      long double temp_var_for_tac_124, temp_var_for_tac_125,
          temp_var_for_tac_126, temp_var_for_tac_127, temp_var_for_tac_128,
          temp_var_for_tac_129, temp_var_for_tac_130, temp_var_for_tac_131,
          temp_var_for_tac_132, temp_var_for_tac_133, temp_var_for_tac_134,
          temp_var_for_tac_135, temp_var_for_tac_136;
      long double temp_var_for_const_83, temp_var_for_const_84,
          temp_var_for_const_85, temp_var_for_const_86, temp_var_for_const_87,
          temp_var_for_const_88, temp_var_for_const_89;
      temp_var_for_tac_124 = sb[6] + s;

      temp_var_for_tac_125 = s * temp_var_for_tac_124;

      temp_var_for_tac_126 = sb[5] + temp_var_for_tac_125;

      temp_var_for_tac_127 = s * temp_var_for_tac_126;

      temp_var_for_tac_128 = sb[4] + temp_var_for_tac_127;

      temp_var_for_tac_129 = s * temp_var_for_tac_128;

      temp_var_for_tac_130 = sb[3] + temp_var_for_tac_129;

      temp_var_for_tac_131 = s * temp_var_for_tac_130;

      temp_var_for_tac_132 = sb[2] + temp_var_for_tac_131;

      temp_var_for_tac_133 = s * temp_var_for_tac_132;

      temp_var_for_tac_134 = sb[1] + temp_var_for_tac_133;

      temp_var_for_tac_135 = s * temp_var_for_tac_134;

      temp_var_for_tac_136 = sb[0] + temp_var_for_tac_135;

      S = temp_var_for_tac_136;
      computeLdAdd((Addr)&temp_var_for_tac_124,
                   {(Addr) &(temp_var_for_const_83 = sb[6]), (Addr)&s},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:264:65");
      computeLdMul((Addr)&temp_var_for_tac_125,
                   {(Addr)&s, (Addr)&temp_var_for_tac_124},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:264:56");
      computeLdAdd((Addr)&temp_var_for_tac_126,
                   {(Addr) &(temp_var_for_const_84 = sb[5]),
                    (Addr)&temp_var_for_tac_125},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:264:52");
      computeLdMul((Addr)&temp_var_for_tac_127,
                   {(Addr)&s, (Addr)&temp_var_for_tac_126},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:264:43");
      computeLdAdd((Addr)&temp_var_for_tac_128,
                   {(Addr) &(temp_var_for_const_85 = sb[4]),
                    (Addr)&temp_var_for_tac_127},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:264:39");
      computeLdMul((Addr)&temp_var_for_tac_129,
                   {(Addr)&s, (Addr)&temp_var_for_tac_128},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:264:30");
      computeLdAdd((Addr)&temp_var_for_tac_130,
                   {(Addr) &(temp_var_for_const_86 = sb[3]),
                    (Addr)&temp_var_for_tac_129},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:263:34");
      computeLdMul((Addr)&temp_var_for_tac_131,
                   {(Addr)&s, (Addr)&temp_var_for_tac_130},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:263:25");
      computeLdAdd((Addr)&temp_var_for_tac_132,
                   {(Addr) &(temp_var_for_const_87 = sb[2]),
                    (Addr)&temp_var_for_tac_131},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:262:29");
      computeLdMul((Addr)&temp_var_for_tac_133,
                   {(Addr)&s, (Addr)&temp_var_for_tac_132},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:262:20");
      computeLdAdd((Addr)&temp_var_for_tac_134,
                   {(Addr) &(temp_var_for_const_88 = sb[1]),
                    (Addr)&temp_var_for_tac_133},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:261:24");
      computeLdMul((Addr)&temp_var_for_tac_135,
                   {(Addr)&s, (Addr)&temp_var_for_tac_134},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:261:15");
      computeLdAdd((Addr)&temp_var_for_tac_136,
                   {(Addr) &(temp_var_for_const_89 = sb[0]),
                    (Addr)&temp_var_for_tac_135},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:260:19");
      AssignLd({(Addr)&S}, (Addr)&temp_var_for_tac_136,
               "/home/shijia/Public/testprogram/s_erfcl.c_e.c:260:11");
      ;
    } else { /* |x| >= 6.666 */
      if (se & 0x8000) {
        long double temp_var_for_ext_8;
        long double temp_var_for_tac_137;
        long double temp_var_for_const_90, temp_var_for_const_91;
        temp_var_for_tac_137 = two - tiny;

        temp_var_for_ext_8 = temp_var_for_tac_137;
        computeLdSub((Addr)&temp_var_for_tac_137,
                     {(Addr) &(temp_var_for_const_91 = two),
                      (Addr) &(temp_var_for_const_90 = tiny)},
                     "/home/shijia/Public/testprogram/s_erfcl.c_e.c:268:36");
        AssignLd({(Addr)&temp_var_for_ext_8}, (Addr)&temp_var_for_tac_137,
                 "/home/shijia/Public/testprogram/s_erfcl.c_e.c:268:30");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_8;
      }
      /* x < -6.666 */

      long double temp_var_for_tac_138, temp_var_for_tac_139,
          temp_var_for_tac_140, temp_var_for_tac_141, temp_var_for_tac_142,
          temp_var_for_tac_143, temp_var_for_tac_144, temp_var_for_tac_145,
          temp_var_for_tac_146, temp_var_for_tac_147;
      long double temp_var_for_const_92, temp_var_for_const_93,
          temp_var_for_const_94, temp_var_for_const_95, temp_var_for_const_96,
          temp_var_for_const_97;
      temp_var_for_tac_138 = s * rc[5];

      temp_var_for_tac_139 = rc[4] + temp_var_for_tac_138;

      temp_var_for_tac_140 = s * temp_var_for_tac_139;

      temp_var_for_tac_141 = rc[3] + temp_var_for_tac_140;

      temp_var_for_tac_142 = s * temp_var_for_tac_141;

      temp_var_for_tac_143 = rc[2] + temp_var_for_tac_142;

      temp_var_for_tac_144 = s * temp_var_for_tac_143;

      temp_var_for_tac_145 = rc[1] + temp_var_for_tac_144;

      temp_var_for_tac_146 = s * temp_var_for_tac_145;

      temp_var_for_tac_147 = rc[0] + temp_var_for_tac_146;

      R = temp_var_for_tac_147;
      computeLdMul((Addr)&temp_var_for_tac_138,
                   {(Addr)&s, (Addr) &(temp_var_for_const_92 = rc[5])},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:277:67");
      computeLdAdd((Addr)&temp_var_for_tac_139,
                   {(Addr) &(temp_var_for_const_93 = rc[4]),
                    (Addr)&temp_var_for_tac_138},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:277:63");
      computeLdMul((Addr)&temp_var_for_tac_140,
                   {(Addr)&s, (Addr)&temp_var_for_tac_139},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:277:54");
      computeLdAdd((Addr)&temp_var_for_tac_141,
                   {(Addr) &(temp_var_for_const_94 = rc[3]),
                    (Addr)&temp_var_for_tac_140},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:277:50");
      computeLdMul((Addr)&temp_var_for_tac_142,
                   {(Addr)&s, (Addr)&temp_var_for_tac_141},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:277:41");
      computeLdAdd((Addr)&temp_var_for_tac_143,
                   {(Addr) &(temp_var_for_const_95 = rc[2]),
                    (Addr)&temp_var_for_tac_142},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:277:37");
      computeLdMul((Addr)&temp_var_for_tac_144,
                   {(Addr)&s, (Addr)&temp_var_for_tac_143},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:277:28");
      computeLdAdd((Addr)&temp_var_for_tac_145,
                   {(Addr) &(temp_var_for_const_96 = rc[1]),
                    (Addr)&temp_var_for_tac_144},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:277:24");
      computeLdMul((Addr)&temp_var_for_tac_146,
                   {(Addr)&s, (Addr)&temp_var_for_tac_145},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:277:15");
      computeLdAdd((Addr)&temp_var_for_tac_147,
                   {(Addr) &(temp_var_for_const_97 = rc[0]),
                    (Addr)&temp_var_for_tac_146},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:276:19");
      AssignLd({(Addr)&R}, (Addr)&temp_var_for_tac_147,
               "/home/shijia/Public/testprogram/s_erfcl.c_e.c:276:11");
      ;
      long double temp_var_for_tac_148, temp_var_for_tac_149,
          temp_var_for_tac_150, temp_var_for_tac_151, temp_var_for_tac_152,
          temp_var_for_tac_153, temp_var_for_tac_154, temp_var_for_tac_155,
          temp_var_for_tac_156;
      long double temp_var_for_const_98, temp_var_for_const_99,
          temp_var_for_const_100, temp_var_for_const_101,
          temp_var_for_const_102;
      temp_var_for_tac_148 = sc[4] + s;

      temp_var_for_tac_149 = s * temp_var_for_tac_148;

      temp_var_for_tac_150 = sc[3] + temp_var_for_tac_149;

      temp_var_for_tac_151 = s * temp_var_for_tac_150;

      temp_var_for_tac_152 = sc[2] + temp_var_for_tac_151;

      temp_var_for_tac_153 = s * temp_var_for_tac_152;

      temp_var_for_tac_154 = sc[1] + temp_var_for_tac_153;

      temp_var_for_tac_155 = s * temp_var_for_tac_154;

      temp_var_for_tac_156 = sc[0] + temp_var_for_tac_155;

      S = temp_var_for_tac_156;
      computeLdAdd((Addr)&temp_var_for_tac_148,
                   {(Addr) &(temp_var_for_const_98 = sc[4]), (Addr)&s},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:278:71");
      computeLdMul((Addr)&temp_var_for_tac_149,
                   {(Addr)&s, (Addr)&temp_var_for_tac_148},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:278:62");
      computeLdAdd((Addr)&temp_var_for_tac_150,
                   {(Addr) &(temp_var_for_const_99 = sc[3]),
                    (Addr)&temp_var_for_tac_149},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:278:58");
      computeLdMul((Addr)&temp_var_for_tac_151,
                   {(Addr)&s, (Addr)&temp_var_for_tac_150},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:278:49");
      computeLdAdd((Addr)&temp_var_for_tac_152,
                   {(Addr) &(temp_var_for_const_100 = sc[2]),
                    (Addr)&temp_var_for_tac_151},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:278:45");
      computeLdMul((Addr)&temp_var_for_tac_153,
                   {(Addr)&s, (Addr)&temp_var_for_tac_152},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:278:36");
      computeLdAdd((Addr)&temp_var_for_tac_154,
                   {(Addr) &(temp_var_for_const_101 = sc[1]),
                    (Addr)&temp_var_for_tac_153},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:278:32");
      computeLdMul((Addr)&temp_var_for_tac_155,
                   {(Addr)&s, (Addr)&temp_var_for_tac_154},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:278:23");
      computeLdAdd((Addr)&temp_var_for_tac_156,
                   {(Addr) &(temp_var_for_const_102 = sc[0]),
                    (Addr)&temp_var_for_tac_155},
                   "/home/shijia/Public/testprogram/s_erfcl.c_e.c:278:19");
      AssignLd({(Addr)&S}, (Addr)&temp_var_for_tac_156,
               "/home/shijia/Public/testprogram/s_erfcl.c_e.c:278:11");
      ;
    }
  }

  z = x;
  AssignLd({(Addr)&z}, (Addr)&x,
           "/home/shijia/Public/testprogram/s_erfcl.c_e.c:282:7");
  ;
  long double temp_var_for_const_103;
  ew_u.value = z;
  AssignLd({(Addr) &(temp_var_for_const_103 = ew_u.value)}, (Addr)&z,
           "/home/shijia/Public/testprogram/s_erfcl.c_e.c:283:5 "
           "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
  ;
  i1 = 0;
  i0 &= UC(0xffffff00);
  long double temp_var_for_ext_9;
  temp_var_for_ext_9;
  long double temp_var_for_tac_157, temp_var_for_tac_158, temp_var_for_tac_159,
      temp_var_for_tac_160, temp_var_for_tac_161, temp_var_for_tac_162,
      temp_var_for_tac_163, temp_var_for_tac_164, temp_var_for_tac_165;
  long double temp_var_for_const_104, temp_var_for_const_105,
      temp_var_for_const_106, temp_var_for_const_107;
  long double temp_var_for_callexp_2;

  long double temp_var_for_callexp_3;

  temp_var_for_tac_157 = 0.0 - z;

  temp_var_for_tac_158 = temp_var_for_tac_157 * z;

  temp_var_for_tac_159 = temp_var_for_tac_158 - 0.5625;

  temp_var_for_callexp_2 = __ieee754_expl(temp_var_for_tac_159);
  temp_var_for_tac_160 = z - x;

  temp_var_for_tac_161 = z + x;

  temp_var_for_tac_162 = temp_var_for_tac_160 * temp_var_for_tac_161;

  temp_var_for_tac_163 = R / S;

  temp_var_for_tac_164 = temp_var_for_tac_162 + temp_var_for_tac_163;

  temp_var_for_callexp_3 = __ieee754_expl(temp_var_for_tac_164);
  temp_var_for_tac_165 = temp_var_for_callexp_2 * temp_var_for_callexp_3;

  r = temp_var_for_tac_165;
  computeLdSub((Addr)&temp_var_for_tac_157,
               {(Addr) &(temp_var_for_const_104 = 0.0), (Addr)&z},
               "/home/shijia/Public/testprogram/s_erfcl.c_e.c:288:29");
  computeLdMul((Addr)&temp_var_for_tac_158,
               {(Addr)&temp_var_for_tac_157, (Addr)&z},
               "/home/shijia/Public/testprogram/s_erfcl.c_e.c:288:34");
  computeLdSub(
      (Addr)&temp_var_for_tac_159,
      {(Addr)&temp_var_for_tac_158, (Addr) &(temp_var_for_const_105 = 0.5625)},
      "/home/shijia/Public/testprogram/s_erfcl.c_e.c:288:38");
  computeLdSub((Addr)&temp_var_for_tac_160, {(Addr)&z, (Addr)&x},
               "/home/shijia/Public/testprogram/s_erfcl.c_e.c:289:27");
  computeLdAdd((Addr)&temp_var_for_tac_161, {(Addr)&z, (Addr)&x},
               "/home/shijia/Public/testprogram/s_erfcl.c_e.c:289:37");
  computeLdMul((Addr)&temp_var_for_tac_162,
               {(Addr)&temp_var_for_tac_160, (Addr)&temp_var_for_tac_161},
               "/home/shijia/Public/testprogram/s_erfcl.c_e.c:289:32");
  computeLdDiv((Addr)&temp_var_for_tac_163, {(Addr)&R, (Addr)&S},
               "/home/shijia/Public/testprogram/s_erfcl.c_e.c:289:46");
  computeLdAdd((Addr)&temp_var_for_tac_164,
               {(Addr)&temp_var_for_tac_162, (Addr)&temp_var_for_tac_163},
               "/home/shijia/Public/testprogram/s_erfcl.c_e.c:289:42");
  computeLdMul((Addr)&temp_var_for_tac_165,
               {(Addr) &(temp_var_for_const_107 = temp_var_for_callexp_2),
                (Addr) &(temp_var_for_const_106 = temp_var_for_callexp_3)},
               "/home/shijia/Public/testprogram/s_erfcl.c_e.c:288:48");
  AssignLd({(Addr)&r}, (Addr)&temp_var_for_tac_165,
           "/home/shijia/Public/testprogram/s_erfcl.c_e.c:288:7");
  ;
  if ((se & 0x8000) == 0) {
    long double temp_var_for_ext_10;
    long double temp_var_for_tac_166;
    temp_var_for_tac_166 = r / x;

    temp_var_for_ext_10 = temp_var_for_tac_166;
    computeLdDiv((Addr)&temp_var_for_tac_166, {(Addr)&r, (Addr)&x},
                 "/home/shijia/Public/testprogram/s_erfcl.c_e.c:292:31");
    AssignLd({(Addr)&temp_var_for_ext_10}, (Addr)&temp_var_for_tac_166,
             "/home/shijia/Public/testprogram/s_erfcl.c_e.c:292:27");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_10", (Addr)&temp_var_for_ext_10));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_10;
  }

  else {
    long double temp_var_for_ext_11;
    long double temp_var_for_tac_167, temp_var_for_tac_168;
    long double temp_var_for_const_108;
    temp_var_for_tac_167 = r / x;

    temp_var_for_tac_168 = two - temp_var_for_tac_167;

    temp_var_for_ext_11 = temp_var_for_tac_168;
    computeLdDiv((Addr)&temp_var_for_tac_167, {(Addr)&r, (Addr)&x},
                 "/home/shijia/Public/testprogram/s_erfcl.c_e.c:301:37");
    computeLdSub(
        (Addr)&temp_var_for_tac_168,
        {(Addr) &(temp_var_for_const_108 = two), (Addr)&temp_var_for_tac_167},
        "/home/shijia/Public/testprogram/s_erfcl.c_e.c:301:33");
    AssignLd({(Addr)&temp_var_for_ext_11}, (Addr)&temp_var_for_tac_168,
             "/home/shijia/Public/testprogram/s_erfcl.c_e.c:301:27");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_11", (Addr)&temp_var_for_ext_11));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_11;
  }
}
#ifdef _WIN32
__set_errno(ERANGE);
#endif
if ((se & 0x8000) == 0) {
  long double temp_var_for_ext_12;
  long double temp_var_for_tac_169;
  long double temp_var_for_const_109, temp_var_for_const_110;
  temp_var_for_tac_169 = tiny * tiny;

  temp_var_for_ext_12 = temp_var_for_tac_169;
  computeLdMul((Addr)&temp_var_for_tac_169,
               {(Addr) &(temp_var_for_const_110 = tiny),
                (Addr) &(temp_var_for_const_109 = tiny)},
               "/home/shijia/Public/testprogram/s_erfcl.c_e.c:313:32");
  AssignLd({(Addr)&temp_var_for_ext_12}, (Addr)&temp_var_for_tac_169,
           "/home/shijia/Public/testprogram/s_erfcl.c_e.c:313:25");
  ;
  callExpStack.push(getReal("temp_var_for_ext_12", (Addr)&temp_var_for_ext_12));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_12;
}

long double temp_var_for_ext_13;
long double temp_var_for_tac_170;
long double temp_var_for_const_111, temp_var_for_const_112;
temp_var_for_tac_170 = two - tiny;

temp_var_for_ext_13 = temp_var_for_tac_170;
computeLdSub((Addr)&temp_var_for_tac_170,
             {(Addr) &(temp_var_for_const_112 = two),
              (Addr) &(temp_var_for_const_111 = tiny)},
             "/home/shijia/Public/testprogram/s_erfcl.c_e.c:321:29");
AssignLd({(Addr)&temp_var_for_ext_13}, (Addr)&temp_var_for_tac_170,
         "/home/shijia/Public/testprogram/s_erfcl.c_e.c:321:23");
;
callExpStack.push(getReal("temp_var_for_ext_13", (Addr)&temp_var_for_ext_13));
callExp++; /*identify the function is  add move tmpShadow*/
return temp_var_for_ext_13;
}

__typeof(__erfcl) erfcl __attribute__((weak, alias("__erfcl")));

#endif
