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

long double __j1_y1_ponel(long double x) {
  const long double *p, *q;
  long double z, r, s;
  int32_t ix;
  uint32_t se, i0, i1;

  static const long double one = 1.0L;

  /* For x >= 8, the asymptotic expansions of pone is
   *	1 + 15/128 s^2 - 4725/2^15 s^4 - ...,	where s = 1/x.
   * We approximate pone by
   *	pone(x) = 1 + (R/S)
   */
  /* J1(x) cosX + Y1(x) sinX  =  sqrt( 2/(pi x)) P1(x)
     P1(x) = 1 + z^2 R(z^2), z=1/x
     8 <= x <= inf  (0 <= z <= 0.125)
     Peak relative error 5.2e-22  */
  static const long double pr8[7] = {
      8.402048819032978959298664869941375143163E-9L,
      1.813743245316438056192649247507255996036E-6L,
      1.260704554112906152344932388588243836276E-4L,
      3.439294839869103014614229832700986965110E-3L,
      3.576910849712074184504430254290179501209E-2L,
      1.131111483254318243139953003461511308672E-1L,
      4.480715825681029711521286449131671880953E-2L};

  static const long double ps8[6] = {
      7.169748325574809484893888315707824924354E-8L,
      1.556549720596672576431813934184403614817E-5L,
      1.094540125521337139209062035774174565882E-3L,
      3.060978962596642798560894375281428805840E-2L,
      3.374146536087205506032643098619414507024E-1L,
      1.253830208588979001991901126393231302559E0L
      /* 1.000000000000000000000000000000000000000E0L, */
  };

  /* J1(x) cosX + Y1(x) sinX  =  sqrt( 2/(pi x)) P1(x)
     P1(x) = 1 + z^2 R(z^2), z=1/x
     4.54541015625 <= x <= 8
     Peak relative error 7.7e-22  */
  static const long double pr5[7] = {
      4.318486887948814529950980396300969247900E-7L,
      4.715341880798817230333360497524173929315E-5L,
      1.642719430496086618401091544113220340094E-3L,
      2.228688005300803935928733750456396149104E-2L,
      1.142773760804150921573259605730018327162E-1L,
      1.755576530055079253910829652698703791957E-1L,
      3.218803858282095929559165965353784980613E-2L};

  static const long double ps5[6] = {
      3.685108812227721334719884358034713967557E-6L,
      4.069102509511177498808856515005792027639E-4L,
      1.449728676496155025507893322405597039816E-2L,
      2.058869213229520086582695850441194363103E-1L,
      1.164890985918737148968424972072751066553E0L,
      2.274776933457009446573027260373361586841E0L
      /*  1.000000000000000000000000000000000000000E0L, */
  };

  /* J1(x) cosX + Y1(x) sinX  =  sqrt( 2/(pi x)) P1(x)
     P1(x) = 1 + z^2 R(z^2), z=1/x
     2.85711669921875 <= x <= 4.54541015625
     Peak relative error 6.5e-21  */
  static const long double pr3[7] = {
      1.265251153957366716825382654273326407972E-5L,
      8.031057269201324914127680782288352574567E-4L,
      1.581648121115028333661412169396282881035E-2L,
      1.179534658087796321928362981518645033967E-1L,
      3.227936912780465219246440724502790727866E-1L,
      2.559223765418386621748404398017602935764E-1L,
      2.277136933287817911091370397134882441046E-2L};

  static const long double ps3[6] = {
      1.079681071833391818661952793568345057548E-4L,
      6.986017817100477138417481463810841529026E-3L,
      1.429403701146942509913198539100230540503E-1L,
      1.148392024337075609460312658938700765074E0L,
      3.643663015091248720208251490291968840882E0L,
      3.990702269032018282145100741746633960737E0L
      /* 1.000000000000000000000000000000000000000E0L, */
  };

  /* J1(x) cosX + Y1(x) sinX  =  sqrt( 2/(pi x)) P1(x)
     P1(x) = 1 + z^2 R(z^2), z=1/x
     2 <= x <= 2.85711669921875
     Peak relative error 3.5e-21  */
  static const long double pr2[7] = {
      2.795623248568412225239401141338714516445E-4L,
      1.092578168441856711925254839815430061135E-2L,
      1.278024620468953761154963591853679640560E-1L,
      5.469680473691500673112904286228351988583E-1L,
      8.313769490922351300461498619045639016059E-1L,
      3.544176317308370086415403567097130611468E-1L,
      1.604142674802373041247957048801599740644E-2L};

  static const long double ps2[6] = {
      2.385605161555183386205027000675875235980E-3L,
      9.616778294482695283928617708206967248579E-2L,
      1.195215570959693572089824415393951258510E0L,
      5.718412857897054829999458736064922974662E0L,
      1.065626298505499086386584642761602177568E1L,
      6.809140730053382188468983548092322151791E0L
      /* 1.000000000000000000000000000000000000000E0L, */
  };

  GET_LDOUBLE_WORDS(se, i0, i1, x);
  ix = se & 0x7fff;
  if (ix >= 0x4002) /* x >= 8 */
  {
    p = pr8;
    q = ps8;
  } else {
    i1 = (ix << 16) | (i0 >> 16);
    if (i1 >= UC(0x40019174)) /* x >= 4.54541015625 */
    {
      p = pr5;
      q = ps5;
    } else if (i1 >= UC(0x4000b6db)) /* x >= 2.85711669921875 */
    {
      p = pr3;
      q = ps3;
    } else /* if (ix >= 0x4000) */ /* x better be >= 2 */
    {
      p = pr2;
      q = ps2;
    }
  }
  z = one / (x * x);
  long double temp_var_for_const_0;
  long double temp_var_for_tac_0;
  computeLdMul((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&x},
               "/home/shijia/Public/testprogram/s_ponel.c_e.c:145:11");
  computeLdDiv((Addr)&z, {(Addr) &(temp_var_for_const_0 = one),
                          (Addr)&temp_var_for_tac_0},
               "/home/shijia/Public/testprogram/s_ponel.c_e.c:145:5");
  r = p[0] +
      z * (p[1] + z * (p[2] + z * (p[3] + z * (p[4] + z * (p[5] + z * p[6])))));
  long double temp_var_for_const_1, temp_var_for_const_2, temp_var_for_const_3,
      temp_var_for_const_4, temp_var_for_const_5, temp_var_for_const_6,
      temp_var_for_const_7;
  long double temp_var_for_tac_1, temp_var_for_tac_2, temp_var_for_tac_3,
      temp_var_for_tac_4, temp_var_for_tac_5, temp_var_for_tac_6,
      temp_var_for_tac_7, temp_var_for_tac_8, temp_var_for_tac_9,
      temp_var_for_tac_10, temp_var_for_tac_11;
  computeLdMul((Addr)&temp_var_for_tac_1,
               {(Addr)&z, (Addr) &(temp_var_for_const_1 = p[6])},
               "/home/shijia/Public/testprogram/s_ponel.c_e.c:147:65");
  computeLdAdd(
      (Addr)&temp_var_for_tac_2,
      {(Addr) &(temp_var_for_const_2 = p[5]), (Addr)&temp_var_for_tac_1},
      "/home/shijia/Public/testprogram/s_ponel.c_e.c:147:57");
  computeLdMul((Addr)&temp_var_for_tac_3, {(Addr)&z, (Addr)&temp_var_for_tac_2},
               "/home/shijia/Public/testprogram/s_ponel.c_e.c:147:53");
  computeLdAdd(
      (Addr)&temp_var_for_tac_4,
      {(Addr) &(temp_var_for_const_3 = p[4]), (Addr)&temp_var_for_tac_3},
      "/home/shijia/Public/testprogram/s_ponel.c_e.c:147:45");
  computeLdMul((Addr)&temp_var_for_tac_5, {(Addr)&z, (Addr)&temp_var_for_tac_4},
               "/home/shijia/Public/testprogram/s_ponel.c_e.c:147:41");
  computeLdAdd(
      (Addr)&temp_var_for_tac_6,
      {(Addr) &(temp_var_for_const_4 = p[3]), (Addr)&temp_var_for_tac_5},
      "/home/shijia/Public/testprogram/s_ponel.c_e.c:147:33");
  computeLdMul((Addr)&temp_var_for_tac_7, {(Addr)&z, (Addr)&temp_var_for_tac_6},
               "/home/shijia/Public/testprogram/s_ponel.c_e.c:147:29");
  computeLdAdd(
      (Addr)&temp_var_for_tac_8,
      {(Addr) &(temp_var_for_const_5 = p[2]), (Addr)&temp_var_for_tac_7},
      "/home/shijia/Public/testprogram/s_ponel.c_e.c:147:21");
  computeLdMul((Addr)&temp_var_for_tac_9, {(Addr)&z, (Addr)&temp_var_for_tac_8},
               "/home/shijia/Public/testprogram/s_ponel.c_e.c:147:17");
  computeLdAdd(
      (Addr)&temp_var_for_tac_10,
      {(Addr) &(temp_var_for_const_6 = p[1]), (Addr)&temp_var_for_tac_9},
      "/home/shijia/Public/testprogram/s_ponel.c_e.c:147:9");
  computeLdMul((Addr)&temp_var_for_tac_11,
               {(Addr)&z, (Addr)&temp_var_for_tac_10},
               "/home/shijia/Public/testprogram/s_ponel.c_e.c:146:12");
  computeLdAdd((Addr)&r, {(Addr) &(temp_var_for_const_7 = p[0]),
                          (Addr)&temp_var_for_tac_11},
               "/home/shijia/Public/testprogram/s_ponel.c_e.c:146:5");
  s = q[0] + z * (q[1] + z * (q[2] + z * (q[3] + z * (q[4] + z * (q[5] + z)))));
  long double temp_var_for_const_8, temp_var_for_const_9, temp_var_for_const_10,
      temp_var_for_const_11, temp_var_for_const_12, temp_var_for_const_13;
  long double temp_var_for_tac_12, temp_var_for_tac_13, temp_var_for_tac_14,
      temp_var_for_tac_15, temp_var_for_tac_16, temp_var_for_tac_17,
      temp_var_for_tac_18, temp_var_for_tac_19, temp_var_for_tac_20,
      temp_var_for_tac_21;
  computeLdAdd((Addr)&temp_var_for_tac_12,
               {(Addr) &(temp_var_for_const_8 = q[5]), (Addr)&z},
               "/home/shijia/Public/testprogram/s_ponel.c_e.c:148:64");
  computeLdMul((Addr)&temp_var_for_tac_13,
               {(Addr)&z, (Addr)&temp_var_for_tac_12},
               "/home/shijia/Public/testprogram/s_ponel.c_e.c:148:60");
  computeLdAdd(
      (Addr)&temp_var_for_tac_14,
      {(Addr) &(temp_var_for_const_9 = q[4]), (Addr)&temp_var_for_tac_13},
      "/home/shijia/Public/testprogram/s_ponel.c_e.c:148:52");
  computeLdMul((Addr)&temp_var_for_tac_15,
               {(Addr)&z, (Addr)&temp_var_for_tac_14},
               "/home/shijia/Public/testprogram/s_ponel.c_e.c:148:48");
  computeLdAdd(
      (Addr)&temp_var_for_tac_16,
      {(Addr) &(temp_var_for_const_10 = q[3]), (Addr)&temp_var_for_tac_15},
      "/home/shijia/Public/testprogram/s_ponel.c_e.c:148:40");
  computeLdMul((Addr)&temp_var_for_tac_17,
               {(Addr)&z, (Addr)&temp_var_for_tac_16},
               "/home/shijia/Public/testprogram/s_ponel.c_e.c:148:36");
  computeLdAdd(
      (Addr)&temp_var_for_tac_18,
      {(Addr) &(temp_var_for_const_11 = q[2]), (Addr)&temp_var_for_tac_17},
      "/home/shijia/Public/testprogram/s_ponel.c_e.c:148:28");
  computeLdMul((Addr)&temp_var_for_tac_19,
               {(Addr)&z, (Addr)&temp_var_for_tac_18},
               "/home/shijia/Public/testprogram/s_ponel.c_e.c:148:24");
  computeLdAdd(
      (Addr)&temp_var_for_tac_20,
      {(Addr) &(temp_var_for_const_12 = q[1]), (Addr)&temp_var_for_tac_19},
      "/home/shijia/Public/testprogram/s_ponel.c_e.c:148:16");
  computeLdMul((Addr)&temp_var_for_tac_21,
               {(Addr)&z, (Addr)&temp_var_for_tac_20},
               "/home/shijia/Public/testprogram/s_ponel.c_e.c:148:12");
  computeLdAdd((Addr)&s, {(Addr) &(temp_var_for_const_13 = q[0]),
                          (Addr)&temp_var_for_tac_21},
               "/home/shijia/Public/testprogram/s_ponel.c_e.c:148:5");
  long double temp_var_for_ext_0;
  temp_var_for_ext_0 = one + z * r / s;
  long double temp_var_for_const_14;
  long double temp_var_for_tac_22, temp_var_for_tac_23;
  computeLdMul((Addr)&temp_var_for_tac_22, {(Addr)&z, (Addr)&r},
               "/home/shijia/Public/testprogram/s_ponel.c_e.c:150:36");
  computeLdDiv((Addr)&temp_var_for_tac_23,
               {(Addr)&temp_var_for_tac_22, (Addr)&s},
               "/home/shijia/Public/testprogram/s_ponel.c_e.c:150:28");
  computeLdAdd(
      (Addr)&temp_var_for_ext_0,
      {(Addr) &(temp_var_for_const_14 = one), (Addr)&temp_var_for_tac_23},
      "/home/shijia/Public/testprogram/s_ponel.c_e.c:150:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

long double __j1_y1_qonel(long double x) {
  const long double *p, *q;
  static long double s, r, z;
  int32_t ix;
  uint32_t se, i0, i1;

  static const long double one = 1.0L;

  /* For x >= 8, the asymptotic expansions of qone is
   *	3/8 s - 105/1024 s^3 - ..., where s = 1/x.
   * We approximate qone by
   *	qone(x) = s*(0.375 + (R/S))
   */

  /* Y1(x)cosX - J1(x)sinX = sqrt( 2/(pi x)) Q1(x),
     Q1(x) = z(.375 + z^2 R(z^2)), z=1/x
     8 <= x <= inf
     Peak relative error 8.3e-22 */

  static const long double qr8[7] = {
    (0.0 - 5.691925079044209246015366919809404457380E-10L);
  long double temp_var_for_const_15, temp_var_for_const_16;
  , (0.0 - 1.632587664706999307871963065396218379137E-7L);
  long double temp_var_for_const_17, temp_var_for_const_18;
  long double temp_var_for_tac_24;
  computeLdSub((Addr)&temp_var_for_tac_24,
               {(Addr) &(temp_var_for_const_16 = 0.0),
                (Addr) &(temp_var_for_const_15 =
                             5.691925079044209246015366919809404457380E-10L)},
               "/home/shijia/Public/testprogram/s_ponel.c_e.c:177:12");
  , (0.0 - 1.577424682764651970003637263552027114600E-5L);
  long double temp_var_for_const_19, temp_var_for_const_20;
  long double temp_var_for_tac_25;
  computeLdSub((Addr)&temp_var_for_tac_25,
               {(Addr) &(temp_var_for_const_18 = 0.0),
                (Addr) &(temp_var_for_const_17 =
                             1.632587664706999307871963065396218379137E-7L)},
               "/home/shijia/Public/testprogram/s_ponel.c_e.c:178:12");
  , (0.0 - 6.377627959241053914770158336842725291713E-4L);
  long double temp_var_for_const_21, temp_var_for_const_22;
  long double temp_var_for_tac_26;
  computeLdSub((Addr)&temp_var_for_tac_26,
               {(Addr) &(temp_var_for_const_20 = 0.0),
                (Addr) &(temp_var_for_const_19 =
                             1.577424682764651970003637263552027114600E-5L)},
               "/home/shijia/Public/testprogram/s_ponel.c_e.c:179:12");
  , (0.0 - 1.087408516779972735197277149494929568768E-2L);
  long double temp_var_for_const_23, temp_var_for_const_24;
  long double temp_var_for_tac_27;
  computeLdSub((Addr)&temp_var_for_tac_27,
               {(Addr) &(temp_var_for_const_22 = 0.0),
                (Addr) &(temp_var_for_const_21 =
                             6.377627959241053914770158336842725291713E-4L)},
               "/home/shijia/Public/testprogram/s_ponel.c_e.c:180:12");
  , (0.0 - 6.854943629378084419631926076882330494217E-2L);
  long double temp_var_for_const_25, temp_var_for_const_26;
  long double temp_var_for_tac_28;
  computeLdSub((Addr)&temp_var_for_tac_28,
               {(Addr) &(temp_var_for_const_24 = 0.0),
                (Addr) &(temp_var_for_const_23 =
                             1.087408516779972735197277149494929568768E-2L)},
               "/home/shijia/Public/testprogram/s_ponel.c_e.c:181:12");
  , (0.0 - 1.055448290469180032312893377152490183203E-1L);
  long double temp_var_for_const_27, temp_var_for_const_28;
  long double temp_var_for_tac_29;
  computeLdSub((Addr)&temp_var_for_tac_29,
               {(Addr) &(temp_var_for_const_26 = 0.0),
                (Addr) &(temp_var_for_const_25 =
                             6.854943629378084419631926076882330494217E-2L)},
               "/home/shijia/Public/testprogram/s_ponel.c_e.c:182:12");
};

static const long double qs8[7] = {
    5.550982172325019811119223916998393907513E-9L,
    1.607188366646736068460131091130644192244E-6L,
    1.580792530091386496626494138334505893599E-4L,
    6.617859900815747303032860443855006056595E-3L,
    1.212840547336984859952597488863037659161E-1L,
    9.017885953937234900458186716154005541075E-1L,
    2.201114489712243262000939120146436167178E0L
    /* 1.000000000000000000000000000000000000000E0L, */
};

/* Y1(x)cosX - J1(x)sinX = sqrt( 2/(pi x)) Q1(x),
   Q1(x) = z(.375 + z^2 R(z^2)), z=1/x
   4.54541015625 <= x <= 8
   Peak relative error 4.1e-22 */
static const long double qr5[7] = {
  (0.0 - 6.719134139179190546324213696633564965983E-8L);
long double temp_var_for_const_29, temp_var_for_const_30;
long double temp_var_for_tac_30;
computeLdSub((Addr)&temp_var_for_tac_30,
             {(Addr) &(temp_var_for_const_28 = 0.0),
              (Addr) &(temp_var_for_const_27 =
                           1.055448290469180032312893377152490183203E-1L)},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:200:12");
, (0.0 - 9.467871458774950479909851595678622044140E-6L);
long double temp_var_for_const_31, temp_var_for_const_32;
long double temp_var_for_tac_31;
computeLdSub((Addr)&temp_var_for_tac_31,
             {(Addr) &(temp_var_for_const_30 = 0.0),
              (Addr) &(temp_var_for_const_29 =
                           6.719134139179190546324213696633564965983E-8L)},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:201:12");
, (0.0 - 4.429341875348286176950914275723051452838E-4L);
long double temp_var_for_const_33, temp_var_for_const_34;
long double temp_var_for_tac_32;
computeLdSub((Addr)&temp_var_for_tac_32,
             {(Addr) &(temp_var_for_const_32 = 0.0),
              (Addr) &(temp_var_for_const_31 =
                           9.467871458774950479909851595678622044140E-6L)},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:202:12");
, (0.0 - 8.539898021757342531563866270278505014487E-3L);
long double temp_var_for_const_35, temp_var_for_const_36;
long double temp_var_for_tac_33;
computeLdSub((Addr)&temp_var_for_tac_33,
             {(Addr) &(temp_var_for_const_34 = 0.0),
              (Addr) &(temp_var_for_const_33 =
                           4.429341875348286176950914275723051452838E-4L)},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:203:12");
, (0.0 - 6.818691805848737010422337101409276287170E-2L);
long double temp_var_for_const_37, temp_var_for_const_38;
long double temp_var_for_tac_34;
computeLdSub((Addr)&temp_var_for_tac_34,
             {(Addr) &(temp_var_for_const_36 = 0.0),
              (Addr) &(temp_var_for_const_35 =
                           8.539898021757342531563866270278505014487E-3L)},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:204:12");
, (0.0 - 1.964432669771684034858848142418228214855E-1L);
long double temp_var_for_const_39, temp_var_for_const_40;
long double temp_var_for_tac_35;
computeLdSub((Addr)&temp_var_for_tac_35,
             {(Addr) &(temp_var_for_const_38 = 0.0),
              (Addr) &(temp_var_for_const_37 =
                           6.818691805848737010422337101409276287170E-2L)},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:205:12");
, (0.0 - 1.333896496989238600119596538299938520726E-1L);
long double temp_var_for_const_41, temp_var_for_const_42;
long double temp_var_for_tac_36;
computeLdSub((Addr)&temp_var_for_tac_36,
             {(Addr) &(temp_var_for_const_40 = 0.0),
              (Addr) &(temp_var_for_const_39 =
                           1.964432669771684034858848142418228214855E-1L)},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:206:12");
}
;

static const long double qs5[7] = {
    6.552755584474634766937589285426911075101E-7L,
    9.410814032118155978663509073200494000589E-5L,
    4.561677087286518359461609153655021253238E-3L,
    9.397742096177905170800336715661091535805E-2L,
    8.518538116671013902180962914473967738771E-1L,
    3.177729183645800174212539541058292579009E0L,
    4.006745668510308096259753538973038902990E0L
    /* 1.000000000000000000000000000000000000000E0L, */
};

/* Y1(x)cosX - J1(x)sinX = sqrt( 2/(pi x)) Q1(x),
   Q1(x) = z(.375 + z^2 R(z^2)), z=1/x
   2.85711669921875 <= x <= 4.54541015625
   Peak relative error 2.2e-21 */
static const long double qr3[7] = {
  (0.0 - 3.618746299358445926506719188614570588404E-6L);
long double temp_var_for_const_43, temp_var_for_const_44;
long double temp_var_for_tac_37;
computeLdSub((Addr)&temp_var_for_tac_37,
             {(Addr) &(temp_var_for_const_42 = 0.0),
              (Addr) &(temp_var_for_const_41 =
                           1.333896496989238600119596538299938520726E-1L)},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:224:12");
, (0.0 - 2.951146018465419674063882650970344502798E-4L);
long double temp_var_for_const_45, temp_var_for_const_46;
long double temp_var_for_tac_38;
computeLdSub((Addr)&temp_var_for_tac_38,
             {(Addr) &(temp_var_for_const_44 = 0.0),
              (Addr) &(temp_var_for_const_43 =
                           3.618746299358445926506719188614570588404E-6L)},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:225:12");
, (0.0 - 7.728518171262562194043409753656506795258E-3L);
long double temp_var_for_const_47, temp_var_for_const_48;
long double temp_var_for_tac_39;
computeLdSub((Addr)&temp_var_for_tac_39,
             {(Addr) &(temp_var_for_const_46 = 0.0),
              (Addr) &(temp_var_for_const_45 =
                           2.951146018465419674063882650970344502798E-4L)},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:226:12");
, (0.0 - 8.058010968753999435006488158237984014883E-2L);
long double temp_var_for_const_49, temp_var_for_const_50;
long double temp_var_for_tac_40;
computeLdSub((Addr)&temp_var_for_tac_40,
             {(Addr) &(temp_var_for_const_48 = 0.0),
              (Addr) &(temp_var_for_const_47 =
                           7.728518171262562194043409753656506795258E-3L)},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:227:12");
, (0.0 - 3.356232856677966691703904770937143483472E-1L);
long double temp_var_for_const_51, temp_var_for_const_52;
long double temp_var_for_tac_41;
computeLdSub((Addr)&temp_var_for_tac_41,
             {(Addr) &(temp_var_for_const_50 = 0.0),
              (Addr) &(temp_var_for_const_49 =
                           8.058010968753999435006488158237984014883E-2L)},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:228:12");
, (0.0 - 4.858192581793118040782557808823460276452E-1L);
long double temp_var_for_const_53, temp_var_for_const_54;
long double temp_var_for_tac_42;
computeLdSub((Addr)&temp_var_for_tac_42,
             {(Addr) &(temp_var_for_const_52 = 0.0),
              (Addr) &(temp_var_for_const_51 =
                           3.356232856677966691703904770937143483472E-1L)},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:229:12");
, (0.0 - 1.592399251246473643510898335746432479373E-1L);
long double temp_var_for_const_55, temp_var_for_const_56;
long double temp_var_for_tac_43;
computeLdSub((Addr)&temp_var_for_tac_43,
             {(Addr) &(temp_var_for_const_54 = 0.0),
              (Addr) &(temp_var_for_const_53 =
                           4.858192581793118040782557808823460276452E-1L)},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:230:12");
}
;

static const long double qs3[7] = {
    3.529139957987837084554591421329876744262E-5L,
    2.973602667215766676998703687065066180115E-3L,
    8.273534546240864308494062287908662592100E-2L,
    9.613359842126507198241321110649974032726E-1L,
    4.853923697093974370118387947065402707519E0L,
    1.002671608961669247462020977417828796933E1L,
    7.028927383922483728931327850683151410267E0L
    /* 1.000000000000000000000000000000000000000E0L, */
};

/* Y1(x)cosX - J1(x)sinX = sqrt( 2/(pi x)) Q1(x),
   Q1(x) = z(.375 + z^2 R(z^2)), z=1/x
   2 <= x <= 2.85711669921875
   Peak relative error 6.9e-22 */
static const long double qr2[7] = {
  (0.0 - 1.372751603025230017220666013816502528318E-4L);
long double temp_var_for_const_57, temp_var_for_const_58;
long double temp_var_for_tac_44;
computeLdSub((Addr)&temp_var_for_tac_44,
             {(Addr) &(temp_var_for_const_56 = 0.0),
              (Addr) &(temp_var_for_const_55 =
                           1.592399251246473643510898335746432479373E-1L)},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:248:12");
, (0.0 - 6.879190253347766576229143006767218972834E-3L);
long double temp_var_for_const_59, temp_var_for_const_60;
long double temp_var_for_tac_45;
computeLdSub((Addr)&temp_var_for_tac_45,
             {(Addr) &(temp_var_for_const_58 = 0.0),
              (Addr) &(temp_var_for_const_57 =
                           1.372751603025230017220666013816502528318E-4L)},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:249:12");
, (0.0 - 1.061253572090925414598304855316280077828E-1L);
long double temp_var_for_const_61, temp_var_for_const_62;
long double temp_var_for_tac_46;
computeLdSub((Addr)&temp_var_for_tac_46,
             {(Addr) &(temp_var_for_const_60 = 0.0),
              (Addr) &(temp_var_for_const_59 =
                           6.879190253347766576229143006767218972834E-3L)},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:250:12");
, (0.0 - 6.262164224345471241219408329354943337214E-1L);
long double temp_var_for_const_63, temp_var_for_const_64;
long double temp_var_for_tac_47;
computeLdSub((Addr)&temp_var_for_tac_47,
             {(Addr) &(temp_var_for_const_62 = 0.0),
              (Addr) &(temp_var_for_const_61 =
                           1.061253572090925414598304855316280077828E-1L)},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:251:12");
, (0.0 - 1.423149636514768476376254324731437473915E0L);
long double temp_var_for_const_65, temp_var_for_const_66;
long double temp_var_for_tac_48;
computeLdSub((Addr)&temp_var_for_tac_48,
             {(Addr) &(temp_var_for_const_64 = 0.0),
              (Addr) &(temp_var_for_const_63 =
                           6.262164224345471241219408329354943337214E-1L)},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:252:12");
, (0.0 - 1.087955310491078933531734062917489870754E0L);
long double temp_var_for_const_67, temp_var_for_const_68;
long double temp_var_for_tac_49;
computeLdSub((Addr)&temp_var_for_tac_49,
             {(Addr) &(temp_var_for_const_66 = 0.0),
              (Addr) &(temp_var_for_const_65 =
                           1.423149636514768476376254324731437473915E0L)},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:253:12");
, (0.0 - 1.826821119773182847861406108689273719137E-1L);
long double temp_var_for_const_69, temp_var_for_const_70;
long double temp_var_for_tac_50;
computeLdSub((Addr)&temp_var_for_tac_50,
             {(Addr) &(temp_var_for_const_68 = 0.0),
              (Addr) &(temp_var_for_const_67 =
                           1.087955310491078933531734062917489870754E0L)},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:254:12");
}
;

static const long double qs2[7] = {
    1.338768933634451601814048220627185324007E-3L,
    7.071099998918497559736318523932241901810E-2L,
    1.200511429784048632105295629933382142221E0L,
    8.327301713640367079030141077172031825276E0L,
    2.468479301872299311658145549931764426840E1L,
    2.961179686096262083509383820557051621644E1L,
    1.201402313144305153005639494661767354977E1L
    /* 1.000000000000000000000000000000000000000E0L, */
};

GET_LDOUBLE_WORDS(se, i0, i1, x);
ix = se & 0x7fff;
if (ix >= 0x4002) /* x >= 8 */
{
  p = qr8;
  q = qs8;
} else {
  i1 = (ix << 16) | (i0 >> 16);
  if (i1 >= UC(0x40019174)) /* x >= 4.54541015625 */
  {
    p = qr5;
    q = qs5;
  } else if (i1 >= UC(0x4000b6db)) /* x >= 2.85711669921875 */
  {
    p = qr3;
    q = qs3;
  } else /* if (ix >= 0x4000) */ /* x better be >= 2 */
  {
    p = qr2;
    q = qs2;
  }
}
long double temp_var_for_ext_1;
temp_var_for_ext_1 = one / (x * x);
long double temp_var_for_const_71;
long double temp_var_for_tac_51, temp_var_for_tac_52;
computeLdSub((Addr)&temp_var_for_tac_51,
             {(Addr) &(temp_var_for_const_70 = 0.0),
              (Addr) &(temp_var_for_const_69 =
                           1.826821119773182847861406108689273719137E-1L)},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:290:33");
computeLdMul((Addr)&temp_var_for_tac_52, {(Addr)&x, (Addr)&x},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:290:28");
computeLdDiv((Addr)&temp_var_for_ext_1, {(Addr) &(temp_var_for_const_71 = one),
                                         (Addr)&temp_var_for_tac_52},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:290:22"); // z
/*(z)(q)(5)(q[5])(z)(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(2)(q[2])(z)(q)(1)(q[1])(z)(q)(0)(q[0])(z)(q)(5)(q[5])(z)(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(2)(q[2])(z)(q)(1)(q[1])(z)(z)(q)(5)(q[5])(z)(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(2)(q[2])(z)(q)(1)(q[1])(z)(q)(5)(q[5])(z)(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(2)(q[2])(z)(z)(q)(5)(q[5])(z)(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(2)(q[2])(z)(q)(5)(q[5])(z)(q)(4)(q[4])(z)(q)(3)(q[3])(z)(z)(q)(5)(q[5])(z)(q)(4)(q[4])(z)(q)(3)(q[3])(z)(q)(5)(q[5])(z)(q)(4)(q[4])(z)(z)(q)(5)(q[5])(z)(q)(4)(q[4])(z)(q)(5)(q[5])(z)(z)(q)(5)(q[5])(0)(e)(f)(tem)(0)(e)(f)(e)(f)(x)(x)(one)*/
z = temp_var_for_ext_1;
AssignLd({(Addr)&z}, (Addr)&temp_var_for_ext_1,
         "/home/shijia/Public/testprogram/s_ponel.c_e.c:292:5");
r = p[0] +
    z * (p[1] + z * (p[2] + z * (p[3] + z * (p[4] + z * (p[5] + z * p[6])))));
long double temp_var_for_const_72, temp_var_for_const_73, temp_var_for_const_74,
    temp_var_for_const_75, temp_var_for_const_76, temp_var_for_const_77,
    temp_var_for_const_78;
long double temp_var_for_tac_53, temp_var_for_tac_54, temp_var_for_tac_55,
    temp_var_for_tac_56, temp_var_for_tac_57, temp_var_for_tac_58,
    temp_var_for_tac_59, temp_var_for_tac_60, temp_var_for_tac_61,
    temp_var_for_tac_62, temp_var_for_tac_63;
computeLdMul((Addr)&temp_var_for_tac_53,
             {(Addr)&z, (Addr) &(temp_var_for_const_72 = p[6])},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:294:65");
computeLdAdd((Addr)&temp_var_for_tac_54,
             {(Addr) &(temp_var_for_const_73 = p[5]),
              (Addr)&temp_var_for_tac_53},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:294:57");
computeLdMul((Addr)&temp_var_for_tac_55, {(Addr)&z, (Addr)&temp_var_for_tac_54},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:294:53");
computeLdAdd((Addr)&temp_var_for_tac_56,
             {(Addr) &(temp_var_for_const_74 = p[4]),
              (Addr)&temp_var_for_tac_55},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:294:45");
computeLdMul((Addr)&temp_var_for_tac_57, {(Addr)&z, (Addr)&temp_var_for_tac_56},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:294:41");
computeLdAdd((Addr)&temp_var_for_tac_58,
             {(Addr) &(temp_var_for_const_75 = p[3]),
              (Addr)&temp_var_for_tac_57},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:294:33");
computeLdMul((Addr)&temp_var_for_tac_59, {(Addr)&z, (Addr)&temp_var_for_tac_58},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:294:29");
computeLdAdd((Addr)&temp_var_for_tac_60,
             {(Addr) &(temp_var_for_const_76 = p[2]),
              (Addr)&temp_var_for_tac_59},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:294:21");
computeLdMul((Addr)&temp_var_for_tac_61, {(Addr)&z, (Addr)&temp_var_for_tac_60},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:294:17");
computeLdAdd((Addr)&temp_var_for_tac_62,
             {(Addr) &(temp_var_for_const_77 = p[1]),
              (Addr)&temp_var_for_tac_61},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:294:9");
computeLdMul((Addr)&temp_var_for_tac_63, {(Addr)&z, (Addr)&temp_var_for_tac_62},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:293:12");
computeLdAdd((Addr)&r, {(Addr) &(temp_var_for_const_78 = p[0]),
                        (Addr)&temp_var_for_tac_63},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:293:5");
s = q[0] +
    z * (q[1] +
         z * (q[2] + z * (q[3] + z * (q[4] + z * (q[5] + z * (q[6] + z))))));
long double temp_var_for_const_79, temp_var_for_const_80, temp_var_for_const_81,
    temp_var_for_const_82, temp_var_for_const_83, temp_var_for_const_84,
    temp_var_for_const_85;
long double temp_var_for_tac_64, temp_var_for_tac_65, temp_var_for_tac_66,
    temp_var_for_tac_67, temp_var_for_tac_68, temp_var_for_tac_69,
    temp_var_for_tac_70, temp_var_for_tac_71, temp_var_for_tac_72,
    temp_var_for_tac_73, temp_var_for_tac_74, temp_var_for_tac_75;
computeLdAdd((Addr)&temp_var_for_tac_64,
             {(Addr) &(temp_var_for_const_79 = q[6]), (Addr)&z},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:297:62");
computeLdMul((Addr)&temp_var_for_tac_65, {(Addr)&z, (Addr)&temp_var_for_tac_64},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:297:58");
computeLdAdd((Addr)&temp_var_for_tac_66,
             {(Addr) &(temp_var_for_const_80 = q[5]),
              (Addr)&temp_var_for_tac_65},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:297:50");
computeLdMul((Addr)&temp_var_for_tac_67, {(Addr)&z, (Addr)&temp_var_for_tac_66},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:297:46");
computeLdAdd((Addr)&temp_var_for_tac_68,
             {(Addr) &(temp_var_for_const_81 = q[4]),
              (Addr)&temp_var_for_tac_67},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:297:38");
computeLdMul((Addr)&temp_var_for_tac_69, {(Addr)&z, (Addr)&temp_var_for_tac_68},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:297:34");
computeLdAdd((Addr)&temp_var_for_tac_70,
             {(Addr) &(temp_var_for_const_82 = q[3]),
              (Addr)&temp_var_for_tac_69},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:297:26");
computeLdMul((Addr)&temp_var_for_tac_71, {(Addr)&z, (Addr)&temp_var_for_tac_70},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:297:22");
computeLdAdd((Addr)&temp_var_for_tac_72,
             {(Addr) &(temp_var_for_const_83 = q[2]),
              (Addr)&temp_var_for_tac_71},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:297:14");
computeLdMul((Addr)&temp_var_for_tac_73, {(Addr)&z, (Addr)&temp_var_for_tac_72},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:296:17");
computeLdAdd((Addr)&temp_var_for_tac_74,
             {(Addr) &(temp_var_for_const_84 = q[1]),
              (Addr)&temp_var_for_tac_73},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:296:9");
computeLdMul((Addr)&temp_var_for_tac_75, {(Addr)&z, (Addr)&temp_var_for_tac_74},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:295:12");
computeLdAdd((Addr)&s, {(Addr) &(temp_var_for_const_85 = q[0]),
                        (Addr)&temp_var_for_tac_75},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:295:5");
long double temp_var_for_ext_2;
temp_var_for_ext_2 = (.375 + z * r / s) / x;
long double temp_var_for_const_86;
long double temp_var_for_tac_76, temp_var_for_tac_77, temp_var_for_tac_78;
computeLdMul((Addr)&temp_var_for_tac_76, {(Addr)&z, (Addr)&r},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:299:38");
computeLdDiv((Addr)&temp_var_for_tac_77, {(Addr)&temp_var_for_tac_76, (Addr)&s},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:299:30");
computeLdAdd((Addr)&temp_var_for_tac_78,
             {(Addr) &(temp_var_for_const_86 = .375),
              (Addr)&temp_var_for_tac_77},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:299:43");
computeLdDiv((Addr)&temp_var_for_ext_2, {(Addr)&temp_var_for_tac_78, (Addr)&x},
             "/home/shijia/Public/testprogram/s_ponel.c_e.c:299:22");
callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
callExp++; /*identify the function is  add move tmpShadow*/
return temp_var_for_ext_2;
}

#endif
