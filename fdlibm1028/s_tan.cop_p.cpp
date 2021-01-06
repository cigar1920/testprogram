#include "../ScDebug/scdebug.h"
/* @(#)s_tan.c 1.3 95/01/18 */
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

/* tan(x)
 * Return tangent function of x.
 *
 * kernel function:
 *	__kernel_tan		... tangent function on [-pi/4,pi/4]
 *	__ieee754_rem_pio2	... argument reduction routine
 *
 * Method.
 *      Let S,C and T denote the sin, cos and tan respectively on
 *	[-PI/4, +PI/4]. Reduce the argument x to y1+y2 = x-k*pi/2
 *	in [-pi/4 , +pi/4], and let n = k mod 4.
 *	We have
 *
 *          n        sin(x)      cos(x)        tan(x)
 *     ----------------------------------------------------------
 *	    0	       S	   C		 T
 *	    1	       C	  -S		-1/T
 *	    2	      -S	  -C		 T
 *	    3	      -C	   S		-1/T
 *     ----------------------------------------------------------
 *
 * Special cases:
 *      Let trig be any of sin, cos, or tan.
 *      trig(+-INF)  is NaN, with signals;
 *      trig(NaN)    is that NaN;
 *
 * Accuracy:
 *	TRIG(x) returns trig(x) nearly rounded
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"

#include "k_rem_pio2.c"
#include "e_rem_pio2.c"
#include "k_tan.cop_p.cpp"
#endif


double __ieee754_tanS(double x) {
  double y[2], z = 0.0;
  int32_t n, ix;

  /* High word of x. */
  GET_HIGH_WORD(ix, x);

  /* |x| ~< pi/4 */
  ix &= IC(0x7fffffff);
  if (ix <= IC(0x3fe921fb)) {
    double temp_var_for_ext_0;
    double temp_var_for_const_0;
    double temp_var_for_callexp_0;

    temp_var_for_callexp_0 = __kernel_tanS(x, z, 1);
    temp_var_for_ext_0 = temp_var_for_callexp_0;
    AssignD({(Addr)&temp_var_for_ext_0},
            (Addr) &(temp_var_for_const_0 = temp_var_for_callexp_0),
            "/home/shijia/Public/testprogram/s_tan.c_e.c:60:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  /* tan(Inf or NaN) is NaN */
  else {
    if (ix >= IC(0x7ff00000)) {
      double temp_var_for_ext_1;
      double temp_var_for_tac_0;
      temp_var_for_tac_0 = x - x;

      temp_var_for_ext_1 = temp_var_for_tac_0;
      computeDSub((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&x},
                  "/home/shijia/Public/testprogram/s_tan.c_e.c:70:30");
      AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_0,
              "/home/shijia/Public/testprogram/s_tan.c_e.c:70:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_1;
    }
    /* NaN */

    /* argument reduction needed */
    else {
      n = __ieee754_rem_pio2(x, y);
      double temp_var_for_ext_2;
      double temp_var_for_tac_1, temp_var_for_tac_2, temp_var_for_tac_3;
      double temp_var_for_const_1, temp_var_for_const_2, temp_var_for_const_3,
          temp_var_for_const_4, temp_var_for_const_5;
      double temp_var_for_callexp_1;

      temp_var_for_callexp_1 =
          __kernel_tanS(y[0], y[1], ((int)(1 - ((n & 1) << 1))));
      temp_var_for_ext_2 = temp_var_for_callexp_1;

      AssignD({(Addr)&temp_var_for_ext_2},
              (Addr) &(temp_var_for_const_5 = temp_var_for_callexp_1),
              "/home/shijia/Public/testprogram/s_tan.c_e.c:82:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_2; /*   1 -- n even
                                                                                                                                    -1 -- n odd */
    }
  }
}

int main()
{
        std::ifstream inputFile("/home/shijia/Public/FpDebug-valgrind_3.12/valgrind/fpdebug/pso/exe-input/tan_t.txt", std::ios::in);
        double input;
        long double oracle, realError = 0.0, scError = 0.0, prealError = 0.0, pscError = 0.0;
        long double delta = 1.0e-20;
        int index, la = 0, eq = 0, sm = 0;
        std::ifstream inputOracle("/home/shijia/Public/FpDebug-valgrind_3.12/valgrind/fpdebug/pso/mpfr/mpfrresults/tan_out.txt", std::ios::in);
        while (inputFile >> input)
        {
                double a = __ieee754_tanS(input);
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