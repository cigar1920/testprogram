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

/* __ieee754_y0(x)
 * Bessel function of the second kind of order zero.
 * Method -- y0(x):
 *	1. For x<2.
 *	   Since
 *		y0(x) = 2/pi*(j0(x)*(ln(x/2)+Euler) + x^2/4 - ...)
 *	   therefore y0(x)-2/pi*j0(x)*ln(x) is an even function.
 *	   We use the following function to approximate y0,
 *		y0(x) = U(z)/V(z) + (2/pi)*(j0(x)*ln(x)), z= x^2
 *
 *	   Note: For tiny x, U/V = u0 and j0(x)~1, hence
 *		y0(tiny) = u0 + (2/pi)*ln(tiny), (choose tiny<2**-27)
 *	2. For x>=2.
 *		y0(x) = sqrt(2/(pi*x))*(p0(x)*cos(x0)+q0(x)*sin(x0))
 *	   where x0 = x-pi/4. It is better to compute sin(x0),cos(x0)
 *	   by the method mentioned above.
 *	3. Special cases: y0(0)=-inf, y0(x<0)=NaN, y0(inf)=0.
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

long double __ieee754_y0l(long double x) {
  long double z, s, c, ss, cc, u, v;
  int32_t ix;
  uint32_t se, i0, i1;

  static const long double one = 1.0L;
  static const long double invsqrtpi =
      5.6418958354775628694807945156077258584405e-1L;
  static const long double tpi = 6.3661977236758134307553505349005744813784e-1L;
  static const long double zero = 0.0;

  /* y0(x) = 2/pi ln(x) J0(x) + U(x^2)/V(x^2)
     0 < x <= 2
     peak relative error 1.7e-21 */
  static const long double U[6] = {
      (long double temp_var_for_tac_0;
  long double temp_var_for_const_0, temp_var_for_const_1;
  temp_var_for_tac_0 = 0.0 - 1.054912306975785573710813351985351350861E10L;

),
      2.520192609749295139432773849576523636127E10L,
      (long double temp_var_for_tac_1;long double temp_var_for_const_2,temp_var_for_const_3;temp_var_for_tac_1 = 0.0 - 1.856426071075602001239955451329519093395E9L;

),
      4.079209129698891442683267466276785956784E7L,
      (long double temp_var_for_tac_2;long double temp_var_for_const_4,temp_var_for_const_5;temp_var_for_tac_2 = 0.0 - 3.440684087134286610316661166492641011539E5L;

),
      1.005524356159130626192144663414848383774E3L,
};

static const long double V[5] = {
    1.429337283720789610137291929228082613676E11L,
    2.492593075325119157558811370165695013002E9L,
    2.186077620785925464237324417623665138376E7L,
    1.238407896366385175196515057064384929222E5L,
    4.693924035211032457494368947123233101664E2L,
    /*  1.000000000000000000000000000000000000000E0L */
};

