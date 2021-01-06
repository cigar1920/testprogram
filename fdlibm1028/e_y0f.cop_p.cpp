#include "../ScDebug/scdebug.h"
/* e_y0f.c -- float version of e_y0.c.
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

float __ieee754_y0f(float x) {
  float z, s, c, ss, cc, u, v;
  int32_t hx, ix;

  static const float one = 1.0;
  static const float invsqrtpi = 5.6418961287e-01; /* 0x3f106ebb */
  static const float tpi = 6.3661974669e-01;       /* 0x3f22f983 */
  static const float zero = 0.0;

  static const float u00 = (double temp_var_for_tac_0;
                            double temp_var_for_const_0, temp_var_for_const_1;
                            temp_var_for_tac_0 = 0.0 - 7.3804296553e-02;

                            );               /* 0xbd9726b5 */
  static const float u01 = 1.7666645348e-01; /* 0x3e34e80d */
  static const float u02 = (double temp_var_for_tac_1;
                            double temp_var_for_const_2, temp_var_for_const_3;
                            temp_var_for_tac_1 = 0.0 - 1.3818567619e-02;

                            );               /* 0xbc626746 */
  static const float u03 = 3.4745343146e-04; /* 0x39b62a69 */
  static const float u04 = (double temp_var_for_tac_2;
                            double temp_var_for_const_4, temp_var_for_const_5;
                            temp_var_for_tac_2 = 0.0 - 3.8140706238e-06;

                            );               /* 0xb67ff53c */
  static const float u05 = 1.9559013964e-08; /* 0x32a802ba */
  static const float u06 = (double temp_var_for_tac_3;
                            double temp_var_for_const_6, temp_var_for_const_7;
                            temp_var_for_tac_3 = 0.0 - 3.9820518410e-11;

                            );               /* 0xae2f21eb */
  static const float v01 = 1.2730483897e-02; /* 0x3c509385 */
  static const float v02 = 7.6006865129e-05; /* 0x389f65e0 */
  static const float v03 = 2.5915085189e-07; /* 0x348b216c */
  static const float v04 = 4.4111031494e-10; /* 0x2ff280c2 */

  GET_FLOAT_WORD(hx, x);
  ix = IC(0x7fffffff) & hx;
  /* Y0(NaN) is NaN, y0(-inf) is Nan, y0(inf) is 0, y0(0) is -inf.  */
  if (!FLT_UWORD_IS_FINITE(ix)) {
    float temp_var_for_ext_0;
    float temp_var_for_tac_4, temp_var_for_tac_5, temp_var_for_tac_6;
    float temp_var_for_const_8;
    temp_var_for_tac_4 = x * x;

    temp_var_for_tac_5 = x + temp_var_for_tac_4;

    temp_var_for_tac_6 = one / temp_var_for_tac_5;

    temp_var_for_ext_0 = temp_var_for_tac_6;
    computeDSub((Addr)&temp_var_for_tac_0,
                {(Addr) &(temp_var_for_const_1 = 0.0),
                 (Addr) &(temp_var_for_const_0 = 7.3804296553e-02)},
                "/home/shijia/Public/testprogram/e_y0f.c_e.c:29:33");
    computeDSub((Addr)&temp_var_for_tac_1,
                {(Addr) &(temp_var_for_const_3 = 0.0),
                 (Addr) &(temp_var_for_const_2 = 1.3818567619e-02)},
                "/home/shijia/Public/testprogram/e_y0f.c_e.c:31:33");
    computeDSub((Addr)&temp_var_for_tac_2,
                {(Addr) &(temp_var_for_const_5 = 0.0),
                 (Addr) &(temp_var_for_const_4 = 3.8140706238e-06)},
                "/home/shijia/Public/testprogram/e_y0f.c_e.c:33:33");
    computeDSub((Addr)&temp_var_for_tac_3,
                {(Addr) &(temp_var_for_const_7 = 0.0),
                 (Addr) &(temp_var_for_const_6 = 3.9820518410e-11)},
                "/home/shijia/Public/testprogram/e_y0f.c_e.c:35:33");
    computeFMul((Addr)&temp_var_for_tac_4, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_y0f.c_e.c:46:39");
    computeFAdd((Addr)&temp_var_for_tac_5,
                {(Addr)&x, (Addr)&temp_var_for_tac_4},
                "/home/shijia/Public/testprogram/e_y0f.c_e.c:46:35");
    computeFDiv(
        (Addr)&temp_var_for_tac_6,
        {(Addr) &(temp_var_for_const_8 = one), (Addr)&temp_var_for_tac_5},
        "/home/shijia/Public/testprogram/e_y0f.c_e.c:46:30");
    AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_6,
            "/home/shijia/Public/testprogram/e_y0f.c_e.c:46:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  if (FLT_UWORD_IS_ZERO(ix)) {
    float temp_var_for_ext_1;
    float temp_var_for_tac_7;
    float temp_var_for_const_9;
    temp_var_for_callexp_0 = __builtin_huge_valf();
    temp_var_for_tac_7 = (-(temp_var_for_callexp_0)) + x;

    temp_var_for_ext_1 = temp_var_for_tac_7;
    computeFAdd((Addr)&temp_var_for_tac_7,
                {(Addr) &(temp_var_for_const_9 = (-(temp_var_for_callexp_0))),
                 (Addr)&x},
                "/home/shijia/Public/testprogram/e_y0f.c_e.c:54:37");
    AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_7,
            "/home/shijia/Public/testprogram/e_y0f.c_e.c:54:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return (0.0 - var_for_e)xt_1;
  }
  /* -inf and overflow exception.  */
  if (hx < 0) {
    float temp_var_for_ext_2;
    float temp_var_for_tac_8, temp_var_for_tac_9;
    float temp_var_for_const_10, temp_var_for_const_11;
    temp_var_for_tac_8 = zero * x;

    temp_var_for_tac_9 = zero / temp_var_for_tac_8;

    temp_var_for_ext_2 = temp_var_for_tac_9;
    computeFMul((Addr)&temp_var_for_tac_8,
                {(Addr) &(temp_var_for_const_10 = zero), (Addr)&x},
                "/home/shijia/Public/testprogram/e_y0f.c_e.c:62:39");
    computeFDiv(
        (Addr)&temp_var_for_tac_9,
        {(Addr) &(temp_var_for_const_11 = zero), (Addr)&temp_var_for_tac_8},
        "/home/shijia/Public/testprogram/e_y0f.c_e.c:62:31");
    AssignF({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_9,
            "/home/shijia/Public/testprogram/e_y0f.c_e.c:62:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  }

  if (ix >= IC(0x40000000)) { /* |x| >= 2.0 */
    /* y0(x) = sqrt(2/(pi*x))*(p0(x)*sin(x0)+q0(x)*cos(x0))
     * where x0 = x-pi/4
     *      Better formula:
     *              cos(x0) = cos(x)cos(pi/4)+sin(x)sin(pi/4)
     *                      =  1/sqrt(2) * (sin(x) + cos(x))
     *              sin(x0) = sin(x)cos(3pi/4)-cos(x)sin(3pi/4)
     *                      =  1/sqrt(2) * (sin(x) - cos(x))
     * To avoid cancellation, use
     *              sin(x) +- cos(x) = -cos(2x)/(sin(x) -+ cos(x))
     * to compute the worse one.
     */
    __ieee754_sincosf(x, &s, &c);
    float temp_var_for_tac_10;
    temp_var_for_tac_10 = s - c;

    ss = temp_var_for_tac_10;
    computeFSub((Addr)&temp_var_for_tac_10, {(Addr)&s, (Addr)&c},
                "/home/shijia/Public/testprogram/e_y0f.c_e.c:81:12");
    AssignF({(Addr)&ss}, (Addr)&temp_var_for_tac_10,
            "/home/shijia/Public/testprogram/e_y0f.c_e.c:81:8");
    ;
    float temp_var_for_tac_11;
    temp_var_for_tac_11 = s + c;

    cc = temp_var_for_tac_11;
    computeFAdd((Addr)&temp_var_for_tac_11, {(Addr)&s, (Addr)&c},
                "/home/shijia/Public/testprogram/e_y0f.c_e.c:82:12");
    AssignF({(Addr)&cc}, (Addr)&temp_var_for_tac_11,
            "/home/shijia/Public/testprogram/e_y0f.c_e.c:82:8");
    ;
    /*
     * j0(x) = 1/sqrt(pi) * (P(0,x)*cc - Q(0,x)*ss) / sqrt(x)
     * y0(x) = 1/sqrt(pi) * (P(0,x)*ss + Q(0,x)*cc) / sqrt(x)
     */
    if (ix <= FLT_UWORD_HALF_MAX) { /* make sure x+x not overflow */
      float temp_var_for_tac_12, temp_var_for_tac_13;
      float temp_var_for_const_12, temp_var_for_const_13;
      float temp_var_for_callexp_1;

      temp_var_for_tac_12 = x + x;

      temp_var_for_callexp_1 = __ieee754_cosf(temp_var_for_tac_12);
      temp_var_for_tac_13 = 0.0 - temp_var_for_callexp_1;

      z = temp_var_for_tac_13;
      computeFAdd((Addr)&temp_var_for_tac_12, {(Addr)&x, (Addr)&x},
                  "/home/shijia/Public/testprogram/e_y0f.c_e.c:88:35");
      computeDSub((Addr)&temp_var_for_tac_13,
                  {(Addr) &(temp_var_for_const_13 = 0.0),
                   (Addr) &(temp_var_for_const_12 = temp_var_for_callexp_1)},
                  "/home/shijia/Public/testprogram/e_y0f.c_e.c:88:16");
      AssignF({(Addr)&z}, (Addr)&temp_var_for_tac_13,
              "/home/shijia/Public/testprogram/e_y0f.c_e.c:88:9");
      ;
      if (int temp_var_for_tac_14, temp_var_for_tac_15;
          int temp_var_for_const_14; temp_var_for_tac_14 = s * c;

          temp_var_for_tac_15 = temp_var_for_tac_14 < zero;

          ) {
        float temp_var_for_tac_16;
        temp_var_for_tac_16 = z / ss;

        cc = temp_var_for_tac_16;
        computeFMul((Addr)&temp_var_for_tac_14, {(Addr)&s, (Addr)&c},
                    "/home/shijia/Public/testprogram/e_y0f.c_e.c:89:14");
        compute((Addr)&temp_var_for_tac_15,
                {(Addr)&temp_var_for_tac_14,
                 (Addr) &(temp_var_for_const_14 = zero)},
                "/home/shijia/Public/testprogram/e_y0f.c_e.c:89:19");
        computeFDiv((Addr)&temp_var_for_tac_16, {(Addr)&z, (Addr)&ss},
                    "/home/shijia/Public/testprogram/e_y0f.c_e.c:90:16");
        AssignF({(Addr)&cc}, (Addr)&temp_var_for_tac_16,
                "/home/shijia/Public/testprogram/e_y0f.c_e.c:90:12");
        ;
      }

      else {
        float temp_var_for_ext_3;
        float temp_var_for_tac_17;
        temp_var_for_tac_17 = z / cc;

        temp_var_for_ext_3 = temp_var_for_tac_17;
        computeFDiv((Addr)&temp_var_for_tac_17, {(Addr)&z, (Addr)&cc},
                    "/home/shijia/Public/testprogram/e_y0f.c_e.c:95:32");
        AssignF({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_17,
                "/home/shijia/Public/testprogram/e_y0f.c_e.c:95:28");
        ; // ss
        /*(ss)(z)(cc)(z)*/
        ss = temp_var_for_ext_3;
        AssignF({(Addr)&ss}, (Addr)&temp_var_for_ext_3,
                "/home/shijia/Public/testprogram/e_y0f.c_e.c:97:12");
        ;
      }
    }
    if (ix > IC(0x48000000)) {
      float temp_var_for_ext_4;
      float temp_var_for_tac_18, temp_var_for_tac_19;
      float temp_var_for_const_15, temp_var_for_const_16;
      float temp_var_for_callexp_2;

      temp_var_for_tac_18 = invsqrtpi * ss;

      temp_var_for_callexp_2 = __ieee754_sqrtf(x);
      temp_var_for_tac_19 = temp_var_for_tac_18 / temp_var_for_callexp_2;

      temp_var_for_ext_4 = temp_var_for_tac_19;
      computeFMul((Addr)&temp_var_for_tac_18,
                  {(Addr) &(temp_var_for_const_15 = invsqrtpi), (Addr)&ss},
                  "/home/shijia/Public/testprogram/e_y0f.c_e.c:102:39");
      computeFDiv((Addr)&temp_var_for_tac_19,
                  {(Addr)&temp_var_for_tac_18,
                   (Addr) &(temp_var_for_const_16 = temp_var_for_callexp_2)},
                  "/home/shijia/Public/testprogram/e_y0f.c_e.c:102:45");
      AssignF({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_19,
              "/home/shijia/Public/testprogram/e_y0f.c_e.c:102:26");
      ; // z
      /*(cc)(z)(__ieee754_sqrtf(x))(ss)(invsqrtpi)*/
      z = temp_var_for_ext_4;
      AssignF({(Addr)&z}, (Addr)&temp_var_for_ext_4,
              "/home/shijia/Public/testprogram/e_y0f.c_e.c:104:9");
      ;
    }

    else {
      float temp_var_for_const_17;
      float temp_var_for_callexp_3;

      temp_var_for_callexp_3 = __j0_y0_pzerof(x);
      u = temp_var_for_callexp_3;
      AssignF({(Addr)&u},
              (Addr) &(temp_var_for_const_17 = temp_var_for_callexp_3),
              "/home/shijia/Public/testprogram/e_y0f.c_e.c:108:9");
      ;
      float temp_var_for_const_18;
      float temp_var_for_callexp_4;

      temp_var_for_callexp_4 = __j0_y0_qzerof(x);
      v = temp_var_for_callexp_4;
      AssignF({(Addr)&v},
              (Addr) &(temp_var_for_const_18 = temp_var_for_callexp_4),
              "/home/shijia/Public/testprogram/e_y0f.c_e.c:109:9");
      ;
      float temp_var_for_tac_20, temp_var_for_tac_21, temp_var_for_tac_22,
          temp_var_for_tac_23, temp_var_for_tac_24;
      float temp_var_for_const_19, temp_var_for_const_20;
      float temp_var_for_callexp_5;

      temp_var_for_tac_20 = u * ss;

      temp_var_for_tac_21 = v * cc;

      temp_var_for_tac_22 = temp_var_for_tac_20 + temp_var_for_tac_21;

      temp_var_for_tac_23 = invsqrtpi * temp_var_for_tac_22;

      temp_var_for_callexp_5 = __ieee754_sqrtf(x);
      temp_var_for_tac_24 = temp_var_for_tac_23 / temp_var_for_callexp_5;

      z = temp_var_for_tac_24;
      computeFMul((Addr)&temp_var_for_tac_20, {(Addr)&u, (Addr)&ss},
                  "/home/shijia/Public/testprogram/e_y0f.c_e.c:110:26");
      computeFMul((Addr)&temp_var_for_tac_21, {(Addr)&v, (Addr)&cc},
                  "/home/shijia/Public/testprogram/e_y0f.c_e.c:110:35");
      computeFAdd((Addr)&temp_var_for_tac_22,
                  {(Addr)&temp_var_for_tac_20, (Addr)&temp_var_for_tac_21},
                  "/home/shijia/Public/testprogram/e_y0f.c_e.c:110:31");
      computeFMul((Addr)&temp_var_for_tac_23,
                  {(Addr) &(temp_var_for_const_19 = invsqrtpi),
                   (Addr)&temp_var_for_tac_22},
                  "/home/shijia/Public/testprogram/e_y0f.c_e.c:110:21");
      computeFDiv((Addr)&temp_var_for_tac_24,
                  {(Addr)&temp_var_for_tac_23,
                   (Addr) &(temp_var_for_const_20 = temp_var_for_callexp_5)},
                  "/home/shijia/Public/testprogram/e_y0f.c_e.c:110:41");
      AssignF({(Addr)&z}, (Addr)&temp_var_for_tac_24,
              "/home/shijia/Public/testprogram/e_y0f.c_e.c:110:9");
      ;
    }
    float temp_var_for_ext_5;
    temp_var_for_ext_5 = z;
    AssignF({(Addr)&temp_var_for_ext_5}, (Addr)&z,
            "/home/shijia/Public/testprogram/e_y0f.c_e.c:113:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_5;
  }
  if (ix <= IC(0x39800000)) { /* x < 2**-13 */
    float temp_var_for_ext_6;
    float temp_var_for_tac_25, temp_var_for_tac_26;
    float temp_var_for_const_21, temp_var_for_const_22, temp_var_for_const_23;
    float temp_var_for_callexp_6;

    temp_var_for_callexp_6 = __ieee754_logf(x);
    temp_var_for_tac_25 = tpi * temp_var_for_callexp_6;

    temp_var_for_tac_26 = u00 + temp_var_for_tac_25;

    temp_var_for_ext_6 = temp_var_for_tac_26;
    computeFMul((Addr)&temp_var_for_tac_25,
                {(Addr) &(temp_var_for_const_22 = tpi),
                 (Addr) &(temp_var_for_const_21 = temp_var_for_callexp_6)},
                "/home/shijia/Public/testprogram/e_y0f.c_e.c:120:37");
    computeFAdd(
        (Addr)&temp_var_for_tac_26,
        {(Addr) &(temp_var_for_const_23 = u00), (Addr)&temp_var_for_tac_25},
        "/home/shijia/Public/testprogram/e_y0f.c_e.c:120:31");
    AssignF({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_26,
            "/home/shijia/Public/testprogram/e_y0f.c_e.c:120:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_6;
  }
  float temp_var_for_tac_27;
  temp_var_for_tac_27 = x * x;

  z = temp_var_for_tac_27;
  computeFMul((Addr)&temp_var_for_tac_27, {(Addr)&x, (Addr)&x},
              "/home/shijia/Public/testprogram/e_y0f.c_e.c:125:9");
  AssignF({(Addr)&z}, (Addr)&temp_var_for_tac_27,
          "/home/shijia/Public/testprogram/e_y0f.c_e.c:125:5");
  ;
  float temp_var_for_tac_28, temp_var_for_tac_29, temp_var_for_tac_30,
      temp_var_for_tac_31, temp_var_for_tac_32, temp_var_for_tac_33,
      temp_var_for_tac_34, temp_var_for_tac_35, temp_var_for_tac_36,
      temp_var_for_tac_37, temp_var_for_tac_38, temp_var_for_tac_39;
  float temp_var_for_const_24, temp_var_for_const_25, temp_var_for_const_26,
      temp_var_for_const_27, temp_var_for_const_28, temp_var_for_const_29,
      temp_var_for_const_30;
  temp_var_for_tac_28 = z * u06;

  temp_var_for_tac_29 = u05 + temp_var_for_tac_28;

  temp_var_for_tac_30 = z * temp_var_for_tac_29;

  temp_var_for_tac_31 = u04 + temp_var_for_tac_30;

  temp_var_for_tac_32 = z * temp_var_for_tac_31;

  temp_var_for_tac_33 = u03 + temp_var_for_tac_32;

  temp_var_for_tac_34 = z * temp_var_for_tac_33;

  temp_var_for_tac_35 = u02 + temp_var_for_tac_34;

  temp_var_for_tac_36 = z * temp_var_for_tac_35;

  temp_var_for_tac_37 = u01 + temp_var_for_tac_36;

  temp_var_for_tac_38 = z * temp_var_for_tac_37;

  temp_var_for_tac_39 = u00 + temp_var_for_tac_38;

  u = temp_var_for_tac_39;
  computeFMul((Addr)&temp_var_for_tac_28,
              {(Addr)&z, (Addr) &(temp_var_for_const_24 = u06)},
              "/home/shijia/Public/testprogram/e_y0f.c_e.c:126:70");
  computeFAdd(
      (Addr)&temp_var_for_tac_29,
      {(Addr) &(temp_var_for_const_25 = u05), (Addr)&temp_var_for_tac_28},
      "/home/shijia/Public/testprogram/e_y0f.c_e.c:126:66");
  computeFMul((Addr)&temp_var_for_tac_30,
              {(Addr)&z, (Addr)&temp_var_for_tac_29},
              "/home/shijia/Public/testprogram/e_y0f.c_e.c:126:59");
  computeFAdd(
      (Addr)&temp_var_for_tac_31,
      {(Addr) &(temp_var_for_const_26 = u04), (Addr)&temp_var_for_tac_30},
      "/home/shijia/Public/testprogram/e_y0f.c_e.c:126:55");
  computeFMul((Addr)&temp_var_for_tac_32,
              {(Addr)&z, (Addr)&temp_var_for_tac_31},
              "/home/shijia/Public/testprogram/e_y0f.c_e.c:126:48");
  computeFAdd(
      (Addr)&temp_var_for_tac_33,
      {(Addr) &(temp_var_for_const_27 = u03), (Addr)&temp_var_for_tac_32},
      "/home/shijia/Public/testprogram/e_y0f.c_e.c:126:44");
  computeFMul((Addr)&temp_var_for_tac_34,
              {(Addr)&z, (Addr)&temp_var_for_tac_33},
              "/home/shijia/Public/testprogram/e_y0f.c_e.c:126:37");
  computeFAdd(
      (Addr)&temp_var_for_tac_35,
      {(Addr) &(temp_var_for_const_28 = u02), (Addr)&temp_var_for_tac_34},
      "/home/shijia/Public/testprogram/e_y0f.c_e.c:126:33");
  computeFMul((Addr)&temp_var_for_tac_36,
              {(Addr)&z, (Addr)&temp_var_for_tac_35},
              "/home/shijia/Public/testprogram/e_y0f.c_e.c:126:26");
  computeFAdd(
      (Addr)&temp_var_for_tac_37,
      {(Addr) &(temp_var_for_const_29 = u01), (Addr)&temp_var_for_tac_36},
      "/home/shijia/Public/testprogram/e_y0f.c_e.c:126:22");
  computeFMul((Addr)&temp_var_for_tac_38,
              {(Addr)&z, (Addr)&temp_var_for_tac_37},
              "/home/shijia/Public/testprogram/e_y0f.c_e.c:126:15");
  computeFAdd(
      (Addr)&temp_var_for_tac_39,
      {(Addr) &(temp_var_for_const_30 = u00), (Addr)&temp_var_for_tac_38},
      "/home/shijia/Public/testprogram/e_y0f.c_e.c:126:11");
  AssignF({(Addr)&u}, (Addr)&temp_var_for_tac_39,
          "/home/shijia/Public/testprogram/e_y0f.c_e.c:126:5");
  ;
  float temp_var_for_tac_40, temp_var_for_tac_41, temp_var_for_tac_42,
      temp_var_for_tac_43, temp_var_for_tac_44, temp_var_for_tac_45,
      temp_var_for_tac_46, temp_var_for_tac_47;
  float temp_var_for_const_31, temp_var_for_const_32, temp_var_for_const_33,
      temp_var_for_const_34, temp_var_for_const_35;
  temp_var_for_tac_40 = z * v04;

  temp_var_for_tac_41 = v03 + temp_var_for_tac_40;

  temp_var_for_tac_42 = z * temp_var_for_tac_41;

  temp_var_for_tac_43 = v02 + temp_var_for_tac_42;

  temp_var_for_tac_44 = z * temp_var_for_tac_43;

  temp_var_for_tac_45 = v01 + temp_var_for_tac_44;

  temp_var_for_tac_46 = z * temp_var_for_tac_45;

  temp_var_for_tac_47 = one + temp_var_for_tac_46;

  v = temp_var_for_tac_47;
  computeFMul((Addr)&temp_var_for_tac_40,
              {(Addr)&z, (Addr) &(temp_var_for_const_31 = v04)},
              "/home/shijia/Public/testprogram/e_y0f.c_e.c:127:48");
  computeFAdd(
      (Addr)&temp_var_for_tac_41,
      {(Addr) &(temp_var_for_const_32 = v03), (Addr)&temp_var_for_tac_40},
      "/home/shijia/Public/testprogram/e_y0f.c_e.c:127:44");
  computeFMul((Addr)&temp_var_for_tac_42,
              {(Addr)&z, (Addr)&temp_var_for_tac_41},
              "/home/shijia/Public/testprogram/e_y0f.c_e.c:127:37");
  computeFAdd(
      (Addr)&temp_var_for_tac_43,
      {(Addr) &(temp_var_for_const_33 = v02), (Addr)&temp_var_for_tac_42},
      "/home/shijia/Public/testprogram/e_y0f.c_e.c:127:33");
  computeFMul((Addr)&temp_var_for_tac_44,
              {(Addr)&z, (Addr)&temp_var_for_tac_43},
              "/home/shijia/Public/testprogram/e_y0f.c_e.c:127:26");
  computeFAdd(
      (Addr)&temp_var_for_tac_45,
      {(Addr) &(temp_var_for_const_34 = v01), (Addr)&temp_var_for_tac_44},
      "/home/shijia/Public/testprogram/e_y0f.c_e.c:127:22");
  computeFMul((Addr)&temp_var_for_tac_46,
              {(Addr)&z, (Addr)&temp_var_for_tac_45},
              "/home/shijia/Public/testprogram/e_y0f.c_e.c:127:15");
  computeFAdd(
      (Addr)&temp_var_for_tac_47,
      {(Addr) &(temp_var_for_const_35 = one), (Addr)&temp_var_for_tac_46},
      "/home/shijia/Public/testprogram/e_y0f.c_e.c:127:11");
  AssignF({(Addr)&v}, (Addr)&temp_var_for_tac_47,
          "/home/shijia/Public/testprogram/e_y0f.c_e.c:127:5");
  ;
  float temp_var_for_ext_7;
  float temp_var_for_tac_48, temp_var_for_tac_49, temp_var_for_tac_50,
      temp_var_for_tac_51;
  float temp_var_for_const_36, temp_var_for_const_37, temp_var_for_const_38;
  float temp_var_for_callexp_7;

  float temp_var_for_callexp_8;

  temp_var_for_tac_48 = u / v;

  temp_var_for_callexp_7 = __ieee754_j0f(x);
  temp_var_for_callexp_8 = __ieee754_logf(x);
  temp_var_for_tac_49 = temp_var_for_callexp_7 * temp_var_for_callexp_8;

  temp_var_for_tac_50 = tpi * temp_var_for_tac_49;

  temp_var_for_tac_51 = temp_var_for_tac_48 + temp_var_for_tac_50;

  temp_var_for_ext_7 = temp_var_for_tac_51;
  computeFDiv((Addr)&temp_var_for_tac_48, {(Addr)&u, (Addr)&v},
              "/home/shijia/Public/testprogram/e_y0f.c_e.c:129:27");
  computeFMul((Addr)&temp_var_for_tac_49,
              {(Addr) &(temp_var_for_const_37 = temp_var_for_callexp_7),
               (Addr) &(temp_var_for_const_36 = temp_var_for_callexp_8)},
              "/home/shijia/Public/testprogram/e_y0f.c_e.c:129:57");
  computeFMul(
      (Addr)&temp_var_for_tac_50,
      {(Addr) &(temp_var_for_const_38 = tpi), (Addr)&temp_var_for_tac_49},
      "/home/shijia/Public/testprogram/e_y0f.c_e.c:129:37");
  computeFAdd((Addr)&temp_var_for_tac_51,
              {(Addr)&temp_var_for_tac_48, (Addr)&temp_var_for_tac_50},
              "/home/shijia/Public/testprogram/e_y0f.c_e.c:129:31");
  AssignF({(Addr)&temp_var_for_ext_7}, (Addr)&temp_var_for_tac_51,
          "/home/shijia/Public/testprogram/e_y0f.c_e.c:129:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_7;
}

/* wrapper y0 */
float __y0f(float x) {
  if ((islessequal(x, 0.0F) || isgreater(x, X_TLOSS)) &&
      _LIB_VERSION != _IEEE_) {
    if (int temp_var_for_tac_52; int temp_var_for_const_39;
        temp_var_for_tac_52 = x < 0.0F;

        ) {
      /* d = zero/(x-x) */
      feraiseexcept(FE_INVALID);
      float temp_var_for_ext_8;
      float temp_var_for_const_40;
      float temp_var_for_callexp_10;

      temp_var_for_callexp_9 = __builtin_huge_valf();
      temp_var_for_callexp_10 = __kernel_standard_f(
          x, x, (-(temp_var_for_callexp_9)), KMATHERRF_Y0_MINUS);
      temp_var_for_ext_8 = temp_var_for_callexp_10;
      compute((Addr)&temp_var_for_tac_52,
              {(Addr)&x, (Addr) &(temp_var_for_const_39 = 0.0F)},
              "/home/shijia/Public/testprogram/e_y0f.c_e.c:139:11");
      AssignF({(Addr)&temp_var_for_ext_8},
              (Addr) &(temp_var_for_const_40 = temp_var_for_callexp_10),
              "/home/shijia/Public/testprogram/e_y0f.c_e.c:143:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
      callExp++; /*identify the function is  add move tmpSha(0.0 - ow*/
retu)rn temp_var_for_ext_8;
    } else {
      if (int temp_var_for_tac_53; int temp_var_for_const_41;
          temp_var_for_tac_53 = x == 0.0F;

          )
      /* d = -one/(x-x) */
      {
        float temp_var_for_ext_9;
        float temp_var_for_const_42;
        float temp_var_for_callexp_12;

        temp_var_for_callexp_11 = __builtin_huge_valf();
        temp_var_for_callexp_12 = __kernel_standard_f(
            x, x, (-(temp_var_for_callexp_11)), KMATHERRF_Y0_ZERO);
        temp_var_for_ext_9 = temp_var_for_callexp_12;
        compute((Addr)&temp_var_for_tac_53,
                {(Addr)&x, (Addr) &(temp_var_for_const_41 = 0.0F)},
                "/home/shijia/Public/testprogram/e_y0f.c_e.c:150:13");
        AssignF({(Addr)&temp_var_for_ext_9},
                (Addr) &(temp_var_for_const_42 = temp_var_for_callexp_12),
                "/home/shijia/Public/testprogram/e_y0f.c_e.c:154:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
        callExp++; /*identify the function is  add move tmpShad(0.0 - w*/
retur)n temp_var_for_ext_9;
      }

      else {
        if (_LIB_VERSION != _POSIX_)
        /* y0(x>X_TLOSS) */
        {
          float temp_var_for_ext_10;
          float temp_var_for_const_43;
          float temp_var_for_callexp_13;

          temp_var_for_callexp_13 =
              __kernel_standard_f(x, x, 0.0f, KMATHERRF_Y0_TLOSS);
          temp_var_for_ext_10 = temp_var_for_callexp_13;
          AssignF({(Addr)&temp_var_for_ext_10},
                  (Addr) &(temp_var_for_const_43 = temp_var_for_callexp_13),
                  "/home/shijia/Public/testprogram/e_y0f.c_e.c:167:31");
          ;
          callExpStack.push(
              getReal("temp_var_for_ext_10", (Addr)&temp_var_for_ext_10));
          callExp++; /*identify the function is  add move tmpShadow*/
          return temp_var_for_ext_10;
        }
      }
    }
  }

  float temp_var_for_ext_11;
  float temp_var_for_const_44;
  float temp_var_for_callexp_14;

  temp_var_for_callexp_14 = __ieee754_y0f(x);
  temp_var_for_ext_11 = temp_var_for_callexp_14;
  AssignF({(Addr)&temp_var_for_ext_11},
          (Addr) &(temp_var_for_const_44 = temp_var_for_callexp_14),
          "/home/shijia/Public/testprogram/e_y0f.c_e.c:179:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_11", (Addr)&temp_var_for_ext_11));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_11;
}

__typeof(__y0f) y0f __attribute__((weak, alias("__y0f")));
