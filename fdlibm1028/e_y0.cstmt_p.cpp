#include "../ScDebug/scdebug.h"
/* @(#)e_y0.c 5.1 93/09/24 */
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
/* Modified by Naohiko Shimizu/Tokai University, Japan 1997/08/26,
   for performance improvement on pipelined processors.
*/
/* __ieee754_y0(x)
 * Bessel function of the second kind of order zero.
 *
 * Method -- y0(x):
 *	1. For x<2.
 *	   Since
 *		y0(x) = 2/pi*(j0(x)*(ln(x/2)+Euler) + x^2/4 - ...)
 *	   therefore y0(x)-2/pi*j0(x)*ln(x) is an even function.
 *	   We use the following function to approximate y0,
 *		y0(x) = U(z)/V(z) + (2/pi)*(j0(x)*ln(x)), z= x^2
 *	   where
 *		U(z) = u00 + u01*z + ... + u06*z^6
 *		V(z) = 1  + v01*z + ... + v04*z^4
 *	   with absolute approximation error bounded by 2**-72.
 *	   Note: For tiny x, U/V = u0 and j0(x)~1, hence
 *		y0(tiny) = u0 + (2/pi)*ln(tiny), (choose tiny<2**-27)
 *	2. For x>=2.
 *		y0(x) = sqrt(2/(pi*x))*(p0(x)*cos(x0)+q0(x)*sin(x0))
 *	   where x0 = x-pi/4. It is better to compute sin(x0),cos(x0)
 *	   by the method mentioned above.
 *	3. Special cases: y0(0)=-inf, y0(x<0)=NaN, y0(inf)=0.
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

double __ieee754_y0(double x) {
  double z, s, c, ss, cc, u, v, z2, z4, z6, u1, u2, u3, v1, v2;
  int32_t hx, ix, lx;

  static const double one = 1.0;
  static const double zero = 0.0;
  static const double invsqrtpi =
      5.64189583547756279280e-01; /* 0x3FE20DD7, 0x50429B6D */
  static const double tpi =
      6.36619772367581382433e-01; /* 0x3FE45F30, 0x6DC9C883 */

  static const double u00 = (0.0 - 7.38042951086872317523e-02);
  double temp_var_for_const_0, temp_var_for_const_1;
  ; /* 0xBFB2E4D6, 0x99CBD01F */
  static const double u01 =
      1.76666452509181115538e-01; /* 0x3FC69D01, 0x9DE9E3FC */
  static const double u02 = (0.0 - 1.38185671945596898896e-02);
  double temp_var_for_const_2, temp_var_for_const_3;
  double temp_var_for_tac_0;
  computeDSub((Addr)&temp_var_for_tac_0,
              {(Addr) &(temp_var_for_const_1 = 0.0),
               (Addr) &(temp_var_for_const_0 = 7.38042951086872317523e-02)},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:58:12");
  ; /* 0xBF8C4CE8, 0xB16CFA97 */
  static const double u03 =
      3.47453432093683650238e-04; /* 0x3F36C54D, 0x20B29B6B */
  static const double u04 = (0.0 - 3.81407053724364161125e-06);
  double temp_var_for_const_4, temp_var_for_const_5;
  double temp_var_for_tac_1;
  computeDSub((Addr)&temp_var_for_tac_1,
              {(Addr) &(temp_var_for_const_3 = 0.0),
               (Addr) &(temp_var_for_const_2 = 1.38185671945596898896e-02)},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:62:12");
  ; /* 0xBECFFEA7, 0x73D25CAD */
  static const double u05 =
      1.95590137035022920206e-08; /* 0x3E550057, 0x3B4EABD4 */
  static const double u06 = (0.0 - 3.98205194132103398453e-11);
  double temp_var_for_const_6, temp_var_for_const_7;
  double temp_var_for_tac_2;
  computeDSub((Addr)&temp_var_for_tac_2,
              {(Addr) &(temp_var_for_const_5 = 0.0),
               (Addr) &(temp_var_for_const_4 = 3.81407053724364161125e-06)},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:66:12");
  ; /* 0xBDC5E43D, 0x693FB3C8 */

  static const double v01 =
      1.27304834834123699328e-02; /* 0x3F8A1270, 0x91C9C71A */
  static const double v02 =
      7.60068627350353253702e-05; /* 0x3F13ECBB, 0xF578C6C1 */
  static const double v03 =
      2.59150851840457805467e-07; /* 0x3E91642D, 0x7FF202FD */
  static const double v04 =
      4.41110311332675467403e-10; /* 0x3DFE5018, 0x3BD6D9EF */

  GET_DOUBLE_WORDS(hx, lx, x);
  ix = IC(0x7fffffff) & hx;
  /* Y0(NaN) is NaN, y0(-inf) is Nan, y0(inf) is 0  */
  if (ix >= IC(0x7ff00000))
    return one / (x + x * x);
  if ((ix | lx) == 0)
    return -HUGE_VAL + x; /* -inf and overflow exception.  */
  if (hx < 0)
    return zero / zero;
  if (ix >= IC(0x40000000)) { /* |x| >= 2.0 */
    /* y0(x) = sqrt(2/(pi*x))*(p0(x)*sin(x0)+q0(x)*cos(x0))
     * where x0 = x-pi/4
     *      Better formula:
     *              cos(x0) = cos(x)cos(pi/4)+sin(x)sin(pi/4)
     *                      =  1/sqrt(2) * (sin(x) + cos(x))
     *              sin(x0) = sin(x)cos(3pi/4)-cos(x)sin(3pi/4)
     *                      =  1/sqrt(2) * (sin(x) - cos(x))
     * To avoid cancellation, use
     *              sin(x) +- cos(x) = -cos(2x)/(sin(x) -+ cos(x))
     * to compute the worse one.
     */
    __ieee754_sincos(x, &s, &c);
    ss = s - c;
    cc = s + c;
    /*
     * j0(x) = 1/sqrt(pi) * (P(0,x)*cc - Q(0,x)*ss) / sqrt(x)
     * y0(x) = 1/sqrt(pi) * (P(0,x)*ss + Q(0,x)*cc) / sqrt(x)
     */
    if (ix < IC(0x7fe00000)) { /* make sure x+x not overflow */
      z = -__ieee754_cos(x + x);
      if ((s * c) < zero)
        cc = z / ss;
      else
        ss = z / cc;
    }
    if (ix > IC(0x48000000))
      z = (invsqrtpi * ss) / __ieee754_sqrt(x);
    else {
      u = __j0_y0_pzero(x);
      v = __j0_y0_qzero(x);
      z = invsqrtpi * (u * ss + v * cc) / __ieee754_sqrt(x);
    }
    return z;
  }
  if (ix <= IC(0x3e400000)) { /* x < 2**-27 */
    return (u00 + tpi * __ieee754_log(x));
  }
  z = x * x;
  double temp_var_for_tac_3;
  computeDSub((Addr)&temp_var_for_tac_3,
              {(Addr) &(temp_var_for_const_7 = 0.0),
               (Addr) &(temp_var_for_const_6 = 3.98205194132103398453e-11)},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:124:9");
  computeDMul((Addr)&z, {(Addr)&x, (Addr)&x},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:124:5");
#ifdef DO_NOT_USE_THIS
  u = u00 + z * (u01 + z * (u02 + z * (u03 + z * (u04 + z * (u05 + z * u06)))));
  v = one + z * (v01 + z * (v02 + z * (v03 + z * v04)));
#else
  u1 = u00 + z * u01;
  double temp_var_for_const_8, temp_var_for_const_9;
  double temp_var_for_tac_4;
  computeDMul((Addr)&temp_var_for_tac_4,
              {(Addr)&z, (Addr) &(temp_var_for_const_8 = u01)},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:129:12");
  computeDAdd((Addr)&u1,
              {(Addr) &(temp_var_for_const_9 = u00), (Addr)&temp_var_for_tac_4},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:129:6");
  z2 = z * z;
  computeDMul((Addr)&z2, {(Addr)&z, (Addr)&z},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:130:6");
  u2 = u02 + z * u03;
  double temp_var_for_const_10, temp_var_for_const_11;
  double temp_var_for_tac_5;
  computeDMul((Addr)&temp_var_for_tac_5,
              {(Addr)&z, (Addr) &(temp_var_for_const_10 = u03)},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:131:12");
  computeDAdd((Addr)&u2, {(Addr) &(temp_var_for_const_11 = u02),
                          (Addr)&temp_var_for_tac_5},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:131:6");
  z4 = z2 * z2;
  computeDMul((Addr)&z4, {(Addr)&z2, (Addr)&z2},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:132:6");
  u3 = u04 + z * u05;
  double temp_var_for_const_12, temp_var_for_const_13;
  double temp_var_for_tac_6;
  computeDMul((Addr)&temp_var_for_tac_6,
              {(Addr)&z, (Addr) &(temp_var_for_const_12 = u05)},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:133:12");
  computeDAdd((Addr)&u3, {(Addr) &(temp_var_for_const_13 = u04),
                          (Addr)&temp_var_for_tac_6},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:133:6");
  z6 = z4 * z2;
  computeDMul((Addr)&z6, {(Addr)&z4, (Addr)&z2},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:134:6");
  u = u1 + z2 * u2 + z4 * u3 + z6 * u06;
  double temp_var_for_const_14;
  double temp_var_for_tac_7, temp_var_for_tac_8, temp_var_for_tac_9,
      temp_var_for_tac_10, temp_var_for_tac_11;
  computeDMul((Addr)&temp_var_for_tac_7, {(Addr)&z2, (Addr)&u2},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:135:10");
  computeDAdd((Addr)&temp_var_for_tac_8, {(Addr)&u1, (Addr)&temp_var_for_tac_7},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:135:25");
  computeDMul((Addr)&temp_var_for_tac_9, {(Addr)&z4, (Addr)&u3},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:135:20");
  computeDAdd((Addr)&temp_var_for_tac_10,
              {(Addr)&temp_var_for_tac_8, (Addr)&temp_var_for_tac_9},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:135:35");
  computeDMul((Addr)&temp_var_for_tac_11,
              {(Addr)&z6, (Addr) &(temp_var_for_const_14 = u06)},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:135:30");
  computeDAdd((Addr)&u,
              {(Addr)&temp_var_for_tac_10, (Addr)&temp_var_for_tac_11},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:135:5");
  v1 = one + z * v01;
  double temp_var_for_const_15, temp_var_for_const_16;
  double temp_var_for_tac_12;
  computeDMul((Addr)&temp_var_for_tac_12,
              {(Addr)&z, (Addr) &(temp_var_for_const_15 = v01)},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:136:12");
  computeDAdd((Addr)&v1, {(Addr) &(temp_var_for_const_16 = one),
                          (Addr)&temp_var_for_tac_12},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:136:6");
  v2 = v02 + z * v03;
  double temp_var_for_const_17, temp_var_for_const_18;
  double temp_var_for_tac_13;
  computeDMul((Addr)&temp_var_for_tac_13,
              {(Addr)&z, (Addr) &(temp_var_for_const_17 = v03)},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:137:12");
  computeDAdd((Addr)&v2, {(Addr) &(temp_var_for_const_18 = v02),
                          (Addr)&temp_var_for_tac_13},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:137:6");
  v = v1 + z2 * v2 + z4 * v04;
  double temp_var_for_const_19;
  double temp_var_for_tac_14, temp_var_for_tac_15, temp_var_for_tac_16;
  computeDMul((Addr)&temp_var_for_tac_14, {(Addr)&z2, (Addr)&v2},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:138:10");
  computeDAdd((Addr)&temp_var_for_tac_15,
              {(Addr)&v1, (Addr)&temp_var_for_tac_14},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:138:25");
  computeDMul((Addr)&temp_var_for_tac_16,
              {(Addr)&z4, (Addr) &(temp_var_for_const_19 = v04)},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:138:20");
  computeDAdd((Addr)&v,
              {(Addr)&temp_var_for_tac_15, (Addr)&temp_var_for_tac_16},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:138:5");
#endif
  double temp_var_for_ext_0;
  temp_var_for_ext_0 = (u / v + tpi * (__ieee754_j0(x) * __ieee754_log(x)));
  double temp_var_for_const_20;
  double temp_var_for_tac_17, temp_var_for_tac_18;
  computeDDiv((Addr)&temp_var_for_tac_17, {(Addr)&u, (Addr)&v},
              "toString(biExpr->getExprLoc())");
computeDMul((Addr)&temp_var_for_tac_18,{(Addr)&(temp_var_for_const_20=tpi),(Addr)&__ieee754_j0(getFVbyShadow<int>((Addr)&x) * __ieee754_log(getFVbyShadow<int>((Addr)&x)},"/home/shijia/Public/testprogram/e_y0.c_e.c:141:31");
computeDAdd((Addr)&temp_var_for_ext_0,
            {(Addr)&temp_var_for_tac_17, (Addr)&temp_var_for_tac_18},
            "/home/shijia/Public/testprogram/e_y0.c_e.c:141:22");
callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
callExp++; /*identify the function is  add move tmpShadow*/
return temp_var_for_ext_0;
}

/* wrapper y0 */
double __y0(double x) {
  if ((islessequal(x, 0.0) || isgreater(x, X_TLOSS)) &&
      _LIB_VERSION != _IEEE_) {
    if (x < 0.0) {
      /* d = zero/(x-x) */
      feraiseexcept(FE_INVALID);
      return __kernel_standard(x, x, -HUGE_VAL, KMATHERR_Y0_MINUS);
    } else if (x == 0.0)
      /* d = -one/(x-x) */
      return __kernel_standard(x, x, -HUGE_VAL, KMATHERR_Y0_ZERO);
    else if (_LIB_VERSION != _POSIX_)
      /* y0(x>X_TLOSS) */
      return __kernel_standard(x, x, 0.0, KMATHERR_Y0_TLOSS);
  }

  double temp_var_for_ext_1;
  temp_var_for_ext_1 = __ieee754_y0(x);
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

__typeof(__y0) y0 __attribute__((weak, alias("__y0")));
#ifdef __NO_LONG_DOUBLE_MATH
__typeof(__y0l) __y0l __attribute__((alias("__y0")));
__typeof(__y0l) y0l __attribute__((weak, alias("__y0l")));
#endif
