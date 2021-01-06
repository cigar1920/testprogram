#include "../ScDebug/scdebug.h"
/* @(#)s_ldexp.c 1.3 95/01/18 */
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

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_ldexp

double __ieee754_ldexp(double value, int exp) {
  if (!isfinite(value) || value == 0.0) {
    double temp_var_for_ext_0;
    temp_var_for_ext_0 = value;
    AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&value,
            "/home/shijia/Public/testprogram/s_ldexp.c_e.c:22:24");
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  double temp_var_for_ext_1;
  temp_var_for_ext_1 = __ieee754_scalbn(value, exp);
  double temp_var_for_const_0;AssignD({(Addr)&temp_var_for_ext_1},(Addr)&(temp_var_for_const_0=__ieee754_scalbn(getFVbyShadow<int>((Addr)&value), (exp)),"/home/shijia/Public/testprogram/s_ldexp.c_e.c:29:22");
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

#endif

double __ldexp(double x, int n) {
  x = __ieee754_ldexp(x, n);
  double temp_var_for_callexp_0 =
      __ieee754_ldexp(getFVbyShadow<double>((Addr)&x), (n));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  AssignD({(Addr)&x}, , "/home/shijia/Public/testprogram/s_ldexp.c_e.c:38:5");
  if (!isfinite(x) || x == 0.0)
    __set_errno(ERANGE);
  double temp_var_for_ext_2;
  temp_var_for_ext_2 = x;
  AssignD({(Addr)&temp_var_for_ext_2}, (Addr)&x,
          "/home/shijia/Public/testprogram/s_ldexp.c_e.c:42:22");
  callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_2;
}

__typeof(__ldexp) ldexp __attribute__((weak, alias("__ldexp")));
#ifdef __NO_LONG_DOUBLE_MATH
__typeof(__ldexpl) __ldexpl __attribute__((alias("__ldexp")));
__typeof(__ldexpl) ldexpl __attribute__((weak, alias("__ldexp")));
#endif
