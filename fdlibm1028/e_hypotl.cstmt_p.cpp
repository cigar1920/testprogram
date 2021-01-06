#include "../ScDebug/scdebug.h"
/* e_hypotl.c -- long double version of e_hypot.c.
 * Conversion to long double by Ulrich Drepper,
 * Cygnus Support, drepper@cygnus.com.
 */

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

/* __ieee754_hypotl(x,y)
 *
 * Method :
 *	If (assume round-to-nearest) z=x*x+y*y
 *	has error less than sqrt(2)/2 ulp, than
 *	sqrt(z) has error less than 1 ulp (exercise).
 *
 *	So, compute sqrt(x*x+y*y) with some care as
 *	follows to get the error below 1 ulp:
 *
 *	Assume x>y>0;
 *	(if possible, set rounding to round-to-nearest)
 *	1. if x > 2y  use
 *		x1*x1+(y*y+(x2*(x+x1))) for x*x+y*y
 *	where x1 = x with lower 32 bits cleared, x2 = x-x1; else
 *	2. if x <= 2y use
 *		t1*y1+((x-y)*(x-y)+(t1*y2+t2*y))
 *	where t1 = 2x with lower 32 bits cleared, t2 = 2x-t1,
 *	y1= y with lower 32 bits chopped, y2 = y-y1.
 *
 *	NOTE: scaling may be necessary if some argument is too
 *	      large or too tiny
 *
 * Special cases:
 *	hypot(x,y) is INF if x or y is +INF or -INF; else
 *	hypot(x,y) is NAN if x or y is NAN.
 *
 * Accuracy:
 *	hypot(x,y) returns sqrt(x^2+y^2) with error less
 *	than 1 ulps (units in the last place)
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

#ifndef __have_fpu_hypot

long double __ieee754_hypotl(long double x, long double y) {
  long double a, b, t1, t2, y1, y2, w;
  uint32_t j, k, ea, eb;

  GET_LDOUBLE_EXP(ea, x);
  ea &= 0x7fff;
  GET_LDOUBLE_EXP(eb, y);
  eb &= 0x7fff;
  if (eb > ea) {
    a = y;
    b = x;
    j = ea;
    ea = eb;
    eb = j;
  } else {
    a = x;
    b = y;
  }
  SET_LDOUBLE_EXP(a, ea); /* a <- |a| */
  SET_LDOUBLE_EXP(b, eb); /* b <- |b| */
  if ((ea - eb) > 0x46) {
    return a + b;
  } /* x/y > 2**70 */
  k = 0;
  if (ea > 0x5f3f) {    /* a>2**8000 */
    if (ea == 0x7fff) { /* Inf or NaN */
      uint32_t high, low;

      w = a + b; /* for sNaN */
      GET_LDOUBLE_WORDS(ea, high, low, a);
      if (((high & IC(0x7fffffff)) | low) == 0)
        w = a;
      GET_LDOUBLE_WORDS(eb, high, low, b);
      if (((eb ^ 0x7fff) | (high & IC(0x7fffffff)) | low) == 0)
        w = b;
      return w;
    }
    /* scale a and b by 2**-9600 */
    ea -= 0x2580;
    eb -= 0x2580;
    k += 9600;
    SET_LDOUBLE_EXP(a, ea);
    SET_LDOUBLE_EXP(b, eb);
  }
  if (eb < 0x20bf) { /* b < 2**-8000 */
    if (eb == 0) {   /* subnormal b or 0 */
      uint32_t high, low;

      GET_LDOUBLE_WORDS(eb, high, low, b);
      if ((high | low) == 0)
        return a;
      SET_LDOUBLE_WORDS(t1, 0x7ffd, UC(0x80000000), 0); /* t1=2^16382 */
      b *= t1;
      a *= t1;
      k -= 16382;
      GET_LDOUBLE_EXP(ea, a);
      GET_LDOUBLE_EXP(eb, b);
      if (eb > ea) {
        t1 = a;
        a = b;
        b = t1;
        j = ea;
        ea = eb;
        eb = j;
      }
    } else {        /* scale a and b by 2^9600 */
      ea += 0x2580; /* a *= 2^9600 */
      eb += 0x2580; /* b *= 2^9600 */
      k -= 9600;
      SET_LDOUBLE_EXP(a, ea);
      SET_LDOUBLE_EXP(b, eb);
    }
  }
  /* medium size a and b */
  w = a - b;
  computeLdSub((Addr)&w, {(Addr)&a, (Addr)&b},
               "/home/shijia/Public/testprogram/e_hypotl.c_e.c:131:5");
  if (w > b) {
    uint32_t high;

    GET_LDOUBLE_MSW(high, a);
    SET_LDOUBLE_WORDS(t1, ea, high, 0);
    t2 = a - t1;
    computeLdSub((Addr)&t2, {(Addr)&a, (Addr)&t1},
                 "/home/shijia/Public/testprogram/e_hypotl.c_e.c:137:8");
    w = __ieee754_sqrtl(t1 * t1 - (b * ((0.0 - b)) - t2 * (a + t1)));
    long double temp_var_for_const_0, temp_var_for_const_1;
    long double temp_var_for_tac_0, temp_var_for_tac_1, temp_var_for_tac_2,
        temp_var_for_tac_3, temp_var_for_tac_4, temp_var_for_tac_5,
        temp_var_for_tac_6;
    computeLdSub((Addr)&temp_var_for_tac_6,
                 {(Addr)&temp_var_for_tac_0, (Addr)&temp_var_for_tac_5},
                 "toString(biExpr->getExprLoc())");
    computeLdMul((Addr)&temp_var_for_tac_0, {(Addr)&t1, (Addr)&t1},
                 "/home/shijia/Public/testprogram/e_hypotl.c_e.c:138:46");
    computeLdSub((Addr)&temp_var_for_tac_1,
                 {(Addr) &(temp_var_for_const_0 = 0.0), (Addr)&b},
                 "/home/shijia/Public/testprogram/e_hypotl.c_e.c:138:38");
    computeLdMul((Addr)&temp_var_for_tac_2,
                 {(Addr)&b, (Addr)&temp_var_for_tac_1},
                 "/home/shijia/Public/testprogram/e_hypotl.c_e.c:138:62");
    computeLdAdd((Addr)&temp_var_for_tac_3, {(Addr)&a, (Addr)&t1},
                 "/home/shijia/Public/testprogram/e_hypotl.c_e.c:138:57");
    computeLdMul((Addr)&temp_var_for_tac_4,
                 {(Addr)&t2, (Addr)&temp_var_for_tac_3},
                 "/home/shijia/Public/testprogram/e_hypotl.c_e.c:138:52");
    computeLdSub((Addr)&temp_var_for_tac_5,
                 {(Addr)&temp_var_for_tac_2, (Addr)&temp_var_for_tac_4},
                 "/home/shijia/Public/testprogram/e_hypotl.c_e.c:138:33");AssignLd({(Addr)&w},(Addr)&(temp_var_for_const_1=__ieee754_sqrtl(getFVbyShadow<int>((Addr)&temp_var_for_tac_6)),"/home/shijia/Public/testprogram/e_hypotl.c_e.c:138:7");
  } else {
    uint32_t high;

    GET_LDOUBLE_MSW(high, b);
    long double temp_var_for_ext_0;
    temp_var_for_ext_0 = a + a;
    computeLdAdd((Addr)&temp_var_for_ext_0, {(Addr)&a, (Addr)&a},
                 "/home/shijia/Public/testprogram/e_hypotl.c_e.c:144:24"); // a
    /*(t1)(a)(t2)(b)(b)(b)(t1)(t1)(t1)(t1)(t1)(a)(t2)(b)(b)(b)(b)(b)(b)(t1)(a)(t2)(t1)(a)(a)(a)*/
    a = temp_var_for_ext_0;
    AssignLd({(Addr)&a}, (Addr)&temp_var_for_ext_0,
             "/home/shijia/Public/testprogram/e_hypotl.c_e.c:146:7");
    SET_LDOUBLE_WORDS(y1, eb, high, 0);
    y2 = b - y1;
    computeLdSub((Addr)&y2, {(Addr)&b, (Addr)&y1},
                 "/home/shijia/Public/testprogram/e_hypotl.c_e.c:148:8");
    GET_LDOUBLE_MSW(high, a);
    SET_LDOUBLE_WORDS(t1, ea + 1, high, 0);
    t2 = a - t1;
    computeLdSub((Addr)&t2, {(Addr)&a, (Addr)&t1},
                 "/home/shijia/Public/testprogram/e_hypotl.c_e.c:151:8");
    w = __ieee754_sqrtl(t1 * y1 - (w * ((0.0 - w)) - (t1 * y2 + t2 * b)));
    long double temp_var_for_const_2, temp_var_for_const_3;
    long double temp_var_for_tac_7, temp_var_for_tac_8, temp_var_for_tac_9,
        temp_var_for_tac_10, temp_var_for_tac_11, temp_var_for_tac_12,
        temp_var_for_tac_13, temp_var_for_tac_14;
    computeLdSub((Addr)&temp_var_for_tac_14,
                 {(Addr)&temp_var_for_tac_7, (Addr)&temp_var_for_tac_13},
                 "toString(biExpr->getExprLoc())");
    computeLdMul((Addr)&temp_var_for_tac_7, {(Addr)&t1, (Addr)&y1},
                 "/home/shijia/Public/testprogram/e_hypotl.c_e.c:152:46");
    computeLdSub((Addr)&temp_var_for_tac_8,
                 {(Addr) &(temp_var_for_const_2 = 0.0), (Addr)&w},
                 "/home/shijia/Public/testprogram/e_hypotl.c_e.c:152:38");
    computeLdMul((Addr)&temp_var_for_tac_9,
                 {(Addr)&w, (Addr)&temp_var_for_tac_8},
                 "/home/shijia/Public/testprogram/e_hypotl.c_e.c:152:58");
    computeLdMul((Addr)&temp_var_for_tac_10, {(Addr)&t1, (Addr)&y2},
                 "/home/shijia/Public/testprogram/e_hypotl.c_e.c:152:68");
    computeLdMul((Addr)&temp_var_for_tac_11, {(Addr)&t2, (Addr)&b},
                 "/home/shijia/Public/testprogram/e_hypotl.c_e.c:152:63");
    computeLdAdd((Addr)&temp_var_for_tac_12,
                 {(Addr)&temp_var_for_tac_10, (Addr)&temp_var_for_tac_11},
                 "/home/shijia/Public/testprogram/e_hypotl.c_e.c:152:52");
    computeLdSub((Addr)&temp_var_for_tac_13,
                 {(Addr)&temp_var_for_tac_9, (Addr)&temp_var_for_tac_12},
                 "/home/shijia/Public/testprogram/e_hypotl.c_e.c:152:33");AssignLd({(Addr)&w},(Addr)&(temp_var_for_const_3=__ieee754_sqrtl(getFVbyShadow<int>((Addr)&temp_var_for_tac_14)),"/home/shijia/Public/testprogram/e_hypotl.c_e.c:152:7");
  }
  if (k != 0) {
    return __ieee754_scalbnl(w, (int)k);
  }
  long double temp_var_for_ext_1;
  temp_var_for_ext_1 = w;
  AssignLd({(Addr)&temp_var_for_ext_1}, (Addr)&w,
           "/home/shijia/Public/testprogram/e_hypotl.c_e.c:158:22");
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}
#endif

long double __hypotl(long double x, long double y) {
  long double z = __ieee754_hypotl(x, y);

  if (!isfinite(z) && isfinite(x) && isfinite(y) && _LIB_VERSION != _IEEE_)
    return __kernel_standard_l(x, y, z, KMATHERRL_HYPOT); /* hypot overflow */

  long double temp_var_for_ext_2;
  temp_var_for_ext_2 = z;
  AssignLd({(Addr)&temp_var_for_ext_2}, (Addr)&z,
           "/home/shijia/Public/testprogram/e_hypotl.c_e.c:172:22");
  callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_2;
}

__typeof(__hypotl) hypotl __attribute__((weak, alias("__hypotl")));

#endif
