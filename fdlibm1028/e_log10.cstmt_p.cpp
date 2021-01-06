#include "../ScDebug/scdebug.h"
/* @(#)e_log10.c 1.3 95/01/18 */
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

/* __ieee754_log10(x)
 * Return the base 10 logarithm of x
 *
 * Method :
 *	Let log10_2hi = leading 40 bits of log10(2) and
 *	    log10_2lo = log10(2) - log10_2hi,
 *	    ivln10   = 1/log(10) rounded.
 *	Then
 *		n = ilogb(x),
 *		if(n<0)  n = n+1;
 *		x = scalbn(x,-n);
 *		log10(x) := n*log10_2hi + (n*log10_2lo + ivln10*log(x))
 *
 * Note 1:
 *	To guarantee log10(10**n)=n, where 10**n is normal, the rounding
 *	mode must set to Round-to-Nearest.
 * Note 2:
 *	[1/log(10)] rounded to 53 bits has error  .198   ulps;
 *	log10 is monotonic at all binary break points.
 *
 * Special cases:
 *	log10(x) is NaN with signal if x < 0;
 *	log10(+INF) is +INF with no signal; log10(0) is -INF with signal;
 *	log10(NaN) is that NaN with no signal;
 *	log10(10**N) = N  for N=0,1,...,22.
 *
 * Constants:
 * The hexadecimal values are the intended ones for the following constants.
 * The decimal values may be used, provided that the compiler will convert
 * from decimal to binary accurately enough to produce the hexadecimal values
 * shown.
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_log10

double __ieee754_log10(double x) {
  double y, z;
  int32_t i, k, hx;
  uint32_t lx;

  static const double two54 =
      1.80143985094819840000e+16; /* 0x43500000, 0x00000000 */
  static const double ivln10 =
      4.34294481903251816668e-01; /* 0x3FDBCB7B, 0x1526E50E */
  static const double log10_2hi =
      3.01029995663611771306e-01; /* 0x3FD34413, 0x509F6000 */
  static const double log10_2lo =
      3.69423907715893078616e-13; /* 0x3D59FEF3, 0x11F12B36 */

  static const double zero = 0.0;

  GET_DOUBLE_WORDS(hx, lx, x);

  k = 0;
  if (hx < IC(0x00100000)) { /* x < 2**-1022  */
    if (((hx & IC(0x7fffffff)) | lx) == 0)
      return -two54 / zero; /* log(+-0)=-inf */
    if (hx < 0)
      return (x - x) / zero; /* log(-#) = NaN */
    k -= 54;
    x *= two54; /* subnormal number, scale up x */
    GET_HIGH_WORD(hx, x);
  }
  if (hx >= IC(0x7ff00000))
    return x + x;
  k += (hx >> 20) - 1023;
  i = ((uint32_t)k & UC(0x80000000)) >> 31;
  hx = (hx & IC(0x000fffff)) | ((0x3ff - i) << 20);
  y = (double)(k + i);
  SET_HIGH_WORD(x, hx);
  z = y * log10_2lo + ivln10 * __ieee754_log(x);
  double temp_var_for_const_0, temp_var_for_const_1, temp_var_for_const_2;
  double temp_var_for_tac_0, temp_var_for_tac_1;
  computeDMul((Addr)&temp_var_for_tac_0,
              {(Addr)&y, (Addr) &(temp_var_for_const_0 = log10_2lo)},
              "toString(biExpr->getExprLoc())");
computeDMul((Addr)&temp_var_for_tac_1,{(Addr)&(temp_var_for_const_2=ivln10),(Addr)&(temp_var_for_const_1=__ieee754_log(getFVbyShadow<int>((Addr)&x))},"/home/shijia/Public/testprogram/e_log10.c_e.c:87:21");
computeDAdd((Addr)&z, {(Addr)&temp_var_for_tac_0, (Addr)&temp_var_for_tac_1},
            "/home/shijia/Public/testprogram/e_log10.c_e.c:87:5");
double temp_var_for_ext_0;
temp_var_for_ext_0 = z + y * log10_2hi;
double temp_var_for_const_3;
double temp_var_for_tac_2;
computeDMul((Addr)&temp_var_for_tac_2,
            {(Addr)&y, (Addr) &(temp_var_for_const_3 = log10_2hi)},
            "/home/shijia/Public/testprogram/e_log10.c_e.c:89:26");
computeDAdd((Addr)&temp_var_for_ext_0, {(Addr)&z, (Addr)&temp_var_for_tac_2},
            "/home/shijia/Public/testprogram/e_log10.c_e.c:89:22");
callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
callExp++; /*identify the function is  add move tmpShadow*/
return temp_var_for_ext_0;
}
#endif

/* wrapper log10(x) */
double __log10(double x) {
  if (_LIB_VERSION != _IEEE_ && islessequal(x, 0.0)) {
    if (x == 0.0) {
      feraiseexcept(FE_DIVBYZERO);
      return __kernel_standard(x, x, -HUGE_VAL,
                               KMATHERR_LOG10_ZERO); /* log10(0) */
    } else {
      feraiseexcept(FE_INVALID);
      return __kernel_standard(x, x, __builtin_nan(""),
                               KMATHERR_LOG10_MINUS); /* log10(x<0) */
    }
  }

  double temp_var_for_ext_1;
  temp_var_for_ext_1 = __ieee754_log10(x);
  double temp_var_for_callexp_0 =
      __ieee754_log10(getFVbyShadow<double>((Addr)&x));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_callexp_0,
          "/home/shijia/Public/testprogram/e_log10.c_e.c:111:22");
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

__typeof(__log10) log10 __attribute__((weak, alias("__log10")));
#ifdef __NO_LONG_DOUBLE_MATH
long double __log10l(long double x) __attribute__((alias("__log10")));
__typeof(__log10l) log10l __attribute__((weak, alias("__log10")));
#endif
