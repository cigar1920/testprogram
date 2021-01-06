#include "../ScDebug/scdebug.h"
/* @(#)e_remainder.c 1.3 95/01/18 */
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

/* __ieee754_remainder(x,p)
 * Return :
 * 	returns  x REM p  =  x - [x/p]*p as if in infinite
 * 	precise arithmetic, where [x/p] is the (infinite bit)
 *	integer nearest x/p (in half way case choose the even one).
 * Method :
 *	Based on fmod() return x-[x/p]chopped*p exactlp.
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_remainder

double __ieee754_remainder(double x, double p) {
  int32_t hx, hp;
  uint32_t sx, lx, lp;
  double p_half;

  static const double zero = 0.0;

  GET_DOUBLE_WORDS(hx, lx, x);
  GET_DOUBLE_WORDS(hp, lp, p);
  sx = hx & IC(0x80000000);
  hp &= IC(0x7fffffff);
  hx &= IC(0x7fffffff);

  /* purge off exception values */
  if ((hp | lp) == 0) {
    double temp_var_for_ext_0;
    double temp_var_for_tac_0, temp_var_for_tac_1, temp_var_for_tac_2;
    temp_var_for_tac_0 = x * p;

    temp_var_for_tac_1 = x * p;

    temp_var_for_tac_2 = temp_var_for_tac_0 / temp_var_for_tac_1;

    temp_var_for_ext_0 = temp_var_for_tac_2;
    computeDMul((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&p},
                "/home/shijia/Public/testprogram/e_remainder.c_e.c:44:29");
    computeDMul((Addr)&temp_var_for_tac_1, {(Addr)&x, (Addr)&p},
                "/home/shijia/Public/testprogram/e_remainder.c_e.c:44:39");
    computeDDiv((Addr)&temp_var_for_tac_2,
                {(Addr)&temp_var_for_tac_0, (Addr)&temp_var_for_tac_1},
                "/home/shijia/Public/testprogram/e_remainder.c_e.c:44:34");
    AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_2,
            "/home/shijia/Public/testprogram/e_remainder.c_e.c:44:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }
  /* p = 0 */
  if ((hx >= IC(0x7ff00000)) ||  /* x not finite */
      ((hp >= IC(0x7ff00000)) && /* p is NaN */
       (((hp - IC(0x7ff00000)) | lp) != 0))) {
    double temp_var_for_ext_1;
    double temp_var_for_tac_3, temp_var_for_tac_4, temp_var_for_tac_5;
    temp_var_for_tac_3 = x * p;

    temp_var_for_tac_4 = x * p;

    temp_var_for_tac_5 = temp_var_for_tac_3 / temp_var_for_tac_4;

    temp_var_for_ext_1 = temp_var_for_tac_5;
    computeDMul((Addr)&temp_var_for_tac_3, {(Addr)&x, (Addr)&p},
                "/home/shijia/Public/testprogram/e_remainder.c_e.c:54:29");
    computeDMul((Addr)&temp_var_for_tac_4, {(Addr)&x, (Addr)&p},
                "/home/shijia/Public/testprogram/e_remainder.c_e.c:54:39");
    computeDDiv((Addr)&temp_var_for_tac_5,
                {(Addr)&temp_var_for_tac_3, (Addr)&temp_var_for_tac_4},
                "/home/shijia/Public/testprogram/e_remainder.c_e.c:54:34");
    AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_5,
            "/home/shijia/Public/testprogram/e_remainder.c_e.c:54:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }

  if (hp <= IC(0x7fdfffff)) {
    double temp_var_for_tac_6;
    double temp_var_for_const_0;
    double temp_var_for_callexp_0;

    temp_var_for_tac_6 = p + p;

    temp_var_for_callexp_0 = __ieee754_fmod(x, temp_var_for_tac_6);
    x = temp_var_for_callexp_0;
    computeDAdd((Addr)&temp_var_for_tac_6, {(Addr)&p, (Addr)&p},
                "/home/shijia/Public/testprogram/e_remainder.c_e.c:61:29");
    AssignD({(Addr)&x}, (Addr) &(temp_var_for_const_0 = temp_var_for_callexp_0),
            "/home/shijia/Public/testprogram/e_remainder.c_e.c:61:7");
    ;
  }
  /* now x < 2p */
  if (((hx - hp) | (lx - lp)) == 0) {
    double temp_var_for_ext_2;
    double temp_var_for_tac_7;
    double temp_var_for_const_1;
    temp_var_for_tac_7 = zero * x;

    temp_var_for_ext_2 = temp_var_for_tac_7;
    computeDMul((Addr)&temp_var_for_tac_7,
                {(Addr) &(temp_var_for_const_1 = zero), (Addr)&x},
                "/home/shijia/Public/testprogram/e_remainder.c_e.c:66:31");
    AssignD({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_7,
            "/home/shijia/Public/testprogram/e_remainder.c_e.c:66:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  }

  double temp_var_for_ext_3;
  double temp_var_for_const_2;
  double temp_var_for_callexp_1;

  temp_var_for_callexp_1 = fabs(x);
  temp_var_for_ext_3 = temp_var_for_callexp_1;
  AssignD({(Addr)&temp_var_for_ext_3},
          (Addr) &(temp_var_for_const_2 = temp_var_for_callexp_1),
          "/home/shijia/Public/testprogram/e_remainder.c_e.c:73:22");
  ; // x
  /*(p)(p)(2)(temp)(__ieee754_fabs(x))*/
  x = temp_var_for_ext_3;
  AssignD({(Addr)&x}, (Addr)&temp_var_for_ext_3,
          "/home/shijia/Public/testprogram/e_remainder.c_e.c:75:5");
  ;
  double temp_var_for_ext_4;
  double temp_var_for_const_3;
  double temp_var_for_callexp_2;

  temp_var_for_callexp_2 = fabs(p);
  temp_var_for_ext_4 = temp_var_for_callexp_2;
  AssignD({(Addr)&temp_var_for_ext_4},
          (Addr) &(temp_var_for_const_3 = temp_var_for_callexp_2),
          "/home/shijia/Public/testprogram/e_remainder.c_e.c:77:22");
  ; // p
  /*(__ieee754_fabs(p))*/
  p = temp_var_for_ext_4;
  AssignD({(Addr)&p}, (Addr)&temp_var_for_ext_4,
          "/home/shijia/Public/testprogram/e_remainder.c_e.c:79:5");
  ;
  if (hp < IC(0x00200000)) {
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
    double temp_var_for_tac_14;
    double temp_var_for_const_4;
    temp_var_for_tac_14 = 0.5 * p;

    p_half = temp_var_for_tac_14;
    computeDAdd((Addr)&temp_var_for_tac_8, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_remainder.c_e.c:81:11");
    compute((Addr)&temp_var_for_tac_9, {(Addr)&temp_var_for_tac_8, (Addr)&p},
            "/home/shijia/Public/testprogram/e_remainder.c_e.c:81:15");
    computeDAdd((Addr)&temp_var_for_tac_11, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_remainder.c_e.c:83:13");
    compute((Addr)&temp_var_for_tac_12, {(Addr)&temp_var_for_tac_11, (Addr)&p},
            "/home/shijia/Public/testprogram/e_remainder.c_e.c:83:17");
    computeDMul((Addr)&temp_var_for_tac_14,
                {(Addr) &(temp_var_for_const_4 = 0.5), (Addr)&p},
                "/home/shijia/Public/testprogram/e_remainder.c_e.c:88:18");
    AssignD({(Addr)&p_half}, (Addr)&temp_var_for_tac_14,
            "/home/shijia/Public/testprogram/e_remainder.c_e.c:88:12");
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
  GET_HIGH_WORD(hx, x);
  SET_HIGH_WORD(x, hx ^ sx);
  double temp_var_for_ext_5;
  temp_var_for_ext_5 = x;
  compute((Addr)&temp_var_for_tac_15, {(Addr)&x, (Addr)&p_half},
          "/home/shijia/Public/testprogram/e_remainder.c_e.c:89:11");
  compute((Addr)&temp_var_for_tac_17, {(Addr)&x, (Addr)&p_half},
          "/home/shijia/Public/testprogram/e_remainder.c_e.c:91:13");
  AssignD({(Addr)&temp_var_for_ext_5}, (Addr)&x,
          "/home/shijia/Public/testprogram/e_remainder.c_e.c:99:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_5;
}

#endif

/* wrapper remainder */
double __remainder(double x, double y) {
  if (((int temp_var_for_tac_19; int temp_var_for_const_5;
        temp_var_for_tac_19 = y == 0.0;

        &&!isnan(x)) ||
       (isinf(x) && !isnan(y))) &&
      _LIB_VERSION != _IEEE_) {
    double temp_var_for_ext_6;
    double temp_var_for_const_6;
    double temp_var_for_callexp_3;

    temp_var_for_callexp_3 = __kernel_standard(x, y, y, KMATHERR_REMAINDER);
    temp_var_for_ext_6 = temp_var_for_callexp_3;
    compute((Addr)&temp_var_for_tac_19,
            {(Addr)&y, (Addr) &(temp_var_for_const_5 = 0.0)},
            "/home/shijia/Public/testprogram/e_remainder.c_e.c:109:11");
    AssignD({(Addr)&temp_var_for_ext_6},
            (Addr) &(temp_var_for_const_6 = temp_var_for_callexp_3),
            "/home/shijia/Public/testprogram/e_remainder.c_e.c:112:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_6;
  }
  /* remainder domain */

  double temp_var_for_ext_7;
  double temp_var_for_const_7;
  double temp_var_for_callexp_4;

  temp_var_for_callexp_4 = __ieee754_remainder(x, y);
  temp_var_for_ext_7 = temp_var_for_callexp_4;
  AssignD({(Addr)&temp_var_for_ext_7},
          (Addr) &(temp_var_for_const_7 = temp_var_for_callexp_4),
          "/home/shijia/Public/testprogram/e_remainder.c_e.c:120:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_7;
}

#undef drem
#undef dreml

__typeof(__remainder) remainder __attribute__((weak, alias("__remainder")));
__typeof(__remainder) __drem __attribute__((alias("__remainder")));
__typeof(remainder) drem __attribute__((weak, alias("__drem")));
#ifdef __NO_LONG_DOUBLE_MATH
__typeof(__remainderl) __remainderl __attribute__((alias("__remainder")));
__typeof(__remainderl) remainderl __attribute__((weak, alias("__remainder")));
__typeof(__remainderl) __dreml __attribute__((alias("__remainderl")));
__typeof(__remainderl) dreml __attribute__((weak, alias("__dreml")));
#endif
