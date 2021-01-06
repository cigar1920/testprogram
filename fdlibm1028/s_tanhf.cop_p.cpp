#include "../ScDebug/scdebug.h"
/* s_tanhf.c -- float version of s_tanh.c.
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

#ifndef __have_fpu_tanh

float __ieee754_tanhf(float x) {
  float t, z;
  int32_t jx, ix;

  static const float one = 1.0;
  static const float two = 2.0;
  static const float tiny = 1.0e-30;

  GET_FLOAT_WORD(jx, x);
  ix = jx & IC(0x7fffffff);

  /* x is INF or NaN */
  if (!FLT_UWORD_IS_FINITE(ix)) {
    if (jx >= 0) {
      float temp_var_for_ext_0;
      float temp_var_for_tac_0, temp_var_for_tac_1;
      float temp_var_for_const_0, temp_var_for_const_1;
      temp_var_for_tac_0 = one / x;

      temp_var_for_tac_1 = temp_var_for_tac_0 + one;

      temp_var_for_ext_0 = temp_var_for_tac_1;
      computeFDiv((Addr)&temp_var_for_tac_0,
                  {(Addr) &(temp_var_for_const_0 = one), (Addr)&x},
                  "/home/shijia/Public/testprogram/s_tanhf.c_e.c:37:32");
      computeFAdd(
          (Addr)&temp_var_for_tac_1,
          {(Addr)&temp_var_for_tac_0, (Addr) &(temp_var_for_const_1 = one)},
          "/home/shijia/Public/testprogram/s_tanhf.c_e.c:37:36");
      AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_1,
              "/home/shijia/Public/testprogram/s_tanhf.c_e.c:37:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_0;
    }
    /* tanh(+-inf)=+-1 */
    else {
      float temp_var_for_ext_1;
      float temp_var_for_tac_2, temp_var_for_tac_3;
      float temp_var_for_const_2, temp_var_for_const_3;
      temp_var_for_tac_2 = one / x;

      temp_var_for_tac_3 = temp_var_for_tac_2 - one;

      temp_var_for_ext_1 = temp_var_for_tac_3;
      computeFDiv((Addr)&temp_var_for_tac_2,
                  {(Addr) &(temp_var_for_const_2 = one), (Addr)&x},
                  "/home/shijia/Public/testprogram/s_tanhf.c_e.c:46:32");
      computeFSub(
          (Addr)&temp_var_for_tac_3,
          {(Addr)&temp_var_for_tac_2, (Addr) &(temp_var_for_const_3 = one)},
          "/home/shijia/Public/testprogram/s_tanhf.c_e.c:46:36");
      AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_3,
              "/home/shijia/Public/testprogram/s_tanhf.c_e.c:46:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_1;
    }
    /* tanh(NaN) = NaN */
  }

  /* |x| < 22 */
  if (ix < IC(0x41b00000)) { /* |x|<22 */
    if (ix == 0) {
      float temp_var_for_ext_2;
      temp_var_for_ext_2 = x;
      AssignF({(Addr)&temp_var_for_ext_2}, (Addr)&x,
              "/home/shijia/Public/testprogram/s_tanhf.c_e.c:59:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_2;
    }
    /* x == +-0 */
    if (ix < IC(0x24000000)) /* |x|<2**-55 */
    {
      float temp_var_for_ext_3;
      float temp_var_for_tac_4, temp_var_for_tac_5;
      float temp_var_for_const_4;
      temp_var_for_tac_4 = one + x;

      temp_var_for_tac_5 = x * temp_var_for_tac_4;

      temp_var_for_ext_3 = temp_var_for_tac_5;
      computeFAdd((Addr)&temp_var_for_tac_4,
                  {(Addr) &(temp_var_for_const_4 = one), (Addr)&x},
                  "/home/shijia/Public/testprogram/s_tanhf.c_e.c:69:37");
      computeFMul((Addr)&temp_var_for_tac_5,
                  {(Addr)&x, (Addr)&temp_var_for_tac_4},
                  "/home/shijia/Public/testprogram/s_tanhf.c_e.c:69:30");
      AssignF({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_5,
              "/home/shijia/Public/testprogram/s_tanhf.c_e.c:69:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_3;
    }
    /* tanh(small) = small */
    if (ix >= IC(0x3f800000)) { /* |x|>=1  */
      float temp_var_for_ext_4;
      float temp_var_for_tac_6;
      float temp_var_for_const_5, temp_var_for_const_6, temp_var_for_const_7;
      float temp_var_for_callexp_0;

      float temp_var_for_callexp_1;

      temp_var_for_callexp_0 = fabsf(x);
      temp_var_for_tac_6 = two * temp_var_for_callexp_0;

      temp_var_for_callexp_1 = expm1f(temp_var_for_tac_6);
      temp_var_for_ext_4 = temp_var_for_callexp_1;
      computeFMul((Addr)&temp_var_for_tac_6,
                  {(Addr) &(temp_var_for_const_6 = two),
                   (Addr) &(temp_var_for_const_5 = temp_var_for_callexp_0)},
                  "/home/shijia/Public/testprogram/s_tanhf.c_e.c:78:39");
      AssignF({(Addr)&temp_var_for_ext_4},
              (Addr) &(temp_var_for_const_7 = temp_var_for_callexp_1),
              "/home/shijia/Public/testprogram/s_tanhf.c_e.c:78:26");
      ; // t
      /*(t_0)(r)(tem)(r)(tem)(t_1)(r)(tem)(r)(tem)(_)(or_)(t)(_)(or_)(expm1f(two
       * * __ieee754_fabsf(x)))*/
      t = temp_var_for_ext_4;
      AssignF({(Addr)&t}, (Addr)&temp_var_for_ext_4,
              "/home/shijia/Public/testprogram/s_tanhf.c_e.c:81:9");
      ;
      float temp_var_for_tac_7, temp_var_for_tac_8, temp_var_for_tac_9;
      float temp_var_for_const_8, temp_var_for_const_9, temp_var_for_const_10;
      temp_var_for_tac_7 = t + two;

      temp_var_for_tac_8 = two / temp_var_for_tac_7;

      temp_var_for_tac_9 = one - temp_var_for_tac_8;

      z = temp_var_for_tac_9;
      computeFAdd((Addr)&temp_var_for_tac_7,
                  {(Addr)&t, (Addr) &(temp_var_for_const_8 = two)},
                  "/home/shijia/Public/testprogram/s_tanhf.c_e.c:82:26");
      computeFDiv(
          (Addr)&temp_var_for_tac_8,
          {(Addr) &(temp_var_for_const_9 = two), (Addr)&temp_var_for_tac_7},
          "/home/shijia/Public/testprogram/s_tanhf.c_e.c:82:21");
      computeFSub(
          (Addr)&temp_var_for_tac_9,
          {(Addr) &(temp_var_for_const_10 = one), (Addr)&temp_var_for_tac_8},
          "/home/shijia/Public/testprogram/s_tanhf.c_e.c:82:15");
      AssignF({(Addr)&z}, (Addr)&temp_var_for_tac_9,
              "/home/shijia/Public/testprogram/s_tanhf.c_e.c:82:9");
      ;
    } else {
      float temp_var_for_ext_5;
      float temp_var_for_tac_10, temp_var_for_tac_11;
      float temp_var_for_const_11, temp_var_for_const_12, temp_var_for_const_13,
          temp_var_for_const_14;
      float temp_var_for_callexp_2;

      float temp_var_for_callexp_3;

      temp_var_for_tac_10 = 0.0 - two;

      temp_var_for_callexp_2 = fabsf(x);
      temp_var_for_tac_11 = temp_var_for_tac_10 * temp_var_for_callexp_2;

      temp_var_for_callexp_3 = expm1f(temp_var_for_tac_11);
      temp_var_for_ext_5 = temp_var_for_callexp_3;
      computeDSub((Addr)&temp_var_for_tac_10,
                  {(Addr) &(temp_var_for_const_12 = 0.0),
                   (Addr) &(temp_var_for_const_11 = two)},
                  "/home/shijia/Public/testprogram/s_tanhf.c_e.c:85:40");
      computeDMul((Addr)&temp_var_for_tac_11,
                  {(Addr)&temp_var_for_tac_10,
                   (Addr) &(temp_var_for_const_13 = temp_var_for_callexp_2)},
                  "/home/shijia/Public/testprogram/s_tanhf.c_e.c:85:47");
      AssignF({(Addr)&temp_var_for_ext_5},
              (Addr) &(temp_var_for_const_14 = temp_var_for_callexp_3),
              "/home/shijia/Public/testprogram/s_tanhf.c_e.c:85:26");
      ; // t
        /*(two)(t)(two)(one)(two)(t)(two)(two)(t)(expm1f(-two *
         * __ieee754_fabsf(x)))*/
      t = temp_var_for_ext_5;
      AssignF({(Addr)&t}, (Addr)&temp_var_for_ext_5,
              "/home/shijia/Public/testprogram/s_tanhf.c_e.c:88:9");
      ;
      float temp_var_for_tac_12, temp_var_for_tac_13, temp_var_for_tac_14;
      float temp_var_for_const_15, temp_var_for_const_16;
      temp_var_for_tac_12 = 0.0 - t;

      temp_var_for_tac_13 = t + two;

      temp_var_for_tac_14 = temp_var_for_tac_12 / temp_var_for_tac_13;

      z = temp_var_for_tac_14;
      computeDSub((Addr)&temp_var_for_tac_12,
                  {(Addr) &(temp_var_for_const_15 = 0.0), (Addr)&t},
                  "/home/shijia/Public/testprogram/s_tanhf.c_e.c:89:16");
      computeFAdd((Addr)&temp_var_for_tac_13,
                  {(Addr)&t, (Addr) &(temp_var_for_const_16 = two)},
                  "/home/shijia/Public/testprogram/s_tanhf.c_e.c:89:26");
      computeDDiv((Addr)&temp_var_for_tac_14,
                  {(Addr)&temp_var_for_tac_12, (Addr)&temp_var_for_tac_13},
                  "/home/shijia/Public/testprogram/s_tanhf.c_e.c:89:21");
      AssignF({(Addr)&z}, (Addr)&temp_var_for_tac_14,
              "/home/shijia/Public/testprogram/s_tanhf.c_e.c:89:9");
      ;
    }
    /* |x| > 22, return +-1 */
  } else {
    float temp_var_for_tac_15;
    float temp_var_for_const_17, temp_var_for_const_18;
    temp_var_for_tac_15 = one - tiny;

    z = temp_var_for_tac_15;
    computeFSub((Addr)&temp_var_for_tac_15,
                {(Addr) &(temp_var_for_const_18 = one),
                 (Addr) &(temp_var_for_const_17 = tiny)},
                "/home/shijia/Public/testprogram/s_tanhf.c_e.c:93:13");
    AssignF({(Addr)&z}, (Addr)&temp_var_for_tac_15,
            "/home/shijia/Public/testprogram/s_tanhf.c_e.c:93:7");
    ; /* raised inexact flag */
  }
  float temp_var_for_ext_6;
  float temp_var_for_const_19;
  temp_var_for_ext_6 = (jx >= 0) ? z : -z;
  AssignF({(Addr)&temp_var_for_ext_6},
          (Addr) &(temp_var_for_const_19 = (jx >= 0) ? z : -z),
          "/home/shijia/Public/testprogram/s_tanhf.c_e.c:96:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext(0.0 - 6);
}

#endif

float __tanhf(float x) {
  float temp_var_for_ext_7;
  temp_var_for_ext_7 = __ieee754_tanhf(x);
  callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_7;
}

__typeof(__tanhf) tanhf __attribute__((weak, alias("__tanhf")));
