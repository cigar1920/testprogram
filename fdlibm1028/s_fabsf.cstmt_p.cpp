#include "../ScDebug/scdebug.h"
/* s_fabsf.c -- float version of s_fabs.c.
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
 * fabsf(x) returns the absolute value of x.
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

float __fabsf(float x) {
  uint32_t ix;

  GET_FLOAT_WORD(ix, x);
  SET_FLOAT_WORD(x, ix & UC(0x7fffffff));
  float temp_var_for_ext_0;
  temp_var_for_ext_0 = x;
  AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&x,
          "/home/shijia/Public/testprogram/s_fabsf.c_e.c:29:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

__typeof(__fabsf) fabsf __attribute__((weak, alias("__fabsf")));
