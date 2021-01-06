#include "../ScDebug/scdebug.h"
/* Extended-precision floating point cosine on <-pi/4,pi/4>.
   Copyright (C) 1999-2013 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Based on quad-precision cosine by Jakub Jelinek <jj@ultra.linux.cz>

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

long double __kernel_cosl(long double x, long double y) {
  long double h, l, z, sin_l, cos_l_m1;
  int index;

  /* The polynomials have not been optimized for extended-precision and
     may contain more terms than needed.  */

  static const long double ONE = 1.00000000000000000000000000000000000E+00L;

  /* cos x ~ ONE + x^2 ( SCOS1 + SCOS2 * x^2 + ... + SCOS4 * x^6 + SCOS5 * x^8 )
     x in <0,1/256>  */
  static const long double SCOS1 =
      (long double temp_var_for_tac_0;
       long double temp_var_for_const_0, temp_var_for_const_1;
       temp_var_for_tac_0 = 0.0 - 5.00000000000000000000000000000000000E-01L;

       );
  static const long double SCOS2 = 4.16666666666666666666666666556146073E-02L;
  static const long double SCOS3 =
      (long double temp_var_for_tac_1;
       long double temp_var_for_const_2, temp_var_for_const_3;
       temp_var_for_tac_1 = 0.0 - 1.38888888888888888888309442601939728E-03L;

       );
  static const long double SCOS4 = 2.48015873015862382987049502531095061E-05L;
  static const long double SCOS5 =
      (long double temp_var_for_tac_2;
       long double temp_var_for_const_4, temp_var_for_const_5;
       temp_var_for_tac_2 = 0.0 - 2.75573112601362126593516899592158083E-07L;

       );

  /* cos x ~ ONE + x^2 ( COS1 + COS2 * x^2 + ... + COS7 * x^12 + COS8 * x^14 )
     x in <0,0.1484375>  */
  static const long double COS1 =
      (long double temp_var_for_tac_3;
       long double temp_var_for_const_6, temp_var_for_const_7;
       temp_var_for_tac_3 = 0.0 - 4.99999999999999999999999999999999759E-01L;

       );
  static const long double COS2 = 4.16666666666666666666666666651287795E-02L;
  static const long double COS3 =
      (long double temp_var_for_tac_4;
       long double temp_var_for_const_8, temp_var_for_const_9;
       temp_var_for_tac_4 = 0.0 - 1.38888888888888888888888742314300284E-03L;

       );
  static const long double COS4 = 2.48015873015873015867694002851118210E-05L;
  static const long double COS5 =
      (long double temp_var_for_tac_5;
       long double temp_var_for_const_10, temp_var_for_const_11;
       temp_var_for_tac_5 = 0.0 - 2.75573192239858811636614709689300351E-07L;

       );
  static const long double COS6 = 2.08767569877762248667431926878073669E-09L;
  static const long double COS7 =
      (long double temp_var_for_tac_6;
       long double temp_var_for_const_12, temp_var_for_const_13;
       temp_var_for_tac_6 = 0.0 - 1.14707451049343817400420280514614892E-11L;

       );
  static const long double COS8 = 4.77810092804389587579843296923533297E-14L;

  /* sin x ~ ONE * x + x^3 ( SSIN1 + SSIN2 * x^2 + ... + SSIN4 * x^6 + SSIN5 *
     x^8 )
     x in <0,1/256>  */
  static const long double SSIN1 =
      (long double temp_var_for_tac_7;
       long double temp_var_for_const_14, temp_var_for_const_15;
       temp_var_for_tac_7 = 0.0 - 1.66666666666666666666666666666666659E-01L;

       );
  static const long double SSIN2 = 8.33333333333333333333333333146298442E-03L;
  static const long double SSIN3 =
      (long double temp_var_for_tac_8;
       long double temp_var_for_const_16, temp_var_for_const_17;
       temp_var_for_tac_8 = 0.0 - 1.98412698412698412697726277416810661E-04L;

       );
  static const long double SSIN4 = 2.75573192239848624174178393552189149E-06L;
  static const long double SSIN5 =
      (long double temp_var_for_tac_9;
       long double temp_var_for_const_18, temp_var_for_const_19;
       temp_var_for_tac_9 = 0.0 - 2.50521016467996193495359189395805639E-08L;

       );

