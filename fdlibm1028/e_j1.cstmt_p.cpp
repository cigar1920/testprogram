#include "../ScDebug/scdebug.h"
/* @(#)e_j1.c 1.3 95/01/18 */
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
/* Modified by Naohiko Shimizu/Tokai University, Japan 1997/08/26,
   for performance improvement on pipelined processors.
*/

/* __ieee754_j1(x)
 * Bessel function of the first kind of order one.
 * Method -- j1(x):
 *	1. For tiny x, we use j1(x) = x/2 - x^3/16 + x^5/384 - ...
 *	2. Reduce x to |x| since j1(x)=-j1(-x),  and
 *	   for x in (0,2)
 *		j1(x) = x/2 + x*z*R0/S0,  where z = x*x;
 *	   (precision:  |j1/x - 1/2 - R0/S0 |<2**-61.51 )
 *	   for x in (2,inf)
 *		j1(x) = sqrt(2/(pi*x))*(p1(x)*cos(x1)-q1(x)*sin(x1))
 *		y1(x) = sqrt(2/(pi*x))*(p1(x)*sin(x1)+q1(x)*cos(x1))
 *	   where x1 = x-3*pi/4. It is better to compute sin(x1),cos(x1)
 *	   as follow:
 *		cos(x1) =  cos(x)cos(3pi/4)+sin(x)sin(3pi/4)
 *			=  1/sqrt(2) * (sin(x) - cos(x))
 *		sin(x1) =  sin(x)cos(3pi/4)-cos(x)sin(3pi/4)
 *			= -1/sqrt(2) * (sin(x) + cos(x))
 *	   (To avoid cancellation, use
 *		sin(x) +- cos(x) = -cos(2x)/(sin(x) -+ cos(x))
 *	    to compute the worse one.)
 *
 *	3 Special cases
 *		j1(nan)= nan
 *		j1(0) = 0
 *		j1(inf) = 0
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

double __ieee754_j1(double x) {
  double z, s, c, ss, cc, r, u, v, y, r1, r2, s1, s2, s3, z2, z4;
  int32_t hx, ix;

  static const double hugeval = 1e300;
  static const double one = 1.0;
  static const double invsqrtpi =
      5.64189583547756279280e-01; /* 0x3FE20DD7, 0x50429B6D */
  static const double zero = 0.0;

  /* R0/S0 on [0,2] */
  static const double r00 = (0.0 - 6.25000000000000000000e-02);
  double temp_var_for_const_0, temp_var_for_const_1;
  ; /* 0xBFB00000, 0x00000000 */
  static const double r01 =
      1.40705666955189706048e-03; /* 0x3F570D9F, 0x98472C61 */
  static const double r02 = (0.0 - 1.59955631084035597520e-05);
  double temp_var_for_const_2, temp_var_for_const_3;
  double temp_var_for_tac_0;
  computeDSub((Addr)&temp_var_for_tac_0,
              {(Addr) &(temp_var_for_const_1 = 0.0),
               (Addr) &(temp_var_for_const_0 = 6.25000000000000000000e-02)},
              "/home/shijia/Public/testprogram/e_j1.c_e.c:63:12");
  ; /* 0xBEF0C5C6, 0xBA169668 */
  static const double r03 =
      4.96727999609584448412e-08; /* 0x3E6AAAFA, 0x46CA0BD9 */
  static const double s01 =
      1.91537599538363460805e-02; /* 0x3F939D0B, 0x12637E53 */
  static const double s02 =
      1.85946785588630915560e-04; /* 0x3F285F56, 0xB9CDF664 */
  static const double s03 =
      1.17718464042623683263e-06; /* 0x3EB3BFF8, 0x333F8498 */
  static const double s04 =
      5.04636257076217042715e-09; /* 0x3E35AC88, 0xC97DFF2C */
  static const double s05 =
      1.23542274426137913908e-11; /* 0x3DAB2ACF, 0xCFB97ED8 */

  GET_HIGH_WORD(hx, x);
  ix = hx & IC(0x7fffffff);
  if (ix >= IC(0x7ff00000))
    return one / x;
  y = __ieee754_fabs(x);
  double temp_var_for_const_4;
  double temp_var_for_tac_1;
  computeDSub((Addr)&temp_var_for_tac_1,
              {(Addr) &(temp_var_for_const_3 = 0.0),
               (Addr) &(temp_var_for_const_2 = 1.59955631084035597520e-05)},
              "toString(biExpr->getExprLoc())");
