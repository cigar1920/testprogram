#include "../ScDebug/scdebug.h"
/*							expm1l.c
 *
 *	Exponential function, minus 1
 *      128-bit long double precision
 *
 *
 *
 * SYNOPSIS:
 *
 * long double x, y, expm1l();
 *
 * y = expm1l( x );
 *
 *
 *
 * DESCRIPTION:
 *
 * Returns e (2.71828...) raised to the x power, minus one.
 *
 * Range reduction is accomplished by separating the argument
 * into an integer k and fraction f such that
 *
 *     x    k  f
 *    e  = 2  e.
 *
 * An expansion x + .5 x^2 + x^3 R(x) approximates exp(f) - 1
 * in the basic range [-0.5 ln 2, 0.5 ln 2].
 *
 *
 * ACCURACY:
 *
 *                      Relative error:
 * arithmetic   domain     # trials      peak         rms
 *    IEEE    -79,+MAXLOG    100,000     1.7e-34     4.5e-35
 *
 */

/* Copyright 2001 by Stephen L. Moshier

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

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

#ifndef __have_fpu_expm1

/* exp(x) - 1 = x + 0.5 x^2 + x^3 P(x)/Q(x)
   -.5 ln 2  <  x  <  .5 ln 2
   Theoretical peak relative error = 8.1e-36  */

