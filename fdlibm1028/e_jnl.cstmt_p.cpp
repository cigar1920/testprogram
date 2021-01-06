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

  GET_LDOUBLE_WORDS(se, i0, i1, x);
  ix = se & 0x7fff;

  /* if J(n,NaN) is NaN */
  if ((ix == 0x7fff) && ((i0 & IC(0x7fffffff)) != 0))
    return x + x;
  if (n < 0) {
    n = -n;
    long double temp_var_for_ext_0;
    temp_var_for_ext_0 = (0.0 - x);
    long double temp_var_for_const_0;
    computeLdSub((Addr)&temp_var_for_ext_0,
                 {(Addr) &(temp_var_for_const_0 = 0.0), (Addr)&x},
                 "/home/shijia/Public/testprogram/e_jnl.c_e.c:90:24"); // x
    /*(x)(x)*/
    x = temp_var_for_ext_0;
    AssignLd({(Addr)&x}, (Addr)&temp_var_for_ext_0,
             "/home/shijia/Public/testprogram/e_jnl.c_e.c:92:7");
    se ^= 0x8000;
  }
  if (n == 0) {
    long double temp_var_for_ext_1;
    temp_var_for_ext_1 = (__ieee754_j0l(x));
    long double temp_var_for_const_1;AssignLd({(Addr)&temp_var_for_ext_1},(Addr)&(temp_var_for_const_1=__ieee754_j0l(getFVbyShadow<int>((Addr)&x)),"/home/shijia/Public/testprogram/e_jnl.c_e.c:97:24");
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }

  if (n == 1) {
    long double temp_var_for_ext_2;
    temp_var_for_ext_2 = (__ieee754_j1l(x));
    long double temp_var_for_const_2;AssignLd({(Addr)&temp_var_for_ext_2},(Addr)&(temp_var_for_const_2=__ieee754_j1l(getFVbyShadow<int>((Addr)&x)),"/home/shijia/Public/testprogram/e_jnl.c_e.c:105:24");
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  }

  sgn = (int)((n & 1) & (se >> 15)); /* even n -- 0, odd n -- sign(x) */
  long double temp_var_for_ext_3;
  temp_var_for_ext_3 = __ieee754_fabsl(x);
  long double temp_var_for_const_3;AssignLd({(Addr)&temp_var_for_ext_3},(Addr)&(temp_var_for_const_3=__ieee754_fabsl(getFVbyShadow<int>((Addr)&x)),"/home/shijia/Public/testprogram/e_jnl.c_e.c:113:22"); // x
  /*(__ieee754_fabsl(x))*/
  x = temp_var_for_ext_3;AssignLd({(Addr)&x},(Addr)&temp_var_for_ext_3,"/home/shijia/Public/testprogram/e_jnl.c_e.c:115:5");
  if ((ix | i0 | i1) == 0 || ix >= 0x7fff)
    /* if x is 0 or inf */
    b = zero;
  else if ((long double)n <= x) {
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
      b = invsqrtpi * temp / __ieee754_sqrtl(x);
    } else {
      a = __ieee754_j0l(x);
      b = __ieee754_j1l(x);
      for (i = 1; i < n; i++) {
        temp = b;
        b = b * ((long double)(i + i) / x) - a; /* avoid underflow */
        a = temp;
      }
    }
  } else {
    if (ix < 0x3fde) { /* x < 2**-33 */
                       /* x is tiny, return the first Taylor expansion of J(n,x)
                        * J(n,x) = 1/n!*(x/2)^n  - ...
                        */
      if (n >= 400)    /* underflow, result < 10^-4952 */
        b = zero;
      else {
        temp = x * 0.5;
        b = temp;
        for (a = one, i = 2; i <= n; i++) {
          a *= (long double)i; /* a = n! */
          b *= temp;           /* b = (x/2)^n */
        }
        b = b / a;
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

      w = (n + n) / (long double)x;
      h = 2.0L / (long double)x;
      q0 = w;
      z = w + h;
      q1 = w * z - 1.0L;
      k = 1;
      while (q1 < 1.0e11L) {
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
      tmp = tmp * __ieee754_logl(__ieee754_fabsl(v * tmp));

      if (tmp < 1.1356523406294143949491931077970765006170e+04L) {
        for (i = n - 1, di = (long double)(i + i); i > 0; i--) {
          temp = b;
          b *= di;
          b = b / x - a;
          a = temp;
          di -= two;
        }
      } else {
        for (i = n - 1, di = (long double)(i + i); i > 0; i--) {
          temp = b;
          b *= di;
          b = b / x - a;
          a = temp;
          di -= two;
          /* scale b to avoid spurious overflow */
          if (b > 1e100L) {
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
      z = __ieee754_j0l(x);
      w = __ieee754_j1l(x);
      if (__ieee754_fabsl(z) >= __ieee754_fabsl(w))
        b = (t * z / b);
      else
        b = (t * w / a);
    }
  }
  if (sgn) {
    long double temp_var_for_ext_4;
    temp_var_for_ext_4 = -b;
    AssignLd({(Addr)&temp_var_for_ext_4}, (Addr) & (-(b)),
             "/home/shijia/Public/testprogram/e_jnl.c_e.c:287:24");
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

  long double temp_var_for_ext_5;
  temp_var_for_ext_5 = b;AssignLd({(Addr)&temp_var_for_ext_5},(Addr)&b,"/home/shijia/Public/testprogram/e_jnl.c_e.c:294:22");
  callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_5;
}

/* wrapper jn */
long double __jnl(int n, long double x) {
  if (isgreater(__ieee754_fabsl(x), X_TLOSS) && _LIB_VERSION != _IEEE_ &&
      _LIB_VERSION != _POSIX_)
    /* jn(n,|x|>X_TLOSS) */
    return __kernel_standard_l(n, x, 0.0l, KMATHERRL_JN_TLOSS);

  long double temp_var_for_ext_6;
  temp_var_for_ext_6 = __ieee754_jnl(n, x);
  long double temp_var_for_callexp_0 =
      __ieee754_jnl((n), getFVbyShadow<long double>((Addr)&x));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  AssignLd({(Addr)&temp_var_for_ext_6}, ,
           "/home/shijia/Public/testprogram/e_jnl.c_e.c:308:22");
  callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_6;
}

__typeof(__jnl) jnl __attribute__((weak, alias("__jnl")));

#endif
