#include "../ScDebug/scdebug.h"
#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

#ifndef __have_fpu_trunc

long double __ieee754_truncl(long double x) {
  int32_t i0, j0;
  uint32_t se, i1;
  int32_t sx;

  GET_LDOUBLE_WORDS(se, i0, i1, x);
  sx = se & 0x8000;
  j0 = (se & IEEE854_LONG_DOUBLE_MAXEXP) - IEEE854_LONG_DOUBLE_BIAS;
  if (j0 < 31) {
    if (j0 < 0)
      /* The magnitude of the number is < 1 so the result is +-0.  */
      SET_LDOUBLE_WORDS(x, sx, 0, 0);
    else
      SET_LDOUBLE_WORDS(x, se, i0 & ~(UC(0x7fffffff) >> j0), 0);
  } else if (j0 > 63) {
    if (j0 == (IEEE854_LONG_DOUBLE_MAXEXP - IEEE854_LONG_DOUBLE_BIAS))
      /* x is inf or NaN.  */
      return x + x;
  } else {
    /* avoid undefined behaviour for shift-count == 32 */
    if (j0 != 63)
      SET_LDOUBLE_WORDS(x, se, i0, i1 & ~(UC(0xffffffff) >> (j0 - 31)));
  }

  long double temp_var_for_ext_0;
  temp_var_for_ext_0 = x;
  AssignLd({(Addr)&temp_var_for_ext_0}, (Addr)&x,
           "/home/shijia/Public/testprogram/s_truncl.c_e.c:34:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

#endif

long double __truncl(long double x) {
  long double temp_var_for_ext_1;
  temp_var_for_ext_1 = __ieee754_truncl(x);
  long double temp_var_for_callexp_0 =
      __ieee754_truncl(getFVbyShadow<long double>((Addr)&x));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  AssignLd({(Addr)&temp_var_for_ext_1}, ,
           "/home/shijia/Public/testprogram/s_truncl.c_e.c:44:22");
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

__typeof(__truncl) truncl __attribute__((weak, alias("__truncl")));

#endif
