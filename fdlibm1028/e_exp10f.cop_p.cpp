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
  float temp_var_for_ext_0;
  float temp_var_for_tac_0;
  float temp_var_for_const_0, temp_var_for_const_1, temp_var_for_const_2;
  temp_var_for_tac_0 = M_LN10 * ((double)arg);

  temp_var_for_callexp_0 = __ieee754_exp(temp_var_for_tac_0);
  temp_var_for_ext_0 = ((float)temp_var_for_callexp_0);
  computeDMul((Addr)&temp_var_for_tac_0,
              {(Addr) &(temp_var_for_const_1 = M_LN10),
               (Addr) &(temp_var_for_const_0 = ((double)arg))},
              "/home/shijia/Public/testprogram/e_exp10f.c_e.c:13:52");
  AssignF({(Addr)&temp_var_for_ext_0},
          (Addr) &(temp_var_for_const_2 = ((float)temp_var_for_callexp_0)),
          "/home/shijia/Public/testprogram/e_exp10f.c_e.c:13:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

#endif

float __exp10f(float x) {
  float z = __ieee754_exp10f(x);

  if (!isfinite(z) && isfinite(x) && _LIB_VERSION != _IEEE_)
  /* exp10 overflow (46) if x > 0, underflow (47) if x < 0.  */
  {
    float temp_var_for_ext_1;
    float temp_var_for_const_3;
    float temp_var_for_callexp_1;

    temp_var_for_callexp_1 =
        __kernel_standard_f(x, x, z, signbit(x) ? KMATHERRF_EXP10_UNDERFLOW
                                                : KMATHERRF_EXP10_OVERFLOW);
    temp_var_for_ext_1 = temp_var_for_callexp_1;
    AssignF({(Addr)&temp_var_for_ext_1},
            (Addr) &(temp_var_for_const_3 = temp_var_for_callexp_1),
            "/home/shijia/Public/testprogram/e_exp10f.c_e.c:28:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }

  float temp_var_for_ext_2;
  temp_var_for_ext_2 = z;
  callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_2;
}

__typeof(__exp10f) exp10f __attribute__((weak, alias("__exp10f")));
__typeof(__exp10f) __pow10f __attribute__((alias("__exp10f")));
__typeof(__pow10f) pow10f __attribute__((weak, alias("__pow10f")));
