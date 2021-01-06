#include "../ScDebug/scdebug.h"
#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

long double __significandl(long double x) {
  uint32_t exp, ix;

  GET_LDOUBLE_EXP(exp, x);
  ix = exp & 0x7fff;
  if (ix != 0 && ix != 0x7fff)
    SET_LDOUBLE_EXP(x, (exp & 0x8000) | 0x3fff);
  long double temp_var_for_ext_0;
  temp_var_for_ext_0 = x;
  AssignLd({(Addr)&temp_var_for_ext_0}, (Addr)&x,
           "/home/shijia/Public/testprogram/s_significandl.c_e.c:15:22");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

__typeof(__significandl) significandl
    __attribute__((weak, alias("__significandl")));

#endif
