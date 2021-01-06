#include "../ScDebug/scdebug.h"
/* s_modff.c -- float version of s_modf.c.
 * Conversion to float by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.
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

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_modf

float __ieee754_modff(float x, float *iptr) {
  int32_t i0, j0;
  uint32_t i;

  static const float one = 1.0;

  GET_FLOAT_WORD(i0, x);
  j0 = ((i0 >> IEEE754_FLOAT_SHIFT) & IEEE754_FLOAT_MAXEXP) -
       IEEE754_FLOAT_BIAS;                        /* exponent of x */
  if (j0 < IEEE754_FLOAT_SHIFT) {                 /* integer part in x */
    if (j0 < 0) {                                 /* |x|<1 */
      SET_FLOAT_WORD(*iptr, i0 & IC(0x80000000)); /* *iptr = +-0 */
      float temp_var_for_ext_0;
      temp_var_for_ext_0 = x;
      AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&x,
              "/home/shijia/Public/testprogram/s_modff.c_e.c:35:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_0;
    } else {
      i = IC(0x007fffff) >> j0;
      if ((i0 & i) == 0) { /* x is integral */
        uint32_t ix;

        float temp_var_for_const_0;
        (*(iptr)) = x;
        AssignF({(Addr) &(temp_var_for_const_0 = (*(iptr)))}, (Addr)&x,
                "/home/shijia/Public/testprogram/s_modff.c_e.c:45:15");
        ;
        GET_FLOAT_WORD(ix, x);
        SET_FLOAT_WORD(x, ix & IC(0x80000000)); /* return +-0 */
        float temp_var_for_ext_1;
        temp_var_for_ext_1 = x;
        AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&x,
                "/home/shijia/Public/testprogram/s_modff.c_e.c:49:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_1;
      } else {
        SET_FLOAT_WORD(*iptr, i0 & (~i));
        float temp_var_for_ext_2;
        float temp_var_for_tac_0;
        float temp_var_for_const_1;
        temp_var_for_tac_0 = x - (*(iptr));

        temp_var_for_ext_2 = temp_var_for_tac_0;
        computeFSub((Addr)&temp_var_for_tac_0,
                    {(Addr)&x, (Addr) &(temp_var_for_const_1 = (*(iptr)))},
                    "/home/shijia/Public/testprogram/s_modff.c_e.c:57:32");
        AssignF({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_0,
                "/home/shijia/Public/testprogram/s_modff.c_e.c:57:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_2;
      }
    }
  } else { /* no fraction part */
    float temp_var_for_tac_1;
    float temp_var_for_const_2, temp_var_for_const_3;
    temp_var_for_tac_1 = x * one;

    (*(iptr)) = temp_var_for_tac_1;
    computeFMul((Addr)&temp_var_for_tac_1,
                {(Addr)&x, (Addr) &(temp_var_for_const_2 = one)},
                "/home/shijia/Public/testprogram/s_modff.c_e.c:65:15");
    AssignF({(Addr) &(temp_var_for_const_3 = (*(iptr)))},
            (Addr)&temp_var_for_tac_1,
            "/home/shijia/Public/testprogram/s_modff.c_e.c:65:11");
    ;
    /* We must handle NaNs separately.  */
    if (j0 == (IEEE754_FLOAT_MAXEXP - IEEE754_FLOAT_BIAS) &&
        (i0 & IC(0x7fffff)) != 0) {
      float temp_var_for_ext_3;
      float temp_var_for_tac_2;
      float temp_var_for_const_4;
      temp_var_for_tac_2 = x * one;

      temp_var_for_ext_3 = temp_var_for_tac_2;
      computeFMul((Addr)&temp_var_for_tac_2,
                  {(Addr)&x, (Addr) &(temp_var_for_const_4 = one)},
                  "/home/shijia/Public/testprogram/s_modff.c_e.c:70:30");
      AssignF({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_2,
              "/home/shijia/Public/testprogram/s_modff.c_e.c:70:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_3;
    }

    SET_FLOAT_WORD(x, i0 & IC(0x80000000)); /* return +-0 */
    float temp_var_for_ext_4;
    temp_var_for_ext_4 = x;
    AssignF({(Addr)&temp_var_for_ext_4}, (Addr)&x,
            "/home/shijia/Public/testprogram/s_modff.c_e.c:79:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_4;
  }
}

#endif

float __modff(float x, float *iptr) {
  float temp_var_for_ext_5;
  float temp_var_for_const_5;
  float temp_var_for_callexp_0;

  temp_var_for_callexp_0 = __ieee754_modff(x, iptr);
  temp_var_for_ext_5 = temp_var_for_callexp_0;
  AssignF({(Addr)&temp_var_for_ext_5},
          (Addr) &(temp_var_for_const_5 = temp_var_for_callexp_0),
          "/home/shijia/Public/testprogram/s_modff.c_e.c:90:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_5;
}

__typeof(__modff) modff __attribute__((weak, alias("__modff")));
