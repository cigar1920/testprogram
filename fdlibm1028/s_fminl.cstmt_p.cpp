#include "../ScDebug/scdebug.h"
#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

long double __fminl(long double x, long double y) {
  long double temp_var_for_ext_0;
  temp_var_for_ext_0 = (islessequal(x, y) || isnan(y)) ? x : y;
  long double temp_var_for_const_0;
  AssignLd(
      {(Addr)&temp_var_for_ext_0},
      (Addr) &(temp_var_for_const_0 = (islessequal(x, y) || isnan(y)) ? x : y),
      "/home/shijia/Public/testprogram/s_fminl.c_e.c:9:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

__typeof(__fminl) fminl __attribute__((weak, alias("__fminl")));

#endif
