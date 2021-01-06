#include "../ScDebug/scdebug.h"
/* s_nearbyintf.c -- float version of s_nearbyint.c.
 * Conversion to float by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.
 */
/* Adapted for use as nearbyint by Ulrich Drepper <drepper@cygnus.com>.  */

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

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

float __nearbyintf(float x) {
  fenv_t env;
  float value;

  feholdexcept(&env);
  float temp_var_for_const_0;
  float temp_var_for_callexp_0;

  temp_var_for_callexp_0 = __ieee754_rintf(x);
  value = temp_var_for_callexp_0;
  AssignF({(Addr)&value},
          (Addr) &(temp_var_for_const_0 = temp_var_for_callexp_0),
          "/home/shijia/Public/testprogram/s_nearbyintf.c_e.c:26:9");
  ;
  fesetenv(&env);
  float temp_var_for_ext_0;
  temp_var_for_ext_0 = value;
  AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&value,
          "/home/shijia/Public/testprogram/s_nearbyintf.c_e.c:29:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

__typeof(__nearbyintf) nearbyintf __attribute__((weak, alias("__nearbyintf")));
