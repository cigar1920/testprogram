#include "../ScDebug/scdebug.h"
/* e_acoshf.c -- float version of e_acosh.c.
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

#ifndef __have_fpu_acosh

float __ieee754_acoshf(float x) {
  float t;
  int32_t hx;

  static const float one = 1.0;
  static const float ln2 = 6.9314718246e-01; /* 0x3f317218 */

  GET_FLOAT_WORD(hx, x);
  if (hx < IC(0x3f800000)) { /* x < 1 */
    float temp_var_for_ext_0;
    float temp_var_for_tac_0, temp_var_for_tac_1, temp_var_for_tac_2;
    temp_var_for_tac_0 = x - x;

    temp_var_for_tac_1 = x - x;

    temp_var_for_tac_2 = temp_var_for_tac_0 / temp_var_for_tac_1;

    temp_var_for_ext_0 = temp_var_for_tac_2;
    computeFSub((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_acoshf.c_e.c:32:29");
    computeFSub((Addr)&temp_var_for_tac_1, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_acoshf.c_e.c:32:39");
    computeFDiv((Addr)&temp_var_for_tac_2,
                {(Addr)&temp_var_for_tac_0, (Addr)&temp_var_for_tac_1},
                "/home/shijia/Public/testprogram/e_acoshf.c_e.c:32:34");
    AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_2,
            "/home/shijia/Public/testprogram/e_acoshf.c_e.c:32:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  } else {
    if (hx >= IC(0x4d800000)) {       /* x > 2**28 */
      if (!FLT_UWORD_IS_FINITE(hx)) { /* x is inf of NaN */
        float temp_var_for_ext_1;
        float temp_var_for_tac_3;
        temp_var_for_tac_3 = x + x;

        temp_var_for_ext_1 = temp_var_for_tac_3;
        computeFAdd((Addr)&temp_var_for_tac_3, {(Addr)&x, (Addr)&x},
                    "/home/shijia/Public/testprogram/e_acoshf.c_e.c:40:32");
        AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_3,
                "/home/shijia/Public/testprogram/e_acoshf.c_e.c:40:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_1;
      }
      float temp_var_for_ext_2;
      float temp_var_for_tac_4;
      float temp_var_for_const_0, temp_var_for_const_1;
      float temp_var_for_callexp_0;

      temp_var_for_callexp_0 = __ieee754_logf(x);
      temp_var_for_tac_4 = temp_var_for_callexp_0 + ln2;

      temp_var_for_ext_2 = temp_var_for_tac_4;
      computeFAdd((Addr)&temp_var_for_tac_4,
                  {(Addr) &(temp_var_for_const_1 = temp_var_for_callexp_0),
                   (Addr) &(temp_var_for_const_0 = ln2)},
                  "/home/shijia/Public/testprogram/e_acoshf.c_e.c:47:46");
      AssignF({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_4,
              "/home/shijia/Public/testprogram/e_acoshf.c_e.c:47:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_2; /* acosh(huge)=log(2x) */
    } else {
      if (hx == IC(0x3f800000)) {
        float temp_var_for_ext_3;
        float temp_var_for_const_2;
        temp_var_for_ext_3 = 0.0f;
        AssignF({(Addr)&temp_var_for_ext_3},
                (Addr) &(temp_var_for_const_2 = 0.0f),
                "/home/shijia/Public/testprogram/e_acoshf.c_e.c:55:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_3; /* acosh(1) = 0 */
      } else {
        if (hx > IC(0x40000000)) { /* 2**28 > x > 2 */
          float temp_var_for_ext_4;
          float temp_var_for_tac_5;
          temp_var_for_tac_5 = x * x;

          temp_var_for_ext_4 = temp_var_for_tac_5;
          computeFMul((Addr)&temp_var_for_tac_5, {(Addr)&x, (Addr)&x},
                      "/home/shijia/Public/testprogram/e_acoshf.c_e.c:63:34");
          AssignF({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_5,
                  "/home/shijia/Public/testprogram/e_acoshf.c_e.c:63:30");
          ; // t
          /*(_)(_)(a)(m)(a)(m)(_)(_)(1)(t)(t_2)(temp_var_for)(x)(x)*/
          t = temp_var_for_ext_4;
          AssignF({(Addr)&t}, (Addr)&temp_var_for_ext_4,
                  "/home/shijia/Public/testprogram/e_acoshf.c_e.c:65:13");
          ;
          float temp_var_for_ext_5;
          float temp_var_for_tac_6, temp_var_for_tac_7, temp_var_for_tac_8,
              temp_var_for_tac_9, temp_var_for_tac_10;
          float temp_var_for_const_3, temp_var_for_const_4,
              temp_var_for_const_5, temp_var_for_const_6, temp_var_for_const_7;
          float temp_var_for_callexp_1;

          float temp_var_for_callexp_2;

          temp_var_for_tac_6 = 2.0F * x;

          temp_var_for_tac_7 = t - one;

          temp_var_for_callexp_1 = __ieee754_sqrtf(temp_var_for_tac_7);
          temp_var_for_tac_8 = x + temp_var_for_callexp_1;

          temp_var_for_tac_9 = one / temp_var_for_tac_8;

          temp_var_for_tac_10 = temp_var_for_tac_6 - temp_var_for_tac_9;

          temp_var_for_callexp_2 = __ieee754_logf(temp_var_for_tac_10);
          temp_var_for_ext_5 = temp_var_for_callexp_2;
          computeFMul((Addr)&temp_var_for_tac_6,
                      {(Addr) &(temp_var_for_const_3 = 2.0F), (Addr)&x},
                      "/home/shijia/Public/testprogram/e_acoshf.c_e.c:68:35");
          computeFSub((Addr)&temp_var_for_tac_7,
                      {(Addr)&t, (Addr) &(temp_var_for_const_4 = one)},
                      "/home/shijia/Public/testprogram/e_acoshf.c_e.c:68:70");
          computeFAdd((Addr)&temp_var_for_tac_8,
                      {(Addr)&x,
                       (Addr) &(temp_var_for_const_5 = temp_var_for_callexp_1)},
                      "/home/shijia/Public/testprogram/e_acoshf.c_e.c:68:50");
          computeFDiv(
              (Addr)&temp_var_for_tac_9,
              {(Addr) &(temp_var_for_const_6 = one), (Addr)&temp_var_for_tac_8},
              "/home/shijia/Public/testprogram/e_acoshf.c_e.c:68:45");
          computeFSub((Addr)&temp_var_for_tac_10,
                      {(Addr)&temp_var_for_tac_6, (Addr)&temp_var_for_tac_9},
                      "/home/shijia/Public/testprogram/e_acoshf.c_e.c:68:39");
          AssignF({(Addr)&temp_var_for_ext_5},
                  (Addr) &(temp_var_for_const_7 = temp_var_for_callexp_2),
                  "/home/shijia/Public/testprogram/e_acoshf.c_e.c:67:30");
          ;
          callExpStack.push(
              getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
          callExp++; /*identify the function is  add move tmpShadow*/
          return temp_var_for_ext_5;
        } else { /* 1<x<2 */
          float temp_var_for_tac_11;
          float temp_var_for_const_8;
          temp_var_for_tac_11 = x - one;

          t = temp_var_for_tac_11;
          computeFSub((Addr)&temp_var_for_tac_11,
                      {(Addr)&x, (Addr) &(temp_var_for_const_8 = one)},
                      "/home/shijia/Public/testprogram/e_acoshf.c_e.c:74:17");
          AssignF({(Addr)&t}, (Addr)&temp_var_for_tac_11,
                  "/home/shijia/Public/testprogram/e_acoshf.c_e.c:74:13");
          ;
          float temp_var_for_ext_6;
          float temp_var_for_tac_12, temp_var_for_tac_13, temp_var_for_tac_14,
              temp_var_for_tac_15;
          float temp_var_for_const_9, temp_var_for_const_10,
              temp_var_for_const_11;
          float temp_var_for_callexp_3;

          float temp_var_for_callexp_4;

          temp_var_for_tac_12 = 2.0F * t;

          temp_var_for_tac_13 = t * t;

          temp_var_for_tac_14 = temp_var_for_tac_12 + temp_var_for_tac_13;

          temp_var_for_callexp_3 = __ieee754_sqrtf(temp_var_for_tac_14);
          temp_var_for_tac_15 = t + temp_var_for_callexp_3;

          temp_var_for_callexp_4 = __ieee754_log1pf(temp_var_for_tac_15);
          temp_var_for_ext_6 = temp_var_for_callexp_4;
          computeFMul((Addr)&temp_var_for_tac_12,
                      {(Addr) &(temp_var_for_const_9 = 2.0F), (Addr)&t},
                      "/home/shijia/Public/testprogram/e_acoshf.c_e.c:77:57");
          computeFMul((Addr)&temp_var_for_tac_13, {(Addr)&t, (Addr)&t},
                      "/home/shijia/Public/testprogram/e_acoshf.c_e.c:77:65");
          computeFAdd((Addr)&temp_var_for_tac_14,
                      {(Addr)&temp_var_for_tac_12, (Addr)&temp_var_for_tac_13},
                      "/home/shijia/Public/testprogram/e_acoshf.c_e.c:77:61");
          computeFAdd((Addr)&temp_var_for_tac_15,
                      {(Addr)&t, (Addr) &(temp_var_for_const_10 =
                                              temp_var_for_callexp_3)},
                      "/home/shijia/Public/testprogram/e_acoshf.c_e.c:77:34");
          AssignF({(Addr)&temp_var_for_ext_6},
                  (Addr) &(temp_var_for_const_11 = temp_var_for_callexp_4),
                  "/home/shijia/Public/testprogram/e_acoshf.c_e.c:76:30");
          ;
          callExpStack.push(
              getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
          callExp++; /*identify the function is  add move tmpShadow*/
          return temp_var_for_ext_6;
        }
      }
    }
  }
}

#endif

/* wrapper acoshf */
float __acoshf(float x) {
  if (isless(x, 1.0f) && _LIB_VERSION != _IEEE_)
  /* acosh(x<1) */
  {
    float temp_var_for_ext_7;
    float temp_var_for_const_12;
    float temp_var_for_callexp_5;

    /*embed fun has found*/
    float temp_var_for_callexp_6;

    temp_var_for_callexp_5 = __builtin_nanf("");
    temp_var_for_callexp_6 =
        __kernel_standard_f(x, x, temp_var_for_callexp_5, KMATHERRF_ACOSH);
    temp_var_for_ext_7 = temp_var_for_callexp_6;
    AssignF({(Addr)&temp_var_for_ext_7},
            (Addr) &(temp_var_for_const_12 = temp_var_for_callexp_6),
            "/home/shijia/Public/testprogram/e_acoshf.c_e.c:96:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_7;
  }

  float temp_var_for_ext_8;
  float temp_var_for_const_13;
  float temp_var_for_callexp_7;

  temp_var_for_callexp_7 = __ieee754_acoshf(x);
  temp_var_for_ext_8 = temp_var_for_callexp_7;
  AssignF({(Addr)&temp_var_for_ext_8},
          (Addr) &(temp_var_for_const_13 = temp_var_for_callexp_7),
          "/home/shijia/Public/testprogram/e_acoshf.c_e.c:104:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_8;
}

__typeof(__acoshf) acoshf __attribute__((weak, alias("__acoshf")));
