#include "../ScDebug/scdebug.h"
/* @(#)s_erf.c 5.1 93/09/24 */
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
/* Modified by Naohiko Shimizu/Tokai University, Japan 1997/08/25,
   for performance improvement on pipelined processors.
*/

/* double erf(double x)
 * double erfc(double x)
 *			     x
 *		      2      |\
 *     erf(x)  =  ---------  | exp(-t*t)dt
 *	 	   sqrt(pi) \|
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
 *	   where R = P/Q where P is an odd poly of degree 8 and
 *	   Q is an odd poly of degree 10.
 *						 -57.90
 *			| R - (erf(x)-x)/x | <= 2
 *
 *
 *	   Remark. The formula is derived by noting
 *          erf(x) = (2/sqrt(pi))*(x - x^3/3 + x^5/10 - x^7/42 + ....)
 *	   and that
 *          2/sqrt(pi) = 1.128379167095512573896158903121545171688
 *	   is close to one. The interval is chosen because the fix
 *	   point of erf(x) is near 0.6174 (i.e., erf(x)=x when x is
 *	   near 0.6174), and by some experiment, 0.84375 is chosen to
 * 	   guarantee the error is less than one ulp for erf.
 *
 *      2. For |x| in [0.84375,1.25], let s = |x| - 1, and
 *         c = 0.84506291151 rounded to single (24 bits)
 *         	erf(x)  = sign(x) * (c  + P1(s)/Q1(s))
 *         	erfc(x) = (1-c)  - P1(s)/Q1(s) if x > 0
 *			  1+(c+P1(s)/Q1(s))    if x < 0
 *         	|P1/Q1 - (erf(|x|)-c)| <= 2**-59.06
 *	   Remark: here we use the taylor series expansion at x=1.
 *		erf(1+s) = erf(1) + s*Poly(s)
 *			 = 0.845.. + P1(s)/Q1(s)
 *	   That is, we use rational approximation to approximate
 *			erf(1+s) - (c = (single)0.84506291151)
 *	   Note that |P1/Q1|< 0.078 for x in [0.84375,1.25]
 *	   where
 *		P1(s) = degree 6 poly in s
 *		Q1(s) = degree 6 poly in s
 *
 *      3. For x in [1.25,1/0.35(~2.857143)],
 *         	erfc(x) = (1/x)*exp(-x*x-0.5625+R1/S1)
 *         	erf(x)  = 1 - erfc(x)
 *	   where
 *		R1(z) = degree 7 poly in z, (z=1/x^2)
 *		S1(z) = degree 8 poly in z
 *
 *      4. For x in [1/0.35,28]
 *         	erfc(x) = (1/x)*exp(-x*x-0.5625+R2/S2) if x > 0
 *			= 2.0 - (1/x)*exp(-x*x-0.5625+R2/S2) if -6<x<0
 *			= 2.0 - tiny		(if x <= -6)
 *         	erf(x)  = sign(x)*(1.0 - erfc(x)) if x < 6, else
 *         	erf(x)  = sign(x)*(1.0 - tiny)
 *	   where
 *		R2(z) = degree 6 poly in z, (z=1/x^2)
 *		S2(z) = degree 7 poly in z
 *
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
 *	   We use rational approximation to approximate
 *      	g(s)=f(1/x^2) = log(erfc(x)*x) - x*x + 0.5625
 *	   Here is the error bound for R1/S1 and R2/S2
 *      	|R1/S1 - f(x)|  < 2**(-62.57)
 *      	|R2/S2 - f(x)|  < 2**(-61.52)
 *
 *      5. For inf > x >= 28
 *         	erf(x)  = sign(x) *(1 - tiny)  (raise inexact)
 *         	erfc(x) = tiny*tiny (raise underflow) if x > 0
 *			= 2 - tiny if x<0
 *
 *      7. Special case:
 *         	erf(0)  = 0, erf(inf)  = 1, erf(-inf) = -1,
 *         	erfc(0) = 1, erfc(inf) = 0, erfc(-inf) = 2,
 *	   	erfc/erf(NaN) is NaN
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

double __erfc(double x) {
  int32_t hx, ix;
  double R, S, P, Q, s, y, z, r;

  static const double tiny = 1e-300;
  static const double half =
      5.00000000000000000000e-01; /* 0x3FE00000, 0x00000000 */
  static const double one =
      1.00000000000000000000e+00; /* 0x3FF00000, 0x00000000 */
  static const double two =
      2.00000000000000000000e+00; /* 0x40000000, 0x00000000 */
  /* c = (float)0.84506291151 */
  static const double erx =
      8.45062911510467529297e-01; /* 0x3FEB0AC1, 0x60000000 */

