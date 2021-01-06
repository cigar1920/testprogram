#include "../ScDebug/scdebug.h"
/* @(#)e_j1.c 1.3 95/01/18 */
/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunSoft, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 */
/* Modified by Naohiko Shimizu/Tokai University, Japan 1997/08/26,
   for performance improvement on pipelined processors.
*/

/* __ieee754_j1(x)
 * Bessel function of the first kind of order one.
 * Method -- j1(x):
 *	1. For tiny x, we use j1(x) = x/2 - x^3/16 + x^5/384 - ...
 *	2. Reduce x to |x| since j1(x)=-j1(-x),  and
 *	   for x in (0,2)
 *		j1(x) = x/2 + x*z*R0/S0,  where z = x*x;
 *	   (precision:  |j1/x - 1/2 - R0/S0 |<2**-61.51 )
 *	   for x in (2,inf)
 *		j1(x) = sqrt(2/(pi*x))*(p1(x)*cos(x1)-q1(x)*sin(x1))
 *		y1(x) = sqrt(2/(pi*x))*(p1(x)*sin(x1)+q1(x)*cos(x1))
 *	   where x1 = x-3*pi/4. It is better to compute sin(x1),cos(x1)
 *	   as follow:
 *		cos(x1) =  cos(x)cos(3pi/4)+sin(x)sin(3pi/4)
 *			=  1/sqrt(2) * (sin(x) - cos(x))
 *		sin(x1) =  sin(x)cos(3pi/4)-cos(x)sin(3pi/4)
 *			= -1/sqrt(2) * (sin(x) + cos(x))
 *	   (To avoid cancellation, use
 *		sin(x) +- cos(x) = -cos(2x)/(sin(x) -+ cos(x))
 *	    to compute the worse one.)
 *
 *	3 Special cases
 *		j1(nan)= nan
 *		j1(0) = 0
 *		j1(inf) = 0
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

double __ieee754_j1(double x) {
  double z, s, c, ss, cc, r, u, v, y, r1, r2, s1, s2, s3, z2, z4;
  int32_t hx, ix;

  static const double hugeval = 1e300;
  static const double one = 1.0;
  static const double invsqrtpi =
      5.64189583547756279280e-01; /* 0x3FE20DD7, 0x50429B6D */
  static const double zero = 0.0;

  /* R0/S0 on [0,2] */
  static const double r00 =
      (double temp_var_for_tac_0;
       double temp_var_for_const_0, temp_var_for_const_1;
       temp_var_for_tac_0 = 0.0 - 6.25000000000000000000e-02;

       ); /* 0xBFB00000, 0x00000000 */
  static const double r01 =
      1.40705666955189706048e-03; /* 0x3F570D9F, 0x98472C61 */
  static const double r02 =
      (double temp_var_for_tac_1;
       double temp_var_for_const_2, temp_var_for_const_3;
       temp_var_for_tac_1 = 0.0 - 1.59955631084035597520e-05;

       ); /* 0xBEF0C5C6, 0xBA169668 */
  static const double r03 =
      4.96727999609584448412e-08; /* 0x3E6AAAFA, 0x46CA0BD9 */
  static const double s01 =
      1.91537599538363460805e-02; /* 0x3F939D0B, 0x12637E53 */
  static const double s02 =
      1.85946785588630915560e-04; /* 0x3F285F56, 0xB9CDF664 */
  static const double s03 =
      1.17718464042623683263e-06; /* 0x3EB3BFF8, 0x333F8498 */
  static const double s04 =
      5.04636257076217042715e-09; /* 0x3E35AC88, 0xC97DFF2C */
  static const double s05 =
      1.23542274426137913908e-11; /* 0x3DAB2ACF, 0xCFB97ED8 */

  GET_HIGH_WORD(hx, x);
  ix = hx & IC(0x7fffffff);
  if (ix >= IC(0x7ff00000)) {
    double temp_var_for_ext_0;
    double temp_var_for_tac_2;
    double temp_var_for_const_4;
    temp_var_for_tac_2 = one / x;

    temp_var_for_ext_0 = temp_var_for_tac_2;
    computeDSub((Addr)&temp_var_for_tac_0,
                {(Addr) &(temp_var_for_const_1 = 0.0),
                 (Addr) &(temp_var_for_const_0 = 6.25000000000000000000e-02)},
                "/home/shijia/Public/testprogram/e_j1.c_e.c:59:12");
    computeDSub((Addr)&temp_var_for_tac_1,
                {(Addr) &(temp_var_for_const_3 = 0.0),
                 (Addr) &(temp_var_for_const_2 = 1.59955631084035597520e-05)},
                "/home/shijia/Public/testprogram/e_j1.c_e.c:63:12");
    computeDDiv((Addr)&temp_var_for_tac_2,
                {(Addr) &(temp_var_for_const_4 = one), (Addr)&x},
                "/home/shijia/Public/testprogram/e_j1.c_e.c:81:30");
    AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_2,
            "/home/shijia/Public/testprogram/e_j1.c_e.c:81:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  double temp_var_for_const_5;
  double temp_var_for_callexp_0;

  temp_var_for_callexp_0 = fabs(x);
  y = temp_var_for_callexp_0;
  AssignD({(Addr)&y}, (Addr) &(temp_var_for_const_5 = temp_var_for_callexp_0),
          "/home/shijia/Public/testprogram/e_j1.c_e.c:87:5");
  ;
  if (ix >= IC(0x40000000)) { /* |x| >= 2.0 */
    __ieee754_sincos(y, &s, &c);
    double temp_var_for_tac_3, temp_var_for_tac_4;
    double temp_var_for_const_6;
    temp_var_for_tac_3 = 0.0 - s;

    temp_var_for_tac_4 = temp_var_for_tac_3 - c;

    ss = temp_var_for_tac_4;
    computeDSub((Addr)&temp_var_for_tac_3,
                {(Addr) &(temp_var_for_const_6 = 0.0), (Addr)&s},
                "/home/shijia/Public/testprogram/e_j1.c_e.c:90:15");
    computeDSub((Addr)&temp_var_for_tac_4,
                {(Addr)&temp_var_for_tac_3, (Addr)&c},
                "/home/shijia/Public/testprogram/e_j1.c_e.c:90:20");
    AssignD({(Addr)&ss}, (Addr)&temp_var_for_tac_4,
            "/home/shijia/Public/testprogram/e_j1.c_e.c:90:8");
    ;
    double temp_var_for_tac_5;
    temp_var_for_tac_5 = s - c;

    cc = temp_var_for_tac_5;
    computeDSub((Addr)&temp_var_for_tac_5, {(Addr)&s, (Addr)&c},
                "/home/shijia/Public/testprogram/e_j1.c_e.c:91:12");
    AssignD({(Addr)&cc}, (Addr)&temp_var_for_tac_5,
            "/home/shijia/Public/testprogram/e_j1.c_e.c:91:8");
    ;
    if (ix < IC(0x7fe00000)) { /* make sure y+y not overflow */
      double temp_var_for_tac_6;
      double temp_var_for_const_7;
      double temp_var_for_callexp_1;

      temp_var_for_tac_6 = y + y;

      temp_var_for_callexp_1 = __ieee754_cos(temp_var_for_tac_6);
      z = temp_var_for_callexp_1;
      computeDAdd((Addr)&temp_var_for_tac_6, {(Addr)&y, (Addr)&y},
                  "/home/shijia/Public/testprogram/e_j1.c_e.c:93:27");
      AssignD({(Addr)&z},
              (Addr) &(temp_var_for_const_7 = temp_var_for_callexp_1),
              "/home/shijia/Public/testprogram/e_j1.c_e.c:93:9");
      ;
      if (int temp_var_for_tac_7, temp_var_for_tac_8; int temp_var_for_const_8;
          temp_var_for_tac_7 = s * c;

          temp_var_for_tac_8 = temp_var_for_tac_7 > zero;

          ) {
        double temp_var_for_tac_9;
        temp_var_for_tac_9 = z / ss;

        cc = temp_var_for_tac_9;
        computeDMul((Addr)&temp_var_for_tac_7, {(Addr)&s, (Addr)&c},
                    "/home/shijia/Public/testprogram/e_j1.c_e.c:94:14");
        compute(
            (Addr)&temp_var_for_tac_8,
            {(Addr)&temp_var_for_tac_7, (Addr) &(temp_var_for_const_8 = zero)},
            "/home/shijia/Public/testprogram/e_j1.c_e.c:94:19");
        computeDDiv((Addr)&temp_var_for_tac_9, {(Addr)&z, (Addr)&ss},
                    "/home/shijia/Public/testprogram/e_j1.c_e.c:95:16");
        AssignD({(Addr)&cc}, (Addr)&temp_var_for_tac_9,
                "/home/shijia/Public/testprogram/e_j1.c_e.c:95:12");
        ;
      }

      else {
        double temp_var_for_ext_1;
        double temp_var_for_tac_10;
        temp_var_for_tac_10 = z / cc;

        temp_var_for_ext_1 = temp_var_for_tac_10;
        computeDDiv((Addr)&temp_var_for_tac_10, {(Addr)&z, (Addr)&cc},
                    "/home/shijia/Public/testprogram/e_j1.c_e.c:100:32");
        AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_10,
                "/home/shijia/Public/testprogram/e_j1.c_e.c:100:28");
        ; // ss
        /*(ss)(z)(cc)(z)*/
        ss = temp_var_for_ext_1;
        AssignD({(Addr)&ss}, (Addr)&temp_var_for_ext_1,
                "/home/shijia/Public/testprogram/e_j1.c_e.c:102:12");
        ;
      }
    }
    /*
     * j1(x) = 1/sqrt(pi) * (P(1,x)*cc - Q(1,x)*ss) / sqrt(x)
     * y1(x) = 1/sqrt(pi) * (P(1,x)*ss + Q(1,x)*cc) / sqrt(x)
     */
    if (ix > IC(0x48000000)) {
      double temp_var_for_ext_2;
      double temp_var_for_tac_11, temp_var_for_tac_12;
      double temp_var_for_const_9, temp_var_for_const_10;
      double temp_var_for_callexp_2;

      temp_var_for_tac_11 = invsqrtpi * cc;

      temp_var_for_callexp_2 = __ieee754_sqrt(y);
      temp_var_for_tac_12 = temp_var_for_tac_11 / temp_var_for_callexp_2;

      temp_var_for_ext_2 = temp_var_for_tac_12;
      computeDMul((Addr)&temp_var_for_tac_11,
                  {(Addr) &(temp_var_for_const_9 = invsqrtpi), (Addr)&cc},
                  "/home/shijia/Public/testprogram/e_j1.c_e.c:111:39");
      computeDDiv((Addr)&temp_var_for_tac_12,
                  {(Addr)&temp_var_for_tac_11,
                   (Addr) &(temp_var_for_const_10 = temp_var_for_callexp_2)},
                  "/home/shijia/Public/testprogram/e_j1.c_e.c:111:45");
      AssignD({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_12,
              "/home/shijia/Public/testprogram/e_j1.c_e.c:111:26");
      ; // z
      /*(cc)(z)(__ieee754_sqrt(y))(cc)(invsqrtpi)*/
      z = temp_var_for_ext_2;
      AssignD({(Addr)&z}, (Addr)&temp_var_for_ext_2,
              "/home/shijia/Public/testprogram/e_j1.c_e.c:113:9");
      ;
    }

    else {
      double temp_var_for_const_11;
      double temp_var_for_callexp_3;

      temp_var_for_callexp_3 = __j1_y1_pone(y);
      u = temp_var_for_callexp_3;
      AssignD({(Addr)&u},
              (Addr) &(temp_var_for_const_11 = temp_var_for_callexp_3),
              "/home/shijia/Public/testprogram/e_j1.c_e.c:117:9");
      ;
      double temp_var_for_const_12;
      double temp_var_for_callexp_4;

      temp_var_for_callexp_4 = __j1_y1_qone(y);
      v = temp_var_for_callexp_4;
      AssignD({(Addr)&v},
              (Addr) &(temp_var_for_const_12 = temp_var_for_callexp_4),
              "/home/shijia/Public/testprogram/e_j1.c_e.c:118:9");
      ;
      double temp_var_for_tac_13, temp_var_for_tac_14, temp_var_for_tac_15,
          temp_var_for_tac_16, temp_var_for_tac_17;
      double temp_var_for_const_13, temp_var_for_const_14;
      double temp_var_for_callexp_5;

      temp_var_for_tac_13 = u * cc;

      temp_var_for_tac_14 = v * ss;

      temp_var_for_tac_15 = temp_var_for_tac_13 - temp_var_for_tac_14;

      temp_var_for_tac_16 = invsqrtpi * temp_var_for_tac_15;

      temp_var_for_callexp_5 = __ieee754_sqrt(y);
      temp_var_for_tac_17 = temp_var_for_tac_16 / temp_var_for_callexp_5;

      z = temp_var_for_tac_17;
      computeDMul((Addr)&temp_var_for_tac_13, {(Addr)&u, (Addr)&cc},
                  "/home/shijia/Public/testprogram/e_j1.c_e.c:119:26");
      computeDMul((Addr)&temp_var_for_tac_14, {(Addr)&v, (Addr)&ss},
                  "/home/shijia/Public/testprogram/e_j1.c_e.c:119:35");
      computeDSub((Addr)&temp_var_for_tac_15,
                  {(Addr)&temp_var_for_tac_13, (Addr)&temp_var_for_tac_14},
                  "/home/shijia/Public/testprogram/e_j1.c_e.c:119:31");
      computeDMul((Addr)&temp_var_for_tac_16,
                  {(Addr) &(temp_var_for_const_13 = invsqrtpi),
                   (Addr)&temp_var_for_tac_15},
                  "/home/shijia/Public/testprogram/e_j1.c_e.c:119:21");
      computeDDiv((Addr)&temp_var_for_tac_17,
                  {(Addr)&temp_var_for_tac_16,
                   (Addr) &(temp_var_for_const_14 = temp_var_for_callexp_5)},
                  "/home/shijia/Public/testprogram/e_j1.c_e.c:119:41");
      AssignD({(Addr)&z}, (Addr)&temp_var_for_tac_17,
              "/home/shijia/Public/testprogram/e_j1.c_e.c:119:9");
      ;
    }
    if (hx < 0) {
      double temp_var_for_ext_3;
      double temp_var_for_const_15;
      temp_var_for_ext_3 = (-(z));
      AssignD({(Addr)&temp_var_for_ext_3},
              (Addr) &(temp_var_for_const_15 = (-(z))),
              "/home/shijia/Public/testprogram/e_j1.c_e.c:123:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
      callExp++; /*identify the function is  add move tmpShadow*/
      return (double temp_var_for_tac_18;
              double temp_var_for_const_16, temp_var_for_const_17;
              temp_var_for_tac_18 = 0.0 - 3;

              );
    }

    else {
      double temp_var_for_ext_4;
      temp_var_for_ext_4 = z;
      computeDSub((Addr)&temp_var_for_tac_18,
                  {(Addr) &(temp_var_for_const_17 = 0.0),
                   (Addr) &(temp_var_for_const_16 = 3)},
                  "/home/shijia/Public/testprogram/e_j1.c_e.c:127:19");
      AssignD({(Addr)&temp_var_for_ext_4}, (Addr)&z,
              "/home/shijia/Public/testprogram/e_j1.c_e.c:132:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_4;
    }
  }
  if (ix < IC(0x3e400000)) { /* |x|<2**-27 */
    if (int temp_var_for_tac_19, temp_var_for_tac_20;
        int temp_var_for_const_18, temp_var_for_const_19;
        temp_var_for_tac_19 = hugeval + x;

        temp_var_for_tac_20 = temp_var_for_tac_19 > one;

        ) {
      double temp_var_for_ext_5;
      double temp_var_for_tac_21;
      double temp_var_for_const_20;
      temp_var_for_tac_21 = 0.5 * x;

      temp_var_for_ext_5 = temp_var_for_tac_21;
      computeDAdd((Addr)&temp_var_for_tac_19,
                  {(Addr) &(temp_var_for_const_18 = hugeval), (Addr)&x},
                  "/home/shijia/Public/testprogram/e_j1.c_e.c:140:17");
      compute(
          (Addr)&temp_var_for_tac_20,
          {(Addr)&temp_var_for_tac_19, (Addr) &(temp_var_for_const_19 = one)},
          "/home/shijia/Public/testprogram/e_j1.c_e.c:140:21");
      computeDMul((Addr)&temp_var_for_tac_21,
                  {(Addr) &(temp_var_for_const_20 = 0.5), (Addr)&x},
                  "/home/shijia/Public/testprogram/e_j1.c_e.c:142:32");
      AssignD({(Addr)&temp_var_for_ext_5}, (Addr)&temp_var_for_tac_21,
              "/home/shijia/Public/testprogram/e_j1.c_e.c:142:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_5;
    }
    /* inexact if x!=0 necessary */
  }
  double temp_var_for_tac_22;
  temp_var_for_tac_22 = x * x;

  z = temp_var_for_tac_22;
  computeDMul((Addr)&temp_var_for_tac_22, {(Addr)&x, (Addr)&x},
              "/home/shijia/Public/testprogram/e_j1.c_e.c:150:9");
  AssignD({(Addr)&z}, (Addr)&temp_var_for_tac_22,
          "/home/shijia/Public/testprogram/e_j1.c_e.c:150:5");
  ;
#ifdef DO_NOT_USE_THIS
  r = z * (r00 + z * (r01 + z * (r02 + z * r03)));
  s = one + z * (s01 + z * (s02 + z * (s03 + z * (s04 + z * s05))));
  r *= x;
#else
  double temp_var_for_tac_23;
  double temp_var_for_const_21;
  temp_var_for_tac_23 = z * r00;

  r1 = temp_var_for_tac_23;
  computeDMul((Addr)&temp_var_for_tac_23,
              {(Addr)&z, (Addr) &(temp_var_for_const_21 = r00)},
              "/home/shijia/Public/testprogram/e_j1.c_e.c:156:10");
  AssignD({(Addr)&r1}, (Addr)&temp_var_for_tac_23,
          "/home/shijia/Public/testprogram/e_j1.c_e.c:156:6");
  ;
  double temp_var_for_tac_24;
  temp_var_for_tac_24 = z * z;

  z2 = temp_var_for_tac_24;
  computeDMul((Addr)&temp_var_for_tac_24, {(Addr)&z, (Addr)&z},
              "/home/shijia/Public/testprogram/e_j1.c_e.c:157:10");
  AssignD({(Addr)&z2}, (Addr)&temp_var_for_tac_24,
          "/home/shijia/Public/testprogram/e_j1.c_e.c:157:6");
  ;
  double temp_var_for_tac_25, temp_var_for_tac_26;
  double temp_var_for_const_22, temp_var_for_const_23;
  temp_var_for_tac_25 = z * r02;

  temp_var_for_tac_26 = r01 + temp_var_for_tac_25;

  r2 = temp_var_for_tac_26;
  computeDMul((Addr)&temp_var_for_tac_25,
              {(Addr)&z, (Addr) &(temp_var_for_const_22 = r02)},
              "/home/shijia/Public/testprogram/e_j1.c_e.c:158:16");
  computeDAdd(
      (Addr)&temp_var_for_tac_26,
      {(Addr) &(temp_var_for_const_23 = r01), (Addr)&temp_var_for_tac_25},
      "/home/shijia/Public/testprogram/e_j1.c_e.c:158:12");
  AssignD({(Addr)&r2}, (Addr)&temp_var_for_tac_26,
          "/home/shijia/Public/testprogram/e_j1.c_e.c:158:6");
  ;
  double temp_var_for_tac_27;
  temp_var_for_tac_27 = z2 * z2;

  z4 = temp_var_for_tac_27;
  computeDMul((Addr)&temp_var_for_tac_27, {(Addr)&z2, (Addr)&z2},
              "/home/shijia/Public/testprogram/e_j1.c_e.c:159:11");
  AssignD({(Addr)&z4}, (Addr)&temp_var_for_tac_27,
          "/home/shijia/Public/testprogram/e_j1.c_e.c:159:6");
  ;
  double temp_var_for_tac_28, temp_var_for_tac_29, temp_var_for_tac_30,
      temp_var_for_tac_31;
  double temp_var_for_const_24;
  temp_var_for_tac_28 = z2 * r2;

  temp_var_for_tac_29 = r1 + temp_var_for_tac_28;

  temp_var_for_tac_30 = z4 * r03;

  temp_var_for_tac_31 = temp_var_for_tac_29 + temp_var_for_tac_30;

  r = temp_var_for_tac_31;
  computeDMul((Addr)&temp_var_for_tac_28, {(Addr)&z2, (Addr)&r2},
              "/home/shijia/Public/testprogram/e_j1.c_e.c:160:15");
  computeDAdd((Addr)&temp_var_for_tac_29,
              {(Addr)&r1, (Addr)&temp_var_for_tac_28},
              "/home/shijia/Public/testprogram/e_j1.c_e.c:160:10");
  computeDMul((Addr)&temp_var_for_tac_30,
              {(Addr)&z4, (Addr) &(temp_var_for_const_24 = r03)},
              "/home/shijia/Public/testprogram/e_j1.c_e.c:160:25");
  computeDAdd((Addr)&temp_var_for_tac_31,
              {(Addr)&temp_var_for_tac_29, (Addr)&temp_var_for_tac_30},
              "/home/shijia/Public/testprogram/e_j1.c_e.c:160:20");
  AssignD({(Addr)&r}, (Addr)&temp_var_for_tac_31,
          "/home/shijia/Public/testprogram/e_j1.c_e.c:160:5");
  ;
  r *= x;
  ;
  double temp_var_for_tac_33, temp_var_for_tac_34;
  double temp_var_for_const_25, temp_var_for_const_26;
  temp_var_for_tac_33 = z * s01;

  temp_var_for_tac_34 = one + temp_var_for_tac_33;

  s1 = temp_var_for_tac_34;
  computeDMul((Addr)&temp_var_for_tac_33,
              {(Addr)&z, (Addr) &(temp_var_for_const_25 = s01)},
              "/home/shijia/Public/testprogram/e_j1.c_e.c:162:16");
  computeDAdd(
      (Addr)&temp_var_for_tac_34,
      {(Addr) &(temp_var_for_const_26 = one), (Addr)&temp_var_for_tac_33},
      "/home/shijia/Public/testprogram/e_j1.c_e.c:162:12");
  AssignD({(Addr)&s1}, (Addr)&temp_var_for_tac_34,
          "/home/shijia/Public/testprogram/e_j1.c_e.c:162:6");
  ;
  double temp_var_for_tac_35, temp_var_for_tac_36;
  double temp_var_for_const_27, temp_var_for_const_28;
  temp_var_for_tac_35 = z * s03;

  temp_var_for_tac_36 = s02 + temp_var_for_tac_35;

  s2 = temp_var_for_tac_36;
  computeDMul((Addr)&temp_var_for_tac_35,
              {(Addr)&z, (Addr) &(temp_var_for_const_27 = s03)},
              "/home/shijia/Public/testprogram/e_j1.c_e.c:163:16");
  computeDAdd(
      (Addr)&temp_var_for_tac_36,
      {(Addr) &(temp_var_for_const_28 = s02), (Addr)&temp_var_for_tac_35},
      "/home/shijia/Public/testprogram/e_j1.c_e.c:163:12");
  AssignD({(Addr)&s2}, (Addr)&temp_var_for_tac_36,
          "/home/shijia/Public/testprogram/e_j1.c_e.c:163:6");
  ;
  double temp_var_for_tac_37, temp_var_for_tac_38;
  double temp_var_for_const_29, temp_var_for_const_30;
  temp_var_for_tac_37 = z * s05;

  temp_var_for_tac_38 = s04 + temp_var_for_tac_37;

  s3 = temp_var_for_tac_38;
  computeDMul((Addr)&temp_var_for_tac_37,
              {(Addr)&z, (Addr) &(temp_var_for_const_29 = s05)},
              "/home/shijia/Public/testprogram/e_j1.c_e.c:164:16");
  computeDAdd(
      (Addr)&temp_var_for_tac_38,
      {(Addr) &(temp_var_for_const_30 = s04), (Addr)&temp_var_for_tac_37},
      "/home/shijia/Public/testprogram/e_j1.c_e.c:164:12");
  AssignD({(Addr)&s3}, (Addr)&temp_var_for_tac_38,
          "/home/shijia/Public/testprogram/e_j1.c_e.c:164:6");
  ;
  double temp_var_for_tac_39, temp_var_for_tac_40, temp_var_for_tac_41,
      temp_var_for_tac_42;
  temp_var_for_tac_39 = z2 * s2;

  temp_var_for_tac_40 = s1 + temp_var_for_tac_39;

  temp_var_for_tac_41 = z4 * s3;

  temp_var_for_tac_42 = temp_var_for_tac_40 + temp_var_for_tac_41;

  s = temp_var_for_tac_42;
  computeDMul((Addr)&temp_var_for_tac_39, {(Addr)&z2, (Addr)&s2},
              "/home/shijia/Public/testprogram/e_j1.c_e.c:165:15");
  computeDAdd((Addr)&temp_var_for_tac_40,
              {(Addr)&s1, (Addr)&temp_var_for_tac_39},
              "/home/shijia/Public/testprogram/e_j1.c_e.c:165:10");
  computeDMul((Addr)&temp_var_for_tac_41, {(Addr)&z4, (Addr)&s3},
              "/home/shijia/Public/testprogram/e_j1.c_e.c:165:25");
  computeDAdd((Addr)&temp_var_for_tac_42,
              {(Addr)&temp_var_for_tac_40, (Addr)&temp_var_for_tac_41},
              "/home/shijia/Public/testprogram/e_j1.c_e.c:165:20");
  AssignD({(Addr)&s}, (Addr)&temp_var_for_tac_42,
          "/home/shijia/Public/testprogram/e_j1.c_e.c:165:5");
  ;
#endif
  double temp_var_for_ext_6;
  double temp_var_for_tac_43, temp_var_for_tac_44, temp_var_for_tac_45;
  double temp_var_for_const_31;
  temp_var_for_tac_43 = x * 0.5;

  temp_var_for_tac_44 = r / s;

  temp_var_for_tac_45 = temp_var_for_tac_43 + temp_var_for_tac_44;

  temp_var_for_ext_6 = temp_var_for_tac_45;
  computeDMul((Addr)&temp_var_for_tac_43,
              {(Addr)&x, (Addr) &(temp_var_for_const_31 = 0.5)},
              "/home/shijia/Public/testprogram/e_j1.c_e.c:168:27");
  computeDDiv((Addr)&temp_var_for_tac_44, {(Addr)&r, (Addr)&s},
              "/home/shijia/Public/testprogram/e_j1.c_e.c:168:37");
  computeDAdd((Addr)&temp_var_for_tac_45,
              {(Addr)&temp_var_for_tac_43, (Addr)&temp_var_for_tac_44},
              "/home/shijia/Public/testprogram/e_j1.c_e.c:168:33");
  AssignD({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_45,
          "/home/shijia/Public/testprogram/e_j1.c_e.c:168:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_6;
}

/* wrapper j1 */
double __j1(double x) {
  if (isgreater(__ieee754_fabs(x), X_TLOSS) && _LIB_VERSION != _IEEE_ &&
      _LIB_VERSION != _POSIX_)
  /* j1(|x|>X_TLOSS) */
  {
    double temp_var_for_ext_7;
    double temp_var_for_const_32;
    double temp_var_for_callexp_6;

    temp_var_for_callexp_6 = __kernel_standard(x, x, 0.0, KMATHERR_J1_TLOSS);
    temp_var_for_ext_7 = temp_var_for_callexp_6;
    AssignD({(Addr)&temp_var_for_ext_7},
            (Addr) &(temp_var_for_const_32 = temp_var_for_callexp_6),
            "/home/shijia/Public/testprogram/e_j1.c_e.c:181:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_7;
  }

  double temp_var_for_ext_8;
  double temp_var_for_const_33;
  double temp_var_for_callexp_7;

  temp_var_for_callexp_7 = __ieee754_j1(x);
  temp_var_for_ext_8 = temp_var_for_callexp_7;
  AssignD({(Addr)&temp_var_for_ext_8},
          (Addr) &(temp_var_for_const_33 = temp_var_for_callexp_7),
          "/home/shijia/Public/testprogram/e_j1.c_e.c:188:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_8;
}

__typeof(__j1) j1 __attribute__((weak, alias("__j1")));
#ifdef __NO_LONG_DOUBLE_MATH
__typeof(__j1l) __j1l __attribute__((alias("__j1")));
__typeof(__j1l) j1l __attribute__((weak, alias("__j1l")));
#endif
