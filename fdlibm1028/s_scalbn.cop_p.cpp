#include "../ScDebug/scdebug.h"
/* @(#)s_scalbn.c 1.3 95/01/18 */
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
 * scalbn (double x, int n)
 * scalbn(x,n) returns x* 2**n  computed by  exponent
 * manipulation rather than by actually performing an
 * exponentiation or a multiplication.
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_scalbn

double __ieee754_scalbn(double x, int n) {
  int32_t k, hx, lx;

  static const double two54 =
      1.80143985094819840000e+16; /* 0x43500000, 0x00000000 */
  static const double twom54 =
      5.55111512312578270212e-17; /* 0x3C900000, 0x00000000 */
  static const double hugeval = 1.0e+300;
  static const double tiny = 1.0e-300;

  GET_DOUBLE_WORDS(hx, lx, x);
  k = (hx >> IEEE754_DOUBLE_SHIFT) &
      IEEE754_DOUBLE_MAXEXP; /* extract exponent */
  if (k == 0) {              /* 0 or subnormal x */
    if ((lx | (hx & IC(0x7fffffff))) == 0) {
      double temp_var_for_ext_0;
      temp_var_for_ext_0 = x;
      AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&x,
              "/home/shijia/Public/testprogram/s_scalbn.c_e.c:42:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_0;
    }
    /* +-0 */
    x *= two54;
    ;
    GET_HIGH_WORD(hx, x);
    k = ((hx & IC(0x7ff00000)) >> IEEE754_DOUBLE_SHIFT) - 54;
  }
  if (k == IEEE754_DOUBLE_MAXEXP) {
    double temp_var_for_ext_1;
    double temp_var_for_tac_1;
    temp_var_for_tac_1 = x + x;

    temp_var_for_ext_1 = temp_var_for_tac_1;
    computeDAdd((Addr)&temp_var_for_tac_1, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/s_scalbn.c_e.c:55:28");
    AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_1,
            "/home/shijia/Public/testprogram/s_scalbn.c_e.c:55:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }
  /* NaN or Inf */
  if ((int32_t)n < IC(-30000)) {
    double temp_var_for_ext_2;
    double temp_var_for_tac_2;
    double temp_var_for_const_0, temp_var_for_const_1;
    double temp_var_for_callexp_0;

    temp_var_for_callexp_0 = copysign(tiny, x);
    temp_var_for_tac_2 = tiny * temp_var_for_callexp_0;

    temp_var_for_ext_2 = temp_var_for_tac_2;
    computeDMul((Addr)&temp_var_for_tac_2,
                {(Addr) &(temp_var_for_const_1 = tiny),
                 (Addr) &(temp_var_for_const_0 = temp_var_for_callexp_0)},
                "/home/shijia/Public/testprogram/s_scalbn.c_e.c:63:31");
    AssignD({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_2,
            "/home/shijia/Public/testprogram/s_scalbn.c_e.c:63:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  }
  /* underflow */
  if ((int32_t)n > IC(30000) || k + n > 0x7fe) {
    double temp_var_for_ext_3;
    double temp_var_for_tac_3;
    double temp_var_for_const_2, temp_var_for_const_3;
    double temp_var_for_callexp_1;

    temp_var_for_callexp_1 = copysign(hugeval, x);
    temp_var_for_tac_3 = hugeval * temp_var_for_callexp_1;

    temp_var_for_ext_3 = temp_var_for_tac_3;
    computeDMul((Addr)&temp_var_for_tac_3,
                {(Addr) &(temp_var_for_const_3 = hugeval),
                 (Addr) &(temp_var_for_const_2 = temp_var_for_callexp_1)},
                "/home/shijia/Public/testprogram/s_scalbn.c_e.c:71:34");
    AssignD({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_3,
            "/home/shijia/Public/testprogram/s_scalbn.c_e.c:71:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_3;
  }
  /* overflow  */
  /* Now k and n are bounded we know that k = k+n does not
     overflow.  */
  k = k + n;
  if (k > 0) /* normal result */
  {
    SET_HIGH_WORD(x, (hx & UC(0x800fffff)) | (k << IEEE754_DOUBLE_SHIFT));
    double temp_var_for_ext_4;
    temp_var_for_ext_4 = x;
    AssignD({(Addr)&temp_var_for_ext_4}, (Addr)&x,
            "/home/shijia/Public/testprogram/s_scalbn.c_e.c:84:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_4;
  }
  if (k <= -54) {
    double temp_var_for_ext_5;
    double temp_var_for_tac_4;
    double temp_var_for_const_4, temp_var_for_const_5;
    double temp_var_for_callexp_2;

    temp_var_for_callexp_2 = copysign(tiny, x);
    temp_var_for_tac_4 = tiny * temp_var_for_callexp_2;

    temp_var_for_ext_5 = temp_var_for_tac_4;
    computeDMul((Addr)&temp_var_for_tac_4,
                {(Addr) &(temp_var_for_const_5 = tiny),
                 (Addr) &(temp_var_for_const_4 = temp_var_for_callexp_2)},
                "/home/shijia/Public/testprogram/s_scalbn.c_e.c:91:31");
    AssignD({(Addr)&temp_var_for_ext_5}, (Addr)&temp_var_for_tac_4,
            "/home/shijia/Public/testprogram/s_scalbn.c_e.c:91:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_5;
  }
  /*underflow */
  k += 54; /* subnormal result */
  SET_HIGH_WORD(x, (hx & UC(0x800fffff)) | (k << IEEE754_DOUBLE_SHIFT));
  double temp_var_for_ext_6;
  double temp_var_for_tac_5;
  double temp_var_for_const_6;
  temp_var_for_tac_5 = x * twom54;

  temp_var_for_ext_6 = temp_var_for_tac_5;
  computeDMul((Addr)&temp_var_for_tac_5,
              {(Addr)&x, (Addr) &(temp_var_for_const_6 = twom54)},
              "/home/shijia/Public/testprogram/s_scalbn.c_e.c:100:26");
  AssignD({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_5,
          "/home/shijia/Public/testprogram/s_scalbn.c_e.c:100:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_6;
}

#endif

double __scalbn(double x, int n) {
  double temp_var_for_ext_7;
  double temp_var_for_const_7;
  double temp_var_for_callexp_3;

  temp_var_for_callexp_3 = __ieee754_scalbn(x, n);
  temp_var_for_ext_7 = temp_var_for_callexp_3;
  AssignD({(Addr)&temp_var_for_ext_7},
          (Addr) &(temp_var_for_const_7 = temp_var_for_callexp_3),
          "/home/shijia/Public/testprogram/s_scalbn.c_e.c:110:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_7;
}

__typeof(__scalbn) scalbn __attribute__((weak, alias("__scalbn")));
#ifdef __NO_LONG_DOUBLE_MATH
long double __scalbnl(long double x, int n) __attribute__((alias("__scalbn")));
__typeof(__scalbnl) scalbnl __attribute__((weak, alias("__scalbn")));
#endif

#if INT_MAX == LONG_MAX
double __scalbln(double x, long n) __attribute__((alias("__scalbn")));
double scalbln(double x, long n) __attribute__((weak, alias("__scalbln")));
#ifndef __have_fpu_scalbn
double __ieee754_scalbln(double x, long n)
    __attribute__((alias("__ieee754_scalbn")));
#endif
#ifdef __NO_LONG_DOUBLE_MATH
long double __scalblnl(long double x, long n)
    __attribute__((alias("__scalbln")));
long double scalblnl(long double x, long n)
    __attribute__((weak, alias("__scalblnl")));
#ifndef __have_fpu_scalbn
long double __ieee754_scalblnl(long double x, long n)
    __attribute__((alias("__ieee754_scalbln")));
#endif
#endif
#endif
