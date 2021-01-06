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
  if (FLT_UWORD_IS_NAN(ix))
    return x + x;
  if (n < 0) {
    n = -n;
    float temp_var_for_ext_0;
    temp_var_for_ext_0 = (0.0 - x);
    float temp_var_for_const_0;
    computeFSub((Addr)&temp_var_for_ext_0,
                {(Addr) &(temp_var_for_const_0 = 0.0), (Addr)&x},
                "/home/shijia/Public/testprogram/e_jnf.c_e.c:41:24"); // x
    /*(x)(x)*/
    x = temp_var_for_ext_0;
    AssignF({(Addr)&x}, (Addr)&temp_var_for_ext_0,
            "/home/shijia/Public/testprogram/e_jnf.c_e.c:43:7");
    hx ^= IC(0x80000000);
  }
  if (n == 0) {
    float temp_var_for_ext_1;
    temp_var_for_ext_1 = (__ieee754_j0f(x));
    float temp_var_for_const_1;AssignF({(Addr)&temp_var_for_ext_1},(Addr)&(temp_var_for_const_1=__ieee754_j0f(getFVbyShadow<int>((Addr)&x)),"/home/shijia/Public/testprogram/e_jnf.c_e.c:48:24");
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }

  if (n == 1) {
    float temp_var_for_ext_2;
    temp_var_for_ext_2 = (__ieee754_j1f(x));
    float temp_var_for_const_2;AssignF({(Addr)&temp_var_for_ext_2},(Addr)&(temp_var_for_const_2=__ieee754_j1f(getFVbyShadow<int>((Addr)&x)),"/home/shijia/Public/testprogram/e_jnf.c_e.c:56:24");
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  }

  sgn = (int)((n & 1) & (hx >> 31)); /* even n -- 0, odd n -- sign(x) */
  float temp_var_for_ext_3;
  temp_var_for_ext_3 = __ieee754_fabsf(x);
  float temp_var_for_const_3;AssignF({(Addr)&temp_var_for_ext_3},(Addr)&(temp_var_for_const_3=__ieee754_fabsf(getFVbyShadow<int>((Addr)&x)),"/home/shijia/Public/testprogram/e_jnf.c_e.c:64:22"); // x
  /*(__ieee754_fabsf(x))*/
  x = temp_var_for_ext_3;AssignF({(Addr)&x},(Addr)&temp_var_for_ext_3,"/home/shijia/Public/testprogram/e_jnf.c_e.c:66:5");
  if (FLT_UWORD_IS_ZERO(ix) || FLT_UWORD_IS_INFINITE(ix))
    b = zero;
  else if ((float)n <= x) {
    /* Safe to use J(n+1,x)=2n/x *J(n,x)-J(n-1,x) */
    a = __ieee754_j0f(x);
    b = __ieee754_j1f(x);
    for (i = 1; i < n; i++) {
      temp = b;
      b = b * ((float)(i + i) / x) - a; /* avoid underflow */
      a = temp;
    }
  } else {
    if (ix < IC(0x30800000)) { /* x < 2**-29 */
      /* x is tiny, return the first Taylor expansion of J(n,x)
       * J(n,x) = 1/n!*(x/2)^n  - ...
       */
      if (n > 33) /* underflow */
        b = zero;
      else {
        temp = x * 0.5f;
        b = temp;
        for (a = one, i = 2; i <= n; i++) {
          a *= (float)i; /* a = n! */
          b *= temp;     /* b = (x/2)^n */
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
      float t, v;
      float q0, q1, h, tmp;
      int32_t k, m;

      w = (n + n) / (float)x;
      h = 2.0f / x;
      q0 = w;
      z = w + h;
      q1 = w * z - 1.0f;
      k = 1;
      while (q1 < 1.0e9f) {
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
      tmp = tmp * __ieee754_logf(__ieee754_fabsf(v * tmp));
      if (tmp < 8.8721679688e+01f) {
        for (i = n - 1, di = (float)(i + i); i > 0; i--) {
          temp = b;
          b *= di;
          b = b / x - a;
          a = temp;
          di -= two;
        }
      } else {
        for (i = n - 1, di = (float)(i + i); i > 0; i--) {
          temp = b;
          b *= di;
          b = b / x - a;
          a = temp;
          di -= two;
          /* scale b to avoid spurious overflow */
          if (b > 1e10f) {
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
      z = __ieee754_j0f(x);
      w = __ieee754_j1f(x);
      if (__ieee754_fabsf(z) >= __ieee754_fabsf(w))
        b = (t * z / b);
      else
        b = (t * w / a);
    }
  }
  if (sgn) {
    float temp_var_for_ext_4;
    temp_var_for_ext_4 = -b;
    AssignF({(Addr)&temp_var_for_ext_4}, (Addr) & (-(b)),
            "/home/shijia/Public/testprogram/e_jnf.c_e.c:194:24");
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

  float temp_var_for_ext_5;
  temp_var_for_ext_5 = b;AssignF({(Addr)&temp_var_for_ext_5},(Addr)&b,"/home/shijia/Public/testprogram/e_jnf.c_e.c:201:22");
  callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_5;
}

/* wrapper jn */
float __jnf(int n, float x) {
  if (isgreater(__ieee754_fabsf(x), X_TLOSS) && _LIB_VERSION != _IEEE_ &&
      _LIB_VERSION != _POSIX_)
    /* jn(n,|x|>X_TLOSS) */
    return __kernel_standard_f(n, x, 0.0f, KMATHERRF_JN_TLOSS);

  float temp_var_for_ext_6;
  temp_var_for_ext_6 = __ieee754_jnf(n, x);
  float temp_var_for_callexp_0 =
      __ieee754_jnf((n), getFVbyShadow<float>((Addr)&x));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  AssignF({(Addr)&temp_var_for_ext_6}, ,
          "/home/shijia/Public/testprogram/e_jnf.c_e.c:215:22");
  callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_6;
}

__typeof(__jnf) jnf __attribute__((weak, alias("__jnf")));
