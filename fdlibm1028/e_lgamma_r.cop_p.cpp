#include "../ScDebug/scdebug.h"
/* @(#)e_lgamma_r.c 1.3 95/01/18 */
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

/* __ieee754_lgamma_r(x, signgamp)
 * Reentrant version of the logarithm of the Gamma function
 * with user provide pointer for the sign of Gamma(x).
 *
 * Method:
 *   1. Argument Reduction for 0 < x <= 8
 *	Since gamma(1+s)=s*gamma(s), for x in [0,8], we may
 *	reduce x to a number in [1.5,2.5] by
 *		lgamma(1+s) = log(s) + lgamma(s)
 *	for example,
 *		lgamma(7.3) = log(6.3) + lgamma(6.3)
 *			    = log(6.3*5.3) + lgamma(5.3)
 *			    = log(6.3*5.3*4.3*3.3*2.3) + lgamma(2.3)
 *   2. Polynomial approximation of lgamma around its
 *	minimun ymin=1.461632144968362245 to maintain monotonicity.
 *	On [ymin-0.23, ymin+0.27] (i.e., [1.23164,1.73163]), use
 *		Let z = x-ymin;
 *		lgamma(x) = -1.214862905358496078218 + z^2*poly(z)
 *	where
 *		poly(z) is a 14 degree polynomial.
 *   2. Rational approximation in the primary interval [2,3]
 *	We use the following approximation:
 *		s = x-2.0;
 *		lgamma(x) = 0.5*s + s*P(s)/Q(s)
 *	with accuracy
 *		|P/Q - (lgamma(x)-0.5s)| < 2**-61.71
 *	Our algorithms are based on the following observation
 *
 *                             zeta(2)-1    2    zeta(3)-1    3
 * lgamma(2+s) = s*(1-Euler) + --------- * s  -  --------- * s  + ...
 *                                 2                 3
 *
 *	where Euler = 0.5771... is the Euler constant, which is very
 *	close to 0.5.
 *
 *   3. For x>=8, we have
 *	lgamma(x)~(x-0.5)log(x)-x+0.5*log(2pi)+1/(12x)-1/(360x**3)+....
 *	(better formula:
 *	   lgamma(x)~(x-0.5)*(log(x)-1)-.5*(log(2pi)-1) + ...)
 *	Let z = 1/x, then we approximation
 *		f(z) = lgamma(x) - (x-0.5)(log(x)-1)
 *	by
 *				    3       5             11
 *		w = w0 + w1*z + w2*z  + w3*z  + ... + w6*z
 *	where
 *		|w - f(z)| < 2**-58.74
 *
 *   4. For negative x, since (G is gamma function)
 *		-x*G(-x)*G(x) = pi/sin(pi*x),
 *	we have
 *		G(x) = pi/(sin(pi*x)*(-x)*G(-x))
 *	since G(-x) is positive, sign(G(x)) = sign(sin(pi*x)) for x<0
 *	Hence, for x<0, signgam = sign(sin(pi*x)) and
 *		lgamma(x) = log(|Gamma(x)|)
 *			  = log(pi/(|x*sin(pi*x)|)) - lgamma(-x);
 *	Note: one should avoid compute pi*(-x) directly in the
 *	      computation of sin(pi*(-x)).
 *
 *   5. Special Cases
 *		lgamma(2+s) ~ s*(1-Euler) for tiny s
 *		lgamma(1)=lgamma(2)=0
 *		lgamma(x) ~ -log(x) for tiny x
 *		lgamma(0) = lgamma(inf) = inf
 *		lgamma(-integer) = +-inf
 *
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

static double sin_pi(double x) {
  double y, z;
  int32_t n, ix;

  static const double zero = 0.00000000000000000000e+00;
  static const double one =
      1.00000000000000000000e+00; /* 0x3FF00000, 0x00000000 */
  static const double pi =
      3.14159265358979311600e+00; /* 0x400921FB, 0x54442D18 */
  static const double two52 =
      4.50359962737049600000e+15; /* 0x43300000, 0x00000000 */

  GET_HIGH_WORD(ix, x);
  ix &= IC(0x7fffffff);

  if (ix < IC(0x3fd00000)) {
    double temp_var_for_ext_0;
    double temp_var_for_tac_0;
    double temp_var_for_const_0, temp_var_for_const_1;
    double temp_var_for_callexp_0;

    temp_var_for_tac_0 = pi * x;

    temp_var_for_callexp_0 = __ieee754_sin(temp_var_for_tac_0);
    temp_var_for_ext_0 = temp_var_for_callexp_0;
    computeDMul((Addr)&temp_var_for_tac_0,
                {(Addr) &(temp_var_for_const_0 = pi), (Addr)&x},
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:101:43");
    AssignD({(Addr)&temp_var_for_ext_0},
            (Addr) &(temp_var_for_const_1 = temp_var_for_callexp_0),
            "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:101:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  double temp_var_for_tac_1;
  double temp_var_for_const_2;
  temp_var_for_tac_1 = 0.0 - x;

  y = temp_var_for_tac_1;
  computeDSub((Addr)&temp_var_for_tac_1,
              {(Addr) &(temp_var_for_const_2 = 0.0), (Addr)&x},
              "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:107:12");
  AssignD({(Addr)&y}, (Addr)&temp_var_for_tac_1,
          "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:107:5");
  ; /* x is assume negative */

  /*
   * argument reduction, make sure inexact flag not raised if input
   * is an integer
   */
  double temp_var_for_const_3;
  double temp_var_for_callexp_1;

  temp_var_for_callexp_1 = __ieee754_floor(y);
  z = temp_var_for_callexp_1;
  AssignD({(Addr)&z}, (Addr) &(temp_var_for_const_3 = temp_var_for_callexp_1),
          "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:113:5");
  ;
  if (int temp_var_for_tac_2; temp_var_for_tac_2 = z != y;

      ) { /* inexact anyway */
    y *= 0.5;
    ;
    double temp_var_for_ext_1;
    double temp_var_for_tac_4, temp_var_for_tac_5;
    double temp_var_for_const_4, temp_var_for_const_5;
    double temp_var_for_callexp_2;

    temp_var_for_callexp_2 = __ieee754_floor(y);
    temp_var_for_tac_4 = y - temp_var_for_callexp_2;

    temp_var_for_tac_5 = 2.0 * temp_var_for_tac_4;

    temp_var_for_ext_1 = temp_var_for_tac_5;
    compute((Addr)&temp_var_for_tac_2, {(Addr)&z, (Addr)&y},
            "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:114:9");
    computeDSub(
        (Addr)&temp_var_for_tac_4,
        {(Addr)&y, (Addr) &(temp_var_for_const_4 = temp_var_for_callexp_2)},
        "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:117:35");
    computeDMul(
        (Addr)&temp_var_for_tac_5,
        {(Addr) &(temp_var_for_const_5 = 2.0), (Addr)&temp_var_for_tac_4},
        "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:117:30");
    AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_5,
            "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:117:24");
    ; // y
    /*(0.5)(y)(__ieee754_floor(y))(y)(2.0)*/
    y = temp_var_for_ext_1;
    AssignD({(Addr)&y}, (Addr)&temp_var_for_ext_1,
            "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:119:7");
    ; /* y = |x| mod 2.0 */
    n = (int32_t)(double temp_var_for_tac_6; double temp_var_for_const_6;
                  temp_var_for_tac_6 = y * 4.0;

                  );
  } else {
    if (ix >= IC(0x43400000)) {
      double temp_var_for_ext_2;
      double temp_var_for_const_7;
      temp_var_for_ext_2 = zero;
      computeDMul((Addr)&temp_var_for_tac_6,
                  {(Addr)&y, (Addr) &(temp_var_for_const_6 = 4.0)},
                  "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:120:21");
      AssignD({(Addr)&temp_var_for_ext_2},
              (Addr) &(temp_var_for_const_7 = zero),
              "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:124:26");
      ; // y
      /*(__ieee754_floor(y))(y)(2.0)(__ieee754_floor(y))(y)(4.0)(y)(zero)*/
      y = temp_var_for_ext_2;
      AssignD({(Addr)&y}, (Addr)&temp_var_for_ext_2,
              "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:126:9");
      ;
      n = 0; /* y must be even */
    } else {
      if (ix < IC(0x43300000)) {
        double temp_var_for_tac_7;
        double temp_var_for_const_8;
        temp_var_for_tac_7 = y + two52;

        z = temp_var_for_tac_7;
        computeDAdd((Addr)&temp_var_for_tac_7,
                    {(Addr)&y, (Addr) &(temp_var_for_const_8 = two52)},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:130:15");
        AssignD({(Addr)&z}, (Addr)&temp_var_for_tac_7,
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:130:11");
        ;
      }
      /* exact */
      GET_LOW_WORD(n, z);
      n &= 1;
      double temp_var_for_ext_3;
      double temp_var_for_const_9;
      temp_var_for_ext_3 = n;
      AssignD({(Addr)&temp_var_for_ext_3}, (Addr) &(temp_var_for_const_9 = n),
              "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:136:26");
      ; // y
      /*(two52)(y)(n)*/
      y = temp_var_for_ext_3;
      AssignD({(Addr)&y}, (Addr)&temp_var_for_ext_3,
              "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:138:9");
      ;
      n <<= 2;
    }
  }
#ifdef __have_fpu_sin
  switch ((int)n) {
  case 0:
    y = __ieee754_sin(pi * y);
    break;
  case 1:
  case 2:
    y = __ieee754_cos(pi * (0.5 - y));
    break;
  case 3:
  case 4:
    y = __ieee754_sin(pi * (one - y));
    break;
  case 5:
  case 6:
    y = -__ieee754_cos(pi * (y - 1.5));
    break;
  default:
    y = __ieee754_sin(pi * (y - 2.0));
    break;
  }
#else
  int temp_var_for_ext_4;
  temp_var_for_ext_4 = (int)n;
  switch (temp_var_for_ext_4) {
  case 0: {
    double temp_var_for_tac_8;
    double temp_var_for_const_10, temp_var_for_const_11;
    double temp_var_for_callexp_3;

    temp_var_for_tac_8 = pi * y;

    temp_var_for_callexp_3 = __kernel_sin(temp_var_for_tac_8, zero, 0);
    y = temp_var_for_callexp_3;
    computeDMul((Addr)&temp_var_for_tac_8,
                {(Addr) &(temp_var_for_const_10 = pi), (Addr)&y},
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:168:25");
    AssignD({(Addr)&y},
            (Addr) &(temp_var_for_const_11 = temp_var_for_callexp_3),
            "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:168:7");
    ;
  }

  break;
  case 1: {
  case 2: {
    double temp_var_for_ext_5;
    double temp_var_for_tac_9, temp_var_for_tac_10;
    double temp_var_for_const_12, temp_var_for_const_13, temp_var_for_const_14;
    double temp_var_for_callexp_4;

    temp_var_for_tac_9 = 0.5 - y;

    temp_var_for_tac_10 = pi * temp_var_for_tac_9;

    temp_var_for_callexp_4 = __kernel_cos(temp_var_for_tac_10, zero);
    temp_var_for_ext_5 = temp_var_for_callexp_4;
    computeDSub((Addr)&temp_var_for_tac_9,
                {(Addr) &(temp_var_for_const_12 = 0.5), (Addr)&y},
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:175:49");
    computeDMul(
        (Addr)&temp_var_for_tac_10,
        {(Addr) &(temp_var_for_const_13 = pi), (Addr)&temp_var_for_tac_9},
        "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:175:42");
    AssignD({(Addr)&temp_var_for_ext_5},
            (Addr) &(temp_var_for_const_14 = temp_var_for_callexp_4),
            "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:175:24");
    ; // y
    /*(y)(pi)(__kernel_cos(pi * (0.5 - y), zero))*/
    y = temp_var_for_ext_5;
    AssignD({(Addr)&y}, (Addr)&temp_var_for_ext_5,
            "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:177:7");
    ;
  }

  }

  break;
  case 3: {
  case 4: {
    double temp_var_for_ext_6;
    double temp_var_for_tac_11, temp_var_for_tac_12;
    double temp_var_for_const_15, temp_var_for_const_16, temp_var_for_const_17;
    double temp_var_for_callexp_5;

    temp_var_for_tac_11 = one - y;

    temp_var_for_tac_12 = pi * temp_var_for_tac_11;

    temp_var_for_callexp_5 = __kernel_sin(temp_var_for_tac_12, zero, 0);
    temp_var_for_ext_6 = temp_var_for_callexp_5;
    computeDSub((Addr)&temp_var_for_tac_11,
                {(Addr) &(temp_var_for_const_15 = one), (Addr)&y},
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:186:49");
    computeDMul(
        (Addr)&temp_var_for_tac_12,
        {(Addr) &(temp_var_for_const_16 = pi), (Addr)&temp_var_for_tac_11},
        "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:186:42");
    AssignD({(Addr)&temp_var_for_ext_6},
            (Addr) &(temp_var_for_const_17 = temp_var_for_callexp_5),
            "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:186:24");
    ; // y
    /*(y)(0.5)(pi)(y)(0.5)(__kernel_sin(pi * (one - y), zero, 0))*/
    y = temp_var_for_ext_6;
    AssignD({(Addr)&y}, (Addr)&temp_var_for_ext_6,
            "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:188:7");
    ;
  }

  }

  break;
  case 5: {
  case 6: {
    double temp_var_for_ext_7;
    double temp_var_for_tac_13, temp_var_for_tac_14, temp_var_for_tac_15;
    double temp_var_for_const_18, temp_var_for_const_19, temp_var_for_const_20,
        temp_var_for_const_21;
    double temp_var_for_callexp_6;

    temp_var_for_tac_13 = y - 1.5;

    temp_var_for_tac_14 = pi * temp_var_for_tac_13;

    temp_var_for_callexp_6 = __kernel_cos(temp_var_for_tac_14, zero);
    temp_var_for_tac_15 = 0.0 - temp_var_for_callexp_6;

    temp_var_for_ext_7 = temp_var_for_tac_15;
    computeDSub((Addr)&temp_var_for_tac_13,
                {(Addr)&y, (Addr) &(temp_var_for_const_18 = 1.5)},
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:197:54");
    computeDMul(
        (Addr)&temp_var_for_tac_14,
        {(Addr) &(temp_var_for_const_19 = pi), (Addr)&temp_var_for_tac_13},
        "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:197:49");
    computeDSub((Addr)&temp_var_for_tac_15,
                {(Addr) &(temp_var_for_const_21 = 0.0),
                 (Addr) &(temp_var_for_const_20 = temp_var_for_callexp_6)},
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:197:31");
    AssignD({(Addr)&temp_var_for_ext_7}, (Addr)&temp_var_for_tac_15,
            "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:197:24");
    ; // y
    /*(y)(one)(pi)(y)(one)(__kernel_cos(pi * (y - 1.5), zero))(__kernel_cos(pi *
     * (y - 1.5), zero))*/
    y = temp_var_for_ext_7;
    AssignD({(Addr)&y}, (Addr)&temp_var_for_ext_7,
            "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:200:7");
    ;
  }

  }

  break;
  default: {
    double temp_var_for_tac_16, temp_var_for_tac_17;
    double temp_var_for_const_22, temp_var_for_const_23, temp_var_for_const_24;
    double temp_var_for_callexp_7;

    temp_var_for_tac_16 = y - 2.0;

    temp_var_for_tac_17 = pi * temp_var_for_tac_16;

    temp_var_for_callexp_7 = __kernel_sin(temp_var_for_tac_17, zero, 0);
    y = temp_var_for_callexp_7;
    computeDSub((Addr)&temp_var_for_tac_16,
                {(Addr)&y, (Addr) &(temp_var_for_const_22 = 2.0)},
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:207:30");
    computeDMul(
        (Addr)&temp_var_for_tac_17,
        {(Addr) &(temp_var_for_const_23 = pi), (Addr)&temp_var_for_tac_16},
        "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:207:25");
    AssignD({(Addr)&y},
            (Addr) &(temp_var_for_const_24 = temp_var_for_callexp_7),
            "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:207:7");
    ;
  }

  break;
  }
#endif
  double temp_var_for_ext_8;
  double temp_var_for_const_25;
  temp_var_for_ext_8 = (-(y));
  AssignD({(Addr)&temp_var_for_ext_8}, (Addr) &(temp_var_for_const_25 = (-(y))),
          "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:214:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
  callExp++; /*identify the function is  add move tmpShadow*/
  return (double temp_var_for_tac_18;
          double temp_var_for_const_26, temp_var_for_const_27;
          temp_var_for_tac_18 = 0.0 - 8;

          );
}

double __ieee754_lgamma_r(double x, int *signgamp) {
  double t, y, z, nadj = 0, p, p1, p2, p3, q, r, w;
  int32_t i, hx, lx, ix;

  static const double zero = 0.00000000000000000000e+00;

  static const double half =
      5.00000000000000000000e-01; /* 0x3FE00000, 0x00000000 */
  static const double one =
      1.00000000000000000000e+00; /* 0x3FF00000, 0x00000000 */
  static const double pi =
      3.14159265358979311600e+00; /* 0x400921FB, 0x54442D18 */
  static const double a0 =
      7.72156649015328655494e-02; /* 0x3FB3C467, 0xE37DB0C8 */
  static const double a1 =
      3.22467033424113591611e-01; /* 0x3FD4A34C, 0xC4A60FAD */
  static const double a2 =
      6.73523010531292681824e-02; /* 0x3FB13E00, 0x1A5562A7 */
  static const double a3 =
      2.05808084325167332806e-02; /* 0x3F951322, 0xAC92547B */
  static const double a4 =
      7.38555086081402883957e-03; /* 0x3F7E404F, 0xB68FEFE8 */
  static const double a5 =
      2.89051383673415629091e-03; /* 0x3F67ADD8, 0xCCB7926B */
  static const double a6 =
      1.19270763183362067845e-03; /* 0x3F538A94, 0x116F3F5D */
  static const double a7 =
      5.10069792153511336608e-04; /* 0x3F40B6C6, 0x89B99C00 */
  static const double a8 =
      2.20862790713908385557e-04; /* 0x3F2CF2EC, 0xED10E54D */
  static const double a9 =
      1.08011567247583939954e-04; /* 0x3F1C5088, 0x987DFB07 */
  static const double a10 =
      2.52144565451257326939e-05; /* 0x3EFA7074, 0x428CFA52 */
  static const double a11 =
      4.48640949618915160150e-05; /* 0x3F07858E, 0x90A45837 */
  static const double tc =
      1.46163214496836224576e+00; /* 0x3FF762D8, 0x6356BE3F */
  static const double tf =
      (double temp_var_for_tac_19;
       double temp_var_for_const_28, temp_var_for_const_29;
       temp_var_for_tac_19 = 0.0 - 1.21486290535849611461e-01;

       ); /* 0xBFBF19B9, 0xBCC38A42 */
  /* tt = -(tail of tf) */
  static const double tt =
      (double temp_var_for_tac_20;
       double temp_var_for_const_30, temp_var_for_const_31;
       temp_var_for_tac_20 = 0.0 - 3.63867699703950536541e-18;

       ); /* 0xBC50C7CA, 0xA48A971F */
  static const double t0 =
      4.83836122723810047042e-01; /* 0x3FDEF72B, 0xC8EE38A2 */
  static const double t1 =
      (double temp_var_for_tac_21;
       double temp_var_for_const_32, temp_var_for_const_33;
       temp_var_for_tac_21 = 0.0 - 1.47587722994593911752e-01;

       ); /* 0xBFC2E427, 0x8DC6C509 */
  static const double t2 =
      6.46249402391333854778e-02; /* 0x3FB08B42, 0x94D5419B */
  static const double t3 =
      (double temp_var_for_tac_22;
       double temp_var_for_const_34, temp_var_for_const_35;
       temp_var_for_tac_22 = 0.0 - 3.27885410759859649565e-02;

       ); /* 0xBFA0C9A8, 0xDF35B713 */
  static const double t4 =
      1.79706750811820387126e-02; /* 0x3F9266E7, 0x970AF9EC */
  static const double t5 =
      (double temp_var_for_tac_23;
       double temp_var_for_const_36, temp_var_for_const_37;
       temp_var_for_tac_23 = 0.0 - 1.03142241298341437450e-02;

       ); /* 0xBF851F9F, 0xBA91EC6A */
  static const double t6 =
      6.10053870246291332635e-03; /* 0x3F78FCE0, 0xE370E344 */
  static const double t7 =
      (double temp_var_for_tac_24;
       double temp_var_for_const_38, temp_var_for_const_39;
       temp_var_for_tac_24 = 0.0 - 3.68452016781138256760e-03;

       ); /* 0xBF6E2EFF, 0xB3E914D7 */
  static const double t8 =
      2.25964780900612472250e-03; /* 0x3F6282D3, 0x2E15C915 */
  static const double t9 =
      (double temp_var_for_tac_25;
       double temp_var_for_const_40, temp_var_for_const_41;
       temp_var_for_tac_25 = 0.0 - 1.40346469989232843813e-03;

       ); /* 0xBF56FE8E, 0xBF2D1AF1 */
  static const double t10 =
      8.81081882437654011382e-04; /* 0x3F4CDF0C, 0xEF61A8E9 */
  static const double t11 =
      (double temp_var_for_tac_26;
       double temp_var_for_const_42, temp_var_for_const_43;
       temp_var_for_tac_26 = 0.0 - 5.38595305356740546715e-04;

       ); /* 0xBF41A610, 0x9C73E0EC */
  static const double t12 =
      3.15632070903625950361e-04; /* 0x3F34AF6D, 0x6C0EBBF7 */
  static const double t13 =
      (double temp_var_for_tac_27;
       double temp_var_for_const_44, temp_var_for_const_45;
       temp_var_for_tac_27 = 0.0 - 3.12754168375120860518e-04;

       ); /* 0xBF347F24, 0xECC38C38 */
  static const double t14 =
      3.35529192635519073543e-04; /* 0x3F35FD3E, 0xE8C2D3F4 */
  static const double u0 =
      (double temp_var_for_tac_28;
       double temp_var_for_const_46, temp_var_for_const_47;
       temp_var_for_tac_28 = 0.0 - 7.72156649015328655494e-02;

       ); /* 0xBFB3C467, 0xE37DB0C8 */
  static const double u1 =
      6.32827064025093366517e-01; /* 0x3FE4401E, 0x8B005DFF */
  static const double u2 =
      1.45492250137234768737e+00; /* 0x3FF7475C, 0xD119BD6F */
  static const double u3 =
      9.77717527963372745603e-01; /* 0x3FEF4976, 0x44EA8450 */
  static const double u4 =
      2.28963728064692451092e-01; /* 0x3FCD4EAE, 0xF6010924 */
  static const double u5 =
      1.33810918536787660377e-02; /* 0x3F8B678B, 0xBF2BAB09 */
  static const double v1 =
      2.45597793713041134822e+00; /* 0x4003A5D7, 0xC2BD619C */
  static const double v2 =
      2.12848976379893395361e+00; /* 0x40010725, 0xA42B18F5 */
  static const double v3 =
      7.69285150456672783825e-01; /* 0x3FE89DFB, 0xE45050AF */
  static const double v4 =
      1.04222645593369134254e-01; /* 0x3FBAAE55, 0xD6537C88 */
  static const double v5 =
      3.21709242282423911810e-03; /* 0x3F6A5ABB, 0x57D0CF61 */
  static const double s0 =
      (double temp_var_for_tac_29;
       double temp_var_for_const_48, temp_var_for_const_49;
       temp_var_for_tac_29 = 0.0 - 7.72156649015328655494e-02;

       ); /* 0xBFB3C467, 0xE37DB0C8 */
  static const double s1 =
      2.14982415960608852501e-01; /* 0x3FCB848B, 0x36E20878 */
  static const double s2 =
      3.25778796408930981787e-01; /* 0x3FD4D98F, 0x4F139F59 */
  static const double s3 =
      1.46350472652464452805e-01; /* 0x3FC2BB9C, 0xBEE5F2F7 */
  static const double s4 =
      2.66422703033638609560e-02; /* 0x3F9B481C, 0x7E939961 */
  static const double s5 =
      1.84028451407337715652e-03; /* 0x3F5E26B6, 0x7368F239 */
  static const double s6 =
      3.19475326584100867617e-05; /* 0x3F00BFEC, 0xDD17E945 */
  static const double r1 =
      1.39200533467621045958e+00; /* 0x3FF645A7, 0x62C4AB74 */
  static const double r2 =
      7.21935547567138069525e-01; /* 0x3FE71A18, 0x93D3DCDC */
  static const double r3 =
      1.71933865632803078993e-01; /* 0x3FC601ED, 0xCCFBDF27 */
  static const double r4 =
      1.86459191715652901344e-02; /* 0x3F9317EA, 0x742ED475 */
  static const double r5 =
      7.77942496381893596434e-04; /* 0x3F497DDA, 0xCA41A95B */
  static const double r6 =
      7.32668430744625636189e-06; /* 0x3EDEBAF7, 0xA5B38140 */
  static const double w0 =
      4.18938533204672725052e-01; /* 0x3FDACFE3, 0x90C97D69 */
  static const double w1 =
      8.33333333333329678849e-02; /* 0x3FB55555, 0x5555553B */
  static const double w2 =
      (double temp_var_for_tac_30;
       double temp_var_for_const_50, temp_var_for_const_51;
       temp_var_for_tac_30 = 0.0 - 2.77777777728775536470e-03;

       ); /* 0xBF66C16C, 0x16B02E5C */
  static const double w3 =
      7.93650558643019558500e-04; /* 0x3F4A019F, 0x98CF38B6 */
  static const double w4 =
      (double temp_var_for_tac_31;
       double temp_var_for_const_52, temp_var_for_const_53;
       temp_var_for_tac_31 = 0.0 - 5.95187557450339963135e-04;

       ); /* 0xBF4380CB, 0x8C0FE741 */
  static const double w5 =
      8.36339918996282139126e-04; /* 0x3F4B67BA, 0x4CDAD5D1 */
  static const double w6 =
      (double temp_var_for_tac_32;
       double temp_var_for_const_54, temp_var_for_const_55;
       temp_var_for_tac_32 = 0.0 - 1.63092934096575273989e-03;

       ); /* 0xBF5AB89D, 0x0B9E43E4 */

  GET_DOUBLE_WORDS(hx, lx, x);

  /* purge off +-inf, NaN, +-0, and negative arguments */
  *signgamp = 1;
  ix = hx & IC(0x7fffffff);
  if (ix >= IC(0x7ff00000)) {
    double temp_var_for_ext_9;
    double temp_var_for_tac_33;
    temp_var_for_tac_33 = x * x;

    temp_var_for_ext_9 = temp_var_for_tac_33;
    computeDSub((Addr)&temp_var_for_tac_18,
                {(Addr) &(temp_var_for_const_27 = 0.0),
                 (Addr) &(temp_var_for_const_26 = 8)},
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:217:15");
    computeDSub((Addr)&temp_var_for_tac_19,
                {(Addr) &(temp_var_for_const_29 = 0.0),
                 (Addr) &(temp_var_for_const_28 = 1.21486290535849611461e-01)},
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:259:12");
    computeDSub((Addr)&temp_var_for_tac_20,
                {(Addr) &(temp_var_for_const_31 = 0.0),
                 (Addr) &(temp_var_for_const_30 = 3.63867699703950536541e-18)},
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:262:12");
    computeDSub((Addr)&temp_var_for_tac_21,
                {(Addr) &(temp_var_for_const_33 = 0.0),
                 (Addr) &(temp_var_for_const_32 = 1.47587722994593911752e-01)},
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:266:12");
    computeDSub((Addr)&temp_var_for_tac_22,
                {(Addr) &(temp_var_for_const_35 = 0.0),
                 (Addr) &(temp_var_for_const_34 = 3.27885410759859649565e-02)},
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:270:12");
    computeDSub((Addr)&temp_var_for_tac_23,
                {(Addr) &(temp_var_for_const_37 = 0.0),
                 (Addr) &(temp_var_for_const_36 = 1.03142241298341437450e-02)},
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:274:12");
    computeDSub((Addr)&temp_var_for_tac_24,
                {(Addr) &(temp_var_for_const_39 = 0.0),
                 (Addr) &(temp_var_for_const_38 = 3.68452016781138256760e-03)},
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:278:12");
    computeDSub((Addr)&temp_var_for_tac_25,
                {(Addr) &(temp_var_for_const_41 = 0.0),
                 (Addr) &(temp_var_for_const_40 = 1.40346469989232843813e-03)},
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:282:12");
    computeDSub((Addr)&temp_var_for_tac_26,
                {(Addr) &(temp_var_for_const_43 = 0.0),
                 (Addr) &(temp_var_for_const_42 = 5.38595305356740546715e-04)},
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:286:12");
    computeDSub((Addr)&temp_var_for_tac_27,
                {(Addr) &(temp_var_for_const_45 = 0.0),
                 (Addr) &(temp_var_for_const_44 = 3.12754168375120860518e-04)},
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:290:12");
    computeDSub((Addr)&temp_var_for_tac_28,
                {(Addr) &(temp_var_for_const_47 = 0.0),
                 (Addr) &(temp_var_for_const_46 = 7.72156649015328655494e-02)},
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:294:12");
    computeDSub((Addr)&temp_var_for_tac_29,
                {(Addr) &(temp_var_for_const_49 = 0.0),
                 (Addr) &(temp_var_for_const_48 = 7.72156649015328655494e-02)},
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:316:12");
    computeDSub((Addr)&temp_var_for_tac_30,
                {(Addr) &(temp_var_for_const_51 = 0.0),
                 (Addr) &(temp_var_for_const_50 = 2.77777777728775536470e-03)},
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:346:12");
    computeDSub((Addr)&temp_var_for_tac_31,
                {(Addr) &(temp_var_for_const_53 = 0.0),
                 (Addr) &(temp_var_for_const_52 = 5.95187557450339963135e-04)},
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:350:12");
    computeDSub((Addr)&temp_var_for_tac_32,
                {(Addr) &(temp_var_for_const_55 = 0.0),
                 (Addr) &(temp_var_for_const_54 = 1.63092934096575273989e-03)},
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:354:12");
    computeDMul((Addr)&temp_var_for_tac_33, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:363:28");
    AssignD({(Addr)&temp_var_for_ext_9}, (Addr)&temp_var_for_tac_33,
            "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:363:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_9;
  }

  if ((ix | lx) == 0) {
    if (hx < 0) {
      *signgamp = -1;
    }

    double temp_var_for_ext_10;
    double temp_var_for_tac_34;
    double temp_var_for_const_56, temp_var_for_const_57;
    double temp_var_for_callexp_8;

    temp_var_for_callexp_8 = fabs(x);
    temp_var_for_tac_34 = one / temp_var_for_callexp_8;

    temp_var_for_ext_10 = temp_var_for_tac_34;
    computeDDiv((Addr)&temp_var_for_tac_34,
                {(Addr) &(temp_var_for_const_57 = one),
                 (Addr) &(temp_var_for_const_56 = temp_var_for_callexp_8)},
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:375:31");
    AssignD({(Addr)&temp_var_for_ext_10}, (Addr)&temp_var_for_tac_34,
            "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:375:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_10", (Addr)&temp_var_for_ext_10));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_10;
  }
  if (ix < IC(0x3b900000)) {
    /* |x|<2**-70, return -log(|x|) */
    if (hx < 0) {
      *signgamp = -1;
      double temp_var_for_ext_11;
      double temp_var_for_const_58;
      temp_var_for_callexp_9 = __ieee754_log((-(x)));
      temp_var_for_ext_11 = (-(temp_var_for_callexp_9));
      AssignD({(Addr)&temp_var_for_ext_11},
              (Addr) &(temp_var_for_const_58 = (-(temp_var_for_callexp_9))),
              "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:386:27");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_11", (Addr)&temp_var_for_ext_11));
      callExp++; /*identify the function is  add move tmpShadow*/
      return (double temp_var_for_tac_35, temp_var_for_tac_36;
              double temp_var_for_const_59, temp_var_for_const_60,
              temp_var_for_const_61, temp_var_for_const_62;
              temp_var_for_tac_35 = 0.0 - 1;

              temp_var_for_tac_36 = 0.0 - mp_var_for_ext_(temp_var_for_tac_35);

              );
    } else {
      double temp_var_for_ext_12;
      double temp_var_for_const_63;
      temp_var_for_callexp_10 = __ieee754_log(x);
      temp_var_for_ext_12 = (-(temp_var_for_callexp_10));
      computeDSub((Addr)&temp_var_for_tac_35,
                  {(Addr) &(temp_var_for_const_60 = 0.0),
                   (Addr) &(temp_var_for_const_59 = 1)},
                  "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:390:41");
      computeDSub((Addr)&temp_var_for_tac_36,
                  {(Addr) &(temp_var_for_const_62 = 0.0),
                   (Addr) &(temp_var_for_const_61 =
                                mp_var_for_ext_(temp_var_for_tac_35))},
                  "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:390:19");
      AssignD({(Addr)&temp_var_for_ext_12},
              (Addr) &(temp_var_for_const_63 = (-(temp_var_for_callexp_10))),
              "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:393:27");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_12", (Addr)&temp_var_for_ext_12));
      callExp++; /*identify the function is  add move tmpShadow*/
      return (0.0 - p_var_for_ext_12);
    }
  }
  if (hx < 0) {
    if (ix >= IC(0x43300000)) /* |x|>=2**52, must be -integer */
    {
      double temp_var_for_ext_13;
      double temp_var_for_tac_37;
      double temp_var_for_const_64;
      temp_var_for_tac_37 = x / zero;

      temp_var_for_ext_13 = temp_var_for_tac_37;
      computeDDiv((Addr)&temp_var_for_tac_37,
                  {(Addr)&x, (Addr) &(temp_var_for_const_64 = zero)},
                  "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:404:31");
      AssignD({(Addr)&temp_var_for_ext_13}, (Addr)&temp_var_for_tac_37,
              "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:404:27");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_13", (Addr)&temp_var_for_ext_13));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_13;
    }

    double temp_var_for_ext_14;
    double temp_var_for_const_65;
    double temp_var_for_callexp_11;

    temp_var_for_callexp_11 = sin_pi(x);
    temp_var_for_ext_14 = temp_var_for_callexp_11;
    AssignD({(Addr)&temp_var_for_ext_14},
            (Addr) &(temp_var_for_const_65 = temp_var_for_callexp_11),
            "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:412:25");
    ; // t
    /*(2.0)(y)(pi)(2.0)(y)(9)(t)(mp_var_for_ext_10)(tem)(t_13)(t)(sin_pi(x))*/
    t = temp_var_for_ext_14;
    AssignD({(Addr)&t}, (Addr)&temp_var_for_ext_14,
            "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:414:7");
    ;
    if (int temp_var_for_tac_38; int temp_var_for_const_66;
        temp_var_for_tac_38 = t == zero;

        ) {
      double temp_var_for_ext_15;
      double temp_var_for_tac_39;
      double temp_var_for_const_67, temp_var_for_const_68;
      double temp_var_for_callexp_12;

      temp_var_for_callexp_12 = fabs(t);
      temp_var_for_tac_39 = one / temp_var_for_callexp_12;

      temp_var_for_ext_15 = temp_var_for_tac_39;
      compute((Addr)&temp_var_for_tac_38,
              {(Addr)&t, (Addr) &(temp_var_for_const_66 = zero)},
              "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:415:11");
      computeDDiv((Addr)&temp_var_for_tac_39,
                  {(Addr) &(temp_var_for_const_68 = one),
                   (Addr) &(temp_var_for_const_67 = temp_var_for_callexp_12)},
                  "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:417:33");
      AssignD({(Addr)&temp_var_for_ext_15}, (Addr)&temp_var_for_tac_39,
              "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:417:27");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_15", (Addr)&temp_var_for_ext_15));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_15;
    }
    /* -integer */
    double temp_var_for_tac_40, temp_var_for_tac_41;
    double temp_var_for_const_69, temp_var_for_const_70, temp_var_for_const_71;
    double temp_var_for_callexp_13;

    double temp_var_for_callexp_14;

    temp_var_for_tac_40 = t * x;

    temp_var_for_callexp_13 = fabs(temp_var_for_tac_40);
    temp_var_for_tac_41 = pi / temp_var_for_callexp_13;

    temp_var_for_callexp_14 = __ieee754_log(temp_var_for_tac_41);
    nadj = temp_var_for_callexp_14;
    computeDMul((Addr)&temp_var_for_tac_40, {(Addr)&t, (Addr)&x},
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:424:31 "
                "<Spelling=/home/shijia/Public/testprogram/"
                "e_lgamma_r.c_e.c:424:48>");
    computeDDiv((Addr)&temp_var_for_tac_41,
                {(Addr) &(temp_var_for_const_70 = pi),
                 (Addr) &(temp_var_for_const_69 = temp_var_for_callexp_13)},
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:424:29");
    AssignD({(Addr)&nadj},
            (Addr) &(temp_var_for_const_71 = temp_var_for_callexp_14),
            "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:424:10");
    ;
    if (int temp_var_for_tac_42; int temp_var_for_const_72;
        temp_var_for_tac_42 = t < zero;

        ) {
      *signgamp = -1;
    }

    double temp_var_for_ext_16;
    double temp_var_for_tac_43;
    double temp_var_for_const_73;
    temp_var_for_tac_43 = 0.0 - x;

    temp_var_for_ext_16 = temp_var_for_tac_43;
    compute((Addr)&temp_var_for_tac_42,
            {(Addr)&t, (Addr) &(temp_var_for_const_72 = zero)},
            "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:425:11");
    computeDSub((Addr)&temp_var_for_tac_43,
                {(Addr) &(temp_var_for_const_73 = 0.0), (Addr)&x},
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:430:32");
    AssignD({(Addr)&temp_var_for_ext_16}, (Addr)&temp_var_for_tac_43,
            "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:430:25");
    ; // x
    /*(__ieee754_fabs(t * x))(pi)()()(x)(x)*/
    x = temp_var_for_ext_16;
    AssignD({(Addr)&x}, (Addr)&temp_var_for_ext_16,
            "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:432:7");
    ;
  }

  /* purge off 1 and 2 */
  if ((((ix - IC(0x3ff00000)) | lx) == 0) ||
      (((ix - IC(0x40000000)) | lx) == 0)) {
    double temp_var_for_const_74;
    r = 0;
    AssignD({(Addr)&r}, (Addr) &(temp_var_for_const_74 = 0),
            "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:438:7");
    ;
  }

  /* for x < 2.0 */
  else {
    if (ix < IC(0x40000000)) {
      if (ix <= IC(0x3feccccc)) { /* lgamma(x) = lgamma(x+1)-log(x) */
        double temp_var_for_tac_44;
        double temp_var_for_const_75, temp_var_for_const_76;
        double temp_var_for_callexp_15;

        temp_var_for_callexp_15 = __ieee754_log(x);
        temp_var_for_tac_44 = 0.0 - temp_var_for_callexp_15;

        r = temp_var_for_tac_44;
        computeDSub((Addr)&temp_var_for_tac_44,
                    {(Addr) &(temp_var_for_const_76 = 0.0),
                     (Addr) &(temp_var_for_const_75 = temp_var_for_callexp_15)},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:445:18");
        AssignD({(Addr)&r}, (Addr)&temp_var_for_tac_44,
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:445:11");
        ;
        if (ix >= IC(0x3FE76944)) {
          double temp_var_for_tac_45;
          double temp_var_for_const_77;
          temp_var_for_tac_45 = one - x;

          y = temp_var_for_tac_45;
          computeDSub(
              (Addr)&temp_var_for_tac_45,
              {(Addr) &(temp_var_for_const_77 = one), (Addr)&x},
              "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:447:19");
          AssignD({(Addr)&y}, (Addr)&temp_var_for_tac_45,
                  "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:447:13");
          ;
          i = 0;
        } else {
          if (ix >= IC(0x3FCDA661)) {
            double temp_var_for_tac_46, temp_var_for_tac_47;
            double temp_var_for_const_78, temp_var_for_const_79;
            temp_var_for_tac_46 = tc - one;

            temp_var_for_tac_47 = x - temp_var_for_tac_46;

            y = temp_var_for_tac_47;
            computeDSub(
                (Addr)&temp_var_for_tac_46,
                {(Addr) &(temp_var_for_const_79 = tc),
                 (Addr) &(temp_var_for_const_78 = one)},
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:451:25");
            computeDSub(
                (Addr)&temp_var_for_tac_47,
                {(Addr)&x, (Addr)&temp_var_for_tac_46},
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:451:19");
            AssignD({(Addr)&y}, (Addr)&temp_var_for_tac_47,
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:451:15");
            ;
            i = 1;
          } else {
            y = x;
            AssignD({(Addr)&y}, (Addr)&x,
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:454:15");
            ;
            i = 2;
          }
        }

      } else {
        double temp_var_for_const_80;
        r = zero;
        AssignD({(Addr)&r}, (Addr) &(temp_var_for_const_80 = zero),
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:460:11");
        ;
        if (ix >= IC(0x3FFBB4C3)) {
          double temp_var_for_tac_48;
          double temp_var_for_const_81;
          temp_var_for_tac_48 = 2.0 - x;

          y = temp_var_for_tac_48;
          computeDSub(
              (Addr)&temp_var_for_tac_48,
              {(Addr) &(temp_var_for_const_81 = 2.0), (Addr)&x},
              "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:462:19");
          AssignD({(Addr)&y}, (Addr)&temp_var_for_tac_48,
                  "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:462:13");
          ;
          i = 0;
        } /* [1.7316,2] */
        else {
          if (ix >= IC(0x3FF3B4C4)) {
            double temp_var_for_tac_49;
            double temp_var_for_const_82;
            temp_var_for_tac_49 = x - tc;

            y = temp_var_for_tac_49;
            computeDSub(
                (Addr)&temp_var_for_tac_49,
                {(Addr)&x, (Addr) &(temp_var_for_const_82 = tc)},
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:467:19");
            AssignD({(Addr)&y}, (Addr)&temp_var_for_tac_49,
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:467:15");
            ;
            i = 1;
          } /* [1.23,1.73] */
          else {
            double temp_var_for_tac_50;
            double temp_var_for_const_83;
            temp_var_for_tac_50 = x - one;

            y = temp_var_for_tac_50;
            computeDSub(
                (Addr)&temp_var_for_tac_50,
                {(Addr)&x, (Addr) &(temp_var_for_const_83 = one)},
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:471:19");
            AssignD({(Addr)&y}, (Addr)&temp_var_for_tac_50,
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:471:15");
            ;
            i = 2;
          }
        }
      }
      int temp_var_for_ext_17;
      temp_var_for_ext_17 = (int)i;
      switch (temp_var_for_ext_17) {
      case 0: {
        double temp_var_for_tac_51;
        temp_var_for_tac_51 = y * y;

        z = temp_var_for_tac_51;
        computeDMul((Addr)&temp_var_for_tac_51, {(Addr)&y, (Addr)&y},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:480:15");
        AssignD({(Addr)&z}, (Addr)&temp_var_for_tac_51,
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:480:11");
        ;
      }

        double temp_var_for_tac_52, temp_var_for_tac_53, temp_var_for_tac_54,
            temp_var_for_tac_55, temp_var_for_tac_56, temp_var_for_tac_57,
            temp_var_for_tac_58, temp_var_for_tac_59, temp_var_for_tac_60,
            temp_var_for_tac_61;
        double temp_var_for_const_84, temp_var_for_const_85,
            temp_var_for_const_86, temp_var_for_const_87, temp_var_for_const_88,
            temp_var_for_const_89;
        temp_var_for_tac_52 = z * a10;

        temp_var_for_tac_53 = a8 + temp_var_for_tac_52;

        temp_var_for_tac_54 = z * temp_var_for_tac_53;

        temp_var_for_tac_55 = a6 + temp_var_for_tac_54;

        temp_var_for_tac_56 = z * temp_var_for_tac_55;

        temp_var_for_tac_57 = a4 + temp_var_for_tac_56;

        temp_var_for_tac_58 = z * temp_var_for_tac_57;

        temp_var_for_tac_59 = a2 + temp_var_for_tac_58;

        temp_var_for_tac_60 = z * temp_var_for_tac_59;

        temp_var_for_tac_61 = a0 + temp_var_for_tac_60;

        p1 = temp_var_for_tac_61;
        computeDMul((Addr)&temp_var_for_tac_52,
                    {(Addr)&z, (Addr) &(temp_var_for_const_84 = a10)},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:483:61");
        computeDAdd(
            (Addr)&temp_var_for_tac_53,
            {(Addr) &(temp_var_for_const_85 = a8), (Addr)&temp_var_for_tac_52},
            "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:483:57");
        computeDMul((Addr)&temp_var_for_tac_54,
                    {(Addr)&z, (Addr)&temp_var_for_tac_53},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:483:51");
        computeDAdd(
            (Addr)&temp_var_for_tac_55,
            {(Addr) &(temp_var_for_const_86 = a6), (Addr)&temp_var_for_tac_54},
            "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:483:47");
        computeDMul((Addr)&temp_var_for_tac_56,
                    {(Addr)&z, (Addr)&temp_var_for_tac_55},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:483:41");
        computeDAdd(
            (Addr)&temp_var_for_tac_57,
            {(Addr) &(temp_var_for_const_87 = a4), (Addr)&temp_var_for_tac_56},
            "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:483:37");
        computeDMul((Addr)&temp_var_for_tac_58,
                    {(Addr)&z, (Addr)&temp_var_for_tac_57},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:483:31");
        computeDAdd(
            (Addr)&temp_var_for_tac_59,
            {(Addr) &(temp_var_for_const_88 = a2), (Addr)&temp_var_for_tac_58},
            "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:483:27");
        computeDMul((Addr)&temp_var_for_tac_60,
                    {(Addr)&z, (Addr)&temp_var_for_tac_59},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:483:21");
        computeDAdd(
            (Addr)&temp_var_for_tac_61,
            {(Addr) &(temp_var_for_const_89 = a0), (Addr)&temp_var_for_tac_60},
            "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:483:17");
        AssignD({(Addr)&p1}, (Addr)&temp_var_for_tac_61,
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:483:12");
        ;
        double temp_var_for_tac_62, temp_var_for_tac_63, temp_var_for_tac_64,
            temp_var_for_tac_65, temp_var_for_tac_66, temp_var_for_tac_67,
            temp_var_for_tac_68, temp_var_for_tac_69, temp_var_for_tac_70,
            temp_var_for_tac_71, temp_var_for_tac_72;
        double temp_var_for_const_90, temp_var_for_const_91,
            temp_var_for_const_92, temp_var_for_const_93, temp_var_for_const_94,
            temp_var_for_const_95;
        temp_var_for_tac_62 = z * a11;

        temp_var_for_tac_63 = a9 + temp_var_for_tac_62;

        temp_var_for_tac_64 = z * temp_var_for_tac_63;

        temp_var_for_tac_65 = a7 + temp_var_for_tac_64;

        temp_var_for_tac_66 = z * temp_var_for_tac_65;

        temp_var_for_tac_67 = a5 + temp_var_for_tac_66;

        temp_var_for_tac_68 = z * temp_var_for_tac_67;

        temp_var_for_tac_69 = a3 + temp_var_for_tac_68;

        temp_var_for_tac_70 = z * temp_var_for_tac_69;

        temp_var_for_tac_71 = a1 + temp_var_for_tac_70;

        temp_var_for_tac_72 = z * temp_var_for_tac_71;

        p2 = temp_var_for_tac_72;
        computeDMul((Addr)&temp_var_for_tac_62,
                    {(Addr)&z, (Addr) &(temp_var_for_const_90 = a11)},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:484:66");
        computeDAdd(
            (Addr)&temp_var_for_tac_63,
            {(Addr) &(temp_var_for_const_91 = a9), (Addr)&temp_var_for_tac_62},
            "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:484:62");
        computeDMul((Addr)&temp_var_for_tac_64,
                    {(Addr)&z, (Addr)&temp_var_for_tac_63},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:484:56");
        computeDAdd(
            (Addr)&temp_var_for_tac_65,
            {(Addr) &(temp_var_for_const_92 = a7), (Addr)&temp_var_for_tac_64},
            "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:484:52");
        computeDMul((Addr)&temp_var_for_tac_66,
                    {(Addr)&z, (Addr)&temp_var_for_tac_65},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:484:46");
        computeDAdd(
            (Addr)&temp_var_for_tac_67,
            {(Addr) &(temp_var_for_const_93 = a5), (Addr)&temp_var_for_tac_66},
            "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:484:42");
        computeDMul((Addr)&temp_var_for_tac_68,
                    {(Addr)&z, (Addr)&temp_var_for_tac_67},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:484:36");
        computeDAdd(
            (Addr)&temp_var_for_tac_69,
            {(Addr) &(temp_var_for_const_94 = a3), (Addr)&temp_var_for_tac_68},
            "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:484:32");
        computeDMul((Addr)&temp_var_for_tac_70,
                    {(Addr)&z, (Addr)&temp_var_for_tac_69},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:484:26");
        computeDAdd(
            (Addr)&temp_var_for_tac_71,
            {(Addr) &(temp_var_for_const_95 = a1), (Addr)&temp_var_for_tac_70},
            "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:484:22");
        computeDMul((Addr)&temp_var_for_tac_72,
                    {(Addr)&z, (Addr)&temp_var_for_tac_71},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:484:16");
        AssignD({(Addr)&p2}, (Addr)&temp_var_for_tac_72,
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:484:12");
        ;
        double temp_var_for_tac_73, temp_var_for_tac_74;
        temp_var_for_tac_73 = y * p1;

        temp_var_for_tac_74 = temp_var_for_tac_73 + p2;

        p = temp_var_for_tac_74;
        computeDMul((Addr)&temp_var_for_tac_73, {(Addr)&y, (Addr)&p1},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:485:15");
        computeDAdd((Addr)&temp_var_for_tac_74,
                    {(Addr)&temp_var_for_tac_73, (Addr)&p2},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:485:20");
        AssignD({(Addr)&p}, (Addr)&temp_var_for_tac_74,
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:485:11");
        ;
        double temp_var_for_tac_75, temp_var_for_tac_76;
        double temp_var_for_const_96;
        temp_var_for_tac_75 = 0.5 * y;

        temp_var_for_tac_76 = p - temp_var_for_tac_75;

        r += temp_var_for_tac_76;
        ;
        break;
      case 1: {
        double temp_var_for_tac_78;
        temp_var_for_tac_78 = y * y;

        z = temp_var_for_tac_78;
        computeDMul((Addr)&temp_var_for_tac_75,
                    {(Addr) &(temp_var_for_const_96 = 0.5), (Addr)&y},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:486:23");
        computeDSub((Addr)&temp_var_for_tac_76,
                    {(Addr)&p, (Addr)&temp_var_for_tac_75},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:486:17");
        computeDMul((Addr)&temp_var_for_tac_78, {(Addr)&y, (Addr)&y},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:489:15");
        AssignD({(Addr)&z}, (Addr)&temp_var_for_tac_78,
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:489:11");
        ;
      }

        double temp_var_for_tac_79;
        temp_var_for_tac_79 = z * y;

        w = temp_var_for_tac_79;
        computeDMul((Addr)&temp_var_for_tac_79, {(Addr)&z, (Addr)&y},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:492:15");
        AssignD({(Addr)&w}, (Addr)&temp_var_for_tac_79,
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:492:11");
        ;
        double temp_var_for_tac_80, temp_var_for_tac_81, temp_var_for_tac_82,
            temp_var_for_tac_83, temp_var_for_tac_84, temp_var_for_tac_85,
            temp_var_for_tac_86, temp_var_for_tac_87;
        double temp_var_for_const_97, temp_var_for_const_98,
            temp_var_for_const_99, temp_var_for_const_100,
            temp_var_for_const_101;
        temp_var_for_tac_80 = w * t12;

        temp_var_for_tac_81 = t9 + temp_var_for_tac_80;

        temp_var_for_tac_82 = w * temp_var_for_tac_81;

        temp_var_for_tac_83 = t6 + temp_var_for_tac_82;

        temp_var_for_tac_84 = w * temp_var_for_tac_83;

        temp_var_for_tac_85 = t3 + temp_var_for_tac_84;

        temp_var_for_tac_86 = w * temp_var_for_tac_85;

        temp_var_for_tac_87 = t0 + temp_var_for_tac_86;

        p1 = temp_var_for_tac_87;
        computeDMul((Addr)&temp_var_for_tac_80,
                    {(Addr)&w, (Addr) &(temp_var_for_const_97 = t12)},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:493:51");
        computeDAdd(
            (Addr)&temp_var_for_tac_81,
            {(Addr) &(temp_var_for_const_98 = t9), (Addr)&temp_var_for_tac_80},
            "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:493:47");
        computeDMul((Addr)&temp_var_for_tac_82,
                    {(Addr)&w, (Addr)&temp_var_for_tac_81},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:493:41");
        computeDAdd(
            (Addr)&temp_var_for_tac_83,
            {(Addr) &(temp_var_for_const_99 = t6), (Addr)&temp_var_for_tac_82},
            "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:493:37");
        computeDMul((Addr)&temp_var_for_tac_84,
                    {(Addr)&w, (Addr)&temp_var_for_tac_83},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:493:31");
        computeDAdd(
            (Addr)&temp_var_for_tac_85,
            {(Addr) &(temp_var_for_const_100 = t3), (Addr)&temp_var_for_tac_84},
            "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:493:27");
        computeDMul((Addr)&temp_var_for_tac_86,
                    {(Addr)&w, (Addr)&temp_var_for_tac_85},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:493:21");
        computeDAdd(
            (Addr)&temp_var_for_tac_87,
            {(Addr) &(temp_var_for_const_101 = t0), (Addr)&temp_var_for_tac_86},
            "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:493:17");
        AssignD({(Addr)&p1}, (Addr)&temp_var_for_tac_87,
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:493:12");
        ; /* parallel comp */
        double temp_var_for_tac_88, temp_var_for_tac_89, temp_var_for_tac_90,
            temp_var_for_tac_91, temp_var_for_tac_92, temp_var_for_tac_93,
            temp_var_for_tac_94, temp_var_for_tac_95;
        double temp_var_for_const_102, temp_var_for_const_103,
            temp_var_for_const_104, temp_var_for_const_105,
            temp_var_for_const_106;
        temp_var_for_tac_88 = w * t13;

        temp_var_for_tac_89 = t10 + temp_var_for_tac_88;

        temp_var_for_tac_90 = w * temp_var_for_tac_89;

        temp_var_for_tac_91 = t7 + temp_var_for_tac_90;

        temp_var_for_tac_92 = w * temp_var_for_tac_91;

        temp_var_for_tac_93 = t4 + temp_var_for_tac_92;

        temp_var_for_tac_94 = w * temp_var_for_tac_93;

        temp_var_for_tac_95 = t1 + temp_var_for_tac_94;

        p2 = temp_var_for_tac_95;
        computeDMul((Addr)&temp_var_for_tac_88,
                    {(Addr)&w, (Addr) &(temp_var_for_const_102 = t13)},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:494:52");
        computeDAdd((Addr)&temp_var_for_tac_89,
                    {(Addr) &(temp_var_for_const_103 = t10),
                     (Addr)&temp_var_for_tac_88},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:494:48");
        computeDMul((Addr)&temp_var_for_tac_90,
                    {(Addr)&w, (Addr)&temp_var_for_tac_89},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:494:41");
        computeDAdd(
            (Addr)&temp_var_for_tac_91,
            {(Addr) &(temp_var_for_const_104 = t7), (Addr)&temp_var_for_tac_90},
            "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:494:37");
        computeDMul((Addr)&temp_var_for_tac_92,
                    {(Addr)&w, (Addr)&temp_var_for_tac_91},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:494:31");
        computeDAdd(
            (Addr)&temp_var_for_tac_93,
            {(Addr) &(temp_var_for_const_105 = t4), (Addr)&temp_var_for_tac_92},
            "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:494:27");
        computeDMul((Addr)&temp_var_for_tac_94,
                    {(Addr)&w, (Addr)&temp_var_for_tac_93},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:494:21");
        computeDAdd(
            (Addr)&temp_var_for_tac_95,
            {(Addr) &(temp_var_for_const_106 = t1), (Addr)&temp_var_for_tac_94},
            "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:494:17");
        AssignD({(Addr)&p2}, (Addr)&temp_var_for_tac_95,
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:494:12");
        ;
        double temp_var_for_tac_96, temp_var_for_tac_97, temp_var_for_tac_98,
            temp_var_for_tac_99, temp_var_for_tac_100, temp_var_for_tac_101,
            temp_var_for_tac_102, temp_var_for_tac_103;
        double temp_var_for_const_107, temp_var_for_const_108,
            temp_var_for_const_109, temp_var_for_const_110,
            temp_var_for_const_111;
        temp_var_for_tac_96 = w * t14;

        temp_var_for_tac_97 = t11 + temp_var_for_tac_96;

        temp_var_for_tac_98 = w * temp_var_for_tac_97;

        temp_var_for_tac_99 = t8 + temp_var_for_tac_98;

        temp_var_for_tac_100 = w * temp_var_for_tac_99;

        temp_var_for_tac_101 = t5 + temp_var_for_tac_100;

        temp_var_for_tac_102 = w * temp_var_for_tac_101;

        temp_var_for_tac_103 = t2 + temp_var_for_tac_102;

        p3 = temp_var_for_tac_103;
        computeDMul((Addr)&temp_var_for_tac_96,
                    {(Addr)&w, (Addr) &(temp_var_for_const_107 = t14)},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:495:52");
        computeDAdd((Addr)&temp_var_for_tac_97,
                    {(Addr) &(temp_var_for_const_108 = t11),
                     (Addr)&temp_var_for_tac_96},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:495:48");
        computeDMul((Addr)&temp_var_for_tac_98,
                    {(Addr)&w, (Addr)&temp_var_for_tac_97},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:495:41");
        computeDAdd(
            (Addr)&temp_var_for_tac_99,
            {(Addr) &(temp_var_for_const_109 = t8), (Addr)&temp_var_for_tac_98},
            "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:495:37");
        computeDMul((Addr)&temp_var_for_tac_100,
                    {(Addr)&w, (Addr)&temp_var_for_tac_99},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:495:31");
        computeDAdd((Addr)&temp_var_for_tac_101,
                    {(Addr) &(temp_var_for_const_110 = t5),
                     (Addr)&temp_var_for_tac_100},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:495:27");
        computeDMul((Addr)&temp_var_for_tac_102,
                    {(Addr)&w, (Addr)&temp_var_for_tac_101},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:495:21");
        computeDAdd((Addr)&temp_var_for_tac_103,
                    {(Addr) &(temp_var_for_const_111 = t2),
                     (Addr)&temp_var_for_tac_102},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:495:17");
        AssignD({(Addr)&p3}, (Addr)&temp_var_for_tac_103,
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:495:12");
        ;
        double temp_var_for_tac_104, temp_var_for_tac_105, temp_var_for_tac_106,
            temp_var_for_tac_107, temp_var_for_tac_108, temp_var_for_tac_109;
        double temp_var_for_const_112;
        temp_var_for_tac_104 = z * p1;

        temp_var_for_tac_105 = y * p3;

        temp_var_for_tac_106 = p2 + temp_var_for_tac_105;

        temp_var_for_tac_107 = w * temp_var_for_tac_106;

        temp_var_for_tac_108 = tt - temp_var_for_tac_107;

        temp_var_for_tac_109 = temp_var_for_tac_104 - temp_var_for_tac_108;

        p = temp_var_for_tac_109;
        computeDMul((Addr)&temp_var_for_tac_104, {(Addr)&z, (Addr)&p1},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:496:15");
        computeDMul((Addr)&temp_var_for_tac_105, {(Addr)&y, (Addr)&p3},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:496:40");
        computeDAdd((Addr)&temp_var_for_tac_106,
                    {(Addr)&p2, (Addr)&temp_var_for_tac_105},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:496:36");
        computeDMul((Addr)&temp_var_for_tac_107,
                    {(Addr)&w, (Addr)&temp_var_for_tac_106},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:496:30");
        computeDSub((Addr)&temp_var_for_tac_108,
                    {(Addr) &(temp_var_for_const_112 = tt),
                     (Addr)&temp_var_for_tac_107},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:496:26");
        computeDSub((Addr)&temp_var_for_tac_109,
                    {(Addr)&temp_var_for_tac_104, (Addr)&temp_var_for_tac_108},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:496:20");
        AssignD({(Addr)&p}, (Addr)&temp_var_for_tac_109,
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:496:11");
        ;
        double temp_var_for_tac_110;
        double temp_var_for_const_113;
        temp_var_for_tac_110 = tf + p;

        r += temp_var_for_tac_110;
        ;
        break;
      case 2: {
        double temp_var_for_ext_18;
        double temp_var_for_tac_112, temp_var_for_tac_113, temp_var_for_tac_114,
            temp_var_for_tac_115, temp_var_for_tac_116, temp_var_for_tac_117,
            temp_var_for_tac_118, temp_var_for_tac_119, temp_var_for_tac_120,
            temp_var_for_tac_121, temp_var_for_tac_122;
        double temp_var_for_const_114, temp_var_for_const_115,
            temp_var_for_const_116, temp_var_for_const_117,
            temp_var_for_const_118, temp_var_for_const_119;
        temp_var_for_tac_112 = y * u5;

        temp_var_for_tac_113 = u4 + temp_var_for_tac_112;

        temp_var_for_tac_114 = y * temp_var_for_tac_113;

        temp_var_for_tac_115 = u3 + temp_var_for_tac_114;

        temp_var_for_tac_116 = y * temp_var_for_tac_115;

        temp_var_for_tac_117 = u2 + temp_var_for_tac_116;

        temp_var_for_tac_118 = y * temp_var_for_tac_117;

        temp_var_for_tac_119 = u1 + temp_var_for_tac_118;

        temp_var_for_tac_120 = y * temp_var_for_tac_119;

        temp_var_for_tac_121 = u0 + temp_var_for_tac_120;

        temp_var_for_tac_122 = y * temp_var_for_tac_121;

        temp_var_for_ext_18 = temp_var_for_tac_122;
        computeDAdd((Addr)&temp_var_for_tac_110,
                    {(Addr) &(temp_var_for_const_113 = tf), (Addr)&p},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:497:18");
        computeDMul((Addr)&temp_var_for_tac_112,
                    {(Addr)&y, (Addr) &(temp_var_for_const_114 = u5)},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:502:65");
        computeDAdd((Addr)&temp_var_for_tac_113,
                    {(Addr) &(temp_var_for_const_115 = u4),
                     (Addr)&temp_var_for_tac_112},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:502:61");
        computeDMul((Addr)&temp_var_for_tac_114,
                    {(Addr)&y, (Addr)&temp_var_for_tac_113},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:502:55");
        computeDAdd((Addr)&temp_var_for_tac_115,
                    {(Addr) &(temp_var_for_const_116 = u3),
                     (Addr)&temp_var_for_tac_114},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:502:51");
        computeDMul((Addr)&temp_var_for_tac_116,
                    {(Addr)&y, (Addr)&temp_var_for_tac_115},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:502:45");
        computeDAdd((Addr)&temp_var_for_tac_117,
                    {(Addr) &(temp_var_for_const_117 = u2),
                     (Addr)&temp_var_for_tac_116},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:502:41");
        computeDMul((Addr)&temp_var_for_tac_118,
                    {(Addr)&y, (Addr)&temp_var_for_tac_117},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:502:35");
        computeDAdd((Addr)&temp_var_for_tac_119,
                    {(Addr) &(temp_var_for_const_118 = u1),
                     (Addr)&temp_var_for_tac_118},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:502:31");
        computeDMul((Addr)&temp_var_for_tac_120,
                    {(Addr)&y, (Addr)&temp_var_for_tac_119},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:502:25");
        computeDAdd((Addr)&temp_var_for_tac_121,
                    {(Addr) &(temp_var_for_const_119 = u0),
                     (Addr)&temp_var_for_tac_120},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:502:21");
        computeDMul((Addr)&temp_var_for_tac_122,
                    {(Addr)&y, (Addr)&temp_var_for_tac_121},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:502:15");
        AssignD({(Addr)&temp_var_for_ext_18}, (Addr)&temp_var_for_tac_122,
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:501:29");
        ; // p1
        /*(p3)(y)(p2)(w)(tt)(p1)(z)(p1)(z)(p3)(y)(p2)(w)(tt)(p3)(y)(p2)(w)(p3)(y)(p2)(p3)(y)(p)(tf)(r)(p)(tf)(u5)(y)(u4)(y)(u3)(y)(u2)(y)(u1)(y)(u0)(y)*/
        p1 = temp_var_for_ext_18;
        AssignD({(Addr)&p1}, (Addr)&temp_var_for_ext_18,
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:504:12");
        ;
      }

        double temp_var_for_tac_123, temp_var_for_tac_124, temp_var_for_tac_125,
            temp_var_for_tac_126, temp_var_for_tac_127, temp_var_for_tac_128,
            temp_var_for_tac_129, temp_var_for_tac_130, temp_var_for_tac_131,
            temp_var_for_tac_132;
        double temp_var_for_const_120, temp_var_for_const_121,
            temp_var_for_const_122, temp_var_for_const_123,
            temp_var_for_const_124, temp_var_for_const_125;
        temp_var_for_tac_123 = y * v5;

        temp_var_for_tac_124 = v4 + temp_var_for_tac_123;

        temp_var_for_tac_125 = y * temp_var_for_tac_124;

        temp_var_for_tac_126 = v3 + temp_var_for_tac_125;

        temp_var_for_tac_127 = y * temp_var_for_tac_126;

        temp_var_for_tac_128 = v2 + temp_var_for_tac_127;

        temp_var_for_tac_129 = y * temp_var_for_tac_128;

        temp_var_for_tac_130 = v1 + temp_var_for_tac_129;

        temp_var_for_tac_131 = y * temp_var_for_tac_130;

        temp_var_for_tac_132 = one + temp_var_for_tac_131;

        p2 = temp_var_for_tac_132;
        computeDMul((Addr)&temp_var_for_tac_123,
                    {(Addr)&y, (Addr) &(temp_var_for_const_120 = v5)},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:507:62");
        computeDAdd((Addr)&temp_var_for_tac_124,
                    {(Addr) &(temp_var_for_const_121 = v4),
                     (Addr)&temp_var_for_tac_123},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:507:58");
        computeDMul((Addr)&temp_var_for_tac_125,
                    {(Addr)&y, (Addr)&temp_var_for_tac_124},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:507:52");
        computeDAdd((Addr)&temp_var_for_tac_126,
                    {(Addr) &(temp_var_for_const_122 = v3),
                     (Addr)&temp_var_for_tac_125},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:507:48");
        computeDMul((Addr)&temp_var_for_tac_127,
                    {(Addr)&y, (Addr)&temp_var_for_tac_126},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:507:42");
        computeDAdd((Addr)&temp_var_for_tac_128,
                    {(Addr) &(temp_var_for_const_123 = v2),
                     (Addr)&temp_var_for_tac_127},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:507:38");
        computeDMul((Addr)&temp_var_for_tac_129,
                    {(Addr)&y, (Addr)&temp_var_for_tac_128},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:507:32");
        computeDAdd((Addr)&temp_var_for_tac_130,
                    {(Addr) &(temp_var_for_const_124 = v1),
                     (Addr)&temp_var_for_tac_129},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:507:28");
        computeDMul((Addr)&temp_var_for_tac_131,
                    {(Addr)&y, (Addr)&temp_var_for_tac_130},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:507:22");
        computeDAdd((Addr)&temp_var_for_tac_132,
                    {(Addr) &(temp_var_for_const_125 = one),
                     (Addr)&temp_var_for_tac_131},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:507:18");
        AssignD({(Addr)&p2}, (Addr)&temp_var_for_tac_132,
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:507:12");
        ;
        double temp_var_for_tac_133, temp_var_for_tac_134, temp_var_for_tac_135,
            temp_var_for_tac_136;
        double temp_var_for_const_126, temp_var_for_const_127;
        temp_var_for_tac_133 = 0.0 - 0.5;

        temp_var_for_tac_134 = temp_var_for_tac_133 * y;

        temp_var_for_tac_135 = p1 / p2;

        temp_var_for_tac_136 = temp_var_for_tac_134 + temp_var_for_tac_135;

        r += temp_var_for_tac_136;
        ;
        break;
      }
    } else {
      if (ix < IC(0x40200000)) { /* x < 8.0 */
        i = (int32_t)x;
        double temp_var_for_const_128;
        t = zero;
        computeDSub((Addr)&temp_var_for_tac_133,
                    {(Addr) &(temp_var_for_const_127 = 0.0),
                     (Addr) &(temp_var_for_const_126 = 0.5)},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:508:20");
        computeDMul((Addr)&temp_var_for_tac_134,
                    {(Addr)&temp_var_for_tac_133, (Addr)&y},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:508:27");
        computeDDiv((Addr)&temp_var_for_tac_135, {(Addr)&p1, (Addr)&p2},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:508:36");
        computeDAdd((Addr)&temp_var_for_tac_136,
                    {(Addr)&temp_var_for_tac_134, (Addr)&temp_var_for_tac_135},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:508:31");
        AssignD({(Addr)&t}, (Addr) &(temp_var_for_const_128 = zero),
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:514:11");
        ;
        double temp_var_for_tac_138;
        double temp_var_for_const_129;
        temp_var_for_tac_138 = x - ((double)i);

        y = temp_var_for_tac_138;
        computeDSub((Addr)&temp_var_for_tac_138,
                    {(Addr)&x, (Addr) &(temp_var_for_const_129 = ((double)i))},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:515:15");
        AssignD({(Addr)&y}, (Addr)&temp_var_for_tac_138,
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:515:11");
        ;
        double temp_var_for_tac_139, temp_var_for_tac_140, temp_var_for_tac_141,
            temp_var_for_tac_142, temp_var_for_tac_143, temp_var_for_tac_144,
            temp_var_for_tac_145, temp_var_for_tac_146, temp_var_for_tac_147,
            temp_var_for_tac_148, temp_var_for_tac_149, temp_var_for_tac_150,
            temp_var_for_tac_151;
        double temp_var_for_const_130, temp_var_for_const_131,
            temp_var_for_const_132, temp_var_for_const_133,
            temp_var_for_const_134, temp_var_for_const_135,
            temp_var_for_const_136;
        temp_var_for_tac_139 = y * s6;

        temp_var_for_tac_140 = s5 + temp_var_for_tac_139;

        temp_var_for_tac_141 = y * temp_var_for_tac_140;

        temp_var_for_tac_142 = s4 + temp_var_for_tac_141;

        temp_var_for_tac_143 = y * temp_var_for_tac_142;

        temp_var_for_tac_144 = s3 + temp_var_for_tac_143;

        temp_var_for_tac_145 = y * temp_var_for_tac_144;

        temp_var_for_tac_146 = s2 + temp_var_for_tac_145;

        temp_var_for_tac_147 = y * temp_var_for_tac_146;

        temp_var_for_tac_148 = s1 + temp_var_for_tac_147;

        temp_var_for_tac_149 = y * temp_var_for_tac_148;

        temp_var_for_tac_150 = s0 + temp_var_for_tac_149;

        temp_var_for_tac_151 = y * temp_var_for_tac_150;

        p = temp_var_for_tac_151;
        computeDMul((Addr)&temp_var_for_tac_139,
                    {(Addr)&y, (Addr) &(temp_var_for_const_130 = s6)},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:517:70");
        computeDAdd((Addr)&temp_var_for_tac_140,
                    {(Addr) &(temp_var_for_const_131 = s5),
                     (Addr)&temp_var_for_tac_139},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:517:66");
        computeDMul((Addr)&temp_var_for_tac_141,
                    {(Addr)&y, (Addr)&temp_var_for_tac_140},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:517:60");
        computeDAdd((Addr)&temp_var_for_tac_142,
                    {(Addr) &(temp_var_for_const_132 = s4),
                     (Addr)&temp_var_for_tac_141},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:517:56");
        computeDMul((Addr)&temp_var_for_tac_143,
                    {(Addr)&y, (Addr)&temp_var_for_tac_142},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:517:50");
        computeDAdd((Addr)&temp_var_for_tac_144,
                    {(Addr) &(temp_var_for_const_133 = s3),
                     (Addr)&temp_var_for_tac_143},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:517:46");
        computeDMul((Addr)&temp_var_for_tac_145,
                    {(Addr)&y, (Addr)&temp_var_for_tac_144},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:517:40");
        computeDAdd((Addr)&temp_var_for_tac_146,
                    {(Addr) &(temp_var_for_const_134 = s2),
                     (Addr)&temp_var_for_tac_145},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:517:36");
        computeDMul((Addr)&temp_var_for_tac_147,
                    {(Addr)&y, (Addr)&temp_var_for_tac_146},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:517:30");
        computeDAdd((Addr)&temp_var_for_tac_148,
                    {(Addr) &(temp_var_for_const_135 = s1),
                     (Addr)&temp_var_for_tac_147},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:517:26");
        computeDMul((Addr)&temp_var_for_tac_149,
                    {(Addr)&y, (Addr)&temp_var_for_tac_148},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:517:20");
        computeDAdd((Addr)&temp_var_for_tac_150,
                    {(Addr) &(temp_var_for_const_136 = s0),
                     (Addr)&temp_var_for_tac_149},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:516:21");
        computeDMul((Addr)&temp_var_for_tac_151,
                    {(Addr)&y, (Addr)&temp_var_for_tac_150},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:516:15");
        AssignD({(Addr)&p}, (Addr)&temp_var_for_tac_151,
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:516:11");
        ;
        double temp_var_for_tac_152, temp_var_for_tac_153, temp_var_for_tac_154,
            temp_var_for_tac_155, temp_var_for_tac_156, temp_var_for_tac_157,
            temp_var_for_tac_158, temp_var_for_tac_159, temp_var_for_tac_160,
            temp_var_for_tac_161, temp_var_for_tac_162, temp_var_for_tac_163;
        double temp_var_for_const_137, temp_var_for_const_138,
            temp_var_for_const_139, temp_var_for_const_140,
            temp_var_for_const_141, temp_var_for_const_142,
            temp_var_for_const_143;
        temp_var_for_tac_152 = y * r6;

        temp_var_for_tac_153 = r5 + temp_var_for_tac_152;

        temp_var_for_tac_154 = y * temp_var_for_tac_153;

        temp_var_for_tac_155 = r4 + temp_var_for_tac_154;

        temp_var_for_tac_156 = y * temp_var_for_tac_155;

        temp_var_for_tac_157 = r3 + temp_var_for_tac_156;

        temp_var_for_tac_158 = y * temp_var_for_tac_157;

        temp_var_for_tac_159 = r2 + temp_var_for_tac_158;

        temp_var_for_tac_160 = y * temp_var_for_tac_159;

        temp_var_for_tac_161 = r1 + temp_var_for_tac_160;

        temp_var_for_tac_162 = y * temp_var_for_tac_161;

        temp_var_for_tac_163 = one + temp_var_for_tac_162;

        q = temp_var_for_tac_163;
        computeDMul((Addr)&temp_var_for_tac_152,
                    {(Addr)&y, (Addr) &(temp_var_for_const_137 = r6)},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:518:71");
        computeDAdd((Addr)&temp_var_for_tac_153,
                    {(Addr) &(temp_var_for_const_138 = r5),
                     (Addr)&temp_var_for_tac_152},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:518:67");
        computeDMul((Addr)&temp_var_for_tac_154,
                    {(Addr)&y, (Addr)&temp_var_for_tac_153},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:518:61");
        computeDAdd((Addr)&temp_var_for_tac_155,
                    {(Addr) &(temp_var_for_const_139 = r4),
                     (Addr)&temp_var_for_tac_154},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:518:57");
        computeDMul((Addr)&temp_var_for_tac_156,
                    {(Addr)&y, (Addr)&temp_var_for_tac_155},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:518:51");
        computeDAdd((Addr)&temp_var_for_tac_157,
                    {(Addr) &(temp_var_for_const_140 = r3),
                     (Addr)&temp_var_for_tac_156},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:518:47");
        computeDMul((Addr)&temp_var_for_tac_158,
                    {(Addr)&y, (Addr)&temp_var_for_tac_157},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:518:41");
        computeDAdd((Addr)&temp_var_for_tac_159,
                    {(Addr) &(temp_var_for_const_141 = r2),
                     (Addr)&temp_var_for_tac_158},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:518:37");
        computeDMul((Addr)&temp_var_for_tac_160,
                    {(Addr)&y, (Addr)&temp_var_for_tac_159},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:518:31");
        computeDAdd((Addr)&temp_var_for_tac_161,
                    {(Addr) &(temp_var_for_const_142 = r1),
                     (Addr)&temp_var_for_tac_160},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:518:27");
        computeDMul((Addr)&temp_var_for_tac_162,
                    {(Addr)&y, (Addr)&temp_var_for_tac_161},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:518:21");
        computeDAdd((Addr)&temp_var_for_tac_163,
                    {(Addr) &(temp_var_for_const_143 = one),
                     (Addr)&temp_var_for_tac_162},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:518:17");
        AssignD({(Addr)&q}, (Addr)&temp_var_for_tac_163,
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:518:11");
        ;
        double temp_var_for_tac_164, temp_var_for_tac_165, temp_var_for_tac_166;
        double temp_var_for_const_144;
        temp_var_for_tac_164 = half * y;

        temp_var_for_tac_165 = p / q;

        temp_var_for_tac_166 = temp_var_for_tac_164 + temp_var_for_tac_165;

        r = temp_var_for_tac_166;
        computeDMul((Addr)&temp_var_for_tac_164,
                    {(Addr) &(temp_var_for_const_144 = half), (Addr)&y},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:519:18");
        computeDDiv((Addr)&temp_var_for_tac_165, {(Addr)&p, (Addr)&q},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:519:26");
        computeDAdd((Addr)&temp_var_for_tac_166,
                    {(Addr)&temp_var_for_tac_164, (Addr)&temp_var_for_tac_165},
                    "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:519:22");
        AssignD({(Addr)&r}, (Addr)&temp_var_for_tac_166,
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:519:11");
        ;
        double temp_var_for_const_145;
        z = one;
        AssignD({(Addr)&z}, (Addr) &(temp_var_for_const_145 = one),
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:520:11");
        ; /* lgamma(1+s) = log(s) + lgamma(s) */
        int temp_var_for_ext_19;
        temp_var_for_ext_19 = (int)i;
        switch (temp_var_for_ext_19) {
        case 7: {
          double temp_var_for_tac_167;
          double temp_var_for_const_146;
          temp_var_for_tac_167 = y + 6.0;

          z *= temp_var_for_tac_167;
          ;
        }
        /* FALLTHRU */
        case 6: {
          double temp_var_for_tac_169;
          double temp_var_for_const_147;
          temp_var_for_tac_169 = y + 5.0;

          z *= temp_var_for_tac_169;
          ;
        }
        /* FALLTHRU */
        case 5: {
          double temp_var_for_tac_171;
          double temp_var_for_const_148;
          temp_var_for_tac_171 = y + 4.0;

          z *= temp_var_for_tac_171;
          ;
        }
        /* FALLTHRU */
        case 4: {
          double temp_var_for_tac_173;
          double temp_var_for_const_149;
          temp_var_for_tac_173 = y + 3.0;

          z *= temp_var_for_tac_173;
          ;
        }
        /* FALLTHRU */
        case 3: {
          double temp_var_for_tac_175;
          double temp_var_for_const_150;
          temp_var_for_tac_175 = y + 2.0;

          z *= temp_var_for_tac_175;
          ;
        }
          /* FALLTHRU */
          double temp_var_for_callexp_16;

          temp_var_for_callexp_16 = __ieee754_log(z);
          r += temp_var_for_callexp_16;
          ;
          break;
        }
        /* 8.0 <= x < 2**58 */
      } else {
        if (ix < IC(0x43900000)) {
          double temp_var_for_const_151;
          double temp_var_for_callexp_17;

          temp_var_for_callexp_17 = __ieee754_log(x);
          t = temp_var_for_callexp_17;
          computeDAdd(
              (Addr)&temp_var_for_tac_167,
              {(Addr)&y, (Addr) &(temp_var_for_const_146 = 6.0)},
              "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:525:19");
          computeDAdd(
              (Addr)&temp_var_for_tac_169,
              {(Addr)&y, (Addr) &(temp_var_for_const_147 = 5.0)},
              "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:529:19");
          computeDAdd(
              (Addr)&temp_var_for_tac_171,
              {(Addr)&y, (Addr) &(temp_var_for_const_148 = 4.0)},
              "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:533:19");
          computeDAdd(
              (Addr)&temp_var_for_tac_173,
              {(Addr)&y, (Addr) &(temp_var_for_const_149 = 3.0)},
              "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:537:19");
          computeDAdd(
              (Addr)&temp_var_for_tac_175,
              {(Addr)&y, (Addr) &(temp_var_for_const_150 = 2.0)},
              "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:541:19");
          AssignD({(Addr)&t},
                  (Addr) &(temp_var_for_const_151 = temp_var_for_callexp_17),
                  "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:550:13");
          ;
          double temp_var_for_tac_178;
          double temp_var_for_const_152;
          temp_var_for_tac_178 = one / x;

          z = temp_var_for_tac_178;
          computeDDiv(
              (Addr)&temp_var_for_tac_178,
              {(Addr) &(temp_var_for_const_152 = one), (Addr)&x},
              "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:551:19");
          AssignD({(Addr)&z}, (Addr)&temp_var_for_tac_178,
                  "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:551:13");
          ;
          double temp_var_for_tac_179;
          temp_var_for_tac_179 = z * z;

          y = temp_var_for_tac_179;
          computeDMul(
              (Addr)&temp_var_for_tac_179, {(Addr)&z, (Addr)&z},
              "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:552:17");
          AssignD({(Addr)&y}, (Addr)&temp_var_for_tac_179,
                  "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:552:13");
          ;
          double temp_var_for_tac_180, temp_var_for_tac_181,
              temp_var_for_tac_182, temp_var_for_tac_183, temp_var_for_tac_184,
              temp_var_for_tac_185, temp_var_for_tac_186, temp_var_for_tac_187,
              temp_var_for_tac_188, temp_var_for_tac_189, temp_var_for_tac_190,
              temp_var_for_tac_191;
          double temp_var_for_const_153, temp_var_for_const_154,
              temp_var_for_const_155, temp_var_for_const_156,
              temp_var_for_const_157, temp_var_for_const_158,
              temp_var_for_const_159;
          temp_var_for_tac_180 = y * w6;

          temp_var_for_tac_181 = w5 + temp_var_for_tac_180;

          temp_var_for_tac_182 = y * temp_var_for_tac_181;

          temp_var_for_tac_183 = w4 + temp_var_for_tac_182;

          temp_var_for_tac_184 = y * temp_var_for_tac_183;

          temp_var_for_tac_185 = w3 + temp_var_for_tac_184;

          temp_var_for_tac_186 = y * temp_var_for_tac_185;

          temp_var_for_tac_187 = w2 + temp_var_for_tac_186;

          temp_var_for_tac_188 = y * temp_var_for_tac_187;

          temp_var_for_tac_189 = w1 + temp_var_for_tac_188;

          temp_var_for_tac_190 = z * temp_var_for_tac_189;

          temp_var_for_tac_191 = w0 + temp_var_for_tac_190;

          w = temp_var_for_tac_191;
          computeDMul(
              (Addr)&temp_var_for_tac_180,
              {(Addr)&y, (Addr) &(temp_var_for_const_153 = w6)},
              "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:554:67");
          computeDAdd(
              (Addr)&temp_var_for_tac_181,
              {(Addr) &(temp_var_for_const_154 = w5),
               (Addr)&temp_var_for_tac_180},
              "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:554:63");
          computeDMul(
              (Addr)&temp_var_for_tac_182,
              {(Addr)&y, (Addr)&temp_var_for_tac_181},
              "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:554:57");
          computeDAdd(
              (Addr)&temp_var_for_tac_183,
              {(Addr) &(temp_var_for_const_155 = w4),
               (Addr)&temp_var_for_tac_182},
              "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:554:53");
          computeDMul(
              (Addr)&temp_var_for_tac_184,
              {(Addr)&y, (Addr)&temp_var_for_tac_183},
              "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:554:47");
          computeDAdd(
              (Addr)&temp_var_for_tac_185,
              {(Addr) &(temp_var_for_const_156 = w3),
               (Addr)&temp_var_for_tac_184},
              "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:554:43");
          computeDMul(
              (Addr)&temp_var_for_tac_186,
              {(Addr)&y, (Addr)&temp_var_for_tac_185},
              "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:554:37");
          computeDAdd(
              (Addr)&temp_var_for_tac_187,
              {(Addr) &(temp_var_for_const_157 = w2),
               (Addr)&temp_var_for_tac_186},
              "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:554:33");
          computeDMul(
              (Addr)&temp_var_for_tac_188,
              {(Addr)&y, (Addr)&temp_var_for_tac_187},
              "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:554:27");
          computeDAdd(
              (Addr)&temp_var_for_tac_189,
              {(Addr) &(temp_var_for_const_158 = w1),
               (Addr)&temp_var_for_tac_188},
              "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:554:23");
          computeDMul(
              (Addr)&temp_var_for_tac_190,
              {(Addr)&z, (Addr)&temp_var_for_tac_189},
              "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:554:17");
          computeDAdd(
              (Addr)&temp_var_for_tac_191,
              {(Addr) &(temp_var_for_const_159 = w0),
               (Addr)&temp_var_for_tac_190},
              "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:553:18");
          AssignD({(Addr)&w}, (Addr)&temp_var_for_tac_191,
                  "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:553:13");
          ;
          double temp_var_for_tac_192, temp_var_for_tac_193,
              temp_var_for_tac_194, temp_var_for_tac_195;
          double temp_var_for_const_160, temp_var_for_const_161;
          temp_var_for_tac_192 = x - half;

          temp_var_for_tac_193 = t - one;

          temp_var_for_tac_194 = temp_var_for_tac_192 * temp_var_for_tac_193;

          temp_var_for_tac_195 = temp_var_for_tac_194 + w;

          r = temp_var_for_tac_195;
          computeDSub(
              (Addr)&temp_var_for_tac_192,
              {(Addr)&x, (Addr) &(temp_var_for_const_160 = half)},
              "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:555:18");
          computeDSub(
              (Addr)&temp_var_for_tac_193,
              {(Addr)&t, (Addr) &(temp_var_for_const_161 = one)},
              "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:555:31");
          computeDMul(
              (Addr)&temp_var_for_tac_194,
              {(Addr)&temp_var_for_tac_192, (Addr)&temp_var_for_tac_193},
              "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:555:26");
          computeDAdd(
              (Addr)&temp_var_for_tac_195,
              {(Addr)&temp_var_for_tac_194, (Addr)&w},
              "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:555:38");
          AssignD({(Addr)&r}, (Addr)&temp_var_for_tac_195,
                  "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:555:13");
          ;
        } else
        /* 2**58 <= x <= inf */
        {
          double temp_var_for_tac_196, temp_var_for_tac_197;
          double temp_var_for_const_162, temp_var_for_const_163;
          double temp_var_for_callexp_18;

          temp_var_for_callexp_18 = __ieee754_log(x);
          temp_var_for_tac_196 = temp_var_for_callexp_18 - one;

          temp_var_for_tac_197 = x * temp_var_for_tac_196;

          r = temp_var_for_tac_197;
          computeDSub(
              (Addr)&temp_var_for_tac_196,
              {(Addr) &(temp_var_for_const_163 = temp_var_for_callexp_18),
               (Addr) &(temp_var_for_const_162 = one)},
              "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:559:37");
          computeDMul(
              (Addr)&temp_var_for_tac_197,
              {(Addr)&x, (Addr)&temp_var_for_tac_196},
              "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:559:17");
          AssignD({(Addr)&r}, (Addr)&temp_var_for_tac_197,
                  "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:559:13");
          ;
        }
      }
    }
  }

  if (hx < 0) {
    double temp_var_for_ext_20;
    double temp_var_for_tac_198;
    temp_var_for_tac_198 = nadj - r;

    temp_var_for_ext_20 = temp_var_for_tac_198;
    computeDSub((Addr)&temp_var_for_tac_198, {(Addr)&nadj, (Addr)&r},
                "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:567:32");
    AssignD({(Addr)&temp_var_for_ext_20}, (Addr)&temp_var_for_tac_198,
            "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:567:25");
    ; // r
    /*(one)(__ieee754_log(x))(x)(one)(__ieee754_log(x))(r)(nadj)*/
    r = temp_var_for_ext_20;
    AssignD({(Addr)&r}, (Addr)&temp_var_for_ext_20,
            "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:569:7");
    ;
  }

  double temp_var_for_ext_21;
  temp_var_for_ext_21 = r;
  AssignD({(Addr)&temp_var_for_ext_21}, (Addr)&r,
          "/home/shijia/Public/testprogram/e_lgamma_r.c_e.c:573:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_21", (Addr)&temp_var_for_ext_21));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_21;
}
