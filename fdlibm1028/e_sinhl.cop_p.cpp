#include "../ScDebug/scdebug.h"
/* e_asinhl.c -- long double version of e_asinh.c.
 * Conversion to long double by Ulrich Drepper,
 * Cygnus Support, drepper@cygnus.com.
 */

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

/* __ieee754_sinhl(x)
 * Method :
 * mathematically sinh(x) if defined to be (exp(x)-exp(-x))/2
 *	1. Replace x by |x| (sinhl(-x) = -sinhl(x)).
 *	2.
 *						     E + E/(E+1)
 *	    0        <= x <= 25     :  sinhl(x) := --------------, E=expm1l(x)
 *							 2
 *
 *	    25       <= x <= lnovft :  sinhl(x) := expl(x)/2
 *	    lnovft   <= x <= ln2ovft:  sinhl(x) := expl(x/2)/2 * expl(x/2)
 *	    ln2ovft  <  x	    :  sinhl(x) := x*shuge (overflow)
 *
 * Special cases:
 *	sinhl(x) is |x| if x is +INF, -INF, or NaN.
 *	only sinhl(0)=0 is exact for finite x.
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

#ifndef __have_fpu_sinh

long double __ieee754_sinhl(long double x) {
  long double t, w, h;
  uint32_t jx, ix, i0, i1;

  static const long double one = 1.0;
  static const long double shuge = 1.0e4931L;

  /* Words of |x|. */
  long double temp_var_for_const_0;
  ew_u.value = x;
  AssignLd({(Addr) &(temp_var_for_const_0 = ew_u.value)}, (Addr)&x,
           "/home/shijia/Public/testprogram/e_sinhl.c_e.c:51:3 "
           "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
  ;
  ix = jx & IEEE854_LONG_DOUBLE_MAXEXP;

  /* x is INF or NaN */
  if (ix == IEEE854_LONG_DOUBLE_MAXEXP) {
    long double temp_var_for_ext_0;
    long double temp_var_for_tac_0;
    temp_var_for_tac_0 = x + x;

    temp_var_for_ext_0 = temp_var_for_tac_0;
    computeLdAdd((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&x},
                 "/home/shijia/Public/testprogram/e_sinhl.c_e.c:57:28");
    AssignLd({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_0,
             "/home/shijia/Public/testprogram/e_sinhl.c_e.c:57:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  long double temp_var_for_const_1;
  h = 0.5;
  AssignLd({(Addr)&h}, (Addr) &(temp_var_for_const_1 = 0.5),
           "/home/shijia/Public/testprogram/e_sinhl.c_e.c:63:5");
  ;
  if (jx & 0x8000) {
    long double temp_var_for_ext_1;
    long double temp_var_for_tac_1;
    long double temp_var_for_const_2;
    temp_var_for_tac_1 = 0.0 - h;

    temp_var_for_ext_1 = temp_var_for_tac_1;
    computeLdSub((Addr)&temp_var_for_tac_1,
                 {(Addr) &(temp_var_for_const_2 = 0.0), (Addr)&h},
                 "/home/shijia/Public/testprogram/e_sinhl.c_e.c:66:31");
    AssignLd({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_1,
             "/home/shijia/Public/testprogram/e_sinhl.c_e.c:66:24");
    ; // h
    /*(h)(h)*/
    h = temp_var_for_ext_1;
    AssignLd({(Addr)&h}, (Addr)&temp_var_for_ext_1,
             "/home/shijia/Public/testprogram/e_sinhl.c_e.c:68:7");
    ;
  }

  /* |x| in [0,25], return sign(x)*0.5*(E+E/(E+1))) */
  if (ix < 0x4003 || (ix == 0x4003 && i0 <= UC(0xc8000000))) { /* |x|<25 */
    if (ix < 0x3fdf)                                           /* |x|<2**-32 */
    {
      if (int temp_var_for_tac_2, temp_var_for_tac_3;
          int temp_var_for_const_3, temp_var_for_const_4;
          temp_var_for_tac_2 = shuge + x;

          temp_var_for_tac_3 = temp_var_for_tac_2 > one;

          ) {
        long double temp_var_for_ext_2;
        temp_var_for_ext_2 = x;
        computeLdAdd((Addr)&temp_var_for_tac_2,
                     {(Addr) &(temp_var_for_const_3 = shuge), (Addr)&x},
                     "/home/shijia/Public/testprogram/e_sinhl.c_e.c:75:17");
        compute(
            (Addr)&temp_var_for_tac_3,
            {(Addr)&temp_var_for_tac_2, (Addr) &(temp_var_for_const_4 = one)},
            "/home/shijia/Public/testprogram/e_sinhl.c_e.c:75:21");
        AssignLd({(Addr)&temp_var_for_ext_2}, (Addr)&x,
                 "/home/shijia/Public/testprogram/e_sinhl.c_e.c:77:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_2;
      }
    }
    /* sinh(tiny) = tiny with inexact */
    long double temp_var_for_const_5;
    long double temp_var_for_callexp_0;

    /*embed fun has found*/
    long double temp_var_for_callexp_1;

    temp_var_for_callexp_0 = fabsl(x);
    temp_var_for_callexp_1 = __ieee754_expm1l(temp_var_for_callexp_0);
    t = temp_var_for_callexp_1;
    AssignLd({(Addr)&t},
             (Addr) &(temp_var_for_const_5 = temp_var_for_callexp_1),
             "/home/shijia/Public/testprogram/e_sinhl.c_e.c:85:7");
    ;
    if (ix < 0x3fff) {
      long double temp_var_for_ext_3;
      long double temp_var_for_tac_4, temp_var_for_tac_5, temp_var_for_tac_6,
          temp_var_for_tac_7, temp_var_for_tac_8, temp_var_for_tac_9;
      long double temp_var_for_const_6, temp_var_for_const_7;
      temp_var_for_tac_4 = 2.0 * t;

      temp_var_for_tac_5 = t * t;

      temp_var_for_tac_6 = t + one;

      temp_var_for_tac_7 = temp_var_for_tac_5 / temp_var_for_tac_6;

      temp_var_for_tac_8 = temp_var_for_tac_4 - temp_var_for_tac_7;

      temp_var_for_tac_9 = h * temp_var_for_tac_8;

      temp_var_for_ext_3 = temp_var_for_tac_9;
      computeLdMul((Addr)&temp_var_for_tac_4,
                   {(Addr) &(temp_var_for_const_6 = 2.0), (Addr)&t},
                   "/home/shijia/Public/testprogram/e_sinhl.c_e.c:88:37");
      computeLdMul((Addr)&temp_var_for_tac_5, {(Addr)&t, (Addr)&t},
                   "/home/shijia/Public/testprogram/e_sinhl.c_e.c:88:45");
      computeLdAdd((Addr)&temp_var_for_tac_6,
                   {(Addr)&t, (Addr) &(temp_var_for_const_7 = one)},
                   "/home/shijia/Public/testprogram/e_sinhl.c_e.c:88:54");
      computeLdDiv((Addr)&temp_var_for_tac_7,
                   {(Addr)&temp_var_for_tac_5, (Addr)&temp_var_for_tac_6},
                   "/home/shijia/Public/testprogram/e_sinhl.c_e.c:88:49");
      computeLdSub((Addr)&temp_var_for_tac_8,
                   {(Addr)&temp_var_for_tac_4, (Addr)&temp_var_for_tac_7},
                   "/home/shijia/Public/testprogram/e_sinhl.c_e.c:88:41");
      computeLdMul((Addr)&temp_var_for_tac_9,
                   {(Addr)&h, (Addr)&temp_var_for_tac_8},
                   "/home/shijia/Public/testprogram/e_sinhl.c_e.c:88:30");
      AssignLd({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_9,
               "/home/shijia/Public/testprogram/e_sinhl.c_e.c:88:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_3;
    }

    long double temp_var_for_ext_4;
    long double temp_var_for_tac_10, temp_var_for_tac_11, temp_var_for_tac_12,
        temp_var_for_tac_13;
    long double temp_var_for_const_8;
    temp_var_for_tac_10 = t + one;

    temp_var_for_tac_11 = t / temp_var_for_tac_10;

    temp_var_for_tac_12 = t + temp_var_for_tac_11;

    temp_var_for_tac_13 = h * temp_var_for_tac_12;

    temp_var_for_ext_4 = temp_var_for_tac_13;
    computeLdAdd((Addr)&temp_var_for_tac_10,
                 {(Addr)&t, (Addr) &(temp_var_for_const_8 = one)},
                 "/home/shijia/Public/testprogram/e_sinhl.c_e.c:96:42");
    computeLdDiv((Addr)&temp_var_for_tac_11,
                 {(Addr)&t, (Addr)&temp_var_for_tac_10},
                 "/home/shijia/Public/testprogram/e_sinhl.c_e.c:96:37");
    computeLdAdd((Addr)&temp_var_for_tac_12,
                 {(Addr)&t, (Addr)&temp_var_for_tac_11},
                 "/home/shijia/Public/testprogram/e_sinhl.c_e.c:96:33");
    computeLdMul((Addr)&temp_var_for_tac_13,
                 {(Addr)&h, (Addr)&temp_var_for_tac_12},
                 "/home/shijia/Public/testprogram/e_sinhl.c_e.c:96:28");
    AssignLd({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_13,
             "/home/shijia/Public/testprogram/e_sinhl.c_e.c:96:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_4;
  }

  /* |x| in [25, log(maxdouble)] return 0.5*exp(|x|) */
  if (ix < 0x400c || (ix == 0x400c && i0 < UC(0xb17217f7))) {
    long double temp_var_for_ext_5;
    long double temp_var_for_tac_14;
    long double temp_var_for_const_9;
    long double temp_var_for_callexp_2;

    /*embed fun has found*/
    long double temp_var_for_callexp_3;

    temp_var_for_callexp_2 = fabsl(x);
    temp_var_for_callexp_3 = __ieee754_expl(temp_var_for_callexp_2);
    temp_var_for_tac_14 = h * temp_var_for_callexp_3;

    temp_var_for_ext_5 = temp_var_for_tac_14;
    computeLdMul(
        (Addr)&temp_var_for_tac_14,
        {(Addr)&h, (Addr) &(temp_var_for_const_9 = temp_var_for_callexp_3)},
        "/home/shijia/Public/testprogram/e_sinhl.c_e.c:105:28");
    AssignLd({(Addr)&temp_var_for_ext_5}, (Addr)&temp_var_for_tac_14,
             "/home/shijia/Public/testprogram/e_sinhl.c_e.c:105:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_5;
  }

  /* |x| in [log(maxdouble), overflowthreshold] */
  if (ix < 0x400c ||
      (ix == 0x400c && (i0 < UC(0xb174ddc0) ||
                        (i0 == UC(0xb174ddc0) && i1 <= UC(0x31aec0ea))))) {
    long double temp_var_for_tac_15;
    long double temp_var_for_const_10, temp_var_for_const_11,
        temp_var_for_const_12;
    long double temp_var_for_callexp_4;

    long double temp_var_for_callexp_5;

    temp_var_for_callexp_4 = fabsl(x);
    temp_var_for_tac_15 = 0.5 * temp_var_for_callexp_4;

    temp_var_for_callexp_5 = __ieee754_expl(temp_var_for_tac_15);
    w = temp_var_for_callexp_5;
    computeLdMul((Addr)&temp_var_for_tac_15,
                 {(Addr) &(temp_var_for_const_11 = 0.5),
                  (Addr) &(temp_var_for_const_10 = temp_var_for_callexp_4)},
                 "/home/shijia/Public/testprogram/e_sinhl.c_e.c:115:28");
    AssignLd({(Addr)&w},
             (Addr) &(temp_var_for_const_12 = temp_var_for_callexp_5),
             "/home/shijia/Public/testprogram/e_sinhl.c_e.c:115:7");
    ;
    long double temp_var_for_tac_16;
    temp_var_for_tac_16 = h * w;

    t = temp_var_for_tac_16;
    computeLdMul((Addr)&temp_var_for_tac_16, {(Addr)&h, (Addr)&w},
                 "/home/shijia/Public/testprogram/e_sinhl.c_e.c:116:11");
    AssignLd({(Addr)&t}, (Addr)&temp_var_for_tac_16,
             "/home/shijia/Public/testprogram/e_sinhl.c_e.c:116:7");
    ;
    long double temp_var_for_ext_6;
    long double temp_var_for_tac_17;
    temp_var_for_tac_17 = t * w;

    temp_var_for_ext_6 = temp_var_for_tac_17;
    computeLdMul((Addr)&temp_var_for_tac_17, {(Addr)&t, (Addr)&w},
                 "/home/shijia/Public/testprogram/e_sinhl.c_e.c:118:28");
    AssignLd({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_17,
             "/home/shijia/Public/testprogram/e_sinhl.c_e.c:118:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_6;
  }

  /* |x| > overflowthreshold, sinhl(x) overflow */
  long double temp_var_for_ext_7;
  long double temp_var_for_tac_18;
  long double temp_var_for_const_13;
  temp_var_for_tac_18 = x * shuge;

  temp_var_for_ext_7 = temp_var_for_tac_18;
  computeLdMul((Addr)&temp_var_for_tac_18,
               {(Addr)&x, (Addr) &(temp_var_for_const_13 = shuge)},
               "/home/shijia/Public/testprogram/e_sinhl.c_e.c:126:26");
  AssignLd({(Addr)&temp_var_for_ext_7}, (Addr)&temp_var_for_tac_18,
           "/home/shijia/Public/testprogram/e_sinhl.c_e.c:126:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_7;
}

#endif

long double __sinhl(long double x) {
  long double z = __ieee754_sinhl(x);

  if (!isfinite(z) && isfinite(x) && _LIB_VERSION != _IEEE_) {
    long double temp_var_for_ext_8;
    long double temp_var_for_const_14;
    long double temp_var_for_callexp_6;

    temp_var_for_callexp_6 = __kernel_standard_l(x, x, z, KMATHERRL_SINH);
    temp_var_for_ext_8 = temp_var_for_callexp_6;
    AssignLd({(Addr)&temp_var_for_ext_8},
             (Addr) &(temp_var_for_const_14 = temp_var_for_callexp_6),
             "/home/shijia/Public/testprogram/e_sinhl.c_e.c:139:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_8;
  }
  /* sinh overflow */

  long double temp_var_for_ext_9;
  temp_var_for_ext_9 = z;
  AssignLd({(Addr)&temp_var_for_ext_9}, (Addr)&z,
           "/home/shijia/Public/testprogram/e_sinhl.c_e.c:147:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_9;
}

__typeof(__sinhl) sinhl __attribute__((weak, alias("__sinhl")));

#endif
