#include "../ScDebug/scdebug.h"
#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

#ifndef __have_fpu_exp10

long double __ieee754_exp10l(long double arg) {
  if (isfinite(arg) && arg < LDBL_MIN_10_EXP - LDBL_DIG - 10) {
    feraiseexcept(FE_UNDERFLOW);
    return 0;
  }
  /* This is a very stupid and inprecise implementation.  It'll get
     replaced sometime (soon?).  */
  long double temp_var_for_ext_0;
  long double temp_var_for_tac_0;
  long double temp_var_for_const_0, temp_var_for_const_1;
  long double temp_var_for_callexp_0;

  temp_var_for_tac_0 = M_LN10l * arg;

  temp_var_for_callexp_0 = __ieee754_expl(temp_var_for_tac_0);
  temp_var_for_ext_0 = temp_var_for_callexp_0;
  computeLdMul((Addr)&temp_var_for_tac_0,
               {(Addr) &(temp_var_for_const_0 = M_LN10l), (Addr)&arg},
               "/home/shijia/Public/testprogram/e_exp10l.c_e.c:17:47");
  AssignLd({(Addr)&temp_var_for_ext_0},
           (Addr) &(temp_var_for_const_1 = temp_var_for_callexp_0),
           "/home/shijia/Public/testprogram/e_exp10l.c_e.c:17:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

#endif

long double __exp10l(long double x) {
  long double z = __ieee754_exp10l(x);

  if (!isfinite(z) && isfinite(x) && _LIB_VERSION != _IEEE_)
  /* exp10 overflow (46) if x > 0, underflow (47) if x < 0.  */
  {
    long double temp_var_for_ext_1;
    long double temp_var_for_const_2;
    long double temp_var_for_callexp_1;

    temp_var_for_callexp_1 =
        __kernel_standard_l(x, x, z, signbit(x) ? KMATHERRL_EXP10_UNDERFLOW
                                                : KMATHERRL_EXP10_OVERFLOW);
    temp_var_for_ext_1 = temp_var_for_callexp_1;
    AssignLd({(Addr)&temp_var_for_ext_1},
             (Addr) &(temp_var_for_const_2 = temp_var_for_callexp_1),
             "/home/shijia/Public/testprogram/e_exp10l.c_e.c:32:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }

  long double temp_var_for_ext_2;
  temp_var_for_ext_2 = z;
  callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_2;
}

__typeof(__exp10l) exp10l __attribute__((weak, alias("__exp10l")));
__typeof(__exp10l) __pow10l __attribute__((alias("__exp10l")));
__typeof(__pow10l) pow10l __attribute__((weak, alias("__pow10l")));

#endif
