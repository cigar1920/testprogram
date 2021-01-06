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
  return __ieee754_expl(M_LN10l * arg);
}

#endif

long double __exp10l(long double x) {
  long double z = __ieee754_exp10l(x);

  if (!isfinite(z) && isfinite(x) && _LIB_VERSION != _IEEE_)
    /* exp10 overflow (46) if x > 0, underflow (47) if x < 0.  */
    return __kernel_standard_l(x, x, z, signbit(x) ? KMATHERRL_EXP10_UNDERFLOW
                                                   : KMATHERRL_EXP10_OVERFLOW);

  long double temp_var_for_ext_0;
  temp_var_for_ext_0 = z;
  AssignLd({(Addr)&temp_var_for_ext_0}, (Addr)&z,
           "/home/shijia/Public/testprogram/e_exp10l.c_e.c:30:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

__typeof(__exp10l) exp10l __attribute__((weak, alias("__exp10l")));
__typeof(__exp10l) __pow10l __attribute__((alias("__exp10l")));
__typeof(__pow10l) pow10l __attribute__((weak, alias("__pow10l")));

#endif
