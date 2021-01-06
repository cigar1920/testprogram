#include "../ScDebug/scdebug.h"
/* e_y0f.c -- float version of e_y0.c.
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

float __ieee754_y0f(float x) {
  float z, s, c, ss, cc, u, v;
  int32_t hx, ix;

  static const float one = 1.0;
  static const float invsqrtpi = 5.6418961287e-01; /* 0x3f106ebb */
  static const float tpi = 6.3661974669e-01;       /* 0x3f22f983 */
  static const float zero = 0.0;

  static const float u00 = (0.0 - 7.3804296553e-02);
  double temp_var_for_const_0, temp_var_for_const_1;
  ;                                          /* 0xbd9726b5 */
  static const float u01 = 1.7666645348e-01; /* 0x3e34e80d */
  static const float u02 = (0.0 - 1.3818567619e-02);
  double temp_var_for_const_2, temp_var_for_const_3;
  double temp_var_for_tac_0;
  computeDSub((Addr)&temp_var_for_tac_0,
              {(Addr) &(temp_var_for_const_1 = 0.0),
               (Addr) &(temp_var_for_const_0 = 7.3804296553e-02)},
              "/home/shijia/Public/testprogram/e_y0f.c_e.c:31:33");
  ;                                          /* 0xbc626746 */
  static const float u03 = 3.4745343146e-04; /* 0x39b62a69 */
  static const float u04 = (0.0 - 3.8140706238e-06);
  double temp_var_for_const_4, temp_var_for_const_5;
  double temp_var_for_tac_1;
  computeDSub((Addr)&temp_var_for_tac_1,
              {(Addr) &(temp_var_for_const_3 = 0.0),
               (Addr) &(temp_var_for_const_2 = 1.3818567619e-02)},
              "/home/shijia/Public/testprogram/e_y0f.c_e.c:33:33");
  ;                                          /* 0xb67ff53c */
  static const float u05 = 1.9559013964e-08; /* 0x32a802ba */
  static const float u06 = (0.0 - 3.9820518410e-11);
  double temp_var_for_const_6, temp_var_for_const_7;
  double temp_var_for_tac_2;
  computeDSub((Addr)&temp_var_for_tac_2,
              {(Addr) &(temp_var_for_const_5 = 0.0),
               (Addr) &(temp_var_for_const_4 = 3.8140706238e-06)},
              "/home/shijia/Public/testprogram/e_y0f.c_e.c:35:33");
  ;                                          /* 0xae2f21eb */
  static const float v01 = 1.2730483897e-02; /* 0x3c509385 */
  static const float v02 = 7.6006865129e-05; /* 0x389f65e0 */
  static const float v03 = 2.5915085189e-07; /* 0x348b216c */
  static const float v04 = 4.4111031494e-10; /* 0x2ff280c2 */

  GET_FLOAT_WORD(hx, x);
  ix = IC(0x7fffffff) & hx;
  /* Y0(NaN) is NaN, y0(-inf) is Nan, y0(inf) is 0, y0(0) is -inf.  */
  if (!FLT_UWORD_IS_FINITE(ix))
    return one / (x + x * x);
  if (FLT_UWORD_IS_ZERO(ix))
    return -HUGE_VALF + x; /* -inf and overflow exception.  */
  if (hx < 0)
    return zero / (zero * x);
  if (ix >= IC(0x40000000)) { /* |x| >= 2.0 */
    /* y0(x) = sqrt(2/(pi*x))*(p0(x)*sin(x0)+q0(x)*cos(x0))
     * where x0 = x-pi/4
     *      Better formula:
     *              cos(x0) = cos(x)cos(pi/4)+sin(x)sin(pi/4)
     *                      =  1/sqrt(2) * (sin(x) + cos(x))
     *              sin(x0) = sin(x)cos(3pi/4)-cos(x)sin(3pi/4)
     *                      =  1/sqrt(2) * (sin(x) - cos(x))
     * To avoid cancellation, use
     *              sin(x) +- cos(x) = -cos(2x)/(sin(x) -+ cos(x))
     * to compute the worse one.
     */
    __ieee754_sincosf(x, &s, &c);
    ss = s - c;
    cc = s + c;
    /*
     * j0(x) = 1/sqrt(pi) * (P(0,x)*cc - Q(0,x)*ss) / sqrt(x)
     * y0(x) = 1/sqrt(pi) * (P(0,x)*ss + Q(0,x)*cc) / sqrt(x)
     */
    if (ix <= FLT_UWORD_HALF_MAX) { /* make sure x+x not overflow */
      z = -__ieee754_cosf(x + x);
      if ((s * c) < zero)
        cc = z / ss;
      else
        ss = z / cc;
    }
    if (ix > IC(0x48000000))
      z = (invsqrtpi * ss) / __ieee754_sqrtf(x);
    else {
      u = __j0_y0_pzerof(x);
      v = __j0_y0_qzerof(x);
      z = invsqrtpi * (u * ss + v * cc) / __ieee754_sqrtf(x);
    }
    return z;
  }
  if (ix <= IC(0x39800000)) { /* x < 2**-13 */
    return (u00 + tpi * __ieee754_logf(x));
  }
  z = x * x;
  float temp_var_for_tac_3;
  computeFSub((Addr)&temp_var_for_tac_3,
              {(Addr) &(temp_var_for_const_7 = 0.0),
               (Addr) &(temp_var_for_const_6 = 3.9820518410e-11)},
              "/home/shijia/Public/testprogram/e_y0f.c_e.c:88:9");
  computeFMul((Addr)&z, {(Addr)&x, (Addr)&x},
              "/home/shijia/Public/testprogram/e_y0f.c_e.c:88:5");
  u = u00 + z * (u01 + z * (u02 + z * (u03 + z * (u04 + z * (u05 + z * u06)))));
  float temp_var_for_const_8, temp_var_for_const_9, temp_var_for_const_10,
      temp_var_for_const_11, temp_var_for_const_12, temp_var_for_const_13,
      temp_var_for_const_14;
  float temp_var_for_tac_4, temp_var_for_tac_5, temp_var_for_tac_6,
      temp_var_for_tac_7, temp_var_for_tac_8, temp_var_for_tac_9,
      temp_var_for_tac_10, temp_var_for_tac_11, temp_var_for_tac_12,
      temp_var_for_tac_13, temp_var_for_tac_14;
  computeFMul((Addr)&temp_var_for_tac_4,
              {(Addr)&z, (Addr) &(temp_var_for_const_8 = u06)},
              "/home/shijia/Public/testprogram/e_y0f.c_e.c:89:66");
  computeFAdd((Addr)&temp_var_for_tac_5,
              {(Addr) &(temp_var_for_const_9 = u05), (Addr)&temp_var_for_tac_4},
              "/home/shijia/Public/testprogram/e_y0f.c_e.c:89:59");
  computeFMul((Addr)&temp_var_for_tac_6, {(Addr)&z, (Addr)&temp_var_for_tac_5},
              "/home/shijia/Public/testprogram/e_y0f.c_e.c:89:55");
  computeFAdd((Addr)&temp_var_for_tac_7, {(Addr) &(temp_var_for_const_10 = u04),
                                          (Addr)&temp_var_for_tac_6},
              "/home/shijia/Public/testprogram/e_y0f.c_e.c:89:48");
  computeFMul((Addr)&temp_var_for_tac_8, {(Addr)&z, (Addr)&temp_var_for_tac_7},
              "/home/shijia/Public/testprogram/e_y0f.c_e.c:89:44");
  computeFAdd((Addr)&temp_var_for_tac_9, {(Addr) &(temp_var_for_const_11 = u03),
                                          (Addr)&temp_var_for_tac_8},
              "/home/shijia/Public/testprogram/e_y0f.c_e.c:89:37");
  computeFMul((Addr)&temp_var_for_tac_10, {(Addr)&z, (Addr)&temp_var_for_tac_9},
              "/home/shijia/Public/testprogram/e_y0f.c_e.c:89:33");
  computeFAdd(
      (Addr)&temp_var_for_tac_11,
      {(Addr) &(temp_var_for_const_12 = u02), (Addr)&temp_var_for_tac_10},
      "/home/shijia/Public/testprogram/e_y0f.c_e.c:89:26");
  computeFMul((Addr)&temp_var_for_tac_12,
              {(Addr)&z, (Addr)&temp_var_for_tac_11},
              "/home/shijia/Public/testprogram/e_y0f.c_e.c:89:22");
  computeFAdd(
      (Addr)&temp_var_for_tac_13,
      {(Addr) &(temp_var_for_const_13 = u01), (Addr)&temp_var_for_tac_12},
      "/home/shijia/Public/testprogram/e_y0f.c_e.c:89:15");
  computeFMul((Addr)&temp_var_for_tac_14,
              {(Addr)&z, (Addr)&temp_var_for_tac_13},
              "/home/shijia/Public/testprogram/e_y0f.c_e.c:89:11");
  computeFAdd((Addr)&u, {(Addr) &(temp_var_for_const_14 = u00),
                         (Addr)&temp_var_for_tac_14},
              "/home/shijia/Public/testprogram/e_y0f.c_e.c:89:5");
  v = one + z * (v01 + z * (v02 + z * (v03 + z * v04)));
  float temp_var_for_const_15, temp_var_for_const_16, temp_var_for_const_17,
      temp_var_for_const_18, temp_var_for_const_19;
  float temp_var_for_tac_15, temp_var_for_tac_16, temp_var_for_tac_17,
      temp_var_for_tac_18, temp_var_for_tac_19, temp_var_for_tac_20,
      temp_var_for_tac_21;
  computeFMul((Addr)&temp_var_for_tac_15,
              {(Addr)&z, (Addr) &(temp_var_for_const_15 = v04)},
              "/home/shijia/Public/testprogram/e_y0f.c_e.c:90:44");
  computeFAdd(
      (Addr)&temp_var_for_tac_16,
      {(Addr) &(temp_var_for_const_16 = v03), (Addr)&temp_var_for_tac_15},
      "/home/shijia/Public/testprogram/e_y0f.c_e.c:90:37");
  computeFMul((Addr)&temp_var_for_tac_17,
              {(Addr)&z, (Addr)&temp_var_for_tac_16},
              "/home/shijia/Public/testprogram/e_y0f.c_e.c:90:33");
  computeFAdd(
      (Addr)&temp_var_for_tac_18,
      {(Addr) &(temp_var_for_const_17 = v02), (Addr)&temp_var_for_tac_17},
      "/home/shijia/Public/testprogram/e_y0f.c_e.c:90:26");
  computeFMul((Addr)&temp_var_for_tac_19,
              {(Addr)&z, (Addr)&temp_var_for_tac_18},
              "/home/shijia/Public/testprogram/e_y0f.c_e.c:90:22");
  computeFAdd(
      (Addr)&temp_var_for_tac_20,
      {(Addr) &(temp_var_for_const_18 = v01), (Addr)&temp_var_for_tac_19},
      "/home/shijia/Public/testprogram/e_y0f.c_e.c:90:15");
  computeFMul((Addr)&temp_var_for_tac_21,
              {(Addr)&z, (Addr)&temp_var_for_tac_20},
              "/home/shijia/Public/testprogram/e_y0f.c_e.c:90:11");
  computeFAdd((Addr)&v, {(Addr) &(temp_var_for_const_19 = one),
                         (Addr)&temp_var_for_tac_21},
              "/home/shijia/Public/testprogram/e_y0f.c_e.c:90:5");
  float temp_var_for_ext_0;
  temp_var_for_ext_0 = (u / v + tpi * (__ieee754_j0f(x) * __ieee754_logf(x)));
  float temp_var_for_const_20;
  float temp_var_for_tac_22, temp_var_for_tac_23;
  computeFDiv((Addr)&temp_var_for_tac_22, {(Addr)&u, (Addr)&v},
              "toString(biExpr->getExprLoc())");
