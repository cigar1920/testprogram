#include "../ScDebug/scdebug.h"
#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

#ifndef __have_fpu_acos

long double __ieee754_acosl(long double x) {
  long double y;

  if (x == 0.0)
    return M_PI_2l;
  if (x == 1.0) {
    long double temp_var_for_ext_0;
    temp_var_for_ext_0 = 0.0;
    long double temp_var_for_const_0;
    AssignLd({(Addr)&temp_var_for_ext_0}, (Addr) &(temp_var_for_const_0 = 0.0),
             "/home/shijia/Public/testprogram/e_acosl.c_e.c:16:24");
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  if (x == -1.0)
    return M_PIl;
  y = __ieee754_atanl(__ieee754_sqrtl(1.0L - (x * x)) / x);
  long double temp_var_for_const_1, temp_var_for_const_2, temp_var_for_const_3;
  long double temp_var_for_tac_0, temp_var_for_tac_1, temp_var_for_tac_2;
  computeLdSub(
      (Addr)&temp_var_for_tac_1,
      {(Addr) &(temp_var_for_const_1 = 1.0L), (Addr)&temp_var_for_tac_0},
      "toString(biExpr->getExprLoc())");
computeLdDiv((Addr)&temp_var_for_tac_2,{(Addr)&(temp_var_for_const_2=__ieee754_sqrtl(getFVbyShadow<int>((Addr)&temp_var_for_tac_1)),(Addr)&x},"toString(biExpr->getExprLoc())");
computeLdMul((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&x},
             "/home/shijia/Public/testprogram/e_acosl.c_e.c:24:44");AssignLd({(Addr)&y},(Addr)&(temp_var_for_const_3=__ieee754_atanl(getFVbyShadow<int>((Addr)&temp_var_for_tac_2)),"/home/shijia/Public/testprogram/e_acosl.c_e.c:24:5");
  if (x > 0.0) {
    long double temp_var_for_ext_1;
    temp_var_for_ext_1 = y;
    AssignLd({(Addr)&temp_var_for_ext_1}, (Addr)&y,
             "/home/shijia/Public/testprogram/e_acosl.c_e.c:27:24");
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }

  return y + M_PIl;
}

#endif

/* wrapper acosl */
long double __acosl(long double x) {
  if (isgreater(__ieee754_fabsl(x), 1.0L) && _LIB_VERSION != _IEEE_) {
    /* acos(|x|>1) */
    feraiseexcept(FE_INVALID);
    return __kernel_standard_l(x, x, __builtin_nanl(""), KMATHERRL_ACOS);
  }

  long double temp_var_for_ext_2;
  temp_var_for_ext_2 = __ieee754_acosl(x);
  long double temp_var_for_callexp_0 =
      __ieee754_acosl(getFVbyShadow<long double>((Addr)&x));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  AssignLd({(Addr)&temp_var_for_ext_2}, ,
           "/home/shijia/Public/testprogram/e_acosl.c_e.c:47:22");
  callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_2;
}

__typeof(__acosl) acosl __attribute__((weak, alias("__acosl")));

#endif
