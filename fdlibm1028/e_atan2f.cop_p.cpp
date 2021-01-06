#include "../ScDebug/scdebug.h"
/* e_atan2f.c -- float version of e_atan2.c.
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

#ifndef __have_fpu_atan2

float __ieee754_atan2f(float y, float x) {
  float z;
  int32_t k, m, hx, hy, ix, iy;

  static const float tiny = 1.0e-30;
  static const float zero = 0.0;
  static const float pi_o_4 = 7.8539818525e-01; /* 0x3f490fdb */
  static const float pi_o_2 = 1.5707963705e+00; /* 0x3fc90fdb */
  static const float pi = 3.1415927410e+00;     /* 0x40490fdb */
  static const float pi_lo = (double temp_var_for_tac_0;
                              double temp_var_for_const_0, temp_var_for_const_1;
                              temp_var_for_tac_0 = 0.0 - 8.7422776573e-08;

                              ); /* 0xb3bbbd2e */

  GET_FLOAT_WORD(hx, x);
  ix = hx & IC(0x7fffffff);
  GET_FLOAT_WORD(hy, y);
  iy = hy & IC(0x7fffffff);
  if (FLT_UWORD_IS_NAN(ix) || FLT_UWORD_IS_NAN(iy)) /* x or y is NaN */
  {
    float temp_var_for_ext_0;
    float temp_var_for_tac_1;
    temp_var_for_tac_1 = x + y;

    temp_var_for_ext_0 = temp_var_for_tac_1;
    computeDSub((Addr)&temp_var_for_tac_0,
                {(Addr) &(temp_var_for_const_1 = 0.0),
                 (Addr) &(temp_var_for_const_0 = 8.7422776573e-08)},
                "/home/shijia/Public/testprogram/e_atan2f.c_e.c:31:35");
    computeFAdd((Addr)&temp_var_for_tac_1, {(Addr)&x, (Addr)&y},
                "/home/shijia/Public/testprogram/e_atan2f.c_e.c:40:28");
    AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_1,
            "/home/shijia/Public/testprogram/e_atan2f.c_e.c:40:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  if (hx == IC(0x3f800000)) {
    float temp_var_for_ext_1;
    float temp_var_for_const_2;
    float temp_var_for_callexp_0;

    temp_var_for_callexp_0 = __ieee754_atanf(y);
    temp_var_for_ext_1 = temp_var_for_callexp_0;
    AssignF({(Addr)&temp_var_for_ext_1},
            (Addr) &(temp_var_for_const_2 = temp_var_for_callexp_0),
            "/home/shijia/Public/testprogram/e_atan2f.c_e.c:48:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }
  /* x=1.0 */
  m = ((hy >> 31) & 1) | ((hx >> 30) & 2); /* 2*sign(x)+sign(y) */

  /* when y = 0 */
  if (FLT_UWORD_IS_ZERO(iy)) {
    int temp_var_for_ext_2;
    temp_var_for_ext_2 = (int)m;
    switch (temp_var_for_ext_2) {
    case 0: {
    case 1: {
      float temp_var_for_ext_3;
      temp_var_for_ext_3 = y;
      AssignF({(Addr)&temp_var_for_ext_3}, (Addr)&y,
              "/home/shijia/Public/testprogram/e_atan2f.c_e.c:64:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_3;
    }
    }
    /* atan(+-0,+anything)=+-0 */
    case 2: {
      float temp_var_for_ext_4;
      float temp_var_for_tac_2;
      float temp_var_for_const_3, temp_var_for_const_4;
      temp_var_for_tac_2 = pi + tiny;

      temp_var_for_ext_4 = temp_var_for_tac_2;
      computeFAdd((Addr)&temp_var_for_tac_2,
                  {(Addr) &(temp_var_for_const_4 = pi),
                   (Addr) &(temp_var_for_const_3 = tiny)},
                  "/home/shijia/Public/testprogram/e_atan2f.c_e.c:74:31");
      AssignF({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_2,
              "/home/shijia/Public/testprogram/e_atan2f.c_e.c:74:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_4;
    }
    /* atan(+0,-anything) = pi */
    case 3: {
      float temp_var_for_ext_5;
      float temp_var_for_tac_3;
      float temp_var_for_const_5, temp_var_for_const_6;
      temp_var_for_tac_3 = (-(pi)) - tiny;

      temp_var_for_ext_5 = temp_var_for_tac_3;
      computeFSub((Addr)&temp_var_for_tac_3,
                  {(Addr) &(temp_var_for_const_6 = (-(pi))),
                   (Addr) &(temp_var_for_const_5 = tiny)},
                  "/home/shijia/Public/testprogram/e_atan2f.c_e.c:83:32");
      AssignF({(Addr)&temp_var_for_ext_5}, (Addr)&temp_var_for_tac_3,
              "/home/shijia/Public/testprogram/e_atan2f.c_e.c:83:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
      callExp++; /*identify the function is  add move tmpShadow*/
      return (0.0 - fo)r_ext_5;
    }
      /* atan(-0,-anything) =-pi */
    }
  }
  /* when x = 0 */
  if (FLT_UWORD_IS_ZERO(ix)) {
    float temp_var_for_ext_6;
    float temp_var_for_const_7;
    temp_var_for_ext_6 = (hy < 0) ? -pi_o_2 - tiny : pi_o_2 + tiny;
    AssignF({(Addr)&temp_var_for_ext_6},
            (Addr) &(temp_var_for_const_7 =
                         (hy < 0) ? -pi_o_2 - tiny : pi_o_2 + tiny),
            "/home/shijia/Public/testprogram/e_atan2f.c_e.c:95:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
    callExp++; /*identify the function is  add move tmpShad(0.0 - w*/
re)turn temp_var_for_ext_6;
  }

  /* when x is INF */
  if (FLT_UWORD_IS_INFINITE(ix)) {
    if (FLT_UWORD_IS_INFINITE(iy)) {
      int temp_var_for_ext_7;
      temp_var_for_ext_7 = (int)m;
      switch (temp_var_for_ext_7) {
      case 0: {
        float temp_var_for_ext_8;
        temp_var_for_ext_8 = float temp_var_for_tac_4;
        float temp_var_for_const_8, temp_var_for_const_9;
        temp_var_for_tac_4 = pi_o_4 + tiny;

        ;
        callExpStack.push(
            getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_8;
      }
      /* atan(+INF,+INF) */
      case 1: {
        float temp_var_for_ext_9;
        float temp_var_for_tac_5;
        float temp_var_for_const_10, temp_var_for_const_11;
        temp_var_for_tac_5 = (-(pi_o_4)) - tiny;

        temp_var_for_ext_9 = temp_var_for_tac_5;
        computeFAdd((Addr)&temp_var_for_tac_4,
                    {(Addr) &(temp_var_for_const_9 = pi_o_4),
                     (Addr) &(temp_var_for_const_8 = tiny)},
                    "/home/shijia/Public/testprogram/e_atan2f.c_e.c:109:37");
        computeFSub((Addr)&temp_var_for_tac_5,
                    {(Addr) &(temp_var_for_const_11 = (-(pi_o_4))),
                     (Addr) &(temp_var_for_const_10 = tiny)},
                    "/home/shijia/Public/testprogram/e_atan2f.c_e.c:118:38");
        AssignF({(Addr)&temp_var_for_ext_9}, (Addr)&temp_var_for_tac_5,
                "/home/shijia/Public/testprogram/e_atan2f.c_e.c:118:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
        callExp++; /*identify the function is  add move tmpShadow*/
        return (0.0 - var_fo)r_ext_9;
      }
      /* atan(-INF,+INF) */
      case 2: {
        float temp_var_for_ext_10;
        float temp_var_for_tac_6, temp_var_for_tac_7;
        float temp_var_for_const_12, temp_var_for_const_13,
            temp_var_for_const_14;
        temp_var_for_tac_6 = ((float)3.0) * pi_o_4;

        temp_var_for_tac_7 = temp_var_for_tac_6 + tiny;

        temp_var_for_ext_10 = temp_var_for_tac_7;
        computeFMul((Addr)&temp_var_for_tac_6,
                    {(Addr) &(temp_var_for_const_13 = ((float)3.0)),
                     (Addr) &(temp_var_for_const_12 = pi_o_4)},
                    "/home/shijia/Public/testprogram/e_atan2f.c_e.c:127:42");
        computeFAdd(
            (Addr)&temp_var_for_tac_7,
            {(Addr)&temp_var_for_tac_6, (Addr) &(temp_var_for_const_14 = tiny)},
            "/home/shijia/Public/testprogram/e_atan2f.c_e.c:127:51");
        AssignF({(Addr)&temp_var_for_ext_10}, (Addr)&temp_var_for_tac_7,
                "/home/shijia/Public/testprogram/e_atan2f.c_e.c:127:29");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_10", (Addr)&temp_var_for_ext_10));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_10;
      }
      /*atan(+INF,-INF) */

      case 3: {
        float temp_var_for_ext_11;
        float temp_var_for_tac_8, temp_var_for_tac_9;
        float temp_var_for_const_15, temp_var_for_const_16,
            temp_var_for_const_17;
        temp_var_for_tac_8 = ((float)(-(3.0))) * pi_o_4;

        temp_var_for_tac_9 = temp_var_for_tac_8 - tiny;

        temp_var_for_ext_11 = temp_var_for_tac_9;
        computeFMul((Addr)&temp_var_for_tac_8,
                    {(Addr) &(temp_var_for_const_16 = ((float)(-(3.0)))),
                     (Addr) &(temp_var_for_const_15 = pi_o_4)},
                    "/home/shijia/Public/testprogram/e_atan2f.c_e.c:137:43");
        computeFSub(
            (Addr)&temp_var_for_tac_9,
            {(Addr)&temp_var_for_tac_8, (Addr) &(temp_var_for_const_17 = tiny)},
            "/home/shijia/Public/testprogram/e_atan2f.c_e.c:137:52");
        AssignF({(Addr)&temp_var_for_ext_11}, (Addr)&temp_var_for_tac_9,
                "/home/shijia/Public/testprogram/e_atan2f.c_e.c:137:29");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_11", (Addr)&temp_var_for_ext_11));
        callExp++; /*identify the function is  add move tmpShadow*/
        return (0.0 - tem)p_var_for_ext_11;
      }
        /*atan(-INF,-INF) */
      }
    } else {
      int temp_var_for_ext_12;
      temp_var_for_ext_12 = (int)m;
      switch (temp_var_for_ext_12) {
      case 0: {
        float temp_var_for_ext_13;
        float temp_var_for_const_18;
        temp_var_for_ext_13 = zero;
        AssignF({(Addr)&temp_var_for_ext_13},
                (Addr) &(temp_var_for_const_18 = zero),
                "/home/shijia/Public/testprogram/e_atan2f.c_e.c:151:29");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_13", (Addr)&temp_var_for_ext_13));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_13;
      }
      /* atan(+...,+INF) */
      case 1: {
        float temp_var_for_ext_14;
        float temp_var_for_const_19;
        temp_var_for_ext_14 = (-(zero));
        AssignF({(Addr)&temp_var_for_ext_14},
                (Addr) &(temp_var_for_const_19 = (-(zero))),
                "/home/shijia/Public/testprogram/e_atan2f.c_e.c:160:29");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_14", (Addr)&temp_var_for_ext_14));
        callExp++; /*identify the function is  add move tmpShadow*/
        return (0.0 - t_14);
      }
      /* atan(-...,+INF) */
      case 2: {
        float temp_var_for_ext_15;
        float temp_var_for_tac_10;
        float temp_var_for_const_20, temp_var_for_const_21;
        temp_var_for_tac_10 = pi + tiny;

        temp_var_for_ext_15 = temp_var_for_tac_10;
        computeFAdd((Addr)&temp_var_for_tac_10,
                    {(Addr) &(temp_var_for_const_21 = pi),
                     (Addr) &(temp_var_for_const_20 = tiny)},
                    "/home/shijia/Public/testprogram/e_atan2f.c_e.c:169:34");
        AssignF({(Addr)&temp_var_for_ext_15}, (Addr)&temp_var_for_tac_10,
                "/home/shijia/Public/testprogram/e_atan2f.c_e.c:169:29");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_15", (Addr)&temp_var_for_ext_15));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_15;
      }
      /* atan(+...,-INF) */
      case 3: {
        float temp_var_for_ext_16;
        float temp_var_for_tac_11;
        float temp_var_for_const_22, temp_var_for_const_23;
        temp_var_for_tac_11 = (-(pi)) - tiny;

        temp_var_for_ext_16 = temp_var_for_tac_11;
        computeFSub((Addr)&temp_var_for_tac_11,
                    {(Addr) &(temp_var_for_const_23 = (-(pi))),
                     (Addr) &(temp_var_for_const_22 = tiny)},
                    "/home/shijia/Public/testprogram/e_atan2f.c_e.c:178:35");
        AssignF({(Addr)&temp_var_for_ext_16}, (Addr)&temp_var_for_tac_11,
                "/home/shijia/Public/testprogram/e_atan2f.c_e.c:178:29");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_16", (Addr)&temp_var_for_ext_16));
        callExp++; /*identify the function is  add move tmpShadow*/
        return (0.0 - or )_ext_16;
      }
        /* atan(-...,-INF) */
      }
    }
  }
  /* when y is INF */
  if (FLT_UWORD_IS_INFINITE(iy)) {
    float temp_var_for_ext_17;
    float temp_var_for_const_24;
    temp_var_for_ext_17 = (hy < 0) ? -pi_o_2 - tiny : pi_o_2 + tiny;
    AssignF({(Addr)&temp_var_for_ext_17},
            (Addr) &(temp_var_for_const_24 =
                         (hy < 0) ? -pi_o_2 - tiny : pi_o_2 + tiny),
            "/home/shijia/Public/testprogram/e_atan2f.c_e.c:191:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_17", (Addr)&temp_var_for_ext_17));
    callExp++; /*identify the function is  add move tmpShado(0.0 - */
ret)urn temp_var_for_ext_17;
  }

  /* compute y/x */
  k = (iy - ix) >> 23;
  if (k > 60) {
    z = float temp_var_for_tac_12, temp_var_for_tac_13;
    float temp_var_for_const_25, temp_var_for_const_26, temp_var_for_const_27;
    temp_var_for_tac_12 = ((float)0.5) * pi_lo;

    temp_var_for_tac_13 = pi_o_2 + temp_var_for_tac_12;

    ;
  }
  /* |y/x| >  2**60 */

  else {
    if (hx < 0 && k < -60) {
      float temp_var_for_const_28;
      z = 0.0;
      computeFMul((Addr)&temp_var_for_tac_12,
                  {(Addr) &(temp_var_for_const_26 = ((float)0.5)),
                   (Addr) &(temp_var_for_const_25 = pi_lo)},
                  "/home/shijia/Public/testprogram/e_atan2f.c_e.c:201:29");
      computeFAdd((Addr)&temp_var_for_tac_13,
                  {(Addr) &(temp_var_for_const_27 = pi_o_2),
                   (Addr)&temp_var_for_tac_12},
                  "/home/shijia/Public/testprogram/e_atan2f.c_e.c:201:16");
      AssignF({(Addr)&z}, (Addr) &(temp_var_for_const_28 = 0.0),
              "/home/shijia/Public/testprogram/e_atan2f.c_e.c:207:9");
      ;
    }
    /* |y|/x < -2**60 */
    else {
      float temp_var_for_tac_14;
      float temp_var_for_const_29;
      float temp_var_for_callexp_1;

      /*embed fun has found*/
      float temp_var_for_callexp_2;

      temp_var_for_tac_14 = y / x;

      temp_var_for_callexp_1 = fabsf(temp_var_for_tac_14);
      temp_var_for_callexp_2 = __ieee754_atanf(temp_var_for_callexp_1);
      z = temp_var_for_callexp_2;
      computeFDiv((Addr)&temp_var_for_tac_14, {(Addr)&y, (Addr)&x},
                  "/home/shijia/Public/testprogram/e_atan2f.c_e.c:211:27 "
                  "<Spelling=/home/shijia/Public/testprogram/"
                  "e_atan2f.c_e.c:211:45>");
      AssignF({(Addr)&z},
              (Addr) &(temp_var_for_const_29 = temp_var_for_callexp_2),
              "/home/shijia/Public/testprogram/e_atan2f.c_e.c:211:9");
      ;
    }
  }
  /* safe to do y/x */
  int temp_var_for_ext_18;
  temp_var_for_ext_18 = (int)m;
  switch (temp_var_for_ext_18) {
  case 0: {
    float temp_var_for_ext_19;
    temp_var_for_ext_19 = z;
    AssignF({(Addr)&temp_var_for_ext_19}, (Addr)&z,
            "/home/shijia/Public/testprogram/e_atan2f.c_e.c:220:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_19", (Addr)&temp_var_for_ext_19));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_19;
  }
  /* atan(+,+) */
  case 1: {
    uint32_t zh;

    GET_FLOAT_WORD(zh, z);
    SET_FLOAT_WORD(z, zh ^ UC(0x80000000));
  }
    float temp_var_for_ext_20;
    temp_var_for_ext_20 = z;
    AssignF({(Addr)&temp_var_for_ext_20}, (Addr)&z,
            "/home/shijia/Public/testprogram/e_atan2f.c_e.c:234:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_20", (Addr)&temp_var_for_ext_20));
    callExp++;                  /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_20; /* atan(-,+) */
  case 2: {
    float temp_var_for_ext_21;
    float temp_var_for_tac_15, temp_var_for_tac_16;
    float temp_var_for_const_30, temp_var_for_const_31;
    temp_var_for_tac_15 = z - pi_lo;

    temp_var_for_tac_16 = pi - temp_var_for_tac_15;

    temp_var_for_ext_21 = temp_var_for_tac_16;
    computeFSub((Addr)&temp_var_for_tac_15,
                {(Addr)&z, (Addr) &(temp_var_for_const_30 = pi_lo)},
                "/home/shijia/Public/testprogram/e_atan2f.c_e.c:241:35");
    computeFSub(
        (Addr)&temp_var_for_tac_16,
        {(Addr) &(temp_var_for_const_31 = pi), (Addr)&temp_var_for_tac_15},
        "/home/shijia/Public/testprogram/e_atan2f.c_e.c:241:30");
    AssignF({(Addr)&temp_var_for_ext_21}, (Addr)&temp_var_for_tac_16,
            "/home/shijia/Public/testprogram/e_atan2f.c_e.c:241:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_21", (Addr)&temp_var_for_ext_21));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_21;
  }
  /* atan(+,-) */
  default: /* case 3 */
  {
    float temp_var_for_ext_22;
    float temp_var_for_tac_17, temp_var_for_tac_18;
    float temp_var_for_const_32, temp_var_for_const_33;
    temp_var_for_tac_17 = z - pi_lo;

    temp_var_for_tac_18 = temp_var_for_tac_17 - pi;

    temp_var_for_ext_22 = temp_var_for_tac_18;
    computeFSub((Addr)&temp_var_for_tac_17,
                {(Addr)&z, (Addr) &(temp_var_for_const_32 = pi_lo)},
                "/home/shijia/Public/testprogram/e_atan2f.c_e.c:251:30");
    computeFSub(
        (Addr)&temp_var_for_tac_18,
        {(Addr)&temp_var_for_tac_17, (Addr) &(temp_var_for_const_33 = pi)},
        "/home/shijia/Public/testprogram/e_atan2f.c_e.c:251:39");
    AssignF({(Addr)&temp_var_for_ext_22}, (Addr)&temp_var_for_tac_18,
            "/home/shijia/Public/testprogram/e_atan2f.c_e.c:251:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_22", (Addr)&temp_var_for_ext_22));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_22;
  }
    /* atan(-,-) */
  }
}

#endif

float __atan2f(float y, float x) {
  if (int temp_var_for_tac_19; int temp_var_for_const_34;
      temp_var_for_tac_19 = x == 0.0f;

      &&int temp_var_for_tac_20; int temp_var_for_const_35;
      temp_var_for_tac_20 = y == 0.0f;

      &&_LIB_VERSION == _SVID_) {
    float temp_var_for_ext_23;
    float temp_var_for_const_36;
    float temp_var_for_callexp_3;

    /*embed fun has found*/
    float temp_var_for_callexp_4;

    temp_var_for_callexp_3 = __builtin_huge_valf();
    temp_var_for_callexp_4 =
        __kernel_standard_f(y, x, temp_var_for_callexp_3, KMATHERRF_ATAN2);
    temp_var_for_ext_23 = temp_var_for_callexp_4;
    compute((Addr)&temp_var_for_tac_19,
            {(Addr)&x, (Addr) &(temp_var_for_const_34 = 0.0f)},
            "/home/shijia/Public/testprogram/e_atan2f.c_e.c:264:9");
    compute((Addr)&temp_var_for_tac_20,
            {(Addr)&y, (Addr) &(temp_var_for_const_35 = 0.0f)},
            "/home/shijia/Public/testprogram/e_atan2f.c_e.c:264:22");
    AssignF({(Addr)&temp_var_for_ext_23},
            (Addr) &(temp_var_for_const_36 = temp_var_for_callexp_4),
            "/home/shijia/Public/testprogram/e_atan2f.c_e.c:266:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_23", (Addr)&temp_var_for_ext_23));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_23;
  }
  /* atan2(+-0,+-0) */

  float temp_var_for_ext_24;
  float temp_var_for_const_37;
  float temp_var_for_callexp_5;

  temp_var_for_callexp_5 = __ieee754_atan2f(y, x);
  temp_var_for_ext_24 = temp_var_for_callexp_5;
  AssignF({(Addr)&temp_var_for_ext_24},
          (Addr) &(temp_var_for_const_37 = temp_var_for_callexp_5),
          "/home/shijia/Public/testprogram/e_atan2f.c_e.c:275:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_24", (Addr)&temp_var_for_ext_24));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_24;
}

__typeof(__atan2f) atan2f __attribute__((weak, alias("__atan2f")));
