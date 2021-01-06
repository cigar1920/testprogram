#include "../ScDebug/scdebug.h"
/* e_ynf.c -- float version of e_jn.c.
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

float __ieee754_ynf(int n, float x) {
  int32_t i, hx, ix;
  uint32_t ib;
  int sign;
  float a, b, temp;

  static const float zero = 0.0000000000e+00;

  GET_FLOAT_WORD(hx, x);
  ix = IC(0x7fffffff) & hx;
  /* if Y(n,NaN) is NaN */
  if (FLT_UWORD_IS_NAN(ix))
    return x + x;
  if (FLT_UWORD_IS_ZERO(ix))
    return -HUGE_VALF + x; /* -inf and overflow exception.  */
  if (hx < 0)
    return zero / (zero * x);
  sign = 1;
  if (n < 0) {
    n = -n;
    sign = 1 - ((n & 1) << 1);
  }
  if (n == 0) {
    float temp_var_for_ext_0;
    temp_var_for_ext_0 = (__ieee754_y0f(x));
    float temp_var_for_const_0;AssignF({(Addr)&temp_var_for_ext_0},(Addr)&(temp_var_for_const_0=__ieee754_y0f(getFVbyShadow<int>((Addr)&x)),"/home/shijia/Public/testprogram/e_ynf.c_e.c:44:24");
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  if (n == 1) {
    float temp_var_for_ext_1;
    temp_var_for_ext_1 = (sign * __ieee754_y1f(x));AssignF({(Addr)&temp_var_for_ext_1},(Addr)&sign * __ieee754_y1f(getFVbyShadow<int>((Addr)&x),"/home/shijia/Public/testprogram/e_ynf.c_e.c:52:24");
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }

  if (FLT_UWORD_IS_INFINITE(ix))
    return zero;

  a = __ieee754_y0f(x);
  b = __ieee754_y1f(x);
  float temp_var_for_const_1;AssignF({(Addr)&b},(Addr)&(temp_var_for_const_1=__ieee754_y1f(getFVbyShadow<int>((Addr)&x)),"/home/shijia/Public/testprogram/e_ynf.c_e.c:62:5");
  /* quit if b is -inf */
  GET_FLOAT_WORD(ib, b);
  for (i = 1; i < n && ib != UC(0xff800000); i++) {
    temp = b;
    AssignF({(Addr)&temp}, (Addr)&b,
            "/home/shijia/Public/testprogram/e_ynf.c_e.c:66:10");
    b = ((float)(i + i) / x) * b - a;
    GET_FLOAT_WORD(ib, b);
    a = temp;
    AssignF({(Addr)&a}, (Addr)&temp,
            "/home/shijia/Public/testprogram/e_ynf.c_e.c:69:7");
  }
  if (sign > 0) {
    float temp_var_for_ext_2;
    temp_var_for_ext_2 = b;
    AssignF({(Addr)&temp_var_for_ext_2}, (Addr)&b,
            "/home/shijia/Public/testprogram/e_ynf.c_e.c:73:24");
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  }

  float temp_var_for_ext_3;
  temp_var_for_ext_3 = -b;AssignF({(Addr)&temp_var_for_ext_3},(Addr)&(-(b)),"/home/shijia/Public/testprogram/e_ynf.c_e.c:80:22");
  callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
  callExp++; /*identify the function is  add move tmpShadow*/
  return (0.0 - 3);double temp_var_for_const_2,temp_var_for_const_3;;
double temp_var_for_tac_0 ;computeDSub((Addr)&temp_var_for_tac_0,{(Addr)&(temp_var_for_const_3=0.0),(Addr)&(temp_var_for_const_2=3)},"toString(biExpr->getExprLoc())");
}

/* wrapper yn */
float __ynf(int n, float x) {
  if ((islessequal(x, 0.0F) || isgreater(x, X_TLOSS)) &&
      _LIB_VERSION != _IEEE_) {
    if (x < 0.0F) {
      /* d = zero/(x-x) */
      feraiseexcept(FE_INVALID);
      return __kernel_standard_f(n, x, -HUGE_VALF, KMATHERRF_YN_MINUS);
    } else if (x == 0.0F)
      /* d = -one/(x-x) */
      return __kernel_standard_f(n, x, -HUGE_VALF, KMATHERRF_YN_ZERO);
    else if (_LIB_VERSION != _POSIX_)
      /* yn(n,x>X_TLOSS) */
      return __kernel_standard_f(n, x, 0.0f, KMATHERRF_YN_TLOSS);
  }

  float temp_var_for_ext_4;
  temp_var_for_ext_4 = __ieee754_ynf(n, x);
  float temp_var_for_callexp_0 =
      __ieee754_ynf((n), getFVbyShadow<float>((Addr)&x));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  AssignF({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_callexp_0,
          "/home/shijia/Public/testprogram/e_ynf.c_e.c:103:22");
  callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_4;
}

__typeof(__ynf) ynf __attribute__((weak, alias("__ynf")));
