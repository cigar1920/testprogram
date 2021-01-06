#include "../ScDebug/scdebug.h"
/* k_rem_pio2f.c -- float version of k_rem_pio2.c
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

int32_t __kernel_rem_pio2f(float *x, float *y, int32_t e0, int32_t nx,
                           int prec) {
  int32_t jz, jx, jv, jp, jk, carry, n, iq[20], i, j, k, m, q0, ih;
  float z, fw, f[20], fq[20], q[20];

  /* In the float version, the input parameter x contains 8 bit
     integers, not 24 bit integers.  113 bit precision is not supported.  */

  static int const init_jk[] = {4, 7, 9}; /* initial value for jk */

  static float const PIo2[] = {
      1.5703125000e+00, /* 0x3fc90000 */
      4.5776367188e-04, /* 0x39f00000 */
      2.5987625122e-05, /* 0x37da0000 */
      7.5437128544e-08, /* 0x33a20000 */
      6.0026650317e-11, /* 0x2e840000 */
      7.3896444519e-13, /* 0x2b500000 */
      5.3845816694e-15, /* 0x27c20000 */
      5.6378512969e-18, /* 0x22d00000 */
      8.3009228831e-20, /* 0x1fc40000 */
      3.2756352257e-22, /* 0x1bc60000 */
      6.3331015649e-25  /* 0x17440000 */
  };

  static float const zero = 0.0;
  static float const one = 1.0;
  static float const two8 = 2.5600000000e+02;  /* 0x43800000 */
  static float const twon8 = 3.9062500000e-03; /* 0x3b800000 */

  /*
   * Table of constants for 2/pi, 396 Hex digits (476 decimal) of 2/pi
   */
  static int32_t const two_over_pi[] = {
      0xA2, 0xF9, 0x83, 0x6E, 0x4E, 0x44, 0x15, 0x29, 0xFC, 0x27, 0x57, 0xD1,
      0xF5, 0x34, 0xDD, 0xC0, 0xDB, 0x62, 0x95, 0x99, 0x3C, 0x43, 0x90, 0x41,
      0xFE, 0x51, 0x63, 0xAB, 0xDE, 0xBB, 0xC5, 0x61, 0xB7, 0x24, 0x6E, 0x3A,
      0x42, 0x4D, 0xD2, 0xE0, 0x06, 0x49, 0x2E, 0xEA, 0x09, 0xD1, 0x92, 0x1C,
      0xFE, 0x1D, 0xEB, 0x1C, 0xB1, 0x29, 0xA7, 0x3E, 0xE8, 0x82, 0x35, 0xF5,
      0x2E, 0xBB, 0x44, 0x84, 0xE9, 0x9C, 0x70, 0x26, 0xB4, 0x5F, 0x7E, 0x41,
      0x39, 0x91, 0xD6, 0x39, 0x83, 0x53, 0x39, 0xF4, 0x9C, 0x84, 0x5F, 0x8B,
      0xBD, 0xF9, 0x28, 0x3B, 0x1F, 0xF8, 0x97, 0xFF, 0xDE, 0x05, 0x98, 0x0F,
      0xEF, 0x2F, 0x11, 0x8B, 0x5A, 0x0A, 0x6D, 0x1F, 0x6D, 0x36, 0x7E, 0xCF,
      0x27, 0xCB, 0x09, 0xB7, 0x4F, 0x46, 0x3F, 0x66, 0x9E, 0x5F, 0xEA, 0x2D,
      0x75, 0x27, 0xBA, 0xC7, 0xEB, 0xE5, 0xF1, 0x7B, 0x3D, 0x07, 0x39, 0xF7,
      0x8A, 0x52, 0x92, 0xEA, 0x6B, 0xFB, 0x5F, 0xB1, 0x1F, 0x8D, 0x5D, 0x08,
      0x56, 0x03, 0x30, 0x46, 0xFC, 0x7B, 0x6B, 0xAB, 0xF0, 0xCF, 0xBC, 0x20,
      0x9A, 0xF4, 0x36, 0x1D, 0xA9, 0xE3, 0x91, 0x61, 0x5E, 0xE6, 0x1B, 0x08,
      0x65, 0x99, 0x85, 0x5F, 0x14, 0xA0, 0x68, 0x40, 0x8D, 0xFF, 0xD8, 0x80,
      0x4D, 0x73, 0x27, 0x31, 0x06, 0x06, 0x15, 0x56, 0xCA, 0x73, 0xA8, 0xC9,
      0x60, 0xE2, 0x7B, 0xC0, 0x8C, 0x6B};

  /* initialize jk */
  jk = init_jk[prec];
  jp = jk;

  /* determine jx,jv,q0, note that 3>q0 */
  jx = nx - 1;
  jv = (e0 - 3) / 8;
  if (jv < 0) {
    jv = 0;
  }

  q0 = e0 - 8 * (jv + 1);

  /* set up f[0] to f[jx+jk] where f[jx+jk] = two_over_pi[jv+jk] */
  j = jv - jx;
  m = jx + jk;
  for (i = 0; i <= m; i++, j++) {
    float temp_var_for_const_0, temp_var_for_const_1;
    f[i] = (j < 0) ? zero : (float)two_over_pi[j];
    AssignF(
        {(Addr) &(temp_var_for_const_1 = f[i])},
        (Addr) &(temp_var_for_const_0 = (j < 0) ? zero : (float)two_over_pi[j]),
        "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:88:10");
    ;
  }

  /* compute q[0],q[1],...q[jk] */
  for (i = 0; i <= jk; i++) {
    for (j = 0, fw = 0.0; j <= jx; j++) {
      fw += float temp_var_for_tac_0;
      float temp_var_for_const_2, temp_var_for_const_3;
      temp_var_for_tac_0 = x[j] * f[jx + i - j];

      ;
    }

    float temp_var_for_const_4;
    q[i] = fw;
    computeFMul((Addr)&temp_var_for_tac_0,
                {(Addr) &(temp_var_for_const_3 = x[j]),
                 (Addr) &(temp_var_for_const_2 = f[jx + i - j])},
                "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:94:18");
    AssignF({(Addr) &(temp_var_for_const_4 = q[i])}, (Addr)&fw,
            "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:97:10");
    ;
  }

  jz = jk;