#define SINCOSL_COS_HI 0
#define SINCOSL_COS_LO 1
#define SINCOSL_SIN_HI 2
#define SINCOSL_SIN_LO 3

  if (signbit(x)) {
    long double temp_var_for_ext_0;
    long double temp_var_for_tac_10;
    long double temp_var_for_const_20;
    temp_var_for_tac_10 = 0.0 - x;

    temp_var_for_ext_0 = temp_var_for_tac_10;
    computeLdSub((Addr)&temp_var_for_tac_0,
                 {(Addr) &(temp_var_for_const_1 = 0.0),
                  (Addr) &(temp_var_for_const_0 =
                               5.00000000000000000000000000000000000E-01L)},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:36:12");
    computeLdSub((Addr)&temp_var_for_tac_1,
                 {(Addr) &(temp_var_for_const_3 = 0.0),
                  (Addr) &(temp_var_for_const_2 =
                               1.38888888888888888888309442601939728E-03L)},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:39:12");
    computeLdSub((Addr)&temp_var_for_tac_2,
                 {(Addr) &(temp_var_for_const_5 = 0.0),
                  (Addr) &(temp_var_for_const_4 =
                               2.75573112601362126593516899592158083E-07L)},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:42:12");
    computeLdSub((Addr)&temp_var_for_tac_3,
                 {(Addr) &(temp_var_for_const_7 = 0.0),
                  (Addr) &(temp_var_for_const_6 =
                               4.99999999999999999999999999999999759E-01L)},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:47:12");
    computeLdSub((Addr)&temp_var_for_tac_4,
                 {(Addr) &(temp_var_for_const_9 = 0.0),
                  (Addr) &(temp_var_for_const_8 =
                               1.38888888888888888888888742314300284E-03L)},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:50:12");
    computeLdSub((Addr)&temp_var_for_tac_5,
                 {(Addr) &(temp_var_for_const_11 = 0.0),
                  (Addr) &(temp_var_for_const_10 =
                               2.75573192239858811636614709689300351E-07L)},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:53:12");
    computeLdSub((Addr)&temp_var_for_tac_6,
                 {(Addr) &(temp_var_for_const_13 = 0.0),
                  (Addr) &(temp_var_for_const_12 =
                               1.14707451049343817400420280514614892E-11L)},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:56:12");
    computeLdSub((Addr)&temp_var_for_tac_7,
                 {(Addr) &(temp_var_for_const_15 = 0.0),
                  (Addr) &(temp_var_for_const_14 =
                               1.66666666666666666666666666666666659E-01L)},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:63:12");
    computeLdSub((Addr)&temp_var_for_tac_8,
                 {(Addr) &(temp_var_for_const_17 = 0.0),
                  (Addr) &(temp_var_for_const_16 =
                               1.98412698412698412697726277416810661E-04L)},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:66:12");
    computeLdSub((Addr)&temp_var_for_tac_9,
                 {(Addr) &(temp_var_for_const_19 = 0.0),
                  (Addr) &(temp_var_for_const_18 =
                               2.50521016467996193495359189395805639E-08L)},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:69:12");
    computeLdSub((Addr)&temp_var_for_tac_10,
                 {(Addr) &(temp_var_for_const_20 = 0.0), (Addr)&x},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:78:31");
    AssignLd({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_10,
             "/home/shijia/Public/testprogram/k_cosl.c_e.c:78:24");
    ; // x
    /*(x)(x)*/
    x = temp_var_for_ext_0;
    AssignLd({(Addr)&x}, (Addr)&temp_var_for_ext_0,
             "/home/shijia/Public/testprogram/k_cosl.c_e.c:80:7");
    ;
    long double temp_var_for_ext_1;
    long double temp_var_for_tac_11;
    long double temp_var_for_const_21;
    temp_var_for_tac_11 = 0.0 - y;

    temp_var_for_ext_1 = temp_var_for_tac_11;
    computeLdSub((Addr)&temp_var_for_tac_11,
                 {(Addr) &(temp_var_for_const_21 = 0.0), (Addr)&y},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:82:31");
    AssignLd({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_11,
             "/home/shijia/Public/testprogram/k_cosl.c_e.c:82:24");
    ; // y
    /*(y)(y)*/
    y = temp_var_for_ext_1;
    AssignLd({(Addr)&y}, (Addr)&temp_var_for_ext_1,
             "/home/shijia/Public/testprogram/k_cosl.c_e.c:84:7");
    ;
  }
  if (int temp_var_for_tac_12; int temp_var_for_const_22;
      temp_var_for_tac_12 = x < 0.1484375L;

      ) {
    /* Argument is small enough to approximate it by a Chebyshev
       polynomial of degree 16.  */
    if (int temp_var_for_tac_13; int temp_var_for_const_23;
        temp_var_for_tac_13 = x < 0x1p-33L;

        ) {
      if (!((int32_t)x)) {
        long double temp_var_for_ext_2;
        long double temp_var_for_const_24;
        temp_var_for_ext_2 = ONE;
        compute((Addr)&temp_var_for_tac_12,
                {(Addr)&x, (Addr) &(temp_var_for_const_22 = 0.1484375L)},
                "/home/shijia/Public/testprogram/k_cosl.c_e.c:86:9");
        compute((Addr)&temp_var_for_tac_13,
                {(Addr)&x, (Addr) &(temp_var_for_const_23 = 0x1p-33L)},
                "/home/shijia/Public/testprogram/k_cosl.c_e.c:89:11");
        AssignLd({(Addr)&temp_var_for_ext_2},
                 (Addr) &(temp_var_for_const_24 = ONE),
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:92:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_2;
      }
    }
    /* generate inexact */
    long double temp_var_for_tac_14;
    temp_var_for_tac_14 = x * x;

    z = temp_var_for_tac_14;
    computeLdMul((Addr)&temp_var_for_tac_14, {(Addr)&x, (Addr)&x},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:100:11");
    AssignLd({(Addr)&z}, (Addr)&temp_var_for_tac_14,
             "/home/shijia/Public/testprogram/k_cosl.c_e.c:100:7");
    ;
    long double temp_var_for_ext_3;
    long double temp_var_for_tac_15, temp_var_for_tac_16, temp_var_for_tac_17,
        temp_var_for_tac_18, temp_var_for_tac_19, temp_var_for_tac_20,
        temp_var_for_tac_21, temp_var_for_tac_22, temp_var_for_tac_23,
        temp_var_for_tac_24, temp_var_for_tac_25, temp_var_for_tac_26,
        temp_var_for_tac_27, temp_var_for_tac_28, temp_var_for_tac_29,
        temp_var_for_tac_30;
    long double temp_var_for_const_25, temp_var_for_const_26,
        temp_var_for_const_27, temp_var_for_const_28, temp_var_for_const_29,
        temp_var_for_const_30, temp_var_for_const_31, temp_var_for_const_32,
        temp_var_for_const_33;
    temp_var_for_tac_15 = z * COS8;

    temp_var_for_tac_16 = COS7 + temp_var_for_tac_15;

    temp_var_for_tac_17 = z * temp_var_for_tac_16;

    temp_var_for_tac_18 = COS6 + temp_var_for_tac_17;

    temp_var_for_tac_19 = z * temp_var_for_tac_18;

    temp_var_for_tac_20 = COS5 + temp_var_for_tac_19;

    temp_var_for_tac_21 = z * temp_var_for_tac_20;

    temp_var_for_tac_22 = COS4 + temp_var_for_tac_21;

    temp_var_for_tac_23 = z * temp_var_for_tac_22;

    temp_var_for_tac_24 = COS3 + temp_var_for_tac_23;

    temp_var_for_tac_25 = z * temp_var_for_tac_24;

    temp_var_for_tac_26 = COS2 + temp_var_for_tac_25;

    temp_var_for_tac_27 = z * temp_var_for_tac_26;

    temp_var_for_tac_28 = COS1 + temp_var_for_tac_27;

    temp_var_for_tac_29 = z * temp_var_for_tac_28;

    temp_var_for_tac_30 = ONE + temp_var_for_tac_29;

    temp_var_for_ext_3 = temp_var_for_tac_30;
    computeLdMul((Addr)&temp_var_for_tac_15,
                 {(Addr)&z, (Addr) &(temp_var_for_const_25 = COS8)},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:109:64");
    computeLdAdd(
        (Addr)&temp_var_for_tac_16,
        {(Addr) &(temp_var_for_const_26 = COS7), (Addr)&temp_var_for_tac_15},
        "/home/shijia/Public/testprogram/k_cosl.c_e.c:109:60");
    computeLdMul((Addr)&temp_var_for_tac_17,
                 {(Addr)&z, (Addr)&temp_var_for_tac_16},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:109:52");
    computeLdAdd(
        (Addr)&temp_var_for_tac_18,
        {(Addr) &(temp_var_for_const_27 = COS6), (Addr)&temp_var_for_tac_17},
        "/home/shijia/Public/testprogram/k_cosl.c_e.c:109:48");
    computeLdMul((Addr)&temp_var_for_tac_19,
                 {(Addr)&z, (Addr)&temp_var_for_tac_18},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:109:40");
    computeLdAdd(
        (Addr)&temp_var_for_tac_20,
        {(Addr) &(temp_var_for_const_28 = COS5), (Addr)&temp_var_for_tac_19},
        "/home/shijia/Public/testprogram/k_cosl.c_e.c:109:36");
    computeLdMul((Addr)&temp_var_for_tac_21,
                 {(Addr)&z, (Addr)&temp_var_for_tac_20},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:109:28");
    computeLdAdd(
        (Addr)&temp_var_for_tac_22,
        {(Addr) &(temp_var_for_const_29 = COS4), (Addr)&temp_var_for_tac_21},
        "/home/shijia/Public/testprogram/k_cosl.c_e.c:108:31");
    computeLdMul((Addr)&temp_var_for_tac_23,
                 {(Addr)&z, (Addr)&temp_var_for_tac_22},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:108:23");
    computeLdAdd(
        (Addr)&temp_var_for_tac_24,
        {(Addr) &(temp_var_for_const_30 = COS3), (Addr)&temp_var_for_tac_23},
        "/home/shijia/Public/testprogram/k_cosl.c_e.c:107:26");
    computeLdMul((Addr)&temp_var_for_tac_25,
                 {(Addr)&z, (Addr)&temp_var_for_tac_24},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:107:18");
    computeLdAdd(
        (Addr)&temp_var_for_tac_26,
        {(Addr) &(temp_var_for_const_31 = COS2), (Addr)&temp_var_for_tac_25},
        "/home/shijia/Public/testprogram/k_cosl.c_e.c:106:21");
    computeLdMul((Addr)&temp_var_for_tac_27,
                 {(Addr)&z, (Addr)&temp_var_for_tac_26},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:106:13");
    computeLdAdd(
        (Addr)&temp_var_for_tac_28,
        {(Addr) &(temp_var_for_const_32 = COS1), (Addr)&temp_var_for_tac_27},
        "/home/shijia/Public/testprogram/k_cosl.c_e.c:105:16");
    computeLdMul((Addr)&temp_var_for_tac_29,
                 {(Addr)&z, (Addr)&temp_var_for_tac_28},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:104:12");
    computeLdAdd(
        (Addr)&temp_var_for_tac_30,
        {(Addr) &(temp_var_for_const_33 = ONE), (Addr)&temp_var_for_tac_29},
        "/home/shijia/Public/testprogram/k_cosl.c_e.c:103:13");
    AssignLd({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_30,
             "/home/shijia/Public/testprogram/k_cosl.c_e.c:102:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_3;
  } else {
    /* So that we don't have to use too large polynomial,  we find
       l and h such that x = l + h,  where fabsl(l) <= 1.0/256 with 83
       possible values for h.  We look up cosl(h) and sinl(h) in
       pre-computed tables,  compute cosl(l) and sinl(l) using a
       Chebyshev polynomial of degree 10(11) and compute
       cosl(h+l) = cosl(h)cosl(l) - sinl(h)sinl(l).  */
    index = (int)(long double temp_var_for_tac_31, temp_var_for_tac_32,
                  temp_var_for_tac_33, temp_var_for_tac_34;
                  long double temp_var_for_const_34, temp_var_for_const_35,
                  temp_var_for_const_36, temp_var_for_const_37;
                  temp_var_for_tac_31 = 1.0L / 256.0L;

                  temp_var_for_tac_32 = 0.1484375L - temp_var_for_tac_31;

                  temp_var_for_tac_33 = x - temp_var_for_tac_32;

                  temp_var_for_tac_34 = 128 * temp_var_for_tac_33;

                  );
    long double temp_var_for_tac_35, temp_var_for_tac_36;
    long double temp_var_for_const_38, temp_var_for_const_39,
        temp_var_for_const_40;
    temp_var_for_tac_35 = index / 128.0;

    temp_var_for_tac_36 = 0.1484375L + temp_var_for_tac_35;

    h = temp_var_for_tac_36;
    computeLdDiv((Addr)&temp_var_for_tac_31,
                 {(Addr) &(temp_var_for_const_35 = 1.0L),
                  (Addr) &(temp_var_for_const_34 = 256.0L)},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:120:49");
    computeLdSub((Addr)&temp_var_for_tac_32,
                 {(Addr) &(temp_var_for_const_36 = 0.1484375L),
                  (Addr)&temp_var_for_tac_31},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:120:42");
    computeLdSub((Addr)&temp_var_for_tac_33,
                 {(Addr)&x, (Addr)&temp_var_for_tac_32},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:120:28");
    computeLdMul(
        (Addr)&temp_var_for_tac_34,
        {(Addr) &(temp_var_for_const_37 = 128), (Addr)&temp_var_for_tac_33},
        "/home/shijia/Public/testprogram/k_cosl.c_e.c:120:23");
    computeDDiv((Addr)&temp_var_for_tac_35,
                {(Addr) &(temp_var_for_const_39 = index),
                 (Addr) &(temp_var_for_const_38 = 128.0)},
                "/home/shijia/Public/testprogram/k_cosl.c_e.c:121:28");
    computeLdAdd((Addr)&temp_var_for_tac_36,
                 {(Addr) &(temp_var_for_const_40 = 0.1484375L),
                  (Addr)&temp_var_for_tac_35},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:121:20");
    AssignLd({(Addr)&h}, (Addr)&temp_var_for_tac_36,
             "/home/shijia/Public/testprogram/k_cosl.c_e.c:121:7");
    ;
    index *= 4;
    long double temp_var_for_tac_37, temp_var_for_tac_38;
    temp_var_for_tac_37 = h - x;

    temp_var_for_tac_38 = y - temp_var_for_tac_37;

    l = temp_var_for_tac_38;
    computeLdSub((Addr)&temp_var_for_tac_37, {(Addr)&h, (Addr)&x},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:123:16");
    computeLdSub((Addr)&temp_var_for_tac_38,
                 {(Addr)&y, (Addr)&temp_var_for_tac_37},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:123:11");
    AssignLd({(Addr)&l}, (Addr)&temp_var_for_tac_38,
             "/home/shijia/Public/testprogram/k_cosl.c_e.c:123:7");
    ;
    long double temp_var_for_tac_39;
    temp_var_for_tac_39 = l * l;

    z = temp_var_for_tac_39;
    computeLdMul((Addr)&temp_var_for_tac_39, {(Addr)&l, (Addr)&l},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:124:11");
    AssignLd({(Addr)&z}, (Addr)&temp_var_for_tac_39,
             "/home/shijia/Public/testprogram/k_cosl.c_e.c:124:7");
    ;
    long double temp_var_for_tac_40, temp_var_for_tac_41, temp_var_for_tac_42,
        temp_var_for_tac_43, temp_var_for_tac_44, temp_var_for_tac_45,
        temp_var_for_tac_46, temp_var_for_tac_47, temp_var_for_tac_48,
        temp_var_for_tac_49, temp_var_for_tac_50;
    long double temp_var_for_const_41, temp_var_for_const_42,
        temp_var_for_const_43, temp_var_for_const_44, temp_var_for_const_45,
        temp_var_for_const_46;
    temp_var_for_tac_40 = z * SSIN5;

    temp_var_for_tac_41 = SSIN4 + temp_var_for_tac_40;

    temp_var_for_tac_42 = z * temp_var_for_tac_41;

    temp_var_for_tac_43 = SSIN3 + temp_var_for_tac_42;

    temp_var_for_tac_44 = z * temp_var_for_tac_43;

    temp_var_for_tac_45 = SSIN2 + temp_var_for_tac_44;

    temp_var_for_tac_46 = z * temp_var_for_tac_45;

    temp_var_for_tac_47 = SSIN1 + temp_var_for_tac_46;

    temp_var_for_tac_48 = z * temp_var_for_tac_47;

    temp_var_for_tac_49 = ONE + temp_var_for_tac_48;

    temp_var_for_tac_50 = l * temp_var_for_tac_49;

    sin_l = temp_var_for_tac_50;
    computeLdMul((Addr)&temp_var_for_tac_40,
                 {(Addr)&z, (Addr) &(temp_var_for_const_41 = SSIN5)},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:127:68");
    computeLdAdd(
        (Addr)&temp_var_for_tac_41,
        {(Addr) &(temp_var_for_const_42 = SSIN4), (Addr)&temp_var_for_tac_40},
        "/home/shijia/Public/testprogram/k_cosl.c_e.c:127:64");
    computeLdMul((Addr)&temp_var_for_tac_42,
                 {(Addr)&z, (Addr)&temp_var_for_tac_41},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:127:55");
    computeLdAdd(
        (Addr)&temp_var_for_tac_43,
        {(Addr) &(temp_var_for_const_43 = SSIN3), (Addr)&temp_var_for_tac_42},
        "/home/shijia/Public/testprogram/k_cosl.c_e.c:127:51");
    computeLdMul((Addr)&temp_var_for_tac_44,
                 {(Addr)&z, (Addr)&temp_var_for_tac_43},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:127:42");
    computeLdAdd(
        (Addr)&temp_var_for_tac_45,
        {(Addr) &(temp_var_for_const_44 = SSIN2), (Addr)&temp_var_for_tac_44},
        "/home/shijia/Public/testprogram/k_cosl.c_e.c:127:38");
    computeLdMul((Addr)&temp_var_for_tac_46,
                 {(Addr)&z, (Addr)&temp_var_for_tac_45},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:127:29");
    computeLdAdd(
        (Addr)&temp_var_for_tac_47,
        {(Addr) &(temp_var_for_const_45 = SSIN1), (Addr)&temp_var_for_tac_46},
        "/home/shijia/Public/testprogram/k_cosl.c_e.c:127:25");
    computeLdMul((Addr)&temp_var_for_tac_48,
                 {(Addr)&z, (Addr)&temp_var_for_tac_47},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:127:16");
    computeLdAdd(
        (Addr)&temp_var_for_tac_49,
        {(Addr) &(temp_var_for_const_46 = ONE), (Addr)&temp_var_for_tac_48},
        "/home/shijia/Public/testprogram/k_cosl.c_e.c:126:18");
    computeLdMul((Addr)&temp_var_for_tac_50,
                 {(Addr)&l, (Addr)&temp_var_for_tac_49},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:126:11");
    AssignLd({(Addr)&sin_l}, (Addr)&temp_var_for_tac_50,
             "/home/shijia/Public/testprogram/k_cosl.c_e.c:125:11");
    ;
    long double temp_var_for_tac_51, temp_var_for_tac_52, temp_var_for_tac_53,
        temp_var_for_tac_54, temp_var_for_tac_55, temp_var_for_tac_56,
        temp_var_for_tac_57, temp_var_for_tac_58, temp_var_for_tac_59;
    long double temp_var_for_const_47, temp_var_for_const_48,
        temp_var_for_const_49, temp_var_for_const_50, temp_var_for_const_51;
    temp_var_for_tac_51 = z * SCOS5;

    temp_var_for_tac_52 = SCOS4 + temp_var_for_tac_51;

    temp_var_for_tac_53 = z * temp_var_for_tac_52;

    temp_var_for_tac_54 = SCOS3 + temp_var_for_tac_53;

    temp_var_for_tac_55 = z * temp_var_for_tac_54;

    temp_var_for_tac_56 = SCOS2 + temp_var_for_tac_55;

    temp_var_for_tac_57 = z * temp_var_for_tac_56;

    temp_var_for_tac_58 = SCOS1 + temp_var_for_tac_57;

    temp_var_for_tac_59 = z * temp_var_for_tac_58;

    cos_l_m1 = temp_var_for_tac_59;
    computeLdMul((Addr)&temp_var_for_tac_51,
                 {(Addr)&z, (Addr) &(temp_var_for_const_47 = SCOS5)},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:129:63");
    computeLdAdd(
        (Addr)&temp_var_for_tac_52,
        {(Addr) &(temp_var_for_const_48 = SCOS4), (Addr)&temp_var_for_tac_51},
        "/home/shijia/Public/testprogram/k_cosl.c_e.c:129:59");
    computeLdMul((Addr)&temp_var_for_tac_53,
                 {(Addr)&z, (Addr)&temp_var_for_tac_52},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:129:50");
    computeLdAdd(
        (Addr)&temp_var_for_tac_54,
        {(Addr) &(temp_var_for_const_49 = SCOS3), (Addr)&temp_var_for_tac_53},
        "/home/shijia/Public/testprogram/k_cosl.c_e.c:129:46");
    computeLdMul((Addr)&temp_var_for_tac_55,
                 {(Addr)&z, (Addr)&temp_var_for_tac_54},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:129:37");
    computeLdAdd(
        (Addr)&temp_var_for_tac_56,
        {(Addr) &(temp_var_for_const_50 = SCOS2), (Addr)&temp_var_for_tac_55},
        "/home/shijia/Public/testprogram/k_cosl.c_e.c:129:33");
    computeLdMul((Addr)&temp_var_for_tac_57,
                 {(Addr)&z, (Addr)&temp_var_for_tac_56},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:129:24");
    computeLdAdd(
        (Addr)&temp_var_for_tac_58,
        {(Addr) &(temp_var_for_const_51 = SCOS1), (Addr)&temp_var_for_tac_57},
        "/home/shijia/Public/testprogram/k_cosl.c_e.c:129:20");
    computeLdMul((Addr)&temp_var_for_tac_59,
                 {(Addr)&z, (Addr)&temp_var_for_tac_58},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:129:11");
    AssignLd({(Addr)&cos_l_m1}, (Addr)&temp_var_for_tac_59,
             "/home/shijia/Public/testprogram/k_cosl.c_e.c:128:14");
    ;
    long double temp_var_for_ext_4;
    long double temp_var_for_tac_60, temp_var_for_tac_61, temp_var_for_tac_62,
        temp_var_for_tac_63, temp_var_for_tac_64;
    long double temp_var_for_const_52, temp_var_for_const_53,
        temp_var_for_const_54, temp_var_for_const_55;
    temp_var_for_tac_60 = __sincosl_table[index + SINCOSL_SIN_HI] * sin_l;

    temp_var_for_tac_61 = __sincosl_table[index + SINCOSL_COS_HI] * cos_l_m1;

    temp_var_for_tac_62 = temp_var_for_tac_60 - temp_var_for_tac_61;

    temp_var_for_tac_63 =
        __sincosl_table[index + SINCOSL_COS_LO] - temp_var_for_tac_62;

    temp_var_for_tac_64 =
        __sincosl_table[index + SINCOSL_COS_HI] + temp_var_for_tac_63;

    temp_var_for_ext_4 = temp_var_for_tac_64;
    computeLdMul((Addr)&temp_var_for_tac_60,
                 {(Addr) &(temp_var_for_const_52 =
                               __sincosl_table[index + SINCOSL_SIN_HI]),
                  (Addr)&sin_l},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:133:68");
    computeLdMul((Addr)&temp_var_for_tac_61,
                 {(Addr) &(temp_var_for_const_53 =
                               __sincosl_table[index + SINCOSL_COS_HI]),
                  (Addr)&cos_l_m1},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:134:68");
    computeLdSub((Addr)&temp_var_for_tac_62,
                 {(Addr)&temp_var_for_tac_60, (Addr)&temp_var_for_tac_61},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:133:76");
    computeLdSub((Addr)&temp_var_for_tac_63,
                 {(Addr) &(temp_var_for_const_54 =
                               __sincosl_table[index + SINCOSL_COS_LO]),
                  (Addr)&temp_var_for_tac_62},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:132:67");
    computeLdAdd((Addr)&temp_var_for_tac_64,
                 {(Addr) &(temp_var_for_const_55 =
                               __sincosl_table[index + SINCOSL_COS_HI]),
                  (Addr)&temp_var_for_tac_63},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:131:66");
    AssignLd({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_64,
             "/home/shijia/Public/testprogram/k_cosl.c_e.c:131:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_4;
  }

#undef SINCOSL_COS_HI
#undef SINCOSL_COS_LO
#undef SINCOSL_SIN_HI
#undef SINCOSL_SIN_LO
}