#include "t_erf.h"

  GET_HIGH_WORD(hx, x);
  ix = hx & IC(0x7fffffff);
  if (ix >= IC(0x7ff00000)) { /* erfc(nan)=nan */
    /* erfc(+-inf)=0,2 */
    double temp_var_for_ext_0;
    double temp_var_for_tac_0, temp_var_for_tac_1, temp_var_for_tac_2,
        temp_var_for_tac_3;
    double temp_var_for_const_0, temp_var_for_const_1, temp_var_for_const_2,
        temp_var_for_const_3, temp_var_for_const_4;
    temp_var_for_tac_0 = ((uint32_t)hx) >> 31;

    temp_var_for_tac_1 = temp_var_for_tac_0 << 1;

    temp_var_for_tac_2 = one / x;

    temp_var_for_tac_3 = ((double)temp_var_for_tac_1) + temp_var_for_tac_2;

    temp_var_for_ext_0 = temp_var_for_tac_3;
    compute((Addr)&temp_var_for_tac_0,
            {(Addr) &(temp_var_for_const_1 = ((uint32_t)hx)),
             (Addr) &(temp_var_for_const_0 = 31)},
            "/home/shijia/Public/testprogram/s_erfc.c_e.c:136:49");
    compute((Addr)&temp_var_for_tac_1,
            {(Addr)&temp_var_for_tac_0, (Addr) &(temp_var_for_const_2 = 1)},
            "/home/shijia/Public/testprogram/s_erfc.c_e.c:136:56");
    computeDDiv((Addr)&temp_var_for_tac_2,
                {(Addr) &(temp_var_for_const_3 = one), (Addr)&x},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:136:68");
    computeDAdd((Addr)&temp_var_for_tac_3,
                {(Addr) &(temp_var_for_const_4 = ((double)temp_var_for_tac_1)),
                 (Addr)&temp_var_for_tac_2},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:136:62");
    AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_3,
            "/home/shijia/Public/testprogram/s_erfc.c_e.c:136:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  if (ix < IC(0x3feb0000)) { /* |x|<0.84375 */
    double r1, r2, s1, s2, s3, z2, z4;

    if (ix < IC(0x3c700000)) /* |x|<2**-56 */
    {
      double temp_var_for_ext_1;
      temp_var_for_ext_1 = one - x;
      callExpStack.push(
          getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_1;
    }

    double temp_var_for_tac_4;
    temp_var_for_tac_4 = x * x;

    z = temp_var_for_tac_4;
    computeDMul((Addr)&temp_var_for_tac_4, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:155:11");
    AssignD({(Addr)&z}, (Addr)&temp_var_for_tac_4,
            "/home/shijia/Public/testprogram/s_erfc.c_e.c:155:7");
    ;
#ifdef DO_NOT_USE_THIS
    r = pp0 + z * (pp1 + z * (pp2 + z * (pp3 + z * pp4)));
    s = one + z * (qq1 + z * (qq2 + z * (qq3 + z * (qq4 + z * qq5))));
#else
    double temp_var_for_tac_5, temp_var_for_tac_6;
    double temp_var_for_const_5, temp_var_for_const_6;
    temp_var_for_tac_5 = z * pp1;

    temp_var_for_tac_6 = pp0 + temp_var_for_tac_5;

    r1 = temp_var_for_tac_6;
    computeDMul((Addr)&temp_var_for_tac_5,
                {(Addr)&z, (Addr) &(temp_var_for_const_5 = pp1)},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:160:18");
    computeDAdd(
        (Addr)&temp_var_for_tac_6,
        {(Addr) &(temp_var_for_const_6 = pp0), (Addr)&temp_var_for_tac_5},
        "/home/shijia/Public/testprogram/s_erfc.c_e.c:160:14");
    AssignD({(Addr)&r1}, (Addr)&temp_var_for_tac_6,
            "/home/shijia/Public/testprogram/s_erfc.c_e.c:160:8");
    ;
    double temp_var_for_tac_7;
    temp_var_for_tac_7 = z * z;

    z2 = temp_var_for_tac_7;
    computeDMul((Addr)&temp_var_for_tac_7, {(Addr)&z, (Addr)&z},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:161:12");
    AssignD({(Addr)&z2}, (Addr)&temp_var_for_tac_7,
            "/home/shijia/Public/testprogram/s_erfc.c_e.c:161:8");
    ;
    double temp_var_for_tac_8, temp_var_for_tac_9;
    double temp_var_for_const_7, temp_var_for_const_8;
    temp_var_for_tac_8 = z * pp3;

    temp_var_for_tac_9 = pp2 + temp_var_for_tac_8;

    r2 = temp_var_for_tac_9;
    computeDMul((Addr)&temp_var_for_tac_8,
                {(Addr)&z, (Addr) &(temp_var_for_const_7 = pp3)},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:162:18");
    computeDAdd(
        (Addr)&temp_var_for_tac_9,
        {(Addr) &(temp_var_for_const_8 = pp2), (Addr)&temp_var_for_tac_8},
        "/home/shijia/Public/testprogram/s_erfc.c_e.c:162:14");
    AssignD({(Addr)&r2}, (Addr)&temp_var_for_tac_9,
            "/home/shijia/Public/testprogram/s_erfc.c_e.c:162:8");
    ;
    double temp_var_for_tac_10;
    temp_var_for_tac_10 = z2 * z2;

    z4 = temp_var_for_tac_10;
    computeDMul((Addr)&temp_var_for_tac_10, {(Addr)&z2, (Addr)&z2},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:163:13");
    AssignD({(Addr)&z4}, (Addr)&temp_var_for_tac_10,
            "/home/shijia/Public/testprogram/s_erfc.c_e.c:163:8");
    ;
    double temp_var_for_tac_11, temp_var_for_tac_12;
    double temp_var_for_const_9, temp_var_for_const_10;
    temp_var_for_tac_11 = z * qq1;

    temp_var_for_tac_12 = one + temp_var_for_tac_11;

    s1 = temp_var_for_tac_12;
    computeDMul((Addr)&temp_var_for_tac_11,
                {(Addr)&z, (Addr) &(temp_var_for_const_9 = qq1)},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:164:18");
    computeDAdd(
        (Addr)&temp_var_for_tac_12,
        {(Addr) &(temp_var_for_const_10 = one), (Addr)&temp_var_for_tac_11},
        "/home/shijia/Public/testprogram/s_erfc.c_e.c:164:14");
    AssignD({(Addr)&s1}, (Addr)&temp_var_for_tac_12,
            "/home/shijia/Public/testprogram/s_erfc.c_e.c:164:8");
    ;
    double temp_var_for_tac_13, temp_var_for_tac_14;
    double temp_var_for_const_11, temp_var_for_const_12;
    temp_var_for_tac_13 = z * qq3;

    temp_var_for_tac_14 = qq2 + temp_var_for_tac_13;

    s2 = temp_var_for_tac_14;
    computeDMul((Addr)&temp_var_for_tac_13,
                {(Addr)&z, (Addr) &(temp_var_for_const_11 = qq3)},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:165:18");
    computeDAdd(
        (Addr)&temp_var_for_tac_14,
        {(Addr) &(temp_var_for_const_12 = qq2), (Addr)&temp_var_for_tac_13},
        "/home/shijia/Public/testprogram/s_erfc.c_e.c:165:14");
    AssignD({(Addr)&s2}, (Addr)&temp_var_for_tac_14,
            "/home/shijia/Public/testprogram/s_erfc.c_e.c:165:8");
    ;
    double temp_var_for_tac_15, temp_var_for_tac_16;
    double temp_var_for_const_13, temp_var_for_const_14;
    temp_var_for_tac_15 = z * qq5;

    temp_var_for_tac_16 = qq4 + temp_var_for_tac_15;

    s3 = temp_var_for_tac_16;
    computeDMul((Addr)&temp_var_for_tac_15,
                {(Addr)&z, (Addr) &(temp_var_for_const_13 = qq5)},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:166:18");
    computeDAdd(
        (Addr)&temp_var_for_tac_16,
        {(Addr) &(temp_var_for_const_14 = qq4), (Addr)&temp_var_for_tac_15},
        "/home/shijia/Public/testprogram/s_erfc.c_e.c:166:14");
    AssignD({(Addr)&s3}, (Addr)&temp_var_for_tac_16,
            "/home/shijia/Public/testprogram/s_erfc.c_e.c:166:8");
    ;
    double temp_var_for_tac_17, temp_var_for_tac_18, temp_var_for_tac_19,
        temp_var_for_tac_20;
    double temp_var_for_const_15;
    temp_var_for_tac_17 = z2 * r2;

    temp_var_for_tac_18 = r1 + temp_var_for_tac_17;

    temp_var_for_tac_19 = z4 * pp4;

    temp_var_for_tac_20 = temp_var_for_tac_18 + temp_var_for_tac_19;

    r = temp_var_for_tac_20;
    computeDMul((Addr)&temp_var_for_tac_17, {(Addr)&z2, (Addr)&r2},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:167:17");
    computeDAdd((Addr)&temp_var_for_tac_18,
                {(Addr)&r1, (Addr)&temp_var_for_tac_17},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:167:12");
    computeDMul((Addr)&temp_var_for_tac_19,
                {(Addr)&z4, (Addr) &(temp_var_for_const_15 = pp4)},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:167:27");
    computeDAdd((Addr)&temp_var_for_tac_20,
                {(Addr)&temp_var_for_tac_18, (Addr)&temp_var_for_tac_19},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:167:22");
    AssignD({(Addr)&r}, (Addr)&temp_var_for_tac_20,
            "/home/shijia/Public/testprogram/s_erfc.c_e.c:167:7");
    ;
    double temp_var_for_tac_21, temp_var_for_tac_22, temp_var_for_tac_23,
        temp_var_for_tac_24;
    temp_var_for_tac_21 = z2 * s2;

    temp_var_for_tac_22 = s1 + temp_var_for_tac_21;

    temp_var_for_tac_23 = z4 * s3;

    temp_var_for_tac_24 = temp_var_for_tac_22 + temp_var_for_tac_23;

    s = temp_var_for_tac_24;
    computeDMul((Addr)&temp_var_for_tac_21, {(Addr)&z2, (Addr)&s2},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:168:17");
    computeDAdd((Addr)&temp_var_for_tac_22,
                {(Addr)&s1, (Addr)&temp_var_for_tac_21},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:168:12");
    computeDMul((Addr)&temp_var_for_tac_23, {(Addr)&z4, (Addr)&s3},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:168:27");
    computeDAdd((Addr)&temp_var_for_tac_24,
                {(Addr)&temp_var_for_tac_22, (Addr)&temp_var_for_tac_23},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:168:22");
    AssignD({(Addr)&s}, (Addr)&temp_var_for_tac_24,
            "/home/shijia/Public/testprogram/s_erfc.c_e.c:168:7");
    ;
#endif
    double temp_var_for_tac_25;
    temp_var_for_tac_25 = r / s;

    y = temp_var_for_tac_25;
    computeDDiv((Addr)&temp_var_for_tac_25, {(Addr)&r, (Addr)&s},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:170:11");
    AssignD({(Addr)&y}, (Addr)&temp_var_for_tac_25,
            "/home/shijia/Public/testprogram/s_erfc.c_e.c:170:7");
    ;
    if (hx < IC(0x3fd00000)) { /* x<1/4 */
      double temp_var_for_ext_2;
      double temp_var_for_tac_26, temp_var_for_tac_27, temp_var_for_tac_28;
      double temp_var_for_const_16;
      temp_var_for_tac_26 = x * y;

      temp_var_for_tac_27 = x + temp_var_for_tac_26;

      temp_var_for_tac_28 = one - temp_var_for_tac_27;

      temp_var_for_ext_2 = temp_var_for_tac_28;
      computeDMul((Addr)&temp_var_for_tac_26, {(Addr)&x, (Addr)&y},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:173:41");
      computeDAdd((Addr)&temp_var_for_tac_27,
                  {(Addr)&x, (Addr)&temp_var_for_tac_26},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:173:37");
      computeDSub(
          (Addr)&temp_var_for_tac_28,
          {(Addr) &(temp_var_for_const_16 = one), (Addr)&temp_var_for_tac_27},
          "/home/shijia/Public/testprogram/s_erfc.c_e.c:173:32");
      AssignD({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_28,
              "/home/shijia/Public/testprogram/s_erfc.c_e.c:173:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_2;
    } else {
      double temp_var_for_ext_3;
      double temp_var_for_tac_29;
      temp_var_for_tac_29 = x * y;

      temp_var_for_ext_3 = temp_var_for_tac_29;
      computeDMul((Addr)&temp_var_for_tac_29, {(Addr)&x, (Addr)&y},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:180:30");
      AssignD({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_29,
              "/home/shijia/Public/testprogram/s_erfc.c_e.c:180:26");
      ; // r
      /*(s)(r)(_)(_)(_)(tem)(_)(_)(_)(_)(_)(y)(x)*/
      r = temp_var_for_ext_3;
      AssignD({(Addr)&r}, (Addr)&temp_var_for_ext_3,
              "/home/shijia/Public/testprogram/s_erfc.c_e.c:182:9");
      ;
      double temp_var_for_tac_30;
      double temp_var_for_const_17;
      temp_var_for_tac_30 = x - half;

      r += temp_var_for_tac_30;
      ;
      double temp_var_for_ext_4;
      double temp_var_for_tac_32;
      double temp_var_for_const_18;
      temp_var_for_tac_32 = half - r;

      temp_var_for_ext_4 = temp_var_for_tac_32;
      computeDSub((Addr)&temp_var_for_tac_30,
                  {(Addr)&x, (Addr) &(temp_var_for_const_17 = half)},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:183:15");
      computeDSub((Addr)&temp_var_for_tac_32,
                  {(Addr) &(temp_var_for_const_18 = half), (Addr)&r},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:185:33");
      AssignD({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_32,
              "/home/shijia/Public/testprogram/s_erfc.c_e.c:185:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_4;
    }
  }
  if (ix < IC(0x3ff40000)) { /* 0.84375 <= |x| < 1.25 */
    double s2, s4, s6, P1, P2, P3, P4, Q1, Q2, Q3, Q4;

    double temp_var_for_tac_33;
    double temp_var_for_const_19, temp_var_for_const_20;
    double temp_var_for_callexp_0;

    temp_var_for_callexp_0 = fabs(x);
    temp_var_for_tac_33 = temp_var_for_callexp_0 - one;

    s = temp_var_for_tac_33;
    computeDSub((Addr)&temp_var_for_tac_33,
                {(Addr) &(temp_var_for_const_20 = temp_var_for_callexp_0),
                 (Addr) &(temp_var_for_const_19 = one)},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:195:27");
    AssignD({(Addr)&s}, (Addr)&temp_var_for_tac_33,
            "/home/shijia/Public/testprogram/s_erfc.c_e.c:195:7");
    ;
#ifdef DO_NOT_USE_THIS
    P = pa0 +
        s * (pa1 + s * (pa2 + s * (pa3 + s * (pa4 + s * (pa5 + s * pa6)))));
    Q = one +
        s * (qa1 + s * (qa2 + s * (qa3 + s * (qa4 + s * (qa5 + s * qa6)))));
#else
    double temp_var_for_tac_34, temp_var_for_tac_35;
    double temp_var_for_const_21, temp_var_for_const_22;
    temp_var_for_tac_34 = s * pa1;

    temp_var_for_tac_35 = pa0 + temp_var_for_tac_34;

    P1 = temp_var_for_tac_35;
    computeDMul((Addr)&temp_var_for_tac_34,
                {(Addr)&s, (Addr) &(temp_var_for_const_21 = pa1)},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:202:18");
    computeDAdd(
        (Addr)&temp_var_for_tac_35,
        {(Addr) &(temp_var_for_const_22 = pa0), (Addr)&temp_var_for_tac_34},
        "/home/shijia/Public/testprogram/s_erfc.c_e.c:202:14");
    AssignD({(Addr)&P1}, (Addr)&temp_var_for_tac_35,
            "/home/shijia/Public/testprogram/s_erfc.c_e.c:202:8");
    ;
    double temp_var_for_tac_36;
    temp_var_for_tac_36 = s * s;

    s2 = temp_var_for_tac_36;
    computeDMul((Addr)&temp_var_for_tac_36, {(Addr)&s, (Addr)&s},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:203:12");
    AssignD({(Addr)&s2}, (Addr)&temp_var_for_tac_36,
            "/home/shijia/Public/testprogram/s_erfc.c_e.c:203:8");
    ;
    double temp_var_for_tac_37, temp_var_for_tac_38;
    double temp_var_for_const_23, temp_var_for_const_24;
    temp_var_for_tac_37 = s * qa1;

    temp_var_for_tac_38 = one + temp_var_for_tac_37;

    Q1 = temp_var_for_tac_38;
    computeDMul((Addr)&temp_var_for_tac_37,
                {(Addr)&s, (Addr) &(temp_var_for_const_23 = qa1)},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:204:18");
    computeDAdd(
        (Addr)&temp_var_for_tac_38,
        {(Addr) &(temp_var_for_const_24 = one), (Addr)&temp_var_for_tac_37},
        "/home/shijia/Public/testprogram/s_erfc.c_e.c:204:14");
    AssignD({(Addr)&Q1}, (Addr)&temp_var_for_tac_38,
            "/home/shijia/Public/testprogram/s_erfc.c_e.c:204:8");
    ;
    double temp_var_for_tac_39;
    temp_var_for_tac_39 = s2 * s2;

    s4 = temp_var_for_tac_39;
    computeDMul((Addr)&temp_var_for_tac_39, {(Addr)&s2, (Addr)&s2},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:205:13");
    AssignD({(Addr)&s4}, (Addr)&temp_var_for_tac_39,
            "/home/shijia/Public/testprogram/s_erfc.c_e.c:205:8");
    ;
    double temp_var_for_tac_40, temp_var_for_tac_41;
    double temp_var_for_const_25, temp_var_for_const_26;
    temp_var_for_tac_40 = s * pa3;

    temp_var_for_tac_41 = pa2 + temp_var_for_tac_40;

    P2 = temp_var_for_tac_41;
    computeDMul((Addr)&temp_var_for_tac_40,
                {(Addr)&s, (Addr) &(temp_var_for_const_25 = pa3)},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:206:18");
    computeDAdd(
        (Addr)&temp_var_for_tac_41,
        {(Addr) &(temp_var_for_const_26 = pa2), (Addr)&temp_var_for_tac_40},
        "/home/shijia/Public/testprogram/s_erfc.c_e.c:206:14");
    AssignD({(Addr)&P2}, (Addr)&temp_var_for_tac_41,
            "/home/shijia/Public/testprogram/s_erfc.c_e.c:206:8");
    ;
    double temp_var_for_tac_42;
    temp_var_for_tac_42 = s4 * s2;

    s6 = temp_var_for_tac_42;
    computeDMul((Addr)&temp_var_for_tac_42, {(Addr)&s4, (Addr)&s2},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:207:13");
    AssignD({(Addr)&s6}, (Addr)&temp_var_for_tac_42,
            "/home/shijia/Public/testprogram/s_erfc.c_e.c:207:8");
    ;
    double temp_var_for_tac_43, temp_var_for_tac_44;
    double temp_var_for_const_27, temp_var_for_const_28;
    temp_var_for_tac_43 = s * qa3;

    temp_var_for_tac_44 = qa2 + temp_var_for_tac_43;

    Q2 = temp_var_for_tac_44;
    computeDMul((Addr)&temp_var_for_tac_43,
                {(Addr)&s, (Addr) &(temp_var_for_const_27 = qa3)},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:208:18");
    computeDAdd(
        (Addr)&temp_var_for_tac_44,
        {(Addr) &(temp_var_for_const_28 = qa2), (Addr)&temp_var_for_tac_43},
        "/home/shijia/Public/testprogram/s_erfc.c_e.c:208:14");
    AssignD({(Addr)&Q2}, (Addr)&temp_var_for_tac_44,
            "/home/shijia/Public/testprogram/s_erfc.c_e.c:208:8");
    ;
    double temp_var_for_tac_45, temp_var_for_tac_46;
    double temp_var_for_const_29, temp_var_for_const_30;
    temp_var_for_tac_45 = s * pa5;

    temp_var_for_tac_46 = pa4 + temp_var_for_tac_45;

    P3 = temp_var_for_tac_46;
    computeDMul((Addr)&temp_var_for_tac_45,
                {(Addr)&s, (Addr) &(temp_var_for_const_29 = pa5)},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:209:18");
    computeDAdd(
        (Addr)&temp_var_for_tac_46,
        {(Addr) &(temp_var_for_const_30 = pa4), (Addr)&temp_var_for_tac_45},
        "/home/shijia/Public/testprogram/s_erfc.c_e.c:209:14");
    AssignD({(Addr)&P3}, (Addr)&temp_var_for_tac_46,
            "/home/shijia/Public/testprogram/s_erfc.c_e.c:209:8");
    ;
    double temp_var_for_tac_47, temp_var_for_tac_48;
    double temp_var_for_const_31, temp_var_for_const_32;
    temp_var_for_tac_47 = s * qa5;

    temp_var_for_tac_48 = qa4 + temp_var_for_tac_47;

    Q3 = temp_var_for_tac_48;
    computeDMul((Addr)&temp_var_for_tac_47,
                {(Addr)&s, (Addr) &(temp_var_for_const_31 = qa5)},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:210:18");
    computeDAdd(
        (Addr)&temp_var_for_tac_48,
        {(Addr) &(temp_var_for_const_32 = qa4), (Addr)&temp_var_for_tac_47},
        "/home/shijia/Public/testprogram/s_erfc.c_e.c:210:14");
    AssignD({(Addr)&Q3}, (Addr)&temp_var_for_tac_48,
            "/home/shijia/Public/testprogram/s_erfc.c_e.c:210:8");
    ;
    double temp_var_for_const_33;
    P4 = pa6;
    AssignD({(Addr)&P4}, (Addr) &(temp_var_for_const_33 = pa6),
            "/home/shijia/Public/testprogram/s_erfc.c_e.c:211:8");
    ;
    double temp_var_for_const_34;
    Q4 = qa6;
    AssignD({(Addr)&Q4}, (Addr) &(temp_var_for_const_34 = qa6),
            "/home/shijia/Public/testprogram/s_erfc.c_e.c:212:8");
    ;
    double temp_var_for_tac_49, temp_var_for_tac_50, temp_var_for_tac_51,
        temp_var_for_tac_52, temp_var_for_tac_53, temp_var_for_tac_54;
    temp_var_for_tac_49 = s2 * P2;

    temp_var_for_tac_50 = P1 + temp_var_for_tac_49;

    temp_var_for_tac_51 = s4 * P3;

    temp_var_for_tac_52 = temp_var_for_tac_50 + temp_var_for_tac_51;

    temp_var_for_tac_53 = s6 * P4;

    temp_var_for_tac_54 = temp_var_for_tac_52 + temp_var_for_tac_53;

    P = temp_var_for_tac_54;
    computeDMul((Addr)&temp_var_for_tac_49, {(Addr)&s2, (Addr)&P2},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:213:17");
    computeDAdd((Addr)&temp_var_for_tac_50,
                {(Addr)&P1, (Addr)&temp_var_for_tac_49},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:213:12");
    computeDMul((Addr)&temp_var_for_tac_51, {(Addr)&s4, (Addr)&P3},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:213:27");
    computeDAdd((Addr)&temp_var_for_tac_52,
                {(Addr)&temp_var_for_tac_50, (Addr)&temp_var_for_tac_51},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:213:22");
    computeDMul((Addr)&temp_var_for_tac_53, {(Addr)&s6, (Addr)&P4},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:213:37");
    computeDAdd((Addr)&temp_var_for_tac_54,
                {(Addr)&temp_var_for_tac_52, (Addr)&temp_var_for_tac_53},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:213:32");
    AssignD({(Addr)&P}, (Addr)&temp_var_for_tac_54,
            "/home/shijia/Public/testprogram/s_erfc.c_e.c:213:7");
    ;
    double temp_var_for_tac_55, temp_var_for_tac_56, temp_var_for_tac_57,
        temp_var_for_tac_58, temp_var_for_tac_59, temp_var_for_tac_60;
    temp_var_for_tac_55 = s2 * Q2;

    temp_var_for_tac_56 = Q1 + temp_var_for_tac_55;

    temp_var_for_tac_57 = s4 * Q3;

    temp_var_for_tac_58 = temp_var_for_tac_56 + temp_var_for_tac_57;

    temp_var_for_tac_59 = s6 * Q4;

    temp_var_for_tac_60 = temp_var_for_tac_58 + temp_var_for_tac_59;

    Q = temp_var_for_tac_60;
    computeDMul((Addr)&temp_var_for_tac_55, {(Addr)&s2, (Addr)&Q2},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:214:17");
    computeDAdd((Addr)&temp_var_for_tac_56,
                {(Addr)&Q1, (Addr)&temp_var_for_tac_55},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:214:12");
    computeDMul((Addr)&temp_var_for_tac_57, {(Addr)&s4, (Addr)&Q3},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:214:27");
    computeDAdd((Addr)&temp_var_for_tac_58,
                {(Addr)&temp_var_for_tac_56, (Addr)&temp_var_for_tac_57},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:214:22");
    computeDMul((Addr)&temp_var_for_tac_59, {(Addr)&s6, (Addr)&Q4},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:214:37");
    computeDAdd((Addr)&temp_var_for_tac_60,
                {(Addr)&temp_var_for_tac_58, (Addr)&temp_var_for_tac_59},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:214:32");
    AssignD({(Addr)&Q}, (Addr)&temp_var_for_tac_60,
            "/home/shijia/Public/testprogram/s_erfc.c_e.c:214:7");
    ;
#endif
    if (hx >= 0) {
      double temp_var_for_tac_61;
      double temp_var_for_const_35, temp_var_for_const_36;
      temp_var_for_tac_61 = one - erx;

      z = temp_var_for_tac_61;
      computeDSub((Addr)&temp_var_for_tac_61,
                  {(Addr) &(temp_var_for_const_36 = one),
                   (Addr) &(temp_var_for_const_35 = erx)},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:217:15");
      AssignD({(Addr)&z}, (Addr)&temp_var_for_tac_61,
              "/home/shijia/Public/testprogram/s_erfc.c_e.c:217:9");
      ;
      double temp_var_for_ext_5;
      double temp_var_for_tac_62, temp_var_for_tac_63;
      temp_var_for_tac_62 = P / Q;

      temp_var_for_tac_63 = z - temp_var_for_tac_62;

      temp_var_for_ext_5 = temp_var_for_tac_63;
      computeDDiv((Addr)&temp_var_for_tac_62, {(Addr)&P, (Addr)&Q},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:219:34");
      computeDSub((Addr)&temp_var_for_tac_63,
                  {(Addr)&z, (Addr)&temp_var_for_tac_62},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:219:30");
      AssignD({(Addr)&temp_var_for_ext_5}, (Addr)&temp_var_for_tac_63,
              "/home/shijia/Public/testprogram/s_erfc.c_e.c:219:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_5;
    } else {
      double temp_var_for_tac_64, temp_var_for_tac_65;
      double temp_var_for_const_37;
      temp_var_for_tac_64 = P / Q;

      temp_var_for_tac_65 = erx + temp_var_for_tac_64;

      z = temp_var_for_tac_65;
      computeDDiv((Addr)&temp_var_for_tac_64, {(Addr)&P, (Addr)&Q},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:225:19");
      computeDAdd(
          (Addr)&temp_var_for_tac_65,
          {(Addr) &(temp_var_for_const_37 = erx), (Addr)&temp_var_for_tac_64},
          "/home/shijia/Public/testprogram/s_erfc.c_e.c:225:15");
      AssignD({(Addr)&z}, (Addr)&temp_var_for_tac_65,
              "/home/shijia/Public/testprogram/s_erfc.c_e.c:225:9");
      ;
      double temp_var_for_ext_6;
      double temp_var_for_tac_66;
      double temp_var_for_const_38;
      temp_var_for_tac_66 = one + z;

      temp_var_for_ext_6 = temp_var_for_tac_66;
      computeDAdd((Addr)&temp_var_for_tac_66,
                  {(Addr) &(temp_var_for_const_38 = one), (Addr)&z},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:227:32");
      AssignD({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_66,
              "/home/shijia/Public/testprogram/s_erfc.c_e.c:227:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_6;
    }
  }
  if (ix < IC(0x403c0000)) { /* |x|<28 */
    double temp_var_for_ext_7;
    double temp_var_for_const_39;
    double temp_var_for_callexp_1;

    temp_var_for_callexp_1 = fabs(x);
    temp_var_for_ext_7 = temp_var_for_callexp_1;
    AssignD({(Addr)&temp_var_for_ext_7},
            (Addr) &(temp_var_for_const_39 = temp_var_for_callexp_1),
            "/home/shijia/Public/testprogram/s_erfc.c_e.c:236:24");
    ; // x
    /*(Q)(P)(erx)(Q)(P)(6)(tem)(__ieee754_fabs(x))*/
    x = temp_var_for_ext_7;
    AssignD({(Addr)&x}, (Addr)&temp_var_for_ext_7,
            "/home/shijia/Public/testprogram/s_erfc.c_e.c:238:7");
    ;
    double temp_var_for_tac_67, temp_var_for_tac_68;
    double temp_var_for_const_40;
    temp_var_for_tac_67 = x * x;

    temp_var_for_tac_68 = one / temp_var_for_tac_67;

    s = temp_var_for_tac_68;
    computeDMul((Addr)&temp_var_for_tac_67, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:239:18");
    computeDDiv(
        (Addr)&temp_var_for_tac_68,
        {(Addr) &(temp_var_for_const_40 = one), (Addr)&temp_var_for_tac_67},
        "/home/shijia/Public/testprogram/s_erfc.c_e.c:239:13");
    AssignD({(Addr)&s}, (Addr)&temp_var_for_tac_68,
            "/home/shijia/Public/testprogram/s_erfc.c_e.c:239:7");
    ;
    if (ix < IC(0x4006DB6D)) { /* |x| < 1/.35 ~ 2.857143 */
#ifdef DO_NOT_USE_THIS
      R = ra0 +
          s * (ra1 +
               s * (ra2 +
                    s * (ra3 + s * (ra4 + s * (ra5 + s * (ra6 + s * ra7))))));
      S = one +
          s * (sa1 +
               s * (sa2 +
                    s * (sa3 +
                         s * (sa4 +
                              s * (sa5 + s * (sa6 + s * (sa7 + s * sa8)))))));
#else
      double R1, R2, R3, R4, S1, S2, S3, S4, s2, s4, s6, s8;

      double temp_var_for_tac_69, temp_var_for_tac_70;
      double temp_var_for_const_41, temp_var_for_const_42;
      temp_var_for_tac_69 = s * ra1;

      temp_var_for_tac_70 = ra0 + temp_var_for_tac_69;

      R1 = temp_var_for_tac_70;
      computeDMul((Addr)&temp_var_for_tac_69,
                  {(Addr)&s, (Addr) &(temp_var_for_const_41 = ra1)},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:255:20");
      computeDAdd(
          (Addr)&temp_var_for_tac_70,
          {(Addr) &(temp_var_for_const_42 = ra0), (Addr)&temp_var_for_tac_69},
          "/home/shijia/Public/testprogram/s_erfc.c_e.c:255:16");
      AssignD({(Addr)&R1}, (Addr)&temp_var_for_tac_70,
              "/home/shijia/Public/testprogram/s_erfc.c_e.c:255:10");
      ;
      double temp_var_for_tac_71;
      temp_var_for_tac_71 = s * s;

      s2 = temp_var_for_tac_71;
      computeDMul((Addr)&temp_var_for_tac_71, {(Addr)&s, (Addr)&s},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:256:14");
      AssignD({(Addr)&s2}, (Addr)&temp_var_for_tac_71,
              "/home/shijia/Public/testprogram/s_erfc.c_e.c:256:10");
      ;
      double temp_var_for_tac_72, temp_var_for_tac_73;
      double temp_var_for_const_43, temp_var_for_const_44;
      temp_var_for_tac_72 = s * sa1;

      temp_var_for_tac_73 = one + temp_var_for_tac_72;

      S1 = temp_var_for_tac_73;
      computeDMul((Addr)&temp_var_for_tac_72,
                  {(Addr)&s, (Addr) &(temp_var_for_const_43 = sa1)},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:257:20");
      computeDAdd(
          (Addr)&temp_var_for_tac_73,
          {(Addr) &(temp_var_for_const_44 = one), (Addr)&temp_var_for_tac_72},
          "/home/shijia/Public/testprogram/s_erfc.c_e.c:257:16");
      AssignD({(Addr)&S1}, (Addr)&temp_var_for_tac_73,
              "/home/shijia/Public/testprogram/s_erfc.c_e.c:257:10");
      ;
      double temp_var_for_tac_74;
      temp_var_for_tac_74 = s2 * s2;

      s4 = temp_var_for_tac_74;
      computeDMul((Addr)&temp_var_for_tac_74, {(Addr)&s2, (Addr)&s2},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:258:15");
      AssignD({(Addr)&s4}, (Addr)&temp_var_for_tac_74,
              "/home/shijia/Public/testprogram/s_erfc.c_e.c:258:10");
      ;
      double temp_var_for_tac_75, temp_var_for_tac_76;
      double temp_var_for_const_45, temp_var_for_const_46;
      temp_var_for_tac_75 = s * ra3;

      temp_var_for_tac_76 = ra2 + temp_var_for_tac_75;

      R2 = temp_var_for_tac_76;
      computeDMul((Addr)&temp_var_for_tac_75,
                  {(Addr)&s, (Addr) &(temp_var_for_const_45 = ra3)},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:259:20");
      computeDAdd(
          (Addr)&temp_var_for_tac_76,
          {(Addr) &(temp_var_for_const_46 = ra2), (Addr)&temp_var_for_tac_75},
          "/home/shijia/Public/testprogram/s_erfc.c_e.c:259:16");
      AssignD({(Addr)&R2}, (Addr)&temp_var_for_tac_76,
              "/home/shijia/Public/testprogram/s_erfc.c_e.c:259:10");
      ;
      double temp_var_for_tac_77;
      temp_var_for_tac_77 = s4 * s2;

      s6 = temp_var_for_tac_77;
      computeDMul((Addr)&temp_var_for_tac_77, {(Addr)&s4, (Addr)&s2},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:260:15");
      AssignD({(Addr)&s6}, (Addr)&temp_var_for_tac_77,
              "/home/shijia/Public/testprogram/s_erfc.c_e.c:260:10");
      ;
      double temp_var_for_tac_78, temp_var_for_tac_79;
      double temp_var_for_const_47, temp_var_for_const_48;
      temp_var_for_tac_78 = s * sa3;

      temp_var_for_tac_79 = sa2 + temp_var_for_tac_78;

      S2 = temp_var_for_tac_79;
      computeDMul((Addr)&temp_var_for_tac_78,
                  {(Addr)&s, (Addr) &(temp_var_for_const_47 = sa3)},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:261:20");
      computeDAdd(
          (Addr)&temp_var_for_tac_79,
          {(Addr) &(temp_var_for_const_48 = sa2), (Addr)&temp_var_for_tac_78},
          "/home/shijia/Public/testprogram/s_erfc.c_e.c:261:16");
      AssignD({(Addr)&S2}, (Addr)&temp_var_for_tac_79,
              "/home/shijia/Public/testprogram/s_erfc.c_e.c:261:10");
      ;
      double temp_var_for_tac_80;
      temp_var_for_tac_80 = s4 * s4;

      s8 = temp_var_for_tac_80;
      computeDMul((Addr)&temp_var_for_tac_80, {(Addr)&s4, (Addr)&s4},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:262:15");
      AssignD({(Addr)&s8}, (Addr)&temp_var_for_tac_80,
              "/home/shijia/Public/testprogram/s_erfc.c_e.c:262:10");
      ;
      double temp_var_for_tac_81, temp_var_for_tac_82;
      double temp_var_for_const_49, temp_var_for_const_50;
      temp_var_for_tac_81 = s * ra5;

      temp_var_for_tac_82 = ra4 + temp_var_for_tac_81;

      R3 = temp_var_for_tac_82;
      computeDMul((Addr)&temp_var_for_tac_81,
                  {(Addr)&s, (Addr) &(temp_var_for_const_49 = ra5)},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:263:20");
      computeDAdd(
          (Addr)&temp_var_for_tac_82,
          {(Addr) &(temp_var_for_const_50 = ra4), (Addr)&temp_var_for_tac_81},
          "/home/shijia/Public/testprogram/s_erfc.c_e.c:263:16");
      AssignD({(Addr)&R3}, (Addr)&temp_var_for_tac_82,
              "/home/shijia/Public/testprogram/s_erfc.c_e.c:263:10");
      ;
      double temp_var_for_tac_83, temp_var_for_tac_84;
      double temp_var_for_const_51, temp_var_for_const_52;
      temp_var_for_tac_83 = s * sa5;

      temp_var_for_tac_84 = sa4 + temp_var_for_tac_83;

      S3 = temp_var_for_tac_84;
      computeDMul((Addr)&temp_var_for_tac_83,
                  {(Addr)&s, (Addr) &(temp_var_for_const_51 = sa5)},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:264:20");
      computeDAdd(
          (Addr)&temp_var_for_tac_84,
          {(Addr) &(temp_var_for_const_52 = sa4), (Addr)&temp_var_for_tac_83},
          "/home/shijia/Public/testprogram/s_erfc.c_e.c:264:16");
      AssignD({(Addr)&S3}, (Addr)&temp_var_for_tac_84,
              "/home/shijia/Public/testprogram/s_erfc.c_e.c:264:10");
      ;
      double temp_var_for_tac_85, temp_var_for_tac_86;
      double temp_var_for_const_53, temp_var_for_const_54;
      temp_var_for_tac_85 = s * ra7;

      temp_var_for_tac_86 = ra6 + temp_var_for_tac_85;

      R4 = temp_var_for_tac_86;
      computeDMul((Addr)&temp_var_for_tac_85,
                  {(Addr)&s, (Addr) &(temp_var_for_const_53 = ra7)},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:265:20");
      computeDAdd(
          (Addr)&temp_var_for_tac_86,
          {(Addr) &(temp_var_for_const_54 = ra6), (Addr)&temp_var_for_tac_85},
          "/home/shijia/Public/testprogram/s_erfc.c_e.c:265:16");
      AssignD({(Addr)&R4}, (Addr)&temp_var_for_tac_86,
              "/home/shijia/Public/testprogram/s_erfc.c_e.c:265:10");
      ;
      double temp_var_for_tac_87, temp_var_for_tac_88;
      double temp_var_for_const_55, temp_var_for_const_56;
      temp_var_for_tac_87 = s * sa7;

      temp_var_for_tac_88 = sa6 + temp_var_for_tac_87;

      S4 = temp_var_for_tac_88;
      computeDMul((Addr)&temp_var_for_tac_87,
                  {(Addr)&s, (Addr) &(temp_var_for_const_55 = sa7)},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:266:20");
      computeDAdd(
          (Addr)&temp_var_for_tac_88,
          {(Addr) &(temp_var_for_const_56 = sa6), (Addr)&temp_var_for_tac_87},
          "/home/shijia/Public/testprogram/s_erfc.c_e.c:266:16");
      AssignD({(Addr)&S4}, (Addr)&temp_var_for_tac_88,
              "/home/shijia/Public/testprogram/s_erfc.c_e.c:266:10");
      ;
      double temp_var_for_tac_89, temp_var_for_tac_90, temp_var_for_tac_91,
          temp_var_for_tac_92, temp_var_for_tac_93, temp_var_for_tac_94;
      temp_var_for_tac_89 = s2 * R2;

      temp_var_for_tac_90 = R1 + temp_var_for_tac_89;

      temp_var_for_tac_91 = s4 * R3;

      temp_var_for_tac_92 = temp_var_for_tac_90 + temp_var_for_tac_91;

      temp_var_for_tac_93 = s6 * R4;

      temp_var_for_tac_94 = temp_var_for_tac_92 + temp_var_for_tac_93;

      R = temp_var_for_tac_94;
      computeDMul((Addr)&temp_var_for_tac_89, {(Addr)&s2, (Addr)&R2},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:267:19");
      computeDAdd((Addr)&temp_var_for_tac_90,
                  {(Addr)&R1, (Addr)&temp_var_for_tac_89},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:267:14");
      computeDMul((Addr)&temp_var_for_tac_91, {(Addr)&s4, (Addr)&R3},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:267:29");
      computeDAdd((Addr)&temp_var_for_tac_92,
                  {(Addr)&temp_var_for_tac_90, (Addr)&temp_var_for_tac_91},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:267:24");
      computeDMul((Addr)&temp_var_for_tac_93, {(Addr)&s6, (Addr)&R4},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:267:39");
      computeDAdd((Addr)&temp_var_for_tac_94,
                  {(Addr)&temp_var_for_tac_92, (Addr)&temp_var_for_tac_93},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:267:34");
      AssignD({(Addr)&R}, (Addr)&temp_var_for_tac_94,
              "/home/shijia/Public/testprogram/s_erfc.c_e.c:267:9");
      ;
      double temp_var_for_tac_95, temp_var_for_tac_96, temp_var_for_tac_97,
          temp_var_for_tac_98, temp_var_for_tac_99, temp_var_for_tac_100,
          temp_var_for_tac_101, temp_var_for_tac_102;
      double temp_var_for_const_57;
      temp_var_for_tac_95 = s2 * S2;

      temp_var_for_tac_96 = S1 + temp_var_for_tac_95;

      temp_var_for_tac_97 = s4 * S3;

      temp_var_for_tac_98 = temp_var_for_tac_96 + temp_var_for_tac_97;

      temp_var_for_tac_99 = s6 * S4;

      temp_var_for_tac_100 = temp_var_for_tac_98 + temp_var_for_tac_99;

      temp_var_for_tac_101 = s8 * sa8;

      temp_var_for_tac_102 = temp_var_for_tac_100 + temp_var_for_tac_101;

      S = temp_var_for_tac_102;
      computeDMul((Addr)&temp_var_for_tac_95, {(Addr)&s2, (Addr)&S2},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:268:19");
      computeDAdd((Addr)&temp_var_for_tac_96,
                  {(Addr)&S1, (Addr)&temp_var_for_tac_95},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:268:14");
      computeDMul((Addr)&temp_var_for_tac_97, {(Addr)&s4, (Addr)&S3},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:268:29");
      computeDAdd((Addr)&temp_var_for_tac_98,
                  {(Addr)&temp_var_for_tac_96, (Addr)&temp_var_for_tac_97},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:268:24");
      computeDMul((Addr)&temp_var_for_tac_99, {(Addr)&s6, (Addr)&S4},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:268:39");
      computeDAdd((Addr)&temp_var_for_tac_100,
                  {(Addr)&temp_var_for_tac_98, (Addr)&temp_var_for_tac_99},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:268:34");
      computeDMul((Addr)&temp_var_for_tac_101,
                  {(Addr)&s8, (Addr) &(temp_var_for_const_57 = sa8)},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:268:49");
      computeDAdd((Addr)&temp_var_for_tac_102,
                  {(Addr)&temp_var_for_tac_100, (Addr)&temp_var_for_tac_101},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:268:44");
      AssignD({(Addr)&S}, (Addr)&temp_var_for_tac_102,
              "/home/shijia/Public/testprogram/s_erfc.c_e.c:268:9");
      ;
#endif
    } else { /* |x| >= 1/.35 ~ 2.857143 */
      double R1, R2, R3, S1, S2, S3, S4, s2, s4, s6;

      if (hx < 0 && ix >= IC(0x40180000)) {
        double temp_var_for_ext_8;
        double temp_var_for_tac_103;
        double temp_var_for_const_58, temp_var_for_const_59;
        temp_var_for_tac_103 = two - tiny;

        temp_var_for_ext_8 = temp_var_for_tac_103;
        computeDSub((Addr)&temp_var_for_tac_103,
                    {(Addr) &(temp_var_for_const_59 = two),
                     (Addr) &(temp_var_for_const_58 = tiny)},
                    "/home/shijia/Public/testprogram/s_erfc.c_e.c:275:34");
        AssignD({(Addr)&temp_var_for_ext_8}, (Addr)&temp_var_for_tac_103,
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:275:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_8;
      }
/* x < -6 */
#ifdef DO_NOT_USE_THIS
      R = rb0 +
          s * (rb1 + s * (rb2 + s * (rb3 + s * (rb4 + s * (rb5 + s * rb6)))));
      S = one +
          s * (sb1 +
               s * (sb2 +
                    s * (sb3 + s * (sb4 + s * (sb5 + s * (sb6 + s * sb7))))));
#else
      double temp_var_for_tac_104, temp_var_for_tac_105;
      double temp_var_for_const_60, temp_var_for_const_61;
      temp_var_for_tac_104 = s * rb1;

      temp_var_for_tac_105 = rb0 + temp_var_for_tac_104;

      R1 = temp_var_for_tac_105;
      computeDMul((Addr)&temp_var_for_tac_104,
                  {(Addr)&s, (Addr) &(temp_var_for_const_60 = rb1)},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:290:20");
      computeDAdd(
          (Addr)&temp_var_for_tac_105,
          {(Addr) &(temp_var_for_const_61 = rb0), (Addr)&temp_var_for_tac_104},
          "/home/shijia/Public/testprogram/s_erfc.c_e.c:290:16");
      AssignD({(Addr)&R1}, (Addr)&temp_var_for_tac_105,
              "/home/shijia/Public/testprogram/s_erfc.c_e.c:290:10");
      ;
      double temp_var_for_tac_106;
      temp_var_for_tac_106 = s * s;

      s2 = temp_var_for_tac_106;
      computeDMul((Addr)&temp_var_for_tac_106, {(Addr)&s, (Addr)&s},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:291:14");
      AssignD({(Addr)&s2}, (Addr)&temp_var_for_tac_106,
              "/home/shijia/Public/testprogram/s_erfc.c_e.c:291:10");
      ;
      double temp_var_for_tac_107, temp_var_for_tac_108;
      double temp_var_for_const_62, temp_var_for_const_63;
      temp_var_for_tac_107 = s * sb1;

      temp_var_for_tac_108 = one + temp_var_for_tac_107;

      S1 = temp_var_for_tac_108;
      computeDMul((Addr)&temp_var_for_tac_107,
                  {(Addr)&s, (Addr) &(temp_var_for_const_62 = sb1)},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:292:20");
      computeDAdd(
          (Addr)&temp_var_for_tac_108,
          {(Addr) &(temp_var_for_const_63 = one), (Addr)&temp_var_for_tac_107},
          "/home/shijia/Public/testprogram/s_erfc.c_e.c:292:16");
      AssignD({(Addr)&S1}, (Addr)&temp_var_for_tac_108,
              "/home/shijia/Public/testprogram/s_erfc.c_e.c:292:10");
      ;
      double temp_var_for_tac_109;
      temp_var_for_tac_109 = s2 * s2;

      s4 = temp_var_for_tac_109;
      computeDMul((Addr)&temp_var_for_tac_109, {(Addr)&s2, (Addr)&s2},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:293:15");
      AssignD({(Addr)&s4}, (Addr)&temp_var_for_tac_109,
              "/home/shijia/Public/testprogram/s_erfc.c_e.c:293:10");
      ;
      double temp_var_for_tac_110, temp_var_for_tac_111;
      double temp_var_for_const_64, temp_var_for_const_65;
      temp_var_for_tac_110 = s * rb3;

      temp_var_for_tac_111 = rb2 + temp_var_for_tac_110;

      R2 = temp_var_for_tac_111;
      computeDMul((Addr)&temp_var_for_tac_110,
                  {(Addr)&s, (Addr) &(temp_var_for_const_64 = rb3)},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:294:20");
      computeDAdd(
          (Addr)&temp_var_for_tac_111,
          {(Addr) &(temp_var_for_const_65 = rb2), (Addr)&temp_var_for_tac_110},
          "/home/shijia/Public/testprogram/s_erfc.c_e.c:294:16");
      AssignD({(Addr)&R2}, (Addr)&temp_var_for_tac_111,
              "/home/shijia/Public/testprogram/s_erfc.c_e.c:294:10");
      ;
      double temp_var_for_tac_112;
      temp_var_for_tac_112 = s4 * s2;

      s6 = temp_var_for_tac_112;
      computeDMul((Addr)&temp_var_for_tac_112, {(Addr)&s4, (Addr)&s2},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:295:15");
      AssignD({(Addr)&s6}, (Addr)&temp_var_for_tac_112,
              "/home/shijia/Public/testprogram/s_erfc.c_e.c:295:10");
      ;
      double temp_var_for_tac_113, temp_var_for_tac_114;
      double temp_var_for_const_66, temp_var_for_const_67;
      temp_var_for_tac_113 = s * sb3;

      temp_var_for_tac_114 = sb2 + temp_var_for_tac_113;

      S2 = temp_var_for_tac_114;
      computeDMul((Addr)&temp_var_for_tac_113,
                  {(Addr)&s, (Addr) &(temp_var_for_const_66 = sb3)},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:296:20");
      computeDAdd(
          (Addr)&temp_var_for_tac_114,
          {(Addr) &(temp_var_for_const_67 = sb2), (Addr)&temp_var_for_tac_113},
          "/home/shijia/Public/testprogram/s_erfc.c_e.c:296:16");
      AssignD({(Addr)&S2}, (Addr)&temp_var_for_tac_114,
              "/home/shijia/Public/testprogram/s_erfc.c_e.c:296:10");
      ;
      double temp_var_for_tac_115, temp_var_for_tac_116;
      double temp_var_for_const_68, temp_var_for_const_69;
      temp_var_for_tac_115 = s * rb5;

      temp_var_for_tac_116 = rb4 + temp_var_for_tac_115;

      R3 = temp_var_for_tac_116;
      computeDMul((Addr)&temp_var_for_tac_115,
                  {(Addr)&s, (Addr) &(temp_var_for_const_68 = rb5)},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:297:20");
      computeDAdd(
          (Addr)&temp_var_for_tac_116,
          {(Addr) &(temp_var_for_const_69 = rb4), (Addr)&temp_var_for_tac_115},
          "/home/shijia/Public/testprogram/s_erfc.c_e.c:297:16");
      AssignD({(Addr)&R3}, (Addr)&temp_var_for_tac_116,
              "/home/shijia/Public/testprogram/s_erfc.c_e.c:297:10");
      ;
      double temp_var_for_tac_117, temp_var_for_tac_118;
      double temp_var_for_const_70, temp_var_for_const_71;
      temp_var_for_tac_117 = s * sb5;

      temp_var_for_tac_118 = sb4 + temp_var_for_tac_117;

      S3 = temp_var_for_tac_118;
      computeDMul((Addr)&temp_var_for_tac_117,
                  {(Addr)&s, (Addr) &(temp_var_for_const_70 = sb5)},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:298:20");
      computeDAdd(
          (Addr)&temp_var_for_tac_118,
          {(Addr) &(temp_var_for_const_71 = sb4), (Addr)&temp_var_for_tac_117},
          "/home/shijia/Public/testprogram/s_erfc.c_e.c:298:16");
      AssignD({(Addr)&S3}, (Addr)&temp_var_for_tac_118,
              "/home/shijia/Public/testprogram/s_erfc.c_e.c:298:10");
      ;
      double temp_var_for_tac_119, temp_var_for_tac_120;
      double temp_var_for_const_72, temp_var_for_const_73;
      temp_var_for_tac_119 = s * sb7;

      temp_var_for_tac_120 = sb6 + temp_var_for_tac_119;

      S4 = temp_var_for_tac_120;
      computeDMul((Addr)&temp_var_for_tac_119,
                  {(Addr)&s, (Addr) &(temp_var_for_const_72 = sb7)},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:299:20");
      computeDAdd(
          (Addr)&temp_var_for_tac_120,
          {(Addr) &(temp_var_for_const_73 = sb6), (Addr)&temp_var_for_tac_119},
          "/home/shijia/Public/testprogram/s_erfc.c_e.c:299:16");
      AssignD({(Addr)&S4}, (Addr)&temp_var_for_tac_120,
              "/home/shijia/Public/testprogram/s_erfc.c_e.c:299:10");
      ;
      double temp_var_for_tac_121, temp_var_for_tac_122, temp_var_for_tac_123,
          temp_var_for_tac_124, temp_var_for_tac_125, temp_var_for_tac_126;
      double temp_var_for_const_74;
      temp_var_for_tac_121 = s2 * R2;

      temp_var_for_tac_122 = R1 + temp_var_for_tac_121;

      temp_var_for_tac_123 = s4 * R3;

      temp_var_for_tac_124 = temp_var_for_tac_122 + temp_var_for_tac_123;

      temp_var_for_tac_125 = s6 * rb6;

      temp_var_for_tac_126 = temp_var_for_tac_124 + temp_var_for_tac_125;

      R = temp_var_for_tac_126;
      computeDMul((Addr)&temp_var_for_tac_121, {(Addr)&s2, (Addr)&R2},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:300:19");
      computeDAdd((Addr)&temp_var_for_tac_122,
                  {(Addr)&R1, (Addr)&temp_var_for_tac_121},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:300:14");
      computeDMul((Addr)&temp_var_for_tac_123, {(Addr)&s4, (Addr)&R3},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:300:29");
      computeDAdd((Addr)&temp_var_for_tac_124,
                  {(Addr)&temp_var_for_tac_122, (Addr)&temp_var_for_tac_123},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:300:24");
      computeDMul((Addr)&temp_var_for_tac_125,
                  {(Addr)&s6, (Addr) &(temp_var_for_const_74 = rb6)},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:300:39");
      computeDAdd((Addr)&temp_var_for_tac_126,
                  {(Addr)&temp_var_for_tac_124, (Addr)&temp_var_for_tac_125},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:300:34");
      AssignD({(Addr)&R}, (Addr)&temp_var_for_tac_126,
              "/home/shijia/Public/testprogram/s_erfc.c_e.c:300:9");
      ;
      double temp_var_for_tac_127, temp_var_for_tac_128, temp_var_for_tac_129,
          temp_var_for_tac_130, temp_var_for_tac_131, temp_var_for_tac_132;
      temp_var_for_tac_127 = s2 * S2;

      temp_var_for_tac_128 = S1 + temp_var_for_tac_127;

      temp_var_for_tac_129 = s4 * S3;

      temp_var_for_tac_130 = temp_var_for_tac_128 + temp_var_for_tac_129;

      temp_var_for_tac_131 = s6 * S4;

      temp_var_for_tac_132 = temp_var_for_tac_130 + temp_var_for_tac_131;

      S = temp_var_for_tac_132;
      computeDMul((Addr)&temp_var_for_tac_127, {(Addr)&s2, (Addr)&S2},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:301:19");
      computeDAdd((Addr)&temp_var_for_tac_128,
                  {(Addr)&S1, (Addr)&temp_var_for_tac_127},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:301:14");
      computeDMul((Addr)&temp_var_for_tac_129, {(Addr)&s4, (Addr)&S3},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:301:29");
      computeDAdd((Addr)&temp_var_for_tac_130,
                  {(Addr)&temp_var_for_tac_128, (Addr)&temp_var_for_tac_129},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:301:24");
      computeDMul((Addr)&temp_var_for_tac_131, {(Addr)&s6, (Addr)&S4},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:301:39");
      computeDAdd((Addr)&temp_var_for_tac_132,
                  {(Addr)&temp_var_for_tac_130, (Addr)&temp_var_for_tac_131},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:301:34");
      AssignD({(Addr)&S}, (Addr)&temp_var_for_tac_132,
              "/home/shijia/Public/testprogram/s_erfc.c_e.c:301:9");
      ;
#endif
    }
    z = x;
    AssignD({(Addr)&z}, (Addr)&x,
            "/home/shijia/Public/testprogram/s_erfc.c_e.c:304:7");
    ;
    SET_LOW_WORD(z, 0);
    double temp_var_for_tac_133, temp_var_for_tac_134, temp_var_for_tac_135,
        temp_var_for_tac_136, temp_var_for_tac_137, temp_var_for_tac_138,
        temp_var_for_tac_139, temp_var_for_tac_140, temp_var_for_tac_141;
    double temp_var_for_const_75, temp_var_for_const_76, temp_var_for_const_77,
        temp_var_for_const_78;
    double temp_var_for_callexp_2;

    double temp_var_for_callexp_3;

    temp_var_for_tac_133 = 0.0 - z;

    temp_var_for_tac_134 = temp_var_for_tac_133 * z;

    temp_var_for_tac_135 = temp_var_for_tac_134 - 0.5625;

    temp_var_for_callexp_2 = __ieee754_exp(temp_var_for_tac_135);
    temp_var_for_tac_136 = z - x;

    temp_var_for_tac_137 = z + x;

    temp_var_for_tac_138 = temp_var_for_tac_136 * temp_var_for_tac_137;

    temp_var_for_tac_139 = R / S;

    temp_var_for_tac_140 = temp_var_for_tac_138 + temp_var_for_tac_139;

    temp_var_for_callexp_3 = __ieee754_exp(temp_var_for_tac_140);
    temp_var_for_tac_141 = temp_var_for_callexp_2 * temp_var_for_callexp_3;

    r = temp_var_for_tac_141;
    computeDSub((Addr)&temp_var_for_tac_133,
                {(Addr) &(temp_var_for_const_75 = 0.0), (Addr)&z},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:306:28");
    computeDMul((Addr)&temp_var_for_tac_134,
                {(Addr)&temp_var_for_tac_133, (Addr)&z},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:306:33");
    computeDSub(
        (Addr)&temp_var_for_tac_135,
        {(Addr)&temp_var_for_tac_134, (Addr) &(temp_var_for_const_76 = 0.5625)},
        "/home/shijia/Public/testprogram/s_erfc.c_e.c:306:37");
    computeDSub((Addr)&temp_var_for_tac_136, {(Addr)&z, (Addr)&x},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:307:26");
    computeDAdd((Addr)&temp_var_for_tac_137, {(Addr)&z, (Addr)&x},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:307:36");
    computeDMul((Addr)&temp_var_for_tac_138,
                {(Addr)&temp_var_for_tac_136, (Addr)&temp_var_for_tac_137},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:307:31");
    computeDDiv((Addr)&temp_var_for_tac_139, {(Addr)&R, (Addr)&S},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:307:45");
    computeDAdd((Addr)&temp_var_for_tac_140,
                {(Addr)&temp_var_for_tac_138, (Addr)&temp_var_for_tac_139},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:307:41");
    computeDMul((Addr)&temp_var_for_tac_141,
                {(Addr) &(temp_var_for_const_78 = temp_var_for_callexp_2),
                 (Addr) &(temp_var_for_const_77 = temp_var_for_callexp_3)},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:306:47");
    AssignD({(Addr)&r}, (Addr)&temp_var_for_tac_141,
            "/home/shijia/Public/testprogram/s_erfc.c_e.c:306:7");
    ;
    if (hx > 0) {
      double temp_var_for_ext_9;
      double temp_var_for_tac_142;
      temp_var_for_tac_142 = r / x;

      temp_var_for_ext_9 = temp_var_for_tac_142;
      computeDDiv((Addr)&temp_var_for_tac_142, {(Addr)&r, (Addr)&x},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:310:30");
      AssignD({(Addr)&temp_var_for_ext_9}, (Addr)&temp_var_for_tac_142,
              "/home/shijia/Public/testprogram/s_erfc.c_e.c:310:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_9;
    }

    else {
      double temp_var_for_ext_10;
      double temp_var_for_tac_143, temp_var_for_tac_144;
      double temp_var_for_const_79;
      temp_var_for_tac_143 = r / x;

      temp_var_for_tac_144 = two - temp_var_for_tac_143;

      temp_var_for_ext_10 = temp_var_for_tac_144;
      computeDDiv((Addr)&temp_var_for_tac_143, {(Addr)&r, (Addr)&x},
                  "/home/shijia/Public/testprogram/s_erfc.c_e.c:319:37");
      computeDSub(
          (Addr)&temp_var_for_tac_144,
          {(Addr) &(temp_var_for_const_79 = two), (Addr)&temp_var_for_tac_143},
          "/home/shijia/Public/testprogram/s_erfc.c_e.c:319:33");
      AssignD({(Addr)&temp_var_for_ext_10}, (Addr)&temp_var_for_tac_144,
              "/home/shijia/Public/testprogram/s_erfc.c_e.c:319:27");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_10", (Addr)&temp_var_for_ext_10));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_10;
    }
  }
  if (hx > 0) {
    double temp_var_for_ext_11;
    double temp_var_for_tac_145;
    double temp_var_for_const_80, temp_var_for_const_81;
    temp_var_for_tac_145 = tiny * tiny;

    temp_var_for_ext_11 = temp_var_for_tac_145;
    computeDMul((Addr)&temp_var_for_tac_145,
                {(Addr) &(temp_var_for_const_81 = tiny),
                 (Addr) &(temp_var_for_const_80 = tiny)},
                "/home/shijia/Public/testprogram/s_erfc.c_e.c:328:32");
    AssignD({(Addr)&temp_var_for_ext_11}, (Addr)&temp_var_for_tac_145,
            "/home/shijia/Public/testprogram/s_erfc.c_e.c:328:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_11", (Addr)&temp_var_for_ext_11));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_11;
  }

  double temp_var_for_ext_12;
  double temp_var_for_tac_146;
  double temp_var_for_const_82, temp_var_for_const_83;
  temp_var_for_tac_146 = two - tiny;

  temp_var_for_ext_12 = temp_var_for_tac_146;
  computeDSub((Addr)&temp_var_for_tac_146,
              {(Addr) &(temp_var_for_const_83 = two),
               (Addr) &(temp_var_for_const_82 = tiny)},
              "/home/shijia/Public/testprogram/s_erfc.c_e.c:336:29");
  AssignD({(Addr)&temp_var_for_ext_12}, (Addr)&temp_var_for_tac_146,
          "/home/shijia/Public/testprogram/s_erfc.c_e.c:336:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_12", (Addr)&temp_var_for_ext_12));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_12;
}

__typeof(__erfc) erfc __attribute__((weak, alias("__erfc")));
#ifdef __NO_LONG_DOUBLE_MATH
__typeof(__erfcl) __erfcl __attribute__((alias("__erfc")));
__typeof(__erfcl) erfcl __attribute__((weak, alias("__erfc")));
#endif
