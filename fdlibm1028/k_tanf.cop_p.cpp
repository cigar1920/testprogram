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
      3.3333334327e-01,         /* 0x3eaaaaab */
      1.3333334029e-01,         /* 0x3e088889 */
      5.3968254477e-02,         /* 0x3d5d0dd1 */
      2.1869488060e-02,         /* 0x3cb327a4 */
      8.8632395491e-03,         /* 0x3c11371f */
      3.5920790397e-03,         /* 0x3b6b6916 */
      1.4562094584e-03,         /* 0x3abede48 */
      5.8804126456e-04,         /* 0x3a1a26c8 */
      2.4646313977e-04,         /* 0x398137b9 */
      7.8179444245e-05,         /* 0x38a3f445 */
      7.1407252108e-05,         /* 0x3895c07a */
      (double temp_var_for_tac_0;
  double temp_var_for_const_0, temp_var_for_const_1;
  temp_var_for_tac_0 = 0.0 - 1.8558637748e-05;

), /* 0xb79bae5f */
      2.5907305826e-05          /* 0x37d95384 */
};

GET_FLOAT_WORD(hx, x);
ix = hx & IC(0x7fffffff); /* high word of |x| */
if (ix < IC(0x31800000))  /* x < 2**-28 */
{
  if ((int32_t)x == 0) { /* generate inexact */
    if ((ix | (iy + 1)) == 0) {
      float temp_var_for_ext_0;
      float temp_var_for_tac_1;
      float temp_var_for_const_2, temp_var_for_const_3;
      float temp_var_for_callexp_0;

      temp_var_for_callexp_0 = fabsf(x);
      temp_var_for_tac_1 = one / temp_var_for_callexp_0;

      temp_var_for_ext_0 = temp_var_for_tac_1;
      computeDSub((Addr)&temp_var_for_tac_0,
                  {(Addr) &(temp_var_for_const_1 = 0.0),
                   (Addr) &(temp_var_for_const_0 = 1.8558637748e-05)},
                  "/home/shijia/Public/testprogram/k_tanf.c_e.c:39:12");
      computeFDiv((Addr)&temp_var_for_tac_1,
                  {(Addr) &(temp_var_for_const_3 = one),
                   (Addr) &(temp_var_for_const_2 = temp_var_for_callexp_0)},
                  "/home/shijia/Public/testprogram/k_tanf.c_e.c:50:34");
      AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_1,
              "/home/shijia/Public/testprogram/k_tanf.c_e.c:50:28");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_0;
    }

    else {
      float temp_var_for_ext_1;
      float temp_var_for_const_4;
      temp_var_for_ext_1 = (iy == 1) ? x : -one / x;
      AssignF({(Addr)&temp_var_for_ext_1},
              (Addr) &(temp_var_for_const_4 = (iy == 1) ? x : -one / x),
              "/home/shijia/Public/testprogram/k_tanf.c_e.c:59:28");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_f(0.0 - r_e) xt_1;
    }
  }
}
if (ix >= IC(0x3f2ca140)) { /* |x|>=0.6744 */
  if (hx < 0) {
    float temp_var_for_ext_2;
    temp_var_for_ext_2 =
        (double temp_var_for_tac_2; double temp_var_for_const_5;
         temp_var_for_tac_2 = 0.0 - x;

         ); // x
    /*(temp_var_for_ext_0)(tem)(1)(r_e)(r_e)(x)(x)*/
    x = temp_var_for_ext_2;
    computeDSub((Addr)&temp_var_for_tac_2,
                {(Addr) &(temp_var_for_const_5 = 0.0), (Addr)&x},
                "/home/shijia/Public/testprogram/k_tanf.c_e.c:70:33");
    AssignF({(Addr)&x}, (Addr)&temp_var_for_ext_2,
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:72:9");
    ;
    float temp_var_for_ext_3;
    float temp_var_for_tac_3;
    float temp_var_for_const_6;
    temp_var_for_tac_3 = 0.0 - y;

    temp_var_for_ext_3 = temp_var_for_tac_3;
    computeDSub((Addr)&temp_var_for_tac_3,
                {(Addr) &(temp_var_for_const_6 = 0.0), (Addr)&y},
                "/home/shijia/Public/testprogram/k_tanf.c_e.c:74:33");
    AssignF({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_3,
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:74:26");
    ; // y
    /*(y)(y)*/
    y = temp_var_for_ext_3;
    AssignF({(Addr)&y}, (Addr)&temp_var_for_ext_3,
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:76:9");
    ;
  }
  float temp_var_for_tac_4;
  float temp_var_for_const_7;
  temp_var_for_tac_4 = pio4 - x;

  z = temp_var_for_tac_4;
  computeFSub((Addr)&temp_var_for_tac_4,
              {(Addr) &(temp_var_for_const_7 = pio4), (Addr)&x},
              "/home/shijia/Public/testprogram/k_tanf.c_e.c:78:14");
  AssignF({(Addr)&z}, (Addr)&temp_var_for_tac_4,
          "/home/shijia/Public/testprogram/k_tanf.c_e.c:78:7");
  ;
  float temp_var_for_tac_5;
  float temp_var_for_const_8;
  temp_var_for_tac_5 = pio4lo - y;

  w = temp_var_for_tac_5;
  computeFSub((Addr)&temp_var_for_tac_5,
              {(Addr) &(temp_var_for_const_8 = pio4lo), (Addr)&y},
              "/home/shijia/Public/testprogram/k_tanf.c_e.c:79:16");
  AssignF({(Addr)&w}, (Addr)&temp_var_for_tac_5,
          "/home/shijia/Public/testprogram/k_tanf.c_e.c:79:7");
  ;
  float temp_var_for_tac_6;
  temp_var_for_tac_6 = z + w;

  x = temp_var_for_tac_6;
  computeFAdd((Addr)&temp_var_for_tac_6, {(Addr)&z, (Addr)&w},
              "/home/shijia/Public/testprogram/k_tanf.c_e.c:80:11");
  AssignF({(Addr)&x}, (Addr)&temp_var_for_tac_6,
          "/home/shijia/Public/testprogram/k_tanf.c_e.c:80:7");
  ;
  float temp_var_for_const_9;
  y = 0.0;
  AssignF({(Addr)&y}, (Addr) &(temp_var_for_const_9 = 0.0),
          "/home/shijia/Public/testprogram/k_tanf.c_e.c:81:7");
  ;
  if (int temp_var_for_tac_7; int temp_var_for_const_10, temp_var_for_const_11;
      float temp_var_for_callexp_1;

      temp_var_for_callexp_1 = fabsf(x);
      temp_var_for_tac_7 = temp_var_for_callexp_1 < 0x1p-13f;

      ) {
    float temp_var_for_ext_4;
    float temp_var_for_tac_8, temp_var_for_tac_9, temp_var_for_tac_10,
        temp_var_for_tac_11, temp_var_for_tac_12, temp_var_for_tac_13,
        temp_var_for_tac_14, temp_var_for_tac_15;
    float temp_var_for_const_12, temp_var_for_const_13, temp_var_for_const_14,
        temp_var_for_const_15, temp_var_for_const_16, temp_var_for_const_17,
        temp_var_for_const_18, temp_var_for_const_19;
    temp_var_for_tac_8 = hx >> 30;

    temp_var_for_tac_9 = temp_var_for_tac_8 & 2;

    temp_var_for_tac_10 = 1 - temp_var_for_tac_9;

    temp_var_for_tac_11 = temp_var_for_tac_10 * iy;

    temp_var_for_tac_12 = 2 * iy;

    temp_var_for_tac_13 = temp_var_for_tac_12 * x;

    temp_var_for_tac_14 = 1.0f - temp_var_for_tac_13;

    temp_var_for_tac_15 = temp_var_for_tac_11 * temp_var_for_tac_14;

    temp_var_for_ext_4 = temp_var_for_tac_15;
    compute((Addr)&temp_var_for_tac_7,
            {(Addr) &(temp_var_for_const_11 = temp_var_for_callexp_1),
             (Addr) &(temp_var_for_const_10 = 0x1p-13f)},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:82:28");
    compute((Addr)&temp_var_for_tac_8, {(Addr) &(temp_var_for_const_13 = hx),
                                        (Addr) &(temp_var_for_const_12 = 30)},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:84:38");
    compute((Addr)&temp_var_for_tac_9,
            {(Addr)&temp_var_for_tac_8, (Addr) &(temp_var_for_const_14 = 2)},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:84:45");
    computeSub((Addr)&temp_var_for_tac_10,
               {(Addr) &(temp_var_for_const_15 = 1), (Addr)&temp_var_for_tac_9},
               "/home/shijia/Public/testprogram/k_tanf.c_e.c:84:31");
    computeMul(
        (Addr)&temp_var_for_tac_11,
        {(Addr)&temp_var_for_tac_10, (Addr) &(temp_var_for_const_16 = iy)},
        "/home/shijia/Public/testprogram/k_tanf.c_e.c:84:51");
    computeMul((Addr)&temp_var_for_tac_12,
               {(Addr) &(temp_var_for_const_18 = 2),
                (Addr) &(temp_var_for_const_17 = iy)},
               "/home/shijia/Public/testprogram/k_tanf.c_e.c:84:68");
    computeFMul((Addr)&temp_var_for_tac_13,
                {(Addr)&temp_var_for_tac_12, (Addr)&x},
                "/home/shijia/Public/testprogram/k_tanf.c_e.c:84:73");
    computeFSub(
        (Addr)&temp_var_for_tac_14,
        {(Addr) &(temp_var_for_const_19 = 1.0f), (Addr)&temp_var_for_tac_13},
        "/home/shijia/Public/testprogram/k_tanf.c_e.c:84:64");
    computeFMul((Addr)&temp_var_for_tac_15,
                {(Addr)&temp_var_for_tac_11, (Addr)&temp_var_for_tac_14},
                "/home/shijia/Public/testprogram/k_tanf.c_e.c:84:56");
    AssignF({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_15,
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:84:26");
    ;
    callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_4;
  }
}
z = x * x;
w = z * z;
/* Break x^5*(T[1]+x^2*T[2]+...) into
 *    x^5(T[1]+x^4*T[3]+...+x^20*T[11]) +
 *    x^5(x^2*(T[2]+x^4*T[4]+...+x^22*[T12]))
 */
r = float temp_var_for_tac_16, temp_var_for_tac_17, temp_var_for_tac_18,
    temp_var_for_tac_19, temp_var_for_tac_20, temp_var_for_tac_21,
    temp_var_for_tac_22, temp_var_for_tac_23, temp_var_for_tac_24,
    temp_var_for_tac_25;
float temp_var_for_const_20, temp_var_for_const_21, temp_var_for_const_22,
    temp_var_for_const_23, temp_var_for_const_24, temp_var_for_const_25;
temp_var_for_tac_16 = w * T[11];

temp_var_for_tac_17 = T[9] + temp_var_for_tac_16;

temp_var_for_tac_18 = w * temp_var_for_tac_17;

temp_var_for_tac_19 = T[7] + temp_var_for_tac_18;

temp_var_for_tac_20 = w * temp_var_for_tac_19;

temp_var_for_tac_21 = T[5] + temp_var_for_tac_20;

temp_var_for_tac_22 = w * temp_var_for_tac_21;

temp_var_for_tac_23 = T[3] + temp_var_for_tac_22;

temp_var_for_tac_24 = w * temp_var_for_tac_23;

temp_var_for_tac_25 = T[1] + temp_var_for_tac_24;

;
float temp_var_for_tac_26, temp_var_for_tac_27, temp_var_for_tac_28,
    temp_var_for_tac_29, temp_var_for_tac_30, temp_var_for_tac_31,
    temp_var_for_tac_32, temp_var_for_tac_33, temp_var_for_tac_34,
    temp_var_for_tac_35, temp_var_for_tac_36;
float temp_var_for_const_26, temp_var_for_const_27, temp_var_for_const_28,
    temp_var_for_const_29, temp_var_for_const_30, temp_var_for_const_31;
temp_var_for_tac_26 = w * T[12];

temp_var_for_tac_27 = T[10] + temp_var_for_tac_26;

temp_var_for_tac_28 = w * temp_var_for_tac_27;

temp_var_for_tac_29 = T[8] + temp_var_for_tac_28;

temp_var_for_tac_30 = w * temp_var_for_tac_29;

temp_var_for_tac_31 = T[6] + temp_var_for_tac_30;

temp_var_for_tac_32 = w * temp_var_for_tac_31;

temp_var_for_tac_33 = T[4] + temp_var_for_tac_32;

temp_var_for_tac_34 = w * temp_var_for_tac_33;

temp_var_for_tac_35 = T[2] + temp_var_for_tac_34;

temp_var_for_tac_36 = z * temp_var_for_tac_35;

v = temp_var_for_tac_36;
computeFMul((Addr)&temp_var_for_tac_16,
            {(Addr)&w, (Addr) &(temp_var_for_const_20 = T[11])},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:97:64");
computeFAdd((Addr)&temp_var_for_tac_17, {(Addr) &(temp_var_for_const_21 = T[9]),
                                         (Addr)&temp_var_for_tac_16},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:97:60");
computeFMul((Addr)&temp_var_for_tac_18, {(Addr)&w, (Addr)&temp_var_for_tac_17},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:97:52");
computeFAdd((Addr)&temp_var_for_tac_19, {(Addr) &(temp_var_for_const_22 = T[7]),
                                         (Addr)&temp_var_for_tac_18},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:97:48");
computeFMul((Addr)&temp_var_for_tac_20, {(Addr)&w, (Addr)&temp_var_for_tac_19},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:97:40");
computeFAdd((Addr)&temp_var_for_tac_21, {(Addr) &(temp_var_for_const_23 = T[5]),
                                         (Addr)&temp_var_for_tac_20},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:97:36");
computeFMul((Addr)&temp_var_for_tac_22, {(Addr)&w, (Addr)&temp_var_for_tac_21},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:97:28");
computeFAdd((Addr)&temp_var_for_tac_23, {(Addr) &(temp_var_for_const_24 = T[3]),
                                         (Addr)&temp_var_for_tac_22},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:97:24");
computeFMul((Addr)&temp_var_for_tac_24, {(Addr)&w, (Addr)&temp_var_for_tac_23},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:97:16");
computeFAdd((Addr)&temp_var_for_tac_25, {(Addr) &(temp_var_for_const_25 = T[1]),
                                         (Addr)&temp_var_for_tac_24},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:97:12");
computeFMul((Addr)&temp_var_for_tac_26,
            {(Addr)&w, (Addr) &(temp_var_for_const_26 = T[12])},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:99:66");
computeFAdd((Addr)&temp_var_for_tac_27,
            {(Addr) &(temp_var_for_const_27 = T[10]),
             (Addr)&temp_var_for_tac_26},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:99:62");
computeFMul((Addr)&temp_var_for_tac_28, {(Addr)&w, (Addr)&temp_var_for_tac_27},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:99:53");
computeFAdd((Addr)&temp_var_for_tac_29, {(Addr) &(temp_var_for_const_28 = T[8]),
                                         (Addr)&temp_var_for_tac_28},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:99:49");
computeFMul((Addr)&temp_var_for_tac_30, {(Addr)&w, (Addr)&temp_var_for_tac_29},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:99:41");
computeFAdd((Addr)&temp_var_for_tac_31, {(Addr) &(temp_var_for_const_29 = T[6]),
                                         (Addr)&temp_var_for_tac_30},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:99:37");
computeFMul((Addr)&temp_var_for_tac_32, {(Addr)&w, (Addr)&temp_var_for_tac_31},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:99:29");
computeFAdd((Addr)&temp_var_for_tac_33, {(Addr) &(temp_var_for_const_30 = T[4]),
                                         (Addr)&temp_var_for_tac_32},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:99:25");
computeFMul((Addr)&temp_var_for_tac_34, {(Addr)&w, (Addr)&temp_var_for_tac_33},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:99:17");
computeFAdd((Addr)&temp_var_for_tac_35, {(Addr) &(temp_var_for_const_31 = T[2]),
                                         (Addr)&temp_var_for_tac_34},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:99:13");
computeFMul((Addr)&temp_var_for_tac_36, {(Addr)&z, (Addr)&temp_var_for_tac_35},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:98:9");
AssignF({(Addr)&v}, (Addr)&temp_var_for_tac_36,
        "/home/shijia/Public/testprogram/k_tanf.c_e.c:98:5");
;
float temp_var_for_tac_37;
temp_var_for_tac_37 = z * x;

s = temp_var_for_tac_37;
computeFMul((Addr)&temp_var_for_tac_37, {(Addr)&z, (Addr)&x},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:100:9");
AssignF({(Addr)&s}, (Addr)&temp_var_for_tac_37,
        "/home/shijia/Public/testprogram/k_tanf.c_e.c:100:5");
;
float temp_var_for_ext_5;
float temp_var_for_tac_38, temp_var_for_tac_39, temp_var_for_tac_40,
    temp_var_for_tac_41, temp_var_for_tac_42;
temp_var_for_tac_38 = r + v;

temp_var_for_tac_39 = s * temp_var_for_tac_38;

temp_var_for_tac_40 = temp_var_for_tac_39 + y;

temp_var_for_tac_41 = z * temp_var_for_tac_40;

temp_var_for_tac_42 = y + temp_var_for_tac_41;

temp_var_for_ext_5 = temp_var_for_tac_42;
computeFAdd((Addr)&temp_var_for_tac_38, {(Addr)&r, (Addr)&v},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:102:40");
computeFMul((Addr)&temp_var_for_tac_39, {(Addr)&s, (Addr)&temp_var_for_tac_38},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:102:35");
computeFAdd((Addr)&temp_var_for_tac_40, {(Addr)&temp_var_for_tac_39, (Addr)&y},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:102:45");
computeFMul((Addr)&temp_var_for_tac_41, {(Addr)&z, (Addr)&temp_var_for_tac_40},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:102:30");
computeFAdd((Addr)&temp_var_for_tac_42, {(Addr)&y, (Addr)&temp_var_for_tac_41},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:102:26");
AssignF({(Addr)&temp_var_for_ext_5}, (Addr)&temp_var_for_tac_42,
        "/home/shijia/Public/testprogram/k_tanf.c_e.c:102:22");
; // r
/*(x)(z)(y)(v)(r)(s)(z)(y)*/
r = temp_var_for_ext_5;
AssignF({(Addr)&r}, (Addr)&temp_var_for_ext_5,
        "/home/shijia/Public/testprogram/k_tanf.c_e.c:104:5");
;
float temp_var_for_tac_43;
float temp_var_for_const_32;
temp_var_for_tac_43 = T[0] * s;

r += temp_var_for_tac_43;
;
float temp_var_for_tac_45;
temp_var_for_tac_45 = x + r;

w = temp_var_for_tac_45;
computeFMul((Addr)&temp_var_for_tac_43,
            {(Addr) &(temp_var_for_const_32 = T[0]), (Addr)&s},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:105:13");
computeFAdd((Addr)&temp_var_for_tac_45, {(Addr)&x, (Addr)&r},
            "/home/shijia/Public/testprogram/k_tanf.c_e.c:106:9");
AssignF({(Addr)&w}, (Addr)&temp_var_for_tac_45,
        "/home/shijia/Public/testprogram/k_tanf.c_e.c:106:5");
;
if (ix >= IC(0x3f2ca140)) {
  float temp_var_for_const_33;
  v = ((float)iy);
  AssignF({(Addr)&v}, (Addr) &(temp_var_for_const_33 = ((float)iy)),
          "/home/shijia/Public/testprogram/k_tanf.c_e.c:108:7");
  ;
  float temp_var_for_ext_6;
  float temp_var_for_tac_46, temp_var_for_tac_47, temp_var_for_tac_48,
      temp_var_for_tac_49, temp_var_for_tac_50, temp_var_for_tac_51,
      temp_var_for_tac_52, temp_var_for_tac_53, temp_var_for_tac_54,
      temp_var_for_tac_55, temp_var_for_tac_56;
  float temp_var_for_const_34, temp_var_for_const_35, temp_var_for_const_36,
      temp_var_for_const_37, temp_var_for_const_38, temp_var_for_const_39;
  temp_var_for_tac_46 = hx >> 30;

  temp_var_for_tac_47 = temp_var_for_tac_46 & 2;

  temp_var_for_tac_48 = 1 - temp_var_for_tac_47;

  temp_var_for_tac_49 = w * w;

  temp_var_for_tac_50 = w + v;

  temp_var_for_tac_51 = temp_var_for_tac_49 / temp_var_for_tac_50;

  temp_var_for_tac_52 = temp_var_for_tac_51 - r;

  temp_var_for_tac_53 = x - temp_var_for_tac_52;

  temp_var_for_tac_54 = 2.0f * temp_var_for_tac_53;

  temp_var_for_tac_55 = v - temp_var_for_tac_54;

  temp_var_for_tac_56 = ((float)temp_var_for_tac_48) * temp_var_for_tac_55;

  temp_var_for_ext_6 = temp_var_for_tac_56;
  compute((Addr)&temp_var_for_tac_46, {(Addr) &(temp_var_for_const_35 = hx),
                                       (Addr) &(temp_var_for_const_34 = 30)},
          "/home/shijia/Public/testprogram/k_tanf.c_e.c:110:43");
  compute((Addr)&temp_var_for_tac_47,
          {(Addr)&temp_var_for_tac_46, (Addr) &(temp_var_for_const_36 = 2)},
          "/home/shijia/Public/testprogram/k_tanf.c_e.c:110:50");
  computeSub((Addr)&temp_var_for_tac_48,
             {(Addr) &(temp_var_for_const_37 = 1), (Addr)&temp_var_for_tac_47},
             "/home/shijia/Public/testprogram/k_tanf.c_e.c:110:36");
  computeFMul((Addr)&temp_var_for_tac_49, {(Addr)&w, (Addr)&w},
              "/home/shijia/Public/testprogram/k_tanf.c_e.c:111:46");
  computeFAdd((Addr)&temp_var_for_tac_50, {(Addr)&w, (Addr)&v},
              "/home/shijia/Public/testprogram/k_tanf.c_e.c:111:55");
  computeFDiv((Addr)&temp_var_for_tac_51,
              {(Addr)&temp_var_for_tac_49, (Addr)&temp_var_for_tac_50},
              "/home/shijia/Public/testprogram/k_tanf.c_e.c:111:50");
  computeFSub((Addr)&temp_var_for_tac_52,
              {(Addr)&temp_var_for_tac_51, (Addr)&r},
              "/home/shijia/Public/testprogram/k_tanf.c_e.c:111:60");
  computeFSub((Addr)&temp_var_for_tac_53,
              {(Addr)&x, (Addr)&temp_var_for_tac_52},
              "/home/shijia/Public/testprogram/k_tanf.c_e.c:111:41");
  computeFMul(
      (Addr)&temp_var_for_tac_54,
      {(Addr) &(temp_var_for_const_38 = 2.0f), (Addr)&temp_var_for_tac_53},
      "/home/shijia/Public/testprogram/k_tanf.c_e.c:111:36");
  computeFSub((Addr)&temp_var_for_tac_55,
              {(Addr)&v, (Addr)&temp_var_for_tac_54},
              "/home/shijia/Public/testprogram/k_tanf.c_e.c:111:29");
  computeFMul((Addr)&temp_var_for_tac_56,
              {(Addr) &(temp_var_for_const_39 = ((float)temp_var_for_tac_48)),
               (Addr)&temp_var_for_tac_55},
              "/home/shijia/Public/testprogram/k_tanf.c_e.c:110:56");
  AssignF({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_56,
          "/home/shijia/Public/testprogram/k_tanf.c_e.c:110:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_6;
}
if (iy == 1) {
  float temp_var_for_ext_7;
  temp_var_for_ext_7 = w;
  callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_7;
}

else { /* if allow error up to 2 ulp,
          simply return -1.0/(x+r) here */
  /*  compute -1.0/(x+r) accurately */
  float a, t;
  int32_t i;

  z = w;
  GET_FLOAT_WORD(i, z);
  SET_FLOAT_WORD(z, i & UC(0xfffff000));
  v = float temp_var_for_tac_57, temp_var_for_tac_58;
  temp_var_for_tac_57 = z - x;

  temp_var_for_tac_58 = r - temp_var_for_tac_57;

  ; /* z+v = r+x */
  float temp_var_for_tac_59, temp_var_for_tac_60;
  float temp_var_for_const_40, temp_var_for_const_41;
  temp_var_for_tac_59 = 0.0 - 1.0f;

  temp_var_for_tac_60 = temp_var_for_tac_59 / w;

  a = temp_var_for_tac_60;
  computeFSub((Addr)&temp_var_for_tac_57, {(Addr)&z, (Addr)&x},
              "/home/shijia/Public/testprogram/k_tanf.c_e.c:133:16");
  computeFSub((Addr)&temp_var_for_tac_58,
              {(Addr)&r, (Addr)&temp_var_for_tac_57},
              "/home/shijia/Public/testprogram/k_tanf.c_e.c:133:11");
  computeDSub((Addr)&temp_var_for_tac_59,
              {(Addr) &(temp_var_for_const_41 = 0.0),
               (Addr) &(temp_var_for_const_40 = 1.0f)},
              "/home/shijia/Public/testprogram/k_tanf.c_e.c:134:18");
  computeDDiv((Addr)&temp_var_for_tac_60,
              {(Addr)&temp_var_for_tac_59, (Addr)&w},
              "/home/shijia/Public/testprogram/k_tanf.c_e.c:134:26");
  AssignF({(Addr)&a}, (Addr)&temp_var_for_tac_60,
          "/home/shijia/Public/testprogram/k_tanf.c_e.c:134:11");
  t = a;
  AssignF({(Addr)&t}, (Addr)&a,
          "/home/shijia/Public/testprogram/k_tanf.c_e.c:134:7");
  ; /* a = -1.0/w */
  GET_FLOAT_WORD(i, t);
  SET_FLOAT_WORD(t, i & UC(0xfffff000));
  float temp_var_for_tac_61, temp_var_for_tac_62;
  float temp_var_for_const_42;
  temp_var_for_tac_61 = t * z;

  temp_var_for_tac_62 = 1.0f + temp_var_for_tac_61;

  s = temp_var_for_tac_62;
  computeFMul((Addr)&temp_var_for_tac_61, {(Addr)&t, (Addr)&z},
              "/home/shijia/Public/testprogram/k_tanf.c_e.c:137:18");
  computeFAdd(
      (Addr)&temp_var_for_tac_62,
      {(Addr) &(temp_var_for_const_42 = 1.0f), (Addr)&temp_var_for_tac_61},
      "/home/shijia/Public/testprogram/k_tanf.c_e.c:137:14");
  AssignF({(Addr)&s}, (Addr)&temp_var_for_tac_62,
          "/home/shijia/Public/testprogram/k_tanf.c_e.c:137:7");
  ;
  float temp_var_for_ext_8;
  float temp_var_for_tac_63, temp_var_for_tac_64, temp_var_for_tac_65,
      temp_var_for_tac_66;
  temp_var_for_tac_63 = t * v;

  temp_var_for_tac_64 = s + temp_var_for_tac_63;

  temp_var_for_tac_65 = a * temp_var_for_tac_64;

  temp_var_for_tac_66 = t + temp_var_for_tac_65;

  temp_var_for_ext_8 = temp_var_for_tac_66;
  computeFMul((Addr)&temp_var_for_tac_63, {(Addr)&t, (Addr)&v},
              "/home/shijia/Public/testprogram/k_tanf.c_e.c:139:41");
  computeFAdd((Addr)&temp_var_for_tac_64,
              {(Addr)&s, (Addr)&temp_var_for_tac_63},
              "/home/shijia/Public/testprogram/k_tanf.c_e.c:139:37");
  computeFMul((Addr)&temp_var_for_tac_65,
              {(Addr)&a, (Addr)&temp_var_for_tac_64},
              "/home/shijia/Public/testprogram/k_tanf.c_e.c:139:32");
  computeFAdd((Addr)&temp_var_for_tac_66,
              {(Addr)&t, (Addr)&temp_var_for_tac_65},
              "/home/shijia/Public/testprogram/k_tanf.c_e.c:139:28");
  AssignF({(Addr)&temp_var_for_ext_8}, (Addr)&temp_var_for_tac_66,
          "/home/shijia/Public/testprogram/k_tanf.c_e.c:139:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_8;
}
}
