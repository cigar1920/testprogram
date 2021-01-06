#include "../ScDebug/scdebug.h"
/* @(#)s_atan.c 1.3 95/01/18 */
/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunSoft, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 *
 */

/* atan(x)
 * Method
 *   1. Reduce x to positive by atan(x) = -atan(-x).
 *   2. According to the integer k=4t+0.25 chopped, t=x, the argument
 *      is further reduced to one of the following intervals and the
 *      arctangent of t is evaluated by the corresponding formula:
 *
 *      [0,7/16]      atan(x) = t-t^3*(a1+t^2*(a2+...(a10+t^2*a11)...)
 *      [7/16,11/16]  atan(x) = atan(1/2) + atan( (t-0.5)/(1+t/2) )
 *      [11/16.19/16] atan(x) = atan( 1 ) + atan( (t-1)/(1+t) )
 *      [19/16,39/16] atan(x) = atan(3/2) + atan( (t-1.5)/(1+1.5t) )
 *      [39/16,INF]   atan(x) = atan(INF) + atan( -1/t )
 *
 * Constants:
 * The hexadecimal values are the intended ones for the following
 * constants. The decimal values may be used, provided that the
 * compiler will convert from decimal to binary accurately enough
 * to produce the hexadecimal values shown.
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_atan

double __ieee754_atan(double x) {
  double w, s1, s2, z;
  int32_t ix, hx, id;

  static const double atanhi[] = {
      4.63647609000806093515e-01, /* atan(0.5)hi 0x3FDDAC67, 0x0561BB4F */
      7.85398163397448278999e-01, /* atan(1.0)hi 0x3FE921FB, 0x54442D18 */
      9.82793723247329054082e-01, /* atan(1.5)hi 0x3FEF730B, 0xD281F69B */
      1.57079632679489655800e+00  /* atan(inf)hi 0x3FF921FB, 0x54442D18 */
  };

  static const double atanlo[] = {
      2.26987774529616870924e-17, /* atan(0.5)lo 0x3C7A2B7F, 0x222F65E2 */
      3.06161699786838301793e-17, /* atan(1.0)lo 0x3C81A626, 0x33145C07 */
      1.39033110312309984516e-17, /* atan(1.5)lo 0x3C700788, 0x7AF0CBBD */
      6.12323399573676603587e-17  /* atan(inf)lo 0x3C91A626, 0x33145C07 */
  };

  static const double aT[] = {
      3.33333333333329318027e-01,         /* 0x3FD55555, 0x5555550D */
      (double temp_var_for_tac_0;
  double temp_var_for_const_0, temp_var_for_const_1;
  temp_var_for_tac_0 = 0.0 - 1.99999999998764832476e-01;

), /* 0xBFC99999, 0x9998EBC4 */
      1.42857142725034663711e-01,         /* 0x3FC24924, 0x920083FF */
      (double temp_var_for_tac_1;double temp_var_for_const_2,temp_var_for_const_3;temp_var_for_tac_1 = 0.0 - 1.11111104054623557880e-01;

), /* 0xBFBC71C6, 0xFE231671 */
      9.09088713343650656196e-02,         /* 0x3FB745CD, 0xC54C206E */
      (double temp_var_for_tac_2;double temp_var_for_const_4,temp_var_for_const_5;temp_var_for_tac_2 = 0.0 - 7.69187620504482999495e-02;

), /* 0xBFB3B0F2, 0xAF749A6D */
      6.66107313738753120669e-02,         /* 0x3FB10D66, 0xA0D03D51 */
      (double temp_var_for_tac_3;double temp_var_for_const_6,temp_var_for_const_7;temp_var_for_tac_3 = 0.0 - 5.83357013379057348645e-02;

), /* 0xBFADDE2D, 0x52DEFD9A */
      4.97687799461593236017e-02,         /* 0x3FA97B4B, 0x24760DEB */
      (double temp_var_for_tac_4;double temp_var_for_const_8,temp_var_for_const_9;temp_var_for_tac_4 = 0.0 - 3.65315727442169155270e-02;

), /* 0xBFA2B444, 0x2C6A6C2F */
      1.62858201153657823623e-02          /* 0x3F90AD3A, 0xE322DA11 */
};

static const double one = 1.0;
static const double hugeval = 1.0e300;

