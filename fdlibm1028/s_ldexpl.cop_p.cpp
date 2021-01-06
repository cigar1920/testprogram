#include "../ScDebug/scdebug.h"
#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

#ifndef __have_fpu_ldexp

long double __ieee754_ldexpl(long double value, int exp) {
  if (!isfinite(value) || int temp_var_for_tac_0; int temp_var_for_const_0;
      temp_var_for_tac_0 = value == 0.0;

      ) {
    long double temp_var_for_ext_0;
    temp_var_for_ext_0 = value;
    compute((Addr)&temp_var_for_tac_0,
            {(Addr)&value, (Addr) &(temp_var_for_const_0 = 0.0)},
            "/home/shijia/Public/testprogram/s_ldexpl.c_e.c:10:33");
    AssignLd({(Addr)&temp_var_for_ext_0}, (Addr)&value,
             "/home/shijia/Public/testprogram/s_ldexpl.c_e.c:12:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  long double temp_var_for_ext_1;
  long double temp_var_for_const_1;
  long double temp_var_for_callexp_0;

  temp_var_for_callexp_0 = __ieee754_scalbnl(value, exp);
  temp_var_for_ext_1 = temp_var_for_callexp_0;
  AssignLd({(Addr)&temp_var_for_ext_1},
           (Addr) &(temp_var_for_const_1 = temp_var_for_callexp_0),
           "/home/shijia/Public/testprogram/s_ldexpl.c_e.c:19:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

#endif

long double __ldexpl(long double x, int n) {
  long double temp_var_for_const_2;
  long double temp_var_for_callexp_1;

  temp_var_for_callexp_1 = __ieee754_ldexpl(x, n);
  x = temp_var_for_callexp_1;
  AssignLd({(Addr)&x}, (Addr) &(temp_var_for_const_2 = temp_var_for_callexp_1),
           "/home/shijia/Public/testprogram/s_ldexpl.c_e.c:28:5");
  ;
  if (!isfinite(x) || int temp_var_for_tac_1; int temp_var_for_const_3;
      temp_var_for_tac_1 = x == 0.0;

      ) {
    __set_errno(ERANGE);
  }

  long double temp_var_for_ext_2;
  temp_var_for_ext_2 = x;
  compute((Addr)&temp_var_for_tac_1,
          {(Addr)&x, (Addr) &(temp_var_for_const_3 = 0.0)},
          "/home/shijia/Public/testprogram/s_ldexpl.c_e.c:29:25");
  AssignLd({(Addr)&temp_var_for_ext_2}, (Addr)&x,
           "/home/shijia/Public/testprogram/s_ldexpl.c_e.c:34:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_2;
}

__typeof(__ldexpl) ldexpl __attribute__((weak, alias("__ldexpl")));

#endif
