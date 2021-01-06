#include "../ScDebug/scdebug.h"
#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

#ifndef __have_fpu_exp

long double __ieee754_expl(long double x) /* default IEEE double exp */
{
  int sign;
  int32_t ex;
  uint32_t hx, lx;
  int intx;
  long double fractx;

  /* Smallest integer x for which e^x overflows.  */
  static const double o_threshold =
      1.1356523406294143949491931077970764891253E4L;
  /* Largest integer x for which e^x underflows.  */
  static const long double u_threshold =
      (long double temp_var_for_tac_0;
       long double temp_var_for_const_0, temp_var_for_const_1;
       temp_var_for_tac_0 = 0.0 - 11355.137111933024058885L;

       );
  static const long double log2e = 1.44269504088896340735992468100189213743L;

  long double temp_var_for_const_2;
  ew_u.value = x;
  computeLdSub((Addr)&temp_var_for_tac_0,
               {(Addr) &(temp_var_for_const_1 = 0.0),
                (Addr) &(temp_var_for_const_0 = 11355.137111933024058885L)},
               "/home/shijia/Public/testprogram/e_expl.c_e.c:21:47");
  AssignLd({(Addr) &(temp_var_for_const_2 = ew_u.value)}, (Addr)&x,
           "/home/shijia/Public/testprogram/e_expl.c_e.c:24:3 "
           "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
  ;
  sign = (int)ex & 0x8000; /* sign bit of x */
  ex &= 0x7fff;
  hx &= IC(0x7fffffff);
  /* filter out non-finite argument */
  if (ex >= 0x7fff) {
    if ((hx | lx) != 0) {
      long double temp_var_for_ext_0;
      temp_var_for_ext_0 = x;
      AssignLd({(Addr)&temp_var_for_ext_0}, (Addr)&x,
               "/home/shijia/Public/testprogram/e_expl.c_e.c:32:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_0;
    }
    /* NaN */
    long double temp_var_for_ext_1;
    long double temp_var_for_const_3;
    temp_var_for_ext_1 = sign ? 0.0 : x;
    AssignLd({(Addr)&temp_var_for_ext_1},
             (Addr) &(temp_var_for_const_3 = sign ? 0.0 : x),
             "/home/shijia/Public/testprogram/e_expl.c_e.c:40:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++;                 /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1; /* exp(+-inf)={inf,0} */
  }
  if (int temp_var_for_tac_1; int temp_var_for_const_4;
      temp_var_for_tac_1 = x > o_threshold;

      ) /* overflow */
  {
    feraiseexcept(FE_OVERFLOW);
    long double temp_var_for_ext_2;
    long double temp_var_for_const_5;
    long double temp_var_for_callexp_0;

    temp_var_for_callexp_0 = __builtin_huge_vall();
    temp_var_for_ext_2 = temp_var_for_callexp_0;
    compute((Addr)&temp_var_for_tac_1,
            {(Addr)&x, (Addr) &(temp_var_for_const_4 = o_threshold)},
            "/home/shijia/Public/testprogram/e_expl.c_e.c:45:9");
    AssignLd({(Addr)&temp_var_for_ext_2},
             (Addr) &(temp_var_for_const_5 = temp_var_for_callexp_0),
             "/home/shijia/Public/testprogram/e_expl.c_e.c:49:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  }
  if (int temp_var_for_tac_2; int temp_var_for_const_6;
      temp_var_for_tac_2 = x < u_threshold;

      ) /* underflow */
  {
    feraiseexcept(FE_UNDERFLOW);
    long double temp_var_for_ext_3;
    long double temp_var_for_const_7;
    temp_var_for_ext_3 = 0;
    compute((Addr)&temp_var_for_tac_2,
            {(Addr)&x, (Addr) &(temp_var_for_const_6 = u_threshold)},
            "/home/shijia/Public/testprogram/e_expl.c_e.c:54:9");
    AssignLd({(Addr)&temp_var_for_ext_3}, (Addr) &(temp_var_for_const_7 = 0),
             "/home/shijia/Public/testprogram/e_expl.c_e.c:58:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_3;
  }
  x *= log2e;
  ;
  intx = (int)x;
  long double temp_var_for_tac_4;
  long double temp_var_for_const_8;
  temp_var_for_tac_4 = x - intx;

  fractx = temp_var_for_tac_4;
  computeLdSub((Addr)&temp_var_for_tac_4,
               {(Addr)&x, (Addr) &(temp_var_for_const_8 = intx)},
               "/home/shijia/Public/testprogram/e_expl.c_e.c:65:14");
  AssignLd({(Addr)&fractx}, (Addr)&temp_var_for_tac_4,
           "/home/shijia/Public/testprogram/e_expl.c_e.c:65:10");
  ;
  long double temp_var_for_ext_4;
  long double temp_var_for_tac_5, temp_var_for_tac_6;
  long double temp_var_for_const_9, temp_var_for_const_10,
      temp_var_for_const_11, temp_var_for_const_12;
  long double temp_var_for_callexp_1;

  long double temp_var_for_callexp_2;

  temp_var_for_tac_5 = M_LN2l * fractx;

  temp_var_for_callexp_1 = __ieee754_expm1l(temp_var_for_tac_5);
  temp_var_for_tac_6 = temp_var_for_callexp_1 + 1.0L;

  temp_var_for_callexp_2 = __ieee754_scalbnl(temp_var_for_tac_6, intx);
  temp_var_for_ext_4 = temp_var_for_callexp_2;
  computeLdMul((Addr)&temp_var_for_tac_5,
               {(Addr) &(temp_var_for_const_9 = M_LN2l), (Addr)&fractx},
               "/home/shijia/Public/testprogram/e_expl.c_e.c:68:49");
  computeLdAdd((Addr)&temp_var_for_tac_6,
               {(Addr) &(temp_var_for_const_11 = temp_var_for_callexp_1),
                (Addr) &(temp_var_for_const_10 = 1.0L)},
               "/home/shijia/Public/testprogram/e_expl.c_e.c:68:59");
  AssignLd({(Addr)&temp_var_for_ext_4},
           (Addr) &(temp_var_for_const_12 = temp_var_for_callexp_2),
           "/home/shijia/Public/testprogram/e_expl.c_e.c:67:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_4;
}

#endif

/* wrapper exp */
long double __expl(long double x) {
  long double z = __ieee754_expl(x);

  if ((!isfinite(z) || int temp_var_for_tac_7; int temp_var_for_const_13;
       temp_var_for_tac_7 = z == 0.0L;

       ) &&
      isfinite(x) && _LIB_VERSION != _IEEE_) {
    long double temp_var_for_ext_5;
    long double temp_var_for_const_14;
    long double temp_var_for_callexp_3;

    temp_var_for_callexp_3 = __kernel_standard_l(
        x, x, z, signbit(x) ? KMATHERRL_EXP_UNDERFLOW : KMATHERRL_EXP_OVERFLOW);
    temp_var_for_ext_5 = temp_var_for_callexp_3;
    compute((Addr)&temp_var_for_tac_7,
            {(Addr)&z, (Addr) &(temp_var_for_const_13 = 0.0L)},
            "/home/shijia/Public/testprogram/e_expl.c_e.c:80:26");
    AssignLd({(Addr)&temp_var_for_ext_5},
             (Addr) &(temp_var_for_const_14 = temp_var_for_callexp_3),
             "/home/shijia/Public/testprogram/e_expl.c_e.c:82:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_5;
  }

  long double temp_var_for_ext_6;
  temp_var_for_ext_6 = z;
  callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_6;
}

__typeof(__expl) expl __attribute__((weak, alias("__expl")));

#endif
