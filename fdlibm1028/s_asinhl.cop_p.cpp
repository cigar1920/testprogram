#include "../ScDebug/scdebug.h"
/* s_asinhl.c -- long double version of s_asinh.c.
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

/* asinhl(x)
 * Method :
 *	Based on
 *		asinhl(x) = signl(x) * logl [ |x| + sqrtl(x*x+1) ]
 *	we have
 *	asinhl(x) := x  if  1+x*x=1,
 *		  := signl(x)*(logl(x)+ln2)) for large |x|, else
 *		  := signl(x)*logl(2|x|+1/(|x|+sqrtl(x*x+1))) if|x|>2, else
 *		  := signl(x)*log1pl(|x| + x^2/(1 + sqrtl(1+x^2)))
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

#ifndef __have_fpu_asinh

long double __ieee754_asinhl(long double x) {
  long double t, w;
  int32_t hx, ix;

  static const long double one =
      1.000000000000000000000e+00L; /* 0x3FFF, 0x00000000, 0x00000000 */
  static const long double ln2 =
      6.931471805599453094287e-01L; /* 0x3FFE, 0xB17217F7, 0xD1CF79AC */
  static const long double hugeval = 1.000000000000000000e+4900L;

  long double temp_var_for_const_0;
  ge_u.value = x;
  AssignLd({(Addr) &(temp_var_for_const_0 = ge_u.value)}, (Addr)&x,
           "/home/shijia/Public/testprogram/s_asinhl.c_e.c:46:3 "
           "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:258:14>");
  ;
  ix = hx & IEEE854_LONG_DOUBLE_MAXEXP;
  if (ix < 0x3fde) { /* |x|<2**-34 */
    if (int temp_var_for_tac_0, temp_var_for_tac_1;
        int temp_var_for_const_1, temp_var_for_const_2;
        temp_var_for_tac_0 = hugeval + x;

        temp_var_for_tac_1 = temp_var_for_tac_0 > one;

        ) {
      long double temp_var_for_ext_0;
      temp_var_for_ext_0 = x;
      computeLdAdd((Addr)&temp_var_for_tac_0,
                   {(Addr) &(temp_var_for_const_1 = hugeval), (Addr)&x},
                   "/home/shijia/Public/testprogram/s_asinhl.c_e.c:49:17");
      compute((Addr)&temp_var_for_tac_1,
              {(Addr)&temp_var_for_tac_0, (Addr) &(temp_var_for_const_2 = one)},
              "/home/shijia/Public/testprogram/s_asinhl.c_e.c:49:21");
      AssignLd({(Addr)&temp_var_for_ext_0}, (Addr)&x,
               "/home/shijia/Public/testprogram/s_asinhl.c_e.c:51:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_0;
    }
    /* return x inexact except 0 */
  }
  if (ix > 0x4020) { /* |x| > 2**34 */
    if (ix == IEEE854_LONG_DOUBLE_MAXEXP) {
      long double temp_var_for_ext_1;
      long double temp_var_for_tac_2;
      temp_var_for_tac_2 = x + x;

      temp_var_for_ext_1 = temp_var_for_tac_2;
      computeLdAdd((Addr)&temp_var_for_tac_2, {(Addr)&x, (Addr)&x},
                   "/home/shijia/Public/testprogram/s_asinhl.c_e.c:62:30");
      AssignLd({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_2,
               "/home/shijia/Public/testprogram/s_asinhl.c_e.c:62:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_1;
    }
    /* x is inf or NaN */
    long double temp_var_for_tac_3;
    long double temp_var_for_const_3, temp_var_for_const_4;
    long double temp_var_for_callexp_0;

    /*embed fun has found*/
    long double temp_var_for_callexp_1;

    temp_var_for_callexp_0 = fabsl(x);
    temp_var_for_callexp_1 = __ieee754_logl(temp_var_for_callexp_0);
    temp_var_for_tac_3 = temp_var_for_callexp_1 + ln2;

    w = temp_var_for_tac_3;
    computeLdAdd((Addr)&temp_var_for_tac_3,
                 {(Addr) &(temp_var_for_const_4 = temp_var_for_callexp_1),
                  (Addr) &(temp_var_for_const_3 = ln2)},
                 "/home/shijia/Public/testprogram/s_asinhl.c_e.c:69:44");
    AssignLd({(Addr)&w}, (Addr)&temp_var_for_tac_3,
             "/home/shijia/Public/testprogram/s_asinhl.c_e.c:69:7");
    ;
  } else {
    long double xa = __ieee754_fabsl(x);

    if (ix > 0x4000) { /* 2**34 > |x| > 2.0 */
      long double temp_var_for_tac_4, temp_var_for_tac_5, temp_var_for_tac_6,
          temp_var_for_tac_7, temp_var_for_tac_8, temp_var_for_tac_9;
      long double temp_var_for_const_5, temp_var_for_const_6,
          temp_var_for_const_7, temp_var_for_const_8, temp_var_for_const_9;
      long double temp_var_for_callexp_2;

      long double temp_var_for_callexp_3;

      temp_var_for_tac_4 = 2.0L * xa;

      temp_var_for_tac_5 = xa * xa;

      temp_var_for_tac_6 = temp_var_for_tac_5 + one;

      temp_var_for_callexp_2 = __ieee754_sqrtl(temp_var_for_tac_6);
      temp_var_for_tac_7 = temp_var_for_callexp_2 + xa;

      temp_var_for_tac_8 = one / temp_var_for_tac_7;

      temp_var_for_tac_9 = temp_var_for_tac_4 + temp_var_for_tac_8;

      temp_var_for_callexp_3 = __ieee754_logl(temp_var_for_tac_9);
      w = temp_var_for_callexp_3;
      computeLdMul((Addr)&temp_var_for_tac_4,
                   {(Addr) &(temp_var_for_const_5 = 2.0L), (Addr)&xa},
                   "/home/shijia/Public/testprogram/s_asinhl.c_e.c:74:31");
      computeLdMul((Addr)&temp_var_for_tac_5, {(Addr)&xa, (Addr)&xa},
                   "/home/shijia/Public/testprogram/s_asinhl.c_e.c:75:52");
      computeLdAdd(
          (Addr)&temp_var_for_tac_6,
          {(Addr)&temp_var_for_tac_5, (Addr) &(temp_var_for_const_6 = one)},
          "/home/shijia/Public/testprogram/s_asinhl.c_e.c:75:57");
      computeLdAdd(
          (Addr)&temp_var_for_tac_7,
          {(Addr) &(temp_var_for_const_7 = temp_var_for_callexp_2), (Addr)&xa},
          "/home/shijia/Public/testprogram/s_asinhl.c_e.c:75:64");
      computeLdDiv(
          (Addr)&temp_var_for_tac_8,
          {(Addr) &(temp_var_for_const_8 = one), (Addr)&temp_var_for_tac_7},
          "/home/shijia/Public/testprogram/s_asinhl.c_e.c:75:30");
      computeLdAdd((Addr)&temp_var_for_tac_9,
                   {(Addr)&temp_var_for_tac_4, (Addr)&temp_var_for_tac_8},
                   "/home/shijia/Public/testprogram/s_asinhl.c_e.c:74:36");
      AssignLd({(Addr)&w},
               (Addr) &(temp_var_for_const_9 = temp_var_for_callexp_3),
               "/home/shijia/Public/testprogram/s_asinhl.c_e.c:74:9");
      ;
    } else { /* 2.0 > |x| > 2**-28 */
      long double temp_var_for_tac_10;
      temp_var_for_tac_10 = xa * xa;

      t = temp_var_for_tac_10;
      computeLdMul((Addr)&temp_var_for_tac_10, {(Addr)&xa, (Addr)&xa},
                   "/home/shijia/Public/testprogram/s_asinhl.c_e.c:77:14");
      AssignLd({(Addr)&t}, (Addr)&temp_var_for_tac_10,
               "/home/shijia/Public/testprogram/s_asinhl.c_e.c:77:9");
      ;
      long double temp_var_for_tac_11, temp_var_for_tac_12, temp_var_for_tac_13,
          temp_var_for_tac_14;
      long double temp_var_for_const_10, temp_var_for_const_11,
          temp_var_for_const_12, temp_var_for_const_13;
      long double temp_var_for_callexp_4;

      long double temp_var_for_callexp_5;

      temp_var_for_tac_11 = one + t;

      temp_var_for_callexp_4 = __ieee754_sqrtl(temp_var_for_tac_11);
      temp_var_for_tac_12 = one + temp_var_for_callexp_4;

      temp_var_for_tac_13 = t / temp_var_for_tac_12;

      temp_var_for_tac_14 = xa + temp_var_for_tac_13;

      temp_var_for_callexp_5 = __ieee754_log1pl(temp_var_for_tac_14);
      w = temp_var_for_callexp_5;
      computeLdAdd((Addr)&temp_var_for_tac_11,
                   {(Addr) &(temp_var_for_const_10 = one), (Addr)&t},
                   "/home/shijia/Public/testprogram/s_asinhl.c_e.c:78:64");
      computeLdAdd((Addr)&temp_var_for_tac_12,
                   {(Addr) &(temp_var_for_const_12 = one),
                    (Addr) &(temp_var_for_const_11 = temp_var_for_callexp_4)},
                   "/home/shijia/Public/testprogram/s_asinhl.c_e.c:78:42");
      computeLdDiv((Addr)&temp_var_for_tac_13,
                   {(Addr)&t, (Addr)&temp_var_for_tac_12},
                   "/home/shijia/Public/testprogram/s_asinhl.c_e.c:78:35");
      computeLdAdd((Addr)&temp_var_for_tac_14,
                   {(Addr)&xa, (Addr)&temp_var_for_tac_13},
                   "/home/shijia/Public/testprogram/s_asinhl.c_e.c:78:31");
      AssignLd({(Addr)&w},
               (Addr) &(temp_var_for_const_13 = temp_var_for_callexp_5),
               "/home/shijia/Public/testprogram/s_asinhl.c_e.c:78:9");
      ;
    }
  }
  if (hx > 0) {
    long double temp_var_for_ext_2;
    temp_var_for_ext_2 = w;
    AssignLd({(Addr)&temp_var_for_ext_2}, (Addr)&w,
             "/home/shijia/Public/testprogram/s_asinhl.c_e.c:83:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  }

  long double temp_var_for_ext_3;
  long double temp_var_for_const_14;
  temp_var_for_ext_3 = (-(w));
  AssignLd({(Addr)&temp_var_for_ext_3},
           (Addr) &(temp_var_for_const_14 = (-(w))),
           "/home/shijia/Public/testprogram/s_asinhl.c_e.c:90:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
  callExp++; /*identify the function is  add move tmpShadow*/
  return (double temp_var_for_tac_15;
          double temp_var_for_const_15, temp_var_for_const_16;
          temp_var_for_tac_15 = 0.0 - 3;

          );
}

#endif

long double __asinhl(long double x) {
  long double temp_var_for_ext_4;
  long double temp_var_for_const_17;
  long double temp_var_for_callexp_6;

  temp_var_for_callexp_6 = __ieee754_asinhl(x);
  temp_var_for_ext_4 = temp_var_for_callexp_6;
  computeDSub((Addr)&temp_var_for_tac_15,
              {(Addr) &(temp_var_for_const_16 = 0.0),
               (Addr) &(temp_var_for_const_15 = 3)},
              "/home/shijia/Public/testprogram/s_asinhl.c_e.c:93:15");
  AssignLd({(Addr)&temp_var_for_ext_4},
           (Addr) &(temp_var_for_const_17 = temp_var_for_callexp_6),
           "/home/shijia/Public/testprogram/s_asinhl.c_e.c:100:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_4;
}

__typeof(__asinhl) asinhl __attribute__((weak, alias("__asinhl")));

#endif
