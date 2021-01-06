#include "../ScDebug/scdebug.h"
/* s_nearbyintl.c -- long double version of s_nearbyint.c.
 * Conversion to long double by Ulrich Drepper,
 * Cygnus Support, drepper@cygnus.com.
 */
/* Adapted for use as nearbyint by Ulrich Drepper <drepper@cygnus.com>.  */

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

/*
 * nearbyintl(x)
 * Return x rounded to integral value according to the prevailing
 * rounding mode.
 * Method:
 *	Using floating addition.
 * Exception:
 *	none
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

long double __nearbyintl(long double x) {
  fenv_t env;
  long double value;

  feholdexcept(&env);
  value = __ieee754_rintl(x);
  long double temp_var_for_const_0;AssignLd({(Addr)&value},(Addr)&(temp_var_for_const_0=__ieee754_rintl(getFVbyShadow<int>((Addr)&x)),"/home/shijia/Public/testprogram/s_nearbyintl.c_e.c:39:9");
  fesetenv(&env);
  long double temp_var_for_ext_0;
  temp_var_for_ext_0 = value;AssignLd({(Addr)&temp_var_for_ext_0},(Addr)&value,"/home/shijia/Public/testprogram/s_nearbyintl.c_e.c:42:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

__typeof(__nearbyintl) nearbyintl __attribute__((weak, alias("__nearbyintl")));

#endif
