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
  if ((ix | (((uint32_t)(lx | -lx)) >> 31)) > IC(0x7ff00000))
    return x + x;
  if (n < 0) {
    n = -n;
    double temp_var_for_ext_0;
    temp_var_for_ext_0 = (0.0 - x);
    double temp_var_for_const_0;
    computeDSub((Addr)&temp_var_for_ext_0,
                {(Addr) &(temp_var_for_const_0 = 0.0), (Addr)&x},
                "/home/shijia/Public/testprogram/e_jn.c_e.c:67:24"); // x
    /*(x)(x)*/
    x = temp_var_for_ext_0;
    AssignD({(Addr)&x}, (Addr)&temp_var_for_ext_0,
            "/home/shijia/Public/testprogram/e_jn.c_e.c:69:7");
    hx ^= IC(0x80000000);
  }
  if (n == 0) {
    double temp_var_for_ext_1;
    temp_var_for_ext_1 = (__ieee754_j0(x));
    double temp_var_for_const_1;AssignD({(Addr)&temp_var_for_ext_1},(Addr)&(temp_var_for_const_1=__ieee754_j0(getFVbyShadow<int>((Addr)&x)),"/home/shijia/Public/testprogram/e_jn.c_e.c:74:24");
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }

  if (n == 1) {
    double temp_var_for_ext_2;
    temp_var_for_ext_2 = (__ieee754_j1(x));
    double temp_var_for_const_2;AssignD({(Addr)&temp_var_for_ext_2},(Addr)&(temp_var_for_const_2=__ieee754_j1(getFVbyShadow<int>((Addr)&x)),"/home/shijia/Public/testprogram/e_jn.c_e.c:82:24");
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  }

  sgn = (int)((n & 1) & (hx >> 31)); /* even n -- 0, odd n -- sign(x) */
  double temp_var_for_ext_3;
  temp_var_for_ext_3 = __ieee754_fabs(x);
  double temp_var_for_const_3;AssignD({(Addr)&temp_var_for_ext_3},(Addr)&(temp_var_for_const_3=__ieee754_fabs(getFVbyShadow<int>((Addr)&x)),"/home/shijia/Public/testprogram/e_jn.c_e.c:90:22"); // x
  /*(__ieee754_fabs(x))*/
  x = temp_var_for_ext_3;AssignD({(Addr)&x},(Addr)&temp_var_for_ext_3,"/home/shijia/Public/testprogram/e_jn.c_e.c:92:5");
  if ((ix | lx) == 0 || ix >= IC(0x7ff00000)) /* if x is 0 or inf */
    b = zero;
  else if ((double)n <= x) {
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
      switch (n & 3) {
      case 0:
        temp = c + s;
        break;
      case 1:
        temp = -c + s;
        break;
      case 2:
        temp = -c - s;
        break;
      case 3:
        temp = c - s;
        break;
      }
      b = invsqrtpi * temp / __ieee754_sqrt(x);
    } else {
      a = __ieee754_j0(x);
      b = __ieee754_j1(x);
      for (i = 1; i < n; i++) {
        temp = b;
        b = b * ((double)(i + i) / x) - a; /* avoid underflow */
        a = temp;
      }
    }
  } else {
    if (ix < IC(0x3e100000)) { /* x < 2**-29 */
      /* x is tiny, return the first Taylor expansion of J(n,x)
       * J(n,x) = 1/n!*(x/2)^n  - ...
       */
      if (n > 33) /* underflow */
        b = zero;
      else {
        temp = x * 0.5;
        b = temp;
        for (a = one, i = 2; i <= n; i++) {
          a *= (double)i; /* a = n! */
          b *= temp;      /* b = (x/2)^n */
        }
        b = b / a;
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

      w = (n + n) / (double)x;
      h = 2.0 / (double)x;
      q0 = w;
      z = w + h;
      q1 = w * z - 1.0;
      k = 1;
      while (q1 < 1.0e9) {
        k += 1;
        z += h;
        tmp = z * q1 - q0;
        q0 = q1;
        q1 = tmp;
      }
      m = n + n;
      for (t = zero, i = 2 * (n + k); i >= m; i -= 2)
        t = one / (i / x - t);
      a = t;
      b = one;
      /*  estimate log((2/x)^n*n!) = n*log(2/x)+n*ln(n)
       *  Hence, if n*(log(2n/x)) > ...
       *  single 8.8722839355e+01
       *  double 7.09782712893383973096e+02
       *  long double 1.1356523406294143949491931077970765006170e+04
       *  then recurrent value may overflow and the result is
       *  likely underflow to zero
       */
      tmp = n;
      v = two / x;
      tmp = tmp * __ieee754_log(__ieee754_fabs(v * tmp));
      if (tmp < 7.09782712893383973096e+02) {
        for (i = n - 1, di = (double)(i + i); i > 0; i--) {
          temp = b;
          b *= di;
          b = b / x - a;
          a = temp;
          di -= two;
        }
      } else {
        for (i = n - 1, di = (double)(i + i); i > 0; i--) {
          temp = b;
          b *= di;
          b = b / x - a;
          a = temp;
          di -= two;
          /* scale b to avoid spurious overflow */
          if (b > 1e100) {
            a /= b;
            t /= b;
            b = one;
          }
        }
      }
      /* j0() and j1() suffer enormous loss of precision at and
       * near zero; however, we know that their zero points never
       * coincide, so just choose the one further away from zero.
       */
      z = __ieee754_j0(x);
      w = __ieee754_j1(x);
      if (__ieee754_fabs(z) >= __ieee754_fabs(w))
        b = (t * z / b);
      else
        b = (t * w / a);
    }
  }
  if (sgn) {
    double temp_var_for_ext_4;
    temp_var_for_ext_4 = -b;
    AssignD({(Addr)&temp_var_for_ext_4}, (Addr) & (-(b)),
            "/home/shijia/Public/testprogram/e_jn.c_e.c:255:24");
    callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
    callExp++; /*identify the function is  add move tmpShadow*/
    return (0.0 - 4);
    double temp_var_for_const_4, temp_var_for_const_5;
    ;
    double temp_var_for_tac_0;
    computeDSub((Addr)&temp_var_for_tac_0,
                {(Addr) &(temp_var_for_const_5 = 0.0),
                 (Addr) &(temp_var_for_const_4 = 4)},
                "toString(biExpr->getExprLoc())");}

  double temp_var_for_ext_5;
  temp_var_for_ext_5 = b;AssignD({(Addr)&temp_var_for_ext_5},(Addr)&b,"/home/shijia/Public/testprogram/e_jn.c_e.c:262:22");
  callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_5;
}

/* wrapper jn */
double __jn(int n, double x) {
  if (isgreater(__ieee754_fabs(x), X_TLOSS) && _LIB_VERSION != _IEEE_ &&
      _LIB_VERSION != _POSIX_)
    /* jn(n,|x|>X_TLOSS) */
    return __kernel_standard(n, x, 0.0, KMATHERR_JN_TLOSS);

  double temp_var_for_ext_6;
  temp_var_for_ext_6 = __ieee754_jn(n, x);
  double temp_var_for_callexp_0 =
      __ieee754_jn((n), getFVbyShadow<double>((Addr)&x));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  AssignD({(Addr)&temp_var_for_ext_6}, ,
          "/home/shijia/Public/testprogram/e_jn.c_e.c:276:22");
  callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_6;
}

__typeof(__jn) jn __attribute__((weak, alias("__jn")));
#ifdef __NO_LONG_DOUBLE_MATH
__typeof(__jnl) __jnl __attribute__((alias("__jn")));
__typeof(__jnl) jnl __attribute__((weak, alias("__jnl")));
#endif
