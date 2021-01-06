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
      (0.0 - 5.722847283900608941516165725053359168840E7L);
  long double temp_var_for_const_0, temp_var_for_const_1;
  ;
  static const long double P2 = 8.944630806357575461578107295909719817253E6L;
  static const long double P3 =
      (0.0 - 7.212432713558031519943281748462837065308E5L);
  long double temp_var_for_const_2, temp_var_for_const_3;
  long double temp_var_for_tac_0;
  computeLdSub((Addr)&temp_var_for_tac_0,
               {(Addr) &(temp_var_for_const_1 = 0.0),
                (Addr) &(temp_var_for_const_0 =
                             5.722847283900608941516165725053359168840E7L)},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:77:12");
  ;
  static const long double P4 = 4.578962475841642634225390068461943438441E4L;
  static const long double P5 =
      (0.0 - 1.716772506388927649032068540558788106762E3L);
  long double temp_var_for_const_4, temp_var_for_const_5;
  long double temp_var_for_tac_1;
  computeLdSub((Addr)&temp_var_for_tac_1,
               {(Addr) &(temp_var_for_const_3 = 0.0),
                (Addr) &(temp_var_for_const_2 =
                             7.212432713558031519943281748462837065308E5L)},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:80:12");
  ;
  static const long double P6 = 4.401308817383362136048032038528753151144E1L;
  static const long double P7 =
      (0.0 - 4.888737542888633647784737721812546636240E-1L);
  long double temp_var_for_const_6, temp_var_for_const_7;
  long double temp_var_for_tac_2;
  computeLdSub((Addr)&temp_var_for_tac_2,
               {(Addr) &(temp_var_for_const_5 = 0.0),
                (Addr) &(temp_var_for_const_4 =
                             1.716772506388927649032068540558788106762E3L)},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:83:12");
  ;
  static const long double Q0 = 1.766112549341972444333352727998584753865E9L;
  static const long double Q1 =
      (0.0 - 7.848989743695296475743081255027098295771E8L);
  long double temp_var_for_const_8, temp_var_for_const_9;
  long double temp_var_for_tac_3;
  computeLdSub((Addr)&temp_var_for_tac_3,
               {(Addr) &(temp_var_for_const_7 = 0.0),
                (Addr) &(temp_var_for_const_6 =
                             4.888737542888633647784737721812546636240E-1L)},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:86:12");
  ;
  static const long double Q2 = 1.615869009634292424463780387327037251069E8L;
  static const long double Q3 =
      (0.0 - 2.019684072836541751428967854947019415698E7L);
  long double temp_var_for_const_10, temp_var_for_const_11;
  long double temp_var_for_tac_4;
  computeLdSub((Addr)&temp_var_for_tac_4,
               {(Addr) &(temp_var_for_const_9 = 0.0),
                (Addr) &(temp_var_for_const_8 =
                             7.848989743695296475743081255027098295771E8L)},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:89:12");
  ;
  static const long double Q4 = 1.682912729190313538934190635536631941751E6L;
  static const long double Q5 =
      (0.0 - 9.615511549171441430850103489315371768998E4L);
  long double temp_var_for_const_12, temp_var_for_const_13;
  long double temp_var_for_tac_5;
  computeLdSub((Addr)&temp_var_for_tac_5,
               {(Addr) &(temp_var_for_const_11 = 0.0),
                (Addr) &(temp_var_for_const_10 =
                             2.019684072836541751428967854947019415698E7L)},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:92:12");
  ;
  static const long double Q6 = 3.697714952261803935521187272204485251835E3L;
  static const long double Q7 =
      (0.0 - 8.802340681794263968892934703309274564037E1L);
  long double temp_var_for_const_14, temp_var_for_const_15;
  long double temp_var_for_tac_6;
  computeLdSub((Addr)&temp_var_for_tac_6,
               {(Addr) &(temp_var_for_const_13 = 0.0),
                (Addr) &(temp_var_for_const_12 =
                             9.615511549171441430850103489315371768998E4L)},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:95:12");
  ;
  /* Q8 = 1.000000000000000000000000000000000000000E0 */
  /* C1 + C2 = ln 2 */
  static const long double C1 = 6.93145751953125E-1L;
  static const long double C2 = 1.428606820309417232121458176568075500134E-6L;
  /* ln (2^16384 * (1 - 2^-113)) */
  static const long double maxlog =
      1.1356523406294143949491931077970764891253E4L;
  /* ln 2^-114 */
  static const long double minarg =
      (0.0 - 7.9018778583833765273564461846232128760607E1L);
  long double temp_var_for_const_16, temp_var_for_const_17;
  long double temp_var_for_tac_7;
  computeLdSub((Addr)&temp_var_for_tac_7,
               {(Addr) &(temp_var_for_const_15 = 0.0),
                (Addr) &(temp_var_for_const_14 =
                             8.802340681794263968892934703309274564037E1L)},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:105:12");
  ;
  static const long double big = 1e4932L;

  /* Detect infinity and NaN.  */
  GET_LDOUBLE_WORDS(ix, msw, lsw, x);
  sign = ix & 0x8000;
  ix &= 0x7fff;
  lsw |= msw & IC(0x7fffffff);
  if (ix >= 0x7fff) {
    /* Infinity. */
    if (lsw == 0) {
      if (sign)
        return -1.0L;
      else
        return x;
    }
    /* NaN. No invalid exception. */
    return x;
  }

  /* expm1(+- 0) = +- 0.  */
  if (ix == 0 && lsw == 0)
    return x;

  /* Overflow.  */
  if (x > maxlog) {
    feraiseexcept(FE_OVERFLOW);
    return HUGE_VALL;
    long double temp_var_for_tac_8;
    computeLdSub((Addr)&temp_var_for_tac_8,
                 {(Addr) &(temp_var_for_const_17 = 0.0),
                  (Addr) &(temp_var_for_const_16 =
                               7.9018778583833765273564461846232128760607E1L)},
                 "toString(biExpr->getExprLoc())");
  }

  /* Minimum value.  */
  if (x < minarg) {
    long double temp_var_for_ext_0;
    temp_var_for_ext_0 = (4.0 / big - 1.0L);
    long double temp_var_for_const_18, temp_var_for_const_19,
        temp_var_for_const_20;
    long double temp_var_for_tac_9;
    computeLdDiv((Addr)&temp_var_for_tac_9,
                 {(Addr) &(temp_var_for_const_19 = 4.0),
                  (Addr) &(temp_var_for_const_18 = big)},
                 "/home/shijia/Public/testprogram/s_expm1l.c_e.c:138:37");
    computeLdSub(
        (Addr)&temp_var_for_ext_0,
        {(Addr)&temp_var_for_tac_9, (Addr) &(temp_var_for_const_20 = 1.0L)},
        "/home/shijia/Public/testprogram/s_expm1l.c_e.c:138:24");
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  /* Express x = ln 2 (k + remainder), remainder not exceeding 1/2. */
  xx = C1 + C2;
  long double temp_var_for_const_21, temp_var_for_const_22;
  computeLdAdd(
      (Addr)&xx, {(Addr) &(temp_var_for_const_22 = C1),
                  (Addr) &(temp_var_for_const_21 = C2)},
      "/home/shijia/Public/testprogram/s_expm1l.c_e.c:145:6"); /* ln 2. */
  px = __ieee754_floorl(0.5L + x / xx);
  long double temp_var_for_const_23, temp_var_for_const_24;
  long double temp_var_for_tac_10, temp_var_for_tac_11;
  computeLdAdd(
      (Addr)&temp_var_for_tac_11,
      {(Addr) &(temp_var_for_const_23 = 0.5L), (Addr)&temp_var_for_tac_10},
      "toString(biExpr->getExprLoc())");
  computeLdDiv((Addr)&temp_var_for_tac_10, {(Addr)&x, (Addr)&xx},
               "/home/shijia/Public/testprogram/s_expm1l.c_e.c:146:30");AssignLd({(Addr)&px},(Addr)&(temp_var_for_const_24=__ieee754_floorl(getFVbyShadow<int>((Addr)&temp_var_for_tac_11)),"/home/shijia/Public/testprogram/s_expm1l.c_e.c:146:6");
  k = px;
  /* remainder times ln 2 */
  x -= px * C1;long double temp_var_for_const_25;
  x -= px * C2;long double temp_var_for_const_26;long double temp_var_for_tac_12;computeLdMul((Addr)&temp_var_for_tac_12,{(Addr)&px,(Addr)&(temp_var_for_const_25=C1)},"/home/shijia/Public/testprogram/s_expm1l.c_e.c:150:11");

  /* Approximate exp(remainder ln 2).  */
  long double temp_var_for_ext_1;
  temp_var_for_ext_1 =
      (((((((P7 * x + P6) * x + P5) * x + P4) * x + P3) * x + P2) * x + P1) *
           x +
       P0) *
      x;long double temp_var_for_const_27,temp_var_for_const_28,temp_var_for_const_29,temp_var_for_const_30,temp_var_for_const_31,temp_var_for_const_32,temp_var_for_const_33,temp_var_for_const_34;long double temp_var_for_tac_13,temp_var_for_tac_14,temp_var_for_tac_15,temp_var_for_tac_16,temp_var_for_tac_17,temp_var_for_tac_18,temp_var_for_tac_19,temp_var_for_tac_20,temp_var_for_tac_21,temp_var_for_tac_22,temp_var_for_tac_23,temp_var_for_tac_24,temp_var_for_tac_25,temp_var_for_tac_26,temp_var_for_tac_27;computeLdMul((Addr)&temp_var_for_tac_13,{(Addr)&px,(Addr)&(temp_var_for_const_26=C2)},"/home/shijia/Public/testprogram/s_expm1l.c_e.c:155:17");computeLdMul((Addr)&temp_var_for_tac_14,{(Addr)&(temp_var_for_const_27=P7),(Addr)&x},"/home/shijia/Public/testprogram/s_expm1l.c_e.c:155:21");computeLdAdd((Addr)&temp_var_for_tac_15,{(Addr)&temp_var_for_tac_14,(Addr)&(temp_var_for_const_28=P6)},"/home/shijia/Public/testprogram/s_expm1l.c_e.c:155:27");computeLdMul((Addr)&temp_var_for_tac_16,{(Addr)&temp_var_for_tac_15,(Addr)&x},"/home/shijia/Public/testprogram/s_expm1l.c_e.c:155:31");computeLdAdd((Addr)&temp_var_for_tac_17,{(Addr)&temp_var_for_tac_16,(Addr)&(temp_var_for_const_29=P5)},"/home/shijia/Public/testprogram/s_expm1l.c_e.c:155:37");computeLdMul((Addr)&temp_var_for_tac_18,{(Addr)&temp_var_for_tac_17,(Addr)&x},"/home/shijia/Public/testprogram/s_expm1l.c_e.c:155:41");computeLdAdd((Addr)&temp_var_for_tac_19,{(Addr)&temp_var_for_tac_18,(Addr)&(temp_var_for_const_30=P4)},"/home/shijia/Public/testprogram/s_expm1l.c_e.c:155:47");computeLdMul((Addr)&temp_var_for_tac_20,{(Addr)&temp_var_for_tac_19,(Addr)&x},"/home/shijia/Public/testprogram/s_expm1l.c_e.c:155:51");computeLdAdd((Addr)&temp_var_for_tac_21,{(Addr)&temp_var_for_tac_20,(Addr)&(temp_var_for_const_31=P3)},"/home/shijia/Public/testprogram/s_expm1l.c_e.c:155:57");computeLdMul((Addr)&temp_var_for_tac_22,{(Addr)&temp_var_for_tac_21,(Addr)&x},"/home/shijia/Public/testprogram/s_expm1l.c_e.c:155:61");computeLdAdd((Addr)&temp_var_for_tac_23,{(Addr)&temp_var_for_tac_22,(Addr)&(temp_var_for_const_32=P2)},"/home/shijia/Public/testprogram/s_expm1l.c_e.c:155:67");computeLdMul((Addr)&temp_var_for_tac_24,{(Addr)&temp_var_for_tac_23,(Addr)&x},"/home/shijia/Public/testprogram/s_expm1l.c_e.c:155:71");computeLdAdd((Addr)&temp_var_for_tac_25,{(Addr)&temp_var_for_tac_24,(Addr)&(temp_var_for_const_33=P1)},"/home/shijia/Public/testprogram/s_expm1l.c_e.c:155:77");computeLdMul((Addr)&temp_var_for_tac_26,{(Addr)&temp_var_for_tac_25,(Addr)&x},"/home/shijia/Public/testprogram/s_expm1l.c_e.c:156:14");computeLdAdd((Addr)&temp_var_for_tac_27,{(Addr)&temp_var_for_tac_26,(Addr)&(temp_var_for_const_34=P0)},"/home/shijia/Public/testprogram/s_expm1l.c_e.c:157:12");computeLdMul((Addr)&temp_var_for_ext_1,{(Addr)&temp_var_for_tac_27,(Addr)&x},"/home/shijia/Public/testprogram/s_expm1l.c_e.c:154:22"); // px
  /*(xx)(x)(0.5L)(xx)(x)(C1)(px)(x)(C1)(px)(C2)(px)(x)(C2)(px)(x)(P0)(x)(P1)(x)(P2)(x)(P3)(x)(P4)(x)(P5)(x)(P6)(x)(P7)*/
  px = temp_var_for_ext_1;AssignLd({(Addr)&px},(Addr)&temp_var_for_ext_1,"/home/shijia/Public/testprogram/s_expm1l.c_e.c:160:6");

  qx = (((((((x + Q7) * x + Q6) * x + Q5) * x + Q4) * x + Q3) * x + Q2) * x +
        Q1) *
           x +
       Q0;long double temp_var_for_const_35,temp_var_for_const_36,temp_var_for_const_37,temp_var_for_const_38,temp_var_for_const_39,temp_var_for_const_40,temp_var_for_const_41,temp_var_for_const_42;long double temp_var_for_tac_28,temp_var_for_tac_29,temp_var_for_tac_30,temp_var_for_tac_31,temp_var_for_tac_32,temp_var_for_tac_33,temp_var_for_tac_34,temp_var_for_tac_35,temp_var_for_tac_36,temp_var_for_tac_37,temp_var_for_tac_38,temp_var_for_tac_39,temp_var_for_tac_40,temp_var_for_tac_41;computeLdAdd((Addr)&temp_var_for_tac_28,{(Addr)&x,(Addr)&(temp_var_for_const_35=Q7)},"/home/shijia/Public/testprogram/s_expm1l.c_e.c:162:23");computeLdMul((Addr)&temp_var_for_tac_29,{(Addr)&temp_var_for_tac_28,(Addr)&x},"/home/shijia/Public/testprogram/s_expm1l.c_e.c:162:27");computeLdAdd((Addr)&temp_var_for_tac_30,{(Addr)&temp_var_for_tac_29,(Addr)&(temp_var_for_const_36=Q6)},"/home/shijia/Public/testprogram/s_expm1l.c_e.c:162:33");computeLdMul((Addr)&temp_var_for_tac_31,{(Addr)&temp_var_for_tac_30,(Addr)&x},"/home/shijia/Public/testprogram/s_expm1l.c_e.c:162:37");computeLdAdd((Addr)&temp_var_for_tac_32,{(Addr)&temp_var_for_tac_31,(Addr)&(temp_var_for_const_37=Q5)},"/home/shijia/Public/testprogram/s_expm1l.c_e.c:162:43");computeLdMul((Addr)&temp_var_for_tac_33,{(Addr)&temp_var_for_tac_32,(Addr)&x},"/home/shijia/Public/testprogram/s_expm1l.c_e.c:162:47");computeLdAdd((Addr)&temp_var_for_tac_34,{(Addr)&temp_var_for_tac_33,(Addr)&(temp_var_for_const_38=Q4)},"/home/shijia/Public/testprogram/s_expm1l.c_e.c:162:53");computeLdMul((Addr)&temp_var_for_tac_35,{(Addr)&temp_var_for_tac_34,(Addr)&x},"/home/shijia/Public/testprogram/s_expm1l.c_e.c:162:57");computeLdAdd((Addr)&temp_var_for_tac_36,{(Addr)&temp_var_for_tac_35,(Addr)&(temp_var_for_const_39=Q3)},"/home/shijia/Public/testprogram/s_expm1l.c_e.c:162:63");computeLdMul((Addr)&temp_var_for_tac_37,{(Addr)&temp_var_for_tac_36,(Addr)&x},"/home/shijia/Public/testprogram/s_expm1l.c_e.c:162:67");computeLdAdd((Addr)&temp_var_for_tac_38,{(Addr)&temp_var_for_tac_37,(Addr)&(temp_var_for_const_40=Q2)},"/home/shijia/Public/testprogram/s_expm1l.c_e.c:162:73");computeLdMul((Addr)&temp_var_for_tac_39,{(Addr)&temp_var_for_tac_38,(Addr)&x},"/home/shijia/Public/testprogram/s_expm1l.c_e.c:162:77");computeLdAdd((Addr)&temp_var_for_tac_40,{(Addr)&temp_var_for_tac_39,(Addr)&(temp_var_for_const_41=Q1)},"/home/shijia/Public/testprogram/s_expm1l.c_e.c:163:13");computeLdMul((Addr)&temp_var_for_tac_41,{(Addr)&temp_var_for_tac_40,(Addr)&x},"/home/shijia/Public/testprogram/s_expm1l.c_e.c:164:14");computeLdAdd((Addr)&qx,{(Addr)&temp_var_for_tac_41,(Addr)&(temp_var_for_const_42=Q0)},"/home/shijia/Public/testprogram/s_expm1l.c_e.c:162:6");

  xx = x * x;computeLdMul((Addr)&xx,{(Addr)&x,(Addr)&x},"/home/shijia/Public/testprogram/s_expm1l.c_e.c:167:6");
  long double temp_var_for_ext_2;
  temp_var_for_ext_2 = x + (0.5 * xx + xx * px / qx);long double temp_var_for_const_43;long double temp_var_for_tac_42,temp_var_for_tac_43,temp_var_for_tac_44;computeLdMul((Addr)&temp_var_for_tac_42,{(Addr)&(temp_var_for_const_43=0.5),(Addr)&xx},"/home/shijia/Public/testprogram/s_expm1l.c_e.c:169:43");computeLdMul((Addr)&temp_var_for_tac_43,{(Addr)&xx,(Addr)&px},"/home/shijia/Public/testprogram/s_expm1l.c_e.c:169:48");computeLdDiv((Addr)&temp_var_for_tac_44,{(Addr)&temp_var_for_tac_43,(Addr)&qx},"/home/shijia/Public/testprogram/s_expm1l.c_e.c:169:38");computeLdAdd((Addr)&temp_var_for_ext_2,{(Addr)&temp_var_for_tac_42,(Addr)&temp_var_for_tac_44,(Addr)&x},"/home/shijia/Public/testprogram/s_expm1l.c_e.c:169:22"); // qx
  /*(x)(x)(qx)(px)(xx)(xx)(0.5)(x)*/
  qx = temp_var_for_ext_2;AssignLd({(Addr)&qx},(Addr)&temp_var_for_ext_2,"/home/shijia/Public/testprogram/s_expm1l.c_e.c:171:6");

  /* exp(x) = exp(k ln 2) exp(remainder ln 2) = 2^k exp(remainder ln 2).

     We have qx = exp(remainder ln 2) - 1, so
     exp(x) - 1 = 2^k (qx + 1) - 1
     = 2^k qx + 2^k - 1.  */
  if (k == 16384) {
    px = __ieee754_ldexpl(1.0L, (int)k - 2);
    x = (px * qx + (px - 0.25L)) * 4.0L;
  } else {
    px = __ieee754_ldexpl(1.0L, (int)k);
    x = px * qx + (px - 1.0L);
  }
  long double temp_var_for_ext_3;
  temp_var_for_ext_3 = x;AssignLd({(Addr)&temp_var_for_ext_3},(Addr)&x,"/home/shijia/Public/testprogram/s_expm1l.c_e.c:186:22");
  callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_3;
}

#endif

long double __expm1l(long double x) {
  long double z = __ieee754_expm1l(x);

  if ((!isfinite(z) || z == -1.0L) && isfinite(x) && _LIB_VERSION != _IEEE_)
    return __kernel_standard_l(x, x, z, signbit(x) ? KMATHERRL_EXPM1_UNDERFLOW
                                                   : KMATHERRL_EXPM1_OVERFLOW);

  long double temp_var_for_ext_4;
  temp_var_for_ext_4 = z;
  AssignLd({(Addr)&temp_var_for_ext_4}, (Addr)&z,
           "/home/shijia/Public/testprogram/s_expm1l.c_e.c:202:22");
  callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_4;
}

__typeof(__expm1l) expm1l __attribute__((weak, alias("__expm1l")));

#endif
