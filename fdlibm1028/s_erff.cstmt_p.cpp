#include "../ScDebug/scdebug.h"
/* s_erff.c -- float version of s_erf.c.
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

float __erff(float x) {
  int32_t hx, ix, i;
  float R, S, P, Q, s, y, z, r;

  static const float tiny = 1e-30;
  static const float one = 1.0000000000e+00; /* 0x3F800000 */
  /* c = (subfloat)0.84506291151 */
  static const float erx = 8.4506291151e-01;  /* 0x3f58560b */
  static const float efx = 1.2837916613e-01;  /* 0x3e0375d4 */
  static const float efx8 = 1.0270333290e+00; /* 0x3f8375d4 */

#include "t_erff.h"

  GET_FLOAT_WORD(hx, x);
  ix = hx & IC(0x7fffffff);
  if (!FLT_UWORD_IS_FINITE(ix)) { /* erf(nan)=nan */
    i = ((uint32_t)hx >> 31) << 1;
    return (float)(1 - i) + one / x; /* erf(+-inf)=+-1 */
  }

  if (ix < IC(0x3f580000)) {   /* |x|<0.84375 */
    if (ix < IC(0x31800000)) { /* |x|<2**-28 */
      if (ix < IC(0x04000000))
        /*avoid underflow */
        return 0.125f * (8.0f * x + efx8 * x);

      return x + efx * x;
    }
    z = x * x;
    r = pp0 + z * (pp1 + z * (pp2 + z * (pp3 + z * pp4)));
    s = one + z * (qq1 + z * (qq2 + z * (qq3 + z * (qq4 + z * qq5))));
    y = r / s;
    return x + x * y;
  }
  if (ix < IC(0x3fa00000)) { /* 0.84375 <= |x| < 1.25 */
    s = __ieee754_fabsf(x) - one;
    P = pa0 +
        s * (pa1 + s * (pa2 + s * (pa3 + s * (pa4 + s * (pa5 + s * pa6)))));
    Q = one +
        s * (qa1 + s * (qa2 + s * (qa3 + s * (qa4 + s * (qa5 + s * qa6)))));
    if (hx >= 0)
      return erx + P / Q;
    else
      return -erx - P / Q;
  }
  if (ix >= IC(0x40c00000)) { /* inf>|x|>=6 */
    if (hx >= 0)
      return one - tiny;
    else
      return tiny - one;
  }
  float temp_var_for_ext_0;
  temp_var_for_ext_0 = __ieee754_fabsf(x);
  float temp_var_for_const_0;AssignF({(Addr)&temp_var_for_ext_0},(Addr)&(temp_var_for_const_0=__ieee754_fabsf(getFVbyShadow<int>((Addr)&x)),"/home/shijia/Public/testprogram/s_erff.c_e.c:72:22"); // x
  /*(__ieee754_fabsf(x))*/
  x = temp_var_for_ext_0;AssignF({(Addr)&x},(Addr)&temp_var_for_ext_0,"/home/shijia/Public/testprogram/s_erff.c_e.c:74:5");
  s = one / (x * x);float temp_var_for_const_1;float temp_var_for_tac_0;computeFMul((Addr)&temp_var_for_tac_0,{(Addr)&x,(Addr)&x},"/home/shijia/Public/testprogram/s_erff.c_e.c:75:11");computeFDiv((Addr)&s,{(Addr)&(temp_var_for_const_1=one),(Addr)&temp_var_for_tac_0},"/home/shijia/Public/testprogram/s_erff.c_e.c:75:5");
  if (ix < IC(0x4036DB6E)) { /* |x| < 1/0.35 */
    R = ra0 +
        s * (ra1 +
             s * (ra2 +
                  s * (ra3 + s * (ra4 + s * (ra5 + s * (ra6 + s * ra7))))));
    S = one +
        s * (sa1 +
             s * (sa2 +
                  s * (sa3 +
                       s * (sa4 +
                            s * (sa5 + s * (sa6 + s * (sa7 + s * sa8)))))));
  } else { /* |x| >= 1/0.35 */
    R = rb0 +
        s * (rb1 + s * (rb2 + s * (rb3 + s * (rb4 + s * (rb5 + s * rb6)))));
    S = one +
        s * (sb1 +
             s * (sb2 +
                  s * (sb3 + s * (sb4 + s * (sb5 + s * (sb6 + s * sb7))))));
  }
  GET_FLOAT_WORD(ix, x);
  SET_FLOAT_WORD(z, ix & UC(0xfffff000));
  r = __ieee754_expf((0.0 - z) * z - 0.5625f) *
      __ieee754_expf((z - x) * (z + x) + R / S);float temp_var_for_const_2,temp_var_for_const_3;float temp_var_for_tac_1,temp_var_for_tac_2,temp_var_for_tac_3,temp_var_for_tac_4,temp_var_for_tac_5,temp_var_for_tac_6,temp_var_for_tac_7,temp_var_for_tac_8;computeDSub((Addr)&temp_var_for_tac_3,{(Addr)&temp_var_for_tac_2,(Addr)&(temp_var_for_const_3=0.5625f)},"toString(biExpr->getExprLoc())");
computeFAdd((Addr)&temp_var_for_tac_8,{(Addr)&temp_var_for_tac_6,(Addr)&temp_var_for_tac_7},"toString(biExpr->getExprLoc())");
computeDSub((Addr)&temp_var_for_tac_1,{(Addr)&(temp_var_for_const_2=0.0),(Addr)&z},"/home/shijia/Public/testprogram/s_erff.c_e.c:97:32");computeDMul((Addr)&temp_var_for_tac_2,{(Addr)&temp_var_for_tac_1,(Addr)&z},"/home/shijia/Public/testprogram/s_erff.c_e.c:97:36");computeFSub((Addr)&temp_var_for_tac_4,{(Addr)&z,(Addr)&x},"/home/shijia/Public/testprogram/s_erff.c_e.c:98:35");computeFAdd((Addr)&temp_var_for_tac_5,{(Addr)&z,(Addr)&x},"/home/shijia/Public/testprogram/s_erff.c_e.c:98:30");computeFMul((Addr)&temp_var_for_tac_6,{(Addr)&temp_var_for_tac_4,(Addr)&temp_var_for_tac_5},"/home/shijia/Public/testprogram/s_erff.c_e.c:98:44");computeFDiv((Addr)&temp_var_for_tac_7,{(Addr)&R,(Addr)&S},"/home/shijia/Public/testprogram/s_erff.c_e.c:98:40");AssignF({(Addr)&r},(Addr)&__ieee754_expf(getFVbyShadow<int>((Addr)&temp_var_for_tac_3) * __ieee754_expf(getFVbyShadow<int>((Addr)&temp_var_for_tac_8),"/home/shijia/Public/testprogram/s_erff.c_e.c:97:5");
  if (hx >= 0)
    return one - r / x;
  float temp_var_for_ext_1;
  temp_var_for_ext_1 = r / x - one;float temp_var_for_const_4;float temp_var_for_tac_9;computeFDiv((Addr)&temp_var_for_tac_9,{(Addr)&r,(Addr)&x},"/home/shijia/Public/testprogram/s_erff.c_e.c:102:30");
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
float temp_var_for_tac_10 ;computeFSub((Addr)&temp_var_for_tac_10,{(Addr)&temp_var_for_tac_9,(Addr)&(temp_var_for_const_4=one)},"toString(biExpr->getExprLoc())");
}

__typeof(__erff) erff __attribute__((weak, alias("__erff")));
