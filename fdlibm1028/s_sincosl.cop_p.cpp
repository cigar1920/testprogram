#include "../ScDebug/scdebug.h"
#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

#ifndef __have_fpu_sincos

void __ieee754_sincosl(long double x, long double *sinx, long double *cosx) {
  long double temp_var_for_const_0, temp_var_for_const_1;
  long double temp_var_for_callexp_0;

  temp_var_for_callexp_0 = __ieee754_sinl(x);
  (*(sinx)) = temp_var_for_callexp_0;
  AssignLd({(Addr) &(temp_var_for_const_1 = (*(sinx)))},
           (Addr) &(temp_var_for_const_0 = temp_var_for_callexp_0),
           "/home/shijia/Public/testprogram/s_sincosl.c_e.c:10:9");
  ;
  long double temp_var_for_const_2, temp_var_for_const_3;
  long double temp_var_for_callexp_1;

  temp_var_for_callexp_1 = __ieee754_cosl(x);
  (*(cosx)) = temp_var_for_callexp_1;
  AssignLd({(Addr) &(temp_var_for_const_3 = (*(cosx)))},
           (Addr) &(temp_var_for_const_2 = temp_var_for_callexp_1),
           "/home/shijia/Public/testprogram/s_sincosl.c_e.c:11:9");
  ;
}

#endif

