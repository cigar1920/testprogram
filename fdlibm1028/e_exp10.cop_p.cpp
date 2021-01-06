#include "../ScDebug/scdebug.h"
#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_exp10

double __ieee754_exp10(double arg) {
  if (isfinite(arg) && arg < DBL_MIN_10_EXP - DBL_DIG - 10) {
    feraiseexcept(FE_UNDERFLOW);
    return 0;
  }
  /* This is a very stupid and inprecise implementation.  It'll get
     replaced sometime (soon?).  */
  double temp_var_for_ext_0;
  double temp_var_for_tac_0;
  double temp_var_for_const_0, temp_var_for_const_1;
  double temp_var_for_callexp_0;

  temp_var_for_tac_0 = M_LN10 * arg;

  temp_var_for_callexp_0 = __ieee754_exp(temp_var_for_tac_0);
  temp_var_for_ext_0 = temp_var_for_callexp_0;
  computeDMul((Addr)&temp_var_for_tac_0,
              {(Addr) &(temp_var_for_const_0 = M_LN10), (Addr)&arg},
              "/home/shijia/Public/testprogram/e_exp10.c_e.c:15:45");
  AssignD({(Addr)&temp_var_for_ext_0},
          (Addr) &(temp_var_for_const_1 = temp_var_for_callexp_0),
          "/home/shijia/Public/testprogram/e_exp10.c_e.c:15:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

#endif

double __exp10(double x) {
  double z = __ieee754_exp10(x);

  if (!isfinite(z) && isfinite(x) && _LIB_VERSION != _IEEE_)
  /* exp10 overflow (46) if x > 0, underflow (47) if x < 0.  */
  {
    double temp_var_for_ext_1;
    double temp_var_for_const_2;
    double temp_var_for_callexp_1;

    temp_var_for_callexp_1 =
        __kernel_standard(x, x, z, signbit(x) ? KMATHERR_EXP10_UNDERFLOW
                                              : KMATHERR_EXP10_OVERFLOW);
    temp_var_for_ext_1 = temp_var_for_callexp_1;
    AssignD({(Addr)&temp_var_for_ext_1},
            (Addr) &(temp_var_for_const_2 = temp_var_for_callexp_1),
            "/home/shijia/Public/testprogram/e_exp10.c_e.c:30:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }

  double temp_var_for_ext_2;
  temp_var_for_ext_2 = z;
  callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_2;
}

__typeof(__exp10) exp10 __attribute__((weak, alias("__exp10")));
__typeof(__exp10) __pow10 __attribute__((alias("__exp10")));
__typeof(__pow10) pow10 __attribute__((weak, alias("__pow10")));
#ifdef __NO_LONG_DOUBLE_MATH
__typeof(__exp10l) __exp10l __attribute__((alias("__exp10")));
__typeof(__exp10l) exp10l __attribute__((weak, alias("__exp10l")));
__typeof(__pow10l) __pow10l __attribute__((alias("__pow10")));
__typeof(__pow10l) pow10l __attribute__((weak, alias("__pow10l")));
#endif
