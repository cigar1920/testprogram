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
    b = x;
    j = ha;
    ha = hb;
    hb = j;
  } else {
    a = x;
    b = y;
  }
  SET_FLOAT_WORD(a, ha); /* a <- |a| */
  SET_FLOAT_WORD(b, hb); /* b <- |b| */
  if ((ha - hb) > IC(0x0f000000)) {
    return a + b;
  } /* x/y > 2**30 */
  k = 0;
  if (ha > IC(0x58800000)) {        /* a>2**50 */
    if (!FLT_UWORD_IS_FINITE(ha)) { /* Inf or NaN */
      w = a + b;                    /* for sNaN */
      if (FLT_UWORD_IS_INFINITE(ha))
        w = a;
      if (FLT_UWORD_IS_INFINITE(hb))
        w = b;
      return w;
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
      return a;
    } else if (FLT_UWORD_IS_SUBNORMAL(hb)) {
      SET_FLOAT_WORD(t1, IC(0x7e800000)); /* t1=2^126 */
      b *= t1;
      a *= t1;
      k -= 126;
    } else {                /* scale a and b by 2^68 */
      ha += IC(0x22000000); /* a *= 2^68 */
      hb += IC(0x22000000); /* b *= 2^68 */
      k -= 68;
      SET_FLOAT_WORD(a, ha);
      SET_FLOAT_WORD(b, hb);
    }
  }
  /* medium size a and b */
  w = a - b;
  computeFSub((Addr)&w, {(Addr)&a, (Addr)&b},
              "/home/shijia/Public/testprogram/e_hypotf.c_e.c:78:5");
  if (w > b) {
    SET_FLOAT_WORD(t1, ha & IC(0xfffff000));
    t2 = a - t1;
    computeFSub((Addr)&t2, {(Addr)&a, (Addr)&t1},
                "/home/shijia/Public/testprogram/e_hypotf.c_e.c:81:8");
    w = __ieee754_sqrtf(t1 * t1 - (b * ((0.0 - b)) - t2 * (a + t1)));
    float temp_var_for_const_0, temp_var_for_const_1;
    float temp_var_for_tac_0, temp_var_for_tac_1, temp_var_for_tac_2,
        temp_var_for_tac_3, temp_var_for_tac_4, temp_var_for_tac_5,
        temp_var_for_tac_6;
    computeDSub((Addr)&temp_var_for_tac_6,
                {(Addr)&temp_var_for_tac_0, (Addr)&temp_var_for_tac_5},
                "toString(biExpr->getExprLoc())");
    computeDMul((Addr)&temp_var_for_tac_0, {(Addr)&t1, (Addr)&t1},
                "/home/shijia/Public/testprogram/e_hypotf.c_e.c:82:46");
    computeDSub((Addr)&temp_var_for_tac_1,
                {(Addr) &(temp_var_for_const_0 = 0.0), (Addr)&b},
                "/home/shijia/Public/testprogram/e_hypotf.c_e.c:82:38");
    computeFMul((Addr)&temp_var_for_tac_2,
                {(Addr)&b, (Addr)&temp_var_for_tac_1},
                "/home/shijia/Public/testprogram/e_hypotf.c_e.c:82:62");
    computeFAdd((Addr)&temp_var_for_tac_3, {(Addr)&a, (Addr)&t1},
                "/home/shijia/Public/testprogram/e_hypotf.c_e.c:82:57");
    computeDMul((Addr)&temp_var_for_tac_4,
                {(Addr)&t2, (Addr)&temp_var_for_tac_3},
                "/home/shijia/Public/testprogram/e_hypotf.c_e.c:82:52");
    computeDSub((Addr)&temp_var_for_tac_5,
                {(Addr)&temp_var_for_tac_2, (Addr)&temp_var_for_tac_4},
                "/home/shijia/Public/testprogram/e_hypotf.c_e.c:82:33");AssignF({(Addr)&w},(Addr)&(temp_var_for_const_1=__ieee754_sqrtf(getFVbyShadow<int>((Addr)&temp_var_for_tac_6)),"/home/shijia/Public/testprogram/e_hypotf.c_e.c:82:7");
  } else {
    float temp_var_for_ext_0;
    temp_var_for_ext_0 = a + a;
    computeFAdd((Addr)&temp_var_for_ext_0, {(Addr)&a, (Addr)&a},
                "/home/shijia/Public/testprogram/e_hypotf.c_e.c:85:24"); // a
    /*(t1)(a)(t2)(b)(b)(b)(t1)(t1)(t1)(t1)(t1)(a)(t2)(b)(b)(b)(b)(b)(b)(t1)(a)(t2)(t1)(a)(a)(a)*/
    a = temp_var_for_ext_0;
    AssignF({(Addr)&a}, (Addr)&temp_var_for_ext_0,
            "/home/shijia/Public/testprogram/e_hypotf.c_e.c:87:7");
    SET_FLOAT_WORD(y1, hb & IC(0xfffff000));
    y2 = b - y1;
    computeFSub((Addr)&y2, {(Addr)&b, (Addr)&y1},
                "/home/shijia/Public/testprogram/e_hypotf.c_e.c:89:8");
    SET_FLOAT_WORD(t1, ha + IC(0x00800000));
    t2 = a - t1;
    computeFSub((Addr)&t2, {(Addr)&a, (Addr)&t1},
                "/home/shijia/Public/testprogram/e_hypotf.c_e.c:91:8");
    w = __ieee754_sqrtf(t1 * y1 - (w * ((0.0 - w)) - (t1 * y2 + t2 * b)));
    float temp_var_for_const_2, temp_var_for_const_3;
    float temp_var_for_tac_7, temp_var_for_tac_8, temp_var_for_tac_9,
        temp_var_for_tac_10, temp_var_for_tac_11, temp_var_for_tac_12,
        temp_var_for_tac_13, temp_var_for_tac_14;
    computeDSub((Addr)&temp_var_for_tac_14,
                {(Addr)&temp_var_for_tac_7, (Addr)&temp_var_for_tac_13},
                "toString(biExpr->getExprLoc())");
    computeDMul((Addr)&temp_var_for_tac_7, {(Addr)&t1, (Addr)&y1},
                "/home/shijia/Public/testprogram/e_hypotf.c_e.c:92:46");
    computeDSub((Addr)&temp_var_for_tac_8,
                {(Addr) &(temp_var_for_const_2 = 0.0), (Addr)&w},
                "/home/shijia/Public/testprogram/e_hypotf.c_e.c:92:38");
    computeFMul((Addr)&temp_var_for_tac_9,
                {(Addr)&w, (Addr)&temp_var_for_tac_8},
                "/home/shijia/Public/testprogram/e_hypotf.c_e.c:92:58");
    computeFMul((Addr)&temp_var_for_tac_10, {(Addr)&t1, (Addr)&y2},
                "/home/shijia/Public/testprogram/e_hypotf.c_e.c:92:68");
    computeFMul((Addr)&temp_var_for_tac_11, {(Addr)&t2, (Addr)&b},
                "/home/shijia/Public/testprogram/e_hypotf.c_e.c:92:63");
    computeDAdd((Addr)&temp_var_for_tac_12,
                {(Addr)&temp_var_for_tac_10, (Addr)&temp_var_for_tac_11},
                "/home/shijia/Public/testprogram/e_hypotf.c_e.c:92:52");
    computeDSub((Addr)&temp_var_for_tac_13,
                {(Addr)&temp_var_for_tac_9, (Addr)&temp_var_for_tac_12},
                "/home/shijia/Public/testprogram/e_hypotf.c_e.c:92:33");AssignF({(Addr)&w},(Addr)&(temp_var_for_const_3=__ieee754_sqrtf(getFVbyShadow<int>((Addr)&temp_var_for_tac_14)),"/home/shijia/Public/testprogram/e_hypotf.c_e.c:92:7");
  }
  if (k != 0) {
    SET_FLOAT_WORD(t1, IC(0x3f800000) + (k << 23));
    return t1 * w;
  }
  float temp_var_for_ext_1;
  temp_var_for_ext_1 = w;
  AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&w,
          "/home/shijia/Public/testprogram/e_hypotf.c_e.c:99:22");
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}
#endif

float __hypotf(float x, float y) {
  float z = __ieee754_hypotf(x, y);

  if (!isfinite(z) && isfinite(x) && isfinite(y) && _LIB_VERSION != _IEEE_)
    return __kernel_standard_f(x, y, z, KMATHERRF_HYPOT); /* hypot overflow */

  float temp_var_for_ext_2;
  temp_var_for_ext_2 = z;
  AssignF({(Addr)&temp_var_for_ext_2}, (Addr)&z,
          "/home/shijia/Public/testprogram/e_hypotf.c_e.c:113:22");
  callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_2;
}

__typeof(__hypotf) hypotf __attribute__((weak, alias("__hypotf")));
