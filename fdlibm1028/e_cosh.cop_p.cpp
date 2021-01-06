#include "../ScDebug/scdebug.h"
/* @(#)e_cosh.c 1.3 95/01/18 */
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
/* Optimized by Ulrich Drepper <drepper@gmail.com>, 2011 */

/* __ieee754_cosh(x)
 * Method :
 * mathematically cosh(x) if defined to be (exp(x)+exp(-x))/2
 *	1. Replace x by |x| (cosh(x) = cosh(-x)).
 *	2.
 *							[ exp(x) - 1 ]^2
 *	    0        <= x <= ln2/2  :  cosh(x) := 1 + -------------------
 *							   2*exp(x)
 *
 *						  exp(x) +  1/exp(x)
 *	    ln2/2    <= x <= 22     :  cosh(x) := -------------------
 *							  2
 *	    22       <= x <= lnovft :  cosh(x) := exp(x)/2
 *	    lnovft   <= x <= ln2ovft:  cosh(x) := exp(x/2)/2 * exp(x/2)
 *	    ln2ovft  <  x	    :  cosh(x) := hugeval*hugeval (overflow)
 *
 * Special cases:
 *	cosh(x) is |x| if x is +INF, -INF, or NaN.
 *	only cosh(0)=1 is exact for finite x.
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_cosh

double __ieee754_cosh(double x) {
  double t, w;
  int32_t ix;
  uint32_t lx;

  static const double one = 1.0;
  static const double half = 0.5;
  static const double hugeval = 1.0e300;

  /* High word of |x|. */
  GET_HIGH_WORD(ix, x);
  ix &= IC(0x7fffffff);

  /* x is INF or NaN */
  if (ix >= IC(0x7ff00000)) {
    double temp_var_for_ext_0;
    double temp_var_for_tac_0;
    temp_var_for_tac_0 = x * x;

    temp_var_for_ext_0 = temp_var_for_tac_0;
    computeDMul((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_cosh.c_e.c:57:28");
    AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_0,
            "/home/shijia/Public/testprogram/e_cosh.c_e.c:57:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  /* |x| in [0,22] */
  if (ix < IC(0x40360000)) {
    /* |x| in [0,0.5*ln2], return 1+expm1(|x|)^2/(2*exp(|x|)) */
    if (ix < IC(0x3fd62e43)) {
      double temp_var_for_ext_1;
      double temp_var_for_const_0;
      double temp_var_for_callexp_0;

      /*embed fun has found*/
      double temp_var_for_callexp_1;

      temp_var_for_callexp_0 = fabs(x);
      temp_var_for_callexp_1 = __ieee754_expm1(temp_var_for_callexp_0);
      temp_var_for_ext_1 = temp_var_for_callexp_1;
      AssignD({(Addr)&temp_var_for_ext_1},
              (Addr) &(temp_var_for_const_0 = temp_var_for_callexp_1),
              "/home/shijia/Public/testprogram/e_cosh.c_e.c:68:26");
      ; // t
      /*(0)(t)(__ieee754_expm1(__ieee754_fabs(x)))*/
      t = temp_var_for_ext_1;
      AssignD({(Addr)&t}, (Addr)&temp_var_for_ext_1,
              "/home/shijia/Public/testprogram/e_cosh.c_e.c:70:9");
      ;
      double temp_var_for_tac_1;
      double temp_var_for_const_1;
      temp_var_for_tac_1 = one + t;

      w = temp_var_for_tac_1;
      computeDAdd((Addr)&temp_var_for_tac_1,
                  {(Addr) &(temp_var_for_const_1 = one), (Addr)&t},
                  "/home/shijia/Public/testprogram/e_cosh.c_e.c:71:15");
      AssignD({(Addr)&w}, (Addr)&temp_var_for_tac_1,
              "/home/shijia/Public/testprogram/e_cosh.c_e.c:71:9");
      ;
      if (ix < IC(0x3c800000)) {
        double temp_var_for_ext_2;
        temp_var_for_ext_2 = w;
        AssignD({(Addr)&temp_var_for_ext_2}, (Addr)&w,
                "/home/shijia/Public/testprogram/e_cosh.c_e.c:74:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_2;
      }
      /* cosh(tiny) = 1 */
      double temp_var_for_ext_3;
      double temp_var_for_tac_2, temp_var_for_tac_3, temp_var_for_tac_4,
          temp_var_for_tac_5;
      double temp_var_for_const_2;
      temp_var_for_tac_2 = t * t;

      temp_var_for_tac_3 = w + w;

      temp_var_for_tac_4 = temp_var_for_tac_2 / temp_var_for_tac_3;

      temp_var_for_tac_5 = one + temp_var_for_tac_4;

      temp_var_for_ext_3 = temp_var_for_tac_5;
      computeDMul((Addr)&temp_var_for_tac_2, {(Addr)&t, (Addr)&t},
                  "/home/shijia/Public/testprogram/e_cosh.c_e.c:82:37");
      computeDAdd((Addr)&temp_var_for_tac_3, {(Addr)&w, (Addr)&w},
                  "/home/shijia/Public/testprogram/e_cosh.c_e.c:82:47");
      computeDDiv((Addr)&temp_var_for_tac_4,
                  {(Addr)&temp_var_for_tac_2, (Addr)&temp_var_for_tac_3},
                  "/home/shijia/Public/testprogram/e_cosh.c_e.c:82:42");
      computeDAdd(
          (Addr)&temp_var_for_tac_5,
          {(Addr) &(temp_var_for_const_2 = one), (Addr)&temp_var_for_tac_4},
          "/home/shijia/Public/testprogram/e_cosh.c_e.c:82:32");
      AssignD({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_5,
              "/home/shijia/Public/testprogram/e_cosh.c_e.c:82:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_3;
    }

    /* |x| in [0.5*ln2,22], return (exp(|x|)+1/exp(|x|)/2; */
    double temp_var_for_ext_4;
    double temp_var_for_const_3;
    double temp_var_for_callexp_2;

    /*embed fun has found*/
    double temp_var_for_callexp_3;

    temp_var_for_callexp_2 = fabs(x);
    temp_var_for_callexp_3 = __ieee754_exp(temp_var_for_callexp_2);
    temp_var_for_ext_4 = temp_var_for_callexp_3;
    AssignD({(Addr)&temp_var_for_ext_4},
            (Addr) &(temp_var_for_const_3 = temp_var_for_callexp_3),
            "/home/shijia/Public/testprogram/e_cosh.c_e.c:91:24");
    ; // t
    /*(t)(one)(_)(_)(a)(m)(tem)(_)(_)(a)(m)(a)(m)(_)(_)(__ieee754_exp(__ieee754_fabs(x)))*/
    t = temp_var_for_ext_4;
    AssignD({(Addr)&t}, (Addr)&temp_var_for_ext_4,
            "/home/shijia/Public/testprogram/e_cosh.c_e.c:93:7");
    ;
    double temp_var_for_ext_5;
    double temp_var_for_tac_6, temp_var_for_tac_7, temp_var_for_tac_8;
    double temp_var_for_const_4, temp_var_for_const_5;
    temp_var_for_tac_6 = half * t;

    temp_var_for_tac_7 = half / t;

    temp_var_for_tac_8 = temp_var_for_tac_6 + temp_var_for_tac_7;

    temp_var_for_ext_5 = temp_var_for_tac_8;
    computeDMul((Addr)&temp_var_for_tac_6,
                {(Addr) &(temp_var_for_const_4 = half), (Addr)&t},
                "/home/shijia/Public/testprogram/e_cosh.c_e.c:95:31");
    computeDDiv((Addr)&temp_var_for_tac_7,
                {(Addr) &(temp_var_for_const_5 = half), (Addr)&t},
                "/home/shijia/Public/testprogram/e_cosh.c_e.c:95:42");
    computeDAdd((Addr)&temp_var_for_tac_8,
                {(Addr)&temp_var_for_tac_6, (Addr)&temp_var_for_tac_7},
                "/home/shijia/Public/testprogram/e_cosh.c_e.c:95:35");
    AssignD({(Addr)&temp_var_for_ext_5}, (Addr)&temp_var_for_tac_8,
            "/home/shijia/Public/testprogram/e_cosh.c_e.c:95:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_5;
  }

  /* |x| in [22, log(maxdouble)] return half*exp(|x|) */
  if (ix < IC(0x40862E42)) {
    double temp_var_for_ext_6;
    double temp_var_for_tac_9;
    double temp_var_for_const_6, temp_var_for_const_7;
    double temp_var_for_callexp_4;

    /*embed fun has found*/
    double temp_var_for_callexp_5;

    temp_var_for_callexp_4 = fabs(x);
    temp_var_for_callexp_5 = __ieee754_exp(temp_var_for_callexp_4);
    temp_var_for_tac_9 = half * temp_var_for_callexp_5;

    temp_var_for_ext_6 = temp_var_for_tac_9;
    computeDMul((Addr)&temp_var_for_tac_9,
                {(Addr) &(temp_var_for_const_7 = half),
                 (Addr) &(temp_var_for_const_6 = temp_var_for_callexp_5)},
                "/home/shijia/Public/testprogram/e_cosh.c_e.c:104:31");
    AssignD({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_9,
            "/home/shijia/Public/testprogram/e_cosh.c_e.c:104:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_6;
  }

  /* |x| in [log(maxdouble), overflowthresold] */
  GET_LOW_WORD(lx, x);
  if (ix < IC(0x408633ce) || (ix == IC(0x408633ce) && lx <= UC(0x8fb9f87d))) {
    double temp_var_for_tac_10;
    double temp_var_for_const_8, temp_var_for_const_9, temp_var_for_const_10;
    double temp_var_for_callexp_6;

    double temp_var_for_callexp_7;

    temp_var_for_callexp_6 = fabs(x);
    temp_var_for_tac_10 = half * temp_var_for_callexp_6;

    temp_var_for_callexp_7 = __ieee754_exp(temp_var_for_tac_10);
    w = temp_var_for_callexp_7;
    computeDMul((Addr)&temp_var_for_tac_10,
                {(Addr) &(temp_var_for_const_9 = half),
                 (Addr) &(temp_var_for_const_8 = temp_var_for_callexp_6)},
                "/home/shijia/Public/testprogram/e_cosh.c_e.c:113:28");
    AssignD({(Addr)&w},
            (Addr) &(temp_var_for_const_10 = temp_var_for_callexp_7),
            "/home/shijia/Public/testprogram/e_cosh.c_e.c:113:7");
    ;
    double temp_var_for_tac_11;
    double temp_var_for_const_11;
    temp_var_for_tac_11 = half * w;

    t = temp_var_for_tac_11;
    computeDMul((Addr)&temp_var_for_tac_11,
                {(Addr) &(temp_var_for_const_11 = half), (Addr)&w},
                "/home/shijia/Public/testprogram/e_cosh.c_e.c:114:14");
    AssignD({(Addr)&t}, (Addr)&temp_var_for_tac_11,
            "/home/shijia/Public/testprogram/e_cosh.c_e.c:114:7");
    ;
    double temp_var_for_ext_7;
    double temp_var_for_tac_12;
    temp_var_for_tac_12 = t * w;

    temp_var_for_ext_7 = temp_var_for_tac_12;
    computeDMul((Addr)&temp_var_for_tac_12, {(Addr)&t, (Addr)&w},
                "/home/shijia/Public/testprogram/e_cosh.c_e.c:116:28");
    AssignD({(Addr)&temp_var_for_ext_7}, (Addr)&temp_var_for_tac_12,
            "/home/shijia/Public/testprogram/e_cosh.c_e.c:116:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_7;
  }

  /* |x| > overflowthresold, cosh(x) overflow */
  double temp_var_for_ext_8;
  double temp_var_for_tac_13;
  double temp_var_for_const_12, temp_var_for_const_13;
  temp_var_for_tac_13 = hugeval * hugeval;

  temp_var_for_ext_8 = temp_var_for_tac_13;
  computeDMul((Addr)&temp_var_for_tac_13,
              {(Addr) &(temp_var_for_const_13 = hugeval),
               (Addr) &(temp_var_for_const_12 = hugeval)},
              "/home/shijia/Public/testprogram/e_cosh.c_e.c:124:32");
  AssignD({(Addr)&temp_var_for_ext_8}, (Addr)&temp_var_for_tac_13,
          "/home/shijia/Public/testprogram/e_cosh.c_e.c:124:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_8;
}

#endif

/* wrapper cosh */
double __cosh(double x) {
  double z = __ieee754_cosh(x);

  if (_LIB_VERSION != _IEEE_ && !isfinite(z) && isfinite(x)) {
    double temp_var_for_ext_9;
    double temp_var_for_const_14;
    double temp_var_for_callexp_8;

    temp_var_for_callexp_8 = __kernel_standard(x, x, z, KMATHERR_COSH);
    temp_var_for_ext_9 = temp_var_for_callexp_8;
    AssignD({(Addr)&temp_var_for_ext_9},
            (Addr) &(temp_var_for_const_14 = temp_var_for_callexp_8),
            "/home/shijia/Public/testprogram/e_cosh.c_e.c:138:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_9;
  }
  /* cosh overflow */

  double temp_var_for_ext_10;
  temp_var_for_ext_10 = z;
  AssignD({(Addr)&temp_var_for_ext_10}, (Addr)&z,
          "/home/shijia/Public/testprogram/e_cosh.c_e.c:146:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_10", (Addr)&temp_var_for_ext_10));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_10;
}

__typeof(__cosh) cosh __attribute__((weak, alias("__cosh")));
#ifdef __NO_LONG_DOUBLE_MATH
__typeof(__coshl) __coshl __attribute__((alias("__cosh")));
__typeof(__coshl) coshl __attribute__((weak, alias("__cosh")));
#endif
