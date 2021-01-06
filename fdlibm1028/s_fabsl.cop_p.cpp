#include "../ScDebug/scdebug.h"
/* s_fabsl.c -- long double version of s_fabs.c.
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

/*
 * fabsl(x) returns the absolute value of x.
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH
long double __fabsl(long double x) {
#ifdef __mc68000__
  ieee_long_double_shape_type *sh_u = (ieee_long_double_shape_type *)&x;
  sh_u->parts.sign_exponent &= 0x7fff;
#else
  uint32_t exp;

  long double temp_var_for_const_0;
  ge_u.value = x;
  AssignLd({(Addr) &(temp_var_for_const_0 = ge_u.value)}, (Addr)&x,
           "/home/shijia/Public/testprogram/s_fabsl.c_e.c:31:3 "
           "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:258:14>");
  ;
  long double temp_var_for_ext_0;
  temp_var_for_ext_0;
#endif
  long double temp_var_for_ext_1;
  temp_var_for_ext_1 = x;
  AssignLd({(Addr)&temp_var_for_ext_1}, (Addr)&x,
           "/home/shijia/Public/testprogram/s_fabsl.c_e.c:36:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

__typeof(__fabsl) fabsl __attribute__((weak, alias("__fabsl")));

#endif
