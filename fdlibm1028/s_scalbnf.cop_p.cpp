#include "../ScDebug/scdebug.h"
#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_scalbn

float __ieee754_scalbnf(float x, int n) {
  int32_t k, ix;

  static const float two25 = 3.355443200e+07;   /* 0x4c000000 */
  static const float twom25 = 2.9802322388e-08; /* 0x33000000 */
  static const float hugeval = 1.0e+30;
  static const float tiny = 1.0e-30;

  GET_FLOAT_WORD(ix, x);
  k = (ix & UC(0x7f800000)) >> IEEE754_FLOAT_SHIFT; /* extract exponent */
  if (k == 0) {                                     /* 0 or subnormal x */
    if ((ix & UC(0x7fffffff)) == 0) {
      float temp_var_for_ext_0;
      temp_var_for_ext_0 = x;
      AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&x,
              "/home/shijia/Public/testprogram/s_scalbnf.c_e.c:20:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_0;
    }
    /* +-0 */
    x *= two25;
    ;
    GET_FLOAT_WORD(ix, x);
    k = ((ix & UC(0x7f800000)) >> IEEE754_FLOAT_SHIFT) - 25;
  }
  if (k == IEEE754_FLOAT_MAXEXP) {
    float temp_var_for_ext_1;
    float temp_var_for_tac_1;
    temp_var_for_tac_1 = x + x;

    temp_var_for_ext_1 = temp_var_for_tac_1;
    computeFAdd((Addr)&temp_var_for_tac_1, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/s_scalbnf.c_e.c:33:28");
    AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_1,
            "/home/shijia/Public/testprogram/s_scalbnf.c_e.c:33:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }
  /* NaN or Inf */
  if ((int32_t)n < IC(-30000)) {
    float temp_var_for_ext_2;
    float temp_var_for_tac_2;
    float temp_var_for_const_0, temp_var_for_const_1;
    float temp_var_for_callexp_0;

    temp_var_for_callexp_0 = copysignf(tiny, x);
    temp_var_for_tac_2 = tiny * temp_var_for_callexp_0;

    temp_var_for_ext_2 = temp_var_for_tac_2;
    computeFMul((Addr)&temp_var_for_tac_2,
                {(Addr) &(temp_var_for_const_1 = tiny),
                 (Addr) &(temp_var_for_const_0 = temp_var_for_callexp_0)},
                "/home/shijia/Public/testprogram/s_scalbnf.c_e.c:41:31");
    AssignF({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_2,
            "/home/shijia/Public/testprogram/s_scalbnf.c_e.c:41:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  }
  /*underflow */
  if ((int32_t)n > IC(30000) || k + n > 0xfe) {
    float temp_var_for_ext_3;
    float temp_var_for_tac_3;
    float temp_var_for_const_2, temp_var_for_const_3;
    float temp_var_for_callexp_1;

    temp_var_for_callexp_1 = copysignf(hugeval, x);
    temp_var_for_tac_3 = hugeval * temp_var_for_callexp_1;

    temp_var_for_ext_3 = temp_var_for_tac_3;
    computeFMul((Addr)&temp_var_for_tac_3,
                {(Addr) &(temp_var_for_const_3 = hugeval),
                 (Addr) &(temp_var_for_const_2 = temp_var_for_callexp_1)},
                "/home/shijia/Public/testprogram/s_scalbnf.c_e.c:49:34");
    AssignF({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_3,
            "/home/shijia/Public/testprogram/s_scalbnf.c_e.c:49:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_3;
  }
  /* overflow  */
  /* Now k and n are bounded we know that k = k+n does not
     overflow.  */
  k = k + n;
  if (k > 0) /* normal result */
  {
    SET_FLOAT_WORD(x, (ix & UC(0x807fffff)) | (k << IEEE754_FLOAT_SHIFT));
    float temp_var_for_ext_4;
    temp_var_for_ext_4 = x;
    AssignF({(Addr)&temp_var_for_ext_4}, (Addr)&x,
            "/home/shijia/Public/testprogram/s_scalbnf.c_e.c:62:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_4;
  }
  if (k <= -25) {
    float temp_var_for_ext_5;
    float temp_var_for_tac_4;
    float temp_var_for_const_4, temp_var_for_const_5;
    float temp_var_for_callexp_2;

    temp_var_for_callexp_2 = copysignf(tiny, x);
    temp_var_for_tac_4 = tiny * temp_var_for_callexp_2;

    temp_var_for_ext_5 = temp_var_for_tac_4;
    computeFMul((Addr)&temp_var_for_tac_4,
                {(Addr) &(temp_var_for_const_5 = tiny),
                 (Addr) &(temp_var_for_const_4 = temp_var_for_callexp_2)},
                "/home/shijia/Public/testprogram/s_scalbnf.c_e.c:69:31");
    AssignF({(Addr)&temp_var_for_ext_5}, (Addr)&temp_var_for_tac_4,
            "/home/shijia/Public/testprogram/s_scalbnf.c_e.c:69:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_5;
  }
  /*underflow */
  k += 25; /* subnormal result */
  SET_FLOAT_WORD(x, (ix & UC(0x807fffff)) | (k << IEEE754_FLOAT_SHIFT));
  float temp_var_for_ext_6;
  float temp_var_for_tac_5;
  float temp_var_for_const_6;
  temp_var_for_tac_5 = x * twom25;

  temp_var_for_ext_6 = temp_var_for_tac_5;
  computeFMul((Addr)&temp_var_for_tac_5,
              {(Addr)&x, (Addr) &(temp_var_for_const_6 = twom25)},
              "/home/shijia/Public/testprogram/s_scalbnf.c_e.c:78:26");
  AssignF({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_5,
          "/home/shijia/Public/testprogram/s_scalbnf.c_e.c:78:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_6;
}

#endif

float __scalbnf(float x, int n) {
  float temp_var_for_ext_7;
  float temp_var_for_const_7;
  float temp_var_for_callexp_3;

  temp_var_for_callexp_3 = __ieee754_scalbnf(x, n);
  temp_var_for_ext_7 = temp_var_for_callexp_3;
  AssignF({(Addr)&temp_var_for_ext_7},
          (Addr) &(temp_var_for_const_7 = temp_var_for_callexp_3),
          "/home/shijia/Public/testprogram/s_scalbnf.c_e.c:88:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_7;
}

__typeof(__scalbnf) scalbnf __attribute__((weak, alias("__scalbnf")));

#if INT_MAX == LONG_MAX
float __scalblnf(float x, long n) __attribute__((alias("__scalbnf")));
float scalblnf(float x, long n) __attribute__((weak, alias("__scalblnf")));
#ifndef __have_fpu_scalbn
float __ieee754_scalblnf(float x, long n)
    __attribute__((alias("__ieee754_scalbnf")));
#endif
#endif
