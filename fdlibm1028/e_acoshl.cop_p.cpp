#include "../ScDebug/scdebug.h"
/* e_acoshl.c -- long double version of e_acosh.c.
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

/* __ieee754_acoshl(x)
 * Method :
 *	Based on
 *		acoshl(x) = logl [ x + sqrtl(x*x-1) ]
 *	we have
 *		acoshl(x) := logl(x)+ln2,	if x is large; else
 *		acoshl(x) := logl(2x-1/(sqrtl(x*x-1)+x)) if x>2; else
 *		acoshl(x) := log1pl(t+sqrtl(2.0*t+t*t)); where t=x-1.
 *
 * Special cases:
 *	acoshl(x) is NaN with signal if x<1.
 *	acoshl(NaN) is NaN without signal.
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

#ifndef __have_fpu_acosh

long double __ieee754_acoshl(long double x) {
  long double t;
  uint32_t se, i0, i1;

  static const long double one = 1.0;
  static const long double ln2 =
      6.931471805599453094287e-01L; /* 0x3FFE, 0xB17217F7, 0xD1CF79AC */

  long double temp_var_for_const_0;
  ew_u.value = x;
  AssignLd({(Addr) &(temp_var_for_const_0 = ew_u.value)}, (Addr)&x,
           "/home/shijia/Public/testprogram/e_acoshl.c_e.c:47:3 "
           "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
  ;
  if (se < 0x3fff || (se & 0x8000)) { /* x < 1 */
    long double temp_var_for_ext_0;
    long double temp_var_for_tac_0, temp_var_for_tac_1, temp_var_for_tac_2;
    temp_var_for_tac_0 = x - x;

    temp_var_for_tac_1 = x - x;

    temp_var_for_tac_2 = temp_var_for_tac_0 / temp_var_for_tac_1;

    temp_var_for_ext_0 = temp_var_for_tac_2;
    computeLdSub((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&x},
                 "/home/shijia/Public/testprogram/e_acoshl.c_e.c:50:29");
    computeLdSub((Addr)&temp_var_for_tac_1, {(Addr)&x, (Addr)&x},
                 "/home/shijia/Public/testprogram/e_acoshl.c_e.c:50:39");
    computeLdDiv((Addr)&temp_var_for_tac_2,
                 {(Addr)&temp_var_for_tac_0, (Addr)&temp_var_for_tac_1},
                 "/home/shijia/Public/testprogram/e_acoshl.c_e.c:50:34");
    AssignLd({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_2,
             "/home/shijia/Public/testprogram/e_acoshl.c_e.c:50:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  } else {
    if (se >= 0x401d) {   /* x > 2**30 */
      if (se >= 0x7fff) { /* x is inf of NaN */
        long double temp_var_for_ext_1;
        long double temp_var_for_tac_3;
        temp_var_for_tac_3 = x + x;

        temp_var_for_ext_1 = temp_var_for_tac_3;
        computeLdAdd((Addr)&temp_var_for_tac_3, {(Addr)&x, (Addr)&x},
                     "/home/shijia/Public/testprogram/e_acoshl.c_e.c:58:32");
        AssignLd({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_3,
                 "/home/shijia/Public/testprogram/e_acoshl.c_e.c:58:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_1;
      } else {
        long double temp_var_for_ext_2;
        long double temp_var_for_tac_4;
        long double temp_var_for_const_1, temp_var_for_const_2;
        long double temp_var_for_callexp_0;

        temp_var_for_callexp_0 = __ieee754_logl(x);
        temp_var_for_tac_4 = temp_var_for_callexp_0 + ln2;

        temp_var_for_ext_2 = temp_var_for_tac_4;
        computeLdAdd((Addr)&temp_var_for_tac_4,
                     {(Addr) &(temp_var_for_const_2 = temp_var_for_callexp_0),
                      (Addr) &(temp_var_for_const_1 = ln2)},
                     "/home/shijia/Public/testprogram/e_acoshl.c_e.c:65:48");
        AssignLd({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_4,
                 "/home/shijia/Public/testprogram/e_acoshl.c_e.c:65:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_2;
      }
      /* acoshl(huge)=logl(2x) */
    } else {
      if (((se - 0x3fff) | i0 | i1) == 0) {
        long double temp_var_for_ext_3;
        long double temp_var_for_const_3;
        temp_var_for_ext_3 = 0.0;
        AssignLd({(Addr)&temp_var_for_ext_3},
                 (Addr) &(temp_var_for_const_3 = 0.0),
                 "/home/shijia/Public/testprogram/e_acoshl.c_e.c:75:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_3; /* acosh(1) = 0 */
      } else {
        if (se > 0x4000) { /* 2**28 > x > 2 */
          long double temp_var_for_ext_4;
          long double temp_var_for_tac_5;
          temp_var_for_tac_5 = x * x;

          temp_var_for_ext_4 = temp_var_for_tac_5;
          computeLdMul((Addr)&temp_var_for_tac_5, {(Addr)&x, (Addr)&x},
                       "/home/shijia/Public/testprogram/e_acoshl.c_e.c:83:34");
          AssignLd({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_5,
                   "/home/shijia/Public/testprogram/e_acoshl.c_e.c:83:30");
          ; // t
          /*(_)(_)(a)(m)(a)(m)(_)(_)(1)(t)(t_2)(temp_var_for)(x)(x)*/
          t = temp_var_for_ext_4;
          AssignLd({(Addr)&t}, (Addr)&temp_var_for_ext_4,
                   "/home/shijia/Public/testprogram/e_acoshl.c_e.c:85:13");
          ;
          long double temp_var_for_ext_5;
          long double temp_var_for_tac_6, temp_var_for_tac_7,
              temp_var_for_tac_8, temp_var_for_tac_9, temp_var_for_tac_10;
          long double temp_var_for_const_4, temp_var_for_const_5,
              temp_var_for_const_6, temp_var_for_const_7, temp_var_for_const_8;
          long double temp_var_for_callexp_1;

          long double temp_var_for_callexp_2;

          temp_var_for_tac_6 = 2.0 * x;

          temp_var_for_tac_7 = t - one;

          temp_var_for_callexp_1 = __ieee754_sqrtl(temp_var_for_tac_7);
          temp_var_for_tac_8 = x + temp_var_for_callexp_1;

          temp_var_for_tac_9 = one / temp_var_for_tac_8;

          temp_var_for_tac_10 = temp_var_for_tac_6 - temp_var_for_tac_9;

          temp_var_for_callexp_2 = __ieee754_logl(temp_var_for_tac_10);
          temp_var_for_ext_5 = temp_var_for_callexp_2;
          computeLdMul((Addr)&temp_var_for_tac_6,
                       {(Addr) &(temp_var_for_const_4 = 2.0), (Addr)&x},
                       "/home/shijia/Public/testprogram/e_acoshl.c_e.c:88:34");
          computeLdSub((Addr)&temp_var_for_tac_7,
                       {(Addr)&t, (Addr) &(temp_var_for_const_5 = one)},
                       "/home/shijia/Public/testprogram/e_acoshl.c_e.c:88:69");
          computeLdAdd((Addr)&temp_var_for_tac_8,
                       {(Addr)&x, (Addr) &(temp_var_for_const_6 =
                                               temp_var_for_callexp_1)},
                       "/home/shijia/Public/testprogram/e_acoshl.c_e.c:88:49");
          computeLdDiv(
              (Addr)&temp_var_for_tac_9,
              {(Addr) &(temp_var_for_const_7 = one), (Addr)&temp_var_for_tac_8},
              "/home/shijia/Public/testprogram/e_acoshl.c_e.c:88:44");
          computeLdSub((Addr)&temp_var_for_tac_10,
                       {(Addr)&temp_var_for_tac_6, (Addr)&temp_var_for_tac_9},
                       "/home/shijia/Public/testprogram/e_acoshl.c_e.c:88:38");
          AssignLd({(Addr)&temp_var_for_ext_5},
                   (Addr) &(temp_var_for_const_8 = temp_var_for_callexp_2),
                   "/home/shijia/Public/testprogram/e_acoshl.c_e.c:87:30");
          ;
          callExpStack.push(
              getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
          callExp++; /*identify the function is  add move tmpShadow*/
          return temp_var_for_ext_5;
        } else { /* 1<x<2 */
          long double temp_var_for_tac_11;
          long double temp_var_for_const_9;
          temp_var_for_tac_11 = x - one;

          t = temp_var_for_tac_11;
          computeLdSub((Addr)&temp_var_for_tac_11,
                       {(Addr)&x, (Addr) &(temp_var_for_const_9 = one)},
                       "/home/shijia/Public/testprogram/e_acoshl.c_e.c:94:17");
          AssignLd({(Addr)&t}, (Addr)&temp_var_for_tac_11,
                   "/home/shijia/Public/testprogram/e_acoshl.c_e.c:94:13");
          ;
          long double temp_var_for_ext_6;
          long double temp_var_for_tac_12, temp_var_for_tac_13,
              temp_var_for_tac_14, temp_var_for_tac_15;
          long double temp_var_for_const_10, temp_var_for_const_11,
              temp_var_for_const_12;
          long double temp_var_for_callexp_3;

          long double temp_var_for_callexp_4;

          temp_var_for_tac_12 = 2.0 * t;

          temp_var_for_tac_13 = t * t;

          temp_var_for_tac_14 = temp_var_for_tac_12 + temp_var_for_tac_13;

          temp_var_for_callexp_3 = __ieee754_sqrtl(temp_var_for_tac_14);
          temp_var_for_tac_15 = t + temp_var_for_callexp_3;

          temp_var_for_callexp_4 = __ieee754_log1pl(temp_var_for_tac_15);
          temp_var_for_ext_6 = temp_var_for_callexp_4;
          computeLdMul((Addr)&temp_var_for_tac_12,
                       {(Addr) &(temp_var_for_const_10 = 2.0), (Addr)&t},
                       "/home/shijia/Public/testprogram/e_acoshl.c_e.c:97:56");
          computeLdMul((Addr)&temp_var_for_tac_13, {(Addr)&t, (Addr)&t},
                       "/home/shijia/Public/testprogram/e_acoshl.c_e.c:97:64");
          computeLdAdd((Addr)&temp_var_for_tac_14,
                       {(Addr)&temp_var_for_tac_12, (Addr)&temp_var_for_tac_13},
                       "/home/shijia/Public/testprogram/e_acoshl.c_e.c:97:60");
          computeLdAdd((Addr)&temp_var_for_tac_15,
                       {(Addr)&t, (Addr) &(temp_var_for_const_11 =
                                               temp_var_for_callexp_3)},
                       "/home/shijia/Public/testprogram/e_acoshl.c_e.c:97:34");
          AssignLd({(Addr)&temp_var_for_ext_6},
                   (Addr) &(temp_var_for_const_12 = temp_var_for_callexp_4),
                   "/home/shijia/Public/testprogram/e_acoshl.c_e.c:96:30");
          ;
          callExpStack.push(
              getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
          callExp++; /*identify the function is  add move tmpShadow*/
          return temp_var_for_ext_6;
        }
      }
    }
  }
}

#endif

/* wrapper acosl */
long double __acoshl(long double x) {
  if (isless(x, 1.0L) && _LIB_VERSION != _IEEE_)
  /* acosh(x<1) */
  {
    long double temp_var_for_ext_7;
    long double temp_var_for_const_13;
    long double temp_var_for_callexp_5;

    /*embed fun has found*/
    long double temp_var_for_callexp_6;

    temp_var_for_callexp_5 = __builtin_nanl("");
    temp_var_for_callexp_6 =
        __kernel_standard_l(x, x, temp_var_for_callexp_5, KMATHERRL_ACOSH);
    temp_var_for_ext_7 = temp_var_for_callexp_6;
    AssignLd({(Addr)&temp_var_for_ext_7},
             (Addr) &(temp_var_for_const_13 = temp_var_for_callexp_6),
             "/home/shijia/Public/testprogram/e_acoshl.c_e.c:116:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_7;
  }

  long double temp_var_for_ext_8;
  long double temp_var_for_const_14;
  long double temp_var_for_callexp_7;

  temp_var_for_callexp_7 = __ieee754_acoshl(x);
  temp_var_for_ext_8 = temp_var_for_callexp_7;
  AssignLd({(Addr)&temp_var_for_ext_8},
           (Addr) &(temp_var_for_const_14 = temp_var_for_callexp_7),
           "/home/shijia/Public/testprogram/e_acoshl.c_e.c:124:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_8;
}

__typeof(__acoshl) acoshl __attribute__((weak, alias("__acoshl")));

#endif
