#include "../ScDebug/scdebug.h"
/* @(#)e_hypot.c 1.3 95/01/18 */
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

/* __ieee754_hypot(x,y)
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
 * 	hypot(x,y) returns sqrt(x^2+y^2) with error less
 * 	than 1 ulps (units in the last place)
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_hypot

double __ieee754_hypot(double x, double y) {
  double a, b, t1, t2, y1, y2, w;
  int32_t j, k, ha, hb;

  GET_HIGH_WORD(ha, x);
  ha &= IC(0x7fffffff);
  GET_HIGH_WORD(hb, y);
  hb &= IC(0x7fffffff);
  if (hb > ha) {
    a = y;
    b = x;
    j = ha;
    ha = hb;
    hb = j;
  } else {
    a = x;
    b = y;
  }
  SET_HIGH_WORD(a, ha); /* a <- |a| */
  SET_HIGH_WORD(b, hb); /* b <- |b| */
  if ((ha - hb) > IC(0x3c00000)) {
    return a + b;
  } /* x/y > 2**60 */
  k = 0;
  if (ha > IC(0x5f300000)) {    /* a>2**500 */
    if (ha >= IC(0x7ff00000)) { /* Inf or NaN */
      uint32_t low;

      w = a + b; /* for sNaN */
      GET_LOW_WORD(low, a);
      if (((ha & IC(0xfffff)) | low) == 0)
        w = a;
      GET_LOW_WORD(low, b);
      if (((hb ^ IC(0x7ff00000)) | low) == 0)
        w = b;
      return w;
    }
    /* scale a and b by 2**-600 */
    ha -= IC(0x25800000);
    hb -= IC(0x25800000);
    k += 600;
    SET_HIGH_WORD(a, ha);
    SET_HIGH_WORD(b, hb);
  }
  if (hb < IC(0x20b00000)) {    /* b < 2**-500 */
    if (hb <= IC(0x000fffff)) { /* subnormal b or 0 */
      uint32_t low;

      GET_LOW_WORD(low, b);
      if ((hb | low) == 0)
        return a;
      t1 = 0;
      SET_HIGH_WORD(t1, IC(0x7fd00000)); /* t1=2^1022 */
      b *= t1;
      a *= t1;
      k -= 1022;
    } else {                /* scale a and b by 2^600 */
      ha += IC(0x25800000); /* a *= 2^600 */
      hb += IC(0x25800000); /* b *= 2^600 */
      k -= 600;
      SET_HIGH_WORD(a, ha);
      SET_HIGH_WORD(b, hb);
    }
  }
  /* medium size a and b */
  w = a - b;
  computeDSub((Addr)&w, {(Addr)&a, (Addr)&b},
              "/home/shijia/Public/testprogram/e_hypot.c_e.c:116:5");
  if (w > b) {
    t1 = 0;
    double temp_var_for_const_0;
    AssignD({(Addr)&t1}, (Addr) &(temp_var_for_const_0 = 0),
            "/home/shijia/Public/testprogram/e_hypot.c_e.c:118:8");
    SET_HIGH_WORD(t1, ha);
    t2 = a - t1;
    computeDSub((Addr)&t2, {(Addr)&a, (Addr)&t1},
                "/home/shijia/Public/testprogram/e_hypot.c_e.c:120:8");
    w = __ieee754_sqrt(t1 * t1 - (b * ((0.0 - b)) - t2 * (a + t1)));
    double temp_var_for_const_1, temp_var_for_const_2;
    double temp_var_for_tac_0, temp_var_for_tac_1, temp_var_for_tac_2,
        temp_var_for_tac_3, temp_var_for_tac_4, temp_var_for_tac_5,
        temp_var_for_tac_6;
    computeDSub((Addr)&temp_var_for_tac_6,
                {(Addr)&temp_var_for_tac_0, (Addr)&temp_var_for_tac_5},
                "toString(biExpr->getExprLoc())");
    computeDMul((Addr)&temp_var_for_tac_0, {(Addr)&t1, (Addr)&t1},
                "/home/shijia/Public/testprogram/e_hypot.c_e.c:121:45");
    computeDSub((Addr)&temp_var_for_tac_1,
                {(Addr) &(temp_var_for_const_1 = 0.0), (Addr)&b},
                "/home/shijia/Public/testprogram/e_hypot.c_e.c:121:37");
    computeDMul((Addr)&temp_var_for_tac_2,
                {(Addr)&b, (Addr)&temp_var_for_tac_1},
                "/home/shijia/Public/testprogram/e_hypot.c_e.c:121:61");
    computeDAdd((Addr)&temp_var_for_tac_3, {(Addr)&a, (Addr)&t1},
                "/home/shijia/Public/testprogram/e_hypot.c_e.c:121:56");
    computeDMul((Addr)&temp_var_for_tac_4,
                {(Addr)&t2, (Addr)&temp_var_for_tac_3},
                "/home/shijia/Public/testprogram/e_hypot.c_e.c:121:51");
    computeDSub((Addr)&temp_var_for_tac_5,
                {(Addr)&temp_var_for_tac_2, (Addr)&temp_var_for_tac_4},
                "/home/shijia/Public/testprogram/e_hypot.c_e.c:121:32");AssignD({(Addr)&w},(Addr)&(temp_var_for_const_2=__ieee754_sqrt(getFVbyShadow<int>((Addr)&temp_var_for_tac_6)),"/home/shijia/Public/testprogram/e_hypot.c_e.c:121:7");
  } else {
    double temp_var_for_ext_0;
    temp_var_for_ext_0 = a + a;
    computeDAdd((Addr)&temp_var_for_ext_0, {(Addr)&a, (Addr)&a},
                "/home/shijia/Public/testprogram/e_hypot.c_e.c:124:24"); // a
    /*(t1)(a)(t2)(b)(b)(b)(t1)(t1)(t1)(t1)(t1)(a)(t2)(b)(b)(b)(b)(b)(b)(t1)(a)(t2)(t1)(a)(a)(a)*/
    a = temp_var_for_ext_0;
    AssignD({(Addr)&a}, (Addr)&temp_var_for_ext_0,
            "/home/shijia/Public/testprogram/e_hypot.c_e.c:126:7");
    y1 = 0;
    double temp_var_for_const_3;
    AssignD({(Addr)&y1}, (Addr) &(temp_var_for_const_3 = 0),
            "/home/shijia/Public/testprogram/e_hypot.c_e.c:127:8");
    SET_HIGH_WORD(y1, hb);
    y2 = b - y1;
    computeDSub((Addr)&y2, {(Addr)&b, (Addr)&y1},
                "/home/shijia/Public/testprogram/e_hypot.c_e.c:129:8");
    t1 = 0;
    double temp_var_for_const_4;
    AssignD({(Addr)&t1}, (Addr) &(temp_var_for_const_4 = 0),
            "/home/shijia/Public/testprogram/e_hypot.c_e.c:130:8");
    SET_HIGH_WORD(t1, ha + IC(0x00100000));
    t2 = a - t1;
    computeDSub((Addr)&t2, {(Addr)&a, (Addr)&t1},
                "/home/shijia/Public/testprogram/e_hypot.c_e.c:132:8");
    w = __ieee754_sqrt(t1 * y1 - (w * ((0.0 - w)) - (t1 * y2 + t2 * b)));
    double temp_var_for_const_5, temp_var_for_const_6;
    double temp_var_for_tac_7, temp_var_for_tac_8, temp_var_for_tac_9,
        temp_var_for_tac_10, temp_var_for_tac_11, temp_var_for_tac_12,
        temp_var_for_tac_13, temp_var_for_tac_14;
    computeDSub((Addr)&temp_var_for_tac_14,
                {(Addr)&temp_var_for_tac_7, (Addr)&temp_var_for_tac_13},
                "toString(biExpr->getExprLoc())");
    computeDMul((Addr)&temp_var_for_tac_7, {(Addr)&t1, (Addr)&y1},
                "/home/shijia/Public/testprogram/e_hypot.c_e.c:133:45");
    computeDSub((Addr)&temp_var_for_tac_8,
                {(Addr) &(temp_var_for_const_5 = 0.0), (Addr)&w},
                "/home/shijia/Public/testprogram/e_hypot.c_e.c:133:37");
    computeDMul((Addr)&temp_var_for_tac_9,
                {(Addr)&w, (Addr)&temp_var_for_tac_8},
                "/home/shijia/Public/testprogram/e_hypot.c_e.c:133:57");
    computeDMul((Addr)&temp_var_for_tac_10, {(Addr)&t1, (Addr)&y2},
                "/home/shijia/Public/testprogram/e_hypot.c_e.c:133:67");
    computeDMul((Addr)&temp_var_for_tac_11, {(Addr)&t2, (Addr)&b},
                "/home/shijia/Public/testprogram/e_hypot.c_e.c:133:62");
    computeDAdd((Addr)&temp_var_for_tac_12,
                {(Addr)&temp_var_for_tac_10, (Addr)&temp_var_for_tac_11},
                "/home/shijia/Public/testprogram/e_hypot.c_e.c:133:51");
    computeDSub((Addr)&temp_var_for_tac_13,
                {(Addr)&temp_var_for_tac_9, (Addr)&temp_var_for_tac_12},
                "/home/shijia/Public/testprogram/e_hypot.c_e.c:133:32");AssignD({(Addr)&w},(Addr)&(temp_var_for_const_6=__ieee754_sqrt(getFVbyShadow<int>((Addr)&temp_var_for_tac_14)),"/home/shijia/Public/testprogram/e_hypot.c_e.c:133:7");
  }
  if (k != 0) {
    return __ieee754_scalbn(w, (int)k);
  }
  double temp_var_for_ext_1;
  temp_var_for_ext_1 = w;
  AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&w,
          "/home/shijia/Public/testprogram/e_hypot.c_e.c:139:22");
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}
#endif

/* wrapper hypot(x,y) */
double __hypot(double x, double y) {
  double z = __ieee754_hypot(x, y);

  if (!isfinite(z) && isfinite(x) && isfinite(y) && _LIB_VERSION != _IEEE_)
    return __kernel_standard(x, y, z, KMATHERR_HYPOT); /* hypot overflow */

  double temp_var_for_ext_2;
  temp_var_for_ext_2 = z;
  AssignD({(Addr)&temp_var_for_ext_2}, (Addr)&z,
          "/home/shijia/Public/testprogram/e_hypot.c_e.c:154:22");
  callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_2;
}

__typeof(__hypot) hypot __attribute__((weak, alias("__hypot")));
#ifdef __NO_LONG_DOUBLE_MATH
long double __hypotl(long double x, long double y)
    __attribute__((alias("__hypot")));
__typeof(__hypotl) hypotl __attribute__((weak, alias("__hypot")));
#endif
