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

#ifndef __NO_LONG_DOUBLE_MATH

#ifndef __have_fpu_remquo

long double __ieee754_remquol(long double x, long double p, int *quo) {
  int32_t ex, ep, hx, hp;
  uint32_t sx, lx, lp;
  int cquo;
  int32_t qs;

  static const long double zero = 0.0;

  long double temp_var_for_const_0;
  ew_u.value = x;
  AssignLd({(Addr) &(temp_var_for_const_0 = ew_u.value)}, (Addr)&x,
           "/home/shijia/Public/testprogram/s_remquol.c_e.c:36:3 "
           "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
  ;
  long double temp_var_for_const_1;
  ew_u.value = p;
  AssignLd({(Addr) &(temp_var_for_const_1 = ew_u.value)}, (Addr)&p,
           "/home/shijia/Public/testprogram/s_remquol.c_e.c:37:3 "
           "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
  ;
  sx = ex & 0x8000;
  qs = (sx ^ (ep & 0x8000)) >> 15;
  ep &= IEEE854_LONG_DOUBLE_MAXEXP;
  ex &= IEEE854_LONG_DOUBLE_MAXEXP;

  /* Purge off exception values.  */
  if ((ep | hp | lp) == 0) {
    long double temp_var_for_ext_0;
    long double temp_var_for_tac_0, temp_var_for_tac_1, temp_var_for_tac_2;
    temp_var_for_tac_0 = x * p;

    temp_var_for_tac_1 = x * p;

    temp_var_for_tac_2 = temp_var_for_tac_0 / temp_var_for_tac_1;

    temp_var_for_ext_0 = temp_var_for_tac_2;
    computeLdMul((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&p},
                 "/home/shijia/Public/testprogram/s_remquol.c_e.c:46:29");
    computeLdMul((Addr)&temp_var_for_tac_1, {(Addr)&x, (Addr)&p},
                 "/home/shijia/Public/testprogram/s_remquol.c_e.c:46:39");
    computeLdDiv((Addr)&temp_var_for_tac_2,
                 {(Addr)&temp_var_for_tac_0, (Addr)&temp_var_for_tac_1},
                 "/home/shijia/Public/testprogram/s_remquol.c_e.c:46:34");
    AssignLd({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_2,
             "/home/shijia/Public/testprogram/s_remquol.c_e.c:46:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }
  /* p = 0 */
  if ((ex == IEEE854_LONG_DOUBLE_MAXEXP)     /* x not finite */
      || ((ep == IEEE854_LONG_DOUBLE_MAXEXP) /* p is NaN */
          && ((hp | lp) != 0))) {
    long double temp_var_for_ext_1;
    long double temp_var_for_tac_3, temp_var_for_tac_4, temp_var_for_tac_5;
    temp_var_for_tac_3 = x * p;

    temp_var_for_tac_4 = x * p;

    temp_var_for_tac_5 = temp_var_for_tac_3 / temp_var_for_tac_4;

    temp_var_for_ext_1 = temp_var_for_tac_5;
    computeLdMul((Addr)&temp_var_for_tac_3, {(Addr)&x, (Addr)&p},
                 "/home/shijia/Public/testprogram/s_remquol.c_e.c:56:29");
    computeLdMul((Addr)&temp_var_for_tac_4, {(Addr)&x, (Addr)&p},
                 "/home/shijia/Public/testprogram/s_remquol.c_e.c:56:39");
    computeLdDiv((Addr)&temp_var_for_tac_5,
                 {(Addr)&temp_var_for_tac_3, (Addr)&temp_var_for_tac_4},
                 "/home/shijia/Public/testprogram/s_remquol.c_e.c:56:34");
    AssignLd({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_5,
             "/home/shijia/Public/testprogram/s_remquol.c_e.c:56:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }

  if (ep <= 0x7ffb) {
    long double temp_var_for_tac_6;
    long double temp_var_for_const_2, temp_var_for_const_3;
    long double temp_var_for_callexp_0;

    temp_var_for_tac_6 = 8 * p;

    temp_var_for_callexp_0 = __ieee754_fmodl(x, temp_var_for_tac_6);
    x = temp_var_for_callexp_0;
    computeLdMul((Addr)&temp_var_for_tac_6,
                 {(Addr) &(temp_var_for_const_2 = 8), (Addr)&p},
                 "/home/shijia/Public/testprogram/s_remquol.c_e.c:63:30");
    AssignLd({(Addr)&x},
             (Addr) &(temp_var_for_const_3 = temp_var_for_callexp_0),
             "/home/shijia/Public/testprogram/s_remquol.c_e.c:63:7");
    ;
  }
  /* now x < 8p */

  if (((ex - ep) | (hx - hp) | (lx - lp)) == 0) {
    *quo = qs ? -1 : 1;
    long double temp_var_for_ext_2;
    long double temp_var_for_tac_7;
    long double temp_var_for_const_4;
    temp_var_for_tac_7 = zero * x;

    temp_var_for_ext_2 = temp_var_for_tac_7;
    computeLdMul((Addr)&temp_var_for_tac_7,
                 {(Addr) &(temp_var_for_const_4 = zero), (Addr)&x},
                 "/home/shijia/Public/testprogram/s_remquol.c_e.c:70:31");
    AssignLd({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_7,
             "/home/shijia/Public/testprogram/s_remquol.c_e.c:70:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  }

  long double temp_var_for_ext_3;
  long double temp_var_for_const_5;
  long double temp_var_for_callexp_1;

  temp_var_for_callexp_1 = fabsl(x);
  temp_var_for_ext_3 = temp_var_for_callexp_1;
  AssignLd({(Addr)&temp_var_for_ext_3},
           (Addr) &(temp_var_for_const_5 = temp_var_for_callexp_1),
           "/home/shijia/Public/testprogram/s_remquol.c_e.c:77:22");
  ; // x
  /*(p)(8)(2)(temp)(__ieee754_fabsl(x))*/
  x = temp_var_for_ext_3;
  AssignLd({(Addr)&x}, (Addr)&temp_var_for_ext_3,
           "/home/shijia/Public/testprogram/s_remquol.c_e.c:79:5");
  ;
  long double temp_var_for_ext_4;
  long double temp_var_for_const_6;
  long double temp_var_for_callexp_2;

  temp_var_for_callexp_2 = fabsl(p);
  temp_var_for_ext_4 = temp_var_for_callexp_2;
  AssignLd({(Addr)&temp_var_for_ext_4},
           (Addr) &(temp_var_for_const_6 = temp_var_for_callexp_2),
           "/home/shijia/Public/testprogram/s_remquol.c_e.c:81:22");
  ; // p
  /*(__ieee754_fabsl(p))*/
  p = temp_var_for_ext_4;
  AssignLd({(Addr)&p}, (Addr)&temp_var_for_ext_4,
           "/home/shijia/Public/testprogram/s_remquol.c_e.c:83:5");
  ;
  cquo = 0;

  if (int temp_var_for_tac_8, temp_var_for_tac_9; int temp_var_for_const_7;
      temp_var_for_tac_8 = 4 * p;

      temp_var_for_tac_9 = x >= temp_var_for_tac_8;

      ) {
    long double temp_var_for_tac_10;
    long double temp_var_for_const_8;
    temp_var_for_tac_10 = 4 * p;

    x -= temp_var_for_tac_10;
    ;
    cquo += 4;
  }
  if (int temp_var_for_tac_12, temp_var_for_tac_13; int temp_var_for_const_9;
      temp_var_for_tac_12 = 2 * p;

      temp_var_for_tac_13 = x >= temp_var_for_tac_12;

      ) {
    long double temp_var_for_tac_14;
    long double temp_var_for_const_10;
    temp_var_for_tac_14 = 2 * p;

    x -= temp_var_for_tac_14;
    ;
    cquo += 2;
  }

  if (ep < 0x0002) {
    if (int temp_var_for_tac_16, temp_var_for_tac_17;
        temp_var_for_tac_16 = x + x;

        temp_var_for_tac_17 = temp_var_for_tac_16 > p;

        ) {
      x -= p;
      ;
      ++cquo;
      if (int temp_var_for_tac_19, temp_var_for_tac_20;
          temp_var_for_tac_19 = x + x;

          temp_var_for_tac_20 = temp_var_for_tac_19 >= p;

          ) {
        x -= p;
        ;
        ++cquo;
      }
    }
  } else {
    long double p_half = long double temp_var_for_tac_22;
    long double temp_var_for_const_11;
    temp_var_for_tac_22 = 0.5 * p;

    ;

    if (int temp_var_for_tac_23; temp_var_for_tac_23 = x > p_half;

        ) {
      x -= p;
      ;
      ++cquo;
      if (int temp_var_for_tac_25; temp_var_for_tac_25 = x >= p_half;

          ) {
        x -= p;
        ;
        ++cquo;
      }
    }
  }

  *quo = qs ? -cquo : cquo;

  if (sx) {
    long double temp_var_for_ext_5;
    long double temp_var_for_tac_27;
    long double temp_var_for_const_12;
    temp_var_for_tac_27 = 0.0 - x;

    temp_var_for_ext_5 = temp_var_for_tac_27;
    computeLdMul((Addr)&temp_var_for_tac_8,
                 {(Addr) &(temp_var_for_const_7 = 4), (Addr)&p},
                 "/home/shijia/Public/testprogram/s_remquol.c_e.c:86:14");
    compute((Addr)&temp_var_for_tac_9, {(Addr)&x, (Addr)&temp_var_for_tac_8},
            "/home/shijia/Public/testprogram/s_remquol.c_e.c:86:9");
    computeLdMul((Addr)&temp_var_for_tac_10,
                 {(Addr) &(temp_var_for_const_8 = 4), (Addr)&p},
                 "/home/shijia/Public/testprogram/s_remquol.c_e.c:87:12");
    computeLdMul((Addr)&temp_var_for_tac_12,
                 {(Addr) &(temp_var_for_const_9 = 2), (Addr)&p},
                 "/home/shijia/Public/testprogram/s_remquol.c_e.c:90:14");
    compute((Addr)&temp_var_for_tac_13, {(Addr)&x, (Addr)&temp_var_for_tac_12},
            "/home/shijia/Public/testprogram/s_remquol.c_e.c:90:9");
    computeLdMul((Addr)&temp_var_for_tac_14,
                 {(Addr) &(temp_var_for_const_10 = 2), (Addr)&p},
                 "/home/shijia/Public/testprogram/s_remquol.c_e.c:91:12");
    computeLdAdd((Addr)&temp_var_for_tac_16, {(Addr)&x, (Addr)&x},
                 "/home/shijia/Public/testprogram/s_remquol.c_e.c:96:11");
    compute((Addr)&temp_var_for_tac_17, {(Addr)&temp_var_for_tac_16, (Addr)&p},
            "/home/shijia/Public/testprogram/s_remquol.c_e.c:96:15");
    computeLdAdd((Addr)&temp_var_for_tac_19, {(Addr)&x, (Addr)&x},
                 "/home/shijia/Public/testprogram/s_remquol.c_e.c:99:13");
    compute((Addr)&temp_var_for_tac_20, {(Addr)&temp_var_for_tac_19, (Addr)&p},
            "/home/shijia/Public/testprogram/s_remquol.c_e.c:99:17");
    computeLdMul((Addr)&temp_var_for_tac_22,
                 {(Addr) &(temp_var_for_const_11 = 0.5), (Addr)&p},
                 "/home/shijia/Public/testprogram/s_remquol.c_e.c:105:30");
    compute((Addr)&temp_var_for_tac_23, {(Addr)&x, (Addr)&p_half},
            "/home/shijia/Public/testprogram/s_remquol.c_e.c:107:11");
    compute((Addr)&temp_var_for_tac_25, {(Addr)&x, (Addr)&p_half},
            "/home/shijia/Public/testprogram/s_remquol.c_e.c:110:13");
    computeLdSub((Addr)&temp_var_for_tac_27,
                 {(Addr) &(temp_var_for_const_12 = 0.0), (Addr)&x},
                 "/home/shijia/Public/testprogram/s_remquol.c_e.c:121:31");
    AssignLd({(Addr)&temp_var_for_ext_5}, (Addr)&temp_var_for_tac_27,
             "/home/shijia/Public/testprogram/s_remquol.c_e.c:121:24");
    ; // x
    /*(p)(4)(p)(4)(x)(p)(4)(p)(2)(p)(2)(x)(p)(2)(x)(x)(p)(x)(x)(x)(p)(x)(p)(0.5)(p)(x)(p)(x)(x)(x)*/
    x = temp_var_for_ext_5;
    AssignLd({(Addr)&x}, (Addr)&temp_var_for_ext_5,
             "/home/shijia/Public/testprogram/s_remquol.c_e.c:123:7");
    ;
  }

  long double temp_var_for_ext_6;
  temp_var_for_ext_6 = x;
  AssignLd({(Addr)&temp_var_for_ext_6}, (Addr)&x,
           "/home/shijia/Public/testprogram/s_remquol.c_e.c:127:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_6;
}

#endif

long double __remquol(long double x, long double y, int *quo) {
  long double temp_var_for_ext_7;
  long double temp_var_for_const_13;
  long double temp_var_for_callexp_3;

  temp_var_for_callexp_3 = __ieee754_remquol(x, y, quo);
  temp_var_for_ext_7 = temp_var_for_callexp_3;
  AssignLd({(Addr)&temp_var_for_ext_7},
           (Addr) &(temp_var_for_const_13 = temp_var_for_callexp_3),
           "/home/shijia/Public/testprogram/s_remquol.c_e.c:137:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_7;
}

__typeof(__remquol) remquol __attribute__((weak, alias("__remquol")));

#endif
