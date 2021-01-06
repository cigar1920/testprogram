#include "../ScDebug/scdebug.h"
/* @(#)w_gamma.c 5.1 93/09/24 */
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

/* double gamma(double x)
 * Return  the logarithm of the Gamma function of x or the Gamma function of x,
 * depending on the library mode.
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

double __tgamma(double x) {
  int local_signgam;
  double y = __ieee754_tgamma_r(x, &local_signgam);

  if (!isfinite(y) && (isfinite(x) || isinf(x) < 0) && _LIB_VERSION != _IEEE_) {
    if (int temp_var_for_tac_0; int temp_var_for_const_0;
        temp_var_for_tac_0 = x == 0.0;

        ) {
      double temp_var_for_ext_0;
      double temp_var_for_const_1;
      double temp_var_for_callexp_0;

      temp_var_for_callexp_0 = __kernel_standard(x, x, y, KMATHERR_TGAMMA_ZERO);
      temp_var_for_ext_0 = temp_var_for_callexp_0;
      compute((Addr)&temp_var_for_tac_0,
              {(Addr)&x, (Addr) &(temp_var_for_const_0 = 0.0)},
              "/home/shijia/Public/testprogram/w_tgamma.c_e.c:27:11");
      AssignD({(Addr)&temp_var_for_ext_0},
              (Addr) &(temp_var_for_const_1 = temp_var_for_callexp_0),
              "/home/shijia/Public/testprogram/w_tgamma.c_e.c:29:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_0;
    }
    /* tgamma pole */
    else {
      if (int temp_var_for_tac_1; int temp_var_for_const_2;
          double temp_var_for_callexp_1;

          temp_var_for_callexp_1 = __ieee754_floor(x);
          temp_var_for_tac_1 = temp_var_for_callexp_1 == x;

          &&int temp_var_for_tac_2; int temp_var_for_const_3;
          temp_var_for_tac_2 = x < 0.0;

          ) {
        double temp_var_for_ext_1;
        double temp_var_for_const_4;
        double temp_var_for_callexp_2;

        temp_var_for_callexp_2 =
            __kernel_standard(x, x, y, KMATHERR_TGAMMA_MINUS);
        temp_var_for_ext_1 = temp_var_for_callexp_2;
        compute(
            (Addr)&temp_var_for_tac_1,
            {(Addr) &(temp_var_for_const_2 = temp_var_for_callexp_1), (Addr)&x},
            "/home/shijia/Public/testprogram/w_tgamma.c_e.c:37:30");
        compute((Addr)&temp_var_for_tac_2,
                {(Addr)&x, (Addr) &(temp_var_for_const_3 = 0.0)},
                "/home/shijia/Public/testprogram/w_tgamma.c_e.c:37:40");
        AssignD({(Addr)&temp_var_for_ext_1},
                (Addr) &(temp_var_for_const_4 = temp_var_for_callexp_2),
                "/home/shijia/Public/testprogram/w_tgamma.c_e.c:39:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_1;
      }
      /* tgamma domain */
      else {
        if (int temp_var_for_tac_3; int temp_var_for_const_5;
            temp_var_for_tac_3 = y == 0;

            ) {
          double temp_var_for_ext_2;
          double temp_var_for_const_6;
          double temp_var_for_callexp_3;

          temp_var_for_callexp_3 =
              __kernel_standard(x, x, y, KMATHERR_TGAMMA_UNDERFLOW);
          temp_var_for_ext_2 = temp_var_for_callexp_3;
          compute((Addr)&temp_var_for_tac_3,
                  {(Addr)&y, (Addr) &(temp_var_for_const_5 = 0)},
                  "/home/shijia/Public/testprogram/w_tgamma.c_e.c:47:15");
          AssignD({(Addr)&temp_var_for_ext_2},
                  (Addr) &(temp_var_for_const_6 = temp_var_for_callexp_3),
                  "/home/shijia/Public/testprogram/w_tgamma.c_e.c:49:30");
          ;
          callExpStack.push(
              getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
          callExp++; /*identify the function is  add move tmpShadow*/
          return temp_var_for_ext_2;
        }
        /* tgamma underflow */
        else {
          double temp_var_for_ext_3;
          double temp_var_for_const_7;
          double temp_var_for_callexp_4;

          temp_var_for_callexp_4 =
              __kernel_standard(x, x, y, KMATHERR_TGAMMA_OVERFLOW);
          temp_var_for_ext_3 = temp_var_for_callexp_4;
          AssignD({(Addr)&temp_var_for_ext_3},
                  (Addr) &(temp_var_for_const_7 = temp_var_for_callexp_4),
                  "/home/shijia/Public/testprogram/w_tgamma.c_e.c:59:30");
          ;
          callExpStack.push(
              getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
          callExp++; /*identify the function is  add move tmpShadow*/
          return temp_var_for_ext_3;
        }
      }
    }
    /* tgamma overflow */
  }
  double temp_var_for_ext_4;
  double temp_var_for_const_8;
  temp_var_for_ext_4 = local_signgam < 0 ? -y : y;
  AssignD({(Addr)&temp_var_for_ext_4},
          (Addr) &(temp_var_for_const_8 = local_signgam < 0 ? -y : y),
          "/home/shijia/Public/testprogram/w_tgamma.c_e.c:71:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for(0.0 - e) xt_4;
}

__typeof(__tgamma) tgamma __attribute__((weak, alias("__tgamma")));
#ifdef __NO_LONG_DOUBLE_MATH
__typeof(__tgammal) __tgammal __attribute__((alias("__tgamma")));
__typeof(__tgammal) tgammal __attribute__((weak, alias("__tgamma")));
#endif
