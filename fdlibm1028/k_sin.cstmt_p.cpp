#include "../ScDebug/scdebug.h"
/* @(#)k_sin.c 1.3 95/01/18 */
/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunSoft, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 */

/* __kernel_sin( x, y, iy)
 * kernel sin function on [-pi/4, pi/4], pi/4 ~ 0.7854
 * Input x is assumed to be bounded by ~pi/4 in magnitude.
 * Input y is the tail of x.
 * Input iy indicates whether y is 0. (if iy=0, y assume to be 0).
 *
 * Algorithm
 *	1. Since sin(-x) = -sin(x), we need only to consider positive x.
 *	2. if x < 2^-27 (hx<0x3e400000 0), return x with inexact if x!=0.
 *	3. sin(x) is approximated by a polynomial of degree 13 on
 *	   [0,pi/4]
 *		  	         3            13
 *	   	sin(x) ~ x + S1*x + ... + S6*x
 *	   where
 *
 * 	|sin(x)         2     4     6     8     10     12  |     -58
 * 	|----- - (1+S1*x +S2*x +S3*x +S4*x +S5*x  +S6*x   )| <= 2
 * 	|  x 					           |
 *
 *	4. sin(x+y) = sin(x) + sin'(x')*y
 *		    ~ sin(x) + (1-x*x/2)*y
 *	   For better accuracy, let
 *		     3      2      2      2      2
 *		r = x *(S2+x *(S3+x *(S4+x *(S5+x *S6))))
 *	   then                   3    2
 *		sin(x) = x + (S1*x + (x *(r-y/2)+y))
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

double __kernel_sin(double x, double y, int iy) {
  double z, r, v;
  int32_t ix;

  static const double half =
      5.00000000000000000000e-01; /* 0x3FE00000, 0x00000000 */
  static const double S1 = (0.0 - 1.66666666666666324348e-01);
  double temp_var_for_const_0, temp_var_for_const_1;
  ; /* 0xBFC55555, 0x55555549 */
  static const double S2 =
      8.33333333332248946124e-03; /* 0x3F811111, 0x1110F8A6 */
  static const double S3 = (0.0 - 1.98412698298579493134e-04);
  double temp_var_for_const_2, temp_var_for_const_3;
  double temp_var_for_tac_0;
  computeDSub((Addr)&temp_var_for_tac_0,
              {(Addr) &(temp_var_for_const_1 = 0.0),
               (Addr) &(temp_var_for_const_0 = 1.66666666666666324348e-01)},
              "/home/shijia/Public/testprogram/k_sin.c_e.c:56:12");
  ; /* 0xBF2A01A0, 0x19C161D5 */
  static const double S4 =
      2.75573137070700676789e-06; /* 0x3EC71DE3, 0x57B1FE7D */
  static const double S5 = (0.0 - 2.50507602534068634195e-08);
  double temp_var_for_const_4, temp_var_for_const_5;
  double temp_var_for_tac_1;
  computeDSub((Addr)&temp_var_for_tac_1,
              {(Addr) &(temp_var_for_const_3 = 0.0),
               (Addr) &(temp_var_for_const_2 = 1.98412698298579493134e-04)},
              "/home/shijia/Public/testprogram/k_sin.c_e.c:60:12");
  ; /* 0xBE5AE5E6, 0x8A2B9CEB */
  static const double S6 =
      1.58969099521155010221e-10; /* 0x3DE5D93A, 0x5ACFD57C */

  GET_HIGH_WORD(ix, x);
  ix &= IC(0x7fffffff);    /* high word of x */
  if (ix < IC(0x3e400000)) /* |x| < 2**-27 */
  {
    if ((int32_t)x == 0)
      return x; /* generate inexact */
  }
  z = x * x;
  double temp_var_for_tac_2;
  computeDSub((Addr)&temp_var_for_tac_2,
              {(Addr) &(temp_var_for_const_5 = 0.0),
               (Addr) &(temp_var_for_const_4 = 2.50507602534068634195e-08)},
              "/home/shijia/Public/testprogram/k_sin.c_e.c:71:9");
  computeDMul((Addr)&z, {(Addr)&x, (Addr)&x},
              "/home/shijia/Public/testprogram/k_sin.c_e.c:71:5");
  v = z * x;
  computeDMul((Addr)&v, {(Addr)&z, (Addr)&x},
              "/home/shijia/Public/testprogram/k_sin.c_e.c:72:5");
  r = S2 + z * (S3 + z * (S4 + z * (S5 + z * S6)));
  double temp_var_for_const_6, temp_var_for_const_7, temp_var_for_const_8,
      temp_var_for_const_9, temp_var_for_const_10;
  double temp_var_for_tac_3, temp_var_for_tac_4, temp_var_for_tac_5,
      temp_var_for_tac_6, temp_var_for_tac_7, temp_var_for_tac_8,
      temp_var_for_tac_9;
  computeDMul((Addr)&temp_var_for_tac_3,
              {(Addr)&z, (Addr) &(temp_var_for_const_6 = S6)},
              "/home/shijia/Public/testprogram/k_sin.c_e.c:73:40");
  computeDAdd((Addr)&temp_var_for_tac_4,
              {(Addr) &(temp_var_for_const_7 = S5), (Addr)&temp_var_for_tac_3},
              "/home/shijia/Public/testprogram/k_sin.c_e.c:73:34");
  computeDMul((Addr)&temp_var_for_tac_5, {(Addr)&z, (Addr)&temp_var_for_tac_4},
              "/home/shijia/Public/testprogram/k_sin.c_e.c:73:30");
  computeDAdd((Addr)&temp_var_for_tac_6,
              {(Addr) &(temp_var_for_const_8 = S4), (Addr)&temp_var_for_tac_5},
              "/home/shijia/Public/testprogram/k_sin.c_e.c:73:24");
  computeDMul((Addr)&temp_var_for_tac_7, {(Addr)&z, (Addr)&temp_var_for_tac_6},
              "/home/shijia/Public/testprogram/k_sin.c_e.c:73:20");
  computeDAdd((Addr)&temp_var_for_tac_8,
              {(Addr) &(temp_var_for_const_9 = S3), (Addr)&temp_var_for_tac_7},
              "/home/shijia/Public/testprogram/k_sin.c_e.c:73:14");
  computeDMul((Addr)&temp_var_for_tac_9, {(Addr)&z, (Addr)&temp_var_for_tac_8},
              "/home/shijia/Public/testprogram/k_sin.c_e.c:73:10");
  computeDAdd((Addr)&r,
              {(Addr) &(temp_var_for_const_10 = S2), (Addr)&temp_var_for_tac_9},
              "/home/shijia/Public/testprogram/k_sin.c_e.c:73:5");
  if (iy == 0) {
    double temp_var_for_ext_0;
    temp_var_for_ext_0 = x + v * (S1 + z * r);
    double temp_var_for_const_11;
    double temp_var_for_tac_10, temp_var_for_tac_11, temp_var_for_tac_12;
    computeDMul((Addr)&temp_var_for_tac_10, {(Addr)&z, (Addr)&r},
                "/home/shijia/Public/testprogram/k_sin.c_e.c:76:38");
    computeDAdd(
        (Addr)&temp_var_for_tac_11,
        {(Addr) &(temp_var_for_const_11 = S1), (Addr)&temp_var_for_tac_10},
        "/home/shijia/Public/testprogram/k_sin.c_e.c:76:32");
    computeDMul((Addr)&temp_var_for_tac_12,
                {(Addr)&v, (Addr)&temp_var_for_tac_11},
                "/home/shijia/Public/testprogram/k_sin.c_e.c:76:28");
    computeDAdd((Addr)&temp_var_for_ext_0,
                {(Addr)&x, (Addr)&temp_var_for_tac_12},
                "/home/shijia/Public/testprogram/k_sin.c_e.c:76:24");
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  else {
    double temp_var_for_ext_1;
    temp_var_for_ext_1 = x - ((z * (half * y - v * r) - y) - v * S1);
    double temp_var_for_const_12, temp_var_for_const_13;
    double temp_var_for_tac_13, temp_var_for_tac_14, temp_var_for_tac_15,
        temp_var_for_tac_16, temp_var_for_tac_17, temp_var_for_tac_18,
        temp_var_for_tac_19;
    computeDMul((Addr)&temp_var_for_tac_13,
                {(Addr) &(temp_var_for_const_12 = half), (Addr)&y},
                "/home/shijia/Public/testprogram/k_sin.c_e.c:84:50");
    computeDMul((Addr)&temp_var_for_tac_14, {(Addr)&v, (Addr)&r},
                "/home/shijia/Public/testprogram/k_sin.c_e.c:84:46");
    computeDSub((Addr)&temp_var_for_tac_15,
                {(Addr)&temp_var_for_tac_13, (Addr)&temp_var_for_tac_14},
                "/home/shijia/Public/testprogram/k_sin.c_e.c:84:34");
    computeDMul((Addr)&temp_var_for_tac_16,
                {(Addr)&z, (Addr)&temp_var_for_tac_15},
                "/home/shijia/Public/testprogram/k_sin.c_e.c:84:55");
    computeDSub((Addr)&temp_var_for_tac_17,
                {(Addr)&temp_var_for_tac_16, (Addr)&y},
                "/home/shijia/Public/testprogram/k_sin.c_e.c:84:64");
    computeDMul((Addr)&temp_var_for_tac_18,
                {(Addr)&v, (Addr) &(temp_var_for_const_13 = S1)},
                "/home/shijia/Public/testprogram/k_sin.c_e.c:84:60");
    computeDSub((Addr)&temp_var_for_tac_19,
                {(Addr)&temp_var_for_tac_17, (Addr)&temp_var_for_tac_18},
                "/home/shijia/Public/testprogram/k_sin.c_e.c:84:28");
    computeDSub((Addr)&temp_var_for_ext_1,
                {(Addr)&x, (Addr)&temp_var_for_tac_19},
                "/home/shijia/Public/testprogram/k_sin.c_e.c:84:24");
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }
}
