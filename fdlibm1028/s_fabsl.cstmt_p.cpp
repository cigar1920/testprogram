#include "../ScDebug/scdebug.h"
/* s_fabsl.c -- long double version of s_fabs.c.
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

/*
 * fabsl(x) returns the absolute value of x.
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH
long double __fabsl(long double x) {
#ifdef __mc68000__
  ieee_long_double_shape_type *sh_u = (ieee_long_double_shape_type *)&x;
  sh_u->parts.sign_exponent &= 0x7fff;
#else
  uint32_t exp;

  GET_LDOUBLE_EXP(exp, x);
  SET_LDOUBLE_EXP(x, exp & 0x7fff);
#endif
  long double temp_var_for_ext_0;
  temp_var_for_ext_0 = x;
  AssignLd({(Addr)&temp_var_for_ext_0}, (Addr)&x,
           "/home/shijia/Public/testprogram/s_fabsl.c_e.c:35:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

__typeof(__fabsl) fabsl __attribute__((weak, alias("__fabsl")));

#endif
