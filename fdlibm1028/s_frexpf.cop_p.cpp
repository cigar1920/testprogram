#include "../ScDebug/scdebug.h"
#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_frexp

float __ieee754_frexpf(float x, int *eptr) {
  int32_t hx, ix;
  static const float two25 = 3.3554432000e+07; /* 0x4c000000 */

  GET_FLOAT_WORD(hx, x);
  ix = UC(0x7fffffff) & hx;
  *eptr = 0;
  if (!FLT_UWORD_IS_FINITE(ix) || FLT_UWORD_IS_ZERO(ix)) {
    float temp_var_for_ext_0;
    temp_var_for_ext_0 = x;
    AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&x,
            "/home/shijia/Public/testprogram/s_frexpf.c_e.c:16:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }
  /* 0,inf,nan */
  if (FLT_UWORD_IS_SUBNORMAL(ix)) { /* subnormal */
    x *= two25;
    ;
    GET_FLOAT_WORD(hx, x);
    ix = hx & UC(0x7fffffff);
    *eptr = -25;
  }
  *eptr += (int)(ix >> 23) - 126;
  hx = (hx & UC(0x807fffff)) | UC(0x3f000000);
  SET_FLOAT_WORD(x, hx);
  float temp_var_for_ext_1;
  temp_var_for_ext_1 = x;
  AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&x,
          "/home/shijia/Public/testprogram/s_frexpf.c_e.c:32:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

#endif

float __frexpf(float x, int *exp) {
  float temp_var_for_ext_2;
  float temp_var_for_const_0;
  float temp_var_for_callexp_0;

  temp_var_for_callexp_0 = __ieee754_frexpf(x, exp);
  temp_var_for_ext_2 = temp_var_for_callexp_0;
  AssignF({(Addr)&temp_var_for_ext_2},
          (Addr) &(temp_var_for_const_0 = temp_var_for_callexp_0),
          "/home/shijia/Public/testprogram/s_frexpf.c_e.c:42:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_2;
}

__typeof(__frexpf) frexpf __attribute__((weak, alias("__frexpf")));
