#include "../ScDebug/scdebug.h"
#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_round

float __ieee754_roundf(float x) {
  int32_t i0, j0;

  static const float hugeval = 1.0e30;

  GET_FLOAT_WORD(i0, x);
  j0 =
      ((i0 >> IEEE754_FLOAT_SHIFT) & IEEE754_FLOAT_MAXEXP) - IEEE754_FLOAT_BIAS;
  if (j0 < IEEE754_FLOAT_SHIFT) {
    if (j0 < 0) {
      math_force_eval(hugeval + x);

      i0 &= IC(0x80000000);
      if (j0 == -1) {
        i0 |= IC(0x3f800000);
      }

    } else {
      uint32_t i = UC(0x007fffff) >> j0;

      if ((i0 & i) == 0)
      /* X is integral.  */
      {
        float temp_var_for_ext_0;
        temp_var_for_ext_0 = x;
        computeFAdd((Addr)&temp_var_for_tac_0,
                    {(Addr) &(temp_var_for_const_0 = hugeval), (Addr)&x},
                    "/home/shijia/Public/testprogram/s_roundf.c_e.c:17:7 "
                    "<Spelling=/home/shijia/Public/testprogram/"
                    "s_roundf.c_e.c:17:31>");
        computeFAdd((Addr)&temp_var_for_tac_1,
                    {(Addr) &(temp_var_for_const_1 = hugeval), (Addr)&x},
                    "/home/shijia/Public/testprogram/s_roundf.c_e.c:17:7 "
                    "<Spelling=/home/shijia/Public/testprogram/"
                    "s_roundf.c_e.c:17:31>");
        AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&x,
                "/home/shijia/Public/testprogram/s_roundf.c_e.c:31:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_0;
      }

      math_force_eval(hugeval + x);

      /* Raise inexact if x != 0.  */
      i0 += UC(0x00400000) >> j0;
      i0 &= ~i;
    }
  } else {
    if (j0 == (IEEE754_FLOAT_MAXEXP - IEEE754_FLOAT_BIAS))
    /* Inf or NaN.  */
    {
      float temp_var_for_ext_1;
      float temp_var_for_tac_4;
      temp_var_for_tac_4 = x + x;

      temp_var_for_ext_1 = temp_var_for_tac_4;
      computeFAdd((Addr)&temp_var_for_tac_2,
                  {(Addr) &(temp_var_for_const_2 = hugeval), (Addr)&x},
                  "/home/shijia/Public/testprogram/s_roundf.c_e.c:38:7 "
                  "<Spelling=/home/shijia/Public/testprogram/"
                  "s_roundf.c_e.c:38:31>");
      computeFAdd((Addr)&temp_var_for_tac_3,
                  {(Addr) &(temp_var_for_const_3 = hugeval), (Addr)&x},
                  "/home/shijia/Public/testprogram/s_roundf.c_e.c:38:7 "
                  "<Spelling=/home/shijia/Public/testprogram/"
                  "s_roundf.c_e.c:38:31>");
      computeFAdd((Addr)&temp_var_for_tac_4, {(Addr)&x, (Addr)&x},
                  "/home/shijia/Public/testprogram/s_roundf.c_e.c:49:30");
      AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_4,
              "/home/shijia/Public/testprogram/s_roundf.c_e.c:49:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_1;
    }

    else {
      float temp_var_for_ext_2;
      temp_var_for_ext_2 = x;
      AssignF({(Addr)&temp_var_for_ext_2}, (Addr)&x,
              "/home/shijia/Public/testprogram/s_roundf.c_e.c:58:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_2;
    }
  }

  SET_FLOAT_WORD(x, i0);
  float temp_var_for_ext_3;
  temp_var_for_ext_3 = x;
  AssignF({(Addr)&temp_var_for_ext_3}, (Addr)&x,
          "/home/shijia/Public/testprogram/s_roundf.c_e.c:68:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_3;
}

#endif

float __roundf(float x) {
  float temp_var_for_ext_4;
  float temp_var_for_const_4;
  float temp_var_for_callexp_0;

  temp_var_for_callexp_0 = __ieee754_roundf(x);
  temp_var_for_ext_4 = temp_var_for_callexp_0;
  AssignF({(Addr)&temp_var_for_ext_4},
          (Addr) &(temp_var_for_const_4 = temp_var_for_callexp_0),
          "/home/shijia/Public/testprogram/s_roundf.c_e.c:78:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_4;
}

__typeof(__roundf) roundf __attribute__((weak, alias("__roundf")));
