#include "../ScDebug/scdebug.h"
/* s_atanf.c -- float version of s_atan.c.
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

#ifndef __have_fpu_atan

float __ieee754_atanf(float x) {
  float w, s1, s2, z;
  int32_t ix, hx, id;

  static const float atanhi[] = {
      4.6364760399e-01, /* atan(0.5)hi 0x3eed6338 */
      7.8539812565e-01, /* atan(1.0)hi 0x3f490fda */
      9.8279368877e-01, /* atan(1.5)hi 0x3f7b985e */
      1.5707962513e+00  /* atan(inf)hi 0x3fc90fda */
  };

  static const float atanlo[] = {
      5.0121582440e-09, /* atan(0.5)lo 0x31ac3769 */
      3.7748947079e-08, /* atan(1.0)lo 0x33222168 */
      3.4473217170e-08, /* atan(1.5)lo 0x33140fb4 */
      7.5497894159e-08  /* atan(inf)lo 0x33a22168 */
  };

  static const float aT[] = {
    3.3333334327e-01, /* 0x3eaaaaaa */
    (0.0 - 2.0000000298e-01);
  double temp_var_for_const_0, temp_var_for_const_1;
  ,                     /* 0xbe4ccccd */
      1.4285714924e-01, /* 0x3e124925 */
      (0.0 - 1.1111110449e-01);
  double temp_var_for_const_2, temp_var_for_const_3;
  double temp_var_for_tac_0;
  computeDSub((Addr)&temp_var_for_tac_0,
              {(Addr) &(temp_var_for_const_1 = 0.0),
               (Addr) &(temp_var_for_const_0 = 2.0000000298e-01)},
              "/home/shijia/Public/testprogram/s_atanf.c_e.c:44:12");
  ,                     /* 0xbde38e38 */
      9.0908870101e-02, /* 0x3dba2e6e */
      (0.0 - 7.6918758452e-02);
  double temp_var_for_const_4, temp_var_for_const_5;
  double temp_var_for_tac_1;
  computeDSub((Addr)&temp_var_for_tac_1,
              {(Addr) &(temp_var_for_const_3 = 0.0),
               (Addr) &(temp_var_for_const_2 = 1.1111110449e-01)},
              "/home/shijia/Public/testprogram/s_atanf.c_e.c:46:12");
  ,                     /* 0xbd9d8795 */
      6.6610731184e-02, /* 0x3d886b35 */
      (0.0 - 5.8335702866e-02);
  double temp_var_for_const_6, temp_var_for_const_7;
  double temp_var_for_tac_2;
  computeDSub((Addr)&temp_var_for_tac_2,
              {(Addr) &(temp_var_for_const_5 = 0.0),
               (Addr) &(temp_var_for_const_4 = 7.6918758452e-02)},
              "/home/shijia/Public/testprogram/s_atanf.c_e.c:48:12");
  ,                     /* 0xbd6ef16b */
      4.9768779427e-02, /* 0x3d4bda59 */
      (0.0 - 3.6531571299e-02);
  double temp_var_for_const_8, temp_var_for_const_9;
  double temp_var_for_tac_3;
  computeDSub((Addr)&temp_var_for_tac_3,
              {(Addr) &(temp_var_for_const_7 = 0.0),
               (Addr) &(temp_var_for_const_6 = 5.8335702866e-02)},
              "/home/shijia/Public/testprogram/s_atanf.c_e.c:50:12");
  ,                    /* 0xbd15a221 */
      1.6285819933e-02 /* 0x3c8569d7 */
};

static const float one = 1.0;
static const float hugeval = 1.0e30;

