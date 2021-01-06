#include "../ScDebug/scdebug.h"
/* e_j0f.c -- float version of e_j0.c.
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

float __ieee754_j0f(float x) {
  float z, s, c, ss, cc, r, u, v;
  int32_t hx, ix;

  static const float hugeval = 1e30;
  static const float one = 1.0;
  static const float invsqrtpi = 5.6418961287e-01; /* 0x3f106ebb */
  static const float zero = 0.0;

  /* R0/S0 on [0, 2.00] */
  static const float R02 = 1.5625000000e-02; /* 0x3c800000 */
  static const float R03 = (0.0 - 1.8997929874e-04);
  double temp_var_for_const_0, temp_var_for_const_1;
  ;                                          /* 0xb947352e */
  static const float R04 = 1.8295404516e-06; /* 0x35f58e88 */
  static const float R05 = (0.0 - 4.6183270541e-09);
  double temp_var_for_const_2, temp_var_for_const_3;
  double temp_var_for_tac_0;
  computeDSub((Addr)&temp_var_for_tac_0,
              {(Addr) &(temp_var_for_const_1 = 0.0),
               (Addr) &(temp_var_for_const_0 = 1.8997929874e-04)},
              "/home/shijia/Public/testprogram/e_j0f.c_e.c:33:33");
  ;                                          /* 0xb19eaf3c */
  static const float S01 = 1.5619102865e-02; /* 0x3c7fe744 */
  static const float S02 = 1.1692678527e-04; /* 0x38f53697 */
  static const float S03 = 5.1354652442e-07; /* 0x3509daa6 */
  static const float S04 = 1.1661400734e-09; /* 0x30a045e8 */

  GET_FLOAT_WORD(hx, x);
  ix = hx & IC(0x7fffffff);
  if (!FLT_UWORD_IS_FINITE(ix))
    return one / (x * x);
  float temp_var_for_ext_0;
  temp_var_for_ext_0 = __ieee754_fabsf(x);
  float temp_var_for_const_4;
  float temp_var_for_tac_1;
  computeDSub((Addr)&temp_var_for_tac_1,
              {(Addr) &(temp_var_for_const_3 = 0.0),
               (Addr) &(temp_var_for_const_2 = 4.6183270541e-09)},
              "toString(biExpr->getExprLoc())");
