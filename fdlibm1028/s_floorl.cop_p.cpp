#include "../ScDebug/scdebug.h"
#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

#ifndef __have_fpu_floor

long double __ieee754_floorl(long double x) {
  int32_t j0;
  uint32_t i, j, se, i0, i1, sx;

  static const long double hugeval = 1.0e4930L;

  long double temp_var_for_const_0;
  ew_u.value = x;
  AssignLd({(Addr) &(temp_var_for_const_0 = ew_u.value)}, (Addr)&x,
           "/home/shijia/Public/testprogram/s_floorl.c_e.c:15:3 "
           "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
  ;
  sx = (se >> 15) & 1;
  j0 = (se & IEEE854_LONG_DOUBLE_MAXEXP) - IEEE854_LONG_DOUBLE_BIAS;
  if (j0 < 31) {
    if (j0 < 0) { /* raise inexact if x != 0 */
      if (int temp_var_for_tac_0, temp_var_for_tac_1;
          int temp_var_for_const_1, temp_var_for_const_2;
          temp_var_for_tac_0 = hugeval + x;

          temp_var_for_tac_1 = temp_var_for_tac_0 > 0.0;

          ) { /* return 0*sign(x) if |x|<1 */
        if (sx == 0) {
          se = 0;
          i0 = i1 = 0;
        } else {
          if (((se & IEEE854_LONG_DOUBLE_MAXEXP) | i0 | i1) != 0) {
            se = 0xbfff;
            i0 = IC(0x80000000); /* explicit */
            i1 = 0;
          }
        }
      }
    } else {
      i = UC(0x7fffffff) >> j0;
      if (((i0 & i) | i1) == 0) {
        long double temp_var_for_ext_0;
        temp_var_for_ext_0 = x;
        computeLdAdd((Addr)&temp_var_for_tac_0,
                     {(Addr) &(temp_var_for_const_1 = hugeval), (Addr)&x},
                     "/home/shijia/Public/testprogram/s_floorl.c_e.c:20:19");
        compute(
            (Addr)&temp_var_for_tac_1,
            {(Addr)&temp_var_for_tac_0, (Addr) &(temp_var_for_const_2 = 0.0)},
            "/home/shijia/Public/testprogram/s_floorl.c_e.c:20:23");
        AssignLd({(Addr)&temp_var_for_ext_0}, (Addr)&x,
                 "/home/shijia/Public/testprogram/s_floorl.c_e.c:36:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_0;
      }
      /* x is integral */
      if (int temp_var_for_tac_2, temp_var_for_tac_3;
          int temp_var_for_const_3, temp_var_for_const_4;
          temp_var_for_tac_2 = hugeval + x;

          temp_var_for_tac_3 = temp_var_for_tac_2 > 0.0;

          ) { /* raise inexact flag */
        if (sx) {
          if (j0 > 0 && (i0 + (UC(0x80000000) >> j0)) > i0) {
            i0 += UC(0x80000000) >> j0;
          }

          else {
            i = UC(0x7fffffff);
            ++se;
          }
        }
        i0 &= (~i);
        i1 = 0;
      }
    }
  } else {
    if (j0 > 62) {
      if (j0 == (IEEE854_LONG_DOUBLE_MAXEXP - IEEE854_LONG_DOUBLE_BIAS)) {
        long double temp_var_for_ext_1;
        long double temp_var_for_tac_4;
        temp_var_for_tac_4 = x + x;

        temp_var_for_ext_1 = temp_var_for_tac_4;
        computeLdAdd((Addr)&temp_var_for_tac_2,
                     {(Addr) &(temp_var_for_const_3 = hugeval), (Addr)&x},
                     "/home/shijia/Public/testprogram/s_floorl.c_e.c:43:19");
        compute(
            (Addr)&temp_var_for_tac_3,
            {(Addr)&temp_var_for_tac_2, (Addr) &(temp_var_for_const_4 = 0.0)},
            "/home/shijia/Public/testprogram/s_floorl.c_e.c:43:23");
        computeLdAdd((Addr)&temp_var_for_tac_4, {(Addr)&x, (Addr)&x},
                     "/home/shijia/Public/testprogram/s_floorl.c_e.c:62:32");
        AssignLd({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_4,
                 "/home/shijia/Public/testprogram/s_floorl.c_e.c:62:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_1;
      }
      /* inf or NaN */
      else {
        long double temp_var_for_ext_2;
        temp_var_for_ext_2 = x;
        AssignLd({(Addr)&temp_var_for_ext_2}, (Addr)&x,
                 "/home/shijia/Public/testprogram/s_floorl.c_e.c:71:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_2;
      }
      /* x is integral */
    } else {
      i = UC(0xffffffff) >> (j0 - 31);
      if ((i1 & i) == 0) {
        long double temp_var_for_ext_3;
        temp_var_for_ext_3 = x;
        AssignLd({(Addr)&temp_var_for_ext_3}, (Addr)&x,
                 "/home/shijia/Public/testprogram/s_floorl.c_e.c:82:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_3;
      }
      /* x is integral */
      if (int temp_var_for_tac_5, temp_var_for_tac_6;
          int temp_var_for_const_5, temp_var_for_const_6;
          temp_var_for_tac_5 = hugeval + x;

          temp_var_for_tac_6 = temp_var_for_tac_5 > 0.0;

          ) { /* raise inexact flag */
        if (sx) {
          if (j0 == 31) {
            i0 += 1;
          }

          else {
            j = i1 + (UC(1) << (63 - j0));
            if (j < i1) {
              i0 += 1;
            }
            /* got a carry */
            i1 = j;
          }
        }
        i1 &= (~i);
      }
    }
  }

  long double temp_var_for_ext_4;
  temp_var_for_ext_4;
  long double temp_var_for_ext_5;
  temp_var_for_ext_5 = x;
  computeLdAdd((Addr)&temp_var_for_tac_5,
               {(Addr) &(temp_var_for_const_5 = hugeval), (Addr)&x},
               "/home/shijia/Public/testprogram/s_floorl.c_e.c:89:19");
  compute((Addr)&temp_var_for_tac_6,
          {(Addr)&temp_var_for_tac_5, (Addr) &(temp_var_for_const_6 = 0.0)},
          "/home/shijia/Public/testprogram/s_floorl.c_e.c:89:23");
  AssignLd({(Addr)&temp_var_for_ext_5}, (Addr)&x,
           "/home/shijia/Public/testprogram/s_floorl.c_e.c:112:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_5;
}

#endif

long double __floorl(long double x) {
  long double temp_var_for_ext_6;
  long double temp_var_for_const_7;
  long double temp_var_for_callexp_0;

  temp_var_for_callexp_0 = __ieee754_floorl(x);
  temp_var_for_ext_6 = temp_var_for_callexp_0;
  AssignLd({(Addr)&temp_var_for_ext_6},
           (Addr) &(temp_var_for_const_7 = temp_var_for_callexp_0),
           "/home/shijia/Public/testprogram/s_floorl.c_e.c:122:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_6;
}

__typeof(__floorl) floorl __attribute__((weak, alias("__floorl")));

#endif
