#include "../ScDebug/scdebug.h"
/* @(#)s_ceil.c 1.3 95/01/18 */
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
 * ceil(x)
 * Return x rounded toward -inf to integral value
 * Method:
 *	Bit twiddling.
 * Exception:
 *	Inexact flag raised if x not equal to ceil(x).
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_ceil

double __ieee754_ceil(double x) {
  int32_t i0, j0;
  uint32_t i, j, i1;

  static const double hugeval = 1.0e300;

  GET_DOUBLE_WORDS(i0, i1, x);
  j0 = ((i0 >> IEEE754_DOUBLE_SHIFT) & IEEE754_DOUBLE_MAXEXP) -
       IEEE754_DOUBLE_BIAS;
  if (j0 < IEEE754_DOUBLE_SHIFT) {
    if (j0 < 0) { /* raise inexact if x != 0 */
      math_force_eval(hugeval + x);
      /* return 0*sign(x) if |x|<1 */
      if (i0 < 0) {
        i0 = IC(0x80000000);
        i1 = 0;
      } else {
        if ((i0 | i1) != 0) {
          i0 = UC(0x3ff00000);
          i1 = 0;
        }
      }

    } else {
      i = UC(0x000fffff) >> j0;
      if (((i0 & i) | i1) == 0) {
        double temp_var_for_ext_0;
        temp_var_for_ext_0 = x;
        computeDAdd((Addr)&temp_var_for_tac_0,
                    {(Addr) &(temp_var_for_const_0 = hugeval), (Addr)&x},
                    "/home/shijia/Public/testprogram/s_ceil.c_e.c:39:7 "
                    "<Spelling=/home/shijia/Public/testprogram/"
                    "s_ceil.c_e.c:39:31>");
        computeDAdd((Addr)&temp_var_for_tac_1,
                    {(Addr) &(temp_var_for_const_1 = hugeval), (Addr)&x},
                    "/home/shijia/Public/testprogram/s_ceil.c_e.c:39:7 "
                    "<Spelling=/home/shijia/Public/testprogram/"
                    "s_ceil.c_e.c:39:31>");
        AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&x,
                "/home/shijia/Public/testprogram/s_ceil.c_e.c:55:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_0;
      }
      /* x is integral */
      math_force_eval(hugeval + x); /* raise inexact flag */
      if (i0 > 0) {
        i0 += IC(0x00100000) >> j0;
      }

      i0 &= (~i);
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
                    "/home/shijia/Public/testprogram/s_ceil.c_e.c:62:7 "
                    "<Spelling=/home/shijia/Public/testprogram/"
                    "s_ceil.c_e.c:62:31>");
        computeDAdd((Addr)&temp_var_for_tac_3,
                    {(Addr) &(temp_var_for_const_3 = hugeval), (Addr)&x},
                    "/home/shijia/Public/testprogram/s_ceil.c_e.c:62:7 "
                    "<Spelling=/home/shijia/Public/testprogram/"
                    "s_ceil.c_e.c:62:31>");
        computeDAdd((Addr)&temp_var_for_tac_4, {(Addr)&x, (Addr)&x},
                    "/home/shijia/Public/testprogram/s_ceil.c_e.c:74:32");
        AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_4,
                "/home/shijia/Public/testprogram/s_ceil.c_e.c:74:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_1;
      }
      /* inf or NaN */
      else {
        double temp_var_for_ext_2;
        temp_var_for_ext_2 = x;
        AssignD({(Addr)&temp_var_for_ext_2}, (Addr)&x,
                "/home/shijia/Public/testprogram/s_ceil.c_e.c:83:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_2;
      }
      /* x is integral */
    } else {
      i = UC(0xffffffff) >> (j0 - IEEE754_DOUBLE_SHIFT);
      if ((i1 & i) == 0) {
        double temp_var_for_ext_3;
        temp_var_for_ext_3 = x;
        AssignD({(Addr)&temp_var_for_ext_3}, (Addr)&x,
                "/home/shijia/Public/testprogram/s_ceil.c_e.c:94:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_3;
      }
      /* x is integral */
      math_force_eval(hugeval + x); /* raise inexact flag */
      if (i0 > 0) {
        if (j0 == IEEE754_DOUBLE_SHIFT) {
          i0 += 1;
        }

        else {
          j = i1 + (UC(1) << (52 - j0));
          if (j < i1) {
            i0 += 1;
          }
          /* got a carry */
          i1 = j;
        }
      }
      i1 &= (~i);
    }
  }

  INSERT_WORDS(x, i0, i1);
  double temp_var_for_ext_4;
  temp_var_for_ext_4 = x;
  computeDAdd((Addr)&temp_var_for_tac_5,
              {(Addr) &(temp_var_for_const_4 = hugeval), (Addr)&x},
              "/home/shijia/Public/testprogram/s_ceil.c_e.c:101:7 "
              "<Spelling=/home/shijia/Public/testprogram/s_ceil.c_e.c:101:31>");
  computeDAdd((Addr)&temp_var_for_tac_6,
              {(Addr) &(temp_var_for_const_5 = hugeval), (Addr)&x},
              "/home/shijia/Public/testprogram/s_ceil.c_e.c:101:7 "
              "<Spelling=/home/shijia/Public/testprogram/s_ceil.c_e.c:101:31>");
  AssignD({(Addr)&temp_var_for_ext_4}, (Addr)&x,
          "/home/shijia/Public/testprogram/s_ceil.c_e.c:122:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_4;
}

#endif

double __ceil(double x) {
  double temp_var_for_ext_5;
  double temp_var_for_const_6;
  double temp_var_for_callexp_0;

  temp_var_for_callexp_0 = __ieee754_ceil(x);
  temp_var_for_ext_5 = temp_var_for_callexp_0;
  AssignD({(Addr)&temp_var_for_ext_5},
          (Addr) &(temp_var_for_const_6 = temp_var_for_callexp_0),
          "/home/shijia/Public/testprogram/s_ceil.c_e.c:132:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_5;
}

__typeof(__ceil) ceil __attribute__((weak, alias("__ceil")));
#ifdef __NO_LONG_DOUBLE_MATH
long double __ceill(long double x) __attribute__((alias("__ceil")));
__typeof(__ceill) ceill __attribute__((weak, alias("__ceil")));
#endif
