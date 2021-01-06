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
  static const long double u_threshold = (0.0 - 11355.137111933024058885L);
  long double temp_var_for_const_0, temp_var_for_const_1;
  ;
  static const long double log2e = 1.44269504088896340735992468100189213743L;

  GET_LDOUBLE_WORDS(ex, hx, lx, x);
  sign = (int)ex & 0x8000; /* sign bit of x */
  ex &= 0x7fff;
  hx &= IC(0x7fffffff);
  /* filter out non-finite argument */
  if (ex >= 0x7fff) {
    if ((hx | lx) != 0)
      return x;            /* NaN */
    return sign ? 0.0 : x; /* exp(+-inf)={inf,0} */
  }
  if (x > o_threshold) /* overflow */
  {
    feraiseexcept(FE_OVERFLOW);
    return HUGE_VALL;
    long double temp_var_for_tac_0;
    computeLdSub((Addr)&temp_var_for_tac_0,
                 {(Addr) &(temp_var_for_const_1 = 0.0),
                  (Addr) &(temp_var_for_const_0 = 11355.137111933024058885L)},
                 "toString(biExpr->getExprLoc())");
  }
  if (x < u_threshold) /* underflow */
  {
    feraiseexcept(FE_UNDERFLOW);
    long double temp_var_for_ext_0;
    temp_var_for_ext_0 = 0;
    long double temp_var_for_const_2;
    AssignLd({(Addr)&temp_var_for_ext_0}, (Addr) &(temp_var_for_const_2 = 0),
             "/home/shijia/Public/testprogram/e_expl.c_e.c:43:24");
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }
  x *= log2e;
  intx = (int)x;
  fractx = x - intx;
  long double temp_var_for_const_3;
  computeLdSub((Addr)&fractx, {(Addr)&x, (Addr) &(temp_var_for_const_3 = intx)},
               "/home/shijia/Public/testprogram/e_expl.c_e.c:50:10");
  return __ieee754_scalbnl(__ieee754_expm1l(M_LN2l * fractx) + 1.0L, intx);
}

#endif

/* wrapper exp */
long double __expl(long double x) {
  long double z = __ieee754_expl(x);

  if ((!isfinite(z) || z == 0.0L) && isfinite(x) && _LIB_VERSION != _IEEE_)
    return __kernel_standard_l(x, x, z, signbit(x) ? KMATHERRL_EXP_UNDERFLOW
                                                   : KMATHERRL_EXP_OVERFLOW);

  long double temp_var_for_ext_1;
  temp_var_for_ext_1 = z;
  AssignLd({(Addr)&temp_var_for_ext_1}, (Addr)&z,
           "/home/shijia/Public/testprogram/e_expl.c_e.c:65:22");
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

__typeof(__expl) expl __attribute__((weak, alias("__expl")));

#endif
