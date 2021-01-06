#include "../ScDebug/scdebug.h"
/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 *
 */

/* float gammaf_r(float x, int *signgamp)
 * Return the logarithm of the Gamma function of x.
 *
 * Method: call __ieee754_gammaf_r
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

float __gammaf_r(float x, int *signgamp) {
  float y = __ieee754_lgammaf_r(x, signgamp);

  if (!isfinite(y) && isfinite(x) && _LIB_VERSION != _IEEE_)
    return __kernel_standard_f(
        x, x, y, __ieee754_floorf(x) == x && x <= 0.0F
                     ? KMATHERRF_LGAMMA_MINUS      /* lgamma pole */
                     : KMATHERRF_LGAMMA_OVERFLOW); /* lgamma overflow */

  float temp_var_for_ext_0;
  temp_var_for_ext_0 = y;
  AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&y,
          "/home/shijia/Public/testprogram/w_gammaf_r.c_e.c:33:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

__typeof(__gammaf_r) gammaf_r __attribute__((weak, alias("__gammaf_r")));
