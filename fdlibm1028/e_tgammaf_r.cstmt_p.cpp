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
  double x_full = (double)x + (double)x_eps;
  double ret = x_full;
  int i;
  volatile float fret;

  for (i = 1; i < n; i++) {
    ret *= x_full + i;
    double temp_var_for_const_0;
    double temp_var_for_tac_0;
    computeDAdd((Addr)&temp_var_for_tac_0,
                {(Addr) & ((double)x), (Addr) & ((double)x_eps)},
                "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:40:19");
    double temp_var_for_tac_1;
    computeDAdd((Addr)&temp_var_for_tac_1,
                {(Addr)&x_full, (Addr) &(temp_var_for_const_0 = i)},
                "toString(biExpr->getExprLoc())");
  }

  fret = (float)ret;
  AssignF({(Addr)&fret}, (Addr) & ((float)ret),
          "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:43:8");

  *eps = (ret - (double)fret) / (double)fret;
  float temp_var_for_tac_2;
  computeDSub((Addr)&temp_var_for_tac_2, {(Addr)&ret, (Addr) & ((double)fret)},
              "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:45:31");
  computeFDiv((Addr) & (*(eps)),
              {(Addr)&temp_var_for_tac_2, (Addr) & ((double)fret)},
              "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:45:8");

  float temp_var_for_ext_0;
  temp_var_for_ext_0 = fret;
  float temp_var_for_const_1;
  AssignF({(Addr)&temp_var_for_ext_0}, (Addr) &(temp_var_for_const_1 = fret),
          "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:48:22");
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

  static const float gamma_coeff[] = { 0x1.555556p-4f, (0.0 - 0xb.60b61p-12f);
  double temp_var_for_const_2, temp_var_for_const_3;
  , 0x3.403404p-12f
};

#define NCOEFF (sizeof(gamma_coeff) / sizeof(gamma_coeff[0]))

