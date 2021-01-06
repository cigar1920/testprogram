#include "../ScDebug/scdebug.h"
/* @(#)e_yn.c 5.1 93/09/24 */
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

/*
 * __ieee754_yn(n, x)
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
 *
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

double __ieee754_yn(int n, double x) {
  int32_t i, hx, ix, lx;
  int32_t sign;
  double a, b, temp;

  static const double invsqrtpi =
      5.64189583547756279280e-01; /* 0x3FE20DD7, 0x50429B6D */
  static const double zero = 0.00000000000000000000e+00;

  GET_DOUBLE_WORDS(hx, lx, x);
  ix = IC(0x7fffffff) & hx;
  /* if Y(n,NaN) is NaN */
  if ((ix | (((uint32_t)(lx | -lx)) >> 31)) > IC(0x7ff00000)) {
    double temp_var_for_ext_0;
    double temp_var_for_tac_0;
    temp_var_for_tac_0 = x + x;

    temp_var_for_ext_0 = temp_var_for_tac_0;
    computeDAdd((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_yn.c_e.c:57:28");
    AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_0,
            "/home/shijia/Public/testprogram/e_yn.c_e.c:57:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  if ((ix | lx) == 0) {
    double temp_var_for_ext_1;
    double temp_var_for_tac_1;
    double temp_var_for_const_0;
    temp_var_for_callexp_0 = __builtin_huge_val();
    temp_var_for_tac_1 = (-(temp_var_for_callexp_0)) + x;

    temp_var_for_ext_1 = temp_var_for_tac_1;
    computeDAdd((Addr)&temp_var_for_tac_1,
                {(Addr) &(temp_var_for_const_0 = (-(temp_var_for_callexp_0))),
                 (Addr)&x},
                "/home/shijia/Public/testprogram/e_yn.c_e.c:65:36");
    AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_1,
            "/home/shijia/Public/testprogram/e_yn.c_e.c:65:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return (0.0 - ar_for_e)xt_1;
  }
  /* -inf and overflow exception.  */;
  if (hx < 0) {
    double temp_var_for_ext_2;
    double temp_var_for_tac_2;
    double temp_var_for_const_1, temp_var_for_const_2;
    temp_var_for_tac_2 = zero / zero;

    temp_var_for_ext_2 = temp_var_for_tac_2;
    computeDDiv((Addr)&temp_var_for_tac_2,
                {(Addr) &(temp_var_for_const_2 = zero),
                 (Addr) &(temp_var_for_const_1 = zero)},
                "/home/shijia/Public/testprogram/e_yn.c_e.c:73:31");
    AssignD({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_2,
            "/home/shijia/Public/testprogram/e_yn.c_e.c:73:24");
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
    double temp_var_for_ext_3;
    double temp_var_for_const_3;
    double temp_var_for_callexp_1;

    temp_var_for_callexp_1 = __ieee754_y0(x);
    temp_var_for_ext_3 = temp_var_for_callexp_1;
    AssignD({(Addr)&temp_var_for_ext_3},
            (Addr) &(temp_var_for_const_3 = temp_var_for_callexp_1),
            "/home/shijia/Public/testprogram/e_yn.c_e.c:86:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_3;
  }

  if (n == 1) {
    double temp_var_for_ext_4;
    double temp_var_for_tac_3;
    double temp_var_for_const_4, temp_var_for_const_5;
    double temp_var_for_callexp_2;

    temp_var_for_callexp_2 = __ieee754_y1(x);
    temp_var_for_tac_3 = sign * temp_var_for_callexp_2;

    temp_var_for_ext_4 = temp_var_for_tac_3;
    computeDMul((Addr)&temp_var_for_tac_3,
                {(Addr) &(temp_var_for_const_5 = sign),
                 (Addr) &(temp_var_for_const_4 = temp_var_for_callexp_2)},
                "/home/shijia/Public/testprogram/e_yn.c_e.c:94:32");
    AssignD({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_3,
            "/home/shijia/Public/testprogram/e_yn.c_e.c:94:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_4;
  }

  if (ix == IC(0x7ff00000)) {
    double temp_var_for_ext_5;
    double temp_var_for_const_6;
    temp_var_for_ext_5 = zero;
    AssignD({(Addr)&temp_var_for_ext_5}, (Addr) &(temp_var_for_const_6 = zero),
            "/home/shijia/Public/testprogram/e_yn.c_e.c:102:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_5;
  }

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
    double c;
    double s;

    __ieee754_sincos(x, &s, &c);
    int temp_var_for_ext_6;
    temp_var_for_ext_6 = n & 3;
    switch (temp_var_for_ext_6) {
    case 0: {
      double temp_var_for_ext_7;
      double temp_var_for_tac_4;
      temp_var_for_tac_4 = s - c;

      temp_var_for_ext_7 = temp_var_for_tac_4;
      computeDSub((Addr)&temp_var_for_tac_4, {(Addr)&s, (Addr)&c},
                  "/home/shijia/Public/testprogram/e_yn.c_e.c:131:30");
      AssignD({(Addr)&temp_var_for_ext_7}, (Addr)&temp_var_for_tac_4,
              "/home/shijia/Public/testprogram/e_yn.c_e.c:131:26");
      ; // temp
      /*(0)(t)(1)(ar_for_e)(ar_for_e)(xt_2)(temp)(mp_var_for_ext_)(turn)(c)(s)*/
      temp = temp_var_for_ext_7;
      AssignD({(Addr)&temp}, (Addr)&temp_var_for_ext_7,
              "/home/shijia/Public/testprogram/e_yn.c_e.c:133:12");
      ;
    }

    break;
    case 1: {
      double temp_var_for_tac_5, temp_var_for_tac_6;
      double temp_var_for_const_7;
      temp_var_for_tac_5 = 0.0 - s;

      temp_var_for_tac_6 = temp_var_for_tac_5 - c;

      temp = temp_var_for_tac_6;
      computeDSub((Addr)&temp_var_for_tac_5,
                  {(Addr) &(temp_var_for_const_7 = 0.0), (Addr)&s},
                  "/home/shijia/Public/testprogram/e_yn.c_e.c:138:19");
      computeDSub((Addr)&temp_var_for_tac_6,
                  {(Addr)&temp_var_for_tac_5, (Addr)&c},
                  "/home/shijia/Public/testprogram/e_yn.c_e.c:138:24");
      AssignD({(Addr)&temp}, (Addr)&temp_var_for_tac_6,
              "/home/shijia/Public/testprogram/e_yn.c_e.c:138:12");
      ;
    }

    break;
    case 2: {
      double temp_var_for_tac_7, temp_var_for_tac_8;
      double temp_var_for_const_8;
      temp_var_for_tac_7 = 0.0 - s;

      temp_var_for_tac_8 = temp_var_for_tac_7 + c;

      temp = temp_var_for_tac_8;
      computeDSub((Addr)&temp_var_for_tac_7,
                  {(Addr) &(temp_var_for_const_8 = 0.0), (Addr)&s},
                  "/home/shijia/Public/testprogram/e_yn.c_e.c:143:19");
      computeDAdd((Addr)&temp_var_for_tac_8,
                  {(Addr)&temp_var_for_tac_7, (Addr)&c},
                  "/home/shijia/Public/testprogram/e_yn.c_e.c:143:24");
      AssignD({(Addr)&temp}, (Addr)&temp_var_for_tac_8,
              "/home/shijia/Public/testprogram/e_yn.c_e.c:143:12");
      ;
    }

    break;
    case 3: {
      double temp_var_for_tac_9;
      temp_var_for_tac_9 = s + c;

      temp = temp_var_for_tac_9;
      computeDAdd((Addr)&temp_var_for_tac_9, {(Addr)&s, (Addr)&c},
                  "/home/shijia/Public/testprogram/e_yn.c_e.c:148:16");
      AssignD({(Addr)&temp}, (Addr)&temp_var_for_tac_9,
              "/home/shijia/Public/testprogram/e_yn.c_e.c:148:12");
      ;
    }

    break;
    }
    double temp_var_for_tac_10, temp_var_for_tac_11;
    double temp_var_for_const_9, temp_var_for_const_10;
    double temp_var_for_callexp_3;

    temp_var_for_tac_10 = invsqrtpi * temp;

    temp_var_for_callexp_3 = __ieee754_sqrt(x);
    temp_var_for_tac_11 = temp_var_for_tac_10 / temp_var_for_callexp_3;

    b = temp_var_for_tac_11;
    computeDMul((Addr)&temp_var_for_tac_10,
                {(Addr) &(temp_var_for_const_9 = invsqrtpi), (Addr)&temp},
                "/home/shijia/Public/testprogram/e_yn.c_e.c:153:19");
    computeDDiv((Addr)&temp_var_for_tac_11,
                {(Addr)&temp_var_for_tac_10,
                 (Addr) &(temp_var_for_const_10 = temp_var_for_callexp_3)},
                "/home/shijia/Public/testprogram/e_yn.c_e.c:153:26");
    AssignD({(Addr)&b}, (Addr)&temp_var_for_tac_11,
            "/home/shijia/Public/testprogram/e_yn.c_e.c:153:7");
    ;
  } else {
    uint32_t high;

    double temp_var_for_const_11;
    double temp_var_for_callexp_4;

    temp_var_for_callexp_4 = __ieee754_y0(x);
    a = temp_var_for_callexp_4;
    AssignD({(Addr)&a},
            (Addr) &(temp_var_for_const_11 = temp_var_for_callexp_4),
            "/home/shijia/Public/testprogram/e_yn.c_e.c:157:7");
    ;
    double temp_var_for_const_12;
    double temp_var_for_callexp_5;

    temp_var_for_callexp_5 = __ieee754_y1(x);
    b = temp_var_for_callexp_5;
    AssignD({(Addr)&b},
            (Addr) &(temp_var_for_const_12 = temp_var_for_callexp_5),
            "/home/shijia/Public/testprogram/e_yn.c_e.c:158:7");
    ;
    /* quit if b is -inf */
    GET_HIGH_WORD(high, b);
    for (i = 1; i < n && high != UC(0xfff00000); i++) {
      temp = b;
      AssignD({(Addr)&temp}, (Addr)&b,
              "/home/shijia/Public/testprogram/e_yn.c_e.c:162:12");
      ;
      double temp_var_for_ext_8;
      double temp_var_for_tac_12, temp_var_for_tac_13, temp_var_for_tac_14,
          temp_var_for_tac_15;
      double temp_var_for_const_13, temp_var_for_const_14,
          temp_var_for_const_15;
      temp_var_for_tac_12 = i + i;

      temp_var_for_tac_13 = ((double)temp_var_for_tac_12) / x;

      temp_var_for_tac_14 = temp_var_for_tac_13 * b;

      temp_var_for_tac_15 = temp_var_for_tac_14 - a;

      temp_var_for_ext_8 = temp_var_for_tac_15;
      computeAdd((Addr)&temp_var_for_tac_12,
                 {(Addr) &(temp_var_for_const_14 = i),
                  (Addr) &(temp_var_for_const_13 = i)},
                 "/home/shijia/Public/testprogram/e_yn.c_e.c:164:40");
      computeDDiv(
          (Addr)&temp_var_for_tac_13,
          {(Addr) &(temp_var_for_const_15 = ((double)temp_var_for_tac_12)),
           (Addr)&x},
          "/home/shijia/Public/testprogram/e_yn.c_e.c:164:45");
      computeDMul((Addr)&temp_var_for_tac_14,
                  {(Addr)&temp_var_for_tac_13, (Addr)&b},
                  "/home/shijia/Public/testprogram/e_yn.c_e.c:164:50");
      computeDSub((Addr)&temp_var_for_tac_15,
                  {(Addr)&temp_var_for_tac_14, (Addr)&a},
                  "/home/shijia/Public/testprogram/e_yn.c_e.c:164:54");
      AssignD({(Addr)&temp_var_for_ext_8}, (Addr)&temp_var_for_tac_15,
              "/home/shijia/Public/testprogram/e_yn.c_e.c:164:26");
      ; // b
      /*(a)(b)(x)(i)(i)(TempNull)*/
      b = temp_var_for_ext_8;
      GET_HIGH_WORD(high, b);
      double temp_var_for_ext_9;
      temp_var_for_ext_9 = temp;
      AssignD({(Addr)&temp_var_for_ext_9}, (Addr)&temp,
              "/home/shijia/Public/testprogram/e_yn.c_e.c:169:26");
      ; // a
      /*(a)(b)(x)(i)(i)(TempNull)(b)(x)(i)(i)(TempNull)(x)(i)(i)(TempNull)(temp)*/
      a = temp_var_for_ext_9;
      AssignD({(Addr)&a}, (Addr)&temp_var_for_ext_9,
              "/home/shijia/Public/testprogram/e_yn.c_e.c:171:9");
      ;
    }
  }
  if (sign > 0) {
    double temp_var_for_ext_10;
    temp_var_for_ext_10 = b;
    AssignD({(Addr)&temp_var_for_ext_10}, (Addr)&b,
            "/home/shijia/Public/testprogram/e_yn.c_e.c:176:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_10", (Addr)&temp_var_for_ext_10));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_10;
  }

  double temp_var_for_ext_11;
  double temp_var_for_const_16;
  temp_var_for_ext_11 = (-(b));
  AssignD({(Addr)&temp_var_for_ext_11},
          (Addr) &(temp_var_for_const_16 = (-(b))),
          "/home/shijia/Public/testprogram/e_yn.c_e.c:184:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_11", (Addr)&temp_var_for_ext_11));
  callExp++; /*identify the function is  add move tmpShadow*/
  return (double temp_var_for_tac_16;
          double temp_var_for_const_17, temp_var_for_const_18;
          temp_var_for_tac_16 = 0.0 - 1;

          );
}

/* wrapper yn */
double __yn(int n, double x) {
  if ((islessequal(x, 0.0) || isgreater(x, X_TLOSS)) &&
      _LIB_VERSION != _IEEE_) {
    if (int temp_var_for_tac_17; int temp_var_for_const_19;
        temp_var_for_tac_17 = x < 0.0;

        ) {
      /* d = zero/(x-x) */
      feraiseexcept(FE_INVALID);
      double temp_var_for_ext_12;
      double temp_var_for_const_20;
      double temp_var_for_callexp_7;

      temp_var_for_callexp_6 = __builtin_huge_val();
      temp_var_for_callexp_7 = __kernel_standard(
          n, x, (-(temp_var_for_callexp_6)), KMATHERR_YN_MINUS);
      temp_var_for_ext_12 = temp_var_for_callexp_7;
      computeDSub((Addr)&temp_var_for_tac_16,
                  {(Addr) &(temp_var_for_const_18 = 0.0),
                   (Addr) &(temp_var_for_const_17 = 1)},
                  "/home/shijia/Public/testprogram/e_yn.c_e.c:187:15");
      compute((Addr)&temp_var_for_tac_17,
              {(Addr)&x, (Addr) &(temp_var_for_const_19 = 0.0)},
              "/home/shijia/Public/testprogram/e_yn.c_e.c:194:11");
      AssignD({(Addr)&temp_var_for_ext_12},
              (Addr) &(temp_var_for_const_20 = temp_var_for_callexp_7),
              "/home/shijia/Public/testprogram/e_yn.c_e.c:198:27");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_12", (Addr)&temp_var_for_ext_12));
      callExp++; /*identify the function is  add move tmpShadow(0.0 - /
     return) temp_var_for_ext_12;
                     } else {
     if (x == 0.0)
                             /* d = -one/(x-x) */
      {
        double temp_var_for_ext_13;
        double temp_var_for_const_21;
        double temp_var_for_callexp_9;

        temp_var_for_callexp_8 = __builtin_huge_val();
        temp_var_for_callexp_9 = __kernel_standard(
            n, x, (-(temp_var_for_callexp_8)), KMATHERR_YN_ZERO);
        temp_var_for_ext_13 = temp_var_for_callexp_9;
        AssignD({(Addr)&temp_var_for_ext_13},
                (Addr) &(temp_var_for_const_21 = temp_var_for_callexp_9),
                "/home/shijia/Public/testprogram/e_yn.c_e.c:209:29");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_13", (Addr)&temp_var_for_ext_13));
        callExp++; /*identify the function is  add move tmpShadow*(0.0 -
       return )temp_var_for_ext_13;
       }

                       else {
       if (_LIB_VERSION != _POSIX_)
                               /* yn(n,x>X_TLOSS) */
        {
          double temp_var_for_ext_14;
          double temp_var_for_const_22;
          double temp_var_for_callexp_10;

          temp_var_for_callexp_10 =
              __kernel_standard(n, x, 0.0, KMATHERR_YN_TLOSS);
          temp_var_for_ext_14 = temp_var_for_callexp_10;
          AssignD({(Addr)&temp_var_for_ext_14},
                  (Addr) &(temp_var_for_const_22 = temp_var_for_callexp_10),
                  "/home/shijia/Public/testprogram/e_yn.c_e.c:222:31");
          ;
          callExpStack.push(
              getReal("temp_var_for_ext_14", (Addr)&temp_var_for_ext_14));
          callExp++; /*identify the function is  add move tmpShadow*/
          return temp_var_for_ext_14;
        }
      }
    }
  }

  double temp_var_for_ext_15;
  double temp_var_for_const_23;
  double temp_var_for_callexp_11;

  temp_var_for_callexp_11 = __ieee754_yn(n, x);
  temp_var_for_ext_15 = temp_var_for_callexp_11;
  AssignD({(Addr)&temp_var_for_ext_15},
          (Addr) &(temp_var_for_const_23 = temp_var_for_callexp_11),
          "/home/shijia/Public/testprogram/e_yn.c_e.c:233:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_15", (Addr)&temp_var_for_ext_15));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_15;
}

__typeof(__yn) yn __attribute__((weak, alias("__yn")));
#ifdef __NO_LONG_DOUBLE_MATH
__typeof(__ynl) __ynl __attribute__((alias("__yn")));
__typeof(__ynl) ynl __attribute__((weak, alias("__ynl")));
#endif
