#include "../ScDebug/scdebug.h"
#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_sqrt

float __ieee754_sqrtf(float x) {
  float z;
  int32_t sign = IC(0x80000000);
  int32_t ix, s, q, m, t, i;
  uint32_t r;

  static const float one = 1.0;
  static const float tiny = 1.0e-30;

  GET_FLOAT_WORD(ix, x);

  /* take care of Inf and NaN */
  if ((ix & IC(0x7f800000)) == IC(0x7f800000)) {
    float temp_var_for_ext_0;
    float temp_var_for_tac_0, temp_var_for_tac_1;
    temp_var_for_tac_0 = x * x;

    temp_var_for_tac_1 = temp_var_for_tac_0 + x;

    temp_var_for_ext_0 = temp_var_for_tac_1;
    computeFMul((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_sqrtf.c_e.c:21:28");
    computeFAdd((Addr)&temp_var_for_tac_1,
                {(Addr)&temp_var_for_tac_0, (Addr)&x},
                "/home/shijia/Public/testprogram/e_sqrtf.c_e.c:21:32");
    AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_1,
            "/home/shijia/Public/testprogram/e_sqrtf.c_e.c:21:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++;                 /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0; /* sqrt(NaN)=NaN, sqrt(+inf)=+inf
                                                          sqrt(-inf)=sNaN */
  }
  /* take care of zero */
  if (ix <= 0) {
    if ((ix & (~sign)) == 0) {
      float temp_var_for_ext_1;
      temp_var_for_ext_1 = x;
      AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&x,
              "/home/shijia/Public/testprogram/e_sqrtf.c_e.c:31:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_1;
    }
    /* sqrt(+-0) = +-0 */
    else {
      if (ix < 0) {
        float temp_var_for_ext_2;
        float temp_var_for_tac_2, temp_var_for_tac_3, temp_var_for_tac_4;
        temp_var_for_tac_2 = x - x;

        temp_var_for_tac_3 = x - x;

        temp_var_for_tac_4 = temp_var_for_tac_2 / temp_var_for_tac_3;

        temp_var_for_ext_2 = temp_var_for_tac_4;
        computeFSub((Addr)&temp_var_for_tac_2, {(Addr)&x, (Addr)&x},
                    "/home/shijia/Public/testprogram/e_sqrtf.c_e.c:41:33");
        computeFSub((Addr)&temp_var_for_tac_3, {(Addr)&x, (Addr)&x},
                    "/home/shijia/Public/testprogram/e_sqrtf.c_e.c:41:43");
        computeFDiv((Addr)&temp_var_for_tac_4,
                    {(Addr)&temp_var_for_tac_2, (Addr)&temp_var_for_tac_3},
                    "/home/shijia/Public/testprogram/e_sqrtf.c_e.c:41:38");
        AssignF({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_4,
                "/home/shijia/Public/testprogram/e_sqrtf.c_e.c:41:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_2;
      }
    }
    /* sqrt(-ve) = sNaN */
  }
  /* normalize x */
  m = (ix >> 23);
  if (m == 0) { /* subnormal x */
    for (i = 0; (ix & IC(0x00800000)) == 0; i++) {
      ix <<= 1;
    }

    m -= i - 1;
  }
  m -= 127; /* unbias exponent */
  ix = (ix & IC(0x007fffff)) | IC(0x00800000);
  if (m & 1) /* odd m, double x to make it even */
  {
    ix += ix;
  }

  m >>= 1; /* m = [m/2] */

  /* generate sqrt(x) bit by bit */
  ix += ix;
  q = s = 0;          /* q = sqrt(x) */
  r = IC(0x01000000); /* r = moving bit from right to left */

  int temp_var_for_ext_3;
  temp_var_for_ext_3 = r != 0;
  while (temp_var_for_ext_3) {
    t = s + r;
    if (t <= ix) {
      s = t + r;
      ix -= t;
      q += r;
    }
    ix += ix;
    r >>= 1;
    temp_var_for_ext_3 = r != 0;
  }

  /* use floating add to find out rounding direction */
  if (ix != 0) {
    float temp_var_for_tac_5;
    float temp_var_for_const_0, temp_var_for_const_1;
    temp_var_for_tac_5 = one - tiny;

    z = temp_var_for_tac_5;
    computeFSub((Addr)&temp_var_for_tac_5,
                {(Addr) &(temp_var_for_const_1 = one),
                 (Addr) &(temp_var_for_const_0 = tiny)},
                "/home/shijia/Public/testprogram/e_sqrtf.c_e.c:89:13");
    AssignF({(Addr)&z}, (Addr)&temp_var_for_tac_5,
            "/home/shijia/Public/testprogram/e_sqrtf.c_e.c:89:7");
    ; /* trigger inexact flag */
    if (int temp_var_for_tac_6; int temp_var_for_const_2;
        temp_var_for_tac_6 = z >= one;

        ) {
      float temp_var_for_tac_7;
      float temp_var_for_const_3, temp_var_for_const_4;
      temp_var_for_tac_7 = one + tiny;

      z = temp_var_for_tac_7;
      compute((Addr)&temp_var_for_tac_6,
              {(Addr)&z, (Addr) &(temp_var_for_const_2 = one)},
              "/home/shijia/Public/testprogram/e_sqrtf.c_e.c:90:11");
      computeFAdd((Addr)&temp_var_for_tac_7,
                  {(Addr) &(temp_var_for_const_4 = one),
                   (Addr) &(temp_var_for_const_3 = tiny)},
                  "/home/shijia/Public/testprogram/e_sqrtf.c_e.c:91:15");
      AssignF({(Addr)&z}, (Addr)&temp_var_for_tac_7,
              "/home/shijia/Public/testprogram/e_sqrtf.c_e.c:91:9");
      ;
      if (int temp_var_for_tac_8; int temp_var_for_const_5;
          temp_var_for_tac_8 = z > one;

          ) {
        q += 2;
      }

      else {
        q += (q & 1);
      }
    }
  }
  ix = (q >> 1) + IC(0x3f000000);
  ix += (m << 23);
  SET_FLOAT_WORD(z, ix);
  float temp_var_for_ext_4;
  temp_var_for_ext_4 = z;
  compute((Addr)&temp_var_for_tac_8,
          {(Addr)&z, (Addr) &(temp_var_for_const_5 = one)},
          "/home/shijia/Public/testprogram/e_sqrtf.c_e.c:92:13");
  AssignF({(Addr)&temp_var_for_ext_4}, (Addr)&z,
          "/home/shijia/Public/testprogram/e_sqrtf.c_e.c:105:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_4;
}
#endif

float __sqrtf(float x) {
  if (isless(x, 0.0) && _LIB_VERSION != _IEEE_) {
    float temp_var_for_ext_5;
    float temp_var_for_const_6;
    float temp_var_for_callexp_0;

    /*embed fun has found*/
    float temp_var_for_callexp_1;

    temp_var_for_callexp_0 = __builtin_nanf("");
    temp_var_for_callexp_1 =
        __kernel_standard_f(x, x, temp_var_for_callexp_0, KMATHERRF_SQRT);
    temp_var_for_ext_5 = temp_var_for_callexp_1;
    AssignF({(Addr)&temp_var_for_ext_5},
            (Addr) &(temp_var_for_const_6 = temp_var_for_callexp_1),
            "/home/shijia/Public/testprogram/e_sqrtf.c_e.c:115:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_5;
  }
  /* sqrt(negative) */
  float temp_var_for_ext_6;
  float temp_var_for_const_7;
  float temp_var_for_callexp_2;

  temp_var_for_callexp_2 = __ieee754_sqrtf(x);
  temp_var_for_ext_6 = temp_var_for_callexp_2;
  AssignF({(Addr)&temp_var_for_ext_6},
          (Addr) &(temp_var_for_const_7 = temp_var_for_callexp_2),
          "/home/shijia/Public/testprogram/e_sqrtf.c_e.c:123:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_6;
}

__typeof(__sqrtf) sqrtf __attribute__((weak, alias("__sqrtf")));
