#include "../ScDebug/scdebug.h"
/* Emulation for sqrtl.
   Contributed by Paolo Bonzini

   Copyright 2002-2003, 2007, 2009-2013 Free Software Foundation, Inc.

   This file was taken from gnulib.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2.1 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

#ifndef __have_fpu_sqrt

/* A simple Newton-Raphson method. */
long double __ieee754_sqrtl(long double x) {
  long double delta, y;
  int exponent;

  /* Check for NaN */
  if (isnanl(x)) {
    long double temp_var_for_ext_0;
    temp_var_for_ext_0 = x;
    AssignLd({(Addr)&temp_var_for_ext_0}, (Addr)&x,
             "/home/shijia/Public/testprogram/e_sqrtl.c_e.c:37:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  /* Check for negative numbers */
  if (int temp_var_for_tac_0; int temp_var_for_const_0;
      temp_var_for_tac_0 = x < 0.0L;

      ) {
    long double temp_var_for_ext_1;
    long double temp_var_for_const_1;
    temp_var_for_callexp_0 = sqrt((-(1)));
    temp_var_for_ext_1 = ((long double)temp_var_for_callexp_0);
    compute((Addr)&temp_var_for_tac_0,
            {(Addr)&x, (Addr) &(temp_var_for_const_0 = 0.0L)},
            "/home/shijia/Public/testprogram/e_sqrtl.c_e.c:44:9");
    AssignLd(
        {(Addr)&temp_var_for_ext_1},
        (Addr) &(temp_var_for_const_1 = ((long double)temp_var_for_callexp_0)),
        "/home/shijia/Public/testprogram/e_sqrtl.c_e.c:46:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }

  /* Check for zero and infinites */
  if (int temp_var_for_tac_1, temp_var_for_tac_2; temp_var_for_tac_1 = x + x;

      temp_var_for_tac_2 = temp_var_for_tac_1 == x;

      ) {
    long double temp_var_for_ext_2;
    temp_var_for_ext_2 = x;
    computeLdAdd((Addr)&temp_var_for_tac_1, {(Addr)&x, (Addr)&x},
                 "/home/shijia/Public/testprogram/e_sqrtl.c_e.c:53:9");
    compute((Addr)&temp_var_for_tac_2, {(Addr)&temp_var_for_tac_1, (Addr)&x},
            "/home/shijia/Public/testprogram/e_sqrtl.c_e.c:53:13");
    AssignLd({(Addr)&temp_var_for_ext_2}, (Addr)&x,
             "/home/shijia/Public/testprogram/e_sqrtl.c_e.c:55:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  }

  __ieee754_frexpl(x, &exponent);
  long double temp_var_for_tac_3;
  long double temp_var_for_const_2, temp_var_for_const_3, temp_var_for_const_4;
  long double temp_var_for_callexp_1;

  temp_var_for_tac_3 = (-(exponent)) / 2;

  temp_var_for_callexp_1 = __ieee754_ldexpl(x, temp_var_for_tac_3);
  y = temp_var_for_callexp_1;
  computeDiv((Addr)&temp_var_for_tac_3,
             {(Addr) &(temp_var_for_const_3 = (-(exponent))),
              (Addr) &(temp_var_for_const_2 = 2)},
             "/home/shijia/Public/testprogram/e_sqrtl.c_e.c:62:37");
  AssignLd({(Addr)&y}, (Addr) &(temp_var_for_const_4 = temp_var_for_callexp_1),
           "/home/shijia/Public/testprogram/e_sqrtl.c_e.c:62:5");
  ;

  int temp_var_for_ext_3;
  do {
    delta = y;
    long double temp_var_for_ext_4;
    long double temp_var_for_tac_4, temp_var_for_tac_5, temp_var_for_tac_6;
    long double temp_var_for_const_5;
    temp_var_for_tac_4 = x / y;

    temp_var_for_tac_5 = y + temp_var_for_tac_4;

    temp_var_for_tac_6 = temp_var_for_tac_5 * 0.5L;

    temp_var_for_ext_4 = temp_var_for_tac_6;
    computeLdDiv((Addr)&temp_var_for_tac_4, {(Addr)&x, (Addr)&y},
                 "/home/shijia/Public/testprogram/e_sqrtl.c_e.c:68:33");
    computeLdAdd((Addr)&temp_var_for_tac_5,
                 {(Addr)&y, (Addr)&temp_var_for_tac_4},
                 "/home/shijia/Public/testprogram/e_sqrtl.c_e.c:68:29");
    computeLdMul(
        (Addr)&temp_var_for_tac_6,
        {(Addr)&temp_var_for_tac_5, (Addr) &(temp_var_for_const_5 = 0.5L)},
        "/home/shijia/Public/testprogram/e_sqrtl.c_e.c:68:38");
    AssignLd({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_6,
             "/home/shijia/Public/testprogram/e_sqrtl.c_e.c:68:24");
    ; // y
    /*(0.5L)(y)(x)(y)*/
    y = temp_var_for_ext_4;
    AssignLd({(Addr)&y}, (Addr)&temp_var_for_ext_4,
             "/home/shijia/Public/testprogram/e_sqrtl.c_e.c:70:7");
    ;
    delta -= y;
    ;
    temp_var_for_ext_3 = int temp_var_for_tac_8;
    int temp_var_for_const_6;
    temp_var_for_tac_8 = delta != 0.0L;

    ;
  } while (temp_var_for_ext_3);

  long double temp_var_for_ext_5;
  temp_var_for_ext_5 = y;
  compute((Addr)&temp_var_for_tac_8,
          {(Addr)&delta, (Addr) &(temp_var_for_const_6 = 0.0L)},
          "/home/shijia/Public/testprogram/e_sqrtl.c_e.c:72:32");
  AssignLd({(Addr)&temp_var_for_ext_5}, (Addr)&y,
           "/home/shijia/Public/testprogram/e_sqrtl.c_e.c:76:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_5;
}

#endif

long double __sqrtl(long double x) {
  if (isless(x, 0.0) && _LIB_VERSION != _IEEE_) {
    long double temp_var_for_ext_6;
    long double temp_var_for_const_7;
    long double temp_var_for_callexp_2;

    /*embed fun has found*/
    long double temp_var_for_callexp_3;

    temp_var_for_callexp_2 = __builtin_nanl("");
    temp_var_for_callexp_3 =
        __kernel_standard_l(x, x, temp_var_for_callexp_2, KMATHERRL_SQRT);
    temp_var_for_ext_6 = temp_var_for_callexp_3;
    AssignLd({(Addr)&temp_var_for_ext_6},
             (Addr) &(temp_var_for_const_7 = temp_var_for_callexp_3),
             "/home/shijia/Public/testprogram/e_sqrtl.c_e.c:87:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_6;
  }
  /* sqrt(negative) */
  long double temp_var_for_ext_7;
  long double temp_var_for_const_8;
  long double temp_var_for_callexp_4;

  temp_var_for_callexp_4 = __ieee754_sqrtl(x);
  temp_var_for_ext_7 = temp_var_for_callexp_4;
  AssignLd({(Addr)&temp_var_for_ext_7},
           (Addr) &(temp_var_for_const_8 = temp_var_for_callexp_4),
           "/home/shijia/Public/testprogram/e_sqrtl.c_e.c:95:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_7;
}

__typeof(__sqrtl) sqrtl __attribute__((weak, alias("__sqrtl")));

#endif
