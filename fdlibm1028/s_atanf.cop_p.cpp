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
      3.3333334327e-01,         /* 0x3eaaaaaa */
      (double temp_var_for_tac_0;
  double temp_var_for_const_0, temp_var_for_const_1;
  temp_var_for_tac_0 = 0.0 - 2.0000000298e-01;

), /* 0xbe4ccccd */
      1.4285714924e-01,         /* 0x3e124925 */
      (double temp_var_for_tac_1;double temp_var_for_const_2,temp_var_for_const_3;temp_var_for_tac_1 = 0.0 - 1.1111110449e-01;

), /* 0xbde38e38 */
      9.0908870101e-02,         /* 0x3dba2e6e */
      (double temp_var_for_tac_2;double temp_var_for_const_4,temp_var_for_const_5;temp_var_for_tac_2 = 0.0 - 7.6918758452e-02;

), /* 0xbd9d8795 */
      6.6610731184e-02,         /* 0x3d886b35 */
      (double temp_var_for_tac_3;double temp_var_for_const_6,temp_var_for_const_7;temp_var_for_tac_3 = 0.0 - 5.8335702866e-02;

), /* 0xbd6ef16b */
      4.9768779427e-02,         /* 0x3d4bda59 */
      (double temp_var_for_tac_4;double temp_var_for_const_8,temp_var_for_const_9;temp_var_for_tac_4 = 0.0 - 3.6531571299e-02;

), /* 0xbd15a221 */
      1.6285819933e-02          /* 0x3c8569d7 */
};

static const float one = 1.0;
static const float hugeval = 1.0e30;

