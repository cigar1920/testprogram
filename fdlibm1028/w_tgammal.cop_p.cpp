#include "../ScDebug/scdebug.h"
/* w_gammal.c -- long double version of w_gamma.c.
 * Conversion to long double by Ulrich Drepper,
 * Cygnus Support, drepper@cygnus.com.
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

/* long double gammal(double x)
 * Return the Gamma function of x.
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

long double __tgammal(long double x) {
  int local_signgam;
  long double y = __ieee754_tgammal_r(x, &local_signgam);

  if (!isfinite(y) && (isfinite(x) || isinf(x) < 0) && _LIB_VERSION != _IEEE_) {
    if (int temp_var_for_tac_0; int temp_var_for_const_0;
        temp_var_for_tac_0 = x == 0.0;

        ) {
      long double temp_var_for_ext_0;
      long double temp_var_for_const_1;
      long double temp_var_for_callexp_0;

      temp_var_for_callexp_0 =
          __kernel_standard_l(x, x, y, KMATHERRL_TGAMMA_ZERO);
      temp_var_for_ext_0 = temp_var_for_callexp_0;
      compute((Addr)&temp_var_for_tac_0,
              {(Addr)&x, (Addr) &(temp_var_for_const_0 = 0.0)},
              "/home/shijia/Public/testprogram/w_tgammal.c_e.c:32:11");
      AssignLd({(Addr)&temp_var_for_ext_0},
               (Addr) &(temp_var_for_const_1 = temp_var_for_callexp_0),
               "/home/shijia/Public/testprogram/w_tgammal.c_e.c:34:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_0;
    }
    /* tgamma pole */
    else {
      if (int temp_var_for_tac_1; int temp_var_for_const_2;
          long double temp_var_for_callexp_1;

          temp_var_for_callexp_1 = __ieee754_floorl(x);
          temp_var_for_tac_1 = temp_var_for_callexp_1 == x;

          &&int temp_var_for_tac_2; int temp_var_for_const_3;
          temp_var_for_tac_2 = x < 0.0L;

          ) {
        long double temp_var_for_ext_1;
        long double temp_var_for_const_4;
        long double temp_var_for_callexp_2;

        temp_var_for_callexp_2 =
            __kernel_standard_l(x, x, y, KMATHERRL_TGAMMA_MINUS);
        temp_var_for_ext_1 = temp_var_for_callexp_2;
        compute(
            (Addr)&temp_var_for_tac_1,
            {(Addr) &(temp_var_for_const_2 = temp_var_for_callexp_1), (Addr)&x},
            "/home/shijia/Public/testprogram/w_tgammal.c_e.c:42:31");
        compute((Addr)&temp_var_for_tac_2,
                {(Addr)&x, (Addr) &(temp_var_for_const_3 = 0.0L)},
                "/home/shijia/Public/testprogram/w_tgammal.c_e.c:42:41");
        AssignLd({(Addr)&temp_var_for_ext_1},
                 (Addr) &(temp_var_for_const_4 = temp_var_for_callexp_2),
                 "/home/shijia/Public/testprogram/w_tgammal.c_e.c:44:28");
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
          long double temp_var_for_ext_2;
          long double temp_var_for_const_6;
          long double temp_var_for_callexp_3;

          temp_var_for_callexp_3 =
              __kernel_standard_l(x, x, y, KMATHERRL_TGAMMA_UNDERFLOW);
          temp_var_for_ext_2 = temp_var_for_callexp_3;
          compute((Addr)&temp_var_for_tac_3,
                  {(Addr)&y, (Addr) &(temp_var_for_const_5 = 0)},
                  "/home/shijia/Public/testprogram/w_tgammal.c_e.c:53:15");
          AssignLd({(Addr)&temp_var_for_ext_2},
                   (Addr) &(temp_var_for_const_6 = temp_var_for_callexp_3),
                   "/home/shijia/Public/testprogram/w_tgammal.c_e.c:55:30");
          ;
          callExpStack.push(
              getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
          callExp++; /*identify the function is  add move tmpShadow*/
          return temp_var_for_ext_2;
        }
        /* tgamma underflow */
        else {
          long double temp_var_for_ext_3;
          long double temp_var_for_const_7;
          long double temp_var_for_callexp_4;

          temp_var_for_callexp_4 =
              __kernel_standard_l(x, x, y, KMATHERRL_TGAMMA_OVERFLOW);
          temp_var_for_ext_3 = temp_var_for_callexp_4;
          AssignLd({(Addr)&temp_var_for_ext_3},
                   (Addr) &(temp_var_for_const_7 = temp_var_for_callexp_4),
                   "/home/shijia/Public/testprogram/w_tgammal.c_e.c:65:30");
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
  long double temp_var_for_ext_4;
  long double temp_var_for_const_8;
  temp_var_for_ext_4 = local_signgam < 0 ? -y : y;
  AssignLd({(Addr)&temp_var_for_ext_4},
           (Addr) &(temp_var_for_const_8 = local_signgam < 0 ? -y : y),
           "/home/shijia/Public/testprogram/w_tgammal.c_e.c:77:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for(0.0 - e) xt_4;
}

__typeof(__tgammal) tgammal __attribute__((weak, alias("__tgammal")));

#endif
