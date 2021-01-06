#include "../ScDebug/scdebug.h"
/* s_logbf.c -- float version of s_logb.c.
 * Conversion to float by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.
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

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

float __logbf(float x) {
  int32_t ix, rix;

  GET_FLOAT_WORD(ix, x);
  ix &= IC(0x7fffffff); /* high |x| */
  if (ix == 0) {
    float temp_var_for_ext_0;
    float temp_var_for_tac_0;
    float temp_var_for_const_0, temp_var_for_const_1;
    float temp_var_for_callexp_0;

    temp_var_for_callexp_0 = fabsf(x);
    temp_var_for_tac_0 = ((float)(-(1.0))) / temp_var_for_callexp_0;

    temp_var_for_ext_0 = temp_var_for_tac_0;
    computeFDiv((Addr)&temp_var_for_tac_0,
                {(Addr) &(temp_var_for_const_1 = ((float)(-(1.0)))),
                 (Addr) &(temp_var_for_const_0 = temp_var_for_callexp_0)},
                "/home/shijia/Public/testprogram/s_logbf.c_e.c:27:38");
    AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_0,
            "/home/shijia/Public/testprogram/s_logbf.c_e.c:27:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    (0.0 - etu) rn temp_var_for_ext_0;
  }

  if (ix >= IC(0x7f800000)) {
    float temp_var_for_ext_1;
    float temp_var_for_tac_1;
    temp_var_for_tac_1 = x * x;

    temp_var_for_ext_1 = temp_var_for_tac_1;
    computeFMul((Addr)&temp_var_for_tac_1, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/s_logbf.c_e.c:35:28");
    AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_1,
            "/home/shijia/Public/testprogram/s_logbf.c_e.c:35:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }

  if ((rix = ix >> IEEE754_FLOAT_SHIFT) == 0) {
    /* POSIX specifies that denormal number is treated as
       though it were normalized.  */
    rix -= count_leading_zeros(ix) - 9;
  }
  float temp_var_for_ext_2;
  float temp_var_for_tac_2;
  float temp_var_for_const_2, temp_var_for_const_3, temp_var_for_const_4;
  temp_var_for_tac_2 = rix - IEEE754_FLOAT_BIAS;

  temp_var_for_ext_2 = ((float)temp_var_for_tac_2);
  computeSub((Addr)&temp_var_for_tac_2,
             {(Addr) &(temp_var_for_const_3 = rix),
              (Addr) &(temp_var_for_const_2 = IEEE754_FLOAT_BIAS)},
             "/home/shijia/Public/testprogram/s_logbf.c_e.c:47:36");
  AssignF({(Addr)&temp_var_for_ext_2},
          (Addr) &(temp_var_for_const_4 = ((float)temp_var_for_tac_2)),
          "/home/shijia/Public/testprogram/s_logbf.c_e.c:47:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_2;
}

__typeof(__logbf) logbf __attribute__((weak, alias("__logbf")));
