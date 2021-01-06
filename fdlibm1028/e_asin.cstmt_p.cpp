#include "../ScDebug/scdebug.h"
/* @(#)e_asin.c 1.3 95/01/18 */
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

/* __ieee754_asin(x)
 * Method :
 *	Since  asin(x) = x + x^3/6 + x^5*3/40 + x^7*15/336 + ...
 *	we approximate asin(x) on [0,0.5] by
 *		asin(x) = x + x*x^2*R(x^2)
 *	where
 *		R(x^2) is a rational approximation of (asin(x)-x)/x^3
 *	and its remez error is bounded by
 *		|(asin(x)-x)/x^3 - R(x^2)| < 2^(-58.75)
 *
 *	For x in [0.5,1]
 *		asin(x) = pi/2-2*asin(sqrt((1-x)/2))
 *	Let y = (1-x), z = y/2, s := sqrt(z), and pio2_hi+pio2_lo=pi/2;
 *	then for x>0.98
 *		asin(x) = pi/2 - 2*(s+s*z*R(z))
 *			= pio2_hi - (2*(s+s*z*R(z)) - pio2_lo)
 *	For x<=0.98, let pio4_hi = pio2_hi/2, then
 *		f = hi part of s;
 *		c = sqrt(z) - f = (z-f*f)/(s+f) 	...f+c=sqrt(z)
 *	and
 *		asin(x) = pi/2 - 2*(s+s*z*R(z))
 *			= pio4_hi+(pio4-2s)-(2s*z*R(z)-pio2_lo)
 *			= pio4_hi+(pio4-2f)-(2s*z*R(z)-(pio2_lo+2c))
 *
 * Special cases:
 *	if x is NaN, return x itself;
 *	if |x|>1, return NaN with invalid signal.
 *
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_asin

double __ieee754_asin(double x) {
  double t, w, p, q, c, r, s;
  int32_t hx, ix;

  static const double one =
      1.00000000000000000000e+00; /* 0x3FF00000, 0x00000000 */
  static const double hugeval = 1.000e+300;
  static const double pio2_hi =
      1.57079632679489655800e+00; /* 0x3FF921FB, 0x54442D18 */
  static const double pio2_lo =
      6.12323399573676603587e-17; /* 0x3C91A626, 0x33145C07 */
  static const double pio4_hi =
      7.85398163397448278999e-01; /* 0x3FE921FB, 0x54442D18 */
  /* coefficient for R(x^2) */
  static const double pS0 =
      1.66666666666666657415e-01; /* 0x3FC55555, 0x55555555 */
  static const double pS1 = (0.0 - 3.25565818622400915405e-01);
  double temp_var_for_const_0, temp_var_for_const_1;
  ; /* 0xBFD4D612, 0x03EB6F7D */
  static const double pS2 =
      2.01212532134862925881e-01; /* 0x3FC9C155, 0x0E884455 */
  static const double pS3 = (0.0 - 4.00555345006794114027e-02);
  double temp_var_for_const_2, temp_var_for_const_3;
  double temp_var_for_tac_0;
  computeDSub((Addr)&temp_var_for_tac_0,
              {(Addr) &(temp_var_for_const_1 = 0.0),
               (Addr) &(temp_var_for_const_0 = 3.25565818622400915405e-01)},
              "/home/shijia/Public/testprogram/e_asin.c_e.c:70:12");
  ; /* 0xBFA48228, 0xB5688F3B */
  static const double pS4 =
      7.91534994289814532176e-04; /* 0x3F49EFE0, 0x7501B288 */
  static const double pS5 =
      3.47933107596021167570e-05; /* 0x3F023DE1, 0x0DFDF709 */
  static const double qS1 = (0.0 - 2.40339491173441421878e+00);
  double temp_var_for_const_4, temp_var_for_const_5;
  double temp_var_for_tac_1;
  computeDSub((Addr)&temp_var_for_tac_1,
              {(Addr) &(temp_var_for_const_3 = 0.0),
               (Addr) &(temp_var_for_const_2 = 4.00555345006794114027e-02)},
              "/home/shijia/Public/testprogram/e_asin.c_e.c:76:12");
  ; /* 0xC0033A27, 0x1C8A2D4B */
  static const double qS2 =
      2.02094576023350569471e+00; /* 0x40002AE5, 0x9C598AC8 */
  static const double qS3 = (0.0 - 6.88283971605453293030e-01);
  double temp_var_for_const_6, temp_var_for_const_7;
  double temp_var_for_tac_2;
  computeDSub((Addr)&temp_var_for_tac_2,
              {(Addr) &(temp_var_for_const_5 = 0.0),
               (Addr) &(temp_var_for_const_4 = 2.40339491173441421878e+00)},
              "/home/shijia/Public/testprogram/e_asin.c_e.c:80:12");
  ; /* 0xBFE6066C, 0x1B8D0159 */
  static const double qS4 =
      7.70381505559019352791e-02; /* 0x3FB3B8C5, 0xB12E9282 */

  GET_HIGH_WORD(hx, x);
  ix = hx & IC(0x7fffffff);
  if (ix >= IC(0x3ff00000)) { /* |x|>= 1 */
    uint32_t lx;

    GET_LOW_WORD(lx, x);
    if (((ix - IC(0x3ff00000)) | lx) == 0)
      /* asin(1)=+-pi/2 with inexact */
      return x * pio2_hi + x * pio2_lo;
    return (x - x) / (x - x);       /* asin(|x|>1) is NaN */
  } else if (ix < IC(0x3fe00000)) { /* |x|<0.5 */
    if (ix < IC(0x3e400000)) {      /* if |x| < 2**-27 */
      if (hugeval + x > one)
        return x; /* return x with inexact if x!=0 */
    } else {
      t = x * x;
      p = t * (pS0 + t * (pS1 + t * (pS2 + t * (pS3 + t * (pS4 + t * pS5)))));
      q = one + t * (qS1 + t * (qS2 + t * (qS3 + t * qS4)));
      w = p / q;
      return x + x * w;
    }
  }
  /* 1> |x|>= 0.5 */
  w = one - __ieee754_fabs(x);
  double temp_var_for_const_8, temp_var_for_const_9;
  double temp_var_for_tac_3;
  computeDSub((Addr)&temp_var_for_tac_3,
              {(Addr) &(temp_var_for_const_7 = 0.0),
               (Addr) &(temp_var_for_const_6 = 6.88283971605453293030e-01)},
              "toString(biExpr->getExprLoc())");
