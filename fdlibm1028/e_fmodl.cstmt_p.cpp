#include "../ScDebug/scdebug.h"
/* e_fmodl.c -- long double version of e_fmod.c.
 * Conversion to IEEE quad long double by Jakub Jelinek, jj@ultra.linux.cz.
 */
/*
 * ====================================================
 * Copyright (C) 1993, 2011 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 */

/*
 * __ieee754_fmodl(x,y)
 * Return x mod y in exact arithmetic
 * Method: shift and subtract
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

#ifndef __have_fpu_fmod

long double __ieee754_fmodl(long double x, long double y) {
  long double intpart;

  if (isinf(y)) {
    if (isinf(x)) {
      long double temp_var_for_ext_0;
      temp_var_for_ext_0 = x < 0 ? -0.0L : 0.0L;
      long double temp_var_for_const_0;
      AssignLd({(Addr)&temp_var_for_ext_0},
               (Addr) &(temp_var_for_const_0 = x < 0 ? -0.0L : 0.0L),
               "/home/shijia/Public/testprogram/e_fmodl.c_e.c:35:26");
      callExpStack.push(
          getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_v(0.0 - r_fo) r_ext_0;
    }

    long double temp_var_for_ext_1;
    temp_var_for_ext_1 = x;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }
  if (__ieee754_fabsl(x) <= __ieee754_fabsl(y)) {
    long double temp_var_for_ext_2;
    temp_var_for_ext_2 = x;
    AssignLd({(Addr)&temp_var_for_ext_2}, (Addr)&x,
             "/home/shijia/Public/testprogram/e_fmodl.c_e.c:50:24");
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  }

  (void)__ieee754_modfl(x / y, &intpart);
  long double temp_var_for_ext_3;
  temp_var_for_ext_3 = x - y * intpart;
  long double temp_var_for_tac_0, temp_var_for_tac_1;
  computeLdDiv((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&y},
               "/home/shijia/Public/testprogram/e_fmodl.c_e.c:58:30");
  computeLdMul((Addr)&temp_var_for_tac_1, {(Addr)&y, (Addr)&intpart},
               "/home/shijia/Public/testprogram/e_fmodl.c_e.c:58:26");
  computeLdSub((Addr)&temp_var_for_ext_3, {(Addr)&x, (Addr)&temp_var_for_tac_1},
               "/home/shijia/Public/testprogram/e_fmodl.c_e.c:58:22");
  callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_3;
}

#endif

long double __fmodl(long double x, long double y) {
  if ((isinf(x) || y == 0.0) && _LIB_VERSION != _IEEE_ && !isunordered(x, y))
    /* fmod(+-Inf,y) or fmod(x,0) */
    return __kernel_standard_l(x, y, y, KMATHERRL_FMOD);
  long double temp_var_for_ext_4;
  temp_var_for_ext_4 = __ieee754_fmodl(x, y);
  long double temp_var_for_callexp_0 =
      __ieee754_fmodl(getFVbyShadow<long double>((Addr)&x),
                      getFVbyShadow<long double>((Addr)&y));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  AssignLd({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_callexp_0,
           "/home/shijia/Public/testprogram/e_fmodl.c_e.c:71:22");
  callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_4;
}

__typeof(__fmodl) fmodl __attribute__((weak, alias("__fmodl")));

#endif
