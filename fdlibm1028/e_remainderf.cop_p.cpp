#include "../ScDebug/scdebug.h"
/* e_remainderf.c -- float version of e_remainder.c.
 * Conversion to float by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.
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

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_remainder

float __ieee754_remainderf(float x, float p) {
  int32_t hx, hp;
  uint32_t sx;
  float p_half;

  static const float zero = 0.0;

  GET_FLOAT_WORD(hx, x);
  GET_FLOAT_WORD(hp, p);
  sx = hx & IC(0x80000000);
  hp &= IC(0x7fffffff);
  hx &= IC(0x7fffffff);

  /* purge off exception values */
  if (FLT_UWORD_IS_ZERO(hp) || !FLT_UWORD_IS_FINITE(hx) ||
      FLT_UWORD_IS_NAN(hp)) {
    float temp_var_for_ext_0;
    float temp_var_for_tac_0, temp_var_for_tac_1, temp_var_for_tac_2;
    temp_var_for_tac_0 = x * p;

    temp_var_for_tac_1 = x * p;

    temp_var_for_tac_2 = temp_var_for_tac_0 / temp_var_for_tac_1;

    temp_var_for_ext_0 = temp_var_for_tac_2;
    computeFMul((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&p},
                "/home/shijia/Public/testprogram/e_remainderf.c_e.c:39:29");
    computeFMul((Addr)&temp_var_for_tac_1, {(Addr)&x, (Addr)&p},
                "/home/shijia/Public/testprogram/e_remainderf.c_e.c:39:39");
    computeFDiv((Addr)&temp_var_for_tac_2,
                {(Addr)&temp_var_for_tac_0, (Addr)&temp_var_for_tac_1},
                "/home/shijia/Public/testprogram/e_remainderf.c_e.c:39:34");
    AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_2,
            "/home/shijia/Public/testprogram/e_remainderf.c_e.c:39:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  if (hp <= FLT_UWORD_HALF_MAX) {
    float temp_var_for_tac_3;
    float temp_var_for_const_0;
    float temp_var_for_callexp_0;

    temp_var_for_tac_3 = p + p;

    temp_var_for_callexp_0 = __ieee754_fmodf(x, temp_var_for_tac_3);
    x = temp_var_for_callexp_0;
    computeFAdd((Addr)&temp_var_for_tac_3, {(Addr)&p, (Addr)&p},
                "/home/shijia/Public/testprogram/e_remainderf.c_e.c:46:30");
    AssignF({(Addr)&x}, (Addr) &(temp_var_for_const_0 = temp_var_for_callexp_0),
            "/home/shijia/Public/testprogram/e_remainderf.c_e.c:46:7");
    ;
  }
  /* now x < 2p */
  if ((hx - hp) == 0) {
    float temp_var_for_ext_1;
    float temp_var_for_tac_4;
    float temp_var_for_const_1;
    temp_var_for_tac_4 = zero * x;

    temp_var_for_ext_1 = temp_var_for_tac_4;
    computeFMul((Addr)&temp_var_for_tac_4,
                {(Addr) &(temp_var_for_const_1 = zero), (Addr)&x},
                "/home/shijia/Public/testprogram/e_remainderf.c_e.c:51:31");
    AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_4,
            "/home/shijia/Public/testprogram/e_remainderf.c_e.c:51:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }

  float temp_var_for_ext_2;
  float temp_var_for_const_2;
  float temp_var_for_callexp_1;

  temp_var_for_callexp_1 = fabsf(x);
  temp_var_for_ext_2 = temp_var_for_callexp_1;
  AssignF({(Addr)&temp_var_for_ext_2},
          (Addr) &(temp_var_for_const_2 = temp_var_for_callexp_1),
          "/home/shijia/Public/testprogram/e_remainderf.c_e.c:58:22");
  ; // x
  /*(p)(p)(1)(temp)(__ieee754_fabsf(x))*/
  x = temp_var_for_ext_2;
  AssignF({(Addr)&x}, (Addr)&temp_var_for_ext_2,
          "/home/shijia/Public/testprogram/e_remainderf.c_e.c:60:5");
  ;
  float temp_var_for_ext_3;
  float temp_var_for_const_3;
  float temp_var_for_callexp_2;

  temp_var_for_callexp_2 = fabsf(p);
  temp_var_for_ext_3 = temp_var_for_callexp_2;
  AssignF({(Addr)&temp_var_for_ext_3},
          (Addr) &(temp_var_for_const_3 = temp_var_for_callexp_2),
          "/home/shijia/Public/testprogram/e_remainderf.c_e.c:62:22");
  ; // p
  /*(__ieee754_fabsf(p))*/
  p = temp_var_for_ext_3;
  AssignF({(Addr)&p}, (Addr)&temp_var_for_ext_3,
          "/home/shijia/Public/testprogram/e_remainderf.c_e.c:64:5");
  ;
  if (hp < IC(0x01000000)) {
    if (int temp_var_for_tac_5, temp_var_for_tac_6; temp_var_for_tac_5 = x + x;

        temp_var_for_tac_6 = temp_var_for_tac_5 > p;

        ) {
      x -= p;
      ;
      if (int temp_var_for_tac_8, temp_var_for_tac_9;
          temp_var_for_tac_8 = x + x;

          temp_var_for_tac_9 = temp_var_for_tac_8 >= p;

          ) {
        x -= p;
        ;
      }
    }
  } else {
    float temp_var_for_tac_11;
    float temp_var_for_const_4;
    temp_var_for_tac_11 = ((float)0.5) * p;

    p_half = temp_var_for_tac_11;
    computeFAdd((Addr)&temp_var_for_tac_5, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_remainderf.c_e.c:66:11");
    compute((Addr)&temp_var_for_tac_6, {(Addr)&temp_var_for_tac_5, (Addr)&p},
            "/home/shijia/Public/testprogram/e_remainderf.c_e.c:66:15");
    computeFAdd((Addr)&temp_var_for_tac_8, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_remainderf.c_e.c:68:13");
    compute((Addr)&temp_var_for_tac_9, {(Addr)&temp_var_for_tac_8, (Addr)&p},
            "/home/shijia/Public/testprogram/e_remainderf.c_e.c:68:17");
    computeFMul((Addr)&temp_var_for_tac_11,
                {(Addr) &(temp_var_for_const_4 = ((float)0.5)), (Addr)&p},
                "/home/shijia/Public/testprogram/e_remainderf.c_e.c:73:25");
    AssignF({(Addr)&p_half}, (Addr)&temp_var_for_tac_11,
            "/home/shijia/Public/testprogram/e_remainderf.c_e.c:73:12");
    ;

    if (int temp_var_for_tac_12; temp_var_for_tac_12 = x > p_half;

        ) {
      x -= p;
      ;
      if (int temp_var_for_tac_14; temp_var_for_tac_14 = x >= p_half;

          ) {
        x -= p;
        ;
      }
    }
  }
  GET_FLOAT_WORD(hx, x);
  SET_FLOAT_WORD(x, hx ^ sx);
  float temp_var_for_ext_4;
  temp_var_for_ext_4 = x;
  compute((Addr)&temp_var_for_tac_12, {(Addr)&x, (Addr)&p_half},
          "/home/shijia/Public/testprogram/e_remainderf.c_e.c:75:11");
  compute((Addr)&temp_var_for_tac_14, {(Addr)&x, (Addr)&p_half},
          "/home/shijia/Public/testprogram/e_remainderf.c_e.c:77:13");
  AssignF({(Addr)&temp_var_for_ext_4}, (Addr)&x,
          "/home/shijia/Public/testprogram/e_remainderf.c_e.c:85:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_4;
}

#endif

/* wrapper remainder */
float __remainderf(float x, float y) {
  if (((int temp_var_for_tac_16; int temp_var_for_const_5;
        temp_var_for_tac_16 = y == 0.0F;

        &&!isnan(x)) ||
       (isinf(x) && !isnan(y))) &&
      _LIB_VERSION != _IEEE_) {
    float temp_var_for_ext_5;
    float temp_var_for_const_6;
    float temp_var_for_callexp_3;

    temp_var_for_callexp_3 = __kernel_standard_f(x, y, y, KMATHERRF_REMAINDER);
    temp_var_for_ext_5 = temp_var_for_callexp_3;
    compute((Addr)&temp_var_for_tac_16,
            {(Addr)&y, (Addr) &(temp_var_for_const_5 = 0.0F)},
            "/home/shijia/Public/testprogram/e_remainderf.c_e.c:95:11");
    AssignF({(Addr)&temp_var_for_ext_5},
            (Addr) &(temp_var_for_const_6 = temp_var_for_callexp_3),
            "/home/shijia/Public/testprogram/e_remainderf.c_e.c:98:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_5;
  }
  /* remainder domain */

  float temp_var_for_ext_6;
  float temp_var_for_const_7;
  float temp_var_for_callexp_4;

  temp_var_for_callexp_4 = __ieee754_remainderf(x, y);
  temp_var_for_ext_6 = temp_var_for_callexp_4;
  AssignF({(Addr)&temp_var_for_ext_6},
          (Addr) &(temp_var_for_const_7 = temp_var_for_callexp_4),
          "/home/shijia/Public/testprogram/e_remainderf.c_e.c:106:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_6;
}

__typeof(__remainderf) remainderf __attribute__((weak, alias("__remainderf")));
__typeof(__remainderf) __dremf __attribute__((alias("__remainderf")));
__typeof(remainderf) dremf __attribute__((weak, alias("__dremf")));
