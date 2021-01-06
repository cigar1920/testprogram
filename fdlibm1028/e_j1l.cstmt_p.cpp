#include "../ScDebug/scdebug.h"
/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 */

/* Long double expansions are
  Copyright (C) 2001 Stephen L. Moshier <moshier@na-net.ornl.gov>
  and are incorporated herein by permission of the author.  The author
  reserves the right to distribute this material elsewhere under different
  copying permissions.  These modifications are distributed here under
  the following terms:

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, see
    <http://www.gnu.org/licenses/>.  */

/* __ieee754_j1(x), __ieee754_y1(x)
 * Bessel function of the first kind of order one.
 * Method -- j1(x):
 *	1. For tiny x, we use j1(x) = x/2 - x^3/16 + x^5/384 - ...
 *	2. Reduce x to |x| since j1(x)=-j1(-x),  and
 *	   for x in (0,2)
 *		j1(x) = x/2 + x*z*R0/S0,  where z = x*x;
 *	   for x in (2,inf)
 *		j1(x) = sqrt(2/(pi*x))*(p1(x)*cos(x1)-q1(x)*sin(x1))
 *		y1(x) = sqrt(2/(pi*x))*(p1(x)*sin(x1)+q1(x)*cos(x1))
 *	   where x1 = x-3*pi/4. It is better to compute sin(x1),cos(x1)
 *	   as follow:
 *		cos(x1) =  cos(x)cos(3pi/4)+sin(x)sin(3pi/4)
 *			=  1/sqrt(2) * (sin(x) - cos(x))
 *		sin(x1) =  sin(x)cos(3pi/4)-cos(x)sin(3pi/4)
 *			= -1/sqrt(2) * (sin(x) + cos(x))
 *	   (To avoid cancellation, use
 *		sin(x) +- cos(x) = -cos(2x)/(sin(x) -+ cos(x))
 *	    to compute the worse one.)
 *
 *	3 Special cases
 *		j1(nan)= nan
 *		j1(0) = 0
 *		j1(inf) = 0
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

long double __ieee754_j1l(long double x) {
  long double z, c, r, s, ss, cc, u, v, y;
  int32_t ix;
  uint32_t se;

  static const long double hugeval = 1e4930L;
  static const long double one = 1.0L;
  static const long double invsqrtpi =
      5.6418958354775628694807945156077258584405e-1L;
  static const long double zero = 0.0;

  /* J1(x) = .5 x + x x^2 R(x^2) / S(x^2)
     0 <= x <= 2
     Peak relative error 4.5e-21 */
  static const long double R[5] = {
    (0.0 - 9.647406112428107954753770469290757756814E7L);
  long double temp_var_for_const_0, temp_var_for_const_1;
  , 2.686288565865230690166454005558203955564E6L,
      (0.0 - 3.689682683905671185891885948692283776081E4L);
  long double temp_var_for_const_2, temp_var_for_const_3;
  long double temp_var_for_tac_0;
  computeLdSub((Addr)&temp_var_for_tac_0,
               {(Addr) &(temp_var_for_const_1 = 0.0),
                (Addr) &(temp_var_for_const_0 =
                             9.647406112428107954753770469290757756814E7L)},
               "/home/shijia/Public/testprogram/e_j1l.c_e.c:82:12");
  , 2.195031194229176602851429567792676658146E2L,
      (0.0 - 5.124499848728030297902028238597308971319E-1L);
  long double temp_var_for_const_4, temp_var_for_const_5;
  long double temp_var_for_tac_1;
  computeLdSub((Addr)&temp_var_for_tac_1,
               {(Addr) &(temp_var_for_const_3 = 0.0),
                (Addr) &(temp_var_for_const_2 =
                             3.689682683905671185891885948692283776081E4L)},
               "/home/shijia/Public/testprogram/e_j1l.c_e.c:84:12");
};
static const long double S[4] = {
    1.543584977988497274437410333029029035089E9L,
    2.133542369567701244002565983150952549520E7L,
    1.394077011298227346483732156167414670520E5L,
    5.252401789085732428842871556112108446506E2L
    /*  1.000000000000000000000000000000000000000E0L, */
};

