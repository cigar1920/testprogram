#include "../ScDebug/scdebug.h"
/* e_logf.c -- float version of e_log.c.
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

#ifndef __have_fpu_log

float __ieee754_logf(float x) {
  float hfsq, f, s, z, R, w, t1, t2, dk;
  int32_t k, ix, i, j;

  static const float ln2_hi = 6.9313812256e-01; /* 0x3f317180 */
  static const float ln2_lo = 9.0580006145e-06; /* 0x3717f7d1 */
  static const float two25 = 3.355443200e+07;   /* 0x4c000000 */
  static const float Lg1 = 6.6666668653e-01;    /* 3F2AAAAB */
  static const float Lg2 = 4.0000000596e-01;    /* 3ECCCCCD */
  static const float Lg3 = 2.8571429849e-01;    /* 3E924925 */
  static const float Lg4 = 2.2222198546e-01;    /* 3E638E29 */
  static const float Lg5 = 1.8183572590e-01;    /* 3E3A3325 */
  static const float Lg6 = 1.5313838422e-01;    /* 3E1CD04F */
  static const float Lg7 = 1.4798198640e-01;    /* 3E178897 */

  static const float zero = 0.0;

  GET_FLOAT_WORD(ix, x);

  k = 0;
  if (ix < IC(0x00800000)) { /* x < 2**-126  */
    if ((ix & IC(0x7fffffff)) == 0) {
      float temp_var_for_ext_0;
      float temp_var_for_tac_0, temp_var_for_tac_1;
      float temp_var_for_const_0;
      temp_var_for_tac_0 = x - x;

      temp_var_for_tac_1 = (-(two25)) / temp_var_for_tac_0;

      temp_var_for_ext_0 = temp_var_for_tac_1;
      computeFSub((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&x},
                  "/home/shijia/Public/testprogram/e_logf.c_e.c:45:40");
      computeFDiv((Addr)&temp_var_for_tac_1,
                  {(Addr) &(temp_var_for_const_0 = (-(two25))),
                   (Addr)&temp_var_for_tac_0},
                  "/home/shijia/Public/testprogram/e_logf.c_e.c:45:35");
      AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_1,
              "/home/shijia/Public/testprogram/e_logf.c_e.c:45:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
      callExp++; /*identify the function is  add move tmpShadow*/
      return (0.0 - p_var)_for_ext_0;
    }
    /* log(+-0)=-inf */
    if (ix < 0) {
      float temp_var_for_ext_1;
      float temp_var_for_tac_2, temp_var_for_tac_3, temp_var_for_tac_4;
      temp_var_for_tac_2 = x - x;

      temp_var_for_tac_3 = x - x;

      temp_var_for_tac_4 = temp_var_for_tac_2 / temp_var_for_tac_3;

      temp_var_for_ext_1 = temp_var_for_tac_4;
      computeFSub((Addr)&temp_var_for_tac_2, {(Addr)&x, (Addr)&x},
                  "/home/shijia/Public/testprogram/e_logf.c_e.c:54:31");
      computeFSub((Addr)&temp_var_for_tac_3, {(Addr)&x, (Addr)&x},
                  "/home/shijia/Public/testprogram/e_logf.c_e.c:54:41");
      computeFDiv((Addr)&temp_var_for_tac_4,
                  {(Addr)&temp_var_for_tac_2, (Addr)&temp_var_for_tac_3},
                  "/home/shijia/Public/testprogram/e_logf.c_e.c:54:36");
      AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_4,
              "/home/shijia/Public/testprogram/e_logf.c_e.c:54:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_1;
    }
    /* log(-#) = NaN */
    k -= 25;
    x *= two25;
    ; /* subnormal number, scale up x */
    GET_FLOAT_WORD(ix, x);
  }
  if (ix >= IC(0x7f800000)) {
    float temp_var_for_ext_2;
    float temp_var_for_tac_6;
    temp_var_for_tac_6 = x + x;

    temp_var_for_ext_2 = temp_var_for_tac_6;
    computeFAdd((Addr)&temp_var_for_tac_6, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_logf.c_e.c:67:28");
    AssignF({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_6,
            "/home/shijia/Public/testprogram/e_logf.c_e.c:67:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  }

  k += (ix >> 23) - 127;
  ix &= IC(0x007fffff);
  i = (ix + (IC(0x95f64) << 3)) & IC(0x800000);
  SET_FLOAT_WORD(x, ix | (i ^ IC(0x3f800000))); /* normalize x or x/2 */
  k += (i >> 23);
  float temp_var_for_tac_7;
  float temp_var_for_const_1;
  temp_var_for_tac_7 = x - ((float)1.0);

  f = temp_var_for_tac_7;
  computeFSub((Addr)&temp_var_for_tac_7,
              {(Addr)&x, (Addr) &(temp_var_for_const_1 = ((float)1.0))},
              "/home/shijia/Public/testprogram/e_logf.c_e.c:78:9");
  AssignF({(Addr)&f}, (Addr)&temp_var_for_tac_7,
          "/home/shijia/Public/testprogram/e_logf.c_e.c:78:5");
  ;
  if ((IC(0x007fffff) & (15 + ix)) < 16) { /* |f| < 2**-20 */
    if (int temp_var_for_tac_8; int temp_var_for_const_2;
        temp_var_for_tac_8 = f == zero;

        ) {
      if (k == 0) {
        float temp_var_for_ext_3;
        float temp_var_for_const_3;
        temp_var_for_ext_3 = zero;
        compute((Addr)&temp_var_for_tac_8,
                {(Addr)&f, (Addr) &(temp_var_for_const_2 = zero)},
                "/home/shijia/Public/testprogram/e_logf.c_e.c:80:11");
        AssignF({(Addr)&temp_var_for_ext_3},
                (Addr) &(temp_var_for_const_3 = zero),
                "/home/shijia/Public/testprogram/e_logf.c_e.c:83:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_3;
      }

      else {
        float temp_var_for_const_4;
        dk = ((float)k);
        AssignF({(Addr)&dk}, (Addr) &(temp_var_for_const_4 = ((float)k)),
                "/home/shijia/Public/testprogram/e_logf.c_e.c:91:12");
        ;
        float temp_var_for_ext_4;
        float temp_var_for_tac_9, temp_var_for_tac_10, temp_var_for_tac_11;
        float temp_var_for_const_5, temp_var_for_const_6;
        temp_var_for_tac_9 = dk * ln2_hi;

        temp_var_for_tac_10 = dk * ln2_lo;

        temp_var_for_tac_11 = temp_var_for_tac_9 + temp_var_for_tac_10;

        temp_var_for_ext_4 = temp_var_for_tac_11;
        computeFMul((Addr)&temp_var_for_tac_9,
                    {(Addr)&dk, (Addr) &(temp_var_for_const_5 = ln2_hi)},
                    "/home/shijia/Public/testprogram/e_logf.c_e.c:93:33");
        computeFMul((Addr)&temp_var_for_tac_10,
                    {(Addr)&dk, (Addr) &(temp_var_for_const_6 = ln2_lo)},
                    "/home/shijia/Public/testprogram/e_logf.c_e.c:93:47");
        computeFAdd((Addr)&temp_var_for_tac_11,
                    {(Addr)&temp_var_for_tac_9, (Addr)&temp_var_for_tac_10},
                    "/home/shijia/Public/testprogram/e_logf.c_e.c:93:42");
        AssignF({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_11,
                "/home/shijia/Public/testprogram/e_logf.c_e.c:93:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_4;
      }
    }
    float temp_var_for_tac_12, temp_var_for_tac_13, temp_var_for_tac_14,
        temp_var_for_tac_15;
    float temp_var_for_const_7, temp_var_for_const_8;
    temp_var_for_tac_12 = f * f;

    temp_var_for_tac_13 = ((float)0.33333333333333333) * f;

    temp_var_for_tac_14 = ((float)0.5) - temp_var_for_tac_13;

    temp_var_for_tac_15 = temp_var_for_tac_12 * temp_var_for_tac_14;

    R = temp_var_for_tac_15;
    computeFMul((Addr)&temp_var_for_tac_12, {(Addr)&f, (Addr)&f},
                "/home/shijia/Public/testprogram/e_logf.c_e.c:100:11");
    computeFMul((Addr)&temp_var_for_tac_13,
                {(Addr) &(temp_var_for_const_7 = ((float)0.33333333333333333)),
                 (Addr)&f},
                "/home/shijia/Public/testprogram/e_logf.c_e.c:100:58");
    computeFSub((Addr)&temp_var_for_tac_14,
                {(Addr) &(temp_var_for_const_8 = ((float)0.5)),
                 (Addr)&temp_var_for_tac_13},
                "/home/shijia/Public/testprogram/e_logf.c_e.c:100:29");
    computeFMul((Addr)&temp_var_for_tac_15,
                {(Addr)&temp_var_for_tac_12, (Addr)&temp_var_for_tac_14},
                "/home/shijia/Public/testprogram/e_logf.c_e.c:100:15");
    AssignF({(Addr)&R}, (Addr)&temp_var_for_tac_15,
            "/home/shijia/Public/testprogram/e_logf.c_e.c:100:7");
    ;
    if (k == 0) {
      float temp_var_for_ext_5;
      float temp_var_for_tac_16;
      temp_var_for_tac_16 = f - R;

      temp_var_for_ext_5 = temp_var_for_tac_16;
      computeFSub((Addr)&temp_var_for_tac_16, {(Addr)&f, (Addr)&R},
                  "/home/shijia/Public/testprogram/e_logf.c_e.c:103:30");
      AssignF({(Addr)&temp_var_for_ext_5}, (Addr)&temp_var_for_tac_16,
              "/home/shijia/Public/testprogram/e_logf.c_e.c:103:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_5;
    }

    else {
      float temp_var_for_const_9;
      dk = ((float)k);
      AssignF({(Addr)&dk}, (Addr) &(temp_var_for_const_9 = ((float)k)),
              "/home/shijia/Public/testprogram/e_logf.c_e.c:111:10");
      ;
      float temp_var_for_ext_6;
      float temp_var_for_tac_17, temp_var_for_tac_18, temp_var_for_tac_19,
          temp_var_for_tac_20, temp_var_for_tac_21;
      float temp_var_for_const_10, temp_var_for_const_11;
      temp_var_for_tac_17 = dk * ln2_hi;

      temp_var_for_tac_18 = dk * ln2_lo;

      temp_var_for_tac_19 = R - temp_var_for_tac_18;

      temp_var_for_tac_20 = temp_var_for_tac_19 - f;

      temp_var_for_tac_21 = temp_var_for_tac_17 - temp_var_for_tac_20;

      temp_var_for_ext_6 = temp_var_for_tac_21;
      computeFMul((Addr)&temp_var_for_tac_17,
                  {(Addr)&dk, (Addr) &(temp_var_for_const_10 = ln2_hi)},
                  "/home/shijia/Public/testprogram/e_logf.c_e.c:113:31");
      computeFMul((Addr)&temp_var_for_tac_18,
                  {(Addr)&dk, (Addr) &(temp_var_for_const_11 = ln2_lo)},
                  "/home/shijia/Public/testprogram/e_logf.c_e.c:113:51");
      computeFSub((Addr)&temp_var_for_tac_19,
                  {(Addr)&R, (Addr)&temp_var_for_tac_18},
                  "/home/shijia/Public/testprogram/e_logf.c_e.c:113:46");
      computeFSub((Addr)&temp_var_for_tac_20,
                  {(Addr)&temp_var_for_tac_19, (Addr)&f},
                  "/home/shijia/Public/testprogram/e_logf.c_e.c:113:61");
      computeFSub((Addr)&temp_var_for_tac_21,
                  {(Addr)&temp_var_for_tac_17, (Addr)&temp_var_for_tac_20},
                  "/home/shijia/Public/testprogram/e_logf.c_e.c:113:40");
      AssignF({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_21,
              "/home/shijia/Public/testprogram/e_logf.c_e.c:113:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_6;
    }
  }
  float temp_var_for_tac_22, temp_var_for_tac_23;
  float temp_var_for_const_12;
  temp_var_for_tac_22 = ((float)2.0) + f;

  temp_var_for_tac_23 = f / temp_var_for_tac_22;

  s = temp_var_for_tac_23;
  computeFAdd((Addr)&temp_var_for_tac_22,
              {(Addr) &(temp_var_for_const_12 = ((float)2.0)), (Addr)&f},
              "/home/shijia/Public/testprogram/e_logf.c_e.c:120:23");
  computeFDiv((Addr)&temp_var_for_tac_23,
              {(Addr)&f, (Addr)&temp_var_for_tac_22},
              "/home/shijia/Public/testprogram/e_logf.c_e.c:120:9");
  AssignF({(Addr)&s}, (Addr)&temp_var_for_tac_23,
          "/home/shijia/Public/testprogram/e_logf.c_e.c:120:5");
  ;
  float temp_var_for_const_13;
  dk = ((float)k);
  AssignF({(Addr)&dk}, (Addr) &(temp_var_for_const_13 = ((float)k)),
          "/home/shijia/Public/testprogram/e_logf.c_e.c:121:6");
  ;
  float temp_var_for_tac_24;
  temp_var_for_tac_24 = s * s;

  z = temp_var_for_tac_24;
  computeFMul((Addr)&temp_var_for_tac_24, {(Addr)&s, (Addr)&s},
              "/home/shijia/Public/testprogram/e_logf.c_e.c:122:9");
  AssignF({(Addr)&z}, (Addr)&temp_var_for_tac_24,
          "/home/shijia/Public/testprogram/e_logf.c_e.c:122:5");
  ;
  i = ix - (IC(0x6147a) << 3);
  float temp_var_for_tac_25;
  temp_var_for_tac_25 = z * z;

  w = temp_var_for_tac_25;
  computeFMul((Addr)&temp_var_for_tac_25, {(Addr)&z, (Addr)&z},
              "/home/shijia/Public/testprogram/e_logf.c_e.c:124:9");
  AssignF({(Addr)&w}, (Addr)&temp_var_for_tac_25,
          "/home/shijia/Public/testprogram/e_logf.c_e.c:124:5");
  ;
  j = (IC(0x6b851) << 3) - ix;
  float temp_var_for_tac_26, temp_var_for_tac_27, temp_var_for_tac_28,
      temp_var_for_tac_29, temp_var_for_tac_30;
  float temp_var_for_const_14, temp_var_for_const_15, temp_var_for_const_16;
  temp_var_for_tac_26 = w * Lg6;

  temp_var_for_tac_27 = Lg4 + temp_var_for_tac_26;

  temp_var_for_tac_28 = w * temp_var_for_tac_27;

  temp_var_for_tac_29 = Lg2 + temp_var_for_tac_28;

  temp_var_for_tac_30 = w * temp_var_for_tac_29;

  t1 = temp_var_for_tac_30;
  computeFMul((Addr)&temp_var_for_tac_26,
              {(Addr)&w, (Addr) &(temp_var_for_const_14 = Lg6)},
              "/home/shijia/Public/testprogram/e_logf.c_e.c:126:32");
  computeFAdd(
      (Addr)&temp_var_for_tac_27,
      {(Addr) &(temp_var_for_const_15 = Lg4), (Addr)&temp_var_for_tac_26},
      "/home/shijia/Public/testprogram/e_logf.c_e.c:126:28");
  computeFMul((Addr)&temp_var_for_tac_28,
              {(Addr)&w, (Addr)&temp_var_for_tac_27},
              "/home/shijia/Public/testprogram/e_logf.c_e.c:126:21");
  computeFAdd(
      (Addr)&temp_var_for_tac_29,
      {(Addr) &(temp_var_for_const_16 = Lg2), (Addr)&temp_var_for_tac_28},
      "/home/shijia/Public/testprogram/e_logf.c_e.c:126:17");
  computeFMul((Addr)&temp_var_for_tac_30,
              {(Addr)&w, (Addr)&temp_var_for_tac_29},
              "/home/shijia/Public/testprogram/e_logf.c_e.c:126:10");
  AssignF({(Addr)&t1}, (Addr)&temp_var_for_tac_30,
          "/home/shijia/Public/testprogram/e_logf.c_e.c:126:6");
  ;
  float temp_var_for_tac_31, temp_var_for_tac_32, temp_var_for_tac_33,
      temp_var_for_tac_34, temp_var_for_tac_35, temp_var_for_tac_36,
      temp_var_for_tac_37;
  float temp_var_for_const_17, temp_var_for_const_18, temp_var_for_const_19,
      temp_var_for_const_20;
  temp_var_for_tac_31 = w * Lg7;

  temp_var_for_tac_32 = Lg5 + temp_var_for_tac_31;

  temp_var_for_tac_33 = w * temp_var_for_tac_32;

  temp_var_for_tac_34 = Lg3 + temp_var_for_tac_33;

  temp_var_for_tac_35 = w * temp_var_for_tac_34;

  temp_var_for_tac_36 = Lg1 + temp_var_for_tac_35;

  temp_var_for_tac_37 = z * temp_var_for_tac_36;

  t2 = temp_var_for_tac_37;
  computeFMul((Addr)&temp_var_for_tac_31,
              {(Addr)&w, (Addr) &(temp_var_for_const_17 = Lg7)},
              "/home/shijia/Public/testprogram/e_logf.c_e.c:127:43");
  computeFAdd(
      (Addr)&temp_var_for_tac_32,
      {(Addr) &(temp_var_for_const_18 = Lg5), (Addr)&temp_var_for_tac_31},
      "/home/shijia/Public/testprogram/e_logf.c_e.c:127:39");
  computeFMul((Addr)&temp_var_for_tac_33,
              {(Addr)&w, (Addr)&temp_var_for_tac_32},
              "/home/shijia/Public/testprogram/e_logf.c_e.c:127:32");
  computeFAdd(
      (Addr)&temp_var_for_tac_34,
      {(Addr) &(temp_var_for_const_19 = Lg3), (Addr)&temp_var_for_tac_33},
      "/home/shijia/Public/testprogram/e_logf.c_e.c:127:28");
  computeFMul((Addr)&temp_var_for_tac_35,
              {(Addr)&w, (Addr)&temp_var_for_tac_34},
              "/home/shijia/Public/testprogram/e_logf.c_e.c:127:21");
  computeFAdd(
      (Addr)&temp_var_for_tac_36,
      {(Addr) &(temp_var_for_const_20 = Lg1), (Addr)&temp_var_for_tac_35},
      "/home/shijia/Public/testprogram/e_logf.c_e.c:127:17");
  computeFMul((Addr)&temp_var_for_tac_37,
              {(Addr)&z, (Addr)&temp_var_for_tac_36},
              "/home/shijia/Public/testprogram/e_logf.c_e.c:127:10");
  AssignF({(Addr)&t2}, (Addr)&temp_var_for_tac_37,
          "/home/shijia/Public/testprogram/e_logf.c_e.c:127:6");
  ;
  i |= j;
  float temp_var_for_tac_38;
  temp_var_for_tac_38 = t2 + t1;

  R = temp_var_for_tac_38;
  computeFAdd((Addr)&temp_var_for_tac_38, {(Addr)&t2, (Addr)&t1},
              "/home/shijia/Public/testprogram/e_logf.c_e.c:129:10");
  AssignF({(Addr)&R}, (Addr)&temp_var_for_tac_38,
          "/home/shijia/Public/testprogram/e_logf.c_e.c:129:5");
  ;
  if (i > 0) {
    float temp_var_for_tac_39, temp_var_for_tac_40;
    float temp_var_for_const_21;
    temp_var_for_tac_39 = 0.5F * f;

    temp_var_for_tac_40 = temp_var_for_tac_39 * f;

    hfsq = temp_var_for_tac_40;
    computeFMul((Addr)&temp_var_for_tac_39,
                {(Addr) &(temp_var_for_const_21 = 0.5F), (Addr)&f},
                "/home/shijia/Public/testprogram/e_logf.c_e.c:131:17");
    computeFMul((Addr)&temp_var_for_tac_40,
                {(Addr)&temp_var_for_tac_39, (Addr)&f},
                "/home/shijia/Public/testprogram/e_logf.c_e.c:131:21");
    AssignF({(Addr)&hfsq}, (Addr)&temp_var_for_tac_40,
            "/home/shijia/Public/testprogram/e_logf.c_e.c:131:10");
    ;

    if (k == 0) {
      float temp_var_for_ext_7;
      float temp_var_for_tac_41, temp_var_for_tac_42, temp_var_for_tac_43,
          temp_var_for_tac_44;
      temp_var_for_tac_41 = hfsq + R;

      temp_var_for_tac_42 = s * temp_var_for_tac_41;

      temp_var_for_tac_43 = hfsq - temp_var_for_tac_42;

      temp_var_for_tac_44 = f - temp_var_for_tac_43;

      temp_var_for_ext_7 = temp_var_for_tac_44;
      computeFAdd((Addr)&temp_var_for_tac_41, {(Addr)&hfsq, (Addr)&R},
                  "/home/shijia/Public/testprogram/e_logf.c_e.c:135:50");
      computeFMul((Addr)&temp_var_for_tac_42,
                  {(Addr)&s, (Addr)&temp_var_for_tac_41},
                  "/home/shijia/Public/testprogram/e_logf.c_e.c:135:42");
      computeFSub((Addr)&temp_var_for_tac_43,
                  {(Addr)&hfsq, (Addr)&temp_var_for_tac_42},
                  "/home/shijia/Public/testprogram/e_logf.c_e.c:135:38");
      computeFSub((Addr)&temp_var_for_tac_44,
                  {(Addr)&f, (Addr)&temp_var_for_tac_43},
                  "/home/shijia/Public/testprogram/e_logf.c_e.c:135:30");
      AssignF({(Addr)&temp_var_for_ext_7}, (Addr)&temp_var_for_tac_44,
              "/home/shijia/Public/testprogram/e_logf.c_e.c:135:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_7;
    }

    else {
      float temp_var_for_ext_8;
      float temp_var_for_tac_45, temp_var_for_tac_46, temp_var_for_tac_47,
          temp_var_for_tac_48, temp_var_for_tac_49, temp_var_for_tac_50,
          temp_var_for_tac_51, temp_var_for_tac_52;
      float temp_var_for_const_22, temp_var_for_const_23;
      temp_var_for_tac_45 = dk * ln2_hi;

      temp_var_for_tac_46 = hfsq + R;

      temp_var_for_tac_47 = s * temp_var_for_tac_46;

      temp_var_for_tac_48 = dk * ln2_lo;

      temp_var_for_tac_49 = temp_var_for_tac_47 + temp_var_for_tac_48;

      temp_var_for_tac_50 = hfsq - temp_var_for_tac_49;

      temp_var_for_tac_51 = temp_var_for_tac_50 - f;

      temp_var_for_tac_52 = temp_var_for_tac_45 - temp_var_for_tac_51;

      temp_var_for_ext_8 = temp_var_for_tac_52;
      computeFMul((Addr)&temp_var_for_tac_45,
                  {(Addr)&dk, (Addr) &(temp_var_for_const_22 = ln2_hi)},
                  "/home/shijia/Public/testprogram/e_logf.c_e.c:145:14");
      computeFAdd((Addr)&temp_var_for_tac_46, {(Addr)&hfsq, (Addr)&R},
                  "/home/shijia/Public/testprogram/e_logf.c_e.c:145:45");
      computeFMul((Addr)&temp_var_for_tac_47,
                  {(Addr)&s, (Addr)&temp_var_for_tac_46},
                  "/home/shijia/Public/testprogram/e_logf.c_e.c:145:37");
      computeFMul((Addr)&temp_var_for_tac_48,
                  {(Addr)&dk, (Addr) &(temp_var_for_const_23 = ln2_lo)},
                  "/home/shijia/Public/testprogram/e_logf.c_e.c:145:55");
      computeFAdd((Addr)&temp_var_for_tac_49,
                  {(Addr)&temp_var_for_tac_47, (Addr)&temp_var_for_tac_48},
                  "/home/shijia/Public/testprogram/e_logf.c_e.c:145:50");
      computeFSub((Addr)&temp_var_for_tac_50,
                  {(Addr)&hfsq, (Addr)&temp_var_for_tac_49},
                  "/home/shijia/Public/testprogram/e_logf.c_e.c:145:32");
      computeFSub((Addr)&temp_var_for_tac_51,
                  {(Addr)&temp_var_for_tac_50, (Addr)&f},
                  "/home/shijia/Public/testprogram/e_logf.c_e.c:145:66");
      computeFSub((Addr)&temp_var_for_tac_52,
                  {(Addr)&temp_var_for_tac_45, (Addr)&temp_var_for_tac_51},
                  "/home/shijia/Public/testprogram/e_logf.c_e.c:145:23");
      AssignF({(Addr)&temp_var_for_ext_8}, (Addr)&temp_var_for_tac_52,
              "/home/shijia/Public/testprogram/e_logf.c_e.c:144:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_8;
    }

  } else {
    if (k == 0) {
      float temp_var_for_ext_9;
      float temp_var_for_tac_53, temp_var_for_tac_54, temp_var_for_tac_55;
      temp_var_for_tac_53 = f - R;

      temp_var_for_tac_54 = s * temp_var_for_tac_53;

      temp_var_for_tac_55 = f - temp_var_for_tac_54;

      temp_var_for_ext_9 = temp_var_for_tac_55;
      computeFSub((Addr)&temp_var_for_tac_53, {(Addr)&f, (Addr)&R},
                  "/home/shijia/Public/testprogram/e_logf.c_e.c:155:39");
      computeFMul((Addr)&temp_var_for_tac_54,
                  {(Addr)&s, (Addr)&temp_var_for_tac_53},
                  "/home/shijia/Public/testprogram/e_logf.c_e.c:155:34");
      computeFSub((Addr)&temp_var_for_tac_55,
                  {(Addr)&f, (Addr)&temp_var_for_tac_54},
                  "/home/shijia/Public/testprogram/e_logf.c_e.c:155:30");
      AssignF({(Addr)&temp_var_for_ext_9}, (Addr)&temp_var_for_tac_55,
              "/home/shijia/Public/testprogram/e_logf.c_e.c:155:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_9;
    }

    else {
      float temp_var_for_ext_10;
      float temp_var_for_tac_56, temp_var_for_tac_57, temp_var_for_tac_58,
          temp_var_for_tac_59, temp_var_for_tac_60, temp_var_for_tac_61,
          temp_var_for_tac_62;
      float temp_var_for_const_24, temp_var_for_const_25;
      temp_var_for_tac_56 = dk * ln2_hi;

      temp_var_for_tac_57 = f - R;

      temp_var_for_tac_58 = s * temp_var_for_tac_57;

      temp_var_for_tac_59 = dk * ln2_lo;

      temp_var_for_tac_60 = temp_var_for_tac_58 - temp_var_for_tac_59;

      temp_var_for_tac_61 = temp_var_for_tac_60 - f;

      temp_var_for_tac_62 = temp_var_for_tac_56 - temp_var_for_tac_61;

      temp_var_for_ext_10 = temp_var_for_tac_62;
      computeFMul((Addr)&temp_var_for_tac_56,
                  {(Addr)&dk, (Addr) &(temp_var_for_const_24 = ln2_hi)},
                  "/home/shijia/Public/testprogram/e_logf.c_e.c:164:32");
      computeFSub((Addr)&temp_var_for_tac_57, {(Addr)&f, (Addr)&R},
                  "/home/shijia/Public/testprogram/e_logf.c_e.c:164:52");
      computeFMul((Addr)&temp_var_for_tac_58,
                  {(Addr)&s, (Addr)&temp_var_for_tac_57},
                  "/home/shijia/Public/testprogram/e_logf.c_e.c:164:47");
      computeFMul((Addr)&temp_var_for_tac_59,
                  {(Addr)&dk, (Addr) &(temp_var_for_const_25 = ln2_lo)},
                  "/home/shijia/Public/testprogram/e_logf.c_e.c:164:62");
      computeFSub((Addr)&temp_var_for_tac_60,
                  {(Addr)&temp_var_for_tac_58, (Addr)&temp_var_for_tac_59},
                  "/home/shijia/Public/testprogram/e_logf.c_e.c:164:57");
      computeFSub((Addr)&temp_var_for_tac_61,
                  {(Addr)&temp_var_for_tac_60, (Addr)&f},
                  "/home/shijia/Public/testprogram/e_logf.c_e.c:164:72");
      computeFSub((Addr)&temp_var_for_tac_62,
                  {(Addr)&temp_var_for_tac_56, (Addr)&temp_var_for_tac_61},
                  "/home/shijia/Public/testprogram/e_logf.c_e.c:164:41");
      AssignF({(Addr)&temp_var_for_ext_10}, (Addr)&temp_var_for_tac_62,
              "/home/shijia/Public/testprogram/e_logf.c_e.c:164:27");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_10", (Addr)&temp_var_for_ext_10));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_10;
    }
  }
}

#endif

/* wrapper logf(x) */
float __logf(float x) {
  if (islessequal(x, 0.0f) && _LIB_VERSION != _IEEE_) {
    if (int temp_var_for_tac_63; int temp_var_for_const_26;
        temp_var_for_tac_63 = x == 0.0f;

        ) {
      feraiseexcept(FE_DIVBYZERO);
      float temp_var_for_ext_11;
      float temp_var_for_const_27;
      float temp_var_for_callexp_1;

      temp_var_for_callexp_0 = __builtin_huge_valf();
      temp_var_for_callexp_1 = __kernel_standard_f(
          x, x, (-(temp_var_for_callexp_0)), KMATHERRF_LOG_ZERO);
      temp_var_for_ext_11 = temp_var_for_callexp_1;
      compute((Addr)&temp_var_for_tac_63,
              {(Addr)&x, (Addr) &(temp_var_for_const_26 = 0.0f)},
              "/home/shijia/Public/testprogram/e_logf.c_e.c:178:11");
      AssignF({(Addr)&temp_var_for_ext_11},
              (Addr) &(temp_var_for_const_27 = temp_var_for_callexp_1),
              "/home/shijia/Public/testprogram/e_logf.c_e.c:181:27");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_11", (Addr)&temp_var_for_ext_11));
      callExp++; /*identify the function is  add move tmpShad(0.0 - w*/
retur)n temp_var_for_ext_11;	/* log(0) */
    } else {
      feraiseexcept(FE_INVALID);
      float temp_var_for_ext_12;
      float temp_var_for_const_28;
      float temp_var_for_callexp_2;

      /*embed fun has found*/
      float temp_var_for_callexp_3;

      temp_var_for_callexp_2 = __builtin_nanf("");
      temp_var_for_callexp_3 = __kernel_standard_f(x, x, temp_var_for_callexp_2,
                                                   KMATHERRF_LOG_MINUS);
      temp_var_for_ext_12 = temp_var_for_callexp_3;
      AssignF({(Addr)&temp_var_for_ext_12},
              (Addr) &(temp_var_for_const_28 = temp_var_for_callexp_3),
              "/home/shijia/Public/testprogram/e_logf.c_e.c:190:27");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_12", (Addr)&temp_var_for_ext_12));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_12; /* log(x<0) */
    }
  }

  float temp_var_for_ext_13;
  float temp_var_for_const_29;
  float temp_var_for_callexp_4;

  temp_var_for_callexp_4 = __ieee754_logf(x);
  temp_var_for_ext_13 = temp_var_for_callexp_4;
  AssignF({(Addr)&temp_var_for_ext_13},
          (Addr) &(temp_var_for_const_29 = temp_var_for_callexp_4),
          "/home/shijia/Public/testprogram/e_logf.c_e.c:200:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_13", (Addr)&temp_var_for_ext_13));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_13;
}

__typeof(__logf) logf __attribute__((weak, alias("__logf")));
