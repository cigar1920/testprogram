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
  } else {
    if (ix >= IC(0x40f71c58)) {
      p = pr5;
      q = ps5;
    } else {
      if (ix >= IC(0x4036db68)) {
        p = pr3;
        q = ps3;
      } else /* if (ix >= IC(0x40000000)) */
      {
        p = pr2;
        q = ps2;
      }
    }
  }

  float temp_var_for_tac_0, temp_var_for_tac_1;
  float temp_var_for_const_0;
  temp_var_for_tac_0 = x * x;

  temp_var_for_tac_1 = one / temp_var_for_tac_0;

  z = temp_var_for_tac_1;
  computeFMul((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&x},
              "/home/shijia/Public/testprogram/s_ponef.c_e.c:124:16");
  computeFDiv((Addr)&temp_var_for_tac_1,
              {(Addr) &(temp_var_for_const_0 = one), (Addr)&temp_var_for_tac_0},
              "/home/shijia/Public/testprogram/s_ponef.c_e.c:124:11");
  AssignF({(Addr)&z}, (Addr)&temp_var_for_tac_1,
          "/home/shijia/Public/testprogram/s_ponef.c_e.c:124:5");
  ;
  float temp_var_for_tac_2, temp_var_for_tac_3, temp_var_for_tac_4,
      temp_var_for_tac_5, temp_var_for_tac_6, temp_var_for_tac_7,
      temp_var_for_tac_8, temp_var_for_tac_9, temp_var_for_tac_10,
      temp_var_for_tac_11;
  float temp_var_for_const_1, temp_var_for_const_2, temp_var_for_const_3,
      temp_var_for_const_4, temp_var_for_const_5, temp_var_for_const_6;
  temp_var_for_tac_2 = z * p[5];

  temp_var_for_tac_3 = p[4] + temp_var_for_tac_2;

  temp_var_for_tac_4 = z * temp_var_for_tac_3;

  temp_var_for_tac_5 = p[3] + temp_var_for_tac_4;

  temp_var_for_tac_6 = z * temp_var_for_tac_5;

  temp_var_for_tac_7 = p[2] + temp_var_for_tac_6;

  temp_var_for_tac_8 = z * temp_var_for_tac_7;

  temp_var_for_tac_9 = p[1] + temp_var_for_tac_8;

  temp_var_for_tac_10 = z * temp_var_for_tac_9;

  temp_var_for_tac_11 = p[0] + temp_var_for_tac_10;

  r = temp_var_for_tac_11;
  computeFMul((Addr)&temp_var_for_tac_2,
              {(Addr)&z, (Addr) &(temp_var_for_const_1 = p[5])},
              "/home/shijia/Public/testprogram/s_ponef.c_e.c:125:64");
  computeFAdd((Addr)&temp_var_for_tac_3, {(Addr) &(temp_var_for_const_2 = p[4]),
                                          (Addr)&temp_var_for_tac_2},
              "/home/shijia/Public/testprogram/s_ponef.c_e.c:125:60");
  computeFMul((Addr)&temp_var_for_tac_4, {(Addr)&z, (Addr)&temp_var_for_tac_3},
              "/home/shijia/Public/testprogram/s_ponef.c_e.c:125:52");
  computeFAdd((Addr)&temp_var_for_tac_5, {(Addr) &(temp_var_for_const_3 = p[3]),
                                          (Addr)&temp_var_for_tac_4},
              "/home/shijia/Public/testprogram/s_ponef.c_e.c:125:48");
  computeFMul((Addr)&temp_var_for_tac_6, {(Addr)&z, (Addr)&temp_var_for_tac_5},
              "/home/shijia/Public/testprogram/s_ponef.c_e.c:125:40");
  computeFAdd((Addr)&temp_var_for_tac_7, {(Addr) &(temp_var_for_const_4 = p[2]),
                                          (Addr)&temp_var_for_tac_6},
              "/home/shijia/Public/testprogram/s_ponef.c_e.c:125:36");
  computeFMul((Addr)&temp_var_for_tac_8, {(Addr)&z, (Addr)&temp_var_for_tac_7},
              "/home/shijia/Public/testprogram/s_ponef.c_e.c:125:28");
  computeFAdd((Addr)&temp_var_for_tac_9, {(Addr) &(temp_var_for_const_5 = p[1]),
                                          (Addr)&temp_var_for_tac_8},
              "/home/shijia/Public/testprogram/s_ponef.c_e.c:125:24");
  computeFMul((Addr)&temp_var_for_tac_10, {(Addr)&z, (Addr)&temp_var_for_tac_9},
              "/home/shijia/Public/testprogram/s_ponef.c_e.c:125:16");
  computeFAdd(
      (Addr)&temp_var_for_tac_11,
      {(Addr) &(temp_var_for_const_6 = p[0]), (Addr)&temp_var_for_tac_10},
      "/home/shijia/Public/testprogram/s_ponef.c_e.c:125:12");
  AssignF({(Addr)&r}, (Addr)&temp_var_for_tac_11,
          "/home/shijia/Public/testprogram/s_ponef.c_e.c:125:5");
  ;
  float temp_var_for_tac_12, temp_var_for_tac_13, temp_var_for_tac_14,
      temp_var_for_tac_15, temp_var_for_tac_16, temp_var_for_tac_17,
      temp_var_for_tac_18, temp_var_for_tac_19, temp_var_for_tac_20,
      temp_var_for_tac_21;
  float temp_var_for_const_7, temp_var_for_const_8, temp_var_for_const_9,
      temp_var_for_const_10, temp_var_for_const_11, temp_var_for_const_12;
  temp_var_for_tac_12 = z * q[4];

  temp_var_for_tac_13 = q[3] + temp_var_for_tac_12;

  temp_var_for_tac_14 = z * temp_var_for_tac_13;

  temp_var_for_tac_15 = q[2] + temp_var_for_tac_14;

  temp_var_for_tac_16 = z * temp_var_for_tac_15;

  temp_var_for_tac_17 = q[1] + temp_var_for_tac_16;

  temp_var_for_tac_18 = z * temp_var_for_tac_17;

  temp_var_for_tac_19 = q[0] + temp_var_for_tac_18;

  temp_var_for_tac_20 = z * temp_var_for_tac_19;

  temp_var_for_tac_21 = one + temp_var_for_tac_20;

  s = temp_var_for_tac_21;
  computeFMul((Addr)&temp_var_for_tac_12,
              {(Addr)&z, (Addr) &(temp_var_for_const_7 = q[4])},
              "/home/shijia/Public/testprogram/s_ponef.c_e.c:126:63");
  computeFAdd(
      (Addr)&temp_var_for_tac_13,
      {(Addr) &(temp_var_for_const_8 = q[3]), (Addr)&temp_var_for_tac_12},
      "/home/shijia/Public/testprogram/s_ponef.c_e.c:126:59");
  computeFMul((Addr)&temp_var_for_tac_14,
              {(Addr)&z, (Addr)&temp_var_for_tac_13},
              "/home/shijia/Public/testprogram/s_ponef.c_e.c:126:51");
  computeFAdd(
      (Addr)&temp_var_for_tac_15,
      {(Addr) &(temp_var_for_const_9 = q[2]), (Addr)&temp_var_for_tac_14},
      "/home/shijia/Public/testprogram/s_ponef.c_e.c:126:47");
  computeFMul((Addr)&temp_var_for_tac_16,
              {(Addr)&z, (Addr)&temp_var_for_tac_15},
              "/home/shijia/Public/testprogram/s_ponef.c_e.c:126:39");
  computeFAdd(
      (Addr)&temp_var_for_tac_17,
      {(Addr) &(temp_var_for_const_10 = q[1]), (Addr)&temp_var_for_tac_16},
      "/home/shijia/Public/testprogram/s_ponef.c_e.c:126:35");
  computeFMul((Addr)&temp_var_for_tac_18,
              {(Addr)&z, (Addr)&temp_var_for_tac_17},
              "/home/shijia/Public/testprogram/s_ponef.c_e.c:126:27");
  computeFAdd(
      (Addr)&temp_var_for_tac_19,
      {(Addr) &(temp_var_for_const_11 = q[0]), (Addr)&temp_var_for_tac_18},
      "/home/shijia/Public/testprogram/s_ponef.c_e.c:126:23");
  computeFMul((Addr)&temp_var_for_tac_20,
              {(Addr)&z, (Addr)&temp_var_for_tac_19},
              "/home/shijia/Public/testprogram/s_ponef.c_e.c:126:15");
  computeFAdd(
      (Addr)&temp_var_for_tac_21,
      {(Addr) &(temp_var_for_const_12 = one), (Addr)&temp_var_for_tac_20},
      "/home/shijia/Public/testprogram/s_ponef.c_e.c:126:11");
  AssignF({(Addr)&s}, (Addr)&temp_var_for_tac_21,
          "/home/shijia/Public/testprogram/s_ponef.c_e.c:126:5");
  ;
  float temp_var_for_ext_0;
  float temp_var_for_tac_22, temp_var_for_tac_23;
  float temp_var_for_const_13;
  temp_var_for_tac_22 = r / s;

  temp_var_for_tac_23 = one + temp_var_for_tac_22;

  temp_var_for_ext_0 = temp_var_for_tac_23;
  computeFDiv((Addr)&temp_var_for_tac_22, {(Addr)&r, (Addr)&s},
              "/home/shijia/Public/testprogram/s_ponef.c_e.c:128:32");
  computeFAdd(
      (Addr)&temp_var_for_tac_23,
      {(Addr) &(temp_var_for_const_13 = one), (Addr)&temp_var_for_tac_22},
      "/home/shijia/Public/testprogram/s_ponef.c_e.c:128:28");
  AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_23,
          "/home/shijia/Public/testprogram/s_ponef.c_e.c:128:22");
  ;
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
      0.0000000000e+00,         /* 0x00000000 */
      (double temp_var_for_tac_24;
  double temp_var_for_const_14, temp_var_for_const_15;
  temp_var_for_tac_24 = 0.0 - 1.0253906250e-01;

), /* 0xbdd20000 */
      (double temp_var_for_tac_25;double temp_var_for_const_16,temp_var_for_const_17;temp_var_for_tac_25 = 0.0 - 1.6271753311e+01;

), /* 0xc1822c8d */
      (double temp_var_for_tac_26;double temp_var_for_const_18,temp_var_for_const_19;temp_var_for_tac_26 = 0.0 - 7.5960174561e+02;

), /* 0xc43de683 */
      (double temp_var_for_tac_27;double temp_var_for_const_20,temp_var_for_const_21;temp_var_for_tac_27 = 0.0 - 1.1849806641e+04;

), /* 0xc639273a */
      (double temp_var_for_tac_28;double temp_var_for_const_22,temp_var_for_const_23;temp_var_for_tac_28 = 0.0 - 4.8438511719e+04;

)  /* 0xc73d3683 */
};

  static const float qs8[6] = {
      1.6139537048e+02,        /* 0x43216537 */
      7.8253862305e+03,        /* 0x45f48b17 */
      1.3387534375e+05,        /* 0x4802bcd6 */
      7.1965775000e+05,        /* 0x492fb29c */
      6.6660125000e+05,        /* 0x4922be94 */
      (double temp_var_for_tac_29;
  double temp_var_for_const_24, temp_var_for_const_25;
  temp_var_for_tac_29 = 0.0 - 2.9449025000e+05;

) /* 0xc88fcb48 */
}
;

  static const float qr5[6] = {
      /* for x in [8,4.5454]=1/[0.125,0.22001] */
      (double temp_var_for_tac_30;
  double temp_var_for_const_26, temp_var_for_const_27;
  temp_var_for_tac_30 = 0.0 - 2.0897993405e-11;

), /* 0xadb7d219 */
      (double temp_var_for_tac_31;double temp_var_for_const_28,temp_var_for_const_29;temp_var_for_tac_31 = 0.0 - 1.0253904760e-01;

), /* 0xbdd1fffe */
      (double temp_var_for_tac_32;double temp_var_for_const_30,temp_var_for_const_31;temp_var_for_tac_32 = 0.0 - 8.0564479828e+00;

), /* 0xc100e736 */
      (double temp_var_for_tac_33;double temp_var_for_const_32,temp_var_for_const_33;temp_var_for_tac_33 = 0.0 - 1.8366960144e+02;

), /* 0xc337ab6b */
      (double temp_var_for_tac_34;double temp_var_for_const_34,temp_var_for_const_35;temp_var_for_tac_34 = 0.0 - 1.3731937256e+03;

), /* 0xc4aba633 */
      (double temp_var_for_tac_35;double temp_var_for_const_36,temp_var_for_const_37;temp_var_for_tac_35 = 0.0 - 2.6124443359e+03;

)  /* 0xc523471c */
}
;

  static const float qs5[6] = {
      8.1276550293e+01,        /* 0x42a28d98 */
      1.9917987061e+03,        /* 0x44f8f98f */
      1.7468484375e+04,        /* 0x468878f8 */
      4.9851425781e+04,        /* 0x4742bb6d */
      2.7948074219e+04,        /* 0x46da5826 */
      (double temp_var_for_tac_36;
  double temp_var_for_const_38, temp_var_for_const_39;
  temp_var_for_tac_36 = 0.0 - 4.7191835938e+03;

) /* 0xc5937978 */
}
;

  static const float qr3[6] = {
      (double temp_var_for_tac_37;
  double temp_var_for_const_40, temp_var_for_const_41;
  temp_var_for_tac_37 = 0.0 - 5.0783124372e-09;

), /* 0xb1ae7d4f */
      (double temp_var_for_tac_38;double temp_var_for_const_42,temp_var_for_const_43;temp_var_for_tac_38 = 0.0 - 1.0253783315e-01;

), /* 0xbdd1ff5b */
      (double temp_var_for_tac_39;double temp_var_for_const_44,temp_var_for_const_45;temp_var_for_tac_39 = 0.0 - 4.6101160049e+00;

), /* 0xc0938612 */
      (double temp_var_for_tac_40;double temp_var_for_const_46,temp_var_for_const_47;temp_var_for_tac_40 = 0.0 - 5.7847221375e+01;

), /* 0xc267638e */
      (double temp_var_for_tac_41;double temp_var_for_const_48,temp_var_for_const_49;temp_var_for_tac_41 = 0.0 - 2.2824453735e+02;

), /* 0xc3643e9a */
      (double temp_var_for_tac_42;double temp_var_for_const_50,temp_var_for_const_51;temp_var_for_tac_42 = 0.0 - 2.1921012878e+02;

)  /* 0xc35b35cb */
}
;

  static const float qs3[6] = {
      4.7665153503e+01,        /* 0x423ea91e */
      6.7386511230e+02,        /* 0x4428775e */
      3.3801528320e+03,        /* 0x45534272 */
      5.5477290039e+03,        /* 0x45ad5dd5 */
      1.9031191406e+03,        /* 0x44ede3d0 */
      (double temp_var_for_tac_43;
  double temp_var_for_const_52, temp_var_for_const_53;
  temp_var_for_tac_43 = 0.0 - 1.3520118713e+02;

) /* 0xc3073381 */
}
;

  static const float qr2[6] = {
      /* for x in [2.8570,2]=1/[0.3499,0.5] */
      (double temp_var_for_tac_44;
  double temp_var_for_const_54, temp_var_for_const_55;
  temp_var_for_tac_44 = 0.0 - 1.7838172539e-07;

), /* 0xb43f8932 */
      (double temp_var_for_tac_45;double temp_var_for_const_56,temp_var_for_const_57;temp_var_for_tac_45 = 0.0 - 1.0251704603e-01;

), /* 0xbdd1f475 */
      (double temp_var_for_tac_46;double temp_var_for_const_58,temp_var_for_const_59;temp_var_for_tac_46 = 0.0 - 2.7522056103e+00;

), /* 0xc0302423 */
      (double temp_var_for_tac_47;double temp_var_for_const_60,temp_var_for_const_61;temp_var_for_tac_47 = 0.0 - 1.9663616180e+01;

), /* 0xc19d4f16 */
      (double temp_var_for_tac_48;double temp_var_for_const_62,temp_var_for_const_63;temp_var_for_tac_48 = 0.0 - 4.2325313568e+01;

), /* 0xc2294d1f */
      (double temp_var_for_tac_49;double temp_var_for_const_64,temp_var_for_const_65;temp_var_for_tac_49 = 0.0 - 2.1371921539e+01;

)  /* 0xc1aaf9b2 */
}
;

  static const float qs2[6] = {
      2.9533363342e+01,        /* 0x41ec4454 */
      2.5298155212e+02,        /* 0x437cfb47 */
      7.5750280762e+02,        /* 0x443d602e */
      7.3939318848e+02,        /* 0x4438d92a */
      1.5594900513e+02,        /* 0x431bf2f2 */
      (double temp_var_for_tac_50;
  double temp_var_for_const_66, temp_var_for_const_67;
  temp_var_for_tac_50 = 0.0 - 4.9594988823e+00;

) /* 0xc09eb437 */
}
;

