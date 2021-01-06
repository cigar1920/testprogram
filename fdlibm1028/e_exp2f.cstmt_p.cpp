#include "../ScDebug/scdebug.h"
/* Single-precision floating point 2^x.
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

/* The basic design here is from
   Shmuel Gal and Boris Bachelis, "An Accurate Elementary Mathematical
   Library for the IEEE Floating Point Standard", ACM Trans. Math. Soft.,
   17 (1), March 1991, pp. 26-45.
   It has been slightly modified to compute 2^x instead of e^x, and for
   single-precision.
   */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_exp2

#undef abs
#define abs(x) ((x) < 0 ? -(x) : (x))

float __ieee754_exp2f(float x) {
  static const float himark = (float)FLT_MAX_EXP;
  static const float lomark = (float)(FLT_MIN_EXP - FLT_MANT_DIG - 1);

  static const volatile float TWOM100 = 7.88860905e-31;
  static const volatile float TWO127 = 1.7014118346e+38;

#include "t_exp2f.h"

  /* Check for usual case.  */
  if (isless(x, himark) && isgreaterequal(x, lomark)) {
    static const float THREEp14 = 49152.0;
    int32_t tval, unsafe;
    float rx, x22, result;
    float ex2_u, scale_u;
    uint32_t exp;

    if (__ieee754_fabsf(x) < FLT_EPSILON / 4.0f)
      return 1.0f + x;

    {
      SAVE_AND_SET_ROUND(FE_TONEAREST);

      /* 1. Argument reduction.
         Choose integers ex, -128 <= t < 128, and some real
         -1/512 <= x1 <= 1/512 so that
         x = ex + t/512 + x1.

         First, calculate rx = ex + t/256.  */
      rx = x + THREEp14;
      float temp_var_for_const_512;
      computeFAdd((Addr)&rx,
                  {(Addr)&x, (Addr) &(temp_var_for_const_512 = THREEp14)},
                  "/home/shijia/Public/testprogram/e_exp2f.c_e.c:66:10");
      rx -= THREEp14;
      x -= rx; /* Compute x=x1. */
               /* Compute tval = (ex*256 + t)+128.
                  Now, t = (tval mod 256)-128 and ex=tval/256  [that's mod, NOT %;
                  and /-round-to-nearest not the usual c integer /].  */
      tval = (int32_t)(rx * 256.0f + 128.0f);

      /* 2. Adjust for accurate table entry.
         Find e so that
         x = ex + t/256 + e + x2
         where -7e-4 < e < 7e-4, and
         (float)(2^(t/256+e))
         is accurate to one part in 2^-64.  */

      /* 'tval & 255' is the same as 'tval%256' except that it's always
         positive.
         Compute x = x2.  */
      x -= __exp2f_deltatable[tval & 255];

      /* 3. Compute ex2 = 2^(t/255+e+ex).  */
      ex2_u = __exp2f_atable[tval & 255];
      tval >>= 8;
      /* x2 is an integer multiple of 2^-30; avoid intermediate
         underflow from the calculation of x22 * x.  */
      unsafe = abs(tval) >= -FLT_MIN_EXP - 32;
      GET_FLOAT_WORD(exp, ex2_u);
      exp =
          ((exp & UC(0x7F800000)) + ((tval >> unsafe) << IEEE754_FLOAT_SHIFT)) |
          (exp & ~UC(0x7F800000));
      SET_FLOAT_WORD(ex2_u, exp);
      exp = UC(0x3f800000) + ((tval - (tval >> unsafe)) << IEEE754_FLOAT_SHIFT);
      SET_FLOAT_WORD(scale_u, exp);

      /* 4. Approximate 2^x2 - 1, using a second-degree polynomial,
         with maximum error in [-2^-9 - 2^-14, 2^-9 + 2^-14]
         less than 1.3e-10.  */

      x22 = (.24022656679f * x + .69314736128f) * ex2_u;
      float temp_var_for_const_513, temp_var_for_const_514;
      float temp_var_for_tac_256, temp_var_for_tac_257;
      computeFMul((Addr)&temp_var_for_tac_256,
                  {(Addr) &(temp_var_for_const_513 = .24022656679f), (Addr)&x},
                  "/home/shijia/Public/testprogram/e_exp2f.c_e.c:104:32");
      computeFAdd((Addr)&temp_var_for_tac_257,
                  {(Addr)&temp_var_for_tac_256,
                   (Addr) &(temp_var_for_const_514 = .69314736128f)},
                  "/home/shijia/Public/testprogram/e_exp2f.c_e.c:104:49");
      computeFMul((Addr)&x22, {(Addr)&temp_var_for_tac_257, (Addr)&ex2_u},
                  "/home/shijia/Public/testprogram/e_exp2f.c_e.c:104:11");
      RESTORE_ROUND();
    }

    /* 5. Return (2^x2-1) * 2^(t/512+e+ex) + 2^(t/512+e+ex).  */
    result = x22 * x + ex2_u;
    float temp_var_for_tac_258;
    computeFMul((Addr)&temp_var_for_tac_258, {(Addr)&x22, (Addr)&x},
                "/home/shijia/Public/testprogram/e_exp2f.c_e.c:109:22");
    computeFAdd((Addr)&result, {(Addr)&temp_var_for_tac_258, (Addr)&ex2_u},
                "/home/shijia/Public/testprogram/e_exp2f.c_e.c:109:12");

    if (!unsafe)
      return result;
    float temp_var_for_ext_0;
    temp_var_for_ext_0 = result * scale_u;
    computeFMul((Addr)&temp_var_for_ext_0, {(Addr)&result, (Addr)&scale_u},
                "/home/shijia/Public/testprogram/e_exp2f.c_e.c:114:24");
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
      float temp_var_for_const_515;
      AssignF({(Addr)&temp_var_for_ext_1}, (Addr) &(temp_var_for_const_515 = 0),
              "/home/shijia/Public/testprogram/e_exp2f.c_e.c:125:26");
      callExpStack.push(
          getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_1;
    }

    /* Underflow */
    float temp_var_for_ext_2;
    temp_var_for_ext_2 = TWOM100 * TWOM100;
    float temp_var_for_const_516, temp_var_for_const_517;
    computeFMul((Addr)&temp_var_for_ext_2,
                {(Addr) &(temp_var_for_const_517 = TWOM100),
                 (Addr) &(temp_var_for_const_516 = TWOM100)},
                "/home/shijia/Public/testprogram/e_exp2f.c_e.c:134:24");
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  }
  /* Return x, if x is a NaN or Inf; or overflow, otherwise.  */
  float temp_var_for_ext_3;
  temp_var_for_ext_3 = TWO127 * x;
  float temp_var_for_const_518;
  computeFMul((Addr)&temp_var_for_ext_3,
              {(Addr) &(temp_var_for_const_518 = TWO127), (Addr)&x},
              "/home/shijia/Public/testprogram/e_exp2f.c_e.c:141:22");
  callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_3;
}

#undef abs

#endif

float __exp2f(float x) {
  float z = __ieee754_exp2f(x);

  if (!isfinite(z) && isfinite(x) && _LIB_VERSION != _IEEE_)
    /* exp2 overflow: 144, exp2 underflow: 145 */
    return __kernel_standard_f(x, x, z, signbit(x) ? KMATHERRF_EXP2_UNDERFLOW
                                                   : KMATHERRF_EXP2_OVERFLOW);

  float temp_var_for_ext_4;
  temp_var_for_ext_4 = z;
  AssignF({(Addr)&temp_var_for_ext_4}, (Addr)&z,
          "/home/shijia/Public/testprogram/e_exp2f.c_e.c:160:22");
  callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_4;
}

__typeof(__exp2f) exp2f __attribute__((weak, alias("__exp2f")));
__typeof(__exp2f) __pow2f __attribute__((alias("__exp2f")));
__typeof(__pow2f) pow2f __attribute__((weak, alias("__pow2f")));
