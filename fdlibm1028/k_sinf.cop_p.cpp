#include "../ScDebug/scdebug.h"
/* k_sinf.c -- float version of k_sin.c
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

float __kernel_sinf(float x, float y, int iy) {
  float z, r, v;
  int32_t ix;

  static const float half = 5.0000000000e-01; /* 0x3f000000 */
  static const float S1 = (double temp_var_for_tac_0;
                           double temp_var_for_const_0, temp_var_for_const_1;
                           temp_var_for_tac_0 = 0.0 - 1.6666667163e-01;

                           );               /* 0xbe2aaaab */
  static const float S2 = 8.3333337680e-03; /* 0x3c088889 */
  static const float S3 = (double temp_var_for_tac_1;
                           double temp_var_for_const_2, temp_var_for_const_3;
                           temp_var_for_tac_1 = 0.0 - 1.9841270114e-04;

                           );               /* 0xb9500d01 */
  static const float S4 = 2.7557314297e-06; /* 0x3638ef1b */
  static const float S5 = (double temp_var_for_tac_2;
                           double temp_var_for_const_4, temp_var_for_const_5;
                           temp_var_for_tac_2 = 0.0 - 2.5050759689e-08;

                           );               /* 0xb2d72f34 */
  static const float S6 = 1.5896910177e-10; /* 0x2f2ec9d3 */

  GET_FLOAT_WORD(ix, x);
  ix &= IC(0x7fffffff);    /* high word of x */
  if (ix < IC(0x32000000)) /* |x| < 2**-27 */
  {
    if ((int32_t)x == 0) {
      float temp_var_for_ext_0;
      temp_var_for_ext_0 = x;
      computeDSub((Addr)&temp_var_for_tac_0,
                  {(Addr) &(temp_var_for_const_1 = 0.0),
                   (Addr) &(temp_var_for_const_0 = 1.6666667163e-01)},
                  "/home/shijia/Public/testprogram/k_sinf.c_e.c:25:32");
      computeDSub((Addr)&temp_var_for_tac_1,
                  {(Addr) &(temp_var_for_const_3 = 0.0),
                   (Addr) &(temp_var_for_const_2 = 1.9841270114e-04)},
                  "/home/shijia/Public/testprogram/k_sinf.c_e.c:27:32");
      computeDSub((Addr)&temp_var_for_tac_2,
                  {(Addr) &(temp_var_for_const_5 = 0.0),
                   (Addr) &(temp_var_for_const_4 = 2.5050759689e-08)},
                  "/home/shijia/Public/testprogram/k_sinf.c_e.c:29:32");
      AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&x,
              "/home/shijia/Public/testprogram/k_sinf.c_e.c:38:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_0;
    }

  } /* generate inexact */
  float temp_var_for_tac_3;
  temp_var_for_tac_3 = x * x;

  z = temp_var_for_tac_3;
  computeFMul((Addr)&temp_var_for_tac_3, {(Addr)&x, (Addr)&x},
              "/home/shijia/Public/testprogram/k_sinf.c_e.c:46:9");
  AssignF({(Addr)&z}, (Addr)&temp_var_for_tac_3,
          "/home/shijia/Public/testprogram/k_sinf.c_e.c:46:5");
  ;
  float temp_var_for_tac_4;
  temp_var_for_tac_4 = z * x;

  v = temp_var_for_tac_4;
  computeFMul((Addr)&temp_var_for_tac_4, {(Addr)&z, (Addr)&x},
              "/home/shijia/Public/testprogram/k_sinf.c_e.c:47:9");
  AssignF({(Addr)&v}, (Addr)&temp_var_for_tac_4,
          "/home/shijia/Public/testprogram/k_sinf.c_e.c:47:5");
  ;
  float temp_var_for_tac_5, temp_var_for_tac_6, temp_var_for_tac_7,
      temp_var_for_tac_8, temp_var_for_tac_9, temp_var_for_tac_10,
      temp_var_for_tac_11, temp_var_for_tac_12;
  float temp_var_for_const_6, temp_var_for_const_7, temp_var_for_const_8,
      temp_var_for_const_9, temp_var_for_const_10;
  temp_var_for_tac_5 = z * S6;

  temp_var_for_tac_6 = S5 + temp_var_for_tac_5;

  temp_var_for_tac_7 = z * temp_var_for_tac_6;

  temp_var_for_tac_8 = S4 + temp_var_for_tac_7;

  temp_var_for_tac_9 = z * temp_var_for_tac_8;

  temp_var_for_tac_10 = S3 + temp_var_for_tac_9;

  temp_var_for_tac_11 = z * temp_var_for_tac_10;

  temp_var_for_tac_12 = S2 + temp_var_for_tac_11;

  r = temp_var_for_tac_12;
  computeFMul((Addr)&temp_var_for_tac_5,
              {(Addr)&z, (Addr) &(temp_var_for_const_6 = S6)},
              "/home/shijia/Public/testprogram/k_sinf.c_e.c:48:44");
  computeFAdd((Addr)&temp_var_for_tac_6,
              {(Addr) &(temp_var_for_const_7 = S5), (Addr)&temp_var_for_tac_5},
              "/home/shijia/Public/testprogram/k_sinf.c_e.c:48:40");
  computeFMul((Addr)&temp_var_for_tac_7, {(Addr)&z, (Addr)&temp_var_for_tac_6},
              "/home/shijia/Public/testprogram/k_sinf.c_e.c:48:34");
  computeFAdd((Addr)&temp_var_for_tac_8,
              {(Addr) &(temp_var_for_const_8 = S4), (Addr)&temp_var_for_tac_7},
              "/home/shijia/Public/testprogram/k_sinf.c_e.c:48:30");
  computeFMul((Addr)&temp_var_for_tac_9, {(Addr)&z, (Addr)&temp_var_for_tac_8},
              "/home/shijia/Public/testprogram/k_sinf.c_e.c:48:24");
  computeFAdd((Addr)&temp_var_for_tac_10,
              {(Addr) &(temp_var_for_const_9 = S3), (Addr)&temp_var_for_tac_9},
              "/home/shijia/Public/testprogram/k_sinf.c_e.c:48:20");
  computeFMul((Addr)&temp_var_for_tac_11,
              {(Addr)&z, (Addr)&temp_var_for_tac_10},
              "/home/shijia/Public/testprogram/k_sinf.c_e.c:48:14");
  computeFAdd((Addr)&temp_var_for_tac_12, {(Addr) &(temp_var_for_const_10 = S2),
                                           (Addr)&temp_var_for_tac_11},
              "/home/shijia/Public/testprogram/k_sinf.c_e.c:48:10");
  AssignF({(Addr)&r}, (Addr)&temp_var_for_tac_12,
          "/home/shijia/Public/testprogram/k_sinf.c_e.c:48:5");
  ;
  if (iy == 0) {
    float temp_var_for_ext_1;
    float temp_var_for_tac_13, temp_var_for_tac_14, temp_var_for_tac_15,
        temp_var_for_tac_16;
    float temp_var_for_const_11;
    temp_var_for_tac_13 = z * r;

    temp_var_for_tac_14 = S1 + temp_var_for_tac_13;

    temp_var_for_tac_15 = v * temp_var_for_tac_14;

    temp_var_for_tac_16 = x + temp_var_for_tac_15;

    temp_var_for_ext_1 = temp_var_for_tac_16;
    computeFMul((Addr)&temp_var_for_tac_13, {(Addr)&z, (Addr)&r},
                "/home/shijia/Public/testprogram/k_sinf.c_e.c:51:42");
    computeFAdd(
        (Addr)&temp_var_for_tac_14,
        {(Addr) &(temp_var_for_const_11 = S1), (Addr)&temp_var_for_tac_13},
        "/home/shijia/Public/testprogram/k_sinf.c_e.c:51:38");
    computeFMul((Addr)&temp_var_for_tac_15,
                {(Addr)&v, (Addr)&temp_var_for_tac_14},
                "/home/shijia/Public/testprogram/k_sinf.c_e.c:51:32");
    computeFAdd((Addr)&temp_var_for_tac_16,
                {(Addr)&x, (Addr)&temp_var_for_tac_15},
                "/home/shijia/Public/testprogram/k_sinf.c_e.c:51:28");
    AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_16,
            "/home/shijia/Public/testprogram/k_sinf.c_e.c:51:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }

  else {
    float temp_var_for_ext_2;
    float temp_var_for_tac_17, temp_var_for_tac_18, temp_var_for_tac_19,
        temp_var_for_tac_20, temp_var_for_tac_21, temp_var_for_tac_22,
        temp_var_for_tac_23, temp_var_for_tac_24;
    float temp_var_for_const_12, temp_var_for_const_13;
    temp_var_for_tac_17 = half * y;

    temp_var_for_tac_18 = v * r;

    temp_var_for_tac_19 = temp_var_for_tac_17 - temp_var_for_tac_18;

    temp_var_for_tac_20 = z * temp_var_for_tac_19;

    temp_var_for_tac_21 = temp_var_for_tac_20 - y;

    temp_var_for_tac_22 = v * S1;

    temp_var_for_tac_23 = temp_var_for_tac_21 - temp_var_for_tac_22;

    temp_var_for_tac_24 = x - temp_var_for_tac_23;

    temp_var_for_ext_2 = temp_var_for_tac_24;
    computeFMul((Addr)&temp_var_for_tac_17,
                {(Addr) &(temp_var_for_const_12 = half), (Addr)&y},
                "/home/shijia/Public/testprogram/k_sinf.c_e.c:59:42");
    computeFMul((Addr)&temp_var_for_tac_18, {(Addr)&v, (Addr)&r},
                "/home/shijia/Public/testprogram/k_sinf.c_e.c:59:50");
    computeFSub((Addr)&temp_var_for_tac_19,
                {(Addr)&temp_var_for_tac_17, (Addr)&temp_var_for_tac_18},
                "/home/shijia/Public/testprogram/k_sinf.c_e.c:59:46");
    computeFMul((Addr)&temp_var_for_tac_20,
                {(Addr)&z, (Addr)&temp_var_for_tac_19},
                "/home/shijia/Public/testprogram/k_sinf.c_e.c:59:34");
    computeFSub((Addr)&temp_var_for_tac_21,
                {(Addr)&temp_var_for_tac_20, (Addr)&y},
                "/home/shijia/Public/testprogram/k_sinf.c_e.c:59:55");
    computeFMul((Addr)&temp_var_for_tac_22,
                {(Addr)&v, (Addr) &(temp_var_for_const_13 = S1)},
                "/home/shijia/Public/testprogram/k_sinf.c_e.c:59:64");
    computeFSub((Addr)&temp_var_for_tac_23,
                {(Addr)&temp_var_for_tac_21, (Addr)&temp_var_for_tac_22},
                "/home/shijia/Public/testprogram/k_sinf.c_e.c:59:60");
    computeFSub((Addr)&temp_var_for_tac_24,
                {(Addr)&x, (Addr)&temp_var_for_tac_23},
                "/home/shijia/Public/testprogram/k_sinf.c_e.c:59:28");
    AssignF({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_24,
            "/home/shijia/Public/testprogram/k_sinf.c_e.c:59:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  }
}
