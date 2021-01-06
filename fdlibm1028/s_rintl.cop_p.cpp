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

  long double temp_var_for_const_0;
  ew_u.value = x;
  AssignLd({(Addr) &(temp_var_for_const_0 = ew_u.value)}, (Addr)&x,
           "/home/shijia/Public/testprogram/s_rintl.c_e.c:25:3 "
           "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
  ;
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
      {
        long double temp_var_for_ext_0;
        temp_var_for_ext_0 = x;
        computeLdAdd((Addr)&temp_var_for_tac_0,
                     {(Addr) &(temp_var_for_const_1 = hugeval), (Addr)&x},
                     "/home/shijia/Public/testprogram/s_rintl.c_e.c:29:7 "
                     "<Spelling=/home/shijia/Public/testprogram/"
                     "s_rintl.c_e.c:29:31>");
        computeLdAdd((Addr)&temp_var_for_tac_1,
                     {(Addr) &(temp_var_for_const_2 = hugeval), (Addr)&x},
                     "/home/shijia/Public/testprogram/s_rintl.c_e.c:29:7 "
                     "<Spelling=/home/shijia/Public/testprogram/"
                     "s_rintl.c_e.c:29:31>");
        AssignLd({(Addr)&temp_var_for_ext_0}, (Addr)&x,
                 "/home/shijia/Public/testprogram/s_rintl.c_e.c:46:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_0;
      }

      /* Raise inexact if x != 0.  */
      math_force_eval(hugeval + x);
      j = i0;
      if ((i0 & (i >> 1)) != 0 || i1 != 0 || (i0 & (UC(0x80000000) >> j0))) {
        j += (UC(0x40000000) >> j0);

        if (j < i0) {
          se += 1;
        }
      }
      i0 = (j & ~i) | IC(0x80000000);
      i1 = 0;
    }
  } else {
    if (j0 > 62) {
      if (j0 == (IEEE854_LONG_DOUBLE_MAXEXP - IEEE854_LONG_DOUBLE_BIAS))
      /* Inf or NaN.  */
      {
        long double temp_var_for_ext_1;
        long double temp_var_for_tac_4;
        temp_var_for_tac_4 = x + x;

        temp_var_for_ext_1 = temp_var_for_tac_4;
        computeLdAdd((Addr)&temp_var_for_tac_2,
                     {(Addr) &(temp_var_for_const_3 = hugeval), (Addr)&x},
                     "/home/shijia/Public/testprogram/s_rintl.c_e.c:54:7 "
                     "<Spelling=/home/shijia/Public/testprogram/"
                     "s_rintl.c_e.c:54:31>");
        computeLdAdd((Addr)&temp_var_for_tac_3,
                     {(Addr) &(temp_var_for_const_4 = hugeval), (Addr)&x},
                     "/home/shijia/Public/testprogram/s_rintl.c_e.c:54:7 "
                     "<Spelling=/home/shijia/Public/testprogram/"
                     "s_rintl.c_e.c:54:31>");
        computeLdAdd((Addr)&temp_var_for_tac_4, {(Addr)&x, (Addr)&x},
                     "/home/shijia/Public/testprogram/s_rintl.c_e.c:72:32");
        AssignLd({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_4,
                 "/home/shijia/Public/testprogram/s_rintl.c_e.c:72:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_1;
      }

      else {
        long double temp_var_for_ext_2;
        temp_var_for_ext_2 = x;
        AssignLd({(Addr)&temp_var_for_ext_2}, (Addr)&x,
                 "/home/shijia/Public/testprogram/s_rintl.c_e.c:81:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_2;
      }

    } else {
      uint32_t i = UC(0xffffffff) >> (j0 - 31);
      uint32_t j;

      if ((i1 & i) == 0)
      /* X is integral.  */
      {
        long double temp_var_for_ext_3;
        temp_var_for_ext_3 = x;
        AssignLd({(Addr)&temp_var_for_ext_3}, (Addr)&x,
                 "/home/shijia/Public/testprogram/s_rintl.c_e.c:96:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_3;
      }

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
  }

  long double temp_var_for_ext_4;
  temp_var_for_ext_4;
  long double temp_var_for_ext_5;
  temp_var_for_ext_5 = x;
  computeLdAdd((Addr)&temp_var_for_tac_5,
               {(Addr) &(temp_var_for_const_5 = hugeval), (Addr)&x},
               "/home/shijia/Public/testprogram/s_rintl.c_e.c:104:7 "
               "<Spelling=/home/shijia/Public/testprogram/"
               "s_rintl.c_e.c:104:31>");
  computeLdAdd((Addr)&temp_var_for_tac_6,
               {(Addr) &(temp_var_for_const_6 = hugeval), (Addr)&x},
               "/home/shijia/Public/testprogram/s_rintl.c_e.c:104:7 "
               "<Spelling=/home/shijia/Public/testprogram/"
               "s_rintl.c_e.c:104:31>");
  AssignLd({(Addr)&temp_var_for_ext_5}, (Addr)&x,
           "/home/shijia/Public/testprogram/s_rintl.c_e.c:128:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_5;
}

long double __ieee754_rintl(long double x) {
  /*
   * above code relies on a FPU doing the rounding,
   * and using round-to-even for FE_TONEAREST
   */
  int temp_var_for_ext_6;
  temp_var_for_ext_6 = fegetround();
  switch (temp_var_for_ext_6) {
  case FE_UPWARD: {
    long double temp_var_for_ext_7;
    long double temp_var_for_const_7;
    long double temp_var_for_callexp_0;

    temp_var_for_callexp_0 = __ieee754_ceill(x);
    temp_var_for_ext_7 = temp_var_for_callexp_0;
    AssignLd({(Addr)&temp_var_for_ext_7},
             (Addr) &(temp_var_for_const_7 = temp_var_for_callexp_0),
             "/home/shijia/Public/testprogram/s_rintl.c_e.c:144:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_7;
  }

  case FE_DOWNWARD: {
    long double temp_var_for_ext_8;
    long double temp_var_for_const_8;
    long double temp_var_for_callexp_1;

    temp_var_for_callexp_1 = __ieee754_floorl(x);
    temp_var_for_ext_8 = temp_var_for_callexp_1;
    AssignLd({(Addr)&temp_var_for_ext_8},
             (Addr) &(temp_var_for_const_8 = temp_var_for_callexp_1),
             "/home/shijia/Public/testprogram/s_rintl.c_e.c:152:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_8;
  }

  case FE_TOWARDZERO: {
    long double temp_var_for_ext_9;
    long double temp_var_for_const_9;
    long double temp_var_for_callexp_2;

    temp_var_for_callexp_2 = __ieee754_truncl(x);
    temp_var_for_ext_9 = temp_var_for_callexp_2;
    AssignLd({(Addr)&temp_var_for_ext_9},
             (Addr) &(temp_var_for_const_9 = temp_var_for_callexp_2),
             "/home/shijia/Public/testprogram/s_rintl.c_e.c:160:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_9;
  }
  }
  /* case FE_TONEAREST: */
  long double temp_var_for_ext_10;
  long double temp_var_for_const_10;
  long double temp_var_for_callexp_3;

  temp_var_for_callexp_3 = __ieee754_roundevenl(x);
  temp_var_for_ext_10 = temp_var_for_callexp_3;
  AssignLd({(Addr)&temp_var_for_ext_10},
           (Addr) &(temp_var_for_const_10 = temp_var_for_callexp_3),
           "/home/shijia/Public/testprogram/s_rintl.c_e.c:168:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_10", (Addr)&temp_var_for_ext_10));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_10;
}

#endif

long double __rintl(long double x) {
  long double temp_var_for_ext_11;
  long double temp_var_for_const_11;
  long double temp_var_for_callexp_4;

  temp_var_for_callexp_4 = __ieee754_rintl(x);
  temp_var_for_ext_11 = temp_var_for_callexp_4;
  AssignLd({(Addr)&temp_var_for_ext_11},
           (Addr) &(temp_var_for_const_11 = temp_var_for_callexp_4),
           "/home/shijia/Public/testprogram/s_rintl.c_e.c:178:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_11", (Addr)&temp_var_for_ext_11));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_11;
}

__typeof(__rintl) rintl __attribute__((weak, alias("__rintl")));

#endif
