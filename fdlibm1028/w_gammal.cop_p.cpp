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
 *
 */

/* long double gammal(long double x)
 * Return the logarithm of the Gamma function of x.
 *
 * Method: call gammal_r
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

long double __gammal(long double x) {
  long double temp_var_for_ext_0;
  long double temp_var_for_const_0;
  temp_var_for_ext_0 = gammal_r(x, (&(signgam)));
  AssignLd({(Addr)&temp_var_for_ext_0},
           (Addr) &(temp_var_for_const_0 = gammal_r(x, (&(signgam)))),
           "/home/shijia/Public/testprogram/w_gammal.c_e.c:27:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

__typeof(__gammal) gammal __attribute__((weak, alias("__gammal")));

#endif
