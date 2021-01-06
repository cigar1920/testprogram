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

/*
  Long double expansions are
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

/* __kernel_tanl( x, y, k )
 * kernel tan function on [-pi/4, pi/4], pi/4 ~ 0.7854
 * Input x is assumed to be bounded by ~pi/4 in magnitude.
 * Input y is the tail of x.
 * Input k indicates whether tan (if k=1) or
 * -1/tan (if k= -1) is returned.
 *
 * Algorithm
 *	1. Since tan(-x) = -tan(x), we need only to consider positive x.
 *	2. if x < 2^-33, return x with inexact if x!=0.
 *	3. tan(x) is approximated by a rational form x + x^3 / 3 + x^5 R(x^2)
 *          on [0,0.67433].
 *
 *	   Note: tan(x+y) = tan(x) + tan'(x)*y
 *		          ~ tan(x) + (1+x*x)*y
 *	   Therefore, for better accuracy in computing tan(x+y), let
 *		r = x^3 * R(x^2)
 *	   then
 *		tan(x+y) = x + (x^3 / 3 + (x^2 *(r+y)+y))
 *
 *      4. For x in [0.67433,pi/4],  let y = pi/4 - x, then
 *		tan(x) = tan(pi/4-y) = (1-tan(y))/(1+tan(y))
 *		       = 1 - 2*(tan(y) - (tan(y)^2)/(1+tan(y)))
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

long double __kernel_tanl(long double x, long double y, int iy) {
  long double z, r, v, w, s;
  long double absx = __ieee754_fabsl(x);
  int sign = 0;

  static const long double one = 1.0L;
  static const long double pio4hi = 0xc.90fdaa22168c235p-4L;
  static const long double pio4lo =
      (long double temp_var_for_tac_0;
       long double temp_var_for_const_0, temp_var_for_const_1;
       temp_var_for_tac_0 = 0.0 - 0x3.b399d747f23e32ecp-68L;

       );
  /* tan x = x + x^3 / 3 + x^5 T(x^2)/U(x^2)
     0 <= x <= 0.6743316650390625
     Peak relative error 8.0e-36  */
  static const long double TH = 3.333333333333333333333333333333333333333E-1L;
  static const long double T0 =
      (long double temp_var_for_tac_1;
       long double temp_var_for_const_2, temp_var_for_const_3;
       temp_var_for_tac_1 = 0.0 - 1.813014711743583437742363284336855889393E7L;

       );
  static const long double T1 = 1.320767960008972224312740075083259247618E6L;
  static const long double T2 =
      (long double temp_var_for_tac_2;
       long double temp_var_for_const_4, temp_var_for_const_5;
       temp_var_for_tac_2 = 0.0 - 2.626775478255838182468651821863299023956E4L;

       );
  static const long double T3 = 1.764573356488504935415411383687150199315E2L;
  static const long double T4 =
      (long double temp_var_for_tac_3;
       long double temp_var_for_const_6, temp_var_for_const_7;
       temp_var_for_tac_3 = 0.0 - 3.333267763822178690794678978979803526092E-1L;

       );
  static const long double U0 =
      (long double temp_var_for_tac_4;
       long double temp_var_for_const_8, temp_var_for_const_9;
       temp_var_for_tac_4 = 0.0 - 1.359761033807687578306772463253710042010E8L;

       );
  static const long double U1 = 6.494370630656893175666729313065113194784E7L;
  static const long double U2 =
      (long double temp_var_for_tac_5;
       long double temp_var_for_const_10, temp_var_for_const_11;
       temp_var_for_tac_5 = 0.0 - 4.180787672237927475505536849168729386782E6L;

       );
  static const long double U3 = 8.031643765106170040139966622980914621521E4L;
  static const long double U4 =
      (long double temp_var_for_tac_6;
       long double temp_var_for_const_12, temp_var_for_const_13;
       temp_var_for_tac_6 = 0.0 - 5.323131271912475695157127875560667378597E2L;

       );
  /* 1.000000000000000000000000000000000000000E0 */

  if (int temp_var_for_tac_7; int temp_var_for_const_14;
      temp_var_for_tac_7 = absx < 0x1p-33L;

      ) {
    if ((int32_t)x == 0) { /* generate inexact */
      if (int temp_var_for_tac_8; int temp_var_for_const_15;
          temp_var_for_tac_8 = x == 0;

          &&iy == -1) {
        long double temp_var_for_ext_0;
        long double temp_var_for_tac_9;
        long double temp_var_for_const_16, temp_var_for_const_17;
        long double temp_var_for_callexp_0;

        temp_var_for_callexp_0 = fabsl(x);
        temp_var_for_tac_9 = one / temp_var_for_callexp_0;

        temp_var_for_ext_0 = temp_var_for_tac_9;
        computeLdSub(
            (Addr)&temp_var_for_tac_0,
            {(Addr) &(temp_var_for_const_1 = 0.0),
             (Addr) &(temp_var_for_const_0 = 0x3.b399d747f23e32ecp-68L)},
            "/home/shijia/Public/testprogram/k_tanl.c_e.c:70:42");
        computeLdSub(
            (Addr)&temp_var_for_tac_1,
            {(Addr) &(temp_var_for_const_3 = 0.0),
             (Addr) &(temp_var_for_const_2 =
                          1.813014711743583437742363284336855889393E7L)},
            "/home/shijia/Public/testprogram/k_tanl.c_e.c:76:12");
        computeLdSub(
            (Addr)&temp_var_for_tac_2,
            {(Addr) &(temp_var_for_const_5 = 0.0),
             (Addr) &(temp_var_for_const_4 =
                          2.626775478255838182468651821863299023956E4L)},
            "/home/shijia/Public/testprogram/k_tanl.c_e.c:79:12");
        computeLdSub(
            (Addr)&temp_var_for_tac_3,
            {(Addr) &(temp_var_for_const_7 = 0.0),
             (Addr) &(temp_var_for_const_6 =
                          3.333267763822178690794678978979803526092E-1L)},
            "/home/shijia/Public/testprogram/k_tanl.c_e.c:82:12");
        computeLdSub(
            (Addr)&temp_var_for_tac_4,
            {(Addr) &(temp_var_for_const_9 = 0.0),
             (Addr) &(temp_var_for_const_8 =
                          1.359761033807687578306772463253710042010E8L)},
            "/home/shijia/Public/testprogram/k_tanl.c_e.c:84:12");
        computeLdSub(
            (Addr)&temp_var_for_tac_5,
            {(Addr) &(temp_var_for_const_11 = 0.0),
             (Addr) &(temp_var_for_const_10 =
                          4.180787672237927475505536849168729386782E6L)},
            "/home/shijia/Public/testprogram/k_tanl.c_e.c:87:12");
        computeLdSub(
            (Addr)&temp_var_for_tac_6,
            {(Addr) &(temp_var_for_const_13 = 0.0),
             (Addr) &(temp_var_for_const_12 =
                          5.323131271912475695157127875560667378597E2L)},
            "/home/shijia/Public/testprogram/k_tanl.c_e.c:90:12");
        compute((Addr)&temp_var_for_tac_7,
                {(Addr)&absx, (Addr) &(temp_var_for_const_14 = 0x1p-33L)},
                "/home/shijia/Public/testprogram/k_tanl.c_e.c:93:12");
        compute((Addr)&temp_var_for_tac_8,
                {(Addr)&x, (Addr) &(temp_var_for_const_15 = 0)},
                "/home/shijia/Public/testprogram/k_tanl.c_e.c:95:13");
        computeLdDiv((Addr)&temp_var_for_tac_9,
                     {(Addr) &(temp_var_for_const_17 = one),
                      (Addr) &(temp_var_for_const_16 = temp_var_for_callexp_0)},
                     "/home/shijia/Public/testprogram/k_tanl.c_e.c:97:34");
        AssignLd({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_9,
                 "/home/shijia/Public/testprogram/k_tanl.c_e.c:97:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_0;
      }

      else {
        long double temp_var_for_ext_1;
        long double temp_var_for_const_18;
        temp_var_for_ext_1 = (iy == 1) ? x : -one / x;
        AssignLd({(Addr)&temp_var_for_ext_1},
                 (Addr) &(temp_var_for_const_18 = (iy == 1) ? x : -one / x),
                 "/home/shijia/Public/testprogram/k_tanl.c_e.c:106:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_f(0.0 - r_e) xt_1;
      }
    }
  }
  if (absx >= 0.6743316650390625L) {
    if (signbit(x)) {
      long double temp_var_for_ext_2;
      long double temp_var_for_tac_10;
      long double temp_var_for_const_19;
      temp_var_for_tac_10 = 0.0 - x;

      temp_var_for_ext_2 = temp_var_for_tac_10;
      computeLdSub((Addr)&temp_var_for_tac_10,
                   {(Addr) &(temp_var_for_const_19 = 0.0), (Addr)&x},
                   "/home/shijia/Public/testprogram/k_tanl.c_e.c:117:33");
      AssignLd({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_10,
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:117:26");
      ; // x
      /*(temp_var_for_ext_0)(tem)(1)(r_e)(r_e)(x)(x)*/
      x = temp_var_for_ext_2;
      AssignLd({(Addr)&x}, (Addr)&temp_var_for_ext_2,
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:119:9");
      ;
      long double temp_var_for_ext_3;
      long double temp_var_for_tac_11;
      long double temp_var_for_const_20;
      temp_var_for_tac_11 = 0.0 - y;

      temp_var_for_ext_3 = temp_var_for_tac_11;
      computeLdSub((Addr)&temp_var_for_tac_11,
                   {(Addr) &(temp_var_for_const_20 = 0.0), (Addr)&y},
                   "/home/shijia/Public/testprogram/k_tanl.c_e.c:121:33");
      AssignLd({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_11,
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:121:26");
      ; // y
      /*(y)(y)*/
      y = temp_var_for_ext_3;
      AssignLd({(Addr)&y}, (Addr)&temp_var_for_ext_3,
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:123:9");
      ;
      sign = -1;
    } else {
      sign = 1;
    }

    long double temp_var_for_tac_12;
    long double temp_var_for_const_21;
    temp_var_for_tac_12 = pio4hi - x;

    z = temp_var_for_tac_12;
    computeLdSub((Addr)&temp_var_for_tac_12,
                 {(Addr) &(temp_var_for_const_21 = pio4hi), (Addr)&x},
                 "/home/shijia/Public/testprogram/k_tanl.c_e.c:129:16");
    AssignLd({(Addr)&z}, (Addr)&temp_var_for_tac_12,
             "/home/shijia/Public/testprogram/k_tanl.c_e.c:129:7");
    ;
    long double temp_var_for_tac_13;
    long double temp_var_for_const_22;
    temp_var_for_tac_13 = pio4lo - y;

    w = temp_var_for_tac_13;
    computeLdSub((Addr)&temp_var_for_tac_13,
                 {(Addr) &(temp_var_for_const_22 = pio4lo), (Addr)&y},
                 "/home/shijia/Public/testprogram/k_tanl.c_e.c:130:16");
    AssignLd({(Addr)&w}, (Addr)&temp_var_for_tac_13,
             "/home/shijia/Public/testprogram/k_tanl.c_e.c:130:7");
    ;
    long double temp_var_for_tac_14;
    temp_var_for_tac_14 = z + w;

    x = temp_var_for_tac_14;
    computeLdAdd((Addr)&temp_var_for_tac_14, {(Addr)&z, (Addr)&w},
                 "/home/shijia/Public/testprogram/k_tanl.c_e.c:131:11");
    AssignLd({(Addr)&x}, (Addr)&temp_var_for_tac_14,
             "/home/shijia/Public/testprogram/k_tanl.c_e.c:131:7");
    ;
    long double temp_var_for_const_23;
    y = 0.0;
    AssignLd({(Addr)&y}, (Addr) &(temp_var_for_const_23 = 0.0),
             "/home/shijia/Public/testprogram/k_tanl.c_e.c:132:7");
    ;
  }
  long double temp_var_for_tac_15;
  temp_var_for_tac_15 = x * x;

  z = temp_var_for_tac_15;
  computeLdMul((Addr)&temp_var_for_tac_15, {(Addr)&x, (Addr)&x},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:134:9");
  AssignLd({(Addr)&z}, (Addr)&temp_var_for_tac_15,
           "/home/shijia/Public/testprogram/k_tanl.c_e.c:134:5");
  ;
  long double temp_var_for_tac_16, temp_var_for_tac_17, temp_var_for_tac_18,
      temp_var_for_tac_19, temp_var_for_tac_20, temp_var_for_tac_21,
      temp_var_for_tac_22, temp_var_for_tac_23;
  long double temp_var_for_const_24, temp_var_for_const_25,
      temp_var_for_const_26, temp_var_for_const_27, temp_var_for_const_28;
  temp_var_for_tac_16 = z * T4;

  temp_var_for_tac_17 = T3 + temp_var_for_tac_16;

  temp_var_for_tac_18 = z * temp_var_for_tac_17;

  temp_var_for_tac_19 = T2 + temp_var_for_tac_18;

  temp_var_for_tac_20 = z * temp_var_for_tac_19;

  temp_var_for_tac_21 = T1 + temp_var_for_tac_20;

  temp_var_for_tac_22 = z * temp_var_for_tac_21;

  temp_var_for_tac_23 = T0 + temp_var_for_tac_22;

  r = temp_var_for_tac_23;
  computeLdMul((Addr)&temp_var_for_tac_16,
               {(Addr)&z, (Addr) &(temp_var_for_const_24 = T4)},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:135:44");
  computeLdAdd(
      (Addr)&temp_var_for_tac_17,
      {(Addr) &(temp_var_for_const_25 = T3), (Addr)&temp_var_for_tac_16},
      "/home/shijia/Public/testprogram/k_tanl.c_e.c:135:40");
  computeLdMul((Addr)&temp_var_for_tac_18,
               {(Addr)&z, (Addr)&temp_var_for_tac_17},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:135:34");
  computeLdAdd(
      (Addr)&temp_var_for_tac_19,
      {(Addr) &(temp_var_for_const_26 = T2), (Addr)&temp_var_for_tac_18},
      "/home/shijia/Public/testprogram/k_tanl.c_e.c:135:30");
  computeLdMul((Addr)&temp_var_for_tac_20,
               {(Addr)&z, (Addr)&temp_var_for_tac_19},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:135:24");
  computeLdAdd(
      (Addr)&temp_var_for_tac_21,
      {(Addr) &(temp_var_for_const_27 = T1), (Addr)&temp_var_for_tac_20},
      "/home/shijia/Public/testprogram/k_tanl.c_e.c:135:20");
  computeLdMul((Addr)&temp_var_for_tac_22,
               {(Addr)&z, (Addr)&temp_var_for_tac_21},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:135:14");
  computeLdAdd(
      (Addr)&temp_var_for_tac_23,
      {(Addr) &(temp_var_for_const_28 = T0), (Addr)&temp_var_for_tac_22},
      "/home/shijia/Public/testprogram/k_tanl.c_e.c:135:10");
  AssignLd({(Addr)&r}, (Addr)&temp_var_for_tac_23,
           "/home/shijia/Public/testprogram/k_tanl.c_e.c:135:5");
  ;
  long double temp_var_for_tac_24, temp_var_for_tac_25, temp_var_for_tac_26,
      temp_var_for_tac_27, temp_var_for_tac_28, temp_var_for_tac_29,
      temp_var_for_tac_30, temp_var_for_tac_31, temp_var_for_tac_32;
  long double temp_var_for_const_29, temp_var_for_const_30,
      temp_var_for_const_31, temp_var_for_const_32, temp_var_for_const_33;
  temp_var_for_tac_24 = U4 + z;

  temp_var_for_tac_25 = z * temp_var_for_tac_24;

  temp_var_for_tac_26 = U3 + temp_var_for_tac_25;

  temp_var_for_tac_27 = z * temp_var_for_tac_26;

  temp_var_for_tac_28 = U2 + temp_var_for_tac_27;

  temp_var_for_tac_29 = z * temp_var_for_tac_28;

  temp_var_for_tac_30 = U1 + temp_var_for_tac_29;

  temp_var_for_tac_31 = z * temp_var_for_tac_30;

  temp_var_for_tac_32 = U0 + temp_var_for_tac_31;

  v = temp_var_for_tac_32;
  computeLdAdd((Addr)&temp_var_for_tac_24,
               {(Addr) &(temp_var_for_const_29 = U4), (Addr)&z},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:136:50");
  computeLdMul((Addr)&temp_var_for_tac_25,
               {(Addr)&z, (Addr)&temp_var_for_tac_24},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:136:44");
  computeLdAdd(
      (Addr)&temp_var_for_tac_26,
      {(Addr) &(temp_var_for_const_30 = U3), (Addr)&temp_var_for_tac_25},
      "/home/shijia/Public/testprogram/k_tanl.c_e.c:136:40");
  computeLdMul((Addr)&temp_var_for_tac_27,
               {(Addr)&z, (Addr)&temp_var_for_tac_26},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:136:34");
  computeLdAdd(
      (Addr)&temp_var_for_tac_28,
      {(Addr) &(temp_var_for_const_31 = U2), (Addr)&temp_var_for_tac_27},
      "/home/shijia/Public/testprogram/k_tanl.c_e.c:136:30");
  computeLdMul((Addr)&temp_var_for_tac_29,
               {(Addr)&z, (Addr)&temp_var_for_tac_28},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:136:24");
  computeLdAdd(
      (Addr)&temp_var_for_tac_30,
      {(Addr) &(temp_var_for_const_32 = U1), (Addr)&temp_var_for_tac_29},
      "/home/shijia/Public/testprogram/k_tanl.c_e.c:136:20");
  computeLdMul((Addr)&temp_var_for_tac_31,
               {(Addr)&z, (Addr)&temp_var_for_tac_30},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:136:14");
  computeLdAdd(
      (Addr)&temp_var_for_tac_32,
      {(Addr) &(temp_var_for_const_33 = U0), (Addr)&temp_var_for_tac_31},
      "/home/shijia/Public/testprogram/k_tanl.c_e.c:136:10");
  AssignLd({(Addr)&v}, (Addr)&temp_var_for_tac_32,
           "/home/shijia/Public/testprogram/k_tanl.c_e.c:136:5");
  ;
  long double temp_var_for_ext_4;
  long double temp_var_for_tac_33;
  temp_var_for_tac_33 = r / v;

  temp_var_for_ext_4 = temp_var_for_tac_33;
  computeLdDiv((Addr)&temp_var_for_tac_33, {(Addr)&r, (Addr)&v},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:138:26");
  AssignLd({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_33,
           "/home/shijia/Public/testprogram/k_tanl.c_e.c:138:22");
  ; // r
  /*(z)(U4)(z)(U3)(z)(U2)(z)(U1)(z)(U0)(z)(U4)(z)(U3)(z)(U2)(z)(U1)(z)(z)(U4)(z)(U3)(z)(U2)(z)(U1)(z)(U4)(z)(U3)(z)(U2)(z)(z)(U4)(z)(U3)(z)(U2)(z)(U4)(z)(U3)(z)(z)(U4)(z)(U3)(z)(U4)(z)(z)(U4)(v)(r)*/
  r = temp_var_for_ext_4;
  AssignLd({(Addr)&r}, (Addr)&temp_var_for_ext_4,
           "/home/shijia/Public/testprogram/k_tanl.c_e.c:140:5");
  ;

  long double temp_var_for_tac_34;
  temp_var_for_tac_34 = z * x;

  s = temp_var_for_tac_34;
  computeLdMul((Addr)&temp_var_for_tac_34, {(Addr)&z, (Addr)&x},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:142:9");
  AssignLd({(Addr)&s}, (Addr)&temp_var_for_tac_34,
           "/home/shijia/Public/testprogram/k_tanl.c_e.c:142:5");
  ;
  long double temp_var_for_ext_5;
  long double temp_var_for_tac_35, temp_var_for_tac_36, temp_var_for_tac_37,
      temp_var_for_tac_38;
  temp_var_for_tac_35 = s * r;

  temp_var_for_tac_36 = temp_var_for_tac_35 + y;

  temp_var_for_tac_37 = z * temp_var_for_tac_36;

  temp_var_for_tac_38 = y + temp_var_for_tac_37;

  temp_var_for_ext_5 = temp_var_for_tac_38;
  computeLdMul((Addr)&temp_var_for_tac_35, {(Addr)&s, (Addr)&r},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:144:35");
  computeLdAdd((Addr)&temp_var_for_tac_36,
               {(Addr)&temp_var_for_tac_35, (Addr)&y},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:144:39");
  computeLdMul((Addr)&temp_var_for_tac_37,
               {(Addr)&z, (Addr)&temp_var_for_tac_36},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:144:30");
  computeLdAdd((Addr)&temp_var_for_tac_38,
               {(Addr)&y, (Addr)&temp_var_for_tac_37},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:144:26");
  AssignLd({(Addr)&temp_var_for_ext_5}, (Addr)&temp_var_for_tac_38,
           "/home/shijia/Public/testprogram/k_tanl.c_e.c:144:22");
  ; // r
  /*(x)(z)(y)(r)(s)(z)(y)*/
  r = temp_var_for_ext_5;
  AssignLd({(Addr)&r}, (Addr)&temp_var_for_ext_5,
           "/home/shijia/Public/testprogram/k_tanl.c_e.c:146:5");
  ;
  long double temp_var_for_tac_39;
  long double temp_var_for_const_34;
  temp_var_for_tac_39 = TH * s;

  r += temp_var_for_tac_39;
  ;
  long double temp_var_for_tac_41;
  temp_var_for_tac_41 = x + r;

  w = temp_var_for_tac_41;
  computeLdMul((Addr)&temp_var_for_tac_39,
               {(Addr) &(temp_var_for_const_34 = TH), (Addr)&s},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:147:11");
  computeLdAdd((Addr)&temp_var_for_tac_41, {(Addr)&x, (Addr)&r},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:148:9");
  AssignLd({(Addr)&w}, (Addr)&temp_var_for_tac_41,
           "/home/shijia/Public/testprogram/k_tanl.c_e.c:148:5");
  ;
  if (sign != 0) {
    long double temp_var_for_const_35;
    v = ((long double)iy);
    AssignLd({(Addr)&v}, (Addr) &(temp_var_for_const_35 = ((long double)iy)),
             "/home/shijia/Public/testprogram/k_tanl.c_e.c:150:7");
    ;
    long double temp_var_for_ext_6;
    long double temp_var_for_tac_42, temp_var_for_tac_43, temp_var_for_tac_44,
        temp_var_for_tac_45, temp_var_for_tac_46, temp_var_for_tac_47,
        temp_var_for_tac_48;
    long double temp_var_for_const_36;
    temp_var_for_tac_42 = w * w;

    temp_var_for_tac_43 = w + v;

    temp_var_for_tac_44 = temp_var_for_tac_42 / temp_var_for_tac_43;

    temp_var_for_tac_45 = temp_var_for_tac_44 - r;

    temp_var_for_tac_46 = x - temp_var_for_tac_45;

    temp_var_for_tac_47 = 2.0 * temp_var_for_tac_46;

    temp_var_for_tac_48 = v - temp_var_for_tac_47;

    temp_var_for_ext_6 = temp_var_for_tac_48;
    computeLdMul((Addr)&temp_var_for_tac_42, {(Addr)&w, (Addr)&w},
                 "/home/shijia/Public/testprogram/k_tanl.c_e.c:152:45");
    computeLdAdd((Addr)&temp_var_for_tac_43, {(Addr)&w, (Addr)&v},
                 "/home/shijia/Public/testprogram/k_tanl.c_e.c:152:54");
    computeLdDiv((Addr)&temp_var_for_tac_44,
                 {(Addr)&temp_var_for_tac_42, (Addr)&temp_var_for_tac_43},
                 "/home/shijia/Public/testprogram/k_tanl.c_e.c:152:49");
    computeLdSub((Addr)&temp_var_for_tac_45,
                 {(Addr)&temp_var_for_tac_44, (Addr)&r},
                 "/home/shijia/Public/testprogram/k_tanl.c_e.c:152:59");
    computeLdSub((Addr)&temp_var_for_tac_46,
                 {(Addr)&x, (Addr)&temp_var_for_tac_45},
                 "/home/shijia/Public/testprogram/k_tanl.c_e.c:152:40");
    computeLdMul(
        (Addr)&temp_var_for_tac_47,
        {(Addr) &(temp_var_for_const_36 = 2.0), (Addr)&temp_var_for_tac_46},
        "/home/shijia/Public/testprogram/k_tanl.c_e.c:152:35");
    computeLdSub((Addr)&temp_var_for_tac_48,
                 {(Addr)&v, (Addr)&temp_var_for_tac_47},
                 "/home/shijia/Public/testprogram/k_tanl.c_e.c:152:29");
    AssignLd({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_48,
             "/home/shijia/Public/testprogram/k_tanl.c_e.c:152:24");
    ; // w
    /*(r)(v)(w)(w)(w)(x)(2.0)(v)*/
    w = temp_var_for_ext_6;
    AssignLd({(Addr)&w}, (Addr)&temp_var_for_ext_6,
             "/home/shijia/Public/testprogram/k_tanl.c_e.c:154:7");
    ;
    if (sign < 0) {
      long double temp_var_for_ext_7;
      long double temp_var_for_tac_49;
      long double temp_var_for_const_37;
      temp_var_for_tac_49 = 0.0 - w;

      temp_var_for_ext_7 = temp_var_for_tac_49;
      computeLdSub((Addr)&temp_var_for_tac_49,
                   {(Addr) &(temp_var_for_const_37 = 0.0), (Addr)&w},
                   "/home/shijia/Public/testprogram/k_tanl.c_e.c:157:33");
      AssignLd({(Addr)&temp_var_for_ext_7}, (Addr)&temp_var_for_tac_49,
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:157:26");
      ; // w
      /*(r)(v)(w)(w)(w)(x)(2.0)(v)(r)(v)(w)(w)(w)(x)(2.0)(r)(v)(w)(w)(w)(x)(r)(v)(w)(w)(w)(v)(w)(w)(w)(w)(w)(v)(w)(w)(w)*/
      w = temp_var_for_ext_7;
      AssignLd({(Addr)&w}, (Addr)&temp_var_for_ext_7,
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:159:9");
      ;
    }

    long double temp_var_for_ext_8;
    temp_var_for_ext_8 = w;
    AssignLd({(Addr)&temp_var_for_ext_8}, (Addr)&w,
             "/home/shijia/Public/testprogram/k_tanl.c_e.c:163:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_8;
  }
  if (iy == 1) {
    long double temp_var_for_ext_9;
    temp_var_for_ext_9 = w;
    AssignLd({(Addr)&temp_var_for_ext_9}, (Addr)&w,
             "/home/shijia/Public/testprogram/k_tanl.c_e.c:170:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_9;
  }

  else {
    long double temp_var_for_ext_10;
    long double temp_var_for_tac_50, temp_var_for_tac_51;
    long double temp_var_for_const_38;
    temp_var_for_tac_50 = x + r;

    temp_var_for_tac_51 = (-(1.0)) / temp_var_for_tac_50;

    temp_var_for_ext_10 = temp_var_for_tac_51;
    computeLdAdd((Addr)&temp_var_for_tac_50, {(Addr)&x, (Addr)&r},
                 "/home/shijia/Public/testprogram/k_tanl.c_e.c:178:37");
    computeLdDiv((Addr)&temp_var_for_tac_51,
                 {(Addr) &(temp_var_for_const_38 = (-(1.0))),
                  (Addr)&temp_var_for_tac_50},
                 "/home/shijia/Public/testprogram/k_tanl.c_e.c:178:32");
    AssignLd({(Addr)&temp_var_for_ext_10}, (Addr)&temp_var_for_tac_51,
             "/home/shijia/Public/testprogram/k_tanl.c_e.c:178:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_10", (Addr)&temp_var_for_ext_10));
    callExp++; /*identify the function is  add move tmpShadow*/
    return (0.0 - ar_)for_ext_10;
  }
}
