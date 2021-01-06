#include "../ScDebug/scdebug.h"
#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_round

float __ieee754_roundf(float x) {
  int32_t i0, j0;

  static const float hugeval = 1.0e30;

  GET_FLOAT_WORD(i0, x);
  j0 =
      ((i0 >> IEEE754_FLOAT_SHIFT) & IEEE754_FLOAT_MAXEXP) - IEEE754_FLOAT_BIAS;
  if (j0 < IEEE754_FLOAT_SHIFT) {
    if (j0 < 0) {
      math_force_eval(hugeval + x);

      i0 &= IC(0x80000000);
      if (j0 == -1)
        i0 |= IC(0x3f800000);
    } else {
      uint32_t i = UC(0x007fffff) >> j0;

      if ((i0 & i) == 0)
        /* X is integral.  */
        return x;
      math_force_eval(hugeval + x);

      /* Raise inexact if x != 0.  */
      i0 += UC(0x00400000) >> j0;
      i0 &= ~i;
    }
  } else {
    if (j0 == (IEEE754_FLOAT_MAXEXP - IEEE754_FLOAT_BIAS))
      /* Inf or NaN.  */
      return x + x;
    else
      return x;
  }

  SET_FLOAT_WORD(x, i0);
  float temp_var_for_ext_0;
  temp_var_for_ext_0 = x;
  AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&x,
          "/home/shijia/Public/testprogram/s_roundf.c_e.c:44:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

#endif

float __roundf(float x) {
  float temp_var_for_ext_1;
  temp_var_for_ext_1 = __ieee754_roundf(x);
  float temp_var_for_callexp_0 =
      __ieee754_roundf(getFVbyShadow<float>((Addr)&x));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  AssignF({(Addr)&temp_var_for_ext_1}, ,
          "/home/shijia/Public/testprogram/s_roundf.c_e.c:54:22");
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

__typeof(__roundf) roundf __attribute__((weak, alias("__roundf")));
