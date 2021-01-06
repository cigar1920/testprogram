#include "../ScDebug/scdebug.h"
#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_rint

static float __ieee754_roundevenf(float x) {
  int32_t i0, j0;

  static const float hugeval = 1.0e30;

  GET_FLOAT_WORD(i0, x);
  j0 =
      ((i0 >> IEEE754_FLOAT_SHIFT) & IEEE754_FLOAT_MAXEXP) - IEEE754_FLOAT_BIAS;
  if (j0 < IEEE754_FLOAT_SHIFT) {
    if (j0 < 0) {
      math_force_eval(hugeval + x);

      if (j0 == -1 && (i0 & IC(0x007fffff)) != 0) {
        i0 &= IC(0x80000000);
        i0 |= IC(0x3f800000);
      } else {
        i0 &= IC(0x80000000);
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
                    "/home/shijia/Public/testprogram/s_rintf.c_e.c:17:7 "
                    "<Spelling=/home/shijia/Public/testprogram/"
                    "s_rintf.c_e.c:17:31>");
        computeFAdd((Addr)&temp_var_for_tac_1,
                    {(Addr) &(temp_var_for_const_1 = hugeval), (Addr)&x},
                    "/home/shijia/Public/testprogram/s_rintf.c_e.c:17:7 "
                    "<Spelling=/home/shijia/Public/testprogram/"
                    "s_rintf.c_e.c:17:31>");
        AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&x,
                "/home/shijia/Public/testprogram/s_rintf.c_e.c:32:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_0;
      }

      /* Raise inexact if x != 0.  */
      math_force_eval(hugeval + x);

      if ((i0 & (i >> 1)) != 0 || (i0 & (UC(0x00800000) >> j0))) {
        i0 += UC(0x00400000) >> j0;
      }
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
                  "/home/shijia/Public/testprogram/s_rintf.c_e.c:40:7 "
                  "<Spelling=/home/shijia/Public/testprogram/"
                  "s_rintf.c_e.c:40:31>");
      computeFAdd((Addr)&temp_var_for_tac_3,
                  {(Addr) &(temp_var_for_const_3 = hugeval), (Addr)&x},
                  "/home/shijia/Public/testprogram/s_rintf.c_e.c:40:7 "
                  "<Spelling=/home/shijia/Public/testprogram/"
                  "s_rintf.c_e.c:40:31>");
      computeFAdd((Addr)&temp_var_for_tac_4, {(Addr)&x, (Addr)&x},
                  "/home/shijia/Public/testprogram/s_rintf.c_e.c:52:30");
      AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_4,
              "/home/shijia/Public/testprogram/s_rintf.c_e.c:52:26");
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
              "/home/shijia/Public/testprogram/s_rintf.c_e.c:61:26");
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
          "/home/shijia/Public/testprogram/s_rintf.c_e.c:71:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_3;
}

float __ieee754_rintf(float x) {
  /*
   * above code relies on a FPU doing the rounding,
   * and using round-to-even for FE_TONEAREST
   */
  int temp_var_for_ext_4;
  temp_var_for_ext_4 = fegetround();
  switch (temp_var_for_ext_4) {
  case FE_UPWARD: {
    float temp_var_for_ext_5;
    float temp_var_for_const_4;
    float temp_var_for_callexp_0;

    temp_var_for_callexp_0 = __ieee754_ceilf(x);
    temp_var_for_ext_5 = temp_var_for_callexp_0;
    AssignF({(Addr)&temp_var_for_ext_5},
            (Addr) &(temp_var_for_const_4 = temp_var_for_callexp_0),
            "/home/shijia/Public/testprogram/s_rintf.c_e.c:87:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_5;
  }

  case FE_DOWNWARD: {
    float temp_var_for_ext_6;
    float temp_var_for_const_5;
    float temp_var_for_callexp_1;

    temp_var_for_callexp_1 = __ieee754_floorf(x);
    temp_var_for_ext_6 = temp_var_for_callexp_1;
    AssignF({(Addr)&temp_var_for_ext_6},
            (Addr) &(temp_var_for_const_5 = temp_var_for_callexp_1),
            "/home/shijia/Public/testprogram/s_rintf.c_e.c:95:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_6;
  }

  case FE_TOWARDZERO: {
    float temp_var_for_ext_7;
    float temp_var_for_const_6;
    float temp_var_for_callexp_2;

    temp_var_for_callexp_2 = __ieee754_truncf(x);
    temp_var_for_ext_7 = temp_var_for_callexp_2;
    AssignF({(Addr)&temp_var_for_ext_7},
            (Addr) &(temp_var_for_const_6 = temp_var_for_callexp_2),
            "/home/shijia/Public/testprogram/s_rintf.c_e.c:103:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_7;
  }
  }
  /* case FE_TONEAREST: */
  float temp_var_for_ext_8;
  float temp_var_for_const_7;
  float temp_var_for_callexp_3;

  temp_var_for_callexp_3 = __ieee754_roundevenf(x);
  temp_var_for_ext_8 = temp_var_for_callexp_3;
  AssignF({(Addr)&temp_var_for_ext_8},
          (Addr) &(temp_var_for_const_7 = temp_var_for_callexp_3),
          "/home/shijia/Public/testprogram/s_rintf.c_e.c:111:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_8;
}

#endif

float __rintf(float x) {
  float temp_var_for_ext_9;
  float temp_var_for_const_8;
  float temp_var_for_callexp_4;

  temp_var_for_callexp_4 = __ieee754_rintf(x);
  temp_var_for_ext_9 = temp_var_for_callexp_4;
  AssignF({(Addr)&temp_var_for_ext_9},
          (Addr) &(temp_var_for_const_8 = temp_var_for_callexp_4),
          "/home/shijia/Public/testprogram/s_rintf.c_e.c:121:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_9;
}

__typeof(__rintf) rintf __attribute__((weak, alias("__rintf")));
