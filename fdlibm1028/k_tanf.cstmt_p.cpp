#include "../ScDebug/scdebug.h"
/* k_tanf.c -- float version of k_tan.c
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

float __kernel_tanf(float x, float y, int iy) {
  float z, r, v, w, s;
  int32_t ix, hx;

  static const float one = 1.0000000000e+00;    /* 0x3f800000 */
  static const float pio4 = 7.8539812565e-01;   /* 0x3f490fda */
  static const float pio4lo = 3.7748947079e-08; /* 0x33222168 */
  static const float T[] = {
    3.3333334327e-01, /* 0x3eaaaaab */
    1.3333334029e-01, /* 0x3e088889 */
    5.3968254477e-02, /* 0x3d5d0dd1 */
    2.1869488060e-02, /* 0x3cb327a4 */
    8.8632395491e-03, /* 0x3c11371f */
    3.5920790397e-03, /* 0x3b6b6916 */
    1.4562094584e-03, /* 0x3abede48 */
    5.8804126456e-04, /* 0x3a1a26c8 */
    2.4646313977e-04, /* 0x398137b9 */
    7.8179444245e-05, /* 0x38a3f445 */
    7.1407252108e-05, /* 0x3895c07a */
    (0.0 - 1.8558637748e-05);
  double temp_var_for_const_0, temp_var_for_const_1;
  ,                    /* 0xb79bae5f */
      2.5907305826e-05 /* 0x37d95384 */
};

