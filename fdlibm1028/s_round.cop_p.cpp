#include "../ScDebug/scdebug.h"
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
/*
FUNCTION
<<round>>, <<roundf>>--round to integer, to nearest
INDEX
        round
INDEX
        roundf

ANSI_SYNOPSIS
        #include <math.h>
        double round(double <[x]>);
        float roundf(float <[x]>);

DESCRIPTION
        The <<round>> functions round their argument to the nearest integer
        value in floating-point format, rounding halfway cases away from zero,
        regardless of the current rounding direction.  (While the "inexact"
        floating-point exception behavior is unspecified by the C standard, the
        <<round>> functions are written so that "inexact" is not raised if the
        result does not equal the argument, which behavior is as recommended by
        IEEE 754 for its related functions.)

RETURNS
<[x]> rounded to an integral value.

PORTABILITY
ANSI C, POSIX

SEEALSO
<<nearbyint>>, <<rint>>

*/

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_round

double __ieee754_round(double x) {
  int32_t i0, j0;
  uint32_t i1;

  static const double hugeval = 1.0e300;

  GET_DOUBLE_WORDS(i0, i1, x);
  j0 = ((i0 >> IEEE754_DOUBLE_SHIFT) & IEEE754_DOUBLE_MAXEXP) -
       IEEE754_DOUBLE_BIAS;
  if (j0 < IEEE754_DOUBLE_SHIFT) {
    if (j0 < 0) {
      math_force_eval(hugeval + x);
      i0 &= UC(0x80000000);
      if (j0 == -1) /* Result is +1.0 or -1.0. */
      {
        i0 |= UC(0x3ff00000);
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
                    "/home/shijia/Public/testprogram/s_round.c_e.c:61:7 "
                    "<Spelling=/home/shijia/Public/testprogram/"
                    "s_round.c_e.c:61:31>");
        computeDAdd((Addr)&temp_var_for_tac_1,
                    {(Addr) &(temp_var_for_const_1 = hugeval), (Addr)&x},
                    "/home/shijia/Public/testprogram/s_round.c_e.c:61:7 "
                    "<Spelling=/home/shijia/Public/testprogram/"
                    "s_round.c_e.c:61:31>");
        AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&x,
                "/home/shijia/Public/testprogram/s_round.c_e.c:76:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_0;
      }

      /* Raise inexact if x != 0.  */
      math_force_eval(hugeval + x);

      i0 += UC(0x00080000) >> j0;
      i0 &= ~i;
      i1 = 0;
    }
  } else {
    if (j0 > 51) {
      if (j0 == (IEEE754_DOUBLE_MAXEXP - IEEE754_DOUBLE_BIAS))
      /* Inf or NaN.  */
      {
        double temp_var_for_ext_1;
        double temp_var_for_tac_4;
        temp_var_for_tac_4 = x + x;

        temp_var_for_ext_1 = temp_var_for_tac_4;
        computeDAdd((Addr)&temp_var_for_tac_2,
                    {(Addr) &(temp_var_for_const_2 = hugeval), (Addr)&x},
                    "/home/shijia/Public/testprogram/s_round.c_e.c:84:7 "
                    "<Spelling=/home/shijia/Public/testprogram/"
                    "s_round.c_e.c:84:31>");
        computeDAdd((Addr)&temp_var_for_tac_3,
                    {(Addr) &(temp_var_for_const_3 = hugeval), (Addr)&x},
                    "/home/shijia/Public/testprogram/s_round.c_e.c:84:7 "
                    "<Spelling=/home/shijia/Public/testprogram/"
                    "s_round.c_e.c:84:31>");
        computeDAdd((Addr)&temp_var_for_tac_4, {(Addr)&x, (Addr)&x},
                    "/home/shijia/Public/testprogram/s_round.c_e.c:96:32");
        AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_4,
                "/home/shijia/Public/testprogram/s_round.c_e.c:96:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_1;
      }

      else {
        double temp_var_for_ext_2;
        temp_var_for_ext_2 = x;
        AssignD({(Addr)&temp_var_for_ext_2}, (Addr)&x,
                "/home/shijia/Public/testprogram/s_round.c_e.c:105:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_2;
      }

    } else {
      uint32_t i = UC(0xffffffff) >> (j0 - IEEE754_DOUBLE_SHIFT);
      uint32_t j;

      if ((i1 & i) == 0)
      /* X is integral.  */
      {
        double temp_var_for_ext_3;
        temp_var_for_ext_3 = x;
        AssignD({(Addr)&temp_var_for_ext_3}, (Addr)&x,
                "/home/shijia/Public/testprogram/s_round.c_e.c:120:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_3;
      }

      /* Raise inexact if x != 0.  */
      math_force_eval(hugeval + x);

      j = i1 + (UC(1) << (51 - j0));

      if (j < i1) {
        i0 += 1;
      }

      i1 = j;
      i1 &= ~i;
    }
  }

  INSERT_WORDS(x, i0, i1);

  double temp_var_for_ext_4;
  temp_var_for_ext_4 = x;
  computeDAdd((Addr)&temp_var_for_tac_5,
              {(Addr) &(temp_var_for_const_4 = hugeval), (Addr)&x},
              "/home/shijia/Public/testprogram/s_round.c_e.c:128:7 "
              "<Spelling=/home/shijia/Public/testprogram/"
              "s_round.c_e.c:128:31>");
  computeDAdd((Addr)&temp_var_for_tac_6,
              {(Addr) &(temp_var_for_const_5 = hugeval), (Addr)&x},
              "/home/shijia/Public/testprogram/s_round.c_e.c:128:7 "
              "<Spelling=/home/shijia/Public/testprogram/"
              "s_round.c_e.c:128:31>");
  AssignD({(Addr)&temp_var_for_ext_4}, (Addr)&x,
          "/home/shijia/Public/testprogram/s_round.c_e.c:144:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_4;
}

#endif

double __round(double x) {
  double temp_var_for_ext_5;
  double temp_var_for_const_6;
  double temp_var_for_callexp_0;

  temp_var_for_callexp_0 = __ieee754_round(x);
  temp_var_for_ext_5 = temp_var_for_callexp_0;
  AssignD({(Addr)&temp_var_for_ext_5},
          (Addr) &(temp_var_for_const_6 = temp_var_for_callexp_0),
          "/home/shijia/Public/testprogram/s_round.c_e.c:154:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_5;
}

__typeof(__round) round __attribute__((weak, alias("__round")));
#ifdef __NO_LONG_DOUBLE_MATH
__typeof(__roundl) __roundl __attribute__((alias("__round")));
__typeof(__roundl) roundl __attribute__((weak, alias("__round")));
#endif
