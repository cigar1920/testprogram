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
    long double temp_var_for_tac_0;
    temp_var_for_tac_0 = x * fn;

    temp_var_for_ext_0 = temp_var_for_tac_0;
    computeLdMul((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&fn},
                 "/home/shijia/Public/testprogram/e_scalbl.c_e.c:30:28");
    AssignLd({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_0,
             "/home/shijia/Public/testprogram/e_scalbl.c_e.c:30:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  if (!isfinite(fn)) {
    if (isnan(fn) || int temp_var_for_tac_1; int temp_var_for_const_0;
        temp_var_for_tac_1 = fn > 0.0L;

        ) {
      long double temp_var_for_ext_1;
      long double temp_var_for_tac_2;
      temp_var_for_tac_2 = x * fn;

      temp_var_for_ext_1 = temp_var_for_tac_2;
      compute((Addr)&temp_var_for_tac_1,
              {(Addr)&fn, (Addr) &(temp_var_for_const_0 = 0.0L)},
              "/home/shijia/Public/testprogram/e_scalbl.c_e.c:37:25");
      computeLdMul((Addr)&temp_var_for_tac_2, {(Addr)&x, (Addr)&fn},
                   "/home/shijia/Public/testprogram/e_scalbl.c_e.c:39:30");
      AssignLd({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_2,
               "/home/shijia/Public/testprogram/e_scalbl.c_e.c:39:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_1;
    }

    if (int temp_var_for_tac_3; int temp_var_for_const_1;
        temp_var_for_tac_3 = x == 0.0L;

        ) {
      long double temp_var_for_ext_2;
      temp_var_for_ext_2 = x;
      compute((Addr)&temp_var_for_tac_3,
              {(Addr)&x, (Addr) &(temp_var_for_const_1 = 0.0L)},
              "/home/shijia/Public/testprogram/e_scalbl.c_e.c:46:11");
      AssignLd({(Addr)&temp_var_for_ext_2}, (Addr)&x,
               "/home/shijia/Public/testprogram/e_scalbl.c_e.c:48:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_2;
    }

    long double temp_var_for_ext_3;
    long double temp_var_for_tac_4;
    long double temp_var_for_const_2;
    temp_var_for_tac_4 = x / (-(fn));

    temp_var_for_ext_3 = temp_var_for_tac_4;
    computeLdDiv((Addr)&temp_var_for_tac_4,
                 {(Addr)&x, (Addr) &(temp_var_for_const_2 = (-(fn)))},
                 "/home/shijia/Public/testprogram/e_scalbl.c_e.c:56:28");
    AssignLd({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_4,
             "/home/shijia/Public/testprogram/e_scalbl.c_e.c:56:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ex(0.0 - _3);
  }
  ifn = (long)fn;
  if (int temp_var_for_tac_5; int temp_var_for_const_3;
      temp_var_for_tac_5 = ((long double)ifn) != fn;

      ) {
    if (int temp_var_for_tac_6; int temp_var_for_const_4;
        long double temp_var_for_callexp_0;

        temp_var_for_callexp_0 = __ieee754_rintl(fn);
        temp_var_for_tac_6 = temp_var_for_callexp_0 != fn;

        ) {
      feraiseexcept(FE_INVALID);
      long double temp_var_for_ext_4;
      long double temp_var_for_const_5;
      long double temp_var_for_callexp_1;

      temp_var_for_callexp_1 = __builtin_nanl("");
      temp_var_for_ext_4 = temp_var_for_callexp_1;
      compute((Addr)&temp_var_for_tac_5,
              {(Addr) &(temp_var_for_const_3 = ((long double)ifn)), (Addr)&fn},
              "/home/shijia/Public/testprogram/e_scalbl.c_e.c:62:24");
      compute(
          (Addr)&temp_var_for_tac_6,
          {(Addr) &(temp_var_for_const_4 = temp_var_for_callexp_0), (Addr)&fn},
          "/home/shijia/Public/testprogram/e_scalbl.c_e.c:63:29");
      AssignLd({(Addr)&temp_var_for_ext_4},
               (Addr) &(temp_var_for_const_5 = temp_var_for_callexp_1),
               "/home/shijia/Public/testprogram/e_scalbl.c_e.c:66:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_4;
    }
    if (ifn > 65000l) {
      long double temp_var_for_ext_5;
      long double temp_var_for_const_6;
      long double temp_var_for_callexp_2;

      temp_var_for_callexp_2 = __ieee754_scalblnl(x, 65000l);
      temp_var_for_ext_5 = temp_var_for_callexp_2;
      AssignLd({(Addr)&temp_var_for_ext_5},
               (Addr) &(temp_var_for_const_6 = temp_var_for_callexp_2),
               "/home/shijia/Public/testprogram/e_scalbl.c_e.c:74:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_5;
    }

    long double temp_var_for_ext_6;
    long double temp_var_for_const_7;
    long double temp_var_for_callexp_3;

    temp_var_for_callexp_3 = __ieee754_scalblnl(x, (-(65000l)));
    temp_var_for_ext_6 = temp_var_for_callexp_3;
    AssignLd({(Addr)&temp_var_for_ext_6},
             (Addr) &(temp_var_for_const_7 = temp_var_for_callexp_3),
             "/home/shijia/Public/testprogram/e_scalbl.c_e.c:82:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_6;
  }

  long double temp_var_for_ext_7;
  long double temp_var_for_const_8;
  long double temp_var_for_callexp_4;

  temp_var_for_callexp_4 = __ieee754_scalblnl(x, ifn);
  temp_var_for_ext_7 = temp_var_for_callexp_4;
  AssignLd({(Addr)&temp_var_for_ext_7},
           (Addr) &(temp_var_for_const_8 = temp_var_for_callexp_4),
           "/home/shijia/Public/testprogram/e_scalbl.c_e.c:89:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_7;
}

static long double __attribute__((noinline))
sysv_scalbl(long double x, long double fn) {
  long double z = __ieee754_scalbl(x, fn);

  if (isinf(z)) {
    if (isfinite(x)) {
      long double temp_var_for_ext_8;
      long double temp_var_for_const_9;
      long double temp_var_for_callexp_5;

      temp_var_for_callexp_5 =
          __kernel_standard_l(x, fn, z, KMATHERRL_SCALB_OVERFLOW);
      temp_var_for_ext_8 = temp_var_for_callexp_5;
      AssignLd({(Addr)&temp_var_for_ext_8},
               (Addr) &(temp_var_for_const_9 = temp_var_for_callexp_5),
               "/home/shijia/Public/testprogram/e_scalbl.c_e.c:102:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_8;
    }
    /* scalb overflow */
    else {
      __set_errno(ERANGE);
    }

  } else {
    if
  }
  (z == 0.0 && z != x) return __kernel_standard_l(
      x, fn, z, KMATHERRL_SCALB_UNDERFLOW); /* scalb underflow */

  long double temp_var_for_ext_9;
  temp_var_for_ext_9 = z;
  AssignLd({(Addr)&temp_var_for_ext_9}, (Addr)&z,
           "/home/shijia/Public/testprogram/e_scalbl.c_e.c:121:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_9;
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
