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

#ifndef __have_fpu_log2

double __ieee754_log2(double x) {
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
    if (((hx & IC(0x7fffffff)) | lx) == 0)
      return -two54 / (x - x); /* log(+-0)=-inf */
    if (hx < 0)
      return (x - x) / (x - x); /* log(-#) = NaN */
    k -= 54;
    x *= two54; /* subnormal number, scale up x */
    GET_HIGH_WORD(hx, x);
  }
  if (hx >= IC(0x7ff00000))
    return x + x;
  k += (hx >> 20) - 1023;
  hx &= IC(0x000fffff);
  i = (hx + IC(0x95f64)) & IC(0x100000);
  SET_HIGH_WORD(x, hx | (i ^ IC(0x3ff00000))); /* normalize x or x/2 */
  k += (i >> 20);
  dk = (double)k;
  f = x - 1.0;
  double temp_var_for_const_0;
  computeDSub((Addr)&f, {(Addr)&x, (Addr) &(temp_var_for_const_0 = 1.0)},
              "/home/shijia/Public/testprogram/e_log2.c_e.c:100:5");
  if ((IC(0x000fffff) & (2 + hx)) < 3) { /* |f| < 2**-20 */
    if (f == zero)
      return dk;
    R = f * f * (0.5 - 0.33333333333333333 * f);
    return dk - (R - f) / ln2;
  }
  s = f / (2.0 + f);
  double temp_var_for_const_1;
  double temp_var_for_tac_0;
  computeDAdd((Addr)&temp_var_for_tac_0,
              {(Addr) &(temp_var_for_const_1 = 2.0), (Addr)&f},
              "/home/shijia/Public/testprogram/e_log2.c_e.c:107:9");
  computeDDiv((Addr)&s, {(Addr)&f, (Addr)&temp_var_for_tac_0},
              "/home/shijia/Public/testprogram/e_log2.c_e.c:107:5");
  z = s * s;
  computeDMul((Addr)&z, {(Addr)&s, (Addr)&s},
              "/home/shijia/Public/testprogram/e_log2.c_e.c:108:5");
  i = hx - IC(0x6147a);
  w = z * z;
  computeDMul((Addr)&w, {(Addr)&z, (Addr)&z},
              "/home/shijia/Public/testprogram/e_log2.c_e.c:110:5");
  j = IC(0x6b851) - hx;
  t1 = w * (Lg2 + w * (Lg4 + w * Lg6));
  double temp_var_for_const_2, temp_var_for_const_3, temp_var_for_const_4;
  double temp_var_for_tac_1, temp_var_for_tac_2, temp_var_for_tac_3,
      temp_var_for_tac_4;
  computeDMul((Addr)&temp_var_for_tac_1,
              {(Addr)&w, (Addr) &(temp_var_for_const_2 = Lg6)},
              "/home/shijia/Public/testprogram/e_log2.c_e.c:112:28");
  computeDAdd((Addr)&temp_var_for_tac_2,
              {(Addr) &(temp_var_for_const_3 = Lg4), (Addr)&temp_var_for_tac_1},
              "/home/shijia/Public/testprogram/e_log2.c_e.c:112:21");
  computeDMul((Addr)&temp_var_for_tac_3, {(Addr)&w, (Addr)&temp_var_for_tac_2},
              "/home/shijia/Public/testprogram/e_log2.c_e.c:112:17");
  computeDAdd((Addr)&temp_var_for_tac_4,
              {(Addr) &(temp_var_for_const_4 = Lg2), (Addr)&temp_var_for_tac_3},
              "/home/shijia/Public/testprogram/e_log2.c_e.c:112:10");
  computeDMul((Addr)&t1, {(Addr)&w, (Addr)&temp_var_for_tac_4},
              "/home/shijia/Public/testprogram/e_log2.c_e.c:112:6");
  t2 = z * (Lg1 + w * (Lg3 + w * (Lg5 + w * Lg7)));
  double temp_var_for_const_5, temp_var_for_const_6, temp_var_for_const_7,
      temp_var_for_const_8;
  double temp_var_for_tac_5, temp_var_for_tac_6, temp_var_for_tac_7,
      temp_var_for_tac_8, temp_var_for_tac_9, temp_var_for_tac_10;
  computeDMul((Addr)&temp_var_for_tac_5,
              {(Addr)&w, (Addr) &(temp_var_for_const_5 = Lg7)},
              "/home/shijia/Public/testprogram/e_log2.c_e.c:113:39");
  computeDAdd((Addr)&temp_var_for_tac_6,
              {(Addr) &(temp_var_for_const_6 = Lg5), (Addr)&temp_var_for_tac_5},
              "/home/shijia/Public/testprogram/e_log2.c_e.c:113:32");
  computeDMul((Addr)&temp_var_for_tac_7, {(Addr)&w, (Addr)&temp_var_for_tac_6},
              "/home/shijia/Public/testprogram/e_log2.c_e.c:113:28");
  computeDAdd((Addr)&temp_var_for_tac_8,
              {(Addr) &(temp_var_for_const_7 = Lg3), (Addr)&temp_var_for_tac_7},
              "/home/shijia/Public/testprogram/e_log2.c_e.c:113:21");
  computeDMul((Addr)&temp_var_for_tac_9, {(Addr)&w, (Addr)&temp_var_for_tac_8},
              "/home/shijia/Public/testprogram/e_log2.c_e.c:113:17");
  computeDAdd((Addr)&temp_var_for_tac_10,
              {(Addr) &(temp_var_for_const_8 = Lg1), (Addr)&temp_var_for_tac_9},
              "/home/shijia/Public/testprogram/e_log2.c_e.c:113:10");
  computeDMul((Addr)&t2, {(Addr)&z, (Addr)&temp_var_for_tac_10},
              "/home/shijia/Public/testprogram/e_log2.c_e.c:113:6");
  i |= j;
  R = t2 + t1;
  computeDAdd((Addr)&R, {(Addr)&t2, (Addr)&t1},
              "/home/shijia/Public/testprogram/e_log2.c_e.c:115:5");
  if (i > 0) {
    hfsq = 0.5 * f * f;
    return dk - ((hfsq - (s * (hfsq + R))) - f) / ln2;
  } else {
    return dk - ((s * (f - R)) - f) / ln2;
  }
}

#endif

/* wrapper log2(x) */
double __log2(double x) {
  if (islessequal(x, 0.0) && _LIB_VERSION != _IEEE_) {
    if (x == 0.0) {
      feraiseexcept(FE_DIVBYZERO);
      return __kernel_standard(x, x, -HUGE_VAL,
                               KMATHERR_LOG2_ZERO); /* log2(0) */
    } else {
      feraiseexcept(FE_INVALID);
      return __kernel_standard(x, x, __builtin_nan(""),
                               KMATHERR_LOG2_MINUS); /* log2(x<0) */
    }
  }

  double temp_var_for_ext_0;
  temp_var_for_ext_0 = __ieee754_log2(x);
  double temp_var_for_callexp_0 =
      __ieee754_log2(getFVbyShadow<double>((Addr)&x));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_callexp_0,
          "/home/shijia/Public/testprogram/e_log2.c_e.c:141:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

__typeof(__log2) log2 __attribute__((weak, alias("__log2")));
#ifdef __NO_LONG_DOUBLE_MATH
long double __log2l(long double x) __attribute__((alias("__log2")));
__typeof(__log2l) log2l __attribute__((weak, alias("__log2")));
#endif
