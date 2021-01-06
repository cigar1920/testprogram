#include "../ScDebug/scdebug.h"
/* @(#)e_acosh.c 1.3 95/01/18 */
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

/* __ieee754_acosh(x)
 * Method :
 *	Based on
 *		acosh(x) = log [ x + sqrt(x*x-1) ]
 *	we have
 *		acosh(x) := log(x)+ln2,	if x is large; else
 *		acosh(x) := log(2x-1/(sqrt(x*x-1)+x)) if x>2; else
 *		acosh(x) := log1p(t+sqrt(2.0*t+t*t)); where t=x-1.
 *
 * Special cases:
 *	acosh(x) is NaN with signal if x<1.
 *	acosh(NaN) is NaN without signal.
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif



double __ieee754_acoshS(double x) {
  double t;
  int32_t hx;
  uint32_t lx;

  static const double one = 1.0;
  static const double ln2 =
      6.93147180559945286227e-01; /* 0x3FE62E42, 0xFEFA39EF */

  GET_DOUBLE_WORDS(hx, lx, x);
  if (hx < IC(0x3ff00000)) { /* x < 1 */
    double temp_var_for_ext_0;
    double temp_var_for_tac_0, temp_var_for_tac_1, temp_var_for_tac_2;
    temp_var_for_tac_0 = x - x;

    temp_var_for_tac_1 = x - x;

    temp_var_for_tac_2 = temp_var_for_tac_0 / temp_var_for_tac_1;

    temp_var_for_ext_0 = temp_var_for_tac_2;
    computeDSub((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_acosh.c_e.c:45:29");
    computeDSub((Addr)&temp_var_for_tac_1, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_acosh.c_e.c:45:39");
    computeDDiv((Addr)&temp_var_for_tac_2,
                {(Addr)&temp_var_for_tac_0, (Addr)&temp_var_for_tac_1},
                "/home/shijia/Public/testprogram/e_acosh.c_e.c:45:34");
    AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_2,
            "/home/shijia/Public/testprogram/e_acosh.c_e.c:45:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  } else {
    if (hx >= IC(0x41b00000)) {   /* x > 2**28 */
      if (hx >= IC(0x7ff00000)) { /* x is inf of NaN */
        double temp_var_for_ext_1;
        double temp_var_for_tac_3;
        temp_var_for_tac_3 = x + x;

        temp_var_for_ext_1 = temp_var_for_tac_3;
        computeDAdd((Addr)&temp_var_for_tac_3, {(Addr)&x, (Addr)&x},
                    "/home/shijia/Public/testprogram/e_acosh.c_e.c:53:32");
        AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_3,
                "/home/shijia/Public/testprogram/e_acosh.c_e.c:53:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_1;
      }
      double temp_var_for_ext_2;
      double temp_var_for_tac_4;
      double temp_var_for_const_0, temp_var_for_const_1;
      double temp_var_for_callexp_0;

      temp_var_for_callexp_0 = __ieee754_log(x);
      temp_var_for_tac_4 = temp_var_for_callexp_0 + ln2;

      temp_var_for_ext_2 = temp_var_for_tac_4;
      computeDAdd((Addr)&temp_var_for_tac_4,
                  {(Addr) &(temp_var_for_const_1 = temp_var_for_callexp_0),
                   (Addr) &(temp_var_for_const_0 = ln2)},
                  "/home/shijia/Public/testprogram/e_acosh.c_e.c:60:45");
      AssignD({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_4,
              "/home/shijia/Public/testprogram/e_acosh.c_e.c:60:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_2; /* acosh(huge)=log(2x) */
    } else {
      if (((hx - IC(0x3ff00000)) | lx) == 0) {
        double temp_var_for_ext_3;
        double temp_var_for_const_2;
        temp_var_for_ext_3 = 0.0;
        AssignD({(Addr)&temp_var_for_ext_3},
                (Addr) &(temp_var_for_const_2 = 0.0),
                "/home/shijia/Public/testprogram/e_acosh.c_e.c:68:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_3; /* acosh(1) = 0 */
      } else {
        if (hx > IC(0x40000000)) { /* 2**28 > x > 2 */
          double temp_var_for_ext_4;
          double temp_var_for_tac_5;
          temp_var_for_tac_5 = x * x;

          temp_var_for_ext_4 = temp_var_for_tac_5;
          computeDMul((Addr)&temp_var_for_tac_5, {(Addr)&x, (Addr)&x},
                      "/home/shijia/Public/testprogram/e_acosh.c_e.c:76:34");
          AssignD({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_5,
                  "/home/shijia/Public/testprogram/e_acosh.c_e.c:76:30");
          ; // t
          /*(_)(_)(a)(m)(a)(m)(_)(_)(1)(t)(t_2)(temp_var_for)(x)(x)*/
          t = temp_var_for_ext_4;
          AssignD({(Addr)&t}, (Addr)&temp_var_for_ext_4,
                  "/home/shijia/Public/testprogram/e_acosh.c_e.c:78:13");
          ;
          double temp_var_for_ext_5;
          double temp_var_for_tac_6, temp_var_for_tac_7, temp_var_for_tac_8,
              temp_var_for_tac_9, temp_var_for_tac_10;
          double temp_var_for_const_3, temp_var_for_const_4,
              temp_var_for_const_5, temp_var_for_const_6, temp_var_for_const_7;
          double temp_var_for_callexp_1;

          double temp_var_for_callexp_2;

          temp_var_for_tac_6 = 2.0 * x;

          temp_var_for_tac_7 = t - one;

          temp_var_for_callexp_1 = __ieee754_sqrt(temp_var_for_tac_7);
          temp_var_for_tac_8 = x + temp_var_for_callexp_1;

          temp_var_for_tac_9 = one / temp_var_for_tac_8;

          temp_var_for_tac_10 = temp_var_for_tac_6 - temp_var_for_tac_9;

          temp_var_for_callexp_2 = __ieee754_log(temp_var_for_tac_10);
          temp_var_for_ext_5 = temp_var_for_callexp_2;
          computeDMul((Addr)&temp_var_for_tac_6,
                      {(Addr) &(temp_var_for_const_3 = 2.0), (Addr)&x},
                      "/home/shijia/Public/testprogram/e_acosh.c_e.c:81:33");
          computeDSub((Addr)&temp_var_for_tac_7,
                      {(Addr)&t, (Addr) &(temp_var_for_const_4 = one)},
                      "/home/shijia/Public/testprogram/e_acosh.c_e.c:81:67");
          computeDAdd((Addr)&temp_var_for_tac_8,
                      {(Addr)&x,
                       (Addr) &(temp_var_for_const_5 = temp_var_for_callexp_1)},
                      "/home/shijia/Public/testprogram/e_acosh.c_e.c:81:48");
          computeDDiv(
              (Addr)&temp_var_for_tac_9,
              {(Addr) &(temp_var_for_const_6 = one), (Addr)&temp_var_for_tac_8},
              "/home/shijia/Public/testprogram/e_acosh.c_e.c:81:43");
          computeDSub((Addr)&temp_var_for_tac_10,
                      {(Addr)&temp_var_for_tac_6, (Addr)&temp_var_for_tac_9},
                      "/home/shijia/Public/testprogram/e_acosh.c_e.c:81:37");
          AssignD({(Addr)&temp_var_for_ext_5},
                  (Addr) &(temp_var_for_const_7 = temp_var_for_callexp_2),
                  "/home/shijia/Public/testprogram/e_acosh.c_e.c:80:30");
          ;
          callExpStack.push(
              getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
          callExp++; /*identify the function is  add move tmpShadow*/
          return temp_var_for_ext_5;
        } else { /* 1<x<2 */
          double temp_var_for_tac_11;
          double temp_var_for_const_8;
          temp_var_for_tac_11 = x - one;

          t = temp_var_for_tac_11;
          computeDSub((Addr)&temp_var_for_tac_11,
                      {(Addr)&x, (Addr) &(temp_var_for_const_8 = one)},
                      "/home/shijia/Public/testprogram/e_acosh.c_e.c:87:17");
          AssignD({(Addr)&t}, (Addr)&temp_var_for_tac_11,
                  "/home/shijia/Public/testprogram/e_acosh.c_e.c:87:13");
          ;
          double temp_var_for_ext_6;
          double temp_var_for_tac_12, temp_var_for_tac_13, temp_var_for_tac_14,
              temp_var_for_tac_15;
          double temp_var_for_const_9, temp_var_for_const_10,
              temp_var_for_const_11;
          double temp_var_for_callexp_3;

          double temp_var_for_callexp_4;

          temp_var_for_tac_12 = 2.0 * t;

          temp_var_for_tac_13 = t * t;

          temp_var_for_tac_14 = temp_var_for_tac_12 + temp_var_for_tac_13;

          temp_var_for_callexp_3 = __ieee754_sqrt(temp_var_for_tac_14);
          temp_var_for_tac_15 = t + temp_var_for_callexp_3;

          temp_var_for_callexp_4 = __ieee754_log1p(temp_var_for_tac_15);
          temp_var_for_ext_6 = temp_var_for_callexp_4;
          computeDMul((Addr)&temp_var_for_tac_12,
                      {(Addr) &(temp_var_for_const_9 = 2.0), (Addr)&t},
                      "/home/shijia/Public/testprogram/e_acosh.c_e.c:90:54");
          computeDMul((Addr)&temp_var_for_tac_13, {(Addr)&t, (Addr)&t},
                      "/home/shijia/Public/testprogram/e_acosh.c_e.c:90:62");
          computeDAdd((Addr)&temp_var_for_tac_14,
                      {(Addr)&temp_var_for_tac_12, (Addr)&temp_var_for_tac_13},
                      "/home/shijia/Public/testprogram/e_acosh.c_e.c:90:58");
          computeDAdd((Addr)&temp_var_for_tac_15,
                      {(Addr)&t, (Addr) &(temp_var_for_const_10 =
                                              temp_var_for_callexp_3)},
                      "/home/shijia/Public/testprogram/e_acosh.c_e.c:90:33");
          AssignD({(Addr)&temp_var_for_ext_6},
                  (Addr) &(temp_var_for_const_11 = temp_var_for_callexp_4),
                  "/home/shijia/Public/testprogram/e_acosh.c_e.c:89:30");
          ;
          callExpStack.push(
              getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
          callExp++; /*identify the function is  add move tmpShadow*/
          return temp_var_for_ext_6;
        }
      }
    }
  }
}




int main()
{
  std::ifstream inputFile("/home/shijia/Public/FpDebug-valgrind_3.12/valgrind/fpdebug/pso/exe-input/acosh_t.txt", std::ios::in);
  double input;
  long double oracle, realError = 0.0, scError = 0.0, prealError = 0.0, pscError = 0.0;
  long double delta = 1.0e-20;
  int index,la=0,eq=0,sm=0;
  std::ifstream inputOracle("/home/shijia/Public/FpDebug-valgrind_3.12/valgrind/fpdebug/pso/mpfr/mpfrresults/acosh_out.txt", std::ios::in);
  while (inputFile >> input)
  {
    double a = __ieee754_acoshS(input);
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