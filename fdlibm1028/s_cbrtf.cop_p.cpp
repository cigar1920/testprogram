#include "../ScDebug/scdebug.h"
/* Compute cubic root of float value.
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

float __cbrtf(float x) {
  float xm, ym, u, t2;
  int xe;
  int x_class;

  static const float factor[5] = {
      0.62996052494743658238361,     /* 1 / 2^(2/3) */
      0.79370052598409973737585,     /* 1 / 2^(1/3) */
      1.0, 1.2599210498948731647672, /* 2^(1/3) */
      1.5874010519681994747517       /* 2^(2/3) */
  };

  /* Reduce X.  XM now is an range 1.0 to 0.5.  */
  float temp_var_for_const_0;
  float temp_var_for_callexp_0;

  /*embed fun has found*/
  float temp_var_for_callexp_1;

  temp_var_for_callexp_0 = fabsf(x);
  temp_var_for_callexp_1 = __ieee754_frexpf(temp_var_for_callexp_0, (&(xe)));
  xm = temp_var_for_callexp_1;
  AssignF({(Addr)&xm}, (Addr) &(temp_var_for_const_0 = temp_var_for_callexp_1),
          "/home/shijia/Public/testprogram/s_cbrtf.c_e.c:38:6");
  ;

  /* If X is not finite or is null return it (with raising exceptions
     if necessary.
     Note: *Our* version of `frexp' sets XE to zero if the argument is
     Inf or NaN.  This is not portable but faster.  */
  if (xe == 0 && ((x_class = fpclassify(x)) == FP_ZERO || x_class == FP_NAN ||
                  x_class == FP_INFINITE)) {
    float temp_var_for_ext_0;
    float temp_var_for_tac_0;
    temp_var_for_tac_0 = x + x;

    temp_var_for_ext_0 = temp_var_for_tac_0;
    computeFAdd((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/s_cbrtf.c_e.c:47:28");
    AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_0,
            "/home/shijia/Public/testprogram/s_cbrtf.c_e.c:47:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  float temp_var_for_tac_1, temp_var_for_tac_2, temp_var_for_tac_3,
      temp_var_for_tac_4;
  float temp_var_for_const_1, temp_var_for_const_2, temp_var_for_const_3;
  temp_var_for_tac_1 = 0.191502161678719066F * xm;

  temp_var_for_tac_2 = 0.697570460207922770F - temp_var_for_tac_1;

  temp_var_for_tac_3 = temp_var_for_tac_2 * xm;

  temp_var_for_tac_4 = 0.492659620528969547F + temp_var_for_tac_3;

  u = temp_var_for_tac_4;
  computeFMul(
      (Addr)&temp_var_for_tac_1,
      {(Addr) &(temp_var_for_const_1 = 0.191502161678719066F), (Addr)&xm},
      "/home/shijia/Public/testprogram/s_cbrtf.c_e.c:54:55");
  computeFSub((Addr)&temp_var_for_tac_2,
              {(Addr) &(temp_var_for_const_2 = 0.697570460207922770F),
               (Addr)&temp_var_for_tac_1},
              "/home/shijia/Public/testprogram/s_cbrtf.c_e.c:54:31");
  computeFMul((Addr)&temp_var_for_tac_3, {(Addr)&temp_var_for_tac_2, (Addr)&xm},
              "/home/shijia/Public/testprogram/s_cbrtf.c_e.c:54:61");
  computeFAdd((Addr)&temp_var_for_tac_4,
              {(Addr) &(temp_var_for_const_3 = 0.492659620528969547F),
               (Addr)&temp_var_for_tac_3},
              "/home/shijia/Public/testprogram/s_cbrtf.c_e.c:53:30");
  AssignF({(Addr)&u}, (Addr)&temp_var_for_tac_4,
          "/home/shijia/Public/testprogram/s_cbrtf.c_e.c:53:5");
  ;

  float temp_var_for_tac_5, temp_var_for_tac_6;
  temp_var_for_tac_5 = u * u;

  temp_var_for_tac_6 = temp_var_for_tac_5 * u;

  t2 = temp_var_for_tac_6;
  computeFMul((Addr)&temp_var_for_tac_5, {(Addr)&u, (Addr)&u},
              "/home/shijia/Public/testprogram/s_cbrtf.c_e.c:56:10");
  computeFMul((Addr)&temp_var_for_tac_6, {(Addr)&temp_var_for_tac_5, (Addr)&u},
              "/home/shijia/Public/testprogram/s_cbrtf.c_e.c:56:14");
  AssignF({(Addr)&t2}, (Addr)&temp_var_for_tac_6,
          "/home/shijia/Public/testprogram/s_cbrtf.c_e.c:56:6");
  ;

  float temp_var_for_tac_7, temp_var_for_tac_8, temp_var_for_tac_9,
      temp_var_for_tac_10, temp_var_for_tac_11, temp_var_for_tac_12,
      temp_var_for_tac_13;
  float temp_var_for_const_4, temp_var_for_const_5, temp_var_for_const_6;
  temp_var_for_tac_7 = 2.0F * xm;

  temp_var_for_tac_8 = t2 + temp_var_for_tac_7;

  temp_var_for_tac_9 = u * temp_var_for_tac_8;

  temp_var_for_tac_10 = 2.0F * t2;

  temp_var_for_tac_11 = temp_var_for_tac_10 + xm;

  temp_var_for_tac_12 = temp_var_for_tac_9 / temp_var_for_tac_11;

  temp_var_for_tac_13 = temp_var_for_tac_12 * factor[2 + xe % 3];

  ym = temp_var_for_tac_13;
  computeFMul((Addr)&temp_var_for_tac_7,
              {(Addr) &(temp_var_for_const_4 = 2.0F), (Addr)&xm},
              "/home/shijia/Public/testprogram/s_cbrtf.c_e.c:58:23");
  computeFAdd((Addr)&temp_var_for_tac_8, {(Addr)&t2, (Addr)&temp_var_for_tac_7},
              "/home/shijia/Public/testprogram/s_cbrtf.c_e.c:58:16");
  computeFMul((Addr)&temp_var_for_tac_9, {(Addr)&u, (Addr)&temp_var_for_tac_8},
              "/home/shijia/Public/testprogram/s_cbrtf.c_e.c:58:10");
  computeFMul((Addr)&temp_var_for_tac_10,
              {(Addr) &(temp_var_for_const_5 = 2.0F), (Addr)&t2},
              "/home/shijia/Public/testprogram/s_cbrtf.c_e.c:58:37");
  computeFAdd((Addr)&temp_var_for_tac_11,
              {(Addr)&temp_var_for_tac_10, (Addr)&xm},
              "/home/shijia/Public/testprogram/s_cbrtf.c_e.c:58:42");
  computeFDiv((Addr)&temp_var_for_tac_12,
              {(Addr)&temp_var_for_tac_9, (Addr)&temp_var_for_tac_11},
              "/home/shijia/Public/testprogram/s_cbrtf.c_e.c:58:29");
  computeFMul((Addr)&temp_var_for_tac_13,
              {(Addr)&temp_var_for_tac_12,
               (Addr) &(temp_var_for_const_6 = factor[2 + xe % 3])},
              "/home/shijia/Public/testprogram/s_cbrtf.c_e.c:58:48");
  AssignF({(Addr)&ym}, (Addr)&temp_var_for_tac_13,
          "/home/shijia/Public/testprogram/s_cbrtf.c_e.c:58:6");
  ;

  float temp_var_for_ext_1;
  float temp_var_for_tac_14;
  float temp_var_for_const_7, temp_var_for_const_8, temp_var_for_const_9;
  float temp_var_for_callexp_2;

  temp_var_for_tac_14 = xe / 3;

  temp_var_for_callexp_2 =
      __ieee754_ldexpf(x > 0.0F ? ym : -ym, temp_var_for_tac_14);
  temp_var_for_ext_1 = temp_var_for_callexp_2;
  computeDiv((Addr)&temp_var_for_tac_14, {(Addr) &(temp_var_for_const_8 = xe),
                                          (Addr) &(temp_var_for_const_7 = 3)},
             "/home/shijia/Public/testprogram/s_cbrtf.c_e.c:61:65");
  AssignF({(Addr)&temp_var_for_ext_1},
          (Addr) &(temp_var_for_const_9 = temp_var_for_callexp_2),
          "/home/shijia/Public/testprogram/s_cbrtf.c_e.c:61:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_v(0.0 - r_) for_ext_1;
}

__typeof(__cbrtf) cbrtf __attribute__((weak, alias("__cbrtf")));
