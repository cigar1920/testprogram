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
  xm = __ieee754_frexpl(__ieee754_fabsl(x), &xe);
  long double temp_var_for_const_0;AssignLd({(Addr)&xm},(Addr)&(temp_var_for_const_0=__ieee754_frexpl((__ieee754_fabsl(getFVbyShadow<int>((Addr)&x)), ((&(xe)))),"/home/shijia/Public/testprogram/s_cbrtl.c_e.c:42:6");

  /* If X is not finite or is null return it (with raising exceptions
     if necessary.
     Note: *Our* version of `frexp' sets XE to zero if the argument is
     Inf or NaN.  This is not portable but faster.  */
  if (xe == 0 && ((x_class = fpclassify(x)) == FP_ZERO || x_class == FP_NAN ||
                  x_class == FP_INFINITE))
    return x + x;

  u = ((((0.0 - 1.34661104733595206551E-1) * xm + 5.46646013663955245034E-1) *
            xm -
        9.54382247715094465250E-1) *
           xm +
       1.13999833547172932737E0) *
          xm +
      4.02389795645447521269E-1;long double temp_var_for_const_1,temp_var_for_const_2,temp_var_for_const_3,temp_var_for_const_4,temp_var_for_const_5,temp_var_for_const_6;long double temp_var_for_tac_0,temp_var_for_tac_1,temp_var_for_tac_2,temp_var_for_tac_3,temp_var_for_tac_4,temp_var_for_tac_5,temp_var_for_tac_6,temp_var_for_tac_7;computeLdSub((Addr)&temp_var_for_tac_0,{(Addr)&(temp_var_for_const_2=0.0),(Addr)&(temp_var_for_const_1=1.34661104733595206551E-1)},"/home/shijia/Public/testprogram/s_cbrtl.c_e.c:52:44");computeLdMul((Addr)&temp_var_for_tac_1,{(Addr)&temp_var_for_tac_0,(Addr)&xm},"/home/shijia/Public/testprogram/s_cbrtl.c_e.c:52:49");computeLdAdd((Addr)&temp_var_for_tac_2,{(Addr)&temp_var_for_tac_1,(Addr)&(temp_var_for_const_3=5.46646013663955245034E-1)},"/home/shijia/Public/testprogram/s_cbrtl.c_e.c:52:78");computeLdMul((Addr)&temp_var_for_tac_3,{(Addr)&temp_var_for_tac_2,(Addr)&xm},"/home/shijia/Public/testprogram/s_cbrtl.c_e.c:53:16");computeLdSub((Addr)&temp_var_for_tac_4,{(Addr)&temp_var_for_tac_3,(Addr)&(temp_var_for_const_4=9.54382247715094465250E-1)},"/home/shijia/Public/testprogram/s_cbrtl.c_e.c:54:36");computeLdMul((Addr)&temp_var_for_tac_5,{(Addr)&temp_var_for_tac_4,(Addr)&xm},"/home/shijia/Public/testprogram/s_cbrtl.c_e.c:55:15");computeLdAdd((Addr)&temp_var_for_tac_6,{(Addr)&temp_var_for_tac_5,(Addr)&(temp_var_for_const_5=1.13999833547172932737E0)},"/home/shijia/Public/testprogram/s_cbrtl.c_e.c:56:34");computeLdMul((Addr)&temp_var_for_tac_7,{(Addr)&temp_var_for_tac_6,(Addr)&xm},"/home/shijia/Public/testprogram/s_cbrtl.c_e.c:57:14");computeLdAdd((Addr)&u,{(Addr)&temp_var_for_tac_7,(Addr)&(temp_var_for_const_6=4.02389795645447521269E-1)},"/home/shijia/Public/testprogram/s_cbrtl.c_e.c:52:5");

  u *= factor[2 + xe % 3];
  long double temp_var_for_ext_0;
  temp_var_for_ext_0 = __ieee754_ldexpl(x > 0.0 ? u : (0.0 - u), xe / 3); // u
  /*(4.02389795645447521269E-1)(xm)(1.13999833547172932737E0)(xm)(9.54382247715094465250E-1)(xm)(5.46646013663955245034E-1)(xm)(1.34661104733595206551E-1)(1.34661104733595206551E-1)(xm)(1.13999833547172932737E0)(xm)(9.54382247715094465250E-1)(xm)(5.46646013663955245034E-1)(xm)(1.34661104733595206551E-1)(1.34661104733595206551E-1)(1.13999833547172932737E0)(xm)(9.54382247715094465250E-1)(xm)(5.46646013663955245034E-1)(xm)(1.34661104733595206551E-1)(1.34661104733595206551E-1)(xm)(9.54382247715094465250E-1)(xm)(5.46646013663955245034E-1)(xm)(1.34661104733595206551E-1)(1.34661104733595206551E-1)(9.54382247715094465250E-1)(xm)(5.46646013663955245034E-1)(xm)(1.34661104733595206551E-1)(1.34661104733595206551E-1)(xm)(5.46646013663955245034E-1)(xm)(1.34661104733595206551E-1)(1.34661104733595206551E-1)(5.46646013663955245034E-1)(xm)(1.34661104733595206551E-1)(1.34661104733595206551E-1)(xm)(1.34661104733595206551E-1)(1.34661104733595206551E-1)(factor)(3)(xe)(2)(factor[TempNull])(u)(__ieee754_ldexpl(x
   * > 0.0 ? u : -u, xe / 3))*/
  u = temp_var_for_ext_0;AssignLd({(Addr)&u},(Addr)&temp_var_for_ext_0,"/home/shijia/Public/testprogram/s_cbrtl.c_e.c:65:5");

  u -= (u - (x / (u * u))) * third;long double temp_var_for_const_7;long double temp_var_for_tac_8,temp_var_for_tac_9,temp_var_for_tac_10;computeLdMul((Addr)&temp_var_for_tac_8,{(Addr)&u,(Addr)&u},"/home/shijia/Public/testprogram/s_cbrtl.c_e.c:67:16");computeLdDiv((Addr)&temp_var_for_tac_9,{(Addr)&x,(Addr)&temp_var_for_tac_8},"/home/shijia/Public/testprogram/s_cbrtl.c_e.c:67:11");computeLdSub((Addr)&temp_var_for_tac_10,{(Addr)&u,(Addr)&temp_var_for_tac_9},"/home/shijia/Public/testprogram/s_cbrtl.c_e.c:67:28");
  u -= (u - (x / (u * u))) * third;long double temp_var_for_const_8;long double temp_var_for_tac_11,temp_var_for_tac_12,temp_var_for_tac_13,temp_var_for_tac_14;computeLdMul((Addr)&temp_var_for_tac_11,{(Addr)&temp_var_for_tac_10,(Addr)&(temp_var_for_const_7=third)},"/home/shijia/Public/testprogram/s_cbrtl.c_e.c:68:21");computeLdMul((Addr)&temp_var_for_tac_12,{(Addr)&u,(Addr)&u},"/home/shijia/Public/testprogram/s_cbrtl.c_e.c:68:16");computeLdDiv((Addr)&temp_var_for_tac_13,{(Addr)&x,(Addr)&temp_var_for_tac_12},"/home/shijia/Public/testprogram/s_cbrtl.c_e.c:68:11");computeLdSub((Addr)&temp_var_for_tac_14,{(Addr)&u,(Addr)&temp_var_for_tac_13},"/home/shijia/Public/testprogram/s_cbrtl.c_e.c:68:28");
  long double temp_var_for_ext_1;
  temp_var_for_ext_1 = u;computeLdMul((Addr)&temp_var_for_ext_1,{(Addr)&temp_var_for_tac_14,(Addr)&(temp_var_for_const_8=third)},"/home/shijia/Public/testprogram/s_cbrtl.c_e.c:70:22");
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

__typeof(__cbrtl) cbrtl __attribute__((weak, alias("__cbrtl")));

#endif
