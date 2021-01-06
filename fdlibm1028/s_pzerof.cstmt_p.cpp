#include "../ScDebug/scdebug.h"
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

float __j0_y0_pzerof(float x) {
  const float *p, *q;
  float z, r, s;
  int32_t ix;

  static const float one = 1.0;

  /* The asymptotic expansions of pzero is
   *	1 - 9/128 s^2 + 11025/98304 s^4 - ...,	where s = 1/x.
   * For x >= 2, We approximate pzero by
   *	pzero(x) = 1 + (R/S)
   * where  R = pR0 + pR1*s^2 + pR2*s^4 + ... + pR5*s^10
   *	  S = 1 + pS0*s^2 + ... + pS4*s^10
   * and
   *	| pzero(x)-1-R/S | <= 2  ** ( -60.26)
   */
  static const float pR8[6] = {
    /* for x in [inf, 8]=1/[0,0.125] */
    0.0000000000e+00, /* 0x00000000 */
    (0.0 - 7.0312500000e-02);
  double temp_var_for_const_0, temp_var_for_const_1;
  , /* 0xbd900000 */
      (0.0 - 8.0816707611e+00);
  double temp_var_for_const_2, temp_var_for_const_3;
  double temp_var_for_tac_0;
  computeDSub((Addr)&temp_var_for_tac_0,
              {(Addr) &(temp_var_for_const_1 = 0.0),
               (Addr) &(temp_var_for_const_0 = 7.0312500000e-02)},
              "/home/shijia/Public/testprogram/s_pzerof.c_e.c:36:12");
  , /* 0xc1014e86 */
      (0.0 - 2.5706311035e+02);
  double temp_var_for_const_4, temp_var_for_const_5;
  double temp_var_for_tac_1;
  computeDSub((Addr)&temp_var_for_tac_1,
              {(Addr) &(temp_var_for_const_3 = 0.0),
               (Addr) &(temp_var_for_const_2 = 8.0816707611e+00)},
              "/home/shijia/Public/testprogram/s_pzerof.c_e.c:37:12");
  , /* 0xc3808814 */
      (0.0 - 2.4852163086e+03);
  double temp_var_for_const_6, temp_var_for_const_7;
  double temp_var_for_tac_2;
  computeDSub((Addr)&temp_var_for_tac_2,
              {(Addr) &(temp_var_for_const_5 = 0.0),
               (Addr) &(temp_var_for_const_4 = 2.5706311035e+02)},
              "/home/shijia/Public/testprogram/s_pzerof.c_e.c:38:12");
  , /* 0xc51b5376 */
      (0.0 - 5.2530439453e+03);
  double temp_var_for_const_8, temp_var_for_const_9;
  double temp_var_for_tac_3;
  computeDSub(
      (Addr)&temp_var_for_tac_3,
      {(Addr) &(temp_var_for_const_7 = 0.0),
       (Addr) &(temp_var_for_const_6 = 2.4852163086e+03)},
      "/home/shijia/Public/testprogram/s_pzerof.c_e.c:39:12"); /* 0xc5a4285a */
};

static const float pS8[5] = {
    1.1653436279e+02, /* 0x42e91198 */
    3.8337448730e+03, /* 0x456f9beb */
    4.0597855469e+04, /* 0x471e95db */
    1.1675296875e+05, /* 0x47e4087c */
    4.7627726562e+04  /* 0x473a0bba */
};

static const float pR5[6] = {
  /* for x in [8,4.5454]=1/[0.125,0.22001] */
  (0.0 - 1.1412546255e-11);
double temp_var_for_const_10, temp_var_for_const_11;
double temp_var_for_tac_4;
computeDSub((Addr)&temp_var_for_tac_4,
            {(Addr) &(temp_var_for_const_9 = 0.0),
             (Addr) &(temp_var_for_const_8 = 5.2530439453e+03)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:52:12");
, /* 0xad48c58a */
    (0.0 - 7.0312492549e-02);
double temp_var_for_const_12, temp_var_for_const_13;
double temp_var_for_tac_5;
computeDSub((Addr)&temp_var_for_tac_5,
            {(Addr) &(temp_var_for_const_11 = 0.0),
             (Addr) &(temp_var_for_const_10 = 1.1412546255e-11)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:53:12");
, /* 0xbd8fffff */
    (0.0 - 4.1596107483e+00);
double temp_var_for_const_14, temp_var_for_const_15;
double temp_var_for_tac_6;
computeDSub((Addr)&temp_var_for_tac_6,
            {(Addr) &(temp_var_for_const_13 = 0.0),
             (Addr) &(temp_var_for_const_12 = 7.0312492549e-02)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:54:12");
, /* 0xc0851b88 */
    (0.0 - 6.7674766541e+01);
double temp_var_for_const_16, temp_var_for_const_17;
double temp_var_for_tac_7;
computeDSub((Addr)&temp_var_for_tac_7,
            {(Addr) &(temp_var_for_const_15 = 0.0),
             (Addr) &(temp_var_for_const_14 = 4.1596107483e+00)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:55:12");
, /* 0xc287597b */
    (0.0 - 3.3123129272e+02);
double temp_var_for_const_18, temp_var_for_const_19;
double temp_var_for_tac_8;
computeDSub((Addr)&temp_var_for_tac_8,
            {(Addr) &(temp_var_for_const_17 = 0.0),
             (Addr) &(temp_var_for_const_16 = 6.7674766541e+01)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:56:12");
, /* 0xc3a59d9b */
    (0.0 - 3.4643338013e+02);
double temp_var_for_const_20, temp_var_for_const_21;
double temp_var_for_tac_9;
computeDSub(
    (Addr)&temp_var_for_tac_9,
    {(Addr) &(temp_var_for_const_19 = 0.0),
     (Addr) &(temp_var_for_const_18 = 3.3123129272e+02)},
    "/home/shijia/Public/testprogram/s_pzerof.c_e.c:57:12"); /* 0xc3ad3779 */
}
;

static const float pS5[5] = {
    6.0753936768e+01, /* 0x42730408 */
    1.0512523193e+03, /* 0x44836813 */
    5.9789707031e+03, /* 0x45bad7c4 */
    9.6254453125e+03, /* 0x461665c8 */
    2.4060581055e+03  /* 0x451660ee */
};

static const float pR3[6] = {
  /* for x in [4.547,2.8571]=1/[0.2199,0.35001] */
  (0.0 - 2.5470459075e-09);
double temp_var_for_const_22, temp_var_for_const_23;
double temp_var_for_tac_10;
computeDSub((Addr)&temp_var_for_tac_10,
            {(Addr) &(temp_var_for_const_21 = 0.0),
             (Addr) &(temp_var_for_const_20 = 3.4643338013e+02)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:70:12");
, /* 0xb12f081b */
    (0.0 - 7.0311963558e-02);
double temp_var_for_const_24, temp_var_for_const_25;
double temp_var_for_tac_11;
computeDSub((Addr)&temp_var_for_tac_11,
            {(Addr) &(temp_var_for_const_23 = 0.0),
             (Addr) &(temp_var_for_const_22 = 2.5470459075e-09)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:71:12");
, /* 0xbd8fffb8 */
    (0.0 - 2.4090321064e+00);
double temp_var_for_const_26, temp_var_for_const_27;
double temp_var_for_tac_12;
computeDSub((Addr)&temp_var_for_tac_12,
            {(Addr) &(temp_var_for_const_25 = 0.0),
             (Addr) &(temp_var_for_const_24 = 7.0311963558e-02)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:72:12");
, /* 0xc01a2d95 */
    (0.0 - 2.1965976715e+01);
double temp_var_for_const_28, temp_var_for_const_29;
double temp_var_for_tac_13;
computeDSub((Addr)&temp_var_for_tac_13,
            {(Addr) &(temp_var_for_const_27 = 0.0),
             (Addr) &(temp_var_for_const_26 = 2.4090321064e+00)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:73:12");
, /* 0xc1afba52 */
    (0.0 - 5.8079170227e+01);
double temp_var_for_const_30, temp_var_for_const_31;
double temp_var_for_tac_14;
computeDSub((Addr)&temp_var_for_tac_14,
            {(Addr) &(temp_var_for_const_29 = 0.0),
             (Addr) &(temp_var_for_const_28 = 2.1965976715e+01)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:74:12");
, /* 0xc2685112 */
    (0.0 - 3.1447946548e+01);
double temp_var_for_const_32, temp_var_for_const_33;
double temp_var_for_tac_15;
computeDSub(
    (Addr)&temp_var_for_tac_15,
    {(Addr) &(temp_var_for_const_31 = 0.0),
     (Addr) &(temp_var_for_const_30 = 5.8079170227e+01)},
    "/home/shijia/Public/testprogram/s_pzerof.c_e.c:75:12"); /* 0xc1fb9565 */
}
;

static const float pS3[5] = {
    3.5856033325e+01, /* 0x420f6c94 */
    3.6151397705e+02, /* 0x43b4c1ca */
    1.1936077881e+03, /* 0x44953373 */
    1.1279968262e+03, /* 0x448cffe6 */
    1.7358093262e+02  /* 0x432d94b8 */
};

static const float pR2[6] = {
  /* for x in [2.8570,2]=1/[0.3499,0.5] */
  (0.0 - 8.8753431271e-08);
double temp_var_for_const_34, temp_var_for_const_35;
double temp_var_for_tac_16;
computeDSub((Addr)&temp_var_for_tac_16,
            {(Addr) &(temp_var_for_const_33 = 0.0),
             (Addr) &(temp_var_for_const_32 = 3.1447946548e+01)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:88:12");
, /* 0xb3be98b7 */
    (0.0 - 7.0303097367e-02);
double temp_var_for_const_36, temp_var_for_const_37;
double temp_var_for_tac_17;
computeDSub((Addr)&temp_var_for_tac_17,
            {(Addr) &(temp_var_for_const_35 = 0.0),
             (Addr) &(temp_var_for_const_34 = 8.8753431271e-08)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:89:12");
, /* 0xbd8ffb12 */
    (0.0 - 1.4507384300e+00);
double temp_var_for_const_38, temp_var_for_const_39;
double temp_var_for_tac_18;
computeDSub((Addr)&temp_var_for_tac_18,
            {(Addr) &(temp_var_for_const_37 = 0.0),
             (Addr) &(temp_var_for_const_36 = 7.0303097367e-02)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:90:12");
, /* 0xbfb9b1cc */
    (0.0 - 7.6356959343e+00);
double temp_var_for_const_40, temp_var_for_const_41;
double temp_var_for_tac_19;
computeDSub((Addr)&temp_var_for_tac_19,
            {(Addr) &(temp_var_for_const_39 = 0.0),
             (Addr) &(temp_var_for_const_38 = 1.4507384300e+00)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:91:12");
, /* 0xc0f4579f */
    (0.0 - 1.1193166733e+01);
double temp_var_for_const_42, temp_var_for_const_43;
double temp_var_for_tac_20;
computeDSub((Addr)&temp_var_for_tac_20,
            {(Addr) &(temp_var_for_const_41 = 0.0),
             (Addr) &(temp_var_for_const_40 = 7.6356959343e+00)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:92:12");
, /* 0xc1331736 */
    (0.0 - 3.2336456776e+00);
double temp_var_for_const_44, temp_var_for_const_45;
double temp_var_for_tac_21;
computeDSub(
    (Addr)&temp_var_for_tac_21,
    {(Addr) &(temp_var_for_const_43 = 0.0),
     (Addr) &(temp_var_for_const_42 = 1.1193166733e+01)},
    "/home/shijia/Public/testprogram/s_pzerof.c_e.c:93:12"); /* 0xc04ef40d */
}
;

static const float pS2[5] = {
    2.2220300674e+01, /* 0x41b1c32d */
    1.3620678711e+02, /* 0x430834f0 */
    2.7047027588e+02, /* 0x43873c32 */
    1.5387539673e+02, /* 0x4319e01a */
    1.4657617569e+01  /* 0x416a859a */
};

GET_FLOAT_WORD(ix, x);
ix &= IC(0x7fffffff);
if (ix >= IC(0x41000000)) {
  /* x >= 2**16 */
  p = pR8;
  q = pS8;
} else if (ix >= IC(0x40917458)) {
  /* x >= 4.545452117919921875 */
  p = pR5;
  q = pS5;
} else if (ix >= IC(0x4036db68)) {
  /* x >= 2.8571414947509765625 */
  p = pR3;
  q = pS3;
} else /* if (ix >= IC(0x40000000)) */
{
  /* x >= 2 */
  p = pR2;
  q = pS2;
}
z = one / (x * x);
float temp_var_for_const_46;
float temp_var_for_tac_22, temp_var_for_tac_23;
computeFSub((Addr)&temp_var_for_tac_22,
            {(Addr) &(temp_var_for_const_45 = 0.0),
             (Addr) &(temp_var_for_const_44 = 3.2336456776e+00)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:124:16");
computeFMul((Addr)&temp_var_for_tac_23, {(Addr)&x, (Addr)&x},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:124:11");
computeFDiv((Addr)&z,
            {(Addr) &(temp_var_for_const_46 = one), (Addr)&temp_var_for_tac_23},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:124:5");
r = p[0] + z * (p[1] + z * (p[2] + z * (p[3] + z * (p[4] + z * p[5]))));
float temp_var_for_const_47, temp_var_for_const_48, temp_var_for_const_49,
    temp_var_for_const_50, temp_var_for_const_51, temp_var_for_const_52;
float temp_var_for_tac_24, temp_var_for_tac_25, temp_var_for_tac_26,
    temp_var_for_tac_27, temp_var_for_tac_28, temp_var_for_tac_29,
    temp_var_for_tac_30, temp_var_for_tac_31, temp_var_for_tac_32;
computeFMul((Addr)&temp_var_for_tac_24,
            {(Addr)&z, (Addr) &(temp_var_for_const_47 = p[5])},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:125:60");
computeFAdd((Addr)&temp_var_for_tac_25, {(Addr) &(temp_var_for_const_48 = p[4]),
                                         (Addr)&temp_var_for_tac_24},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:125:52");
computeFMul((Addr)&temp_var_for_tac_26, {(Addr)&z, (Addr)&temp_var_for_tac_25},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:125:48");
computeFAdd((Addr)&temp_var_for_tac_27, {(Addr) &(temp_var_for_const_49 = p[3]),
                                         (Addr)&temp_var_for_tac_26},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:125:40");
computeFMul((Addr)&temp_var_for_tac_28, {(Addr)&z, (Addr)&temp_var_for_tac_27},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:125:36");
computeFAdd((Addr)&temp_var_for_tac_29, {(Addr) &(temp_var_for_const_50 = p[2]),
                                         (Addr)&temp_var_for_tac_28},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:125:28");
computeFMul((Addr)&temp_var_for_tac_30, {(Addr)&z, (Addr)&temp_var_for_tac_29},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:125:24");
computeFAdd((Addr)&temp_var_for_tac_31, {(Addr) &(temp_var_for_const_51 = p[1]),
                                         (Addr)&temp_var_for_tac_30},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:125:16");
computeFMul((Addr)&temp_var_for_tac_32, {(Addr)&z, (Addr)&temp_var_for_tac_31},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:125:12");
computeFAdd((Addr)&r, {(Addr) &(temp_var_for_const_52 = p[0]),
                       (Addr)&temp_var_for_tac_32},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:125:5");
s = one + z * (q[0] + z * (q[1] + z * (q[2] + z * (q[3] + z * q[4]))));
float temp_var_for_const_53, temp_var_for_const_54, temp_var_for_const_55,
    temp_var_for_const_56, temp_var_for_const_57, temp_var_for_const_58;
float temp_var_for_tac_33, temp_var_for_tac_34, temp_var_for_tac_35,
    temp_var_for_tac_36, temp_var_for_tac_37, temp_var_for_tac_38,
    temp_var_for_tac_39, temp_var_for_tac_40, temp_var_for_tac_41;
computeFMul((Addr)&temp_var_for_tac_33,
            {(Addr)&z, (Addr) &(temp_var_for_const_53 = q[4])},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:126:59");
computeFAdd((Addr)&temp_var_for_tac_34, {(Addr) &(temp_var_for_const_54 = q[3]),
                                         (Addr)&temp_var_for_tac_33},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:126:51");
computeFMul((Addr)&temp_var_for_tac_35, {(Addr)&z, (Addr)&temp_var_for_tac_34},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:126:47");
computeFAdd((Addr)&temp_var_for_tac_36, {(Addr) &(temp_var_for_const_55 = q[2]),
                                         (Addr)&temp_var_for_tac_35},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:126:39");
computeFMul((Addr)&temp_var_for_tac_37, {(Addr)&z, (Addr)&temp_var_for_tac_36},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:126:35");
computeFAdd((Addr)&temp_var_for_tac_38, {(Addr) &(temp_var_for_const_56 = q[1]),
                                         (Addr)&temp_var_for_tac_37},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:126:27");
computeFMul((Addr)&temp_var_for_tac_39, {(Addr)&z, (Addr)&temp_var_for_tac_38},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:126:23");
computeFAdd((Addr)&temp_var_for_tac_40, {(Addr) &(temp_var_for_const_57 = q[0]),
                                         (Addr)&temp_var_for_tac_39},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:126:15");
computeFMul((Addr)&temp_var_for_tac_41, {(Addr)&z, (Addr)&temp_var_for_tac_40},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:126:11");
computeFAdd((Addr)&s,
            {(Addr) &(temp_var_for_const_58 = one), (Addr)&temp_var_for_tac_41},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:126:5");
float temp_var_for_ext_0;
temp_var_for_ext_0 = one + r / s;
float temp_var_for_const_59;
float temp_var_for_tac_42;
computeFDiv((Addr)&temp_var_for_tac_42, {(Addr)&r, (Addr)&s},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:128:28");
computeFAdd((Addr)&temp_var_for_ext_0,
            {(Addr) &(temp_var_for_const_59 = one), (Addr)&temp_var_for_tac_42},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:128:22");
callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
callExp++; /*identify the function is  add move tmpShadow*/
return temp_var_for_ext_0;
}

float __j0_y0_qzerof(float x) {
  const float *p, *q;
  float s, r, z;
  int32_t ix;

  static const float one = 1.0;

  /* For x >= 8, the asymptotic expansions of qzero is
   *	-1/8 s + 75/1024 s^3 - ..., where s = 1/x.
   * We approximate qzero by
   *	qzero(x) = s*(-1.25 + (R/S))
   * where  R = qR0 + qR1*s^2 + qR2*s^4 + ... + qR5*s^10
   *	  S = 1 + qS0*s^2 + ... + qS5*s^12
   * and
   *	| qzero(x)/s +1.25-R/S | <= 2  ** ( -61.22)
   */
  static const float qR8[6] = {
      /* for x in [inf, 8]=1/[0,0.125] */
      0.0000000000e+00, /* 0x00000000 */
      7.3242187500e-02, /* 0x3d960000 */
      1.1768206596e+01, /* 0x413c4a93 */
      5.5767340088e+02, /* 0x440b6b19 */
      8.8591972656e+03, /* 0x460a6cca */
      3.7014625000e+04  /* 0x471096a0 */
  };

  static const float qS8[6] = {
    1.6377603149e+02, /* 0x4323c6aa */
    8.0983447266e+03, /* 0x45fd12c2 */
    1.4253829688e+05, /* 0x480b3293 */
    8.0330925000e+05, /* 0x49441ed4 */
    8.4050156250e+05, /* 0x494d3359 */
    (0.0 - 3.4389928125e+05);
  double temp_var_for_const_60, temp_var_for_const_61; /* 0xc8a7eb69 */
};

static const float qR5[6] = {
    /* for x in [8,4.5454]=1/[0.125,0.22001] */
    1.8408595828e-11, /* 0x2da1ec79 */
    7.3242180049e-02, /* 0x3d95ffff */
    5.8356351852e+00, /* 0x40babd86 */
    1.3511157227e+02, /* 0x43071c90 */
    1.0272437744e+03, /* 0x448067cd */
    1.9899779053e+03  /* 0x44f8bf4b */
};

static const float qS5[6] = {
  8.2776611328e+01, /* 0x42a58da0 */
  2.0778142090e+03, /* 0x4501dd07 */
  1.8847289062e+04, /* 0x46933e94 */
  5.6751113281e+04, /* 0x475daf1d */
  3.5976753906e+04, /* 0x470c88c1 */
  (0.0 - 5.3543427734e+03);
double temp_var_for_const_62, temp_var_for_const_63;
double temp_var_for_tac_43;
computeDSub(
    (Addr)&temp_var_for_tac_43,
    {(Addr) &(temp_var_for_const_61 = 0.0),
     (Addr) &(temp_var_for_const_60 = 3.4389928125e+05)},
    "/home/shijia/Public/testprogram/s_pzerof.c_e.c:185:12"); /* 0xc5a752be */
}
;

static const float qR3[6] = {
    /* for x in [4.547,2.8571]=1/[0.2199,0.35001] */
    4.3774099900e-09, /* 0x3196681b */
    7.3241114616e-02, /* 0x3d95ff70 */
    3.3442313671e+00, /* 0x405607e3 */
    4.2621845245e+01, /* 0x422a7cc5 */
    1.7080809021e+02, /* 0x432acedf */
    1.6673394775e+02  /* 0x4326bbe4 */
};

static const float qS3[6] = {
  4.8758872986e+01, /* 0x42430916 */
  7.0968920898e+02, /* 0x44316c1c */
  3.7041481934e+03, /* 0x4567825f */
  6.4604252930e+03, /* 0x45c9e367 */
  2.5163337402e+03, /* 0x451d4557 */
  (0.0 - 1.4924745178e+02);
double temp_var_for_const_64, temp_var_for_const_65;
double temp_var_for_tac_44;
computeDSub(
    (Addr)&temp_var_for_tac_44,
    {(Addr) &(temp_var_for_const_63 = 0.0),
     (Addr) &(temp_var_for_const_62 = 5.3543427734e+03)},
    "/home/shijia/Public/testprogram/s_pzerof.c_e.c:204:12"); /* 0xc3153f59 */
}
;

static const float qR2[6] = {
    /* for x in [2.8570,2]=1/[0.3499,0.5] */
    1.5044444979e-07, /* 0x342189db */
    7.3223426938e-02, /* 0x3d95f62a */
    1.9981917143e+00, /* 0x3fffc4bf */
    1.4495602608e+01, /* 0x4167edfd */
    3.1666231155e+01, /* 0x41fd5471 */
    1.6252708435e+01  /* 0x4182058c */
};

static const float qS2[6] = {
  3.0365585327e+01, /* 0x41f2ecb8 */
  2.6934811401e+02, /* 0x4386ac8f */
  8.4478375244e+02, /* 0x44533229 */
  8.8293585205e+02, /* 0x445cbbe5 */
  2.1266638184e+02, /* 0x4354aa98 */
  (0.0 - 5.3109550476e+00);
double temp_var_for_const_66, temp_var_for_const_67;
double temp_var_for_tac_45;
computeDSub(
    (Addr)&temp_var_for_tac_45,
    {(Addr) &(temp_var_for_const_65 = 0.0),
     (Addr) &(temp_var_for_const_64 = 1.4924745178e+02)},
    "/home/shijia/Public/testprogram/s_pzerof.c_e.c:223:12"); /* 0xc0a9f358 */
}
;

GET_FLOAT_WORD(ix, x);
ix &= IC(0x7fffffff);
if (ix >= IC(0x41000000)) {
  /* x >= 2**16 */
  p = qR8;
  q = qS8;
} else if (ix >= IC(0x40917458)) {
  /* x >= 4.545452117919921875 */
  /* x >= 4.54541015625 */
  p = qR5;
  q = qS5;
} else if (ix >= IC(0x4036db68)) {
  /* x >= 2.8571414947509765625 */
  p = qR3;
  q = qS3;
} else /* if (ix >= IC(0x40000000)) */
{
  /* x >= 2 */
  p = qR2;
  q = qS2;
}
float temp_var_for_ext_1;
temp_var_for_ext_1 = one / (x * x);
float temp_var_for_const_68;
float temp_var_for_tac_46, temp_var_for_tac_47;
computeFSub((Addr)&temp_var_for_tac_46,
            {(Addr) &(temp_var_for_const_67 = 0.0),
             (Addr) &(temp_var_for_const_66 = 5.3109550476e+00)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:248:33");
computeFMul((Addr)&temp_var_for_tac_47, {(Addr)&x, (Addr)&x},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:248:28");
computeFDiv((Addr)&temp_var_for_ext_1,
            {(Addr) &(temp_var_for_const_68 = one), (Addr)&temp_var_for_tac_47},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:248:22"); // z
/*(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(2)(q[2])(z)(q)(1)(q[1])(z)(q)(0)(q[0])(z)(one)(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(2)(q[2])(z)(q)(1)(q[1])(z)(q)(0)(q[0])(z)(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(2)(q[2])(z)(q)(1)(q[1])(z)(q)(0)(q[0])(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(2)(q[2])(z)(q)(1)(q[1])(z)(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(2)(q[2])(z)(q)(1)(q[1])(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(2)(q[2])(z)(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(2)(q[2])(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(4)(q[4])(z)(q)(3)(q[3])(q)(4)(q[4])(z)(0)(e)(tem)(0)(e)(x)(x)(one)*/
z = temp_var_for_ext_1;
AssignF({(Addr)&z}, (Addr)&temp_var_for_ext_1,
        "/home/shijia/Public/testprogram/s_pzerof.c_e.c:250:5");
r = p[0] + z * (p[1] + z * (p[2] + z * (p[3] + z * (p[4] + z * p[5]))));
float temp_var_for_const_69, temp_var_for_const_70, temp_var_for_const_71,
    temp_var_for_const_72, temp_var_for_const_73, temp_var_for_const_74;
float temp_var_for_tac_48, temp_var_for_tac_49, temp_var_for_tac_50,
    temp_var_for_tac_51, temp_var_for_tac_52, temp_var_for_tac_53,
    temp_var_for_tac_54, temp_var_for_tac_55, temp_var_for_tac_56;
computeFMul((Addr)&temp_var_for_tac_48,
            {(Addr)&z, (Addr) &(temp_var_for_const_69 = p[5])},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:251:60");
computeFAdd((Addr)&temp_var_for_tac_49, {(Addr) &(temp_var_for_const_70 = p[4]),
                                         (Addr)&temp_var_for_tac_48},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:251:52");
computeFMul((Addr)&temp_var_for_tac_50, {(Addr)&z, (Addr)&temp_var_for_tac_49},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:251:48");
computeFAdd((Addr)&temp_var_for_tac_51, {(Addr) &(temp_var_for_const_71 = p[3]),
                                         (Addr)&temp_var_for_tac_50},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:251:40");
computeFMul((Addr)&temp_var_for_tac_52, {(Addr)&z, (Addr)&temp_var_for_tac_51},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:251:36");
computeFAdd((Addr)&temp_var_for_tac_53, {(Addr) &(temp_var_for_const_72 = p[2]),
                                         (Addr)&temp_var_for_tac_52},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:251:28");
computeFMul((Addr)&temp_var_for_tac_54, {(Addr)&z, (Addr)&temp_var_for_tac_53},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:251:24");
computeFAdd((Addr)&temp_var_for_tac_55, {(Addr) &(temp_var_for_const_73 = p[1]),
                                         (Addr)&temp_var_for_tac_54},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:251:16");
computeFMul((Addr)&temp_var_for_tac_56, {(Addr)&z, (Addr)&temp_var_for_tac_55},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:251:12");
computeFAdd((Addr)&r, {(Addr) &(temp_var_for_const_74 = p[0]),
                       (Addr)&temp_var_for_tac_56},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:251:5");
s = one +
    z * (q[0] + z * (q[1] + z * (q[2] + z * (q[3] + z * (q[4] + z * q[5])))));
float temp_var_for_const_75, temp_var_for_const_76, temp_var_for_const_77,
    temp_var_for_const_78, temp_var_for_const_79, temp_var_for_const_80,
    temp_var_for_const_81;
float temp_var_for_tac_57, temp_var_for_tac_58, temp_var_for_tac_59,
    temp_var_for_tac_60, temp_var_for_tac_61, temp_var_for_tac_62,
    temp_var_for_tac_63, temp_var_for_tac_64, temp_var_for_tac_65,
    temp_var_for_tac_66, temp_var_for_tac_67;
computeFMul((Addr)&temp_var_for_tac_57,
            {(Addr)&z, (Addr) &(temp_var_for_const_75 = q[5])},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:253:65");
computeFAdd((Addr)&temp_var_for_tac_58, {(Addr) &(temp_var_for_const_76 = q[4]),
                                         (Addr)&temp_var_for_tac_57},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:253:57");
computeFMul((Addr)&temp_var_for_tac_59, {(Addr)&z, (Addr)&temp_var_for_tac_58},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:253:53");
computeFAdd((Addr)&temp_var_for_tac_60, {(Addr) &(temp_var_for_const_77 = q[3]),
                                         (Addr)&temp_var_for_tac_59},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:253:45");
computeFMul((Addr)&temp_var_for_tac_61, {(Addr)&z, (Addr)&temp_var_for_tac_60},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:253:41");
computeFAdd((Addr)&temp_var_for_tac_62, {(Addr) &(temp_var_for_const_78 = q[2]),
                                         (Addr)&temp_var_for_tac_61},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:253:33");
computeFMul((Addr)&temp_var_for_tac_63, {(Addr)&z, (Addr)&temp_var_for_tac_62},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:253:29");
computeFAdd((Addr)&temp_var_for_tac_64, {(Addr) &(temp_var_for_const_79 = q[1]),
                                         (Addr)&temp_var_for_tac_63},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:253:21");
computeFMul((Addr)&temp_var_for_tac_65, {(Addr)&z, (Addr)&temp_var_for_tac_64},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:253:17");
computeFAdd((Addr)&temp_var_for_tac_66, {(Addr) &(temp_var_for_const_80 = q[0]),
                                         (Addr)&temp_var_for_tac_65},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:253:9");
computeFMul((Addr)&temp_var_for_tac_67, {(Addr)&z, (Addr)&temp_var_for_tac_66},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:252:11");
computeFAdd((Addr)&s,
            {(Addr) &(temp_var_for_const_81 = one), (Addr)&temp_var_for_tac_67},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:252:5");
float temp_var_for_ext_2;
temp_var_for_ext_2 = (-.125f + r / s) / x;
float temp_var_for_tac_68, temp_var_for_tac_69;
computeFDiv((Addr)&temp_var_for_tac_68, {(Addr)&r, (Addr)&s},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:255:32");
computeFAdd((Addr)&temp_var_for_tac_69,
            {(Addr) & (-(.125f)), (Addr)&temp_var_for_tac_68},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:255:41");
computeFDiv((Addr)&temp_var_for_ext_2, {(Addr)&temp_var_for_tac_69, (Addr)&x},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:255:22");
callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
callExp++; /*identify the function is  add move tmpShadow*/
return (0.0 - temp_)var_for_ext_2;
}
