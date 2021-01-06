#include "../ScDebug/scdebug.h"
/* @(#)e_jn.c 1.4 95/01/18 */
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

/*
 * __ieee754_jn(n, x)
 * floating point Bessel's function of the 1st and 2nd kind
 * of order n
 *
 * Special cases:
 *	y0(0)=y1(0)=yn(n,0) = -inf with overflow signal;
 *	y0(-ve)=y1(-ve)=yn(n,-ve) are NaN with invalid signal.
 * Note 2. About jn(n,x), yn(n,x)
 *	For n=0, j0(x) is called,
 *	for n=1, j1(x) is called,
 *	for n<x, forward recursion us used starting
 *	from values of j0(x) and j1(x).
 *	for n>x, a continued fraction approximation to
 *	j(n,x)/j(n-1,x) is evaluated and then backward
 *	recursion is used starting from a supposed value
 *	for j(n,x). The resulting value of j(0,x) is
 *	compared with the actual value to correct the
 *	supposed value of j(n,x).
 *
 *	yn(n,x) is similar in all respects, except
 *	that forward recursion is used for all
 *	values of n>1.
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

double __ieee754_jn(int n, double x) {
  int32_t i, hx, ix, lx;
  int sgn;
  double a, b, temp, di;
  double z, w;

  static const double invsqrtpi =
      5.64189583547756279280e-01; /* 0x3FE20DD7, 0x50429B6D */
  static const double two =
      2.00000000000000000000e+00; /* 0x40000000, 0x00000000 */
  static const double one =
      1.00000000000000000000e+00; /* 0x3FF00000, 0x00000000 */
  static const double zero = 0.00000000000000000000e+00;

  /* J(-n,x) = (-1)^n * J(n, x), J(n, -x) = (-1)^n * J(n, x)
   * Thus, J(-n,x) = J(n,-x)
   */
  GET_DOUBLE_WORDS(hx, lx, x);
  ix = IC(0x7fffffff) & hx;
  /* if J(n,NaN) is NaN */
  if ((ix | (((uint32_t)(lx | -lx)) >> 31)) > IC(0x7ff00000)) {
    double temp_var_for_ext_0;
    double temp_var_for_tac_0;
    temp_var_for_tac_0 = x + x;

    temp_var_for_ext_0 = temp_var_for_tac_0;
    computeDAdd((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_jn.c_e.c:64:28");
    AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_0,
            "/home/shijia/Public/testprogram/e_jn.c_e.c:64:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  if (n < 0) {
    n = -n;
    double temp_var_for_ext_1;
    double temp_var_for_tac_1;
    double temp_var_for_const_0;
    temp_var_for_tac_1 = 0.0 - x;

    temp_var_for_ext_1 = temp_var_for_tac_1;
    computeDSub((Addr)&temp_var_for_tac_1,
                {(Addr) &(temp_var_for_const_0 = 0.0), (Addr)&x},
                "/home/shijia/Public/testprogram/e_jn.c_e.c:73:31");
    AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_1,
            "/home/shijia/Public/testprogram/e_jn.c_e.c:73:24");
    ; // x
    /*(0)(t)(x)(x)*/
    x = temp_var_for_ext_1;
    AssignD({(Addr)&x}, (Addr)&temp_var_for_ext_1,
            "/home/shijia/Public/testprogram/e_jn.c_e.c:75:7");
    ;
    hx ^= IC(0x80000000);
  }
  if (n == 0) {
    double temp_var_for_ext_2;
    double temp_var_for_const_1;
    double temp_var_for_callexp_0;

    temp_var_for_callexp_0 = __ieee754_j0(x);
    temp_var_for_ext_2 = temp_var_for_callexp_0;
    AssignD({(Addr)&temp_var_for_ext_2},
            (Addr) &(temp_var_for_const_1 = temp_var_for_callexp_0),
            "/home/shijia/Public/testprogram/e_jn.c_e.c:80:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  }

  if (n == 1) {
    double temp_var_for_ext_3;
    double temp_var_for_const_2;
    double temp_var_for_callexp_1;

    temp_var_for_callexp_1 = __ieee754_j1(x);
    temp_var_for_ext_3 = temp_var_for_callexp_1;
    AssignD({(Addr)&temp_var_for_ext_3},
            (Addr) &(temp_var_for_const_2 = temp_var_for_callexp_1),
            "/home/shijia/Public/testprogram/e_jn.c_e.c:88:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_3;
  }

  sgn = (int)((n & 1) & (hx >> 31)); /* even n -- 0, odd n -- sign(x) */
  double temp_var_for_ext_4;
  double temp_var_for_const_3;
  double temp_var_for_callexp_2;

  temp_var_for_callexp_2 = fabs(x);
  temp_var_for_ext_4 = temp_var_for_callexp_2;
  AssignD({(Addr)&temp_var_for_ext_4},
          (Addr) &(temp_var_for_const_3 = temp_var_for_callexp_2),
          "/home/shijia/Public/testprogram/e_jn.c_e.c:96:22");
  ; // x
  /*(__ieee754_fabs(x))*/
  x = temp_var_for_ext_4;
  AssignD({(Addr)&x}, (Addr)&temp_var_for_ext_4,
          "/home/shijia/Public/testprogram/e_jn.c_e.c:98:5");
  ;
  if ((ix | lx) == 0 || ix >= IC(0x7ff00000)) /* if x is 0 or inf */
  {
    double temp_var_for_const_4;
    b = zero;
    AssignD({(Addr)&b}, (Addr) &(temp_var_for_const_4 = zero),
            "/home/shijia/Public/testprogram/e_jn.c_e.c:101:7");
    ;
  }

  else {
    if (int temp_var_for_tac_2; int temp_var_for_const_5;
        temp_var_for_tac_2 = ((double)n) <= x;

        ) {
      /* Safe to use J(n+1,x)=2n/x *J(n,x)-J(n-1,x) */
      if (ix >= IC(0x52D00000)) { /* x > 2**302 */
                                  /* (x >> n**2)
                                   *      Jn(x) = cos(x-(2n+1)*pi/4)*sqrt(2/x*pi)
                                   *      Yn(x) = sin(x-(2n+1)*pi/4)*sqrt(2/x*pi)
                                   *      Let s=sin(x), c=cos(x),
                                   *      xn=x-(2n+1)*pi/4, sqt2 = sqrt(2),then
                                   *
                                   *         n    sin(xn)*sqt2    cos(xn)*sqt2
                                   *      ----------------------------------
                                   *         0     s-c         c+s
                                   *         1    -s-c        -c+s
                                   *         2    -s+c        -c-s
                                   *         3     s+c         c-s
                                   */
        double s;
        double c;

        __ieee754_sincos(x, &s, &c);
        int temp_var_for_ext_5;
        temp_var_for_ext_5 = n & 3;
        switch (temp_var_for_ext_5) {
        case 0: {
          double temp_var_for_tac_3;
          temp_var_for_tac_3 = c + s;

          temp = temp_var_for_tac_3;
          compute((Addr)&temp_var_for_tac_2,
                  {(Addr) &(temp_var_for_const_5 = ((double)n)), (Addr)&x},
                  "/home/shijia/Public/testprogram/e_jn.c_e.c:105:19");
          computeDAdd((Addr)&temp_var_for_tac_3, {(Addr)&c, (Addr)&s},
                      "/home/shijia/Public/testprogram/e_jn.c_e.c:129:20");
          AssignD({(Addr)&temp}, (Addr)&temp_var_for_tac_3,
                  "/home/shijia/Public/testprogram/e_jn.c_e.c:129:16");
          ;
        }

        break;
        case 1: {
          double temp_var_for_tac_4, temp_var_for_tac_5;
          double temp_var_for_const_6;
          temp_var_for_tac_4 = 0.0 - c;

          temp_var_for_tac_5 = temp_var_for_tac_4 + s;

          temp = temp_var_for_tac_5;
          computeDSub((Addr)&temp_var_for_tac_4,
                      {(Addr) &(temp_var_for_const_6 = 0.0), (Addr)&c},
                      "/home/shijia/Public/testprogram/e_jn.c_e.c:134:23");
          computeDAdd((Addr)&temp_var_for_tac_5,
                      {(Addr)&temp_var_for_tac_4, (Addr)&s},
                      "/home/shijia/Public/testprogram/e_jn.c_e.c:134:28");
          AssignD({(Addr)&temp}, (Addr)&temp_var_for_tac_5,
                  "/home/shijia/Public/testprogram/e_jn.c_e.c:134:16");
          ;
        }

        break;
        case 2: {
          double temp_var_for_tac_6, temp_var_for_tac_7;
          double temp_var_for_const_7;
          temp_var_for_tac_6 = 0.0 - c;

          temp_var_for_tac_7 = temp_var_for_tac_6 - s;

          temp = temp_var_for_tac_7;
          computeDSub((Addr)&temp_var_for_tac_6,
                      {(Addr) &(temp_var_for_const_7 = 0.0), (Addr)&c},
                      "/home/shijia/Public/testprogram/e_jn.c_e.c:139:23");
          computeDSub((Addr)&temp_var_for_tac_7,
                      {(Addr)&temp_var_for_tac_6, (Addr)&s},
                      "/home/shijia/Public/testprogram/e_jn.c_e.c:139:28");
          AssignD({(Addr)&temp}, (Addr)&temp_var_for_tac_7,
                  "/home/shijia/Public/testprogram/e_jn.c_e.c:139:16");
          ;
        }

        break;
        case 3: {
          double temp_var_for_tac_8;
          temp_var_for_tac_8 = c - s;

          temp = temp_var_for_tac_8;
          computeDSub((Addr)&temp_var_for_tac_8, {(Addr)&c, (Addr)&s},
                      "/home/shijia/Public/testprogram/e_jn.c_e.c:144:20");
          AssignD({(Addr)&temp}, (Addr)&temp_var_for_tac_8,
                  "/home/shijia/Public/testprogram/e_jn.c_e.c:144:16");
          ;
        }

        break;
        }
        double temp_var_for_tac_9, temp_var_for_tac_10;
        double temp_var_for_const_8, temp_var_for_const_9;
        double temp_var_for_callexp_3;

        temp_var_for_tac_9 = invsqrtpi * temp;

        temp_var_for_callexp_3 = __ieee754_sqrt(x);
        temp_var_for_tac_10 = temp_var_for_tac_9 / temp_var_for_callexp_3;

        b = temp_var_for_tac_10;
        computeDMul((Addr)&temp_var_for_tac_9,
                    {(Addr) &(temp_var_for_const_8 = invsqrtpi), (Addr)&temp},
                    "/home/shijia/Public/testprogram/e_jn.c_e.c:149:23");
        computeDDiv((Addr)&temp_var_for_tac_10,
                    {(Addr)&temp_var_for_tac_9,
                     (Addr) &(temp_var_for_const_9 = temp_var_for_callexp_3)},
                    "/home/shijia/Public/testprogram/e_jn.c_e.c:149:30");
        AssignD({(Addr)&b}, (Addr)&temp_var_for_tac_10,
                "/home/shijia/Public/testprogram/e_jn.c_e.c:149:11");
        ;
      } else {
        double temp_var_for_const_10;
        double temp_var_for_callexp_4;

        temp_var_for_callexp_4 = __ieee754_j0(x);
        a = temp_var_for_callexp_4;
        AssignD({(Addr)&a},
                (Addr) &(temp_var_for_const_10 = temp_var_for_callexp_4),
                "/home/shijia/Public/testprogram/e_jn.c_e.c:151:11");
        ;
        double temp_var_for_const_11;
        double temp_var_for_callexp_5;

        temp_var_for_callexp_5 = __ieee754_j1(x);
        b = temp_var_for_callexp_5;
        AssignD({(Addr)&b},
                (Addr) &(temp_var_for_const_11 = temp_var_for_callexp_5),
                "/home/shijia/Public/testprogram/e_jn.c_e.c:152:11");
        ;
        for (i = 1; i < n; i++) {
          temp = b;
          AssignD({(Addr)&temp}, (Addr)&b,
                  "/home/shijia/Public/testprogram/e_jn.c_e.c:154:16");
          ;
          double temp_var_for_ext_6;
          double temp_var_for_tac_11, temp_var_for_tac_12, temp_var_for_tac_13,
              temp_var_for_tac_14;
          double temp_var_for_const_12, temp_var_for_const_13,
              temp_var_for_const_14;
          temp_var_for_tac_11 = i + i;

          temp_var_for_tac_12 = ((double)temp_var_for_tac_11) / x;

          temp_var_for_tac_13 = b * temp_var_for_tac_12;

          temp_var_for_tac_14 = temp_var_for_tac_13 - a;

          temp_var_for_ext_6 = temp_var_for_tac_14;
          computeAdd((Addr)&temp_var_for_tac_11,
                     {(Addr) &(temp_var_for_const_13 = i),
                      (Addr) &(temp_var_for_const_12 = i)},
                     "/home/shijia/Public/testprogram/e_jn.c_e.c:156:48");
          computeDDiv(
              (Addr)&temp_var_for_tac_12,
              {(Addr) &(temp_var_for_const_14 = ((double)temp_var_for_tac_11)),
               (Addr)&x},
              "/home/shijia/Public/testprogram/e_jn.c_e.c:156:53");
          computeDMul((Addr)&temp_var_for_tac_13,
                      {(Addr)&b, (Addr)&temp_var_for_tac_12},
                      "/home/shijia/Public/testprogram/e_jn.c_e.c:156:34");
          computeDSub((Addr)&temp_var_for_tac_14,
                      {(Addr)&temp_var_for_tac_13, (Addr)&a},
                      "/home/shijia/Public/testprogram/e_jn.c_e.c:156:58");
          AssignD({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_14,
                  "/home/shijia/Public/testprogram/e_jn.c_e.c:156:30");
          ; // b
          /*(a)(x)(i)(i)(TempNull)(b)*/
          b = temp_var_for_ext_6; /* avoid underflow */
          double temp_var_for_ext_7;
          temp_var_for_ext_7 = temp;
          AssignD({(Addr)&temp_var_for_ext_7}, (Addr)&temp,
                  "/home/shijia/Public/testprogram/e_jn.c_e.c:160:30");
          ; // a
          /*(a)(x)(i)(i)(TempNull)(b)(x)(i)(i)(TempNull)(b)(x)(i)(i)(TempNull)(temp)*/
          a = temp_var_for_ext_7;
          AssignD({(Addr)&a}, (Addr)&temp_var_for_ext_7,
                  "/home/shijia/Public/testprogram/e_jn.c_e.c:162:13");
          ;
        }
      }
    } else {
      if (ix < IC(0x3e100000)) { /* x < 2**-29 */
        /* x is tiny, return the first Taylor expansion of J(n,x)
         * J(n,x) = 1/n!*(x/2)^n  - ...
         */
        if (n > 33) /* underflow */
        {
          double temp_var_for_const_15;
          b = zero;
          AssignD({(Addr)&b}, (Addr) &(temp_var_for_const_15 = zero),
                  "/home/shijia/Public/testprogram/e_jn.c_e.c:172:13");
          ;
        }

        else {
          double temp_var_for_tac_15;
          double temp_var_for_const_16;
          temp_var_for_tac_15 = x * 0.5;

          temp = temp_var_for_tac_15;
          computeDMul((Addr)&temp_var_for_tac_15,
                      {(Addr)&x, (Addr) &(temp_var_for_const_16 = 0.5)},
                      "/home/shijia/Public/testprogram/e_jn.c_e.c:176:20");
          AssignD({(Addr)&temp}, (Addr)&temp_var_for_tac_15,
                  "/home/shijia/Public/testprogram/e_jn.c_e.c:176:16");
          ;
          b = temp;
          AssignD({(Addr)&b}, (Addr)&temp,
                  "/home/shijia/Public/testprogram/e_jn.c_e.c:177:13");
          ;
          for (a = one, i = 2; i <= n; i++) {
            a *= ((double)i);
            ; /* a = n! */
            b *= temp;
            ; /* b = (x/2)^n */
          }
          double temp_var_for_ext_8;
          double temp_var_for_tac_18;
          temp_var_for_tac_18 = b / a;

          temp_var_for_ext_8 = temp_var_for_tac_18;
          computeDDiv((Addr)&temp_var_for_tac_18, {(Addr)&b, (Addr)&a},
                      "/home/shijia/Public/testprogram/e_jn.c_e.c:183:34");
          AssignD({(Addr)&temp_var_for_ext_8}, (Addr)&temp_var_for_tac_18,
                  "/home/shijia/Public/testprogram/e_jn.c_e.c:183:30");
          ; // b
          /*(i)(i)(a)(temp)(b)(a)(b)*/
          b = temp_var_for_ext_8;
          AssignD({(Addr)&b}, (Addr)&temp_var_for_ext_8,
                  "/home/shijia/Public/testprogram/e_jn.c_e.c:185:13");
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
        double t, v;
        double q0, q1, h, tmp;
        int32_t k, m;

        double temp_var_for_tac_19, temp_var_for_tac_20;
        double temp_var_for_const_17, temp_var_for_const_18,
            temp_var_for_const_19;
        temp_var_for_tac_19 = n + n;

        temp_var_for_tac_20 = temp_var_for_tac_19 / ((double)x);

        w = temp_var_for_tac_20;
        computeAdd((Addr)&temp_var_for_tac_19,
                   {(Addr) &(temp_var_for_const_18 = n),
                    (Addr) &(temp_var_for_const_17 = n)},
                   "/home/shijia/Public/testprogram/e_jn.c_e.c:221:16");
        computeDDiv((Addr)&temp_var_for_tac_20,
                    {(Addr)&temp_var_for_tac_19,
                     (Addr) &(temp_var_for_const_19 = ((double)x))},
                    "/home/shijia/Public/testprogram/e_jn.c_e.c:221:21");
        AssignD({(Addr)&w}, (Addr)&temp_var_for_tac_20,
                "/home/shijia/Public/testprogram/e_jn.c_e.c:221:11");
        ;
        h = double temp_var_for_tac_21;
        double temp_var_for_const_20, temp_var_for_const_21;
        temp_var_for_tac_21 = 2.0 / ((double)x);

        ;
        q0 = w;
        computeDDiv((Addr)&temp_var_for_tac_21,
                    {(Addr) &(temp_var_for_const_21 = 2.0),
                     (Addr) &(temp_var_for_const_20 = ((double)x))},
                    "/home/shijia/Public/testprogram/e_jn.c_e.c:222:17");
        AssignD({(Addr)&q0}, (Addr)&w,
                "/home/shijia/Public/testprogram/e_jn.c_e.c:223:12");
        ;
        double temp_var_for_tac_22;
        temp_var_for_tac_22 = w + h;

        z = temp_var_for_tac_22;
        computeDAdd((Addr)&temp_var_for_tac_22, {(Addr)&w, (Addr)&h},
                    "/home/shijia/Public/testprogram/e_jn.c_e.c:224:15");
        AssignD({(Addr)&z}, (Addr)&temp_var_for_tac_22,
                "/home/shijia/Public/testprogram/e_jn.c_e.c:224:11");
        ;
        double temp_var_for_tac_23, temp_var_for_tac_24;
        double temp_var_for_const_22;
        temp_var_for_tac_23 = w * z;

        temp_var_for_tac_24 = temp_var_for_tac_23 - 1.0;

        q1 = temp_var_for_tac_24;
        computeDMul((Addr)&temp_var_for_tac_23, {(Addr)&w, (Addr)&z},
                    "/home/shijia/Public/testprogram/e_jn.c_e.c:225:16");
        computeDSub(
            (Addr)&temp_var_for_tac_24,
            {(Addr)&temp_var_for_tac_23, (Addr) &(temp_var_for_const_22 = 1.0)},
            "/home/shijia/Public/testprogram/e_jn.c_e.c:225:20");
        AssignD({(Addr)&q1}, (Addr)&temp_var_for_tac_24,
                "/home/shijia/Public/testprogram/e_jn.c_e.c:225:12");
        ;
        k = 1;
        int temp_var_for_ext_9;
        temp_var_for_ext_9 = int temp_var_for_tac_25;
        int temp_var_for_const_23;
        temp_var_for_tac_25 = q1 < 1.0e9;

        ;
        while (temp_var_for_ext_9) {
          k += 1;
          z += h;
          ;
          double temp_var_for_tac_27, temp_var_for_tac_28;
          temp_var_for_tac_27 = z * q1;

          temp_var_for_tac_28 = temp_var_for_tac_27 - q0;

          tmp = temp_var_for_tac_28;
          compute((Addr)&temp_var_for_tac_25,
                  {(Addr)&q1, (Addr) &(temp_var_for_const_23 = 1.0e9)},
                  "/home/shijia/Public/testprogram/e_jn.c_e.c:228:33");
          computeDMul((Addr)&temp_var_for_tac_27, {(Addr)&z, (Addr)&q1},
                      "/home/shijia/Public/testprogram/e_jn.c_e.c:232:19");
          computeDSub((Addr)&temp_var_for_tac_28,
                      {(Addr)&temp_var_for_tac_27, (Addr)&q0},
                      "/home/shijia/Public/testprogram/e_jn.c_e.c:232:24");
          AssignD({(Addr)&tmp}, (Addr)&temp_var_for_tac_28,
                  "/home/shijia/Public/testprogram/e_jn.c_e.c:232:15");
          ;
          double temp_var_for_ext_10;
          temp_var_for_ext_10 = q1;
          AssignD({(Addr)&temp_var_for_ext_10}, (Addr)&q1,
                  "/home/shijia/Public/testprogram/e_jn.c_e.c:234:31");
          ; // q0
          /*(q0)(q1)(z)(q1)(z)(q1)*/
          q0 = temp_var_for_ext_10;
          AssignD({(Addr)&q0}, (Addr)&temp_var_for_ext_10,
                  "/home/shijia/Public/testprogram/e_jn.c_e.c:236:14");
          ;
          q1 = tmp;
          AssignD({(Addr)&q1}, (Addr)&tmp,
                  "/home/shijia/Public/testprogram/e_jn.c_e.c:237:14");
          ;
          temp_var_for_ext_9 = int temp_var_for_tac_29;
          int temp_var_for_const_24;
          temp_var_for_tac_29 = q1 < 1.0e9;

          ;
        }
        m = n + n;
        for (t = zero, i = 2 * (n + k); i >= m; i -= 2) {
          double temp_var_for_ext_11;
          double temp_var_for_tac_30, temp_var_for_tac_31, temp_var_for_tac_32;
          double temp_var_for_const_25, temp_var_for_const_26;
          temp_var_for_tac_30 = i / x;

          temp_var_for_tac_31 = temp_var_for_tac_30 - t;

          temp_var_for_tac_32 = one / temp_var_for_tac_31;

          temp_var_for_ext_11 = temp_var_for_tac_32;
          compute((Addr)&temp_var_for_tac_29,
                  {(Addr)&q1, (Addr) &(temp_var_for_const_24 = 1.0e9)},
                  "/home/shijia/Public/testprogram/e_jn.c_e.c:238:35");
          computeDDiv((Addr)&temp_var_for_tac_30,
                      {(Addr) &(temp_var_for_const_25 = i), (Addr)&x},
                      "/home/shijia/Public/testprogram/e_jn.c_e.c:243:42");
          computeDSub((Addr)&temp_var_for_tac_31,
                      {(Addr)&temp_var_for_tac_30, (Addr)&t},
                      "/home/shijia/Public/testprogram/e_jn.c_e.c:243:46");
          computeDDiv((Addr)&temp_var_for_tac_32,
                      {(Addr) &(temp_var_for_const_26 = one),
                       (Addr)&temp_var_for_tac_31},
                      "/home/shijia/Public/testprogram/e_jn.c_e.c:243:37");
          AssignD({(Addr)&temp_var_for_ext_11}, (Addr)&temp_var_for_tac_32,
                  "/home/shijia/Public/testprogram/e_jn.c_e.c:243:31");
          ; // t
          /*(t)(x)(i)(one)*/
          t = temp_var_for_ext_11;
          AssignD({(Addr)&t}, (Addr)&temp_var_for_ext_11,
                  "/home/shijia/Public/testprogram/e_jn.c_e.c:245:13");
          ;
        }

        a = t;
        AssignD({(Addr)&a}, (Addr)&t,
                "/home/shijia/Public/testprogram/e_jn.c_e.c:248:11");
        ;
        double temp_var_for_const_27;
        b = one;
        AssignD({(Addr)&b}, (Addr) &(temp_var_for_const_27 = one),
                "/home/shijia/Public/testprogram/e_jn.c_e.c:249:11");
        ;
        /*  estimate log((2/x)^n*n!) = n*log(2/x)+n*ln(n)
         *  Hence, if n*(log(2n/x)) > ...
         *  single 8.8722839355e+01
         *  double 7.09782712893383973096e+02
         *  long double 1.1356523406294143949491931077970765006170e+04
         *  then recurrent value may overflow and the result is
         *  likely underflow to zero
         */
        double temp_var_for_const_28;
        tmp = n;
        AssignD({(Addr)&tmp}, (Addr) &(temp_var_for_const_28 = n),
                "/home/shijia/Public/testprogram/e_jn.c_e.c:258:13");
        ;
        double temp_var_for_tac_33;
        double temp_var_for_const_29;
        temp_var_for_tac_33 = two / x;

        v = temp_var_for_tac_33;
        computeDDiv((Addr)&temp_var_for_tac_33,
                    {(Addr) &(temp_var_for_const_29 = two), (Addr)&x},
                    "/home/shijia/Public/testprogram/e_jn.c_e.c:259:17");
        AssignD({(Addr)&v}, (Addr)&temp_var_for_tac_33,
                "/home/shijia/Public/testprogram/e_jn.c_e.c:259:11");
        ;
        double temp_var_for_ext_12;
        double temp_var_for_tac_34, temp_var_for_tac_35;
        double temp_var_for_const_30;
        double temp_var_for_callexp_6;

        /*embed fun has found*/
        double temp_var_for_callexp_7;

        temp_var_for_tac_34 = v * tmp;

        temp_var_for_callexp_6 = fabs(temp_var_for_tac_34);
        temp_var_for_callexp_7 = __ieee754_log(temp_var_for_callexp_6);
        temp_var_for_tac_35 = tmp * temp_var_for_callexp_7;

        temp_var_for_ext_12 = temp_var_for_tac_35;
        computeDMul((Addr)&temp_var_for_tac_34, {(Addr)&v, (Addr)&tmp},
                    "/home/shijia/Public/testprogram/e_jn.c_e.c:262:33 "
                    "<Spelling=/home/shijia/Public/testprogram/"
                    "e_jn.c_e.c:262:50>");
        computeDMul((Addr)&temp_var_for_tac_35,
                    {(Addr)&tmp,
                     (Addr) &(temp_var_for_const_30 = temp_var_for_callexp_7)},
                    "/home/shijia/Public/testprogram/e_jn.c_e.c:262:17");
        AssignD({(Addr)&temp_var_for_ext_12}, (Addr)&temp_var_for_tac_35,
                "/home/shijia/Public/testprogram/e_jn.c_e.c:261:29");
        ; // tmp
        /*(x)(two)(__ieee754_log(__ieee754_fabs(v * tmp)))(tmp)*/
        tmp = temp_var_for_ext_12;
        AssignD({(Addr)&tmp}, (Addr)&temp_var_for_ext_12,
                "/home/shijia/Public/testprogram/e_jn.c_e.c:264:13");
        ;
        if (int temp_var_for_tac_36; int temp_var_for_const_31;
            temp_var_for_tac_36 = tmp < 7.09782712893383973096e+02;

            ) {
          for (i = n - 1, di = (double)(i + i); i > 0; i--) {
            temp = b;
            compute((Addr)&temp_var_for_tac_36,
                    {(Addr)&tmp, (Addr) &(temp_var_for_const_31 =
                                              7.09782712893383973096e+02)},
                    "/home/shijia/Public/testprogram/e_jn.c_e.c:265:17");
            AssignD({(Addr)&temp}, (Addr)&b,
                    "/home/shijia/Public/testprogram/e_jn.c_e.c:267:18");
            ;
            b *= di;
            ;
            double temp_var_for_ext_13;
            double temp_var_for_tac_38, temp_var_for_tac_39;
            temp_var_for_tac_38 = b / x;

            temp_var_for_tac_39 = temp_var_for_tac_38 - a;

            temp_var_for_ext_13 = temp_var_for_tac_39;
            computeDDiv((Addr)&temp_var_for_tac_38, {(Addr)&b, (Addr)&x},
                        "/home/shijia/Public/testprogram/e_jn.c_e.c:270:37");
            computeDSub((Addr)&temp_var_for_tac_39,
                        {(Addr)&temp_var_for_tac_38, (Addr)&a},
                        "/home/shijia/Public/testprogram/e_jn.c_e.c:270:41");
            AssignD({(Addr)&temp_var_for_ext_13}, (Addr)&temp_var_for_tac_39,
                    "/home/shijia/Public/testprogram/e_jn.c_e.c:270:33");
            ; // b
            /*(di)(b)(a)(x)(b)*/
            b = temp_var_for_ext_13;
            AssignD({(Addr)&b}, (Addr)&temp_var_for_ext_13,
                    "/home/shijia/Public/testprogram/e_jn.c_e.c:272:15");
            ;
            double temp_var_for_ext_14;
            temp_var_for_ext_14 = temp;
            AssignD({(Addr)&temp_var_for_ext_14}, (Addr)&temp,
                    "/home/shijia/Public/testprogram/e_jn.c_e.c:274:33");
            ; // a
            /*(a)(x)(b)(x)(b)(temp)*/
            a = temp_var_for_ext_14;
            AssignD({(Addr)&a}, (Addr)&temp_var_for_ext_14,
                    "/home/shijia/Public/testprogram/e_jn.c_e.c:276:15");
            ;
            di -= two;
            ;
          }
        } else {
          for (i = n - 1, double temp_var_for_ext_15;
               temp_var_for_ext_15 = (double)(i + i); // di
               /*(two)(di)(i)(i)(TempNull)*/
               di = temp_var_for_ext_15;
               i > 0; i--) {
            temp = b;
            b *= di;
            double temp_var_for_ext_16;
            temp_var_for_ext_16 = b / x - a; // b
            /*(di)(b)(a)(x)(b)*/
            b = temp_var_for_ext_16;
            double temp_var_for_ext_17;
            temp_var_for_ext_17 = temp; // a
            /*(a)(x)(b)(x)(b)(temp)*/
            a = temp_var_for_ext_17;
            di -= two;
            /* scale b to avoid spurious overflow */
            if (b > 1e100) {
              a /= b;
              t /= b;
              double temp_var_for_ext_18;
              temp_var_for_ext_18 = one; // b
              /*(two)(di)(b)(a)(b)(t)(one)*/
              b = temp_var_for_ext_18;
            }
          }
        }
        /* j0() and j1() suffer enormous loss of precision at and
         * near zero; however, we know that their zero points never
         * coincide, so just choose the one further away from zero.
         */
        double temp_var_for_const_32;
        double temp_var_for_callexp_8;

        temp_var_for_callexp_8 = __ieee754_j0(x);
        z = temp_var_for_callexp_8;
        AssignD({(Addr)&z},
                (Addr) &(temp_var_for_const_32 = temp_var_for_callexp_8),
                "/home/shijia/Public/testprogram/e_jn.c_e.c:311:11");
        ;
        double temp_var_for_const_33;
        double temp_var_for_callexp_9;

        temp_var_for_callexp_9 = __ieee754_j1(x);
        w = temp_var_for_callexp_9;
        AssignD({(Addr)&w},
                (Addr) &(temp_var_for_const_33 = temp_var_for_callexp_9),
                "/home/shijia/Public/testprogram/e_jn.c_e.c:312:11");
        ;
        if (int temp_var_for_tac_41;
            int temp_var_for_const_34, temp_var_for_const_35;
            double temp_var_for_callexp_10;

            double temp_var_for_callexp_11;

            temp_var_for_callexp_10 = fabs(z);
            temp_var_for_callexp_11 = fabs(w);
            temp_var_for_tac_41 =
                temp_var_for_callexp_10 >= temp_var_for_callexp_11;

            ) {
          double temp_var_for_ext_19;
          double temp_var_for_tac_42, temp_var_for_tac_43;
          temp_var_for_tac_42 = t * z;

          temp_var_for_tac_43 = temp_var_for_tac_42 / b;

          temp_var_for_ext_19 = temp_var_for_tac_43;
          compute((Addr)&temp_var_for_tac_41,
                  {(Addr) &(temp_var_for_const_35 = temp_var_for_callexp_10),
                   (Addr) &(temp_var_for_const_34 = temp_var_for_callexp_11)},
                  "/home/shijia/Public/testprogram/e_jn.c_e.c:313:31");
          computeDMul((Addr)&temp_var_for_tac_42, {(Addr)&t, (Addr)&z},
                      "/home/shijia/Public/testprogram/e_jn.c_e.c:315:36");
          computeDDiv((Addr)&temp_var_for_tac_43,
                      {(Addr)&temp_var_for_tac_42, (Addr)&b},
                      "/home/shijia/Public/testprogram/e_jn.c_e.c:315:40");
          AssignD({(Addr)&temp_var_for_ext_19}, (Addr)&temp_var_for_tac_43,
                  "/home/shijia/Public/testprogram/e_jn.c_e.c:315:31");
          ; // b
          /*(b)(z)(t)*/
          b = temp_var_for_ext_19;
          AssignD({(Addr)&b}, (Addr)&temp_var_for_ext_19,
                  "/home/shijia/Public/testprogram/e_jn.c_e.c:317:13");
          ;
        }

        else {
          double temp_var_for_ext_20;
          double temp_var_for_tac_44, temp_var_for_tac_45;
          temp_var_for_tac_44 = t * w;

          temp_var_for_tac_45 = temp_var_for_tac_44 / a;

          temp_var_for_ext_20 = temp_var_for_tac_45;
          computeDMul((Addr)&temp_var_for_tac_44, {(Addr)&t, (Addr)&w},
                      "/home/shijia/Public/testprogram/e_jn.c_e.c:322:36");
          computeDDiv((Addr)&temp_var_for_tac_45,
                      {(Addr)&temp_var_for_tac_44, (Addr)&a},
                      "/home/shijia/Public/testprogram/e_jn.c_e.c:322:40");
          AssignD({(Addr)&temp_var_for_ext_20}, (Addr)&temp_var_for_tac_45,
                  "/home/shijia/Public/testprogram/e_jn.c_e.c:322:31");
          ; // b
          /*(b)(z)(t)(z)(t)(a)(w)(t)*/
          b = temp_var_for_ext_20;
          AssignD({(Addr)&b}, (Addr)&temp_var_for_ext_20,
                  "/home/shijia/Public/testprogram/e_jn.c_e.c:324:13");
          ;
        }
      }
    }
  }

  if (sgn) {
    double temp_var_for_ext_21;
    double temp_var_for_const_36;
    temp_var_for_ext_21 = (-(b));
    AssignD({(Addr)&temp_var_for_ext_21},
            (Addr) &(temp_var_for_const_36 = (-(b))),
            "/home/shijia/Public/testprogram/e_jn.c_e.c:332:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_21", (Addr)&temp_var_for_ext_21));
    callExp++; /*identify the function is  add move tmpShadow*/
    return (double temp_var_for_tac_46;
            double temp_var_for_const_37, temp_var_for_const_38;
            temp_var_for_tac_46 = 0.0 - 1;

            );
  }

  double temp_var_for_ext_22;
  temp_var_for_ext_22 = b;
  computeDSub((Addr)&temp_var_for_tac_46,
              {(Addr) &(temp_var_for_const_38 = 0.0),
               (Addr) &(temp_var_for_const_37 = 1)},
              "/home/shijia/Public/testprogram/e_jn.c_e.c:336:17");
  AssignD({(Addr)&temp_var_for_ext_22}, (Addr)&b,
          "/home/shijia/Public/testprogram/e_jn.c_e.c:340:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_22", (Addr)&temp_var_for_ext_22));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_22;
}

/* wrapper jn */
double __jn(int n, double x) {
  if (isgreater(__ieee754_fabs(x), X_TLOSS) && _LIB_VERSION != _IEEE_ &&
      _LIB_VERSION != _POSIX_)
  /* jn(n,|x|>X_TLOSS) */
  {
    double temp_var_for_ext_23;
    double temp_var_for_const_39;
    double temp_var_for_callexp_12;

    temp_var_for_callexp_12 = __kernel_standard(n, x, 0.0, KMATHERR_JN_TLOSS);
    temp_var_for_ext_23 = temp_var_for_callexp_12;
    AssignD({(Addr)&temp_var_for_ext_23},
            (Addr) &(temp_var_for_const_39 = temp_var_for_callexp_12),
            "/home/shijia/Public/testprogram/e_jn.c_e.c:353:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_23", (Addr)&temp_var_for_ext_23));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_23;
  }

  double temp_var_for_ext_24;
  double temp_var_for_const_40;
  double temp_var_for_callexp_13;

  temp_var_for_callexp_13 = __ieee754_jn(n, x);
  temp_var_for_ext_24 = temp_var_for_callexp_13;
  AssignD({(Addr)&temp_var_for_ext_24},
          (Addr) &(temp_var_for_const_40 = temp_var_for_callexp_13),
          "/home/shijia/Public/testprogram/e_jn.c_e.c:361:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_24", (Addr)&temp_var_for_ext_24));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_24;
}

__typeof(__jn) jn __attribute__((weak, alias("__jn")));
#ifdef __NO_LONG_DOUBLE_MATH
__typeof(__jnl) __jnl __attribute__((alias("__jn")));
__typeof(__jnl) jnl __attribute__((weak, alias("__jnl")));
#endif
