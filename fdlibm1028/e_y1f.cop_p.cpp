#include "../ScDebug/scdebug.h"
/* e_y1f.c -- float version of e_y1.c.
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

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

float __ieee754_y1f(float x) {
  float z, s, c, ss, cc, u, v;
  int32_t hx, ix;

  static const float one = 1.0;
  static const float invsqrtpi = 5.6418961287e-01; /* 0x3f106ebb */
  static const float tpi = 6.3661974669e-01;       /* 0x3f22f983 */
  static const float zero = 0.0;

  static const float U0[5] = {
      (double temp_var_for_tac_0;
  double temp_var_for_const_0, temp_var_for_const_1;
  temp_var_for_tac_0 = 0.0 - 1.9605709612e-01;

), /* 0xbe48c331 */
      5.0443872809e-02,         /* 0x3d4e9e3c */
      (double temp_var_for_tac_1;double temp_var_for_const_2,temp_var_for_const_3;temp_var_for_tac_1 = 0.0 - 1.9125689287e-03;

), /* 0xbafaaf2a */
      2.3525259166e-05,         /* 0x37c5581c */
      (double temp_var_for_tac_2;double temp_var_for_const_4,temp_var_for_const_5;temp_var_for_tac_2 = 0.0 - 9.1909917899e-08;

)  /* 0xb3c56003 */
};

static const float V0[5] = {
    1.9916731864e-02, /* 0x3ca3286a */
    2.0255257550e-04, /* 0x3954644b */
    1.3560879779e-06, /* 0x35b602d4 */
    6.2274145840e-09, /* 0x31d5f8eb */
    1.6655924903e-11  /* 0x2d9281cf */
};