GET_FLOAT_WORD(hx, x);
ix = hx & IC(0x7fffffff);
if (ix >= IC(0x50800000)) { /* if |x| >= 2^34 */
  if (FLT_UWORD_IS_NAN(ix))
    return x + x; /* NaN */
  if (hx > 0)
    return atanhi[3] + atanlo[3];
  else
    return -atanhi[3] - atanlo[3];
}
if (ix < IC(0x3ee00000)) {   /* |x| < 0.4375 */
  if (ix < IC(0x31000000)) { /* |x| < 2^-29 */
    if (hugeval + x > one)
      return x; /* raise inexact */
  }
  id = -1;
} else {
  x = __ieee754_fabsf(x);
  if (ix < IC(0x3f980000)) {   /* |x| < 1.1875 */
    if (ix < IC(0x3f300000)) { /* 7/16 <=|x|<11/16 */
      id = 0;
      x = ((float)2.0 * x - one) / ((float)2.0 + x);
    } else { /* 11/16<=|x|< 19/16 */
      id = 1;
      x = (x - one) / (x + one);
    }
  } else {
    if (ix < IC(0x401c0000)) { /* |x| < 2.4375 */
      id = 2;
      x = (x - (float)1.5) / (one + (float)1.5 * x);
    } else { /* 2.4375 <= |x| < 2^66 */
      id = 3;
      x = -(float)1.0 / x;
    }
  }
}
/* end of argument reduction */
z = x * x;
float temp_var_for_tac_4;
computeFSub((Addr)&temp_var_for_tac_4,
            {(Addr) &(temp_var_for_const_9 = 0.0),
             (Addr) &(temp_var_for_const_8 = 3.6531571299e-02)},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:94:9");
computeFMul((Addr)&z, {(Addr)&x, (Addr)&x},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:94:5");
w = z * z;
computeFMul((Addr)&w, {(Addr)&z, (Addr)&z},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:95:5");
/* break sum from i=0 to 10 aT[i]z**(i+1) into odd and even poly */
s1 = z * (aT[0] +
          w * (aT[2] + w * (aT[4] + w * (aT[6] + w * (aT[8] + w * aT[10])))));
float temp_var_for_const_10, temp_var_for_const_11, temp_var_for_const_12,
    temp_var_for_const_13, temp_var_for_const_14, temp_var_for_const_15;
float temp_var_for_tac_5, temp_var_for_tac_6, temp_var_for_tac_7,
    temp_var_for_tac_8, temp_var_for_tac_9, temp_var_for_tac_10,
    temp_var_for_tac_11, temp_var_for_tac_12, temp_var_for_tac_13,
    temp_var_for_tac_14;
computeFMul((Addr)&temp_var_for_tac_5,
            {(Addr)&w, (Addr) &(temp_var_for_const_10 = aT[10])},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:98:63");
computeFAdd((Addr)&temp_var_for_tac_6, {(Addr) &(temp_var_for_const_11 = aT[8]),
                                        (Addr)&temp_var_for_tac_5},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:98:54");
computeFMul((Addr)&temp_var_for_tac_7, {(Addr)&w, (Addr)&temp_var_for_tac_6},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:98:50");
computeFAdd((Addr)&temp_var_for_tac_8, {(Addr) &(temp_var_for_const_12 = aT[6]),
                                        (Addr)&temp_var_for_tac_7},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:98:41");
computeFMul((Addr)&temp_var_for_tac_9, {(Addr)&w, (Addr)&temp_var_for_tac_8},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:98:37");
computeFAdd((Addr)&temp_var_for_tac_10,
            {(Addr) &(temp_var_for_const_13 = aT[4]),
             (Addr)&temp_var_for_tac_9},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:98:28");
computeFMul((Addr)&temp_var_for_tac_11, {(Addr)&w, (Addr)&temp_var_for_tac_10},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:98:24");
computeFAdd((Addr)&temp_var_for_tac_12,
            {(Addr) &(temp_var_for_const_14 = aT[2]),
             (Addr)&temp_var_for_tac_11},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:98:15");
computeFMul((Addr)&temp_var_for_tac_13, {(Addr)&w, (Addr)&temp_var_for_tac_12},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:97:19");
computeFAdd((Addr)&temp_var_for_tac_14,
            {(Addr) &(temp_var_for_const_15 = aT[0]),
             (Addr)&temp_var_for_tac_13},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:97:10");
computeFMul((Addr)&s1, {(Addr)&z, (Addr)&temp_var_for_tac_14},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:97:6");
s2 = w * (aT[1] + w * (aT[3] + w * (aT[5] + w * (aT[7] + w * aT[9]))));
float temp_var_for_const_16, temp_var_for_const_17, temp_var_for_const_18,
    temp_var_for_const_19, temp_var_for_const_20;
float temp_var_for_tac_15, temp_var_for_tac_16, temp_var_for_tac_17,
    temp_var_for_tac_18, temp_var_for_tac_19, temp_var_for_tac_20,
    temp_var_for_tac_21, temp_var_for_tac_22;
computeFMul((Addr)&temp_var_for_tac_15,
            {(Addr)&w, (Addr) &(temp_var_for_const_16 = aT[9])},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:99:58");
computeFAdd((Addr)&temp_var_for_tac_16,
            {(Addr) &(temp_var_for_const_17 = aT[7]),
             (Addr)&temp_var_for_tac_15},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:99:49");
computeFMul((Addr)&temp_var_for_tac_17, {(Addr)&w, (Addr)&temp_var_for_tac_16},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:99:45");
computeFAdd((Addr)&temp_var_for_tac_18,
            {(Addr) &(temp_var_for_const_18 = aT[5]),
             (Addr)&temp_var_for_tac_17},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:99:36");
computeFMul((Addr)&temp_var_for_tac_19, {(Addr)&w, (Addr)&temp_var_for_tac_18},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:99:32");
computeFAdd((Addr)&temp_var_for_tac_20,
            {(Addr) &(temp_var_for_const_19 = aT[3]),
             (Addr)&temp_var_for_tac_19},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:99:23");
computeFMul((Addr)&temp_var_for_tac_21, {(Addr)&w, (Addr)&temp_var_for_tac_20},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:99:19");
computeFAdd((Addr)&temp_var_for_tac_22,
            {(Addr) &(temp_var_for_const_20 = aT[1]),
             (Addr)&temp_var_for_tac_21},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:99:10");
computeFMul((Addr)&s2, {(Addr)&w, (Addr)&temp_var_for_tac_22},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:99:6");
if (id < 0)
  return x - x * (s1 + s2);
else {
  z = atanhi[id] - ((x * (s1 + s2) - atanlo[id]) - x);
  return (hx < 0) ? -z : z;
}
}

#endif

float __atanf(float x) {
  float temp_var_for_ext_0;
  temp_var_for_ext_0 = __ieee754_atanf(x);
  float temp_var_for_callexp_0 =
      __ieee754_atanf(getFVbyShadow<float>((Addr)&x));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_callexp_0,
          "/home/shijia/Public/testprogram/s_atanf.c_e.c:112:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

__typeof(__atanf) atanf __attribute__((weak, alias("__atanf")));
