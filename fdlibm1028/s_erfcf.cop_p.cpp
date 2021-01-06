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

float __erfcf(float x) {
  int32_t hx, ix;
  float R, S, P, Q, s, y, z, r;

#include "t_erff.h"

  static const float tiny = 1e-30;
  static const float half = 5.0000000000e-01; /* 0x3F000000 */
  static const float one = 1.0000000000e+00;  /* 0x3F800000 */
  static const float two = 2.0000000000e+00;  /* 0x40000000 */
  /* c = (subfloat)0.84506291151 */
  static const float erx = 8.4506291151e-01; /* 0x3f58560b */

  GET_FLOAT_WORD(hx, x);
  ix = hx & IC(0x7fffffff);
  if (!FLT_UWORD_IS_FINITE(ix)) { /* erfc(nan)=nan */
    /* erfc(+-inf)=0,2 */
    float temp_var_for_ext_0;
    float temp_var_for_tac_0, temp_var_for_tac_1, temp_var_for_tac_2,
        temp_var_for_tac_3;
    float temp_var_for_const_0, temp_var_for_const_1, temp_var_for_const_2,
        temp_var_for_const_3, temp_var_for_const_4;
    temp_var_for_tac_0 = ((uint32_t)hx) >> 31;

    temp_var_for_tac_1 = temp_var_for_tac_0 << 1;

    temp_var_for_tac_2 = one / x;

    temp_var_for_tac_3 = ((float)temp_var_for_tac_1) + temp_var_for_tac_2;

    temp_var_for_ext_0 = temp_var_for_tac_3;
    compute((Addr)&temp_var_for_tac_0,
            {(Addr) &(temp_var_for_const_1 = ((uint32_t)hx)),
             (Addr) &(temp_var_for_const_0 = 31)},
            "/home/shijia/Public/testprogram/s_erfcf.c_e.c:38:48");
    compute((Addr)&temp_var_for_tac_1,
            {(Addr)&temp_var_for_tac_0, (Addr) &(temp_var_for_const_2 = 1)},
            "/home/shijia/Public/testprogram/s_erfcf.c_e.c:38:55");
    computeFDiv((Addr)&temp_var_for_tac_2,
                {(Addr) &(temp_var_for_const_3 = one), (Addr)&x},
                "/home/shijia/Public/testprogram/s_erfcf.c_e.c:38:67");
    computeFAdd((Addr)&temp_var_for_tac_3,
                {(Addr) &(temp_var_for_const_4 = ((float)temp_var_for_tac_1)),
                 (Addr)&temp_var_for_tac_2},
                "/home/shijia/Public/testprogram/s_erfcf.c_e.c:38:61");
    AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_3,
            "/home/shijia/Public/testprogram/s_erfcf.c_e.c:38:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  if (ix < IC(0x3f580000)) { /* |x|<0.84375 */
    if (ix < IC(0x23800000)) /* |x|<2**-56 */
    {
      float temp_var_for_ext_1;
      temp_var_for_ext_1 = one - x;
      callExpStack.push(
          getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_1;
    }

    float temp_var_for_tac_4;
    temp_var_for_tac_4 = x * x;

    z = temp_var_for_tac_4;
    computeFMul((Addr)&temp_var_for_tac_4, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/s_erfcf.c_e.c:55:11");
    AssignF({(Addr)&z}, (Addr)&temp_var_for_tac_4,
            "/home/shijia/Public/testprogram/s_erfcf.c_e.c:55:7");
    ;
    float temp_var_for_tac_5, temp_var_for_tac_6, temp_var_for_tac_7,
        temp_var_for_tac_8, temp_var_for_tac_9, temp_var_for_tac_10,
        temp_var_for_tac_11, temp_var_for_tac_12;
    float temp_var_for_const_5, temp_var_for_const_6, temp_var_for_const_7,
        temp_var_for_const_8, temp_var_for_const_9;
    temp_var_for_tac_5 = z * pp4;

    temp_var_for_tac_6 = pp3 + temp_var_for_tac_5;

    temp_var_for_tac_7 = z * temp_var_for_tac_6;

    temp_var_for_tac_8 = pp2 + temp_var_for_tac_7;

    temp_var_for_tac_9 = z * temp_var_for_tac_8;

    temp_var_for_tac_10 = pp1 + temp_var_for_tac_9;

    temp_var_for_tac_11 = z * temp_var_for_tac_10;

    temp_var_for_tac_12 = pp0 + temp_var_for_tac_11;

    r = temp_var_for_tac_12;
    computeFMul((Addr)&temp_var_for_tac_5,
                {(Addr)&z, (Addr) &(temp_var_for_const_5 = pp4)},
                "/home/shijia/Public/testprogram/s_erfcf.c_e.c:56:50");
    computeFAdd(
        (Addr)&temp_var_for_tac_6,
        {(Addr) &(temp_var_for_const_6 = pp3), (Addr)&temp_var_for_tac_5},
        "/home/shijia/Public/testprogram/s_erfcf.c_e.c:56:46");
    computeFMul((Addr)&temp_var_for_tac_7,
                {(Addr)&z, (Addr)&temp_var_for_tac_6},
                "/home/shijia/Public/testprogram/s_erfcf.c_e.c:56:39");
    computeFAdd(
        (Addr)&temp_var_for_tac_8,
        {(Addr) &(temp_var_for_const_7 = pp2), (Addr)&temp_var_for_tac_7},
        "/home/shijia/Public/testprogram/s_erfcf.c_e.c:56:35");
    computeFMul((Addr)&temp_var_for_tac_9,
                {(Addr)&z, (Addr)&temp_var_for_tac_8},
                "/home/shijia/Public/testprogram/s_erfcf.c_e.c:56:28");
    computeFAdd(
        (Addr)&temp_var_for_tac_10,
        {(Addr) &(temp_var_for_const_8 = pp1), (Addr)&temp_var_for_tac_9},
        "/home/shijia/Public/testprogram/s_erfcf.c_e.c:56:24");
    computeFMul((Addr)&temp_var_for_tac_11,
                {(Addr)&z, (Addr)&temp_var_for_tac_10},
                "/home/shijia/Public/testprogram/s_erfcf.c_e.c:56:17");
    computeFAdd(
        (Addr)&temp_var_for_tac_12,
        {(Addr) &(temp_var_for_const_9 = pp0), (Addr)&temp_var_for_tac_11},
        "/home/shijia/Public/testprogram/s_erfcf.c_e.c:56:13");
    AssignF({(Addr)&r}, (Addr)&temp_var_for_tac_12,
            "/home/shijia/Public/testprogram/s_erfcf.c_e.c:56:7");
    ;
    float temp_var_for_tac_13, temp_var_for_tac_14, temp_var_for_tac_15,
        temp_var_for_tac_16, temp_var_for_tac_17, temp_var_for_tac_18,
        temp_var_for_tac_19, temp_var_for_tac_20, temp_var_for_tac_21,
        temp_var_for_tac_22;
    float temp_var_for_const_10, temp_var_for_const_11, temp_var_for_const_12,
        temp_var_for_const_13, temp_var_for_const_14, temp_var_for_const_15;
    temp_var_for_tac_13 = z * qq5;

    temp_var_for_tac_14 = qq4 + temp_var_for_tac_13;

    temp_var_for_tac_15 = z * temp_var_for_tac_14;

    temp_var_for_tac_16 = qq3 + temp_var_for_tac_15;

    temp_var_for_tac_17 = z * temp_var_for_tac_16;

    temp_var_for_tac_18 = qq2 + temp_var_for_tac_17;

    temp_var_for_tac_19 = z * temp_var_for_tac_18;

    temp_var_for_tac_20 = qq1 + temp_var_for_tac_19;

    temp_var_for_tac_21 = z * temp_var_for_tac_20;

    temp_var_for_tac_22 = one + temp_var_for_tac_21;

    s = temp_var_for_tac_22;
    computeFMul((Addr)&temp_var_for_tac_13,
                {(Addr)&z, (Addr) &(temp_var_for_const_10 = qq5)},
                "/home/shijia/Public/testprogram/s_erfcf.c_e.c:57:61");
    computeFAdd(
        (Addr)&temp_var_for_tac_14,
        {(Addr) &(temp_var_for_const_11 = qq4), (Addr)&temp_var_for_tac_13},
        "/home/shijia/Public/testprogram/s_erfcf.c_e.c:57:57");
    computeFMul((Addr)&temp_var_for_tac_15,
                {(Addr)&z, (Addr)&temp_var_for_tac_14},
                "/home/shijia/Public/testprogram/s_erfcf.c_e.c:57:50");
    computeFAdd(
        (Addr)&temp_var_for_tac_16,
        {(Addr) &(temp_var_for_const_12 = qq3), (Addr)&temp_var_for_tac_15},
        "/home/shijia/Public/testprogram/s_erfcf.c_e.c:57:46");
    computeFMul((Addr)&temp_var_for_tac_17,
                {(Addr)&z, (Addr)&temp_var_for_tac_16},
                "/home/shijia/Public/testprogram/s_erfcf.c_e.c:57:39");
    computeFAdd(
        (Addr)&temp_var_for_tac_18,
        {(Addr) &(temp_var_for_const_13 = qq2), (Addr)&temp_var_for_tac_17},
        "/home/shijia/Public/testprogram/s_erfcf.c_e.c:57:35");
    computeFMul((Addr)&temp_var_for_tac_19,
                {(Addr)&z, (Addr)&temp_var_for_tac_18},
                "/home/shijia/Public/testprogram/s_erfcf.c_e.c:57:28");
    computeFAdd(
        (Addr)&temp_var_for_tac_20,
        {(Addr) &(temp_var_for_const_14 = qq1), (Addr)&temp_var_for_tac_19},
        "/home/shijia/Public/testprogram/s_erfcf.c_e.c:57:24");
    computeFMul((Addr)&temp_var_for_tac_21,
                {(Addr)&z, (Addr)&temp_var_for_tac_20},
                "/home/shijia/Public/testprogram/s_erfcf.c_e.c:57:17");
    computeFAdd(
        (Addr)&temp_var_for_tac_22,
        {(Addr) &(temp_var_for_const_15 = one), (Addr)&temp_var_for_tac_21},
        "/home/shijia/Public/testprogram/s_erfcf.c_e.c:57:13");
    AssignF({(Addr)&s}, (Addr)&temp_var_for_tac_22,
            "/home/shijia/Public/testprogram/s_erfcf.c_e.c:57:7");
    ;
    float temp_var_for_tac_23;
    temp_var_for_tac_23 = r / s;

    y = temp_var_for_tac_23;
    computeFDiv((Addr)&temp_var_for_tac_23, {(Addr)&r, (Addr)&s},
                "/home/shijia/Public/testprogram/s_erfcf.c_e.c:58:11");
    AssignF({(Addr)&y}, (Addr)&temp_var_for_tac_23,
            "/home/shijia/Public/testprogram/s_erfcf.c_e.c:58:7");
    ;
    if (hx < IC(0x3e800000)) { /* x<1/4 */
      float temp_var_for_ext_2;
      float temp_var_for_tac_24, temp_var_for_tac_25, temp_var_for_tac_26;
      float temp_var_for_const_16;
      temp_var_for_tac_24 = x * y;

      temp_var_for_tac_25 = x + temp_var_for_tac_24;

      temp_var_for_tac_26 = one - temp_var_for_tac_25;

      temp_var_for_ext_2 = temp_var_for_tac_26;
      computeFMul((Addr)&temp_var_for_tac_24, {(Addr)&x, (Addr)&y},
                  "/home/shijia/Public/testprogram/s_erfcf.c_e.c:61:41");
      computeFAdd((Addr)&temp_var_for_tac_25,
                  {(Addr)&x, (Addr)&temp_var_for_tac_24},
                  "/home/shijia/Public/testprogram/s_erfcf.c_e.c:61:37");
      computeFSub(
          (Addr)&temp_var_for_tac_26,
          {(Addr) &(temp_var_for_const_16 = one), (Addr)&temp_var_for_tac_25},
          "/home/shijia/Public/testprogram/s_erfcf.c_e.c:61:32");
      AssignF({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_26,
              "/home/shijia/Public/testprogram/s_erfcf.c_e.c:61:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_2;
    } else {
      float temp_var_for_ext_3;
      float temp_var_for_tac_27;
      temp_var_for_tac_27 = x * y;

      temp_var_for_ext_3 = temp_var_for_tac_27;
      computeFMul((Addr)&temp_var_for_tac_27, {(Addr)&x, (Addr)&y},
                  "/home/shijia/Public/testprogram/s_erfcf.c_e.c:68:30");
      AssignF({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_27,
              "/home/shijia/Public/testprogram/s_erfcf.c_e.c:68:26");
      ; // r
      /*(s)(r)(_)(_)(_)(tem)(_)(_)(_)(_)(_)(y)(x)*/
      r = temp_var_for_ext_3;
      AssignF({(Addr)&r}, (Addr)&temp_var_for_ext_3,
              "/home/shijia/Public/testprogram/s_erfcf.c_e.c:70:9");
      ;
      float temp_var_for_tac_28;
      float temp_var_for_const_17;
      temp_var_for_tac_28 = x - half;

      r += temp_var_for_tac_28;
      ;
      float temp_var_for_ext_4;
      float temp_var_for_tac_30;
      float temp_var_for_const_18;
      temp_var_for_tac_30 = half - r;

      temp_var_for_ext_4 = temp_var_for_tac_30;
      computeFSub((Addr)&temp_var_for_tac_28,
                  {(Addr)&x, (Addr) &(temp_var_for_const_17 = half)},
                  "/home/shijia/Public/testprogram/s_erfcf.c_e.c:71:15");
      computeFSub((Addr)&temp_var_for_tac_30,
                  {(Addr) &(temp_var_for_const_18 = half), (Addr)&r},
                  "/home/shijia/Public/testprogram/s_erfcf.c_e.c:73:33");
      AssignF({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_30,
              "/home/shijia/Public/testprogram/s_erfcf.c_e.c:73:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_4;
    }
  }
  if (ix < IC(0x3fa00000)) { /* 0.84375 <= |x| < 1.25 */
    float temp_var_for_tac_31;
    float temp_var_for_const_19, temp_var_for_const_20;
    float temp_var_for_callexp_0;

    temp_var_for_callexp_0 = fabsf(x);
    temp_var_for_tac_31 = temp_var_for_callexp_0 - one;

    s = temp_var_for_tac_31;
    computeFSub((Addr)&temp_var_for_tac_31,
                {(Addr) &(temp_var_for_const_20 = temp_var_for_callexp_0),
                 (Addr) &(temp_var_for_const_19 = one)},
                "/home/shijia/Public/testprogram/s_erfcf.c_e.c:81:28");
    AssignF({(Addr)&s}, (Addr)&temp_var_for_tac_31,
            "/home/shijia/Public/testprogram/s_erfcf.c_e.c:81:7");
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
                "/home/shijia/Public/testprogram/s_erfcf.c_e.c:83:66");
    computeFAdd(
        (Addr)&temp_var_for_tac_33,
        {(Addr) &(temp_var_for_const_22 = pa5), (Addr)&temp_var_for_tac_32},
        "/home/shijia/Public/testprogram/s_erfcf.c_e.c:83:62");
    computeFMul((Addr)&temp_var_for_tac_34,
                {(Addr)&s, (Addr)&temp_var_for_tac_33},
                "/home/shijia/Public/testprogram/s_erfcf.c_e.c:83:55");
    computeFAdd(
        (Addr)&temp_var_for_tac_35,
        {(Addr) &(temp_var_for_const_23 = pa4), (Addr)&temp_var_for_tac_34},
        "/home/shijia/Public/testprogram/s_erfcf.c_e.c:83:51");
    computeFMul((Addr)&temp_var_for_tac_36,
                {(Addr)&s, (Addr)&temp_var_for_tac_35},
                "/home/shijia/Public/testprogram/s_erfcf.c_e.c:83:44");
    computeFAdd(
        (Addr)&temp_var_for_tac_37,
        {(Addr) &(temp_var_for_const_24 = pa3), (Addr)&temp_var_for_tac_36},
        "/home/shijia/Public/testprogram/s_erfcf.c_e.c:83:40");
    computeFMul((Addr)&temp_var_for_tac_38,
                {(Addr)&s, (Addr)&temp_var_for_tac_37},
                "/home/shijia/Public/testprogram/s_erfcf.c_e.c:83:33");
    computeFAdd(
        (Addr)&temp_var_for_tac_39,
        {(Addr) &(temp_var_for_const_25 = pa2), (Addr)&temp_var_for_tac_38},
        "/home/shijia/Public/testprogram/s_erfcf.c_e.c:83:29");
    computeFMul((Addr)&temp_var_for_tac_40,
                {(Addr)&s, (Addr)&temp_var_for_tac_39},
                "/home/shijia/Public/testprogram/s_erfcf.c_e.c:83:22");
    computeFAdd(
        (Addr)&temp_var_for_tac_41,
        {(Addr) &(temp_var_for_const_26 = pa1), (Addr)&temp_var_for_tac_40},
        "/home/shijia/Public/testprogram/s_erfcf.c_e.c:83:18");
    computeFMul((Addr)&temp_var_for_tac_42,
                {(Addr)&s, (Addr)&temp_var_for_tac_41},
                "/home/shijia/Public/testprogram/s_erfcf.c_e.c:83:11");
    computeFAdd(
        (Addr)&temp_var_for_tac_43,
        {(Addr) &(temp_var_for_const_27 = pa0), (Addr)&temp_var_for_tac_42},
        "/home/shijia/Public/testprogram/s_erfcf.c_e.c:82:13");
    AssignF({(Addr)&P}, (Addr)&temp_var_for_tac_43,
            "/home/shijia/Public/testprogram/s_erfcf.c_e.c:82:7");
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
                "/home/shijia/Public/testprogram/s_erfcf.c_e.c:85:66");
    computeFAdd(
        (Addr)&temp_var_for_tac_45,
        {(Addr) &(temp_var_for_const_29 = qa5), (Addr)&temp_var_for_tac_44},
        "/home/shijia/Public/testprogram/s_erfcf.c_e.c:85:62");
    computeFMul((Addr)&temp_var_for_tac_46,
                {(Addr)&s, (Addr)&temp_var_for_tac_45},
                "/home/shijia/Public/testprogram/s_erfcf.c_e.c:85:55");
    computeFAdd(
        (Addr)&temp_var_for_tac_47,
        {(Addr) &(temp_var_for_const_30 = qa4), (Addr)&temp_var_for_tac_46},
        "/home/shijia/Public/testprogram/s_erfcf.c_e.c:85:51");
    computeFMul((Addr)&temp_var_for_tac_48,
                {(Addr)&s, (Addr)&temp_var_for_tac_47},
                "/home/shijia/Public/testprogram/s_erfcf.c_e.c:85:44");
    computeFAdd(
        (Addr)&temp_var_for_tac_49,
        {(Addr) &(temp_var_for_const_31 = qa3), (Addr)&temp_var_for_tac_48},
        "/home/shijia/Public/testprogram/s_erfcf.c_e.c:85:40");
    computeFMul((Addr)&temp_var_for_tac_50,
                {(Addr)&s, (Addr)&temp_var_for_tac_49},
                "/home/shijia/Public/testprogram/s_erfcf.c_e.c:85:33");
    computeFAdd(
        (Addr)&temp_var_for_tac_51,
        {(Addr) &(temp_var_for_const_32 = qa2), (Addr)&temp_var_for_tac_50},
        "/home/shijia/Public/testprogram/s_erfcf.c_e.c:85:29");
    computeFMul((Addr)&temp_var_for_tac_52,
                {(Addr)&s, (Addr)&temp_var_for_tac_51},
                "/home/shijia/Public/testprogram/s_erfcf.c_e.c:85:22");
    computeFAdd(
        (Addr)&temp_var_for_tac_53,
        {(Addr) &(temp_var_for_const_33 = qa1), (Addr)&temp_var_for_tac_52},
        "/home/shijia/Public/testprogram/s_erfcf.c_e.c:85:18");
    computeFMul((Addr)&temp_var_for_tac_54,
                {(Addr)&s, (Addr)&temp_var_for_tac_53},
                "/home/shijia/Public/testprogram/s_erfcf.c_e.c:85:11");
    computeFAdd(
        (Addr)&temp_var_for_tac_55,
        {(Addr) &(temp_var_for_const_34 = one), (Addr)&temp_var_for_tac_54},
        "/home/shijia/Public/testprogram/s_erfcf.c_e.c:84:13");
    AssignF({(Addr)&Q}, (Addr)&temp_var_for_tac_55,
            "/home/shijia/Public/testprogram/s_erfcf.c_e.c:84:7");
    ;
    if (hx >= 0) {
      float temp_var_for_tac_56;
      float temp_var_for_const_35, temp_var_for_const_36;
      temp_var_for_tac_56 = one - erx;

      z = temp_var_for_tac_56;
      computeFSub((Addr)&temp_var_for_tac_56,
                  {(Addr) &(temp_var_for_const_36 = one),
                   (Addr) &(temp_var_for_const_35 = erx)},
                  "/home/shijia/Public/testprogram/s_erfcf.c_e.c:87:15");
      AssignF({(Addr)&z}, (Addr)&temp_var_for_tac_56,
              "/home/shijia/Public/testprogram/s_erfcf.c_e.c:87:9");
      ;
      float temp_var_for_ext_5;
      float temp_var_for_tac_57, temp_var_for_tac_58;
      temp_var_for_tac_57 = P / Q;

      temp_var_for_tac_58 = z - temp_var_for_tac_57;

      temp_var_for_ext_5 = temp_var_for_tac_58;
      computeFDiv((Addr)&temp_var_for_tac_57, {(Addr)&P, (Addr)&Q},
                  "/home/shijia/Public/testprogram/s_erfcf.c_e.c:89:34");
      computeFSub((Addr)&temp_var_for_tac_58,
                  {(Addr)&z, (Addr)&temp_var_for_tac_57},
                  "/home/shijia/Public/testprogram/s_erfcf.c_e.c:89:30");
      AssignF({(Addr)&temp_var_for_ext_5}, (Addr)&temp_var_for_tac_58,
              "/home/shijia/Public/testprogram/s_erfcf.c_e.c:89:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_5;
    } else {
      float temp_var_for_tac_59, temp_var_for_tac_60;
      float temp_var_for_const_37;
      temp_var_for_tac_59 = P / Q;

      temp_var_for_tac_60 = erx + temp_var_for_tac_59;

      z = temp_var_for_tac_60;
      computeFDiv((Addr)&temp_var_for_tac_59, {(Addr)&P, (Addr)&Q},
                  "/home/shijia/Public/testprogram/s_erfcf.c_e.c:95:19");
      computeFAdd(
          (Addr)&temp_var_for_tac_60,
          {(Addr) &(temp_var_for_const_37 = erx), (Addr)&temp_var_for_tac_59},
          "/home/shijia/Public/testprogram/s_erfcf.c_e.c:95:15");
      AssignF({(Addr)&z}, (Addr)&temp_var_for_tac_60,
              "/home/shijia/Public/testprogram/s_erfcf.c_e.c:95:9");
      ;
      float temp_var_for_ext_6;
      float temp_var_for_tac_61;
      float temp_var_for_const_38;
      temp_var_for_tac_61 = one + z;

      temp_var_for_ext_6 = temp_var_for_tac_61;
      computeFAdd((Addr)&temp_var_for_tac_61,
                  {(Addr) &(temp_var_for_const_38 = one), (Addr)&z},
                  "/home/shijia/Public/testprogram/s_erfcf.c_e.c:97:32");
      AssignF({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_61,
              "/home/shijia/Public/testprogram/s_erfcf.c_e.c:97:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_6;
    }
  }

  if (ix < IC(0x41e00000)) { /* |x|<28 */
    float temp_var_for_ext_7;
    float temp_var_for_const_39;
    float temp_var_for_callexp_1;

    temp_var_for_callexp_1 = fabsf(x);
    temp_var_for_ext_7 = temp_var_for_callexp_1;
    AssignF({(Addr)&temp_var_for_ext_7},
            (Addr) &(temp_var_for_const_39 = temp_var_for_callexp_1),
            "/home/shijia/Public/testprogram/s_erfcf.c_e.c:107:24");
    ; // x
    /*(Q)(P)(erx)(Q)(P)(6)(tem)(__ieee754_fabsf(x))*/
    x = temp_var_for_ext_7;
    AssignF({(Addr)&x}, (Addr)&temp_var_for_ext_7,
            "/home/shijia/Public/testprogram/s_erfcf.c_e.c:109:7");
    ;
    float temp_var_for_tac_62, temp_var_for_tac_63;
    float temp_var_for_const_40;
    temp_var_for_tac_62 = x * x;

    temp_var_for_tac_63 = one / temp_var_for_tac_62;

    s = temp_var_for_tac_63;
    computeFMul((Addr)&temp_var_for_tac_62, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/s_erfcf.c_e.c:110:18");
    computeFDiv(
        (Addr)&temp_var_for_tac_63,
        {(Addr) &(temp_var_for_const_40 = one), (Addr)&temp_var_for_tac_62},
        "/home/shijia/Public/testprogram/s_erfcf.c_e.c:110:13");
    AssignF({(Addr)&s}, (Addr)&temp_var_for_tac_63,
            "/home/shijia/Public/testprogram/s_erfcf.c_e.c:110:7");
    ;
    if (ix < IC(0x4036DB6D)) { /* |x| < 1/.35 ~ 2.857143 */
      float temp_var_for_tac_64, temp_var_for_tac_65, temp_var_for_tac_66,
          temp_var_for_tac_67, temp_var_for_tac_68, temp_var_for_tac_69,
          temp_var_for_tac_70, temp_var_for_tac_71, temp_var_for_tac_72,
          temp_var_for_tac_73, temp_var_for_tac_74, temp_var_for_tac_75,
          temp_var_for_tac_76, temp_var_for_tac_77;
      float temp_var_for_const_41, temp_var_for_const_42, temp_var_for_const_43,
          temp_var_for_const_44, temp_var_for_const_45, temp_var_for_const_46,
          temp_var_for_const_47, temp_var_for_const_48;
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
                  {(Addr)&s, (Addr) &(temp_var_for_const_41 = ra7)},
                  "/home/shijia/Public/testprogram/s_erfcf.c_e.c:115:67");
      computeFAdd(
          (Addr)&temp_var_for_tac_65,
          {(Addr) &(temp_var_for_const_42 = ra6), (Addr)&temp_var_for_tac_64},
          "/home/shijia/Public/testprogram/s_erfcf.c_e.c:115:63");
      computeFMul((Addr)&temp_var_for_tac_66,
                  {(Addr)&s, (Addr)&temp_var_for_tac_65},
                  "/home/shijia/Public/testprogram/s_erfcf.c_e.c:115:56");
      computeFAdd(
          (Addr)&temp_var_for_tac_67,
          {(Addr) &(temp_var_for_const_43 = ra5), (Addr)&temp_var_for_tac_66},
          "/home/shijia/Public/testprogram/s_erfcf.c_e.c:115:52");
      computeFMul((Addr)&temp_var_for_tac_68,
                  {(Addr)&s, (Addr)&temp_var_for_tac_67},
                  "/home/shijia/Public/testprogram/s_erfcf.c_e.c:115:45");
      computeFAdd(
          (Addr)&temp_var_for_tac_69,
          {(Addr) &(temp_var_for_const_44 = ra4), (Addr)&temp_var_for_tac_68},
          "/home/shijia/Public/testprogram/s_erfcf.c_e.c:115:41");
      computeFMul((Addr)&temp_var_for_tac_70,
                  {(Addr)&s, (Addr)&temp_var_for_tac_69},
                  "/home/shijia/Public/testprogram/s_erfcf.c_e.c:115:34");
      computeFAdd(
          (Addr)&temp_var_for_tac_71,
          {(Addr) &(temp_var_for_const_45 = ra3), (Addr)&temp_var_for_tac_70},
          "/home/shijia/Public/testprogram/s_erfcf.c_e.c:115:30");
      computeFMul((Addr)&temp_var_for_tac_72,
                  {(Addr)&s, (Addr)&temp_var_for_tac_71},
                  "/home/shijia/Public/testprogram/s_erfcf.c_e.c:115:23");
      computeFAdd(
          (Addr)&temp_var_for_tac_73,
          {(Addr) &(temp_var_for_const_46 = ra2), (Addr)&temp_var_for_tac_72},
          "/home/shijia/Public/testprogram/s_erfcf.c_e.c:114:25");
      computeFMul((Addr)&temp_var_for_tac_74,
                  {(Addr)&s, (Addr)&temp_var_for_tac_73},
                  "/home/shijia/Public/testprogram/s_erfcf.c_e.c:114:18");
      computeFAdd(
          (Addr)&temp_var_for_tac_75,
          {(Addr) &(temp_var_for_const_47 = ra1), (Addr)&temp_var_for_tac_74},
          "/home/shijia/Public/testprogram/s_erfcf.c_e.c:113:20");
      computeFMul((Addr)&temp_var_for_tac_76,
                  {(Addr)&s, (Addr)&temp_var_for_tac_75},
                  "/home/shijia/Public/testprogram/s_erfcf.c_e.c:113:13");
      computeFAdd(
          (Addr)&temp_var_for_tac_77,
          {(Addr) &(temp_var_for_const_48 = ra0), (Addr)&temp_var_for_tac_76},
          "/home/shijia/Public/testprogram/s_erfcf.c_e.c:112:15");
      AssignF({(Addr)&R}, (Addr)&temp_var_for_tac_77,
              "/home/shijia/Public/testprogram/s_erfcf.c_e.c:112:9");
      ;
      float temp_var_for_tac_78, temp_var_for_tac_79, temp_var_for_tac_80,
          temp_var_for_tac_81, temp_var_for_tac_82, temp_var_for_tac_83,
          temp_var_for_tac_84, temp_var_for_tac_85, temp_var_for_tac_86,
          temp_var_for_tac_87, temp_var_for_tac_88, temp_var_for_tac_89,
          temp_var_for_tac_90, temp_var_for_tac_91, temp_var_for_tac_92,
          temp_var_for_tac_93;
      float temp_var_for_const_49, temp_var_for_const_50, temp_var_for_const_51,
          temp_var_for_const_52, temp_var_for_const_53, temp_var_for_const_54,
          temp_var_for_const_55, temp_var_for_const_56, temp_var_for_const_57;
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
                  {(Addr)&s, (Addr) &(temp_var_for_const_49 = sa8)},
                  "/home/shijia/Public/testprogram/s_erfcf.c_e.c:121:66");
      computeFAdd(
          (Addr)&temp_var_for_tac_79,
          {(Addr) &(temp_var_for_const_50 = sa7), (Addr)&temp_var_for_tac_78},
          "/home/shijia/Public/testprogram/s_erfcf.c_e.c:121:62");
      computeFMul((Addr)&temp_var_for_tac_80,
                  {(Addr)&s, (Addr)&temp_var_for_tac_79},
                  "/home/shijia/Public/testprogram/s_erfcf.c_e.c:121:55");
      computeFAdd(
          (Addr)&temp_var_for_tac_81,
          {(Addr) &(temp_var_for_const_51 = sa6), (Addr)&temp_var_for_tac_80},
          "/home/shijia/Public/testprogram/s_erfcf.c_e.c:121:51");
      computeFMul((Addr)&temp_var_for_tac_82,
                  {(Addr)&s, (Addr)&temp_var_for_tac_81},
                  "/home/shijia/Public/testprogram/s_erfcf.c_e.c:121:44");
      computeFAdd(
          (Addr)&temp_var_for_tac_83,
          {(Addr) &(temp_var_for_const_52 = sa5), (Addr)&temp_var_for_tac_82},
          "/home/shijia/Public/testprogram/s_erfcf.c_e.c:121:40");
      computeFMul((Addr)&temp_var_for_tac_84,
                  {(Addr)&s, (Addr)&temp_var_for_tac_83},
                  "/home/shijia/Public/testprogram/s_erfcf.c_e.c:121:33");
      computeFAdd(
          (Addr)&temp_var_for_tac_85,
          {(Addr) &(temp_var_for_const_53 = sa4), (Addr)&temp_var_for_tac_84},
          "/home/shijia/Public/testprogram/s_erfcf.c_e.c:120:35");
      computeFMul((Addr)&temp_var_for_tac_86,
                  {(Addr)&s, (Addr)&temp_var_for_tac_85},
                  "/home/shijia/Public/testprogram/s_erfcf.c_e.c:120:28");
      computeFAdd(
          (Addr)&temp_var_for_tac_87,
          {(Addr) &(temp_var_for_const_54 = sa3), (Addr)&temp_var_for_tac_86},
          "/home/shijia/Public/testprogram/s_erfcf.c_e.c:119:30");
      computeFMul((Addr)&temp_var_for_tac_88,
                  {(Addr)&s, (Addr)&temp_var_for_tac_87},
                  "/home/shijia/Public/testprogram/s_erfcf.c_e.c:119:23");
      computeFAdd(
          (Addr)&temp_var_for_tac_89,
          {(Addr) &(temp_var_for_const_55 = sa2), (Addr)&temp_var_for_tac_88},
          "/home/shijia/Public/testprogram/s_erfcf.c_e.c:118:25");
      computeFMul((Addr)&temp_var_for_tac_90,
                  {(Addr)&s, (Addr)&temp_var_for_tac_89},
                  "/home/shijia/Public/testprogram/s_erfcf.c_e.c:118:18");
      computeFAdd(
          (Addr)&temp_var_for_tac_91,
          {(Addr) &(temp_var_for_const_56 = sa1), (Addr)&temp_var_for_tac_90},
          "/home/shijia/Public/testprogram/s_erfcf.c_e.c:117:20");
      computeFMul((Addr)&temp_var_for_tac_92,
                  {(Addr)&s, (Addr)&temp_var_for_tac_91},
                  "/home/shijia/Public/testprogram/s_erfcf.c_e.c:117:13");
      computeFAdd(
          (Addr)&temp_var_for_tac_93,
          {(Addr) &(temp_var_for_const_57 = one), (Addr)&temp_var_for_tac_92},
          "/home/shijia/Public/testprogram/s_erfcf.c_e.c:116:15");
      AssignF({(Addr)&S}, (Addr)&temp_var_for_tac_93,
              "/home/shijia/Public/testprogram/s_erfcf.c_e.c:116:9");
      ;
    } else { /* |x| >= 1/.35 ~ 2.857143 */
      if (hx < 0 && ix >= IC(0x40c00000)) {
        float temp_var_for_ext_8;
        float temp_var_for_tac_94;
        float temp_var_for_const_58, temp_var_for_const_59;
        temp_var_for_tac_94 = two - tiny;

        temp_var_for_ext_8 = temp_var_for_tac_94;
        computeFSub((Addr)&temp_var_for_tac_94,
                    {(Addr) &(temp_var_for_const_59 = two),
                     (Addr) &(temp_var_for_const_58 = tiny)},
                    "/home/shijia/Public/testprogram/s_erfcf.c_e.c:125:34");
        AssignF({(Addr)&temp_var_for_ext_8}, (Addr)&temp_var_for_tac_94,
                "/home/shijia/Public/testprogram/s_erfcf.c_e.c:125:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_8;
      }
      /* x < -6 */
      float temp_var_for_tac_95, temp_var_for_tac_96, temp_var_for_tac_97,
          temp_var_for_tac_98, temp_var_for_tac_99, temp_var_for_tac_100,
          temp_var_for_tac_101, temp_var_for_tac_102, temp_var_for_tac_103,
          temp_var_for_tac_104, temp_var_for_tac_105, temp_var_for_tac_106;
      float temp_var_for_const_60, temp_var_for_const_61, temp_var_for_const_62,
          temp_var_for_const_63, temp_var_for_const_64, temp_var_for_const_65,
          temp_var_for_const_66;
      temp_var_for_tac_95 = s * rb6;

      temp_var_for_tac_96 = rb5 + temp_var_for_tac_95;

      temp_var_for_tac_97 = s * temp_var_for_tac_96;

      temp_var_for_tac_98 = rb4 + temp_var_for_tac_97;

      temp_var_for_tac_99 = s * temp_var_for_tac_98;

      temp_var_for_tac_100 = rb3 + temp_var_for_tac_99;

      temp_var_for_tac_101 = s * temp_var_for_tac_100;

      temp_var_for_tac_102 = rb2 + temp_var_for_tac_101;

      temp_var_for_tac_103 = s * temp_var_for_tac_102;

      temp_var_for_tac_104 = rb1 + temp_var_for_tac_103;

      temp_var_for_tac_105 = s * temp_var_for_tac_104;

      temp_var_for_tac_106 = rb0 + temp_var_for_tac_105;

      R = temp_var_for_tac_106;
      computeFMul((Addr)&temp_var_for_tac_95,
                  {(Addr)&s, (Addr) &(temp_var_for_const_60 = rb6)},
                  "/home/shijia/Public/testprogram/s_erfcf.c_e.c:133:68");
      computeFAdd(
          (Addr)&temp_var_for_tac_96,
          {(Addr) &(temp_var_for_const_61 = rb5), (Addr)&temp_var_for_tac_95},
          "/home/shijia/Public/testprogram/s_erfcf.c_e.c:133:64");
      computeFMul((Addr)&temp_var_for_tac_97,
                  {(Addr)&s, (Addr)&temp_var_for_tac_96},
                  "/home/shijia/Public/testprogram/s_erfcf.c_e.c:133:57");
      computeFAdd(
          (Addr)&temp_var_for_tac_98,
          {(Addr) &(temp_var_for_const_62 = rb4), (Addr)&temp_var_for_tac_97},
          "/home/shijia/Public/testprogram/s_erfcf.c_e.c:133:53");
      computeFMul((Addr)&temp_var_for_tac_99,
                  {(Addr)&s, (Addr)&temp_var_for_tac_98},
                  "/home/shijia/Public/testprogram/s_erfcf.c_e.c:133:46");
      computeFAdd(
          (Addr)&temp_var_for_tac_100,
          {(Addr) &(temp_var_for_const_63 = rb3), (Addr)&temp_var_for_tac_99},
          "/home/shijia/Public/testprogram/s_erfcf.c_e.c:133:42");
      computeFMul((Addr)&temp_var_for_tac_101,
                  {(Addr)&s, (Addr)&temp_var_for_tac_100},
                  "/home/shijia/Public/testprogram/s_erfcf.c_e.c:133:35");
      computeFAdd(
          (Addr)&temp_var_for_tac_102,
          {(Addr) &(temp_var_for_const_64 = rb2), (Addr)&temp_var_for_tac_101},
          "/home/shijia/Public/testprogram/s_erfcf.c_e.c:133:31");
      computeFMul((Addr)&temp_var_for_tac_103,
                  {(Addr)&s, (Addr)&temp_var_for_tac_102},
                  "/home/shijia/Public/testprogram/s_erfcf.c_e.c:133:24");
      computeFAdd(
          (Addr)&temp_var_for_tac_104,
          {(Addr) &(temp_var_for_const_65 = rb1), (Addr)&temp_var_for_tac_103},
          "/home/shijia/Public/testprogram/s_erfcf.c_e.c:133:20");
      computeFMul((Addr)&temp_var_for_tac_105,
                  {(Addr)&s, (Addr)&temp_var_for_tac_104},
                  "/home/shijia/Public/testprogram/s_erfcf.c_e.c:133:13");
      computeFAdd(
          (Addr)&temp_var_for_tac_106,
          {(Addr) &(temp_var_for_const_66 = rb0), (Addr)&temp_var_for_tac_105},
          "/home/shijia/Public/testprogram/s_erfcf.c_e.c:132:15");
      AssignF({(Addr)&R}, (Addr)&temp_var_for_tac_106,
              "/home/shijia/Public/testprogram/s_erfcf.c_e.c:132:9");
      ;
      float temp_var_for_tac_107, temp_var_for_tac_108, temp_var_for_tac_109,
          temp_var_for_tac_110, temp_var_for_tac_111, temp_var_for_tac_112,
          temp_var_for_tac_113, temp_var_for_tac_114, temp_var_for_tac_115,
          temp_var_for_tac_116, temp_var_for_tac_117, temp_var_for_tac_118,
          temp_var_for_tac_119, temp_var_for_tac_120;
      float temp_var_for_const_67, temp_var_for_const_68, temp_var_for_const_69,
          temp_var_for_const_70, temp_var_for_const_71, temp_var_for_const_72,
          temp_var_for_const_73, temp_var_for_const_74;
      temp_var_for_tac_107 = s * sb7;

      temp_var_for_tac_108 = sb6 + temp_var_for_tac_107;

      temp_var_for_tac_109 = s * temp_var_for_tac_108;

      temp_var_for_tac_110 = sb5 + temp_var_for_tac_109;

      temp_var_for_tac_111 = s * temp_var_for_tac_110;

      temp_var_for_tac_112 = sb4 + temp_var_for_tac_111;

      temp_var_for_tac_113 = s * temp_var_for_tac_112;

      temp_var_for_tac_114 = sb3 + temp_var_for_tac_113;

      temp_var_for_tac_115 = s * temp_var_for_tac_114;

      temp_var_for_tac_116 = sb2 + temp_var_for_tac_115;

      temp_var_for_tac_117 = s * temp_var_for_tac_116;

      temp_var_for_tac_118 = sb1 + temp_var_for_tac_117;

      temp_var_for_tac_119 = s * temp_var_for_tac_118;

      temp_var_for_tac_120 = one + temp_var_for_tac_119;

      S = temp_var_for_tac_120;
      computeFMul((Addr)&temp_var_for_tac_107,
                  {(Addr)&s, (Addr) &(temp_var_for_const_67 = sb7)},
                  "/home/shijia/Public/testprogram/s_erfcf.c_e.c:137:67");
      computeFAdd(
          (Addr)&temp_var_for_tac_108,
          {(Addr) &(temp_var_for_const_68 = sb6), (Addr)&temp_var_for_tac_107},
          "/home/shijia/Public/testprogram/s_erfcf.c_e.c:137:63");
      computeFMul((Addr)&temp_var_for_tac_109,
                  {(Addr)&s, (Addr)&temp_var_for_tac_108},
                  "/home/shijia/Public/testprogram/s_erfcf.c_e.c:137:56");
      computeFAdd(
          (Addr)&temp_var_for_tac_110,
          {(Addr) &(temp_var_for_const_69 = sb5), (Addr)&temp_var_for_tac_109},
          "/home/shijia/Public/testprogram/s_erfcf.c_e.c:137:52");
      computeFMul((Addr)&temp_var_for_tac_111,
                  {(Addr)&s, (Addr)&temp_var_for_tac_110},
                  "/home/shijia/Public/testprogram/s_erfcf.c_e.c:137:45");
      computeFAdd(
          (Addr)&temp_var_for_tac_112,
          {(Addr) &(temp_var_for_const_70 = sb4), (Addr)&temp_var_for_tac_111},
          "/home/shijia/Public/testprogram/s_erfcf.c_e.c:137:41");
      computeFMul((Addr)&temp_var_for_tac_113,
                  {(Addr)&s, (Addr)&temp_var_for_tac_112},
                  "/home/shijia/Public/testprogram/s_erfcf.c_e.c:137:34");
      computeFAdd(
          (Addr)&temp_var_for_tac_114,
          {(Addr) &(temp_var_for_const_71 = sb3), (Addr)&temp_var_for_tac_113},
          "/home/shijia/Public/testprogram/s_erfcf.c_e.c:137:30");
      computeFMul((Addr)&temp_var_for_tac_115,
                  {(Addr)&s, (Addr)&temp_var_for_tac_114},
                  "/home/shijia/Public/testprogram/s_erfcf.c_e.c:137:23");
      computeFAdd(
          (Addr)&temp_var_for_tac_116,
          {(Addr) &(temp_var_for_const_72 = sb2), (Addr)&temp_var_for_tac_115},
          "/home/shijia/Public/testprogram/s_erfcf.c_e.c:136:25");
      computeFMul((Addr)&temp_var_for_tac_117,
                  {(Addr)&s, (Addr)&temp_var_for_tac_116},
                  "/home/shijia/Public/testprogram/s_erfcf.c_e.c:136:18");
      computeFAdd(
          (Addr)&temp_var_for_tac_118,
          {(Addr) &(temp_var_for_const_73 = sb1), (Addr)&temp_var_for_tac_117},
          "/home/shijia/Public/testprogram/s_erfcf.c_e.c:135:20");
      computeFMul((Addr)&temp_var_for_tac_119,
                  {(Addr)&s, (Addr)&temp_var_for_tac_118},
                  "/home/shijia/Public/testprogram/s_erfcf.c_e.c:135:13");
      computeFAdd(
          (Addr)&temp_var_for_tac_120,
          {(Addr) &(temp_var_for_const_74 = one), (Addr)&temp_var_for_tac_119},
          "/home/shijia/Public/testprogram/s_erfcf.c_e.c:134:15");
      AssignF({(Addr)&S}, (Addr)&temp_var_for_tac_120,
              "/home/shijia/Public/testprogram/s_erfcf.c_e.c:134:9");
      ;
    }
    GET_FLOAT_WORD(ix, x);
    SET_FLOAT_WORD(z, ix & IC(0xffffe000));
    float temp_var_for_tac_121, temp_var_for_tac_122, temp_var_for_tac_123,
        temp_var_for_tac_124, temp_var_for_tac_125, temp_var_for_tac_126,
        temp_var_for_tac_127, temp_var_for_tac_128, temp_var_for_tac_129;
    float temp_var_for_const_75, temp_var_for_const_76, temp_var_for_const_77,
        temp_var_for_const_78;
    float temp_var_for_callexp_2;

    float temp_var_for_callexp_3;

    temp_var_for_tac_121 = 0.0 - z;

    temp_var_for_tac_122 = temp_var_for_tac_121 * z;

    temp_var_for_tac_123 = temp_var_for_tac_122 - 0.5625f;

    temp_var_for_callexp_2 = __ieee754_expf(temp_var_for_tac_123);
    temp_var_for_tac_124 = z - x;

    temp_var_for_tac_125 = z + x;

    temp_var_for_tac_126 = temp_var_for_tac_124 * temp_var_for_tac_125;

    temp_var_for_tac_127 = R / S;

    temp_var_for_tac_128 = temp_var_for_tac_126 + temp_var_for_tac_127;

    temp_var_for_callexp_3 = __ieee754_expf(temp_var_for_tac_128);
    temp_var_for_tac_129 = temp_var_for_callexp_2 * temp_var_for_callexp_3;

    r = temp_var_for_tac_129;
    computeDSub((Addr)&temp_var_for_tac_121,
                {(Addr) &(temp_var_for_const_75 = 0.0), (Addr)&z},
                "/home/shijia/Public/testprogram/s_erfcf.c_e.c:141:29");
    computeDMul((Addr)&temp_var_for_tac_122,
                {(Addr)&temp_var_for_tac_121, (Addr)&z},
                "/home/shijia/Public/testprogram/s_erfcf.c_e.c:141:34");
    computeDSub((Addr)&temp_var_for_tac_123,
                {(Addr)&temp_var_for_tac_122,
                 (Addr) &(temp_var_for_const_76 = 0.5625f)},
                "/home/shijia/Public/testprogram/s_erfcf.c_e.c:141:38");
    computeFSub((Addr)&temp_var_for_tac_124, {(Addr)&z, (Addr)&x},
                "/home/shijia/Public/testprogram/s_erfcf.c_e.c:142:27");
    computeFAdd((Addr)&temp_var_for_tac_125, {(Addr)&z, (Addr)&x},
                "/home/shijia/Public/testprogram/s_erfcf.c_e.c:142:37");
    computeFMul((Addr)&temp_var_for_tac_126,
                {(Addr)&temp_var_for_tac_124, (Addr)&temp_var_for_tac_125},
                "/home/shijia/Public/testprogram/s_erfcf.c_e.c:142:32");
    computeFDiv((Addr)&temp_var_for_tac_127, {(Addr)&R, (Addr)&S},
                "/home/shijia/Public/testprogram/s_erfcf.c_e.c:142:46");
    computeFAdd((Addr)&temp_var_for_tac_128,
                {(Addr)&temp_var_for_tac_126, (Addr)&temp_var_for_tac_127},
                "/home/shijia/Public/testprogram/s_erfcf.c_e.c:142:42");
    computeFMul((Addr)&temp_var_for_tac_129,
                {(Addr) &(temp_var_for_const_78 = temp_var_for_callexp_2),
                 (Addr) &(temp_var_for_const_77 = temp_var_for_callexp_3)},
                "/home/shijia/Public/testprogram/s_erfcf.c_e.c:141:49");
    AssignF({(Addr)&r}, (Addr)&temp_var_for_tac_129,
            "/home/shijia/Public/testprogram/s_erfcf.c_e.c:141:7");
    ;
    if (hx > 0) {
      float temp_var_for_ext_9;
      float temp_var_for_tac_130;
      temp_var_for_tac_130 = r / x;

      temp_var_for_ext_9 = temp_var_for_tac_130;
      computeFDiv((Addr)&temp_var_for_tac_130, {(Addr)&r, (Addr)&x},
                  "/home/shijia/Public/testprogram/s_erfcf.c_e.c:145:30");
      AssignF({(Addr)&temp_var_for_ext_9}, (Addr)&temp_var_for_tac_130,
              "/home/shijia/Public/testprogram/s_erfcf.c_e.c:145:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_9;
    }

    else {
      float temp_var_for_ext_10;
      float temp_var_for_tac_131, temp_var_for_tac_132;
      float temp_var_for_const_79;
      temp_var_for_tac_131 = r / x;

      temp_var_for_tac_132 = two - temp_var_for_tac_131;

      temp_var_for_ext_10 = temp_var_for_tac_132;
      computeFDiv((Addr)&temp_var_for_tac_131, {(Addr)&r, (Addr)&x},
                  "/home/shijia/Public/testprogram/s_erfcf.c_e.c:154:37");
      computeFSub(
          (Addr)&temp_var_for_tac_132,
          {(Addr) &(temp_var_for_const_79 = two), (Addr)&temp_var_for_tac_131},
          "/home/shijia/Public/testprogram/s_erfcf.c_e.c:154:33");
      AssignF({(Addr)&temp_var_for_ext_10}, (Addr)&temp_var_for_tac_132,
              "/home/shijia/Public/testprogram/s_erfcf.c_e.c:154:27");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_10", (Addr)&temp_var_for_ext_10));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_10;
    }
  }
#ifdef _WIN32
  __set_errno(ERANGE);
#endif
  if (hx > 0) {
    float temp_var_for_ext_11;
    float temp_var_for_tac_133;
    float temp_var_for_const_80, temp_var_for_const_81;
    temp_var_for_tac_133 = tiny * tiny;

    temp_var_for_ext_11 = temp_var_for_tac_133;
    computeFMul((Addr)&temp_var_for_tac_133,
                {(Addr) &(temp_var_for_const_81 = tiny),
                 (Addr) &(temp_var_for_const_80 = tiny)},
                "/home/shijia/Public/testprogram/s_erfcf.c_e.c:166:32");
    AssignF({(Addr)&temp_var_for_ext_11}, (Addr)&temp_var_for_tac_133,
            "/home/shijia/Public/testprogram/s_erfcf.c_e.c:166:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_11", (Addr)&temp_var_for_ext_11));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_11;
  }

  float temp_var_for_ext_12;
  float temp_var_for_tac_134;
  float temp_var_for_const_82, temp_var_for_const_83;
  temp_var_for_tac_134 = two - tiny;

  temp_var_for_ext_12 = temp_var_for_tac_134;
  computeFSub((Addr)&temp_var_for_tac_134,
              {(Addr) &(temp_var_for_const_83 = two),
               (Addr) &(temp_var_for_const_82 = tiny)},
              "/home/shijia/Public/testprogram/s_erfcf.c_e.c:174:29");
  AssignF({(Addr)&temp_var_for_ext_12}, (Addr)&temp_var_for_tac_134,
          "/home/shijia/Public/testprogram/s_erfcf.c_e.c:174:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_12", (Addr)&temp_var_for_ext_12));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_12;
}

__typeof(__erfcf) erfcf __attribute__((weak, alias("__erfcf")));
