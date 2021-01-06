#include "../ScDebug/scdebug.h"
/* @(#)e_scalb.c 1.3 95/01/18 */
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

#include "fdlibm.h"

double __ieee754_scalb(double x, double fn) {
  long ifn;

  if (isnan(x)) {
    double temp_var_for_ext_0;
    temp_var_for_ext_0 = x * fn;
    computeDMul((Addr)&temp_var_for_ext_0, {(Addr)&x, (Addr)&fn},
                "/home/shijia/Public/testprogram/e_scalb.c_e.c:20:24");
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  if (!isfinite(fn)) {
    if (isnan(fn) || fn > 0.0) {
      double temp_var_for_ext_1;
      temp_var_for_ext_1 = x * fn;
      computeDMul((Addr)&temp_var_for_ext_1, {(Addr)&x, (Addr)&fn},
                  "/home/shijia/Public/testprogram/e_scalb.c_e.c:29:26");
      callExpStack.push(
          getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_1;
    }

    if (x == 0.0) {
      double temp_var_for_ext_2;
      temp_var_for_ext_2 = x;
      AssignD({(Addr)&temp_var_for_ext_2}, (Addr)&x,
              "/home/shijia/Public/testprogram/e_scalb.c_e.c:38:26");
      callExpStack.push(
          getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_2;
    }

    double temp_var_for_ext_3;
    temp_var_for_ext_3 = x / -fn;
    computeDDiv((Addr)&temp_var_for_ext_3, {(Addr)&x, (Addr) & (-(fn))},
                "/home/shijia/Public/testprogram/e_scalb.c_e.c:46:24");
    callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ex(0.0 - _3);
  }
  ifn = (long)fn;
  if ((double)ifn != fn) {
    if (__ieee754_rint(fn) != fn) {
      feraiseexcept(FE_INVALID);
      double temp_var_for_ext_4;
      temp_var_for_ext_4 = __builtin_nan("");
      double temp_var_for_callexp_0 = __builtin_nan((""));
      CallStackPop((Addr)&temp_var_for_callexp_0,
                   getTop(temp_var_for_callexp_0));
      AssignD({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_callexp_0,
              "/home/shijia/Public/testprogram/e_scalb.c_e.c:56:26");
      callExpStack.push(
          getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_4;
    }
    if (ifn > 65000l) {
      double temp_var_for_ext_5;
      temp_var_for_ext_5 = __ieee754_scalbln(x, 65000l);
      double temp_var_for_const_0;AssignD({(Addr)&temp_var_for_ext_5},(Addr)&(temp_var_for_const_0=__ieee754_scalbln(getFVbyShadow<int>((Addr)&x), (65000l)),"/home/shijia/Public/testprogram/e_scalb.c_e.c:64:26");
      callExpStack.push(
          getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_5;
    }

    double temp_var_for_ext_6;
    temp_var_for_ext_6 = __ieee754_scalbln(x, -65000l);
    double temp_var_for_const_1;AssignD({(Addr)&temp_var_for_ext_6},(Addr)&(temp_var_for_const_1=__ieee754_scalbln(getFVbyShadow<int>((Addr)&x), ((-(65000l)))),"/home/shijia/Public/testprogram/e_scalb.c_e.c:72:24");
    callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_6;
  }

  double temp_var_for_ext_7;
  temp_var_for_ext_7 = __ieee754_scalbln(x, ifn);
  double temp_var_for_const_2;AssignD({(Addr)&temp_var_for_ext_7},(Addr)&(temp_var_for_const_2=__ieee754_scalbln(getFVbyShadow<int>((Addr)&x), (ifn)),"/home/shijia/Public/testprogram/e_scalb.c_e.c:79:22");
  callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_7;
}

static double __attribute__((noinline)) sysv_scalb(double x, double fn) {
  double z = __ieee754_scalb(x, fn);

  if (isinf(z)) {
    if (isfinite(x))
      return __kernel_standard(x, fn, z,
                               KMATHERR_SCALB_OVERFLOW); /* scalb overflow */
    else
      __set_errno(ERANGE);
  } else {
    if
  }
  (z == 0.0 && z != x) return __kernel_standard(
      x, fn, z, KMATHERR_SCALB_UNDERFLOW); /* scalb underflow */

  double temp_var_for_ext_8;
  temp_var_for_ext_8 = z;
  AssignD({(Addr)&temp_var_for_ext_8}, (Addr)&z,
          "/home/shijia/Public/testprogram/e_scalb.c_e.c:101:22");
  callExpStack.push(getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_8;
}

/*
 * wrapper scalb(double x, double fn) is provide for
 * passing various standard test suite. One
 * should use scalbn() instead.
 */

double __scalb(double x, double fn) {
  if (_LIB_VERSION == _SVID_) {
    return sysv_scalb(x, fn);
  } else {
    double z = __ieee754_scalb(x, fn);

    if (!isfinite(z) || z == 0.0) {
      if (isnan(z)) {
        if (!isnan(x) && !isnan(fn))
          z = __kernel_standard(x, fn, z, KMATHERR_SCALB_INVALID);
      } else if (isinf(z)) {
        if (!isinf(x) && !isinf(fn))
          z = __kernel_standard(x, fn, z, KMATHERR_SCALB_OVERFLOW);
      } else {
        /* z == 0.  */
        if (x != 0.0 && !isinf(fn))
          z = __kernel_standard(x, fn, z, KMATHERR_SCALB_UNDERFLOW);
      }
    }
    return z;
  }
}

__typeof(__scalb) scalb __attribute__((weak, alias("__scalb")));
#ifdef __NO_LONG_DOUBLE_MATH
long double __scalbl(long double x, long double fn)
    __attribute__((alias("__scalb")));
__typeof(__scalbl) scalbl __attribute__((weak, alias("__scalb")));
#endif