long double temp_var_for_const_6;
ew_u.value = x;
computeLdSub((Addr)&temp_var_for_tac_0,
             {(Addr) &(temp_var_for_const_1 = 0.0),
              (Addr) &(temp_var_for_const_0 =
                           1.054912306975785573710813351985351350861E10L)},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:73:12");
computeLdSub((Addr)&temp_var_for_tac_1,
             {(Addr) &(temp_var_for_const_3 = 0.0),
              (Addr) &(temp_var_for_const_2 =
                           1.856426071075602001239955451329519093395E9L)},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:75:12");
computeLdSub((Addr)&temp_var_for_tac_2,
             {(Addr) &(temp_var_for_const_5 = 0.0),
              (Addr) &(temp_var_for_const_4 =
                           3.440684087134286610316661166492641011539E5L)},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:77:12");
AssignLd({(Addr) &(temp_var_for_const_6 = ew_u.value)}, (Addr)&x,
         "/home/shijia/Public/testprogram/e_y0l.c_e.c:90:3 "
         "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
;
ix = se & IEEE854_LONG_DOUBLE_MAXEXP;
/* Y0(NaN) is NaN, y0(-inf) is Nan, y0(inf) is 0  */
if (se & 0x8000) {
  long double temp_var_for_ext_0;
  long double temp_var_for_tac_3, temp_var_for_tac_4;
  long double temp_var_for_const_7, temp_var_for_const_8;
  temp_var_for_tac_3 = zero * x;

  temp_var_for_tac_4 = zero / temp_var_for_tac_3;

  temp_var_for_ext_0 = temp_var_for_tac_4;
  computeLdMul((Addr)&temp_var_for_tac_3,
               {(Addr) &(temp_var_for_const_7 = zero), (Addr)&x},
               "/home/shijia/Public/testprogram/e_y0l.c_e.c:95:39");
  computeLdDiv(
      (Addr)&temp_var_for_tac_4,
      {(Addr) &(temp_var_for_const_8 = zero), (Addr)&temp_var_for_tac_3},
      "/home/shijia/Public/testprogram/e_y0l.c_e.c:95:31");
  AssignLd({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_4,
           "/home/shijia/Public/testprogram/e_y0l.c_e.c:95:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

if (ix >= IEEE854_LONG_DOUBLE_MAXEXP) {
  long double temp_var_for_ext_1;
  long double temp_var_for_tac_5, temp_var_for_tac_6, temp_var_for_tac_7;
  long double temp_var_for_const_9;
  temp_var_for_tac_5 = x * x;

  temp_var_for_tac_6 = x + temp_var_for_tac_5;

  temp_var_for_tac_7 = one / temp_var_for_tac_6;

  temp_var_for_ext_1 = temp_var_for_tac_7;
  computeLdMul((Addr)&temp_var_for_tac_5, {(Addr)&x, (Addr)&x},
               "/home/shijia/Public/testprogram/e_y0l.c_e.c:103:39");
  computeLdAdd((Addr)&temp_var_for_tac_6, {(Addr)&x, (Addr)&temp_var_for_tac_5},
               "/home/shijia/Public/testprogram/e_y0l.c_e.c:103:35");
  computeLdDiv((Addr)&temp_var_for_tac_7, {(Addr) &(temp_var_for_const_9 = one),
                                           (Addr)&temp_var_for_tac_6},
               "/home/shijia/Public/testprogram/e_y0l.c_e.c:103:30");
  AssignLd({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_7,
           "/home/shijia/Public/testprogram/e_y0l.c_e.c:103:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

if ((i0 | i1) == 0) {
  long double temp_var_for_ext_2;
  long double temp_var_for_tac_8;
  long double temp_var_for_const_10;
  temp_var_for_callexp_0 = __builtin_huge_vall();
  temp_var_for_tac_8 = (-(temp_var_for_callexp_0)) + x;

  temp_var_for_ext_2 = temp_var_for_tac_8;
  computeLdAdd(
      (Addr)&temp_var_for_tac_8,
      {(Addr) &(temp_var_for_const_10 = (-(temp_var_for_callexp_0))), (Addr)&x},
      "/home/shijia/Public/testprogram/e_y0l.c_e.c:111:37");
  AssignLd({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_8,
           "/home/shijia/Public/testprogram/e_y0l.c_e.c:111:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
  callExp++; /*identify the function is  add move tmpShadow*/
  return (0.0 - var_for_e)xt_2;
}
/* -inf and overflow exception.  */
if (ix >= 0x4000) { /* |x| >= 2.0 */

  /* y0(x) = sqrt(2/(pi*x))*(p0(x)*sin(x0)+q0(x)*cos(x0))
   * where x0 = x-pi/4
   *      Better formula:
   *              cos(x0) = cos(x)cos(pi/4)+sin(x)sin(pi/4)
   *                      =  1/sqrt(2) * (sin(x) + cos(x))
   *              sin(x0) = sin(x)cos(3pi/4)-cos(x)sin(3pi/4)
   *                      =  1/sqrt(2) * (sin(x) - cos(x))
   * To avoid cancellation, use
   *              sin(x) +- cos(x) = -cos(2x)/(sin(x) -+ cos(x))
   * to compute the worse one.
   */
  __ieee754_sincosl(x, &s, &c);
  long double temp_var_for_tac_9;
  temp_var_for_tac_9 = s - c;

  ss = temp_var_for_tac_9;
  computeLdSub((Addr)&temp_var_for_tac_9, {(Addr)&s, (Addr)&c},
               "/home/shijia/Public/testprogram/e_y0l.c_e.c:131:12");
  AssignLd({(Addr)&ss}, (Addr)&temp_var_for_tac_9,
           "/home/shijia/Public/testprogram/e_y0l.c_e.c:131:8");
  ;
  long double temp_var_for_tac_10;
  temp_var_for_tac_10 = s + c;

  cc = temp_var_for_tac_10;
  computeLdAdd((Addr)&temp_var_for_tac_10, {(Addr)&s, (Addr)&c},
               "/home/shijia/Public/testprogram/e_y0l.c_e.c:132:12");
  AssignLd({(Addr)&cc}, (Addr)&temp_var_for_tac_10,
           "/home/shijia/Public/testprogram/e_y0l.c_e.c:132:8");
  ;
  /*
   * j0(x) = 1/sqrt(pi) * (P(0,x)*cc - Q(0,x)*ss) / sqrt(x)
   * y0(x) = 1/sqrt(pi) * (P(0,x)*ss + Q(0,x)*cc) / sqrt(x)
   */
  if (ix < 0x7ffe) { /* make sure x+x not overflow */
    long double temp_var_for_tac_11, temp_var_for_tac_12;
    long double temp_var_for_const_11, temp_var_for_const_12;
    long double temp_var_for_callexp_1;

    temp_var_for_tac_11 = x + x;

    temp_var_for_callexp_1 = __ieee754_cosl(temp_var_for_tac_11);
    temp_var_for_tac_12 = 0.0 - temp_var_for_callexp_1;

    z = temp_var_for_tac_12;
    computeLdAdd((Addr)&temp_var_for_tac_11, {(Addr)&x, (Addr)&x},
                 "/home/shijia/Public/testprogram/e_y0l.c_e.c:138:35");
    computeLdSub((Addr)&temp_var_for_tac_12,
                 {(Addr) &(temp_var_for_const_12 = 0.0),
                  (Addr) &(temp_var_for_const_11 = temp_var_for_callexp_1)},
                 "/home/shijia/Public/testprogram/e_y0l.c_e.c:138:16");
    AssignLd({(Addr)&z}, (Addr)&temp_var_for_tac_12,
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:138:9");
    ;
    if (int temp_var_for_tac_13, temp_var_for_tac_14; int temp_var_for_const_13;
        temp_var_for_tac_13 = s * c;

        temp_var_for_tac_14 = temp_var_for_tac_13 < zero;

        ) {
      long double temp_var_for_tac_15;
      temp_var_for_tac_15 = z / ss;

      cc = temp_var_for_tac_15;
      computeLdMul((Addr)&temp_var_for_tac_13, {(Addr)&s, (Addr)&c},
                   "/home/shijia/Public/testprogram/e_y0l.c_e.c:139:14");
      compute(
          (Addr)&temp_var_for_tac_14,
          {(Addr)&temp_var_for_tac_13, (Addr) &(temp_var_for_const_13 = zero)},
          "/home/shijia/Public/testprogram/e_y0l.c_e.c:139:19");
      computeLdDiv((Addr)&temp_var_for_tac_15, {(Addr)&z, (Addr)&ss},
                   "/home/shijia/Public/testprogram/e_y0l.c_e.c:140:16");
      AssignLd({(Addr)&cc}, (Addr)&temp_var_for_tac_15,
               "/home/shijia/Public/testprogram/e_y0l.c_e.c:140:12");
      ;
    }

    else {
      long double temp_var_for_ext_3;
      long double temp_var_for_tac_16;
      temp_var_for_tac_16 = z / cc;

      temp_var_for_ext_3 = temp_var_for_tac_16;
      computeLdDiv((Addr)&temp_var_for_tac_16, {(Addr)&z, (Addr)&cc},
                   "/home/shijia/Public/testprogram/e_y0l.c_e.c:145:32");
      AssignLd({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_16,
               "/home/shijia/Public/testprogram/e_y0l.c_e.c:145:28");
      ; // ss
      /*(ss)(z)(cc)(z)*/
      ss = temp_var_for_ext_3;
      AssignLd({(Addr)&ss}, (Addr)&temp_var_for_ext_3,
               "/home/shijia/Public/testprogram/e_y0l.c_e.c:147:12");
      ;
    }
  }
  if (ix > 0x4080) /* 1e39 */
  {
    long double temp_var_for_ext_4;
    long double temp_var_for_tac_17, temp_var_for_tac_18;
    long double temp_var_for_const_14, temp_var_for_const_15;
    long double temp_var_for_callexp_2;

    temp_var_for_tac_17 = invsqrtpi * ss;

    temp_var_for_callexp_2 = __ieee754_sqrtl(x);
    temp_var_for_tac_18 = temp_var_for_tac_17 / temp_var_for_callexp_2;

    temp_var_for_ext_4 = temp_var_for_tac_18;
    computeLdMul((Addr)&temp_var_for_tac_17,
                 {(Addr) &(temp_var_for_const_14 = invsqrtpi), (Addr)&ss},
                 "/home/shijia/Public/testprogram/e_y0l.c_e.c:153:39");
    computeLdDiv((Addr)&temp_var_for_tac_18,
                 {(Addr)&temp_var_for_tac_17,
                  (Addr) &(temp_var_for_const_15 = temp_var_for_callexp_2)},
                 "/home/shijia/Public/testprogram/e_y0l.c_e.c:153:45");
    AssignLd({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_18,
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:153:26");
    ; // z
    /*(cc)(z)(__ieee754_sqrtl(x))(ss)(invsqrtpi)*/
    z = temp_var_for_ext_4;
    AssignLd({(Addr)&z}, (Addr)&temp_var_for_ext_4,
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:155:9");
    ;
  }

  else {
    long double temp_var_for_const_16;
    long double temp_var_for_callexp_3;

    temp_var_for_callexp_3 = __j0_y0_pzerol(x);
    u = temp_var_for_callexp_3;
    AssignLd({(Addr)&u},
             (Addr) &(temp_var_for_const_16 = temp_var_for_callexp_3),
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:159:9");
    ;
    long double temp_var_for_const_17;
    long double temp_var_for_callexp_4;

    temp_var_for_callexp_4 = __j0_y0_qzerol(x);
    v = temp_var_for_callexp_4;
    AssignLd({(Addr)&v},
             (Addr) &(temp_var_for_const_17 = temp_var_for_callexp_4),
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:160:9");
    ;
    long double temp_var_for_tac_19, temp_var_for_tac_20, temp_var_for_tac_21,
        temp_var_for_tac_22, temp_var_for_tac_23;
    long double temp_var_for_const_18, temp_var_for_const_19;
    long double temp_var_for_callexp_5;

    temp_var_for_tac_19 = u * ss;

    temp_var_for_tac_20 = v * cc;

    temp_var_for_tac_21 = temp_var_for_tac_19 + temp_var_for_tac_20;

    temp_var_for_tac_22 = invsqrtpi * temp_var_for_tac_21;

    temp_var_for_callexp_5 = __ieee754_sqrtl(x);
    temp_var_for_tac_23 = temp_var_for_tac_22 / temp_var_for_callexp_5;

    z = temp_var_for_tac_23;
    computeLdMul((Addr)&temp_var_for_tac_19, {(Addr)&u, (Addr)&ss},
                 "/home/shijia/Public/testprogram/e_y0l.c_e.c:161:26");
    computeLdMul((Addr)&temp_var_for_tac_20, {(Addr)&v, (Addr)&cc},
                 "/home/shijia/Public/testprogram/e_y0l.c_e.c:161:35");
    computeLdAdd((Addr)&temp_var_for_tac_21,
                 {(Addr)&temp_var_for_tac_19, (Addr)&temp_var_for_tac_20},
                 "/home/shijia/Public/testprogram/e_y0l.c_e.c:161:31");
    computeLdMul((Addr)&temp_var_for_tac_22,
                 {(Addr) &(temp_var_for_const_18 = invsqrtpi),
                  (Addr)&temp_var_for_tac_21},
                 "/home/shijia/Public/testprogram/e_y0l.c_e.c:161:21");
    computeLdDiv((Addr)&temp_var_for_tac_23,
                 {(Addr)&temp_var_for_tac_22,
                  (Addr) &(temp_var_for_const_19 = temp_var_for_callexp_5)},
                 "/home/shijia/Public/testprogram/e_y0l.c_e.c:161:41");
    AssignLd({(Addr)&z}, (Addr)&temp_var_for_tac_23,
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:161:9");
    ;
  }
  long double temp_var_for_ext_5;
  temp_var_for_ext_5 = z;
  AssignLd({(Addr)&temp_var_for_ext_5}, (Addr)&z,
           "/home/shijia/Public/testprogram/e_y0l.c_e.c:164:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_5;
}
if (ix <= 0x3fde) /* x < 2^-33 */
{
  long double temp_var_for_tac_24, temp_var_for_tac_25, temp_var_for_tac_26;
  long double temp_var_for_const_20, temp_var_for_const_21,
      temp_var_for_const_22, temp_var_for_const_23;
  long double temp_var_for_callexp_6;

  temp_var_for_tac_24 = 0.0 - 7.380429510868722527629822444004602747322E-2L;

  temp_var_for_callexp_6 = __ieee754_logl(x);
  temp_var_for_tac_25 = tpi * temp_var_for_callexp_6;

  temp_var_for_tac_26 = temp_var_for_tac_24 + temp_var_for_tac_25;

  z = temp_var_for_tac_26;
  computeLdSub((Addr)&temp_var_for_tac_24,
               {(Addr) &(temp_var_for_const_21 = 0.0),
                (Addr) &(temp_var_for_const_20 =
                             7.380429510868722527629822444004602747322E-2L)},
               "/home/shijia/Public/testprogram/e_y0l.c_e.c:171:14");
  computeLdMul((Addr)&temp_var_for_tac_25,
               {(Addr) &(temp_var_for_const_23 = tpi),
                (Addr) &(temp_var_for_const_22 = temp_var_for_callexp_6)},
               "/home/shijia/Public/testprogram/e_y0l.c_e.c:172:13");
  computeLdAdd((Addr)&temp_var_for_tac_26,
               {(Addr)&temp_var_for_tac_24, (Addr)&temp_var_for_tac_25},
               "/home/shijia/Public/testprogram/e_y0l.c_e.c:171:63");
  AssignLd({(Addr)&z}, (Addr)&temp_var_for_tac_26,
           "/home/shijia/Public/testprogram/e_y0l.c_e.c:171:7");
  ;
  long double temp_var_for_ext_6;
  temp_var_for_ext_6 = z;
  AssignLd({(Addr)&temp_var_for_ext_6}, (Addr)&z,
           "/home/shijia/Public/testprogram/e_y0l.c_e.c:174:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_6;
}
long double temp_var_for_tac_27;
temp_var_for_tac_27 = x * x;

z = temp_var_for_tac_27;
computeLdMul((Addr)&temp_var_for_tac_27, {(Addr)&x, (Addr)&x},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:179:9");
AssignLd({(Addr)&z}, (Addr)&temp_var_for_tac_27,
         "/home/shijia/Public/testprogram/e_y0l.c_e.c:179:5");
;
long double temp_var_for_tac_28, temp_var_for_tac_29, temp_var_for_tac_30,
    temp_var_for_tac_31, temp_var_for_tac_32, temp_var_for_tac_33,
    temp_var_for_tac_34, temp_var_for_tac_35, temp_var_for_tac_36,
    temp_var_for_tac_37;
long double temp_var_for_const_24, temp_var_for_const_25, temp_var_for_const_26,
    temp_var_for_const_27, temp_var_for_const_28, temp_var_for_const_29;
temp_var_for_tac_28 = z * U[5];

temp_var_for_tac_29 = U[4] + temp_var_for_tac_28;

temp_var_for_tac_30 = z * temp_var_for_tac_29;

temp_var_for_tac_31 = U[3] + temp_var_for_tac_30;

temp_var_for_tac_32 = z * temp_var_for_tac_31;

temp_var_for_tac_33 = U[2] + temp_var_for_tac_32;

temp_var_for_tac_34 = z * temp_var_for_tac_33;

temp_var_for_tac_35 = U[1] + temp_var_for_tac_34;

temp_var_for_tac_36 = z * temp_var_for_tac_35;

temp_var_for_tac_37 = U[0] + temp_var_for_tac_36;

u = temp_var_for_tac_37;
computeLdMul((Addr)&temp_var_for_tac_28,
             {(Addr)&z, (Addr) &(temp_var_for_const_24 = U[5])},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:180:64");
computeLdAdd((Addr)&temp_var_for_tac_29,
             {(Addr) &(temp_var_for_const_25 = U[4]),
              (Addr)&temp_var_for_tac_28},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:180:60");
computeLdMul((Addr)&temp_var_for_tac_30, {(Addr)&z, (Addr)&temp_var_for_tac_29},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:180:52");
computeLdAdd((Addr)&temp_var_for_tac_31,
             {(Addr) &(temp_var_for_const_26 = U[3]),
              (Addr)&temp_var_for_tac_30},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:180:48");
computeLdMul((Addr)&temp_var_for_tac_32, {(Addr)&z, (Addr)&temp_var_for_tac_31},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:180:40");
computeLdAdd((Addr)&temp_var_for_tac_33,
             {(Addr) &(temp_var_for_const_27 = U[2]),
              (Addr)&temp_var_for_tac_32},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:180:36");
computeLdMul((Addr)&temp_var_for_tac_34, {(Addr)&z, (Addr)&temp_var_for_tac_33},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:180:28");
computeLdAdd((Addr)&temp_var_for_tac_35,
             {(Addr) &(temp_var_for_const_28 = U[1]),
              (Addr)&temp_var_for_tac_34},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:180:24");
computeLdMul((Addr)&temp_var_for_tac_36, {(Addr)&z, (Addr)&temp_var_for_tac_35},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:180:16");
computeLdAdd((Addr)&temp_var_for_tac_37,
             {(Addr) &(temp_var_for_const_29 = U[0]),
              (Addr)&temp_var_for_tac_36},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:180:12");
AssignLd({(Addr)&u}, (Addr)&temp_var_for_tac_37,
         "/home/shijia/Public/testprogram/e_y0l.c_e.c:180:5");
;
long double temp_var_for_tac_38, temp_var_for_tac_39, temp_var_for_tac_40,
    temp_var_for_tac_41, temp_var_for_tac_42, temp_var_for_tac_43,
    temp_var_for_tac_44, temp_var_for_tac_45, temp_var_for_tac_46;
long double temp_var_for_const_30, temp_var_for_const_31, temp_var_for_const_32,
    temp_var_for_const_33, temp_var_for_const_34;
temp_var_for_tac_38 = V[4] + z;

temp_var_for_tac_39 = z * temp_var_for_tac_38;

temp_var_for_tac_40 = V[3] + temp_var_for_tac_39;

temp_var_for_tac_41 = z * temp_var_for_tac_40;

temp_var_for_tac_42 = V[2] + temp_var_for_tac_41;

temp_var_for_tac_43 = z * temp_var_for_tac_42;

temp_var_for_tac_44 = V[1] + temp_var_for_tac_43;

temp_var_for_tac_45 = z * temp_var_for_tac_44;

temp_var_for_tac_46 = V[0] + temp_var_for_tac_45;

v = temp_var_for_tac_46;
computeLdAdd((Addr)&temp_var_for_tac_38,
             {(Addr) &(temp_var_for_const_30 = V[4]), (Addr)&z},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:181:60");
computeLdMul((Addr)&temp_var_for_tac_39, {(Addr)&z, (Addr)&temp_var_for_tac_38},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:181:52");
computeLdAdd((Addr)&temp_var_for_tac_40,
             {(Addr) &(temp_var_for_const_31 = V[3]),
              (Addr)&temp_var_for_tac_39},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:181:48");
computeLdMul((Addr)&temp_var_for_tac_41, {(Addr)&z, (Addr)&temp_var_for_tac_40},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:181:40");
computeLdAdd((Addr)&temp_var_for_tac_42,
             {(Addr) &(temp_var_for_const_32 = V[2]),
              (Addr)&temp_var_for_tac_41},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:181:36");
computeLdMul((Addr)&temp_var_for_tac_43, {(Addr)&z, (Addr)&temp_var_for_tac_42},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:181:28");
computeLdAdd((Addr)&temp_var_for_tac_44,
             {(Addr) &(temp_var_for_const_33 = V[1]),
              (Addr)&temp_var_for_tac_43},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:181:24");
computeLdMul((Addr)&temp_var_for_tac_45, {(Addr)&z, (Addr)&temp_var_for_tac_44},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:181:16");
computeLdAdd((Addr)&temp_var_for_tac_46,
             {(Addr) &(temp_var_for_const_34 = V[0]),
              (Addr)&temp_var_for_tac_45},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:181:12");
AssignLd({(Addr)&v}, (Addr)&temp_var_for_tac_46,
         "/home/shijia/Public/testprogram/e_y0l.c_e.c:181:5");
;
long double temp_var_for_ext_7;
long double temp_var_for_tac_47, temp_var_for_tac_48, temp_var_for_tac_49,
    temp_var_for_tac_50;
long double temp_var_for_const_35, temp_var_for_const_36, temp_var_for_const_37;
long double temp_var_for_callexp_7;

long double temp_var_for_callexp_8;

temp_var_for_tac_47 = u / v;

temp_var_for_callexp_7 = __ieee754_j0l(x);
temp_var_for_callexp_8 = __ieee754_logl(x);
temp_var_for_tac_48 = temp_var_for_callexp_7 * temp_var_for_callexp_8;

temp_var_for_tac_49 = tpi * temp_var_for_tac_48;

temp_var_for_tac_50 = temp_var_for_tac_47 + temp_var_for_tac_49;

temp_var_for_ext_7 = temp_var_for_tac_50;
computeLdDiv((Addr)&temp_var_for_tac_47, {(Addr)&u, (Addr)&v},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:183:27");
computeLdMul((Addr)&temp_var_for_tac_48,
             {(Addr) &(temp_var_for_const_36 = temp_var_for_callexp_7),
              (Addr) &(temp_var_for_const_35 = temp_var_for_callexp_8)},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:183:57");
computeLdMul((Addr)&temp_var_for_tac_49, {(Addr) &(temp_var_for_const_37 = tpi),
                                          (Addr)&temp_var_for_tac_48},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:183:37");
computeLdAdd((Addr)&temp_var_for_tac_50,
             {(Addr)&temp_var_for_tac_47, (Addr)&temp_var_for_tac_49},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:183:31");
AssignLd({(Addr)&temp_var_for_ext_7}, (Addr)&temp_var_for_tac_50,
         "/home/shijia/Public/testprogram/e_y0l.c_e.c:183:22");
;
callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
callExp++; /*identify the function is  add move tmpShadow*/
return temp_var_for_ext_7;
}

/* wrapper y0 */
long double __y0l(long double x) {
  if ((islessequal(x, 0.0) || isgreater(x, X_TLOSS)) &&
      _LIB_VERSION != _IEEE_) {
    if (int temp_var_for_tac_51; int temp_var_for_const_38;
        temp_var_for_tac_51 = x < 0.0;

        ) {
      /* d = zero/(x-x) */
      feraiseexcept(FE_INVALID);
      long double temp_var_for_ext_8;
      long double temp_var_for_const_39;
      long double temp_var_for_callexp_10;

      temp_var_for_callexp_9 = __builtin_huge_vall();
      temp_var_for_callexp_10 = __kernel_standard_l(
          x, x, (-(temp_var_for_callexp_9)), KMATHERRL_Y0_MINUS);
      temp_var_for_ext_8 = temp_var_for_callexp_10;
      compute((Addr)&temp_var_for_tac_51,
              {(Addr)&x, (Addr) &(temp_var_for_const_38 = 0.0)},
              "/home/shijia/Public/testprogram/e_y0l.c_e.c:193:11");
      AssignLd({(Addr)&temp_var_for_ext_8},
               (Addr) &(temp_var_for_const_39 = temp_var_for_callexp_10),
               "/home/shijia/Public/testprogram/e_y0l.c_e.c:197:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
      callExp++; /*identify the function is  add move tmpSha(0.0 - ow*/
retu)rn temp_var_for_ext_8;
    } else {
      if (int temp_var_for_tac_52; int temp_var_for_const_40;
          temp_var_for_tac_52 = x == 0.0;

          )
      /* d = -one/(x-x) */
      {
        long double temp_var_for_ext_9;
        long double temp_var_for_const_41;
        long double temp_var_for_callexp_12;

        temp_var_for_callexp_11 = __builtin_huge_vall();
        temp_var_for_callexp_12 = __kernel_standard_l(
            x, x, (-(temp_var_for_callexp_11)), KMATHERRL_Y0_ZERO);
        temp_var_for_ext_9 = temp_var_for_callexp_12;
        compute((Addr)&temp_var_for_tac_52,
                {(Addr)&x, (Addr) &(temp_var_for_const_40 = 0.0)},
                "/home/shijia/Public/testprogram/e_y0l.c_e.c:204:13");
        AssignLd({(Addr)&temp_var_for_ext_9},
                 (Addr) &(temp_var_for_const_41 = temp_var_for_callexp_12),
                 "/home/shijia/Public/testprogram/e_y0l.c_e.c:208:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
        callExp++; /*identify the function is  add move tmpShad(0.0 - w*/
retur)n temp_var_for_ext_9;
      }

      else {
        if (_LIB_VERSION != _POSIX_)
        /* y0(x>X_TLOSS) */
        {
          long double temp_var_for_ext_10;
          long double temp_var_for_const_42;
          long double temp_var_for_callexp_13;

          temp_var_for_callexp_13 =
              __kernel_standard_l(x, x, 0.0L, KMATHERRL_Y0_TLOSS);
          temp_var_for_ext_10 = temp_var_for_callexp_13;
          AssignLd({(Addr)&temp_var_for_ext_10},
                   (Addr) &(temp_var_for_const_42 = temp_var_for_callexp_13),
                   "/home/shijia/Public/testprogram/e_y0l.c_e.c:221:31");
          ;
          callExpStack.push(
              getReal("temp_var_for_ext_10", (Addr)&temp_var_for_ext_10));
          callExp++; /*identify the function is  add move tmpShadow*/
          return temp_var_for_ext_10;
        }
      }
    }
  }

  long double temp_var_for_ext_11;
  long double temp_var_for_const_43;
  long double temp_var_for_callexp_14;

  temp_var_for_callexp_14 = __ieee754_y0l(x);
  temp_var_for_ext_11 = temp_var_for_callexp_14;
  AssignLd({(Addr)&temp_var_for_ext_11},
           (Addr) &(temp_var_for_const_43 = temp_var_for_callexp_14),
           "/home/shijia/Public/testprogram/e_y0l.c_e.c:233:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_11", (Addr)&temp_var_for_ext_11));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_11;
}

__typeof(__y0l) y0l __attribute__((weak, alias("__y0l")));

#endif
