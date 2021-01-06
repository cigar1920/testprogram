#include "../ScDebug/scdebug.h"
/* s_erff.c -- float version of s_erf.c.
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

float __erff(float x) {
  int32_t hx, ix, i;
  float R, S, P, Q, s, y, z, r;

  static const float tiny = 1e-30;
  static const float one = 1.0000000000e+00; /* 0x3F800000 */
  /* c = (subfloat)0.84506291151 */
  static const float erx = 8.4506291151e-01;  /* 0x3f58560b */
  static const float efx = 1.2837916613e-01;  /* 0x3e0375d4 */
  static const float efx8 = 1.0270333290e+00; /* 0x3f8375d4 */

#include "t_erff.h"

  GET_FLOAT_WORD(hx, x);
  ix = hx & IC(0x7fffffff);
  if (!FLT_UWORD_IS_FINITE(ix)) { /* erf(nan)=nan */
    i = ((uint32_t)hx >> 31) << 1;
    float temp_var_for_ext_0;
    float temp_var_for_tac_0, temp_var_for_tac_1, temp_var_for_tac_2;
    float temp_var_for_const_0, temp_var_for_const_1, temp_var_for_const_2,
        temp_var_for_const_3;
    temp_var_for_tac_0 = 1 - i;

    temp_var_for_tac_1 = one / x;

    temp_var_for_tac_2 = ((float)temp_var_for_tac_0) + temp_var_for_tac_1;

    temp_var_for_ext_0 = temp_var_for_tac_2;
    computeSub((Addr)&temp_var_for_tac_0, {(Addr) &(temp_var_for_const_1 = 1),
                                           (Addr) &(temp_var_for_const_0 = i)},
               "/home/shijia/Public/testprogram/s_erff.c_e.c:38:36");
    computeFDiv((Addr)&temp_var_for_tac_1,
                {(Addr) &(temp_var_for_const_2 = one), (Addr)&x},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:38:47");
    computeFAdd((Addr)&temp_var_for_tac_2,
                {(Addr) &(temp_var_for_const_3 = ((float)temp_var_for_tac_0)),
                 (Addr)&temp_var_for_tac_1},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:38:41");
    AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_2,
            "/home/shijia/Public/testprogram/s_erff.c_e.c:38:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++;                 /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0; /* erf(+-inf)=+-1 */
  }

  if (ix < IC(0x3f580000)) {   /* |x|<0.84375 */
    if (ix < IC(0x31800000)) { /* |x|<2**-28 */
      if (ix < IC(0x04000000))
      /*avoid underflow */
      {
        float temp_var_for_ext_1;
        temp_var_for_ext_1 = float temp_var_for_tac_3, temp_var_for_tac_4,
        temp_var_for_tac_5, temp_var_for_tac_6;
        float temp_var_for_const_4, temp_var_for_const_5, temp_var_for_const_6;
        temp_var_for_tac_3 = 8.0f * x;

        temp_var_for_tac_4 = efx8 * x;

        temp_var_for_tac_5 = temp_var_for_tac_3 + temp_var_for_tac_4;

        temp_var_for_tac_6 = 0.125f * temp_var_for_tac_5;

        ;
        callExpStack.push(
            getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_1;
      }

      float temp_var_for_ext_2;
      float temp_var_for_tac_7, temp_var_for_tac_8;
      float temp_var_for_const_7;
      temp_var_for_tac_7 = efx * x;

      temp_var_for_tac_8 = x + temp_var_for_tac_7;

      temp_var_for_ext_2 = temp_var_for_tac_8;
      computeFMul((Addr)&temp_var_for_tac_3,
                  {(Addr) &(temp_var_for_const_4 = 8.0f), (Addr)&x},
                  "/home/shijia/Public/testprogram/s_erff.c_e.c:50:45");
      computeFMul((Addr)&temp_var_for_tac_4,
                  {(Addr) &(temp_var_for_const_5 = efx8), (Addr)&x},
                  "/home/shijia/Public/testprogram/s_erff.c_e.c:50:56");
      computeFAdd((Addr)&temp_var_for_tac_5,
                  {(Addr)&temp_var_for_tac_3, (Addr)&temp_var_for_tac_4},
                  "/home/shijia/Public/testprogram/s_erff.c_e.c:50:49");
      computeFMul(
          (Addr)&temp_var_for_tac_6,
          {(Addr) &(temp_var_for_const_6 = 0.125f), (Addr)&temp_var_for_tac_5},
          "/home/shijia/Public/testprogram/s_erff.c_e.c:50:37");
      computeFMul((Addr)&temp_var_for_tac_7,
                  {(Addr) &(temp_var_for_const_7 = efx), (Addr)&x},
                  "/home/shijia/Public/testprogram/s_erff.c_e.c:58:36");
      computeFAdd((Addr)&temp_var_for_tac_8,
                  {(Addr)&x, (Addr)&temp_var_for_tac_7},
                  "/home/shijia/Public/testprogram/s_erff.c_e.c:58:30");
      AssignF({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_8,
              "/home/shijia/Public/testprogram/s_erff.c_e.c:58:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_2;
    }
    float temp_var_for_tac_9;
    temp_var_for_tac_9 = x * x;

    z = temp_var_for_tac_9;
    computeFMul((Addr)&temp_var_for_tac_9, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:64:11");
    AssignF({(Addr)&z}, (Addr)&temp_var_for_tac_9,
            "/home/shijia/Public/testprogram/s_erff.c_e.c:64:7");
    ;
    float temp_var_for_tac_10, temp_var_for_tac_11, temp_var_for_tac_12,
        temp_var_for_tac_13, temp_var_for_tac_14, temp_var_for_tac_15,
        temp_var_for_tac_16, temp_var_for_tac_17;
    float temp_var_for_const_8, temp_var_for_const_9, temp_var_for_const_10,
        temp_var_for_const_11, temp_var_for_const_12;
    temp_var_for_tac_10 = z * pp4;

    temp_var_for_tac_11 = pp3 + temp_var_for_tac_10;

    temp_var_for_tac_12 = z * temp_var_for_tac_11;

    temp_var_for_tac_13 = pp2 + temp_var_for_tac_12;

    temp_var_for_tac_14 = z * temp_var_for_tac_13;

    temp_var_for_tac_15 = pp1 + temp_var_for_tac_14;

    temp_var_for_tac_16 = z * temp_var_for_tac_15;

    temp_var_for_tac_17 = pp0 + temp_var_for_tac_16;

    r = temp_var_for_tac_17;
    computeFMul((Addr)&temp_var_for_tac_10,
                {(Addr)&z, (Addr) &(temp_var_for_const_8 = pp4)},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:65:50");
    computeFAdd(
        (Addr)&temp_var_for_tac_11,
        {(Addr) &(temp_var_for_const_9 = pp3), (Addr)&temp_var_for_tac_10},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:65:46");
    computeFMul((Addr)&temp_var_for_tac_12,
                {(Addr)&z, (Addr)&temp_var_for_tac_11},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:65:39");
    computeFAdd(
        (Addr)&temp_var_for_tac_13,
        {(Addr) &(temp_var_for_const_10 = pp2), (Addr)&temp_var_for_tac_12},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:65:35");
    computeFMul((Addr)&temp_var_for_tac_14,
                {(Addr)&z, (Addr)&temp_var_for_tac_13},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:65:28");
    computeFAdd(
        (Addr)&temp_var_for_tac_15,
        {(Addr) &(temp_var_for_const_11 = pp1), (Addr)&temp_var_for_tac_14},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:65:24");
    computeFMul((Addr)&temp_var_for_tac_16,
                {(Addr)&z, (Addr)&temp_var_for_tac_15},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:65:17");
    computeFAdd(
        (Addr)&temp_var_for_tac_17,
        {(Addr) &(temp_var_for_const_12 = pp0), (Addr)&temp_var_for_tac_16},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:65:13");
    AssignF({(Addr)&r}, (Addr)&temp_var_for_tac_17,
            "/home/shijia/Public/testprogram/s_erff.c_e.c:65:7");
    ;
    float temp_var_for_tac_18, temp_var_for_tac_19, temp_var_for_tac_20,
        temp_var_for_tac_21, temp_var_for_tac_22, temp_var_for_tac_23,
        temp_var_for_tac_24, temp_var_for_tac_25, temp_var_for_tac_26,
        temp_var_for_tac_27;
    float temp_var_for_const_13, temp_var_for_const_14, temp_var_for_const_15,
        temp_var_for_const_16, temp_var_for_const_17, temp_var_for_const_18;
    temp_var_for_tac_18 = z * qq5;

    temp_var_for_tac_19 = qq4 + temp_var_for_tac_18;

    temp_var_for_tac_20 = z * temp_var_for_tac_19;

    temp_var_for_tac_21 = qq3 + temp_var_for_tac_20;

    temp_var_for_tac_22 = z * temp_var_for_tac_21;

    temp_var_for_tac_23 = qq2 + temp_var_for_tac_22;

    temp_var_for_tac_24 = z * temp_var_for_tac_23;

    temp_var_for_tac_25 = qq1 + temp_var_for_tac_24;

    temp_var_for_tac_26 = z * temp_var_for_tac_25;

    temp_var_for_tac_27 = one + temp_var_for_tac_26;

    s = temp_var_for_tac_27;
    computeFMul((Addr)&temp_var_for_tac_18,
                {(Addr)&z, (Addr) &(temp_var_for_const_13 = qq5)},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:66:61");
    computeFAdd(
        (Addr)&temp_var_for_tac_19,
        {(Addr) &(temp_var_for_const_14 = qq4), (Addr)&temp_var_for_tac_18},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:66:57");
    computeFMul((Addr)&temp_var_for_tac_20,
                {(Addr)&z, (Addr)&temp_var_for_tac_19},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:66:50");
    computeFAdd(
        (Addr)&temp_var_for_tac_21,
        {(Addr) &(temp_var_for_const_15 = qq3), (Addr)&temp_var_for_tac_20},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:66:46");
    computeFMul((Addr)&temp_var_for_tac_22,
                {(Addr)&z, (Addr)&temp_var_for_tac_21},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:66:39");
    computeFAdd(
        (Addr)&temp_var_for_tac_23,
        {(Addr) &(temp_var_for_const_16 = qq2), (Addr)&temp_var_for_tac_22},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:66:35");
    computeFMul((Addr)&temp_var_for_tac_24,
                {(Addr)&z, (Addr)&temp_var_for_tac_23},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:66:28");
    computeFAdd(
        (Addr)&temp_var_for_tac_25,
        {(Addr) &(temp_var_for_const_17 = qq1), (Addr)&temp_var_for_tac_24},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:66:24");
    computeFMul((Addr)&temp_var_for_tac_26,
                {(Addr)&z, (Addr)&temp_var_for_tac_25},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:66:17");
    computeFAdd(
        (Addr)&temp_var_for_tac_27,
        {(Addr) &(temp_var_for_const_18 = one), (Addr)&temp_var_for_tac_26},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:66:13");
    AssignF({(Addr)&s}, (Addr)&temp_var_for_tac_27,
            "/home/shijia/Public/testprogram/s_erff.c_e.c:66:7");
    ;
    float temp_var_for_tac_28;
    temp_var_for_tac_28 = r / s;

    y = temp_var_for_tac_28;
    computeFDiv((Addr)&temp_var_for_tac_28, {(Addr)&r, (Addr)&s},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:67:11");
    AssignF({(Addr)&y}, (Addr)&temp_var_for_tac_28,
            "/home/shijia/Public/testprogram/s_erff.c_e.c:67:7");
    ;
    float temp_var_for_ext_3;
    float temp_var_for_tac_29, temp_var_for_tac_30;
    temp_var_for_tac_29 = x * y;

    temp_var_for_tac_30 = x + temp_var_for_tac_29;

    temp_var_for_ext_3 = temp_var_for_tac_30;
    computeFMul((Addr)&temp_var_for_tac_29, {(Addr)&x, (Addr)&y},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:69:32");
    computeFAdd((Addr)&temp_var_for_tac_30,
                {(Addr)&x, (Addr)&temp_var_for_tac_29},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:69:28");
    AssignF({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_30,
            "/home/shijia/Public/testprogram/s_erff.c_e.c:69:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_3;
  }
  if (ix < IC(0x3fa00000)) { /* 0.84375 <= |x| < 1.25 */
    float temp_var_for_ext_4;
    float temp_var_for_tac_31;
    float temp_var_for_const_19, temp_var_for_const_20;
    float temp_var_for_callexp_0;

    temp_var_for_callexp_0 = fabsf(x);
    temp_var_for_tac_31 = temp_var_for_callexp_0 - one;

    temp_var_for_ext_4 = temp_var_for_tac_31;
    computeFSub((Addr)&temp_var_for_tac_31,
                {(Addr) &(temp_var_for_const_20 = temp_var_for_callexp_0),
                 (Addr) &(temp_var_for_const_19 = one)},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:76:45");
    AssignF({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_31,
            "/home/shijia/Public/testprogram/s_erff.c_e.c:76:24");
    ; // s
    /*(s)(r)(3)(e)(t)(3)(e)(one)(__ieee754_fabsf(x))*/
    s = temp_var_for_ext_4;
    AssignF({(Addr)&s}, (Addr)&temp_var_for_ext_4,
            "/home/shijia/Public/testprogram/s_erff.c_e.c:78:7");
    ;
    float temp_var_for_tac_32, temp_var_for_tac_33, temp_var_for_tac_34,
        temp_var_for_tac_35, temp_var_for_tac_36, temp_var_for_tac_37,
        temp_var_for_tac_38, temp_var_for_tac_39, temp_var_for_tac_40,
        temp_var_for_tac_41, temp_var_for_tac_42, temp_var_for_tac_43;
    float temp_var_for_const_21, temp_var_for_const_22, temp_var_for_const_23,
        temp_var_for_const_24, temp_var_for_const_25, temp_var_for_const_26,
        temp_var_for_const_27;
    temp_var_for_tac_32 = s * pa6;

    temp_var_for_tac_33 = pa5 + temp_var_for_tac_32;

    temp_var_for_tac_34 = s * temp_var_for_tac_33;

    temp_var_for_tac_35 = pa4 + temp_var_for_tac_34;

    temp_var_for_tac_36 = s * temp_var_for_tac_35;

    temp_var_for_tac_37 = pa3 + temp_var_for_tac_36;

    temp_var_for_tac_38 = s * temp_var_for_tac_37;

    temp_var_for_tac_39 = pa2 + temp_var_for_tac_38;

    temp_var_for_tac_40 = s * temp_var_for_tac_39;

    temp_var_for_tac_41 = pa1 + temp_var_for_tac_40;

    temp_var_for_tac_42 = s * temp_var_for_tac_41;

    temp_var_for_tac_43 = pa0 + temp_var_for_tac_42;

    P = temp_var_for_tac_43;
    computeFMul((Addr)&temp_var_for_tac_32,
                {(Addr)&s, (Addr) &(temp_var_for_const_21 = pa6)},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:80:66");
    computeFAdd(
        (Addr)&temp_var_for_tac_33,
        {(Addr) &(temp_var_for_const_22 = pa5), (Addr)&temp_var_for_tac_32},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:80:62");
    computeFMul((Addr)&temp_var_for_tac_34,
                {(Addr)&s, (Addr)&temp_var_for_tac_33},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:80:55");
    computeFAdd(
        (Addr)&temp_var_for_tac_35,
        {(Addr) &(temp_var_for_const_23 = pa4), (Addr)&temp_var_for_tac_34},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:80:51");
    computeFMul((Addr)&temp_var_for_tac_36,
                {(Addr)&s, (Addr)&temp_var_for_tac_35},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:80:44");
    computeFAdd(
        (Addr)&temp_var_for_tac_37,
        {(Addr) &(temp_var_for_const_24 = pa3), (Addr)&temp_var_for_tac_36},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:80:40");
    computeFMul((Addr)&temp_var_for_tac_38,
                {(Addr)&s, (Addr)&temp_var_for_tac_37},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:80:33");
    computeFAdd(
        (Addr)&temp_var_for_tac_39,
        {(Addr) &(temp_var_for_const_25 = pa2), (Addr)&temp_var_for_tac_38},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:80:29");
    computeFMul((Addr)&temp_var_for_tac_40,
                {(Addr)&s, (Addr)&temp_var_for_tac_39},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:80:22");
    computeFAdd(
        (Addr)&temp_var_for_tac_41,
        {(Addr) &(temp_var_for_const_26 = pa1), (Addr)&temp_var_for_tac_40},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:80:18");
    computeFMul((Addr)&temp_var_for_tac_42,
                {(Addr)&s, (Addr)&temp_var_for_tac_41},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:80:11");
    computeFAdd(
        (Addr)&temp_var_for_tac_43,
        {(Addr) &(temp_var_for_const_27 = pa0), (Addr)&temp_var_for_tac_42},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:79:13");
    AssignF({(Addr)&P}, (Addr)&temp_var_for_tac_43,
            "/home/shijia/Public/testprogram/s_erff.c_e.c:79:7");
    ;
    float temp_var_for_tac_44, temp_var_for_tac_45, temp_var_for_tac_46,
        temp_var_for_tac_47, temp_var_for_tac_48, temp_var_for_tac_49,
        temp_var_for_tac_50, temp_var_for_tac_51, temp_var_for_tac_52,
        temp_var_for_tac_53, temp_var_for_tac_54, temp_var_for_tac_55;
    float temp_var_for_const_28, temp_var_for_const_29, temp_var_for_const_30,
        temp_var_for_const_31, temp_var_for_const_32, temp_var_for_const_33,
        temp_var_for_const_34;
    temp_var_for_tac_44 = s * qa6;

    temp_var_for_tac_45 = qa5 + temp_var_for_tac_44;

    temp_var_for_tac_46 = s * temp_var_for_tac_45;

    temp_var_for_tac_47 = qa4 + temp_var_for_tac_46;

    temp_var_for_tac_48 = s * temp_var_for_tac_47;

    temp_var_for_tac_49 = qa3 + temp_var_for_tac_48;

    temp_var_for_tac_50 = s * temp_var_for_tac_49;

    temp_var_for_tac_51 = qa2 + temp_var_for_tac_50;

    temp_var_for_tac_52 = s * temp_var_for_tac_51;

    temp_var_for_tac_53 = qa1 + temp_var_for_tac_52;

    temp_var_for_tac_54 = s * temp_var_for_tac_53;

    temp_var_for_tac_55 = one + temp_var_for_tac_54;

    Q = temp_var_for_tac_55;
    computeFMul((Addr)&temp_var_for_tac_44,
                {(Addr)&s, (Addr) &(temp_var_for_const_28 = qa6)},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:82:66");
    computeFAdd(
        (Addr)&temp_var_for_tac_45,
        {(Addr) &(temp_var_for_const_29 = qa5), (Addr)&temp_var_for_tac_44},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:82:62");
    computeFMul((Addr)&temp_var_for_tac_46,
                {(Addr)&s, (Addr)&temp_var_for_tac_45},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:82:55");
    computeFAdd(
        (Addr)&temp_var_for_tac_47,
        {(Addr) &(temp_var_for_const_30 = qa4), (Addr)&temp_var_for_tac_46},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:82:51");
    computeFMul((Addr)&temp_var_for_tac_48,
                {(Addr)&s, (Addr)&temp_var_for_tac_47},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:82:44");
    computeFAdd(
        (Addr)&temp_var_for_tac_49,
        {(Addr) &(temp_var_for_const_31 = qa3), (Addr)&temp_var_for_tac_48},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:82:40");
    computeFMul((Addr)&temp_var_for_tac_50,
                {(Addr)&s, (Addr)&temp_var_for_tac_49},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:82:33");
    computeFAdd(
        (Addr)&temp_var_for_tac_51,
        {(Addr) &(temp_var_for_const_32 = qa2), (Addr)&temp_var_for_tac_50},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:82:29");
    computeFMul((Addr)&temp_var_for_tac_52,
                {(Addr)&s, (Addr)&temp_var_for_tac_51},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:82:22");
    computeFAdd(
        (Addr)&temp_var_for_tac_53,
        {(Addr) &(temp_var_for_const_33 = qa1), (Addr)&temp_var_for_tac_52},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:82:18");
    computeFMul((Addr)&temp_var_for_tac_54,
                {(Addr)&s, (Addr)&temp_var_for_tac_53},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:82:11");
    computeFAdd(
        (Addr)&temp_var_for_tac_55,
        {(Addr) &(temp_var_for_const_34 = one), (Addr)&temp_var_for_tac_54},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:81:13");
    AssignF({(Addr)&Q}, (Addr)&temp_var_for_tac_55,
            "/home/shijia/Public/testprogram/s_erff.c_e.c:81:7");
    ;
    if (hx >= 0) {
      float temp_var_for_ext_5;
      float temp_var_for_tac_56, temp_var_for_tac_57;
      float temp_var_for_const_35;
      temp_var_for_tac_56 = P / Q;

      temp_var_for_tac_57 = erx + temp_var_for_tac_56;

      temp_var_for_ext_5 = temp_var_for_tac_57;
      computeFDiv((Addr)&temp_var_for_tac_56, {(Addr)&P, (Addr)&Q},
                  "/home/shijia/Public/testprogram/s_erff.c_e.c:85:36");
      computeFAdd(
          (Addr)&temp_var_for_tac_57,
          {(Addr) &(temp_var_for_const_35 = erx), (Addr)&temp_var_for_tac_56},
          "/home/shijia/Public/testprogram/s_erff.c_e.c:85:32");
      AssignF({(Addr)&temp_var_for_ext_5}, (Addr)&temp_var_for_tac_57,
              "/home/shijia/Public/testprogram/s_erff.c_e.c:85:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_5;
    }

    else {
      float temp_var_for_ext_6;
      float temp_var_for_tac_58, temp_var_for_tac_59;
      float temp_var_for_const_36;
      temp_var_for_tac_58 = P / Q;

      temp_var_for_tac_59 = (-(erx)) - temp_var_for_tac_58;

      temp_var_for_ext_6 = temp_var_for_tac_59;
      computeFDiv((Addr)&temp_var_for_tac_58, {(Addr)&P, (Addr)&Q},
                  "/home/shijia/Public/testprogram/s_erff.c_e.c:94:37");
      computeFSub((Addr)&temp_var_for_tac_59,
                  {(Addr) &(temp_var_for_const_36 = (-(erx))),
                   (Addr)&temp_var_for_tac_58},
                  "/home/shijia/Public/testprogram/s_erff.c_e.c:94:33");
      AssignF({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_59,
              "/home/shijia/Public/testprogram/s_erff.c_e.c:94:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
      callExp++; /*identify the function is  add move tmpShadow*/
      return (0.0 - r_f)or_ext_6;
    }
  }
  if (ix >= IC(0x40c00000)) { /* inf>|x|>=6 */
    if (hx >= 0) {
      float temp_var_for_ext_7;
      float temp_var_for_tac_60;
      float temp_var_for_const_37, temp_var_for_const_38;
      temp_var_for_tac_60 = one - tiny;

      temp_var_for_ext_7 = temp_var_for_tac_60;
      computeFSub((Addr)&temp_var_for_tac_60,
                  {(Addr) &(temp_var_for_const_38 = one),
                   (Addr) &(temp_var_for_const_37 = tiny)},
                  "/home/shijia/Public/testprogram/s_erff.c_e.c:104:32");
      AssignF({(Addr)&temp_var_for_ext_7}, (Addr)&temp_var_for_tac_60,
              "/home/shijia/Public/testprogram/s_erff.c_e.c:104:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_7;
    }

    else {
      float temp_var_for_ext_8;
      float temp_var_for_tac_61;
      float temp_var_for_const_39, temp_var_for_const_40;
      temp_var_for_tac_61 = tiny - one;

      temp_var_for_ext_8 = temp_var_for_tac_61;
      computeFSub((Addr)&temp_var_for_tac_61,
                  {(Addr) &(temp_var_for_const_40 = tiny),
                   (Addr) &(temp_var_for_const_39 = one)},
                  "/home/shijia/Public/testprogram/s_erff.c_e.c:113:33");
      AssignF({(Addr)&temp_var_for_ext_8}, (Addr)&temp_var_for_tac_61,
              "/home/shijia/Public/testprogram/s_erff.c_e.c:113:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_8;
    }
  }
  float temp_var_for_ext_9;
  float temp_var_for_const_41;
  float temp_var_for_callexp_1;

  temp_var_for_callexp_1 = fabsf(x);
  temp_var_for_ext_9 = temp_var_for_callexp_1;
  AssignF({(Addr)&temp_var_for_ext_9},
          (Addr) &(temp_var_for_const_41 = temp_var_for_callexp_1),
          "/home/shijia/Public/testprogram/s_erff.c_e.c:121:22");
  ; // x
  /*(qa6)(s)(qa5)(s)(qa4)(s)(qa3)(s)(qa2)(s)(qa1)(s)(one)(qa6)(s)(qa5)(s)(qa4)(s)(qa3)(s)(qa2)(s)(qa1)(s)(qa6)(s)(qa5)(s)(qa4)(s)(qa3)(s)(qa2)(s)(qa1)(qa6)(s)(qa5)(s)(qa4)(s)(qa3)(s)(qa2)(s)(qa6)(s)(qa5)(s)(qa4)(s)(qa3)(s)(qa2)(qa6)(s)(qa5)(s)(qa4)(s)(qa3)(s)(qa6)(s)(qa5)(s)(qa4)(s)(qa3)(qa6)(s)(qa5)(s)(qa4)(s)(qa6)(s)(qa5)(s)(qa4)(qa6)(s)(qa5)(s)(qa6)(s)(qa5)(qa6)(s)(5)(e)(tem)(5)(e)(6)(e)(r_f)(r_f)(6)(e)(xt_7)(tem)(t_8)(temp)(__ieee754_fabsf(x))*/
  x = temp_var_for_ext_9;
  AssignF({(Addr)&x}, (Addr)&temp_var_for_ext_9,
          "/home/shijia/Public/testprogram/s_erff.c_e.c:123:5");
  ;
  float temp_var_for_tac_62, temp_var_for_tac_63;
  float temp_var_for_const_42;
  temp_var_for_tac_62 = x * x;

  temp_var_for_tac_63 = one / temp_var_for_tac_62;

  s = temp_var_for_tac_63;
  computeFMul((Addr)&temp_var_for_tac_62, {(Addr)&x, (Addr)&x},
              "/home/shijia/Public/testprogram/s_erff.c_e.c:124:16");
  computeFDiv(
      (Addr)&temp_var_for_tac_63,
      {(Addr) &(temp_var_for_const_42 = one), (Addr)&temp_var_for_tac_62},
      "/home/shijia/Public/testprogram/s_erff.c_e.c:124:11");
  AssignF({(Addr)&s}, (Addr)&temp_var_for_tac_63,
          "/home/shijia/Public/testprogram/s_erff.c_e.c:124:5");
  ;
  if (ix < IC(0x4036DB6E)) { /* |x| < 1/0.35 */
    float temp_var_for_tac_64, temp_var_for_tac_65, temp_var_for_tac_66,
        temp_var_for_tac_67, temp_var_for_tac_68, temp_var_for_tac_69,
        temp_var_for_tac_70, temp_var_for_tac_71, temp_var_for_tac_72,
        temp_var_for_tac_73, temp_var_for_tac_74, temp_var_for_tac_75,
        temp_var_for_tac_76, temp_var_for_tac_77;
    float temp_var_for_const_43, temp_var_for_const_44, temp_var_for_const_45,
        temp_var_for_const_46, temp_var_for_const_47, temp_var_for_const_48,
        temp_var_for_const_49, temp_var_for_const_50;
    temp_var_for_tac_64 = s * ra7;

    temp_var_for_tac_65 = ra6 + temp_var_for_tac_64;

    temp_var_for_tac_66 = s * temp_var_for_tac_65;

    temp_var_for_tac_67 = ra5 + temp_var_for_tac_66;

    temp_var_for_tac_68 = s * temp_var_for_tac_67;

    temp_var_for_tac_69 = ra4 + temp_var_for_tac_68;

    temp_var_for_tac_70 = s * temp_var_for_tac_69;

    temp_var_for_tac_71 = ra3 + temp_var_for_tac_70;

    temp_var_for_tac_72 = s * temp_var_for_tac_71;

    temp_var_for_tac_73 = ra2 + temp_var_for_tac_72;

    temp_var_for_tac_74 = s * temp_var_for_tac_73;

    temp_var_for_tac_75 = ra1 + temp_var_for_tac_74;

    temp_var_for_tac_76 = s * temp_var_for_tac_75;

    temp_var_for_tac_77 = ra0 + temp_var_for_tac_76;

    R = temp_var_for_tac_77;
    computeFMul((Addr)&temp_var_for_tac_64,
                {(Addr)&s, (Addr) &(temp_var_for_const_43 = ra7)},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:129:65");
    computeFAdd(
        (Addr)&temp_var_for_tac_65,
        {(Addr) &(temp_var_for_const_44 = ra6), (Addr)&temp_var_for_tac_64},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:129:61");
    computeFMul((Addr)&temp_var_for_tac_66,
                {(Addr)&s, (Addr)&temp_var_for_tac_65},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:129:54");
    computeFAdd(
        (Addr)&temp_var_for_tac_67,
        {(Addr) &(temp_var_for_const_45 = ra5), (Addr)&temp_var_for_tac_66},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:129:50");
    computeFMul((Addr)&temp_var_for_tac_68,
                {(Addr)&s, (Addr)&temp_var_for_tac_67},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:129:43");
    computeFAdd(
        (Addr)&temp_var_for_tac_69,
        {(Addr) &(temp_var_for_const_46 = ra4), (Addr)&temp_var_for_tac_68},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:129:39");
    computeFMul((Addr)&temp_var_for_tac_70,
                {(Addr)&s, (Addr)&temp_var_for_tac_69},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:129:32");
    computeFAdd(
        (Addr)&temp_var_for_tac_71,
        {(Addr) &(temp_var_for_const_47 = ra3), (Addr)&temp_var_for_tac_70},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:129:28");
    computeFMul((Addr)&temp_var_for_tac_72,
                {(Addr)&s, (Addr)&temp_var_for_tac_71},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:129:21");
    computeFAdd(
        (Addr)&temp_var_for_tac_73,
        {(Addr) &(temp_var_for_const_48 = ra2), (Addr)&temp_var_for_tac_72},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:128:23");
    computeFMul((Addr)&temp_var_for_tac_74,
                {(Addr)&s, (Addr)&temp_var_for_tac_73},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:128:16");
    computeFAdd(
        (Addr)&temp_var_for_tac_75,
        {(Addr) &(temp_var_for_const_49 = ra1), (Addr)&temp_var_for_tac_74},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:127:18");
    computeFMul((Addr)&temp_var_for_tac_76,
                {(Addr)&s, (Addr)&temp_var_for_tac_75},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:127:11");
    computeFAdd(
        (Addr)&temp_var_for_tac_77,
        {(Addr) &(temp_var_for_const_50 = ra0), (Addr)&temp_var_for_tac_76},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:126:13");
    AssignF({(Addr)&R}, (Addr)&temp_var_for_tac_77,
            "/home/shijia/Public/testprogram/s_erff.c_e.c:126:7");
    ;
    float temp_var_for_tac_78, temp_var_for_tac_79, temp_var_for_tac_80,
        temp_var_for_tac_81, temp_var_for_tac_82, temp_var_for_tac_83,
        temp_var_for_tac_84, temp_var_for_tac_85, temp_var_for_tac_86,
        temp_var_for_tac_87, temp_var_for_tac_88, temp_var_for_tac_89,
        temp_var_for_tac_90, temp_var_for_tac_91, temp_var_for_tac_92,
        temp_var_for_tac_93;
    float temp_var_for_const_51, temp_var_for_const_52, temp_var_for_const_53,
        temp_var_for_const_54, temp_var_for_const_55, temp_var_for_const_56,
        temp_var_for_const_57, temp_var_for_const_58, temp_var_for_const_59;
    temp_var_for_tac_78 = s * sa8;

    temp_var_for_tac_79 = sa7 + temp_var_for_tac_78;

    temp_var_for_tac_80 = s * temp_var_for_tac_79;

    temp_var_for_tac_81 = sa6 + temp_var_for_tac_80;

    temp_var_for_tac_82 = s * temp_var_for_tac_81;

    temp_var_for_tac_83 = sa5 + temp_var_for_tac_82;

    temp_var_for_tac_84 = s * temp_var_for_tac_83;

    temp_var_for_tac_85 = sa4 + temp_var_for_tac_84;

    temp_var_for_tac_86 = s * temp_var_for_tac_85;

    temp_var_for_tac_87 = sa3 + temp_var_for_tac_86;

    temp_var_for_tac_88 = s * temp_var_for_tac_87;

    temp_var_for_tac_89 = sa2 + temp_var_for_tac_88;

    temp_var_for_tac_90 = s * temp_var_for_tac_89;

    temp_var_for_tac_91 = sa1 + temp_var_for_tac_90;

    temp_var_for_tac_92 = s * temp_var_for_tac_91;

    temp_var_for_tac_93 = one + temp_var_for_tac_92;

    S = temp_var_for_tac_93;
    computeFMul((Addr)&temp_var_for_tac_78,
                {(Addr)&s, (Addr) &(temp_var_for_const_51 = sa8)},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:135:64");
    computeFAdd(
        (Addr)&temp_var_for_tac_79,
        {(Addr) &(temp_var_for_const_52 = sa7), (Addr)&temp_var_for_tac_78},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:135:60");
    computeFMul((Addr)&temp_var_for_tac_80,
                {(Addr)&s, (Addr)&temp_var_for_tac_79},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:135:53");
    computeFAdd(
        (Addr)&temp_var_for_tac_81,
        {(Addr) &(temp_var_for_const_53 = sa6), (Addr)&temp_var_for_tac_80},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:135:49");
    computeFMul((Addr)&temp_var_for_tac_82,
                {(Addr)&s, (Addr)&temp_var_for_tac_81},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:135:42");
    computeFAdd(
        (Addr)&temp_var_for_tac_83,
        {(Addr) &(temp_var_for_const_54 = sa5), (Addr)&temp_var_for_tac_82},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:135:38");
    computeFMul((Addr)&temp_var_for_tac_84,
                {(Addr)&s, (Addr)&temp_var_for_tac_83},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:135:31");
    computeFAdd(
        (Addr)&temp_var_for_tac_85,
        {(Addr) &(temp_var_for_const_55 = sa4), (Addr)&temp_var_for_tac_84},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:134:33");
    computeFMul((Addr)&temp_var_for_tac_86,
                {(Addr)&s, (Addr)&temp_var_for_tac_85},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:134:26");
    computeFAdd(
        (Addr)&temp_var_for_tac_87,
        {(Addr) &(temp_var_for_const_56 = sa3), (Addr)&temp_var_for_tac_86},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:133:28");
    computeFMul((Addr)&temp_var_for_tac_88,
                {(Addr)&s, (Addr)&temp_var_for_tac_87},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:133:21");
    computeFAdd(
        (Addr)&temp_var_for_tac_89,
        {(Addr) &(temp_var_for_const_57 = sa2), (Addr)&temp_var_for_tac_88},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:132:23");
    computeFMul((Addr)&temp_var_for_tac_90,
                {(Addr)&s, (Addr)&temp_var_for_tac_89},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:132:16");
    computeFAdd(
        (Addr)&temp_var_for_tac_91,
        {(Addr) &(temp_var_for_const_58 = sa1), (Addr)&temp_var_for_tac_90},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:131:18");
    computeFMul((Addr)&temp_var_for_tac_92,
                {(Addr)&s, (Addr)&temp_var_for_tac_91},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:131:11");
    computeFAdd(
        (Addr)&temp_var_for_tac_93,
        {(Addr) &(temp_var_for_const_59 = one), (Addr)&temp_var_for_tac_92},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:130:13");
    AssignF({(Addr)&S}, (Addr)&temp_var_for_tac_93,
            "/home/shijia/Public/testprogram/s_erff.c_e.c:130:7");
    ;
  } else { /* |x| >= 1/0.35 */
    float temp_var_for_tac_94, temp_var_for_tac_95, temp_var_for_tac_96,
        temp_var_for_tac_97, temp_var_for_tac_98, temp_var_for_tac_99,
        temp_var_for_tac_100, temp_var_for_tac_101, temp_var_for_tac_102,
        temp_var_for_tac_103, temp_var_for_tac_104, temp_var_for_tac_105;
    float temp_var_for_const_60, temp_var_for_const_61, temp_var_for_const_62,
        temp_var_for_const_63, temp_var_for_const_64, temp_var_for_const_65,
        temp_var_for_const_66;
    temp_var_for_tac_94 = s * rb6;

    temp_var_for_tac_95 = rb5 + temp_var_for_tac_94;

    temp_var_for_tac_96 = s * temp_var_for_tac_95;

    temp_var_for_tac_97 = rb4 + temp_var_for_tac_96;

    temp_var_for_tac_98 = s * temp_var_for_tac_97;

    temp_var_for_tac_99 = rb3 + temp_var_for_tac_98;

    temp_var_for_tac_100 = s * temp_var_for_tac_99;

    temp_var_for_tac_101 = rb2 + temp_var_for_tac_100;

    temp_var_for_tac_102 = s * temp_var_for_tac_101;

    temp_var_for_tac_103 = rb1 + temp_var_for_tac_102;

    temp_var_for_tac_104 = s * temp_var_for_tac_103;

    temp_var_for_tac_105 = rb0 + temp_var_for_tac_104;

    R = temp_var_for_tac_105;
    computeFMul((Addr)&temp_var_for_tac_94,
                {(Addr)&s, (Addr) &(temp_var_for_const_60 = rb6)},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:138:66");
    computeFAdd(
        (Addr)&temp_var_for_tac_95,
        {(Addr) &(temp_var_for_const_61 = rb5), (Addr)&temp_var_for_tac_94},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:138:62");
    computeFMul((Addr)&temp_var_for_tac_96,
                {(Addr)&s, (Addr)&temp_var_for_tac_95},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:138:55");
    computeFAdd(
        (Addr)&temp_var_for_tac_97,
        {(Addr) &(temp_var_for_const_62 = rb4), (Addr)&temp_var_for_tac_96},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:138:51");
    computeFMul((Addr)&temp_var_for_tac_98,
                {(Addr)&s, (Addr)&temp_var_for_tac_97},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:138:44");
    computeFAdd(
        (Addr)&temp_var_for_tac_99,
        {(Addr) &(temp_var_for_const_63 = rb3), (Addr)&temp_var_for_tac_98},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:138:40");
    computeFMul((Addr)&temp_var_for_tac_100,
                {(Addr)&s, (Addr)&temp_var_for_tac_99},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:138:33");
    computeFAdd(
        (Addr)&temp_var_for_tac_101,
        {(Addr) &(temp_var_for_const_64 = rb2), (Addr)&temp_var_for_tac_100},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:138:29");
    computeFMul((Addr)&temp_var_for_tac_102,
                {(Addr)&s, (Addr)&temp_var_for_tac_101},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:138:22");
    computeFAdd(
        (Addr)&temp_var_for_tac_103,
        {(Addr) &(temp_var_for_const_65 = rb1), (Addr)&temp_var_for_tac_102},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:138:18");
    computeFMul((Addr)&temp_var_for_tac_104,
                {(Addr)&s, (Addr)&temp_var_for_tac_103},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:138:11");
    computeFAdd(
        (Addr)&temp_var_for_tac_105,
        {(Addr) &(temp_var_for_const_66 = rb0), (Addr)&temp_var_for_tac_104},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:137:13");
    AssignF({(Addr)&R}, (Addr)&temp_var_for_tac_105,
            "/home/shijia/Public/testprogram/s_erff.c_e.c:137:7");
    ;
    float temp_var_for_tac_106, temp_var_for_tac_107, temp_var_for_tac_108,
        temp_var_for_tac_109, temp_var_for_tac_110, temp_var_for_tac_111,
        temp_var_for_tac_112, temp_var_for_tac_113, temp_var_for_tac_114,
        temp_var_for_tac_115, temp_var_for_tac_116, temp_var_for_tac_117,
        temp_var_for_tac_118, temp_var_for_tac_119;
    float temp_var_for_const_67, temp_var_for_const_68, temp_var_for_const_69,
        temp_var_for_const_70, temp_var_for_const_71, temp_var_for_const_72,
        temp_var_for_const_73, temp_var_for_const_74;
    temp_var_for_tac_106 = s * sb7;

    temp_var_for_tac_107 = sb6 + temp_var_for_tac_106;

    temp_var_for_tac_108 = s * temp_var_for_tac_107;

    temp_var_for_tac_109 = sb5 + temp_var_for_tac_108;

    temp_var_for_tac_110 = s * temp_var_for_tac_109;

    temp_var_for_tac_111 = sb4 + temp_var_for_tac_110;

    temp_var_for_tac_112 = s * temp_var_for_tac_111;

    temp_var_for_tac_113 = sb3 + temp_var_for_tac_112;

    temp_var_for_tac_114 = s * temp_var_for_tac_113;

    temp_var_for_tac_115 = sb2 + temp_var_for_tac_114;

    temp_var_for_tac_116 = s * temp_var_for_tac_115;

    temp_var_for_tac_117 = sb1 + temp_var_for_tac_116;

    temp_var_for_tac_118 = s * temp_var_for_tac_117;

    temp_var_for_tac_119 = one + temp_var_for_tac_118;

    S = temp_var_for_tac_119;
    computeFMul((Addr)&temp_var_for_tac_106,
                {(Addr)&s, (Addr) &(temp_var_for_const_67 = sb7)},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:142:65");
    computeFAdd(
        (Addr)&temp_var_for_tac_107,
        {(Addr) &(temp_var_for_const_68 = sb6), (Addr)&temp_var_for_tac_106},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:142:61");
    computeFMul((Addr)&temp_var_for_tac_108,
                {(Addr)&s, (Addr)&temp_var_for_tac_107},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:142:54");
    computeFAdd(
        (Addr)&temp_var_for_tac_109,
        {(Addr) &(temp_var_for_const_69 = sb5), (Addr)&temp_var_for_tac_108},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:142:50");
    computeFMul((Addr)&temp_var_for_tac_110,
                {(Addr)&s, (Addr)&temp_var_for_tac_109},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:142:43");
    computeFAdd(
        (Addr)&temp_var_for_tac_111,
        {(Addr) &(temp_var_for_const_70 = sb4), (Addr)&temp_var_for_tac_110},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:142:39");
    computeFMul((Addr)&temp_var_for_tac_112,
                {(Addr)&s, (Addr)&temp_var_for_tac_111},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:142:32");
    computeFAdd(
        (Addr)&temp_var_for_tac_113,
        {(Addr) &(temp_var_for_const_71 = sb3), (Addr)&temp_var_for_tac_112},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:142:28");
    computeFMul((Addr)&temp_var_for_tac_114,
                {(Addr)&s, (Addr)&temp_var_for_tac_113},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:142:21");
    computeFAdd(
        (Addr)&temp_var_for_tac_115,
        {(Addr) &(temp_var_for_const_72 = sb2), (Addr)&temp_var_for_tac_114},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:141:23");
    computeFMul((Addr)&temp_var_for_tac_116,
                {(Addr)&s, (Addr)&temp_var_for_tac_115},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:141:16");
    computeFAdd(
        (Addr)&temp_var_for_tac_117,
        {(Addr) &(temp_var_for_const_73 = sb1), (Addr)&temp_var_for_tac_116},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:140:18");
    computeFMul((Addr)&temp_var_for_tac_118,
                {(Addr)&s, (Addr)&temp_var_for_tac_117},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:140:11");
    computeFAdd(
        (Addr)&temp_var_for_tac_119,
        {(Addr) &(temp_var_for_const_74 = one), (Addr)&temp_var_for_tac_118},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:139:13");
    AssignF({(Addr)&S}, (Addr)&temp_var_for_tac_119,
            "/home/shijia/Public/testprogram/s_erff.c_e.c:139:7");
    ;
  }
  GET_FLOAT_WORD(ix, x);
  SET_FLOAT_WORD(z, ix & UC(0xfffff000));
  float temp_var_for_tac_120, temp_var_for_tac_121, temp_var_for_tac_122,
      temp_var_for_tac_123, temp_var_for_tac_124, temp_var_for_tac_125,
      temp_var_for_tac_126, temp_var_for_tac_127, temp_var_for_tac_128;
  float temp_var_for_const_75, temp_var_for_const_76, temp_var_for_const_77,
      temp_var_for_const_78;
  float temp_var_for_callexp_2;

  float temp_var_for_callexp_3;

  temp_var_for_tac_120 = 0.0 - z;

  temp_var_for_tac_121 = temp_var_for_tac_120 * z;

  temp_var_for_tac_122 = temp_var_for_tac_121 - 0.5625f;

  temp_var_for_callexp_2 = __ieee754_expf(temp_var_for_tac_122);
  temp_var_for_tac_123 = z - x;

  temp_var_for_tac_124 = z + x;

  temp_var_for_tac_125 = temp_var_for_tac_123 * temp_var_for_tac_124;

  temp_var_for_tac_126 = R / S;

  temp_var_for_tac_127 = temp_var_for_tac_125 + temp_var_for_tac_126;

  temp_var_for_callexp_3 = __ieee754_expf(temp_var_for_tac_127);
  temp_var_for_tac_128 = temp_var_for_callexp_2 * temp_var_for_callexp_3;

  r = temp_var_for_tac_128;
  computeDSub((Addr)&temp_var_for_tac_120,
              {(Addr) &(temp_var_for_const_75 = 0.0), (Addr)&z},
              "/home/shijia/Public/testprogram/s_erff.c_e.c:146:27");
  computeDMul((Addr)&temp_var_for_tac_121,
              {(Addr)&temp_var_for_tac_120, (Addr)&z},
              "/home/shijia/Public/testprogram/s_erff.c_e.c:146:32");
  computeDSub(
      (Addr)&temp_var_for_tac_122,
      {(Addr)&temp_var_for_tac_121, (Addr) &(temp_var_for_const_76 = 0.5625f)},
      "/home/shijia/Public/testprogram/s_erff.c_e.c:146:36");
  computeFSub((Addr)&temp_var_for_tac_123, {(Addr)&z, (Addr)&x},
              "/home/shijia/Public/testprogram/s_erff.c_e.c:147:25");
  computeFAdd((Addr)&temp_var_for_tac_124, {(Addr)&z, (Addr)&x},
              "/home/shijia/Public/testprogram/s_erff.c_e.c:147:35");
  computeFMul((Addr)&temp_var_for_tac_125,
              {(Addr)&temp_var_for_tac_123, (Addr)&temp_var_for_tac_124},
              "/home/shijia/Public/testprogram/s_erff.c_e.c:147:30");
  computeFDiv((Addr)&temp_var_for_tac_126, {(Addr)&R, (Addr)&S},
              "/home/shijia/Public/testprogram/s_erff.c_e.c:147:44");
  computeFAdd((Addr)&temp_var_for_tac_127,
              {(Addr)&temp_var_for_tac_125, (Addr)&temp_var_for_tac_126},
              "/home/shijia/Public/testprogram/s_erff.c_e.c:147:40");
  computeFMul((Addr)&temp_var_for_tac_128,
              {(Addr) &(temp_var_for_const_78 = temp_var_for_callexp_2),
               (Addr) &(temp_var_for_const_77 = temp_var_for_callexp_3)},
              "/home/shijia/Public/testprogram/s_erff.c_e.c:146:47");
  AssignF({(Addr)&r}, (Addr)&temp_var_for_tac_128,
          "/home/shijia/Public/testprogram/s_erff.c_e.c:146:5");
  ;
  if (hx >= 0) {
    float temp_var_for_ext_10;
    float temp_var_for_tac_129, temp_var_for_tac_130;
    float temp_var_for_const_79;
    temp_var_for_tac_129 = r / x;

    temp_var_for_tac_130 = one - temp_var_for_tac_129;

    temp_var_for_ext_10 = temp_var_for_tac_130;
    computeFDiv((Addr)&temp_var_for_tac_129, {(Addr)&r, (Addr)&x},
                "/home/shijia/Public/testprogram/s_erff.c_e.c:150:35");
    computeFSub(
        (Addr)&temp_var_for_tac_130,
        {(Addr) &(temp_var_for_const_79 = one), (Addr)&temp_var_for_tac_129},
        "/home/shijia/Public/testprogram/s_erff.c_e.c:150:31");
    AssignF({(Addr)&temp_var_for_ext_10}, (Addr)&temp_var_for_tac_130,
            "/home/shijia/Public/testprogram/s_erff.c_e.c:150:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_10", (Addr)&temp_var_for_ext_10));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_10;
  }

  float temp_var_for_ext_11;
  float temp_var_for_tac_131, temp_var_for_tac_132;
  float temp_var_for_const_80;
  temp_var_for_tac_131 = r / x;

  temp_var_for_tac_132 = temp_var_for_tac_131 - one;

  temp_var_for_ext_11 = temp_var_for_tac_132;
  computeFDiv((Addr)&temp_var_for_tac_131, {(Addr)&r, (Addr)&x},
              "/home/shijia/Public/testprogram/s_erff.c_e.c:158:27");
  computeFSub(
      (Addr)&temp_var_for_tac_132,
      {(Addr)&temp_var_for_tac_131, (Addr) &(temp_var_for_const_80 = one)},
      "/home/shijia/Public/testprogram/s_erff.c_e.c:158:31");
  AssignF({(Addr)&temp_var_for_ext_11}, (Addr)&temp_var_for_tac_132,
          "/home/shijia/Public/testprogram/s_erff.c_e.c:158:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_11", (Addr)&temp_var_for_ext_11));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_11;
}

__typeof(__erff) erff __attribute__((weak, alias("__erff")));
