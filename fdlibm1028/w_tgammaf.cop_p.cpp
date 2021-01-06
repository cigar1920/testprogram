#include "../ScDebug/scdebug.h"
/* w_gammaf.c -- float version of w_gamma.c.
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

float __tgammaf(float x) {
  int local_signgam;
  float y = __ieee754_tgammaf_r(x, &local_signgam);

  if (!isfinite(y) && (isfinite(x) || isinf(x) < 0) && _LIB_VERSION != _IEEE_) {
    if (int temp_var_for_tac_0; int temp_var_for_const_0;
        temp_var_for_tac_0 = x == 0.0F;

        ) {
      float temp_var_for_ext_0;
      float temp_var_for_const_1;
      float temp_var_for_callexp_0;

      temp_var_for_callexp_0 =
          __kernel_standard_f(x, x, y, KMATHERRF_TGAMMA_ZERO);
      temp_var_for_ext_0 = temp_var_for_callexp_0;
      compute((Addr)&temp_var_for_tac_0,
              {(Addr)&x, (Addr) &(temp_var_for_const_0 = 0.0F)},
              "/home/shijia/Public/testprogram/w_tgammaf.c_e.c:25:11");
      AssignF({(Addr)&temp_var_for_ext_0},
              (Addr) &(temp_var_for_const_1 = temp_var_for_callexp_0),
              "/home/shijia/Public/testprogram/w_tgammaf.c_e.c:27:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_0;
    }
    /* tgammaf pole */
    else {
      if (int temp_var_for_tac_1; int temp_var_for_const_2;
          float temp_var_for_callexp_1;

          temp_var_for_callexp_1 = __ieee754_floorf(x);
          temp_var_for_tac_1 = temp_var_for_callexp_1 == x;

          &&int temp_var_for_tac_2; int temp_var_for_const_3;
          temp_var_for_tac_2 = x < 0.0f;

          ) {
        float temp_var_for_ext_1;
        float temp_var_for_const_4;
        float temp_var_for_callexp_2;

        temp_var_for_callexp_2 =
            __kernel_standard_f(x, x, y, KMATHERRF_TGAMMA_MINUS);
        temp_var_for_ext_1 = temp_var_for_callexp_2;
        compute(
            (Addr)&temp_var_for_tac_1,
            {(Addr) &(temp_var_for_const_2 = temp_var_for_callexp_1), (Addr)&x},
            "/home/shijia/Public/testprogram/w_tgammaf.c_e.c:35:31");
        compute((Addr)&temp_var_for_tac_2,
                {(Addr)&x, (Addr) &(temp_var_for_const_3 = 0.0f)},
                "/home/shijia/Public/testprogram/w_tgammaf.c_e.c:35:41");
        AssignF({(Addr)&temp_var_for_ext_1},
                (Addr) &(temp_var_for_const_4 = temp_var_for_callexp_2),
                "/home/shijia/Public/testprogram/w_tgammaf.c_e.c:37:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_1;
      }
      /* tgammaf domain */
      else {
        if (int temp_var_for_tac_3; int temp_var_for_const_5;
            temp_var_for_tac_3 = y == 0;

            ) {
          float temp_var_for_ext_2;
          float temp_var_for_const_6;
          float temp_var_for_callexp_3;

          temp_var_for_callexp_3 =
              __kernel_standard_f(x, x, y, KMATHERRF_TGAMMA_UNDERFLOW);
          temp_var_for_ext_2 = temp_var_for_callexp_3;
          compute((Addr)&temp_var_for_tac_3,
                  {(Addr)&y, (Addr) &(temp_var_for_const_5 = 0)},
                  "/home/shijia/Public/testprogram/w_tgammaf.c_e.c:46:15");
          AssignF({(Addr)&temp_var_for_ext_2},
                  (Addr) &(temp_var_for_const_6 = temp_var_for_callexp_3),
                  "/home/shijia/Public/testprogram/w_tgammaf.c_e.c:48:30");
          ;
          callExpStack.push(
              getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
          callExp++; /*identify the function is  add move tmpShadow*/
          return temp_var_for_ext_2;
        }
        /* tgamma underflow */
        else {
          float temp_var_for_ext_3;
          float temp_var_for_const_7;
          float temp_var_for_callexp_4;

          temp_var_for_callexp_4 =
              __kernel_standard_f(x, x, y, KMATHERRF_TGAMMA_OVERFLOW);
          temp_var_for_ext_3 = temp_var_for_callexp_4;
          AssignF({(Addr)&temp_var_for_ext_3},
                  (Addr) &(temp_var_for_const_7 = temp_var_for_callexp_4),
                  "/home/shijia/Public/testprogram/w_tgammaf.c_e.c:58:30");
          ;
          callExpStack.push(
              getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
          callExp++; /*identify the function is  add move tmpShadow*/
          return temp_var_for_ext_3;
        }
      }
    }
    /* tgammaf overflow */
  }
  float temp_var_for_ext_4;
  float temp_var_for_const_8;
  temp_var_for_ext_4 = local_signgam < 0 ? -y : y;
  AssignF({(Addr)&temp_var_for_ext_4},
          (Addr) &(temp_var_for_const_8 = local_signgam < 0 ? -y : y),
          "/home/shijia/Public/testprogram/w_tgammaf.c_e.c:70:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for(0.0 - e) xt_4;
}

__typeof(__tgammaf) tgammaf __attribute__((weak, alias("__tgammaf")));
