#include "../ScDebug/scdebug.h"
/* e_powf.c -- float version of e_pow.c.
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

#ifndef __have_fpu_pow

float __ieee754_powf(float x, float y) {
  float z, ax, z_h, z_l, p_h, p_l;
  float y1, t1, t2, r, s, t, u, v, w;
  int32_t i, j, k, yisint, n;
  int32_t hx, hy, ix, iy, is;

  static const float bp[] = {1.0, 1.5};
  static const float dp_h[] = {0.0, 5.84960938e-01}; /* 0x3f15c000 */
  static const float dp_l[] = {0.0, 1.56322085e-06}; /* 0x35d1cfdc */
  static const float zero = 0.0;
  static const float one = 1.0;
  static const float two = 2.0;
  static const float two24 = 16777216.0; /* 0x4b800000 */
  /* poly coefs for (3/2)*(log(x)-2s-2/3*s**3 */
  static const float L1 = 6.0000002384e-01; /* 0x3f19999a */
  static const float L2 = 4.2857143283e-01; /* 0x3edb6db7 */
  static const float L3 = 3.3333334327e-01; /* 0x3eaaaaab */
  static const float L4 = 2.7272811532e-01; /* 0x3e8ba305 */
  static const float L5 = 2.3066075146e-01; /* 0x3e6c3255 */
  static const float L6 = 2.0697501302e-01; /* 0x3e53f142 */
  static const float P1 = 1.6666667163e-01; /* 0x3e2aaaab */
  static const float P2 = (double temp_var_for_tac_0;
                           double temp_var_for_const_0, temp_var_for_const_1;
                           temp_var_for_tac_0 = 0.0 - 2.7777778450e-03;

                           );               /* 0xbb360b61 */
  static const float P3 = 6.6137559770e-05; /* 0x388ab355 */
  static const float P4 = (double temp_var_for_tac_1;
                           double temp_var_for_const_2, temp_var_for_const_3;
                           temp_var_for_tac_1 = 0.0 - 1.6533901999e-06;

                           );                    /* 0xb5ddea0e */
  static const float P5 = 4.1381369442e-08;      /* 0x3331bb4c */
  static const float lg2 = 6.9314718246e-01;     /* 0x3f317218 */
  static const float lg2_h = 6.93145752e-01;     /* 0x3f317200 */
  static const float lg2_l = 1.42860654e-06;     /* 0x35bfbe8c */
  static const float ovt = 4.2995665694e-08;     /* -(128-log2(ovfl+.5ulp)) */
  static const float cp = 9.6179670095e-01;      /* 0x3f76384f =2/(3ln2) */
  static const float cp_h = 9.6179199219e-01;    /* 0x3f763800 =head of cp */
  static const float cp_l = 4.7017383622e-06;    /* 0x369dc3a0 =tail of cp_h */
  static const float ivln2 = 1.4426950216e+00;   /* 0x3fb8aa3b =1/ln2 */
  static const float ivln2_h = 1.4426879883e+00; /* 0x3fb8aa00 =16b 1/ln2 */
  static const float ivln2_l = 7.0526075433e-06; /* 0x36eca570 =1/ln2 tail */

  GET_FLOAT_WORD(hx, x);
  GET_FLOAT_WORD(hy, y);
  ix = hx & IC(0x7fffffff);
  iy = hy & IC(0x7fffffff);

  /* y==zero: x**0 = 1 */
  if (FLT_UWORD_IS_ZERO(iy)) {
    /* unless x is signaling NaN */
    if (issignalingf(x)) {
      float temp_var_for_ext_0;
      float temp_var_for_const_4;
      float temp_var_for_callexp_0;

      temp_var_for_callexp_0 = __builtin_nanf("");
      temp_var_for_ext_0 = temp_var_for_callexp_0;
      computeDSub((Addr)&temp_var_for_tac_0,
                  {(Addr) &(temp_var_for_const_1 = 0.0),
                   (Addr) &(temp_var_for_const_0 = 2.7777778450e-03)},
                  "/home/shijia/Public/testprogram/e_powf.c_e.c:43:32");
      computeDSub((Addr)&temp_var_for_tac_1,
                  {(Addr) &(temp_var_for_const_3 = 0.0),
                   (Addr) &(temp_var_for_const_2 = 1.6533901999e-06)},
                  "/home/shijia/Public/testprogram/e_powf.c_e.c:45:32");
      AssignF({(Addr)&temp_var_for_ext_0},
              (Addr) &(temp_var_for_const_4 = temp_var_for_callexp_0),
              "/home/shijia/Public/testprogram/e_powf.c_e.c:68:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_0;
    }

    float temp_var_for_ext_1;
    float temp_var_for_const_5;
    temp_var_for_ext_1 = one;
    AssignF({(Addr)&temp_var_for_ext_1}, (Addr) &(temp_var_for_const_5 = one),
            "/home/shijia/Public/testprogram/e_powf.c_e.c:76:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }

  /* x==+-1 */
  if (int temp_var_for_tac_2; int temp_var_for_const_6;
      temp_var_for_tac_2 = x == 1.0F;

      ) {
    float temp_var_for_ext_2;
    float temp_var_for_const_7;
    temp_var_for_ext_2 = one;
    compute((Addr)&temp_var_for_tac_2,
            {(Addr)&x, (Addr) &(temp_var_for_const_6 = 1.0F)},
            "/home/shijia/Public/testprogram/e_powf.c_e.c:83:9");
    AssignF({(Addr)&temp_var_for_ext_2}, (Addr) &(temp_var_for_const_7 = one),
            "/home/shijia/Public/testprogram/e_powf.c_e.c:85:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  }

  if (int temp_var_for_tac_3, temp_var_for_tac_4;
      int temp_var_for_const_8, temp_var_for_const_9;
      temp_var_for_tac_3 = 0.0 - 1.0F;

      temp_var_for_tac_4 = x == temp_var_for_tac_3;

      &&isinf(y)) {
    float temp_var_for_ext_3;
    float temp_var_for_const_10;
    temp_var_for_ext_3 = one;
    computeDSub((Addr)&temp_var_for_tac_3,
                {(Addr) &(temp_var_for_const_9 = 0.0),
                 (Addr) &(temp_var_for_const_8 = 1.0F)},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:91:17");
    compute((Addr)&temp_var_for_tac_4, {(Addr)&x, (Addr)&temp_var_for_tac_3},
            "/home/shijia/Public/testprogram/e_powf.c_e.c:91:9");
    AssignF({(Addr)&temp_var_for_ext_3}, (Addr) &(temp_var_for_const_10 = one),
            "/home/shijia/Public/testprogram/e_powf.c_e.c:93:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_3;
  }

  /* +-NaN return x+y */
  if (FLT_UWORD_IS_NAN(ix) || FLT_UWORD_IS_NAN(iy)) {
    float temp_var_for_ext_4;
    float temp_var_for_tac_5;
    temp_var_for_tac_5 = x + y;

    temp_var_for_ext_4 = temp_var_for_tac_5;
    computeFAdd((Addr)&temp_var_for_tac_5, {(Addr)&x, (Addr)&y},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:102:28");
    AssignF({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_5,
            "/home/shijia/Public/testprogram/e_powf.c_e.c:102:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_4;
  }

  /* determine if y is an odd int when x < 0
   * yisint = 0   ... y is not an integer
   * yisint = 1   ... y is an odd int
   * yisint = 2   ... y is an even int
   */
  yisint = 0;
  if (hx < 0) {
    if (iy >= IC(0x4b800000)) /* |y| >= 2**24 */
    {
      yisint = 2;
    }
    /* even integer y */
    else {
      if (iy >= IC(0x3f800000)) /* |y| >= 2**0 */
      {
        k = (iy >> IEEE754_FLOAT_SHIFT) - IEEE754_FLOAT_BIAS; /* exponent */
        j = iy >> (IEEE754_FLOAT_SHIFT - k);
        if ((j << (IEEE754_FLOAT_SHIFT - k)) == iy) {
          yisint = 2 - (j & 1);
        }
      }
    }
  }

  /* special value of y */
  if (FLT_UWORD_IS_INFINITE(iy)) { /* y is +-inf */
    if (ix == IC(0x3f800000)) {
      float temp_var_for_ext_5;
      float temp_var_for_const_11;
      temp_var_for_ext_5 = one;
      AssignF({(Addr)&temp_var_for_ext_5},
              (Addr) &(temp_var_for_const_11 = one),
              "/home/shijia/Public/testprogram/e_powf.c_e.c:136:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_5;
    }
    /* +-1**+-inf = 1 */
    else {
      if (ix > IC(0x3f800000)) /* (|x|>1)**+-inf = inf,0 */
      {
        float temp_var_for_ext_6;
        float temp_var_for_const_12;
        temp_var_for_ext_6 = (hy >= 0) ? y : zero;
        AssignF({(Addr)&temp_var_for_ext_6},
                (Addr) &(temp_var_for_const_12 = (hy >= 0) ? y : zero),
                "/home/shijia/Public/testprogram/e_powf.c_e.c:147:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_6;
      }

      else /* (|x|<1)**-,+inf = inf,0 */
      {
        float temp_var_for_ext_7;
        temp_var_for_ext_7 = (hy < 0) ? -y : zero;
        callExpStack.push(
            getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_(0.0 - o) r_ext_7;
      }
    }
  }
  if (iy == IC(0x3f800000)) { /* y is  +-1 */
    if (hy < 0) {
      float temp_var_for_ext_8;
      float temp_var_for_tac_6;
      float temp_var_for_const_13;
      temp_var_for_tac_6 = one / x;

      temp_var_for_ext_8 = temp_var_for_tac_6;
      computeFDiv((Addr)&temp_var_for_tac_6,
                  {(Addr) &(temp_var_for_const_13 = one), (Addr)&x},
                  "/home/shijia/Public/testprogram/e_powf.c_e.c:168:32");
      AssignF({(Addr)&temp_var_for_ext_8}, (Addr)&temp_var_for_tac_6,
              "/home/shijia/Public/testprogram/e_powf.c_e.c:168:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_8;
    }

    else {
      float temp_var_for_ext_9;
      temp_var_for_ext_9 = x;
      AssignF({(Addr)&temp_var_for_ext_9}, (Addr)&x,
              "/home/shijia/Public/testprogram/e_powf.c_e.c:177:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_9;
    }
  }
  if (hy == IC(0x40000000)) {
    float temp_var_for_ext_10;
    float temp_var_for_tac_7;
    temp_var_for_tac_7 = x * x;

    temp_var_for_ext_10 = temp_var_for_tac_7;
    computeFMul((Addr)&temp_var_for_tac_7, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:186:29");
    AssignF({(Addr)&temp_var_for_ext_10}, (Addr)&temp_var_for_tac_7,
            "/home/shijia/Public/testprogram/e_powf.c_e.c:186:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_10", (Addr)&temp_var_for_ext_10));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_10;
  }
  /* y is  2 */
  if (hy == IC(0x3f000000)) { /* y is  0.5 */
    if (hx >= 0)              /* x >= +0 */
    {
      float temp_var_for_ext_11;
      float temp_var_for_const_14;
      float temp_var_for_callexp_1;

      temp_var_for_callexp_1 = __ieee754_sqrtf(x);
      temp_var_for_ext_11 = temp_var_for_callexp_1;
      AssignF({(Addr)&temp_var_for_ext_11},
              (Addr) &(temp_var_for_const_14 = temp_var_for_callexp_1),
              "/home/shijia/Public/testprogram/e_powf.c_e.c:197:27");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_11", (Addr)&temp_var_for_ext_11));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_11;
    }
  }

  float temp_var_for_const_15;
  float temp_var_for_callexp_2;

  temp_var_for_callexp_2 = fabsf(x);
  ax = temp_var_for_callexp_2;
  AssignF({(Addr)&ax}, (Addr) &(temp_var_for_const_15 = temp_var_for_callexp_2),
          "/home/shijia/Public/testprogram/e_powf.c_e.c:205:6");
  ;
  /* special value of x */
  if (FLT_UWORD_IS_INFINITE(ix) || FLT_UWORD_IS_ZERO(ix) ||
      ix == IC(0x3f800000)) {
    z = ax;
    AssignF({(Addr)&z}, (Addr)&ax,
            "/home/shijia/Public/testprogram/e_powf.c_e.c:209:7");
    ; /*x is +-0,+-inf,+-1 */
    if (hy < 0) {
      float temp_var_for_ext_12;
      float temp_var_for_tac_8;
      float temp_var_for_const_16;
      temp_var_for_tac_8 = one / z;

      temp_var_for_ext_12 = temp_var_for_tac_8;
      computeFDiv((Addr)&temp_var_for_tac_8,
                  {(Addr) &(temp_var_for_const_16 = one), (Addr)&z},
                  "/home/shijia/Public/testprogram/e_powf.c_e.c:212:33");
      AssignF({(Addr)&temp_var_for_ext_12}, (Addr)&temp_var_for_tac_8,
              "/home/shijia/Public/testprogram/e_powf.c_e.c:212:27");
      ; // z
      /*(z)(one)*/
      z = temp_var_for_ext_12;
      AssignF({(Addr)&z}, (Addr)&temp_var_for_ext_12,
              "/home/shijia/Public/testprogram/e_powf.c_e.c:214:9");
      ;
    }
    /* z = (1/|x|) */
    if (hx < 0) {
      if (((ix - IC(0x3f800000)) | yisint) == 0) {
        float temp_var_for_ext_13;
        float temp_var_for_tac_9, temp_var_for_tac_10, temp_var_for_tac_11;
        temp_var_for_tac_9 = z - z;

        temp_var_for_tac_10 = z - z;

        temp_var_for_tac_11 = temp_var_for_tac_9 / temp_var_for_tac_10;

        temp_var_for_ext_13 = temp_var_for_tac_11;
        computeFSub((Addr)&temp_var_for_tac_9, {(Addr)&z, (Addr)&z},
                    "/home/shijia/Public/testprogram/e_powf.c_e.c:220:34");
        computeFSub((Addr)&temp_var_for_tac_10, {(Addr)&z, (Addr)&z},
                    "/home/shijia/Public/testprogram/e_powf.c_e.c:220:44");
        computeFDiv((Addr)&temp_var_for_tac_11,
                    {(Addr)&temp_var_for_tac_9, (Addr)&temp_var_for_tac_10},
                    "/home/shijia/Public/testprogram/e_powf.c_e.c:220:39");
        AssignF({(Addr)&temp_var_for_ext_13}, (Addr)&temp_var_for_tac_11,
                "/home/shijia/Public/testprogram/e_powf.c_e.c:220:29");
        ; // z
        /*(z)(one)(z)(z)(z)(z)*/
        z = temp_var_for_ext_13;
        AssignF({(Addr)&z}, (Addr)&temp_var_for_ext_13,
                "/home/shijia/Public/testprogram/e_powf.c_e.c:222:11");
        ; /* (-1)**non-int is NaN */
      } else {
        if (yisint == 1) {
          float temp_var_for_ext_14;
          float temp_var_for_tac_12;
          float temp_var_for_const_17;
          temp_var_for_tac_12 = 0.0 - z;

          temp_var_for_ext_14 = temp_var_for_tac_12;
          computeDSub((Addr)&temp_var_for_tac_12,
                      {(Addr) &(temp_var_for_const_17 = 0.0), (Addr)&z},
                      "/home/shijia/Public/testprogram/e_powf.c_e.c:226:38");
          AssignF({(Addr)&temp_var_for_ext_14}, (Addr)&temp_var_for_tac_12,
                  "/home/shijia/Public/testprogram/e_powf.c_e.c:226:31");
          ; // z
          /*(z)(z)(z)(z)(z)(z)(z)(z)(z)(z)*/
          z = temp_var_for_ext_14;
          AssignF({(Addr)&z}, (Addr)&temp_var_for_ext_14,
                  "/home/shijia/Public/testprogram/e_powf.c_e.c:228:13");
          ;
        }
      }
      /* (x<0)**odd = -(|x|**odd) */
    }
    float temp_var_for_ext_15;
    temp_var_for_ext_15 = z;
    AssignF({(Addr)&temp_var_for_ext_15}, (Addr)&z,
            "/home/shijia/Public/testprogram/e_powf.c_e.c:234:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_15", (Addr)&temp_var_for_ext_15));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_15;
  }

  /* (x<0)**(non-int) is NaN */
  if (((((uint32_t)hx >> 31) - 1) | yisint) == 0) {
    float temp_var_for_ext_16;
    float temp_var_for_tac_13, temp_var_for_tac_14, temp_var_for_tac_15;
    temp_var_for_tac_13 = x - x;

    temp_var_for_tac_14 = x - x;

    temp_var_for_tac_15 = temp_var_for_tac_13 / temp_var_for_tac_14;

    temp_var_for_ext_16 = temp_var_for_tac_15;
    computeFSub((Addr)&temp_var_for_tac_13, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:244:30");
    computeFSub((Addr)&temp_var_for_tac_14, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:244:40");
    computeFDiv((Addr)&temp_var_for_tac_15,
                {(Addr)&temp_var_for_tac_13, (Addr)&temp_var_for_tac_14},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:244:35");
    AssignF({(Addr)&temp_var_for_ext_16}, (Addr)&temp_var_for_tac_15,
            "/home/shijia/Public/testprogram/e_powf.c_e.c:244:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_16", (Addr)&temp_var_for_ext_16));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_16;
  }

  /* |y| is huge */
  if (iy > IC(0x4d000000)) { /* if |y| > 2**27 */
    /* over/underflow if x is not close to one */
    if (ix < IC(0x3f7ffff8)) {
      if (hy < 0) {
        feraiseexcept(FE_OVERFLOW);
        float temp_var_for_ext_17;
        float temp_var_for_const_18;
        float temp_var_for_callexp_3;

        temp_var_for_callexp_3 = __builtin_huge_valf();
        temp_var_for_ext_17 = temp_var_for_callexp_3;
        AssignF({(Addr)&temp_var_for_ext_17},
                (Addr) &(temp_var_for_const_18 = temp_var_for_callexp_3),
                "/home/shijia/Public/testprogram/e_powf.c_e.c:258:29");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_17", (Addr)&temp_var_for_ext_17));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_17;
      }
      feraiseexcept(FE_UNDERFLOW);
      float temp_var_for_ext_18;
      float temp_var_for_const_19;
      temp_var_for_ext_18 = 0;
      AssignF({(Addr)&temp_var_for_ext_18}, (Addr) &(temp_var_for_const_19 = 0),
              "/home/shijia/Public/testprogram/e_powf.c_e.c:266:27");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_18", (Addr)&temp_var_for_ext_18));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_18;
    }
    if (ix > IC(0x3f800007)) {
      if (hy > 0) {
        feraiseexcept(FE_OVERFLOW);
        float temp_var_for_ext_19;
        float temp_var_for_const_20;
        float temp_var_for_callexp_4;

        temp_var_for_callexp_4 = __builtin_huge_valf();
        temp_var_for_ext_19 = temp_var_for_callexp_4;
        AssignF({(Addr)&temp_var_for_ext_19},
                (Addr) &(temp_var_for_const_20 = temp_var_for_callexp_4),
                "/home/shijia/Public/testprogram/e_powf.c_e.c:276:29");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_19", (Addr)&temp_var_for_ext_19));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_19;
      }
      feraiseexcept(FE_UNDERFLOW);
      float temp_var_for_ext_20;
      float temp_var_for_const_21;
      temp_var_for_ext_20 = 0;
      AssignF({(Addr)&temp_var_for_ext_20}, (Addr) &(temp_var_for_const_21 = 0),
              "/home/shijia/Public/testprogram/e_powf.c_e.c:284:27");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_20", (Addr)&temp_var_for_ext_20));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_20;
    }
    /* now |1-x| is tiny <= 2**-20, suffice to compute
       log(x) by x-x^2/2+x^3/3-x^4/4 */
    float temp_var_for_tac_16;
    float temp_var_for_const_22;
    temp_var_for_tac_16 = ax - 1;

    t = temp_var_for_tac_16;
    computeFSub((Addr)&temp_var_for_tac_16,
                {(Addr)&ax, (Addr) &(temp_var_for_const_22 = 1)},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:292:12");
    AssignF({(Addr)&t}, (Addr)&temp_var_for_tac_16,
            "/home/shijia/Public/testprogram/e_powf.c_e.c:292:7");
    ; /* t has 20 trailing zeros */
    float temp_var_for_tac_17, temp_var_for_tac_18, temp_var_for_tac_19,
        temp_var_for_tac_20, temp_var_for_tac_21, temp_var_for_tac_22;
    float temp_var_for_const_23, temp_var_for_const_24, temp_var_for_const_25;
    temp_var_for_tac_17 = t * t;

    temp_var_for_tac_18 = t * ((float)0.25);

    temp_var_for_tac_19 = ((float)0.333333333333) - temp_var_for_tac_18;

    temp_var_for_tac_20 = t * temp_var_for_tac_19;

    temp_var_for_tac_21 = ((float)0.5) - temp_var_for_tac_20;

    temp_var_for_tac_22 = temp_var_for_tac_17 * temp_var_for_tac_21;

    w = temp_var_for_tac_22;
    computeFMul((Addr)&temp_var_for_tac_17, {(Addr)&t, (Addr)&t},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:293:12");
    computeFMul((Addr)&temp_var_for_tac_18,
                {(Addr)&t, (Addr) &(temp_var_for_const_23 = ((float)0.25))},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:293:64");
    computeFSub((Addr)&temp_var_for_tac_19,
                {(Addr) &(temp_var_for_const_24 = ((float)0.333333333333)),
                 (Addr)&temp_var_for_tac_18},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:293:60");
    computeFMul((Addr)&temp_var_for_tac_20,
                {(Addr)&t, (Addr)&temp_var_for_tac_19},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:293:35");
    computeFSub((Addr)&temp_var_for_tac_21,
                {(Addr) &(temp_var_for_const_25 = ((float)0.5)),
                 (Addr)&temp_var_for_tac_20},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:293:31");
    computeFMul((Addr)&temp_var_for_tac_22,
                {(Addr)&temp_var_for_tac_17, (Addr)&temp_var_for_tac_21},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:293:17");
    AssignF({(Addr)&w}, (Addr)&temp_var_for_tac_22,
            "/home/shijia/Public/testprogram/e_powf.c_e.c:293:7");
    ;
    float temp_var_for_tac_23;
    float temp_var_for_const_26;
    temp_var_for_tac_23 = ivln2_h * t;

    u = temp_var_for_tac_23;
    computeFMul((Addr)&temp_var_for_tac_23,
                {(Addr) &(temp_var_for_const_26 = ivln2_h), (Addr)&t},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:294:17");
    AssignF({(Addr)&u}, (Addr)&temp_var_for_tac_23,
            "/home/shijia/Public/testprogram/e_powf.c_e.c:294:7");
    ; /* ivln2_h has 16 sig. bits */
    float temp_var_for_tac_24, temp_var_for_tac_25, temp_var_for_tac_26;
    float temp_var_for_const_27, temp_var_for_const_28;
    temp_var_for_tac_24 = t * ivln2_l;

    temp_var_for_tac_25 = w * ivln2;

    temp_var_for_tac_26 = temp_var_for_tac_24 - temp_var_for_tac_25;

    v = temp_var_for_tac_26;
    computeFMul((Addr)&temp_var_for_tac_24,
                {(Addr)&t, (Addr) &(temp_var_for_const_27 = ivln2_l)},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:295:11");
    computeFMul((Addr)&temp_var_for_tac_25,
                {(Addr)&w, (Addr) &(temp_var_for_const_28 = ivln2)},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:295:25");
    computeFSub((Addr)&temp_var_for_tac_26,
                {(Addr)&temp_var_for_tac_24, (Addr)&temp_var_for_tac_25},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:295:21");
    AssignF({(Addr)&v}, (Addr)&temp_var_for_tac_26,
            "/home/shijia/Public/testprogram/e_powf.c_e.c:295:7");
    ;
    float temp_var_for_tac_27;
    temp_var_for_tac_27 = u + v;

    t1 = temp_var_for_tac_27;
    computeFAdd((Addr)&temp_var_for_tac_27, {(Addr)&u, (Addr)&v},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:296:12");
    AssignF({(Addr)&t1}, (Addr)&temp_var_for_tac_27,
            "/home/shijia/Public/testprogram/e_powf.c_e.c:296:8");
    ;
    GET_FLOAT_WORD(is, t1);
    SET_FLOAT_WORD(t1, is & UC(0xfffff000));
    float temp_var_for_tac_28, temp_var_for_tac_29;
    temp_var_for_tac_28 = t1 - u;

    temp_var_for_tac_29 = v - temp_var_for_tac_28;

    t2 = temp_var_for_tac_29;
    computeFSub((Addr)&temp_var_for_tac_28, {(Addr)&t1, (Addr)&u},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:299:18");
    computeFSub((Addr)&temp_var_for_tac_29,
                {(Addr)&v, (Addr)&temp_var_for_tac_28},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:299:12");
    AssignF({(Addr)&t2}, (Addr)&temp_var_for_tac_29,
            "/home/shijia/Public/testprogram/e_powf.c_e.c:299:8");
    ;
  } else {
    float s2, s_h, s_l, t_h, t_l;

    /* Avoid internal underflow for tiny y.  The exact value
       of y does not matter if |y| <= 2**-32.  */
    if (iy < IC(0x2f800000)) {
      SET_FLOAT_WORD(y, (hy & UC(0x80000000)) | UC(0x2f800000));
    }
    n = 0;
    /* take care subnormal number */
    if (FLT_UWORD_IS_SUBNORMAL(ix)) {
      ax *= two24;
      ;
      n -= 24;
      GET_FLOAT_WORD(ix, ax);
    }
    n += ((ix) >> 23) - 0x7f;
    j = ix & IC(0x007fffff);
    /* determine interval */
    ix = j | IC(0x3f800000); /* normalize ix */
    if (j <= IC(0x1cc471)) {
      k = 0;
    }
    /* |x|<sqrt(3/2) */
    else {
      if (j < IC(0x5db3d7)) {
        k = 1;
      }
      /* |x|<sqrt(3)   */
      else {
        k = 0;
        n += 1;
        ix -= IC(0x00800000);
      }
    }

    SET_FLOAT_WORD(ax, ix);

    /* compute s = s_h+s_l = (x-1)/(x+1) or (x-1.5)/(x+1.5) */
    float temp_var_for_ext_21;
    float temp_var_for_tac_31;
    float temp_var_for_const_29;
    temp_var_for_tac_31 = ax - bp[k];

    temp_var_for_ext_21 = temp_var_for_tac_31;
    computeFSub((Addr)&temp_var_for_tac_31,
                {(Addr)&ax, (Addr) &(temp_var_for_const_29 = bp[k])},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:339:30");
    AssignF({(Addr)&temp_var_for_ext_21}, (Addr)&temp_var_for_tac_31,
            "/home/shijia/Public/testprogram/e_powf.c_e.c:339:25");
    ; // u
    /*(u)(t1)(v)(u)(t1)(two24)(ax)(bp)(k)(bp[k])(ax)*/
    u = temp_var_for_ext_21;
    AssignF({(Addr)&u}, (Addr)&temp_var_for_ext_21,
            "/home/shijia/Public/testprogram/e_powf.c_e.c:341:7");
    ; /* bp[0]=1.0, bp[1]=1.5 */
    float temp_var_for_tac_32, temp_var_for_tac_33;
    float temp_var_for_const_30, temp_var_for_const_31;
    temp_var_for_tac_32 = ax + bp[k];

    temp_var_for_tac_33 = one / temp_var_for_tac_32;

    v = temp_var_for_tac_33;
    computeFAdd((Addr)&temp_var_for_tac_32,
                {(Addr)&ax, (Addr) &(temp_var_for_const_30 = bp[k])},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:342:19");
    computeFDiv(
        (Addr)&temp_var_for_tac_33,
        {(Addr) &(temp_var_for_const_31 = one), (Addr)&temp_var_for_tac_32},
        "/home/shijia/Public/testprogram/e_powf.c_e.c:342:13");
    AssignF({(Addr)&v}, (Addr)&temp_var_for_tac_33,
            "/home/shijia/Public/testprogram/e_powf.c_e.c:342:7");
    ;
    float temp_var_for_tac_34;
    temp_var_for_tac_34 = u * v;

    s = temp_var_for_tac_34;
    computeFMul((Addr)&temp_var_for_tac_34, {(Addr)&u, (Addr)&v},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:343:11");
    AssignF({(Addr)&s}, (Addr)&temp_var_for_tac_34,
            "/home/shijia/Public/testprogram/e_powf.c_e.c:343:7");
    ;
    s_h = s;
    AssignF({(Addr)&s_h}, (Addr)&s,
            "/home/shijia/Public/testprogram/e_powf.c_e.c:344:9");
    ;
    GET_FLOAT_WORD(is, s_h);
    SET_FLOAT_WORD(s_h, is & UC(0xfffff000));
    /* t_h=ax+bp[k] High */
    SET_FLOAT_WORD(t_h,
                   ((ix >> 1) | IC(0x20000000)) + IC(0x0040000) + (k << 21));
    float temp_var_for_tac_35, temp_var_for_tac_36;
    float temp_var_for_const_32;
    temp_var_for_tac_35 = t_h - bp[k];

    temp_var_for_tac_36 = ax - temp_var_for_tac_35;

    t_l = temp_var_for_tac_36;
    computeFSub((Addr)&temp_var_for_tac_35,
                {(Addr)&t_h, (Addr) &(temp_var_for_const_32 = bp[k])},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:350:21");
    computeFSub((Addr)&temp_var_for_tac_36,
                {(Addr)&ax, (Addr)&temp_var_for_tac_35},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:350:14");
    AssignF({(Addr)&t_l}, (Addr)&temp_var_for_tac_36,
            "/home/shijia/Public/testprogram/e_powf.c_e.c:350:9");
    ;
    float temp_var_for_tac_37, temp_var_for_tac_38, temp_var_for_tac_39,
        temp_var_for_tac_40, temp_var_for_tac_41;
    temp_var_for_tac_37 = s_h * t_h;

    temp_var_for_tac_38 = u - temp_var_for_tac_37;

    temp_var_for_tac_39 = s_h * t_l;

    temp_var_for_tac_40 = temp_var_for_tac_38 - temp_var_for_tac_39;

    temp_var_for_tac_41 = v * temp_var_for_tac_40;

    s_l = temp_var_for_tac_41;
    computeFMul((Addr)&temp_var_for_tac_37, {(Addr)&s_h, (Addr)&t_h},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:351:25");
    computeFSub((Addr)&temp_var_for_tac_38,
                {(Addr)&u, (Addr)&temp_var_for_tac_37},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:351:19");
    computeFMul((Addr)&temp_var_for_tac_39, {(Addr)&s_h, (Addr)&t_l},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:351:38");
    computeFSub((Addr)&temp_var_for_tac_40,
                {(Addr)&temp_var_for_tac_38, (Addr)&temp_var_for_tac_39},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:351:32");
    computeFMul((Addr)&temp_var_for_tac_41,
                {(Addr)&v, (Addr)&temp_var_for_tac_40},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:351:13");
    AssignF({(Addr)&s_l}, (Addr)&temp_var_for_tac_41,
            "/home/shijia/Public/testprogram/e_powf.c_e.c:351:9");
    ;
    /* compute log(ax) */
    float temp_var_for_tac_42;
    temp_var_for_tac_42 = s * s;

    s2 = temp_var_for_tac_42;
    computeFMul((Addr)&temp_var_for_tac_42, {(Addr)&s, (Addr)&s},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:353:12");
    AssignF({(Addr)&s2}, (Addr)&temp_var_for_tac_42,
            "/home/shijia/Public/testprogram/e_powf.c_e.c:353:8");
    ;
    float temp_var_for_tac_43, temp_var_for_tac_44, temp_var_for_tac_45,
        temp_var_for_tac_46, temp_var_for_tac_47, temp_var_for_tac_48,
        temp_var_for_tac_49, temp_var_for_tac_50, temp_var_for_tac_51,
        temp_var_for_tac_52, temp_var_for_tac_53, temp_var_for_tac_54;
    float temp_var_for_const_33, temp_var_for_const_34, temp_var_for_const_35,
        temp_var_for_const_36, temp_var_for_const_37, temp_var_for_const_38;
    temp_var_for_tac_43 = s2 * s2;

    temp_var_for_tac_44 = s2 * L6;

    temp_var_for_tac_45 = L5 + temp_var_for_tac_44;

    temp_var_for_tac_46 = s2 * temp_var_for_tac_45;

    temp_var_for_tac_47 = L4 + temp_var_for_tac_46;

    temp_var_for_tac_48 = s2 * temp_var_for_tac_47;

    temp_var_for_tac_49 = L3 + temp_var_for_tac_48;

    temp_var_for_tac_50 = s2 * temp_var_for_tac_49;

    temp_var_for_tac_51 = L2 + temp_var_for_tac_50;

    temp_var_for_tac_52 = s2 * temp_var_for_tac_51;

    temp_var_for_tac_53 = L1 + temp_var_for_tac_52;

    temp_var_for_tac_54 = temp_var_for_tac_43 * temp_var_for_tac_53;

    r = temp_var_for_tac_54;
    computeFMul((Addr)&temp_var_for_tac_43, {(Addr)&s2, (Addr)&s2},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:354:12");
    computeFMul((Addr)&temp_var_for_tac_44,
                {(Addr)&s2, (Addr) &(temp_var_for_const_33 = L6)},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:355:62");
    computeFAdd(
        (Addr)&temp_var_for_tac_45,
        {(Addr) &(temp_var_for_const_34 = L5), (Addr)&temp_var_for_tac_44},
        "/home/shijia/Public/testprogram/e_powf.c_e.c:355:57");
    computeFMul((Addr)&temp_var_for_tac_46,
                {(Addr)&s2, (Addr)&temp_var_for_tac_45},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:355:51");
    computeFAdd(
        (Addr)&temp_var_for_tac_47,
        {(Addr) &(temp_var_for_const_35 = L4), (Addr)&temp_var_for_tac_46},
        "/home/shijia/Public/testprogram/e_powf.c_e.c:355:46");
    computeFMul((Addr)&temp_var_for_tac_48,
                {(Addr)&s2, (Addr)&temp_var_for_tac_47},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:355:40");
    computeFAdd(
        (Addr)&temp_var_for_tac_49,
        {(Addr) &(temp_var_for_const_36 = L3), (Addr)&temp_var_for_tac_48},
        "/home/shijia/Public/testprogram/e_powf.c_e.c:355:35");
    computeFMul((Addr)&temp_var_for_tac_50,
                {(Addr)&s2, (Addr)&temp_var_for_tac_49},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:355:29");
    computeFAdd(
        (Addr)&temp_var_for_tac_51,
        {(Addr) &(temp_var_for_const_37 = L2), (Addr)&temp_var_for_tac_50},
        "/home/shijia/Public/testprogram/e_powf.c_e.c:355:24");
    computeFMul((Addr)&temp_var_for_tac_52,
                {(Addr)&s2, (Addr)&temp_var_for_tac_51},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:355:18");
    computeFAdd(
        (Addr)&temp_var_for_tac_53,
        {(Addr) &(temp_var_for_const_38 = L1), (Addr)&temp_var_for_tac_52},
        "/home/shijia/Public/testprogram/e_powf.c_e.c:355:13");
    computeFMul((Addr)&temp_var_for_tac_54,
                {(Addr)&temp_var_for_tac_43, (Addr)&temp_var_for_tac_53},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:354:17");
    AssignF({(Addr)&r}, (Addr)&temp_var_for_tac_54,
            "/home/shijia/Public/testprogram/e_powf.c_e.c:354:7");
    ;
    float temp_var_for_tac_55, temp_var_for_tac_56;
    temp_var_for_tac_55 = s_h + s;

    temp_var_for_tac_56 = s_l * temp_var_for_tac_55;

    r += temp_var_for_tac_56;
    ;
    float temp_var_for_ext_22;
    float temp_var_for_tac_58;
    temp_var_for_tac_58 = s_h * s_h;

    temp_var_for_ext_22 = temp_var_for_tac_58;
    computeFAdd((Addr)&temp_var_for_tac_55, {(Addr)&s_h, (Addr)&s},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:356:21");
    computeFMul((Addr)&temp_var_for_tac_56,
                {(Addr)&s_l, (Addr)&temp_var_for_tac_55},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:356:14");
    computeFMul((Addr)&temp_var_for_tac_58, {(Addr)&s_h, (Addr)&s_h},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:358:31");
    AssignF({(Addr)&temp_var_for_ext_22}, (Addr)&temp_var_for_tac_58,
            "/home/shijia/Public/testprogram/e_powf.c_e.c:358:25");
    ; // s2
    /*(L6)(s2)(L5)(s2)(L4)(s2)(L3)(s2)(L2)(s2)(L1)(s2)(s2)(s2)(s2)(L6)(s2)(L5)(s2)(L4)(s2)(L3)(s2)(L2)(s2)(L1)(L6)(s2)(L5)(s2)(L4)(s2)(L3)(s2)(L2)(s2)(L6)(s2)(L5)(s2)(L4)(s2)(L3)(s2)(L2)(L6)(s2)(L5)(s2)(L4)(s2)(L3)(s2)(L6)(s2)(L5)(s2)(L4)(s2)(L3)(L6)(s2)(L5)(s2)(L4)(s2)(L6)(s2)(L5)(s2)(L4)(L6)(s2)(L5)(s2)(L6)(s2)(L5)(L6)(s2)(s)(s_h)(s_l)(r)(s)(s_h)(s_l)(s)(s_h)(s_h)(s_h)*/
    s2 = temp_var_for_ext_22;
    AssignF({(Addr)&s2}, (Addr)&temp_var_for_ext_22,
            "/home/shijia/Public/testprogram/e_powf.c_e.c:360:8");
    ;
    float temp_var_for_tac_59, temp_var_for_tac_60;
    float temp_var_for_const_39;
    temp_var_for_tac_59 = 3.0f + s2;

    temp_var_for_tac_60 = temp_var_for_tac_59 + r;

    t_h = temp_var_for_tac_60;
    computeFAdd((Addr)&temp_var_for_tac_59,
                {(Addr) &(temp_var_for_const_39 = 3.0f), (Addr)&s2},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:361:16");
    computeFAdd((Addr)&temp_var_for_tac_60,
                {(Addr)&temp_var_for_tac_59, (Addr)&r},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:361:21");
    AssignF({(Addr)&t_h}, (Addr)&temp_var_for_tac_60,
            "/home/shijia/Public/testprogram/e_powf.c_e.c:361:9");
    ;
    GET_FLOAT_WORD(is, t_h);
    SET_FLOAT_WORD(t_h, is & UC(0xfffff000));
    float temp_var_for_tac_61, temp_var_for_tac_62, temp_var_for_tac_63;
    float temp_var_for_const_40;
    temp_var_for_tac_61 = t_h - 3.0f;

    temp_var_for_tac_62 = temp_var_for_tac_61 - s2;

    temp_var_for_tac_63 = r - temp_var_for_tac_62;

    t_l = temp_var_for_tac_63;
    computeFSub((Addr)&temp_var_for_tac_61,
                {(Addr)&t_h, (Addr) &(temp_var_for_const_40 = 3.0f)},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:364:21");
    computeFSub((Addr)&temp_var_for_tac_62,
                {(Addr)&temp_var_for_tac_61, (Addr)&s2},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:364:29");
    computeFSub((Addr)&temp_var_for_tac_63,
                {(Addr)&r, (Addr)&temp_var_for_tac_62},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:364:13");
    AssignF({(Addr)&t_l}, (Addr)&temp_var_for_tac_63,
            "/home/shijia/Public/testprogram/e_powf.c_e.c:364:9");
    ;
    /* u+v = s*(1+...) */
    float temp_var_for_tac_64;
    temp_var_for_tac_64 = s_h * t_h;

    u = temp_var_for_tac_64;
    computeFMul((Addr)&temp_var_for_tac_64, {(Addr)&s_h, (Addr)&t_h},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:366:13");
    AssignF({(Addr)&u}, (Addr)&temp_var_for_tac_64,
            "/home/shijia/Public/testprogram/e_powf.c_e.c:366:7");
    ;
    float temp_var_for_tac_65, temp_var_for_tac_66, temp_var_for_tac_67;
    temp_var_for_tac_65 = s_l * t_h;

    temp_var_for_tac_66 = t_l * s;

    temp_var_for_tac_67 = temp_var_for_tac_65 + temp_var_for_tac_66;

    v = temp_var_for_tac_67;
    computeFMul((Addr)&temp_var_for_tac_65, {(Addr)&s_l, (Addr)&t_h},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:367:13");
    computeFMul((Addr)&temp_var_for_tac_66, {(Addr)&t_l, (Addr)&s},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:367:25");
    computeFAdd((Addr)&temp_var_for_tac_67,
                {(Addr)&temp_var_for_tac_65, (Addr)&temp_var_for_tac_66},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:367:19");
    AssignF({(Addr)&v}, (Addr)&temp_var_for_tac_67,
            "/home/shijia/Public/testprogram/e_powf.c_e.c:367:7");
    ;
    /* 2/(3log2)*(s+...) */
    float temp_var_for_tac_68;
    temp_var_for_tac_68 = u + v;

    p_h = temp_var_for_tac_68;
    computeFAdd((Addr)&temp_var_for_tac_68, {(Addr)&u, (Addr)&v},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:369:13");
    AssignF({(Addr)&p_h}, (Addr)&temp_var_for_tac_68,
            "/home/shijia/Public/testprogram/e_powf.c_e.c:369:9");
    ;
    GET_FLOAT_WORD(is, p_h);
    SET_FLOAT_WORD(p_h, is & UC(0xfffff000));
    float temp_var_for_tac_69, temp_var_for_tac_70;
    temp_var_for_tac_69 = p_h - u;

    temp_var_for_tac_70 = v - temp_var_for_tac_69;

    p_l = temp_var_for_tac_70;
    computeFSub((Addr)&temp_var_for_tac_69, {(Addr)&p_h, (Addr)&u},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:372:20");
    computeFSub((Addr)&temp_var_for_tac_70,
                {(Addr)&v, (Addr)&temp_var_for_tac_69},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:372:13");
    AssignF({(Addr)&p_l}, (Addr)&temp_var_for_tac_70,
            "/home/shijia/Public/testprogram/e_powf.c_e.c:372:9");
    ;
    float temp_var_for_tac_71;
    float temp_var_for_const_41;
    temp_var_for_tac_71 = cp_h * p_h;

    z_h = temp_var_for_tac_71;
    computeFMul((Addr)&temp_var_for_tac_71,
                {(Addr) &(temp_var_for_const_41 = cp_h), (Addr)&p_h},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:373:16");
    AssignF({(Addr)&z_h}, (Addr)&temp_var_for_tac_71,
            "/home/shijia/Public/testprogram/e_powf.c_e.c:373:9");
    ; /* cp_h+cp_l = 2/(3*log2) */
    float temp_var_for_tac_72, temp_var_for_tac_73, temp_var_for_tac_74,
        temp_var_for_tac_75;
    float temp_var_for_const_42, temp_var_for_const_43, temp_var_for_const_44;
    temp_var_for_tac_72 = cp_l * p_h;

    temp_var_for_tac_73 = p_l * cp;

    temp_var_for_tac_74 = temp_var_for_tac_72 + temp_var_for_tac_73;

    temp_var_for_tac_75 = temp_var_for_tac_74 + dp_l[k];

    z_l = temp_var_for_tac_75;
    computeFMul((Addr)&temp_var_for_tac_72,
                {(Addr) &(temp_var_for_const_42 = cp_l), (Addr)&p_h},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:374:16");
    computeFMul((Addr)&temp_var_for_tac_73,
                {(Addr)&p_l, (Addr) &(temp_var_for_const_43 = cp)},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:374:28");
    computeFAdd((Addr)&temp_var_for_tac_74,
                {(Addr)&temp_var_for_tac_72, (Addr)&temp_var_for_tac_73},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:374:22");
    computeFAdd(
        (Addr)&temp_var_for_tac_75,
        {(Addr)&temp_var_for_tac_74, (Addr) &(temp_var_for_const_44 = dp_l[k])},
        "/home/shijia/Public/testprogram/e_powf.c_e.c:374:33");
    AssignF({(Addr)&z_l}, (Addr)&temp_var_for_tac_75,
            "/home/shijia/Public/testprogram/e_powf.c_e.c:374:9");
    ;
    /* log2(ax) = (s+..)*2/(3*log2) = n + dp_h + z_h + z_l */
    float temp_var_for_const_45;
    t = ((float)n);
    AssignF({(Addr)&t}, (Addr) &(temp_var_for_const_45 = ((float)n)),
            "/home/shijia/Public/testprogram/e_powf.c_e.c:376:7");
    ;
    float temp_var_for_tac_76, temp_var_for_tac_77, temp_var_for_tac_78;
    float temp_var_for_const_46;
    temp_var_for_tac_76 = z_h + z_l;

    temp_var_for_tac_77 = temp_var_for_tac_76 + dp_h[k];

    temp_var_for_tac_78 = temp_var_for_tac_77 + t;

    t1 = temp_var_for_tac_78;
    computeFAdd((Addr)&temp_var_for_tac_76, {(Addr)&z_h, (Addr)&z_l},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:377:17");
    computeFAdd(
        (Addr)&temp_var_for_tac_77,
        {(Addr)&temp_var_for_tac_76, (Addr) &(temp_var_for_const_46 = dp_h[k])},
        "/home/shijia/Public/testprogram/e_powf.c_e.c:377:24");
    computeFAdd((Addr)&temp_var_for_tac_78,
                {(Addr)&temp_var_for_tac_77, (Addr)&t},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:377:35");
    AssignF({(Addr)&t1}, (Addr)&temp_var_for_tac_78,
            "/home/shijia/Public/testprogram/e_powf.c_e.c:377:8");
    ;
    GET_FLOAT_WORD(is, t1);
    SET_FLOAT_WORD(t1, is & UC(0xfffff000));
    float temp_var_for_tac_79, temp_var_for_tac_80, temp_var_for_tac_81,
        temp_var_for_tac_82;
    float temp_var_for_const_47;
    temp_var_for_tac_79 = t1 - t;

    temp_var_for_tac_80 = temp_var_for_tac_79 - dp_h[k];

    temp_var_for_tac_81 = temp_var_for_tac_80 - z_h;

    temp_var_for_tac_82 = z_l - temp_var_for_tac_81;

    t2 = temp_var_for_tac_82;
    computeFSub((Addr)&temp_var_for_tac_79, {(Addr)&t1, (Addr)&t},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:380:22");
    computeFSub(
        (Addr)&temp_var_for_tac_80,
        {(Addr)&temp_var_for_tac_79, (Addr) &(temp_var_for_const_47 = dp_h[k])},
        "/home/shijia/Public/testprogram/e_powf.c_e.c:380:27");
    computeFSub((Addr)&temp_var_for_tac_81,
                {(Addr)&temp_var_for_tac_80, (Addr)&z_h},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:380:38");
    computeFSub((Addr)&temp_var_for_tac_82,
                {(Addr)&z_l, (Addr)&temp_var_for_tac_81},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:380:14");
    AssignF({(Addr)&t2}, (Addr)&temp_var_for_tac_82,
            "/home/shijia/Public/testprogram/e_powf.c_e.c:380:8");
    ;
  }

  float temp_var_for_const_48;
  s = one;
  AssignF({(Addr)&s}, (Addr) &(temp_var_for_const_48 = one),
          "/home/shijia/Public/testprogram/e_powf.c_e.c:383:5");
  ; /* s (sign of result -ve**odd) = -1 else = 1 */
  if (((((uint32_t)hx >> 31) - 1) | (yisint - 1)) == 0) {
    float temp_var_for_tac_83;
    float temp_var_for_const_49, temp_var_for_const_50;
    temp_var_for_tac_83 = 0.0 - one;

    s = temp_var_for_tac_83;
    computeDSub((Addr)&temp_var_for_tac_83,
                {(Addr) &(temp_var_for_const_50 = 0.0),
                 (Addr) &(temp_var_for_const_49 = one)},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:385:14");
    AssignF({(Addr)&s}, (Addr)&temp_var_for_tac_83,
            "/home/shijia/Public/testprogram/e_powf.c_e.c:385:7");
    ;
  }
  /* (-ve)**(odd int) */

  /* split up y into y1+y2 and compute (y1+y2)*(t1+t2) */
  GET_FLOAT_WORD(is, y);
  SET_FLOAT_WORD(y1, is & UC(0xfffff000));
  float temp_var_for_tac_84, temp_var_for_tac_85, temp_var_for_tac_86,
      temp_var_for_tac_87;
  temp_var_for_tac_84 = y - y1;

  temp_var_for_tac_85 = temp_var_for_tac_84 * t1;

  temp_var_for_tac_86 = y * t2;

  temp_var_for_tac_87 = temp_var_for_tac_85 + temp_var_for_tac_86;

  p_l = temp_var_for_tac_87;
  computeFSub((Addr)&temp_var_for_tac_84, {(Addr)&y, (Addr)&y1},
              "/home/shijia/Public/testprogram/e_powf.c_e.c:392:12");
  computeFMul((Addr)&temp_var_for_tac_85,
              {(Addr)&temp_var_for_tac_84, (Addr)&t1},
              "/home/shijia/Public/testprogram/e_powf.c_e.c:392:18");
  computeFMul((Addr)&temp_var_for_tac_86, {(Addr)&y, (Addr)&t2},
              "/home/shijia/Public/testprogram/e_powf.c_e.c:392:27");
  computeFAdd((Addr)&temp_var_for_tac_87,
              {(Addr)&temp_var_for_tac_85, (Addr)&temp_var_for_tac_86},
              "/home/shijia/Public/testprogram/e_powf.c_e.c:392:23");
  AssignF({(Addr)&p_l}, (Addr)&temp_var_for_tac_87,
          "/home/shijia/Public/testprogram/e_powf.c_e.c:392:7");
  ;
  float temp_var_for_tac_88;
  temp_var_for_tac_88 = y1 * t1;

  p_h = temp_var_for_tac_88;
  computeFMul((Addr)&temp_var_for_tac_88, {(Addr)&y1, (Addr)&t1},
              "/home/shijia/Public/testprogram/e_powf.c_e.c:393:12");
  AssignF({(Addr)&p_h}, (Addr)&temp_var_for_tac_88,
          "/home/shijia/Public/testprogram/e_powf.c_e.c:393:7");
  ;
  float temp_var_for_tac_89;
  temp_var_for_tac_89 = p_l + p_h;

  z = temp_var_for_tac_89;
  computeFAdd((Addr)&temp_var_for_tac_89, {(Addr)&p_l, (Addr)&p_h},
              "/home/shijia/Public/testprogram/e_powf.c_e.c:394:11");
  AssignF({(Addr)&z}, (Addr)&temp_var_for_tac_89,
          "/home/shijia/Public/testprogram/e_powf.c_e.c:394:5");
  ;
  GET_FLOAT_WORD(j, z);
  i = j & IC(0x7fffffff);
  if (j > 0) {
    if (i > FLT_UWORD_EXP_MAX) {
      feraiseexcept(FE_OVERFLOW);
      float temp_var_for_ext_23;
      float temp_var_for_const_51;
      float temp_var_for_callexp_5;

      /*embed fun has found*/
      float temp_var_for_callexp_6;

      temp_var_for_callexp_5 = __builtin_huge_valf();
      temp_var_for_callexp_6 = copysignf(temp_var_for_callexp_5, s);
      temp_var_for_ext_23 = temp_var_for_callexp_6;
      AssignF({(Addr)&temp_var_for_ext_23},
              (Addr) &(temp_var_for_const_51 = temp_var_for_callexp_6),
              "/home/shijia/Public/testprogram/e_powf.c_e.c:401:27");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_23", (Addr)&temp_var_for_ext_23));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_23;
    }
    if (i == FLT_UWORD_EXP_MAX) {
      if (int temp_var_for_tac_90, temp_var_for_tac_91, temp_var_for_tac_92;
          int temp_var_for_const_52; temp_var_for_tac_90 = p_l + ovt;

          temp_var_for_tac_91 = z - p_h;

          temp_var_for_tac_92 = temp_var_for_tac_90 > temp_var_for_tac_91;

          ) {
        feraiseexcept(FE_OVERFLOW);
        float temp_var_for_ext_24;
        float temp_var_for_const_53;
        float temp_var_for_callexp_7;

        /*embed fun has found*/
        float temp_var_for_callexp_8;

        temp_var_for_callexp_7 = __builtin_huge_valf();
        temp_var_for_callexp_8 = copysignf(temp_var_for_callexp_7, s);
        temp_var_for_ext_24 = temp_var_for_callexp_8;
        computeFAdd((Addr)&temp_var_for_tac_90,
                    {(Addr)&p_l, (Addr) &(temp_var_for_const_52 = ovt)},
                    "/home/shijia/Public/testprogram/e_powf.c_e.c:408:15");
        computeFSub((Addr)&temp_var_for_tac_91, {(Addr)&z, (Addr)&p_h},
                    "/home/shijia/Public/testprogram/e_powf.c_e.c:408:25");
        compute((Addr)&temp_var_for_tac_92,
                {(Addr)&temp_var_for_tac_90, (Addr)&temp_var_for_tac_91},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:408:21");
        AssignF({(Addr)&temp_var_for_ext_24},
                (Addr) &(temp_var_for_const_53 = temp_var_for_callexp_8),
                "/home/shijia/Public/testprogram/e_powf.c_e.c:411:29");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_24", (Addr)&temp_var_for_ext_24));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_24;
      }
    }

  } else {
    if (i > FLT_UWORD_EXP_MIN) {
      feraiseexcept(FE_UNDERFLOW);
      float temp_var_for_ext_25;
      float temp_var_for_const_54;
      float temp_var_for_callexp_9;

      temp_var_for_callexp_9 = copysignf(0.0f, s);
      temp_var_for_ext_25 = temp_var_for_callexp_9;
      AssignF({(Addr)&temp_var_for_ext_25},
              (Addr) &(temp_var_for_const_54 = temp_var_for_callexp_9),
              "/home/shijia/Public/testprogram/e_powf.c_e.c:423:27");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_25", (Addr)&temp_var_for_ext_25));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_25;
    }
    if (i == FLT_UWORD_EXP_MIN) {
      if (int temp_var_for_tac_93, temp_var_for_tac_94;
          temp_var_for_tac_93 = z - p_h;

          temp_var_for_tac_94 = p_l <= temp_var_for_tac_93;

          ) {
        feraiseexcept(FE_UNDERFLOW);
        float temp_var_for_ext_26;
        float temp_var_for_const_55;
        float temp_var_for_callexp_10;

        temp_var_for_callexp_10 = copysignf(0.0f, s);
        temp_var_for_ext_26 = temp_var_for_callexp_10;
        computeFSub((Addr)&temp_var_for_tac_93, {(Addr)&z, (Addr)&p_h},
                    "/home/shijia/Public/testprogram/e_powf.c_e.c:430:20");
        compute((Addr)&temp_var_for_tac_94,
                {(Addr)&p_l, (Addr)&temp_var_for_tac_93},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:430:15");
        AssignF({(Addr)&temp_var_for_ext_26},
                (Addr) &(temp_var_for_const_55 = temp_var_for_callexp_10),
                "/home/shijia/Public/testprogram/e_powf.c_e.c:433:29");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_26", (Addr)&temp_var_for_ext_26));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_26;
      }
    }
  }
  /*
   * compute 2**(p_h+p_l)
   */
  k = (i >> 23) - 0x7f;

  n = 0;
  if (i > IC(0x3f000000)) { /* if |z| > 0.5, set n = [z+0.5] */
    n = j + (IC(0x00800000) >> (k + 1));
    k = ((n & IC(0x7fffffff)) >> 23) - 0x7f; /* new k for n */
    SET_FLOAT_WORD(t, n & ~(UC(0x007fffff) >> k));
    n = ((n & IC(0x007fffff)) | IC(0x00800000)) >> (23 - k);
    if (j < 0) {
      n = -n;
    }

    p_h -= t;
    ;
  }
  float temp_var_for_ext_27;
  float temp_var_for_tac_96;
  temp_var_for_tac_96 = p_l + p_h;

  temp_var_for_ext_27 = temp_var_for_tac_96;
  computeFAdd((Addr)&temp_var_for_tac_96, {(Addr)&p_l, (Addr)&p_h},
              "/home/shijia/Public/testprogram/e_powf.c_e.c:459:29");
  AssignF({(Addr)&temp_var_for_ext_27}, (Addr)&temp_var_for_tac_96,
          "/home/shijia/Public/testprogram/e_powf.c_e.c:459:23");
  ; // t
  /*(p_h)(p_l)(ovt)(p_l)(p_h)(z)(p_h)(z)(t)(p_h)(p_h)(p_l)*/
  t = temp_var_for_ext_27;
  AssignF({(Addr)&t}, (Addr)&temp_var_for_ext_27,
          "/home/shijia/Public/testprogram/e_powf.c_e.c:461:5");
  ;
  GET_FLOAT_WORD(is, t);
  SET_FLOAT_WORD(t, is & UC(0xfffff000));
  float temp_var_for_tac_97;
  float temp_var_for_const_56;
  temp_var_for_tac_97 = t * lg2_h;

  u = temp_var_for_tac_97;
  computeFMul((Addr)&temp_var_for_tac_97,
              {(Addr)&t, (Addr) &(temp_var_for_const_56 = lg2_h)},
              "/home/shijia/Public/testprogram/e_powf.c_e.c:464:9");
  AssignF({(Addr)&u}, (Addr)&temp_var_for_tac_97,
          "/home/shijia/Public/testprogram/e_powf.c_e.c:464:5");
  ;
  float temp_var_for_tac_98, temp_var_for_tac_99, temp_var_for_tac_100,
      temp_var_for_tac_101, temp_var_for_tac_102;
  float temp_var_for_const_57, temp_var_for_const_58;
  temp_var_for_tac_98 = t - p_h;

  temp_var_for_tac_99 = p_l - temp_var_for_tac_98;

  temp_var_for_tac_100 = temp_var_for_tac_99 * lg2;

  temp_var_for_tac_101 = t * lg2_l;

  temp_var_for_tac_102 = temp_var_for_tac_100 + temp_var_for_tac_101;

  v = temp_var_for_tac_102;
  computeFSub((Addr)&temp_var_for_tac_98, {(Addr)&t, (Addr)&p_h},
              "/home/shijia/Public/testprogram/e_powf.c_e.c:465:17");
  computeFSub((Addr)&temp_var_for_tac_99,
              {(Addr)&p_l, (Addr)&temp_var_for_tac_98},
              "/home/shijia/Public/testprogram/e_powf.c_e.c:465:12");
  computeFMul(
      (Addr)&temp_var_for_tac_100,
      {(Addr)&temp_var_for_tac_99, (Addr) &(temp_var_for_const_57 = lg2)},
      "/home/shijia/Public/testprogram/e_powf.c_e.c:465:25");
  computeFMul((Addr)&temp_var_for_tac_101,
              {(Addr)&t, (Addr) &(temp_var_for_const_58 = lg2_l)},
              "/home/shijia/Public/testprogram/e_powf.c_e.c:465:35");
  computeFAdd((Addr)&temp_var_for_tac_102,
              {(Addr)&temp_var_for_tac_100, (Addr)&temp_var_for_tac_101},
              "/home/shijia/Public/testprogram/e_powf.c_e.c:465:31");
  AssignF({(Addr)&v}, (Addr)&temp_var_for_tac_102,
          "/home/shijia/Public/testprogram/e_powf.c_e.c:465:5");
  ;
  float temp_var_for_tac_103;
  temp_var_for_tac_103 = u + v;

  z = temp_var_for_tac_103;
  computeFAdd((Addr)&temp_var_for_tac_103, {(Addr)&u, (Addr)&v},
              "/home/shijia/Public/testprogram/e_powf.c_e.c:466:9");
  AssignF({(Addr)&z}, (Addr)&temp_var_for_tac_103,
          "/home/shijia/Public/testprogram/e_powf.c_e.c:466:5");
  ;
  float temp_var_for_tac_104, temp_var_for_tac_105;
  temp_var_for_tac_104 = z - u;

  temp_var_for_tac_105 = v - temp_var_for_tac_104;

  w = temp_var_for_tac_105;
  computeFSub((Addr)&temp_var_for_tac_104, {(Addr)&z, (Addr)&u},
              "/home/shijia/Public/testprogram/e_powf.c_e.c:467:14");
  computeFSub((Addr)&temp_var_for_tac_105,
              {(Addr)&v, (Addr)&temp_var_for_tac_104},
              "/home/shijia/Public/testprogram/e_powf.c_e.c:467:9");
  AssignF({(Addr)&w}, (Addr)&temp_var_for_tac_105,
          "/home/shijia/Public/testprogram/e_powf.c_e.c:467:5");
  ;
  float temp_var_for_tac_106;
  temp_var_for_tac_106 = z * z;

  t = temp_var_for_tac_106;
  computeFMul((Addr)&temp_var_for_tac_106, {(Addr)&z, (Addr)&z},
              "/home/shijia/Public/testprogram/e_powf.c_e.c:468:9");
  AssignF({(Addr)&t}, (Addr)&temp_var_for_tac_106,
          "/home/shijia/Public/testprogram/e_powf.c_e.c:468:5");
  ;
  float temp_var_for_tac_107, temp_var_for_tac_108, temp_var_for_tac_109,
      temp_var_for_tac_110, temp_var_for_tac_111, temp_var_for_tac_112,
      temp_var_for_tac_113, temp_var_for_tac_114, temp_var_for_tac_115,
      temp_var_for_tac_116;
  float temp_var_for_const_59, temp_var_for_const_60, temp_var_for_const_61,
      temp_var_for_const_62, temp_var_for_const_63;
  temp_var_for_tac_107 = t * P5;

  temp_var_for_tac_108 = P4 + temp_var_for_tac_107;

  temp_var_for_tac_109 = t * temp_var_for_tac_108;

  temp_var_for_tac_110 = P3 + temp_var_for_tac_109;

  temp_var_for_tac_111 = t * temp_var_for_tac_110;

  temp_var_for_tac_112 = P2 + temp_var_for_tac_111;

  temp_var_for_tac_113 = t * temp_var_for_tac_112;

  temp_var_for_tac_114 = P1 + temp_var_for_tac_113;

  temp_var_for_tac_115 = t * temp_var_for_tac_114;

  temp_var_for_tac_116 = z - temp_var_for_tac_115;

  t1 = temp_var_for_tac_116;
  computeFMul((Addr)&temp_var_for_tac_107,
              {(Addr)&t, (Addr) &(temp_var_for_const_59 = P5)},
              "/home/shijia/Public/testprogram/e_powf.c_e.c:469:54");
  computeFAdd(
      (Addr)&temp_var_for_tac_108,
      {(Addr) &(temp_var_for_const_60 = P4), (Addr)&temp_var_for_tac_107},
      "/home/shijia/Public/testprogram/e_powf.c_e.c:469:50");
  computeFMul((Addr)&temp_var_for_tac_109,
              {(Addr)&t, (Addr)&temp_var_for_tac_108},
              "/home/shijia/Public/testprogram/e_powf.c_e.c:469:44");
  computeFAdd(
      (Addr)&temp_var_for_tac_110,
      {(Addr) &(temp_var_for_const_61 = P3), (Addr)&temp_var_for_tac_109},
      "/home/shijia/Public/testprogram/e_powf.c_e.c:469:40");
  computeFMul((Addr)&temp_var_for_tac_111,
              {(Addr)&t, (Addr)&temp_var_for_tac_110},
              "/home/shijia/Public/testprogram/e_powf.c_e.c:469:34");
  computeFAdd(
      (Addr)&temp_var_for_tac_112,
      {(Addr) &(temp_var_for_const_62 = P2), (Addr)&temp_var_for_tac_111},
      "/home/shijia/Public/testprogram/e_powf.c_e.c:469:30");
  computeFMul((Addr)&temp_var_for_tac_113,
              {(Addr)&t, (Addr)&temp_var_for_tac_112},
              "/home/shijia/Public/testprogram/e_powf.c_e.c:469:24");
  computeFAdd(
      (Addr)&temp_var_for_tac_114,
      {(Addr) &(temp_var_for_const_63 = P1), (Addr)&temp_var_for_tac_113},
      "/home/shijia/Public/testprogram/e_powf.c_e.c:469:20");
  computeFMul((Addr)&temp_var_for_tac_115,
              {(Addr)&t, (Addr)&temp_var_for_tac_114},
              "/home/shijia/Public/testprogram/e_powf.c_e.c:469:14");
  computeFSub((Addr)&temp_var_for_tac_116,
              {(Addr)&z, (Addr)&temp_var_for_tac_115},
              "/home/shijia/Public/testprogram/e_powf.c_e.c:469:10");
  AssignF({(Addr)&t1}, (Addr)&temp_var_for_tac_116,
          "/home/shijia/Public/testprogram/e_powf.c_e.c:469:6");
  ;
  float temp_var_for_tac_117, temp_var_for_tac_118, temp_var_for_tac_119,
      temp_var_for_tac_120, temp_var_for_tac_121, temp_var_for_tac_122;
  float temp_var_for_const_64;
  temp_var_for_tac_117 = z * t1;

  temp_var_for_tac_118 = t1 - two;

  temp_var_for_tac_119 = temp_var_for_tac_117 / temp_var_for_tac_118;

  temp_var_for_tac_120 = z * w;

  temp_var_for_tac_121 = w + temp_var_for_tac_120;

  temp_var_for_tac_122 = temp_var_for_tac_119 - temp_var_for_tac_121;

  r = temp_var_for_tac_122;
  computeFMul((Addr)&temp_var_for_tac_117, {(Addr)&z, (Addr)&t1},
              "/home/shijia/Public/testprogram/e_powf.c_e.c:470:10");
  computeFSub((Addr)&temp_var_for_tac_118,
              {(Addr)&t1, (Addr) &(temp_var_for_const_64 = two)},
              "/home/shijia/Public/testprogram/e_powf.c_e.c:470:22");
  computeFDiv((Addr)&temp_var_for_tac_119,
              {(Addr)&temp_var_for_tac_117, (Addr)&temp_var_for_tac_118},
              "/home/shijia/Public/testprogram/e_powf.c_e.c:470:16");
  computeFMul((Addr)&temp_var_for_tac_120, {(Addr)&z, (Addr)&w},
              "/home/shijia/Public/testprogram/e_powf.c_e.c:470:38");
  computeFAdd((Addr)&temp_var_for_tac_121,
              {(Addr)&w, (Addr)&temp_var_for_tac_120},
              "/home/shijia/Public/testprogram/e_powf.c_e.c:470:34");
  computeFSub((Addr)&temp_var_for_tac_122,
              {(Addr)&temp_var_for_tac_119, (Addr)&temp_var_for_tac_121},
              "/home/shijia/Public/testprogram/e_powf.c_e.c:470:29");
  AssignF({(Addr)&r}, (Addr)&temp_var_for_tac_122,
          "/home/shijia/Public/testprogram/e_powf.c_e.c:470:5");
  ;
  float temp_var_for_ext_28;
  float temp_var_for_tac_123, temp_var_for_tac_124;
  float temp_var_for_const_65;
  temp_var_for_tac_123 = r - z;

  temp_var_for_tac_124 = one - temp_var_for_tac_123;

  temp_var_for_ext_28 = temp_var_for_tac_124;
  computeFSub((Addr)&temp_var_for_tac_123, {(Addr)&r, (Addr)&z},
              "/home/shijia/Public/testprogram/e_powf.c_e.c:472:34");
  computeFSub(
      (Addr)&temp_var_for_tac_124,
      {(Addr) &(temp_var_for_const_65 = one), (Addr)&temp_var_for_tac_123},
      "/home/shijia/Public/testprogram/e_powf.c_e.c:472:29");
  AssignF({(Addr)&temp_var_for_ext_28}, (Addr)&temp_var_for_tac_124,
          "/home/shijia/Public/testprogram/e_powf.c_e.c:472:23");
  ; // z
  /*(w)(z)(w)(two)(t1)(t1)(z)(two)(t1)(t1)(z)(t1)(z)(two)(t1)(w)(z)(w)(w)(z)(z)(r)(one)*/
  z = temp_var_for_ext_28;
  AssignF({(Addr)&z}, (Addr)&temp_var_for_ext_28,
          "/home/shijia/Public/testprogram/e_powf.c_e.c:474:5");
  ;
  GET_FLOAT_WORD(j, z);
  j += (n << 23);
  if ((j >> 23) <= 0) {
    float temp_var_for_ext_29;
    float temp_var_for_const_66;
    float temp_var_for_callexp_11;

    temp_var_for_callexp_11 = __ieee754_scalbnf(z, ((int)n));
    temp_var_for_ext_29 = temp_var_for_callexp_11;
    AssignF({(Addr)&temp_var_for_ext_29},
            (Addr) &(temp_var_for_const_66 = temp_var_for_callexp_11),
            "/home/shijia/Public/testprogram/e_powf.c_e.c:479:25");
    ; // z
    /*(z)(r)(one)(z)(r)(__ieee754_scalbnf(z, (int)n))*/
    z = temp_var_for_ext_29;
    AssignF({(Addr)&z}, (Addr)&temp_var_for_ext_29,
            "/home/shijia/Public/testprogram/e_powf.c_e.c:481:7");
    ; /* subnormal output */
  } else {
    SET_FLOAT_WORD(z, j);
  }
  float temp_var_for_ext_30;
  float temp_var_for_tac_125;
  temp_var_for_tac_125 = s * z;

  temp_var_for_ext_30 = temp_var_for_tac_125;
  computeFMul((Addr)&temp_var_for_tac_125, {(Addr)&s, (Addr)&z},
              "/home/shijia/Public/testprogram/e_powf.c_e.c:486:27");
  AssignF({(Addr)&temp_var_for_ext_30}, (Addr)&temp_var_for_tac_125,
          "/home/shijia/Public/testprogram/e_powf.c_e.c:486:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_30", (Addr)&temp_var_for_ext_30));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_30;
}

#endif

/* wrapper powf */
float __powf(float x, float y) {
  float z = __ieee754_powf(x, y);

  if (!isfinite(z)) {
    if (_LIB_VERSION != _IEEE_) {
      if (isnan(x)) {
        if (int temp_var_for_tac_126; int temp_var_for_const_67;
            temp_var_for_tac_126 = y == 0.0f;

            )
        /* pow(NaN,0.0) */
        {
          float temp_var_for_ext_31;
          float temp_var_for_const_68;
          float temp_var_for_callexp_12;

          temp_var_for_callexp_12 =
              __kernel_standard_f(x, y, z, KMATHERRF_POW_NAN);
          temp_var_for_ext_31 = temp_var_for_callexp_12;
          compute((Addr)&temp_var_for_tac_126,
                  {(Addr)&y, (Addr) &(temp_var_for_const_67 = 0.0f)},
                  "/home/shijia/Public/testprogram/e_powf.c_e.c:501:15");
          AssignF({(Addr)&temp_var_for_ext_31},
                  (Addr) &(temp_var_for_const_68 = temp_var_for_callexp_12),
                  "/home/shijia/Public/testprogram/e_powf.c_e.c:505:31");
          ;
          callExpStack.push(
              getReal("temp_var_for_ext_31", (Addr)&temp_var_for_ext_31));
          callExp++; /*identify the function is  add move tmpShadow*/
          return temp_var_for_ext_31;
        }

      } else {
        if (isfinite(x) && isfinite(y)) {
          if (isnan(z)) {
            /* pow neg**non-int */
            float temp_var_for_ext_32;
            float temp_var_for_const_69;
            float temp_var_for_callexp_13;

            temp_var_for_callexp_13 =
                __kernel_standard_f(x, y, z, KMATHERRF_POW_NONINT);
            temp_var_for_ext_32 = temp_var_for_callexp_13;
            AssignF({(Addr)&temp_var_for_ext_32},
                    (Addr) &(temp_var_for_const_69 = temp_var_for_callexp_13),
                    "/home/shijia/Public/testprogram/e_powf.c_e.c:517:33");
            ;
            callExpStack.push(
                getReal("temp_var_for_ext_32", (Addr)&temp_var_for_ext_32));
            callExp++; /*identify the function is  add move tmpShadow*/
            return temp_var_for_ext_32;
          } else {
            if (int temp_var_for_tac_127; int temp_var_for_const_70;
                temp_var_for_tac_127 = x == 0.0f;

                &&int temp_var_for_tac_128; int temp_var_for_const_71;
                temp_var_for_tac_128 = y < 0.0f;

                ) {
              if (signbit(x) && signbit(z))
              /* pow(-0.0,negative) */
              {
                float temp_var_for_ext_33;
                float temp_var_for_const_72;
                float temp_var_for_callexp_14;

                temp_var_for_callexp_14 =
                    __kernel_standard_f(x, y, z, KMATHERRF_POW_MINUS);
                temp_var_for_ext_33 = temp_var_for_callexp_14;
                compute((Addr)&temp_var_for_tac_127,
                        {(Addr)&x, (Addr) &(temp_var_for_const_70 = 0.0f)},
                        "/home/shijia/Public/testprogram/e_powf.c_e.c:524:19");
                compute((Addr)&temp_var_for_tac_128,
                        {(Addr)&y, (Addr) &(temp_var_for_const_71 = 0.0f)},
                        "/home/shijia/Public/testprogram/e_powf.c_e.c:524:32");
                AssignF(
                    {(Addr)&temp_var_for_ext_33},
                    (Addr) &(temp_var_for_const_72 = temp_var_for_callexp_14),
                    "/home/shijia/Public/testprogram/e_powf.c_e.c:529:37");
                ;
                callExpStack.push(
                    getReal("temp_var_for_ext_33", (Addr)&temp_var_for_ext_33));
                callExp++; /*identify the function is  add move tmpShadow*/
                return temp_var_for_ext_33;
              }

              else
              /* pow(+0.0,negative) */
              {
                float temp_var_for_ext_34;
                float temp_var_for_const_73;
                float temp_var_for_callexp_15;

                temp_var_for_callexp_15 =
                    __kernel_standard_f(x, y, z, KMATHERRF_POW_ZEROMINUS);
                temp_var_for_ext_34 = temp_var_for_callexp_15;
                AssignF(
                    {(Addr)&temp_var_for_ext_34},
                    (Addr) &(temp_var_for_const_73 = temp_var_for_callexp_15),
                    "/home/shijia/Public/testprogram/e_powf.c_e.c:541:37");
                ;
                callExpStack.push(
                    getReal("temp_var_for_ext_34", (Addr)&temp_var_for_ext_34));
                callExp++; /*identify the function is  add move tmpShadow*/
                return temp_var_for_ext_34;
              }

            } else {
              /* pow overflow */
              float temp_var_for_ext_35;
              float temp_var_for_const_74;
              float temp_var_for_callexp_16;

              temp_var_for_callexp_16 =
                  __kernel_standard_f(x, y, z, KMATHERRF_POW_OVERFLOW);
              temp_var_for_ext_35 = temp_var_for_callexp_16;
              AssignF({(Addr)&temp_var_for_ext_35},
                      (Addr) &(temp_var_for_const_74 = temp_var_for_callexp_16),
                      "/home/shijia/Public/testprogram/e_powf.c_e.c:552:35");
              ;
              callExpStack.push(
                  getReal("temp_var_for_ext_35", (Addr)&temp_var_for_ext_35));
              callExp++; /*identify the function is  add move tmpShadow*/
              return temp_var_for_ext_35;
            }
          }
        }
      }
    }
  } else {
    if
  }
  (z == 0.0f && isfinite(x) && isfinite(y) && _LIB_VERSION != _IEEE_) {
    if (x == 0.0f) {
      if (y == 0.0f)
        /* pow(0.0,0.0) */
        return __kernel_standard_f(x, y, z, KMATHERRF_POW_ZERO);
    } else {
      /* pow underflow */
      return __kernel_standard_f(x, y, z, KMATHERRF_POW_UNDERFLOW);
    }
  }

  return z;
}

__typeof(__powf) powf __attribute__((weak, alias("__powf")));
