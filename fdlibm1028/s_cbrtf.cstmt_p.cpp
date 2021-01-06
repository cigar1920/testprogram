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
  xm = __ieee754_frexpf(__ieee754_fabsf(x), &xe);
  float temp_var_for_const_0;AssignF({(Addr)&xm},(Addr)&(temp_var_for_const_0=__ieee754_frexpf((__ieee754_fabsf(getFVbyShadow<int>((Addr)&x)), ((&(xe)))),"/home/shijia/Public/testprogram/s_cbrtf.c_e.c:38:6");

  /* If X is not finite or is null return it (with raising exceptions
     if necessary.
     Note: *Our* version of `frexp' sets XE to zero if the argument is
     Inf or NaN.  This is not portable but faster.  */
  if (xe == 0 && ((x_class = fpclassify(x)) == FP_ZERO || x_class == FP_NAN ||
                  x_class == FP_INFINITE))
    return x + x;

  u = (0.492659620528969547F +
       (0.697570460207922770F - 0.191502161678719066F * xm) * xm);float temp_var_for_const_1,temp_var_for_const_2,temp_var_for_const_3;float temp_var_for_tac_0,temp_var_for_tac_1,temp_var_for_tac_2;computeFMul((Addr)&temp_var_for_tac_0,{(Addr)&(temp_var_for_const_1=0.191502161678719066F),(Addr)&xm},"/home/shijia/Public/testprogram/s_cbrtf.c_e.c:49:31");computeFSub((Addr)&temp_var_for_tac_1,{(Addr)&(temp_var_for_const_2=0.697570460207922770F),(Addr)&temp_var_for_tac_0},"/home/shijia/Public/testprogram/s_cbrtf.c_e.c:49:61");computeFMul((Addr)&temp_var_for_tac_2,{(Addr)&temp_var_for_tac_1,(Addr)&xm},"/home/shijia/Public/testprogram/s_cbrtf.c_e.c:48:30");computeFAdd((Addr)&u,{(Addr)&(temp_var_for_const_3=0.492659620528969547F),(Addr)&temp_var_for_tac_2},"/home/shijia/Public/testprogram/s_cbrtf.c_e.c:48:5");

  t2 = u * u * u;computeFMul((Addr)&t2,{(Addr)&u,(Addr)&u,(Addr)&u},"/home/shijia/Public/testprogram/s_cbrtf.c_e.c:51:6");

  ym = u * (t2 + 2.0F * xm) / (2.0F * t2 + xm) * factor[2 + xe % 3];float temp_var_for_const_4,temp_var_for_const_5,temp_var_for_const_6;float temp_var_for_tac_3,temp_var_for_tac_4,temp_var_for_tac_5,temp_var_for_tac_6,temp_var_for_tac_7,temp_var_for_tac_8;computeFMul((Addr)&temp_var_for_tac_3,{(Addr)&(temp_var_for_const_4=2.0F),(Addr)&xm},"/home/shijia/Public/testprogram/s_cbrtf.c_e.c:53:16");computeFAdd((Addr)&temp_var_for_tac_4,{(Addr)&t2,(Addr)&temp_var_for_tac_3},"/home/shijia/Public/testprogram/s_cbrtf.c_e.c:53:10");computeFMul((Addr)&temp_var_for_tac_5,{(Addr)&u,(Addr)&temp_var_for_tac_4},"/home/shijia/Public/testprogram/s_cbrtf.c_e.c:53:37");computeFMul((Addr)&temp_var_for_tac_6,{(Addr)&(temp_var_for_const_5=2.0F),(Addr)&t2},"/home/shijia/Public/testprogram/s_cbrtf.c_e.c:53:42");computeFAdd((Addr)&temp_var_for_tac_7,{(Addr)&temp_var_for_tac_6,(Addr)&xm},"/home/shijia/Public/testprogram/s_cbrtf.c_e.c:53:29");computeFDiv((Addr)&temp_var_for_tac_8,{(Addr)&temp_var_for_tac_5,(Addr)&temp_var_for_tac_7},"/home/shijia/Public/testprogram/s_cbrtf.c_e.c:53:48");computeFMul((Addr)&ym,{(Addr)&temp_var_for_tac_8,(Addr)&(temp_var_for_const_6=factor[2 + xe % 3])},"/home/shijia/Public/testprogram/s_cbrtf.c_e.c:53:6");

  float temp_var_for_ext_0;
  temp_var_for_ext_0 = __ieee754_ldexpf(x > 0.0F ? ym : -ym, xe / 3);
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_v(0.0 - r_) for_ext_0;
}

__typeof(__cbrtf) cbrtf __attribute__((weak, alias("__cbrtf")));
