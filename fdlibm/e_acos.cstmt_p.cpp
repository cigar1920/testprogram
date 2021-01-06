#include "../ScDebug/scdebug.h"
/* @(#)e_acos.c 1.3 95/01/18 */
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

/* __ieee754_acos(x)
 * Method :
 *	acos(x)  = pi/2 - asin(x)
 *	acos(-x) = pi/2 + asin(x)
 * For |x|<=0.5
 *	acos(x) = pi/2 - (x + x*x^2*R(x^2))	(see asin.c)
 * For x>0.5
 * 	acos(x) = pi/2 - (pi/2 - 2asin(sqrt((1-x)/2)))
 *		= 2asin(sqrt((1-x)/2))
 *		= 2s + 2s*z*R(z) 	...z=(1-x)/2, s=sqrt(z)
 *		= 2f + (2c + 2s*z*R(z))
 *     where f=hi part of s, and c = (z-f*f)/(s+f) is the correction term
 *     for f so that f+c ~ sqrt(z).
 * For x<-0.5
 *	acos(x) = pi - 2asin(sqrt((1-|x|)/2))
 *		= pi - 0.5*(s+s*z*R(z)), where z=(1-|x|)/2,s=sqrt(z)
 *
 * Special cases:
 *	if x is NaN, return x itself;
 *	if |x|>1, return NaN with invalid signal.
 *
 * Function needed: sqrt
 */

#ifndef __FDLIBM_H__
#include "./include/fdlibm.h"
#include "./e_sqrt.c"
#endif

#ifndef __have_fpu_acos

