#include "../ScDebug/scdebug.h"
/* @(#)w_lgamma.c 1.3 95/01/18 */
/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunSoft, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 *
 */

/* double lgamma(double x)
 * Return the logarithm of the Gamma function of x.
 *
 * Method: call lgamma_r
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

double __lgamma(double x) {
  double temp_var_for_ext_0;
  double temp_var_for_const_0;
  double temp_var_for_callexp_0;

  temp_var_for_callexp_0 = lgamma_r(x, (&(signgam)));
  temp_var_for_ext_0 = temp_var_for_callexp_0;
  AssignD({(Addr)&temp_var_for_ext_0},
          (Addr) &(temp_var_for_const_0 = temp_var_for_callexp_0),
          "/home/shijia/Public/testprogram/w_lgamma.c_e.c:26:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

__typeof(__lgamma) lgamma __attribute__((weak, alias("__lgamma")));
#ifdef __NO_LONG_DOUBLE_MATH
__typeof(__lgammal) __lgammal __attribute__((alias("__lgamma")));
__typeof(__lgammal) lgammal __attribute__((weak, alias("__lgamma")));
#endif
