#include "../ScDebug/scdebug.h"
#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

float __copysignf(float x, float y) {
  uint32_t ix, iy;

  GET_FLOAT_WORD(ix, x);
  GET_FLOAT_WORD(iy, y);
  SET_FLOAT_WORD(x, (ix & UC(0x7fffffff)) | (iy & UC(0x80000000)));
  float temp_var_for_ext_0;
  temp_var_for_ext_0 = x;
  AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&x,
          "/home/shijia/Public/testprogram/s_copysignf.c_e.c:12:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

__typeof(__copysignf) copysignf __attribute__((weak, alias("__copysignf")));
