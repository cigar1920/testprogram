#include "../ScDebug/scdebug.h"
/* e_remainderl.c -- long double version of e_remainder.c.
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

/* __ieee754_remainderl(x,p)
 * Return :
 *	returns  x REM p  =  x - [x/p]*p as if in infinite
 *	precise arithmetic, where [x/p] is the (infinite bit)
 *	integer nearest x/p (in half way case choose the even one).
 * Method :
 *	Based on fmod() return x-[x/p]chopped*p exactlp.
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

#ifndef __have_fpu_remainder

long double __ieee754_remainderl(long double x, long double p) {
  uint32_t sx, sex, sep, x0, x1, p0, p1;
  long double p_half;

  static const long double zero = 0.0;

  GET_LDOUBLE_WORDS(sex, x0, x1, x);
  GET_LDOUBLE_WORDS(sep, p0, p1, p);
  sx = sex & IC(0x8000);
  sep &= IEEE854_LONG_DOUBLE_MAXEXP;
  sex &= IEEE854_LONG_DOUBLE_MAXEXP;

  /* purge off exception values */
  if ((sep | p0 | p1) == 0)
    return (x * p) / (x * p);                 /* p = 0 */
  if ((sex == IEEE854_LONG_DOUBLE_MAXEXP) ||  /* x not finite */
      ((sep == IEEE854_LONG_DOUBLE_MAXEXP) && /* p is NaN */
       (((p0 & IC(0x7fffffff)) | p1) != 0)))
    return (x * p) / (x * p);

  if (sep < (IEEE854_LONG_DOUBLE_MAXEXP - 1))
    x = __ieee754_fmodl(x, p + p); /* now x < 2p */
  if (((sex - sep) | ((x0 - p0) & IC(0x7fffffff)) | (x1 - p1)) == 0)
    return zero * x;
  long double temp_var_for_ext_0;
  temp_var_for_ext_0 = __ieee754_fabsl(x);
  long double temp_var_for_const_0;AssignLd({(Addr)&temp_var_for_ext_0},(Addr)&(temp_var_for_const_0=__ieee754_fabsl(getFVbyShadow<int>((Addr)&x)),"/home/shijia/Public/testprogram/e_remainderl.c_e.c:59:22"); // x
  /*(__ieee754_fabsl(x))*/
  x = temp_var_for_ext_0;AssignLd({(Addr)&x},(Addr)&temp_var_for_ext_0,"/home/shijia/Public/testprogram/e_remainderl.c_e.c:61:5");
  long double temp_var_for_ext_1;
  temp_var_for_ext_1 = __ieee754_fabsl(p);long double temp_var_for_const_1;AssignLd({(Addr)&temp_var_for_ext_1},(Addr)&(temp_var_for_const_1=__ieee754_fabsl(getFVbyShadow<int>((Addr)&p)),"/home/shijia/Public/testprogram/e_remainderl.c_e.c:63:22"); // p
  /*(__ieee754_fabsl(p))*/
  p = temp_var_for_ext_1;AssignLd({(Addr)&p},(Addr)&temp_var_for_ext_1,"/home/shijia/Public/testprogram/e_remainderl.c_e.c:65:5");
  if (sep < 0x0002) {
    if (x + x > p) {
      x -= p;
      if (x + x >= p)
        x -= p;
    }
  } else {
    p_half = 0.5L * p;
    if (x > p_half) {
      x -= p;
      if (x >= p_half)
        x -= p;
    }
  }
  GET_LDOUBLE_EXP(sex, x);
  SET_LDOUBLE_EXP(x, sex ^ sx);
  long double temp_var_for_ext_2;
  temp_var_for_ext_2 = x;AssignLd({(Addr)&temp_var_for_ext_2},(Addr)&x,"/home/shijia/Public/testprogram/e_remainderl.c_e.c:83:22");
  callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_2;
}

#endif

/* wrapper remainder */
long double __remainderl(long double x, long double y) {
  if (((y == 0.0 && !isnan(x)) || (isinf(x) && !isnan(y))) &&
      _LIB_VERSION != _IEEE_)
    return __kernel_standard_l(x, y, y,
                               KMATHERRL_REMAINDER); /* remainder domain */

  long double temp_var_for_ext_3;
  temp_var_for_ext_3 = __ieee754_remainderl(x, y);
  long double temp_var_for_callexp_0 =
      __ieee754_remainderl(getFVbyShadow<long double>((Addr)&x),
                           getFVbyShadow<long double>((Addr)&y));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  AssignLd({(Addr)&temp_var_for_ext_3}, ,
           "/home/shijia/Public/testprogram/e_remainderl.c_e.c:99:22");
  callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_3;
}

__typeof(__remainderl) remainderl __attribute__((weak, alias("__remainderl")));
__typeof(__remainderl) __dreml __attribute__((alias("__remainderl")));
__typeof(remainderl) dreml __attribute__((weak, alias("__dreml")));

#endif
