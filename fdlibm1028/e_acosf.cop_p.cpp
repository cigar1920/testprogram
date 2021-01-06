#include "../ScDebug/scdebug.h"
/* e_acosf.c -- float version of e_acos.c.
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

#ifndef __have_fpu_acos

float __ieee754_acosf(float x) {
  float z, p, q, r, w, s, c, df;
  int32_t hx, ix;

  static const float one = 1.0000000000e+00;     /* 0x3F800000 */
  static const float pi = 3.1415925026e+00;      /* 0x40490fda */
  static const float pio2_hi = 1.5707962513e+00; /* 0x3fc90fda */
  static const float pio2_lo = 7.5497894159e-08; /* 0x33a22168 */
  static const float pS0 = 1.6666667163e-01;     /* 0x3e2aaaab */
  static const float pS1 = (double temp_var_for_tac_0;
                            double temp_var_for_const_0, temp_var_for_const_1;
                            temp_var_for_tac_0 = 0.0 - 3.2556581497e-01;

                            );               /* 0xbea6b090 */
  static const float pS2 = 2.0121252537e-01; /* 0x3e4e0aa8 */
  static const float pS3 = (double temp_var_for_tac_1;
                            double temp_var_for_const_2, temp_var_for_const_3;
                            temp_var_for_tac_1 = 0.0 - 4.0055535734e-02;

                            );               /* 0xbd241146 */
  static const float pS4 = 7.9153501429e-04; /* 0x3a4f7f04 */
  static const float pS5 = 3.4793309169e-05; /* 0x3811ef08 */
  static const float qS1 = (double temp_var_for_tac_2;
                            double temp_var_for_const_4, temp_var_for_const_5;
                            temp_var_for_tac_2 = 0.0 - 2.4033949375e+00;

                            );               /* 0xc019d139 */
  static const float qS2 = 2.0209457874e+00; /* 0x4001572d */
  static const float qS3 = (double temp_var_for_tac_3;
                            double temp_var_for_const_6, temp_var_for_const_7;
                            temp_var_for_tac_3 = 0.0 - 6.8828397989e-01;

                            );               /* 0xbf303361 */
  static const float qS4 = 7.7038154006e-02; /* 0x3d9dc62e */

  GET_FLOAT_WORD(hx, x);
  ix = hx & IC(0x7fffffff);
  if (ix == IC(0x3f800000)) { /* |x|==1 */
    if (hx > 0) {
      float temp_var_for_ext_0;
      float temp_var_for_const_8;
      temp_var_for_ext_0 = 0.0;
      computeDSub((Addr)&temp_var_for_tac_0,
                  {(Addr) &(temp_var_for_const_1 = 0.0),
                   (Addr) &(temp_var_for_const_0 = 3.2556581497e-01)},
                  "/home/shijia/Public/testprogram/e_acosf.c_e.c:31:33");
      computeDSub((Addr)&temp_var_for_tac_1,
                  {(Addr) &(temp_var_for_const_3 = 0.0),
                   (Addr) &(temp_var_for_const_2 = 4.0055535734e-02)},
                  "/home/shijia/Public/testprogram/e_acosf.c_e.c:33:33");
      computeDSub((Addr)&temp_var_for_tac_2,
                  {(Addr) &(temp_var_for_const_5 = 0.0),
                   (Addr) &(temp_var_for_const_4 = 2.4033949375e+00)},
                  "/home/shijia/Public/testprogram/e_acosf.c_e.c:36:33");
      computeDSub((Addr)&temp_var_for_tac_3,
                  {(Addr) &(temp_var_for_const_7 = 0.0),
                   (Addr) &(temp_var_for_const_6 = 6.8828397989e-01)},
                  "/home/shijia/Public/testprogram/e_acosf.c_e.c:38:33");
      AssignF({(Addr)&temp_var_for_ext_0}, (Addr) &(temp_var_for_const_8 = 0.0),
              "/home/shijia/Public/testprogram/e_acosf.c_e.c:46:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_0;
    }
    /* acos(1) = 0  */
    else {
      float temp_var_for_ext_1;
      float temp_var_for_tac_4, temp_var_for_tac_5;
      float temp_var_for_const_9, temp_var_for_const_10, temp_var_for_const_11;
      temp_var_for_tac_4 = 2.0f * pio2_lo;

      temp_var_for_tac_5 = pi + temp_var_for_tac_4;

      temp_var_for_ext_1 = temp_var_for_tac_5;
      computeFMul((Addr)&temp_var_for_tac_4,
                  {(Addr) &(temp_var_for_const_10 = 2.0f),
                   (Addr) &(temp_var_for_const_9 = pio2_lo)},
                  "/home/shijia/Public/testprogram/e_acosf.c_e.c:55:38");
      computeFAdd(
          (Addr)&temp_var_for_tac_5,
          {(Addr) &(temp_var_for_const_11 = pi), (Addr)&temp_var_for_tac_4},
          "/home/shijia/Public/testprogram/e_acosf.c_e.c:55:31");
      AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_5,
              "/home/shijia/Public/testprogram/e_acosf.c_e.c:55:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_1;
    }
    /* acos(-1)= pi */
  } else {
    if (ix > IC(0x3f800000)) { /* |x| >= 1 */
      float temp_var_for_ext_2;
      float temp_var_for_tac_6, temp_var_for_tac_7, temp_var_for_tac_8;
      temp_var_for_tac_6 = x - x;

      temp_var_for_tac_7 = x - x;

      temp_var_for_tac_8 = temp_var_for_tac_6 / temp_var_for_tac_7;

      temp_var_for_ext_2 = temp_var_for_tac_8;
      computeFSub((Addr)&temp_var_for_tac_6, {(Addr)&x, (Addr)&x},
                  "/home/shijia/Public/testprogram/e_acosf.c_e.c:65:31");
      computeFSub((Addr)&temp_var_for_tac_7, {(Addr)&x, (Addr)&x},
                  "/home/shijia/Public/testprogram/e_acosf.c_e.c:65:41");
      computeFDiv((Addr)&temp_var_for_tac_8,
                  {(Addr)&temp_var_for_tac_6, (Addr)&temp_var_for_tac_7},
                  "/home/shijia/Public/testprogram/e_acosf.c_e.c:65:36");
      AssignF({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_8,
              "/home/shijia/Public/testprogram/e_acosf.c_e.c:65:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_2; /* acos(|x|>1) is NaN */
    }
  }

  if (ix < IC(0x3f000000)) { /* |x| < 0.5 */
    if (ix <= IC(0x32800000)) {
      float temp_var_for_ext_3;
      float temp_var_for_tac_9;
      float temp_var_for_const_12, temp_var_for_const_13;
      temp_var_for_tac_9 = pio2_hi + pio2_lo;

      temp_var_for_ext_3 = temp_var_for_tac_9;
      computeFAdd((Addr)&temp_var_for_tac_9,
                  {(Addr) &(temp_var_for_const_13 = pio2_hi),
                   (Addr) &(temp_var_for_const_12 = pio2_lo)},
                  "/home/shijia/Public/testprogram/e_acosf.c_e.c:76:36");
      AssignF({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_9,
              "/home/shijia/Public/testprogram/e_acosf.c_e.c:76:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_3;
    }
    /*if|x|<=2**-26 */
    float temp_var_for_tac_10;
    temp_var_for_tac_10 = x * x;

    z = temp_var_for_tac_10;
    computeFMul((Addr)&temp_var_for_tac_10, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_acosf.c_e.c:83:11");
    AssignF({(Addr)&z}, (Addr)&temp_var_for_tac_10,
            "/home/shijia/Public/testprogram/e_acosf.c_e.c:83:7");
    ;
    float temp_var_for_tac_11, temp_var_for_tac_12, temp_var_for_tac_13,
        temp_var_for_tac_14, temp_var_for_tac_15, temp_var_for_tac_16,
        temp_var_for_tac_17, temp_var_for_tac_18, temp_var_for_tac_19,
        temp_var_for_tac_20, temp_var_for_tac_21;
    float temp_var_for_const_14, temp_var_for_const_15, temp_var_for_const_16,
        temp_var_for_const_17, temp_var_for_const_18, temp_var_for_const_19;
    temp_var_for_tac_11 = z * pS5;

    temp_var_for_tac_12 = pS4 + temp_var_for_tac_11;

    temp_var_for_tac_13 = z * temp_var_for_tac_12;

    temp_var_for_tac_14 = pS3 + temp_var_for_tac_13;

    temp_var_for_tac_15 = z * temp_var_for_tac_14;

    temp_var_for_tac_16 = pS2 + temp_var_for_tac_15;

    temp_var_for_tac_17 = z * temp_var_for_tac_16;

    temp_var_for_tac_18 = pS1 + temp_var_for_tac_17;

    temp_var_for_tac_19 = z * temp_var_for_tac_18;

    temp_var_for_tac_20 = pS0 + temp_var_for_tac_19;

    temp_var_for_tac_21 = z * temp_var_for_tac_20;

    p = temp_var_for_tac_21;
    computeFMul((Addr)&temp_var_for_tac_11,
                {(Addr)&z, (Addr) &(temp_var_for_const_14 = pS5)},
                "/home/shijia/Public/testprogram/e_acosf.c_e.c:84:66");
    computeFAdd(
        (Addr)&temp_var_for_tac_12,
        {(Addr) &(temp_var_for_const_15 = pS4), (Addr)&temp_var_for_tac_11},
        "/home/shijia/Public/testprogram/e_acosf.c_e.c:84:62");
    computeFMul((Addr)&temp_var_for_tac_13,
                {(Addr)&z, (Addr)&temp_var_for_tac_12},
                "/home/shijia/Public/testprogram/e_acosf.c_e.c:84:55");
    computeFAdd(
        (Addr)&temp_var_for_tac_14,
        {(Addr) &(temp_var_for_const_16 = pS3), (Addr)&temp_var_for_tac_13},
        "/home/shijia/Public/testprogram/e_acosf.c_e.c:84:51");
    computeFMul((Addr)&temp_var_for_tac_15,
                {(Addr)&z, (Addr)&temp_var_for_tac_14},
                "/home/shijia/Public/testprogram/e_acosf.c_e.c:84:44");
    computeFAdd(
        (Addr)&temp_var_for_tac_16,
        {(Addr) &(temp_var_for_const_17 = pS2), (Addr)&temp_var_for_tac_15},
        "/home/shijia/Public/testprogram/e_acosf.c_e.c:84:40");
    computeFMul((Addr)&temp_var_for_tac_17,
                {(Addr)&z, (Addr)&temp_var_for_tac_16},
                "/home/shijia/Public/testprogram/e_acosf.c_e.c:84:33");
    computeFAdd(
        (Addr)&temp_var_for_tac_18,
        {(Addr) &(temp_var_for_const_18 = pS1), (Addr)&temp_var_for_tac_17},
        "/home/shijia/Public/testprogram/e_acosf.c_e.c:84:29");
    computeFMul((Addr)&temp_var_for_tac_19,
                {(Addr)&z, (Addr)&temp_var_for_tac_18},
                "/home/shijia/Public/testprogram/e_acosf.c_e.c:84:22");
    computeFAdd(
        (Addr)&temp_var_for_tac_20,
        {(Addr) &(temp_var_for_const_19 = pS0), (Addr)&temp_var_for_tac_19},
        "/home/shijia/Public/testprogram/e_acosf.c_e.c:84:18");
    computeFMul((Addr)&temp_var_for_tac_21,
                {(Addr)&z, (Addr)&temp_var_for_tac_20},
                "/home/shijia/Public/testprogram/e_acosf.c_e.c:84:11");
    AssignF({(Addr)&p}, (Addr)&temp_var_for_tac_21,
            "/home/shijia/Public/testprogram/e_acosf.c_e.c:84:7");
    ;
    float temp_var_for_tac_22, temp_var_for_tac_23, temp_var_for_tac_24,
        temp_var_for_tac_25, temp_var_for_tac_26, temp_var_for_tac_27,
        temp_var_for_tac_28, temp_var_for_tac_29;
    float temp_var_for_const_20, temp_var_for_const_21, temp_var_for_const_22,
        temp_var_for_const_23, temp_var_for_const_24;
    temp_var_for_tac_22 = z * qS4;

    temp_var_for_tac_23 = qS3 + temp_var_for_tac_22;

    temp_var_for_tac_24 = z * temp_var_for_tac_23;

    temp_var_for_tac_25 = qS2 + temp_var_for_tac_24;

    temp_var_for_tac_26 = z * temp_var_for_tac_25;

    temp_var_for_tac_27 = qS1 + temp_var_for_tac_26;

    temp_var_for_tac_28 = z * temp_var_for_tac_27;

    temp_var_for_tac_29 = one + temp_var_for_tac_28;

    q = temp_var_for_tac_29;
    computeFMul((Addr)&temp_var_for_tac_22,
                {(Addr)&z, (Addr) &(temp_var_for_const_20 = qS4)},
                "/home/shijia/Public/testprogram/e_acosf.c_e.c:85:50");
    computeFAdd(
        (Addr)&temp_var_for_tac_23,
        {(Addr) &(temp_var_for_const_21 = qS3), (Addr)&temp_var_for_tac_22},
        "/home/shijia/Public/testprogram/e_acosf.c_e.c:85:46");
    computeFMul((Addr)&temp_var_for_tac_24,
                {(Addr)&z, (Addr)&temp_var_for_tac_23},
                "/home/shijia/Public/testprogram/e_acosf.c_e.c:85:39");
    computeFAdd(
        (Addr)&temp_var_for_tac_25,
        {(Addr) &(temp_var_for_const_22 = qS2), (Addr)&temp_var_for_tac_24},
        "/home/shijia/Public/testprogram/e_acosf.c_e.c:85:35");
    computeFMul((Addr)&temp_var_for_tac_26,
                {(Addr)&z, (Addr)&temp_var_for_tac_25},
                "/home/shijia/Public/testprogram/e_acosf.c_e.c:85:28");
    computeFAdd(
        (Addr)&temp_var_for_tac_27,
        {(Addr) &(temp_var_for_const_23 = qS1), (Addr)&temp_var_for_tac_26},
        "/home/shijia/Public/testprogram/e_acosf.c_e.c:85:24");
    computeFMul((Addr)&temp_var_for_tac_28,
                {(Addr)&z, (Addr)&temp_var_for_tac_27},
                "/home/shijia/Public/testprogram/e_acosf.c_e.c:85:17");
    computeFAdd(
        (Addr)&temp_var_for_tac_29,
        {(Addr) &(temp_var_for_const_24 = one), (Addr)&temp_var_for_tac_28},
        "/home/shijia/Public/testprogram/e_acosf.c_e.c:85:13");
    AssignF({(Addr)&q}, (Addr)&temp_var_for_tac_29,
            "/home/shijia/Public/testprogram/e_acosf.c_e.c:85:7");
    ;
    float temp_var_for_tac_30;
    temp_var_for_tac_30 = p / q;

    r = temp_var_for_tac_30;
    computeFDiv((Addr)&temp_var_for_tac_30, {(Addr)&p, (Addr)&q},
                "/home/shijia/Public/testprogram/e_acosf.c_e.c:86:11");
    AssignF({(Addr)&r}, (Addr)&temp_var_for_tac_30,
            "/home/shijia/Public/testprogram/e_acosf.c_e.c:86:7");
    ;
    float temp_var_for_ext_4;
    float temp_var_for_tac_31, temp_var_for_tac_32, temp_var_for_tac_33,
        temp_var_for_tac_34;
    float temp_var_for_const_25, temp_var_for_const_26;
    temp_var_for_tac_31 = x * r;

    temp_var_for_tac_32 = pio2_lo - temp_var_for_tac_31;

    temp_var_for_tac_33 = x - temp_var_for_tac_32;

    temp_var_for_tac_34 = pio2_hi - temp_var_for_tac_33;

    temp_var_for_ext_4 = temp_var_for_tac_34;
    computeFMul((Addr)&temp_var_for_tac_31, {(Addr)&x, (Addr)&r},
                "/home/shijia/Public/testprogram/e_acosf.c_e.c:88:54");
    computeFSub(
        (Addr)&temp_var_for_tac_32,
        {(Addr) &(temp_var_for_const_25 = pio2_lo), (Addr)&temp_var_for_tac_31},
        "/home/shijia/Public/testprogram/e_acosf.c_e.c:88:50");
    computeFSub((Addr)&temp_var_for_tac_33,
                {(Addr)&x, (Addr)&temp_var_for_tac_32},
                "/home/shijia/Public/testprogram/e_acosf.c_e.c:88:39");
    computeFSub(
        (Addr)&temp_var_for_tac_34,
        {(Addr) &(temp_var_for_const_26 = pio2_hi), (Addr)&temp_var_for_tac_33},
        "/home/shijia/Public/testprogram/e_acosf.c_e.c:88:34");
    AssignF({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_34,
            "/home/shijia/Public/testprogram/e_acosf.c_e.c:88:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_4;
  } else {
    if (hx < 0) { /* x < -0.5 */
      float temp_var_for_tac_35, temp_var_for_tac_36;
      float temp_var_for_const_27, temp_var_for_const_28;
      temp_var_for_tac_35 = one + x;

      temp_var_for_tac_36 = temp_var_for_tac_35 * 0.5f;

      z = temp_var_for_tac_36;
      computeFAdd((Addr)&temp_var_for_tac_35,
                  {(Addr) &(temp_var_for_const_27 = one), (Addr)&x},
                  "/home/shijia/Public/testprogram/e_acosf.c_e.c:94:16");
      computeFMul(
          (Addr)&temp_var_for_tac_36,
          {(Addr)&temp_var_for_tac_35, (Addr) &(temp_var_for_const_28 = 0.5f)},
          "/home/shijia/Public/testprogram/e_acosf.c_e.c:94:21");
      AssignF({(Addr)&z}, (Addr)&temp_var_for_tac_36,
              "/home/shijia/Public/testprogram/e_acosf.c_e.c:94:9");
      ;
      float temp_var_for_tac_37, temp_var_for_tac_38, temp_var_for_tac_39,
          temp_var_for_tac_40, temp_var_for_tac_41, temp_var_for_tac_42,
          temp_var_for_tac_43, temp_var_for_tac_44, temp_var_for_tac_45,
          temp_var_for_tac_46, temp_var_for_tac_47;
      float temp_var_for_const_29, temp_var_for_const_30, temp_var_for_const_31,
          temp_var_for_const_32, temp_var_for_const_33, temp_var_for_const_34;
      temp_var_for_tac_37 = z * pS5;

      temp_var_for_tac_38 = pS4 + temp_var_for_tac_37;

      temp_var_for_tac_39 = z * temp_var_for_tac_38;

      temp_var_for_tac_40 = pS3 + temp_var_for_tac_39;

      temp_var_for_tac_41 = z * temp_var_for_tac_40;

      temp_var_for_tac_42 = pS2 + temp_var_for_tac_41;

      temp_var_for_tac_43 = z * temp_var_for_tac_42;

      temp_var_for_tac_44 = pS1 + temp_var_for_tac_43;

      temp_var_for_tac_45 = z * temp_var_for_tac_44;

      temp_var_for_tac_46 = pS0 + temp_var_for_tac_45;

      temp_var_for_tac_47 = z * temp_var_for_tac_46;

      p = temp_var_for_tac_47;
      computeFMul((Addr)&temp_var_for_tac_37,
                  {(Addr)&z, (Addr) &(temp_var_for_const_29 = pS5)},
                  "/home/shijia/Public/testprogram/e_acosf.c_e.c:95:68");
      computeFAdd(
          (Addr)&temp_var_for_tac_38,
          {(Addr) &(temp_var_for_const_30 = pS4), (Addr)&temp_var_for_tac_37},
          "/home/shijia/Public/testprogram/e_acosf.c_e.c:95:64");
      computeFMul((Addr)&temp_var_for_tac_39,
                  {(Addr)&z, (Addr)&temp_var_for_tac_38},
                  "/home/shijia/Public/testprogram/e_acosf.c_e.c:95:57");
      computeFAdd(
          (Addr)&temp_var_for_tac_40,
          {(Addr) &(temp_var_for_const_31 = pS3), (Addr)&temp_var_for_tac_39},
          "/home/shijia/Public/testprogram/e_acosf.c_e.c:95:53");
      computeFMul((Addr)&temp_var_for_tac_41,
                  {(Addr)&z, (Addr)&temp_var_for_tac_40},
                  "/home/shijia/Public/testprogram/e_acosf.c_e.c:95:46");
      computeFAdd(
          (Addr)&temp_var_for_tac_42,
          {(Addr) &(temp_var_for_const_32 = pS2), (Addr)&temp_var_for_tac_41},
          "/home/shijia/Public/testprogram/e_acosf.c_e.c:95:42");
      computeFMul((Addr)&temp_var_for_tac_43,
                  {(Addr)&z, (Addr)&temp_var_for_tac_42},
                  "/home/shijia/Public/testprogram/e_acosf.c_e.c:95:35");
      computeFAdd(
          (Addr)&temp_var_for_tac_44,
          {(Addr) &(temp_var_for_const_33 = pS1), (Addr)&temp_var_for_tac_43},
          "/home/shijia/Public/testprogram/e_acosf.c_e.c:95:31");
      computeFMul((Addr)&temp_var_for_tac_45,
                  {(Addr)&z, (Addr)&temp_var_for_tac_44},
                  "/home/shijia/Public/testprogram/e_acosf.c_e.c:95:24");
      computeFAdd(
          (Addr)&temp_var_for_tac_46,
          {(Addr) &(temp_var_for_const_34 = pS0), (Addr)&temp_var_for_tac_45},
          "/home/shijia/Public/testprogram/e_acosf.c_e.c:95:20");
      computeFMul((Addr)&temp_var_for_tac_47,
                  {(Addr)&z, (Addr)&temp_var_for_tac_46},
                  "/home/shijia/Public/testprogram/e_acosf.c_e.c:95:13");
      AssignF({(Addr)&p}, (Addr)&temp_var_for_tac_47,
              "/home/shijia/Public/testprogram/e_acosf.c_e.c:95:9");
      ;
      float temp_var_for_tac_48, temp_var_for_tac_49, temp_var_for_tac_50,
          temp_var_for_tac_51, temp_var_for_tac_52, temp_var_for_tac_53,
          temp_var_for_tac_54, temp_var_for_tac_55;
      float temp_var_for_const_35, temp_var_for_const_36, temp_var_for_const_37,
          temp_var_for_const_38, temp_var_for_const_39;
      temp_var_for_tac_48 = z * qS4;

      temp_var_for_tac_49 = qS3 + temp_var_for_tac_48;

      temp_var_for_tac_50 = z * temp_var_for_tac_49;

      temp_var_for_tac_51 = qS2 + temp_var_for_tac_50;

      temp_var_for_tac_52 = z * temp_var_for_tac_51;

      temp_var_for_tac_53 = qS1 + temp_var_for_tac_52;

      temp_var_for_tac_54 = z * temp_var_for_tac_53;

      temp_var_for_tac_55 = one + temp_var_for_tac_54;

      q = temp_var_for_tac_55;
      computeFMul((Addr)&temp_var_for_tac_48,
                  {(Addr)&z, (Addr) &(temp_var_for_const_35 = qS4)},
                  "/home/shijia/Public/testprogram/e_acosf.c_e.c:96:52");
      computeFAdd(
          (Addr)&temp_var_for_tac_49,
          {(Addr) &(temp_var_for_const_36 = qS3), (Addr)&temp_var_for_tac_48},
          "/home/shijia/Public/testprogram/e_acosf.c_e.c:96:48");
      computeFMul((Addr)&temp_var_for_tac_50,
                  {(Addr)&z, (Addr)&temp_var_for_tac_49},
                  "/home/shijia/Public/testprogram/e_acosf.c_e.c:96:41");
      computeFAdd(
          (Addr)&temp_var_for_tac_51,
          {(Addr) &(temp_var_for_const_37 = qS2), (Addr)&temp_var_for_tac_50},
          "/home/shijia/Public/testprogram/e_acosf.c_e.c:96:37");
      computeFMul((Addr)&temp_var_for_tac_52,
                  {(Addr)&z, (Addr)&temp_var_for_tac_51},
                  "/home/shijia/Public/testprogram/e_acosf.c_e.c:96:30");
      computeFAdd(
          (Addr)&temp_var_for_tac_53,
          {(Addr) &(temp_var_for_const_38 = qS1), (Addr)&temp_var_for_tac_52},
          "/home/shijia/Public/testprogram/e_acosf.c_e.c:96:26");
      computeFMul((Addr)&temp_var_for_tac_54,
                  {(Addr)&z, (Addr)&temp_var_for_tac_53},
                  "/home/shijia/Public/testprogram/e_acosf.c_e.c:96:19");
      computeFAdd(
          (Addr)&temp_var_for_tac_55,
          {(Addr) &(temp_var_for_const_39 = one), (Addr)&temp_var_for_tac_54},
          "/home/shijia/Public/testprogram/e_acosf.c_e.c:96:15");
      AssignF({(Addr)&q}, (Addr)&temp_var_for_tac_55,
              "/home/shijia/Public/testprogram/e_acosf.c_e.c:96:9");
      ;
      float temp_var_for_const_40;
      float temp_var_for_callexp_0;

      temp_var_for_callexp_0 = __ieee754_sqrtf(z);
      s = temp_var_for_callexp_0;
      AssignF({(Addr)&s},
              (Addr) &(temp_var_for_const_40 = temp_var_for_callexp_0),
              "/home/shijia/Public/testprogram/e_acosf.c_e.c:97:9");
      ;
      float temp_var_for_tac_56;
      temp_var_for_tac_56 = p / q;

      r = temp_var_for_tac_56;
      computeFDiv((Addr)&temp_var_for_tac_56, {(Addr)&p, (Addr)&q},
                  "/home/shijia/Public/testprogram/e_acosf.c_e.c:98:13");
      AssignF({(Addr)&r}, (Addr)&temp_var_for_tac_56,
              "/home/shijia/Public/testprogram/e_acosf.c_e.c:98:9");
      ;
      float temp_var_for_tac_57, temp_var_for_tac_58;
      float temp_var_for_const_41;
      temp_var_for_tac_57 = r * s;

      temp_var_for_tac_58 = temp_var_for_tac_57 - pio2_lo;

      w = temp_var_for_tac_58;
      computeFMul((Addr)&temp_var_for_tac_57, {(Addr)&r, (Addr)&s},
                  "/home/shijia/Public/testprogram/e_acosf.c_e.c:99:13");
      computeFSub((Addr)&temp_var_for_tac_58,
                  {(Addr)&temp_var_for_tac_57,
                   (Addr) &(temp_var_for_const_41 = pio2_lo)},
                  "/home/shijia/Public/testprogram/e_acosf.c_e.c:99:17");
      AssignF({(Addr)&w}, (Addr)&temp_var_for_tac_58,
              "/home/shijia/Public/testprogram/e_acosf.c_e.c:99:9");
      ;
      float temp_var_for_ext_5;
      float temp_var_for_tac_59, temp_var_for_tac_60, temp_var_for_tac_61;
      float temp_var_for_const_42, temp_var_for_const_43;
      temp_var_for_tac_59 = s + w;

      temp_var_for_tac_60 = 2.0f * temp_var_for_tac_59;

      temp_var_for_tac_61 = pi - temp_var_for_tac_60;

      temp_var_for_ext_5 = temp_var_for_tac_61;
      computeFAdd((Addr)&temp_var_for_tac_59, {(Addr)&s, (Addr)&w},
                  "/home/shijia/Public/testprogram/e_acosf.c_e.c:101:43");
      computeFMul(
          (Addr)&temp_var_for_tac_60,
          {(Addr) &(temp_var_for_const_42 = 2.0f), (Addr)&temp_var_for_tac_59},
          "/home/shijia/Public/testprogram/e_acosf.c_e.c:101:38");
      computeFSub(
          (Addr)&temp_var_for_tac_61,
          {(Addr) &(temp_var_for_const_43 = pi), (Addr)&temp_var_for_tac_60},
          "/home/shijia/Public/testprogram/e_acosf.c_e.c:101:31");
      AssignF({(Addr)&temp_var_for_ext_5}, (Addr)&temp_var_for_tac_61,
              "/home/shijia/Public/testprogram/e_acosf.c_e.c:101:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_5;
    } else { /* x > 0.5 */
      int32_t idf;

      float temp_var_for_tac_62, temp_var_for_tac_63;
      float temp_var_for_const_44, temp_var_for_const_45;
      temp_var_for_tac_62 = one - x;

      temp_var_for_tac_63 = temp_var_for_tac_62 * 0.5f;

      z = temp_var_for_tac_63;
      computeFSub((Addr)&temp_var_for_tac_62,
                  {(Addr) &(temp_var_for_const_44 = one), (Addr)&x},
                  "/home/shijia/Public/testprogram/e_acosf.c_e.c:109:16");
      computeFMul(
          (Addr)&temp_var_for_tac_63,
          {(Addr)&temp_var_for_tac_62, (Addr) &(temp_var_for_const_45 = 0.5f)},
          "/home/shijia/Public/testprogram/e_acosf.c_e.c:109:21");
      AssignF({(Addr)&z}, (Addr)&temp_var_for_tac_63,
              "/home/shijia/Public/testprogram/e_acosf.c_e.c:109:9");
      ;
      float temp_var_for_const_46;
      float temp_var_for_callexp_1;

      temp_var_for_callexp_1 = __ieee754_sqrtf(z);
      s = temp_var_for_callexp_1;
      AssignF({(Addr)&s},
              (Addr) &(temp_var_for_const_46 = temp_var_for_callexp_1),
              "/home/shijia/Public/testprogram/e_acosf.c_e.c:110:9");
      ;
      df = s;
      AssignF({(Addr)&df}, (Addr)&s,
              "/home/shijia/Public/testprogram/e_acosf.c_e.c:111:10");
      ;
      GET_FLOAT_WORD(idf, df);
      SET_FLOAT_WORD(df, idf & IC(0xfffff000));
      float temp_var_for_tac_64, temp_var_for_tac_65, temp_var_for_tac_66,
          temp_var_for_tac_67;
      temp_var_for_tac_64 = df * df;

      temp_var_for_tac_65 = z - temp_var_for_tac_64;

      temp_var_for_tac_66 = s + df;

      temp_var_for_tac_67 = temp_var_for_tac_65 / temp_var_for_tac_66;

      c = temp_var_for_tac_67;
      computeFMul((Addr)&temp_var_for_tac_64, {(Addr)&df, (Addr)&df},
                  "/home/shijia/Public/testprogram/e_acosf.c_e.c:114:19");
      computeFSub((Addr)&temp_var_for_tac_65,
                  {(Addr)&z, (Addr)&temp_var_for_tac_64},
                  "/home/shijia/Public/testprogram/e_acosf.c_e.c:114:14");
      computeFAdd((Addr)&temp_var_for_tac_66, {(Addr)&s, (Addr)&df},
                  "/home/shijia/Public/testprogram/e_acosf.c_e.c:114:30");
      computeFDiv((Addr)&temp_var_for_tac_67,
                  {(Addr)&temp_var_for_tac_65, (Addr)&temp_var_for_tac_66},
                  "/home/shijia/Public/testprogram/e_acosf.c_e.c:114:25");
      AssignF({(Addr)&c}, (Addr)&temp_var_for_tac_67,
              "/home/shijia/Public/testprogram/e_acosf.c_e.c:114:9");
      ;
      float temp_var_for_tac_68, temp_var_for_tac_69, temp_var_for_tac_70,
          temp_var_for_tac_71, temp_var_for_tac_72, temp_var_for_tac_73,
          temp_var_for_tac_74, temp_var_for_tac_75, temp_var_for_tac_76,
          temp_var_for_tac_77, temp_var_for_tac_78;
      float temp_var_for_const_47, temp_var_for_const_48, temp_var_for_const_49,
          temp_var_for_const_50, temp_var_for_const_51, temp_var_for_const_52;
      temp_var_for_tac_68 = z * pS5;

      temp_var_for_tac_69 = pS4 + temp_var_for_tac_68;

      temp_var_for_tac_70 = z * temp_var_for_tac_69;

      temp_var_for_tac_71 = pS3 + temp_var_for_tac_70;

      temp_var_for_tac_72 = z * temp_var_for_tac_71;

      temp_var_for_tac_73 = pS2 + temp_var_for_tac_72;

      temp_var_for_tac_74 = z * temp_var_for_tac_73;

      temp_var_for_tac_75 = pS1 + temp_var_for_tac_74;

      temp_var_for_tac_76 = z * temp_var_for_tac_75;

      temp_var_for_tac_77 = pS0 + temp_var_for_tac_76;

      temp_var_for_tac_78 = z * temp_var_for_tac_77;

      p = temp_var_for_tac_78;
      computeFMul((Addr)&temp_var_for_tac_68,
                  {(Addr)&z, (Addr) &(temp_var_for_const_47 = pS5)},
                  "/home/shijia/Public/testprogram/e_acosf.c_e.c:115:68");
      computeFAdd(
          (Addr)&temp_var_for_tac_69,
          {(Addr) &(temp_var_for_const_48 = pS4), (Addr)&temp_var_for_tac_68},
          "/home/shijia/Public/testprogram/e_acosf.c_e.c:115:64");
      computeFMul((Addr)&temp_var_for_tac_70,
                  {(Addr)&z, (Addr)&temp_var_for_tac_69},
                  "/home/shijia/Public/testprogram/e_acosf.c_e.c:115:57");
      computeFAdd(
          (Addr)&temp_var_for_tac_71,
          {(Addr) &(temp_var_for_const_49 = pS3), (Addr)&temp_var_for_tac_70},
          "/home/shijia/Public/testprogram/e_acosf.c_e.c:115:53");
      computeFMul((Addr)&temp_var_for_tac_72,
                  {(Addr)&z, (Addr)&temp_var_for_tac_71},
                  "/home/shijia/Public/testprogram/e_acosf.c_e.c:115:46");
      computeFAdd(
          (Addr)&temp_var_for_tac_73,
          {(Addr) &(temp_var_for_const_50 = pS2), (Addr)&temp_var_for_tac_72},
          "/home/shijia/Public/testprogram/e_acosf.c_e.c:115:42");
      computeFMul((Addr)&temp_var_for_tac_74,
                  {(Addr)&z, (Addr)&temp_var_for_tac_73},
                  "/home/shijia/Public/testprogram/e_acosf.c_e.c:115:35");
      computeFAdd(
          (Addr)&temp_var_for_tac_75,
          {(Addr) &(temp_var_for_const_51 = pS1), (Addr)&temp_var_for_tac_74},
          "/home/shijia/Public/testprogram/e_acosf.c_e.c:115:31");
      computeFMul((Addr)&temp_var_for_tac_76,
                  {(Addr)&z, (Addr)&temp_var_for_tac_75},
                  "/home/shijia/Public/testprogram/e_acosf.c_e.c:115:24");
      computeFAdd(
          (Addr)&temp_var_for_tac_77,
          {(Addr) &(temp_var_for_const_52 = pS0), (Addr)&temp_var_for_tac_76},
          "/home/shijia/Public/testprogram/e_acosf.c_e.c:115:20");
      computeFMul((Addr)&temp_var_for_tac_78,
                  {(Addr)&z, (Addr)&temp_var_for_tac_77},
                  "/home/shijia/Public/testprogram/e_acosf.c_e.c:115:13");
      AssignF({(Addr)&p}, (Addr)&temp_var_for_tac_78,
              "/home/shijia/Public/testprogram/e_acosf.c_e.c:115:9");
      ;
      float temp_var_for_tac_79, temp_var_for_tac_80, temp_var_for_tac_81,
          temp_var_for_tac_82, temp_var_for_tac_83, temp_var_for_tac_84,
          temp_var_for_tac_85, temp_var_for_tac_86;
      float temp_var_for_const_53, temp_var_for_const_54, temp_var_for_const_55,
          temp_var_for_const_56, temp_var_for_const_57;
      temp_var_for_tac_79 = z * qS4;

      temp_var_for_tac_80 = qS3 + temp_var_for_tac_79;

      temp_var_for_tac_81 = z * temp_var_for_tac_80;

      temp_var_for_tac_82 = qS2 + temp_var_for_tac_81;

      temp_var_for_tac_83 = z * temp_var_for_tac_82;

      temp_var_for_tac_84 = qS1 + temp_var_for_tac_83;

      temp_var_for_tac_85 = z * temp_var_for_tac_84;

      temp_var_for_tac_86 = one + temp_var_for_tac_85;

      q = temp_var_for_tac_86;
      computeFMul((Addr)&temp_var_for_tac_79,
                  {(Addr)&z, (Addr) &(temp_var_for_const_53 = qS4)},
                  "/home/shijia/Public/testprogram/e_acosf.c_e.c:116:52");
      computeFAdd(
          (Addr)&temp_var_for_tac_80,
          {(Addr) &(temp_var_for_const_54 = qS3), (Addr)&temp_var_for_tac_79},
          "/home/shijia/Public/testprogram/e_acosf.c_e.c:116:48");
      computeFMul((Addr)&temp_var_for_tac_81,
                  {(Addr)&z, (Addr)&temp_var_for_tac_80},
                  "/home/shijia/Public/testprogram/e_acosf.c_e.c:116:41");
      computeFAdd(
          (Addr)&temp_var_for_tac_82,
          {(Addr) &(temp_var_for_const_55 = qS2), (Addr)&temp_var_for_tac_81},
          "/home/shijia/Public/testprogram/e_acosf.c_e.c:116:37");
      computeFMul((Addr)&temp_var_for_tac_83,
                  {(Addr)&z, (Addr)&temp_var_for_tac_82},
                  "/home/shijia/Public/testprogram/e_acosf.c_e.c:116:30");
      computeFAdd(
          (Addr)&temp_var_for_tac_84,
          {(Addr) &(temp_var_for_const_56 = qS1), (Addr)&temp_var_for_tac_83},
          "/home/shijia/Public/testprogram/e_acosf.c_e.c:116:26");
      computeFMul((Addr)&temp_var_for_tac_85,
                  {(Addr)&z, (Addr)&temp_var_for_tac_84},
                  "/home/shijia/Public/testprogram/e_acosf.c_e.c:116:19");
      computeFAdd(
          (Addr)&temp_var_for_tac_86,
          {(Addr) &(temp_var_for_const_57 = one), (Addr)&temp_var_for_tac_85},
          "/home/shijia/Public/testprogram/e_acosf.c_e.c:116:15");
      AssignF({(Addr)&q}, (Addr)&temp_var_for_tac_86,
              "/home/shijia/Public/testprogram/e_acosf.c_e.c:116:9");
      ;
      float temp_var_for_tac_87;
      temp_var_for_tac_87 = p / q;

      r = temp_var_for_tac_87;
      computeFDiv((Addr)&temp_var_for_tac_87, {(Addr)&p, (Addr)&q},
                  "/home/shijia/Public/testprogram/e_acosf.c_e.c:117:13");
      AssignF({(Addr)&r}, (Addr)&temp_var_for_tac_87,
              "/home/shijia/Public/testprogram/e_acosf.c_e.c:117:9");
      ;
      float temp_var_for_tac_88, temp_var_for_tac_89;
      temp_var_for_tac_88 = r * s;

      temp_var_for_tac_89 = temp_var_for_tac_88 + c;

      w = temp_var_for_tac_89;
      computeFMul((Addr)&temp_var_for_tac_88, {(Addr)&r, (Addr)&s},
                  "/home/shijia/Public/testprogram/e_acosf.c_e.c:118:13");
      computeFAdd((Addr)&temp_var_for_tac_89,
                  {(Addr)&temp_var_for_tac_88, (Addr)&c},
                  "/home/shijia/Public/testprogram/e_acosf.c_e.c:118:17");
      AssignF({(Addr)&w}, (Addr)&temp_var_for_tac_89,
              "/home/shijia/Public/testprogram/e_acosf.c_e.c:118:9");
      ;
      float temp_var_for_ext_6;
      float temp_var_for_tac_90, temp_var_for_tac_91;
      float temp_var_for_const_58;
      temp_var_for_tac_90 = df + w;

      temp_var_for_tac_91 = 2.0f * temp_var_for_tac_90;

      temp_var_for_ext_6 = temp_var_for_tac_91;
      computeFAdd((Addr)&temp_var_for_tac_90, {(Addr)&df, (Addr)&w},
                  "/home/shijia/Public/testprogram/e_acosf.c_e.c:120:39");
      computeFMul(
          (Addr)&temp_var_for_tac_91,
          {(Addr) &(temp_var_for_const_58 = 2.0f), (Addr)&temp_var_for_tac_90},
          "/home/shijia/Public/testprogram/e_acosf.c_e.c:120:33");
      AssignF({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_91,
              "/home/shijia/Public/testprogram/e_acosf.c_e.c:120:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_6;
    }
  }
}

#endif

/* wrapper acosf */
float __acosf(float x) {
  if (isgreater(__ieee754_fabsf(x), 1.0f) && _LIB_VERSION != _IEEE_) {
    /* acos(|x|>1) */
    feraiseexcept(FE_INVALID);
    float temp_var_for_ext_7;
    float temp_var_for_const_59;
    float temp_var_for_callexp_2;

    /*embed fun has found*/
    float temp_var_for_callexp_3;

    temp_var_for_callexp_2 = __builtin_nanf("");
    temp_var_for_callexp_3 =
        __kernel_standard_f(x, x, temp_var_for_callexp_2, KMATHERRF_ACOS);
    temp_var_for_ext_7 = temp_var_for_callexp_3;
    AssignF({(Addr)&temp_var_for_ext_7},
            (Addr) &(temp_var_for_const_59 = temp_var_for_callexp_3),
            "/home/shijia/Public/testprogram/e_acosf.c_e.c:137:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_7;
  }

  float temp_var_for_ext_8;
  float temp_var_for_const_60;
  float temp_var_for_callexp_4;

  temp_var_for_callexp_4 = __ieee754_acosf(x);
  temp_var_for_ext_8 = temp_var_for_callexp_4;
  AssignF({(Addr)&temp_var_for_ext_8},
          (Addr) &(temp_var_for_const_60 = temp_var_for_callexp_4),
          "/home/shijia/Public/testprogram/e_acosf.c_e.c:145:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_8;
}

__typeof(__acosf) acosf __attribute__((weak, alias("__acosf")));
