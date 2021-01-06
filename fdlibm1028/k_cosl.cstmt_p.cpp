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
      (0.0 - 5.00000000000000000000000000000000000E-01L);
  long double temp_var_for_const_0, temp_var_for_const_1;
  ;
  static const long double SCOS2 = 4.16666666666666666666666666556146073E-02L;
  static const long double SCOS3 =
      (0.0 - 1.38888888888888888888309442601939728E-03L);
  long double temp_var_for_const_2, temp_var_for_const_3;
  long double temp_var_for_tac_0;
  computeLdSub((Addr)&temp_var_for_tac_0,
               {(Addr) &(temp_var_for_const_1 = 0.0),
                (Addr) &(temp_var_for_const_0 =
                             5.00000000000000000000000000000000000E-01L)},
               "/home/shijia/Public/testprogram/k_cosl.c_e.c:39:12");
  ;
  static const long double SCOS4 = 2.48015873015862382987049502531095061E-05L;
  static const long double SCOS5 =
      (0.0 - 2.75573112601362126593516899592158083E-07L);
  long double temp_var_for_const_4, temp_var_for_const_5;
  long double temp_var_for_tac_1;
  computeLdSub((Addr)&temp_var_for_tac_1,
               {(Addr) &(temp_var_for_const_3 = 0.0),
                (Addr) &(temp_var_for_const_2 =
                             1.38888888888888888888309442601939728E-03L)},
               "/home/shijia/Public/testprogram/k_cosl.c_e.c:42:12");
  ;

  /* cos x ~ ONE + x^2 ( COS1 + COS2 * x^2 + ... + COS7 * x^12 + COS8 * x^14 )
     x in <0,0.1484375>  */
  static const long double COS1 =
      (0.0 - 4.99999999999999999999999999999999759E-01L);
  long double temp_var_for_const_6, temp_var_for_const_7;
  long double temp_var_for_tac_2;
  computeLdSub((Addr)&temp_var_for_tac_2,
               {(Addr) &(temp_var_for_const_5 = 0.0),
                (Addr) &(temp_var_for_const_4 =
                             2.75573112601362126593516899592158083E-07L)},
               "/home/shijia/Public/testprogram/k_cosl.c_e.c:47:12");
  ;
  static const long double COS2 = 4.16666666666666666666666666651287795E-02L;
  static const long double COS3 =
      (0.0 - 1.38888888888888888888888742314300284E-03L);
  long double temp_var_for_const_8, temp_var_for_const_9;
  long double temp_var_for_tac_3;
  computeLdSub((Addr)&temp_var_for_tac_3,
               {(Addr) &(temp_var_for_const_7 = 0.0),
                (Addr) &(temp_var_for_const_6 =
                             4.99999999999999999999999999999999759E-01L)},
               "/home/shijia/Public/testprogram/k_cosl.c_e.c:50:12");
  ;
  static const long double COS4 = 2.48015873015873015867694002851118210E-05L;
  static const long double COS5 =
      (0.0 - 2.75573192239858811636614709689300351E-07L);
  long double temp_var_for_const_10, temp_var_for_const_11;
  long double temp_var_for_tac_4;
  computeLdSub((Addr)&temp_var_for_tac_4,
               {(Addr) &(temp_var_for_const_9 = 0.0),
                (Addr) &(temp_var_for_const_8 =
                             1.38888888888888888888888742314300284E-03L)},
               "/home/shijia/Public/testprogram/k_cosl.c_e.c:53:12");
  ;
  static const long double COS6 = 2.08767569877762248667431926878073669E-09L;
  static const long double COS7 =
      (0.0 - 1.14707451049343817400420280514614892E-11L);
  long double temp_var_for_const_12, temp_var_for_const_13;
  long double temp_var_for_tac_5;
  computeLdSub((Addr)&temp_var_for_tac_5,
               {(Addr) &(temp_var_for_const_11 = 0.0),
                (Addr) &(temp_var_for_const_10 =
                             2.75573192239858811636614709689300351E-07L)},
               "/home/shijia/Public/testprogram/k_cosl.c_e.c:56:12");
  ;
  static const long double COS8 = 4.77810092804389587579843296923533297E-14L;

  /* sin x ~ ONE * x + x^3 ( SSIN1 + SSIN2 * x^2 + ... + SSIN4 * x^6 + SSIN5 *
     x^8 )
     x in <0,1/256>  */
  static const long double SSIN1 =
      (0.0 - 1.66666666666666666666666666666666659E-01L);
  long double temp_var_for_const_14, temp_var_for_const_15;
  long double temp_var_for_tac_6;
  computeLdSub((Addr)&temp_var_for_tac_6,
               {(Addr) &(temp_var_for_const_13 = 0.0),
                (Addr) &(temp_var_for_const_12 =
                             1.14707451049343817400420280514614892E-11L)},
               "/home/shijia/Public/testprogram/k_cosl.c_e.c:63:12");
  ;
  static const long double SSIN2 = 8.33333333333333333333333333146298442E-03L;
  static const long double SSIN3 =
      (0.0 - 1.98412698412698412697726277416810661E-04L);
  long double temp_var_for_const_16, temp_var_for_const_17;
  long double temp_var_for_tac_7;
  computeLdSub((Addr)&temp_var_for_tac_7,
               {(Addr) &(temp_var_for_const_15 = 0.0),
                (Addr) &(temp_var_for_const_14 =
                             1.66666666666666666666666666666666659E-01L)},
               "/home/shijia/Public/testprogram/k_cosl.c_e.c:66:12");
  ;
  static const long double SSIN4 = 2.75573192239848624174178393552189149E-06L;
  static const long double SSIN5 =
      (0.0 - 2.50521016467996193495359189395805639E-08L);
  long double temp_var_for_const_18, temp_var_for_const_19;
  long double temp_var_for_tac_8;
  computeLdSub((Addr)&temp_var_for_tac_8,
               {(Addr) &(temp_var_for_const_17 = 0.0),
                (Addr) &(temp_var_for_const_16 =
                             1.98412698412698412697726277416810661E-04L)},
               "/home/shijia/Public/testprogram/k_cosl.c_e.c:69:12");
  ;

