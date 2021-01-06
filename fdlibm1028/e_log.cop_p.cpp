#include "../ScDebug/scdebug.h"
/* @(#)e_log.c 1.3 95/01/18 */
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

/* __ieee754_log(x)
 * Return the logrithm of x
 *
 * Method :
 *   1. Argument Reduction: find k and f such that
 *			x = 2^k * (1+f),
 *	   where  sqrt(2)/2 < 1+f < sqrt(2) .
 *
 *   2. Approximation of log(1+f).
 *	Let s = f/(2+f) ; based on log(1+f) = log(1+s) - log(1-s)
 *		 = 2s + 2/3 s**3 + 2/5 s**5 + .....,
 *	     	 = 2s + s*R
 *      We use a special Reme algorithm on [0,0.1716] to generate
 * 	a polynomial of degree 14 to approximate R The maximum error
 *	of this polynomial approximation is bounded by 2**-58.45. In
 *	other words,
 *		        2      4      6      8      10      12      14
 *	    R(z) ~ Lg1*s +Lg2*s +Lg3*s +Lg4*s +Lg5*s  +Lg6*s  +Lg7*s
 *  	(the values of Lg1 to Lg7 are listed in the program)
 *	and
 *	    |      2          14          |     -58.45
 *	    | Lg1*s +...+Lg7*s    -  R(z) | <= 2
 *	    |                             |
 *	Note that 2s = f - s*f = f - hfsq + s*hfsq, where hfsq = f*f/2.
 *	In order to guarantee error in log below 1ulp, we compute log
 *	by
 *		log(1+f) = f - s*(f - R)	(if f is not too large)
 *		log(1+f) = f - (hfsq - s*(hfsq+R)).	(better accuracy)
 *
 *	3. Finally,  log(x) = k*ln2 + log(1+f).
 *			    = k*ln2_hi+(f-(hfsq-(s*(hfsq+R)+k*ln2_lo)))
 *	   Here ln2 is split into two floating point number:
 *			ln2_hi + ln2_lo,
 *	   where n*ln2_hi is always exact for |n| < 2000.
 *
 * Special cases:
 *	log(x) is NaN with signal if x < 0 (including -INF) ;
 *	log(+INF) is +INF; log(0) is -INF with signal;
 *	log(NaN) is that NaN with no signal.
 *
 * Accuracy:
 *	according to an error analysis, the error is always less than
 *	1 ulp (unit in the last place).
 *
 * Constants:
 * The hexadecimal values are the intended ones for the following
 * constants. The decimal values may be used, provided that the
 * compiler will convert from decimal to binary accurately enough
 * to produce the hexadecimal values shown.
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif


double __ieee754_logS(double x) {
  double hfsq, f, s, z, R, w, t1, t2, dk;
  int32_t k, hx, i, j;
  uint32_t lx;

  static const double ln2_hi =
      6.93147180369123816490e-01; /* 3fe62e42 fee00000 */
  static const double ln2_lo =
      1.90821492927058770002e-10; /* 3dea39ef 35793c76 */
  static const double two54 =
      1.80143985094819840000e+16;                     /* 43500000 00000000 */
  static const double Lg1 = 6.666666666666735130e-01; /* 3FE55555 55555593 */
  static const double Lg2 = 3.999999999940941908e-01; /* 3FD99999 9997FA04 */
  static const double Lg3 = 2.857142874366239149e-01; /* 3FD24924 94229359 */
  static const double Lg4 = 2.222219843214978396e-01; /* 3FCC71C5 1D8E78AF */
  static const double Lg5 = 1.818357216161805012e-01; /* 3FC74664 96CB03DE */
  static const double Lg6 = 1.531383769920937332e-01; /* 3FC39A09 D078C69F */
  static const double Lg7 = 1.479819860511658591e-01; /* 3FC2F112 DF3E5244 */

  static const double zero = 0.0;

  GET_DOUBLE_WORDS(hx, lx, x);

  k = 0;
  if (hx < IC(0x00100000)) { /* x < 2**-1022  */
    if (((hx & IC(0x7fffffff)) | lx) == 0) {
      double temp_var_for_ext_0;
      double temp_var_for_tac_0;
      double temp_var_for_const_0, temp_var_for_const_1;
      temp_var_for_tac_0 = (-(two54)) / zero;

      temp_var_for_ext_0 = temp_var_for_tac_0;
      computeDDiv((Addr)&temp_var_for_tac_0,
                  {(Addr) &(temp_var_for_const_1 = (-(two54))),
                   (Addr) &(temp_var_for_const_0 = zero)},
                  "/home/shijia/Public/testprogram/e_log.c_e.c:97:35");
      AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_0,
              "/home/shijia/Public/testprogram/e_log.c_e.c:97:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
      callExp++; /*identify the function is  add move tmpShadow*/
      return (temp_var_for_ext_0);
    }
    /* log(+-0)=-inf */
    if (hx < 0) {
      double temp_var_for_ext_1;
      double temp_var_for_tac_1, temp_var_for_tac_2;
      double temp_var_for_const_2;
      temp_var_for_tac_1 = x - x;

      temp_var_for_tac_2 = temp_var_for_tac_1 / zero;

      temp_var_for_ext_1 = temp_var_for_tac_2;
      computeDSub((Addr)&temp_var_for_tac_1, {(Addr)&x, (Addr)&x},
                  "/home/shijia/Public/testprogram/e_log.c_e.c:106:31");
      computeDDiv(
          (Addr)&temp_var_for_tac_2,
          {(Addr)&temp_var_for_tac_1, (Addr) &(temp_var_for_const_2 = zero)},
          "/home/shijia/Public/testprogram/e_log.c_e.c:106:36");
      AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_2,
              "/home/shijia/Public/testprogram/e_log.c_e.c:106:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_1;
    }
    /* log(-#) = NaN */
    k -= 54;
    x *= two54;
    ; /* subnormal number, scale up x */
    GET_HIGH_WORD(hx, x);
  }

  if (hx >= IC(0x7ff00000)) {
    double temp_var_for_ext_2;
    double temp_var_for_tac_4;
    temp_var_for_tac_4 = x + x;

    temp_var_for_ext_2 = temp_var_for_tac_4;
    computeDAdd((Addr)&temp_var_for_tac_4, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_log.c_e.c:120:28");
    AssignD({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_4,
            "/home/shijia/Public/testprogram/e_log.c_e.c:120:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  }

  k += (hx >> 20) - 1023;
  hx &= IC(0x000fffff);
  i = (hx + IC(0x95f64)) & IC(0x100000);
  SET_HIGH_WORD(x, hx | (i ^ IC(0x3ff00000))); /* normalize x or x/2 */
  k += (i >> 20);
  double temp_var_for_ext_3;
  double temp_var_for_tac_5;
  double temp_var_for_const_3;
  temp_var_for_tac_5 = x - 1.0;

  temp_var_for_ext_3 = temp_var_for_tac_5;
  computeDSub((Addr)&temp_var_for_tac_5,
              {(Addr)&x, (Addr) &(temp_var_for_const_3 = 1.0)},
              "/home/shijia/Public/testprogram/e_log.c_e.c:132:26");
  AssignD({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_5,
          "/home/shijia/Public/testprogram/e_log.c_e.c:132:22");
  ; // f
  /*(xt_0)(ar_fo)(ar_fo)(xt_1)(f)(v)(f)(v)(two54)(x)(2)(t)(1.0)(x)*/
  f = temp_var_for_ext_3;
  AssignD({(Addr)&f}, (Addr)&temp_var_for_ext_3,
          "/home/shijia/Public/testprogram/e_log.c_e.c:134:5");
  ;
  if ((IC(0x000fffff) & (2 + hx)) < 3) { /* |f| < 2**-20 */
    if ( f == zero
        ) {
      if (k == 0) {
        double temp_var_for_ext_4;
        double temp_var_for_const_5;
        temp_var_for_ext_4 = zero;
        AssignD({(Addr)&temp_var_for_ext_4},
                (Addr) &(temp_var_for_const_5 = zero),
                "/home/shijia/Public/testprogram/e_log.c_e.c:139:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_4;
      }

      double temp_var_for_const_6;
      dk = ((double)k);
      AssignD({(Addr)&dk}, (Addr) &(temp_var_for_const_6 = ((double)k)),
              "/home/shijia/Public/testprogram/e_log.c_e.c:146:10");
      ;
      double temp_var_for_ext_5;
      double temp_var_for_tac_7, temp_var_for_tac_8, temp_var_for_tac_9;
      double temp_var_for_const_7, temp_var_for_const_8;
      temp_var_for_tac_7 = dk * ln2_hi;

      temp_var_for_tac_8 = dk * ln2_lo;

      temp_var_for_tac_9 = temp_var_for_tac_7 + temp_var_for_tac_8;

      temp_var_for_ext_5 = temp_var_for_tac_9;
      computeDMul((Addr)&temp_var_for_tac_7,
                  {(Addr)&dk, (Addr) &(temp_var_for_const_7 = ln2_hi)},
                  "/home/shijia/Public/testprogram/e_log.c_e.c:148:31");
      computeDMul((Addr)&temp_var_for_tac_8,
                  {(Addr)&dk, (Addr) &(temp_var_for_const_8 = ln2_lo)},
                  "/home/shijia/Public/testprogram/e_log.c_e.c:148:45");
      computeDAdd((Addr)&temp_var_for_tac_9,
                  {(Addr)&temp_var_for_tac_7, (Addr)&temp_var_for_tac_8},
                  "/home/shijia/Public/testprogram/e_log.c_e.c:148:40");
      AssignD({(Addr)&temp_var_for_ext_5}, (Addr)&temp_var_for_tac_9,
              "/home/shijia/Public/testprogram/e_log.c_e.c:148:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_5;
    }
    double temp_var_for_tac_10, temp_var_for_tac_11, temp_var_for_tac_12,
        temp_var_for_tac_13;
    double temp_var_for_const_9, temp_var_for_const_10;
    temp_var_for_tac_10 = f * f;

    temp_var_for_tac_11 = 0.33333333333333333 * f;

    temp_var_for_tac_12 = 0.5 - temp_var_for_tac_11;

    temp_var_for_tac_13 = temp_var_for_tac_10 * temp_var_for_tac_12;

    R = temp_var_for_tac_13;
    computeDMul((Addr)&temp_var_for_tac_10, {(Addr)&f, (Addr)&f},
                "/home/shijia/Public/testprogram/e_log.c_e.c:154:11");
    computeDMul(
        (Addr)&temp_var_for_tac_11,
        {(Addr) &(temp_var_for_const_9 = 0.33333333333333333), (Addr)&f},
        "/home/shijia/Public/testprogram/e_log.c_e.c:154:44");
    computeDSub(
        (Addr)&temp_var_for_tac_12,
        {(Addr) &(temp_var_for_const_10 = 0.5), (Addr)&temp_var_for_tac_11},
        "/home/shijia/Public/testprogram/e_log.c_e.c:154:22");
    computeDMul((Addr)&temp_var_for_tac_13,
                {(Addr)&temp_var_for_tac_10, (Addr)&temp_var_for_tac_12},
                "/home/shijia/Public/testprogram/e_log.c_e.c:154:15");
    AssignD({(Addr)&R}, (Addr)&temp_var_for_tac_13,
            "/home/shijia/Public/testprogram/e_log.c_e.c:154:7");
    ;
    if (k == 0) {
      double temp_var_for_ext_6;
      double temp_var_for_tac_14;
      temp_var_for_tac_14 = f - R;

      temp_var_for_ext_6 = temp_var_for_tac_14;
      computeDSub((Addr)&temp_var_for_tac_14, {(Addr)&f, (Addr)&R},
                  "/home/shijia/Public/testprogram/e_log.c_e.c:157:30");
      AssignD({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_14,
              "/home/shijia/Public/testprogram/e_log.c_e.c:157:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_6;
    }

    double temp_var_for_const_11;
    dk = ((double)k);
    AssignD({(Addr)&dk}, (Addr) &(temp_var_for_const_11 = ((double)k)),
            "/home/shijia/Public/testprogram/e_log.c_e.c:164:8");
    ;
    double temp_var_for_ext_7;
    double temp_var_for_tac_15, temp_var_for_tac_16, temp_var_for_tac_17,
        temp_var_for_tac_18, temp_var_for_tac_19;
    double temp_var_for_const_12, temp_var_for_const_13;
    temp_var_for_tac_15 = dk * ln2_hi;

    temp_var_for_tac_16 = dk * ln2_lo;

    temp_var_for_tac_17 = R - temp_var_for_tac_16;

    temp_var_for_tac_18 = temp_var_for_tac_17 - f;

    temp_var_for_tac_19 = temp_var_for_tac_15 - temp_var_for_tac_18;

    temp_var_for_ext_7 = temp_var_for_tac_19;
    computeDMul((Addr)&temp_var_for_tac_15,
                {(Addr)&dk, (Addr) &(temp_var_for_const_12 = ln2_hi)},
                "/home/shijia/Public/testprogram/e_log.c_e.c:166:29");
    computeDMul((Addr)&temp_var_for_tac_16,
                {(Addr)&dk, (Addr) &(temp_var_for_const_13 = ln2_lo)},
                "/home/shijia/Public/testprogram/e_log.c_e.c:166:49");
    computeDSub((Addr)&temp_var_for_tac_17,
                {(Addr)&R, (Addr)&temp_var_for_tac_16},
                "/home/shijia/Public/testprogram/e_log.c_e.c:166:44");
    computeDSub((Addr)&temp_var_for_tac_18,
                {(Addr)&temp_var_for_tac_17, (Addr)&f},
                "/home/shijia/Public/testprogram/e_log.c_e.c:166:59");
    computeDSub((Addr)&temp_var_for_tac_19,
                {(Addr)&temp_var_for_tac_15, (Addr)&temp_var_for_tac_18},
                "/home/shijia/Public/testprogram/e_log.c_e.c:166:38");
    AssignD({(Addr)&temp_var_for_ext_7}, (Addr)&temp_var_for_tac_19,
            "/home/shijia/Public/testprogram/e_log.c_e.c:166:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_7;
  }
  double temp_var_for_tac_20, temp_var_for_tac_21;
  double temp_var_for_const_14;
  temp_var_for_tac_20 = 2.0 + f;

  temp_var_for_tac_21 = f / temp_var_for_tac_20;

  s = temp_var_for_tac_21;
  computeDAdd((Addr)&temp_var_for_tac_20,
              {(Addr) &(temp_var_for_const_14 = 2.0), (Addr)&f},
              "/home/shijia/Public/testprogram/e_log.c_e.c:171:16");
  computeDDiv((Addr)&temp_var_for_tac_21,
              {(Addr)&f, (Addr)&temp_var_for_tac_20},
              "/home/shijia/Public/testprogram/e_log.c_e.c:171:9");
  AssignD({(Addr)&s}, (Addr)&temp_var_for_tac_21,
          "/home/shijia/Public/testprogram/e_log.c_e.c:171:5");
  ;
  double temp_var_for_const_15;
  dk = ((double)k);
  AssignD({(Addr)&dk}, (Addr) &(temp_var_for_const_15 = ((double)k)),
          "/home/shijia/Public/testprogram/e_log.c_e.c:172:6");
  ;
  double temp_var_for_tac_22;
  temp_var_for_tac_22 = s * s;

  z = temp_var_for_tac_22;
  computeDMul((Addr)&temp_var_for_tac_22, {(Addr)&s, (Addr)&s},
              "/home/shijia/Public/testprogram/e_log.c_e.c:173:9");
  AssignD({(Addr)&z}, (Addr)&temp_var_for_tac_22,
          "/home/shijia/Public/testprogram/e_log.c_e.c:173:5");
  ;
  i = hx - IC(0x6147a);
  double temp_var_for_tac_23;
  temp_var_for_tac_23 = z * z;

  w = temp_var_for_tac_23;
  computeDMul((Addr)&temp_var_for_tac_23, {(Addr)&z, (Addr)&z},
              "/home/shijia/Public/testprogram/e_log.c_e.c:175:9");
  AssignD({(Addr)&w}, (Addr)&temp_var_for_tac_23,
          "/home/shijia/Public/testprogram/e_log.c_e.c:175:5");
  ;
  j = IC(0x6b851) - hx;
  double temp_var_for_tac_24, temp_var_for_tac_25, temp_var_for_tac_26,
      temp_var_for_tac_27, temp_var_for_tac_28;
  double temp_var_for_const_16, temp_var_for_const_17, temp_var_for_const_18;
  temp_var_for_tac_24 = w * Lg6;

  temp_var_for_tac_25 = Lg4 + temp_var_for_tac_24;

  temp_var_for_tac_26 = w * temp_var_for_tac_25;

  temp_var_for_tac_27 = Lg2 + temp_var_for_tac_26;

  temp_var_for_tac_28 = w * temp_var_for_tac_27;

  t1 = temp_var_for_tac_28;
  computeDMul((Addr)&temp_var_for_tac_24,
              {(Addr)&w, (Addr) &(temp_var_for_const_16 = Lg6)},
              "/home/shijia/Public/testprogram/e_log.c_e.c:177:32");
  computeDAdd(
      (Addr)&temp_var_for_tac_25,
      {(Addr) &(temp_var_for_const_17 = Lg4), (Addr)&temp_var_for_tac_24},
      "/home/shijia/Public/testprogram/e_log.c_e.c:177:28");
  computeDMul((Addr)&temp_var_for_tac_26,
              {(Addr)&w, (Addr)&temp_var_for_tac_25},
              "/home/shijia/Public/testprogram/e_log.c_e.c:177:21");
  computeDAdd(
      (Addr)&temp_var_for_tac_27,
      {(Addr) &(temp_var_for_const_18 = Lg2), (Addr)&temp_var_for_tac_26},
      "/home/shijia/Public/testprogram/e_log.c_e.c:177:17");
  computeDMul((Addr)&temp_var_for_tac_28,
              {(Addr)&w, (Addr)&temp_var_for_tac_27},
              "/home/shijia/Public/testprogram/e_log.c_e.c:177:10");
  AssignD({(Addr)&t1}, (Addr)&temp_var_for_tac_28,
          "/home/shijia/Public/testprogram/e_log.c_e.c:177:6");
  ;
  double temp_var_for_tac_29, temp_var_for_tac_30, temp_var_for_tac_31,
      temp_var_for_tac_32, temp_var_for_tac_33, temp_var_for_tac_34,
      temp_var_for_tac_35;
  double temp_var_for_const_19, temp_var_for_const_20, temp_var_for_const_21,
      temp_var_for_const_22;
  temp_var_for_tac_29 = w * Lg7;

  temp_var_for_tac_30 = Lg5 + temp_var_for_tac_29;

  temp_var_for_tac_31 = w * temp_var_for_tac_30;

  temp_var_for_tac_32 = Lg3 + temp_var_for_tac_31;

  temp_var_for_tac_33 = w * temp_var_for_tac_32;

  temp_var_for_tac_34 = Lg1 + temp_var_for_tac_33;

  temp_var_for_tac_35 = z * temp_var_for_tac_34;

  t2 = temp_var_for_tac_35;
  computeDMul((Addr)&temp_var_for_tac_29,
              {(Addr)&w, (Addr) &(temp_var_for_const_19 = Lg7)},
              "/home/shijia/Public/testprogram/e_log.c_e.c:178:43");
  computeDAdd(
      (Addr)&temp_var_for_tac_30,
      {(Addr) &(temp_var_for_const_20 = Lg5), (Addr)&temp_var_for_tac_29},
      "/home/shijia/Public/testprogram/e_log.c_e.c:178:39");
  computeDMul((Addr)&temp_var_for_tac_31,
              {(Addr)&w, (Addr)&temp_var_for_tac_30},
              "/home/shijia/Public/testprogram/e_log.c_e.c:178:32");
  computeDAdd(
      (Addr)&temp_var_for_tac_32,
      {(Addr) &(temp_var_for_const_21 = Lg3), (Addr)&temp_var_for_tac_31},
      "/home/shijia/Public/testprogram/e_log.c_e.c:178:28");
  computeDMul((Addr)&temp_var_for_tac_33,
              {(Addr)&w, (Addr)&temp_var_for_tac_32},
              "/home/shijia/Public/testprogram/e_log.c_e.c:178:21");
  computeDAdd(
      (Addr)&temp_var_for_tac_34,
      {(Addr) &(temp_var_for_const_22 = Lg1), (Addr)&temp_var_for_tac_33},
      "/home/shijia/Public/testprogram/e_log.c_e.c:178:17");
  computeDMul((Addr)&temp_var_for_tac_35,
              {(Addr)&z, (Addr)&temp_var_for_tac_34},
              "/home/shijia/Public/testprogram/e_log.c_e.c:178:10");
  AssignD({(Addr)&t2}, (Addr)&temp_var_for_tac_35,
          "/home/shijia/Public/testprogram/e_log.c_e.c:178:6");
  ;
  i |= j;
  double temp_var_for_tac_36;
  temp_var_for_tac_36 = t2 + t1;

  R = temp_var_for_tac_36;
  computeDAdd((Addr)&temp_var_for_tac_36, {(Addr)&t2, (Addr)&t1},
              "/home/shijia/Public/testprogram/e_log.c_e.c:180:10");
  AssignD({(Addr)&R}, (Addr)&temp_var_for_tac_36,
          "/home/shijia/Public/testprogram/e_log.c_e.c:180:5");
  ;
  if (i > 0) {
    double temp_var_for_tac_37, temp_var_for_tac_38;
    double temp_var_for_const_23;
    temp_var_for_tac_37 = 0.5 * f;

    temp_var_for_tac_38 = temp_var_for_tac_37 * f;

    hfsq = temp_var_for_tac_38;
    computeDMul((Addr)&temp_var_for_tac_37,
                {(Addr) &(temp_var_for_const_23 = 0.5), (Addr)&f},
                "/home/shijia/Public/testprogram/e_log.c_e.c:182:16");
    computeDMul((Addr)&temp_var_for_tac_38,
                {(Addr)&temp_var_for_tac_37, (Addr)&f},
                "/home/shijia/Public/testprogram/e_log.c_e.c:182:20");
    AssignD({(Addr)&hfsq}, (Addr)&temp_var_for_tac_38,
            "/home/shijia/Public/testprogram/e_log.c_e.c:182:10");
    ;
    if (k == 0) {
      double temp_var_for_ext_8;
      double temp_var_for_tac_39, temp_var_for_tac_40, temp_var_for_tac_41,
          temp_var_for_tac_42;
      temp_var_for_tac_39 = hfsq + R;

      temp_var_for_tac_40 = s * temp_var_for_tac_39;

      temp_var_for_tac_41 = hfsq - temp_var_for_tac_40;

      temp_var_for_tac_42 = f - temp_var_for_tac_41;

      temp_var_for_ext_8 = temp_var_for_tac_42;
      computeDAdd((Addr)&temp_var_for_tac_39, {(Addr)&hfsq, (Addr)&R},
                  "/home/shijia/Public/testprogram/e_log.c_e.c:185:50");
      computeDMul((Addr)&temp_var_for_tac_40,
                  {(Addr)&s, (Addr)&temp_var_for_tac_39},
                  "/home/shijia/Public/testprogram/e_log.c_e.c:185:42");
      computeDSub((Addr)&temp_var_for_tac_41,
                  {(Addr)&hfsq, (Addr)&temp_var_for_tac_40},
                  "/home/shijia/Public/testprogram/e_log.c_e.c:185:38");
      computeDSub((Addr)&temp_var_for_tac_42,
                  {(Addr)&f, (Addr)&temp_var_for_tac_41},
                  "/home/shijia/Public/testprogram/e_log.c_e.c:185:30");
      AssignD({(Addr)&temp_var_for_ext_8}, (Addr)&temp_var_for_tac_42,
              "/home/shijia/Public/testprogram/e_log.c_e.c:185:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_8;
    }

    double temp_var_for_ext_9;
    double temp_var_for_tac_43, temp_var_for_tac_44, temp_var_for_tac_45,
        temp_var_for_tac_46, temp_var_for_tac_47, temp_var_for_tac_48,
        temp_var_for_tac_49, temp_var_for_tac_50;
    double temp_var_for_const_24, temp_var_for_const_25;
    temp_var_for_tac_43 = dk * ln2_hi;

    temp_var_for_tac_44 = hfsq + R;

    temp_var_for_tac_45 = s * temp_var_for_tac_44;

    temp_var_for_tac_46 = dk * ln2_lo;

    temp_var_for_tac_47 = temp_var_for_tac_45 + temp_var_for_tac_46;

    temp_var_for_tac_48 = hfsq - temp_var_for_tac_47;

    temp_var_for_tac_49 = temp_var_for_tac_48 - f;

    temp_var_for_tac_50 = temp_var_for_tac_43 - temp_var_for_tac_49;

    temp_var_for_ext_9 = temp_var_for_tac_50;
    computeDMul((Addr)&temp_var_for_tac_43,
                {(Addr)&dk, (Addr) &(temp_var_for_const_24 = ln2_hi)},
                "/home/shijia/Public/testprogram/e_log.c_e.c:194:12");
    computeDAdd((Addr)&temp_var_for_tac_44, {(Addr)&hfsq, (Addr)&R},
                "/home/shijia/Public/testprogram/e_log.c_e.c:194:43");
    computeDMul((Addr)&temp_var_for_tac_45,
                {(Addr)&s, (Addr)&temp_var_for_tac_44},
                "/home/shijia/Public/testprogram/e_log.c_e.c:194:35");
    computeDMul((Addr)&temp_var_for_tac_46,
                {(Addr)&dk, (Addr) &(temp_var_for_const_25 = ln2_lo)},
                "/home/shijia/Public/testprogram/e_log.c_e.c:194:53");
    computeDAdd((Addr)&temp_var_for_tac_47,
                {(Addr)&temp_var_for_tac_45, (Addr)&temp_var_for_tac_46},
                "/home/shijia/Public/testprogram/e_log.c_e.c:194:48");
    computeDSub((Addr)&temp_var_for_tac_48,
                {(Addr)&hfsq, (Addr)&temp_var_for_tac_47},
                "/home/shijia/Public/testprogram/e_log.c_e.c:194:30");
    computeDSub((Addr)&temp_var_for_tac_49,
                {(Addr)&temp_var_for_tac_48, (Addr)&f},
                "/home/shijia/Public/testprogram/e_log.c_e.c:194:64");
    computeDSub((Addr)&temp_var_for_tac_50,
                {(Addr)&temp_var_for_tac_43, (Addr)&temp_var_for_tac_49},
                "/home/shijia/Public/testprogram/e_log.c_e.c:194:21");
    AssignD({(Addr)&temp_var_for_ext_9}, (Addr)&temp_var_for_tac_50,
            "/home/shijia/Public/testprogram/e_log.c_e.c:193:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_9;
  }
  if (k == 0) {
    double temp_var_for_ext_10;
    double temp_var_for_tac_51, temp_var_for_tac_52, temp_var_for_tac_53;
    temp_var_for_tac_51 = f - R;

    temp_var_for_tac_52 = s * temp_var_for_tac_51;

    temp_var_for_tac_53 = f - temp_var_for_tac_52;

    temp_var_for_ext_10 = temp_var_for_tac_53;
    computeDSub((Addr)&temp_var_for_tac_51, {(Addr)&f, (Addr)&R},
                "/home/shijia/Public/testprogram/e_log.c_e.c:201:38");
    computeDMul((Addr)&temp_var_for_tac_52,
                {(Addr)&s, (Addr)&temp_var_for_tac_51},
                "/home/shijia/Public/testprogram/e_log.c_e.c:201:33");
    computeDSub((Addr)&temp_var_for_tac_53,
                {(Addr)&f, (Addr)&temp_var_for_tac_52},
                "/home/shijia/Public/testprogram/e_log.c_e.c:201:29");
    AssignD({(Addr)&temp_var_for_ext_10}, (Addr)&temp_var_for_tac_53,
            "/home/shijia/Public/testprogram/e_log.c_e.c:201:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_10", (Addr)&temp_var_for_ext_10));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_10;
  }

  double temp_var_for_ext_11;
  double temp_var_for_tac_54, temp_var_for_tac_55, temp_var_for_tac_56,
      temp_var_for_tac_57, temp_var_for_tac_58, temp_var_for_tac_59,
      temp_var_for_tac_60;
  double temp_var_for_const_26, temp_var_for_const_27;
  temp_var_for_tac_54 = dk * ln2_hi;

  temp_var_for_tac_55 = f - R;

  temp_var_for_tac_56 = s * temp_var_for_tac_55;

  temp_var_for_tac_57 = dk * ln2_lo;

  temp_var_for_tac_58 = temp_var_for_tac_56 - temp_var_for_tac_57;

  temp_var_for_tac_59 = temp_var_for_tac_58 - f;

  temp_var_for_tac_60 = temp_var_for_tac_54 - temp_var_for_tac_59;

  temp_var_for_ext_11 = temp_var_for_tac_60;
  computeDMul((Addr)&temp_var_for_tac_54,
              {(Addr)&dk, (Addr) &(temp_var_for_const_26 = ln2_hi)},
              "/home/shijia/Public/testprogram/e_log.c_e.c:209:28");
  computeDSub((Addr)&temp_var_for_tac_55, {(Addr)&f, (Addr)&R},
              "/home/shijia/Public/testprogram/e_log.c_e.c:209:48");
  computeDMul((Addr)&temp_var_for_tac_56,
              {(Addr)&s, (Addr)&temp_var_for_tac_55},
              "/home/shijia/Public/testprogram/e_log.c_e.c:209:43");
  computeDMul((Addr)&temp_var_for_tac_57,
              {(Addr)&dk, (Addr) &(temp_var_for_const_27 = ln2_lo)},
              "/home/shijia/Public/testprogram/e_log.c_e.c:209:58");
  computeDSub((Addr)&temp_var_for_tac_58,
              {(Addr)&temp_var_for_tac_56, (Addr)&temp_var_for_tac_57},
              "/home/shijia/Public/testprogram/e_log.c_e.c:209:53");
  computeDSub((Addr)&temp_var_for_tac_59,
              {(Addr)&temp_var_for_tac_58, (Addr)&f},
              "/home/shijia/Public/testprogram/e_log.c_e.c:209:68");
  computeDSub((Addr)&temp_var_for_tac_60,
              {(Addr)&temp_var_for_tac_54, (Addr)&temp_var_for_tac_59},
              "/home/shijia/Public/testprogram/e_log.c_e.c:209:37");
  AssignD({(Addr)&temp_var_for_ext_11}, (Addr)&temp_var_for_tac_60,
          "/home/shijia/Public/testprogram/e_log.c_e.c:209:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_11", (Addr)&temp_var_for_ext_11));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_11;
}

int main()
{
  std::ifstream inputFile("/home/shijia/Public/FpDebug-valgrind_3.12/valgrind/fpdebug/pso/exe-input/log_t.txt", std::ios::in);
  double input;
  long double oracle, realError = 0.0, scError = 0.0, prealError = 0.0, pscError = 0.0;
  long double delta = 1.0e-20;
  int index,la=0,eq=0,sm=0;
  std::ifstream inputOracle("/home/shijia/Public/FpDebug-valgrind_3.12/valgrind/fpdebug/pso/mpfr/mpfrresults/log_out.txt", std::ios::in);
  while (inputFile >> input)
  {
    double a = __ieee754_logS(input);
    inputOracle >> index >> oracle;
    // std::cout<<oracle<<std::endl;
    // printf("oracle  %.20Le %.20le\n",oracle,a);
    prealError = fabs(oracle - (long double)a) / max(delta, fabs(oracle));
    realError += prealError;
    CallStackPop((Addr)&a, getTop(a));
    Real scValue = getReal("", (Addr)&a);
    pscError = fabs(oracle - (long double)scValue.z - (long double)scValue.zz) / max(delta, fabs(oracle));
    scError += pscError;
    if(pscError<prealError)
    {
      sm++;
    }
    else if(pscError==prealError)
    {
      eq++;
    }
    else
    {
      la++;
    }
    
    
    // printVarInfo("a", (Addr)&a);
    // printf("%d %.20Le %.20Le\n",index,realError/index,scError/index);
  }
  printf("%d %.20Le %.20Le ", index, realError / index, scError / index);
  printf("%d %d %d\n", la,eq,sm);
  return 0;
}