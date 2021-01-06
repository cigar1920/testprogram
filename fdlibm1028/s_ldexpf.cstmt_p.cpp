#include "../ScDebug/scdebug.h"
#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_ldexp

float __ieee754_ldexpf(float value, int exp) {
  if (!isfinite(value) || value == 0.0F) {
    float temp_var_for_ext_0;
    temp_var_for_ext_0 = value;
    AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&value,
            "/home/shijia/Public/testprogram/s_ldexpf.c_e.c:10:24");
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  float temp_var_for_ext_1;
  temp_var_for_ext_1 = __ieee754_scalbnf(value, exp);
  float temp_var_for_const_0;AssignF({(Addr)&temp_var_for_ext_1},(Addr)&(temp_var_for_const_0=__ieee754_scalbnf(getFVbyShadow<int>((Addr)&value), (exp)),"/home/shijia/Public/testprogram/s_ldexpf.c_e.c:17:22");
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

#endif

float __ldexpf(float x, int n) {
  x = __ieee754_ldexpf(x, n);
  float temp_var_for_callexp_0 =
      __ieee754_ldexpf(getFVbyShadow<float>((Addr)&x), (n));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  AssignF({(Addr)&x}, , "/home/shijia/Public/testprogram/s_ldexpf.c_e.c:26:5");
  if (!isfinite(x) || x == 0.0F)
    __set_errno(ERANGE);
  float temp_var_for_ext_2;
  temp_var_for_ext_2 = x;
  AssignF({(Addr)&temp_var_for_ext_2}, (Addr)&x,
          "/home/shijia/Public/testprogram/s_ldexpf.c_e.c:30:22");
  callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_2;
}

__typeof(__ldexpf) ldexpf __attribute__((weak, alias("__ldexpf")));
