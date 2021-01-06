#include "../ScDebug/scdebug.h"
/* e_asinf.c -- float version of e_asin.c.
 * Conversion to float by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.
 */

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
  Modifications for single precision expansion are
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

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_asin

float __ieee754_asinf(float x) {
  float t, w, p, q, c, r, s;
  int32_t hx, ix;

  static const float one = 1.0000000000e+00; /* 0x3F800000 */
  static const float hugeval = 1.000e+30;
  static const float pio2_hi = 1.57079637050628662109375f;
  static const float pio2_lo =
      (double temp_var_for_tac_0;
       double temp_var_for_const_0, temp_var_for_const_1;
       temp_var_for_tac_0 = 0.0 - 4.37113900018624283e-8f;

       );
  static const float pio4_hi = 0.785398185253143310546875f;
  /* asin x = x + x^3 p(x^2)
     -0.5 <= x <= 0.5;
     Peak relative error 4.8e-9 */
  static const float p0 = 1.666675248e-1f;
  static const float p1 = 7.495297643e-2f;
  static const float p2 = 4.547037598e-2f;
  static const float p3 = 2.417951451e-2f;
  static const float p4 = 4.216630880e-2f;

  GET_FLOAT_WORD(hx, x);
  ix = hx & IC(0x7fffffff);
  if (ix == IC(0x3f800000)) {
    /* asin(1)=+-pi/2 with inexact */
    float temp_var_for_ext_0;
    float temp_var_for_tac_1, temp_var_for_tac_2, temp_var_for_tac_3;
    float temp_var_for_const_2, temp_var_for_const_3;
    temp_var_for_tac_1 = x * pio2_hi;

    temp_var_for_tac_2 = x * pio2_lo;

    temp_var_for_tac_3 = temp_var_for_tac_1 + temp_var_for_tac_2;

    temp_var_for_ext_0 = temp_var_for_tac_3;
    computeDSub((Addr)&temp_var_for_tac_0,
                {(Addr) &(temp_var_for_const_1 = 0.0),
                 (Addr) &(temp_var_for_const_0 = 4.37113900018624283e-8f)},
                "/home/shijia/Public/testprogram/e_asinf.c_e.c:51:37");
    computeFMul((Addr)&temp_var_for_tac_1,
                {(Addr)&x, (Addr) &(temp_var_for_const_2 = pio2_hi)},
                "/home/shijia/Public/testprogram/e_asinf.c_e.c:67:28");
    computeFMul((Addr)&temp_var_for_tac_2,
                {(Addr)&x, (Addr) &(temp_var_for_const_3 = pio2_lo)},
                "/home/shijia/Public/testprogram/e_asinf.c_e.c:67:42");
    computeFAdd((Addr)&temp_var_for_tac_3,
                {(Addr)&temp_var_for_tac_1, (Addr)&temp_var_for_tac_2},
                "/home/shijia/Public/testprogram/e_asinf.c_e.c:67:38");
    AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_3,
            "/home/shijia/Public/testprogram/e_asinf.c_e.c:67:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  } else {
    if (ix > IC(0x3f800000)) { /* |x|>= 1 */
      float temp_var_for_ext_1;
      float temp_var_for_tac_4, temp_var_for_tac_5, temp_var_for_tac_6;
      temp_var_for_tac_4 = x - x;

      temp_var_for_tac_5 = x - x;

      temp_var_for_tac_6 = temp_var_for_tac_4 / temp_var_for_tac_5;

      temp_var_for_ext_1 = temp_var_for_tac_6;
      computeFSub((Addr)&temp_var_for_tac_4, {(Addr)&x, (Addr)&x},
                  "/home/shijia/Public/testprogram/e_asinf.c_e.c:74:31");
      computeFSub((Addr)&temp_var_for_tac_5, {(Addr)&x, (Addr)&x},
                  "/home/shijia/Public/testprogram/e_asinf.c_e.c:74:41");
      computeFDiv((Addr)&temp_var_for_tac_6,
                  {(Addr)&temp_var_for_tac_4, (Addr)&temp_var_for_tac_5},
                  "/home/shijia/Public/testprogram/e_asinf.c_e.c:74:36");
      AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_6,
              "/home/shijia/Public/testprogram/e_asinf.c_e.c:74:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_1; /* asin(|x|>1) is NaN */
    } else {
      if (ix < IC(0x3f000000)) {   /* |x|<0.5 */
        if (ix < IC(0x32000000)) { /* if |x| < 2**-27 */
          if (int temp_var_for_tac_7, temp_var_for_tac_8;
              int temp_var_for_const_4, temp_var_for_const_5;
              temp_var_for_tac_7 = hugeval + x;

              temp_var_for_tac_8 = temp_var_for_tac_7 > one;

              ) {
            float temp_var_for_ext_2;
            temp_var_for_ext_2 = x;
            computeFAdd((Addr)&temp_var_for_tac_7,
                        {(Addr) &(temp_var_for_const_4 = hugeval), (Addr)&x},
                        "/home/shijia/Public/testprogram/e_asinf.c_e.c:82:23");
            compute((Addr)&temp_var_for_tac_8,
                    {(Addr)&temp_var_for_tac_7,
                     (Addr) &(temp_var_for_const_5 = one)},
                    "/home/shijia/Public/testprogram/e_asinf.c_e.c:82:27");
            AssignF({(Addr)&temp_var_for_ext_2}, (Addr)&x,
                    "/home/shijia/Public/testprogram/e_asinf.c_e.c:84:32");
            ;
            callExpStack.push(
                getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
            callExp++; /*identify the function is  add move tmpShadow*/
            return temp_var_for_ext_2;
          }
          /* return x with inexact if x!=0 */
        } else {
          float temp_var_for_ext_3;
          float temp_var_for_tac_9;
          temp_var_for_tac_9 = x * x;

          temp_var_for_ext_3 = temp_var_for_tac_9;
          computeFMul((Addr)&temp_var_for_tac_9, {(Addr)&x, (Addr)&x},
                      "/home/shijia/Public/testprogram/e_asinf.c_e.c:93:34");
          AssignF({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_9,
                  "/home/shijia/Public/testprogram/e_asinf.c_e.c:93:30");
          ; // t
            /*(r_ext_0)(r)(rn temp)(t)(rn
             * temp)(t)(r_ext_0)(r)(_)(_)(a)(m)(a)(m)(_)(_)(x)(hugeval)(x)(x)*/
          t = temp_var_for_ext_3;
          AssignF({(Addr)&t}, (Addr)&temp_var_for_ext_3,
                  "/home/shijia/Public/testprogram/e_asinf.c_e.c:96:13");
          ;
          float temp_var_for_tac_10, temp_var_for_tac_11, temp_var_for_tac_12,
              temp_var_for_tac_13, temp_var_for_tac_14, temp_var_for_tac_15,
              temp_var_for_tac_16, temp_var_for_tac_17, temp_var_for_tac_18;
          float temp_var_for_const_6, temp_var_for_const_7,
              temp_var_for_const_8, temp_var_for_const_9, temp_var_for_const_10;
          temp_var_for_tac_10 = t * p4;

          temp_var_for_tac_11 = p3 + temp_var_for_tac_10;

          temp_var_for_tac_12 = t * temp_var_for_tac_11;

          temp_var_for_tac_13 = p2 + temp_var_for_tac_12;

          temp_var_for_tac_14 = t * temp_var_for_tac_13;

          temp_var_for_tac_15 = p1 + temp_var_for_tac_14;

          temp_var_for_tac_16 = t * temp_var_for_tac_15;

          temp_var_for_tac_17 = p0 + temp_var_for_tac_16;

          temp_var_for_tac_18 = t * temp_var_for_tac_17;

          w = temp_var_for_tac_18;
          computeFMul((Addr)&temp_var_for_tac_10,
                      {(Addr)&t, (Addr) &(temp_var_for_const_6 = p4)},
                      "/home/shijia/Public/testprogram/e_asinf.c_e.c:97:57");
          computeFAdd(
              (Addr)&temp_var_for_tac_11,
              {(Addr) &(temp_var_for_const_7 = p3), (Addr)&temp_var_for_tac_10},
              "/home/shijia/Public/testprogram/e_asinf.c_e.c:97:53");
          computeFMul((Addr)&temp_var_for_tac_12,
                      {(Addr)&t, (Addr)&temp_var_for_tac_11},
                      "/home/shijia/Public/testprogram/e_asinf.c_e.c:97:47");
          computeFAdd(
              (Addr)&temp_var_for_tac_13,
              {(Addr) &(temp_var_for_const_8 = p2), (Addr)&temp_var_for_tac_12},
              "/home/shijia/Public/testprogram/e_asinf.c_e.c:97:43");
          computeFMul((Addr)&temp_var_for_tac_14,
                      {(Addr)&t, (Addr)&temp_var_for_tac_13},
                      "/home/shijia/Public/testprogram/e_asinf.c_e.c:97:37");
          computeFAdd(
              (Addr)&temp_var_for_tac_15,
              {(Addr) &(temp_var_for_const_9 = p1), (Addr)&temp_var_for_tac_14},
              "/home/shijia/Public/testprogram/e_asinf.c_e.c:97:33");
          computeFMul((Addr)&temp_var_for_tac_16,
                      {(Addr)&t, (Addr)&temp_var_for_tac_15},
                      "/home/shijia/Public/testprogram/e_asinf.c_e.c:97:27");
          computeFAdd((Addr)&temp_var_for_tac_17,
                      {(Addr) &(temp_var_for_const_10 = p0),
                       (Addr)&temp_var_for_tac_16},
                      "/home/shijia/Public/testprogram/e_asinf.c_e.c:97:23");
          computeFMul((Addr)&temp_var_for_tac_18,
                      {(Addr)&t, (Addr)&temp_var_for_tac_17},
                      "/home/shijia/Public/testprogram/e_asinf.c_e.c:97:17");
          AssignF({(Addr)&w}, (Addr)&temp_var_for_tac_18,
                  "/home/shijia/Public/testprogram/e_asinf.c_e.c:97:13");
          ;
          float temp_var_for_ext_4;
          float temp_var_for_tac_19, temp_var_for_tac_20;
          temp_var_for_tac_19 = x * w;

          temp_var_for_tac_20 = x + temp_var_for_tac_19;

          temp_var_for_ext_4 = temp_var_for_tac_20;
          computeFMul((Addr)&temp_var_for_tac_19, {(Addr)&x, (Addr)&w},
                      "/home/shijia/Public/testprogram/e_asinf.c_e.c:99:38");
          computeFAdd((Addr)&temp_var_for_tac_20,
                      {(Addr)&x, (Addr)&temp_var_for_tac_19},
                      "/home/shijia/Public/testprogram/e_asinf.c_e.c:99:34");
          AssignF({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_20,
                  "/home/shijia/Public/testprogram/e_asinf.c_e.c:99:30");
          ;
          callExpStack.push(
              getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
          callExp++; /*identify the function is  add move tmpShadow*/
          return temp_var_for_ext_4;
        }
      }
    }
  }

  /* 1> |x|>= 0.5 */
  float temp_var_for_tac_21;
  float temp_var_for_const_11, temp_var_for_const_12;
  float temp_var_for_callexp_0;

  temp_var_for_callexp_0 = fabsf(x);
  temp_var_for_tac_21 = one - temp_var_for_callexp_0;

  w = temp_var_for_tac_21;
  computeFSub((Addr)&temp_var_for_tac_21,
              {(Addr) &(temp_var_for_const_12 = one),
               (Addr) &(temp_var_for_const_11 = temp_var_for_callexp_0)},
              "/home/shijia/Public/testprogram/e_asinf.c_e.c:110:11");
  AssignF({(Addr)&w}, (Addr)&temp_var_for_tac_21,
          "/home/shijia/Public/testprogram/e_asinf.c_e.c:110:5");
  ;
  float temp_var_for_tac_22;
  float temp_var_for_const_13;
  temp_var_for_tac_22 = w * 0.5f;

  t = temp_var_for_tac_22;
  computeFMul((Addr)&temp_var_for_tac_22,
              {(Addr)&w, (Addr) &(temp_var_for_const_13 = 0.5f)},
              "/home/shijia/Public/testprogram/e_asinf.c_e.c:111:9");
  AssignF({(Addr)&t}, (Addr)&temp_var_for_tac_22,
          "/home/shijia/Public/testprogram/e_asinf.c_e.c:111:5");
  ;
  float temp_var_for_tac_23, temp_var_for_tac_24, temp_var_for_tac_25,
      temp_var_for_tac_26, temp_var_for_tac_27, temp_var_for_tac_28,
      temp_var_for_tac_29, temp_var_for_tac_30, temp_var_for_tac_31;
  float temp_var_for_const_14, temp_var_for_const_15, temp_var_for_const_16,
      temp_var_for_const_17, temp_var_for_const_18;
  temp_var_for_tac_23 = t * p4;

  temp_var_for_tac_24 = p3 + temp_var_for_tac_23;

  temp_var_for_tac_25 = t * temp_var_for_tac_24;

  temp_var_for_tac_26 = p2 + temp_var_for_tac_25;

  temp_var_for_tac_27 = t * temp_var_for_tac_26;

  temp_var_for_tac_28 = p1 + temp_var_for_tac_27;

  temp_var_for_tac_29 = t * temp_var_for_tac_28;

  temp_var_for_tac_30 = p0 + temp_var_for_tac_29;

  temp_var_for_tac_31 = t * temp_var_for_tac_30;

  p = temp_var_for_tac_31;
  computeFMul((Addr)&temp_var_for_tac_23,
              {(Addr)&t, (Addr) &(temp_var_for_const_14 = p4)},
              "/home/shijia/Public/testprogram/e_asinf.c_e.c:112:49");
  computeFAdd((Addr)&temp_var_for_tac_24, {(Addr) &(temp_var_for_const_15 = p3),
                                           (Addr)&temp_var_for_tac_23},
              "/home/shijia/Public/testprogram/e_asinf.c_e.c:112:45");
  computeFMul((Addr)&temp_var_for_tac_25,
              {(Addr)&t, (Addr)&temp_var_for_tac_24},
              "/home/shijia/Public/testprogram/e_asinf.c_e.c:112:39");
  computeFAdd((Addr)&temp_var_for_tac_26, {(Addr) &(temp_var_for_const_16 = p2),
                                           (Addr)&temp_var_for_tac_25},
              "/home/shijia/Public/testprogram/e_asinf.c_e.c:112:35");
  computeFMul((Addr)&temp_var_for_tac_27,
              {(Addr)&t, (Addr)&temp_var_for_tac_26},
              "/home/shijia/Public/testprogram/e_asinf.c_e.c:112:29");
  computeFAdd((Addr)&temp_var_for_tac_28, {(Addr) &(temp_var_for_const_17 = p1),
                                           (Addr)&temp_var_for_tac_27},
              "/home/shijia/Public/testprogram/e_asinf.c_e.c:112:25");
  computeFMul((Addr)&temp_var_for_tac_29,
              {(Addr)&t, (Addr)&temp_var_for_tac_28},
              "/home/shijia/Public/testprogram/e_asinf.c_e.c:112:19");
  computeFAdd((Addr)&temp_var_for_tac_30, {(Addr) &(temp_var_for_const_18 = p0),
                                           (Addr)&temp_var_for_tac_29},
              "/home/shijia/Public/testprogram/e_asinf.c_e.c:112:15");
  computeFMul((Addr)&temp_var_for_tac_31,
              {(Addr)&t, (Addr)&temp_var_for_tac_30},
              "/home/shijia/Public/testprogram/e_asinf.c_e.c:112:9");
  AssignF({(Addr)&p}, (Addr)&temp_var_for_tac_31,
          "/home/shijia/Public/testprogram/e_asinf.c_e.c:112:5");
  ;
  float temp_var_for_const_19;
  float temp_var_for_callexp_1;

  temp_var_for_callexp_1 = __ieee754_sqrtf(t);
  s = temp_var_for_callexp_1;
  AssignF({(Addr)&s}, (Addr) &(temp_var_for_const_19 = temp_var_for_callexp_1),
          "/home/shijia/Public/testprogram/e_asinf.c_e.c:113:5");
  ;
  if (ix >= IC(0x3F79999A)) { /* if |x| > 0.975 */
    float temp_var_for_tac_32, temp_var_for_tac_33, temp_var_for_tac_34,
        temp_var_for_tac_35, temp_var_for_tac_36;
    float temp_var_for_const_20, temp_var_for_const_21, temp_var_for_const_22;
    temp_var_for_tac_32 = s * p;

    temp_var_for_tac_33 = s + temp_var_for_tac_32;

    temp_var_for_tac_34 = 2.0f * temp_var_for_tac_33;

    temp_var_for_tac_35 = temp_var_for_tac_34 - pio2_lo;

    temp_var_for_tac_36 = pio2_hi - temp_var_for_tac_35;

    t = temp_var_for_tac_36;
    computeFMul((Addr)&temp_var_for_tac_32, {(Addr)&s, (Addr)&p},
                "/home/shijia/Public/testprogram/e_asinf.c_e.c:115:34");
    computeFAdd((Addr)&temp_var_for_tac_33,
                {(Addr)&s, (Addr)&temp_var_for_tac_32},
                "/home/shijia/Public/testprogram/e_asinf.c_e.c:115:30");
    computeFMul(
        (Addr)&temp_var_for_tac_34,
        {(Addr) &(temp_var_for_const_20 = 2.0f), (Addr)&temp_var_for_tac_33},
        "/home/shijia/Public/testprogram/e_asinf.c_e.c:115:25");
    computeFSub(
        (Addr)&temp_var_for_tac_35,
        {(Addr)&temp_var_for_tac_34, (Addr) &(temp_var_for_const_21 = pio2_lo)},
        "/home/shijia/Public/testprogram/e_asinf.c_e.c:115:39");
    computeFSub(
        (Addr)&temp_var_for_tac_36,
        {(Addr) &(temp_var_for_const_22 = pio2_hi), (Addr)&temp_var_for_tac_35},
        "/home/shijia/Public/testprogram/e_asinf.c_e.c:115:17");
    AssignF({(Addr)&t}, (Addr)&temp_var_for_tac_36,
            "/home/shijia/Public/testprogram/e_asinf.c_e.c:115:7");
    ;
  } else {
    int32_t iw;

    w = s;
    AssignF({(Addr)&w}, (Addr)&s,
            "/home/shijia/Public/testprogram/e_asinf.c_e.c:119:7");
    ;
    GET_FLOAT_WORD(iw, w);
    SET_FLOAT_WORD(w, iw & IC(0xfffff000));
    float temp_var_for_tac_37, temp_var_for_tac_38, temp_var_for_tac_39,
        temp_var_for_tac_40;
    temp_var_for_tac_37 = w * w;

    temp_var_for_tac_38 = t - temp_var_for_tac_37;

    temp_var_for_tac_39 = s + w;

    temp_var_for_tac_40 = temp_var_for_tac_38 / temp_var_for_tac_39;

    c = temp_var_for_tac_40;
    computeFMul((Addr)&temp_var_for_tac_37, {(Addr)&w, (Addr)&w},
                "/home/shijia/Public/testprogram/e_asinf.c_e.c:122:16");
    computeFSub((Addr)&temp_var_for_tac_38,
                {(Addr)&t, (Addr)&temp_var_for_tac_37},
                "/home/shijia/Public/testprogram/e_asinf.c_e.c:122:12");
    computeFAdd((Addr)&temp_var_for_tac_39, {(Addr)&s, (Addr)&w},
                "/home/shijia/Public/testprogram/e_asinf.c_e.c:122:26");
    computeFDiv((Addr)&temp_var_for_tac_40,
                {(Addr)&temp_var_for_tac_38, (Addr)&temp_var_for_tac_39},
                "/home/shijia/Public/testprogram/e_asinf.c_e.c:122:21");
    AssignF({(Addr)&c}, (Addr)&temp_var_for_tac_40,
            "/home/shijia/Public/testprogram/e_asinf.c_e.c:122:7");
    ;
    r = p;
    AssignF({(Addr)&r}, (Addr)&p,
            "/home/shijia/Public/testprogram/e_asinf.c_e.c:123:7");
    ;
    float temp_var_for_tac_41, temp_var_for_tac_42, temp_var_for_tac_43,
        temp_var_for_tac_44, temp_var_for_tac_45;
    float temp_var_for_const_23, temp_var_for_const_24, temp_var_for_const_25;
    temp_var_for_tac_41 = 2.0f * s;

    temp_var_for_tac_42 = temp_var_for_tac_41 * r;

    temp_var_for_tac_43 = 2.0f * c;

    temp_var_for_tac_44 = pio2_lo - temp_var_for_tac_43;

    temp_var_for_tac_45 = temp_var_for_tac_42 - temp_var_for_tac_44;

    p = temp_var_for_tac_45;
    computeFMul((Addr)&temp_var_for_tac_41,
                {(Addr) &(temp_var_for_const_23 = 2.0f), (Addr)&s},
                "/home/shijia/Public/testprogram/e_asinf.c_e.c:124:14");
    computeFMul((Addr)&temp_var_for_tac_42,
                {(Addr)&temp_var_for_tac_41, (Addr)&r},
                "/home/shijia/Public/testprogram/e_asinf.c_e.c:124:18");
    computeFMul((Addr)&temp_var_for_tac_43,
                {(Addr) &(temp_var_for_const_24 = 2.0f), (Addr)&c},
                "/home/shijia/Public/testprogram/e_asinf.c_e.c:124:40");
    computeFSub(
        (Addr)&temp_var_for_tac_44,
        {(Addr) &(temp_var_for_const_25 = pio2_lo), (Addr)&temp_var_for_tac_43},
        "/home/shijia/Public/testprogram/e_asinf.c_e.c:124:33");
    computeFSub((Addr)&temp_var_for_tac_45,
                {(Addr)&temp_var_for_tac_42, (Addr)&temp_var_for_tac_44},
                "/home/shijia/Public/testprogram/e_asinf.c_e.c:124:22");
    AssignF({(Addr)&p}, (Addr)&temp_var_for_tac_45,
            "/home/shijia/Public/testprogram/e_asinf.c_e.c:124:7");
    ;
    float temp_var_for_tac_46, temp_var_for_tac_47;
    float temp_var_for_const_26, temp_var_for_const_27;
    temp_var_for_tac_46 = 2.0f * w;

    temp_var_for_tac_47 = pio4_hi - temp_var_for_tac_46;

    q = temp_var_for_tac_47;
    computeFMul((Addr)&temp_var_for_tac_46,
                {(Addr) &(temp_var_for_const_26 = 2.0f), (Addr)&w},
                "/home/shijia/Public/testprogram/e_asinf.c_e.c:125:24");
    computeFSub(
        (Addr)&temp_var_for_tac_47,
        {(Addr) &(temp_var_for_const_27 = pio4_hi), (Addr)&temp_var_for_tac_46},
        "/home/shijia/Public/testprogram/e_asinf.c_e.c:125:17");
    AssignF({(Addr)&q}, (Addr)&temp_var_for_tac_47,
            "/home/shijia/Public/testprogram/e_asinf.c_e.c:125:7");
    ;
    float temp_var_for_tac_48, temp_var_for_tac_49;
    float temp_var_for_const_28;
    temp_var_for_tac_48 = p - q;

    temp_var_for_tac_49 = pio4_hi - temp_var_for_tac_48;

    t = temp_var_for_tac_49;
    computeFSub((Addr)&temp_var_for_tac_48, {(Addr)&p, (Addr)&q},
                "/home/shijia/Public/testprogram/e_asinf.c_e.c:126:22");
    computeFSub(
        (Addr)&temp_var_for_tac_49,
        {(Addr) &(temp_var_for_const_28 = pio4_hi), (Addr)&temp_var_for_tac_48},
        "/home/shijia/Public/testprogram/e_asinf.c_e.c:126:17");
    AssignF({(Addr)&t}, (Addr)&temp_var_for_tac_49,
            "/home/shijia/Public/testprogram/e_asinf.c_e.c:126:7");
    ;
  }
  if (hx > 0) {
    float temp_var_for_ext_5;
    temp_var_for_ext_5 = t;
    AssignF({(Addr)&temp_var_for_ext_5}, (Addr)&t,
            "/home/shijia/Public/testprogram/e_asinf.c_e.c:130:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_5;
  }

  float temp_var_for_ext_6;
  float temp_var_for_const_29;
  temp_var_for_ext_6 = (-(t));
  AssignF({(Addr)&temp_var_for_ext_6}, (Addr) &(temp_var_for_const_29 = (-(t))),
          "/home/shijia/Public/testprogram/e_asinf.c_e.c:137:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
  callExp++; /*identify the function is  add move tmpShadow*/
  return (double temp_var_for_tac_50;
          double temp_var_for_const_30, temp_var_for_const_31;
          temp_var_for_tac_50 = 0.0 - 6;

          );
}

#endif

/* wrapper asin */
float __asinf(float x) {
  if (isgreater(__ieee754_fabsf(x), 1.0) && _LIB_VERSION != _IEEE_) {
    /* asin(|x|>1) */
    feraiseexcept(FE_INVALID);
    float temp_var_for_ext_7;
    float temp_var_for_const_32;
    float temp_var_for_callexp_2;

    /*embed fun has found*/
    float temp_var_for_callexp_3;

    temp_var_for_callexp_2 = __builtin_nanf("");
    temp_var_for_callexp_3 =
        __kernel_standard_f(x, x, temp_var_for_callexp_2, KMATHERRF_ASIN);
    temp_var_for_ext_7 = temp_var_for_callexp_3;
    computeDSub((Addr)&temp_var_for_tac_50,
                {(Addr) &(temp_var_for_const_31 = 0.0),
                 (Addr) &(temp_var_for_const_30 = 6)},
                "/home/shijia/Public/testprogram/e_asinf.c_e.c:140:15");
    AssignF({(Addr)&temp_var_for_ext_7},
            (Addr) &(temp_var_for_const_32 = temp_var_for_callexp_3),
            "/home/shijia/Public/testprogram/e_asinf.c_e.c:151:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_7;
  }

  float temp_var_for_ext_8;
  float temp_var_for_const_33;
  float temp_var_for_callexp_4;

  temp_var_for_callexp_4 = __ieee754_asinf(x);
  temp_var_for_ext_8 = temp_var_for_callexp_4;
  AssignF({(Addr)&temp_var_for_ext_8},
          (Addr) &(temp_var_for_const_33 = temp_var_for_callexp_4),
          "/home/shijia/Public/testprogram/e_asinf.c_e.c:159:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_8;
}

__typeof(__asinf) asinf __attribute__((weak, alias("__asinf")));
