#include "../ScDebug/scdebug.h"
/* s_modfl.c -- long double version of s_modf.c.
 * Conversion to long double by Ulrich Drepper,
 * Cygnus Support, drepper@cygnus.com.
 */

/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 */

/*
 * modfl(long double x, long double *iptr)
 * return fraction part of x, and return x's integral part in *iptr.
 * Method:
 *	Bit twiddling.
 *
 * Exception:
 *	No exception.
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

#ifndef __have_fpu_modf

long double __ieee754_modfl(long double x, long double *iptr) {
  int32_t i0, i1, j0;
  uint32_t i, se;

  static const long double one = 1.0;

  long double temp_var_for_const_0;
  ew_u.value = x;
  AssignLd({(Addr) &(temp_var_for_const_0 = ew_u.value)}, (Addr)&x,
           "/home/shijia/Public/testprogram/s_modfl.c_e.c:41:3 "
           "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
  ;
  j0 = (se & IEEE854_LONG_DOUBLE_MAXEXP) -
       IEEE854_LONG_DOUBLE_BIAS; /* exponent of x */
  if (j0 < 32) {                 /* integer part in high x */
    if (j0 < 0) {                /* |x|<1 */
      long double temp_var_for_ext_0;
      temp_var_for_ext_0; /* *iptr = +-0 */
      long double temp_var_for_ext_1;
      temp_var_for_ext_1 = x;
      AssignLd({(Addr)&temp_var_for_ext_1}, (Addr)&x,
               "/home/shijia/Public/testprogram/s_modfl.c_e.c:49:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_1;
    } else {
      i = IC(0x7fffffff) >> j0;
      if (((i0 & i) | i1) == 0) { /* x is integral */
        long double temp_var_for_const_1;
        (*(iptr)) = x;
        AssignLd({(Addr) &(temp_var_for_const_1 = (*(iptr)))}, (Addr)&x,
                 "/home/shijia/Public/testprogram/s_modfl.c_e.c:57:15");
        ;
        long double temp_var_for_ext_2;
        temp_var_for_ext_2; /* return +-0 */
        long double temp_var_for_ext_3;
        temp_var_for_ext_3 = x;
        AssignLd({(Addr)&temp_var_for_ext_3}, (Addr)&x,
                 "/home/shijia/Public/testprogram/s_modfl.c_e.c:61:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_3;
      } else {
        long double temp_var_for_ext_4;
        temp_var_for_ext_4;
        long double temp_var_for_ext_5;
        long double temp_var_for_tac_0;
        long double temp_var_for_const_2;
        temp_var_for_tac_0 = x - (*(iptr));

        temp_var_for_ext_5 = temp_var_for_tac_0;
        computeLdSub((Addr)&temp_var_for_tac_0,
                     {(Addr)&x, (Addr) &(temp_var_for_const_2 = (*(iptr)))},
                     "/home/shijia/Public/testprogram/s_modfl.c_e.c:70:32");
        AssignLd({(Addr)&temp_var_for_ext_5}, (Addr)&temp_var_for_tac_0,
                 "/home/shijia/Public/testprogram/s_modfl.c_e.c:70:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_5;
      }
    }
  } else {
    if (j0 > 63) { /* no fraction part */
      long double temp_var_for_tac_1;
      long double temp_var_for_const_3, temp_var_for_const_4;
      temp_var_for_tac_1 = x * one;

      (*(iptr)) = temp_var_for_tac_1;
      computeLdMul((Addr)&temp_var_for_tac_1,
                   {(Addr)&x, (Addr) &(temp_var_for_const_3 = one)},
                   "/home/shijia/Public/testprogram/s_modfl.c_e.c:79:17");
      AssignLd({(Addr) &(temp_var_for_const_4 = (*(iptr)))},
               (Addr)&temp_var_for_tac_1,
               "/home/shijia/Public/testprogram/s_modfl.c_e.c:79:13");
      ;
      /* We must handle NaNs separately.  */
      if (j0 == (IEEE854_LONG_DOUBLE_MAXEXP - IEEE854_LONG_DOUBLE_BIAS) &&
          ((i0 & IC(0x7fffffff)) | i1) != 0) {
        long double temp_var_for_ext_6;
        long double temp_var_for_tac_2;
        long double temp_var_for_const_5;
        temp_var_for_tac_2 = x * one;

        temp_var_for_ext_6 = temp_var_for_tac_2;
        computeLdMul((Addr)&temp_var_for_tac_2,
                     {(Addr)&x, (Addr) &(temp_var_for_const_5 = one)},
                     "/home/shijia/Public/testprogram/s_modfl.c_e.c:84:32");
        AssignLd({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_2,
                 "/home/shijia/Public/testprogram/s_modfl.c_e.c:84:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_6;
      }

      long double temp_var_for_ext_7;
      temp_var_for_ext_7; /* return +-0 */
      long double temp_var_for_ext_8;
      temp_var_for_ext_8 = x;
      AssignLd({(Addr)&temp_var_for_ext_8}, (Addr)&x,
               "/home/shijia/Public/testprogram/s_modfl.c_e.c:94:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_8;
    } else { /* fraction part in low x */
      i = UC(0x7fffffff) >> (j0 - 32);
      if ((i1 & i) == 0) { /* x is integral */
        long double temp_var_for_const_6;
        (*(iptr)) = x;
        AssignLd({(Addr) &(temp_var_for_const_6 = (*(iptr)))}, (Addr)&x,
                 "/home/shijia/Public/testprogram/s_modfl.c_e.c:102:15");
        ;
        long double temp_var_for_ext_9;
        temp_var_for_ext_9; /* return +-0 */
        long double temp_var_for_ext_10;
        temp_var_for_ext_10 = x;
        AssignLd({(Addr)&temp_var_for_ext_10}, (Addr)&x,
                 "/home/shijia/Public/testprogram/s_modfl.c_e.c:106:29");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_10", (Addr)&temp_var_for_ext_10));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_10;
      } else {
        long double temp_var_for_ext_11;
        temp_var_for_ext_11;
        long double temp_var_for_ext_12;
        long double temp_var_for_tac_3;
        long double temp_var_for_const_7;
        temp_var_for_tac_3 = x - (*(iptr));

        temp_var_for_ext_12 = temp_var_for_tac_3;
        computeLdSub((Addr)&temp_var_for_tac_3,
                     {(Addr)&x, (Addr) &(temp_var_for_const_7 = (*(iptr)))},
                     "/home/shijia/Public/testprogram/s_modfl.c_e.c:115:33");
        AssignLd({(Addr)&temp_var_for_ext_12}, (Addr)&temp_var_for_tac_3,
                 "/home/shijia/Public/testprogram/s_modfl.c_e.c:115:29");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_12", (Addr)&temp_var_for_ext_12));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_12;
      }
    }
  }
}

#endif

long double __modfl(long double x, long double *iptr) {
  long double temp_var_for_ext_13;
  long double temp_var_for_const_8;
  long double temp_var_for_callexp_0;

  temp_var_for_callexp_0 = __ieee754_modfl(x, iptr);
  temp_var_for_ext_13 = temp_var_for_callexp_0;
  AssignLd({(Addr)&temp_var_for_ext_13},
           (Addr) &(temp_var_for_const_8 = temp_var_for_callexp_0),
           "/home/shijia/Public/testprogram/s_modfl.c_e.c:129:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_13", (Addr)&temp_var_for_ext_13));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_13;
}

__typeof(__modfl) modfl __attribute__((weak, alias("__modfl")));

#endif
