#include "../ScDebug/scdebug.h"
/* Single-precision floating point e^x.
   Copyright (C) 1997-2013 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by Geoffrey Keating <geoffk@ozemail.com.au>

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

/* How this works:

   The input value, x, is written as

   x = n * ln(2) + t/512 + delta[t] + x;

   where:
   - n is an integer, 127 >= n >= -150;
   - t is an integer, 177 >= t >= -177
   - delta is based on a table entry, delta[t] < 2^-28
   - x is whatever is left, |x| < 2^-10

   Then e^x is approximated as

   e^x = 2^n ( e^(t/512 + delta[t])
               + ( e^(t/512 + delta[t])
                   * ( p(x + delta[t] + n * ln(2)) - delta ) ) )

   where
   - p(x) is a polynomial approximating e(x)-1;
   - e^(t/512 + delta[t]) is obtained from a table.

   The table used is the same one as for the double precision version;
   since we have the table, we might as well use it.

   It turns out to be faster to do calculations in double precision than
   to perform an 'accurate table method' expf, because of the range reduction
   overhead (compare exp2f).
   */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_exp

float __ieee754_expf(float x) {
  static const float himark = 88.72283935546875f;
  static const float lomark = (0.0 - 103.972084045410f);
  double temp_var_for_const_0, temp_var_for_const_1;
  ;

#include "t_expf.h"

  /* Check for usual case.  */
  if (isless(x, himark) && isgreater(x, lomark)) {
    static const float THREEp42 = 13194139533312.0f;
    static const float THREEp22 = 12582912.0f;

    /* 1/ln(2).  */
    static const float m_1_ln2 = 1.44269502163f;

    /* ln(2) */
    static const double m_ln2 = .6931471805599452862;

    int tval;
    volatile double x22, t, result, dx;
    volatile float n, delta;
    double ex2_u;

    {
      int32_t exponent;
      SAVE_AND_SET_ROUND(FE_TONEAREST);

      /* Calculate n.  */
      n = x * m_1_ln2 + THREEp22;
      float temp_var_for_const_358, temp_var_for_const_359;
      float temp_var_for_tac_179;
      computeFMul((Addr)&temp_var_for_tac_179,
                  {(Addr)&x, (Addr) &(temp_var_for_const_358 = m_1_ln2)},
                  "/home/shijia/Public/testprogram/e_expf.c_e.c:83:23");
      computeFAdd((Addr)&n, {(Addr)&temp_var_for_tac_179,
                             (Addr) &(temp_var_for_const_359 = THREEp22)},
                  "/home/shijia/Public/testprogram/e_expf.c_e.c:83:9");
      n -= THREEp22;
      dx = x - n * m_ln2;
      double temp_var_for_const_360, temp_var_for_const_361;
      double temp_var_for_tac_180;
      computeDMul((Addr)&temp_var_for_tac_180,
                  {(Addr) &(temp_var_for_const_361 = n),
                   (Addr) &(temp_var_for_const_360 = m_ln2)},
                  "/home/shijia/Public/testprogram/e_expf.c_e.c:85:14");
      computeDSub((Addr)&dx, {(Addr)&x, (Addr)&temp_var_for_tac_180},
                  "/home/shijia/Public/testprogram/e_expf.c_e.c:85:10");

      /* Calculate t/512.  */
      t = dx + THREEp42;
      double temp_var_for_const_362, temp_var_for_const_363;
      computeDAdd((Addr)&t, {(Addr) &(temp_var_for_const_363 = dx),
                             (Addr) &(temp_var_for_const_362 = THREEp42)},
                  "/home/shijia/Public/testprogram/e_expf.c_e.c:88:9");
      t -= THREEp42;
      dx -= t;

      /* Compute tval = t. */
      tval = (int)(t * 512.0);
      double temp_var_for_const_364, temp_var_for_const_365;
      ;

      if (t >= 0) {
        delta = (0.0 - __exp_deltatable[tval]);
        float temp_var_for_const_366, temp_var_for_const_367;
        float temp_var_for_tac_181;
        computeDMul((Addr)&temp_var_for_tac_181,
                    {(Addr) &(temp_var_for_const_365 = t),
                     (Addr) &(temp_var_for_const_364 = 512.0)},
                    "/home/shijia/Public/testprogram/e_expf.c_e.c:96:22");
        computeFSub((Addr)&delta,
                    {(Addr) &(temp_var_for_const_367 = 0.0),
                     (Addr) &(temp_var_for_const_366 = __exp_deltatable[tval])},
                    "/home/shijia/Public/testprogram/e_expf.c_e.c:96:15");
      }

      else {
        delta = __exp_deltatable[-tval];
        float temp_var_for_const_368;
        AssignF({(Addr)&delta},
                (Addr) &(temp_var_for_const_368 = __exp_deltatable[(-(tval))]),
                "/home/shijia/Public/testprogram/e_expf.c_e.c:100:15");
      }

      /* Compute ex2 = 2^n e^(t/512+delta[t]).  */
      ex2_u = __exp_atable[tval + 177];
      double temp_var_for_const_369;
      AssignD({(Addr)&ex2_u},
              (Addr) &(temp_var_for_const_369 = __exp_atable[tval + 177]),
              "/home/shijia/Public/testprogram/e_expf.c_e.c:104:13");
      GET_HIGH_WORD(exponent, ex2_u);
      exponent += ((int32_t)n) << IEEE754_DOUBLE_SHIFT;
      SET_HIGH_WORD(ex2_u, exponent);

      /* Approximate e^(dx+delta) - 1, using a second-degree polynomial,
         with maximum error in [-2^-10-2^-28,2^-10+2^-28]
         less than 5e-11.  */
      x22 = (0.5000000496709180453 * dx + 1.0000001192102037084) * dx + delta;
      double temp_var_for_const_370, temp_var_for_const_371,
          temp_var_for_const_372, temp_var_for_const_373,
          temp_var_for_const_374;
      double temp_var_for_tac_182, temp_var_for_tac_183, temp_var_for_tac_184;
      computeDMul((Addr)&temp_var_for_tac_182,
                  {(Addr) &(temp_var_for_const_371 = 0.5000000496709180453),
                   (Addr) &(temp_var_for_const_370 = dx)},
                  "/home/shijia/Public/testprogram/e_expf.c_e.c:112:41");
      computeDAdd((Addr)&temp_var_for_tac_183,
                  {(Addr)&temp_var_for_tac_182,
                   (Addr) &(temp_var_for_const_372 = 1.0000001192102037084)},
                  "/home/shijia/Public/testprogram/e_expf.c_e.c:112:66");
      computeDMul(
          (Addr)&temp_var_for_tac_184,
          {(Addr)&temp_var_for_tac_183, (Addr) &(temp_var_for_const_373 = dx)},
          "/home/shijia/Public/testprogram/e_expf.c_e.c:112:71");
      RESTORE_ROUND();
      double temp_var_for_tac_185;
      computeDAdd((Addr)&temp_var_for_tac_185,
                  {(Addr)&temp_var_for_tac_184,
                   (Addr) &(temp_var_for_const_374 = delta)},
                  "toString(biExpr->getExprLoc())");
    }

    /* Return result.  */
    result = x22 * ex2_u + ex2_u;
    double temp_var_for_const_375;
    double temp_var_for_tac_186;
    computeDMul((Addr)&temp_var_for_tac_186,
                {(Addr) &(temp_var_for_const_375 = x22), (Addr)&ex2_u},
                "/home/shijia/Public/testprogram/e_expf.c_e.c:117:26");
    computeDAdd((Addr)&result, {(Addr)&temp_var_for_tac_186, (Addr)&ex2_u},
                "/home/shijia/Public/testprogram/e_expf.c_e.c:117:12");
    float temp_var_for_ext_0;
    temp_var_for_ext_0 = (float)result;
    AssignF({(Addr)&temp_var_for_ext_0}, (Addr) & ((float)result),
            "/home/shijia/Public/testprogram/e_expf.c_e.c:119:24");
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }
  /* Exceptional cases:  */
  if (isless(x, himark)) {
    if (isinf(x))
    /* e^-inf == 0, with no error.  */
    {
      float temp_var_for_ext_1;
      temp_var_for_ext_1 = 0;
      float temp_var_for_const_376;
      AssignF({(Addr)&temp_var_for_ext_1}, (Addr) &(temp_var_for_const_376 = 0),
              "/home/shijia/Public/testprogram/e_expf.c_e.c:130:26");
      callExpStack.push(
          getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_1;
    }

    /* Underflow */
    feraiseexcept(FE_UNDERFLOW);
    float temp_var_for_ext_2;
    temp_var_for_ext_2 = 0;
    float temp_var_for_const_377;
    AssignF({(Addr)&temp_var_for_ext_2}, (Addr) &(temp_var_for_const_377 = 0),
            "/home/shijia/Public/testprogram/e_expf.c_e.c:140:24");
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  }
  /* Return x, if x is a NaN or Inf; or overflow, otherwise.  */
  if (isinf(x))
    return HUGE_VALF;
  if (isnan(x)) {
    float temp_var_for_ext_3;
    temp_var_for_ext_3 = x;
    AssignF({(Addr)&temp_var_for_ext_3}, (Addr)&x,
            "/home/shijia/Public/testprogram/e_expf.c_e.c:150:24");
    callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_3;
  }

  feraiseexcept(FE_OVERFLOW);
  return HUGE_VALF;
}

#endif

/* wrapper exp */
float __expf(float x) {
  float z = __ieee754_expf(x);

  if ((!isfinite(z) || z == 0.0f) && isfinite(x) && _LIB_VERSION != _IEEE_)
    return __kernel_standard_f(x, x, z, signbit(x) ? KMATHERRF_EXP_UNDERFLOW
                                                   : KMATHERRF_EXP_OVERFLOW);

  float temp_var_for_ext_4;
  temp_var_for_ext_4 = z;
  AssignF({(Addr)&temp_var_for_ext_4}, (Addr)&z,
          "/home/shijia/Public/testprogram/e_expf.c_e.c:171:22");
  callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_4;
}

__typeof(__expf) expf __attribute__((weak, alias("__expf")));
