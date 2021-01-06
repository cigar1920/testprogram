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

double __cbrt(double x) {
  double xm, ym, u, t2;
  int xe;
  int x_class;

  static const double factor[5] = {
      0.62996052494743658238361,     /* 1 / 2^(2/3) */
      0.79370052598409973737585,     /* 1 / 2^(1/3) */
      1.0, 1.2599210498948731647672, /* 2^(1/3) */
      1.5874010519681994747517       /* 2^(2/3) */
  };

  /* Reduce X.  XM now is an range 1.0 to 0.5.  */
  xm = __ieee754_frexp(__ieee754_fabs(x), &xe);
  double temp_var_for_const_0;AssignD({(Addr)&xm},(Addr)&(temp_var_for_const_0=__ieee754_frexp((__ieee754_fabs(getFVbyShadow<int>((Addr)&x)), ((&(xe)))),"/home/shijia/Public/testprogram/s_cbrt.c_e.c:38:6");

  /* If X is not finite or is null return it (with raising exceptions
     if necessary.
     Note: *Our* version of `frexp' sets XE to zero if the argument is
     Inf or NaN.  This is not portable but faster.  */
  if (xe == 0 && ((x_class = fpclassify(x)) == FP_ZERO || x_class == FP_NAN ||
                  x_class == FP_INFINITE))
    return x + x;

  u = (0.354895765043919860 +
       ((1.50819193781584896 +
         (((0.0 - 2.11499494167371287) +
           ((2.44693122563534430 +
             (((0.0 - 1.83469277483613086) +
               (0.784932344976639262 - 0.145263899385486377 * xm) * xm) *
              xm)) *
            xm)) *
          xm)) *
        xm));double temp_var_for_const_1,temp_var_for_const_2,temp_var_for_const_3,temp_var_for_const_4,temp_var_for_const_5,temp_var_for_const_6,temp_var_for_const_7,temp_var_for_const_8,temp_var_for_const_9;double temp_var_for_tac_0,temp_var_for_tac_1,temp_var_for_tac_2,temp_var_for_tac_3,temp_var_for_tac_4,temp_var_for_tac_5,temp_var_for_tac_6,temp_var_for_tac_7,temp_var_for_tac_8,temp_var_for_tac_9,temp_var_for_tac_10,temp_var_for_tac_11,temp_var_for_tac_12;computeDSub((Addr)&temp_var_for_tac_0,{(Addr)&(temp_var_for_const_2=0.0),(Addr)&(temp_var_for_const_1=2.11499494167371287)},"/home/shijia/Public/testprogram/s_cbrt.c_e.c:52:21");computeDSub((Addr)&temp_var_for_tac_1,{(Addr)&(temp_var_for_const_4=0.0),(Addr)&(temp_var_for_const_3=1.83469277483613086)},"/home/shijia/Public/testprogram/s_cbrt.c_e.c:53:61");computeDMul((Addr)&temp_var_for_tac_2,{(Addr)&(temp_var_for_const_5=0.145263899385486377),(Addr)&xm},"/home/shijia/Public/testprogram/s_cbrt.c_e.c:53:38");computeDSub((Addr)&temp_var_for_tac_3,{(Addr)&(temp_var_for_const_6=0.784932344976639262),(Addr)&temp_var_for_tac_2},"/home/shijia/Public/testprogram/s_cbrt.c_e.c:53:67");computeDMul((Addr)&temp_var_for_tac_4,{(Addr)&temp_var_for_tac_3,(Addr)&xm},"/home/shijia/Public/testprogram/s_cbrt.c_e.c:52:44");computeDAdd((Addr)&temp_var_for_tac_5,{(Addr)&temp_var_for_tac_1,(Addr)&temp_var_for_tac_4},"/home/shijia/Public/testprogram/s_cbrt.c_e.c:53:73");computeDMul((Addr)&temp_var_for_tac_6,{(Addr)&temp_var_for_tac_5,(Addr)&xm},"/home/shijia/Public/testprogram/s_cbrt.c_e.c:51:34");computeDAdd((Addr)&temp_var_for_tac_7,{(Addr)&(temp_var_for_const_7=2.44693122563534430),(Addr)&temp_var_for_tac_6},"/home/shijia/Public/testprogram/s_cbrt.c_e.c:54:20");computeDMul((Addr)&temp_var_for_tac_8,{(Addr)&temp_var_for_tac_7,(Addr)&xm},"/home/shijia/Public/testprogram/s_cbrt.c_e.c:50:40");computeDAdd((Addr)&temp_var_for_tac_9,{(Addr)&temp_var_for_tac_0,(Addr)&temp_var_for_tac_8},"/home/shijia/Public/testprogram/s_cbrt.c_e.c:55:18");computeDMul((Addr)&temp_var_for_tac_10,{(Addr)&temp_var_for_tac_9,(Addr)&xm},"/home/shijia/Public/testprogram/s_cbrt.c_e.c:49:30");computeDAdd((Addr)&temp_var_for_tac_11,{(Addr)&(temp_var_for_const_8=1.50819193781584896),(Addr)&temp_var_for_tac_10},"/home/shijia/Public/testprogram/s_cbrt.c_e.c:56:16");computeDMul((Addr)&temp_var_for_tac_12,{(Addr)&temp_var_for_tac_11,(Addr)&xm},"/home/shijia/Public/testprogram/s_cbrt.c_e.c:48:29");computeDAdd((Addr)&u,{(Addr)&(temp_var_for_const_9=0.354895765043919860),(Addr)&temp_var_for_tac_12},"/home/shijia/Public/testprogram/s_cbrt.c_e.c:48:5");

  t2 = u * u * u;computeDMul((Addr)&t2,{(Addr)&u,(Addr)&u,(Addr)&u},"/home/shijia/Public/testprogram/s_cbrt.c_e.c:59:6");

  ym = u * (t2 + 2.0 * xm) / (2.0 * t2 + xm) * factor[2 + xe % 3];double temp_var_for_const_10,temp_var_for_const_11,temp_var_for_const_12;double temp_var_for_tac_13,temp_var_for_tac_14,temp_var_for_tac_15,temp_var_for_tac_16,temp_var_for_tac_17,temp_var_for_tac_18;computeDMul((Addr)&temp_var_for_tac_13,{(Addr)&(temp_var_for_const_10=2.0),(Addr)&xm},"/home/shijia/Public/testprogram/s_cbrt.c_e.c:61:16");computeDAdd((Addr)&temp_var_for_tac_14,{(Addr)&t2,(Addr)&temp_var_for_tac_13},"/home/shijia/Public/testprogram/s_cbrt.c_e.c:61:10");computeDMul((Addr)&temp_var_for_tac_15,{(Addr)&u,(Addr)&temp_var_for_tac_14},"/home/shijia/Public/testprogram/s_cbrt.c_e.c:61:35");computeDMul((Addr)&temp_var_for_tac_16,{(Addr)&(temp_var_for_const_11=2.0),(Addr)&t2},"/home/shijia/Public/testprogram/s_cbrt.c_e.c:61:40");computeDAdd((Addr)&temp_var_for_tac_17,{(Addr)&temp_var_for_tac_16,(Addr)&xm},"/home/shijia/Public/testprogram/s_cbrt.c_e.c:61:28");computeDDiv((Addr)&temp_var_for_tac_18,{(Addr)&temp_var_for_tac_15,(Addr)&temp_var_for_tac_17},"/home/shijia/Public/testprogram/s_cbrt.c_e.c:61:46");computeDMul((Addr)&ym,{(Addr)&temp_var_for_tac_18,(Addr)&(temp_var_for_const_12=factor[2 + xe % 3])},"/home/shijia/Public/testprogram/s_cbrt.c_e.c:61:6");

  double temp_var_for_ext_0;
  temp_var_for_ext_0 = __ieee754_ldexp(x > 0.0 ? ym : -ym, xe / 3);
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_v(0.0 - r_) for_ext_0;
}

__typeof(__cbrt) cbrt __attribute__((weak, alias("__cbrt")));
#ifdef __NO_LONG_DOUBLE_MATH
__typeof(cbrtl) __cbrtl __attribute__((alias("__cbrt")));
__typeof(__cbrtl) cbrtl __attribute__((weak, alias("__cbrt")));
#endif
