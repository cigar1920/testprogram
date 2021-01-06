#include "../ScDebug/scdebug.h"
/* @(#)s_rint.c 1.3 95/01/18 */
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
 * rint(x)
 * Return x rounded to integral value according to the prevailing
 * rounding mode.
 * Method:
 *	Using floating addition.
 * Exception:
 *	Inexact flag raised if x not equal to rint(x).
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_rint

static double __ieee754_roundeven(double x) {
  int32_t i0, j0;
  uint32_t i1;

  static const double hugeval = 1.0e300;

  GET_DOUBLE_WORDS(i0, i1, x);
  j0 = ((i0 >> IEEE754_DOUBLE_SHIFT) & IEEE754_DOUBLE_MAXEXP) -
       IEEE754_DOUBLE_BIAS;
  if (j0 < IEEE754_DOUBLE_SHIFT) {
    if (j0 < 0) {
      math_force_eval(hugeval + x);
      if (j0 == -1 && (i0 & IC(0x000fffff)) != 0) {
        i0 &= UC(0x80000000);
        i0 |= UC(0x3ff00000);
      } else {
        i0 &= UC(0x80000000);
      }
      i1 = 0;
    } else {
      uint32_t i = UC(0x000fffff) >> j0;

      if (((i0 & i) | i1) == 0)
      /* X is integral.  */
      {
        double temp_var_for_ext_0;
        temp_var_for_ext_0 = x;
        computeDAdd((Addr)&temp_var_for_tac_0,
                    {(Addr) &(temp_var_for_const_0 = hugeval), (Addr)&x},
                    "/home/shijia/Public/testprogram/s_rint.c_e.c:40:7 "
                    "<Spelling=/home/shijia/Public/testprogram/"
                    "s_rint.c_e.c:40:31>");
        computeDAdd((Addr)&temp_var_for_tac_1,
                    {(Addr) &(temp_var_for_const_1 = hugeval), (Addr)&x},
                    "/home/shijia/Public/testprogram/s_rint.c_e.c:40:7 "
                    "<Spelling=/home/shijia/Public/testprogram/"
                    "s_rint.c_e.c:40:31>");
        AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&x,
                "/home/shijia/Public/testprogram/s_rint.c_e.c:55:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_0;
      }

      /* Raise inexact if x != 0.  */
      math_force_eval(hugeval + x);

      if ((i0 & (i >> 1)) != 0 || i1 != 0 || (i0 & (UC(0x00100000) >> j0))) {
        i0 += UC(0x00080000) >> j0;
      }
      i0 &= ~i;
      i1 = 0;
    }
  } else {
    if (j0 > 51) {
      if (j0 == (IEEE754_DOUBLE_MAXEXP - IEEE754_DOUBLE_BIAS)) {
        double temp_var_for_ext_1;
        double temp_var_for_tac_4;
        temp_var_for_tac_4 = x + x;

        temp_var_for_ext_1 = temp_var_for_tac_4;
        computeDAdd((Addr)&temp_var_for_tac_2,
                    {(Addr) &(temp_var_for_const_2 = hugeval), (Addr)&x},
                    "/home/shijia/Public/testprogram/s_rint.c_e.c:63:7 "
                    "<Spelling=/home/shijia/Public/testprogram/"
                    "s_rint.c_e.c:63:31>");
        computeDAdd((Addr)&temp_var_for_tac_3,
                    {(Addr) &(temp_var_for_const_3 = hugeval), (Addr)&x},
                    "/home/shijia/Public/testprogram/s_rint.c_e.c:63:7 "
                    "<Spelling=/home/shijia/Public/testprogram/"
                    "s_rint.c_e.c:63:31>");
        computeDAdd((Addr)&temp_var_for_tac_4, {(Addr)&x, (Addr)&x},
                    "/home/shijia/Public/testprogram/s_rint.c_e.c:75:32");
        AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_4,
                "/home/shijia/Public/testprogram/s_rint.c_e.c:75:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_1;
      }
      /* Inf or NaN */
      else {
        double temp_var_for_ext_2;
        temp_var_for_ext_2 = x;
        AssignD({(Addr)&temp_var_for_ext_2}, (Addr)&x,
                "/home/shijia/Public/testprogram/s_rint.c_e.c:84:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_2;
      }
      /* x is integral */
    } else {
      uint32_t i = UC(0xffffffff) >> (j0 - IEEE754_DOUBLE_SHIFT);
      uint32_t j;

      if ((i1 & i) == 0) {
        double temp_var_for_ext_3;
        temp_var_for_ext_3 = x;
        AssignD({(Addr)&temp_var_for_ext_3}, (Addr)&x,
                "/home/shijia/Public/testprogram/s_rint.c_e.c:97:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_3;
      }
      /* x is integral */

      /* Raise inexact if x != 0. */
      math_force_eval(hugeval + x);

      if ((i1 & (i >> 1)) != 0 || (j0 == IEEE754_DOUBLE_SHIFT && (i0 & 1)) ||
          (i1 & (UC(1) << (52 - j0)))) {
        j = i1 + (UC(1) << (51 - j0));
        if (j < i1) {
          i0 += 1;
        }

        i1 = j;
      }
      i1 &= ~i;
    }
  }

  INSERT_WORDS(x, i0, i1);
  double temp_var_for_ext_4;
  temp_var_for_ext_4 = x;
  computeDAdd((Addr)&temp_var_for_tac_5,
              {(Addr) &(temp_var_for_const_4 = hugeval), (Addr)&x},
              "/home/shijia/Public/testprogram/s_rint.c_e.c:106:7 "
              "<Spelling=/home/shijia/Public/testprogram/s_rint.c_e.c:106:31>");
  computeDAdd((Addr)&temp_var_for_tac_6,
              {(Addr) &(temp_var_for_const_5 = hugeval), (Addr)&x},
              "/home/shijia/Public/testprogram/s_rint.c_e.c:106:7 "
              "<Spelling=/home/shijia/Public/testprogram/s_rint.c_e.c:106:31>");
  AssignD({(Addr)&temp_var_for_ext_4}, (Addr)&x,
          "/home/shijia/Public/testprogram/s_rint.c_e.c:123:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_4;
}

double __ieee754_rint(double x) {
  /*
   * above code relies on a FPU doing the rounding,
   * and using round-to-even for FE_TONEAREST
   */
  int temp_var_for_ext_5;
  temp_var_for_ext_5 = fegetround();
  switch (temp_var_for_ext_5) {
  case FE_UPWARD: {
    double temp_var_for_ext_6;
    double temp_var_for_const_6;
    double temp_var_for_callexp_0;

    temp_var_for_callexp_0 = __ieee754_ceil(x);
    temp_var_for_ext_6 = temp_var_for_callexp_0;
    AssignD({(Addr)&temp_var_for_ext_6},
            (Addr) &(temp_var_for_const_6 = temp_var_for_callexp_0),
            "/home/shijia/Public/testprogram/s_rint.c_e.c:139:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_6;
  }

  case FE_DOWNWARD: {
    double temp_var_for_ext_7;
    double temp_var_for_const_7;
    double temp_var_for_callexp_1;

    temp_var_for_callexp_1 = __ieee754_floor(x);
    temp_var_for_ext_7 = temp_var_for_callexp_1;
    AssignD({(Addr)&temp_var_for_ext_7},
            (Addr) &(temp_var_for_const_7 = temp_var_for_callexp_1),
            "/home/shijia/Public/testprogram/s_rint.c_e.c:147:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_7;
  }

  case FE_TOWARDZERO: {
    double temp_var_for_ext_8;
    double temp_var_for_const_8;
    double temp_var_for_callexp_2;

    temp_var_for_callexp_2 = __ieee754_trunc(x);
    temp_var_for_ext_8 = temp_var_for_callexp_2;
    AssignD({(Addr)&temp_var_for_ext_8},
            (Addr) &(temp_var_for_const_8 = temp_var_for_callexp_2),
            "/home/shijia/Public/testprogram/s_rint.c_e.c:155:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_8;
  }
  }
  /* case FE_TONEAREST: */
  double temp_var_for_ext_9;
  double temp_var_for_const_9;
  double temp_var_for_callexp_3;

  temp_var_for_callexp_3 = __ieee754_roundeven(x);
  temp_var_for_ext_9 = temp_var_for_callexp_3;
  AssignD({(Addr)&temp_var_for_ext_9},
          (Addr) &(temp_var_for_const_9 = temp_var_for_callexp_3),
          "/home/shijia/Public/testprogram/s_rint.c_e.c:163:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_9;
}

#endif

double __rint(double x) {
  double temp_var_for_ext_10;
  double temp_var_for_const_10;
  double temp_var_for_callexp_4;

  temp_var_for_callexp_4 = __ieee754_rint(x);
  temp_var_for_ext_10 = temp_var_for_callexp_4;
  AssignD({(Addr)&temp_var_for_ext_10},
          (Addr) &(temp_var_for_const_10 = temp_var_for_callexp_4),
          "/home/shijia/Public/testprogram/s_rint.c_e.c:173:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_10", (Addr)&temp_var_for_ext_10));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_10;
}

__typeof(__rint) rint __attribute__((weak, alias("__rint")));
#ifdef __NO_LONG_DOUBLE_MATH
__typeof(rintl) __rintl __attribute__((alias("__rint")));
__typeof(__rintl) rintl __attribute__((weak, alias("__rint")));
#endif
