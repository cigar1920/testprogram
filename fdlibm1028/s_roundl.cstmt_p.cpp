#include "../ScDebug/scdebug.h"
#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

#ifndef __have_fpu_round

long double __ieee754_roundl(long double x) {
  int32_t j0;
  uint32_t se, i1, i0;

  static const long double hugeval = 1.0e4930L;

  GET_LDOUBLE_WORDS(se, i0, i1, x);
  j0 = (se & IEEE854_LONG_DOUBLE_MAXEXP) - IEEE854_LONG_DOUBLE_BIAS;
  if (j0 < 31) {
    if (j0 < 0) {
      math_force_eval(hugeval + x);
      se &= 0x8000;
      i0 = i1 = 0;
      if (j0 == -1) {
        se |= 0x3fff;
        i0 = UC(0x80000000);
      }
    } else {
      uint32_t i = UC(0x7fffffff) >> j0;
      uint32_t j;

      if (((i0 & i) | i1) == 0)
        /* X is integral.  */
        return x;

      /* Raise inexact if x != 0.  */
      math_force_eval(hugeval + x);
      j = i0 + (UC(0x40000000) >> j0);

      if (j < i0)
        se += 1;
      i0 = (j & ~i) | IC(0x80000000);
      i1 = 0;
    }
  } else if (j0 > 62) {
    if (j0 == (IEEE854_LONG_DOUBLE_MAXEXP - IEEE854_LONG_DOUBLE_BIAS))
      /* Inf or NaN.  */
      return x + x;
    else
      return x;
  } else {
    uint32_t i = UC(0xffffffff) >> (j0 - 31);
    uint32_t j;

    if ((i1 & i) == 0)
      /* X is integral.  */
      return x;

    /* Raise inexact if x != 0.  */
    math_force_eval(hugeval + x);
    j = i1 + (UC(1) << (62 - j0));

    if (j < i1) {
      uint32_t k = i0 + 1;

      if (k < i0) {
        se += 1;
        k |= UC(0x80000000);
      }
      i0 = k;
    }
    i1 = j;
    i1 &= ~i;
  }

  SET_LDOUBLE_WORDS(x, se, i0, i1);
  long double temp_var_for_ext_0;
  temp_var_for_ext_0 = x;
  AssignLd({(Addr)&temp_var_for_ext_0}, (Addr)&x,
           "/home/shijia/Public/testprogram/s_roundl.c_e.c:76:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

#endif

long double __roundl(long double x) {
  long double temp_var_for_ext_1;
  temp_var_for_ext_1 = __ieee754_roundl(x);
  long double temp_var_for_callexp_0 =
      __ieee754_roundl(getFVbyShadow<long double>((Addr)&x));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  AssignLd({(Addr)&temp_var_for_ext_1}, ,
           "/home/shijia/Public/testprogram/s_roundl.c_e.c:86:22");
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

__typeof(__roundl) roundl __attribute__((weak, alias("__roundl")));

#endif
