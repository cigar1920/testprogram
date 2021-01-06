#include "../ScDebug/scdebug.h"
/*							log10l.c
 *
 *	Common logarithm, 128-bit long double precision
 *
 *
 *
 * SYNOPSIS:
 *
 * long double x, y, log10l();
 *
 * y = log10l( x );
 *
 *
 *
 * DESCRIPTION:
 *
 * Returns the base 10 logarithm of x.
 *
 * The argument is separated into its exponent and fractional
 * parts.  If the exponent is between -1 and +1, the logarithm
 * of the fraction is approximated by
 *
 *     log(1+x) = x - 0.5 x^2 + x^3 P(x)/Q(x).
 *
 * Otherwise, setting  z = 2(x-1)/x+1),
 *
 *     log(x) = z + z^3 P(z)/Q(z).
 *
 *
 *
 * ACCURACY:
 *
 *                      Relative error:
 * arithmetic   domain     # trials      peak         rms
 *    IEEE      0.5, 2.0     30000      2.3e-34     4.9e-35
 *    IEEE     exp(+-10000)  30000      1.0e-34     4.1e-35
 *
 * In the tests over the interval exp(+-10000), the logarithms
 * of the random arguments were uniformly distributed over
 * [-10000, +10000].
 *
 */

/*
   Cephes Math Library Release 2.2:  January, 1991
   Copyright 1984, 1991 by Stephen L. Moshier
   Adapted for glibc November, 2001

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

#ifndef __have_fpu_log10

/* Evaluate P[n] x^n  +  P[n-1] x^(n-1)  +  ...  +  P[0] */

static long double log10l_neval(long double x, const long double *p, int n) {
  long double y;

  p += n;
  y = *p--;
  long double temp_var_for_const_0;
  AssignLd({(Addr)&y}, (Addr) &(temp_var_for_const_0 = (*(((p)--)))),
           "/home/shijia/Public/testprogram/e_log10l.c_e.c:77:5");
  int temp_var_for_ext_0;
  do {
    long double temp_var_for_ext_1;
    temp_var_for_ext_1 = y * x + *p--;
    long double temp_var_for_const_1;
    long double temp_var_for_tac_0;
    computeLdMul((Addr)&temp_var_for_tac_0, {(Addr)&y, (Addr)&x},
                 "/home/shijia/Public/testprogram/e_log10l.c_e.c:81:32");
    computeLdAdd((Addr)&temp_var_for_ext_1,
                 {(Addr)&temp_var_for_tac_0,
                  (Addr) &(temp_var_for_const_1 = (*(((p)--))))},
                 "/home/shijia/Public/testprogram/e_log10l.c_e.c:81:24"); // y
    /*(p)(p)((--(p)))(x)(y)*/
    y = temp_var_for_ext_1;
    AssignLd({(Addr)&y}, (Addr)&temp_var_for_ext_1,
             "/home/shijia/Public/testprogram/e_log10l.c_e.c:83:7");
    temp_var_for_ext_0 = --n > 0;
  } while (temp_var_for_ext_0);
  long double temp_var_for_ext_2;
  temp_var_for_ext_2 = y;
  AssignLd({(Addr)&temp_var_for_ext_2}, (Addr)&y,
           "/home/shijia/Public/testprogram/e_log10l.c_e.c:87:22");
  callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_2;
}

/* Evaluate x^n+1  +  P[n] x^(n)  +  P[n-1] x^(n-1)  +  ...  +  P[0] */