AssignD({(Addr)&y},(Addr)&(temp_var_for_const_4=__ieee754_fabs(getFVbyShadow<int>((Addr)&x)),"/home/shijia/Public/testprogram/e_j1.c_e.c:81:5");
  if (ix >= IC(0x40000000)) { /* |x| >= 2.0 */
    __ieee754_sincos(y, &s, &c);
    ss = -s - c;
    cc = s - c;
    if (ix < IC(0x7fe00000)) { /* make sure y+y not overflow */
      z = __ieee754_cos(y + y);
      if ((s * c) > zero)
        cc = z / ss;
      else
        ss = z / cc;
    }
    /*
     * j1(x) = 1/sqrt(pi) * (P(1,x)*cc - Q(1,x)*ss) / sqrt(x)
     * y1(x) = 1/sqrt(pi) * (P(1,x)*ss + Q(1,x)*cc) / sqrt(x)
     */
    if (ix > IC(0x48000000))
      z = (invsqrtpi * cc) / __ieee754_sqrt(y);
    else {
      u = __j1_y1_pone(y);
      v = __j1_y1_qone(y);
      z = invsqrtpi * (u * cc - v * ss) / __ieee754_sqrt(y);
    }
    if (hx < 0)
      return -z;
    else
      return z;
  }
  if (ix < IC(0x3e400000)) { /* |x|<2**-27 */
    if (hugeval + x > one)
      return 0.5 * x; /* inexact if x!=0 necessary */
  }
  z = x * x;computeDMul((Addr)&z,{(Addr)&x,(Addr)&x},"/home/shijia/Public/testprogram/e_j1.c_e.c:113:5");
#ifdef DO_NOT_USE_THIS
  r = z * (r00 + z * (r01 + z * (r02 + z * r03)));
  s = one + z * (s01 + z * (s02 + z * (s03 + z * (s04 + z * s05))));
  r *= x;
#else
  r1 = z * r00;double temp_var_for_const_5;computeDMul((Addr)&r1,{(Addr)&z,(Addr)&(temp_var_for_const_5=r00)},"/home/shijia/Public/testprogram/e_j1.c_e.c:119:6");
  z2 = z * z;computeDMul((Addr)&z2,{(Addr)&z,(Addr)&z},"/home/shijia/Public/testprogram/e_j1.c_e.c:120:6");
  r2 = r01 + z * r02;double temp_var_for_const_6,temp_var_for_const_7;double temp_var_for_tac_2;computeDMul((Addr)&temp_var_for_tac_2,{(Addr)&z,(Addr)&(temp_var_for_const_6=r02)},"/home/shijia/Public/testprogram/e_j1.c_e.c:121:12");computeDAdd((Addr)&r2,{(Addr)&(temp_var_for_const_7=r01),(Addr)&temp_var_for_tac_2},"/home/shijia/Public/testprogram/e_j1.c_e.c:121:6");
  z4 = z2 * z2;computeDMul((Addr)&z4,{(Addr)&z2,(Addr)&z2},"/home/shijia/Public/testprogram/e_j1.c_e.c:122:6");
  r = r1 + z2 * r2 + z4 * r03;double temp_var_for_const_8;double temp_var_for_tac_3,temp_var_for_tac_4,temp_var_for_tac_5;computeDMul((Addr)&temp_var_for_tac_3,{(Addr)&z2,(Addr)&r2},"/home/shijia/Public/testprogram/e_j1.c_e.c:123:10");computeDAdd((Addr)&temp_var_for_tac_4,{(Addr)&r1,(Addr)&temp_var_for_tac_3},"/home/shijia/Public/testprogram/e_j1.c_e.c:123:25");computeDMul((Addr)&temp_var_for_tac_5,{(Addr)&z4,(Addr)&(temp_var_for_const_8=r03)},"/home/shijia/Public/testprogram/e_j1.c_e.c:123:20");computeDAdd((Addr)&r,{(Addr)&temp_var_for_tac_4,(Addr)&temp_var_for_tac_5},"/home/shijia/Public/testprogram/e_j1.c_e.c:123:5");
  r *= x;
  s1 = one + z * s01;double temp_var_for_const_9,temp_var_for_const_10;double temp_var_for_tac_6;computeDMul((Addr)&temp_var_for_tac_6,{(Addr)&z,(Addr)&(temp_var_for_const_9=s01)},"/home/shijia/Public/testprogram/e_j1.c_e.c:125:12");computeDAdd((Addr)&s1,{(Addr)&(temp_var_for_const_10=one),(Addr)&temp_var_for_tac_6},"/home/shijia/Public/testprogram/e_j1.c_e.c:125:6");
  s2 = s02 + z * s03;double temp_var_for_const_11,temp_var_for_const_12;double temp_var_for_tac_7;computeDMul((Addr)&temp_var_for_tac_7,{(Addr)&z,(Addr)&(temp_var_for_const_11=s03)},"/home/shijia/Public/testprogram/e_j1.c_e.c:126:12");computeDAdd((Addr)&s2,{(Addr)&(temp_var_for_const_12=s02),(Addr)&temp_var_for_tac_7},"/home/shijia/Public/testprogram/e_j1.c_e.c:126:6");
  s3 = s04 + z * s05;double temp_var_for_const_13,temp_var_for_const_14;double temp_var_for_tac_8;computeDMul((Addr)&temp_var_for_tac_8,{(Addr)&z,(Addr)&(temp_var_for_const_13=s05)},"/home/shijia/Public/testprogram/e_j1.c_e.c:127:12");computeDAdd((Addr)&s3,{(Addr)&(temp_var_for_const_14=s04),(Addr)&temp_var_for_tac_8},"/home/shijia/Public/testprogram/e_j1.c_e.c:127:6");
  s = s1 + z2 * s2 + z4 * s3;double temp_var_for_tac_9,temp_var_for_tac_10,temp_var_for_tac_11;computeDMul((Addr)&temp_var_for_tac_9,{(Addr)&z2,(Addr)&s2},"/home/shijia/Public/testprogram/e_j1.c_e.c:128:10");computeDAdd((Addr)&temp_var_for_tac_10,{(Addr)&s1,(Addr)&temp_var_for_tac_9},"/home/shijia/Public/testprogram/e_j1.c_e.c:128:25");computeDMul((Addr)&temp_var_for_tac_11,{(Addr)&z4,(Addr)&s3},"/home/shijia/Public/testprogram/e_j1.c_e.c:128:20");computeDAdd((Addr)&s,{(Addr)&temp_var_for_tac_10,(Addr)&temp_var_for_tac_11},"/home/shijia/Public/testprogram/e_j1.c_e.c:128:5");
#endif
  double temp_var_for_ext_0;
  temp_var_for_ext_0 = (x * 0.5 + r / s);double temp_var_for_const_15;double temp_var_for_tac_12,temp_var_for_tac_13;computeDMul((Addr)&temp_var_for_tac_12,{(Addr)&x,(Addr)&(temp_var_for_const_15=0.5)},"/home/shijia/Public/testprogram/e_j1.c_e.c:131:37");computeDDiv((Addr)&temp_var_for_tac_13,{(Addr)&r,(Addr)&s},"/home/shijia/Public/testprogram/e_j1.c_e.c:131:33");computeDAdd((Addr)&temp_var_for_ext_0,{(Addr)&temp_var_for_tac_12,(Addr)&temp_var_for_tac_13},"/home/shijia/Public/testprogram/e_j1.c_e.c:131:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

/* wrapper j1 */
double __j1(double x) {
  if (isgreater(__ieee754_fabs(x), X_TLOSS) && _LIB_VERSION != _IEEE_ &&
      _LIB_VERSION != _POSIX_)
    /* j1(|x|>X_TLOSS) */
    return __kernel_standard(x, x, 0.0, KMATHERR_J1_TLOSS);

  double temp_var_for_ext_1;
  temp_var_for_ext_1 = __ieee754_j1(x);
  double temp_var_for_callexp_0 = __ieee754_j1(getFVbyShadow<double>((Addr)&x));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_callexp_0,
          "/home/shijia/Public/testprogram/e_j1.c_e.c:145:22");
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

__typeof(__j1) j1 __attribute__((weak, alias("__j1")));
#ifdef __NO_LONG_DOUBLE_MATH
__typeof(__j1l) __j1l __attribute__((alias("__j1")));
__typeof(__j1l) j1l __attribute__((weak, alias("__j1l")));
#endif