GET_HIGH_WORD(hx, x);
ix = hx & IC(0x7fffffff);
if (ix >= IC(0x44100000)) { /* if |x| >= 2^66 */
  uint32_t low;

  GET_LOW_WORD(low, x);
  if (ix > IC(0x7ff00000) || (ix == IC(0x7ff00000) && (low != 0))) {
    double temp_var_for_ext_0;
    double temp_var_for_tac_5;
    temp_var_for_tac_5 = x + x;

    temp_var_for_ext_0 = temp_var_for_tac_5;
    computeDSub((Addr)&temp_var_for_tac_0,
                {(Addr) &(temp_var_for_const_1 = 0.0),
                 (Addr) &(temp_var_for_const_0 = 1.99999999998764832476e-01)},
                "/home/shijia/Public/testprogram/s_atan.c_e.c:60:12");
    computeDSub((Addr)&temp_var_for_tac_1,
                {(Addr) &(temp_var_for_const_3 = 0.0),
                 (Addr) &(temp_var_for_const_2 = 1.11111104054623557880e-01)},
                "/home/shijia/Public/testprogram/s_atan.c_e.c:62:12");
    computeDSub((Addr)&temp_var_for_tac_2,
                {(Addr) &(temp_var_for_const_5 = 0.0),
                 (Addr) &(temp_var_for_const_4 = 7.69187620504482999495e-02)},
                "/home/shijia/Public/testprogram/s_atan.c_e.c:64:12");
    computeDSub((Addr)&temp_var_for_tac_3,
                {(Addr) &(temp_var_for_const_7 = 0.0),
                 (Addr) &(temp_var_for_const_6 = 5.83357013379057348645e-02)},
                "/home/shijia/Public/testprogram/s_atan.c_e.c:66:12");
    computeDSub((Addr)&temp_var_for_tac_4,
                {(Addr) &(temp_var_for_const_9 = 0.0),
                 (Addr) &(temp_var_for_const_8 = 3.65315727442169155270e-02)},
                "/home/shijia/Public/testprogram/s_atan.c_e.c:68:12");
    computeDAdd((Addr)&temp_var_for_tac_5, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/s_atan.c_e.c:83:30");
    AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_5,
            "/home/shijia/Public/testprogram/s_atan.c_e.c:83:26");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }
  /* NaN */
  if (hx > 0) {
    double temp_var_for_ext_1;
    double temp_var_for_tac_6;
    double temp_var_for_const_10, temp_var_for_const_11;
    temp_var_for_tac_6 = atanhi[3] + atanlo[3];

    temp_var_for_ext_1 = temp_var_for_tac_6;
    computeDAdd((Addr)&temp_var_for_tac_6,
                {(Addr) &(temp_var_for_const_11 = atanhi[3]),
                 (Addr) &(temp_var_for_const_10 = atanlo[3])},
                "/home/shijia/Public/testprogram/s_atan.c_e.c:92:38");
    AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_6,
            "/home/shijia/Public/testprogram/s_atan.c_e.c:92:26");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }

  else {
    double temp_var_for_ext_2;
    double temp_var_for_tac_7;
    double temp_var_for_const_12, temp_var_for_const_13;
    temp_var_for_tac_7 = (-(atanhi[3])) - atanlo[3];

    temp_var_for_ext_2 = temp_var_for_tac_7;
    computeDSub((Addr)&temp_var_for_tac_7,
                {(Addr) &(temp_var_for_const_13 = (-(atanhi[3]))),
                 (Addr) &(temp_var_for_const_12 = atanlo[3])},
                "/home/shijia/Public/testprogram/s_atan.c_e.c:101:39");
    AssignD({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_7,
            "/home/shijia/Public/testprogram/s_atan.c_e.c:101:26");
    ;
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return (0.0 - rn temp_v)ar_for_ext_2;
  }
}
if (ix < IC(0x3fdc0000)) {   /* |x| < 0.4375 */
  if (ix < IC(0x3e200000)) { /* |x| < 2^-29 */
    if (int temp_var_for_tac_8, temp_var_for_tac_9;
        int temp_var_for_const_14, temp_var_for_const_15;
        temp_var_for_tac_8 = hugeval + x;

        temp_var_for_tac_9 = temp_var_for_tac_8 > one;

        ) {
      double temp_var_for_ext_3;
      temp_var_for_ext_3 = x;
      computeDAdd((Addr)&temp_var_for_tac_8,
                  {(Addr) &(temp_var_for_const_14 = hugeval), (Addr)&x},
                  "/home/shijia/Public/testprogram/s_atan.c_e.c:110:19");
      compute(
          (Addr)&temp_var_for_tac_9,
          {(Addr)&temp_var_for_tac_8, (Addr) &(temp_var_for_const_15 = one)},
          "/home/shijia/Public/testprogram/s_atan.c_e.c:110:23");
      AssignD({(Addr)&temp_var_for_ext_3}, (Addr)&x,
              "/home/shijia/Public/testprogram/s_atan.c_e.c:112:28");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_3;
    }
    /* raise inexact */
  }
  id = -1;
} else {
  double temp_var_for_ext_4;
  double temp_var_for_const_16;
  double temp_var_for_callexp_0;

  temp_var_for_callexp_0 = fabs(x);
  temp_var_for_ext_4 = temp_var_for_callexp_0;
  AssignD({(Addr)&temp_var_for_ext_4},
          (Addr) &(temp_var_for_const_16 = temp_var_for_callexp_0),
          "/home/shijia/Public/testprogram/s_atan.c_e.c:123:24");
  ; // x
  /*(0)(t)(for_ex)(_)(for_ex[_])(temp_v)(_)(temp_v[_])(for_ex)(_)(for_ex[_])(rn
   * tem)(_)(rn tem[_])(rn tem[_])(x)(hugeval)(__ieee754_fabs(x))*/
  x = temp_var_for_ext_4;
  AssignD({(Addr)&x}, (Addr)&temp_var_for_ext_4,
          "/home/shijia/Public/testprogram/s_atan.c_e.c:126:7");
  ;
  if (ix < IC(0x3ff30000)) {   /* |x| < 1.1875 */
    if (ix < IC(0x3fe60000)) { /* 7/16 <=|x|<11/16 */
      id = 0;
      double temp_var_for_ext_5;
      double temp_var_for_tac_10, temp_var_for_tac_11, temp_var_for_tac_12,
          temp_var_for_tac_13;
      double temp_var_for_const_17, temp_var_for_const_18,
          temp_var_for_const_19;
      temp_var_for_tac_10 = 2.0 * x;

      temp_var_for_tac_11 = temp_var_for_tac_10 - one;

      temp_var_for_tac_12 = 2.0 + x;

      temp_var_for_tac_13 = temp_var_for_tac_11 / temp_var_for_tac_12;

      temp_var_for_ext_5 = temp_var_for_tac_13;
      computeDMul((Addr)&temp_var_for_tac_10,
                  {(Addr) &(temp_var_for_const_17 = 2.0), (Addr)&x},
                  "/home/shijia/Public/testprogram/s_atan.c_e.c:131:35");
      computeDSub(
          (Addr)&temp_var_for_tac_11,
          {(Addr)&temp_var_for_tac_10, (Addr) &(temp_var_for_const_18 = one)},
          "/home/shijia/Public/testprogram/s_atan.c_e.c:131:39");
      computeDAdd((Addr)&temp_var_for_tac_12,
                  {(Addr) &(temp_var_for_const_19 = 2.0), (Addr)&x},
                  "/home/shijia/Public/testprogram/s_atan.c_e.c:131:53");
      computeDDiv((Addr)&temp_var_for_tac_13,
                  {(Addr)&temp_var_for_tac_11, (Addr)&temp_var_for_tac_12},
                  "/home/shijia/Public/testprogram/s_atan.c_e.c:131:46");
      AssignD({(Addr)&temp_var_for_ext_5}, (Addr)&temp_var_for_tac_13,
              "/home/shijia/Public/testprogram/s_atan.c_e.c:131:28");
      ; // x
      /*(x)(2.0)(one)(x)(2.0)*/
      x = temp_var_for_ext_5;
      AssignD({(Addr)&x}, (Addr)&temp_var_for_ext_5,
              "/home/shijia/Public/testprogram/s_atan.c_e.c:133:11");
      ;
    } else { /* 11/16<=|x|< 19/16 */
      id = 1;
      double temp_var_for_ext_6;
      double temp_var_for_tac_14, temp_var_for_tac_15, temp_var_for_tac_16;
      double temp_var_for_const_20, temp_var_for_const_21;
      temp_var_for_tac_14 = x - one;

      temp_var_for_tac_15 = x + one;

      temp_var_for_tac_16 = temp_var_for_tac_14 / temp_var_for_tac_15;

      temp_var_for_ext_6 = temp_var_for_tac_16;
      computeDSub((Addr)&temp_var_for_tac_14,
                  {(Addr)&x, (Addr) &(temp_var_for_const_20 = one)},
                  "/home/shijia/Public/testprogram/s_atan.c_e.c:137:33");
      computeDAdd((Addr)&temp_var_for_tac_15,
                  {(Addr)&x, (Addr) &(temp_var_for_const_21 = one)},
                  "/home/shijia/Public/testprogram/s_atan.c_e.c:137:45");
      computeDDiv((Addr)&temp_var_for_tac_16,
                  {(Addr)&temp_var_for_tac_14, (Addr)&temp_var_for_tac_15},
                  "/home/shijia/Public/testprogram/s_atan.c_e.c:137:40");
      AssignD({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_16,
              "/home/shijia/Public/testprogram/s_atan.c_e.c:137:28");
      ; // x
      /*(x)(2.0)(one)(x)(2.0)(one)(x)(2.0)(x)(2.0)(x)(2.0)(one)(x)(one)(x)*/
      x = temp_var_for_ext_6;
      AssignD({(Addr)&x}, (Addr)&temp_var_for_ext_6,
              "/home/shijia/Public/testprogram/s_atan.c_e.c:139:11");
      ;
    }
  } else {
    if (ix < IC(0x40038000)) { /* |x| < 2.4375 */
      id = 2;
      double temp_var_for_ext_7;
      double temp_var_for_tac_17, temp_var_for_tac_18, temp_var_for_tac_19,
          temp_var_for_tac_20;
      double temp_var_for_const_22, temp_var_for_const_23,
          temp_var_for_const_24;
      temp_var_for_tac_17 = x - 1.5;

      temp_var_for_tac_18 = 1.5 * x;

      temp_var_for_tac_19 = one + temp_var_for_tac_18;

      temp_var_for_tac_20 = temp_var_for_tac_17 / temp_var_for_tac_19;

      temp_var_for_ext_7 = temp_var_for_tac_20;
      computeDSub((Addr)&temp_var_for_tac_17,
                  {(Addr)&x, (Addr) &(temp_var_for_const_22 = 1.5)},
                  "/home/shijia/Public/testprogram/s_atan.c_e.c:145:33");
      computeDMul((Addr)&temp_var_for_tac_18,
                  {(Addr) &(temp_var_for_const_23 = 1.5), (Addr)&x},
                  "/home/shijia/Public/testprogram/s_atan.c_e.c:145:53");
      computeDAdd(
          (Addr)&temp_var_for_tac_19,
          {(Addr) &(temp_var_for_const_24 = one), (Addr)&temp_var_for_tac_18},
          "/home/shijia/Public/testprogram/s_atan.c_e.c:145:47");
      computeDDiv((Addr)&temp_var_for_tac_20,
                  {(Addr)&temp_var_for_tac_17, (Addr)&temp_var_for_tac_19},
                  "/home/shijia/Public/testprogram/s_atan.c_e.c:145:40");
      AssignD({(Addr)&temp_var_for_ext_7}, (Addr)&temp_var_for_tac_20,
              "/home/shijia/Public/testprogram/s_atan.c_e.c:145:28");
      ; // x
      /*(one)(x)(one)(x)(one)(x)(one)(x)(x)(1.5)(one)(1.5)(x)*/
      x = temp_var_for_ext_7;
      AssignD({(Addr)&x}, (Addr)&temp_var_for_ext_7,
              "/home/shijia/Public/testprogram/s_atan.c_e.c:147:11");
      ;
    } else { /* 2.4375 <= |x| < 2^66 */
      id = 3;
      double temp_var_for_ext_8;
      double temp_var_for_tac_21, temp_var_for_tac_22;
      double temp_var_for_const_25, temp_var_for_const_26;
      temp_var_for_tac_21 = 0.0 - 1.0;

      temp_var_for_tac_22 = temp_var_for_tac_21 / x;

      temp_var_for_ext_8 = temp_var_for_tac_22;
      computeDSub((Addr)&temp_var_for_tac_21,
                  {(Addr) &(temp_var_for_const_26 = 0.0),
                   (Addr) &(temp_var_for_const_25 = 1.0)},
                  "/home/shijia/Public/testprogram/s_atan.c_e.c:151:35");
      computeDDiv((Addr)&temp_var_for_tac_22,
                  {(Addr)&temp_var_for_tac_21, (Addr)&x},
                  "/home/shijia/Public/testprogram/s_atan.c_e.c:151:42");
      AssignD({(Addr)&temp_var_for_ext_8}, (Addr)&temp_var_for_tac_22,
              "/home/shijia/Public/testprogram/s_atan.c_e.c:151:28");
      ; // x
      /*(x)(1.5)(one)(1.5)(x)(1.5)(x)(x)(1.5)(one)(x)(1.5)(x)(1.0)(1.0)*/
      x = temp_var_for_ext_8;
      AssignD({(Addr)&x}, (Addr)&temp_var_for_ext_8,
              "/home/shijia/Public/testprogram/s_atan.c_e.c:153:11");
      ;
    }
  }
}
/* end of argument reduction */
double temp_var_for_tac_23;
temp_var_for_tac_23 = x * x;

z = temp_var_for_tac_23;
computeDMul((Addr)&temp_var_for_tac_23, {(Addr)&x, (Addr)&x},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:158:9");
AssignD({(Addr)&z}, (Addr)&temp_var_for_tac_23,
        "/home/shijia/Public/testprogram/s_atan.c_e.c:158:5");
;
double temp_var_for_tac_24;
temp_var_for_tac_24 = z * z;

w = temp_var_for_tac_24;
computeDMul((Addr)&temp_var_for_tac_24, {(Addr)&z, (Addr)&z},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:159:9");
AssignD({(Addr)&w}, (Addr)&temp_var_for_tac_24,
        "/home/shijia/Public/testprogram/s_atan.c_e.c:159:5");
;
/* break sum from i=0 to 10 aT[i]z**(i+1) into odd and even poly */
double temp_var_for_tac_25, temp_var_for_tac_26, temp_var_for_tac_27,
    temp_var_for_tac_28, temp_var_for_tac_29, temp_var_for_tac_30,
    temp_var_for_tac_31, temp_var_for_tac_32, temp_var_for_tac_33,
    temp_var_for_tac_34, temp_var_for_tac_35;
double temp_var_for_const_27, temp_var_for_const_28, temp_var_for_const_29,
    temp_var_for_const_30, temp_var_for_const_31, temp_var_for_const_32;
temp_var_for_tac_25 = w * aT[10];

temp_var_for_tac_26 = aT[8] + temp_var_for_tac_25;

temp_var_for_tac_27 = w * temp_var_for_tac_26;

temp_var_for_tac_28 = aT[6] + temp_var_for_tac_27;

temp_var_for_tac_29 = w * temp_var_for_tac_28;

temp_var_for_tac_30 = aT[4] + temp_var_for_tac_29;

temp_var_for_tac_31 = w * temp_var_for_tac_30;

temp_var_for_tac_32 = aT[2] + temp_var_for_tac_31;

temp_var_for_tac_33 = w * temp_var_for_tac_32;

temp_var_for_tac_34 = aT[0] + temp_var_for_tac_33;

temp_var_for_tac_35 = z * temp_var_for_tac_34;

s1 = temp_var_for_tac_35;
computeDMul((Addr)&temp_var_for_tac_25,
            {(Addr)&w, (Addr) &(temp_var_for_const_27 = aT[10])},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:162:67");
computeDAdd((Addr)&temp_var_for_tac_26,
            {(Addr) &(temp_var_for_const_28 = aT[8]),
             (Addr)&temp_var_for_tac_25},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:162:63");
computeDMul((Addr)&temp_var_for_tac_27, {(Addr)&w, (Addr)&temp_var_for_tac_26},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:162:54");
computeDAdd((Addr)&temp_var_for_tac_28,
            {(Addr) &(temp_var_for_const_29 = aT[6]),
             (Addr)&temp_var_for_tac_27},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:162:50");
computeDMul((Addr)&temp_var_for_tac_29, {(Addr)&w, (Addr)&temp_var_for_tac_28},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:162:41");
computeDAdd((Addr)&temp_var_for_tac_30,
            {(Addr) &(temp_var_for_const_30 = aT[4]),
             (Addr)&temp_var_for_tac_29},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:162:37");
computeDMul((Addr)&temp_var_for_tac_31, {(Addr)&w, (Addr)&temp_var_for_tac_30},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:162:28");
computeDAdd((Addr)&temp_var_for_tac_32,
            {(Addr) &(temp_var_for_const_31 = aT[2]),
             (Addr)&temp_var_for_tac_31},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:162:24");
computeDMul((Addr)&temp_var_for_tac_33, {(Addr)&w, (Addr)&temp_var_for_tac_32},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:162:15");
computeDAdd((Addr)&temp_var_for_tac_34,
            {(Addr) &(temp_var_for_const_32 = aT[0]),
             (Addr)&temp_var_for_tac_33},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:161:19");
computeDMul((Addr)&temp_var_for_tac_35, {(Addr)&z, (Addr)&temp_var_for_tac_34},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:161:10");
AssignD({(Addr)&s1}, (Addr)&temp_var_for_tac_35,
        "/home/shijia/Public/testprogram/s_atan.c_e.c:161:6");
;
double temp_var_for_tac_36, temp_var_for_tac_37, temp_var_for_tac_38,
    temp_var_for_tac_39, temp_var_for_tac_40, temp_var_for_tac_41,
    temp_var_for_tac_42, temp_var_for_tac_43, temp_var_for_tac_44;
double temp_var_for_const_33, temp_var_for_const_34, temp_var_for_const_35,
    temp_var_for_const_36, temp_var_for_const_37;
temp_var_for_tac_36 = w * aT[9];

temp_var_for_tac_37 = aT[7] + temp_var_for_tac_36;

temp_var_for_tac_38 = w * temp_var_for_tac_37;

temp_var_for_tac_39 = aT[5] + temp_var_for_tac_38;

temp_var_for_tac_40 = w * temp_var_for_tac_39;

temp_var_for_tac_41 = aT[3] + temp_var_for_tac_40;

temp_var_for_tac_42 = w * temp_var_for_tac_41;

temp_var_for_tac_43 = aT[1] + temp_var_for_tac_42;

temp_var_for_tac_44 = w * temp_var_for_tac_43;

s2 = temp_var_for_tac_44;
computeDMul((Addr)&temp_var_for_tac_36,
            {(Addr)&w, (Addr) &(temp_var_for_const_33 = aT[9])},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:163:62");
computeDAdd((Addr)&temp_var_for_tac_37,
            {(Addr) &(temp_var_for_const_34 = aT[7]),
             (Addr)&temp_var_for_tac_36},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:163:58");
computeDMul((Addr)&temp_var_for_tac_38, {(Addr)&w, (Addr)&temp_var_for_tac_37},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:163:49");
computeDAdd((Addr)&temp_var_for_tac_39,
            {(Addr) &(temp_var_for_const_35 = aT[5]),
             (Addr)&temp_var_for_tac_38},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:163:45");
computeDMul((Addr)&temp_var_for_tac_40, {(Addr)&w, (Addr)&temp_var_for_tac_39},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:163:36");
computeDAdd((Addr)&temp_var_for_tac_41,
            {(Addr) &(temp_var_for_const_36 = aT[3]),
             (Addr)&temp_var_for_tac_40},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:163:32");
computeDMul((Addr)&temp_var_for_tac_42, {(Addr)&w, (Addr)&temp_var_for_tac_41},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:163:23");
computeDAdd((Addr)&temp_var_for_tac_43,
            {(Addr) &(temp_var_for_const_37 = aT[1]),
             (Addr)&temp_var_for_tac_42},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:163:19");
computeDMul((Addr)&temp_var_for_tac_44, {(Addr)&w, (Addr)&temp_var_for_tac_43},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:163:10");
AssignD({(Addr)&s2}, (Addr)&temp_var_for_tac_44,
        "/home/shijia/Public/testprogram/s_atan.c_e.c:163:6");
;
if (id < 0) {
  double temp_var_for_ext_9;
  double temp_var_for_tac_45, temp_var_for_tac_46, temp_var_for_tac_47;
  temp_var_for_tac_45 = s1 + s2;

  temp_var_for_tac_46 = x * temp_var_for_tac_45;

  temp_var_for_tac_47 = x - temp_var_for_tac_46;

  temp_var_for_ext_9 = temp_var_for_tac_47;
  computeDAdd((Addr)&temp_var_for_tac_45, {(Addr)&s1, (Addr)&s2},
              "/home/shijia/Public/testprogram/s_atan.c_e.c:166:38");
  computeDMul((Addr)&temp_var_for_tac_46,
              {(Addr)&x, (Addr)&temp_var_for_tac_45},
              "/home/shijia/Public/testprogram/s_atan.c_e.c:166:32");
  computeDSub((Addr)&temp_var_for_tac_47,
              {(Addr)&x, (Addr)&temp_var_for_tac_46},
              "/home/shijia/Public/testprogram/s_atan.c_e.c:166:28");
  AssignD({(Addr)&temp_var_for_ext_9}, (Addr)&temp_var_for_tac_47,
          "/home/shijia/Public/testprogram/s_atan.c_e.c:166:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_9;
}

else {
  double temp_var_for_tac_48, temp_var_for_tac_49, temp_var_for_tac_50,
      temp_var_for_tac_51, temp_var_for_tac_52;
  double temp_var_for_const_38, temp_var_for_const_39;
  temp_var_for_tac_48 = s1 + s2;

  temp_var_for_tac_49 = x * temp_var_for_tac_48;

  temp_var_for_tac_50 = temp_var_for_tac_49 - atanlo[id];

  temp_var_for_tac_51 = temp_var_for_tac_50 - x;

  temp_var_for_tac_52 = atanhi[id] - temp_var_for_tac_51;

  z = temp_var_for_tac_52;
  computeDAdd((Addr)&temp_var_for_tac_48, {(Addr)&s1, (Addr)&s2},
              "/home/shijia/Public/testprogram/s_atan.c_e.c:173:32");
  computeDMul((Addr)&temp_var_for_tac_49,
              {(Addr)&x, (Addr)&temp_var_for_tac_48},
              "/home/shijia/Public/testprogram/s_atan.c_e.c:173:26");
  computeDSub((Addr)&temp_var_for_tac_50,
              {(Addr)&temp_var_for_tac_49,
               (Addr) &(temp_var_for_const_38 = atanlo[id])},
              "/home/shijia/Public/testprogram/s_atan.c_e.c:173:38");
  computeDSub((Addr)&temp_var_for_tac_51,
              {(Addr)&temp_var_for_tac_50, (Addr)&x},
              "/home/shijia/Public/testprogram/s_atan.c_e.c:173:52");
  computeDSub((Addr)&temp_var_for_tac_52,
              {(Addr) &(temp_var_for_const_39 = atanhi[id]),
               (Addr)&temp_var_for_tac_51},
              "/home/shijia/Public/testprogram/s_atan.c_e.c:173:20");
  AssignD({(Addr)&z}, (Addr)&temp_var_for_tac_52,
          "/home/shijia/Public/testprogram/s_atan.c_e.c:173:7");
  ;
  double temp_var_for_ext_10;
  double temp_var_for_const_40;
  temp_var_for_ext_10 = (hx < 0) ? -z : z;
  AssignD({(Addr)&temp_var_for_ext_10},
          (Addr) &(temp_var_for_const_40 = (hx < 0) ? -z : z),
          "/home/shijia/Public/testprogram/s_atan.c_e.c:175:25");
  ;
  callExpStack.push(getReal("temp_var_for_ext_10", (Addr)&temp_var_for_ext_10));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_(0.0 - x) t_10;
}
}

#endif

double __atan(double x) {
  double temp_var_for_ext_11;
  temp_var_for_ext_11 = __ieee754_atan(x);
  callExpStack.push(getReal("temp_var_for_ext_11", (Addr)&temp_var_for_ext_11));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_11;
}

__typeof(__atan) atan __attribute__((weak, alias("__atan")));
#ifdef __NO_LONG_DOUBLE_MATH
__typeof(__atanl) __atanl __attribute__((alias("__atan")));
__typeof(__atanl) atanl __attribute__((weak, alias("__atan")));
#endif
