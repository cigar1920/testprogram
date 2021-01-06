#include "../ScDebug/scdebug.h"
#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

float __significandf(float x) {
  uint32_t hx, ix;

  GET_FLOAT_WORD(hx, x);
  ix = hx & UC(0x7f800000);
  if (ix != 0 && ix != UC(0x7f800000)) {
    SET_FLOAT_WORD(x, (hx & UC(0x807fffff)) | UC(0x3f800000));
  }
  float temp_var_for_ext_0;
  temp_var_for_ext_0 = x;
  AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&x,
          "/home/shijia/Public/testprogram/s_significandf.c_e.c:14:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

__typeof(__significandf) significandf
    __attribute__((weak, alias("__significandf")));
