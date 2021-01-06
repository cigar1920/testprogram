#include "../ScDebug/scdebug.h"
/* @(#)k_cos.c 1.3 95/01/18 */
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

/*
 * __kernel_cos( x,  y )
 * kernel cos function on [-pi/4, pi/4], pi/4 ~ 0.785398164
 * Input x is assumed to be bounded by ~pi/4 in magnitude.
 * Input y is the tail of x.
 *
 * Algorithm
 *	1. Since cos(-x) = cos(x), we need only to consider positive x.
 *	2. if x < 2^-27 (hx<0x3e400000 0), return 1 with inexact if x!=0.
 *	3. cos(x) is approximated by a polynomial of degree 14 on
 *	   [0,pi/4]
 *		  	                 4            14
 *	   	cos(x) ~ 1 - x*x/2 + C1*x + ... + C6*x
 *	   where the remez error is
 *
 * 	|              2     4     6     8     10    12     14 |     -58
 * 	|cos(x)-(1-.5*x +C1*x +C2*x +C3*x +C4*x +C5*x  +C6*x  )| <= 2
 * 	|    					               |
 *
 * 	               4     6     8     10    12     14
 *	4. let r = C1*x +C2*x +C3*x +C4*x +C5*x  +C6*x  , then
 *	       cos(x) = 1 - x*x/2 + r
 *	   since cos(x+y) ~ cos(x) - sin(x)*y
 *			  ~ cos(x) - x*y,
 *	   a correction term is necessary in cos(x) and hence
 *		cos(x+y) = 1 - (x*x/2 - (r - x*y))
 *	   For better accuracy when x > 0.3, let qx = |x|/4 with
 *	   the last 32 bits mask off, and if x > 0.78125, let qx = 0.28125.
 *	   Then
 *		cos(x+y) = (1-qx) - ((x*x/2-qx) - (r-x*y)).
 *	   Note that 1-qx and (x*x/2-qx) is EXACT here, and the
 *	   magnitude of the latter is at least a quarter of x*x/2,
 *	   thus, reducing the rounding error in the subtraction.
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

double __kernel_cos(double x, double y) {
  double a, hz, z, r, qx;
  int32_t ix;

  static const double one =
      1.00000000000000000000e+00; /* 0x3FF00000, 0x00000000 */
  static const double C1 =
      4.16666666666666019037e-02; /* 0x3FA55555, 0x5555554C */
  static const double C2 =
      (double temp_var_for_tac_0;
       double temp_var_for_const_0, temp_var_for_const_1;
       temp_var_for_tac_0 = 0.0 - 1.38888888888741095749e-03;

       ); /* 0xBF56C16C, 0x16C15177 */
  static const double C3 =
      2.48015872894767294178e-05; /* 0x3EFA01A0, 0x19CB1590 */
  static const double C4 =
      (double temp_var_for_tac_1;
       double temp_var_for_const_2, temp_var_for_const_3;
       temp_var_for_tac_1 = 0.0 - 2.75573143513906633035e-07;

       ); /* 0xBE927E4F, 0x809C52AD */
  static const double C5 =
      2.08757232129817482790e-09; /* 0x3E21EE9E, 0xBDB4B1C4 */
  static const double C6 =
      (double temp_var_for_tac_2;
       double temp_var_for_const_4, temp_var_for_const_5;
       temp_var_for_tac_2 = 0.0 - 1.13596475577881948265e-11;

       ); /* 0xBDA8FAE9, 0xBE8838D4 */

  GET_HIGH_WORD(ix, x);
  ix &= IC(0x7fffffff);      /* ix = |x|'s high word */
  if (ix < IC(0x3e400000)) { /* if x < 2**27 */
    if (((int)x) == 0) {
      double temp_var_for_ext_0;
      double temp_var_for_const_6;
      temp_var_for_ext_0 = one;
      computeDSub((Addr)&temp_var_for_tac_0,
                  {(Addr) &(temp_var_for_const_1 = 0.0),
                   (Addr) &(temp_var_for_const_0 = 1.38888888888741095749e-03)},
                  "/home/shijia/Public/testprogram/k_cos.c_e.c:61:12");
      computeDSub((Addr)&temp_var_for_tac_1,
                  {(Addr) &(temp_var_for_const_3 = 0.0),
                   (Addr) &(temp_var_for_const_2 = 2.75573143513906633035e-07)},
                  "/home/shijia/Public/testprogram/k_cos.c_e.c:65:12");
      computeDSub((Addr)&temp_var_for_tac_2,
                  {(Addr) &(temp_var_for_const_5 = 0.0),
                   (Addr) &(temp_var_for_const_4 = 1.13596475577881948265e-11)},
                  "/home/shijia/Public/testprogram/k_cos.c_e.c:69:12");
      AssignD({(Addr)&temp_var_for_ext_0}, (Addr) &(temp_var_for_const_6 = one),
              "/home/shijia/Public/testprogram/k_cos.c_e.c:76:26");
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
              "/home/shijia/Public/testprogram/k_cos.c_e.c:84:9");
  AssignD({(Addr)&z}, (Addr)&temp_var_for_tac_3,
          "/home/shijia/Public/testprogram/k_cos.c_e.c:84:5");
  ;
  double temp_var_for_tac_4, temp_var_for_tac_5, temp_var_for_tac_6,
      temp_var_for_tac_7, temp_var_for_tac_8, temp_var_for_tac_9,
      temp_var_for_tac_10, temp_var_for_tac_11, temp_var_for_tac_12,
      temp_var_for_tac_13, temp_var_for_tac_14;
  double temp_var_for_const_7, temp_var_for_const_8, temp_var_for_const_9,
      temp_var_for_const_10, temp_var_for_const_11, temp_var_for_const_12;
  temp_var_for_tac_4 = z * C6;

  temp_var_for_tac_5 = C5 + temp_var_for_tac_4;

  temp_var_for_tac_6 = z * temp_var_for_tac_5;

  temp_var_for_tac_7 = C4 + temp_var_for_tac_6;

  temp_var_for_tac_8 = z * temp_var_for_tac_7;

  temp_var_for_tac_9 = C3 + temp_var_for_tac_8;

  temp_var_for_tac_10 = z * temp_var_for_tac_9;

  temp_var_for_tac_11 = C2 + temp_var_for_tac_10;

  temp_var_for_tac_12 = z * temp_var_for_tac_11;

  temp_var_for_tac_13 = C1 + temp_var_for_tac_12;

  temp_var_for_tac_14 = z * temp_var_for_tac_13;

  r = temp_var_for_tac_14;
  computeDMul((Addr)&temp_var_for_tac_4,
              {(Addr)&z, (Addr) &(temp_var_for_const_7 = C6)},
              "/home/shijia/Public/testprogram/k_cos.c_e.c:85:59");
  computeDAdd((Addr)&temp_var_for_tac_5,
              {(Addr) &(temp_var_for_const_8 = C5), (Addr)&temp_var_for_tac_4},
              "/home/shijia/Public/testprogram/k_cos.c_e.c:85:55");
  computeDMul((Addr)&temp_var_for_tac_6, {(Addr)&z, (Addr)&temp_var_for_tac_5},
              "/home/shijia/Public/testprogram/k_cos.c_e.c:85:49");
  computeDAdd((Addr)&temp_var_for_tac_7,
              {(Addr) &(temp_var_for_const_9 = C4), (Addr)&temp_var_for_tac_6},
              "/home/shijia/Public/testprogram/k_cos.c_e.c:85:45");
  computeDMul((Addr)&temp_var_for_tac_8, {(Addr)&z, (Addr)&temp_var_for_tac_7},
              "/home/shijia/Public/testprogram/k_cos.c_e.c:85:39");
  computeDAdd((Addr)&temp_var_for_tac_9,
              {(Addr) &(temp_var_for_const_10 = C3), (Addr)&temp_var_for_tac_8},
              "/home/shijia/Public/testprogram/k_cos.c_e.c:85:35");
  computeDMul((Addr)&temp_var_for_tac_10, {(Addr)&z, (Addr)&temp_var_for_tac_9},
              "/home/shijia/Public/testprogram/k_cos.c_e.c:85:29");
  computeDAdd((Addr)&temp_var_for_tac_11, {(Addr) &(temp_var_for_const_11 = C2),
                                           (Addr)&temp_var_for_tac_10},
              "/home/shijia/Public/testprogram/k_cos.c_e.c:85:25");
  computeDMul((Addr)&temp_var_for_tac_12,
              {(Addr)&z, (Addr)&temp_var_for_tac_11},
              "/home/shijia/Public/testprogram/k_cos.c_e.c:85:19");
  computeDAdd((Addr)&temp_var_for_tac_13, {(Addr) &(temp_var_for_const_12 = C1),
                                           (Addr)&temp_var_for_tac_12},
              "/home/shijia/Public/testprogram/k_cos.c_e.c:85:15");
  computeDMul((Addr)&temp_var_for_tac_14,
              {(Addr)&z, (Addr)&temp_var_for_tac_13},
              "/home/shijia/Public/testprogram/k_cos.c_e.c:85:9");
  AssignD({(Addr)&r}, (Addr)&temp_var_for_tac_14,
          "/home/shijia/Public/testprogram/k_cos.c_e.c:85:5");
  ;
  if (ix < IC(0x3FD33333)) /* if |x| < 0.3 */
  {
    double temp_var_for_ext_1;
    double temp_var_for_tac_15, temp_var_for_tac_16, temp_var_for_tac_17,
        temp_var_for_tac_18, temp_var_for_tac_19, temp_var_for_tac_20;
    double temp_var_for_const_13, temp_var_for_const_14;
    temp_var_for_tac_15 = 0.5 * z;

    temp_var_for_tac_16 = z * r;

    temp_var_for_tac_17 = x * y;

    temp_var_for_tac_18 = temp_var_for_tac_16 - temp_var_for_tac_17;

    temp_var_for_tac_19 = temp_var_for_tac_15 - temp_var_for_tac_18;

    temp_var_for_tac_20 = one - temp_var_for_tac_19;

    temp_var_for_ext_1 = temp_var_for_tac_20;
    computeDMul((Addr)&temp_var_for_tac_15,
                {(Addr) &(temp_var_for_const_13 = 0.5), (Addr)&z},
                "/home/shijia/Public/testprogram/k_cos.c_e.c:89:37");
    computeDMul((Addr)&temp_var_for_tac_16, {(Addr)&z, (Addr)&r},
                "/home/shijia/Public/testprogram/k_cos.c_e.c:89:46");
    computeDMul((Addr)&temp_var_for_tac_17, {(Addr)&x, (Addr)&y},
                "/home/shijia/Public/testprogram/k_cos.c_e.c:89:54");
    computeDSub((Addr)&temp_var_for_tac_18,
                {(Addr)&temp_var_for_tac_16, (Addr)&temp_var_for_tac_17},
                "/home/shijia/Public/testprogram/k_cos.c_e.c:89:50");
    computeDSub((Addr)&temp_var_for_tac_19,
                {(Addr)&temp_var_for_tac_15, (Addr)&temp_var_for_tac_18},
                "/home/shijia/Public/testprogram/k_cos.c_e.c:89:41");
    computeDSub(
        (Addr)&temp_var_for_tac_20,
        {(Addr) &(temp_var_for_const_14 = one), (Addr)&temp_var_for_tac_19},
        "/home/shijia/Public/testprogram/k_cos.c_e.c:89:30");
    AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_20,
            "/home/shijia/Public/testprogram/k_cos.c_e.c:89:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }

  else {
    if (ix > IC(0x3fe90000)) { /* x > 0.78125 */
      double temp_var_for_const_15;
      qx = 0.28125;
      AssignD({(Addr)&qx}, (Addr) &(temp_var_for_const_15 = 0.28125),
              "/home/shijia/Public/testprogram/k_cos.c_e.c:97:10");
      ;
    } else {
      INSERT_WORDS(qx, ix - IC(0x00200000), 0); /* x/4 */
    }
    double temp_var_for_tac_21, temp_var_for_tac_22;
    double temp_var_for_const_16;
    temp_var_for_tac_21 = 0.5 * z;

    temp_var_for_tac_22 = temp_var_for_tac_21 - qx;

    hz = temp_var_for_tac_22;
    computeDMul((Addr)&temp_var_for_tac_21,
                {(Addr) &(temp_var_for_const_16 = 0.5), (Addr)&z},
                "/home/shijia/Public/testprogram/k_cos.c_e.c:101:14");
    computeDSub((Addr)&temp_var_for_tac_22,
                {(Addr)&temp_var_for_tac_21, (Addr)&qx},
                "/home/shijia/Public/testprogram/k_cos.c_e.c:101:18");
    AssignD({(Addr)&hz}, (Addr)&temp_var_for_tac_22,
            "/home/shijia/Public/testprogram/k_cos.c_e.c:101:8");
    ;
    double temp_var_for_tac_23;
    double temp_var_for_const_17;
    temp_var_for_tac_23 = one - qx;

    a = temp_var_for_tac_23;
    computeDSub((Addr)&temp_var_for_tac_23,
                {(Addr) &(temp_var_for_const_17 = one), (Addr)&qx},
                "/home/shijia/Public/testprogram/k_cos.c_e.c:102:13");
    AssignD({(Addr)&a}, (Addr)&temp_var_for_tac_23,
            "/home/shijia/Public/testprogram/k_cos.c_e.c:102:7");
    ;
    double temp_var_for_ext_2;
    double temp_var_for_tac_24, temp_var_for_tac_25, temp_var_for_tac_26,
        temp_var_for_tac_27, temp_var_for_tac_28;
    temp_var_for_tac_24 = z * r;

    temp_var_for_tac_25 = x * y;

    temp_var_for_tac_26 = temp_var_for_tac_24 - temp_var_for_tac_25;

    temp_var_for_tac_27 = hz - temp_var_for_tac_26;

    temp_var_for_tac_28 = a - temp_var_for_tac_27;

    temp_var_for_ext_2 = temp_var_for_tac_28;
    computeDMul((Addr)&temp_var_for_tac_24, {(Addr)&z, (Addr)&r},
                "/home/shijia/Public/testprogram/k_cos.c_e.c:104:39");
    computeDMul((Addr)&temp_var_for_tac_25, {(Addr)&x, (Addr)&y},
                "/home/shijia/Public/testprogram/k_cos.c_e.c:104:47");
    computeDSub((Addr)&temp_var_for_tac_26,
                {(Addr)&temp_var_for_tac_24, (Addr)&temp_var_for_tac_25},
                "/home/shijia/Public/testprogram/k_cos.c_e.c:104:43");
    computeDSub((Addr)&temp_var_for_tac_27,
                {(Addr)&hz, (Addr)&temp_var_for_tac_26},
                "/home/shijia/Public/testprogram/k_cos.c_e.c:104:34");
    computeDSub((Addr)&temp_var_for_tac_28,
                {(Addr)&a, (Addr)&temp_var_for_tac_27},
                "/home/shijia/Public/testprogram/k_cos.c_e.c:104:28");
    AssignD({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_28,
            "/home/shijia/Public/testprogram/k_cos.c_e.c:104:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  }
}
