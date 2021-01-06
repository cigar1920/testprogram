#include "../ScDebug/scdebug.h"
#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_sincos

void __ieee754_sincosf(float x, float *sinx, float *cosx) {
  float temp_var_for_const_0, temp_var_for_const_1;
  float temp_var_for_callexp_0;

  temp_var_for_callexp_0 = sinf(x);
  (*(sinx)) = temp_var_for_callexp_0;
  AssignF({(Addr) &(temp_var_for_const_1 = (*(sinx)))},
          (Addr) &(temp_var_for_const_0 = temp_var_for_callexp_0),
          "/home/shijia/Public/testprogram/s_sincosf.c_e.c:8:9");
  ;
  float temp_var_for_const_2, temp_var_for_const_3;
  float temp_var_for_callexp_1;

  temp_var_for_callexp_1 = cosf(x);
  (*(cosx)) = temp_var_for_callexp_1;
  AssignF({(Addr) &(temp_var_for_const_3 = (*(cosx)))},
          (Addr) &(temp_var_for_const_2 = temp_var_for_callexp_1),
          "/home/shijia/Public/testprogram/s_sincosf.c_e.c:9:9");
  ;
}

#endif

void __sincosf(float x, float *sinx, float *cosx) {
  int32_t ix;

  /* High word of x. */
  GET_FLOAT_WORD(ix, x);

  /* |x| ~< pi/4 */
  ix &= IC(0x7fffffff);
  if (ix <= IC(0x3f490fd8)) {
#ifdef __have_fpu_sincos
    __ieee754_sincosf(x, sinx, cosx);
#else
    float temp_var_for_const_4, temp_var_for_const_5;
    float temp_var_for_callexp_2;

    temp_var_for_callexp_2 = __kernel_sinf(x, 0.0, 0);
    (*(sinx)) = temp_var_for_callexp_2;
    AssignF({(Addr) &(temp_var_for_const_5 = (*(sinx)))},
            (Addr) &(temp_var_for_const_4 = temp_var_for_callexp_2),
            "/home/shijia/Public/testprogram/s_sincosf.c_e.c:26:11");
    ;
    float temp_var_for_const_6, temp_var_for_const_7;
    float temp_var_for_callexp_3;

    temp_var_for_callexp_3 = __kernel_cosf(x, 0.0);
    (*(cosx)) = temp_var_for_callexp_3;
    AssignF({(Addr) &(temp_var_for_const_7 = (*(cosx)))},
            (Addr) &(temp_var_for_const_6 = temp_var_for_callexp_3),
            "/home/shijia/Public/testprogram/s_sincosf.c_e.c:27:11");
    ;
#endif
  } else {
    if (ix >= IC(0x7f800000)) {
      /* sin(Inf or NaN) is NaN */
      float temp_var_for_tac_0;
      float temp_var_for_const_8, temp_var_for_const_9;
      temp_var_for_tac_0 = x - x;

      (*(cosx)) = temp_var_for_tac_0;
      computeFSub((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&x},
                  "/home/shijia/Public/testprogram/s_sincosf.c_e.c:32:25");
      AssignF({(Addr) &(temp_var_for_const_8 = (*(cosx)))},
              (Addr)&temp_var_for_tac_0,
              "/home/shijia/Public/testprogram/s_sincosf.c_e.c:32:21");
      (*(sinx)) = (*(cosx));
      AssignF({(Addr) &(temp_var_for_const_9 = (*(sinx)))}, (Addr) & (*(cosx)),
              "/home/shijia/Public/testprogram/s_sincosf.c_e.c:32:13");
      ;
    } else {
#ifdef __have_fpu_sincos
      __ieee754_sincosf(x, sinx, cosx);
#else
      /* Argument reduction needed.  */
      float y[2];
      int32_t n;

      n = __ieee754_rem_pio2f(x, y);
      int temp_var_for_ext_0;
      temp_var_for_ext_0 = (int)(n & 3);
      switch (temp_var_for_ext_0) {
      case 0: {
        float temp_var_for_const_10, temp_var_for_const_11;
        float temp_var_for_callexp_4;

        temp_var_for_callexp_4 = __kernel_sinf(y[0], y[1], 1);
        (*(sinx)) = temp_var_for_callexp_4;
        AssignF({(Addr) &(temp_var_for_const_11 = (*(sinx)))},
                (Addr) &(temp_var_for_const_10 = temp_var_for_callexp_4),
                "/home/shijia/Public/testprogram/s_sincosf.c_e.c:46:15");
        ;
      }

        float temp_var_for_const_12, temp_var_for_const_13;
        float temp_var_for_callexp_5;

        temp_var_for_callexp_5 = __kernel_cosf(y[0], y[1]);
        (*(cosx)) = temp_var_for_callexp_5;
        AssignF({(Addr) &(temp_var_for_const_13 = (*(cosx)))},
                (Addr) &(temp_var_for_const_12 = temp_var_for_callexp_5),
                "/home/shijia/Public/testprogram/s_sincosf.c_e.c:49:15");
        ;
        break;
      case 1: {
        float temp_var_for_const_14, temp_var_for_const_15;
        float temp_var_for_callexp_6;

        temp_var_for_callexp_6 = __kernel_cosf(y[0], y[1]);
        (*(sinx)) = temp_var_for_callexp_6;
        AssignF({(Addr) &(temp_var_for_const_15 = (*(sinx)))},
                (Addr) &(temp_var_for_const_14 = temp_var_for_callexp_6),
                "/home/shijia/Public/testprogram/s_sincosf.c_e.c:52:15");
        ;
      }

        float temp_var_for_tac_1;
        float temp_var_for_const_16, temp_var_for_const_17,
            temp_var_for_const_18;
        float temp_var_for_callexp_7;

        temp_var_for_callexp_7 = __kernel_sinf(y[0], y[1], 1);
        temp_var_for_tac_1 = 0.0 - temp_var_for_callexp_7;

        (*(cosx)) = temp_var_for_tac_1;
        computeDSub((Addr)&temp_var_for_tac_1,
                    {(Addr) &(temp_var_for_const_17 = 0.0),
                     (Addr) &(temp_var_for_const_16 = temp_var_for_callexp_7)},
                    "/home/shijia/Public/testprogram/s_sincosf.c_e.c:55:22");
        AssignF({(Addr) &(temp_var_for_const_18 = (*(cosx)))},
                (Addr)&temp_var_for_tac_1,
                "/home/shijia/Public/testprogram/s_sincosf.c_e.c:55:15");
        ;
        break;
      case 2: {
        float temp_var_for_tac_2;
        float temp_var_for_const_19, temp_var_for_const_20,
            temp_var_for_const_21;
        float temp_var_for_callexp_8;

        temp_var_for_callexp_8 = __kernel_sinf(y[0], y[1], 1);
        temp_var_for_tac_2 = 0.0 - temp_var_for_callexp_8;

        (*(sinx)) = temp_var_for_tac_2;
        computeDSub((Addr)&temp_var_for_tac_2,
                    {(Addr) &(temp_var_for_const_20 = 0.0),
                     (Addr) &(temp_var_for_const_19 = temp_var_for_callexp_8)},
                    "/home/shijia/Public/testprogram/s_sincosf.c_e.c:58:22");
        AssignF({(Addr) &(temp_var_for_const_21 = (*(sinx)))},
                (Addr)&temp_var_for_tac_2,
                "/home/shijia/Public/testprogram/s_sincosf.c_e.c:58:15");
        ;
      }

        float temp_var_for_tac_3;
        float temp_var_for_const_22, temp_var_for_const_23,
            temp_var_for_const_24;
        float temp_var_for_callexp_9;

        temp_var_for_callexp_9 = __kernel_cosf(y[0], y[1]);
        temp_var_for_tac_3 = 0.0 - temp_var_for_callexp_9;

        (*(cosx)) = temp_var_for_tac_3;
        computeDSub((Addr)&temp_var_for_tac_3,
                    {(Addr) &(temp_var_for_const_23 = 0.0),
                     (Addr) &(temp_var_for_const_22 = temp_var_for_callexp_9)},
                    "/home/shijia/Public/testprogram/s_sincosf.c_e.c:61:22");
        AssignF({(Addr) &(temp_var_for_const_24 = (*(cosx)))},
                (Addr)&temp_var_for_tac_3,
                "/home/shijia/Public/testprogram/s_sincosf.c_e.c:61:15");
        ;
        break;
      default: {
        float temp_var_for_tac_4;
        float temp_var_for_const_25, temp_var_for_const_26,
            temp_var_for_const_27;
        float temp_var_for_callexp_10;

        temp_var_for_callexp_10 = __kernel_cosf(y[0], y[1]);
        temp_var_for_tac_4 = 0.0 - temp_var_for_callexp_10;

        (*(sinx)) = temp_var_for_tac_4;
        computeDSub((Addr)&temp_var_for_tac_4,
                    {(Addr) &(temp_var_for_const_26 = 0.0),
                     (Addr) &(temp_var_for_const_25 = temp_var_for_callexp_10)},
                    "/home/shijia/Public/testprogram/s_sincosf.c_e.c:63:31");
        AssignF({(Addr) &(temp_var_for_const_27 = (*(sinx)))},
                (Addr)&temp_var_for_tac_4,
                "/home/shijia/Public/testprogram/s_sincosf.c_e.c:63:24");
        ;
      }

        float temp_var_for_const_28, temp_var_for_const_29;
        float temp_var_for_callexp_11;

        temp_var_for_callexp_11 = __kernel_sinf(y[0], y[1], 1);
        (*(cosx)) = temp_var_for_callexp_11;
        AssignF({(Addr) &(temp_var_for_const_29 = (*(cosx)))},
                (Addr) &(temp_var_for_const_28 = temp_var_for_callexp_11),
                "/home/shijia/Public/testprogram/s_sincosf.c_e.c:65:15");
        ;
        break;
      }
#endif
    }
  }
}

__typeof(__sincosf) sincosf __attribute__((weak, alias("__sincosf")));
