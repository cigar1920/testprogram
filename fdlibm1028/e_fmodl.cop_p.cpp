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
      long double temp_var_for_const_0;
      temp_var_for_ext_0 = x < 0 ? -0.0L : 0.0L;
      AssignLd({(Addr)&temp_var_for_ext_0},
               (Addr) &(temp_var_for_const_0 = x < 0 ? -0.0L : 0.0L),
               "/home/shijia/Public/testprogram/e_fmodl.c_e.c:35:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_v(0.0 - r_fo) r_ext_0;
    }

    long double temp_var_for_ext_1;
    temp_var_for_ext_1 = x;
    AssignLd({(Addr)&temp_var_for_ext_1}, (Addr)&x,
             "/home/shijia/Public/testprogram/e_fmodl.c_e.c:43:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }
  if (int temp_var_for_tac_0; int temp_var_for_const_1, temp_var_for_const_2;
      long double temp_var_for_callexp_0;

      long double temp_var_for_callexp_1;

      temp_var_for_callexp_0 = fabsl(x); temp_var_for_callexp_1 = fabsl(y);
      temp_var_for_tac_0 = temp_var_for_callexp_0 <= temp_var_for_callexp_1;

      ) {
    long double temp_var_for_ext_2;
    temp_var_for_ext_2 = x;
    compute((Addr)&temp_var_for_tac_0,
            {(Addr) &(temp_var_for_const_2 = temp_var_for_callexp_0),
             (Addr) &(temp_var_for_const_1 = temp_var_for_callexp_1)},
            "/home/shijia/Public/testprogram/e_fmodl.c_e.c:48:26");
    AssignLd({(Addr)&temp_var_for_ext_2}, (Addr)&x,
             "/home/shijia/Public/testprogram/e_fmodl.c_e.c:50:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  }

  (void)__ieee754_modfl(x / y, &intpart);
  long double temp_var_for_ext_3;
  long double temp_var_for_tac_1, temp_var_for_tac_2;
  temp_var_for_tac_1 = y * intpart;

  temp_var_for_tac_2 = x - temp_var_for_tac_1;

  temp_var_for_ext_3 = temp_var_for_tac_2;
  computeLdMul((Addr)&temp_var_for_tac_1, {(Addr)&y, (Addr)&intpart},
               "/home/shijia/Public/testprogram/e_fmodl.c_e.c:58:30");
  computeLdSub((Addr)&temp_var_for_tac_2, {(Addr)&x, (Addr)&temp_var_for_tac_1},
               "/home/shijia/Public/testprogram/e_fmodl.c_e.c:58:26");
  AssignLd({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_2,
           "/home/shijia/Public/testprogram/e_fmodl.c_e.c:58:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_3;
}

#endif

long double __fmodl(long double x, long double y) {
  if ((isinf(x) || int temp_var_for_tac_3; int temp_var_for_const_3;
       temp_var_for_tac_3 = y == 0.0;

       ) &&
      _LIB_VERSION != _IEEE_ && !isunordered(x, y))
  /* fmod(+-Inf,y) or fmod(x,0) */
  {
    long double temp_var_for_ext_4;
    long double temp_var_for_const_4;
    long double temp_var_for_callexp_2;

    temp_var_for_callexp_2 = __kernel_standard_l(x, y, y, KMATHERRL_FMOD);
    temp_var_for_ext_4 = temp_var_for_callexp_2;
    compute((Addr)&temp_var_for_tac_3,
            {(Addr)&y, (Addr) &(temp_var_for_const_3 = 0.0)},
            "/home/shijia/Public/testprogram/e_fmodl.c_e.c:67:22");
    AssignLd({(Addr)&temp_var_for_ext_4},
             (Addr) &(temp_var_for_const_4 = temp_var_for_callexp_2),
             "/home/shijia/Public/testprogram/e_fmodl.c_e.c:71:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_4;
  }

  long double temp_var_for_ext_5;
  long double temp_var_for_const_5;
  long double temp_var_for_callexp_3;

  temp_var_for_callexp_3 = __ieee754_fmodl(x, y);
  temp_var_for_ext_5 = temp_var_for_callexp_3;
  AssignLd({(Addr)&temp_var_for_ext_5},
           (Addr) &(temp_var_for_const_5 = temp_var_for_callexp_3),
           "/home/shijia/Public/testprogram/e_fmodl.c_e.c:78:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_5;
}

__typeof(__fmodl) fmodl __attribute__((weak, alias("__fmodl")));

#endif
