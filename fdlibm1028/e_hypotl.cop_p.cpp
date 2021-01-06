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

  long double temp_var_for_const_0;
  ge_u.value = x;
  AssignLd({(Addr) &(temp_var_for_const_0 = ge_u.value)}, (Addr)&x,
           "/home/shijia/Public/testprogram/e_hypotl.c_e.c:61:3 "
           "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:258:14>");
  ;
  ea &= 0x7fff;
  long double temp_var_for_const_1;
  ge_u.value = y;
  AssignLd({(Addr) &(temp_var_for_const_1 = ge_u.value)}, (Addr)&y,
           "/home/shijia/Public/testprogram/e_hypotl.c_e.c:63:3 "
           "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:258:14>");
  ;
  eb &= 0x7fff;
  if (eb > ea) {
    a = y;
    AssignLd({(Addr)&a}, (Addr)&y,
             "/home/shijia/Public/testprogram/e_hypotl.c_e.c:66:7");
    ;
    b = x;
    AssignLd({(Addr)&b}, (Addr)&x,
             "/home/shijia/Public/testprogram/e_hypotl.c_e.c:67:7");
    ;
    j = ea;
    ea = eb;
    eb = j;
  } else {
    a = x;
    AssignLd({(Addr)&a}, (Addr)&x,
             "/home/shijia/Public/testprogram/e_hypotl.c_e.c:72:7");
    ;
    b = y;
    AssignLd({(Addr)&b}, (Addr)&y,
             "/home/shijia/Public/testprogram/e_hypotl.c_e.c:73:7");
    ;
  }
  long double temp_var_for_ext_0;
  temp_var_for_ext_0; /* a <- |a| */
  long double temp_var_for_ext_1;
  temp_var_for_ext_1; /* b <- |b| */
  if ((ea - eb) > 0x46) {
    long double temp_var_for_ext_2;
    long double temp_var_for_tac_0;
    temp_var_for_tac_0 = a + b;

    temp_var_for_ext_2 = temp_var_for_tac_0;
    computeLdAdd((Addr)&temp_var_for_tac_0, {(Addr)&a, (Addr)&b},
                 "/home/shijia/Public/testprogram/e_hypotl.c_e.c:81:28");
    AssignLd({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_0,
             "/home/shijia/Public/testprogram/e_hypotl.c_e.c:81:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  } /* x/y > 2**70 */
  k = 0;
  if (ea > 0x5f3f) {    /* a>2**8000 */
    if (ea == 0x7fff) { /* Inf or NaN */
      uint32_t high, low;

      long double temp_var_for_tac_1;
      temp_var_for_tac_1 = a + b;

      w = temp_var_for_tac_1;
      computeLdAdd((Addr)&temp_var_for_tac_1, {(Addr)&a, (Addr)&b},
                   "/home/shijia/Public/testprogram/e_hypotl.c_e.c:91:13");
      AssignLd({(Addr)&w}, (Addr)&temp_var_for_tac_1,
               "/home/shijia/Public/testprogram/e_hypotl.c_e.c:91:9");
      ; /* for sNaN */
      long double temp_var_for_const_2;
      ew_u.value = a;
      AssignLd({(Addr) &(temp_var_for_const_2 = ew_u.value)}, (Addr)&a,
               "/home/shijia/Public/testprogram/e_hypotl.c_e.c:92:7 "
               "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
      ;
      if (((high & IC(0x7fffffff)) | low) == 0) {
        w = a;
        AssignLd({(Addr)&w}, (Addr)&a,
                 "/home/shijia/Public/testprogram/e_hypotl.c_e.c:94:11");
        ;
      }

      long double temp_var_for_const_3;
      ew_u.value = b;
      AssignLd({(Addr) &(temp_var_for_const_3 = ew_u.value)}, (Addr)&b,
               "/home/shijia/Public/testprogram/e_hypotl.c_e.c:97:7 "
               "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
      ;
      if (((eb ^ 0x7fff) | (high & IC(0x7fffffff)) | low) == 0) {
        w = b;
        AssignLd({(Addr)&w}, (Addr)&b,
                 "/home/shijia/Public/testprogram/e_hypotl.c_e.c:99:11");
        ;
      }

      long double temp_var_for_ext_3;
      temp_var_for_ext_3 = w;
      AssignLd({(Addr)&temp_var_for_ext_3}, (Addr)&w,
               "/home/shijia/Public/testprogram/e_hypotl.c_e.c:103:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_3;
    }
    /* scale a and b by 2**-9600 */
    ea -= 0x2580;
    eb -= 0x2580;
    k += 9600;
    long double temp_var_for_ext_4;
    temp_var_for_ext_4;
    long double temp_var_for_ext_5;
    temp_var_for_ext_5;
  }
  if (eb < 0x20bf) { /* b < 2**-8000 */
    if (eb == 0) {   /* subnormal b or 0 */
      uint32_t high, low;

      long double temp_var_for_const_4;
      ew_u.value = b;
      AssignLd({(Addr) &(temp_var_for_const_4 = ew_u.value)}, (Addr)&b,
               "/home/shijia/Public/testprogram/e_hypotl.c_e.c:122:7 "
               "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
      ;
      if ((high | low) == 0) {
        long double temp_var_for_ext_6;
        temp_var_for_ext_6 = a;
        AssignLd({(Addr)&temp_var_for_ext_6}, (Addr)&a,
                 "/home/shijia/Public/testprogram/e_hypotl.c_e.c:125:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_6;
      }

      long double temp_var_for_ext_7;
      temp_var_for_ext_7; /* t1=2^16382 */
      b *= t1;
      ;
      a *= t1;
      ;
      k -= 16382;
      long double temp_var_for_const_5;
      ge_u.value = a;
      AssignLd({(Addr) &(temp_var_for_const_5 = ge_u.value)}, (Addr)&a,
               "/home/shijia/Public/testprogram/e_hypotl.c_e.c:137:7 "
               "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:258:14>");
      ;
      long double temp_var_for_const_6;
      ge_u.value = b;
      AssignLd({(Addr) &(temp_var_for_const_6 = ge_u.value)}, (Addr)&b,
               "/home/shijia/Public/testprogram/e_hypotl.c_e.c:138:7 "
               "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:258:14>");
      ;
      if (eb > ea) {
        t1 = a;
        AssignLd({(Addr)&t1}, (Addr)&a,
                 "/home/shijia/Public/testprogram/e_hypotl.c_e.c:140:12");
        ;
        a = b;
        AssignLd({(Addr)&a}, (Addr)&b,
                 "/home/shijia/Public/testprogram/e_hypotl.c_e.c:141:11");
        ;
        b = t1;
        AssignLd({(Addr)&b}, (Addr)&t1,
                 "/home/shijia/Public/testprogram/e_hypotl.c_e.c:142:11");
        ;
        j = ea;
        ea = eb;
        eb = j;
      }
    } else {        /* scale a and b by 2^9600 */
      ea += 0x2580; /* a *= 2^9600 */
      eb += 0x2580; /* b *= 2^9600 */
      k -= 9600;
      long double temp_var_for_ext_8;
      temp_var_for_ext_8;
      long double temp_var_for_ext_9;
      temp_var_for_ext_9;
    }
  }
  /* medium size a and b */
  long double temp_var_for_tac_4;
  temp_var_for_tac_4 = a - b;

  w = temp_var_for_tac_4;
  computeLdSub((Addr)&temp_var_for_tac_4, {(Addr)&a, (Addr)&b},
               "/home/shijia/Public/testprogram/e_hypotl.c_e.c:158:9");
  AssignLd({(Addr)&w}, (Addr)&temp_var_for_tac_4,
           "/home/shijia/Public/testprogram/e_hypotl.c_e.c:158:5");
  ;
  if (int temp_var_for_tac_5; temp_var_for_tac_5 = w > b;

      ) {
    uint32_t high;

    long double temp_var_for_const_7;
    sh_u.value = a;
    compute((Addr)&temp_var_for_tac_5, {(Addr)&w, (Addr)&b},
            "/home/shijia/Public/testprogram/e_hypotl.c_e.c:159:9");
    AssignLd({(Addr) &(temp_var_for_const_7 = sh_u.value)}, (Addr)&a,
             "/home/shijia/Public/testprogram/e_hypotl.c_e.c:162:5 "
             "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:220:14>");
    ;
    long double temp_var_for_ext_10;
    temp_var_for_ext_10;
    long double temp_var_for_tac_6;
    temp_var_for_tac_6 = a - t1;

    t2 = temp_var_for_tac_6;
    computeLdSub((Addr)&temp_var_for_tac_6, {(Addr)&a, (Addr)&t1},
                 "/home/shijia/Public/testprogram/e_hypotl.c_e.c:165:12");
    AssignLd({(Addr)&t2}, (Addr)&temp_var_for_tac_6,
             "/home/shijia/Public/testprogram/e_hypotl.c_e.c:165:8");
    ;
    long double temp_var_for_tac_7, temp_var_for_tac_8, temp_var_for_tac_9,
        temp_var_for_tac_10, temp_var_for_tac_11, temp_var_for_tac_12,
        temp_var_for_tac_13;
    long double temp_var_for_const_8, temp_var_for_const_9;
    long double temp_var_for_callexp_0;

    temp_var_for_tac_7 = t1 * t1;

    temp_var_for_tac_8 = 0.0 - b;

    temp_var_for_tac_9 = b * temp_var_for_tac_8;

    temp_var_for_tac_10 = a + t1;

    temp_var_for_tac_11 = t2 * temp_var_for_tac_10;

    temp_var_for_tac_12 = temp_var_for_tac_9 - temp_var_for_tac_11;

    temp_var_for_tac_13 = temp_var_for_tac_7 - temp_var_for_tac_12;

    temp_var_for_callexp_0 = __ieee754_sqrtl(temp_var_for_tac_13);
    w = temp_var_for_callexp_0;
    computeLdMul((Addr)&temp_var_for_tac_7, {(Addr)&t1, (Addr)&t1},
                 "/home/shijia/Public/testprogram/e_hypotl.c_e.c:166:28");
    computeLdSub((Addr)&temp_var_for_tac_8,
                 {(Addr) &(temp_var_for_const_8 = 0.0), (Addr)&b},
                 "/home/shijia/Public/testprogram/e_hypotl.c_e.c:166:46");
    computeLdMul((Addr)&temp_var_for_tac_9,
                 {(Addr)&b, (Addr)&temp_var_for_tac_8},
                 "/home/shijia/Public/testprogram/e_hypotl.c_e.c:166:38");
    computeLdAdd((Addr)&temp_var_for_tac_10, {(Addr)&a, (Addr)&t1},
                 "/home/shijia/Public/testprogram/e_hypotl.c_e.c:166:62");
    computeLdMul((Addr)&temp_var_for_tac_11,
                 {(Addr)&t2, (Addr)&temp_var_for_tac_10},
                 "/home/shijia/Public/testprogram/e_hypotl.c_e.c:166:57");
    computeLdSub((Addr)&temp_var_for_tac_12,
                 {(Addr)&temp_var_for_tac_9, (Addr)&temp_var_for_tac_11},
                 "/home/shijia/Public/testprogram/e_hypotl.c_e.c:166:52");
    computeLdSub((Addr)&temp_var_for_tac_13,
                 {(Addr)&temp_var_for_tac_7, (Addr)&temp_var_for_tac_12},
                 "/home/shijia/Public/testprogram/e_hypotl.c_e.c:166:33");
    AssignLd({(Addr)&w},
             (Addr) &(temp_var_for_const_9 = temp_var_for_callexp_0),
             "/home/shijia/Public/testprogram/e_hypotl.c_e.c:166:7");
    ;
  } else {
    uint32_t high;

    long double temp_var_for_const_10;
    sh_u.value = b;
    AssignLd({(Addr) &(temp_var_for_const_10 = sh_u.value)}, (Addr)&b,
             "/home/shijia/Public/testprogram/e_hypotl.c_e.c:170:5 "
             "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:220:14>");
    ;
    long double temp_var_for_ext_11;
    long double temp_var_for_tac_14;
    temp_var_for_tac_14 = a + a;

    temp_var_for_ext_11 = temp_var_for_tac_14;
    computeLdAdd((Addr)&temp_var_for_tac_14, {(Addr)&a, (Addr)&a},
                 "/home/shijia/Public/testprogram/e_hypotl.c_e.c:172:29");
    AssignLd({(Addr)&temp_var_for_ext_11}, (Addr)&temp_var_for_tac_14,
             "/home/shijia/Public/testprogram/e_hypotl.c_e.c:172:25");
    ; // a
    /*(a)(a)*/
    a = temp_var_for_ext_11;
    AssignLd({(Addr)&a}, (Addr)&temp_var_for_ext_11,
             "/home/shijia/Public/testprogram/e_hypotl.c_e.c:174:7");
    ;
    long double temp_var_for_ext_12;
    temp_var_for_ext_12;
    long double temp_var_for_tac_15;
    temp_var_for_tac_15 = b - y1;

    y2 = temp_var_for_tac_15;
    computeLdSub((Addr)&temp_var_for_tac_15, {(Addr)&b, (Addr)&y1},
                 "/home/shijia/Public/testprogram/e_hypotl.c_e.c:177:12");
    AssignLd({(Addr)&y2}, (Addr)&temp_var_for_tac_15,
             "/home/shijia/Public/testprogram/e_hypotl.c_e.c:177:8");
    ;
    long double temp_var_for_const_11;
    sh_u.value = a;
    AssignLd({(Addr) &(temp_var_for_const_11 = sh_u.value)}, (Addr)&a,
             "/home/shijia/Public/testprogram/e_hypotl.c_e.c:178:5 "
             "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:220:14>");
    ;
    long double temp_var_for_ext_13;
    temp_var_for_ext_13;
    long double temp_var_for_tac_16;
    temp_var_for_tac_16 = a - t1;

    t2 = temp_var_for_tac_16;
    computeLdSub((Addr)&temp_var_for_tac_16, {(Addr)&a, (Addr)&t1},
                 "/home/shijia/Public/testprogram/e_hypotl.c_e.c:181:12");
    AssignLd({(Addr)&t2}, (Addr)&temp_var_for_tac_16,
             "/home/shijia/Public/testprogram/e_hypotl.c_e.c:181:8");
    ;
    long double temp_var_for_tac_17, temp_var_for_tac_18, temp_var_for_tac_19,
        temp_var_for_tac_20, temp_var_for_tac_21, temp_var_for_tac_22,
        temp_var_for_tac_23, temp_var_for_tac_24;
    long double temp_var_for_const_12, temp_var_for_const_13;
    long double temp_var_for_callexp_1;

    temp_var_for_tac_17 = t1 * y1;

    temp_var_for_tac_18 = 0.0 - w;

    temp_var_for_tac_19 = w * temp_var_for_tac_18;

    temp_var_for_tac_20 = t1 * y2;

    temp_var_for_tac_21 = t2 * b;

    temp_var_for_tac_22 = temp_var_for_tac_20 + temp_var_for_tac_21;

    temp_var_for_tac_23 = temp_var_for_tac_19 - temp_var_for_tac_22;

    temp_var_for_tac_24 = temp_var_for_tac_17 - temp_var_for_tac_23;

    temp_var_for_callexp_1 = __ieee754_sqrtl(temp_var_for_tac_24);
    w = temp_var_for_callexp_1;
    computeLdMul((Addr)&temp_var_for_tac_17, {(Addr)&t1, (Addr)&y1},
                 "/home/shijia/Public/testprogram/e_hypotl.c_e.c:182:28");
    computeLdSub((Addr)&temp_var_for_tac_18,
                 {(Addr) &(temp_var_for_const_12 = 0.0), (Addr)&w},
                 "/home/shijia/Public/testprogram/e_hypotl.c_e.c:182:46");
    computeLdMul((Addr)&temp_var_for_tac_19,
                 {(Addr)&w, (Addr)&temp_var_for_tac_18},
                 "/home/shijia/Public/testprogram/e_hypotl.c_e.c:182:38");
    computeLdMul((Addr)&temp_var_for_tac_20, {(Addr)&t1, (Addr)&y2},
                 "/home/shijia/Public/testprogram/e_hypotl.c_e.c:182:58");
    computeLdMul((Addr)&temp_var_for_tac_21, {(Addr)&t2, (Addr)&b},
                 "/home/shijia/Public/testprogram/e_hypotl.c_e.c:182:68");
    computeLdAdd((Addr)&temp_var_for_tac_22,
                 {(Addr)&temp_var_for_tac_20, (Addr)&temp_var_for_tac_21},
                 "/home/shijia/Public/testprogram/e_hypotl.c_e.c:182:63");
    computeLdSub((Addr)&temp_var_for_tac_23,
                 {(Addr)&temp_var_for_tac_19, (Addr)&temp_var_for_tac_22},
                 "/home/shijia/Public/testprogram/e_hypotl.c_e.c:182:52");
    computeLdSub((Addr)&temp_var_for_tac_24,
                 {(Addr)&temp_var_for_tac_17, (Addr)&temp_var_for_tac_23},
                 "/home/shijia/Public/testprogram/e_hypotl.c_e.c:182:33");
    AssignLd({(Addr)&w},
             (Addr) &(temp_var_for_const_13 = temp_var_for_callexp_1),
             "/home/shijia/Public/testprogram/e_hypotl.c_e.c:182:7");
    ;
  }
  if (k != 0) {
    long double temp_var_for_ext_14;
    long double temp_var_for_const_14;
    long double temp_var_for_callexp_2;

    temp_var_for_callexp_2 = __ieee754_scalbnl(w, ((int)k));
    temp_var_for_ext_14 = temp_var_for_callexp_2;
    AssignLd({(Addr)&temp_var_for_ext_14},
             (Addr) &(temp_var_for_const_14 = temp_var_for_callexp_2),
             "/home/shijia/Public/testprogram/e_hypotl.c_e.c:186:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_14", (Addr)&temp_var_for_ext_14));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_14;
  }
  long double temp_var_for_ext_15;
  temp_var_for_ext_15 = w;
  AssignLd({(Addr)&temp_var_for_ext_15}, (Addr)&w,
           "/home/shijia/Public/testprogram/e_hypotl.c_e.c:193:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_15", (Addr)&temp_var_for_ext_15));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_15;
}
#endif

long double __hypotl(long double x, long double y) {
  long double z = __ieee754_hypotl(x, y);

  if (!isfinite(z) && isfinite(x) && isfinite(y) && _LIB_VERSION != _IEEE_) {
    long double temp_var_for_ext_16;
    long double temp_var_for_const_15;
    long double temp_var_for_callexp_3;

    temp_var_for_callexp_3 = __kernel_standard_l(x, y, z, KMATHERRL_HYPOT);
    temp_var_for_ext_16 = temp_var_for_callexp_3;
    AssignLd({(Addr)&temp_var_for_ext_16},
             (Addr) &(temp_var_for_const_15 = temp_var_for_callexp_3),
             "/home/shijia/Public/testprogram/e_hypotl.c_e.c:205:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_16", (Addr)&temp_var_for_ext_16));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_16;
  }
  /* hypot overflow */

  long double temp_var_for_ext_17;
  temp_var_for_ext_17 = z;
  AssignLd({(Addr)&temp_var_for_ext_17}, (Addr)&z,
           "/home/shijia/Public/testprogram/e_hypotl.c_e.c:214:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_17", (Addr)&temp_var_for_ext_17));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_17;
}

__typeof(__hypotl) hypotl __attribute__((weak, alias("__hypotl")));

#endif
