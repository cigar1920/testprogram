#include "../ScDebug/scdebug.h"
/* e_jnf.c -- float version of e_jn.c.
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

float __ieee754_jnf(int n, float x) {
  int32_t i, hx, ix;
  int sgn;
  float a, b, temp, di;
  float z, w;

  static const float two = 2.0000000000e+00; /* 0x40000000 */
  static const float one = 1.0000000000e+00; /* 0x3F800000 */
  static const float zero = 0.0000000000e+00;

  /* J(-n,x) = (-1)^n * J(n, x), J(n, -x) = (-1)^n * J(n, x)
   * Thus, J(-n,x) = J(n,-x)
   */
  GET_FLOAT_WORD(hx, x);
  ix = IC(0x7fffffff) & hx;
  /* if J(n,NaN) is NaN */
  if (FLT_UWORD_IS_NAN(ix)) {
    float temp_var_for_ext_0;
    float temp_var_for_tac_0;
    temp_var_for_tac_0 = x + x;

    temp_var_for_ext_0 = temp_var_for_tac_0;
    computeFAdd((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_jnf.c_e.c:38:28");
    AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_0,
            "/home/shijia/Public/testprogram/e_jnf.c_e.c:38:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  if (n < 0) {
    n = -n;
    float temp_var_for_ext_1;
    float temp_var_for_tac_1;
    float temp_var_for_const_0;
    temp_var_for_tac_1 = 0.0 - x;

    temp_var_for_ext_1 = temp_var_for_tac_1;
    computeDSub((Addr)&temp_var_for_tac_1,
                {(Addr) &(temp_var_for_const_0 = 0.0), (Addr)&x},
                "/home/shijia/Public/testprogram/e_jnf.c_e.c:47:31");
    AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_1,
            "/home/shijia/Public/testprogram/e_jnf.c_e.c:47:24");
    ; // x
    /*(0)(t)(x)(x)*/
    x = temp_var_for_ext_1;
    AssignF({(Addr)&x}, (Addr)&temp_var_for_ext_1,
            "/home/shijia/Public/testprogram/e_jnf.c_e.c:49:7");
    ;
    hx ^= IC(0x80000000);
  }
  if (n == 0) {
    float temp_var_for_ext_2;
    float temp_var_for_const_1;
    float temp_var_for_callexp_0;

    temp_var_for_callexp_0 = __ieee754_j0f(x);
    temp_var_for_ext_2 = temp_var_for_callexp_0;
    AssignF({(Addr)&temp_var_for_ext_2},
            (Addr) &(temp_var_for_const_1 = temp_var_for_callexp_0),
            "/home/shijia/Public/testprogram/e_jnf.c_e.c:54:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  }

  if (n == 1) {
    float temp_var_for_ext_3;
    float temp_var_for_const_2;
    float temp_var_for_callexp_1;

    temp_var_for_callexp_1 = __ieee754_j1f(x);
    temp_var_for_ext_3 = temp_var_for_callexp_1;
    AssignF({(Addr)&temp_var_for_ext_3},
            (Addr) &(temp_var_for_const_2 = temp_var_for_callexp_1),
            "/home/shijia/Public/testprogram/e_jnf.c_e.c:62:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_3;
  }

  sgn = (int)((n & 1) & (hx >> 31)); /* even n -- 0, odd n -- sign(x) */
  float temp_var_for_ext_4;
  float temp_var_for_const_3;
  float temp_var_for_callexp_2;

  temp_var_for_callexp_2 = fabsf(x);
  temp_var_for_ext_4 = temp_var_for_callexp_2;
  AssignF({(Addr)&temp_var_for_ext_4},
          (Addr) &(temp_var_for_const_3 = temp_var_for_callexp_2),
          "/home/shijia/Public/testprogram/e_jnf.c_e.c:70:22");
  ; // x
  /*(__ieee754_fabsf(x))*/
  x = temp_var_for_ext_4;
  AssignF({(Addr)&x}, (Addr)&temp_var_for_ext_4,
          "/home/shijia/Public/testprogram/e_jnf.c_e.c:72:5");
  ;
  if (FLT_UWORD_IS_ZERO(ix) || FLT_UWORD_IS_INFINITE(ix)) {
    float temp_var_for_const_4;
    b = zero;
    AssignF({(Addr)&b}, (Addr) &(temp_var_for_const_4 = zero),
            "/home/shijia/Public/testprogram/e_jnf.c_e.c:74:7");
    ;
  }

  else {
    if (int temp_var_for_tac_2; int temp_var_for_const_5;
        temp_var_for_tac_2 = ((float)n) <= x;

        ) {
      /* Safe to use J(n+1,x)=2n/x *J(n,x)-J(n-1,x) */
      float temp_var_for_const_6;
      float temp_var_for_callexp_3;

      temp_var_for_callexp_3 = __ieee754_j0f(x);
      a = temp_var_for_callexp_3;
      compute((Addr)&temp_var_for_tac_2,
              {(Addr) &(temp_var_for_const_5 = ((float)n)), (Addr)&x},
              "/home/shijia/Public/testprogram/e_jnf.c_e.c:78:18");
      AssignF({(Addr)&a},
              (Addr) &(temp_var_for_const_6 = temp_var_for_callexp_3),
              "/home/shijia/Public/testprogram/e_jnf.c_e.c:80:9");
      ;
      float temp_var_for_const_7;
      float temp_var_for_callexp_4;

      temp_var_for_callexp_4 = __ieee754_j1f(x);
      b = temp_var_for_callexp_4;
      AssignF({(Addr)&b},
              (Addr) &(temp_var_for_const_7 = temp_var_for_callexp_4),
              "/home/shijia/Public/testprogram/e_jnf.c_e.c:81:9");
      ;
      for (i = 1; i < n; i++) {
        temp = b;
        AssignF({(Addr)&temp}, (Addr)&b,
                "/home/shijia/Public/testprogram/e_jnf.c_e.c:83:14");
        ;
        float temp_var_for_ext_5;
        float temp_var_for_tac_3, temp_var_for_tac_4, temp_var_for_tac_5,
            temp_var_for_tac_6;
        float temp_var_for_const_8, temp_var_for_const_9, temp_var_for_const_10;
        temp_var_for_tac_3 = i + i;

        temp_var_for_tac_4 = ((float)temp_var_for_tac_3) / x;

        temp_var_for_tac_5 = b * temp_var_for_tac_4;

        temp_var_for_tac_6 = temp_var_for_tac_5 - a;

        temp_var_for_ext_5 = temp_var_for_tac_6;
        computeAdd((Addr)&temp_var_for_tac_3,
                   {(Addr) &(temp_var_for_const_9 = i),
                    (Addr) &(temp_var_for_const_8 = i)},
                   "/home/shijia/Public/testprogram/e_jnf.c_e.c:85:45");
        computeFDiv(
            (Addr)&temp_var_for_tac_4,
            {(Addr) &(temp_var_for_const_10 = ((float)temp_var_for_tac_3)),
             (Addr)&x},
            "/home/shijia/Public/testprogram/e_jnf.c_e.c:85:50");
        computeFMul((Addr)&temp_var_for_tac_5,
                    {(Addr)&b, (Addr)&temp_var_for_tac_4},
                    "/home/shijia/Public/testprogram/e_jnf.c_e.c:85:32");
        computeFSub((Addr)&temp_var_for_tac_6,
                    {(Addr)&temp_var_for_tac_5, (Addr)&a},
                    "/home/shijia/Public/testprogram/e_jnf.c_e.c:85:55");
        AssignF({(Addr)&temp_var_for_ext_5}, (Addr)&temp_var_for_tac_6,
                "/home/shijia/Public/testprogram/e_jnf.c_e.c:85:28");
        ; // b
        /*(a)(x)(i)(i)(TempNull)(b)*/
        b = temp_var_for_ext_5; /* avoid underflow */
        float temp_var_for_ext_6;
        temp_var_for_ext_6 = temp;
        AssignF({(Addr)&temp_var_for_ext_6}, (Addr)&temp,
                "/home/shijia/Public/testprogram/e_jnf.c_e.c:89:28");
        ; // a
        /*(a)(x)(i)(i)(TempNull)(b)(x)(i)(i)(TempNull)(b)(x)(i)(i)(TempNull)(temp)*/
        a = temp_var_for_ext_6;
        AssignF({(Addr)&a}, (Addr)&temp_var_for_ext_6,
                "/home/shijia/Public/testprogram/e_jnf.c_e.c:91:11");
        ;
      }
    } else {
      if (ix < IC(0x30800000)) { /* x < 2**-29 */
        /* x is tiny, return the first Taylor expansion of J(n,x)
         * J(n,x) = 1/n!*(x/2)^n  - ...
         */
        if (n > 33) /* underflow */
        {
          float temp_var_for_const_11;
          b = zero;
          AssignF({(Addr)&b}, (Addr) &(temp_var_for_const_11 = zero),
                  "/home/shijia/Public/testprogram/e_jnf.c_e.c:100:13");
          ;
        }

        else {
          float temp_var_for_tac_7;
          float temp_var_for_const_12;
          temp_var_for_tac_7 = x * 0.5f;

          temp = temp_var_for_tac_7;
          computeFMul((Addr)&temp_var_for_tac_7,
                      {(Addr)&x, (Addr) &(temp_var_for_const_12 = 0.5f)},
                      "/home/shijia/Public/testprogram/e_jnf.c_e.c:104:20");
          AssignF({(Addr)&temp}, (Addr)&temp_var_for_tac_7,
                  "/home/shijia/Public/testprogram/e_jnf.c_e.c:104:16");
          ;
          b = temp;
          AssignF({(Addr)&b}, (Addr)&temp,
                  "/home/shijia/Public/testprogram/e_jnf.c_e.c:105:13");
          ;
          for (a = one, i = 2; i <= n; i++) {
            a *= ((float)i);
            ; /* a = n! */
            b *= temp;
            ; /* b = (x/2)^n */
          }
          float temp_var_for_ext_7;
          float temp_var_for_tac_10;
          temp_var_for_tac_10 = b / a;

          temp_var_for_ext_7 = temp_var_for_tac_10;
          computeFDiv((Addr)&temp_var_for_tac_10, {(Addr)&b, (Addr)&a},
                      "/home/shijia/Public/testprogram/e_jnf.c_e.c:111:34");
          AssignF({(Addr)&temp_var_for_ext_7}, (Addr)&temp_var_for_tac_10,
                  "/home/shijia/Public/testprogram/e_jnf.c_e.c:111:30");
          ; // b
          /*(i)(i)(a)(temp)(b)(a)(b)*/
          b = temp_var_for_ext_7;
          AssignF({(Addr)&b}, (Addr)&temp_var_for_ext_7,
                  "/home/shijia/Public/testprogram/e_jnf.c_e.c:113:13");
          ;
        }
      } else {
        /* use backward recurrence */
        /*          x      x^2      x^2
         *  J(n,x)/J(n-1,x) =  ----   ------   ------   .....
         *          2n  - 2(n+1) - 2(n+2)
         *
         *          1      1        1
         *  (for large x)   =  ----  ------   ------   .....
         *          2n   2(n+1)   2(n+2)
         *          -- - ------ - ------ -
         *           x     x         x
         *
         * Let w = 2n/x and h=2/x, then the above quotient
         * is equal to the continued fraction:
         *          1
         *  = -----------------------
         *             1
         *     w - -----------------
         *            1
         *          w+h - ---------
         *             w+2h - ...
         *
         * To determine how many terms needed, let
         * Q(0) = w, Q(1) = w(w+h) - 1,
         * Q(k) = (w+k*h)*Q(k-1) - Q(k-2),
         * When Q(k) > 1e4  good for single
         * When Q(k) > 1e9  good for double
         * When Q(k) > 1e17 good for quadruple
         */
        /* determine k */
        float t, v;
        float q0, q1, h, tmp;
        int32_t k, m;

        float temp_var_for_tac_11, temp_var_for_tac_12;
        float temp_var_for_const_13, temp_var_for_const_14,
            temp_var_for_const_15;
        temp_var_for_tac_11 = n + n;

        temp_var_for_tac_12 = temp_var_for_tac_11 / ((float)x);

        w = temp_var_for_tac_12;
        computeAdd((Addr)&temp_var_for_tac_11,
                   {(Addr) &(temp_var_for_const_14 = n),
                    (Addr) &(temp_var_for_const_13 = n)},
                   "/home/shijia/Public/testprogram/e_jnf.c_e.c:149:16");
        computeFDiv((Addr)&temp_var_for_tac_12,
                    {(Addr)&temp_var_for_tac_11,
                     (Addr) &(temp_var_for_const_15 = ((float)x))},
                    "/home/shijia/Public/testprogram/e_jnf.c_e.c:149:21");
        AssignF({(Addr)&w}, (Addr)&temp_var_for_tac_12,
                "/home/shijia/Public/testprogram/e_jnf.c_e.c:149:11");
        ;
        h = float temp_var_for_tac_13;
        float temp_var_for_const_16;
        temp_var_for_tac_13 = 2.0f / x;

        ;
        q0 = w;
        computeFDiv((Addr)&temp_var_for_tac_13,
                    {(Addr) &(temp_var_for_const_16 = 2.0f), (Addr)&x},
                    "/home/shijia/Public/testprogram/e_jnf.c_e.c:150:18");
        AssignF({(Addr)&q0}, (Addr)&w,
                "/home/shijia/Public/testprogram/e_jnf.c_e.c:151:12");
        ;
        float temp_var_for_tac_14;
        temp_var_for_tac_14 = w + h;

        z = temp_var_for_tac_14;
        computeFAdd((Addr)&temp_var_for_tac_14, {(Addr)&w, (Addr)&h},
                    "/home/shijia/Public/testprogram/e_jnf.c_e.c:152:15");
        AssignF({(Addr)&z}, (Addr)&temp_var_for_tac_14,
                "/home/shijia/Public/testprogram/e_jnf.c_e.c:152:11");
        ;
        float temp_var_for_tac_15, temp_var_for_tac_16;
        float temp_var_for_const_17;
        temp_var_for_tac_15 = w * z;

        temp_var_for_tac_16 = temp_var_for_tac_15 - 1.0f;

        q1 = temp_var_for_tac_16;
        computeFMul((Addr)&temp_var_for_tac_15, {(Addr)&w, (Addr)&z},
                    "/home/shijia/Public/testprogram/e_jnf.c_e.c:153:16");
        computeFSub((Addr)&temp_var_for_tac_16,
                    {(Addr)&temp_var_for_tac_15,
                     (Addr) &(temp_var_for_const_17 = 1.0f)},
                    "/home/shijia/Public/testprogram/e_jnf.c_e.c:153:20");
        AssignF({(Addr)&q1}, (Addr)&temp_var_for_tac_16,
                "/home/shijia/Public/testprogram/e_jnf.c_e.c:153:12");
        ;
        k = 1;
        int temp_var_for_ext_8;
        temp_var_for_ext_8 = int temp_var_for_tac_17;
        int temp_var_for_const_18;
        temp_var_for_tac_17 = q1 < 1.0e9f;

        ;
        while (temp_var_for_ext_8) {
          k += 1;
          z += h;
          ;
          float temp_var_for_tac_19, temp_var_for_tac_20;
          temp_var_for_tac_19 = z * q1;

          temp_var_for_tac_20 = temp_var_for_tac_19 - q0;

          tmp = temp_var_for_tac_20;
          compute((Addr)&temp_var_for_tac_17,
                  {(Addr)&q1, (Addr) &(temp_var_for_const_18 = 1.0e9f)},
                  "/home/shijia/Public/testprogram/e_jnf.c_e.c:156:33");
          computeFMul((Addr)&temp_var_for_tac_19, {(Addr)&z, (Addr)&q1},
                      "/home/shijia/Public/testprogram/e_jnf.c_e.c:160:19");
          computeFSub((Addr)&temp_var_for_tac_20,
                      {(Addr)&temp_var_for_tac_19, (Addr)&q0},
                      "/home/shijia/Public/testprogram/e_jnf.c_e.c:160:24");
          AssignF({(Addr)&tmp}, (Addr)&temp_var_for_tac_20,
                  "/home/shijia/Public/testprogram/e_jnf.c_e.c:160:15");
          ;
          float temp_var_for_ext_9;
          temp_var_for_ext_9 = q1;
          AssignF({(Addr)&temp_var_for_ext_9}, (Addr)&q1,
                  "/home/shijia/Public/testprogram/e_jnf.c_e.c:162:30");
          ; // q0
          /*(q0)(q1)(z)(q1)(z)(q1)*/
          q0 = temp_var_for_ext_9;
          AssignF({(Addr)&q0}, (Addr)&temp_var_for_ext_9,
                  "/home/shijia/Public/testprogram/e_jnf.c_e.c:164:14");
          ;
          q1 = tmp;
          AssignF({(Addr)&q1}, (Addr)&tmp,
                  "/home/shijia/Public/testprogram/e_jnf.c_e.c:165:14");
          ;
          temp_var_for_ext_8 = int temp_var_for_tac_21;
          int temp_var_for_const_19;
          temp_var_for_tac_21 = q1 < 1.0e9f;

          ;
        }
        m = n + n;
        for (t = zero, i = 2 * (n + k); i >= m; i -= 2) {
          float temp_var_for_ext_10;
          float temp_var_for_tac_22, temp_var_for_tac_23, temp_var_for_tac_24;
          float temp_var_for_const_20, temp_var_for_const_21;
          temp_var_for_tac_22 = i / x;

          temp_var_for_tac_23 = temp_var_for_tac_22 - t;

          temp_var_for_tac_24 = one / temp_var_for_tac_23;

          temp_var_for_ext_10 = temp_var_for_tac_24;
          compute((Addr)&temp_var_for_tac_21,
                  {(Addr)&q1, (Addr) &(temp_var_for_const_19 = 1.0e9f)},
                  "/home/shijia/Public/testprogram/e_jnf.c_e.c:166:35");
          computeFDiv((Addr)&temp_var_for_tac_22,
                      {(Addr) &(temp_var_for_const_20 = i), (Addr)&x},
                      "/home/shijia/Public/testprogram/e_jnf.c_e.c:171:42");
          computeFSub((Addr)&temp_var_for_tac_23,
                      {(Addr)&temp_var_for_tac_22, (Addr)&t},
                      "/home/shijia/Public/testprogram/e_jnf.c_e.c:171:46");
          computeFDiv((Addr)&temp_var_for_tac_24,
                      {(Addr) &(temp_var_for_const_21 = one),
                       (Addr)&temp_var_for_tac_23},
                      "/home/shijia/Public/testprogram/e_jnf.c_e.c:171:37");
          AssignF({(Addr)&temp_var_for_ext_10}, (Addr)&temp_var_for_tac_24,
                  "/home/shijia/Public/testprogram/e_jnf.c_e.c:171:31");
          ; // t
          /*(t)(x)(i)(one)*/
          t = temp_var_for_ext_10;
          AssignF({(Addr)&t}, (Addr)&temp_var_for_ext_10,
                  "/home/shijia/Public/testprogram/e_jnf.c_e.c:173:13");
          ;
        }

        a = t;
        AssignF({(Addr)&a}, (Addr)&t,
                "/home/shijia/Public/testprogram/e_jnf.c_e.c:176:11");
        ;
        float temp_var_for_const_22;
        b = one;
        AssignF({(Addr)&b}, (Addr) &(temp_var_for_const_22 = one),
                "/home/shijia/Public/testprogram/e_jnf.c_e.c:177:11");
        ;
        /*  estimate log((2/x)^n*n!) = n*log(2/x)+n*ln(n)
         *  Hence, if n*(log(2n/x)) > ...
         *  single 8.8722839355e+01
         *  double 7.09782712893383973096e+02
         *  long double 1.1356523406294143949491931077970765006170e+04
         *  then recurrent value may overflow and the result is
         *  likely underflow to zero
         */
        float temp_var_for_const_23;
        tmp = n;
        AssignF({(Addr)&tmp}, (Addr) &(temp_var_for_const_23 = n),
                "/home/shijia/Public/testprogram/e_jnf.c_e.c:186:13");
        ;
        float temp_var_for_tac_25;
        float temp_var_for_const_24;
        temp_var_for_tac_25 = two / x;

        v = temp_var_for_tac_25;
        computeFDiv((Addr)&temp_var_for_tac_25,
                    {(Addr) &(temp_var_for_const_24 = two), (Addr)&x},
                    "/home/shijia/Public/testprogram/e_jnf.c_e.c:187:17");
        AssignF({(Addr)&v}, (Addr)&temp_var_for_tac_25,
                "/home/shijia/Public/testprogram/e_jnf.c_e.c:187:11");
        ;
        float temp_var_for_ext_11;
        float temp_var_for_tac_26, temp_var_for_tac_27;
        float temp_var_for_const_25;
        float temp_var_for_callexp_5;

        /*embed fun has found*/
        float temp_var_for_callexp_6;

        temp_var_for_tac_26 = v * tmp;

        temp_var_for_callexp_5 = fabsf(temp_var_for_tac_26);
        temp_var_for_callexp_6 = __ieee754_logf(temp_var_for_callexp_5);
        temp_var_for_tac_27 = tmp * temp_var_for_callexp_6;

        temp_var_for_ext_11 = temp_var_for_tac_27;
        computeFMul((Addr)&temp_var_for_tac_26, {(Addr)&v, (Addr)&tmp},
                    "/home/shijia/Public/testprogram/e_jnf.c_e.c:190:34 "
                    "<Spelling=/home/shijia/Public/testprogram/"
                    "e_jnf.c_e.c:190:52>");
        computeFMul((Addr)&temp_var_for_tac_27,
                    {(Addr)&tmp,
                     (Addr) &(temp_var_for_const_25 = temp_var_for_callexp_6)},
                    "/home/shijia/Public/testprogram/e_jnf.c_e.c:190:17");
        AssignF({(Addr)&temp_var_for_ext_11}, (Addr)&temp_var_for_tac_27,
                "/home/shijia/Public/testprogram/e_jnf.c_e.c:189:29");
        ; // tmp
        /*(x)(two)(__ieee754_logf(__ieee754_fabsf(v * tmp)))(tmp)*/
        tmp = temp_var_for_ext_11;
        AssignF({(Addr)&tmp}, (Addr)&temp_var_for_ext_11,
                "/home/shijia/Public/testprogram/e_jnf.c_e.c:192:13");
        ;
        if (int temp_var_for_tac_28; int temp_var_for_const_26;
            temp_var_for_tac_28 = tmp < 8.8721679688e+01f;

            ) {
          for (i = n - 1, di = (float)(i + i); i > 0; i--) {
            temp = b;
            compute((Addr)&temp_var_for_tac_28,
                    {(Addr)&tmp,
                     (Addr) &(temp_var_for_const_26 = 8.8721679688e+01f)},
                    "/home/shijia/Public/testprogram/e_jnf.c_e.c:193:17");
            AssignF({(Addr)&temp}, (Addr)&b,
                    "/home/shijia/Public/testprogram/e_jnf.c_e.c:195:18");
            ;
            b *= di;
            ;
            float temp_var_for_ext_12;
            float temp_var_for_tac_30, temp_var_for_tac_31;
            temp_var_for_tac_30 = b / x;

            temp_var_for_tac_31 = temp_var_for_tac_30 - a;

            temp_var_for_ext_12 = temp_var_for_tac_31;
            computeFDiv((Addr)&temp_var_for_tac_30, {(Addr)&b, (Addr)&x},
                        "/home/shijia/Public/testprogram/e_jnf.c_e.c:198:37");
            computeFSub((Addr)&temp_var_for_tac_31,
                        {(Addr)&temp_var_for_tac_30, (Addr)&a},
                        "/home/shijia/Public/testprogram/e_jnf.c_e.c:198:41");
            AssignF({(Addr)&temp_var_for_ext_12}, (Addr)&temp_var_for_tac_31,
                    "/home/shijia/Public/testprogram/e_jnf.c_e.c:198:33");
            ; // b
            /*(di)(b)(a)(x)(b)*/
            b = temp_var_for_ext_12;
            AssignF({(Addr)&b}, (Addr)&temp_var_for_ext_12,
                    "/home/shijia/Public/testprogram/e_jnf.c_e.c:200:15");
            ;
            float temp_var_for_ext_13;
            temp_var_for_ext_13 = temp;
            AssignF({(Addr)&temp_var_for_ext_13}, (Addr)&temp,
                    "/home/shijia/Public/testprogram/e_jnf.c_e.c:202:33");
            ; // a
            /*(a)(x)(b)(x)(b)(temp)*/
            a = temp_var_for_ext_13;
            AssignF({(Addr)&a}, (Addr)&temp_var_for_ext_13,
                    "/home/shijia/Public/testprogram/e_jnf.c_e.c:204:15");
            ;
            di -= two;
            ;
          }
        } else {
          for (i = n - 1, float temp_var_for_ext_14;
               temp_var_for_ext_14 = (float)(i + i); // di
               /*(two)(di)(i)(i)(TempNull)*/
               di = temp_var_for_ext_14;
               i > 0; i--) {
            temp = b;
            b *= di;
            float temp_var_for_ext_15;
            temp_var_for_ext_15 = b / x - a; // b
            /*(di)(b)(a)(x)(b)*/
            b = temp_var_for_ext_15;
            float temp_var_for_ext_16;
            temp_var_for_ext_16 = temp; // a
            /*(a)(x)(b)(x)(b)(temp)*/
            a = temp_var_for_ext_16;
            di -= two;
            /* scale b to avoid spurious overflow */
            if (b > 1e10f) {
              a /= b;
              t /= b;
              float temp_var_for_ext_17;
              temp_var_for_ext_17 = one; // b
              /*(two)(di)(b)(a)(b)(t)(one)*/
              b = temp_var_for_ext_17;
            }
          }
        }
        /* j0() and j1() suffer enormous loss of precision at and
         * near zero; however, we know that their zero points never
         * coincide, so just choose the one further away from zero.
         */
        float temp_var_for_const_27;
        float temp_var_for_callexp_7;

        temp_var_for_callexp_7 = __ieee754_j0f(x);
        z = temp_var_for_callexp_7;
        AssignF({(Addr)&z},
                (Addr) &(temp_var_for_const_27 = temp_var_for_callexp_7),
                "/home/shijia/Public/testprogram/e_jnf.c_e.c:239:11");
        ;
        float temp_var_for_const_28;
        float temp_var_for_callexp_8;

        temp_var_for_callexp_8 = __ieee754_j1f(x);
        w = temp_var_for_callexp_8;
        AssignF({(Addr)&w},
                (Addr) &(temp_var_for_const_28 = temp_var_for_callexp_8),
                "/home/shijia/Public/testprogram/e_jnf.c_e.c:240:11");
        ;
        if (int temp_var_for_tac_33;
            int temp_var_for_const_29, temp_var_for_const_30;
            float temp_var_for_callexp_9;

            float temp_var_for_callexp_10;

            temp_var_for_callexp_9 = fabsf(z);
            temp_var_for_callexp_10 = fabsf(w);
            temp_var_for_tac_33 =
                temp_var_for_callexp_9 >= temp_var_for_callexp_10;

            ) {
          float temp_var_for_ext_18;
          float temp_var_for_tac_34, temp_var_for_tac_35;
          temp_var_for_tac_34 = t * z;

          temp_var_for_tac_35 = temp_var_for_tac_34 / b;

          temp_var_for_ext_18 = temp_var_for_tac_35;
          compute((Addr)&temp_var_for_tac_33,
                  {(Addr) &(temp_var_for_const_30 = temp_var_for_callexp_9),
                   (Addr) &(temp_var_for_const_29 = temp_var_for_callexp_10)},
                  "/home/shijia/Public/testprogram/e_jnf.c_e.c:241:32");
          computeFMul((Addr)&temp_var_for_tac_34, {(Addr)&t, (Addr)&z},
                      "/home/shijia/Public/testprogram/e_jnf.c_e.c:243:36");
          computeFDiv((Addr)&temp_var_for_tac_35,
                      {(Addr)&temp_var_for_tac_34, (Addr)&b},
                      "/home/shijia/Public/testprogram/e_jnf.c_e.c:243:40");
          AssignF({(Addr)&temp_var_for_ext_18}, (Addr)&temp_var_for_tac_35,
                  "/home/shijia/Public/testprogram/e_jnf.c_e.c:243:31");
          ; // b
          /*(b)(z)(t)*/
          b = temp_var_for_ext_18;
          AssignF({(Addr)&b}, (Addr)&temp_var_for_ext_18,
                  "/home/shijia/Public/testprogram/e_jnf.c_e.c:245:13");
          ;
        }

        else {
          float temp_var_for_ext_19;
          float temp_var_for_tac_36, temp_var_for_tac_37;
          temp_var_for_tac_36 = t * w;

          temp_var_for_tac_37 = temp_var_for_tac_36 / a;

          temp_var_for_ext_19 = temp_var_for_tac_37;
          computeFMul((Addr)&temp_var_for_tac_36, {(Addr)&t, (Addr)&w},
                      "/home/shijia/Public/testprogram/e_jnf.c_e.c:250:36");
          computeFDiv((Addr)&temp_var_for_tac_37,
                      {(Addr)&temp_var_for_tac_36, (Addr)&a},
                      "/home/shijia/Public/testprogram/e_jnf.c_e.c:250:40");
          AssignF({(Addr)&temp_var_for_ext_19}, (Addr)&temp_var_for_tac_37,
                  "/home/shijia/Public/testprogram/e_jnf.c_e.c:250:31");
          ; // b
          /*(b)(z)(t)(z)(t)(a)(w)(t)*/
          b = temp_var_for_ext_19;
          AssignF({(Addr)&b}, (Addr)&temp_var_for_ext_19,
                  "/home/shijia/Public/testprogram/e_jnf.c_e.c:252:13");
          ;
        }
      }
    }
  }

  if (sgn) {
    float temp_var_for_ext_20;
    float temp_var_for_const_31;
    temp_var_for_ext_20 = (-(b));
    AssignF({(Addr)&temp_var_for_ext_20},
            (Addr) &(temp_var_for_const_31 = (-(b))),
            "/home/shijia/Public/testprogram/e_jnf.c_e.c:260:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_20", (Addr)&temp_var_for_ext_20));
    callExp++; /*identify the function is  add move tmpShadow*/
    return (double temp_var_for_tac_38;
            double temp_var_for_const_32, temp_var_for_const_33;
            temp_var_for_tac_38 = 0.0 - 0;

            );
  }

  float temp_var_for_ext_21;
  temp_var_for_ext_21 = b;
  computeDSub((Addr)&temp_var_for_tac_38,
              {(Addr) &(temp_var_for_const_33 = 0.0),
               (Addr) &(temp_var_for_const_32 = 0)},
              "/home/shijia/Public/testprogram/e_jnf.c_e.c:264:17");
  AssignF({(Addr)&temp_var_for_ext_21}, (Addr)&b,
          "/home/shijia/Public/testprogram/e_jnf.c_e.c:268:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_21", (Addr)&temp_var_for_ext_21));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_21;
}

/* wrapper jn */
float __jnf(int n, float x) {
  if (isgreater(__ieee754_fabsf(x), X_TLOSS) && _LIB_VERSION != _IEEE_ &&
      _LIB_VERSION != _POSIX_)
  /* jn(n,|x|>X_TLOSS) */
  {
    float temp_var_for_ext_22;
    float temp_var_for_const_34;
    float temp_var_for_callexp_11;

    temp_var_for_callexp_11 =
        __kernel_standard_f(n, x, 0.0f, KMATHERRF_JN_TLOSS);
    temp_var_for_ext_22 = temp_var_for_callexp_11;
    AssignF({(Addr)&temp_var_for_ext_22},
            (Addr) &(temp_var_for_const_34 = temp_var_for_callexp_11),
            "/home/shijia/Public/testprogram/e_jnf.c_e.c:281:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_22", (Addr)&temp_var_for_ext_22));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_22;
  }

  float temp_var_for_ext_23;
  float temp_var_for_const_35;
  float temp_var_for_callexp_12;

  temp_var_for_callexp_12 = __ieee754_jnf(n, x);
  temp_var_for_ext_23 = temp_var_for_callexp_12;
  AssignF({(Addr)&temp_var_for_ext_23},
          (Addr) &(temp_var_for_const_35 = temp_var_for_callexp_12),
          "/home/shijia/Public/testprogram/e_jnf.c_e.c:289:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_23", (Addr)&temp_var_for_ext_23));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_23;
}

__typeof(__jnf) jnf __attribute__((weak, alias("__jnf")));
