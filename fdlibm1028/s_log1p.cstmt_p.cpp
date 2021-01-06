#include "../ScDebug/scdebug.h"
/* @(#)s_log1p.c 1.3 95/01/18 */
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
/* Modified by Naohiko Shimizu/Tokai University, Japan 1997/08/25,
   for performance improvement on pipelined processors.
*/

/* double log1p(double x)
 *
 * Method :
 *   1. Argument Reduction: find k and f such that
 *			1+x = 2^k * (1+f),
 *	   where  sqrt(2)/2 < 1+f < sqrt(2) .
 *
 *      Note. If k=0, then f=x is exact. However, if k!=0, then f
 *	may not be representable exactly. In that case, a correction
 *	term is need. Let u=1+x rounded. Let c = (1+x)-u, then
 *	log(1+x) - log(u) ~ c/u. Thus, we proceed to compute log(u),
 *	and add back the correction term c/u.
 *	(Note: when x > 2**53, one can simply return log(x))
 *
 *   2. Approximation of log1p(f).
 *	Let s = f/(2+f) ; based on log(1+f) = log(1+s) - log(1-s)
 *		 = 2s + 2/3 s**3 + 2/5 s**5 + .....,
 *	     = 2s + s*R
 *      We use a special Reme algorithm on [0,0.1716] to generate
 *	a polynomial of degree 14 to approximate R The maximum error
 *	of this polynomial approximation is bounded by 2**-58.45. In
 *	other words,
 *		        2      4      6      8      10      12      14
 *	    R(z) ~ Lp1*s +Lp2*s +Lp3*s +Lp4*s +Lp5*s  +Lp6*s  +Lp7*s
 *  	(the values of Lp1 to Lp7 are listed in the program)
 *	and
 *	    |      2          14          |     -58.45
 *	    | Lp1*s +...+Lp7*s    -  R(z) | <= 2
 *	    |                             |
 *	Note that 2s = f - s*f = f - hfsq + s*hfsq, where hfsq = f*f/2.
 *	In order to guarantee error in log below 1ulp, we compute log
 *	by
 *		log1p(f) = f - (hfsq - s*(hfsq+R)).
 *
 *	3. Finally, log1p(x) = k*ln2 + log1p(f).
 *			     = k*ln2_hi+(f-(hfsq-(s*(hfsq+R)+k*ln2_lo)))
 *	   Here ln2 is split into two floating point number:
 *			ln2_hi + ln2_lo,
 *	   where n*ln2_hi is always exact for |n| < 2000.
 *
 * Special cases:
 *	log1p(x) is NaN with signal if x < -1 (including -INF) ;
 *	log1p(+INF) is +INF; log1p(-1) is -INF with signal;
 *	log1p(NaN) is that NaN with no signal.
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
 *
 * Note: Assuming log() return accurate answer, the following
 *	 algorithm can be used to compute log1p(x) to within a few ULP:
 *
 *		u = 1+x;
 *		if(u==1.0) return x ; else
 *			   return log(u)*(x/(u-1.0));
 *
 *	 See HP-15C Advanced Functions Handbook, p.193.
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_log1p

double __ieee754_log1p(double x) {
  double hfsq, f, c, s, z, R, u, z2, z4, z6, R1, R2, R3, R4;
  int32_t k, hx, hu, ax;

  static const double ln2_hi =
      6.93147180369123816490e-01; /* 3fe62e42 fee00000 */
  static const double ln2_lo =
      1.90821492927058770002e-10; /* 3dea39ef 35793c76 */
  static const double two54 =
      1.80143985094819840000e+16; /* 43500000 00000000 */
  static const double Lp[] = {
      0.0, 6.666666666666735130e-01, /* 3FE55555 55555593 */
      3.999999999940941908e-01,      /* 3FD99999 9997FA04 */
      2.857142874366239149e-01,      /* 3FD24924 94229359 */
      2.222219843214978396e-01,      /* 3FCC71C5 1D8E78AF */
      1.818357216161805012e-01,      /* 3FC74664 96CB03DE */
      1.531383769920937332e-01,      /* 3FC39A09 D078C69F */
      1.479819860511658591e-01       /* 3FC2F112 DF3E5244 */
  };
  static const double zero = 0.0;

  GET_HIGH_WORD(hx, x);
  ax = hx & IC(0x7fffffff);

  k = 1;
  if (hx < IC(0x3FDA827A)) {    /* x < 0.41422  */
    if (ax >= IC(0x3ff00000)) { /* x <= -1.0 */
      if (x == -1.0)
        return -two54 / zero; /* log1p(-1)=+inf */
      else
        return (x - x) / (x - x); /* log1p(x<-1)=NaN */
    }
    if (ax < IC(0x3e200000)) {    /* |x| < 2**-29 */
      math_force_eval(two54 + x); /* raise inexact */
      if (ax < IC(0x3c900000))    /* |x| < 2**-54 */
        return x;
      else
        return x - x * x * 0.5;
    }
    if (hx > 0 || hx <= IC(0xbfd2bec3)) {
      k = 0;
      f = x;
      hu = 1;
      c = 0;
    } /* -0.2929<x<0.41422 */
  } else if (hx >= IC(0x7ff00000))
    return x + x;
  if (k != 0) {
    if (hx < IC(0x43400000)) {
      u = 1.0 + x;
      GET_HIGH_WORD(hu, u);
      k = (hu >> 20) - 1023;
      c = (k > 0) ? 1.0 - (u - x) : x - (u - 1.0); /* correction term */
      c /= u;
    } else {
      u = x;
      GET_HIGH_WORD(hu, u);
      k = (hu >> 20) - 1023;
      c = 0;
    }
    hu &= IC(0x000fffff);
    if (hu < IC(0x6a09e)) {
      SET_HIGH_WORD(u, hu | IC(0x3ff00000)); /* normalize u */
    } else {
      k += 1;
      SET_HIGH_WORD(u, hu | IC(0x3fe00000)); /* normalize u/2 */
      hu = (IC(0x00100000) - hu) >> 2;
    }
    f = u - 1.0;
  }
  hfsq = 0.5 * f * f;
  double temp_var_for_const_0;
  computeDMul((Addr)&hfsq,
              {(Addr) &(temp_var_for_const_0 = 0.5), (Addr)&f, (Addr)&f},
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:157:8");
  if (hu == 0) { /* |f| < 2**-20 */
    if (f == zero) {
      if (k == 0)
        return zero;
      else {
        c += k * ln2_lo;
        return k * ln2_hi + c;
      }
    }
    R = hfsq * (1.0 - 0.66666666666666666 * f);
    if (k == 0)
      return f - R;
    else
      return k * ln2_hi - ((R - (k * ln2_lo + c)) - f);
  }
  s = f / (2.0 + f);
  double temp_var_for_const_1;
  double temp_var_for_tac_0;
  computeDAdd((Addr)&temp_var_for_tac_0,
              {(Addr) &(temp_var_for_const_1 = 2.0), (Addr)&f},
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:173:9");
  computeDDiv((Addr)&s, {(Addr)&f, (Addr)&temp_var_for_tac_0},
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:173:5");
  z = s * s;
  computeDMul((Addr)&z, {(Addr)&s, (Addr)&s},
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:174:5");
#ifdef DO_NOT_USE_THIS
  R = z * (Lp1 +
           z * (Lp2 + z * (Lp3 + z * (Lp4 + z * (Lp5 + z * (Lp6 + z * Lp7))))));
#else
  R1 = z * Lp[1];
  double temp_var_for_const_2;
  computeDMul((Addr)&R1, {(Addr)&z, (Addr) &(temp_var_for_const_2 = Lp[1])},
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:179:6");
  z2 = z * z;
  computeDMul((Addr)&z2, {(Addr)&z, (Addr)&z},
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:180:6");
  R2 = Lp[2] + z * Lp[3];
  double temp_var_for_const_3, temp_var_for_const_4;
  double temp_var_for_tac_1;
  computeDMul((Addr)&temp_var_for_tac_1,
              {(Addr)&z, (Addr) &(temp_var_for_const_3 = Lp[3])},
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:181:14");
  computeDAdd((Addr)&R2, {(Addr) &(temp_var_for_const_4 = Lp[2]),
                          (Addr)&temp_var_for_tac_1},
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:181:6");
  z4 = z2 * z2;
  computeDMul((Addr)&z4, {(Addr)&z2, (Addr)&z2},
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:182:6");
  R3 = Lp[4] + z * Lp[5];
  double temp_var_for_const_5, temp_var_for_const_6;
  double temp_var_for_tac_2;
  computeDMul((Addr)&temp_var_for_tac_2,
              {(Addr)&z, (Addr) &(temp_var_for_const_5 = Lp[5])},
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:183:14");
  computeDAdd((Addr)&R3, {(Addr) &(temp_var_for_const_6 = Lp[4]),
                          (Addr)&temp_var_for_tac_2},
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:183:6");
  z6 = z4 * z2;
  computeDMul((Addr)&z6, {(Addr)&z4, (Addr)&z2},
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:184:6");
  R4 = Lp[6] + z * Lp[7];
  double temp_var_for_const_7, temp_var_for_const_8;
  double temp_var_for_tac_3;
  computeDMul((Addr)&temp_var_for_tac_3,
              {(Addr)&z, (Addr) &(temp_var_for_const_7 = Lp[7])},
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:185:14");
  computeDAdd((Addr)&R4, {(Addr) &(temp_var_for_const_8 = Lp[6]),
                          (Addr)&temp_var_for_tac_3},
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:185:6");
  R = R1 + z2 * R2 + z4 * R3 + z6 * R4;
  double temp_var_for_tac_4, temp_var_for_tac_5, temp_var_for_tac_6,
      temp_var_for_tac_7, temp_var_for_tac_8;
  computeDMul((Addr)&temp_var_for_tac_4, {(Addr)&z2, (Addr)&R2},
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:186:10");
  computeDAdd((Addr)&temp_var_for_tac_5, {(Addr)&R1, (Addr)&temp_var_for_tac_4},
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:186:25");
  computeDMul((Addr)&temp_var_for_tac_6, {(Addr)&z4, (Addr)&R3},
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:186:20");
  computeDAdd((Addr)&temp_var_for_tac_7,
              {(Addr)&temp_var_for_tac_5, (Addr)&temp_var_for_tac_6},
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:186:35");
  computeDMul((Addr)&temp_var_for_tac_8, {(Addr)&z6, (Addr)&R4},
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:186:30");
  computeDAdd((Addr)&R, {(Addr)&temp_var_for_tac_7, (Addr)&temp_var_for_tac_8},
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:186:5");
#endif
  if (k == 0)
    return f - (hfsq - s * (hfsq + R));
  else
    return k * ln2_hi - ((hfsq - (s * (hfsq + R) + (k * ln2_lo + c))) - f);
}

#endif

/* wrapper log1p(x) */
double __log1p(double x) {
  if (islessequal(x, -1.0) && _LIB_VERSION != _IEEE_) {
    if (x == -1.0) {
      feraiseexcept(FE_DIVBYZERO);
      return __kernel_standard(x, x, -HUGE_VAL, KMATHERR_LOG_ZERO); /* log(0) */
    } else {
      feraiseexcept(FE_INVALID);
      return __kernel_standard(x, x, __builtin_nan(""),
                               KMATHERR_LOG_MINUS); /* log(x<0) */
    }
  }

  double temp_var_for_ext_0;
  temp_var_for_ext_0 = __ieee754_log1p(x);
  double temp_var_for_callexp_0 =
      __ieee754_log1p(getFVbyShadow<double>((Addr)&x));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_callexp_0,
          "/home/shijia/Public/testprogram/s_log1p.c_e.c:210:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

__typeof(__log1p) log1p __attribute__((weak, alias("__log1p")));
#ifdef __NO_LONG_DOUBLE_MATH
long double __log1pl(long double x) __attribute__((alias("__log1p")));
__typeof(__log1pl) log1pl __attribute__((weak, alias("__log1p")));
#endif
