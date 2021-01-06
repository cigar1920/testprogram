#include "../ScDebug/scdebug.h"
/* @(#)e_exp.c 1.3 95/01/18 */
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

/* __ieee754_exp(x)
 * Returns the exponential of x.
 *
 * Method
 *   1. Argument reduction:
 *      Reduce x to an r so that |r| <= 0.5*ln2 ~ 0.34658.
 *	Given x, find r and integer k such that
 *
 *               x = k*ln2 + r,  |r| <= 0.5*ln2.
 *
 *      Here r will be represented as r = hi-lo for better
 *	accuracy.
 *
 *   2. Approximation of exp(r) by a special rational function on
 *	the interval [0,0.34658]:
 *	Write
 *	    R(r**2) = r*(exp(r)+1)/(exp(r)-1) = 2 + r*r/6 - r**4/360 + ...
 *      We use a special Reme algorithm on [0,0.34658] to generate
 * 	a polynomial of degree 5 to approximate R. The maximum error
 *	of this polynomial approximation is bounded by 2**-59. In
 *	other words,
 *	    R(z) ~ 2.0 + P1*z + P2*z**2 + P3*z**3 + P4*z**4 + P5*z**5
 *  	(where z=r*r, and the values of P1 to P5 are listed below)
 *	and
 *	    |                  5          |     -59
 *	    | 2.0+P1*z+...+P5*z   -  R(z) | <= 2
 *	    |                             |
 *	The computation of exp(r) thus becomes
 *                             2*r
 *		exp(r) = 1 + -------
 *		              R - r
 *                                 r*R1(r)
 *		       = 1 + r + ----------- (for better accuracy)
 *		                  2 - R1(r)
 *	where
 *			         2       4             10
 *		R1(r) = r - (P1*r  + P2*r  + ... + P5*r   ).
 *
 *   3. Scale back to obtain exp(x):
 *	From step 1, we have
 *	   exp(x) = 2^k * exp(r)
 *
 * Special cases:
 *	exp(INF) is INF, exp(NaN) is NaN;
 *	exp(-INF) is 0, and
 *	for finite argument, only exp(0)=1 is exact.
 *
 * Accuracy:
 *	according to an error analysis, the error is always less than
 *	1 ulp (unit in the last place).
 *
 * Misc. info.
 *	For IEEE double
 *	    if x >  7.09782712893383973096e+02 then exp(x) overflow
 *	    if x < -7.45133219101941108420e+02 then exp(x) underflow
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

#ifndef __have_fpu_exp

double __ieee754_exp(double x) /* default IEEE double exp */
{
  double y, hi, lo, c, t;
  int32_t k, xsb;
  uint32_t hx;

  static const double one = 1.0;
  static const double halF[2] = { 0.5, (0.0 - 0.5);
  double temp_var_for_const_0, temp_var_for_const_1;
};

static const double hugeval = 1.0e+300;
static const double twom1000 =
    9.33263618503218878990e-302; /* 2**-1000=0x01700000,0 */
static const double o_threshold =
    7.09782712893383973096e+02; /* 0x40862E42, 0xFEFA39EF */
static const double u_threshold = (0.0 - 7.45133219101941108420e+02);
double temp_var_for_const_2, temp_var_for_const_3;
double temp_var_for_tac_0;
computeDSub((Addr)&temp_var_for_tac_0, {(Addr) &(temp_var_for_const_1 = 0.0),
                                        (Addr) &(temp_var_for_const_0 = 0.5)},
            "/home/shijia/Public/testprogram/e_exp.c_e.c:97:12");
; /* 0xc0874910, 0xD52D3051 */
static const double ln2HI[2] = {
  6.93147180369123816490e-01, /* 0x3fe62e42, 0xfee00000 */
  (0.0 - 6.93147180369123816490e-01);
double temp_var_for_const_4, temp_var_for_const_5;
double temp_var_for_tac_1;
computeDSub(
    (Addr)&temp_var_for_tac_1,
    {(Addr) &(temp_var_for_const_3 = 0.0),
     (Addr) &(temp_var_for_const_2 = 7.45133219101941108420e+02)},
    "/home/shijia/Public/testprogram/e_exp.c_e.c:100:12"); /* 0xbfe62e42,
                                                              0xfee00000 */
}
;

static const double ln2LO[2] = {
  1.90821492927058770002e-10, /* 0x3dea39ef, 0x35793c76 */
  (0.0 - 1.90821492927058770002e-10);
double temp_var_for_const_6, temp_var_for_const_7;
double temp_var_for_tac_2;
computeDSub(
    (Addr)&temp_var_for_tac_2,
    {(Addr) &(temp_var_for_const_5 = 0.0),
     (Addr) &(temp_var_for_const_4 = 6.93147180369123816490e-01)},
    "/home/shijia/Public/testprogram/e_exp.c_e.c:105:12"); /* 0xbdea39ef,
                                                              0x35793c76 */
}
;

static const double invln2 =
    1.44269504088896338700e+00; /* 0x3ff71547, 0x652b82fe */
static const double P1 =
    1.66666666666666019037e-01; /* 0x3FC55555, 0x5555553E */
static const double P2 = (0.0 - 2.77777777770155933842e-03);
double temp_var_for_const_8, temp_var_for_const_9;
double temp_var_for_tac_3;
computeDSub((Addr)&temp_var_for_tac_3,
            {(Addr) &(temp_var_for_const_7 = 0.0),
             (Addr) &(temp_var_for_const_6 = 1.90821492927058770002e-10)},
            "/home/shijia/Public/testprogram/e_exp.c_e.c:113:12");
; /* 0xBF66C16C, 0x16BEBD93 */
static const double P3 =
    6.61375632143793436117e-05; /* 0x3F11566A, 0xAF25DE2C */
static const double P4 = (0.0 - 1.65339022054652515390e-06);
double temp_var_for_const_10, temp_var_for_const_11;
double temp_var_for_tac_4;
computeDSub((Addr)&temp_var_for_tac_4,
            {(Addr) &(temp_var_for_const_9 = 0.0),
             (Addr) &(temp_var_for_const_8 = 2.77777777770155933842e-03)},
            "/home/shijia/Public/testprogram/e_exp.c_e.c:117:12");
; /* 0xBEBBBD41, 0xC5D26BF1 */
static const double P5 =
    4.13813679705723846039e-08; /* 0x3E663769, 0x72BEA4D0 */

GET_HIGH_WORD(hx, x); /* high word of x */
xsb = (hx >> 31) & 1; /* sign bit of x */
hx &= IC(0x7fffffff); /* high word of |x| */

/* filter out non-finite argument */
if (hx >= IC(0x40862E42)) { /* if |x|>=709.78... */
  if (hx >= IC(0x7ff00000)) {
    GET_LOW_WORD(k, x);
    if (((hx & IC(0xfffff)) | k) != 0)
      return x;                  /* NaN */
    return (xsb == 0) ? x : 0.0; /* exp(+-inf)={inf,0} */
  }
  if (x > o_threshold) /* overflow */
  {
    feraiseexcept(FE_OVERFLOW);
    return HUGE_VAL;
  }
  if (x < u_threshold) /* underflow */
  {
    feraiseexcept(FE_UNDERFLOW);
    return 0;
  }
}

/* argument reduction */
if (hx > IC(0x3fd62e42)) {   /* if  |x| > 0.5 ln2 */
  if (hx < IC(0x3FF0A2B2)) { /* and |x| < 1.5 ln2 */
    hi = x - ln2HI[xsb];
    lo = ln2LO[xsb];
    k = 1 - xsb - xsb;
  } else {
    k = invln2 * x + halF[xsb];
    t = k;
    hi = x - t * ln2HI[0]; /* t*ln2HI is exact here */
    lo = t * ln2LO[0];
  }
  x = hi - lo;
} else if (hx < IC(0x3e300000)) { /* when |x|<2**-28 */
  if (hugeval + x > one)
    return one + x; /* trigger inexact */
  return one;
} else {
  k = 0;
  lo = 0;
  hi = 0;
}

/* x is now in primary range */
t = x * x;
double temp_var_for_tac_5;
computeDSub((Addr)&temp_var_for_tac_5,
            {(Addr) &(temp_var_for_const_11 = 0.0),
             (Addr) &(temp_var_for_const_10 = 1.65339022054652515390e-06)},
            "/home/shijia/Public/testprogram/e_exp.c_e.c:169:9");
computeDMul((Addr)&t, {(Addr)&x, (Addr)&x},
            "/home/shijia/Public/testprogram/e_exp.c_e.c:169:5");
c = x - t * (P1 + t * (P2 + t * (P3 + t * (P4 + t * P5))));
double temp_var_for_const_12, temp_var_for_const_13, temp_var_for_const_14,
    temp_var_for_const_15, temp_var_for_const_16;
double temp_var_for_tac_6, temp_var_for_tac_7, temp_var_for_tac_8,
    temp_var_for_tac_9, temp_var_for_tac_10, temp_var_for_tac_11,
    temp_var_for_tac_12, temp_var_for_tac_13, temp_var_for_tac_14;
computeDMul((Addr)&temp_var_for_tac_6,
            {(Addr)&t, (Addr) &(temp_var_for_const_12 = P5)},
            "/home/shijia/Public/testprogram/e_exp.c_e.c:170:49");
computeDAdd((Addr)&temp_var_for_tac_7,
            {(Addr) &(temp_var_for_const_13 = P4), (Addr)&temp_var_for_tac_6},
            "/home/shijia/Public/testprogram/e_exp.c_e.c:170:43");
computeDMul((Addr)&temp_var_for_tac_8, {(Addr)&t, (Addr)&temp_var_for_tac_7},
            "/home/shijia/Public/testprogram/e_exp.c_e.c:170:39");
computeDAdd((Addr)&temp_var_for_tac_9,
            {(Addr) &(temp_var_for_const_14 = P3), (Addr)&temp_var_for_tac_8},
            "/home/shijia/Public/testprogram/e_exp.c_e.c:170:33");
computeDMul((Addr)&temp_var_for_tac_10, {(Addr)&t, (Addr)&temp_var_for_tac_9},
            "/home/shijia/Public/testprogram/e_exp.c_e.c:170:29");
computeDAdd((Addr)&temp_var_for_tac_11,
            {(Addr) &(temp_var_for_const_15 = P2), (Addr)&temp_var_for_tac_10},
            "/home/shijia/Public/testprogram/e_exp.c_e.c:170:23");
computeDMul((Addr)&temp_var_for_tac_12, {(Addr)&t, (Addr)&temp_var_for_tac_11},
            "/home/shijia/Public/testprogram/e_exp.c_e.c:170:19");
computeDAdd((Addr)&temp_var_for_tac_13,
            {(Addr) &(temp_var_for_const_16 = P1), (Addr)&temp_var_for_tac_12},
            "/home/shijia/Public/testprogram/e_exp.c_e.c:170:13");
computeDMul((Addr)&temp_var_for_tac_14, {(Addr)&t, (Addr)&temp_var_for_tac_13},
            "/home/shijia/Public/testprogram/e_exp.c_e.c:170:9");
computeDSub((Addr)&c, {(Addr)&x, (Addr)&temp_var_for_tac_14},
            "/home/shijia/Public/testprogram/e_exp.c_e.c:170:5");
if (k == 0)
  return one - ((x * c) / (c - 2.0) - x);
y = one - ((lo - (x * c) / (2.0 - c)) - hi);
double temp_var_for_const_17, temp_var_for_const_18;
double temp_var_for_tac_15, temp_var_for_tac_16, temp_var_for_tac_17,
    temp_var_for_tac_18, temp_var_for_tac_19;
computeDMul((Addr)&temp_var_for_tac_15, {(Addr)&x, (Addr)&c},
            "/home/shijia/Public/testprogram/e_exp.c_e.c:173:35");
computeDSub((Addr)&temp_var_for_tac_16,
            {(Addr) &(temp_var_for_const_17 = 2.0), (Addr)&c},
            "/home/shijia/Public/testprogram/e_exp.c_e.c:173:28");
computeDDiv((Addr)&temp_var_for_tac_17,
            {(Addr)&temp_var_for_tac_15, (Addr)&temp_var_for_tac_16},
            "/home/shijia/Public/testprogram/e_exp.c_e.c:173:18");
computeDSub((Addr)&temp_var_for_tac_18, {(Addr)&lo, (Addr)&temp_var_for_tac_17},
            "/home/shijia/Public/testprogram/e_exp.c_e.c:173:41");
computeDSub((Addr)&temp_var_for_tac_19, {(Addr)&temp_var_for_tac_18, (Addr)&hi},
            "/home/shijia/Public/testprogram/e_exp.c_e.c:173:11");
computeDSub((Addr)&y,
            {(Addr) &(temp_var_for_const_18 = one), (Addr)&temp_var_for_tac_19},
            "/home/shijia/Public/testprogram/e_exp.c_e.c:173:5");
GET_HIGH_WORD(hx, y);
if (k >= -1021) {
  hx += (k << IEEE754_DOUBLE_SHIFT); /* add k to y's exponent */
  SET_HIGH_WORD(y, hx);
  return y;
} else {
  hx += ((k + 1000) << IEEE754_DOUBLE_SHIFT); /* add k to y's exponent */
  SET_HIGH_WORD(y, hx);
  return y * twom1000;
}
}

#endif

/* wrapper exp */
double __exp(double x) {
  double z = __ieee754_exp(x);

  if (_LIB_VERSION != _IEEE_ && (!isfinite(z) || z == 0.0) && isfinite(x))
    return __kernel_standard(x, x, z, signbit(x) ? KMATHERR_EXP_UNDERFLOW
                                                 : KMATHERR_EXP_OVERFLOW);

  double temp_var_for_ext_0;
  temp_var_for_ext_0 = z;
  AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&z,
          "/home/shijia/Public/testprogram/e_exp.c_e.c:197:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

__typeof(__exp) exp __attribute__((weak, alias("__exp")));
#ifdef __NO_LONG_DOUBLE_MATH
long double __expl(long double x) __attribute__((alias("__exp")));
__typeof(__expl) expl __attribute__((weak, alias("__exp")));
#endif
