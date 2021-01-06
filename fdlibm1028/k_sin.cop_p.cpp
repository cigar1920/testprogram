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
  static const double S1 =
      (double temp_var_for_tac_0;
       double temp_var_for_const_0, temp_var_for_const_1;
       temp_var_for_tac_0 = 0.0 - 1.66666666666666324348e-01;

       ); /* 0xBFC55555, 0x55555549 */
  static const double S2 =
      8.33333333332248946124e-03; /* 0x3F811111, 0x1110F8A6 */
  static const double S3 =
      (double temp_var_for_tac_1;
       double temp_var_for_const_2, temp_var_for_const_3;
       temp_var_for_tac_1 = 0.0 - 1.98412698298579493134e-04;

       ); /* 0xBF2A01A0, 0x19C161D5 */
  static const double S4 =
      2.75573137070700676789e-06; /* 0x3EC71DE3, 0x57B1FE7D */
  static const double S5 =
      (double temp_var_for_tac_2;
       double temp_var_for_const_4, temp_var_for_const_5;
       temp_var_for_tac_2 = 0.0 - 2.50507602534068634195e-08;

       ); /* 0xBE5AE5E6, 0x8A2B9CEB */
  static const double S6 =
      1.58969099521155010221e-10; /* 0x3DE5D93A, 0x5ACFD57C */

  GET_HIGH_WORD(ix, x);
  ix &= IC(0x7fffffff);    /* high word of x */
  if (ix < IC(0x3e400000)) /* |x| < 2**-27 */
  {
    if ((int32_t)x == 0) {
      double temp_var_for_ext_0;
      temp_var_for_ext_0 = x;
      computeDSub((Addr)&temp_var_for_tac_0,
                  {(Addr) &(temp_var_for_const_1 = 0.0),
                   (Addr) &(temp_var_for_const_0 = 1.66666666666666324348e-01)},
                  "/home/shijia/Public/testprogram/k_sin.c_e.c:52:12");
      computeDSub((Addr)&temp_var_for_tac_1,
                  {(Addr) &(temp_var_for_const_3 = 0.0),
                   (Addr) &(temp_var_for_const_2 = 1.98412698298579493134e-04)},
                  "/home/shijia/Public/testprogram/k_sin.c_e.c:56:12");
      computeDSub((Addr)&temp_var_for_tac_2,
                  {(Addr) &(temp_var_for_const_5 = 0.0),
                   (Addr) &(temp_var_for_const_4 = 2.50507602534068634195e-08)},
                  "/home/shijia/Public/testprogram/k_sin.c_e.c:60:12");
      AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&x,
              "/home/shijia/Public/testprogram/k_sin.c_e.c:70:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_0;
    }
    /* generate inexact */
  }
  double temp_var_for_tac_3;
  temp_var_for_tac_3 = x * x;

  z = temp_var_for_tac_3;
  computeDMul((Addr)&temp_var_for_tac_3, {(Addr)&x, (Addr)&x},
              "/home/shijia/Public/testprogram/k_sin.c_e.c:78:9");
  AssignD({(Addr)&z}, (Addr)&temp_var_for_tac_3,
          "/home/shijia/Public/testprogram/k_sin.c_e.c:78:5");
  ;
  double temp_var_for_tac_4;
  temp_var_for_tac_4 = z * x;

  v = temp_var_for_tac_4;
  computeDMul((Addr)&temp_var_for_tac_4, {(Addr)&z, (Addr)&x},
              "/home/shijia/Public/testprogram/k_sin.c_e.c:79:9");
  AssignD({(Addr)&v}, (Addr)&temp_var_for_tac_4,
          "/home/shijia/Public/testprogram/k_sin.c_e.c:79:5");
  ;
  double temp_var_for_tac_5, temp_var_for_tac_6, temp_var_for_tac_7,
      temp_var_for_tac_8, temp_var_for_tac_9, temp_var_for_tac_10,
      temp_var_for_tac_11, temp_var_for_tac_12;
  double temp_var_for_const_6, temp_var_for_const_7, temp_var_for_const_8,
      temp_var_for_const_9, temp_var_for_const_10;
  temp_var_for_tac_5 = z * S6;

  temp_var_for_tac_6 = S5 + temp_var_for_tac_5;

  temp_var_for_tac_7 = z * temp_var_for_tac_6;

  temp_var_for_tac_8 = S4 + temp_var_for_tac_7;

  temp_var_for_tac_9 = z * temp_var_for_tac_8;

  temp_var_for_tac_10 = S3 + temp_var_for_tac_9;

  temp_var_for_tac_11 = z * temp_var_for_tac_10;

  temp_var_for_tac_12 = S2 + temp_var_for_tac_11;

  r = temp_var_for_tac_12;
  computeDMul((Addr)&temp_var_for_tac_5,
              {(Addr)&z, (Addr) &(temp_var_for_const_6 = S6)},
              "/home/shijia/Public/testprogram/k_sin.c_e.c:80:44");
  computeDAdd((Addr)&temp_var_for_tac_6,
              {(Addr) &(temp_var_for_const_7 = S5), (Addr)&temp_var_for_tac_5},
              "/home/shijia/Public/testprogram/k_sin.c_e.c:80:40");
  computeDMul((Addr)&temp_var_for_tac_7, {(Addr)&z, (Addr)&temp_var_for_tac_6},
              "/home/shijia/Public/testprogram/k_sin.c_e.c:80:34");
  computeDAdd((Addr)&temp_var_for_tac_8,
              {(Addr) &(temp_var_for_const_8 = S4), (Addr)&temp_var_for_tac_7},
              "/home/shijia/Public/testprogram/k_sin.c_e.c:80:30");
  computeDMul((Addr)&temp_var_for_tac_9, {(Addr)&z, (Addr)&temp_var_for_tac_8},
              "/home/shijia/Public/testprogram/k_sin.c_e.c:80:24");
  computeDAdd((Addr)&temp_var_for_tac_10,
              {(Addr) &(temp_var_for_const_9 = S3), (Addr)&temp_var_for_tac_9},
              "/home/shijia/Public/testprogram/k_sin.c_e.c:80:20");
  computeDMul((Addr)&temp_var_for_tac_11,
              {(Addr)&z, (Addr)&temp_var_for_tac_10},
              "/home/shijia/Public/testprogram/k_sin.c_e.c:80:14");
  computeDAdd((Addr)&temp_var_for_tac_12, {(Addr) &(temp_var_for_const_10 = S2),
                                           (Addr)&temp_var_for_tac_11},
              "/home/shijia/Public/testprogram/k_sin.c_e.c:80:10");
  AssignD({(Addr)&r}, (Addr)&temp_var_for_tac_12,
          "/home/shijia/Public/testprogram/k_sin.c_e.c:80:5");
  ;
  if (iy == 0) {
    double temp_var_for_ext_1;
    double temp_var_for_tac_13, temp_var_for_tac_14, temp_var_for_tac_15,
        temp_var_for_tac_16;
    double temp_var_for_const_11;
    temp_var_for_tac_13 = z * r;

    temp_var_for_tac_14 = S1 + temp_var_for_tac_13;

    temp_var_for_tac_15 = v * temp_var_for_tac_14;

    temp_var_for_tac_16 = x + temp_var_for_tac_15;

    temp_var_for_ext_1 = temp_var_for_tac_16;
    computeDMul((Addr)&temp_var_for_tac_13, {(Addr)&z, (Addr)&r},
                "/home/shijia/Public/testprogram/k_sin.c_e.c:83:42");
    computeDAdd(
        (Addr)&temp_var_for_tac_14,
        {(Addr) &(temp_var_for_const_11 = S1), (Addr)&temp_var_for_tac_13},
        "/home/shijia/Public/testprogram/k_sin.c_e.c:83:38");
    computeDMul((Addr)&temp_var_for_tac_15,
                {(Addr)&v, (Addr)&temp_var_for_tac_14},
                "/home/shijia/Public/testprogram/k_sin.c_e.c:83:32");
    computeDAdd((Addr)&temp_var_for_tac_16,
                {(Addr)&x, (Addr)&temp_var_for_tac_15},
                "/home/shijia/Public/testprogram/k_sin.c_e.c:83:28");
    AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_16,
            "/home/shijia/Public/testprogram/k_sin.c_e.c:83:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }

  else {
    double temp_var_for_ext_2;
    double temp_var_for_tac_17, temp_var_for_tac_18, temp_var_for_tac_19,
        temp_var_for_tac_20, temp_var_for_tac_21, temp_var_for_tac_22,
        temp_var_for_tac_23, temp_var_for_tac_24;
    double temp_var_for_const_12, temp_var_for_const_13;
    temp_var_for_tac_17 = half * y;

    temp_var_for_tac_18 = v * r;

    temp_var_for_tac_19 = temp_var_for_tac_17 - temp_var_for_tac_18;

    temp_var_for_tac_20 = z * temp_var_for_tac_19;

    temp_var_for_tac_21 = temp_var_for_tac_20 - y;

    temp_var_for_tac_22 = v * S1;

    temp_var_for_tac_23 = temp_var_for_tac_21 - temp_var_for_tac_22;

    temp_var_for_tac_24 = x - temp_var_for_tac_23;

    temp_var_for_ext_2 = temp_var_for_tac_24;
    computeDMul((Addr)&temp_var_for_tac_17,
                {(Addr) &(temp_var_for_const_12 = half), (Addr)&y},
                "/home/shijia/Public/testprogram/k_sin.c_e.c:91:42");
    computeDMul((Addr)&temp_var_for_tac_18, {(Addr)&v, (Addr)&r},
                "/home/shijia/Public/testprogram/k_sin.c_e.c:91:50");
    computeDSub((Addr)&temp_var_for_tac_19,
                {(Addr)&temp_var_for_tac_17, (Addr)&temp_var_for_tac_18},
                "/home/shijia/Public/testprogram/k_sin.c_e.c:91:46");
    computeDMul((Addr)&temp_var_for_tac_20,
                {(Addr)&z, (Addr)&temp_var_for_tac_19},
                "/home/shijia/Public/testprogram/k_sin.c_e.c:91:34");
    computeDSub((Addr)&temp_var_for_tac_21,
                {(Addr)&temp_var_for_tac_20, (Addr)&y},
                "/home/shijia/Public/testprogram/k_sin.c_e.c:91:55");
    computeDMul((Addr)&temp_var_for_tac_22,
                {(Addr)&v, (Addr) &(temp_var_for_const_13 = S1)},
                "/home/shijia/Public/testprogram/k_sin.c_e.c:91:64");
    computeDSub((Addr)&temp_var_for_tac_23,
                {(Addr)&temp_var_for_tac_21, (Addr)&temp_var_for_tac_22},
                "/home/shijia/Public/testprogram/k_sin.c_e.c:91:60");
    computeDSub((Addr)&temp_var_for_tac_24,
                {(Addr)&x, (Addr)&temp_var_for_tac_23},
                "/home/shijia/Public/testprogram/k_sin.c_e.c:91:28");
    AssignD({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_24,
            "/home/shijia/Public/testprogram/k_sin.c_e.c:91:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  }
}
