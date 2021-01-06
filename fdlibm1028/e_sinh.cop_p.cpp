#include "../ScDebug/scdebug.h"
/* @(#)e_sinh.c 1.3 95/01/18 */
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

/* __ieee754_sinh(x)
 * Method :
 * mathematically sinh(x) if defined to be (exp(x)-exp(-x))/2
 *	1. Replace x by |x| (sinh(-x) = -sinh(x)).
 *	2.
 *						    E + E/(E+1)
 *	    0        <= x <= 22     :  sinh(x) := --------------, E=expm1(x)
 *							2
 *
 *	    22       <= x <= lnovft :  sinh(x) := exp(x)/2
 *	    lnovft   <= x <= ln2ovft:  sinh(x) := exp(x/2)/2 * exp(x/2)
 *	    ln2ovft  <  x	    :  sinh(x) := x*shuge (overflow)
 *
 * Special cases:
 *	sinh(x) is |x| if x is +INF, -INF, or NaN.
 *	only sinh(0)=0 is exact for finite x.
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_sinh

double __ieee754_sinh(double x) {
  double t, w, h;
  int32_t ix, jx;
  uint32_t lx;

  static const double one = 1.0;
  static const double shuge = 1.0e307;

  /* High word of |x|. */
  GET_HIGH_WORD(jx, x);
  ix = jx & IC(0x7fffffff);

  /* x is INF or NaN */
  if (ix >= IC(0x7ff00000)) {
    double temp_var_for_ext_0;
    double temp_var_for_tac_0;
    temp_var_for_tac_0 = x + x;

    temp_var_for_ext_0 = temp_var_for_tac_0;
    computeDAdd((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_sinh.c_e.c:52:28");
    AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_0,
            "/home/shijia/Public/testprogram/e_sinh.c_e.c:52:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  double temp_var_for_const_0;
  h = 0.5;
  AssignD({(Addr)&h}, (Addr) &(temp_var_for_const_0 = 0.5),
          "/home/shijia/Public/testprogram/e_sinh.c_e.c:58:5");
  ;
  if (jx < 0) {
    double temp_var_for_ext_1;
    double temp_var_for_tac_1;
    double temp_var_for_const_1;
    temp_var_for_tac_1 = 0.0 - h;

    temp_var_for_ext_1 = temp_var_for_tac_1;
    computeDSub((Addr)&temp_var_for_tac_1,
                {(Addr) &(temp_var_for_const_1 = 0.0), (Addr)&h},
                "/home/shijia/Public/testprogram/e_sinh.c_e.c:61:31");
    AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_1,
            "/home/shijia/Public/testprogram/e_sinh.c_e.c:61:24");
    ; // h
    /*(h)(h)*/
    h = temp_var_for_ext_1;
    AssignD({(Addr)&h}, (Addr)&temp_var_for_ext_1,
            "/home/shijia/Public/testprogram/e_sinh.c_e.c:63:7");
    ;
  }

  /* |x| in [0,22], return sign(x)*0.5*(E+E/(E+1))) */
  if (ix < IC(0x40360000)) { /* |x|<22 */
    if (ix < IC(0x3e300000)) /* |x|<2**-28 */
    {
      if (int temp_var_for_tac_2, temp_var_for_tac_3;
          int temp_var_for_const_2, temp_var_for_const_3;
          temp_var_for_tac_2 = shuge + x;

          temp_var_for_tac_3 = temp_var_for_tac_2 > one;

          ) {
        double temp_var_for_ext_2;
        temp_var_for_ext_2 = x;
        computeDAdd((Addr)&temp_var_for_tac_2,
                    {(Addr) &(temp_var_for_const_2 = shuge), (Addr)&x},
                    "/home/shijia/Public/testprogram/e_sinh.c_e.c:70:17");
        compute(
            (Addr)&temp_var_for_tac_3,
            {(Addr)&temp_var_for_tac_2, (Addr) &(temp_var_for_const_3 = one)},
            "/home/shijia/Public/testprogram/e_sinh.c_e.c:70:21");
        AssignD({(Addr)&temp_var_for_ext_2}, (Addr)&x,
                "/home/shijia/Public/testprogram/e_sinh.c_e.c:72:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_2;
      }
    }
    /* sinh(tiny) = tiny with inexact */
    double temp_var_for_const_4;
    double temp_var_for_callexp_0;

    /*embed fun has found*/
    double temp_var_for_callexp_1;

    temp_var_for_callexp_0 = fabs(x);
    temp_var_for_callexp_1 = __ieee754_expm1(temp_var_for_callexp_0);
    t = temp_var_for_callexp_1;
    AssignD({(Addr)&t}, (Addr) &(temp_var_for_const_4 = temp_var_for_callexp_1),
            "/home/shijia/Public/testprogram/e_sinh.c_e.c:80:7");
    ;
    if (ix < IC(0x3ff00000)) {
      double temp_var_for_ext_3;
      double temp_var_for_tac_4, temp_var_for_tac_5, temp_var_for_tac_6,
          temp_var_for_tac_7, temp_var_for_tac_8, temp_var_for_tac_9;
      double temp_var_for_const_5, temp_var_for_const_6;
      temp_var_for_tac_4 = 2.0 * t;

      temp_var_for_tac_5 = t * t;

      temp_var_for_tac_6 = t + one;

      temp_var_for_tac_7 = temp_var_for_tac_5 / temp_var_for_tac_6;

      temp_var_for_tac_8 = temp_var_for_tac_4 - temp_var_for_tac_7;

      temp_var_for_tac_9 = h * temp_var_for_tac_8;

      temp_var_for_ext_3 = temp_var_for_tac_9;
      computeDMul((Addr)&temp_var_for_tac_4,
                  {(Addr) &(temp_var_for_const_5 = 2.0), (Addr)&t},
                  "/home/shijia/Public/testprogram/e_sinh.c_e.c:83:37");
      computeDMul((Addr)&temp_var_for_tac_5, {(Addr)&t, (Addr)&t},
                  "/home/shijia/Public/testprogram/e_sinh.c_e.c:83:45");
      computeDAdd((Addr)&temp_var_for_tac_6,
                  {(Addr)&t, (Addr) &(temp_var_for_const_6 = one)},
                  "/home/shijia/Public/testprogram/e_sinh.c_e.c:83:54");
      computeDDiv((Addr)&temp_var_for_tac_7,
                  {(Addr)&temp_var_for_tac_5, (Addr)&temp_var_for_tac_6},
                  "/home/shijia/Public/testprogram/e_sinh.c_e.c:83:49");
      computeDSub((Addr)&temp_var_for_tac_8,
                  {(Addr)&temp_var_for_tac_4, (Addr)&temp_var_for_tac_7},
                  "/home/shijia/Public/testprogram/e_sinh.c_e.c:83:41");
      computeDMul((Addr)&temp_var_for_tac_9,
                  {(Addr)&h, (Addr)&temp_var_for_tac_8},
                  "/home/shijia/Public/testprogram/e_sinh.c_e.c:83:30");
      AssignD({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_9,
              "/home/shijia/Public/testprogram/e_sinh.c_e.c:83:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_3;
    }

    double temp_var_for_ext_4;
    double temp_var_for_tac_10, temp_var_for_tac_11, temp_var_for_tac_12,
        temp_var_for_tac_13;
    double temp_var_for_const_7;
    temp_var_for_tac_10 = t + one;

    temp_var_for_tac_11 = t / temp_var_for_tac_10;

    temp_var_for_tac_12 = t + temp_var_for_tac_11;

    temp_var_for_tac_13 = h * temp_var_for_tac_12;

    temp_var_for_ext_4 = temp_var_for_tac_13;
    computeDAdd((Addr)&temp_var_for_tac_10,
                {(Addr)&t, (Addr) &(temp_var_for_const_7 = one)},
                "/home/shijia/Public/testprogram/e_sinh.c_e.c:91:42");
    computeDDiv((Addr)&temp_var_for_tac_11,
                {(Addr)&t, (Addr)&temp_var_for_tac_10},
                "/home/shijia/Public/testprogram/e_sinh.c_e.c:91:37");
    computeDAdd((Addr)&temp_var_for_tac_12,
                {(Addr)&t, (Addr)&temp_var_for_tac_11},
                "/home/shijia/Public/testprogram/e_sinh.c_e.c:91:33");
    computeDMul((Addr)&temp_var_for_tac_13,
                {(Addr)&h, (Addr)&temp_var_for_tac_12},
                "/home/shijia/Public/testprogram/e_sinh.c_e.c:91:28");
    AssignD({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_13,
            "/home/shijia/Public/testprogram/e_sinh.c_e.c:91:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_4;
  }

  /* |x| in [22, log(maxdouble)] return 0.5*exp(|x|) */
  if (ix < IC(0x40862e42)) {
    double temp_var_for_ext_5;
    double temp_var_for_tac_14;
    double temp_var_for_const_8;
    double temp_var_for_callexp_2;

    /*embed fun has found*/
    double temp_var_for_callexp_3;

    temp_var_for_callexp_2 = fabs(x);
    temp_var_for_callexp_3 = __ieee754_exp(temp_var_for_callexp_2);
    temp_var_for_tac_14 = h * temp_var_for_callexp_3;

    temp_var_for_ext_5 = temp_var_for_tac_14;
    computeDMul(
        (Addr)&temp_var_for_tac_14,
        {(Addr)&h, (Addr) &(temp_var_for_const_8 = temp_var_for_callexp_3)},
        "/home/shijia/Public/testprogram/e_sinh.c_e.c:100:28");
    AssignD({(Addr)&temp_var_for_ext_5}, (Addr)&temp_var_for_tac_14,
            "/home/shijia/Public/testprogram/e_sinh.c_e.c:100:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_5;
  }

  /* |x| in [log(maxdouble), overflowthresold] */
  GET_LOW_WORD(lx, x);
  if (ix < IC(0x408633ce) || (ix == IC(0x408633ce) && lx <= UC(0x8fb9f87d))) {
    double temp_var_for_tac_15;
    double temp_var_for_const_9, temp_var_for_const_10, temp_var_for_const_11;
    double temp_var_for_callexp_4;

    double temp_var_for_callexp_5;

    temp_var_for_callexp_4 = fabs(x);
    temp_var_for_tac_15 = 0.5 * temp_var_for_callexp_4;

    temp_var_for_callexp_5 = __ieee754_exp(temp_var_for_tac_15);
    w = temp_var_for_callexp_5;
    computeDMul((Addr)&temp_var_for_tac_15,
                {(Addr) &(temp_var_for_const_10 = 0.5),
                 (Addr) &(temp_var_for_const_9 = temp_var_for_callexp_4)},
                "/home/shijia/Public/testprogram/e_sinh.c_e.c:109:27");
    AssignD({(Addr)&w},
            (Addr) &(temp_var_for_const_11 = temp_var_for_callexp_5),
            "/home/shijia/Public/testprogram/e_sinh.c_e.c:109:7");
    ;
    double temp_var_for_tac_16;
    temp_var_for_tac_16 = h * w;

    t = temp_var_for_tac_16;
    computeDMul((Addr)&temp_var_for_tac_16, {(Addr)&h, (Addr)&w},
                "/home/shijia/Public/testprogram/e_sinh.c_e.c:110:11");
    AssignD({(Addr)&t}, (Addr)&temp_var_for_tac_16,
            "/home/shijia/Public/testprogram/e_sinh.c_e.c:110:7");
    ;
    double temp_var_for_ext_6;
    double temp_var_for_tac_17;
    temp_var_for_tac_17 = t * w;

    temp_var_for_ext_6 = temp_var_for_tac_17;
    computeDMul((Addr)&temp_var_for_tac_17, {(Addr)&t, (Addr)&w},
                "/home/shijia/Public/testprogram/e_sinh.c_e.c:112:28");
    AssignD({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_17,
            "/home/shijia/Public/testprogram/e_sinh.c_e.c:112:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_6;
  }

  /* |x| > overflowthresold, sinh(x) overflow */
  double temp_var_for_ext_7;
  double temp_var_for_tac_18;
  double temp_var_for_const_12;
  temp_var_for_tac_18 = x * shuge;

  temp_var_for_ext_7 = temp_var_for_tac_18;
  computeDMul((Addr)&temp_var_for_tac_18,
              {(Addr)&x, (Addr) &(temp_var_for_const_12 = shuge)},
              "/home/shijia/Public/testprogram/e_sinh.c_e.c:120:26");
  AssignD({(Addr)&temp_var_for_ext_7}, (Addr)&temp_var_for_tac_18,
          "/home/shijia/Public/testprogram/e_sinh.c_e.c:120:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_7;
}

#endif

/* wrapper sinh */
double __sinh(double x) {
  double z = __ieee754_sinh(x);

  if (_LIB_VERSION != _IEEE_ && !isfinite(z) && isfinite(x)) {
    double temp_var_for_ext_8;
    double temp_var_for_const_13;
    double temp_var_for_callexp_6;

    temp_var_for_callexp_6 = __kernel_standard(x, x, z, KMATHERR_SINH);
    temp_var_for_ext_8 = temp_var_for_callexp_6;
    AssignD({(Addr)&temp_var_for_ext_8},
            (Addr) &(temp_var_for_const_13 = temp_var_for_callexp_6),
            "/home/shijia/Public/testprogram/e_sinh.c_e.c:134:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_8;
  }
  /* sinh overflow */

  double temp_var_for_ext_9;
  temp_var_for_ext_9 = z;
  AssignD({(Addr)&temp_var_for_ext_9}, (Addr)&z,
          "/home/shijia/Public/testprogram/e_sinh.c_e.c:142:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_9;
}

__typeof(__sinh) sinh __attribute__((weak, alias("__sinh")));
#ifdef __NO_LONG_DOUBLE_MATH
__typeof(__sinhl) __sinhl __attribute__((alias("__sinh")));
__typeof(__sinhl) sinhl __attribute__((weak, alias("__sinh")));
#endif
