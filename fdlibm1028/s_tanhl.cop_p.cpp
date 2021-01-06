#include "../ScDebug/scdebug.h"
/* s_tanhl.c -- long double version of s_tanh.c.
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

/* tanhl(x)
 * Return the Hyperbolic Tangent of x
 *
 * Method :
 *				        x    -x
 *				       e  - e
 *	0. tanhl(x) is defined to be -----------
 *				        x    -x
 *				       e  + e
 *	1. reduce x to non-negative by tanhl(-x) = -tanhl(x).
 *	2.  0      <= x <= 2**-55 : tanhl(x) := x*(one+x)
 *					         -t
 *	    2**-55 <  x <=  1     : tanhl(x) := -----; t = expm1l(-2x)
 *					        t + 2
 *						      2
 *	    1      <= x <=  23.0  : tanhl(x) := 1-  ----- ; t=expm1l(2x)
 *						    t + 2
 *	    23.0   <  x <= INF    : tanhl(x) := 1.
 *
 * Special cases:
 *	tanhl(NaN) is NaN;
 *	only tanhl(0)=0 is exact for finite argument.
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

#ifndef __have_fpu_tanh

long double __ieee754_tanhl(long double x) {
  long double t, z;
  int32_t se;
  uint32_t j0, j1, ix;

  static const long double one = 1.0;
  static const long double two = 2.0;
  static const long double tiny = 1.0e-4900L;

  /* High word of |x|. */
  long double temp_var_for_const_0;
  ew_u.value = x;
  AssignLd({(Addr) &(temp_var_for_const_0 = ew_u.value)}, (Addr)&x,
           "/home/shijia/Public/testprogram/s_tanhl.c_e.c:59:3 "
           "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
  ;
  ix = se & 0x7fff;

  /* x is INF or NaN */
  if (ix == 0x7fff) {
    /* for NaN it's not important which branch: tanhl(NaN) = NaN */
    if (se & 0x8000) {
      long double temp_var_for_ext_0;
      long double temp_var_for_tac_0, temp_var_for_tac_1;
      long double temp_var_for_const_1, temp_var_for_const_2;
      temp_var_for_tac_0 = one / x;

      temp_var_for_tac_1 = temp_var_for_tac_0 - one;

      temp_var_for_ext_0 = temp_var_for_tac_1;
      computeLdDiv((Addr)&temp_var_for_tac_0,
                   {(Addr) &(temp_var_for_const_1 = one), (Addr)&x},
                   "/home/shijia/Public/testprogram/s_tanhl.c_e.c:67:32");
      computeLdSub(
          (Addr)&temp_var_for_tac_1,
          {(Addr)&temp_var_for_tac_0, (Addr) &(temp_var_for_const_2 = one)},
          "/home/shijia/Public/testprogram/s_tanhl.c_e.c:67:36");
      AssignLd({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_1,
               "/home/shijia/Public/testprogram/s_tanhl.c_e.c:67:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_0;
    }
    /* tanhl(-inf)= -1; */
    else {
      long double temp_var_for_ext_1;
      long double temp_var_for_tac_2, temp_var_for_tac_3;
      long double temp_var_for_const_3, temp_var_for_const_4;
      temp_var_for_tac_2 = one / x;

      temp_var_for_tac_3 = temp_var_for_tac_2 + one;

      temp_var_for_ext_1 = temp_var_for_tac_3;
      computeLdDiv((Addr)&temp_var_for_tac_2,
                   {(Addr) &(temp_var_for_const_3 = one), (Addr)&x},
                   "/home/shijia/Public/testprogram/s_tanhl.c_e.c:76:32");
      computeLdAdd(
          (Addr)&temp_var_for_tac_3,
          {(Addr)&temp_var_for_tac_2, (Addr) &(temp_var_for_const_4 = one)},
          "/home/shijia/Public/testprogram/s_tanhl.c_e.c:76:36");
      AssignLd({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_3,
               "/home/shijia/Public/testprogram/s_tanhl.c_e.c:76:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_1;
    }
    /* tanhl(+inf)=+1 */
  }

  /* |x| < 23 */
  if (ix < 0x4003 || (ix == 0x4003 && j0 < UC(0xb8000000))) { /* |x|<23 */
    if ((ix | j0 | j1) == 0) {
      long double temp_var_for_ext_2;
      temp_var_for_ext_2 = x;
      AssignLd({(Addr)&temp_var_for_ext_2}, (Addr)&x,
               "/home/shijia/Public/testprogram/s_tanhl.c_e.c:89:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_2;
    }
    /* x == +- 0 */
    if (ix < 0x3fc8) /* |x|<2**-55 */
    {
      long double temp_var_for_ext_3;
      long double temp_var_for_tac_4, temp_var_for_tac_5;
      long double temp_var_for_const_5, temp_var_for_const_6;
      temp_var_for_tac_4 = one + tiny;

      temp_var_for_tac_5 = x * temp_var_for_tac_4;

      temp_var_for_ext_3 = temp_var_for_tac_5;
      computeLdAdd((Addr)&temp_var_for_tac_4,
                   {(Addr) &(temp_var_for_const_6 = one),
                    (Addr) &(temp_var_for_const_5 = tiny)},
                   "/home/shijia/Public/testprogram/s_tanhl.c_e.c:99:37");
      computeLdMul((Addr)&temp_var_for_tac_5,
                   {(Addr)&x, (Addr)&temp_var_for_tac_4},
                   "/home/shijia/Public/testprogram/s_tanhl.c_e.c:99:30");
      AssignLd({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_5,
               "/home/shijia/Public/testprogram/s_tanhl.c_e.c:99:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_3;
    }
    /* tanh(small) = small */
    if (ix >= 0x3fff) { /* |x|>=1  */
      long double temp_var_for_ext_4;
      long double temp_var_for_tac_6;
      long double temp_var_for_const_7, temp_var_for_const_8,
          temp_var_for_const_9;
      long double temp_var_for_callexp_0;

      long double temp_var_for_callexp_1;

      temp_var_for_callexp_0 = fabsl(x);
      temp_var_for_tac_6 = two * temp_var_for_callexp_0;

      temp_var_for_callexp_1 = __ieee754_expm1l(temp_var_for_tac_6);
      temp_var_for_ext_4 = temp_var_for_callexp_1;
      computeLdMul((Addr)&temp_var_for_tac_6,
                   {(Addr) &(temp_var_for_const_8 = two),
                    (Addr) &(temp_var_for_const_7 = temp_var_for_callexp_0)},
                   "/home/shijia/Public/testprogram/s_tanhl.c_e.c:108:49");
      AssignLd({(Addr)&temp_var_for_ext_4},
               (Addr) &(temp_var_for_const_9 = temp_var_for_callexp_1),
               "/home/shijia/Public/testprogram/s_tanhl.c_e.c:108:26");
      ; // t
        /*(t_0)(r)(tem)(r)(tem)(t_1)(r)(tem)(r)(tem)(ext_)(r_f)(t)(ext_)(r_f)(__ieee754_expm1l(two
         * * __ieee754_fabsl(x)))*/
      t = temp_var_for_ext_4;
      AssignLd({(Addr)&t}, (Addr)&temp_var_for_ext_4,
               "/home/shijia/Public/testprogram/s_tanhl.c_e.c:111:9");
      ;
      long double temp_var_for_tac_7, temp_var_for_tac_8, temp_var_for_tac_9;
      long double temp_var_for_const_10, temp_var_for_const_11,
          temp_var_for_const_12;
      temp_var_for_tac_7 = t + two;

      temp_var_for_tac_8 = two / temp_var_for_tac_7;

      temp_var_for_tac_9 = one - temp_var_for_tac_8;

      z = temp_var_for_tac_9;
      computeLdAdd((Addr)&temp_var_for_tac_7,
                   {(Addr)&t, (Addr) &(temp_var_for_const_10 = two)},
                   "/home/shijia/Public/testprogram/s_tanhl.c_e.c:112:26");
      computeLdDiv(
          (Addr)&temp_var_for_tac_8,
          {(Addr) &(temp_var_for_const_11 = two), (Addr)&temp_var_for_tac_7},
          "/home/shijia/Public/testprogram/s_tanhl.c_e.c:112:21");
      computeLdSub(
          (Addr)&temp_var_for_tac_9,
          {(Addr) &(temp_var_for_const_12 = one), (Addr)&temp_var_for_tac_8},
          "/home/shijia/Public/testprogram/s_tanhl.c_e.c:112:15");
      AssignLd({(Addr)&z}, (Addr)&temp_var_for_tac_9,
               "/home/shijia/Public/testprogram/s_tanhl.c_e.c:112:9");
      ;
    } else {
      long double temp_var_for_ext_5;
      long double temp_var_for_tac_10, temp_var_for_tac_11;
      long double temp_var_for_const_13, temp_var_for_const_14,
          temp_var_for_const_15, temp_var_for_const_16;
      long double temp_var_for_callexp_2;

      long double temp_var_for_callexp_3;

      temp_var_for_tac_10 = 0.0 - two;

      temp_var_for_callexp_2 = fabsl(x);
      temp_var_for_tac_11 = temp_var_for_tac_10 * temp_var_for_callexp_2;

      temp_var_for_callexp_3 = __ieee754_expm1l(temp_var_for_tac_11);
      temp_var_for_ext_5 = temp_var_for_callexp_3;
      computeLdSub((Addr)&temp_var_for_tac_10,
                   {(Addr) &(temp_var_for_const_14 = 0.0),
                    (Addr) &(temp_var_for_const_13 = two)},
                   "/home/shijia/Public/testprogram/s_tanhl.c_e.c:116:33");
      computeLdMul((Addr)&temp_var_for_tac_11,
                   {(Addr)&temp_var_for_tac_10,
                    (Addr) &(temp_var_for_const_15 = temp_var_for_callexp_2)},
                   "/home/shijia/Public/testprogram/s_tanhl.c_e.c:116:40");
      AssignLd({(Addr)&temp_var_for_ext_5},
               (Addr) &(temp_var_for_const_16 = temp_var_for_callexp_3),
               "/home/shijia/Public/testprogram/s_tanhl.c_e.c:115:26");
      ; // t
        /*(two)(t)(two)(one)(two)(t)(two)(two)(t)(__ieee754_expm1l(-two *
         * __ieee754_fabsl(x)))*/
      t = temp_var_for_ext_5;
      AssignLd({(Addr)&t}, (Addr)&temp_var_for_ext_5,
               "/home/shijia/Public/testprogram/s_tanhl.c_e.c:119:9");
      ;
      long double temp_var_for_tac_12, temp_var_for_tac_13, temp_var_for_tac_14;
      long double temp_var_for_const_17, temp_var_for_const_18;
      temp_var_for_tac_12 = 0.0 - t;

      temp_var_for_tac_13 = t + two;

      temp_var_for_tac_14 = temp_var_for_tac_12 / temp_var_for_tac_13;

      z = temp_var_for_tac_14;
      computeLdSub((Addr)&temp_var_for_tac_12,
                   {(Addr) &(temp_var_for_const_17 = 0.0), (Addr)&t},
                   "/home/shijia/Public/testprogram/s_tanhl.c_e.c:120:16");
      computeLdAdd((Addr)&temp_var_for_tac_13,
                   {(Addr)&t, (Addr) &(temp_var_for_const_18 = two)},
                   "/home/shijia/Public/testprogram/s_tanhl.c_e.c:120:26");
      computeLdDiv((Addr)&temp_var_for_tac_14,
                   {(Addr)&temp_var_for_tac_12, (Addr)&temp_var_for_tac_13},
                   "/home/shijia/Public/testprogram/s_tanhl.c_e.c:120:21");
      AssignLd({(Addr)&z}, (Addr)&temp_var_for_tac_14,
               "/home/shijia/Public/testprogram/s_tanhl.c_e.c:120:9");
      ;
    }
    /* |x| > 23, return +-1 */
  } else {
    long double temp_var_for_tac_15;
    long double temp_var_for_const_19, temp_var_for_const_20;
    temp_var_for_tac_15 = one - tiny;

    z = temp_var_for_tac_15;
    computeLdSub((Addr)&temp_var_for_tac_15,
                 {(Addr) &(temp_var_for_const_20 = one),
                  (Addr) &(temp_var_for_const_19 = tiny)},
                 "/home/shijia/Public/testprogram/s_tanhl.c_e.c:124:13");
    AssignLd({(Addr)&z}, (Addr)&temp_var_for_tac_15,
             "/home/shijia/Public/testprogram/s_tanhl.c_e.c:124:7");
    ; /* raised inexact flag */
  }
  long double temp_var_for_ext_6;
  long double temp_var_for_const_21;
  temp_var_for_ext_6 = (se & 0x8000) ? -z : z;
  AssignLd({(Addr)&temp_var_for_ext_6},
           (Addr) &(temp_var_for_const_21 = (se & 0x8000) ? -z : z),
           "/home/shijia/Public/testprogram/s_tanhl.c_e.c:127:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for(0.0 - e) xt_6;
}

#endif

long double __tanhl(long double x) {
  long double temp_var_for_ext_7;
  temp_var_for_ext_7 = __ieee754_tanhl(x);
  callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_7;
}

__typeof(__tanhl) tanhl __attribute__((weak, alias("__tanhl")));

#endif
