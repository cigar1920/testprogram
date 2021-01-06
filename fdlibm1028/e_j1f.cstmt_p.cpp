#include "../ScDebug/scdebug.h"
/* e_j1f.c -- float version of e_j1.c.
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

float __ieee754_j1f(float x) {
  float z, s, c, ss, cc, r, u, v, y;
  int32_t hx, ix;

  static const float hugeval = 1e30;
  static const float one = 1.0;
  static const float invsqrtpi = 5.6418961287e-01; /* 0x3f106ebb */
  static const float zero = 0.0;

  /* R0/S0 on [0,2] */
  static const float r00 = (0.0 - 6.2500000000e-02);
  double temp_var_for_const_0, temp_var_for_const_1;
  ;                                          /* 0xbd800000 */
  static const float r01 = 1.4070566976e-03; /* 0x3ab86cfd */
  static const float r02 = (0.0 - 1.5995563444e-05);
  double temp_var_for_const_2, temp_var_for_const_3;
  double temp_var_for_tac_0;
  computeDSub((Addr)&temp_var_for_tac_0,
              {(Addr) &(temp_var_for_const_1 = 0.0),
               (Addr) &(temp_var_for_const_0 = 6.2500000000e-02)},
              "/home/shijia/Public/testprogram/e_j1f.c_e.c:32:33");
  ;                                          /* 0xb7862e36 */
  static const float r03 = 4.9672799207e-08; /* 0x335557d2 */
  static const float s01 = 1.9153760746e-02; /* 0x3c9ce859 */
  static const float s02 = 1.8594678841e-04; /* 0x3942fab6 */
  static const float s03 = 1.1771846857e-06; /* 0x359dffc2 */
  static const float s04 = 5.0463624390e-09; /* 0x31ad6446 */
  static const float s05 = 1.2354227016e-11; /* 0x2d59567e */

  GET_FLOAT_WORD(hx, x);
  ix = hx & IC(0x7fffffff);
  if (!FLT_UWORD_IS_FINITE(ix))
    return one / x;
  y = __ieee754_fabsf(x);
  float temp_var_for_const_4;
  float temp_var_for_tac_1;
  computeDSub((Addr)&temp_var_for_tac_1,
              {(Addr) &(temp_var_for_const_3 = 0.0),
               (Addr) &(temp_var_for_const_2 = 1.5995563444e-05)},
              "toString(biExpr->getExprLoc())");
