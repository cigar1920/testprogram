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

/* __ieee754_coshl(x)
 * Method :
 * mathematically coshl(x) if defined to be (exp(x)+exp(-x))/2
 *	1. Replace x by |x| (coshl(x) = coshl(-x)).
 *	2.
 *							[ exp(x) - 1 ]^2
 *	    0        <= x <= ln2/2  :  coshl(x) := 1 + -------------------
 *							   2*exp(x)
 *
 *						   exp(x) +  1/exp(x)
 *	    ln2/2    <= x <= 22     :  coshl(x) := -------------------
 *							   2
 *	    22       <= x <= lnovft :  coshl(x) := expl(x)/2
 *	    lnovft   <= x <= ln2ovft:  coshl(x) := expl(x/2)/2 * expl(x/2)
 *	    ln2ovft  <  x	    :  coshl(x) := huge*huge (overflow)
 *
 * Special cases:
 *	coshl(x) is |x| if x is +INF, -INF, or NaN.
 *	only coshl(0)=1 is exact for finite x.
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

#ifndef __have_fpu_cosh

long double __ieee754_coshl(long double x) {
  long double t, w;
  int32_t ex;
  uint32_t mx, lx;

  static const long double one = 1.0;
  static const long double half = 0.5;
  static const long double hugeval = 1.0e4900L;

  /* High word of |x|. */
  long double temp_var_for_const_0;
  ew_u.value = x;
  AssignLd({(Addr) &(temp_var_for_const_0 = ew_u.value)}, (Addr)&x,
           "/home/shijia/Public/testprogram/e_coshl.c_e.c:51:3 "
           "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
  ;
  ex &= 0x7fff;

  /* x is INF or NaN */
  if (ex == 0x7fff) {
    long double temp_var_for_ext_0;
    long double temp_var_for_tac_0;
    temp_var_for_tac_0 = x * x;

    temp_var_for_ext_0 = temp_var_for_tac_0;
    computeLdMul((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&x},
                 "/home/shijia/Public/testprogram/e_coshl.c_e.c:57:28");
    AssignLd({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_0,
             "/home/shijia/Public/testprogram/e_coshl.c_e.c:57:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  /* |x| in [0,22] */
  if (ex < 0x4003 || (ex == 0x4003 && mx < UC(0xb0000000))) {
    /* |x| in [0,0.5*ln2], return 1+expm1l(|x|)^2/(2*expl(|x|)) */
    if (ex < 0x3ffd || (ex == 0x3ffd && mx < UC(0xb17217f7))) {
      long double temp_var_for_ext_1;
      long double temp_var_for_const_1;
      long double temp_var_for_callexp_0;

      /*embed fun has found*/
      long double temp_var_for_callexp_1;

      temp_var_for_callexp_0 = fabsl(x);
      temp_var_for_callexp_1 = __ieee754_expm1l(temp_var_for_callexp_0);
      temp_var_for_ext_1 = temp_var_for_callexp_1;
      AssignLd({(Addr)&temp_var_for_ext_1},
               (Addr) &(temp_var_for_const_1 = temp_var_for_callexp_1),
               "/home/shijia/Public/testprogram/e_coshl.c_e.c:68:26");
      ; // t
      /*(0)(t)(__ieee754_expm1l(__ieee754_fabsl(x)))*/
      t = temp_var_for_ext_1;
      AssignLd({(Addr)&t}, (Addr)&temp_var_for_ext_1,
               "/home/shijia/Public/testprogram/e_coshl.c_e.c:70:9");
      ;
      long double temp_var_for_tac_1;
      long double temp_var_for_const_2;
      temp_var_for_tac_1 = one + t;

      w = temp_var_for_tac_1;
      computeLdAdd((Addr)&temp_var_for_tac_1,
                   {(Addr) &(temp_var_for_const_2 = one), (Addr)&t},
                   "/home/shijia/Public/testprogram/e_coshl.c_e.c:71:15");
      AssignLd({(Addr)&w}, (Addr)&temp_var_for_tac_1,
               "/home/shijia/Public/testprogram/e_coshl.c_e.c:71:9");
      ;
      if (ex < 0x3fbc) {
        long double temp_var_for_ext_2;
        temp_var_for_ext_2 = w;
        AssignLd({(Addr)&temp_var_for_ext_2}, (Addr)&w,
                 "/home/shijia/Public/testprogram/e_coshl.c_e.c:74:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_2;
      }
      /* cosh(tiny) = 1 */
      long double temp_var_for_ext_3;
      long double temp_var_for_tac_2, temp_var_for_tac_3, temp_var_for_tac_4,
          temp_var_for_tac_5;
      long double temp_var_for_const_3;
      temp_var_for_tac_2 = t * t;

      temp_var_for_tac_3 = w + w;

      temp_var_for_tac_4 = temp_var_for_tac_2 / temp_var_for_tac_3;

      temp_var_for_tac_5 = one + temp_var_for_tac_4;

      temp_var_for_ext_3 = temp_var_for_tac_5;
      computeLdMul((Addr)&temp_var_for_tac_2, {(Addr)&t, (Addr)&t},
                   "/home/shijia/Public/testprogram/e_coshl.c_e.c:82:37");
      computeLdAdd((Addr)&temp_var_for_tac_3, {(Addr)&w, (Addr)&w},
                   "/home/shijia/Public/testprogram/e_coshl.c_e.c:82:47");
      computeLdDiv((Addr)&temp_var_for_tac_4,
                   {(Addr)&temp_var_for_tac_2, (Addr)&temp_var_for_tac_3},
                   "/home/shijia/Public/testprogram/e_coshl.c_e.c:82:42");
      computeLdAdd(
          (Addr)&temp_var_for_tac_5,
          {(Addr) &(temp_var_for_const_3 = one), (Addr)&temp_var_for_tac_4},
          "/home/shijia/Public/testprogram/e_coshl.c_e.c:82:32");
      AssignLd({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_5,
               "/home/shijia/Public/testprogram/e_coshl.c_e.c:82:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_3;
    }

    /* |x| in [0.5*ln2,22], return (exp(|x|)+1/exp(|x|)/2; */
    long double temp_var_for_ext_4;
    long double temp_var_for_const_4;
    long double temp_var_for_callexp_2;

    /*embed fun has found*/
    long double temp_var_for_callexp_3;

    temp_var_for_callexp_2 = fabsl(x);
    temp_var_for_callexp_3 = __ieee754_expl(temp_var_for_callexp_2);
    temp_var_for_ext_4 = temp_var_for_callexp_3;
    AssignLd({(Addr)&temp_var_for_ext_4},
             (Addr) &(temp_var_for_const_4 = temp_var_for_callexp_3),
             "/home/shijia/Public/testprogram/e_coshl.c_e.c:91:24");
    ; // t
    /*(t)(one)(_)(_)(a)(m)(tem)(_)(_)(a)(m)(a)(m)(_)(_)(__ieee754_expl(__ieee754_fabsl(x)))*/
    t = temp_var_for_ext_4;
    AssignLd({(Addr)&t}, (Addr)&temp_var_for_ext_4,
             "/home/shijia/Public/testprogram/e_coshl.c_e.c:93:7");
    ;
    long double temp_var_for_ext_5;
    long double temp_var_for_tac_6, temp_var_for_tac_7, temp_var_for_tac_8;
    long double temp_var_for_const_5, temp_var_for_const_6;
    temp_var_for_tac_6 = half * t;

    temp_var_for_tac_7 = half / t;

    temp_var_for_tac_8 = temp_var_for_tac_6 + temp_var_for_tac_7;

    temp_var_for_ext_5 = temp_var_for_tac_8;
    computeLdMul((Addr)&temp_var_for_tac_6,
                 {(Addr) &(temp_var_for_const_5 = half), (Addr)&t},
                 "/home/shijia/Public/testprogram/e_coshl.c_e.c:95:31");
    computeLdDiv((Addr)&temp_var_for_tac_7,
                 {(Addr) &(temp_var_for_const_6 = half), (Addr)&t},
                 "/home/shijia/Public/testprogram/e_coshl.c_e.c:95:42");
    computeLdAdd((Addr)&temp_var_for_tac_8,
                 {(Addr)&temp_var_for_tac_6, (Addr)&temp_var_for_tac_7},
                 "/home/shijia/Public/testprogram/e_coshl.c_e.c:95:35");
    AssignLd({(Addr)&temp_var_for_ext_5}, (Addr)&temp_var_for_tac_8,
             "/home/shijia/Public/testprogram/e_coshl.c_e.c:95:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_5;
  }

  /* |x| in [22, ln(maxdouble)] return half*exp(|x|) */
  if (ex < 0x400c || (ex == 0x400c && mx < UC(0xb1700000))) {
    long double temp_var_for_ext_6;
    long double temp_var_for_tac_9;
    long double temp_var_for_const_7, temp_var_for_const_8;
    long double temp_var_for_callexp_4;

    /*embed fun has found*/
    long double temp_var_for_callexp_5;

    temp_var_for_callexp_4 = fabsl(x);
    temp_var_for_callexp_5 = __ieee754_expl(temp_var_for_callexp_4);
    temp_var_for_tac_9 = half * temp_var_for_callexp_5;

    temp_var_for_ext_6 = temp_var_for_tac_9;
    computeLdMul((Addr)&temp_var_for_tac_9,
                 {(Addr) &(temp_var_for_const_8 = half),
                  (Addr) &(temp_var_for_const_7 = temp_var_for_callexp_5)},
                 "/home/shijia/Public/testprogram/e_coshl.c_e.c:104:31");
    AssignLd({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_9,
             "/home/shijia/Public/testprogram/e_coshl.c_e.c:104:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_6;
  }

  /* |x| in [log(maxdouble), log(2*maxdouble)) */
  if (ex == 0x400c &&
      (mx < UC(0xb174ddc0) || (mx == UC(0xb174ddc0) && lx < UC(0x31aec0eb)))) {
    long double temp_var_for_tac_10;
    long double temp_var_for_const_9, temp_var_for_const_10,
        temp_var_for_const_11;
    long double temp_var_for_callexp_6;

    long double temp_var_for_callexp_7;

    temp_var_for_callexp_6 = fabsl(x);
    temp_var_for_tac_10 = half * temp_var_for_callexp_6;

    temp_var_for_callexp_7 = __ieee754_expl(temp_var_for_tac_10);
    w = temp_var_for_callexp_7;
    computeLdMul((Addr)&temp_var_for_tac_10,
                 {(Addr) &(temp_var_for_const_10 = half),
                  (Addr) &(temp_var_for_const_9 = temp_var_for_callexp_6)},
                 "/home/shijia/Public/testprogram/e_coshl.c_e.c:113:29");
    AssignLd({(Addr)&w},
             (Addr) &(temp_var_for_const_11 = temp_var_for_callexp_7),
             "/home/shijia/Public/testprogram/e_coshl.c_e.c:113:7");
    ;
    long double temp_var_for_tac_11;
    long double temp_var_for_const_12;
    temp_var_for_tac_11 = half * w;

    t = temp_var_for_tac_11;
    computeLdMul((Addr)&temp_var_for_tac_11,
                 {(Addr) &(temp_var_for_const_12 = half), (Addr)&w},
                 "/home/shijia/Public/testprogram/e_coshl.c_e.c:114:14");
    AssignLd({(Addr)&t}, (Addr)&temp_var_for_tac_11,
             "/home/shijia/Public/testprogram/e_coshl.c_e.c:114:7");
    ;
    long double temp_var_for_ext_7;
    long double temp_var_for_tac_12;
    temp_var_for_tac_12 = t * w;

    temp_var_for_ext_7 = temp_var_for_tac_12;
    computeLdMul((Addr)&temp_var_for_tac_12, {(Addr)&t, (Addr)&w},
                 "/home/shijia/Public/testprogram/e_coshl.c_e.c:116:28");
    AssignLd({(Addr)&temp_var_for_ext_7}, (Addr)&temp_var_for_tac_12,
             "/home/shijia/Public/testprogram/e_coshl.c_e.c:116:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_7;
  }

  /* |x| >= log(2*maxdouble), cosh(x) overflow */
  long double temp_var_for_ext_8;
  long double temp_var_for_tac_13;
  long double temp_var_for_const_13, temp_var_for_const_14;
  temp_var_for_tac_13 = hugeval * hugeval;

  temp_var_for_ext_8 = temp_var_for_tac_13;
  computeLdMul((Addr)&temp_var_for_tac_13,
               {(Addr) &(temp_var_for_const_14 = hugeval),
                (Addr) &(temp_var_for_const_13 = hugeval)},
               "/home/shijia/Public/testprogram/e_coshl.c_e.c:124:32");
  AssignLd({(Addr)&temp_var_for_ext_8}, (Addr)&temp_var_for_tac_13,
           "/home/shijia/Public/testprogram/e_coshl.c_e.c:124:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_8;
}

#endif

long double __coshl(long double x) {
  long double z = __ieee754_coshl(x);

  if (!isfinite(z) && isfinite(x) && _LIB_VERSION != _IEEE_) {
    long double temp_var_for_ext_9;
    long double temp_var_for_const_15;
    long double temp_var_for_callexp_8;

    temp_var_for_callexp_8 = __kernel_standard_l(x, x, z, KMATHERRL_COSH);
    temp_var_for_ext_9 = temp_var_for_callexp_8;
    AssignLd({(Addr)&temp_var_for_ext_9},
             (Addr) &(temp_var_for_const_15 = temp_var_for_callexp_8),
             "/home/shijia/Public/testprogram/e_coshl.c_e.c:137:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_9;
  }
  /* cosh overflow */

  long double temp_var_for_ext_10;
  temp_var_for_ext_10 = z;
  AssignLd({(Addr)&temp_var_for_ext_10}, (Addr)&z,
           "/home/shijia/Public/testprogram/e_coshl.c_e.c:145:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_10", (Addr)&temp_var_for_ext_10));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_10;
}

__typeof(__coshl) coshl __attribute__((weak, alias("__coshl")));

#endif
