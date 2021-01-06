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
  static const long double pio4lo = (0.0 - 0x3.b399d747f23e32ecp-68L);
  long double temp_var_for_const_0, temp_var_for_const_1;
  ;
  /* tan x = x + x^3 / 3 + x^5 T(x^2)/U(x^2)
     0 <= x <= 0.6743316650390625
     Peak relative error 8.0e-36  */
  static const long double TH = 3.333333333333333333333333333333333333333E-1L;
  static const long double T0 =
      (0.0 - 1.813014711743583437742363284336855889393E7L);
  long double temp_var_for_const_2, temp_var_for_const_3;
  long double temp_var_for_tac_0;
  computeLdSub((Addr)&temp_var_for_tac_0,
               {(Addr) &(temp_var_for_const_1 = 0.0),
                (Addr) &(temp_var_for_const_0 = 0x3.b399d747f23e32ecp-68L)},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:76:12");
  ;
  static const long double T1 = 1.320767960008972224312740075083259247618E6L;
  static const long double T2 =
      (0.0 - 2.626775478255838182468651821863299023956E4L);
  long double temp_var_for_const_4, temp_var_for_const_5;
  long double temp_var_for_tac_1;
  computeLdSub((Addr)&temp_var_for_tac_1,
               {(Addr) &(temp_var_for_const_3 = 0.0),
                (Addr) &(temp_var_for_const_2 =
                             1.813014711743583437742363284336855889393E7L)},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:79:12");
  ;
  static const long double T3 = 1.764573356488504935415411383687150199315E2L;
  static const long double T4 =
      (0.0 - 3.333267763822178690794678978979803526092E-1L);
  long double temp_var_for_const_6, temp_var_for_const_7;
  long double temp_var_for_tac_2;
  computeLdSub((Addr)&temp_var_for_tac_2,
               {(Addr) &(temp_var_for_const_5 = 0.0),
                (Addr) &(temp_var_for_const_4 =
                             2.626775478255838182468651821863299023956E4L)},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:82:12");
  ;
  static const long double U0 =
      (0.0 - 1.359761033807687578306772463253710042010E8L);
  long double temp_var_for_const_8, temp_var_for_const_9;
  long double temp_var_for_tac_3;
  computeLdSub((Addr)&temp_var_for_tac_3,
               {(Addr) &(temp_var_for_const_7 = 0.0),
                (Addr) &(temp_var_for_const_6 =
                             3.333267763822178690794678978979803526092E-1L)},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:84:12");
  ;
  static const long double U1 = 6.494370630656893175666729313065113194784E7L;
  static const long double U2 =
      (0.0 - 4.180787672237927475505536849168729386782E6L);
  long double temp_var_for_const_10, temp_var_for_const_11;
  long double temp_var_for_tac_4;
  computeLdSub((Addr)&temp_var_for_tac_4,
               {(Addr) &(temp_var_for_const_9 = 0.0),
                (Addr) &(temp_var_for_const_8 =
                             1.359761033807687578306772463253710042010E8L)},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:87:12");
  ;
  static const long double U3 = 8.031643765106170040139966622980914621521E4L;
  static const long double U4 =
      (0.0 - 5.323131271912475695157127875560667378597E2L);
  long double temp_var_for_const_12, temp_var_for_const_13;
  long double temp_var_for_tac_5;
  computeLdSub((Addr)&temp_var_for_tac_5,
               {(Addr) &(temp_var_for_const_11 = 0.0),
                (Addr) &(temp_var_for_const_10 =
                             4.180787672237927475505536849168729386782E6L)},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:90:12");
  ;
  /* 1.000000000000000000000000000000000000000E0 */

  if (absx < 0x1p-33L) {
    if ((int32_t)x == 0) { /* generate inexact */
      if (x == 0 && iy == -1)
        return one / __ieee754_fabsl(x);
      else
        return (iy == 1) ? x : -one / x;
    }
    long double temp_var_for_tac_6;
    computeLdSub((Addr)&temp_var_for_tac_6,
                 {(Addr) &(temp_var_for_const_13 = 0.0),
                  (Addr) &(temp_var_for_const_12 =
                               5.323131271912475695157127875560667378597E2L)},
                 "toString(biExpr->getExprLoc())");
  }
  if (absx >= 0.6743316650390625L) {
    if (signbit(x)) {
      long double temp_var_for_ext_0;
      temp_var_for_ext_0 = (0.0 - x);
      long double temp_var_for_const_14;
      computeLdSub((Addr)&temp_var_for_ext_0,
                   {(Addr) &(temp_var_for_const_14 = 0.0), (Addr)&x},
                   "/home/shijia/Public/testprogram/k_tanl.c_e.c:104:26"); // x
      /*(x)(x)*/
      x = temp_var_for_ext_0;
      AssignLd({(Addr)&x}, (Addr)&temp_var_for_ext_0,
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:106:9");
      long double temp_var_for_ext_1;
      temp_var_for_ext_1 = (0.0 - y);
      long double temp_var_for_const_15;
      computeLdSub((Addr)&temp_var_for_ext_1,
                   {(Addr) &(temp_var_for_const_15 = 0.0), (Addr)&y},
                   "/home/shijia/Public/testprogram/k_tanl.c_e.c:108:26"); // y
      /*(y)(y)*/
      y = temp_var_for_ext_1;
      AssignLd({(Addr)&y}, (Addr)&temp_var_for_ext_1,
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:110:9");
      sign = -1;
    } else {
      sign = 1;
    }

    z = pio4hi - x;
    long double temp_var_for_const_16;
    computeLdSub((Addr)&z, {(Addr) &(temp_var_for_const_16 = pio4hi), (Addr)&x},
                 "/home/shijia/Public/testprogram/k_tanl.c_e.c:116:7");
    w = pio4lo - y;
    long double temp_var_for_const_17;
    computeLdSub((Addr)&w, {(Addr) &(temp_var_for_const_17 = pio4lo), (Addr)&y},
                 "/home/shijia/Public/testprogram/k_tanl.c_e.c:117:7");
    x = z + w;
    computeLdAdd((Addr)&x, {(Addr)&z, (Addr)&w},
                 "/home/shijia/Public/testprogram/k_tanl.c_e.c:118:7");
    y = 0.0;
    long double temp_var_for_const_18;
    AssignLd({(Addr)&y}, (Addr) &(temp_var_for_const_18 = 0.0),
             "/home/shijia/Public/testprogram/k_tanl.c_e.c:119:7");
  }
  z = x * x;
  computeLdMul((Addr)&z, {(Addr)&x, (Addr)&x},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:121:5");
  r = T0 + z * (T1 + z * (T2 + z * (T3 + z * T4)));
  long double temp_var_for_const_19, temp_var_for_const_20,
      temp_var_for_const_21, temp_var_for_const_22, temp_var_for_const_23;
  long double temp_var_for_tac_7, temp_var_for_tac_8, temp_var_for_tac_9,
      temp_var_for_tac_10, temp_var_for_tac_11, temp_var_for_tac_12,
      temp_var_for_tac_13;
  computeLdMul((Addr)&temp_var_for_tac_7,
               {(Addr)&z, (Addr) &(temp_var_for_const_19 = T4)},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:122:40");
  computeLdAdd((Addr)&temp_var_for_tac_8, {(Addr) &(temp_var_for_const_20 = T3),
                                           (Addr)&temp_var_for_tac_7},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:122:34");
  computeLdMul((Addr)&temp_var_for_tac_9, {(Addr)&z, (Addr)&temp_var_for_tac_8},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:122:30");
  computeLdAdd(
      (Addr)&temp_var_for_tac_10,
      {(Addr) &(temp_var_for_const_21 = T2), (Addr)&temp_var_for_tac_9},
      "/home/shijia/Public/testprogram/k_tanl.c_e.c:122:24");
  computeLdMul((Addr)&temp_var_for_tac_11,
               {(Addr)&z, (Addr)&temp_var_for_tac_10},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:122:20");
  computeLdAdd(
      (Addr)&temp_var_for_tac_12,
      {(Addr) &(temp_var_for_const_22 = T1), (Addr)&temp_var_for_tac_11},
      "/home/shijia/Public/testprogram/k_tanl.c_e.c:122:14");
  computeLdMul((Addr)&temp_var_for_tac_13,
               {(Addr)&z, (Addr)&temp_var_for_tac_12},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:122:10");
  computeLdAdd((Addr)&r, {(Addr) &(temp_var_for_const_23 = T0),
                          (Addr)&temp_var_for_tac_13},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:122:5");
  v = U0 + z * (U1 + z * (U2 + z * (U3 + z * (U4 + z))));
  long double temp_var_for_const_24, temp_var_for_const_25,
      temp_var_for_const_26, temp_var_for_const_27, temp_var_for_const_28;
  long double temp_var_for_tac_14, temp_var_for_tac_15, temp_var_for_tac_16,
      temp_var_for_tac_17, temp_var_for_tac_18, temp_var_for_tac_19,
      temp_var_for_tac_20, temp_var_for_tac_21;
  computeLdAdd((Addr)&temp_var_for_tac_14,
               {(Addr) &(temp_var_for_const_24 = U4), (Addr)&z},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:123:44");
  computeLdMul((Addr)&temp_var_for_tac_15,
               {(Addr)&z, (Addr)&temp_var_for_tac_14},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:123:40");
  computeLdAdd(
      (Addr)&temp_var_for_tac_16,
      {(Addr) &(temp_var_for_const_25 = U3), (Addr)&temp_var_for_tac_15},
      "/home/shijia/Public/testprogram/k_tanl.c_e.c:123:34");
  computeLdMul((Addr)&temp_var_for_tac_17,
               {(Addr)&z, (Addr)&temp_var_for_tac_16},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:123:30");
  computeLdAdd(
      (Addr)&temp_var_for_tac_18,
      {(Addr) &(temp_var_for_const_26 = U2), (Addr)&temp_var_for_tac_17},
      "/home/shijia/Public/testprogram/k_tanl.c_e.c:123:24");
  computeLdMul((Addr)&temp_var_for_tac_19,
               {(Addr)&z, (Addr)&temp_var_for_tac_18},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:123:20");
  computeLdAdd(
      (Addr)&temp_var_for_tac_20,
      {(Addr) &(temp_var_for_const_27 = U1), (Addr)&temp_var_for_tac_19},
      "/home/shijia/Public/testprogram/k_tanl.c_e.c:123:14");
  computeLdMul((Addr)&temp_var_for_tac_21,
               {(Addr)&z, (Addr)&temp_var_for_tac_20},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:123:10");
  computeLdAdd((Addr)&v, {(Addr) &(temp_var_for_const_28 = U0),
                          (Addr)&temp_var_for_tac_21},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:123:5");
  long double temp_var_for_ext_2;
  temp_var_for_ext_2 = r / v;
  computeLdDiv((Addr)&temp_var_for_ext_2, {(Addr)&r, (Addr)&v},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:125:22"); // r
  /*(z)(U4)(z)(U3)(z)(U2)(z)(U1)(z)(U0)(z)(U4)(z)(U3)(z)(U2)(z)(U1)(z)(z)(U4)(z)(U3)(z)(U2)(z)(U1)(z)(U4)(z)(U3)(z)(U2)(z)(z)(U4)(z)(U3)(z)(U2)(z)(U4)(z)(U3)(z)(z)(U4)(z)(U3)(z)(U4)(z)(z)(U4)(v)(r)*/
  r = temp_var_for_ext_2;
  AssignLd({(Addr)&r}, (Addr)&temp_var_for_ext_2,
           "/home/shijia/Public/testprogram/k_tanl.c_e.c:127:5");

  s = z * x;
  computeLdMul((Addr)&s, {(Addr)&z, (Addr)&x},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:129:5");
  long double temp_var_for_ext_3;
  temp_var_for_ext_3 = y + z * (s * r + y);
  long double temp_var_for_tac_22, temp_var_for_tac_23, temp_var_for_tac_24;
  computeLdMul((Addr)&temp_var_for_tac_22, {(Addr)&s, (Addr)&r},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:131:39");
  computeLdAdd((Addr)&temp_var_for_tac_23,
               {(Addr)&temp_var_for_tac_22, (Addr)&y},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:131:30");
  computeLdMul((Addr)&temp_var_for_tac_24,
               {(Addr)&z, (Addr)&temp_var_for_tac_23},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:131:26");
  computeLdAdd((Addr)&temp_var_for_ext_3,
               {(Addr)&y, (Addr)&temp_var_for_tac_24},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:131:22"); // r
  /*(x)(z)(y)(r)(s)(z)(y)*/
  r = temp_var_for_ext_3;
  AssignLd({(Addr)&r}, (Addr)&temp_var_for_ext_3,
           "/home/shijia/Public/testprogram/k_tanl.c_e.c:133:5");
  r += TH * s;
  long double temp_var_for_const_29;
  w = x + r;
  long double temp_var_for_tac_25;
  computeLdMul((Addr)&temp_var_for_tac_25,
               {(Addr) &(temp_var_for_const_29 = TH), (Addr)&s},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:135:9");
  computeLdAdd((Addr)&w, {(Addr)&x, (Addr)&r},
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:135:5");
  if (sign != 0) {
    v = (long double)iy;
    AssignLd({(Addr)&v}, (Addr) & ((long double)iy),
             "/home/shijia/Public/testprogram/k_tanl.c_e.c:137:7");
    long double temp_var_for_ext_4;
    temp_var_for_ext_4 = (v - 2.0 * (x - (w * w / (w + v) - r)));
    long double temp_var_for_const_30;
    long double temp_var_for_tac_26, temp_var_for_tac_27, temp_var_for_tac_28,
        temp_var_for_tac_29, temp_var_for_tac_30, temp_var_for_tac_31;
    computeLdMul((Addr)&temp_var_for_tac_26, {(Addr)&w, (Addr)&w},
                 "/home/shijia/Public/testprogram/k_tanl.c_e.c:139:54");
    computeLdAdd((Addr)&temp_var_for_tac_27, {(Addr)&w, (Addr)&v},
                 "/home/shijia/Public/testprogram/k_tanl.c_e.c:139:49");
    computeLdDiv((Addr)&temp_var_for_tac_28,
                 {(Addr)&temp_var_for_tac_26, (Addr)&temp_var_for_tac_27},
                 "/home/shijia/Public/testprogram/k_tanl.c_e.c:139:59");
    computeLdSub((Addr)&temp_var_for_tac_29,
                 {(Addr)&temp_var_for_tac_28, (Addr)&r},
                 "/home/shijia/Public/testprogram/k_tanl.c_e.c:139:40");
    computeLdSub((Addr)&temp_var_for_tac_30,
                 {(Addr)&x, (Addr)&temp_var_for_tac_29},
                 "/home/shijia/Public/testprogram/k_tanl.c_e.c:139:35");
    computeLdMul(
        (Addr)&temp_var_for_tac_31,
        {(Addr) &(temp_var_for_const_30 = 2.0), (Addr)&temp_var_for_tac_30},
        "/home/shijia/Public/testprogram/k_tanl.c_e.c:139:29");
    computeLdSub((Addr)&temp_var_for_ext_4,
                 {(Addr)&v, (Addr)&temp_var_for_tac_31},
                 "/home/shijia/Public/testprogram/k_tanl.c_e.c:139:24"); // w
    /*(r)(v)(w)(w)(w)(x)(2.0)(v)*/
    w = temp_var_for_ext_4;
    AssignLd({(Addr)&w}, (Addr)&temp_var_for_ext_4,
             "/home/shijia/Public/testprogram/k_tanl.c_e.c:141:7");
    if (sign < 0) {
      long double temp_var_for_ext_5;
      temp_var_for_ext_5 = (0.0 - w);
      long double temp_var_for_const_31;
      computeLdSub((Addr)&temp_var_for_ext_5,
                   {(Addr) &(temp_var_for_const_31 = 0.0), (Addr)&w},
                   "/home/shijia/Public/testprogram/k_tanl.c_e.c:144:26"); // w
      /*(r)(v)(w)(w)(w)(x)(2.0)(v)(r)(v)(w)(w)(w)(x)(2.0)(r)(v)(w)(w)(w)(x)(r)(v)(w)(w)(w)(v)(w)(w)(w)(w)(w)(v)(w)(w)(w)*/
      w = temp_var_for_ext_5;
      AssignLd({(Addr)&w}, (Addr)&temp_var_for_ext_5,
               "/home/shijia/Public/testprogram/k_tanl.c_e.c:146:9");
    }

    long double temp_var_for_ext_6;
    temp_var_for_ext_6 = w;
    AssignLd({(Addr)&temp_var_for_ext_6}, (Addr)&w,
             "/home/shijia/Public/testprogram/k_tanl.c_e.c:150:24");
    callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_6;
  }
  if (iy == 1) {
    long double temp_var_for_ext_7;
    temp_var_for_ext_7 = w;
    AssignLd({(Addr)&temp_var_for_ext_7}, (Addr)&w,
             "/home/shijia/Public/testprogram/k_tanl.c_e.c:157:24");
    callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_7;
  }

  else {
    long double temp_var_for_ext_8;
    temp_var_for_ext_8 = -1.0 / (x + r);
    long double temp_var_for_tac_32;
    computeLdAdd((Addr)&temp_var_for_tac_32, {(Addr)&x, (Addr)&r},
                 "/home/shijia/Public/testprogram/k_tanl.c_e.c:165:31");
    computeLdDiv((Addr)&temp_var_for_ext_8,
                 {(Addr) & (-(1.0)), (Addr)&temp_var_for_tac_32},
                 "/home/shijia/Public/testprogram/k_tanl.c_e.c:165:24");
    callExpStack.push(getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
    callExp++; /*identify the function is  add move tmpShadow*/
    return (0.0 - var)_for_ext_8;
  }
}
