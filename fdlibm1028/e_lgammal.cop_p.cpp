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

/* __ieee754_lgammal(x)
 * Return the logarithm of the Gamma function of x.
 *
 * Method: call __ieee754_lgamma_r
 */

#include "fdlibm.h"

long double __ieee754_lgamma(long double x) {
  long double temp_var_for_ext_0;
  long double temp_var_for_const_0;
  long double temp_var_for_callexp_0;

  temp_var_for_callexp_0 = __ieee754_lgammal_r(x, (&(signgam)));
  temp_var_for_ext_0 = temp_var_for_callexp_0;
  AssignLd({(Addr)&temp_var_for_ext_0},
           (Addr) &(temp_var_for_const_0 = temp_var_for_callexp_0),
           "/home/shijia/Public/testprogram/e_lgammal.c_e.c:24:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}
