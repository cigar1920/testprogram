#include "../ScDebug/scdebug.h"
/* e_logf.c -- float version of e_log.c.
 * Conversion to float by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.
 * adapted for log2 by Ulrich Drepper <drepper@cygnus.com>
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

#ifndef __have_fpu_log2

float __ieee754_log2f(float x) {
  float hfsq, f, s, z, R, w, t1, t2, dk;
  int32_t k, ix, i, j;

  static const float ln2 = 0.69314718055994530942;
  static const float two25 = 3.355443200e+07; /* 0x4c000000 */
  static const float Lg1 = 6.6666668653e-01;  /* 3F2AAAAB */
  static const float Lg2 = 4.0000000596e-01;  /* 3ECCCCCD */
  static const float Lg3 = 2.8571429849e-01;  /* 3E924925 */
  static const float Lg4 = 2.2222198546e-01;  /* 3E638E29 */
  static const float Lg5 = 1.8183572590e-01;  /* 3E3A3325 */
  static const float Lg6 = 1.5313838422e-01;  /* 3E1CD04F */
  static const float Lg7 = 1.4798198640e-01;  /* 3E178897 */

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
                  "/home/shijia/Public/testprogram/e_log2f.c_e.c:45:40");
      computeFDiv((Addr)&temp_var_for_tac_1,
                  {(Addr) &(temp_var_for_const_0 = (-(two25))),
                   (Addr)&temp_var_for_tac_0},
                  "/home/shijia/Public/testprogram/e_log2f.c_e.c:45:35");
      AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_1,
              "/home/shijia/Public/testprogram/e_log2f.c_e.c:45:26");
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
                  "/home/shijia/Public/testprogram/e_log2f.c_e.c:54:31");
      computeFSub((Addr)&temp_var_for_tac_3, {(Addr)&x, (Addr)&x},
                  "/home/shijia/Public/testprogram/e_log2f.c_e.c:54:41");
      computeFDiv((Addr)&temp_var_for_tac_4,
                  {(Addr)&temp_var_for_tac_2, (Addr)&temp_var_for_tac_3},
                  "/home/shijia/Public/testprogram/e_log2f.c_e.c:54:36");
      AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_4,
              "/home/shijia/Public/testprogram/e_log2f.c_e.c:54:26");
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
                "/home/shijia/Public/testprogram/e_log2f.c_e.c:67:28");
    AssignF({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_6,
            "/home/shijia/Public/testprogram/e_log2f.c_e.c:67:24");
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
  float temp_var_for_const_1;
  dk = ((float)k);
  AssignF({(Addr)&dk}, (Addr) &(temp_var_for_const_1 = ((float)k)),
          "/home/shijia/Public/testprogram/e_log2f.c_e.c:78:6");
  ;
  float temp_var_for_tac_7;
  float temp_var_for_const_2;
  temp_var_for_tac_7 = x - ((float)1.0);

  f = temp_var_for_tac_7;
  computeFSub((Addr)&temp_var_for_tac_7,
              {(Addr)&x, (Addr) &(temp_var_for_const_2 = ((float)1.0))},
              "/home/shijia/Public/testprogram/e_log2f.c_e.c:79:9");
  AssignF({(Addr)&f}, (Addr)&temp_var_for_tac_7,
          "/home/shijia/Public/testprogram/e_log2f.c_e.c:79:5");
  ;
  if ((IC(0x007fffff) & (15 + ix)) < 16) { /* |f| < 2**-20 */
    if (int temp_var_for_tac_8; int temp_var_for_const_3;
        temp_var_for_tac_8 = f == zero;

        ) {
      float temp_var_for_ext_3;
      temp_var_for_ext_3 = dk;
      compute((Addr)&temp_var_for_tac_8,
              {(Addr)&f, (Addr) &(temp_var_for_const_3 = zero)},
              "/home/shijia/Public/testprogram/e_log2f.c_e.c:81:11");
      AssignF({(Addr)&temp_var_for_ext_3}, (Addr)&dk,
              "/home/shijia/Public/testprogram/e_log2f.c_e.c:83:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_3;
    }

    float temp_var_for_tac_9, temp_var_for_tac_10, temp_var_for_tac_11,
        temp_var_for_tac_12;
    float temp_var_for_const_4, temp_var_for_const_5;
    temp_var_for_tac_9 = f * f;

    temp_var_for_tac_10 = ((float)0.33333333333333333) * f;

    temp_var_for_tac_11 = ((float)0.5) - temp_var_for_tac_10;

    temp_var_for_tac_12 = temp_var_for_tac_9 * temp_var_for_tac_11;

    R = temp_var_for_tac_12;
    computeFMul((Addr)&temp_var_for_tac_9, {(Addr)&f, (Addr)&f},
                "/home/shijia/Public/testprogram/e_log2f.c_e.c:90:11");
    computeFMul((Addr)&temp_var_for_tac_10,
                {(Addr) &(temp_var_for_const_4 = ((float)0.33333333333333333)),
                 (Addr)&f},
                "/home/shijia/Public/testprogram/e_log2f.c_e.c:90:58");
    computeFSub((Addr)&temp_var_for_tac_11,
                {(Addr) &(temp_var_for_const_5 = ((float)0.5)),
                 (Addr)&temp_var_for_tac_10},
                "/home/shijia/Public/testprogram/e_log2f.c_e.c:90:29");
    computeFMul((Addr)&temp_var_for_tac_12,
                {(Addr)&temp_var_for_tac_9, (Addr)&temp_var_for_tac_11},
                "/home/shijia/Public/testprogram/e_log2f.c_e.c:90:15");
    AssignF({(Addr)&R}, (Addr)&temp_var_for_tac_12,
            "/home/shijia/Public/testprogram/e_log2f.c_e.c:90:7");
    ;
    float temp_var_for_ext_4;
    float temp_var_for_tac_13, temp_var_for_tac_14, temp_var_for_tac_15;
    float temp_var_for_const_6;
    temp_var_for_tac_13 = R - f;

    temp_var_for_tac_14 = temp_var_for_tac_13 / ln2;

    temp_var_for_tac_15 = dk - temp_var_for_tac_14;

    temp_var_for_ext_4 = temp_var_for_tac_15;
    computeFSub((Addr)&temp_var_for_tac_13, {(Addr)&R, (Addr)&f},
                "/home/shijia/Public/testprogram/e_log2f.c_e.c:92:34");
    computeFDiv(
        (Addr)&temp_var_for_tac_14,
        {(Addr)&temp_var_for_tac_13, (Addr) &(temp_var_for_const_6 = ln2)},
        "/home/shijia/Public/testprogram/e_log2f.c_e.c:92:39");
    computeFSub((Addr)&temp_var_for_tac_15,
                {(Addr)&dk, (Addr)&temp_var_for_tac_14},
                "/home/shijia/Public/testprogram/e_log2f.c_e.c:92:29");
    AssignF({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_15,
            "/home/shijia/Public/testprogram/e_log2f.c_e.c:92:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_4;
  }
  float temp_var_for_tac_16, temp_var_for_tac_17;
  float temp_var_for_const_7;
  temp_var_for_tac_16 = ((float)2.0) + f;

  temp_var_for_tac_17 = f / temp_var_for_tac_16;

  s = temp_var_for_tac_17;
  computeFAdd((Addr)&temp_var_for_tac_16,
              {(Addr) &(temp_var_for_const_7 = ((float)2.0)), (Addr)&f},
              "/home/shijia/Public/testprogram/e_log2f.c_e.c:97:23");
  computeFDiv((Addr)&temp_var_for_tac_17,
              {(Addr)&f, (Addr)&temp_var_for_tac_16},
              "/home/shijia/Public/testprogram/e_log2f.c_e.c:97:9");
  AssignF({(Addr)&s}, (Addr)&temp_var_for_tac_17,
          "/home/shijia/Public/testprogram/e_log2f.c_e.c:97:5");
  ;
  float temp_var_for_tac_18;
  temp_var_for_tac_18 = s * s;

  z = temp_var_for_tac_18;
  computeFMul((Addr)&temp_var_for_tac_18, {(Addr)&s, (Addr)&s},
              "/home/shijia/Public/testprogram/e_log2f.c_e.c:98:9");
  AssignF({(Addr)&z}, (Addr)&temp_var_for_tac_18,
          "/home/shijia/Public/testprogram/e_log2f.c_e.c:98:5");
  ;
  i = ix - (IC(0x6147a) << 3);
  float temp_var_for_tac_19;
  temp_var_for_tac_19 = z * z;

  w = temp_var_for_tac_19;
  computeFMul((Addr)&temp_var_for_tac_19, {(Addr)&z, (Addr)&z},
              "/home/shijia/Public/testprogram/e_log2f.c_e.c:100:9");
  AssignF({(Addr)&w}, (Addr)&temp_var_for_tac_19,
          "/home/shijia/Public/testprogram/e_log2f.c_e.c:100:5");
  ;
  j = (IC(0x6b851) << 3) - ix;
  float temp_var_for_tac_20, temp_var_for_tac_21, temp_var_for_tac_22,
      temp_var_for_tac_23, temp_var_for_tac_24;
  float temp_var_for_const_8, temp_var_for_const_9, temp_var_for_const_10;
  temp_var_for_tac_20 = w * Lg6;

  temp_var_for_tac_21 = Lg4 + temp_var_for_tac_20;

  temp_var_for_tac_22 = w * temp_var_for_tac_21;

  temp_var_for_tac_23 = Lg2 + temp_var_for_tac_22;

  temp_var_for_tac_24 = w * temp_var_for_tac_23;

  t1 = temp_var_for_tac_24;
  computeFMul((Addr)&temp_var_for_tac_20,
              {(Addr)&w, (Addr) &(temp_var_for_const_8 = Lg6)},
              "/home/shijia/Public/testprogram/e_log2f.c_e.c:102:32");
  computeFAdd((Addr)&temp_var_for_tac_21, {(Addr) &(temp_var_for_const_9 = Lg4),
                                           (Addr)&temp_var_for_tac_20},
              "/home/shijia/Public/testprogram/e_log2f.c_e.c:102:28");
  computeFMul((Addr)&temp_var_for_tac_22,
              {(Addr)&w, (Addr)&temp_var_for_tac_21},
              "/home/shijia/Public/testprogram/e_log2f.c_e.c:102:21");
  computeFAdd(
      (Addr)&temp_var_for_tac_23,
      {(Addr) &(temp_var_for_const_10 = Lg2), (Addr)&temp_var_for_tac_22},
      "/home/shijia/Public/testprogram/e_log2f.c_e.c:102:17");
  computeFMul((Addr)&temp_var_for_tac_24,
              {(Addr)&w, (Addr)&temp_var_for_tac_23},
              "/home/shijia/Public/testprogram/e_log2f.c_e.c:102:10");
  AssignF({(Addr)&t1}, (Addr)&temp_var_for_tac_24,
          "/home/shijia/Public/testprogram/e_log2f.c_e.c:102:6");
  ;
  float temp_var_for_tac_25, temp_var_for_tac_26, temp_var_for_tac_27,
      temp_var_for_tac_28, temp_var_for_tac_29, temp_var_for_tac_30,
      temp_var_for_tac_31;
  float temp_var_for_const_11, temp_var_for_const_12, temp_var_for_const_13,
      temp_var_for_const_14;
  temp_var_for_tac_25 = w * Lg7;

  temp_var_for_tac_26 = Lg5 + temp_var_for_tac_25;

  temp_var_for_tac_27 = w * temp_var_for_tac_26;

  temp_var_for_tac_28 = Lg3 + temp_var_for_tac_27;

  temp_var_for_tac_29 = w * temp_var_for_tac_28;

  temp_var_for_tac_30 = Lg1 + temp_var_for_tac_29;

  temp_var_for_tac_31 = z * temp_var_for_tac_30;

  t2 = temp_var_for_tac_31;
  computeFMul((Addr)&temp_var_for_tac_25,
              {(Addr)&w, (Addr) &(temp_var_for_const_11 = Lg7)},
              "/home/shijia/Public/testprogram/e_log2f.c_e.c:103:43");
  computeFAdd(
      (Addr)&temp_var_for_tac_26,
      {(Addr) &(temp_var_for_const_12 = Lg5), (Addr)&temp_var_for_tac_25},
      "/home/shijia/Public/testprogram/e_log2f.c_e.c:103:39");
  computeFMul((Addr)&temp_var_for_tac_27,
              {(Addr)&w, (Addr)&temp_var_for_tac_26},
              "/home/shijia/Public/testprogram/e_log2f.c_e.c:103:32");
  computeFAdd(
      (Addr)&temp_var_for_tac_28,
      {(Addr) &(temp_var_for_const_13 = Lg3), (Addr)&temp_var_for_tac_27},
      "/home/shijia/Public/testprogram/e_log2f.c_e.c:103:28");
  computeFMul((Addr)&temp_var_for_tac_29,
              {(Addr)&w, (Addr)&temp_var_for_tac_28},
              "/home/shijia/Public/testprogram/e_log2f.c_e.c:103:21");
  computeFAdd(
      (Addr)&temp_var_for_tac_30,
      {(Addr) &(temp_var_for_const_14 = Lg1), (Addr)&temp_var_for_tac_29},
      "/home/shijia/Public/testprogram/e_log2f.c_e.c:103:17");
  computeFMul((Addr)&temp_var_for_tac_31,
              {(Addr)&z, (Addr)&temp_var_for_tac_30},
              "/home/shijia/Public/testprogram/e_log2f.c_e.c:103:10");
  AssignF({(Addr)&t2}, (Addr)&temp_var_for_tac_31,
          "/home/shijia/Public/testprogram/e_log2f.c_e.c:103:6");
  ;
  i |= j;
  float temp_var_for_tac_32;
  temp_var_for_tac_32 = t2 + t1;

  R = temp_var_for_tac_32;
  computeFAdd((Addr)&temp_var_for_tac_32, {(Addr)&t2, (Addr)&t1},
              "/home/shijia/Public/testprogram/e_log2f.c_e.c:105:10");
  AssignF({(Addr)&R}, (Addr)&temp_var_for_tac_32,
          "/home/shijia/Public/testprogram/e_log2f.c_e.c:105:5");
  ;
  if (i > 0) {
    float temp_var_for_tac_33, temp_var_for_tac_34;
    float temp_var_for_const_15;
    temp_var_for_tac_33 = ((float)0.5) * f;

    temp_var_for_tac_34 = temp_var_for_tac_33 * f;

    hfsq = temp_var_for_tac_34;
    computeFMul((Addr)&temp_var_for_tac_33,
                {(Addr) &(temp_var_for_const_15 = ((float)0.5)), (Addr)&f},
                "/home/shijia/Public/testprogram/e_log2f.c_e.c:107:23");
    computeFMul((Addr)&temp_var_for_tac_34,
                {(Addr)&temp_var_for_tac_33, (Addr)&f},
                "/home/shijia/Public/testprogram/e_log2f.c_e.c:107:27");
    AssignF({(Addr)&hfsq}, (Addr)&temp_var_for_tac_34,
            "/home/shijia/Public/testprogram/e_log2f.c_e.c:107:10");
    ;

    float temp_var_for_ext_5;
    float temp_var_for_tac_35, temp_var_for_tac_36, temp_var_for_tac_37,
        temp_var_for_tac_38, temp_var_for_tac_39, temp_var_for_tac_40;
    float temp_var_for_const_16;
    temp_var_for_tac_35 = hfsq + R;

    temp_var_for_tac_36 = s * temp_var_for_tac_35;

    temp_var_for_tac_37 = hfsq - temp_var_for_tac_36;

    temp_var_for_tac_38 = temp_var_for_tac_37 - f;

    temp_var_for_tac_39 = temp_var_for_tac_38 / ln2;

    temp_var_for_tac_40 = dk - temp_var_for_tac_39;

    temp_var_for_ext_5 = temp_var_for_tac_40;
    computeFAdd((Addr)&temp_var_for_tac_35, {(Addr)&hfsq, (Addr)&R},
                "/home/shijia/Public/testprogram/e_log2f.c_e.c:110:51");
    computeFMul((Addr)&temp_var_for_tac_36,
                {(Addr)&s, (Addr)&temp_var_for_tac_35},
                "/home/shijia/Public/testprogram/e_log2f.c_e.c:110:43");
    computeFSub((Addr)&temp_var_for_tac_37,
                {(Addr)&hfsq, (Addr)&temp_var_for_tac_36},
                "/home/shijia/Public/testprogram/e_log2f.c_e.c:110:38");
    computeFSub((Addr)&temp_var_for_tac_38,
                {(Addr)&temp_var_for_tac_37, (Addr)&f},
                "/home/shijia/Public/testprogram/e_log2f.c_e.c:110:58");
    computeFDiv(
        (Addr)&temp_var_for_tac_39,
        {(Addr)&temp_var_for_tac_38, (Addr) &(temp_var_for_const_16 = ln2)},
        "/home/shijia/Public/testprogram/e_log2f.c_e.c:110:63");
    computeFSub((Addr)&temp_var_for_tac_40,
                {(Addr)&dk, (Addr)&temp_var_for_tac_39},
                "/home/shijia/Public/testprogram/e_log2f.c_e.c:110:29");
    AssignF({(Addr)&temp_var_for_ext_5}, (Addr)&temp_var_for_tac_40,
            "/home/shijia/Public/testprogram/e_log2f.c_e.c:110:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_5;
  } else {
    float temp_var_for_ext_6;
    float temp_var_for_tac_41, temp_var_for_tac_42, temp_var_for_tac_43,
        temp_var_for_tac_44, temp_var_for_tac_45;
    float temp_var_for_const_17;
    temp_var_for_tac_41 = f - R;

    temp_var_for_tac_42 = s * temp_var_for_tac_41;

    temp_var_for_tac_43 = temp_var_for_tac_42 - f;

    temp_var_for_tac_44 = temp_var_for_tac_43 / ln2;

    temp_var_for_tac_45 = dk - temp_var_for_tac_44;

    temp_var_for_ext_6 = temp_var_for_tac_45;
    computeFSub((Addr)&temp_var_for_tac_41, {(Addr)&f, (Addr)&R},
                "/home/shijia/Public/testprogram/e_log2f.c_e.c:116:40");
    computeFMul((Addr)&temp_var_for_tac_42,
                {(Addr)&s, (Addr)&temp_var_for_tac_41},
                "/home/shijia/Public/testprogram/e_log2f.c_e.c:116:35");
    computeFSub((Addr)&temp_var_for_tac_43,
                {(Addr)&temp_var_for_tac_42, (Addr)&f},
                "/home/shijia/Public/testprogram/e_log2f.c_e.c:116:46");
    computeFDiv(
        (Addr)&temp_var_for_tac_44,
        {(Addr)&temp_var_for_tac_43, (Addr) &(temp_var_for_const_17 = ln2)},
        "/home/shijia/Public/testprogram/e_log2f.c_e.c:116:51");
    computeFSub((Addr)&temp_var_for_tac_45,
                {(Addr)&dk, (Addr)&temp_var_for_tac_44},
                "/home/shijia/Public/testprogram/e_log2f.c_e.c:116:29");
    AssignF({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_45,
            "/home/shijia/Public/testprogram/e_log2f.c_e.c:116:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_6;
  }
}

#endif

/* wrapper log2(x) */
float __log2f(float x) {
  if (islessequal(x, 0.0) && _LIB_VERSION != _IEEE_) {
    if (int temp_var_for_tac_46; int temp_var_for_const_18;
        temp_var_for_tac_46 = x == 0.0F;

        ) {
      feraiseexcept(FE_DIVBYZERO);
      float temp_var_for_ext_7;
      float temp_var_for_const_19;
      float temp_var_for_callexp_1;

      temp_var_for_callexp_0 = __builtin_huge_valf();
      temp_var_for_callexp_1 = __kernel_standard_f(
          x, x, (-(temp_var_for_callexp_0)), KMATHERRF_LOG2_ZERO);
      temp_var_for_ext_7 = temp_var_for_callexp_1;
      compute((Addr)&temp_var_for_tac_46,
              {(Addr)&x, (Addr) &(temp_var_for_const_18 = 0.0F)},
              "/home/shijia/Public/testprogram/e_log2f.c_e.c:128:11");
      AssignF({(Addr)&temp_var_for_ext_7},
              (Addr) &(temp_var_for_const_19 = temp_var_for_callexp_1),
              "/home/shijia/Public/testprogram/e_log2f.c_e.c:131:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
      callExp++; /*identify the function is  add move tmpSh(0.0 - dow*/
ret)urn temp_var_for_ext_7;	/* log2(0) */
    } else {
      feraiseexcept(FE_INVALID);
      float temp_var_for_ext_8;
      float temp_var_for_const_20;
      float temp_var_for_callexp_2;

      /*embed fun has found*/
      float temp_var_for_callexp_3;

      temp_var_for_callexp_2 = __builtin_nanf("");
      temp_var_for_callexp_3 = __kernel_standard_f(x, x, temp_var_for_callexp_2,
                                                   KMATHERRF_LOG2_MINUS);
      temp_var_for_ext_8 = temp_var_for_callexp_3;
      AssignF({(Addr)&temp_var_for_ext_8},
              (Addr) &(temp_var_for_const_20 = temp_var_for_callexp_3),
              "/home/shijia/Public/testprogram/e_log2f.c_e.c:140:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_8; /* log2(x<0) */
    }
  }

  float temp_var_for_ext_9;
  float temp_var_for_const_21;
  float temp_var_for_callexp_4;

  temp_var_for_callexp_4 = __ieee754_log2f(x);
  temp_var_for_ext_9 = temp_var_for_callexp_4;
  AssignF({(Addr)&temp_var_for_ext_9},
          (Addr) &(temp_var_for_const_21 = temp_var_for_callexp_4),
          "/home/shijia/Public/testprogram/e_log2f.c_e.c:150:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_9;
}

__typeof(__log2f) log2f __attribute__((weak, alias("__log2f")));
