#include "../ScDebug/scdebug.h"
/* e_lgammaf_r.c -- float version of e_lgamma_r.c.
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

static float sin_pif(float x) {
  float y, z;
  int32_t n, ix;

  static const float zero = 0.0000000000e+00;
  static const float one = 1.0000000000e+00;   /* 0x3f800000 */
  static const float pi = 3.1415927410e+00;    /* 0x40490fdb */
  static const float two23 = 8.3886080000e+06; /* 0x4b000000 */

  GET_FLOAT_WORD(ix, x);
  ix &= IC(0x7fffffff);

  if (ix < IC(0x3e800000))
#ifdef __have_fpu_sin
    return __ieee754_sinf(pi * x);
#else
  {
    float temp_var_for_ext_0;
    float temp_var_for_tac_0;
    float temp_var_for_const_0, temp_var_for_const_1;
    float temp_var_for_callexp_0;

    temp_var_for_tac_0 = pi * x;

    temp_var_for_callexp_0 = __kernel_sinf(temp_var_for_tac_0, zero, 0);
    temp_var_for_ext_0 = temp_var_for_callexp_0;
    computeFMul((Addr)&temp_var_for_tac_0,
                {(Addr) &(temp_var_for_const_0 = pi), (Addr)&x},
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:38:43");
    AssignF({(Addr)&temp_var_for_ext_0},
            (Addr) &(temp_var_for_const_1 = temp_var_for_callexp_0),
            "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:38:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

#endif
  float temp_var_for_tac_1;
  float temp_var_for_const_2;
  temp_var_for_tac_1 = 0.0 - x;

  y = temp_var_for_tac_1;
  computeDSub((Addr)&temp_var_for_tac_1,
              {(Addr) &(temp_var_for_const_2 = 0.0), (Addr)&x},
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:45:12");
  AssignF({(Addr)&y}, (Addr)&temp_var_for_tac_1,
          "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:45:5");
  ; /* x is assume negative */

  /*
   * argument reduction, make sure inexact flag not raised if input
   * is an integer
   */
  float temp_var_for_const_3;
  float temp_var_for_callexp_1;

  temp_var_for_callexp_1 = __ieee754_floorf(y);
  z = temp_var_for_callexp_1;
  AssignF({(Addr)&z}, (Addr) &(temp_var_for_const_3 = temp_var_for_callexp_1),
          "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:51:5");
  ;
  if (int temp_var_for_tac_2; temp_var_for_tac_2 = z != y;

      ) { /* inexact anyway */
    y *= 0.5F;
    ;
    float temp_var_for_ext_1;
    float temp_var_for_tac_4, temp_var_for_tac_5;
    float temp_var_for_const_4, temp_var_for_const_5;
    float temp_var_for_callexp_2;

    temp_var_for_callexp_2 = __ieee754_floorf(y);
    temp_var_for_tac_4 = y - temp_var_for_callexp_2;

    temp_var_for_tac_5 = 2.0F * temp_var_for_tac_4;

    temp_var_for_ext_1 = temp_var_for_tac_5;
    compute((Addr)&temp_var_for_tac_2, {(Addr)&z, (Addr)&y},
            "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:52:9");
    computeFSub(
        (Addr)&temp_var_for_tac_4,
        {(Addr)&y, (Addr) &(temp_var_for_const_4 = temp_var_for_callexp_2)},
        "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:55:36");
    computeFMul(
        (Addr)&temp_var_for_tac_5,
        {(Addr) &(temp_var_for_const_5 = 2.0F), (Addr)&temp_var_for_tac_4},
        "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:55:31");
    AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_5,
            "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:55:24");
    ; // y
    /*(0.5F)(y)(__ieee754_floorf(y))(y)(2.0F)*/
    y = temp_var_for_ext_1;
    AssignF({(Addr)&y}, (Addr)&temp_var_for_ext_1,
            "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:57:7");
    ; /* y = |x| mod 2.0 */
    n = (int32_t)(float temp_var_for_tac_6; float temp_var_for_const_6;
                  temp_var_for_tac_6 = y * 4.0F;

                  );
  } else {
    if (ix >= IC(0x4b800000)) {
      float temp_var_for_ext_2;
      float temp_var_for_const_7;
      temp_var_for_ext_2 = zero;
      computeFMul((Addr)&temp_var_for_tac_6,
                  {(Addr)&y, (Addr) &(temp_var_for_const_6 = 4.0F)},
                  "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:58:21");
      AssignF({(Addr)&temp_var_for_ext_2},
              (Addr) &(temp_var_for_const_7 = zero),
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:62:26");
      ; // y
      /*(__ieee754_floorf(y))(y)(2.0F)(__ieee754_floorf(y))(y)(4.0F)(y)(zero)*/
      y = temp_var_for_ext_2;
      AssignF({(Addr)&y}, (Addr)&temp_var_for_ext_2,
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:64:9");
      ;
      n = 0; /* y must be even */
    } else {
      if (ix < IC(0x4b000000)) {
        float temp_var_for_tac_7;
        float temp_var_for_const_8;
        temp_var_for_tac_7 = y + two23;

        z = temp_var_for_tac_7;
        computeFAdd((Addr)&temp_var_for_tac_7,
                    {(Addr)&y, (Addr) &(temp_var_for_const_8 = two23)},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:68:15");
        AssignF({(Addr)&z}, (Addr)&temp_var_for_tac_7,
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:68:11");
        ;
      }
      /* exact */
      GET_FLOAT_WORD(n, z);
      n &= 1;
      float temp_var_for_ext_3;
      float temp_var_for_const_9;
      temp_var_for_ext_3 = n;
      AssignF({(Addr)&temp_var_for_ext_3}, (Addr) &(temp_var_for_const_9 = n),
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:74:26");
      ; // y
      /*(two23)(y)(n)*/
      y = temp_var_for_ext_3;
      AssignF({(Addr)&y}, (Addr)&temp_var_for_ext_3,
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:76:9");
      ;
      n <<= 2;
    }
  }
#ifdef __have_fpu_sin
  switch ((int)n) {
  case 0:
    y = __ieee754_sinf(pi * y);
    break;
  case 1:
  case 2:
    y = __ieee754_cosf(pi * (0.5F - y));
    break;
  case 3:
  case 4:
    y = __ieee754_sinf(pi * (one - y));
    break;
  case 5:
  case 6:
    y = -__ieee754_cosf(pi * (y - 1.5F));
    break;
  default:
    y = __ieee754_sinf(pi * (y - 2.0F));
    break;
  }
#else
  int temp_var_for_ext_4;
  temp_var_for_ext_4 = (int)n;
  switch (temp_var_for_ext_4) {
  case 0: {
    float temp_var_for_tac_8;
    float temp_var_for_const_10, temp_var_for_const_11;
    float temp_var_for_callexp_3;

    temp_var_for_tac_8 = pi * y;

    temp_var_for_callexp_3 = __kernel_sinf(temp_var_for_tac_8, zero, 0);
    y = temp_var_for_callexp_3;
    computeFMul((Addr)&temp_var_for_tac_8,
                {(Addr) &(temp_var_for_const_10 = pi), (Addr)&y},
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:106:26");
    AssignF({(Addr)&y},
            (Addr) &(temp_var_for_const_11 = temp_var_for_callexp_3),
            "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:106:7");
    ;
  }

  break;
  case 1: {
  case 2: {
    float temp_var_for_ext_5;
    float temp_var_for_tac_9, temp_var_for_tac_10;
    float temp_var_for_const_12, temp_var_for_const_13, temp_var_for_const_14;
    float temp_var_for_callexp_4;

    temp_var_for_tac_9 = 0.5F - y;

    temp_var_for_tac_10 = pi * temp_var_for_tac_9;

    temp_var_for_callexp_4 = __kernel_cosf(temp_var_for_tac_10, zero);
    temp_var_for_ext_5 = temp_var_for_callexp_4;
    computeFSub((Addr)&temp_var_for_tac_9,
                {(Addr) &(temp_var_for_const_12 = 0.5F), (Addr)&y},
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:113:51");
    computeFMul(
        (Addr)&temp_var_for_tac_10,
        {(Addr) &(temp_var_for_const_13 = pi), (Addr)&temp_var_for_tac_9},
        "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:113:43");
    AssignF({(Addr)&temp_var_for_ext_5},
            (Addr) &(temp_var_for_const_14 = temp_var_for_callexp_4),
            "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:113:24");
    ; // y
    /*(y)(pi)(__kernel_cosf(pi * (0.5F - y), zero))*/
    y = temp_var_for_ext_5;
    AssignF({(Addr)&y}, (Addr)&temp_var_for_ext_5,
            "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:115:7");
    ;
  }

  }

  break;
  case 3: {
  case 4: {
    float temp_var_for_ext_6;
    float temp_var_for_tac_11, temp_var_for_tac_12;
    float temp_var_for_const_15, temp_var_for_const_16, temp_var_for_const_17;
    float temp_var_for_callexp_5;

    temp_var_for_tac_11 = one - y;

    temp_var_for_tac_12 = pi * temp_var_for_tac_11;

    temp_var_for_callexp_5 = __kernel_sinf(temp_var_for_tac_12, zero, 0);
    temp_var_for_ext_6 = temp_var_for_callexp_5;
    computeFSub((Addr)&temp_var_for_tac_11,
                {(Addr) &(temp_var_for_const_15 = one), (Addr)&y},
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:124:50");
    computeFMul(
        (Addr)&temp_var_for_tac_12,
        {(Addr) &(temp_var_for_const_16 = pi), (Addr)&temp_var_for_tac_11},
        "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:124:43");
    AssignF({(Addr)&temp_var_for_ext_6},
            (Addr) &(temp_var_for_const_17 = temp_var_for_callexp_5),
            "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:124:24");
    ; // y
    /*(y)(0.5F)(pi)(y)(0.5F)(__kernel_sinf(pi * (one - y), zero, 0))*/
    y = temp_var_for_ext_6;
    AssignF({(Addr)&y}, (Addr)&temp_var_for_ext_6,
            "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:126:7");
    ;
  }

  }

  break;
  case 5: {
  case 6: {
    float temp_var_for_ext_7;
    float temp_var_for_tac_13, temp_var_for_tac_14, temp_var_for_tac_15;
    float temp_var_for_const_18, temp_var_for_const_19, temp_var_for_const_20,
        temp_var_for_const_21;
    float temp_var_for_callexp_6;

    temp_var_for_tac_13 = y - 1.5F;

    temp_var_for_tac_14 = pi * temp_var_for_tac_13;

    temp_var_for_callexp_6 = __kernel_cosf(temp_var_for_tac_14, zero);
    temp_var_for_tac_15 = 0.0 - temp_var_for_callexp_6;

    temp_var_for_ext_7 = temp_var_for_tac_15;
    computeFSub((Addr)&temp_var_for_tac_13,
                {(Addr)&y, (Addr) &(temp_var_for_const_18 = 1.5F)},
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:135:55");
    computeFMul(
        (Addr)&temp_var_for_tac_14,
        {(Addr) &(temp_var_for_const_19 = pi), (Addr)&temp_var_for_tac_13},
        "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:135:50");
    computeDSub((Addr)&temp_var_for_tac_15,
                {(Addr) &(temp_var_for_const_21 = 0.0),
                 (Addr) &(temp_var_for_const_20 = temp_var_for_callexp_6)},
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:135:31");
    AssignF({(Addr)&temp_var_for_ext_7}, (Addr)&temp_var_for_tac_15,
            "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:135:24");
    ; // y
      /*(y)(one)(pi)(y)(one)(__kernel_cosf(pi * (y - 1.5F),
       * zero))(__kernel_cosf(pi * (y - 1.5F), zero))*/
    y = temp_var_for_ext_7;
    AssignF({(Addr)&y}, (Addr)&temp_var_for_ext_7,
            "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:138:7");
    ;
  }

  }

  break;
  default: {
    float temp_var_for_tac_16, temp_var_for_tac_17;
    float temp_var_for_const_22, temp_var_for_const_23, temp_var_for_const_24;
    float temp_var_for_callexp_7;

    temp_var_for_tac_16 = y - 2.0F;

    temp_var_for_tac_17 = pi * temp_var_for_tac_16;

    temp_var_for_callexp_7 = __kernel_sinf(temp_var_for_tac_17, zero, 0);
    y = temp_var_for_callexp_7;
    computeFSub((Addr)&temp_var_for_tac_16,
                {(Addr)&y, (Addr) &(temp_var_for_const_22 = 2.0F)},
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:145:31");
    computeFMul(
        (Addr)&temp_var_for_tac_17,
        {(Addr) &(temp_var_for_const_23 = pi), (Addr)&temp_var_for_tac_16},
        "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:145:26");
    AssignF({(Addr)&y},
            (Addr) &(temp_var_for_const_24 = temp_var_for_callexp_7),
            "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:145:7");
    ;
  }

  break;
  }
#endif
  float temp_var_for_ext_8;
  float temp_var_for_const_25;
  temp_var_for_ext_8 = (-(y));
  AssignF({(Addr)&temp_var_for_ext_8}, (Addr) &(temp_var_for_const_25 = (-(y))),
          "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:152:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
  callExp++; /*identify the function is  add move tmpShadow*/
  return (double temp_var_for_tac_18;
          double temp_var_for_const_26, temp_var_for_const_27;
          temp_var_for_tac_18 = 0.0 - 8;

          );
}

float __ieee754_lgammaf_r(float x, int *signgamp) {
  float t, y, z, nadj = 0, p, p1, p2, p3, q, r, w;
  int32_t i, hx, ix;

  static const float zero = 0.0000000000e+00;

  static const float half = 5.0000000000e-01; /* 0x3f000000 */
  static const float one = 1.0000000000e+00;  /* 0x3f800000 */
  static const float pi = 3.1415927410e+00;   /* 0x40490fdb */
  static const float a0 = 7.7215664089e-02;   /* 0x3d9e233f */
  static const float a1 = 3.2246702909e-01;   /* 0x3ea51a66 */
  static const float a2 = 6.7352302372e-02;   /* 0x3d89f001 */
  static const float a3 = 2.0580807701e-02;   /* 0x3ca89915 */
  static const float a4 = 7.3855509982e-03;   /* 0x3bf2027e */
  static const float a5 = 2.8905137442e-03;   /* 0x3b3d6ec6 */
  static const float a6 = 1.1927076848e-03;   /* 0x3a9c54a1 */
  static const float a7 = 5.1006977446e-04;   /* 0x3a05b634 */
  static const float a8 = 2.2086278477e-04;   /* 0x39679767 */
  static const float a9 = 1.0801156895e-04;   /* 0x38e28445 */
  static const float a10 = 2.5214456400e-05;  /* 0x37d383a2 */
  static const float a11 = 4.4864096708e-05;  /* 0x383c2c75 */
  static const float tc = 1.4616321325e+00;   /* 0x3fbb16c3 */
  static const float tf = (double temp_var_for_tac_19;
                           double temp_var_for_const_28, temp_var_for_const_29;
                           temp_var_for_tac_19 = 0.0 - 1.2148628384e-01;

                           ); /* 0xbdf8cdcd */

  /* tt = -(tail of tf) */
  static const float tt = 6.6971006518e-09; /* 0x31e61c52 */
  static const float t0 = 4.8383611441e-01; /* 0x3ef7b95e */
  static const float t1 = (double temp_var_for_tac_20;
                           double temp_var_for_const_30, temp_var_for_const_31;
                           temp_var_for_tac_20 = 0.0 - 1.4758771658e-01;

                           );               /* 0xbe17213c */
  static const float t2 = 6.4624942839e-02; /* 0x3d845a15 */
  static const float t3 = (double temp_var_for_tac_21;
                           double temp_var_for_const_32, temp_var_for_const_33;
                           temp_var_for_tac_21 = 0.0 - 3.2788541168e-02;

                           );               /* 0xbd064d47 */
  static const float t4 = 1.7970675603e-02; /* 0x3c93373d */
  static const float t5 = (double temp_var_for_tac_22;
                           double temp_var_for_const_34, temp_var_for_const_35;
                           temp_var_for_tac_22 = 0.0 - 1.0314224288e-02;

                           );               /* 0xbc28fcfe */
  static const float t6 = 6.1005386524e-03; /* 0x3bc7e707 */
  static const float t7 = (double temp_var_for_tac_23;
                           double temp_var_for_const_36, temp_var_for_const_37;
                           temp_var_for_tac_23 = 0.0 - 3.6845202558e-03;

                           );               /* 0xbb7177fe */
  static const float t8 = 2.2596477065e-03; /* 0x3b141699 */
  static const float t9 = (double temp_var_for_tac_24;
                           double temp_var_for_const_38, temp_var_for_const_39;
                           temp_var_for_tac_24 = 0.0 - 1.4034647029e-03;

                           );                /* 0xbab7f476 */
  static const float t10 = 8.8108185446e-04; /* 0x3a66f867 */
  static const float t11 = (double temp_var_for_tac_25;
                            double temp_var_for_const_40, temp_var_for_const_41;
                            temp_var_for_tac_25 = 0.0 - 5.3859531181e-04;

                            );               /* 0xba0d3085 */
  static const float t12 = 3.1563205994e-04; /* 0x39a57b6b */
  static const float t13 = (double temp_var_for_tac_26;
                            double temp_var_for_const_42, temp_var_for_const_43;
                            temp_var_for_tac_26 = 0.0 - 3.1275415677e-04;

                            );               /* 0xb9a3f927 */
  static const float t14 = 3.3552918467e-04; /* 0x39afe9f7 */
  static const float u0 = (double temp_var_for_tac_27;
                           double temp_var_for_const_44, temp_var_for_const_45;
                           temp_var_for_tac_27 = 0.0 - 7.7215664089e-02;

                           );               /* 0xbd9e233f */
  static const float u1 = 6.3282704353e-01; /* 0x3f2200f4 */
  static const float u2 = 1.4549225569e+00; /* 0x3fba3ae7 */
  static const float u3 = 9.7771751881e-01; /* 0x3f7a4bb2 */
  static const float u4 = 2.2896373272e-01; /* 0x3e6a7578 */
  static const float u5 = 1.3381091878e-02; /* 0x3c5b3c5e */
  static const float v1 = 2.4559779167e+00; /* 0x401d2ebe */
  static const float v2 = 2.1284897327e+00; /* 0x4008392d */
  static const float v3 = 7.6928514242e-01; /* 0x3f44efdf */
  static const float v4 = 1.0422264785e-01; /* 0x3dd572af */
  static const float v5 = 3.2170924824e-03; /* 0x3b52d5db */
  static const float s0 = (double temp_var_for_tac_28;
                           double temp_var_for_const_46, temp_var_for_const_47;
                           temp_var_for_tac_28 = 0.0 - 7.7215664089e-02;

                           );               /* 0xbd9e233f */
  static const float s1 = 2.1498242021e-01; /* 0x3e5c245a */
  static const float s2 = 3.2577878237e-01; /* 0x3ea6cc7a */
  static const float s3 = 1.4635047317e-01; /* 0x3e15dce6 */
  static const float s4 = 2.6642270386e-02; /* 0x3cda40e4 */
  static const float s5 = 1.8402845599e-03; /* 0x3af135b4 */
  static const float s6 = 3.1947532989e-05; /* 0x3805ff67 */
  static const float r1 = 1.3920053244e+00; /* 0x3fb22d3b */
  static const float r2 = 7.2193557024e-01; /* 0x3f38d0c5 */
  static const float r3 = 1.7193385959e-01; /* 0x3e300f6e */
  static const float r4 = 1.8645919859e-02; /* 0x3c98bf54 */
  static const float r5 = 7.7794247773e-04; /* 0x3a4beed6 */
  static const float r6 = 7.3266842264e-06; /* 0x36f5d7bd */
  static const float w0 = 4.1893854737e-01; /* 0x3ed67f1d */
  static const float w1 = 8.3333335817e-02; /* 0x3daaaaab */
  static const float w2 = (double temp_var_for_tac_29;
                           double temp_var_for_const_48, temp_var_for_const_49;
                           temp_var_for_tac_29 = 0.0 - 2.7777778450e-03;

                           );               /* 0xbb360b61 */
  static const float w3 = 7.9365057172e-04; /* 0x3a500cfd */
  static const float w4 = (double temp_var_for_tac_30;
                           double temp_var_for_const_50, temp_var_for_const_51;
                           temp_var_for_tac_30 = 0.0 - 5.9518753551e-04;

                           );               /* 0xba1c065c */
  static const float w5 = 8.3633989561e-04; /* 0x3a5b3dd2 */
  static const float w6 = (double temp_var_for_tac_31;
                           double temp_var_for_const_52, temp_var_for_const_53;
                           temp_var_for_tac_31 = 0.0 - 1.6309292987e-03;

                           ); /* 0xbad5c4e8 */

  GET_FLOAT_WORD(hx, x);

  /* purge off +-inf, NaN, +-0, and negative arguments */
  *signgamp = 1;
  ix = hx & IC(0x7fffffff);
  if (ix >= IC(0x7f800000)) {
    float temp_var_for_ext_9;
    float temp_var_for_tac_32;
    temp_var_for_tac_32 = x * x;

    temp_var_for_ext_9 = temp_var_for_tac_32;
    computeDSub((Addr)&temp_var_for_tac_18,
                {(Addr) &(temp_var_for_const_27 = 0.0),
                 (Addr) &(temp_var_for_const_26 = 8)},
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:155:15");
    computeDSub((Addr)&temp_var_for_tac_19,
                {(Addr) &(temp_var_for_const_29 = 0.0),
                 (Addr) &(temp_var_for_const_28 = 1.2148628384e-01)},
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:180:32");
    computeDSub((Addr)&temp_var_for_tac_20,
                {(Addr) &(temp_var_for_const_31 = 0.0),
                 (Addr) &(temp_var_for_const_30 = 1.4758771658e-01)},
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:185:32");
    computeDSub((Addr)&temp_var_for_tac_21,
                {(Addr) &(temp_var_for_const_33 = 0.0),
                 (Addr) &(temp_var_for_const_32 = 3.2788541168e-02)},
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:187:32");
    computeDSub((Addr)&temp_var_for_tac_22,
                {(Addr) &(temp_var_for_const_35 = 0.0),
                 (Addr) &(temp_var_for_const_34 = 1.0314224288e-02)},
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:189:32");
    computeDSub((Addr)&temp_var_for_tac_23,
                {(Addr) &(temp_var_for_const_37 = 0.0),
                 (Addr) &(temp_var_for_const_36 = 3.6845202558e-03)},
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:191:32");
    computeDSub((Addr)&temp_var_for_tac_24,
                {(Addr) &(temp_var_for_const_39 = 0.0),
                 (Addr) &(temp_var_for_const_38 = 1.4034647029e-03)},
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:193:32");
    computeDSub((Addr)&temp_var_for_tac_25,
                {(Addr) &(temp_var_for_const_41 = 0.0),
                 (Addr) &(temp_var_for_const_40 = 5.3859531181e-04)},
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:195:33");
    computeDSub((Addr)&temp_var_for_tac_26,
                {(Addr) &(temp_var_for_const_43 = 0.0),
                 (Addr) &(temp_var_for_const_42 = 3.1275415677e-04)},
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:197:33");
    computeDSub((Addr)&temp_var_for_tac_27,
                {(Addr) &(temp_var_for_const_45 = 0.0),
                 (Addr) &(temp_var_for_const_44 = 7.7215664089e-02)},
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:199:32");
    computeDSub((Addr)&temp_var_for_tac_28,
                {(Addr) &(temp_var_for_const_47 = 0.0),
                 (Addr) &(temp_var_for_const_46 = 7.7215664089e-02)},
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:210:32");
    computeDSub((Addr)&temp_var_for_tac_29,
                {(Addr) &(temp_var_for_const_49 = 0.0),
                 (Addr) &(temp_var_for_const_48 = 2.7777778450e-03)},
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:225:32");
    computeDSub((Addr)&temp_var_for_tac_30,
                {(Addr) &(temp_var_for_const_51 = 0.0),
                 (Addr) &(temp_var_for_const_50 = 5.9518753551e-04)},
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:227:32");
    computeDSub((Addr)&temp_var_for_tac_31,
                {(Addr) &(temp_var_for_const_53 = 0.0),
                 (Addr) &(temp_var_for_const_52 = 1.6309292987e-03)},
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:229:32");
    computeFMul((Addr)&temp_var_for_tac_32, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:238:28");
    AssignF({(Addr)&temp_var_for_ext_9}, (Addr)&temp_var_for_tac_32,
            "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:238:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_9;
  }

  if (ix == 0) {
    if (hx < 0) {
      *signgamp = -1;
    }

    float temp_var_for_ext_10;
    float temp_var_for_tac_33;
    float temp_var_for_const_54, temp_var_for_const_55;
    float temp_var_for_callexp_8;

    temp_var_for_callexp_8 = fabsf(x);
    temp_var_for_tac_33 = one / temp_var_for_callexp_8;

    temp_var_for_ext_10 = temp_var_for_tac_33;
    computeFDiv((Addr)&temp_var_for_tac_33,
                {(Addr) &(temp_var_for_const_55 = one),
                 (Addr) &(temp_var_for_const_54 = temp_var_for_callexp_8)},
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:250:31");
    AssignF({(Addr)&temp_var_for_ext_10}, (Addr)&temp_var_for_tac_33,
            "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:250:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_10", (Addr)&temp_var_for_ext_10));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_10;
  }
  if (ix < IC(0x1c800000)) {
    /* |x|<2**-70, return -log(|x|) */
    if (hx < 0) {
      *signgamp = -1;
      float temp_var_for_ext_11;
      float temp_var_for_const_56;
      temp_var_for_callexp_9 = __ieee754_logf((-(x)));
      temp_var_for_ext_11 = (-(temp_var_for_callexp_9));
      AssignF({(Addr)&temp_var_for_ext_11},
              (Addr) &(temp_var_for_const_56 = (-(temp_var_for_callexp_9))),
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:261:27");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_11", (Addr)&temp_var_for_ext_11));
      callExp++; /*identify the function is  add move tmpShadow*/
      return (double temp_var_for_tac_34, temp_var_for_tac_35;
              double temp_var_for_const_57, temp_var_for_const_58,
              temp_var_for_const_59, temp_var_for_const_60;
              temp_var_for_tac_34 = 0.0 - 1;

              temp_var_for_tac_35 = 0.0 - emp_var_for_ext_(temp_var_for_tac_34);

              );
    } else {
      float temp_var_for_ext_12;
      float temp_var_for_const_61;
      temp_var_for_callexp_10 = __ieee754_logf(x);
      temp_var_for_ext_12 = (-(temp_var_for_callexp_10));
      computeDSub((Addr)&temp_var_for_tac_34,
                  {(Addr) &(temp_var_for_const_58 = 0.0),
                   (Addr) &(temp_var_for_const_57 = 1)},
                  "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:265:42");
      computeDSub((Addr)&temp_var_for_tac_35,
                  {(Addr) &(temp_var_for_const_60 = 0.0),
                   (Addr) &(temp_var_for_const_59 =
                                emp_var_for_ext_(temp_var_for_tac_34))},
                  "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:265:19");
      AssignF({(Addr)&temp_var_for_ext_12},
              (Addr) &(temp_var_for_const_61 = (-(temp_var_for_callexp_10))),
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:268:27");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_12", (Addr)&temp_var_for_ext_12));
      callExp++; /*identify the function is  add move tmpShadow*/
      return (0.0 - mp_var_for_ext_12);
    }
  }
  if (hx < 0) {
    if (ix >= IC(0x4b000000)) /* |x|>=2**23, must be -integer */
    {
      float temp_var_for_ext_13;
      float temp_var_for_tac_36;
      float temp_var_for_const_62;
      temp_var_for_tac_36 = x / zero;

      temp_var_for_ext_13 = temp_var_for_tac_36;
      computeFDiv((Addr)&temp_var_for_tac_36,
                  {(Addr)&x, (Addr) &(temp_var_for_const_62 = zero)},
                  "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:279:31");
      AssignF({(Addr)&temp_var_for_ext_13}, (Addr)&temp_var_for_tac_36,
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:279:27");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_13", (Addr)&temp_var_for_ext_13));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_13;
    }

    float temp_var_for_ext_14;
    float temp_var_for_const_63;
    float temp_var_for_callexp_11;

    temp_var_for_callexp_11 = sin_pif(x);
    temp_var_for_ext_14 = temp_var_for_callexp_11;
    AssignF({(Addr)&temp_var_for_ext_14},
            (Addr) &(temp_var_for_const_63 = temp_var_for_callexp_11),
            "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:287:25");
    ; // t
    /*(2.0F)(y)(pi)(2.0F)(y)(9)(t)(emp_var_for_ext_10)(tem)(t_13)(t)(sin_pif(x))*/
    t = temp_var_for_ext_14;
    AssignF({(Addr)&t}, (Addr)&temp_var_for_ext_14,
            "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:289:7");
    ;
    if (int temp_var_for_tac_37; int temp_var_for_const_64;
        temp_var_for_tac_37 = t == zero;

        ) {
      float temp_var_for_ext_15;
      float temp_var_for_tac_38;
      float temp_var_for_const_65, temp_var_for_const_66;
      float temp_var_for_callexp_12;

      temp_var_for_callexp_12 = fabsf(t);
      temp_var_for_tac_38 = one / temp_var_for_callexp_12;

      temp_var_for_ext_15 = temp_var_for_tac_38;
      compute((Addr)&temp_var_for_tac_37,
              {(Addr)&t, (Addr) &(temp_var_for_const_64 = zero)},
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:290:11");
      computeFDiv((Addr)&temp_var_for_tac_38,
                  {(Addr) &(temp_var_for_const_66 = one),
                   (Addr) &(temp_var_for_const_65 = temp_var_for_callexp_12)},
                  "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:292:33");
      AssignF({(Addr)&temp_var_for_ext_15}, (Addr)&temp_var_for_tac_38,
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:292:27");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_15", (Addr)&temp_var_for_ext_15));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_15;
    }
    /* -integer */
    float temp_var_for_tac_39, temp_var_for_tac_40;
    float temp_var_for_const_67, temp_var_for_const_68, temp_var_for_const_69;
    float temp_var_for_callexp_13;

    float temp_var_for_callexp_14;

    temp_var_for_tac_39 = t * x;

    temp_var_for_callexp_13 = fabsf(temp_var_for_tac_39);
    temp_var_for_tac_40 = pi / temp_var_for_callexp_13;

    temp_var_for_callexp_14 = __ieee754_logf(temp_var_for_tac_40);
    nadj = temp_var_for_callexp_14;
    computeFMul((Addr)&temp_var_for_tac_39, {(Addr)&t, (Addr)&x},
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:299:32 "
                "<Spelling=/home/shijia/Public/testprogram/"
                "e_lgammaf_r.c_e.c:299:50>");
    computeFDiv((Addr)&temp_var_for_tac_40,
                {(Addr) &(temp_var_for_const_68 = pi),
                 (Addr) &(temp_var_for_const_67 = temp_var_for_callexp_13)},
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:299:30");
    AssignF({(Addr)&nadj},
            (Addr) &(temp_var_for_const_69 = temp_var_for_callexp_14),
            "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:299:10");
    ;
    if (int temp_var_for_tac_41; int temp_var_for_const_70;
        temp_var_for_tac_41 = t < zero;

        ) {
      *signgamp = -1;
    }

    float temp_var_for_ext_16;
    float temp_var_for_tac_42;
    float temp_var_for_const_71;
    temp_var_for_tac_42 = 0.0 - x;

    temp_var_for_ext_16 = temp_var_for_tac_42;
    compute((Addr)&temp_var_for_tac_41,
            {(Addr)&t, (Addr) &(temp_var_for_const_70 = zero)},
            "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:300:11");
    computeDSub((Addr)&temp_var_for_tac_42,
                {(Addr) &(temp_var_for_const_71 = 0.0), (Addr)&x},
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:305:32");
    AssignF({(Addr)&temp_var_for_ext_16}, (Addr)&temp_var_for_tac_42,
            "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:305:25");
    ; // x
    /*(__ieee754_fabsf(t * x))(pi)()()(x)(x)*/
    x = temp_var_for_ext_16;
    AssignF({(Addr)&x}, (Addr)&temp_var_for_ext_16,
            "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:307:7");
    ;
  }

  /* purge off 1 and 2 */
  if (ix == IC(0x3f800000) || ix == IC(0x40000000)) {
    float temp_var_for_const_72;
    r = 0;
    AssignF({(Addr)&r}, (Addr) &(temp_var_for_const_72 = 0),
            "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:312:7");
    ;
  }

  /* for x < 2.0 */
  else {
    if (ix < IC(0x40000000)) {
      if (ix <= IC(0x3f666666)) { /* lgamma(x) = lgamma(x+1)-log(x) */
        float temp_var_for_tac_43;
        float temp_var_for_const_73, temp_var_for_const_74;
        float temp_var_for_callexp_15;

        temp_var_for_callexp_15 = __ieee754_logf(x);
        temp_var_for_tac_43 = 0.0 - temp_var_for_callexp_15;

        r = temp_var_for_tac_43;
        computeDSub((Addr)&temp_var_for_tac_43,
                    {(Addr) &(temp_var_for_const_74 = 0.0),
                     (Addr) &(temp_var_for_const_73 = temp_var_for_callexp_15)},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:319:18");
        AssignF({(Addr)&r}, (Addr)&temp_var_for_tac_43,
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:319:11");
        ;
        if (ix >= IC(0x3f3b4a20)) {
          float temp_var_for_tac_44;
          float temp_var_for_const_75;
          temp_var_for_tac_44 = one - x;

          y = temp_var_for_tac_44;
          computeFSub(
              (Addr)&temp_var_for_tac_44,
              {(Addr) &(temp_var_for_const_75 = one), (Addr)&x},
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:321:19");
          AssignF({(Addr)&y}, (Addr)&temp_var_for_tac_44,
                  "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:321:13");
          ;
          i = 0;
        } else {
          if (ix >= IC(0x3e6d3308)) {
            float temp_var_for_tac_45, temp_var_for_tac_46;
            float temp_var_for_const_76, temp_var_for_const_77;
            temp_var_for_tac_45 = tc - one;

            temp_var_for_tac_46 = x - temp_var_for_tac_45;

            y = temp_var_for_tac_46;
            computeFSub(
                (Addr)&temp_var_for_tac_45,
                {(Addr) &(temp_var_for_const_77 = tc),
                 (Addr) &(temp_var_for_const_76 = one)},
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:325:25");
            computeFSub(
                (Addr)&temp_var_for_tac_46,
                {(Addr)&x, (Addr)&temp_var_for_tac_45},
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:325:19");
            AssignF({(Addr)&y}, (Addr)&temp_var_for_tac_46,
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:325:15");
            ;
            i = 1;
          } else {
            y = x;
            AssignF({(Addr)&y}, (Addr)&x,
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:328:15");
            ;
            i = 2;
          }
        }

      } else {
        float temp_var_for_const_78;
        r = zero;
        AssignF({(Addr)&r}, (Addr) &(temp_var_for_const_78 = zero),
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:334:11");
        ;
        if (ix >= IC(0x3fdda618)) {
          float temp_var_for_tac_47;
          float temp_var_for_const_79;
          temp_var_for_tac_47 = 2.0F - x;

          y = temp_var_for_tac_47;
          computeFSub(
              (Addr)&temp_var_for_tac_47,
              {(Addr) &(temp_var_for_const_79 = 2.0F), (Addr)&x},
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:336:20");
          AssignF({(Addr)&y}, (Addr)&temp_var_for_tac_47,
                  "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:336:13");
          ;
          i = 0;
        } /* [1.7316,2] */
        else {
          if (ix >= IC(0x3F9da620)) {
            float temp_var_for_tac_48;
            float temp_var_for_const_80;
            temp_var_for_tac_48 = x - tc;

            y = temp_var_for_tac_48;
            computeFSub(
                (Addr)&temp_var_for_tac_48,
                {(Addr)&x, (Addr) &(temp_var_for_const_80 = tc)},
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:341:19");
            AssignF({(Addr)&y}, (Addr)&temp_var_for_tac_48,
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:341:15");
            ;
            i = 1;
          } /* [1.23,1.73] */
          else {
            float temp_var_for_tac_49;
            float temp_var_for_const_81;
            temp_var_for_tac_49 = x - one;

            y = temp_var_for_tac_49;
            computeFSub(
                (Addr)&temp_var_for_tac_49,
                {(Addr)&x, (Addr) &(temp_var_for_const_81 = one)},
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:345:19");
            AssignF({(Addr)&y}, (Addr)&temp_var_for_tac_49,
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:345:15");
            ;
            i = 2;
          }
        }
      }
      int temp_var_for_ext_17;
      temp_var_for_ext_17 = (int)i;
      switch (temp_var_for_ext_17) {
      case 0: {
        float temp_var_for_tac_50;
        temp_var_for_tac_50 = y * y;

        z = temp_var_for_tac_50;
        computeFMul((Addr)&temp_var_for_tac_50, {(Addr)&y, (Addr)&y},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:354:15");
        AssignF({(Addr)&z}, (Addr)&temp_var_for_tac_50,
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:354:11");
        ;
      }

        float temp_var_for_tac_51, temp_var_for_tac_52, temp_var_for_tac_53,
            temp_var_for_tac_54, temp_var_for_tac_55, temp_var_for_tac_56,
            temp_var_for_tac_57, temp_var_for_tac_58, temp_var_for_tac_59,
            temp_var_for_tac_60;
        float temp_var_for_const_82, temp_var_for_const_83,
            temp_var_for_const_84, temp_var_for_const_85, temp_var_for_const_86,
            temp_var_for_const_87;
        temp_var_for_tac_51 = z * a10;

        temp_var_for_tac_52 = a8 + temp_var_for_tac_51;

        temp_var_for_tac_53 = z * temp_var_for_tac_52;

        temp_var_for_tac_54 = a6 + temp_var_for_tac_53;

        temp_var_for_tac_55 = z * temp_var_for_tac_54;

        temp_var_for_tac_56 = a4 + temp_var_for_tac_55;

        temp_var_for_tac_57 = z * temp_var_for_tac_56;

        temp_var_for_tac_58 = a2 + temp_var_for_tac_57;

        temp_var_for_tac_59 = z * temp_var_for_tac_58;

        temp_var_for_tac_60 = a0 + temp_var_for_tac_59;

        p1 = temp_var_for_tac_60;
        computeFMul((Addr)&temp_var_for_tac_51,
                    {(Addr)&z, (Addr) &(temp_var_for_const_82 = a10)},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:357:61");
        computeFAdd(
            (Addr)&temp_var_for_tac_52,
            {(Addr) &(temp_var_for_const_83 = a8), (Addr)&temp_var_for_tac_51},
            "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:357:57");
        computeFMul((Addr)&temp_var_for_tac_53,
                    {(Addr)&z, (Addr)&temp_var_for_tac_52},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:357:51");
        computeFAdd(
            (Addr)&temp_var_for_tac_54,
            {(Addr) &(temp_var_for_const_84 = a6), (Addr)&temp_var_for_tac_53},
            "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:357:47");
        computeFMul((Addr)&temp_var_for_tac_55,
                    {(Addr)&z, (Addr)&temp_var_for_tac_54},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:357:41");
        computeFAdd(
            (Addr)&temp_var_for_tac_56,
            {(Addr) &(temp_var_for_const_85 = a4), (Addr)&temp_var_for_tac_55},
            "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:357:37");
        computeFMul((Addr)&temp_var_for_tac_57,
                    {(Addr)&z, (Addr)&temp_var_for_tac_56},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:357:31");
        computeFAdd(
            (Addr)&temp_var_for_tac_58,
            {(Addr) &(temp_var_for_const_86 = a2), (Addr)&temp_var_for_tac_57},
            "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:357:27");
        computeFMul((Addr)&temp_var_for_tac_59,
                    {(Addr)&z, (Addr)&temp_var_for_tac_58},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:357:21");
        computeFAdd(
            (Addr)&temp_var_for_tac_60,
            {(Addr) &(temp_var_for_const_87 = a0), (Addr)&temp_var_for_tac_59},
            "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:357:17");
        AssignF({(Addr)&p1}, (Addr)&temp_var_for_tac_60,
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:357:12");
        ;
        float temp_var_for_tac_61, temp_var_for_tac_62, temp_var_for_tac_63,
            temp_var_for_tac_64, temp_var_for_tac_65, temp_var_for_tac_66,
            temp_var_for_tac_67, temp_var_for_tac_68, temp_var_for_tac_69,
            temp_var_for_tac_70, temp_var_for_tac_71;
        float temp_var_for_const_88, temp_var_for_const_89,
            temp_var_for_const_90, temp_var_for_const_91, temp_var_for_const_92,
            temp_var_for_const_93;
        temp_var_for_tac_61 = z * a11;

        temp_var_for_tac_62 = a9 + temp_var_for_tac_61;

        temp_var_for_tac_63 = z * temp_var_for_tac_62;

        temp_var_for_tac_64 = a7 + temp_var_for_tac_63;

        temp_var_for_tac_65 = z * temp_var_for_tac_64;

        temp_var_for_tac_66 = a5 + temp_var_for_tac_65;

        temp_var_for_tac_67 = z * temp_var_for_tac_66;

        temp_var_for_tac_68 = a3 + temp_var_for_tac_67;

        temp_var_for_tac_69 = z * temp_var_for_tac_68;

        temp_var_for_tac_70 = a1 + temp_var_for_tac_69;

        temp_var_for_tac_71 = z * temp_var_for_tac_70;

        p2 = temp_var_for_tac_71;
        computeFMul((Addr)&temp_var_for_tac_61,
                    {(Addr)&z, (Addr) &(temp_var_for_const_88 = a11)},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:358:66");
        computeFAdd(
            (Addr)&temp_var_for_tac_62,
            {(Addr) &(temp_var_for_const_89 = a9), (Addr)&temp_var_for_tac_61},
            "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:358:62");
        computeFMul((Addr)&temp_var_for_tac_63,
                    {(Addr)&z, (Addr)&temp_var_for_tac_62},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:358:56");
        computeFAdd(
            (Addr)&temp_var_for_tac_64,
            {(Addr) &(temp_var_for_const_90 = a7), (Addr)&temp_var_for_tac_63},
            "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:358:52");
        computeFMul((Addr)&temp_var_for_tac_65,
                    {(Addr)&z, (Addr)&temp_var_for_tac_64},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:358:46");
        computeFAdd(
            (Addr)&temp_var_for_tac_66,
            {(Addr) &(temp_var_for_const_91 = a5), (Addr)&temp_var_for_tac_65},
            "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:358:42");
        computeFMul((Addr)&temp_var_for_tac_67,
                    {(Addr)&z, (Addr)&temp_var_for_tac_66},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:358:36");
        computeFAdd(
            (Addr)&temp_var_for_tac_68,
            {(Addr) &(temp_var_for_const_92 = a3), (Addr)&temp_var_for_tac_67},
            "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:358:32");
        computeFMul((Addr)&temp_var_for_tac_69,
                    {(Addr)&z, (Addr)&temp_var_for_tac_68},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:358:26");
        computeFAdd(
            (Addr)&temp_var_for_tac_70,
            {(Addr) &(temp_var_for_const_93 = a1), (Addr)&temp_var_for_tac_69},
            "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:358:22");
        computeFMul((Addr)&temp_var_for_tac_71,
                    {(Addr)&z, (Addr)&temp_var_for_tac_70},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:358:16");
        AssignF({(Addr)&p2}, (Addr)&temp_var_for_tac_71,
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:358:12");
        ;
        float temp_var_for_tac_72, temp_var_for_tac_73;
        temp_var_for_tac_72 = y * p1;

        temp_var_for_tac_73 = temp_var_for_tac_72 + p2;

        p = temp_var_for_tac_73;
        computeFMul((Addr)&temp_var_for_tac_72, {(Addr)&y, (Addr)&p1},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:359:15");
        computeFAdd((Addr)&temp_var_for_tac_73,
                    {(Addr)&temp_var_for_tac_72, (Addr)&p2},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:359:20");
        AssignF({(Addr)&p}, (Addr)&temp_var_for_tac_73,
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:359:11");
        ;
        float temp_var_for_tac_74, temp_var_for_tac_75;
        float temp_var_for_const_94;
        temp_var_for_tac_74 = 0.5F * y;

        temp_var_for_tac_75 = p - temp_var_for_tac_74;

        r += temp_var_for_tac_75;
        ;
        break;
      case 1: {
        float temp_var_for_tac_77;
        temp_var_for_tac_77 = y * y;

        z = temp_var_for_tac_77;
        computeFMul((Addr)&temp_var_for_tac_74,
                    {(Addr) &(temp_var_for_const_94 = 0.5F), (Addr)&y},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:360:24");
        computeFSub((Addr)&temp_var_for_tac_75,
                    {(Addr)&p, (Addr)&temp_var_for_tac_74},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:360:17");
        computeFMul((Addr)&temp_var_for_tac_77, {(Addr)&y, (Addr)&y},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:363:15");
        AssignF({(Addr)&z}, (Addr)&temp_var_for_tac_77,
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:363:11");
        ;
      }

        float temp_var_for_tac_78;
        temp_var_for_tac_78 = z * y;

        w = temp_var_for_tac_78;
        computeFMul((Addr)&temp_var_for_tac_78, {(Addr)&z, (Addr)&y},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:366:15");
        AssignF({(Addr)&w}, (Addr)&temp_var_for_tac_78,
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:366:11");
        ;
        float temp_var_for_tac_79, temp_var_for_tac_80, temp_var_for_tac_81,
            temp_var_for_tac_82, temp_var_for_tac_83, temp_var_for_tac_84,
            temp_var_for_tac_85, temp_var_for_tac_86;
        float temp_var_for_const_95, temp_var_for_const_96,
            temp_var_for_const_97, temp_var_for_const_98, temp_var_for_const_99;
        temp_var_for_tac_79 = w * t12;

        temp_var_for_tac_80 = t9 + temp_var_for_tac_79;

        temp_var_for_tac_81 = w * temp_var_for_tac_80;

        temp_var_for_tac_82 = t6 + temp_var_for_tac_81;

        temp_var_for_tac_83 = w * temp_var_for_tac_82;

        temp_var_for_tac_84 = t3 + temp_var_for_tac_83;

        temp_var_for_tac_85 = w * temp_var_for_tac_84;

        temp_var_for_tac_86 = t0 + temp_var_for_tac_85;

        p1 = temp_var_for_tac_86;
        computeFMul((Addr)&temp_var_for_tac_79,
                    {(Addr)&w, (Addr) &(temp_var_for_const_95 = t12)},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:367:51");
        computeFAdd(
            (Addr)&temp_var_for_tac_80,
            {(Addr) &(temp_var_for_const_96 = t9), (Addr)&temp_var_for_tac_79},
            "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:367:47");
        computeFMul((Addr)&temp_var_for_tac_81,
                    {(Addr)&w, (Addr)&temp_var_for_tac_80},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:367:41");
        computeFAdd(
            (Addr)&temp_var_for_tac_82,
            {(Addr) &(temp_var_for_const_97 = t6), (Addr)&temp_var_for_tac_81},
            "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:367:37");
        computeFMul((Addr)&temp_var_for_tac_83,
                    {(Addr)&w, (Addr)&temp_var_for_tac_82},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:367:31");
        computeFAdd(
            (Addr)&temp_var_for_tac_84,
            {(Addr) &(temp_var_for_const_98 = t3), (Addr)&temp_var_for_tac_83},
            "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:367:27");
        computeFMul((Addr)&temp_var_for_tac_85,
                    {(Addr)&w, (Addr)&temp_var_for_tac_84},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:367:21");
        computeFAdd(
            (Addr)&temp_var_for_tac_86,
            {(Addr) &(temp_var_for_const_99 = t0), (Addr)&temp_var_for_tac_85},
            "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:367:17");
        AssignF({(Addr)&p1}, (Addr)&temp_var_for_tac_86,
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:367:12");
        ; /* parallel comp */
        float temp_var_for_tac_87, temp_var_for_tac_88, temp_var_for_tac_89,
            temp_var_for_tac_90, temp_var_for_tac_91, temp_var_for_tac_92,
            temp_var_for_tac_93, temp_var_for_tac_94;
        float temp_var_for_const_100, temp_var_for_const_101,
            temp_var_for_const_102, temp_var_for_const_103,
            temp_var_for_const_104;
        temp_var_for_tac_87 = w * t13;

        temp_var_for_tac_88 = t10 + temp_var_for_tac_87;

        temp_var_for_tac_89 = w * temp_var_for_tac_88;

        temp_var_for_tac_90 = t7 + temp_var_for_tac_89;

        temp_var_for_tac_91 = w * temp_var_for_tac_90;

        temp_var_for_tac_92 = t4 + temp_var_for_tac_91;

        temp_var_for_tac_93 = w * temp_var_for_tac_92;

        temp_var_for_tac_94 = t1 + temp_var_for_tac_93;

        p2 = temp_var_for_tac_94;
        computeFMul((Addr)&temp_var_for_tac_87,
                    {(Addr)&w, (Addr) &(temp_var_for_const_100 = t13)},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:368:52");
        computeFAdd((Addr)&temp_var_for_tac_88,
                    {(Addr) &(temp_var_for_const_101 = t10),
                     (Addr)&temp_var_for_tac_87},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:368:48");
        computeFMul((Addr)&temp_var_for_tac_89,
                    {(Addr)&w, (Addr)&temp_var_for_tac_88},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:368:41");
        computeFAdd(
            (Addr)&temp_var_for_tac_90,
            {(Addr) &(temp_var_for_const_102 = t7), (Addr)&temp_var_for_tac_89},
            "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:368:37");
        computeFMul((Addr)&temp_var_for_tac_91,
                    {(Addr)&w, (Addr)&temp_var_for_tac_90},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:368:31");
        computeFAdd(
            (Addr)&temp_var_for_tac_92,
            {(Addr) &(temp_var_for_const_103 = t4), (Addr)&temp_var_for_tac_91},
            "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:368:27");
        computeFMul((Addr)&temp_var_for_tac_93,
                    {(Addr)&w, (Addr)&temp_var_for_tac_92},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:368:21");
        computeFAdd(
            (Addr)&temp_var_for_tac_94,
            {(Addr) &(temp_var_for_const_104 = t1), (Addr)&temp_var_for_tac_93},
            "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:368:17");
        AssignF({(Addr)&p2}, (Addr)&temp_var_for_tac_94,
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:368:12");
        ;
        float temp_var_for_tac_95, temp_var_for_tac_96, temp_var_for_tac_97,
            temp_var_for_tac_98, temp_var_for_tac_99, temp_var_for_tac_100,
            temp_var_for_tac_101, temp_var_for_tac_102;
        float temp_var_for_const_105, temp_var_for_const_106,
            temp_var_for_const_107, temp_var_for_const_108,
            temp_var_for_const_109;
        temp_var_for_tac_95 = w * t14;

        temp_var_for_tac_96 = t11 + temp_var_for_tac_95;

        temp_var_for_tac_97 = w * temp_var_for_tac_96;

        temp_var_for_tac_98 = t8 + temp_var_for_tac_97;

        temp_var_for_tac_99 = w * temp_var_for_tac_98;

        temp_var_for_tac_100 = t5 + temp_var_for_tac_99;

        temp_var_for_tac_101 = w * temp_var_for_tac_100;

        temp_var_for_tac_102 = t2 + temp_var_for_tac_101;

        p3 = temp_var_for_tac_102;
        computeFMul((Addr)&temp_var_for_tac_95,
                    {(Addr)&w, (Addr) &(temp_var_for_const_105 = t14)},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:369:52");
        computeFAdd((Addr)&temp_var_for_tac_96,
                    {(Addr) &(temp_var_for_const_106 = t11),
                     (Addr)&temp_var_for_tac_95},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:369:48");
        computeFMul((Addr)&temp_var_for_tac_97,
                    {(Addr)&w, (Addr)&temp_var_for_tac_96},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:369:41");
        computeFAdd(
            (Addr)&temp_var_for_tac_98,
            {(Addr) &(temp_var_for_const_107 = t8), (Addr)&temp_var_for_tac_97},
            "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:369:37");
        computeFMul((Addr)&temp_var_for_tac_99,
                    {(Addr)&w, (Addr)&temp_var_for_tac_98},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:369:31");
        computeFAdd(
            (Addr)&temp_var_for_tac_100,
            {(Addr) &(temp_var_for_const_108 = t5), (Addr)&temp_var_for_tac_99},
            "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:369:27");
        computeFMul((Addr)&temp_var_for_tac_101,
                    {(Addr)&w, (Addr)&temp_var_for_tac_100},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:369:21");
        computeFAdd((Addr)&temp_var_for_tac_102,
                    {(Addr) &(temp_var_for_const_109 = t2),
                     (Addr)&temp_var_for_tac_101},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:369:17");
        AssignF({(Addr)&p3}, (Addr)&temp_var_for_tac_102,
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:369:12");
        ;
        float temp_var_for_tac_103, temp_var_for_tac_104, temp_var_for_tac_105,
            temp_var_for_tac_106, temp_var_for_tac_107, temp_var_for_tac_108;
        float temp_var_for_const_110;
        temp_var_for_tac_103 = z * p1;

        temp_var_for_tac_104 = y * p3;

        temp_var_for_tac_105 = p2 + temp_var_for_tac_104;

        temp_var_for_tac_106 = w * temp_var_for_tac_105;

        temp_var_for_tac_107 = tt - temp_var_for_tac_106;

        temp_var_for_tac_108 = temp_var_for_tac_103 - temp_var_for_tac_107;

        p = temp_var_for_tac_108;
        computeFMul((Addr)&temp_var_for_tac_103, {(Addr)&z, (Addr)&p1},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:370:15");
        computeFMul((Addr)&temp_var_for_tac_104, {(Addr)&y, (Addr)&p3},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:370:40");
        computeFAdd((Addr)&temp_var_for_tac_105,
                    {(Addr)&p2, (Addr)&temp_var_for_tac_104},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:370:36");
        computeFMul((Addr)&temp_var_for_tac_106,
                    {(Addr)&w, (Addr)&temp_var_for_tac_105},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:370:30");
        computeFSub((Addr)&temp_var_for_tac_107,
                    {(Addr) &(temp_var_for_const_110 = tt),
                     (Addr)&temp_var_for_tac_106},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:370:26");
        computeFSub((Addr)&temp_var_for_tac_108,
                    {(Addr)&temp_var_for_tac_103, (Addr)&temp_var_for_tac_107},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:370:20");
        AssignF({(Addr)&p}, (Addr)&temp_var_for_tac_108,
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:370:11");
        ;
        float temp_var_for_tac_109;
        float temp_var_for_const_111;
        temp_var_for_tac_109 = tf + p;

        r += temp_var_for_tac_109;
        ;
        break;
      case 2: {
        float temp_var_for_ext_18;
        float temp_var_for_tac_111, temp_var_for_tac_112, temp_var_for_tac_113,
            temp_var_for_tac_114, temp_var_for_tac_115, temp_var_for_tac_116,
            temp_var_for_tac_117, temp_var_for_tac_118, temp_var_for_tac_119,
            temp_var_for_tac_120, temp_var_for_tac_121;
        float temp_var_for_const_112, temp_var_for_const_113,
            temp_var_for_const_114, temp_var_for_const_115,
            temp_var_for_const_116, temp_var_for_const_117;
        temp_var_for_tac_111 = y * u5;

        temp_var_for_tac_112 = u4 + temp_var_for_tac_111;

        temp_var_for_tac_113 = y * temp_var_for_tac_112;

        temp_var_for_tac_114 = u3 + temp_var_for_tac_113;

        temp_var_for_tac_115 = y * temp_var_for_tac_114;

        temp_var_for_tac_116 = u2 + temp_var_for_tac_115;

        temp_var_for_tac_117 = y * temp_var_for_tac_116;

        temp_var_for_tac_118 = u1 + temp_var_for_tac_117;

        temp_var_for_tac_119 = y * temp_var_for_tac_118;

        temp_var_for_tac_120 = u0 + temp_var_for_tac_119;

        temp_var_for_tac_121 = y * temp_var_for_tac_120;

        temp_var_for_ext_18 = temp_var_for_tac_121;
        computeFAdd((Addr)&temp_var_for_tac_109,
                    {(Addr) &(temp_var_for_const_111 = tf), (Addr)&p},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:371:18");
        computeFMul((Addr)&temp_var_for_tac_111,
                    {(Addr)&y, (Addr) &(temp_var_for_const_112 = u5)},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:376:65");
        computeFAdd((Addr)&temp_var_for_tac_112,
                    {(Addr) &(temp_var_for_const_113 = u4),
                     (Addr)&temp_var_for_tac_111},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:376:61");
        computeFMul((Addr)&temp_var_for_tac_113,
                    {(Addr)&y, (Addr)&temp_var_for_tac_112},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:376:55");
        computeFAdd((Addr)&temp_var_for_tac_114,
                    {(Addr) &(temp_var_for_const_114 = u3),
                     (Addr)&temp_var_for_tac_113},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:376:51");
        computeFMul((Addr)&temp_var_for_tac_115,
                    {(Addr)&y, (Addr)&temp_var_for_tac_114},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:376:45");
        computeFAdd((Addr)&temp_var_for_tac_116,
                    {(Addr) &(temp_var_for_const_115 = u2),
                     (Addr)&temp_var_for_tac_115},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:376:41");
        computeFMul((Addr)&temp_var_for_tac_117,
                    {(Addr)&y, (Addr)&temp_var_for_tac_116},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:376:35");
        computeFAdd((Addr)&temp_var_for_tac_118,
                    {(Addr) &(temp_var_for_const_116 = u1),
                     (Addr)&temp_var_for_tac_117},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:376:31");
        computeFMul((Addr)&temp_var_for_tac_119,
                    {(Addr)&y, (Addr)&temp_var_for_tac_118},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:376:25");
        computeFAdd((Addr)&temp_var_for_tac_120,
                    {(Addr) &(temp_var_for_const_117 = u0),
                     (Addr)&temp_var_for_tac_119},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:376:21");
        computeFMul((Addr)&temp_var_for_tac_121,
                    {(Addr)&y, (Addr)&temp_var_for_tac_120},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:376:15");
        AssignF({(Addr)&temp_var_for_ext_18}, (Addr)&temp_var_for_tac_121,
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:375:29");
        ; // p1
        /*(p3)(y)(p2)(w)(tt)(p1)(z)(p1)(z)(p3)(y)(p2)(w)(tt)(p3)(y)(p2)(w)(p3)(y)(p2)(p3)(y)(p)(tf)(r)(p)(tf)(u5)(y)(u4)(y)(u3)(y)(u2)(y)(u1)(y)(u0)(y)*/
        p1 = temp_var_for_ext_18;
        AssignF({(Addr)&p1}, (Addr)&temp_var_for_ext_18,
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:378:12");
        ;
      }

        float temp_var_for_tac_122, temp_var_for_tac_123, temp_var_for_tac_124,
            temp_var_for_tac_125, temp_var_for_tac_126, temp_var_for_tac_127,
            temp_var_for_tac_128, temp_var_for_tac_129, temp_var_for_tac_130,
            temp_var_for_tac_131;
        float temp_var_for_const_118, temp_var_for_const_119,
            temp_var_for_const_120, temp_var_for_const_121,
            temp_var_for_const_122, temp_var_for_const_123;
        temp_var_for_tac_122 = y * v5;

        temp_var_for_tac_123 = v4 + temp_var_for_tac_122;

        temp_var_for_tac_124 = y * temp_var_for_tac_123;

        temp_var_for_tac_125 = v3 + temp_var_for_tac_124;

        temp_var_for_tac_126 = y * temp_var_for_tac_125;

        temp_var_for_tac_127 = v2 + temp_var_for_tac_126;

        temp_var_for_tac_128 = y * temp_var_for_tac_127;

        temp_var_for_tac_129 = v1 + temp_var_for_tac_128;

        temp_var_for_tac_130 = y * temp_var_for_tac_129;

        temp_var_for_tac_131 = one + temp_var_for_tac_130;

        p2 = temp_var_for_tac_131;
        computeFMul((Addr)&temp_var_for_tac_122,
                    {(Addr)&y, (Addr) &(temp_var_for_const_118 = v5)},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:381:62");
        computeFAdd((Addr)&temp_var_for_tac_123,
                    {(Addr) &(temp_var_for_const_119 = v4),
                     (Addr)&temp_var_for_tac_122},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:381:58");
        computeFMul((Addr)&temp_var_for_tac_124,
                    {(Addr)&y, (Addr)&temp_var_for_tac_123},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:381:52");
        computeFAdd((Addr)&temp_var_for_tac_125,
                    {(Addr) &(temp_var_for_const_120 = v3),
                     (Addr)&temp_var_for_tac_124},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:381:48");
        computeFMul((Addr)&temp_var_for_tac_126,
                    {(Addr)&y, (Addr)&temp_var_for_tac_125},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:381:42");
        computeFAdd((Addr)&temp_var_for_tac_127,
                    {(Addr) &(temp_var_for_const_121 = v2),
                     (Addr)&temp_var_for_tac_126},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:381:38");
        computeFMul((Addr)&temp_var_for_tac_128,
                    {(Addr)&y, (Addr)&temp_var_for_tac_127},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:381:32");
        computeFAdd((Addr)&temp_var_for_tac_129,
                    {(Addr) &(temp_var_for_const_122 = v1),
                     (Addr)&temp_var_for_tac_128},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:381:28");
        computeFMul((Addr)&temp_var_for_tac_130,
                    {(Addr)&y, (Addr)&temp_var_for_tac_129},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:381:22");
        computeFAdd((Addr)&temp_var_for_tac_131,
                    {(Addr) &(temp_var_for_const_123 = one),
                     (Addr)&temp_var_for_tac_130},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:381:18");
        AssignF({(Addr)&p2}, (Addr)&temp_var_for_tac_131,
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:381:12");
        ;
        float temp_var_for_tac_132, temp_var_for_tac_133, temp_var_for_tac_134,
            temp_var_for_tac_135;
        float temp_var_for_const_124, temp_var_for_const_125;
        temp_var_for_tac_132 = 0.0 - 0.5F;

        temp_var_for_tac_133 = temp_var_for_tac_132 * y;

        temp_var_for_tac_134 = p1 / p2;

        temp_var_for_tac_135 = temp_var_for_tac_133 + temp_var_for_tac_134;

        r += temp_var_for_tac_135;
        ;
        break;
      }
    } else {
      if (ix < IC(0x41000000)) { /* x < 8.0 */
        i = (int32_t)x;
        float temp_var_for_const_126;
        t = zero;
        computeDSub((Addr)&temp_var_for_tac_132,
                    {(Addr) &(temp_var_for_const_125 = 0.0),
                     (Addr) &(temp_var_for_const_124 = 0.5F)},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:382:20");
        computeDMul((Addr)&temp_var_for_tac_133,
                    {(Addr)&temp_var_for_tac_132, (Addr)&y},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:382:28");
        computeFDiv((Addr)&temp_var_for_tac_134, {(Addr)&p1, (Addr)&p2},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:382:37");
        computeDAdd((Addr)&temp_var_for_tac_135,
                    {(Addr)&temp_var_for_tac_133, (Addr)&temp_var_for_tac_134},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:382:32");
        AssignF({(Addr)&t}, (Addr) &(temp_var_for_const_126 = zero),
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:388:11");
        ;
        float temp_var_for_tac_137;
        float temp_var_for_const_127;
        temp_var_for_tac_137 = x - ((float)i);

        y = temp_var_for_tac_137;
        computeFSub((Addr)&temp_var_for_tac_137,
                    {(Addr)&x, (Addr) &(temp_var_for_const_127 = ((float)i))},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:389:15");
        AssignF({(Addr)&y}, (Addr)&temp_var_for_tac_137,
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:389:11");
        ;
        float temp_var_for_tac_138, temp_var_for_tac_139, temp_var_for_tac_140,
            temp_var_for_tac_141, temp_var_for_tac_142, temp_var_for_tac_143,
            temp_var_for_tac_144, temp_var_for_tac_145, temp_var_for_tac_146,
            temp_var_for_tac_147, temp_var_for_tac_148, temp_var_for_tac_149,
            temp_var_for_tac_150;
        float temp_var_for_const_128, temp_var_for_const_129,
            temp_var_for_const_130, temp_var_for_const_131,
            temp_var_for_const_132, temp_var_for_const_133,
            temp_var_for_const_134;
        temp_var_for_tac_138 = y * s6;

        temp_var_for_tac_139 = s5 + temp_var_for_tac_138;

        temp_var_for_tac_140 = y * temp_var_for_tac_139;

        temp_var_for_tac_141 = s4 + temp_var_for_tac_140;

        temp_var_for_tac_142 = y * temp_var_for_tac_141;

        temp_var_for_tac_143 = s3 + temp_var_for_tac_142;

        temp_var_for_tac_144 = y * temp_var_for_tac_143;

        temp_var_for_tac_145 = s2 + temp_var_for_tac_144;

        temp_var_for_tac_146 = y * temp_var_for_tac_145;

        temp_var_for_tac_147 = s1 + temp_var_for_tac_146;

        temp_var_for_tac_148 = y * temp_var_for_tac_147;

        temp_var_for_tac_149 = s0 + temp_var_for_tac_148;

        temp_var_for_tac_150 = y * temp_var_for_tac_149;

        p = temp_var_for_tac_150;
        computeFMul((Addr)&temp_var_for_tac_138,
                    {(Addr)&y, (Addr) &(temp_var_for_const_128 = s6)},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:391:70");
        computeFAdd((Addr)&temp_var_for_tac_139,
                    {(Addr) &(temp_var_for_const_129 = s5),
                     (Addr)&temp_var_for_tac_138},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:391:66");
        computeFMul((Addr)&temp_var_for_tac_140,
                    {(Addr)&y, (Addr)&temp_var_for_tac_139},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:391:60");
        computeFAdd((Addr)&temp_var_for_tac_141,
                    {(Addr) &(temp_var_for_const_130 = s4),
                     (Addr)&temp_var_for_tac_140},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:391:56");
        computeFMul((Addr)&temp_var_for_tac_142,
                    {(Addr)&y, (Addr)&temp_var_for_tac_141},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:391:50");
        computeFAdd((Addr)&temp_var_for_tac_143,
                    {(Addr) &(temp_var_for_const_131 = s3),
                     (Addr)&temp_var_for_tac_142},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:391:46");
        computeFMul((Addr)&temp_var_for_tac_144,
                    {(Addr)&y, (Addr)&temp_var_for_tac_143},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:391:40");
        computeFAdd((Addr)&temp_var_for_tac_145,
                    {(Addr) &(temp_var_for_const_132 = s2),
                     (Addr)&temp_var_for_tac_144},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:391:36");
        computeFMul((Addr)&temp_var_for_tac_146,
                    {(Addr)&y, (Addr)&temp_var_for_tac_145},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:391:30");
        computeFAdd((Addr)&temp_var_for_tac_147,
                    {(Addr) &(temp_var_for_const_133 = s1),
                     (Addr)&temp_var_for_tac_146},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:391:26");
        computeFMul((Addr)&temp_var_for_tac_148,
                    {(Addr)&y, (Addr)&temp_var_for_tac_147},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:391:20");
        computeFAdd((Addr)&temp_var_for_tac_149,
                    {(Addr) &(temp_var_for_const_134 = s0),
                     (Addr)&temp_var_for_tac_148},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:390:21");
        computeFMul((Addr)&temp_var_for_tac_150,
                    {(Addr)&y, (Addr)&temp_var_for_tac_149},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:390:15");
        AssignF({(Addr)&p}, (Addr)&temp_var_for_tac_150,
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:390:11");
        ;
        float temp_var_for_tac_151, temp_var_for_tac_152, temp_var_for_tac_153,
            temp_var_for_tac_154, temp_var_for_tac_155, temp_var_for_tac_156,
            temp_var_for_tac_157, temp_var_for_tac_158, temp_var_for_tac_159,
            temp_var_for_tac_160, temp_var_for_tac_161, temp_var_for_tac_162;
        float temp_var_for_const_135, temp_var_for_const_136,
            temp_var_for_const_137, temp_var_for_const_138,
            temp_var_for_const_139, temp_var_for_const_140,
            temp_var_for_const_141;
        temp_var_for_tac_151 = y * r6;

        temp_var_for_tac_152 = r5 + temp_var_for_tac_151;

        temp_var_for_tac_153 = y * temp_var_for_tac_152;

        temp_var_for_tac_154 = r4 + temp_var_for_tac_153;

        temp_var_for_tac_155 = y * temp_var_for_tac_154;

        temp_var_for_tac_156 = r3 + temp_var_for_tac_155;

        temp_var_for_tac_157 = y * temp_var_for_tac_156;

        temp_var_for_tac_158 = r2 + temp_var_for_tac_157;

        temp_var_for_tac_159 = y * temp_var_for_tac_158;

        temp_var_for_tac_160 = r1 + temp_var_for_tac_159;

        temp_var_for_tac_161 = y * temp_var_for_tac_160;

        temp_var_for_tac_162 = one + temp_var_for_tac_161;

        q = temp_var_for_tac_162;
        computeFMul((Addr)&temp_var_for_tac_151,
                    {(Addr)&y, (Addr) &(temp_var_for_const_135 = r6)},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:392:71");
        computeFAdd((Addr)&temp_var_for_tac_152,
                    {(Addr) &(temp_var_for_const_136 = r5),
                     (Addr)&temp_var_for_tac_151},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:392:67");
        computeFMul((Addr)&temp_var_for_tac_153,
                    {(Addr)&y, (Addr)&temp_var_for_tac_152},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:392:61");
        computeFAdd((Addr)&temp_var_for_tac_154,
                    {(Addr) &(temp_var_for_const_137 = r4),
                     (Addr)&temp_var_for_tac_153},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:392:57");
        computeFMul((Addr)&temp_var_for_tac_155,
                    {(Addr)&y, (Addr)&temp_var_for_tac_154},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:392:51");
        computeFAdd((Addr)&temp_var_for_tac_156,
                    {(Addr) &(temp_var_for_const_138 = r3),
                     (Addr)&temp_var_for_tac_155},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:392:47");
        computeFMul((Addr)&temp_var_for_tac_157,
                    {(Addr)&y, (Addr)&temp_var_for_tac_156},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:392:41");
        computeFAdd((Addr)&temp_var_for_tac_158,
                    {(Addr) &(temp_var_for_const_139 = r2),
                     (Addr)&temp_var_for_tac_157},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:392:37");
        computeFMul((Addr)&temp_var_for_tac_159,
                    {(Addr)&y, (Addr)&temp_var_for_tac_158},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:392:31");
        computeFAdd((Addr)&temp_var_for_tac_160,
                    {(Addr) &(temp_var_for_const_140 = r1),
                     (Addr)&temp_var_for_tac_159},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:392:27");
        computeFMul((Addr)&temp_var_for_tac_161,
                    {(Addr)&y, (Addr)&temp_var_for_tac_160},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:392:21");
        computeFAdd((Addr)&temp_var_for_tac_162,
                    {(Addr) &(temp_var_for_const_141 = one),
                     (Addr)&temp_var_for_tac_161},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:392:17");
        AssignF({(Addr)&q}, (Addr)&temp_var_for_tac_162,
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:392:11");
        ;
        float temp_var_for_tac_163, temp_var_for_tac_164, temp_var_for_tac_165;
        float temp_var_for_const_142;
        temp_var_for_tac_163 = half * y;

        temp_var_for_tac_164 = p / q;

        temp_var_for_tac_165 = temp_var_for_tac_163 + temp_var_for_tac_164;

        r = temp_var_for_tac_165;
        computeFMul((Addr)&temp_var_for_tac_163,
                    {(Addr) &(temp_var_for_const_142 = half), (Addr)&y},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:393:18");
        computeFDiv((Addr)&temp_var_for_tac_164, {(Addr)&p, (Addr)&q},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:393:26");
        computeFAdd((Addr)&temp_var_for_tac_165,
                    {(Addr)&temp_var_for_tac_163, (Addr)&temp_var_for_tac_164},
                    "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:393:22");
        AssignF({(Addr)&r}, (Addr)&temp_var_for_tac_165,
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:393:11");
        ;
        float temp_var_for_const_143;
        z = one;
        AssignF({(Addr)&z}, (Addr) &(temp_var_for_const_143 = one),
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:394:11");
        ; /* lgamma(1+s) = log(s) + lgamma(s) */
        int temp_var_for_ext_19;
        temp_var_for_ext_19 = (int)i;
        switch (temp_var_for_ext_19) {
        case 7: {
          float temp_var_for_tac_166;
          float temp_var_for_const_144;
          temp_var_for_tac_166 = y + 6.0F;

          z *= temp_var_for_tac_166;
          ;
        }
        /* FALLTHRU */
        case 6: {
          float temp_var_for_tac_168;
          float temp_var_for_const_145;
          temp_var_for_tac_168 = y + 5.0F;

          z *= temp_var_for_tac_168;
          ;
        }
        /* FALLTHRU */
        case 5: {
          float temp_var_for_tac_170;
          float temp_var_for_const_146;
          temp_var_for_tac_170 = y + 4.0F;

          z *= temp_var_for_tac_170;
          ;
        }
        /* FALLTHRU */
        case 4: {
          float temp_var_for_tac_172;
          float temp_var_for_const_147;
          temp_var_for_tac_172 = y + 3.0F;

          z *= temp_var_for_tac_172;
          ;
        }
        /* FALLTHRU */
        case 3: {
          float temp_var_for_tac_174;
          float temp_var_for_const_148;
          temp_var_for_tac_174 = y + 2.0F;

          z *= temp_var_for_tac_174;
          ;
        }
          /* FALLTHRU */
          float temp_var_for_callexp_16;

          temp_var_for_callexp_16 = __ieee754_logf(z);
          r += temp_var_for_callexp_16;
          ;
          break;
        }
        /* 8.0 <= x < 2**58 */
      } else {
        if (ix < IC(0x5c800000)) {
          float temp_var_for_const_149;
          float temp_var_for_callexp_17;

          temp_var_for_callexp_17 = __ieee754_logf(x);
          t = temp_var_for_callexp_17;
          computeFAdd(
              (Addr)&temp_var_for_tac_166,
              {(Addr)&y, (Addr) &(temp_var_for_const_144 = 6.0F)},
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:399:19");
          computeFAdd(
              (Addr)&temp_var_for_tac_168,
              {(Addr)&y, (Addr) &(temp_var_for_const_145 = 5.0F)},
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:403:19");
          computeFAdd(
              (Addr)&temp_var_for_tac_170,
              {(Addr)&y, (Addr) &(temp_var_for_const_146 = 4.0F)},
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:407:19");
          computeFAdd(
              (Addr)&temp_var_for_tac_172,
              {(Addr)&y, (Addr) &(temp_var_for_const_147 = 3.0F)},
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:411:19");
          computeFAdd(
              (Addr)&temp_var_for_tac_174,
              {(Addr)&y, (Addr) &(temp_var_for_const_148 = 2.0F)},
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:415:19");
          AssignF({(Addr)&t},
                  (Addr) &(temp_var_for_const_149 = temp_var_for_callexp_17),
                  "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:424:13");
          ;
          float temp_var_for_tac_177;
          float temp_var_for_const_150;
          temp_var_for_tac_177 = one / x;

          z = temp_var_for_tac_177;
          computeFDiv(
              (Addr)&temp_var_for_tac_177,
              {(Addr) &(temp_var_for_const_150 = one), (Addr)&x},
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:425:19");
          AssignF({(Addr)&z}, (Addr)&temp_var_for_tac_177,
                  "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:425:13");
          ;
          float temp_var_for_tac_178;
          temp_var_for_tac_178 = z * z;

          y = temp_var_for_tac_178;
          computeFMul(
              (Addr)&temp_var_for_tac_178, {(Addr)&z, (Addr)&z},
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:426:17");
          AssignF({(Addr)&y}, (Addr)&temp_var_for_tac_178,
                  "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:426:13");
          ;
          float temp_var_for_tac_179, temp_var_for_tac_180,
              temp_var_for_tac_181, temp_var_for_tac_182, temp_var_for_tac_183,
              temp_var_for_tac_184, temp_var_for_tac_185, temp_var_for_tac_186,
              temp_var_for_tac_187, temp_var_for_tac_188, temp_var_for_tac_189,
              temp_var_for_tac_190;
          float temp_var_for_const_151, temp_var_for_const_152,
              temp_var_for_const_153, temp_var_for_const_154,
              temp_var_for_const_155, temp_var_for_const_156,
              temp_var_for_const_157;
          temp_var_for_tac_179 = y * w6;

          temp_var_for_tac_180 = w5 + temp_var_for_tac_179;

          temp_var_for_tac_181 = y * temp_var_for_tac_180;

          temp_var_for_tac_182 = w4 + temp_var_for_tac_181;

          temp_var_for_tac_183 = y * temp_var_for_tac_182;

          temp_var_for_tac_184 = w3 + temp_var_for_tac_183;

          temp_var_for_tac_185 = y * temp_var_for_tac_184;

          temp_var_for_tac_186 = w2 + temp_var_for_tac_185;

          temp_var_for_tac_187 = y * temp_var_for_tac_186;

          temp_var_for_tac_188 = w1 + temp_var_for_tac_187;

          temp_var_for_tac_189 = z * temp_var_for_tac_188;

          temp_var_for_tac_190 = w0 + temp_var_for_tac_189;

          w = temp_var_for_tac_190;
          computeFMul(
              (Addr)&temp_var_for_tac_179,
              {(Addr)&y, (Addr) &(temp_var_for_const_151 = w6)},
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:428:67");
          computeFAdd(
              (Addr)&temp_var_for_tac_180,
              {(Addr) &(temp_var_for_const_152 = w5),
               (Addr)&temp_var_for_tac_179},
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:428:63");
          computeFMul(
              (Addr)&temp_var_for_tac_181,
              {(Addr)&y, (Addr)&temp_var_for_tac_180},
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:428:57");
          computeFAdd(
              (Addr)&temp_var_for_tac_182,
              {(Addr) &(temp_var_for_const_153 = w4),
               (Addr)&temp_var_for_tac_181},
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:428:53");
          computeFMul(
              (Addr)&temp_var_for_tac_183,
              {(Addr)&y, (Addr)&temp_var_for_tac_182},
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:428:47");
          computeFAdd(
              (Addr)&temp_var_for_tac_184,
              {(Addr) &(temp_var_for_const_154 = w3),
               (Addr)&temp_var_for_tac_183},
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:428:43");
          computeFMul(
              (Addr)&temp_var_for_tac_185,
              {(Addr)&y, (Addr)&temp_var_for_tac_184},
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:428:37");
          computeFAdd(
              (Addr)&temp_var_for_tac_186,
              {(Addr) &(temp_var_for_const_155 = w2),
               (Addr)&temp_var_for_tac_185},
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:428:33");
          computeFMul(
              (Addr)&temp_var_for_tac_187,
              {(Addr)&y, (Addr)&temp_var_for_tac_186},
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:428:27");
          computeFAdd(
              (Addr)&temp_var_for_tac_188,
              {(Addr) &(temp_var_for_const_156 = w1),
               (Addr)&temp_var_for_tac_187},
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:428:23");
          computeFMul(
              (Addr)&temp_var_for_tac_189,
              {(Addr)&z, (Addr)&temp_var_for_tac_188},
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:428:17");
          computeFAdd(
              (Addr)&temp_var_for_tac_190,
              {(Addr) &(temp_var_for_const_157 = w0),
               (Addr)&temp_var_for_tac_189},
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:427:18");
          AssignF({(Addr)&w}, (Addr)&temp_var_for_tac_190,
                  "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:427:13");
          ;
          float temp_var_for_tac_191, temp_var_for_tac_192,
              temp_var_for_tac_193, temp_var_for_tac_194;
          float temp_var_for_const_158, temp_var_for_const_159;
          temp_var_for_tac_191 = x - half;

          temp_var_for_tac_192 = t - one;

          temp_var_for_tac_193 = temp_var_for_tac_191 * temp_var_for_tac_192;

          temp_var_for_tac_194 = temp_var_for_tac_193 + w;

          r = temp_var_for_tac_194;
          computeFSub(
              (Addr)&temp_var_for_tac_191,
              {(Addr)&x, (Addr) &(temp_var_for_const_158 = half)},
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:429:18");
          computeFSub(
              (Addr)&temp_var_for_tac_192,
              {(Addr)&t, (Addr) &(temp_var_for_const_159 = one)},
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:429:31");
          computeFMul(
              (Addr)&temp_var_for_tac_193,
              {(Addr)&temp_var_for_tac_191, (Addr)&temp_var_for_tac_192},
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:429:26");
          computeFAdd(
              (Addr)&temp_var_for_tac_194,
              {(Addr)&temp_var_for_tac_193, (Addr)&w},
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:429:38");
          AssignF({(Addr)&r}, (Addr)&temp_var_for_tac_194,
                  "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:429:13");
          ;
        } else
        /* 2**58 <= x <= inf */
        {
          float temp_var_for_tac_195, temp_var_for_tac_196;
          float temp_var_for_const_160, temp_var_for_const_161;
          float temp_var_for_callexp_18;

          temp_var_for_callexp_18 = __ieee754_logf(x);
          temp_var_for_tac_195 = temp_var_for_callexp_18 - one;

          temp_var_for_tac_196 = x * temp_var_for_tac_195;

          r = temp_var_for_tac_196;
          computeFSub(
              (Addr)&temp_var_for_tac_195,
              {(Addr) &(temp_var_for_const_161 = temp_var_for_callexp_18),
               (Addr) &(temp_var_for_const_160 = one)},
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:433:38");
          computeFMul(
              (Addr)&temp_var_for_tac_196,
              {(Addr)&x, (Addr)&temp_var_for_tac_195},
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:433:17");
          AssignF({(Addr)&r}, (Addr)&temp_var_for_tac_196,
                  "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:433:13");
          ;
        }
      }
    }
  }

  if (hx < 0) {
    float temp_var_for_ext_20;
    float temp_var_for_tac_197;
    temp_var_for_tac_197 = nadj - r;

    temp_var_for_ext_20 = temp_var_for_tac_197;
    computeFSub((Addr)&temp_var_for_tac_197, {(Addr)&nadj, (Addr)&r},
                "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:441:32");
    AssignF({(Addr)&temp_var_for_ext_20}, (Addr)&temp_var_for_tac_197,
            "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:441:25");
    ; // r
    /*(one)(__ieee754_logf(x))(x)(one)(__ieee754_logf(x))(r)(nadj)*/
    r = temp_var_for_ext_20;
    AssignF({(Addr)&r}, (Addr)&temp_var_for_ext_20,
            "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:443:7");
    ;
  }

  float temp_var_for_ext_21;
  temp_var_for_ext_21 = r;
  AssignF({(Addr)&temp_var_for_ext_21}, (Addr)&r,
          "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:447:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_21", (Addr)&temp_var_for_ext_21));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_21;
}
