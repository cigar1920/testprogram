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

double __j0_y0_pzero(double x) {
  const double *p, *q;
  double z, r, s, z2, z4, r1, r2, r3, s1, s2, s3;
  int32_t ix;

  static const double one = 1.0;

  /* The asymptotic expansions of pzero is
   *	1 - 9/128 s^2 + 11025/98304 s^4 - ...,	where s = 1/x.
   * For x >= 2, We approximate pzero by
   *  pzero(x) = 1 + (R/S)
   * where  R = pR0 + pR1*s^2 + pR2*s^4 + ... + pR5*s^10
   *	  S = 1 + pS0*s^2 + ... + pS4*s^10
   * and
   *	| pzero(x)-1-R/S | <= 2  ** ( -60.26)
   */
  static const double pR8[6] = {
      /* for x in [inf, 8]=1/[0,0.125] */
      0.00000000000000000000e+00,         /* 0x00000000, 0x00000000 */
      (double temp_var_for_tac_0;
  double temp_var_for_const_0, temp_var_for_const_1;
  temp_var_for_tac_0 = 0.0 - 7.03124999999900357484e-02;

), /* 0xBFB1FFFF, 0xFFFFFD32 */
      (double temp_var_for_tac_1;double temp_var_for_const_2,temp_var_for_const_3;temp_var_for_tac_1 = 0.0 - 8.08167041275349795626e+00;

), /* 0xC02029D0, 0xB44FA779 */
      (double temp_var_for_tac_2;double temp_var_for_const_4,temp_var_for_const_5;temp_var_for_tac_2 = 0.0 - 2.57063105679704847262e+02;

), /* 0xC0701102, 0x7B19E863 */
      (double temp_var_for_tac_3;double temp_var_for_const_6,temp_var_for_const_7;temp_var_for_tac_3 = 0.0 - 2.48521641009428822144e+03;

), /* 0xC0A36A6E, 0xCD4DCAFC */
      (double temp_var_for_tac_4;double temp_var_for_const_8,temp_var_for_const_9;temp_var_for_tac_4 = 0.0 - 5.25304380490729545272e+03;

)  /* 0xC0B4850B, 0x36CC643D */
};

static const double pS8[5] = {
    1.16534364619668181717e+02, /* 0x405D2233, 0x07A96751 */
    3.83374475364121826715e+03, /* 0x40ADF37D, 0x50596938 */
    4.05978572648472545552e+04, /* 0x40E3D2BB, 0x6EB6B05F */
    1.16752972564375915681e+05, /* 0x40FC810F, 0x8F9FA9BD */
    4.76277284146730962675e+04  /* 0x40E74177, 0x4F2C49DC */
};

  static const double pR5[6] = {
      /* for x in [8,4.5454]=1/[0.125,0.22001] */
      (double temp_var_for_tac_5;
  double temp_var_for_const_10, temp_var_for_const_11;
  temp_var_for_tac_5 = 0.0 - 1.14125464691894502584e-11;

), /* 0xBDA918B1, 0x47E495CC */
      (double temp_var_for_tac_6;double temp_var_for_const_12,temp_var_for_const_13;temp_var_for_tac_6 = 0.0 - 7.03124940873599280078e-02;

), /* 0xBFB1FFFF, 0xE69AFBC6 */
      (double temp_var_for_tac_7;double temp_var_for_const_14,temp_var_for_const_15;temp_var_for_tac_7 = 0.0 - 4.15961064470587782438e+00;

), /* 0xC010A370, 0xF90C6BBF */
      (double temp_var_for_tac_8;double temp_var_for_const_16,temp_var_for_const_17;temp_var_for_tac_8 = 0.0 - 6.76747652265167261021e+01;

), /* 0xC050EB2F, 0x5A7D1783 */
      (double temp_var_for_tac_9;double temp_var_for_const_18,temp_var_for_const_19;temp_var_for_tac_9 = 0.0 - 3.31231299649172967747e+02;

), /* 0xC074B3B3, 0x6742CC63 */
      (double temp_var_for_tac_10;double temp_var_for_const_20,temp_var_for_const_21;temp_var_for_tac_10 = 0.0 - 3.46433388365604912451e+02;

)  /* 0xC075A6EF, 0x28A38BD7 */
}
;

static const double pS5[5] = {
    6.07539382692300335975e+01, /* 0x404E6081, 0x0C98C5DE */
    1.05125230595704579173e+03, /* 0x40906D02, 0x5C7E2864 */
    5.97897094333855784498e+03, /* 0x40B75AF8, 0x8FBE1D60 */
    9.62544514357774460223e+03, /* 0x40C2CCB8, 0xFA76FA38 */
    2.40605815922939109441e+03  /* 0x40A2CC1D, 0xC70BE864 */
};

  static const double pR3[6] = {
      /* for x in [4.547,2.8571]=1/[0.2199,0.35001] */
      (double temp_var_for_tac_11;
  double temp_var_for_const_22, temp_var_for_const_23;
  temp_var_for_tac_11 = 0.0 - 2.54704601771951915620e-09;

), /* 0xBE25E103, 0x6FE1AA86 */
      (double temp_var_for_tac_12;double temp_var_for_const_24,temp_var_for_const_25;temp_var_for_tac_12 = 0.0 - 7.03119616381481654654e-02;

), /* 0xBFB1FFF6, 0xF7C0E24B */
      (double temp_var_for_tac_13;double temp_var_for_const_26,temp_var_for_const_27;temp_var_for_tac_13 = 0.0 - 2.40903221549529611423e+00;

), /* 0xC00345B2, 0xAEA48074 */
      (double temp_var_for_tac_14;double temp_var_for_const_28,temp_var_for_const_29;temp_var_for_tac_14 = 0.0 - 2.19659774734883086467e+01;

), /* 0xC035F74A, 0x4CB94E14 */
      (double temp_var_for_tac_15;double temp_var_for_const_30,temp_var_for_const_31;temp_var_for_tac_15 = 0.0 - 5.80791704701737572236e+01;

), /* 0xC04D0A22, 0x420A1A45 */
      (double temp_var_for_tac_16;double temp_var_for_const_32,temp_var_for_const_33;temp_var_for_tac_16 = 0.0 - 3.14479470594888503854e+01;

)  /* 0xC03F72AC, 0xA892D80F */
}
;

static const double pS3[5] = {
    3.58560338055209726349e+01, /* 0x4041ED92, 0x84077DD3 */
    3.61513983050303863820e+02, /* 0x40769839, 0x464A7C0E */
    1.19360783792111533330e+03, /* 0x4092A66E, 0x6D1061D6 */
    1.12799679856907414432e+03, /* 0x40919FFC, 0xB8C39B7E */
    1.73580930813335754692e+02  /* 0x4065B296, 0xFC379081 */
};

  static const double pR2[6] = {
      /* for x in [2.8570,2]=1/[0.3499,0.5] */
      (double temp_var_for_tac_17;
  double temp_var_for_const_34, temp_var_for_const_35;
  temp_var_for_tac_17 = 0.0 - 8.87534333032526411254e-08;

), /* 0xBE77D316, 0xE927026D */
      (double temp_var_for_tac_18;double temp_var_for_const_36,temp_var_for_const_37;temp_var_for_tac_18 = 0.0 - 7.03030995483624743247e-02;

), /* 0xBFB1FF62, 0x495E1E42 */
      (double temp_var_for_tac_19;double temp_var_for_const_38,temp_var_for_const_39;temp_var_for_tac_19 = 0.0 - 1.45073846780952986357e+00;

), /* 0xBFF73639, 0x8A24A843 */
      (double temp_var_for_tac_20;double temp_var_for_const_40,temp_var_for_const_41;temp_var_for_tac_20 = 0.0 - 7.63569613823527770791e+00;

), /* 0xC01E8AF3, 0xEDAFA7F3 */
      (double temp_var_for_tac_21;double temp_var_for_const_42,temp_var_for_const_43;temp_var_for_tac_21 = 0.0 - 1.11931668860356747786e+01;

), /* 0xC02662E6, 0xC5246303 */
      (double temp_var_for_tac_22;double temp_var_for_const_44,temp_var_for_const_45;temp_var_for_tac_22 = 0.0 - 3.23364579351335335033e+00;

)  /* 0xC009DE81, 0xAF8FE70F */
}
;

static const double pS2[5] = {
    2.22202997532088808441e+01, /* 0x40363865, 0x908B5959 */
    1.36206794218215208048e+02, /* 0x4061069E, 0x0EE8878F */
    2.70470278658083486789e+02, /* 0x4070E786, 0x42EA079B */
    1.53875394208320329881e+02, /* 0x40633C03, 0x3AB6FAFF */
    1.46576176948256193810e+01  /* 0x402D50B3, 0x44391809 */
};

GET_HIGH_WORD(ix, x);
ix &= IC(0x7fffffff);
if (ix >= IC(0x41b00000)) {
  /* x >= 2**28 */
  double temp_var_for_ext_0;
  double temp_var_for_const_46;
  temp_var_for_ext_0 = one;
  computeDSub((Addr)&temp_var_for_tac_0,
              {(Addr) &(temp_var_for_const_1 = 0.0),
               (Addr) &(temp_var_for_const_0 = 7.03124999999900357484e-02)},
              "/home/shijia/Public/testprogram/s_pzero.c_e.c:35:12");
  computeDSub((Addr)&temp_var_for_tac_1,
              {(Addr) &(temp_var_for_const_3 = 0.0),
               (Addr) &(temp_var_for_const_2 = 8.08167041275349795626e+00)},
              "/home/shijia/Public/testprogram/s_pzero.c_e.c:36:12");
  computeDSub((Addr)&temp_var_for_tac_2,
              {(Addr) &(temp_var_for_const_5 = 0.0),
               (Addr) &(temp_var_for_const_4 = 2.57063105679704847262e+02)},
              "/home/shijia/Public/testprogram/s_pzero.c_e.c:37:12");
  computeDSub((Addr)&temp_var_for_tac_3,
              {(Addr) &(temp_var_for_const_7 = 0.0),
               (Addr) &(temp_var_for_const_6 = 2.48521641009428822144e+03)},
              "/home/shijia/Public/testprogram/s_pzero.c_e.c:38:12");
  computeDSub((Addr)&temp_var_for_tac_4,
              {(Addr) &(temp_var_for_const_9 = 0.0),
               (Addr) &(temp_var_for_const_8 = 5.25304380490729545272e+03)},
              "/home/shijia/Public/testprogram/s_pzero.c_e.c:39:12");
  computeDSub((Addr)&temp_var_for_tac_5,
              {(Addr) &(temp_var_for_const_11 = 0.0),
               (Addr) &(temp_var_for_const_10 = 1.14125464691894502584e-11)},
              "/home/shijia/Public/testprogram/s_pzero.c_e.c:52:12");
  computeDSub((Addr)&temp_var_for_tac_6,
              {(Addr) &(temp_var_for_const_13 = 0.0),
               (Addr) &(temp_var_for_const_12 = 7.03124940873599280078e-02)},
              "/home/shijia/Public/testprogram/s_pzero.c_e.c:53:12");
  computeDSub((Addr)&temp_var_for_tac_7,
              {(Addr) &(temp_var_for_const_15 = 0.0),
               (Addr) &(temp_var_for_const_14 = 4.15961064470587782438e+00)},
              "/home/shijia/Public/testprogram/s_pzero.c_e.c:54:12");
  computeDSub((Addr)&temp_var_for_tac_8,
              {(Addr) &(temp_var_for_const_17 = 0.0),
               (Addr) &(temp_var_for_const_16 = 6.76747652265167261021e+01)},
              "/home/shijia/Public/testprogram/s_pzero.c_e.c:55:12");
  computeDSub((Addr)&temp_var_for_tac_9,
              {(Addr) &(temp_var_for_const_19 = 0.0),
               (Addr) &(temp_var_for_const_18 = 3.31231299649172967747e+02)},
              "/home/shijia/Public/testprogram/s_pzero.c_e.c:56:12");
  computeDSub((Addr)&temp_var_for_tac_10,
              {(Addr) &(temp_var_for_const_21 = 0.0),
               (Addr) &(temp_var_for_const_20 = 3.46433388365604912451e+02)},
              "/home/shijia/Public/testprogram/s_pzero.c_e.c:57:12");
  computeDSub((Addr)&temp_var_for_tac_11,
              {(Addr) &(temp_var_for_const_23 = 0.0),
               (Addr) &(temp_var_for_const_22 = 2.54704601771951915620e-09)},
              "/home/shijia/Public/testprogram/s_pzero.c_e.c:70:12");
  computeDSub((Addr)&temp_var_for_tac_12,
              {(Addr) &(temp_var_for_const_25 = 0.0),
               (Addr) &(temp_var_for_const_24 = 7.03119616381481654654e-02)},
              "/home/shijia/Public/testprogram/s_pzero.c_e.c:71:12");
  computeDSub((Addr)&temp_var_for_tac_13,
              {(Addr) &(temp_var_for_const_27 = 0.0),
               (Addr) &(temp_var_for_const_26 = 2.40903221549529611423e+00)},
              "/home/shijia/Public/testprogram/s_pzero.c_e.c:72:12");
  computeDSub((Addr)&temp_var_for_tac_14,
              {(Addr) &(temp_var_for_const_29 = 0.0),
               (Addr) &(temp_var_for_const_28 = 2.19659774734883086467e+01)},
              "/home/shijia/Public/testprogram/s_pzero.c_e.c:73:12");
  computeDSub((Addr)&temp_var_for_tac_15,
              {(Addr) &(temp_var_for_const_31 = 0.0),
               (Addr) &(temp_var_for_const_30 = 5.80791704701737572236e+01)},
              "/home/shijia/Public/testprogram/s_pzero.c_e.c:74:12");
  computeDSub((Addr)&temp_var_for_tac_16,
              {(Addr) &(temp_var_for_const_33 = 0.0),
               (Addr) &(temp_var_for_const_32 = 3.14479470594888503854e+01)},
              "/home/shijia/Public/testprogram/s_pzero.c_e.c:75:12");
  computeDSub((Addr)&temp_var_for_tac_17,
              {(Addr) &(temp_var_for_const_35 = 0.0),
               (Addr) &(temp_var_for_const_34 = 8.87534333032526411254e-08)},
              "/home/shijia/Public/testprogram/s_pzero.c_e.c:88:12");
  computeDSub((Addr)&temp_var_for_tac_18,
              {(Addr) &(temp_var_for_const_37 = 0.0),
               (Addr) &(temp_var_for_const_36 = 7.03030995483624743247e-02)},
              "/home/shijia/Public/testprogram/s_pzero.c_e.c:89:12");
  computeDSub((Addr)&temp_var_for_tac_19,
              {(Addr) &(temp_var_for_const_39 = 0.0),
               (Addr) &(temp_var_for_const_38 = 1.45073846780952986357e+00)},
              "/home/shijia/Public/testprogram/s_pzero.c_e.c:90:12");
  computeDSub((Addr)&temp_var_for_tac_20,
              {(Addr) &(temp_var_for_const_41 = 0.0),
               (Addr) &(temp_var_for_const_40 = 7.63569613823527770791e+00)},
              "/home/shijia/Public/testprogram/s_pzero.c_e.c:91:12");
  computeDSub((Addr)&temp_var_for_tac_21,
              {(Addr) &(temp_var_for_const_43 = 0.0),
               (Addr) &(temp_var_for_const_42 = 1.11931668860356747786e+01)},
              "/home/shijia/Public/testprogram/s_pzero.c_e.c:92:12");
  computeDSub((Addr)&temp_var_for_tac_22,
              {(Addr) &(temp_var_for_const_45 = 0.0),
               (Addr) &(temp_var_for_const_44 = 3.23364579351335335033e+00)},
              "/home/shijia/Public/testprogram/s_pzero.c_e.c:93:12");
  AssignD({(Addr)&temp_var_for_ext_0}, (Addr) &(temp_var_for_const_46 = one),
          "/home/shijia/Public/testprogram/s_pzero.c_e.c:109:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
} else {
  if (ix >= IC(0x40200000)) {
    /* x >= 8 */
    p = pR8;
    q = pS8;
  } else {
    if (ix >= IC(0x40122E8B)) {
      /* x >= 4.545452117919921875 */
      p = pR5;
      q = pS5;
    } else {
      if (ix >= IC(0x4006DB6D)) {
        /* x >= 2.8571414947509765625 */
        p = pR3;
        q = pS3;
      } else /* if (ix >= IC(0x40000000)) */
      {
        /* x >= 2 */
        p = pR2;
        q = pS2;
      }
    }
  }
}

double temp_var_for_tac_23, temp_var_for_tac_24;
double temp_var_for_const_47;
temp_var_for_tac_23 = x * x;

temp_var_for_tac_24 = one / temp_var_for_tac_23;

z = temp_var_for_tac_24;
computeDMul((Addr)&temp_var_for_tac_23, {(Addr)&x, (Addr)&x},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:138:16");
computeDDiv((Addr)&temp_var_for_tac_24,
            {(Addr) &(temp_var_for_const_47 = one), (Addr)&temp_var_for_tac_23},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:138:11");
AssignD({(Addr)&z}, (Addr)&temp_var_for_tac_24,
        "/home/shijia/Public/testprogram/s_pzero.c_e.c:138:5");
;
#ifdef DO_NOT_USE_THIS
r = p[0] + z * (p[1] + z * (p[2] + z * (p[3] + z * (p[4] + z * p[5]))));
s = one + z * (q[0] + z * (q[1] + z * (q[2] + z * (q[3] + z * q[4]))));
#else
double temp_var_for_tac_25, temp_var_for_tac_26;
double temp_var_for_const_48, temp_var_for_const_49;
temp_var_for_tac_25 = z * p[1];

temp_var_for_tac_26 = p[0] + temp_var_for_tac_25;

r1 = temp_var_for_tac_26;
computeDMul((Addr)&temp_var_for_tac_25,
            {(Addr)&z, (Addr) &(temp_var_for_const_48 = p[1])},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:143:17");
computeDAdd((Addr)&temp_var_for_tac_26, {(Addr) &(temp_var_for_const_49 = p[0]),
                                         (Addr)&temp_var_for_tac_25},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:143:13");
AssignD({(Addr)&r1}, (Addr)&temp_var_for_tac_26,
        "/home/shijia/Public/testprogram/s_pzero.c_e.c:143:6");
;
double temp_var_for_tac_27;
temp_var_for_tac_27 = z * z;

z2 = temp_var_for_tac_27;
computeDMul((Addr)&temp_var_for_tac_27, {(Addr)&z, (Addr)&z},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:144:10");
AssignD({(Addr)&z2}, (Addr)&temp_var_for_tac_27,
        "/home/shijia/Public/testprogram/s_pzero.c_e.c:144:6");
;
double temp_var_for_tac_28, temp_var_for_tac_29;
double temp_var_for_const_50, temp_var_for_const_51;
temp_var_for_tac_28 = z * p[3];

temp_var_for_tac_29 = p[2] + temp_var_for_tac_28;

r2 = temp_var_for_tac_29;
computeDMul((Addr)&temp_var_for_tac_28,
            {(Addr)&z, (Addr) &(temp_var_for_const_50 = p[3])},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:145:17");
computeDAdd((Addr)&temp_var_for_tac_29, {(Addr) &(temp_var_for_const_51 = p[2]),
                                         (Addr)&temp_var_for_tac_28},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:145:13");
AssignD({(Addr)&r2}, (Addr)&temp_var_for_tac_29,
        "/home/shijia/Public/testprogram/s_pzero.c_e.c:145:6");
;
double temp_var_for_tac_30;
temp_var_for_tac_30 = z2 * z2;

z4 = temp_var_for_tac_30;
computeDMul((Addr)&temp_var_for_tac_30, {(Addr)&z2, (Addr)&z2},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:146:11");
AssignD({(Addr)&z4}, (Addr)&temp_var_for_tac_30,
        "/home/shijia/Public/testprogram/s_pzero.c_e.c:146:6");
;
double temp_var_for_tac_31, temp_var_for_tac_32;
double temp_var_for_const_52, temp_var_for_const_53;
temp_var_for_tac_31 = z * p[5];

temp_var_for_tac_32 = p[4] + temp_var_for_tac_31;

r3 = temp_var_for_tac_32;
computeDMul((Addr)&temp_var_for_tac_31,
            {(Addr)&z, (Addr) &(temp_var_for_const_52 = p[5])},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:147:17");
computeDAdd((Addr)&temp_var_for_tac_32, {(Addr) &(temp_var_for_const_53 = p[4]),
                                         (Addr)&temp_var_for_tac_31},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:147:13");
AssignD({(Addr)&r3}, (Addr)&temp_var_for_tac_32,
        "/home/shijia/Public/testprogram/s_pzero.c_e.c:147:6");
;
double temp_var_for_tac_33, temp_var_for_tac_34, temp_var_for_tac_35,
    temp_var_for_tac_36;
temp_var_for_tac_33 = z2 * r2;

temp_var_for_tac_34 = r1 + temp_var_for_tac_33;

temp_var_for_tac_35 = z4 * r3;

temp_var_for_tac_36 = temp_var_for_tac_34 + temp_var_for_tac_35;

r = temp_var_for_tac_36;
computeDMul((Addr)&temp_var_for_tac_33, {(Addr)&z2, (Addr)&r2},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:148:15");
computeDAdd((Addr)&temp_var_for_tac_34, {(Addr)&r1, (Addr)&temp_var_for_tac_33},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:148:10");
computeDMul((Addr)&temp_var_for_tac_35, {(Addr)&z4, (Addr)&r3},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:148:25");
computeDAdd((Addr)&temp_var_for_tac_36,
            {(Addr)&temp_var_for_tac_34, (Addr)&temp_var_for_tac_35},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:148:20");
AssignD({(Addr)&r}, (Addr)&temp_var_for_tac_36,
        "/home/shijia/Public/testprogram/s_pzero.c_e.c:148:5");
;
double temp_var_for_tac_37, temp_var_for_tac_38;
double temp_var_for_const_54, temp_var_for_const_55;
temp_var_for_tac_37 = z * q[0];

temp_var_for_tac_38 = one + temp_var_for_tac_37;

s1 = temp_var_for_tac_38;
computeDMul((Addr)&temp_var_for_tac_37,
            {(Addr)&z, (Addr) &(temp_var_for_const_54 = q[0])},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:149:16");
computeDAdd((Addr)&temp_var_for_tac_38,
            {(Addr) &(temp_var_for_const_55 = one), (Addr)&temp_var_for_tac_37},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:149:12");
AssignD({(Addr)&s1}, (Addr)&temp_var_for_tac_38,
        "/home/shijia/Public/testprogram/s_pzero.c_e.c:149:6");
;
double temp_var_for_tac_39, temp_var_for_tac_40;
double temp_var_for_const_56, temp_var_for_const_57;
temp_var_for_tac_39 = z * q[2];

temp_var_for_tac_40 = q[1] + temp_var_for_tac_39;

s2 = temp_var_for_tac_40;
computeDMul((Addr)&temp_var_for_tac_39,
            {(Addr)&z, (Addr) &(temp_var_for_const_56 = q[2])},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:150:17");
computeDAdd((Addr)&temp_var_for_tac_40, {(Addr) &(temp_var_for_const_57 = q[1]),
                                         (Addr)&temp_var_for_tac_39},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:150:13");
AssignD({(Addr)&s2}, (Addr)&temp_var_for_tac_40,
        "/home/shijia/Public/testprogram/s_pzero.c_e.c:150:6");
;
double temp_var_for_tac_41, temp_var_for_tac_42;
double temp_var_for_const_58, temp_var_for_const_59;
temp_var_for_tac_41 = z * q[4];

temp_var_for_tac_42 = q[3] + temp_var_for_tac_41;

s3 = temp_var_for_tac_42;
computeDMul((Addr)&temp_var_for_tac_41,
            {(Addr)&z, (Addr) &(temp_var_for_const_58 = q[4])},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:151:17");
computeDAdd((Addr)&temp_var_for_tac_42, {(Addr) &(temp_var_for_const_59 = q[3]),
                                         (Addr)&temp_var_for_tac_41},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:151:13");
AssignD({(Addr)&s3}, (Addr)&temp_var_for_tac_42,
        "/home/shijia/Public/testprogram/s_pzero.c_e.c:151:6");
;
double temp_var_for_tac_43, temp_var_for_tac_44, temp_var_for_tac_45,
    temp_var_for_tac_46;
temp_var_for_tac_43 = z2 * s2;

temp_var_for_tac_44 = s1 + temp_var_for_tac_43;

temp_var_for_tac_45 = z4 * s3;

temp_var_for_tac_46 = temp_var_for_tac_44 + temp_var_for_tac_45;

s = temp_var_for_tac_46;
computeDMul((Addr)&temp_var_for_tac_43, {(Addr)&z2, (Addr)&s2},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:152:15");
computeDAdd((Addr)&temp_var_for_tac_44, {(Addr)&s1, (Addr)&temp_var_for_tac_43},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:152:10");
computeDMul((Addr)&temp_var_for_tac_45, {(Addr)&z4, (Addr)&s3},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:152:25");
computeDAdd((Addr)&temp_var_for_tac_46,
            {(Addr)&temp_var_for_tac_44, (Addr)&temp_var_for_tac_45},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:152:20");
AssignD({(Addr)&s}, (Addr)&temp_var_for_tac_46,
        "/home/shijia/Public/testprogram/s_pzero.c_e.c:152:5");
;
#endif
double temp_var_for_ext_1;
double temp_var_for_tac_47, temp_var_for_tac_48;
double temp_var_for_const_60;
temp_var_for_tac_47 = r / s;

temp_var_for_tac_48 = one + temp_var_for_tac_47;

temp_var_for_ext_1 = temp_var_for_tac_48;
computeDDiv((Addr)&temp_var_for_tac_47, {(Addr)&r, (Addr)&s},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:155:32");
computeDAdd((Addr)&temp_var_for_tac_48,
            {(Addr) &(temp_var_for_const_60 = one), (Addr)&temp_var_for_tac_47},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:155:28");
AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_48,
        "/home/shijia/Public/testprogram/s_pzero.c_e.c:155:22");
;
callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
callExp++; /*identify the function is  add move tmpShadow*/
return temp_var_for_ext_1;
}

double __j0_y0_qzero(double x) {
  const double *p, *q;
  double s, r, z, z2, z4, z6, r1, r2, r3, s1, s2, s3;
  int32_t ix;

  static const double one = 1.0;

  /* For x >= 8, the asymptotic expansions of qzero is
   *	-1/8 s + 75/1024 s^3 - ..., where s = 1/x.
   * We approximate pzero by
   *	qzero(x) = s*(-1.25 + (R/S))
   * where  R = qR0 + qR1*s^2 + qR2*s^4 + ... + qR5*s^10
   *  S = 1 + qS0*s^2 + ... + qS5*s^12
   * and
   *	| qzero(x)/s +1.25-R/S | <= 2  ** ( -61.22)
   */
  static const double qR8[6] = {
      /* for x in [inf, 8]=1/[0,0.125] */
      0.00000000000000000000e+00, /* 0x00000000, 0x00000000 */
      7.32421874999935051953e-02, /* 0x3FB2BFFF, 0xFFFFFE2C */
      1.17682064682252693899e+01, /* 0x40278952, 0x5BB334D6 */
      5.57673380256401856059e+02, /* 0x40816D63, 0x15301825 */
      8.85919720756468632317e+03, /* 0x40C14D99, 0x3E18F46D */
      3.70146267776887834771e+04  /* 0x40E212D4, 0x0E901566 */
  };

  static const double qS8[6] = {
      1.63776026895689824414e+02,        /* 0x406478D5, 0x365B39BC */
      8.09834494656449805916e+03,        /* 0x40BFA258, 0x4E6B0563 */
      1.42538291419120476348e+05,        /* 0x41016652, 0x54D38C3F */
      8.03309257119514397345e+05,        /* 0x412883DA, 0x83A52B43 */
      8.40501579819060512818e+05,        /* 0x4129A66B, 0x28DE0B3D */
      (double temp_var_for_tac_49;
  double temp_var_for_const_61, temp_var_for_const_62;
  temp_var_for_tac_49 = 0.0 - 3.43899293537866615225e+05;

) /* 0xC114FD6D, 0x2C9530C5 */
};

static const double qR5[6] = {
    /* for x in [8,4.5454]=1/[0.125,0.22001] */
    1.84085963594515531381e-11, /* 0x3DB43D8F, 0x29CC8CD9 */
    7.32421766612684765896e-02, /* 0x3FB2BFFF, 0xD172B04C */
    5.83563508962056953777e+00, /* 0x401757B0, 0xB9953DD3 */
    1.35111577286449829671e+02, /* 0x4060E392, 0x0A8788E9 */
    1.02724376596164097464e+03, /* 0x40900CF9, 0x9DC8C481 */
    1.98997785864605384631e+03  /* 0x409F17E9, 0x53C6E3A6 */
};

  static const double qS5[6] = {
      8.27766102236537761883e+01,        /* 0x4054B1B3, 0xFB5E1543 */
      2.07781416421392987104e+03,        /* 0x40A03BA0, 0xDA21C0CE */
      1.88472887785718085070e+04,        /* 0x40D267D2, 0x7B591E6D */
      5.67511122894947329769e+04,        /* 0x40EBB5E3, 0x97E02372 */
      3.59767538425114471465e+04,        /* 0x40E19118, 0x1F7A54A0 */
      (double temp_var_for_tac_50;
  double temp_var_for_const_63, temp_var_for_const_64;
  temp_var_for_tac_50 = 0.0 - 5.35434275601944773371e+03;

) /* 0xC0B4EA57, 0xBEDBC609 */
}
;

static const double qR3[6] = {
    /* for x in [4.547,2.8571]=1/[0.2199,0.35001] */
    4.37741014089738620906e-09, /* 0x3E32CD03, 0x6ADECB82 */
    7.32411180042911447163e-02, /* 0x3FB2BFEE, 0x0E8D0842 */
    3.34423137516170720929e+00, /* 0x400AC0FC, 0x61149CF5 */
    4.26218440745412650017e+01, /* 0x40454F98, 0x962DAEDD */
    1.70808091340565596283e+02, /* 0x406559DB, 0xE25EFD1F */
    1.66733948696651168575e+02  /* 0x4064D77C, 0x81FA21E0 */
};

  static const double qS3[6] = {
      4.87588729724587182091e+01,        /* 0x40486122, 0xBFE343A6 */
      7.09689221056606015736e+02,        /* 0x40862D83, 0x86544EB3 */
      3.70414822620111362994e+03,        /* 0x40ACF04B, 0xE44DFC63 */
      6.46042516752568917582e+03,        /* 0x40B93C6C, 0xD7C76A28 */
      2.51633368920368957333e+03,        /* 0x40A3A8AA, 0xD94FB1C0 */
      (double temp_var_for_tac_51;
  double temp_var_for_const_65, temp_var_for_const_66;
  temp_var_for_tac_51 = 0.0 - 1.49247451836156386662e+02;

) /* 0xC062A7EB, 0x201CF40F */
}
;

static const double qR2[6] = {
    /* for x in [2.8570,2]=1/[0.3499,0.5] */
    1.50444444886983272379e-07, /* 0x3E84313B, 0x54F76BDB */
    7.32234265963079278272e-02, /* 0x3FB2BEC5, 0x3E883E34 */
    1.99819174093815998816e+00, /* 0x3FFFF897, 0xE727779C */
    1.44956029347885735348e+01, /* 0x402CFDBF, 0xAAF96FE5 */
    3.16662317504781540833e+01, /* 0x403FAA8E, 0x29FBDC4A */
    1.62527075710929267416e+01  /* 0x403040B1, 0x71814BB4 */
};

  static const double qS2[6] = {
      3.03655848355219184498e+01,        /* 0x403E5D96, 0xF7C07AED */
      2.69348118608049844624e+02,        /* 0x4070D591, 0xE4D14B40 */
      8.44783757595320139444e+02,        /* 0x408A6645, 0x22B3BF22 */
      8.82935845112488550512e+02,        /* 0x408B977C, 0x9C5CC214 */
      2.12666388511798828631e+02,        /* 0x406A9553, 0x0E001365 */
      (double temp_var_for_tac_52;
  double temp_var_for_const_67, temp_var_for_const_68;
  temp_var_for_tac_52 = 0.0 - 5.31095493882666946917e+00;

) /* 0xC0153E6A, 0xF8B32931 */
}
;

GET_HIGH_WORD(ix, x);
ix &= IC(0x7fffffff);
if (ix >= IC(0x41b00000)) {
  /* x >= 2**28 */
  double temp_var_for_ext_2;
  double temp_var_for_tac_53;
  double temp_var_for_const_69;
  temp_var_for_tac_53 = (-(.125)) / x;

  temp_var_for_ext_2 = temp_var_for_tac_53;
  computeDSub((Addr)&temp_var_for_tac_49,
              {(Addr) &(temp_var_for_const_62 = 0.0),
               (Addr) &(temp_var_for_const_61 = 3.43899293537866615225e+05)},
              "/home/shijia/Public/testprogram/s_pzero.c_e.c:193:12");
  computeDSub((Addr)&temp_var_for_tac_50,
              {(Addr) &(temp_var_for_const_64 = 0.0),
               (Addr) &(temp_var_for_const_63 = 5.35434275601944773371e+03)},
              "/home/shijia/Public/testprogram/s_pzero.c_e.c:212:12");
  computeDSub((Addr)&temp_var_for_tac_51,
              {(Addr) &(temp_var_for_const_66 = 0.0),
               (Addr) &(temp_var_for_const_65 = 1.49247451836156386662e+02)},
              "/home/shijia/Public/testprogram/s_pzero.c_e.c:231:12");
  computeDSub((Addr)&temp_var_for_tac_52,
              {(Addr) &(temp_var_for_const_68 = 0.0),
               (Addr) &(temp_var_for_const_67 = 5.31095493882666946917e+00)},
              "/home/shijia/Public/testprogram/s_pzero.c_e.c:250:12");
  computeDDiv((Addr)&temp_var_for_tac_53,
              {(Addr) &(temp_var_for_const_69 = (-(.125))), (Addr)&x},
              "/home/shijia/Public/testprogram/s_pzero.c_e.c:258:32");
  AssignD({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_53,
          "/home/shijia/Public/testprogram/s_pzero.c_e.c:258:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
  callExp++; /*identify the function is  add move tmpShadow*/
  return (0.0 - or_e)xt_2;
} else {
  if (ix >= IC(0x40200000)) {
    /* x >= 8 */
    p = qR8;
    q = qS8;
  } else {
    if (ix >= IC(0x40122E8B)) {
      /* x >= 4.545452117919921875 */
      p = qR5;
      q = qS5;
    } else {
      if (ix >= IC(0x4006DB6D)) {
        /* x >= 2.8571414947509765625 */
        p = qR3;
        q = qS3;
      } else /* if (ix >= IC(0x40000000)) */
      {
        /* x >= 2 */
        p = qR2;
        q = qS2;
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
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:287:16");
computeDDiv((Addr)&temp_var_for_tac_55,
            {(Addr) &(temp_var_for_const_70 = one), (Addr)&temp_var_for_tac_54},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:287:11");
AssignD({(Addr)&z}, (Addr)&temp_var_for_tac_55,
        "/home/shijia/Public/testprogram/s_pzero.c_e.c:287:5");
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
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:293:17");
computeDAdd((Addr)&temp_var_for_tac_57, {(Addr) &(temp_var_for_const_72 = p[0]),
                                         (Addr)&temp_var_for_tac_56},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:293:13");
AssignD({(Addr)&r1}, (Addr)&temp_var_for_tac_57,
        "/home/shijia/Public/testprogram/s_pzero.c_e.c:293:6");
;
double temp_var_for_tac_58;
temp_var_for_tac_58 = z * z;

z2 = temp_var_for_tac_58;
computeDMul((Addr)&temp_var_for_tac_58, {(Addr)&z, (Addr)&z},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:294:10");
AssignD({(Addr)&z2}, (Addr)&temp_var_for_tac_58,
        "/home/shijia/Public/testprogram/s_pzero.c_e.c:294:6");
;
double temp_var_for_tac_59, temp_var_for_tac_60;
double temp_var_for_const_73, temp_var_for_const_74;
temp_var_for_tac_59 = z * p[3];

temp_var_for_tac_60 = p[2] + temp_var_for_tac_59;

r2 = temp_var_for_tac_60;
computeDMul((Addr)&temp_var_for_tac_59,
            {(Addr)&z, (Addr) &(temp_var_for_const_73 = p[3])},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:295:17");
computeDAdd((Addr)&temp_var_for_tac_60, {(Addr) &(temp_var_for_const_74 = p[2]),
                                         (Addr)&temp_var_for_tac_59},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:295:13");
AssignD({(Addr)&r2}, (Addr)&temp_var_for_tac_60,
        "/home/shijia/Public/testprogram/s_pzero.c_e.c:295:6");
;
double temp_var_for_tac_61;
temp_var_for_tac_61 = z2 * z2;

z4 = temp_var_for_tac_61;
computeDMul((Addr)&temp_var_for_tac_61, {(Addr)&z2, (Addr)&z2},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:296:11");
AssignD({(Addr)&z4}, (Addr)&temp_var_for_tac_61,
        "/home/shijia/Public/testprogram/s_pzero.c_e.c:296:6");
;
double temp_var_for_tac_62, temp_var_for_tac_63;
double temp_var_for_const_75, temp_var_for_const_76;
temp_var_for_tac_62 = z * p[5];

temp_var_for_tac_63 = p[4] + temp_var_for_tac_62;

r3 = temp_var_for_tac_63;
computeDMul((Addr)&temp_var_for_tac_62,
            {(Addr)&z, (Addr) &(temp_var_for_const_75 = p[5])},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:297:17");
computeDAdd((Addr)&temp_var_for_tac_63, {(Addr) &(temp_var_for_const_76 = p[4]),
                                         (Addr)&temp_var_for_tac_62},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:297:13");
AssignD({(Addr)&r3}, (Addr)&temp_var_for_tac_63,
        "/home/shijia/Public/testprogram/s_pzero.c_e.c:297:6");
;
double temp_var_for_tac_64;
temp_var_for_tac_64 = z4 * z2;

z6 = temp_var_for_tac_64;
computeDMul((Addr)&temp_var_for_tac_64, {(Addr)&z4, (Addr)&z2},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:298:11");
AssignD({(Addr)&z6}, (Addr)&temp_var_for_tac_64,
        "/home/shijia/Public/testprogram/s_pzero.c_e.c:298:6");
;
double temp_var_for_tac_65, temp_var_for_tac_66, temp_var_for_tac_67,
    temp_var_for_tac_68;
temp_var_for_tac_65 = z2 * r2;

temp_var_for_tac_66 = r1 + temp_var_for_tac_65;

temp_var_for_tac_67 = z4 * r3;

temp_var_for_tac_68 = temp_var_for_tac_66 + temp_var_for_tac_67;

r = temp_var_for_tac_68;
computeDMul((Addr)&temp_var_for_tac_65, {(Addr)&z2, (Addr)&r2},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:299:15");
computeDAdd((Addr)&temp_var_for_tac_66, {(Addr)&r1, (Addr)&temp_var_for_tac_65},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:299:10");
computeDMul((Addr)&temp_var_for_tac_67, {(Addr)&z4, (Addr)&r3},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:299:25");
computeDAdd((Addr)&temp_var_for_tac_68,
            {(Addr)&temp_var_for_tac_66, (Addr)&temp_var_for_tac_67},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:299:20");
AssignD({(Addr)&r}, (Addr)&temp_var_for_tac_68,
        "/home/shijia/Public/testprogram/s_pzero.c_e.c:299:5");
;
double temp_var_for_tac_69, temp_var_for_tac_70;
double temp_var_for_const_77, temp_var_for_const_78;
temp_var_for_tac_69 = z * q[0];

temp_var_for_tac_70 = one + temp_var_for_tac_69;

s1 = temp_var_for_tac_70;
computeDMul((Addr)&temp_var_for_tac_69,
            {(Addr)&z, (Addr) &(temp_var_for_const_77 = q[0])},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:300:16");
computeDAdd((Addr)&temp_var_for_tac_70,
            {(Addr) &(temp_var_for_const_78 = one), (Addr)&temp_var_for_tac_69},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:300:12");
AssignD({(Addr)&s1}, (Addr)&temp_var_for_tac_70,
        "/home/shijia/Public/testprogram/s_pzero.c_e.c:300:6");
;
double temp_var_for_tac_71, temp_var_for_tac_72;
double temp_var_for_const_79, temp_var_for_const_80;
temp_var_for_tac_71 = z * q[2];

temp_var_for_tac_72 = q[1] + temp_var_for_tac_71;

s2 = temp_var_for_tac_72;
computeDMul((Addr)&temp_var_for_tac_71,
            {(Addr)&z, (Addr) &(temp_var_for_const_79 = q[2])},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:301:17");
computeDAdd((Addr)&temp_var_for_tac_72, {(Addr) &(temp_var_for_const_80 = q[1]),
                                         (Addr)&temp_var_for_tac_71},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:301:13");
AssignD({(Addr)&s2}, (Addr)&temp_var_for_tac_72,
        "/home/shijia/Public/testprogram/s_pzero.c_e.c:301:6");
;
double temp_var_for_tac_73, temp_var_for_tac_74;
double temp_var_for_const_81, temp_var_for_const_82;
temp_var_for_tac_73 = z * q[4];

temp_var_for_tac_74 = q[3] + temp_var_for_tac_73;

s3 = temp_var_for_tac_74;
computeDMul((Addr)&temp_var_for_tac_73,
            {(Addr)&z, (Addr) &(temp_var_for_const_81 = q[4])},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:302:17");
computeDAdd((Addr)&temp_var_for_tac_74, {(Addr) &(temp_var_for_const_82 = q[3]),
                                         (Addr)&temp_var_for_tac_73},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:302:13");
AssignD({(Addr)&s3}, (Addr)&temp_var_for_tac_74,
        "/home/shijia/Public/testprogram/s_pzero.c_e.c:302:6");
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
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:303:15");
computeDAdd((Addr)&temp_var_for_tac_76, {(Addr)&s1, (Addr)&temp_var_for_tac_75},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:303:10");
computeDMul((Addr)&temp_var_for_tac_77, {(Addr)&z4, (Addr)&s3},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:303:25");
computeDAdd((Addr)&temp_var_for_tac_78,
            {(Addr)&temp_var_for_tac_76, (Addr)&temp_var_for_tac_77},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:303:20");
computeDMul((Addr)&temp_var_for_tac_79,
            {(Addr)&z6, (Addr) &(temp_var_for_const_83 = q[5])},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:303:35");
computeDAdd((Addr)&temp_var_for_tac_80,
            {(Addr)&temp_var_for_tac_78, (Addr)&temp_var_for_tac_79},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:303:30");
AssignD({(Addr)&s}, (Addr)&temp_var_for_tac_80,
        "/home/shijia/Public/testprogram/s_pzero.c_e.c:303:5");
;
#endif
double temp_var_for_ext_3;
double temp_var_for_tac_81, temp_var_for_tac_82, temp_var_for_tac_83;
double temp_var_for_const_84;
temp_var_for_tac_81 = r / s;

temp_var_for_tac_82 = (-(.125)) + temp_var_for_tac_81;

temp_var_for_tac_83 = temp_var_for_tac_82 / x;

temp_var_for_ext_3 = temp_var_for_tac_83;
computeDDiv((Addr)&temp_var_for_tac_81, {(Addr)&r, (Addr)&s},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:306:35");
computeDAdd((Addr)&temp_var_for_tac_82,
            {(Addr) &(temp_var_for_const_84 = (-(.125))),
             (Addr)&temp_var_for_tac_81},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:306:31");
computeDDiv((Addr)&temp_var_for_tac_83, {(Addr)&temp_var_for_tac_82, (Addr)&x},
            "/home/shijia/Public/testprogram/s_pzero.c_e.c:306:40");
AssignD({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_83,
        "/home/shijia/Public/testprogram/s_pzero.c_e.c:306:22");
;
callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
callExp++; /*identify the function is  add move tmpShadow*/
return (0.0 - emp_)var_for_ext_3;
}
