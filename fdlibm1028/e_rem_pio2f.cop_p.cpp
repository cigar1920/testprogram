#include "../ScDebug/scdebug.h"
/* e_rem_pio2f.c -- float version of e_rem_pio2.c
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

/* __ieee754_rem_pio2f(x,y)
 *
 * return the remainder of x rem pi/2 in y[0]+y[1]
 * use __kernel_rem_pio2f()
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

int32_t __ieee754_rem_pio2f(float x, float *y) {
  float z, w, t, r, fn;
  float tx[3];
  int32_t e0, i, j, nx, n, ix, hx;

  /* This array is like the one in e_rem_pio2.c, but the numbers are
     single precision and the last 8 bits are forced to 0.  */
  static const int32_t npio2_hw[] = {
      IC(0x3fc90f00), IC(0x40490f00), IC(0x4096cb00), IC(0x40c90f00),
      IC(0x40fb5300), IC(0x4116cb00), IC(0x412fed00), IC(0x41490f00),
      IC(0x41623100), IC(0x417b5300), IC(0x418a3a00), IC(0x4196cb00),
      IC(0x41a35c00), IC(0x41afed00), IC(0x41bc7e00), IC(0x41c90f00),
      IC(0x41d5a000), IC(0x41e23100), IC(0x41eec200), IC(0x41fb5300),
      IC(0x4203f200), IC(0x420a3a00), IC(0x42108300), IC(0x4216cb00),
      IC(0x421d1400), IC(0x42235c00), IC(0x4229a500), IC(0x422fed00),
      IC(0x42363600), IC(0x423c7e00), IC(0x4242c700), IC(0x42490f00)};

  /*
   * invpio2:  24 bits of 2/pi
   * pio2_1:   first  17 bit of pi/2
   * pio2_1t:  pi/2 - pio2_1
   * pio2_2:   second 17 bit of pi/2
   * pio2_2t:  pi/2 - (pio2_1+pio2_2)
   * pio2_3:   third  17 bit of pi/2
   * pio2_3t:  pi/2 - (pio2_1+pio2_2+pio2_3)
   */

  static const float zero = 0.0000000000e+00;    /* 0x00000000 */
  static const float half = 5.0000000000e-01;    /* 0x3f000000 */
  static const float two8 = 2.5600000000e+02;    /* 0x43800000 */
  static const float invpio2 = 6.3661980629e-01; /* 0x3f22f984 */
  static const float pio2_1 = 1.5707855225e+00;  /* 0x3fc90f80 */
  static const float pio2_1t = 1.0804334124e-05; /* 0x37354443 */
  static const float pio2_2 = 1.0804273188e-05;  /* 0x37354400 */
  static const float pio2_2t = 6.0770999344e-11; /* 0x2e85a308 */
  static const float pio2_3 = 6.0770943833e-11;  /* 0x2e85a300 */
  static const float pio2_3t = 6.1232342629e-17; /* 0x248d3132 */

  GET_FLOAT_WORD(hx, x);
  ix = hx & IC(0x7fffffff);
  if (ix <= IC(0x3f490fd8)) /* |x| ~<= pi/4 , no need for reduction */
  {
    float temp_var_for_const_0;
    y[0] = x;
    AssignF({(Addr) &(temp_var_for_const_0 = y[0])}, (Addr)&x,
            "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:68:10");
    ;
    float temp_var_for_const_1, temp_var_for_const_2;
    y[1] = 0;
    AssignF({(Addr) &(temp_var_for_const_2 = y[1])},
            (Addr) &(temp_var_for_const_1 = 0),
            "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:69:10");
    ;
    return 0;
  }
  if (ix < IC(0x4016cbe4)) { /* |x| < 3pi/4, special case with n=+-1 */
    if (hx > 0) {
      float temp_var_for_tac_0;
      float temp_var_for_const_3;
      temp_var_for_tac_0 = x - pio2_1;

      z = temp_var_for_tac_0;
      computeFSub((Addr)&temp_var_for_tac_0,
                  {(Addr)&x, (Addr) &(temp_var_for_const_3 = pio2_1)},
                  "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:74:13");
      AssignF({(Addr)&z}, (Addr)&temp_var_for_tac_0,
              "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:74:9");
      ;
      if ((ix & IC(0xfffffff0)) != IC(0x3fc90fd0)) { /* 24+24 bit pi OK */
        float temp_var_for_tac_1;
        float temp_var_for_const_4, temp_var_for_const_5;
        temp_var_for_tac_1 = z - pio2_1t;

        y[0] = temp_var_for_tac_1;
        computeFSub((Addr)&temp_var_for_tac_1,
                    {(Addr)&z, (Addr) &(temp_var_for_const_4 = pio2_1t)},
                    "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:76:18");
        AssignF({(Addr) &(temp_var_for_const_5 = y[0])},
                (Addr)&temp_var_for_tac_1,
                "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:76:14");
        ;
        float temp_var_for_tac_2, temp_var_for_tac_3;
        float temp_var_for_const_6, temp_var_for_const_7, temp_var_for_const_8;
        temp_var_for_tac_2 = z - y[0];

        temp_var_for_tac_3 = temp_var_for_tac_2 - pio2_1t;

        y[1] = temp_var_for_tac_3;
        computeFSub((Addr)&temp_var_for_tac_2,
                    {(Addr)&z, (Addr) &(temp_var_for_const_6 = y[0])},
                    "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:77:19");
        computeFSub((Addr)&temp_var_for_tac_3,
                    {(Addr)&temp_var_for_tac_2,
                     (Addr) &(temp_var_for_const_7 = pio2_1t)},
                    "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:77:27");
        AssignF({(Addr) &(temp_var_for_const_8 = y[1])},
                (Addr)&temp_var_for_tac_3,
                "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:77:14");
        ;
      } else { /* near pi/2, use 24+24+24 bit pi */
        z -= pio2_2;
        ;
        float temp_var_for_ext_0;
        float temp_var_for_tac_5;
        float temp_var_for_const_9;
        temp_var_for_tac_5 = z - pio2_2t;

        temp_var_for_ext_0 = temp_var_for_tac_5;
        computeFSub((Addr)&temp_var_for_tac_5,
                    {(Addr)&z, (Addr) &(temp_var_for_const_9 = pio2_2t)},
                    "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:81:32");
        AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_5,
                "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:81:28");
        ; // y[0]
        /*(pio2_1t)(y)(0)(y[0])(z)(y)(0)(y[0])(z)(pio2_2)(z)(pio2_2t)(z)*/
        float temp_var_for_const_10;
        y[0] = temp_var_for_ext_0;
        AssignF({(Addr) &(temp_var_for_const_10 = y[0])},
                (Addr)&temp_var_for_ext_0,
                "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:83:14");
        ;
        float temp_var_for_tac_6, temp_var_for_tac_7;
        float temp_var_for_const_11, temp_var_for_const_12,
            temp_var_for_const_13;
        temp_var_for_tac_6 = z - y[0];

        temp_var_for_tac_7 = temp_var_for_tac_6 - pio2_2t;

        y[1] = temp_var_for_tac_7;
        computeFSub((Addr)&temp_var_for_tac_6,
                    {(Addr)&z, (Addr) &(temp_var_for_const_11 = y[0])},
                    "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:84:19");
        computeFSub((Addr)&temp_var_for_tac_7,
                    {(Addr)&temp_var_for_tac_6,
                     (Addr) &(temp_var_for_const_12 = pio2_2t)},
                    "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:84:27");
        AssignF({(Addr) &(temp_var_for_const_13 = y[1])},
                (Addr)&temp_var_for_tac_7,
                "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:84:14");
        ;
      }
      return 1;
    } else { /* negative x */
      float temp_var_for_ext_1;
      float temp_var_for_tac_8;
      float temp_var_for_const_14;
      temp_var_for_tac_8 = x + pio2_1;

      temp_var_for_ext_1 = temp_var_for_tac_8;
      computeFAdd((Addr)&temp_var_for_tac_8,
                  {(Addr)&x, (Addr) &(temp_var_for_const_14 = pio2_1)},
                  "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:89:30");
      AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_8,
              "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:89:26");
      ; // z
      /*(pio2_2t)(y)(0)(y[0])(z)(y)(0)(y[0])(z)(pio2_1)(x)*/
      z = temp_var_for_ext_1;
      AssignF({(Addr)&z}, (Addr)&temp_var_for_ext_1,
              "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:91:9");
      ;
      if ((ix & IC(0xfffffff0)) != IC(0x3fc90fd0)) { /* 24+24 bit pi OK */
        float temp_var_for_tac_9;
        float temp_var_for_const_15, temp_var_for_const_16;
        temp_var_for_tac_9 = z + pio2_1t;

        y[0] = temp_var_for_tac_9;
        computeFAdd((Addr)&temp_var_for_tac_9,
                    {(Addr)&z, (Addr) &(temp_var_for_const_15 = pio2_1t)},
                    "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:93:18");
        AssignF({(Addr) &(temp_var_for_const_16 = y[0])},
                (Addr)&temp_var_for_tac_9,
                "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:93:14");
        ;
        float temp_var_for_tac_10, temp_var_for_tac_11;
        float temp_var_for_const_17, temp_var_for_const_18,
            temp_var_for_const_19;
        temp_var_for_tac_10 = z - y[0];

        temp_var_for_tac_11 = temp_var_for_tac_10 + pio2_1t;

        y[1] = temp_var_for_tac_11;
        computeFSub((Addr)&temp_var_for_tac_10,
                    {(Addr)&z, (Addr) &(temp_var_for_const_17 = y[0])},
                    "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:94:19");
        computeFAdd((Addr)&temp_var_for_tac_11,
                    {(Addr)&temp_var_for_tac_10,
                     (Addr) &(temp_var_for_const_18 = pio2_1t)},
                    "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:94:27");
        AssignF({(Addr) &(temp_var_for_const_19 = y[1])},
                (Addr)&temp_var_for_tac_11,
                "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:94:14");
        ;
      } else { /* near pi/2, use 24+24+24 bit pi */
        z += pio2_2;
        ;
        float temp_var_for_ext_2;
        float temp_var_for_tac_13;
        float temp_var_for_const_20;
        temp_var_for_tac_13 = z + pio2_2t;

        temp_var_for_ext_2 = temp_var_for_tac_13;
        computeFAdd((Addr)&temp_var_for_tac_13,
                    {(Addr)&z, (Addr) &(temp_var_for_const_20 = pio2_2t)},
                    "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:98:32");
        AssignF({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_13,
                "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:98:28");
        ; // y[0]
        /*(pio2_1t)(y)(0)(y[0])(z)(y)(0)(y[0])(z)(pio2_2)(z)(pio2_2t)(z)*/
        float temp_var_for_const_21;
        y[0] = temp_var_for_ext_2;
        AssignF({(Addr) &(temp_var_for_const_21 = y[0])},
                (Addr)&temp_var_for_ext_2,
                "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:100:14");
        ;
        float temp_var_for_tac_14, temp_var_for_tac_15;
        float temp_var_for_const_22, temp_var_for_const_23,
            temp_var_for_const_24;
        temp_var_for_tac_14 = z - y[0];

        temp_var_for_tac_15 = temp_var_for_tac_14 + pio2_2t;

        y[1] = temp_var_for_tac_15;
        computeFSub((Addr)&temp_var_for_tac_14,
                    {(Addr)&z, (Addr) &(temp_var_for_const_22 = y[0])},
                    "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:101:19");
        computeFAdd((Addr)&temp_var_for_tac_15,
                    {(Addr)&temp_var_for_tac_14,
                     (Addr) &(temp_var_for_const_23 = pio2_2t)},
                    "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:101:27");
        AssignF({(Addr) &(temp_var_for_const_24 = y[1])},
                (Addr)&temp_var_for_tac_15,
                "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:101:14");
        ;
      }
      return -1;
    }
  }
  if (ix <= IC(0x43490f80)) { /* |x| ~<= 2^7*(pi/2), medium size */
    float temp_var_for_const_25;
    float temp_var_for_callexp_0;

    temp_var_for_callexp_0 = fabsf(x);
    t = temp_var_for_callexp_0;
    AssignF({(Addr)&t},
            (Addr) &(temp_var_for_const_25 = temp_var_for_callexp_0),
            "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:107:7");
    ;
    n = (int32_t)(float temp_var_for_tac_16, temp_var_for_tac_17;
                  float temp_var_for_const_26, temp_var_for_const_27;
                  temp_var_for_tac_16 = t * invpio2;

                  temp_var_for_tac_17 = temp_var_for_tac_16 + half;

                  );
    float temp_var_for_const_28;
    fn = ((float)n);
    computeFMul((Addr)&temp_var_for_tac_16,
                {(Addr)&t, (Addr) &(temp_var_for_const_26 = invpio2)},
                "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:108:21");
    computeFAdd(
        (Addr)&temp_var_for_tac_17,
        {(Addr)&temp_var_for_tac_16, (Addr) &(temp_var_for_const_27 = half)},
        "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:108:31");
    AssignF({(Addr)&fn}, (Addr) &(temp_var_for_const_28 = ((float)n)),
            "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:109:8");
    ;
    float temp_var_for_tac_18, temp_var_for_tac_19;
    float temp_var_for_const_29;
    temp_var_for_tac_18 = fn * pio2_1;

    temp_var_for_tac_19 = t - temp_var_for_tac_18;

    r = temp_var_for_tac_19;
    computeFMul((Addr)&temp_var_for_tac_18,
                {(Addr)&fn, (Addr) &(temp_var_for_const_29 = pio2_1)},
                "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:110:16");
    computeFSub((Addr)&temp_var_for_tac_19,
                {(Addr)&t, (Addr)&temp_var_for_tac_18},
                "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:110:11");
    AssignF({(Addr)&r}, (Addr)&temp_var_for_tac_19,
            "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:110:7");
    ;
    float temp_var_for_tac_20;
    float temp_var_for_const_30;
    temp_var_for_tac_20 = fn * pio2_1t;

    w = temp_var_for_tac_20;
    computeFMul((Addr)&temp_var_for_tac_20,
                {(Addr)&fn, (Addr) &(temp_var_for_const_30 = pio2_1t)},
                "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:111:12");
    AssignF({(Addr)&w}, (Addr)&temp_var_for_tac_20,
            "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:111:7");
    ; /* 1st round good to 40 bit */
    if (n < 32 && (int32_t)(ix & IC(0xffffff00)) != npio2_hw[n - 1]) {
      float temp_var_for_tac_21;
      float temp_var_for_const_31;
      temp_var_for_tac_21 = r - w;

      y[0] = temp_var_for_tac_21;
      computeFSub((Addr)&temp_var_for_tac_21, {(Addr)&r, (Addr)&w},
                  "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:113:16");
      AssignF({(Addr) &(temp_var_for_const_31 = y[0])},
              (Addr)&temp_var_for_tac_21,
              "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:113:12");
      ; /* quick check no cancellation */
    } else {
      uint32_t high;

      j = ix >> IEEE754_FLOAT_SHIFT;
      float temp_var_for_tac_22;
      float temp_var_for_const_32;
      temp_var_for_tac_22 = r - w;

      y[0] = temp_var_for_tac_22;
      computeFSub((Addr)&temp_var_for_tac_22, {(Addr)&r, (Addr)&w},
                  "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:118:16");
      AssignF({(Addr) &(temp_var_for_const_32 = y[0])},
              (Addr)&temp_var_for_tac_22,
              "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:118:12");
      ;
      GET_FLOAT_WORD(high, y[0]);
      i = j - ((high >> IEEE754_FLOAT_SHIFT) & IEEE754_FLOAT_MAXEXP);
      if (i > 8) { /* 2nd iteration needed, good to 57 */
        t = r;
        AssignF({(Addr)&t}, (Addr)&r,
                "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:122:11");
        ;
        float temp_var_for_tac_23;
        float temp_var_for_const_33;
        temp_var_for_tac_23 = fn * pio2_2;

        w = temp_var_for_tac_23;
        computeFMul((Addr)&temp_var_for_tac_23,
                    {(Addr)&fn, (Addr) &(temp_var_for_const_33 = pio2_2)},
                    "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:123:16");
        AssignF({(Addr)&w}, (Addr)&temp_var_for_tac_23,
                "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:123:11");
        ;
        float temp_var_for_tac_24;
        temp_var_for_tac_24 = t - w;

        r = temp_var_for_tac_24;
        computeFSub((Addr)&temp_var_for_tac_24, {(Addr)&t, (Addr)&w},
                    "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:124:15");
        AssignF({(Addr)&r}, (Addr)&temp_var_for_tac_24,
                "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:124:11");
        ;
        float temp_var_for_ext_3;
        float temp_var_for_tac_25, temp_var_for_tac_26, temp_var_for_tac_27,
            temp_var_for_tac_28;
        float temp_var_for_const_34;
        temp_var_for_tac_25 = fn * pio2_2t;

        temp_var_for_tac_26 = t - r;

        temp_var_for_tac_27 = temp_var_for_tac_26 - w;

        temp_var_for_tac_28 = temp_var_for_tac_25 - temp_var_for_tac_27;

        temp_var_for_ext_3 = temp_var_for_tac_28;
        computeFMul((Addr)&temp_var_for_tac_25,
                    {(Addr)&fn, (Addr) &(temp_var_for_const_34 = pio2_2t)},
                    "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:126:33");
        computeFSub((Addr)&temp_var_for_tac_26, {(Addr)&t, (Addr)&r},
                    "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:126:49");
        computeFSub((Addr)&temp_var_for_tac_27,
                    {(Addr)&temp_var_for_tac_26, (Addr)&w},
                    "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:126:54");
        computeFSub((Addr)&temp_var_for_tac_28,
                    {(Addr)&temp_var_for_tac_25, (Addr)&temp_var_for_tac_27},
                    "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:126:43");
        AssignF({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_28,
                "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:126:28");
        ; // w
        /*(w)(t)(w)(r)(t)(pio2_2t)(fn)*/
        w = temp_var_for_ext_3;
        AssignF({(Addr)&w}, (Addr)&temp_var_for_ext_3,
                "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:128:11");
        ;
        float temp_var_for_tac_29;
        float temp_var_for_const_35;
        temp_var_for_tac_29 = r - w;

        y[0] = temp_var_for_tac_29;
        computeFSub((Addr)&temp_var_for_tac_29, {(Addr)&r, (Addr)&w},
                    "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:129:18");
        AssignF({(Addr) &(temp_var_for_const_35 = y[0])},
                (Addr)&temp_var_for_tac_29,
                "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:129:14");
        ;
        GET_FLOAT_WORD(high, y[0]);
        i = j - ((high >> IEEE754_FLOAT_SHIFT) & IEEE754_FLOAT_MAXEXP);
        if (i > 25) { /* 3rd iteration need, 74 bits acc */
          t = r;
          AssignF({(Addr)&t}, (Addr)&r,
                  "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:133:13");
          ; /* will cover all possible cases */
          float temp_var_for_tac_30;
          float temp_var_for_const_36;
          temp_var_for_tac_30 = fn * pio2_3;

          w = temp_var_for_tac_30;
          computeFMul(
              (Addr)&temp_var_for_tac_30,
              {(Addr)&fn, (Addr) &(temp_var_for_const_36 = pio2_3)},
              "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:134:18");
          AssignF({(Addr)&w}, (Addr)&temp_var_for_tac_30,
                  "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:134:13");
          ;
          float temp_var_for_tac_31;
          temp_var_for_tac_31 = t - w;

          r = temp_var_for_tac_31;
          computeFSub(
              (Addr)&temp_var_for_tac_31, {(Addr)&t, (Addr)&w},
              "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:135:17");
          AssignF({(Addr)&r}, (Addr)&temp_var_for_tac_31,
                  "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:135:13");
          ;
          float temp_var_for_ext_4;
          float temp_var_for_tac_32, temp_var_for_tac_33, temp_var_for_tac_34,
              temp_var_for_tac_35;
          float temp_var_for_const_37;
          temp_var_for_tac_32 = fn * pio2_3t;

          temp_var_for_tac_33 = t - r;

          temp_var_for_tac_34 = temp_var_for_tac_33 - w;

          temp_var_for_tac_35 = temp_var_for_tac_32 - temp_var_for_tac_34;

          temp_var_for_ext_4 = temp_var_for_tac_35;
          computeFMul(
              (Addr)&temp_var_for_tac_32,
              {(Addr)&fn, (Addr) &(temp_var_for_const_37 = pio2_3t)},
              "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:137:35");
          computeFSub(
              (Addr)&temp_var_for_tac_33, {(Addr)&t, (Addr)&r},
              "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:137:51");
          computeFSub(
              (Addr)&temp_var_for_tac_34,
              {(Addr)&temp_var_for_tac_33, (Addr)&w},
              "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:137:56");
          computeFSub(
              (Addr)&temp_var_for_tac_35,
              {(Addr)&temp_var_for_tac_32, (Addr)&temp_var_for_tac_34},
              "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:137:45");
          AssignF({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_35,
                  "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:137:30");
          ; // w
          /*(w)(t)(w)(r)(t)(pio2_3t)(fn)*/
          w = temp_var_for_ext_4;
          AssignF({(Addr)&w}, (Addr)&temp_var_for_ext_4,
                  "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:139:13");
          ;
          float temp_var_for_tac_36;
          float temp_var_for_const_38;
          temp_var_for_tac_36 = r - w;

          y[0] = temp_var_for_tac_36;
          computeFSub(
              (Addr)&temp_var_for_tac_36, {(Addr)&r, (Addr)&w},
              "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:140:20");
          AssignF({(Addr) &(temp_var_for_const_38 = y[0])},
                  (Addr)&temp_var_for_tac_36,
                  "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:140:16");
          ;
        }
      }
    }
    float temp_var_for_tac_37, temp_var_for_tac_38;
    float temp_var_for_const_39, temp_var_for_const_40;
    temp_var_for_tac_37 = r - y[0];

    temp_var_for_tac_38 = temp_var_for_tac_37 - w;

    y[1] = temp_var_for_tac_38;
    computeFSub((Addr)&temp_var_for_tac_37,
                {(Addr)&r, (Addr) &(temp_var_for_const_39 = y[0])},
                "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:144:15");
    computeFSub((Addr)&temp_var_for_tac_38,
                {(Addr)&temp_var_for_tac_37, (Addr)&w},
                "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:144:23");
    AssignF({(Addr) &(temp_var_for_const_40 = y[1])},
            (Addr)&temp_var_for_tac_38,
            "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:144:10");
    ;
    if (hx < 0) {
      float temp_var_for_ext_5;
      float temp_var_for_tac_39;
      float temp_var_for_const_41, temp_var_for_const_42;
      temp_var_for_tac_39 = 0.0 - y[0];

      temp_var_for_ext_5 = temp_var_for_tac_39;
      computeDSub((Addr)&temp_var_for_tac_39,
                  {(Addr) &(temp_var_for_const_42 = 0.0),
                   (Addr) &(temp_var_for_const_41 = y[0])},
                  "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:147:33");
      AssignF({(Addr)&temp_var_for_ext_5}, (Addr)&temp_var_for_tac_39,
              "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:147:26");
      ; // y[0]
      /*(w)(y)(0)(y[0])(r)(y)(0)(y[0])(r)(y)(0)(y[0])(y[0])*/
      float temp_var_for_const_43;
      y[0] = temp_var_for_ext_5;
      AssignF({(Addr) &(temp_var_for_const_43 = y[0])},
              (Addr)&temp_var_for_ext_5,
              "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:149:12");
      ;
      float temp_var_for_ext_6;
      float temp_var_for_tac_40;
      float temp_var_for_const_44, temp_var_for_const_45;
      temp_var_for_tac_40 = 0.0 - y[1];

      temp_var_for_ext_6 = temp_var_for_tac_40;
      computeDSub((Addr)&temp_var_for_tac_40,
                  {(Addr) &(temp_var_for_const_45 = 0.0),
                   (Addr) &(temp_var_for_const_44 = y[1])},
                  "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:151:33");
      AssignF({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_40,
              "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:151:26");
      ; // y[1]
      /*(y)(1)(y[1])(y[1])*/
      float temp_var_for_const_46;
      y[1] = temp_var_for_ext_6;
      AssignF({(Addr) &(temp_var_for_const_46 = y[1])},
              (Addr)&temp_var_for_ext_6,
              "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:153:12");
      ;
      return -n;
    } else {
      return n;
    }
  }
  /*
   * all other (large) arguments
   */
  if (!FLT_UWORD_IS_FINITE(ix)) { /* x is inf or NaN */
    float temp_var_for_tac_41;
    float temp_var_for_const_47, temp_var_for_const_48;
    temp_var_for_tac_41 = x - x;

    y[1] = temp_var_for_tac_41;
    computeFSub((Addr)&temp_var_for_tac_41, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:163:21");
    AssignF({(Addr) &(temp_var_for_const_47 = y[1])},
            (Addr)&temp_var_for_tac_41,
            "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:163:17");
    y[0] = y[1];
    AssignF({(Addr) &(temp_var_for_const_48 = y[0])}, (Addr)&y[1],
            "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:163:10");
    ;
    return 0;
  }
  /* set z = scalbn(|x|,ilogb(x)-7) */
  e0 = (ix >> IEEE754_FLOAT_SHIFT) -
       (IEEE754_FLOAT_BIAS + 7); /* e0 = ilogb(z)-7; */
  SET_FLOAT_WORD(z, ix - (e0 << IEEE754_FLOAT_SHIFT));
  for (i = 0; i < 2; i++) {
    float temp_var_for_const_49, temp_var_for_const_50;
    tx[i] = ((float)((int32_t)z));
    AssignF({(Addr) &(temp_var_for_const_50 = tx[i])},
            (Addr) &(temp_var_for_const_49 = ((float)((int32_t)z))),
            "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:171:11");
    ;
    float temp_var_for_ext_7;
    float temp_var_for_tac_42, temp_var_for_tac_43;
    float temp_var_for_const_51, temp_var_for_const_52;
    temp_var_for_tac_42 = z - tx[i];

    temp_var_for_tac_43 = temp_var_for_tac_42 * two8;

    temp_var_for_ext_7 = temp_var_for_tac_43;
    computeFSub((Addr)&temp_var_for_tac_42,
                {(Addr)&z, (Addr) &(temp_var_for_const_51 = tx[i])},
                "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:173:29");
    computeFMul(
        (Addr)&temp_var_for_tac_43,
        {(Addr)&temp_var_for_tac_42, (Addr) &(temp_var_for_const_52 = two8)},
        "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:173:38");
    AssignF({(Addr)&temp_var_for_ext_7}, (Addr)&temp_var_for_tac_43,
            "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:173:24");
    ; // z
    /*(two8)(tx)(i)(tx[i])(z)*/
    z = temp_var_for_ext_7;
    AssignF({(Addr)&z}, (Addr)&temp_var_for_ext_7,
            "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:175:7");
    ;
  }
  float temp_var_for_const_53;
  tx[2] = z;
  AssignF({(Addr) &(temp_var_for_const_53 = tx[2])}, (Addr)&z,
          "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:177:9");
  ;
  nx = 3;
  int temp_var_for_ext_8;
  temp_var_for_ext_8 = int temp_var_for_tac_44;
  int temp_var_for_const_54, temp_var_for_const_55;
  temp_var_for_tac_44 = tx[nx - 1] == zero;

  ;
  while (temp_var_for_ext_8) {
    nx--;
    temp_var_for_ext_8 = int temp_var_for_tac_45;
    int temp_var_for_const_56, temp_var_for_const_57;
    temp_var_for_tac_45 = tx[nx - 1] == zero;

    ;
  }
  /* skip zero term */
  n = __kernel_rem_pio2f(tx, y, e0, nx, 2);
  if (hx < 0) {
    float temp_var_for_ext_9;
    float temp_var_for_tac_46;
    float temp_var_for_const_58, temp_var_for_const_59;
    temp_var_for_tac_46 = 0.0 - y[0];

    temp_var_for_ext_9 = temp_var_for_tac_46;
    compute((Addr)&temp_var_for_tac_44,
            {(Addr) &(temp_var_for_const_55 = tx[nx - 1]),
             (Addr) &(temp_var_for_const_54 = zero)},
            "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:180:35");
    compute((Addr)&temp_var_for_tac_45,
            {(Addr) &(temp_var_for_const_57 = tx[nx - 1]),
             (Addr) &(temp_var_for_const_56 = zero)},
            "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:183:37");
    computeDSub((Addr)&temp_var_for_tac_46,
                {(Addr) &(temp_var_for_const_59 = 0.0),
                 (Addr) &(temp_var_for_const_58 = y[0])},
                "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:189:31");
    AssignF({(Addr)&temp_var_for_ext_9}, (Addr)&temp_var_for_tac_46,
            "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:189:24");
    ; // y[0]
    /*(y)(0)(y[0])(y[0])*/
    float temp_var_for_const_60;
    y[0] = temp_var_for_ext_9;
    AssignF({(Addr) &(temp_var_for_const_60 = y[0])}, (Addr)&temp_var_for_ext_9,
            "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:191:10");
    ;
    float temp_var_for_ext_10;
    float temp_var_for_tac_47;
    float temp_var_for_const_61, temp_var_for_const_62;
    temp_var_for_tac_47 = 0.0 - y[1];

    temp_var_for_ext_10 = temp_var_for_tac_47;
    computeDSub((Addr)&temp_var_for_tac_47,
                {(Addr) &(temp_var_for_const_62 = 0.0),
                 (Addr) &(temp_var_for_const_61 = y[1])},
                "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:193:32");
    AssignF({(Addr)&temp_var_for_ext_10}, (Addr)&temp_var_for_tac_47,
            "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:193:25");
    ; // y[1]
    /*(y)(1)(y[1])(y[1])*/
    float temp_var_for_const_63;
    y[1] = temp_var_for_ext_10;
    AssignF({(Addr) &(temp_var_for_const_63 = y[1])},
            (Addr)&temp_var_for_ext_10,
            "/home/shijia/Public/testprogram/e_rem_pio2f.c_e.c:195:10");
    ;
    return -n;
  }
  return n;
}
