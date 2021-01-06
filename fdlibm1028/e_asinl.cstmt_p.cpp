#include "../ScDebug/scdebug.h"
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

/*
  Long double expansions are
  Copyright (C) 2001 Stephen L. Moshier <moshier@na-net.ornl.gov>
  and are incorporated herein by permission of the author.  The author
  reserves the right to distribute this material elsewhere under different
  copying permissions.  These modifications are distributed here under
  the following terms:

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, see
    <http://www.gnu.org/licenses/>.  */

/* __ieee754_asin(x)
 * Method :
 *	Since  asin(x) = x + x^3/6 + x^5*3/40 + x^7*15/336 + ...
 *	we approximate asin(x) on [0,0.5] by
 *		asin(x) = x + x*x^2*R(x^2)
 *
 *	For x in [0.5,1]
 *		asin(x) = pi/2-2*asin(sqrt((1-x)/2))
 *	Let y = (1-x), z = y/2, s := sqrt(z), and pio2_hi+pio2_lo=pi/2;
 *	then for x>0.98
 *		asin(x) = pi/2 - 2*(s+s*z*R(z))
 *			= pio2_hi - (2*(s+s*z*R(z)) - pio2_lo)
 *	For x<=0.98, let pio4_hi = pio2_hi/2, then
 *		f = hi part of s;
 *		c = sqrt(z) - f = (z-f*f)/(s+f)		...f+c=sqrt(z)
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

#ifndef __NO_LONG_DOUBLE_MATH

#ifndef __have_fpu_asin

long double __ieee754_asinl(long double x) {
  long double t, w, p, q, c, r, s;
  int32_t ix;
  uint32_t se, i0, i1, k;

  static const long double one = 1.0L;
  static const long double hugeval = 1.0e+4932L;
  static const long double pio2_hi =
      0x1.921fb54442d1846ap+0L; /* pi/2 rounded to nearest to 64 bits.  */
  static const long double pio2_lo = (0.0 - 0x7.6733ae8fe47c65d8p-68L);
  long double temp_var_for_const_0, temp_var_for_const_1;
  ; /* pi/2 - pio2_hi rounded to nearest to 64
bits.  */
  static const long double pio4_hi =
      0xc.90fdaa22168c235p-4L; /* pi/4 rounded to nearest to 64 bits.  */
                               /* coefficient for R(x^2) */
                               /* asin(x) = x + x^3 pS(x^2) / qS(x^2)
                                  0 <= x <= 0.5
                                  peak relative error 1.9e-21  */
  static const long double pS0 =
      (0.0 - 1.008714657938491626019651170502036851607E1L);
  long double temp_var_for_const_2, temp_var_for_const_3;
  long double temp_var_for_tac_0;
  computeLdSub((Addr)&temp_var_for_tac_0,
               {(Addr) &(temp_var_for_const_1 = 0.0),
                (Addr) &(temp_var_for_const_0 = 0x7.6733ae8fe47c65d8p-68L)},
               "/home/shijia/Public/testprogram/e_asinl.c_e.c:88:12");
  ;
  static const long double pS1 = 2.331460313214179572063441834101394865259E1L;
  static const long double pS2 =
      (0.0 - 1.863169762159016144159202387315381830227E1L);
  long double temp_var_for_const_4, temp_var_for_const_5;
  long double temp_var_for_tac_1;
  computeLdSub((Addr)&temp_var_for_tac_1,
               {(Addr) &(temp_var_for_const_3 = 0.0),
                (Addr) &(temp_var_for_const_2 =
                             1.008714657938491626019651170502036851607E1L)},
               "/home/shijia/Public/testprogram/e_asinl.c_e.c:91:12");
  ;
  static const long double pS3 = 5.930399351579141771077475766877674661747E0L;
  static const long double pS4 =
      (0.0 - 6.121291917696920296944056882932695185001E-1L);
  long double temp_var_for_const_6, temp_var_for_const_7;
  long double temp_var_for_tac_2;
  computeLdSub((Addr)&temp_var_for_tac_2,
               {(Addr) &(temp_var_for_const_5 = 0.0),
                (Addr) &(temp_var_for_const_4 =
                             1.863169762159016144159202387315381830227E1L)},
               "/home/shijia/Public/testprogram/e_asinl.c_e.c:94:12");
  ;
  static const long double pS5 = 3.776934006243367487161248678019350338383E-3L;
  static const long double qS0 =
      (0.0 - 6.052287947630949712886794360635592886517E1L);
  long double temp_var_for_const_8, temp_var_for_const_9;
  long double temp_var_for_tac_3;
  computeLdSub((Addr)&temp_var_for_tac_3,
               {(Addr) &(temp_var_for_const_7 = 0.0),
                (Addr) &(temp_var_for_const_6 =
                             6.121291917696920296944056882932695185001E-1L)},
               "/home/shijia/Public/testprogram/e_asinl.c_e.c:97:12");
  ;
  static const long double qS1 = 1.671229145571899593737596543114258558503E2L;
  static const long double qS2 =
      (0.0 - 1.707840117062586426144397688315411324388E2L);
  long double temp_var_for_const_10, temp_var_for_const_11;
  long double temp_var_for_tac_4;
  computeLdSub((Addr)&temp_var_for_tac_4,
               {(Addr) &(temp_var_for_const_9 = 0.0),
                (Addr) &(temp_var_for_const_8 =
                             6.052287947630949712886794360635592886517E1L)},
               "/home/shijia/Public/testprogram/e_asinl.c_e.c:100:12");
  ;
  static const long double qS3 = 7.870295154902110425886636075950077640623E1L;
  static const long double qS4 =
      (0.0 - 1.568433562487314651121702982333303458814E1L);
  long double temp_var_for_const_12, temp_var_for_const_13;
  long double temp_var_for_tac_5;
  computeLdSub((Addr)&temp_var_for_tac_5,
               {(Addr) &(temp_var_for_const_11 = 0.0),
                (Addr) &(temp_var_for_const_10 =
                             1.707840117062586426144397688315411324388E2L)},
               "/home/shijia/Public/testprogram/e_asinl.c_e.c:103:12");
  ;
  /* 1.000000000000000000000000000000000000000E0 */

  GET_LDOUBLE_WORDS(se, i0, i1, x);
  ix = se & 0x7fff;
  ix = (ix << 16) | (i0 >> 16);
  if (ix >= IC(0x3fff8000)) { /* |x|>= 1 */
    if (ix == IC(0x3fff8000) && ((i0 - UC(0x80000000)) | i1) == 0)
      /* asin(1)=+-pi/2 with inexact */
      return x * pio2_hi + x * pio2_lo;
    return (x - x) / (x - x);       /* asin(|x|>1) is NaN */
  } else if (ix < IC(0x3ffe8000)) { /* |x|<0.5 */
    if (ix < IC(0x3fde8000)) {      /* if |x| < 2**-33 */
      if (hugeval + x > one)
        return x; /* return x with inexact if x!=0 */
    } else {
      t = x * x;
      p = t * (pS0 + t * (pS1 + t * (pS2 + t * (pS3 + t * (pS4 + t * pS5)))));
      q = qS0 + t * (qS1 + t * (qS2 + t * (qS3 + t * (qS4 + t))));
      w = p / q;
      return x + x * w;
    }
  }
  /* 1> |x|>= 0.5 */
  w = one - __ieee754_fabsl(x);
  long double temp_var_for_const_14, temp_var_for_const_15;
  long double temp_var_for_tac_6;
  computeLdSub((Addr)&temp_var_for_tac_6,
               {(Addr) &(temp_var_for_const_13 = 0.0),
                (Addr) &(temp_var_for_const_12 =
                             1.568433562487314651121702982333303458814E1L)},
               "toString(biExpr->getExprLoc())");
