#include "../ScDebug/scdebug.h"
/* k_cosf.c -- float version of k_cos.c
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

float __kernel_cosf(float x, float y) {
  float a, hz, z, r, qx;
  int32_t ix;

  static const float one = 1.0000000000e+00; /* 0x3f800000 */
  static const float C1 = 4.1666667908e-02;  /* 0x3d2aaaab */
  static const float C2 = (double temp_var_for_tac_0;
                           double temp_var_for_const_0, temp_var_for_const_1;
                           temp_var_for_tac_0 = 0.0 - 1.3888889225e-03;

                           );               /* 0xbab60b61 */
  static const float C3 = 2.4801587642e-05; /* 0x37d00d01 */
  static const float C4 = (double temp_var_for_tac_1;
                           double temp_var_for_const_2, temp_var_for_const_3;
                           temp_var_for_tac_1 = 0.0 - 2.7557314297e-07;

                           );               /* 0xb493f27c */
  static const float C5 = 2.0875723372e-09; /* 0x310f74f6 */
  static const float C6 = (double temp_var_for_tac_2;
                           double temp_var_for_const_4, temp_var_for_const_5;
                           temp_var_for_tac_2 = 0.0 - 1.1359647598e-11;

                           ); /* 0xad47d74e */

  GET_FLOAT_WORD(ix, x);
  ix &= IC(0x7fffffff);      /* ix = |x|'s high word */
  if (ix < IC(0x32000000)) { /* if x < 2**27 */
    if (((int32_t)x) == 0) {
      float temp_var_for_ext_0;
      float temp_var_for_const_6;
      temp_var_for_ext_0 = one;
      computeDSub((Addr)&temp_var_for_tac_0,
                  {(Addr) &(temp_var_for_const_1 = 0.0),
                   (Addr) &(temp_var_for_const_0 = 1.3888889225e-03)},
                  "/home/shijia/Public/testprogram/k_cosf.c_e.c:26:32");
      computeDSub((Addr)&temp_var_for_tac_1,
                  {(Addr) &(temp_var_for_const_3 = 0.0),
                   (Addr) &(temp_var_for_const_2 = 2.7557314297e-07)},
                  "/home/shijia/Public/testprogram/k_cosf.c_e.c:28:32");
      computeDSub((Addr)&temp_var_for_tac_2,
                  {(Addr) &(temp_var_for_const_5 = 0.0),
                   (Addr) &(temp_var_for_const_4 = 1.1359647598e-11)},
                  "/home/shijia/Public/testprogram/k_cosf.c_e.c:30:32");
      AssignF({(Addr)&temp_var_for_ext_0}, (Addr) &(temp_var_for_const_6 = one),
              "/home/shijia/Public/testprogram/k_cosf.c_e.c:37:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_0;
    }
    /* generate inexact */
  }
  float temp_var_for_tac_3;
  temp_var_for_tac_3 = x * x;

  z = temp_var_for_tac_3;
  computeFMul((Addr)&temp_var_for_tac_3, {(Addr)&x, (Addr)&x},
              "/home/shijia/Public/testprogram/k_cosf.c_e.c:45:9");
  AssignF({(Addr)&z}, (Addr)&temp_var_for_tac_3,
          "/home/shijia/Public/testprogram/k_cosf.c_e.c:45:5");
  ;
  float temp_var_for_tac_4, temp_var_for_tac_5, temp_var_for_tac_6,
      temp_var_for_tac_7, temp_var_for_tac_8, temp_var_for_tac_9,
      temp_var_for_tac_10, temp_var_for_tac_11, temp_var_for_tac_12,
      temp_var_for_tac_13, temp_var_for_tac_14;
  float temp_var_for_const_7, temp_var_for_const_8, temp_var_for_const_9,
      temp_var_for_const_10, temp_var_for_const_11, temp_var_for_const_12;
  temp_var_for_tac_4 = z * C6;

  temp_var_for_tac_5 = C5 + temp_var_for_tac_4;

  temp_var_for_tac_6 = z * temp_var_for_tac_5;

  temp_var_for_tac_7 = C4 + temp_var_for_tac_6;

  temp_var_for_tac_8 = z * temp_var_for_tac_7;

  temp_var_for_tac_9 = C3 + temp_var_for_tac_8;

  temp_var_for_tac_10 = z * temp_var_for_tac_9;

  temp_var_for_tac_11 = C2 + temp_var_for_tac_10;

  temp_var_for_tac_12 = z * temp_var_for_tac_11;

  temp_var_for_tac_13 = C1 + temp_var_for_tac_12;

  temp_var_for_tac_14 = z * temp_var_for_tac_13;

  r = temp_var_for_tac_14;
  computeFMul((Addr)&temp_var_for_tac_4,
              {(Addr)&z, (Addr) &(temp_var_for_const_7 = C6)},
              "/home/shijia/Public/testprogram/k_cosf.c_e.c:46:59");
  computeFAdd((Addr)&temp_var_for_tac_5,
              {(Addr) &(temp_var_for_const_8 = C5), (Addr)&temp_var_for_tac_4},
              "/home/shijia/Public/testprogram/k_cosf.c_e.c:46:55");
  computeFMul((Addr)&temp_var_for_tac_6, {(Addr)&z, (Addr)&temp_var_for_tac_5},
              "/home/shijia/Public/testprogram/k_cosf.c_e.c:46:49");
  computeFAdd((Addr)&temp_var_for_tac_7,
              {(Addr) &(temp_var_for_const_9 = C4), (Addr)&temp_var_for_tac_6},
              "/home/shijia/Public/testprogram/k_cosf.c_e.c:46:45");
  computeFMul((Addr)&temp_var_for_tac_8, {(Addr)&z, (Addr)&temp_var_for_tac_7},
              "/home/shijia/Public/testprogram/k_cosf.c_e.c:46:39");
  computeFAdd((Addr)&temp_var_for_tac_9,
              {(Addr) &(temp_var_for_const_10 = C3), (Addr)&temp_var_for_tac_8},
              "/home/shijia/Public/testprogram/k_cosf.c_e.c:46:35");
  computeFMul((Addr)&temp_var_for_tac_10, {(Addr)&z, (Addr)&temp_var_for_tac_9},
              "/home/shijia/Public/testprogram/k_cosf.c_e.c:46:29");
  computeFAdd((Addr)&temp_var_for_tac_11, {(Addr) &(temp_var_for_const_11 = C2),
                                           (Addr)&temp_var_for_tac_10},
              "/home/shijia/Public/testprogram/k_cosf.c_e.c:46:25");
  computeFMul((Addr)&temp_var_for_tac_12,
              {(Addr)&z, (Addr)&temp_var_for_tac_11},
              "/home/shijia/Public/testprogram/k_cosf.c_e.c:46:19");
  computeFAdd((Addr)&temp_var_for_tac_13, {(Addr) &(temp_var_for_const_12 = C1),
                                           (Addr)&temp_var_for_tac_12},
              "/home/shijia/Public/testprogram/k_cosf.c_e.c:46:15");
  computeFMul((Addr)&temp_var_for_tac_14,
              {(Addr)&z, (Addr)&temp_var_for_tac_13},
              "/home/shijia/Public/testprogram/k_cosf.c_e.c:46:9");
  AssignF({(Addr)&r}, (Addr)&temp_var_for_tac_14,
          "/home/shijia/Public/testprogram/k_cosf.c_e.c:46:5");
  ;
  if (ix < IC(0x3e99999a)) /* if |x| < 0.3 */
  {
    float temp_var_for_ext_1;
    float temp_var_for_tac_15, temp_var_for_tac_16, temp_var_for_tac_17,
        temp_var_for_tac_18, temp_var_for_tac_19, temp_var_for_tac_20;
    float temp_var_for_const_13, temp_var_for_const_14;
    temp_var_for_tac_15 = 0.5f * z;

    temp_var_for_tac_16 = z * r;

    temp_var_for_tac_17 = x * y;

    temp_var_for_tac_18 = temp_var_for_tac_16 - temp_var_for_tac_17;

    temp_var_for_tac_19 = temp_var_for_tac_15 - temp_var_for_tac_18;

    temp_var_for_tac_20 = one - temp_var_for_tac_19;

    temp_var_for_ext_1 = temp_var_for_tac_20;
    computeFMul((Addr)&temp_var_for_tac_15,
                {(Addr) &(temp_var_for_const_13 = 0.5f), (Addr)&z},
                "/home/shijia/Public/testprogram/k_cosf.c_e.c:50:38");
    computeFMul((Addr)&temp_var_for_tac_16, {(Addr)&z, (Addr)&r},
                "/home/shijia/Public/testprogram/k_cosf.c_e.c:50:47");
    computeFMul((Addr)&temp_var_for_tac_17, {(Addr)&x, (Addr)&y},
                "/home/shijia/Public/testprogram/k_cosf.c_e.c:50:55");
    computeFSub((Addr)&temp_var_for_tac_18,
                {(Addr)&temp_var_for_tac_16, (Addr)&temp_var_for_tac_17},
                "/home/shijia/Public/testprogram/k_cosf.c_e.c:50:51");
    computeFSub((Addr)&temp_var_for_tac_19,
                {(Addr)&temp_var_for_tac_15, (Addr)&temp_var_for_tac_18},
                "/home/shijia/Public/testprogram/k_cosf.c_e.c:50:42");
    computeFSub(
        (Addr)&temp_var_for_tac_20,
        {(Addr) &(temp_var_for_const_14 = one), (Addr)&temp_var_for_tac_19},
        "/home/shijia/Public/testprogram/k_cosf.c_e.c:50:30");
    AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_20,
            "/home/shijia/Public/testprogram/k_cosf.c_e.c:50:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }

  else {
    if (ix > IC(0x3f480000)) { /* x > 0.78125 */
      float temp_var_for_const_15;
      qx = 0.28125f;
      AssignF({(Addr)&qx}, (Addr) &(temp_var_for_const_15 = 0.28125f),
              "/home/shijia/Public/testprogram/k_cosf.c_e.c:58:10");
      ;
    } else {
      SET_FLOAT_WORD(qx, ix - IC(0x01000000)); /* x/4 */
    }
    float temp_var_for_tac_21, temp_var_for_tac_22;
    float temp_var_for_const_16;
    temp_var_for_tac_21 = 0.5f * z;

    temp_var_for_tac_22 = temp_var_for_tac_21 - qx;

    hz = temp_var_for_tac_22;
    computeFMul((Addr)&temp_var_for_tac_21,
                {(Addr) &(temp_var_for_const_16 = 0.5f), (Addr)&z},
                "/home/shijia/Public/testprogram/k_cosf.c_e.c:62:15");
    computeFSub((Addr)&temp_var_for_tac_22,
                {(Addr)&temp_var_for_tac_21, (Addr)&qx},
                "/home/shijia/Public/testprogram/k_cosf.c_e.c:62:19");
    AssignF({(Addr)&hz}, (Addr)&temp_var_for_tac_22,
            "/home/shijia/Public/testprogram/k_cosf.c_e.c:62:8");
    ;

    float temp_var_for_tac_23;
    float temp_var_for_const_17;
    temp_var_for_tac_23 = one - qx;

    a = temp_var_for_tac_23;
    computeFSub((Addr)&temp_var_for_tac_23,
                {(Addr) &(temp_var_for_const_17 = one), (Addr)&qx},
                "/home/shijia/Public/testprogram/k_cosf.c_e.c:64:13");
    AssignF({(Addr)&a}, (Addr)&temp_var_for_tac_23,
            "/home/shijia/Public/testprogram/k_cosf.c_e.c:64:7");
    ;
    float temp_var_for_ext_2;
    float temp_var_for_tac_24, temp_var_for_tac_25, temp_var_for_tac_26,
        temp_var_for_tac_27, temp_var_for_tac_28;
    temp_var_for_tac_24 = z * r;

    temp_var_for_tac_25 = x * y;

    temp_var_for_tac_26 = temp_var_for_tac_24 - temp_var_for_tac_25;

    temp_var_for_tac_27 = hz - temp_var_for_tac_26;

    temp_var_for_tac_28 = a - temp_var_for_tac_27;

    temp_var_for_ext_2 = temp_var_for_tac_28;
    computeFMul((Addr)&temp_var_for_tac_24, {(Addr)&z, (Addr)&r},
                "/home/shijia/Public/testprogram/k_cosf.c_e.c:66:39");
    computeFMul((Addr)&temp_var_for_tac_25, {(Addr)&x, (Addr)&y},
                "/home/shijia/Public/testprogram/k_cosf.c_e.c:66:47");
    computeFSub((Addr)&temp_var_for_tac_26,
                {(Addr)&temp_var_for_tac_24, (Addr)&temp_var_for_tac_25},
                "/home/shijia/Public/testprogram/k_cosf.c_e.c:66:43");
    computeFSub((Addr)&temp_var_for_tac_27,
                {(Addr)&hz, (Addr)&temp_var_for_tac_26},
                "/home/shijia/Public/testprogram/k_cosf.c_e.c:66:34");
    computeFSub((Addr)&temp_var_for_tac_28,
                {(Addr)&a, (Addr)&temp_var_for_tac_27},
                "/home/shijia/Public/testprogram/k_cosf.c_e.c:66:28");
    AssignF({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_28,
            "/home/shijia/Public/testprogram/k_cosf.c_e.c:66:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  }
}
