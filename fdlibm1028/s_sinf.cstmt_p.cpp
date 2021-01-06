#include "../ScDebug/scdebug.h"
/* sf_sin.c -- float version of s_sin.c.
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

#ifndef __have_fpu_sin

float __ieee754_sinf(float x) {
  float y[2], z = 0.0;
  int32_t n, ix;

  GET_FLOAT_WORD(ix, x);

  /* |x| ~< pi/4 */
  ix &= IC(0x7fffffff);
  if (ix <= IC(0x3f490fd8))
    return __kernel_sinf(x, z, 0);

  /* sin(Inf or NaN) is NaN */
  else if (!FLT_UWORD_IS_FINITE(ix))
    return x - x;

  /* argument reduction needed */
  else {
    n = __ieee754_rem_pio2f(x, y);
    switch ((int)(n & 3)) {
    case 0:
      return __kernel_sinf(y[0], y[1], 1);
    case 1:
      return __kernel_cosf(y[0], y[1]);
    case 2:
      return -__kernel_sinf(y[0], y[1], 1);
    default:
      return -__kernel_cosf(y[0], y[1]);
    }
  }
}

#endif

float __sinf(float x) {
  float ret;

  ret = __ieee754_sinf(x);
  float temp_var_for_callexp_0 = __ieee754_sinf(getFVbyShadow<float>((Addr)&x));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  AssignF({(Addr)&ret}, (Addr)&temp_var_for_callexp_0,
          "/home/shijia/Public/testprogram/s_sinf.c_e.c:58:7");
  if (isnan(ret) && !isnan(x))
    ret = __kernel_standard_f(x, x, ret, KMATHERRF_SIN_INF);
  float temp_var_for_ext_0;
  temp_var_for_ext_0 = ret;
  AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&ret,
          "/home/shijia/Public/testprogram/s_sinf.c_e.c:62:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

__typeof(__sinf) sinf __attribute__((weak, alias("__sinf")));
