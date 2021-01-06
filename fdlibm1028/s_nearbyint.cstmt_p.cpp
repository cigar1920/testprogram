#include "../ScDebug/scdebug.h"
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

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

/*
 * nearbyint(x)
 * Return x rounded to integral value according to the prevailing
 * rounding mode.
 * Method:
 *	Using floating addition.
 * Exception:
 *	none
 */

double __nearbyint(double x) {
  fenv_t env;
  double value;

  feholdexcept(&env);
  value = __ieee754_rint(x);
  double temp_var_for_const_0;AssignD({(Addr)&value},(Addr)&(temp_var_for_const_0=__ieee754_rint(getFVbyShadow<int>((Addr)&x)),"/home/shijia/Public/testprogram/s_nearbyint.c_e.c:32:9");
  fesetenv(&env);
  double temp_var_for_ext_0;
  temp_var_for_ext_0 = value;AssignD({(Addr)&temp_var_for_ext_0},(Addr)&value,"/home/shijia/Public/testprogram/s_nearbyint.c_e.c:35:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

__typeof(__nearbyint) nearbyint __attribute__((weak, alias("__nearbyint")));
#ifdef __NO_LONG_DOUBLE_MATH
__typeof(nearbyintl) __nearbyintl __attribute__((alias("__nearbyint")));
__typeof(__nearbyintl) nearbyintl __attribute__((weak, alias("__nearbyint")));
#endif
