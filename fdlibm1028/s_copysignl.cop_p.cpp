#include "../ScDebug/scdebug.h"
#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

long double __copysignl(long double x, long double y) {
  uint32_t es1, es2;
  long double temp_var_for_const_0;
  ge_u.value = x;
  AssignLd({(Addr) &(temp_var_for_const_0 = ge_u.value)}, (Addr)&x,
           "/home/shijia/Public/testprogram/s_copysignl.c_e.c:9:3 "
           "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:258:14>");
  ;
  long double temp_var_for_const_1;
  ge_u.value = y;
  AssignLd({(Addr) &(temp_var_for_const_1 = ge_u.value)}, (Addr)&y,
           "/home/shijia/Public/testprogram/s_copysignl.c_e.c:10:3 "
           "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:258:14>");
  ;
  long double temp_var_for_ext_0;
  temp_var_for_ext_0;
  long double temp_var_for_ext_1;
  temp_var_for_ext_1 = x;
  AssignLd({(Addr)&temp_var_for_ext_1}, (Addr)&x,
           "/home/shijia/Public/testprogram/s_copysignl.c_e.c:14:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

__typeof(__copysignl) copysignl __attribute__((weak, alias("__copysignl")));

#endif
