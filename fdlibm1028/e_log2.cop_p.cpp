#include "../ScDebug/scdebug.h"
/* Adapted for log2 by Ulrich Drepper <drepper@cygnus.com>.  */
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

/* __ieee754_log2(x)
 * Return the logarithm to base 2 of x
 *
 * Method :
 *   1. Argument Reduction: find k and f such that
 *			x = 2^k * (1+f),
 *	   where  sqrt(2)/2 < 1+f < sqrt(2) .
 *
 *   2. Approximation of log(1+f).
 *	Let s = f/(2+f) ; based on log(1+f) = log(1+s) - log(1-s)
 *		 = 2s + 2/3 s**3 + 2/5 s**5 + .....,
 *		 = 2s + s*R
 *      We use a special Reme algorithm on [0,0.1716] to generate
 *	a polynomial of degree 14 to approximate R The maximum error
 *	of this polynomial approximation is bounded by 2**-58.45. In
 *	other words,
 *			2      4      6      8      10      12      14
 *	    R(z) ~ Lg1*s +Lg2*s +Lg3*s +Lg4*s +Lg5*s  +Lg6*s  +Lg7*s
 *	(the values of Lg1 to Lg7 are listed in the program)
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
 *	3. Finally,  log(x) = k + log(1+f).
 *			    = k+(f-(hfsq-(s*(hfsq+R))))
 *
 * Special cases:
 *	log2(x) is NaN with signal if x < 0 (including -INF) ;
 *	log2(+INF) is +INF; log(0) is -INF with signal;
 *	log2(NaN) is that NaN with no signal.
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



double __ieee754_log2S(double x) {
  double hfsq, f, s, z, R, w, t1, t2, dk;
  int32_t k, hx, i, j;
  uint32_t lx;

  static const double ln2 = 0.69314718055994530942;
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
      double temp_var_for_tac_0, temp_var_for_tac_1;
      double temp_var_for_const_0;
      temp_var_for_tac_0 = x - x;

      temp_var_for_tac_1 = (-(two54)) / temp_var_for_tac_0;

      temp_var_for_ext_0 = temp_var_for_tac_1;
      computeDSub((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&x},
                  "/home/shijia/Public/testprogram/e_log2.c_e.c:86:40");
      computeDDiv((Addr)&temp_var_for_tac_1,
                  {(Addr) &(temp_var_for_const_0 = (-(two54))),
                   (Addr)&temp_var_for_tac_0},
                  "/home/shijia/Public/testprogram/e_log2.c_e.c:86:35");
      AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_1,
              "/home/shijia/Public/testprogram/e_log2.c_e.c:86:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_0;
    }
    /* log(+-0)=-inf */
    if (hx < 0) {
      double temp_var_for_ext_1;
      double temp_var_for_tac_2, temp_var_for_tac_3, temp_var_for_tac_4;
      temp_var_for_tac_2 = x - x;

      temp_var_for_tac_3 = x - x;

      temp_var_for_tac_4 = temp_var_for_tac_2 / temp_var_for_tac_3;

      temp_var_for_ext_1 = temp_var_for_tac_4;
      computeDSub((Addr)&temp_var_for_tac_2, {(Addr)&x, (Addr)&x},
                  "/home/shijia/Public/testprogram/e_log2.c_e.c:95:31");
      computeDSub((Addr)&temp_var_for_tac_3, {(Addr)&x, (Addr)&x},
                  "/home/shijia/Public/testprogram/e_log2.c_e.c:95:41");
      computeDDiv((Addr)&temp_var_for_tac_4,
                  {(Addr)&temp_var_for_tac_2, (Addr)&temp_var_for_tac_3},
                  "/home/shijia/Public/testprogram/e_log2.c_e.c:95:36");
      AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_4,
              "/home/shijia/Public/testprogram/e_log2.c_e.c:95:26");
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
    double temp_var_for_tac_6;
    temp_var_for_tac_6 = x + x;

    temp_var_for_ext_2 = temp_var_for_tac_6;
    computeDAdd((Addr)&temp_var_for_tac_6, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_log2.c_e.c:108:28");
    AssignD({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_6,
            "/home/shijia/Public/testprogram/e_log2.c_e.c:108:24");
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
  double temp_var_for_const_1;
  dk = ((double)k);
  AssignD({(Addr)&dk}, (Addr) &(temp_var_for_const_1 = ((double)k)),
          "/home/shijia/Public/testprogram/e_log2.c_e.c:119:6");
  ;
  double temp_var_for_tac_7;
  double temp_var_for_const_2;
  temp_var_for_tac_7 = x - 1.0;

  f = temp_var_for_tac_7;
  computeDSub((Addr)&temp_var_for_tac_7,
              {(Addr)&x, (Addr) &(temp_var_for_const_2 = 1.0)},
              "/home/shijia/Public/testprogram/e_log2.c_e.c:120:9");
  AssignD({(Addr)&f}, (Addr)&temp_var_for_tac_7,
          "/home/shijia/Public/testprogram/e_log2.c_e.c:120:5");
  ;
  if ((IC(0x000fffff) & (2 + hx)) < 3) { /* |f| < 2**-20 */
    if (f == zero

        ) {
      double temp_var_for_ext_3;
      temp_var_for_ext_3 = dk;
      AssignD({(Addr)&temp_var_for_ext_3}, (Addr)&dk,
              "/home/shijia/Public/testprogram/e_log2.c_e.c:124:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_3;
    }

    double temp_var_for_tac_9, temp_var_for_tac_10, temp_var_for_tac_11,
        temp_var_for_tac_12;
    double temp_var_for_const_4, temp_var_for_const_5;
    temp_var_for_tac_9 = f * f;

    temp_var_for_tac_10 = 0.33333333333333333 * f;

    temp_var_for_tac_11 = 0.5 - temp_var_for_tac_10;

    temp_var_for_tac_12 = temp_var_for_tac_9 * temp_var_for_tac_11;

    R = temp_var_for_tac_12;
    computeDMul((Addr)&temp_var_for_tac_9, {(Addr)&f, (Addr)&f},
                "/home/shijia/Public/testprogram/e_log2.c_e.c:131:11");
    computeDMul(
        (Addr)&temp_var_for_tac_10,
        {(Addr) &(temp_var_for_const_4 = 0.33333333333333333), (Addr)&f},
        "/home/shijia/Public/testprogram/e_log2.c_e.c:131:44");
    computeDSub(
        (Addr)&temp_var_for_tac_11,
        {(Addr) &(temp_var_for_const_5 = 0.5), (Addr)&temp_var_for_tac_10},
        "/home/shijia/Public/testprogram/e_log2.c_e.c:131:22");
    computeDMul((Addr)&temp_var_for_tac_12,
                {(Addr)&temp_var_for_tac_9, (Addr)&temp_var_for_tac_11},
                "/home/shijia/Public/testprogram/e_log2.c_e.c:131:15");
    AssignD({(Addr)&R}, (Addr)&temp_var_for_tac_12,
            "/home/shijia/Public/testprogram/e_log2.c_e.c:131:7");
    ;
    double temp_var_for_ext_4;
    double temp_var_for_tac_13, temp_var_for_tac_14, temp_var_for_tac_15;
    double temp_var_for_const_6;
    temp_var_for_tac_13 = R - f;

    temp_var_for_tac_14 = temp_var_for_tac_13 / ln2;

    temp_var_for_tac_15 = dk - temp_var_for_tac_14;

    temp_var_for_ext_4 = temp_var_for_tac_15;
    computeDSub((Addr)&temp_var_for_tac_13, {(Addr)&R, (Addr)&f},
                "/home/shijia/Public/testprogram/e_log2.c_e.c:133:34");
    computeDDiv(
        (Addr)&temp_var_for_tac_14,
        {(Addr)&temp_var_for_tac_13, (Addr) &(temp_var_for_const_6 = ln2)},
        "/home/shijia/Public/testprogram/e_log2.c_e.c:133:39");
    computeDSub((Addr)&temp_var_for_tac_15,
                {(Addr)&dk, (Addr)&temp_var_for_tac_14},
                "/home/shijia/Public/testprogram/e_log2.c_e.c:133:29");
    AssignD({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_15,
            "/home/shijia/Public/testprogram/e_log2.c_e.c:133:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_4;
  }
  double temp_var_for_tac_16, temp_var_for_tac_17;
  double temp_var_for_const_7;
  temp_var_for_tac_16 = 2.0 + f;

  temp_var_for_tac_17 = f / temp_var_for_tac_16;

  s = temp_var_for_tac_17;
  computeDAdd((Addr)&temp_var_for_tac_16,
              {(Addr) &(temp_var_for_const_7 = 2.0), (Addr)&f},
              "/home/shijia/Public/testprogram/e_log2.c_e.c:138:16");
  computeDDiv((Addr)&temp_var_for_tac_17,
              {(Addr)&f, (Addr)&temp_var_for_tac_16},
              "/home/shijia/Public/testprogram/e_log2.c_e.c:138:9");
  AssignD({(Addr)&s}, (Addr)&temp_var_for_tac_17,
          "/home/shijia/Public/testprogram/e_log2.c_e.c:138:5");
  ;
  double temp_var_for_tac_18;
  temp_var_for_tac_18 = s * s;

  z = temp_var_for_tac_18;
  computeDMul((Addr)&temp_var_for_tac_18, {(Addr)&s, (Addr)&s},
              "/home/shijia/Public/testprogram/e_log2.c_e.c:139:9");
  AssignD({(Addr)&z}, (Addr)&temp_var_for_tac_18,
          "/home/shijia/Public/testprogram/e_log2.c_e.c:139:5");
  ;
  i = hx - IC(0x6147a);
  double temp_var_for_tac_19;
  temp_var_for_tac_19 = z * z;

  w = temp_var_for_tac_19;
  computeDMul((Addr)&temp_var_for_tac_19, {(Addr)&z, (Addr)&z},
              "/home/shijia/Public/testprogram/e_log2.c_e.c:141:9");
  AssignD({(Addr)&w}, (Addr)&temp_var_for_tac_19,
          "/home/shijia/Public/testprogram/e_log2.c_e.c:141:5");
  ;
  j = IC(0x6b851) - hx;
  double temp_var_for_tac_20, temp_var_for_tac_21, temp_var_for_tac_22,
      temp_var_for_tac_23, temp_var_for_tac_24;
  double temp_var_for_const_8, temp_var_for_const_9, temp_var_for_const_10;
  temp_var_for_tac_20 = w * Lg6;

  temp_var_for_tac_21 = Lg4 + temp_var_for_tac_20;

  temp_var_for_tac_22 = w * temp_var_for_tac_21;

  temp_var_for_tac_23 = Lg2 + temp_var_for_tac_22;

  temp_var_for_tac_24 = w * temp_var_for_tac_23;

  t1 = temp_var_for_tac_24;
  computeDMul((Addr)&temp_var_for_tac_20,
              {(Addr)&w, (Addr) &(temp_var_for_const_8 = Lg6)},
              "/home/shijia/Public/testprogram/e_log2.c_e.c:143:32");
  computeDAdd((Addr)&temp_var_for_tac_21, {(Addr) &(temp_var_for_const_9 = Lg4),
                                           (Addr)&temp_var_for_tac_20},
              "/home/shijia/Public/testprogram/e_log2.c_e.c:143:28");
  computeDMul((Addr)&temp_var_for_tac_22,
              {(Addr)&w, (Addr)&temp_var_for_tac_21},
              "/home/shijia/Public/testprogram/e_log2.c_e.c:143:21");
  computeDAdd(
      (Addr)&temp_var_for_tac_23,
      {(Addr) &(temp_var_for_const_10 = Lg2), (Addr)&temp_var_for_tac_22},
      "/home/shijia/Public/testprogram/e_log2.c_e.c:143:17");
  computeDMul((Addr)&temp_var_for_tac_24,
              {(Addr)&w, (Addr)&temp_var_for_tac_23},
              "/home/shijia/Public/testprogram/e_log2.c_e.c:143:10");
  AssignD({(Addr)&t1}, (Addr)&temp_var_for_tac_24,
          "/home/shijia/Public/testprogram/e_log2.c_e.c:143:6");
  ;
  double temp_var_for_tac_25, temp_var_for_tac_26, temp_var_for_tac_27,
      temp_var_for_tac_28, temp_var_for_tac_29, temp_var_for_tac_30,
      temp_var_for_tac_31;
  double temp_var_for_const_11, temp_var_for_const_12, temp_var_for_const_13,
      temp_var_for_const_14;
  temp_var_for_tac_25 = w * Lg7;

  temp_var_for_tac_26 = Lg5 + temp_var_for_tac_25;

  temp_var_for_tac_27 = w * temp_var_for_tac_26;

  temp_var_for_tac_28 = Lg3 + temp_var_for_tac_27;

  temp_var_for_tac_29 = w * temp_var_for_tac_28;

  temp_var_for_tac_30 = Lg1 + temp_var_for_tac_29;

  temp_var_for_tac_31 = z * temp_var_for_tac_30;

  t2 = temp_var_for_tac_31;
  computeDMul((Addr)&temp_var_for_tac_25,
              {(Addr)&w, (Addr) &(temp_var_for_const_11 = Lg7)},
              "/home/shijia/Public/testprogram/e_log2.c_e.c:144:43");
  computeDAdd(
      (Addr)&temp_var_for_tac_26,
      {(Addr) &(temp_var_for_const_12 = Lg5), (Addr)&temp_var_for_tac_25},
      "/home/shijia/Public/testprogram/e_log2.c_e.c:144:39");
  computeDMul((Addr)&temp_var_for_tac_27,
              {(Addr)&w, (Addr)&temp_var_for_tac_26},
              "/home/shijia/Public/testprogram/e_log2.c_e.c:144:32");
  computeDAdd(
      (Addr)&temp_var_for_tac_28,
      {(Addr) &(temp_var_for_const_13 = Lg3), (Addr)&temp_var_for_tac_27},
      "/home/shijia/Public/testprogram/e_log2.c_e.c:144:28");
  computeDMul((Addr)&temp_var_for_tac_29,
              {(Addr)&w, (Addr)&temp_var_for_tac_28},
              "/home/shijia/Public/testprogram/e_log2.c_e.c:144:21");
  computeDAdd(
      (Addr)&temp_var_for_tac_30,
      {(Addr) &(temp_var_for_const_14 = Lg1), (Addr)&temp_var_for_tac_29},
      "/home/shijia/Public/testprogram/e_log2.c_e.c:144:17");
  computeDMul((Addr)&temp_var_for_tac_31,
              {(Addr)&z, (Addr)&temp_var_for_tac_30},
              "/home/shijia/Public/testprogram/e_log2.c_e.c:144:10");
  AssignD({(Addr)&t2}, (Addr)&temp_var_for_tac_31,
          "/home/shijia/Public/testprogram/e_log2.c_e.c:144:6");
  ;
  i |= j;
  double temp_var_for_tac_32;
  temp_var_for_tac_32 = t2 + t1;

  R = temp_var_for_tac_32;
  computeDAdd((Addr)&temp_var_for_tac_32, {(Addr)&t2, (Addr)&t1},
              "/home/shijia/Public/testprogram/e_log2.c_e.c:146:10");
  AssignD({(Addr)&R}, (Addr)&temp_var_for_tac_32,
          "/home/shijia/Public/testprogram/e_log2.c_e.c:146:5");
  ;
  if (i > 0) {
    double temp_var_for_tac_33, temp_var_for_tac_34;
    double temp_var_for_const_15;
    temp_var_for_tac_33 = 0.5 * f;

    temp_var_for_tac_34 = temp_var_for_tac_33 * f;

    hfsq = temp_var_for_tac_34;
    computeDMul((Addr)&temp_var_for_tac_33,
                {(Addr) &(temp_var_for_const_15 = 0.5), (Addr)&f},
                "/home/shijia/Public/testprogram/e_log2.c_e.c:148:16");
    computeDMul((Addr)&temp_var_for_tac_34,
                {(Addr)&temp_var_for_tac_33, (Addr)&f},
                "/home/shijia/Public/testprogram/e_log2.c_e.c:148:20");
    AssignD({(Addr)&hfsq}, (Addr)&temp_var_for_tac_34,
            "/home/shijia/Public/testprogram/e_log2.c_e.c:148:10");
    ;
    double temp_var_for_ext_5;
    double temp_var_for_tac_35, temp_var_for_tac_36, temp_var_for_tac_37,
        temp_var_for_tac_38, temp_var_for_tac_39, temp_var_for_tac_40;
    double temp_var_for_const_16;
    temp_var_for_tac_35 = hfsq + R;

    temp_var_for_tac_36 = s * temp_var_for_tac_35;

    temp_var_for_tac_37 = hfsq - temp_var_for_tac_36;

    temp_var_for_tac_38 = temp_var_for_tac_37 - f;

    temp_var_for_tac_39 = temp_var_for_tac_38 / ln2;

    temp_var_for_tac_40 = dk - temp_var_for_tac_39;

    temp_var_for_ext_5 = temp_var_for_tac_40;
    computeDAdd((Addr)&temp_var_for_tac_35, {(Addr)&hfsq, (Addr)&R},
                "/home/shijia/Public/testprogram/e_log2.c_e.c:150:51");
    computeDMul((Addr)&temp_var_for_tac_36,
                {(Addr)&s, (Addr)&temp_var_for_tac_35},
                "/home/shijia/Public/testprogram/e_log2.c_e.c:150:43");
    computeDSub((Addr)&temp_var_for_tac_37,
                {(Addr)&hfsq, (Addr)&temp_var_for_tac_36},
                "/home/shijia/Public/testprogram/e_log2.c_e.c:150:38");
    computeDSub((Addr)&temp_var_for_tac_38,
                {(Addr)&temp_var_for_tac_37, (Addr)&f},
                "/home/shijia/Public/testprogram/e_log2.c_e.c:150:58");
    computeDDiv(
        (Addr)&temp_var_for_tac_39,
        {(Addr)&temp_var_for_tac_38, (Addr) &(temp_var_for_const_16 = ln2)},
        "/home/shijia/Public/testprogram/e_log2.c_e.c:150:63");
    computeDSub((Addr)&temp_var_for_tac_40,
                {(Addr)&dk, (Addr)&temp_var_for_tac_39},
                "/home/shijia/Public/testprogram/e_log2.c_e.c:150:29");
    AssignD({(Addr)&temp_var_for_ext_5}, (Addr)&temp_var_for_tac_40,
            "/home/shijia/Public/testprogram/e_log2.c_e.c:150:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_5;
  } else {
    double temp_var_for_ext_6;
    double temp_var_for_tac_41, temp_var_for_tac_42, temp_var_for_tac_43,
        temp_var_for_tac_44, temp_var_for_tac_45;
    double temp_var_for_const_17;
    temp_var_for_tac_41 = f - R;

    temp_var_for_tac_42 = s * temp_var_for_tac_41;

    temp_var_for_tac_43 = temp_var_for_tac_42 - f;

    temp_var_for_tac_44 = temp_var_for_tac_43 / ln2;

    temp_var_for_tac_45 = dk - temp_var_for_tac_44;

    temp_var_for_ext_6 = temp_var_for_tac_45;
    computeDSub((Addr)&temp_var_for_tac_41, {(Addr)&f, (Addr)&R},
                "/home/shijia/Public/testprogram/e_log2.c_e.c:156:40");
    computeDMul((Addr)&temp_var_for_tac_42,
                {(Addr)&s, (Addr)&temp_var_for_tac_41},
                "/home/shijia/Public/testprogram/e_log2.c_e.c:156:35");
    computeDSub((Addr)&temp_var_for_tac_43,
                {(Addr)&temp_var_for_tac_42, (Addr)&f},
                "/home/shijia/Public/testprogram/e_log2.c_e.c:156:46");
    computeDDiv(
        (Addr)&temp_var_for_tac_44,
        {(Addr)&temp_var_for_tac_43, (Addr) &(temp_var_for_const_17 = ln2)},
        "/home/shijia/Public/testprogram/e_log2.c_e.c:156:51");
    computeDSub((Addr)&temp_var_for_tac_45,
                {(Addr)&dk, (Addr)&temp_var_for_tac_44},
                "/home/shijia/Public/testprogram/e_log2.c_e.c:156:29");
    AssignD({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_45,
            "/home/shijia/Public/testprogram/e_log2.c_e.c:156:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_6;
  }
}
int main()
{
  std::ifstream inputFile("/home/shijia/Public/FpDebug-valgrind_3.12/valgrind/fpdebug/pso/exe-input/log2_t.txt", std::ios::in);
  double input;
  long double oracle, realError = 0.0, scError = 0.0, prealError = 0.0, pscError = 0.0;
  long double delta = 1.0e-20;
  int index,la=0,eq=0,sm=0;
  std::ifstream inputOracle("/home/shijia/Public/FpDebug-valgrind_3.12/valgrind/fpdebug/pso/mpfr/mpfrresults/log2_out.txt", std::ios::in);
  while (inputFile >> input)
  {
    double a = __ieee754_log2S(input);
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