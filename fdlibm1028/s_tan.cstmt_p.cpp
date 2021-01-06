#include "../ScDebug/scdebug.h"
/* @(#)s_tan.c 1.3 95/01/18 */
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

/* tan(x)
 * Return tangent function of x.
 *
 * kernel function:
 *	__kernel_tan		... tangent function on [-pi/4,pi/4]
 *	__ieee754_rem_pio2	... argument reduction routine
 *
 * Method.
 *      Let S,C and T denote the sin, cos and tan respectively on
 *	[-PI/4, +PI/4]. Reduce the argument x to y1+y2 = x-k*pi/2
 *	in [-pi/4 , +pi/4], and let n = k mod 4.
 *	We have
 *
 *          n        sin(x)      cos(x)        tan(x)
 *     ----------------------------------------------------------
 *	    0	       S	   C		 T
 *	    1	       C	  -S		-1/T
 *	    2	      -S	  -C		 T
 *	    3	      -C	   S		-1/T
 *     ----------------------------------------------------------
 *
 * Special cases:
 *      Let trig be any of sin, cos, or tan.
 *      trig(+-INF)  is NaN, with signals;
 *      trig(NaN)    is that NaN;
 *
 * Accuracy:
 *	TRIG(x) returns trig(x) nearly rounded
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_tan

double __ieee754_tan(double x) {
  double y[2], z = 0.0;
  int32_t n, ix;

  /* High word of x. */
  GET_HIGH_WORD(ix, x);

  /* |x| ~< pi/4 */
  ix &= IC(0x7fffffff);
  if (ix <= IC(0x3fe921fb))
    return __kernel_tan(x, z, 1);

  /* tan(Inf or NaN) is NaN */
  else if (ix >= IC(0x7ff00000))
    return x - x; /* NaN */

  /* argument reduction needed */
  else {
    n = __ieee754_rem_pio2(x, y);
    return __kernel_tan(
        y[0], y[1],
        (int)(1 -
              ((n & 1)
               << 1))); /*   1 -- n even
                                                                           -1 --
                           n odd */
  }
}

#endif

double __tan(double x) {
  double ret;

  ret = __ieee754_tan(x);
  double temp_var_for_callexp_0 =
      __ieee754_tan(getFVbyShadow<double>((Addr)&x));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  AssignD({(Addr)&ret}, (Addr)&temp_var_for_callexp_0,
          "/home/shijia/Public/testprogram/s_tan.c_e.c:83:7");
  if (isnan(ret) && isinf(x))
    ret = __kernel_standard(x, x, ret, KMATHERR_TAN_INF);
  double temp_var_for_ext_0;
  temp_var_for_ext_0 = ret;
  AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&ret,
          "/home/shijia/Public/testprogram/s_tan.c_e.c:87:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

__typeof(__tan) tan __attribute__((weak, alias("__tan")));
#ifdef __NO_LONG_DOUBLE_MATH
__typeof(__tanl) __tanl __attribute__((alias("__tan")));
__typeof(__tanl) tanl __attribute__((weak, alias("__tan")));
#endif
