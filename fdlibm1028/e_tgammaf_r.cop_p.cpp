#include "../ScDebug/scdebug.h"
/* Implementation of gamma function according to ISO C.
   Copyright (C) 1997-2013 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by Ulrich Drepper <drepper@cygnus.com>, 1997.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif
#include "fpu_ctrl.h"

/* Compute the product of X + X_EPS, X + X_EPS + 1, ..., X + X_EPS + N
   - 1, in the form R * (1 + *EPS) where the return value R is an
   approximation to the product and *EPS is set to indicate the
   approximate error in the return value.  X is such that all the
   values X + 1, ..., X + N - 1 are exactly representable, and X_EPS /
   X is small enough that factors quadratic in it can be
   neglected.  */

static float __gamma_productf(float x, float x_eps, int n, float *eps) {
  double x_full = double temp_var_for_tac_0;
  double temp_var_for_const_0, temp_var_for_const_1;
  temp_var_for_tac_0 = ((double)x) + ((double)x_eps);

  ;
  double ret = x_full;
  int i;
  volatile float fret;

  for (i = 1; i < n; i++) {
    double temp_var_for_tac_1;
    double temp_var_for_const_2;
    temp_var_for_tac_1 = x_full + i;

    ret *= temp_var_for_tac_1;
    ;
  }

  fret = (float)ret;

  float temp_var_for_tac_3, temp_var_for_tac_4;
  float temp_var_for_const_3, temp_var_for_const_4, temp_var_for_const_5;
  temp_var_for_tac_3 = ret - ((double)fret);

  temp_var_for_tac_4 = temp_var_for_tac_3 / ((double)fret);

  (*(eps)) = temp_var_for_tac_4;
  computeDAdd((Addr)&temp_var_for_tac_0,
              {(Addr) &(temp_var_for_const_1 = ((double)x)),
               (Addr) &(temp_var_for_const_0 = ((double)x_eps))},
              "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:34:29");
  computeDAdd((Addr)&temp_var_for_tac_1,
              {(Addr)&x_full, (Addr) &(temp_var_for_const_2 = i)},
              "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:40:19");
  computeDSub((Addr)&temp_var_for_tac_3,
              {(Addr)&ret, (Addr) &(temp_var_for_const_3 = ((double)fret))},
              "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:45:15");
  computeDDiv((Addr)&temp_var_for_tac_4,
              {(Addr)&temp_var_for_tac_3,
               (Addr) &(temp_var_for_const_4 = ((double)fret))},
              "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:45:31");
  AssignF({(Addr) &(temp_var_for_const_5 = (*(eps)))},
          (Addr)&temp_var_for_tac_4,
          "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:45:8");
  ;

  float temp_var_for_ext_0;
  float temp_var_for_const_6;
  temp_var_for_ext_0 = fret;
  AssignF({(Addr)&temp_var_for_ext_0}, (Addr) &(temp_var_for_const_6 = fret),
          "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:48:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

/* Return gamma (X), for positive X less than 42, in the form R *
   2^(*EXP2_ADJ), where R is the return value and *EXP2_ADJ is set to
   avoid overflow or underflow in intermediate calculations.  */

static float gammaf_positive(float x, int *exp2_adj) {
  int local_signgam;

  /* Coefficients B_2k / 2k(2k-1) of x^-(2k-1) inside exp in Stirling's
     approximation to gamma function.  */

  static const float gamma_coeff[] = {0x1.555556p-4f, (double temp_var_for_tac_5;
  double temp_var_for_const_7, temp_var_for_const_8;
  temp_var_for_tac_5 = 0.0 - 0xb.60b61p-12f;

),
                                      0x3.403404p-12f
};

#define NCOEFF (sizeof(gamma_coeff) / sizeof(gamma_coeff[0]))

if (int temp_var_for_tac_6; int temp_var_for_const_9;
    temp_var_for_tac_6 = x < 0.5f;

    ) {
  *exp2_adj = 0;
  float temp_var_for_ext_1;
  float temp_var_for_tac_7, temp_var_for_tac_8;
  float temp_var_for_const_10, temp_var_for_const_11;
  float temp_var_for_callexp_0;

  /*embed fun has found*/
  float temp_var_for_callexp_1;

  temp_var_for_tac_7 = x + 1.0f;

  temp_var_for_callexp_0 =
      __ieee754_lgammaf_r(temp_var_for_tac_7, (&(local_signgam)));
  temp_var_for_callexp_1 = __ieee754_expf(temp_var_for_callexp_0);
  temp_var_for_tac_8 = temp_var_for_callexp_1 / x;

  temp_var_for_ext_1 = temp_var_for_tac_8;
  computeDSub((Addr)&temp_var_for_tac_5,
              {(Addr) &(temp_var_for_const_8 = 0.0),
               (Addr) &(temp_var_for_const_7 = 0xb.60b61p-12f)},
              "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:64:60");
  compute((Addr)&temp_var_for_tac_6,
          {(Addr)&x, (Addr) &(temp_var_for_const_9 = 0.5f)},
          "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:69:9");
  computeFAdd((Addr)&temp_var_for_tac_7,
              {(Addr)&x, (Addr) &(temp_var_for_const_10 = 1.0f)},
              "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:73:46");
  computeFDiv(
      (Addr)&temp_var_for_tac_8,
      {(Addr) &(temp_var_for_const_11 = temp_var_for_callexp_1), (Addr)&x},
      "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:73:71");
  AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_8,
          "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:72:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
} else {
  if (int temp_var_for_tac_9; int temp_var_for_const_12;
      temp_var_for_tac_9 = x <= 1.5f;

      ) {
    *exp2_adj = 0;
    float temp_var_for_ext_2;
    float temp_var_for_const_13;
    float temp_var_for_callexp_2;

    /*embed fun has found*/
    float temp_var_for_callexp_3;

    temp_var_for_callexp_2 = __ieee754_lgammaf_r(x, (&(local_signgam)));
    temp_var_for_callexp_3 = __ieee754_expf(temp_var_for_callexp_2);
    temp_var_for_ext_2 = temp_var_for_callexp_3;
    compute((Addr)&temp_var_for_tac_9,
            {(Addr)&x, (Addr) &(temp_var_for_const_12 = 1.5f)},
            "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:78:11");
    AssignF({(Addr)&temp_var_for_ext_2},
            (Addr) &(temp_var_for_const_13 = temp_var_for_callexp_3),
            "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:81:26");
    ;
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  } else {
    if (int temp_var_for_tac_10; int temp_var_for_const_14;
        temp_var_for_tac_10 = x < 2.5f;

        ) {
      float x_adj = float temp_var_for_tac_11;
      float temp_var_for_const_15;
      temp_var_for_tac_11 = x - 1.0f;

      ;
      *exp2_adj = 0;

      float temp_var_for_ext_3;
      float temp_var_for_tac_12;
      float temp_var_for_const_16;
      float temp_var_for_callexp_4;

      /*embed fun has found*/
      float temp_var_for_callexp_5;

      temp_var_for_callexp_4 = __ieee754_lgammaf_r(x_adj, (&(local_signgam)));
      temp_var_for_callexp_5 = __ieee754_expf(temp_var_for_callexp_4);
      temp_var_for_tac_12 = temp_var_for_callexp_5 * x_adj;

      temp_var_for_ext_3 = temp_var_for_tac_12;
      compute((Addr)&temp_var_for_tac_10,
              {(Addr)&x, (Addr) &(temp_var_for_const_14 = 2.5f)},
              "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:88:13");
      computeFSub((Addr)&temp_var_for_tac_11,
                  {(Addr)&x, (Addr) &(temp_var_for_const_15 = 1.0f)},
                  "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:89:25");
      computeFMul((Addr)&temp_var_for_tac_12,
                  {(Addr) &(temp_var_for_const_16 = temp_var_for_callexp_5),
                   (Addr)&x_adj},
                  "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:94:72");
      AssignF({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_12,
              "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:93:28");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_3;
    } else {
      float eps = 0;
      float x_eps = 0;
      float x_adj = x;
      float prod = 1;
      float exp_adj;
      float x_adj_int;
      float x_adj_frac;
      int x_adj_log2;
      float x_adj_mant;
      float ret;
      float bsum;
      float x_adj2;
      size_t i;

      if (int temp_var_for_tac_13; int temp_var_for_const_17;
          temp_var_for_tac_13 = x < 4.0f;

          ) {
        /* Adjust into the range for applying Stirling's
           approximation.  */
        float n = __ieee754_ceilf(4.0f - x);

        volatile float x_tmp = float temp_var_for_tac_14;
        temp_var_for_tac_14 = x + n;

        ;

        float temp_var_for_const_18;
        x_adj = x_tmp;
        compute((Addr)&temp_var_for_tac_13,
                {(Addr)&x, (Addr) &(temp_var_for_const_17 = 4.0f)},
                "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:114:15");
        computeFAdd((Addr)&temp_var_for_tac_14, {(Addr)&x, (Addr)&n},
                    "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:119:36");
        AssignF({(Addr)&x_adj}, (Addr) &(temp_var_for_const_18 = x_tmp),
                "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:121:17");
        ;
        float temp_var_for_tac_15, temp_var_for_tac_16;
        temp_var_for_tac_15 = x_adj - n;

        temp_var_for_tac_16 = x - temp_var_for_tac_15;

        x_eps = temp_var_for_tac_16;
        computeFSub((Addr)&temp_var_for_tac_15, {(Addr)&x_adj, (Addr)&n},
                    "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:122:31");
        computeFSub((Addr)&temp_var_for_tac_16,
                    {(Addr)&x, (Addr)&temp_var_for_tac_15},
                    "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:122:22");
        AssignF({(Addr)&x_eps}, (Addr)&temp_var_for_tac_16,
                "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:122:17");
        ;
        float temp_var_for_tac_17;
        float temp_var_for_const_19;
        float temp_var_for_callexp_6;

        temp_var_for_tac_17 = x_adj - n;

        temp_var_for_callexp_6 =
            __gamma_productf(temp_var_for_tac_17, x_eps, n, (&(eps)));
        prod = temp_var_for_callexp_6;
        computeFSub((Addr)&temp_var_for_tac_17, {(Addr)&x_adj, (Addr)&n},
                    "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:123:41");
        AssignF({(Addr)&prod},
                (Addr) &(temp_var_for_const_19 = temp_var_for_callexp_6),
                "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:123:16");
        ;
      }
      /* The result is now gamma (X_ADJ + X_EPS) / (PROD * (1 + EPS)).
         Compute gamma (X_ADJ + X_EPS) using Stirling's approximation,
         starting by computing pow (X_ADJ, X_ADJ) with a power of 2
         factored out.  */
      float temp_var_for_tac_18;
      float temp_var_for_const_20;
      temp_var_for_tac_18 = 0.0 - eps;

      exp_adj = temp_var_for_tac_18;
      computeDSub((Addr)&temp_var_for_tac_18,
                  {(Addr) &(temp_var_for_const_20 = 0.0), (Addr)&eps},
                  "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:129:24");
      AssignF({(Addr)&exp_adj}, (Addr)&temp_var_for_tac_18,
              "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:129:17");
      ;
      float temp_var_for_const_21;
      float temp_var_for_callexp_7;

      temp_var_for_callexp_7 = __ieee754_roundf(x_adj);
      x_adj_int = temp_var_for_callexp_7;
      AssignF({(Addr)&x_adj_int},
              (Addr) &(temp_var_for_const_21 = temp_var_for_callexp_7),
              "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:130:19");
      ;
      float temp_var_for_tac_19;
      temp_var_for_tac_19 = x_adj - x_adj_int;

      x_adj_frac = temp_var_for_tac_19;
      computeFSub((Addr)&temp_var_for_tac_19, {(Addr)&x_adj, (Addr)&x_adj_int},
                  "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:131:28");
      AssignF({(Addr)&x_adj_frac}, (Addr)&temp_var_for_tac_19,
              "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:131:20");
      ;
      float temp_var_for_const_22;
      float temp_var_for_callexp_8;

      temp_var_for_callexp_8 = __ieee754_frexpf(x_adj, (&(x_adj_log2)));
      x_adj_mant = temp_var_for_callexp_8;
      AssignF({(Addr)&x_adj_mant},
              (Addr) &(temp_var_for_const_22 = temp_var_for_callexp_8),
              "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:132:20");
      ;

      if (int temp_var_for_tac_20; int temp_var_for_const_23;
          temp_var_for_tac_20 = x_adj_mant < ((float)M_SQRT1_2);

          ) {
        x_adj_log2--;
        x_adj_mant *= 2.0f;
        ;
      }
      *exp2_adj = x_adj_log2 *(int)x_adj_int;
      float temp_var_for_tac_22, temp_var_for_tac_23, temp_var_for_tac_24,
          temp_var_for_tac_25, temp_var_for_tac_26, temp_var_for_tac_27,
          temp_var_for_tac_28, temp_var_for_tac_29;
      float temp_var_for_const_24, temp_var_for_const_25, temp_var_for_const_26,
          temp_var_for_const_27, temp_var_for_const_28, temp_var_for_const_29,
          temp_var_for_const_30, temp_var_for_const_31;
      float temp_var_for_callexp_9;

      float temp_var_for_callexp_10;

      float temp_var_for_callexp_11;

      float temp_var_for_callexp_12;

      temp_var_for_callexp_9 = __ieee754_powf(x_adj_mant, x_adj);
      temp_var_for_tac_22 = x_adj_log2 * x_adj_frac;

      temp_var_for_callexp_10 = __ieee754_exp2f(temp_var_for_tac_22);
      temp_var_for_tac_23 = temp_var_for_callexp_9 * temp_var_for_callexp_10;

      temp_var_for_tac_24 = 0.0 - x_adj;

      temp_var_for_callexp_11 = __ieee754_expf(temp_var_for_tac_24);
      temp_var_for_tac_25 = temp_var_for_tac_23 * temp_var_for_callexp_11;

      temp_var_for_tac_26 = 2.0f * ((float)M_PI);

      temp_var_for_tac_27 = temp_var_for_tac_26 / x_adj;

      temp_var_for_callexp_12 = __ieee754_sqrtf(temp_var_for_tac_27);
      temp_var_for_tac_28 = temp_var_for_tac_25 * temp_var_for_callexp_12;

      temp_var_for_tac_29 = temp_var_for_tac_28 / prod;

      ret = temp_var_for_tac_29;
      compute((Addr)&temp_var_for_tac_20,
              {(Addr)&x_adj_mant,
               (Addr) &(temp_var_for_const_23 = ((float)M_SQRT1_2))},
              "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:134:24");
      computeFMul(
          (Addr)&temp_var_for_tac_22,
          {(Addr) &(temp_var_for_const_24 = x_adj_log2), (Addr)&x_adj_frac},
          "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:140:42");
      computeFMul((Addr)&temp_var_for_tac_23,
                  {(Addr) &(temp_var_for_const_26 = temp_var_for_callexp_9),
                   (Addr) &(temp_var_for_const_25 = temp_var_for_callexp_10)},
                  "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:139:49");
      computeDSub((Addr)&temp_var_for_tac_24,
                  {(Addr) &(temp_var_for_const_27 = 0.0), (Addr)&x_adj},
                  "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:141:35");
      computeFMul((Addr)&temp_var_for_tac_25,
                  {(Addr)&temp_var_for_tac_23,
                   (Addr) &(temp_var_for_const_28 = temp_var_for_callexp_11)},
                  "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:140:56");
      computeFMul((Addr)&temp_var_for_tac_26,
                  {(Addr) &(temp_var_for_const_30 = 2.0f),
                   (Addr) &(temp_var_for_const_29 = ((float)M_PI))},
                  "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:142:36");
      computeFDiv((Addr)&temp_var_for_tac_27,
                  {(Addr)&temp_var_for_tac_26, (Addr)&x_adj},
                  "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:142:50");
      computeFMul((Addr)&temp_var_for_tac_28,
                  {(Addr)&temp_var_for_tac_25,
                   (Addr) &(temp_var_for_const_31 = temp_var_for_callexp_12)},
                  "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:141:45");
      computeFDiv((Addr)&temp_var_for_tac_29,
                  {(Addr)&temp_var_for_tac_28, (Addr)&prod},
                  "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:142:59");
      AssignF({(Addr)&ret}, (Addr)&temp_var_for_tac_29,
              "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:139:13");
      ;
      float temp_var_for_tac_30;
      float temp_var_for_const_32;
      float temp_var_for_callexp_13;

      temp_var_for_callexp_13 = __ieee754_logf(x_adj);
      temp_var_for_tac_30 = x_eps * temp_var_for_callexp_13;

      exp_adj += temp_var_for_tac_30;
      ;
      float temp_var_for_const_33;
      bsum = gamma_coeff[NCOEFF - 1];
      computeFMul((Addr)&temp_var_for_tac_30,
                  {(Addr)&x_eps,
                   (Addr) &(temp_var_for_const_32 = temp_var_for_callexp_13)},
                  "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:143:26");
      AssignF({(Addr)&bsum},
              (Addr) &(temp_var_for_const_33 = gamma_coeff[NCOEFF - 1]),
              "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:144:14");
      ;

      float temp_var_for_tac_32;
      temp_var_for_tac_32 = x_adj * x_adj;

      x_adj2 = temp_var_for_tac_32;
      computeFMul((Addr)&temp_var_for_tac_32, {(Addr)&x_adj, (Addr)&x_adj},
                  "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:146:24");
      AssignF({(Addr)&x_adj2}, (Addr)&temp_var_for_tac_32,
              "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:146:16");
      ;

      for (i = 1; i <= NCOEFF - 1; i++)
        bsum = bsum / x_adj2 + gamma_coeff[NCOEFF - 1 - i];
      float temp_var_for_tac_33;
      temp_var_for_tac_33 = bsum / x_adj;

      exp_adj += temp_var_for_tac_33;
      ;
      float temp_var_for_tac_35;
      float temp_var_for_const_34;
      float temp_var_for_callexp_14;

      temp_var_for_callexp_14 = __ieee754_expm1f(exp_adj);
      temp_var_for_tac_35 = ret * temp_var_for_callexp_14;

      ret += temp_var_for_tac_35;
      ;
      float temp_var_for_ext_4;
      temp_var_for_ext_4 = ret;
      computeFDiv((Addr)&temp_var_for_tac_33, {(Addr)&bsum, (Addr)&x_adj},
                  "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:150:25");
      computeFMul((Addr)&temp_var_for_tac_35,
                  {(Addr)&ret,
                   (Addr) &(temp_var_for_const_34 = temp_var_for_callexp_14)},
                  "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:151:20");
      AssignF({(Addr)&temp_var_for_ext_4}, (Addr)&ret,
              "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:153:28");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_4;
    }
  }
}

#undef NCOEFF
}

float __ieee754_tgammaf_r(float x, int *signgamp) {
  int32_t hx;
  volatile float ret;

  GET_FLOAT_WORD(hx, x);

  if ((hx & IC(0x7fffffff)) == 0) {
    /* Return value for x == 0 is Inf with divide by zero exception.  */
    *signgamp = 0;
    float temp_var_for_ext_5;
    float temp_var_for_tac_37;
    float temp_var_for_const_35;
    temp_var_for_tac_37 = 1.0F / x;

    temp_var_for_ext_5 = temp_var_for_tac_37;
    computeFDiv((Addr)&temp_var_for_tac_37,
                {(Addr) &(temp_var_for_const_35 = 1.0F), (Addr)&x},
                "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:175:31");
    AssignF({(Addr)&temp_var_for_ext_5}, (Addr)&temp_var_for_tac_37,
            "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:175:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_5;
  }
  if (hx < 0 && (uint32_t)hx < UC(0xff800000) && int temp_var_for_tac_38;
      int temp_var_for_const_36; float temp_var_for_callexp_15;

      temp_var_for_callexp_15 = __ieee754_rintf(x);
      temp_var_for_tac_38 = temp_var_for_callexp_15 == x;

      ) {
    /* Return value for integer x < 0 is NaN with invalid exception.  */
    *signgamp = 0;
    float temp_var_for_ext_6;
    float temp_var_for_tac_39, temp_var_for_tac_40, temp_var_for_tac_41;
    temp_var_for_tac_39 = x - x;

    temp_var_for_tac_40 = x - x;

    temp_var_for_tac_41 = temp_var_for_tac_39 / temp_var_for_tac_40;

    temp_var_for_ext_6 = temp_var_for_tac_41;
    compute(
        (Addr)&temp_var_for_tac_38,
        {(Addr) &(temp_var_for_const_36 = temp_var_for_callexp_15), (Addr)&x},
        "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:180:69");
    computeFSub((Addr)&temp_var_for_tac_39, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:184:29");
    computeFSub((Addr)&temp_var_for_tac_40, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:184:39");
    computeFDiv((Addr)&temp_var_for_tac_41,
                {(Addr)&temp_var_for_tac_39, (Addr)&temp_var_for_tac_40},
                "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:184:34");
    AssignF({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_41,
            "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:184:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_6;
  }
  if (hx == IC(0xff800000)) {
    /* x == -Inf.  According to ISO this is NaN.  */
    *signgamp = 0;
    float temp_var_for_ext_7;
    float temp_var_for_tac_42;
    temp_var_for_tac_42 = x - x;

    temp_var_for_ext_7 = temp_var_for_tac_42;
    computeFSub((Addr)&temp_var_for_tac_42, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:193:28");
    AssignF({(Addr)&temp_var_for_ext_7}, (Addr)&temp_var_for_tac_42,
            "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:193:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_7;
  }
  if ((hx & IC(0x7f800000)) == IC(0x7f800000)) {
    /* Positive infinity (return positive infinity) or NaN (return
       NaN).  */
    *signgamp = 0;
    float temp_var_for_ext_8;
    float temp_var_for_tac_43;
    temp_var_for_tac_43 = x + x;

    temp_var_for_ext_8 = temp_var_for_tac_43;
    computeFAdd((Addr)&temp_var_for_tac_43, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:203:28");
    AssignF({(Addr)&temp_var_for_ext_8}, (Addr)&temp_var_for_tac_43,
            "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:203:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_8;
  }

  if (int temp_var_for_tac_44; int temp_var_for_const_37;
      temp_var_for_tac_44 = x >= 36.0f;

      ) {
    /* Overflow.  */
    *signgamp = 0;
    ret = FLT_MAX * FLT_MAX;
    float temp_var_for_ext_9;
    float temp_var_for_const_38;
    temp_var_for_ext_9 = ret;
    compute((Addr)&temp_var_for_tac_44,
            {(Addr)&x, (Addr) &(temp_var_for_const_37 = 36.0f)},
            "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:209:9");
    AssignF({(Addr)&temp_var_for_ext_9}, (Addr) &(temp_var_for_const_38 = ret),
            "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:214:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_9;
  } else {
    SAVE_AND_SET_ROUND(FE_TONEAREST);
    if (int temp_var_for_tac_45; int temp_var_for_const_39;
        temp_var_for_tac_45 = x > 0.0f;

        ) {
      int exp2_adj;
      float tret;

      *signgamp = 0;
      float temp_var_for_const_40;
      float temp_var_for_callexp_16;

      temp_var_for_callexp_16 = gammaf_positive(x, (&(exp2_adj)));
      tret = temp_var_for_callexp_16;
      compute((Addr)&temp_var_for_tac_45,
              {(Addr)&x, (Addr) &(temp_var_for_const_39 = 0.0f)},
              "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:220:11");
      AssignF({(Addr)&tret},
              (Addr) &(temp_var_for_const_40 = temp_var_for_callexp_16),
              "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:225:12");
      ;
      ret = __ieee754_scalbnf(tret, exp2_adj);
    } else {
      if
    }
    (x >= -FLT_EPSILON / 4.0f) {
      *signgamp = 0;
      ret = 1.0f / x;
    }
    else {
      float tx = __ieee754_truncf(x);

      *signgamp = (tx == 2.0f * __ieee754_truncf(tx / 2.0f)) ? -1 : 1;
      if (x <= -42.0f)
        /* Underflow.  */
        ret = FLT_MIN * FLT_MIN;
      else {
        float frac = tx - x;
        float sinpix;
        int exp2_adj;
        float tret;

        if (frac > 0.5f)
          frac = 1.0f - frac;
        sinpix = (frac <= 0.25f ? __ieee754_sinf((float)M_PI * frac)
                                : __ieee754_cosf((float)M_PI * (0.5f - frac)));

        tret = (float)M_PI / (-x * sinpix * gammaf_positive(-x, &exp2_adj));
        ret = __ieee754_scalbnf(tret, -exp2_adj);
      }
    }
    RESTORE_ROUND();
  }
  if (isinf(ret) && int temp_var_for_tac_46; int temp_var_for_const_41;
      temp_var_for_tac_46 = x != 0.0f;

      ) {
    if (*signgamp < 0) {
      ret = -copysignf(FLT_MAX, ret) * FLT_MAX;
      float temp_var_for_ext_10;
      float temp_var_for_tac_47;
      float temp_var_for_const_42, temp_var_for_const_43;
      temp_var_for_tac_47 = 0.0 - ret;

      temp_var_for_ext_10 = temp_var_for_tac_47;
      compute((Addr)&temp_var_for_tac_46,
              {(Addr)&x, (Addr) &(temp_var_for_const_41 = 0.0f)},
              "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:258:23");
      computeDSub((Addr)&temp_var_for_tac_47,
                  {(Addr) &(temp_var_for_const_43 = 0.0),
                   (Addr) &(temp_var_for_const_42 = ret)},
                  "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:262:34");
      AssignF({(Addr)&temp_var_for_ext_10}, (Addr)&temp_var_for_tac_47,
              "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:262:27");
      ; // ret
      /*(ret)(ret)*/
      ret = temp_var_for_ext_10;
    } else {
      ret = copysignf(FLT_MAX, ret) * FLT_MAX;
    }
  } else {
    if (int temp_var_for_tac_48;
        int temp_var_for_const_44, temp_var_for_const_45;
        temp_var_for_tac_48 = ret == 0.0f;

        ) {
      if (*signgamp < 0) {
        ret = -copysignf(FLT_MIN, ret) * FLT_MIN;
        float temp_var_for_ext_11;
        float temp_var_for_tac_49;
        float temp_var_for_const_46, temp_var_for_const_47;
        temp_var_for_tac_49 = 0.0 - ret;

        temp_var_for_ext_11 = temp_var_for_tac_49;
        compute((Addr)&temp_var_for_tac_48,
                {(Addr) &(temp_var_for_const_45 = ret),
                 (Addr) &(temp_var_for_const_44 = 0.0f)},
                "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:269:13");
        computeDSub((Addr)&temp_var_for_tac_49,
                    {(Addr) &(temp_var_for_const_47 = 0.0),
                     (Addr) &(temp_var_for_const_46 = ret)},
                    "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:273:36");
        AssignF({(Addr)&temp_var_for_ext_11}, (Addr)&temp_var_for_tac_49,
                "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:273:29");
        ; // ret
        /*(ret)(ret)*/
        ret = temp_var_for_ext_11;
      } else {
        ret = copysignf(FLT_MIN, ret) * FLT_MIN;
      }
    }
  }

  float temp_var_for_ext_12;
  float temp_var_for_const_48;
  temp_var_for_ext_12 = ret;
  AssignF({(Addr)&temp_var_for_ext_12}, (Addr) &(temp_var_for_const_48 = ret),
          "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:283:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_12", (Addr)&temp_var_for_ext_12));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_12;
}
