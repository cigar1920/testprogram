#include "../ScDebug/scdebug.h"
/* @(#)e_atanh.c 1.3 95/01/18 */
/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunSoft, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 *
 */

/* __ieee754_atanh(x)
 * Method :
 *    1.Reduced x to positive by atanh(-x) = -atanh(x)
 *    2.For x>=0.5
 *                  1              2x                          x
 *	atanh(x) = --- * log(1 + -------) = 0.5 * log1p(2 * --------)
 *                  2             1 - x                      1 - x
 *
 * 	For x<0.5
 *	atanh(x) = 0.5*log1p(2x+2x*x/(1-x))
 *
 * Special cases:
 *	atanh(x) is NaN if |x| > 1 with signal;
 *	atanh(NaN) is that NaN with no signal;
 *	atanh(+-1) is +-INF with signal.
 *
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_atanh

double __ieee754_atanh(double x) {
#if defined __have_fpu_log1p
  double xa = __ieee754_fabs(x);
  double t;

  static const double hugeval = 1e300;

  if (isless(xa, 0.5)) {
    if (xa < 0x1.0p-28) {
      math_force_eval(hugeval + x);
      return x;
    }

    t = xa + xa;
    t = 0.5 * __ieee754_log1p(t + t * xa / (1.0 - xa));
  } else if (isless(xa, 1.0)) {
    t = 0.5 * __ieee754_log1p((xa + xa) / (1.0 - xa));
  } else {
    if (isgreater(xa, 1.0))
      return (x - x) / (x - x);

    return x / 0.0;
  }

  return __copysign(t, x);

#elif defined __have_fpu_log

  return 0.5 * log((1 + x) / (1 - x));

#else
  double t;
  int32_t hx, ix;
  uint32_t lx;

  static const double one = 1.0;
  static const double hugeval = 1e300;
  static const double zero = 0.0;

  GET_DOUBLE_WORDS(hx, lx, x);
  ix = hx & IC(0x7fffffff);
  if ((ix | ((lx | (-lx)) >> 31)) > IC(0x3ff00000)) /* |x|>1 */
  {
    double temp_var_for_ext_0;
    double temp_var_for_tac_0, temp_var_for_tac_1, temp_var_for_tac_2;
    temp_var_for_tac_0 = x - x;

    temp_var_for_tac_1 = x - x;

    temp_var_for_tac_2 = temp_var_for_tac_0 / temp_var_for_tac_1;

    temp_var_for_ext_0 = temp_var_for_tac_2;
    computeDSub((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_atanh.c_e.c:82:29");
    computeDSub((Addr)&temp_var_for_tac_1, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_atanh.c_e.c:82:39");
    computeDDiv((Addr)&temp_var_for_tac_2,
                {(Addr)&temp_var_for_tac_0, (Addr)&temp_var_for_tac_1},
                "/home/shijia/Public/testprogram/e_atanh.c_e.c:82:34");
    AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_2,
            "/home/shijia/Public/testprogram/e_atanh.c_e.c:82:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  if (ix == IC(0x3ff00000)) {
    double temp_var_for_ext_1;
    double temp_var_for_tac_3;
    double temp_var_for_const_0;
    temp_var_for_tac_3 = x / zero;

    temp_var_for_ext_1 = temp_var_for_tac_3;
    computeDDiv((Addr)&temp_var_for_tac_3,
                {(Addr)&x, (Addr) &(temp_var_for_const_0 = zero)},
                "/home/shijia/Public/testprogram/e_atanh.c_e.c:90:28");
    AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_3,
            "/home/shijia/Public/testprogram/e_atanh.c_e.c:90:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }

  if (ix < IC(0x3e300000) && int temp_var_for_tac_4, temp_var_for_tac_5;
      int temp_var_for_const_1, temp_var_for_const_2;
      temp_var_for_tac_4 = hugeval + x;

      temp_var_for_tac_5 = temp_var_for_tac_4 > zero;

      ) {
    double temp_var_for_ext_2;
    temp_var_for_ext_2 = x;
    computeDAdd((Addr)&temp_var_for_tac_4,
                {(Addr) &(temp_var_for_const_1 = hugeval), (Addr)&x},
                "/home/shijia/Public/testprogram/e_atanh.c_e.c:96:39");
    compute((Addr)&temp_var_for_tac_5,
            {(Addr)&temp_var_for_tac_4, (Addr) &(temp_var_for_const_2 = zero)},
            "/home/shijia/Public/testprogram/e_atanh.c_e.c:96:44");
    AssignD({(Addr)&temp_var_for_ext_2}, (Addr)&x,
            "/home/shijia/Public/testprogram/e_atanh.c_e.c:98:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  }
  /* x<2**-28 */
  SET_HIGH_WORD(x, ix);
  if (ix < IC(0x3fe00000)) { /* x < 0.5 */
    double temp_var_for_ext_3;
    double temp_var_for_tac_6;
    temp_var_for_tac_6 = x + x;

    temp_var_for_ext_3 = temp_var_for_tac_6;
    computeDAdd((Addr)&temp_var_for_tac_6, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_atanh.c_e.c:107:28");
    AssignD({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_6,
            "/home/shijia/Public/testprogram/e_atanh.c_e.c:107:24");
    ; // t
    /*(_)(_)(a)(m)(a)(m)(_)(_)(xt_1)(t)(x)(hugeval)(x)(x)*/
    t = temp_var_for_ext_3;
    AssignD({(Addr)&t}, (Addr)&temp_var_for_ext_3,
            "/home/shijia/Public/testprogram/e_atanh.c_e.c:109:7");
    ;
    double temp_var_for_tac_7, temp_var_for_tac_8, temp_var_for_tac_9,
        temp_var_for_tac_10, temp_var_for_tac_11;
    double temp_var_for_const_3, temp_var_for_const_4, temp_var_for_const_5;
    double temp_var_for_callexp_0;

    temp_var_for_tac_7 = t * x;

    temp_var_for_tac_8 = one - x;

    temp_var_for_tac_9 = temp_var_for_tac_7 / temp_var_for_tac_8;

    temp_var_for_tac_10 = t + temp_var_for_tac_9;

    temp_var_for_callexp_0 = __ieee754_log1p(temp_var_for_tac_10);
    temp_var_for_tac_11 = 0.5 * temp_var_for_callexp_0;

    t = temp_var_for_tac_11;
    computeDMul((Addr)&temp_var_for_tac_7, {(Addr)&t, (Addr)&x},
                "/home/shijia/Public/testprogram/e_atanh.c_e.c:110:37");
    computeDSub((Addr)&temp_var_for_tac_8,
                {(Addr) &(temp_var_for_const_3 = one), (Addr)&x},
                "/home/shijia/Public/testprogram/e_atanh.c_e.c:110:48");
    computeDDiv((Addr)&temp_var_for_tac_9,
                {(Addr)&temp_var_for_tac_7, (Addr)&temp_var_for_tac_8},
                "/home/shijia/Public/testprogram/e_atanh.c_e.c:110:41");
    computeDAdd((Addr)&temp_var_for_tac_10,
                {(Addr)&t, (Addr)&temp_var_for_tac_9},
                "/home/shijia/Public/testprogram/e_atanh.c_e.c:110:33");
    computeDMul((Addr)&temp_var_for_tac_11,
                {(Addr) &(temp_var_for_const_5 = 0.5),
                 (Addr) &(temp_var_for_const_4 = temp_var_for_callexp_0)},
                "/home/shijia/Public/testprogram/e_atanh.c_e.c:110:13");
    AssignD({(Addr)&t}, (Addr)&temp_var_for_tac_11,
            "/home/shijia/Public/testprogram/e_atanh.c_e.c:110:7");
    ;
  } else {
    double temp_var_for_ext_4;
    double temp_var_for_tac_12, temp_var_for_tac_13, temp_var_for_tac_14,
        temp_var_for_tac_15;
    double temp_var_for_const_6, temp_var_for_const_7, temp_var_for_const_8;
    double temp_var_for_callexp_1;

    temp_var_for_tac_12 = x + x;

    temp_var_for_tac_13 = one - x;

    temp_var_for_tac_14 = temp_var_for_tac_12 / temp_var_for_tac_13;

    temp_var_for_callexp_1 = __ieee754_log1p(temp_var_for_tac_14);
    temp_var_for_tac_15 = 0.5 * temp_var_for_callexp_1;

    temp_var_for_ext_4 = temp_var_for_tac_15;
    computeDAdd((Addr)&temp_var_for_tac_12, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_atanh.c_e.c:113:51");
    computeDSub((Addr)&temp_var_for_tac_13,
                {(Addr) &(temp_var_for_const_6 = one), (Addr)&x},
                "/home/shijia/Public/testprogram/e_atanh.c_e.c:113:63");
    computeDDiv((Addr)&temp_var_for_tac_14,
                {(Addr)&temp_var_for_tac_12, (Addr)&temp_var_for_tac_13},
                "/home/shijia/Public/testprogram/e_atanh.c_e.c:113:56");
    computeDMul((Addr)&temp_var_for_tac_15,
                {(Addr) &(temp_var_for_const_8 = 0.5),
                 (Addr) &(temp_var_for_const_7 = temp_var_for_callexp_1)},
                "/home/shijia/Public/testprogram/e_atanh.c_e.c:113:30");
    AssignD({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_15,
            "/home/shijia/Public/testprogram/e_atanh.c_e.c:113:24");
    ; // t
      /*(__ieee754_log1p(t + t * x / (one -
       * x)))(0.5)(x)(one)(x)(t)(t)(x)(one)(x)(t)(x)(t)(x)(one)(__ieee754_log1p((x
       * + x) / (one - x)))(0.5)*/
    t = temp_var_for_ext_4;
    AssignD({(Addr)&t}, (Addr)&temp_var_for_ext_4,
            "/home/shijia/Public/testprogram/e_atanh.c_e.c:117:7");
    ;
  }
  if (hx >= 0) {
    double temp_var_for_ext_5;
    temp_var_for_ext_5 = t;
    AssignD({(Addr)&temp_var_for_ext_5}, (Addr)&t,
            "/home/shijia/Public/testprogram/e_atanh.c_e.c:121:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_5;
  }

  double temp_var_for_ext_6;
  double temp_var_for_const_9;
  temp_var_for_ext_6 = (-(t));
  AssignD({(Addr)&temp_var_for_ext_6}, (Addr) &(temp_var_for_const_9 = (-(t))),
          "/home/shijia/Public/testprogram/e_atanh.c_e.c:128:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
  callExp++; /*identify the function is  add move tmpShadow*/
  return (double temp_var_for_tac_16;
          double temp_var_for_const_10, temp_var_for_const_11;
          temp_var_for_tac_16 = 0.0 - 6;

          );
#endif
}

#endif

/* wrapper atanh */
double __atanh(double x) {
  if (_LIB_VERSION != _IEEE_ && isgreaterequal(__ieee754_fabs(x), 1.0)) {
    double temp_var_for_ext_7;
    double temp_var_for_const_12;
    double temp_var_for_callexp_2;

    /*embed fun has found*/
    double temp_var_for_callexp_3;

    temp_var_for_callexp_2 = __builtin_huge_val();
    temp_var_for_callexp_3 = __kernel_standard(
        x, x, temp_var_for_callexp_2,
        __ieee754_fabs(x) > 1.0 ? KMATHERR_ATANH_PLUSONE /* atanh(|x|>1) */
                                : KMATHERR_ATANH_ONE);
    temp_var_for_ext_7 = temp_var_for_callexp_3;
    computeDSub((Addr)&temp_var_for_tac_16,
                {(Addr) &(temp_var_for_const_11 = 0.0),
                 (Addr) &(temp_var_for_const_10 = 6)},
                "/home/shijia/Public/testprogram/e_atanh.c_e.c:131:15");
    AssignD({(Addr)&temp_var_for_ext_7},
            (Addr) &(temp_var_for_const_12 = temp_var_for_callexp_3),
            "/home/shijia/Public/testprogram/e_atanh.c_e.c:141:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_7;
  }
  /* atanh(|x|==1) */

  double temp_var_for_ext_8;
  double temp_var_for_const_13;
  double temp_var_for_callexp_4;

  temp_var_for_callexp_4 = __ieee754_atanh(x);
  temp_var_for_ext_8 = temp_var_for_callexp_4;
  AssignD({(Addr)&temp_var_for_ext_8},
          (Addr) &(temp_var_for_const_13 = temp_var_for_callexp_4),
          "/home/shijia/Public/testprogram/e_atanh.c_e.c:152:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_8;
}

__typeof(__atanh) atanh __attribute__((weak, alias("__atanh")));
#ifdef __NO_LONG_DOUBLE_MATH
__typeof(__atanhl) __atanhl __attribute__((alias("__atanh")));
__typeof(__atanhl) atanhl __attribute__((weak, alias("__atanh")));
#endif
