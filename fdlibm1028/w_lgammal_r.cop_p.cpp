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

/* double lgamma(double x)
 * Return the logarithm of the Gamma function of x.
 *
 * Method: call __ieee754_lgammal_r
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

long double __lgammal_r(long double x, int *signgamp) {
  long double y = __ieee754_lgammal_r(x, signgamp);

  if (!isfinite(y) && isfinite(x) && _LIB_VERSION != _IEEE_) {
    long double temp_var_for_ext_0;
    long double temp_var_for_const_0;
    long double temp_var_for_callexp_0;

    temp_var_for_callexp_0 = __kernel_standard_l(
        x, x, y, __ieee754_floorl(x) == x && x <= 0.0
                     ? KMATHERRL_LGAMMA_MINUS /* lgamma pole */
                     : KMATHERRL_LGAMMA_OVERFLOW);
    temp_var_for_ext_0 = temp_var_for_callexp_0;
    AssignLd({(Addr)&temp_var_for_ext_0},
             (Addr) &(temp_var_for_const_0 = temp_var_for_callexp_0),
             "/home/shijia/Public/testprogram/w_lgammal_r.c_e.c:30:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }
  /* lgamma overflow */

  long double temp_var_for_ext_1;
  temp_var_for_ext_1 = y;
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

__typeof(__lgammal_r) lgammal_r __attribute__((weak, alias("__lgammal_r")));

#endif
