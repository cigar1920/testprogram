#include "../ScDebug/scdebug.h"
/* @(#)s_atan.c 1.3 95/01/18 */
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

/* atan(x)
 * Method
 *   1. Reduce x to positive by atan(x) = -atan(-x).
 *   2. According to the integer k=4t+0.25 chopped, t=x, the argument
 *      is further reduced to one of the following intervals and the
 *      arctangent of t is evaluated by the corresponding formula:
 *
 *      [0,7/16]      atan(x) = t-t^3*(a1+t^2*(a2+...(a10+t^2*a11)...)
 *      [7/16,11/16]  atan(x) = atan(1/2) + atan( (t-0.5)/(1+t/2) )
 *      [11/16.19/16] atan(x) = atan( 1 ) + atan( (t-1)/(1+t) )
 *      [19/16,39/16] atan(x) = atan(3/2) + atan( (t-1.5)/(1+1.5t) )
 *      [39/16,INF]   atan(x) = atan(INF) + atan( -1/t )
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

#ifndef __have_fpu_atan

double __ieee754_atan(double x) {
  double w, s1, s2, z;
  int32_t ix, hx, id;

  static const double atanhi[] = {
      4.63647609000806093515e-01, /* atan(0.5)hi 0x3FDDAC67, 0x0561BB4F */
      7.85398163397448278999e-01, /* atan(1.0)hi 0x3FE921FB, 0x54442D18 */
      9.82793723247329054082e-01, /* atan(1.5)hi 0x3FEF730B, 0xD281F69B */
      1.57079632679489655800e+00  /* atan(inf)hi 0x3FF921FB, 0x54442D18 */
  };

  static const double atanlo[] = {
      2.26987774529616870924e-17, /* atan(0.5)lo 0x3C7A2B7F, 0x222F65E2 */
      3.06161699786838301793e-17, /* atan(1.0)lo 0x3C81A626, 0x33145C07 */
      1.39033110312309984516e-17, /* atan(1.5)lo 0x3C700788, 0x7AF0CBBD */
      6.12323399573676603587e-17  /* atan(inf)lo 0x3C91A626, 0x33145C07 */
  };

  static const double aT[] = {
    3.33333333333329318027e-01, /* 0x3FD55555, 0x5555550D */
    (0.0 - 1.99999999998764832476e-01);
  double temp_var_for_const_0, temp_var_for_const_1;
  ,                               /* 0xBFC99999, 0x9998EBC4 */
      1.42857142725034663711e-01, /* 0x3FC24924, 0x920083FF */
      (0.0 - 1.11111104054623557880e-01);
  double temp_var_for_const_2, temp_var_for_const_3;
  double temp_var_for_tac_0;
  computeDSub((Addr)&temp_var_for_tac_0,
              {(Addr) &(temp_var_for_const_1 = 0.0),
               (Addr) &(temp_var_for_const_0 = 1.99999999998764832476e-01)},
              "/home/shijia/Public/testprogram/s_atan.c_e.c:62:12");
  ,                               /* 0xBFBC71C6, 0xFE231671 */
      9.09088713343650656196e-02, /* 0x3FB745CD, 0xC54C206E */
      (0.0 - 7.69187620504482999495e-02);
  double temp_var_for_const_4, temp_var_for_const_5;
  double temp_var_for_tac_1;
  computeDSub((Addr)&temp_var_for_tac_1,
              {(Addr) &(temp_var_for_const_3 = 0.0),
               (Addr) &(temp_var_for_const_2 = 1.11111104054623557880e-01)},
              "/home/shijia/Public/testprogram/s_atan.c_e.c:64:12");
  ,                               /* 0xBFB3B0F2, 0xAF749A6D */
      6.66107313738753120669e-02, /* 0x3FB10D66, 0xA0D03D51 */
      (0.0 - 5.83357013379057348645e-02);
  double temp_var_for_const_6, temp_var_for_const_7;
  double temp_var_for_tac_2;
  computeDSub((Addr)&temp_var_for_tac_2,
              {(Addr) &(temp_var_for_const_5 = 0.0),
               (Addr) &(temp_var_for_const_4 = 7.69187620504482999495e-02)},
              "/home/shijia/Public/testprogram/s_atan.c_e.c:66:12");
  ,                               /* 0xBFADDE2D, 0x52DEFD9A */
      4.97687799461593236017e-02, /* 0x3FA97B4B, 0x24760DEB */
      (0.0 - 3.65315727442169155270e-02);
  double temp_var_for_const_8, temp_var_for_const_9;
  double temp_var_for_tac_3;
  computeDSub((Addr)&temp_var_for_tac_3,
              {(Addr) &(temp_var_for_const_7 = 0.0),
               (Addr) &(temp_var_for_const_6 = 5.83357013379057348645e-02)},
              "/home/shijia/Public/testprogram/s_atan.c_e.c:68:12");
  ,                              /* 0xBFA2B444, 0x2C6A6C2F */
      1.62858201153657823623e-02 /* 0x3F90AD3A, 0xE322DA11 */
};

