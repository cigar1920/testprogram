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

  GET_LDOUBLE_WORDS(ex, hx, lx, x);
  GET_LDOUBLE_WORDS(ep, hp, lp, p);
  sx = ex & 0x8000;
  qs = (sx ^ (ep & 0x8000)) >> 15;
  ep &= IEEE854_LONG_DOUBLE_MAXEXP;
  ex &= IEEE854_LONG_DOUBLE_MAXEXP;

  /* Purge off exception values.  */
  if ((ep | hp | lp) == 0)
    return (x * p) / (x * p);                /* p = 0 */
  if ((ex == IEEE854_LONG_DOUBLE_MAXEXP)     /* x not finite */
      || ((ep == IEEE854_LONG_DOUBLE_MAXEXP) /* p is NaN */
          && ((hp | lp) != 0)))
    return (x * p) / (x * p);

  if (ep <= 0x7ffb)
    x = __ieee754_fmodl(x, 8 * p); /* now x < 8p */

  if (((ex - ep) | (hx - hp) | (lx - lp)) == 0) {
    *quo = qs ? -1 : 1;
    return zero * x;
  }

  long double temp_var_for_ext_0;
  temp_var_for_ext_0 = __ieee754_fabsl(x);
  long double temp_var_for_const_0;AssignLd({(Addr)&temp_var_for_ext_0},(Addr)&(temp_var_for_const_0=__ieee754_fabsl(getFVbyShadow<int>((Addr)&x)),"/home/shijia/Public/testprogram/s_remquol.c_e.c:60:22"); // x
  /*(__ieee754_fabsl(x))*/
  x = temp_var_for_ext_0;AssignLd({(Addr)&x},(Addr)&temp_var_for_ext_0,"/home/shijia/Public/testprogram/s_remquol.c_e.c:62:5");
  long double temp_var_for_ext_1;
  temp_var_for_ext_1 = __ieee754_fabsl(p);long double temp_var_for_const_1;AssignLd({(Addr)&temp_var_for_ext_1},(Addr)&(temp_var_for_const_1=__ieee754_fabsl(getFVbyShadow<int>((Addr)&p)),"/home/shijia/Public/testprogram/s_remquol.c_e.c:64:22"); // p
  /*(__ieee754_fabsl(p))*/
  p = temp_var_for_ext_1;AssignLd({(Addr)&p},(Addr)&temp_var_for_ext_1,"/home/shijia/Public/testprogram/s_remquol.c_e.c:66:5");
  cquo = 0;

  if (x >= 4 * p);long double temp_var_for_const_2; {
    x -= 4 * p;
    long double temp_var_for_const_3;
    long double temp_var_for_tac_0;
    computeLdMul((Addr)&temp_var_for_tac_0,
                 {(Addr) &(temp_var_for_const_2 = 4), (Addr)&p},
                 "/home/shijia/Public/testprogram/s_remquol.c_e.c:70:12");
    cquo += 4;
    long double temp_var_for_tac_1;
    computeLdMul((Addr)&temp_var_for_tac_1,
                 {(Addr) &(temp_var_for_const_3 = 4), (Addr)&p},
                 "toString(biExpr->getExprLoc())");}
  if (x >= 2 * p);long double temp_var_for_const_4; {
    x -= 2 * p;
    long double temp_var_for_const_5;
    long double temp_var_for_tac_2;
    computeLdMul((Addr)&temp_var_for_tac_2,
                 {(Addr) &(temp_var_for_const_4 = 2), (Addr)&p},
                 "/home/shijia/Public/testprogram/s_remquol.c_e.c:74:12");
    cquo += 2;
    long double temp_var_for_tac_3;
    computeLdMul((Addr)&temp_var_for_tac_3,
                 {(Addr) &(temp_var_for_const_5 = 2), (Addr)&p},
                 "toString(biExpr->getExprLoc())");}

  if (ep < 0x0002) {
    if (x + x > p) {
      x -= p;
      ++cquo;
      if (x + x >= p) {
        x -= p;
        ++cquo;
      }
    }
  } else {
    long double p_half = 0.5 * p;

    if (x > p_half) {
      x -= p;
      ++cquo;
      if (x >= p_half) {
        x -= p;
        ++cquo;
      }
    }
  }

  *quo = qs ? -cquo : cquo;

  if (sx)
    x = -x;
  long double temp_var_for_ext_2;
  temp_var_for_ext_2 = x;AssignLd({(Addr)&temp_var_for_ext_2},(Addr)&x,"/home/shijia/Public/testprogram/s_remquol.c_e.c:105:22");
  callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_2;
}

#endif

long double __remquol(long double x, long double y, int *quo) {
  long double temp_var_for_ext_3;
  temp_var_for_ext_3 = __ieee754_remquol(x, y, quo);
  long double temp_var_for_callexp_0 =
      __ieee754_remquol(getFVbyShadow<long double>((Addr)&x),
                        getFVbyShadow<long double>((Addr)&y), (quo));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  AssignLd({(Addr)&temp_var_for_ext_3}, ,
           "/home/shijia/Public/testprogram/s_remquol.c_e.c:115:22");
  callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_3;
}

__typeof(__remquol) remquol __attribute__((weak, alias("__remquol")));

#endif
