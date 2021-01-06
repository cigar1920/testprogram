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

#ifndef __NO_LONG_DOUBLE_MATH

long double __j0_y0_pzerol(long double x) {
  const long double *p, *q;
  long double z, r, s;
  int32_t ix;
  uint32_t se, i0, i1;

  static const long double one = 1.0L;

  /* The asymptotic expansions of pzero is
   *	1 - 9/128 s^2 + 11025/98304 s^4 - ...,	where s = 1/x.
   * For x >= 2, We approximate pzero by
   *	pzero(x) = 1 + s^2 R(s^2) / S(s^2)
   */
  static const long double pR8[7] = {
    /* 8 <= x <= inf
       Peak relative error 4.62 */
    (0.0 - 4.094398895124198016684337960227780260127E-9L);
  long double temp_var_for_const_0, temp_var_for_const_1;
  , (0.0 - 8.929643669432412640061946338524096893089E-7L);
  long double temp_var_for_const_2, temp_var_for_const_3;
  long double temp_var_for_tac_0;
  computeLdSub((Addr)&temp_var_for_tac_0,
               {(Addr) &(temp_var_for_const_1 = 0.0),
                (Addr) &(temp_var_for_const_0 =
                             4.094398895124198016684337960227780260127E-9L)},
               "/home/shijia/Public/testprogram/s_pzerol.c_e.c:35:12");
  , (0.0 - 6.281267456906136703868258380673108109256E-5L);
  long double temp_var_for_const_4, temp_var_for_const_5;
  long double temp_var_for_tac_1;
  computeLdSub((Addr)&temp_var_for_tac_1,
               {(Addr) &(temp_var_for_const_3 = 0.0),
                (Addr) &(temp_var_for_const_2 =
                             8.929643669432412640061946338524096893089E-7L)},
               "/home/shijia/Public/testprogram/s_pzerol.c_e.c:36:12");
  , (0.0 - 1.736902783620362966354814353559382399665E-3L);
  long double temp_var_for_const_6, temp_var_for_const_7;
  long double temp_var_for_tac_2;
  computeLdSub((Addr)&temp_var_for_tac_2,
               {(Addr) &(temp_var_for_const_5 = 0.0),
                (Addr) &(temp_var_for_const_4 =
                             6.281267456906136703868258380673108109256E-5L)},
               "/home/shijia/Public/testprogram/s_pzerol.c_e.c:37:12");
  , (0.0 - 1.831506216290984960532230842266070146847E-2L);
  long double temp_var_for_const_8, temp_var_for_const_9;
  long double temp_var_for_tac_3;
  computeLdSub((Addr)&temp_var_for_tac_3,
               {(Addr) &(temp_var_for_const_7 = 0.0),
                (Addr) &(temp_var_for_const_6 =
                             1.736902783620362966354814353559382399665E-3L)},
               "/home/shijia/Public/testprogram/s_pzerol.c_e.c:38:12");
  , (0.0 - 5.827178869301452892963280214772398135283E-2L);
  long double temp_var_for_const_10, temp_var_for_const_11;
  long double temp_var_for_tac_4;
  computeLdSub((Addr)&temp_var_for_tac_4,
               {(Addr) &(temp_var_for_const_9 = 0.0),
                (Addr) &(temp_var_for_const_8 =
                             1.831506216290984960532230842266070146847E-2L)},
               "/home/shijia/Public/testprogram/s_pzerol.c_e.c:39:12");
  , (0.0 - 2.087563267939546435460286895807046616992E-2L);
  long double temp_var_for_const_12, temp_var_for_const_13;
  long double temp_var_for_tac_5;
  computeLdSub((Addr)&temp_var_for_tac_5,
               {(Addr) &(temp_var_for_const_11 = 0.0),
                (Addr) &(temp_var_for_const_10 =
                             5.827178869301452892963280214772398135283E-2L)},
               "/home/shijia/Public/testprogram/s_pzerol.c_e.c:40:12");
};

static const long double pS8[6] = {
    5.823145095287749230197031108839653988393E-8L,
    1.279281986035060320477759999428992730280E-5L,
    9.132668954726626677174825517150228961304E-4L,
    2.606019379433060585351880541545146252534E-2L,
    2.956262215119520464228467583516287175244E-1L,
    1.149498145388256448535563278632697465675E0L
    /* 1.000000000000000000000000000000000000000E0L, */
};

static const long double pR5[7] = {
  /* 4.54541015625 <= x <= 8
     Peak relative error 6.51E-22 */
  (0.0 - 2.041226787870240954326915847282179737987E-7L);
long double temp_var_for_const_14, temp_var_for_const_15;
long double temp_var_for_tac_6;
computeLdSub((Addr)&temp_var_for_tac_6,
             {(Addr) &(temp_var_for_const_13 = 0.0),
              (Addr) &(temp_var_for_const_12 =
                           2.087563267939546435460286895807046616992E-2L)},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:55:12");
, (0.0 - 2.255373879859413325570636768224534428156E-5L);
long double temp_var_for_const_16, temp_var_for_const_17;
long double temp_var_for_tac_7;
computeLdSub((Addr)&temp_var_for_tac_7,
             {(Addr) &(temp_var_for_const_15 = 0.0),
              (Addr) &(temp_var_for_const_14 =
                           2.041226787870240954326915847282179737987E-7L)},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:56:12");
, (0.0 - 7.957485746440825353553537274569102059990E-4L);
long double temp_var_for_const_18, temp_var_for_const_19;
long double temp_var_for_tac_8;
computeLdSub((Addr)&temp_var_for_tac_8,
             {(Addr) &(temp_var_for_const_17 = 0.0),
              (Addr) &(temp_var_for_const_16 =
                           2.255373879859413325570636768224534428156E-5L)},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:57:12");
, (0.0 - 1.093205102486816696940149222095559439425E-2L);
long double temp_var_for_const_20, temp_var_for_const_21;
long double temp_var_for_tac_9;
computeLdSub((Addr)&temp_var_for_tac_9,
             {(Addr) &(temp_var_for_const_19 = 0.0),
              (Addr) &(temp_var_for_const_18 =
                           7.957485746440825353553537274569102059990E-4L)},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:58:12");
, (0.0 - 5.657957849316537477657603125260701114646E-2L);
long double temp_var_for_const_22, temp_var_for_const_23;
long double temp_var_for_tac_10;
computeLdSub((Addr)&temp_var_for_tac_10,
             {(Addr) &(temp_var_for_const_21 = 0.0),
              (Addr) &(temp_var_for_const_20 =
                           1.093205102486816696940149222095559439425E-2L)},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:59:12");
, (0.0 - 8.641175552716402616180994954177818461588E-2L);
long double temp_var_for_const_24, temp_var_for_const_25;
long double temp_var_for_tac_11;
computeLdSub((Addr)&temp_var_for_tac_11,
             {(Addr) &(temp_var_for_const_23 = 0.0),
              (Addr) &(temp_var_for_const_22 =
                           5.657957849316537477657603125260701114646E-2L)},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:60:12");
, (0.0 - 1.354654710097134007437166939230619726157E-2L);
long double temp_var_for_const_26, temp_var_for_const_27;
long double temp_var_for_tac_12;
computeLdSub((Addr)&temp_var_for_tac_12,
             {(Addr) &(temp_var_for_const_25 = 0.0),
              (Addr) &(temp_var_for_const_24 =
                           8.641175552716402616180994954177818461588E-2L)},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:61:12");
}
;

static const long double pS5[6] = {
    2.903078099681108697057258628212823545290E-6L,
    3.253948449946735405975737677123673867321E-4L,
    1.181269751723085006534147920481582279979E-2L,
    1.719212057790143888884745200257619469363E-1L,
    1.006306498779212467670654535430694221924E0L,
    2.069568808688074324555596301126375951502E0L
    /* 1.000000000000000000000000000000000000000E0L, */
};

static const long double pR3[7] = {
  /* 2.85711669921875 <= x <= 4.54541015625
     peak relative error 5.25e-21 */
  (0.0 - 5.755732156848468345557663552240816066802E-6L);
long double temp_var_for_const_28, temp_var_for_const_29;
long double temp_var_for_tac_13;
computeLdSub((Addr)&temp_var_for_tac_13,
             {(Addr) &(temp_var_for_const_27 = 0.0),
              (Addr) &(temp_var_for_const_26 =
                           1.354654710097134007437166939230619726157E-2L)},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:76:12");
, (0.0 - 3.703675625855715998827966962258113034767E-4L);
long double temp_var_for_const_30, temp_var_for_const_31;
long double temp_var_for_tac_14;
computeLdSub((Addr)&temp_var_for_tac_14,
             {(Addr) &(temp_var_for_const_29 = 0.0),
              (Addr) &(temp_var_for_const_28 =
                           5.755732156848468345557663552240816066802E-6L)},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:77:12");
, (0.0 - 7.390893350679637611641350096842846433236E-3L);
long double temp_var_for_const_32, temp_var_for_const_33;
long double temp_var_for_tac_15;
computeLdSub((Addr)&temp_var_for_tac_15,
             {(Addr) &(temp_var_for_const_31 = 0.0),
              (Addr) &(temp_var_for_const_30 =
                           3.703675625855715998827966962258113034767E-4L)},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:78:12");
, (0.0 - 5.571922144490038765024591058478043873253E-2L);
long double temp_var_for_const_34, temp_var_for_const_35;
long double temp_var_for_tac_16;
computeLdSub((Addr)&temp_var_for_tac_16,
             {(Addr) &(temp_var_for_const_33 = 0.0),
              (Addr) &(temp_var_for_const_32 =
                           7.390893350679637611641350096842846433236E-3L)},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:79:12");
, (0.0 - 1.531290690378157869291151002472627396088E-1L);
long double temp_var_for_const_36, temp_var_for_const_37;
long double temp_var_for_tac_17;
computeLdSub((Addr)&temp_var_for_tac_17,
             {(Addr) &(temp_var_for_const_35 = 0.0),
              (Addr) &(temp_var_for_const_34 =
                           5.571922144490038765024591058478043873253E-2L)},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:80:12");
, (0.0 - 1.193350853469302941921647487062620011042E-1L);
long double temp_var_for_const_38, temp_var_for_const_39;
long double temp_var_for_tac_18;
computeLdSub((Addr)&temp_var_for_tac_18,
             {(Addr) &(temp_var_for_const_37 = 0.0),
              (Addr) &(temp_var_for_const_36 =
                           1.531290690378157869291151002472627396088E-1L)},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:81:12");
, (0.0 - 8.567802507331578894302991505331963782905E-3L);
long double temp_var_for_const_40, temp_var_for_const_41;
long double temp_var_for_tac_19;
computeLdSub((Addr)&temp_var_for_tac_19,
             {(Addr) &(temp_var_for_const_39 = 0.0),
              (Addr) &(temp_var_for_const_38 =
                           1.193350853469302941921647487062620011042E-1L)},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:82:12");
}
;

static const long double pS3[6] = {
    8.185931139070086158103309281525036712419E-5L,
    5.398016943778891093520574483111255476787E-3L,
    1.130589193590489566669164765853409621081E-1L,
    9.358652328786413274673192987670237145071E-1L,
    3.091711512598349056276917907005098085273E0L,
    3.594602474737921977972586821673124231111E0L
    /* 1.000000000000000000000000000000000000000E0L, */
};

static const long double pR2[7] = {
  /* 2 <= x <= 2.85711669921875
     peak relative error 2.64e-21 */
  (0.0 - 1.219525235804532014243621104365384992623E-4L);
long double temp_var_for_const_42, temp_var_for_const_43;
long double temp_var_for_tac_20;
computeLdSub((Addr)&temp_var_for_tac_20,
             {(Addr) &(temp_var_for_const_41 = 0.0),
              (Addr) &(temp_var_for_const_40 =
                           8.567802507331578894302991505331963782905E-3L)},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:97:12");
, (0.0 - 4.838597135805578919601088680065298763049E-3L);
long double temp_var_for_const_44, temp_var_for_const_45;
long double temp_var_for_tac_21;
computeLdSub((Addr)&temp_var_for_tac_21,
             {(Addr) &(temp_var_for_const_43 = 0.0),
              (Addr) &(temp_var_for_const_42 =
                           1.219525235804532014243621104365384992623E-4L)},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:98:12");
, (0.0 - 5.732223181683569266223306197751407418301E-2L);
long double temp_var_for_const_46, temp_var_for_const_47;
long double temp_var_for_tac_22;
computeLdSub((Addr)&temp_var_for_tac_22,
             {(Addr) &(temp_var_for_const_45 = 0.0),
              (Addr) &(temp_var_for_const_44 =
                           4.838597135805578919601088680065298763049E-3L)},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:99:12");
, (0.0 - 2.472947430526425064982909699406646503758E-1L);
long double temp_var_for_const_48, temp_var_for_const_49;
long double temp_var_for_tac_23;
computeLdSub((Addr)&temp_var_for_tac_23,
             {(Addr) &(temp_var_for_const_47 = 0.0),
              (Addr) &(temp_var_for_const_46 =
                           5.732223181683569266223306197751407418301E-2L)},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:100:12");
, (0.0 - 3.753373645974077960207588073975976327695E-1L);
long double temp_var_for_const_50, temp_var_for_const_51;
long double temp_var_for_tac_24;
computeLdSub((Addr)&temp_var_for_tac_24,
             {(Addr) &(temp_var_for_const_49 = 0.0),
              (Addr) &(temp_var_for_const_48 =
                           2.472947430526425064982909699406646503758E-1L)},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:101:12");
, (0.0 - 1.556241316844728872406672349347137975495E-1L);
long double temp_var_for_const_52, temp_var_for_const_53;
long double temp_var_for_tac_25;
computeLdSub((Addr)&temp_var_for_tac_25,
             {(Addr) &(temp_var_for_const_51 = 0.0),
              (Addr) &(temp_var_for_const_50 =
                           3.753373645974077960207588073975976327695E-1L)},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:102:12");
, (0.0 - 5.355423239526452209595316733635519506958E-3L);
long double temp_var_for_const_54, temp_var_for_const_55;
long double temp_var_for_tac_26;
computeLdSub((Addr)&temp_var_for_tac_26,
             {(Addr) &(temp_var_for_const_53 = 0.0),
              (Addr) &(temp_var_for_const_52 =
                           1.556241316844728872406672349347137975495E-1L)},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:103:12");
}
;

static const long double pS2[6] = {
    1.734442793664291412489066256138894953823E-3L,
    7.158111826468626405416300895617986926008E-2L,
    9.153839713992138340197264669867993552641E-1L,
    4.539209519433011393525841956702487797582E0L,
    8.868932430625331650266067101752626253644E0L,
    6.067161890196324146320763844772857713502E0L
    /* 1.000000000000000000000000000000000000000E0L, */
};

GET_LDOUBLE_WORDS(se, i0, i1, x);
ix = se & 0x7fff;
if (ix >= 0x4002) {
  /* x >= 8 */
  p = pR8;
  q = pS8;
} else {
  i1 = (ix << 16) | (i0 >> 16);
  if (i1 >= UC(0x40019174)) {
    /* x >= 4.54541015625 */
    p = pR5;
    q = pS5;
  } else if (i1 >= UC(0x4000b6db)) {
    /* x >= 2.85711669921875 */
    p = pR3;
    q = pS3;
  } else /* if (ix >= 0x4000) */
  {
    /* x >= 2 */
    p = pR2;
    q = pS2;
  }
}
z = one / (x * x);
long double temp_var_for_const_56;
long double temp_var_for_tac_27, temp_var_for_tac_28;
computeLdSub((Addr)&temp_var_for_tac_27,
             {(Addr) &(temp_var_for_const_55 = 0.0),
              (Addr) &(temp_var_for_const_54 =
                           5.355423239526452209595316733635519506958E-3L)},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:138:16");
computeLdMul((Addr)&temp_var_for_tac_28, {(Addr)&x, (Addr)&x},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:138:11");
computeLdDiv((Addr)&z, {(Addr) &(temp_var_for_const_56 = one),
                        (Addr)&temp_var_for_tac_28},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:138:5");
r = p[0] +
    z * (p[1] + z * (p[2] + z * (p[3] + z * (p[4] + z * (p[5] + z * p[6])))));
long double temp_var_for_const_57, temp_var_for_const_58, temp_var_for_const_59,
    temp_var_for_const_60, temp_var_for_const_61, temp_var_for_const_62,
    temp_var_for_const_63;
long double temp_var_for_tac_29, temp_var_for_tac_30, temp_var_for_tac_31,
    temp_var_for_tac_32, temp_var_for_tac_33, temp_var_for_tac_34,
    temp_var_for_tac_35, temp_var_for_tac_36, temp_var_for_tac_37,
    temp_var_for_tac_38, temp_var_for_tac_39;
computeLdMul((Addr)&temp_var_for_tac_29,
             {(Addr)&z, (Addr) &(temp_var_for_const_57 = p[6])},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:140:65");
computeLdAdd((Addr)&temp_var_for_tac_30,
             {(Addr) &(temp_var_for_const_58 = p[5]),
              (Addr)&temp_var_for_tac_29},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:140:57");
computeLdMul((Addr)&temp_var_for_tac_31, {(Addr)&z, (Addr)&temp_var_for_tac_30},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:140:53");
computeLdAdd((Addr)&temp_var_for_tac_32,
             {(Addr) &(temp_var_for_const_59 = p[4]),
              (Addr)&temp_var_for_tac_31},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:140:45");
computeLdMul((Addr)&temp_var_for_tac_33, {(Addr)&z, (Addr)&temp_var_for_tac_32},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:140:41");
computeLdAdd((Addr)&temp_var_for_tac_34,
             {(Addr) &(temp_var_for_const_60 = p[3]),
              (Addr)&temp_var_for_tac_33},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:140:33");
computeLdMul((Addr)&temp_var_for_tac_35, {(Addr)&z, (Addr)&temp_var_for_tac_34},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:140:29");
computeLdAdd((Addr)&temp_var_for_tac_36,
             {(Addr) &(temp_var_for_const_61 = p[2]),
              (Addr)&temp_var_for_tac_35},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:140:21");
computeLdMul((Addr)&temp_var_for_tac_37, {(Addr)&z, (Addr)&temp_var_for_tac_36},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:140:17");
computeLdAdd((Addr)&temp_var_for_tac_38,
             {(Addr) &(temp_var_for_const_62 = p[1]),
              (Addr)&temp_var_for_tac_37},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:140:9");
computeLdMul((Addr)&temp_var_for_tac_39, {(Addr)&z, (Addr)&temp_var_for_tac_38},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:139:12");
computeLdAdd((Addr)&r, {(Addr) &(temp_var_for_const_63 = p[0]),
                        (Addr)&temp_var_for_tac_39},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:139:5");
s = q[0] + z * (q[1] + z * (q[2] + z * (q[3] + z * (q[4] + z * (q[5] + z)))));
long double temp_var_for_const_64, temp_var_for_const_65, temp_var_for_const_66,
    temp_var_for_const_67, temp_var_for_const_68, temp_var_for_const_69;
long double temp_var_for_tac_40, temp_var_for_tac_41, temp_var_for_tac_42,
    temp_var_for_tac_43, temp_var_for_tac_44, temp_var_for_tac_45,
    temp_var_for_tac_46, temp_var_for_tac_47, temp_var_for_tac_48,
    temp_var_for_tac_49;
computeLdAdd((Addr)&temp_var_for_tac_40,
             {(Addr) &(temp_var_for_const_64 = q[5]), (Addr)&z},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:141:64");
computeLdMul((Addr)&temp_var_for_tac_41, {(Addr)&z, (Addr)&temp_var_for_tac_40},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:141:60");
computeLdAdd((Addr)&temp_var_for_tac_42,
             {(Addr) &(temp_var_for_const_65 = q[4]),
              (Addr)&temp_var_for_tac_41},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:141:52");
computeLdMul((Addr)&temp_var_for_tac_43, {(Addr)&z, (Addr)&temp_var_for_tac_42},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:141:48");
computeLdAdd((Addr)&temp_var_for_tac_44,
             {(Addr) &(temp_var_for_const_66 = q[3]),
              (Addr)&temp_var_for_tac_43},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:141:40");
computeLdMul((Addr)&temp_var_for_tac_45, {(Addr)&z, (Addr)&temp_var_for_tac_44},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:141:36");
computeLdAdd((Addr)&temp_var_for_tac_46,
             {(Addr) &(temp_var_for_const_67 = q[2]),
              (Addr)&temp_var_for_tac_45},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:141:28");
computeLdMul((Addr)&temp_var_for_tac_47, {(Addr)&z, (Addr)&temp_var_for_tac_46},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:141:24");
computeLdAdd((Addr)&temp_var_for_tac_48,
             {(Addr) &(temp_var_for_const_68 = q[1]),
              (Addr)&temp_var_for_tac_47},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:141:16");
computeLdMul((Addr)&temp_var_for_tac_49, {(Addr)&z, (Addr)&temp_var_for_tac_48},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:141:12");
computeLdAdd((Addr)&s, {(Addr) &(temp_var_for_const_69 = q[0]),
                        (Addr)&temp_var_for_tac_49},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:141:5");
long double temp_var_for_ext_0;
temp_var_for_ext_0 = (one + z * r / s);
long double temp_var_for_const_70;
long double temp_var_for_tac_50, temp_var_for_tac_51;
computeLdMul((Addr)&temp_var_for_tac_50, {(Addr)&z, (Addr)&r},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:143:37");
computeLdDiv((Addr)&temp_var_for_tac_51, {(Addr)&temp_var_for_tac_50, (Addr)&s},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:143:29");
computeLdAdd((Addr)&temp_var_for_ext_0, {(Addr) &(temp_var_for_const_70 = one),
                                         (Addr)&temp_var_for_tac_51},
             "/home/shijia/Public/testprogram/s_pzerol.c_e.c:143:22");
callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
callExp++; /*identify the function is  add move tmpShadow*/
return temp_var_for_ext_0;
}

long double __j0_y0_qzerol(long double x) {
  const long double *p, *q;
  long double s, r, z;
  int32_t ix;
  uint32_t se, i0, i1;

  static const long double one = 1.0L;

  /* For x >= 8, the asymptotic expansions of qzero is
   *	-1/8 s + 75/1024 s^3 - ..., where s = 1/x.
   * We approximate qzero by
   *	qzero(x) = s*(-.125 + R(s^2) / S(s^2))
   */
  static const long double qR8[7] = {
      /* 8 <= x <= inf
         peak relative error 2.23e-21 */
      3.001267180483191397885272640777189348008E-10L,
      8.693186311430836495238494289942413810121E-8L,
      8.496875536711266039522937037850596580686E-6L,
      3.482702869915288984296602449543513958409E-4L,
      6.036378380706107692863811938221290851352E-3L,
      3.881970028476167836382607922840452192636E-2L,
      6.132191514516237371140841765561219149638E-2L};

  static const long double qS8[7] = {
      4.097730123753051126914971174076227600212E-9L,
      1.199615869122646109596153392152131139306E-6L,
      1.196337580514532207793107149088168946451E-4L,
      5.099074440112045094341500497767181211104E-3L,
      9.577420799632372483249761659674764460583E-2L,
      7.385243015344292267061953461563695918646E-1L,
      1.917266424391428937962682301561699055943E0L
      /* 1.000000000000000000000000000000000000000E0L, */
  };

  static const long double qR5[7] = {
      /* 4.54541015625 <= x <= 8
         peak relative error 1.03e-21 */
      3.406256556438974327309660241748106352137E-8L,
      4.855492710552705436943630087976121021980E-6L,
      2.301011739663737780613356017352912281980E-4L,
      4.500470249273129953870234803596619899226E-3L,
      3.651376459725695502726921248173637054828E-2L,
      1.071578819056574524416060138514508609805E-1L,
      7.458950172851611673015774675225656063757E-2L};

  static const long double qS5[7] = {
      4.650675622764245276538207123618745150785E-7L,
      6.773573292521412265840260065635377164455E-5L,
      3.340711249876192721980146877577806687714E-3L,
      7.036218046856839214741678375536970613501E-2L,
      6.569599559163872573895171876511377891143E-1L,
      2.557525022583599204591036677199171155186E0L,
      3.457237396120935674982927714210361269133E0L
      /* 1.000000000000000000000000000000000000000E0L, */
  };

  static const long double qR3[7] = {
      /* 2.85711669921875 <= x <= 4.54541015625
         peak relative error 5.24e-21 */
      1.749459596550816915639829017724249805242E-6L,
      1.446252487543383683621692672078376929437E-4L,
      3.842084087362410664036704812125005761859E-3L,
      4.066369994699462547896426554180954233581E-2L,
      1.721093619117980251295234795188992722447E-1L,
      2.538595333972857367655146949093055405072E-1L,
      8.560591367256769038905328596020118877936E-2L};

  static const long double qS3[7] = {
      2.388596091707517488372313710647510488042E-5L,
      2.048679968058758616370095132104333998147E-3L,
      5.824663198201417760864458765259945181513E-2L,
      6.953906394693328750931617748038994763958E-1L,
      3.638186936390881159685868764832961092476E0L,
      7.900169524705757837298990558459547842607E0L,
      5.992718532451026507552820701127504582907E0L
      /* 1.000000000000000000000000000000000000000E0L, */
  };

  static const long double qR2[7] = {
      /* 2 <= x <= 2.85711669921875
         peak relative error 1.58e-21  */
      6.306524405520048545426928892276696949540E-5L,
      3.209606155709930950935893996591576624054E-3L,
      5.027828775702022732912321378866797059604E-2L,
      3.012705561838718956481911477587757845163E-1L,
      6.960544893905752937420734884995688523815E-1L,
      5.431871999743531634887107835372232030655E-1L,
      9.447736151202905471899259026430157211949E-2L};

  static const long double qS2[7] = {
      8.610579901936193494609755345106129102676E-4L,
      4.649054352710496997203474853066665869047E-2L,
      8.104282924459837407218042945106320388339E-1L,
      5.807730930825886427048038146088828206852E0L,
      1.795310145936848873627710102199881642939E1L,
      2.281313316875375733663657188888110605044E1L,
      1.011242067883822301487154844458322200143E1L
      /* 1.000000000000000000000000000000000000000E0L, */
  };

  GET_LDOUBLE_WORDS(se, i0, i1, x);
  ix = se & 0x7fff;
  if (ix >= 0x4002) {
    /* x >= 8 */
    p = qR8;
    q = qS8;
  } else {
    i1 = (ix << 16) | (i0 >> 16);
    if (i1 >= UC(0x40019174)) {
      /* x >= 4.54541015625 */
      p = qR5;
      q = qS5;
    } else if (i1 >= UC(0x4000b6db)) {
      /* x >= 2.85711669921875 */
      p = qR3;
      q = qS3;
    } else /* if (ix >= 0x4000) */
    {
      /* x >= 2 */
      p = qR2;
      q = qS2;
    }
  }
  long double temp_var_for_ext_1;
  temp_var_for_ext_1 = one / (x * x);
  long double temp_var_for_const_71;
  long double temp_var_for_tac_52;
  computeLdMul((Addr)&temp_var_for_tac_52, {(Addr)&x, (Addr)&x},
               "/home/shijia/Public/testprogram/s_pzerol.c_e.c:274:28");
  computeLdDiv(
      (Addr)&temp_var_for_ext_1,
      {(Addr) &(temp_var_for_const_71 = one), (Addr)&temp_var_for_tac_52},
      "/home/shijia/Public/testprogram/s_pzerol.c_e.c:274:22"); // z
  /*(z)(q)(5)(q[5])(z)(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(2)(q[2])(z)(q)(1)(q[1])(z)(q)(0)(q[0])(z)(q)(5)(q[5])(z)(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(2)(q[2])(z)(q)(1)(q[1])(z)(z)(q)(5)(q[5])(z)(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(2)(q[2])(z)(q)(1)(q[1])(z)(q)(5)(q[5])(z)(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(2)(q[2])(z)(z)(q)(5)(q[5])(z)(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(2)(q[2])(z)(q)(5)(q[5])(z)(q)(4)(q[4])(z)(q)(3)(q[3])(z)(z)(q)(5)(q[5])(z)(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(5)(q[5])(z)(q)(4)(q[4])(z)(z)(q)(5)(q[5])(z)(q)(4)(q[4])(z)(q)(5)(q[5])(z)(z)(q)(5)(q[5])(_)(_)(_)(mp_)(_)(_)(_)(_)(_)(x)(x)(one)*/
  z = temp_var_for_ext_1;
  AssignLd({(Addr)&z}, (Addr)&temp_var_for_ext_1,
           "/home/shijia/Public/testprogram/s_pzerol.c_e.c:276:5");
  r = p[0] +
      z * (p[1] + z * (p[2] + z * (p[3] + z * (p[4] + z * (p[5] + z * p[6])))));
  long double temp_var_for_const_72, temp_var_for_const_73,
      temp_var_for_const_74, temp_var_for_const_75, temp_var_for_const_76,
      temp_var_for_const_77, temp_var_for_const_78;
  long double temp_var_for_tac_53, temp_var_for_tac_54, temp_var_for_tac_55,
      temp_var_for_tac_56, temp_var_for_tac_57, temp_var_for_tac_58,
      temp_var_for_tac_59, temp_var_for_tac_60, temp_var_for_tac_61,
      temp_var_for_tac_62, temp_var_for_tac_63;
  computeLdMul((Addr)&temp_var_for_tac_53,
               {(Addr)&z, (Addr) &(temp_var_for_const_72 = p[6])},
               "/home/shijia/Public/testprogram/s_pzerol.c_e.c:278:65");
  computeLdAdd(
      (Addr)&temp_var_for_tac_54,
      {(Addr) &(temp_var_for_const_73 = p[5]), (Addr)&temp_var_for_tac_53},
      "/home/shijia/Public/testprogram/s_pzerol.c_e.c:278:57");
  computeLdMul((Addr)&temp_var_for_tac_55,
               {(Addr)&z, (Addr)&temp_var_for_tac_54},
               "/home/shijia/Public/testprogram/s_pzerol.c_e.c:278:53");
  computeLdAdd(
      (Addr)&temp_var_for_tac_56,
      {(Addr) &(temp_var_for_const_74 = p[4]), (Addr)&temp_var_for_tac_55},
      "/home/shijia/Public/testprogram/s_pzerol.c_e.c:278:45");
  computeLdMul((Addr)&temp_var_for_tac_57,
               {(Addr)&z, (Addr)&temp_var_for_tac_56},
               "/home/shijia/Public/testprogram/s_pzerol.c_e.c:278:41");
  computeLdAdd(
      (Addr)&temp_var_for_tac_58,
      {(Addr) &(temp_var_for_const_75 = p[3]), (Addr)&temp_var_for_tac_57},
      "/home/shijia/Public/testprogram/s_pzerol.c_e.c:278:33");
  computeLdMul((Addr)&temp_var_for_tac_59,
               {(Addr)&z, (Addr)&temp_var_for_tac_58},
               "/home/shijia/Public/testprogram/s_pzerol.c_e.c:278:29");
  computeLdAdd(
      (Addr)&temp_var_for_tac_60,
      {(Addr) &(temp_var_for_const_76 = p[2]), (Addr)&temp_var_for_tac_59},
      "/home/shijia/Public/testprogram/s_pzerol.c_e.c:278:21");
  computeLdMul((Addr)&temp_var_for_tac_61,
               {(Addr)&z, (Addr)&temp_var_for_tac_60},
               "/home/shijia/Public/testprogram/s_pzerol.c_e.c:278:17");
  computeLdAdd(
      (Addr)&temp_var_for_tac_62,
      {(Addr) &(temp_var_for_const_77 = p[1]), (Addr)&temp_var_for_tac_61},
      "/home/shijia/Public/testprogram/s_pzerol.c_e.c:278:9");
  computeLdMul((Addr)&temp_var_for_tac_63,
               {(Addr)&z, (Addr)&temp_var_for_tac_62},
               "/home/shijia/Public/testprogram/s_pzerol.c_e.c:277:12");
  computeLdAdd((Addr)&r, {(Addr) &(temp_var_for_const_78 = p[0]),
                          (Addr)&temp_var_for_tac_63},
               "/home/shijia/Public/testprogram/s_pzerol.c_e.c:277:5");
  s = q[0] +
      z * (q[1] +
           z * (q[2] + z * (q[3] + z * (q[4] + z * (q[5] + z * (q[6] + z))))));
  long double temp_var_for_const_79, temp_var_for_const_80,
      temp_var_for_const_81, temp_var_for_const_82, temp_var_for_const_83,
      temp_var_for_const_84, temp_var_for_const_85;
  long double temp_var_for_tac_64, temp_var_for_tac_65, temp_var_for_tac_66,
      temp_var_for_tac_67, temp_var_for_tac_68, temp_var_for_tac_69,
      temp_var_for_tac_70, temp_var_for_tac_71, temp_var_for_tac_72,
      temp_var_for_tac_73, temp_var_for_tac_74, temp_var_for_tac_75;
  computeLdAdd((Addr)&temp_var_for_tac_64,
               {(Addr) &(temp_var_for_const_79 = q[6]), (Addr)&z},
               "/home/shijia/Public/testprogram/s_pzerol.c_e.c:281:62");
  computeLdMul((Addr)&temp_var_for_tac_65,
               {(Addr)&z, (Addr)&temp_var_for_tac_64},
               "/home/shijia/Public/testprogram/s_pzerol.c_e.c:281:58");
  computeLdAdd(
      (Addr)&temp_var_for_tac_66,
      {(Addr) &(temp_var_for_const_80 = q[5]), (Addr)&temp_var_for_tac_65},
      "/home/shijia/Public/testprogram/s_pzerol.c_e.c:281:50");
  computeLdMul((Addr)&temp_var_for_tac_67,
               {(Addr)&z, (Addr)&temp_var_for_tac_66},
               "/home/shijia/Public/testprogram/s_pzerol.c_e.c:281:46");
  computeLdAdd(
      (Addr)&temp_var_for_tac_68,
      {(Addr) &(temp_var_for_const_81 = q[4]), (Addr)&temp_var_for_tac_67},
      "/home/shijia/Public/testprogram/s_pzerol.c_e.c:281:38");
  computeLdMul((Addr)&temp_var_for_tac_69,
               {(Addr)&z, (Addr)&temp_var_for_tac_68},
               "/home/shijia/Public/testprogram/s_pzerol.c_e.c:281:34");
  computeLdAdd(
      (Addr)&temp_var_for_tac_70,
      {(Addr) &(temp_var_for_const_82 = q[3]), (Addr)&temp_var_for_tac_69},
      "/home/shijia/Public/testprogram/s_pzerol.c_e.c:281:26");
  computeLdMul((Addr)&temp_var_for_tac_71,
               {(Addr)&z, (Addr)&temp_var_for_tac_70},
               "/home/shijia/Public/testprogram/s_pzerol.c_e.c:281:22");
  computeLdAdd(
      (Addr)&temp_var_for_tac_72,
      {(Addr) &(temp_var_for_const_83 = q[2]), (Addr)&temp_var_for_tac_71},
      "/home/shijia/Public/testprogram/s_pzerol.c_e.c:281:14");
  computeLdMul((Addr)&temp_var_for_tac_73,
               {(Addr)&z, (Addr)&temp_var_for_tac_72},
               "/home/shijia/Public/testprogram/s_pzerol.c_e.c:280:17");
  computeLdAdd(
      (Addr)&temp_var_for_tac_74,
      {(Addr) &(temp_var_for_const_84 = q[1]), (Addr)&temp_var_for_tac_73},
      "/home/shijia/Public/testprogram/s_pzerol.c_e.c:280:9");
  computeLdMul((Addr)&temp_var_for_tac_75,
               {(Addr)&z, (Addr)&temp_var_for_tac_74},
               "/home/shijia/Public/testprogram/s_pzerol.c_e.c:279:12");
  computeLdAdd((Addr)&s, {(Addr) &(temp_var_for_const_85 = q[0]),
                          (Addr)&temp_var_for_tac_75},
               "/home/shijia/Public/testprogram/s_pzerol.c_e.c:279:5");
  long double temp_var_for_ext_2;
  temp_var_for_ext_2 = (-.125 + z * r / s) / x;
  long double temp_var_for_tac_76, temp_var_for_tac_77, temp_var_for_tac_78;
  computeLdMul((Addr)&temp_var_for_tac_76, {(Addr)&z, (Addr)&r},
               "/home/shijia/Public/testprogram/s_pzerol.c_e.c:283:39");
  computeLdDiv((Addr)&temp_var_for_tac_77,
               {(Addr)&temp_var_for_tac_76, (Addr)&s},
               "/home/shijia/Public/testprogram/s_pzerol.c_e.c:283:31");
  computeLdAdd((Addr)&temp_var_for_tac_78,
               {(Addr) & (-(.125)), (Addr)&temp_var_for_tac_77},
               "/home/shijia/Public/testprogram/s_pzerol.c_e.c:283:44");
  computeLdDiv((Addr)&temp_var_for_ext_2,
               {(Addr)&temp_var_for_tac_78, (Addr)&x},
               "/home/shijia/Public/testprogram/s_pzerol.c_e.c:283:22");
  callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
  callExp++; /*identify the function is  add move tmpShadow*/
  ret(0.0 - rn t) emp_var_for_ext_2;
}

#endif
