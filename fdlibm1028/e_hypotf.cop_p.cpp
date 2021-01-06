#include "../ScDebug/scdebug.h"
/* e_hypotf.c -- float version of e_hypot.c.
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

#ifndef __have_fpu_hypot
float __ieee754_hypotf(float x, float y) {
  float a, b, t1, t2, y1, y2, w;
  int32_t j, k, ha, hb;

  GET_FLOAT_WORD(ha, x);
  ha &= IC(0x7fffffff);
  GET_FLOAT_WORD(hb, y);
  hb &= IC(0x7fffffff);
  if (hb > ha) {
    a = y;
    AssignF({(Addr)&a}, (Addr)&y,
            "/home/shijia/Public/testprogram/e_hypotf.c_e.c:30:7");
    ;
    b = x;
    AssignF({(Addr)&b}, (Addr)&x,
            "/home/shijia/Public/testprogram/e_hypotf.c_e.c:31:7");
    ;
    j = ha;
    ha = hb;
    hb = j;
  } else {
    a = x;
    AssignF({(Addr)&a}, (Addr)&x,
            "/home/shijia/Public/testprogram/e_hypotf.c_e.c:36:7");
    ;
    b = y;
    AssignF({(Addr)&b}, (Addr)&y,
            "/home/shijia/Public/testprogram/e_hypotf.c_e.c:37:7");
    ;
  }
  SET_FLOAT_WORD(a, ha); /* a <- |a| */
  SET_FLOAT_WORD(b, hb); /* b <- |b| */
  if ((ha - hb) > IC(0x0f000000)) {
    float temp_var_for_ext_0;
    float temp_var_for_tac_0;
    temp_var_for_tac_0 = a + b;

    temp_var_for_ext_0 = temp_var_for_tac_0;
    computeFAdd((Addr)&temp_var_for_tac_0, {(Addr)&a, (Addr)&b},
                "/home/shijia/Public/testprogram/e_hypotf.c_e.c:43:28");
    AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_0,
            "/home/shijia/Public/testprogram/e_hypotf.c_e.c:43:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  } /* x/y > 2**30 */
  k = 0;
  if (ha > IC(0x58800000)) {        /* a>2**50 */
    if (!FLT_UWORD_IS_FINITE(ha)) { /* Inf or NaN */
      float temp_var_for_tac_1;
      temp_var_for_tac_1 = a + b;

      w = temp_var_for_tac_1;
      computeFAdd((Addr)&temp_var_for_tac_1, {(Addr)&a, (Addr)&b},
                  "/home/shijia/Public/testprogram/e_hypotf.c_e.c:51:13");
      AssignF({(Addr)&w}, (Addr)&temp_var_for_tac_1,
              "/home/shijia/Public/testprogram/e_hypotf.c_e.c:51:9");
      ; /* for sNaN */
      if (FLT_UWORD_IS_INFINITE(ha)) {
        w = a;
        AssignF({(Addr)&w}, (Addr)&a,
                "/home/shijia/Public/testprogram/e_hypotf.c_e.c:53:11");
        ;
      }

      if (FLT_UWORD_IS_INFINITE(hb)) {
        w = b;
        AssignF({(Addr)&w}, (Addr)&b,
                "/home/shijia/Public/testprogram/e_hypotf.c_e.c:57:11");
        ;
      }

      float temp_var_for_ext_1;
      temp_var_for_ext_1 = w;
      AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&w,
              "/home/shijia/Public/testprogram/e_hypotf.c_e.c:61:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_1;
    }
    /* scale a and b by 2**-68 */
    ha -= IC(0x22000000);
    hb -= IC(0x22000000);
    k += 68;
    SET_FLOAT_WORD(a, ha);
    SET_FLOAT_WORD(b, hb);
  }
  if (hb < IC(0x26800000)) { /* b < 2**-50 */
    if (FLT_UWORD_IS_ZERO(hb)) {
      float temp_var_for_ext_2;
      temp_var_for_ext_2 = a;
      AssignF({(Addr)&temp_var_for_ext_2}, (Addr)&a,
              "/home/shijia/Public/testprogram/e_hypotf.c_e.c:77:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_2;
    } else {
      if (FLT_UWORD_IS_SUBNORMAL(hb)) {
        SET_FLOAT_WORD(t1, IC(0x7e800000)); /* t1=2^126 */
        b *= t1;
        ;
        a *= t1;
        ;
        k -= 126;
      } else {                /* scale a and b by 2^68 */
        ha += IC(0x22000000); /* a *= 2^68 */
        hb += IC(0x22000000); /* b *= 2^68 */
        k -= 68;
        SET_FLOAT_WORD(a, ha);
        SET_FLOAT_WORD(b, hb);
      }
    }
  }
  /* medium size a and b */
  float temp_var_for_tac_4;
  temp_var_for_tac_4 = a - b;

  w = temp_var_for_tac_4;
  computeFSub((Addr)&temp_var_for_tac_4, {(Addr)&a, (Addr)&b},
              "/home/shijia/Public/testprogram/e_hypotf.c_e.c:98:9");
  AssignF({(Addr)&w}, (Addr)&temp_var_for_tac_4,
          "/home/shijia/Public/testprogram/e_hypotf.c_e.c:98:5");
  ;
  if (int temp_var_for_tac_5; temp_var_for_tac_5 = w > b;

      ) {
    SET_FLOAT_WORD(t1, ha & IC(0xfffff000));
    float temp_var_for_tac_6;
    temp_var_for_tac_6 = a - t1;

    t2 = temp_var_for_tac_6;
    compute((Addr)&temp_var_for_tac_5, {(Addr)&w, (Addr)&b},
            "/home/shijia/Public/testprogram/e_hypotf.c_e.c:99:9");
    computeFSub((Addr)&temp_var_for_tac_6, {(Addr)&a, (Addr)&t1},
                "/home/shijia/Public/testprogram/e_hypotf.c_e.c:101:12");
    AssignF({(Addr)&t2}, (Addr)&temp_var_for_tac_6,
            "/home/shijia/Public/testprogram/e_hypotf.c_e.c:101:8");
    ;
    float temp_var_for_tac_7, temp_var_for_tac_8, temp_var_for_tac_9,
        temp_var_for_tac_10, temp_var_for_tac_11, temp_var_for_tac_12,
        temp_var_for_tac_13;
    float temp_var_for_const_0, temp_var_for_const_1;
    float temp_var_for_callexp_0;

    temp_var_for_tac_7 = t1 * t1;

    temp_var_for_tac_8 = 0.0 - b;

    temp_var_for_tac_9 = b * temp_var_for_tac_8;

    temp_var_for_tac_10 = a + t1;

    temp_var_for_tac_11 = t2 * temp_var_for_tac_10;

    temp_var_for_tac_12 = temp_var_for_tac_9 - temp_var_for_tac_11;

    temp_var_for_tac_13 = temp_var_for_tac_7 - temp_var_for_tac_12;

    temp_var_for_callexp_0 = __ieee754_sqrtf(temp_var_for_tac_13);
    w = temp_var_for_callexp_0;
    computeFMul((Addr)&temp_var_for_tac_7, {(Addr)&t1, (Addr)&t1},
                "/home/shijia/Public/testprogram/e_hypotf.c_e.c:102:28");
    computeDSub((Addr)&temp_var_for_tac_8,
                {(Addr) &(temp_var_for_const_0 = 0.0), (Addr)&b},
                "/home/shijia/Public/testprogram/e_hypotf.c_e.c:102:46");
    computeDMul((Addr)&temp_var_for_tac_9,
                {(Addr)&b, (Addr)&temp_var_for_tac_8},
                "/home/shijia/Public/testprogram/e_hypotf.c_e.c:102:38");
    computeFAdd((Addr)&temp_var_for_tac_10, {(Addr)&a, (Addr)&t1},
                "/home/shijia/Public/testprogram/e_hypotf.c_e.c:102:62");
    computeFMul((Addr)&temp_var_for_tac_11,
                {(Addr)&t2, (Addr)&temp_var_for_tac_10},
                "/home/shijia/Public/testprogram/e_hypotf.c_e.c:102:57");
    computeDSub((Addr)&temp_var_for_tac_12,
                {(Addr)&temp_var_for_tac_9, (Addr)&temp_var_for_tac_11},
                "/home/shijia/Public/testprogram/e_hypotf.c_e.c:102:52");
    computeDSub((Addr)&temp_var_for_tac_13,
                {(Addr)&temp_var_for_tac_7, (Addr)&temp_var_for_tac_12},
                "/home/shijia/Public/testprogram/e_hypotf.c_e.c:102:33");
    AssignF({(Addr)&w}, (Addr) &(temp_var_for_const_1 = temp_var_for_callexp_0),
            "/home/shijia/Public/testprogram/e_hypotf.c_e.c:102:7");
    ;
  } else {
    float temp_var_for_ext_3;
    float temp_var_for_tac_14;
    temp_var_for_tac_14 = a + a;

    temp_var_for_ext_3 = temp_var_for_tac_14;
    computeFAdd((Addr)&temp_var_for_tac_14, {(Addr)&a, (Addr)&a},
                "/home/shijia/Public/testprogram/e_hypotf.c_e.c:105:28");
    AssignF({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_14,
            "/home/shijia/Public/testprogram/e_hypotf.c_e.c:105:24");
    ; // a
    /*(t1)(a)(t2)(b)(b)(b)(t1)(t1)(t1)(t1)(t1)(a)(t2)(b)(b)(b)(b)(b)(b)(t1)(a)(t2)(t1)(a)(a)(a)*/
    a = temp_var_for_ext_3;
    AssignF({(Addr)&a}, (Addr)&temp_var_for_ext_3,
            "/home/shijia/Public/testprogram/e_hypotf.c_e.c:107:7");
    ;
    SET_FLOAT_WORD(y1, hb & IC(0xfffff000));
    float temp_var_for_tac_15;
    temp_var_for_tac_15 = b - y1;

    y2 = temp_var_for_tac_15;
    computeFSub((Addr)&temp_var_for_tac_15, {(Addr)&b, (Addr)&y1},
                "/home/shijia/Public/testprogram/e_hypotf.c_e.c:109:12");
    AssignF({(Addr)&y2}, (Addr)&temp_var_for_tac_15,
            "/home/shijia/Public/testprogram/e_hypotf.c_e.c:109:8");
    ;
    SET_FLOAT_WORD(t1, ha + IC(0x00800000));
    float temp_var_for_tac_16;
    temp_var_for_tac_16 = a - t1;

    t2 = temp_var_for_tac_16;
    computeFSub((Addr)&temp_var_for_tac_16, {(Addr)&a, (Addr)&t1},
                "/home/shijia/Public/testprogram/e_hypotf.c_e.c:111:12");
    AssignF({(Addr)&t2}, (Addr)&temp_var_for_tac_16,
            "/home/shijia/Public/testprogram/e_hypotf.c_e.c:111:8");
    ;
    float temp_var_for_tac_17, temp_var_for_tac_18, temp_var_for_tac_19,
        temp_var_for_tac_20, temp_var_for_tac_21, temp_var_for_tac_22,
        temp_var_for_tac_23, temp_var_for_tac_24;
    float temp_var_for_const_2, temp_var_for_const_3;
    float temp_var_for_callexp_1;

    temp_var_for_tac_17 = t1 * y1;

    temp_var_for_tac_18 = 0.0 - w;

    temp_var_for_tac_19 = w * temp_var_for_tac_18;

    temp_var_for_tac_20 = t1 * y2;

    temp_var_for_tac_21 = t2 * b;

    temp_var_for_tac_22 = temp_var_for_tac_20 + temp_var_for_tac_21;

    temp_var_for_tac_23 = temp_var_for_tac_19 - temp_var_for_tac_22;

    temp_var_for_tac_24 = temp_var_for_tac_17 - temp_var_for_tac_23;

    temp_var_for_callexp_1 = __ieee754_sqrtf(temp_var_for_tac_24);
    w = temp_var_for_callexp_1;
    computeFMul((Addr)&temp_var_for_tac_17, {(Addr)&t1, (Addr)&y1},
                "/home/shijia/Public/testprogram/e_hypotf.c_e.c:112:28");
    computeDSub((Addr)&temp_var_for_tac_18,
                {(Addr) &(temp_var_for_const_2 = 0.0), (Addr)&w},
                "/home/shijia/Public/testprogram/e_hypotf.c_e.c:112:46");
    computeDMul((Addr)&temp_var_for_tac_19,
                {(Addr)&w, (Addr)&temp_var_for_tac_18},
                "/home/shijia/Public/testprogram/e_hypotf.c_e.c:112:38");
    computeFMul((Addr)&temp_var_for_tac_20, {(Addr)&t1, (Addr)&y2},
                "/home/shijia/Public/testprogram/e_hypotf.c_e.c:112:58");
    computeFMul((Addr)&temp_var_for_tac_21, {(Addr)&t2, (Addr)&b},
                "/home/shijia/Public/testprogram/e_hypotf.c_e.c:112:68");
    computeFAdd((Addr)&temp_var_for_tac_22,
                {(Addr)&temp_var_for_tac_20, (Addr)&temp_var_for_tac_21},
                "/home/shijia/Public/testprogram/e_hypotf.c_e.c:112:63");
    computeDSub((Addr)&temp_var_for_tac_23,
                {(Addr)&temp_var_for_tac_19, (Addr)&temp_var_for_tac_22},
                "/home/shijia/Public/testprogram/e_hypotf.c_e.c:112:52");
    computeDSub((Addr)&temp_var_for_tac_24,
                {(Addr)&temp_var_for_tac_17, (Addr)&temp_var_for_tac_23},
                "/home/shijia/Public/testprogram/e_hypotf.c_e.c:112:33");
    AssignF({(Addr)&w}, (Addr) &(temp_var_for_const_3 = temp_var_for_callexp_1),
            "/home/shijia/Public/testprogram/e_hypotf.c_e.c:112:7");
    ;
  }
  if (k != 0) {
    SET_FLOAT_WORD(t1, IC(0x3f800000) + (k << 23));
    float temp_var_for_ext_4;
    float temp_var_for_tac_25;
    temp_var_for_tac_25 = t1 * w;

    temp_var_for_ext_4 = temp_var_for_tac_25;
    computeFMul((Addr)&temp_var_for_tac_25, {(Addr)&t1, (Addr)&w},
                "/home/shijia/Public/testprogram/e_hypotf.c_e.c:117:29");
    AssignF({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_25,
            "/home/shijia/Public/testprogram/e_hypotf.c_e.c:117:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_4;
  }
  float temp_var_for_ext_5;
  temp_var_for_ext_5 = w;
  AssignF({(Addr)&temp_var_for_ext_5}, (Addr)&w,
          "/home/shijia/Public/testprogram/e_hypotf.c_e.c:123:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_5;
}
#endif

float __hypotf(float x, float y) {
  float z = __ieee754_hypotf(x, y);

  if (!isfinite(z) && isfinite(x) && isfinite(y) && _LIB_VERSION != _IEEE_) {
    float temp_var_for_ext_6;
    float temp_var_for_const_4;
    float temp_var_for_callexp_2;

    temp_var_for_callexp_2 = __kernel_standard_f(x, y, z, KMATHERRF_HYPOT);
    temp_var_for_ext_6 = temp_var_for_callexp_2;
    AssignF({(Addr)&temp_var_for_ext_6},
            (Addr) &(temp_var_for_const_4 = temp_var_for_callexp_2),
            "/home/shijia/Public/testprogram/e_hypotf.c_e.c:135:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_6;
  }
  /* hypot overflow */

  float temp_var_for_ext_7;
  temp_var_for_ext_7 = z;
  AssignF({(Addr)&temp_var_for_ext_7}, (Addr)&z,
          "/home/shijia/Public/testprogram/e_hypotf.c_e.c:143:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_7;
}

__typeof(__hypotf) hypotf __attribute__((weak, alias("__hypotf")));