GET_FLOAT_WORD(hx, x);
ix = IC(0x7fffffff) & hx;
/* if Y1(NaN) is NaN, Y1(-inf) is NaN, Y1(inf) is 0 */
if (!FLT_UWORD_IS_FINITE(ix)) {
  float temp_var_for_ext_0;
  float temp_var_for_tac_3, temp_var_for_tac_4, temp_var_for_tac_5;
  float temp_var_for_const_6;
  temp_var_for_tac_3 = x * x;

  temp_var_for_tac_4 = x + temp_var_for_tac_3;

  temp_var_for_tac_5 = one / temp_var_for_tac_4;

  temp_var_for_ext_0 = temp_var_for_tac_5;
  computeDSub((Addr)&temp_var_for_tac_0,
              {(Addr) &(temp_var_for_const_1 = 0.0),
               (Addr) &(temp_var_for_const_0 = 1.9605709612e-01)},
              "/home/shijia/Public/testprogram/e_y1f.c_e.c:30:12");
  computeDSub((Addr)&temp_var_for_tac_1,
              {(Addr) &(temp_var_for_const_3 = 0.0),
               (Addr) &(temp_var_for_const_2 = 1.9125689287e-03)},
              "/home/shijia/Public/testprogram/e_y1f.c_e.c:32:12");
  computeDSub((Addr)&temp_var_for_tac_2,
              {(Addr) &(temp_var_for_const_5 = 0.0),
               (Addr) &(temp_var_for_const_4 = 9.1909917899e-08)},
              "/home/shijia/Public/testprogram/e_y1f.c_e.c:34:12");
  computeFMul((Addr)&temp_var_for_tac_3, {(Addr)&x, (Addr)&x},
              "/home/shijia/Public/testprogram/e_y1f.c_e.c:50:39");
  computeFAdd((Addr)&temp_var_for_tac_4, {(Addr)&x, (Addr)&temp_var_for_tac_3},
              "/home/shijia/Public/testprogram/e_y1f.c_e.c:50:35");
  computeFDiv((Addr)&temp_var_for_tac_5,
              {(Addr) &(temp_var_for_const_6 = one), (Addr)&temp_var_for_tac_4},
              "/home/shijia/Public/testprogram/e_y1f.c_e.c:50:30");
  AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_5,
          "/home/shijia/Public/testprogram/e_y1f.c_e.c:50:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

if (FLT_UWORD_IS_ZERO(ix)) {
  float temp_var_for_ext_1;
  float temp_var_for_tac_6;
  float temp_var_for_const_7;
  temp_var_for_callexp_0 = __builtin_huge_valf();
  temp_var_for_tac_6 = (-(temp_var_for_callexp_0)) + x;

  temp_var_for_ext_1 = temp_var_for_tac_6;
  computeFAdd(
      (Addr)&temp_var_for_tac_6,
      {(Addr) &(temp_var_for_const_7 = (-(temp_var_for_callexp_0))), (Addr)&x},
      "/home/shijia/Public/testprogram/e_y1f.c_e.c:58:37");
  AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_6,
          "/home/shijia/Public/testprogram/e_y1f.c_e.c:58:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return (0.0 - var_for_e)xt_1;
}
/* -inf and overflow exception.  */
if (hx < 0) {
  float temp_var_for_ext_2;
  float temp_var_for_tac_7, temp_var_for_tac_8;
  float temp_var_for_const_8, temp_var_for_const_9;
  temp_var_for_tac_7 = zero * x;

  temp_var_for_tac_8 = zero / temp_var_for_tac_7;

  temp_var_for_ext_2 = temp_var_for_tac_8;
  computeFMul((Addr)&temp_var_for_tac_7,
              {(Addr) &(temp_var_for_const_8 = zero), (Addr)&x},
              "/home/shijia/Public/testprogram/e_y1f.c_e.c:66:39");
  computeFDiv((Addr)&temp_var_for_tac_8, {(Addr) &(temp_var_for_const_9 = zero),
                                          (Addr)&temp_var_for_tac_7},
              "/home/shijia/Public/testprogram/e_y1f.c_e.c:66:31");
  AssignF({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_8,
          "/home/shijia/Public/testprogram/e_y1f.c_e.c:66:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_2;
}

if (ix >= IC(0x40000000)) { /* |x| >= 2.0 */
  __ieee754_sincosf(x, &s, &c);
  float temp_var_for_tac_9, temp_var_for_tac_10;
  float temp_var_for_const_10;
  temp_var_for_tac_9 = 0.0 - s;

  temp_var_for_tac_10 = temp_var_for_tac_9 - c;

  ss = temp_var_for_tac_10;
  computeDSub((Addr)&temp_var_for_tac_9,
              {(Addr) &(temp_var_for_const_10 = 0.0), (Addr)&s},
              "/home/shijia/Public/testprogram/e_y1f.c_e.c:74:15");
  computeDSub((Addr)&temp_var_for_tac_10, {(Addr)&temp_var_for_tac_9, (Addr)&c},
              "/home/shijia/Public/testprogram/e_y1f.c_e.c:74:20");
  AssignF({(Addr)&ss}, (Addr)&temp_var_for_tac_10,
          "/home/shijia/Public/testprogram/e_y1f.c_e.c:74:8");
  ;
  float temp_var_for_tac_11;
  temp_var_for_tac_11 = s - c;

  cc = temp_var_for_tac_11;
  computeFSub((Addr)&temp_var_for_tac_11, {(Addr)&s, (Addr)&c},
              "/home/shijia/Public/testprogram/e_y1f.c_e.c:75:12");
  AssignF({(Addr)&cc}, (Addr)&temp_var_for_tac_11,
          "/home/shijia/Public/testprogram/e_y1f.c_e.c:75:8");
  ;
  if (ix <= FLT_UWORD_HALF_MAX) { /* make sure x+x not overflow */
    float temp_var_for_tac_12;
    float temp_var_for_const_11;
    float temp_var_for_callexp_1;

    temp_var_for_tac_12 = x + x;

    temp_var_for_callexp_1 = __ieee754_cosf(temp_var_for_tac_12);
    z = temp_var_for_callexp_1;
    computeFAdd((Addr)&temp_var_for_tac_12, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_y1f.c_e.c:77:28");
    AssignF({(Addr)&z},
            (Addr) &(temp_var_for_const_11 = temp_var_for_callexp_1),
            "/home/shijia/Public/testprogram/e_y1f.c_e.c:77:9");
    ;
    if (int temp_var_for_tac_13, temp_var_for_tac_14; int temp_var_for_const_12;
        temp_var_for_tac_13 = s * c;

        temp_var_for_tac_14 = temp_var_for_tac_13 > zero;

        ) {
      float temp_var_for_tac_15;
      temp_var_for_tac_15 = z / ss;

      cc = temp_var_for_tac_15;
      computeFMul((Addr)&temp_var_for_tac_13, {(Addr)&s, (Addr)&c},
                  "/home/shijia/Public/testprogram/e_y1f.c_e.c:78:14");
      compute(
          (Addr)&temp_var_for_tac_14,
          {(Addr)&temp_var_for_tac_13, (Addr) &(temp_var_for_const_12 = zero)},
          "/home/shijia/Public/testprogram/e_y1f.c_e.c:78:19");
      computeFDiv((Addr)&temp_var_for_tac_15, {(Addr)&z, (Addr)&ss},
                  "/home/shijia/Public/testprogram/e_y1f.c_e.c:79:16");
      AssignF({(Addr)&cc}, (Addr)&temp_var_for_tac_15,
              "/home/shijia/Public/testprogram/e_y1f.c_e.c:79:12");
      ;
    }

    else {
      float temp_var_for_ext_3;
      float temp_var_for_tac_16;
      temp_var_for_tac_16 = z / cc;

      temp_var_for_ext_3 = temp_var_for_tac_16;
      computeFDiv((Addr)&temp_var_for_tac_16, {(Addr)&z, (Addr)&cc},
                  "/home/shijia/Public/testprogram/e_y1f.c_e.c:84:32");
      AssignF({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_16,
              "/home/shijia/Public/testprogram/e_y1f.c_e.c:84:28");
      ; // ss
      /*(ss)(z)(cc)(z)*/
      ss = temp_var_for_ext_3;
      AssignF({(Addr)&ss}, (Addr)&temp_var_for_ext_3,
              "/home/shijia/Public/testprogram/e_y1f.c_e.c:86:12");
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
    float temp_var_for_ext_4;
    float temp_var_for_tac_17, temp_var_for_tac_18;
    float temp_var_for_const_13, temp_var_for_const_14;
    float temp_var_for_callexp_2;

    temp_var_for_tac_17 = invsqrtpi * ss;

    temp_var_for_callexp_2 = __ieee754_sqrtf(x);
    temp_var_for_tac_18 = temp_var_for_tac_17 / temp_var_for_callexp_2;

    temp_var_for_ext_4 = temp_var_for_tac_18;
    computeFMul((Addr)&temp_var_for_tac_17,
                {(Addr) &(temp_var_for_const_13 = invsqrtpi), (Addr)&ss},
                "/home/shijia/Public/testprogram/e_y1f.c_e.c:102:39");
    computeFDiv((Addr)&temp_var_for_tac_18,
                {(Addr)&temp_var_for_tac_17,
                 (Addr) &(temp_var_for_const_14 = temp_var_for_callexp_2)},
                "/home/shijia/Public/testprogram/e_y1f.c_e.c:102:45");
    AssignF({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_18,
            "/home/shijia/Public/testprogram/e_y1f.c_e.c:102:26");
    ; // z
    /*(cc)(z)(__ieee754_sqrtf(x))(ss)(invsqrtpi)*/
    z = temp_var_for_ext_4;
    AssignF({(Addr)&z}, (Addr)&temp_var_for_ext_4,
            "/home/shijia/Public/testprogram/e_y1f.c_e.c:104:9");
    ;
  }

  else {
    float temp_var_for_const_15;
    float temp_var_for_callexp_3;

    temp_var_for_callexp_3 = __j1_y1_ponef(x);
    u = temp_var_for_callexp_3;
    AssignF({(Addr)&u},
            (Addr) &(temp_var_for_const_15 = temp_var_for_callexp_3),
            "/home/shijia/Public/testprogram/e_y1f.c_e.c:108:9");
    ;
    float temp_var_for_const_16;
    float temp_var_for_callexp_4;

    temp_var_for_callexp_4 = __j1_y1_qonef(x);
    v = temp_var_for_callexp_4;
    AssignF({(Addr)&v},
            (Addr) &(temp_var_for_const_16 = temp_var_for_callexp_4),
            "/home/shijia/Public/testprogram/e_y1f.c_e.c:109:9");
    ;
    float temp_var_for_tac_19, temp_var_for_tac_20, temp_var_for_tac_21,
        temp_var_for_tac_22, temp_var_for_tac_23;
    float temp_var_for_const_17, temp_var_for_const_18;
    float temp_var_for_callexp_5;

    temp_var_for_tac_19 = u * ss;

    temp_var_for_tac_20 = v * cc;

    temp_var_for_tac_21 = temp_var_for_tac_19 + temp_var_for_tac_20;

    temp_var_for_tac_22 = invsqrtpi * temp_var_for_tac_21;

    temp_var_for_callexp_5 = __ieee754_sqrtf(x);
    temp_var_for_tac_23 = temp_var_for_tac_22 / temp_var_for_callexp_5;

    z = temp_var_for_tac_23;
    computeFMul((Addr)&temp_var_for_tac_19, {(Addr)&u, (Addr)&ss},
                "/home/shijia/Public/testprogram/e_y1f.c_e.c:110:26");
    computeFMul((Addr)&temp_var_for_tac_20, {(Addr)&v, (Addr)&cc},
                "/home/shijia/Public/testprogram/e_y1f.c_e.c:110:35");
    computeFAdd((Addr)&temp_var_for_tac_21,
                {(Addr)&temp_var_for_tac_19, (Addr)&temp_var_for_tac_20},
                "/home/shijia/Public/testprogram/e_y1f.c_e.c:110:31");
    computeFMul((Addr)&temp_var_for_tac_22,
                {(Addr) &(temp_var_for_const_17 = invsqrtpi),
                 (Addr)&temp_var_for_tac_21},
                "/home/shijia/Public/testprogram/e_y1f.c_e.c:110:21");
    computeFDiv((Addr)&temp_var_for_tac_23,
                {(Addr)&temp_var_for_tac_22,
                 (Addr) &(temp_var_for_const_18 = temp_var_for_callexp_5)},
                "/home/shijia/Public/testprogram/e_y1f.c_e.c:110:41");
    AssignF({(Addr)&z}, (Addr)&temp_var_for_tac_23,
            "/home/shijia/Public/testprogram/e_y1f.c_e.c:110:9");
    ;
  }
  float temp_var_for_ext_5;
  temp_var_for_ext_5 = z;
  AssignF({(Addr)&temp_var_for_ext_5}, (Addr)&z,
          "/home/shijia/Public/testprogram/e_y1f.c_e.c:113:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_5;
}
if (ix <= IC(0x33000000)) { /* x < 2**-25 */
  float temp_var_for_ext_6;
  float temp_var_for_tac_24;
  float temp_var_for_const_19;
  temp_var_for_tac_24 = (-(tpi)) / x;

  temp_var_for_ext_6 = temp_var_for_tac_24;
  computeFDiv((Addr)&temp_var_for_tac_24,
              {(Addr) &(temp_var_for_const_19 = (-(tpi))), (Addr)&x},
              "/home/shijia/Public/testprogram/e_y1f.c_e.c:120:32");
  AssignF({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_24,
          "/home/shijia/Public/testprogram/e_y1f.c_e.c:120:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_(0.0 - or_) ext_6;
}
float temp_var_for_tac_25;
temp_var_for_tac_25 = x * x;

z = temp_var_for_tac_25;
computeFMul((Addr)&temp_var_for_tac_25, {(Addr)&x, (Addr)&x},
            "/home/shijia/Public/testprogram/e_y1f.c_e.c:125:9");
AssignF({(Addr)&z}, (Addr)&temp_var_for_tac_25,
        "/home/shijia/Public/testprogram/e_y1f.c_e.c:125:5");
;
float temp_var_for_tac_26, temp_var_for_tac_27, temp_var_for_tac_28,
    temp_var_for_tac_29, temp_var_for_tac_30, temp_var_for_tac_31,
    temp_var_for_tac_32, temp_var_for_tac_33;
float temp_var_for_const_20, temp_var_for_const_21, temp_var_for_const_22,
    temp_var_for_const_23, temp_var_for_const_24;
temp_var_for_tac_26 = z * U0[4];

temp_var_for_tac_27 = U0[3] + temp_var_for_tac_26;

temp_var_for_tac_28 = z * temp_var_for_tac_27;

temp_var_for_tac_29 = U0[2] + temp_var_for_tac_28;

temp_var_for_tac_30 = z * temp_var_for_tac_29;

temp_var_for_tac_31 = U0[1] + temp_var_for_tac_30;

temp_var_for_tac_32 = z * temp_var_for_tac_31;

temp_var_for_tac_33 = U0[0] + temp_var_for_tac_32;

u = temp_var_for_tac_33;
computeFMul((Addr)&temp_var_for_tac_26,
            {(Addr)&z, (Addr) &(temp_var_for_const_20 = U0[4])},
            "/home/shijia/Public/testprogram/e_y1f.c_e.c:126:56");
computeFAdd((Addr)&temp_var_for_tac_27,
            {(Addr) &(temp_var_for_const_21 = U0[3]),
             (Addr)&temp_var_for_tac_26},
            "/home/shijia/Public/testprogram/e_y1f.c_e.c:126:52");
computeFMul((Addr)&temp_var_for_tac_28, {(Addr)&z, (Addr)&temp_var_for_tac_27},
            "/home/shijia/Public/testprogram/e_y1f.c_e.c:126:43");
computeFAdd((Addr)&temp_var_for_tac_29,
            {(Addr) &(temp_var_for_const_22 = U0[2]),
             (Addr)&temp_var_for_tac_28},
            "/home/shijia/Public/testprogram/e_y1f.c_e.c:126:39");
computeFMul((Addr)&temp_var_for_tac_30, {(Addr)&z, (Addr)&temp_var_for_tac_29},
            "/home/shijia/Public/testprogram/e_y1f.c_e.c:126:30");
computeFAdd((Addr)&temp_var_for_tac_31,
            {(Addr) &(temp_var_for_const_23 = U0[1]),
             (Addr)&temp_var_for_tac_30},
            "/home/shijia/Public/testprogram/e_y1f.c_e.c:126:26");
computeFMul((Addr)&temp_var_for_tac_32, {(Addr)&z, (Addr)&temp_var_for_tac_31},
            "/home/shijia/Public/testprogram/e_y1f.c_e.c:126:17");
computeFAdd((Addr)&temp_var_for_tac_33,
            {(Addr) &(temp_var_for_const_24 = U0[0]),
             (Addr)&temp_var_for_tac_32},
            "/home/shijia/Public/testprogram/e_y1f.c_e.c:126:13");
AssignF({(Addr)&u}, (Addr)&temp_var_for_tac_33,
        "/home/shijia/Public/testprogram/e_y1f.c_e.c:126:5");
;
float temp_var_for_tac_34, temp_var_for_tac_35, temp_var_for_tac_36,
    temp_var_for_tac_37, temp_var_for_tac_38, temp_var_for_tac_39,
    temp_var_for_tac_40, temp_var_for_tac_41, temp_var_for_tac_42,
    temp_var_for_tac_43;
float temp_var_for_const_25, temp_var_for_const_26, temp_var_for_const_27,
    temp_var_for_const_28, temp_var_for_const_29, temp_var_for_const_30;
temp_var_for_tac_34 = z * V0[4];

temp_var_for_tac_35 = V0[3] + temp_var_for_tac_34;

temp_var_for_tac_36 = z * temp_var_for_tac_35;

temp_var_for_tac_37 = V0[2] + temp_var_for_tac_36;

temp_var_for_tac_38 = z * temp_var_for_tac_37;

temp_var_for_tac_39 = V0[1] + temp_var_for_tac_38;

temp_var_for_tac_40 = z * temp_var_for_tac_39;

temp_var_for_tac_41 = V0[0] + temp_var_for_tac_40;

temp_var_for_tac_42 = z * temp_var_for_tac_41;

temp_var_for_tac_43 = one + temp_var_for_tac_42;

v = temp_var_for_tac_43;
computeFMul((Addr)&temp_var_for_tac_34,
            {(Addr)&z, (Addr) &(temp_var_for_const_25 = V0[4])},
            "/home/shijia/Public/testprogram/e_y1f.c_e.c:127:67");
computeFAdd((Addr)&temp_var_for_tac_35,
            {(Addr) &(temp_var_for_const_26 = V0[3]),
             (Addr)&temp_var_for_tac_34},
            "/home/shijia/Public/testprogram/e_y1f.c_e.c:127:63");
computeFMul((Addr)&temp_var_for_tac_36, {(Addr)&z, (Addr)&temp_var_for_tac_35},
            "/home/shijia/Public/testprogram/e_y1f.c_e.c:127:54");
computeFAdd((Addr)&temp_var_for_tac_37,
            {(Addr) &(temp_var_for_const_27 = V0[2]),
             (Addr)&temp_var_for_tac_36},
            "/home/shijia/Public/testprogram/e_y1f.c_e.c:127:50");
computeFMul((Addr)&temp_var_for_tac_38, {(Addr)&z, (Addr)&temp_var_for_tac_37},
            "/home/shijia/Public/testprogram/e_y1f.c_e.c:127:41");
computeFAdd((Addr)&temp_var_for_tac_39,
            {(Addr) &(temp_var_for_const_28 = V0[1]),
             (Addr)&temp_var_for_tac_38},
            "/home/shijia/Public/testprogram/e_y1f.c_e.c:127:37");
computeFMul((Addr)&temp_var_for_tac_40, {(Addr)&z, (Addr)&temp_var_for_tac_39},
            "/home/shijia/Public/testprogram/e_y1f.c_e.c:127:28");
computeFAdd((Addr)&temp_var_for_tac_41,
            {(Addr) &(temp_var_for_const_29 = V0[0]),
             (Addr)&temp_var_for_tac_40},
            "/home/shijia/Public/testprogram/e_y1f.c_e.c:127:24");
computeFMul((Addr)&temp_var_for_tac_42, {(Addr)&z, (Addr)&temp_var_for_tac_41},
            "/home/shijia/Public/testprogram/e_y1f.c_e.c:127:15");
computeFAdd((Addr)&temp_var_for_tac_43,
            {(Addr) &(temp_var_for_const_30 = one), (Addr)&temp_var_for_tac_42},
            "/home/shijia/Public/testprogram/e_y1f.c_e.c:127:11");
AssignF({(Addr)&v}, (Addr)&temp_var_for_tac_43,
        "/home/shijia/Public/testprogram/e_y1f.c_e.c:127:5");
;
float temp_var_for_ext_7;
float temp_var_for_tac_44, temp_var_for_tac_45, temp_var_for_tac_46,
    temp_var_for_tac_47, temp_var_for_tac_48, temp_var_for_tac_49,
    temp_var_for_tac_50;
float temp_var_for_const_31, temp_var_for_const_32, temp_var_for_const_33,
    temp_var_for_const_34;
float temp_var_for_callexp_6;

float temp_var_for_callexp_7;

temp_var_for_tac_44 = u / v;

temp_var_for_tac_45 = x * temp_var_for_tac_44;

temp_var_for_callexp_6 = __ieee754_j1f(x);
temp_var_for_callexp_7 = __ieee754_logf(x);
temp_var_for_tac_46 = temp_var_for_callexp_6 * temp_var_for_callexp_7;

temp_var_for_tac_47 = one / x;

temp_var_for_tac_48 = temp_var_for_tac_46 - temp_var_for_tac_47;

temp_var_for_tac_49 = tpi * temp_var_for_tac_48;

temp_var_for_tac_50 = temp_var_for_tac_45 + temp_var_for_tac_49;

temp_var_for_ext_7 = temp_var_for_tac_50;
computeFDiv((Addr)&temp_var_for_tac_44, {(Addr)&u, (Addr)&v},
            "/home/shijia/Public/testprogram/e_y1f.c_e.c:130:15");
computeFMul((Addr)&temp_var_for_tac_45, {(Addr)&x, (Addr)&temp_var_for_tac_44},
            "/home/shijia/Public/testprogram/e_y1f.c_e.c:130:10");
computeFMul((Addr)&temp_var_for_tac_46,
            {(Addr) &(temp_var_for_const_32 = temp_var_for_callexp_6),
             (Addr) &(temp_var_for_const_31 = temp_var_for_callexp_7)},
            "/home/shijia/Public/testprogram/e_y1f.c_e.c:130:46");
computeFDiv((Addr)&temp_var_for_tac_47,
            {(Addr) &(temp_var_for_const_33 = one), (Addr)&x},
            "/home/shijia/Public/testprogram/e_y1f.c_e.c:130:72");
computeFSub((Addr)&temp_var_for_tac_48,
            {(Addr)&temp_var_for_tac_46, (Addr)&temp_var_for_tac_47},
            "/home/shijia/Public/testprogram/e_y1f.c_e.c:130:66");
computeFMul((Addr)&temp_var_for_tac_49,
            {(Addr) &(temp_var_for_const_34 = tpi), (Addr)&temp_var_for_tac_48},
            "/home/shijia/Public/testprogram/e_y1f.c_e.c:130:26");
computeFAdd((Addr)&temp_var_for_tac_50,
            {(Addr)&temp_var_for_tac_45, (Addr)&temp_var_for_tac_49},
            "/home/shijia/Public/testprogram/e_y1f.c_e.c:130:20");
AssignF({(Addr)&temp_var_for_ext_7}, (Addr)&temp_var_for_tac_50,
        "/home/shijia/Public/testprogram/e_y1f.c_e.c:129:22");
;
callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
callExp++; /*identify the function is  add move tmpShadow*/
return temp_var_for_ext_7;
}

/* wrapper y1 */
float __y1f(float x) {
  if ((islessequal(x, 0.0F) || isgreater(x, X_TLOSS)) &&
      _LIB_VERSION != _IEEE_) {
    if (int temp_var_for_tac_51; int temp_var_for_const_35;
        temp_var_for_tac_51 = x < 0.0F;

        ) {
      /* d = zero/(x-x) */
      feraiseexcept(FE_INVALID);
      float temp_var_for_ext_8;
      float temp_var_for_const_36;
      float temp_var_for_callexp_9;

      temp_var_for_callexp_8 = __builtin_huge_valf();
      temp_var_for_callexp_9 = __kernel_standard_f(
          x, x, (-(temp_var_for_callexp_8)), KMATHERRF_Y1_MINUS);
      temp_var_for_ext_8 = temp_var_for_callexp_9;
      compute((Addr)&temp_var_for_tac_51,
              {(Addr)&x, (Addr) &(temp_var_for_const_35 = 0.0F)},
              "/home/shijia/Public/testprogram/e_y1f.c_e.c:140:11");
      AssignF({(Addr)&temp_var_for_ext_8},
              (Addr) &(temp_var_for_const_36 = temp_var_for_callexp_9),
              "/home/shijia/Public/testprogram/e_y1f.c_e.c:144:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
      callExp++; /*identify the function is  add move tmpSha(0.0 - ow*/
retu)rn temp_var_for_ext_8;
    } else {
      if (int temp_var_for_tac_52; int temp_var_for_const_37;
          temp_var_for_tac_52 = x == 0.0F;

          )
      /* d = -one/(x-x) */
      {
        float temp_var_for_ext_9;
        float temp_var_for_const_38;
        float temp_var_for_callexp_11;

        temp_var_for_callexp_10 = __builtin_huge_valf();
        temp_var_for_callexp_11 = __kernel_standard_f(
            x, x, (-(temp_var_for_callexp_10)), KMATHERRF_Y1_ZERO);
        temp_var_for_ext_9 = temp_var_for_callexp_11;
        compute((Addr)&temp_var_for_tac_52,
                {(Addr)&x, (Addr) &(temp_var_for_const_37 = 0.0F)},
                "/home/shijia/Public/testprogram/e_y1f.c_e.c:151:13");
        AssignF({(Addr)&temp_var_for_ext_9},
                (Addr) &(temp_var_for_const_38 = temp_var_for_callexp_11),
                "/home/shijia/Public/testprogram/e_y1f.c_e.c:155:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
        callExp++; /*identify the function is  add move tmpShad(0.0 - w*/
retur)n temp_var_for_ext_9;
      }

      else {
        if (_LIB_VERSION != _POSIX_)
        /* y1(x>X_TLOSS) */
        {
          float temp_var_for_ext_10;
          float temp_var_for_const_39;
          float temp_var_for_callexp_12;

          temp_var_for_callexp_12 =
              __kernel_standard_f(x, x, 0.0f, KMATHERRF_Y1_TLOSS);
          temp_var_for_ext_10 = temp_var_for_callexp_12;
          AssignF({(Addr)&temp_var_for_ext_10},
                  (Addr) &(temp_var_for_const_39 = temp_var_for_callexp_12),
                  "/home/shijia/Public/testprogram/e_y1f.c_e.c:168:31");
          ;
          callExpStack.push(
              getReal("temp_var_for_ext_10", (Addr)&temp_var_for_ext_10));
          callExp++; /*identify the function is  add move tmpShadow*/
          return temp_var_for_ext_10;
        }
      }
    }
  }

  float temp_var_for_ext_11;
  float temp_var_for_const_40;
  float temp_var_for_callexp_13;

  temp_var_for_callexp_13 = __ieee754_y1f(x);
  temp_var_for_ext_11 = temp_var_for_callexp_13;
  AssignF({(Addr)&temp_var_for_ext_11},
          (Addr) &(temp_var_for_const_40 = temp_var_for_callexp_13),
          "/home/shijia/Public/testprogram/e_y1f.c_e.c:180:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_11", (Addr)&temp_var_for_ext_11));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_11;
}

__typeof(__y1f) y1f __attribute__((weak, alias("__y1f")));
