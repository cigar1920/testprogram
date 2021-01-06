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
  double temp_var_for_const_0;
  double temp_var_for_callexp_0;

  /*embed fun has found*/
  double temp_var_for_callexp_1;

  temp_var_for_callexp_0 = fabs(x);
  temp_var_for_callexp_1 = __ieee754_frexp(temp_var_for_callexp_0, (&(xe)));
  xm = temp_var_for_callexp_1;
  AssignD({(Addr)&xm}, (Addr) &(temp_var_for_const_0 = temp_var_for_callexp_1),
          "/home/shijia/Public/testprogram/s_cbrt.c_e.c:38:6");
  ;

  /* If X is not finite or is null return it (with raising exceptions
     if necessary.
     Note: *Our* version of `frexp' sets XE to zero if the argument is
     Inf or NaN.  This is not portable but faster.  */
  if (xe == 0 && ((x_class = fpclassify(x)) == FP_ZERO || x_class == FP_NAN ||
                  x_class == FP_INFINITE)) {
    double temp_var_for_ext_0;
    double temp_var_for_tac_0;
    temp_var_for_tac_0 = x + x;

    temp_var_for_ext_0 = temp_var_for_tac_0;
    computeDAdd((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/s_cbrt.c_e.c:47:28");
    AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_0,
            "/home/shijia/Public/testprogram/s_cbrt.c_e.c:47:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  double temp_var_for_tac_1, temp_var_for_tac_2, temp_var_for_tac_3,
      temp_var_for_tac_4, temp_var_for_tac_5, temp_var_for_tac_6,
      temp_var_for_tac_7, temp_var_for_tac_8, temp_var_for_tac_9,
      temp_var_for_tac_10, temp_var_for_tac_11, temp_var_for_tac_12,
      temp_var_for_tac_13, temp_var_for_tac_14;
  double temp_var_for_const_1, temp_var_for_const_2, temp_var_for_const_3,
      temp_var_for_const_4, temp_var_for_const_5, temp_var_for_const_6,
      temp_var_for_const_7, temp_var_for_const_8, temp_var_for_const_9;
  temp_var_for_tac_1 = 0.0 - 2.11499494167371287;

  temp_var_for_tac_2 = 0.0 - 1.83469277483613086;

  temp_var_for_tac_3 = 0.145263899385486377 * xm;

  temp_var_for_tac_4 = 0.784932344976639262 - temp_var_for_tac_3;

  temp_var_for_tac_5 = temp_var_for_tac_4 * xm;

  temp_var_for_tac_6 = temp_var_for_tac_2 + temp_var_for_tac_5;

  temp_var_for_tac_7 = temp_var_for_tac_6 * xm;

  temp_var_for_tac_8 = 2.44693122563534430 + temp_var_for_tac_7;

  temp_var_for_tac_9 = temp_var_for_tac_8 * xm;

  temp_var_for_tac_10 = temp_var_for_tac_1 + temp_var_for_tac_9;

  temp_var_for_tac_11 = temp_var_for_tac_10 * xm;

  temp_var_for_tac_12 = 1.50819193781584896 + temp_var_for_tac_11;

  temp_var_for_tac_13 = temp_var_for_tac_12 * xm;

  temp_var_for_tac_14 = 0.354895765043919860 + temp_var_for_tac_13;

  u = temp_var_for_tac_14;
  computeDSub((Addr)&temp_var_for_tac_1,
              {(Addr) &(temp_var_for_const_2 = 0.0),
               (Addr) &(temp_var_for_const_1 = 2.11499494167371287)},
              "/home/shijia/Public/testprogram/s_cbrt.c_e.c:55:17");
  computeDSub((Addr)&temp_var_for_tac_2,
              {(Addr) &(temp_var_for_const_4 = 0.0),
               (Addr) &(temp_var_for_const_3 = 1.83469277483613086)},
              "/home/shijia/Public/testprogram/s_cbrt.c_e.c:57:21");
  computeDMul(
      (Addr)&temp_var_for_tac_3,
      {(Addr) &(temp_var_for_const_5 = 0.145263899385486377), (Addr)&xm},
      "/home/shijia/Public/testprogram/s_cbrt.c_e.c:58:61");
  computeDSub((Addr)&temp_var_for_tac_4,
              {(Addr) &(temp_var_for_const_6 = 0.784932344976639262),
               (Addr)&temp_var_for_tac_3},
              "/home/shijia/Public/testprogram/s_cbrt.c_e.c:58:38");
  computeDMul((Addr)&temp_var_for_tac_5, {(Addr)&temp_var_for_tac_4, (Addr)&xm},
              "/home/shijia/Public/testprogram/s_cbrt.c_e.c:58:67");
  computeDAdd((Addr)&temp_var_for_tac_6,
              {(Addr)&temp_var_for_tac_2, (Addr)&temp_var_for_tac_5},
              "/home/shijia/Public/testprogram/s_cbrt.c_e.c:57:44");
  computeDMul((Addr)&temp_var_for_tac_7, {(Addr)&temp_var_for_tac_6, (Addr)&xm},
              "/home/shijia/Public/testprogram/s_cbrt.c_e.c:58:73");
  computeDAdd((Addr)&temp_var_for_tac_8,
              {(Addr) &(temp_var_for_const_7 = 2.44693122563534430),
               (Addr)&temp_var_for_tac_7},
              "/home/shijia/Public/testprogram/s_cbrt.c_e.c:56:34");
  computeDMul((Addr)&temp_var_for_tac_9, {(Addr)&temp_var_for_tac_8, (Addr)&xm},
              "/home/shijia/Public/testprogram/s_cbrt.c_e.c:59:20");
  computeDAdd((Addr)&temp_var_for_tac_10,
              {(Addr)&temp_var_for_tac_1, (Addr)&temp_var_for_tac_9},
              "/home/shijia/Public/testprogram/s_cbrt.c_e.c:55:40");
  computeDMul((Addr)&temp_var_for_tac_11,
              {(Addr)&temp_var_for_tac_10, (Addr)&xm},
              "/home/shijia/Public/testprogram/s_cbrt.c_e.c:60:18");
  computeDAdd((Addr)&temp_var_for_tac_12,
              {(Addr) &(temp_var_for_const_8 = 1.50819193781584896),
               (Addr)&temp_var_for_tac_11},
              "/home/shijia/Public/testprogram/s_cbrt.c_e.c:54:30");
  computeDMul((Addr)&temp_var_for_tac_13,
              {(Addr)&temp_var_for_tac_12, (Addr)&xm},
              "/home/shijia/Public/testprogram/s_cbrt.c_e.c:61:16");
  computeDAdd((Addr)&temp_var_for_tac_14,
              {(Addr) &(temp_var_for_const_9 = 0.354895765043919860),
               (Addr)&temp_var_for_tac_13},
              "/home/shijia/Public/testprogram/s_cbrt.c_e.c:53:29");
  AssignD({(Addr)&u}, (Addr)&temp_var_for_tac_14,
          "/home/shijia/Public/testprogram/s_cbrt.c_e.c:53:5");
  ;

  double temp_var_for_tac_15, temp_var_for_tac_16;
  temp_var_for_tac_15 = u * u;

  temp_var_for_tac_16 = temp_var_for_tac_15 * u;

  t2 = temp_var_for_tac_16;
  computeDMul((Addr)&temp_var_for_tac_15, {(Addr)&u, (Addr)&u},
              "/home/shijia/Public/testprogram/s_cbrt.c_e.c:64:10");
  computeDMul((Addr)&temp_var_for_tac_16,
              {(Addr)&temp_var_for_tac_15, (Addr)&u},
              "/home/shijia/Public/testprogram/s_cbrt.c_e.c:64:14");
  AssignD({(Addr)&t2}, (Addr)&temp_var_for_tac_16,
          "/home/shijia/Public/testprogram/s_cbrt.c_e.c:64:6");
  ;

  double temp_var_for_tac_17, temp_var_for_tac_18, temp_var_for_tac_19,
      temp_var_for_tac_20, temp_var_for_tac_21, temp_var_for_tac_22,
      temp_var_for_tac_23;
  double temp_var_for_const_10, temp_var_for_const_11, temp_var_for_const_12;
  temp_var_for_tac_17 = 2.0 * xm;

  temp_var_for_tac_18 = t2 + temp_var_for_tac_17;

  temp_var_for_tac_19 = u * temp_var_for_tac_18;

  temp_var_for_tac_20 = 2.0 * t2;

  temp_var_for_tac_21 = temp_var_for_tac_20 + xm;

  temp_var_for_tac_22 = temp_var_for_tac_19 / temp_var_for_tac_21;

  temp_var_for_tac_23 = temp_var_for_tac_22 * factor[2 + xe % 3];

  ym = temp_var_for_tac_23;
  computeDMul((Addr)&temp_var_for_tac_17,
              {(Addr) &(temp_var_for_const_10 = 2.0), (Addr)&xm},
              "/home/shijia/Public/testprogram/s_cbrt.c_e.c:66:22");
  computeDAdd((Addr)&temp_var_for_tac_18,
              {(Addr)&t2, (Addr)&temp_var_for_tac_17},
              "/home/shijia/Public/testprogram/s_cbrt.c_e.c:66:16");
  computeDMul((Addr)&temp_var_for_tac_19,
              {(Addr)&u, (Addr)&temp_var_for_tac_18},
              "/home/shijia/Public/testprogram/s_cbrt.c_e.c:66:10");
  computeDMul((Addr)&temp_var_for_tac_20,
              {(Addr) &(temp_var_for_const_11 = 2.0), (Addr)&t2},
              "/home/shijia/Public/testprogram/s_cbrt.c_e.c:66:35");
  computeDAdd((Addr)&temp_var_for_tac_21,
              {(Addr)&temp_var_for_tac_20, (Addr)&xm},
              "/home/shijia/Public/testprogram/s_cbrt.c_e.c:66:40");
  computeDDiv((Addr)&temp_var_for_tac_22,
              {(Addr)&temp_var_for_tac_19, (Addr)&temp_var_for_tac_21},
              "/home/shijia/Public/testprogram/s_cbrt.c_e.c:66:28");
  computeDMul((Addr)&temp_var_for_tac_23,
              {(Addr)&temp_var_for_tac_22,
               (Addr) &(temp_var_for_const_12 = factor[2 + xe % 3])},
              "/home/shijia/Public/testprogram/s_cbrt.c_e.c:66:46");
  AssignD({(Addr)&ym}, (Addr)&temp_var_for_tac_23,
          "/home/shijia/Public/testprogram/s_cbrt.c_e.c:66:6");
  ;

  double temp_var_for_ext_1;
  double temp_var_for_tac_24;
  double temp_var_for_const_13, temp_var_for_const_14, temp_var_for_const_15;
  double temp_var_for_callexp_2;

  temp_var_for_tac_24 = xe / 3;

  temp_var_for_callexp_2 =
      __ieee754_ldexp(x > 0.0 ? ym : -ym, temp_var_for_tac_24);
  temp_var_for_ext_1 = temp_var_for_callexp_2;
  computeDiv((Addr)&temp_var_for_tac_24, {(Addr) &(temp_var_for_const_14 = xe),
                                          (Addr) &(temp_var_for_const_13 = 3)},
             "/home/shijia/Public/testprogram/s_cbrt.c_e.c:69:63");
  AssignD({(Addr)&temp_var_for_ext_1},
          (Addr) &(temp_var_for_const_15 = temp_var_for_callexp_2),
          "/home/shijia/Public/testprogram/s_cbrt.c_e.c:69:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_v(0.0 - r_) for_ext_1;
}

__typeof(__cbrt) cbrt __attribute__((weak, alias("__cbrt")));
#ifdef __NO_LONG_DOUBLE_MATH
__typeof(cbrtl) __cbrtl __attribute__((alias("__cbrt")));
__typeof(__cbrtl) cbrtl __attribute__((weak, alias("__cbrt")));
#endif
