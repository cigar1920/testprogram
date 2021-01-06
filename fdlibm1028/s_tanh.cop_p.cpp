#include "../ScDebug/scdebug.h"
/* @(#)s_tanh.c 1.3 95/01/18 */
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

/* Tanh(x)
 * Return the Hyperbolic Tangent of x
 *
 * Method :
 *				       x    -x
 *				      e  - e
 *	0. tanh(x) is defined to be -----------
 *				       x    -x
 *				      e  + e
 *	1. reduce x to non-negative by tanh(-x) = -tanh(x).
 *	2.  0      <= x <= 2**-55 : tanh(x) := x*(one+x)
 *					        -t
 *	    2**-55 <  x <=  1     : tanh(x) := -----; t = expm1(-2x)
 *					       t + 2
 *						     2
 *	    1      <= x <=  22.0  : tanh(x) := 1-  ----- ; t=expm1(2x)
 *						   t + 2
 *	    22.0   <  x <= INF    : tanh(x) := 1.
 *
 * Special cases:
 *	tanh(NaN) is NaN;
 *	only tanh(0)=0 is exact for finite argument.
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_tanh

double __ieee754_tanh(double x) {
  double t, z;
  int32_t jx, ix, lx;

  static const double one = 1.0;
  static const double two = 2.0;
  static const double tiny = 1.0e-300;

  /* High word of |x|. */
  GET_DOUBLE_WORDS(jx, lx, x);
  ix = jx & IC(0x7fffffff);

  /* x is INF or NaN */
  if (ix >= IC(0x7ff00000)) {
    if (jx >= 0) {
      double temp_var_for_ext_0;
      double temp_var_for_tac_0, temp_var_for_tac_1;
      double temp_var_for_const_0, temp_var_for_const_1;
      temp_var_for_tac_0 = one / x;

      temp_var_for_tac_1 = temp_var_for_tac_0 + one;

      temp_var_for_ext_0 = temp_var_for_tac_1;
      computeDDiv((Addr)&temp_var_for_tac_0,
                  {(Addr) &(temp_var_for_const_0 = one), (Addr)&x},
                  "/home/shijia/Public/testprogram/s_tanh.c_e.c:59:32");
      computeDAdd(
          (Addr)&temp_var_for_tac_1,
          {(Addr)&temp_var_for_tac_0, (Addr) &(temp_var_for_const_1 = one)},
          "/home/shijia/Public/testprogram/s_tanh.c_e.c:59:36");
      AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_1,
              "/home/shijia/Public/testprogram/s_tanh.c_e.c:59:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_0;
    }
    /* tanh(+-inf)=+-1 */
    else {
      double temp_var_for_ext_1;
      double temp_var_for_tac_2, temp_var_for_tac_3;
      double temp_var_for_const_2, temp_var_for_const_3;
      temp_var_for_tac_2 = one / x;

      temp_var_for_tac_3 = temp_var_for_tac_2 - one;

      temp_var_for_ext_1 = temp_var_for_tac_3;
      computeDDiv((Addr)&temp_var_for_tac_2,
                  {(Addr) &(temp_var_for_const_2 = one), (Addr)&x},
                  "/home/shijia/Public/testprogram/s_tanh.c_e.c:68:32");
      computeDSub(
          (Addr)&temp_var_for_tac_3,
          {(Addr)&temp_var_for_tac_2, (Addr) &(temp_var_for_const_3 = one)},
          "/home/shijia/Public/testprogram/s_tanh.c_e.c:68:36");
      AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_3,
              "/home/shijia/Public/testprogram/s_tanh.c_e.c:68:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_1;
    }
    /* tanh(NaN) = NaN */
  }

  /* |x| < 22 */
  if (ix < IC(0x40360000)) { /* |x|<22 */
    if ((ix | lx) == 0) {
      double temp_var_for_ext_2;
      temp_var_for_ext_2 = x;
      AssignD({(Addr)&temp_var_for_ext_2}, (Addr)&x,
              "/home/shijia/Public/testprogram/s_tanh.c_e.c:81:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_2;
    }
    /* x == +-0 */
    if (ix < IC(0x3c800000)) /* |x|<2**-55 */
    {
      double temp_var_for_ext_3;
      double temp_var_for_tac_4, temp_var_for_tac_5;
      double temp_var_for_const_4;
      temp_var_for_tac_4 = one + x;

      temp_var_for_tac_5 = x * temp_var_for_tac_4;

      temp_var_for_ext_3 = temp_var_for_tac_5;
      computeDAdd((Addr)&temp_var_for_tac_4,
                  {(Addr) &(temp_var_for_const_4 = one), (Addr)&x},
                  "/home/shijia/Public/testprogram/s_tanh.c_e.c:91:37");
      computeDMul((Addr)&temp_var_for_tac_5,
                  {(Addr)&x, (Addr)&temp_var_for_tac_4},
                  "/home/shijia/Public/testprogram/s_tanh.c_e.c:91:30");
      AssignD({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_5,
              "/home/shijia/Public/testprogram/s_tanh.c_e.c:91:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_3;
    }
    /* tanh(small) = small */
    if (ix >= IC(0x3ff00000)) { /* |x|>=1  */
      double temp_var_for_ext_4;
      double temp_var_for_tac_6;
      double temp_var_for_const_5, temp_var_for_const_6, temp_var_for_const_7;
      double temp_var_for_callexp_0;

      double temp_var_for_callexp_1;

      temp_var_for_callexp_0 = fabs(x);
      temp_var_for_tac_6 = two * temp_var_for_callexp_0;

      temp_var_for_callexp_1 = __ieee754_expm1(temp_var_for_tac_6);
      temp_var_for_ext_4 = temp_var_for_callexp_1;
      computeDMul((Addr)&temp_var_for_tac_6,
                  {(Addr) &(temp_var_for_const_6 = two),
                   (Addr) &(temp_var_for_const_5 = temp_var_for_callexp_0)},
                  "/home/shijia/Public/testprogram/s_tanh.c_e.c:100:48");
      AssignD({(Addr)&temp_var_for_ext_4},
              (Addr) &(temp_var_for_const_7 = temp_var_for_callexp_1),
              "/home/shijia/Public/testprogram/s_tanh.c_e.c:100:26");
      ; // t
        /*(t_0)(r)(tem)(r)(tem)(t_1)(r)(tem)(r)(tem)(_)(or_)(t)(_)(or_)(__ieee754_expm1(two
         * * __ieee754_fabs(x)))*/
      t = temp_var_for_ext_4;
      AssignD({(Addr)&t}, (Addr)&temp_var_for_ext_4,
              "/home/shijia/Public/testprogram/s_tanh.c_e.c:103:9");
      ;
      double temp_var_for_tac_7, temp_var_for_tac_8, temp_var_for_tac_9;
      double temp_var_for_const_8, temp_var_for_const_9, temp_var_for_const_10;
      temp_var_for_tac_7 = t + two;

      temp_var_for_tac_8 = two / temp_var_for_tac_7;

      temp_var_for_tac_9 = one - temp_var_for_tac_8;

      z = temp_var_for_tac_9;
      computeDAdd((Addr)&temp_var_for_tac_7,
                  {(Addr)&t, (Addr) &(temp_var_for_const_8 = two)},
                  "/home/shijia/Public/testprogram/s_tanh.c_e.c:104:26");
      computeDDiv(
          (Addr)&temp_var_for_tac_8,
          {(Addr) &(temp_var_for_const_9 = two), (Addr)&temp_var_for_tac_7},
          "/home/shijia/Public/testprogram/s_tanh.c_e.c:104:21");
      computeDSub(
          (Addr)&temp_var_for_tac_9,
          {(Addr) &(temp_var_for_const_10 = one), (Addr)&temp_var_for_tac_8},
          "/home/shijia/Public/testprogram/s_tanh.c_e.c:104:15");
      AssignD({(Addr)&z}, (Addr)&temp_var_for_tac_9,
              "/home/shijia/Public/testprogram/s_tanh.c_e.c:104:9");
      ;
    } else {
      double temp_var_for_ext_5;
      double temp_var_for_tac_10, temp_var_for_tac_11;
      double temp_var_for_const_11, temp_var_for_const_12,
          temp_var_for_const_13, temp_var_for_const_14;
      double temp_var_for_callexp_2;

      double temp_var_for_callexp_3;

      temp_var_for_tac_10 = 0.0 - two;

      temp_var_for_callexp_2 = fabs(x);
      temp_var_for_tac_11 = temp_var_for_tac_10 * temp_var_for_callexp_2;

      temp_var_for_callexp_3 = __ieee754_expm1(temp_var_for_tac_11);
      temp_var_for_ext_5 = temp_var_for_callexp_3;
      computeDSub((Addr)&temp_var_for_tac_10,
                  {(Addr) &(temp_var_for_const_12 = 0.0),
                   (Addr) &(temp_var_for_const_11 = two)},
                  "/home/shijia/Public/testprogram/s_tanh.c_e.c:107:49");
      computeDMul((Addr)&temp_var_for_tac_11,
                  {(Addr)&temp_var_for_tac_10,
                   (Addr) &(temp_var_for_const_13 = temp_var_for_callexp_2)},
                  "/home/shijia/Public/testprogram/s_tanh.c_e.c:107:56");
      AssignD({(Addr)&temp_var_for_ext_5},
              (Addr) &(temp_var_for_const_14 = temp_var_for_callexp_3),
              "/home/shijia/Public/testprogram/s_tanh.c_e.c:107:26");
      ; // t
        /*(two)(t)(two)(one)(two)(t)(two)(two)(t)(__ieee754_expm1(-two *
         * __ieee754_fabs(x)))*/
      t = temp_var_for_ext_5;
      AssignD({(Addr)&t}, (Addr)&temp_var_for_ext_5,
              "/home/shijia/Public/testprogram/s_tanh.c_e.c:110:9");
      ;
      double temp_var_for_tac_12, temp_var_for_tac_13, temp_var_for_tac_14;
      double temp_var_for_const_15, temp_var_for_const_16;
      temp_var_for_tac_12 = 0.0 - t;

      temp_var_for_tac_13 = t + two;

      temp_var_for_tac_14 = temp_var_for_tac_12 / temp_var_for_tac_13;

      z = temp_var_for_tac_14;
      computeDSub((Addr)&temp_var_for_tac_12,
                  {(Addr) &(temp_var_for_const_15 = 0.0), (Addr)&t},
                  "/home/shijia/Public/testprogram/s_tanh.c_e.c:111:16");
      computeDAdd((Addr)&temp_var_for_tac_13,
                  {(Addr)&t, (Addr) &(temp_var_for_const_16 = two)},
                  "/home/shijia/Public/testprogram/s_tanh.c_e.c:111:26");
      computeDDiv((Addr)&temp_var_for_tac_14,
                  {(Addr)&temp_var_for_tac_12, (Addr)&temp_var_for_tac_13},
                  "/home/shijia/Public/testprogram/s_tanh.c_e.c:111:21");
      AssignD({(Addr)&z}, (Addr)&temp_var_for_tac_14,
              "/home/shijia/Public/testprogram/s_tanh.c_e.c:111:9");
      ;
    }
    /* |x| > 22, return +-1 */
  } else {
    double temp_var_for_tac_15;
    double temp_var_for_const_17, temp_var_for_const_18;
    temp_var_for_tac_15 = one - tiny;

    z = temp_var_for_tac_15;
    computeDSub((Addr)&temp_var_for_tac_15,
                {(Addr) &(temp_var_for_const_18 = one),
                 (Addr) &(temp_var_for_const_17 = tiny)},
                "/home/shijia/Public/testprogram/s_tanh.c_e.c:115:13");
    AssignD({(Addr)&z}, (Addr)&temp_var_for_tac_15,
            "/home/shijia/Public/testprogram/s_tanh.c_e.c:115:7");
    ; /* raised inexact flag */
  }
  double temp_var_for_ext_6;
  double temp_var_for_const_19;
  temp_var_for_ext_6 = (jx >= 0) ? z : -z;
  AssignD({(Addr)&temp_var_for_ext_6},
          (Addr) &(temp_var_for_const_19 = (jx >= 0) ? z : -z),
          "/home/shijia/Public/testprogram/s_tanh.c_e.c:118:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext(0.0 - 6);
}

#endif

double __tanh(double x) {
  double temp_var_for_ext_7;
  temp_var_for_ext_7 = __ieee754_tanh(x);
  callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_7;
}

__typeof(__tanh) tanh __attribute__((weak, alias("__tanh")));
#ifdef __NO_LONG_DOUBLE_MATH
__typeof(__tanhl) __tanhl __attribute__((alias("__tanh")));
__typeof(__tanhl) tanhl __attribute__((weak, alias("__tanh")));
#endif
