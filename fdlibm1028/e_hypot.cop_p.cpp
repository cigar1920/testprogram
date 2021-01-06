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
    AssignD({(Addr)&a}, (Addr)&y,
            "/home/shijia/Public/testprogram/e_hypot.c_e.c:60:7");
    ;
    b = x;
    AssignD({(Addr)&b}, (Addr)&x,
            "/home/shijia/Public/testprogram/e_hypot.c_e.c:61:7");
    ;
    j = ha;
    ha = hb;
    hb = j;
  } else {
    a = x;
    AssignD({(Addr)&a}, (Addr)&x,
            "/home/shijia/Public/testprogram/e_hypot.c_e.c:66:7");
    ;
    b = y;
    AssignD({(Addr)&b}, (Addr)&y,
            "/home/shijia/Public/testprogram/e_hypot.c_e.c:67:7");
    ;
  }
  SET_HIGH_WORD(a, ha); /* a <- |a| */
  SET_HIGH_WORD(b, hb); /* b <- |b| */
  if ((ha - hb) > IC(0x3c00000)) {
    double temp_var_for_ext_0;
    double temp_var_for_tac_0;
    temp_var_for_tac_0 = a + b;

    temp_var_for_ext_0 = temp_var_for_tac_0;
    computeDAdd((Addr)&temp_var_for_tac_0, {(Addr)&a, (Addr)&b},
                "/home/shijia/Public/testprogram/e_hypot.c_e.c:73:28");
    AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_0,
            "/home/shijia/Public/testprogram/e_hypot.c_e.c:73:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  } /* x/y > 2**60 */
  k = 0;
  if (ha > IC(0x5f300000)) {    /* a>2**500 */
    if (ha >= IC(0x7ff00000)) { /* Inf or NaN */
      uint32_t low;

      double temp_var_for_tac_1;
      temp_var_for_tac_1 = a + b;

      w = temp_var_for_tac_1;
      computeDAdd((Addr)&temp_var_for_tac_1, {(Addr)&a, (Addr)&b},
                  "/home/shijia/Public/testprogram/e_hypot.c_e.c:83:13");
      AssignD({(Addr)&w}, (Addr)&temp_var_for_tac_1,
              "/home/shijia/Public/testprogram/e_hypot.c_e.c:83:9");
      ; /* for sNaN */
      GET_LOW_WORD(low, a);
      if (((ha & IC(0xfffff)) | low) == 0) {
        w = a;
        AssignD({(Addr)&w}, (Addr)&a,
                "/home/shijia/Public/testprogram/e_hypot.c_e.c:86:11");
        ;
      }

      GET_LOW_WORD(low, b);
      if (((hb ^ IC(0x7ff00000)) | low) == 0) {
        w = b;
        AssignD({(Addr)&w}, (Addr)&b,
                "/home/shijia/Public/testprogram/e_hypot.c_e.c:91:11");
        ;
      }

      double temp_var_for_ext_1;
      temp_var_for_ext_1 = w;
      AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&w,
              "/home/shijia/Public/testprogram/e_hypot.c_e.c:95:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_1;
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
      if ((hb | low) == 0) {
        double temp_var_for_ext_2;
        temp_var_for_ext_2 = a;
        AssignD({(Addr)&temp_var_for_ext_2}, (Addr)&a,
                "/home/shijia/Public/testprogram/e_hypot.c_e.c:115:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_2;
      }

      double temp_var_for_const_0;
      t1 = 0;
      AssignD({(Addr)&t1}, (Addr) &(temp_var_for_const_0 = 0),
              "/home/shijia/Public/testprogram/e_hypot.c_e.c:122:10");
      ;
      SET_HIGH_WORD(t1, IC(0x7fd00000)); /* t1=2^1022 */
      b *= t1;
      ;
      a *= t1;
      ;
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
  double temp_var_for_tac_4;
  temp_var_for_tac_4 = a - b;

  w = temp_var_for_tac_4;
  computeDSub((Addr)&temp_var_for_tac_4, {(Addr)&a, (Addr)&b},
              "/home/shijia/Public/testprogram/e_hypot.c_e.c:136:9");
  AssignD({(Addr)&w}, (Addr)&temp_var_for_tac_4,
          "/home/shijia/Public/testprogram/e_hypot.c_e.c:136:5");
  ;
  if (int temp_var_for_tac_5; temp_var_for_tac_5 = w > b;

      ) {
    double temp_var_for_const_1;
    t1 = 0;
    compute((Addr)&temp_var_for_tac_5, {(Addr)&w, (Addr)&b},
            "/home/shijia/Public/testprogram/e_hypot.c_e.c:137:9");
    AssignD({(Addr)&t1}, (Addr) &(temp_var_for_const_1 = 0),
            "/home/shijia/Public/testprogram/e_hypot.c_e.c:138:8");
    ;
    SET_HIGH_WORD(t1, ha);
    double temp_var_for_tac_6;
    temp_var_for_tac_6 = a - t1;

    t2 = temp_var_for_tac_6;
    computeDSub((Addr)&temp_var_for_tac_6, {(Addr)&a, (Addr)&t1},
                "/home/shijia/Public/testprogram/e_hypot.c_e.c:140:12");
    AssignD({(Addr)&t2}, (Addr)&temp_var_for_tac_6,
            "/home/shijia/Public/testprogram/e_hypot.c_e.c:140:8");
    ;
    double temp_var_for_tac_7, temp_var_for_tac_8, temp_var_for_tac_9,
        temp_var_for_tac_10, temp_var_for_tac_11, temp_var_for_tac_12,
        temp_var_for_tac_13;
    double temp_var_for_const_2, temp_var_for_const_3;
    double temp_var_for_callexp_0;

    temp_var_for_tac_7 = t1 * t1;

    temp_var_for_tac_8 = 0.0 - b;

    temp_var_for_tac_9 = b * temp_var_for_tac_8;

    temp_var_for_tac_10 = a + t1;

    temp_var_for_tac_11 = t2 * temp_var_for_tac_10;

    temp_var_for_tac_12 = temp_var_for_tac_9 - temp_var_for_tac_11;

    temp_var_for_tac_13 = temp_var_for_tac_7 - temp_var_for_tac_12;

    temp_var_for_callexp_0 = __ieee754_sqrt(temp_var_for_tac_13);
    w = temp_var_for_callexp_0;
    computeDMul((Addr)&temp_var_for_tac_7, {(Addr)&t1, (Addr)&t1},
                "/home/shijia/Public/testprogram/e_hypot.c_e.c:141:27");
    computeDSub((Addr)&temp_var_for_tac_8,
                {(Addr) &(temp_var_for_const_2 = 0.0), (Addr)&b},
                "/home/shijia/Public/testprogram/e_hypot.c_e.c:141:45");
    computeDMul((Addr)&temp_var_for_tac_9,
                {(Addr)&b, (Addr)&temp_var_for_tac_8},
                "/home/shijia/Public/testprogram/e_hypot.c_e.c:141:37");
    computeDAdd((Addr)&temp_var_for_tac_10, {(Addr)&a, (Addr)&t1},
                "/home/shijia/Public/testprogram/e_hypot.c_e.c:141:61");
    computeDMul((Addr)&temp_var_for_tac_11,
                {(Addr)&t2, (Addr)&temp_var_for_tac_10},
                "/home/shijia/Public/testprogram/e_hypot.c_e.c:141:56");
    computeDSub((Addr)&temp_var_for_tac_12,
                {(Addr)&temp_var_for_tac_9, (Addr)&temp_var_for_tac_11},
                "/home/shijia/Public/testprogram/e_hypot.c_e.c:141:51");
    computeDSub((Addr)&temp_var_for_tac_13,
                {(Addr)&temp_var_for_tac_7, (Addr)&temp_var_for_tac_12},
                "/home/shijia/Public/testprogram/e_hypot.c_e.c:141:32");
    AssignD({(Addr)&w}, (Addr) &(temp_var_for_const_3 = temp_var_for_callexp_0),
            "/home/shijia/Public/testprogram/e_hypot.c_e.c:141:7");
    ;
  } else {
    double temp_var_for_ext_3;
    double temp_var_for_tac_14;
    temp_var_for_tac_14 = a + a;

    temp_var_for_ext_3 = temp_var_for_tac_14;
    computeDAdd((Addr)&temp_var_for_tac_14, {(Addr)&a, (Addr)&a},
                "/home/shijia/Public/testprogram/e_hypot.c_e.c:144:28");
    AssignD({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_14,
            "/home/shijia/Public/testprogram/e_hypot.c_e.c:144:24");
    ; // a
    /*(t1)(a)(t2)(b)(b)(b)(t1)(t1)(t1)(t1)(t1)(a)(t2)(b)(b)(b)(b)(b)(b)(t1)(a)(t2)(t1)(a)(a)(a)*/
    a = temp_var_for_ext_3;
    AssignD({(Addr)&a}, (Addr)&temp_var_for_ext_3,
            "/home/shijia/Public/testprogram/e_hypot.c_e.c:146:7");
    ;
    double temp_var_for_const_4;
    y1 = 0;
    AssignD({(Addr)&y1}, (Addr) &(temp_var_for_const_4 = 0),
            "/home/shijia/Public/testprogram/e_hypot.c_e.c:147:8");
    ;
    SET_HIGH_WORD(y1, hb);
    double temp_var_for_tac_15;
    temp_var_for_tac_15 = b - y1;

    y2 = temp_var_for_tac_15;
    computeDSub((Addr)&temp_var_for_tac_15, {(Addr)&b, (Addr)&y1},
                "/home/shijia/Public/testprogram/e_hypot.c_e.c:149:12");
    AssignD({(Addr)&y2}, (Addr)&temp_var_for_tac_15,
            "/home/shijia/Public/testprogram/e_hypot.c_e.c:149:8");
    ;
    double temp_var_for_const_5;
    t1 = 0;
    AssignD({(Addr)&t1}, (Addr) &(temp_var_for_const_5 = 0),
            "/home/shijia/Public/testprogram/e_hypot.c_e.c:150:8");
    ;
    SET_HIGH_WORD(t1, ha + IC(0x00100000));
    double temp_var_for_tac_16;
    temp_var_for_tac_16 = a - t1;

    t2 = temp_var_for_tac_16;
    computeDSub((Addr)&temp_var_for_tac_16, {(Addr)&a, (Addr)&t1},
                "/home/shijia/Public/testprogram/e_hypot.c_e.c:152:12");
    AssignD({(Addr)&t2}, (Addr)&temp_var_for_tac_16,
            "/home/shijia/Public/testprogram/e_hypot.c_e.c:152:8");
    ;
    double temp_var_for_tac_17, temp_var_for_tac_18, temp_var_for_tac_19,
        temp_var_for_tac_20, temp_var_for_tac_21, temp_var_for_tac_22,
        temp_var_for_tac_23, temp_var_for_tac_24;
    double temp_var_for_const_6, temp_var_for_const_7;
    double temp_var_for_callexp_1;

    temp_var_for_tac_17 = t1 * y1;

    temp_var_for_tac_18 = 0.0 - w;

    temp_var_for_tac_19 = w * temp_var_for_tac_18;

    temp_var_for_tac_20 = t1 * y2;

    temp_var_for_tac_21 = t2 * b;

    temp_var_for_tac_22 = temp_var_for_tac_20 + temp_var_for_tac_21;

    temp_var_for_tac_23 = temp_var_for_tac_19 - temp_var_for_tac_22;

    temp_var_for_tac_24 = temp_var_for_tac_17 - temp_var_for_tac_23;

    temp_var_for_callexp_1 = __ieee754_sqrt(temp_var_for_tac_24);
    w = temp_var_for_callexp_1;
    computeDMul((Addr)&temp_var_for_tac_17, {(Addr)&t1, (Addr)&y1},
                "/home/shijia/Public/testprogram/e_hypot.c_e.c:153:27");
    computeDSub((Addr)&temp_var_for_tac_18,
                {(Addr) &(temp_var_for_const_6 = 0.0), (Addr)&w},
                "/home/shijia/Public/testprogram/e_hypot.c_e.c:153:45");
    computeDMul((Addr)&temp_var_for_tac_19,
                {(Addr)&w, (Addr)&temp_var_for_tac_18},
                "/home/shijia/Public/testprogram/e_hypot.c_e.c:153:37");
    computeDMul((Addr)&temp_var_for_tac_20, {(Addr)&t1, (Addr)&y2},
                "/home/shijia/Public/testprogram/e_hypot.c_e.c:153:57");
    computeDMul((Addr)&temp_var_for_tac_21, {(Addr)&t2, (Addr)&b},
                "/home/shijia/Public/testprogram/e_hypot.c_e.c:153:67");
    computeDAdd((Addr)&temp_var_for_tac_22,
                {(Addr)&temp_var_for_tac_20, (Addr)&temp_var_for_tac_21},
                "/home/shijia/Public/testprogram/e_hypot.c_e.c:153:62");
    computeDSub((Addr)&temp_var_for_tac_23,
                {(Addr)&temp_var_for_tac_19, (Addr)&temp_var_for_tac_22},
                "/home/shijia/Public/testprogram/e_hypot.c_e.c:153:51");
    computeDSub((Addr)&temp_var_for_tac_24,
                {(Addr)&temp_var_for_tac_17, (Addr)&temp_var_for_tac_23},
                "/home/shijia/Public/testprogram/e_hypot.c_e.c:153:32");
    AssignD({(Addr)&w}, (Addr) &(temp_var_for_const_7 = temp_var_for_callexp_1),
            "/home/shijia/Public/testprogram/e_hypot.c_e.c:153:7");
    ;
  }
  if (k != 0) {
    double temp_var_for_ext_4;
    double temp_var_for_const_8;
    double temp_var_for_callexp_2;

    temp_var_for_callexp_2 = __ieee754_scalbn(w, ((int)k));
    temp_var_for_ext_4 = temp_var_for_callexp_2;
    AssignD({(Addr)&temp_var_for_ext_4},
            (Addr) &(temp_var_for_const_8 = temp_var_for_callexp_2),
            "/home/shijia/Public/testprogram/e_hypot.c_e.c:157:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_4;
  }
  double temp_var_for_ext_5;
  temp_var_for_ext_5 = w;
  AssignD({(Addr)&temp_var_for_ext_5}, (Addr)&w,
          "/home/shijia/Public/testprogram/e_hypot.c_e.c:163:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_5;
}
#endif

/* wrapper hypot(x,y) */
double __hypot(double x, double y) {
  double z = __ieee754_hypot(x, y);

  if (!isfinite(z) && isfinite(x) && isfinite(y) && _LIB_VERSION != _IEEE_) {
    double temp_var_for_ext_6;
    double temp_var_for_const_9;
    double temp_var_for_callexp_3;

    temp_var_for_callexp_3 = __kernel_standard(x, y, z, KMATHERR_HYPOT);
    temp_var_for_ext_6 = temp_var_for_callexp_3;
    AssignD({(Addr)&temp_var_for_ext_6},
            (Addr) &(temp_var_for_const_9 = temp_var_for_callexp_3),
            "/home/shijia/Public/testprogram/e_hypot.c_e.c:176:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_6;
  }
  /* hypot overflow */

  double temp_var_for_ext_7;
  temp_var_for_ext_7 = z;
  AssignD({(Addr)&temp_var_for_ext_7}, (Addr)&z,
          "/home/shijia/Public/testprogram/e_hypot.c_e.c:184:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_7;
}

__typeof(__hypot) hypot __attribute__((weak, alias("__hypot")));
#ifdef __NO_LONG_DOUBLE_MATH
long double __hypotl(long double x, long double y)
    __attribute__((alias("__hypot")));
__typeof(__hypotl) hypotl __attribute__((weak, alias("__hypot")));
#endif