computeLdSub((Addr)&w,{(Addr)&(temp_var_for_const_15=one),(Addr)&(temp_var_for_const_14=__ieee754_fabsl(getFVbyShadow<int>((Addr)&x))},"/home/shijia/Public/testprogram/e_asinl.c_e.c:127:5");
t = w * 0.5;
long double temp_var_for_const_16;
computeLdMul((Addr)&t, {(Addr)&w, (Addr) &(temp_var_for_const_16 = 0.5)},
             "/home/shijia/Public/testprogram/e_asinl.c_e.c:128:5");
p = t * (pS0 + t * (pS1 + t * (pS2 + t * (pS3 + t * (pS4 + t * pS5)))));
long double temp_var_for_const_17, temp_var_for_const_18, temp_var_for_const_19,
    temp_var_for_const_20, temp_var_for_const_21, temp_var_for_const_22;
long double temp_var_for_tac_7, temp_var_for_tac_8, temp_var_for_tac_9,
    temp_var_for_tac_10, temp_var_for_tac_11, temp_var_for_tac_12,
    temp_var_for_tac_13, temp_var_for_tac_14, temp_var_for_tac_15,
    temp_var_for_tac_16;
computeLdMul((Addr)&temp_var_for_tac_7,
             {(Addr)&t, (Addr) &(temp_var_for_const_17 = pS5)},
             "/home/shijia/Public/testprogram/e_asinl.c_e.c:129:60");
computeLdAdd((Addr)&temp_var_for_tac_8,
             {(Addr) &(temp_var_for_const_18 = pS4), (Addr)&temp_var_for_tac_7},
             "/home/shijia/Public/testprogram/e_asinl.c_e.c:129:53");
computeLdMul((Addr)&temp_var_for_tac_9, {(Addr)&t, (Addr)&temp_var_for_tac_8},
             "/home/shijia/Public/testprogram/e_asinl.c_e.c:129:49");
computeLdAdd((Addr)&temp_var_for_tac_10,
             {(Addr) &(temp_var_for_const_19 = pS3), (Addr)&temp_var_for_tac_9},
             "/home/shijia/Public/testprogram/e_asinl.c_e.c:129:42");
computeLdMul((Addr)&temp_var_for_tac_11, {(Addr)&t, (Addr)&temp_var_for_tac_10},
             "/home/shijia/Public/testprogram/e_asinl.c_e.c:129:38");
computeLdAdd((Addr)&temp_var_for_tac_12, {(Addr) &(temp_var_for_const_20 = pS2),
                                          (Addr)&temp_var_for_tac_11},
             "/home/shijia/Public/testprogram/e_asinl.c_e.c:129:31");
computeLdMul((Addr)&temp_var_for_tac_13, {(Addr)&t, (Addr)&temp_var_for_tac_12},
             "/home/shijia/Public/testprogram/e_asinl.c_e.c:129:27");
computeLdAdd((Addr)&temp_var_for_tac_14, {(Addr) &(temp_var_for_const_21 = pS1),
                                          (Addr)&temp_var_for_tac_13},
             "/home/shijia/Public/testprogram/e_asinl.c_e.c:129:20");
computeLdMul((Addr)&temp_var_for_tac_15, {(Addr)&t, (Addr)&temp_var_for_tac_14},
             "/home/shijia/Public/testprogram/e_asinl.c_e.c:129:16");
computeLdAdd((Addr)&temp_var_for_tac_16, {(Addr) &(temp_var_for_const_22 = pS0),
                                          (Addr)&temp_var_for_tac_15},
             "/home/shijia/Public/testprogram/e_asinl.c_e.c:129:9");
computeLdMul((Addr)&p, {(Addr)&t, (Addr)&temp_var_for_tac_16},
             "/home/shijia/Public/testprogram/e_asinl.c_e.c:129:5");
q = qS0 + t * (qS1 + t * (qS2 + t * (qS3 + t * (qS4 + t))));
long double temp_var_for_const_23, temp_var_for_const_24, temp_var_for_const_25,
    temp_var_for_const_26, temp_var_for_const_27;
long double temp_var_for_tac_17, temp_var_for_tac_18, temp_var_for_tac_19,
    temp_var_for_tac_20, temp_var_for_tac_21, temp_var_for_tac_22,
    temp_var_for_tac_23, temp_var_for_tac_24;
computeLdAdd((Addr)&temp_var_for_tac_17,
             {(Addr) &(temp_var_for_const_23 = qS4), (Addr)&t},
             "/home/shijia/Public/testprogram/e_asinl.c_e.c:130:48");
computeLdMul((Addr)&temp_var_for_tac_18, {(Addr)&t, (Addr)&temp_var_for_tac_17},
             "/home/shijia/Public/testprogram/e_asinl.c_e.c:130:44");
computeLdAdd((Addr)&temp_var_for_tac_19, {(Addr) &(temp_var_for_const_24 = qS3),
                                          (Addr)&temp_var_for_tac_18},
             "/home/shijia/Public/testprogram/e_asinl.c_e.c:130:37");
computeLdMul((Addr)&temp_var_for_tac_20, {(Addr)&t, (Addr)&temp_var_for_tac_19},
             "/home/shijia/Public/testprogram/e_asinl.c_e.c:130:33");
computeLdAdd((Addr)&temp_var_for_tac_21, {(Addr) &(temp_var_for_const_25 = qS2),
                                          (Addr)&temp_var_for_tac_20},
             "/home/shijia/Public/testprogram/e_asinl.c_e.c:130:26");
computeLdMul((Addr)&temp_var_for_tac_22, {(Addr)&t, (Addr)&temp_var_for_tac_21},
             "/home/shijia/Public/testprogram/e_asinl.c_e.c:130:22");
computeLdAdd((Addr)&temp_var_for_tac_23, {(Addr) &(temp_var_for_const_26 = qS1),
                                          (Addr)&temp_var_for_tac_22},
             "/home/shijia/Public/testprogram/e_asinl.c_e.c:130:15");
computeLdMul((Addr)&temp_var_for_tac_24, {(Addr)&t, (Addr)&temp_var_for_tac_23},
             "/home/shijia/Public/testprogram/e_asinl.c_e.c:130:11");
computeLdAdd((Addr)&q, {(Addr) &(temp_var_for_const_27 = qS0),
                        (Addr)&temp_var_for_tac_24},
             "/home/shijia/Public/testprogram/e_asinl.c_e.c:130:5");
s = __ieee754_sqrtl(t);
long double temp_var_for_const_28;AssignLd({(Addr)&s},(Addr)&(temp_var_for_const_28=__ieee754_sqrtl(getFVbyShadow<int>((Addr)&t)),"/home/shijia/Public/testprogram/e_asinl.c_e.c:131:5");
  if (ix >= IC(0x3ffef999)) { /* if |x| > 0.975 */
    w = p / q;
    t = pio2_hi - (2.0 * (s + s * w) - pio2_lo);
  } else {
    GET_LDOUBLE_WORDS(k, i0, i1, s);
    i1 = 0;
    SET_LDOUBLE_WORDS(w, k, i0, i1);
    c = (t - w * w) / (s + w);
    r = p / q;
    p = 2.0 * s * r - (pio2_lo - 2.0 * c);
    q = pio4_hi - 2.0 * w;
    t = pio4_hi - (p - q);
  }
  if ((se & 0x8000) == 0)
    return t;
  long double temp_var_for_ext_0;
  temp_var_for_ext_0 = -t;AssignLd({(Addr)&temp_var_for_ext_0},(Addr)&(-(t)),"/home/shijia/Public/testprogram/e_asinl.c_e.c:148:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return (0.0 - 0);double temp_var_for_const_29,temp_var_for_const_30;;
double temp_var_for_tac_25 ;computeDSub((Addr)&temp_var_for_tac_25,{(Addr)&(temp_var_for_const_30=0.0),(Addr)&(temp_var_for_const_29=0)},"toString(biExpr->getExprLoc())");
}

#endif

/* wrapper asin */
long double __asinl(long double x) {
  if (isgreater(__ieee754_fabsl(x), 1.0) && _LIB_VERSION != _IEEE_) {
    /* asin(|x|>1) */
    feraiseexcept(FE_INVALID);
    return __kernel_standard_l(x, x, __builtin_nanl(""), KMATHERRL_ASIN);
  }

  long double temp_var_for_ext_1;
  temp_var_for_ext_1 = __ieee754_asinl(x);
  long double temp_var_for_callexp_0 =
      __ieee754_asinl(getFVbyShadow<long double>((Addr)&x));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  AssignLd({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_callexp_0,
           "/home/shijia/Public/testprogram/e_asinl.c_e.c:165:22");
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

__typeof(__asinl) asinl __attribute__((weak, alias("__asinl")));

#endif