GET_FLOAT_WORD(hx, x);
ix = hx & IC(0x7fffffff); /* high word of |x| */
if (ix < IC(0x31800000))  /* x < 2**-28 */
{
  if ((int32_t)x == 0) { /* generate inexact */
    if ((ix | (iy + 1)) == 0)
      return one / __ieee754_fabsf(x);
    else
      return (iy == 1) ? x : -one / x;
  }
}
if (ix >= IC(0x3f2ca140)) { /* |x|>=0.6744 */
  if (hx < 0) {
    x = -x;
    y = -y;
  }
  z = pio4 - x;
  w = pio4lo - y;
  x = z + w;
  y = 0.0;
  if (__ieee754_fabsf(x) < 0x1p-13f)
    return (1 - ((hx >> 30) & 2)) * iy * (1.0f - 2 * iy * x);
}
z = x * x;
float temp_var_for_tac_0;
computeFSub((Addr)&temp_var_for_tac_0,
            {(Addr) &(temp_var_for_const_1 = 0.0),
             (Addr) &(temp_var_for_const_0 = 1.8558637748e-05)},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:66:9");
computeFMul((Addr)&z, {(Addr)&x, (Addr)&x},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:66:5");
w = z * z;
computeFMul((Addr)&w, {(Addr)&z, (Addr)&z},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:67:5");
/* Break x^5*(T[1]+x^2*T[2]+...) into
 *    x^5(T[1]+x^4*T[3]+...+x^20*T[11]) +
 *    x^5(x^2*(T[2]+x^4*T[4]+...+x^22*[T12]))
 */
r = T[1] + w * (T[3] + w * (T[5] + w * (T[7] + w * (T[9] + w * T[11]))));
float temp_var_for_const_2, temp_var_for_const_3, temp_var_for_const_4,
    temp_var_for_const_5, temp_var_for_const_6, temp_var_for_const_7;
float temp_var_for_tac_1, temp_var_for_tac_2, temp_var_for_tac_3,
    temp_var_for_tac_4, temp_var_for_tac_5, temp_var_for_tac_6,
    temp_var_for_tac_7, temp_var_for_tac_8, temp_var_for_tac_9;
computeFMul((Addr)&temp_var_for_tac_1,
            {(Addr)&w, (Addr) &(temp_var_for_const_2 = T[11])},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:72:60");
computeFAdd((Addr)&temp_var_for_tac_2,
            {(Addr) &(temp_var_for_const_3 = T[9]), (Addr)&temp_var_for_tac_1},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:72:52");
computeFMul((Addr)&temp_var_for_tac_3, {(Addr)&w, (Addr)&temp_var_for_tac_2},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:72:48");
computeFAdd((Addr)&temp_var_for_tac_4,
            {(Addr) &(temp_var_for_const_4 = T[7]), (Addr)&temp_var_for_tac_3},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:72:40");
computeFMul((Addr)&temp_var_for_tac_5, {(Addr)&w, (Addr)&temp_var_for_tac_4},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:72:36");
computeFAdd((Addr)&temp_var_for_tac_6,
            {(Addr) &(temp_var_for_const_5 = T[5]), (Addr)&temp_var_for_tac_5},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:72:28");
computeFMul((Addr)&temp_var_for_tac_7, {(Addr)&w, (Addr)&temp_var_for_tac_6},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:72:24");
computeFAdd((Addr)&temp_var_for_tac_8,
            {(Addr) &(temp_var_for_const_6 = T[3]), (Addr)&temp_var_for_tac_7},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:72:16");
computeFMul((Addr)&temp_var_for_tac_9, {(Addr)&w, (Addr)&temp_var_for_tac_8},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:72:12");
computeFAdd((Addr)&r,
            {(Addr) &(temp_var_for_const_7 = T[1]), (Addr)&temp_var_for_tac_9},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:72:5");
v = z * (T[2] + w * (T[4] + w * (T[6] + w * (T[8] + w * (T[10] + w * T[12])))));
float temp_var_for_const_8, temp_var_for_const_9, temp_var_for_const_10,
    temp_var_for_const_11, temp_var_for_const_12, temp_var_for_const_13;
float temp_var_for_tac_10, temp_var_for_tac_11, temp_var_for_tac_12,
    temp_var_for_tac_13, temp_var_for_tac_14, temp_var_for_tac_15,
    temp_var_for_tac_16, temp_var_for_tac_17, temp_var_for_tac_18,
    temp_var_for_tac_19;
computeFMul((Addr)&temp_var_for_tac_10,
            {(Addr)&w, (Addr) &(temp_var_for_const_8 = T[12])},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:74:62");
computeFAdd((Addr)&temp_var_for_tac_11, {(Addr) &(temp_var_for_const_9 = T[10]),
                                         (Addr)&temp_var_for_tac_10},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:74:53");
computeFMul((Addr)&temp_var_for_tac_12, {(Addr)&w, (Addr)&temp_var_for_tac_11},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:74:49");
computeFAdd((Addr)&temp_var_for_tac_13, {(Addr) &(temp_var_for_const_10 = T[8]),
                                         (Addr)&temp_var_for_tac_12},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:74:41");
computeFMul((Addr)&temp_var_for_tac_14, {(Addr)&w, (Addr)&temp_var_for_tac_13},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:74:37");
computeFAdd((Addr)&temp_var_for_tac_15, {(Addr) &(temp_var_for_const_11 = T[6]),
                                         (Addr)&temp_var_for_tac_14},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:74:29");
computeFMul((Addr)&temp_var_for_tac_16, {(Addr)&w, (Addr)&temp_var_for_tac_15},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:74:25");
computeFAdd((Addr)&temp_var_for_tac_17, {(Addr) &(temp_var_for_const_12 = T[4]),
                                         (Addr)&temp_var_for_tac_16},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:74:17");
computeFMul((Addr)&temp_var_for_tac_18, {(Addr)&w, (Addr)&temp_var_for_tac_17},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:74:13");
computeFAdd((Addr)&temp_var_for_tac_19, {(Addr) &(temp_var_for_const_13 = T[2]),
                                         (Addr)&temp_var_for_tac_18},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:73:9");
computeFMul((Addr)&v, {(Addr)&z, (Addr)&temp_var_for_tac_19},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:73:5");
s = z * x;
computeFMul((Addr)&s, {(Addr)&z, (Addr)&x},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:75:5");
float temp_var_for_ext_0;
temp_var_for_ext_0 = y + z * (s * (r + v) + y);
float temp_var_for_tac_20, temp_var_for_tac_21, temp_var_for_tac_22,
    temp_var_for_tac_23;
computeFAdd((Addr)&temp_var_for_tac_20, {(Addr)&r, (Addr)&v},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:77:35");
computeFMul((Addr)&temp_var_for_tac_21, {(Addr)&s, (Addr)&temp_var_for_tac_20},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:77:45");
computeFAdd((Addr)&temp_var_for_tac_22, {(Addr)&temp_var_for_tac_21, (Addr)&y},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:77:30");
computeFMul((Addr)&temp_var_for_tac_23, {(Addr)&z, (Addr)&temp_var_for_tac_22},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:77:26");
computeFAdd((Addr)&temp_var_for_ext_0, {(Addr)&y, (Addr)&temp_var_for_tac_23},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:77:22"); // r
/*(x)(z)(y)(v)(r)(s)(z)(y)*/
r = temp_var_for_ext_0;
AssignF({(Addr)&r}, (Addr)&temp_var_for_ext_0,
        "/home/shijia/Public/testprogram/k_tanf.c_e.c:79:5");
r += T[0] * s;
float temp_var_for_const_14;
w = x + r;
float temp_var_for_tac_24;
computeFMul((Addr)&temp_var_for_tac_24,
            {(Addr) &(temp_var_for_const_14 = T[0]), (Addr)&s},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:81:9");
computeFAdd((Addr)&w, {(Addr)&x, (Addr)&r},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:81:5");
if (ix >= IC(0x3f2ca140)) {
  v = (float)iy;
  return (float)(1 - ((hx >> 30) & 2)) *
         (v - 2.0f * (x - (w * w / (w + v) - r)));
}
if (iy == 1) {
  float temp_var_for_ext_1;
  temp_var_for_ext_1 = w;
  AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&w,
          "/home/shijia/Public/testprogram/k_tanf.c_e.c:89:24");
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

else { /* if allow error up to 2 ulp,
          simply return -1.0/(x+r) here */
  /*  compute -1.0/(x+r) accurately */
  float a, t;
  int32_t i;

  z = w;
  AssignF({(Addr)&z}, (Addr)&w,
          "/home/shijia/Public/testprogram/k_tanf.c_e.c:101:7");
  GET_FLOAT_WORD(i, z);
  SET_FLOAT_WORD(z, i & UC(0xfffff000));
  v = r - (z - x);
  float temp_var_for_tac_25;
  computeFSub((Addr)&temp_var_for_tac_25, {(Addr)&z, (Addr)&x},
              "/home/shijia/Public/testprogram/k_tanf.c_e.c:104:11");
  computeFSub(
      (Addr)&v, {(Addr)&r, (Addr)&temp_var_for_tac_25},
      "/home/shijia/Public/testprogram/k_tanf.c_e.c:104:7"); /* z+v = r+x */
  t = a = (0.0 - 1.0f) / w;
  float temp_var_for_const_15, temp_var_for_const_16;
  float temp_var_for_tac_26;
  computeDSub((Addr)&temp_var_for_tac_26,
              {(Addr) &(temp_var_for_const_16 = 0.0),
               (Addr) &(temp_var_for_const_15 = 1.0f)},
              "/home/shijia/Public/testprogram/k_tanf.c_e.c:105:26");
  computeFDiv((Addr)&a, {(Addr)&temp_var_for_tac_26, (Addr)&w},
              "/home/shijia/Public/testprogram/k_tanf.c_e.c:105:11");
  AssignF(
      {(Addr)&t}, (Addr)&a,
      "/home/shijia/Public/testprogram/k_tanf.c_e.c:105:7"); /* a = -1.0/w */
  GET_FLOAT_WORD(i, t);
  SET_FLOAT_WORD(t, i & UC(0xfffff000));
  s = 1.0f + t * z;
  float temp_var_for_const_17;
  float temp_var_for_tac_27;
  computeFMul((Addr)&temp_var_for_tac_27, {(Addr)&t, (Addr)&z},
              "/home/shijia/Public/testprogram/k_tanf.c_e.c:108:14");
  computeFAdd((Addr)&s, {(Addr) &(temp_var_for_const_17 = 1.0f),
                         (Addr)&temp_var_for_tac_27},
              "/home/shijia/Public/testprogram/k_tanf.c_e.c:108:7");
  float temp_var_for_ext_2;
  temp_var_for_ext_2 = t + a * (s + t * v);
  float temp_var_for_tac_28, temp_var_for_tac_29, temp_var_for_tac_30;
  computeFMul((Addr)&temp_var_for_tac_28, {(Addr)&t, (Addr)&v},
              "/home/shijia/Public/testprogram/k_tanf.c_e.c:110:37");
  computeFAdd((Addr)&temp_var_for_tac_29,
              {(Addr)&s, (Addr)&temp_var_for_tac_28},
              "/home/shijia/Public/testprogram/k_tanf.c_e.c:110:32");
  computeFMul((Addr)&temp_var_for_tac_30,
              {(Addr)&a, (Addr)&temp_var_for_tac_29},
              "/home/shijia/Public/testprogram/k_tanf.c_e.c:110:28");
  computeFAdd((Addr)&temp_var_for_ext_2, {(Addr)&t, (Addr)&temp_var_for_tac_30},
              "/home/shijia/Public/testprogram/k_tanf.c_e.c:110:24");
  callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_2;
}
}
