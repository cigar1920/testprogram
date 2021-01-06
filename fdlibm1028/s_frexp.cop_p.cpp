#include "../ScDebug/scdebug.h"
/* @(#)s_frexp.c 1.4 95/01/18 */
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
 * for non-zero x
 *	x = frexp(arg,&exp);
 * return a double fp quantity x such that 0.5 <= |x| <1.0
 * and the corresponding binary exponent "exp". That is
 *	arg = x*2^exp.
 * If arg is inf, 0.0, or NaN, then frexp(arg,&exp) returns arg
 * with *exp=0.
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_frexp

double __ieee754_frexp(double x, int *eptr) {
  int32_t hx, ix, lx;
  static const double two54 =
      1.80143985094819840000e+16; /* 0x43500000, 0x00000000 */

  GET_DOUBLE_WORDS(hx, lx, x);
  ix = UC(0x7fffffff) & hx;
  *eptr = 0;
  if (ix >= IC(0x7ff00000) || ((ix | lx) == 0)) {
    double temp_var_for_ext_0;
    temp_var_for_ext_0 = x;
    AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&x,
            "/home/shijia/Public/testprogram/s_frexp.c_e.c:39:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }
  /* 0,inf,nan */
  if (ix < IC(0x00100000)) { /* subnormal */
    x *= two54;
    ;
    GET_HIGH_WORD(hx, x);
    ix = hx & UC(0x7fffffff);
    *eptr = -54;
  }
  *eptr += (int)(ix >> 20) - 1022;
  hx = (hx & UC(0x800fffff)) | UC(0x3fe00000);
  SET_HIGH_WORD(x, hx);
  double temp_var_for_ext_1;
  temp_var_for_ext_1 = x;
  AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&x,
          "/home/shijia/Public/testprogram/s_frexp.c_e.c:55:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

#endif

double __frexp(double x, int *exp) {
  double temp_var_for_ext_2;
  double temp_var_for_const_0;
  double temp_var_for_callexp_0;

  temp_var_for_callexp_0 = __ieee754_frexp(x, exp);
  temp_var_for_ext_2 = temp_var_for_callexp_0;
  AssignD({(Addr)&temp_var_for_ext_2},
          (Addr) &(temp_var_for_const_0 = temp_var_for_callexp_0),
          "/home/shijia/Public/testprogram/s_frexp.c_e.c:65:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_2;
}

__typeof(__frexp) frexp __attribute__((weak, alias("__frexp")));
#ifdef __NO_LONG_DOUBLE_MATH
long double __frexpl(long double x, int *expt)
    __attribute__((alias("__frexp")));
__typeof(__frexpl) frexpl __attribute__((weak, alias("__frexp")));
#endif
