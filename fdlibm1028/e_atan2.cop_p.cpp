#include "../ScDebug/scdebug.h"
/* @(#)e_atan2.c 1.3 95/01/18 */
/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunSoft, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 *
 */

/* __ieee754_atan2(y,x)
 * Method :
 *	1. Reduce y to positive by atan2(y,x)=-atan2(-y,x).
 *	2. Reduce x to positive by (if x and y are unexceptional):
 *		ARG (x+iy) = arctan(y/x)   	   ... if x > 0,
 *		ARG (x+iy) = pi - arctan[y/(-x)]   ... if x < 0,
 *
 * Special cases:
 *
 *	ATAN2((anything), NaN ) is NaN;
 *	ATAN2(NAN , (anything) ) is NaN;
 *	ATAN2(+-0, +(anything but NaN)) is +-0  ;
 *	ATAN2(+-0, -(anything but NaN)) is +-pi ;
 *	ATAN2(+-(anything but 0 and NaN), 0) is +-pi/2;
 *	ATAN2(+-(anything but INF and NaN), +INF) is +-0 ;
 *	ATAN2(+-(anything but INF and NaN), -INF) is +-pi;
 *	ATAN2(+-INF,+INF ) is +-pi/4 ;
 *	ATAN2(+-INF,-INF ) is +-3pi/4;
 *	ATAN2(+-INF, (anything but,0,NaN, and INF)) is +-pi/2;
 *
 * Constants:
 * The hexadecimal values are the intended ones for the following
 * constants. The decimal values may be used, provided that the
 * compiler will convert from decimal to binary accurately enough
 * to produce the hexadecimal values shown.
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_atan2

double __ieee754_atan2(double y, double x) {
  double z;
  int32_t k, m, hx, hy, ix, iy;
  uint32_t lx, ly;

  static const double tiny = 1.0e-300;
  static const double zero = 0.0;
  static const double pi_o_4 =
      7.8539816339744827900E-01; /* 0x3FE921FB, 0x54442D18 */
  static const double pi_o_2 =
      1.5707963267948965580E+00; /* 0x3FF921FB, 0x54442D18 */
  static const double pi =
      3.1415926535897931160E+00; /* 0x400921FB, 0x54442D18 */
  static const double pi_lo =
      1.2246467991473531772E-16; /* 0x3CA1A626, 0x33145C07 */

  GET_DOUBLE_WORDS(hx, lx, x);
  ix = hx & IC(0x7fffffff);
  GET_DOUBLE_WORDS(hy, ly, y);
  iy = hy & IC(0x7fffffff);
  if (((ix | ((lx | -lx) >> 31)) > IC(0x7ff00000)) ||
      ((iy | ((ly | -ly) >> 31)) > IC(0x7ff00000))) /* x or y is NaN */
  {
    double temp_var_for_ext_0;
    double temp_var_for_tac_0;
    temp_var_for_tac_0 = x + y;

    temp_var_for_ext_0 = temp_var_for_tac_0;
    computeDAdd((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&y},
                "/home/shijia/Public/testprogram/e_atan2.c_e.c:71:28");
    AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_0,
            "/home/shijia/Public/testprogram/e_atan2.c_e.c:71:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  if (((hx - IC(0x3ff00000)) | lx) == 0) {
    double temp_var_for_ext_1;
    double temp_var_for_const_0;
    double temp_var_for_callexp_0;

    temp_var_for_callexp_0 = __ieee754_atan(y);
    temp_var_for_ext_1 = temp_var_for_callexp_0;
    AssignD({(Addr)&temp_var_for_ext_1},
            (Addr) &(temp_var_for_const_0 = temp_var_for_callexp_0),
            "/home/shijia/Public/testprogram/e_atan2.c_e.c:79:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }
  /* x=1.0 */
  m = ((hy >> 31) & 1) | ((hx >> 30) & 2); /* 2*sign(x)+sign(y) */

  /* when y = 0 */
  if ((iy | ly) == 0) {
    int temp_var_for_ext_2;
    temp_var_for_ext_2 = (int)m;
    switch (temp_var_for_ext_2) {
    case 0: {
    case 1: {
      double temp_var_for_ext_3;
      temp_var_for_ext_3 = y;
      AssignD({(Addr)&temp_var_for_ext_3}, (Addr)&y,
              "/home/shijia/Public/testprogram/e_atan2.c_e.c:95:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_3;
    }
    }
    /* atan(+-0,+anything)=+-0 */
    case 2: {
      double temp_var_for_ext_4;
      double temp_var_for_tac_1;
      double temp_var_for_const_1, temp_var_for_const_2;
      temp_var_for_tac_1 = pi + tiny;

      temp_var_for_ext_4 = temp_var_for_tac_1;
      computeDAdd((Addr)&temp_var_for_tac_1,
                  {(Addr) &(temp_var_for_const_2 = pi),
                   (Addr) &(temp_var_for_const_1 = tiny)},
                  "/home/shijia/Public/testprogram/e_atan2.c_e.c:105:31");
      AssignD({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_1,
              "/home/shijia/Public/testprogram/e_atan2.c_e.c:105:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_4;
    }
    /* atan(+0,-anything) = pi */
    case 3: {
      double temp_var_for_ext_5;
      double temp_var_for_tac_2;
      double temp_var_for_const_3, temp_var_for_const_4;
      temp_var_for_tac_2 = (-(pi)) - tiny;

      temp_var_for_ext_5 = temp_var_for_tac_2;
      computeDSub((Addr)&temp_var_for_tac_2,
                  {(Addr) &(temp_var_for_const_4 = (-(pi))),
                   (Addr) &(temp_var_for_const_3 = tiny)},
                  "/home/shijia/Public/testprogram/e_atan2.c_e.c:114:32");
      AssignD({(Addr)&temp_var_for_ext_5}, (Addr)&temp_var_for_tac_2,
              "/home/shijia/Public/testprogram/e_atan2.c_e.c:114:26");
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
  if ((ix | lx) == 0) {
    double temp_var_for_ext_6;
    double temp_var_for_const_5;
    temp_var_for_ext_6 = (hy < 0) ? -pi_o_2 - tiny : pi_o_2 + tiny;
    AssignD({(Addr)&temp_var_for_ext_6},
            (Addr) &(temp_var_for_const_5 =
                         (hy < 0) ? -pi_o_2 - tiny : pi_o_2 + tiny),
            "/home/shijia/Public/testprogram/e_atan2.c_e.c:126:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
    callExp++; /*identify the function is  add move tmpShad(0.0 - w*/
re)turn temp_var_for_ext_6;
  }

  /* when x is INF */
  if (ix == IC(0x7ff00000)) {
    if (iy == IC(0x7ff00000)) {
      int temp_var_for_ext_7;
      temp_var_for_ext_7 = (int)m;
      switch (temp_var_for_ext_7) {
      case 0: {
        double temp_var_for_ext_8;
        temp_var_for_ext_8 = double temp_var_for_tac_3;
        double temp_var_for_const_6, temp_var_for_const_7;
        temp_var_for_tac_3 = pi_o_4 + tiny;

        ;
        callExpStack.push(
            getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_8;
      }
      /* atan(+INF,+INF) */
      case 1: {
        double temp_var_for_ext_9;
        double temp_var_for_tac_4;
        double temp_var_for_const_8, temp_var_for_const_9;
        temp_var_for_tac_4 = (-(pi_o_4)) - tiny;

        temp_var_for_ext_9 = temp_var_for_tac_4;
        computeDAdd((Addr)&temp_var_for_tac_3,
                    {(Addr) &(temp_var_for_const_7 = pi_o_4),
                     (Addr) &(temp_var_for_const_6 = tiny)},
                    "/home/shijia/Public/testprogram/e_atan2.c_e.c:140:37");
        computeDSub((Addr)&temp_var_for_tac_4,
                    {(Addr) &(temp_var_for_const_9 = (-(pi_o_4))),
                     (Addr) &(temp_var_for_const_8 = tiny)},
                    "/home/shijia/Public/testprogram/e_atan2.c_e.c:149:38");
        AssignD({(Addr)&temp_var_for_ext_9}, (Addr)&temp_var_for_tac_4,
                "/home/shijia/Public/testprogram/e_atan2.c_e.c:149:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
        callExp++; /*identify the function is  add move tmpShadow*/
        return (0.0 - var_fo)r_ext_9;
      }
      /* atan(-INF,+INF) */
      case 2: {
        double temp_var_for_ext_10;
        double temp_var_for_tac_5, temp_var_for_tac_6;
        double temp_var_for_const_10, temp_var_for_const_11,
            temp_var_for_const_12;
        temp_var_for_tac_5 = 3.0 * pi_o_4;

        temp_var_for_tac_6 = temp_var_for_tac_5 + tiny;

        temp_var_for_ext_10 = temp_var_for_tac_6;
        computeDMul((Addr)&temp_var_for_tac_5,
                    {(Addr) &(temp_var_for_const_11 = 3.0),
                     (Addr) &(temp_var_for_const_10 = pi_o_4)},
                    "/home/shijia/Public/testprogram/e_atan2.c_e.c:158:35");
        computeDAdd(
            (Addr)&temp_var_for_tac_6,
            {(Addr)&temp_var_for_tac_5, (Addr) &(temp_var_for_const_12 = tiny)},
            "/home/shijia/Public/testprogram/e_atan2.c_e.c:158:44");
        AssignD({(Addr)&temp_var_for_ext_10}, (Addr)&temp_var_for_tac_6,
                "/home/shijia/Public/testprogram/e_atan2.c_e.c:158:29");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_10", (Addr)&temp_var_for_ext_10));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_10;
      }
      /*atan(+INF,-INF) */
      case 3: {
        double temp_var_for_ext_11;
        double temp_var_for_tac_7, temp_var_for_tac_8;
        double temp_var_for_const_13, temp_var_for_const_14,
            temp_var_for_const_15;
        temp_var_for_tac_7 = (-(3.0)) * pi_o_4;

        temp_var_for_tac_8 = temp_var_for_tac_7 - tiny;

        temp_var_for_ext_11 = temp_var_for_tac_8;
        computeDMul((Addr)&temp_var_for_tac_7,
                    {(Addr) &(temp_var_for_const_14 = (-(3.0))),
                     (Addr) &(temp_var_for_const_13 = pi_o_4)},
                    "/home/shijia/Public/testprogram/e_atan2.c_e.c:167:36");
        computeDSub(
            (Addr)&temp_var_for_tac_8,
            {(Addr)&temp_var_for_tac_7, (Addr) &(temp_var_for_const_15 = tiny)},
            "/home/shijia/Public/testprogram/e_atan2.c_e.c:167:45");
        AssignD({(Addr)&temp_var_for_ext_11}, (Addr)&temp_var_for_tac_8,
                "/home/shijia/Public/testprogram/e_atan2.c_e.c:167:29");
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
        double temp_var_for_ext_13;
        double temp_var_for_const_16;
        temp_var_for_ext_13 = zero;
        AssignD({(Addr)&temp_var_for_ext_13},
                (Addr) &(temp_var_for_const_16 = zero),
                "/home/shijia/Public/testprogram/e_atan2.c_e.c:181:29");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_13", (Addr)&temp_var_for_ext_13));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_13;
      }
      /* atan(+...,+INF) */
      case 1: {
        double temp_var_for_ext_14;
        double temp_var_for_const_17;
        temp_var_for_ext_14 = (-(zero));
        AssignD({(Addr)&temp_var_for_ext_14},
                (Addr) &(temp_var_for_const_17 = (-(zero))),
                "/home/shijia/Public/testprogram/e_atan2.c_e.c:190:29");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_14", (Addr)&temp_var_for_ext_14));
        callExp++; /*identify the function is  add move tmpShadow*/
        return (0.0 - t_14);
      }
      /* atan(-...,+INF) */
      case 2: {
        double temp_var_for_ext_15;
        double temp_var_for_tac_9;
        double temp_var_for_const_18, temp_var_for_const_19;
        temp_var_for_tac_9 = pi + tiny;

        temp_var_for_ext_15 = temp_var_for_tac_9;
        computeDAdd((Addr)&temp_var_for_tac_9,
                    {(Addr) &(temp_var_for_const_19 = pi),
                     (Addr) &(temp_var_for_const_18 = tiny)},
                    "/home/shijia/Public/testprogram/e_atan2.c_e.c:199:34");
        AssignD({(Addr)&temp_var_for_ext_15}, (Addr)&temp_var_for_tac_9,
                "/home/shijia/Public/testprogram/e_atan2.c_e.c:199:29");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_15", (Addr)&temp_var_for_ext_15));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_15;
      }
      /* atan(+...,-INF) */
      case 3: {
        double temp_var_for_ext_16;
        double temp_var_for_tac_10;
        double temp_var_for_const_20, temp_var_for_const_21;
        temp_var_for_tac_10 = (-(pi)) - tiny;

        temp_var_for_ext_16 = temp_var_for_tac_10;
        computeDSub((Addr)&temp_var_for_tac_10,
                    {(Addr) &(temp_var_for_const_21 = (-(pi))),
                     (Addr) &(temp_var_for_const_20 = tiny)},
                    "/home/shijia/Public/testprogram/e_atan2.c_e.c:208:35");
        AssignD({(Addr)&temp_var_for_ext_16}, (Addr)&temp_var_for_tac_10,
                "/home/shijia/Public/testprogram/e_atan2.c_e.c:208:29");
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
  if (iy == IC(0x7ff00000)) {
    double temp_var_for_ext_17;
    double temp_var_for_const_22;
    temp_var_for_ext_17 = (hy < 0) ? -pi_o_2 - tiny : pi_o_2 + tiny;
    AssignD({(Addr)&temp_var_for_ext_17},
            (Addr) &(temp_var_for_const_22 =
                         (hy < 0) ? -pi_o_2 - tiny : pi_o_2 + tiny),
            "/home/shijia/Public/testprogram/e_atan2.c_e.c:221:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_17", (Addr)&temp_var_for_ext_17));
    callExp++; /*identify the function is  add move tmpShado(0.0 - */
ret)urn temp_var_for_ext_17;
  }

  /* compute y/x */
  k = (iy - ix) >> 20;
  if (k > 60) {
    z = double temp_var_for_tac_11, temp_var_for_tac_12;
    double temp_var_for_const_23, temp_var_for_const_24, temp_var_for_const_25;
    temp_var_for_tac_11 = 0.5 * pi_lo;

    temp_var_for_tac_12 = pi_o_2 + temp_var_for_tac_11;

    ;
  }
  /* |y/x| >  2**60 */
  else {
    if (hx < 0 && k < -60) {
      double temp_var_for_const_26;
      z = 0.0;
      computeDMul((Addr)&temp_var_for_tac_11,
                  {(Addr) &(temp_var_for_const_24 = 0.5),
                   (Addr) &(temp_var_for_const_23 = pi_lo)},
                  "/home/shijia/Public/testprogram/e_atan2.c_e.c:231:22");
      computeDAdd((Addr)&temp_var_for_tac_12,
                  {(Addr) &(temp_var_for_const_25 = pi_o_2),
                   (Addr)&temp_var_for_tac_11},
                  "/home/shijia/Public/testprogram/e_atan2.c_e.c:231:16");
      AssignD({(Addr)&z}, (Addr) &(temp_var_for_const_26 = 0.0),
              "/home/shijia/Public/testprogram/e_atan2.c_e.c:236:9");
      ;
    }
    /* |y|/x < -2**60 */
    else {
      double temp_var_for_tac_13;
      double temp_var_for_const_27;
      double temp_var_for_callexp_1;

      /*embed fun has found*/
      double temp_var_for_callexp_2;

      temp_var_for_tac_13 = y / x;

      temp_var_for_callexp_1 = fabs(temp_var_for_tac_13);
      temp_var_for_callexp_2 = __ieee754_atan(temp_var_for_callexp_1);
      z = temp_var_for_callexp_2;
      computeDDiv((Addr)&temp_var_for_tac_13, {(Addr)&y, (Addr)&x},
                  "/home/shijia/Public/testprogram/e_atan2.c_e.c:240:26 "
                  "<Spelling=/home/shijia/Public/testprogram/"
                  "e_atan2.c_e.c:240:43>");
      AssignD({(Addr)&z},
              (Addr) &(temp_var_for_const_27 = temp_var_for_callexp_2),
              "/home/shijia/Public/testprogram/e_atan2.c_e.c:240:9");
      ;
    }
  }
  /* safe to do y/x */
  int temp_var_for_ext_18;
  temp_var_for_ext_18 = (int)m;
  switch (temp_var_for_ext_18) {
  case 0: {
    double temp_var_for_ext_19;
    temp_var_for_ext_19 = z;
    AssignD({(Addr)&temp_var_for_ext_19}, (Addr)&z,
            "/home/shijia/Public/testprogram/e_atan2.c_e.c:249:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_19", (Addr)&temp_var_for_ext_19));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_19;
  }
  /* atan(+,+) */
  case 1: {
    uint32_t zh;

    GET_HIGH_WORD(zh, z);
    SET_HIGH_WORD(z, zh ^ UC(0x80000000));
  }
    double temp_var_for_ext_20;
    temp_var_for_ext_20 = z;
    AssignD({(Addr)&temp_var_for_ext_20}, (Addr)&z,
            "/home/shijia/Public/testprogram/e_atan2.c_e.c:263:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_20", (Addr)&temp_var_for_ext_20));
    callExp++;                  /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_20; /* atan(-,+) */
  case 2: {
    double temp_var_for_ext_21;
    double temp_var_for_tac_14, temp_var_for_tac_15;
    double temp_var_for_const_28, temp_var_for_const_29;
    temp_var_for_tac_14 = z - pi_lo;

    temp_var_for_tac_15 = pi - temp_var_for_tac_14;

    temp_var_for_ext_21 = temp_var_for_tac_15;
    computeDSub((Addr)&temp_var_for_tac_14,
                {(Addr)&z, (Addr) &(temp_var_for_const_28 = pi_lo)},
                "/home/shijia/Public/testprogram/e_atan2.c_e.c:270:35");
    computeDSub(
        (Addr)&temp_var_for_tac_15,
        {(Addr) &(temp_var_for_const_29 = pi), (Addr)&temp_var_for_tac_14},
        "/home/shijia/Public/testprogram/e_atan2.c_e.c:270:30");
    AssignD({(Addr)&temp_var_for_ext_21}, (Addr)&temp_var_for_tac_15,
            "/home/shijia/Public/testprogram/e_atan2.c_e.c:270:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_21", (Addr)&temp_var_for_ext_21));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_21;
  }
  /* atan(+,-) */
  default: /* case 3 */
  {
    double temp_var_for_ext_22;
    double temp_var_for_tac_16, temp_var_for_tac_17;
    double temp_var_for_const_30, temp_var_for_const_31;
    temp_var_for_tac_16 = z - pi_lo;

    temp_var_for_tac_17 = temp_var_for_tac_16 - pi;

    temp_var_for_ext_22 = temp_var_for_tac_17;
    computeDSub((Addr)&temp_var_for_tac_16,
                {(Addr)&z, (Addr) &(temp_var_for_const_30 = pi_lo)},
                "/home/shijia/Public/testprogram/e_atan2.c_e.c:280:30");
    computeDSub(
        (Addr)&temp_var_for_tac_17,
        {(Addr)&temp_var_for_tac_16, (Addr) &(temp_var_for_const_31 = pi)},
        "/home/shijia/Public/testprogram/e_atan2.c_e.c:280:39");
    AssignD({(Addr)&temp_var_for_ext_22}, (Addr)&temp_var_for_tac_17,
            "/home/shijia/Public/testprogram/e_atan2.c_e.c:280:25");
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

double __atan2(double y, double x) /* wrapper atan2 */
{
  if (_LIB_VERSION == _SVID_ && int temp_var_for_tac_18;
      int temp_var_for_const_32; temp_var_for_tac_18 = x == 0.0;

      &&int temp_var_for_tac_19; int temp_var_for_const_33;
      temp_var_for_tac_19 = y == 0.0;

      ) {
    double temp_var_for_ext_23;
    double temp_var_for_const_34;
    double temp_var_for_callexp_3;

    /*embed fun has found*/
    double temp_var_for_callexp_4;

    temp_var_for_callexp_3 = __builtin_huge_val();
    temp_var_for_callexp_4 =
        __kernel_standard(y, x, temp_var_for_callexp_3, KMATHERR_ATAN2);
    temp_var_for_ext_23 = temp_var_for_callexp_4;
    compute((Addr)&temp_var_for_tac_18,
            {(Addr)&x, (Addr) &(temp_var_for_const_32 = 0.0)},
            "/home/shijia/Public/testprogram/e_atan2.c_e.c:294:35");
    compute((Addr)&temp_var_for_tac_19,
            {(Addr)&y, (Addr) &(temp_var_for_const_33 = 0.0)},
            "/home/shijia/Public/testprogram/e_atan2.c_e.c:294:47");
    AssignD({(Addr)&temp_var_for_ext_23},
            (Addr) &(temp_var_for_const_34 = temp_var_for_callexp_4),
            "/home/shijia/Public/testprogram/e_atan2.c_e.c:296:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_23", (Addr)&temp_var_for_ext_23));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_23;
  }
  /* atan2(+-0,+-0) */

  double temp_var_for_ext_24;
  double temp_var_for_const_35;
  double temp_var_for_callexp_5;

  temp_var_for_callexp_5 = __ieee754_atan2(y, x);
  temp_var_for_ext_24 = temp_var_for_callexp_5;
  AssignD({(Addr)&temp_var_for_ext_24},
          (Addr) &(temp_var_for_const_35 = temp_var_for_callexp_5),
          "/home/shijia/Public/testprogram/e_atan2.c_e.c:305:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_24", (Addr)&temp_var_for_ext_24));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_24;
}

__typeof(__atan2) atan2 __attribute__((weak, alias("__atan2")));
#ifdef __NO_LONG_DOUBLE_MATH
__typeof(__atan2l) __atan2l __attribute__((alias("__atan2")));
__typeof(__atan2l) atan2l __attribute__((weak, alias("__atan2")));
#endif
