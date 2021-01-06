#include "../ScDebug/scdebug.h"
#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_floor

float __ieee754_floorf(float x) {
  int32_t i0, j0;
  uint32_t i;

  static const float hugeval = 1.0e30;

  GET_FLOAT_WORD(i0, x);
  j0 =
      ((i0 >> IEEE754_FLOAT_SHIFT) & IEEE754_FLOAT_MAXEXP) - IEEE754_FLOAT_BIAS;
  if (j0 < IEEE754_FLOAT_SHIFT) {
    if (j0 < 0) {                   /* raise inexact if x != 0 */
      math_force_eval(hugeval + x); /* return 0*sign(x) if |x|<1 */
      if (i0 >= 0) {
        i0 = 0;
      } else {
        if ((i0 & UC(0x7fffffff)) != 0) {
          i0 = UC(0xbf800000);
        }
      }

    } else {
      i = UC(0x007fffff) >> j0;
      if ((i0 & i) == 0) {
        float temp_var_for_ext_0;
        temp_var_for_ext_0 = x;
        computeFAdd((Addr)&temp_var_for_tac_0,
                    {(Addr) &(temp_var_for_const_0 = hugeval), (Addr)&x},
                    "/home/shijia/Public/testprogram/s_floorf.c_e.c:18:7 "
                    "<Spelling=/home/shijia/Public/testprogram/"
                    "s_floorf.c_e.c:18:31>");
        computeFAdd((Addr)&temp_var_for_tac_1,
                    {(Addr) &(temp_var_for_const_1 = hugeval), (Addr)&x},
                    "/home/shijia/Public/testprogram/s_floorf.c_e.c:18:7 "
                    "<Spelling=/home/shijia/Public/testprogram/"
                    "s_floorf.c_e.c:18:31>");
        AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&x,
                "/home/shijia/Public/testprogram/s_floorf.c_e.c:31:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_0;
      }
      /* x is integral */
      math_force_eval(hugeval + x); /* raise inexact flag */
      if (i0 < 0) {
        i0 += UC(0x00800000) >> j0;
      }

      i0 &= (~i);
    }
  } else {
    if (j0 == (IEEE754_FLOAT_MAXEXP - IEEE754_FLOAT_BIAS)) {
      float temp_var_for_ext_1;
      float temp_var_for_tac_4;
      temp_var_for_tac_4 = x + x;

      temp_var_for_ext_1 = temp_var_for_tac_4;
      computeFAdd((Addr)&temp_var_for_tac_2,
                  {(Addr) &(temp_var_for_const_2 = hugeval), (Addr)&x},
                  "/home/shijia/Public/testprogram/s_floorf.c_e.c:38:7 "
                  "<Spelling=/home/shijia/Public/testprogram/"
                  "s_floorf.c_e.c:38:31>");
      computeFAdd((Addr)&temp_var_for_tac_3,
                  {(Addr) &(temp_var_for_const_3 = hugeval), (Addr)&x},
                  "/home/shijia/Public/testprogram/s_floorf.c_e.c:38:7 "
                  "<Spelling=/home/shijia/Public/testprogram/"
                  "s_floorf.c_e.c:38:31>");
      computeFAdd((Addr)&temp_var_for_tac_4, {(Addr)&x, (Addr)&x},
                  "/home/shijia/Public/testprogram/s_floorf.c_e.c:48:30");
      AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_4,
              "/home/shijia/Public/testprogram/s_floorf.c_e.c:48:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_1;
    }
    /* inf or NaN */
    else {
      float temp_var_for_ext_2;
      temp_var_for_ext_2 = x;
      AssignF({(Addr)&temp_var_for_ext_2}, (Addr)&x,
              "/home/shijia/Public/testprogram/s_floorf.c_e.c:57:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_2;
    }
    /* x is integral */
  }
  SET_FLOAT_WORD(x, i0);
  float temp_var_for_ext_3;
  temp_var_for_ext_3 = x;
  AssignF({(Addr)&temp_var_for_ext_3}, (Addr)&x,
          "/home/shijia/Public/testprogram/s_floorf.c_e.c:67:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_3;
}

#endif

float __floorf(float x) {
  float temp_var_for_ext_4;
  float temp_var_for_const_4;
  float temp_var_for_callexp_0;

  temp_var_for_callexp_0 = __ieee754_floorf(x);
  temp_var_for_ext_4 = temp_var_for_callexp_0;
  AssignF({(Addr)&temp_var_for_ext_4},
          (Addr) &(temp_var_for_const_4 = temp_var_for_callexp_0),
          "/home/shijia/Public/testprogram/s_floorf.c_e.c:77:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_4;
}

__typeof(__floorf) floorf __attribute__((weak, alias("__floorf")));