AssignF({(Addr)&temp_var_for_ext_0},(Addr)&(temp_var_for_const_4=__ieee754_fabsf(getFVbyShadow<int>((Addr)&x)),"/home/shijia/Public/testprogram/e_j0f.c_e.c:44:22"); // x
  /*(__ieee754_fabsf(x))*/
  x = temp_var_for_ext_0;AssignF({(Addr)&x},(Addr)&temp_var_for_ext_0,"/home/shijia/Public/testprogram/e_j0f.c_e.c:46:5");
  if (ix >= IC(0x40000000)) { /* |x| >= 2.0 */
    __ieee754_sincosf(x, &s, &c);
    ss = s - c;
    cc = s + c;
    if (ix <= FLT_UWORD_HALF_MAX) { /* make sure x+x not overflow */
      z = -__ieee754_cosf(x + x);
      if ((s * c) < zero)
        cc = z / ss;
      else
        ss = z / cc;
    }
    /*
     * j0(x) = 1/sqrt(pi) * (P(0,x)*cc - Q(0,x)*ss) / sqrt(x)
     * y0(x) = 1/sqrt(pi) * (P(0,x)*ss + Q(0,x)*cc) / sqrt(x)
     */
    if (ix > IC(0x48000000))
      z = (invsqrtpi * cc) / __ieee754_sqrtf(x);
    else {
      u = __j0_y0_pzerof(x);
      v = __j0_y0_qzerof(x);
      z = invsqrtpi * (u * cc - v * ss) / __ieee754_sqrtf(x);
    }
    return z;
  }
  if (ix < IC(0x39000000)) {      /* |x| < 2**-13 */
    math_force_eval(hugeval + x); /* raise inexact if x != 0 */
    if (ix < IC(0x32000000))
      return one; /* |x|<2**-27 */
    else
      return one - 0.25f * x * x;
  }
  z = x * x;computeFMul((Addr)&z,{(Addr)&x,(Addr)&x},"/home/shijia/Public/testprogram/e_j0f.c_e.c:78:5");
  r = z * (R02 + z * (R03 + z * (R04 + z * R05)));float temp_var_for_const_5,temp_var_for_const_6,temp_var_for_const_7,temp_var_for_const_8;float temp_var_for_tac_2,temp_var_for_tac_3,temp_var_for_tac_4,temp_var_for_tac_5,temp_var_for_tac_6,temp_var_for_tac_7;computeFMul((Addr)&temp_var_for_tac_2,{(Addr)&z,(Addr)&(temp_var_for_const_5=R05)},"/home/shijia/Public/testprogram/e_j0f.c_e.c:79:38");computeFAdd((Addr)&temp_var_for_tac_3,{(Addr)&(temp_var_for_const_6=R04),(Addr)&temp_var_for_tac_2},"/home/shijia/Public/testprogram/e_j0f.c_e.c:79:31");computeFMul((Addr)&temp_var_for_tac_4,{(Addr)&z,(Addr)&temp_var_for_tac_3},"/home/shijia/Public/testprogram/e_j0f.c_e.c:79:27");computeFAdd((Addr)&temp_var_for_tac_5,{(Addr)&(temp_var_for_const_7=R03),(Addr)&temp_var_for_tac_4},"/home/shijia/Public/testprogram/e_j0f.c_e.c:79:20");computeFMul((Addr)&temp_var_for_tac_6,{(Addr)&z,(Addr)&temp_var_for_tac_5},"/home/shijia/Public/testprogram/e_j0f.c_e.c:79:16");computeFAdd((Addr)&temp_var_for_tac_7,{(Addr)&(temp_var_for_const_8=R02),(Addr)&temp_var_for_tac_6},"/home/shijia/Public/testprogram/e_j0f.c_e.c:79:9");computeFMul((Addr)&r,{(Addr)&z,(Addr)&temp_var_for_tac_7},"/home/shijia/Public/testprogram/e_j0f.c_e.c:79:5");
  s = one + z * (S01 + z * (S02 + z * (S03 + z * S04)));float temp_var_for_const_9,temp_var_for_const_10,temp_var_for_const_11,temp_var_for_const_12,temp_var_for_const_13;float temp_var_for_tac_8,temp_var_for_tac_9,temp_var_for_tac_10,temp_var_for_tac_11,temp_var_for_tac_12,temp_var_for_tac_13,temp_var_for_tac_14;computeFMul((Addr)&temp_var_for_tac_8,{(Addr)&z,(Addr)&(temp_var_for_const_9=S04)},"/home/shijia/Public/testprogram/e_j0f.c_e.c:80:44");computeFAdd((Addr)&temp_var_for_tac_9,{(Addr)&(temp_var_for_const_10=S03),(Addr)&temp_var_for_tac_8},"/home/shijia/Public/testprogram/e_j0f.c_e.c:80:37");computeFMul((Addr)&temp_var_for_tac_10,{(Addr)&z,(Addr)&temp_var_for_tac_9},"/home/shijia/Public/testprogram/e_j0f.c_e.c:80:33");computeFAdd((Addr)&temp_var_for_tac_11,{(Addr)&(temp_var_for_const_11=S02),(Addr)&temp_var_for_tac_10},"/home/shijia/Public/testprogram/e_j0f.c_e.c:80:26");computeFMul((Addr)&temp_var_for_tac_12,{(Addr)&z,(Addr)&temp_var_for_tac_11},"/home/shijia/Public/testprogram/e_j0f.c_e.c:80:22");computeFAdd((Addr)&temp_var_for_tac_13,{(Addr)&(temp_var_for_const_12=S01),(Addr)&temp_var_for_tac_12},"/home/shijia/Public/testprogram/e_j0f.c_e.c:80:15");computeFMul((Addr)&temp_var_for_tac_14,{(Addr)&z,(Addr)&temp_var_for_tac_13},"/home/shijia/Public/testprogram/e_j0f.c_e.c:80:11");computeFAdd((Addr)&s,{(Addr)&(temp_var_for_const_13=one),(Addr)&temp_var_for_tac_14},"/home/shijia/Public/testprogram/e_j0f.c_e.c:80:5");
  if (ix < IC(0x3F800000)) { /* |x| < 1.00 */
    return one + z * (-0.25f + (r / s));
  } else {
    u = 0.5f * x;

    return ((one + u) * (one - u) + z * (r / s));
  }
}

/* wrapper j0 */
float __j0f(float x) {
  if (isgreater(__ieee754_fabsf(x), X_TLOSS) && _LIB_VERSION != _IEEE_ &&
      _LIB_VERSION != _POSIX_)
    /* j0(|x|>X_TLOSS) */
    return __kernel_standard_f(x, x, 0.0f, KMATHERRF_J0_TLOSS);

  float temp_var_for_ext_1;
  temp_var_for_ext_1 = __ieee754_j0f(x);
  float temp_var_for_callexp_0 = __ieee754_j0f(getFVbyShadow<float>((Addr)&x));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_callexp_0,
          "/home/shijia/Public/testprogram/e_j0f.c_e.c:98:22");
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

__typeof(__j0f) j0f __attribute__((weak, alias("__j0f")));
