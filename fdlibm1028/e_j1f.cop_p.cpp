#include "../ScDebug/scdebug.h"
/* e_j1f.c -- float version of e_j1.c.
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

float __ieee754_j1f(float x) {
  float z, s, c, ss, cc, r, u, v, y;
  int32_t hx, ix;

  static const float hugeval = 1e30;
  static const float one = 1.0;
  static const float invsqrtpi = 5.6418961287e-01; /* 0x3f106ebb */
  static const float zero = 0.0;

  /* R0/S0 on [0,2] */
  static const float r00 = (double temp_var_for_tac_0;
                            double temp_var_for_const_0, temp_var_for_const_1;
                            temp_var_for_tac_0 = 0.0 - 6.2500000000e-02;

                            );               /* 0xbd800000 */
  static const float r01 = 1.4070566976e-03; /* 0x3ab86cfd */
  static const float r02 = (double temp_var_for_tac_1;
                            double temp_var_for_const_2, temp_var_for_const_3;
                            temp_var_for_tac_1 = 0.0 - 1.5995563444e-05;

                            );               /* 0xb7862e36 */
  static const float r03 = 4.9672799207e-08; /* 0x335557d2 */
  static const float s01 = 1.9153760746e-02; /* 0x3c9ce859 */
  static const float s02 = 1.8594678841e-04; /* 0x3942fab6 */
  static const float s03 = 1.1771846857e-06; /* 0x359dffc2 */
  static const float s04 = 5.0463624390e-09; /* 0x31ad6446 */
  static const float s05 = 1.2354227016e-11; /* 0x2d59567e */

  GET_FLOAT_WORD(hx, x);
  ix = hx & IC(0x7fffffff);
  if (!FLT_UWORD_IS_FINITE(ix)) {
    float temp_var_for_ext_0;
    float temp_var_for_tac_2;
    float temp_var_for_const_4;
    temp_var_for_tac_2 = one / x;

    temp_var_for_ext_0 = temp_var_for_tac_2;
    computeDSub((Addr)&temp_var_for_tac_0,
                {(Addr) &(temp_var_for_const_1 = 0.0),
                 (Addr) &(temp_var_for_const_0 = 6.2500000000e-02)},
                "/home/shijia/Public/testprogram/e_j1f.c_e.c:30:33");
    computeDSub((Addr)&temp_var_for_tac_1,
                {(Addr) &(temp_var_for_const_3 = 0.0),
                 (Addr) &(temp_var_for_const_2 = 1.5995563444e-05)},
                "/home/shijia/Public/testprogram/e_j1f.c_e.c:32:33");
    computeFDiv((Addr)&temp_var_for_tac_2,
                {(Addr) &(temp_var_for_const_4 = one), (Addr)&x},
                "/home/shijia/Public/testprogram/e_j1f.c_e.c:44:30");
    AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_2,
            "/home/shijia/Public/testprogram/e_j1f.c_e.c:44:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  float temp_var_for_const_5;
  float temp_var_for_callexp_0;

  temp_var_for_callexp_0 = fabsf(x);
  y = temp_var_for_callexp_0;
  AssignF({(Addr)&y}, (Addr) &(temp_var_for_const_5 = temp_var_for_callexp_0),
          "/home/shijia/Public/testprogram/e_j1f.c_e.c:50:5");
  ;
  if (ix >= IC(0x40000000)) { /* |x| >= 2.0 */
    __ieee754_sincosf(y, &s, &c);
    float temp_var_for_tac_3, temp_var_for_tac_4;
    float temp_var_for_const_6;
    temp_var_for_tac_3 = 0.0 - s;

    temp_var_for_tac_4 = temp_var_for_tac_3 - c;

    ss = temp_var_for_tac_4;
    computeDSub((Addr)&temp_var_for_tac_3,
                {(Addr) &(temp_var_for_const_6 = 0.0), (Addr)&s},
                "/home/shijia/Public/testprogram/e_j1f.c_e.c:53:15");
    computeDSub((Addr)&temp_var_for_tac_4,
                {(Addr)&temp_var_for_tac_3, (Addr)&c},
                "/home/shijia/Public/testprogram/e_j1f.c_e.c:53:20");
    AssignF({(Addr)&ss}, (Addr)&temp_var_for_tac_4,
            "/home/shijia/Public/testprogram/e_j1f.c_e.c:53:8");
    ;
    float temp_var_for_tac_5;
    temp_var_for_tac_5 = s - c;

    cc = temp_var_for_tac_5;
    computeFSub((Addr)&temp_var_for_tac_5, {(Addr)&s, (Addr)&c},
                "/home/shijia/Public/testprogram/e_j1f.c_e.c:54:12");
    AssignF({(Addr)&cc}, (Addr)&temp_var_for_tac_5,
            "/home/shijia/Public/testprogram/e_j1f.c_e.c:54:8");
    ;
    if (ix <= FLT_UWORD_HALF_MAX) { /* make sure y+y not overflow */
      float temp_var_for_tac_6;
      float temp_var_for_const_7;
      float temp_var_for_callexp_1;

      temp_var_for_tac_6 = y + y;

      temp_var_for_callexp_1 = __ieee754_cosf(temp_var_for_tac_6);
      z = temp_var_for_callexp_1;
      computeFAdd((Addr)&temp_var_for_tac_6, {(Addr)&y, (Addr)&y},
                  "/home/shijia/Public/testprogram/e_j1f.c_e.c:56:28");
      AssignF({(Addr)&z},
              (Addr) &(temp_var_for_const_7 = temp_var_for_callexp_1),
              "/home/shijia/Public/testprogram/e_j1f.c_e.c:56:9");
      ;
      if (int temp_var_for_tac_7, temp_var_for_tac_8; int temp_var_for_const_8;
          temp_var_for_tac_7 = s * c;

          temp_var_for_tac_8 = temp_var_for_tac_7 > zero;

          ) {
        float temp_var_for_tac_9;
        temp_var_for_tac_9 = z / ss;

        cc = temp_var_for_tac_9;
        computeFMul((Addr)&temp_var_for_tac_7, {(Addr)&s, (Addr)&c},
                    "/home/shijia/Public/testprogram/e_j1f.c_e.c:57:14");
        compute(
            (Addr)&temp_var_for_tac_8,
            {(Addr)&temp_var_for_tac_7, (Addr) &(temp_var_for_const_8 = zero)},
            "/home/shijia/Public/testprogram/e_j1f.c_e.c:57:19");
        computeFDiv((Addr)&temp_var_for_tac_9, {(Addr)&z, (Addr)&ss},
                    "/home/shijia/Public/testprogram/e_j1f.c_e.c:58:16");
        AssignF({(Addr)&cc}, (Addr)&temp_var_for_tac_9,
                "/home/shijia/Public/testprogram/e_j1f.c_e.c:58:12");
        ;
      }

      else {
        float temp_var_for_ext_1;
        float temp_var_for_tac_10;
        temp_var_for_tac_10 = z / cc;

        temp_var_for_ext_1 = temp_var_for_tac_10;
        computeFDiv((Addr)&temp_var_for_tac_10, {(Addr)&z, (Addr)&cc},
                    "/home/shijia/Public/testprogram/e_j1f.c_e.c:63:32");
        AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_10,
                "/home/shijia/Public/testprogram/e_j1f.c_e.c:63:28");
        ; // ss
        /*(ss)(z)(cc)(z)*/
        ss = temp_var_for_ext_1;
        AssignF({(Addr)&ss}, (Addr)&temp_var_for_ext_1,
                "/home/shijia/Public/testprogram/e_j1f.c_e.c:65:12");
        ;
      }
    }
    /*
     * j1(x) = 1/sqrt(pi) * (P(1,x)*cc - Q(1,x)*ss) / sqrt(x)
     * y1(x) = 1/sqrt(pi) * (P(1,x)*ss + Q(1,x)*cc) / sqrt(x)
     */
    if (ix > IC(0x48000000)) {
      float temp_var_for_ext_2;
      float temp_var_for_tac_11, temp_var_for_tac_12;
      float temp_var_for_const_9, temp_var_for_const_10;
      float temp_var_for_callexp_2;

      temp_var_for_tac_11 = invsqrtpi * cc;

      temp_var_for_callexp_2 = __ieee754_sqrtf(y);
      temp_var_for_tac_12 = temp_var_for_tac_11 / temp_var_for_callexp_2;

      temp_var_for_ext_2 = temp_var_for_tac_12;
      computeFMul((Addr)&temp_var_for_tac_11,
                  {(Addr) &(temp_var_for_const_9 = invsqrtpi), (Addr)&cc},
                  "/home/shijia/Public/testprogram/e_j1f.c_e.c:74:39");
      computeFDiv((Addr)&temp_var_for_tac_12,
                  {(Addr)&temp_var_for_tac_11,
                   (Addr) &(temp_var_for_const_10 = temp_var_for_callexp_2)},
                  "/home/shijia/Public/testprogram/e_j1f.c_e.c:74:45");
      AssignF({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_12,
              "/home/shijia/Public/testprogram/e_j1f.c_e.c:74:26");
      ; // z
      /*(cc)(z)(__ieee754_sqrtf(y))(cc)(invsqrtpi)*/
      z = temp_var_for_ext_2;
      AssignF({(Addr)&z}, (Addr)&temp_var_for_ext_2,
              "/home/shijia/Public/testprogram/e_j1f.c_e.c:76:9");
      ;
    }

    else {
      float temp_var_for_const_11;
      float temp_var_for_callexp_3;

      temp_var_for_callexp_3 = __j1_y1_ponef(y);
      u = temp_var_for_callexp_3;
      AssignF({(Addr)&u},
              (Addr) &(temp_var_for_const_11 = temp_var_for_callexp_3),
              "/home/shijia/Public/testprogram/e_j1f.c_e.c:80:9");
      ;
      float temp_var_for_const_12;
      float temp_var_for_callexp_4;

      temp_var_for_callexp_4 = __j1_y1_qonef(y);
      v = temp_var_for_callexp_4;
      AssignF({(Addr)&v},
              (Addr) &(temp_var_for_const_12 = temp_var_for_callexp_4),
              "/home/shijia/Public/testprogram/e_j1f.c_e.c:81:9");
      ;
      float temp_var_for_tac_13, temp_var_for_tac_14, temp_var_for_tac_15,
          temp_var_for_tac_16, temp_var_for_tac_17;
      float temp_var_for_const_13, temp_var_for_const_14;
      float temp_var_for_callexp_5;

      temp_var_for_tac_13 = u * cc;

      temp_var_for_tac_14 = v * ss;

      temp_var_for_tac_15 = temp_var_for_tac_13 - temp_var_for_tac_14;

      temp_var_for_tac_16 = invsqrtpi * temp_var_for_tac_15;

      temp_var_for_callexp_5 = __ieee754_sqrtf(y);
      temp_var_for_tac_17 = temp_var_for_tac_16 / temp_var_for_callexp_5;

      z = temp_var_for_tac_17;
      computeFMul((Addr)&temp_var_for_tac_13, {(Addr)&u, (Addr)&cc},
                  "/home/shijia/Public/testprogram/e_j1f.c_e.c:82:26");
      computeFMul((Addr)&temp_var_for_tac_14, {(Addr)&v, (Addr)&ss},
                  "/home/shijia/Public/testprogram/e_j1f.c_e.c:82:35");
      computeFSub((Addr)&temp_var_for_tac_15,
                  {(Addr)&temp_var_for_tac_13, (Addr)&temp_var_for_tac_14},
                  "/home/shijia/Public/testprogram/e_j1f.c_e.c:82:31");
      computeFMul((Addr)&temp_var_for_tac_16,
                  {(Addr) &(temp_var_for_const_13 = invsqrtpi),
                   (Addr)&temp_var_for_tac_15},
                  "/home/shijia/Public/testprogram/e_j1f.c_e.c:82:21");
      computeFDiv((Addr)&temp_var_for_tac_17,
                  {(Addr)&temp_var_for_tac_16,
                   (Addr) &(temp_var_for_const_14 = temp_var_for_callexp_5)},
                  "/home/shijia/Public/testprogram/e_j1f.c_e.c:82:41");
      AssignF({(Addr)&z}, (Addr)&temp_var_for_tac_17,
              "/home/shijia/Public/testprogram/e_j1f.c_e.c:82:9");
      ;
    }
    if (hx < 0) {
      float temp_var_for_ext_3;
      float temp_var_for_const_15;
      temp_var_for_ext_3 = (-(z));
      AssignF({(Addr)&temp_var_for_ext_3},
              (Addr) &(temp_var_for_const_15 = (-(z))),
              "/home/shijia/Public/testprogram/e_j1f.c_e.c:86:26");
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
      float temp_var_for_ext_4;
      temp_var_for_ext_4 = z;
      computeDSub((Addr)&temp_var_for_tac_18,
                  {(Addr) &(temp_var_for_const_17 = 0.0),
                   (Addr) &(temp_var_for_const_16 = 3)},
                  "/home/shijia/Public/testprogram/e_j1f.c_e.c:90:19");
      AssignF({(Addr)&temp_var_for_ext_4}, (Addr)&z,
              "/home/shijia/Public/testprogram/e_j1f.c_e.c:95:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_4;
    }
  }
  if (ix < IC(0x32000000)) { /* |x|<2**-27 */
    if (int temp_var_for_tac_19, temp_var_for_tac_20;
        int temp_var_for_const_18, temp_var_for_const_19;
        temp_var_for_tac_19 = hugeval + x;

        temp_var_for_tac_20 = temp_var_for_tac_19 > one;

        ) {
      float temp_var_for_ext_5;
      float temp_var_for_tac_21;
      float temp_var_for_const_20;
      temp_var_for_tac_21 = 0.5f * x;

      temp_var_for_ext_5 = temp_var_for_tac_21;
      computeFAdd((Addr)&temp_var_for_tac_19,
                  {(Addr) &(temp_var_for_const_18 = hugeval), (Addr)&x},
                  "/home/shijia/Public/testprogram/e_j1f.c_e.c:103:17");
      compute(
          (Addr)&temp_var_for_tac_20,
          {(Addr)&temp_var_for_tac_19, (Addr) &(temp_var_for_const_19 = one)},
          "/home/shijia/Public/testprogram/e_j1f.c_e.c:103:21");
      computeFMul((Addr)&temp_var_for_tac_21,
                  {(Addr) &(temp_var_for_const_20 = 0.5f), (Addr)&x},
                  "/home/shijia/Public/testprogram/e_j1f.c_e.c:105:33");
      AssignF({(Addr)&temp_var_for_ext_5}, (Addr)&temp_var_for_tac_21,
              "/home/shijia/Public/testprogram/e_j1f.c_e.c:105:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_5;
    }
    /* inexact if x!=0 necessary */
  }
  float temp_var_for_tac_22;
  temp_var_for_tac_22 = x * x;

  z = temp_var_for_tac_22;
  computeFMul((Addr)&temp_var_for_tac_22, {(Addr)&x, (Addr)&x},
              "/home/shijia/Public/testprogram/e_j1f.c_e.c:113:9");
  AssignF({(Addr)&z}, (Addr)&temp_var_for_tac_22,
          "/home/shijia/Public/testprogram/e_j1f.c_e.c:113:5");
  ;
  float temp_var_for_tac_23, temp_var_for_tac_24, temp_var_for_tac_25,
      temp_var_for_tac_26, temp_var_for_tac_27, temp_var_for_tac_28,
      temp_var_for_tac_29;
  float temp_var_for_const_21, temp_var_for_const_22, temp_var_for_const_23,
      temp_var_for_const_24;
  temp_var_for_tac_23 = z * r03;

  temp_var_for_tac_24 = r02 + temp_var_for_tac_23;

  temp_var_for_tac_25 = z * temp_var_for_tac_24;

  temp_var_for_tac_26 = r01 + temp_var_for_tac_25;

  temp_var_for_tac_27 = z * temp_var_for_tac_26;

  temp_var_for_tac_28 = r00 + temp_var_for_tac_27;

  temp_var_for_tac_29 = z * temp_var_for_tac_28;

  r = temp_var_for_tac_29;
  computeFMul((Addr)&temp_var_for_tac_23,
              {(Addr)&z, (Addr) &(temp_var_for_const_21 = r03)},
              "/home/shijia/Public/testprogram/e_j1f.c_e.c:114:42");
  computeFAdd(
      (Addr)&temp_var_for_tac_24,
      {(Addr) &(temp_var_for_const_22 = r02), (Addr)&temp_var_for_tac_23},
      "/home/shijia/Public/testprogram/e_j1f.c_e.c:114:38");
  computeFMul((Addr)&temp_var_for_tac_25,
              {(Addr)&z, (Addr)&temp_var_for_tac_24},
              "/home/shijia/Public/testprogram/e_j1f.c_e.c:114:31");
  computeFAdd(
      (Addr)&temp_var_for_tac_26,
      {(Addr) &(temp_var_for_const_23 = r01), (Addr)&temp_var_for_tac_25},
      "/home/shijia/Public/testprogram/e_j1f.c_e.c:114:27");
  computeFMul((Addr)&temp_var_for_tac_27,
              {(Addr)&z, (Addr)&temp_var_for_tac_26},
              "/home/shijia/Public/testprogram/e_j1f.c_e.c:114:20");
  computeFAdd(
      (Addr)&temp_var_for_tac_28,
      {(Addr) &(temp_var_for_const_24 = r00), (Addr)&temp_var_for_tac_27},
      "/home/shijia/Public/testprogram/e_j1f.c_e.c:114:16");
  computeFMul((Addr)&temp_var_for_tac_29,
              {(Addr)&z, (Addr)&temp_var_for_tac_28},
              "/home/shijia/Public/testprogram/e_j1f.c_e.c:114:9");
  AssignF({(Addr)&r}, (Addr)&temp_var_for_tac_29,
          "/home/shijia/Public/testprogram/e_j1f.c_e.c:114:5");
  ;
  float temp_var_for_tac_30, temp_var_for_tac_31, temp_var_for_tac_32,
      temp_var_for_tac_33, temp_var_for_tac_34, temp_var_for_tac_35,
      temp_var_for_tac_36, temp_var_for_tac_37, temp_var_for_tac_38,
      temp_var_for_tac_39;
  float temp_var_for_const_25, temp_var_for_const_26, temp_var_for_const_27,
      temp_var_for_const_28, temp_var_for_const_29, temp_var_for_const_30;
  temp_var_for_tac_30 = z * s05;

  temp_var_for_tac_31 = s04 + temp_var_for_tac_30;

  temp_var_for_tac_32 = z * temp_var_for_tac_31;

  temp_var_for_tac_33 = s03 + temp_var_for_tac_32;

  temp_var_for_tac_34 = z * temp_var_for_tac_33;

  temp_var_for_tac_35 = s02 + temp_var_for_tac_34;

  temp_var_for_tac_36 = z * temp_var_for_tac_35;

  temp_var_for_tac_37 = s01 + temp_var_for_tac_36;

  temp_var_for_tac_38 = z * temp_var_for_tac_37;

  temp_var_for_tac_39 = one + temp_var_for_tac_38;

  s = temp_var_for_tac_39;
  computeFMul((Addr)&temp_var_for_tac_30,
              {(Addr)&z, (Addr) &(temp_var_for_const_25 = s05)},
              "/home/shijia/Public/testprogram/e_j1f.c_e.c:115:59");
  computeFAdd(
      (Addr)&temp_var_for_tac_31,
      {(Addr) &(temp_var_for_const_26 = s04), (Addr)&temp_var_for_tac_30},
      "/home/shijia/Public/testprogram/e_j1f.c_e.c:115:55");
  computeFMul((Addr)&temp_var_for_tac_32,
              {(Addr)&z, (Addr)&temp_var_for_tac_31},
              "/home/shijia/Public/testprogram/e_j1f.c_e.c:115:48");
  computeFAdd(
      (Addr)&temp_var_for_tac_33,
      {(Addr) &(temp_var_for_const_27 = s03), (Addr)&temp_var_for_tac_32},
      "/home/shijia/Public/testprogram/e_j1f.c_e.c:115:44");
  computeFMul((Addr)&temp_var_for_tac_34,
              {(Addr)&z, (Addr)&temp_var_for_tac_33},
              "/home/shijia/Public/testprogram/e_j1f.c_e.c:115:37");
  computeFAdd(
      (Addr)&temp_var_for_tac_35,
      {(Addr) &(temp_var_for_const_28 = s02), (Addr)&temp_var_for_tac_34},
      "/home/shijia/Public/testprogram/e_j1f.c_e.c:115:33");
  computeFMul((Addr)&temp_var_for_tac_36,
              {(Addr)&z, (Addr)&temp_var_for_tac_35},
              "/home/shijia/Public/testprogram/e_j1f.c_e.c:115:26");
  computeFAdd(
      (Addr)&temp_var_for_tac_37,
      {(Addr) &(temp_var_for_const_29 = s01), (Addr)&temp_var_for_tac_36},
      "/home/shijia/Public/testprogram/e_j1f.c_e.c:115:22");
  computeFMul((Addr)&temp_var_for_tac_38,
              {(Addr)&z, (Addr)&temp_var_for_tac_37},
              "/home/shijia/Public/testprogram/e_j1f.c_e.c:115:15");
  computeFAdd(
      (Addr)&temp_var_for_tac_39,
      {(Addr) &(temp_var_for_const_30 = one), (Addr)&temp_var_for_tac_38},
      "/home/shijia/Public/testprogram/e_j1f.c_e.c:115:11");
  AssignF({(Addr)&s}, (Addr)&temp_var_for_tac_39,
          "/home/shijia/Public/testprogram/e_j1f.c_e.c:115:5");
  ;
  r *= x;
  ;
  float temp_var_for_ext_6;
  float temp_var_for_tac_41, temp_var_for_tac_42, temp_var_for_tac_43;
  float temp_var_for_const_31;
  temp_var_for_tac_41 = x * 0.5f;

  temp_var_for_tac_42 = r / s;

  temp_var_for_tac_43 = temp_var_for_tac_41 + temp_var_for_tac_42;

  temp_var_for_ext_6 = temp_var_for_tac_43;
  computeFMul((Addr)&temp_var_for_tac_41,
              {(Addr)&x, (Addr) &(temp_var_for_const_31 = 0.5f)},
              "/home/shijia/Public/testprogram/e_j1f.c_e.c:118:27");
  computeFDiv((Addr)&temp_var_for_tac_42, {(Addr)&r, (Addr)&s},
              "/home/shijia/Public/testprogram/e_j1f.c_e.c:118:38");
  computeFAdd((Addr)&temp_var_for_tac_43,
              {(Addr)&temp_var_for_tac_41, (Addr)&temp_var_for_tac_42},
              "/home/shijia/Public/testprogram/e_j1f.c_e.c:118:34");
  AssignF({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_43,
          "/home/shijia/Public/testprogram/e_j1f.c_e.c:118:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_6;
}

/* wrapper j1 */
float __j1f(float x) {
  if (isgreater(__ieee754_fabsf(x), X_TLOSS) && _LIB_VERSION != _IEEE_ &&
      _LIB_VERSION != _POSIX_)
  /* j1(|x|>X_TLOSS) */
  {
    float temp_var_for_ext_7;
    float temp_var_for_const_32;
    float temp_var_for_callexp_6;

    temp_var_for_callexp_6 =
        __kernel_standard_f(x, x, 0.0f, KMATHERRF_J1_TLOSS);
    temp_var_for_ext_7 = temp_var_for_callexp_6;
    AssignF({(Addr)&temp_var_for_ext_7},
            (Addr) &(temp_var_for_const_32 = temp_var_for_callexp_6),
            "/home/shijia/Public/testprogram/e_j1f.c_e.c:131:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_7;
  }

  float temp_var_for_ext_8;
  float temp_var_for_const_33;
  float temp_var_for_callexp_7;

  temp_var_for_callexp_7 = __ieee754_j1f(x);
  temp_var_for_ext_8 = temp_var_for_callexp_7;
  AssignF({(Addr)&temp_var_for_ext_8},
          (Addr) &(temp_var_for_const_33 = temp_var_for_callexp_7),
          "/home/shijia/Public/testprogram/e_j1f.c_e.c:138:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_8;
}

__typeof(__j1f) j1f __attribute__((weak, alias("__j1f")));
