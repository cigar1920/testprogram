#include "../ScDebug/scdebug.h"
/* s_atanhl.c -- long double version of s_atan.c.
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

/* __ieee754_atanhl(x)
 * Method :
 *    1.Reduced x to positive by atanh(-x) = -atanh(x)
 *    2.For x>=0.5
 *                   1              2x                          x
 *	atanhl(x) = --- * log(1 + -------) = 0.5 * log1p(2 * --------)
 *                   2             1 - x                      1 - x
 *
 *	For x<0.5
 *	atanhl(x) = 0.5*log1pl(2x+2x*x/(1-x))
 *
 * Special cases:
 *	atanhl(x) is NaN if |x| > 1 with signal;
 *	atanhl(NaN) is that NaN with no signal;
 *	atanhl(+-1) is +-INF with signal.
 *
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

#ifndef __have_fpu_atanh

long double __ieee754_atanhl(long double x) {
  long double t;
  int32_t ix;
  uint32_t i0, i1;
  int32_t se;

  static const long double one = 1.0;
  static const long double hugeval = 1e4900L;
  static const long double zero = 0.0;

  long double temp_var_for_const_0;
  ew_u.value = x;
  AssignLd({(Addr) &(temp_var_for_const_0 = ew_u.value)}, (Addr)&x,
           "/home/shijia/Public/testprogram/e_atanhl.c_e.c:53:3 "
           "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
  ;
  ix = se & 0x7fff;
  if ((ix + ((((i0 & IC(0x7fffffff)) | i1) | (-((i0 & IC(0x7fffffff)) | i1))) >>
             31)) > 0x3fff)
  /* |x|>1 */
  {
    long double temp_var_for_ext_0;
    long double temp_var_for_tac_0, temp_var_for_tac_1, temp_var_for_tac_2;
    temp_var_for_tac_0 = x - x;

    temp_var_for_tac_1 = x - x;

    temp_var_for_tac_2 = temp_var_for_tac_0 / temp_var_for_tac_1;

    temp_var_for_ext_0 = temp_var_for_tac_2;
    computeLdSub((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&x},
                 "/home/shijia/Public/testprogram/e_atanhl.c_e.c:60:29");
    computeLdSub((Addr)&temp_var_for_tac_1, {(Addr)&x, (Addr)&x},
                 "/home/shijia/Public/testprogram/e_atanhl.c_e.c:60:39");
    computeLdDiv((Addr)&temp_var_for_tac_2,
                 {(Addr)&temp_var_for_tac_0, (Addr)&temp_var_for_tac_1},
                 "/home/shijia/Public/testprogram/e_atanhl.c_e.c:60:34");
    AssignLd({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_2,
             "/home/shijia/Public/testprogram/e_atanhl.c_e.c:60:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  if (ix == 0x3fff) {
    long double temp_var_for_ext_1;
    long double temp_var_for_tac_3;
    long double temp_var_for_const_1;
    temp_var_for_tac_3 = x / zero;

    temp_var_for_ext_1 = temp_var_for_tac_3;
    computeLdDiv((Addr)&temp_var_for_tac_3,
                 {(Addr)&x, (Addr) &(temp_var_for_const_1 = zero)},
                 "/home/shijia/Public/testprogram/e_atanhl.c_e.c:68:28");
    AssignLd({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_3,
             "/home/shijia/Public/testprogram/e_atanhl.c_e.c:68:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }

  if (ix < 0x3fe3) {
    math_force_eval(hugeval + x);
    long double temp_var_for_ext_2;
    temp_var_for_ext_2 = x;
    computeLdAdd((Addr)&temp_var_for_tac_4,
                 {(Addr) &(temp_var_for_const_2 = hugeval), (Addr)&x},
                 "/home/shijia/Public/testprogram/e_atanhl.c_e.c:75:5 "
                 "<Spelling=/home/shijia/Public/testprogram/"
                 "e_atanhl.c_e.c:75:29>");
    computeLdAdd((Addr)&temp_var_for_tac_5,
                 {(Addr) &(temp_var_for_const_3 = hugeval), (Addr)&x},
                 "/home/shijia/Public/testprogram/e_atanhl.c_e.c:75:5 "
                 "<Spelling=/home/shijia/Public/testprogram/"
                 "e_atanhl.c_e.c:75:29>");
    AssignLd({(Addr)&temp_var_for_ext_2}, (Addr)&x,
             "/home/shijia/Public/testprogram/e_atanhl.c_e.c:77:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++;                 /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2; /* x<2**-28 */
  }
  long double temp_var_for_ext_3;
  temp_var_for_ext_3;
  if (ix < 0x3ffe) { /* x < 0.5 */
    long double temp_var_for_tac_6;
    temp_var_for_tac_6 = x + x;

    t = temp_var_for_tac_6;
    computeLdAdd((Addr)&temp_var_for_tac_6, {(Addr)&x, (Addr)&x},
                 "/home/shijia/Public/testprogram/e_atanhl.c_e.c:85:11");
    AssignLd({(Addr)&t}, (Addr)&temp_var_for_tac_6,
             "/home/shijia/Public/testprogram/e_atanhl.c_e.c:85:7");
    ;
    long double temp_var_for_tac_7, temp_var_for_tac_8, temp_var_for_tac_9,
        temp_var_for_tac_10, temp_var_for_tac_11;
    long double temp_var_for_const_4, temp_var_for_const_5,
        temp_var_for_const_6;
    long double temp_var_for_callexp_0;

    temp_var_for_tac_7 = t * x;

    temp_var_for_tac_8 = one - x;

    temp_var_for_tac_9 = temp_var_for_tac_7 / temp_var_for_tac_8;

    temp_var_for_tac_10 = t + temp_var_for_tac_9;

    temp_var_for_callexp_0 = __ieee754_log1pl(temp_var_for_tac_10);
    temp_var_for_tac_11 = 0.5 * temp_var_for_callexp_0;

    t = temp_var_for_tac_11;
    computeLdMul((Addr)&temp_var_for_tac_7, {(Addr)&t, (Addr)&x},
                 "/home/shijia/Public/testprogram/e_atanhl.c_e.c:86:38");
    computeLdSub((Addr)&temp_var_for_tac_8,
                 {(Addr) &(temp_var_for_const_4 = one), (Addr)&x},
                 "/home/shijia/Public/testprogram/e_atanhl.c_e.c:86:49");
    computeLdDiv((Addr)&temp_var_for_tac_9,
                 {(Addr)&temp_var_for_tac_7, (Addr)&temp_var_for_tac_8},
                 "/home/shijia/Public/testprogram/e_atanhl.c_e.c:86:42");
    computeLdAdd((Addr)&temp_var_for_tac_10,
                 {(Addr)&t, (Addr)&temp_var_for_tac_9},
                 "/home/shijia/Public/testprogram/e_atanhl.c_e.c:86:34");
    computeLdMul((Addr)&temp_var_for_tac_11,
                 {(Addr) &(temp_var_for_const_6 = 0.5),
                  (Addr) &(temp_var_for_const_5 = temp_var_for_callexp_0)},
                 "/home/shijia/Public/testprogram/e_atanhl.c_e.c:86:13");
    AssignLd({(Addr)&t}, (Addr)&temp_var_for_tac_11,
             "/home/shijia/Public/testprogram/e_atanhl.c_e.c:86:7");
    ;
  } else {
    long double temp_var_for_ext_4;
    long double temp_var_for_tac_12, temp_var_for_tac_13, temp_var_for_tac_14,
        temp_var_for_tac_15;
    long double temp_var_for_const_7, temp_var_for_const_8,
        temp_var_for_const_9;
    long double temp_var_for_callexp_1;

    temp_var_for_tac_12 = x + x;

    temp_var_for_tac_13 = one - x;

    temp_var_for_tac_14 = temp_var_for_tac_12 / temp_var_for_tac_13;

    temp_var_for_callexp_1 = __ieee754_log1pl(temp_var_for_tac_14);
    temp_var_for_tac_15 = 0.5 * temp_var_for_callexp_1;

    temp_var_for_ext_4 = temp_var_for_tac_15;
    computeLdAdd((Addr)&temp_var_for_tac_12, {(Addr)&x, (Addr)&x},
                 "/home/shijia/Public/testprogram/e_atanhl.c_e.c:89:52");
    computeLdSub((Addr)&temp_var_for_tac_13,
                 {(Addr) &(temp_var_for_const_7 = one), (Addr)&x},
                 "/home/shijia/Public/testprogram/e_atanhl.c_e.c:89:64");
    computeLdDiv((Addr)&temp_var_for_tac_14,
                 {(Addr)&temp_var_for_tac_12, (Addr)&temp_var_for_tac_13},
                 "/home/shijia/Public/testprogram/e_atanhl.c_e.c:89:57");
    computeLdMul((Addr)&temp_var_for_tac_15,
                 {(Addr) &(temp_var_for_const_9 = 0.5),
                  (Addr) &(temp_var_for_const_8 = temp_var_for_callexp_1)},
                 "/home/shijia/Public/testprogram/e_atanhl.c_e.c:89:30");
    AssignLd({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_15,
             "/home/shijia/Public/testprogram/e_atanhl.c_e.c:89:24");
    ; // t
      /*(__ieee754_log1pl(t + t * x / (one -
       * x)))(0.5)(x)(one)(x)(t)(t)(x)(one)(x)(t)(x)(t)(x)(one)(__ieee754_log1pl((x
       * + x) / (one - x)))(0.5)*/
    t = temp_var_for_ext_4;
    AssignLd({(Addr)&t}, (Addr)&temp_var_for_ext_4,
             "/home/shijia/Public/testprogram/e_atanhl.c_e.c:93:7");
    ;
  }
  if (se < 0) {
    long double temp_var_for_ext_5;
    long double temp_var_for_tac_16;
    long double temp_var_for_const_10;
    temp_var_for_tac_16 = 0.0 - t;

    temp_var_for_ext_5 = temp_var_for_tac_16;
    computeLdSub((Addr)&temp_var_for_tac_16,
                 {(Addr) &(temp_var_for_const_10 = 0.0), (Addr)&t},
                 "/home/shijia/Public/testprogram/e_atanhl.c_e.c:97:31");
    AssignLd({(Addr)&temp_var_for_ext_5}, (Addr)&temp_var_for_tac_16,
             "/home/shijia/Public/testprogram/e_atanhl.c_e.c:97:24");
    ; // t
      /*(__ieee754_log1pl((x + x) / (one -
       * x)))(0.5)(x)(one)(x)(x)(x)(x)(x)(one)(t)(t)*/
    t = temp_var_for_ext_5;
    AssignLd({(Addr)&t}, (Addr)&temp_var_for_ext_5,
             "/home/shijia/Public/testprogram/e_atanhl.c_e.c:100:7");
    ;
  }

  long double temp_var_for_ext_6;
  temp_var_for_ext_6 = t;
  AssignLd({(Addr)&temp_var_for_ext_6}, (Addr)&t,
           "/home/shijia/Public/testprogram/e_atanhl.c_e.c:104:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_6;
}

#endif

/* wrapper atanh */
long double __atanhl(long double x) {
  if (isgreaterequal(__ieee754_fabsl(x), 1.0) && _LIB_VERSION != _IEEE_) {
    long double temp_var_for_ext_7;
    long double temp_var_for_const_11;
    long double temp_var_for_callexp_2;

    /*embed fun has found*/
    long double temp_var_for_callexp_3;

    temp_var_for_callexp_2 = __builtin_huge_vall();
    temp_var_for_callexp_3 = __kernel_standard_l(
        x, x, temp_var_for_callexp_2,
        __ieee754_fabsl(x) > 1.0 ? KMATHERRL_ATANH_PLUSONE /* atanh(|x|>1) */
                                 : KMATHERRL_ATANH_ONE);
    temp_var_for_ext_7 = temp_var_for_callexp_3;
    AssignLd({(Addr)&temp_var_for_ext_7},
             (Addr) &(temp_var_for_const_11 = temp_var_for_callexp_3),
             "/home/shijia/Public/testprogram/e_atanhl.c_e.c:116:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_7;
  }
  /* atanh(|x|==1) */

  long double temp_var_for_ext_8;
  long double temp_var_for_const_12;
  long double temp_var_for_callexp_4;

  temp_var_for_callexp_4 = __ieee754_atanhl(x);
  temp_var_for_ext_8 = temp_var_for_callexp_4;
  AssignLd({(Addr)&temp_var_for_ext_8},
           (Addr) &(temp_var_for_const_12 = temp_var_for_callexp_4),
           "/home/shijia/Public/testprogram/e_atanhl.c_e.c:127:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_8;
}

__typeof(__atanhl) atanhl __attribute__((weak, alias("__atanhl")));

#endif
