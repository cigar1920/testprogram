#include "../ScDebug/scdebug.h"
#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

float __fminf(float x, float y) {
  float temp_var_for_ext_0;
  temp_var_for_ext_0 = (islessequal(x, y) || isnan(y)) ? x : y;
  float temp_var_for_const_0;
  AssignF(
      {(Addr)&temp_var_for_ext_0},
      (Addr) &(temp_var_for_const_0 = (islessequal(x, y) || isnan(y)) ? x : y),
      "/home/shijia/Public/testprogram/s_fminf.c_e.c:7:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

__typeof(__fminf) fminf __attribute__((weak, alias("__fminf")));
