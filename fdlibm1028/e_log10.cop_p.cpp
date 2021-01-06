#include "../ScDebug/scdebug.h"
/* @(#)e_log10.c 1.3 95/01/18 */
/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunSoft, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 */

/* __ieee754_log10(x)
 * Return the base 10 logarithm of x
 *
 * Method :
 *	Let log10_2hi = leading 40 bits of log10(2) and
 *	    log10_2lo = log10(2) - log10_2hi,
 *	    ivln10   = 1/log(10) rounded.
 *	Then
 *		n = ilogb(x),
 *		if(n<0)  n = n+1;
 *		x = scalbn(x,-n);
 *		log10(x) := n*log10_2hi + (n*log10_2lo + ivln10*log(x))
 *
 * Note 1:
 *	To guarantee log10(10**n)=n, where 10**n is normal, the rounding
 *	mode must set to Round-to-Nearest.
 * Note 2:
 *	[1/log(10)] rounded to 53 bits has error  .198   ulps;
 *	log10 is monotonic at all binary break points.
 *
 * Special cases:
 *	log10(x) is NaN with signal if x < 0;
 *	log10(+INF) is +INF with no signal; log10(0) is -INF with signal;
 *	log10(NaN) is that NaN with no signal;
 *	log10(10**N) = N  for N=0,1,...,22.
 *
 * Constants:
 * The hexadecimal values are the intended ones for the following constants.
 * The decimal values may be used, provided that the compiler will convert
 * from decimal to binary accurately enough to produce the hexadecimal values
 * shown.
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

double __ieee754_log10S(double x)
{
  double y, z;
  int32_t i, k, hx;
  uint32_t lx;

  static const double two54 =
      1.80143985094819840000e+16; /* 0x43500000, 0x00000000 */
  static const double ivln10 =
      4.34294481903251816668e-01; /* 0x3FDBCB7B, 0x1526E50E */
  static const double log10_2hi =
      3.01029995663611771306e-01; /* 0x3FD34413, 0x509F6000 */
  static const double log10_2lo =
      3.69423907715893078616e-13; /* 0x3D59FEF3, 0x11F12B36 */

  static const double zero = 0.0;

  GET_DOUBLE_WORDS(hx, lx, x);

  k = 0;
  if (hx < IC(0x00100000))
  { /* x < 2**-1022  */
    if (((hx & IC(0x7fffffff)) | lx) == 0)
    {
      double temp_var_for_ext_0;
      double temp_var_for_tac_0;
      double temp_var_for_const_0, temp_var_for_const_1;
      temp_var_for_tac_0 = (-(two54)) / zero;

      temp_var_for_ext_0 = temp_var_for_tac_0;
      computeDDiv((Addr)&temp_var_for_tac_0,
                  {(Addr) & (temp_var_for_const_1 = (-(two54))),
                   (Addr) & (temp_var_for_const_0 = zero)},
                  "/home/shijia/Public/testprogram/e_log10.c_e.c:74:35");
      AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_0,
              "/home/shijia/Public/testprogram/e_log10.c_e.c:74:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_0;
    }
    /* log(+-0)=-inf */
    if (hx < 0)
    {
      double temp_var_for_ext_1;
      double temp_var_for_tac_1, temp_var_for_tac_2;
      double temp_var_for_const_2;
      temp_var_for_tac_1 = x - x;

      temp_var_for_tac_2 = temp_var_for_tac_1 / zero;

      temp_var_for_ext_1 = temp_var_for_tac_2;
      computeDSub((Addr)&temp_var_for_tac_1, {(Addr)&x, (Addr)&x},
                  "/home/shijia/Public/testprogram/e_log10.c_e.c:83:31");
      computeDDiv(
          (Addr)&temp_var_for_tac_2,
          {(Addr)&temp_var_for_tac_1, (Addr) & (temp_var_for_const_2 = zero)},
          "/home/shijia/Public/testprogram/e_log10.c_e.c:83:36");
      AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_2,
              "/home/shijia/Public/testprogram/e_log10.c_e.c:83:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_1;
    }
    /* log(-#) = NaN */
    k -= 54;
    x *= two54;
    ; /* subnormal number, scale up x */
    GET_HIGH_WORD(hx, x);
  }
  if (hx >= IC(0x7ff00000))
  {
    double temp_var_for_ext_2;
    double temp_var_for_tac_4;
    temp_var_for_tac_4 = x + x;

    temp_var_for_ext_2 = temp_var_for_tac_4;
    computeDAdd((Addr)&temp_var_for_tac_4, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_log10.c_e.c:96:28");
    AssignD({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_4,
            "/home/shijia/Public/testprogram/e_log10.c_e.c:96:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  }

  k += (hx >> 20) - 1023;
  i = ((uint32_t)k & UC(0x80000000)) >> 31;
  hx = (hx & IC(0x000fffff)) | ((0x3ff - i) << 20);
  double temp_var_for_tac_5;
  double temp_var_for_const_3, temp_var_for_const_4, temp_var_for_const_5;
  temp_var_for_tac_5 = k + i;

  y = ((double)temp_var_for_tac_5);
  computeDAdd((Addr)&temp_var_for_tac_5, {(Addr) & (temp_var_for_const_4 = k), (Addr) & (temp_var_for_const_3 = i)},
              "/home/shijia/Public/testprogram/e_log10.c_e.c:105:18");
  AssignD({(Addr)&y},
          (Addr) & (temp_var_for_const_5 = ((double)temp_var_for_tac_5)),
          "/home/shijia/Public/testprogram/e_log10.c_e.c:105:5");
  ;
  SET_HIGH_WORD(x, hx);
  double temp_var_for_tac_6, temp_var_for_tac_7, temp_var_for_tac_8;
  double temp_var_for_const_6, temp_var_for_const_7, temp_var_for_const_8;
  double temp_var_for_callexp_0;

  temp_var_for_tac_6 = y * log10_2lo;

  temp_var_for_callexp_0 = __ieee754_log(x);
  temp_var_for_tac_7 = ivln10 * temp_var_for_callexp_0;

  temp_var_for_tac_8 = temp_var_for_tac_6 + temp_var_for_tac_7;
  z = temp_var_for_tac_8;

  ;
  double temp_var_for_ext_3;
  double temp_var_for_tac_9, temp_var_for_tac_10;
  double temp_var_for_const_9;
  temp_var_for_tac_9 = y * log10_2hi;

  temp_var_for_tac_10 = z + temp_var_for_tac_9;

  temp_var_for_ext_3 = temp_var_for_tac_10;
  computeDMul((Addr)&temp_var_for_tac_6,
              {(Addr)&y, (Addr) & (temp_var_for_const_6 = log10_2lo)},
              "/home/shijia/Public/testprogram/e_log10.c_e.c:107:9");
  computeDMul((Addr)&temp_var_for_tac_7,
              {(Addr) & (temp_var_for_const_8 = ivln10),
               (Addr) & (temp_var_for_const_7 = temp_var_for_callexp_0)},
              "/home/shijia/Public/testprogram/e_log10.c_e.c:107:30");
  computeDAdd((Addr)&temp_var_for_tac_8,
              {(Addr)&temp_var_for_tac_6, (Addr)&temp_var_for_tac_7},
              "/home/shijia/Public/testprogram/e_log10.c_e.c:107:21");
  computeDMul((Addr)&temp_var_for_tac_9,
              {(Addr)&y, (Addr) & (temp_var_for_const_9 = log10_2hi)},
              "/home/shijia/Public/testprogram/e_log10.c_e.c:109:30");
  computeDAdd((Addr)&temp_var_for_tac_10, {(Addr)&z, (Addr)&temp_var_for_tac_9},
              "/home/shijia/Public/testprogram/e_log10.c_e.c:109:26");
  AssignD({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_10,
          "/home/shijia/Public/testprogram/e_log10.c_e.c:109:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_3;
}
int main()
{
  std::ifstream inputFile("/home/shijia/Public/FpDebug-valgrind_3.12/valgrind/fpdebug/pso/exe-input/log10_t.txt", std::ios::in);
  double input;
  long double oracle, realError = 0.0, scError = 0.0, prealError = 0.0, pscError = 0.0;
  long double delta = 1.0e-20;
  int index,la=0,eq=0,sm=0;
  std::ifstream inputOracle("/home/shijia/Public/FpDebug-valgrind_3.12/valgrind/fpdebug/pso/mpfr/mpfrresults/log10_out.txt", std::ios::in);
  while (inputFile >> input)
  {
    double a = __ieee754_log10S(input);
    inputOracle >> index >> oracle;
    // std::cout<<oracle<<std::endl;
    // printf("oracle  %.20Le %.20le\n",oracle,a);
    prealError = fabs(oracle - (long double)a) / max(delta, fabs(oracle));
    realError += prealError;
    CallStackPop((Addr)&a, getTop(a));
    Real scValue = getReal("", (Addr)&a);
    pscError = fabs(oracle - (long double)scValue.z - (long double)scValue.zz) / max(delta, fabs(oracle));
    scError += pscError;
    if(pscError<prealError)
    {
      sm++;
    }
    else if(pscError==prealError)
    {
      eq++;
    }
    else
    {
      la++;
    }
    
    
    // printVarInfo("a", (Addr)&a);
    // printf("%d %.20Le %.20Le\n",index,realError/index,scError/index);
  }
  printf("%d %.20Le %.20Le ", index, realError / index, scError / index);
  printf("%d %d %d\n", la,eq,sm);
  return 0;
}