GET_FLOAT_WORD(hx, x);
ix = hx & IC(0x7fffffff);
if (ix >= IC(0x50800000)) { /* if |x| >= 2^34 */
  if (FLT_UWORD_IS_NAN(ix)) {
    float temp_var_for_ext_0;
    float temp_var_for_tac_5;
    temp_var_for_tac_5 = x + x;

    temp_var_for_ext_0 = temp_var_for_tac_5;
    computeDSub((Addr)&temp_var_for_tac_0,
                {(Addr) &(temp_var_for_const_1 = 0.0),
                 (Addr) &(temp_var_for_const_0 = 2.0000000298e-01)},
                "/home/shijia/Public/testprogram/s_atanf.c_e.c:42:12");
    computeDSub((Addr)&temp_var_for_tac_1,
                {(Addr) &(temp_var_for_const_3 = 0.0),
                 (Addr) &(temp_var_for_const_2 = 1.1111110449e-01)},
                "/home/shijia/Public/testprogram/s_atanf.c_e.c:44:12");
    computeDSub((Addr)&temp_var_for_tac_2,
                {(Addr) &(temp_var_for_const_5 = 0.0),
                 (Addr) &(temp_var_for_const_4 = 7.6918758452e-02)},
                "/home/shijia/Public/testprogram/s_atanf.c_e.c:46:12");
    computeDSub((Addr)&temp_var_for_tac_3,
                {(Addr) &(temp_var_for_const_7 = 0.0),
                 (Addr) &(temp_var_for_const_6 = 5.8335702866e-02)},
                "/home/shijia/Public/testprogram/s_atanf.c_e.c:48:12");
    computeDSub((Addr)&temp_var_for_tac_4,
                {(Addr) &(temp_var_for_const_9 = 0.0),
                 (Addr) &(temp_var_for_const_8 = 3.6531571299e-02)},
                "/home/shijia/Public/testprogram/s_atanf.c_e.c:50:12");
    computeFAdd((Addr)&temp_var_for_tac_5, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/s_atanf.c_e.c:62:30");
    AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_5,
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:62:26");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }
  /* NaN */
  if (hx > 0) {
    float temp_var_for_ext_1;
    float temp_var_for_tac_6;
    float temp_var_for_const_10, temp_var_for_const_11;
    temp_var_for_tac_6 = atanhi[3] + atanlo[3];

    temp_var_for_ext_1 = temp_var_for_tac_6;
    computeFAdd((Addr)&temp_var_for_tac_6,
                {(Addr) &(temp_var_for_const_11 = atanhi[3]),
                 (Addr) &(temp_var_for_const_10 = atanlo[3])},
                "/home/shijia/Public/testprogram/s_atanf.c_e.c:71:38");
    AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_6,
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:71:26");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }

  else {
    float temp_var_for_ext_2;
    float temp_var_for_tac_7;
    float temp_var_for_const_12, temp_var_for_const_13;
    temp_var_for_tac_7 = (-(atanhi[3])) - atanlo[3];

    temp_var_for_ext_2 = temp_var_for_tac_7;
    computeFSub((Addr)&temp_var_for_tac_7,
                {(Addr) &(temp_var_for_const_13 = (-(atanhi[3]))),
                 (Addr) &(temp_var_for_const_12 = atanlo[3])},
                "/home/shijia/Public/testprogram/s_atanf.c_e.c:80:39");
    AssignF({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_7,
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:80:26");
    ;
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return (0.0 - rn temp_v)ar_for_ext_2;
  }
}
if (ix < IC(0x3ee00000)) {   /* |x| < 0.4375 */
  if (ix < IC(0x31000000)) { /* |x| < 2^-29 */
    if (int temp_var_for_tac_8, temp_var_for_tac_9;
        int temp_var_for_const_14, temp_var_for_const_15;
        temp_var_for_tac_8 = hugeval + x;

        temp_var_for_tac_9 = temp_var_for_tac_8 > one;

        ) {
      float temp_var_for_ext_3;
      temp_var_for_ext_3 = x;
      computeFAdd((Addr)&temp_var_for_tac_8,
                  {(Addr) &(temp_var_for_const_14 = hugeval), (Addr)&x},
                  "/home/shijia/Public/testprogram/s_atanf.c_e.c:89:19");
      compute(
          (Addr)&temp_var_for_tac_9,
          {(Addr)&temp_var_for_tac_8, (Addr) &(temp_var_for_const_15 = one)},
          "/home/shijia/Public/testprogram/s_atanf.c_e.c:89:23");
      AssignF({(Addr)&temp_var_for_ext_3}, (Addr)&x,
              "/home/shijia/Public/testprogram/s_atanf.c_e.c:91:28");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_3;
    }
    /* raise inexact */
  }
  id = -1;
} else {
  float temp_var_for_ext_4;
  float temp_var_for_const_16;
  float temp_var_for_callexp_0;

  temp_var_for_callexp_0 = fabsf(x);
  temp_var_for_ext_4 = temp_var_for_callexp_0;
  AssignF({(Addr)&temp_var_for_ext_4},
          (Addr) &(temp_var_for_const_16 = temp_var_for_callexp_0),
          "/home/shijia/Public/testprogram/s_atanf.c_e.c:102:24");
  ; // x
  /*(0)(t)(for_ex)(_)(for_ex[_])(temp_v)(_)(temp_v[_])(for_ex)(_)(for_ex[_])(rn
   * tem)(_)(rn tem[_])(rn tem[_])(x)(hugeval)(__ieee754_fabsf(x))*/
  x = temp_var_for_ext_4;
  AssignF({(Addr)&x}, (Addr)&temp_var_for_ext_4,
          "/home/shijia/Public/testprogram/s_atanf.c_e.c:105:7");
  ;
  if (ix < IC(0x3f980000)) {   /* |x| < 1.1875 */
    if (ix < IC(0x3f300000)) { /* 7/16 <=|x|<11/16 */
      id = 0;
      float temp_var_for_ext_5;
      float temp_var_for_tac_10, temp_var_for_tac_11, temp_var_for_tac_12,
          temp_var_for_tac_13;
      float temp_var_for_const_17, temp_var_for_const_18, temp_var_for_const_19;
      temp_var_for_tac_10 = ((float)2.0) * x;

      temp_var_for_tac_11 = temp_var_for_tac_10 - one;

      temp_var_for_tac_12 = ((float)2.0) + x;

      temp_var_for_tac_13 = temp_var_for_tac_11 / temp_var_for_tac_12;

      temp_var_for_ext_5 = temp_var_for_tac_13;
      computeFMul((Addr)&temp_var_for_tac_10,
                  {(Addr) &(temp_var_for_const_17 = ((float)2.0)), (Addr)&x},
                  "/home/shijia/Public/testprogram/s_atanf.c_e.c:110:42");
      computeFSub(
          (Addr)&temp_var_for_tac_11,
          {(Addr)&temp_var_for_tac_10, (Addr) &(temp_var_for_const_18 = one)},
          "/home/shijia/Public/testprogram/s_atanf.c_e.c:110:46");
      computeFAdd((Addr)&temp_var_for_tac_12,
                  {(Addr) &(temp_var_for_const_19 = ((float)2.0)), (Addr)&x},
                  "/home/shijia/Public/testprogram/s_atanf.c_e.c:110:67");
      computeFDiv((Addr)&temp_var_for_tac_13,
                  {(Addr)&temp_var_for_tac_11, (Addr)&temp_var_for_tac_12},
                  "/home/shijia/Public/testprogram/s_atanf.c_e.c:110:53");
      AssignF({(Addr)&temp_var_for_ext_5}, (Addr)&temp_var_for_tac_13,
              "/home/shijia/Public/testprogram/s_atanf.c_e.c:110:28");
      ; // x
      /*(x)(2.0)(2.0)(one)(x)(2.0)(2.0)*/
      x = temp_var_for_ext_5;
      AssignF({(Addr)&x}, (Addr)&temp_var_for_ext_5,
              "/home/shijia/Public/testprogram/s_atanf.c_e.c:112:11");
      ;
    } else { /* 11/16<=|x|< 19/16 */
      id = 1;
      float temp_var_for_ext_6;
      float temp_var_for_tac_14, temp_var_for_tac_15, temp_var_for_tac_16;
      float temp_var_for_const_20, temp_var_for_const_21;
      temp_var_for_tac_14 = x - one;

      temp_var_for_tac_15 = x + one;

      temp_var_for_tac_16 = temp_var_for_tac_14 / temp_var_for_tac_15;

      temp_var_for_ext_6 = temp_var_for_tac_16;
      computeFSub((Addr)&temp_var_for_tac_14,
                  {(Addr)&x, (Addr) &(temp_var_for_const_20 = one)},
                  "/home/shijia/Public/testprogram/s_atanf.c_e.c:116:33");
      computeFAdd((Addr)&temp_var_for_tac_15,
                  {(Addr)&x, (Addr) &(temp_var_for_const_21 = one)},
                  "/home/shijia/Public/testprogram/s_atanf.c_e.c:116:45");
      computeFDiv((Addr)&temp_var_for_tac_16,
                  {(Addr)&temp_var_for_tac_14, (Addr)&temp_var_for_tac_15},
                  "/home/shijia/Public/testprogram/s_atanf.c_e.c:116:40");
      AssignF({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_16,
              "/home/shijia/Public/testprogram/s_atanf.c_e.c:116:28");
      ; // x
      /*(x)(2.0)(2.0)(one)(x)(2.0)(2.0)(one)(x)(2.0)(2.0)(x)(2.0)(2.0)(x)(2.0)(2.0)(one)(x)(one)(x)*/
      x = temp_var_for_ext_6;
      AssignF({(Addr)&x}, (Addr)&temp_var_for_ext_6,
              "/home/shijia/Public/testprogram/s_atanf.c_e.c:118:11");
      ;
    }
  } else {
    if (ix < IC(0x401c0000)) { /* |x| < 2.4375 */
      id = 2;
      float temp_var_for_ext_7;
      float temp_var_for_tac_17, temp_var_for_tac_18, temp_var_for_tac_19,
          temp_var_for_tac_20;
      float temp_var_for_const_22, temp_var_for_const_23, temp_var_for_const_24;
      temp_var_for_tac_17 = x - ((float)1.5);

      temp_var_for_tac_18 = ((float)1.5) * x;

      temp_var_for_tac_19 = one + temp_var_for_tac_18;

      temp_var_for_tac_20 = temp_var_for_tac_17 / temp_var_for_tac_19;

      temp_var_for_ext_7 = temp_var_for_tac_20;
      computeFSub((Addr)&temp_var_for_tac_17,
                  {(Addr)&x, (Addr) &(temp_var_for_const_22 = ((float)1.5))},
                  "/home/shijia/Public/testprogram/s_atanf.c_e.c:124:33");
      computeFMul((Addr)&temp_var_for_tac_18,
                  {(Addr) &(temp_var_for_const_23 = ((float)1.5)), (Addr)&x},
                  "/home/shijia/Public/testprogram/s_atanf.c_e.c:124:67");
      computeFAdd(
          (Addr)&temp_var_for_tac_19,
          {(Addr) &(temp_var_for_const_24 = one), (Addr)&temp_var_for_tac_18},
          "/home/shijia/Public/testprogram/s_atanf.c_e.c:124:54");
      computeFDiv((Addr)&temp_var_for_tac_20,
                  {(Addr)&temp_var_for_tac_17, (Addr)&temp_var_for_tac_19},
                  "/home/shijia/Public/testprogram/s_atanf.c_e.c:124:47");
      AssignF({(Addr)&temp_var_for_ext_7}, (Addr)&temp_var_for_tac_20,
              "/home/shijia/Public/testprogram/s_atanf.c_e.c:124:28");
      ; // x
      /*(one)(x)(one)(x)(one)(x)(one)(x)(x)(1.5)(1.5)(one)(1.5)(1.5)(x)*/
      x = temp_var_for_ext_7;
      AssignF({(Addr)&x}, (Addr)&temp_var_for_ext_7,
              "/home/shijia/Public/testprogram/s_atanf.c_e.c:126:11");
      ;
    } else { /* 2.4375 <= |x| < 2^66 */
      id = 3;
      float temp_var_for_ext_8;
      float temp_var_for_tac_21, temp_var_for_tac_22;
      float temp_var_for_const_25, temp_var_for_const_26;
      temp_var_for_tac_21 = 0.0 - ((float)1.0);

      temp_var_for_tac_22 = temp_var_for_tac_21 / x;

      temp_var_for_ext_8 = temp_var_for_tac_22;
      computeDSub((Addr)&temp_var_for_tac_21,
                  {(Addr) &(temp_var_for_const_26 = 0.0),
                   (Addr) &(temp_var_for_const_25 = ((float)1.0))},
                  "/home/shijia/Public/testprogram/s_atanf.c_e.c:130:35");
      computeDDiv((Addr)&temp_var_for_tac_22,
                  {(Addr)&temp_var_for_tac_21, (Addr)&x},
                  "/home/shijia/Public/testprogram/s_atanf.c_e.c:130:49");
      AssignF({(Addr)&temp_var_for_ext_8}, (Addr)&temp_var_for_tac_22,
              "/home/shijia/Public/testprogram/s_atanf.c_e.c:130:28");
      ; // x
      /*(x)(1.5)(1.5)(one)(1.5)(1.5)(x)(1.5)(1.5)(x)(x)(1.5)(1.5)(one)(x)(1.5)(1.5)(x)(1.0)(1.0)(((float)1.0))*/
      x = temp_var_for_ext_8;
      AssignF({(Addr)&x}, (Addr)&temp_var_for_ext_8,
              "/home/shijia/Public/testprogram/s_atanf.c_e.c:132:11");
      ;
    }
  }
}
/* end of argument reduction */
float temp_var_for_tac_23;
temp_var_for_tac_23 = x * x;

z = temp_var_for_tac_23;
computeFMul((Addr)&temp_var_for_tac_23, {(Addr)&x, (Addr)&x},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:137:9");
AssignF({(Addr)&z}, (Addr)&temp_var_for_tac_23,
        "/home/shijia/Public/testprogram/s_atanf.c_e.c:137:5");
;
float temp_var_for_tac_24;
temp_var_for_tac_24 = z * z;

w = temp_var_for_tac_24;
computeFMul((Addr)&temp_var_for_tac_24, {(Addr)&z, (Addr)&z},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:138:9");
AssignF({(Addr)&w}, (Addr)&temp_var_for_tac_24,
        "/home/shijia/Public/testprogram/s_atanf.c_e.c:138:5");
;
/* break sum from i=0 to 10 aT[i]z**(i+1) into odd and even poly */
float temp_var_for_tac_25, temp_var_for_tac_26, temp_var_for_tac_27,
    temp_var_for_tac_28, temp_var_for_tac_29, temp_var_for_tac_30,
    temp_var_for_tac_31, temp_var_for_tac_32, temp_var_for_tac_33,
    temp_var_for_tac_34, temp_var_for_tac_35;
float temp_var_for_const_27, temp_var_for_const_28, temp_var_for_const_29,
    temp_var_for_const_30, temp_var_for_const_31, temp_var_for_const_32;
temp_var_for_tac_25 = w * aT[10];

temp_var_for_tac_26 = aT[8] + temp_var_for_tac_25;

temp_var_for_tac_27 = w * temp_var_for_tac_26;

temp_var_for_tac_28 = aT[6] + temp_var_for_tac_27;

temp_var_for_tac_29 = w * temp_var_for_tac_28;

temp_var_for_tac_30 = aT[4] + temp_var_for_tac_29;

temp_var_for_tac_31 = w * temp_var_for_tac_30;

temp_var_for_tac_32 = aT[2] + temp_var_for_tac_31;

temp_var_for_tac_33 = w * temp_var_for_tac_32;

temp_var_for_tac_34 = aT[0] + temp_var_for_tac_33;

temp_var_for_tac_35 = z * temp_var_for_tac_34;

s1 = temp_var_for_tac_35;
computeFMul((Addr)&temp_var_for_tac_25,
            {(Addr)&w, (Addr) &(temp_var_for_const_27 = aT[10])},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:141:67");
computeFAdd((Addr)&temp_var_for_tac_26,
            {(Addr) &(temp_var_for_const_28 = aT[8]),
             (Addr)&temp_var_for_tac_25},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:141:63");
computeFMul((Addr)&temp_var_for_tac_27, {(Addr)&w, (Addr)&temp_var_for_tac_26},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:141:54");
computeFAdd((Addr)&temp_var_for_tac_28,
            {(Addr) &(temp_var_for_const_29 = aT[6]),
             (Addr)&temp_var_for_tac_27},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:141:50");
computeFMul((Addr)&temp_var_for_tac_29, {(Addr)&w, (Addr)&temp_var_for_tac_28},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:141:41");
computeFAdd((Addr)&temp_var_for_tac_30,
            {(Addr) &(temp_var_for_const_30 = aT[4]),
             (Addr)&temp_var_for_tac_29},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:141:37");
computeFMul((Addr)&temp_var_for_tac_31, {(Addr)&w, (Addr)&temp_var_for_tac_30},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:141:28");
computeFAdd((Addr)&temp_var_for_tac_32,
            {(Addr) &(temp_var_for_const_31 = aT[2]),
             (Addr)&temp_var_for_tac_31},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:141:24");
computeFMul((Addr)&temp_var_for_tac_33, {(Addr)&w, (Addr)&temp_var_for_tac_32},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:141:15");
computeFAdd((Addr)&temp_var_for_tac_34,
            {(Addr) &(temp_var_for_const_32 = aT[0]),
             (Addr)&temp_var_for_tac_33},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:140:19");
computeFMul((Addr)&temp_var_for_tac_35, {(Addr)&z, (Addr)&temp_var_for_tac_34},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:140:10");
AssignF({(Addr)&s1}, (Addr)&temp_var_for_tac_35,
        "/home/shijia/Public/testprogram/s_atanf.c_e.c:140:6");
;
float temp_var_for_tac_36, temp_var_for_tac_37, temp_var_for_tac_38,
    temp_var_for_tac_39, temp_var_for_tac_40, temp_var_for_tac_41,
    temp_var_for_tac_42, temp_var_for_tac_43, temp_var_for_tac_44;
float temp_var_for_const_33, temp_var_for_const_34, temp_var_for_const_35,
    temp_var_for_const_36, temp_var_for_const_37;
temp_var_for_tac_36 = w * aT[9];

temp_var_for_tac_37 = aT[7] + temp_var_for_tac_36;

temp_var_for_tac_38 = w * temp_var_for_tac_37;

temp_var_for_tac_39 = aT[5] + temp_var_for_tac_38;

temp_var_for_tac_40 = w * temp_var_for_tac_39;

temp_var_for_tac_41 = aT[3] + temp_var_for_tac_40;

temp_var_for_tac_42 = w * temp_var_for_tac_41;

temp_var_for_tac_43 = aT[1] + temp_var_for_tac_42;

temp_var_for_tac_44 = w * temp_var_for_tac_43;

s2 = temp_var_for_tac_44;
computeFMul((Addr)&temp_var_for_tac_36,
            {(Addr)&w, (Addr) &(temp_var_for_const_33 = aT[9])},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:142:62");
computeFAdd((Addr)&temp_var_for_tac_37,
            {(Addr) &(temp_var_for_const_34 = aT[7]),
             (Addr)&temp_var_for_tac_36},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:142:58");
computeFMul((Addr)&temp_var_for_tac_38, {(Addr)&w, (Addr)&temp_var_for_tac_37},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:142:49");
computeFAdd((Addr)&temp_var_for_tac_39,
            {(Addr) &(temp_var_for_const_35 = aT[5]),
             (Addr)&temp_var_for_tac_38},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:142:45");
computeFMul((Addr)&temp_var_for_tac_40, {(Addr)&w, (Addr)&temp_var_for_tac_39},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:142:36");
computeFAdd((Addr)&temp_var_for_tac_41,
            {(Addr) &(temp_var_for_const_36 = aT[3]),
             (Addr)&temp_var_for_tac_40},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:142:32");
computeFMul((Addr)&temp_var_for_tac_42, {(Addr)&w, (Addr)&temp_var_for_tac_41},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:142:23");
computeFAdd((Addr)&temp_var_for_tac_43,
            {(Addr) &(temp_var_for_const_37 = aT[1]),
             (Addr)&temp_var_for_tac_42},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:142:19");
computeFMul((Addr)&temp_var_for_tac_44, {(Addr)&w, (Addr)&temp_var_for_tac_43},
            "/home/shijia/Public/testprogram/s_atanf.c_e.c:142:10");
AssignF({(Addr)&s2}, (Addr)&temp_var_for_tac_44,
        "/home/shijia/Public/testprogram/s_atanf.c_e.c:142:6");
;
if (id < 0) {
  float temp_var_for_ext_9;
  float temp_var_for_tac_45, temp_var_for_tac_46, temp_var_for_tac_47;
  temp_var_for_tac_45 = s1 + s2;

  temp_var_for_tac_46 = x * temp_var_for_tac_45;

  temp_var_for_tac_47 = x - temp_var_for_tac_46;

  temp_var_for_ext_9 = temp_var_for_tac_47;
  computeFAdd((Addr)&temp_var_for_tac_45, {(Addr)&s1, (Addr)&s2},
              "/home/shijia/Public/testprogram/s_atanf.c_e.c:145:38");
  computeFMul((Addr)&temp_var_for_tac_46,
              {(Addr)&x, (Addr)&temp_var_for_tac_45},
              "/home/shijia/Public/testprogram/s_atanf.c_e.c:145:32");
  computeFSub((Addr)&temp_var_for_tac_47,
              {(Addr)&x, (Addr)&temp_var_for_tac_46},
              "/home/shijia/Public/testprogram/s_atanf.c_e.c:145:28");
  AssignF({(Addr)&temp_var_for_ext_9}, (Addr)&temp_var_for_tac_47,
          "/home/shijia/Public/testprogram/s_atanf.c_e.c:145:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_9;
}

else {
  float temp_var_for_tac_48, temp_var_for_tac_49, temp_var_for_tac_50,
      temp_var_for_tac_51, temp_var_for_tac_52;
  float temp_var_for_const_38, temp_var_for_const_39;
  temp_var_for_tac_48 = s1 + s2;

  temp_var_for_tac_49 = x * temp_var_for_tac_48;

  temp_var_for_tac_50 = temp_var_for_tac_49 - atanlo[id];

  temp_var_for_tac_51 = temp_var_for_tac_50 - x;

  temp_var_for_tac_52 = atanhi[id] - temp_var_for_tac_51;

  z = temp_var_for_tac_52;
  computeFAdd((Addr)&temp_var_for_tac_48, {(Addr)&s1, (Addr)&s2},
              "/home/shijia/Public/testprogram/s_atanf.c_e.c:152:32");
  computeFMul((Addr)&temp_var_for_tac_49,
              {(Addr)&x, (Addr)&temp_var_for_tac_48},
              "/home/shijia/Public/testprogram/s_atanf.c_e.c:152:26");
  computeFSub((Addr)&temp_var_for_tac_50,
              {(Addr)&temp_var_for_tac_49,
               (Addr) &(temp_var_for_const_38 = atanlo[id])},
              "/home/shijia/Public/testprogram/s_atanf.c_e.c:152:38");
  computeFSub((Addr)&temp_var_for_tac_51,
              {(Addr)&temp_var_for_tac_50, (Addr)&x},
              "/home/shijia/Public/testprogram/s_atanf.c_e.c:152:52");
  computeFSub((Addr)&temp_var_for_tac_52,
              {(Addr) &(temp_var_for_const_39 = atanhi[id]),
               (Addr)&temp_var_for_tac_51},
              "/home/shijia/Public/testprogram/s_atanf.c_e.c:152:20");
  AssignF({(Addr)&z}, (Addr)&temp_var_for_tac_52,
          "/home/shijia/Public/testprogram/s_atanf.c_e.c:152:7");
  ;
  float temp_var_for_ext_10;
  float temp_var_for_const_40;
  temp_var_for_ext_10 = (hx < 0) ? -z : z;
  AssignF({(Addr)&temp_var_for_ext_10},
          (Addr) &(temp_var_for_const_40 = (hx < 0) ? -z : z),
          "/home/shijia/Public/testprogram/s_atanf.c_e.c:154:25");
  ;
  callExpStack.push(getReal("temp_var_for_ext_10", (Addr)&temp_var_for_ext_10));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_(0.0 - x) t_10;
}
}

#endif

float __atanf(float x) {
  float temp_var_for_ext_11;
  temp_var_for_ext_11 = __ieee754_atanf(x);
  callExpStack.push(getReal("temp_var_for_ext_11", (Addr)&temp_var_for_ext_11));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_11;
}

__typeof(__atanf) atanf __attribute__((weak, alias("__atanf")));