static const double one = 1.0;
static const double hugeval = 1.0e300;

GET_HIGH_WORD(hx, x);
ix = hx & IC(0x7fffffff);
if (ix >= IC(0x44100000)) { /* if |x| >= 2^66 */
  uint32_t low;

  GET_LOW_WORD(low, x);
  if (ix > IC(0x7ff00000) || (ix == IC(0x7ff00000) && (low != 0)))
    return x + x; /* NaN */
  if (hx > 0)
    return atanhi[3] + atanlo[3];
  else
    return -atanhi[3] - atanlo[3];
}
if (ix < IC(0x3fdc0000)) {   /* |x| < 0.4375 */
  if (ix < IC(0x3e200000)) { /* |x| < 2^-29 */
    if (hugeval + x > one)
      return x; /* raise inexact */
  }
  id = -1;
} else {
  x = __ieee754_fabs(x);
  if (ix < IC(0x3ff30000)) {   /* |x| < 1.1875 */
    if (ix < IC(0x3fe60000)) { /* 7/16 <=|x|<11/16 */
      id = 0;
      x = (2.0 * x - one) / (2.0 + x);
    } else { /* 11/16<=|x|< 19/16 */
      id = 1;
      x = (x - one) / (x + one);
    }
  } else {
    if (ix < IC(0x40038000)) { /* |x| < 2.4375 */
      id = 2;
      x = (x - 1.5) / (one + 1.5 * x);
    } else { /* 2.4375 <= |x| < 2^66 */
      id = 3;
      x = -1.0 / x;
    }
  }
}
/* end of argument reduction */
z = x * x;
double temp_var_for_tac_4;
computeDSub((Addr)&temp_var_for_tac_4,
            {(Addr) &(temp_var_for_const_9 = 0.0),
             (Addr) &(temp_var_for_const_8 = 3.65315727442169155270e-02)},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:115:9");
computeDMul((Addr)&z, {(Addr)&x, (Addr)&x},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:115:5");
w = z * z;
computeDMul((Addr)&w, {(Addr)&z, (Addr)&z},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:116:5");
/* break sum from i=0 to 10 aT[i]z**(i+1) into odd and even poly */
s1 = z * (aT[0] +
          w * (aT[2] + w * (aT[4] + w * (aT[6] + w * (aT[8] + w * aT[10])))));
double temp_var_for_const_10, temp_var_for_const_11, temp_var_for_const_12,
    temp_var_for_const_13, temp_var_for_const_14, temp_var_for_const_15;
double temp_var_for_tac_5, temp_var_for_tac_6, temp_var_for_tac_7,
    temp_var_for_tac_8, temp_var_for_tac_9, temp_var_for_tac_10,
    temp_var_for_tac_11, temp_var_for_tac_12, temp_var_for_tac_13,
    temp_var_for_tac_14;
computeDMul((Addr)&temp_var_for_tac_5,
            {(Addr)&w, (Addr) &(temp_var_for_const_10 = aT[10])},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:119:63");
computeDAdd((Addr)&temp_var_for_tac_6, {(Addr) &(temp_var_for_const_11 = aT[8]),
                                        (Addr)&temp_var_for_tac_5},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:119:54");
computeDMul((Addr)&temp_var_for_tac_7, {(Addr)&w, (Addr)&temp_var_for_tac_6},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:119:50");
computeDAdd((Addr)&temp_var_for_tac_8, {(Addr) &(temp_var_for_const_12 = aT[6]),
                                        (Addr)&temp_var_for_tac_7},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:119:41");
computeDMul((Addr)&temp_var_for_tac_9, {(Addr)&w, (Addr)&temp_var_for_tac_8},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:119:37");
computeDAdd((Addr)&temp_var_for_tac_10,
            {(Addr) &(temp_var_for_const_13 = aT[4]),
             (Addr)&temp_var_for_tac_9},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:119:28");
computeDMul((Addr)&temp_var_for_tac_11, {(Addr)&w, (Addr)&temp_var_for_tac_10},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:119:24");
computeDAdd((Addr)&temp_var_for_tac_12,
            {(Addr) &(temp_var_for_const_14 = aT[2]),
             (Addr)&temp_var_for_tac_11},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:119:15");
computeDMul((Addr)&temp_var_for_tac_13, {(Addr)&w, (Addr)&temp_var_for_tac_12},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:118:19");
computeDAdd((Addr)&temp_var_for_tac_14,
            {(Addr) &(temp_var_for_const_15 = aT[0]),
             (Addr)&temp_var_for_tac_13},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:118:10");
computeDMul((Addr)&s1, {(Addr)&z, (Addr)&temp_var_for_tac_14},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:118:6");
s2 = w * (aT[1] + w * (aT[3] + w * (aT[5] + w * (aT[7] + w * aT[9]))));
double temp_var_for_const_16, temp_var_for_const_17, temp_var_for_const_18,
    temp_var_for_const_19, temp_var_for_const_20;
double temp_var_for_tac_15, temp_var_for_tac_16, temp_var_for_tac_17,
    temp_var_for_tac_18, temp_var_for_tac_19, temp_var_for_tac_20,
    temp_var_for_tac_21, temp_var_for_tac_22;
computeDMul((Addr)&temp_var_for_tac_15,
            {(Addr)&w, (Addr) &(temp_var_for_const_16 = aT[9])},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:120:58");
computeDAdd((Addr)&temp_var_for_tac_16,
            {(Addr) &(temp_var_for_const_17 = aT[7]),
             (Addr)&temp_var_for_tac_15},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:120:49");
computeDMul((Addr)&temp_var_for_tac_17, {(Addr)&w, (Addr)&temp_var_for_tac_16},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:120:45");
computeDAdd((Addr)&temp_var_for_tac_18,
            {(Addr) &(temp_var_for_const_18 = aT[5]),
             (Addr)&temp_var_for_tac_17},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:120:36");
computeDMul((Addr)&temp_var_for_tac_19, {(Addr)&w, (Addr)&temp_var_for_tac_18},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:120:32");
computeDAdd((Addr)&temp_var_for_tac_20,
            {(Addr) &(temp_var_for_const_19 = aT[3]),
             (Addr)&temp_var_for_tac_19},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:120:23");
computeDMul((Addr)&temp_var_for_tac_21, {(Addr)&w, (Addr)&temp_var_for_tac_20},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:120:19");
computeDAdd((Addr)&temp_var_for_tac_22,
            {(Addr) &(temp_var_for_const_20 = aT[1]),
             (Addr)&temp_var_for_tac_21},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:120:10");
computeDMul((Addr)&s2, {(Addr)&w, (Addr)&temp_var_for_tac_22},
            "/home/shijia/Public/testprogram/s_atan.c_e.c:120:6");
if (id < 0)
  return x - x * (s1 + s2);
else {
  z = atanhi[id] - ((x * (s1 + s2) - atanlo[id]) - x);
  return (hx < 0) ? -z : z;
}
}

#endif

double __atan(double x) {
  double temp_var_for_ext_0;
  temp_var_for_ext_0 = __ieee754_atan(x);
  double temp_var_for_callexp_0 =
      __ieee754_atan(getFVbyShadow<double>((Addr)&x));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_callexp_0,
          "/home/shijia/Public/testprogram/s_atan.c_e.c:133:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

__typeof(__atan) atan __attribute__((weak, alias("__atan")));
#ifdef __NO_LONG_DOUBLE_MATH
__typeof(__atanl) __atanl __attribute__((alias("__atan")));
__typeof(__atanl) atanl __attribute__((weak, alias("__atan")));
#endif