long double __ieee754_expm1l(long double x) {
  long double px, qx, xx;
  int32_t ix, sign;
  uint32_t msw, lsw;
  int32_t k;

  static const long double P0 = 2.943520915569954073888921213330863757240E8L;
  static const long double P1 =
      (long double temp_var_for_tac_0;
       long double temp_var_for_const_0, temp_var_for_const_1;
       temp_var_for_tac_0 = 0.0 - 5.722847283900608941516165725053359168840E7L;

       );
  static const long double P2 = 8.944630806357575461578107295909719817253E6L;
  static const long double P3 =
      (long double temp_var_for_tac_1;
       long double temp_var_for_const_2, temp_var_for_const_3;
       temp_var_for_tac_1 = 0.0 - 7.212432713558031519943281748462837065308E5L;

       );
  static const long double P4 = 4.578962475841642634225390068461943438441E4L;
  static const long double P5 =
      (long double temp_var_for_tac_2;
       long double temp_var_for_const_4, temp_var_for_const_5;
       temp_var_for_tac_2 = 0.0 - 1.716772506388927649032068540558788106762E3L;

       );
  static const long double P6 = 4.401308817383362136048032038528753151144E1L;
  static const long double P7 =
      (long double temp_var_for_tac_3;
       long double temp_var_for_const_6, temp_var_for_const_7;
       temp_var_for_tac_3 = 0.0 - 4.888737542888633647784737721812546636240E-1L;

       );
  static const long double Q0 = 1.766112549341972444333352727998584753865E9L;
  static const long double Q1 =
      (long double temp_var_for_tac_4;
       long double temp_var_for_const_8, temp_var_for_const_9;
       temp_var_for_tac_4 = 0.0 - 7.848989743695296475743081255027098295771E8L;

       );
  static const long double Q2 = 1.615869009634292424463780387327037251069E8L;
  static const long double Q3 =
      (long double temp_var_for_tac_5;
       long double temp_var_for_const_10, temp_var_for_const_11;
       temp_var_for_tac_5 = 0.0 - 2.019684072836541751428967854947019415698E7L;

       );
  static const long double Q4 = 1.682912729190313538934190635536631941751E6L;
  static const long double Q5 =
      (long double temp_var_for_tac_6;
       long double temp_var_for_const_12, temp_var_for_const_13;
       temp_var_for_tac_6 = 0.0 - 9.615511549171441430850103489315371768998E4L;

       );
  static const long double Q6 = 3.697714952261803935521187272204485251835E3L;
  static const long double Q7 =
      (long double temp_var_for_tac_7;
       long double temp_var_for_const_14, temp_var_for_const_15;
       temp_var_for_tac_7 = 0.0 - 8.802340681794263968892934703309274564037E1L;

       );
  /* Q8 = 1.000000000000000000000000000000000000000E0 */
  /* C1 + C2 = ln 2 */
  static const long double C1 = 6.93145751953125E-1L;
  static const long double C2 = 1.428606820309417232121458176568075500134E-6L;
  /* ln (2^16384 * (1 - 2^-113)) */
  static const long double maxlog =
      1.1356523406294143949491931077970764891253E4L;
  /* ln 2^-114 */
  static const long double minarg =
      (long double temp_var_for_tac_8;
       long double temp_var_for_const_16, temp_var_for_const_17;
       temp_var_for_tac_8 = 0.0 - 7.9018778583833765273564461846232128760607E1L;

       );
  static const long double big = 1e4932L;

  /* Detect infinity and NaN.  */
  long double temp_var_for_const_18;
  ew_u.value = x;
  computeLdSub((Addr)&temp_var_for_tac_0,
               {(Addr) &(temp_var_for_const_1 = 0.0),
                (Addr) &(temp_var_for_const_0 =
                             5.722847283900608941516165725053359168840E7L)},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:74:12");
  computeLdSub((Addr)&temp_var_for_tac_1,
               {(Addr) &(temp_var_for_const_3 = 0.0),
                (Addr) &(temp_var_for_const_2 =
                             7.212432713558031519943281748462837065308E5L)},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:77:12");
  computeLdSub((Addr)&temp_var_for_tac_2,
               {(Addr) &(temp_var_for_const_5 = 0.0),
                (Addr) &(temp_var_for_const_4 =
                             1.716772506388927649032068540558788106762E3L)},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:80:12");
  computeLdSub((Addr)&temp_var_for_tac_3,
               {(Addr) &(temp_var_for_const_7 = 0.0),
                (Addr) &(temp_var_for_const_6 =
                             4.888737542888633647784737721812546636240E-1L)},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:83:12");
  computeLdSub((Addr)&temp_var_for_tac_4,
               {(Addr) &(temp_var_for_const_9 = 0.0),
                (Addr) &(temp_var_for_const_8 =
                             7.848989743695296475743081255027098295771E8L)},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:86:12");
  computeLdSub((Addr)&temp_var_for_tac_5,
               {(Addr) &(temp_var_for_const_11 = 0.0),
                (Addr) &(temp_var_for_const_10 =
                             2.019684072836541751428967854947019415698E7L)},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:89:12");
  computeLdSub((Addr)&temp_var_for_tac_6,
               {(Addr) &(temp_var_for_const_13 = 0.0),
                (Addr) &(temp_var_for_const_12 =
                             9.615511549171441430850103489315371768998E4L)},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:92:12");
  computeLdSub((Addr)&temp_var_for_tac_7,
               {(Addr) &(temp_var_for_const_15 = 0.0),
                (Addr) &(temp_var_for_const_14 =
                             8.802340681794263968892934703309274564037E1L)},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:95:12");
  computeLdSub((Addr)&temp_var_for_tac_8,
               {(Addr) &(temp_var_for_const_17 = 0.0),
                (Addr) &(temp_var_for_const_16 =
                             7.9018778583833765273564461846232128760607E1L)},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:105:12");
  AssignLd({(Addr) &(temp_var_for_const_18 = ew_u.value)}, (Addr)&x,
           "/home/shijia/Public/testprogram/s_expm1l.c_e.c:109:3 "
           "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
  ;
  sign = ix & 0x8000;
  ix &= 0x7fff;
  lsw |= msw & IC(0x7fffffff);
  if (ix >= 0x7fff) {
    /* Infinity. */
    if (lsw == 0) {
      if (sign) {
        long double temp_var_for_ext_0;
        long double temp_var_for_const_19;
        temp_var_for_ext_0 = (-(1.0L));
        AssignLd({(Addr)&temp_var_for_ext_0},
                 (Addr) &(temp_var_for_const_19 = (-(1.0L))),
                 "/home/shijia/Public/testprogram/s_expm1l.c_e.c:118:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
        callExp++; /*identify the function is  add move tmpShadow*/
        return (0.0 - xt_0);
      }

      else {
        long double temp_var_for_ext_1;
        temp_var_for_ext_1 = x;
        AssignLd({(Addr)&temp_var_for_ext_1}, (Addr)&x,
                 "/home/shijia/Public/testprogram/s_expm1l.c_e.c:127:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_1;
      }
    }
    /* NaN. No invalid exception. */
    long double temp_var_for_ext_2;
    temp_var_for_ext_2 = x;
    AssignLd({(Addr)&temp_var_for_ext_2}, (Addr)&x,
             "/home/shijia/Public/testprogram/s_expm1l.c_e.c:136:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  }

  /* expm1(+- 0) = +- 0.  */
  if (ix == 0 && lsw == 0) {
    long double temp_var_for_ext_3;
    temp_var_for_ext_3 = x;
    AssignLd({(Addr)&temp_var_for_ext_3}, (Addr)&x,
             "/home/shijia/Public/testprogram/s_expm1l.c_e.c:145:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_3;
  }

  /* Overflow.  */
  if (int temp_var_for_tac_9; int temp_var_for_const_20;
      temp_var_for_tac_9 = x > maxlog;

      ) {
    feraiseexcept(FE_OVERFLOW);
    long double temp_var_for_ext_4;
    long double temp_var_for_const_21;
    long double temp_var_for_callexp_0;

    temp_var_for_callexp_0 = __builtin_huge_vall();
    temp_var_for_ext_4 = temp_var_for_callexp_0;
    compute((Addr)&temp_var_for_tac_9,
            {(Addr)&x, (Addr) &(temp_var_for_const_20 = maxlog)},
            "/home/shijia/Public/testprogram/s_expm1l.c_e.c:152:9");
    AssignLd({(Addr)&temp_var_for_ext_4},
             (Addr) &(temp_var_for_const_21 = temp_var_for_callexp_0),
             "/home/shijia/Public/testprogram/s_expm1l.c_e.c:155:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_4;
  }

  /* Minimum value.  */
  if (int temp_var_for_tac_10; int temp_var_for_const_22;
      temp_var_for_tac_10 = x < minarg;

      ) {
    long double temp_var_for_ext_5;
    long double temp_var_for_tac_11, temp_var_for_tac_12;
    long double temp_var_for_const_23, temp_var_for_const_24,
        temp_var_for_const_25;
    temp_var_for_tac_11 = 4.0 / big;

    temp_var_for_tac_12 = temp_var_for_tac_11 - 1.0L;

    temp_var_for_ext_5 = temp_var_for_tac_12;
    compute((Addr)&temp_var_for_tac_10,
            {(Addr)&x, (Addr) &(temp_var_for_const_22 = minarg)},
            "/home/shijia/Public/testprogram/s_expm1l.c_e.c:162:9");
    computeLdDiv((Addr)&temp_var_for_tac_11,
                 {(Addr) &(temp_var_for_const_24 = 4.0),
                  (Addr) &(temp_var_for_const_23 = big)},
                 "/home/shijia/Public/testprogram/s_expm1l.c_e.c:164:31");
    computeLdSub(
        (Addr)&temp_var_for_tac_12,
        {(Addr)&temp_var_for_tac_11, (Addr) &(temp_var_for_const_25 = 1.0L)},
        "/home/shijia/Public/testprogram/s_expm1l.c_e.c:164:37");
    AssignLd({(Addr)&temp_var_for_ext_5}, (Addr)&temp_var_for_tac_12,
             "/home/shijia/Public/testprogram/s_expm1l.c_e.c:164:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_5;
  }

  /* Express x = ln 2 (k + remainder), remainder not exceeding 1/2. */
  long double temp_var_for_tac_13;
  long double temp_var_for_const_26, temp_var_for_const_27;
  temp_var_for_tac_13 = C1 + C2;

  xx = temp_var_for_tac_13;
  computeLdAdd((Addr)&temp_var_for_tac_13,
               {(Addr) &(temp_var_for_const_27 = C1),
                (Addr) &(temp_var_for_const_26 = C2)},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:171:11");
  AssignLd({(Addr)&xx}, (Addr)&temp_var_for_tac_13,
           "/home/shijia/Public/testprogram/s_expm1l.c_e.c:171:6");
  ; /* ln 2. */
  long double temp_var_for_tac_14, temp_var_for_tac_15;
  long double temp_var_for_const_28, temp_var_for_const_29;
  long double temp_var_for_callexp_1;

  temp_var_for_tac_14 = x / xx;

  temp_var_for_tac_15 = 0.5L + temp_var_for_tac_14;

  temp_var_for_callexp_1 = __ieee754_floorl(temp_var_for_tac_15);
  px = temp_var_for_callexp_1;
  computeLdDiv((Addr)&temp_var_for_tac_14, {(Addr)&x, (Addr)&xx},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:172:34");
  computeLdAdd(
      (Addr)&temp_var_for_tac_15,
      {(Addr) &(temp_var_for_const_28 = 0.5L), (Addr)&temp_var_for_tac_14},
      "/home/shijia/Public/testprogram/s_expm1l.c_e.c:172:30");
  AssignLd({(Addr)&px},
           (Addr) &(temp_var_for_const_29 = temp_var_for_callexp_1),
           "/home/shijia/Public/testprogram/s_expm1l.c_e.c:172:6");
  ;
  k = px;
  /* remainder times ln 2 */
  long double temp_var_for_tac_16;
  long double temp_var_for_const_30;
  temp_var_for_tac_16 = px * C1;

  x -= temp_var_for_tac_16;
  ;
  long double temp_var_for_tac_18;
  long double temp_var_for_const_31;
  temp_var_for_tac_18 = px * C2;

  x -= temp_var_for_tac_18;
  ;

  /* Approximate exp(remainder ln 2).  */
  long double temp_var_for_ext_6;
  long double temp_var_for_tac_20, temp_var_for_tac_21, temp_var_for_tac_22,
      temp_var_for_tac_23, temp_var_for_tac_24, temp_var_for_tac_25,
      temp_var_for_tac_26, temp_var_for_tac_27, temp_var_for_tac_28,
      temp_var_for_tac_29, temp_var_for_tac_30, temp_var_for_tac_31,
      temp_var_for_tac_32, temp_var_for_tac_33, temp_var_for_tac_34;
  long double temp_var_for_const_32, temp_var_for_const_33,
      temp_var_for_const_34, temp_var_for_const_35, temp_var_for_const_36,
      temp_var_for_const_37, temp_var_for_const_38, temp_var_for_const_39;
  temp_var_for_tac_20 = P7 * x;

  temp_var_for_tac_21 = temp_var_for_tac_20 + P6;

  temp_var_for_tac_22 = temp_var_for_tac_21 * x;

  temp_var_for_tac_23 = temp_var_for_tac_22 + P5;

  temp_var_for_tac_24 = temp_var_for_tac_23 * x;

  temp_var_for_tac_25 = temp_var_for_tac_24 + P4;

  temp_var_for_tac_26 = temp_var_for_tac_25 * x;

  temp_var_for_tac_27 = temp_var_for_tac_26 + P3;

  temp_var_for_tac_28 = temp_var_for_tac_27 * x;

  temp_var_for_tac_29 = temp_var_for_tac_28 + P2;

  temp_var_for_tac_30 = temp_var_for_tac_29 * x;

  temp_var_for_tac_31 = temp_var_for_tac_30 + P1;

  temp_var_for_tac_32 = temp_var_for_tac_31 * x;

  temp_var_for_tac_33 = temp_var_for_tac_32 + P0;

  temp_var_for_tac_34 = temp_var_for_tac_33 * x;

  temp_var_for_ext_6 = temp_var_for_tac_34;
  computeLdMul((Addr)&temp_var_for_tac_16,
               {(Addr)&px, (Addr) &(temp_var_for_const_30 = C1)},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:175:11");
  computeLdMul((Addr)&temp_var_for_tac_18,
               {(Addr)&px, (Addr) &(temp_var_for_const_31 = C2)},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:176:11");
  computeLdMul((Addr)&temp_var_for_tac_20,
               {(Addr) &(temp_var_for_const_32 = P7), (Addr)&x},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:181:17");
  computeLdAdd(
      (Addr)&temp_var_for_tac_21,
      {(Addr)&temp_var_for_tac_20, (Addr) &(temp_var_for_const_33 = P6)},
      "/home/shijia/Public/testprogram/s_expm1l.c_e.c:181:21");
  computeLdMul((Addr)&temp_var_for_tac_22,
               {(Addr)&temp_var_for_tac_21, (Addr)&x},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:181:27");
  computeLdAdd(
      (Addr)&temp_var_for_tac_23,
      {(Addr)&temp_var_for_tac_22, (Addr) &(temp_var_for_const_34 = P5)},
      "/home/shijia/Public/testprogram/s_expm1l.c_e.c:181:31");
  computeLdMul((Addr)&temp_var_for_tac_24,
               {(Addr)&temp_var_for_tac_23, (Addr)&x},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:181:37");
  computeLdAdd(
      (Addr)&temp_var_for_tac_25,
      {(Addr)&temp_var_for_tac_24, (Addr) &(temp_var_for_const_35 = P4)},
      "/home/shijia/Public/testprogram/s_expm1l.c_e.c:181:41");
  computeLdMul((Addr)&temp_var_for_tac_26,
               {(Addr)&temp_var_for_tac_25, (Addr)&x},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:181:47");
  computeLdAdd(
      (Addr)&temp_var_for_tac_27,
      {(Addr)&temp_var_for_tac_26, (Addr) &(temp_var_for_const_36 = P3)},
      "/home/shijia/Public/testprogram/s_expm1l.c_e.c:181:51");
  computeLdMul((Addr)&temp_var_for_tac_28,
               {(Addr)&temp_var_for_tac_27, (Addr)&x},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:181:57");
  computeLdAdd(
      (Addr)&temp_var_for_tac_29,
      {(Addr)&temp_var_for_tac_28, (Addr) &(temp_var_for_const_37 = P2)},
      "/home/shijia/Public/testprogram/s_expm1l.c_e.c:181:61");
  computeLdMul((Addr)&temp_var_for_tac_30,
               {(Addr)&temp_var_for_tac_29, (Addr)&x},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:181:67");
  computeLdAdd(
      (Addr)&temp_var_for_tac_31,
      {(Addr)&temp_var_for_tac_30, (Addr) &(temp_var_for_const_38 = P1)},
      "/home/shijia/Public/testprogram/s_expm1l.c_e.c:181:71");
  computeLdMul((Addr)&temp_var_for_tac_32,
               {(Addr)&temp_var_for_tac_31, (Addr)&x},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:181:77");
  computeLdAdd(
      (Addr)&temp_var_for_tac_33,
      {(Addr)&temp_var_for_tac_32, (Addr) &(temp_var_for_const_39 = P0)},
      "/home/shijia/Public/testprogram/s_expm1l.c_e.c:182:14");
  computeLdMul((Addr)&temp_var_for_tac_34,
               {(Addr)&temp_var_for_tac_33, (Addr)&x},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:183:12");
  AssignLd({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_34,
           "/home/shijia/Public/testprogram/s_expm1l.c_e.c:180:22");
  ; // px
  /*(xx)(x)(0.5L)(xx)(x)(C1)(px)(x)(C1)(px)(C2)(px)(x)(C2)(px)(x)(P0)(x)(P1)(x)(P2)(x)(P3)(x)(P4)(x)(P5)(x)(P6)(x)(P7)*/
  px = temp_var_for_ext_6;
  AssignLd({(Addr)&px}, (Addr)&temp_var_for_ext_6,
           "/home/shijia/Public/testprogram/s_expm1l.c_e.c:186:6");
  ;

  long double temp_var_for_tac_35, temp_var_for_tac_36, temp_var_for_tac_37,
      temp_var_for_tac_38, temp_var_for_tac_39, temp_var_for_tac_40,
      temp_var_for_tac_41, temp_var_for_tac_42, temp_var_for_tac_43,
      temp_var_for_tac_44, temp_var_for_tac_45, temp_var_for_tac_46,
      temp_var_for_tac_47, temp_var_for_tac_48, temp_var_for_tac_49;
  long double temp_var_for_const_40, temp_var_for_const_41,
      temp_var_for_const_42, temp_var_for_const_43, temp_var_for_const_44,
      temp_var_for_const_45, temp_var_for_const_46, temp_var_for_const_47;
  temp_var_for_tac_35 = x + Q7;

  temp_var_for_tac_36 = temp_var_for_tac_35 * x;

  temp_var_for_tac_37 = temp_var_for_tac_36 + Q6;

  temp_var_for_tac_38 = temp_var_for_tac_37 * x;

  temp_var_for_tac_39 = temp_var_for_tac_38 + Q5;

  temp_var_for_tac_40 = temp_var_for_tac_39 * x;

  temp_var_for_tac_41 = temp_var_for_tac_40 + Q4;

  temp_var_for_tac_42 = temp_var_for_tac_41 * x;

  temp_var_for_tac_43 = temp_var_for_tac_42 + Q3;

  temp_var_for_tac_44 = temp_var_for_tac_43 * x;

  temp_var_for_tac_45 = temp_var_for_tac_44 + Q2;

  temp_var_for_tac_46 = temp_var_for_tac_45 * x;

  temp_var_for_tac_47 = temp_var_for_tac_46 + Q1;

  temp_var_for_tac_48 = temp_var_for_tac_47 * x;

  temp_var_for_tac_49 = temp_var_for_tac_48 + Q0;

  qx = temp_var_for_tac_49;
  computeLdAdd((Addr)&temp_var_for_tac_35,
               {(Addr)&x, (Addr) &(temp_var_for_const_40 = Q7)},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:188:17");
  computeLdMul((Addr)&temp_var_for_tac_36,
               {(Addr)&temp_var_for_tac_35, (Addr)&x},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:188:23");
  computeLdAdd(
      (Addr)&temp_var_for_tac_37,
      {(Addr)&temp_var_for_tac_36, (Addr) &(temp_var_for_const_41 = Q6)},
      "/home/shijia/Public/testprogram/s_expm1l.c_e.c:188:27");
  computeLdMul((Addr)&temp_var_for_tac_38,
               {(Addr)&temp_var_for_tac_37, (Addr)&x},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:188:33");
  computeLdAdd(
      (Addr)&temp_var_for_tac_39,
      {(Addr)&temp_var_for_tac_38, (Addr) &(temp_var_for_const_42 = Q5)},
      "/home/shijia/Public/testprogram/s_expm1l.c_e.c:188:37");
  computeLdMul((Addr)&temp_var_for_tac_40,
               {(Addr)&temp_var_for_tac_39, (Addr)&x},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:188:43");
  computeLdAdd(
      (Addr)&temp_var_for_tac_41,
      {(Addr)&temp_var_for_tac_40, (Addr) &(temp_var_for_const_43 = Q4)},
      "/home/shijia/Public/testprogram/s_expm1l.c_e.c:188:47");
  computeLdMul((Addr)&temp_var_for_tac_42,
               {(Addr)&temp_var_for_tac_41, (Addr)&x},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:188:53");
  computeLdAdd(
      (Addr)&temp_var_for_tac_43,
      {(Addr)&temp_var_for_tac_42, (Addr) &(temp_var_for_const_44 = Q3)},
      "/home/shijia/Public/testprogram/s_expm1l.c_e.c:188:57");
  computeLdMul((Addr)&temp_var_for_tac_44,
               {(Addr)&temp_var_for_tac_43, (Addr)&x},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:188:63");
  computeLdAdd(
      (Addr)&temp_var_for_tac_45,
      {(Addr)&temp_var_for_tac_44, (Addr) &(temp_var_for_const_45 = Q2)},
      "/home/shijia/Public/testprogram/s_expm1l.c_e.c:188:67");
  computeLdMul((Addr)&temp_var_for_tac_46,
               {(Addr)&temp_var_for_tac_45, (Addr)&x},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:188:73");
  computeLdAdd(
      (Addr)&temp_var_for_tac_47,
      {(Addr)&temp_var_for_tac_46, (Addr) &(temp_var_for_const_46 = Q1)},
      "/home/shijia/Public/testprogram/s_expm1l.c_e.c:188:77");
  computeLdMul((Addr)&temp_var_for_tac_48,
               {(Addr)&temp_var_for_tac_47, (Addr)&x},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:189:13");
  computeLdAdd(
      (Addr)&temp_var_for_tac_49,
      {(Addr)&temp_var_for_tac_48, (Addr) &(temp_var_for_const_47 = Q0)},
      "/home/shijia/Public/testprogram/s_expm1l.c_e.c:190:14");
  AssignLd({(Addr)&qx}, (Addr)&temp_var_for_tac_49,
           "/home/shijia/Public/testprogram/s_expm1l.c_e.c:188:6");
  ;

  long double temp_var_for_tac_50;
  temp_var_for_tac_50 = x * x;

  xx = temp_var_for_tac_50;
  computeLdMul((Addr)&temp_var_for_tac_50, {(Addr)&x, (Addr)&x},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:193:10");
  AssignLd({(Addr)&xx}, (Addr)&temp_var_for_tac_50,
           "/home/shijia/Public/testprogram/s_expm1l.c_e.c:193:6");
  ;
  long double temp_var_for_ext_7;
  long double temp_var_for_tac_51, temp_var_for_tac_52, temp_var_for_tac_53,
      temp_var_for_tac_54, temp_var_for_tac_55;
  long double temp_var_for_const_48;
  temp_var_for_tac_51 = 0.5 * xx;

  temp_var_for_tac_52 = xx * px;

  temp_var_for_tac_53 = temp_var_for_tac_52 / qx;

  temp_var_for_tac_54 = temp_var_for_tac_51 + temp_var_for_tac_53;

  temp_var_for_tac_55 = x + temp_var_for_tac_54;

  temp_var_for_ext_7 = temp_var_for_tac_55;
  computeLdMul((Addr)&temp_var_for_tac_51,
               {(Addr) &(temp_var_for_const_48 = 0.5), (Addr)&xx},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:195:33");
  computeLdMul((Addr)&temp_var_for_tac_52, {(Addr)&xx, (Addr)&px},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:195:43");
  computeLdDiv((Addr)&temp_var_for_tac_53,
               {(Addr)&temp_var_for_tac_52, (Addr)&qx},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:195:48");
  computeLdAdd((Addr)&temp_var_for_tac_54,
               {(Addr)&temp_var_for_tac_51, (Addr)&temp_var_for_tac_53},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:195:38");
  computeLdAdd((Addr)&temp_var_for_tac_55,
               {(Addr)&x, (Addr)&temp_var_for_tac_54},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:195:26");
  AssignLd({(Addr)&temp_var_for_ext_7}, (Addr)&temp_var_for_tac_55,
           "/home/shijia/Public/testprogram/s_expm1l.c_e.c:195:22");
  ; // qx
  /*(x)(x)(qx)(px)(xx)(xx)(0.5)(x)*/
  qx = temp_var_for_ext_7;
  AssignLd({(Addr)&qx}, (Addr)&temp_var_for_ext_7,
           "/home/shijia/Public/testprogram/s_expm1l.c_e.c:197:6");
  ;

  /* exp(x) = exp(k ln 2) exp(remainder ln 2) = 2^k exp(remainder ln 2).

     We have qx = exp(remainder ln 2) - 1, so
     exp(x) - 1 = 2^k (qx + 1) - 1
     = 2^k qx + 2^k - 1.  */
  if (k == 16384) {
    long double temp_var_for_ext_8;
    long double temp_var_for_tac_56;
    long double temp_var_for_const_49, temp_var_for_const_50,
        temp_var_for_const_51;
    long double temp_var_for_callexp_2;

    temp_var_for_tac_56 = ((int)k) - 2;

    temp_var_for_callexp_2 = __ieee754_ldexpl(1.0L, temp_var_for_tac_56);
    temp_var_for_ext_8 = temp_var_for_callexp_2;
    computeSub((Addr)&temp_var_for_tac_56,
               {(Addr) &(temp_var_for_const_50 = ((int)k)),
                (Addr) &(temp_var_for_const_49 = 2)},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:206:56");
    AssignLd({(Addr)&temp_var_for_ext_8},
             (Addr) &(temp_var_for_const_51 = temp_var_for_callexp_2),
             "/home/shijia/Public/testprogram/s_expm1l.c_e.c:206:24");
    ; // px
      /*(qx)(px)(xx)(xx)(0.5)(x)(qx)(px)(xx)(xx)(0.5)(xx)(0.5)(qx)(px)(xx)(px)(xx)(__ieee754_ldexpl(1.0L,
       * (int)k - 2))*/
    px = temp_var_for_ext_8;
    long double temp_var_for_tac_57, temp_var_for_tac_58, temp_var_for_tac_59,
        temp_var_for_tac_60;
    long double temp_var_for_const_52, temp_var_for_const_53;
    temp_var_for_tac_57 = px * qx;

    temp_var_for_tac_58 = px - 0.25L;

    temp_var_for_tac_59 = temp_var_for_tac_57 + temp_var_for_tac_58;

    temp_var_for_tac_60 = temp_var_for_tac_59 * 4.0L;

    x = temp_var_for_tac_60;
    computeLdMul((Addr)&temp_var_for_tac_57, {(Addr)&px, (Addr)&qx},
                 "/home/shijia/Public/testprogram/s_expm1l.c_e.c:210:13");
    computeLdSub((Addr)&temp_var_for_tac_58,
                 {(Addr)&px, (Addr) &(temp_var_for_const_52 = 0.25L)},
                 "/home/shijia/Public/testprogram/s_expm1l.c_e.c:210:24");
    computeLdAdd((Addr)&temp_var_for_tac_59,
                 {(Addr)&temp_var_for_tac_57, (Addr)&temp_var_for_tac_58},
                 "/home/shijia/Public/testprogram/s_expm1l.c_e.c:210:18");
    computeLdMul(
        (Addr)&temp_var_for_tac_60,
        {(Addr)&temp_var_for_tac_59, (Addr) &(temp_var_for_const_53 = 4.0L)},
        "/home/shijia/Public/testprogram/s_expm1l.c_e.c:210:34");
    AssignLd({(Addr)&x}, (Addr)&temp_var_for_tac_60,
             "/home/shijia/Public/testprogram/s_expm1l.c_e.c:210:7");
    ;
  } else {
    long double temp_var_for_ext_9;
    long double temp_var_for_const_54;
    long double temp_var_for_callexp_3;

    temp_var_for_callexp_3 = __ieee754_ldexpl(1.0L, ((int)k));
    temp_var_for_ext_9 = temp_var_for_callexp_3;
    AssignLd({(Addr)&temp_var_for_ext_9},
             (Addr) &(temp_var_for_const_54 = temp_var_for_callexp_3),
             "/home/shijia/Public/testprogram/s_expm1l.c_e.c:213:24");
    ; // px
      /*(4.0L)(0.25L)(px)(qx)(px)(0.25L)(px)(qx)(px)(qx)(px)(0.25L)(px)(__ieee754_ldexpl(1.0L,
       * (int)k))*/
    px = temp_var_for_ext_9;
    AssignLd({(Addr)&px}, (Addr)&temp_var_for_ext_9,
             "/home/shijia/Public/testprogram/s_expm1l.c_e.c:216:8");
    ;
    long double temp_var_for_tac_61, temp_var_for_tac_62, temp_var_for_tac_63;
    long double temp_var_for_const_55;
    temp_var_for_tac_61 = px * qx;

    temp_var_for_tac_62 = px - 1.0L;

    temp_var_for_tac_63 = temp_var_for_tac_61 + temp_var_for_tac_62;

    x = temp_var_for_tac_63;
    computeLdMul((Addr)&temp_var_for_tac_61, {(Addr)&px, (Addr)&qx},
                 "/home/shijia/Public/testprogram/s_expm1l.c_e.c:217:12");
    computeLdSub((Addr)&temp_var_for_tac_62,
                 {(Addr)&px, (Addr) &(temp_var_for_const_55 = 1.0L)},
                 "/home/shijia/Public/testprogram/s_expm1l.c_e.c:217:23");
    computeLdAdd((Addr)&temp_var_for_tac_63,
                 {(Addr)&temp_var_for_tac_61, (Addr)&temp_var_for_tac_62},
                 "/home/shijia/Public/testprogram/s_expm1l.c_e.c:217:17");
    AssignLd({(Addr)&x}, (Addr)&temp_var_for_tac_63,
             "/home/shijia/Public/testprogram/s_expm1l.c_e.c:217:7");
    ;
  }
  long double temp_var_for_ext_10;
  temp_var_for_ext_10 = x;
  AssignLd({(Addr)&temp_var_for_ext_10}, (Addr)&x,
           "/home/shijia/Public/testprogram/s_expm1l.c_e.c:220:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_10", (Addr)&temp_var_for_ext_10));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_10;
}

#endif

long double __expm1l(long double x) {
  long double z = __ieee754_expm1l(x);

  if ((!isfinite(z) || int temp_var_for_tac_64, temp_var_for_tac_65;
       int temp_var_for_const_56, temp_var_for_const_57;
       temp_var_for_tac_64 = 0.0 - 1.0L;

       temp_var_for_tac_65 = z == temp_var_for_tac_64;

       ) &&
      isfinite(x) && _LIB_VERSION != _IEEE_) {
    long double temp_var_for_ext_11;
    long double temp_var_for_const_58;
    long double temp_var_for_callexp_4;

    temp_var_for_callexp_4 =
        __kernel_standard_l(x, x, z, signbit(x) ? KMATHERRL_EXPM1_UNDERFLOW
                                                : KMATHERRL_EXPM1_OVERFLOW);
    temp_var_for_ext_11 = temp_var_for_callexp_4;
    computeLdSub((Addr)&temp_var_for_tac_64,
                 {(Addr) &(temp_var_for_const_57 = 0.0),
                  (Addr) &(temp_var_for_const_56 = 1.0L)},
                 "/home/shijia/Public/testprogram/s_expm1l.c_e.c:231:34");
    compute((Addr)&temp_var_for_tac_65, {(Addr)&z, (Addr)&temp_var_for_tac_64},
            "/home/shijia/Public/testprogram/s_expm1l.c_e.c:231:26");
    AssignLd({(Addr)&temp_var_for_ext_11},
             (Addr) &(temp_var_for_const_58 = temp_var_for_callexp_4),
             "/home/shijia/Public/testprogram/s_expm1l.c_e.c:234:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_11", (Addr)&temp_var_for_ext_11));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_11;
  }

  long double temp_var_for_ext_12;
  temp_var_for_ext_12 = z;
  callExpStack.push(getReal("temp_var_for_ext_12", (Addr)&temp_var_for_ext_12));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_12;
}

__typeof(__expm1l) expm1l __attribute__((weak, alias("__expm1l")));

#endif