static long double log10l_deval(long double x, const long double *p, int n) {
  long double y;

  p += n;
  long double temp_var_for_ext_3;
  temp_var_for_ext_3 = x + *p--;
  long double temp_var_for_const_2;
  computeLdAdd((Addr)&temp_var_for_ext_3,
               {(Addr)&x, (Addr) &(temp_var_for_const_2 = (*(((p)--))))},
               "/home/shijia/Public/testprogram/e_log10l.c_e.c:100:22"); // y
  /*(p)(p)((--(p)))(x)(y)(x)(y)(p)(p)((--(p)))(x)*/
  y = temp_var_for_ext_3;
  AssignLd({(Addr)&y}, (Addr)&temp_var_for_ext_3,
           "/home/shijia/Public/testprogram/e_log10l.c_e.c:102:5");
  int temp_var_for_ext_4;
  do {
    long double temp_var_for_ext_5;
    temp_var_for_ext_5 = y * x + *p--;
    long double temp_var_for_const_3;
    long double temp_var_for_tac_1;
    computeLdMul((Addr)&temp_var_for_tac_1, {(Addr)&y, (Addr)&x},
                 "/home/shijia/Public/testprogram/e_log10l.c_e.c:106:32");
    computeLdAdd((Addr)&temp_var_for_ext_5,
                 {(Addr)&temp_var_for_tac_1,
                  (Addr) &(temp_var_for_const_3 = (*(((p)--))))},
                 "/home/shijia/Public/testprogram/e_log10l.c_e.c:106:24"); // y
    /*(p)(p)((--(p)))(x)(p)(p)((--(p)))(x)(y)*/
    y = temp_var_for_ext_5;
    AssignLd({(Addr)&y}, (Addr)&temp_var_for_ext_5,
             "/home/shijia/Public/testprogram/e_log10l.c_e.c:108:7");
    temp_var_for_ext_4 = --n > 0;
  } while (temp_var_for_ext_4);
  long double temp_var_for_ext_6;
  temp_var_for_ext_6 = y;
  AssignLd({(Addr)&temp_var_for_ext_6}, (Addr)&y,
           "/home/shijia/Public/testprogram/e_log10l.c_e.c:112:22");
  callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_6;
}

