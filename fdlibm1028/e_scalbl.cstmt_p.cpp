#include "../ScDebug/scdebug.h"
/* Copyright (C) 2011-2013 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by Ulrich Drepper <drepper@gmail.com>, 2011.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

long double __ieee754_scalbl(long double x, long double fn) {
  long ifn;

  if (isnan(x)) {
    long double temp_var_for_ext_0;
    temp_var_for_ext_0 = x * fn;
    computeLdMul((Addr)&temp_var_for_ext_0, {(Addr)&x, (Addr)&fn},
                 "/home/shijia/Public/testprogram/e_scalbl.c_e.c:30:24");
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  if (!isfinite(fn)) {
    if (isnan(fn) || fn > 0.0L) {
      long double temp_var_for_ext_1;
      temp_var_for_ext_1 = x * fn;
      computeLdMul((Addr)&temp_var_for_ext_1, {(Addr)&x, (Addr)&fn},
                   "/home/shijia/Public/testprogram/e_scalbl.c_e.c:39:26");
      callExpStack.push(
          getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_1;
    }

    if (x == 0.0L) {
      long double temp_var_for_ext_2;
      temp_var_for_ext_2 = x;
      AssignLd({(Addr)&temp_var_for_ext_2}, (Addr)&x,
               "/home/shijia/Public/testprogram/e_scalbl.c_e.c:48:26");
      callExpStack.push(
          getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_2;
    }

    long double temp_var_for_ext_3;
    temp_var_for_ext_3 = x / -fn;
    computeLdDiv((Addr)&temp_var_for_ext_3, {(Addr)&x, (Addr) & (-(fn))},
                 "/home/shijia/Public/testprogram/e_scalbl.c_e.c:56:24");
    callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ex(0.0 - _3);
  }
  ifn = (long)fn;
  if ((long double)ifn != fn) {
    if (__ieee754_rintl(fn) != fn) {
      feraiseexcept(FE_INVALID);
      long double temp_var_for_ext_4;
      temp_var_for_ext_4 = __builtin_nanl("");
      long double temp_var_for_callexp_0 = __builtin_nanl((""));
      CallStackPop((Addr)&temp_var_for_callexp_0,
                   getTop(temp_var_for_callexp_0));
      AssignLd({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_callexp_0,
               "/home/shijia/Public/testprogram/e_scalbl.c_e.c:66:26");
      callExpStack.push(
          getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_4;
    }
    if (ifn > 65000l) {
      long double temp_var_for_ext_5;
      temp_var_for_ext_5 = __ieee754_scalblnl(x, 65000l);
      long double temp_var_for_const_0;AssignLd({(Addr)&temp_var_for_ext_5},(Addr)&(temp_var_for_const_0=__ieee754_scalblnl(getFVbyShadow<int>((Addr)&x), (65000l)),"/home/shijia/Public/testprogram/e_scalbl.c_e.c:74:26");
      callExpStack.push(
          getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_5;
    }

    long double temp_var_for_ext_6;
    temp_var_for_ext_6 = __ieee754_scalblnl(x, -65000l);
    long double temp_var_for_const_1;AssignLd({(Addr)&temp_var_for_ext_6},(Addr)&(temp_var_for_const_1=__ieee754_scalblnl(getFVbyShadow<int>((Addr)&x), ((-(65000l)))),"/home/shijia/Public/testprogram/e_scalbl.c_e.c:82:24");
    callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_6;
  }

  long double temp_var_for_ext_7;
  temp_var_for_ext_7 = __ieee754_scalblnl(x, ifn);
  long double temp_var_for_const_2;AssignLd({(Addr)&temp_var_for_ext_7},(Addr)&(temp_var_for_const_2=__ieee754_scalblnl(getFVbyShadow<int>((Addr)&x), (ifn)),"/home/shijia/Public/testprogram/e_scalbl.c_e.c:89:22");
  callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_7;
}

static long double __attribute__((noinline))
sysv_scalbl(long double x, long double fn) {
  long double z = __ieee754_scalbl(x, fn);

  if (isinf(z)) {
    if (isfinite(x))
      return __kernel_standard_l(x, fn, z,
                                 KMATHERRL_SCALB_OVERFLOW); /* scalb overflow */
    else
      __set_errno(ERANGE);
  } else {
    if
  }
  (z == 0.0 && z != x) return __kernel_standard_l(
      x, fn, z, KMATHERRL_SCALB_UNDERFLOW); /* scalb underflow */

  long double temp_var_for_ext_8;
  temp_var_for_ext_8 = z;
  AssignLd({(Addr)&temp_var_for_ext_8}, (Addr)&z,
           "/home/shijia/Public/testprogram/e_scalbl.c_e.c:112:22");
  callExpStack.push(getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_8;
}

/* Wrapper scalb */
long double __scalbl(long double x, long double fn) {
  if (_LIB_VERSION == _SVID_) {
    return sysv_scalbl(x, fn);
  } else {
    long double z = __ieee754_scalbl(x, fn);

    if (!isfinite(z) || z == 0.0) {
      if (isnan(z)) {
        if (!isnan(x) && !isnan(fn))
          z = __kernel_standard_l(x, fn, z, KMATHERRL_SCALB_INVALID);
      } else if (isinf(z)) {
        if (!isinf(x) && !isinf(fn))
          z = __kernel_standard_l(x, fn, z, KMATHERRL_SCALB_OVERFLOW);
      } else {
        /* z == 0.  */
        if (x != 0.0 && !isinf(fn))
          z = __kernel_standard_l(x, fn, z, KMATHERRL_SCALB_UNDERFLOW);
      }
    }
    return z;
  }
}

__typeof(__scalbl) scalbl __attribute__((weak, alias("__scalbl")));

#endif
