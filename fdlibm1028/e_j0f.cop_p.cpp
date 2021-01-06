#include "../ScDebug/scdebug.h"
/* e_j0f.c -- float version of e_j0.c.
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

float __ieee754_j0f(float x) {
  float z, s, c, ss, cc, r, u, v;
  int32_t hx, ix;

  static const float hugeval = 1e30;
  static const float one = 1.0;
  static const float invsqrtpi = 5.6418961287e-01; /* 0x3f106ebb */
  static const float zero = 0.0;

  /* R0/S0 on [0, 2.00] */
  static const float R02 = 1.5625000000e-02; /* 0x3c800000 */
  static const float R03 = (double temp_var_for_tac_0;
                            double temp_var_for_const_0, temp_var_for_const_1;
                            temp_var_for_tac_0 = 0.0 - 1.8997929874e-04;

                            );               /* 0xb947352e */
  static const float R04 = 1.8295404516e-06; /* 0x35f58e88 */
  static const float R05 = (double temp_var_for_tac_1;
                            double temp_var_for_const_2, temp_var_for_const_3;
                            temp_var_for_tac_1 = 0.0 - 4.6183270541e-09;

                            );               /* 0xb19eaf3c */
  static const float S01 = 1.5619102865e-02; /* 0x3c7fe744 */
  static const float S02 = 1.1692678527e-04; /* 0x38f53697 */
  static const float S03 = 5.1354652442e-07; /* 0x3509daa6 */
  static const float S04 = 1.1661400734e-09; /* 0x30a045e8 */

  GET_FLOAT_WORD(hx, x);
  ix = hx & IC(0x7fffffff);
  if (!FLT_UWORD_IS_FINITE(ix)) {
    float temp_var_for_ext_0;
    float temp_var_for_tac_2, temp_var_for_tac_3;
    float temp_var_for_const_4;
    temp_var_for_tac_2 = x * x;

    temp_var_for_tac_3 = one / temp_var_for_tac_2;

    temp_var_for_ext_0 = temp_var_for_tac_3;
    computeDSub((Addr)&temp_var_for_tac_0,
                {(Addr) &(temp_var_for_const_1 = 0.0),
                 (Addr) &(temp_var_for_const_0 = 1.8997929874e-04)},
                "/home/shijia/Public/testprogram/e_j0f.c_e.c:31:33");
    computeDSub((Addr)&temp_var_for_tac_1,
                {(Addr) &(temp_var_for_const_3 = 0.0),
                 (Addr) &(temp_var_for_const_2 = 4.6183270541e-09)},
                "/home/shijia/Public/testprogram/e_j0f.c_e.c:33:33");
    computeFMul((Addr)&temp_var_for_tac_2, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_j0f.c_e.c:43:35");
    computeFDiv(
        (Addr)&temp_var_for_tac_3,
        {(Addr) &(temp_var_for_const_4 = one), (Addr)&temp_var_for_tac_2},
        "/home/shijia/Public/testprogram/e_j0f.c_e.c:43:30");
    AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_3,
            "/home/shijia/Public/testprogram/e_j0f.c_e.c:43:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  float temp_var_for_ext_1;
  float temp_var_for_const_5;
  float temp_var_for_callexp_0;

  temp_var_for_callexp_0 = fabsf(x);
  temp_var_for_ext_1 = temp_var_for_callexp_0;
  AssignF({(Addr)&temp_var_for_ext_1},
          (Addr) &(temp_var_for_const_5 = temp_var_for_callexp_0),
          "/home/shijia/Public/testprogram/e_j0f.c_e.c:50:22");
  ; // x
  /*(_)(_)(tem)(_)(_)(__ieee754_fabsf(x))*/
  x = temp_var_for_ext_1;
  AssignF({(Addr)&x}, (Addr)&temp_var_for_ext_1,
          "/home/shijia/Public/testprogram/e_j0f.c_e.c:52:5");
  ;
  if (ix >= IC(0x40000000)) { /* |x| >= 2.0 */
    __ieee754_sincosf(x, &s, &c);
    float temp_var_for_tac_4;
    temp_var_for_tac_4 = s - c;

    ss = temp_var_for_tac_4;
    computeFSub((Addr)&temp_var_for_tac_4, {(Addr)&s, (Addr)&c},
                "/home/shijia/Public/testprogram/e_j0f.c_e.c:55:12");
    AssignF({(Addr)&ss}, (Addr)&temp_var_for_tac_4,
            "/home/shijia/Public/testprogram/e_j0f.c_e.c:55:8");
    ;
    float temp_var_for_tac_5;
    temp_var_for_tac_5 = s + c;

    cc = temp_var_for_tac_5;
    computeFAdd((Addr)&temp_var_for_tac_5, {(Addr)&s, (Addr)&c},
                "/home/shijia/Public/testprogram/e_j0f.c_e.c:56:12");
    AssignF({(Addr)&cc}, (Addr)&temp_var_for_tac_5,
            "/home/shijia/Public/testprogram/e_j0f.c_e.c:56:8");
    ;
    if (ix <= FLT_UWORD_HALF_MAX) { /* make sure x+x not overflow */
      float temp_var_for_tac_6, temp_var_for_tac_7;
      float temp_var_for_const_6, temp_var_for_const_7;
      float temp_var_for_callexp_1;

      temp_var_for_tac_6 = x + x;

      temp_var_for_callexp_1 = __ieee754_cosf(temp_var_for_tac_6);
      temp_var_for_tac_7 = 0.0 - temp_var_for_callexp_1;

      z = temp_var_for_tac_7;
      computeFAdd((Addr)&temp_var_for_tac_6, {(Addr)&x, (Addr)&x},
                  "/home/shijia/Public/testprogram/e_j0f.c_e.c:58:35");
      computeDSub((Addr)&temp_var_for_tac_7,
                  {(Addr) &(temp_var_for_const_7 = 0.0),
                   (Addr) &(temp_var_for_const_6 = temp_var_for_callexp_1)},
                  "/home/shijia/Public/testprogram/e_j0f.c_e.c:58:16");
      AssignF({(Addr)&z}, (Addr)&temp_var_for_tac_7,
              "/home/shijia/Public/testprogram/e_j0f.c_e.c:58:9");
      ;
      if (int temp_var_for_tac_8, temp_var_for_tac_9; int temp_var_for_const_8;
          temp_var_for_tac_8 = s * c;

          temp_var_for_tac_9 = temp_var_for_tac_8 < zero;

          ) {
        float temp_var_for_tac_10;
        temp_var_for_tac_10 = z / ss;

        cc = temp_var_for_tac_10;
        computeFMul((Addr)&temp_var_for_tac_8, {(Addr)&s, (Addr)&c},
                    "/home/shijia/Public/testprogram/e_j0f.c_e.c:59:14");
        compute(
            (Addr)&temp_var_for_tac_9,
            {(Addr)&temp_var_for_tac_8, (Addr) &(temp_var_for_const_8 = zero)},
            "/home/shijia/Public/testprogram/e_j0f.c_e.c:59:19");
        computeFDiv((Addr)&temp_var_for_tac_10, {(Addr)&z, (Addr)&ss},
                    "/home/shijia/Public/testprogram/e_j0f.c_e.c:60:16");
        AssignF({(Addr)&cc}, (Addr)&temp_var_for_tac_10,
                "/home/shijia/Public/testprogram/e_j0f.c_e.c:60:12");
        ;
      }

      else {
        float temp_var_for_ext_2;
        float temp_var_for_tac_11;
        temp_var_for_tac_11 = z / cc;

        temp_var_for_ext_2 = temp_var_for_tac_11;
        computeFDiv((Addr)&temp_var_for_tac_11, {(Addr)&z, (Addr)&cc},
                    "/home/shijia/Public/testprogram/e_j0f.c_e.c:65:32");
        AssignF({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_11,
                "/home/shijia/Public/testprogram/e_j0f.c_e.c:65:28");
        ; // ss
        /*(ss)(z)(cc)(z)*/
        ss = temp_var_for_ext_2;
        AssignF({(Addr)&ss}, (Addr)&temp_var_for_ext_2,
                "/home/shijia/Public/testprogram/e_j0f.c_e.c:67:12");
        ;
      }
    }
    /*
     * j0(x) = 1/sqrt(pi) * (P(0,x)*cc - Q(0,x)*ss) / sqrt(x)
     * y0(x) = 1/sqrt(pi) * (P(0,x)*ss + Q(0,x)*cc) / sqrt(x)
     */
    if (ix > IC(0x48000000)) {
      float temp_var_for_ext_3;
      float temp_var_for_tac_12, temp_var_for_tac_13;
      float temp_var_for_const_9, temp_var_for_const_10;
      float temp_var_for_callexp_2;

      temp_var_for_tac_12 = invsqrtpi * cc;

      temp_var_for_callexp_2 = __ieee754_sqrtf(x);
      temp_var_for_tac_13 = temp_var_for_tac_12 / temp_var_for_callexp_2;

      temp_var_for_ext_3 = temp_var_for_tac_13;
      computeFMul((Addr)&temp_var_for_tac_12,
                  {(Addr) &(temp_var_for_const_9 = invsqrtpi), (Addr)&cc},
                  "/home/shijia/Public/testprogram/e_j0f.c_e.c:76:39");
      computeFDiv((Addr)&temp_var_for_tac_13,
                  {(Addr)&temp_var_for_tac_12,
                   (Addr) &(temp_var_for_const_10 = temp_var_for_callexp_2)},
                  "/home/shijia/Public/testprogram/e_j0f.c_e.c:76:45");
      AssignF({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_13,
              "/home/shijia/Public/testprogram/e_j0f.c_e.c:76:26");
      ; // z
      /*(cc)(z)(__ieee754_sqrtf(x))(cc)(invsqrtpi)*/
      z = temp_var_for_ext_3;
      AssignF({(Addr)&z}, (Addr)&temp_var_for_ext_3,
              "/home/shijia/Public/testprogram/e_j0f.c_e.c:78:9");
      ;
    }

    else {
      float temp_var_for_const_11;
      float temp_var_for_callexp_3;

      temp_var_for_callexp_3 = __j0_y0_pzerof(x);
      u = temp_var_for_callexp_3;
      AssignF({(Addr)&u},
              (Addr) &(temp_var_for_const_11 = temp_var_for_callexp_3),
              "/home/shijia/Public/testprogram/e_j0f.c_e.c:82:9");
      ;
      float temp_var_for_const_12;
      float temp_var_for_callexp_4;

      temp_var_for_callexp_4 = __j0_y0_qzerof(x);
      v = temp_var_for_callexp_4;
      AssignF({(Addr)&v},
              (Addr) &(temp_var_for_const_12 = temp_var_for_callexp_4),
              "/home/shijia/Public/testprogram/e_j0f.c_e.c:83:9");
      ;
      float temp_var_for_tac_14, temp_var_for_tac_15, temp_var_for_tac_16,
          temp_var_for_tac_17, temp_var_for_tac_18;
      float temp_var_for_const_13, temp_var_for_const_14;
      float temp_var_for_callexp_5;

      temp_var_for_tac_14 = u * cc;

      temp_var_for_tac_15 = v * ss;

      temp_var_for_tac_16 = temp_var_for_tac_14 - temp_var_for_tac_15;

      temp_var_for_tac_17 = invsqrtpi * temp_var_for_tac_16;

      temp_var_for_callexp_5 = __ieee754_sqrtf(x);
      temp_var_for_tac_18 = temp_var_for_tac_17 / temp_var_for_callexp_5;

      z = temp_var_for_tac_18;
      computeFMul((Addr)&temp_var_for_tac_14, {(Addr)&u, (Addr)&cc},
                  "/home/shijia/Public/testprogram/e_j0f.c_e.c:84:26");
      computeFMul((Addr)&temp_var_for_tac_15, {(Addr)&v, (Addr)&ss},
                  "/home/shijia/Public/testprogram/e_j0f.c_e.c:84:35");
      computeFSub((Addr)&temp_var_for_tac_16,
                  {(Addr)&temp_var_for_tac_14, (Addr)&temp_var_for_tac_15},
                  "/home/shijia/Public/testprogram/e_j0f.c_e.c:84:31");
      computeFMul((Addr)&temp_var_for_tac_17,
                  {(Addr) &(temp_var_for_const_13 = invsqrtpi),
                   (Addr)&temp_var_for_tac_16},
                  "/home/shijia/Public/testprogram/e_j0f.c_e.c:84:21");
      computeFDiv((Addr)&temp_var_for_tac_18,
                  {(Addr)&temp_var_for_tac_17,
                   (Addr) &(temp_var_for_const_14 = temp_var_for_callexp_5)},
                  "/home/shijia/Public/testprogram/e_j0f.c_e.c:84:41");
      AssignF({(Addr)&z}, (Addr)&temp_var_for_tac_18,
              "/home/shijia/Public/testprogram/e_j0f.c_e.c:84:9");
      ;
    }
    float temp_var_for_ext_4;
    temp_var_for_ext_4 = z;
    AssignF({(Addr)&temp_var_for_ext_4}, (Addr)&z,
            "/home/shijia/Public/testprogram/e_j0f.c_e.c:87:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_4;
  }
  if (ix < IC(0x39000000)) {      /* |x| < 2**-13 */
    math_force_eval(hugeval + x); /* raise inexact if x != 0 */
    if (ix < IC(0x32000000)) {
      float temp_var_for_ext_5;
      float temp_var_for_const_17;
      temp_var_for_ext_5 = one;
      computeFAdd((Addr)&temp_var_for_tac_19,
                  {(Addr) &(temp_var_for_const_15 = hugeval), (Addr)&x},
                  "/home/shijia/Public/testprogram/e_j0f.c_e.c:93:5 "
                  "<Spelling=/home/shijia/Public/testprogram/"
                  "e_j0f.c_e.c:93:29>");
      computeFAdd((Addr)&temp_var_for_tac_20,
                  {(Addr) &(temp_var_for_const_16 = hugeval), (Addr)&x},
                  "/home/shijia/Public/testprogram/e_j0f.c_e.c:93:5 "
                  "<Spelling=/home/shijia/Public/testprogram/"
                  "e_j0f.c_e.c:93:29>");
      AssignF({(Addr)&temp_var_for_ext_5},
              (Addr) &(temp_var_for_const_17 = one),
              "/home/shijia/Public/testprogram/e_j0f.c_e.c:96:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_5;
    }
    /* |x|<2**-27 */
    else {
      float temp_var_for_ext_6;
      float temp_var_for_tac_21, temp_var_for_tac_22, temp_var_for_tac_23;
      float temp_var_for_const_18, temp_var_for_const_19;
      temp_var_for_tac_21 = 0.25f * x;

      temp_var_for_tac_22 = temp_var_for_tac_21 * x;

      temp_var_for_tac_23 = one - temp_var_for_tac_22;

      temp_var_for_ext_6 = temp_var_for_tac_23;
      computeFMul((Addr)&temp_var_for_tac_21,
                  {(Addr) &(temp_var_for_const_18 = 0.25f), (Addr)&x},
                  "/home/shijia/Public/testprogram/e_j0f.c_e.c:105:40");
      computeFMul((Addr)&temp_var_for_tac_22,
                  {(Addr)&temp_var_for_tac_21, (Addr)&x},
                  "/home/shijia/Public/testprogram/e_j0f.c_e.c:105:44");
      computeFSub(
          (Addr)&temp_var_for_tac_23,
          {(Addr) &(temp_var_for_const_19 = one), (Addr)&temp_var_for_tac_22},
          "/home/shijia/Public/testprogram/e_j0f.c_e.c:105:32");
      AssignF({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_23,
              "/home/shijia/Public/testprogram/e_j0f.c_e.c:105:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_6;
    }
  }
  float temp_var_for_tac_24;
  temp_var_for_tac_24 = x * x;

  z = temp_var_for_tac_24;
  computeFMul((Addr)&temp_var_for_tac_24, {(Addr)&x, (Addr)&x},
              "/home/shijia/Public/testprogram/e_j0f.c_e.c:112:9");
  AssignF({(Addr)&z}, (Addr)&temp_var_for_tac_24,
          "/home/shijia/Public/testprogram/e_j0f.c_e.c:112:5");
  ;
  float temp_var_for_tac_25, temp_var_for_tac_26, temp_var_for_tac_27,
      temp_var_for_tac_28, temp_var_for_tac_29, temp_var_for_tac_30,
      temp_var_for_tac_31;
  float temp_var_for_const_20, temp_var_for_const_21, temp_var_for_const_22,
      temp_var_for_const_23;
  temp_var_for_tac_25 = z * R05;

  temp_var_for_tac_26 = R04 + temp_var_for_tac_25;

  temp_var_for_tac_27 = z * temp_var_for_tac_26;

  temp_var_for_tac_28 = R03 + temp_var_for_tac_27;

  temp_var_for_tac_29 = z * temp_var_for_tac_28;

  temp_var_for_tac_30 = R02 + temp_var_for_tac_29;

  temp_var_for_tac_31 = z * temp_var_for_tac_30;

  r = temp_var_for_tac_31;
  computeFMul((Addr)&temp_var_for_tac_25,
              {(Addr)&z, (Addr) &(temp_var_for_const_20 = R05)},
              "/home/shijia/Public/testprogram/e_j0f.c_e.c:113:42");
  computeFAdd(
      (Addr)&temp_var_for_tac_26,
      {(Addr) &(temp_var_for_const_21 = R04), (Addr)&temp_var_for_tac_25},
      "/home/shijia/Public/testprogram/e_j0f.c_e.c:113:38");
  computeFMul((Addr)&temp_var_for_tac_27,
              {(Addr)&z, (Addr)&temp_var_for_tac_26},
              "/home/shijia/Public/testprogram/e_j0f.c_e.c:113:31");
  computeFAdd(
      (Addr)&temp_var_for_tac_28,
      {(Addr) &(temp_var_for_const_22 = R03), (Addr)&temp_var_for_tac_27},
      "/home/shijia/Public/testprogram/e_j0f.c_e.c:113:27");
  computeFMul((Addr)&temp_var_for_tac_29,
              {(Addr)&z, (Addr)&temp_var_for_tac_28},
              "/home/shijia/Public/testprogram/e_j0f.c_e.c:113:20");
  computeFAdd(
      (Addr)&temp_var_for_tac_30,
      {(Addr) &(temp_var_for_const_23 = R02), (Addr)&temp_var_for_tac_29},
      "/home/shijia/Public/testprogram/e_j0f.c_e.c:113:16");
  computeFMul((Addr)&temp_var_for_tac_31,
              {(Addr)&z, (Addr)&temp_var_for_tac_30},
              "/home/shijia/Public/testprogram/e_j0f.c_e.c:113:9");
  AssignF({(Addr)&r}, (Addr)&temp_var_for_tac_31,
          "/home/shijia/Public/testprogram/e_j0f.c_e.c:113:5");
  ;
  float temp_var_for_tac_32, temp_var_for_tac_33, temp_var_for_tac_34,
      temp_var_for_tac_35, temp_var_for_tac_36, temp_var_for_tac_37,
      temp_var_for_tac_38, temp_var_for_tac_39;
  float temp_var_for_const_24, temp_var_for_const_25, temp_var_for_const_26,
      temp_var_for_const_27, temp_var_for_const_28;
  temp_var_for_tac_32 = z * S04;

  temp_var_for_tac_33 = S03 + temp_var_for_tac_32;

  temp_var_for_tac_34 = z * temp_var_for_tac_33;

  temp_var_for_tac_35 = S02 + temp_var_for_tac_34;

  temp_var_for_tac_36 = z * temp_var_for_tac_35;

  temp_var_for_tac_37 = S01 + temp_var_for_tac_36;

  temp_var_for_tac_38 = z * temp_var_for_tac_37;

  temp_var_for_tac_39 = one + temp_var_for_tac_38;

  s = temp_var_for_tac_39;
  computeFMul((Addr)&temp_var_for_tac_32,
              {(Addr)&z, (Addr) &(temp_var_for_const_24 = S04)},
              "/home/shijia/Public/testprogram/e_j0f.c_e.c:114:48");
  computeFAdd(
      (Addr)&temp_var_for_tac_33,
      {(Addr) &(temp_var_for_const_25 = S03), (Addr)&temp_var_for_tac_32},
      "/home/shijia/Public/testprogram/e_j0f.c_e.c:114:44");
  computeFMul((Addr)&temp_var_for_tac_34,
              {(Addr)&z, (Addr)&temp_var_for_tac_33},
              "/home/shijia/Public/testprogram/e_j0f.c_e.c:114:37");
  computeFAdd(
      (Addr)&temp_var_for_tac_35,
      {(Addr) &(temp_var_for_const_26 = S02), (Addr)&temp_var_for_tac_34},
      "/home/shijia/Public/testprogram/e_j0f.c_e.c:114:33");
  computeFMul((Addr)&temp_var_for_tac_36,
              {(Addr)&z, (Addr)&temp_var_for_tac_35},
              "/home/shijia/Public/testprogram/e_j0f.c_e.c:114:26");
  computeFAdd(
      (Addr)&temp_var_for_tac_37,
      {(Addr) &(temp_var_for_const_27 = S01), (Addr)&temp_var_for_tac_36},
      "/home/shijia/Public/testprogram/e_j0f.c_e.c:114:22");
  computeFMul((Addr)&temp_var_for_tac_38,
              {(Addr)&z, (Addr)&temp_var_for_tac_37},
              "/home/shijia/Public/testprogram/e_j0f.c_e.c:114:15");
  computeFAdd(
      (Addr)&temp_var_for_tac_39,
      {(Addr) &(temp_var_for_const_28 = one), (Addr)&temp_var_for_tac_38},
      "/home/shijia/Public/testprogram/e_j0f.c_e.c:114:11");
  AssignF({(Addr)&s}, (Addr)&temp_var_for_tac_39,
          "/home/shijia/Public/testprogram/e_j0f.c_e.c:114:5");
  ;
  if (ix < IC(0x3F800000)) { /* |x| < 1.00 */
    float temp_var_for_ext_7;
    float temp_var_for_tac_40, temp_var_for_tac_41, temp_var_for_tac_42,
        temp_var_for_tac_43;
    float temp_var_for_const_29, temp_var_for_const_30;
    temp_var_for_tac_40 = r / s;

    temp_var_for_tac_41 = (-(0.25f)) + temp_var_for_tac_40;

    temp_var_for_tac_42 = z * temp_var_for_tac_41;

    temp_var_for_tac_43 = one + temp_var_for_tac_42;

    temp_var_for_ext_7 = temp_var_for_tac_43;
    computeFDiv((Addr)&temp_var_for_tac_40, {(Addr)&r, (Addr)&s},
                "/home/shijia/Public/testprogram/e_j0f.c_e.c:117:49");
    computeFAdd((Addr)&temp_var_for_tac_41,
                {(Addr) &(temp_var_for_const_29 = (-(0.25f))),
                 (Addr)&temp_var_for_tac_40},
                "/home/shijia/Public/testprogram/e_j0f.c_e.c:117:44");
    computeFMul((Addr)&temp_var_for_tac_42,
                {(Addr)&z, (Addr)&temp_var_for_tac_41},
                "/home/shijia/Public/testprogram/e_j0f.c_e.c:117:34");
    computeFAdd(
        (Addr)&temp_var_for_tac_43,
        {(Addr) &(temp_var_for_const_30 = one), (Addr)&temp_var_for_tac_42},
        "/home/shijia/Public/testprogram/e_j0f.c_e.c:117:30");
    AssignF({(Addr)&temp_var_for_ext_7}, (Addr)&temp_var_for_tac_43,
            "/home/shijia/Public/testprogram/e_j0f.c_e.c:117:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
    callExp++; /*identify the function is  add move tmpShadow*/
    return t(0.0 - mp_va) r_for_ext_7;
  } else {
    float temp_var_for_ext_8;
    float temp_var_for_tac_44;
    float temp_var_for_const_31;
    temp_var_for_tac_44 = 0.5f * x;

    temp_var_for_ext_8 = temp_var_for_tac_44;
    computeFMul((Addr)&temp_var_for_tac_44,
                {(Addr) &(temp_var_for_const_31 = 0.5f), (Addr)&x},
                "/home/shijia/Public/testprogram/e_j0f.c_e.c:123:31");
    AssignF({(Addr)&temp_var_for_ext_8}, (Addr)&temp_var_for_tac_44,
            "/home/shijia/Public/testprogram/e_j0f.c_e.c:123:24");
    ; // u
    /*(S04)(z)(S03)(z)(S02)(z)(S01)(z)(one)(S04)(z)(S03)(z)(S02)(z)(S01)(z)(S04)(z)(S03)(z)(S02)(z)(S01)(S04)(z)(S03)(z)(S02)(z)(S04)(z)(S03)(z)(S02)(S04)(z)(S03)(z)(S04)(z)(S03)(S04)(z)(t)(r)(mp_va)(mp_va)(u)(tem)(t)(r)(mp_va)(mp_va)(u)(t)(r)(mp_va)(mp_va)(t)(r)(x)(0.5f)*/
    u = temp_var_for_ext_8;
    AssignF({(Addr)&u}, (Addr)&temp_var_for_ext_8,
            "/home/shijia/Public/testprogram/e_j0f.c_e.c:125:7");
    ;

    float temp_var_for_ext_9;
    float temp_var_for_tac_45, temp_var_for_tac_46, temp_var_for_tac_47,
        temp_var_for_tac_48, temp_var_for_tac_49, temp_var_for_tac_50;
    float temp_var_for_const_32, temp_var_for_const_33;
    temp_var_for_tac_45 = one + u;

    temp_var_for_tac_46 = one - u;

    temp_var_for_tac_47 = temp_var_for_tac_45 * temp_var_for_tac_46;

    temp_var_for_tac_48 = r / s;

    temp_var_for_tac_49 = z * temp_var_for_tac_48;

    temp_var_for_tac_50 = temp_var_for_tac_47 + temp_var_for_tac_49;

    temp_var_for_ext_9 = temp_var_for_tac_50;
    computeFAdd((Addr)&temp_var_for_tac_45,
                {(Addr) &(temp_var_for_const_32 = one), (Addr)&u},
                "/home/shijia/Public/testprogram/e_j0f.c_e.c:128:32");
    computeFSub((Addr)&temp_var_for_tac_46,
                {(Addr) &(temp_var_for_const_33 = one), (Addr)&u},
                "/home/shijia/Public/testprogram/e_j0f.c_e.c:128:44");
    computeFMul((Addr)&temp_var_for_tac_47,
                {(Addr)&temp_var_for_tac_45, (Addr)&temp_var_for_tac_46},
                "/home/shijia/Public/testprogram/e_j0f.c_e.c:128:37");
    computeFDiv((Addr)&temp_var_for_tac_48, {(Addr)&r, (Addr)&s},
                "/home/shijia/Public/testprogram/e_j0f.c_e.c:128:58");
    computeFMul((Addr)&temp_var_for_tac_49,
                {(Addr)&z, (Addr)&temp_var_for_tac_48},
                "/home/shijia/Public/testprogram/e_j0f.c_e.c:128:53");
    computeFAdd((Addr)&temp_var_for_tac_50,
                {(Addr)&temp_var_for_tac_47, (Addr)&temp_var_for_tac_49},
                "/home/shijia/Public/testprogram/e_j0f.c_e.c:128:49");
    AssignF({(Addr)&temp_var_for_ext_9}, (Addr)&temp_var_for_tac_50,
            "/home/shijia/Public/testprogram/e_j0f.c_e.c:128:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_9;
  }
}

/* wrapper j0 */
float __j0f(float x) {
  if (isgreater(__ieee754_fabsf(x), X_TLOSS) && _LIB_VERSION != _IEEE_ &&
      _LIB_VERSION != _POSIX_)
  /* j0(|x|>X_TLOSS) */
  {
    float temp_var_for_ext_10;
    float temp_var_for_const_34;
    float temp_var_for_callexp_6;

    temp_var_for_callexp_6 =
        __kernel_standard_f(x, x, 0.0f, KMATHERRF_J0_TLOSS);
    temp_var_for_ext_10 = temp_var_for_callexp_6;
    AssignF({(Addr)&temp_var_for_ext_10},
            (Addr) &(temp_var_for_const_34 = temp_var_for_callexp_6),
            "/home/shijia/Public/testprogram/e_j0f.c_e.c:142:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_10", (Addr)&temp_var_for_ext_10));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_10;
  }

  float temp_var_for_ext_11;
  float temp_var_for_const_35;
  float temp_var_for_callexp_7;

  temp_var_for_callexp_7 = __ieee754_j0f(x);
  temp_var_for_ext_11 = temp_var_for_callexp_7;
  AssignF({(Addr)&temp_var_for_ext_11},
          (Addr) &(temp_var_for_const_35 = temp_var_for_callexp_7),
          "/home/shijia/Public/testprogram/e_j0f.c_e.c:150:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_11", (Addr)&temp_var_for_ext_11));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_11;
}

__typeof(__j0f) j0f __attribute__((weak, alias("__j0f")));
