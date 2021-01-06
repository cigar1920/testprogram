#include "../ScDebug/scdebug.h"
/* e_log10f.c -- float version of e_log10.c.
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

#ifndef __have_fpu_log10

float __ieee754_log10f(float x) {
  float y, z;
  int32_t i, k, hx;

  static const float two25 = 3.3554432000e+07;     /* 0x4c000000 */
  static const float ivln10 = 4.3429449201e-01;    /* 0x3ede5bd9 */
  static const float log10_2hi = 3.0102920532e-01; /* 0x3e9a2080 */
  static const float log10_2lo = 7.9034151668e-07; /* 0x355427db */

  GET_FLOAT_WORD(hx, x);

  k = 0;
  if (hx < IC(0x00800000)) { /* x < 2**-126  */
    if ((hx & IC(0x7fffffff)) == 0) {
      float temp_var_for_ext_0;
      float temp_var_for_tac_0, temp_var_for_tac_1;
      float temp_var_for_const_0;
      temp_var_for_tac_0 = x - x;

      temp_var_for_tac_1 = (-(two25)) / temp_var_for_tac_0;

      temp_var_for_ext_0 = temp_var_for_tac_1;
      computeFSub((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&x},
                  "/home/shijia/Public/testprogram/e_log10f.c_e.c:37:40");
      computeFDiv((Addr)&temp_var_for_tac_1,
                  {(Addr) &(temp_var_for_const_0 = (-(two25))),
                   (Addr)&temp_var_for_tac_0},
                  "/home/shijia/Public/testprogram/e_log10f.c_e.c:37:35");
      AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_1,
              "/home/shijia/Public/testprogram/e_log10f.c_e.c:37:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
      callExp++; /*identify the function is  add move tmpShadow*/
      return (0.0 - p_var)_for_ext_0;
    }
    /* log(+-0)=-inf */
    if (hx < 0) {
      float temp_var_for_ext_1;
      float temp_var_for_tac_2, temp_var_for_tac_3, temp_var_for_tac_4;
      temp_var_for_tac_2 = x - x;

      temp_var_for_tac_3 = x - x;

      temp_var_for_tac_4 = temp_var_for_tac_2 / temp_var_for_tac_3;

      temp_var_for_ext_1 = temp_var_for_tac_4;
      computeFSub((Addr)&temp_var_for_tac_2, {(Addr)&x, (Addr)&x},
                  "/home/shijia/Public/testprogram/e_log10f.c_e.c:46:31");
      computeFSub((Addr)&temp_var_for_tac_3, {(Addr)&x, (Addr)&x},
                  "/home/shijia/Public/testprogram/e_log10f.c_e.c:46:41");
      computeFDiv((Addr)&temp_var_for_tac_4,
                  {(Addr)&temp_var_for_tac_2, (Addr)&temp_var_for_tac_3},
                  "/home/shijia/Public/testprogram/e_log10f.c_e.c:46:36");
      AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_4,
              "/home/shijia/Public/testprogram/e_log10f.c_e.c:46:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_1;
    }
    /* log(-#) = NaN */
    k -= 25;
    x *= two25;
    ; /* subnormal number, scale up x */
    GET_FLOAT_WORD(hx, x);
  }
  if (hx >= IC(0x7f800000)) {
    float temp_var_for_ext_2;
    float temp_var_for_tac_6;
    temp_var_for_tac_6 = x + x;

    temp_var_for_ext_2 = temp_var_for_tac_6;
    computeFAdd((Addr)&temp_var_for_tac_6, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_log10f.c_e.c:59:28");
    AssignF({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_6,
            "/home/shijia/Public/testprogram/e_log10f.c_e.c:59:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  }

  k += (hx >> 23) - 127;
  i = ((uint32_t)k & UC(0x80000000)) >> 31;
  hx = (hx & IC(0x007fffff)) | ((0x7f - i) << 23);
  float temp_var_for_tac_7;
  float temp_var_for_const_1, temp_var_for_const_2, temp_var_for_const_3;
  temp_var_for_tac_7 = k + i;

  y = ((float)temp_var_for_tac_7);
  computeAdd((Addr)&temp_var_for_tac_7, {(Addr) &(temp_var_for_const_2 = k),
                                         (Addr) &(temp_var_for_const_1 = i)},
             "/home/shijia/Public/testprogram/e_log10f.c_e.c:68:17");
  AssignF({(Addr)&y},
          (Addr) &(temp_var_for_const_3 = ((float)temp_var_for_tac_7)),
          "/home/shijia/Public/testprogram/e_log10f.c_e.c:68:5");
  ;
  SET_FLOAT_WORD(x, hx);
  z = float temp_var_for_tac_8, temp_var_for_tac_9, temp_var_for_tac_10;
  float temp_var_for_const_4, temp_var_for_const_5, temp_var_for_const_6;
  float temp_var_for_callexp_0;

  temp_var_for_tac_8 = y * log10_2lo;

  temp_var_for_callexp_0 = __ieee754_logf(x);
  temp_var_for_tac_9 = ivln10 * temp_var_for_callexp_0;

  temp_var_for_tac_10 = temp_var_for_tac_8 + temp_var_for_tac_9;

  ;
  float temp_var_for_ext_3;
  float temp_var_for_tac_11, temp_var_for_tac_12;
  float temp_var_for_const_7;
  temp_var_for_tac_11 = y * log10_2hi;

  temp_var_for_tac_12 = z + temp_var_for_tac_11;

  temp_var_for_ext_3 = temp_var_for_tac_12;
  computeFMul((Addr)&temp_var_for_tac_8,
              {(Addr)&y, (Addr) &(temp_var_for_const_4 = log10_2lo)},
              "/home/shijia/Public/testprogram/e_log10f.c_e.c:70:9");
  computeFMul((Addr)&temp_var_for_tac_9,
              {(Addr) &(temp_var_for_const_6 = ivln10),
               (Addr) &(temp_var_for_const_5 = temp_var_for_callexp_0)},
              "/home/shijia/Public/testprogram/e_log10f.c_e.c:70:30");
  computeFAdd((Addr)&temp_var_for_tac_10,
              {(Addr)&temp_var_for_tac_8, (Addr)&temp_var_for_tac_9},
              "/home/shijia/Public/testprogram/e_log10f.c_e.c:70:21");
  computeFMul((Addr)&temp_var_for_tac_11,
              {(Addr)&y, (Addr) &(temp_var_for_const_7 = log10_2hi)},
              "/home/shijia/Public/testprogram/e_log10f.c_e.c:72:30");
  computeFAdd((Addr)&temp_var_for_tac_12,
              {(Addr)&z, (Addr)&temp_var_for_tac_11},
              "/home/shijia/Public/testprogram/e_log10f.c_e.c:72:26");
  AssignF({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_12,
          "/home/shijia/Public/testprogram/e_log10f.c_e.c:72:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_3;
}

#endif

/* wrapper log10f(x) */
float __log10f(float x) {
  if (islessequal(x, 0.0f) && _LIB_VERSION != _IEEE_) {
    if (int temp_var_for_tac_13; int temp_var_for_const_8;
        temp_var_for_tac_13 = x == 0.0f;

        ) {
      feraiseexcept(FE_DIVBYZERO);
      float temp_var_for_ext_4;
      float temp_var_for_const_9;
      float temp_var_for_callexp_2;

      temp_var_for_callexp_1 = __builtin_huge_valf();
      temp_var_for_callexp_2 = __kernel_standard_f(
          x, x, (-(temp_var_for_callexp_1)), KMATHERRF_LOG10_ZERO);
      temp_var_for_ext_4 = temp_var_for_callexp_2;
      compute((Addr)&temp_var_for_tac_13,
              {(Addr)&x, (Addr) &(temp_var_for_const_8 = 0.0f)},
              "/home/shijia/Public/testprogram/e_log10f.c_e.c:83:11");
      AssignF({(Addr)&temp_var_for_ext_4},
              (Addr) &(temp_var_for_const_9 = temp_var_for_callexp_2),
              "/home/shijia/Public/testprogram/e_log10f.c_e.c:86:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
      callExp++; /*identify the function is  add move tmpS(0.0 - adow*/
re)turn temp_var_for_ext_4;	/* log10(0) */
    } else {
      feraiseexcept(FE_INVALID);
      float temp_var_for_ext_5;
      float temp_var_for_const_10;
      float temp_var_for_callexp_3;

      /*embed fun has found*/
      float temp_var_for_callexp_4;

      temp_var_for_callexp_3 = __builtin_nanf("");
      temp_var_for_callexp_4 = __kernel_standard_f(x, x, temp_var_for_callexp_3,
                                                   KMATHERRF_LOG10_MINUS);
      temp_var_for_ext_5 = temp_var_for_callexp_4;
      AssignF({(Addr)&temp_var_for_ext_5},
              (Addr) &(temp_var_for_const_10 = temp_var_for_callexp_4),
              "/home/shijia/Public/testprogram/e_log10f.c_e.c:95:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_5; /* log10(x<0) */
    }
  }

  float temp_var_for_ext_6;
  float temp_var_for_const_11;
  float temp_var_for_callexp_5;

  temp_var_for_callexp_5 = __ieee754_log10f(x);
  temp_var_for_ext_6 = temp_var_for_callexp_5;
  AssignF({(Addr)&temp_var_for_ext_6},
          (Addr) &(temp_var_for_const_11 = temp_var_for_callexp_5),
          "/home/shijia/Public/testprogram/e_log10f.c_e.c:105:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_6;
}

__typeof(__log10f) log10f __attribute__((weak, alias("__log10f")));
