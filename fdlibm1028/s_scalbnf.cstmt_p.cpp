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
    if ((ix & UC(0x7fffffff)) == 0)
      return x; /* +-0 */
    x *= two25;
    GET_FLOAT_WORD(ix, x);
    k = ((ix & UC(0x7f800000)) >> IEEE754_FLOAT_SHIFT) - 25;
  }
  if (k == IEEE754_FLOAT_MAXEXP)
    return x + x; /* NaN or Inf */
  if ((int32_t)n < IC(-30000))
    return tiny * copysignf(tiny, x); /*underflow */
  if ((int32_t)n > IC(30000) || k + n > 0xfe)
    return hugeval * copysignf(hugeval, x); /* overflow  */
  /* Now k and n are bounded we know that k = k+n does not
     overflow.  */
  k = k + n;
  if (k > 0) /* normal result */
  {
    SET_FLOAT_WORD(x, (ix & UC(0x807fffff)) | (k << IEEE754_FLOAT_SHIFT));
    return x;
  }
  if (k <= -25)
    return tiny * copysignf(tiny, x); /*underflow */
  k += 25;                            /* subnormal result */
  SET_FLOAT_WORD(x, (ix & UC(0x807fffff)) | (k << IEEE754_FLOAT_SHIFT));
  float temp_var_for_ext_0;
  temp_var_for_ext_0 = x * twom25;
  float temp_var_for_const_0;
  computeFMul((Addr)&temp_var_for_ext_0,
              {(Addr)&x, (Addr) &(temp_var_for_const_0 = twom25)},
              "/home/shijia/Public/testprogram/s_scalbnf.c_e.c:43:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

#endif

float __scalbnf(float x, int n) {
  float temp_var_for_ext_1;
  temp_var_for_ext_1 = __ieee754_scalbnf(x, n);
  float temp_var_for_callexp_0 =
      __ieee754_scalbnf(getFVbyShadow<float>((Addr)&x), (n));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_callexp_0,
          "/home/shijia/Public/testprogram/s_scalbnf.c_e.c:53:22");
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
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