computeDSub((Addr)&w,{(Addr)&(temp_var_for_const_9=one),(Addr)&(temp_var_for_const_8=__ieee754_fabs(getFVbyShadow<int>((Addr)&x))},"/home/shijia/Public/testprogram/e_asin.c_e.c:107:5");
t = w * 0.5;
double temp_var_for_const_10;
computeDMul((Addr)&t, {(Addr)&w, (Addr) &(temp_var_for_const_10 = 0.5)},
            "/home/shijia/Public/testprogram/e_asin.c_e.c:108:5");
p = t * (pS0 + t * (pS1 + t * (pS2 + t * (pS3 + t * (pS4 + t * pS5)))));
double temp_var_for_const_11, temp_var_for_const_12, temp_var_for_const_13,
    temp_var_for_const_14, temp_var_for_const_15, temp_var_for_const_16;
double temp_var_for_tac_4, temp_var_for_tac_5, temp_var_for_tac_6,
    temp_var_for_tac_7, temp_var_for_tac_8, temp_var_for_tac_9,
    temp_var_for_tac_10, temp_var_for_tac_11, temp_var_for_tac_12,
    temp_var_for_tac_13;
computeDMul((Addr)&temp_var_for_tac_4,
            {(Addr)&t, (Addr) &(temp_var_for_const_11 = pS5)},
            "/home/shijia/Public/testprogram/e_asin.c_e.c:109:60");
computeDAdd((Addr)&temp_var_for_tac_5,
            {(Addr) &(temp_var_for_const_12 = pS4), (Addr)&temp_var_for_tac_4},
            "/home/shijia/Public/testprogram/e_asin.c_e.c:109:53");
computeDMul((Addr)&temp_var_for_tac_6, {(Addr)&t, (Addr)&temp_var_for_tac_5},
            "/home/shijia/Public/testprogram/e_asin.c_e.c:109:49");
computeDAdd((Addr)&temp_var_for_tac_7,
            {(Addr) &(temp_var_for_const_13 = pS3), (Addr)&temp_var_for_tac_6},
            "/home/shijia/Public/testprogram/e_asin.c_e.c:109:42");
computeDMul((Addr)&temp_var_for_tac_8, {(Addr)&t, (Addr)&temp_var_for_tac_7},
            "/home/shijia/Public/testprogram/e_asin.c_e.c:109:38");
computeDAdd((Addr)&temp_var_for_tac_9,
            {(Addr) &(temp_var_for_const_14 = pS2), (Addr)&temp_var_for_tac_8},
            "/home/shijia/Public/testprogram/e_asin.c_e.c:109:31");
computeDMul((Addr)&temp_var_for_tac_10, {(Addr)&t, (Addr)&temp_var_for_tac_9},
            "/home/shijia/Public/testprogram/e_asin.c_e.c:109:27");
computeDAdd((Addr)&temp_var_for_tac_11,
            {(Addr) &(temp_var_for_const_15 = pS1), (Addr)&temp_var_for_tac_10},
            "/home/shijia/Public/testprogram/e_asin.c_e.c:109:20");
computeDMul((Addr)&temp_var_for_tac_12, {(Addr)&t, (Addr)&temp_var_for_tac_11},
            "/home/shijia/Public/testprogram/e_asin.c_e.c:109:16");
computeDAdd((Addr)&temp_var_for_tac_13,
            {(Addr) &(temp_var_for_const_16 = pS0), (Addr)&temp_var_for_tac_12},
            "/home/shijia/Public/testprogram/e_asin.c_e.c:109:9");
computeDMul((Addr)&p, {(Addr)&t, (Addr)&temp_var_for_tac_13},
            "/home/shijia/Public/testprogram/e_asin.c_e.c:109:5");
q = one + t * (qS1 + t * (qS2 + t * (qS3 + t * qS4)));
double temp_var_for_const_17, temp_var_for_const_18, temp_var_for_const_19,
    temp_var_for_const_20, temp_var_for_const_21;
double temp_var_for_tac_14, temp_var_for_tac_15, temp_var_for_tac_16,
    temp_var_for_tac_17, temp_var_for_tac_18, temp_var_for_tac_19,
    temp_var_for_tac_20;
computeDMul((Addr)&temp_var_for_tac_14,
            {(Addr)&t, (Addr) &(temp_var_for_const_17 = qS4)},
            "/home/shijia/Public/testprogram/e_asin.c_e.c:110:44");
computeDAdd((Addr)&temp_var_for_tac_15,
            {(Addr) &(temp_var_for_const_18 = qS3), (Addr)&temp_var_for_tac_14},
            "/home/shijia/Public/testprogram/e_asin.c_e.c:110:37");
computeDMul((Addr)&temp_var_for_tac_16, {(Addr)&t, (Addr)&temp_var_for_tac_15},
            "/home/shijia/Public/testprogram/e_asin.c_e.c:110:33");
computeDAdd((Addr)&temp_var_for_tac_17,
            {(Addr) &(temp_var_for_const_19 = qS2), (Addr)&temp_var_for_tac_16},
            "/home/shijia/Public/testprogram/e_asin.c_e.c:110:26");
computeDMul((Addr)&temp_var_for_tac_18, {(Addr)&t, (Addr)&temp_var_for_tac_17},
            "/home/shijia/Public/testprogram/e_asin.c_e.c:110:22");
computeDAdd((Addr)&temp_var_for_tac_19,
            {(Addr) &(temp_var_for_const_20 = qS1), (Addr)&temp_var_for_tac_18},
            "/home/shijia/Public/testprogram/e_asin.c_e.c:110:15");
computeDMul((Addr)&temp_var_for_tac_20, {(Addr)&t, (Addr)&temp_var_for_tac_19},
            "/home/shijia/Public/testprogram/e_asin.c_e.c:110:11");
computeDAdd((Addr)&q,
            {(Addr) &(temp_var_for_const_21 = one), (Addr)&temp_var_for_tac_20},
            "/home/shijia/Public/testprogram/e_asin.c_e.c:110:5");
s = __ieee754_sqrt(t);
double temp_var_for_const_22;AssignD({(Addr)&s},(Addr)&(temp_var_for_const_22=__ieee754_sqrt(getFVbyShadow<int>((Addr)&t)),"/home/shijia/Public/testprogram/e_asin.c_e.c:111:5");
  if (ix >= IC(0x3FEF3333)) { /* if |x| > 0.975 */
    w = p / q;
    t = pio2_hi - (2.0 * (s + s * w) - pio2_lo);
  } else {
    w = s;
    SET_LOW_WORD(w, 0);
    c = (t - w * w) / (s + w);
    r = p / q;
    p = 2.0 * s * r - (pio2_lo - 2.0 * c);
    q = pio4_hi - 2.0 * w;
    t = pio4_hi - (p - q);
  }
  if (hx > 0)
    return t;
  double temp_var_for_ext_0;
  temp_var_for_ext_0 = -t;AssignD({(Addr)&temp_var_for_ext_0},(Addr)&(-(t)),"/home/shijia/Public/testprogram/e_asin.c_e.c:127:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return (0.0 - 0);double temp_var_for_const_23,temp_var_for_const_24;;
double temp_var_for_tac_21 ;computeDSub((Addr)&temp_var_for_tac_21,{(Addr)&(temp_var_for_const_24=0.0),(Addr)&(temp_var_for_const_23=0)},"toString(biExpr->getExprLoc())");
}

#endif

/* wrapper asin */
double __asin(double x) {
  if (_LIB_VERSION != _IEEE_ && isgreater(__ieee754_fabs(x), 1.0)) {
    /* asin(|x|>1) */
    feraiseexcept(FE_INVALID);
    return __kernel_standard(x, x, __builtin_nan(""), KMATHERR_ASIN);
  }

  double temp_var_for_ext_1;
  temp_var_for_ext_1 = __ieee754_asin(x);
  double temp_var_for_callexp_0 =
      __ieee754_asin(getFVbyShadow<double>((Addr)&x));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_callexp_0,
          "/home/shijia/Public/testprogram/e_asin.c_e.c:144:22");
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

__typeof(__asin) asin __attribute__((weak, alias("__asin")));
#ifdef __NO_LONG_DOUBLE_MATH
__typeof(__asinl) __asinl __attribute__((alias("__asin")));
__typeof(__asinl) asinl __attribute__((weak, alias("__asin")));
#endif
