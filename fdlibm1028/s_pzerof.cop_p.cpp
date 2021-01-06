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
      0.0000000000e+00,         /* 0x00000000 */
      (double temp_var_for_tac_0;
  double temp_var_for_const_0, temp_var_for_const_1;
  temp_var_for_tac_0 = 0.0 - 7.0312500000e-02;

), /* 0xbd900000 */
      (double temp_var_for_tac_1;double temp_var_for_const_2,temp_var_for_const_3;temp_var_for_tac_1 = 0.0 - 8.0816707611e+00;

), /* 0xc1014e86 */
      (double temp_var_for_tac_2;double temp_var_for_const_4,temp_var_for_const_5;temp_var_for_tac_2 = 0.0 - 2.5706311035e+02;

), /* 0xc3808814 */
      (double temp_var_for_tac_3;double temp_var_for_const_6,temp_var_for_const_7;temp_var_for_tac_3 = 0.0 - 2.4852163086e+03;

), /* 0xc51b5376 */
      (double temp_var_for_tac_4;double temp_var_for_const_8,temp_var_for_const_9;temp_var_for_tac_4 = 0.0 - 5.2530439453e+03;

)  /* 0xc5a4285a */
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
      (double temp_var_for_tac_5;
  double temp_var_for_const_10, temp_var_for_const_11;
  temp_var_for_tac_5 = 0.0 - 1.1412546255e-11;

), /* 0xad48c58a */
      (double temp_var_for_tac_6;double temp_var_for_const_12,temp_var_for_const_13;temp_var_for_tac_6 = 0.0 - 7.0312492549e-02;

), /* 0xbd8fffff */
      (double temp_var_for_tac_7;double temp_var_for_const_14,temp_var_for_const_15;temp_var_for_tac_7 = 0.0 - 4.1596107483e+00;

), /* 0xc0851b88 */
      (double temp_var_for_tac_8;double temp_var_for_const_16,temp_var_for_const_17;temp_var_for_tac_8 = 0.0 - 6.7674766541e+01;

), /* 0xc287597b */
      (double temp_var_for_tac_9;double temp_var_for_const_18,temp_var_for_const_19;temp_var_for_tac_9 = 0.0 - 3.3123129272e+02;

), /* 0xc3a59d9b */
      (double temp_var_for_tac_10;double temp_var_for_const_20,temp_var_for_const_21;temp_var_for_tac_10 = 0.0 - 3.4643338013e+02;

)  /* 0xc3ad3779 */
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
      (double temp_var_for_tac_11;
  double temp_var_for_const_22, temp_var_for_const_23;
  temp_var_for_tac_11 = 0.0 - 2.5470459075e-09;

), /* 0xb12f081b */
      (double temp_var_for_tac_12;double temp_var_for_const_24,temp_var_for_const_25;temp_var_for_tac_12 = 0.0 - 7.0311963558e-02;

), /* 0xbd8fffb8 */
      (double temp_var_for_tac_13;double temp_var_for_const_26,temp_var_for_const_27;temp_var_for_tac_13 = 0.0 - 2.4090321064e+00;

), /* 0xc01a2d95 */
      (double temp_var_for_tac_14;double temp_var_for_const_28,temp_var_for_const_29;temp_var_for_tac_14 = 0.0 - 2.1965976715e+01;

), /* 0xc1afba52 */
      (double temp_var_for_tac_15;double temp_var_for_const_30,temp_var_for_const_31;temp_var_for_tac_15 = 0.0 - 5.8079170227e+01;

), /* 0xc2685112 */
      (double temp_var_for_tac_16;double temp_var_for_const_32,temp_var_for_const_33;temp_var_for_tac_16 = 0.0 - 3.1447946548e+01;

)  /* 0xc1fb9565 */
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
      (double temp_var_for_tac_17;
  double temp_var_for_const_34, temp_var_for_const_35;
  temp_var_for_tac_17 = 0.0 - 8.8753431271e-08;

), /* 0xb3be98b7 */
      (double temp_var_for_tac_18;double temp_var_for_const_36,temp_var_for_const_37;temp_var_for_tac_18 = 0.0 - 7.0303097367e-02;

), /* 0xbd8ffb12 */
      (double temp_var_for_tac_19;double temp_var_for_const_38,temp_var_for_const_39;temp_var_for_tac_19 = 0.0 - 1.4507384300e+00;

), /* 0xbfb9b1cc */
      (double temp_var_for_tac_20;double temp_var_for_const_40,temp_var_for_const_41;temp_var_for_tac_20 = 0.0 - 7.6356959343e+00;

), /* 0xc0f4579f */
      (double temp_var_for_tac_21;double temp_var_for_const_42,temp_var_for_const_43;temp_var_for_tac_21 = 0.0 - 1.1193166733e+01;

), /* 0xc1331736 */
      (double temp_var_for_tac_22;double temp_var_for_const_44,temp_var_for_const_45;temp_var_for_tac_22 = 0.0 - 3.2336456776e+00;

)  /* 0xc04ef40d */
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
} else {
  if (ix >= IC(0x40917458)) {
    /* x >= 4.545452117919921875 */
    p = pR5;
    q = pS5;
  } else {
    if (ix >= IC(0x4036db68)) {
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

float temp_var_for_tac_23, temp_var_for_tac_24;
float temp_var_for_const_46;
temp_var_for_tac_23 = x * x;

temp_var_for_tac_24 = one / temp_var_for_tac_23;

z = temp_var_for_tac_24;
computeDSub((Addr)&temp_var_for_tac_0,
            {(Addr) &(temp_var_for_const_1 = 0.0),
             (Addr) &(temp_var_for_const_0 = 7.0312500000e-02)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:35:12");
computeDSub((Addr)&temp_var_for_tac_1,
            {(Addr) &(temp_var_for_const_3 = 0.0),
             (Addr) &(temp_var_for_const_2 = 8.0816707611e+00)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:36:12");
computeDSub((Addr)&temp_var_for_tac_2,
            {(Addr) &(temp_var_for_const_5 = 0.0),
             (Addr) &(temp_var_for_const_4 = 2.5706311035e+02)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:37:12");
computeDSub((Addr)&temp_var_for_tac_3,
            {(Addr) &(temp_var_for_const_7 = 0.0),
             (Addr) &(temp_var_for_const_6 = 2.4852163086e+03)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:38:12");
computeDSub((Addr)&temp_var_for_tac_4,
            {(Addr) &(temp_var_for_const_9 = 0.0),
             (Addr) &(temp_var_for_const_8 = 5.2530439453e+03)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:39:12");
computeDSub((Addr)&temp_var_for_tac_5,
            {(Addr) &(temp_var_for_const_11 = 0.0),
             (Addr) &(temp_var_for_const_10 = 1.1412546255e-11)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:52:12");
computeDSub((Addr)&temp_var_for_tac_6,
            {(Addr) &(temp_var_for_const_13 = 0.0),
             (Addr) &(temp_var_for_const_12 = 7.0312492549e-02)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:53:12");
computeDSub((Addr)&temp_var_for_tac_7,
            {(Addr) &(temp_var_for_const_15 = 0.0),
             (Addr) &(temp_var_for_const_14 = 4.1596107483e+00)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:54:12");
computeDSub((Addr)&temp_var_for_tac_8,
            {(Addr) &(temp_var_for_const_17 = 0.0),
             (Addr) &(temp_var_for_const_16 = 6.7674766541e+01)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:55:12");
computeDSub((Addr)&temp_var_for_tac_9,
            {(Addr) &(temp_var_for_const_19 = 0.0),
             (Addr) &(temp_var_for_const_18 = 3.3123129272e+02)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:56:12");
computeDSub((Addr)&temp_var_for_tac_10,
            {(Addr) &(temp_var_for_const_21 = 0.0),
             (Addr) &(temp_var_for_const_20 = 3.4643338013e+02)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:57:12");
computeDSub((Addr)&temp_var_for_tac_11,
            {(Addr) &(temp_var_for_const_23 = 0.0),
             (Addr) &(temp_var_for_const_22 = 2.5470459075e-09)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:70:12");
computeDSub((Addr)&temp_var_for_tac_12,
            {(Addr) &(temp_var_for_const_25 = 0.0),
             (Addr) &(temp_var_for_const_24 = 7.0311963558e-02)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:71:12");
computeDSub((Addr)&temp_var_for_tac_13,
            {(Addr) &(temp_var_for_const_27 = 0.0),
             (Addr) &(temp_var_for_const_26 = 2.4090321064e+00)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:72:12");
computeDSub((Addr)&temp_var_for_tac_14,
            {(Addr) &(temp_var_for_const_29 = 0.0),
             (Addr) &(temp_var_for_const_28 = 2.1965976715e+01)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:73:12");
computeDSub((Addr)&temp_var_for_tac_15,
            {(Addr) &(temp_var_for_const_31 = 0.0),
             (Addr) &(temp_var_for_const_30 = 5.8079170227e+01)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:74:12");
computeDSub((Addr)&temp_var_for_tac_16,
            {(Addr) &(temp_var_for_const_33 = 0.0),
             (Addr) &(temp_var_for_const_32 = 3.1447946548e+01)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:75:12");
computeDSub((Addr)&temp_var_for_tac_17,
            {(Addr) &(temp_var_for_const_35 = 0.0),
             (Addr) &(temp_var_for_const_34 = 8.8753431271e-08)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:88:12");
computeDSub((Addr)&temp_var_for_tac_18,
            {(Addr) &(temp_var_for_const_37 = 0.0),
             (Addr) &(temp_var_for_const_36 = 7.0303097367e-02)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:89:12");
computeDSub((Addr)&temp_var_for_tac_19,
            {(Addr) &(temp_var_for_const_39 = 0.0),
             (Addr) &(temp_var_for_const_38 = 1.4507384300e+00)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:90:12");
computeDSub((Addr)&temp_var_for_tac_20,
            {(Addr) &(temp_var_for_const_41 = 0.0),
             (Addr) &(temp_var_for_const_40 = 7.6356959343e+00)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:91:12");
computeDSub((Addr)&temp_var_for_tac_21,
            {(Addr) &(temp_var_for_const_43 = 0.0),
             (Addr) &(temp_var_for_const_42 = 1.1193166733e+01)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:92:12");
computeDSub((Addr)&temp_var_for_tac_22,
            {(Addr) &(temp_var_for_const_45 = 0.0),
             (Addr) &(temp_var_for_const_44 = 3.2336456776e+00)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:93:12");
computeFMul((Addr)&temp_var_for_tac_23, {(Addr)&x, (Addr)&x},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:129:16");
computeFDiv((Addr)&temp_var_for_tac_24,
            {(Addr) &(temp_var_for_const_46 = one), (Addr)&temp_var_for_tac_23},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:129:11");
AssignF({(Addr)&z}, (Addr)&temp_var_for_tac_24,
        "/home/shijia/Public/testprogram/s_pzerof.c_e.c:129:5");
;
float temp_var_for_tac_25, temp_var_for_tac_26, temp_var_for_tac_27,
    temp_var_for_tac_28, temp_var_for_tac_29, temp_var_for_tac_30,
    temp_var_for_tac_31, temp_var_for_tac_32, temp_var_for_tac_33,
    temp_var_for_tac_34;
float temp_var_for_const_47, temp_var_for_const_48, temp_var_for_const_49,
    temp_var_for_const_50, temp_var_for_const_51, temp_var_for_const_52;
temp_var_for_tac_25 = z * p[5];

temp_var_for_tac_26 = p[4] + temp_var_for_tac_25;

temp_var_for_tac_27 = z * temp_var_for_tac_26;

temp_var_for_tac_28 = p[3] + temp_var_for_tac_27;

temp_var_for_tac_29 = z * temp_var_for_tac_28;

temp_var_for_tac_30 = p[2] + temp_var_for_tac_29;

temp_var_for_tac_31 = z * temp_var_for_tac_30;

temp_var_for_tac_32 = p[1] + temp_var_for_tac_31;

temp_var_for_tac_33 = z * temp_var_for_tac_32;

temp_var_for_tac_34 = p[0] + temp_var_for_tac_33;

r = temp_var_for_tac_34;
computeFMul((Addr)&temp_var_for_tac_25,
            {(Addr)&z, (Addr) &(temp_var_for_const_47 = p[5])},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:130:64");
computeFAdd((Addr)&temp_var_for_tac_26, {(Addr) &(temp_var_for_const_48 = p[4]),
                                         (Addr)&temp_var_for_tac_25},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:130:60");
computeFMul((Addr)&temp_var_for_tac_27, {(Addr)&z, (Addr)&temp_var_for_tac_26},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:130:52");
computeFAdd((Addr)&temp_var_for_tac_28, {(Addr) &(temp_var_for_const_49 = p[3]),
                                         (Addr)&temp_var_for_tac_27},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:130:48");
computeFMul((Addr)&temp_var_for_tac_29, {(Addr)&z, (Addr)&temp_var_for_tac_28},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:130:40");
computeFAdd((Addr)&temp_var_for_tac_30, {(Addr) &(temp_var_for_const_50 = p[2]),
                                         (Addr)&temp_var_for_tac_29},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:130:36");
computeFMul((Addr)&temp_var_for_tac_31, {(Addr)&z, (Addr)&temp_var_for_tac_30},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:130:28");
computeFAdd((Addr)&temp_var_for_tac_32, {(Addr) &(temp_var_for_const_51 = p[1]),
                                         (Addr)&temp_var_for_tac_31},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:130:24");
computeFMul((Addr)&temp_var_for_tac_33, {(Addr)&z, (Addr)&temp_var_for_tac_32},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:130:16");
computeFAdd((Addr)&temp_var_for_tac_34, {(Addr) &(temp_var_for_const_52 = p[0]),
                                         (Addr)&temp_var_for_tac_33},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:130:12");
AssignF({(Addr)&r}, (Addr)&temp_var_for_tac_34,
        "/home/shijia/Public/testprogram/s_pzerof.c_e.c:130:5");
;
float temp_var_for_tac_35, temp_var_for_tac_36, temp_var_for_tac_37,
    temp_var_for_tac_38, temp_var_for_tac_39, temp_var_for_tac_40,
    temp_var_for_tac_41, temp_var_for_tac_42, temp_var_for_tac_43,
    temp_var_for_tac_44;
float temp_var_for_const_53, temp_var_for_const_54, temp_var_for_const_55,
    temp_var_for_const_56, temp_var_for_const_57, temp_var_for_const_58;
temp_var_for_tac_35 = z * q[4];

temp_var_for_tac_36 = q[3] + temp_var_for_tac_35;

temp_var_for_tac_37 = z * temp_var_for_tac_36;

temp_var_for_tac_38 = q[2] + temp_var_for_tac_37;

temp_var_for_tac_39 = z * temp_var_for_tac_38;

temp_var_for_tac_40 = q[1] + temp_var_for_tac_39;

temp_var_for_tac_41 = z * temp_var_for_tac_40;

temp_var_for_tac_42 = q[0] + temp_var_for_tac_41;

temp_var_for_tac_43 = z * temp_var_for_tac_42;

temp_var_for_tac_44 = one + temp_var_for_tac_43;

s = temp_var_for_tac_44;
computeFMul((Addr)&temp_var_for_tac_35,
            {(Addr)&z, (Addr) &(temp_var_for_const_53 = q[4])},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:131:63");
computeFAdd((Addr)&temp_var_for_tac_36, {(Addr) &(temp_var_for_const_54 = q[3]),
                                         (Addr)&temp_var_for_tac_35},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:131:59");
computeFMul((Addr)&temp_var_for_tac_37, {(Addr)&z, (Addr)&temp_var_for_tac_36},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:131:51");
computeFAdd((Addr)&temp_var_for_tac_38, {(Addr) &(temp_var_for_const_55 = q[2]),
                                         (Addr)&temp_var_for_tac_37},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:131:47");
computeFMul((Addr)&temp_var_for_tac_39, {(Addr)&z, (Addr)&temp_var_for_tac_38},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:131:39");
computeFAdd((Addr)&temp_var_for_tac_40, {(Addr) &(temp_var_for_const_56 = q[1]),
                                         (Addr)&temp_var_for_tac_39},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:131:35");
computeFMul((Addr)&temp_var_for_tac_41, {(Addr)&z, (Addr)&temp_var_for_tac_40},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:131:27");
computeFAdd((Addr)&temp_var_for_tac_42, {(Addr) &(temp_var_for_const_57 = q[0]),
                                         (Addr)&temp_var_for_tac_41},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:131:23");
computeFMul((Addr)&temp_var_for_tac_43, {(Addr)&z, (Addr)&temp_var_for_tac_42},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:131:15");
computeFAdd((Addr)&temp_var_for_tac_44,
            {(Addr) &(temp_var_for_const_58 = one), (Addr)&temp_var_for_tac_43},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:131:11");
AssignF({(Addr)&s}, (Addr)&temp_var_for_tac_44,
        "/home/shijia/Public/testprogram/s_pzerof.c_e.c:131:5");
;
float temp_var_for_ext_0;
float temp_var_for_tac_45, temp_var_for_tac_46;
float temp_var_for_const_59;
temp_var_for_tac_45 = r / s;

temp_var_for_tac_46 = one + temp_var_for_tac_45;

temp_var_for_ext_0 = temp_var_for_tac_46;
computeFDiv((Addr)&temp_var_for_tac_45, {(Addr)&r, (Addr)&s},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:133:32");
computeFAdd((Addr)&temp_var_for_tac_46,
            {(Addr) &(temp_var_for_const_59 = one), (Addr)&temp_var_for_tac_45},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:133:28");
AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_46,
        "/home/shijia/Public/testprogram/s_pzerof.c_e.c:133:22");
;
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
      1.6377603149e+02,        /* 0x4323c6aa */
      8.0983447266e+03,        /* 0x45fd12c2 */
      1.4253829688e+05,        /* 0x480b3293 */
      8.0330925000e+05,        /* 0x49441ed4 */
      8.4050156250e+05,        /* 0x494d3359 */
      (double temp_var_for_tac_47;
  double temp_var_for_const_60, temp_var_for_const_61;
  temp_var_for_tac_47 = 0.0 - 3.4389928125e+05;

) /* 0xc8a7eb69 */
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
      8.2776611328e+01,        /* 0x42a58da0 */
      2.0778142090e+03,        /* 0x4501dd07 */
      1.8847289062e+04,        /* 0x46933e94 */
      5.6751113281e+04,        /* 0x475daf1d */
      3.5976753906e+04,        /* 0x470c88c1 */
      (double temp_var_for_tac_48;
  double temp_var_for_const_62, temp_var_for_const_63;
  temp_var_for_tac_48 = 0.0 - 5.3543427734e+03;

) /* 0xc5a752be */
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
      4.8758872986e+01,        /* 0x42430916 */
      7.0968920898e+02,        /* 0x44316c1c */
      3.7041481934e+03,        /* 0x4567825f */
      6.4604252930e+03,        /* 0x45c9e367 */
      2.5163337402e+03,        /* 0x451d4557 */
      (double temp_var_for_tac_49;
  double temp_var_for_const_64, temp_var_for_const_65;
  temp_var_for_tac_49 = 0.0 - 1.4924745178e+02;

) /* 0xc3153f59 */
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
      3.0365585327e+01,        /* 0x41f2ecb8 */
      2.6934811401e+02,        /* 0x4386ac8f */
      8.4478375244e+02,        /* 0x44533229 */
      8.8293585205e+02,        /* 0x445cbbe5 */
      2.1266638184e+02,        /* 0x4354aa98 */
      (double temp_var_for_tac_50;
  double temp_var_for_const_66, temp_var_for_const_67;
  temp_var_for_tac_50 = 0.0 - 5.3109550476e+00;

) /* 0xc0a9f358 */
}
;

GET_FLOAT_WORD(ix, x);
ix &= IC(0x7fffffff);
if (ix >= IC(0x41000000)) {
  /* x >= 2**16 */
  p = qR8;
  q = qS8;
} else {
  if (ix >= IC(0x40917458)) {
    /* x >= 4.545452117919921875 */
    /* x >= 4.54541015625 */
    p = qR5;
    q = qS5;
  } else {
    if (ix >= IC(0x4036db68)) {
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

float temp_var_for_ext_1;
float temp_var_for_tac_51, temp_var_for_tac_52;
float temp_var_for_const_68;
temp_var_for_tac_51 = x * x;

temp_var_for_tac_52 = one / temp_var_for_tac_51;

temp_var_for_ext_1 = temp_var_for_tac_52;
computeDSub((Addr)&temp_var_for_tac_47,
            {(Addr) &(temp_var_for_const_61 = 0.0),
             (Addr) &(temp_var_for_const_60 = 3.4389928125e+05)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:171:12");
computeDSub((Addr)&temp_var_for_tac_48,
            {(Addr) &(temp_var_for_const_63 = 0.0),
             (Addr) &(temp_var_for_const_62 = 5.3543427734e+03)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:190:12");
computeDSub((Addr)&temp_var_for_tac_49,
            {(Addr) &(temp_var_for_const_65 = 0.0),
             (Addr) &(temp_var_for_const_64 = 1.4924745178e+02)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:209:12");
computeDSub((Addr)&temp_var_for_tac_50,
            {(Addr) &(temp_var_for_const_67 = 0.0),
             (Addr) &(temp_var_for_const_66 = 5.3109550476e+00)},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:228:12");
computeFMul((Addr)&temp_var_for_tac_51, {(Addr)&x, (Addr)&x},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:258:33");
computeFDiv((Addr)&temp_var_for_tac_52,
            {(Addr) &(temp_var_for_const_68 = one), (Addr)&temp_var_for_tac_51},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:258:28");
AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_52,
        "/home/shijia/Public/testprogram/s_pzerof.c_e.c:258:22");
; // z
/*(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(2)(q[2])(z)(q)(1)(q[1])(z)(q)(0)(q[0])(z)(one)(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(2)(q[2])(z)(q)(1)(q[1])(z)(q)(0)(q[0])(z)(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(2)(q[2])(z)(q)(1)(q[1])(z)(q)(0)(q[0])(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(2)(q[2])(z)(q)(1)(q[1])(z)(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(2)(q[2])(z)(q)(1)(q[1])(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(2)(q[2])(z)(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(2)(q[2])(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(4)(q[4])(z)(q)(3)(q[3])(q)(4)(q[4])(z)(0)(e)(tem)(0)(e)(x)(x)(one)*/
z = temp_var_for_ext_1;
AssignF({(Addr)&z}, (Addr)&temp_var_for_ext_1,
        "/home/shijia/Public/testprogram/s_pzerof.c_e.c:260:5");
;
float temp_var_for_tac_53, temp_var_for_tac_54, temp_var_for_tac_55,
    temp_var_for_tac_56, temp_var_for_tac_57, temp_var_for_tac_58,
    temp_var_for_tac_59, temp_var_for_tac_60, temp_var_for_tac_61,
    temp_var_for_tac_62;
float temp_var_for_const_69, temp_var_for_const_70, temp_var_for_const_71,
    temp_var_for_const_72, temp_var_for_const_73, temp_var_for_const_74;
temp_var_for_tac_53 = z * p[5];

temp_var_for_tac_54 = p[4] + temp_var_for_tac_53;

temp_var_for_tac_55 = z * temp_var_for_tac_54;

temp_var_for_tac_56 = p[3] + temp_var_for_tac_55;

temp_var_for_tac_57 = z * temp_var_for_tac_56;

temp_var_for_tac_58 = p[2] + temp_var_for_tac_57;

temp_var_for_tac_59 = z * temp_var_for_tac_58;

temp_var_for_tac_60 = p[1] + temp_var_for_tac_59;

temp_var_for_tac_61 = z * temp_var_for_tac_60;

temp_var_for_tac_62 = p[0] + temp_var_for_tac_61;

r = temp_var_for_tac_62;
computeFMul((Addr)&temp_var_for_tac_53,
            {(Addr)&z, (Addr) &(temp_var_for_const_69 = p[5])},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:261:64");
computeFAdd((Addr)&temp_var_for_tac_54, {(Addr) &(temp_var_for_const_70 = p[4]),
                                         (Addr)&temp_var_for_tac_53},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:261:60");
computeFMul((Addr)&temp_var_for_tac_55, {(Addr)&z, (Addr)&temp_var_for_tac_54},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:261:52");
computeFAdd((Addr)&temp_var_for_tac_56, {(Addr) &(temp_var_for_const_71 = p[3]),
                                         (Addr)&temp_var_for_tac_55},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:261:48");
computeFMul((Addr)&temp_var_for_tac_57, {(Addr)&z, (Addr)&temp_var_for_tac_56},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:261:40");
computeFAdd((Addr)&temp_var_for_tac_58, {(Addr) &(temp_var_for_const_72 = p[2]),
                                         (Addr)&temp_var_for_tac_57},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:261:36");
computeFMul((Addr)&temp_var_for_tac_59, {(Addr)&z, (Addr)&temp_var_for_tac_58},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:261:28");
computeFAdd((Addr)&temp_var_for_tac_60, {(Addr) &(temp_var_for_const_73 = p[1]),
                                         (Addr)&temp_var_for_tac_59},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:261:24");
computeFMul((Addr)&temp_var_for_tac_61, {(Addr)&z, (Addr)&temp_var_for_tac_60},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:261:16");
computeFAdd((Addr)&temp_var_for_tac_62, {(Addr) &(temp_var_for_const_74 = p[0]),
                                         (Addr)&temp_var_for_tac_61},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:261:12");
AssignF({(Addr)&r}, (Addr)&temp_var_for_tac_62,
        "/home/shijia/Public/testprogram/s_pzerof.c_e.c:261:5");
;
float temp_var_for_tac_63, temp_var_for_tac_64, temp_var_for_tac_65,
    temp_var_for_tac_66, temp_var_for_tac_67, temp_var_for_tac_68,
    temp_var_for_tac_69, temp_var_for_tac_70, temp_var_for_tac_71,
    temp_var_for_tac_72, temp_var_for_tac_73, temp_var_for_tac_74;
float temp_var_for_const_75, temp_var_for_const_76, temp_var_for_const_77,
    temp_var_for_const_78, temp_var_for_const_79, temp_var_for_const_80,
    temp_var_for_const_81;
temp_var_for_tac_63 = z * q[5];

temp_var_for_tac_64 = q[4] + temp_var_for_tac_63;

temp_var_for_tac_65 = z * temp_var_for_tac_64;

temp_var_for_tac_66 = q[3] + temp_var_for_tac_65;

temp_var_for_tac_67 = z * temp_var_for_tac_66;

temp_var_for_tac_68 = q[2] + temp_var_for_tac_67;

temp_var_for_tac_69 = z * temp_var_for_tac_68;

temp_var_for_tac_70 = q[1] + temp_var_for_tac_69;

temp_var_for_tac_71 = z * temp_var_for_tac_70;

temp_var_for_tac_72 = q[0] + temp_var_for_tac_71;

temp_var_for_tac_73 = z * temp_var_for_tac_72;

temp_var_for_tac_74 = one + temp_var_for_tac_73;

s = temp_var_for_tac_74;
computeFMul((Addr)&temp_var_for_tac_63,
            {(Addr)&z, (Addr) &(temp_var_for_const_75 = q[5])},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:263:69");
computeFAdd((Addr)&temp_var_for_tac_64, {(Addr) &(temp_var_for_const_76 = q[4]),
                                         (Addr)&temp_var_for_tac_63},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:263:65");
computeFMul((Addr)&temp_var_for_tac_65, {(Addr)&z, (Addr)&temp_var_for_tac_64},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:263:57");
computeFAdd((Addr)&temp_var_for_tac_66, {(Addr) &(temp_var_for_const_77 = q[3]),
                                         (Addr)&temp_var_for_tac_65},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:263:53");
computeFMul((Addr)&temp_var_for_tac_67, {(Addr)&z, (Addr)&temp_var_for_tac_66},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:263:45");
computeFAdd((Addr)&temp_var_for_tac_68, {(Addr) &(temp_var_for_const_78 = q[2]),
                                         (Addr)&temp_var_for_tac_67},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:263:41");
computeFMul((Addr)&temp_var_for_tac_69, {(Addr)&z, (Addr)&temp_var_for_tac_68},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:263:33");
computeFAdd((Addr)&temp_var_for_tac_70, {(Addr) &(temp_var_for_const_79 = q[1]),
                                         (Addr)&temp_var_for_tac_69},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:263:29");
computeFMul((Addr)&temp_var_for_tac_71, {(Addr)&z, (Addr)&temp_var_for_tac_70},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:263:21");
computeFAdd((Addr)&temp_var_for_tac_72, {(Addr) &(temp_var_for_const_80 = q[0]),
                                         (Addr)&temp_var_for_tac_71},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:263:17");
computeFMul((Addr)&temp_var_for_tac_73, {(Addr)&z, (Addr)&temp_var_for_tac_72},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:263:9");
computeFAdd((Addr)&temp_var_for_tac_74,
            {(Addr) &(temp_var_for_const_81 = one), (Addr)&temp_var_for_tac_73},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:262:11");
AssignF({(Addr)&s}, (Addr)&temp_var_for_tac_74,
        "/home/shijia/Public/testprogram/s_pzerof.c_e.c:262:5");
;
float temp_var_for_ext_2;
float temp_var_for_tac_75, temp_var_for_tac_76, temp_var_for_tac_77;
float temp_var_for_const_82;
temp_var_for_tac_75 = r / s;

temp_var_for_tac_76 = (-(.125f)) + temp_var_for_tac_75;

temp_var_for_tac_77 = temp_var_for_tac_76 / x;

temp_var_for_ext_2 = temp_var_for_tac_77;
computeFDiv((Addr)&temp_var_for_tac_75, {(Addr)&r, (Addr)&s},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:265:36");
computeFAdd((Addr)&temp_var_for_tac_76,
            {(Addr) &(temp_var_for_const_82 = (-(.125f))),
             (Addr)&temp_var_for_tac_75},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:265:32");
computeFDiv((Addr)&temp_var_for_tac_77, {(Addr)&temp_var_for_tac_76, (Addr)&x},
            "/home/shijia/Public/testprogram/s_pzerof.c_e.c:265:41");
AssignF({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_77,
        "/home/shijia/Public/testprogram/s_pzerof.c_e.c:265:22");
;
callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
callExp++; /*identify the function is  add move tmpShadow*/
return (0.0 - temp_)var_for_ext_2;
}