AssignF({(Addr)&y},(Addr)&(temp_var_for_const_4=__ieee754_fabsf(getFVbyShadow<int>((Addr)&x)),"/home/shijia/Public/testprogram/e_j1f.c_e.c:44:5");
  if (ix >= IC(0x40000000)) { /* |x| >= 2.0 */
    __ieee754_sincosf(y, &s, &c);
    ss = -s - c;
    cc = s - c;
    if (ix <= FLT_UWORD_HALF_MAX) { /* make sure y+y not overflow */
      z = __ieee754_cosf(y + y);
      if ((s * c) > zero)
        cc = z / ss;
      else
        ss = z / cc;
    }
    /*
     * j1(x) = 1/sqrt(pi) * (P(1,x)*cc - Q(1,x)*ss) / sqrt(x)
     * y1(x) = 1/sqrt(pi) * (P(1,x)*ss + Q(1,x)*cc) / sqrt(x)
     */
    if (ix > IC(0x48000000))
      z = (invsqrtpi * cc) / __ieee754_sqrtf(y);
    else {
      u = __j1_y1_ponef(y);
      v = __j1_y1_qonef(y);
      z = invsqrtpi * (u * cc - v * ss) / __ieee754_sqrtf(y);
    }
    if (hx < 0)
      return -z;
    else
      return z;
  }
  if (ix < IC(0x32000000)) { /* |x|<2**-27 */
    if (hugeval + x > one)
      return 0.5f * x; /* inexact if x!=0 necessary */
  }
  z = x * x;computeFMul((Addr)&z,{(Addr)&x,(Addr)&x},"/home/shijia/Public/testprogram/e_j1f.c_e.c:76:5");
  r = z * (r00 + z * (r01 + z * (r02 + z * r03)));float temp_var_for_const_5,temp_var_for_const_6,temp_var_for_const_7,temp_var_for_const_8;float temp_var_for_tac_2,temp_var_for_tac_3,temp_var_for_tac_4,temp_var_for_tac_5,temp_var_for_tac_6,temp_var_for_tac_7;computeFMul((Addr)&temp_var_for_tac_2,{(Addr)&z,(Addr)&(temp_var_for_const_5=r03)},"/home/shijia/Public/testprogram/e_j1f.c_e.c:77:38");computeFAdd((Addr)&temp_var_for_tac_3,{(Addr)&(temp_var_for_const_6=r02),(Addr)&temp_var_for_tac_2},"/home/shijia/Public/testprogram/e_j1f.c_e.c:77:31");computeFMul((Addr)&temp_var_for_tac_4,{(Addr)&z,(Addr)&temp_var_for_tac_3},"/home/shijia/Public/testprogram/e_j1f.c_e.c:77:27");computeFAdd((Addr)&temp_var_for_tac_5,{(Addr)&(temp_var_for_const_7=r01),(Addr)&temp_var_for_tac_4},"/home/shijia/Public/testprogram/e_j1f.c_e.c:77:20");computeFMul((Addr)&temp_var_for_tac_6,{(Addr)&z,(Addr)&temp_var_for_tac_5},"/home/shijia/Public/testprogram/e_j1f.c_e.c:77:16");computeFAdd((Addr)&temp_var_for_tac_7,{(Addr)&(temp_var_for_const_8=r00),(Addr)&temp_var_for_tac_6},"/home/shijia/Public/testprogram/e_j1f.c_e.c:77:9");computeFMul((Addr)&r,{(Addr)&z,(Addr)&temp_var_for_tac_7},"/home/shijia/Public/testprogram/e_j1f.c_e.c:77:5");
  s = one + z * (s01 + z * (s02 + z * (s03 + z * (s04 + z * s05))));float temp_var_for_const_9,temp_var_for_const_10,temp_var_for_const_11,temp_var_for_const_12,temp_var_for_const_13,temp_var_for_const_14;float temp_var_for_tac_8,temp_var_for_tac_9,temp_var_for_tac_10,temp_var_for_tac_11,temp_var_for_tac_12,temp_var_for_tac_13,temp_var_for_tac_14,temp_var_for_tac_15,temp_var_for_tac_16;computeFMul((Addr)&temp_var_for_tac_8,{(Addr)&z,(Addr)&(temp_var_for_const_9=s05)},"/home/shijia/Public/testprogram/e_j1f.c_e.c:78:55");computeFAdd((Addr)&temp_var_for_tac_9,{(Addr)&(temp_var_for_const_10=s04),(Addr)&temp_var_for_tac_8},"/home/shijia/Public/testprogram/e_j1f.c_e.c:78:48");computeFMul((Addr)&temp_var_for_tac_10,{(Addr)&z,(Addr)&temp_var_for_tac_9},"/home/shijia/Public/testprogram/e_j1f.c_e.c:78:44");computeFAdd((Addr)&temp_var_for_tac_11,{(Addr)&(temp_var_for_const_11=s03),(Addr)&temp_var_for_tac_10},"/home/shijia/Public/testprogram/e_j1f.c_e.c:78:37");computeFMul((Addr)&temp_var_for_tac_12,{(Addr)&z,(Addr)&temp_var_for_tac_11},"/home/shijia/Public/testprogram/e_j1f.c_e.c:78:33");computeFAdd((Addr)&temp_var_for_tac_13,{(Addr)&(temp_var_for_const_12=s02),(Addr)&temp_var_for_tac_12},"/home/shijia/Public/testprogram/e_j1f.c_e.c:78:26");computeFMul((Addr)&temp_var_for_tac_14,{(Addr)&z,(Addr)&temp_var_for_tac_13},"/home/shijia/Public/testprogram/e_j1f.c_e.c:78:22");computeFAdd((Addr)&temp_var_for_tac_15,{(Addr)&(temp_var_for_const_13=s01),(Addr)&temp_var_for_tac_14},"/home/shijia/Public/testprogram/e_j1f.c_e.c:78:15");computeFMul((Addr)&temp_var_for_tac_16,{(Addr)&z,(Addr)&temp_var_for_tac_15},"/home/shijia/Public/testprogram/e_j1f.c_e.c:78:11");computeFAdd((Addr)&s,{(Addr)&(temp_var_for_const_14=one),(Addr)&temp_var_for_tac_16},"/home/shijia/Public/testprogram/e_j1f.c_e.c:78:5");
  r *= x;
  float temp_var_for_ext_0;
  temp_var_for_ext_0 = (x * 0.5f + r / s);float temp_var_for_const_15;float temp_var_for_tac_17,temp_var_for_tac_18;computeFMul((Addr)&temp_var_for_tac_17,{(Addr)&x,(Addr)&(temp_var_for_const_15=0.5f)},"/home/shijia/Public/testprogram/e_j1f.c_e.c:81:38");computeFDiv((Addr)&temp_var_for_tac_18,{(Addr)&r,(Addr)&s},"/home/shijia/Public/testprogram/e_j1f.c_e.c:81:34");computeFAdd((Addr)&temp_var_for_ext_0,{(Addr)&temp_var_for_tac_17,(Addr)&temp_var_for_tac_18},"/home/shijia/Public/testprogram/e_j1f.c_e.c:81:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

/* wrapper j1 */
float __j1f(float x) {
  if (isgreater(__ieee754_fabsf(x), X_TLOSS) && _LIB_VERSION != _IEEE_ &&
      _LIB_VERSION != _POSIX_)
    /* j1(|x|>X_TLOSS) */
    return __kernel_standard_f(x, x, 0.0f, KMATHERRF_J1_TLOSS);

  float temp_var_for_ext_1;
  temp_var_for_ext_1 = __ieee754_j1f(x);
  float temp_var_for_callexp_0 = __ieee754_j1f(getFVbyShadow<float>((Addr)&x));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_callexp_0,
          "/home/shijia/Public/testprogram/e_j1f.c_e.c:95:22");
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

__typeof(__j1f) j1f __attribute__((weak, alias("__j1f")));
