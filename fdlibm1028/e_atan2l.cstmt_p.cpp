#include "../ScDebug/scdebug.h"
/* e_atan2l.c -- long double version of e_atan2.c.
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

/* __ieee754_atan2l(y,x)
 * Method :
 *	1. Reduce y to positive by atan2(y,x)=-atan2(-y,x).
 *	2. Reduce x to positive by (if x and y are unexceptional):
 *		ARG (x+iy) = arctan(y/x)	   ... if x > 0,
 *		ARG (x+iy) = pi - arctan[y/(-x)]   ... if x < 0,
 *
 * Special cases:
 *
 *	ATAN2((anything), NaN ) is NaN;
 *	ATAN2(NAN , (anything) ) is NaN;
 *	ATAN2(+-0, +(anything but NaN)) is +-0  ;
 *	ATAN2(+-0, -(anything but NaN)) is +-pi ;
 *	ATAN2(+-(anything but 0 and NaN), 0) is +-pi/2;
 *	ATAN2(+-(anything but INF and NaN), +INF) is +-0 ;
 *	ATAN2(+-(anything but INF and NaN), -INF) is +-pi;
 *	ATAN2(+-INF,+INF ) is +-pi/4 ;
 *	ATAN2(+-INF,-INF ) is +-3pi/4;
 *	ATAN2(+-INF, (anything but,0,NaN, and INF)) is +-pi/2;
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

#ifndef __NO_LONG_DOUBLE_MATH

#ifndef __have_fpu_atan2

long double __ieee754_atan2l(long double y, long double x) {
  long double z;
  int32_t k, m, hx, hy, ix, iy;
  uint32_t sx, sy, lx, ly;

  static const long double tiny = 1.0e-4900L;
  static const long double zero = 0.0;
  static const long double pi_o_4 =
      7.85398163397448309628202E-01L; /* 0x3FFE, 0xC90FDAA2, 0x2168C235 */
  static const long double pi_o_2 =
      1.5707963267948966192564E+00L; /* 0x3FFF, 0xC90FDAA2, 0x2168C235 */
  static const long double pi =
      3.14159265358979323851281E+00L; /* 0x4000, 0xC90FDAA2, 0x2168C235 */
  static const long double pi_lo = (0.0 - 5.01655761266833202345176e-20L);
  long double temp_var_for_const_0, temp_var_for_const_1;
  ; /* 0xBFBE, 0xECE675D1, 0xFC8F8CBB */

  GET_LDOUBLE_WORDS(sx, hx, lx, x);
  ix = sx & 0x7fff;
  lx |= hx & IC(0x7fffffff);
  GET_LDOUBLE_WORDS(sy, hy, ly, y);
  iy = sy & 0x7fff;
  ly |= hy & IC(0x7fffffff);
  if (((2 * ix | ((lx | -lx) >> 31)) > UC(0xfffe)) ||
      ((2 * iy | ((ly | -ly) >> 31)) > UC(0xfffe))) /* x or y is NaN */
    return x + y;
  if (((sx - 0x3fff) | lx) == 0)
    return __ieee754_atanl(y);             /* x=1.0 */
  m = ((sy >> 15) & 1) | ((sx >> 14) & 2); /* 2*sign(x)+sign(y) */

  /* when y = 0 */
  if ((iy | ly) == 0) {
    switch ((int)m) {
    case 0:
    case 1:
      return y; /* atan(+-0,+anything)=+-0 */
    case 2:
      return pi + tiny; /* atan(+0,-anything) = pi */
    case 3:
      return -pi - tiny; /* atan(-0,-anything) =-pi */
    }
  }
  /* when x = 0 */
  if ((ix | lx) == 0)
    return (sy & 0x8000) ? -pi_o_2 - tiny : pi_o_2 + tiny;

  /* when x is INF */
  if (ix == 0x7fff) {
    if (iy == 0x7fff) {
      switch ((int)m) {
      case 0:
        return pi_o_4 + tiny; /* atan(+INF,+INF) */
      case 1:
        return -pi_o_4 - tiny; /* atan(-INF,+INF) */
      case 2:
        return 3.0 * pi_o_4 + tiny; /*atan(+INF,-INF) */
      case 3:
        return -3.0 * pi_o_4 - tiny; /*atan(-INF,-INF) */
      }
    } else {
      switch ((int)m) {
      case 0:
        return zero; /* atan(+...,+INF) */
      case 1:
        return -zero; /* atan(-...,+INF) */
      case 2:
        return pi + tiny; /* atan(+...,-INF) */
      case 3:
        return -pi - tiny; /* atan(-...,-INF) */
      }
    }
  }
  /* when y is INF */
  if (iy == 0x7fff)
    return (sy & 0x8000) ? -pi_o_2 - tiny : pi_o_2 + tiny;

  /* compute y/x */
  k = iy - ix;
  if (k > 70)
    z = pi_o_2 + 0.5L * pi_lo; /* |y/x| >  2**70 */
  else if ((sx & 0x8000) && k < -70)
    z = 0.0; /* |y|/x < -2**70 */
  else
    z = __ieee754_atanl(__ieee754_fabsl(y / x)); /* safe to do y/x */
  switch ((int)m) {
  case 0:
    return z; /* atan(+,+) */
  case 1: {
    uint32_t sz;

    GET_LDOUBLE_EXP(sz, z);
    SET_LDOUBLE_EXP(z, sz ^ UC(0x8000));
  }
    return z; /* atan(-,+) */
  case 2:
    return pi - (z - pi_lo); /* atan(+,-) */
  default:                   /* case 3 */
    return (z - pi_lo) - pi; /* atan(-,-) */
  }
  long double temp_var_for_tac_0;
  computeLdSub(
      (Addr)&temp_var_for_tac_0,
      {(Addr) &(temp_var_for_const_1 = 0.0),
       (Addr) &(temp_var_for_const_0 = 5.01655761266833202345176e-20L)},
      "toString(biExpr->getExprLoc())");
}

#endif

long double __atan2l(long double y, long double x) {
  if (x == 0.0 && y == 0.0 && _LIB_VERSION == _SVID_)
    return __kernel_standard_l(y, x, HUGE_VALL,
                               KMATHERRL_ATAN2); /* atan2(+-0,+-0) */

  long double temp_var_for_ext_0;
  temp_var_for_ext_0 = __ieee754_atan2l(y, x);
  long double temp_var_for_callexp_0 =
      __ieee754_atan2l(getFVbyShadow<long double>((Addr)&y),
                       getFVbyShadow<long double>((Addr)&x));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  AssignLd({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_callexp_0,
           "/home/shijia/Public/testprogram/e_atan2l.c_e.c:161:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

__typeof(__atan2l) atan2l __attribute__((weak, alias("__atan2l")));

#endif
