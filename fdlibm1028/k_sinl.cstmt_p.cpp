#include "../ScDebug/scdebug.h"
/* Quad-precision floating point sine on <-pi/4,pi/4>.
   Copyright (C) 1999-2013 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Based on quad-precision sine by Jakub Jelinek <jj@ultra.linux.cz>

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

/* The polynomials have not been optimized for extended-precision and
   may contain more terms than needed.  */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

long double __kernel_sinl(long double x, long double y, int iy) {
  long double absx, h, l, z, sin_l, cos_l_m1;
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
               "/home/shijia/Public/testprogram/k_sinl.c_e.c:42:12");
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
               "/home/shijia/Public/testprogram/k_sinl.c_e.c:45:12");
  ;

  /* sin x ~ ONE * x + x^3 ( SIN1 + SIN2 * x^2 + ... + SIN7 * x^12 + SIN8 * x^14
     )
     x in <0,0.1484375>  */
  static const long double SIN1 =
      (0.0 - 1.66666666666666666666666666666666538e-01L);
  long double temp_var_for_const_6, temp_var_for_const_7;
  long double temp_var_for_tac_2;
  computeLdSub((Addr)&temp_var_for_tac_2,
               {(Addr) &(temp_var_for_const_5 = 0.0),
                (Addr) &(temp_var_for_const_4 =
                             2.75573112601362126593516899592158083E-07L)},
               "/home/shijia/Public/testprogram/k_sinl.c_e.c:51:12");
  ;
  static const long double SIN2 = 8.33333333333333333333333333307532934e-03L;
  static const long double SIN3 =
      (0.0 - 1.98412698412698412698412534478712057e-04L);
  long double temp_var_for_const_8, temp_var_for_const_9;
  long double temp_var_for_tac_3;
  computeLdSub((Addr)&temp_var_for_tac_3,
               {(Addr) &(temp_var_for_const_7 = 0.0),
                (Addr) &(temp_var_for_const_6 =
                             1.66666666666666666666666666666666538e-01L)},
               "/home/shijia/Public/testprogram/k_sinl.c_e.c:54:12");
  ;
  static const long double SIN4 = 2.75573192239858906520896496653095890e-06L;
  static const long double SIN5 =
      (0.0 - 2.50521083854417116999224301266655662e-08L);
  long double temp_var_for_const_10, temp_var_for_const_11;
  long double temp_var_for_tac_4;
  computeLdSub((Addr)&temp_var_for_tac_4,
               {(Addr) &(temp_var_for_const_9 = 0.0),
                (Addr) &(temp_var_for_const_8 =
                             1.98412698412698412698412534478712057e-04L)},
               "/home/shijia/Public/testprogram/k_sinl.c_e.c:57:12");
  ;
  static const long double SIN6 = 1.60590438367608957516841576404938118e-10L;
  static const long double SIN7 =
      (0.0 - 7.64716343504264506714019494041582610e-13L);
  long double temp_var_for_const_12, temp_var_for_const_13;
  long double temp_var_for_tac_5;
  computeLdSub((Addr)&temp_var_for_tac_5,
               {(Addr) &(temp_var_for_const_11 = 0.0),
                (Addr) &(temp_var_for_const_10 =
                             2.50521083854417116999224301266655662e-08L)},
               "/home/shijia/Public/testprogram/k_sinl.c_e.c:60:12");
  ;
  static const long double SIN8 = 2.81068754939739570236322404393398135e-15L;

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
                             7.64716343504264506714019494041582610e-13L)},
               "/home/shijia/Public/testprogram/k_sinl.c_e.c:67:12");
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
               "/home/shijia/Public/testprogram/k_sinl.c_e.c:70:12");
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
               "/home/shijia/Public/testprogram/k_sinl.c_e.c:73:12");
  ;

#define SINCOSL_COS_HI 0
#define SINCOSL_COS_LO 1
#define SINCOSL_SIN_HI 2
#define SINCOSL_SIN_LO 3

  absx = __ieee754_fabsl(x);
  long double temp_var_for_const_20;
  long double temp_var_for_tac_9;
  computeLdSub((Addr)&temp_var_for_tac_9,
               {(Addr) &(temp_var_for_const_19 = 0.0),
                (Addr) &(temp_var_for_const_18 =
                             2.50521016467996193495359189395805639E-08L)},
               "toString(biExpr->getExprLoc())");
