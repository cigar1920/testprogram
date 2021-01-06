#include "../ScDebug/scdebug.h"
/* e_logf.c -- float version of e_log.c.
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

#ifndef __have_fpu_log

float __ieee754_logf(float x) {
  float hfsq, f, s, z, R, w, t1, t2, dk;
  int32_t k, ix, i, j;

  static const float ln2_hi = 6.9313812256e-01; /* 0x3f317180 */
  static const float ln2_lo = 9.0580006145e-06; /* 0x3717f7d1 */
  static const float two25 = 3.355443200e+07;   /* 0x4c000000 */
  static const float Lg1 = 6.6666668653e-01;    /* 3F2AAAAB */
  static const float Lg2 = 4.0000000596e-01;    /* 3ECCCCCD */
  static const float Lg3 = 2.8571429849e-01;    /* 3E924925 */
  static const float Lg4 = 2.2222198546e-01;    /* 3E638E29 */
  static const float Lg5 = 1.8183572590e-01;    /* 3E3A3325 */
  static const float Lg6 = 1.5313838422e-01;    /* 3E1CD04F */
  static const float Lg7 = 1.4798198640e-01;    /* 3E178897 */

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
  f = x - (float)1.0;
  computeFSub((Addr)&f, {(Addr)&x, (Addr) & ((float)1.0)},
              "/home/shijia/Public/testprogram/e_logf.c_e.c:58:5");
  if ((IC(0x007fffff) & (15 + ix)) < 16) { /* |f| < 2**-20 */
    if (f == zero) {
      if (k == 0)
        return zero;
      else {
        dk = (float)k;
        return dk * ln2_hi + dk * ln2_lo;
      }
    }
    R = f * f * ((float)0.5 - (float)0.33333333333333333 * f);
    if (k == 0)
      return f - R;
    else {
      dk = (float)k;
      return dk * ln2_hi - ((R - dk * ln2_lo) - f);
    }
  }
  s = f / ((float)2.0 + f);
  float temp_var_for_tac_0;
  computeFAdd((Addr)&temp_var_for_tac_0, {(Addr) & ((float)2.0), (Addr)&f},
              "/home/shijia/Public/testprogram/e_logf.c_e.c:76:9");
  computeFDiv((Addr)&s, {(Addr)&f, (Addr)&temp_var_for_tac_0},
              "/home/shijia/Public/testprogram/e_logf.c_e.c:76:5");
  dk = (float)k;
  z = s * s;
  computeFMul((Addr)&z, {(Addr)&s, (Addr)&s},
              "/home/shijia/Public/testprogram/e_logf.c_e.c:78:5");
  i = ix - (IC(0x6147a) << 3);
  w = z * z;
  computeFMul((Addr)&w, {(Addr)&z, (Addr)&z},
              "/home/shijia/Public/testprogram/e_logf.c_e.c:80:5");
  j = (IC(0x6b851) << 3) - ix;
  t1 = w * (Lg2 + w * (Lg4 + w * Lg6));
  float temp_var_for_const_0, temp_var_for_const_1, temp_var_for_const_2;
  float temp_var_for_tac_1, temp_var_for_tac_2, temp_var_for_tac_3,
      temp_var_for_tac_4;
  computeFMul((Addr)&temp_var_for_tac_1,
              {(Addr)&w, (Addr) &(temp_var_for_const_0 = Lg6)},
              "/home/shijia/Public/testprogram/e_logf.c_e.c:82:28");
  computeFAdd((Addr)&temp_var_for_tac_2,
              {(Addr) &(temp_var_for_const_1 = Lg4), (Addr)&temp_var_for_tac_1},
              "/home/shijia/Public/testprogram/e_logf.c_e.c:82:21");
  computeFMul((Addr)&temp_var_for_tac_3, {(Addr)&w, (Addr)&temp_var_for_tac_2},
              "/home/shijia/Public/testprogram/e_logf.c_e.c:82:17");
  computeFAdd((Addr)&temp_var_for_tac_4,
              {(Addr) &(temp_var_for_const_2 = Lg2), (Addr)&temp_var_for_tac_3},
              "/home/shijia/Public/testprogram/e_logf.c_e.c:82:10");
  computeFMul((Addr)&t1, {(Addr)&w, (Addr)&temp_var_for_tac_4},
              "/home/shijia/Public/testprogram/e_logf.c_e.c:82:6");
  t2 = z * (Lg1 + w * (Lg3 + w * (Lg5 + w * Lg7)));
  float temp_var_for_const_3, temp_var_for_const_4, temp_var_for_const_5,
      temp_var_for_const_6;
  float temp_var_for_tac_5, temp_var_for_tac_6, temp_var_for_tac_7,
      temp_var_for_tac_8, temp_var_for_tac_9, temp_var_for_tac_10;
  computeFMul((Addr)&temp_var_for_tac_5,
              {(Addr)&w, (Addr) &(temp_var_for_const_3 = Lg7)},
              "/home/shijia/Public/testprogram/e_logf.c_e.c:83:39");
  computeFAdd((Addr)&temp_var_for_tac_6,
              {(Addr) &(temp_var_for_const_4 = Lg5), (Addr)&temp_var_for_tac_5},
              "/home/shijia/Public/testprogram/e_logf.c_e.c:83:32");
  computeFMul((Addr)&temp_var_for_tac_7, {(Addr)&w, (Addr)&temp_var_for_tac_6},
              "/home/shijia/Public/testprogram/e_logf.c_e.c:83:28");
  computeFAdd((Addr)&temp_var_for_tac_8,
              {(Addr) &(temp_var_for_const_5 = Lg3), (Addr)&temp_var_for_tac_7},
              "/home/shijia/Public/testprogram/e_logf.c_e.c:83:21");
  computeFMul((Addr)&temp_var_for_tac_9, {(Addr)&w, (Addr)&temp_var_for_tac_8},
              "/home/shijia/Public/testprogram/e_logf.c_e.c:83:17");
  computeFAdd((Addr)&temp_var_for_tac_10,
              {(Addr) &(temp_var_for_const_6 = Lg1), (Addr)&temp_var_for_tac_9},
              "/home/shijia/Public/testprogram/e_logf.c_e.c:83:10");
  computeFMul((Addr)&t2, {(Addr)&z, (Addr)&temp_var_for_tac_10},
              "/home/shijia/Public/testprogram/e_logf.c_e.c:83:6");
  i |= j;
  R = t2 + t1;
  computeFAdd((Addr)&R, {(Addr)&t2, (Addr)&t1},
              "/home/shijia/Public/testprogram/e_logf.c_e.c:85:5");
  if (i > 0) {
    hfsq = 0.5F * f * f;

    if (k == 0)
      return f - (hfsq - s * (hfsq + R));
    else
      return dk * ln2_hi - ((hfsq - (s * (hfsq + R) + dk * ln2_lo)) - f);
  } else {
    if (k == 0)
      return f - s * (f - R);
    else
      return dk * ln2_hi - ((s * (f - R) - dk * ln2_lo) - f);
  }
}

#endif

/* wrapper logf(x) */
float __logf(float x) {
  if (islessequal(x, 0.0f) && _LIB_VERSION != _IEEE_) {
    if (x == 0.0f) {
      feraiseexcept(FE_DIVBYZERO);
      return __kernel_standard_f(x, x, -HUGE_VALF,
                                 KMATHERRF_LOG_ZERO); /* log(0) */
    } else {
      feraiseexcept(FE_INVALID);
      return __kernel_standard_f(x, x, __builtin_nanf(""),
                                 KMATHERRF_LOG_MINUS); /* log(x<0) */
    }
  }

  float temp_var_for_ext_0;
  temp_var_for_ext_0 = __ieee754_logf(x);
  float temp_var_for_callexp_0 = __ieee754_logf(getFVbyShadow<float>((Addr)&x));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_callexp_0,
          "/home/shijia/Public/testprogram/e_logf.c_e.c:118:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

__typeof(__logf) logf __attribute__((weak, alias("__logf")));
