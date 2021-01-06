#include "../ScDebug/scdebug.h"
/* e_sinhf.c -- float version of e_sinh.c.
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
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_sinh

float __ieee754_sinhf(float x) {
  float t, w, h;
  int32_t ix, jx;

  static const float one = 1.0;
  static const float shuge = 1.0e37;

  GET_FLOAT_WORD(jx, x);
  ix = jx & IC(0x7fffffff);

  /* x is INF or NaN */
  if (!FLT_UWORD_IS_FINITE(ix)) {
    float temp_var_for_ext_0;
    float temp_var_for_tac_0;
    temp_var_for_tac_0 = x + x;

    temp_var_for_ext_0 = temp_var_for_tac_0;
    computeFAdd((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_sinhf.c_e.c:35:28");
    AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_0,
            "/home/shijia/Public/testprogram/e_sinhf.c_e.c:35:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  float temp_var_for_const_0;
  h = 0.5;
  AssignF({(Addr)&h}, (Addr) &(temp_var_for_const_0 = 0.5),
          "/home/shijia/Public/testprogram/e_sinhf.c_e.c:41:5");
  ;
  if (jx < 0) {
    float temp_var_for_ext_1;
    float temp_var_for_tac_1;
    float temp_var_for_const_1;
    temp_var_for_tac_1 = 0.0 - h;

    temp_var_for_ext_1 = temp_var_for_tac_1;
    computeDSub((Addr)&temp_var_for_tac_1,
                {(Addr) &(temp_var_for_const_1 = 0.0), (Addr)&h},
                "/home/shijia/Public/testprogram/e_sinhf.c_e.c:44:31");
    AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_1,
            "/home/shijia/Public/testprogram/e_sinhf.c_e.c:44:24");
    ; // h
    /*(h)(h)*/
    h = temp_var_for_ext_1;
    AssignF({(Addr)&h}, (Addr)&temp_var_for_ext_1,
            "/home/shijia/Public/testprogram/e_sinhf.c_e.c:46:7");
    ;
  }

  /* |x| in [0,22], return sign(x)*0.5*(E+E/(E+1))) */
  if (ix < IC(0x41b00000)) { /* |x|<22 */
    if (ix < IC(0x31800000)) /* |x|<2**-28 */
    {
      if (int temp_var_for_tac_2, temp_var_for_tac_3;
          int temp_var_for_const_2, temp_var_for_const_3;
          temp_var_for_tac_2 = shuge + x;

          temp_var_for_tac_3 = temp_var_for_tac_2 > one;

          ) {
        float temp_var_for_ext_2;
        temp_var_for_ext_2 = x;
        computeFAdd((Addr)&temp_var_for_tac_2,
                    {(Addr) &(temp_var_for_const_2 = shuge), (Addr)&x},
                    "/home/shijia/Public/testprogram/e_sinhf.c_e.c:53:17");
        compute(
            (Addr)&temp_var_for_tac_3,
            {(Addr)&temp_var_for_tac_2, (Addr) &(temp_var_for_const_3 = one)},
            "/home/shijia/Public/testprogram/e_sinhf.c_e.c:53:21");
        AssignF({(Addr)&temp_var_for_ext_2}, (Addr)&x,
                "/home/shijia/Public/testprogram/e_sinhf.c_e.c:55:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_2;
      }
    }
    /* sinh(tiny) = tiny with inexact */
    float temp_var_for_const_4;
    float temp_var_for_callexp_0;

    /*embed fun has found*/
    float temp_var_for_callexp_1;

    temp_var_for_callexp_0 = fabsf(x);
    temp_var_for_callexp_1 = __ieee754_expm1f(temp_var_for_callexp_0);
    t = temp_var_for_callexp_1;
    AssignF({(Addr)&t}, (Addr) &(temp_var_for_const_4 = temp_var_for_callexp_1),
            "/home/shijia/Public/testprogram/e_sinhf.c_e.c:63:7");
    ;
    if (ix < IC(0x3f800000)) {
      float temp_var_for_ext_3;
      float temp_var_for_tac_4, temp_var_for_tac_5, temp_var_for_tac_6,
          temp_var_for_tac_7, temp_var_for_tac_8, temp_var_for_tac_9;
      float temp_var_for_const_5, temp_var_for_const_6;
      temp_var_for_tac_4 = 2.0f * t;

      temp_var_for_tac_5 = t * t;

      temp_var_for_tac_6 = t + one;

      temp_var_for_tac_7 = temp_var_for_tac_5 / temp_var_for_tac_6;

      temp_var_for_tac_8 = temp_var_for_tac_4 - temp_var_for_tac_7;

      temp_var_for_tac_9 = h * temp_var_for_tac_8;

      temp_var_for_ext_3 = temp_var_for_tac_9;
      computeFMul((Addr)&temp_var_for_tac_4,
                  {(Addr) &(temp_var_for_const_5 = 2.0f), (Addr)&t},
                  "/home/shijia/Public/testprogram/e_sinhf.c_e.c:66:38");
      computeFMul((Addr)&temp_var_for_tac_5, {(Addr)&t, (Addr)&t},
                  "/home/shijia/Public/testprogram/e_sinhf.c_e.c:66:46");
      computeFAdd((Addr)&temp_var_for_tac_6,
                  {(Addr)&t, (Addr) &(temp_var_for_const_6 = one)},
                  "/home/shijia/Public/testprogram/e_sinhf.c_e.c:66:55");
      computeFDiv((Addr)&temp_var_for_tac_7,
                  {(Addr)&temp_var_for_tac_5, (Addr)&temp_var_for_tac_6},
                  "/home/shijia/Public/testprogram/e_sinhf.c_e.c:66:50");
      computeFSub((Addr)&temp_var_for_tac_8,
                  {(Addr)&temp_var_for_tac_4, (Addr)&temp_var_for_tac_7},
                  "/home/shijia/Public/testprogram/e_sinhf.c_e.c:66:42");
      computeFMul((Addr)&temp_var_for_tac_9,
                  {(Addr)&h, (Addr)&temp_var_for_tac_8},
                  "/home/shijia/Public/testprogram/e_sinhf.c_e.c:66:30");
      AssignF({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_9,
              "/home/shijia/Public/testprogram/e_sinhf.c_e.c:66:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_3;
    }

    float temp_var_for_ext_4;
    float temp_var_for_tac_10, temp_var_for_tac_11, temp_var_for_tac_12,
        temp_var_for_tac_13;
    float temp_var_for_const_7;
    temp_var_for_tac_10 = t + one;

    temp_var_for_tac_11 = t / temp_var_for_tac_10;

    temp_var_for_tac_12 = t + temp_var_for_tac_11;

    temp_var_for_tac_13 = h * temp_var_for_tac_12;

    temp_var_for_ext_4 = temp_var_for_tac_13;
    computeFAdd((Addr)&temp_var_for_tac_10,
                {(Addr)&t, (Addr) &(temp_var_for_const_7 = one)},
                "/home/shijia/Public/testprogram/e_sinhf.c_e.c:74:42");
    computeFDiv((Addr)&temp_var_for_tac_11,
                {(Addr)&t, (Addr)&temp_var_for_tac_10},
                "/home/shijia/Public/testprogram/e_sinhf.c_e.c:74:37");
    computeFAdd((Addr)&temp_var_for_tac_12,
                {(Addr)&t, (Addr)&temp_var_for_tac_11},
                "/home/shijia/Public/testprogram/e_sinhf.c_e.c:74:33");
    computeFMul((Addr)&temp_var_for_tac_13,
                {(Addr)&h, (Addr)&temp_var_for_tac_12},
                "/home/shijia/Public/testprogram/e_sinhf.c_e.c:74:28");
    AssignF({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_13,
            "/home/shijia/Public/testprogram/e_sinhf.c_e.c:74:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_4;
  }

  /* |x| in [22, log(maxdouble)] return 0.5*exp(|x|) */
  if (ix <= FLT_UWORD_LOG_MAX) {
    float temp_var_for_ext_5;
    float temp_var_for_tac_14;
    float temp_var_for_const_8;
    float temp_var_for_callexp_2;

    /*embed fun has found*/
    float temp_var_for_callexp_3;

    temp_var_for_callexp_2 = fabsf(x);
    temp_var_for_callexp_3 = __ieee754_expf(temp_var_for_callexp_2);
    temp_var_for_tac_14 = h * temp_var_for_callexp_3;

    temp_var_for_ext_5 = temp_var_for_tac_14;
    computeFMul(
        (Addr)&temp_var_for_tac_14,
        {(Addr)&h, (Addr) &(temp_var_for_const_8 = temp_var_for_callexp_3)},
        "/home/shijia/Public/testprogram/e_sinhf.c_e.c:83:28");
    AssignF({(Addr)&temp_var_for_ext_5}, (Addr)&temp_var_for_tac_14,
            "/home/shijia/Public/testprogram/e_sinhf.c_e.c:83:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_5;
  }

  /* |x| in [log(maxdouble), overflowthresold] */
  if (ix <= FLT_UWORD_LOG_2MAX) {
    float temp_var_for_tac_15;
    float temp_var_for_const_9, temp_var_for_const_10, temp_var_for_const_11;
    float temp_var_for_callexp_4;

    float temp_var_for_callexp_5;

    temp_var_for_callexp_4 = fabsf(x);
    temp_var_for_tac_15 = 0.5f * temp_var_for_callexp_4;

    temp_var_for_callexp_5 = __ieee754_expf(temp_var_for_tac_15);
    w = temp_var_for_callexp_5;
    computeFMul((Addr)&temp_var_for_tac_15,
                {(Addr) &(temp_var_for_const_10 = 0.5f),
                 (Addr) &(temp_var_for_const_9 = temp_var_for_callexp_4)},
                "/home/shijia/Public/testprogram/e_sinhf.c_e.c:91:29");
    AssignF({(Addr)&w},
            (Addr) &(temp_var_for_const_11 = temp_var_for_callexp_5),
            "/home/shijia/Public/testprogram/e_sinhf.c_e.c:91:7");
    ;
    float temp_var_for_tac_16;
    temp_var_for_tac_16 = h * w;

    t = temp_var_for_tac_16;
    computeFMul((Addr)&temp_var_for_tac_16, {(Addr)&h, (Addr)&w},
                "/home/shijia/Public/testprogram/e_sinhf.c_e.c:92:11");
    AssignF({(Addr)&t}, (Addr)&temp_var_for_tac_16,
            "/home/shijia/Public/testprogram/e_sinhf.c_e.c:92:7");
    ;
    float temp_var_for_ext_6;
    float temp_var_for_tac_17;
    temp_var_for_tac_17 = t * w;

    temp_var_for_ext_6 = temp_var_for_tac_17;
    computeFMul((Addr)&temp_var_for_tac_17, {(Addr)&t, (Addr)&w},
                "/home/shijia/Public/testprogram/e_sinhf.c_e.c:94:28");
    AssignF({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_17,
            "/home/shijia/Public/testprogram/e_sinhf.c_e.c:94:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_6;
  }

  /* |x| > overflowthresold, sinh(x) overflow */
  float temp_var_for_ext_7;
  float temp_var_for_tac_18;
  float temp_var_for_const_12;
  temp_var_for_tac_18 = x * shuge;

  temp_var_for_ext_7 = temp_var_for_tac_18;
  computeFMul((Addr)&temp_var_for_tac_18,
              {(Addr)&x, (Addr) &(temp_var_for_const_12 = shuge)},
              "/home/shijia/Public/testprogram/e_sinhf.c_e.c:102:26");
  AssignF({(Addr)&temp_var_for_ext_7}, (Addr)&temp_var_for_tac_18,
          "/home/shijia/Public/testprogram/e_sinhf.c_e.c:102:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_7;
}

#endif

float __sinhf(float x) {
  float z = __ieee754_sinhf(x);

  if (!isfinite(z) && isfinite(x) && _LIB_VERSION != _IEEE_) {
    float temp_var_for_ext_8;
    float temp_var_for_const_13;
    float temp_var_for_callexp_6;

    temp_var_for_callexp_6 = __kernel_standard_f(x, x, z, KMATHERRF_SINH);
    temp_var_for_ext_8 = temp_var_for_callexp_6;
    AssignF({(Addr)&temp_var_for_ext_8},
            (Addr) &(temp_var_for_const_13 = temp_var_for_callexp_6),
            "/home/shijia/Public/testprogram/e_sinhf.c_e.c:115:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_8;
  }
  /* sinh overflow */

  float temp_var_for_ext_9;
  temp_var_for_ext_9 = z;
  AssignF({(Addr)&temp_var_for_ext_9}, (Addr)&z,
          "/home/shijia/Public/testprogram/e_sinhf.c_e.c:123:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_9;
}

__typeof(__sinhf) sinhf __attribute__((weak, alias("__sinhf")));
