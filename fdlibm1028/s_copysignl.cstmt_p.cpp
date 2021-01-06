#include "../ScDebug/scdebug.h"
#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

long double __copysignl(long double x, long double y) {
  uint32_t es1, es2;
  GET_LDOUBLE_EXP(es1, x);
  GET_LDOUBLE_EXP(es2, y);
  SET_LDOUBLE_EXP(x, (es1 & 0x7fff) | (es2 & 0x8000));
  long double temp_var_for_ext_0;
  temp_var_for_ext_0 = x;
  AssignLd({(Addr)&temp_var_for_ext_0}, (Addr)&x,
           "/home/shijia/Public/testprogram/s_copysignl.c_e.c:13:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

__typeof(__copysignl) copysignl __attribute__((weak, alias("__copysignl")));

#endif
