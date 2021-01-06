#include "../ScDebug/scdebug.h"
/* @(#)e_y0.c 5.1 93/09/24 */
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
/* Modified by Naohiko Shimizu/Tokai University, Japan 1997/08/26,
   for performance improvement on pipelined processors.
*/
/* __ieee754_y0(x)
 * Bessel function of the second kind of order zero.
 *
 * Method -- y0(x):
 *	1. For x<2.
 *	   Since
 *		y0(x) = 2/pi*(j0(x)*(ln(x/2)+Euler) + x^2/4 - ...)
 *	   therefore y0(x)-2/pi*j0(x)*ln(x) is an even function.
 *	   We use the following function to approximate y0,
 *		y0(x) = U(z)/V(z) + (2/pi)*(j0(x)*ln(x)), z= x^2
 *	   where
 *		U(z) = u00 + u01*z + ... + u06*z^6
 *		V(z) = 1  + v01*z + ... + v04*z^4
 *	   with absolute approximation error bounded by 2**-72.
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

double __ieee754_y0(double x) {
  double z, s, c, ss, cc, u, v, z2, z4, z6, u1, u2, u3, v1, v2;
  int32_t hx, ix, lx;

  static const double one = 1.0;
  static const double zero = 0.0;
  static const double invsqrtpi =
      5.64189583547756279280e-01; /* 0x3FE20DD7, 0x50429B6D */
  static const double tpi =
      6.36619772367581382433e-01; /* 0x3FE45F30, 0x6DC9C883 */

  static const double u00 =
      (double temp_var_for_tac_0;
       double temp_var_for_const_0, temp_var_for_const_1;
       temp_var_for_tac_0 = 0.0 - 7.38042951086872317523e-02;

       ); /* 0xBFB2E4D6, 0x99CBD01F */
  static const double u01 =
      1.76666452509181115538e-01; /* 0x3FC69D01, 0x9DE9E3FC */
  static const double u02 =
      (double temp_var_for_tac_1;
       double temp_var_for_const_2, temp_var_for_const_3;
       temp_var_for_tac_1 = 0.0 - 1.38185671945596898896e-02;

       ); /* 0xBF8C4CE8, 0xB16CFA97 */
  static const double u03 =
      3.47453432093683650238e-04; /* 0x3F36C54D, 0x20B29B6B */
  static const double u04 =
      (double temp_var_for_tac_2;
       double temp_var_for_const_4, temp_var_for_const_5;
       temp_var_for_tac_2 = 0.0 - 3.81407053724364161125e-06;

       ); /* 0xBECFFEA7, 0x73D25CAD */
  static const double u05 =
      1.95590137035022920206e-08; /* 0x3E550057, 0x3B4EABD4 */
  static const double u06 =
      (double temp_var_for_tac_3;
       double temp_var_for_const_6, temp_var_for_const_7;
       temp_var_for_tac_3 = 0.0 - 3.98205194132103398453e-11;

       ); /* 0xBDC5E43D, 0x693FB3C8 */

  static const double v01 =
      1.27304834834123699328e-02; /* 0x3F8A1270, 0x91C9C71A */
  static const double v02 =
      7.60068627350353253702e-05; /* 0x3F13ECBB, 0xF578C6C1 */
  static const double v03 =
      2.59150851840457805467e-07; /* 0x3E91642D, 0x7FF202FD */
  static const double v04 =
      4.41110311332675467403e-10; /* 0x3DFE5018, 0x3BD6D9EF */

  GET_DOUBLE_WORDS(hx, lx, x);
  ix = IC(0x7fffffff) & hx;
  /* Y0(NaN) is NaN, y0(-inf) is Nan, y0(inf) is 0  */
  if (ix >= IC(0x7ff00000)) {
    double temp_var_for_ext_0;
    double temp_var_for_tac_4, temp_var_for_tac_5, temp_var_for_tac_6;
    double temp_var_for_const_8;
    temp_var_for_tac_4 = x * x;

    temp_var_for_tac_5 = x + temp_var_for_tac_4;

    temp_var_for_tac_6 = one / temp_var_for_tac_5;

    temp_var_for_ext_0 = temp_var_for_tac_6;
    computeDSub((Addr)&temp_var_for_tac_0,
                {(Addr) &(temp_var_for_const_1 = 0.0),
                 (Addr) &(temp_var_for_const_0 = 7.38042951086872317523e-02)},
                "/home/shijia/Public/testprogram/e_y0.c_e.c:54:12");
    computeDSub((Addr)&temp_var_for_tac_1,
                {(Addr) &(temp_var_for_const_3 = 0.0),
                 (Addr) &(temp_var_for_const_2 = 1.38185671945596898896e-02)},
                "/home/shijia/Public/testprogram/e_y0.c_e.c:58:12");
    computeDSub((Addr)&temp_var_for_tac_2,
                {(Addr) &(temp_var_for_const_5 = 0.0),
                 (Addr) &(temp_var_for_const_4 = 3.81407053724364161125e-06)},
                "/home/shijia/Public/testprogram/e_y0.c_e.c:62:12");
    computeDSub((Addr)&temp_var_for_tac_3,
                {(Addr) &(temp_var_for_const_7 = 0.0),
                 (Addr) &(temp_var_for_const_6 = 3.98205194132103398453e-11)},
                "/home/shijia/Public/testprogram/e_y0.c_e.c:66:12");
    computeDMul((Addr)&temp_var_for_tac_4, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_y0.c_e.c:82:39");
    computeDAdd((Addr)&temp_var_for_tac_5,
                {(Addr)&x, (Addr)&temp_var_for_tac_4},
                "/home/shijia/Public/testprogram/e_y0.c_e.c:82:35");
    computeDDiv(
        (Addr)&temp_var_for_tac_6,
        {(Addr) &(temp_var_for_const_8 = one), (Addr)&temp_var_for_tac_5},
        "/home/shijia/Public/testprogram/e_y0.c_e.c:82:30");
    AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_6,
            "/home/shijia/Public/testprogram/e_y0.c_e.c:82:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  if ((ix | lx) == 0) {
    double temp_var_for_ext_1;
    double temp_var_for_tac_7;
    double temp_var_for_const_9;
    temp_var_for_callexp_0 = __builtin_huge_val();
    temp_var_for_tac_7 = (-(temp_var_for_callexp_0)) + x;

    temp_var_for_ext_1 = temp_var_for_tac_7;
    computeDAdd((Addr)&temp_var_for_tac_7,
                {(Addr) &(temp_var_for_const_9 = (-(temp_var_for_callexp_0))),
                 (Addr)&x},
                "/home/shijia/Public/testprogram/e_y0.c_e.c:90:36");
    AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_7,
            "/home/shijia/Public/testprogram/e_y0.c_e.c:90:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return (0.0 - ar_for_e)xt_1;
  }
  /* -inf and overflow exception.  */
  if (hx < 0) {
    double temp_var_for_ext_2;
    double temp_var_for_tac_8;
    double temp_var_for_const_10, temp_var_for_const_11;
    temp_var_for_tac_8 = zero / zero;

    temp_var_for_ext_2 = temp_var_for_tac_8;
    computeDDiv((Addr)&temp_var_for_tac_8,
                {(Addr) &(temp_var_for_const_11 = zero),
                 (Addr) &(temp_var_for_const_10 = zero)},
                "/home/shijia/Public/testprogram/e_y0.c_e.c:98:31");
    AssignD({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_8,
            "/home/shijia/Public/testprogram/e_y0.c_e.c:98:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  }

  if (ix >= IC(0x40000000)) { /* |x| >= 2.0 */
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
    __ieee754_sincos(x, &s, &c);
    double temp_var_for_tac_9;
    temp_var_for_tac_9 = s - c;

    ss = temp_var_for_tac_9;
    computeDSub((Addr)&temp_var_for_tac_9, {(Addr)&s, (Addr)&c},
                "/home/shijia/Public/testprogram/e_y0.c_e.c:117:12");
    AssignD({(Addr)&ss}, (Addr)&temp_var_for_tac_9,
            "/home/shijia/Public/testprogram/e_y0.c_e.c:117:8");
    ;
    double temp_var_for_tac_10;
    temp_var_for_tac_10 = s + c;

    cc = temp_var_for_tac_10;
    computeDAdd((Addr)&temp_var_for_tac_10, {(Addr)&s, (Addr)&c},
                "/home/shijia/Public/testprogram/e_y0.c_e.c:118:12");
    AssignD({(Addr)&cc}, (Addr)&temp_var_for_tac_10,
            "/home/shijia/Public/testprogram/e_y0.c_e.c:118:8");
    ;
    /*
     * j0(x) = 1/sqrt(pi) * (P(0,x)*cc - Q(0,x)*ss) / sqrt(x)
     * y0(x) = 1/sqrt(pi) * (P(0,x)*ss + Q(0,x)*cc) / sqrt(x)
     */
    if (ix < IC(0x7fe00000)) { /* make sure x+x not overflow */
      double temp_var_for_tac_11, temp_var_for_tac_12;
      double temp_var_for_const_12, temp_var_for_const_13;
      double temp_var_for_callexp_1;

      temp_var_for_tac_11 = x + x;

      temp_var_for_callexp_1 = __ieee754_cos(temp_var_for_tac_11);
      temp_var_for_tac_12 = 0.0 - temp_var_for_callexp_1;

      z = temp_var_for_tac_12;
      computeDAdd((Addr)&temp_var_for_tac_11, {(Addr)&x, (Addr)&x},
                  "/home/shijia/Public/testprogram/e_y0.c_e.c:124:34");
      computeDSub((Addr)&temp_var_for_tac_12,
                  {(Addr) &(temp_var_for_const_13 = 0.0),
                   (Addr) &(temp_var_for_const_12 = temp_var_for_callexp_1)},
                  "/home/shijia/Public/testprogram/e_y0.c_e.c:124:16");
      AssignD({(Addr)&z}, (Addr)&temp_var_for_tac_12,
              "/home/shijia/Public/testprogram/e_y0.c_e.c:124:9");
      ;
      if (int temp_var_for_tac_13, temp_var_for_tac_14;
          int temp_var_for_const_14; temp_var_for_tac_13 = s * c;

          temp_var_for_tac_14 = temp_var_for_tac_13 < zero;

          ) {
        double temp_var_for_tac_15;
        temp_var_for_tac_15 = z / ss;

        cc = temp_var_for_tac_15;
        computeDMul((Addr)&temp_var_for_tac_13, {(Addr)&s, (Addr)&c},
                    "/home/shijia/Public/testprogram/e_y0.c_e.c:125:14");
        compute((Addr)&temp_var_for_tac_14,
                {(Addr)&temp_var_for_tac_13,
                 (Addr) &(temp_var_for_const_14 = zero)},
                "/home/shijia/Public/testprogram/e_y0.c_e.c:125:19");
        computeDDiv((Addr)&temp_var_for_tac_15, {(Addr)&z, (Addr)&ss},
                    "/home/shijia/Public/testprogram/e_y0.c_e.c:126:16");
        AssignD({(Addr)&cc}, (Addr)&temp_var_for_tac_15,
                "/home/shijia/Public/testprogram/e_y0.c_e.c:126:12");
        ;
      }

      else {
        double temp_var_for_ext_3;
        double temp_var_for_tac_16;
        temp_var_for_tac_16 = z / cc;

        temp_var_for_ext_3 = temp_var_for_tac_16;
        computeDDiv((Addr)&temp_var_for_tac_16, {(Addr)&z, (Addr)&cc},
                    "/home/shijia/Public/testprogram/e_y0.c_e.c:131:32");
        AssignD({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_16,
                "/home/shijia/Public/testprogram/e_y0.c_e.c:131:28");
        ; // ss
        /*(ss)(z)(cc)(z)*/
        ss = temp_var_for_ext_3;
        AssignD({(Addr)&ss}, (Addr)&temp_var_for_ext_3,
                "/home/shijia/Public/testprogram/e_y0.c_e.c:133:12");
        ;
      }
    }
    if (ix > IC(0x48000000)) {
      double temp_var_for_ext_4;
      double temp_var_for_tac_17, temp_var_for_tac_18;
      double temp_var_for_const_15, temp_var_for_const_16;
      double temp_var_for_callexp_2;

      temp_var_for_tac_17 = invsqrtpi * ss;

      temp_var_for_callexp_2 = __ieee754_sqrt(x);
      temp_var_for_tac_18 = temp_var_for_tac_17 / temp_var_for_callexp_2;

      temp_var_for_ext_4 = temp_var_for_tac_18;
      computeDMul((Addr)&temp_var_for_tac_17,
                  {(Addr) &(temp_var_for_const_15 = invsqrtpi), (Addr)&ss},
                  "/home/shijia/Public/testprogram/e_y0.c_e.c:138:39");
      computeDDiv((Addr)&temp_var_for_tac_18,
                  {(Addr)&temp_var_for_tac_17,
                   (Addr) &(temp_var_for_const_16 = temp_var_for_callexp_2)},
                  "/home/shijia/Public/testprogram/e_y0.c_e.c:138:45");
      AssignD({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_18,
              "/home/shijia/Public/testprogram/e_y0.c_e.c:138:26");
      ; // z
      /*(cc)(z)(__ieee754_sqrt(x))(ss)(invsqrtpi)*/
      z = temp_var_for_ext_4;
      AssignD({(Addr)&z}, (Addr)&temp_var_for_ext_4,
              "/home/shijia/Public/testprogram/e_y0.c_e.c:140:9");
      ;
    }

    else {
      double temp_var_for_const_17;
      double temp_var_for_callexp_3;

      temp_var_for_callexp_3 = __j0_y0_pzero(x);
      u = temp_var_for_callexp_3;
      AssignD({(Addr)&u},
              (Addr) &(temp_var_for_const_17 = temp_var_for_callexp_3),
              "/home/shijia/Public/testprogram/e_y0.c_e.c:144:9");
      ;
      double temp_var_for_const_18;
      double temp_var_for_callexp_4;

      temp_var_for_callexp_4 = __j0_y0_qzero(x);
      v = temp_var_for_callexp_4;
      AssignD({(Addr)&v},
              (Addr) &(temp_var_for_const_18 = temp_var_for_callexp_4),
              "/home/shijia/Public/testprogram/e_y0.c_e.c:145:9");
      ;
      double temp_var_for_tac_19, temp_var_for_tac_20, temp_var_for_tac_21,
          temp_var_for_tac_22, temp_var_for_tac_23;
      double temp_var_for_const_19, temp_var_for_const_20;
      double temp_var_for_callexp_5;

      temp_var_for_tac_19 = u * ss;

      temp_var_for_tac_20 = v * cc;

      temp_var_for_tac_21 = temp_var_for_tac_19 + temp_var_for_tac_20;

      temp_var_for_tac_22 = invsqrtpi * temp_var_for_tac_21;

      temp_var_for_callexp_5 = __ieee754_sqrt(x);
      temp_var_for_tac_23 = temp_var_for_tac_22 / temp_var_for_callexp_5;

      z = temp_var_for_tac_23;
      computeDMul((Addr)&temp_var_for_tac_19, {(Addr)&u, (Addr)&ss},
                  "/home/shijia/Public/testprogram/e_y0.c_e.c:146:26");
      computeDMul((Addr)&temp_var_for_tac_20, {(Addr)&v, (Addr)&cc},
                  "/home/shijia/Public/testprogram/e_y0.c_e.c:146:35");
      computeDAdd((Addr)&temp_var_for_tac_21,
                  {(Addr)&temp_var_for_tac_19, (Addr)&temp_var_for_tac_20},
                  "/home/shijia/Public/testprogram/e_y0.c_e.c:146:31");
      computeDMul((Addr)&temp_var_for_tac_22,
                  {(Addr) &(temp_var_for_const_19 = invsqrtpi),
                   (Addr)&temp_var_for_tac_21},
                  "/home/shijia/Public/testprogram/e_y0.c_e.c:146:21");
      computeDDiv((Addr)&temp_var_for_tac_23,
                  {(Addr)&temp_var_for_tac_22,
                   (Addr) &(temp_var_for_const_20 = temp_var_for_callexp_5)},
                  "/home/shijia/Public/testprogram/e_y0.c_e.c:146:41");
      AssignD({(Addr)&z}, (Addr)&temp_var_for_tac_23,
              "/home/shijia/Public/testprogram/e_y0.c_e.c:146:9");
      ;
    }
    double temp_var_for_ext_5;
    temp_var_for_ext_5 = z;
    AssignD({(Addr)&temp_var_for_ext_5}, (Addr)&z,
            "/home/shijia/Public/testprogram/e_y0.c_e.c:149:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_5;
  }
  if (ix <= IC(0x3e400000)) { /* x < 2**-27 */
    double temp_var_for_ext_6;
    double temp_var_for_tac_24, temp_var_for_tac_25;
    double temp_var_for_const_21, temp_var_for_const_22, temp_var_for_const_23;
    double temp_var_for_callexp_6;

    temp_var_for_callexp_6 = __ieee754_log(x);
    temp_var_for_tac_24 = tpi * temp_var_for_callexp_6;

    temp_var_for_tac_25 = u00 + temp_var_for_tac_24;

    temp_var_for_ext_6 = temp_var_for_tac_25;
    computeDMul((Addr)&temp_var_for_tac_24,
                {(Addr) &(temp_var_for_const_22 = tpi),
                 (Addr) &(temp_var_for_const_21 = temp_var_for_callexp_6)},
                "/home/shijia/Public/testprogram/e_y0.c_e.c:156:37");
    computeDAdd(
        (Addr)&temp_var_for_tac_25,
        {(Addr) &(temp_var_for_const_23 = u00), (Addr)&temp_var_for_tac_24},
        "/home/shijia/Public/testprogram/e_y0.c_e.c:156:31");
    AssignD({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_25,
            "/home/shijia/Public/testprogram/e_y0.c_e.c:156:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_6;
  }
  double temp_var_for_tac_26;
  temp_var_for_tac_26 = x * x;

  z = temp_var_for_tac_26;
  computeDMul((Addr)&temp_var_for_tac_26, {(Addr)&x, (Addr)&x},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:161:9");
  AssignD({(Addr)&z}, (Addr)&temp_var_for_tac_26,
          "/home/shijia/Public/testprogram/e_y0.c_e.c:161:5");
  ;
#ifdef DO_NOT_USE_THIS
  u = u00 + z * (u01 + z * (u02 + z * (u03 + z * (u04 + z * (u05 + z * u06)))));
  v = one + z * (v01 + z * (v02 + z * (v03 + z * v04)));
#else
  double temp_var_for_tac_27, temp_var_for_tac_28;
  double temp_var_for_const_24, temp_var_for_const_25;
  temp_var_for_tac_27 = z * u01;

  temp_var_for_tac_28 = u00 + temp_var_for_tac_27;

  u1 = temp_var_for_tac_28;
  computeDMul((Addr)&temp_var_for_tac_27,
              {(Addr)&z, (Addr) &(temp_var_for_const_24 = u01)},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:166:16");
  computeDAdd(
      (Addr)&temp_var_for_tac_28,
      {(Addr) &(temp_var_for_const_25 = u00), (Addr)&temp_var_for_tac_27},
      "/home/shijia/Public/testprogram/e_y0.c_e.c:166:12");
  AssignD({(Addr)&u1}, (Addr)&temp_var_for_tac_28,
          "/home/shijia/Public/testprogram/e_y0.c_e.c:166:6");
  ;
  double temp_var_for_tac_29;
  temp_var_for_tac_29 = z * z;

  z2 = temp_var_for_tac_29;
  computeDMul((Addr)&temp_var_for_tac_29, {(Addr)&z, (Addr)&z},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:167:10");
  AssignD({(Addr)&z2}, (Addr)&temp_var_for_tac_29,
          "/home/shijia/Public/testprogram/e_y0.c_e.c:167:6");
  ;
  double temp_var_for_tac_30, temp_var_for_tac_31;
  double temp_var_for_const_26, temp_var_for_const_27;
  temp_var_for_tac_30 = z * u03;

  temp_var_for_tac_31 = u02 + temp_var_for_tac_30;

  u2 = temp_var_for_tac_31;
  computeDMul((Addr)&temp_var_for_tac_30,
              {(Addr)&z, (Addr) &(temp_var_for_const_26 = u03)},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:168:16");
  computeDAdd(
      (Addr)&temp_var_for_tac_31,
      {(Addr) &(temp_var_for_const_27 = u02), (Addr)&temp_var_for_tac_30},
      "/home/shijia/Public/testprogram/e_y0.c_e.c:168:12");
  AssignD({(Addr)&u2}, (Addr)&temp_var_for_tac_31,
          "/home/shijia/Public/testprogram/e_y0.c_e.c:168:6");
  ;
  double temp_var_for_tac_32;
  temp_var_for_tac_32 = z2 * z2;

  z4 = temp_var_for_tac_32;
  computeDMul((Addr)&temp_var_for_tac_32, {(Addr)&z2, (Addr)&z2},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:169:11");
  AssignD({(Addr)&z4}, (Addr)&temp_var_for_tac_32,
          "/home/shijia/Public/testprogram/e_y0.c_e.c:169:6");
  ;
  double temp_var_for_tac_33, temp_var_for_tac_34;
  double temp_var_for_const_28, temp_var_for_const_29;
  temp_var_for_tac_33 = z * u05;

  temp_var_for_tac_34 = u04 + temp_var_for_tac_33;

  u3 = temp_var_for_tac_34;
  computeDMul((Addr)&temp_var_for_tac_33,
              {(Addr)&z, (Addr) &(temp_var_for_const_28 = u05)},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:170:16");
  computeDAdd(
      (Addr)&temp_var_for_tac_34,
      {(Addr) &(temp_var_for_const_29 = u04), (Addr)&temp_var_for_tac_33},
      "/home/shijia/Public/testprogram/e_y0.c_e.c:170:12");
  AssignD({(Addr)&u3}, (Addr)&temp_var_for_tac_34,
          "/home/shijia/Public/testprogram/e_y0.c_e.c:170:6");
  ;
  double temp_var_for_tac_35;
  temp_var_for_tac_35 = z4 * z2;

  z6 = temp_var_for_tac_35;
  computeDMul((Addr)&temp_var_for_tac_35, {(Addr)&z4, (Addr)&z2},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:171:11");
  AssignD({(Addr)&z6}, (Addr)&temp_var_for_tac_35,
          "/home/shijia/Public/testprogram/e_y0.c_e.c:171:6");
  ;
  double temp_var_for_tac_36, temp_var_for_tac_37, temp_var_for_tac_38,
      temp_var_for_tac_39, temp_var_for_tac_40, temp_var_for_tac_41;
  double temp_var_for_const_30;
  temp_var_for_tac_36 = z2 * u2;

  temp_var_for_tac_37 = u1 + temp_var_for_tac_36;

  temp_var_for_tac_38 = z4 * u3;

  temp_var_for_tac_39 = temp_var_for_tac_37 + temp_var_for_tac_38;

  temp_var_for_tac_40 = z6 * u06;

  temp_var_for_tac_41 = temp_var_for_tac_39 + temp_var_for_tac_40;

  u = temp_var_for_tac_41;
  computeDMul((Addr)&temp_var_for_tac_36, {(Addr)&z2, (Addr)&u2},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:172:15");
  computeDAdd((Addr)&temp_var_for_tac_37,
              {(Addr)&u1, (Addr)&temp_var_for_tac_36},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:172:10");
  computeDMul((Addr)&temp_var_for_tac_38, {(Addr)&z4, (Addr)&u3},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:172:25");
  computeDAdd((Addr)&temp_var_for_tac_39,
              {(Addr)&temp_var_for_tac_37, (Addr)&temp_var_for_tac_38},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:172:20");
  computeDMul((Addr)&temp_var_for_tac_40,
              {(Addr)&z6, (Addr) &(temp_var_for_const_30 = u06)},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:172:35");
  computeDAdd((Addr)&temp_var_for_tac_41,
              {(Addr)&temp_var_for_tac_39, (Addr)&temp_var_for_tac_40},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:172:30");
  AssignD({(Addr)&u}, (Addr)&temp_var_for_tac_41,
          "/home/shijia/Public/testprogram/e_y0.c_e.c:172:5");
  ;
  double temp_var_for_tac_42, temp_var_for_tac_43;
  double temp_var_for_const_31, temp_var_for_const_32;
  temp_var_for_tac_42 = z * v01;

  temp_var_for_tac_43 = one + temp_var_for_tac_42;

  v1 = temp_var_for_tac_43;
  computeDMul((Addr)&temp_var_for_tac_42,
              {(Addr)&z, (Addr) &(temp_var_for_const_31 = v01)},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:173:16");
  computeDAdd(
      (Addr)&temp_var_for_tac_43,
      {(Addr) &(temp_var_for_const_32 = one), (Addr)&temp_var_for_tac_42},
      "/home/shijia/Public/testprogram/e_y0.c_e.c:173:12");
  AssignD({(Addr)&v1}, (Addr)&temp_var_for_tac_43,
          "/home/shijia/Public/testprogram/e_y0.c_e.c:173:6");
  ;
  double temp_var_for_tac_44, temp_var_for_tac_45;
  double temp_var_for_const_33, temp_var_for_const_34;
  temp_var_for_tac_44 = z * v03;

  temp_var_for_tac_45 = v02 + temp_var_for_tac_44;

  v2 = temp_var_for_tac_45;
  computeDMul((Addr)&temp_var_for_tac_44,
              {(Addr)&z, (Addr) &(temp_var_for_const_33 = v03)},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:174:16");
  computeDAdd(
      (Addr)&temp_var_for_tac_45,
      {(Addr) &(temp_var_for_const_34 = v02), (Addr)&temp_var_for_tac_44},
      "/home/shijia/Public/testprogram/e_y0.c_e.c:174:12");
  AssignD({(Addr)&v2}, (Addr)&temp_var_for_tac_45,
          "/home/shijia/Public/testprogram/e_y0.c_e.c:174:6");
  ;
  double temp_var_for_tac_46, temp_var_for_tac_47, temp_var_for_tac_48,
      temp_var_for_tac_49;
  double temp_var_for_const_35;
  temp_var_for_tac_46 = z2 * v2;

  temp_var_for_tac_47 = v1 + temp_var_for_tac_46;

  temp_var_for_tac_48 = z4 * v04;

  temp_var_for_tac_49 = temp_var_for_tac_47 + temp_var_for_tac_48;

  v = temp_var_for_tac_49;
  computeDMul((Addr)&temp_var_for_tac_46, {(Addr)&z2, (Addr)&v2},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:175:15");
  computeDAdd((Addr)&temp_var_for_tac_47,
              {(Addr)&v1, (Addr)&temp_var_for_tac_46},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:175:10");
  computeDMul((Addr)&temp_var_for_tac_48,
              {(Addr)&z4, (Addr) &(temp_var_for_const_35 = v04)},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:175:25");
  computeDAdd((Addr)&temp_var_for_tac_49,
              {(Addr)&temp_var_for_tac_47, (Addr)&temp_var_for_tac_48},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:175:20");
  AssignD({(Addr)&v}, (Addr)&temp_var_for_tac_49,
          "/home/shijia/Public/testprogram/e_y0.c_e.c:175:5");
  ;
#endif
  double temp_var_for_ext_7;
  double temp_var_for_tac_50, temp_var_for_tac_51, temp_var_for_tac_52,
      temp_var_for_tac_53;
  double temp_var_for_const_36, temp_var_for_const_37, temp_var_for_const_38;
  double temp_var_for_callexp_7;

  double temp_var_for_callexp_8;

  temp_var_for_tac_50 = u / v;

  temp_var_for_callexp_7 = __ieee754_j0(x);
  temp_var_for_callexp_8 = __ieee754_log(x);
  temp_var_for_tac_51 = temp_var_for_callexp_7 * temp_var_for_callexp_8;

  temp_var_for_tac_52 = tpi * temp_var_for_tac_51;

  temp_var_for_tac_53 = temp_var_for_tac_50 + temp_var_for_tac_52;

  temp_var_for_ext_7 = temp_var_for_tac_53;
  computeDDiv((Addr)&temp_var_for_tac_50, {(Addr)&u, (Addr)&v},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:178:27");
  computeDMul((Addr)&temp_var_for_tac_51,
              {(Addr) &(temp_var_for_const_37 = temp_var_for_callexp_7),
               (Addr) &(temp_var_for_const_36 = temp_var_for_callexp_8)},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:178:56");
  computeDMul(
      (Addr)&temp_var_for_tac_52,
      {(Addr) &(temp_var_for_const_38 = tpi), (Addr)&temp_var_for_tac_51},
      "/home/shijia/Public/testprogram/e_y0.c_e.c:178:37");
  computeDAdd((Addr)&temp_var_for_tac_53,
              {(Addr)&temp_var_for_tac_50, (Addr)&temp_var_for_tac_52},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:178:31");
  AssignD({(Addr)&temp_var_for_ext_7}, (Addr)&temp_var_for_tac_53,
          "/home/shijia/Public/testprogram/e_y0.c_e.c:178:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_7;
}

/* wrapper y0 */
double __y0(double x) {
  if ((islessequal(x, 0.0) || isgreater(x, X_TLOSS)) &&
      _LIB_VERSION != _IEEE_) {
    if (int temp_var_for_tac_54; int temp_var_for_const_39;
        temp_var_for_tac_54 = x < 0.0;

        ) {
      /* d = zero/(x-x) */
      feraiseexcept(FE_INVALID);
      double temp_var_for_ext_8;
      double temp_var_for_const_40;
      double temp_var_for_callexp_10;

      temp_var_for_callexp_9 = __builtin_huge_val();
      temp_var_for_callexp_10 = __kernel_standard(
          x, x, (-(temp_var_for_callexp_9)), KMATHERR_Y0_MINUS);
      temp_var_for_ext_8 = temp_var_for_callexp_10;
      compute((Addr)&temp_var_for_tac_54,
              {(Addr)&x, (Addr) &(temp_var_for_const_39 = 0.0)},
              "/home/shijia/Public/testprogram/e_y0.c_e.c:188:11");
      AssignD({(Addr)&temp_var_for_ext_8},
              (Addr) &(temp_var_for_const_40 = temp_var_for_callexp_10),
              "/home/shijia/Public/testprogram/e_y0.c_e.c:192:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
      callExp++; /*identify the function is  add move tmpShado(0.0 - */
retur)n temp_var_for_ext_8;
    } else {
      if (int temp_var_for_tac_55; int temp_var_for_const_41;
          temp_var_for_tac_55 = x == 0.0;

          )
      /* d = -one/(x-x) */
      {
        double temp_var_for_ext_9;
        double temp_var_for_const_42;
        double temp_var_for_callexp_12;

        temp_var_for_callexp_11 = __builtin_huge_val();
        temp_var_for_callexp_12 = __kernel_standard(
            x, x, (-(temp_var_for_callexp_11)), KMATHERR_Y0_ZERO);
        temp_var_for_ext_9 = temp_var_for_callexp_12;
        compute((Addr)&temp_var_for_tac_55,
                {(Addr)&x, (Addr) &(temp_var_for_const_41 = 0.0)},
                "/home/shijia/Public/testprogram/e_y0.c_e.c:199:13");
        AssignD({(Addr)&temp_var_for_ext_9},
                (Addr) &(temp_var_for_const_42 = temp_var_for_callexp_12),
                "/home/shijia/Public/testprogram/e_y0.c_e.c:203:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
        callExp++; /*identify the function is  add move tmpShadow(0.0 - /
       return) temp_var_for_ext_9;
       }

                       else {
       if (_LIB_VERSION != _POSIX_)
                               /* y0(x>X_TLOSS) */
        {
          double temp_var_for_ext_10;
          double temp_var_for_const_43;
          double temp_var_for_callexp_13;

          temp_var_for_callexp_13 =
              __kernel_standard(x, x, 0.0, KMATHERR_Y0_TLOSS);
          temp_var_for_ext_10 = temp_var_for_callexp_13;
          AssignD({(Addr)&temp_var_for_ext_10},
                  (Addr) &(temp_var_for_const_43 = temp_var_for_callexp_13),
                  "/home/shijia/Public/testprogram/e_y0.c_e.c:216:31");
          ;
          callExpStack.push(
              getReal("temp_var_for_ext_10", (Addr)&temp_var_for_ext_10));
          callExp++; /*identify the function is  add move tmpShadow*/
          return temp_var_for_ext_10;
        }
      }
    }
  }

  double temp_var_for_ext_11;
  double temp_var_for_const_44;
  double temp_var_for_callexp_14;

  temp_var_for_callexp_14 = __ieee754_y0(x);
  temp_var_for_ext_11 = temp_var_for_callexp_14;
  AssignD({(Addr)&temp_var_for_ext_11},
          (Addr) &(temp_var_for_const_44 = temp_var_for_callexp_14),
          "/home/shijia/Public/testprogram/e_y0.c_e.c:227:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_11", (Addr)&temp_var_for_ext_11));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_11;
}

__typeof(__y0) y0 __attribute__((weak, alias("__y0")));
#ifdef __NO_LONG_DOUBLE_MATH
__typeof(__y0l) __y0l __attribute__((alias("__y0")));
__typeof(__y0l) y0l __attribute__((weak, alias("__y0l")));
#endif
