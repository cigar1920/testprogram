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
    double temp_var_for_ext_0;
    double temp_var_for_const_0;
    temp_var_for_ext_0 = one;
    AssignD({(Addr)&temp_var_for_ext_0}, (Addr) &(temp_var_for_const_0 = one),
            "/home/shijia/Public/testprogram/s_pone.c_e.c:108:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  } else {
    if (ix >= IC(0x40200000)) {
      p = pr8;
      q = ps8;
    } else {
      if (ix >= IC(0x40122E8B)) {
        p = pr5;
        q = ps5;
      } else {
        if (ix >= IC(0x4006DB6D)) {
          p = pr3;
          q = ps3;
        } else /* if (ix >= IC(0x40000000)) */
        {
          p = pr2;
          q = ps2;
        }
      }
    }
  }

  double temp_var_for_tac_0, temp_var_for_tac_1;
  double temp_var_for_const_1;
  temp_var_for_tac_0 = x * x;

  temp_var_for_tac_1 = one / temp_var_for_tac_0;

  z = temp_var_for_tac_1;
  computeDMul((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&x},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:133:16");
  computeDDiv((Addr)&temp_var_for_tac_1,
              {(Addr) &(temp_var_for_const_1 = one), (Addr)&temp_var_for_tac_0},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:133:11");
  AssignD({(Addr)&z}, (Addr)&temp_var_for_tac_1,
          "/home/shijia/Public/testprogram/s_pone.c_e.c:133:5");
  ;
#ifdef DO_NOT_USE_THIS
  r = p[0] + z * (p[1] + z * (p[2] + z * (p[3] + z * (p[4] + z * p[5]))));
  s = one + z * (q[0] + z * (q[1] + z * (q[2] + z * (q[3] + z * q[4]))));
#else
  double temp_var_for_tac_2, temp_var_for_tac_3;
  double temp_var_for_const_2, temp_var_for_const_3;
  temp_var_for_tac_2 = z * p[1];

  temp_var_for_tac_3 = p[0] + temp_var_for_tac_2;

  r1 = temp_var_for_tac_3;
  computeDMul((Addr)&temp_var_for_tac_2,
              {(Addr)&z, (Addr) &(temp_var_for_const_2 = p[1])},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:138:17");
  computeDAdd((Addr)&temp_var_for_tac_3, {(Addr) &(temp_var_for_const_3 = p[0]),
                                          (Addr)&temp_var_for_tac_2},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:138:13");
  AssignD({(Addr)&r1}, (Addr)&temp_var_for_tac_3,
          "/home/shijia/Public/testprogram/s_pone.c_e.c:138:6");
  ;
  double temp_var_for_tac_4;
  temp_var_for_tac_4 = z * z;

  z2 = temp_var_for_tac_4;
  computeDMul((Addr)&temp_var_for_tac_4, {(Addr)&z, (Addr)&z},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:139:10");
  AssignD({(Addr)&z2}, (Addr)&temp_var_for_tac_4,
          "/home/shijia/Public/testprogram/s_pone.c_e.c:139:6");
  ;
  double temp_var_for_tac_5, temp_var_for_tac_6;
  double temp_var_for_const_4, temp_var_for_const_5;
  temp_var_for_tac_5 = z * p[3];

  temp_var_for_tac_6 = p[2] + temp_var_for_tac_5;

  r2 = temp_var_for_tac_6;
  computeDMul((Addr)&temp_var_for_tac_5,
              {(Addr)&z, (Addr) &(temp_var_for_const_4 = p[3])},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:140:17");
  computeDAdd((Addr)&temp_var_for_tac_6, {(Addr) &(temp_var_for_const_5 = p[2]),
                                          (Addr)&temp_var_for_tac_5},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:140:13");
  AssignD({(Addr)&r2}, (Addr)&temp_var_for_tac_6,
          "/home/shijia/Public/testprogram/s_pone.c_e.c:140:6");
  ;
  double temp_var_for_tac_7;
  temp_var_for_tac_7 = z2 * z2;

  z4 = temp_var_for_tac_7;
  computeDMul((Addr)&temp_var_for_tac_7, {(Addr)&z2, (Addr)&z2},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:141:11");
  AssignD({(Addr)&z4}, (Addr)&temp_var_for_tac_7,
          "/home/shijia/Public/testprogram/s_pone.c_e.c:141:6");
  ;
  double temp_var_for_tac_8, temp_var_for_tac_9;
  double temp_var_for_const_6, temp_var_for_const_7;
  temp_var_for_tac_8 = z * p[5];

  temp_var_for_tac_9 = p[4] + temp_var_for_tac_8;

  r3 = temp_var_for_tac_9;
  computeDMul((Addr)&temp_var_for_tac_8,
              {(Addr)&z, (Addr) &(temp_var_for_const_6 = p[5])},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:142:17");
  computeDAdd((Addr)&temp_var_for_tac_9, {(Addr) &(temp_var_for_const_7 = p[4]),
                                          (Addr)&temp_var_for_tac_8},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:142:13");
  AssignD({(Addr)&r3}, (Addr)&temp_var_for_tac_9,
          "/home/shijia/Public/testprogram/s_pone.c_e.c:142:6");
  ;
  double temp_var_for_tac_10, temp_var_for_tac_11, temp_var_for_tac_12,
      temp_var_for_tac_13;
  temp_var_for_tac_10 = z2 * r2;

  temp_var_for_tac_11 = r1 + temp_var_for_tac_10;

  temp_var_for_tac_12 = z4 * r3;

  temp_var_for_tac_13 = temp_var_for_tac_11 + temp_var_for_tac_12;

  r = temp_var_for_tac_13;
  computeDMul((Addr)&temp_var_for_tac_10, {(Addr)&z2, (Addr)&r2},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:143:15");
  computeDAdd((Addr)&temp_var_for_tac_11,
              {(Addr)&r1, (Addr)&temp_var_for_tac_10},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:143:10");
  computeDMul((Addr)&temp_var_for_tac_12, {(Addr)&z4, (Addr)&r3},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:143:25");
  computeDAdd((Addr)&temp_var_for_tac_13,
              {(Addr)&temp_var_for_tac_11, (Addr)&temp_var_for_tac_12},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:143:20");
  AssignD({(Addr)&r}, (Addr)&temp_var_for_tac_13,
          "/home/shijia/Public/testprogram/s_pone.c_e.c:143:5");
  ;
  double temp_var_for_tac_14, temp_var_for_tac_15;
  double temp_var_for_const_8, temp_var_for_const_9;
  temp_var_for_tac_14 = z * q[0];

  temp_var_for_tac_15 = one + temp_var_for_tac_14;

  s1 = temp_var_for_tac_15;
  computeDMul((Addr)&temp_var_for_tac_14,
              {(Addr)&z, (Addr) &(temp_var_for_const_8 = q[0])},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:144:16");
  computeDAdd((Addr)&temp_var_for_tac_15, {(Addr) &(temp_var_for_const_9 = one),
                                           (Addr)&temp_var_for_tac_14},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:144:12");
  AssignD({(Addr)&s1}, (Addr)&temp_var_for_tac_15,
          "/home/shijia/Public/testprogram/s_pone.c_e.c:144:6");
  ;
  double temp_var_for_tac_16, temp_var_for_tac_17;
  double temp_var_for_const_10, temp_var_for_const_11;
  temp_var_for_tac_16 = z * q[2];

  temp_var_for_tac_17 = q[1] + temp_var_for_tac_16;

  s2 = temp_var_for_tac_17;
  computeDMul((Addr)&temp_var_for_tac_16,
              {(Addr)&z, (Addr) &(temp_var_for_const_10 = q[2])},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:145:17");
  computeDAdd(
      (Addr)&temp_var_for_tac_17,
      {(Addr) &(temp_var_for_const_11 = q[1]), (Addr)&temp_var_for_tac_16},
      "/home/shijia/Public/testprogram/s_pone.c_e.c:145:13");
  AssignD({(Addr)&s2}, (Addr)&temp_var_for_tac_17,
          "/home/shijia/Public/testprogram/s_pone.c_e.c:145:6");
  ;
  double temp_var_for_tac_18, temp_var_for_tac_19;
  double temp_var_for_const_12, temp_var_for_const_13;
  temp_var_for_tac_18 = z * q[4];

  temp_var_for_tac_19 = q[3] + temp_var_for_tac_18;

  s3 = temp_var_for_tac_19;
  computeDMul((Addr)&temp_var_for_tac_18,
              {(Addr)&z, (Addr) &(temp_var_for_const_12 = q[4])},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:146:17");
  computeDAdd(
      (Addr)&temp_var_for_tac_19,
      {(Addr) &(temp_var_for_const_13 = q[3]), (Addr)&temp_var_for_tac_18},
      "/home/shijia/Public/testprogram/s_pone.c_e.c:146:13");
  AssignD({(Addr)&s3}, (Addr)&temp_var_for_tac_19,
          "/home/shijia/Public/testprogram/s_pone.c_e.c:146:6");
  ;
  double temp_var_for_tac_20, temp_var_for_tac_21, temp_var_for_tac_22,
      temp_var_for_tac_23;
  temp_var_for_tac_20 = z2 * s2;

  temp_var_for_tac_21 = s1 + temp_var_for_tac_20;

  temp_var_for_tac_22 = z4 * s3;

  temp_var_for_tac_23 = temp_var_for_tac_21 + temp_var_for_tac_22;

  s = temp_var_for_tac_23;
  computeDMul((Addr)&temp_var_for_tac_20, {(Addr)&z2, (Addr)&s2},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:147:15");
  computeDAdd((Addr)&temp_var_for_tac_21,
              {(Addr)&s1, (Addr)&temp_var_for_tac_20},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:147:10");
  computeDMul((Addr)&temp_var_for_tac_22, {(Addr)&z4, (Addr)&s3},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:147:25");
  computeDAdd((Addr)&temp_var_for_tac_23,
              {(Addr)&temp_var_for_tac_21, (Addr)&temp_var_for_tac_22},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:147:20");
  AssignD({(Addr)&s}, (Addr)&temp_var_for_tac_23,
          "/home/shijia/Public/testprogram/s_pone.c_e.c:147:5");
  ;
#endif
  double temp_var_for_ext_1;
  double temp_var_for_tac_24, temp_var_for_tac_25;
  double temp_var_for_const_14;
  temp_var_for_tac_24 = r / s;

  temp_var_for_tac_25 = one + temp_var_for_tac_24;

  temp_var_for_ext_1 = temp_var_for_tac_25;
  computeDDiv((Addr)&temp_var_for_tac_24, {(Addr)&r, (Addr)&s},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:150:32");
  computeDAdd(
      (Addr)&temp_var_for_tac_25,
      {(Addr) &(temp_var_for_const_14 = one), (Addr)&temp_var_for_tac_24},
      "/home/shijia/Public/testprogram/s_pone.c_e.c:150:28");
  AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_25,
          "/home/shijia/Public/testprogram/s_pone.c_e.c:150:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
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
      0.00000000000000000000e+00,         /* 0x00000000, 0x00000000 */
      (double temp_var_for_tac_26;
  double temp_var_for_const_15, temp_var_for_const_16;
  temp_var_for_tac_26 = 0.0 - 1.02539062499992714161e-01;

), /* 0xBFBA3FFF, 0xFFFFFDF3 */
      (double temp_var_for_tac_27;double temp_var_for_const_17,temp_var_for_const_18;temp_var_for_tac_27 = 0.0 - 1.62717534544589987888e+01;

), /* 0xC0304591, 0xA26779F7 */
      (double temp_var_for_tac_28;double temp_var_for_const_19,temp_var_for_const_20;temp_var_for_tac_28 = 0.0 - 7.59601722513950107896e+02;

), /* 0xC087BCD0, 0x53E4B576 */
      (double temp_var_for_tac_29;double temp_var_for_const_21,temp_var_for_const_22;temp_var_for_tac_29 = 0.0 - 1.18498066702429587167e+04;

), /* 0xC0C724E7, 0x40F87415 */
      (double temp_var_for_tac_30;double temp_var_for_const_23,temp_var_for_const_24;temp_var_for_tac_30 = 0.0 - 4.84385124285750353010e+04;

)  /* 0xC0E7A6D0, 0x65D09C6A */
};

  static const double qs8[6] = {
      1.61395369700722909556e+02,        /* 0x40642CA6, 0xDE5BCDE5 */
      7.82538599923348465381e+03,        /* 0x40BE9162, 0xD0D88419 */
      1.33875336287249578163e+05,        /* 0x4100579A, 0xB0B75E98 */
      7.19657723683240939863e+05,        /* 0x4125F653, 0x72869C19 */
      6.66601232617776375264e+05,        /* 0x412457D2, 0x7719AD5C */
      (double temp_var_for_tac_31;
  double temp_var_for_const_25, temp_var_for_const_26;
  temp_var_for_tac_31 = 0.0 - 2.94490264303834643215e+05;

) /* 0xC111F969, 0x0EA5AA18 */
}
;

  static const double qr5[6] = {
      /* for x in [8,4.5454]=1/[0.125,0.22001] */
      (double temp_var_for_tac_32;
  double temp_var_for_const_27, temp_var_for_const_28;
  temp_var_for_tac_32 = 0.0 - 2.08979931141764104297e-11;

), /* 0xBDB6FA43, 0x1AA1A098 */
      (double temp_var_for_tac_33;double temp_var_for_const_29,temp_var_for_const_30;temp_var_for_tac_33 = 0.0 - 1.02539050241375426231e-01;

), /* 0xBFBA3FFF, 0xCB597FEF */
      (double temp_var_for_tac_34;double temp_var_for_const_31,temp_var_for_const_32;temp_var_for_tac_34 = 0.0 - 8.05644828123936029840e+00;

), /* 0xC0201CE6, 0xCA03AD4B */
      (double temp_var_for_tac_35;double temp_var_for_const_33,temp_var_for_const_34;temp_var_for_tac_35 = 0.0 - 1.83669607474888380239e+02;

), /* 0xC066F56D, 0x6CA7B9B0 */
      (double temp_var_for_tac_36;double temp_var_for_const_35,temp_var_for_const_36;temp_var_for_tac_36 = 0.0 - 1.37319376065508163265e+03;

), /* 0xC09574C6, 0x6931734F */
      (double temp_var_for_tac_37;double temp_var_for_const_37,temp_var_for_const_38;temp_var_for_tac_37 = 0.0 - 2.61244440453215656817e+03;

)  /* 0xC0A468E3, 0x88FDA79D */
}
;

  static const double qs5[6] = {
      8.12765501384335777857e+01,        /* 0x405451B2, 0xFF5A11B2 */
      1.99179873460485964642e+03,        /* 0x409F1F31, 0xE77BF839 */
      1.74684851924908907677e+04,        /* 0x40D10F1F, 0x0D64CE29 */
      4.98514270910352279316e+04,        /* 0x40E8576D, 0xAABAD197 */
      2.79480751638918118260e+04,        /* 0x40DB4B04, 0xCF7C364B */
      (double temp_var_for_tac_38;
  double temp_var_for_const_39, temp_var_for_const_40;
  temp_var_for_tac_38 = 0.0 - 4.71918354795128470869e+03;

) /* 0xC0B26F2E, 0xFCFFA004 */
}
;

  static const double qr3[6] = {
      (double temp_var_for_tac_39;
  double temp_var_for_const_41, temp_var_for_const_42;
  temp_var_for_tac_39 = 0.0 - 5.07831226461766561369e-09;

), /* 0xBE35CFA9, 0xD38FC84F */
      (double temp_var_for_tac_40;double temp_var_for_const_43,temp_var_for_const_44;temp_var_for_tac_40 = 0.0 - 1.02537829820837089745e-01;

), /* 0xBFBA3FEB, 0x51AEED54 */
      (double temp_var_for_tac_41;double temp_var_for_const_45,temp_var_for_const_46;temp_var_for_tac_41 = 0.0 - 4.61011581139473403113e+00;

), /* 0xC01270C2, 0x3302D9FF */
      (double temp_var_for_tac_42;double temp_var_for_const_47,temp_var_for_const_48;temp_var_for_tac_42 = 0.0 - 5.78472216562783643212e+01;

), /* 0xC04CEC71, 0xC25D16DA */
      (double temp_var_for_tac_43;double temp_var_for_const_49,temp_var_for_const_50;temp_var_for_tac_43 = 0.0 - 2.28244540737631695038e+02;

), /* 0xC06C87D3, 0x4718D55F */
      (double temp_var_for_tac_44;double temp_var_for_const_51,temp_var_for_const_52;temp_var_for_tac_44 = 0.0 - 2.19210128478909325622e+02;

)  /* 0xC06B66B9, 0x5F5C1BF6 */
}
;

  static const double qs3[6] = {
      4.76651550323729509273e+01,        /* 0x4047D523, 0xCCD367E4 */
      6.73865112676699709482e+02,        /* 0x40850EEB, 0xC031EE3E */
      3.38015286679526343505e+03,        /* 0x40AA684E, 0x448E7C9A */
      5.54772909720722782367e+03,        /* 0x40B5ABBA, 0xA61D54A6 */
      1.90311919338810798763e+03,        /* 0x409DBC7A, 0x0DD4DF4B */
      (double temp_var_for_tac_45;
  double temp_var_for_const_53, temp_var_for_const_54;
  temp_var_for_tac_45 = 0.0 - 1.35201191444307340817e+02;

) /* 0xC060E670, 0x290A311F */
}
;

  static const double qr2[6] = {
      /* for x in [2.8570,2]=1/[0.3499,0.5] */
      (double temp_var_for_tac_46;
  double temp_var_for_const_55, temp_var_for_const_56;
  temp_var_for_tac_46 = 0.0 - 1.78381727510958865572e-07;

), /* 0xBE87F126, 0x44C626D2 */
      (double temp_var_for_tac_47;double temp_var_for_const_57,temp_var_for_const_58;temp_var_for_tac_47 = 0.0 - 1.02517042607985553460e-01;

), /* 0xBFBA3E8E, 0x9148B010 */
      (double temp_var_for_tac_48;double temp_var_for_const_59,temp_var_for_const_60;temp_var_for_tac_48 = 0.0 - 2.75220568278187460720e+00;

), /* 0xC0060484, 0x69BB4EDA */
      (double temp_var_for_tac_49;double temp_var_for_const_61,temp_var_for_const_62;temp_var_for_tac_49 = 0.0 - 1.96636162643703720221e+01;

), /* 0xC033A9E2, 0xC168907F */
      (double temp_var_for_tac_50;double temp_var_for_const_63,temp_var_for_const_64;temp_var_for_tac_50 = 0.0 - 4.23253133372830490089e+01;

), /* 0xC04529A3, 0xDE104AAA */
      (double temp_var_for_tac_51;double temp_var_for_const_65,temp_var_for_const_66;temp_var_for_tac_51 = 0.0 - 2.13719211703704061733e+01;

)  /* 0xC0355F36, 0x39CF6E52 */
}
;

  static const double qs2[6] = {
      2.95333629060523854548e+01,        /* 0x403D888A, 0x78AE64FF */
      2.52981549982190529136e+02,        /* 0x406F9F68, 0xDB821CBA */
      7.57502834868645436472e+02,        /* 0x4087AC05, 0xCE49A0F7 */
      7.39393205320467245656e+02,        /* 0x40871B25, 0x48D4C029 */
      1.55949003336666123687e+02,        /* 0x40637E5E, 0x3C3ED8D4 */
      (double temp_var_for_tac_52;
  double temp_var_for_const_67, temp_var_for_const_68;
  temp_var_for_tac_52 = 0.0 - 4.95949898822628210127e+00;

) /* 0xC013D686, 0xE71BE86B */
}
;

GET_HIGH_WORD(ix, x);
ix &= IC(0x7fffffff);
if (ix >= IC(0x41b00000)) {
  double temp_var_for_ext_2;
  double temp_var_for_tac_53;
  double temp_var_for_const_69;
  temp_var_for_tac_53 = .375 / x;

  temp_var_for_ext_2 = temp_var_for_tac_53;
  computeDSub((Addr)&temp_var_for_tac_26,
              {(Addr) &(temp_var_for_const_16 = 0.0),
               (Addr) &(temp_var_for_const_15 = 1.02539062499992714161e-01)},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:176:12");
  computeDSub((Addr)&temp_var_for_tac_27,
              {(Addr) &(temp_var_for_const_18 = 0.0),
               (Addr) &(temp_var_for_const_17 = 1.62717534544589987888e+01)},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:177:12");
  computeDSub((Addr)&temp_var_for_tac_28,
              {(Addr) &(temp_var_for_const_20 = 0.0),
               (Addr) &(temp_var_for_const_19 = 7.59601722513950107896e+02)},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:178:12");
  computeDSub((Addr)&temp_var_for_tac_29,
              {(Addr) &(temp_var_for_const_22 = 0.0),
               (Addr) &(temp_var_for_const_21 = 1.18498066702429587167e+04)},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:179:12");
  computeDSub((Addr)&temp_var_for_tac_30,
              {(Addr) &(temp_var_for_const_24 = 0.0),
               (Addr) &(temp_var_for_const_23 = 4.84385124285750353010e+04)},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:180:12");
  computeDSub((Addr)&temp_var_for_tac_31,
              {(Addr) &(temp_var_for_const_26 = 0.0),
               (Addr) &(temp_var_for_const_25 = 2.94490264303834643215e+05)},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:189:12");
  computeDSub((Addr)&temp_var_for_tac_32,
              {(Addr) &(temp_var_for_const_28 = 0.0),
               (Addr) &(temp_var_for_const_27 = 2.08979931141764104297e-11)},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:194:12");
  computeDSub((Addr)&temp_var_for_tac_33,
              {(Addr) &(temp_var_for_const_30 = 0.0),
               (Addr) &(temp_var_for_const_29 = 1.02539050241375426231e-01)},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:195:12");
  computeDSub((Addr)&temp_var_for_tac_34,
              {(Addr) &(temp_var_for_const_32 = 0.0),
               (Addr) &(temp_var_for_const_31 = 8.05644828123936029840e+00)},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:196:12");
  computeDSub((Addr)&temp_var_for_tac_35,
              {(Addr) &(temp_var_for_const_34 = 0.0),
               (Addr) &(temp_var_for_const_33 = 1.83669607474888380239e+02)},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:197:12");
  computeDSub((Addr)&temp_var_for_tac_36,
              {(Addr) &(temp_var_for_const_36 = 0.0),
               (Addr) &(temp_var_for_const_35 = 1.37319376065508163265e+03)},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:198:12");
  computeDSub((Addr)&temp_var_for_tac_37,
              {(Addr) &(temp_var_for_const_38 = 0.0),
               (Addr) &(temp_var_for_const_37 = 2.61244440453215656817e+03)},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:199:12");
  computeDSub((Addr)&temp_var_for_tac_38,
              {(Addr) &(temp_var_for_const_40 = 0.0),
               (Addr) &(temp_var_for_const_39 = 4.71918354795128470869e+03)},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:208:12");
  computeDSub((Addr)&temp_var_for_tac_39,
              {(Addr) &(temp_var_for_const_42 = 0.0),
               (Addr) &(temp_var_for_const_41 = 5.07831226461766561369e-09)},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:212:12");
  computeDSub((Addr)&temp_var_for_tac_40,
              {(Addr) &(temp_var_for_const_44 = 0.0),
               (Addr) &(temp_var_for_const_43 = 1.02537829820837089745e-01)},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:213:12");
  computeDSub((Addr)&temp_var_for_tac_41,
              {(Addr) &(temp_var_for_const_46 = 0.0),
               (Addr) &(temp_var_for_const_45 = 4.61011581139473403113e+00)},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:214:12");
  computeDSub((Addr)&temp_var_for_tac_42,
              {(Addr) &(temp_var_for_const_48 = 0.0),
               (Addr) &(temp_var_for_const_47 = 5.78472216562783643212e+01)},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:215:12");
  computeDSub((Addr)&temp_var_for_tac_43,
              {(Addr) &(temp_var_for_const_50 = 0.0),
               (Addr) &(temp_var_for_const_49 = 2.28244540737631695038e+02)},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:216:12");
  computeDSub((Addr)&temp_var_for_tac_44,
              {(Addr) &(temp_var_for_const_52 = 0.0),
               (Addr) &(temp_var_for_const_51 = 2.19210128478909325622e+02)},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:217:12");
  computeDSub((Addr)&temp_var_for_tac_45,
              {(Addr) &(temp_var_for_const_54 = 0.0),
               (Addr) &(temp_var_for_const_53 = 1.35201191444307340817e+02)},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:226:12");
  computeDSub((Addr)&temp_var_for_tac_46,
              {(Addr) &(temp_var_for_const_56 = 0.0),
               (Addr) &(temp_var_for_const_55 = 1.78381727510958865572e-07)},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:231:12");
  computeDSub((Addr)&temp_var_for_tac_47,
              {(Addr) &(temp_var_for_const_58 = 0.0),
               (Addr) &(temp_var_for_const_57 = 1.02517042607985553460e-01)},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:232:12");
  computeDSub((Addr)&temp_var_for_tac_48,
              {(Addr) &(temp_var_for_const_60 = 0.0),
               (Addr) &(temp_var_for_const_59 = 2.75220568278187460720e+00)},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:233:12");
  computeDSub((Addr)&temp_var_for_tac_49,
              {(Addr) &(temp_var_for_const_62 = 0.0),
               (Addr) &(temp_var_for_const_61 = 1.96636162643703720221e+01)},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:234:12");
  computeDSub((Addr)&temp_var_for_tac_50,
              {(Addr) &(temp_var_for_const_64 = 0.0),
               (Addr) &(temp_var_for_const_63 = 4.23253133372830490089e+01)},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:235:12");
  computeDSub((Addr)&temp_var_for_tac_51,
              {(Addr) &(temp_var_for_const_66 = 0.0),
               (Addr) &(temp_var_for_const_65 = 2.13719211703704061733e+01)},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:236:12");
  computeDSub((Addr)&temp_var_for_tac_52,
              {(Addr) &(temp_var_for_const_68 = 0.0),
               (Addr) &(temp_var_for_const_67 = 4.95949898822628210127e+00)},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:245:12");
  computeDDiv((Addr)&temp_var_for_tac_53,
              {(Addr) &(temp_var_for_const_69 = .375), (Addr)&x},
              "/home/shijia/Public/testprogram/s_pone.c_e.c:252:31");
  AssignD({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_53,
          "/home/shijia/Public/testprogram/s_pone.c_e.c:252:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_2;
} else {
  if (ix >= IC(0x40200000)) {
    p = qr8;
    q = qs8;
  } else {
    if (ix >= IC(0x40122E8B)) {
      p = qr5;
      q = qs5;
    } else {
      if (ix >= IC(0x4006DB6D)) {
        p = qr3;
        q = qs3;
      } else /* if (ix >= IC(0x40000000)) */
      {
        p = qr2;
        q = qs2;
      }
    }
  }
}

double temp_var_for_tac_54, temp_var_for_tac_55;
double temp_var_for_const_70;
temp_var_for_tac_54 = x * x;

temp_var_for_tac_55 = one / temp_var_for_tac_54;

z = temp_var_for_tac_55;
computeDMul((Addr)&temp_var_for_tac_54, {(Addr)&x, (Addr)&x},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:277:16");
computeDDiv((Addr)&temp_var_for_tac_55,
            {(Addr) &(temp_var_for_const_70 = one), (Addr)&temp_var_for_tac_54},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:277:11");
AssignD({(Addr)&z}, (Addr)&temp_var_for_tac_55,
        "/home/shijia/Public/testprogram/s_pone.c_e.c:277:5");
;
#ifdef DO_NOT_USE_THIS
r = p[0] + z * (p[1] + z * (p[2] + z * (p[3] + z * (p[4] + z * p[5]))));
s = one +
    z * (q[0] + z * (q[1] + z * (q[2] + z * (q[3] + z * (q[4] + z * q[5])))));
#else
double temp_var_for_tac_56, temp_var_for_tac_57;
double temp_var_for_const_71, temp_var_for_const_72;
temp_var_for_tac_56 = z * p[1];

temp_var_for_tac_57 = p[0] + temp_var_for_tac_56;

r1 = temp_var_for_tac_57;
computeDMul((Addr)&temp_var_for_tac_56,
            {(Addr)&z, (Addr) &(temp_var_for_const_71 = p[1])},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:283:17");
computeDAdd((Addr)&temp_var_for_tac_57, {(Addr) &(temp_var_for_const_72 = p[0]),
                                         (Addr)&temp_var_for_tac_56},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:283:13");
AssignD({(Addr)&r1}, (Addr)&temp_var_for_tac_57,
        "/home/shijia/Public/testprogram/s_pone.c_e.c:283:6");
;
double temp_var_for_tac_58;
temp_var_for_tac_58 = z * z;

z2 = temp_var_for_tac_58;
computeDMul((Addr)&temp_var_for_tac_58, {(Addr)&z, (Addr)&z},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:284:10");
AssignD({(Addr)&z2}, (Addr)&temp_var_for_tac_58,
        "/home/shijia/Public/testprogram/s_pone.c_e.c:284:6");
;
double temp_var_for_tac_59, temp_var_for_tac_60;
double temp_var_for_const_73, temp_var_for_const_74;
temp_var_for_tac_59 = z * p[3];

temp_var_for_tac_60 = p[2] + temp_var_for_tac_59;

r2 = temp_var_for_tac_60;
computeDMul((Addr)&temp_var_for_tac_59,
            {(Addr)&z, (Addr) &(temp_var_for_const_73 = p[3])},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:285:17");
computeDAdd((Addr)&temp_var_for_tac_60, {(Addr) &(temp_var_for_const_74 = p[2]),
                                         (Addr)&temp_var_for_tac_59},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:285:13");
AssignD({(Addr)&r2}, (Addr)&temp_var_for_tac_60,
        "/home/shijia/Public/testprogram/s_pone.c_e.c:285:6");
;
double temp_var_for_tac_61;
temp_var_for_tac_61 = z2 * z2;

z4 = temp_var_for_tac_61;
computeDMul((Addr)&temp_var_for_tac_61, {(Addr)&z2, (Addr)&z2},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:286:11");
AssignD({(Addr)&z4}, (Addr)&temp_var_for_tac_61,
        "/home/shijia/Public/testprogram/s_pone.c_e.c:286:6");
;
double temp_var_for_tac_62, temp_var_for_tac_63;
double temp_var_for_const_75, temp_var_for_const_76;
temp_var_for_tac_62 = z * p[5];

temp_var_for_tac_63 = p[4] + temp_var_for_tac_62;

r3 = temp_var_for_tac_63;
computeDMul((Addr)&temp_var_for_tac_62,
            {(Addr)&z, (Addr) &(temp_var_for_const_75 = p[5])},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:287:17");
computeDAdd((Addr)&temp_var_for_tac_63, {(Addr) &(temp_var_for_const_76 = p[4]),
                                         (Addr)&temp_var_for_tac_62},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:287:13");
AssignD({(Addr)&r3}, (Addr)&temp_var_for_tac_63,
        "/home/shijia/Public/testprogram/s_pone.c_e.c:287:6");
;
double temp_var_for_tac_64;
temp_var_for_tac_64 = z4 * z2;

z6 = temp_var_for_tac_64;
computeDMul((Addr)&temp_var_for_tac_64, {(Addr)&z4, (Addr)&z2},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:288:11");
AssignD({(Addr)&z6}, (Addr)&temp_var_for_tac_64,
        "/home/shijia/Public/testprogram/s_pone.c_e.c:288:6");
;
double temp_var_for_tac_65, temp_var_for_tac_66, temp_var_for_tac_67,
    temp_var_for_tac_68;
temp_var_for_tac_65 = z2 * r2;

temp_var_for_tac_66 = r1 + temp_var_for_tac_65;

temp_var_for_tac_67 = z4 * r3;

temp_var_for_tac_68 = temp_var_for_tac_66 + temp_var_for_tac_67;

r = temp_var_for_tac_68;
computeDMul((Addr)&temp_var_for_tac_65, {(Addr)&z2, (Addr)&r2},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:289:15");
computeDAdd((Addr)&temp_var_for_tac_66, {(Addr)&r1, (Addr)&temp_var_for_tac_65},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:289:10");
computeDMul((Addr)&temp_var_for_tac_67, {(Addr)&z4, (Addr)&r3},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:289:25");
computeDAdd((Addr)&temp_var_for_tac_68,
            {(Addr)&temp_var_for_tac_66, (Addr)&temp_var_for_tac_67},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:289:20");
AssignD({(Addr)&r}, (Addr)&temp_var_for_tac_68,
        "/home/shijia/Public/testprogram/s_pone.c_e.c:289:5");
;
double temp_var_for_tac_69, temp_var_for_tac_70;
double temp_var_for_const_77, temp_var_for_const_78;
temp_var_for_tac_69 = z * q[0];

temp_var_for_tac_70 = one + temp_var_for_tac_69;

s1 = temp_var_for_tac_70;
computeDMul((Addr)&temp_var_for_tac_69,
            {(Addr)&z, (Addr) &(temp_var_for_const_77 = q[0])},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:290:16");
computeDAdd((Addr)&temp_var_for_tac_70,
            {(Addr) &(temp_var_for_const_78 = one), (Addr)&temp_var_for_tac_69},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:290:12");
AssignD({(Addr)&s1}, (Addr)&temp_var_for_tac_70,
        "/home/shijia/Public/testprogram/s_pone.c_e.c:290:6");
;
double temp_var_for_tac_71, temp_var_for_tac_72;
double temp_var_for_const_79, temp_var_for_const_80;
temp_var_for_tac_71 = z * q[2];

temp_var_for_tac_72 = q[1] + temp_var_for_tac_71;

s2 = temp_var_for_tac_72;
computeDMul((Addr)&temp_var_for_tac_71,
            {(Addr)&z, (Addr) &(temp_var_for_const_79 = q[2])},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:291:17");
computeDAdd((Addr)&temp_var_for_tac_72, {(Addr) &(temp_var_for_const_80 = q[1]),
                                         (Addr)&temp_var_for_tac_71},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:291:13");
AssignD({(Addr)&s2}, (Addr)&temp_var_for_tac_72,
        "/home/shijia/Public/testprogram/s_pone.c_e.c:291:6");
;
double temp_var_for_tac_73, temp_var_for_tac_74;
double temp_var_for_const_81, temp_var_for_const_82;
temp_var_for_tac_73 = z * q[4];

temp_var_for_tac_74 = q[3] + temp_var_for_tac_73;

s3 = temp_var_for_tac_74;
computeDMul((Addr)&temp_var_for_tac_73,
            {(Addr)&z, (Addr) &(temp_var_for_const_81 = q[4])},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:292:17");
computeDAdd((Addr)&temp_var_for_tac_74, {(Addr) &(temp_var_for_const_82 = q[3]),
                                         (Addr)&temp_var_for_tac_73},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:292:13");
AssignD({(Addr)&s3}, (Addr)&temp_var_for_tac_74,
        "/home/shijia/Public/testprogram/s_pone.c_e.c:292:6");
;
double temp_var_for_tac_75, temp_var_for_tac_76, temp_var_for_tac_77,
    temp_var_for_tac_78, temp_var_for_tac_79, temp_var_for_tac_80;
double temp_var_for_const_83;
temp_var_for_tac_75 = z2 * s2;

temp_var_for_tac_76 = s1 + temp_var_for_tac_75;

temp_var_for_tac_77 = z4 * s3;

temp_var_for_tac_78 = temp_var_for_tac_76 + temp_var_for_tac_77;

temp_var_for_tac_79 = z6 * q[5];

temp_var_for_tac_80 = temp_var_for_tac_78 + temp_var_for_tac_79;

s = temp_var_for_tac_80;
computeDMul((Addr)&temp_var_for_tac_75, {(Addr)&z2, (Addr)&s2},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:293:15");
computeDAdd((Addr)&temp_var_for_tac_76, {(Addr)&s1, (Addr)&temp_var_for_tac_75},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:293:10");
computeDMul((Addr)&temp_var_for_tac_77, {(Addr)&z4, (Addr)&s3},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:293:25");
computeDAdd((Addr)&temp_var_for_tac_78,
            {(Addr)&temp_var_for_tac_76, (Addr)&temp_var_for_tac_77},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:293:20");
computeDMul((Addr)&temp_var_for_tac_79,
            {(Addr)&z6, (Addr) &(temp_var_for_const_83 = q[5])},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:293:35");
computeDAdd((Addr)&temp_var_for_tac_80,
            {(Addr)&temp_var_for_tac_78, (Addr)&temp_var_for_tac_79},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:293:30");
AssignD({(Addr)&s}, (Addr)&temp_var_for_tac_80,
        "/home/shijia/Public/testprogram/s_pone.c_e.c:293:5");
;
#endif
double temp_var_for_ext_3;
double temp_var_for_tac_81, temp_var_for_tac_82, temp_var_for_tac_83;
double temp_var_for_const_84;
temp_var_for_tac_81 = r / s;

temp_var_for_tac_82 = .375 + temp_var_for_tac_81;

temp_var_for_tac_83 = temp_var_for_tac_82 / x;

temp_var_for_ext_3 = temp_var_for_tac_83;
computeDDiv((Addr)&temp_var_for_tac_81, {(Addr)&r, (Addr)&s},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:296:34");
computeDAdd((Addr)&temp_var_for_tac_82, {(Addr) &(temp_var_for_const_84 = .375),
                                         (Addr)&temp_var_for_tac_81},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:296:30");
computeDDiv((Addr)&temp_var_for_tac_83, {(Addr)&temp_var_for_tac_82, (Addr)&x},
            "/home/shijia/Public/testprogram/s_pone.c_e.c:296:39");
AssignD({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_83,
        "/home/shijia/Public/testprogram/s_pone.c_e.c:296:22");
;
callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
callExp++; /*identify the function is  add move tmpShadow*/
return temp_var_for_ext_3;
}
