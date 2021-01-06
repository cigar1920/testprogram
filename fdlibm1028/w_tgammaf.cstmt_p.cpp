#include "../ScDebug/scdebug.h"
/* w_gammaf.c -- float version of w_gamma.c.
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

float __tgammaf(float x) {
  int local_signgam;
  float y = __ieee754_tgammaf_r(x, &local_signgam);

  if (!isfinite(y) && (isfinite(x) || isinf(x) < 0) && _LIB_VERSION != _IEEE_) {
    if (x == 0.0F)
      return __kernel_standard_f(x, x, y,
                                 KMATHERRF_TGAMMA_ZERO); /* tgammaf pole */
    else if (__ieee754_floorf(x) == x && x < 0.0f)
      return __kernel_standard_f(x, x, y,
                                 KMATHERRF_TGAMMA_MINUS); /* tgammaf domain */
    else if (y == 0)
      return __kernel_standard_f(
          x, x, y, KMATHERRF_TGAMMA_UNDERFLOW); /* tgamma underflow */
    else
      return __kernel_standard_f(
          x, x, y, KMATHERRF_TGAMMA_OVERFLOW); /* tgammaf overflow */
  }
  float temp_var_for_ext_0;
  temp_var_for_ext_0 = local_signgam < 0 ? -y : y;
  float temp_var_for_const_0;
  AssignF({(Addr)&temp_var_for_ext_0},
          (Addr) &(temp_var_for_const_0 = local_signgam < 0 ? -y : y),
          "/home/shijia/Public/testprogram/w_tgammaf.c_e.c:39:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for(0.0 - e) xt_0;
}

__typeof(__tgammaf) tgammaf __attribute__((weak, alias("__tgammaf")));
