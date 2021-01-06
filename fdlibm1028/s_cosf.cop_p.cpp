#include "../ScDebug/scdebug.h"
/* sf_cos.c -- float version of s_cos.c.
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

#ifndef __have_fpu_cos

float __ieee754_cosf(float x) {
  float y[2], z = 0.0;
  int32_t n, ix;

  GET_FLOAT_WORD(ix, x);

  /* |x| ~< pi/4 */
  ix &= IC(0x7fffffff);
  if (ix <= IC(0x3f490fd8)) {
    float temp_var_for_ext_0;
    float temp_var_for_const_0;
    float temp_var_for_callexp_0;

    temp_var_for_callexp_0 = __kernel_cosf(x, z);
    temp_var_for_ext_0 = temp_var_for_callexp_0;
    AssignF({(Addr)&temp_var_for_ext_0},
            (Addr) &(temp_var_for_const_0 = temp_var_for_callexp_0),
            "/home/shijia/Public/testprogram/s_cosf.c_e.c:32:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  /* cos(Inf or NaN) is NaN */
  else {
    if (!FLT_UWORD_IS_FINITE(ix)) {
      float temp_var_for_ext_1;
      float temp_var_for_tac_0;
      temp_var_for_tac_0 = x - x;

      temp_var_for_ext_1 = temp_var_for_tac_0;
      computeFSub((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&x},
                  "/home/shijia/Public/testprogram/s_cosf.c_e.c:42:30");
      AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_0,
              "/home/shijia/Public/testprogram/s_cosf.c_e.c:42:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_1;
    }

    /* argument reduction needed */
    else {
      n = __ieee754_rem_pio2f(x, y);
      int temp_var_for_ext_2;
      temp_var_for_ext_2 = (int)(n & 3);
      switch (temp_var_for_ext_2) {
      case 0: {
        float temp_var_for_ext_3;
        float temp_var_for_const_1;
        float temp_var_for_callexp_1;

        temp_var_for_callexp_1 = __kernel_cosf(y[0], y[1]);
        temp_var_for_ext_3 = temp_var_for_callexp_1;
        AssignF({(Addr)&temp_var_for_ext_3},
                (Addr) &(temp_var_for_const_1 = temp_var_for_callexp_1),
                "/home/shijia/Public/testprogram/s_cosf.c_e.c:57:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_3;
      }

      case 1: {
        float temp_var_for_ext_4;
        float temp_var_for_const_2;
        temp_var_for_callexp_2 = __kernel_sinf(y[0], y[1], 1);
        temp_var_for_ext_4 = (-(temp_var_for_callexp_2));
        AssignF({(Addr)&temp_var_for_ext_4},
                (Addr) &(temp_var_for_const_2 = (-(temp_var_for_callexp_2))),
                "/home/shijia/Public/testprogram/s_cosf.c_e.c:66:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
        callExp++; /*identify the function is  add move tmpShadow*/
        return (0.0 - * / return temp_var_for_ext_4);
      }

      case 2: {
        float temp_var_for_ext_5;
        float temp_var_for_const_3;
        temp_var_for_callexp_3 = __kernel_cosf(y[0], y[1]);
        temp_var_for_ext_5 = (-(temp_var_for_callexp_3));
        AssignF({(Addr)&temp_var_for_ext_5},
                (Addr) &(temp_var_for_const_3 = (-(temp_var_for_callexp_3))),
                "/home/shijia/Public/testprogram/s_cosf.c_e.c:75:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
        callExp++; /*identify the function is  add move tmpShadow*/
        return (0.0 - return temp_var_for_ext_5);
      }

      default: {
        float temp_var_for_ext_6;
        float temp_var_for_const_4;
        float temp_var_for_callexp_4;

        temp_var_for_callexp_4 = __kernel_sinf(y[0], y[1], 1);
        temp_var_for_ext_6 = temp_var_for_callexp_4;
        AssignF({(Addr)&temp_var_for_ext_6},
                (Addr) &(temp_var_for_const_4 = temp_var_for_callexp_4),
                "/home/shijia/Public/testprogram/s_cosf.c_e.c:84:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_6;
      }
      }
    }
  }
}

#endif

float __cosf(float x) {
  float ret;

  float temp_var_for_const_5;
  float temp_var_for_callexp_5;

  temp_var_for_callexp_5 = __ieee754_cosf(x);
  ret = temp_var_for_callexp_5;
  AssignF({(Addr)&ret}, (Addr) &(temp_var_for_const_5 = temp_var_for_callexp_5),
          "/home/shijia/Public/testprogram/s_cosf.c_e.c:100:7");
  ;
  if (isnan(ret) && !isnan(x)) {
    float temp_var_for_const_6;
    float temp_var_for_callexp_6;

    temp_var_for_callexp_6 = __kernel_standard_f(x, x, ret, KMATHERRF_COS_INF);
    ret = temp_var_for_callexp_6;
    AssignF({(Addr)&ret},
            (Addr) &(temp_var_for_const_6 = temp_var_for_callexp_6),
            "/home/shijia/Public/testprogram/s_cosf.c_e.c:102:9");
    ;
  }

  float temp_var_for_ext_7;
  temp_var_for_ext_7 = ret;
  AssignF({(Addr)&temp_var_for_ext_7}, (Addr)&ret,
          "/home/shijia/Public/testprogram/s_cosf.c_e.c:106:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_7;
}

__typeof(__cosf) cosf __attribute__((weak, alias("__cosf")));
