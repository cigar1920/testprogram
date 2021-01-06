#include "../ScDebug/scdebug.h"
#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_trunc

float __ieee754_truncf(float x) {
  int32_t i0, j0;
  int32_t sx;

  GET_FLOAT_WORD(i0, x);
  sx = i0 & UC(0x80000000);
  j0 =
      ((i0 >> IEEE754_FLOAT_SHIFT) & IEEE754_FLOAT_MAXEXP) - IEEE754_FLOAT_BIAS;
  if (j0 < IEEE754_FLOAT_SHIFT) {
    if (j0 < 0) {
      /* The magnitude of the number is < 1 so the result is +-0.  */
      SET_FLOAT_WORD(x, sx);
    } else {
      SET_FLOAT_WORD(x, sx | (i0 & ~(UC(0x007fffff) >> j0)));
    }
  } else {
    if (j0 == (IEEE754_FLOAT_MAXEXP - IEEE754_FLOAT_BIAS))
      /* x is inf or NaN.  */
      return x + x;
  }

  float temp_var_for_ext_0;
  temp_var_for_ext_0 = x;
  AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&x,
          "/home/shijia/Public/testprogram/s_truncf.c_e.c:29:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

#endif

float __truncf(float x) {
  float temp_var_for_ext_1;
  temp_var_for_ext_1 = __ieee754_truncf(x);
  float temp_var_for_callexp_0 =
      __ieee754_truncf(getFVbyShadow<float>((Addr)&x));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  AssignF({(Addr)&temp_var_for_ext_1}, ,
          "/home/shijia/Public/testprogram/s_truncf.c_e.c:39:22");
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

__typeof(__truncf) truncf __attribute__((weak, alias("__truncf")));
