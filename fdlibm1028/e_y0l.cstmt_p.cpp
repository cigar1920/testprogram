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

/* __ieee754_y0(x)
 * Bessel function of the second kind of order zero.
 * Method -- y0(x):
 *	1. For x<2.
 *	   Since
 *		y0(x) = 2/pi*(j0(x)*(ln(x/2)+Euler) + x^2/4 - ...)
 *	   therefore y0(x)-2/pi*j0(x)*ln(x) is an even function.
 *	   We use the following function to approximate y0,
 *		y0(x) = U(z)/V(z) + (2/pi)*(j0(x)*ln(x)), z= x^2
 *
 *	   Note: For tiny x, U/V = u0 and j0(x)~1, hence
 *		y0(tiny) = u0 + (2/pi)*ln(tiny), (choose tiny<2**-27)
 *	2. For x>=2.
 *		y0(x) = sqrt(2/(pi*x))*(p0(x)*cos(x0)+q0(x)*sin(x0))
 *	   where x0 = x-pi/4. It is better to compute sin(x0),cos(x0)
 *	   by the method mentioned above.
 *	3. Special cases: y0(0)=-inf, y0(x<0)=NaN, y0(inf)=0.
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

long double __ieee754_y0l(long double x) {
  long double z, s, c, ss, cc, u, v;
  int32_t ix;
  uint32_t se, i0, i1;

  static const long double one = 1.0L;
  static const long double invsqrtpi =
      5.6418958354775628694807945156077258584405e-1L;
  static const long double tpi = 6.3661977236758134307553505349005744813784e-1L;
  static const long double zero = 0.0;

  /* y0(x) = 2/pi ln(x) J0(x) + U(x^2)/V(x^2)
     0 < x <= 2
     peak relative error 1.7e-21 */
  static const long double U[6] = {
    (0.0 - 1.054912306975785573710813351985351350861E10L);
  long double temp_var_for_const_0, temp_var_for_const_1;
  , 2.520192609749295139432773849576523636127E10L,
      (0.0 - 1.856426071075602001239955451329519093395E9L);
  long double temp_var_for_const_2, temp_var_for_const_3;
  long double temp_var_for_tac_0;
  computeLdSub((Addr)&temp_var_for_tac_0,
               {(Addr) &(temp_var_for_const_1 = 0.0),
                (Addr) &(temp_var_for_const_0 =
                             1.054912306975785573710813351985351350861E10L)},
               "/home/shijia/Public/testprogram/e_y0l.c_e.c:75:12");
  , 4.079209129698891442683267466276785956784E7L,
      (0.0 - 3.440684087134286610316661166492641011539E5L);
  long double temp_var_for_const_4, temp_var_for_const_5;
  long double temp_var_for_tac_1;
  computeLdSub((Addr)&temp_var_for_tac_1,
               {(Addr) &(temp_var_for_const_3 = 0.0),
                (Addr) &(temp_var_for_const_2 =
                             1.856426071075602001239955451329519093395E9L)},
               "/home/shijia/Public/testprogram/e_y0l.c_e.c:77:12");
  , 1.005524356159130626192144663414848383774E3L,
};

static const long double V[5] = {
    1.429337283720789610137291929228082613676E11L,
    2.492593075325119157558811370165695013002E9L,
    2.186077620785925464237324417623665138376E7L,
    1.238407896366385175196515057064384929222E5L,
    4.693924035211032457494368947123233101664E2L,
    /*  1.000000000000000000000000000000000000000E0L */
};

GET_LDOUBLE_WORDS(se, i0, i1, x);
ix = se & IEEE854_LONG_DOUBLE_MAXEXP;
/* Y0(NaN) is NaN, y0(-inf) is Nan, y0(inf) is 0  */
if (se & 0x8000)
  return zero / (zero * x);
if (ix >= IEEE854_LONG_DOUBLE_MAXEXP)
  return one / (x + x * x);
if ((i0 | i1) == 0)
  return -HUGE_VALL + x; /* -inf and overflow exception.  */