long double __ieee754_log10l(long double x) {
  long double z;
  long double y;
  int e;
  uint32_t exp;

  /* Coefficients for ln(1+x) = x - x**2/2 + x**3 P(x)/Q(x)
   * 1/sqrt(2) <= x < sqrt(2)
   * Theoretical peak relative error = 5.3e-37,
   * relative peak error spread = 2.3e-14
   */
  static const long double P[13] = {
      1.313572404063446165910279910527789794488E4L,
      7.771154681358524243729929227226708890930E4L,
      2.014652742082537582487669938141683759923E5L,
      3.007007295140399532324943111654767187848E5L,
      2.854829159639697837788887080758954924001E5L,
      1.797628303815655343403735250238293741397E5L,
      7.594356839258970405033155585486712125861E4L,
      2.128857716871515081352991964243375186031E4L,
      3.824952356185897735160588078446136783779E3L,
      4.114517881637811823002128927449878962058E2L,
      2.321125933898420063925789532045674660756E1L,
      4.998469661968096229986658302195402690910E-1L,
      1.538612243596254322971797716843006400388E-6L};

  static const long double Q[12] = {
      3.940717212190338497730839731583397586124E4L,
      2.626900195321832660448791748036714883242E5L,
      7.777690340007566932935753241556479363645E5L,
      1.347518538384329112529391120390701166528E6L,
      1.514882452993549494932585972882995548426E6L,
      1.158019977462989115839826904108208787040E6L,
      6.132189329546557743179177159925690841200E5L,
      2.248234257620569139969141618556349415120E5L,
      5.605842085972455027590989944010492125825E4L,
      9.147150349299596453976674231612674085381E3L,
      9.104928120962988414618126155557301584078E2L,
      4.839208193348159620282142911143429644326E1L
      /* 1.000000000000000000000000000000000000000E0L, */
  };

  /* Coefficients for log(x) = z + z^3 P(z^2)/Q(z^2),
   * where z = 2(x-1)/(x+1)
   * 1/sqrt(2) <= x < sqrt(2)
   * Theoretical peak relative error = 1.1e-35,
   * relative peak error spread 1.1e-9
   */
  static const long double R[6] = {
    1.418134209872192732479751274970992665513E5L,
    (0.0 - 8.977257995689735303686582344659576526998E4L);
  long double temp_var_for_const_4, temp_var_for_const_5;
  , 2.048819892795278657810231591630928516206E4L,
      (0.0 - 2.024301798136027039250415126250455056397E3L);
  long double temp_var_for_const_6, temp_var_for_const_7;
  long double temp_var_for_tac_2;
  computeLdSub((Addr)&temp_var_for_tac_2,
               {(Addr) &(temp_var_for_const_5 = 0.0),
                (Addr) &(temp_var_for_const_4 =
                             8.977257995689735303686582344659576526998E4L)},
               "/home/shijia/Public/testprogram/e_log10l.c_e.c:170:12");
  , 8.057002716646055371965756206836056074715E1L,
      (0.0 - 8.828896441624934385266096344596648080902E-1L);
  long double temp_var_for_const_8, temp_var_for_const_9;
  long double temp_var_for_tac_3;
  computeLdSub((Addr)&temp_var_for_tac_3,
               {(Addr) &(temp_var_for_const_7 = 0.0),
                (Addr) &(temp_var_for_const_6 =
                             2.024301798136027039250415126250455056397E3L)},
               "/home/shijia/Public/testprogram/e_log10l.c_e.c:172:12");
};

static const long double S[6] = {
  1.701761051846631278975701529965589676574E6L,
  (0.0 - 1.332535117259762928288745111081235577029E6L);
long double temp_var_for_const_10, temp_var_for_const_11;
long double temp_var_for_tac_4;
computeLdSub((Addr)&temp_var_for_tac_4,
             {(Addr) &(temp_var_for_const_9 = 0.0),
              (Addr) &(temp_var_for_const_8 =
                           8.828896441624934385266096344596648080902E-1L)},
             "/home/shijia/Public/testprogram/e_log10l.c_e.c:176:12");
, 4.001557694070773974936904547424676279307E5L,
    (0.0 - 5.748542087379434595104154610899551484314E4L);
long double temp_var_for_const_12, temp_var_for_const_13;
long double temp_var_for_tac_5;
computeLdSub((Addr)&temp_var_for_tac_5,
             {(Addr) &(temp_var_for_const_11 = 0.0),
              (Addr) &(temp_var_for_const_10 =
                           1.332535117259762928288745111081235577029E6L)},
             "/home/shijia/Public/testprogram/e_log10l.c_e.c:178:12");
, 3.998526750980007367835804959888064681098E3L,
    (0.0 - 1.186359407982897997337150403816839480438E2L);
long double temp_var_for_const_14, temp_var_for_const_15;
long double temp_var_for_tac_6;
computeLdSub((Addr)&temp_var_for_tac_6,
             {(Addr) &(temp_var_for_const_13 = 0.0),
              (Addr) &(temp_var_for_const_12 =
                           5.748542087379434595104154610899551484314E4L)},
             "/home/shijia/Public/testprogram/e_log10l.c_e.c:180:12");
/* 1.000000000000000000000000000000000000000E0L, */
}
;

/* log10(2) */
static const long double L102A = 0.3125L;
static const long double L102B =
    (0.0 - 1.14700043360188047862611052755069732318101185E-2L);
long double temp_var_for_const_16, temp_var_for_const_17;
long double temp_var_for_tac_7;
computeLdSub((Addr)&temp_var_for_tac_7,
             {(Addr) &(temp_var_for_const_15 = 0.0),
              (Addr) &(temp_var_for_const_14 =
                           1.186359407982897997337150403816839480438E2L)},
             "/home/shijia/Public/testprogram/e_log10l.c_e.c:187:12");
;
/* log10(e) */
static const long double L10EA = 0.5L;
static const long double L10EB =
    (0.0 - 6.570551809674817234887108108339491770560299E-2L);
long double temp_var_for_const_18, temp_var_for_const_19;
long double temp_var_for_tac_8;
computeLdSub((Addr)&temp_var_for_tac_8,
             {(Addr) &(temp_var_for_const_17 = 0.0),
              (Addr) &(temp_var_for_const_16 =
                           1.14700043360188047862611052755069732318101185E-2L)},
             "/home/shijia/Public/testprogram/e_log10l.c_e.c:191:12");
;
/* sqrt(2)/2 */
static const long double SQRTH =
    7.071067811865475244008443621048490392848359E-1L;

/* Test for domain */
GET_LDOUBLE_EXP(exp, x);
if ((exp & 0x7fff) == 0)
  return (-1.0L / (x - x));
if (exp & 0x8000)
  return (x - x) / (x - x);
if (exp >= 0x7fff) {
  long double temp_var_for_ext_7;
  temp_var_for_ext_7 = x + x;
  long double temp_var_for_tac_9;
  computeLdSub((Addr)&temp_var_for_tac_9,
               {(Addr) &(temp_var_for_const_19 = 0.0),
                (Addr) &(temp_var_for_const_18 =
                             6.570551809674817234887108108339491770560299E-2L)},
               "/home/shijia/Public/testprogram/e_log10l.c_e.c:204:28");
  computeLdAdd((Addr)&temp_var_for_ext_7, {(Addr)&x, (Addr)&x},
               "/home/shijia/Public/testprogram/e_log10l.c_e.c:204:24");
  callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_7;
}

/* separate mantissa from exponent */

/* Note, frexp is used so that denormal numbers
 * will be handled properly.
 */
long double temp_var_for_ext_8;
temp_var_for_ext_8 = __ieee754_frexpl(x, &e);
long double temp_var_for_const_20;AssignLd({(Addr)&temp_var_for_ext_8},(Addr)&(temp_var_for_const_20=__ieee754_frexpl(getFVbyShadow<int>((Addr)&x), ((&(e)))),"/home/shijia/Public/testprogram/e_log10l.c_e.c:216:22"); // x
  /*(p)(p)((--(p)))(x)(y)(x)(y)(7)(t)(__ieee754_frexpl(x, &e))*/
  x = temp_var_for_ext_8;AssignLd({(Addr)&x},(Addr)&temp_var_for_ext_8,"/home/shijia/Public/testprogram/e_log10l.c_e.c:218:5");

  /* logarithm using log(x) = z + z**3 P(z)/Q(z),
   * where z = 2(x-1)/x+1)
   */
  if ((e > 2) || (e < -2)) {
  if (x < SQRTH) { /* 2( 2x-1 )/( 2x+1 ) */
    e -= 1;
    z = x - 0.5L;
    long double temp_var_for_const_21;
    computeLdSub((Addr)&z, {(Addr)&x, (Addr) &(temp_var_for_const_21 = 0.5L)},
                 "/home/shijia/Public/testprogram/e_log10l.c_e.c:226:9");
    y = 0.5L * z + 0.5L;
    long double temp_var_for_const_22, temp_var_for_const_23;
    long double temp_var_for_tac_10;
    computeLdMul((Addr)&temp_var_for_tac_10,
                 {(Addr) &(temp_var_for_const_22 = 0.5L), (Addr)&z},
                 "/home/shijia/Public/testprogram/e_log10l.c_e.c:227:20");
    computeLdAdd((Addr)&y, {(Addr)&temp_var_for_tac_10,
                            (Addr) &(temp_var_for_const_23 = 0.5L)},
                 "/home/shijia/Public/testprogram/e_log10l.c_e.c:227:9");
  } else { /*  2 (x-1)/(x+1)   */
    long double temp_var_for_ext_9;
    temp_var_for_ext_9 = x - 0.5L;
    long double temp_var_for_const_24;
    computeLdSub((Addr)&temp_var_for_ext_9,
                 {(Addr)&x, (Addr) &(temp_var_for_const_24 = 0.5L)},
                 "/home/shijia/Public/testprogram/e_log10l.c_e.c:230:26"); // z
    /*(0.5L)(z)(0.5L)(z)(0.5L)(0.5L)(x)*/
    z = temp_var_for_ext_9;
    AssignLd({(Addr)&z}, (Addr)&temp_var_for_ext_9,
             "/home/shijia/Public/testprogram/e_log10l.c_e.c:232:9");
    z -= 0.5L;
    y = 0.5L * x + 0.5L;
    long double temp_var_for_const_25, temp_var_for_const_26;
    long double temp_var_for_tac_11;
    computeLdMul((Addr)&temp_var_for_tac_11,
                 {(Addr) &(temp_var_for_const_25 = 0.5L), (Addr)&x},
                 "/home/shijia/Public/testprogram/e_log10l.c_e.c:234:20");
    computeLdAdd((Addr)&y, {(Addr)&temp_var_for_tac_11,
                            (Addr) &(temp_var_for_const_26 = 0.5L)},
                 "/home/shijia/Public/testprogram/e_log10l.c_e.c:234:9");
  }
  long double temp_var_for_ext_10;
  temp_var_for_ext_10 = z / y;
  computeLdDiv((Addr)&temp_var_for_ext_10, {(Addr)&z, (Addr)&y},
               "/home/shijia/Public/testprogram/e_log10l.c_e.c:237:25"); // x
  /*(0.5L)(x)(0.5L)(x)(0.5L)(y)(z)*/
  x = temp_var_for_ext_10;
  AssignLd({(Addr)&x}, (Addr)&temp_var_for_ext_10,
           "/home/shijia/Public/testprogram/e_log10l.c_e.c:239:7");
  long double temp_var_for_ext_11;
  temp_var_for_ext_11 = x * x;
  computeLdMul((Addr)&temp_var_for_ext_11, {(Addr)&x, (Addr)&x},
               "/home/shijia/Public/testprogram/e_log10l.c_e.c:241:25"); // z
  /*(y)(z)(x)(x)*/
  z = temp_var_for_ext_11;
  AssignLd({(Addr)&z}, (Addr)&temp_var_for_ext_11,
           "/home/shijia/Public/testprogram/e_log10l.c_e.c:243:7");
  y = x * (z * log10l_neval(z, R, 5) / log10l_deval(z, S, 5));
  long double temp_var_for_tac_12, temp_var_for_tac_13;
  computeLdMul((Addr)&temp_var_for_tac_12,
               {(Addr)&z, (Addr)&temp_var_for_callexp_0},
               "toString(biExpr->getExprLoc())");
  long double temp_var_for_callexp_0 =
      log10l_neval(getFVbyShadow<long double>((Addr)&z), (R), (5));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  long double temp_var_for_callexp_1 =
      log10l_deval(getFVbyShadow<long double>((Addr)&z), (S), (5));
  CallStackPop((Addr)&temp_var_for_callexp_1, getTop(temp_var_for_callexp_1));
  computeLdDiv((Addr)&temp_var_for_tac_13,
               {(Addr)&temp_var_for_tac_12, (Addr)&temp_var_for_callexp_1},
               "/home/shijia/Public/testprogram/e_log10l.c_e.c:244:11");
  computeLdMul((Addr)&y, {(Addr)&x, (Addr)&temp_var_for_tac_13},
               "/home/shijia/Public/testprogram/e_log10l.c_e.c:244:7");
  goto done;
  }

  /* logarithm using log(1+x) = x - .5x**2 + x**3 P(x)/Q(x) */

  if (x < SQRTH) {
  e -= 1;
  long double temp_var_for_ext_12;
  temp_var_for_ext_12 = 2.0 * x - 1.0L;
  long double temp_var_for_const_27, temp_var_for_const_28;
  long double temp_var_for_tac_14;
  computeLdMul((Addr)&temp_var_for_tac_14,
               {(Addr) &(temp_var_for_const_27 = 2.0), (Addr)&x},
               "/home/shijia/Public/testprogram/e_log10l.c_e.c:253:35");
  computeLdSub(
      (Addr)&temp_var_for_ext_12,
      {(Addr)&temp_var_for_tac_14, (Addr) &(temp_var_for_const_28 = 1.0L)},
      "/home/shijia/Public/testprogram/e_log10l.c_e.c:253:25"); // x
  /*(log10l_deval(z, S, 5))(log10l_neval(z, R, 5))(z)(x)(log10l_deval(z, S,
   * 5))(log10l_neval(z, R, 5))(z)(log10l_neval(z, R, 5))(z)(1.0L)(x)(2.0)*/
  x = temp_var_for_ext_12;
  AssignLd(
      {(Addr)&x}, (Addr)&temp_var_for_ext_12,
      "/home/shijia/Public/testprogram/e_log10l.c_e.c:256:7"); /*  2x - 1  */
  } else {
  long double temp_var_for_ext_13;
  temp_var_for_ext_13 = x - 1.0L;
  long double temp_var_for_const_29;
  computeLdSub((Addr)&temp_var_for_ext_13,
               {(Addr)&x, (Addr) &(temp_var_for_const_29 = 1.0L)},
               "/home/shijia/Public/testprogram/e_log10l.c_e.c:259:25"); // x
  /*(1.0L)(x)(2.0)(x)(2.0)(1.0L)(x)*/
  x = temp_var_for_ext_13;
  AssignLd({(Addr)&x}, (Addr)&temp_var_for_ext_13,
           "/home/shijia/Public/testprogram/e_log10l.c_e.c:261:7");
  }
  z = x * x;computeLdMul((Addr)&z,{(Addr)&x,(Addr)&x},"/home/shijia/Public/testprogram/e_log10l.c_e.c:263:5");
  y = x * (z * log10l_neval(x, P, 12) / log10l_deval(x, Q, 11));long double temp_var_for_tac_15,temp_var_for_tac_16;computeLdMul((Addr)&temp_var_for_tac_15,{(Addr)&z,(Addr)&temp_var_for_callexp_2},"toString(biExpr->getExprLoc())");
long double temp_var_for_callexp_2 = log10l_neval(getFVbyShadow<long double>((Addr)&x), (P), (12));CallStackPop((Addr)&temp_var_for_callexp_2,getTop(temp_var_for_callexp_2));
long double temp_var_for_callexp_3 = log10l_deval(getFVbyShadow<long double>((Addr)&x), (Q), (11));CallStackPop((Addr)&temp_var_for_callexp_3,getTop(temp_var_for_callexp_3));
computeLdDiv((Addr)&temp_var_for_tac_16,{(Addr)&temp_var_for_tac_15,(Addr)&temp_var_for_callexp_3},"/home/shijia/Public/testprogram/e_log10l.c_e.c:264:9");computeLdMul((Addr)&y,{(Addr)&x,(Addr)&temp_var_for_tac_16},"/home/shijia/Public/testprogram/e_log10l.c_e.c:264:5");
  long double temp_var_for_ext_14;
  temp_var_for_ext_14 = y - 0.5 * z;long double temp_var_for_const_30;long double temp_var_for_tac_17;computeLdMul((Addr)&temp_var_for_tac_17,{(Addr)&(temp_var_for_const_30=0.5),(Addr)&z},"/home/shijia/Public/testprogram/e_log10l.c_e.c:266:27");computeLdSub((Addr)&temp_var_for_ext_14,{(Addr)&y,(Addr)&temp_var_for_tac_17},"/home/shijia/Public/testprogram/e_log10l.c_e.c:266:23"); // y
  /*(log10l_deval(x, Q, 11))(log10l_neval(x, P, 12))(z)(x)(log10l_deval(x, Q,
   * 11))(log10l_neval(x, P, 12))(z)(log10l_neval(x, P, 12))(z)(z)(0.5)(y)*/
  y = temp_var_for_ext_14;AssignLd({(Addr)&y},(Addr)&temp_var_for_ext_14,"/home/shijia/Public/testprogram/e_log10l.c_e.c:269:5");

done:

  /* Multiply log of fraction by log10(e)
   * and base 2 exponent by log10(2).
   */
  {
  long double temp_var_for_ext_15;
  temp_var_for_ext_15 = y * L10EB;
  long double temp_var_for_const_31;
  computeLdMul((Addr)&temp_var_for_ext_15,
               {(Addr)&y, (Addr) &(temp_var_for_const_31 = L10EB)},
               "/home/shijia/Public/testprogram/e_log10l.c_e.c:278:25"); // z
  /*(z)(0.5)(y)(z)(0.5)(L10EB)(y)*/
  z = temp_var_for_ext_15;
  AssignLd({(Addr)&z}, (Addr)&temp_var_for_ext_15,
           "/home/shijia/Public/testprogram/e_log10l.c_e.c:280:7");
  }

  z += x * L10EB;long double temp_var_for_const_32;
  z += e * L102B;long double temp_var_for_const_33,temp_var_for_const_34;long double temp_var_for_tac_18;computeLdMul((Addr)&temp_var_for_tac_18,{(Addr)&x,(Addr)&(temp_var_for_const_32=L10EB)},"/home/shijia/Public/testprogram/e_log10l.c_e.c:284:10");
  z += y * L10EA;long double temp_var_for_const_35;long double temp_var_for_tac_19;computeLdMul((Addr)&temp_var_for_tac_19,{(Addr)&(temp_var_for_const_34=e),(Addr)&(temp_var_for_const_33=L102B)},"/home/shijia/Public/testprogram/e_log10l.c_e.c:285:10");
  z += x * L10EA;long double temp_var_for_const_36;long double temp_var_for_tac_20;computeLdMul((Addr)&temp_var_for_tac_20,{(Addr)&y,(Addr)&(temp_var_for_const_35=L10EA)},"/home/shijia/Public/testprogram/e_log10l.c_e.c:286:10");
  z += e * L102A;long double temp_var_for_const_37,temp_var_for_const_38;long double temp_var_for_tac_21;computeLdMul((Addr)&temp_var_for_tac_21,{(Addr)&x,(Addr)&(temp_var_for_const_36=L10EA)},"/home/shijia/Public/testprogram/e_log10l.c_e.c:287:10");
  long double temp_var_for_ext_16;
  temp_var_for_ext_16 = z;computeLdMul((Addr)&temp_var_for_ext_16,{(Addr)&(temp_var_for_const_38=e),(Addr)&(temp_var_for_const_37=L102A)},"/home/shijia/Public/testprogram/e_log10l.c_e.c:289:23");
  callExpStack.push(getReal("temp_var_for_ext_16", (Addr)&temp_var_for_ext_16));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_16;
}

#endif

/* wrapper log10l(x) */
long double __log10l(long double x) {
  if (islessequal(x, 0.0L) && _LIB_VERSION != _IEEE_) {
    if (x == 0.0L) {
      feraiseexcept(FE_DIVBYZERO);
      return __kernel_standard_l(x, x, -HUGE_VALL,
                                 KMATHERRL_LOG10_ZERO); /* log10(0) */
    } else {
      feraiseexcept(FE_INVALID);
      return __kernel_standard_l(x, x, __builtin_nanl(""),
                                 KMATHERRL_LOG10_MINUS); /* log10(x<0) */
    }
  }

  long double temp_var_for_ext_17;
  temp_var_for_ext_17 = __ieee754_log10l(x);
  long double temp_var_for_callexp_4 =
      __ieee754_log10l(getFVbyShadow<long double>((Addr)&x));
  CallStackPop((Addr)&temp_var_for_callexp_4, getTop(temp_var_for_callexp_4));
  AssignLd({(Addr)&temp_var_for_ext_17}, (Addr)&temp_var_for_callexp_4,
           "/home/shijia/Public/testprogram/e_log10l.c_e.c:312:23");
  callExpStack.push(getReal("temp_var_for_ext_17", (Addr)&temp_var_for_ext_17));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_17;
}

__typeof(__log10l) log10l __attribute__((weak, alias("__log10l")));

#endif
