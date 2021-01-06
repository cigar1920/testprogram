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

/* Long double expansions are
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

/* __ieee754_lgammal_r(x, signgamp)
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
 *   2. Rational approximation in the primary interval [2,3]
 *	We use the following approximation:
 *		s = x-2.0;
 *		lgamma(x) = 0.5*s + s*P(s)/Q(s)
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

#ifndef __NO_LONG_DOUBLE_MATH

static long double sin_pi_l(long double x) {
  long double y, z;
  int32_t n, ix;
  uint32_t se, i0, i1;

  static const long double zero = 0.0L;
  static const long double half = 0.5L;
  static const long double one = 1.0L;
  static const long double pi = 3.14159265358979323846264L;
  static const long double two63 = 9.223372036854775808e18L;

  long double temp_var_for_const_0;
  ew_u.value = x;
  AssignLd({(Addr) &(temp_var_for_const_0 = ew_u.value)}, (Addr)&x,
           "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:111:3 "
           "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
  ;
  ix = se & 0x7fff;
  ix = (ix << 16) | (i0 >> 16);
  if (ix < IC(0x3ffd8000)) /* 0.25 */
  {
    long double temp_var_for_ext_0;
    long double temp_var_for_tac_0;
    long double temp_var_for_const_1, temp_var_for_const_2;
    long double temp_var_for_callexp_0;

    temp_var_for_tac_0 = pi * x;

    temp_var_for_callexp_0 = __ieee754_sinl(temp_var_for_tac_0);
    temp_var_for_ext_0 = temp_var_for_callexp_0;
    computeLdMul((Addr)&temp_var_for_tac_0,
                 {(Addr) &(temp_var_for_const_1 = pi), (Addr)&x},
                 "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:117:44");
    AssignLd({(Addr)&temp_var_for_ext_0},
             (Addr) &(temp_var_for_const_2 = temp_var_for_callexp_0),
             "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:117:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  long double temp_var_for_tac_1;
  long double temp_var_for_const_3;
  temp_var_for_tac_1 = 0.0 - x;

  y = temp_var_for_tac_1;
  computeLdSub((Addr)&temp_var_for_tac_1,
               {(Addr) &(temp_var_for_const_3 = 0.0), (Addr)&x},
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:123:12");
  AssignLd({(Addr)&y}, (Addr)&temp_var_for_tac_1,
           "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:123:5");
  ; /* x is assume negative */

  /*
   * argument reduction, make sure inexact flag not raised if input
   * is an integer
   */
  long double temp_var_for_const_4;
  long double temp_var_for_callexp_1;

  temp_var_for_callexp_1 = __ieee754_floorl(y);
  z = temp_var_for_callexp_1;
  AssignLd({(Addr)&z}, (Addr) &(temp_var_for_const_4 = temp_var_for_callexp_1),
           "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:129:5");
  ;
  if (int temp_var_for_tac_2; temp_var_for_tac_2 = z != y;

      ) { /* inexact anyway */
    y *= 0.5;
    ;
    long double temp_var_for_ext_1;
    long double temp_var_for_tac_4, temp_var_for_tac_5;
    long double temp_var_for_const_5, temp_var_for_const_6;
    long double temp_var_for_callexp_2;

    temp_var_for_callexp_2 = __ieee754_floorl(y);
    temp_var_for_tac_4 = y - temp_var_for_callexp_2;

    temp_var_for_tac_5 = 2.0 * temp_var_for_tac_4;

    temp_var_for_ext_1 = temp_var_for_tac_5;
    compute((Addr)&temp_var_for_tac_2, {(Addr)&z, (Addr)&y},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:130:9");
    computeLdSub(
        (Addr)&temp_var_for_tac_4,
        {(Addr)&y, (Addr) &(temp_var_for_const_5 = temp_var_for_callexp_2)},
        "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:133:35");
    computeLdMul(
        (Addr)&temp_var_for_tac_5,
        {(Addr) &(temp_var_for_const_6 = 2.0), (Addr)&temp_var_for_tac_4},
        "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:133:30");
    AssignLd({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_5,
             "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:133:24");
    ; // y
    /*(0.5)(y)(__ieee754_floorl(y))(y)(2.0)*/
    y = temp_var_for_ext_1;
    AssignLd({(Addr)&y}, (Addr)&temp_var_for_ext_1,
             "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:135:7");
    ; /* y = |x| mod 2.0 */
    n = (int32_t)(long double temp_var_for_tac_6;
                  long double temp_var_for_const_7;
                  temp_var_for_tac_6 = y * 4.0;

                  );
  } else {
    if (ix >= IC(0x403f8000)) /* 2^64 */
    {
      long double temp_var_for_ext_2;
      long double temp_var_for_const_8;
      temp_var_for_ext_2 = zero;
      computeLdMul((Addr)&temp_var_for_tac_6,
                   {(Addr)&y, (Addr) &(temp_var_for_const_7 = 4.0)},
                   "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:136:21");
      AssignLd({(Addr)&temp_var_for_ext_2},
               (Addr) &(temp_var_for_const_8 = zero),
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:141:26");
      ; // y
      /*(__ieee754_floorl(y))(y)(2.0)(__ieee754_floorl(y))(y)(4.0)(y)(zero)*/
      y = temp_var_for_ext_2;
      AssignLd({(Addr)&y}, (Addr)&temp_var_for_ext_2,
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:143:9");
      ;
      n = 0; /* y must be even */
    } else {
      if (ix < IC(0x403e8000)) /* 2^63 */
      {
        long double temp_var_for_tac_7;
        long double temp_var_for_const_9;
        temp_var_for_tac_7 = y + two63;

        z = temp_var_for_tac_7;
        computeLdAdd(
            (Addr)&temp_var_for_tac_7,
            {(Addr)&y, (Addr) &(temp_var_for_const_9 = two63)},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:148:15");
        AssignLd({(Addr)&z}, (Addr)&temp_var_for_tac_7,
                 "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:148:11");
        ;
      }
      /* exact */
      long double temp_var_for_const_10;
      ew_u.value = z;
      AssignLd({(Addr) &(temp_var_for_const_10 = ew_u.value)}, (Addr)&z,
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:151:7 "
               "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
      ;
      n = i1 & 1;
      long double temp_var_for_const_11;
      y = n;
      AssignLd({(Addr)&y}, (Addr) &(temp_var_for_const_11 = n),
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:153:9");
      ;
      n <<= 2;
    }
  }

  int temp_var_for_ext_3;
  temp_var_for_ext_3 = (int)n;
  switch (temp_var_for_ext_3) {
  case 0: {
    long double temp_var_for_tac_8;
    long double temp_var_for_const_12, temp_var_for_const_13;
    long double temp_var_for_callexp_3;

    temp_var_for_tac_8 = pi * y;

    temp_var_for_callexp_3 = __ieee754_sinl(temp_var_for_tac_8);
    y = temp_var_for_callexp_3;
    computeLdMul((Addr)&temp_var_for_tac_8,
                 {(Addr) &(temp_var_for_const_12 = pi), (Addr)&y},
                 "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:162:27");
    AssignLd({(Addr)&y},
             (Addr) &(temp_var_for_const_13 = temp_var_for_callexp_3),
             "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:162:7");
    ;
  }

  break;
  case 1: {
  case 2: {
    long double temp_var_for_ext_4;
    long double temp_var_for_tac_9, temp_var_for_tac_10;
    long double temp_var_for_const_14, temp_var_for_const_15,
        temp_var_for_const_16;
    long double temp_var_for_callexp_4;

    temp_var_for_tac_9 = half - y;

    temp_var_for_tac_10 = pi * temp_var_for_tac_9;

    temp_var_for_callexp_4 = __ieee754_cosl(temp_var_for_tac_10);
    temp_var_for_ext_4 = temp_var_for_callexp_4;
    computeLdSub((Addr)&temp_var_for_tac_9,
                 {(Addr) &(temp_var_for_const_14 = half), (Addr)&y},
                 "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:169:52");
    computeLdMul(
        (Addr)&temp_var_for_tac_10,
        {(Addr) &(temp_var_for_const_15 = pi), (Addr)&temp_var_for_tac_9},
        "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:169:44");
    AssignLd({(Addr)&temp_var_for_ext_4},
             (Addr) &(temp_var_for_const_16 = temp_var_for_callexp_4),
             "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:169:24");
    ; // y
    /*(y)(pi)(__ieee754_cosl(pi * (half - y)))*/
    y = temp_var_for_ext_4;
    AssignLd({(Addr)&y}, (Addr)&temp_var_for_ext_4,
             "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:171:7");
    ;
  }

  }

  break;
  case 3: {
  case 4: {
    long double temp_var_for_ext_5;
    long double temp_var_for_tac_11, temp_var_for_tac_12;
    long double temp_var_for_const_17, temp_var_for_const_18,
        temp_var_for_const_19;
    long double temp_var_for_callexp_5;

    temp_var_for_tac_11 = one - y;

    temp_var_for_tac_12 = pi * temp_var_for_tac_11;

    temp_var_for_callexp_5 = __ieee754_sinl(temp_var_for_tac_12);
    temp_var_for_ext_5 = temp_var_for_callexp_5;
    computeLdSub((Addr)&temp_var_for_tac_11,
                 {(Addr) &(temp_var_for_const_17 = one), (Addr)&y},
                 "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:180:51");
    computeLdMul(
        (Addr)&temp_var_for_tac_12,
        {(Addr) &(temp_var_for_const_18 = pi), (Addr)&temp_var_for_tac_11},
        "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:180:44");
    AssignLd({(Addr)&temp_var_for_ext_5},
             (Addr) &(temp_var_for_const_19 = temp_var_for_callexp_5),
             "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:180:24");
    ; // y
    /*(y)(half)(pi)(y)(half)(__ieee754_sinl(pi * (one - y)))*/
    y = temp_var_for_ext_5;
    AssignLd({(Addr)&y}, (Addr)&temp_var_for_ext_5,
             "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:182:7");
    ;
  }

  }

  break;
  case 5: {
  case 6: {
    long double temp_var_for_ext_6;
    long double temp_var_for_tac_13, temp_var_for_tac_14, temp_var_for_tac_15;
    long double temp_var_for_const_20, temp_var_for_const_21,
        temp_var_for_const_22, temp_var_for_const_23;
    long double temp_var_for_callexp_6;

    temp_var_for_tac_13 = y - 1.5;

    temp_var_for_tac_14 = pi * temp_var_for_tac_13;

    temp_var_for_callexp_6 = __ieee754_cosl(temp_var_for_tac_14);
    temp_var_for_tac_15 = 0.0 - temp_var_for_callexp_6;

    temp_var_for_ext_6 = temp_var_for_tac_15;
    computeLdSub((Addr)&temp_var_for_tac_13,
                 {(Addr)&y, (Addr) &(temp_var_for_const_20 = 1.5)},
                 "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:191:56");
    computeLdMul(
        (Addr)&temp_var_for_tac_14,
        {(Addr) &(temp_var_for_const_21 = pi), (Addr)&temp_var_for_tac_13},
        "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:191:51");
    computeLdSub((Addr)&temp_var_for_tac_15,
                 {(Addr) &(temp_var_for_const_23 = 0.0),
                  (Addr) &(temp_var_for_const_22 = temp_var_for_callexp_6)},
                 "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:191:31");
    AssignLd({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_15,
             "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:191:24");
    ; // y
      /*(y)(one)(pi)(y)(one)(__ieee754_cosl(pi * (y - 1.5)))(__ieee754_cosl(pi *
       * (y - 1.5)))*/
    y = temp_var_for_ext_6;
    AssignLd({(Addr)&y}, (Addr)&temp_var_for_ext_6,
             "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:194:7");
    ;
  }

  }

  break;
  default: {
    long double temp_var_for_tac_16, temp_var_for_tac_17;
    long double temp_var_for_const_24, temp_var_for_const_25,
        temp_var_for_const_26;
    long double temp_var_for_callexp_7;

    temp_var_for_tac_16 = y - 2.0;

    temp_var_for_tac_17 = pi * temp_var_for_tac_16;

    temp_var_for_callexp_7 = __ieee754_sinl(temp_var_for_tac_17);
    y = temp_var_for_callexp_7;
    computeLdSub((Addr)&temp_var_for_tac_16,
                 {(Addr)&y, (Addr) &(temp_var_for_const_24 = 2.0)},
                 "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:201:32");
    computeLdMul(
        (Addr)&temp_var_for_tac_17,
        {(Addr) &(temp_var_for_const_25 = pi), (Addr)&temp_var_for_tac_16},
        "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:201:27");
    AssignLd({(Addr)&y},
             (Addr) &(temp_var_for_const_26 = temp_var_for_callexp_7),
             "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:201:7");
    ;
  }

  break;
  }
  long double temp_var_for_ext_7;
  long double temp_var_for_const_27;
  temp_var_for_ext_7 = (-(y));
  AssignLd({(Addr)&temp_var_for_ext_7},
           (Addr) &(temp_var_for_const_27 = (-(y))),
           "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:207:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
  callExp++; /*identify the function is  add move tmpShadow*/
  return (double temp_var_for_tac_18;
          double temp_var_for_const_28, temp_var_for_const_29;
          temp_var_for_tac_18 = 0.0 - 7;

          );
}

long double __ieee754_lgammal_r(long double x, int *signgamp) {
  long double t, y, z, nadj = 0, p, p1, p2, q, r, w;
  int32_t i, ix;
  uint32_t se, i0, i1;

  static const long double half = 0.5L;
  static const long double one = 1.0L;
  static const long double pi = 3.14159265358979323846264L;
  /* lgam(1+x) = 0.5 x + x a(x)/b(x)
     -0.268402099609375 <= x <= 0
     peak relative error 6.6e-22 */
  static const long double a0 =
      (long double temp_var_for_tac_19;
       long double temp_var_for_const_30, temp_var_for_const_31;
       temp_var_for_tac_19 = 0.0 - 6.343246574721079391729402781192128239938E2L;

       );
  static const long double a1 = 1.856560238672465796768677717168371401378E3L;
  static const long double a2 = 2.404733102163746263689288466865843408429E3L;
  static const long double a3 = 8.804188795790383497379532868917517596322E2L;
  static const long double a4 = 1.135361354097447729740103745999661157426E2L;
  static const long double a5 = 3.766956539107615557608581581190400021285E0L;
  static const long double b0 = 8.214973713960928795704317259806842490498E3L;
  static const long double b1 = 1.026343508841367384879065363925870888012E4L;
  static const long double b2 = 4.553337477045763320522762343132210919277E3L;
  static const long double b3 = 8.506975785032585797446253359230031874803E2L;
  static const long double b4 = 6.042447899703295436820744186992189445813E1L;
  /* static const long double b5 =  1.000000000000000000000000000000000000000E0
   */
  static const long double tc = 1.4616321449683623412626595423257213284682E0L;
  static const long double tf =
      (double temp_var_for_tac_20;
       double temp_var_for_const_32, temp_var_for_const_33;
       temp_var_for_tac_20 =
           0.0 - 1.2148629053584961146050602565082954242826E-1;

       ); /* double precision */
  /* tt = (tail of tf), i.e. tf + tt has extended precision. */
  static const long double tt = 3.3649914684731379602768989080467587736363E-18L;
  /* lgam ( 1.4616321449683623412626595423257213284682E0 ) =
     -1.2148629053584960809551455717769158215135617312999903886372437313313530E-1
     */
  /* lgam (x + tc) = tf + tt + x g(x)/h(x)
     - 0.230003726999612341262659542325721328468 <= x
     <= 0.2699962730003876587373404576742786715318
     peak relative error 2.1e-21 */
  static const long double g0 = 3.645529916721223331888305293534095553827E-18L;
  static const long double g1 = 5.126654642791082497002594216163574795690E3L;
  static const long double g2 = 8.828603575854624811911631336122070070327E3L;
  static const long double g3 = 5.464186426932117031234820886525701595203E3L;
  static const long double g4 = 1.455427403530884193180776558102868592293E3L;
  static const long double g5 = 1.541735456969245924860307497029155838446E2L;
  static const long double g6 = 4.335498275274822298341872707453445815118E0L;
  static const long double h0 = 1.059584930106085509696730443974495979641E4L;
  static const long double h1 = 2.147921653490043010629481226937850618860E4L;
  static const long double h2 = 1.643014770044524804175197151958100656728E4L;
  static const long double h3 = 5.869021995186925517228323497501767586078E3L;
  static const long double h4 = 9.764244777714344488787381271643502742293E2L;
  static const long double h5 = 6.442485441570592541741092969581997002349E1L;
  /* static const long double h6 = 1.000000000000000000000000000000000000000E0
   */

  /* lgam (x+1) = -0.5 x + x u(x)/v(x)
     -0.100006103515625 <= x <= 0.231639862060546875
     peak relative error 1.3e-21 */
  static const long double u0 =
      (long double temp_var_for_tac_21;
       long double temp_var_for_const_34, temp_var_for_const_35;
       temp_var_for_tac_21 = 0.0 - 8.886217500092090678492242071879342025627E1L;

       );
  static const long double u1 = 6.840109978129177639438792958320783599310E2L;
  static const long double u2 = 2.042626104514127267855588786511809932433E3L;
  static const long double u3 = 1.911723903442667422201651063009856064275E3L;
  static const long double u4 = 7.447065275665887457628865263491667767695E2L;
  static const long double u5 = 1.132256494121790736268471016493103952637E2L;
  static const long double u6 = 4.484398885516614191003094714505960972894E0L;
  static const long double v0 = 1.150830924194461522996462401210374632929E3L;
  static const long double v1 = 3.399692260848747447377972081399737098610E3L;
  static const long double v2 = 3.786631705644460255229513563657226008015E3L;
  static const long double v3 = 1.966450123004478374557778781564114347876E3L;
  static const long double v4 = 4.741359068914069299837355438370682773122E2L;
  static const long double v5 = 4.508989649747184050907206782117647852364E1L;
  /* static const long double v6 =  1.000000000000000000000000000000000000000E0
   */

  /* lgam (x+2) = .5 x + x s(x)/r(x)
     0 <= x <= 1
     peak relative error 7.2e-22 */
  static const long double s0 = 1.454726263410661942989109455292824853344E6L;
  static const long double s1 =
      (long double temp_var_for_tac_22;
       long double temp_var_for_const_36, temp_var_for_const_37;
       temp_var_for_tac_22 = 0.0 - 3.901428390086348447890408306153378922752E6L;

       );
  static const long double s2 =
      (long double temp_var_for_tac_23;
       long double temp_var_for_const_38, temp_var_for_const_39;
       temp_var_for_tac_23 = 0.0 - 6.573568698209374121847873064292963089438E6L;

       );
  static const long double s3 =
      (long double temp_var_for_tac_24;
       long double temp_var_for_const_40, temp_var_for_const_41;
       temp_var_for_tac_24 = 0.0 - 3.319055881485044417245964508099095984643E6L;

       );
  static const long double s4 =
      (long double temp_var_for_tac_25;
       long double temp_var_for_const_42, temp_var_for_const_43;
       temp_var_for_tac_25 = 0.0 - 7.094891568758439227560184618114707107977E5L;

       );
  static const long double s5 =
      (long double temp_var_for_tac_26;
       long double temp_var_for_const_44, temp_var_for_const_45;
       temp_var_for_tac_26 = 0.0 - 6.263426646464505837422314539808112478303E4L;

       );
  static const long double s6 =
      (long double temp_var_for_tac_27;
       long double temp_var_for_const_46, temp_var_for_const_47;
       temp_var_for_tac_27 = 0.0 - 1.684926520999477529949915657519454051529E3L;

       );
  static const long double r0 =
      (long double temp_var_for_tac_28;
       long double temp_var_for_const_48, temp_var_for_const_49;
       temp_var_for_tac_28 = 0.0 - 1.883978160734303518163008696712983134698E7L;

       );
  static const long double r1 =
      (long double temp_var_for_tac_29;
       long double temp_var_for_const_50, temp_var_for_const_51;
       temp_var_for_tac_29 = 0.0 - 2.815206082812062064902202753264922306830E7L;

       );
  static const long double r2 =
      (long double temp_var_for_tac_30;
       long double temp_var_for_const_52, temp_var_for_const_53;
       temp_var_for_tac_30 = 0.0 - 1.600245495251915899081846093343626358398E7L;

       );
  static const long double r3 =
      (long double temp_var_for_tac_31;
       long double temp_var_for_const_54, temp_var_for_const_55;
       temp_var_for_tac_31 = 0.0 - 4.310526301881305003489257052083370058799E6L;

       );
  static const long double r4 =
      (long double temp_var_for_tac_32;
       long double temp_var_for_const_56, temp_var_for_const_57;
       temp_var_for_tac_32 = 0.0 - 5.563807682263923279438235987186184968542E5L;

       );
  static const long double r5 =
      (long double temp_var_for_tac_33;
       long double temp_var_for_const_58, temp_var_for_const_59;
       temp_var_for_tac_33 = 0.0 - 3.027734654434169996032905158145259713083E4L;

       );
  static const long double r6 =
      (long double temp_var_for_tac_34;
       long double temp_var_for_const_60, temp_var_for_const_61;
       temp_var_for_tac_34 = 0.0 - 4.501995652861105629217250715790764371267E2L;

       );
  /* static const long double r6 =  1.000000000000000000000000000000000000000E0
   */

  /* lgam(x) = ( x - 0.5 ) * log(x) - x + LS2PI + 1/x w(1/x^2)
     x >= 8
     Peak relative error 1.51e-21
     w0 = LS2PI - 0.5 */
  static const long double w0 = 4.189385332046727417803e-1L;
  static const long double w1 = 8.333333333333331447505E-2L;
  static const long double w2 =
      (long double temp_var_for_tac_35;
       long double temp_var_for_const_62, temp_var_for_const_63;
       temp_var_for_tac_35 = 0.0 - 2.777777777750349603440E-3L;

       );
  static const long double w3 = 7.936507795855070755671E-4L;
  static const long double w4 =
      (long double temp_var_for_tac_36;
       long double temp_var_for_const_64, temp_var_for_const_65;
       temp_var_for_tac_36 = 0.0 - 5.952345851765688514613E-4L;

       );
  static const long double w5 = 8.412723297322498080632E-4L;
  static const long double w6 =
      (long double temp_var_for_tac_37;
       long double temp_var_for_const_66, temp_var_for_const_67;
       temp_var_for_tac_37 = 0.0 - 1.880801938119376907179E-3L;

       );
  static const long double w7 = 4.885026142432270781165E-3L;
  static const long double zero = 0.0L;

  *signgamp = 1;
  long double temp_var_for_const_68;
  ew_u.value = x;
  computeDSub((Addr)&temp_var_for_tac_18,
              {(Addr) &(temp_var_for_const_29 = 0.0),
               (Addr) &(temp_var_for_const_28 = 7)},
              "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:210:15");
  computeLdSub((Addr)&temp_var_for_tac_19,
               {(Addr) &(temp_var_for_const_31 = 0.0),
                (Addr) &(temp_var_for_const_30 =
                             6.343246574721079391729402781192128239938E2L)},
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:225:12");
  computeDSub((Addr)&temp_var_for_tac_20,
              {(Addr) &(temp_var_for_const_33 = 0.0),
               (Addr) &(temp_var_for_const_32 =
                            1.2148629053584961146050602565082954242826E-1)},
              "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:240:12");
  computeLdSub((Addr)&temp_var_for_tac_21,
               {(Addr) &(temp_var_for_const_35 = 0.0),
                (Addr) &(temp_var_for_const_34 =
                             8.886217500092090678492242071879342025627E1L)},
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:271:12");
  computeLdSub((Addr)&temp_var_for_tac_22,
               {(Addr) &(temp_var_for_const_37 = 0.0),
                (Addr) &(temp_var_for_const_36 =
                             3.901428390086348447890408306153378922752E6L)},
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:292:12");
  computeLdSub((Addr)&temp_var_for_tac_23,
               {(Addr) &(temp_var_for_const_39 = 0.0),
                (Addr) &(temp_var_for_const_38 =
                             6.573568698209374121847873064292963089438E6L)},
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:294:12");
  computeLdSub((Addr)&temp_var_for_tac_24,
               {(Addr) &(temp_var_for_const_41 = 0.0),
                (Addr) &(temp_var_for_const_40 =
                             3.319055881485044417245964508099095984643E6L)},
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:296:12");
  computeLdSub((Addr)&temp_var_for_tac_25,
               {(Addr) &(temp_var_for_const_43 = 0.0),
                (Addr) &(temp_var_for_const_42 =
                             7.094891568758439227560184618114707107977E5L)},
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:298:12");
  computeLdSub((Addr)&temp_var_for_tac_26,
               {(Addr) &(temp_var_for_const_45 = 0.0),
                (Addr) &(temp_var_for_const_44 =
                             6.263426646464505837422314539808112478303E4L)},
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:300:12");
  computeLdSub((Addr)&temp_var_for_tac_27,
               {(Addr) &(temp_var_for_const_47 = 0.0),
                (Addr) &(temp_var_for_const_46 =
                             1.684926520999477529949915657519454051529E3L)},
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:302:12");
  computeLdSub((Addr)&temp_var_for_tac_28,
               {(Addr) &(temp_var_for_const_49 = 0.0),
                (Addr) &(temp_var_for_const_48 =
                             1.883978160734303518163008696712983134698E7L)},
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:304:12");
  computeLdSub((Addr)&temp_var_for_tac_29,
               {(Addr) &(temp_var_for_const_51 = 0.0),
                (Addr) &(temp_var_for_const_50 =
                             2.815206082812062064902202753264922306830E7L)},
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:306:12");
  computeLdSub((Addr)&temp_var_for_tac_30,
               {(Addr) &(temp_var_for_const_53 = 0.0),
                (Addr) &(temp_var_for_const_52 =
                             1.600245495251915899081846093343626358398E7L)},
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:308:12");
  computeLdSub((Addr)&temp_var_for_tac_31,
               {(Addr) &(temp_var_for_const_55 = 0.0),
                (Addr) &(temp_var_for_const_54 =
                             4.310526301881305003489257052083370058799E6L)},
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:310:12");
  computeLdSub((Addr)&temp_var_for_tac_32,
               {(Addr) &(temp_var_for_const_57 = 0.0),
                (Addr) &(temp_var_for_const_56 =
                             5.563807682263923279438235987186184968542E5L)},
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:312:12");
  computeLdSub((Addr)&temp_var_for_tac_33,
               {(Addr) &(temp_var_for_const_59 = 0.0),
                (Addr) &(temp_var_for_const_58 =
                             3.027734654434169996032905158145259713083E4L)},
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:314:12");
  computeLdSub((Addr)&temp_var_for_tac_34,
               {(Addr) &(temp_var_for_const_61 = 0.0),
                (Addr) &(temp_var_for_const_60 =
                             4.501995652861105629217250715790764371267E2L)},
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:316:12");
  computeLdSub((Addr)&temp_var_for_tac_35,
               {(Addr) &(temp_var_for_const_63 = 0.0),
                (Addr) &(temp_var_for_const_62 = 2.777777777750349603440E-3L)},
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:326:38");
  computeLdSub((Addr)&temp_var_for_tac_36,
               {(Addr) &(temp_var_for_const_65 = 0.0),
                (Addr) &(temp_var_for_const_64 = 5.952345851765688514613E-4L)},
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:328:38");
  computeLdSub((Addr)&temp_var_for_tac_37,
               {(Addr) &(temp_var_for_const_67 = 0.0),
                (Addr) &(temp_var_for_const_66 = 1.880801938119376907179E-3L)},
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:330:38");
  AssignLd({(Addr) &(temp_var_for_const_68 = ew_u.value)}, (Addr)&x,
           "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:335:3 "
           "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
  ;
  ix = se & 0x7fff;

  if ((ix | i0 | i1) == 0) {
    if (se & 0x8000) {
      *signgamp = -1;
    }

    long double temp_var_for_ext_8;
    long double temp_var_for_tac_38;
    long double temp_var_for_const_69, temp_var_for_const_70;
    long double temp_var_for_callexp_8;

    temp_var_for_callexp_8 = fabsl(x);
    temp_var_for_tac_38 = one / temp_var_for_callexp_8;

    temp_var_for_ext_8 = temp_var_for_tac_38;
    computeLdDiv((Addr)&temp_var_for_tac_38,
                 {(Addr) &(temp_var_for_const_70 = one),
                  (Addr) &(temp_var_for_const_69 = temp_var_for_callexp_8)},
                 "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:344:30");
    AssignLd({(Addr)&temp_var_for_ext_8}, (Addr)&temp_var_for_tac_38,
             "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:344:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_8;
  }

  ix = (ix << 16) | (i0 >> 16);

  /* purge off +-inf, NaN, +-0, and negative arguments */
  if (ix >= IC(0x7fff0000)) {
    long double temp_var_for_ext_9;
    long double temp_var_for_tac_39;
    temp_var_for_tac_39 = x * x;

    temp_var_for_ext_9 = temp_var_for_tac_39;
    computeLdMul((Addr)&temp_var_for_tac_39, {(Addr)&x, (Addr)&x},
                 "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:355:28");
    AssignLd({(Addr)&temp_var_for_ext_9}, (Addr)&temp_var_for_tac_39,
             "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:355:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_9;
  }

  if (ix < IC(0x3fc08000)) /* 2^-63 */
  {                        /* |x|<2**-63, return -log(|x|) */
    if (se & 0x8000) {
      *signgamp = -1;
      long double temp_var_for_ext_10;
      long double temp_var_for_const_71;
      temp_var_for_callexp_9 = __ieee754_logl((-(x)));
      temp_var_for_ext_10 = (-(temp_var_for_callexp_9));
      AssignLd({(Addr)&temp_var_for_ext_10},
               (Addr) &(temp_var_for_const_71 = (-(temp_var_for_callexp_9))),
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:366:27");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_10", (Addr)&temp_var_for_ext_10));
      callExp++; /*identify the function is  add move tmpShadow*/
      return (double temp_var_for_tac_40, temp_var_for_tac_41;
              double temp_var_for_const_72, temp_var_for_const_73,
              temp_var_for_const_74, temp_var_for_const_75;
              temp_var_for_tac_40 = 0.0 - 0;

              temp_var_for_tac_41 = 0.0 - emp_var_for_ext_(temp_var_for_tac_40);

              );
    } else {
      long double temp_var_for_ext_11;
      long double temp_var_for_const_76;
      temp_var_for_callexp_10 = __ieee754_logl(x);
      temp_var_for_ext_11 = (-(temp_var_for_callexp_10));
      computeDSub((Addr)&temp_var_for_tac_40,
                  {(Addr) &(temp_var_for_const_73 = 0.0),
                   (Addr) &(temp_var_for_const_72 = 0)},
                  "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:370:42");
      computeDSub((Addr)&temp_var_for_tac_41,
                  {(Addr) &(temp_var_for_const_75 = 0.0),
                   (Addr) &(temp_var_for_const_74 =
                                emp_var_for_ext_(temp_var_for_tac_40))},
                  "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:370:19");
      AssignLd({(Addr)&temp_var_for_ext_11},
               (Addr) &(temp_var_for_const_76 = (-(temp_var_for_callexp_10))),
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:373:27");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_11", (Addr)&temp_var_for_ext_11));
      callExp++; /*identify the function is  add move tmpShadow*/
      return (0.0 - mp_var_for_ext_11);
    }
  }
  if (se & 0x8000) {
    long double temp_var_for_ext_12;
    long double temp_var_for_const_77;
    long double temp_var_for_callexp_11;

    temp_var_for_callexp_11 = sin_pi_l(x);
    temp_var_for_ext_12 = temp_var_for_callexp_11;
    AssignLd({(Addr)&temp_var_for_ext_12},
             (Addr) &(temp_var_for_const_77 = temp_var_for_callexp_11),
             "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:382:25");
    ; // t
    /*(temp_var_for_ext_8)(tem)(9)(t)(sin_pi_l(x))*/
    t = temp_var_for_ext_12;
    AssignLd({(Addr)&t}, (Addr)&temp_var_for_ext_12,
             "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:384:7");
    ;
    if (int temp_var_for_tac_42; int temp_var_for_const_78;
        temp_var_for_tac_42 = t == zero;

        ) {
      long double temp_var_for_ext_13;
      long double temp_var_for_tac_43;
      long double temp_var_for_const_79, temp_var_for_const_80;
      long double temp_var_for_callexp_12;

      temp_var_for_callexp_12 = fabsl(t);
      temp_var_for_tac_43 = one / temp_var_for_callexp_12;

      temp_var_for_ext_13 = temp_var_for_tac_43;
      compute((Addr)&temp_var_for_tac_42,
              {(Addr)&t, (Addr) &(temp_var_for_const_78 = zero)},
              "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:385:11");
      computeLdDiv((Addr)&temp_var_for_tac_43,
                   {(Addr) &(temp_var_for_const_80 = one),
                    (Addr) &(temp_var_for_const_79 = temp_var_for_callexp_12)},
                   "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:387:33");
      AssignLd({(Addr)&temp_var_for_ext_13}, (Addr)&temp_var_for_tac_43,
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:387:27");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_13", (Addr)&temp_var_for_ext_13));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_13;
    }
    /* -integer */
    long double temp_var_for_tac_44, temp_var_for_tac_45;
    long double temp_var_for_const_81, temp_var_for_const_82,
        temp_var_for_const_83;
    long double temp_var_for_callexp_13;

    long double temp_var_for_callexp_14;

    temp_var_for_tac_44 = t * x;

    temp_var_for_callexp_13 = fabsl(temp_var_for_tac_44);
    temp_var_for_tac_45 = pi / temp_var_for_callexp_13;

    temp_var_for_callexp_14 = __ieee754_logl(temp_var_for_tac_45);
    nadj = temp_var_for_callexp_14;
    computeLdMul((Addr)&temp_var_for_tac_44, {(Addr)&t, (Addr)&x},
                 "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:394:32 "
                 "<Spelling=/home/shijia/Public/testprogram/"
                 "e_lgammal_r.c_e.c:394:50>");
    computeLdDiv((Addr)&temp_var_for_tac_45,
                 {(Addr) &(temp_var_for_const_82 = pi),
                  (Addr) &(temp_var_for_const_81 = temp_var_for_callexp_13)},
                 "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:394:30");
    AssignLd({(Addr)&nadj},
             (Addr) &(temp_var_for_const_83 = temp_var_for_callexp_14),
             "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:394:10");
    ;
    if (int temp_var_for_tac_46; int temp_var_for_const_84;
        temp_var_for_tac_46 = t < zero;

        ) {
      *signgamp = -1;
    }

    long double temp_var_for_ext_14;
    long double temp_var_for_tac_47;
    long double temp_var_for_const_85;
    temp_var_for_tac_47 = 0.0 - x;

    temp_var_for_ext_14 = temp_var_for_tac_47;
    compute((Addr)&temp_var_for_tac_46,
            {(Addr)&t, (Addr) &(temp_var_for_const_84 = zero)},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:395:11");
    computeLdSub((Addr)&temp_var_for_tac_47,
                 {(Addr) &(temp_var_for_const_85 = 0.0), (Addr)&x},
                 "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:400:32");
    AssignLd({(Addr)&temp_var_for_ext_14}, (Addr)&temp_var_for_tac_47,
             "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:400:25");
    ; // x
    /*(__ieee754_fabsl(t * x))(pi)()()(x)(x)*/
    x = temp_var_for_ext_14;
    AssignLd({(Addr)&x}, (Addr)&temp_var_for_ext_14,
             "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:402:7");
    ;
  }

  /* purge off 1 and 2 */
  if ((((ix - IC(0x3fff8000)) | i0 | i1) == 0) ||
      (((ix - IC(0x40008000)) | i0 | i1) == 0)) {
    long double temp_var_for_const_86;
    r = 0;
    AssignLd({(Addr)&r}, (Addr) &(temp_var_for_const_86 = 0),
             "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:408:7");
    ;
  }

  else {
    if (ix < IC(0x40008000)) /* 2.0 */
    {
      /* x < 2.0 */
      if (ix <= IC(0x3ffee666)) /* 8.99993896484375e-1 */
      {
        /* lgamma(x) = lgamma(x+1) - log(x) */
        long double temp_var_for_tac_48;
        long double temp_var_for_const_87, temp_var_for_const_88;
        long double temp_var_for_callexp_15;

        temp_var_for_callexp_15 = __ieee754_logl(x);
        temp_var_for_tac_48 = 0.0 - temp_var_for_callexp_15;

        r = temp_var_for_tac_48;
        computeLdSub(
            (Addr)&temp_var_for_tac_48,
            {(Addr) &(temp_var_for_const_88 = 0.0),
             (Addr) &(temp_var_for_const_87 = temp_var_for_callexp_15)},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:418:18");
        AssignLd({(Addr)&r}, (Addr)&temp_var_for_tac_48,
                 "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:418:11");
        ;
        if (ix >= IC(0x3ffebb4a)) /* 7.31597900390625e-1 */
        {
          long double temp_var_for_tac_49;
          long double temp_var_for_const_89;
          temp_var_for_tac_49 = x - one;

          y = temp_var_for_tac_49;
          computeLdSub(
              (Addr)&temp_var_for_tac_49,
              {(Addr)&x, (Addr) &(temp_var_for_const_89 = one)},
              "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:421:17");
          AssignLd({(Addr)&y}, (Addr)&temp_var_for_tac_49,
                   "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:421:13");
          ;
          i = 0;
        } else {
          if (ix >= IC(0x3ffced33)) /* 2.31639862060546875e-1 */
          {
            long double temp_var_for_tac_50, temp_var_for_tac_51;
            long double temp_var_for_const_90, temp_var_for_const_91;
            temp_var_for_tac_50 = tc - one;

            temp_var_for_tac_51 = x - temp_var_for_tac_50;

            y = temp_var_for_tac_51;
            computeLdSub(
                (Addr)&temp_var_for_tac_50,
                {(Addr) &(temp_var_for_const_91 = tc),
                 (Addr) &(temp_var_for_const_90 = one)},
                "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:426:25");
            computeLdSub(
                (Addr)&temp_var_for_tac_51,
                {(Addr)&x, (Addr)&temp_var_for_tac_50},
                "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:426:19");
            AssignLd(
                {(Addr)&y}, (Addr)&temp_var_for_tac_51,
                "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:426:15");
            ;
            i = 1;
          } else {
            /* x < 0.23 */
            y = x;
            AssignLd(
                {(Addr)&y}, (Addr)&x,
                "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:430:15");
            ;
            i = 2;
          }
        }

      } else {
        long double temp_var_for_const_92;
        r = zero;
        AssignLd({(Addr)&r}, (Addr) &(temp_var_for_const_92 = zero),
                 "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:436:11");
        ;
        if (ix >= IC(0x3fffdda6)) /* 1.73162841796875 */
        {
          /* [1.7316,2] */
          long double temp_var_for_tac_52;
          long double temp_var_for_const_93;
          temp_var_for_tac_52 = x - 2.0;

          y = temp_var_for_tac_52;
          computeLdSub(
              (Addr)&temp_var_for_tac_52,
              {(Addr)&x, (Addr) &(temp_var_for_const_93 = 2.0)},
              "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:440:17");
          AssignLd({(Addr)&y}, (Addr)&temp_var_for_tac_52,
                   "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:440:13");
          ;
          i = 0;
        } else {
          if (ix >= IC(0x3fff9da6)) /* 1.23162841796875 */
          {
            /* [1.23,1.73] */
            long double temp_var_for_tac_53;
            long double temp_var_for_const_94;
            temp_var_for_tac_53 = x - tc;

            y = temp_var_for_tac_53;
            computeLdSub(
                (Addr)&temp_var_for_tac_53,
                {(Addr)&x, (Addr) &(temp_var_for_const_94 = tc)},
                "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:446:19");
            AssignLd(
                {(Addr)&y}, (Addr)&temp_var_for_tac_53,
                "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:446:15");
            ;
            i = 1;
          } else {
            /* [0.9, 1.23] */
            long double temp_var_for_tac_54;
            long double temp_var_for_const_95;
            temp_var_for_tac_54 = x - one;

            y = temp_var_for_tac_54;
            computeLdSub(
                (Addr)&temp_var_for_tac_54,
                {(Addr)&x, (Addr) &(temp_var_for_const_95 = one)},
                "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:450:19");
            AssignLd(
                {(Addr)&y}, (Addr)&temp_var_for_tac_54,
                "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:450:15");
            ;
            i = 2;
          }
        }
      }
      int temp_var_for_ext_15;
      temp_var_for_ext_15 = (int)i;
      switch (temp_var_for_ext_15) {
      case 0: {
        long double temp_var_for_tac_55, temp_var_for_tac_56,
            temp_var_for_tac_57, temp_var_for_tac_58, temp_var_for_tac_59,
            temp_var_for_tac_60, temp_var_for_tac_61, temp_var_for_tac_62,
            temp_var_for_tac_63, temp_var_for_tac_64;
        long double temp_var_for_const_96, temp_var_for_const_97,
            temp_var_for_const_98, temp_var_for_const_99,
            temp_var_for_const_100, temp_var_for_const_101;
        temp_var_for_tac_55 = y * a5;

        temp_var_for_tac_56 = a4 + temp_var_for_tac_55;

        temp_var_for_tac_57 = y * temp_var_for_tac_56;

        temp_var_for_tac_58 = a3 + temp_var_for_tac_57;

        temp_var_for_tac_59 = y * temp_var_for_tac_58;

        temp_var_for_tac_60 = a2 + temp_var_for_tac_59;

        temp_var_for_tac_61 = y * temp_var_for_tac_60;

        temp_var_for_tac_62 = a1 + temp_var_for_tac_61;

        temp_var_for_tac_63 = y * temp_var_for_tac_62;

        temp_var_for_tac_64 = a0 + temp_var_for_tac_63;

        p1 = temp_var_for_tac_64;
        computeLdMul(
            (Addr)&temp_var_for_tac_55,
            {(Addr)&y, (Addr) &(temp_var_for_const_96 = a5)},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:459:61");
        computeLdAdd(
            (Addr)&temp_var_for_tac_56,
            {(Addr) &(temp_var_for_const_97 = a4), (Addr)&temp_var_for_tac_55},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:459:57");
        computeLdMul(
            (Addr)&temp_var_for_tac_57, {(Addr)&y, (Addr)&temp_var_for_tac_56},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:459:51");
        computeLdAdd(
            (Addr)&temp_var_for_tac_58,
            {(Addr) &(temp_var_for_const_98 = a3), (Addr)&temp_var_for_tac_57},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:459:47");
        computeLdMul(
            (Addr)&temp_var_for_tac_59, {(Addr)&y, (Addr)&temp_var_for_tac_58},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:459:41");
        computeLdAdd(
            (Addr)&temp_var_for_tac_60,
            {(Addr) &(temp_var_for_const_99 = a2), (Addr)&temp_var_for_tac_59},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:459:37");
        computeLdMul(
            (Addr)&temp_var_for_tac_61, {(Addr)&y, (Addr)&temp_var_for_tac_60},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:459:31");
        computeLdAdd(
            (Addr)&temp_var_for_tac_62,
            {(Addr) &(temp_var_for_const_100 = a1), (Addr)&temp_var_for_tac_61},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:459:27");
        computeLdMul(
            (Addr)&temp_var_for_tac_63, {(Addr)&y, (Addr)&temp_var_for_tac_62},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:459:21");
        computeLdAdd(
            (Addr)&temp_var_for_tac_64,
            {(Addr) &(temp_var_for_const_101 = a0), (Addr)&temp_var_for_tac_63},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:459:17");
        AssignLd({(Addr)&p1}, (Addr)&temp_var_for_tac_64,
                 "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:459:12");
        ;
      }

        long double temp_var_for_tac_65, temp_var_for_tac_66,
            temp_var_for_tac_67, temp_var_for_tac_68, temp_var_for_tac_69,
            temp_var_for_tac_70, temp_var_for_tac_71, temp_var_for_tac_72,
            temp_var_for_tac_73;
        long double temp_var_for_const_102, temp_var_for_const_103,
            temp_var_for_const_104, temp_var_for_const_105,
            temp_var_for_const_106;
        temp_var_for_tac_65 = b4 + y;

        temp_var_for_tac_66 = y * temp_var_for_tac_65;

        temp_var_for_tac_67 = b3 + temp_var_for_tac_66;

        temp_var_for_tac_68 = y * temp_var_for_tac_67;

        temp_var_for_tac_69 = b2 + temp_var_for_tac_68;

        temp_var_for_tac_70 = y * temp_var_for_tac_69;

        temp_var_for_tac_71 = b1 + temp_var_for_tac_70;

        temp_var_for_tac_72 = y * temp_var_for_tac_71;

        temp_var_for_tac_73 = b0 + temp_var_for_tac_72;

        p2 = temp_var_for_tac_73;
        computeLdAdd(
            (Addr)&temp_var_for_tac_65,
            {(Addr) &(temp_var_for_const_102 = b4), (Addr)&y},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:462:57");
        computeLdMul(
            (Addr)&temp_var_for_tac_66, {(Addr)&y, (Addr)&temp_var_for_tac_65},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:462:51");
        computeLdAdd(
            (Addr)&temp_var_for_tac_67,
            {(Addr) &(temp_var_for_const_103 = b3), (Addr)&temp_var_for_tac_66},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:462:47");
        computeLdMul(
            (Addr)&temp_var_for_tac_68, {(Addr)&y, (Addr)&temp_var_for_tac_67},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:462:41");
        computeLdAdd(
            (Addr)&temp_var_for_tac_69,
            {(Addr) &(temp_var_for_const_104 = b2), (Addr)&temp_var_for_tac_68},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:462:37");
        computeLdMul(
            (Addr)&temp_var_for_tac_70, {(Addr)&y, (Addr)&temp_var_for_tac_69},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:462:31");
        computeLdAdd(
            (Addr)&temp_var_for_tac_71,
            {(Addr) &(temp_var_for_const_105 = b1), (Addr)&temp_var_for_tac_70},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:462:27");
        computeLdMul(
            (Addr)&temp_var_for_tac_72, {(Addr)&y, (Addr)&temp_var_for_tac_71},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:462:21");
        computeLdAdd(
            (Addr)&temp_var_for_tac_73,
            {(Addr) &(temp_var_for_const_106 = b0), (Addr)&temp_var_for_tac_72},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:462:17");
        AssignLd({(Addr)&p2}, (Addr)&temp_var_for_tac_73,
                 "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:462:12");
        ;
        long double temp_var_for_tac_74, temp_var_for_tac_75,
            temp_var_for_tac_76, temp_var_for_tac_77;
        long double temp_var_for_const_107;
        temp_var_for_tac_74 = half * y;

        temp_var_for_tac_75 = y * p1;

        temp_var_for_tac_76 = temp_var_for_tac_75 / p2;

        temp_var_for_tac_77 = temp_var_for_tac_74 + temp_var_for_tac_76;

        r += temp_var_for_tac_77;
        ;
        break;
      case 1: {
        long double temp_var_for_ext_16;
        long double temp_var_for_tac_79, temp_var_for_tac_80,
            temp_var_for_tac_81, temp_var_for_tac_82, temp_var_for_tac_83,
            temp_var_for_tac_84, temp_var_for_tac_85, temp_var_for_tac_86,
            temp_var_for_tac_87, temp_var_for_tac_88, temp_var_for_tac_89,
            temp_var_for_tac_90;
        long double temp_var_for_const_108, temp_var_for_const_109,
            temp_var_for_const_110, temp_var_for_const_111,
            temp_var_for_const_112, temp_var_for_const_113,
            temp_var_for_const_114;
        temp_var_for_tac_79 = y * g6;

        temp_var_for_tac_80 = g5 + temp_var_for_tac_79;

        temp_var_for_tac_81 = y * temp_var_for_tac_80;

        temp_var_for_tac_82 = g4 + temp_var_for_tac_81;

        temp_var_for_tac_83 = y * temp_var_for_tac_82;

        temp_var_for_tac_84 = g3 + temp_var_for_tac_83;

        temp_var_for_tac_85 = y * temp_var_for_tac_84;

        temp_var_for_tac_86 = g2 + temp_var_for_tac_85;

        temp_var_for_tac_87 = y * temp_var_for_tac_86;

        temp_var_for_tac_88 = g1 + temp_var_for_tac_87;

        temp_var_for_tac_89 = y * temp_var_for_tac_88;

        temp_var_for_tac_90 = g0 + temp_var_for_tac_89;

        temp_var_for_ext_16 = temp_var_for_tac_90;
        computeLdMul(
            (Addr)&temp_var_for_tac_74,
            {(Addr) &(temp_var_for_const_107 = half), (Addr)&y},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:463:19");
        computeLdMul(
            (Addr)&temp_var_for_tac_75, {(Addr)&y, (Addr)&p1},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:463:27");
        computeLdDiv(
            (Addr)&temp_var_for_tac_76, {(Addr)&temp_var_for_tac_75, (Addr)&p2},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:463:32");
        computeLdAdd(
            (Addr)&temp_var_for_tac_77,
            {(Addr)&temp_var_for_tac_74, (Addr)&temp_var_for_tac_76},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:463:23");
        computeLdMul(
            (Addr)&temp_var_for_tac_79,
            {(Addr)&y, (Addr) &(temp_var_for_const_108 = g6)},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:469:65");
        computeLdAdd(
            (Addr)&temp_var_for_tac_80,
            {(Addr) &(temp_var_for_const_109 = g5), (Addr)&temp_var_for_tac_79},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:469:61");
        computeLdMul(
            (Addr)&temp_var_for_tac_81, {(Addr)&y, (Addr)&temp_var_for_tac_80},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:469:55");
        computeLdAdd(
            (Addr)&temp_var_for_tac_82,
            {(Addr) &(temp_var_for_const_110 = g4), (Addr)&temp_var_for_tac_81},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:469:51");
        computeLdMul(
            (Addr)&temp_var_for_tac_83, {(Addr)&y, (Addr)&temp_var_for_tac_82},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:469:45");
        computeLdAdd(
            (Addr)&temp_var_for_tac_84,
            {(Addr) &(temp_var_for_const_111 = g3), (Addr)&temp_var_for_tac_83},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:469:41");
        computeLdMul(
            (Addr)&temp_var_for_tac_85, {(Addr)&y, (Addr)&temp_var_for_tac_84},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:469:35");
        computeLdAdd(
            (Addr)&temp_var_for_tac_86,
            {(Addr) &(temp_var_for_const_112 = g2), (Addr)&temp_var_for_tac_85},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:469:31");
        computeLdMul(
            (Addr)&temp_var_for_tac_87, {(Addr)&y, (Addr)&temp_var_for_tac_86},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:469:25");
        computeLdAdd(
            (Addr)&temp_var_for_tac_88,
            {(Addr) &(temp_var_for_const_113 = g1), (Addr)&temp_var_for_tac_87},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:469:21");
        computeLdMul(
            (Addr)&temp_var_for_tac_89, {(Addr)&y, (Addr)&temp_var_for_tac_88},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:469:15");
        computeLdAdd(
            (Addr)&temp_var_for_tac_90,
            {(Addr) &(temp_var_for_const_114 = g0), (Addr)&temp_var_for_tac_89},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:468:16");
        AssignLd({(Addr)&temp_var_for_ext_16}, (Addr)&temp_var_for_tac_90,
                 "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:467:29");
        ; // p1
        /*(y)(b4)(y)(b3)(y)(b2)(y)(b1)(y)(b0)(y)(b4)(y)(b3)(y)(b2)(y)(b1)(y)(y)(b4)(y)(b3)(y)(b2)(y)(b1)(y)(b4)(y)(b3)(y)(b2)(y)(y)(b4)(y)(b3)(y)(b2)(y)(b4)(y)(b3)(y)(y)(b4)(y)(b3)(y)(b4)(y)(y)(b4)(p2)(p1)(y)(y)(half)(r)(p2)(p1)(y)(y)(half)(y)(half)(p2)(p1)(y)(p1)(y)(g6)(y)(g5)(y)(g4)(y)(g3)(y)(g2)(y)(g1)(y)(g0)*/
        p1 = temp_var_for_ext_16;
        AssignLd({(Addr)&p1}, (Addr)&temp_var_for_ext_16,
                 "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:471:12");
        ;
      }

        long double temp_var_for_tac_91, temp_var_for_tac_92,
            temp_var_for_tac_93, temp_var_for_tac_94, temp_var_for_tac_95,
            temp_var_for_tac_96, temp_var_for_tac_97, temp_var_for_tac_98,
            temp_var_for_tac_99, temp_var_for_tac_100, temp_var_for_tac_101;
        long double temp_var_for_const_115, temp_var_for_const_116,
            temp_var_for_const_117, temp_var_for_const_118,
            temp_var_for_const_119, temp_var_for_const_120;
        temp_var_for_tac_91 = h5 + y;

        temp_var_for_tac_92 = y * temp_var_for_tac_91;

        temp_var_for_tac_93 = h4 + temp_var_for_tac_92;

        temp_var_for_tac_94 = y * temp_var_for_tac_93;

        temp_var_for_tac_95 = h3 + temp_var_for_tac_94;

        temp_var_for_tac_96 = y * temp_var_for_tac_95;

        temp_var_for_tac_97 = h2 + temp_var_for_tac_96;

        temp_var_for_tac_98 = y * temp_var_for_tac_97;

        temp_var_for_tac_99 = h1 + temp_var_for_tac_98;

        temp_var_for_tac_100 = y * temp_var_for_tac_99;

        temp_var_for_tac_101 = h0 + temp_var_for_tac_100;

        p2 = temp_var_for_tac_101;
        computeLdAdd(
            (Addr)&temp_var_for_tac_91,
            {(Addr) &(temp_var_for_const_115 = h5), (Addr)&y},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:474:67");
        computeLdMul(
            (Addr)&temp_var_for_tac_92, {(Addr)&y, (Addr)&temp_var_for_tac_91},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:474:61");
        computeLdAdd(
            (Addr)&temp_var_for_tac_93,
            {(Addr) &(temp_var_for_const_116 = h4), (Addr)&temp_var_for_tac_92},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:474:57");
        computeLdMul(
            (Addr)&temp_var_for_tac_94, {(Addr)&y, (Addr)&temp_var_for_tac_93},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:474:51");
        computeLdAdd(
            (Addr)&temp_var_for_tac_95,
            {(Addr) &(temp_var_for_const_117 = h3), (Addr)&temp_var_for_tac_94},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:474:47");
        computeLdMul(
            (Addr)&temp_var_for_tac_96, {(Addr)&y, (Addr)&temp_var_for_tac_95},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:474:41");
        computeLdAdd(
            (Addr)&temp_var_for_tac_97,
            {(Addr) &(temp_var_for_const_118 = h2), (Addr)&temp_var_for_tac_96},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:474:37");
        computeLdMul(
            (Addr)&temp_var_for_tac_98, {(Addr)&y, (Addr)&temp_var_for_tac_97},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:474:31");
        computeLdAdd(
            (Addr)&temp_var_for_tac_99,
            {(Addr) &(temp_var_for_const_119 = h1), (Addr)&temp_var_for_tac_98},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:474:27");
        computeLdMul(
            (Addr)&temp_var_for_tac_100, {(Addr)&y, (Addr)&temp_var_for_tac_99},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:474:21");
        computeLdAdd(
            (Addr)&temp_var_for_tac_101, {(Addr) &(temp_var_for_const_120 = h0),
                                          (Addr)&temp_var_for_tac_100},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:474:17");
        AssignLd({(Addr)&p2}, (Addr)&temp_var_for_tac_101,
                 "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:474:12");
        ;
        long double temp_var_for_tac_102, temp_var_for_tac_103,
            temp_var_for_tac_104;
        long double temp_var_for_const_121;
        temp_var_for_tac_102 = y * p1;

        temp_var_for_tac_103 = temp_var_for_tac_102 / p2;

        temp_var_for_tac_104 = tt + temp_var_for_tac_103;

        p = temp_var_for_tac_104;
        computeLdMul(
            (Addr)&temp_var_for_tac_102, {(Addr)&y, (Addr)&p1},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:475:20");
        computeLdDiv(
            (Addr)&temp_var_for_tac_103,
            {(Addr)&temp_var_for_tac_102, (Addr)&p2},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:475:25");
        computeLdAdd(
            (Addr)&temp_var_for_tac_104, {(Addr) &(temp_var_for_const_121 = tt),
                                          (Addr)&temp_var_for_tac_103},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:475:16");
        AssignLd({(Addr)&p}, (Addr)&temp_var_for_tac_104,
                 "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:475:11");
        ;
        long double temp_var_for_tac_105;
        long double temp_var_for_const_122;
        temp_var_for_tac_105 = tf + p;

        r += temp_var_for_tac_105;
        ;
        break;
      case 2: {
        long double temp_var_for_ext_17;
        long double temp_var_for_tac_107, temp_var_for_tac_108,
            temp_var_for_tac_109, temp_var_for_tac_110, temp_var_for_tac_111,
            temp_var_for_tac_112, temp_var_for_tac_113, temp_var_for_tac_114,
            temp_var_for_tac_115, temp_var_for_tac_116, temp_var_for_tac_117,
            temp_var_for_tac_118, temp_var_for_tac_119;
        long double temp_var_for_const_123, temp_var_for_const_124,
            temp_var_for_const_125, temp_var_for_const_126,
            temp_var_for_const_127, temp_var_for_const_128,
            temp_var_for_const_129;
        temp_var_for_tac_107 = y * u6;

        temp_var_for_tac_108 = u5 + temp_var_for_tac_107;

        temp_var_for_tac_109 = y * temp_var_for_tac_108;

        temp_var_for_tac_110 = u4 + temp_var_for_tac_109;

        temp_var_for_tac_111 = y * temp_var_for_tac_110;

        temp_var_for_tac_112 = u3 + temp_var_for_tac_111;

        temp_var_for_tac_113 = y * temp_var_for_tac_112;

        temp_var_for_tac_114 = u2 + temp_var_for_tac_113;

        temp_var_for_tac_115 = y * temp_var_for_tac_114;

        temp_var_for_tac_116 = u1 + temp_var_for_tac_115;

        temp_var_for_tac_117 = y * temp_var_for_tac_116;

        temp_var_for_tac_118 = u0 + temp_var_for_tac_117;

        temp_var_for_tac_119 = y * temp_var_for_tac_118;

        temp_var_for_ext_17 = temp_var_for_tac_119;
        computeLdAdd(
            (Addr)&temp_var_for_tac_105,
            {(Addr) &(temp_var_for_const_122 = tf), (Addr)&p},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:476:18");
        computeLdMul(
            (Addr)&temp_var_for_tac_107,
            {(Addr)&y, (Addr) &(temp_var_for_const_123 = u6)},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:484:61");
        computeLdAdd(
            (Addr)&temp_var_for_tac_108, {(Addr) &(temp_var_for_const_124 = u5),
                                          (Addr)&temp_var_for_tac_107},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:484:57");
        computeLdMul(
            (Addr)&temp_var_for_tac_109,
            {(Addr)&y, (Addr)&temp_var_for_tac_108},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:484:51");
        computeLdAdd(
            (Addr)&temp_var_for_tac_110, {(Addr) &(temp_var_for_const_125 = u4),
                                          (Addr)&temp_var_for_tac_109},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:484:47");
        computeLdMul(
            (Addr)&temp_var_for_tac_111,
            {(Addr)&y, (Addr)&temp_var_for_tac_110},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:484:41");
        computeLdAdd(
            (Addr)&temp_var_for_tac_112, {(Addr) &(temp_var_for_const_126 = u3),
                                          (Addr)&temp_var_for_tac_111},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:484:37");
        computeLdMul(
            (Addr)&temp_var_for_tac_113,
            {(Addr)&y, (Addr)&temp_var_for_tac_112},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:484:31");
        computeLdAdd(
            (Addr)&temp_var_for_tac_114, {(Addr) &(temp_var_for_const_127 = u2),
                                          (Addr)&temp_var_for_tac_113},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:484:27");
        computeLdMul(
            (Addr)&temp_var_for_tac_115,
            {(Addr)&y, (Addr)&temp_var_for_tac_114},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:484:21");
        computeLdAdd(
            (Addr)&temp_var_for_tac_116, {(Addr) &(temp_var_for_const_128 = u1),
                                          (Addr)&temp_var_for_tac_115},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:483:22");
        computeLdMul(
            (Addr)&temp_var_for_tac_117,
            {(Addr)&y, (Addr)&temp_var_for_tac_116},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:483:16");
        computeLdAdd(
            (Addr)&temp_var_for_tac_118, {(Addr) &(temp_var_for_const_129 = u0),
                                          (Addr)&temp_var_for_tac_117},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:482:17");
        computeLdMul(
            (Addr)&temp_var_for_tac_119,
            {(Addr)&y, (Addr)&temp_var_for_tac_118},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:481:15");
        AssignLd({(Addr)&temp_var_for_ext_17}, (Addr)&temp_var_for_tac_119,
                 "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:480:29");
        ; // p1
        /*(p2)(p1)(y)(tt)(p2)(p1)(y)(p1)(y)(p)(tf)(r)(p)(tf)(u6)(y)(u5)(y)(u4)(y)(u3)(y)(u2)(y)(u1)(y)(u0)(y)*/
        p1 = temp_var_for_ext_17;
        AssignLd({(Addr)&p1}, (Addr)&temp_var_for_ext_17,
                 "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:486:12");
        ;
      }

        long double temp_var_for_tac_120, temp_var_for_tac_121,
            temp_var_for_tac_122, temp_var_for_tac_123, temp_var_for_tac_124,
            temp_var_for_tac_125, temp_var_for_tac_126, temp_var_for_tac_127,
            temp_var_for_tac_128, temp_var_for_tac_129, temp_var_for_tac_130;
        long double temp_var_for_const_130, temp_var_for_const_131,
            temp_var_for_const_132, temp_var_for_const_133,
            temp_var_for_const_134, temp_var_for_const_135;
        temp_var_for_tac_120 = v5 + y;

        temp_var_for_tac_121 = y * temp_var_for_tac_120;

        temp_var_for_tac_122 = v4 + temp_var_for_tac_121;

        temp_var_for_tac_123 = y * temp_var_for_tac_122;

        temp_var_for_tac_124 = v3 + temp_var_for_tac_123;

        temp_var_for_tac_125 = y * temp_var_for_tac_124;

        temp_var_for_tac_126 = v2 + temp_var_for_tac_125;

        temp_var_for_tac_127 = y * temp_var_for_tac_126;

        temp_var_for_tac_128 = v1 + temp_var_for_tac_127;

        temp_var_for_tac_129 = y * temp_var_for_tac_128;

        temp_var_for_tac_130 = v0 + temp_var_for_tac_129;

        p2 = temp_var_for_tac_130;
        computeLdAdd(
            (Addr)&temp_var_for_tac_120,
            {(Addr) &(temp_var_for_const_130 = v5), (Addr)&y},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:489:67");
        computeLdMul(
            (Addr)&temp_var_for_tac_121,
            {(Addr)&y, (Addr)&temp_var_for_tac_120},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:489:61");
        computeLdAdd(
            (Addr)&temp_var_for_tac_122, {(Addr) &(temp_var_for_const_131 = v4),
                                          (Addr)&temp_var_for_tac_121},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:489:57");
        computeLdMul(
            (Addr)&temp_var_for_tac_123,
            {(Addr)&y, (Addr)&temp_var_for_tac_122},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:489:51");
        computeLdAdd(
            (Addr)&temp_var_for_tac_124, {(Addr) &(temp_var_for_const_132 = v3),
                                          (Addr)&temp_var_for_tac_123},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:489:47");
        computeLdMul(
            (Addr)&temp_var_for_tac_125,
            {(Addr)&y, (Addr)&temp_var_for_tac_124},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:489:41");
        computeLdAdd(
            (Addr)&temp_var_for_tac_126, {(Addr) &(temp_var_for_const_133 = v2),
                                          (Addr)&temp_var_for_tac_125},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:489:37");
        computeLdMul(
            (Addr)&temp_var_for_tac_127,
            {(Addr)&y, (Addr)&temp_var_for_tac_126},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:489:31");
        computeLdAdd(
            (Addr)&temp_var_for_tac_128, {(Addr) &(temp_var_for_const_134 = v1),
                                          (Addr)&temp_var_for_tac_127},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:489:27");
        computeLdMul(
            (Addr)&temp_var_for_tac_129,
            {(Addr)&y, (Addr)&temp_var_for_tac_128},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:489:21");
        computeLdAdd(
            (Addr)&temp_var_for_tac_130, {(Addr) &(temp_var_for_const_135 = v0),
                                          (Addr)&temp_var_for_tac_129},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:489:17");
        AssignLd({(Addr)&p2}, (Addr)&temp_var_for_tac_130,
                 "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:489:12");
        ;
        long double temp_var_for_tac_131, temp_var_for_tac_132,
            temp_var_for_tac_133, temp_var_for_tac_134;
        long double temp_var_for_const_136, temp_var_for_const_137;
        temp_var_for_tac_131 = 0.0 - half;

        temp_var_for_tac_132 = temp_var_for_tac_131 * y;

        temp_var_for_tac_133 = p1 / p2;

        temp_var_for_tac_134 = temp_var_for_tac_132 + temp_var_for_tac_133;

        r += temp_var_for_tac_134;
        ;
        break;
      }
    } else {
      if (ix < IC(0x40028000)) /* 8.0 */
      {
        /* x < 8.0 */
        i = (int32_t)x;
        long double temp_var_for_const_138;
        t = zero;
        computeLdSub(
            (Addr)&temp_var_for_tac_131,
            {(Addr) &(temp_var_for_const_137 = 0.0),
             (Addr) &(temp_var_for_const_136 = half)},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:490:20");
        computeLdMul(
            (Addr)&temp_var_for_tac_132,
            {(Addr)&temp_var_for_tac_131, (Addr)&y},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:490:28");
        computeLdDiv(
            (Addr)&temp_var_for_tac_133, {(Addr)&p1, (Addr)&p2},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:490:37");
        computeLdAdd(
            (Addr)&temp_var_for_tac_134,
            {(Addr)&temp_var_for_tac_132, (Addr)&temp_var_for_tac_133},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:490:32");
        AssignLd({(Addr)&t}, (Addr) &(temp_var_for_const_138 = zero),
                 "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:498:11");
        ;
        long double temp_var_for_tac_136;
        long double temp_var_for_const_139;
        temp_var_for_tac_136 = x - ((double)i);

        y = temp_var_for_tac_136;
        computeLdSub(
            (Addr)&temp_var_for_tac_136,
            {(Addr)&x, (Addr) &(temp_var_for_const_139 = ((double)i))},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:499:15");
        AssignLd({(Addr)&y}, (Addr)&temp_var_for_tac_136,
                 "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:499:11");
        ;
        long double temp_var_for_tac_137, temp_var_for_tac_138,
            temp_var_for_tac_139, temp_var_for_tac_140, temp_var_for_tac_141,
            temp_var_for_tac_142, temp_var_for_tac_143, temp_var_for_tac_144,
            temp_var_for_tac_145, temp_var_for_tac_146, temp_var_for_tac_147,
            temp_var_for_tac_148, temp_var_for_tac_149;
        long double temp_var_for_const_140, temp_var_for_const_141,
            temp_var_for_const_142, temp_var_for_const_143,
            temp_var_for_const_144, temp_var_for_const_145,
            temp_var_for_const_146;
        temp_var_for_tac_137 = y * s6;

        temp_var_for_tac_138 = s5 + temp_var_for_tac_137;

        temp_var_for_tac_139 = y * temp_var_for_tac_138;

        temp_var_for_tac_140 = s4 + temp_var_for_tac_139;

        temp_var_for_tac_141 = y * temp_var_for_tac_140;

        temp_var_for_tac_142 = s3 + temp_var_for_tac_141;

        temp_var_for_tac_143 = y * temp_var_for_tac_142;

        temp_var_for_tac_144 = s2 + temp_var_for_tac_143;

        temp_var_for_tac_145 = y * temp_var_for_tac_144;

        temp_var_for_tac_146 = s1 + temp_var_for_tac_145;

        temp_var_for_tac_147 = y * temp_var_for_tac_146;

        temp_var_for_tac_148 = s0 + temp_var_for_tac_147;

        temp_var_for_tac_149 = y * temp_var_for_tac_148;

        p = temp_var_for_tac_149;
        computeLdMul(
            (Addr)&temp_var_for_tac_137,
            {(Addr)&y, (Addr) &(temp_var_for_const_140 = s6)},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:501:70");
        computeLdAdd(
            (Addr)&temp_var_for_tac_138, {(Addr) &(temp_var_for_const_141 = s5),
                                          (Addr)&temp_var_for_tac_137},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:501:66");
        computeLdMul(
            (Addr)&temp_var_for_tac_139,
            {(Addr)&y, (Addr)&temp_var_for_tac_138},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:501:60");
        computeLdAdd(
            (Addr)&temp_var_for_tac_140, {(Addr) &(temp_var_for_const_142 = s4),
                                          (Addr)&temp_var_for_tac_139},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:501:56");
        computeLdMul(
            (Addr)&temp_var_for_tac_141,
            {(Addr)&y, (Addr)&temp_var_for_tac_140},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:501:50");
        computeLdAdd(
            (Addr)&temp_var_for_tac_142, {(Addr) &(temp_var_for_const_143 = s3),
                                          (Addr)&temp_var_for_tac_141},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:501:46");
        computeLdMul(
            (Addr)&temp_var_for_tac_143,
            {(Addr)&y, (Addr)&temp_var_for_tac_142},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:501:40");
        computeLdAdd(
            (Addr)&temp_var_for_tac_144, {(Addr) &(temp_var_for_const_144 = s2),
                                          (Addr)&temp_var_for_tac_143},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:501:36");
        computeLdMul(
            (Addr)&temp_var_for_tac_145,
            {(Addr)&y, (Addr)&temp_var_for_tac_144},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:501:30");
        computeLdAdd(
            (Addr)&temp_var_for_tac_146, {(Addr) &(temp_var_for_const_145 = s1),
                                          (Addr)&temp_var_for_tac_145},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:501:26");
        computeLdMul(
            (Addr)&temp_var_for_tac_147,
            {(Addr)&y, (Addr)&temp_var_for_tac_146},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:501:20");
        computeLdAdd(
            (Addr)&temp_var_for_tac_148, {(Addr) &(temp_var_for_const_146 = s0),
                                          (Addr)&temp_var_for_tac_147},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:500:21");
        computeLdMul(
            (Addr)&temp_var_for_tac_149,
            {(Addr)&y, (Addr)&temp_var_for_tac_148},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:500:15");
        AssignLd({(Addr)&p}, (Addr)&temp_var_for_tac_149,
                 "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:500:11");
        ;
        long double temp_var_for_tac_150, temp_var_for_tac_151,
            temp_var_for_tac_152, temp_var_for_tac_153, temp_var_for_tac_154,
            temp_var_for_tac_155, temp_var_for_tac_156, temp_var_for_tac_157,
            temp_var_for_tac_158, temp_var_for_tac_159, temp_var_for_tac_160,
            temp_var_for_tac_161, temp_var_for_tac_162;
        long double temp_var_for_const_147, temp_var_for_const_148,
            temp_var_for_const_149, temp_var_for_const_150,
            temp_var_for_const_151, temp_var_for_const_152,
            temp_var_for_const_153;
        temp_var_for_tac_150 = r6 + y;

        temp_var_for_tac_151 = y * temp_var_for_tac_150;

        temp_var_for_tac_152 = r5 + temp_var_for_tac_151;

        temp_var_for_tac_153 = y * temp_var_for_tac_152;

        temp_var_for_tac_154 = r4 + temp_var_for_tac_153;

        temp_var_for_tac_155 = y * temp_var_for_tac_154;

        temp_var_for_tac_156 = r3 + temp_var_for_tac_155;

        temp_var_for_tac_157 = y * temp_var_for_tac_156;

        temp_var_for_tac_158 = r2 + temp_var_for_tac_157;

        temp_var_for_tac_159 = y * temp_var_for_tac_158;

        temp_var_for_tac_160 = r1 + temp_var_for_tac_159;

        temp_var_for_tac_161 = y * temp_var_for_tac_160;

        temp_var_for_tac_162 = r0 + temp_var_for_tac_161;

        q = temp_var_for_tac_162;
        computeLdAdd(
            (Addr)&temp_var_for_tac_150,
            {(Addr) &(temp_var_for_const_147 = r6), (Addr)&y},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:503:71");
        computeLdMul(
            (Addr)&temp_var_for_tac_151,
            {(Addr)&y, (Addr)&temp_var_for_tac_150},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:503:65");
        computeLdAdd(
            (Addr)&temp_var_for_tac_152, {(Addr) &(temp_var_for_const_148 = r5),
                                          (Addr)&temp_var_for_tac_151},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:503:61");
        computeLdMul(
            (Addr)&temp_var_for_tac_153,
            {(Addr)&y, (Addr)&temp_var_for_tac_152},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:503:55");
        computeLdAdd(
            (Addr)&temp_var_for_tac_154, {(Addr) &(temp_var_for_const_149 = r4),
                                          (Addr)&temp_var_for_tac_153},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:503:51");
        computeLdMul(
            (Addr)&temp_var_for_tac_155,
            {(Addr)&y, (Addr)&temp_var_for_tac_154},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:503:45");
        computeLdAdd(
            (Addr)&temp_var_for_tac_156, {(Addr) &(temp_var_for_const_150 = r3),
                                          (Addr)&temp_var_for_tac_155},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:503:41");
        computeLdMul(
            (Addr)&temp_var_for_tac_157,
            {(Addr)&y, (Addr)&temp_var_for_tac_156},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:503:35");
        computeLdAdd(
            (Addr)&temp_var_for_tac_158, {(Addr) &(temp_var_for_const_151 = r2),
                                          (Addr)&temp_var_for_tac_157},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:503:31");
        computeLdMul(
            (Addr)&temp_var_for_tac_159,
            {(Addr)&y, (Addr)&temp_var_for_tac_158},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:503:25");
        computeLdAdd(
            (Addr)&temp_var_for_tac_160, {(Addr) &(temp_var_for_const_152 = r1),
                                          (Addr)&temp_var_for_tac_159},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:503:21");
        computeLdMul(
            (Addr)&temp_var_for_tac_161,
            {(Addr)&y, (Addr)&temp_var_for_tac_160},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:503:15");
        computeLdAdd(
            (Addr)&temp_var_for_tac_162, {(Addr) &(temp_var_for_const_153 = r0),
                                          (Addr)&temp_var_for_tac_161},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:502:16");
        AssignLd({(Addr)&q}, (Addr)&temp_var_for_tac_162,
                 "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:502:11");
        ;
        long double temp_var_for_tac_163, temp_var_for_tac_164,
            temp_var_for_tac_165;
        long double temp_var_for_const_154;
        temp_var_for_tac_163 = half * y;

        temp_var_for_tac_164 = p / q;

        temp_var_for_tac_165 = temp_var_for_tac_163 + temp_var_for_tac_164;

        r = temp_var_for_tac_165;
        computeLdMul(
            (Addr)&temp_var_for_tac_163,
            {(Addr) &(temp_var_for_const_154 = half), (Addr)&y},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:504:18");
        computeLdDiv(
            (Addr)&temp_var_for_tac_164, {(Addr)&p, (Addr)&q},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:504:26");
        computeLdAdd(
            (Addr)&temp_var_for_tac_165,
            {(Addr)&temp_var_for_tac_163, (Addr)&temp_var_for_tac_164},
            "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:504:22");
        AssignLd({(Addr)&r}, (Addr)&temp_var_for_tac_165,
                 "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:504:11");
        ;
        long double temp_var_for_const_155;
        z = one;
        AssignLd({(Addr)&z}, (Addr) &(temp_var_for_const_155 = one),
                 "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:505:11");
        ; /* lgamma(1+s) = log(s) + lgamma(s) */
        int temp_var_for_ext_18;
        temp_var_for_ext_18 = (int)i;
        switch (temp_var_for_ext_18) {
        case 7: {
          long double temp_var_for_tac_166;
          long double temp_var_for_const_156;
          temp_var_for_tac_166 = y + 6.0;

          z *= temp_var_for_tac_166;
          ;
        }
        /* FALLTHRU */
        case 6: {
          long double temp_var_for_tac_168;
          long double temp_var_for_const_157;
          temp_var_for_tac_168 = y + 5.0;

          z *= temp_var_for_tac_168;
          ;
        }
        /* FALLTHRU */
        case 5: {
          long double temp_var_for_tac_170;
          long double temp_var_for_const_158;
          temp_var_for_tac_170 = y + 4.0;

          z *= temp_var_for_tac_170;
          ;
        }
        /* FALLTHRU */
        case 4: {
          long double temp_var_for_tac_172;
          long double temp_var_for_const_159;
          temp_var_for_tac_172 = y + 3.0;

          z *= temp_var_for_tac_172;
          ;
        }
        /* FALLTHRU */
        case 3: {
          long double temp_var_for_tac_174;
          long double temp_var_for_const_160;
          temp_var_for_tac_174 = y + 2.0;

          z *= temp_var_for_tac_174;
          ;
        }
          /* FALLTHRU */
          long double temp_var_for_callexp_16;

          temp_var_for_callexp_16 = __ieee754_logl(z);
          r += temp_var_for_callexp_16;
          ;
          break;
        }
      } else {
        if (ix < IC(0x40418000)) /* 2^66 */
        {
          /* 8.0 <= x < 2**66 */
          long double temp_var_for_const_161;
          long double temp_var_for_callexp_17;

          temp_var_for_callexp_17 = __ieee754_logl(x);
          t = temp_var_for_callexp_17;
          computeLdAdd(
              (Addr)&temp_var_for_tac_166,
              {(Addr)&y, (Addr) &(temp_var_for_const_156 = 6.0)},
              "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:510:19");
          computeLdAdd(
              (Addr)&temp_var_for_tac_168,
              {(Addr)&y, (Addr) &(temp_var_for_const_157 = 5.0)},
              "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:514:19");
          computeLdAdd(
              (Addr)&temp_var_for_tac_170,
              {(Addr)&y, (Addr) &(temp_var_for_const_158 = 4.0)},
              "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:518:19");
          computeLdAdd(
              (Addr)&temp_var_for_tac_172,
              {(Addr)&y, (Addr) &(temp_var_for_const_159 = 3.0)},
              "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:522:19");
          computeLdAdd(
              (Addr)&temp_var_for_tac_174,
              {(Addr)&y, (Addr) &(temp_var_for_const_160 = 2.0)},
              "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:526:19");
          AssignLd({(Addr)&t},
                   (Addr) &(temp_var_for_const_161 = temp_var_for_callexp_17),
                   "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:536:13");
          ;
          long double temp_var_for_tac_177;
          long double temp_var_for_const_162;
          temp_var_for_tac_177 = one / x;

          z = temp_var_for_tac_177;
          computeLdDiv(
              (Addr)&temp_var_for_tac_177,
              {(Addr) &(temp_var_for_const_162 = one), (Addr)&x},
              "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:537:19");
          AssignLd({(Addr)&z}, (Addr)&temp_var_for_tac_177,
                   "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:537:13");
          ;
          long double temp_var_for_tac_178;
          temp_var_for_tac_178 = z * z;

          y = temp_var_for_tac_178;
          computeLdMul(
              (Addr)&temp_var_for_tac_178, {(Addr)&z, (Addr)&z},
              "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:538:17");
          AssignLd({(Addr)&y}, (Addr)&temp_var_for_tac_178,
                   "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:538:13");
          ;
          long double temp_var_for_tac_179, temp_var_for_tac_180,
              temp_var_for_tac_181, temp_var_for_tac_182, temp_var_for_tac_183,
              temp_var_for_tac_184, temp_var_for_tac_185, temp_var_for_tac_186,
              temp_var_for_tac_187, temp_var_for_tac_188, temp_var_for_tac_189,
              temp_var_for_tac_190, temp_var_for_tac_191, temp_var_for_tac_192;
          long double temp_var_for_const_163, temp_var_for_const_164,
              temp_var_for_const_165, temp_var_for_const_166,
              temp_var_for_const_167, temp_var_for_const_168,
              temp_var_for_const_169, temp_var_for_const_170;
          temp_var_for_tac_179 = y * w7;

          temp_var_for_tac_180 = w6 + temp_var_for_tac_179;

          temp_var_for_tac_181 = y * temp_var_for_tac_180;

          temp_var_for_tac_182 = w5 + temp_var_for_tac_181;

          temp_var_for_tac_183 = y * temp_var_for_tac_182;

          temp_var_for_tac_184 = w4 + temp_var_for_tac_183;

          temp_var_for_tac_185 = y * temp_var_for_tac_184;

          temp_var_for_tac_186 = w3 + temp_var_for_tac_185;

          temp_var_for_tac_187 = y * temp_var_for_tac_186;

          temp_var_for_tac_188 = w2 + temp_var_for_tac_187;

          temp_var_for_tac_189 = y * temp_var_for_tac_188;

          temp_var_for_tac_190 = w1 + temp_var_for_tac_189;

          temp_var_for_tac_191 = z * temp_var_for_tac_190;

          temp_var_for_tac_192 = w0 + temp_var_for_tac_191;

          w = temp_var_for_tac_192;
          computeLdMul(
              (Addr)&temp_var_for_tac_179,
              {(Addr)&y, (Addr) &(temp_var_for_const_163 = w7)},
              "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:542:67");
          computeLdAdd(
              (Addr)&temp_var_for_tac_180,
              {(Addr) &(temp_var_for_const_164 = w6),
               (Addr)&temp_var_for_tac_179},
              "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:542:63");
          computeLdMul(
              (Addr)&temp_var_for_tac_181,
              {(Addr)&y, (Addr)&temp_var_for_tac_180},
              "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:542:57");
          computeLdAdd(
              (Addr)&temp_var_for_tac_182,
              {(Addr) &(temp_var_for_const_165 = w5),
               (Addr)&temp_var_for_tac_181},
              "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:542:53");
          computeLdMul(
              (Addr)&temp_var_for_tac_183,
              {(Addr)&y, (Addr)&temp_var_for_tac_182},
              "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:542:47");
          computeLdAdd(
              (Addr)&temp_var_for_tac_184,
              {(Addr) &(temp_var_for_const_166 = w4),
               (Addr)&temp_var_for_tac_183},
              "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:542:43");
          computeLdMul(
              (Addr)&temp_var_for_tac_185,
              {(Addr)&y, (Addr)&temp_var_for_tac_184},
              "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:542:37");
          computeLdAdd(
              (Addr)&temp_var_for_tac_186,
              {(Addr) &(temp_var_for_const_167 = w3),
               (Addr)&temp_var_for_tac_185},
              "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:542:33");
          computeLdMul(
              (Addr)&temp_var_for_tac_187,
              {(Addr)&y, (Addr)&temp_var_for_tac_186},
              "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:542:27");
          computeLdAdd(
              (Addr)&temp_var_for_tac_188,
              {(Addr) &(temp_var_for_const_168 = w2),
               (Addr)&temp_var_for_tac_187},
              "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:541:28");
          computeLdMul(
              (Addr)&temp_var_for_tac_189,
              {(Addr)&y, (Addr)&temp_var_for_tac_188},
              "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:541:22");
          computeLdAdd(
              (Addr)&temp_var_for_tac_190,
              {(Addr) &(temp_var_for_const_169 = w1),
               (Addr)&temp_var_for_tac_189},
              "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:540:23");
          computeLdMul(
              (Addr)&temp_var_for_tac_191,
              {(Addr)&z, (Addr)&temp_var_for_tac_190},
              "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:540:17");
          computeLdAdd(
              (Addr)&temp_var_for_tac_192,
              {(Addr) &(temp_var_for_const_170 = w0),
               (Addr)&temp_var_for_tac_191},
              "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:539:18");
          AssignLd({(Addr)&w}, (Addr)&temp_var_for_tac_192,
                   "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:539:13");
          ;
          long double temp_var_for_tac_193, temp_var_for_tac_194,
              temp_var_for_tac_195, temp_var_for_tac_196;
          long double temp_var_for_const_171, temp_var_for_const_172;
          temp_var_for_tac_193 = x - half;

          temp_var_for_tac_194 = t - one;

          temp_var_for_tac_195 = temp_var_for_tac_193 * temp_var_for_tac_194;

          temp_var_for_tac_196 = temp_var_for_tac_195 + w;

          r = temp_var_for_tac_196;
          computeLdSub(
              (Addr)&temp_var_for_tac_193,
              {(Addr)&x, (Addr) &(temp_var_for_const_171 = half)},
              "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:543:18");
          computeLdSub(
              (Addr)&temp_var_for_tac_194,
              {(Addr)&t, (Addr) &(temp_var_for_const_172 = one)},
              "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:543:31");
          computeLdMul(
              (Addr)&temp_var_for_tac_195,
              {(Addr)&temp_var_for_tac_193, (Addr)&temp_var_for_tac_194},
              "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:543:26");
          computeLdAdd(
              (Addr)&temp_var_for_tac_196,
              {(Addr)&temp_var_for_tac_195, (Addr)&w},
              "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:543:38");
          AssignLd({(Addr)&r}, (Addr)&temp_var_for_tac_196,
                   "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:543:13");
          ;
        } else
        /* 2**66 <= x <= inf */
        {
          long double temp_var_for_tac_197, temp_var_for_tac_198;
          long double temp_var_for_const_173, temp_var_for_const_174;
          long double temp_var_for_callexp_18;

          temp_var_for_callexp_18 = __ieee754_logl(x);
          temp_var_for_tac_197 = temp_var_for_callexp_18 - one;

          temp_var_for_tac_198 = x * temp_var_for_tac_197;

          r = temp_var_for_tac_198;
          computeLdSub(
              (Addr)&temp_var_for_tac_197,
              {(Addr) &(temp_var_for_const_174 = temp_var_for_callexp_18),
               (Addr) &(temp_var_for_const_173 = one)},
              "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:547:38");
          computeLdMul(
              (Addr)&temp_var_for_tac_198,
              {(Addr)&x, (Addr)&temp_var_for_tac_197},
              "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:547:17");
          AssignLd({(Addr)&r}, (Addr)&temp_var_for_tac_198,
                   "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:547:13");
          ;
        }
      }
    }
  }

  if (se & 0x8000) {
    long double temp_var_for_ext_19;
    long double temp_var_for_tac_199;
    temp_var_for_tac_199 = nadj - r;

    temp_var_for_ext_19 = temp_var_for_tac_199;
    computeLdSub((Addr)&temp_var_for_tac_199, {(Addr)&nadj, (Addr)&r},
                 "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:555:32");
    AssignLd({(Addr)&temp_var_for_ext_19}, (Addr)&temp_var_for_tac_199,
             "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:555:25");
    ; // r
    /*(one)(__ieee754_logl(x))(x)(one)(__ieee754_logl(x))(r)(nadj)*/
    r = temp_var_for_ext_19;
    AssignLd({(Addr)&r}, (Addr)&temp_var_for_ext_19,
             "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:557:7");
    ;
  }

  long double temp_var_for_ext_20;
  temp_var_for_ext_20 = r;
  AssignLd({(Addr)&temp_var_for_ext_20}, (Addr)&r,
           "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:561:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_20", (Addr)&temp_var_for_ext_20));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_20;
}

#endif
