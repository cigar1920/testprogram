#include "../ScDebug/scdebug.h"
/* @(#)s_ldexp.c 1.3 95/01/18 */
/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunSoft, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_ldexp

double __ieee754_ldexp(double value, int exp) {
  if (!isfinite(value) || int temp_var_for_tac_0; int temp_var_for_const_0;
      temp_var_for_tac_0 = value == 0.0;

      ) {
    double temp_var_for_ext_0;
    temp_var_for_ext_0 = value;
    compute((Addr)&temp_var_for_tac_0,
            {(Addr)&value, (Addr) &(temp_var_for_const_0 = 0.0)},
            "/home/shijia/Public/testprogram/s_ldexp.c_e.c:20:33");
    AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&value,
            "/home/shijia/Public/testprogram/s_ldexp.c_e.c:22:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  double temp_var_for_ext_1;
  double temp_var_for_const_1;
  double temp_var_for_callexp_0;

  temp_var_for_callexp_0 = __ieee754_scalbn(value, exp);
  temp_var_for_ext_1 = temp_var_for_callexp_0;
  AssignD({(Addr)&temp_var_for_ext_1},
          (Addr) &(temp_var_for_const_1 = temp_var_for_callexp_0),
          "/home/shijia/Public/testprogram/s_ldexp.c_e.c:29:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

#endif

double __ldexp(double x, int n) {
  double temp_var_for_const_2;
  double temp_var_for_callexp_1;

  temp_var_for_callexp_1 = __ieee754_ldexp(x, n);
  x = temp_var_for_callexp_1;
  AssignD({(Addr)&x}, (Addr) &(temp_var_for_const_2 = temp_var_for_callexp_1),
          "/home/shijia/Public/testprogram/s_ldexp.c_e.c:38:5");
  ;
  if (!isfinite(x) || int temp_var_for_tac_1; int temp_var_for_const_3;
      temp_var_for_tac_1 = x == 0.0;

      ) {
    __set_errno(ERANGE);
  }

  double temp_var_for_ext_2;
  temp_var_for_ext_2 = x;
  compute((Addr)&temp_var_for_tac_1,
          {(Addr)&x, (Addr) &(temp_var_for_const_3 = 0.0)},
          "/home/shijia/Public/testprogram/s_ldexp.c_e.c:39:25");
  AssignD({(Addr)&temp_var_for_ext_2}, (Addr)&x,
          "/home/shijia/Public/testprogram/s_ldexp.c_e.c:44:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_2;
}

__typeof(__ldexp) ldexp __attribute__((weak, alias("__ldexp")));
#ifdef __NO_LONG_DOUBLE_MATH
__typeof(__ldexpl) __ldexpl __attribute__((alias("__ldexp")));
__typeof(__ldexpl) ldexpl __attribute__((weak, alias("__ldexp")));
#endif
