#include "../ScDebug/scdebug.h"
/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunSoft, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 */

/* __ieee754_rem_pio2(x,y)
 *
 * return the remainder of x rem pi/2 in y[0]+y[1]
 * use __kernel_rem_pio2()
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

int32_t __ieee754_rem_pio2(double x, double *y) {
  double z, w, t, r, fn;
  double tx[3];
  int32_t e0, i, j, nx, n, ix, hx;
  uint32_t low;

  static const int32_t npio2_hw[] = {
      IC(0x3FF921FB), IC(0x400921FB), IC(0x4012D97C), IC(0x401921FB),
      IC(0x401F6A7A), IC(0x4022D97C), IC(0x4025FDBB), IC(0x402921FB),
      IC(0x402C463A), IC(0x402F6A7A), IC(0x4031475C), IC(0x4032D97C),
      IC(0x40346B9C), IC(0x4035FDBB), IC(0x40378FDB), IC(0x403921FB),
      IC(0x403AB41B), IC(0x403C463A), IC(0x403DD85A), IC(0x403F6A7A),
      IC(0x40407E4C), IC(0x4041475C), IC(0x4042106C), IC(0x4042D97C),
      IC(0x4043A28C), IC(0x40446B9C), IC(0x404534AC), IC(0x4045FDBB),
      IC(0x4046C6CB), IC(0x40478FDB), IC(0x404858EB), IC(0x404921FB)};

  /*
   * invpio2:  53 bits of 2/pi
   * pio2_1:   first  33 bit of pi/2
   * pio2_1t:  pi/2 - pio2_1
   * pio2_2:   second 33 bit of pi/2
   * pio2_2t:  pi/2 - (pio2_1+pio2_2)
   * pio2_3:   third  33 bit of pi/2
   * pio2_3t:  pi/2 - (pio2_1+pio2_2+pio2_3)
   */

  static const double zero =
      0.00000000000000000000e+00; /* 0x00000000, 0x00000000 */
  static const double half =
      5.00000000000000000000e-01; /* 0x3FE00000, 0x00000000 */
  static const double two24 =
      1.67772160000000000000e+07; /* 0x41700000, 0x00000000 */
  static const double invpio2 =
      6.36619772367581382433e-01; /* 0x3FE45F30, 0x6DC9C883 */
  static const double pio2_1 =
      1.57079632673412561417e+00; /* 0x3FF921FB, 0x54400000 */
  static const double pio2_1t =
      6.07710050650619224932e-11; /* 0x3DD0B461, 0x1A626331 */
  static const double pio2_2 =
      6.07710050630396597660e-11; /* 0x3DD0B461, 0x1A600000 */
  static const double pio2_2t =
      2.02226624879595063154e-21; /* 0x3BA3198A, 0x2E037073 */
  static const double pio2_3 =
      2.02226624871116645580e-21; /* 0x3BA3198A, 0x2E000000 */
  static const double pio2_3t =
      8.47842766036889956997e-32; /* 0x397B839A, 0x252049C1 */

  GET_HIGH_WORD(hx, x); /* high word of x */
  ix = hx & IC(0x7fffffff);
  if (ix <= IC(0x3fe921fb)) /* |x| ~<= pi/4 , no need for reduction */
  {
    double temp_var_for_const_0;
    y[0] = x;
    AssignD({(Addr) &(temp_var_for_const_0 = y[0])}, (Addr)&x,
            "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:73:10");
    ;
    double temp_var_for_const_1, temp_var_for_const_2;
    y[1] = 0;
    AssignD({(Addr) &(temp_var_for_const_2 = y[1])},
            (Addr) &(temp_var_for_const_1 = 0),
            "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:74:10");
    ;
    return 0;
  }

  if (ix < IC(0x4002d97c)) { /* |x| < 3pi/4, special case with n=+-1 */
    if (hx > 0) {
      double temp_var_for_tac_0;
      double temp_var_for_const_3;
      temp_var_for_tac_0 = x - pio2_1;

      z = temp_var_for_tac_0;
      computeDSub((Addr)&temp_var_for_tac_0,
                  {(Addr)&x, (Addr) &(temp_var_for_const_3 = pio2_1)},
                  "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:80:13");
      AssignD({(Addr)&z}, (Addr)&temp_var_for_tac_0,
              "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:80:9");
      ;
      if (ix != IC(0x3ff921fb)) { /* 33+53 bit pi is good enough */
        double temp_var_for_tac_1;
        double temp_var_for_const_4, temp_var_for_const_5;
        temp_var_for_tac_1 = z - pio2_1t;

        y[0] = temp_var_for_tac_1;
        computeDSub((Addr)&temp_var_for_tac_1,
                    {(Addr)&z, (Addr) &(temp_var_for_const_4 = pio2_1t)},
                    "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:82:18");
        AssignD({(Addr) &(temp_var_for_const_5 = y[0])},
                (Addr)&temp_var_for_tac_1,
                "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:82:14");
        ;
        double temp_var_for_tac_2, temp_var_for_tac_3;
        double temp_var_for_const_6, temp_var_for_const_7, temp_var_for_const_8;
        temp_var_for_tac_2 = z - y[0];

        temp_var_for_tac_3 = temp_var_for_tac_2 - pio2_1t;

        y[1] = temp_var_for_tac_3;
        computeDSub((Addr)&temp_var_for_tac_2,
                    {(Addr)&z, (Addr) &(temp_var_for_const_6 = y[0])},
                    "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:83:19");
        computeDSub((Addr)&temp_var_for_tac_3,
                    {(Addr)&temp_var_for_tac_2,
                     (Addr) &(temp_var_for_const_7 = pio2_1t)},
                    "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:83:27");
        AssignD({(Addr) &(temp_var_for_const_8 = y[1])},
                (Addr)&temp_var_for_tac_3,
                "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:83:14");
        ;
      } else { /* near pi/2, use 33+33+53 bit pi */
        z -= pio2_2;
        ;
        double temp_var_for_ext_0;
        double temp_var_for_tac_5;
        double temp_var_for_const_9;
        temp_var_for_tac_5 = z - pio2_2t;

        temp_var_for_ext_0 = temp_var_for_tac_5;
        computeDSub((Addr)&temp_var_for_tac_5,
                    {(Addr)&z, (Addr) &(temp_var_for_const_9 = pio2_2t)},
                    "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:87:32");
        AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_5,
                "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:87:28");
        ; // y[0]
        /*(pio2_1t)(y)(0)(y[0])(z)(y)(0)(y[0])(z)(pio2_2)(z)(pio2_2t)(z)*/
        double temp_var_for_const_10;
        y[0] = temp_var_for_ext_0;
        AssignD({(Addr) &(temp_var_for_const_10 = y[0])},
                (Addr)&temp_var_for_ext_0,
                "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:89:14");
        ;
        double temp_var_for_tac_6, temp_var_for_tac_7;
        double temp_var_for_const_11, temp_var_for_const_12,
            temp_var_for_const_13;
        temp_var_for_tac_6 = z - y[0];

        temp_var_for_tac_7 = temp_var_for_tac_6 - pio2_2t;

        y[1] = temp_var_for_tac_7;
        computeDSub((Addr)&temp_var_for_tac_6,
                    {(Addr)&z, (Addr) &(temp_var_for_const_11 = y[0])},
                    "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:90:19");
        computeDSub((Addr)&temp_var_for_tac_7,
                    {(Addr)&temp_var_for_tac_6,
                     (Addr) &(temp_var_for_const_12 = pio2_2t)},
                    "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:90:27");
        AssignD({(Addr) &(temp_var_for_const_13 = y[1])},
                (Addr)&temp_var_for_tac_7,
                "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:90:14");
        ;
      }
      return 1;
    } else { /* negative x */
      double temp_var_for_ext_1;
      double temp_var_for_tac_8;
      double temp_var_for_const_14;
      temp_var_for_tac_8 = x + pio2_1;

      temp_var_for_ext_1 = temp_var_for_tac_8;
      computeDAdd((Addr)&temp_var_for_tac_8,
                  {(Addr)&x, (Addr) &(temp_var_for_const_14 = pio2_1)},
                  "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:95:30");
      AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_8,
              "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:95:26");
      ; // z
      /*(pio2_2t)(y)(0)(y[0])(z)(y)(0)(y[0])(z)(pio2_1)(x)*/
      z = temp_var_for_ext_1;
      AssignD({(Addr)&z}, (Addr)&temp_var_for_ext_1,
              "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:97:9");
      ;
      if (ix != IC(0x3ff921fb)) { /* 33+53 bit pi is good enough */
        double temp_var_for_tac_9;
        double temp_var_for_const_15, temp_var_for_const_16;
        temp_var_for_tac_9 = z + pio2_1t;

        y[0] = temp_var_for_tac_9;
        computeDAdd((Addr)&temp_var_for_tac_9,
                    {(Addr)&z, (Addr) &(temp_var_for_const_15 = pio2_1t)},
                    "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:99:18");
        AssignD({(Addr) &(temp_var_for_const_16 = y[0])},
                (Addr)&temp_var_for_tac_9,
                "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:99:14");
        ;
        double temp_var_for_tac_10, temp_var_for_tac_11;
        double temp_var_for_const_17, temp_var_for_const_18,
            temp_var_for_const_19;
        temp_var_for_tac_10 = z - y[0];

        temp_var_for_tac_11 = temp_var_for_tac_10 + pio2_1t;

        y[1] = temp_var_for_tac_11;
        computeDSub((Addr)&temp_var_for_tac_10,
                    {(Addr)&z, (Addr) &(temp_var_for_const_17 = y[0])},
                    "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:100:19");
        computeDAdd((Addr)&temp_var_for_tac_11,
                    {(Addr)&temp_var_for_tac_10,
                     (Addr) &(temp_var_for_const_18 = pio2_1t)},
                    "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:100:27");
        AssignD({(Addr) &(temp_var_for_const_19 = y[1])},
                (Addr)&temp_var_for_tac_11,
                "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:100:14");
        ;
      } else { /* near pi/2, use 33+33+53 bit pi */
        z += pio2_2;
        ;
        double temp_var_for_ext_2;
        double temp_var_for_tac_13;
        double temp_var_for_const_20;
        temp_var_for_tac_13 = z + pio2_2t;

        temp_var_for_ext_2 = temp_var_for_tac_13;
        computeDAdd((Addr)&temp_var_for_tac_13,
                    {(Addr)&z, (Addr) &(temp_var_for_const_20 = pio2_2t)},
                    "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:104:32");
        AssignD({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_13,
                "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:104:28");
        ; // y[0]
        /*(pio2_1t)(y)(0)(y[0])(z)(y)(0)(y[0])(z)(pio2_2)(z)(pio2_2t)(z)*/
        double temp_var_for_const_21;
        y[0] = temp_var_for_ext_2;
        AssignD({(Addr) &(temp_var_for_const_21 = y[0])},
                (Addr)&temp_var_for_ext_2,
                "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:106:14");
        ;
        double temp_var_for_tac_14, temp_var_for_tac_15;
        double temp_var_for_const_22, temp_var_for_const_23,
            temp_var_for_const_24;
        temp_var_for_tac_14 = z - y[0];

        temp_var_for_tac_15 = temp_var_for_tac_14 + pio2_2t;

        y[1] = temp_var_for_tac_15;
        computeDSub((Addr)&temp_var_for_tac_14,
                    {(Addr)&z, (Addr) &(temp_var_for_const_22 = y[0])},
                    "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:107:19");
        computeDAdd((Addr)&temp_var_for_tac_15,
                    {(Addr)&temp_var_for_tac_14,
                     (Addr) &(temp_var_for_const_23 = pio2_2t)},
                    "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:107:27");
        AssignD({(Addr) &(temp_var_for_const_24 = y[1])},
                (Addr)&temp_var_for_tac_15,
                "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:107:14");
        ;
      }
      return -1;
    }
  }

  if (ix <= IC(0x413921fb)) { /* |x| ~<= 2^19*(pi/2), medium size */
    double temp_var_for_const_25;
    double temp_var_for_callexp_0;

    temp_var_for_callexp_0 = fabs(x);
    t = temp_var_for_callexp_0;
    AssignD({(Addr)&t},
            (Addr) &(temp_var_for_const_25 = temp_var_for_callexp_0),
            "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:114:7");
    ;
    n = (int32_t)(double temp_var_for_tac_16, temp_var_for_tac_17;
                  double temp_var_for_const_26, temp_var_for_const_27;
                  temp_var_for_tac_16 = t * invpio2;

                  temp_var_for_tac_17 = temp_var_for_tac_16 + half;

                  );
    double temp_var_for_const_28;
    fn = ((double)n);
    computeDMul((Addr)&temp_var_for_tac_16,
                {(Addr)&t, (Addr) &(temp_var_for_const_26 = invpio2)},
                "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:115:21");
    computeDAdd(
        (Addr)&temp_var_for_tac_17,
        {(Addr)&temp_var_for_tac_16, (Addr) &(temp_var_for_const_27 = half)},
        "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:115:31");
    AssignD({(Addr)&fn}, (Addr) &(temp_var_for_const_28 = ((double)n)),
            "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:116:8");
    ;
    double temp_var_for_tac_18, temp_var_for_tac_19;
    double temp_var_for_const_29;
    temp_var_for_tac_18 = fn * pio2_1;

    temp_var_for_tac_19 = t - temp_var_for_tac_18;

    r = temp_var_for_tac_19;
    computeDMul((Addr)&temp_var_for_tac_18,
                {(Addr)&fn, (Addr) &(temp_var_for_const_29 = pio2_1)},
                "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:117:16");
    computeDSub((Addr)&temp_var_for_tac_19,
                {(Addr)&t, (Addr)&temp_var_for_tac_18},
                "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:117:11");
    AssignD({(Addr)&r}, (Addr)&temp_var_for_tac_19,
            "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:117:7");
    ;
    double temp_var_for_tac_20;
    double temp_var_for_const_30;
    temp_var_for_tac_20 = fn * pio2_1t;

    w = temp_var_for_tac_20;
    computeDMul((Addr)&temp_var_for_tac_20,
                {(Addr)&fn, (Addr) &(temp_var_for_const_30 = pio2_1t)},
                "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:118:12");
    AssignD({(Addr)&w}, (Addr)&temp_var_for_tac_20,
            "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:118:7");
    ; /* 1st round good to 85 bit */
    if (n < 32 && ix != npio2_hw[n - 1]) {
      double temp_var_for_tac_21;
      double temp_var_for_const_31;
      temp_var_for_tac_21 = r - w;

      y[0] = temp_var_for_tac_21;
      computeDSub((Addr)&temp_var_for_tac_21, {(Addr)&r, (Addr)&w},
                  "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:120:16");
      AssignD({(Addr) &(temp_var_for_const_31 = y[0])},
              (Addr)&temp_var_for_tac_21,
              "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:120:12");
      ; /* quick check no cancellation */
    } else {
      uint32_t high;

      j = ix >> IEEE754_DOUBLE_SHIFT;
      double temp_var_for_tac_22;
      double temp_var_for_const_32;
      temp_var_for_tac_22 = r - w;

      y[0] = temp_var_for_tac_22;
      computeDSub((Addr)&temp_var_for_tac_22, {(Addr)&r, (Addr)&w},
                  "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:125:16");
      AssignD({(Addr) &(temp_var_for_const_32 = y[0])},
              (Addr)&temp_var_for_tac_22,
              "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:125:12");
      ;
      GET_HIGH_WORD(high, y[0]);
      i = j - ((high >> IEEE754_DOUBLE_SHIFT) & IEEE754_DOUBLE_MAXEXP);
      if (i > 16) { /* 2nd iteration needed, good to 118 */
        t = r;
        AssignD({(Addr)&t}, (Addr)&r,
                "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:129:11");
        ;
        double temp_var_for_tac_23;
        double temp_var_for_const_33;
        temp_var_for_tac_23 = fn * pio2_2;

        w = temp_var_for_tac_23;
        computeDMul((Addr)&temp_var_for_tac_23,
                    {(Addr)&fn, (Addr) &(temp_var_for_const_33 = pio2_2)},
                    "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:130:16");
        AssignD({(Addr)&w}, (Addr)&temp_var_for_tac_23,
                "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:130:11");
        ;
        double temp_var_for_tac_24;
        temp_var_for_tac_24 = t - w;

        r = temp_var_for_tac_24;
        computeDSub((Addr)&temp_var_for_tac_24, {(Addr)&t, (Addr)&w},
                    "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:131:15");
        AssignD({(Addr)&r}, (Addr)&temp_var_for_tac_24,
                "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:131:11");
        ;
        double temp_var_for_ext_3;
        double temp_var_for_tac_25, temp_var_for_tac_26, temp_var_for_tac_27,
            temp_var_for_tac_28;
        double temp_var_for_const_34;
        temp_var_for_tac_25 = fn * pio2_2t;

        temp_var_for_tac_26 = t - r;

        temp_var_for_tac_27 = temp_var_for_tac_26 - w;

        temp_var_for_tac_28 = temp_var_for_tac_25 - temp_var_for_tac_27;

        temp_var_for_ext_3 = temp_var_for_tac_28;
        computeDMul((Addr)&temp_var_for_tac_25,
                    {(Addr)&fn, (Addr) &(temp_var_for_const_34 = pio2_2t)},
                    "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:133:33");
        computeDSub((Addr)&temp_var_for_tac_26, {(Addr)&t, (Addr)&r},
                    "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:133:49");
        computeDSub((Addr)&temp_var_for_tac_27,
                    {(Addr)&temp_var_for_tac_26, (Addr)&w},
                    "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:133:54");
        computeDSub((Addr)&temp_var_for_tac_28,
                    {(Addr)&temp_var_for_tac_25, (Addr)&temp_var_for_tac_27},
                    "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:133:43");
        AssignD({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_28,
                "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:133:28");
        ; // w
        /*(w)(t)(w)(r)(t)(pio2_2t)(fn)*/
        w = temp_var_for_ext_3;
        AssignD({(Addr)&w}, (Addr)&temp_var_for_ext_3,
                "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:135:11");
        ;
        double temp_var_for_tac_29;
        double temp_var_for_const_35;
        temp_var_for_tac_29 = r - w;

        y[0] = temp_var_for_tac_29;
        computeDSub((Addr)&temp_var_for_tac_29, {(Addr)&r, (Addr)&w},
                    "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:136:18");
        AssignD({(Addr) &(temp_var_for_const_35 = y[0])},
                (Addr)&temp_var_for_tac_29,
                "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:136:14");
        ;
        GET_HIGH_WORD(high, y[0]);
        i = j - ((high >> IEEE754_DOUBLE_SHIFT) & IEEE754_DOUBLE_MAXEXP);
        if (i > 49) { /* 3rd iteration need, 151 bits acc */
          t = r;
          AssignD({(Addr)&t}, (Addr)&r,
                  "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:140:13");
          ; /* will cover all possible cases */
          double temp_var_for_tac_30;
          double temp_var_for_const_36;
          temp_var_for_tac_30 = fn * pio2_3;

          w = temp_var_for_tac_30;
          computeDMul(
              (Addr)&temp_var_for_tac_30,
              {(Addr)&fn, (Addr) &(temp_var_for_const_36 = pio2_3)},
              "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:141:18");
          AssignD({(Addr)&w}, (Addr)&temp_var_for_tac_30,
                  "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:141:13");
          ;
          double temp_var_for_tac_31;
          temp_var_for_tac_31 = t - w;

          r = temp_var_for_tac_31;
          computeDSub(
              (Addr)&temp_var_for_tac_31, {(Addr)&t, (Addr)&w},
              "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:142:17");
          AssignD({(Addr)&r}, (Addr)&temp_var_for_tac_31,
                  "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:142:13");
          ;
          double temp_var_for_ext_4;
          double temp_var_for_tac_32, temp_var_for_tac_33, temp_var_for_tac_34,
              temp_var_for_tac_35;
          double temp_var_for_const_37;
          temp_var_for_tac_32 = fn * pio2_3t;

          temp_var_for_tac_33 = t - r;

          temp_var_for_tac_34 = temp_var_for_tac_33 - w;

          temp_var_for_tac_35 = temp_var_for_tac_32 - temp_var_for_tac_34;

          temp_var_for_ext_4 = temp_var_for_tac_35;
          computeDMul(
              (Addr)&temp_var_for_tac_32,
              {(Addr)&fn, (Addr) &(temp_var_for_const_37 = pio2_3t)},
              "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:144:35");
          computeDSub(
              (Addr)&temp_var_for_tac_33, {(Addr)&t, (Addr)&r},
              "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:144:51");
          computeDSub(
              (Addr)&temp_var_for_tac_34,
              {(Addr)&temp_var_for_tac_33, (Addr)&w},
              "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:144:56");
          computeDSub(
              (Addr)&temp_var_for_tac_35,
              {(Addr)&temp_var_for_tac_32, (Addr)&temp_var_for_tac_34},
              "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:144:45");
          AssignD({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_35,
                  "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:144:30");
          ; // w
          /*(w)(t)(w)(r)(t)(pio2_3t)(fn)*/
          w = temp_var_for_ext_4;
          AssignD({(Addr)&w}, (Addr)&temp_var_for_ext_4,
                  "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:146:13");
          ;
          double temp_var_for_tac_36;
          double temp_var_for_const_38;
          temp_var_for_tac_36 = r - w;

          y[0] = temp_var_for_tac_36;
          computeDSub(
              (Addr)&temp_var_for_tac_36, {(Addr)&r, (Addr)&w},
              "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:147:20");
          AssignD({(Addr) &(temp_var_for_const_38 = y[0])},
                  (Addr)&temp_var_for_tac_36,
                  "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:147:16");
          ;
        }
      }
    }
    double temp_var_for_tac_37, temp_var_for_tac_38;
    double temp_var_for_const_39, temp_var_for_const_40;
    temp_var_for_tac_37 = r - y[0];

    temp_var_for_tac_38 = temp_var_for_tac_37 - w;

    y[1] = temp_var_for_tac_38;
    computeDSub((Addr)&temp_var_for_tac_37,
                {(Addr)&r, (Addr) &(temp_var_for_const_39 = y[0])},
                "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:151:15");
    computeDSub((Addr)&temp_var_for_tac_38,
                {(Addr)&temp_var_for_tac_37, (Addr)&w},
                "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:151:23");
    AssignD({(Addr) &(temp_var_for_const_40 = y[1])},
            (Addr)&temp_var_for_tac_38,
            "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:151:10");
    ;
    if (hx < 0) {
      double temp_var_for_ext_5;
      double temp_var_for_tac_39;
      double temp_var_for_const_41, temp_var_for_const_42;
      temp_var_for_tac_39 = 0.0 - y[0];

      temp_var_for_ext_5 = temp_var_for_tac_39;
      computeDSub((Addr)&temp_var_for_tac_39,
                  {(Addr) &(temp_var_for_const_42 = 0.0),
                   (Addr) &(temp_var_for_const_41 = y[0])},
                  "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:154:33");
      AssignD({(Addr)&temp_var_for_ext_5}, (Addr)&temp_var_for_tac_39,
              "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:154:26");
      ; // y[0]
      /*(w)(y)(0)(y[0])(r)(y)(0)(y[0])(r)(y)(0)(y[0])(y[0])*/
      double temp_var_for_const_43;
      y[0] = temp_var_for_ext_5;
      AssignD({(Addr) &(temp_var_for_const_43 = y[0])},
              (Addr)&temp_var_for_ext_5,
              "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:156:12");
      ;
      double temp_var_for_ext_6;
      double temp_var_for_tac_40;
      double temp_var_for_const_44, temp_var_for_const_45;
      temp_var_for_tac_40 = 0.0 - y[1];

      temp_var_for_ext_6 = temp_var_for_tac_40;
      computeDSub((Addr)&temp_var_for_tac_40,
                  {(Addr) &(temp_var_for_const_45 = 0.0),
                   (Addr) &(temp_var_for_const_44 = y[1])},
                  "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:158:33");
      AssignD({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_40,
              "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:158:26");
      ; // y[1]
      /*(y)(1)(y[1])(y[1])*/
      double temp_var_for_const_46;
      y[1] = temp_var_for_ext_6;
      AssignD({(Addr) &(temp_var_for_const_46 = y[1])},
              (Addr)&temp_var_for_ext_6,
              "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:160:12");
      ;
      return -n;
    } else {
      return n;
    }
  }

  /*
   * all other (large) arguments
   */
  if (ix >= IC(0x7ff00000)) { /* x is inf or NaN */
    double temp_var_for_tac_41;
    double temp_var_for_const_47, temp_var_for_const_48;
    temp_var_for_tac_41 = x - x;

    y[1] = temp_var_for_tac_41;
    computeDSub((Addr)&temp_var_for_tac_41, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:171:21");
    AssignD({(Addr) &(temp_var_for_const_47 = y[1])},
            (Addr)&temp_var_for_tac_41,
            "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:171:17");
    y[0] = y[1];
    AssignD({(Addr) &(temp_var_for_const_48 = y[0])}, (Addr)&y[1],
            "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:171:10");
    ;
    return 0;
  }
  /* set z = scalbn(|x|,ilogb(x)-23) */
  GET_LOW_WORD(low, x);
  e0 = (ix >> IEEE754_DOUBLE_SHIFT) -
       (IEEE754_DOUBLE_BIAS + 23); /* e0 = ilogb(z)-23; */
  INSERT_WORDS(z, ix - (e0 << IEEE754_DOUBLE_SHIFT), low);
  for (i = 0; i < 2; i++) {
    double temp_var_for_const_49, temp_var_for_const_50;
    tx[i] = ((double)((int32_t)z));
    AssignD({(Addr) &(temp_var_for_const_50 = tx[i])},
            (Addr) &(temp_var_for_const_49 = ((double)((int32_t)z))),
            "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:180:11");
    ;
    double temp_var_for_ext_7;
    double temp_var_for_tac_42, temp_var_for_tac_43;
    double temp_var_for_const_51, temp_var_for_const_52;
    temp_var_for_tac_42 = z - tx[i];

    temp_var_for_tac_43 = temp_var_for_tac_42 * two24;

    temp_var_for_ext_7 = temp_var_for_tac_43;
    computeDSub((Addr)&temp_var_for_tac_42,
                {(Addr)&z, (Addr) &(temp_var_for_const_51 = tx[i])},
                "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:182:29");
    computeDMul(
        (Addr)&temp_var_for_tac_43,
        {(Addr)&temp_var_for_tac_42, (Addr) &(temp_var_for_const_52 = two24)},
        "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:182:38");
    AssignD({(Addr)&temp_var_for_ext_7}, (Addr)&temp_var_for_tac_43,
            "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:182:24");
    ; // z
    /*(two24)(tx)(i)(tx[i])(z)*/
    z = temp_var_for_ext_7;
    AssignD({(Addr)&z}, (Addr)&temp_var_for_ext_7,
            "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:184:7");
    ;
  }
  double temp_var_for_const_53;
  tx[2] = z;
  AssignD({(Addr) &(temp_var_for_const_53 = tx[2])}, (Addr)&z,
          "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:186:9");
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
  n = __kernel_rem_pio2(tx, y, e0, nx, 2);
  if (hx < 0) {
    double temp_var_for_ext_9;
    double temp_var_for_tac_46;
    double temp_var_for_const_58, temp_var_for_const_59;
    temp_var_for_tac_46 = 0.0 - y[0];

    temp_var_for_ext_9 = temp_var_for_tac_46;
    compute((Addr)&temp_var_for_tac_44,
            {(Addr) &(temp_var_for_const_55 = tx[nx - 1]),
             (Addr) &(temp_var_for_const_54 = zero)},
            "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:189:35");
    compute((Addr)&temp_var_for_tac_45,
            {(Addr) &(temp_var_for_const_57 = tx[nx - 1]),
             (Addr) &(temp_var_for_const_56 = zero)},
            "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:192:37");
    computeDSub((Addr)&temp_var_for_tac_46,
                {(Addr) &(temp_var_for_const_59 = 0.0),
                 (Addr) &(temp_var_for_const_58 = y[0])},
                "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:198:31");
    AssignD({(Addr)&temp_var_for_ext_9}, (Addr)&temp_var_for_tac_46,
            "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:198:24");
    ; // y[0]
    /*(y)(0)(y[0])(y[0])*/
    double temp_var_for_const_60;
    y[0] = temp_var_for_ext_9;
    AssignD({(Addr) &(temp_var_for_const_60 = y[0])}, (Addr)&temp_var_for_ext_9,
            "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:200:10");
    ;
    double temp_var_for_ext_10;
    double temp_var_for_tac_47;
    double temp_var_for_const_61, temp_var_for_const_62;
    temp_var_for_tac_47 = 0.0 - y[1];

    temp_var_for_ext_10 = temp_var_for_tac_47;
    computeDSub((Addr)&temp_var_for_tac_47,
                {(Addr) &(temp_var_for_const_62 = 0.0),
                 (Addr) &(temp_var_for_const_61 = y[1])},
                "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:202:32");
    AssignD({(Addr)&temp_var_for_ext_10}, (Addr)&temp_var_for_tac_47,
            "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:202:25");
    ; // y[1]
    /*(y)(1)(y[1])(y[1])*/
    double temp_var_for_const_63;
    y[1] = temp_var_for_ext_10;
    AssignD({(Addr) &(temp_var_for_const_63 = y[1])},
            (Addr)&temp_var_for_ext_10,
            "/home/shijia/Public/testprogram/e_rem_pio2.c_e.c:204:10");
    ;
    return -n;
  }
  return n;
}