if (x < 0.5f) {
  *exp2_adj = 0;
  float temp_var_for_ext_1;
  temp_var_for_ext_1 =
      __ieee754_expf(__ieee754_lgammaf_r(x + 1.0f, &local_signgam)) / x;
  float temp_var_for_const_4, temp_var_for_const_5;
  float temp_var_for_tac_3, temp_var_for_tac_4;
  computeFAdd((Addr)&temp_var_for_tac_4,
              {(Addr)&x, (Addr) &(temp_var_for_const_4 = 1.0f)},
              "toString(biExpr->getExprLoc())");
  computeFSub((Addr)&temp_var_for_tac_3,
              {(Addr) &(temp_var_for_const_3 = 0.0),
               (Addr) &(temp_var_for_const_2 = 0xb.60b61p-12f)},
              "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:73:46");computeFDiv((Addr)&temp_var_for_ext_1,{(Addr)&(temp_var_for_const_5=__ieee754_expf((__ieee754_lgammaf_r(getFVbyShadow<int>((Addr)&temp_var_for_tac_4), ((&(local_signgam))))),(Addr)&x},"/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:72:24");
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
} else {
  if (x <= 1.5f) {
    *exp2_adj = 0;
    float temp_var_for_ext_2;
    temp_var_for_ext_2 = __ieee754_expf(__ieee754_lgammaf_r(x, &local_signgam));
    float temp_var_for_const_6;AssignF({(Addr)&temp_var_for_ext_2},(Addr)&(temp_var_for_const_6=__ieee754_expf((__ieee754_lgammaf_r(getFVbyShadow<int>((Addr)&x), ((&(local_signgam))))),"/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:81:26");
      callExpStack.push(
          getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_2;
  } else {
    if (x < 2.5f) {
      float x_adj = x - 1.0f;
      float temp_var_for_const_7;
      *exp2_adj = 0;

      float temp_var_for_ext_3;
      temp_var_for_ext_3 =
          __ieee754_expf(__ieee754_lgammaf_r(x_adj, &local_signgam)) * x_adj;
      float temp_var_for_const_8;
      float temp_var_for_tac_5;
      computeFSub((Addr)&temp_var_for_tac_5,
                  {(Addr)&x, (Addr) &(temp_var_for_const_7 = 1.0f)},
                  "toString(biExpr->getExprLoc())");
computeFMul((Addr)&temp_var_for_ext_3,{(Addr)&(temp_var_for_const_8=__ieee754_expf((__ieee754_lgammaf_r(getFVbyShadow<int>((Addr)&x_adj), ((&(local_signgam))))),(Addr)&x_adj},"/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:93:28");
callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
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

      if (x < 4.0f) {
        /* Adjust into the range for applying Stirling's
           approximation.  */
        float n = __ieee754_ceilf(4.0f - x);
        float temp_var_for_const_9;
        ;

        volatile float x_tmp = x + n;
        float temp_var_for_tac_6;
        computeFSub((Addr)&temp_var_for_tac_6,
                    {(Addr) &(temp_var_for_const_9 = 4.0f), (Addr)&x},
                    "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:119:36");

        x_adj = x_tmp;
        computeFAdd((Addr)&x_adj, {(Addr)&x, (Addr)&n},
                    "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:121:17");
        x_eps = (x - (x_adj - n));
        float temp_var_for_tac_7;
        computeFSub((Addr)&temp_var_for_tac_7, {(Addr)&x_adj, (Addr)&n},
                    "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:122:22");
        computeFSub((Addr)&x_eps, {(Addr)&x, (Addr)&temp_var_for_tac_7},
                    "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:122:17");
        prod = __gamma_productf(x_adj - n, x_eps, n, &eps);
        float temp_var_for_tac_8;
        computeFSub((Addr)&temp_var_for_tac_8, {(Addr)&x_adj, (Addr)&n},
                    "toString(biExpr->getExprLoc())");
        float temp_var_for_callexp_0 =
            __gamma_productf(getFVbyShadow<float>((Addr)&temp_var_for_tac_8),
                             getFVbyShadow<float>((Addr)&x_eps),
                             getFVbyShadow<float>((Addr)&n), ((&(eps))));
        CallStackPop((Addr)&temp_var_for_callexp_0,
                     getTop(temp_var_for_callexp_0));
        AssignF({(Addr)&prod}, (Addr)&temp_var_for_callexp_0,
                "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:123:16");
      }
      /* The result is now gamma (X_ADJ + X_EPS) / (PROD * (1 + EPS)).
         Compute gamma (X_ADJ + X_EPS) using Stirling's approximation,
         starting by computing pow (X_ADJ, X_ADJ) with a power of 2
         factored out.  */
      exp_adj = (0.0 - eps);
      float temp_var_for_const_10;
      computeFSub((Addr)&exp_adj,
                  {(Addr) &(temp_var_for_const_10 = 0.0), (Addr)&eps},
                  "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:129:17");
      x_adj_int = __ieee754_roundf(x_adj);
      float temp_var_for_const_11;AssignF({(Addr)&x_adj_int},(Addr)&(temp_var_for_const_11=__ieee754_roundf(getFVbyShadow<int>((Addr)&x_adj)),"/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:130:19");
        x_adj_frac = x_adj - x_adj_int;computeFSub((Addr)&x_adj_frac,{(Addr)&x_adj,(Addr)&x_adj_int},"/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:131:20");
        x_adj_mant = __ieee754_frexpf(x_adj, &x_adj_log2);float temp_var_for_const_12;AssignF({(Addr)&x_adj_mant},(Addr)&(temp_var_for_const_12=__ieee754_frexpf(getFVbyShadow<int>((Addr)&x_adj), ((&(x_adj_log2)))),"/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:132:20");

        if (x_adj_mant < (float)M_SQRT1_2) {
        x_adj_log2--;
        x_adj_mant *= 2.0f;
        }
        *exp2_adj = x_adj_log2 *(int)x_adj_int;
        ret = __ieee754_powf(x_adj_mant, x_adj) *
              __ieee754_exp2f(x_adj_log2 * x_adj_frac) *
              __ieee754_expf(-x_adj) *
              __ieee754_sqrtf(2.0f * (float)M_PI / x_adj) / prod;
        exp_adj += x_eps * __ieee754_logf(x_adj);float temp_var_for_const_13;
        bsum = gamma_coeff[NCOEFF - 1];computeFMul((Addr)&bsum,{(Addr)&x_eps,(Addr)&(temp_var_for_const_13=__ieee754_logf(getFVbyShadow<int>((Addr)&x_adj))},"/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:144:14");

        x_adj2 = x_adj * x_adj;

        for (i = 1; i <= NCOEFF - 1; i++)
          bsum = bsum / x_adj2 + gamma_coeff[NCOEFF - 1 - i];
        exp_adj += bsum / x_adj;
        ret += ret * __ieee754_expm1f(exp_adj);float temp_var_for_const_14;float temp_var_for_tac_9;computeFDiv((Addr)&temp_var_for_tac_9,{(Addr)&bsum,(Addr)&x_adj},"toString(biExpr->getExprLoc())");

        float temp_var_for_ext_4;
        temp_var_for_ext_4 = ret;computeFMul((Addr)&temp_var_for_ext_4,{(Addr)&ret,(Addr)&(temp_var_for_const_14=__ieee754_expm1f(getFVbyShadow<int>((Addr)&exp_adj))},"/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:153:28");
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
    return 1.0F / x;
  }
  if (hx < 0 && (uint32_t)hx < UC(0xff800000) && __ieee754_rintf(x) == x) {
    /* Return value for integer x < 0 is NaN with invalid exception.  */
    *signgamp = 0;
    return (x - x) / (x - x);
  }
  if (hx == IC(0xff800000)) {
    /* x == -Inf.  According to ISO this is NaN.  */
    *signgamp = 0;
    return x - x;
  }
  if ((hx & IC(0x7f800000)) == IC(0x7f800000)) {
    /* Positive infinity (return positive infinity) or NaN (return
       NaN).  */
    *signgamp = 0;
    return x + x;
  }

  if (x >= 36.0f) {
    /* Overflow.  */
    *signgamp = 0;
    ret = FLT_MAX * FLT_MAX;
    float temp_var_for_ext_5;
    temp_var_for_ext_5 = ret;
    float temp_var_for_const_15;
    AssignF({(Addr)&temp_var_for_ext_5}, (Addr) &(temp_var_for_const_15 = ret),
            "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:198:24");
    callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_5;
  } else {
    SAVE_AND_SET_ROUND(FE_TONEAREST);
    if (x > 0.0f) {
      int exp2_adj;
      float tret;

      *signgamp = 0;
      tret = gammaf_positive(x, &exp2_adj);
      float temp_var_for_callexp_1 =
          gammaf_positive(getFVbyShadow<float>((Addr)&x), ((&(exp2_adj))));
      CallStackPop((Addr)&temp_var_for_callexp_1,
                   getTop(temp_var_for_callexp_1));
      AssignF({(Addr)&tret}, ,
              "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:209:12");
      ret = __ieee754_scalbnf(tret, exp2_adj);
      float temp_var_for_const_16;AssignF({(Addr)&ret},(Addr)&(temp_var_for_const_16=__ieee754_scalbnf(getFVbyShadow<int>((Addr)&tret), (exp2_adj)),"/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:210:11");
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
  if (isinf(ret) && x != 0.0f) {
    if (*signgamp < 0) {
      ret = -copysignf(FLT_MAX, ret) * FLT_MAX;
      float temp_var_for_ext_6;
      temp_var_for_ext_6 = (0.0 - ret);
      float temp_var_for_const_17, temp_var_for_const_18;
      computeFSub(
          (Addr)&temp_var_for_ext_6, {(Addr) &(temp_var_for_const_18 = 0.0),
                                      (Addr) &(temp_var_for_const_17 = ret)},
          "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:246:26"); // ret
      /*(ret)(ret)*/
      ret = temp_var_for_ext_6;
      AssignF({(Addr)&ret}, (Addr)&temp_var_for_ext_6,
              "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:248:11");
    } else {
      ret = copysignf(FLT_MAX, ret) * FLT_MAX;
    }
  } else {
    if (ret == 0.0f) {
      if (*signgamp < 0) {
        ret = -copysignf(FLT_MIN, ret) * FLT_MIN;
        float temp_var_for_ext_7;
        temp_var_for_ext_7 = (0.0 - ret);
        float temp_var_for_const_19, temp_var_for_const_20;
        computeFSub(
            (Addr)&temp_var_for_ext_7, {(Addr) &(temp_var_for_const_20 = 0.0),
                                        (Addr) &(temp_var_for_const_19 = ret)},
            "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:257:28"); // ret
        /*(ret)(ret)*/
        ret = temp_var_for_ext_7;
        AssignF({(Addr)&ret}, (Addr)&temp_var_for_ext_7,
                "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:259:13");
      } else {
        ret = copysignf(FLT_MIN, ret) * FLT_MIN;
      }
    }
  }

  float temp_var_for_ext_8;
  temp_var_for_ext_8 = ret;
  float temp_var_for_const_21;
  AssignF({(Addr)&temp_var_for_ext_8}, (Addr) &(temp_var_for_const_21 = ret),
          "/home/shijia/Public/testprogram/e_tgammaf_r.c_e.c:267:22");
  callExpStack.push(getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_8;
}
