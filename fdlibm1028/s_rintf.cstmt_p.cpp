#include "../ScDebug/scdebug.h"
#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_rint

static float __ieee754_roundevenf(float x) {
  int32_t i0, j0;

  static const float hugeval = 1.0e30;

  GET_FLOAT_WORD(i0, x);
  j0 =
      ((i0 >> IEEE754_FLOAT_SHIFT) & IEEE754_FLOAT_MAXEXP) - IEEE754_FLOAT_BIAS;
  if (j0 < IEEE754_FLOAT_SHIFT) {
    if (j0 < 0) {
      math_force_eval(hugeval + x);

      if (j0 == -1 && (i0 & IC(0x007fffff)) != 0) {
        i0 &= IC(0x80000000);
        i0 |= IC(0x3f800000);
      } else {
        i0 &= IC(0x80000000);
      }
    } else {
      uint32_t i = UC(0x007fffff) >> j0;

      if ((i0 & i) == 0)
        /* X is integral.  */
        return x;

      /* Raise inexact if x != 0.  */
      math_force_eval(hugeval + x);

      if ((i0 & (i >> 1)) != 0 || (i0 & (UC(0x00800000) >> j0))) {
        i0 += UC(0x00400000) >> j0;
      }
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
          "/home/shijia/Public/testprogram/s_rintf.c_e.c:50:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

float __ieee754_rintf(float x) {
  /*
   * above code relies on a FPU doing the rounding,
   * and using round-to-even for FE_TONEAREST
   */
  int temp_var_for_ext_1;
  temp_var_for_ext_1 = fegetround();
  switch (temp_var_for_ext_1) {
  case FE_UPWARD:
    return __ieee754_ceilf(x);
  case FE_DOWNWARD:
    return __ieee754_floorf(x);
  case FE_TOWARDZERO:
    return __ieee754_truncf(x);
  }
  /* case FE_TONEAREST: */
  float temp_var_for_ext_2;
  temp_var_for_ext_2 = __ieee754_roundevenf(x);
  float temp_var_for_callexp_0 =
      __ieee754_roundevenf(getFVbyShadow<float>((Addr)&x));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  AssignF({(Addr)&temp_var_for_ext_2}, ,
          "/home/shijia/Public/testprogram/s_rintf.c_e.c:73:22");
  callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_2;
}

#endif

float __rintf(float x) {
  float temp_var_for_ext_3;
  temp_var_for_ext_3 = __ieee754_rintf(x);
  float temp_var_for_callexp_1 =
      __ieee754_rintf(getFVbyShadow<float>((Addr)&x));
  CallStackPop((Addr)&temp_var_for_callexp_1, getTop(temp_var_for_callexp_1));
  AssignF({(Addr)&temp_var_for_ext_3}, ,
          "/home/shijia/Public/testprogram/s_rintf.c_e.c:83:22");
  callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_3;
}

__typeof(__rintf) rintf __attribute__((weak, alias("__rintf")));
