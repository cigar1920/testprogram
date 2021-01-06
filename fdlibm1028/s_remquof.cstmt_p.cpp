#include "../ScDebug/scdebug.h"
/* Compute remainder and a congruent to the quotient.
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

#ifndef __have_fpu_remquo

float __ieee754_remquof(float x, float y, int *quo) {
  int32_t hx, hy;
  uint32_t sx;
  int cquo;
  int32_t qs;

  static const float zero = 0.0;

  GET_FLOAT_WORD(hx, x);
  GET_FLOAT_WORD(hy, y);
  sx = hx & IC(0x80000000);
  qs = sx ^ (hy & IC(0x80000000));
  hy &= IC(0x7fffffff);
  hx &= IC(0x7fffffff);

  /* Purge off exception values.  */
  if (hy == 0)
    return (x * y) / (x * y);   /* y = 0 */
  if ((hx >= IC(0x7f800000))    /* x not finite */
      || (hy > IC(0x7f800000))) /* y is NaN */
    return (x * y) / (x * y);

  if (hy <= IC(0x7dffffff))
    x = __ieee754_fmodf(x, 8 * y); /* now x < 8y */

  if ((hx - hy) == 0) {
    *quo = qs ? -1 : 1;
    return zero * x;
  }

  float temp_var_for_ext_0;
  temp_var_for_ext_0 = __ieee754_fabsf(x);
  float temp_var_for_const_0;AssignF({(Addr)&temp_var_for_ext_0},(Addr)&(temp_var_for_const_0=__ieee754_fabsf(getFVbyShadow<int>((Addr)&x)),"/home/shijia/Public/testprogram/s_remquof.c_e.c:57:22"); // x
  /*(__ieee754_fabsf(x))*/
  x = temp_var_for_ext_0;AssignF({(Addr)&x},(Addr)&temp_var_for_ext_0,"/home/shijia/Public/testprogram/s_remquof.c_e.c:59:5");
  float temp_var_for_ext_1;
  temp_var_for_ext_1 = __ieee754_fabsf(y);float temp_var_for_const_1;AssignF({(Addr)&temp_var_for_ext_1},(Addr)&(temp_var_for_const_1=__ieee754_fabsf(getFVbyShadow<int>((Addr)&y)),"/home/shijia/Public/testprogram/s_remquof.c_e.c:61:22"); // y
  /*(__ieee754_fabsf(y))*/
  y = temp_var_for_ext_1;AssignF({(Addr)&y},(Addr)&temp_var_for_ext_1,"/home/shijia/Public/testprogram/s_remquof.c_e.c:63:5");
  cquo = 0;

  if (x >= 4 * y);float temp_var_for_const_2; {
    x -= 4 * y;
    float temp_var_for_const_3;
    float temp_var_for_tac_0;
    computeFMul((Addr)&temp_var_for_tac_0,
                {(Addr) &(temp_var_for_const_2 = 4), (Addr)&y},
                "/home/shijia/Public/testprogram/s_remquof.c_e.c:67:12");
    cquo += 4;
    float temp_var_for_tac_1;
    computeFMul((Addr)&temp_var_for_tac_1,
                {(Addr) &(temp_var_for_const_3 = 4), (Addr)&y},
                "toString(biExpr->getExprLoc())");}
  if (x >= 2 * y);float temp_var_for_const_4; {
    x -= 2 * y;
    float temp_var_for_const_5;
    float temp_var_for_tac_2;
    computeFMul((Addr)&temp_var_for_tac_2,
                {(Addr) &(temp_var_for_const_4 = 2), (Addr)&y},
                "/home/shijia/Public/testprogram/s_remquof.c_e.c:71:12");
    cquo += 2;
    float temp_var_for_tac_3;
    computeFMul((Addr)&temp_var_for_tac_3,
                {(Addr) &(temp_var_for_const_5 = 2), (Addr)&y},
                "toString(biExpr->getExprLoc())");}

  if (hy < IC(0x01000000)) {
    if (x + x > y) {
      x -= y;
      ++cquo;
      if (x + x >= y) {
        x -= y;
        ++cquo;
      }
    }
  } else {
    float y_half = 0.5 * y;

    if (x > y_half) {
      x -= y;
      ++cquo;
      if (x >= y_half) {
        x -= y;
        ++cquo;
      }
    }
  }

  *quo = qs ? -cquo : cquo;

  if (sx)
    x = -x;
  float temp_var_for_ext_2;
  temp_var_for_ext_2 = x;AssignF({(Addr)&temp_var_for_ext_2},(Addr)&x,"/home/shijia/Public/testprogram/s_remquof.c_e.c:102:22");
  callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_2;
}

#endif

float __remquof(float x, float y, int *quo) {
  float temp_var_for_ext_3;
  temp_var_for_ext_3 = __ieee754_remquof(x, y, quo);
  float temp_var_for_callexp_0 = __ieee754_remquof(
      getFVbyShadow<float>((Addr)&x), getFVbyShadow<float>((Addr)&y), (quo));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  AssignF({(Addr)&temp_var_for_ext_3}, ,
          "/home/shijia/Public/testprogram/s_remquof.c_e.c:112:22");
  callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_3;
}

__typeof(__remquof) remquof __attribute__((weak, alias("__remquof")));
