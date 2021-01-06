#include "../ScDebug/scdebug.h"
/* e_coshf.c -- float version of e_cosh.c.
 * Conversion to float by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.
 * Optimizations by Ulrich Drepper <drepper@gmail.com>, 2011
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

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_cosh

float __ieee754_coshf(float x) {
  float t, w;
  int32_t ix;

  static const float hugeval = 1.0e30;
  static const float one = 1.0;
  static const float half = 0.5;

  GET_FLOAT_WORD(ix, x);
  ix &= IC(0x7fffffff);

  /* x is INF or NaN */
  if (!FLT_UWORD_IS_FINITE(ix)) {
    float temp_var_for_ext_0;
    float temp_var_for_tac_0;
    temp_var_for_tac_0 = x * x;

    temp_var_for_ext_0 = temp_var_for_tac_0;
    computeFMul((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_coshf.c_e.c:37:28");
    AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_0,
            "/home/shijia/Public/testprogram/e_coshf.c_e.c:37:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  /* |x| in [0.5*ln2,22], return (exp(|x|)+1/exp(|x|)/2; */
  if (ix < IC(0x41b00000)) {
    /* |x| in [0,0.5*ln2], return 1+expm1(|x|)^2/(2*exp(|x|)) */
    if (ix < IC(0x3eb17218)) {
      float temp_var_for_ext_1;
      float temp_var_for_const_0;
      float temp_var_for_callexp_0;

      /*embed fun has found*/
      float temp_var_for_callexp_1;

      temp_var_for_callexp_0 = fabsf(x);
      temp_var_for_callexp_1 = __ieee754_expm1f(temp_var_for_callexp_0);
      temp_var_for_ext_1 = temp_var_for_callexp_1;
      AssignF({(Addr)&temp_var_for_ext_1},
              (Addr) &(temp_var_for_const_0 = temp_var_for_callexp_1),
              "/home/shijia/Public/testprogram/e_coshf.c_e.c:48:26");
      ; // t
      /*(0)(t)(__ieee754_expm1f(__ieee754_fabsf(x)))*/
      t = temp_var_for_ext_1;
      AssignF({(Addr)&t}, (Addr)&temp_var_for_ext_1,
              "/home/shijia/Public/testprogram/e_coshf.c_e.c:50:9");
      ;
      float temp_var_for_tac_1;
      float temp_var_for_const_1;
      temp_var_for_tac_1 = one + t;

      w = temp_var_for_tac_1;
      computeFAdd((Addr)&temp_var_for_tac_1,
                  {(Addr) &(temp_var_for_const_1 = one), (Addr)&t},
                  "/home/shijia/Public/testprogram/e_coshf.c_e.c:51:15");
      AssignF({(Addr)&w}, (Addr)&temp_var_for_tac_1,
              "/home/shijia/Public/testprogram/e_coshf.c_e.c:51:9");
      ;
      if (ix < IC(0x24000000)) {
        float temp_var_for_ext_2;
        temp_var_for_ext_2 = w;
        AssignF({(Addr)&temp_var_for_ext_2}, (Addr)&w,
                "/home/shijia/Public/testprogram/e_coshf.c_e.c:54:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_2;
      }
      /* cosh(tiny) = 1 */
      float temp_var_for_ext_3;
      float temp_var_for_tac_2, temp_var_for_tac_3, temp_var_for_tac_4,
          temp_var_for_tac_5;
      float temp_var_for_const_2;
      temp_var_for_tac_2 = t * t;

      temp_var_for_tac_3 = w + w;

      temp_var_for_tac_4 = temp_var_for_tac_2 / temp_var_for_tac_3;

      temp_var_for_tac_5 = one + temp_var_for_tac_4;

      temp_var_for_ext_3 = temp_var_for_tac_5;
      computeFMul((Addr)&temp_var_for_tac_2, {(Addr)&t, (Addr)&t},
                  "/home/shijia/Public/testprogram/e_coshf.c_e.c:62:37");
      computeFAdd((Addr)&temp_var_for_tac_3, {(Addr)&w, (Addr)&w},
                  "/home/shijia/Public/testprogram/e_coshf.c_e.c:62:47");
      computeFDiv((Addr)&temp_var_for_tac_4,
                  {(Addr)&temp_var_for_tac_2, (Addr)&temp_var_for_tac_3},
                  "/home/shijia/Public/testprogram/e_coshf.c_e.c:62:42");
      computeFAdd(
          (Addr)&temp_var_for_tac_5,
          {(Addr) &(temp_var_for_const_2 = one), (Addr)&temp_var_for_tac_4},
          "/home/shijia/Public/testprogram/e_coshf.c_e.c:62:32");
      AssignF({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_5,
              "/home/shijia/Public/testprogram/e_coshf.c_e.c:62:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_3;
    }

    /* |x| in [0,22] */
    float temp_var_for_ext_4;
    float temp_var_for_const_3;
    float temp_var_for_callexp_2;

    /*embed fun has found*/
    float temp_var_for_callexp_3;

    temp_var_for_callexp_2 = fabsf(x);
    temp_var_for_callexp_3 = __ieee754_expf(temp_var_for_callexp_2);
    temp_var_for_ext_4 = temp_var_for_callexp_3;
    AssignF({(Addr)&temp_var_for_ext_4},
            (Addr) &(temp_var_for_const_3 = temp_var_for_callexp_3),
            "/home/shijia/Public/testprogram/e_coshf.c_e.c:71:24");
    ; // t
    /*(t)(one)(_)(_)(a)(m)(tem)(_)(_)(a)(m)(a)(m)(_)(_)(__ieee754_expf(__ieee754_fabsf(x)))*/
    t = temp_var_for_ext_4;
    AssignF({(Addr)&t}, (Addr)&temp_var_for_ext_4,
            "/home/shijia/Public/testprogram/e_coshf.c_e.c:73:7");
    ;
    float temp_var_for_ext_5;
    float temp_var_for_tac_6, temp_var_for_tac_7, temp_var_for_tac_8;
    float temp_var_for_const_4, temp_var_for_const_5;
    temp_var_for_tac_6 = half * t;

    temp_var_for_tac_7 = half / t;

    temp_var_for_tac_8 = temp_var_for_tac_6 + temp_var_for_tac_7;

    temp_var_for_ext_5 = temp_var_for_tac_8;
    computeFMul((Addr)&temp_var_for_tac_6,
                {(Addr) &(temp_var_for_const_4 = half), (Addr)&t},
                "/home/shijia/Public/testprogram/e_coshf.c_e.c:75:31");
    computeFDiv((Addr)&temp_var_for_tac_7,
                {(Addr) &(temp_var_for_const_5 = half), (Addr)&t},
                "/home/shijia/Public/testprogram/e_coshf.c_e.c:75:42");
    computeFAdd((Addr)&temp_var_for_tac_8,
                {(Addr)&temp_var_for_tac_6, (Addr)&temp_var_for_tac_7},
                "/home/shijia/Public/testprogram/e_coshf.c_e.c:75:35");
    AssignF({(Addr)&temp_var_for_ext_5}, (Addr)&temp_var_for_tac_8,
            "/home/shijia/Public/testprogram/e_coshf.c_e.c:75:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_5;
  }

  /* |x| in [22, log(maxdouble)] return half*exp(|x|) */
  if (ix <= FLT_UWORD_LOG_MAX) {
    float temp_var_for_ext_6;
    float temp_var_for_tac_9;
    float temp_var_for_const_6, temp_var_for_const_7;
    float temp_var_for_callexp_4;

    /*embed fun has found*/
    float temp_var_for_callexp_5;

    temp_var_for_callexp_4 = fabsf(x);
    temp_var_for_callexp_5 = __ieee754_expf(temp_var_for_callexp_4);
    temp_var_for_tac_9 = half * temp_var_for_callexp_5;

    temp_var_for_ext_6 = temp_var_for_tac_9;
    computeFMul((Addr)&temp_var_for_tac_9,
                {(Addr) &(temp_var_for_const_7 = half),
                 (Addr) &(temp_var_for_const_6 = temp_var_for_callexp_5)},
                "/home/shijia/Public/testprogram/e_coshf.c_e.c:84:31");
    AssignF({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_9,
            "/home/shijia/Public/testprogram/e_coshf.c_e.c:84:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_6;
  }

  /* |x| in [log(maxdouble), overflowthresold] */
  if (ix <= FLT_UWORD_LOG_2MAX) {
    float temp_var_for_tac_10;
    float temp_var_for_const_8, temp_var_for_const_9, temp_var_for_const_10;
    float temp_var_for_callexp_6;

    float temp_var_for_callexp_7;

    temp_var_for_callexp_6 = fabsf(x);
    temp_var_for_tac_10 = half * temp_var_for_callexp_6;

    temp_var_for_callexp_7 = __ieee754_expf(temp_var_for_tac_10);
    w = temp_var_for_callexp_7;
    computeFMul((Addr)&temp_var_for_tac_10,
                {(Addr) &(temp_var_for_const_9 = half),
                 (Addr) &(temp_var_for_const_8 = temp_var_for_callexp_6)},
                "/home/shijia/Public/testprogram/e_coshf.c_e.c:92:29");
    AssignF({(Addr)&w},
            (Addr) &(temp_var_for_const_10 = temp_var_for_callexp_7),
            "/home/shijia/Public/testprogram/e_coshf.c_e.c:92:7");
    ;
    float temp_var_for_tac_11;
    float temp_var_for_const_11;
    temp_var_for_tac_11 = half * w;

    t = temp_var_for_tac_11;
    computeFMul((Addr)&temp_var_for_tac_11,
                {(Addr) &(temp_var_for_const_11 = half), (Addr)&w},
                "/home/shijia/Public/testprogram/e_coshf.c_e.c:93:14");
    AssignF({(Addr)&t}, (Addr)&temp_var_for_tac_11,
            "/home/shijia/Public/testprogram/e_coshf.c_e.c:93:7");
    ;
    float temp_var_for_ext_7;
    float temp_var_for_tac_12;
    temp_var_for_tac_12 = t * w;

    temp_var_for_ext_7 = temp_var_for_tac_12;
    computeFMul((Addr)&temp_var_for_tac_12, {(Addr)&t, (Addr)&w},
                "/home/shijia/Public/testprogram/e_coshf.c_e.c:95:28");
    AssignF({(Addr)&temp_var_for_ext_7}, (Addr)&temp_var_for_tac_12,
            "/home/shijia/Public/testprogram/e_coshf.c_e.c:95:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_7;
  }

  /* |x| > overflowthresold, cosh(x) overflow */
  float temp_var_for_ext_8;
  float temp_var_for_tac_13;
  float temp_var_for_const_12, temp_var_for_const_13;
  temp_var_for_tac_13 = hugeval * hugeval;

  temp_var_for_ext_8 = temp_var_for_tac_13;
  computeFMul((Addr)&temp_var_for_tac_13,
              {(Addr) &(temp_var_for_const_13 = hugeval),
               (Addr) &(temp_var_for_const_12 = hugeval)},
              "/home/shijia/Public/testprogram/e_coshf.c_e.c:103:32");
  AssignF({(Addr)&temp_var_for_ext_8}, (Addr)&temp_var_for_tac_13,
          "/home/shijia/Public/testprogram/e_coshf.c_e.c:103:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_8;
}

#endif

float __coshf(float x) {
  float z = __ieee754_coshf(x);

  if (!isfinite(z) && isfinite(x) && _LIB_VERSION != _IEEE_) {
    float temp_var_for_ext_9;
    float temp_var_for_const_14;
    float temp_var_for_callexp_8;

    temp_var_for_callexp_8 = __kernel_standard_f(x, x, z, KMATHERRF_COSH);
    temp_var_for_ext_9 = temp_var_for_callexp_8;
    AssignF({(Addr)&temp_var_for_ext_9},
            (Addr) &(temp_var_for_const_14 = temp_var_for_callexp_8),
            "/home/shijia/Public/testprogram/e_coshf.c_e.c:116:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_9;
  }
  /* cosh overflow */

  float temp_var_for_ext_10;
  temp_var_for_ext_10 = z;
  AssignF({(Addr)&temp_var_for_ext_10}, (Addr)&z,
          "/home/shijia/Public/testprogram/e_coshf.c_e.c:124:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_10", (Addr)&temp_var_for_ext_10));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_10;
}

__typeof(__coshf) coshf __attribute__((weak, alias("__coshf")));
