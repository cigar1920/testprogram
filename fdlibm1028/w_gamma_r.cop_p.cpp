#include "../ScDebug/scdebug.h"
/* @(#)w_gamma_r.c 1.3 95/01/18 */
/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunSoft, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 */

/*
 * wrapper double gamma_r(double x, int *signgamp)
 */

#include "fdlibm.h"

double __gamma_r(double x, int *signgamp) /* wrapper lgamma_r */
{
  double y = __ieee754_lgamma_r(x, signgamp);

  if (_LIB_VERSION != _IEEE_ && !isfinite(y) && isfinite(x)) {
    double temp_var_for_ext_0;
    double temp_var_for_const_0;
    double temp_var_for_callexp_0;

    temp_var_for_callexp_0 =
        __kernel_standard(x, x, y, __ieee754_floor(x) == x && x <= 0.0
                                       ? KMATHERR_LGAMMA_MINUS /* lgamma pole */
                                       : KMATHERR_LGAMMA_OVERFLOW);
    temp_var_for_ext_0 = temp_var_for_callexp_0;
    AssignD({(Addr)&temp_var_for_ext_0},
            (Addr) &(temp_var_for_const_0 = temp_var_for_callexp_0),
            "/home/shijia/Public/testprogram/w_gamma_r.c_e.c:25:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }
  /* lgamma overflow */

  double temp_var_for_ext_1;
  temp_var_for_ext_1 = y;
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

__typeof(__gamma_r) gamma_r __attribute__((weak, alias("__gamma_r")));
#ifdef __NO_LONG_DOUBLE_MATH
__typeof(__gammal_r) __gammal_r __attribute__((alias("__gamma_r")));
__typeof(__gammal_r) gammal_r __attribute__((weak, alias("__gamma_r")));
#endif
