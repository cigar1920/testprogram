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
  static const float S1 = (0.0 - 1.6666667163e-01);
  double temp_var_for_const_0, temp_var_for_const_1;
  ;                                         /* 0xbe2aaaab */
  static const float S2 = 8.3333337680e-03; /* 0x3c088889 */
  static const float S3 = (0.0 - 1.9841270114e-04);
  double temp_var_for_const_2, temp_var_for_const_3;
  double temp_var_for_tac_0;
  computeDSub((Addr)&temp_var_for_tac_0,
              {(Addr) &(temp_var_for_const_1 = 0.0),
               (Addr) &(temp_var_for_const_0 = 1.6666667163e-01)},
              "/home/shijia/Public/testprogram/k_sinf.c_e.c:27:32");
  ;                                         /* 0xb9500d01 */
  static const float S4 = 2.7557314297e-06; /* 0x3638ef1b */
  static const float S5 = (0.0 - 2.5050759689e-08);
  double temp_var_for_const_4, temp_var_for_const_5;
  double temp_var_for_tac_1;
  computeDSub((Addr)&temp_var_for_tac_1,
              {(Addr) &(temp_var_for_const_3 = 0.0),
               (Addr) &(temp_var_for_const_2 = 1.9841270114e-04)},
              "/home/shijia/Public/testprogram/k_sinf.c_e.c:29:32");
  ;                                         /* 0xb2d72f34 */
  static const float S6 = 1.5896910177e-10; /* 0x2f2ec9d3 */

  GET_FLOAT_WORD(ix, x);
  ix &= IC(0x7fffffff);    /* high word of x */
  if (ix < IC(0x32000000)) /* |x| < 2**-27 */
  {
    if ((int32_t)x == 0)
      return x;
  } /* generate inexact */
  z = x * x;
  float temp_var_for_tac_2;
  computeFSub((Addr)&temp_var_for_tac_2,
              {(Addr) &(temp_var_for_const_5 = 0.0),
               (Addr) &(temp_var_for_const_4 = 2.5050759689e-08)},
              "/home/shijia/Public/testprogram/k_sinf.c_e.c:39:9");
  computeFMul((Addr)&z, {(Addr)&x, (Addr)&x},
              "/home/shijia/Public/testprogram/k_sinf.c_e.c:39:5");
  v = z * x;
  computeFMul((Addr)&v, {(Addr)&z, (Addr)&x},
              "/home/shijia/Public/testprogram/k_sinf.c_e.c:40:5");
  r = S2 + z * (S3 + z * (S4 + z * (S5 + z * S6)));
  float temp_var_for_const_6, temp_var_for_const_7, temp_var_for_const_8,
      temp_var_for_const_9, temp_var_for_const_10;
  float temp_var_for_tac_3, temp_var_for_tac_4, temp_var_for_tac_5,
      temp_var_for_tac_6, temp_var_for_tac_7, temp_var_for_tac_8,
      temp_var_for_tac_9;
  computeFMul((Addr)&temp_var_for_tac_3,
              {(Addr)&z, (Addr) &(temp_var_for_const_6 = S6)},
              "/home/shijia/Public/testprogram/k_sinf.c_e.c:41:40");
  computeFAdd((Addr)&temp_var_for_tac_4,
              {(Addr) &(temp_var_for_const_7 = S5), (Addr)&temp_var_for_tac_3},
              "/home/shijia/Public/testprogram/k_sinf.c_e.c:41:34");
  computeFMul((Addr)&temp_var_for_tac_5, {(Addr)&z, (Addr)&temp_var_for_tac_4},
              "/home/shijia/Public/testprogram/k_sinf.c_e.c:41:30");
  computeFAdd((Addr)&temp_var_for_tac_6,
              {(Addr) &(temp_var_for_const_8 = S4), (Addr)&temp_var_for_tac_5},
              "/home/shijia/Public/testprogram/k_sinf.c_e.c:41:24");
  computeFMul((Addr)&temp_var_for_tac_7, {(Addr)&z, (Addr)&temp_var_for_tac_6},
              "/home/shijia/Public/testprogram/k_sinf.c_e.c:41:20");
  computeFAdd((Addr)&temp_var_for_tac_8,
              {(Addr) &(temp_var_for_const_9 = S3), (Addr)&temp_var_for_tac_7},
              "/home/shijia/Public/testprogram/k_sinf.c_e.c:41:14");
  computeFMul((Addr)&temp_var_for_tac_9, {(Addr)&z, (Addr)&temp_var_for_tac_8},
              "/home/shijia/Public/testprogram/k_sinf.c_e.c:41:10");
  computeFAdd((Addr)&r,
              {(Addr) &(temp_var_for_const_10 = S2), (Addr)&temp_var_for_tac_9},
              "/home/shijia/Public/testprogram/k_sinf.c_e.c:41:5");
  if (iy == 0) {
    float temp_var_for_ext_0;
    temp_var_for_ext_0 = x + v * (S1 + z * r);
    float temp_var_for_const_11;
    float temp_var_for_tac_10, temp_var_for_tac_11, temp_var_for_tac_12;
    computeFMul((Addr)&temp_var_for_tac_10, {(Addr)&z, (Addr)&r},
                "/home/shijia/Public/testprogram/k_sinf.c_e.c:44:38");
    computeFAdd(
        (Addr)&temp_var_for_tac_11,
        {(Addr) &(temp_var_for_const_11 = S1), (Addr)&temp_var_for_tac_10},
        "/home/shijia/Public/testprogram/k_sinf.c_e.c:44:32");
    computeFMul((Addr)&temp_var_for_tac_12,
                {(Addr)&v, (Addr)&temp_var_for_tac_11},
                "/home/shijia/Public/testprogram/k_sinf.c_e.c:44:28");
    computeFAdd((Addr)&temp_var_for_ext_0,
                {(Addr)&x, (Addr)&temp_var_for_tac_12},
                "/home/shijia/Public/testprogram/k_sinf.c_e.c:44:24");
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  else {
    float temp_var_for_ext_1;
    temp_var_for_ext_1 = x - ((z * (half * y - v * r) - y) - v * S1);
    float temp_var_for_const_12, temp_var_for_const_13;
    float temp_var_for_tac_13, temp_var_for_tac_14, temp_var_for_tac_15,
        temp_var_for_tac_16, temp_var_for_tac_17, temp_var_for_tac_18,
        temp_var_for_tac_19;
    computeFMul((Addr)&temp_var_for_tac_13,
                {(Addr) &(temp_var_for_const_12 = half), (Addr)&y},
                "/home/shijia/Public/testprogram/k_sinf.c_e.c:52:50");
    computeFMul((Addr)&temp_var_for_tac_14, {(Addr)&v, (Addr)&r},
                "/home/shijia/Public/testprogram/k_sinf.c_e.c:52:46");
    computeFSub((Addr)&temp_var_for_tac_15,
                {(Addr)&temp_var_for_tac_13, (Addr)&temp_var_for_tac_14},
                "/home/shijia/Public/testprogram/k_sinf.c_e.c:52:34");
    computeFMul((Addr)&temp_var_for_tac_16,
                {(Addr)&z, (Addr)&temp_var_for_tac_15},
                "/home/shijia/Public/testprogram/k_sinf.c_e.c:52:55");
    computeFSub((Addr)&temp_var_for_tac_17,
                {(Addr)&temp_var_for_tac_16, (Addr)&y},
                "/home/shijia/Public/testprogram/k_sinf.c_e.c:52:64");
    computeFMul((Addr)&temp_var_for_tac_18,
                {(Addr)&v, (Addr) &(temp_var_for_const_13 = S1)},
                "/home/shijia/Public/testprogram/k_sinf.c_e.c:52:60");
    computeFSub((Addr)&temp_var_for_tac_19,
                {(Addr)&temp_var_for_tac_17, (Addr)&temp_var_for_tac_18},
                "/home/shijia/Public/testprogram/k_sinf.c_e.c:52:28");
    computeFSub((Addr)&temp_var_for_ext_1,
                {(Addr)&x, (Addr)&temp_var_for_tac_19},
                "/home/shijia/Public/testprogram/k_sinf.c_e.c:52:24");
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }
}