#define SINCOSL_COS_HI 0
#define SINCOSL_COS_LO 1
#define SINCOSL_SIN_HI 2
#define SINCOSL_SIN_LO 3

  if (signbit(x)) {
    long double temp_var_for_ext_0;
    temp_var_for_ext_0 = (0.0 - x);
    long double temp_var_for_const_20;
    long double temp_var_for_tac_9;
    computeLdSub((Addr)&temp_var_for_tac_9,
                 {(Addr) &(temp_var_for_const_19 = 0.0),
                  (Addr) &(temp_var_for_const_18 =
                               2.50521016467996193495359189395805639E-08L)},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:78:31");
    computeLdSub((Addr)&temp_var_for_ext_0,
                 {(Addr) &(temp_var_for_const_20 = 0.0), (Addr)&x},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:78:24"); // x
    /*(x)(x)*/
    x = temp_var_for_ext_0;
    AssignLd({(Addr)&x}, (Addr)&temp_var_for_ext_0,
             "/home/shijia/Public/testprogram/k_cosl.c_e.c:80:7");
    long double temp_var_for_ext_1;
    temp_var_for_ext_1 = (0.0 - y);
    long double temp_var_for_const_21;
    computeLdSub((Addr)&temp_var_for_ext_1,
                 {(Addr) &(temp_var_for_const_21 = 0.0), (Addr)&y},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:82:24"); // y
    /*(y)(y)*/
    y = temp_var_for_ext_1;
    AssignLd({(Addr)&y}, (Addr)&temp_var_for_ext_1,
             "/home/shijia/Public/testprogram/k_cosl.c_e.c:84:7");
  }
  if (x < 0.1484375L) {
    /* Argument is small enough to approximate it by a Chebyshev
       polynomial of degree 16.  */
    if (x < 0x1p-33L)
      if (!((int32_t)x))
        return ONE; /* generate inexact */
    z = x * x;
    computeLdMul((Addr)&z, {(Addr)&x, (Addr)&x},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:92:7");
    long double temp_var_for_ext_2;
    temp_var_for_ext_2 =
        ONE +
        (z *
         (COS1 +
          z * (COS2 +
               z * (COS3 +
                    z * (COS4 +
                         z * (COS5 + z * (COS6 + z * (COS7 + z * COS8))))))));
    long double temp_var_for_const_22, temp_var_for_const_23,
        temp_var_for_const_24, temp_var_for_const_25, temp_var_for_const_26,
        temp_var_for_const_27, temp_var_for_const_28, temp_var_for_const_29,
        temp_var_for_const_30;
    long double temp_var_for_tac_10, temp_var_for_tac_11, temp_var_for_tac_12,
        temp_var_for_tac_13, temp_var_for_tac_14, temp_var_for_tac_15,
        temp_var_for_tac_16, temp_var_for_tac_17, temp_var_for_tac_18,
        temp_var_for_tac_19, temp_var_for_tac_20, temp_var_for_tac_21,
        temp_var_for_tac_22, temp_var_for_tac_23, temp_var_for_tac_24;
    computeLdMul((Addr)&temp_var_for_tac_10,
                 {(Addr)&z, (Addr) &(temp_var_for_const_22 = COS8)},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:101:60");
    computeLdAdd(
        (Addr)&temp_var_for_tac_11,
        {(Addr) &(temp_var_for_const_23 = COS7), (Addr)&temp_var_for_tac_10},
        "/home/shijia/Public/testprogram/k_cosl.c_e.c:101:52");
    computeLdMul((Addr)&temp_var_for_tac_12,
                 {(Addr)&z, (Addr)&temp_var_for_tac_11},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:101:48");
    computeLdAdd(
        (Addr)&temp_var_for_tac_13,
        {(Addr) &(temp_var_for_const_24 = COS6), (Addr)&temp_var_for_tac_12},
        "/home/shijia/Public/testprogram/k_cosl.c_e.c:101:40");
    computeLdMul((Addr)&temp_var_for_tac_14,
                 {(Addr)&z, (Addr)&temp_var_for_tac_13},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:101:36");
    computeLdAdd(
        (Addr)&temp_var_for_tac_15,
        {(Addr) &(temp_var_for_const_25 = COS5), (Addr)&temp_var_for_tac_14},
        "/home/shijia/Public/testprogram/k_cosl.c_e.c:101:28");
    computeLdMul((Addr)&temp_var_for_tac_16,
                 {(Addr)&z, (Addr)&temp_var_for_tac_15},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:100:31");
    computeLdAdd(
        (Addr)&temp_var_for_tac_17,
        {(Addr) &(temp_var_for_const_26 = COS4), (Addr)&temp_var_for_tac_16},
        "/home/shijia/Public/testprogram/k_cosl.c_e.c:100:23");
    computeLdMul((Addr)&temp_var_for_tac_18,
                 {(Addr)&z, (Addr)&temp_var_for_tac_17},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:99:26");
    computeLdAdd(
        (Addr)&temp_var_for_tac_19,
        {(Addr) &(temp_var_for_const_27 = COS3), (Addr)&temp_var_for_tac_18},
        "/home/shijia/Public/testprogram/k_cosl.c_e.c:99:18");
    computeLdMul((Addr)&temp_var_for_tac_20,
                 {(Addr)&z, (Addr)&temp_var_for_tac_19},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:98:21");
    computeLdAdd(
        (Addr)&temp_var_for_tac_21,
        {(Addr) &(temp_var_for_const_28 = COS2), (Addr)&temp_var_for_tac_20},
        "/home/shijia/Public/testprogram/k_cosl.c_e.c:98:13");
    computeLdMul((Addr)&temp_var_for_tac_22,
                 {(Addr)&z, (Addr)&temp_var_for_tac_21},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:97:16");
    computeLdAdd(
        (Addr)&temp_var_for_tac_23,
        {(Addr) &(temp_var_for_const_29 = COS1), (Addr)&temp_var_for_tac_22},
        "/home/shijia/Public/testprogram/k_cosl.c_e.c:96:12");
    computeLdMul((Addr)&temp_var_for_tac_24,
                 {(Addr)&z, (Addr)&temp_var_for_tac_23},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:95:13");
    computeLdAdd(
        (Addr)&temp_var_for_ext_2,
        {(Addr) &(temp_var_for_const_30 = ONE), (Addr)&temp_var_for_tac_24},
        "/home/shijia/Public/testprogram/k_cosl.c_e.c:94:24");
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  } else {
    /* So that we don't have to use too large polynomial,  we find
       l and h such that x = l + h,  where fabsl(l) <= 1.0/256 with 83
       possible values for h.  We look up cosl(h) and sinl(h) in
       pre-computed tables,  compute cosl(l) and sinl(l) using a
       Chebyshev polynomial of degree 10(11) and compute
       cosl(h+l) = cosl(h)cosl(l) - sinl(h)sinl(l).  */
    index = (int)(128 * (x - (0.1484375L - 1.0L / 256.0L)));
    long double temp_var_for_const_31, temp_var_for_const_32,
        temp_var_for_const_33, temp_var_for_const_34;
    long double temp_var_for_tac_25, temp_var_for_tac_26, temp_var_for_tac_27;
    computeLdDiv((Addr)&temp_var_for_tac_25,
                 {(Addr) &(temp_var_for_const_32 = 1.0L),
                  (Addr) &(temp_var_for_const_31 = 256.0L)},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:112:42");
    computeLdSub((Addr)&temp_var_for_tac_26,
                 {(Addr) &(temp_var_for_const_33 = 0.1484375L),
                  (Addr)&temp_var_for_tac_25},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:112:28");
    computeLdSub((Addr)&temp_var_for_tac_27,
                 {(Addr)&x, (Addr)&temp_var_for_tac_26},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:112:23");
    ;
    h = 0.1484375L + index / 128.0;
    long double temp_var_for_const_35, temp_var_for_const_36,
        temp_var_for_const_37;
    long double temp_var_for_tac_28, temp_var_for_tac_29;
    computeDMul(
        (Addr)&temp_var_for_tac_28,
        {(Addr) &(temp_var_for_const_34 = 128), (Addr)&temp_var_for_tac_27},
        "/home/shijia/Public/testprogram/k_cosl.c_e.c:113:28");
    computeLdDiv((Addr)&temp_var_for_tac_29,
                 {(Addr) &(temp_var_for_const_36 = index),
                  (Addr) &(temp_var_for_const_35 = 128.0)},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:113:20");
    computeLdAdd((Addr)&h, {(Addr) &(temp_var_for_const_37 = 0.1484375L),
                            (Addr)&temp_var_for_tac_29},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:113:7");
    index *= 4;
    l = y - (h - x);
    long double temp_var_for_tac_30;
    computeLdSub((Addr)&temp_var_for_tac_30, {(Addr)&h, (Addr)&x},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:115:11");
    computeLdSub((Addr)&l, {(Addr)&y, (Addr)&temp_var_for_tac_30},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:115:7");
    z = l * l;
    computeLdMul((Addr)&z, {(Addr)&l, (Addr)&l},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:116:7");
    sin_l =
        l * (ONE +
             z * (SSIN1 + z * (SSIN2 + z * (SSIN3 + z * (SSIN4 + z * SSIN5)))));
    long double temp_var_for_const_38, temp_var_for_const_39,
        temp_var_for_const_40, temp_var_for_const_41, temp_var_for_const_42,
        temp_var_for_const_43;
    long double temp_var_for_tac_31, temp_var_for_tac_32, temp_var_for_tac_33,
        temp_var_for_tac_34, temp_var_for_tac_35, temp_var_for_tac_36,
        temp_var_for_tac_37, temp_var_for_tac_38, temp_var_for_tac_39,
        temp_var_for_tac_40;
    computeLdMul((Addr)&temp_var_for_tac_31,
                 {(Addr)&z, (Addr) &(temp_var_for_const_38 = SSIN5)},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:119:64");
    computeLdAdd(
        (Addr)&temp_var_for_tac_32,
        {(Addr) &(temp_var_for_const_39 = SSIN4), (Addr)&temp_var_for_tac_31},
        "/home/shijia/Public/testprogram/k_cosl.c_e.c:119:55");
    computeLdMul((Addr)&temp_var_for_tac_33,
                 {(Addr)&z, (Addr)&temp_var_for_tac_32},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:119:51");
    computeLdAdd(
        (Addr)&temp_var_for_tac_34,
        {(Addr) &(temp_var_for_const_40 = SSIN3), (Addr)&temp_var_for_tac_33},
        "/home/shijia/Public/testprogram/k_cosl.c_e.c:119:42");
    computeLdMul((Addr)&temp_var_for_tac_35,
                 {(Addr)&z, (Addr)&temp_var_for_tac_34},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:119:38");
    computeLdAdd(
        (Addr)&temp_var_for_tac_36,
        {(Addr) &(temp_var_for_const_41 = SSIN2), (Addr)&temp_var_for_tac_35},
        "/home/shijia/Public/testprogram/k_cosl.c_e.c:119:29");
    computeLdMul((Addr)&temp_var_for_tac_37,
                 {(Addr)&z, (Addr)&temp_var_for_tac_36},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:119:25");
    computeLdAdd(
        (Addr)&temp_var_for_tac_38,
        {(Addr) &(temp_var_for_const_42 = SSIN1), (Addr)&temp_var_for_tac_37},
        "/home/shijia/Public/testprogram/k_cosl.c_e.c:119:16");
    computeLdMul((Addr)&temp_var_for_tac_39,
                 {(Addr)&z, (Addr)&temp_var_for_tac_38},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:118:18");
    computeLdAdd(
        (Addr)&temp_var_for_tac_40,
        {(Addr) &(temp_var_for_const_43 = ONE), (Addr)&temp_var_for_tac_39},
        "/home/shijia/Public/testprogram/k_cosl.c_e.c:118:11");
    computeLdMul((Addr)&sin_l, {(Addr)&l, (Addr)&temp_var_for_tac_40},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:117:11");
    cos_l_m1 =
        z * (SCOS1 + z * (SCOS2 + z * (SCOS3 + z * (SCOS4 + z * SCOS5))));
    long double temp_var_for_const_44, temp_var_for_const_45,
        temp_var_for_const_46, temp_var_for_const_47, temp_var_for_const_48;
    long double temp_var_for_tac_41, temp_var_for_tac_42, temp_var_for_tac_43,
        temp_var_for_tac_44, temp_var_for_tac_45, temp_var_for_tac_46,
        temp_var_for_tac_47, temp_var_for_tac_48;
    computeLdMul((Addr)&temp_var_for_tac_41,
                 {(Addr)&z, (Addr) &(temp_var_for_const_44 = SCOS5)},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:121:59");
    computeLdAdd(
        (Addr)&temp_var_for_tac_42,
        {(Addr) &(temp_var_for_const_45 = SCOS4), (Addr)&temp_var_for_tac_41},
        "/home/shijia/Public/testprogram/k_cosl.c_e.c:121:50");
    computeLdMul((Addr)&temp_var_for_tac_43,
                 {(Addr)&z, (Addr)&temp_var_for_tac_42},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:121:46");
    computeLdAdd(
        (Addr)&temp_var_for_tac_44,
        {(Addr) &(temp_var_for_const_46 = SCOS3), (Addr)&temp_var_for_tac_43},
        "/home/shijia/Public/testprogram/k_cosl.c_e.c:121:37");
    computeLdMul((Addr)&temp_var_for_tac_45,
                 {(Addr)&z, (Addr)&temp_var_for_tac_44},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:121:33");
    computeLdAdd(
        (Addr)&temp_var_for_tac_46,
        {(Addr) &(temp_var_for_const_47 = SCOS2), (Addr)&temp_var_for_tac_45},
        "/home/shijia/Public/testprogram/k_cosl.c_e.c:121:24");
    computeLdMul((Addr)&temp_var_for_tac_47,
                 {(Addr)&z, (Addr)&temp_var_for_tac_46},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:121:20");
    computeLdAdd(
        (Addr)&temp_var_for_tac_48,
        {(Addr) &(temp_var_for_const_48 = SCOS1), (Addr)&temp_var_for_tac_47},
        "/home/shijia/Public/testprogram/k_cosl.c_e.c:121:11");
    computeLdMul((Addr)&cos_l_m1, {(Addr)&z, (Addr)&temp_var_for_tac_48},
                 "/home/shijia/Public/testprogram/k_cosl.c_e.c:120:14");
    return __sincosl_table[index + SINCOSL_COS_HI] +
           (__sincosl_table[index + SINCOSL_COS_LO] -
            (__sincosl_table[index + SINCOSL_SIN_HI] * sin_l -
             __sincosl_table[index + SINCOSL_COS_HI] * cos_l_m1));
  }

#undef SINCOSL_COS_HI
#undef SINCOSL_COS_LO
#undef SINCOSL_SIN_HI
#undef SINCOSL_SIN_LO
}
