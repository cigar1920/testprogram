#include "../ScDebug/scdebug.h"
/* s_expm1f.c -- float version of s_expm1.c.
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

#ifndef __have_fpu_expm1

float __ieee754_expm1f(float x) {
  float y, hi, lo, c, t, e, hxs, hfx, r1;
  int32_t k, xsb;
  uint32_t hx;

  static const float hugeval = 1.0e+30;
  static const float one = 1.0;
  static const float o_threshold = 8.8721679688e+01; /* 0x42b17180 */
  static const float ln2_hi = 6.9313812256e-01;      /* 0x3f317180 */
  static const float ln2_lo = 9.0580006145e-06;      /* 0x3717f7d1 */
  static const float invln2 = 1.4426950216e+00;      /* 0x3fb8aa3b */
  /* scaled coefficients related to expm1 */
  static const float Q1 = (0.0 - 3.3333335072e-02);
  double temp_var_for_const_0, temp_var_for_const_1;
  ;                                         /* 0xbd088889 */
  static const float Q2 = 1.5873016091e-03; /* 0x3ad00d01 */
  static const float Q3 = (0.0 - 7.9365076090e-05);
  double temp_var_for_const_2, temp_var_for_const_3;
  double temp_var_for_tac_0;
  computeDSub((Addr)&temp_var_for_tac_0,
              {(Addr) &(temp_var_for_const_1 = 0.0),
               (Addr) &(temp_var_for_const_0 = 3.3333335072e-02)},
              "/home/shijia/Public/testprogram/s_expm1f.c_e.c:36:32");
  ;                                         /* 0xb8a670cd */
  static const float Q4 = 4.0082177293e-06; /* 0x36867e54 */
  static const float Q5 = (0.0 - 2.0109921195e-07);
  double temp_var_for_const_4, temp_var_for_const_5;
  double temp_var_for_tac_1;
  computeDSub((Addr)&temp_var_for_tac_1,
              {(Addr) &(temp_var_for_const_3 = 0.0),
               (Addr) &(temp_var_for_const_2 = 7.9365076090e-05)},
              "/home/shijia/Public/testprogram/s_expm1f.c_e.c:38:32");
  ; /* 0xb457edbb */

  GET_FLOAT_WORD(hx, x);
  xsb = hx & UC(0x80000000); /* sign bit of x */
  if (xsb == 0)
    y = x;
  else
    y = -x;             /* y = |x| */
  hx &= UC(0x7fffffff); /* high word of |x| */

  /* filter out huge and non-finite argument */
  if (hx >= UC(0x4195b844)) {   /* if |x|>=27*ln2 */
    if (hx >= UC(0x42b17218)) { /* if |x|>=88.721... */
      if (hx > UC(0x7f800000))
        return x + x; /* NaN */
      if (hx == UC(0x7f800000))
        return (xsb == 0) ? x : -one; /* exp(+-inf)={inf,-1} */
      if (x > o_threshold) {
        feraiseexcept(FE_OVERFLOW);
        return HUGE_VALF; /* overflow */
      }
    }
    if (xsb != 0) {              /* x < -27*ln2, return -1.0 with inexact */
      feraiseexcept(FE_INEXACT); /* raise inexact */
      return -one;               /* return -1 */
    }
  }

  /* argument reduction */
  if (hx > UC(0x3eb17218)) {   /* if  |x| > 0.5 ln2 */
    if (hx < UC(0x3F851592)) { /* and |x| < 1.5 ln2 */
      if (xsb == 0) {
        hi = x - ln2_hi;
        lo = ln2_lo;
        k = 1;
      } else {
        hi = x + ln2_hi;
        lo = -ln2_lo;
        k = -1;
      }
    } else {
      k = invln2 * x + ((xsb == 0) ? 0.5F : -0.5F);
      t = k;
      hi = x - t * ln2_hi; /* t*ln2_hi is exact here */
      lo = t * ln2_lo;
    }
    x = hi - lo;
    c = (hi - x) - lo;
  } else if (hx < UC(0x33000000)) { /* when |x|<2**-25, return x */
    t = hugeval + x;                /* return x with inexact flags when x!=0 */
    return x - (t - (hugeval + x));
  } else {
    k = 0;
    c = 0;
  }

  /* x is now in primary range */
  hfx = 0.5F * x;
  float temp_var_for_const_6;
  float temp_var_for_tac_2;
  computeFSub((Addr)&temp_var_for_tac_2,
              {(Addr) &(temp_var_for_const_5 = 0.0),
               (Addr) &(temp_var_for_const_4 = 2.0109921195e-07)},
              "/home/shijia/Public/testprogram/s_expm1f.c_e.c:95:14");
  computeFMul((Addr)&hfx, {(Addr) &(temp_var_for_const_6 = 0.5F), (Addr)&x},
              "/home/shijia/Public/testprogram/s_expm1f.c_e.c:95:7");

  hxs = x * hfx;
  computeFMul((Addr)&hxs, {(Addr)&x, (Addr)&hfx},
              "/home/shijia/Public/testprogram/s_expm1f.c_e.c:97:7");
  r1 = one + hxs * (Q1 + hxs * (Q2 + hxs * (Q3 + hxs * (Q4 + hxs * Q5))));
  float temp_var_for_const_7, temp_var_for_const_8, temp_var_for_const_9,
      temp_var_for_const_10, temp_var_for_const_11, temp_var_for_const_12;
  float temp_var_for_tac_3, temp_var_for_tac_4, temp_var_for_tac_5,
      temp_var_for_tac_6, temp_var_for_tac_7, temp_var_for_tac_8,
      temp_var_for_tac_9, temp_var_for_tac_10, temp_var_for_tac_11;
  computeFMul((Addr)&temp_var_for_tac_3,
              {(Addr)&hxs, (Addr) &(temp_var_for_const_7 = Q5)},
              "/home/shijia/Public/testprogram/s_expm1f.c_e.c:98:60");
  computeFAdd((Addr)&temp_var_for_tac_4,
              {(Addr) &(temp_var_for_const_8 = Q4), (Addr)&temp_var_for_tac_3},
              "/home/shijia/Public/testprogram/s_expm1f.c_e.c:98:54");
  computeFMul((Addr)&temp_var_for_tac_5,
              {(Addr)&hxs, (Addr)&temp_var_for_tac_4},
              "/home/shijia/Public/testprogram/s_expm1f.c_e.c:98:48");
  computeFAdd((Addr)&temp_var_for_tac_6,
              {(Addr) &(temp_var_for_const_9 = Q3), (Addr)&temp_var_for_tac_5},
              "/home/shijia/Public/testprogram/s_expm1f.c_e.c:98:42");
  computeFMul((Addr)&temp_var_for_tac_7,
              {(Addr)&hxs, (Addr)&temp_var_for_tac_6},
              "/home/shijia/Public/testprogram/s_expm1f.c_e.c:98:36");
  computeFAdd((Addr)&temp_var_for_tac_8,
              {(Addr) &(temp_var_for_const_10 = Q2), (Addr)&temp_var_for_tac_7},
              "/home/shijia/Public/testprogram/s_expm1f.c_e.c:98:30");
  computeFMul((Addr)&temp_var_for_tac_9,
              {(Addr)&hxs, (Addr)&temp_var_for_tac_8},
              "/home/shijia/Public/testprogram/s_expm1f.c_e.c:98:24");
  computeFAdd((Addr)&temp_var_for_tac_10,
              {(Addr) &(temp_var_for_const_11 = Q1), (Addr)&temp_var_for_tac_9},
              "/home/shijia/Public/testprogram/s_expm1f.c_e.c:98:18");
  computeFMul((Addr)&temp_var_for_tac_11,
              {(Addr)&hxs, (Addr)&temp_var_for_tac_10},
              "/home/shijia/Public/testprogram/s_expm1f.c_e.c:98:12");
  computeFAdd((Addr)&r1, {(Addr) &(temp_var_for_const_12 = one),
                          (Addr)&temp_var_for_tac_11},
              "/home/shijia/Public/testprogram/s_expm1f.c_e.c:98:6");
  t = 3.0F - r1 * hfx;
  float temp_var_for_const_13;
  float temp_var_for_tac_12;
  computeFMul((Addr)&temp_var_for_tac_12, {(Addr)&r1, (Addr)&hfx},
              "/home/shijia/Public/testprogram/s_expm1f.c_e.c:99:12");
  computeFSub((Addr)&t, {(Addr) &(temp_var_for_const_13 = 3.0F),
                         (Addr)&temp_var_for_tac_12},
              "/home/shijia/Public/testprogram/s_expm1f.c_e.c:99:5");
  e = hxs * ((r1 - t) / (6.0F - x * t));
  float temp_var_for_const_14;
  float temp_var_for_tac_13, temp_var_for_tac_14, temp_var_for_tac_15,
      temp_var_for_tac_16;
  computeFSub((Addr)&temp_var_for_tac_13, {(Addr)&r1, (Addr)&t},
              "/home/shijia/Public/testprogram/s_expm1f.c_e.c:100:35");
  computeFMul((Addr)&temp_var_for_tac_14, {(Addr)&x, (Addr)&t},
              "/home/shijia/Public/testprogram/s_expm1f.c_e.c:100:31");
  computeFSub(
      (Addr)&temp_var_for_tac_15,
      {(Addr) &(temp_var_for_const_14 = 6.0F), (Addr)&temp_var_for_tac_14},
      "/home/shijia/Public/testprogram/s_expm1f.c_e.c:100:23");
  computeFDiv((Addr)&temp_var_for_tac_16,
              {(Addr)&temp_var_for_tac_13, (Addr)&temp_var_for_tac_15},
              "/home/shijia/Public/testprogram/s_expm1f.c_e.c:100:11");
  computeFMul((Addr)&e, {(Addr)&hxs, (Addr)&temp_var_for_tac_16},
              "/home/shijia/Public/testprogram/s_expm1f.c_e.c:100:5");
  if (k == 0)
    return x - (x * e - hxs); /* c is 0 */
  else {
    e = (x * (e - c) - c);
    e -= hxs;
    if (k == -1)
      return 0.5F * (x - e) - 0.5F;

    if (k == 1) {
      if (x < -0.25F)
        return -2.0F * (e - (x + 0.5F));
      else
        return one + 2.0F * (x - e);
    }
    if (k <= -2 || k > 56) { /* suffice to return exp(x)-1 */
      int32_t i;

      y = one - (e - x);
      GET_FLOAT_WORD(i, y);
      SET_FLOAT_WORD(y, i + (k << 23)); /* add k to y's exponent */
      return y - one;
    }
    t = one;
    if (k < 23) {
      int32_t i;

      SET_FLOAT_WORD(t, UC(0x3f800000) - (UC(0x1000000) >> k)); /* t=1-2^-k */
      y = t - (e - x);
      GET_FLOAT_WORD(i, y);
      SET_FLOAT_WORD(y, i + (k << 23)); /* add k to y's exponent */
    } else {
      int32_t i;

      SET_FLOAT_WORD(t, ((UC(0x7f) - k) << 23)); /* 2^-k */
      y = x - (e + t);
      y += one;
      GET_FLOAT_WORD(i, y);
      SET_FLOAT_WORD(y, i + (k << 23)); /* add k to y's exponent */
    }
  }
  float temp_var_for_ext_0;
  temp_var_for_ext_0 = y;
  AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&y,
          "/home/shijia/Public/testprogram/s_expm1f.c_e.c:142:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

#endif

float __expm1f(float x) {
  float z = __ieee754_expm1f(x);

  if ((!isfinite(z) || z == -1.0f) && isfinite(x) && _LIB_VERSION != _IEEE_)
    return __kernel_standard_f(x, x, z, signbit(x) ? KMATHERRF_EXPM1_UNDERFLOW
                                                   : KMATHERRF_EXPM1_OVERFLOW);

  float temp_var_for_ext_1;
  temp_var_for_ext_1 = z;
  AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&z,
          "/home/shijia/Public/testprogram/s_expm1f.c_e.c:158:22");
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

__typeof(__expm1f) expm1f __attribute__((weak, alias("__expm1f")));
