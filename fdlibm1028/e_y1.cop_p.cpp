#include "../ScDebug/scdebug.h"
/* @(#)e_y1.c 5.1 93/09/24 */
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

/* __ieee754_y1(x)
 * Bessel function of the second kind of order one.
 * Method -- y1(x):
 *	1. screen out x<=0 cases: y1(0)=-inf, y1(x<0)=NaN
 *	2. For x<2.
 *	   Since
 *		y1(x) = 2/pi*(j1(x)*(ln(x/2)+Euler)-1/x-x/2+5/64*x^3-...)
 *	   therefore y1(x)-2/pi*j1(x)*ln(x)-1/x is an odd function.
 *	   We use the following function to approximate y1,
 *		y1(x) = x*U(z)/V(z) + (2/pi)*(j1(x)*ln(x)-1/x), z= x^2
 *	   where for x in [0,2] (abs err less than 2**-65.89)
 *		U(z) = U0[0] + U0[1]*z + ... + U0[4]*z^4
 *		V(z) = 1  + v0[0]*z + ... + v0[4]*z^5
 *	   Note: For tiny x, 1/x dominate y1 and hence
 *		y1(tiny) = -2/pi/tiny, (choose tiny<2**-54)
 *	3. For x>=2.
 *		y1(x) = sqrt(2/(pi*x))*(p1(x)*sin(x1)+q1(x)*cos(x1))
 *	   where x1 = x-3*pi/4. It is better to compute sin(x1),cos(x1)
 *	   by method mentioned above.
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

double __ieee754_y1(double x) {
  double z, s, c, ss, cc, u, v, u1, u2, v1, v2, v3, z2, z4;
  int32_t hx, ix, lx;

  static const double one = 1.0;
  static const double invsqrtpi =
      5.64189583547756279280e-01; /* 0x3FE20DD7, 0x50429B6D */
  static const double tpi =
      6.36619772367581382433e-01; /* 0x3FE45F30, 0x6DC9C883 */
  static const double zero = 0.0;

  static const double U0[5] = {
      (double temp_var_for_tac_0;
  double temp_var_for_const_0, temp_var_for_const_1;
  temp_var_for_tac_0 = 0.0 - 1.96057090646238940668e-01;

), /* 0xBFC91866, 0x143CBC8A */
      5.04438716639811282616e-02,         /* 0x3FA9D3C7, 0x76292CD1 */
      (double temp_var_for_tac_1;double temp_var_for_const_2,temp_var_for_const_3;temp_var_for_tac_1 = 0.0 - 1.91256895875763547298e-03;

), /* 0xBF5F55E5, 0x4844F50F */
      2.35252600561610495928e-05,         /* 0x3EF8AB03, 0x8FA6B88E */
      (double temp_var_for_tac_2;double temp_var_for_const_4,temp_var_for_const_5;temp_var_for_tac_2 = 0.0 - 9.19099158039878874504e-08;

)  /* 0xBE78AC00, 0x569105B8 */
};

static const double V0[5] = {
    1.99167318236649903973e-02, /* 0x3F94650D, 0x3F4DA9F0 */
    2.02552581025135171496e-04, /* 0x3F2A8C89, 0x6C257764 */
    1.35608801097516229404e-06, /* 0x3EB6C05A, 0x894E8CA6 */
    6.22741452364621501295e-09, /* 0x3E3ABF1D, 0x5BA69A86 */
    1.66559246207992079114e-11  /* 0x3DB25039, 0xDACA772A */
};

