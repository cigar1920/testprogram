#include "../ScDebug/scdebug.h"
/* s_asinhf.c -- float version of s_asinh.c.
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

#ifndef __have_fpu_asinh

float __ieee754_asinhf(float x) {
  float w;
  int32_t hx, ix;

  static const float one = 1.0000000000e+00; /* 0x3F800000 */
  static const float ln2 = 6.9314718246e-01; /* 0x3f317218 */
  static const float hugeval = 1.0000000000e+30;

  GET_FLOAT_WORD(hx, x);
  ix = hx & IC(0x7fffffff);
  if (ix < IC(0x38000000)) { /* |x|<2**-14 */
    if (int temp_var_for_tac_0, temp_var_for_tac_1;
        int temp_var_for_const_0, temp_var_for_const_1;
        temp_var_for_tac_0 = hugeval + x;

        temp_var_for_tac_1 = temp_var_for_tac_0 > one;

        ) {
      float temp_var_for_ext_0;
      temp_var_for_ext_0 = x;
      computeFAdd((Addr)&temp_var_for_tac_0,
                  {(Addr) &(temp_var_for_const_0 = hugeval), (Addr)&x},
                  "/home/shijia/Public/testprogram/s_asinhf.c_e.c:33:17");
      compute((Addr)&temp_var_for_tac_1,
              {(Addr)&temp_var_for_tac_0, (Addr) &(temp_var_for_const_1 = one)},
              "/home/shijia/Public/testprogram/s_asinhf.c_e.c:33:21");
      AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&x,
              "/home/shijia/Public/testprogram/s_asinhf.c_e.c:35:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_0;
    }
    /* return x inexact except 0 */
  }
  if (ix > IC(0x47000000)) { /* |x| > 2**14 */
    if (!FLT_UWORD_IS_FINITE(ix)) {
      float temp_var_for_ext_1;
      float temp_var_for_tac_2;
      temp_var_for_tac_2 = x + x;

      temp_var_for_ext_1 = temp_var_for_tac_2;
      computeFAdd((Addr)&temp_var_for_tac_2, {(Addr)&x, (Addr)&x},
                  "/home/shijia/Public/testprogram/s_asinhf.c_e.c:46:30");
      AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_2,
              "/home/shijia/Public/testprogram/s_asinhf.c_e.c:46:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_1;
    }
    /* x is inf or NaN */
    float temp_var_for_tac_3;
    float temp_var_for_const_2, temp_var_for_const_3;
    float temp_var_for_callexp_0;

    /*embed fun has found*/
    float temp_var_for_callexp_1;

    temp_var_for_callexp_0 = fabsf(x);
    temp_var_for_callexp_1 = __ieee754_logf(temp_var_for_callexp_0);
    temp_var_for_tac_3 = temp_var_for_callexp_1 + ln2;

    w = temp_var_for_tac_3;
    computeFAdd((Addr)&temp_var_for_tac_3,
                {(Addr) &(temp_var_for_const_3 = temp_var_for_callexp_1),
                 (Addr) &(temp_var_for_const_2 = ln2)},
                "/home/shijia/Public/testprogram/s_asinhf.c_e.c:53:44");
    AssignF({(Addr)&w}, (Addr)&temp_var_for_tac_3,
            "/home/shijia/Public/testprogram/s_asinhf.c_e.c:53:7");
    ;
  } else {
    float xa = __ieee754_fabsf(x);

    if (ix > IC(0x40000000)) { /* 2**14 > |x| > 2.0 */
      float temp_var_for_tac_4, temp_var_for_tac_5, temp_var_for_tac_6,
          temp_var_for_tac_7, temp_var_for_tac_8, temp_var_for_tac_9;
      float temp_var_for_const_4, temp_var_for_const_5, temp_var_for_const_6,
          temp_var_for_const_7, temp_var_for_const_8;
      float temp_var_for_callexp_2;

      float temp_var_for_callexp_3;

      temp_var_for_tac_4 = 2.0f * xa;

      temp_var_for_tac_5 = xa * xa;

      temp_var_for_tac_6 = temp_var_for_tac_5 + one;

      temp_var_for_callexp_2 = __ieee754_sqrtf(temp_var_for_tac_6);
      temp_var_for_tac_7 = temp_var_for_callexp_2 + xa;

      temp_var_for_tac_8 = one / temp_var_for_tac_7;

      temp_var_for_tac_9 = temp_var_for_tac_4 + temp_var_for_tac_8;

      temp_var_for_callexp_3 = __ieee754_logf(temp_var_for_tac_9);
      w = temp_var_for_callexp_3;
      computeFMul((Addr)&temp_var_for_tac_4,
                  {(Addr) &(temp_var_for_const_4 = 2.0f), (Addr)&xa},
                  "/home/shijia/Public/testprogram/s_asinhf.c_e.c:58:31");
      computeFMul((Addr)&temp_var_for_tac_5, {(Addr)&xa, (Addr)&xa},
                  "/home/shijia/Public/testprogram/s_asinhf.c_e.c:59:52");
      computeFAdd(
          (Addr)&temp_var_for_tac_6,
          {(Addr)&temp_var_for_tac_5, (Addr) &(temp_var_for_const_5 = one)},
          "/home/shijia/Public/testprogram/s_asinhf.c_e.c:59:57");
      computeFAdd(
          (Addr)&temp_var_for_tac_7,
          {(Addr) &(temp_var_for_const_6 = temp_var_for_callexp_2), (Addr)&xa},
          "/home/shijia/Public/testprogram/s_asinhf.c_e.c:59:64");
      computeFDiv(
          (Addr)&temp_var_for_tac_8,
          {(Addr) &(temp_var_for_const_7 = one), (Addr)&temp_var_for_tac_7},
          "/home/shijia/Public/testprogram/s_asinhf.c_e.c:59:30");
      computeFAdd((Addr)&temp_var_for_tac_9,
                  {(Addr)&temp_var_for_tac_4, (Addr)&temp_var_for_tac_8},
                  "/home/shijia/Public/testprogram/s_asinhf.c_e.c:58:36");
      AssignF({(Addr)&w},
              (Addr) &(temp_var_for_const_8 = temp_var_for_callexp_3),
              "/home/shijia/Public/testprogram/s_asinhf.c_e.c:58:9");
      ;
    } else { /* 2.0 > |x| > 2**-14 */
      float t = float temp_var_for_tac_10;
      temp_var_for_tac_10 = xa * xa;

      ;

      float temp_var_for_tac_11, temp_var_for_tac_12, temp_var_for_tac_13,
          temp_var_for_tac_14;
      float temp_var_for_const_9, temp_var_for_const_10, temp_var_for_const_11,
          temp_var_for_const_12;
      float temp_var_for_callexp_4;

      float temp_var_for_callexp_5;

      temp_var_for_tac_11 = one + t;

      temp_var_for_callexp_4 = __ieee754_sqrtf(temp_var_for_tac_11);
      temp_var_for_tac_12 = one + temp_var_for_callexp_4;

      temp_var_for_tac_13 = t / temp_var_for_tac_12;

      temp_var_for_tac_14 = xa + temp_var_for_tac_13;

      temp_var_for_callexp_5 = __ieee754_log1pf(temp_var_for_tac_14);
      w = temp_var_for_callexp_5;
      computeFMul((Addr)&temp_var_for_tac_10, {(Addr)&xa, (Addr)&xa},
                  "/home/shijia/Public/testprogram/s_asinhf.c_e.c:61:20");
      computeFAdd((Addr)&temp_var_for_tac_11,
                  {(Addr) &(temp_var_for_const_9 = one), (Addr)&t},
                  "/home/shijia/Public/testprogram/s_asinhf.c_e.c:63:64");
      computeFAdd((Addr)&temp_var_for_tac_12,
                  {(Addr) &(temp_var_for_const_11 = one),
                   (Addr) &(temp_var_for_const_10 = temp_var_for_callexp_4)},
                  "/home/shijia/Public/testprogram/s_asinhf.c_e.c:63:42");
      computeFDiv((Addr)&temp_var_for_tac_13,
                  {(Addr)&t, (Addr)&temp_var_for_tac_12},
                  "/home/shijia/Public/testprogram/s_asinhf.c_e.c:63:35");
      computeFAdd((Addr)&temp_var_for_tac_14,
                  {(Addr)&xa, (Addr)&temp_var_for_tac_13},
                  "/home/shijia/Public/testprogram/s_asinhf.c_e.c:63:31");
      AssignF({(Addr)&w},
              (Addr) &(temp_var_for_const_12 = temp_var_for_callexp_5),
              "/home/shijia/Public/testprogram/s_asinhf.c_e.c:63:9");
      ;
    }
  }
  if (hx > 0) {
    float temp_var_for_ext_2;
    temp_var_for_ext_2 = w;
    AssignF({(Addr)&temp_var_for_ext_2}, (Addr)&w,
            "/home/shijia/Public/testprogram/s_asinhf.c_e.c:68:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  }

  float temp_var_for_ext_3;
  float temp_var_for_const_13;
  temp_var_for_ext_3 = (-(w));
  AssignF({(Addr)&temp_var_for_ext_3}, (Addr) &(temp_var_for_const_13 = (-(w))),
          "/home/shijia/Public/testprogram/s_asinhf.c_e.c:75:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
  callExp++; /*identify the function is  add move tmpShadow*/
  return (double temp_var_for_tac_15;
          double temp_var_for_const_14, temp_var_for_const_15;
          temp_var_for_tac_15 = 0.0 - 3;

          );
}

#endif

float __asinhf(float x) {
  float temp_var_for_ext_4;
  float temp_var_for_const_16;
  float temp_var_for_callexp_6;

  temp_var_for_callexp_6 = __ieee754_asinhf(x);
  temp_var_for_ext_4 = temp_var_for_callexp_6;
  computeDSub((Addr)&temp_var_for_tac_15,
              {(Addr) &(temp_var_for_const_15 = 0.0),
               (Addr) &(temp_var_for_const_14 = 3)},
              "/home/shijia/Public/testprogram/s_asinhf.c_e.c:78:15");
  AssignF({(Addr)&temp_var_for_ext_4},
          (Addr) &(temp_var_for_const_16 = temp_var_for_callexp_6),
          "/home/shijia/Public/testprogram/s_asinhf.c_e.c:85:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_4;
}

__typeof(__asinhf) asinhf __attribute__((weak, alias("__asinhf")));