GET_LDOUBLE_EXP(se, x);
ix = se & 0x7fff;
if (ix >= 0x7fff)
  return one / x;
y = __ieee754_fabsl(x);
long double temp_var_for_const_6;
long double temp_var_for_tac_2;
computeLdSub((Addr)&temp_var_for_tac_2,
             {(Addr) &(temp_var_for_const_5 = 0.0),
              (Addr) &(temp_var_for_const_4 =
                           5.124499848728030297902028238597308971319E-1L)},
             "toString(biExpr->getExprLoc())");
AssignLd({(Addr)&y},(Addr)&(temp_var_for_const_6=__ieee754_fabsl(getFVbyShadow<int>((Addr)&x)),"/home/shijia/Public/testprogram/e_j1l.c_e.c:97:5");
  if (ix >= 0x4000) { /* |x| >= 2.0 */
  __ieee754_sincosl(y, &s, &c);
  ss = -s - c;
  cc = s - c;
  if (ix < 0x7ffe) { /* make sure y+y not overflow */
    z = __ieee754_cosl(y + y);
    if ((s * c) > zero)
      cc = z / ss;
    else
      ss = z / cc;
  }
  /*
   * j1(x) = 1/sqrt(pi) * (P(1,x)*cc - Q(1,x)*ss) / sqrt(x)
   * y1(x) = 1/sqrt(pi) * (P(1,x)*ss + Q(1,x)*cc) / sqrt(x)
   */
  if (ix > 0x4080)
    z = (invsqrtpi * cc) / __ieee754_sqrtl(y);
  else {
    u = __j1_y1_ponel(y);
    v = __j1_y1_qonel(y);
    z = invsqrtpi * (u * cc - v * ss) / __ieee754_sqrtl(y);
  }
  if (se & 0x8000)
    return -z;
  else
    return z;
  }
  if (ix < 0x3fde) /* |x| < 2^-33 */
  {
  if (hugeval + x > one)
    return 0.5 * x; /* inexact if x!=0 necessary */
  }
  z = x * x;computeLdMul((Addr)&z,{(Addr)&x,(Addr)&x},"/home/shijia/Public/testprogram/e_j1l.c_e.c:130:5");
  r = z * (R[0] + z * (R[1] + z * (R[2] + z * (R[3] + z * R[4]))));long double temp_var_for_const_7,temp_var_for_const_8,temp_var_for_const_9,temp_var_for_const_10,temp_var_for_const_11;long double temp_var_for_tac_3,temp_var_for_tac_4,temp_var_for_tac_5,temp_var_for_tac_6,temp_var_for_tac_7,temp_var_for_tac_8,temp_var_for_tac_9,temp_var_for_tac_10;computeLdMul((Addr)&temp_var_for_tac_3,{(Addr)&z,(Addr)&(temp_var_for_const_7=R[4])},"/home/shijia/Public/testprogram/e_j1l.c_e.c:131:53");computeLdAdd((Addr)&temp_var_for_tac_4,{(Addr)&(temp_var_for_const_8=R[3]),(Addr)&temp_var_for_tac_3},"/home/shijia/Public/testprogram/e_j1l.c_e.c:131:45");computeLdMul((Addr)&temp_var_for_tac_5,{(Addr)&z,(Addr)&temp_var_for_tac_4},"/home/shijia/Public/testprogram/e_j1l.c_e.c:131:41");computeLdAdd((Addr)&temp_var_for_tac_6,{(Addr)&(temp_var_for_const_9=R[2]),(Addr)&temp_var_for_tac_5},"/home/shijia/Public/testprogram/e_j1l.c_e.c:131:33");computeLdMul((Addr)&temp_var_for_tac_7,{(Addr)&z,(Addr)&temp_var_for_tac_6},"/home/shijia/Public/testprogram/e_j1l.c_e.c:131:29");computeLdAdd((Addr)&temp_var_for_tac_8,{(Addr)&(temp_var_for_const_10=R[1]),(Addr)&temp_var_for_tac_7},"/home/shijia/Public/testprogram/e_j1l.c_e.c:131:21");computeLdMul((Addr)&temp_var_for_tac_9,{(Addr)&z,(Addr)&temp_var_for_tac_8},"/home/shijia/Public/testprogram/e_j1l.c_e.c:131:17");computeLdAdd((Addr)&temp_var_for_tac_10,{(Addr)&(temp_var_for_const_11=R[0]),(Addr)&temp_var_for_tac_9},"/home/shijia/Public/testprogram/e_j1l.c_e.c:131:9");computeLdMul((Addr)&r,{(Addr)&z,(Addr)&temp_var_for_tac_10},"/home/shijia/Public/testprogram/e_j1l.c_e.c:131:5");
  s = S[0] + z * (S[1] + z * (S[2] + z * (S[3] + z)));long double temp_var_for_const_12,temp_var_for_const_13,temp_var_for_const_14,temp_var_for_const_15;long double temp_var_for_tac_11,temp_var_for_tac_12,temp_var_for_tac_13,temp_var_for_tac_14,temp_var_for_tac_15,temp_var_for_tac_16;computeLdAdd((Addr)&temp_var_for_tac_11,{(Addr)&(temp_var_for_const_12=S[3]),(Addr)&z},"/home/shijia/Public/testprogram/e_j1l.c_e.c:132:40");computeLdMul((Addr)&temp_var_for_tac_12,{(Addr)&z,(Addr)&temp_var_for_tac_11},"/home/shijia/Public/testprogram/e_j1l.c_e.c:132:36");computeLdAdd((Addr)&temp_var_for_tac_13,{(Addr)&(temp_var_for_const_13=S[2]),(Addr)&temp_var_for_tac_12},"/home/shijia/Public/testprogram/e_j1l.c_e.c:132:28");computeLdMul((Addr)&temp_var_for_tac_14,{(Addr)&z,(Addr)&temp_var_for_tac_13},"/home/shijia/Public/testprogram/e_j1l.c_e.c:132:24");computeLdAdd((Addr)&temp_var_for_tac_15,{(Addr)&(temp_var_for_const_14=S[1]),(Addr)&temp_var_for_tac_14},"/home/shijia/Public/testprogram/e_j1l.c_e.c:132:16");computeLdMul((Addr)&temp_var_for_tac_16,{(Addr)&z,(Addr)&temp_var_for_tac_15},"/home/shijia/Public/testprogram/e_j1l.c_e.c:132:12");computeLdAdd((Addr)&s,{(Addr)&(temp_var_for_const_15=S[0]),(Addr)&temp_var_for_tac_16},"/home/shijia/Public/testprogram/e_j1l.c_e.c:132:5");
  r *= x;
  long double temp_var_for_ext_0;
  temp_var_for_ext_0 = (x * 0.5 + r / s);long double temp_var_for_const_16;long double temp_var_for_tac_17,temp_var_for_tac_18;computeLdMul((Addr)&temp_var_for_tac_17,{(Addr)&x,(Addr)&(temp_var_for_const_16=0.5)},"/home/shijia/Public/testprogram/e_j1l.c_e.c:135:37");computeLdDiv((Addr)&temp_var_for_tac_18,{(Addr)&r,(Addr)&s},"/home/shijia/Public/testprogram/e_j1l.c_e.c:135:33");computeLdAdd((Addr)&temp_var_for_ext_0,{(Addr)&temp_var_for_tac_17,(Addr)&temp_var_for_tac_18},"/home/shijia/Public/testprogram/e_j1l.c_e.c:135:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

/* wrapper j1 */
long double __j1l(long double x) {
  if (isgreater(__ieee754_fabsl(x), X_TLOSS) && _LIB_VERSION != _IEEE_ &&
      _LIB_VERSION != _POSIX_)
    /* j1(|x|>X_TLOSS) */
    return __kernel_standard_l(x, x, 0.0L, KMATHERRL_J1_TLOSS);

  long double temp_var_for_ext_1;
  temp_var_for_ext_1 = __ieee754_j1l(x);
  long double temp_var_for_callexp_0 =
      __ieee754_j1l(getFVbyShadow<long double>((Addr)&x));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  AssignLd({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_callexp_0,
           "/home/shijia/Public/testprogram/e_j1l.c_e.c:149:22");
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

__typeof(__j1l) j1l __attribute__((weak, alias("__j1l")));

#endif
