#include "../ScDebug/scdebug.h"
/* e_atan2l.c -- long double version of e_atan2.c.
 * Conversion to long double by Ulrich Drepper,
 * Cygnus Support, drepper@cygnus.com.
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

/* __ieee754_atan2l(y,x)
 * Method :
 *	1. Reduce y to positive by atan2(y,x)=-atan2(-y,x).
 *	2. Reduce x to positive by (if x and y are unexceptional):
 *		ARG (x+iy) = arctan(y/x)	   ... if x > 0,
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

#ifndef __NO_LONG_DOUBLE_MATH

#ifndef __have_fpu_atan2

long double __ieee754_atan2l(long double y, long double x) {
  long double z;
  int32_t k, m, hx, hy, ix, iy;
  uint32_t sx, sy, lx, ly;

  static const long double tiny = 1.0e-4900L;
  static const long double zero = 0.0;
  static const long double pi_o_4 =
      7.85398163397448309628202E-01L; /* 0x3FFE, 0xC90FDAA2, 0x2168C235 */
  static const long double pi_o_2 =
      1.5707963267948966192564E+00L; /* 0x3FFF, 0xC90FDAA2, 0x2168C235 */
  static const long double pi =
      3.14159265358979323851281E+00L; /* 0x4000, 0xC90FDAA2, 0x2168C235 */
  static const long double pi_lo =
      (long double temp_var_for_tac_0;
       long double temp_var_for_const_0, temp_var_for_const_1;
       temp_var_for_tac_0 = 0.0 - 5.01655761266833202345176e-20L;

       ); /* 0xBFBE, 0xECE675D1, 0xFC8F8CBB */

  long double temp_var_for_const_2;
  ew_u.value = x;
  computeLdSub(
      (Addr)&temp_var_for_tac_0,
      {(Addr) &(temp_var_for_const_1 = 0.0),
       (Addr) &(temp_var_for_const_0 = 5.01655761266833202345176e-20L)},
      "/home/shijia/Public/testprogram/e_atan2l.c_e.c:66:12");
  AssignLd({(Addr) &(temp_var_for_const_2 = ew_u.value)}, (Addr)&x,
           "/home/shijia/Public/testprogram/e_atan2l.c_e.c:69:3 "
           "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
  ;
  ix = sx & 0x7fff;
  lx |= hx & IC(0x7fffffff);
  long double temp_var_for_const_3;
  ew_u.value = y;
  AssignLd({(Addr) &(temp_var_for_const_3 = ew_u.value)}, (Addr)&y,
           "/home/shijia/Public/testprogram/e_atan2l.c_e.c:72:3 "
           "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
  ;
  iy = sy & 0x7fff;
  ly |= hy & IC(0x7fffffff);
  if (((2 * ix | ((lx | -lx) >> 31)) > UC(0xfffe)) ||
      ((2 * iy | ((ly | -ly) >> 31)) > UC(0xfffe))) /* x or y is NaN */
  {
    long double temp_var_for_ext_0;
    long double temp_var_for_tac_1;
    temp_var_for_tac_1 = x + y;

    temp_var_for_ext_0 = temp_var_for_tac_1;
    computeLdAdd((Addr)&temp_var_for_tac_1, {(Addr)&x, (Addr)&y},
                 "/home/shijia/Public/testprogram/e_atan2l.c_e.c:79:28");
    AssignLd({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_1,
             "/home/shijia/Public/testprogram/e_atan2l.c_e.c:79:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  if (((sx - 0x3fff) | lx) == 0) {
    long double temp_var_for_ext_1;
    long double temp_var_for_const_4;
    long double temp_var_for_callexp_0;

    temp_var_for_callexp_0 = __ieee754_atanl(y);
    temp_var_for_ext_1 = temp_var_for_callexp_0;
    AssignLd({(Addr)&temp_var_for_ext_1},
             (Addr) &(temp_var_for_const_4 = temp_var_for_callexp_0),
             "/home/shijia/Public/testprogram/e_atan2l.c_e.c:87:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }
  /* x=1.0 */
  m = ((sy >> 15) & 1) | ((sx >> 14) & 2); /* 2*sign(x)+sign(y) */

  /* when y = 0 */
  if ((iy | ly) == 0) {
    int temp_var_for_ext_2;
    temp_var_for_ext_2 = (int)m;
    switch (temp_var_for_ext_2) {
    case 0: {
    case 1: {
      long double temp_var_for_ext_3;
      temp_var_for_ext_3 = y;
      AssignLd({(Addr)&temp_var_for_ext_3}, (Addr)&y,
               "/home/shijia/Public/testprogram/e_atan2l.c_e.c:103:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_3;
    }
    }
    /* atan(+-0,+anything)=+-0 */
    case 2: {
      long double temp_var_for_ext_4;
      long double temp_var_for_tac_2;
      long double temp_var_for_const_5, temp_var_for_const_6;
      temp_var_for_tac_2 = pi + tiny;

      temp_var_for_ext_4 = temp_var_for_tac_2;
      computeLdAdd((Addr)&temp_var_for_tac_2,
                   {(Addr) &(temp_var_for_const_6 = pi),
                    (Addr) &(temp_var_for_const_5 = tiny)},
                   "/home/shijia/Public/testprogram/e_atan2l.c_e.c:113:31");
      AssignLd({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_2,
               "/home/shijia/Public/testprogram/e_atan2l.c_e.c:113:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_4;
    }
    /* atan(+0,-anything) = pi */
    case 3: {
      long double temp_var_for_ext_5;
      long double temp_var_for_tac_3;
      long double temp_var_for_const_7, temp_var_for_const_8;
      temp_var_for_tac_3 = (-(pi)) - tiny;

      temp_var_for_ext_5 = temp_var_for_tac_3;
      computeLdSub((Addr)&temp_var_for_tac_3,
                   {(Addr) &(temp_var_for_const_8 = (-(pi))),
                    (Addr) &(temp_var_for_const_7 = tiny)},
                   "/home/shijia/Public/testprogram/e_atan2l.c_e.c:122:32");
      AssignLd({(Addr)&temp_var_for_ext_5}, (Addr)&temp_var_for_tac_3,
               "/home/shijia/Public/testprogram/e_atan2l.c_e.c:122:26");
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
    long double temp_var_for_ext_6;
    long double temp_var_for_const_9;
    temp_var_for_ext_6 = (sy & 0x8000) ? -pi_o_2 - tiny : pi_o_2 + tiny;
    AssignLd({(Addr)&temp_var_for_ext_6},
             (Addr) &(temp_var_for_const_9 =
                          (sy & 0x8000) ? -pi_o_2 - tiny : pi_o_2 + tiny),
             "/home/shijia/Public/testprogram/e_atan2l.c_e.c:134:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
    callExp++; /*identify the function is  add move tmpShad(0.0 - w*/
re)turn temp_var_for_ext_6;
  }

  /* when x is INF */
  if (ix == 0x7fff) {
    if (iy == 0x7fff) {
      int temp_var_for_ext_7;
      temp_var_for_ext_7 = (int)m;
      switch (temp_var_for_ext_7) {
      case 0: {
        long double temp_var_for_ext_8;
        temp_var_for_ext_8 = long double temp_var_for_tac_4;
        long double temp_var_for_const_10, temp_var_for_const_11;
        temp_var_for_tac_4 = pi_o_4 + tiny;

        ;
        callExpStack.push(
            getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_8;
      }
      /* atan(+INF,+INF) */
      case 1: {
        long double temp_var_for_ext_9;
        long double temp_var_for_tac_5;
        long double temp_var_for_const_12, temp_var_for_const_13;
        temp_var_for_tac_5 = (-(pi_o_4)) - tiny;

        temp_var_for_ext_9 = temp_var_for_tac_5;
        computeLdAdd((Addr)&temp_var_for_tac_4,
                     {(Addr) &(temp_var_for_const_11 = pi_o_4),
                      (Addr) &(temp_var_for_const_10 = tiny)},
                     "/home/shijia/Public/testprogram/e_atan2l.c_e.c:148:37");
        computeLdSub((Addr)&temp_var_for_tac_5,
                     {(Addr) &(temp_var_for_const_13 = (-(pi_o_4))),
                      (Addr) &(temp_var_for_const_12 = tiny)},
                     "/home/shijia/Public/testprogram/e_atan2l.c_e.c:157:38");
        AssignLd({(Addr)&temp_var_for_ext_9}, (Addr)&temp_var_for_tac_5,
                 "/home/shijia/Public/testprogram/e_atan2l.c_e.c:157:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
        callExp++; /*identify the function is  add move tmpShadow*/
        return (0.0 - var_fo)r_ext_9;
      }
      /* atan(-INF,+INF) */
      case 2: {
        long double temp_var_for_ext_10;
        long double temp_var_for_tac_6, temp_var_for_tac_7;
        long double temp_var_for_const_14, temp_var_for_const_15,
            temp_var_for_const_16;
        temp_var_for_tac_6 = 3.0 * pi_o_4;

        temp_var_for_tac_7 = temp_var_for_tac_6 + tiny;

        temp_var_for_ext_10 = temp_var_for_tac_7;
        computeLdMul((Addr)&temp_var_for_tac_6,
                     {(Addr) &(temp_var_for_const_15 = 3.0),
                      (Addr) &(temp_var_for_const_14 = pi_o_4)},
                     "/home/shijia/Public/testprogram/e_atan2l.c_e.c:166:35");
        computeLdAdd(
            (Addr)&temp_var_for_tac_7,
            {(Addr)&temp_var_for_tac_6, (Addr) &(temp_var_for_const_16 = tiny)},
            "/home/shijia/Public/testprogram/e_atan2l.c_e.c:166:44");
        AssignLd({(Addr)&temp_var_for_ext_10}, (Addr)&temp_var_for_tac_7,
                 "/home/shijia/Public/testprogram/e_atan2l.c_e.c:166:29");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_10", (Addr)&temp_var_for_ext_10));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_10;
      }
      /*atan(+INF,-INF) */
      case 3: {
        long double temp_var_for_ext_11;
        long double temp_var_for_tac_8, temp_var_for_tac_9;
        long double temp_var_for_const_17, temp_var_for_const_18,
            temp_var_for_const_19;
        temp_var_for_tac_8 = (-(3.0)) * pi_o_4;

        temp_var_for_tac_9 = temp_var_for_tac_8 - tiny;

        temp_var_for_ext_11 = temp_var_for_tac_9;
        computeLdMul((Addr)&temp_var_for_tac_8,
                     {(Addr) &(temp_var_for_const_18 = (-(3.0))),
                      (Addr) &(temp_var_for_const_17 = pi_o_4)},
                     "/home/shijia/Public/testprogram/e_atan2l.c_e.c:175:36");
        computeLdSub(
            (Addr)&temp_var_for_tac_9,
            {(Addr)&temp_var_for_tac_8, (Addr) &(temp_var_for_const_19 = tiny)},
            "/home/shijia/Public/testprogram/e_atan2l.c_e.c:175:45");
        AssignLd({(Addr)&temp_var_for_ext_11}, (Addr)&temp_var_for_tac_9,
                 "/home/shijia/Public/testprogram/e_atan2l.c_e.c:175:29");
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
        long double temp_var_for_ext_13;
        long double temp_var_for_const_20;
        temp_var_for_ext_13 = zero;
        AssignLd({(Addr)&temp_var_for_ext_13},
                 (Addr) &(temp_var_for_const_20 = zero),
                 "/home/shijia/Public/testprogram/e_atan2l.c_e.c:189:29");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_13", (Addr)&temp_var_for_ext_13));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_13;
      }
      /* atan(+...,+INF) */
      case 1: {
        long double temp_var_for_ext_14;
        long double temp_var_for_const_21;
        temp_var_for_ext_14 = (-(zero));
        AssignLd({(Addr)&temp_var_for_ext_14},
                 (Addr) &(temp_var_for_const_21 = (-(zero))),
                 "/home/shijia/Public/testprogram/e_atan2l.c_e.c:198:29");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_14", (Addr)&temp_var_for_ext_14));
        callExp++; /*identify the function is  add move tmpShadow*/
        return (0.0 - t_14);
      }
      /* atan(-...,+INF) */
      case 2: {
        long double temp_var_for_ext_15;
        long double temp_var_for_tac_10;
        long double temp_var_for_const_22, temp_var_for_const_23;
        temp_var_for_tac_10 = pi + tiny;

        temp_var_for_ext_15 = temp_var_for_tac_10;
        computeLdAdd((Addr)&temp_var_for_tac_10,
                     {(Addr) &(temp_var_for_const_23 = pi),
                      (Addr) &(temp_var_for_const_22 = tiny)},
                     "/home/shijia/Public/testprogram/e_atan2l.c_e.c:207:34");
        AssignLd({(Addr)&temp_var_for_ext_15}, (Addr)&temp_var_for_tac_10,
                 "/home/shijia/Public/testprogram/e_atan2l.c_e.c:207:29");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_15", (Addr)&temp_var_for_ext_15));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_15;
      }
      /* atan(+...,-INF) */
      case 3: {
        long double temp_var_for_ext_16;
        long double temp_var_for_tac_11;
        long double temp_var_for_const_24, temp_var_for_const_25;
        temp_var_for_tac_11 = (-(pi)) - tiny;

        temp_var_for_ext_16 = temp_var_for_tac_11;
        computeLdSub((Addr)&temp_var_for_tac_11,
                     {(Addr) &(temp_var_for_const_25 = (-(pi))),
                      (Addr) &(temp_var_for_const_24 = tiny)},
                     "/home/shijia/Public/testprogram/e_atan2l.c_e.c:216:35");
        AssignLd({(Addr)&temp_var_for_ext_16}, (Addr)&temp_var_for_tac_11,
                 "/home/shijia/Public/testprogram/e_atan2l.c_e.c:216:29");
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
  if (iy == 0x7fff) {
    long double temp_var_for_ext_17;
    long double temp_var_for_const_26;
    temp_var_for_ext_17 = (sy & 0x8000) ? -pi_o_2 - tiny : pi_o_2 + tiny;
    AssignLd({(Addr)&temp_var_for_ext_17},
             (Addr) &(temp_var_for_const_26 =
                          (sy & 0x8000) ? -pi_o_2 - tiny : pi_o_2 + tiny),
             "/home/shijia/Public/testprogram/e_atan2l.c_e.c:229:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_17", (Addr)&temp_var_for_ext_17));
    callExp++; /*identify the function is  add move tmpShado(0.0 - */
ret)urn temp_var_for_ext_17;
  }

  /* compute y/x */
  k = iy - ix;
  if (k > 70) {
    z = long double temp_var_for_tac_12, temp_var_for_tac_13;
    long double temp_var_for_const_27, temp_var_for_const_28,
        temp_var_for_const_29;
    temp_var_for_tac_12 = 0.5L * pi_lo;

    temp_var_for_tac_13 = pi_o_2 + temp_var_for_tac_12;

    ;
  }
  /* |y/x| >  2**70 */
  else {
    if ((sx & 0x8000) && k < -70) {
      long double temp_var_for_const_30;
      z = 0.0;
      computeLdMul((Addr)&temp_var_for_tac_12,
                   {(Addr) &(temp_var_for_const_28 = 0.5L),
                    (Addr) &(temp_var_for_const_27 = pi_lo)},
                   "/home/shijia/Public/testprogram/e_atan2l.c_e.c:239:23");
      computeLdAdd((Addr)&temp_var_for_tac_13,
                   {(Addr) &(temp_var_for_const_29 = pi_o_2),
                    (Addr)&temp_var_for_tac_12},
                   "/home/shijia/Public/testprogram/e_atan2l.c_e.c:239:16");
      AssignLd({(Addr)&z}, (Addr) &(temp_var_for_const_30 = 0.0),
               "/home/shijia/Public/testprogram/e_atan2l.c_e.c:244:9");
      ;
    }
    /* |y|/x < -2**70 */
    else {
      long double temp_var_for_tac_14;
      long double temp_var_for_const_31;
      long double temp_var_for_callexp_1;

      /*embed fun has found*/
      long double temp_var_for_callexp_2;

      temp_var_for_tac_14 = y / x;

      temp_var_for_callexp_1 = fabsl(temp_var_for_tac_14);
      temp_var_for_callexp_2 = __ieee754_atanl(temp_var_for_callexp_1);
      z = temp_var_for_callexp_2;
      computeLdDiv((Addr)&temp_var_for_tac_14, {(Addr)&y, (Addr)&x},
                   "/home/shijia/Public/testprogram/e_atan2l.c_e.c:248:27 "
                   "<Spelling=/home/shijia/Public/testprogram/"
                   "e_atan2l.c_e.c:248:45>");
      AssignLd({(Addr)&z},
               (Addr) &(temp_var_for_const_31 = temp_var_for_callexp_2),
               "/home/shijia/Public/testprogram/e_atan2l.c_e.c:248:9");
      ;
    }
  }
  /* safe to do y/x */
  int temp_var_for_ext_18;
  temp_var_for_ext_18 = (int)m;
  switch (temp_var_for_ext_18) {
  case 0: {
    long double temp_var_for_ext_19;
    temp_var_for_ext_19 = z;
    AssignLd({(Addr)&temp_var_for_ext_19}, (Addr)&z,
             "/home/shijia/Public/testprogram/e_atan2l.c_e.c:257:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_19", (Addr)&temp_var_for_ext_19));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_19;
  }
  /* atan(+,+) */
  case 1: {
    uint32_t sz;

    long double temp_var_for_const_32;
    ge_u.value = z;
    AssignLd({(Addr) &(temp_var_for_const_32 = ge_u.value)}, (Addr)&z,
             "/home/shijia/Public/testprogram/e_atan2l.c_e.c:267:5 "
             "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:258:14>");
    ;
    long double temp_var_for_ext_20;
    temp_var_for_ext_20;
  }
    long double temp_var_for_ext_21;
    temp_var_for_ext_21 = z;
    AssignLd({(Addr)&temp_var_for_ext_21}, (Addr)&z,
             "/home/shijia/Public/testprogram/e_atan2l.c_e.c:272:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_21", (Addr)&temp_var_for_ext_21));
    callExp++;                  /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_21; /* atan(-,+) */
  case 2: {
    long double temp_var_for_ext_22;
    long double temp_var_for_tac_15, temp_var_for_tac_16;
    long double temp_var_for_const_33, temp_var_for_const_34;
    temp_var_for_tac_15 = z - pi_lo;

    temp_var_for_tac_16 = pi - temp_var_for_tac_15;

    temp_var_for_ext_22 = temp_var_for_tac_16;
    computeLdSub((Addr)&temp_var_for_tac_15,
                 {(Addr)&z, (Addr) &(temp_var_for_const_33 = pi_lo)},
                 "/home/shijia/Public/testprogram/e_atan2l.c_e.c:279:35");
    computeLdSub(
        (Addr)&temp_var_for_tac_16,
        {(Addr) &(temp_var_for_const_34 = pi), (Addr)&temp_var_for_tac_15},
        "/home/shijia/Public/testprogram/e_atan2l.c_e.c:279:30");
    AssignLd({(Addr)&temp_var_for_ext_22}, (Addr)&temp_var_for_tac_16,
             "/home/shijia/Public/testprogram/e_atan2l.c_e.c:279:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_22", (Addr)&temp_var_for_ext_22));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_22;
  }
  /* atan(+,-) */
  default: /* case 3 */
  {
    long double temp_var_for_ext_23;
    long double temp_var_for_tac_17, temp_var_for_tac_18;
    long double temp_var_for_const_35, temp_var_for_const_36;
    temp_var_for_tac_17 = z - pi_lo;

    temp_var_for_tac_18 = temp_var_for_tac_17 - pi;

    temp_var_for_ext_23 = temp_var_for_tac_18;
    computeLdSub((Addr)&temp_var_for_tac_17,
                 {(Addr)&z, (Addr) &(temp_var_for_const_35 = pi_lo)},
                 "/home/shijia/Public/testprogram/e_atan2l.c_e.c:289:30");
    computeLdSub(
        (Addr)&temp_var_for_tac_18,
        {(Addr)&temp_var_for_tac_17, (Addr) &(temp_var_for_const_36 = pi)},
        "/home/shijia/Public/testprogram/e_atan2l.c_e.c:289:39");
    AssignLd({(Addr)&temp_var_for_ext_23}, (Addr)&temp_var_for_tac_18,
             "/home/shijia/Public/testprogram/e_atan2l.c_e.c:289:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_23", (Addr)&temp_var_for_ext_23));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_23;
  }
    /* atan(-,-) */
  }
}

#endif

long double __atan2l(long double y, long double x) {
  if (int temp_var_for_tac_19; int temp_var_for_const_37;
      temp_var_for_tac_19 = x == 0.0;

      &&int temp_var_for_tac_20; int temp_var_for_const_38;
      temp_var_for_tac_20 = y == 0.0;

      &&_LIB_VERSION == _SVID_) {
    long double temp_var_for_ext_24;
    long double temp_var_for_const_39;
    long double temp_var_for_callexp_3;

    /*embed fun has found*/
    long double temp_var_for_callexp_4;

    temp_var_for_callexp_3 = __builtin_huge_vall();
    temp_var_for_callexp_4 =
        __kernel_standard_l(y, x, temp_var_for_callexp_3, KMATHERRL_ATAN2);
    temp_var_for_ext_24 = temp_var_for_callexp_4;
    compute((Addr)&temp_var_for_tac_19,
            {(Addr)&x, (Addr) &(temp_var_for_const_37 = 0.0)},
            "/home/shijia/Public/testprogram/e_atan2l.c_e.c:302:9");
    compute((Addr)&temp_var_for_tac_20,
            {(Addr)&y, (Addr) &(temp_var_for_const_38 = 0.0)},
            "/home/shijia/Public/testprogram/e_atan2l.c_e.c:302:21");
    AssignLd({(Addr)&temp_var_for_ext_24},
             (Addr) &(temp_var_for_const_39 = temp_var_for_callexp_4),
             "/home/shijia/Public/testprogram/e_atan2l.c_e.c:304:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_24", (Addr)&temp_var_for_ext_24));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_24;
  }
  /* atan2(+-0,+-0) */

  long double temp_var_for_ext_25;
  long double temp_var_for_const_40;
  long double temp_var_for_callexp_5;

  temp_var_for_callexp_5 = __ieee754_atan2l(y, x);
  temp_var_for_ext_25 = temp_var_for_callexp_5;
  AssignLd({(Addr)&temp_var_for_ext_25},
           (Addr) &(temp_var_for_const_40 = temp_var_for_callexp_5),
           "/home/shijia/Public/testprogram/e_atan2l.c_e.c:313:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_25", (Addr)&temp_var_for_ext_25));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_25;
}

__typeof(__atan2l) atan2l __attribute__((weak, alias("__atan2l")));

#endif
