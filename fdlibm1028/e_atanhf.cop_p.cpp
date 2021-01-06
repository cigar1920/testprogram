#include "../ScDebug/scdebug.h"
/* e_atanhf.c -- float version of e_atanh.c.
 * Conversion to float by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.
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
 *
 */

/* __ieee754_atanh(x)
   Method :
      1.Reduced x to positive by atanh(-x) = -atanh(x)
      2.For x>=0.5
                    1              2x                          x
        atanh(x) = --- * log(1 + -------) = 0.5 * log1p(2 * --------)
                    2             1 - x                      1 - x

        For x<0.5
        atanh(x) = 0.5*log1p(2x+2x*x/(1-x))

   Special cases:
        atanh(x) is NaN if |x| > 1 with signal;
        atanh(NaN) is that NaN with no signal;
        atanh(+-1) is +-INF with signal.

 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_atanh

float __ieee754_atanhf(float x) {
#if defined __have_fpu_log1p
  float xa = __ieee754_fabsf(x);
  float t;

  static const float hugeval = 1e30;

  if (isless(xa, 0.5f)) {
    if (xa <
        hexconstf(0x1.0p-28f, 3.7252902984619140625000e-09F, UC(0x31800000))) {
      math_force_eval(hugeval + x);
      return x;
    }

    t = xa + xa;
    t = 0.5f * __ieee754_log1pf(t + t * xa / (1.0f - xa));
  } else if (isless(xa, 1.0f)) {
    t = 0.5f * __ieee754_log1pf((xa + xa) / (1.0f - xa));
  } else {
    if (isgreater(xa, 1.0f))
      return (x - x) / (x - x);

    return x / 0.0f;
  }

  return __copysignf(t, x);

#elif defined __have_fpu_log

  return 0.5f * logf((1.0f + x) / (1.0f - x));

#else

  float t;
  int32_t hx, ix;

  static const float one = 1.0;
  static const float hugeval = 1e30;
  static const float zero = 0.0;

  GET_FLOAT_WORD(hx, x);
  ix = hx & IC(0x7fffffff);
  if (ix > IC(0x3f800000)) /* |x|>1 */
  {
    float temp_var_for_ext_0;
    float temp_var_for_tac_0, temp_var_for_tac_1, temp_var_for_tac_2;
    temp_var_for_tac_0 = x - x;

    temp_var_for_tac_1 = x - x;

    temp_var_for_tac_2 = temp_var_for_tac_0 / temp_var_for_tac_1;

    temp_var_for_ext_0 = temp_var_for_tac_2;
    computeFSub((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_atanhf.c_e.c:86:29");
    computeFSub((Addr)&temp_var_for_tac_1, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_atanhf.c_e.c:86:39");
    computeFDiv((Addr)&temp_var_for_tac_2,
                {(Addr)&temp_var_for_tac_0, (Addr)&temp_var_for_tac_1},
                "/home/shijia/Public/testprogram/e_atanhf.c_e.c:86:34");
    AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_2,
            "/home/shijia/Public/testprogram/e_atanhf.c_e.c:86:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  if (ix == IC(0x3f800000)) {
    float temp_var_for_ext_1;
    float temp_var_for_tac_3;
    float temp_var_for_const_0;
    temp_var_for_tac_3 = x / zero;

    temp_var_for_ext_1 = temp_var_for_tac_3;
    computeFDiv((Addr)&temp_var_for_tac_3,
                {(Addr)&x, (Addr) &(temp_var_for_const_0 = zero)},
                "/home/shijia/Public/testprogram/e_atanhf.c_e.c:94:28");
    AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_3,
            "/home/shijia/Public/testprogram/e_atanhf.c_e.c:94:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }

  if (ix < IC(0x31800000) && int temp_var_for_tac_4, temp_var_for_tac_5;
      int temp_var_for_const_1, temp_var_for_const_2;
      temp_var_for_tac_4 = hugeval + x;

      temp_var_for_tac_5 = temp_var_for_tac_4 > zero;

      ) {
    float temp_var_for_ext_2;
    temp_var_for_ext_2 = x;
    computeFAdd((Addr)&temp_var_for_tac_4,
                {(Addr) &(temp_var_for_const_1 = hugeval), (Addr)&x},
                "/home/shijia/Public/testprogram/e_atanhf.c_e.c:100:39");
    compute((Addr)&temp_var_for_tac_5,
            {(Addr)&temp_var_for_tac_4, (Addr) &(temp_var_for_const_2 = zero)},
            "/home/shijia/Public/testprogram/e_atanhf.c_e.c:100:44");
    AssignF({(Addr)&temp_var_for_ext_2}, (Addr)&x,
            "/home/shijia/Public/testprogram/e_atanhf.c_e.c:102:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  }
  /* x<2**-28 */
  SET_FLOAT_WORD(x, ix);
  if (ix < IC(0x3f000000)) { /* x < 0.5 */
    float temp_var_for_ext_3;
    float temp_var_for_tac_6;
    temp_var_for_tac_6 = x + x;

    temp_var_for_ext_3 = temp_var_for_tac_6;
    computeFAdd((Addr)&temp_var_for_tac_6, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_atanhf.c_e.c:111:28");
    AssignF({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_6,
            "/home/shijia/Public/testprogram/e_atanhf.c_e.c:111:24");
    ; // t
    /*(_)(_)(a)(m)(a)(m)(_)(_)(xt_1)(t)(x)(hugeval)(x)(x)*/
    t = temp_var_for_ext_3;
    AssignF({(Addr)&t}, (Addr)&temp_var_for_ext_3,
            "/home/shijia/Public/testprogram/e_atanhf.c_e.c:113:7");
    ;
    float temp_var_for_tac_7, temp_var_for_tac_8, temp_var_for_tac_9,
        temp_var_for_tac_10, temp_var_for_tac_11;
    float temp_var_for_const_3, temp_var_for_const_4, temp_var_for_const_5;
    float temp_var_for_callexp_0;

    temp_var_for_tac_7 = t * x;

    temp_var_for_tac_8 = one - x;

    temp_var_for_tac_9 = temp_var_for_tac_7 / temp_var_for_tac_8;

    temp_var_for_tac_10 = t + temp_var_for_tac_9;

    temp_var_for_callexp_0 = __ieee754_log1pf(temp_var_for_tac_10);
    temp_var_for_tac_11 = 0.5f * temp_var_for_callexp_0;

    t = temp_var_for_tac_11;
    computeFMul((Addr)&temp_var_for_tac_7, {(Addr)&t, (Addr)&x},
                "/home/shijia/Public/testprogram/e_atanhf.c_e.c:114:39");
    computeFSub((Addr)&temp_var_for_tac_8,
                {(Addr) &(temp_var_for_const_3 = one), (Addr)&x},
                "/home/shijia/Public/testprogram/e_atanhf.c_e.c:114:50");
    computeFDiv((Addr)&temp_var_for_tac_9,
                {(Addr)&temp_var_for_tac_7, (Addr)&temp_var_for_tac_8},
                "/home/shijia/Public/testprogram/e_atanhf.c_e.c:114:43");
    computeFAdd((Addr)&temp_var_for_tac_10,
                {(Addr)&t, (Addr)&temp_var_for_tac_9},
                "/home/shijia/Public/testprogram/e_atanhf.c_e.c:114:35");
    computeFMul((Addr)&temp_var_for_tac_11,
                {(Addr) &(temp_var_for_const_5 = 0.5f),
                 (Addr) &(temp_var_for_const_4 = temp_var_for_callexp_0)},
                "/home/shijia/Public/testprogram/e_atanhf.c_e.c:114:14");
    AssignF({(Addr)&t}, (Addr)&temp_var_for_tac_11,
            "/home/shijia/Public/testprogram/e_atanhf.c_e.c:114:7");
    ;
  } else {
    float temp_var_for_ext_4;
    float temp_var_for_tac_12, temp_var_for_tac_13, temp_var_for_tac_14,
        temp_var_for_tac_15;
    float temp_var_for_const_6, temp_var_for_const_7, temp_var_for_const_8;
    float temp_var_for_callexp_1;

    temp_var_for_tac_12 = x + x;

    temp_var_for_tac_13 = one - x;

    temp_var_for_tac_14 = temp_var_for_tac_12 / temp_var_for_tac_13;

    temp_var_for_callexp_1 = __ieee754_log1pf(temp_var_for_tac_14);
    temp_var_for_tac_15 = 0.5f * temp_var_for_callexp_1;

    temp_var_for_ext_4 = temp_var_for_tac_15;
    computeFAdd((Addr)&temp_var_for_tac_12, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_atanhf.c_e.c:117:53");
    computeFSub((Addr)&temp_var_for_tac_13,
                {(Addr) &(temp_var_for_const_6 = one), (Addr)&x},
                "/home/shijia/Public/testprogram/e_atanhf.c_e.c:117:65");
    computeFDiv((Addr)&temp_var_for_tac_14,
                {(Addr)&temp_var_for_tac_12, (Addr)&temp_var_for_tac_13},
                "/home/shijia/Public/testprogram/e_atanhf.c_e.c:117:58");
    computeFMul((Addr)&temp_var_for_tac_15,
                {(Addr) &(temp_var_for_const_8 = 0.5f),
                 (Addr) &(temp_var_for_const_7 = temp_var_for_callexp_1)},
                "/home/shijia/Public/testprogram/e_atanhf.c_e.c:117:31");
    AssignF({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_15,
            "/home/shijia/Public/testprogram/e_atanhf.c_e.c:117:24");
    ; // t
      /*(__ieee754_log1pf(t + t * x / (one -
       * x)))(0.5f)(x)(one)(x)(t)(t)(x)(one)(x)(t)(x)(t)(x)(one)(__ieee754_log1pf((x
       * + x) / (one - x)))(0.5f)*/
    t = temp_var_for_ext_4;
    AssignF({(Addr)&t}, (Addr)&temp_var_for_ext_4,
            "/home/shijia/Public/testprogram/e_atanhf.c_e.c:121:7");
    ;
  }

  if (hx >= 0) {
    float temp_var_for_ext_5;
    temp_var_for_ext_5 = t;
    AssignF({(Addr)&temp_var_for_ext_5}, (Addr)&t,
            "/home/shijia/Public/testprogram/e_atanhf.c_e.c:126:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_5;
  }

  float temp_var_for_ext_6;
  float temp_var_for_const_9;
  temp_var_for_ext_6 = (-(t));
  AssignF({(Addr)&temp_var_for_ext_6}, (Addr) &(temp_var_for_const_9 = (-(t))),
          "/home/shijia/Public/testprogram/e_atanhf.c_e.c:133:22");
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

/* wrapper atanhf */
float __atanhf(float x) {
  if (isgreaterequal(__ieee754_fabsf(x), 1.0F) && _LIB_VERSION != _IEEE_) {
    float temp_var_for_ext_7;
    float temp_var_for_const_12;
    float temp_var_for_callexp_2;

    /*embed fun has found*/
    float temp_var_for_callexp_3;

    temp_var_for_callexp_2 = __builtin_huge_valf();
    temp_var_for_callexp_3 = __kernel_standard_f(
        x, x, temp_var_for_callexp_2,
        __ieee754_fabsf(x) > 1.0F ? KMATHERRF_ATANH_PLUSONE /* atanh(|x|>1) */
                                  : KMATHERRF_ATANH_ONE);
    temp_var_for_ext_7 = temp_var_for_callexp_3;
    computeDSub((Addr)&temp_var_for_tac_16,
                {(Addr) &(temp_var_for_const_11 = 0.0),
                 (Addr) &(temp_var_for_const_10 = 6)},
                "/home/shijia/Public/testprogram/e_atanhf.c_e.c:136:15");
    AssignF({(Addr)&temp_var_for_ext_7},
            (Addr) &(temp_var_for_const_12 = temp_var_for_callexp_3),
            "/home/shijia/Public/testprogram/e_atanhf.c_e.c:147:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_7;
  }
  /* atanh(|x|==1) */

  float temp_var_for_ext_8;
  float temp_var_for_const_13;
  float temp_var_for_callexp_4;

  temp_var_for_callexp_4 = __ieee754_atanhf(x);
  temp_var_for_ext_8 = temp_var_for_callexp_4;
  AssignF({(Addr)&temp_var_for_ext_8},
          (Addr) &(temp_var_for_const_13 = temp_var_for_callexp_4),
          "/home/shijia/Public/testprogram/e_atanhf.c_e.c:158:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_8;
}

__typeof(__atanhf) atanhf __attribute__((weak, alias("__atanhf")));
