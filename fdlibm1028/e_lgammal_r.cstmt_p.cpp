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

  GET_LDOUBLE_WORDS(se, i0, i1, x);
  ix = se & 0x7fff;
  ix = (ix << 16) | (i0 >> 16);
  if (ix < IC(0x3ffd8000)) /* 0.25 */
    return __ieee754_sinl(pi * x);
  y = (0.0 - x);
  long double temp_var_for_const_0;
  computeLdSub(
      (Addr)&y,
      {(Addr) &(temp_var_for_const_0 = 0.0), (Addr)&x}, "/home/shijia/Public/"
                                                        "testprogram/"
                                                        "e_lgammal_r.c_e.c:116:"
                                                        "5"); /* x is assume
                                                                 negative */

  /*
   * argument reduction, make sure inexact flag not raised if input
   * is an integer
   */
  z = __ieee754_floorl(y);
  long double temp_var_for_const_1;AssignLd({(Addr)&z},(Addr)&(temp_var_for_const_1=__ieee754_floorl(getFVbyShadow<int>((Addr)&y)),"/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:122:5");
  if (z != y) { /* inexact anyway */
    y *= 0.5;
    long double temp_var_for_ext_0;
    temp_var_for_ext_0 = 2.0 * (y - __ieee754_floorl(y));
    long double temp_var_for_const_2, temp_var_for_const_3;
    long double temp_var_for_tac_0;computeLdSub((Addr)&temp_var_for_tac_0,{(Addr)&y,(Addr)&(temp_var_for_const_2=__ieee754_floorl(getFVbyShadow<int>((Addr)&y))},"/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:126:30");
    computeLdMul(
        (Addr)&temp_var_for_ext_0,
        {(Addr) &(temp_var_for_const_3 = 2.0), (Addr)&temp_var_for_tac_0},
        "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:126:24"); // y
    /*(0.5)(y)(__ieee754_floorl(y))(y)(2.0)*/
    y = temp_var_for_ext_0;
    AssignLd(
        {(Addr)&y}, (Addr)&temp_var_for_ext_0,
        "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:128:7"); /* y = |x|
                                                                       mod 2.0
                                                                       */
    n = (int32_t)(y * 4.0);
  } else {
    if (ix >= IC(0x403f8000)) /* 2^64 */
    {
      y = zero;
      n = 0; /* y must be even */
    } else {
      if (ix < IC(0x403e8000)) /* 2^63 */
        z = y + two63;         /* exact */
      GET_LDOUBLE_WORDS(se, i0, i1, z);
      n = i1 & 1;
      y = n;
      n <<= 2;
    }
  }

  switch ((int)n) {
  case 0:
    y = __ieee754_sinl(pi * y);
    break;
  case 1:
  case 2:
    y = __ieee754_cosl(pi * (half - y));
    break;
  case 3:
  case 4:
    y = __ieee754_sinl(pi * (one - y));
    break;
  case 5:
  case 6:
    y = -__ieee754_cosl(pi * (y - 1.5));
    break;
  default:
    y = __ieee754_sinl(pi * (y - 2.0));
    break;
  }
  long double temp_var_for_ext_1;
  temp_var_for_ext_1 = -y;AssignLd({(Addr)&temp_var_for_ext_1},(Addr)&(-(y)),"/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:166:22");
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return (0.0 - 1);double temp_var_for_const_4,temp_var_for_const_5;;
double temp_var_for_tac_1 ;computeDSub((Addr)&temp_var_for_tac_1,{(Addr)&(temp_var_for_const_5=0.0),(Addr)&(temp_var_for_const_4=1)},"toString(biExpr->getExprLoc())");
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
      (0.0 - 6.343246574721079391729402781192128239938E2L);
  long double temp_var_for_const_6, temp_var_for_const_7;
  ;
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
      (0.0 - 1.2148629053584961146050602565082954242826E-1);
  double temp_var_for_const_8, temp_var_for_const_9;
  double temp_var_for_tac_2;
  computeDSub((Addr)&temp_var_for_tac_2,
              {(Addr) &(temp_var_for_const_7 = 0.0),
               (Addr) &(temp_var_for_const_6 =
                            6.343246574721079391729402781192128239938E2L)},
              "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:199:12");
  ; /* double precision */
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
      (0.0 - 8.886217500092090678492242071879342025627E1L);
  long double temp_var_for_const_10, temp_var_for_const_11;
  long double temp_var_for_tac_3;
  computeLdSub((Addr)&temp_var_for_tac_3,
               {(Addr) &(temp_var_for_const_9 = 0.0),
                (Addr) &(temp_var_for_const_8 =
                             1.2148629053584961146050602565082954242826E-1)},
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:230:12");
  ;
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
      (0.0 - 3.901428390086348447890408306153378922752E6L);
  long double temp_var_for_const_12, temp_var_for_const_13;
  long double temp_var_for_tac_4;
  computeLdSub((Addr)&temp_var_for_tac_4,
               {(Addr) &(temp_var_for_const_11 = 0.0),
                (Addr) &(temp_var_for_const_10 =
                             8.886217500092090678492242071879342025627E1L)},
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:251:12");
  ;
  static const long double s2 =
      (0.0 - 6.573568698209374121847873064292963089438E6L);
  long double temp_var_for_const_14, temp_var_for_const_15;
  long double temp_var_for_tac_5;
  computeLdSub((Addr)&temp_var_for_tac_5,
               {(Addr) &(temp_var_for_const_13 = 0.0),
                (Addr) &(temp_var_for_const_12 =
                             3.901428390086348447890408306153378922752E6L)},
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:253:12");
  ;
  static const long double s3 =
      (0.0 - 3.319055881485044417245964508099095984643E6L);
  long double temp_var_for_const_16, temp_var_for_const_17;
  long double temp_var_for_tac_6;
  computeLdSub((Addr)&temp_var_for_tac_6,
               {(Addr) &(temp_var_for_const_15 = 0.0),
                (Addr) &(temp_var_for_const_14 =
                             6.573568698209374121847873064292963089438E6L)},
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:255:12");
  ;
  static const long double s4 =
      (0.0 - 7.094891568758439227560184618114707107977E5L);
  long double temp_var_for_const_18, temp_var_for_const_19;
  long double temp_var_for_tac_7;
  computeLdSub((Addr)&temp_var_for_tac_7,
               {(Addr) &(temp_var_for_const_17 = 0.0),
                (Addr) &(temp_var_for_const_16 =
                             3.319055881485044417245964508099095984643E6L)},
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:257:12");
  ;
  static const long double s5 =
      (0.0 - 6.263426646464505837422314539808112478303E4L);
  long double temp_var_for_const_20, temp_var_for_const_21;
  long double temp_var_for_tac_8;
  computeLdSub((Addr)&temp_var_for_tac_8,
               {(Addr) &(temp_var_for_const_19 = 0.0),
                (Addr) &(temp_var_for_const_18 =
                             7.094891568758439227560184618114707107977E5L)},
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:259:12");
  ;
  static const long double s6 =
      (0.0 - 1.684926520999477529949915657519454051529E3L);
  long double temp_var_for_const_22, temp_var_for_const_23;
  long double temp_var_for_tac_9;
  computeLdSub((Addr)&temp_var_for_tac_9,
               {(Addr) &(temp_var_for_const_21 = 0.0),
                (Addr) &(temp_var_for_const_20 =
                             6.263426646464505837422314539808112478303E4L)},
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:261:12");
  ;
  static const long double r0 =
      (0.0 - 1.883978160734303518163008696712983134698E7L);
  long double temp_var_for_const_24, temp_var_for_const_25;
  long double temp_var_for_tac_10;
  computeLdSub((Addr)&temp_var_for_tac_10,
               {(Addr) &(temp_var_for_const_23 = 0.0),
                (Addr) &(temp_var_for_const_22 =
                             1.684926520999477529949915657519454051529E3L)},
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:263:12");
  ;
  static const long double r1 =
      (0.0 - 2.815206082812062064902202753264922306830E7L);
  long double temp_var_for_const_26, temp_var_for_const_27;
  long double temp_var_for_tac_11;
  computeLdSub((Addr)&temp_var_for_tac_11,
               {(Addr) &(temp_var_for_const_25 = 0.0),
                (Addr) &(temp_var_for_const_24 =
                             1.883978160734303518163008696712983134698E7L)},
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:265:12");
  ;
  static const long double r2 =
      (0.0 - 1.600245495251915899081846093343626358398E7L);
  long double temp_var_for_const_28, temp_var_for_const_29;
  long double temp_var_for_tac_12;
  computeLdSub((Addr)&temp_var_for_tac_12,
               {(Addr) &(temp_var_for_const_27 = 0.0),
                (Addr) &(temp_var_for_const_26 =
                             2.815206082812062064902202753264922306830E7L)},
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:267:12");
  ;
  static const long double r3 =
      (0.0 - 4.310526301881305003489257052083370058799E6L);
  long double temp_var_for_const_30, temp_var_for_const_31;
  long double temp_var_for_tac_13;
  computeLdSub((Addr)&temp_var_for_tac_13,
               {(Addr) &(temp_var_for_const_29 = 0.0),
                (Addr) &(temp_var_for_const_28 =
                             1.600245495251915899081846093343626358398E7L)},
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:269:12");
  ;
  static const long double r4 =
      (0.0 - 5.563807682263923279438235987186184968542E5L);
  long double temp_var_for_const_32, temp_var_for_const_33;
  long double temp_var_for_tac_14;
  computeLdSub((Addr)&temp_var_for_tac_14,
               {(Addr) &(temp_var_for_const_31 = 0.0),
                (Addr) &(temp_var_for_const_30 =
                             4.310526301881305003489257052083370058799E6L)},
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:271:12");
  ;
  static const long double r5 =
      (0.0 - 3.027734654434169996032905158145259713083E4L);
  long double temp_var_for_const_34, temp_var_for_const_35;
  long double temp_var_for_tac_15;
  computeLdSub((Addr)&temp_var_for_tac_15,
               {(Addr) &(temp_var_for_const_33 = 0.0),
                (Addr) &(temp_var_for_const_32 =
                             5.563807682263923279438235987186184968542E5L)},
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:273:12");
  ;
  static const long double r6 =
      (0.0 - 4.501995652861105629217250715790764371267E2L);
  long double temp_var_for_const_36, temp_var_for_const_37;
  long double temp_var_for_tac_16;
  computeLdSub((Addr)&temp_var_for_tac_16,
               {(Addr) &(temp_var_for_const_35 = 0.0),
                (Addr) &(temp_var_for_const_34 =
                             3.027734654434169996032905158145259713083E4L)},
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:275:12");
  ;
  /* static const long double r6 =  1.000000000000000000000000000000000000000E0
   */

  /* lgam(x) = ( x - 0.5 ) * log(x) - x + LS2PI + 1/x w(1/x^2)
     x >= 8
     Peak relative error 1.51e-21
     w0 = LS2PI - 0.5 */
  static const long double w0 = 4.189385332046727417803e-1L;
  static const long double w1 = 8.333333333333331447505E-2L;
  static const long double w2 = (0.0 - 2.777777777750349603440E-3L);
  long double temp_var_for_const_38, temp_var_for_const_39;
  long double temp_var_for_tac_17;
  computeLdSub((Addr)&temp_var_for_tac_17,
               {(Addr) &(temp_var_for_const_37 = 0.0),
                (Addr) &(temp_var_for_const_36 =
                             4.501995652861105629217250715790764371267E2L)},
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:285:38");
  ;
  static const long double w3 = 7.936507795855070755671E-4L;
  static const long double w4 = (0.0 - 5.952345851765688514613E-4L);
  long double temp_var_for_const_40, temp_var_for_const_41;
  long double temp_var_for_tac_18;
  computeLdSub((Addr)&temp_var_for_tac_18,
               {(Addr) &(temp_var_for_const_39 = 0.0),
                (Addr) &(temp_var_for_const_38 = 2.777777777750349603440E-3L)},
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:287:38");
  ;
  static const long double w5 = 8.412723297322498080632E-4L;
  static const long double w6 = (0.0 - 1.880801938119376907179E-3L);
  long double temp_var_for_const_42, temp_var_for_const_43;
  long double temp_var_for_tac_19;
  computeLdSub((Addr)&temp_var_for_tac_19,
               {(Addr) &(temp_var_for_const_41 = 0.0),
                (Addr) &(temp_var_for_const_40 = 5.952345851765688514613E-4L)},
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:289:38");
  ;
  static const long double w7 = 4.885026142432270781165E-3L;
  static const long double zero = 0.0L;

  *signgamp = 1;
  GET_LDOUBLE_WORDS(se, i0, i1, x);
  ix = se & 0x7fff;

  if ((ix | i0 | i1) == 0) {
    if (se & 0x8000)
      *signgamp = -1;
    return one / __ieee754_fabsl(x);
  }

  ix = (ix << 16) | (i0 >> 16);

  /* purge off +-inf, NaN, +-0, and negative arguments */
  if (ix >= IC(0x7fff0000))
    return x * x;

  if (ix < IC(0x3fc08000)) /* 2^-63 */
  {                        /* |x|<2**-63, return -log(|x|) */
    if (se & 0x8000) {
      *signgamp = -1;
      return -__ieee754_logl(-x);
    } else
      return -__ieee754_logl(x);
  }
  if (se & 0x8000) {
    t = sin_pi_l(x);
    if (t == zero)
      return one / __ieee754_fabsl(t); /* -integer */
    nadj = __ieee754_logl(pi / __ieee754_fabsl(t * x));
    if (t < zero)
      *signgamp = -1;
    x = -x;
  }

  /* purge off 1 and 2 */
  if ((((ix - IC(0x3fff8000)) | i0 | i1) == 0) ||
      (((ix - IC(0x40008000)) | i0 | i1) == 0))
    r = 0;
  else if (ix < IC(0x40008000)) /* 2.0 */
  {
    /* x < 2.0 */
    if (ix <= IC(0x3ffee666)) /* 8.99993896484375e-1 */
    {
      /* lgamma(x) = lgamma(x+1) - log(x) */
      r = -__ieee754_logl(x);
      if (ix >= IC(0x3ffebb4a)) /* 7.31597900390625e-1 */
      {
        y = x - one;
        i = 0;
      } else if (ix >= IC(0x3ffced33)) /* 2.31639862060546875e-1 */
      {
        y = x - (tc - one);
        i = 1;
      } else {
        /* x < 0.23 */
        y = x;
        i = 2;
      }
    } else {
      r = zero;
      if (ix >= IC(0x3fffdda6)) /* 1.73162841796875 */
      {
        /* [1.7316,2] */
        y = x - 2.0;
        i = 0;
      } else if (ix >= IC(0x3fff9da6)) /* 1.23162841796875 */
      {
        /* [1.23,1.73] */
        y = x - tc;
        i = 1;
      } else {
        /* [0.9, 1.23] */
        y = x - one;
        i = 2;
      }
    }
    switch ((int)i) {
    case 0:
      p1 = a0 + y * (a1 + y * (a2 + y * (a3 + y * (a4 + y * a5))));
      p2 = b0 + y * (b1 + y * (b2 + y * (b3 + y * (b4 + y))));
      r += half * y + y * p1 / p2;
      break;
    case 1:
      p1 = g0 + y * (g1 + y * (g2 + y * (g3 + y * (g4 + y * (g5 + y * g6)))));
      p2 = h0 + y * (h1 + y * (h2 + y * (h3 + y * (h4 + y * (h5 + y)))));
      p = tt + y * p1 / p2;
      r += (tf + p);
      break;
    case 2:
      p1 = y *
           (u0 + y * (u1 + y * (u2 + y * (u3 + y * (u4 + y * (u5 + y * u6))))));
      p2 = v0 + y * (v1 + y * (v2 + y * (v3 + y * (v4 + y * (v5 + y)))));
      r += (-half * y + p1 / p2);
      break;
    }
  } else if (ix < IC(0x40028000)) /* 8.0 */
  {
    /* x < 8.0 */
    i = (int32_t)x;
    t = zero;
    y = x - (double)i;
    p = y *
        (s0 + y * (s1 + y * (s2 + y * (s3 + y * (s4 + y * (s5 + y * s6))))));
    q = r0 +
        y * (r1 + y * (r2 + y * (r3 + y * (r4 + y * (r5 + y * (r6 + y))))));
    r = half * y + p / q;
    z = one; /* lgamma(1+s) = log(s) + lgamma(s) */
    switch ((int)i) {
    case 7:
      z *= (y + 6.0); /* FALLTHRU */
    case 6:
      z *= (y + 5.0); /* FALLTHRU */
    case 5:
      z *= (y + 4.0); /* FALLTHRU */
    case 4:
      z *= (y + 3.0); /* FALLTHRU */
    case 3:
      z *= (y + 2.0); /* FALLTHRU */
      r += __ieee754_logl(z);
      break;
    }
  } else if (ix < IC(0x40418000)) /* 2^66 */
  {
    /* 8.0 <= x < 2**66 */
    t = __ieee754_logl(x);
    z = one / x;
    y = z * z;
    w = w0 +
        z * (w1 +
             y * (w2 + y * (w3 + y * (w4 + y * (w5 + y * (w6 + y * w7))))));
    r = (x - half) * (t - one) + w;
  } else
    /* 2**66 <= x <= inf */
    r = x * (__ieee754_logl(x) - one);
  if (se & 0x8000)
    r = nadj - r;
  long double temp_var_for_ext_2;
  temp_var_for_ext_2 = r;
  computeLdSub((Addr)&temp_var_for_ext_2,
               {(Addr) &(temp_var_for_const_43 = 0.0),
                (Addr) &(temp_var_for_const_42 = 1.880801938119376907179E-3L)},
               "/home/shijia/Public/testprogram/e_lgammal_r.c_e.c:430:22");
  callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_2;
}

#endif
