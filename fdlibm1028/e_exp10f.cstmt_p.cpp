#include "../ScDebug/scdebug.h"
#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_exp10

float __ieee754_exp10f(float arg) {
  /* The argument to exp needs to be calculated in enough precision
     that the fractional part has as much precision as float, in
     addition to the bits in the integer part; using double ensures
     this.  */
  return (float)__ieee754_exp(M_LN10 * (double)arg);
}

#endif

float __exp10f(float x) {
  float z = __ieee754_exp10f(x);

  if (!isfinite(z) && isfinite(x) && _LIB_VERSION != _IEEE_)
    /* exp10 overflow (46) if x > 0, underflow (47) if x < 0.  */
    return __kernel_standard_f(x, x, z, signbit(x) ? KMATHERRF_EXP10_UNDERFLOW
                                                   : KMATHERRF_EXP10_OVERFLOW);

  float temp_var_for_ext_0;
  temp_var_for_ext_0 = z;
  AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&z,
          "/home/shijia/Public/testprogram/e_exp10f.c_e.c:26:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

__typeof(__exp10f) exp10f __attribute__((weak, alias("__exp10f")));
__typeof(__exp10f) __pow10f __attribute__((alias("__exp10f")));
__typeof(__pow10f) pow10f __attribute__((weak, alias("__pow10f")));
