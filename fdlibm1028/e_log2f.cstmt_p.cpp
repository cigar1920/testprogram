#include "../ScDebug/scdebug.h"
/* e_logf.c -- float version of e_log.c.
 * Conversion to float by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.
 * adapted for log2 by Ulrich Drepper <drepper@cygnus.com>
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

#ifndef __have_fpu_log2

float __ieee754_log2f(float x) {
  float hfsq, f, s, z, R, w, t1, t2, dk;
  int32_t k, ix, i, j;

  static const float ln2 = 0.69314718055994530942;
  static const float two25 = 3.355443200e+07; /* 0x4c000000 */
  static const float Lg1 = 6.6666668653e-01;  /* 3F2AAAAB */
  static const float Lg2 = 4.0000000596e-01;  /* 3ECCCCCD */
  static const float Lg3 = 2.8571429849e-01;  /* 3E924925 */
  static const float Lg4 = 2.2222198546e-01;  /* 3E638E29 */
  static const float Lg5 = 1.8183572590e-01;  /* 3E3A3325 */
  static const float Lg6 = 1.5313838422e-01;  /* 3E1CD04F */
  static const float Lg7 = 1.4798198640e-01;  /* 3E178897 */

  static const float zero = 0.0;

  GET_FLOAT_WORD(ix, x);

  k = 0;
  if (ix < IC(0x00800000)) { /* x < 2**-126  */
    if ((ix & IC(0x7fffffff)) == 0)
      return -two25 / (x - x); /* log(+-0)=-inf */
    if (ix < 0)
      return (x - x) / (x - x); /* log(-#) = NaN */
    k -= 25;
    x *= two25; /* subnormal number, scale up x */
    GET_FLOAT_WORD(ix, x);
  }
  if (ix >= IC(0x7f800000))
    return x + x;
  k += (ix >> 23) - 127;
  ix &= IC(0x007fffff);
  i = (ix + (IC(0x95f64) << 3)) & IC(0x800000);
  SET_FLOAT_WORD(x, ix | (i ^ IC(0x3f800000))); /* normalize x or x/2 */
  k += (i >> 23);
  dk = (float)k;
  f = x - (float)1.0;
  computeFSub((Addr)&f, {(Addr)&x, (Addr) & ((float)1.0)},
              "/home/shijia/Public/testprogram/e_log2f.c_e.c:59:5");
  if ((IC(0x007fffff) & (15 + ix)) < 16) { /* |f| < 2**-20 */
    if (f == zero)
      return dk;
    R = f * f * ((float)0.5 - (float)0.33333333333333333 * f);
    return dk - (R - f) / ln2;
  }
  s = f / ((float)2.0 + f);
  float temp_var_for_tac_0;
  computeFAdd((Addr)&temp_var_for_tac_0, {(Addr) & ((float)2.0), (Addr)&f},
              "/home/shijia/Public/testprogram/e_log2f.c_e.c:66:9");
  computeFDiv((Addr)&s, {(Addr)&f, (Addr)&temp_var_for_tac_0},
              "/home/shijia/Public/testprogram/e_log2f.c_e.c:66:5");
  z = s * s;
  computeFMul((Addr)&z, {(Addr)&s, (Addr)&s},
              "/home/shijia/Public/testprogram/e_log2f.c_e.c:67:5");
  i = ix - (IC(0x6147a) << 3);
  w = z * z;
  computeFMul((Addr)&w, {(Addr)&z, (Addr)&z},
              "/home/shijia/Public/testprogram/e_log2f.c_e.c:69:5");
  j = (IC(0x6b851) << 3) - ix;
  t1 = w * (Lg2 + w * (Lg4 + w * Lg6));
  float temp_var_for_const_0, temp_var_for_const_1, temp_var_for_const_2;
  float temp_var_for_tac_1, temp_var_for_tac_2, temp_var_for_tac_3,
      temp_var_for_tac_4;
  computeFMul((Addr)&temp_var_for_tac_1,
              {(Addr)&w, (Addr) &(temp_var_for_const_0 = Lg6)},
              "/home/shijia/Public/testprogram/e_log2f.c_e.c:71:28");
  computeFAdd((Addr)&temp_var_for_tac_2,
              {(Addr) &(temp_var_for_const_1 = Lg4), (Addr)&temp_var_for_tac_1},
              "/home/shijia/Public/testprogram/e_log2f.c_e.c:71:21");
  computeFMul((Addr)&temp_var_for_tac_3, {(Addr)&w, (Addr)&temp_var_for_tac_2},
              "/home/shijia/Public/testprogram/e_log2f.c_e.c:71:17");
  computeFAdd((Addr)&temp_var_for_tac_4,
              {(Addr) &(temp_var_for_const_2 = Lg2), (Addr)&temp_var_for_tac_3},
              "/home/shijia/Public/testprogram/e_log2f.c_e.c:71:10");
  computeFMul((Addr)&t1, {(Addr)&w, (Addr)&temp_var_for_tac_4},
              "/home/shijia/Public/testprogram/e_log2f.c_e.c:71:6");
  t2 = z * (Lg1 + w * (Lg3 + w * (Lg5 + w * Lg7)));
  float temp_var_for_const_3, temp_var_for_const_4, temp_var_for_const_5,
      temp_var_for_const_6;
  float temp_var_for_tac_5, temp_var_for_tac_6, temp_var_for_tac_7,
      temp_var_for_tac_8, temp_var_for_tac_9, temp_var_for_tac_10;
  computeFMul((Addr)&temp_var_for_tac_5,
              {(Addr)&w, (Addr) &(temp_var_for_const_3 = Lg7)},
              "/home/shijia/Public/testprogram/e_log2f.c_e.c:72:39");
  computeFAdd((Addr)&temp_var_for_tac_6,
              {(Addr) &(temp_var_for_const_4 = Lg5), (Addr)&temp_var_for_tac_5},
              "/home/shijia/Public/testprogram/e_log2f.c_e.c:72:32");
  computeFMul((Addr)&temp_var_for_tac_7, {(Addr)&w, (Addr)&temp_var_for_tac_6},
              "/home/shijia/Public/testprogram/e_log2f.c_e.c:72:28");
  computeFAdd((Addr)&temp_var_for_tac_8,
              {(Addr) &(temp_var_for_const_5 = Lg3), (Addr)&temp_var_for_tac_7},
              "/home/shijia/Public/testprogram/e_log2f.c_e.c:72:21");
  computeFMul((Addr)&temp_var_for_tac_9, {(Addr)&w, (Addr)&temp_var_for_tac_8},
              "/home/shijia/Public/testprogram/e_log2f.c_e.c:72:17");
  computeFAdd((Addr)&temp_var_for_tac_10,
              {(Addr) &(temp_var_for_const_6 = Lg1), (Addr)&temp_var_for_tac_9},
              "/home/shijia/Public/testprogram/e_log2f.c_e.c:72:10");
  computeFMul((Addr)&t2, {(Addr)&z, (Addr)&temp_var_for_tac_10},
              "/home/shijia/Public/testprogram/e_log2f.c_e.c:72:6");
  i |= j;
  R = t2 + t1;
  computeFAdd((Addr)&R, {(Addr)&t2, (Addr)&t1},
              "/home/shijia/Public/testprogram/e_log2f.c_e.c:74:5");
  if (i > 0) {
    hfsq = (float)0.5 * f * f;

    return dk - ((hfsq - (s * (hfsq + R))) - f) / ln2;
  } else {
    return dk - ((s * (f - R)) - f) / ln2;
  }
}

#endif

/* wrapper log2(x) */
float __log2f(float x) {
  if (islessequal(x, 0.0) && _LIB_VERSION != _IEEE_) {
    if (x == 0.0F) {
      feraiseexcept(FE_DIVBYZERO);
      return __kernel_standard_f(x, x, -HUGE_VALF,
                                 KMATHERRF_LOG2_ZERO); /* log2(0) */
    } else {
      feraiseexcept(FE_INVALID);
      return __kernel_standard_f(x, x, __builtin_nanf(""),
                                 KMATHERRF_LOG2_MINUS); /* log2(x<0) */
    }
  }

  float temp_var_for_ext_0;
  temp_var_for_ext_0 = __ieee754_log2f(x);
  float temp_var_for_callexp_0 =
      __ieee754_log2f(getFVbyShadow<float>((Addr)&x));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_callexp_0,
          "/home/shijia/Public/testprogram/e_log2f.c_e.c:101:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

__typeof(__log2f) log2f __attribute__((weak, alias("__log2f")));
