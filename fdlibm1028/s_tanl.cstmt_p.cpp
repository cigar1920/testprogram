#include "../ScDebug/scdebug.h"
/* s_tanl.c -- long double version of s_tan.c.
 * Conversion to long double by Ulrich Drepper,
 * Cygnus Support, drepper@cygnus.com.
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

/* tanl(x)
 * Return tangent function of x.
 *
 * kernel function:
 *	__kernel_tanl		... tangent function on [-pi/4,pi/4]
 *	__ieee754_rem_pio2l	... argument reduction routine
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

#ifndef __NO_LONG_DOUBLE_MATH

#ifndef __have_fpu_tan

long double __ieee754_tanl(long double x) {
  long double y[2], z = 0.0;
  int32_t n, se;

  /* High word of x. */
  GET_LDOUBLE_EXP(se, x);

  /* |x| ~< pi/4 */
  se &= 0x7fff;
  if (se <= 0x3ffe)
    return __kernel_tanl(x, z, 1);

  /* tan(Inf or NaN) is NaN */
  else if (se == 0x7fff)
    return x - x;

  /* argument reduction needed */
  else {
    n = __ieee754_rem_pio2l(x, y);
    return __kernel_tanl(
        y[0], y[1], (int)(1 - ((n & 1) << 1))); /*   1 -- n even -1 -- n odd */
  }
}

#endif

long double __tanl(long double x) {
  long double ret;

  ret = __ieee754_tanl(x);
  long double temp_var_for_callexp_0 =
      __ieee754_tanl(getFVbyShadow<long double>((Addr)&x));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  AssignLd({(Addr)&ret}, (Addr)&temp_var_for_callexp_0,
           "/home/shijia/Public/testprogram/s_tanl.c_e.c:84:7");
  if (isnan(ret) && isinf(x))
    ret = __kernel_standard_l(x, x, ret, KMATHERRL_TAN_INF);
  long double temp_var_for_ext_0;
  temp_var_for_ext_0 = ret;
  AssignLd({(Addr)&temp_var_for_ext_0}, (Addr)&ret,
           "/home/shijia/Public/testprogram/s_tanl.c_e.c:88:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

__typeof(__tanl) tanl __attribute__((weak, alias("__tanl")));

#endif
