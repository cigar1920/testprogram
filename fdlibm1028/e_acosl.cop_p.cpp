#include "../ScDebug/scdebug.h"
#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

#ifndef __have_fpu_acos

long double __ieee754_acosl(long double x) {
  long double y;

  if (int temp_var_for_tac_0; int temp_var_for_const_0;
      temp_var_for_tac_0 = x == 0.0;

      ) {
    long double temp_var_for_ext_0;
    long double temp_var_for_const_1;
    temp_var_for_ext_0 = M_PI_2l;
    compute((Addr)&temp_var_for_tac_0,
            {(Addr)&x, (Addr) &(temp_var_for_const_0 = 0.0)},
            "/home/shijia/Public/testprogram/e_acosl.c_e.c:12:9");
    AssignLd({(Addr)&temp_var_for_ext_0},
             (Addr) &(temp_var_for_const_1 = M_PI_2l),
             "/home/shijia/Public/testprogram/e_acosl.c_e.c:14:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  if (int temp_var_for_tac_1; int temp_var_for_const_2;
      temp_var_for_tac_1 = x == 1.0;

      ) {
    long double temp_var_for_ext_1;
    long double temp_var_for_const_3;
    temp_var_for_ext_1 = 0.0;
    compute((Addr)&temp_var_for_tac_1,
            {(Addr)&x, (Addr) &(temp_var_for_const_2 = 1.0)},
            "/home/shijia/Public/testprogram/e_acosl.c_e.c:20:9");
    AssignLd({(Addr)&temp_var_for_ext_1}, (Addr) &(temp_var_for_const_3 = 0.0),
             "/home/shijia/Public/testprogram/e_acosl.c_e.c:22:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }

  if (int temp_var_for_tac_2, temp_var_for_tac_3;
      int temp_var_for_const_4, temp_var_for_const_5;
      temp_var_for_tac_2 = 0.0 - 1.0;

      temp_var_for_tac_3 = x == temp_var_for_tac_2;

      ) {
    long double temp_var_for_ext_2;
    long double temp_var_for_const_6;
    temp_var_for_ext_2 = M_PIl;
    computeDSub((Addr)&temp_var_for_tac_2,
                {(Addr) &(temp_var_for_const_5 = 0.0),
                 (Addr) &(temp_var_for_const_4 = 1.0)},
                "/home/shijia/Public/testprogram/e_acosl.c_e.c:28:17");
    compute((Addr)&temp_var_for_tac_3, {(Addr)&x, (Addr)&temp_var_for_tac_2},
            "/home/shijia/Public/testprogram/e_acosl.c_e.c:28:9");
    AssignLd({(Addr)&temp_var_for_ext_2},
             (Addr) &(temp_var_for_const_6 = M_PIl),
             "/home/shijia/Public/testprogram/e_acosl.c_e.c:30:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  }

  long double temp_var_for_tac_4, temp_var_for_tac_5, temp_var_for_tac_6;
  long double temp_var_for_const_7, temp_var_for_const_8, temp_var_for_const_9;
  long double temp_var_for_callexp_0;

  long double temp_var_for_callexp_1;

  temp_var_for_tac_4 = x * x;

  temp_var_for_tac_5 = 1.0L - temp_var_for_tac_4;

  temp_var_for_callexp_0 = __ieee754_sqrtl(temp_var_for_tac_5);
  temp_var_for_tac_6 = temp_var_for_callexp_0 / x;

  temp_var_for_callexp_1 = __ieee754_atanl(temp_var_for_tac_6);
  y = temp_var_for_callexp_1;
  computeLdMul((Addr)&temp_var_for_tac_4, {(Addr)&x, (Addr)&x},
               "/home/shijia/Public/testprogram/e_acosl.c_e.c:36:49");
  computeLdSub(
      (Addr)&temp_var_for_tac_5,
      {(Addr) &(temp_var_for_const_7 = 1.0L), (Addr)&temp_var_for_tac_4},
      "/home/shijia/Public/testprogram/e_acosl.c_e.c:36:44");
  computeLdDiv(
      (Addr)&temp_var_for_tac_6,
      {(Addr) &(temp_var_for_const_8 = temp_var_for_callexp_0), (Addr)&x},
      "/home/shijia/Public/testprogram/e_acosl.c_e.c:36:55");
  AssignLd({(Addr)&y}, (Addr) &(temp_var_for_const_9 = temp_var_for_callexp_1),
           "/home/shijia/Public/testprogram/e_acosl.c_e.c:36:5");
  ;
  if (int temp_var_for_tac_7; int temp_var_for_const_10;
      temp_var_for_tac_7 = x > 0.0;

      ) {
    long double temp_var_for_ext_3;
    temp_var_for_ext_3 = y;
    compute((Addr)&temp_var_for_tac_7,
            {(Addr)&x, (Addr) &(temp_var_for_const_10 = 0.0)},
            "/home/shijia/Public/testprogram/e_acosl.c_e.c:37:9");
    AssignLd({(Addr)&temp_var_for_ext_3}, (Addr)&y,
             "/home/shijia/Public/testprogram/e_acosl.c_e.c:39:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_3;
  }

  long double temp_var_for_ext_4;
  long double temp_var_for_tac_8;
  long double temp_var_for_const_11;
  temp_var_for_tac_8 = y + M_PIl;

  temp_var_for_ext_4 = temp_var_for_tac_8;
  computeLdAdd((Addr)&temp_var_for_tac_8,
               {(Addr)&y, (Addr) &(temp_var_for_const_11 = M_PIl)},
               "/home/shijia/Public/testprogram/e_acosl.c_e.c:46:26");
  AssignLd({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_8,
           "/home/shijia/Public/testprogram/e_acosl.c_e.c:46:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_4;
}

#endif

/* wrapper acosl */
long double __acosl(long double x) {
  if (isgreater(__ieee754_fabsl(x), 1.0L) && _LIB_VERSION != _IEEE_) {
    /* acos(|x|>1) */
    feraiseexcept(FE_INVALID);
    long double temp_var_for_ext_5;
    long double temp_var_for_const_12;
    long double temp_var_for_callexp_2;

    /*embed fun has found*/
    long double temp_var_for_callexp_3;

    temp_var_for_callexp_2 = __builtin_nanl("");
    temp_var_for_callexp_3 =
        __kernel_standard_l(x, x, temp_var_for_callexp_2, KMATHERRL_ACOS);
    temp_var_for_ext_5 = temp_var_for_callexp_3;
    AssignLd({(Addr)&temp_var_for_ext_5},
             (Addr) &(temp_var_for_const_12 = temp_var_for_callexp_3),
             "/home/shijia/Public/testprogram/e_acosl.c_e.c:60:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_5;
  }

  long double temp_var_for_ext_6;
  long double temp_var_for_const_13;
  long double temp_var_for_callexp_4;

  temp_var_for_callexp_4 = __ieee754_acosl(x);
  temp_var_for_ext_6 = temp_var_for_callexp_4;
  AssignLd({(Addr)&temp_var_for_ext_6},
           (Addr) &(temp_var_for_const_13 = temp_var_for_callexp_4),
           "/home/shijia/Public/testprogram/e_acosl.c_e.c:68:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_6;
}

__typeof(__acosl) acosl __attribute__((weak, alias("__acosl")));

#endif
