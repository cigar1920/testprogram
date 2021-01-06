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

/* Expansions and modifications for 128-bit long double are
   Copyright (C) 2001 Stephen L. Moshier <moshier@na-net.ornl.gov>
   and are incorporated herein by permission of the author.  The author
   reserves the right to distribute this material elsewhere under different
   copying permissions.  These modifications are distributed here under
   the following terms:

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, see
    <http://www.gnu.org/licenses/>.  */

/* __ieee754_powl(x,y) return x**y
 *
 *		      n
 * Method:  Let x =  2   * (1+f)
 *	1. Compute and return log2(x) in two pieces:
 *		log2(x) = w1 + w2,
 *	   where w1 has 113-53 = 60 bit trailing zeros.
 *	2. Perform y*log2(x) = n+y' by simulating multi-precision
 *	   arithmetic, where |y'|<=0.5.
 *	3. Return x**y = 2**n*exp(y'*log2)
 *
 * Special cases:
 *	1.  (anything) ** 0  is 1
 *	2.  (anything) ** 1  is itself
 *	3a. (anything) ** NAN is NAN except
 *	3b. +1         ** NAN is 1
 *	4.  NAN ** (anything except 0) is NAN
 *	5.  +-(|x| > 1) **  +INF is +INF
 *	6.  +-(|x| > 1) **  -INF is +0
 *	7.  +-(|x| < 1) **  +INF is +0
 *	8.  +-(|x| < 1) **  -INF is +INF
 *	9.  +-1         ** +-INF is 1
 *	10. +0 ** (+anything except 0, NAN)               is +0
 *	11. -0 ** (+anything except 0, NAN, odd integer)  is +0
 *	12. +0 ** (-anything except 0, NAN)               is +INF
 *	13. -0 ** (-anything except 0, NAN, odd integer)  is +INF
 *	14. -0 ** (odd integer) = -( +0 ** (odd integer) )
 *	15. +INF ** (+anything except 0,NAN) is +INF
 *	16. +INF ** (-anything except 0,NAN) is +0
 *	17. -INF ** (anything)  = -0 ** (-anything)
 *	18. (-anything) ** (integer) is (-1)**(integer)*(+anything**integer)
 *	19. (-anything except 0 and inf) ** (non-integer) is NAN
 *
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

#ifndef __have_fpu_pow

long double __ieee754_powl(long double x, long double y) {
  int x_class = fpclassify(x);
  int y_class = fpclassify(y);
  int odd_y;
  long double d, rslt;
  int32_t dexp, yexp;

  if (y_class == FP_ZERO || int temp_var_for_tac_0; int temp_var_for_const_0;
      temp_var_for_tac_0 = x == 1.0L;

      ) {
    /* unless x is signaling NaN */
    if (issignalingl(x)) {
      long double temp_var_for_ext_0;
      long double temp_var_for_const_1;
      long double temp_var_for_callexp_0;

      temp_var_for_callexp_0 = __builtin_nanl("");
      temp_var_for_ext_0 = temp_var_for_callexp_0;
      compute((Addr)&temp_var_for_tac_0,
              {(Addr)&x, (Addr) &(temp_var_for_const_0 = 1.0L)},
              "/home/shijia/Public/testprogram/e_powl.c_e.c:83:31");
      AssignLd({(Addr)&temp_var_for_ext_0},
               (Addr) &(temp_var_for_const_1 = temp_var_for_callexp_0),
               "/home/shijia/Public/testprogram/e_powl.c_e.c:87:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_0;
    }

    long double temp_var_for_ext_1;
    long double temp_var_for_const_2;
    temp_var_for_ext_1 = 1.0L;
    AssignLd({(Addr)&temp_var_for_ext_1}, (Addr) &(temp_var_for_const_2 = 1.0L),
             "/home/shijia/Public/testprogram/e_powl.c_e.c:95:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }

  if (x_class == FP_NAN || y_class == FP_NAN) {
    long double temp_var_for_const_3;
    rslt = signbit(x) ? (0.0 - __builtin_nanl("")) : __builtin_nanl("");
    AssignLd({(Addr)&rslt}, (Addr) &(temp_var_for_const_3 =
                                         signbit(x) ? (0.0 - __builtin_nanl(""))
                                                    : __builtin_nanl("")),
             "/home/shijia/Public/testprogram/e_powl.c_e.c:102:10");
    ;
    long double temp_var_for_ext_2;
    temp_var_for_ext_2 = rslt;
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  }
  if (x_class == FP_ZERO) {
    if (y_class == FP_INFINITE) {
      long double temp_var_for_ext_3;
      temp_var_for_ext_3 = signbit(y) ? HUGE_VALL : 0.0L;
      callExpStack.push(
          getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_3;
    }

    if (signbit(x) && int temp_var_for_tac_1; int temp_var_for_const_4;
        long double temp_var_for_callexp_1;

        temp_var_for_callexp_1 = __ieee754_truncl(y);
        temp_var_for_tac_1 = temp_var_for_callexp_1 != y;

        ) {
      long double temp_var_for_ext_4;
      long double temp_var_for_const_5;
      temp_var_for_ext_4 = signbit(y) ? (1.0 / -x) : 0.0L;
      compute(
          (Addr)&temp_var_for_tac_1,
          {(Addr) &(temp_var_for_const_4 = temp_var_for_callexp_1), (Addr)&y},
          "/home/shijia/Public/testprogram/e_powl.c_e.c:119:43");
      AssignLd({(Addr)&temp_var_for_ext_4},
               (Addr) &(temp_var_for_const_5 = signbit(y) ? (1.0 / -x) : 0.0L),
               "/home/shijia/Public/testprogram/e_powl.c_e.c:121:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var(0.0 - f) or_ext_4;
    }
    d = __ieee754_scalbnl(y, -1);
    odd_y = __ieee754_truncl(d) != d;
    if (!signbit(y)) {
      if (!odd_y || !signbit(x)) {
        long double temp_var_for_ext_5;
        long double temp_var_for_const_6;
        temp_var_for_ext_5 = 0.0L;
        AssignLd({(Addr)&temp_var_for_ext_5},
                 (Addr) &(temp_var_for_const_6 = 0.0L),
                 "/home/shijia/Public/testprogram/e_powl.c_e.c:132:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_5;
      }

      long double temp_var_for_ext_6;
      long double temp_var_for_const_7;
      temp_var_for_ext_6 = (-(0.0L));
      AssignLd({(Addr)&temp_var_for_ext_6},
               (Addr) &(temp_var_for_const_7 = (-(0.0L))),
               "/home/shijia/Public/testprogram/e_powl.c_e.c:140:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
      callExp++; /*identify the function is  add move tmpShadow*/
      return (0.0 - xt_6);
    }

    feraiseexcept(FE_DIVBYZERO);
    if (!odd_y || !signbit(x)) {
      long double temp_var_for_ext_7;
      long double temp_var_for_const_8;
      long double temp_var_for_callexp_2;

      temp_var_for_callexp_2 = __builtin_huge_vall();
      temp_var_for_ext_7 = temp_var_for_callexp_2;
      AssignLd({(Addr)&temp_var_for_ext_7},
               (Addr) &(temp_var_for_const_8 = temp_var_for_callexp_2),
               "/home/shijia/Public/testprogram/e_powl.c_e.c:150:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_7;
    }

    long double temp_var_for_ext_8;
    long double temp_var_for_const_9;
    temp_var_for_ext_8 = signbit(x) ? -HUGE_VALL : HUGE_VALL;
    AssignLd(
        {(Addr)&temp_var_for_ext_8},
        (Addr) &(temp_var_for_const_9 = signbit(x) ? -HUGE_VALL : HUGE_VALL),
        "/home/shijia/Public/testprogram/e_powl.c_e.c:158:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
    callExp++; /*identify the function is  add move tmpShadow*/
    ret(0.0 - rn temp_v) ar_for_ext_8;
  }
  if (y_class == FP_INFINITE) {
    long double a_x;

    if (x_class == FP_INFINITE) {
      long double temp_var_for_ext_9;
      temp_var_for_ext_9 = (signbit(y) ? 0.0L : HUGE_VALL);
      callExpStack.push(
          getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_9;
    }

    a_x = (signbit(x) ? (long double temp_var_for_tac_2;
                         long double temp_var_for_const_10;
                         temp_var_for_tac_2 = 0.0 - x;

                         )
                      : x);
    if (int temp_var_for_tac_3; int temp_var_for_const_11;
        temp_var_for_tac_3 = a_x == 1.0L;

        ) {
      long double temp_var_for_ext_10;
      long double temp_var_for_const_12;
      temp_var_for_ext_10 = 1.0L;
      computeLdSub((Addr)&temp_var_for_tac_2,
                   {(Addr) &(temp_var_for_const_10 = 0.0), (Addr)&x},
                   "/home/shijia/Public/testprogram/e_powl.c_e.c:175:30");
      compute((Addr)&temp_var_for_tac_3,
              {(Addr)&a_x, (Addr) &(temp_var_for_const_11 = 1.0L)},
              "/home/shijia/Public/testprogram/e_powl.c_e.c:176:13");
      AssignLd({(Addr)&temp_var_for_ext_10},
               (Addr) &(temp_var_for_const_12 = 1.0L),
               "/home/shijia/Public/testprogram/e_powl.c_e.c:178:27");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_10", (Addr)&temp_var_for_ext_10));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_10;
    }

    if (int temp_var_for_tac_4; int temp_var_for_const_13;
        temp_var_for_tac_4 = a_x > 1.0;

        ) {
      long double temp_var_for_ext_11;
      long double temp_var_for_const_14;
      temp_var_for_ext_11 = signbit(y) == 0 ? HUGE_VALL : 0.0L;
      compute((Addr)&temp_var_for_tac_4,
              {(Addr)&a_x, (Addr) &(temp_var_for_const_13 = 1.0)},
              "/home/shijia/Public/testprogram/e_powl.c_e.c:185:13");
      AssignLd(
          {(Addr)&temp_var_for_ext_11},
          (Addr) &(temp_var_for_const_14 = signbit(y) == 0 ? HUGE_VALL : 0.0L),
          "/home/shijia/Public/testprogram/e_powl.c_e.c:187:27");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_11", (Addr)&temp_var_for_ext_11));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_11;
    }

    long double temp_var_for_ext_12;
    temp_var_for_ext_12 = (!signbit(y) ? 0.0L : HUGE_VALL);
    callExpStack.push(
        getReal("temp_var_for_ext_12", (Addr)&temp_var_for_ext_12));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_12;
  }
  if (x_class == FP_INFINITE) {
    /* pow (x, y) signals the invalid operation exception for finite x < 0 and
     * finite non-integer y.  */
    if (signbit(x) && __ieee754_truncl(y) != y) {
      long double temp_var_for_ext_13;
      temp_var_for_ext_13 = signbit(y) ? long double temp_var_for_tac_5;
      long double temp_var_for_const_15, temp_var_for_const_16;
      temp_var_for_tac_5 = 1.0 / (-(x));

 : -x;
 callExpStack.push(getReal("temp_var_for_ext_13", (Addr)&temp_var_for_ext_13));
 callExp++; /*identify the function is  add move tmpShadow*/
 return temp_var_for(0.0 - e) xt_(0.0 - 3);
    }
    long double temp_var_for_const_17;
    long double temp_var_for_callexp_3;

    temp_var_for_callexp_3 = __ieee754_scalbnl(y, (-(1)));
    d = temp_var_for_callexp_3;
    computeLdDiv((Addr)&temp_var_for_tac_5,
                 {(Addr) &(temp_var_for_const_16 = 1.0),
                  (Addr) &(temp_var_for_const_15 = (-(x)))},
                 "/home/shijia/Public/testprogram/e_powl.c_e.c:206:46");
    AssignLd({(Addr)&d},
             (Addr) &(temp_var_for_const_17 = temp_var_for_callexp_3),
             "/home/shijia/Public/testprogram/e_powl.c_e.c:212:7");
    ;
    odd_y = int temp_var_for_tac_6;
    int temp_var_for_const_18;
    long double temp_var_for_callexp_4;

    temp_var_for_callexp_4 = __ieee754_truncl(d);
    temp_var_for_tac_6 = temp_var_for_callexp_4 != d;

    ;
    /* pow( -inf, y) = +0 for y<0 and not an odd integer,  */
    if (signbit(x) && signbit(y) && !odd_y) {
      long double temp_var_for_ext_14;
      long double temp_var_for_const_19;
      temp_var_for_ext_14 = 0.0L;
      compute(
          (Addr)&temp_var_for_tac_6,
          {(Addr) &(temp_var_for_const_18 = temp_var_for_callexp_4), (Addr)&d},
          "/home/shijia/Public/testprogram/e_powl.c_e.c:213:33");
      AssignLd({(Addr)&temp_var_for_ext_14},
               (Addr) &(temp_var_for_const_19 = 0.0L),
               "/home/shijia/Public/testprogram/e_powl.c_e.c:217:27");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_14", (Addr)&temp_var_for_ext_14));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_14;
    }

    /* pow( -inf, y) = -inf for y an odd integer > 0.  */
    if (signbit(x) && !signbit(y) && odd_y) {
      long double temp_var_for_ext_15;
      long double temp_var_for_const_20;
      temp_var_for_callexp_5 = __builtin_huge_vall();
      temp_var_for_ext_15 = (-(temp_var_for_callexp_5));
      AssignLd({(Addr)&temp_var_for_ext_15},
               (Addr) &(temp_var_for_const_20 = (-(temp_var_for_callexp_5))),
               "/home/shijia/Public/testprogram/e_powl.c_e.c:227:27");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_15", (Addr)&temp_var_for_ext_15));
      callExp++; /*identify the function is  add move tmpShadow*/
      return (0.0 - or_ext_15);
    }

    /* pow( -inf, y) = +inf for y>0 and not an odd integer.  */
    if (signbit(x) && !signbit(y) && !odd_y) {
      long double temp_var_for_ext_16;
      long double temp_var_for_const_21;
      long double temp_var_for_callexp_6;

      temp_var_for_callexp_6 = __builtin_huge_vall();
      temp_var_for_ext_16 = temp_var_for_callexp_6;
      AssignLd({(Addr)&temp_var_for_ext_16},
               (Addr) &(temp_var_for_const_21 = temp_var_for_callexp_6),
               "/home/shijia/Public/testprogram/e_powl.c_e.c:237:27");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_16", (Addr)&temp_var_for_ext_16));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_16;
    }

    /* pow (+/-inf, y) is +/-0 with no exception for y an odd integer < 0. */
    if (signbit(y)) {
      /* pow (+/-inf, y) is +0 with no exception for finite y < 0 and not an odd
       * integer.  */
      long double temp_var_for_ext_17;
      long double temp_var_for_const_22;
      temp_var_for_ext_17 = (odd_y && signbit(x)) ? -0.0L : 0.0L;
      AssignLd({(Addr)&temp_var_for_ext_17},
               (Addr) &(temp_var_for_const_22 =
                            (odd_y && signbit(x)) ? -0.0L : 0.0L),
               "/home/shijia/Public/testprogram/e_powl.c_e.c:249:27");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_17", (Addr)&temp_var_for_ext_17));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_va(0.0 - _for) _ext_17;
    }
    /* pow (+/-inf, y) is +/-inf with no exception for finite y > 0 an odd
     * integer.  */
    /* pow (+/-inf, y) is +inf with no exception for finite y > 0 and not an odd
     * integer.  */
    long double temp_var_for_ext_18;
    temp_var_for_ext_18 = (odd_y && signbit(x) ? -HUGE_VALL : HUGE_VALL);
    callExpStack.push(
        getReal("temp_var_for_ext_18", (Addr)&temp_var_for_ext_18));
    callExp++; /*identify the function is  add move tmpShadow*/
    ret(0.0 - rn temp_v) ar_for_ext_18;
  }

  d = __ieee754_truncl(y);
  if (d != y) {
    if (signbit(x)) {
      long double temp_var_for_ext_19;
      long double temp_var_for_const_23;
      temp_var_for_callexp_7 = __builtin_nanl("");
      temp_var_for_ext_19 = (-(temp_var_for_callexp_7));
      AssignLd({(Addr)&temp_var_for_ext_19},
               (Addr) &(temp_var_for_const_23 = (-(temp_var_for_callexp_7))),
               "/home/shijia/Public/testprogram/e_powl.c_e.c:271:27");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_19", (Addr)&temp_var_for_ext_19));
      callExp++; /*identify the function is  add move tmpShadow*/
      return (0.0 - emp_var_for_ext_19);
    }
    if (int temp_var_for_tac_7; int temp_var_for_const_24;
        temp_var_for_tac_7 = y == 0.5L;

        ) {
      long double temp_var_for_ext_20;
      long double temp_var_for_const_25;
      long double temp_var_for_callexp_8;

      temp_var_for_callexp_8 = __ieee754_sqrtl(x);
      temp_var_for_ext_20 = temp_var_for_callexp_8;
      compute((Addr)&temp_var_for_tac_7,
              {(Addr)&y, (Addr) &(temp_var_for_const_24 = 0.5L)},
              "/home/shijia/Public/testprogram/e_powl.c_e.c:277:11");
      AssignLd({(Addr)&temp_var_for_ext_20},
               (Addr) &(temp_var_for_const_25 = temp_var_for_callexp_8),
               "/home/shijia/Public/testprogram/e_powl.c_e.c:279:27");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_20", (Addr)&temp_var_for_ext_20));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_20;
    }
  } else {
    if
  }
  ((d <= (long double)INT_MAX && d >= (long double)INT_MIN)) {
    return __ieee754_powil(x, (int)y);
  }
  /* As exp already checks for minlog and maxlog no further checks are
   * necessary.  */
  d = __ieee754_log2l(__ieee754_fabsl(x));
  dexp = __ieee754_ilogbl(d);
  yexp = __ieee754_ilogbl(y);
  if (dexp > 0 && (yexp + dexp) >= LDBL_MAX_EXP) {
    dexp = __ieee754_ilogbl(x);
    if ((dexp < 0 && y < 0.0L) || (dexp > 0 && y > 0.0L)) {
      feraiseexcept(FE_OVERFLOW);
      rslt = HUGE_VALL;
    } else {
      feraiseexcept(FE_UNDERFLOW);
      rslt = 0;
    }
  } else if (dexp < 0 && y > 0.0L && (-yexp + dexp) < LDBL_MIN_EXP) {
    feraiseexcept(FE_UNDERFLOW);
    if ((-yexp + dexp) >= (LDBL_MIN_EXP - LDBL_MANT_DIG))
      rslt = 1.0L;
    else
      rslt = 0;
  } else {
    rslt = __ieee754_exp2l(y * d);
  }

  if (signbit(x)) {
    long double temp_var_for_const_26;
    long double temp_var_for_callexp_9;

    temp_var_for_callexp_9 = __ieee754_scalbnl(y, (-(1)));
    y = temp_var_for_callexp_9;
    AssignLd({(Addr)&y},
             (Addr) &(temp_var_for_const_26 = temp_var_for_callexp_9),
             "/home/shijia/Public/testprogram/e_powl.c_e.c:316:7");
    ;
    if (int temp_var_for_tac_8; int temp_var_for_const_27;
        long double temp_var_for_callexp_10;

        temp_var_for_callexp_10 = __ieee754_truncl(y);
        temp_var_for_tac_8 = y != temp_var_for_callexp_10;

        ) {
      long double temp_var_for_ext_21;
      long double temp_var_for_tac_9;
      long double temp_var_for_const_28;
      temp_var_for_tac_9 = 0.0 - rslt;

      temp_var_for_ext_21 = temp_var_for_tac_9;
      compute(
          (Addr)&temp_var_for_tac_8,
          {(Addr)&y, (Addr) &(temp_var_for_const_27 = temp_var_for_callexp_10)},
          "/home/shijia/Public/testprogram/e_powl.c_e.c:317:11");
      computeLdSub((Addr)&temp_var_for_tac_9,
                   {(Addr) &(temp_var_for_const_28 = 0.0), (Addr)&rslt},
                   "/home/shijia/Public/testprogram/e_powl.c_e.c:319:34");
      AssignLd({(Addr)&temp_var_for_ext_21}, (Addr)&temp_var_for_tac_9,
               "/home/shijia/Public/testprogram/e_powl.c_e.c:319:27");
      ; // rslt
      /*(rslt)(rslt)*/
      rslt = temp_var_for_ext_21;
      AssignLd({(Addr)&rslt}, (Addr)&temp_var_for_ext_21,
               "/home/shijia/Public/testprogram/e_powl.c_e.c:321:12");
      ;
    }
  }
  long double temp_var_for_ext_22;
  temp_var_for_ext_22 = rslt;
  AssignLd({(Addr)&temp_var_for_ext_22}, (Addr)&rslt,
           "/home/shijia/Public/testprogram/e_powl.c_e.c:325:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_22", (Addr)&temp_var_for_ext_22));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_22;
}

#endif

/* wrapper powl */
long double __powl(long double x, long double y) {
  long double z = __ieee754_powl(x, y);

  if (!isfinite(z)) {
    if (_LIB_VERSION != _IEEE_) {
      if (isnan(x)) {
        if (y == 0.0L)
          /* pow(NaN,0.0) */
          return __kernel_standard_l(x, y, z, KMATHERRL_POW_NAN);
      } else if (isfinite(x) && isfinite(y)) {
        if (isnan(z)) {
          /* pow neg**non-int */
          return __kernel_standard_l(x, y, z, KMATHERRL_POW_NONINT);
        } else if (x == 0.0L && y < 0.0L) {
          if (signbit(x) && signbit(z))
            /* pow(-0.0,negative) */
            return __kernel_standard_l(x, y, z, KMATHERRL_POW_MINUS);
          else
            /* pow(+0.0,negative) */
            return __kernel_standard_l(x, y, z, KMATHERRL_POW_ZEROMINUS);
        } else {
          /* pow overflow */
          return __kernel_standard_l(x, y, z, KMATHERRL_POW_OVERFLOW);
        }
      }
    }
  } else {
    if
  }
  (z == 0.0L && isfinite(x) && isfinite(y) && _LIB_VERSION != _IEEE_) {
    if (x == 0.0L) {
      if (y == 0.0L)
        /* pow(0.0,0.0) */
        return __kernel_standard_l(x, y, z, KMATHERRL_POW_ZERO);
    } else {
      /* pow underflow */
      return __kernel_standard_l(x, y, z, KMATHERRL_POW_UNDERFLOW);
    }
  }

  return z;
}

__typeof(__powl) powl __attribute__((weak, alias("__powl")));

#endif
