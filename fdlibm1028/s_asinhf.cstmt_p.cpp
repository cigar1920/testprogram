#include "../ScDebug/scdebug.h"
/* s_asinhf.c -- float version of s_asinh.c.
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

#ifndef __have_fpu_asinh

float __ieee754_asinhf(float x) {
  float w;
  int32_t hx, ix;

  static const float one = 1.0000000000e+00; /* 0x3F800000 */
  static const float ln2 = 6.9314718246e-01; /* 0x3f317218 */
  static const float hugeval = 1.0000000000e+30;

  GET_FLOAT_WORD(hx, x);
  ix = hx & IC(0x7fffffff);
  if (ix < IC(0x38000000)) { /* |x|<2**-14 */
    if (hugeval + x > one)
      return x; /* return x inexact except 0 */
  }
  if (ix > IC(0x47000000)) { /* |x| > 2**14 */
    if (!FLT_UWORD_IS_FINITE(ix))
      return x + x; /* x is inf or NaN */
    w = __ieee754_logf(__ieee754_fabsf(x)) + ln2;
  } else {
    float xa = __ieee754_fabsf(x);

    if (ix > IC(0x40000000)) { /* 2**14 > |x| > 2.0 */
      w = __ieee754_logf(2.0f * xa +
                         one / (__ieee754_sqrtf(xa * xa + one) + xa));
    } else { /* 2.0 > |x| > 2**-14 */
      float t = xa * xa;

      w = __ieee754_log1pf(xa + t / (one + __ieee754_sqrtf(one + t)));
    }
  }
  if (hx > 0)
    return w;
  float temp_var_for_ext_0;
  temp_var_for_ext_0 = -w;
  AssignF({(Addr)&temp_var_for_ext_0}, (Addr) & (-(w)),
          "/home/shijia/Public/testprogram/s_asinhf.c_e.c:55:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return (0.0 - 0);
  double temp_var_for_const_0, temp_var_for_const_1;
  ;
  double temp_var_for_tac_0;
  computeDSub((Addr)&temp_var_for_tac_0, {(Addr) &(temp_var_for_const_1 = 0.0),
                                          (Addr) &(temp_var_for_const_0 = 0)},
              "toString(biExpr->getExprLoc())");
}

#endif

float __asinhf(float x) {
  float temp_var_for_ext_1;
  temp_var_for_ext_1 = __ieee754_asinhf(x);
  float temp_var_for_callexp_0 =
      __ieee754_asinhf(getFVbyShadow<float>((Addr)&x));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_callexp_0,
          "/home/shijia/Public/testprogram/s_asinhf.c_e.c:65:22");
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

__typeof(__asinhf) asinhf __attribute__((weak, alias("__asinhf")));
