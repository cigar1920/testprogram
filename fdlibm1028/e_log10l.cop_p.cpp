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
  long double temp_var_for_const_0;
  y = (*((--(p))));
  AssignLd({(Addr)&y}, (Addr) &(temp_var_for_const_0 = (*((--(p))))),
           "/home/shijia/Public/testprogram/e_log10l.c_e.c:77:5");
  ;
  int temp_var_for_ext_0;
  do {
    long double temp_var_for_ext_1;
    long double temp_var_for_tac_0, temp_var_for_tac_1;
    long double temp_var_for_const_1;
    temp_var_for_tac_0 = y * x;

    temp_var_for_tac_1 = temp_var_for_tac_0 + (*((--(p))));

    temp_var_for_ext_1 = temp_var_for_tac_1;
    computeLdMul((Addr)&temp_var_for_tac_0, {(Addr)&y, (Addr)&x},
                 "/home/shijia/Public/testprogram/e_log10l.c_e.c:81:28");
    computeLdAdd((Addr)&temp_var_for_tac_1,
                 {(Addr)&temp_var_for_tac_0,
                  (Addr) &(temp_var_for_const_1 = (*((--(p)))))},
                 "/home/shijia/Public/testprogram/e_log10l.c_e.c:81:32");
    AssignLd({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_1,
             "/home/shijia/Public/testprogram/e_log10l.c_e.c:81:24");
    ; // y
    /*(p)(p)((--(p)))(x)(y)*/
    y = temp_var_for_ext_1;
    AssignLd({(Addr)&y}, (Addr)&temp_var_for_ext_1,
             "/home/shijia/Public/testprogram/e_log10l.c_e.c:83:7");
    ;
    temp_var_for_ext_0 = --n > 0;
  } while (temp_var_for_ext_0);
  long double temp_var_for_ext_2;
  temp_var_for_ext_2 = y;
  AssignLd({(Addr)&temp_var_for_ext_2}, (Addr)&y,
           "/home/shijia/Public/testprogram/e_log10l.c_e.c:87:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_2;
}

/* Evaluate x^n+1  +  P[n] x^(n)  +  P[n-1] x^(n-1)  +  ...  +  P[0] */

static long double log10l_deval(long double x, const long double *p, int n) {
  long double y;

  p += n;
  long double temp_var_for_ext_3;
  long double temp_var_for_tac_2;
  long double temp_var_for_const_2;
  temp_var_for_tac_2 = x + (*((--(p))));

  temp_var_for_ext_3 = temp_var_for_tac_2;
  computeLdAdd((Addr)&temp_var_for_tac_2,
               {(Addr)&x, (Addr) &(temp_var_for_const_2 = (*((--(p)))))},
               "/home/shijia/Public/testprogram/e_log10l.c_e.c:100:26");
  AssignLd({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_2,
           "/home/shijia/Public/testprogram/e_log10l.c_e.c:100:22");
  ; // y
  /*(p)(p)((--(p)))(x)(y)(x)(y)(p)(p)((--(p)))(x)*/
  y = temp_var_for_ext_3;
  AssignLd({(Addr)&y}, (Addr)&temp_var_for_ext_3,
           "/home/shijia/Public/testprogram/e_log10l.c_e.c:102:5");
  ;
  int temp_var_for_ext_4;
  do {
    long double temp_var_for_ext_5;
    long double temp_var_for_tac_3, temp_var_for_tac_4;
    long double temp_var_for_const_3;
    temp_var_for_tac_3 = y * x;

    temp_var_for_tac_4 = temp_var_for_tac_3 + (*((--(p))));

    temp_var_for_ext_5 = temp_var_for_tac_4;
    computeLdMul((Addr)&temp_var_for_tac_3, {(Addr)&y, (Addr)&x},
                 "/home/shijia/Public/testprogram/e_log10l.c_e.c:106:28");
    computeLdAdd((Addr)&temp_var_for_tac_4,
                 {(Addr)&temp_var_for_tac_3,
                  (Addr) &(temp_var_for_const_3 = (*((--(p)))))},
                 "/home/shijia/Public/testprogram/e_log10l.c_e.c:106:32");
    AssignLd({(Addr)&temp_var_for_ext_5}, (Addr)&temp_var_for_tac_4,
             "/home/shijia/Public/testprogram/e_log10l.c_e.c:106:24");
    ; // y
    /*(p)(p)((--(p)))(x)(p)(p)((--(p)))(x)(y)*/
    y = temp_var_for_ext_5;
    AssignLd({(Addr)&y}, (Addr)&temp_var_for_ext_5,
             "/home/shijia/Public/testprogram/e_log10l.c_e.c:108:7");
    ;
    temp_var_for_ext_4 = --n > 0;
  } while (temp_var_for_ext_4);
  long double temp_var_for_ext_6;
  temp_var_for_ext_6 = y;
  AssignLd({(Addr)&temp_var_for_ext_6}, (Addr)&y,
           "/home/shijia/Public/testprogram/e_log10l.c_e.c:112:22");
  ;
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
      (long double temp_var_for_tac_5;
  long double temp_var_for_const_4, temp_var_for_const_5;
  temp_var_for_tac_5 = 0.0 - 8.977257995689735303686582344659576526998E4L;

),
      2.048819892795278657810231591630928516206E4L,
      (long double temp_var_for_tac_6;long double temp_var_for_const_6,temp_var_for_const_7;temp_var_for_tac_6 = 0.0 - 2.024301798136027039250415126250455056397E3L;

),
      8.057002716646055371965756206836056074715E1L,
      (long double temp_var_for_tac_7;long double temp_var_for_const_8,temp_var_for_const_9;temp_var_for_tac_7 = 0.0 - 8.828896441624934385266096344596648080902E-1L;

)
};

  static const long double S[6] = {
      1.701761051846631278975701529965589676574E6L,
      (long double temp_var_for_tac_8;
  long double temp_var_for_const_10, temp_var_for_const_11;
  temp_var_for_tac_8 = 0.0 - 1.332535117259762928288745111081235577029E6L;

),
      4.001557694070773974936904547424676279307E5L,
      (long double temp_var_for_tac_9;long double temp_var_for_const_12,temp_var_for_const_13;temp_var_for_tac_9 = 0.0 - 5.748542087379434595104154610899551484314E4L;

),
      3.998526750980007367835804959888064681098E3L,
      (long double temp_var_for_tac_10;long double temp_var_for_const_14,temp_var_for_const_15;temp_var_for_tac_10 = 0.0 - 1.186359407982897997337150403816839480438E2L;

)
/* 1.000000000000000000000000000000000000000E0L, */
}
;

/* log10(2) */
static const long double L102A = 0.3125L;
static const long double L102B =
    (long double temp_var_for_tac_11;
     long double temp_var_for_const_16, temp_var_for_const_17;
     temp_var_for_tac_11 =
         0.0 - 1.14700043360188047862611052755069732318101185E-2L;

     );
/* log10(e) */
static const long double L10EA = 0.5L;
static const long double L10EB =
    (long double temp_var_for_tac_12;
     long double temp_var_for_const_18, temp_var_for_const_19;
     temp_var_for_tac_12 =
         0.0 - 6.570551809674817234887108108339491770560299E-2L;

     );
/* sqrt(2)/2 */
static const long double SQRTH =
    7.071067811865475244008443621048490392848359E-1L;

/* Test for domain */
long double temp_var_for_const_20;
ge_u.value = x;
computeLdSub((Addr)&temp_var_for_tac_5,
             {(Addr) &(temp_var_for_const_5 = 0.0),
              (Addr) &(temp_var_for_const_4 =
                           8.977257995689735303686582344659576526998E4L)},
             "/home/shijia/Public/testprogram/e_log10l.c_e.c:168:12");
computeLdSub((Addr)&temp_var_for_tac_6,
             {(Addr) &(temp_var_for_const_7 = 0.0),
              (Addr) &(temp_var_for_const_6 =
                           2.024301798136027039250415126250455056397E3L)},
             "/home/shijia/Public/testprogram/e_log10l.c_e.c:170:12");
computeLdSub((Addr)&temp_var_for_tac_7,
             {(Addr) &(temp_var_for_const_9 = 0.0),
              (Addr) &(temp_var_for_const_8 =
                           8.828896441624934385266096344596648080902E-1L)},
             "/home/shijia/Public/testprogram/e_log10l.c_e.c:172:12");
computeLdSub((Addr)&temp_var_for_tac_8,
             {(Addr) &(temp_var_for_const_11 = 0.0),
              (Addr) &(temp_var_for_const_10 =
                           1.332535117259762928288745111081235577029E6L)},
             "/home/shijia/Public/testprogram/e_log10l.c_e.c:176:12");
computeLdSub((Addr)&temp_var_for_tac_9,
             {(Addr) &(temp_var_for_const_13 = 0.0),
              (Addr) &(temp_var_for_const_12 =
                           5.748542087379434595104154610899551484314E4L)},
             "/home/shijia/Public/testprogram/e_log10l.c_e.c:178:12");
computeLdSub((Addr)&temp_var_for_tac_10,
             {(Addr) &(temp_var_for_const_15 = 0.0),
              (Addr) &(temp_var_for_const_14 =
                           1.186359407982897997337150403816839480438E2L)},
             "/home/shijia/Public/testprogram/e_log10l.c_e.c:180:12");
computeLdSub((Addr)&temp_var_for_tac_11,
             {(Addr) &(temp_var_for_const_17 = 0.0),
              (Addr) &(temp_var_for_const_16 =
                           1.14700043360188047862611052755069732318101185E-2L)},
             "/home/shijia/Public/testprogram/e_log10l.c_e.c:187:12");
computeLdSub((Addr)&temp_var_for_tac_12,
             {(Addr) &(temp_var_for_const_19 = 0.0),
              (Addr) &(temp_var_for_const_18 =
                           6.570551809674817234887108108339491770560299E-2L)},
             "/home/shijia/Public/testprogram/e_log10l.c_e.c:191:12");
AssignLd({(Addr) &(temp_var_for_const_20 = ge_u.value)}, (Addr)&x,
         "/home/shijia/Public/testprogram/e_log10l.c_e.c:197:3 "
         "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:258:14>");
;
if ((exp & 0x7fff) == 0) {
  long double temp_var_for_ext_7;
  long double temp_var_for_tac_13, temp_var_for_tac_14;
  long double temp_var_for_const_21;
  temp_var_for_tac_13 = x - x;

  temp_var_for_tac_14 = (-(1.0L)) / temp_var_for_tac_13;

  temp_var_for_ext_7 = temp_var_for_tac_14;
  computeLdSub((Addr)&temp_var_for_tac_13, {(Addr)&x, (Addr)&x},
               "/home/shijia/Public/testprogram/e_log10l.c_e.c:200:38");
  computeLdDiv(
      (Addr)&temp_var_for_tac_14,
      {(Addr) &(temp_var_for_const_21 = (-(1.0L))), (Addr)&temp_var_for_tac_13},
      "/home/shijia/Public/testprogram/e_log10l.c_e.c:200:33");
  AssignLd({(Addr)&temp_var_for_ext_7}, (Addr)&temp_var_for_tac_14,
           "/home/shijia/Public/testprogram/e_log10l.c_e.c:200:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
  callExp++; /*identify the function is  add move tmpShadow*/
  return te(0.0 - p_va) r_for_ext_7;
}

if (exp & 0x8000) {
  long double temp_var_for_ext_8;
  long double temp_var_for_tac_15, temp_var_for_tac_16, temp_var_for_tac_17;
  temp_var_for_tac_15 = x - x;

  temp_var_for_tac_16 = x - x;

  temp_var_for_tac_17 = temp_var_for_tac_15 / temp_var_for_tac_16;

  temp_var_for_ext_8 = temp_var_for_tac_17;
  computeLdSub((Addr)&temp_var_for_tac_15, {(Addr)&x, (Addr)&x},
               "/home/shijia/Public/testprogram/e_log10l.c_e.c:208:29");
  computeLdSub((Addr)&temp_var_for_tac_16, {(Addr)&x, (Addr)&x},
               "/home/shijia/Public/testprogram/e_log10l.c_e.c:208:39");
  computeLdDiv((Addr)&temp_var_for_tac_17,
               {(Addr)&temp_var_for_tac_15, (Addr)&temp_var_for_tac_16},
               "/home/shijia/Public/testprogram/e_log10l.c_e.c:208:34");
  AssignLd({(Addr)&temp_var_for_ext_8}, (Addr)&temp_var_for_tac_17,
           "/home/shijia/Public/testprogram/e_log10l.c_e.c:208:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_8;
}

if (exp >= 0x7fff) {
  long double temp_var_for_ext_9;
  long double temp_var_for_tac_18;
  temp_var_for_tac_18 = x + x;

  temp_var_for_ext_9 = temp_var_for_tac_18;
  computeLdAdd((Addr)&temp_var_for_tac_18, {(Addr)&x, (Addr)&x},
               "/home/shijia/Public/testprogram/e_log10l.c_e.c:216:28");
  AssignLd({(Addr)&temp_var_for_ext_9}, (Addr)&temp_var_for_tac_18,
           "/home/shijia/Public/testprogram/e_log10l.c_e.c:216:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_9;
}

/* separate mantissa from exponent */

/* Note, frexp is used so that denormal numbers
 * will be handled properly.
 */
long double temp_var_for_const_22;
long double temp_var_for_callexp_0;

temp_var_for_callexp_0 = __ieee754_frexpl(x, (&(e)));
x = temp_var_for_callexp_0;
AssignLd({(Addr)&x}, (Addr) &(temp_var_for_const_22 = temp_var_for_callexp_0),
         "/home/shijia/Public/testprogram/e_log10l.c_e.c:227:5");
;

/* logarithm using log(x) = z + z**3 P(z)/Q(z),
 * where z = 2(x-1)/x+1)
 */
if ((e > 2) || (e < -2)) {
  if (int temp_var_for_tac_19; int temp_var_for_const_23;
      temp_var_for_tac_19 = x < SQRTH;

      ) { /* 2( 2x-1 )/( 2x+1 ) */
    e -= 1;
    long double temp_var_for_tac_20;
    long double temp_var_for_const_24;
    temp_var_for_tac_20 = x - 0.5L;

    z = temp_var_for_tac_20;
    compute((Addr)&temp_var_for_tac_19,
            {(Addr)&x, (Addr) &(temp_var_for_const_23 = SQRTH)},
            "/home/shijia/Public/testprogram/e_log10l.c_e.c:233:11");
    computeLdSub((Addr)&temp_var_for_tac_20,
                 {(Addr)&x, (Addr) &(temp_var_for_const_24 = 0.5L)},
                 "/home/shijia/Public/testprogram/e_log10l.c_e.c:235:13");
    AssignLd({(Addr)&z}, (Addr)&temp_var_for_tac_20,
             "/home/shijia/Public/testprogram/e_log10l.c_e.c:235:9");
    ;
    long double temp_var_for_tac_21, temp_var_for_tac_22;
    long double temp_var_for_const_25, temp_var_for_const_26;
    temp_var_for_tac_21 = 0.5L * z;

    temp_var_for_tac_22 = temp_var_for_tac_21 + 0.5L;

    y = temp_var_for_tac_22;
    computeLdMul((Addr)&temp_var_for_tac_21,
                 {(Addr) &(temp_var_for_const_25 = 0.5L), (Addr)&z},
                 "/home/shijia/Public/testprogram/e_log10l.c_e.c:236:16");
    computeLdAdd(
        (Addr)&temp_var_for_tac_22,
        {(Addr)&temp_var_for_tac_21, (Addr) &(temp_var_for_const_26 = 0.5L)},
        "/home/shijia/Public/testprogram/e_log10l.c_e.c:236:20");
    AssignLd({(Addr)&y}, (Addr)&temp_var_for_tac_22,
             "/home/shijia/Public/testprogram/e_log10l.c_e.c:236:9");
    ;
  } else { /*  2 (x-1)/(x+1)   */
    long double temp_var_for_ext_10;
    long double temp_var_for_tac_23;
    long double temp_var_for_const_27;
    temp_var_for_tac_23 = x - 0.5L;

    temp_var_for_ext_10 = temp_var_for_tac_23;
    computeLdSub((Addr)&temp_var_for_tac_23,
                 {(Addr)&x, (Addr) &(temp_var_for_const_27 = 0.5L)},
                 "/home/shijia/Public/testprogram/e_log10l.c_e.c:239:31");
    AssignLd({(Addr)&temp_var_for_ext_10}, (Addr)&temp_var_for_tac_23,
             "/home/shijia/Public/testprogram/e_log10l.c_e.c:239:27");
    ; // z
    /*(0.5L)(z)(0.5L)(z)(0.5L)(0.5L)(x)*/
    z = temp_var_for_ext_10;
    AssignLd({(Addr)&z}, (Addr)&temp_var_for_ext_10,
             "/home/shijia/Public/testprogram/e_log10l.c_e.c:241:9");
    ;
    z -= 0.5L;
    ;
    long double temp_var_for_tac_25, temp_var_for_tac_26;
    long double temp_var_for_const_28, temp_var_for_const_29;
    temp_var_for_tac_25 = 0.5L * x;

    temp_var_for_tac_26 = temp_var_for_tac_25 + 0.5L;

    y = temp_var_for_tac_26;
    computeLdMul((Addr)&temp_var_for_tac_25,
                 {(Addr) &(temp_var_for_const_28 = 0.5L), (Addr)&x},
                 "/home/shijia/Public/testprogram/e_log10l.c_e.c:243:16");
    computeLdAdd(
        (Addr)&temp_var_for_tac_26,
        {(Addr)&temp_var_for_tac_25, (Addr) &(temp_var_for_const_29 = 0.5L)},
        "/home/shijia/Public/testprogram/e_log10l.c_e.c:243:20");
    AssignLd({(Addr)&y}, (Addr)&temp_var_for_tac_26,
             "/home/shijia/Public/testprogram/e_log10l.c_e.c:243:9");
    ;
  }
  long double temp_var_for_ext_11;
  long double temp_var_for_tac_27;
  temp_var_for_tac_27 = z / y;

  temp_var_for_ext_11 = temp_var_for_tac_27;
  computeLdDiv((Addr)&temp_var_for_tac_27, {(Addr)&z, (Addr)&y},
               "/home/shijia/Public/testprogram/e_log10l.c_e.c:246:29");
  AssignLd({(Addr)&temp_var_for_ext_11}, (Addr)&temp_var_for_tac_27,
           "/home/shijia/Public/testprogram/e_log10l.c_e.c:246:25");
  ; // x
  /*(0.5L)(x)(0.5L)(x)(0.5L)(y)(z)*/
  x = temp_var_for_ext_11;
  AssignLd({(Addr)&x}, (Addr)&temp_var_for_ext_11,
           "/home/shijia/Public/testprogram/e_log10l.c_e.c:248:7");
  ;
  long double temp_var_for_ext_12;
  long double temp_var_for_tac_28;
  temp_var_for_tac_28 = x * x;

  temp_var_for_ext_12 = temp_var_for_tac_28;
  computeLdMul((Addr)&temp_var_for_tac_28, {(Addr)&x, (Addr)&x},
               "/home/shijia/Public/testprogram/e_log10l.c_e.c:250:29");
  AssignLd({(Addr)&temp_var_for_ext_12}, (Addr)&temp_var_for_tac_28,
           "/home/shijia/Public/testprogram/e_log10l.c_e.c:250:25");
  ; // z
  /*(y)(z)(x)(x)*/
  z = temp_var_for_ext_12;
  AssignLd({(Addr)&z}, (Addr)&temp_var_for_ext_12,
           "/home/shijia/Public/testprogram/e_log10l.c_e.c:252:7");
  ;
  long double temp_var_for_tac_29, temp_var_for_tac_30, temp_var_for_tac_31;
  long double temp_var_for_const_30, temp_var_for_const_31;
  long double temp_var_for_callexp_1;

  long double temp_var_for_callexp_2;

  temp_var_for_callexp_1 = log10l_neval(z, R, 5);
  temp_var_for_tac_29 = z * temp_var_for_callexp_1;

  temp_var_for_callexp_2 = log10l_deval(z, S, 5);
  temp_var_for_tac_30 = temp_var_for_tac_29 / temp_var_for_callexp_2;

  temp_var_for_tac_31 = x * temp_var_for_tac_30;

  y = temp_var_for_tac_31;
  computeLdMul(
      (Addr)&temp_var_for_tac_29,
      {(Addr)&z, (Addr) &(temp_var_for_const_30 = temp_var_for_callexp_1)},
      "/home/shijia/Public/testprogram/e_log10l.c_e.c:253:16");
  computeLdDiv((Addr)&temp_var_for_tac_30,
               {(Addr)&temp_var_for_tac_29,
                (Addr) &(temp_var_for_const_31 = temp_var_for_callexp_2)},
               "/home/shijia/Public/testprogram/e_log10l.c_e.c:253:40");
  computeLdMul((Addr)&temp_var_for_tac_31,
               {(Addr)&x, (Addr)&temp_var_for_tac_30},
               "/home/shijia/Public/testprogram/e_log10l.c_e.c:253:11");
  AssignLd({(Addr)&y}, (Addr)&temp_var_for_tac_31,
           "/home/shijia/Public/testprogram/e_log10l.c_e.c:253:7");
  ;
  goto done;
}

/* logarithm using log(1+x) = x - .5x**2 + x**3 P(x)/Q(x) */

if (int temp_var_for_tac_32; int temp_var_for_const_32;
    temp_var_for_tac_32 = x < SQRTH;

    ) {
  e -= 1;
  long double temp_var_for_ext_13;
  long double temp_var_for_tac_33, temp_var_for_tac_34;
  long double temp_var_for_const_33, temp_var_for_const_34;
  temp_var_for_tac_33 = 2.0 * x;

  temp_var_for_tac_34 = temp_var_for_tac_33 - 1.0L;

  temp_var_for_ext_13 = temp_var_for_tac_34;
  compute((Addr)&temp_var_for_tac_32,
          {(Addr)&x, (Addr) &(temp_var_for_const_32 = SQRTH)},
          "/home/shijia/Public/testprogram/e_log10l.c_e.c:259:9");
  computeLdMul((Addr)&temp_var_for_tac_33,
               {(Addr) &(temp_var_for_const_33 = 2.0), (Addr)&x},
               "/home/shijia/Public/testprogram/e_log10l.c_e.c:262:31");
  computeLdSub(
      (Addr)&temp_var_for_tac_34,
      {(Addr)&temp_var_for_tac_33, (Addr) &(temp_var_for_const_34 = 1.0L)},
      "/home/shijia/Public/testprogram/e_log10l.c_e.c:262:35");
  AssignLd({(Addr)&temp_var_for_ext_13}, (Addr)&temp_var_for_tac_34,
           "/home/shijia/Public/testprogram/e_log10l.c_e.c:262:25");
  ; // x
    /*(log10l_deval(z, S, 5))(log10l_neval(z, R, 5))(z)(x)(log10l_deval(z, S,
     * 5))(log10l_neval(z, R, 5))(z)(log10l_neval(z, R, 5))(z)(1.0L)(x)(2.0)*/
  x = temp_var_for_ext_13;
  AssignLd({(Addr)&x}, (Addr)&temp_var_for_ext_13,
           "/home/shijia/Public/testprogram/e_log10l.c_e.c:265:7");
  ; /*  2x - 1  */
} else {
  long double temp_var_for_ext_14;
  long double temp_var_for_tac_35;
  long double temp_var_for_const_35;
  temp_var_for_tac_35 = x - 1.0L;

  temp_var_for_ext_14 = temp_var_for_tac_35;
  computeLdSub((Addr)&temp_var_for_tac_35,
               {(Addr)&x, (Addr) &(temp_var_for_const_35 = 1.0L)},
               "/home/shijia/Public/testprogram/e_log10l.c_e.c:268:29");
  AssignLd({(Addr)&temp_var_for_ext_14}, (Addr)&temp_var_for_tac_35,
           "/home/shijia/Public/testprogram/e_log10l.c_e.c:268:25");
  ; // x
  /*(1.0L)(x)(2.0)(x)(2.0)(1.0L)(x)*/
  x = temp_var_for_ext_14;
  AssignLd({(Addr)&x}, (Addr)&temp_var_for_ext_14,
           "/home/shijia/Public/testprogram/e_log10l.c_e.c:270:7");
  ;
}
long double temp_var_for_tac_36;
temp_var_for_tac_36 = x * x;

z = temp_var_for_tac_36;
computeLdMul((Addr)&temp_var_for_tac_36, {(Addr)&x, (Addr)&x},
             "/home/shijia/Public/testprogram/e_log10l.c_e.c:272:9");
AssignLd({(Addr)&z}, (Addr)&temp_var_for_tac_36,
         "/home/shijia/Public/testprogram/e_log10l.c_e.c:272:5");
;
long double temp_var_for_tac_37, temp_var_for_tac_38, temp_var_for_tac_39;
long double temp_var_for_const_36, temp_var_for_const_37;
long double temp_var_for_callexp_3;

long double temp_var_for_callexp_4;

temp_var_for_callexp_3 = log10l_neval(x, P, 12);
temp_var_for_tac_37 = z * temp_var_for_callexp_3;

temp_var_for_callexp_4 = log10l_deval(x, Q, 11);
temp_var_for_tac_38 = temp_var_for_tac_37 / temp_var_for_callexp_4;

temp_var_for_tac_39 = x * temp_var_for_tac_38;

y = temp_var_for_tac_39;
computeLdMul((Addr)&temp_var_for_tac_37,
             {(Addr)&z,
              (Addr) &(temp_var_for_const_36 = temp_var_for_callexp_3)},
             "/home/shijia/Public/testprogram/e_log10l.c_e.c:273:14");
computeLdDiv((Addr)&temp_var_for_tac_38,
             {(Addr)&temp_var_for_tac_37,
              (Addr) &(temp_var_for_const_37 = temp_var_for_callexp_4)},
             "/home/shijia/Public/testprogram/e_log10l.c_e.c:273:39");
computeLdMul((Addr)&temp_var_for_tac_39, {(Addr)&x, (Addr)&temp_var_for_tac_38},
             "/home/shijia/Public/testprogram/e_log10l.c_e.c:273:9");
AssignLd({(Addr)&y}, (Addr)&temp_var_for_tac_39,
         "/home/shijia/Public/testprogram/e_log10l.c_e.c:273:5");
;
long double temp_var_for_ext_15;
long double temp_var_for_tac_40, temp_var_for_tac_41;
long double temp_var_for_const_38;
temp_var_for_tac_40 = 0.5 * z;

temp_var_for_tac_41 = y - temp_var_for_tac_40;

temp_var_for_ext_15 = temp_var_for_tac_41;
computeLdMul((Addr)&temp_var_for_tac_40,
             {(Addr) &(temp_var_for_const_38 = 0.5), (Addr)&z},
             "/home/shijia/Public/testprogram/e_log10l.c_e.c:275:33");
computeLdSub((Addr)&temp_var_for_tac_41, {(Addr)&y, (Addr)&temp_var_for_tac_40},
             "/home/shijia/Public/testprogram/e_log10l.c_e.c:275:27");
AssignLd({(Addr)&temp_var_for_ext_15}, (Addr)&temp_var_for_tac_41,
         "/home/shijia/Public/testprogram/e_log10l.c_e.c:275:23");
; // y
  /*(log10l_deval(x, Q, 11))(log10l_neval(x, P, 12))(z)(x)(log10l_deval(x, Q,
   * 11))(log10l_neval(x, P, 12))(z)(log10l_neval(x, P, 12))(z)(z)(0.5)(y)*/
y = temp_var_for_ext_15;
AssignLd({(Addr)&y}, (Addr)&temp_var_for_ext_15,
         "/home/shijia/Public/testprogram/e_log10l.c_e.c:278:5");
;

done:

/* Multiply log of fraction by log10(e)
 * and base 2 exponent by log10(2).
 */
{
  long double temp_var_for_ext_16;
  long double temp_var_for_tac_42;
  long double temp_var_for_const_39;
  temp_var_for_tac_42 = y * L10EB;

  temp_var_for_ext_16 = temp_var_for_tac_42;
  computeLdMul((Addr)&temp_var_for_tac_42,
               {(Addr)&y, (Addr) &(temp_var_for_const_39 = L10EB)},
               "/home/shijia/Public/testprogram/e_log10l.c_e.c:287:29");
  AssignLd({(Addr)&temp_var_for_ext_16}, (Addr)&temp_var_for_tac_42,
           "/home/shijia/Public/testprogram/e_log10l.c_e.c:287:25");
  ; // z
  /*(z)(0.5)(y)(z)(0.5)(L10EB)(y)*/
  z = temp_var_for_ext_16;
  AssignLd({(Addr)&z}, (Addr)&temp_var_for_ext_16,
           "/home/shijia/Public/testprogram/e_log10l.c_e.c:289:7");
  ;
}

long double temp_var_for_tac_43;
long double temp_var_for_const_40;
temp_var_for_tac_43 = x * L10EB;

z += temp_var_for_tac_43;
;
long double temp_var_for_tac_45;
long double temp_var_for_const_41, temp_var_for_const_42;
temp_var_for_tac_45 = e * L102B;

z += temp_var_for_tac_45;
;
long double temp_var_for_tac_47;
long double temp_var_for_const_43;
temp_var_for_tac_47 = y * L10EA;

z += temp_var_for_tac_47;
;
long double temp_var_for_tac_49;
long double temp_var_for_const_44;
temp_var_for_tac_49 = x * L10EA;

z += temp_var_for_tac_49;
;
long double temp_var_for_tac_51;
long double temp_var_for_const_45, temp_var_for_const_46;
temp_var_for_tac_51 = e * L102A;

z += temp_var_for_tac_51;
;
long double temp_var_for_ext_17;
temp_var_for_ext_17 = z;
computeLdMul((Addr)&temp_var_for_tac_43,
             {(Addr)&x, (Addr) &(temp_var_for_const_40 = L10EB)},
             "/home/shijia/Public/testprogram/e_log10l.c_e.c:292:10");
computeLdMul((Addr)&temp_var_for_tac_45,
             {(Addr) &(temp_var_for_const_42 = e),
              (Addr) &(temp_var_for_const_41 = L102B)},
             "/home/shijia/Public/testprogram/e_log10l.c_e.c:293:10");
computeLdMul((Addr)&temp_var_for_tac_47,
             {(Addr)&y, (Addr) &(temp_var_for_const_43 = L10EA)},
             "/home/shijia/Public/testprogram/e_log10l.c_e.c:294:10");
computeLdMul((Addr)&temp_var_for_tac_49,
             {(Addr)&x, (Addr) &(temp_var_for_const_44 = L10EA)},
             "/home/shijia/Public/testprogram/e_log10l.c_e.c:295:10");
computeLdMul((Addr)&temp_var_for_tac_51,
             {(Addr) &(temp_var_for_const_46 = e),
              (Addr) &(temp_var_for_const_45 = L102A)},
             "/home/shijia/Public/testprogram/e_log10l.c_e.c:296:10");
AssignLd({(Addr)&temp_var_for_ext_17}, (Addr)&z,
         "/home/shijia/Public/testprogram/e_log10l.c_e.c:298:23");
;
callExpStack.push(getReal("temp_var_for_ext_17", (Addr)&temp_var_for_ext_17));
callExp++; /*identify the function is  add move tmpShadow*/
return temp_var_for_ext_17;
}

#endif

/* wrapper log10l(x) */
long double __log10l(long double x) {
  if (islessequal(x, 0.0L) && _LIB_VERSION != _IEEE_) {
    if (int temp_var_for_tac_53; int temp_var_for_const_47;
        temp_var_for_tac_53 = x == 0.0L;

        ) {
      feraiseexcept(FE_DIVBYZERO);
      long double temp_var_for_ext_18;
      long double temp_var_for_const_48;
      long double temp_var_for_callexp_6;

      temp_var_for_callexp_5 = __builtin_huge_vall();
      temp_var_for_callexp_6 = __kernel_standard_l(
          x, x, (-(temp_var_for_callexp_5)), KMATHERRL_LOG10_ZERO);
      temp_var_for_ext_18 = temp_var_for_callexp_6;
      compute((Addr)&temp_var_for_tac_53,
              {(Addr)&x, (Addr) &(temp_var_for_const_47 = 0.0L)},
              "/home/shijia/Public/testprogram/e_log10l.c_e.c:309:11");
      AssignLd({(Addr)&temp_var_for_ext_18},
               (Addr) &(temp_var_for_const_48 = temp_var_for_callexp_6),
               "/home/shijia/Public/testprogram/e_log10l.c_e.c:312:27");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_18", (Addr)&temp_var_for_ext_18));
      callExp++; /*identify the function is  add move tmpSh(0.0 - dow*/
ret)urn temp_var_for_ext_18;	/* log10(0) */
    } else {
      feraiseexcept(FE_INVALID);
      long double temp_var_for_ext_19;
      long double temp_var_for_const_49;
      long double temp_var_for_callexp_7;

      /*embed fun has found*/
      long double temp_var_for_callexp_8;

      temp_var_for_callexp_7 = __builtin_nanl("");
      temp_var_for_callexp_8 = __kernel_standard_l(x, x, temp_var_for_callexp_7,
                                                   KMATHERRL_LOG10_MINUS);
      temp_var_for_ext_19 = temp_var_for_callexp_8;
      AssignLd({(Addr)&temp_var_for_ext_19},
               (Addr) &(temp_var_for_const_49 = temp_var_for_callexp_8),
               "/home/shijia/Public/testprogram/e_log10l.c_e.c:321:27");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_19", (Addr)&temp_var_for_ext_19));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_19; /* log10(x<0) */
    }
  }

  long double temp_var_for_ext_20;
  long double temp_var_for_const_50;
  long double temp_var_for_callexp_9;

  temp_var_for_callexp_9 = __ieee754_log10l(x);
  temp_var_for_ext_20 = temp_var_for_callexp_9;
  AssignLd({(Addr)&temp_var_for_ext_20},
           (Addr) &(temp_var_for_const_50 = temp_var_for_callexp_9),
           "/home/shijia/Public/testprogram/e_log10l.c_e.c:331:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_20", (Addr)&temp_var_for_ext_20));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_20;
}

__typeof(__log10l) log10l __attribute__((weak, alias("__log10l")));

#endif
