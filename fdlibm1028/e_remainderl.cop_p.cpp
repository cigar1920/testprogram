#include "../ScDebug/scdebug.h"
/* e_remainderl.c -- long double version of e_remainder.c.
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

/* __ieee754_remainderl(x,p)
 * Return :
 *	returns  x REM p  =  x - [x/p]*p as if in infinite
 *	precise arithmetic, where [x/p] is the (infinite bit)
 *	integer nearest x/p (in half way case choose the even one).
 * Method :
 *	Based on fmod() return x-[x/p]chopped*p exactlp.
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

#ifndef __have_fpu_remainder

long double __ieee754_remainderl(long double x, long double p) {
  uint32_t sx, sex, sep, x0, x1, p0, p1;
  long double p_half;

  static const long double zero = 0.0;

  long double temp_var_for_const_0;
  ew_u.value = x;
  AssignLd({(Addr) &(temp_var_for_const_0 = ew_u.value)}, (Addr)&x,
           "/home/shijia/Public/testprogram/e_remainderl.c_e.c:40:3 "
           "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
  ;
  long double temp_var_for_const_1;
  ew_u.value = p;
  AssignLd({(Addr) &(temp_var_for_const_1 = ew_u.value)}, (Addr)&p,
           "/home/shijia/Public/testprogram/e_remainderl.c_e.c:41:3 "
           "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
  ;
  sx = sex & IC(0x8000);
  sep &= IEEE854_LONG_DOUBLE_MAXEXP;
  sex &= IEEE854_LONG_DOUBLE_MAXEXP;

  /* purge off exception values */
  if ((sep | p0 | p1) == 0) {
    long double temp_var_for_ext_0;
    long double temp_var_for_tac_0, temp_var_for_tac_1, temp_var_for_tac_2;
    temp_var_for_tac_0 = x * p;

    temp_var_for_tac_1 = x * p;

    temp_var_for_tac_2 = temp_var_for_tac_0 / temp_var_for_tac_1;

    temp_var_for_ext_0 = temp_var_for_tac_2;
    computeLdMul((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&p},
                 "/home/shijia/Public/testprogram/e_remainderl.c_e.c:49:29");
    computeLdMul((Addr)&temp_var_for_tac_1, {(Addr)&x, (Addr)&p},
                 "/home/shijia/Public/testprogram/e_remainderl.c_e.c:49:39");
    computeLdDiv((Addr)&temp_var_for_tac_2,
                 {(Addr)&temp_var_for_tac_0, (Addr)&temp_var_for_tac_1},
                 "/home/shijia/Public/testprogram/e_remainderl.c_e.c:49:34");
    AssignLd({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_2,
             "/home/shijia/Public/testprogram/e_remainderl.c_e.c:49:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }
  /* p = 0 */
  if ((sex == IEEE854_LONG_DOUBLE_MAXEXP) ||  /* x not finite */
      ((sep == IEEE854_LONG_DOUBLE_MAXEXP) && /* p is NaN */
       (((p0 & IC(0x7fffffff)) | p1) != 0))) {
    long double temp_var_for_ext_1;
    long double temp_var_for_tac_3, temp_var_for_tac_4, temp_var_for_tac_5;
    temp_var_for_tac_3 = x * p;

    temp_var_for_tac_4 = x * p;

    temp_var_for_tac_5 = temp_var_for_tac_3 / temp_var_for_tac_4;

    temp_var_for_ext_1 = temp_var_for_tac_5;
    computeLdMul((Addr)&temp_var_for_tac_3, {(Addr)&x, (Addr)&p},
                 "/home/shijia/Public/testprogram/e_remainderl.c_e.c:59:29");
    computeLdMul((Addr)&temp_var_for_tac_4, {(Addr)&x, (Addr)&p},
                 "/home/shijia/Public/testprogram/e_remainderl.c_e.c:59:39");
    computeLdDiv((Addr)&temp_var_for_tac_5,
                 {(Addr)&temp_var_for_tac_3, (Addr)&temp_var_for_tac_4},
                 "/home/shijia/Public/testprogram/e_remainderl.c_e.c:59:34");
    AssignLd({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_5,
             "/home/shijia/Public/testprogram/e_remainderl.c_e.c:59:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }

  if (sep < (IEEE854_LONG_DOUBLE_MAXEXP - 1)) {
    long double temp_var_for_tac_6;
    long double temp_var_for_const_2;
    long double temp_var_for_callexp_0;

    temp_var_for_tac_6 = p + p;

    temp_var_for_callexp_0 = __ieee754_fmodl(x, temp_var_for_tac_6);
    x = temp_var_for_callexp_0;
    computeLdAdd((Addr)&temp_var_for_tac_6, {(Addr)&p, (Addr)&p},
                 "/home/shijia/Public/testprogram/e_remainderl.c_e.c:66:30");
    AssignLd({(Addr)&x},
             (Addr) &(temp_var_for_const_2 = temp_var_for_callexp_0),
             "/home/shijia/Public/testprogram/e_remainderl.c_e.c:66:7");
    ;
  }
  /* now x < 2p */
  if (((sex - sep) | ((x0 - p0) & IC(0x7fffffff)) | (x1 - p1)) == 0) {
    long double temp_var_for_ext_2;
    long double temp_var_for_tac_7;
    long double temp_var_for_const_3;
    temp_var_for_tac_7 = zero * x;

    temp_var_for_ext_2 = temp_var_for_tac_7;
    computeLdMul((Addr)&temp_var_for_tac_7,
                 {(Addr) &(temp_var_for_const_3 = zero), (Addr)&x},
                 "/home/shijia/Public/testprogram/e_remainderl.c_e.c:71:31");
    AssignLd({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_7,
             "/home/shijia/Public/testprogram/e_remainderl.c_e.c:71:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  }

  long double temp_var_for_ext_3;
  long double temp_var_for_const_4;
  long double temp_var_for_callexp_1;

  temp_var_for_callexp_1 = fabsl(x);
  temp_var_for_ext_3 = temp_var_for_callexp_1;
  AssignLd({(Addr)&temp_var_for_ext_3},
           (Addr) &(temp_var_for_const_4 = temp_var_for_callexp_1),
           "/home/shijia/Public/testprogram/e_remainderl.c_e.c:78:22");
  ; // x
  /*(p)(p)(2)(temp)(__ieee754_fabsl(x))*/
  x = temp_var_for_ext_3;
  AssignLd({(Addr)&x}, (Addr)&temp_var_for_ext_3,
           "/home/shijia/Public/testprogram/e_remainderl.c_e.c:80:5");
  ;
  long double temp_var_for_ext_4;
  long double temp_var_for_const_5;
  long double temp_var_for_callexp_2;

  temp_var_for_callexp_2 = fabsl(p);
  temp_var_for_ext_4 = temp_var_for_callexp_2;
  AssignLd({(Addr)&temp_var_for_ext_4},
           (Addr) &(temp_var_for_const_5 = temp_var_for_callexp_2),
           "/home/shijia/Public/testprogram/e_remainderl.c_e.c:82:22");
  ; // p
  /*(__ieee754_fabsl(p))*/
  p = temp_var_for_ext_4;
  AssignLd({(Addr)&p}, (Addr)&temp_var_for_ext_4,
           "/home/shijia/Public/testprogram/e_remainderl.c_e.c:84:5");
  ;
  if (sep < 0x0002) {
    if (int temp_var_for_tac_8, temp_var_for_tac_9; temp_var_for_tac_8 = x + x;

        temp_var_for_tac_9 = temp_var_for_tac_8 > p;

        ) {
      x -= p;
      ;
      if (int temp_var_for_tac_11, temp_var_for_tac_12;
          temp_var_for_tac_11 = x + x;

          temp_var_for_tac_12 = temp_var_for_tac_11 >= p;

          ) {
        x -= p;
        ;
      }
    }
  } else {
    long double temp_var_for_tac_14;
    long double temp_var_for_const_6;
    temp_var_for_tac_14 = 0.5L * p;

    p_half = temp_var_for_tac_14;
    computeLdAdd((Addr)&temp_var_for_tac_8, {(Addr)&x, (Addr)&x},
                 "/home/shijia/Public/testprogram/e_remainderl.c_e.c:86:11");
    compute((Addr)&temp_var_for_tac_9, {(Addr)&temp_var_for_tac_8, (Addr)&p},
            "/home/shijia/Public/testprogram/e_remainderl.c_e.c:86:15");
    computeLdAdd((Addr)&temp_var_for_tac_11, {(Addr)&x, (Addr)&x},
                 "/home/shijia/Public/testprogram/e_remainderl.c_e.c:88:13");
    compute((Addr)&temp_var_for_tac_12, {(Addr)&temp_var_for_tac_11, (Addr)&p},
            "/home/shijia/Public/testprogram/e_remainderl.c_e.c:88:17");
    computeLdMul((Addr)&temp_var_for_tac_14,
                 {(Addr) &(temp_var_for_const_6 = 0.5L), (Addr)&p},
                 "/home/shijia/Public/testprogram/e_remainderl.c_e.c:93:19");
    AssignLd({(Addr)&p_half}, (Addr)&temp_var_for_tac_14,
             "/home/shijia/Public/testprogram/e_remainderl.c_e.c:93:12");
    ;
    if (int temp_var_for_tac_15; temp_var_for_tac_15 = x > p_half;

        ) {
      x -= p;
      ;
      if (int temp_var_for_tac_17; temp_var_for_tac_17 = x >= p_half;

          ) {
        x -= p;
        ;
      }
    }
  }
  long double temp_var_for_const_7;
  ge_u.value = x;
  compute((Addr)&temp_var_for_tac_15, {(Addr)&x, (Addr)&p_half},
          "/home/shijia/Public/testprogram/e_remainderl.c_e.c:94:11");
  compute((Addr)&temp_var_for_tac_17, {(Addr)&x, (Addr)&p_half},
          "/home/shijia/Public/testprogram/e_remainderl.c_e.c:96:13");
  AssignLd({(Addr) &(temp_var_for_const_7 = ge_u.value)}, (Addr)&x,
           "/home/shijia/Public/testprogram/e_remainderl.c_e.c:101:3 "
           "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:258:14>");
  ;
  long double temp_var_for_ext_5;
  temp_var_for_ext_5;
  long double temp_var_for_ext_6;
  temp_var_for_ext_6 = x;
  AssignLd({(Addr)&temp_var_for_ext_6}, (Addr)&x,
           "/home/shijia/Public/testprogram/e_remainderl.c_e.c:105:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_6;
}

#endif

/* wrapper remainder */
long double __remainderl(long double x, long double y) {
  if (((int temp_var_for_tac_19; int temp_var_for_const_8;
        temp_var_for_tac_19 = y == 0.0;

        &&!isnan(x)) ||
       (isinf(x) && !isnan(y))) &&
      _LIB_VERSION != _IEEE_) {
    long double temp_var_for_ext_7;
    long double temp_var_for_const_9;
    long double temp_var_for_callexp_3;

    temp_var_for_callexp_3 = __kernel_standard_l(x, y, y, KMATHERRL_REMAINDER);
    temp_var_for_ext_7 = temp_var_for_callexp_3;
    compute((Addr)&temp_var_for_tac_19,
            {(Addr)&y, (Addr) &(temp_var_for_const_8 = 0.0)},
            "/home/shijia/Public/testprogram/e_remainderl.c_e.c:115:11");
    AssignLd({(Addr)&temp_var_for_ext_7},
             (Addr) &(temp_var_for_const_9 = temp_var_for_callexp_3),
             "/home/shijia/Public/testprogram/e_remainderl.c_e.c:118:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_7;
  }
  /* remainder domain */

  long double temp_var_for_ext_8;
  long double temp_var_for_const_10;
  long double temp_var_for_callexp_4;

  temp_var_for_callexp_4 = __ieee754_remainderl(x, y);
  temp_var_for_ext_8 = temp_var_for_callexp_4;
  AssignLd({(Addr)&temp_var_for_ext_8},
           (Addr) &(temp_var_for_const_10 = temp_var_for_callexp_4),
           "/home/shijia/Public/testprogram/e_remainderl.c_e.c:126:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_8;
}

__typeof(__remainderl) remainderl __attribute__((weak, alias("__remainderl")));
__typeof(__remainderl) __dreml __attribute__((alias("__remainderl")));
__typeof(remainderl) dreml __attribute__((weak, alias("__dreml")));

#endif