GET_FLOAT_WORD(ix, x);
ix &= IC(0x7fffffff);
if (ix >= IC(0x40200000)) {
  p = qr8;
  q = qs8;
} else {
  if (ix >= IC(0x40f71c58)) {
    p = qr5;
    q = qs5;
  } else {
    if (ix >= IC(0x4036db68)) {
      p = qr3;
      q = qs3;
    } else /* if (ix >= IC(0x40000000)) */
    {
      p = qr2;
      q = qs2;
    }
  }
}

float temp_var_for_ext_1;
float temp_var_for_tac_51, temp_var_for_tac_52;
float temp_var_for_const_68;
temp_var_for_tac_51 = x * x;

temp_var_for_tac_52 = one / temp_var_for_tac_51;

temp_var_for_ext_1 = temp_var_for_tac_52;
computeDSub((Addr)&temp_var_for_tac_24,
            {(Addr) &(temp_var_for_const_15 = 0.0),
             (Addr) &(temp_var_for_const_14 = 1.0253906250e-01)},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:154:12");
computeDSub((Addr)&temp_var_for_tac_25,
            {(Addr) &(temp_var_for_const_17 = 0.0),
             (Addr) &(temp_var_for_const_16 = 1.6271753311e+01)},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:155:12");
computeDSub((Addr)&temp_var_for_tac_26,
            {(Addr) &(temp_var_for_const_19 = 0.0),
             (Addr) &(temp_var_for_const_18 = 7.5960174561e+02)},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:156:12");
computeDSub((Addr)&temp_var_for_tac_27,
            {(Addr) &(temp_var_for_const_21 = 0.0),
             (Addr) &(temp_var_for_const_20 = 1.1849806641e+04)},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:157:12");
computeDSub((Addr)&temp_var_for_tac_28,
            {(Addr) &(temp_var_for_const_23 = 0.0),
             (Addr) &(temp_var_for_const_22 = 4.8438511719e+04)},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:158:12");
computeDSub((Addr)&temp_var_for_tac_29,
            {(Addr) &(temp_var_for_const_25 = 0.0),
             (Addr) &(temp_var_for_const_24 = 2.9449025000e+05)},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:167:12");
computeDSub((Addr)&temp_var_for_tac_30,
            {(Addr) &(temp_var_for_const_27 = 0.0),
             (Addr) &(temp_var_for_const_26 = 2.0897993405e-11)},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:172:12");
computeDSub((Addr)&temp_var_for_tac_31,
            {(Addr) &(temp_var_for_const_29 = 0.0),
             (Addr) &(temp_var_for_const_28 = 1.0253904760e-01)},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:173:12");
computeDSub((Addr)&temp_var_for_tac_32,
            {(Addr) &(temp_var_for_const_31 = 0.0),
             (Addr) &(temp_var_for_const_30 = 8.0564479828e+00)},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:174:12");
computeDSub((Addr)&temp_var_for_tac_33,
            {(Addr) &(temp_var_for_const_33 = 0.0),
             (Addr) &(temp_var_for_const_32 = 1.8366960144e+02)},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:175:12");
computeDSub((Addr)&temp_var_for_tac_34,
            {(Addr) &(temp_var_for_const_35 = 0.0),
             (Addr) &(temp_var_for_const_34 = 1.3731937256e+03)},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:176:12");
computeDSub((Addr)&temp_var_for_tac_35,
            {(Addr) &(temp_var_for_const_37 = 0.0),
             (Addr) &(temp_var_for_const_36 = 2.6124443359e+03)},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:177:12");
computeDSub((Addr)&temp_var_for_tac_36,
            {(Addr) &(temp_var_for_const_39 = 0.0),
             (Addr) &(temp_var_for_const_38 = 4.7191835938e+03)},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:186:12");
computeDSub((Addr)&temp_var_for_tac_37,
            {(Addr) &(temp_var_for_const_41 = 0.0),
             (Addr) &(temp_var_for_const_40 = 5.0783124372e-09)},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:190:12");
computeDSub((Addr)&temp_var_for_tac_38,
            {(Addr) &(temp_var_for_const_43 = 0.0),
             (Addr) &(temp_var_for_const_42 = 1.0253783315e-01)},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:191:12");
computeDSub((Addr)&temp_var_for_tac_39,
            {(Addr) &(temp_var_for_const_45 = 0.0),
             (Addr) &(temp_var_for_const_44 = 4.6101160049e+00)},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:192:12");
computeDSub((Addr)&temp_var_for_tac_40,
            {(Addr) &(temp_var_for_const_47 = 0.0),
             (Addr) &(temp_var_for_const_46 = 5.7847221375e+01)},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:193:12");
computeDSub((Addr)&temp_var_for_tac_41,
            {(Addr) &(temp_var_for_const_49 = 0.0),
             (Addr) &(temp_var_for_const_48 = 2.2824453735e+02)},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:194:12");
computeDSub((Addr)&temp_var_for_tac_42,
            {(Addr) &(temp_var_for_const_51 = 0.0),
             (Addr) &(temp_var_for_const_50 = 2.1921012878e+02)},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:195:12");
computeDSub((Addr)&temp_var_for_tac_43,
            {(Addr) &(temp_var_for_const_53 = 0.0),
             (Addr) &(temp_var_for_const_52 = 1.3520118713e+02)},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:204:12");
computeDSub((Addr)&temp_var_for_tac_44,
            {(Addr) &(temp_var_for_const_55 = 0.0),
             (Addr) &(temp_var_for_const_54 = 1.7838172539e-07)},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:209:12");
computeDSub((Addr)&temp_var_for_tac_45,
            {(Addr) &(temp_var_for_const_57 = 0.0),
             (Addr) &(temp_var_for_const_56 = 1.0251704603e-01)},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:210:12");
computeDSub((Addr)&temp_var_for_tac_46,
            {(Addr) &(temp_var_for_const_59 = 0.0),
             (Addr) &(temp_var_for_const_58 = 2.7522056103e+00)},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:211:12");
computeDSub((Addr)&temp_var_for_tac_47,
            {(Addr) &(temp_var_for_const_61 = 0.0),
             (Addr) &(temp_var_for_const_60 = 1.9663616180e+01)},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:212:12");
computeDSub((Addr)&temp_var_for_tac_48,
            {(Addr) &(temp_var_for_const_63 = 0.0),
             (Addr) &(temp_var_for_const_62 = 4.2325313568e+01)},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:213:12");
computeDSub((Addr)&temp_var_for_tac_49,
            {(Addr) &(temp_var_for_const_65 = 0.0),
             (Addr) &(temp_var_for_const_64 = 2.1371921539e+01)},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:214:12");
computeDSub((Addr)&temp_var_for_tac_50,
            {(Addr) &(temp_var_for_const_67 = 0.0),
             (Addr) &(temp_var_for_const_66 = 4.9594988823e+00)},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:223:12");
computeFMul((Addr)&temp_var_for_tac_51, {(Addr)&x, (Addr)&x},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:248:33");
computeFDiv((Addr)&temp_var_for_tac_52,
            {(Addr) &(temp_var_for_const_68 = one), (Addr)&temp_var_for_tac_51},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:248:28");
AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_52,
        "/home/shijia/Public/testprogram/s_ponef.c_e.c:248:22");
; // z
/*(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(2)(q[2])(z)(q)(1)(q[1])(z)(q)(0)(q[0])(z)(one)(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(2)(q[2])(z)(q)(1)(q[1])(z)(q)(0)(q[0])(z)(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(2)(q[2])(z)(q)(1)(q[1])(z)(q)(0)(q[0])(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(2)(q[2])(z)(q)(1)(q[1])(z)(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(2)(q[2])(z)(q)(1)(q[1])(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(2)(q[2])(z)(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(2)(q[2])(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(4)(q[4])(z)(q)(3)(q[3])(q)(4)(q[4])(z)(0)(e)(tem)(0)(e)(x)(x)(one)*/
z = temp_var_for_ext_1;
AssignF({(Addr)&z}, (Addr)&temp_var_for_ext_1,
        "/home/shijia/Public/testprogram/s_ponef.c_e.c:250:5");
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
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:251:64");
computeFAdd((Addr)&temp_var_for_tac_54, {(Addr) &(temp_var_for_const_70 = p[4]),
                                         (Addr)&temp_var_for_tac_53},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:251:60");
computeFMul((Addr)&temp_var_for_tac_55, {(Addr)&z, (Addr)&temp_var_for_tac_54},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:251:52");
computeFAdd((Addr)&temp_var_for_tac_56, {(Addr) &(temp_var_for_const_71 = p[3]),
                                         (Addr)&temp_var_for_tac_55},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:251:48");
computeFMul((Addr)&temp_var_for_tac_57, {(Addr)&z, (Addr)&temp_var_for_tac_56},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:251:40");
computeFAdd((Addr)&temp_var_for_tac_58, {(Addr) &(temp_var_for_const_72 = p[2]),
                                         (Addr)&temp_var_for_tac_57},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:251:36");
computeFMul((Addr)&temp_var_for_tac_59, {(Addr)&z, (Addr)&temp_var_for_tac_58},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:251:28");
computeFAdd((Addr)&temp_var_for_tac_60, {(Addr) &(temp_var_for_const_73 = p[1]),
                                         (Addr)&temp_var_for_tac_59},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:251:24");
computeFMul((Addr)&temp_var_for_tac_61, {(Addr)&z, (Addr)&temp_var_for_tac_60},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:251:16");
computeFAdd((Addr)&temp_var_for_tac_62, {(Addr) &(temp_var_for_const_74 = p[0]),
                                         (Addr)&temp_var_for_tac_61},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:251:12");
AssignF({(Addr)&r}, (Addr)&temp_var_for_tac_62,
        "/home/shijia/Public/testprogram/s_ponef.c_e.c:251:5");
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
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:253:69");
computeFAdd((Addr)&temp_var_for_tac_64, {(Addr) &(temp_var_for_const_76 = q[4]),
                                         (Addr)&temp_var_for_tac_63},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:253:65");
computeFMul((Addr)&temp_var_for_tac_65, {(Addr)&z, (Addr)&temp_var_for_tac_64},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:253:57");
computeFAdd((Addr)&temp_var_for_tac_66, {(Addr) &(temp_var_for_const_77 = q[3]),
                                         (Addr)&temp_var_for_tac_65},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:253:53");
computeFMul((Addr)&temp_var_for_tac_67, {(Addr)&z, (Addr)&temp_var_for_tac_66},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:253:45");
computeFAdd((Addr)&temp_var_for_tac_68, {(Addr) &(temp_var_for_const_78 = q[2]),
                                         (Addr)&temp_var_for_tac_67},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:253:41");
computeFMul((Addr)&temp_var_for_tac_69, {(Addr)&z, (Addr)&temp_var_for_tac_68},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:253:33");
computeFAdd((Addr)&temp_var_for_tac_70, {(Addr) &(temp_var_for_const_79 = q[1]),
                                         (Addr)&temp_var_for_tac_69},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:253:29");
computeFMul((Addr)&temp_var_for_tac_71, {(Addr)&z, (Addr)&temp_var_for_tac_70},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:253:21");
computeFAdd((Addr)&temp_var_for_tac_72, {(Addr) &(temp_var_for_const_80 = q[0]),
                                         (Addr)&temp_var_for_tac_71},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:253:17");
computeFMul((Addr)&temp_var_for_tac_73, {(Addr)&z, (Addr)&temp_var_for_tac_72},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:253:9");
computeFAdd((Addr)&temp_var_for_tac_74,
            {(Addr) &(temp_var_for_const_81 = one), (Addr)&temp_var_for_tac_73},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:252:11");
AssignF({(Addr)&s}, (Addr)&temp_var_for_tac_74,
        "/home/shijia/Public/testprogram/s_ponef.c_e.c:252:5");
;
float temp_var_for_ext_2;
float temp_var_for_tac_75, temp_var_for_tac_76, temp_var_for_tac_77;
float temp_var_for_const_82;
temp_var_for_tac_75 = r / s;

temp_var_for_tac_76 = .375f + temp_var_for_tac_75;

temp_var_for_tac_77 = temp_var_for_tac_76 / x;

temp_var_for_ext_2 = temp_var_for_tac_77;
computeFDiv((Addr)&temp_var_for_tac_75, {(Addr)&r, (Addr)&s},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:255:35");
computeFAdd((Addr)&temp_var_for_tac_76,
            {(Addr) &(temp_var_for_const_82 = .375f),
             (Addr)&temp_var_for_tac_75},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:255:31");
computeFDiv((Addr)&temp_var_for_tac_77, {(Addr)&temp_var_for_tac_76, (Addr)&x},
            "/home/shijia/Public/testprogram/s_ponef.c_e.c:255:40");
AssignF({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_77,
        "/home/shijia/Public/testprogram/s_ponef.c_e.c:255:22");
;
callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
callExp++; /*identify the function is  add move tmpShadow*/
return temp_var_for_ext_2;
}
