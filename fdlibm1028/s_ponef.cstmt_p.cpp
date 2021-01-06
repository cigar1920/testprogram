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

float __j1_y1_ponef(float x) {
  const float *p, *q;
  float z, r, s;
  int32_t ix;

  static const float one = 1.0;

  /* For x >= 8, the asymptotic expansions of pone is
   *	1 + 15/128 s^2 - 4725/2^15 s^4 - ...,	where s = 1/x.
   * We approximate pone by
   *	pone(x) = 1 + (R/S)
   * where  R = pr0 + pr1*s^2 + pr2*s^4 + ... + pr5*s^10
   *	  S = 1 + ps0*s^2 + ... + ps4*s^10
   * and
   *	| pone(x)-1-R/S | <= 2  ** ( -60.06)
   */
  static const float pr8[6] = {
      /* for x in [inf, 8]=1/[0,0.125] */
      0.0000000000e+00, /* 0x00000000 */
      1.1718750000e-01, /* 0x3df00000 */
      1.3239480972e+01, /* 0x4153d4ea */
      4.1205184937e+02, /* 0x43ce06a3 */
      3.8747453613e+03, /* 0x45722bed */
      7.9144794922e+03  /* 0x45f753d6 */
  };

  static const float ps8[5] = {
      1.1420736694e+02, /* 0x42e46a2c */
      3.6509309082e+03, /* 0x45642ee5 */
      3.6956207031e+04, /* 0x47105c35 */
      9.7602796875e+04, /* 0x47bea166 */
      3.0804271484e+04  /* 0x46f0a88b */
  };

  static const float pr5[6] = {
      /* for x in [8,4.5454]=1/[0.125,0.22001] */
      1.3199052094e-11, /* 0x2d68333f */
      1.1718749255e-01, /* 0x3defffff */
      6.8027510643e+00, /* 0x40d9b023 */
      1.0830818176e+02, /* 0x42d89dca */
      5.1763616943e+02, /* 0x440168b7 */
      5.2871520996e+02  /* 0x44042dc6 */
  };

  static const float ps5[5] = {
      5.9280597687e+01, /* 0x426d1f55 */
      9.9140142822e+02, /* 0x4477d9b1 */
      5.3532670898e+03, /* 0x45a74a23 */
      7.8446904297e+03, /* 0x45f52586 */
      1.5040468750e+03  /* 0x44bc0180 */
  };

  static const float pr3[6] = {
      3.0250391081e-09, /* 0x314fe10d */
      1.1718686670e-01, /* 0x3defffab */
      3.9329774380e+00, /* 0x407bb5e7 */
      3.5119403839e+01, /* 0x420c7a45 */
      9.1055007935e+01, /* 0x42b61c2a */
      4.8559066772e+01  /* 0x42423c7c */
  };

  static const float ps3[5] = {
      3.4791309357e+01, /* 0x420b2a4d */
      3.3676245117e+02, /* 0x43a86198 */
      1.0468714600e+03, /* 0x4482dbe3 */
      8.9081134033e+02, /* 0x445eb3ed */
      1.0378793335e+02  /* 0x42cf936c */
  };

  static const float pr2[6] = {
      /* for x in [2.8570,2]=1/[0.3499,0.5] */
      1.0771083225e-07, /* 0x33e74ea8 */
      1.1717621982e-01, /* 0x3deffa16 */
      2.3685150146e+00, /* 0x401795c0 */
      1.2242610931e+01, /* 0x4143e1bc */
      1.7693971634e+01, /* 0x418d8d41 */
      5.0735230446e+00  /* 0x40a25a4d */
  };

  static const float ps2[5] = {
      2.1436485291e+01, /* 0x41ab7dec */
      1.2529022980e+02, /* 0x42fa9499 */
      2.3227647400e+02, /* 0x436846c7 */
      1.1767937469e+02, /* 0x42eb5bd7 */
      8.3646392822e+00  /* 0x4105d590 */
  };

  GET_FLOAT_WORD(ix, x);
  ix &= IC(0x7fffffff);
  if (ix >= IC(0x41000000)) {
    p = pr8;
    q = ps8;
  } else if (ix >= IC(0x40f71c58)) {
    p = pr5;
    q = ps5;
  } else if (ix >= IC(0x4036db68)) {
    p = pr3;
    q = ps3;
  } else /* if (ix >= IC(0x40000000)) */
  {
    p = pr2;
    q = ps2;
  }
  z = one / (x * x);
  float temp_var_for_const_0;
  float temp_var_for_tac_0;
  computeFMul((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&x},
              "/home/shijia/Public/testprogram/s_ponef.c_e.c:119:11");
  computeFDiv((Addr)&z,
              {(Addr) &(temp_var_for_const_0 = one), (Addr)&temp_var_for_tac_0},
              "/home/shijia/Public/testprogram/s_ponef.c_e.c:119:5");
  r = p[0] + z * (p[1] + z * (p[2] + z * (p[3] + z * (p[4] + z * p[5]))));
  float temp_var_for_const_1, temp_var_for_const_2, temp_var_for_const_3,
      temp_var_for_const_4, temp_var_for_const_5, temp_var_for_const_6;
  float temp_var_for_tac_1, temp_var_for_tac_2, temp_var_for_tac_3,
      temp_var_for_tac_4, temp_var_for_tac_5, temp_var_for_tac_6,
      temp_var_for_tac_7, temp_var_for_tac_8, temp_var_for_tac_9;
  computeFMul((Addr)&temp_var_for_tac_1,
              {(Addr)&z, (Addr) &(temp_var_for_const_1 = p[5])},
              "/home/shijia/Public/testprogram/s_ponef.c_e.c:120:60");
  computeFAdd((Addr)&temp_var_for_tac_2, {(Addr) &(temp_var_for_const_2 = p[4]),
                                          (Addr)&temp_var_for_tac_1},
              "/home/shijia/Public/testprogram/s_ponef.c_e.c:120:52");
  computeFMul((Addr)&temp_var_for_tac_3, {(Addr)&z, (Addr)&temp_var_for_tac_2},
              "/home/shijia/Public/testprogram/s_ponef.c_e.c:120:48");
  computeFAdd((Addr)&temp_var_for_tac_4, {(Addr) &(temp_var_for_const_3 = p[3]),
                                          (Addr)&temp_var_for_tac_3},
              "/home/shijia/Public/testprogram/s_ponef.c_e.c:120:40");
  computeFMul((Addr)&temp_var_for_tac_5, {(Addr)&z, (Addr)&temp_var_for_tac_4},
              "/home/shijia/Public/testprogram/s_ponef.c_e.c:120:36");
  computeFAdd((Addr)&temp_var_for_tac_6, {(Addr) &(temp_var_for_const_4 = p[2]),
                                          (Addr)&temp_var_for_tac_5},
              "/home/shijia/Public/testprogram/s_ponef.c_e.c:120:28");
  computeFMul((Addr)&temp_var_for_tac_7, {(Addr)&z, (Addr)&temp_var_for_tac_6},
              "/home/shijia/Public/testprogram/s_ponef.c_e.c:120:24");
  computeFAdd((Addr)&temp_var_for_tac_8, {(Addr) &(temp_var_for_const_5 = p[1]),
                                          (Addr)&temp_var_for_tac_7},
              "/home/shijia/Public/testprogram/s_ponef.c_e.c:120:16");
  computeFMul((Addr)&temp_var_for_tac_9, {(Addr)&z, (Addr)&temp_var_for_tac_8},
              "/home/shijia/Public/testprogram/s_ponef.c_e.c:120:12");
  computeFAdd((Addr)&r, {(Addr) &(temp_var_for_const_6 = p[0]),
                         (Addr)&temp_var_for_tac_9},
              "/home/shijia/Public/testprogram/s_ponef.c_e.c:120:5");
  s = one + z * (q[0] + z * (q[1] + z * (q[2] + z * (q[3] + z * q[4]))));
  float temp_var_for_const_7, temp_var_for_const_8, temp_var_for_const_9,
      temp_var_for_const_10, temp_var_for_const_11, temp_var_for_const_12;
  float temp_var_for_tac_10, temp_var_for_tac_11, temp_var_for_tac_12,
      temp_var_for_tac_13, temp_var_for_tac_14, temp_var_for_tac_15,
      temp_var_for_tac_16, temp_var_for_tac_17, temp_var_for_tac_18;
  computeFMul((Addr)&temp_var_for_tac_10,
              {(Addr)&z, (Addr) &(temp_var_for_const_7 = q[4])},
              "/home/shijia/Public/testprogram/s_ponef.c_e.c:121:59");
  computeFAdd(
      (Addr)&temp_var_for_tac_11,
      {(Addr) &(temp_var_for_const_8 = q[3]), (Addr)&temp_var_for_tac_10},
      "/home/shijia/Public/testprogram/s_ponef.c_e.c:121:51");
  computeFMul((Addr)&temp_var_for_tac_12,
              {(Addr)&z, (Addr)&temp_var_for_tac_11},
              "/home/shijia/Public/testprogram/s_ponef.c_e.c:121:47");
  computeFAdd(
      (Addr)&temp_var_for_tac_13,
      {(Addr) &(temp_var_for_const_9 = q[2]), (Addr)&temp_var_for_tac_12},
      "/home/shijia/Public/testprogram/s_ponef.c_e.c:121:39");
  computeFMul((Addr)&temp_var_for_tac_14,
              {(Addr)&z, (Addr)&temp_var_for_tac_13},
              "/home/shijia/Public/testprogram/s_ponef.c_e.c:121:35");
  computeFAdd(
      (Addr)&temp_var_for_tac_15,
      {(Addr) &(temp_var_for_const_10 = q[1]), (Addr)&temp_var_for_tac_14},
      "/home/shijia/Public/testprogram/s_ponef.c_e.c:121:27");
  computeFMul((Addr)&temp_var_for_tac_16,
              {(Addr)&z, (Addr)&temp_var_for_tac_15},
              "/home/shijia/Public/testprogram/s_ponef.c_e.c:121:23");
  computeFAdd(
      (Addr)&temp_var_for_tac_17,
      {(Addr) &(temp_var_for_const_11 = q[0]), (Addr)&temp_var_for_tac_16},
      "/home/shijia/Public/testprogram/s_ponef.c_e.c:121:15");
  computeFMul((Addr)&temp_var_for_tac_18,
              {(Addr)&z, (Addr)&temp_var_for_tac_17},
              "/home/shijia/Public/testprogram/s_ponef.c_e.c:121:11");
  computeFAdd((Addr)&s, {(Addr) &(temp_var_for_const_12 = one),
                         (Addr)&temp_var_for_tac_18},
              "/home/shijia/Public/testprogram/s_ponef.c_e.c:121:5");
  float temp_var_for_ext_0;
  temp_var_for_ext_0 = one + r / s;
  float temp_var_for_const_13;
  float temp_var_for_tac_19;
  computeFDiv((Addr)&temp_var_for_tac_19, {(Addr)&r, (Addr)&s},
              "/home/shijia/Public/testprogram/s_ponef.c_e.c:123:28");
  computeFAdd((Addr)&temp_var_for_ext_0, {(Addr) &(temp_var_for_const_13 = one),
                                          (Addr)&temp_var_for_tac_19},
              "/home/shijia/Public/testprogram/s_ponef.c_e.c:123:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

float __j1_y1_qonef(float x) {
  const float *p, *q;
  float s, r, z;
  int32_t ix;

  static const float one = 1.0;

  /* For x >= 8, the asymptotic expansions of qone is
   *	3/8 s - 105/1024 s^3 - ..., where s = 1/x.
   * We approximate qone by
   *	qone(x) = s*(0.375 + (R/S))
   * where  R = qr1*s^2 + qr2*s^4 + ... + qr5*s^10
   *	  S = 1 + qs1*s^2 + ... + qs6*s^12
   * and
   *	| qone(x)/s -0.375-R/S | <= 2  ** ( -61.13)
   */

  static const float qr8[6] = {
    /* for x in [inf, 8]=1/[0,0.125] */
    0.0000000000e+00, /* 0x00000000 */
    (0.0 - 1.0253906250e-01);
  double temp_var_for_const_14, temp_var_for_const_15;
  , /* 0xbdd20000 */
      (0.0 - 1.6271753311e+01);
  double temp_var_for_const_16, temp_var_for_const_17;
  double temp_var_for_tac_20;
  computeDSub((Addr)&temp_var_for_tac_20,
              {(Addr) &(temp_var_for_const_15 = 0.0),
               (Addr) &(temp_var_for_const_14 = 1.0253906250e-01)},
              "/home/shijia/Public/testprogram/s_ponef.c_e.c:150:12");
  , /* 0xc1822c8d */
      (0.0 - 7.5960174561e+02);
  double temp_var_for_const_18, temp_var_for_const_19;
  double temp_var_for_tac_21;
  computeDSub((Addr)&temp_var_for_tac_21,
              {(Addr) &(temp_var_for_const_17 = 0.0),
               (Addr) &(temp_var_for_const_16 = 1.6271753311e+01)},
              "/home/shijia/Public/testprogram/s_ponef.c_e.c:151:12");
  , /* 0xc43de683 */
      (0.0 - 1.1849806641e+04);
  double temp_var_for_const_20, temp_var_for_const_21;
  double temp_var_for_tac_22;
  computeDSub((Addr)&temp_var_for_tac_22,
              {(Addr) &(temp_var_for_const_19 = 0.0),
               (Addr) &(temp_var_for_const_18 = 7.5960174561e+02)},
              "/home/shijia/Public/testprogram/s_ponef.c_e.c:152:12");
  , /* 0xc639273a */
      (0.0 - 4.8438511719e+04);
  double temp_var_for_const_22, temp_var_for_const_23;
  double temp_var_for_tac_23;
  computeDSub(
      (Addr)&temp_var_for_tac_23,
      {(Addr) &(temp_var_for_const_21 = 0.0),
       (Addr) &(temp_var_for_const_20 = 1.1849806641e+04)},
      "/home/shijia/Public/testprogram/s_ponef.c_e.c:153:12"); /* 0xc73d3683 */
};

static const float qs8[6] = {
  1.6139537048e+02, /* 0x43216537 */
  7.8253862305e+03, /* 0x45f48b17 */
  1.3387534375e+05, /* 0x4802bcd6 */
  7.1965775000e+05, /* 0x492fb29c */
  6.6660125000e+05, /* 0x4922be94 */
  (0.0 - 2.9449025000e+05);
double temp_var_for_const_24, temp_var_for_const_25;
double temp_var_for_tac_24;
computeDSub(
    (Addr)&temp_var_for_tac_24,
    {(Addr) &(temp_var_for_const_23 = 0.0),
     (Addr) &(temp_var_for_const_22 = 4.8438511719e+04)},
    "/home/shijia/Public/testprogram/s_ponef.c_e.c:162:12"); /* 0xc88fcb48 */
}
;

static const float qr5[6] = {
  /* for x in [8,4.5454]=1/[0.125,0.22001] */
  (0.0 - 2.0897993405e-11);
double temp_var_for_const_26, temp_var_for_const_27;
double temp_var_for_tac_25;
computeDSub((Addr)&temp_var_for_tac_25,
            {(Addr) &(temp_var_for_const_25 = 0.0),
             (Addr) &(temp_var_for_const_24 = 2.9449025000e+05)},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:167:12");
, /* 0xadb7d219 */
    (0.0 - 1.0253904760e-01);
double temp_var_for_const_28, temp_var_for_const_29;
double temp_var_for_tac_26;
computeDSub((Addr)&temp_var_for_tac_26,
            {(Addr) &(temp_var_for_const_27 = 0.0),
             (Addr) &(temp_var_for_const_26 = 2.0897993405e-11)},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:168:12");
, /* 0xbdd1fffe */
    (0.0 - 8.0564479828e+00);
double temp_var_for_const_30, temp_var_for_const_31;
double temp_var_for_tac_27;
computeDSub((Addr)&temp_var_for_tac_27,
            {(Addr) &(temp_var_for_const_29 = 0.0),
             (Addr) &(temp_var_for_const_28 = 1.0253904760e-01)},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:169:12");
, /* 0xc100e736 */
    (0.0 - 1.8366960144e+02);
double temp_var_for_const_32, temp_var_for_const_33;
double temp_var_for_tac_28;
computeDSub((Addr)&temp_var_for_tac_28,
            {(Addr) &(temp_var_for_const_31 = 0.0),
             (Addr) &(temp_var_for_const_30 = 8.0564479828e+00)},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:170:12");
, /* 0xc337ab6b */
    (0.0 - 1.3731937256e+03);
double temp_var_for_const_34, temp_var_for_const_35;
double temp_var_for_tac_29;
computeDSub((Addr)&temp_var_for_tac_29,
            {(Addr) &(temp_var_for_const_33 = 0.0),
             (Addr) &(temp_var_for_const_32 = 1.8366960144e+02)},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:171:12");
, /* 0xc4aba633 */
    (0.0 - 2.6124443359e+03);
double temp_var_for_const_36, temp_var_for_const_37;
double temp_var_for_tac_30;
computeDSub(
    (Addr)&temp_var_for_tac_30,
    {(Addr) &(temp_var_for_const_35 = 0.0),
     (Addr) &(temp_var_for_const_34 = 1.3731937256e+03)},
    "/home/shijia/Public/testprogram/s_ponef.c_e.c:172:12"); /* 0xc523471c */
}
;

static const float qs5[6] = {
  8.1276550293e+01, /* 0x42a28d98 */
  1.9917987061e+03, /* 0x44f8f98f */
  1.7468484375e+04, /* 0x468878f8 */
  4.9851425781e+04, /* 0x4742bb6d */
  2.7948074219e+04, /* 0x46da5826 */
  (0.0 - 4.7191835938e+03);
double temp_var_for_const_38, temp_var_for_const_39;
double temp_var_for_tac_31;
computeDSub(
    (Addr)&temp_var_for_tac_31,
    {(Addr) &(temp_var_for_const_37 = 0.0),
     (Addr) &(temp_var_for_const_36 = 2.6124443359e+03)},
    "/home/shijia/Public/testprogram/s_ponef.c_e.c:181:12"); /* 0xc5937978 */
}
;

static const float qr3[6] = {(0.0 - 5.0783124372e-09);
double temp_var_for_const_40, temp_var_for_const_41;
double temp_var_for_tac_32;
computeDSub((Addr)&temp_var_for_tac_32,
            {(Addr) &(temp_var_for_const_39 = 0.0),
             (Addr) &(temp_var_for_const_38 = 4.7191835938e+03)},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:185:12");
, /* 0xb1ae7d4f */
    (0.0 - 1.0253783315e-01);
double temp_var_for_const_42, temp_var_for_const_43;
double temp_var_for_tac_33;
computeDSub((Addr)&temp_var_for_tac_33,
            {(Addr) &(temp_var_for_const_41 = 0.0),
             (Addr) &(temp_var_for_const_40 = 5.0783124372e-09)},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:186:12");
, /* 0xbdd1ff5b */
    (0.0 - 4.6101160049e+00);
double temp_var_for_const_44, temp_var_for_const_45;
double temp_var_for_tac_34;
computeDSub((Addr)&temp_var_for_tac_34,
            {(Addr) &(temp_var_for_const_43 = 0.0),
             (Addr) &(temp_var_for_const_42 = 1.0253783315e-01)},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:187:12");
, /* 0xc0938612 */
    (0.0 - 5.7847221375e+01);
double temp_var_for_const_46, temp_var_for_const_47;
double temp_var_for_tac_35;
computeDSub((Addr)&temp_var_for_tac_35,
            {(Addr) &(temp_var_for_const_45 = 0.0),
             (Addr) &(temp_var_for_const_44 = 4.6101160049e+00)},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:188:12");
, /* 0xc267638e */
    (0.0 - 2.2824453735e+02);
double temp_var_for_const_48, temp_var_for_const_49;
double temp_var_for_tac_36;
computeDSub((Addr)&temp_var_for_tac_36,
            {(Addr) &(temp_var_for_const_47 = 0.0),
             (Addr) &(temp_var_for_const_46 = 5.7847221375e+01)},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:189:12");
, /* 0xc3643e9a */
    (0.0 - 2.1921012878e+02);
double temp_var_for_const_50, temp_var_for_const_51;
double temp_var_for_tac_37;
computeDSub(
    (Addr)&temp_var_for_tac_37,
    {(Addr) &(temp_var_for_const_49 = 0.0),
     (Addr) &(temp_var_for_const_48 = 2.2824453735e+02)},
    "/home/shijia/Public/testprogram/s_ponef.c_e.c:190:12"); /* 0xc35b35cb */
}
;

static const float qs3[6] = {
  4.7665153503e+01, /* 0x423ea91e */
  6.7386511230e+02, /* 0x4428775e */
  3.3801528320e+03, /* 0x45534272 */
  5.5477290039e+03, /* 0x45ad5dd5 */
  1.9031191406e+03, /* 0x44ede3d0 */
  (0.0 - 1.3520118713e+02);
double temp_var_for_const_52, temp_var_for_const_53;
double temp_var_for_tac_38;
computeDSub(
    (Addr)&temp_var_for_tac_38,
    {(Addr) &(temp_var_for_const_51 = 0.0),
     (Addr) &(temp_var_for_const_50 = 2.1921012878e+02)},
    "/home/shijia/Public/testprogram/s_ponef.c_e.c:199:12"); /* 0xc3073381 */
}
;

static const float qr2[6] = {
  /* for x in [2.8570,2]=1/[0.3499,0.5] */
  (0.0 - 1.7838172539e-07);
double temp_var_for_const_54, temp_var_for_const_55;
double temp_var_for_tac_39;
computeDSub((Addr)&temp_var_for_tac_39,
            {(Addr) &(temp_var_for_const_53 = 0.0),
             (Addr) &(temp_var_for_const_52 = 1.3520118713e+02)},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:204:12");
, /* 0xb43f8932 */
    (0.0 - 1.0251704603e-01);
double temp_var_for_const_56, temp_var_for_const_57;
double temp_var_for_tac_40;
computeDSub((Addr)&temp_var_for_tac_40,
            {(Addr) &(temp_var_for_const_55 = 0.0),
             (Addr) &(temp_var_for_const_54 = 1.7838172539e-07)},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:205:12");
, /* 0xbdd1f475 */
    (0.0 - 2.7522056103e+00);
double temp_var_for_const_58, temp_var_for_const_59;
double temp_var_for_tac_41;
computeDSub((Addr)&temp_var_for_tac_41,
            {(Addr) &(temp_var_for_const_57 = 0.0),
             (Addr) &(temp_var_for_const_56 = 1.0251704603e-01)},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:206:12");
, /* 0xc0302423 */
    (0.0 - 1.9663616180e+01);
double temp_var_for_const_60, temp_var_for_const_61;
double temp_var_for_tac_42;
computeDSub((Addr)&temp_var_for_tac_42,
            {(Addr) &(temp_var_for_const_59 = 0.0),
             (Addr) &(temp_var_for_const_58 = 2.7522056103e+00)},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:207:12");
, /* 0xc19d4f16 */
    (0.0 - 4.2325313568e+01);
double temp_var_for_const_62, temp_var_for_const_63;
double temp_var_for_tac_43;
computeDSub((Addr)&temp_var_for_tac_43,
            {(Addr) &(temp_var_for_const_61 = 0.0),
             (Addr) &(temp_var_for_const_60 = 1.9663616180e+01)},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:208:12");
, /* 0xc2294d1f */
    (0.0 - 2.1371921539e+01);
double temp_var_for_const_64, temp_var_for_const_65;
double temp_var_for_tac_44;
computeDSub(
    (Addr)&temp_var_for_tac_44,
    {(Addr) &(temp_var_for_const_63 = 0.0),
     (Addr) &(temp_var_for_const_62 = 4.2325313568e+01)},
    "/home/shijia/Public/testprogram/s_ponef.c_e.c:209:12"); /* 0xc1aaf9b2 */
}
;

static const float qs2[6] = {
  2.9533363342e+01, /* 0x41ec4454 */
  2.5298155212e+02, /* 0x437cfb47 */
  7.5750280762e+02, /* 0x443d602e */
  7.3939318848e+02, /* 0x4438d92a */
  1.5594900513e+02, /* 0x431bf2f2 */
  (0.0 - 4.9594988823e+00);
double temp_var_for_const_66, temp_var_for_const_67;
double temp_var_for_tac_45;
computeDSub(
    (Addr)&temp_var_for_tac_45,
    {(Addr) &(temp_var_for_const_65 = 0.0),
     (Addr) &(temp_var_for_const_64 = 2.1371921539e+01)},
    "/home/shijia/Public/testprogram/s_ponef.c_e.c:218:12"); /* 0xc09eb437 */
}
;

GET_FLOAT_WORD(ix, x);
ix &= IC(0x7fffffff);
if (ix >= IC(0x40200000)) {
  p = qr8;
  q = qs8;
} else if (ix >= IC(0x40f71c58)) {
  p = qr5;
  q = qs5;
} else if (ix >= IC(0x4036db68)) {
  p = qr3;
  q = qs3;
} else /* if (ix >= IC(0x40000000)) */
{
  p = qr2;
  q = qs2;
}
float temp_var_for_ext_1;
temp_var_for_ext_1 = one / (x * x);
float temp_var_for_const_68;
float temp_var_for_tac_46, temp_var_for_tac_47;
computeFSub((Addr)&temp_var_for_tac_46,
            {(Addr) &(temp_var_for_const_67 = 0.0),
             (Addr) &(temp_var_for_const_66 = 4.9594988823e+00)},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:238:33");
computeFMul((Addr)&temp_var_for_tac_47, {(Addr)&x, (Addr)&x},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:238:28");
computeFDiv((Addr)&temp_var_for_ext_1,
            {(Addr) &(temp_var_for_const_68 = one), (Addr)&temp_var_for_tac_47},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:238:22"); // z
/*(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(2)(q[2])(z)(q)(1)(q[1])(z)(q)(0)(q[0])(z)(one)(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(2)(q[2])(z)(q)(1)(q[1])(z)(q)(0)(q[0])(z)(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(2)(q[2])(z)(q)(1)(q[1])(z)(q)(0)(q[0])(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(2)(q[2])(z)(q)(1)(q[1])(z)(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(2)(q[2])(z)(q)(1)(q[1])(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(2)(q[2])(z)(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(2)(q[2])(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(4)(q[4])(z)(q)(3)(q[3])(q)(4)(q[4])(z)(0)(e)(tem)(0)(e)(x)(x)(one)*/
z = temp_var_for_ext_1;
AssignF({(Addr)&z}, (Addr)&temp_var_for_ext_1,
        "/home/shijia/Public/testprogram/s_ponef.c_e.c:240:5");
r = p[0] + z * (p[1] + z * (p[2] + z * (p[3] + z * (p[4] + z * p[5]))));
float temp_var_for_const_69, temp_var_for_const_70, temp_var_for_const_71,
    temp_var_for_const_72, temp_var_for_const_73, temp_var_for_const_74;
float temp_var_for_tac_48, temp_var_for_tac_49, temp_var_for_tac_50,
    temp_var_for_tac_51, temp_var_for_tac_52, temp_var_for_tac_53,
    temp_var_for_tac_54, temp_var_for_tac_55, temp_var_for_tac_56;
computeFMul((Addr)&temp_var_for_tac_48,
            {(Addr)&z, (Addr) &(temp_var_for_const_69 = p[5])},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:241:60");
computeFAdd((Addr)&temp_var_for_tac_49, {(Addr) &(temp_var_for_const_70 = p[4]),
                                         (Addr)&temp_var_for_tac_48},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:241:52");
computeFMul((Addr)&temp_var_for_tac_50, {(Addr)&z, (Addr)&temp_var_for_tac_49},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:241:48");
computeFAdd((Addr)&temp_var_for_tac_51, {(Addr) &(temp_var_for_const_71 = p[3]),
                                         (Addr)&temp_var_for_tac_50},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:241:40");
computeFMul((Addr)&temp_var_for_tac_52, {(Addr)&z, (Addr)&temp_var_for_tac_51},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:241:36");
computeFAdd((Addr)&temp_var_for_tac_53, {(Addr) &(temp_var_for_const_72 = p[2]),
                                         (Addr)&temp_var_for_tac_52},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:241:28");
computeFMul((Addr)&temp_var_for_tac_54, {(Addr)&z, (Addr)&temp_var_for_tac_53},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:241:24");
computeFAdd((Addr)&temp_var_for_tac_55, {(Addr) &(temp_var_for_const_73 = p[1]),
                                         (Addr)&temp_var_for_tac_54},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:241:16");
computeFMul((Addr)&temp_var_for_tac_56, {(Addr)&z, (Addr)&temp_var_for_tac_55},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:241:12");
computeFAdd((Addr)&r, {(Addr) &(temp_var_for_const_74 = p[0]),
                       (Addr)&temp_var_for_tac_56},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:241:5");
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
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:243:65");
computeFAdd((Addr)&temp_var_for_tac_58, {(Addr) &(temp_var_for_const_76 = q[4]),
                                         (Addr)&temp_var_for_tac_57},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:243:57");
computeFMul((Addr)&temp_var_for_tac_59, {(Addr)&z, (Addr)&temp_var_for_tac_58},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:243:53");
computeFAdd((Addr)&temp_var_for_tac_60, {(Addr) &(temp_var_for_const_77 = q[3]),
                                         (Addr)&temp_var_for_tac_59},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:243:45");
computeFMul((Addr)&temp_var_for_tac_61, {(Addr)&z, (Addr)&temp_var_for_tac_60},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:243:41");
computeFAdd((Addr)&temp_var_for_tac_62, {(Addr) &(temp_var_for_const_78 = q[2]),
                                         (Addr)&temp_var_for_tac_61},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:243:33");
computeFMul((Addr)&temp_var_for_tac_63, {(Addr)&z, (Addr)&temp_var_for_tac_62},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:243:29");
computeFAdd((Addr)&temp_var_for_tac_64, {(Addr) &(temp_var_for_const_79 = q[1]),
                                         (Addr)&temp_var_for_tac_63},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:243:21");
computeFMul((Addr)&temp_var_for_tac_65, {(Addr)&z, (Addr)&temp_var_for_tac_64},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:243:17");
computeFAdd((Addr)&temp_var_for_tac_66, {(Addr) &(temp_var_for_const_80 = q[0]),
                                         (Addr)&temp_var_for_tac_65},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:243:9");
computeFMul((Addr)&temp_var_for_tac_67, {(Addr)&z, (Addr)&temp_var_for_tac_66},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:242:11");
computeFAdd((Addr)&s,
            {(Addr) &(temp_var_for_const_81 = one), (Addr)&temp_var_for_tac_67},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:242:5");
float temp_var_for_ext_2;
temp_var_for_ext_2 = (.375f + r / s) / x;
float temp_var_for_const_82;
float temp_var_for_tac_68, temp_var_for_tac_69;
computeFDiv((Addr)&temp_var_for_tac_68, {(Addr)&r, (Addr)&s},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:245:31");
computeFAdd((Addr)&temp_var_for_tac_69,
            {(Addr) &(temp_var_for_const_82 = .375f),
             (Addr)&temp_var_for_tac_68},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:245:40");
computeFDiv((Addr)&temp_var_for_ext_2, {(Addr)&temp_var_for_tac_69, (Addr)&x},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:245:22");
callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
callExp++; /*identify the function is  add move tmpShadow*/
return temp_var_for_ext_2;
}
