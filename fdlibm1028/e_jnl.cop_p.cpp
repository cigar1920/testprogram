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

/* Modifications for long double are
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

/*
 * __ieee754_jn(n, x)
 * floating point Bessel's function of the 1st kind
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
 *
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

long double __ieee754_jnl(int n, long double x) {
  uint32_t se, i0, i1;
  int32_t i, ix;
  int sgn;
  long double a, b, temp, di;
  long double z, w;

  static const long double invsqrtpi = 5.64189583547756286948079e-1L;
  static const long double two = 2.0e0L;
  static const long double one = 1.0e0L;
  static const long double zero = 0.0L;

  /* J(-n,x) = (-1)^n * J(n, x), J(n, -x) = (-1)^n * J(n, x)
   * Thus, J(-n,x) = J(n,-x)
   */

  long double temp_var_for_const_0;
  ew_u.value = x;
  AssignLd({(Addr) &(temp_var_for_const_0 = ew_u.value)}, (Addr)&x,
           "/home/shijia/Public/testprogram/e_jnl.c_e.c:81:3 "
           "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
  ;
  ix = se & 0x7fff;

  /* if J(n,NaN) is NaN */
  if ((ix == 0x7fff) && ((i0 & IC(0x7fffffff)) != 0)) {
    long double temp_var_for_ext_0;
    long double temp_var_for_tac_0;
    temp_var_for_tac_0 = x + x;

    temp_var_for_ext_0 = temp_var_for_tac_0;
    computeLdAdd((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&x},
                 "/home/shijia/Public/testprogram/e_jnl.c_e.c:87:28");
    AssignLd({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_0,
             "/home/shijia/Public/testprogram/e_jnl.c_e.c:87:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  if (n < 0) {
    n = -n;
    long double temp_var_for_ext_1;
    long double temp_var_for_tac_1;
    long double temp_var_for_const_1;
    temp_var_for_tac_1 = 0.0 - x;

    temp_var_for_ext_1 = temp_var_for_tac_1;
    computeLdSub((Addr)&temp_var_for_tac_1,
                 {(Addr) &(temp_var_for_const_1 = 0.0), (Addr)&x},
                 "/home/shijia/Public/testprogram/e_jnl.c_e.c:96:31");
    AssignLd({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_1,
             "/home/shijia/Public/testprogram/e_jnl.c_e.c:96:24");
    ; // x
    /*(0)(t)(x)(x)*/
    x = temp_var_for_ext_1;
    AssignLd({(Addr)&x}, (Addr)&temp_var_for_ext_1,
             "/home/shijia/Public/testprogram/e_jnl.c_e.c:98:7");
    ;
    se ^= 0x8000;
  }
  if (n == 0) {
    long double temp_var_for_ext_2;
    long double temp_var_for_const_2;
    long double temp_var_for_callexp_0;

    temp_var_for_callexp_0 = __ieee754_j0l(x);
    temp_var_for_ext_2 = temp_var_for_callexp_0;
    AssignLd({(Addr)&temp_var_for_ext_2},
             (Addr) &(temp_var_for_const_2 = temp_var_for_callexp_0),
             "/home/shijia/Public/testprogram/e_jnl.c_e.c:103:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  }

  if (n == 1) {
    long double temp_var_for_ext_3;
    long double temp_var_for_const_3;
    long double temp_var_for_callexp_1;

    temp_var_for_callexp_1 = __ieee754_j1l(x);
    temp_var_for_ext_3 = temp_var_for_callexp_1;
    AssignLd({(Addr)&temp_var_for_ext_3},
             (Addr) &(temp_var_for_const_3 = temp_var_for_callexp_1),
             "/home/shijia/Public/testprogram/e_jnl.c_e.c:111:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_3;
  }

  sgn = (int)((n & 1) & (se >> 15)); /* even n -- 0, odd n -- sign(x) */
  long double temp_var_for_ext_4;
  long double temp_var_for_const_4;
  long double temp_var_for_callexp_2;

  temp_var_for_callexp_2 = fabsl(x);
  temp_var_for_ext_4 = temp_var_for_callexp_2;
  AssignLd({(Addr)&temp_var_for_ext_4},
           (Addr) &(temp_var_for_const_4 = temp_var_for_callexp_2),
           "/home/shijia/Public/testprogram/e_jnl.c_e.c:119:22");
  ; // x
  /*(__ieee754_fabsl(x))*/
  x = temp_var_for_ext_4;
  AssignLd({(Addr)&x}, (Addr)&temp_var_for_ext_4,
           "/home/shijia/Public/testprogram/e_jnl.c_e.c:121:5");
  ;
  if ((ix | i0 | i1) == 0 || ix >= 0x7fff)
  /* if x is 0 or inf */
  {
    long double temp_var_for_const_5;
    b = zero;
    AssignLd({(Addr)&b}, (Addr) &(temp_var_for_const_5 = zero),
             "/home/shijia/Public/testprogram/e_jnl.c_e.c:125:7");
    ;
  }

  else {
    if (int temp_var_for_tac_2; int temp_var_for_const_6;
        temp_var_for_tac_2 = ((long double)n) <= x;

        ) {
      /* Safe to use J(n+1,x)=2n/x *J(n,x)-J(n-1,x) */
      if (ix >= 0x412D) { /* x > 2**302 */

        /* ??? This might be a futile gesture.
           If x exceeds X_TLOSS anyway, the wrapper function
           will set the result to zero. */

        /* (x >> n**2)
         *      Jn(x) = cos(x-(2n+1)*pi/4)*sqrt(2/x*pi)
         *      Yn(x) = sin(x-(2n+1)*pi/4)*sqrt(2/x*pi)
         *      Let s=sin(x), c=cos(x),
         *          xn=x-(2n+1)*pi/4, sqt2 = sqrt(2),then
         *
         *             n    sin(xn)*sqt2    cos(xn)*sqt2
         *          ----------------------------------
         *             0     s-c             c+s
         *             1    -s-c            -c+s
         *             2    -s+c            -c-s
         *             3     s+c             c-s
         */
        long double s;
        long double c;

        __ieee754_sincosl(x, &s, &c);
        int temp_var_for_ext_5;
        temp_var_for_ext_5 = n & 3;
        switch (temp_var_for_ext_5) {
        case 0: {
          long double temp_var_for_tac_3;
          temp_var_for_tac_3 = c + s;

          temp = temp_var_for_tac_3;
          compute((Addr)&temp_var_for_tac_2,
                  {(Addr) &(temp_var_for_const_6 = ((long double)n)), (Addr)&x},
                  "/home/shijia/Public/testprogram/e_jnl.c_e.c:129:24");
          computeLdAdd((Addr)&temp_var_for_tac_3, {(Addr)&c, (Addr)&s},
                       "/home/shijia/Public/testprogram/e_jnl.c_e.c:158:20");
          AssignLd({(Addr)&temp}, (Addr)&temp_var_for_tac_3,
                   "/home/shijia/Public/testprogram/e_jnl.c_e.c:158:16");
          ;
        }

        break;
        case 1: {
          long double temp_var_for_tac_4, temp_var_for_tac_5;
          long double temp_var_for_const_7;
          temp_var_for_tac_4 = 0.0 - c;

          temp_var_for_tac_5 = temp_var_for_tac_4 + s;

          temp = temp_var_for_tac_5;
          computeLdSub((Addr)&temp_var_for_tac_4,
                       {(Addr) &(temp_var_for_const_7 = 0.0), (Addr)&c},
                       "/home/shijia/Public/testprogram/e_jnl.c_e.c:163:23");
          computeLdAdd((Addr)&temp_var_for_tac_5,
                       {(Addr)&temp_var_for_tac_4, (Addr)&s},
                       "/home/shijia/Public/testprogram/e_jnl.c_e.c:163:28");
          AssignLd({(Addr)&temp}, (Addr)&temp_var_for_tac_5,
                   "/home/shijia/Public/testprogram/e_jnl.c_e.c:163:16");
          ;
        }

        break;
        case 2: {
          long double temp_var_for_tac_6, temp_var_for_tac_7;
          long double temp_var_for_const_8;
          temp_var_for_tac_6 = 0.0 - c;

          temp_var_for_tac_7 = temp_var_for_tac_6 - s;

          temp = temp_var_for_tac_7;
          computeLdSub((Addr)&temp_var_for_tac_6,
                       {(Addr) &(temp_var_for_const_8 = 0.0), (Addr)&c},
                       "/home/shijia/Public/testprogram/e_jnl.c_e.c:168:23");
          computeLdSub((Addr)&temp_var_for_tac_7,
                       {(Addr)&temp_var_for_tac_6, (Addr)&s},
                       "/home/shijia/Public/testprogram/e_jnl.c_e.c:168:28");
          AssignLd({(Addr)&temp}, (Addr)&temp_var_for_tac_7,
                   "/home/shijia/Public/testprogram/e_jnl.c_e.c:168:16");
          ;
        }

        break;
        case 3: {
          long double temp_var_for_tac_8;
          temp_var_for_tac_8 = c - s;

          temp = temp_var_for_tac_8;
          computeLdSub((Addr)&temp_var_for_tac_8, {(Addr)&c, (Addr)&s},
                       "/home/shijia/Public/testprogram/e_jnl.c_e.c:173:20");
          AssignLd({(Addr)&temp}, (Addr)&temp_var_for_tac_8,
                   "/home/shijia/Public/testprogram/e_jnl.c_e.c:173:16");
          ;
        }

        break;
        }
        long double temp_var_for_tac_9, temp_var_for_tac_10;
        long double temp_var_for_const_9, temp_var_for_const_10;
        long double temp_var_for_callexp_3;

        temp_var_for_tac_9 = invsqrtpi * temp;

        temp_var_for_callexp_3 = __ieee754_sqrtl(x);
        temp_var_for_tac_10 = temp_var_for_tac_9 / temp_var_for_callexp_3;

        b = temp_var_for_tac_10;
        computeLdMul((Addr)&temp_var_for_tac_9,
                     {(Addr) &(temp_var_for_const_9 = invsqrtpi), (Addr)&temp},
                     "/home/shijia/Public/testprogram/e_jnl.c_e.c:178:23");
        computeLdDiv((Addr)&temp_var_for_tac_10,
                     {(Addr)&temp_var_for_tac_9,
                      (Addr) &(temp_var_for_const_10 = temp_var_for_callexp_3)},
                     "/home/shijia/Public/testprogram/e_jnl.c_e.c:178:30");
        AssignLd({(Addr)&b}, (Addr)&temp_var_for_tac_10,
                 "/home/shijia/Public/testprogram/e_jnl.c_e.c:178:11");
        ;
      } else {
        long double temp_var_for_const_11;
        long double temp_var_for_callexp_4;

        temp_var_for_callexp_4 = __ieee754_j0l(x);
        a = temp_var_for_callexp_4;
        AssignLd({(Addr)&a},
                 (Addr) &(temp_var_for_const_11 = temp_var_for_callexp_4),
                 "/home/shijia/Public/testprogram/e_jnl.c_e.c:180:11");
        ;
        long double temp_var_for_const_12;
        long double temp_var_for_callexp_5;

        temp_var_for_callexp_5 = __ieee754_j1l(x);
        b = temp_var_for_callexp_5;
        AssignLd({(Addr)&b},
                 (Addr) &(temp_var_for_const_12 = temp_var_for_callexp_5),
                 "/home/shijia/Public/testprogram/e_jnl.c_e.c:181:11");
        ;
        for (i = 1; i < n; i++) {
          temp = b;
          AssignLd({(Addr)&temp}, (Addr)&b,
                   "/home/shijia/Public/testprogram/e_jnl.c_e.c:183:16");
          ;
          long double temp_var_for_ext_6;
          long double temp_var_for_tac_11, temp_var_for_tac_12,
              temp_var_for_tac_13, temp_var_for_tac_14;
          long double temp_var_for_const_13, temp_var_for_const_14,
              temp_var_for_const_15;
          temp_var_for_tac_11 = i + i;

          temp_var_for_tac_12 = ((long double)temp_var_for_tac_11) / x;

          temp_var_for_tac_13 = b * temp_var_for_tac_12;

          temp_var_for_tac_14 = temp_var_for_tac_13 - a;

          temp_var_for_ext_6 = temp_var_for_tac_14;
          computeAdd((Addr)&temp_var_for_tac_11,
                     {(Addr) &(temp_var_for_const_14 = i),
                      (Addr) &(temp_var_for_const_13 = i)},
                     "/home/shijia/Public/testprogram/e_jnl.c_e.c:185:53");
          computeLdDiv((Addr)&temp_var_for_tac_12,
                       {(Addr) &(temp_var_for_const_15 =
                                     ((long double)temp_var_for_tac_11)),
                        (Addr)&x},
                       "/home/shijia/Public/testprogram/e_jnl.c_e.c:185:58");
          computeLdMul((Addr)&temp_var_for_tac_13,
                       {(Addr)&b, (Addr)&temp_var_for_tac_12},
                       "/home/shijia/Public/testprogram/e_jnl.c_e.c:185:34");
          computeLdSub((Addr)&temp_var_for_tac_14,
                       {(Addr)&temp_var_for_tac_13, (Addr)&a},
                       "/home/shijia/Public/testprogram/e_jnl.c_e.c:185:63");
          AssignLd({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_14,
                   "/home/shijia/Public/testprogram/e_jnl.c_e.c:185:30");
          ; // b
          /*(a)(x)(i)(i)(TempNull)(b)*/
          b = temp_var_for_ext_6; /* avoid underflow */
          long double temp_var_for_ext_7;
          temp_var_for_ext_7 = temp;
          AssignLd({(Addr)&temp_var_for_ext_7}, (Addr)&temp,
                   "/home/shijia/Public/testprogram/e_jnl.c_e.c:189:30");
          ; // a
          /*(a)(x)(i)(i)(TempNull)(b)(x)(i)(i)(TempNull)(b)(x)(i)(i)(TempNull)(temp)*/
          a = temp_var_for_ext_7;
          AssignLd({(Addr)&a}, (Addr)&temp_var_for_ext_7,
                   "/home/shijia/Public/testprogram/e_jnl.c_e.c:191:13");
          ;
        }
      }
    } else {
      if (ix < 0x3fde) { /* x < 2**-33 */
        /* x is tiny, return the first Taylor expansion of J(n,x)
         * J(n,x) = 1/n!*(x/2)^n  - ...
         */
        if (n >= 400) /* underflow, result < 10^-4952 */
        {
          long double temp_var_for_const_16;
          b = zero;
          AssignLd({(Addr)&b}, (Addr) &(temp_var_for_const_16 = zero),
                   "/home/shijia/Public/testprogram/e_jnl.c_e.c:201:13");
          ;
        }

        else {
          long double temp_var_for_tac_15;
          long double temp_var_for_const_17;
          temp_var_for_tac_15 = x * 0.5;

          temp = temp_var_for_tac_15;
          computeLdMul((Addr)&temp_var_for_tac_15,
                       {(Addr)&x, (Addr) &(temp_var_for_const_17 = 0.5)},
                       "/home/shijia/Public/testprogram/e_jnl.c_e.c:205:20");
          AssignLd({(Addr)&temp}, (Addr)&temp_var_for_tac_15,
                   "/home/shijia/Public/testprogram/e_jnl.c_e.c:205:16");
          ;
          b = temp;
          AssignLd({(Addr)&b}, (Addr)&temp,
                   "/home/shijia/Public/testprogram/e_jnl.c_e.c:206:13");
          ;
          for (a = one, i = 2; i <= n; i++) {
            a *= ((long double)i);
            ; /* a = n! */
            b *= temp;
            ; /* b = (x/2)^n */
          }
          long double temp_var_for_ext_8;
          long double temp_var_for_tac_18;
          temp_var_for_tac_18 = b / a;

          temp_var_for_ext_8 = temp_var_for_tac_18;
          computeLdDiv((Addr)&temp_var_for_tac_18, {(Addr)&b, (Addr)&a},
                       "/home/shijia/Public/testprogram/e_jnl.c_e.c:212:34");
          AssignLd({(Addr)&temp_var_for_ext_8}, (Addr)&temp_var_for_tac_18,
                   "/home/shijia/Public/testprogram/e_jnl.c_e.c:212:30");
          ; // b
          /*(i)(i)(a)(temp)(b)(a)(b)*/
          b = temp_var_for_ext_8;
          AssignLd({(Addr)&b}, (Addr)&temp_var_for_ext_8,
                   "/home/shijia/Public/testprogram/e_jnl.c_e.c:214:13");
          ;
        }
      } else {
        /* use backward recurrence */
        /*                      x      x^2      x^2
         *  J(n,x)/J(n-1,x) =  ----   ------   ------   .....
         *                      2n  - 2(n+1) - 2(n+2)
         *
         *                      1      1        1
         *  (for large x)   =  ----  ------   ------   .....
         *                      2n   2(n+1)   2(n+2)
         *                      -- - ------ - ------ -
         *                       x     x         x
         *
         * Let w = 2n/x and h=2/x, then the above quotient
         * is equal to the continued fraction:
         *                  1
         *      = -----------------------
         *                     1
         *         w - -----------------
         *                        1
         *              w+h - ---------
         *                     w+2h - ...
         *
         * To determine how many terms needed, let
         * Q(0) = w, Q(1) = w(w+h) - 1,
         * Q(k) = (w+k*h)*Q(k-1) - Q(k-2),
         * When Q(k) > 1e4      good for single
         * When Q(k) > 1e9      good for double
         * When Q(k) > 1e17     good for quadruple
         */
        /* determine k */
        long double t, v;

        long double q0, q1, h, tmp;

        int32_t k, m;

        long double temp_var_for_tac_19, temp_var_for_tac_20;
        long double temp_var_for_const_18, temp_var_for_const_19,
            temp_var_for_const_20;
        temp_var_for_tac_19 = n + n;

        temp_var_for_tac_20 = temp_var_for_tac_19 / ((long double)x);

        w = temp_var_for_tac_20;
        computeAdd((Addr)&temp_var_for_tac_19,
                   {(Addr) &(temp_var_for_const_19 = n),
                    (Addr) &(temp_var_for_const_18 = n)},
                   "/home/shijia/Public/testprogram/e_jnl.c_e.c:252:16");
        computeLdDiv((Addr)&temp_var_for_tac_20,
                     {(Addr)&temp_var_for_tac_19,
                      (Addr) &(temp_var_for_const_20 = ((long double)x))},
                     "/home/shijia/Public/testprogram/e_jnl.c_e.c:252:21");
        AssignLd({(Addr)&w}, (Addr)&temp_var_for_tac_20,
                 "/home/shijia/Public/testprogram/e_jnl.c_e.c:252:11");
        ;
        h = long double temp_var_for_tac_21;
        long double temp_var_for_const_21, temp_var_for_const_22;
        temp_var_for_tac_21 = 2.0L / ((long double)x);

        ;
        q0 = w;
        computeLdDiv((Addr)&temp_var_for_tac_21,
                     {(Addr) &(temp_var_for_const_22 = 2.0L),
                      (Addr) &(temp_var_for_const_21 = ((long double)x))},
                     "/home/shijia/Public/testprogram/e_jnl.c_e.c:253:18");
        AssignLd({(Addr)&q0}, (Addr)&w,
                 "/home/shijia/Public/testprogram/e_jnl.c_e.c:254:12");
        ;
        long double temp_var_for_tac_22;
        temp_var_for_tac_22 = w + h;

        z = temp_var_for_tac_22;
        computeLdAdd((Addr)&temp_var_for_tac_22, {(Addr)&w, (Addr)&h},
                     "/home/shijia/Public/testprogram/e_jnl.c_e.c:255:15");
        AssignLd({(Addr)&z}, (Addr)&temp_var_for_tac_22,
                 "/home/shijia/Public/testprogram/e_jnl.c_e.c:255:11");
        ;
        long double temp_var_for_tac_23, temp_var_for_tac_24;
        long double temp_var_for_const_23;
        temp_var_for_tac_23 = w * z;

        temp_var_for_tac_24 = temp_var_for_tac_23 - 1.0L;

        q1 = temp_var_for_tac_24;
        computeLdMul((Addr)&temp_var_for_tac_23, {(Addr)&w, (Addr)&z},
                     "/home/shijia/Public/testprogram/e_jnl.c_e.c:256:16");
        computeLdSub((Addr)&temp_var_for_tac_24,
                     {(Addr)&temp_var_for_tac_23,
                      (Addr) &(temp_var_for_const_23 = 1.0L)},
                     "/home/shijia/Public/testprogram/e_jnl.c_e.c:256:20");
        AssignLd({(Addr)&q1}, (Addr)&temp_var_for_tac_24,
                 "/home/shijia/Public/testprogram/e_jnl.c_e.c:256:12");
        ;
        k = 1;
        int temp_var_for_ext_9;
        temp_var_for_ext_9 = int temp_var_for_tac_25;
        int temp_var_for_const_24;
        temp_var_for_tac_25 = q1 < 1.0e11L;

        ;
        while (temp_var_for_ext_9) {
          k += 1;
          z += h;
          ;
          long double temp_var_for_tac_27, temp_var_for_tac_28;
          temp_var_for_tac_27 = z * q1;

          temp_var_for_tac_28 = temp_var_for_tac_27 - q0;

          tmp = temp_var_for_tac_28;
          compute((Addr)&temp_var_for_tac_25,
                  {(Addr)&q1, (Addr) &(temp_var_for_const_24 = 1.0e11L)},
                  "/home/shijia/Public/testprogram/e_jnl.c_e.c:259:33");
          computeLdMul((Addr)&temp_var_for_tac_27, {(Addr)&z, (Addr)&q1},
                       "/home/shijia/Public/testprogram/e_jnl.c_e.c:263:19");
          computeLdSub((Addr)&temp_var_for_tac_28,
                       {(Addr)&temp_var_for_tac_27, (Addr)&q0},
                       "/home/shijia/Public/testprogram/e_jnl.c_e.c:263:24");
          AssignLd({(Addr)&tmp}, (Addr)&temp_var_for_tac_28,
                   "/home/shijia/Public/testprogram/e_jnl.c_e.c:263:15");
          ;
          long double temp_var_for_ext_10;
          temp_var_for_ext_10 = q1;
          AssignLd({(Addr)&temp_var_for_ext_10}, (Addr)&q1,
                   "/home/shijia/Public/testprogram/e_jnl.c_e.c:265:31");
          ; // q0
          /*(q0)(q1)(z)(q1)(z)(q1)*/
          q0 = temp_var_for_ext_10;
          AssignLd({(Addr)&q0}, (Addr)&temp_var_for_ext_10,
                   "/home/shijia/Public/testprogram/e_jnl.c_e.c:267:14");
          ;
          q1 = tmp;
          AssignLd({(Addr)&q1}, (Addr)&tmp,
                   "/home/shijia/Public/testprogram/e_jnl.c_e.c:268:14");
          ;
          temp_var_for_ext_9 = int temp_var_for_tac_29;
          int temp_var_for_const_25;
          temp_var_for_tac_29 = q1 < 1.0e11L;

          ;
        }
        m = n + n;
        for (t = zero, i = 2 * (n + k); i >= m; i -= 2) {
          long double temp_var_for_ext_11;
          long double temp_var_for_tac_30, temp_var_for_tac_31,
              temp_var_for_tac_32;
          long double temp_var_for_const_26, temp_var_for_const_27;
          temp_var_for_tac_30 = i / x;

          temp_var_for_tac_31 = temp_var_for_tac_30 - t;

          temp_var_for_tac_32 = one / temp_var_for_tac_31;

          temp_var_for_ext_11 = temp_var_for_tac_32;
          compute((Addr)&temp_var_for_tac_29,
                  {(Addr)&q1, (Addr) &(temp_var_for_const_25 = 1.0e11L)},
                  "/home/shijia/Public/testprogram/e_jnl.c_e.c:269:35");
          computeLdDiv((Addr)&temp_var_for_tac_30,
                       {(Addr) &(temp_var_for_const_26 = i), (Addr)&x},
                       "/home/shijia/Public/testprogram/e_jnl.c_e.c:274:42");
          computeLdSub((Addr)&temp_var_for_tac_31,
                       {(Addr)&temp_var_for_tac_30, (Addr)&t},
                       "/home/shijia/Public/testprogram/e_jnl.c_e.c:274:46");
          computeLdDiv((Addr)&temp_var_for_tac_32,
                       {(Addr) &(temp_var_for_const_27 = one),
                        (Addr)&temp_var_for_tac_31},
                       "/home/shijia/Public/testprogram/e_jnl.c_e.c:274:37");
          AssignLd({(Addr)&temp_var_for_ext_11}, (Addr)&temp_var_for_tac_32,
                   "/home/shijia/Public/testprogram/e_jnl.c_e.c:274:31");
          ; // t
          /*(t)(x)(i)(one)*/
          t = temp_var_for_ext_11;
          AssignLd({(Addr)&t}, (Addr)&temp_var_for_ext_11,
                   "/home/shijia/Public/testprogram/e_jnl.c_e.c:276:13");
          ;
        }

        a = t;
        AssignLd({(Addr)&a}, (Addr)&t,
                 "/home/shijia/Public/testprogram/e_jnl.c_e.c:279:11");
        ;
        long double temp_var_for_const_28;
        b = one;
        AssignLd({(Addr)&b}, (Addr) &(temp_var_for_const_28 = one),
                 "/home/shijia/Public/testprogram/e_jnl.c_e.c:280:11");
        ;
        /*  estimate log((2/x)^n*n!) = n*log(2/x)+n*ln(n)
         *  Hence, if n*(log(2n/x)) > ...
         *  single 8.8722839355e+01
         *  double 7.09782712893383973096e+02
         *  long double 1.1356523406294143949491931077970765006170e+04
         *  then recurrent value may overflow and the result is
         *  likely underflow to zero
         */
        long double temp_var_for_const_29;
        tmp = n;
        AssignLd({(Addr)&tmp}, (Addr) &(temp_var_for_const_29 = n),
                 "/home/shijia/Public/testprogram/e_jnl.c_e.c:289:13");
        ;
        long double temp_var_for_tac_33;
        long double temp_var_for_const_30;
        temp_var_for_tac_33 = two / x;

        v = temp_var_for_tac_33;
        computeLdDiv((Addr)&temp_var_for_tac_33,
                     {(Addr) &(temp_var_for_const_30 = two), (Addr)&x},
                     "/home/shijia/Public/testprogram/e_jnl.c_e.c:290:17");
        AssignLd({(Addr)&v}, (Addr)&temp_var_for_tac_33,
                 "/home/shijia/Public/testprogram/e_jnl.c_e.c:290:11");
        ;
        long double temp_var_for_ext_12;
        long double temp_var_for_tac_34, temp_var_for_tac_35;
        long double temp_var_for_const_31;
        long double temp_var_for_callexp_6;

        /*embed fun has found*/
        long double temp_var_for_callexp_7;

        temp_var_for_tac_34 = v * tmp;

        temp_var_for_callexp_6 = fabsl(temp_var_for_tac_34);
        temp_var_for_callexp_7 = __ieee754_logl(temp_var_for_callexp_6);
        temp_var_for_tac_35 = tmp * temp_var_for_callexp_7;

        temp_var_for_ext_12 = temp_var_for_tac_35;
        computeLdMul((Addr)&temp_var_for_tac_34, {(Addr)&v, (Addr)&tmp},
                     "/home/shijia/Public/testprogram/e_jnl.c_e.c:293:34 "
                     "<Spelling=/home/shijia/Public/testprogram/"
                     "e_jnl.c_e.c:293:52>");
        computeLdMul((Addr)&temp_var_for_tac_35,
                     {(Addr)&tmp,
                      (Addr) &(temp_var_for_const_31 = temp_var_for_callexp_7)},
                     "/home/shijia/Public/testprogram/e_jnl.c_e.c:293:17");
        AssignLd({(Addr)&temp_var_for_ext_12}, (Addr)&temp_var_for_tac_35,
                 "/home/shijia/Public/testprogram/e_jnl.c_e.c:292:29");
        ; // tmp
        /*(x)(two)(__ieee754_logl(__ieee754_fabsl(v * tmp)))(tmp)*/
        tmp = temp_var_for_ext_12;
        AssignLd({(Addr)&tmp}, (Addr)&temp_var_for_ext_12,
                 "/home/shijia/Public/testprogram/e_jnl.c_e.c:295:13");
        ;

        if (int temp_var_for_tac_36; int temp_var_for_const_32;
            temp_var_for_tac_36 =
                tmp < 1.1356523406294143949491931077970765006170e+04L;

            ) {
          for (i = n - 1, di = (long double)(i + i); i > 0; i--) {
            temp = b;
            compute(
                (Addr)&temp_var_for_tac_36,
                {(Addr)&tmp,
                 (Addr) &(temp_var_for_const_32 =
                              1.1356523406294143949491931077970765006170e+04L)},
                "/home/shijia/Public/testprogram/e_jnl.c_e.c:297:17");
            AssignLd({(Addr)&temp}, (Addr)&b,
                     "/home/shijia/Public/testprogram/e_jnl.c_e.c:299:18");
            ;
            b *= di;
            ;
            long double temp_var_for_ext_13;
            long double temp_var_for_tac_38, temp_var_for_tac_39;
            temp_var_for_tac_38 = b / x;

            temp_var_for_tac_39 = temp_var_for_tac_38 - a;

            temp_var_for_ext_13 = temp_var_for_tac_39;
            computeLdDiv((Addr)&temp_var_for_tac_38, {(Addr)&b, (Addr)&x},
                         "/home/shijia/Public/testprogram/e_jnl.c_e.c:302:37");
            computeLdSub((Addr)&temp_var_for_tac_39,
                         {(Addr)&temp_var_for_tac_38, (Addr)&a},
                         "/home/shijia/Public/testprogram/e_jnl.c_e.c:302:41");
            AssignLd({(Addr)&temp_var_for_ext_13}, (Addr)&temp_var_for_tac_39,
                     "/home/shijia/Public/testprogram/e_jnl.c_e.c:302:33");
            ; // b
            /*(di)(b)(a)(x)(b)*/
            b = temp_var_for_ext_13;
            AssignLd({(Addr)&b}, (Addr)&temp_var_for_ext_13,
                     "/home/shijia/Public/testprogram/e_jnl.c_e.c:304:15");
            ;
            long double temp_var_for_ext_14;
            temp_var_for_ext_14 = temp;
            AssignLd({(Addr)&temp_var_for_ext_14}, (Addr)&temp,
                     "/home/shijia/Public/testprogram/e_jnl.c_e.c:306:33");
            ; // a
            /*(a)(x)(b)(x)(b)(temp)*/
            a = temp_var_for_ext_14;
            AssignLd({(Addr)&a}, (Addr)&temp_var_for_ext_14,
                     "/home/shijia/Public/testprogram/e_jnl.c_e.c:308:15");
            ;
            di -= two;
            ;
          }
        } else {
          for (i = n - 1, long double temp_var_for_ext_15;
               temp_var_for_ext_15 = (long double)(i + i); // di
               /*(two)(di)(i)(i)(TempNull)*/
               di = temp_var_for_ext_15;
               i > 0; i--) {
            temp = b;
            b *= di;
            long double temp_var_for_ext_16;
            temp_var_for_ext_16 = b / x - a; // b
            /*(di)(b)(a)(x)(b)*/
            b = temp_var_for_ext_16;
            long double temp_var_for_ext_17;
            temp_var_for_ext_17 = temp; // a
            /*(a)(x)(b)(x)(b)(temp)*/
            a = temp_var_for_ext_17;
            di -= two;
            /* scale b to avoid spurious overflow */
            if (b > 1e100L) {
              a /= b;
              t /= b;
              long double temp_var_for_ext_18;
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
        long double temp_var_for_const_33;
        long double temp_var_for_callexp_8;

        temp_var_for_callexp_8 = __ieee754_j0l(x);
        z = temp_var_for_callexp_8;
        AssignLd({(Addr)&z},
                 (Addr) &(temp_var_for_const_33 = temp_var_for_callexp_8),
                 "/home/shijia/Public/testprogram/e_jnl.c_e.c:343:11");
        ;
        long double temp_var_for_const_34;
        long double temp_var_for_callexp_9;

        temp_var_for_callexp_9 = __ieee754_j1l(x);
        w = temp_var_for_callexp_9;
        AssignLd({(Addr)&w},
                 (Addr) &(temp_var_for_const_34 = temp_var_for_callexp_9),
                 "/home/shijia/Public/testprogram/e_jnl.c_e.c:344:11");
        ;
        if (int temp_var_for_tac_41;
            int temp_var_for_const_35, temp_var_for_const_36;
            long double temp_var_for_callexp_10;

            long double temp_var_for_callexp_11;

            temp_var_for_callexp_10 = fabsl(z);
            temp_var_for_callexp_11 = fabsl(w);
            temp_var_for_tac_41 =
                temp_var_for_callexp_10 >= temp_var_for_callexp_11;

            ) {
          long double temp_var_for_ext_19;
          long double temp_var_for_tac_42, temp_var_for_tac_43;
          temp_var_for_tac_42 = t * z;

          temp_var_for_tac_43 = temp_var_for_tac_42 / b;

          temp_var_for_ext_19 = temp_var_for_tac_43;
          compute((Addr)&temp_var_for_tac_41,
                  {(Addr) &(temp_var_for_const_36 = temp_var_for_callexp_10),
                   (Addr) &(temp_var_for_const_35 = temp_var_for_callexp_11)},
                  "/home/shijia/Public/testprogram/e_jnl.c_e.c:345:32");
          computeLdMul((Addr)&temp_var_for_tac_42, {(Addr)&t, (Addr)&z},
                       "/home/shijia/Public/testprogram/e_jnl.c_e.c:347:36");
          computeLdDiv((Addr)&temp_var_for_tac_43,
                       {(Addr)&temp_var_for_tac_42, (Addr)&b},
                       "/home/shijia/Public/testprogram/e_jnl.c_e.c:347:40");
          AssignLd({(Addr)&temp_var_for_ext_19}, (Addr)&temp_var_for_tac_43,
                   "/home/shijia/Public/testprogram/e_jnl.c_e.c:347:31");
          ; // b
          /*(b)(z)(t)*/
          b = temp_var_for_ext_19;
          AssignLd({(Addr)&b}, (Addr)&temp_var_for_ext_19,
                   "/home/shijia/Public/testprogram/e_jnl.c_e.c:349:13");
          ;
        }

        else {
          long double temp_var_for_ext_20;
          long double temp_var_for_tac_44, temp_var_for_tac_45;
          temp_var_for_tac_44 = t * w;

          temp_var_for_tac_45 = temp_var_for_tac_44 / a;

          temp_var_for_ext_20 = temp_var_for_tac_45;
          computeLdMul((Addr)&temp_var_for_tac_44, {(Addr)&t, (Addr)&w},
                       "/home/shijia/Public/testprogram/e_jnl.c_e.c:354:36");
          computeLdDiv((Addr)&temp_var_for_tac_45,
                       {(Addr)&temp_var_for_tac_44, (Addr)&a},
                       "/home/shijia/Public/testprogram/e_jnl.c_e.c:354:40");
          AssignLd({(Addr)&temp_var_for_ext_20}, (Addr)&temp_var_for_tac_45,
                   "/home/shijia/Public/testprogram/e_jnl.c_e.c:354:31");
          ; // b
          /*(b)(z)(t)(z)(t)(a)(w)(t)*/
          b = temp_var_for_ext_20;
          AssignLd({(Addr)&b}, (Addr)&temp_var_for_ext_20,
                   "/home/shijia/Public/testprogram/e_jnl.c_e.c:356:13");
          ;
        }
      }
    }
  }

  if (sgn) {
    long double temp_var_for_ext_21;
    long double temp_var_for_const_37;
    temp_var_for_ext_21 = (-(b));
    AssignLd({(Addr)&temp_var_for_ext_21},
             (Addr) &(temp_var_for_const_37 = (-(b))),
             "/home/shijia/Public/testprogram/e_jnl.c_e.c:364:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_21", (Addr)&temp_var_for_ext_21));
    callExp++; /*identify the function is  add move tmpShadow*/
    return (double temp_var_for_tac_46;
            double temp_var_for_const_38, temp_var_for_const_39;
            temp_var_for_tac_46 = 0.0 - 1;

            );
  }

  long double temp_var_for_ext_22;
  temp_var_for_ext_22 = b;
  computeDSub((Addr)&temp_var_for_tac_46,
              {(Addr) &(temp_var_for_const_39 = 0.0),
               (Addr) &(temp_var_for_const_38 = 1)},
              "/home/shijia/Public/testprogram/e_jnl.c_e.c:368:17");
  AssignLd({(Addr)&temp_var_for_ext_22}, (Addr)&b,
           "/home/shijia/Public/testprogram/e_jnl.c_e.c:372:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_22", (Addr)&temp_var_for_ext_22));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_22;
}

/* wrapper jn */
long double __jnl(int n, long double x) {
  if (isgreater(__ieee754_fabsl(x), X_TLOSS) && _LIB_VERSION != _IEEE_ &&
      _LIB_VERSION != _POSIX_)
  /* jn(n,|x|>X_TLOSS) */
  {
    long double temp_var_for_ext_23;
    long double temp_var_for_const_40;
    long double temp_var_for_callexp_12;

    temp_var_for_callexp_12 =
        __kernel_standard_l(n, x, 0.0l, KMATHERRL_JN_TLOSS);
    temp_var_for_ext_23 = temp_var_for_callexp_12;
    AssignLd({(Addr)&temp_var_for_ext_23},
             (Addr) &(temp_var_for_const_40 = temp_var_for_callexp_12),
             "/home/shijia/Public/testprogram/e_jnl.c_e.c:385:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_23", (Addr)&temp_var_for_ext_23));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_23;
  }

  long double temp_var_for_ext_24;
  long double temp_var_for_const_41;
  long double temp_var_for_callexp_13;

  temp_var_for_callexp_13 = __ieee754_jnl(n, x);
  temp_var_for_ext_24 = temp_var_for_callexp_13;
  AssignLd({(Addr)&temp_var_for_ext_24},
           (Addr) &(temp_var_for_const_41 = temp_var_for_callexp_13),
           "/home/shijia/Public/testprogram/e_jnl.c_e.c:393:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_24", (Addr)&temp_var_for_ext_24));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_24;
}

__typeof(__jnl) jnl __attribute__((weak, alias("__jnl")));

#endif
