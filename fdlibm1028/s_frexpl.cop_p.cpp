#include "../ScDebug/scdebug.h"
#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

#ifndef __have_fpu_frexp

long double __ieee754_frexpl(long double x, int *eptr) {
  static const long double two65 =
      3.68934881474191032320e+19L; /* 0x4040, 0x80000000, 0x00000000 */

  uint32_t se, hx, ix, lx;

  long double temp_var_for_const_0;
  ew_u.value = x;
  AssignLd({(Addr) &(temp_var_for_const_0 = ew_u.value)}, (Addr)&x,
           "/home/shijia/Public/testprogram/s_frexpl.c_e.c:15:3 "
           "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
  ;
  ix = 0x7fff & se;
  *eptr = 0;
  if (ix == 0x7fff || ((ix | hx | lx) == 0)) {
    long double temp_var_for_ext_0;
    temp_var_for_ext_0 = x;
    AssignLd({(Addr)&temp_var_for_ext_0}, (Addr)&x,
             "/home/shijia/Public/testprogram/s_frexpl.c_e.c:20:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }
  /* 0,inf,nan */
  if (ix == 0x0000) { /* subnormal */
    x *= two65;
    ;
    long double temp_var_for_const_1;
    ge_u.value = x;
    AssignLd({(Addr) &(temp_var_for_const_1 = ge_u.value)}, (Addr)&x,
             "/home/shijia/Public/testprogram/s_frexpl.c_e.c:28:5 "
             "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:258:14>");
    ;
    ix = se & 0x7fff;
    *eptr = -65;
  }
  *eptr += (int)(ix - 16382);
  se = (se & 0x8000) | 0x3ffe;
  long double temp_var_for_ext_1;
  temp_var_for_ext_1;
  long double temp_var_for_ext_2;
  temp_var_for_ext_2 = x;
  AssignLd({(Addr)&temp_var_for_ext_2}, (Addr)&x,
           "/home/shijia/Public/testprogram/s_frexpl.c_e.c:37:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_2;
}

#endif

long double __frexpl(long double x, int *exp) {
  long double temp_var_for_ext_3;
  long double temp_var_for_const_2;
  long double temp_var_for_callexp_0;

  temp_var_for_callexp_0 = __ieee754_frexpl(x, exp);
  temp_var_for_ext_3 = temp_var_for_callexp_0;
  AssignLd({(Addr)&temp_var_for_ext_3},
           (Addr) &(temp_var_for_const_2 = temp_var_for_callexp_0),
           "/home/shijia/Public/testprogram/s_frexpl.c_e.c:47:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_3;
}

__typeof(__frexpl) frexpl __attribute__((weak, alias("__frexpl")));

#endif
