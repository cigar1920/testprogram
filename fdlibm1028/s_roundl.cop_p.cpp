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

  long double temp_var_for_const_0;
  ew_u.value = x;
  AssignLd({(Addr) &(temp_var_for_const_0 = ew_u.value)}, (Addr)&x,
           "/home/shijia/Public/testprogram/s_roundl.c_e.c:15:3 "
           "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
  ;
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
      {
        long double temp_var_for_ext_0;
        temp_var_for_ext_0 = x;
        computeLdAdd((Addr)&temp_var_for_tac_0,
                     {(Addr) &(temp_var_for_const_1 = hugeval), (Addr)&x},
                     "/home/shijia/Public/testprogram/s_roundl.c_e.c:19:7 "
                     "<Spelling=/home/shijia/Public/testprogram/"
                     "s_roundl.c_e.c:19:31>");
        computeLdAdd((Addr)&temp_var_for_tac_1,
                     {(Addr) &(temp_var_for_const_2 = hugeval), (Addr)&x},
                     "/home/shijia/Public/testprogram/s_roundl.c_e.c:19:7 "
                     "<Spelling=/home/shijia/Public/testprogram/"
                     "s_roundl.c_e.c:19:31>");
        AssignLd({(Addr)&temp_var_for_ext_0}, (Addr)&x,
                 "/home/shijia/Public/testprogram/s_roundl.c_e.c:34:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_0;
      }

      /* Raise inexact if x != 0.  */
      math_force_eval(hugeval + x);
      j = i0 + (UC(0x40000000) >> j0);

      if (j < i0) {
        se += 1;
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
                     "/home/shijia/Public/testprogram/s_roundl.c_e.c:42:7 "
                     "<Spelling=/home/shijia/Public/testprogram/"
                     "s_roundl.c_e.c:42:31>");
        computeLdAdd((Addr)&temp_var_for_tac_3,
                     {(Addr) &(temp_var_for_const_4 = hugeval), (Addr)&x},
                     "/home/shijia/Public/testprogram/s_roundl.c_e.c:42:7 "
                     "<Spelling=/home/shijia/Public/testprogram/"
                     "s_roundl.c_e.c:42:31>");
        computeLdAdd((Addr)&temp_var_for_tac_4, {(Addr)&x, (Addr)&x},
                     "/home/shijia/Public/testprogram/s_roundl.c_e.c:58:32");
        AssignLd({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_4,
                 "/home/shijia/Public/testprogram/s_roundl.c_e.c:58:28");
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
                 "/home/shijia/Public/testprogram/s_roundl.c_e.c:67:28");
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
                 "/home/shijia/Public/testprogram/s_roundl.c_e.c:82:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_3;
      }

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
  }

  long double temp_var_for_ext_4;
  temp_var_for_ext_4;
  long double temp_var_for_ext_5;
  temp_var_for_ext_5 = x;
  computeLdAdd((Addr)&temp_var_for_tac_5,
               {(Addr) &(temp_var_for_const_5 = hugeval), (Addr)&x},
               "/home/shijia/Public/testprogram/s_roundl.c_e.c:90:7 "
               "<Spelling=/home/shijia/Public/testprogram/"
               "s_roundl.c_e.c:90:31>");
  computeLdAdd((Addr)&temp_var_for_tac_6,
               {(Addr) &(temp_var_for_const_6 = hugeval), (Addr)&x},
               "/home/shijia/Public/testprogram/s_roundl.c_e.c:90:7 "
               "<Spelling=/home/shijia/Public/testprogram/"
               "s_roundl.c_e.c:90:31>");
  AssignLd({(Addr)&temp_var_for_ext_5}, (Addr)&x,
           "/home/shijia/Public/testprogram/s_roundl.c_e.c:110:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_5;
}

#endif

long double __roundl(long double x) {
  long double temp_var_for_ext_6;
  long double temp_var_for_const_7;
  long double temp_var_for_callexp_0;

  temp_var_for_callexp_0 = __ieee754_roundl(x);
  temp_var_for_ext_6 = temp_var_for_callexp_0;
  AssignLd({(Addr)&temp_var_for_ext_6},
           (Addr) &(temp_var_for_const_7 = temp_var_for_callexp_0),
           "/home/shijia/Public/testprogram/s_roundl.c_e.c:120:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_6;
}

__typeof(__roundl) roundl __attribute__((weak, alias("__roundl")));

#endif
