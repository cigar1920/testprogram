#include "../ScDebug/scdebug.h"
/* @(#)s_asinh.c 1.3 95/01/18 */
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

/* asinh(x)
 * Method :
 *	Based on
 *		asinh(x) = sign(x) * log [ |x| + sqrt(x*x+1) ]
 *	we have
 *	asinh(x) := x  if  1+x*x=1,
 *		 := sign(x)*(log(x)+ln2)) for large |x|, else
 *		 := sign(x)*log(2|x|+1/(|x|+sqrt(x*x+1))) if|x|>2, else
 *		 := sign(x)*log1p(|x| + x^2/(1 + sqrt(1+x^2)))
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

double __ieee754_asinhS(double x)
{
  double w;
  int32_t hx, ix;

  static const double one =
      1.00000000000000000000e+00; /* 0x3FF00000, 0x00000000 */
  static const double ln2 =
      6.93147180559945286227e-01; /* 0x3FE62E42, 0xFEFA39EF */
  static const double hugeval = 1.00000000000000000000e+300;

  GET_HIGH_WORD(hx, x);
  ix = hx & IC(0x7fffffff);
  if (ix < IC(0x3e300000))
  { /* |x|<2**-28 */
    if (hugeval + x > one)
    {
      double temp_var_for_ext_0;
      temp_var_for_ext_0 = x;
      AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&x,
              "/home/shijia/Public/testprogram/s_asinh.c_e.c:45:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_0;
    }
    /* return x inexact except 0 */
  }
  if (ix > IC(0x41b00000))
  { /* |x| > 2**28 */
    if (ix >= IC(0x7ff00000))
    {
      double temp_var_for_ext_1;
      double temp_var_for_tac_2;
      temp_var_for_tac_2 = x + x;

      temp_var_for_ext_1 = temp_var_for_tac_2;
      computeDAdd((Addr)&temp_var_for_tac_2, {(Addr)&x, (Addr)&x},
                  "/home/shijia/Public/testprogram/s_asinh.c_e.c:56:30");
      AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_2,
              "/home/shijia/Public/testprogram/s_asinh.c_e.c:56:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_1;
    }
    /* x is inf or NaN */
    double temp_var_for_tac_3;
    double temp_var_for_const_2, temp_var_for_const_3;
    double temp_var_for_callexp_0;

    /*embed fun has found*/
    double temp_var_for_callexp_1;

    temp_var_for_callexp_0 = fabs(x);
    temp_var_for_callexp_1 = __ieee754_log(temp_var_for_callexp_0);
    temp_var_for_tac_3 = temp_var_for_callexp_1 + ln2;

    w = temp_var_for_tac_3;
    computeDAdd((Addr)&temp_var_for_tac_3,
                {(Addr) & (temp_var_for_const_3 = temp_var_for_callexp_1),
                 (Addr) & (temp_var_for_const_2 = ln2)},
                "/home/shijia/Public/testprogram/s_asinh.c_e.c:63:42");
    AssignD({(Addr)&w}, (Addr)&temp_var_for_tac_3,
            "/home/shijia/Public/testprogram/s_asinh.c_e.c:63:7");
    ;
  }
  else
  {
    double xa = __ieee754_fabs(x);

    if (ix > IC(0x40000000))
    { /* 2**28 > |x| > 2.0 */
      double temp_var_for_tac_4, temp_var_for_tac_5, temp_var_for_tac_6,
          temp_var_for_tac_7, temp_var_for_tac_8, temp_var_for_tac_9;
      double temp_var_for_const_4, temp_var_for_const_5, temp_var_for_const_6,
          temp_var_for_const_7, temp_var_for_const_8;
      double temp_var_for_callexp_2;

      double temp_var_for_callexp_3;

      temp_var_for_tac_4 = 2.0 * xa;

      temp_var_for_tac_5 = xa * xa;

      temp_var_for_tac_6 = temp_var_for_tac_5 + one;

      temp_var_for_callexp_2 = __ieee754_sqrt(temp_var_for_tac_6);
      temp_var_for_tac_7 = temp_var_for_callexp_2 + xa;

      temp_var_for_tac_8 = one / temp_var_for_tac_7;

      temp_var_for_tac_9 = temp_var_for_tac_4 + temp_var_for_tac_8;

      temp_var_for_callexp_3 = __ieee754_log(temp_var_for_tac_9);
      w = temp_var_for_callexp_3;
      computeDMul((Addr)&temp_var_for_tac_4,
                  {(Addr) & (temp_var_for_const_4 = 2.0), (Addr)&xa},
                  "/home/shijia/Public/testprogram/s_asinh.c_e.c:68:29");
      computeDMul((Addr)&temp_var_for_tac_5, {(Addr)&xa, (Addr)&xa},
                  "/home/shijia/Public/testprogram/s_asinh.c_e.c:68:61");
      computeDAdd(
          (Addr)&temp_var_for_tac_6,
          {(Addr)&temp_var_for_tac_5, (Addr) & (temp_var_for_const_5 = one)},
          "/home/shijia/Public/testprogram/s_asinh.c_e.c:68:66");
      computeDAdd(
          (Addr)&temp_var_for_tac_7,
          {(Addr) & (temp_var_for_const_6 = temp_var_for_callexp_2), (Addr)&xa},
          "/home/shijia/Public/testprogram/s_asinh.c_e.c:68:73");
      computeDDiv(
          (Addr)&temp_var_for_tac_8,
          {(Addr) & (temp_var_for_const_7 = one), (Addr)&temp_var_for_tac_7},
          "/home/shijia/Public/testprogram/s_asinh.c_e.c:68:40");
      computeDAdd((Addr)&temp_var_for_tac_9,
                  {(Addr)&temp_var_for_tac_4, (Addr)&temp_var_for_tac_8},
                  "/home/shijia/Public/testprogram/s_asinh.c_e.c:68:34");
      AssignD({(Addr)&w},
              (Addr) & (temp_var_for_const_8 = temp_var_for_callexp_3),
              "/home/shijia/Public/testprogram/s_asinh.c_e.c:68:9");
      ;
    }
    else
    { /* 2.0 > |x| > 2**-28 */
      double temp_var_for_tac_10;
      temp_var_for_tac_10 = xa * xa;

      double t = temp_var_for_tac_10;
      computeDMul((Addr)&t, {(Addr)&xa, (Addr)&xa},
                  "/home/shijia/Public/testprogram/s_asinh.c_e.c:70:21");
      ;

      double temp_var_for_tac_11, temp_var_for_tac_12, temp_var_for_tac_13,
          temp_var_for_tac_14;
      double temp_var_for_const_9, temp_var_for_const_10, temp_var_for_const_11,
          temp_var_for_const_12;
      double temp_var_for_callexp_4;

      double temp_var_for_callexp_5;

      temp_var_for_tac_11 = one + t;

      temp_var_for_callexp_4 = __ieee754_sqrt(temp_var_for_tac_11);
      temp_var_for_tac_12 = one + temp_var_for_callexp_4;

      temp_var_for_tac_13 = t / temp_var_for_tac_12;

      temp_var_for_tac_14 = xa + temp_var_for_tac_13;

      temp_var_for_callexp_5 = __ieee754_log1p(temp_var_for_tac_14);
      w = temp_var_for_callexp_5;
      computeDMul((Addr)&temp_var_for_tac_10, {(Addr)&xa, (Addr)&xa},
                  "/home/shijia/Public/testprogram/s_asinh.c_e.c:70:21");
      computeDAdd((Addr)&temp_var_for_tac_11,
                  {(Addr) & (temp_var_for_const_9 = one), (Addr)&t},
                  "/home/shijia/Public/testprogram/s_asinh.c_e.c:72:62");
      computeDAdd((Addr)&temp_var_for_tac_12,
                  {(Addr) & (temp_var_for_const_11 = one),
                   (Addr) & (temp_var_for_const_10 = temp_var_for_callexp_4)},
                  "/home/shijia/Public/testprogram/s_asinh.c_e.c:72:41");
      computeDDiv((Addr)&temp_var_for_tac_13,
                  {(Addr)&t, (Addr)&temp_var_for_tac_12},
                  "/home/shijia/Public/testprogram/s_asinh.c_e.c:72:34");
      computeDAdd((Addr)&temp_var_for_tac_14,
                  {(Addr)&xa, (Addr)&temp_var_for_tac_13},
                  "/home/shijia/Public/testprogram/s_asinh.c_e.c:72:30");
      AssignD({(Addr)&w},
              (Addr) & (temp_var_for_const_12 = temp_var_for_callexp_5),
              "/home/shijia/Public/testprogram/s_asinh.c_e.c:72:9");
      ;
    }
  }
  if (hx > 0)
  {
    double temp_var_for_ext_2;
    temp_var_for_ext_2 = w;
    AssignD({(Addr)&temp_var_for_ext_2}, (Addr)&w,
            "/home/shijia/Public/testprogram/s_asinh.c_e.c:77:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  }

  double temp_var_for_ext_3;
  double temp_var_for_const_13;
  temp_var_for_ext_3 = (-(w));
  AssignD({(Addr)&temp_var_for_ext_3}, (Addr) & (temp_var_for_const_13 = (-(w))),
          "/home/shijia/Public/testprogram/s_asinh.c_e.c:84:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
  callExp++; /*identify the function is  add move tmpShadow*/
  return (temp_var_for_ext_3);
}

int main()
{
  std::ifstream inputFile("/home/shijia/Public/FpDebug-valgrind_3.12/valgrind/fpdebug/pso/exe-input/asinh_t.txt", std::ios::in);
  double input;
  long double oracle, realError = 0.0, scError = 0.0, prealError = 0.0, pscError = 0.0;
  long double delta = 1.0e-20;
  int index, la = 0, eq = 0, sm = 0;
  std::ifstream inputOracle("/home/shijia/Public/FpDebug-valgrind_3.12/valgrind/fpdebug/pso/mpfr/mpfrresults/asinh_out.txt", std::ios::in);
  while (inputFile >> input)
  {
    double a = __ieee754_asinhS(input);
    inputOracle >> index >> oracle;
    // std::cout<<oracle<<std::endl;
    // printf("oracle  %.20Le %.20le\n",oracle,a);
    prealError = fabs(oracle - (long double)a) / max(delta, fabs(oracle));
    realError += prealError;
    CallStackPop((Addr)&a, getTop(a));
    Real scValue = getReal("", (Addr)&a);
    pscError = fabs(oracle - (long double)scValue.z - (long double)scValue.zz) / max(delta, fabs(oracle));
    scError += pscError;
    if (pscError < prealError)
    {
      sm++;
    }
    else if (pscError == prealError)
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
  printf("%d %d %d\n", la, eq, sm);
  return 0;
}