AssignLd({(Addr)&absx},(Addr)&(temp_var_for_const_20=__ieee754_fabsl(getFVbyShadow<int>((Addr)&x)),"/home/shijia/Public/testprogram/k_sinl.c_e.c:80:8");
  if (absx < 0.1484375L) {
    /* Argument is small enough to approximate it by a Chebyshev
       polynomial of degree 17.  */
    if (absx < 0x1p-33L)
      if (!((int32_t)x))
        return x; /* generate inexact */
    z = x * x;
    computeLdMul((Addr)&z, {(Addr)&x, (Addr)&x},
                 "/home/shijia/Public/testprogram/k_sinl.c_e.c:87:7");
    long double temp_var_for_ext_0;
    temp_var_for_ext_0 =
        x +
        (x *
         (z *
          (SIN1 +
           z * (SIN2 +
                z * (SIN3 +
                     z * (SIN4 +
                          z * (SIN5 + z * (SIN6 + z * (SIN7 + z * SIN8)))))))));
    long double temp_var_for_const_21, temp_var_for_const_22,
        temp_var_for_const_23, temp_var_for_const_24, temp_var_for_const_25,
        temp_var_for_const_26, temp_var_for_const_27, temp_var_for_const_28;
    long double temp_var_for_tac_10, temp_var_for_tac_11, temp_var_for_tac_12,
        temp_var_for_tac_13, temp_var_for_tac_14, temp_var_for_tac_15,
        temp_var_for_tac_16, temp_var_for_tac_17, temp_var_for_tac_18,
        temp_var_for_tac_19, temp_var_for_tac_20, temp_var_for_tac_21,
        temp_var_for_tac_22, temp_var_for_tac_23, temp_var_for_tac_24;
    computeLdMul((Addr)&temp_var_for_tac_10,
                 {(Addr)&z, (Addr) &(temp_var_for_const_21 = SIN8)},
                 "/home/shijia/Public/testprogram/k_sinl.c_e.c:97:61");
    computeLdAdd(
        (Addr)&temp_var_for_tac_11,
        {(Addr) &(temp_var_for_const_22 = SIN7), (Addr)&temp_var_for_tac_10},
        "/home/shijia/Public/testprogram/k_sinl.c_e.c:97:53");
    computeLdMul((Addr)&temp_var_for_tac_12,
                 {(Addr)&z, (Addr)&temp_var_for_tac_11},
                 "/home/shijia/Public/testprogram/k_sinl.c_e.c:97:49");
    computeLdAdd(
        (Addr)&temp_var_for_tac_13,
        {(Addr) &(temp_var_for_const_23 = SIN6), (Addr)&temp_var_for_tac_12},
        "/home/shijia/Public/testprogram/k_sinl.c_e.c:97:41");
    computeLdMul((Addr)&temp_var_for_tac_14,
                 {(Addr)&z, (Addr)&temp_var_for_tac_13},
                 "/home/shijia/Public/testprogram/k_sinl.c_e.c:97:37");
    computeLdAdd(
        (Addr)&temp_var_for_tac_15,
        {(Addr) &(temp_var_for_const_24 = SIN5), (Addr)&temp_var_for_tac_14},
        "/home/shijia/Public/testprogram/k_sinl.c_e.c:97:29");
    computeLdMul((Addr)&temp_var_for_tac_16,
                 {(Addr)&z, (Addr)&temp_var_for_tac_15},
                 "/home/shijia/Public/testprogram/k_sinl.c_e.c:96:32");
    computeLdAdd(
        (Addr)&temp_var_for_tac_17,
        {(Addr) &(temp_var_for_const_25 = SIN4), (Addr)&temp_var_for_tac_16},
        "/home/shijia/Public/testprogram/k_sinl.c_e.c:96:24");
    computeLdMul((Addr)&temp_var_for_tac_18,
                 {(Addr)&z, (Addr)&temp_var_for_tac_17},
                 "/home/shijia/Public/testprogram/k_sinl.c_e.c:95:27");
    computeLdAdd(
        (Addr)&temp_var_for_tac_19,
        {(Addr) &(temp_var_for_const_26 = SIN3), (Addr)&temp_var_for_tac_18},
        "/home/shijia/Public/testprogram/k_sinl.c_e.c:95:19");
    computeLdMul((Addr)&temp_var_for_tac_20,
                 {(Addr)&z, (Addr)&temp_var_for_tac_19},
                 "/home/shijia/Public/testprogram/k_sinl.c_e.c:94:22");
    computeLdAdd(
        (Addr)&temp_var_for_tac_21,
        {(Addr) &(temp_var_for_const_27 = SIN2), (Addr)&temp_var_for_tac_20},
        "/home/shijia/Public/testprogram/k_sinl.c_e.c:94:14");
    computeLdMul((Addr)&temp_var_for_tac_22,
                 {(Addr)&z, (Addr)&temp_var_for_tac_21},
                 "/home/shijia/Public/testprogram/k_sinl.c_e.c:93:17");
    computeLdAdd(
        (Addr)&temp_var_for_tac_23,
        {(Addr) &(temp_var_for_const_28 = SIN1), (Addr)&temp_var_for_tac_22},
        "/home/shijia/Public/testprogram/k_sinl.c_e.c:92:13");
    computeLdMul((Addr)&temp_var_for_tac_24,
                 {(Addr)&z, (Addr)&temp_var_for_tac_23, (Addr)&x},
                 "/home/shijia/Public/testprogram/k_sinl.c_e.c:90:11");
    computeLdAdd((Addr)&temp_var_for_ext_0,
                 {(Addr)&x, (Addr)&temp_var_for_tac_24},
                 "/home/shijia/Public/testprogram/k_sinl.c_e.c:89:24");
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  } else {
    /* So that we don't have to use too large polynomial,  we find
       l and h such that x = l + h,  where fabsl(l) <= 1.0/256 with 83
       possible values for h.  We look up cosl(h) and sinl(h) in
       pre-computed tables,  compute cosl(l) and sinl(l) using a
       Chebyshev polynomial of degree 10(11) and compute
       sinl(h+l) = sinl(h)cosl(l) + cosl(h)sinl(l).  */
    index = (int)(128 * (absx - (0.1484375L - 1.0L / 256.0L)));
    long double temp_var_for_const_29, temp_var_for_const_30,
        temp_var_for_const_31, temp_var_for_const_32;
    long double temp_var_for_tac_25, temp_var_for_tac_26, temp_var_for_tac_27;
    computeLdDiv((Addr)&temp_var_for_tac_25,
                 {(Addr) &(temp_var_for_const_30 = 1.0L),
                  (Addr) &(temp_var_for_const_29 = 256.0L)},
                 "/home/shijia/Public/testprogram/k_sinl.c_e.c:108:45");
    computeLdSub((Addr)&temp_var_for_tac_26,
                 {(Addr) &(temp_var_for_const_31 = 0.1484375L),
                  (Addr)&temp_var_for_tac_25},
                 "/home/shijia/Public/testprogram/k_sinl.c_e.c:108:31");
    computeLdSub((Addr)&temp_var_for_tac_27,
                 {(Addr)&absx, (Addr)&temp_var_for_tac_26},
                 "/home/shijia/Public/testprogram/k_sinl.c_e.c:108:23");
    ;
    h = 0.1484375L + index / 128.0;
    long double temp_var_for_const_33, temp_var_for_const_34,
        temp_var_for_const_35;
    long double temp_var_for_tac_28, temp_var_for_tac_29;
    computeDMul(
        (Addr)&temp_var_for_tac_28,
        {(Addr) &(temp_var_for_const_32 = 128), (Addr)&temp_var_for_tac_27},
        "/home/shijia/Public/testprogram/k_sinl.c_e.c:109:28");
    computeLdDiv((Addr)&temp_var_for_tac_29,
                 {(Addr) &(temp_var_for_const_34 = index),
                  (Addr) &(temp_var_for_const_33 = 128.0)},
                 "/home/shijia/Public/testprogram/k_sinl.c_e.c:109:20");
    computeLdAdd((Addr)&h, {(Addr) &(temp_var_for_const_35 = 0.1484375L),
                            (Addr)&temp_var_for_tac_29},
                 "/home/shijia/Public/testprogram/k_sinl.c_e.c:109:7");
    index *= 4;
    if (iy) {
      l = (x < 0 ? (0.0 - y) : y) - (h - absx);
      long double temp_var_for_const_36;
      long double temp_var_for_tac_30;
      computeLdSub((Addr)&temp_var_for_tac_30, {(Addr)&h, (Addr)&absx},
                   "/home/shijia/Public/testprogram/k_sinl.c_e.c:112:35");
      computeLdSub((Addr)&l,
                   {(Addr) &(temp_var_for_const_36 = x < 0 ? (0.0 - y) : y),
                    (Addr)&temp_var_for_tac_30},
                   "/home/shijia/Public/testprogram/k_sinl.c_e.c:112:9");
    }

    else {
      l = absx - h;
      long double temp_var_for_tac_31;
      computeLdSub((Addr)&temp_var_for_tac_31, {(Addr)&absx, (Addr)&h},
                   "toString(biExpr->getExprLoc())");
    }

    z = l * l;
    computeLdMul((Addr)&z, {(Addr)&l, (Addr)&l},
                 "/home/shijia/Public/testprogram/k_sinl.c_e.c:119:7");
    sin_l =
        l * (ONE +
             z * (SSIN1 + z * (SSIN2 + z * (SSIN3 + z * (SSIN4 + z * SSIN5)))));
    long double temp_var_for_const_37, temp_var_for_const_38,
        temp_var_for_const_39, temp_var_for_const_40, temp_var_for_const_41,
        temp_var_for_const_42;
    long double temp_var_for_tac_32, temp_var_for_tac_33, temp_var_for_tac_34,
        temp_var_for_tac_35, temp_var_for_tac_36, temp_var_for_tac_37,
        temp_var_for_tac_38, temp_var_for_tac_39, temp_var_for_tac_40,
        temp_var_for_tac_41;
    computeLdMul((Addr)&temp_var_for_tac_32,
                 {(Addr)&z, (Addr) &(temp_var_for_const_37 = SSIN5)},
                 "/home/shijia/Public/testprogram/k_sinl.c_e.c:122:64");
    computeLdAdd(
        (Addr)&temp_var_for_tac_33,
        {(Addr) &(temp_var_for_const_38 = SSIN4), (Addr)&temp_var_for_tac_32},
        "/home/shijia/Public/testprogram/k_sinl.c_e.c:122:55");
    computeLdMul((Addr)&temp_var_for_tac_34,
                 {(Addr)&z, (Addr)&temp_var_for_tac_33},
                 "/home/shijia/Public/testprogram/k_sinl.c_e.c:122:51");
    computeLdAdd(
        (Addr)&temp_var_for_tac_35,
        {(Addr) &(temp_var_for_const_39 = SSIN3), (Addr)&temp_var_for_tac_34},
        "/home/shijia/Public/testprogram/k_sinl.c_e.c:122:42");
    computeLdMul((Addr)&temp_var_for_tac_36,
                 {(Addr)&z, (Addr)&temp_var_for_tac_35},
                 "/home/shijia/Public/testprogram/k_sinl.c_e.c:122:38");
    computeLdAdd(
        (Addr)&temp_var_for_tac_37,
        {(Addr) &(temp_var_for_const_40 = SSIN2), (Addr)&temp_var_for_tac_36},
        "/home/shijia/Public/testprogram/k_sinl.c_e.c:122:29");
    computeLdMul((Addr)&temp_var_for_tac_38,
                 {(Addr)&z, (Addr)&temp_var_for_tac_37},
                 "/home/shijia/Public/testprogram/k_sinl.c_e.c:122:25");
    computeLdAdd(
        (Addr)&temp_var_for_tac_39,
        {(Addr) &(temp_var_for_const_41 = SSIN1), (Addr)&temp_var_for_tac_38},
        "/home/shijia/Public/testprogram/k_sinl.c_e.c:122:16");
    computeLdMul((Addr)&temp_var_for_tac_40,
                 {(Addr)&z, (Addr)&temp_var_for_tac_39},
                 "/home/shijia/Public/testprogram/k_sinl.c_e.c:121:18");
    computeLdAdd(
        (Addr)&temp_var_for_tac_41,
        {(Addr) &(temp_var_for_const_42 = ONE), (Addr)&temp_var_for_tac_40},
        "/home/shijia/Public/testprogram/k_sinl.c_e.c:121:11");
    computeLdMul((Addr)&sin_l, {(Addr)&l, (Addr)&temp_var_for_tac_41},
                 "/home/shijia/Public/testprogram/k_sinl.c_e.c:120:11");
    cos_l_m1 =
        z * (SCOS1 + z * (SCOS2 + z * (SCOS3 + z * (SCOS4 + z * SCOS5))));
    long double temp_var_for_const_43, temp_var_for_const_44,
        temp_var_for_const_45, temp_var_for_const_46, temp_var_for_const_47;
    long double temp_var_for_tac_42, temp_var_for_tac_43, temp_var_for_tac_44,
        temp_var_for_tac_45, temp_var_for_tac_46, temp_var_for_tac_47,
        temp_var_for_tac_48, temp_var_for_tac_49;
    computeLdMul((Addr)&temp_var_for_tac_42,
                 {(Addr)&z, (Addr) &(temp_var_for_const_43 = SCOS5)},
                 "/home/shijia/Public/testprogram/k_sinl.c_e.c:124:59");
    computeLdAdd(
        (Addr)&temp_var_for_tac_43,
        {(Addr) &(temp_var_for_const_44 = SCOS4), (Addr)&temp_var_for_tac_42},
        "/home/shijia/Public/testprogram/k_sinl.c_e.c:124:50");
    computeLdMul((Addr)&temp_var_for_tac_44,
                 {(Addr)&z, (Addr)&temp_var_for_tac_43},
                 "/home/shijia/Public/testprogram/k_sinl.c_e.c:124:46");
    computeLdAdd(
        (Addr)&temp_var_for_tac_45,
        {(Addr) &(temp_var_for_const_45 = SCOS3), (Addr)&temp_var_for_tac_44},
        "/home/shijia/Public/testprogram/k_sinl.c_e.c:124:37");
    computeLdMul((Addr)&temp_var_for_tac_46,
                 {(Addr)&z, (Addr)&temp_var_for_tac_45},
                 "/home/shijia/Public/testprogram/k_sinl.c_e.c:124:33");
    computeLdAdd(
        (Addr)&temp_var_for_tac_47,
        {(Addr) &(temp_var_for_const_46 = SCOS2), (Addr)&temp_var_for_tac_46},
        "/home/shijia/Public/testprogram/k_sinl.c_e.c:124:24");
    computeLdMul((Addr)&temp_var_for_tac_48,
                 {(Addr)&z, (Addr)&temp_var_for_tac_47},
                 "/home/shijia/Public/testprogram/k_sinl.c_e.c:124:20");
    computeLdAdd(
        (Addr)&temp_var_for_tac_49,
        {(Addr) &(temp_var_for_const_47 = SCOS1), (Addr)&temp_var_for_tac_48},
        "/home/shijia/Public/testprogram/k_sinl.c_e.c:124:11");
    computeLdMul((Addr)&cos_l_m1, {(Addr)&z, (Addr)&temp_var_for_tac_49},
                 "/home/shijia/Public/testprogram/k_sinl.c_e.c:123:14");
    z = __sincosl_table[index + SINCOSL_SIN_HI] +
        (__sincosl_table[index + SINCOSL_SIN_LO] +
         (__sincosl_table[index + SINCOSL_SIN_HI] * cos_l_m1) +
         (__sincosl_table[index + SINCOSL_COS_HI] * sin_l));
    long double temp_var_for_ext_1;
    temp_var_for_ext_1 = (x < 0) ? -z : z;
    long double temp_var_for_const_48;
    AssignLd({(Addr)&temp_var_for_ext_1},
             (Addr) &(temp_var_for_const_48 = (x < 0) ? -z : z),
             "/home/shijia/Public/testprogram/k_sinl.c_e.c:130:24");
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for(0.0 - e) xt_1;
  }

#undef SINCOSL_COS_HI
#undef SINCOSL_COS_LO
#undef SINCOSL_SIN_HI
#undef SINCOSL_SIN_LO
}
