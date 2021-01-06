#include "../ScDebug/scdebug.h"
/* @(#)e_lgamma.c 1.3 95/01/18 */
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

/* __ieee754_lgamma(x)
 * Return the logarithm of the Gamma function of x.
 *
 * Method: call __ieee754_lgamma_r
 */

#include "fdlibm.h"

double __ieee754_lgamma(double x) {
  double temp_var_for_ext_0;
  double temp_var_for_const_0;
  double temp_var_for_callexp_0;

  temp_var_for_callexp_0 = __ieee754_lgamma_r(x, (&(signgam)));
  temp_var_for_ext_0 = temp_var_for_callexp_0;
  AssignD({(Addr)&temp_var_for_ext_0},
          (Addr) &(temp_var_for_const_0 = temp_var_for_callexp_0),
          "/home/shijia/Public/testprogram/e_lgamma.c_e.c:24:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}