recompute:
  /* distill q[] into iq[] reversingly */
  {
    for (i = 0, j = jz, z = q[jz]; j > 0; i++, j--) {
      float temp_var_for_tac_1;
      float temp_var_for_const_5, temp_var_for_const_6;
      temp_var_for_tac_1 = twon8 * z;

      fw = ((float)((int32_t)temp_var_for_tac_1));
      computeFMul((Addr)&temp_var_for_tac_1,
                  {(Addr) &(temp_var_for_const_5 = twon8), (Addr)&z},
                  "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:105:36");
      AssignF({(Addr)&fw}, (Addr) &(temp_var_for_const_6 =
                                        ((float)((int32_t)temp_var_for_tac_1))),
              "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:105:10");
      ;
      iq[i] =
          (int32_t)(float temp_var_for_tac_2, temp_var_for_tac_3;
                    float temp_var_for_const_7; temp_var_for_tac_2 = two8 * fw;

                    temp_var_for_tac_3 = z - temp_var_for_tac_2;

                    );
      float temp_var_for_ext_0;
      float temp_var_for_tac_4;
      float temp_var_for_const_8;
      temp_var_for_tac_4 = q[j - 1] + fw;

      temp_var_for_ext_0 = temp_var_for_tac_4;
      computeFMul((Addr)&temp_var_for_tac_2,
                  {(Addr) &(temp_var_for_const_7 = two8), (Addr)&fw},
                  "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:106:34");
      computeFSub((Addr)&temp_var_for_tac_3,
                  {(Addr)&z, (Addr)&temp_var_for_tac_2},
                  "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:106:27");
      computeFAdd((Addr)&temp_var_for_tac_4,
                  {(Addr) &(temp_var_for_const_8 = q[j - 1]), (Addr)&fw},
                  "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:108:37");
      AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_4,
              "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:108:26");
      ; // z
      /*(z)(twon8)(fw)(two8)(z)(fw)(two8)(fw)(q)(1)(j)(q[TempNull])*/
      z = temp_var_for_ext_0;
      AssignF({(Addr)&z}, (Addr)&temp_var_for_ext_0,
              "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:110:9");
      ;
    }
  }

  /* compute n */
  float temp_var_for_const_9;
  float temp_var_for_callexp_0;

  temp_var_for_callexp_0 = __ieee754_scalbnf(z, ((int)q0));
  z = temp_var_for_callexp_0;
  AssignF({(Addr)&z}, (Addr) &(temp_var_for_const_9 = temp_var_for_callexp_0),
          "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:115:5");
  ; /* actual value of z */
  float temp_var_for_tac_5, temp_var_for_tac_6;
  float temp_var_for_const_10, temp_var_for_const_11, temp_var_for_const_12;
  float temp_var_for_callexp_1;

  temp_var_for_tac_5 = z * ((float)0.125);

  temp_var_for_callexp_1 = __ieee754_floorf(temp_var_for_tac_5);
  temp_var_for_tac_6 = ((float)8.0) * temp_var_for_callexp_1;

  z -= temp_var_for_tac_6;
  ; /* trim off integer >= 8 */

  n = (int32_t)z;
  z -= ((float)n);
  ;
  ih = 0;
  if (q0 > 0) { /* need iq[jz-1] to determine n */
    i = (iq[jz - 1] >> (8 - q0));
    n += i;
    iq[jz - 1] -= i << (8 - q0);
    ih = iq[jz - 1] >> (7 - q0);
  } else {
    if (q0 == 0) {
      ih = iq[jz - 1] >> 7;
    } else {
      if (int temp_var_for_tac_9; int temp_var_for_const_13;
          temp_var_for_tac_9 = z >= ((float)0.5);

          ) {
        ih = 2;
      }
    }
  }

  if (ih > 0) { /* q > 0.5 */
    n += 1;
    carry = 0;
    for (i = 0; i < jz; i++) { /* compute 1-q */
      j = iq[i];
      if (carry == 0) {
        if (j != 0) {
          carry = 1;
          iq[i] = 0x100 - j;
        }
      } else {
        iq[i] = 0xff - j;
      }
    }
    if (q0 > 0) { /* rare case: chance is 1 in 12 */
      int temp_var_for_ext_1;
      temp_var_for_ext_1 = (int)q0;
      switch (temp_var_for_ext_1) {
      case 1: {
        iq[jz - 1] &= 0x7f;
      }

      break;
      case 2: {
        iq[jz - 1] &= 0x3f;
      }

      break;
      }
    }
    if (ih == 2) {
      float temp_var_for_ext_2;
      float temp_var_for_tac_10;
      float temp_var_for_const_14;
      temp_var_for_tac_10 = one - z;

      temp_var_for_ext_2 = temp_var_for_tac_10;
      computeFMul((Addr)&temp_var_for_tac_5,
                  {(Addr)&z, (Addr) &(temp_var_for_const_10 = ((float)0.125))},
                  "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:117:27");
      computeFMul((Addr)&temp_var_for_tac_6,
                  {(Addr) &(temp_var_for_const_12 = ((float)8.0)),
                   (Addr) &(temp_var_for_const_11 = temp_var_for_callexp_1)},
                  "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:116:19");
      compute((Addr)&temp_var_for_tac_9,
              {(Addr)&z, (Addr) &(temp_var_for_const_13 = ((float)0.5))},
              "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:131:13");
      computeFSub((Addr)&temp_var_for_tac_10,
                  {(Addr) &(temp_var_for_const_14 = one), (Addr)&z},
                  "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:169:32");
      AssignF({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_10,
              "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:169:26");
      ; // z
      /*(__ieee754_floorf(z * (float) 0.125))(8.0)(8.0)(z)(__ieee754_floorf(z *
       * (float) 0.125))(8.0)(8.0)(0.125)(0.125)(z)(n)(n)(z)(z)(one)*/
      z = temp_var_for_ext_2;
      AssignF({(Addr)&z}, (Addr)&temp_var_for_ext_2,
              "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:172:9");
      ;
      if (carry != 0) {
        float temp_var_for_callexp_2;

        temp_var_for_callexp_2 = __ieee754_scalbnf(one, ((int)q0));
        z -= temp_var_for_callexp_2;
        ;
      }
    }
  }

  /* check if recomputation is needed */
  if (int temp_var_for_tac_12; int temp_var_for_const_15;
      temp_var_for_tac_12 = z == zero;

      ) {
    j = 0;
    for (i = jz - 1; i >= jk; i--) {
      j |= iq[i];
    }

    if (j == 0) { /* need recomputation */
      for (k = 1; iq[jk - k] == 0; k++) {
        ;
      }
      /* k = no. of terms needed */

      for (i = jz + 1; i <= jz + k; i++) { /* add q[jz+1] to q[jz+k] */
        float temp_var_for_const_16, temp_var_for_const_17;
        f[jx + i] = ((float)two_over_pi[jv + i]);
        compute((Addr)&temp_var_for_tac_12,
                {(Addr)&z, (Addr) &(temp_var_for_const_15 = zero)},
                "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:180:9");
        AssignF({(Addr) &(temp_var_for_const_17 = f[jx + i])},
                (Addr) &(temp_var_for_const_16 = ((float)two_over_pi[jv + i])),
                "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:193:19");
        ;
        for (j = 0, fw = 0.0; j <= jx; j++) {
          float temp_var_for_tac_13;
          float temp_var_for_const_18, temp_var_for_const_19;
          temp_var_for_tac_13 = x[j] * f[jx + i - j];

          fw += temp_var_for_tac_13;
          ;
        }

        float temp_var_for_const_20;
        q[i] = fw;
        computeFMul((Addr)&temp_var_for_tac_13,
                    {(Addr) &(temp_var_for_const_19 = x[j]),
                     (Addr) &(temp_var_for_const_18 = f[jx + i - j])},
                    "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:195:22");
        AssignF({(Addr) &(temp_var_for_const_20 = q[i])}, (Addr)&fw,
                "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:198:14");
        ;
      }
      jz += k;
      goto recompute;
    }
  }

  /* chop off zero terms */
  if (int temp_var_for_tac_15; int temp_var_for_const_21;
      temp_var_for_tac_15 = z == ((float)0.0);

      ) {
    jz -= 1;
    q0 -= 8;
    int temp_var_for_ext_3;
    temp_var_for_ext_3 = iq[jz] == 0;
    while (temp_var_for_ext_3) {
      jz--;
      q0 -= 8;
      temp_var_for_ext_3 = iq[jz] == 0;
    }
  } else { /* break z into 8-bit if necessary */
    float temp_var_for_const_22;
    float temp_var_for_callexp_3;

    temp_var_for_callexp_3 = __ieee754_scalbnf(z, ((int)(-(q0))));
    z = temp_var_for_callexp_3;
    compute((Addr)&temp_var_for_tac_15,
            {(Addr)&z, (Addr) &(temp_var_for_const_21 = ((float)0.0))},
            "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:206:9");
    AssignF({(Addr)&z},
            (Addr) &(temp_var_for_const_22 = temp_var_for_callexp_3),
            "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:217:7");
    ;
    if (int temp_var_for_tac_16; int temp_var_for_const_23;
        temp_var_for_tac_16 = z >= two8;

        ) {
      float temp_var_for_tac_17;
      float temp_var_for_const_24, temp_var_for_const_25;
      temp_var_for_tac_17 = twon8 * z;

      fw = ((float)((int32_t)temp_var_for_tac_17));
      compute((Addr)&temp_var_for_tac_16,
              {(Addr)&z, (Addr) &(temp_var_for_const_23 = two8)},
              "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:218:11");
      computeFMul((Addr)&temp_var_for_tac_17,
                  {(Addr) &(temp_var_for_const_24 = twon8), (Addr)&z},
                  "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:219:36");
      AssignF({(Addr)&fw},
              (Addr) &(temp_var_for_const_25 =
                           ((float)((int32_t)temp_var_for_tac_17))),
              "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:219:10");
      ;
      iq[jz] = (int32_t)(float temp_var_for_tac_18, temp_var_for_tac_19;
                         float temp_var_for_const_26;
                         temp_var_for_tac_18 = two8 * fw;

                         temp_var_for_tac_19 = z - temp_var_for_tac_18;

                         );
      jz += 1;
      q0 += 8;
      iq[jz] = (int32_t)fw;
    } else {
      iq[jz] = (int32_t)z;
    }
  }

  /* convert integer "bit" chunk to floating-point value */
  float temp_var_for_ext_4;
  float temp_var_for_const_27;
  float temp_var_for_callexp_4;

  temp_var_for_callexp_4 = __ieee754_scalbnf(one, ((int)q0));
  temp_var_for_ext_4 = temp_var_for_callexp_4;
  computeFMul((Addr)&temp_var_for_tac_18,
              {(Addr) &(temp_var_for_const_26 = two8), (Addr)&fw},
              "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:220:35");
  computeFSub((Addr)&temp_var_for_tac_19,
              {(Addr)&z, (Addr)&temp_var_for_tac_18},
              "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:220:28");
  AssignF({(Addr)&temp_var_for_ext_4},
          (Addr) &(temp_var_for_const_27 = temp_var_for_callexp_4),
          "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:231:22");
  ; // fw
  /*(z)(twon8)(fw)(two8)(z)(fw)(two8)(__ieee754_scalbnf(one, (int)q0))*/
  fw = temp_var_for_ext_4;
  AssignF({(Addr)&fw}, (Addr)&temp_var_for_ext_4,
          "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:233:6");
  ;
  for (i = jz; i >= 0; i--) {
    float temp_var_for_tac_20;
    float temp_var_for_const_28, temp_var_for_const_29;
    temp_var_for_tac_20 = fw * ((float)iq[i]);

    q[i] = temp_var_for_tac_20;
    computeFMul((Addr)&temp_var_for_tac_20,
                {(Addr)&fw, (Addr) &(temp_var_for_const_28 = ((float)iq[i]))},
                "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:235:15");
    AssignF({(Addr) &(temp_var_for_const_29 = q[i])},
            (Addr)&temp_var_for_tac_20,
            "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:235:10");
    ;
    fw *= twon8;
    ;
  }

  /* compute PIo2[0,...,jp]*q[jz,...,0] */
  for (i = jz; i >= 0; i--) {
    for (float temp_var_for_ext_5; temp_var_for_ext_5 = 0.0, k = 0;
         k <= jp && k <= jz - i; k++) {
      fw += PIo2[k] * q[i + k];
    }

    fq[jz - i] = fw;
  }

  /* compress fq[] into y[] */
  int temp_var_for_ext_6;
  temp_var_for_ext_6 = prec;
  switch (temp_var_for_ext_6) {
  case 0: {
    float temp_var_for_const_30;
    fw = 0.0;
    AssignF({(Addr)&fw}, (Addr) &(temp_var_for_const_30 = 0.0),
            "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:254:8");
    ;
  }

    for (i = jz; i >= 0; i--) {
      fw += fq[i];
      ;
    }

    float temp_var_for_const_31, temp_var_for_const_32;
    y[0] = (ih == 0) ? fw : (0.0 - fw);
    AssignF({(Addr) &(temp_var_for_const_32 = y[0])},
            (Addr) &(temp_var_for_const_31 = (ih == 0) ? fw : (0.0 - fw)),
            "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:261:10");
    ;
    break;
  case 1: {
  case 2: {
    volatile float fv = 0.0;

    for (i = jz; i >= 0; i--) {
      fv += fq[i];
    }

    y[0] =
        (ih == 0) ? fv : (double temp_var_for_tac_23;
                          double temp_var_for_const_33, temp_var_for_const_34;
                          temp_var_for_tac_23 = 0.0 - fv;

                          );
    float temp_var_for_ext_7;
    float temp_var_for_tac_24;
    float temp_var_for_const_35, temp_var_for_const_36;
    temp_var_for_tac_24 = fq[0] - fv;

    temp_var_for_ext_7 = temp_var_for_tac_24;
    computeDSub((Addr)&temp_var_for_tac_23,
                {(Addr) &(temp_var_for_const_34 = 0.0),
                 (Addr) &(temp_var_for_const_33 = fv)},
                "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:271:34");
    computeFSub((Addr)&temp_var_for_tac_24,
                {(Addr) &(temp_var_for_const_36 = fq[0]),
                 (Addr) &(temp_var_for_const_35 = fv)},
                "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:273:32");
    AssignF({(Addr)&temp_var_for_ext_7}, (Addr)&temp_var_for_tac_24,
            "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:273:24");
    ; // fv
    /*(fv)(fq)(0)(fq[0])*/
    fv = temp_var_for_ext_7;
    for (i = 1; i <= jz; i++) {
      fv += fq[i];
    }

    float temp_var_for_const_37, temp_var_for_const_38;
    y[1] = (ih == 0) ? fv : (0.0 - fv);
    AssignF({(Addr) &(temp_var_for_const_38 = y[1])},
            (Addr) &(temp_var_for_const_37 = (ih == 0) ? fv : (0.0 - fv)),
            "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:280:10");
    ;
  }
  }

  break;
  case 3: /* painful */
  {
    for (i = jz; i > 0; i--) {
      volatile float fv = fq[i - 1] + fq[i];

      float temp_var_for_tac_25;
      float temp_var_for_const_39, temp_var_for_const_40;
      temp_var_for_tac_25 = fq[i - 1] - fv;

      fq[i] += temp_var_for_tac_25;
      ;
      float temp_var_for_const_41, temp_var_for_const_42;
      fq[i - 1] = fv;
      computeFSub((Addr)&temp_var_for_tac_25,
                  {(Addr) &(temp_var_for_const_40 = fq[i - 1]),
                   (Addr) &(temp_var_for_const_39 = fv)},
                  "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:290:26");
      AssignF({(Addr) &(temp_var_for_const_42 = fq[i - 1])},
              (Addr) &(temp_var_for_const_41 = fv),
              "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:291:17");
      ;
    }
  }

    for (i = jz; i > 1; i--) {
      volatile float fv = float temp_var_for_tac_27;
      float temp_var_for_const_43, temp_var_for_const_44;
      temp_var_for_tac_27 = fq[i - 1] + fq[i];

      ;

      float temp_var_for_tac_28;
      float temp_var_for_const_45, temp_var_for_const_46;
      temp_var_for_tac_28 = fq[i - 1] - fv;

      fq[i] += temp_var_for_tac_28;
      ;
      float temp_var_for_const_47, temp_var_for_const_48;
      fq[i - 1] = fv;
      computeFAdd((Addr)&temp_var_for_tac_27,
                  {(Addr) &(temp_var_for_const_44 = fq[i - 1]),
                   (Addr) &(temp_var_for_const_43 = fq[i])},
                  "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:296:37");
      computeFSub((Addr)&temp_var_for_tac_28,
                  {(Addr) &(temp_var_for_const_46 = fq[i - 1]),
                   (Addr) &(temp_var_for_const_45 = fv)},
                  "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:298:26");
      AssignF({(Addr) &(temp_var_for_const_48 = fq[i - 1])},
              (Addr) &(temp_var_for_const_47 = fv),
              "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:299:17");
      ;
    }
    for (fw = 0.0, i = jz; i >= 2; i--) {
      fw += fq[i];
      ;
    }

    if (ih == 0) {
      float temp_var_for_const_49, temp_var_for_const_50;
      y[0] = fq[0];
      AssignF({(Addr) &(temp_var_for_const_50 = y[0])},
              (Addr) &(temp_var_for_const_49 = fq[0]),
              "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:306:12");
      ;
      float temp_var_for_const_51, temp_var_for_const_52;
      y[1] = fq[1];
      AssignF({(Addr) &(temp_var_for_const_52 = y[1])},
              (Addr) &(temp_var_for_const_51 = fq[1]),
              "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:307:12");
      ;
      float temp_var_for_const_53;
      y[2] = fw;
      AssignF({(Addr) &(temp_var_for_const_53 = y[2])}, (Addr)&fw,
              "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:308:12");
      ;
    } else {
      float temp_var_for_tac_31;
      float temp_var_for_const_54, temp_var_for_const_55, temp_var_for_const_56;
      temp_var_for_tac_31 = 0.0 - fq[0];

      y[0] = temp_var_for_tac_31;
      computeDSub((Addr)&temp_var_for_tac_31,
                  {(Addr) &(temp_var_for_const_55 = 0.0),
                   (Addr) &(temp_var_for_const_54 = fq[0])},
                  "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:310:19");
      AssignF({(Addr) &(temp_var_for_const_56 = y[0])},
              (Addr)&temp_var_for_tac_31,
              "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:310:12");
      ;
      float temp_var_for_tac_32;
      float temp_var_for_const_57, temp_var_for_const_58, temp_var_for_const_59;
      temp_var_for_tac_32 = 0.0 - fq[1];

      y[1] = temp_var_for_tac_32;
      computeDSub((Addr)&temp_var_for_tac_32,
                  {(Addr) &(temp_var_for_const_58 = 0.0),
                   (Addr) &(temp_var_for_const_57 = fq[1])},
                  "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:311:19");
      AssignF({(Addr) &(temp_var_for_const_59 = y[1])},
              (Addr)&temp_var_for_tac_32,
              "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:311:12");
      ;
      float temp_var_for_tac_33;
      float temp_var_for_const_60, temp_var_for_const_61;
      temp_var_for_tac_33 = 0.0 - fw;

      y[2] = temp_var_for_tac_33;
      computeDSub((Addr)&temp_var_for_tac_33,
                  {(Addr) &(temp_var_for_const_60 = 0.0), (Addr)&fw},
                  "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:312:19");
      AssignF({(Addr) &(temp_var_for_const_61 = y[2])},
              (Addr)&temp_var_for_tac_33,
              "/home/shijia/Public/testprogram/k_rem_pio2f.c_e.c:312:12");
      ;
    }
  }
  return n & 7;
}
