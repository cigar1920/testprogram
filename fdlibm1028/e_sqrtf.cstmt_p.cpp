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
    return x * x + x; /* sqrt(NaN)=NaN, sqrt(+inf)=+inf
                                         sqrt(-inf)=sNaN */
  }
  /* take care of zero */
  if (ix <= 0) {
    if ((ix & (~sign)) == 0)
      return x; /* sqrt(+-0) = +-0 */
    else if (ix < 0)
      return (x - x) / (x - x); /* sqrt(-ve) = sNaN */
  }
  /* normalize x */
  m = (ix >> 23);
  if (m == 0) { /* subnormal x */
    for (i = 0; (ix & IC(0x00800000)) == 0; i++)
      ix <<= 1;
    m -= i - 1;
  }
  m -= 127; /* unbias exponent */
  ix = (ix & IC(0x007fffff)) | IC(0x00800000);
  if (m & 1) /* odd m, double x to make it even */
    ix += ix;
  m >>= 1; /* m = [m/2] */

  /* generate sqrt(x) bit by bit */
  ix += ix;
  q = s = 0;          /* q = sqrt(x) */
  r = IC(0x01000000); /* r = moving bit from right to left */

  while (r != 0) {
    t = s + r;
    if (t <= ix) {
      s = t + r;
      ix -= t;
      q += r;
    }
    ix += ix;
    r >>= 1;
  }

  /* use floating add to find out rounding direction */
  if (ix != 0) {
    z = one - tiny; /* trigger inexact flag */
    if (z >= one) {
      z = one + tiny;
      if (z > one)
        q += 2;
      else
        q += (q & 1);
    }
  }
  ix = (q >> 1) + IC(0x3f000000);
  ix += (m << 23);
  SET_FLOAT_WORD(z, ix);
  float temp_var_for_ext_0;
  temp_var_for_ext_0 = z;
  AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&z,
          "/home/shijia/Public/testprogram/e_sqrtf.c_e.c:74:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}
#endif

float __sqrtf(float x) {
  if (isless(x, 0.0) && _LIB_VERSION != _IEEE_)
    return __kernel_standard_f(x, x, __builtin_nanf(""),
                               KMATHERRF_SQRT); /* sqrt(negative) */
  float temp_var_for_ext_1;
  temp_var_for_ext_1 = __ieee754_sqrtf(x);
  float temp_var_for_callexp_0 =
      __ieee754_sqrtf(getFVbyShadow<float>((Addr)&x));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  AssignF({(Addr)&temp_var_for_ext_1}, ,
          "/home/shijia/Public/testprogram/e_sqrtf.c_e.c:86:22");
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

__typeof(__sqrtf) sqrtf __attribute__((weak, alias("__sqrtf")));