GET_DOUBLE_WORDS(hx, lx, x);
ix = IC(0x7fffffff) & hx;
/* if Y1(NaN) is NaN, Y1(-inf) is NaN, Y1(inf) is 0 */
if (ix >= IC(0x7ff00000)) {
  double temp_var_for_ext_0;
  double temp_var_for_tac_3, temp_var_for_tac_4, temp_var_for_tac_5;
  double temp_var_for_const_6;
  temp_var_for_tac_3 = x * x;

  temp_var_for_tac_4 = x + temp_var_for_tac_3;

  temp_var_for_tac_5 = one / temp_var_for_tac_4;

  temp_var_for_ext_0 = temp_var_for_tac_5;
  computeDSub((Addr)&temp_var_for_tac_0,
              {(Addr) &(temp_var_for_const_1 = 0.0),
               (Addr) &(temp_var_for_const_0 = 1.96057090646238940668e-01)},
              "/home/shijia/Public/testprogram/e_y1.c_e.c:53:12");
  computeDSub((Addr)&temp_var_for_tac_1,
              {(Addr) &(temp_var_for_const_3 = 0.0),
               (Addr) &(temp_var_for_const_2 = 1.91256895875763547298e-03)},
              "/home/shijia/Public/testprogram/e_y1.c_e.c:55:12");
  computeDSub((Addr)&temp_var_for_tac_2,
              {(Addr) &(temp_var_for_const_5 = 0.0),
               (Addr) &(temp_var_for_const_4 = 9.19099158039878874504e-08)},
              "/home/shijia/Public/testprogram/e_y1.c_e.c:57:12");
  computeDMul((Addr)&temp_var_for_tac_3, {(Addr)&x, (Addr)&x},
              "/home/shijia/Public/testprogram/e_y1.c_e.c:73:39");
  computeDAdd((Addr)&temp_var_for_tac_4, {(Addr)&x, (Addr)&temp_var_for_tac_3},
              "/home/shijia/Public/testprogram/e_y1.c_e.c:73:35");
  computeDDiv((Addr)&temp_var_for_tac_5,
              {(Addr) &(temp_var_for_const_6 = one), (Addr)&temp_var_for_tac_4},
              "/home/shijia/Public/testprogram/e_y1.c_e.c:73:30");
  AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_5,
          "/home/shijia/Public/testprogram/e_y1.c_e.c:73:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

if ((ix | lx) == 0) {
  double temp_var_for_ext_1;
  double temp_var_for_tac_6;
  double temp_var_for_const_7;
  temp_var_for_callexp_0 = __builtin_huge_val();
  temp_var_for_tac_6 = (-(temp_var_for_callexp_0)) + x;

  temp_var_for_ext_1 = temp_var_for_tac_6;
  computeDAdd(
      (Addr)&temp_var_for_tac_6,
      {(Addr) &(temp_var_for_const_7 = (-(temp_var_for_callexp_0))), (Addr)&x},
      "/home/shijia/Public/testprogram/e_y1.c_e.c:81:36");
  AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_6,
          "/home/shijia/Public/testprogram/e_y1.c_e.c:81:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return (0.0 - ar_for_e)xt_1;
}
/* -inf and overflow exception.  */;
if (hx < 0) {
  double temp_var_for_ext_2;
  double temp_var_for_tac_7;
  double temp_var_for_const_8, temp_var_for_const_9;
  temp_var_for_tac_7 = zero / zero;

  temp_var_for_ext_2 = temp_var_for_tac_7;
  computeDDiv((Addr)&temp_var_for_tac_7,
              {(Addr) &(temp_var_for_const_9 = zero),
               (Addr) &(temp_var_for_const_8 = zero)},
              "/home/shijia/Public/testprogram/e_y1.c_e.c:89:31");
  AssignD({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_7,
          "/home/shijia/Public/testprogram/e_y1.c_e.c:89:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_2;
}

if (ix >= IC(0x40000000)) { /* |x| >= 2.0 */
  __ieee754_sincos(x, &s, &c);
  double temp_var_for_tac_8, temp_var_for_tac_9;
  double temp_var_for_const_10;
  temp_var_for_tac_8 = 0.0 - s;

  temp_var_for_tac_9 = temp_var_for_tac_8 - c;

  ss = temp_var_for_tac_9;
  computeDSub((Addr)&temp_var_for_tac_8,
              {(Addr) &(temp_var_for_const_10 = 0.0), (Addr)&s},
              "/home/shijia/Public/testprogram/e_y1.c_e.c:97:15");
  computeDSub((Addr)&temp_var_for_tac_9, {(Addr)&temp_var_for_tac_8, (Addr)&c},
              "/home/shijia/Public/testprogram/e_y1.c_e.c:97:20");
  AssignD({(Addr)&ss}, (Addr)&temp_var_for_tac_9,
          "/home/shijia/Public/testprogram/e_y1.c_e.c:97:8");
  ;
  double temp_var_for_tac_10;
  temp_var_for_tac_10 = s - c;

  cc = temp_var_for_tac_10;
  computeDSub((Addr)&temp_var_for_tac_10, {(Addr)&s, (Addr)&c},
              "/home/shijia/Public/testprogram/e_y1.c_e.c:98:12");
  AssignD({(Addr)&cc}, (Addr)&temp_var_for_tac_10,
          "/home/shijia/Public/testprogram/e_y1.c_e.c:98:8");
  ;
  if (ix < IC(0x7fe00000)) { /* make sure x+x not overflow */
    double temp_var_for_tac_11;
    double temp_var_for_const_11;
    double temp_var_for_callexp_1;

    temp_var_for_tac_11 = x + x;

    temp_var_for_callexp_1 = __ieee754_cos(temp_var_for_tac_11);
    z = temp_var_for_callexp_1;
    computeDAdd((Addr)&temp_var_for_tac_11, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_y1.c_e.c:100:27");
    AssignD({(Addr)&z},
            (Addr) &(temp_var_for_const_11 = temp_var_for_callexp_1),
            "/home/shijia/Public/testprogram/e_y1.c_e.c:100:9");
    ;
    if (int temp_var_for_tac_12, temp_var_for_tac_13; int temp_var_for_const_12;
        temp_var_for_tac_12 = s * c;

        temp_var_for_tac_13 = temp_var_for_tac_12 > zero;

        ) {
      double temp_var_for_tac_14;
      temp_var_for_tac_14 = z / ss;

      cc = temp_var_for_tac_14;
      computeDMul((Addr)&temp_var_for_tac_12, {(Addr)&s, (Addr)&c},
                  "/home/shijia/Public/testprogram/e_y1.c_e.c:101:14");
      compute(
          (Addr)&temp_var_for_tac_13,
          {(Addr)&temp_var_for_tac_12, (Addr) &(temp_var_for_const_12 = zero)},
          "/home/shijia/Public/testprogram/e_y1.c_e.c:101:19");
      computeDDiv((Addr)&temp_var_for_tac_14, {(Addr)&z, (Addr)&ss},
                  "/home/shijia/Public/testprogram/e_y1.c_e.c:102:16");
      AssignD({(Addr)&cc}, (Addr)&temp_var_for_tac_14,
              "/home/shijia/Public/testprogram/e_y1.c_e.c:102:12");
      ;
    }

    else {
      double temp_var_for_ext_3;
      double temp_var_for_tac_15;
      temp_var_for_tac_15 = z / cc;

      temp_var_for_ext_3 = temp_var_for_tac_15;
      computeDDiv((Addr)&temp_var_for_tac_15, {(Addr)&z, (Addr)&cc},
                  "/home/shijia/Public/testprogram/e_y1.c_e.c:107:32");
      AssignD({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_15,
              "/home/shijia/Public/testprogram/e_y1.c_e.c:107:28");
      ; // ss
      /*(ss)(z)(cc)(z)*/
      ss = temp_var_for_ext_3;
      AssignD({(Addr)&ss}, (Addr)&temp_var_for_ext_3,
              "/home/shijia/Public/testprogram/e_y1.c_e.c:109:12");
      ;
    }
  }
  /* y1(x) = sqrt(2/(pi*x))*(p1(x)*sin(x0)+q1(x)*cos(x0))
   * where x0 = x-3pi/4
   *      Better formula:
   *              cos(x0) = cos(x)cos(3pi/4)+sin(x)sin(3pi/4)
   *                      =  1/sqrt(2) * (sin(x) - cos(x))
   *              sin(x0) = sin(x)cos(3pi/4)-cos(x)sin(3pi/4)
   *                      = -1/sqrt(2) * (cos(x) + sin(x))
   * To avoid cancellation, use
   *              sin(x) +- cos(x) = -cos(2x)/(sin(x) -+ cos(x))
   * to compute the worse one.
   */
  if (ix > IC(0x48000000)) {
    double temp_var_for_ext_4;
    double temp_var_for_tac_16, temp_var_for_tac_17;
    double temp_var_for_const_13, temp_var_for_const_14;
    double temp_var_for_callexp_2;

    temp_var_for_tac_16 = invsqrtpi * ss;

    temp_var_for_callexp_2 = __ieee754_sqrt(x);
    temp_var_for_tac_17 = temp_var_for_tac_16 / temp_var_for_callexp_2;

    temp_var_for_ext_4 = temp_var_for_tac_17;
    computeDMul((Addr)&temp_var_for_tac_16,
                {(Addr) &(temp_var_for_const_13 = invsqrtpi), (Addr)&ss},
                "/home/shijia/Public/testprogram/e_y1.c_e.c:125:39");
    computeDDiv((Addr)&temp_var_for_tac_17,
                {(Addr)&temp_var_for_tac_16,
                 (Addr) &(temp_var_for_const_14 = temp_var_for_callexp_2)},
                "/home/shijia/Public/testprogram/e_y1.c_e.c:125:45");
    AssignD({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_17,
            "/home/shijia/Public/testprogram/e_y1.c_e.c:125:26");
    ; // z
    /*(cc)(z)(__ieee754_sqrt(x))(ss)(invsqrtpi)*/
    z = temp_var_for_ext_4;
    AssignD({(Addr)&z}, (Addr)&temp_var_for_ext_4,
            "/home/shijia/Public/testprogram/e_y1.c_e.c:127:9");
    ;
  }

  else {
    double temp_var_for_const_15;
    double temp_var_for_callexp_3;

    temp_var_for_callexp_3 = __j1_y1_pone(x);
    u = temp_var_for_callexp_3;
    AssignD({(Addr)&u},
            (Addr) &(temp_var_for_const_15 = temp_var_for_callexp_3),
            "/home/shijia/Public/testprogram/e_y1.c_e.c:131:9");
    ;
    double temp_var_for_const_16;
    double temp_var_for_callexp_4;

    temp_var_for_callexp_4 = __j1_y1_qone(x);
    v = temp_var_for_callexp_4;
    AssignD({(Addr)&v},
            (Addr) &(temp_var_for_const_16 = temp_var_for_callexp_4),
            "/home/shijia/Public/testprogram/e_y1.c_e.c:132:9");
    ;
    double temp_var_for_tac_18, temp_var_for_tac_19, temp_var_for_tac_20,
        temp_var_for_tac_21, temp_var_for_tac_22;
    double temp_var_for_const_17, temp_var_for_const_18;
    double temp_var_for_callexp_5;

    temp_var_for_tac_18 = u * ss;

    temp_var_for_tac_19 = v * cc;

    temp_var_for_tac_20 = temp_var_for_tac_18 + temp_var_for_tac_19;

    temp_var_for_tac_21 = invsqrtpi * temp_var_for_tac_20;

    temp_var_for_callexp_5 = __ieee754_sqrt(x);
    temp_var_for_tac_22 = temp_var_for_tac_21 / temp_var_for_callexp_5;

    z = temp_var_for_tac_22;
    computeDMul((Addr)&temp_var_for_tac_18, {(Addr)&u, (Addr)&ss},
                "/home/shijia/Public/testprogram/e_y1.c_e.c:133:26");
    computeDMul((Addr)&temp_var_for_tac_19, {(Addr)&v, (Addr)&cc},
                "/home/shijia/Public/testprogram/e_y1.c_e.c:133:35");
    computeDAdd((Addr)&temp_var_for_tac_20,
                {(Addr)&temp_var_for_tac_18, (Addr)&temp_var_for_tac_19},
                "/home/shijia/Public/testprogram/e_y1.c_e.c:133:31");
    computeDMul((Addr)&temp_var_for_tac_21,
                {(Addr) &(temp_var_for_const_17 = invsqrtpi),
                 (Addr)&temp_var_for_tac_20},
                "/home/shijia/Public/testprogram/e_y1.c_e.c:133:21");
    computeDDiv((Addr)&temp_var_for_tac_22,
                {(Addr)&temp_var_for_tac_21,
                 (Addr) &(temp_var_for_const_18 = temp_var_for_callexp_5)},
                "/home/shijia/Public/testprogram/e_y1.c_e.c:133:41");
    AssignD({(Addr)&z}, (Addr)&temp_var_for_tac_22,
            "/home/shijia/Public/testprogram/e_y1.c_e.c:133:9");
    ;
  }
  double temp_var_for_ext_5;
  temp_var_for_ext_5 = z;
  AssignD({(Addr)&temp_var_for_ext_5}, (Addr)&z,
          "/home/shijia/Public/testprogram/e_y1.c_e.c:136:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_5;
}
if (ix <= IC(0x3c900000)) { /* x < 2**-54 */
  double temp_var_for_ext_6;
  double temp_var_for_tac_23;
  double temp_var_for_const_19;
  temp_var_for_tac_23 = (-(tpi)) / x;

  temp_var_for_ext_6 = temp_var_for_tac_23;
  computeDDiv((Addr)&temp_var_for_tac_23,
              {(Addr) &(temp_var_for_const_19 = (-(tpi))), (Addr)&x},
              "/home/shijia/Public/testprogram/e_y1.c_e.c:143:32");
  AssignD({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_23,
          "/home/shijia/Public/testprogram/e_y1.c_e.c:143:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_(0.0 - or_) ext_6;
}
double temp_var_for_tac_24;
temp_var_for_tac_24 = x * x;

z = temp_var_for_tac_24;
computeDMul((Addr)&temp_var_for_tac_24, {(Addr)&x, (Addr)&x},
            "/home/shijia/Public/testprogram/e_y1.c_e.c:148:9");
AssignD({(Addr)&z}, (Addr)&temp_var_for_tac_24,
        "/home/shijia/Public/testprogram/e_y1.c_e.c:148:5");
;
#ifdef DO_NOT_USE_THIS
u = U0[0] + z * (U0[1] + z * (U0[2] + z * (U0[3] + z * U0[4])));
v = one + z * (V0[0] + z * (V0[1] + z * (V0[2] + z * (V0[3] + z * V0[4]))));
#else
double temp_var_for_tac_25, temp_var_for_tac_26;
double temp_var_for_const_20, temp_var_for_const_21;
temp_var_for_tac_25 = z * U0[1];

temp_var_for_tac_26 = U0[0] + temp_var_for_tac_25;

u1 = temp_var_for_tac_26;
computeDMul((Addr)&temp_var_for_tac_25,
            {(Addr)&z, (Addr) &(temp_var_for_const_20 = U0[1])},
            "/home/shijia/Public/testprogram/e_y1.c_e.c:153:18");
computeDAdd((Addr)&temp_var_for_tac_26,
            {(Addr) &(temp_var_for_const_21 = U0[0]),
             (Addr)&temp_var_for_tac_25},
            "/home/shijia/Public/testprogram/e_y1.c_e.c:153:14");
AssignD({(Addr)&u1}, (Addr)&temp_var_for_tac_26,
        "/home/shijia/Public/testprogram/e_y1.c_e.c:153:6");
;
double temp_var_for_tac_27;
temp_var_for_tac_27 = z * z;

z2 = temp_var_for_tac_27;
computeDMul((Addr)&temp_var_for_tac_27, {(Addr)&z, (Addr)&z},
            "/home/shijia/Public/testprogram/e_y1.c_e.c:154:10");
AssignD({(Addr)&z2}, (Addr)&temp_var_for_tac_27,
        "/home/shijia/Public/testprogram/e_y1.c_e.c:154:6");
;
double temp_var_for_tac_28, temp_var_for_tac_29;
double temp_var_for_const_22, temp_var_for_const_23;
temp_var_for_tac_28 = z * U0[3];

temp_var_for_tac_29 = U0[2] + temp_var_for_tac_28;

u2 = temp_var_for_tac_29;
computeDMul((Addr)&temp_var_for_tac_28,
            {(Addr)&z, (Addr) &(temp_var_for_const_22 = U0[3])},
            "/home/shijia/Public/testprogram/e_y1.c_e.c:155:18");
computeDAdd((Addr)&temp_var_for_tac_29,
            {(Addr) &(temp_var_for_const_23 = U0[2]),
             (Addr)&temp_var_for_tac_28},
            "/home/shijia/Public/testprogram/e_y1.c_e.c:155:14");
AssignD({(Addr)&u2}, (Addr)&temp_var_for_tac_29,
        "/home/shijia/Public/testprogram/e_y1.c_e.c:155:6");
;
double temp_var_for_tac_30;
temp_var_for_tac_30 = z2 * z2;

z4 = temp_var_for_tac_30;
computeDMul((Addr)&temp_var_for_tac_30, {(Addr)&z2, (Addr)&z2},
            "/home/shijia/Public/testprogram/e_y1.c_e.c:156:11");
AssignD({(Addr)&z4}, (Addr)&temp_var_for_tac_30,
        "/home/shijia/Public/testprogram/e_y1.c_e.c:156:6");
;
double temp_var_for_tac_31, temp_var_for_tac_32, temp_var_for_tac_33,
    temp_var_for_tac_34;
double temp_var_for_const_24;
temp_var_for_tac_31 = z2 * u2;

temp_var_for_tac_32 = u1 + temp_var_for_tac_31;

temp_var_for_tac_33 = z4 * U0[4];

temp_var_for_tac_34 = temp_var_for_tac_32 + temp_var_for_tac_33;

u = temp_var_for_tac_34;
computeDMul((Addr)&temp_var_for_tac_31, {(Addr)&z2, (Addr)&u2},
            "/home/shijia/Public/testprogram/e_y1.c_e.c:157:15");
computeDAdd((Addr)&temp_var_for_tac_32, {(Addr)&u1, (Addr)&temp_var_for_tac_31},
            "/home/shijia/Public/testprogram/e_y1.c_e.c:157:10");
computeDMul((Addr)&temp_var_for_tac_33,
            {(Addr)&z4, (Addr) &(temp_var_for_const_24 = U0[4])},
            "/home/shijia/Public/testprogram/e_y1.c_e.c:157:25");
computeDAdd((Addr)&temp_var_for_tac_34,
            {(Addr)&temp_var_for_tac_32, (Addr)&temp_var_for_tac_33},
            "/home/shijia/Public/testprogram/e_y1.c_e.c:157:20");
AssignD({(Addr)&u}, (Addr)&temp_var_for_tac_34,
        "/home/shijia/Public/testprogram/e_y1.c_e.c:157:5");
;
double temp_var_for_tac_35, temp_var_for_tac_36;
double temp_var_for_const_25, temp_var_for_const_26;
temp_var_for_tac_35 = z * V0[0];

temp_var_for_tac_36 = one + temp_var_for_tac_35;

v1 = temp_var_for_tac_36;
computeDMul((Addr)&temp_var_for_tac_35,
            {(Addr)&z, (Addr) &(temp_var_for_const_25 = V0[0])},
            "/home/shijia/Public/testprogram/e_y1.c_e.c:158:16");
computeDAdd((Addr)&temp_var_for_tac_36,
            {(Addr) &(temp_var_for_const_26 = one), (Addr)&temp_var_for_tac_35},
            "/home/shijia/Public/testprogram/e_y1.c_e.c:158:12");
AssignD({(Addr)&v1}, (Addr)&temp_var_for_tac_36,
        "/home/shijia/Public/testprogram/e_y1.c_e.c:158:6");
;
double temp_var_for_tac_37, temp_var_for_tac_38;
double temp_var_for_const_27, temp_var_for_const_28;
temp_var_for_tac_37 = z * V0[2];

temp_var_for_tac_38 = V0[1] + temp_var_for_tac_37;

v2 = temp_var_for_tac_38;
computeDMul((Addr)&temp_var_for_tac_37,
            {(Addr)&z, (Addr) &(temp_var_for_const_27 = V0[2])},
            "/home/shijia/Public/testprogram/e_y1.c_e.c:159:18");
computeDAdd((Addr)&temp_var_for_tac_38,
            {(Addr) &(temp_var_for_const_28 = V0[1]),
             (Addr)&temp_var_for_tac_37},
            "/home/shijia/Public/testprogram/e_y1.c_e.c:159:14");
AssignD({(Addr)&v2}, (Addr)&temp_var_for_tac_38,
        "/home/shijia/Public/testprogram/e_y1.c_e.c:159:6");
;
double temp_var_for_tac_39, temp_var_for_tac_40;
double temp_var_for_const_29, temp_var_for_const_30;
temp_var_for_tac_39 = z * V0[4];

temp_var_for_tac_40 = V0[3] + temp_var_for_tac_39;

v3 = temp_var_for_tac_40;
computeDMul((Addr)&temp_var_for_tac_39,
            {(Addr)&z, (Addr) &(temp_var_for_const_29 = V0[4])},
            "/home/shijia/Public/testprogram/e_y1.c_e.c:160:18");
computeDAdd((Addr)&temp_var_for_tac_40,
            {(Addr) &(temp_var_for_const_30 = V0[3]),
             (Addr)&temp_var_for_tac_39},
            "/home/shijia/Public/testprogram/e_y1.c_e.c:160:14");
AssignD({(Addr)&v3}, (Addr)&temp_var_for_tac_40,
        "/home/shijia/Public/testprogram/e_y1.c_e.c:160:6");
;
double temp_var_for_tac_41, temp_var_for_tac_42, temp_var_for_tac_43,
    temp_var_for_tac_44;
temp_var_for_tac_41 = z2 * v2;

temp_var_for_tac_42 = v1 + temp_var_for_tac_41;

temp_var_for_tac_43 = z4 * v3;

temp_var_for_tac_44 = temp_var_for_tac_42 + temp_var_for_tac_43;

v = temp_var_for_tac_44;
computeDMul((Addr)&temp_var_for_tac_41, {(Addr)&z2, (Addr)&v2},
            "/home/shijia/Public/testprogram/e_y1.c_e.c:161:15");
computeDAdd((Addr)&temp_var_for_tac_42, {(Addr)&v1, (Addr)&temp_var_for_tac_41},
            "/home/shijia/Public/testprogram/e_y1.c_e.c:161:10");
computeDMul((Addr)&temp_var_for_tac_43, {(Addr)&z4, (Addr)&v3},
            "/home/shijia/Public/testprogram/e_y1.c_e.c:161:25");
computeDAdd((Addr)&temp_var_for_tac_44,
            {(Addr)&temp_var_for_tac_42, (Addr)&temp_var_for_tac_43},
            "/home/shijia/Public/testprogram/e_y1.c_e.c:161:20");
AssignD({(Addr)&v}, (Addr)&temp_var_for_tac_44,
        "/home/shijia/Public/testprogram/e_y1.c_e.c:161:5");
;
#endif
double temp_var_for_ext_7;
double temp_var_for_tac_45, temp_var_for_tac_46, temp_var_for_tac_47,
    temp_var_for_tac_48, temp_var_for_tac_49, temp_var_for_tac_50,
    temp_var_for_tac_51;
double temp_var_for_const_31, temp_var_for_const_32, temp_var_for_const_33,
    temp_var_for_const_34;
double temp_var_for_callexp_6;

double temp_var_for_callexp_7;

temp_var_for_tac_45 = u / v;

temp_var_for_tac_46 = x * temp_var_for_tac_45;

temp_var_for_callexp_6 = __ieee754_j1(x);
temp_var_for_callexp_7 = __ieee754_log(x);
temp_var_for_tac_47 = temp_var_for_callexp_6 * temp_var_for_callexp_7;

temp_var_for_tac_48 = one / x;

temp_var_for_tac_49 = temp_var_for_tac_47 - temp_var_for_tac_48;

temp_var_for_tac_50 = tpi * temp_var_for_tac_49;

temp_var_for_tac_51 = temp_var_for_tac_46 + temp_var_for_tac_50;

temp_var_for_ext_7 = temp_var_for_tac_51;
computeDDiv((Addr)&temp_var_for_tac_45, {(Addr)&u, (Addr)&v},
            "/home/shijia/Public/testprogram/e_y1.c_e.c:165:15");
computeDMul((Addr)&temp_var_for_tac_46, {(Addr)&x, (Addr)&temp_var_for_tac_45},
            "/home/shijia/Public/testprogram/e_y1.c_e.c:165:10");
computeDMul((Addr)&temp_var_for_tac_47,
            {(Addr) &(temp_var_for_const_32 = temp_var_for_callexp_6),
             (Addr) &(temp_var_for_const_31 = temp_var_for_callexp_7)},
            "/home/shijia/Public/testprogram/e_y1.c_e.c:165:45");
computeDDiv((Addr)&temp_var_for_tac_48,
            {(Addr) &(temp_var_for_const_33 = one), (Addr)&x},
            "/home/shijia/Public/testprogram/e_y1.c_e.c:165:70");
computeDSub((Addr)&temp_var_for_tac_49,
            {(Addr)&temp_var_for_tac_47, (Addr)&temp_var_for_tac_48},
            "/home/shijia/Public/testprogram/e_y1.c_e.c:165:64");
computeDMul((Addr)&temp_var_for_tac_50,
            {(Addr) &(temp_var_for_const_34 = tpi), (Addr)&temp_var_for_tac_49},
            "/home/shijia/Public/testprogram/e_y1.c_e.c:165:26");
computeDAdd((Addr)&temp_var_for_tac_51,
            {(Addr)&temp_var_for_tac_46, (Addr)&temp_var_for_tac_50},
            "/home/shijia/Public/testprogram/e_y1.c_e.c:165:20");
AssignD({(Addr)&temp_var_for_ext_7}, (Addr)&temp_var_for_tac_51,
        "/home/shijia/Public/testprogram/e_y1.c_e.c:164:22");
;
callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
callExp++; /*identify the function is  add move tmpShadow*/
return temp_var_for_ext_7;
}

/* wrapper y1 */
double __y1(double x) {
  if ((islessequal(x, 0.0) || isgreater(x, X_TLOSS)) &&
      _LIB_VERSION != _IEEE_) {
    if (int temp_var_for_tac_52; int temp_var_for_const_35;
        temp_var_for_tac_52 = x < 0.0;

        ) {
      /* d = zero/(x-x) */
      feraiseexcept(FE_INVALID);
      double temp_var_for_ext_8;
      double temp_var_for_const_36;
      double temp_var_for_callexp_9;

      temp_var_for_callexp_8 = __builtin_huge_val();
      temp_var_for_callexp_9 = __kernel_standard(
          x, x, (-(temp_var_for_callexp_8)), KMATHERR_Y1_MINUS);
      temp_var_for_ext_8 = temp_var_for_callexp_9;
      compute((Addr)&temp_var_for_tac_52,
              {(Addr)&x, (Addr) &(temp_var_for_const_35 = 0.0)},
              "/home/shijia/Public/testprogram/e_y1.c_e.c:175:11");
      AssignD({(Addr)&temp_var_for_ext_8},
              (Addr) &(temp_var_for_const_36 = temp_var_for_callexp_9),
              "/home/shijia/Public/testprogram/e_y1.c_e.c:179:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
      callExp++; /*identify the function is  add move tmpShado(0.0 - */
retur)n temp_var_for_ext_8;
    } else {
      if (int temp_var_for_tac_53; int temp_var_for_const_37;
          temp_var_for_tac_53 = x == 0.0;

          )
      /* d = -one/(x-x) */
      {
        double temp_var_for_ext_9;
        double temp_var_for_const_38;
        double temp_var_for_callexp_11;

        temp_var_for_callexp_10 = __builtin_huge_val();
        temp_var_for_callexp_11 = __kernel_standard(
            x, x, (-(temp_var_for_callexp_10)), KMATHERR_Y1_ZERO);
        temp_var_for_ext_9 = temp_var_for_callexp_11;
        compute((Addr)&temp_var_for_tac_53,
                {(Addr)&x, (Addr) &(temp_var_for_const_37 = 0.0)},
                "/home/shijia/Public/testprogram/e_y1.c_e.c:186:13");
        AssignD({(Addr)&temp_var_for_ext_9},
                (Addr) &(temp_var_for_const_38 = temp_var_for_callexp_11),
                "/home/shijia/Public/testprogram/e_y1.c_e.c:190:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
        callExp++; /*identify the function is  add move tmpShadow(0.0 - /
       return) temp_var_for_ext_9;
       }

                       else {
       if (_LIB_VERSION != _POSIX_)
                               /* y1(x>X_TLOSS) */
        {
          double temp_var_for_ext_10;
          double temp_var_for_const_39;
          double temp_var_for_callexp_12;

          temp_var_for_callexp_12 =
              __kernel_standard(x, x, 0.0, KMATHERR_Y1_TLOSS);
          temp_var_for_ext_10 = temp_var_for_callexp_12;
          AssignD({(Addr)&temp_var_for_ext_10},
                  (Addr) &(temp_var_for_const_39 = temp_var_for_callexp_12),
                  "/home/shijia/Public/testprogram/e_y1.c_e.c:203:31");
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
  double temp_var_for_const_40;
  double temp_var_for_callexp_13;

  temp_var_for_callexp_13 = __ieee754_y1(x);
  temp_var_for_ext_11 = temp_var_for_callexp_13;
  AssignD({(Addr)&temp_var_for_ext_11},
          (Addr) &(temp_var_for_const_40 = temp_var_for_callexp_13),
          "/home/shijia/Public/testprogram/e_y1.c_e.c:214:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_11", (Addr)&temp_var_for_ext_11));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_11;
}

__typeof(__y1) y1 __attribute__((weak, alias("__y1")));
#ifdef __NO_LONG_DOUBLE_MATH
__typeof(__y1l) __y1l __attribute__((alias("__y1")));
__typeof(__y1l) y1l __attribute__((weak, alias("__y1l")));
#endif
