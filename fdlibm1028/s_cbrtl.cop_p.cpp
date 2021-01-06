#include "../ScDebug/scdebug.h"
/* Compute cubic root of double value.
   Copyright (C) 1997-2013 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by Dirk Alboth <dirka@uni-paderborn.de> and
   Ulrich Drepper <drepper@cygnus.com>, 1997.

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

long double __cbrtl(long double x) {
  long double xm, u;
  int xe;
  int x_class;

  static const long double factor[5] = {
      0.62996052494743658238361L,      /* 1 / 2^(2/3) */
      0.79370052598409973737585L,      /* 1 / 2^(1/3) */
      1.0L, 1.2599210498948731647672L, /* 2^(1/3) */
      1.5874010519681994747517L        /* 2^(2/3) */
  };

  static const long double third = 0.3333333333333333333333333L;

  /* Reduce X.  XM now is an range 1.0 to 0.5.  */
  long double temp_var_for_const_0;
  long double temp_var_for_callexp_0;

  /*embed fun has found*/
  long double temp_var_for_callexp_1;

  temp_var_for_callexp_0 = fabsl(x);
  temp_var_for_callexp_1 = __ieee754_frexpl(temp_var_for_callexp_0, (&(xe)));
  xm = temp_var_for_callexp_1;
  AssignLd({(Addr)&xm}, (Addr) &(temp_var_for_const_0 = temp_var_for_callexp_1),
           "/home/shijia/Public/testprogram/s_cbrtl.c_e.c:42:6");
  ;

  /* If X is not finite or is null return it (with raising exceptions
     if necessary.
     Note: *Our* version of `frexp' sets XE to zero if the argument is
     Inf or NaN.  This is not portable but faster.  */
  if (xe == 0 && ((x_class = fpclassify(x)) == FP_ZERO || x_class == FP_NAN ||
                  x_class == FP_INFINITE)) {
    long double temp_var_for_ext_0;
    long double temp_var_for_tac_0;
    temp_var_for_tac_0 = x + x;

    temp_var_for_ext_0 = temp_var_for_tac_0;
    computeLdAdd((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&x},
                 "/home/shijia/Public/testprogram/s_cbrtl.c_e.c:51:28");
    AssignLd({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_0,
             "/home/shijia/Public/testprogram/s_cbrtl.c_e.c:51:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  long double temp_var_for_tac_1, temp_var_for_tac_2, temp_var_for_tac_3,
      temp_var_for_tac_4, temp_var_for_tac_5, temp_var_for_tac_6,
      temp_var_for_tac_7, temp_var_for_tac_8, temp_var_for_tac_9;
  long double temp_var_for_const_1, temp_var_for_const_2, temp_var_for_const_3,
      temp_var_for_const_4, temp_var_for_const_5, temp_var_for_const_6;
  temp_var_for_tac_1 = 0.0 - 1.34661104733595206551E-1;

  temp_var_for_tac_2 = temp_var_for_tac_1 * xm;

  temp_var_for_tac_3 = temp_var_for_tac_2 + 5.46646013663955245034E-1;

  temp_var_for_tac_4 = temp_var_for_tac_3 * xm;

  temp_var_for_tac_5 = temp_var_for_tac_4 - 9.54382247715094465250E-1;

  temp_var_for_tac_6 = temp_var_for_tac_5 * xm;

  temp_var_for_tac_7 = temp_var_for_tac_6 + 1.13999833547172932737E0;

  temp_var_for_tac_8 = temp_var_for_tac_7 * xm;

  temp_var_for_tac_9 = temp_var_for_tac_8 + 4.02389795645447521269E-1;

  u = temp_var_for_tac_9;
  computeDSub((Addr)&temp_var_for_tac_1,
              {(Addr) &(temp_var_for_const_2 = 0.0),
               (Addr) &(temp_var_for_const_1 = 1.34661104733595206551E-1)},
              "/home/shijia/Public/testprogram/s_cbrtl.c_e.c:57:15");
  computeLdMul((Addr)&temp_var_for_tac_2,
               {(Addr)&temp_var_for_tac_1, (Addr)&xm},
               "/home/shijia/Public/testprogram/s_cbrtl.c_e.c:57:44");
  computeLdAdd((Addr)&temp_var_for_tac_3,
               {(Addr)&temp_var_for_tac_2,
                (Addr) &(temp_var_for_const_3 = 5.46646013663955245034E-1)},
               "/home/shijia/Public/testprogram/s_cbrtl.c_e.c:57:49");
  computeLdMul((Addr)&temp_var_for_tac_4,
               {(Addr)&temp_var_for_tac_3, (Addr)&xm},
               "/home/shijia/Public/testprogram/s_cbrtl.c_e.c:57:78");
  computeLdSub((Addr)&temp_var_for_tac_5,
               {(Addr)&temp_var_for_tac_4,
                (Addr) &(temp_var_for_const_4 = 9.54382247715094465250E-1)},
               "/home/shijia/Public/testprogram/s_cbrtl.c_e.c:58:16");
  computeLdMul((Addr)&temp_var_for_tac_6,
               {(Addr)&temp_var_for_tac_5, (Addr)&xm},
               "/home/shijia/Public/testprogram/s_cbrtl.c_e.c:59:36");
  computeLdAdd((Addr)&temp_var_for_tac_7,
               {(Addr)&temp_var_for_tac_6,
                (Addr) &(temp_var_for_const_5 = 1.13999833547172932737E0)},
               "/home/shijia/Public/testprogram/s_cbrtl.c_e.c:60:15");
  computeLdMul((Addr)&temp_var_for_tac_8,
               {(Addr)&temp_var_for_tac_7, (Addr)&xm},
               "/home/shijia/Public/testprogram/s_cbrtl.c_e.c:61:34");
  computeLdAdd((Addr)&temp_var_for_tac_9,
               {(Addr)&temp_var_for_tac_8,
                (Addr) &(temp_var_for_const_6 = 4.02389795645447521269E-1)},
               "/home/shijia/Public/testprogram/s_cbrtl.c_e.c:62:14");
  AssignLd({(Addr)&u}, (Addr)&temp_var_for_tac_9,
           "/home/shijia/Public/testprogram/s_cbrtl.c_e.c:57:5");
  ;

  u *= factor[2 + xe % 3];
  ;
  long double temp_var_for_ext_1;
  long double temp_var_for_tac_11;
  long double temp_var_for_const_7, temp_var_for_const_8, temp_var_for_const_9;
  long double temp_var_for_callexp_2;

  temp_var_for_tac_11 = xe / 3;

  temp_var_for_callexp_2 =
      __ieee754_ldexpl(x > 0.0 ? u : (0.0 - u), temp_var_for_tac_11);
  temp_var_for_ext_1 = temp_var_for_callexp_2;
  computeDiv((Addr)&temp_var_for_tac_11, {(Addr) &(temp_var_for_const_8 = xe),
                                          (Addr) &(temp_var_for_const_7 = 3)},
             "/home/shijia/Public/testprogram/s_cbrtl.c_e.c:67:69");
  AssignLd({(Addr)&temp_var_for_ext_1},
           (Addr) &(temp_var_for_const_9 = temp_var_for_callexp_2),
           "/home/shijia/Public/testprogram/s_cbrtl.c_e.c:67:22");
  ; // u
    /*(4.02389795645447521269E-1)(xm)(1.13999833547172932737E0)(xm)(9.54382247715094465250E-1)(xm)(5.46646013663955245034E-1)(xm)(1.34661104733595206551E-1)(1.34661104733595206551E-1)(xm)(1.13999833547172932737E0)(xm)(9.54382247715094465250E-1)(xm)(5.46646013663955245034E-1)(xm)(1.34661104733595206551E-1)(1.34661104733595206551E-1)(1.13999833547172932737E0)(xm)(9.54382247715094465250E-1)(xm)(5.46646013663955245034E-1)(xm)(1.34661104733595206551E-1)(1.34661104733595206551E-1)(xm)(9.54382247715094465250E-1)(xm)(5.46646013663955245034E-1)(xm)(1.34661104733595206551E-1)(1.34661104733595206551E-1)(9.54382247715094465250E-1)(xm)(5.46646013663955245034E-1)(xm)(1.34661104733595206551E-1)(1.34661104733595206551E-1)(xm)(5.46646013663955245034E-1)(xm)(1.34661104733595206551E-1)(1.34661104733595206551E-1)(5.46646013663955245034E-1)(xm)(1.34661104733595206551E-1)(1.34661104733595206551E-1)(xm)(1.34661104733595206551E-1)(1.34661104733595206551E-1)(factor)(3)(xe)(2)(factor[TempNull])(u)(__ieee754_ldexpl(x
     * > 0.0 ? u : -u, xe / 3))*/
  u = temp_var_for_ext_1;

  long double temp_var_for_tac_12, temp_var_for_tac_13, temp_var_for_tac_14,
      temp_var_for_tac_15;
  long double temp_var_for_const_10;
  temp_var_for_tac_12 = u * u;

  temp_var_for_tac_13 = x / temp_var_for_tac_12;

  temp_var_for_tac_14 = u - temp_var_for_tac_13;

  temp_var_for_tac_15 = temp_var_for_tac_14 * third;

  u -= temp_var_for_tac_15;
  ;
  long double temp_var_for_tac_17, temp_var_for_tac_18, temp_var_for_tac_19,
      temp_var_for_tac_20;
  long double temp_var_for_const_11;
  temp_var_for_tac_17 = u * u;

  temp_var_for_tac_18 = x / temp_var_for_tac_17;

  temp_var_for_tac_19 = u - temp_var_for_tac_18;

  temp_var_for_tac_20 = temp_var_for_tac_19 * third;

  u -= temp_var_for_tac_20;
  ;
  long double temp_var_for_ext_2;
  temp_var_for_ext_2 = u;
  computeLdMul((Addr)&temp_var_for_tac_12, {(Addr)&u, (Addr)&u},
               "/home/shijia/Public/testprogram/s_cbrtl.c_e.c:72:21");
  computeLdDiv((Addr)&temp_var_for_tac_13,
               {(Addr)&x, (Addr)&temp_var_for_tac_12},
               "/home/shijia/Public/testprogram/s_cbrtl.c_e.c:72:16");
  computeLdSub((Addr)&temp_var_for_tac_14,
               {(Addr)&u, (Addr)&temp_var_for_tac_13},
               "/home/shijia/Public/testprogram/s_cbrtl.c_e.c:72:11");
  computeLdMul(
      (Addr)&temp_var_for_tac_15,
      {(Addr)&temp_var_for_tac_14, (Addr) &(temp_var_for_const_10 = third)},
      "/home/shijia/Public/testprogram/s_cbrtl.c_e.c:72:28");
  computeLdMul((Addr)&temp_var_for_tac_17, {(Addr)&u, (Addr)&u},
               "/home/shijia/Public/testprogram/s_cbrtl.c_e.c:73:21");
  computeLdDiv((Addr)&temp_var_for_tac_18,
               {(Addr)&x, (Addr)&temp_var_for_tac_17},
               "/home/shijia/Public/testprogram/s_cbrtl.c_e.c:73:16");
  computeLdSub((Addr)&temp_var_for_tac_19,
               {(Addr)&u, (Addr)&temp_var_for_tac_18},
               "/home/shijia/Public/testprogram/s_cbrtl.c_e.c:73:11");
  computeLdMul(
      (Addr)&temp_var_for_tac_20,
      {(Addr)&temp_var_for_tac_19, (Addr) &(temp_var_for_const_11 = third)},
      "/home/shijia/Public/testprogram/s_cbrtl.c_e.c:73:28");
  AssignLd({(Addr)&temp_var_for_ext_2}, (Addr)&u,
           "/home/shijia/Public/testprogram/s_cbrtl.c_e.c:75:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_2;
}

__typeof(__cbrtl) cbrtl __attribute__((weak, alias("__cbrtl")));

#endif
