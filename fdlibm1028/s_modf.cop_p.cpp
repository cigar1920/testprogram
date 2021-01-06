#include "../ScDebug/scdebug.h"
/* @(#)s_modf.c 1.3 95/01/18 */
/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunSoft, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 */

/*
 * modf(double x, double *iptr)
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

#ifndef __have_fpu_modf

double __ieee754_modf(double x, double *iptr) {
  int32_t i0, i1, j0;
  uint32_t i;

  static const double one = 1.0;

  GET_DOUBLE_WORDS(i0, i1, x);
  j0 = ((i0 >> IEEE754_DOUBLE_SHIFT) & IEEE754_DOUBLE_MAXEXP) -
       IEEE754_DOUBLE_BIAS;                        /* exponent of x */
  if (j0 < IEEE754_DOUBLE_SHIFT) {                 /* integer part in high x */
    if (j0 < 0) {                                  /* |x|<1 */
      INSERT_WORDS(*iptr, i0 & UC(0x80000000), 0); /* *iptr = +-0 */
      double temp_var_for_ext_0;
      temp_var_for_ext_0 = x;
      AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&x,
              "/home/shijia/Public/testprogram/s_modf.c_e.c:42:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_0;
    } else {
      i = UC(0x000fffff) >> j0;
      if (((i0 & i) | i1) == 0) { /* x is integral */
        double temp_var_for_const_0;
        (*(iptr)) = x;
        AssignD({(Addr) &(temp_var_for_const_0 = (*(iptr)))}, (Addr)&x,
                "/home/shijia/Public/testprogram/s_modf.c_e.c:50:15");
        ;
        INSERT_WORDS(x, i0 & UC(0x80000000), 0); /* return +-0 */
        double temp_var_for_ext_1;
        temp_var_for_ext_1 = x;
        AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&x,
                "/home/shijia/Public/testprogram/s_modf.c_e.c:53:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_1;
      } else {
        INSERT_WORDS(*iptr, i0 & (~i), 0);
        double temp_var_for_ext_2;
        double temp_var_for_tac_0;
        double temp_var_for_const_1;
        temp_var_for_tac_0 = x - (*(iptr));

        temp_var_for_ext_2 = temp_var_for_tac_0;
        computeDSub((Addr)&temp_var_for_tac_0,
                    {(Addr)&x, (Addr) &(temp_var_for_const_1 = (*(iptr)))},
                    "/home/shijia/Public/testprogram/s_modf.c_e.c:61:32");
        AssignD({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_0,
                "/home/shijia/Public/testprogram/s_modf.c_e.c:61:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_2;
      }
    }
  } else {
    if (j0 > 51) { /* no fraction part */
      double temp_var_for_tac_1;
      double temp_var_for_const_2, temp_var_for_const_3;
      temp_var_for_tac_1 = x * one;

      (*(iptr)) = temp_var_for_tac_1;
      computeDMul((Addr)&temp_var_for_tac_1,
                  {(Addr)&x, (Addr) &(temp_var_for_const_2 = one)},
                  "/home/shijia/Public/testprogram/s_modf.c_e.c:70:17");
      AssignD({(Addr) &(temp_var_for_const_3 = (*(iptr)))},
              (Addr)&temp_var_for_tac_1,
              "/home/shijia/Public/testprogram/s_modf.c_e.c:70:13");
      ;
      /* We must handle NaNs separately.  */
      if (j0 == (IEEE754_DOUBLE_MAXEXP - IEEE754_DOUBLE_BIAS) &&
          ((i0 & UC(0xfffff)) | i1) != 0) {
        double temp_var_for_ext_3;
        double temp_var_for_tac_2;
        double temp_var_for_const_4;
        temp_var_for_tac_2 = x * one;

        temp_var_for_ext_3 = temp_var_for_tac_2;
        computeDMul((Addr)&temp_var_for_tac_2,
                    {(Addr)&x, (Addr) &(temp_var_for_const_4 = one)},
                    "/home/shijia/Public/testprogram/s_modf.c_e.c:75:32");
        AssignD({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_2,
                "/home/shijia/Public/testprogram/s_modf.c_e.c:75:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_3;
      }

      INSERT_WORDS(x, i0 & UC(0x80000000), 0); /* return +-0 */
      double temp_var_for_ext_4;
      temp_var_for_ext_4 = x;
      AssignD({(Addr)&temp_var_for_ext_4}, (Addr)&x,
              "/home/shijia/Public/testprogram/s_modf.c_e.c:84:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_4;
    } else { /* fraction part in low x */
      i = UC(0xffffffff) >> (j0 - IEEE754_DOUBLE_SHIFT);
      if ((i1 & i) == 0) { /* x is integral */
        double temp_var_for_const_5;
        (*(iptr)) = x;
        AssignD({(Addr) &(temp_var_for_const_5 = (*(iptr)))}, (Addr)&x,
                "/home/shijia/Public/testprogram/s_modf.c_e.c:92:15");
        ;
        INSERT_WORDS(x, i0 & UC(0x80000000), 0); /* return +-0 */
        double temp_var_for_ext_5;
        temp_var_for_ext_5 = x;
        AssignD({(Addr)&temp_var_for_ext_5}, (Addr)&x,
                "/home/shijia/Public/testprogram/s_modf.c_e.c:95:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_5;
      } else {
        INSERT_WORDS(*iptr, i0, i1 & (~i));
        double temp_var_for_ext_6;
        double temp_var_for_tac_3;
        double temp_var_for_const_6;
        temp_var_for_tac_3 = x - (*(iptr));

        temp_var_for_ext_6 = temp_var_for_tac_3;
        computeDSub((Addr)&temp_var_for_tac_3,
                    {(Addr)&x, (Addr) &(temp_var_for_const_6 = (*(iptr)))},
                    "/home/shijia/Public/testprogram/s_modf.c_e.c:103:32");
        AssignD({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_3,
                "/home/shijia/Public/testprogram/s_modf.c_e.c:103:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_6;
      }
    }
  }
}

#endif

double __modf(double x, double *iptr) {
  double temp_var_for_ext_7;
  double temp_var_for_const_7;
  double temp_var_for_callexp_0;

  temp_var_for_callexp_0 = __ieee754_modf(x, iptr);
  temp_var_for_ext_7 = temp_var_for_callexp_0;
  AssignD({(Addr)&temp_var_for_ext_7},
          (Addr) &(temp_var_for_const_7 = temp_var_for_callexp_0),
          "/home/shijia/Public/testprogram/s_modf.c_e.c:117:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_7;
}

__typeof(__modf) modf __attribute__((weak, alias("__modf")));
#ifdef __NO_LONG_DOUBLE_MATH
__typeof(__modfl) __modfl __attribute__((alias("__modf")));
__typeof(__modfl) modfl __attribute__((weak, alias("__modf")));
#endif
