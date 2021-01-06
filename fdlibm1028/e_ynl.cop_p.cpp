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
 * __ieee754_yn(n, x)
 * floating point Bessel's function of the 2nd kind
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

long double __ieee754_ynl(int n, long double x) {
  uint32_t se, i0, i1;
  int32_t i, ix;
  int sign;
  long double a, b, temp;

  static const long double invsqrtpi = 5.64189583547756286948079e-1L;
  static const long double zero = 0.0L;

  long double temp_var_for_const_0;
  ew_u.value = x;
  AssignLd({(Addr) &(temp_var_for_const_0 = ew_u.value)}, (Addr)&x,
           "/home/shijia/Public/testprogram/e_ynl.c_e.c:74:3 "
           "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
  ;
  ix = se & IEEE854_LONG_DOUBLE_MAXEXP;
  /* if Y(n,NaN) is NaN */
  if ((ix == IEEE854_LONG_DOUBLE_MAXEXP) && ((i0 & IC(0x7fffffff)) != 0)) {
    long double temp_var_for_ext_0;
    long double temp_var_for_tac_0;
    temp_var_for_tac_0 = x + x;

    temp_var_for_ext_0 = temp_var_for_tac_0;
    computeLdAdd((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&x},
                 "/home/shijia/Public/testprogram/e_ynl.c_e.c:79:28");
    AssignLd({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_0,
             "/home/shijia/Public/testprogram/e_ynl.c_e.c:79:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  if ((ix | i0 | i1) == 0) {
    long double temp_var_for_ext_1;
    long double temp_var_for_tac_1;
    long double temp_var_for_const_1;
    temp_var_for_callexp_0 = __builtin_huge_vall();
    temp_var_for_tac_1 = (-(temp_var_for_callexp_0)) + x;

    temp_var_for_ext_1 = temp_var_for_tac_1;
    computeLdAdd((Addr)&temp_var_for_tac_1,
                 {(Addr) &(temp_var_for_const_1 = (-(temp_var_for_callexp_0))),
                  (Addr)&x},
                 "/home/shijia/Public/testprogram/e_ynl.c_e.c:87:37");
    AssignLd({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_1,
             "/home/shijia/Public/testprogram/e_ynl.c_e.c:87:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return (0.0 - var_for_e)xt_1;
  }
  /* -inf and overflow exception.  */
  if (se & 0x8000) {
    long double temp_var_for_ext_2;
    long double temp_var_for_tac_2, temp_var_for_tac_3;
    long double temp_var_for_const_2, temp_var_for_const_3;
    temp_var_for_tac_2 = zero * x;

    temp_var_for_tac_3 = zero / temp_var_for_tac_2;

    temp_var_for_ext_2 = temp_var_for_tac_3;
    computeLdMul((Addr)&temp_var_for_tac_2,
                 {(Addr) &(temp_var_for_const_2 = zero), (Addr)&x},
                 "/home/shijia/Public/testprogram/e_ynl.c_e.c:95:39");
    computeLdDiv(
        (Addr)&temp_var_for_tac_3,
        {(Addr) &(temp_var_for_const_3 = zero), (Addr)&temp_var_for_tac_2},
        "/home/shijia/Public/testprogram/e_ynl.c_e.c:95:31");
    AssignLd({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_3,
             "/home/shijia/Public/testprogram/e_ynl.c_e.c:95:24");
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
    long double temp_var_for_ext_3;
    long double temp_var_for_const_4;
    long double temp_var_for_callexp_1;

    temp_var_for_callexp_1 = __ieee754_y0l(x);
    temp_var_for_ext_3 = temp_var_for_callexp_1;
    AssignLd({(Addr)&temp_var_for_ext_3},
             (Addr) &(temp_var_for_const_4 = temp_var_for_callexp_1),
             "/home/shijia/Public/testprogram/e_ynl.c_e.c:108:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_3;
  }

  if (n == 1) {
    long double temp_var_for_ext_4;
    long double temp_var_for_tac_4;
    long double temp_var_for_const_5, temp_var_for_const_6;
    long double temp_var_for_callexp_2;

    temp_var_for_callexp_2 = __ieee754_y1l(x);
    temp_var_for_tac_4 = sign * temp_var_for_callexp_2;

    temp_var_for_ext_4 = temp_var_for_tac_4;
    computeLdMul((Addr)&temp_var_for_tac_4,
                 {(Addr) &(temp_var_for_const_6 = sign),
                  (Addr) &(temp_var_for_const_5 = temp_var_for_callexp_2)},
                 "/home/shijia/Public/testprogram/e_ynl.c_e.c:116:32");
    AssignLd({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_4,
             "/home/shijia/Public/testprogram/e_ynl.c_e.c:116:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_4;
  }

  if (ix == IEEE854_LONG_DOUBLE_MAXEXP) {
    long double temp_var_for_ext_5;
    long double temp_var_for_const_7;
    temp_var_for_ext_5 = zero;
    AssignLd({(Addr)&temp_var_for_ext_5}, (Addr) &(temp_var_for_const_7 = zero),
             "/home/shijia/Public/testprogram/e_ynl.c_e.c:124:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_5;
  }

  if (ix >= 0x412D) { /* x > 2**302 */

    /* ??? See comment above on the possible futility of this.  */

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
    int temp_var_for_ext_6;
    temp_var_for_ext_6 = n & 3;
    switch (temp_var_for_ext_6) {
    case 0: {
      long double temp_var_for_ext_7;
      long double temp_var_for_tac_5;
      temp_var_for_tac_5 = s - c;

      temp_var_for_ext_7 = temp_var_for_tac_5;
      computeLdSub((Addr)&temp_var_for_tac_5, {(Addr)&s, (Addr)&c},
                   "/home/shijia/Public/testprogram/e_ynl.c_e.c:156:30");
      AssignLd({(Addr)&temp_var_for_ext_7}, (Addr)&temp_var_for_tac_5,
               "/home/shijia/Public/testprogram/e_ynl.c_e.c:156:26");
      ; // temp
      /*(0)(t)(1)(var_for_e)(var_for_e)(_)(for_)(temp)(_)(for_)(emp_var_for_ext_)(etur)(c)(s)*/
      temp = temp_var_for_ext_7;
      AssignLd({(Addr)&temp}, (Addr)&temp_var_for_ext_7,
               "/home/shijia/Public/testprogram/e_ynl.c_e.c:158:12");
      ;
    }

    break;
    case 1: {
      long double temp_var_for_tac_6, temp_var_for_tac_7;
      long double temp_var_for_const_8;
      temp_var_for_tac_6 = 0.0 - s;

      temp_var_for_tac_7 = temp_var_for_tac_6 - c;

      temp = temp_var_for_tac_7;
      computeLdSub((Addr)&temp_var_for_tac_6,
                   {(Addr) &(temp_var_for_const_8 = 0.0), (Addr)&s},
                   "/home/shijia/Public/testprogram/e_ynl.c_e.c:163:19");
      computeLdSub((Addr)&temp_var_for_tac_7,
                   {(Addr)&temp_var_for_tac_6, (Addr)&c},
                   "/home/shijia/Public/testprogram/e_ynl.c_e.c:163:24");
      AssignLd({(Addr)&temp}, (Addr)&temp_var_for_tac_7,
               "/home/shijia/Public/testprogram/e_ynl.c_e.c:163:12");
      ;
    }

    break;
    case 2: {
      long double temp_var_for_tac_8, temp_var_for_tac_9;
      long double temp_var_for_const_9;
      temp_var_for_tac_8 = 0.0 - s;

      temp_var_for_tac_9 = temp_var_for_tac_8 + c;

      temp = temp_var_for_tac_9;
      computeLdSub((Addr)&temp_var_for_tac_8,
                   {(Addr) &(temp_var_for_const_9 = 0.0), (Addr)&s},
                   "/home/shijia/Public/testprogram/e_ynl.c_e.c:168:19");
      computeLdAdd((Addr)&temp_var_for_tac_9,
                   {(Addr)&temp_var_for_tac_8, (Addr)&c},
                   "/home/shijia/Public/testprogram/e_ynl.c_e.c:168:24");
      AssignLd({(Addr)&temp}, (Addr)&temp_var_for_tac_9,
               "/home/shijia/Public/testprogram/e_ynl.c_e.c:168:12");
      ;
    }

    break;
    case 3: {
      long double temp_var_for_tac_10;
      temp_var_for_tac_10 = s + c;

      temp = temp_var_for_tac_10;
      computeLdAdd((Addr)&temp_var_for_tac_10, {(Addr)&s, (Addr)&c},
                   "/home/shijia/Public/testprogram/e_ynl.c_e.c:173:16");
      AssignLd({(Addr)&temp}, (Addr)&temp_var_for_tac_10,
               "/home/shijia/Public/testprogram/e_ynl.c_e.c:173:12");
      ;
    }

    break;
    }
    long double temp_var_for_tac_11, temp_var_for_tac_12;
    long double temp_var_for_const_10, temp_var_for_const_11;
    long double temp_var_for_callexp_3;

    temp_var_for_tac_11 = invsqrtpi * temp;

    temp_var_for_callexp_3 = __ieee754_sqrtl(x);
    temp_var_for_tac_12 = temp_var_for_tac_11 / temp_var_for_callexp_3;

    b = temp_var_for_tac_12;
    computeLdMul((Addr)&temp_var_for_tac_11,
                 {(Addr) &(temp_var_for_const_10 = invsqrtpi), (Addr)&temp},
                 "/home/shijia/Public/testprogram/e_ynl.c_e.c:178:19");
    computeLdDiv((Addr)&temp_var_for_tac_12,
                 {(Addr)&temp_var_for_tac_11,
                  (Addr) &(temp_var_for_const_11 = temp_var_for_callexp_3)},
                 "/home/shijia/Public/testprogram/e_ynl.c_e.c:178:26");
    AssignLd({(Addr)&b}, (Addr)&temp_var_for_tac_12,
             "/home/shijia/Public/testprogram/e_ynl.c_e.c:178:7");
    ;
  } else {
    long double temp_var_for_const_12;
    long double temp_var_for_callexp_4;

    temp_var_for_callexp_4 = __ieee754_y0l(x);
    a = temp_var_for_callexp_4;
    AssignLd({(Addr)&a},
             (Addr) &(temp_var_for_const_12 = temp_var_for_callexp_4),
             "/home/shijia/Public/testprogram/e_ynl.c_e.c:180:7");
    ;
    long double temp_var_for_const_13;
    long double temp_var_for_callexp_5;

    temp_var_for_callexp_5 = __ieee754_y1l(x);
    b = temp_var_for_callexp_5;
    AssignLd({(Addr)&b},
             (Addr) &(temp_var_for_const_13 = temp_var_for_callexp_5),
             "/home/shijia/Public/testprogram/e_ynl.c_e.c:181:7");
    ;
    /* quit if b is -inf */
    long double temp_var_for_const_14;
    ew_u.value = b;
    AssignLd({(Addr) &(temp_var_for_const_14 = ew_u.value)}, (Addr)&b,
             "/home/shijia/Public/testprogram/e_ynl.c_e.c:183:5 "
             "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
    ;
    /* Use 0xffffffff since GET_LDOUBLE_WORDS sign-extends SE.  */
    for (i = 1; i < n && se != UC(0xffffffff); i++) {
      temp = b;
      AssignLd({(Addr)&temp}, (Addr)&b,
               "/home/shijia/Public/testprogram/e_ynl.c_e.c:186:12");
      ;
      long double temp_var_for_ext_8;
      long double temp_var_for_tac_13, temp_var_for_tac_14, temp_var_for_tac_15,
          temp_var_for_tac_16;
      long double temp_var_for_const_15, temp_var_for_const_16,
          temp_var_for_const_17;
      temp_var_for_tac_13 = i + i;

      temp_var_for_tac_14 = ((long double)temp_var_for_tac_13) / x;

      temp_var_for_tac_15 = temp_var_for_tac_14 * b;

      temp_var_for_tac_16 = temp_var_for_tac_15 - a;

      temp_var_for_ext_8 = temp_var_for_tac_16;
      computeAdd((Addr)&temp_var_for_tac_13,
                 {(Addr) &(temp_var_for_const_16 = i),
                  (Addr) &(temp_var_for_const_15 = i)},
                 "/home/shijia/Public/testprogram/e_ynl.c_e.c:188:45");
      computeLdDiv(
          (Addr)&temp_var_for_tac_14,
          {(Addr) &(temp_var_for_const_17 = ((long double)temp_var_for_tac_13)),
           (Addr)&x},
          "/home/shijia/Public/testprogram/e_ynl.c_e.c:188:50");
      computeLdMul((Addr)&temp_var_for_tac_15,
                   {(Addr)&temp_var_for_tac_14, (Addr)&b},
                   "/home/shijia/Public/testprogram/e_ynl.c_e.c:188:55");
      computeLdSub((Addr)&temp_var_for_tac_16,
                   {(Addr)&temp_var_for_tac_15, (Addr)&a},
                   "/home/shijia/Public/testprogram/e_ynl.c_e.c:188:59");
      AssignLd({(Addr)&temp_var_for_ext_8}, (Addr)&temp_var_for_tac_16,
               "/home/shijia/Public/testprogram/e_ynl.c_e.c:188:26");
      ; // b
      /*(a)(b)(x)(i)(i)(TempNull)*/
      b = temp_var_for_ext_8;
      long double temp_var_for_const_18;
      ew_u.value = b;
      AssignLd({(Addr) &(temp_var_for_const_18 = ew_u.value)}, (Addr)&b,
               "/home/shijia/Public/testprogram/e_ynl.c_e.c:191:7 "
               "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
      ;
      a = temp;
      AssignLd({(Addr)&a}, (Addr)&temp,
               "/home/shijia/Public/testprogram/e_ynl.c_e.c:192:9");
      ;
    }
  }
  if (sign > 0) {
    long double temp_var_for_ext_9;
    temp_var_for_ext_9 = b;
    AssignLd({(Addr)&temp_var_for_ext_9}, (Addr)&b,
             "/home/shijia/Public/testprogram/e_ynl.c_e.c:197:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_9;
  }

  long double temp_var_for_ext_10;
  long double temp_var_for_const_19;
  temp_var_for_ext_10 = (-(b));
  AssignLd({(Addr)&temp_var_for_ext_10},
           (Addr) &(temp_var_for_const_19 = (-(b))),
           "/home/shijia/Public/testprogram/e_ynl.c_e.c:204:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_10", (Addr)&temp_var_for_ext_10));
  callExp++; /*identify the function is  add move tmpShadow*/
  return (double temp_var_for_tac_17;
          double temp_var_for_const_20, temp_var_for_const_21;
          temp_var_for_tac_17 = 0.0 - 0;

          );
}

/* wrapper yn */
long double __ynl(int n, long double x) {
  if ((islessequal(x, 0.0) || isgreater(x, X_TLOSS)) &&
      _LIB_VERSION != _IEEE_) {
    if (int temp_var_for_tac_18; int temp_var_for_const_22;
        temp_var_for_tac_18 = x < 0.0;

        ) {
      /* d = zero/(x-x) */
      feraiseexcept(FE_INVALID);
      long double temp_var_for_ext_11;
      long double temp_var_for_const_23;
      long double temp_var_for_callexp_7;

      temp_var_for_callexp_6 = __builtin_huge_vall();
      temp_var_for_callexp_7 = __kernel_standard_l(
          n, x, (-(temp_var_for_callexp_6)), KMATHERRL_YN_MINUS);
      temp_var_for_ext_11 = temp_var_for_callexp_7;
      computeDSub((Addr)&temp_var_for_tac_17,
                  {(Addr) &(temp_var_for_const_21 = 0.0),
                   (Addr) &(temp_var_for_const_20 = 0)},
                  "/home/shijia/Public/testprogram/e_ynl.c_e.c:207:15");
      compute((Addr)&temp_var_for_tac_18,
              {(Addr)&x, (Addr) &(temp_var_for_const_22 = 0.0)},
              "/home/shijia/Public/testprogram/e_ynl.c_e.c:214:11");
      AssignLd({(Addr)&temp_var_for_ext_11},
               (Addr) &(temp_var_for_const_23 = temp_var_for_callexp_7),
               "/home/shijia/Public/testprogram/e_ynl.c_e.c:218:27");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_11", (Addr)&temp_var_for_ext_11));
      callExp++; /*identify the function is  add move tmpShad(0.0 - w*/
retur)n temp_var_for_ext_11;
    } else {
      if (int temp_var_for_tac_19; int temp_var_for_const_24;
          temp_var_for_tac_19 = x == 0.0;

          )
      /* d = -one/(x-x) */
      {
        long double temp_var_for_ext_12;
        long double temp_var_for_const_25;
        long double temp_var_for_callexp_9;

        temp_var_for_callexp_8 = __builtin_huge_vall();
        temp_var_for_callexp_9 = __kernel_standard_l(
            n, x, (-(temp_var_for_callexp_8)), KMATHERRL_YN_ZERO);
        temp_var_for_ext_12 = temp_var_for_callexp_9;
        compute((Addr)&temp_var_for_tac_19,
                {(Addr)&x, (Addr) &(temp_var_for_const_24 = 0.0)},
                "/home/shijia/Public/testprogram/e_ynl.c_e.c:225:13");
        AssignLd({(Addr)&temp_var_for_ext_12},
                 (Addr) &(temp_var_for_const_25 = temp_var_for_callexp_9),
                 "/home/shijia/Public/testprogram/e_ynl.c_e.c:229:29");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_12", (Addr)&temp_var_for_ext_12));
        callExp++; /*identify the function is  add move tmpShado(0.0 - */
return) temp_var_for_ext_12;
      }

      else {
        if (_LIB_VERSION != _POSIX_)
        /* yn(n,x>X_TLOSS) */
        {
          long double temp_var_for_ext_13;
          long double temp_var_for_const_26;
          long double temp_var_for_callexp_10;

          temp_var_for_callexp_10 =
              __kernel_standard_l(n, x, 0.0L, KMATHERRL_YN_TLOSS);
          temp_var_for_ext_13 = temp_var_for_callexp_10;
          AssignLd({(Addr)&temp_var_for_ext_13},
                   (Addr) &(temp_var_for_const_26 = temp_var_for_callexp_10),
                   "/home/shijia/Public/testprogram/e_ynl.c_e.c:242:31");
          ;
          callExpStack.push(
              getReal("temp_var_for_ext_13", (Addr)&temp_var_for_ext_13));
          callExp++; /*identify the function is  add move tmpShadow*/
          return temp_var_for_ext_13;
        }
      }
    }
  }

  long double temp_var_for_ext_14;
  long double temp_var_for_const_27;
  double temp_var_for_callexp_11;

  temp_var_for_callexp_11 = __ieee754_yn(n, x);
  temp_var_for_ext_14 = temp_var_for_callexp_11;
  AssignLd({(Addr)&temp_var_for_ext_14},
           (Addr) &(temp_var_for_const_27 = temp_var_for_callexp_11),
           "/home/shijia/Public/testprogram/e_ynl.c_e.c:254:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_14", (Addr)&temp_var_for_ext_14));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_14;
}

__typeof(__ynl) ynl __attribute__((weak, alias("__ynl")));

#endif
