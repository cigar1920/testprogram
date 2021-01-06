#include "../ScDebug/scdebug.h"
#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

/*
 * rintl(x)
 * Return x rounded to integral value according to the prevailing
 * rounding mode.
 * Method:
 *	Using floating addition.
 * Exception:
 *	Inexact flag raised if x not equal to rintl(x).
 */

#ifndef __NO_LONG_DOUBLE_MATH

#ifndef __have_fpu_rint

static long double __ieee754_roundevenl(long double x) {
  int32_t j0;
  uint32_t se, i1, i0;

  static const long double hugeval = 1.0e4930L;

  GET_LDOUBLE_WORDS(se, i0, i1, x);
  j0 = (se & IEEE854_LONG_DOUBLE_MAXEXP) - IEEE854_LONG_DOUBLE_BIAS;
  if (j0 < 31) {
    if (j0 < 0) {
      math_force_eval(hugeval + x);
      se &= 0x8000;
      if (j0 == -1 && (i0 & UC(0x7fffffff)) != 0) {
        se |= 0x3fff;
        i0 = UC(0x80000000);
      } else {
        i0 = 0;
      }
      i1 = 0;
    } else {
      uint32_t i = UC(0x7fffffff) >> j0;
      uint32_t j;

      if (((i0 & i) | i1) == 0)
        /* X is integral.  */
        return x;

      /* Raise inexact if x != 0.  */
      math_force_eval(hugeval + x);
      j = i0;
      if ((i0 & (i >> 1)) != 0 || i1 != 0 || (i0 & (UC(0x80000000) >> j0))) {
        j += (UC(0x40000000) >> j0);

        if (j < i0)
          se += 1;
      }
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

    if ((i1 & (i >> 1)) != 0 || (j0 == 32 && (i0 & 1)) ||
        (i1 & (UC(1) << (63 - j0)))) {
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
    }
    i1 &= ~i;
  }

  SET_LDOUBLE_WORDS(x, se, i0, i1);
  long double temp_var_for_ext_0;
  temp_var_for_ext_0 = x;
  AssignLd({(Addr)&temp_var_for_ext_0}, (Addr)&x,
           "/home/shijia/Public/testprogram/s_rintl.c_e.c:95:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

long double __ieee754_rintl(long double x) {
  /*
   * above code relies on a FPU doing the rounding,
   * and using round-to-even for FE_TONEAREST
   */
  int temp_var_for_ext_1;
  temp_var_for_ext_1 = fegetround();
  switch (temp_var_for_ext_1) {
  case FE_UPWARD:
    return __ieee754_ceill(x);
  case FE_DOWNWARD:
    return __ieee754_floorl(x);
  case FE_TOWARDZERO:
    return __ieee754_truncl(x);
  }
  /* case FE_TONEAREST: */
  long double temp_var_for_ext_2;
  temp_var_for_ext_2 = __ieee754_roundevenl(x);
  long double temp_var_for_callexp_0 =
      __ieee754_roundevenl(getFVbyShadow<long double>((Addr)&x));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  AssignLd({(Addr)&temp_var_for_ext_2}, ,
           "/home/shijia/Public/testprogram/s_rintl.c_e.c:118:22");
  callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_2;
}

#endif

long double __rintl(long double x) {
  long double temp_var_for_ext_3;
  temp_var_for_ext_3 = __ieee754_rintl(x);
  long double temp_var_for_callexp_1 =
      __ieee754_rintl(getFVbyShadow<long double>((Addr)&x));
  CallStackPop((Addr)&temp_var_for_callexp_1, getTop(temp_var_for_callexp_1));
  AssignLd({(Addr)&temp_var_for_ext_3}, ,
           "/home/shijia/Public/testprogram/s_rintl.c_e.c:128:22");
  callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_3;
}

__typeof(__rintl) rintl __attribute__((weak, alias("__rintl")));

#endif
