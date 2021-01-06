#include "../ScDebug/scdebug.h"
/* s_tanl.c -- long double version of s_tan.c.
 * Conversion to long double by Ulrich Drepper,
 * Cygnus Support, drepper@cygnus.com.
 */

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

/* tanl(x)
 * Return tangent function of x.
 *
 * kernel function:
 *	__kernel_tanl		... tangent function on [-pi/4,pi/4]
 *	__ieee754_rem_pio2l	... argument reduction routine
 *
 * Method.
 *      Let S,C and T denote the sin, cos and tan respectively on
 *	[-PI/4, +PI/4]. Reduce the argument x to y1+y2 = x-k*pi/2
 *	in [-pi/4 , +pi/4], and let n = k mod 4.
 *	We have
 *
 *          n        sin(x)      cos(x)        tan(x)
 *     ----------------------------------------------------------
 *	    0	       S	   C		 T
 *	    1	       C	  -S		-1/T
 *	    2	      -S	  -C		 T
 *	    3	      -C	   S		-1/T
 *     ----------------------------------------------------------
 *
 * Special cases:
 *      Let trig be any of sin, cos, or tan.
 *      trig(+-INF)  is NaN, with signals;
 *      trig(NaN)    is that NaN;
 *
 * Accuracy:
 *	TRIG(x) returns trig(x) nearly rounded
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

#ifndef __have_fpu_tan

long double __ieee754_tanl(long double x) {
  long double y[2], z = 0.0;
  int32_t n, se;

  /* High word of x. */
  long double temp_var_for_const_0;
  ge_u.value = x;
  AssignLd({(Addr) &(temp_var_for_const_0 = ge_u.value)}, (Addr)&x,
           "/home/shijia/Public/testprogram/s_tanl.c_e.c:60:3 "
           "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:258:14>");
  ;

  /* |x| ~< pi/4 */
  se &= 0x7fff;
  if (se <= 0x3ffe) {
    long double temp_var_for_ext_0;
    long double temp_var_for_const_1;
    long double temp_var_for_callexp_0;

    temp_var_for_callexp_0 = __kernel_tanl(x, z, 1);
    temp_var_for_ext_0 = temp_var_for_callexp_0;
    AssignLd({(Addr)&temp_var_for_ext_0},
             (Addr) &(temp_var_for_const_1 = temp_var_for_callexp_0),
             "/home/shijia/Public/testprogram/s_tanl.c_e.c:66:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  /* tan(Inf or NaN) is NaN */
  else {
    if (se == 0x7fff) {
      long double temp_var_for_ext_1;
      long double temp_var_for_tac_0;
      temp_var_for_tac_0 = x - x;

      temp_var_for_ext_1 = temp_var_for_tac_0;
      computeLdSub((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&x},
                   "/home/shijia/Public/testprogram/s_tanl.c_e.c:76:30");
      AssignLd({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_0,
               "/home/shijia/Public/testprogram/s_tanl.c_e.c:76:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_1;
    }

    /* argument reduction needed */
    else {
      n = __ieee754_rem_pio2l(x, y);
      long double temp_var_for_ext_2;
      long double temp_var_for_tac_1, temp_var_for_tac_2, temp_var_for_tac_3;
      long double temp_var_for_const_2, temp_var_for_const_3,
          temp_var_for_const_4, temp_var_for_const_5, temp_var_for_const_6;
      long double temp_var_for_callexp_1;

      temp_var_for_tac_1 = n & 1;

      temp_var_for_tac_2 = temp_var_for_tac_1 << 1;

      temp_var_for_tac_3 = 1 - temp_var_for_tac_2;

      temp_var_for_callexp_1 =
          __kernel_tanl(y[0], y[1], ((int)temp_var_for_tac_3));
      temp_var_for_ext_2 = temp_var_for_callexp_1;
      compute((Addr)&temp_var_for_tac_1, {(Addr) &(temp_var_for_const_3 = n),
                                          (Addr) &(temp_var_for_const_2 = 1)},
              "/home/shijia/Public/testprogram/s_tanl.c_e.c:87:68");
      compute((Addr)&temp_var_for_tac_2,
              {(Addr)&temp_var_for_tac_1, (Addr) &(temp_var_for_const_4 = 1)},
              "/home/shijia/Public/testprogram/s_tanl.c_e.c:87:73");
      computeSub((Addr)&temp_var_for_tac_3, {(Addr) &(temp_var_for_const_5 = 1),
                                             (Addr)&temp_var_for_tac_2},
                 "/home/shijia/Public/testprogram/s_tanl.c_e.c:87:62");
      AssignLd({(Addr)&temp_var_for_ext_2},
               (Addr) &(temp_var_for_const_6 = temp_var_for_callexp_1),
               "/home/shijia/Public/testprogram/s_tanl.c_e.c:87:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_2; /*   1 -- n even -1 -- n odd */
    }
  }
}

#endif

long double __tanl(long double x) {
  long double ret;

  ret = __ieee754_tanl(x);
  if (isnan(ret) && isinf(x)) {
    ret = __kernel_standard_l(x, x, ret, KMATHERRL_TAN_INF);
  }

  long double temp_var_for_ext_3;
  temp_var_for_ext_3 = ret;
  callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_3;
}

__typeof(__tanl) tanl __attribute__((weak, alias("__tanl")));

#endif
