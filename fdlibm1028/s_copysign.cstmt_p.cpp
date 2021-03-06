#include "../ScDebug/scdebug.h"
/* @(#)s_copysign.c 1.3 95/01/18 */
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
 * copysign(double x, double y)
 * copysign(x,y) returns a value with the magnitude of x and
 * with the sign bit of y.
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

double __copysign(double x, double y) {
  uint32_t hx, hy;

  GET_HIGH_WORD(hx, x);
  GET_HIGH_WORD(hy, y);
  SET_HIGH_WORD(x, (hx & UC(0x7fffffff)) | (hy & UC(0x80000000)));
  double temp_var_for_ext_0;
  temp_var_for_ext_0 = x;
  AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&x,
          "/home/shijia/Public/testprogram/s_copysign.c_e.c:30:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

__typeof(__copysign) copysign __attribute__((weak, alias("__copysign")));
#ifdef __NO_LONG_DOUBLE_MATH
__typeof(__copysignl) __copysignl __attribute__((alias("__copysign")));
__typeof(__copysignl) copysignl __attribute__((weak, alias("__copysign")));
#endif
