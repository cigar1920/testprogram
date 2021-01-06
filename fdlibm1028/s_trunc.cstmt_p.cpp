#include "../ScDebug/scdebug.h"
#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_trunc

double __ieee754_trunc(double x) {
  int32_t i0, j0;
  uint32_t i1;
  int32_t sx;

  GET_DOUBLE_WORDS(i0, i1, x);
  sx = i0 & IC(0x80000000);
  j0 = ((i0 >> IEEE754_DOUBLE_SHIFT) & IEEE754_DOUBLE_MAXEXP) -
       IEEE754_DOUBLE_BIAS;
  if (j0 < IEEE754_DOUBLE_SHIFT) {
    if (j0 < 0)
      /* The magnitude of the number is < 1 so the result is +-0.  */
      INSERT_WORDS(x, sx, 0);
    else
      INSERT_WORDS(x, sx | (i0 & ~(UC(0x000fffff) >> j0)), 0);
  } else if (j0 > 51) {
    if (j0 == (IEEE754_DOUBLE_MAXEXP - IEEE754_DOUBLE_BIAS))
      /* x is inf or NaN.  */
      return x + x;
  } else {
    INSERT_WORDS(x, i0, i1 & ~(UC(0xffffffff) >> (j0 - IEEE754_DOUBLE_SHIFT)));
  }

  double temp_var_for_ext_0;
  temp_var_for_ext_0 = x;
  AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&x,
          "/home/shijia/Public/testprogram/s_trunc.c_e.c:31:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

#endif

double __trunc(double x) {
  double temp_var_for_ext_1;
  temp_var_for_ext_1 = __ieee754_trunc(x);
  double temp_var_for_callexp_0 =
      __ieee754_trunc(getFVbyShadow<double>((Addr)&x));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  AssignD({(Addr)&temp_var_for_ext_1}, ,
          "/home/shijia/Public/testprogram/s_trunc.c_e.c:41:22");
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

__typeof(__trunc) trunc __attribute__((weak, alias("__trunc")));
#ifdef __NO_LONG_DOUBLE_MATH
long double __truncl(long double x) __attribute__((alias("__trunc")));
__typeof(__truncl) truncl __attribute__((weak, alias("__trunc")));
#endif
