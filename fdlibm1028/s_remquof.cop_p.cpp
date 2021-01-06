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
  if (hy == 0) {
    float temp_var_for_ext_0;
    float temp_var_for_tac_0, temp_var_for_tac_1, temp_var_for_tac_2;
    temp_var_for_tac_0 = x * y;

    temp_var_for_tac_1 = x * y;

    temp_var_for_tac_2 = temp_var_for_tac_0 / temp_var_for_tac_1;

    temp_var_for_ext_0 = temp_var_for_tac_2;
    computeFMul((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&y},
                "/home/shijia/Public/testprogram/s_remquof.c_e.c:44:29");
    computeFMul((Addr)&temp_var_for_tac_1, {(Addr)&x, (Addr)&y},
                "/home/shijia/Public/testprogram/s_remquof.c_e.c:44:39");
    computeFDiv((Addr)&temp_var_for_tac_2,
                {(Addr)&temp_var_for_tac_0, (Addr)&temp_var_for_tac_1},
                "/home/shijia/Public/testprogram/s_remquof.c_e.c:44:34");
    AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_2,
            "/home/shijia/Public/testprogram/s_remquof.c_e.c:44:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }
  /* y = 0 */
  if ((hx >= IC(0x7f800000))    /* x not finite */
      || (hy > IC(0x7f800000))) /* y is NaN */
  {
    float temp_var_for_ext_1;
    float temp_var_for_tac_3, temp_var_for_tac_4, temp_var_for_tac_5;
    temp_var_for_tac_3 = x * y;

    temp_var_for_tac_4 = x * y;

    temp_var_for_tac_5 = temp_var_for_tac_3 / temp_var_for_tac_4;

    temp_var_for_ext_1 = temp_var_for_tac_5;
    computeFMul((Addr)&temp_var_for_tac_3, {(Addr)&x, (Addr)&y},
                "/home/shijia/Public/testprogram/s_remquof.c_e.c:54:29");
    computeFMul((Addr)&temp_var_for_tac_4, {(Addr)&x, (Addr)&y},
                "/home/shijia/Public/testprogram/s_remquof.c_e.c:54:39");
    computeFDiv((Addr)&temp_var_for_tac_5,
                {(Addr)&temp_var_for_tac_3, (Addr)&temp_var_for_tac_4},
                "/home/shijia/Public/testprogram/s_remquof.c_e.c:54:34");
    AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_5,
            "/home/shijia/Public/testprogram/s_remquof.c_e.c:54:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }

  if (hy <= IC(0x7dffffff)) {
    float temp_var_for_tac_6;
    float temp_var_for_const_0, temp_var_for_const_1;
    float temp_var_for_callexp_0;

    temp_var_for_tac_6 = 8 * y;

    temp_var_for_callexp_0 = __ieee754_fmodf(x, temp_var_for_tac_6);
    x = temp_var_for_callexp_0;
    computeFMul((Addr)&temp_var_for_tac_6,
                {(Addr) &(temp_var_for_const_0 = 8), (Addr)&y},
                "/home/shijia/Public/testprogram/s_remquof.c_e.c:61:30");
    AssignF({(Addr)&x}, (Addr) &(temp_var_for_const_1 = temp_var_for_callexp_0),
            "/home/shijia/Public/testprogram/s_remquof.c_e.c:61:7");
    ;
  }
  /* now x < 8y */

  if ((hx - hy) == 0) {
    *quo = qs ? -1 : 1;
    float temp_var_for_ext_2;
    float temp_var_for_tac_7;
    float temp_var_for_const_2;
    temp_var_for_tac_7 = zero * x;

    temp_var_for_ext_2 = temp_var_for_tac_7;
    computeFMul((Addr)&temp_var_for_tac_7,
                {(Addr) &(temp_var_for_const_2 = zero), (Addr)&x},
                "/home/shijia/Public/testprogram/s_remquof.c_e.c:68:31");
    AssignF({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_7,
            "/home/shijia/Public/testprogram/s_remquof.c_e.c:68:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  }

  float temp_var_for_ext_3;
  float temp_var_for_const_3;
  float temp_var_for_callexp_1;

  temp_var_for_callexp_1 = fabsf(x);
  temp_var_for_ext_3 = temp_var_for_callexp_1;
  AssignF({(Addr)&temp_var_for_ext_3},
          (Addr) &(temp_var_for_const_3 = temp_var_for_callexp_1),
          "/home/shijia/Public/testprogram/s_remquof.c_e.c:75:22");
  ; // x
  /*(y)(8)(2)(temp)(__ieee754_fabsf(x))*/
  x = temp_var_for_ext_3;
  AssignF({(Addr)&x}, (Addr)&temp_var_for_ext_3,
          "/home/shijia/Public/testprogram/s_remquof.c_e.c:77:5");
  ;
  float temp_var_for_ext_4;
  float temp_var_for_const_4;
  float temp_var_for_callexp_2;

  temp_var_for_callexp_2 = fabsf(y);
  temp_var_for_ext_4 = temp_var_for_callexp_2;
  AssignF({(Addr)&temp_var_for_ext_4},
          (Addr) &(temp_var_for_const_4 = temp_var_for_callexp_2),
          "/home/shijia/Public/testprogram/s_remquof.c_e.c:79:22");
  ; // y
  /*(__ieee754_fabsf(y))*/
  y = temp_var_for_ext_4;
  AssignF({(Addr)&y}, (Addr)&temp_var_for_ext_4,
          "/home/shijia/Public/testprogram/s_remquof.c_e.c:81:5");
  ;
  cquo = 0;

  if (int temp_var_for_tac_8, temp_var_for_tac_9; int temp_var_for_const_5;
      temp_var_for_tac_8 = 4 * y;

      temp_var_for_tac_9 = x >= temp_var_for_tac_8;

      ) {
    float temp_var_for_tac_10;
    float temp_var_for_const_6;
    temp_var_for_tac_10 = 4 * y;

    x -= temp_var_for_tac_10;
    ;
    cquo += 4;
  }
  if (int temp_var_for_tac_12, temp_var_for_tac_13; int temp_var_for_const_7;
      temp_var_for_tac_12 = 2 * y;

      temp_var_for_tac_13 = x >= temp_var_for_tac_12;

      ) {
    float temp_var_for_tac_14;
    float temp_var_for_const_8;
    temp_var_for_tac_14 = 2 * y;

    x -= temp_var_for_tac_14;
    ;
    cquo += 2;
  }

  if (hy < IC(0x01000000)) {
    if (int temp_var_for_tac_16, temp_var_for_tac_17;
        temp_var_for_tac_16 = x + x;

        temp_var_for_tac_17 = temp_var_for_tac_16 > y;

        ) {
      x -= y;
      ;
      ++cquo;
      if (int temp_var_for_tac_19, temp_var_for_tac_20;
          temp_var_for_tac_19 = x + x;

          temp_var_for_tac_20 = temp_var_for_tac_19 >= y;

          ) {
        x -= y;
        ;
        ++cquo;
      }
    }
  } else {
    float y_half = double temp_var_for_tac_22;
    double temp_var_for_const_9;
    temp_var_for_tac_22 = 0.5 * y;

    ;

    if (int temp_var_for_tac_23; temp_var_for_tac_23 = x > y_half;

        ) {
      x -= y;
      ;
      ++cquo;
      if (int temp_var_for_tac_25; temp_var_for_tac_25 = x >= y_half;

          ) {
        x -= y;
        ;
        ++cquo;
      }
    }
  }

  *quo = qs ? -cquo : cquo;

  if (sx) {
    float temp_var_for_ext_5;
    float temp_var_for_tac_27;
    float temp_var_for_const_10;
    temp_var_for_tac_27 = 0.0 - x;

    temp_var_for_ext_5 = temp_var_for_tac_27;
    computeFMul((Addr)&temp_var_for_tac_8,
                {(Addr) &(temp_var_for_const_5 = 4), (Addr)&y},
                "/home/shijia/Public/testprogram/s_remquof.c_e.c:84:14");
    compute((Addr)&temp_var_for_tac_9, {(Addr)&x, (Addr)&temp_var_for_tac_8},
            "/home/shijia/Public/testprogram/s_remquof.c_e.c:84:9");
    computeFMul((Addr)&temp_var_for_tac_10,
                {(Addr) &(temp_var_for_const_6 = 4), (Addr)&y},
                "/home/shijia/Public/testprogram/s_remquof.c_e.c:85:12");
    computeFMul((Addr)&temp_var_for_tac_12,
                {(Addr) &(temp_var_for_const_7 = 2), (Addr)&y},
                "/home/shijia/Public/testprogram/s_remquof.c_e.c:88:14");
    compute((Addr)&temp_var_for_tac_13, {(Addr)&x, (Addr)&temp_var_for_tac_12},
            "/home/shijia/Public/testprogram/s_remquof.c_e.c:88:9");
    computeFMul((Addr)&temp_var_for_tac_14,
                {(Addr) &(temp_var_for_const_8 = 2), (Addr)&y},
                "/home/shijia/Public/testprogram/s_remquof.c_e.c:89:12");
    computeFAdd((Addr)&temp_var_for_tac_16, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/s_remquof.c_e.c:94:11");
    compute((Addr)&temp_var_for_tac_17, {(Addr)&temp_var_for_tac_16, (Addr)&y},
            "/home/shijia/Public/testprogram/s_remquof.c_e.c:94:15");
    computeFAdd((Addr)&temp_var_for_tac_19, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/s_remquof.c_e.c:97:13");
    compute((Addr)&temp_var_for_tac_20, {(Addr)&temp_var_for_tac_19, (Addr)&y},
            "/home/shijia/Public/testprogram/s_remquof.c_e.c:97:17");
    computeDMul((Addr)&temp_var_for_tac_22,
                {(Addr) &(temp_var_for_const_9 = 0.5), (Addr)&y},
                "/home/shijia/Public/testprogram/s_remquof.c_e.c:103:24");
    compute((Addr)&temp_var_for_tac_23, {(Addr)&x, (Addr)&y_half},
            "/home/shijia/Public/testprogram/s_remquof.c_e.c:105:11");
    compute((Addr)&temp_var_for_tac_25, {(Addr)&x, (Addr)&y_half},
            "/home/shijia/Public/testprogram/s_remquof.c_e.c:108:13");
    computeDSub((Addr)&temp_var_for_tac_27,
                {(Addr) &(temp_var_for_const_10 = 0.0), (Addr)&x},
                "/home/shijia/Public/testprogram/s_remquof.c_e.c:119:31");
    AssignF({(Addr)&temp_var_for_ext_5}, (Addr)&temp_var_for_tac_27,
            "/home/shijia/Public/testprogram/s_remquof.c_e.c:119:24");
    ; // x
    /*(y)(4)(y)(4)(x)(y)(4)(y)(2)(y)(2)(x)(y)(2)(x)(x)(y)(x)(x)(x)(y)(x)(y)(0.5)(y)(x)(y)(x)(x)(x)*/
    x = temp_var_for_ext_5;
    AssignF({(Addr)&x}, (Addr)&temp_var_for_ext_5,
            "/home/shijia/Public/testprogram/s_remquof.c_e.c:121:7");
    ;
  }

  float temp_var_for_ext_6;
  temp_var_for_ext_6 = x;
  AssignF({(Addr)&temp_var_for_ext_6}, (Addr)&x,
          "/home/shijia/Public/testprogram/s_remquof.c_e.c:125:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_6;
}

#endif

float __remquof(float x, float y, int *quo) {
  float temp_var_for_ext_7;
  float temp_var_for_const_11;
  float temp_var_for_callexp_3;

  temp_var_for_callexp_3 = __ieee754_remquof(x, y, quo);
  temp_var_for_ext_7 = temp_var_for_callexp_3;
  AssignF({(Addr)&temp_var_for_ext_7},
          (Addr) &(temp_var_for_const_11 = temp_var_for_callexp_3),
          "/home/shijia/Public/testprogram/s_remquof.c_e.c:135:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_7;
}

__typeof(__remquof) remquof __attribute__((weak, alias("__remquof")));
