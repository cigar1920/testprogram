#include "../ScDebug/scdebug.h"
/* s_tanf.c -- float version of s_tan.c.
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

#ifndef __have_fpu_tan

float __ieee754_tanf(float x) {
  float y[2], z = 0.0;
  int32_t n, ix;

  GET_FLOAT_WORD(ix, x);

  /* |x| ~< pi/4 */
  ix &= IC(0x7fffffff);
  if (ix <= IC(0x3f490fda)) {
    float temp_var_for_ext_0;
    float temp_var_for_const_0;
    float temp_var_for_callexp_0;

    temp_var_for_callexp_0 = __kernel_tanf(x, z, 1);
    temp_var_for_ext_0 = temp_var_for_callexp_0;
    AssignF({(Addr)&temp_var_for_ext_0},
            (Addr) &(temp_var_for_const_0 = temp_var_for_callexp_0),
            "/home/shijia/Public/testprogram/s_tanf.c_e.c:32:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  /* tan(Inf or NaN) is NaN */
  else {
    if (!FLT_UWORD_IS_FINITE(ix)) {
      float temp_var_for_ext_1;
      float temp_var_for_tac_0;
      temp_var_for_tac_0 = x - x;

      temp_var_for_ext_1 = temp_var_for_tac_0;
      computeFSub((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&x},
                  "/home/shijia/Public/testprogram/s_tanf.c_e.c:42:30");
      AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_0,
              "/home/shijia/Public/testprogram/s_tanf.c_e.c:42:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_1;
    }
    /* NaN */

    /* argument reduction needed */
    else {
      n = __ieee754_rem_pio2f(x, y);
      float temp_var_for_ext_2;
      float temp_var_for_tac_1, temp_var_for_tac_2, temp_var_for_tac_3;
      float temp_var_for_const_1, temp_var_for_const_2, temp_var_for_const_3,
          temp_var_for_const_4, temp_var_for_const_5;
      float temp_var_for_callexp_1;

      temp_var_for_tac_1 = n & 1;

      temp_var_for_tac_2 = temp_var_for_tac_1 << 1;

      temp_var_for_tac_3 = 1 - temp_var_for_tac_2;

      temp_var_for_callexp_1 =
          __kernel_tanf(y[0], y[1], ((int)temp_var_for_tac_3));
      temp_var_for_ext_2 = temp_var_for_callexp_1;
      compute((Addr)&temp_var_for_tac_1, {(Addr) &(temp_var_for_const_2 = n),
                                          (Addr) &(temp_var_for_const_1 = 1)},
              "/home/shijia/Public/testprogram/s_tanf.c_e.c:54:68");
      compute((Addr)&temp_var_for_tac_2,
              {(Addr)&temp_var_for_tac_1, (Addr) &(temp_var_for_const_3 = 1)},
              "/home/shijia/Public/testprogram/s_tanf.c_e.c:54:73");
      computeSub((Addr)&temp_var_for_tac_3, {(Addr) &(temp_var_for_const_4 = 1),
                                             (Addr)&temp_var_for_tac_2},
                 "/home/shijia/Public/testprogram/s_tanf.c_e.c:54:62");
      AssignF({(Addr)&temp_var_for_ext_2},
              (Addr) &(temp_var_for_const_5 = temp_var_for_callexp_1),
              "/home/shijia/Public/testprogram/s_tanf.c_e.c:54:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_2; /*   1 -- n even -1 -- n odd */
    }
  }
}

#endif

float __tanf(float x) {
  float ret;

  ret = __ieee754_tan(x);
  if (isnan(ret) && isinf(x)) {
    ret = __kernel_standard_f(x, x, ret, KMATHERRF_TAN_INF);
  }

  float temp_var_for_ext_3;
  temp_var_for_ext_3 = ret;
  callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_3;
}

__typeof(__tanf) tanf __attribute__((weak, alias("__tanf")));