computeFMul((Addr)&temp_var_for_tac_23,{(Addr)&(temp_var_for_const_20=tpi),(Addr)&__ieee754_j0f(getFVbyShadow<int>((Addr)&x) * __ieee754_logf(getFVbyShadow<int>((Addr)&x)},"/home/shijia/Public/testprogram/e_y0f.c_e.c:92:31");
computeFAdd((Addr)&temp_var_for_ext_0,
            {(Addr)&temp_var_for_tac_22, (Addr)&temp_var_for_tac_23},
            "/home/shijia/Public/testprogram/e_y0f.c_e.c:92:22");
callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
callExp++; /*identify the function is  add move tmpShadow*/
return temp_var_for_ext_0;
}

/* wrapper y0 */
float __y0f(float x) {
  if ((islessequal(x, 0.0F) || isgreater(x, X_TLOSS)) &&
      _LIB_VERSION != _IEEE_) {
    if (x < 0.0F) {
      /* d = zero/(x-x) */
      feraiseexcept(FE_INVALID);
      return __kernel_standard_f(x, x, -HUGE_VALF, KMATHERRF_Y0_MINUS);
    } else if (x == 0.0F)
      /* d = -one/(x-x) */
      return __kernel_standard_f(x, x, -HUGE_VALF, KMATHERRF_Y0_ZERO);
    else if (_LIB_VERSION != _POSIX_)
      /* y0(x>X_TLOSS) */
      return __kernel_standard_f(x, x, 0.0f, KMATHERRF_Y0_TLOSS);
  }

  float temp_var_for_ext_1;
  temp_var_for_ext_1 = __ieee754_y0f(x);
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

__typeof(__y0f) y0f __attribute__((weak, alias("__y0f")));
