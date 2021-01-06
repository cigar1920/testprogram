#include "../ScDebug/scdebug.h"
/* s_log1pf.c -- float version of s_log1p.c.
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

#ifndef __have_fpu_log1p

float __ieee754_log1pf(float x) {
  float hfsq, f, c, s, z, R, u;
  int32_t k, hx, hu, ax;

  static const float ln2_hi = 6.9313812256e-01; /* 0x3f317180 */
  static const float ln2_lo = 9.0580006145e-06; /* 0x3717f7d1 */
  static const float two25 = 3.355443200e+07;   /* 0x4c000000 */
  static const float Lp1 = 6.6666668653e-01;    /* 3F2AAAAB */
  static const float Lp2 = 4.0000000596e-01;    /* 3ECCCCCD */
  static const float Lp3 = 2.8571429849e-01;    /* 3E924925 */
  static const float Lp4 = 2.2222198546e-01;    /* 3E638E29 */
  static const float Lp5 = 1.8183572590e-01;    /* 3E3A3325 */
  static const float Lp6 = 1.5313838422e-01;    /* 3E1CD04F */
  static const float Lp7 = 1.4798198640e-01;    /* 3E178897 */

  static const float zero = 0.0;

  GET_FLOAT_WORD(hx, x);
  ax = hx & IC(0x7fffffff);

  k = 1;
  if (hx < IC(0x3ed413d7)) {    /* x < 0.41422  */
    if (ax >= IC(0x3f800000)) { /* x <= -1.0 */
      if (int temp_var_for_tac_0; int temp_var_for_const_0;
          temp_var_for_tac_0 = x == 1.0F;

          ) {
        float temp_var_for_ext_0;
        float temp_var_for_tac_1, temp_var_for_tac_2;
        float temp_var_for_const_1;
        temp_var_for_tac_1 = x - x;

        temp_var_for_tac_2 = (-(two25)) / temp_var_for_tac_1;

        temp_var_for_ext_0 = temp_var_for_tac_2;
        compute((Addr)&temp_var_for_tac_0,
                {(Addr)&x, (Addr) &(temp_var_for_const_0 = 1.0F)},
                "/home/shijia/Public/testprogram/s_log1pf.c_e.c:45:13");
        computeFSub((Addr)&temp_var_for_tac_1, {(Addr)&x, (Addr)&x},
                    "/home/shijia/Public/testprogram/s_log1pf.c_e.c:47:42");
        computeFDiv((Addr)&temp_var_for_tac_2,
                    {(Addr) &(temp_var_for_const_1 = (-(two25))),
                     (Addr)&temp_var_for_tac_1},
                    "/home/shijia/Public/testprogram/s_log1pf.c_e.c:47:37");
        AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_2,
                "/home/shijia/Public/testprogram/s_log1pf.c_e.c:47:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
        callExp++; /*identify the function is  add move tmpShadow*/
        return (0.0 - p_var)_for_ext_0;
      }
      /* log1p(-1)=+inf */
      else {
        float temp_var_for_ext_1;
        float temp_var_for_tac_3, temp_var_for_tac_4, temp_var_for_tac_5;
        temp_var_for_tac_3 = x - x;

        temp_var_for_tac_4 = x - x;

        temp_var_for_tac_5 = temp_var_for_tac_3 / temp_var_for_tac_4;

        temp_var_for_ext_1 = temp_var_for_tac_5;
        computeFSub((Addr)&temp_var_for_tac_3, {(Addr)&x, (Addr)&x},
                    "/home/shijia/Public/testprogram/s_log1pf.c_e.c:56:33");
        computeFSub((Addr)&temp_var_for_tac_4, {(Addr)&x, (Addr)&x},
                    "/home/shijia/Public/testprogram/s_log1pf.c_e.c:56:43");
        computeFDiv((Addr)&temp_var_for_tac_5,
                    {(Addr)&temp_var_for_tac_3, (Addr)&temp_var_for_tac_4},
                    "/home/shijia/Public/testprogram/s_log1pf.c_e.c:56:38");
        AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_5,
                "/home/shijia/Public/testprogram/s_log1pf.c_e.c:56:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_1;
      }
      /* log1p(x<-1)=NaN */
    }
    if (ax < IC(0x31000000)) {    /* |x| < 2**-29 */
      math_force_eval(two25 + x); /* raise inexact */
      if (ax < IC(0x24800000))    /* |x| < 2**-54 */
      {
        float temp_var_for_ext_2;
        temp_var_for_ext_2 = x;
        computeFAdd((Addr)&temp_var_for_tac_6,
                    {(Addr) &(temp_var_for_const_2 = two25), (Addr)&x},
                    "/home/shijia/Public/testprogram/s_log1pf.c_e.c:65:7 "
                    "<Spelling=/home/shijia/Public/testprogram/"
                    "s_log1pf.c_e.c:65:29>");
        computeFAdd((Addr)&temp_var_for_tac_7,
                    {(Addr) &(temp_var_for_const_3 = two25), (Addr)&x},
                    "/home/shijia/Public/testprogram/s_log1pf.c_e.c:65:7 "
                    "<Spelling=/home/shijia/Public/testprogram/"
                    "s_log1pf.c_e.c:65:29>");
        AssignF({(Addr)&temp_var_for_ext_2}, (Addr)&x,
                "/home/shijia/Public/testprogram/s_log1pf.c_e.c:69:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_2;
      }

      else {
        float temp_var_for_ext_3;
        float temp_var_for_tac_8, temp_var_for_tac_9, temp_var_for_tac_10;
        float temp_var_for_const_4;
        temp_var_for_tac_8 = x * x;

        temp_var_for_tac_9 = temp_var_for_tac_8 * 0.5f;

        temp_var_for_tac_10 = x - temp_var_for_tac_9;

        temp_var_for_ext_3 = temp_var_for_tac_10;
        computeFMul((Addr)&temp_var_for_tac_8, {(Addr)&x, (Addr)&x},
                    "/home/shijia/Public/testprogram/s_log1pf.c_e.c:78:36");
        computeFMul(
            (Addr)&temp_var_for_tac_9,
            {(Addr)&temp_var_for_tac_8, (Addr) &(temp_var_for_const_4 = 0.5f)},
            "/home/shijia/Public/testprogram/s_log1pf.c_e.c:78:40");
        computeFSub((Addr)&temp_var_for_tac_10,
                    {(Addr)&x, (Addr)&temp_var_for_tac_9},
                    "/home/shijia/Public/testprogram/s_log1pf.c_e.c:78:32");
        AssignF({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_10,
                "/home/shijia/Public/testprogram/s_log1pf.c_e.c:78:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_3;
      }
    }
    if (hx > 0 || hx <= IC(0xbe95f61f)) {
      k = 0;
      f = x;
      AssignF({(Addr)&f}, (Addr)&x,
              "/home/shijia/Public/testprogram/s_log1pf.c_e.c:87:9");
      ;
      hu = 1;
      float temp_var_for_const_5;
      c = 0;
      AssignF({(Addr)&c}, (Addr) &(temp_var_for_const_5 = 0),
              "/home/shijia/Public/testprogram/s_log1pf.c_e.c:89:9");
      ;
    } /* -0.2929<x<0.41422 */
  }
  if (hx >= IC(0x7f800000)) {
    float temp_var_for_ext_4;
    float temp_var_for_tac_11;
    temp_var_for_tac_11 = x + x;

    temp_var_for_ext_4 = temp_var_for_tac_11;
    computeFAdd((Addr)&temp_var_for_tac_11, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/s_log1pf.c_e.c:94:28");
    AssignF({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_11,
            "/home/shijia/Public/testprogram/s_log1pf.c_e.c:94:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_4;
  }

  if (k != 0) {
    if (hx < IC(0x5a000000)) {
      float temp_var_for_tac_12;
      float temp_var_for_const_6;
      temp_var_for_tac_12 = 1.0f + x;

      u = temp_var_for_tac_12;
      computeFAdd((Addr)&temp_var_for_tac_12,
                  {(Addr) &(temp_var_for_const_6 = 1.0f), (Addr)&x},
                  "/home/shijia/Public/testprogram/s_log1pf.c_e.c:102:16");
      AssignF({(Addr)&u}, (Addr)&temp_var_for_tac_12,
              "/home/shijia/Public/testprogram/s_log1pf.c_e.c:102:9");
      ;
      GET_FLOAT_WORD(hu, u);
      k = (hu >> 23) - 127;
      /* correction term */
      float temp_var_for_const_7;
      c = (k > 0) ? 1.0f - (u - x) : x - (u - 1.0f);
      AssignF({(Addr)&c},
              (Addr) &(temp_var_for_const_7 =
                           (k > 0) ? 1.0f - (u - x) : x - (u - 1.0f)),
              "/home/shijia/Public/testprogram/s_log1pf.c_e.c:106:9");
      ;
      c /= u;
    } else {
      float temp_var_for_ext_5;
      temp_var_for_ext_5 = x;
      AssignF({(Addr)&temp_var_for_ext_5}, (Addr)&x,
              "/home/shijia/Public/testprogram/s_log1pf.c_e.c:110:26");
      ; // u
      /*(x)(u)(1.0f)(x)(u)(1.0f)(u)(x)(1.0f)(u)(u)(c)(x)*/
      u = temp_var_for_ext_5;
      AssignF({(Addr)&u}, (Addr)&temp_var_for_ext_5,
              "/home/shijia/Public/testprogram/s_log1pf.c_e.c:112:9");
      ;
      GET_FLOAT_WORD(hu, u);
      k = (hu >> 23) - 127;
      float temp_var_for_const_8;
      c = 0;
      AssignF({(Addr)&c}, (Addr) &(temp_var_for_const_8 = 0),
              "/home/shijia/Public/testprogram/s_log1pf.c_e.c:115:9");
      ;
    }
    hu &= IC(0x007fffff);
    if (hu < IC(0x3504f7)) {
      SET_FLOAT_WORD(u, hu | IC(0x3f800000)); /* normalize u */
    } else {
      k += 1;
      SET_FLOAT_WORD(u, hu | IC(0x3f000000)); /* normalize u/2 */
      hu = (IC(0x00800000) - hu) >> 2;
    }
    float temp_var_for_tac_13;
    float temp_var_for_const_9;
    temp_var_for_tac_13 = u - 1.0f;

    f = temp_var_for_tac_13;
    computeFSub((Addr)&temp_var_for_tac_13,
                {(Addr)&u, (Addr) &(temp_var_for_const_9 = 1.0f)},
                "/home/shijia/Public/testprogram/s_log1pf.c_e.c:125:11");
    AssignF({(Addr)&f}, (Addr)&temp_var_for_tac_13,
            "/home/shijia/Public/testprogram/s_log1pf.c_e.c:125:7");
    ;
  }
  float temp_var_for_tac_14, temp_var_for_tac_15;
  float temp_var_for_const_10;
  temp_var_for_tac_14 = 0.5f * f;

  temp_var_for_tac_15 = temp_var_for_tac_14 * f;

  hfsq = temp_var_for_tac_15;
  computeFMul((Addr)&temp_var_for_tac_14,
              {(Addr) &(temp_var_for_const_10 = 0.5f), (Addr)&f},
              "/home/shijia/Public/testprogram/s_log1pf.c_e.c:127:15");
  computeFMul((Addr)&temp_var_for_tac_15,
              {(Addr)&temp_var_for_tac_14, (Addr)&f},
              "/home/shijia/Public/testprogram/s_log1pf.c_e.c:127:19");
  AssignF({(Addr)&hfsq}, (Addr)&temp_var_for_tac_15,
          "/home/shijia/Public/testprogram/s_log1pf.c_e.c:127:8");
  ;

  if (hu == 0) { /* |f| < 2**-20 */
    if (int temp_var_for_tac_16; int temp_var_for_const_11;
        temp_var_for_tac_16 = f == zero;

        ) {
      if (k == 0) {
        float temp_var_for_ext_6;
        float temp_var_for_const_12;
        temp_var_for_ext_6 = zero;
        compute((Addr)&temp_var_for_tac_16,
                {(Addr)&f, (Addr) &(temp_var_for_const_11 = zero)},
                "/home/shijia/Public/testprogram/s_log1pf.c_e.c:130:11");
        AssignF({(Addr)&temp_var_for_ext_6},
                (Addr) &(temp_var_for_const_12 = zero),
                "/home/shijia/Public/testprogram/s_log1pf.c_e.c:133:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_6;
      }

      else {
        float temp_var_for_tac_17;
        float temp_var_for_const_13, temp_var_for_const_14;
        temp_var_for_tac_17 = k * ln2_lo;

        c += temp_var_for_tac_17;
        ;
        float temp_var_for_ext_7;
        float temp_var_for_tac_19, temp_var_for_tac_20;
        float temp_var_for_const_15, temp_var_for_const_16;
        temp_var_for_tac_19 = k * ln2_hi;

        temp_var_for_tac_20 = temp_var_for_tac_19 + c;

        temp_var_for_ext_7 = temp_var_for_tac_20;
        computeFMul((Addr)&temp_var_for_tac_17,
                    {(Addr) &(temp_var_for_const_14 = k),
                     (Addr) &(temp_var_for_const_13 = ln2_lo)},
                    "/home/shijia/Public/testprogram/s_log1pf.c_e.c:141:16");
        computeFMul((Addr)&temp_var_for_tac_19,
                    {(Addr) &(temp_var_for_const_16 = k),
                     (Addr) &(temp_var_for_const_15 = ln2_hi)},
                    "/home/shijia/Public/testprogram/s_log1pf.c_e.c:143:32");
        computeFAdd((Addr)&temp_var_for_tac_20,
                    {(Addr)&temp_var_for_tac_19, (Addr)&c},
                    "/home/shijia/Public/testprogram/s_log1pf.c_e.c:143:41");
        AssignF({(Addr)&temp_var_for_ext_7}, (Addr)&temp_var_for_tac_20,
                "/home/shijia/Public/testprogram/s_log1pf.c_e.c:143:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_7;
      }
    }
    float temp_var_for_tac_21, temp_var_for_tac_22, temp_var_for_tac_23;
    float temp_var_for_const_17, temp_var_for_const_18;
    temp_var_for_tac_21 = 0.66666666666666666f * f;

    temp_var_for_tac_22 = 1.0f - temp_var_for_tac_21;

    temp_var_for_tac_23 = hfsq * temp_var_for_tac_22;

    R = temp_var_for_tac_23;
    computeFMul(
        (Addr)&temp_var_for_tac_21,
        {(Addr) &(temp_var_for_const_17 = 0.66666666666666666f), (Addr)&f},
        "/home/shijia/Public/testprogram/s_log1pf.c_e.c:150:45");
    computeFSub(
        (Addr)&temp_var_for_tac_22,
        {(Addr) &(temp_var_for_const_18 = 1.0f), (Addr)&temp_var_for_tac_21},
        "/home/shijia/Public/testprogram/s_log1pf.c_e.c:150:22");
    computeFMul((Addr)&temp_var_for_tac_23,
                {(Addr)&hfsq, (Addr)&temp_var_for_tac_22},
                "/home/shijia/Public/testprogram/s_log1pf.c_e.c:150:14");
    AssignF({(Addr)&R}, (Addr)&temp_var_for_tac_23,
            "/home/shijia/Public/testprogram/s_log1pf.c_e.c:150:7");
    ;
    if (k == 0) {
      float temp_var_for_ext_8;
      float temp_var_for_tac_24;
      temp_var_for_tac_24 = f - R;

      temp_var_for_ext_8 = temp_var_for_tac_24;
      computeFSub((Addr)&temp_var_for_tac_24, {(Addr)&f, (Addr)&R},
                  "/home/shijia/Public/testprogram/s_log1pf.c_e.c:153:30");
      AssignF({(Addr)&temp_var_for_ext_8}, (Addr)&temp_var_for_tac_24,
              "/home/shijia/Public/testprogram/s_log1pf.c_e.c:153:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_8;
    }

    else {
      float temp_var_for_ext_9;
      float temp_var_for_tac_25, temp_var_for_tac_26, temp_var_for_tac_27,
          temp_var_for_tac_28, temp_var_for_tac_29, temp_var_for_tac_30;
      float temp_var_for_const_19, temp_var_for_const_20, temp_var_for_const_21,
          temp_var_for_const_22;
      temp_var_for_tac_25 = k * ln2_hi;

      temp_var_for_tac_26 = k * ln2_lo;

      temp_var_for_tac_27 = temp_var_for_tac_26 + c;

      temp_var_for_tac_28 = R - temp_var_for_tac_27;

      temp_var_for_tac_29 = temp_var_for_tac_28 - f;

      temp_var_for_tac_30 = temp_var_for_tac_25 - temp_var_for_tac_29;

      temp_var_for_ext_9 = temp_var_for_tac_30;
      computeFMul((Addr)&temp_var_for_tac_25,
                  {(Addr) &(temp_var_for_const_20 = k),
                   (Addr) &(temp_var_for_const_19 = ln2_hi)},
                  "/home/shijia/Public/testprogram/s_log1pf.c_e.c:162:30");
      computeFMul((Addr)&temp_var_for_tac_26,
                  {(Addr) &(temp_var_for_const_22 = k),
                   (Addr) &(temp_var_for_const_21 = ln2_lo)},
                  "/home/shijia/Public/testprogram/s_log1pf.c_e.c:162:50");
      computeFAdd((Addr)&temp_var_for_tac_27,
                  {(Addr)&temp_var_for_tac_26, (Addr)&c},
                  "/home/shijia/Public/testprogram/s_log1pf.c_e.c:162:59");
      computeFSub((Addr)&temp_var_for_tac_28,
                  {(Addr)&R, (Addr)&temp_var_for_tac_27},
                  "/home/shijia/Public/testprogram/s_log1pf.c_e.c:162:45");
      computeFSub((Addr)&temp_var_for_tac_29,
                  {(Addr)&temp_var_for_tac_28, (Addr)&f},
                  "/home/shijia/Public/testprogram/s_log1pf.c_e.c:162:65");
      computeFSub((Addr)&temp_var_for_tac_30,
                  {(Addr)&temp_var_for_tac_25, (Addr)&temp_var_for_tac_29},
                  "/home/shijia/Public/testprogram/s_log1pf.c_e.c:162:39");
      AssignF({(Addr)&temp_var_for_ext_9}, (Addr)&temp_var_for_tac_30,
              "/home/shijia/Public/testprogram/s_log1pf.c_e.c:162:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_9;
    }
  }
  float temp_var_for_tac_31, temp_var_for_tac_32;
  float temp_var_for_const_23;
  temp_var_for_tac_31 = 2.0f + f;

  temp_var_for_tac_32 = f / temp_var_for_tac_31;

  s = temp_var_for_tac_32;
  computeFAdd((Addr)&temp_var_for_tac_31,
              {(Addr) &(temp_var_for_const_23 = 2.0f), (Addr)&f},
              "/home/shijia/Public/testprogram/s_log1pf.c_e.c:169:17");
  computeFDiv((Addr)&temp_var_for_tac_32,
              {(Addr)&f, (Addr)&temp_var_for_tac_31},
              "/home/shijia/Public/testprogram/s_log1pf.c_e.c:169:9");
  AssignF({(Addr)&s}, (Addr)&temp_var_for_tac_32,
          "/home/shijia/Public/testprogram/s_log1pf.c_e.c:169:5");
  ;
  float temp_var_for_tac_33;
  temp_var_for_tac_33 = s * s;

  z = temp_var_for_tac_33;
  computeFMul((Addr)&temp_var_for_tac_33, {(Addr)&s, (Addr)&s},
              "/home/shijia/Public/testprogram/s_log1pf.c_e.c:170:9");
  AssignF({(Addr)&z}, (Addr)&temp_var_for_tac_33,
          "/home/shijia/Public/testprogram/s_log1pf.c_e.c:170:5");
  ;
  float temp_var_for_tac_34, temp_var_for_tac_35, temp_var_for_tac_36,
      temp_var_for_tac_37, temp_var_for_tac_38, temp_var_for_tac_39,
      temp_var_for_tac_40, temp_var_for_tac_41, temp_var_for_tac_42,
      temp_var_for_tac_43, temp_var_for_tac_44, temp_var_for_tac_45,
      temp_var_for_tac_46;
  float temp_var_for_const_24, temp_var_for_const_25, temp_var_for_const_26,
      temp_var_for_const_27, temp_var_for_const_28, temp_var_for_const_29,
      temp_var_for_const_30;
  temp_var_for_tac_34 = z * Lp7;

  temp_var_for_tac_35 = Lp6 + temp_var_for_tac_34;

  temp_var_for_tac_36 = z * temp_var_for_tac_35;

  temp_var_for_tac_37 = Lp5 + temp_var_for_tac_36;

  temp_var_for_tac_38 = z * temp_var_for_tac_37;

  temp_var_for_tac_39 = Lp4 + temp_var_for_tac_38;

  temp_var_for_tac_40 = z * temp_var_for_tac_39;

  temp_var_for_tac_41 = Lp3 + temp_var_for_tac_40;

  temp_var_for_tac_42 = z * temp_var_for_tac_41;

  temp_var_for_tac_43 = Lp2 + temp_var_for_tac_42;

  temp_var_for_tac_44 = z * temp_var_for_tac_43;

  temp_var_for_tac_45 = Lp1 + temp_var_for_tac_44;

  temp_var_for_tac_46 = z * temp_var_for_tac_45;

  R = temp_var_for_tac_46;
  computeFMul((Addr)&temp_var_for_tac_34,
              {(Addr)&z, (Addr) &(temp_var_for_const_24 = Lp7)},
              "/home/shijia/Public/testprogram/s_log1pf.c_e.c:172:69");
  computeFAdd(
      (Addr)&temp_var_for_tac_35,
      {(Addr) &(temp_var_for_const_25 = Lp6), (Addr)&temp_var_for_tac_34},
      "/home/shijia/Public/testprogram/s_log1pf.c_e.c:172:65");
  computeFMul((Addr)&temp_var_for_tac_36,
              {(Addr)&z, (Addr)&temp_var_for_tac_35},
              "/home/shijia/Public/testprogram/s_log1pf.c_e.c:172:58");
  computeFAdd(
      (Addr)&temp_var_for_tac_37,
      {(Addr) &(temp_var_for_const_26 = Lp5), (Addr)&temp_var_for_tac_36},
      "/home/shijia/Public/testprogram/s_log1pf.c_e.c:172:54");
  computeFMul((Addr)&temp_var_for_tac_38,
              {(Addr)&z, (Addr)&temp_var_for_tac_37},
              "/home/shijia/Public/testprogram/s_log1pf.c_e.c:172:47");
  computeFAdd(
      (Addr)&temp_var_for_tac_39,
      {(Addr) &(temp_var_for_const_27 = Lp4), (Addr)&temp_var_for_tac_38},
      "/home/shijia/Public/testprogram/s_log1pf.c_e.c:172:43");
  computeFMul((Addr)&temp_var_for_tac_40,
              {(Addr)&z, (Addr)&temp_var_for_tac_39},
              "/home/shijia/Public/testprogram/s_log1pf.c_e.c:172:36");
  computeFAdd(
      (Addr)&temp_var_for_tac_41,
      {(Addr) &(temp_var_for_const_28 = Lp3), (Addr)&temp_var_for_tac_40},
      "/home/shijia/Public/testprogram/s_log1pf.c_e.c:172:32");
  computeFMul((Addr)&temp_var_for_tac_42,
              {(Addr)&z, (Addr)&temp_var_for_tac_41},
              "/home/shijia/Public/testprogram/s_log1pf.c_e.c:172:25");
  computeFAdd(
      (Addr)&temp_var_for_tac_43,
      {(Addr) &(temp_var_for_const_29 = Lp2), (Addr)&temp_var_for_tac_42},
      "/home/shijia/Public/testprogram/s_log1pf.c_e.c:172:21");
  computeFMul((Addr)&temp_var_for_tac_44,
              {(Addr)&z, (Addr)&temp_var_for_tac_43},
              "/home/shijia/Public/testprogram/s_log1pf.c_e.c:172:14");
  computeFAdd(
      (Addr)&temp_var_for_tac_45,
      {(Addr) &(temp_var_for_const_30 = Lp1), (Addr)&temp_var_for_tac_44},
      "/home/shijia/Public/testprogram/s_log1pf.c_e.c:171:16");
  computeFMul((Addr)&temp_var_for_tac_46,
              {(Addr)&z, (Addr)&temp_var_for_tac_45},
              "/home/shijia/Public/testprogram/s_log1pf.c_e.c:171:9");
  AssignF({(Addr)&R}, (Addr)&temp_var_for_tac_46,
          "/home/shijia/Public/testprogram/s_log1pf.c_e.c:171:5");
  ;
  if (k == 0) {
    float temp_var_for_ext_10;
    float temp_var_for_tac_47, temp_var_for_tac_48, temp_var_for_tac_49,
        temp_var_for_tac_50;
    temp_var_for_tac_47 = hfsq + R;

    temp_var_for_tac_48 = s * temp_var_for_tac_47;

    temp_var_for_tac_49 = hfsq - temp_var_for_tac_48;

    temp_var_for_tac_50 = f - temp_var_for_tac_49;

    temp_var_for_ext_10 = temp_var_for_tac_50;
    computeFAdd((Addr)&temp_var_for_tac_47, {(Addr)&hfsq, (Addr)&R},
                "/home/shijia/Public/testprogram/s_log1pf.c_e.c:175:49");
    computeFMul((Addr)&temp_var_for_tac_48,
                {(Addr)&s, (Addr)&temp_var_for_tac_47},
                "/home/shijia/Public/testprogram/s_log1pf.c_e.c:175:41");
    computeFSub((Addr)&temp_var_for_tac_49,
                {(Addr)&hfsq, (Addr)&temp_var_for_tac_48},
                "/home/shijia/Public/testprogram/s_log1pf.c_e.c:175:37");
    computeFSub((Addr)&temp_var_for_tac_50,
                {(Addr)&f, (Addr)&temp_var_for_tac_49},
                "/home/shijia/Public/testprogram/s_log1pf.c_e.c:175:29");
    AssignF({(Addr)&temp_var_for_ext_10}, (Addr)&temp_var_for_tac_50,
            "/home/shijia/Public/testprogram/s_log1pf.c_e.c:175:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_10", (Addr)&temp_var_for_ext_10));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_10;
  }

  else {
    float temp_var_for_ext_11;
    float temp_var_for_tac_51, temp_var_for_tac_52, temp_var_for_tac_53,
        temp_var_for_tac_54, temp_var_for_tac_55, temp_var_for_tac_56,
        temp_var_for_tac_57, temp_var_for_tac_58, temp_var_for_tac_59;
    float temp_var_for_const_31, temp_var_for_const_32, temp_var_for_const_33,
        temp_var_for_const_34;
    temp_var_for_tac_51 = k * ln2_hi;

    temp_var_for_tac_52 = hfsq + R;

    temp_var_for_tac_53 = s * temp_var_for_tac_52;

    temp_var_for_tac_54 = k * ln2_lo;

    temp_var_for_tac_55 = temp_var_for_tac_54 + c;

    temp_var_for_tac_56 = temp_var_for_tac_53 + temp_var_for_tac_55;

    temp_var_for_tac_57 = hfsq - temp_var_for_tac_56;

    temp_var_for_tac_58 = temp_var_for_tac_57 - f;

    temp_var_for_tac_59 = temp_var_for_tac_51 - temp_var_for_tac_58;

    temp_var_for_ext_11 = temp_var_for_tac_59;
    computeFMul((Addr)&temp_var_for_tac_51,
                {(Addr) &(temp_var_for_const_32 = k),
                 (Addr) &(temp_var_for_const_31 = ln2_hi)},
                "/home/shijia/Public/testprogram/s_log1pf.c_e.c:185:11");
    computeFAdd((Addr)&temp_var_for_tac_52, {(Addr)&hfsq, (Addr)&R},
                "/home/shijia/Public/testprogram/s_log1pf.c_e.c:185:42");
    computeFMul((Addr)&temp_var_for_tac_53,
                {(Addr)&s, (Addr)&temp_var_for_tac_52},
                "/home/shijia/Public/testprogram/s_log1pf.c_e.c:185:34");
    computeFMul((Addr)&temp_var_for_tac_54,
                {(Addr) &(temp_var_for_const_34 = k),
                 (Addr) &(temp_var_for_const_33 = ln2_lo)},
                "/home/shijia/Public/testprogram/s_log1pf.c_e.c:185:52");
    computeFAdd((Addr)&temp_var_for_tac_55,
                {(Addr)&temp_var_for_tac_54, (Addr)&c},
                "/home/shijia/Public/testprogram/s_log1pf.c_e.c:185:61");
    computeFAdd((Addr)&temp_var_for_tac_56,
                {(Addr)&temp_var_for_tac_53, (Addr)&temp_var_for_tac_55},
                "/home/shijia/Public/testprogram/s_log1pf.c_e.c:185:47");
    computeFSub((Addr)&temp_var_for_tac_57,
                {(Addr)&hfsq, (Addr)&temp_var_for_tac_56},
                "/home/shijia/Public/testprogram/s_log1pf.c_e.c:185:29");
    computeFSub((Addr)&temp_var_for_tac_58,
                {(Addr)&temp_var_for_tac_57, (Addr)&f},
                "/home/shijia/Public/testprogram/s_log1pf.c_e.c:185:68");
    computeFSub((Addr)&temp_var_for_tac_59,
                {(Addr)&temp_var_for_tac_51, (Addr)&temp_var_for_tac_58},
                "/home/shijia/Public/testprogram/s_log1pf.c_e.c:185:20");
    AssignF({(Addr)&temp_var_for_ext_11}, (Addr)&temp_var_for_tac_59,
            "/home/shijia/Public/testprogram/s_log1pf.c_e.c:184:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_11", (Addr)&temp_var_for_ext_11));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_11;
  }
}

#endif

/* wrapper log1p(x) */
float __log1pf(float x) {
  if (islessequal(x, -1.0) && _LIB_VERSION != _IEEE_) {
    if (int temp_var_for_tac_60, temp_var_for_tac_61;
        int temp_var_for_const_35, temp_var_for_const_36;
        temp_var_for_tac_60 = 0.0 - 1.0F;

        temp_var_for_tac_61 = x == temp_var_for_tac_60;

        ) {
      feraiseexcept(FE_DIVBYZERO);
      float temp_var_for_ext_12;
      float temp_var_for_const_37;
      float temp_var_for_callexp_1;

      temp_var_for_callexp_0 = __builtin_huge_valf();
      temp_var_for_callexp_1 = __kernel_standard_f(
          x, x, (-(temp_var_for_callexp_0)), KMATHERRF_LOG_ZERO);
      temp_var_for_ext_12 = temp_var_for_callexp_1;
      computeDSub((Addr)&temp_var_for_tac_60,
                  {(Addr) &(temp_var_for_const_36 = 0.0),
                   (Addr) &(temp_var_for_const_35 = 1.0F)},
                  "/home/shijia/Public/testprogram/s_log1pf.c_e.c:198:19");
      compute((Addr)&temp_var_for_tac_61,
              {(Addr)&x, (Addr)&temp_var_for_tac_60},
              "/home/shijia/Public/testprogram/s_log1pf.c_e.c:198:11");
      AssignF({(Addr)&temp_var_for_ext_12},
              (Addr) &(temp_var_for_const_37 = temp_var_for_callexp_1),
              "/home/shijia/Public/testprogram/s_log1pf.c_e.c:201:27");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_12", (Addr)&temp_var_for_ext_12));
      callExp++; /*identify the function is  add move tmpShad(0.0 - w*/
retur)n temp_var_for_ext_12;	/* log(0) */
    } else {
      feraiseexcept(FE_INVALID);
      float temp_var_for_ext_13;
      float temp_var_for_const_38;
      float temp_var_for_callexp_2;

      /*embed fun has found*/
      float temp_var_for_callexp_3;

      temp_var_for_callexp_2 = __builtin_nanf("");
      temp_var_for_callexp_3 = __kernel_standard_f(x, x, temp_var_for_callexp_2,
                                                   KMATHERRF_LOG_MINUS);
      temp_var_for_ext_13 = temp_var_for_callexp_3;
      AssignF({(Addr)&temp_var_for_ext_13},
              (Addr) &(temp_var_for_const_38 = temp_var_for_callexp_3),
              "/home/shijia/Public/testprogram/s_log1pf.c_e.c:210:27");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_13", (Addr)&temp_var_for_ext_13));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_13; /* log(x<0) */
    }
  }

  float temp_var_for_ext_14;
  float temp_var_for_const_39;
  float temp_var_for_callexp_4;

  temp_var_for_callexp_4 = __ieee754_log1pf(x);
  temp_var_for_ext_14 = temp_var_for_callexp_4;
  AssignF({(Addr)&temp_var_for_ext_14},
          (Addr) &(temp_var_for_const_39 = temp_var_for_callexp_4),
          "/home/shijia/Public/testprogram/s_log1pf.c_e.c:220:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_14", (Addr)&temp_var_for_ext_14));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_14;
}

__typeof(__log1pf) log1pf __attribute__((weak, alias("__log1pf")));