if (ix >= 0x4000) {      /* |x| >= 2.0 */

  /* y0(x) = sqrt(2/(pi*x))*(p0(x)*sin(x0)+q0(x)*cos(x0))
   * where x0 = x-pi/4
   *      Better formula:
   *              cos(x0) = cos(x)cos(pi/4)+sin(x)sin(pi/4)
   *                      =  1/sqrt(2) * (sin(x) + cos(x))
   *              sin(x0) = sin(x)cos(3pi/4)-cos(x)sin(3pi/4)
   *                      =  1/sqrt(2) * (sin(x) - cos(x))
   * To avoid cancellation, use
   *              sin(x) +- cos(x) = -cos(2x)/(sin(x) -+ cos(x))
   * to compute the worse one.
   */
  __ieee754_sincosl(x, &s, &c);
  ss = s - c;
  cc = s + c;
  /*
   * j0(x) = 1/sqrt(pi) * (P(0,x)*cc - Q(0,x)*ss) / sqrt(x)
   * y0(x) = 1/sqrt(pi) * (P(0,x)*ss + Q(0,x)*cc) / sqrt(x)
   */
  if (ix < 0x7ffe) { /* make sure x+x not overflow */
    z = -__ieee754_cosl(x + x);
    if ((s * c) < zero)
      cc = z / ss;
    else
      ss = z / cc;
  }
  if (ix > 0x4080) /* 1e39 */
    z = (invsqrtpi * ss) / __ieee754_sqrtl(x);
  else {
    u = __j0_y0_pzerol(x);
    v = __j0_y0_qzerol(x);
    z = invsqrtpi * (u * ss + v * cc) / __ieee754_sqrtl(x);
  }
  return z;
}
if (ix <= 0x3fde) /* x < 2^-33 */
{
  z = -7.380429510868722527629822444004602747322E-2L + tpi * __ieee754_logl(x);
  return z;
}
z = x * x;
long double temp_var_for_tac_2;
computeLdSub((Addr)&temp_var_for_tac_2,
             {(Addr) &(temp_var_for_const_5 = 0.0),
              (Addr) &(temp_var_for_const_4 =
                           3.440684087134286610316661166492641011539E5L)},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:141:9");
computeLdMul((Addr)&z, {(Addr)&x, (Addr)&x},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:141:5");
u = U[0] + z * (U[1] + z * (U[2] + z * (U[3] + z * (U[4] + z * U[5]))));
long double temp_var_for_const_6, temp_var_for_const_7, temp_var_for_const_8,
    temp_var_for_const_9, temp_var_for_const_10, temp_var_for_const_11;
long double temp_var_for_tac_3, temp_var_for_tac_4, temp_var_for_tac_5,
    temp_var_for_tac_6, temp_var_for_tac_7, temp_var_for_tac_8,
    temp_var_for_tac_9, temp_var_for_tac_10, temp_var_for_tac_11;
computeLdMul((Addr)&temp_var_for_tac_3,
             {(Addr)&z, (Addr) &(temp_var_for_const_6 = U[5])},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:142:60");
computeLdAdd((Addr)&temp_var_for_tac_4,
             {(Addr) &(temp_var_for_const_7 = U[4]), (Addr)&temp_var_for_tac_3},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:142:52");
computeLdMul((Addr)&temp_var_for_tac_5, {(Addr)&z, (Addr)&temp_var_for_tac_4},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:142:48");
computeLdAdd((Addr)&temp_var_for_tac_6,
             {(Addr) &(temp_var_for_const_8 = U[3]), (Addr)&temp_var_for_tac_5},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:142:40");
computeLdMul((Addr)&temp_var_for_tac_7, {(Addr)&z, (Addr)&temp_var_for_tac_6},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:142:36");
computeLdAdd((Addr)&temp_var_for_tac_8,
             {(Addr) &(temp_var_for_const_9 = U[2]), (Addr)&temp_var_for_tac_7},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:142:28");
computeLdMul((Addr)&temp_var_for_tac_9, {(Addr)&z, (Addr)&temp_var_for_tac_8},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:142:24");
computeLdAdd((Addr)&temp_var_for_tac_10,
             {(Addr) &(temp_var_for_const_10 = U[1]),
              (Addr)&temp_var_for_tac_9},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:142:16");
computeLdMul((Addr)&temp_var_for_tac_11, {(Addr)&z, (Addr)&temp_var_for_tac_10},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:142:12");
computeLdAdd((Addr)&u, {(Addr) &(temp_var_for_const_11 = U[0]),
                        (Addr)&temp_var_for_tac_11},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:142:5");
v = V[0] + z * (V[1] + z * (V[2] + z * (V[3] + z * (V[4] + z))));
long double temp_var_for_const_12, temp_var_for_const_13, temp_var_for_const_14,
    temp_var_for_const_15, temp_var_for_const_16;
long double temp_var_for_tac_12, temp_var_for_tac_13, temp_var_for_tac_14,
    temp_var_for_tac_15, temp_var_for_tac_16, temp_var_for_tac_17,
    temp_var_for_tac_18, temp_var_for_tac_19;
computeLdAdd((Addr)&temp_var_for_tac_12,
             {(Addr) &(temp_var_for_const_12 = V[4]), (Addr)&z},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:143:52");
computeLdMul((Addr)&temp_var_for_tac_13, {(Addr)&z, (Addr)&temp_var_for_tac_12},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:143:48");
computeLdAdd((Addr)&temp_var_for_tac_14,
             {(Addr) &(temp_var_for_const_13 = V[3]),
              (Addr)&temp_var_for_tac_13},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:143:40");
computeLdMul((Addr)&temp_var_for_tac_15, {(Addr)&z, (Addr)&temp_var_for_tac_14},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:143:36");
computeLdAdd((Addr)&temp_var_for_tac_16,
             {(Addr) &(temp_var_for_const_14 = V[2]),
              (Addr)&temp_var_for_tac_15},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:143:28");
computeLdMul((Addr)&temp_var_for_tac_17, {(Addr)&z, (Addr)&temp_var_for_tac_16},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:143:24");
computeLdAdd((Addr)&temp_var_for_tac_18,
             {(Addr) &(temp_var_for_const_15 = V[1]),
              (Addr)&temp_var_for_tac_17},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:143:16");
computeLdMul((Addr)&temp_var_for_tac_19, {(Addr)&z, (Addr)&temp_var_for_tac_18},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:143:12");
computeLdAdd((Addr)&v, {(Addr) &(temp_var_for_const_16 = V[0]),
                        (Addr)&temp_var_for_tac_19},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:143:5");
long double temp_var_for_ext_0;
temp_var_for_ext_0 = (u / v + tpi * (__ieee754_j0l(x) * __ieee754_logl(x)));
long double temp_var_for_const_17;
long double temp_var_for_tac_20, temp_var_for_tac_21;
computeLdDiv((Addr)&temp_var_for_tac_20, {(Addr)&u, (Addr)&v},
             "toString(biExpr->getExprLoc())");
computeLdMul((Addr)&temp_var_for_tac_21,{(Addr)&(temp_var_for_const_17=tpi),(Addr)&__ieee754_j0l(getFVbyShadow<int>((Addr)&x) * __ieee754_logl(getFVbyShadow<int>((Addr)&x)},"/home/shijia/Public/testprogram/e_y0l.c_e.c:145:31");
computeLdAdd((Addr)&temp_var_for_ext_0,
             {(Addr)&temp_var_for_tac_20, (Addr)&temp_var_for_tac_21},
             "/home/shijia/Public/testprogram/e_y0l.c_e.c:145:22");
callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
callExp++; /*identify the function is  add move tmpShadow*/
return temp_var_for_ext_0;
}

/* wrapper y0 */
long double __y0l(long double x) {
  if ((islessequal(x, 0.0) || isgreater(x, X_TLOSS)) &&
      _LIB_VERSION != _IEEE_) {
    if (x < 0.0) {
      /* d = zero/(x-x) */
      feraiseexcept(FE_INVALID);
      return __kernel_standard_l(x, x, -HUGE_VALL, KMATHERRL_Y0_MINUS);
    } else if (x == 0.0)
      /* d = -one/(x-x) */
      return __kernel_standard_l(x, x, -HUGE_VALL, KMATHERRL_Y0_ZERO);
    else if (_LIB_VERSION != _POSIX_)
      /* y0(x>X_TLOSS) */
      return __kernel_standard_l(x, x, 0.0L, KMATHERRL_Y0_TLOSS);
  }

  long double temp_var_for_ext_1;
  temp_var_for_ext_1 = __ieee754_y0l(x);
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

__typeof(__y0l) y0l __attribute__((weak, alias("__y0l")));

#endif
