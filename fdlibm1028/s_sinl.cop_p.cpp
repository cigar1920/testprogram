#include "../ScDebug/scdebug.h"
/* s_sinl.c -- long double version of s_sin.c.
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

/* sinl(x)
 * Return sine function of x.
 *
 * kernel function:
 *	__kernel_sinl		... sine function on [-pi/4,pi/4]
 *	__kernel_cosl		... cose function on [-pi/4,pi/4]
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

#ifndef __have_fpu_sin

long double __ieee754_sinl(long double x) {
  long double y[2], z = 0.0;
  int32_t n, se;
  uint32_t i0, i1;

  /* High word of x. */
  long double temp_var_for_const_0;
  ew_u.value = x;
  AssignLd({(Addr) &(temp_var_for_const_0 = ew_u.value)}, (Addr)&x,
           "/home/shijia/Public/testprogram/s_sinl.c_e.c:62:3 "
           "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
  ;
  (void)i1;

  /* |x| ~< pi/4 */
  se &= 0x7fff;
  if (se < 0x3ffe || (se == 0x3ffe && i0 <= UC(0xc90fdaa2))) {
    long double temp_var_for_ext_0;
    long double temp_var_for_const_1;
    long double temp_var_for_callexp_0;

    temp_var_for_callexp_0 = __kernel_sinl(x, z, 0);
    temp_var_for_ext_0 = temp_var_for_callexp_0;
    AssignLd({(Addr)&temp_var_for_ext_0},
             (Addr) &(temp_var_for_const_1 = temp_var_for_callexp_0),
             "/home/shijia/Public/testprogram/s_sinl.c_e.c:69:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  /* sin(Inf or NaN) is NaN */
  else {
    if (se == 0x7fff) {
      long double temp_var_for_ext_1;
      long double temp_var_for_tac_0;
      temp_var_for_tac_0 = x - x;

      temp_var_for_ext_1 = temp_var_for_tac_0;
      computeLdSub((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&x},
                   "/home/shijia/Public/testprogram/s_sinl.c_e.c:79:30");
      AssignLd({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_0,
               "/home/shijia/Public/testprogram/s_sinl.c_e.c:79:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_1;
    }

    /* argument reduction needed */
    else {
      n = __ieee754_rem_pio2l(x, y);
      int temp_var_for_ext_2;
      temp_var_for_ext_2 = (int)(n & 3);
      switch (temp_var_for_ext_2) {
      case 0: {
        long double temp_var_for_ext_3;
        long double temp_var_for_const_2;
        long double temp_var_for_callexp_1;

        temp_var_for_callexp_1 = __kernel_sinl(y[0], y[1], 1);
        temp_var_for_ext_3 = temp_var_for_callexp_1;
        AssignLd({(Addr)&temp_var_for_ext_3},
                 (Addr) &(temp_var_for_const_2 = temp_var_for_callexp_1),
                 "/home/shijia/Public/testprogram/s_sinl.c_e.c:94:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_3;
      }

      case 1: {
        long double temp_var_for_ext_4;
        long double temp_var_for_const_3;
        long double temp_var_for_callexp_2;

        temp_var_for_callexp_2 = __kernel_cosl(y[0], y[1]);
        temp_var_for_ext_4 = temp_var_for_callexp_2;
        AssignLd({(Addr)&temp_var_for_ext_4},
                 (Addr) &(temp_var_for_const_3 = temp_var_for_callexp_2),
                 "/home/shijia/Public/testprogram/s_sinl.c_e.c:103:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_4;
      }

      case 2: {
        long double temp_var_for_ext_5;
        long double temp_var_for_const_4;
        temp_var_for_callexp_3 = __kernel_sinl(y[0], y[1], 1);
        temp_var_for_ext_5 = (-(temp_var_for_callexp_3));
        AssignLd({(Addr)&temp_var_for_ext_5},
                 (Addr) &(temp_var_for_const_4 = (-(temp_var_for_callexp_3))),
                 "/home/shijia/Public/testprogram/s_sinl.c_e.c:112:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
        callExp++; /*identify the function is  add move tmpShadow*/
        return (0.0 - * / return temp_var_for_ext_5);
      }

      default: {
        long double temp_var_for_ext_6;
        long double temp_var_for_const_5;
        temp_var_for_callexp_4 = __kernel_cosl(y[0], y[1]);
        temp_var_for_ext_6 = (-(temp_var_for_callexp_4));
        AssignLd({(Addr)&temp_var_for_ext_6},
                 (Addr) &(temp_var_for_const_5 = (-(temp_var_for_callexp_4))),
                 "/home/shijia/Public/testprogram/s_sinl.c_e.c:121:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
        callExp++; /*identify the function is  add move tmpShadow*/
        return (0.0 - return temp_var_for_ext_6);
      }
      }
    }
  }
}

#endif

long double __sinl(long double x) {
  long double ret;

  long double temp_var_for_const_6;
  long double temp_var_for_callexp_5;

  temp_var_for_callexp_5 = __ieee754_sinl(x);
  ret = temp_var_for_callexp_5;
  AssignLd({(Addr)&ret},
           (Addr) &(temp_var_for_const_6 = temp_var_for_callexp_5),
           "/home/shijia/Public/testprogram/s_sinl.c_e.c:137:7");
  ;
  if (isnan(ret) && !isnan(x)) {
    long double temp_var_for_const_7;
    long double temp_var_for_callexp_6;

    temp_var_for_callexp_6 = __kernel_standard_l(x, x, ret, KMATHERRL_SIN_INF);
    ret = temp_var_for_callexp_6;
    AssignLd({(Addr)&ret},
             (Addr) &(temp_var_for_const_7 = temp_var_for_callexp_6),
             "/home/shijia/Public/testprogram/s_sinl.c_e.c:139:9");
    ;
  }

  long double temp_var_for_ext_7;
  temp_var_for_ext_7 = ret;
  AssignLd({(Addr)&temp_var_for_ext_7}, (Addr)&ret,
           "/home/shijia/Public/testprogram/s_sinl.c_e.c:143:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_7;
}

__typeof(__sinl) sinl __attribute__((weak, alias("__sinl")));

#endif