void __sincosl(long double x, long double *sinx, long double *cosx) {
  int32_t se;
  uint32_t i0, i1;

  /* High word of x. */
  long double temp_var_for_const_4;
  ew_u.value = x;
  AssignLd({(Addr) &(temp_var_for_const_4 = ew_u.value)}, (Addr)&x,
           "/home/shijia/Public/testprogram/s_sincosl.c_e.c:21:3 "
           "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
  ;
  (void)i1;

  /* |x| ~< pi/4 */
  se &= 0x7fff;
  if (se < 0x3ffe || (se == 0x3ffe && i0 <= UC(0xc90fdaa2))) {
#ifdef __have_fpu_sincos
    __ieee754_sincosl(x, sinx, cosx);
#else
    long double temp_var_for_const_5, temp_var_for_const_6;
    long double temp_var_for_callexp_2;

    temp_var_for_callexp_2 = __kernel_sinl(x, 0.0, 0);
    (*(sinx)) = temp_var_for_callexp_2;
    AssignLd({(Addr) &(temp_var_for_const_6 = (*(sinx)))},
             (Addr) &(temp_var_for_const_5 = temp_var_for_callexp_2),
             "/home/shijia/Public/testprogram/s_sincosl.c_e.c:30:11");
    ;
    long double temp_var_for_const_7, temp_var_for_const_8;
    long double temp_var_for_callexp_3;

    temp_var_for_callexp_3 = __kernel_cosl(x, 0.0);
    (*(cosx)) = temp_var_for_callexp_3;
    AssignLd({(Addr) &(temp_var_for_const_8 = (*(cosx)))},
             (Addr) &(temp_var_for_const_7 = temp_var_for_callexp_3),
             "/home/shijia/Public/testprogram/s_sincosl.c_e.c:31:11");
    ;
#endif
  } else {
    if (se == 0x7fff) {
      /* sin(Inf or NaN) is NaN */
      long double temp_var_for_tac_0;
      long double temp_var_for_const_9, temp_var_for_const_10;
      temp_var_for_tac_0 = x - x;

      (*(cosx)) = temp_var_for_tac_0;
      computeLdSub((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&x},
                   "/home/shijia/Public/testprogram/s_sincosl.c_e.c:36:25");
      AssignLd({(Addr) &(temp_var_for_const_9 = (*(cosx)))},
               (Addr)&temp_var_for_tac_0,
               "/home/shijia/Public/testprogram/s_sincosl.c_e.c:36:21");
      (*(sinx)) = (*(cosx));
      AssignLd({(Addr) &(temp_var_for_const_10 = (*(sinx)))},
               (Addr) & (*(cosx)),
               "/home/shijia/Public/testprogram/s_sincosl.c_e.c:36:13");
      ;
    } else {
#ifdef __have_fpu_sincos
      __ieee754_sincosl(x, sinx, cosx);
#else
      /* Argument reduction needed.  */
      long double y[2];
      int32_t n;

      n = __ieee754_rem_pio2l(x, y);
      int temp_var_for_ext_0;
      temp_var_for_ext_0 = (int)(n & 3);
      switch (temp_var_for_ext_0) {
      case 0: {
        long double temp_var_for_const_11, temp_var_for_const_12;
        long double temp_var_for_callexp_4;

        temp_var_for_callexp_4 = __kernel_sinl(y[0], y[1], 1);
        (*(sinx)) = temp_var_for_callexp_4;
        AssignLd({(Addr) &(temp_var_for_const_12 = (*(sinx)))},
                 (Addr) &(temp_var_for_const_11 = temp_var_for_callexp_4),
                 "/home/shijia/Public/testprogram/s_sincosl.c_e.c:50:15");
        ;
      }

        long double temp_var_for_const_13, temp_var_for_const_14;
        long double temp_var_for_callexp_5;

        temp_var_for_callexp_5 = __kernel_cosl(y[0], y[1]);
        (*(cosx)) = temp_var_for_callexp_5;
        AssignLd({(Addr) &(temp_var_for_const_14 = (*(cosx)))},
                 (Addr) &(temp_var_for_const_13 = temp_var_for_callexp_5),
                 "/home/shijia/Public/testprogram/s_sincosl.c_e.c:53:15");
        ;
        break;
      case 1: {
        long double temp_var_for_const_15, temp_var_for_const_16;
        long double temp_var_for_callexp_6;

        temp_var_for_callexp_6 = __kernel_cosl(y[0], y[1]);
        (*(sinx)) = temp_var_for_callexp_6;
        AssignLd({(Addr) &(temp_var_for_const_16 = (*(sinx)))},
                 (Addr) &(temp_var_for_const_15 = temp_var_for_callexp_6),
                 "/home/shijia/Public/testprogram/s_sincosl.c_e.c:56:15");
        ;
      }

        long double temp_var_for_tac_1;
        long double temp_var_for_const_17, temp_var_for_const_18,
            temp_var_for_const_19;
        long double temp_var_for_callexp_7;

        temp_var_for_callexp_7 = __kernel_sinl(y[0], y[1], 1);
        temp_var_for_tac_1 = 0.0 - temp_var_for_callexp_7;

        (*(cosx)) = temp_var_for_tac_1;
        computeLdSub((Addr)&temp_var_for_tac_1,
                     {(Addr) &(temp_var_for_const_18 = 0.0),
                      (Addr) &(temp_var_for_const_17 = temp_var_for_callexp_7)},
                     "/home/shijia/Public/testprogram/s_sincosl.c_e.c:59:22");
        AssignLd({(Addr) &(temp_var_for_const_19 = (*(cosx)))},
                 (Addr)&temp_var_for_tac_1,
                 "/home/shijia/Public/testprogram/s_sincosl.c_e.c:59:15");
        ;
        break;
      case 2: {
        long double temp_var_for_tac_2;
        long double temp_var_for_const_20, temp_var_for_const_21,
            temp_var_for_const_22;
        long double temp_var_for_callexp_8;

        temp_var_for_callexp_8 = __kernel_sinl(y[0], y[1], 1);
        temp_var_for_tac_2 = 0.0 - temp_var_for_callexp_8;

        (*(sinx)) = temp_var_for_tac_2;
        computeLdSub((Addr)&temp_var_for_tac_2,
                     {(Addr) &(temp_var_for_const_21 = 0.0),
                      (Addr) &(temp_var_for_const_20 = temp_var_for_callexp_8)},
                     "/home/shijia/Public/testprogram/s_sincosl.c_e.c:62:22");
        AssignLd({(Addr) &(temp_var_for_const_22 = (*(sinx)))},
                 (Addr)&temp_var_for_tac_2,
                 "/home/shijia/Public/testprogram/s_sincosl.c_e.c:62:15");
        ;
      }

        long double temp_var_for_tac_3;
        long double temp_var_for_const_23, temp_var_for_const_24,
            temp_var_for_const_25;
        long double temp_var_for_callexp_9;

        temp_var_for_callexp_9 = __kernel_cosl(y[0], y[1]);
        temp_var_for_tac_3 = 0.0 - temp_var_for_callexp_9;

        (*(cosx)) = temp_var_for_tac_3;
        computeLdSub((Addr)&temp_var_for_tac_3,
                     {(Addr) &(temp_var_for_const_24 = 0.0),
                      (Addr) &(temp_var_for_const_23 = temp_var_for_callexp_9)},
                     "/home/shijia/Public/testprogram/s_sincosl.c_e.c:65:22");
        AssignLd({(Addr) &(temp_var_for_const_25 = (*(cosx)))},
                 (Addr)&temp_var_for_tac_3,
                 "/home/shijia/Public/testprogram/s_sincosl.c_e.c:65:15");
        ;
        break;
      default: {
        long double temp_var_for_tac_4;
        long double temp_var_for_const_26, temp_var_for_const_27,
            temp_var_for_const_28;
        long double temp_var_for_callexp_10;

        temp_var_for_callexp_10 = __kernel_cosl(y[0], y[1]);
        temp_var_for_tac_4 = 0.0 - temp_var_for_callexp_10;

        (*(sinx)) = temp_var_for_tac_4;
        computeLdSub(
            (Addr)&temp_var_for_tac_4,
            {(Addr) &(temp_var_for_const_27 = 0.0),
             (Addr) &(temp_var_for_const_26 = temp_var_for_callexp_10)},
            "/home/shijia/Public/testprogram/s_sincosl.c_e.c:67:31");
        AssignLd({(Addr) &(temp_var_for_const_28 = (*(sinx)))},
                 (Addr)&temp_var_for_tac_4,
                 "/home/shijia/Public/testprogram/s_sincosl.c_e.c:67:24");
        ;
      }

        long double temp_var_for_const_29, temp_var_for_const_30;
        long double temp_var_for_callexp_11;

        temp_var_for_callexp_11 = __kernel_sinl(y[0], y[1], 1);
        (*(cosx)) = temp_var_for_callexp_11;
        AssignLd({(Addr) &(temp_var_for_const_30 = (*(cosx)))},
                 (Addr) &(temp_var_for_const_29 = temp_var_for_callexp_11),
                 "/home/shijia/Public/testprogram/s_sincosl.c_e.c:69:15");
        ;
        break;
      }
#endif
    }
  }
}

__typeof(__sincosl) sincosl __attribute__((weak, alias("__sincosl")));

#endif