double __ieee754_acos(double x) {
  double z, p, q, r, w, s, c, df;
  int32_t hx, ix;

  static const double one =
      1.00000000000000000000e+00; /* 0x3FF00000, 0x00000000 */
  static const double pi =
      3.14159265358979311600e+00; /* 0x400921FB, 0x54442D18 */
  static const double pio2_hi =
      1.57079632679489655800e+00; /* 0x3FF921FB, 0x54442D18 */
  static const double pio2_lo =
      6.12323399573676603587e-17; /* 0x3C91A626, 0x33145C07 */
  static const double pS0 =
      1.66666666666666657415e-01; /* 0x3FC55555, 0x55555555 */
  static const double pS1 = (0.0 - 3.25565818622400915405e-01);
  double temp_var_for_const_4, temp_var_for_const_5;
  ; /* 0xBFD4D612, 0x03EB6F7D */
  static const double pS2 =
      2.01212532134862925881e-01; /* 0x3FC9C155, 0x0E884455 */
  static const double pS3 = (0.0 - 4.00555345006794114027e-02);
  double temp_var_for_const_6, temp_var_for_const_7;
  double temp_var_for_tac_5;
  computeDSub((Addr)&temp_var_for_tac_5,
              {(Addr) &(temp_var_for_const_5 = 0.0),
               (Addr) &(temp_var_for_const_4 = 3.25565818622400915405e-01)},
              "/home/shijia/Public/testprogram/e_acos.c_e.c:63:12");
  ; /* 0xBFA48228, 0xB5688F3B */
  static const double pS4 =
      7.91534994289814532176e-04; /* 0x3F49EFE0, 0x7501B288 */
  static const double pS5 =
      3.47933107596021167570e-05; /* 0x3F023DE1, 0x0DFDF709 */
  static const double qS1 = (0.0 - 2.40339491173441421878e+00);
  double temp_var_for_const_8, temp_var_for_const_9;
  double temp_var_for_tac_6;
  computeDSub((Addr)&temp_var_for_tac_6,
              {(Addr) &(temp_var_for_const_7 = 0.0),
               (Addr) &(temp_var_for_const_6 = 4.00555345006794114027e-02)},
              "/home/shijia/Public/testprogram/e_acos.c_e.c:69:12");
  ; /* 0xC0033A27, 0x1C8A2D4B */
  static const double qS2 =
      2.02094576023350569471e+00; /* 0x40002AE5, 0x9C598AC8 */
  static const double qS3 = (0.0 - 6.88283971605453293030e-01);
  double temp_var_for_const_10, temp_var_for_const_11;
  double temp_var_for_tac_7;
  computeDSub((Addr)&temp_var_for_tac_7,
              {(Addr) &(temp_var_for_const_9 = 0.0),
               (Addr) &(temp_var_for_const_8 = 2.40339491173441421878e+00)},
              "/home/shijia/Public/testprogram/e_acos.c_e.c:73:12");
  ; /* 0xBFE6066C, 0x1B8D0159 */
  static const double qS4 =
      7.70381505559019352791e-02; /* 0x3FB3B8C5, 0xB12E9282 */

  GET_HIGH_WORD(hx, x);
  ix = hx & IC(0x7fffffff);
  if (ix >= IC(0x3ff00000)) { /* |x| >= 1 */
    uint32_t lx;

    GET_LOW_WORD(lx, x);
    if (((ix - IC(0x3ff00000)) | lx) == 0) { /* |x|==1 */
      if (hx > 0)
        double temp_var_for_ext_0;
      temp_var_for_ext_0 = 0.0;
      callExpStack.push(
          getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_0; /* acos(1) = 0  */
      else double temp_var_for_ext_1;
      temp_var_for_ext_1 = pi + 2.0 * pio2_lo;
      callExpStack.push(
          getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_1; /* acos(-1)= pi */
    }
    double temp_var_for_ext_2;
    temp_var_for_ext_2 = (x - x) / (x - x);
    double temp_var_for_tac_9, temp_var_for_tac_10;
    computeDSub((Addr)&temp_var_for_tac_9, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:99:39");
    computeDSub((Addr)&temp_var_for_tac_10, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:99:34");
    computeDDiv((Addr)&temp_var_for_ext_2,
                {(Addr)&temp_var_for_tac_9, (Addr)&temp_var_for_tac_10},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:99:24");
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++;                 /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2; /* acos(|x|>1) is NaN */
  }

  if (ix < IC(0x3fe00000)) { /* |x| < 0.5 */
    if (ix <= IC(0x3c600000))
      double temp_var_for_ext_3;
    temp_var_for_ext_3 = pio2_hi + pio2_lo;
    callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
    callExp++;                 /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_3; /*if|x|<2**-57 */
    z = x * x;
    computeDMul((Addr)&z, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:112:7");
    p = z * (pS0 + z * (pS1 + z * (pS2 + z * (pS3 + z * (pS4 + z * pS5)))));
    double temp_var_for_const_12, temp_var_for_const_13, temp_var_for_const_14,
        temp_var_for_const_15, temp_var_for_const_16, temp_var_for_const_17;
    double temp_var_for_tac_11, temp_var_for_tac_12, temp_var_for_tac_13,
        temp_var_for_tac_14, temp_var_for_tac_15, temp_var_for_tac_16,
        temp_var_for_tac_17, temp_var_for_tac_18, temp_var_for_tac_19,
        temp_var_for_tac_20;
    computeDMul((Addr)&temp_var_for_tac_11,
                {(Addr)&z, (Addr) &(temp_var_for_const_12 = pS5)},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:113:62");
    computeDAdd(
        (Addr)&temp_var_for_tac_12,
        {(Addr) &(temp_var_for_const_13 = pS4), (Addr)&temp_var_for_tac_11},
        "/home/shijia/Public/testprogram/e_acos.c_e.c:113:55");
    computeDMul((Addr)&temp_var_for_tac_13,
                {(Addr)&z, (Addr)&temp_var_for_tac_12},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:113:51");
    computeDAdd(
        (Addr)&temp_var_for_tac_14,
        {(Addr) &(temp_var_for_const_14 = pS3), (Addr)&temp_var_for_tac_13},
        "/home/shijia/Public/testprogram/e_acos.c_e.c:113:44");
    computeDMul((Addr)&temp_var_for_tac_15,
                {(Addr)&z, (Addr)&temp_var_for_tac_14},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:113:40");
    computeDAdd(
        (Addr)&temp_var_for_tac_16,
        {(Addr) &(temp_var_for_const_15 = pS2), (Addr)&temp_var_for_tac_15},
        "/home/shijia/Public/testprogram/e_acos.c_e.c:113:33");
    computeDMul((Addr)&temp_var_for_tac_17,
                {(Addr)&z, (Addr)&temp_var_for_tac_16},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:113:29");
    computeDAdd(
        (Addr)&temp_var_for_tac_18,
        {(Addr) &(temp_var_for_const_16 = pS1), (Addr)&temp_var_for_tac_17},
        "/home/shijia/Public/testprogram/e_acos.c_e.c:113:22");
    computeDMul((Addr)&temp_var_for_tac_19,
                {(Addr)&z, (Addr)&temp_var_for_tac_18},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:113:18");
    computeDAdd(
        (Addr)&temp_var_for_tac_20,
        {(Addr) &(temp_var_for_const_17 = pS0), (Addr)&temp_var_for_tac_19},
        "/home/shijia/Public/testprogram/e_acos.c_e.c:113:11");
    computeDMul((Addr)&p, {(Addr)&z, (Addr)&temp_var_for_tac_20},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:113:7");
    q = one + z * (qS1 + z * (qS2 + z * (qS3 + z * qS4)));
    double temp_var_for_const_18, temp_var_for_const_19, temp_var_for_const_20,
        temp_var_for_const_21, temp_var_for_const_22;
    double temp_var_for_tac_21, temp_var_for_tac_22, temp_var_for_tac_23,
        temp_var_for_tac_24, temp_var_for_tac_25, temp_var_for_tac_26,
        temp_var_for_tac_27;
    computeDMul((Addr)&temp_var_for_tac_21,
                {(Addr)&z, (Addr) &(temp_var_for_const_18 = qS4)},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:114:46");
    computeDAdd(
        (Addr)&temp_var_for_tac_22,
        {(Addr) &(temp_var_for_const_19 = qS3), (Addr)&temp_var_for_tac_21},
        "/home/shijia/Public/testprogram/e_acos.c_e.c:114:39");
    computeDMul((Addr)&temp_var_for_tac_23,
                {(Addr)&z, (Addr)&temp_var_for_tac_22},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:114:35");
    computeDAdd(
        (Addr)&temp_var_for_tac_24,
        {(Addr) &(temp_var_for_const_20 = qS2), (Addr)&temp_var_for_tac_23},
        "/home/shijia/Public/testprogram/e_acos.c_e.c:114:28");
    computeDMul((Addr)&temp_var_for_tac_25,
                {(Addr)&z, (Addr)&temp_var_for_tac_24},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:114:24");
    computeDAdd(
        (Addr)&temp_var_for_tac_26,
        {(Addr) &(temp_var_for_const_21 = qS1), (Addr)&temp_var_for_tac_25},
        "/home/shijia/Public/testprogram/e_acos.c_e.c:114:17");
    computeDMul((Addr)&temp_var_for_tac_27,
                {(Addr)&z, (Addr)&temp_var_for_tac_26},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:114:13");
    computeDAdd((Addr)&q, {(Addr) &(temp_var_for_const_22 = one),
                           (Addr)&temp_var_for_tac_27},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:114:7");
    r = p / q;
    computeDDiv((Addr)&r, {(Addr)&p, (Addr)&q},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:115:7");
    double temp_var_for_ext_4;
    temp_var_for_ext_4 = pio2_hi - (x - (pio2_lo - x * r));
    double temp_var_for_const_23, temp_var_for_const_24;
    double temp_var_for_tac_28, temp_var_for_tac_29, temp_var_for_tac_30;
    computeDMul((Addr)&temp_var_for_tac_28, {(Addr)&x, (Addr)&r},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:117:50");
    computeDSub(
        (Addr)&temp_var_for_tac_29,
        {(Addr) &(temp_var_for_const_23 = pio2_lo), (Addr)&temp_var_for_tac_28},
        "/home/shijia/Public/testprogram/e_acos.c_e.c:117:39");
    computeDSub((Addr)&temp_var_for_tac_30,
                {(Addr)&x, (Addr)&temp_var_for_tac_29},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:117:34");
    computeDSub(
        (Addr)&temp_var_for_ext_4,
        {(Addr) &(temp_var_for_const_24 = pio2_hi), (Addr)&temp_var_for_tac_30},
        "/home/shijia/Public/testprogram/e_acos.c_e.c:117:24");
    callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_4;
  } else if (hx < 0) { /* x < -0.5 */
    z = (one + x) * 0.5;
    double temp_var_for_const_25, temp_var_for_const_26;
    double temp_var_for_tac_31;
    computeDAdd((Addr)&temp_var_for_tac_31,
                {(Addr) &(temp_var_for_const_25 = one), (Addr)&x},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:122:19");
    computeDMul((Addr)&z, {(Addr)&temp_var_for_tac_31,
                           (Addr) &(temp_var_for_const_26 = 0.5)},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:122:7");
    p = z * (pS0 + z * (pS1 + z * (pS2 + z * (pS3 + z * (pS4 + z * pS5)))));
    double temp_var_for_const_27, temp_var_for_const_28, temp_var_for_const_29,
        temp_var_for_const_30, temp_var_for_const_31, temp_var_for_const_32;
    double temp_var_for_tac_32, temp_var_for_tac_33, temp_var_for_tac_34,
        temp_var_for_tac_35, temp_var_for_tac_36, temp_var_for_tac_37,
        temp_var_for_tac_38, temp_var_for_tac_39, temp_var_for_tac_40,
        temp_var_for_tac_41;
    computeDMul((Addr)&temp_var_for_tac_32,
                {(Addr)&z, (Addr) &(temp_var_for_const_27 = pS5)},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:123:62");
    computeDAdd(
        (Addr)&temp_var_for_tac_33,
        {(Addr) &(temp_var_for_const_28 = pS4), (Addr)&temp_var_for_tac_32},
        "/home/shijia/Public/testprogram/e_acos.c_e.c:123:55");
    computeDMul((Addr)&temp_var_for_tac_34,
                {(Addr)&z, (Addr)&temp_var_for_tac_33},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:123:51");
    computeDAdd(
        (Addr)&temp_var_for_tac_35,
        {(Addr) &(temp_var_for_const_29 = pS3), (Addr)&temp_var_for_tac_34},
        "/home/shijia/Public/testprogram/e_acos.c_e.c:123:44");
    computeDMul((Addr)&temp_var_for_tac_36,
                {(Addr)&z, (Addr)&temp_var_for_tac_35},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:123:40");
    computeDAdd(
        (Addr)&temp_var_for_tac_37,
        {(Addr) &(temp_var_for_const_30 = pS2), (Addr)&temp_var_for_tac_36},
        "/home/shijia/Public/testprogram/e_acos.c_e.c:123:33");
    computeDMul((Addr)&temp_var_for_tac_38,
                {(Addr)&z, (Addr)&temp_var_for_tac_37},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:123:29");
    computeDAdd(
        (Addr)&temp_var_for_tac_39,
        {(Addr) &(temp_var_for_const_31 = pS1), (Addr)&temp_var_for_tac_38},
        "/home/shijia/Public/testprogram/e_acos.c_e.c:123:22");
    computeDMul((Addr)&temp_var_for_tac_40,
                {(Addr)&z, (Addr)&temp_var_for_tac_39},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:123:18");
    computeDAdd(
        (Addr)&temp_var_for_tac_41,
        {(Addr) &(temp_var_for_const_32 = pS0), (Addr)&temp_var_for_tac_40},
        "/home/shijia/Public/testprogram/e_acos.c_e.c:123:11");
    computeDMul((Addr)&p, {(Addr)&z, (Addr)&temp_var_for_tac_41},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:123:7");
    q = one + z * (qS1 + z * (qS2 + z * (qS3 + z * qS4)));
    double temp_var_for_const_33, temp_var_for_const_34, temp_var_for_const_35,
        temp_var_for_const_36, temp_var_for_const_37;
    double temp_var_for_tac_42, temp_var_for_tac_43, temp_var_for_tac_44,
        temp_var_for_tac_45, temp_var_for_tac_46, temp_var_for_tac_47,
        temp_var_for_tac_48;
    computeDMul((Addr)&temp_var_for_tac_42,
                {(Addr)&z, (Addr) &(temp_var_for_const_33 = qS4)},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:124:46");
    computeDAdd(
        (Addr)&temp_var_for_tac_43,
        {(Addr) &(temp_var_for_const_34 = qS3), (Addr)&temp_var_for_tac_42},
        "/home/shijia/Public/testprogram/e_acos.c_e.c:124:39");
    computeDMul((Addr)&temp_var_for_tac_44,
                {(Addr)&z, (Addr)&temp_var_for_tac_43},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:124:35");
    computeDAdd(
        (Addr)&temp_var_for_tac_45,
        {(Addr) &(temp_var_for_const_35 = qS2), (Addr)&temp_var_for_tac_44},
        "/home/shijia/Public/testprogram/e_acos.c_e.c:124:28");
    computeDMul((Addr)&temp_var_for_tac_46,
                {(Addr)&z, (Addr)&temp_var_for_tac_45},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:124:24");
    computeDAdd(
        (Addr)&temp_var_for_tac_47,
        {(Addr) &(temp_var_for_const_36 = qS1), (Addr)&temp_var_for_tac_46},
        "/home/shijia/Public/testprogram/e_acos.c_e.c:124:17");
    computeDMul((Addr)&temp_var_for_tac_48,
                {(Addr)&z, (Addr)&temp_var_for_tac_47},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:124:13");
    computeDAdd((Addr)&q, {(Addr) &(temp_var_for_const_37 = one),
                           (Addr)&temp_var_for_tac_48},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:124:7");
    s = __ieee754_sqrt(z);
    double temp_var_for_callexp_0 =
        __ieee754_sqrt(getFVbyShadow<double>((Addr)&z));
    CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
    AssignD({(Addr)&s}, (Addr)&temp_var_for_callexp_0,
            "/home/shijia/Public/testprogram/e_acos.c_e.c:125:7");
    r = p / q;
    computeDDiv((Addr)&r, {(Addr)&p, (Addr)&q},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:126:7");
    w = r * s - pio2_lo;
    double temp_var_for_const_38;
    double temp_var_for_tac_49;
    computeDMul((Addr)&temp_var_for_tac_49, {(Addr)&r, (Addr)&s},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:127:15");
    computeDSub((Addr)&w, {(Addr)&temp_var_for_tac_49,
                           (Addr) &(temp_var_for_const_38 = pio2_lo)},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:127:7");
    double temp_var_for_ext_5;
    temp_var_for_ext_5 = pi - 2.0 * (s + w);
    double temp_var_for_const_39, temp_var_for_const_40;
    double temp_var_for_tac_50, temp_var_for_tac_51;
    computeDAdd((Addr)&temp_var_for_tac_50, {(Addr)&s, (Addr)&w},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:129:35");
    computeDMul(
        (Addr)&temp_var_for_tac_51,
        {(Addr) &(temp_var_for_const_39 = 2.0), (Addr)&temp_var_for_tac_50},
        "/home/shijia/Public/testprogram/e_acos.c_e.c:129:29");
    computeDSub(
        (Addr)&temp_var_for_ext_5,
        {(Addr) &(temp_var_for_const_40 = pi), (Addr)&temp_var_for_tac_51},
        "/home/shijia/Public/testprogram/e_acos.c_e.c:129:24");
    callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_5;
  } else { /* x > 0.5 */
    z = (one - x) * 0.5;
    double temp_var_for_const_41, temp_var_for_const_42;
    double temp_var_for_tac_52;
    computeDSub((Addr)&temp_var_for_tac_52,
                {(Addr) &(temp_var_for_const_41 = one), (Addr)&x},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:134:19");
    computeDMul((Addr)&z, {(Addr)&temp_var_for_tac_52,
                           (Addr) &(temp_var_for_const_42 = 0.5)},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:134:7");
    s = __ieee754_sqrt(z);
    double temp_var_for_callexp_1 =
        __ieee754_sqrt(getFVbyShadow<double>((Addr)&z));
    CallStackPop((Addr)&temp_var_for_callexp_1, getTop(temp_var_for_callexp_1));
    AssignD({(Addr)&s}, (Addr)&temp_var_for_callexp_1,
            "/home/shijia/Public/testprogram/e_acos.c_e.c:135:7");
    df = s;
    AssignD({(Addr)&df}, (Addr)&s,
            "/home/shijia/Public/testprogram/e_acos.c_e.c:136:8");
    SET_LOW_WORD(df, 0);
    c = (z - df * df) / (s + df);
    double temp_var_for_tac_53, temp_var_for_tac_54, temp_var_for_tac_55;
    computeDMul((Addr)&temp_var_for_tac_53, {(Addr)&df, (Addr)&df},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:138:12");
    computeDSub((Addr)&temp_var_for_tac_54,
                {(Addr)&z, (Addr)&temp_var_for_tac_53},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:138:28");
    computeDAdd((Addr)&temp_var_for_tac_55, {(Addr)&s, (Addr)&df},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:138:23");
    computeDDiv((Addr)&c,
                {(Addr)&temp_var_for_tac_54, (Addr)&temp_var_for_tac_55},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:138:7");
    p = z * (pS0 + z * (pS1 + z * (pS2 + z * (pS3 + z * (pS4 + z * pS5)))));
    double temp_var_for_const_43, temp_var_for_const_44, temp_var_for_const_45,
        temp_var_for_const_46, temp_var_for_const_47, temp_var_for_const_48;
    double temp_var_for_tac_56, temp_var_for_tac_57, temp_var_for_tac_58,
        temp_var_for_tac_59, temp_var_for_tac_60, temp_var_for_tac_61,
        temp_var_for_tac_62, temp_var_for_tac_63, temp_var_for_tac_64,
        temp_var_for_tac_65;
    computeDMul((Addr)&temp_var_for_tac_56,
                {(Addr)&z, (Addr) &(temp_var_for_const_43 = pS5)},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:139:62");
    computeDAdd(
        (Addr)&temp_var_for_tac_57,
        {(Addr) &(temp_var_for_const_44 = pS4), (Addr)&temp_var_for_tac_56},
        "/home/shijia/Public/testprogram/e_acos.c_e.c:139:55");
    computeDMul((Addr)&temp_var_for_tac_58,
                {(Addr)&z, (Addr)&temp_var_for_tac_57},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:139:51");
    computeDAdd(
        (Addr)&temp_var_for_tac_59,
        {(Addr) &(temp_var_for_const_45 = pS3), (Addr)&temp_var_for_tac_58},
        "/home/shijia/Public/testprogram/e_acos.c_e.c:139:44");
    computeDMul((Addr)&temp_var_for_tac_60,
                {(Addr)&z, (Addr)&temp_var_for_tac_59},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:139:40");
    computeDAdd(
        (Addr)&temp_var_for_tac_61,
        {(Addr) &(temp_var_for_const_46 = pS2), (Addr)&temp_var_for_tac_60},
        "/home/shijia/Public/testprogram/e_acos.c_e.c:139:33");
    computeDMul((Addr)&temp_var_for_tac_62,
                {(Addr)&z, (Addr)&temp_var_for_tac_61},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:139:29");
    computeDAdd(
        (Addr)&temp_var_for_tac_63,
        {(Addr) &(temp_var_for_const_47 = pS1), (Addr)&temp_var_for_tac_62},
        "/home/shijia/Public/testprogram/e_acos.c_e.c:139:22");
    computeDMul((Addr)&temp_var_for_tac_64,
                {(Addr)&z, (Addr)&temp_var_for_tac_63},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:139:18");
    computeDAdd(
        (Addr)&temp_var_for_tac_65,
        {(Addr) &(temp_var_for_const_48 = pS0), (Addr)&temp_var_for_tac_64},
        "/home/shijia/Public/testprogram/e_acos.c_e.c:139:11");
    computeDMul((Addr)&p, {(Addr)&z, (Addr)&temp_var_for_tac_65},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:139:7");
    q = one + z * (qS1 + z * (qS2 + z * (qS3 + z * qS4)));
    double temp_var_for_const_49, temp_var_for_const_50, temp_var_for_const_51,
        temp_var_for_const_52, temp_var_for_const_53;
    double temp_var_for_tac_66, temp_var_for_tac_67, temp_var_for_tac_68,
        temp_var_for_tac_69, temp_var_for_tac_70, temp_var_for_tac_71,
        temp_var_for_tac_72;
    computeDMul((Addr)&temp_var_for_tac_66,
                {(Addr)&z, (Addr) &(temp_var_for_const_49 = qS4)},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:140:46");
    computeDAdd(
        (Addr)&temp_var_for_tac_67,
        {(Addr) &(temp_var_for_const_50 = qS3), (Addr)&temp_var_for_tac_66},
        "/home/shijia/Public/testprogram/e_acos.c_e.c:140:39");
    computeDMul((Addr)&temp_var_for_tac_68,
                {(Addr)&z, (Addr)&temp_var_for_tac_67},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:140:35");
    computeDAdd(
        (Addr)&temp_var_for_tac_69,
        {(Addr) &(temp_var_for_const_51 = qS2), (Addr)&temp_var_for_tac_68},
        "/home/shijia/Public/testprogram/e_acos.c_e.c:140:28");
    computeDMul((Addr)&temp_var_for_tac_70,
                {(Addr)&z, (Addr)&temp_var_for_tac_69},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:140:24");
    computeDAdd(
        (Addr)&temp_var_for_tac_71,
        {(Addr) &(temp_var_for_const_52 = qS1), (Addr)&temp_var_for_tac_70},
        "/home/shijia/Public/testprogram/e_acos.c_e.c:140:17");
    computeDMul((Addr)&temp_var_for_tac_72,
                {(Addr)&z, (Addr)&temp_var_for_tac_71},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:140:13");
    computeDAdd((Addr)&q, {(Addr) &(temp_var_for_const_53 = one),
                           (Addr)&temp_var_for_tac_72},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:140:7");
    r = p / q;
    computeDDiv((Addr)&r, {(Addr)&p, (Addr)&q},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:141:7");
    w = r * s + c;
    double temp_var_for_tac_73;
    computeDMul((Addr)&temp_var_for_tac_73, {(Addr)&r, (Addr)&s},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:142:15");
    computeDAdd((Addr)&w, {(Addr)&temp_var_for_tac_73, (Addr)&c},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:142:7");
    double temp_var_for_ext_6;
    temp_var_for_ext_6 = 2.0 * (df + w);
    double temp_var_for_const_54;
    double temp_var_for_tac_74;
    computeDAdd((Addr)&temp_var_for_tac_74, {(Addr)&df, (Addr)&w},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:144:30");
    computeDMul(
        (Addr)&temp_var_for_ext_6,
        {(Addr) &(temp_var_for_const_54 = 2.0), (Addr)&temp_var_for_tac_74},
        "/home/shijia/Public/testprogram/e_acos.c_e.c:144:24");
    callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_6;
  }
}

#endif

int main() {
  printf("%lf\n", __ieee754_acos(0.5));
  return 0;
}

// /* wrapper acos */
// double __acos(double x)
// {
// 	if (_LIB_VERSION != _IEEE_ && isgreater(__ieee754_fabs(x), 1.0))
// 	{
// 		/* acos(|x|>1) */
// 		feraiseexcept(FE_INVALID);
// 		return __kernel_standard(x, x, __builtin_nan(""),
// KMATHERR_ACOS);
// 	}

// 	return __ieee754_acos(x);
// }

// __typeof(__acos) acos __attribute__((weak, alias("__acos")));
// #ifdef __NO_LONG_DOUBLE_MATH
// __typeof(__acosl) __acosl __attribute__((alias("__acos")));
// __typeof(__acosl) acosl __attribute__((weak, alias("__acos")));
// #endif
