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
    double temp_var_for_tac_0;
    temp_var_for_tac_0 = x * fn;

    temp_var_for_ext_0 = temp_var_for_tac_0;
    computeDMul((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&fn},
                "/home/shijia/Public/testprogram/e_scalb.c_e.c:20:28");
    AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_0,
            "/home/shijia/Public/testprogram/e_scalb.c_e.c:20:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  if (!isfinite(fn)) {
    if (isnan(fn) || int temp_var_for_tac_1; int temp_var_for_const_0;
        temp_var_for_tac_1 = fn > 0.0;

        ) {
      double temp_var_for_ext_1;
      double temp_var_for_tac_2;
      temp_var_for_tac_2 = x * fn;

      temp_var_for_ext_1 = temp_var_for_tac_2;
      compute((Addr)&temp_var_for_tac_1,
              {(Addr)&fn, (Addr) &(temp_var_for_const_0 = 0.0)},
              "/home/shijia/Public/testprogram/e_scalb.c_e.c:27:25");
      computeDMul((Addr)&temp_var_for_tac_2, {(Addr)&x, (Addr)&fn},
                  "/home/shijia/Public/testprogram/e_scalb.c_e.c:29:30");
      AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_2,
              "/home/shijia/Public/testprogram/e_scalb.c_e.c:29:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_1;
    }

    if (int temp_var_for_tac_3; int temp_var_for_const_1;
        temp_var_for_tac_3 = x == 0.0;

        ) {
      double temp_var_for_ext_2;
      temp_var_for_ext_2 = x;
      compute((Addr)&temp_var_for_tac_3,
              {(Addr)&x, (Addr) &(temp_var_for_const_1 = 0.0)},
              "/home/shijia/Public/testprogram/e_scalb.c_e.c:36:11");
      AssignD({(Addr)&temp_var_for_ext_2}, (Addr)&x,
              "/home/shijia/Public/testprogram/e_scalb.c_e.c:38:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_2;
    }

    double temp_var_for_ext_3;
    double temp_var_for_tac_4;
    double temp_var_for_const_2;
    temp_var_for_tac_4 = x / (-(fn));

    temp_var_for_ext_3 = temp_var_for_tac_4;
    computeDDiv((Addr)&temp_var_for_tac_4,
                {(Addr)&x, (Addr) &(temp_var_for_const_2 = (-(fn)))},
                "/home/shijia/Public/testprogram/e_scalb.c_e.c:46:28");
    AssignD({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_4,
            "/home/shijia/Public/testprogram/e_scalb.c_e.c:46:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ex(0.0 - _3);
  }
  ifn = (long)fn;
  if (int temp_var_for_tac_5; int temp_var_for_const_3;
      temp_var_for_tac_5 = ((double)ifn) != fn;

      ) {
    if (int temp_var_for_tac_6; int temp_var_for_const_4;
        double temp_var_for_callexp_0;

        temp_var_for_callexp_0 = __ieee754_rint(fn);
        temp_var_for_tac_6 = temp_var_for_callexp_0 != fn;

        ) {
      feraiseexcept(FE_INVALID);
      double temp_var_for_ext_4;
      double temp_var_for_const_5;
      double temp_var_for_callexp_1;

      temp_var_for_callexp_1 = __builtin_nan("");
      temp_var_for_ext_4 = temp_var_for_callexp_1;
      compute((Addr)&temp_var_for_tac_5,
              {(Addr) &(temp_var_for_const_3 = ((double)ifn)), (Addr)&fn},
              "/home/shijia/Public/testprogram/e_scalb.c_e.c:52:19");
      compute(
          (Addr)&temp_var_for_tac_6,
          {(Addr) &(temp_var_for_const_4 = temp_var_for_callexp_0), (Addr)&fn},
          "/home/shijia/Public/testprogram/e_scalb.c_e.c:53:28");
      AssignD({(Addr)&temp_var_for_ext_4},
              (Addr) &(temp_var_for_const_5 = temp_var_for_callexp_1),
              "/home/shijia/Public/testprogram/e_scalb.c_e.c:56:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_4;
    }
    if (ifn > 65000l) {
      double temp_var_for_ext_5;
      double temp_var_for_const_6;
      double temp_var_for_callexp_2;

      temp_var_for_callexp_2 = __ieee754_scalbln(x, 65000l);
      temp_var_for_ext_5 = temp_var_for_callexp_2;
      AssignD({(Addr)&temp_var_for_ext_5},
              (Addr) &(temp_var_for_const_6 = temp_var_for_callexp_2),
              "/home/shijia/Public/testprogram/e_scalb.c_e.c:64:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_5;
    }

    double temp_var_for_ext_6;
    double temp_var_for_const_7;
    double temp_var_for_callexp_3;

    temp_var_for_callexp_3 = __ieee754_scalbln(x, (-(65000l)));
    temp_var_for_ext_6 = temp_var_for_callexp_3;
    AssignD({(Addr)&temp_var_for_ext_6},
            (Addr) &(temp_var_for_const_7 = temp_var_for_callexp_3),
            "/home/shijia/Public/testprogram/e_scalb.c_e.c:72:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_6;
  }

  double temp_var_for_ext_7;
  double temp_var_for_const_8;
  double temp_var_for_callexp_4;

  temp_var_for_callexp_4 = __ieee754_scalbln(x, ifn);
  temp_var_for_ext_7 = temp_var_for_callexp_4;
  AssignD({(Addr)&temp_var_for_ext_7},
          (Addr) &(temp_var_for_const_8 = temp_var_for_callexp_4),
          "/home/shijia/Public/testprogram/e_scalb.c_e.c:79:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_7;
}

static double __attribute__((noinline)) sysv_scalb(double x, double fn) {
  double z = __ieee754_scalb(x, fn);

  if (isinf(z)) {
    if (isfinite(x)) {
      double temp_var_for_ext_8;
      double temp_var_for_const_9;
      double temp_var_for_callexp_5;

      temp_var_for_callexp_5 =
          __kernel_standard(x, fn, z, KMATHERR_SCALB_OVERFLOW);
      temp_var_for_ext_8 = temp_var_for_callexp_5;
      AssignD({(Addr)&temp_var_for_ext_8},
              (Addr) &(temp_var_for_const_9 = temp_var_for_callexp_5),
              "/home/shijia/Public/testprogram/e_scalb.c_e.c:91:26");
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
  (z == 0.0 && z != x) return __kernel_standard(
      x, fn, z, KMATHERR_SCALB_UNDERFLOW); /* scalb underflow */

  double temp_var_for_ext_9;
  temp_var_for_ext_9 = z;
  AssignD({(Addr)&temp_var_for_ext_9}, (Addr)&z,
          "/home/shijia/Public/testprogram/e_scalb.c_e.c:109:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_9;
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
