#include "../ScDebug/scdebug.h"
/* e_ynf.c -- float version of e_jn.c.
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

float __ieee754_ynf(int n, float x) {
  int32_t i, hx, ix;
  uint32_t ib;
  int sign;
  float a, b, temp;

  static const float zero = 0.0000000000e+00;

  GET_FLOAT_WORD(hx, x);
  ix = IC(0x7fffffff) & hx;
  /* if Y(n,NaN) is NaN */
  if (FLT_UWORD_IS_NAN(ix)) {
    float temp_var_for_ext_0;
    float temp_var_for_tac_0;
    temp_var_for_tac_0 = x + x;

    temp_var_for_ext_0 = temp_var_for_tac_0;
    computeFAdd((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_ynf.c_e.c:33:28");
    AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_0,
            "/home/shijia/Public/testprogram/e_ynf.c_e.c:33:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  if (FLT_UWORD_IS_ZERO(ix)) {
    float temp_var_for_ext_1;
    float temp_var_for_tac_1;
    float temp_var_for_const_0;
    temp_var_for_callexp_0 = __builtin_huge_valf();
    temp_var_for_tac_1 = (-(temp_var_for_callexp_0)) + x;

    temp_var_for_ext_1 = temp_var_for_tac_1;
    computeFAdd((Addr)&temp_var_for_tac_1,
                {(Addr) &(temp_var_for_const_0 = (-(temp_var_for_callexp_0))),
                 (Addr)&x},
                "/home/shijia/Public/testprogram/e_ynf.c_e.c:41:37");
    AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_1,
            "/home/shijia/Public/testprogram/e_ynf.c_e.c:41:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return (0.0 - var_for_e)xt_1;
  }
  /* -inf and overflow exception.  */
  if (hx < 0) {
    float temp_var_for_ext_2;
    float temp_var_for_tac_2, temp_var_for_tac_3;
    float temp_var_for_const_1, temp_var_for_const_2;
    temp_var_for_tac_2 = zero * x;

    temp_var_for_tac_3 = zero / temp_var_for_tac_2;

    temp_var_for_ext_2 = temp_var_for_tac_3;
    computeFMul((Addr)&temp_var_for_tac_2,
                {(Addr) &(temp_var_for_const_1 = zero), (Addr)&x},
                "/home/shijia/Public/testprogram/e_ynf.c_e.c:49:39");
    computeFDiv(
        (Addr)&temp_var_for_tac_3,
        {(Addr) &(temp_var_for_const_2 = zero), (Addr)&temp_var_for_tac_2},
        "/home/shijia/Public/testprogram/e_ynf.c_e.c:49:31");
    AssignF({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_3,
            "/home/shijia/Public/testprogram/e_ynf.c_e.c:49:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  }

  sign = 1;
  if (n < 0) {
    n = -n;
    sign = 1 - ((n & 1) << 1);
  }
  if (n == 0) {
    float temp_var_for_ext_3;
    float temp_var_for_const_3;
    float temp_var_for_callexp_1;

    temp_var_for_callexp_1 = __ieee754_y0f(x);
    temp_var_for_ext_3 = temp_var_for_callexp_1;
    AssignF({(Addr)&temp_var_for_ext_3},
            (Addr) &(temp_var_for_const_3 = temp_var_for_callexp_1),
            "/home/shijia/Public/testprogram/e_ynf.c_e.c:62:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_3;
  }

  if (n == 1) {
    float temp_var_for_ext_4;
    float temp_var_for_tac_4;
    float temp_var_for_const_4, temp_var_for_const_5;
    float temp_var_for_callexp_2;

    temp_var_for_callexp_2 = __ieee754_y1f(x);
    temp_var_for_tac_4 = sign * temp_var_for_callexp_2;

    temp_var_for_ext_4 = temp_var_for_tac_4;
    computeFMul((Addr)&temp_var_for_tac_4,
                {(Addr) &(temp_var_for_const_5 = sign),
                 (Addr) &(temp_var_for_const_4 = temp_var_for_callexp_2)},
                "/home/shijia/Public/testprogram/e_ynf.c_e.c:70:32");
    AssignF({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_4,
            "/home/shijia/Public/testprogram/e_ynf.c_e.c:70:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_4;
  }

  if (FLT_UWORD_IS_INFINITE(ix)) {
    float temp_var_for_ext_5;
    float temp_var_for_const_6;
    temp_var_for_ext_5 = zero;
    AssignF({(Addr)&temp_var_for_ext_5}, (Addr) &(temp_var_for_const_6 = zero),
            "/home/shijia/Public/testprogram/e_ynf.c_e.c:78:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_5;
  }

  float temp_var_for_const_7;
  float temp_var_for_callexp_3;

  temp_var_for_callexp_3 = __ieee754_y0f(x);
  a = temp_var_for_callexp_3;
  AssignF({(Addr)&a}, (Addr) &(temp_var_for_const_7 = temp_var_for_callexp_3),
          "/home/shijia/Public/testprogram/e_ynf.c_e.c:84:5");
  ;
  float temp_var_for_const_8;
  float temp_var_for_callexp_4;

  temp_var_for_callexp_4 = __ieee754_y1f(x);
  b = temp_var_for_callexp_4;
  AssignF({(Addr)&b}, (Addr) &(temp_var_for_const_8 = temp_var_for_callexp_4),
          "/home/shijia/Public/testprogram/e_ynf.c_e.c:85:5");
  ;
  /* quit if b is -inf */
  GET_FLOAT_WORD(ib, b);
  for (i = 1; i < n && ib != UC(0xff800000); i++) {
    temp = b;
    AssignF({(Addr)&temp}, (Addr)&b,
            "/home/shijia/Public/testprogram/e_ynf.c_e.c:89:10");
    ;
    float temp_var_for_ext_6;
    float temp_var_for_tac_5, temp_var_for_tac_6, temp_var_for_tac_7,
        temp_var_for_tac_8;
    float temp_var_for_const_9, temp_var_for_const_10, temp_var_for_const_11;
    temp_var_for_tac_5 = i + i;

    temp_var_for_tac_6 = ((float)temp_var_for_tac_5) / x;

    temp_var_for_tac_7 = temp_var_for_tac_6 * b;

    temp_var_for_tac_8 = temp_var_for_tac_7 - a;

    temp_var_for_ext_6 = temp_var_for_tac_8;
    computeAdd((Addr)&temp_var_for_tac_5, {(Addr) &(temp_var_for_const_10 = i),
                                           (Addr) &(temp_var_for_const_9 = i)},
               "/home/shijia/Public/testprogram/e_ynf.c_e.c:91:37");
    computeFDiv((Addr)&temp_var_for_tac_6,
                {(Addr) &(temp_var_for_const_11 = ((float)temp_var_for_tac_5)),
                 (Addr)&x},
                "/home/shijia/Public/testprogram/e_ynf.c_e.c:91:42");
    computeFMul((Addr)&temp_var_for_tac_7,
                {(Addr)&temp_var_for_tac_6, (Addr)&b},
                "/home/shijia/Public/testprogram/e_ynf.c_e.c:91:47");
    computeFSub((Addr)&temp_var_for_tac_8,
                {(Addr)&temp_var_for_tac_7, (Addr)&a},
                "/home/shijia/Public/testprogram/e_ynf.c_e.c:91:51");
    AssignF({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_8,
            "/home/shijia/Public/testprogram/e_ynf.c_e.c:91:24");
    ; // b
    /*(a)(b)(x)(i)(i)(TempNull)*/
    b = temp_var_for_ext_6;
    GET_FLOAT_WORD(ib, b);
    float temp_var_for_ext_7;
    temp_var_for_ext_7 = temp;
    AssignF({(Addr)&temp_var_for_ext_7}, (Addr)&temp,
            "/home/shijia/Public/testprogram/e_ynf.c_e.c:96:24");
    ; // a
    /*(a)(b)(x)(i)(i)(TempNull)(b)(x)(i)(i)(TempNull)(x)(i)(i)(TempNull)(temp)*/
    a = temp_var_for_ext_7;
    AssignF({(Addr)&a}, (Addr)&temp_var_for_ext_7,
            "/home/shijia/Public/testprogram/e_ynf.c_e.c:98:7");
    ;
  }
  if (sign > 0) {
    float temp_var_for_ext_8;
    temp_var_for_ext_8 = b;
    AssignF({(Addr)&temp_var_for_ext_8}, (Addr)&b,
            "/home/shijia/Public/testprogram/e_ynf.c_e.c:102:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_8;
  }

  float temp_var_for_ext_9;
  float temp_var_for_const_12;
  temp_var_for_ext_9 = (-(b));
  AssignF({(Addr)&temp_var_for_ext_9}, (Addr) &(temp_var_for_const_12 = (-(b))),
          "/home/shijia/Public/testprogram/e_ynf.c_e.c:109:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
  callExp++; /*identify the function is  add move tmpShadow*/
  return (double temp_var_for_tac_9;
          double temp_var_for_const_13, temp_var_for_const_14;
          temp_var_for_tac_9 = 0.0 - 9;

          );
}

/* wrapper yn */
float __ynf(int n, float x) {
  if ((islessequal(x, 0.0F) || isgreater(x, X_TLOSS)) &&
      _LIB_VERSION != _IEEE_) {
    if (int temp_var_for_tac_10; int temp_var_for_const_15;
        temp_var_for_tac_10 = x < 0.0F;

        ) {
      /* d = zero/(x-x) */
      feraiseexcept(FE_INVALID);
      float temp_var_for_ext_10;
      float temp_var_for_const_16;
      float temp_var_for_callexp_6;

      temp_var_for_callexp_5 = __builtin_huge_valf();
      temp_var_for_callexp_6 = __kernel_standard_f(
          n, x, (-(temp_var_for_callexp_5)), KMATHERRF_YN_MINUS);
      temp_var_for_ext_10 = temp_var_for_callexp_6;
      computeDSub((Addr)&temp_var_for_tac_9,
                  {(Addr) &(temp_var_for_const_14 = 0.0),
                   (Addr) &(temp_var_for_const_13 = 9)},
                  "/home/shijia/Public/testprogram/e_ynf.c_e.c:112:15");
      compute((Addr)&temp_var_for_tac_10,
              {(Addr)&x, (Addr) &(temp_var_for_const_15 = 0.0F)},
              "/home/shijia/Public/testprogram/e_ynf.c_e.c:119:11");
      AssignF({(Addr)&temp_var_for_ext_10},
              (Addr) &(temp_var_for_const_16 = temp_var_for_callexp_6),
              "/home/shijia/Public/testprogram/e_ynf.c_e.c:123:27");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_10", (Addr)&temp_var_for_ext_10));
      callExp++; /*identify the function is  add move tmpShad(0.0 - w*/
retur)n temp_var_for_ext_10;
    } else {
      if (int temp_var_for_tac_11; int temp_var_for_const_17;
          temp_var_for_tac_11 = x == 0.0F;

          )
      /* d = -one/(x-x) */
      {
        float temp_var_for_ext_11;
        float temp_var_for_const_18;
        float temp_var_for_callexp_8;

        temp_var_for_callexp_7 = __builtin_huge_valf();
        temp_var_for_callexp_8 = __kernel_standard_f(
            n, x, (-(temp_var_for_callexp_7)), KMATHERRF_YN_ZERO);
        temp_var_for_ext_11 = temp_var_for_callexp_8;
        compute((Addr)&temp_var_for_tac_11,
                {(Addr)&x, (Addr) &(temp_var_for_const_17 = 0.0F)},
                "/home/shijia/Public/testprogram/e_ynf.c_e.c:130:13");
        AssignF({(Addr)&temp_var_for_ext_11},
                (Addr) &(temp_var_for_const_18 = temp_var_for_callexp_8),
                "/home/shijia/Public/testprogram/e_ynf.c_e.c:134:29");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_11", (Addr)&temp_var_for_ext_11));
        callExp++; /*identify the function is  add move tmpShado(0.0 - */
return) temp_var_for_ext_11;
      }

      else {
        if (_LIB_VERSION != _POSIX_)
        /* yn(n,x>X_TLOSS) */
        {
          float temp_var_for_ext_12;
          float temp_var_for_const_19;
          float temp_var_for_callexp_9;

          temp_var_for_callexp_9 =
              __kernel_standard_f(n, x, 0.0f, KMATHERRF_YN_TLOSS);
          temp_var_for_ext_12 = temp_var_for_callexp_9;
          AssignF({(Addr)&temp_var_for_ext_12},
                  (Addr) &(temp_var_for_const_19 = temp_var_for_callexp_9),
                  "/home/shijia/Public/testprogram/e_ynf.c_e.c:147:31");
          ;
          callExpStack.push(
              getReal("temp_var_for_ext_12", (Addr)&temp_var_for_ext_12));
          callExp++; /*identify the function is  add move tmpShadow*/
          return temp_var_for_ext_12;
        }
      }
    }
  }

  float temp_var_for_ext_13;
  float temp_var_for_const_20;
  float temp_var_for_callexp_10;

  temp_var_for_callexp_10 = __ieee754_ynf(n, x);
  temp_var_for_ext_13 = temp_var_for_callexp_10;
  AssignF({(Addr)&temp_var_for_ext_13},
          (Addr) &(temp_var_for_const_20 = temp_var_for_callexp_10),
          "/home/shijia/Public/testprogram/e_ynf.c_e.c:159:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_13", (Addr)&temp_var_for_ext_13));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_13;
}

__typeof(__ynf) ynf __attribute__((weak, alias("__ynf")));
