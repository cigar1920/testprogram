#include "../ScDebug/scdebug.h"
/* Base 2 logarithm.
   Copyright (C) 2011-2013 Free Software Foundation, Inc.

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

#ifndef __have_fpu_log2

long double __ieee754_log2l(long double x) {
  /* Decompose x into
     x = 2^e * y
     where
     e is an integer,
     1/2 < y < 2.
     Then log2(x) = e + log2(y) = e + log(y)/log(2).  */
  int e;
  long double y;

  long double temp_var_for_const_0;
  long double temp_var_for_callexp_0;

  temp_var_for_callexp_0 = __ieee754_frexpl(x, (&(e)));
  y = temp_var_for_callexp_0;
  AssignLd({(Addr)&y}, (Addr) &(temp_var_for_const_0 = temp_var_for_callexp_0),
           "/home/shijia/Public/testprogram/e_log2l.c_e.c:35:5");
  ;
  if (int temp_var_for_tac_0; int temp_var_for_const_1;
      temp_var_for_tac_0 = y < M_SQRT1_2l;

      ) {
    long double temp_var_for_ext_0;
    long double temp_var_for_tac_1;
    long double temp_var_for_const_2;
    temp_var_for_tac_1 = 2.0L * y;

    temp_var_for_ext_0 = temp_var_for_tac_1;
    compute((Addr)&temp_var_for_tac_0,
            {(Addr)&y, (Addr) &(temp_var_for_const_1 = M_SQRT1_2l)},
            "/home/shijia/Public/testprogram/e_log2l.c_e.c:36:9");
    computeLdMul((Addr)&temp_var_for_tac_1,
                 {(Addr) &(temp_var_for_const_2 = 2.0L), (Addr)&y},
                 "/home/shijia/Public/testprogram/e_log2l.c_e.c:38:31");
    AssignLd({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_1,
             "/home/shijia/Public/testprogram/e_log2l.c_e.c:38:24");
    ; // y
    /*(y)(2.0L)*/
    y = temp_var_for_ext_0;
    AssignLd({(Addr)&y}, (Addr)&temp_var_for_ext_0,
             "/home/shijia/Public/testprogram/e_log2l.c_e.c:40:7");
    ;
    e = e - 1;
  }

  long double temp_var_for_ext_1;
  long double temp_var_for_tac_2, temp_var_for_tac_3;
  long double temp_var_for_const_3, temp_var_for_const_4, temp_var_for_const_5;
  long double temp_var_for_callexp_1;

  temp_var_for_callexp_1 = __ieee754_logl(y);
  temp_var_for_tac_2 = temp_var_for_callexp_1 * M_LOG2El;

  temp_var_for_tac_3 = ((long double)e) + temp_var_for_tac_2;

  temp_var_for_ext_1 = temp_var_for_tac_3;
  computeLdMul((Addr)&temp_var_for_tac_2,
               {(Addr) &(temp_var_for_const_4 = temp_var_for_callexp_1),
                (Addr) &(temp_var_for_const_3 = M_LOG2El)},
               "/home/shijia/Public/testprogram/e_log2l.c_e.c:45:59");
  computeLdAdd((Addr)&temp_var_for_tac_3,
               {(Addr) &(temp_var_for_const_5 = ((long double)e)),
                (Addr)&temp_var_for_tac_2},
               "/home/shijia/Public/testprogram/e_log2l.c_e.c:45:39");
  AssignLd({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_3,
           "/home/shijia/Public/testprogram/e_log2l.c_e.c:45:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

#endif

/* wrapper log2(x) */
long double __log2l(long double x) {
  if (islessequal(x, 0.0) && _LIB_VERSION != _IEEE_) {
    if (int temp_var_for_tac_4; int temp_var_for_const_6;
        temp_var_for_tac_4 = x == 0.0;

        ) {
      feraiseexcept(FE_DIVBYZERO);
      long double temp_var_for_ext_2;
      long double temp_var_for_const_7;
      long double temp_var_for_callexp_3;

      temp_var_for_callexp_2 = __builtin_huge_vall();
      temp_var_for_callexp_3 = __kernel_standard_l(
          x, x, (-(temp_var_for_callexp_2)), KMATHERRL_LOG2_ZERO);
      temp_var_for_ext_2 = temp_var_for_callexp_3;
      compute((Addr)&temp_var_for_tac_4,
              {(Addr)&x, (Addr) &(temp_var_for_const_6 = 0.0)},
              "/home/shijia/Public/testprogram/e_log2l.c_e.c:56:11");
      AssignLd({(Addr)&temp_var_for_ext_2},
               (Addr) &(temp_var_for_const_7 = temp_var_for_callexp_3),
               "/home/shijia/Public/testprogram/e_log2l.c_e.c:59:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
      callExp++; /*identify the function is  add move tmpSh(0.0 - dow*/
ret)urn temp_var_for_ext_2;	/* log2(0) */
    } else {
      feraiseexcept(FE_INVALID);
      long double temp_var_for_ext_3;
      long double temp_var_for_const_8;
      long double temp_var_for_callexp_4;

      /*embed fun has found*/
      long double temp_var_for_callexp_5;

      temp_var_for_callexp_4 = __builtin_nanl("");
      temp_var_for_callexp_5 = __kernel_standard_l(x, x, temp_var_for_callexp_4,
                                                   KMATHERRL_LOG2_MINUS);
      temp_var_for_ext_3 = temp_var_for_callexp_5;
      AssignLd({(Addr)&temp_var_for_ext_3},
               (Addr) &(temp_var_for_const_8 = temp_var_for_callexp_5),
               "/home/shijia/Public/testprogram/e_log2l.c_e.c:68:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_3; /* log2(x<0) */
    }
  }

  long double temp_var_for_ext_4;
  long double temp_var_for_const_9;
  long double temp_var_for_callexp_6;

  temp_var_for_callexp_6 = __ieee754_log2l(x);
  temp_var_for_ext_4 = temp_var_for_callexp_6;
  AssignLd({(Addr)&temp_var_for_ext_4},
           (Addr) &(temp_var_for_const_9 = temp_var_for_callexp_6),
           "/home/shijia/Public/testprogram/e_log2l.c_e.c:78:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_4;
}

__typeof(__log2l) log2l __attribute__((weak, alias("__log2l")));

#endif
