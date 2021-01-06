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

double __j1_y1_pone(double x) {
  const double *p, *q;
  double z, r, s, r1, r2, r3, s1, s2, s3, z2, z4;
  int32_t ix;

  static const double one = 1.0;

  /* For x >= 8, the asymptotic expansions of pone is
   *	1 + 15/128 s^2 - 4725/2^15 s^4 - ...,	where s = 1/x.
   * We approximate pone by
   *	pone(x) = 1 + (R/S)
   * where  R = pr0 + pr1*s^2 + pr2*s^4 + ... + pr5*s^10
   *  S = 1 + ps0*s^2 + ... + ps4*s^10
   * and
   *	| pone(x)-1-R/S | <= 2  ** ( -60.06)
   */

  static const double pr8[6] = {
      /* for x in [inf, 8]=1/[0,0.125] */
      0.00000000000000000000e+00, /* 0x00000000, 0x00000000 */
      1.17187499999988647970e-01, /* 0x3FBDFFFF, 0xFFFFFCCE */
      1.32394806593073575129e+01, /* 0x402A7A9D, 0x357F7FCE */
      4.12051854307378562225e+02, /* 0x4079C0D4, 0x652EA590 */
      3.87474538913960532227e+03, /* 0x40AE457D, 0xA3A532CC */
      7.91447954031891731574e+03  /* 0x40BEEA7A, 0xC32782DD */
  };

  static const double ps8[5] = {
      1.14207370375678408436e+02, /* 0x405C8D45, 0x8E656CAC */
      3.65093083420853463394e+03, /* 0x40AC85DC, 0x964D274F */
      3.69562060269033463555e+04, /* 0x40E20B86, 0x97C5BB7F */
      9.76027935934950801311e+04, /* 0x40F7D42C, 0xB28F17BB */
      3.08042720627888811578e+04  /* 0x40DE1511, 0x697A0B2D */
  };

  static const double pr5[6] = {
      /* for x in [8,4.5454]=1/[0.125,0.22001] */
      1.31990519556243522749e-11, /* 0x3DAD0667, 0xDAE1CA7D */
      1.17187493190614097638e-01, /* 0x3FBDFFFF, 0xE2C10043 */
      6.80275127868432871736e+00, /* 0x401B3604, 0x6E6315E3 */
      1.08308182990189109773e+02, /* 0x405B13B9, 0x452602ED */
      5.17636139533199752805e+02, /* 0x40802D16, 0xD052D649 */
      5.28715201363337541807e+02  /* 0x408085B8, 0xBB7E0CB7 */
  };

  static const double ps5[5] = {
      5.92805987221131331921e+01, /* 0x404DA3EA, 0xA8AF633D */
      9.91401418733614377743e+02, /* 0x408EFB36, 0x1B066701 */
      5.35326695291487976647e+03, /* 0x40B4E944, 0x5706B6FB */
      7.84469031749551231769e+03, /* 0x40BEA4B0, 0xB8A5BB15 */
      1.50404688810361062679e+03  /* 0x40978030, 0x036F5E51 */
  };

  static const double pr3[6] = {
      3.02503916137373618024e-09, /* 0x3E29FC21, 0xA7AD9EDD */
      1.17186865567253592491e-01, /* 0x3FBDFFF5, 0x5B21D17B */
      3.93297750033315640650e+00, /* 0x400F76BC, 0xE85EAD8A */
      3.51194035591636932736e+01, /* 0x40418F48, 0x9DA6D129 */
      9.10550110750781271918e+01, /* 0x4056C385, 0x4D2C1837 */
      4.85590685197364919645e+01  /* 0x4048478F, 0x8EA83EE5 */
  };

  static const double ps3[5] = {
      3.47913095001251519989e+01, /* 0x40416549, 0xA134069C */
      3.36762458747825746741e+02, /* 0x40750C33, 0x07F1A75F */
      1.04687139975775130551e+03, /* 0x40905B7C, 0x5037D523 */
      8.90811346398256432622e+02, /* 0x408BD67D, 0xA32E31E9 */
      1.03787932439639277504e+02  /* 0x4059F26D, 0x7C2EED53 */
  };

  static const double pr2[6] = {
      /* for x in [2.8570,2]=1/[0.3499,0.5] */
      1.07710830106873743082e-07, /* 0x3E7CE9D4, 0xF65544F4 */
      1.17176219462683348094e-01, /* 0x3FBDFF42, 0xBE760D83 */
      2.36851496667608785174e+00, /* 0x4002F2B7, 0xF98FAEC0 */
      1.22426109148261232917e+01, /* 0x40287C37, 0x7F71A964 */
      1.76939711271687727390e+01, /* 0x4031B1A8, 0x177F8EE2 */
      5.07352312588818499250e+00  /* 0x40144B49, 0xA574C1FE */
  };

  static const double ps2[5] = {
      2.14364859363821409488e+01, /* 0x40356FBD, 0x8AD5ECDC */
      1.25290227168402751090e+02, /* 0x405F5293, 0x14F92CD5 */
      2.32276469057162813669e+02, /* 0x406D08D8, 0xD5A2DBD9 */
      1.17679373287147100768e+02, /* 0x405D6B7A, 0xDA1884A9 */
      8.36463893371618283368e+00  /* 0x4020BAB1, 0xF44E5192 */
  };

  GET_HIGH_WORD(ix, x);
  ix &= IC(0x7fffffff);
  if (ix >= IC(0x41b00000)) {
    return one;
  } else if (ix >= IC(0x40200000)) {
    p = pr8;
    q = ps8;
  } else if (ix >= IC(0x40122E8B)) {
    p = pr5;
    q = ps5;
  } else if (ix >= IC(0x4006DB6D)) {
    p = pr3;
    q = ps3;
  } else /* if (ix >= IC(0x40000000)) */
  {
    p = pr2;
    q = ps2;
  }
  z = one / (x * x);
  double temp_var_for_const_0;
  double temp_var_for_tac_0;
  computeDMul((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&x},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:122:11");
  computeDDiv((Addr)&z,
              {(Addr) &(temp_var_for_const_0 = one), (Addr)&temp_var_for_tac_0},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:122:5");
#ifdef DO_NOT_USE_THIS
  r = p[0] + z * (p[1] + z * (p[2] + z * (p[3] + z * (p[4] + z * p[5]))));
  s = one + z * (q[0] + z * (q[1] + z * (q[2] + z * (q[3] + z * q[4]))));
#else
  r1 = p[0] + z * p[1];
  double temp_var_for_const_1, temp_var_for_const_2;
  double temp_var_for_tac_1;
  computeDMul((Addr)&temp_var_for_tac_1,
              {(Addr)&z, (Addr) &(temp_var_for_const_1 = p[1])},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:127:13");
  computeDAdd((Addr)&r1, {(Addr) &(temp_var_for_const_2 = p[0]),
                          (Addr)&temp_var_for_tac_1},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:127:6");
  z2 = z * z;
  computeDMul((Addr)&z2, {(Addr)&z, (Addr)&z},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:128:6");
  r2 = p[2] + z * p[3];
  double temp_var_for_const_3, temp_var_for_const_4;
  double temp_var_for_tac_2;
  computeDMul((Addr)&temp_var_for_tac_2,
              {(Addr)&z, (Addr) &(temp_var_for_const_3 = p[3])},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:129:13");
  computeDAdd((Addr)&r2, {(Addr) &(temp_var_for_const_4 = p[2]),
                          (Addr)&temp_var_for_tac_2},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:129:6");
  z4 = z2 * z2;
  computeDMul((Addr)&z4, {(Addr)&z2, (Addr)&z2},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:130:6");
  r3 = p[4] + z * p[5];
  double temp_var_for_const_5, temp_var_for_const_6;
  double temp_var_for_tac_3;
  computeDMul((Addr)&temp_var_for_tac_3,
              {(Addr)&z, (Addr) &(temp_var_for_const_5 = p[5])},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:131:13");
  computeDAdd((Addr)&r3, {(Addr) &(temp_var_for_const_6 = p[4]),
                          (Addr)&temp_var_for_tac_3},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:131:6");
  r = r1 + z2 * r2 + z4 * r3;
  double temp_var_for_tac_4, temp_var_for_tac_5, temp_var_for_tac_6;
  computeDMul((Addr)&temp_var_for_tac_4, {(Addr)&z2, (Addr)&r2},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:132:10");
  computeDAdd((Addr)&temp_var_for_tac_5, {(Addr)&r1, (Addr)&temp_var_for_tac_4},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:132:25");
  computeDMul((Addr)&temp_var_for_tac_6, {(Addr)&z4, (Addr)&r3},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:132:20");
  computeDAdd((Addr)&r, {(Addr)&temp_var_for_tac_5, (Addr)&temp_var_for_tac_6},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:132:5");
  s1 = one + z * q[0];
  double temp_var_for_const_7, temp_var_for_const_8;
  double temp_var_for_tac_7;
  computeDMul((Addr)&temp_var_for_tac_7,
              {(Addr)&z, (Addr) &(temp_var_for_const_7 = q[0])},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:133:12");
  computeDAdd((Addr)&s1,
              {(Addr) &(temp_var_for_const_8 = one), (Addr)&temp_var_for_tac_7},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:133:6");
  s2 = q[1] + z * q[2];
  double temp_var_for_const_9, temp_var_for_const_10;
  double temp_var_for_tac_8;
  computeDMul((Addr)&temp_var_for_tac_8,
              {(Addr)&z, (Addr) &(temp_var_for_const_9 = q[2])},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:134:13");
  computeDAdd((Addr)&s2, {(Addr) &(temp_var_for_const_10 = q[1]),
                          (Addr)&temp_var_for_tac_8},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:134:6");
  s3 = q[3] + z * q[4];
  double temp_var_for_const_11, temp_var_for_const_12;
  double temp_var_for_tac_9;
  computeDMul((Addr)&temp_var_for_tac_9,
              {(Addr)&z, (Addr) &(temp_var_for_const_11 = q[4])},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:135:13");
  computeDAdd((Addr)&s3, {(Addr) &(temp_var_for_const_12 = q[3]),
                          (Addr)&temp_var_for_tac_9},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:135:6");
  s = s1 + z2 * s2 + z4 * s3;
  double temp_var_for_tac_10, temp_var_for_tac_11, temp_var_for_tac_12;
  computeDMul((Addr)&temp_var_for_tac_10, {(Addr)&z2, (Addr)&s2},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:136:10");
  computeDAdd((Addr)&temp_var_for_tac_11,
              {(Addr)&s1, (Addr)&temp_var_for_tac_10},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:136:25");
  computeDMul((Addr)&temp_var_for_tac_12, {(Addr)&z4, (Addr)&s3},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:136:20");
  computeDAdd((Addr)&s,
              {(Addr)&temp_var_for_tac_11, (Addr)&temp_var_for_tac_12},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:136:5");
#endif
  double temp_var_for_ext_0;
  temp_var_for_ext_0 = one + r / s;
  double temp_var_for_const_13;
  double temp_var_for_tac_13;
  computeDDiv((Addr)&temp_var_for_tac_13, {(Addr)&r, (Addr)&s},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:139:28");
  computeDAdd((Addr)&temp_var_for_ext_0, {(Addr) &(temp_var_for_const_13 = one),
                                          (Addr)&temp_var_for_tac_13},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:139:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

double __j1_y1_qone(double x) {
  const double *p, *q;
  double s, r, z, r1, r2, r3, s1, s2, s3, z2, z4, z6;
  int32_t ix;

  static const double one = 1.0;

  /* For x >= 8, the asymptotic expansions of qone is
   *	3/8 s - 105/1024 s^3 - ..., where s = 1/x.
   * We approximate qone by
   *	qone(x) = s*(0.375 + (R/S))
   * where  R = qr1*s^2 + qr2*s^4 + ... + qr5*s^10
   *  S = 1 + qs1*s^2 + ... + qs6*s^12
   * and
   *	| qone(x)/s -0.375-R/S | <= 2  ** ( -61.13)
   */

  static const double qr8[6] = {
    /* for x in [inf, 8]=1/[0,0.125] */
    0.00000000000000000000e+00, /* 0x00000000, 0x00000000 */
    (0.0 - 1.02539062499992714161e-01);
  double temp_var_for_const_14, temp_var_for_const_15;
  , /* 0xBFBA3FFF, 0xFFFFFDF3 */
      (0.0 - 1.62717534544589987888e+01);
  double temp_var_for_const_16, temp_var_for_const_17;
  double temp_var_for_tac_14;
  computeDSub((Addr)&temp_var_for_tac_14,
              {(Addr) &(temp_var_for_const_15 = 0.0),
               (Addr) &(temp_var_for_const_14 = 1.02539062499992714161e-01)},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:166:12");
  , /* 0xC0304591, 0xA26779F7 */
      (0.0 - 7.59601722513950107896e+02);
  double temp_var_for_const_18, temp_var_for_const_19;
  double temp_var_for_tac_15;
  computeDSub((Addr)&temp_var_for_tac_15,
              {(Addr) &(temp_var_for_const_17 = 0.0),
               (Addr) &(temp_var_for_const_16 = 1.62717534544589987888e+01)},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:167:12");
  , /* 0xC087BCD0, 0x53E4B576 */
      (0.0 - 1.18498066702429587167e+04);
  double temp_var_for_const_20, temp_var_for_const_21;
  double temp_var_for_tac_16;
  computeDSub((Addr)&temp_var_for_tac_16,
              {(Addr) &(temp_var_for_const_19 = 0.0),
               (Addr) &(temp_var_for_const_18 = 7.59601722513950107896e+02)},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:168:12");
  , /* 0xC0C724E7, 0x40F87415 */
      (0.0 - 4.84385124285750353010e+04);
  double temp_var_for_const_22, temp_var_for_const_23;
  double temp_var_for_tac_17;
  computeDSub(
      (Addr)&temp_var_for_tac_17,
      {(Addr) &(temp_var_for_const_21 = 0.0),
       (Addr) &(temp_var_for_const_20 = 1.18498066702429587167e+04)},
      "/home/shijia/Public/testprogram/s_pone.c_e.c:169:12"); /* 0xC0E7A6D0,
                                                                 0x65D09C6A */
};

static const double qs8[6] = {
  1.61395369700722909556e+02, /* 0x40642CA6, 0xDE5BCDE5 */
  7.82538599923348465381e+03, /* 0x40BE9162, 0xD0D88419 */
  1.33875336287249578163e+05, /* 0x4100579A, 0xB0B75E98 */
  7.19657723683240939863e+05, /* 0x4125F653, 0x72869C19 */
  6.66601232617776375264e+05, /* 0x412457D2, 0x7719AD5C */
  (0.0 - 2.94490264303834643215e+05);
double temp_var_for_const_24, temp_var_for_const_25;
double temp_var_for_tac_18;
computeDSub(
    (Addr)&temp_var_for_tac_18,
    {(Addr) &(temp_var_for_const_23 = 0.0),
     (Addr) &(temp_var_for_const_22 = 4.84385124285750353010e+04)},
    "/home/shijia/Public/testprogram/s_pone.c_e.c:178:12"); /* 0xC111F969,
                                                               0x0EA5AA18 */
}
;

static const double qr5[6] = {
  /* for x in [8,4.5454]=1/[0.125,0.22001] */
  (0.0 - 2.08979931141764104297e-11);
double temp_var_for_const_26, temp_var_for_const_27;
double temp_var_for_tac_19;
computeDSub((Addr)&temp_var_for_tac_19,
            {(Addr) &(temp_var_for_const_25 = 0.0),
             (Addr) &(temp_var_for_const_24 = 2.94490264303834643215e+05)},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:183:12");
, /* 0xBDB6FA43, 0x1AA1A098 */
    (0.0 - 1.02539050241375426231e-01);
double temp_var_for_const_28, temp_var_for_const_29;
double temp_var_for_tac_20;
computeDSub((Addr)&temp_var_for_tac_20,
            {(Addr) &(temp_var_for_const_27 = 0.0),
             (Addr) &(temp_var_for_const_26 = 2.08979931141764104297e-11)},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:184:12");
, /* 0xBFBA3FFF, 0xCB597FEF */
    (0.0 - 8.05644828123936029840e+00);
double temp_var_for_const_30, temp_var_for_const_31;
double temp_var_for_tac_21;
computeDSub((Addr)&temp_var_for_tac_21,
            {(Addr) &(temp_var_for_const_29 = 0.0),
             (Addr) &(temp_var_for_const_28 = 1.02539050241375426231e-01)},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:185:12");
, /* 0xC0201CE6, 0xCA03AD4B */
    (0.0 - 1.83669607474888380239e+02);
double temp_var_for_const_32, temp_var_for_const_33;
double temp_var_for_tac_22;
computeDSub((Addr)&temp_var_for_tac_22,
            {(Addr) &(temp_var_for_const_31 = 0.0),
             (Addr) &(temp_var_for_const_30 = 8.05644828123936029840e+00)},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:186:12");
, /* 0xC066F56D, 0x6CA7B9B0 */
    (0.0 - 1.37319376065508163265e+03);
double temp_var_for_const_34, temp_var_for_const_35;
double temp_var_for_tac_23;
computeDSub((Addr)&temp_var_for_tac_23,
            {(Addr) &(temp_var_for_const_33 = 0.0),
             (Addr) &(temp_var_for_const_32 = 1.83669607474888380239e+02)},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:187:12");
, /* 0xC09574C6, 0x6931734F */
    (0.0 - 2.61244440453215656817e+03);
double temp_var_for_const_36, temp_var_for_const_37;
double temp_var_for_tac_24;
computeDSub(
    (Addr)&temp_var_for_tac_24,
    {(Addr) &(temp_var_for_const_35 = 0.0),
     (Addr) &(temp_var_for_const_34 = 1.37319376065508163265e+03)},
    "/home/shijia/Public/testprogram/s_pone.c_e.c:188:12"); /* 0xC0A468E3,
                                                               0x88FDA79D */
}
;

static const double qs5[6] = {
  8.12765501384335777857e+01, /* 0x405451B2, 0xFF5A11B2 */
  1.99179873460485964642e+03, /* 0x409F1F31, 0xE77BF839 */
  1.74684851924908907677e+04, /* 0x40D10F1F, 0x0D64CE29 */
  4.98514270910352279316e+04, /* 0x40E8576D, 0xAABAD197 */
  2.79480751638918118260e+04, /* 0x40DB4B04, 0xCF7C364B */
  (0.0 - 4.71918354795128470869e+03);
double temp_var_for_const_38, temp_var_for_const_39;
double temp_var_for_tac_25;
computeDSub(
    (Addr)&temp_var_for_tac_25,
    {(Addr) &(temp_var_for_const_37 = 0.0),
     (Addr) &(temp_var_for_const_36 = 2.61244440453215656817e+03)},
    "/home/shijia/Public/testprogram/s_pone.c_e.c:197:12"); /* 0xC0B26F2E,
                                                               0xFCFFA004 */
}
;

static const double qr3[6] = {(0.0 - 5.07831226461766561369e-09);
double temp_var_for_const_40, temp_var_for_const_41;
double temp_var_for_tac_26;
computeDSub((Addr)&temp_var_for_tac_26,
            {(Addr) &(temp_var_for_const_39 = 0.0),
             (Addr) &(temp_var_for_const_38 = 4.71918354795128470869e+03)},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:201:12");
, /* 0xBE35CFA9, 0xD38FC84F */
    (0.0 - 1.02537829820837089745e-01);
double temp_var_for_const_42, temp_var_for_const_43;
double temp_var_for_tac_27;
computeDSub((Addr)&temp_var_for_tac_27,
            {(Addr) &(temp_var_for_const_41 = 0.0),
             (Addr) &(temp_var_for_const_40 = 5.07831226461766561369e-09)},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:202:12");
, /* 0xBFBA3FEB, 0x51AEED54 */
    (0.0 - 4.61011581139473403113e+00);
double temp_var_for_const_44, temp_var_for_const_45;
double temp_var_for_tac_28;
computeDSub((Addr)&temp_var_for_tac_28,
            {(Addr) &(temp_var_for_const_43 = 0.0),
             (Addr) &(temp_var_for_const_42 = 1.02537829820837089745e-01)},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:203:12");
, /* 0xC01270C2, 0x3302D9FF */
    (0.0 - 5.78472216562783643212e+01);
double temp_var_for_const_46, temp_var_for_const_47;
double temp_var_for_tac_29;
computeDSub((Addr)&temp_var_for_tac_29,
            {(Addr) &(temp_var_for_const_45 = 0.0),
             (Addr) &(temp_var_for_const_44 = 4.61011581139473403113e+00)},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:204:12");
, /* 0xC04CEC71, 0xC25D16DA */
    (0.0 - 2.28244540737631695038e+02);
double temp_var_for_const_48, temp_var_for_const_49;
double temp_var_for_tac_30;
computeDSub((Addr)&temp_var_for_tac_30,
            {(Addr) &(temp_var_for_const_47 = 0.0),
             (Addr) &(temp_var_for_const_46 = 5.78472216562783643212e+01)},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:205:12");
, /* 0xC06C87D3, 0x4718D55F */
    (0.0 - 2.19210128478909325622e+02);
double temp_var_for_const_50, temp_var_for_const_51;
double temp_var_for_tac_31;
computeDSub(
    (Addr)&temp_var_for_tac_31,
    {(Addr) &(temp_var_for_const_49 = 0.0),
     (Addr) &(temp_var_for_const_48 = 2.28244540737631695038e+02)},
    "/home/shijia/Public/testprogram/s_pone.c_e.c:206:12"); /* 0xC06B66B9,
                                                               0x5F5C1BF6 */
}
;

static const double qs3[6] = {
  4.76651550323729509273e+01, /* 0x4047D523, 0xCCD367E4 */
  6.73865112676699709482e+02, /* 0x40850EEB, 0xC031EE3E */
  3.38015286679526343505e+03, /* 0x40AA684E, 0x448E7C9A */
  5.54772909720722782367e+03, /* 0x40B5ABBA, 0xA61D54A6 */
  1.90311919338810798763e+03, /* 0x409DBC7A, 0x0DD4DF4B */
  (0.0 - 1.35201191444307340817e+02);
double temp_var_for_const_52, temp_var_for_const_53;
double temp_var_for_tac_32;
computeDSub(
    (Addr)&temp_var_for_tac_32,
    {(Addr) &(temp_var_for_const_51 = 0.0),
     (Addr) &(temp_var_for_const_50 = 2.19210128478909325622e+02)},
    "/home/shijia/Public/testprogram/s_pone.c_e.c:215:12"); /* 0xC060E670,
                                                               0x290A311F */
}
;

static const double qr2[6] = {
  /* for x in [2.8570,2]=1/[0.3499,0.5] */
  (0.0 - 1.78381727510958865572e-07);
double temp_var_for_const_54, temp_var_for_const_55;
double temp_var_for_tac_33;
computeDSub((Addr)&temp_var_for_tac_33,
            {(Addr) &(temp_var_for_const_53 = 0.0),
             (Addr) &(temp_var_for_const_52 = 1.35201191444307340817e+02)},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:220:12");
, /* 0xBE87F126, 0x44C626D2 */
    (0.0 - 1.02517042607985553460e-01);
double temp_var_for_const_56, temp_var_for_const_57;
double temp_var_for_tac_34;
computeDSub((Addr)&temp_var_for_tac_34,
            {(Addr) &(temp_var_for_const_55 = 0.0),
             (Addr) &(temp_var_for_const_54 = 1.78381727510958865572e-07)},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:221:12");
, /* 0xBFBA3E8E, 0x9148B010 */
    (0.0 - 2.75220568278187460720e+00);
double temp_var_for_const_58, temp_var_for_const_59;
double temp_var_for_tac_35;
computeDSub((Addr)&temp_var_for_tac_35,
            {(Addr) &(temp_var_for_const_57 = 0.0),
             (Addr) &(temp_var_for_const_56 = 1.02517042607985553460e-01)},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:222:12");
, /* 0xC0060484, 0x69BB4EDA */
    (0.0 - 1.96636162643703720221e+01);
double temp_var_for_const_60, temp_var_for_const_61;
double temp_var_for_tac_36;
computeDSub((Addr)&temp_var_for_tac_36,
            {(Addr) &(temp_var_for_const_59 = 0.0),
             (Addr) &(temp_var_for_const_58 = 2.75220568278187460720e+00)},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:223:12");
, /* 0xC033A9E2, 0xC168907F */
    (0.0 - 4.23253133372830490089e+01);
double temp_var_for_const_62, temp_var_for_const_63;
double temp_var_for_tac_37;
computeDSub((Addr)&temp_var_for_tac_37,
            {(Addr) &(temp_var_for_const_61 = 0.0),
             (Addr) &(temp_var_for_const_60 = 1.96636162643703720221e+01)},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:224:12");
, /* 0xC04529A3, 0xDE104AAA */
    (0.0 - 2.13719211703704061733e+01);
double temp_var_for_const_64, temp_var_for_const_65;
double temp_var_for_tac_38;
computeDSub(
    (Addr)&temp_var_for_tac_38,
    {(Addr) &(temp_var_for_const_63 = 0.0),
     (Addr) &(temp_var_for_const_62 = 4.23253133372830490089e+01)},
    "/home/shijia/Public/testprogram/s_pone.c_e.c:225:12"); /* 0xC0355F36,
                                                               0x39CF6E52 */
}
;

static const double qs2[6] = {
  2.95333629060523854548e+01, /* 0x403D888A, 0x78AE64FF */
  2.52981549982190529136e+02, /* 0x406F9F68, 0xDB821CBA */
  7.57502834868645436472e+02, /* 0x4087AC05, 0xCE49A0F7 */
  7.39393205320467245656e+02, /* 0x40871B25, 0x48D4C029 */
  1.55949003336666123687e+02, /* 0x40637E5E, 0x3C3ED8D4 */
  (0.0 - 4.95949898822628210127e+00);
double temp_var_for_const_66, temp_var_for_const_67;
double temp_var_for_tac_39;
computeDSub(
    (Addr)&temp_var_for_tac_39,
    {(Addr) &(temp_var_for_const_65 = 0.0),
     (Addr) &(temp_var_for_const_64 = 2.13719211703704061733e+01)},
    "/home/shijia/Public/testprogram/s_pone.c_e.c:234:12"); /* 0xC013D686,
                                                               0xE71BE86B */
}
;

GET_HIGH_WORD(ix, x);
ix &= IC(0x7fffffff);
if (ix >= IC(0x41b00000)) {
  return .375 / x;
} else if (ix >= IC(0x40200000)) {
  p = qr8;
  q = qs8;
} else if (ix >= IC(0x40122E8B)) {
  p = qr5;
  q = qs5;
} else if (ix >= IC(0x4006DB6D)) {
  p = qr3;
  q = qs3;
} else /* if (ix >= IC(0x40000000)) */
{
  p = qr2;
  q = qs2;
}
z = one / (x * x);
double temp_var_for_const_68;
double temp_var_for_tac_40, temp_var_for_tac_41;
computeDSub((Addr)&temp_var_for_tac_40,
            {(Addr) &(temp_var_for_const_67 = 0.0),
             (Addr) &(temp_var_for_const_66 = 4.95949898822628210127e+00)},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:255:16");
computeDMul((Addr)&temp_var_for_tac_41, {(Addr)&x, (Addr)&x},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:255:11");
computeDDiv((Addr)&z,
            {(Addr) &(temp_var_for_const_68 = one), (Addr)&temp_var_for_tac_41},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:255:5");
#ifdef DO_NOT_USE_THIS
r = p[0] + z * (p[1] + z * (p[2] + z * (p[3] + z * (p[4] + z * p[5]))));
s = one +
    z * (q[0] + z * (q[1] + z * (q[2] + z * (q[3] + z * (q[4] + z * q[5])))));
#else
r1 = p[0] + z * p[1];
double temp_var_for_const_69, temp_var_for_const_70;
double temp_var_for_tac_42;
computeDMul((Addr)&temp_var_for_tac_42,
            {(Addr)&z, (Addr) &(temp_var_for_const_69 = p[1])},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:261:13");
computeDAdd((Addr)&r1, {(Addr) &(temp_var_for_const_70 = p[0]),
                        (Addr)&temp_var_for_tac_42},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:261:6");
z2 = z * z;
computeDMul((Addr)&z2, {(Addr)&z, (Addr)&z},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:262:6");
r2 = p[2] + z * p[3];
double temp_var_for_const_71, temp_var_for_const_72;
double temp_var_for_tac_43;
computeDMul((Addr)&temp_var_for_tac_43,
            {(Addr)&z, (Addr) &(temp_var_for_const_71 = p[3])},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:263:13");
computeDAdd((Addr)&r2, {(Addr) &(temp_var_for_const_72 = p[2]),
                        (Addr)&temp_var_for_tac_43},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:263:6");
z4 = z2 * z2;
computeDMul((Addr)&z4, {(Addr)&z2, (Addr)&z2},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:264:6");
r3 = p[4] + z * p[5];
double temp_var_for_const_73, temp_var_for_const_74;
double temp_var_for_tac_44;
computeDMul((Addr)&temp_var_for_tac_44,
            {(Addr)&z, (Addr) &(temp_var_for_const_73 = p[5])},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:265:13");
computeDAdd((Addr)&r3, {(Addr) &(temp_var_for_const_74 = p[4]),
                        (Addr)&temp_var_for_tac_44},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:265:6");
z6 = z4 * z2;
computeDMul((Addr)&z6, {(Addr)&z4, (Addr)&z2},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:266:6");
r = r1 + z2 * r2 + z4 * r3;
double temp_var_for_tac_45, temp_var_for_tac_46, temp_var_for_tac_47;
computeDMul((Addr)&temp_var_for_tac_45, {(Addr)&z2, (Addr)&r2},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:267:10");
computeDAdd((Addr)&temp_var_for_tac_46, {(Addr)&r1, (Addr)&temp_var_for_tac_45},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:267:25");
computeDMul((Addr)&temp_var_for_tac_47, {(Addr)&z4, (Addr)&r3},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:267:20");
computeDAdd((Addr)&r, {(Addr)&temp_var_for_tac_46, (Addr)&temp_var_for_tac_47},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:267:5");
s1 = one + z * q[0];
double temp_var_for_const_75, temp_var_for_const_76;
double temp_var_for_tac_48;
computeDMul((Addr)&temp_var_for_tac_48,
            {(Addr)&z, (Addr) &(temp_var_for_const_75 = q[0])},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:268:12");
computeDAdd((Addr)&s1,
            {(Addr) &(temp_var_for_const_76 = one), (Addr)&temp_var_for_tac_48},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:268:6");
s2 = q[1] + z * q[2];
double temp_var_for_const_77, temp_var_for_const_78;
double temp_var_for_tac_49;
computeDMul((Addr)&temp_var_for_tac_49,
            {(Addr)&z, (Addr) &(temp_var_for_const_77 = q[2])},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:269:13");
computeDAdd((Addr)&s2, {(Addr) &(temp_var_for_const_78 = q[1]),
                        (Addr)&temp_var_for_tac_49},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:269:6");
s3 = q[3] + z * q[4];
double temp_var_for_const_79, temp_var_for_const_80;
double temp_var_for_tac_50;
computeDMul((Addr)&temp_var_for_tac_50,
            {(Addr)&z, (Addr) &(temp_var_for_const_79 = q[4])},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:270:13");
computeDAdd((Addr)&s3, {(Addr) &(temp_var_for_const_80 = q[3]),
                        (Addr)&temp_var_for_tac_50},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:270:6");
s = s1 + z2 * s2 + z4 * s3 + z6 * q[5];
double temp_var_for_const_81;
double temp_var_for_tac_51, temp_var_for_tac_52, temp_var_for_tac_53,
    temp_var_for_tac_54, temp_var_for_tac_55;
computeDMul((Addr)&temp_var_for_tac_51, {(Addr)&z2, (Addr)&s2},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:271:10");
computeDAdd((Addr)&temp_var_for_tac_52, {(Addr)&s1, (Addr)&temp_var_for_tac_51},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:271:25");
computeDMul((Addr)&temp_var_for_tac_53, {(Addr)&z4, (Addr)&s3},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:271:20");
computeDAdd((Addr)&temp_var_for_tac_54,
            {(Addr)&temp_var_for_tac_52, (Addr)&temp_var_for_tac_53},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:271:35");
computeDMul((Addr)&temp_var_for_tac_55,
            {(Addr)&z6, (Addr) &(temp_var_for_const_81 = q[5])},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:271:30");
computeDAdd((Addr)&s, {(Addr)&temp_var_for_tac_54, (Addr)&temp_var_for_tac_55},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:271:5");
#endif
double temp_var_for_ext_1;
temp_var_for_ext_1 = (.375 + r / s) / x;
double temp_var_for_const_82;
double temp_var_for_tac_56, temp_var_for_tac_57;
computeDDiv((Addr)&temp_var_for_tac_56, {(Addr)&r, (Addr)&s},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:274:30");
computeDAdd((Addr)&temp_var_for_tac_57, {(Addr) &(temp_var_for_const_82 = .375),
                                         (Addr)&temp_var_for_tac_56},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:274:39");
computeDDiv((Addr)&temp_var_for_ext_1, {(Addr)&temp_var_for_tac_57, (Addr)&x},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:274:22");
callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
callExp++; /*identify the function is  add move tmpShadow*/
return temp_var_for_ext_1;
}
