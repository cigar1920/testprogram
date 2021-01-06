#include "../ScDebug/scdebug.h"
#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

#ifndef __have_fpu_scalbn

long double __ieee754_scalbnl(long double x, int n) {
  int32_t k, es, hx, lx;

  static const long double two64 = 1.8446744073709551616e19L;
  static const long double twom64 = 5.421010862427522170037e-20L;
  static const long double hugeval = 1.0e+4900L;
  static const long double tiny = 1.0e-4900L;

  long double temp_var_for_const_0;
  ew_u.value = x;
  AssignLd({(Addr) &(temp_var_for_const_0 = ew_u.value)}, (Addr)&x,
           "/home/shijia/Public/testprogram/s_scalbnl.c_e.c:17:3 "
           "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
  ;
  k = es & IEEE854_LONG_DOUBLE_MAXEXP; /* extract exponent */
  if (k == 0) {                        /* 0 or subnormal x */
    if ((lx | (hx & UC(0x7fffffff))) == 0) {
      long double temp_var_for_ext_0;
      temp_var_for_ext_0 = x;
      AssignLd({(Addr)&temp_var_for_ext_0}, (Addr)&x,
               "/home/shijia/Public/testprogram/s_scalbnl.c_e.c:22:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_0;
    }
    /* +-0 */
    x *= two64;
    ;
    long double temp_var_for_const_1;
    ge_u.value = x;
    AssignLd({(Addr) &(temp_var_for_const_1 = ge_u.value)}, (Addr)&x,
             "/home/shijia/Public/testprogram/s_scalbnl.c_e.c:30:5 "
             "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:258:14>");
    ;
    k = (hx & IEEE854_LONG_DOUBLE_MAXEXP) - 64;
  }
  if (k == IEEE854_LONG_DOUBLE_MAXEXP) {
    long double temp_var_for_ext_1;
    long double temp_var_for_tac_1;
    temp_var_for_tac_1 = x + x;

    temp_var_for_ext_1 = temp_var_for_tac_1;
    computeLdAdd((Addr)&temp_var_for_tac_1, {(Addr)&x, (Addr)&x},
                 "/home/shijia/Public/testprogram/s_scalbnl.c_e.c:35:28");
    AssignLd({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_1,
             "/home/shijia/Public/testprogram/s_scalbnl.c_e.c:35:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }
  /* NaN or Inf */
  if ((int32_t)n < IC(-30000)) {
    long double temp_var_for_ext_2;
    long double temp_var_for_tac_2;
    long double temp_var_for_const_2, temp_var_for_const_3;
    long double temp_var_for_callexp_0;

    temp_var_for_callexp_0 = copysignl(tiny, x);
    temp_var_for_tac_2 = tiny * temp_var_for_callexp_0;

    temp_var_for_ext_2 = temp_var_for_tac_2;
    computeLdMul((Addr)&temp_var_for_tac_2,
                 {(Addr) &(temp_var_for_const_3 = tiny),
                  (Addr) &(temp_var_for_const_2 = temp_var_for_callexp_0)},
                 "/home/shijia/Public/testprogram/s_scalbnl.c_e.c:43:31");
    AssignLd({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_2,
             "/home/shijia/Public/testprogram/s_scalbnl.c_e.c:43:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  }

  if ((int32_t)n > IC(30000) || (k + n) > 0x7ffe) {
    long double temp_var_for_ext_3;
    long double temp_var_for_tac_3;
    long double temp_var_for_const_4, temp_var_for_const_5;
    long double temp_var_for_callexp_1;

    temp_var_for_callexp_1 = copysignl(hugeval, x);
    temp_var_for_tac_3 = hugeval * temp_var_for_callexp_1;

    temp_var_for_ext_3 = temp_var_for_tac_3;
    computeLdMul((Addr)&temp_var_for_tac_3,
                 {(Addr) &(temp_var_for_const_5 = hugeval),
                  (Addr) &(temp_var_for_const_4 = temp_var_for_callexp_1)},
                 "/home/shijia/Public/testprogram/s_scalbnl.c_e.c:51:34");
    AssignLd({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_3,
             "/home/shijia/Public/testprogram/s_scalbnl.c_e.c:51:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_3;
  }
  /* overflow  */
  /* Now k and n are bounded we know that k = k+n does not
     overflow.  */
  k = k + n;
  if (k > 0) /* normal result */
  {
    long double temp_var_for_ext_4;
    temp_var_for_ext_4;
    long double temp_var_for_ext_5;
    temp_var_for_ext_5 = x;
    AssignLd({(Addr)&temp_var_for_ext_5}, (Addr)&x,
             "/home/shijia/Public/testprogram/s_scalbnl.c_e.c:65:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_5;
  }
  if (k <= -64) {
    long double temp_var_for_ext_6;
    long double temp_var_for_tac_4;
    long double temp_var_for_const_6, temp_var_for_const_7;
    long double temp_var_for_callexp_2;

    temp_var_for_callexp_2 = copysignl(tiny, x);
    temp_var_for_tac_4 = tiny * temp_var_for_callexp_2;

    temp_var_for_ext_6 = temp_var_for_tac_4;
    computeLdMul((Addr)&temp_var_for_tac_4,
                 {(Addr) &(temp_var_for_const_7 = tiny),
                  (Addr) &(temp_var_for_const_6 = temp_var_for_callexp_2)},
                 "/home/shijia/Public/testprogram/s_scalbnl.c_e.c:72:31");
    AssignLd({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_4,
             "/home/shijia/Public/testprogram/s_scalbnl.c_e.c:72:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_6;
  }
  /*underflow */
  k += 64; /* subnormal result */
  long double temp_var_for_ext_7;
  temp_var_for_ext_7;
  long double temp_var_for_ext_8;
  long double temp_var_for_tac_5;
  long double temp_var_for_const_8;
  temp_var_for_tac_5 = x * twom64;

  temp_var_for_ext_8 = temp_var_for_tac_5;
  computeLdMul((Addr)&temp_var_for_tac_5,
               {(Addr)&x, (Addr) &(temp_var_for_const_8 = twom64)},
               "/home/shijia/Public/testprogram/s_scalbnl.c_e.c:82:26");
  AssignLd({(Addr)&temp_var_for_ext_8}, (Addr)&temp_var_for_tac_5,
           "/home/shijia/Public/testprogram/s_scalbnl.c_e.c:82:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_8;
}

#endif

long double __scalbnl(long double x, int n) {
  long double temp_var_for_ext_9;
  long double temp_var_for_const_9;
  long double temp_var_for_callexp_3;

  temp_var_for_callexp_3 = __ieee754_scalbnl(x, n);
  temp_var_for_ext_9 = temp_var_for_callexp_3;
  AssignLd({(Addr)&temp_var_for_ext_9},
           (Addr) &(temp_var_for_const_9 = temp_var_for_callexp_3),
           "/home/shijia/Public/testprogram/s_scalbnl.c_e.c:92:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_9;
}

__typeof(__scalbnl) scalbnl __attribute__((weak, alias("__scalbnl")));

#if INT_MAX == LONG_MAX
long double __scalblnl(long double x, long n)
    __attribute__((alias("__scalbnl")));
long double scalblnl(long double x, long n)
    __attribute__((weak, alias("__scalblnl")));
#ifndef __have_fpu_scalbn
long double __ieee754_scalblnl(long double x, long n)
    __attribute__((alias("__ieee754_scalbnl")));
#endif
#endif

#endif
