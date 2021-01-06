#include "../ScDebug/scdebug.h"
/* @(#)s_asinh.c 1.3 95/01/18 */
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

/* asinh(x)
 * Method :
 *	Based on
 *		asinh(x) = sign(x) * log [ |x| + sqrt(x*x+1) ]
 *	we have
 *	asinh(x) := x  if  1+x*x=1,
 *		 := sign(x)*(log(x)+ln2)) for large |x|, else
 *		 := sign(x)*log(2|x|+1/(|x|+sqrt(x*x+1))) if|x|>2, else
 *		 := sign(x)*log1p(|x| + x^2/(1 + sqrt(1+x^2)))
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_asinh

double __ieee754_asinh(double x) {
  double w;
  int32_t hx, ix;

  static const double one =
      1.00000000000000000000e+00; /* 0x3FF00000, 0x00000000 */
  static const double ln2 =
      6.93147180559945286227e-01; /* 0x3FE62E42, 0xFEFA39EF */
  static const double hugeval = 1.00000000000000000000e+300;

  GET_HIGH_WORD(hx, x);
  ix = hx & IC(0x7fffffff);
  if (ix < IC(0x3e300000)) { /* |x|<2**-28 */
    if (hugeval + x > one)
      return x; /* return x inexact except 0 */
  }
  if (ix > IC(0x41b00000)) { /* |x| > 2**28 */
    if (ix >= IC(0x7ff00000))
      return x + x; /* x is inf or NaN */
    w = __ieee754_log(__ieee754_fabs(x)) + ln2;
  } else {
    double xa = __ieee754_fabs(x);

    if (ix > IC(0x40000000)) { /* 2**28 > |x| > 2.0 */
      w = __ieee754_log(2.0 * xa + one / (__ieee754_sqrt(xa * xa + one) + xa));
    } else { /* 2.0 > |x| > 2**-28 */
      double t = xa * xa;

      w = __ieee754_log1p(xa + t / (one + __ieee754_sqrt(one + t)));
    }
  }
  if (hx > 0)
    return w;
  double temp_var_for_ext_0;
  temp_var_for_ext_0 = -w;
  AssignD({(Addr)&temp_var_for_ext_0}, (Addr) & (-(w)),
          "/home/shijia/Public/testprogram/s_asinh.c_e.c:64:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return (0.0 - 0);
  double temp_var_for_const_0, temp_var_for_const_1;
  ;
  double temp_var_for_tac_0;
  computeDSub((Addr)&temp_var_for_tac_0, {(Addr) &(temp_var_for_const_1 = 0.0),
                                          (Addr) &(temp_var_for_const_0 = 0)},
              "toString(biExpr->getExprLoc())");
}

#endif

double __asinh(double x) {
  double temp_var_for_ext_1;
  temp_var_for_ext_1 = __ieee754_asinh(x);
  double temp_var_for_callexp_0 =
      __ieee754_asinh(getFVbyShadow<double>((Addr)&x));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_callexp_0,
          "/home/shijia/Public/testprogram/s_asinh.c_e.c:74:22");
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

__typeof(__asinh) asinh __attribute__((weak, alias("__asinh")));
#ifdef __NO_LONG_DOUBLE_MATH
__typeof(__asinhl) __asinhl __attribute__((alias("__asinh")));
__typeof(__asinhl) asinhl __attribute__((weak, alias("__asinh")));
#endif
