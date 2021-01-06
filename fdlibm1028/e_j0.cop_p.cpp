#include "../ScDebug/scdebug.h"
/* @(#)e_j0.c 1.3 95/01/18 */
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

/* __ieee754_j0(x)
 * Bessel function of the first kind of order zero.
 * Method -- j0(x):
 *	1. For tiny x, we use j0(x) = 1 - x^2/4 + x^4/64 - ...
 *	2. Reduce x to |x| since j0(x)=j0(-x),  and
 *	   for x in (0,2)
 *		j0(x) = 1-z/4+ z^2*R0/S0,  where z = x*x;
 *	   (precision:  |j0-1+z/4-z^2R0/S0 |<2**-63.67 )
 *	   for x in (2,inf)
 *      j0(x) = sqrt(2/(pi*x))*(p0(x)*cos(x0)-q0(x)*sin(x0))
 *     where x0 = x-pi/4. It is better to compute sin(x0),cos(x0)
 *	   as follow:
 *		cos(x0) = cos(x)cos(pi/4)+sin(x)sin(pi/4)
 *			= 1/sqrt(2) * (cos(x) + sin(x))
 *		sin(x0) = sin(x)cos(pi/4)-cos(x)sin(pi/4)
 *			= 1/sqrt(2) * (sin(x) - cos(x))
 *     (To avoid cancellation, use
 *		sin(x) +- cos(x) = -cos(2x)/(sin(x) -+ cos(x))
 *      to compute the worse one.)
 *
 *	3 Special cases
 *		j0(nan)= nan
 *		j0(0) = 1
 *		j0(inf) = 0
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

double __ieee754_j0(double x) {
  double z, s, c, ss, cc, r, u, v, r1, r2, s1, s2, z2, z4;
  int32_t hx, ix;

  static const double hugeval = 1e300;
  static const double one = 1.0;
  static const double zero = 0.0;
  static const double invsqrtpi =
      5.64189583547756279280e-01; /* 0x3FE20DD7, 0x50429B6D */

  /* R0/S0 on [0, 2.00] */
  static const double R02 =
      1.56249999999999947958e-02; /* 0x3F8FFFFF, 0xFFFFFFFD */
  static const double R03 =
      (double temp_var_for_tac_0;
       double temp_var_for_const_0, temp_var_for_const_1;
       temp_var_for_tac_0 = 0.0 - 1.89979294238854721751e-04;

       ); /* 0xBF28E6A5, 0xB61AC6E9 */
  static const double R04 =
      1.82954049532700665670e-06; /* 0x3EBEB1D1, 0x0C503919 */
  static const double R05 =
      (double temp_var_for_tac_1;
       double temp_var_for_const_2, temp_var_for_const_3;
       temp_var_for_tac_1 = 0.0 - 4.61832688532103189199e-09;

       ); /* 0xBE33D5E7, 0x73D63FCE */
  static const double S01 =
      1.56191029464890010492e-02; /* 0x3F8FFCE8, 0x82C8C2A4 */
  static const double S02 =
      1.16926784663337450260e-04; /* 0x3F1EA6D2, 0xDD57DBF4 */
  static const double S03 =
      5.13546550207318111446e-07; /* 0x3EA13B54, 0xCE84D5A9 */
  static const double S04 =
      1.16614003333790000205e-09; /* 0x3E1408BC, 0xF4745D8F */

  GET_HIGH_WORD(hx, x);
  ix = hx & IC(0x7fffffff);
  if (ix >= IC(0x7ff00000)) {
    double temp_var_for_ext_0;
    double temp_var_for_tac_2, temp_var_for_tac_3;
    double temp_var_for_const_4;
    temp_var_for_tac_2 = x * x;

    temp_var_for_tac_3 = one / temp_var_for_tac_2;

    temp_var_for_ext_0 = temp_var_for_tac_3;
    computeDSub((Addr)&temp_var_for_tac_0,
                {(Addr) &(temp_var_for_const_1 = 0.0),
                 (Addr) &(temp_var_for_const_0 = 1.89979294238854721751e-04)},
                "/home/shijia/Public/testprogram/e_j0.c_e.c:60:12");
    computeDSub((Addr)&temp_var_for_tac_1,
                {(Addr) &(temp_var_for_const_3 = 0.0),
                 (Addr) &(temp_var_for_const_2 = 4.61832688532103189199e-09)},
                "/home/shijia/Public/testprogram/e_j0.c_e.c:64:12");
    computeDMul((Addr)&temp_var_for_tac_2, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_j0.c_e.c:78:35");
    computeDDiv(
        (Addr)&temp_var_for_tac_3,
        {(Addr) &(temp_var_for_const_4 = one), (Addr)&temp_var_for_tac_2},
        "/home/shijia/Public/testprogram/e_j0.c_e.c:78:30");
    AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_3,
            "/home/shijia/Public/testprogram/e_j0.c_e.c:78:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  double temp_var_for_ext_1;
  double temp_var_for_const_5;
  double temp_var_for_callexp_0;

  temp_var_for_callexp_0 = fabs(x);
  temp_var_for_ext_1 = temp_var_for_callexp_0;
  AssignD({(Addr)&temp_var_for_ext_1},
          (Addr) &(temp_var_for_const_5 = temp_var_for_callexp_0),
          "/home/shijia/Public/testprogram/e_j0.c_e.c:85:22");
  ; // x
  /*(_)(_)(tem)(_)(_)(__ieee754_fabs(x))*/
  x = temp_var_for_ext_1;
  AssignD({(Addr)&x}, (Addr)&temp_var_for_ext_1,
          "/home/shijia/Public/testprogram/e_j0.c_e.c:87:5");
  ;
  if (ix >= IC(0x40000000)) { /* |x| >= 2.0 */
    __ieee754_sincos(x, &s, &c);
    double temp_var_for_tac_4;
    temp_var_for_tac_4 = s - c;

    ss = temp_var_for_tac_4;
    computeDSub((Addr)&temp_var_for_tac_4, {(Addr)&s, (Addr)&c},
                "/home/shijia/Public/testprogram/e_j0.c_e.c:90:12");
    AssignD({(Addr)&ss}, (Addr)&temp_var_for_tac_4,
            "/home/shijia/Public/testprogram/e_j0.c_e.c:90:8");
    ;
    double temp_var_for_tac_5;
    temp_var_for_tac_5 = s + c;

    cc = temp_var_for_tac_5;
    computeDAdd((Addr)&temp_var_for_tac_5, {(Addr)&s, (Addr)&c},
                "/home/shijia/Public/testprogram/e_j0.c_e.c:91:12");
    AssignD({(Addr)&cc}, (Addr)&temp_var_for_tac_5,
            "/home/shijia/Public/testprogram/e_j0.c_e.c:91:8");
    ;
    if (ix < IC(0x7fe00000)) { /* make sure x+x not overflow */
      double temp_var_for_tac_6, temp_var_for_tac_7;
      double temp_var_for_const_6, temp_var_for_const_7;
      double temp_var_for_callexp_1;

      temp_var_for_tac_6 = x + x;

      temp_var_for_callexp_1 = __ieee754_cos(temp_var_for_tac_6);
      temp_var_for_tac_7 = 0.0 - temp_var_for_callexp_1;

      z = temp_var_for_tac_7;
      computeDAdd((Addr)&temp_var_for_tac_6, {(Addr)&x, (Addr)&x},
                  "/home/shijia/Public/testprogram/e_j0.c_e.c:93:34");
      computeDSub((Addr)&temp_var_for_tac_7,
                  {(Addr) &(temp_var_for_const_7 = 0.0),
                   (Addr) &(temp_var_for_const_6 = temp_var_for_callexp_1)},
                  "/home/shijia/Public/testprogram/e_j0.c_e.c:93:16");
      AssignD({(Addr)&z}, (Addr)&temp_var_for_tac_7,
              "/home/shijia/Public/testprogram/e_j0.c_e.c:93:9");
      ;
      if (int temp_var_for_tac_8, temp_var_for_tac_9; int temp_var_for_const_8;
          temp_var_for_tac_8 = s * c;

          temp_var_for_tac_9 = temp_var_for_tac_8 < zero;

          ) {
        double temp_var_for_tac_10;
        temp_var_for_tac_10 = z / ss;

        cc = temp_var_for_tac_10;
        computeDMul((Addr)&temp_var_for_tac_8, {(Addr)&s, (Addr)&c},
                    "/home/shijia/Public/testprogram/e_j0.c_e.c:94:14");
        compute(
            (Addr)&temp_var_for_tac_9,
            {(Addr)&temp_var_for_tac_8, (Addr) &(temp_var_for_const_8 = zero)},
            "/home/shijia/Public/testprogram/e_j0.c_e.c:94:19");
        computeDDiv((Addr)&temp_var_for_tac_10, {(Addr)&z, (Addr)&ss},
                    "/home/shijia/Public/testprogram/e_j0.c_e.c:95:16");
        AssignD({(Addr)&cc}, (Addr)&temp_var_for_tac_10,
                "/home/shijia/Public/testprogram/e_j0.c_e.c:95:12");
        ;
      }

      else {
        double temp_var_for_ext_2;
        double temp_var_for_tac_11;
        temp_var_for_tac_11 = z / cc;

        temp_var_for_ext_2 = temp_var_for_tac_11;
        computeDDiv((Addr)&temp_var_for_tac_11, {(Addr)&z, (Addr)&cc},
                    "/home/shijia/Public/testprogram/e_j0.c_e.c:100:32");
        AssignD({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_11,
                "/home/shijia/Public/testprogram/e_j0.c_e.c:100:28");
        ; // ss
        /*(ss)(z)(cc)(z)*/
        ss = temp_var_for_ext_2;
        AssignD({(Addr)&ss}, (Addr)&temp_var_for_ext_2,
                "/home/shijia/Public/testprogram/e_j0.c_e.c:102:12");
        ;
      }
    }
    /*
     * j0(x) = 1/sqrt(pi) * (P(0,x)*cc - Q(0,x)*ss) / sqrt(x)
     * y0(x) = 1/sqrt(pi) * (P(0,x)*ss + Q(0,x)*cc) / sqrt(x)
     */
    if (ix > IC(0x48000000)) {
      double temp_var_for_ext_3;
      double temp_var_for_tac_12, temp_var_for_tac_13;
      double temp_var_for_const_9, temp_var_for_const_10;
      double temp_var_for_callexp_2;

      temp_var_for_tac_12 = invsqrtpi * cc;

      temp_var_for_callexp_2 = __ieee754_sqrt(x);
      temp_var_for_tac_13 = temp_var_for_tac_12 / temp_var_for_callexp_2;

      temp_var_for_ext_3 = temp_var_for_tac_13;
      computeDMul((Addr)&temp_var_for_tac_12,
                  {(Addr) &(temp_var_for_const_9 = invsqrtpi), (Addr)&cc},
                  "/home/shijia/Public/testprogram/e_j0.c_e.c:111:39");
      computeDDiv((Addr)&temp_var_for_tac_13,
                  {(Addr)&temp_var_for_tac_12,
                   (Addr) &(temp_var_for_const_10 = temp_var_for_callexp_2)},
                  "/home/shijia/Public/testprogram/e_j0.c_e.c:111:45");
      AssignD({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_13,
              "/home/shijia/Public/testprogram/e_j0.c_e.c:111:26");
      ; // z
      /*(cc)(z)(__ieee754_sqrt(x))(cc)(invsqrtpi)*/
      z = temp_var_for_ext_3;
      AssignD({(Addr)&z}, (Addr)&temp_var_for_ext_3,
              "/home/shijia/Public/testprogram/e_j0.c_e.c:113:9");
      ;
    }

    else {
      double temp_var_for_const_11;
      double temp_var_for_callexp_3;

      temp_var_for_callexp_3 = __j0_y0_pzero(x);
      u = temp_var_for_callexp_3;
      AssignD({(Addr)&u},
              (Addr) &(temp_var_for_const_11 = temp_var_for_callexp_3),
              "/home/shijia/Public/testprogram/e_j0.c_e.c:117:9");
      ;
      double temp_var_for_const_12;
      double temp_var_for_callexp_4;

      temp_var_for_callexp_4 = __j0_y0_qzero(x);
      v = temp_var_for_callexp_4;
      AssignD({(Addr)&v},
              (Addr) &(temp_var_for_const_12 = temp_var_for_callexp_4),
              "/home/shijia/Public/testprogram/e_j0.c_e.c:118:9");
      ;
      double temp_var_for_tac_14, temp_var_for_tac_15, temp_var_for_tac_16,
          temp_var_for_tac_17, temp_var_for_tac_18;
      double temp_var_for_const_13, temp_var_for_const_14;
      double temp_var_for_callexp_5;

      temp_var_for_tac_14 = u * cc;

      temp_var_for_tac_15 = v * ss;

      temp_var_for_tac_16 = temp_var_for_tac_14 - temp_var_for_tac_15;

      temp_var_for_tac_17 = invsqrtpi * temp_var_for_tac_16;

      temp_var_for_callexp_5 = __ieee754_sqrt(x);
      temp_var_for_tac_18 = temp_var_for_tac_17 / temp_var_for_callexp_5;

      z = temp_var_for_tac_18;
      computeDMul((Addr)&temp_var_for_tac_14, {(Addr)&u, (Addr)&cc},
                  "/home/shijia/Public/testprogram/e_j0.c_e.c:119:26");
      computeDMul((Addr)&temp_var_for_tac_15, {(Addr)&v, (Addr)&ss},
                  "/home/shijia/Public/testprogram/e_j0.c_e.c:119:35");
      computeDSub((Addr)&temp_var_for_tac_16,
                  {(Addr)&temp_var_for_tac_14, (Addr)&temp_var_for_tac_15},
                  "/home/shijia/Public/testprogram/e_j0.c_e.c:119:31");
      computeDMul((Addr)&temp_var_for_tac_17,
                  {(Addr) &(temp_var_for_const_13 = invsqrtpi),
                   (Addr)&temp_var_for_tac_16},
                  "/home/shijia/Public/testprogram/e_j0.c_e.c:119:21");
      computeDDiv((Addr)&temp_var_for_tac_18,
                  {(Addr)&temp_var_for_tac_17,
                   (Addr) &(temp_var_for_const_14 = temp_var_for_callexp_5)},
                  "/home/shijia/Public/testprogram/e_j0.c_e.c:119:41");
      AssignD({(Addr)&z}, (Addr)&temp_var_for_tac_18,
              "/home/shijia/Public/testprogram/e_j0.c_e.c:119:9");
      ;
    }
    double temp_var_for_ext_4;
    temp_var_for_ext_4 = z;
    AssignD({(Addr)&temp_var_for_ext_4}, (Addr)&z,
            "/home/shijia/Public/testprogram/e_j0.c_e.c:122:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_4;
  }
  if (ix < IC(0x3f200000)) {      /* |x| < 2**-13 */
    math_force_eval(hugeval + x); /* raise inexact if x != 0 */
    if (ix < IC(0x3e400000)) {
      double temp_var_for_ext_5;
      double temp_var_for_const_17;
      temp_var_for_ext_5 = one;
      computeDAdd((Addr)&temp_var_for_tac_19,
                  {(Addr) &(temp_var_for_const_15 = hugeval), (Addr)&x},
                  "/home/shijia/Public/testprogram/e_j0.c_e.c:128:5 "
                  "<Spelling=/home/shijia/Public/testprogram/"
                  "e_j0.c_e.c:128:29>");
      computeDAdd((Addr)&temp_var_for_tac_20,
                  {(Addr) &(temp_var_for_const_16 = hugeval), (Addr)&x},
                  "/home/shijia/Public/testprogram/e_j0.c_e.c:128:5 "
                  "<Spelling=/home/shijia/Public/testprogram/"
                  "e_j0.c_e.c:128:29>");
      AssignD({(Addr)&temp_var_for_ext_5},
              (Addr) &(temp_var_for_const_17 = one),
              "/home/shijia/Public/testprogram/e_j0.c_e.c:131:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_5;
    }
    /* |x|<2**-27 */
    else {
      double temp_var_for_ext_6;
      double temp_var_for_tac_21, temp_var_for_tac_22, temp_var_for_tac_23;
      double temp_var_for_const_18, temp_var_for_const_19;
      temp_var_for_tac_21 = 0.25 * x;

      temp_var_for_tac_22 = temp_var_for_tac_21 * x;

      temp_var_for_tac_23 = one - temp_var_for_tac_22;

      temp_var_for_ext_6 = temp_var_for_tac_23;
      computeDMul((Addr)&temp_var_for_tac_21,
                  {(Addr) &(temp_var_for_const_18 = 0.25), (Addr)&x},
                  "/home/shijia/Public/testprogram/e_j0.c_e.c:140:39");
      computeDMul((Addr)&temp_var_for_tac_22,
                  {(Addr)&temp_var_for_tac_21, (Addr)&x},
                  "/home/shijia/Public/testprogram/e_j0.c_e.c:140:43");
      computeDSub(
          (Addr)&temp_var_for_tac_23,
          {(Addr) &(temp_var_for_const_19 = one), (Addr)&temp_var_for_tac_22},
          "/home/shijia/Public/testprogram/e_j0.c_e.c:140:32");
      AssignD({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_23,
              "/home/shijia/Public/testprogram/e_j0.c_e.c:140:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_6;
    }
  }
  double temp_var_for_tac_24;
  temp_var_for_tac_24 = x * x;

  z = temp_var_for_tac_24;
  computeDMul((Addr)&temp_var_for_tac_24, {(Addr)&x, (Addr)&x},
              "/home/shijia/Public/testprogram/e_j0.c_e.c:147:9");
  AssignD({(Addr)&z}, (Addr)&temp_var_for_tac_24,
          "/home/shijia/Public/testprogram/e_j0.c_e.c:147:5");
  ;
#ifdef DO_NOT_USE_THIS
  r = z * (R02 + z * (R03 + z * (R04 + z * R05)));
  s = one + z * (S01 + z * (S02 + z * (S03 + z * S04)));
#else
  double temp_var_for_tac_25;
  double temp_var_for_const_20;
  temp_var_for_tac_25 = z * R02;

  r1 = temp_var_for_tac_25;
  computeDMul((Addr)&temp_var_for_tac_25,
              {(Addr)&z, (Addr) &(temp_var_for_const_20 = R02)},
              "/home/shijia/Public/testprogram/e_j0.c_e.c:152:10");
  AssignD({(Addr)&r1}, (Addr)&temp_var_for_tac_25,
          "/home/shijia/Public/testprogram/e_j0.c_e.c:152:6");
  ;
  double temp_var_for_tac_26;
  temp_var_for_tac_26 = z * z;

  z2 = temp_var_for_tac_26;
  computeDMul((Addr)&temp_var_for_tac_26, {(Addr)&z, (Addr)&z},
              "/home/shijia/Public/testprogram/e_j0.c_e.c:153:10");
  AssignD({(Addr)&z2}, (Addr)&temp_var_for_tac_26,
          "/home/shijia/Public/testprogram/e_j0.c_e.c:153:6");
  ;
  double temp_var_for_tac_27, temp_var_for_tac_28;
  double temp_var_for_const_21, temp_var_for_const_22;
  temp_var_for_tac_27 = z * R04;

  temp_var_for_tac_28 = R03 + temp_var_for_tac_27;

  r2 = temp_var_for_tac_28;
  computeDMul((Addr)&temp_var_for_tac_27,
              {(Addr)&z, (Addr) &(temp_var_for_const_21 = R04)},
              "/home/shijia/Public/testprogram/e_j0.c_e.c:154:16");
  computeDAdd(
      (Addr)&temp_var_for_tac_28,
      {(Addr) &(temp_var_for_const_22 = R03), (Addr)&temp_var_for_tac_27},
      "/home/shijia/Public/testprogram/e_j0.c_e.c:154:12");
  AssignD({(Addr)&r2}, (Addr)&temp_var_for_tac_28,
          "/home/shijia/Public/testprogram/e_j0.c_e.c:154:6");
  ;
  double temp_var_for_tac_29;
  temp_var_for_tac_29 = z2 * z2;

  z4 = temp_var_for_tac_29;
  computeDMul((Addr)&temp_var_for_tac_29, {(Addr)&z2, (Addr)&z2},
              "/home/shijia/Public/testprogram/e_j0.c_e.c:155:11");
  AssignD({(Addr)&z4}, (Addr)&temp_var_for_tac_29,
          "/home/shijia/Public/testprogram/e_j0.c_e.c:155:6");
  ;
  double temp_var_for_tac_30, temp_var_for_tac_31, temp_var_for_tac_32,
      temp_var_for_tac_33;
  double temp_var_for_const_23;
  temp_var_for_tac_30 = z2 * r2;

  temp_var_for_tac_31 = r1 + temp_var_for_tac_30;

  temp_var_for_tac_32 = z4 * R05;

  temp_var_for_tac_33 = temp_var_for_tac_31 + temp_var_for_tac_32;

  r = temp_var_for_tac_33;
  computeDMul((Addr)&temp_var_for_tac_30, {(Addr)&z2, (Addr)&r2},
              "/home/shijia/Public/testprogram/e_j0.c_e.c:156:15");
  computeDAdd((Addr)&temp_var_for_tac_31,
              {(Addr)&r1, (Addr)&temp_var_for_tac_30},
              "/home/shijia/Public/testprogram/e_j0.c_e.c:156:10");
  computeDMul((Addr)&temp_var_for_tac_32,
              {(Addr)&z4, (Addr) &(temp_var_for_const_23 = R05)},
              "/home/shijia/Public/testprogram/e_j0.c_e.c:156:25");
  computeDAdd((Addr)&temp_var_for_tac_33,
              {(Addr)&temp_var_for_tac_31, (Addr)&temp_var_for_tac_32},
              "/home/shijia/Public/testprogram/e_j0.c_e.c:156:20");
  AssignD({(Addr)&r}, (Addr)&temp_var_for_tac_33,
          "/home/shijia/Public/testprogram/e_j0.c_e.c:156:5");
  ;
  double temp_var_for_tac_34, temp_var_for_tac_35;
  double temp_var_for_const_24, temp_var_for_const_25;
  temp_var_for_tac_34 = z * S01;

  temp_var_for_tac_35 = one + temp_var_for_tac_34;

  s1 = temp_var_for_tac_35;
  computeDMul((Addr)&temp_var_for_tac_34,
              {(Addr)&z, (Addr) &(temp_var_for_const_24 = S01)},
              "/home/shijia/Public/testprogram/e_j0.c_e.c:157:16");
  computeDAdd(
      (Addr)&temp_var_for_tac_35,
      {(Addr) &(temp_var_for_const_25 = one), (Addr)&temp_var_for_tac_34},
      "/home/shijia/Public/testprogram/e_j0.c_e.c:157:12");
  AssignD({(Addr)&s1}, (Addr)&temp_var_for_tac_35,
          "/home/shijia/Public/testprogram/e_j0.c_e.c:157:6");
  ;
  double temp_var_for_tac_36, temp_var_for_tac_37;
  double temp_var_for_const_26, temp_var_for_const_27;
  temp_var_for_tac_36 = z * S03;

  temp_var_for_tac_37 = S02 + temp_var_for_tac_36;

  s2 = temp_var_for_tac_37;
  computeDMul((Addr)&temp_var_for_tac_36,
              {(Addr)&z, (Addr) &(temp_var_for_const_26 = S03)},
              "/home/shijia/Public/testprogram/e_j0.c_e.c:158:16");
  computeDAdd(
      (Addr)&temp_var_for_tac_37,
      {(Addr) &(temp_var_for_const_27 = S02), (Addr)&temp_var_for_tac_36},
      "/home/shijia/Public/testprogram/e_j0.c_e.c:158:12");
  AssignD({(Addr)&s2}, (Addr)&temp_var_for_tac_37,
          "/home/shijia/Public/testprogram/e_j0.c_e.c:158:6");
  ;
  double temp_var_for_tac_38, temp_var_for_tac_39, temp_var_for_tac_40,
      temp_var_for_tac_41;
  double temp_var_for_const_28;
  temp_var_for_tac_38 = z2 * s2;

  temp_var_for_tac_39 = s1 + temp_var_for_tac_38;

  temp_var_for_tac_40 = z4 * S04;

  temp_var_for_tac_41 = temp_var_for_tac_39 + temp_var_for_tac_40;

  s = temp_var_for_tac_41;
  computeDMul((Addr)&temp_var_for_tac_38, {(Addr)&z2, (Addr)&s2},
              "/home/shijia/Public/testprogram/e_j0.c_e.c:159:15");
  computeDAdd((Addr)&temp_var_for_tac_39,
              {(Addr)&s1, (Addr)&temp_var_for_tac_38},
              "/home/shijia/Public/testprogram/e_j0.c_e.c:159:10");
  computeDMul((Addr)&temp_var_for_tac_40,
              {(Addr)&z4, (Addr) &(temp_var_for_const_28 = S04)},
              "/home/shijia/Public/testprogram/e_j0.c_e.c:159:25");
  computeDAdd((Addr)&temp_var_for_tac_41,
              {(Addr)&temp_var_for_tac_39, (Addr)&temp_var_for_tac_40},
              "/home/shijia/Public/testprogram/e_j0.c_e.c:159:20");
  AssignD({(Addr)&s}, (Addr)&temp_var_for_tac_41,
          "/home/shijia/Public/testprogram/e_j0.c_e.c:159:5");
  ;
#endif
  if (ix < IC(0x3FF00000)) { /* |x| < 1.00 */
    double temp_var_for_ext_7;
    double temp_var_for_tac_42, temp_var_for_tac_43, temp_var_for_tac_44,
        temp_var_for_tac_45;
    double temp_var_for_const_29, temp_var_for_const_30;
    temp_var_for_tac_42 = r / s;

    temp_var_for_tac_43 = (-(0.25)) + temp_var_for_tac_42;

    temp_var_for_tac_44 = z * temp_var_for_tac_43;

    temp_var_for_tac_45 = one + temp_var_for_tac_44;

    temp_var_for_ext_7 = temp_var_for_tac_45;
    computeDDiv((Addr)&temp_var_for_tac_42, {(Addr)&r, (Addr)&s},
                "/home/shijia/Public/testprogram/e_j0.c_e.c:163:48");
    computeDAdd((Addr)&temp_var_for_tac_43,
                {(Addr) &(temp_var_for_const_29 = (-(0.25))),
                 (Addr)&temp_var_for_tac_42},
                "/home/shijia/Public/testprogram/e_j0.c_e.c:163:43");
    computeDMul((Addr)&temp_var_for_tac_44,
                {(Addr)&z, (Addr)&temp_var_for_tac_43},
                "/home/shijia/Public/testprogram/e_j0.c_e.c:163:34");
    computeDAdd(
        (Addr)&temp_var_for_tac_45,
        {(Addr) &(temp_var_for_const_30 = one), (Addr)&temp_var_for_tac_44},
        "/home/shijia/Public/testprogram/e_j0.c_e.c:163:30");
    AssignD({(Addr)&temp_var_for_ext_7}, (Addr)&temp_var_for_tac_45,
            "/home/shijia/Public/testprogram/e_j0.c_e.c:163:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
    callExp++; /*identify the function is  add move tmpShadow*/
    return te(0.0 - p_va) r_for_ext_7;
  } else {
    double temp_var_for_tac_46;
    double temp_var_for_const_31;
    temp_var_for_tac_46 = 0.5 * x;

    u = temp_var_for_tac_46;
    computeDMul((Addr)&temp_var_for_tac_46,
                {(Addr) &(temp_var_for_const_31 = 0.5), (Addr)&x},
                "/home/shijia/Public/testprogram/e_j0.c_e.c:168:13");
    AssignD({(Addr)&u}, (Addr)&temp_var_for_tac_46,
            "/home/shijia/Public/testprogram/e_j0.c_e.c:168:7");
    ;
    double temp_var_for_ext_8;
    double temp_var_for_tac_47, temp_var_for_tac_48, temp_var_for_tac_49,
        temp_var_for_tac_50, temp_var_for_tac_51, temp_var_for_tac_52;
    double temp_var_for_const_32, temp_var_for_const_33;
    temp_var_for_tac_47 = one + u;

    temp_var_for_tac_48 = one - u;

    temp_var_for_tac_49 = temp_var_for_tac_47 * temp_var_for_tac_48;

    temp_var_for_tac_50 = r / s;

    temp_var_for_tac_51 = z * temp_var_for_tac_50;

    temp_var_for_tac_52 = temp_var_for_tac_49 + temp_var_for_tac_51;

    temp_var_for_ext_8 = temp_var_for_tac_52;
    computeDAdd((Addr)&temp_var_for_tac_47,
                {(Addr) &(temp_var_for_const_32 = one), (Addr)&u},
                "/home/shijia/Public/testprogram/e_j0.c_e.c:170:32");
    computeDSub((Addr)&temp_var_for_tac_48,
                {(Addr) &(temp_var_for_const_33 = one), (Addr)&u},
                "/home/shijia/Public/testprogram/e_j0.c_e.c:170:44");
    computeDMul((Addr)&temp_var_for_tac_49,
                {(Addr)&temp_var_for_tac_47, (Addr)&temp_var_for_tac_48},
                "/home/shijia/Public/testprogram/e_j0.c_e.c:170:37");
    computeDDiv((Addr)&temp_var_for_tac_50, {(Addr)&r, (Addr)&s},
                "/home/shijia/Public/testprogram/e_j0.c_e.c:170:58");
    computeDMul((Addr)&temp_var_for_tac_51,
                {(Addr)&z, (Addr)&temp_var_for_tac_50},
                "/home/shijia/Public/testprogram/e_j0.c_e.c:170:53");
    computeDAdd((Addr)&temp_var_for_tac_52,
                {(Addr)&temp_var_for_tac_49, (Addr)&temp_var_for_tac_51},
                "/home/shijia/Public/testprogram/e_j0.c_e.c:170:49");
    AssignD({(Addr)&temp_var_for_ext_8}, (Addr)&temp_var_for_tac_52,
            "/home/shijia/Public/testprogram/e_j0.c_e.c:170:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_8;
  }
}

/* wrapper j0 */
double __j0(double x) {
  if (isgreater(__ieee754_fabs(x), X_TLOSS) && _LIB_VERSION != _IEEE_ &&
      _LIB_VERSION != _POSIX_)
  /* j0(|x|>X_TLOSS) */
  {
    double temp_var_for_ext_9;
    double temp_var_for_const_34;
    double temp_var_for_callexp_6;

    temp_var_for_callexp_6 = __kernel_standard(x, x, 0.0, KMATHERR_J0_TLOSS);
    temp_var_for_ext_9 = temp_var_for_callexp_6;
    AssignD({(Addr)&temp_var_for_ext_9},
            (Addr) &(temp_var_for_const_34 = temp_var_for_callexp_6),
            "/home/shijia/Public/testprogram/e_j0.c_e.c:184:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_9;
  }

  double temp_var_for_ext_10;
  double temp_var_for_const_35;
  double temp_var_for_callexp_7;

  temp_var_for_callexp_7 = __ieee754_j0(x);
  temp_var_for_ext_10 = temp_var_for_callexp_7;
  AssignD({(Addr)&temp_var_for_ext_10},
          (Addr) &(temp_var_for_const_35 = temp_var_for_callexp_7),
          "/home/shijia/Public/testprogram/e_j0.c_e.c:191:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_10", (Addr)&temp_var_for_ext_10));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_10;
}

__typeof(__j0) j0 __attribute__((weak, alias("__j0")));
#ifdef __NO_LONG_DOUBLE_MATH
__typeof(__j0l) __j0l __attribute__((alias("__j0")));
__typeof(__j0l) j0l __attribute__((weak, alias("__j0l")));
#endif
