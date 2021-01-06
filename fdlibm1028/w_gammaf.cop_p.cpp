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

/* float gammaf(double x)
 * Return the logarithm of the Gamma function of x.
 *
 * Method: call gammaf_r
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

float __gammaf(float x) {
  float temp_var_for_ext_0;
  float temp_var_for_const_0;
  temp_var_for_ext_0 = gammaf_r(x, (&(signgam)));
  AssignF({(Addr)&temp_var_for_ext_0},
          (Addr) &(temp_var_for_const_0 = gammaf_r(x, (&(signgam)))),
          "/home/shijia/Public/testprogram/w_gammaf.c_e.c:25:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

__typeof(__gammaf) gammaf __attribute__((weak, alias("__gammaf")));
