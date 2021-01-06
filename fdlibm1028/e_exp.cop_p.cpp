#include "../ScDebug/scdebug.h"
/* @(#)e_exp.c 1.3 95/01/18 */
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

/* __ieee754_exp(x)
 * Returns the exponential of x.
 *
 * Method
 *   1. Argument reduction:
 *      Reduce x to an r so that |r| <= 0.5*ln2 ~ 0.34658.
 *	Given x, find r and integer k such that
 *
 *               x = k*ln2 + r,  |r| <= 0.5*ln2.
 *
 *      Here r will be represented as r = hi-lo for better
 *	accuracy.
 *
 *   2. Approximation of exp(r) by a special rational function on
 *	the interval [0,0.34658]:
 *	Write
 *	    R(r**2) = r*(exp(r)+1)/(exp(r)-1) = 2 + r*r/6 - r**4/360 + ...
 *      We use a special Reme algorithm on [0,0.34658] to generate
 * 	a polynomial of degree 5 to approximate R. The maximum error
 *	of this polynomial approximation is bounded by 2**-59. In
 *	other words,
 *	    R(z) ~ 2.0 + P1*z + P2*z**2 + P3*z**3 + P4*z**4 + P5*z**5
 *  	(where z=r*r, and the values of P1 to P5 are listed below)
 *	and
 *	    |                  5          |     -59
 *	    | 2.0+P1*z+...+P5*z   -  R(z) | <= 2
 *	    |                             |
 *	The computation of exp(r) thus becomes
 *                             2*r
 *		exp(r) = 1 + -------
 *		              R - r
 *                                 r*R1(r)
 *		       = 1 + r + ----------- (for better accuracy)
 *		                  2 - R1(r)
 *	where
 *			         2       4             10
 *		R1(r) = r - (P1*r  + P2*r  + ... + P5*r   ).
 *
 *   3. Scale back to obtain exp(x):
 *	From step 1, we have
 *	   exp(x) = 2^k * exp(r)
 *
 * Special cases:
 *	exp(INF) is INF, exp(NaN) is NaN;
 *	exp(-INF) is 0, and
 *	for finite argument, only exp(0)=1 is exact.
 *
 * Accuracy:
 *	according to an error analysis, the error is always less than
 *	1 ulp (unit in the last place).
 *
 * Misc. info.
 *	For IEEE double
 *	    if x >  7.09782712893383973096e+02 then exp(x) overflow
 *	    if x < -7.45133219101941108420e+02 then exp(x) underflow
 *
 * Constants:
 * The hexadecimal values are the intended ones for the following
 * constants. The decimal values may be used, provided that the
 * compiler will convert from decimal to binary accurately enough
 * to produce the hexadecimal values shown.
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

double __ieee754_expS(double x) /* default IEEE double exp */
{
        double y, hi, lo, c, t;
        int32_t k, xsb;
        uint32_t hx;
        static const double one = 1.0;
        static const double halF[2] = {0.5, -0.5};

        static const double hugeval = 1.0e+300;
        static const double twom1000 = 9.33263618503218878990e-302;    /* 2**-1000=0x01700000,0 */
        static const double o_threshold = 7.09782712893383973096e+02;  /* 0x40862E42, 0xFEFA39EF */
        static const double u_threshold = -7.45133219101941108420e+02; /* 0xc0874910, 0xD52D3051 */
        static const double ln2HI[2] = {
            6.93147180369123816490e-01, /* 0x3fe62e42, 0xfee00000 */
            -6.93147180369123816490e-01 /* 0xbfe62e42, 0xfee00000 */
        };

        static const double ln2LO[2] = {
            1.90821492927058770002e-10, /* 0x3dea39ef, 0x35793c76 */
            -1.90821492927058770002e-10 /* 0xbdea39ef, 0x35793c76 */
        };

        static const double invln2 = 1.44269504088896338700e+00; /* 0x3ff71547, 0x652b82fe */
        static const double P1 = 1.66666666666666019037e-01;     /* 0x3FC55555, 0x5555553E */
        static const double P2 = -2.77777777770155933842e-03;    /* 0xBF66C16C, 0x16BEBD93 */
        static const double P3 = 6.61375632143793436117e-05;     /* 0x3F11566A, 0xAF25DE2C */
        static const double P4 = -1.65339022054652515390e-06;    /* 0xBEBBBD41, 0xC5D26BF1 */
        static const double P5 = 4.13813679705723846039e-08;     /* 0x3E663769, 0x72BEA4D0 */
        GET_HIGH_WORD(hx, x);                                    /* high word of x */
        xsb = (hx >> 31) & 1;                                    /* sign bit of x */
        hx &= IC(0x7fffffff);                                    /* high word of |x| */

        /* filter out non-finite argument */
        if (hx >= IC(0x40862E42))
        { /* if |x|>=709.78... */
                if (hx >= IC(0x7ff00000))
                {
                        GET_LOW_WORD(k, x);
                        if (((hx & IC(0xfffff)) | k) != 0)
                        {
                                double temp_var_for_ext_0;
                                temp_var_for_ext_0 = x;
                                AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&x,
                                        "/home/shijia/Public/testprogram/e_exp.c_e.c:131:28");
                                ;
                                callExpStack.push(
                                    getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
                                callExp++; /*identify the function is  add move tmpShadow*/
                                return temp_var_for_ext_0;
                        }
                        /* NaN */
                        double temp_var_for_ext_1;
                        double temp_var_for_const_12;
                        temp_var_for_ext_1 = (xsb == 0) ? x : 0.0;
                        AssignD({(Addr)&temp_var_for_ext_1},
                                (Addr) & (temp_var_for_const_12 = (xsb == 0) ? x : 0.0),
                                "/home/shijia/Public/testprogram/e_exp.c_e.c:139:26");
                        ;

                        callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
                        callExp++;                 /*identify the function is  add move tmpShadow*/
                        return temp_var_for_ext_1; /* exp(+-inf)={inf,0} */
                }
                if (x > o_threshold) /* overflow */
                {
                        feraiseexcept(FE_OVERFLOW);
                        double temp_var_for_ext_2;
                        double temp_var_for_const_13;
                        double temp_var_for_callexp_0;

                        temp_var_for_callexp_0 = __builtin_huge_val();
                        temp_var_for_ext_2 = temp_var_for_callexp_0;
                        AssignD({(Addr)&temp_var_for_ext_2},
                                (Addr) & (temp_var_for_const_13 = temp_var_for_callexp_0),
                                "/home/shijia/Public/testprogram/e_exp.c_e.c:149:26");
                        ;

                        callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
                        callExp++; /*identify the function is  add move tmpShadow*/
                        return temp_var_for_ext_2;
                }
                if (x < u_threshold) /* underflow */
                {
                        feraiseexcept(FE_UNDERFLOW);
                        double temp_var_for_ext_3;
                        double temp_var_for_const_15;
                        temp_var_for_ext_3 = 0;
                        AssignD({(Addr)&temp_var_for_ext_3}, (Addr) & (temp_var_for_const_15 = 0),
                                "/home/shijia/Public/testprogram/e_exp.c_e.c:159:26");
                        ;

                        callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
                        callExp++; /*identify the function is  add move tmpShadow*/
                        return temp_var_for_ext_3;
                }
        }

        /* argument reduction */
        if (hx > IC(0x3fd62e42))
        { /* if  |x| > 0.5 ln2 */
                if (hx < IC(0x3FF0A2B2))
                { /* and |x| < 1.5 ln2 */
                        double temp_var_for_tac_7;
                        double temp_var_for_const_16;
                        temp_var_for_tac_7 = x - ln2HI[xsb];

                        hi = temp_var_for_tac_7;
                        AssignD({(Addr)&hi}, (Addr) & (temp_var_for_tac_7 = hi),
                                "/home/shijia/Public/testprogram/e_exp.c_e.c:170:10");
                        ;
                        double temp_var_for_const_17, temp_var_for_const_18;
                        lo = ln2LO[xsb];
                        AssignD({(Addr)&lo}, (Addr) & (temp_var_for_const_17 = ln2LO[xsb]),
                                "/home/shijia/Public/testprogram/e_exp.c_e.c:171:10");
                        ;
                        k = 1 - xsb - xsb;
                        AssignD({(Addr)&k}, (Addr) & (temp_var_for_const_18 = 1 - xsb - xsb),
                                "/home/shijia/Public/testprogram/e_exp.c_e.c:175:9");
                }
                else
                {
                        double temp_var_for_tac_8, temp_var_for_tac_9;
                        double temp_var_for_const_18, temp_var_for_const_19;
                        temp_var_for_tac_8 = invln2 * x;

                        temp_var_for_tac_9 = temp_var_for_tac_8 + halF[xsb];
                        k = temp_var_for_tac_9;
                        computeDMul((Addr)&temp_var_for_tac_8,
                                    {(Addr) & (temp_var_for_const_18 = invln2), (Addr)&x},
                                    "/home/shijia/Public/testprogram/e_exp.c_e.c:174:18");
                        computeDAdd((Addr)&temp_var_for_tac_9,
                                    {(Addr)&temp_var_for_tac_8,
                                     (Addr) & (temp_var_for_const_19 = halF[xsb])},
                                    "/home/shijia/Public/testprogram/e_exp.c_e.c:174:22");
                        AssignD({(Addr)&k}, (Addr) & (temp_var_for_tac_9),
                                "/home/shijia/Public/testprogram/e_exp.c_e.c:175:9");
                        ;

                        double temp_var_for_const_20;
                        t = k;

                        AssignD({(Addr)&t}, (Addr) & (k),
                                "/home/shijia/Public/testprogram/e_exp.c_e.c:175:9");
                        ;
                        double temp_var_for_tac_10, temp_var_for_tac_11;
                        double temp_var_for_const_21;
                        temp_var_for_tac_10 = t * ln2HI[0];

                        temp_var_for_tac_11 = x - temp_var_for_tac_10;

                        hi = temp_var_for_tac_11;
                        computeDMul((Addr)&temp_var_for_tac_10,
                                    {(Addr)&t, (Addr) & (temp_var_for_const_21 = ln2HI[0])},
                                    "/home/shijia/Public/testprogram/e_exp.c_e.c:176:18");
                        AssignD({(Addr)&hi}, (Addr) & (temp_var_for_tac_11 = hi),
                                "/home/shijia/Public/testprogram/e_exp.c_e.c:176:10");
                        ; /* t*ln2HI is exact here */
                        double temp_var_for_tac_12;
                        double temp_var_for_const_22;
                        temp_var_for_tac_12 = t * ln2LO[0];

                        lo = temp_var_for_tac_12;
                        AssignD({(Addr)&lo}, (Addr) & (temp_var_for_tac_12 = lo),
                                "/home/shijia/Public/testprogram/e_exp.c_e.c:177:10");
                        ;
                }

                double temp_var_for_tac_13;
                temp_var_for_tac_13 = hi - lo;

                x = temp_var_for_tac_13;
                computeDSub((Addr)&temp_var_for_tac_13, {(Addr)&hi, (Addr)&lo},
                            "/home/shijia/Public/testprogram/e_exp.c_e.c:179:12");
                AssignD({(Addr)&x}, (Addr)&temp_var_for_tac_13,
                        "/home/shijia/Public/testprogram/e_exp.c_e.c:179:7");
                ;
        }
        else
        {
                if (hx < IC(0x3e300000))
                { /* when |x|<2**-28 */
                        if (hugeval + x > one)
                        {
                                double temp_var_for_ext_4;
                                double temp_var_for_tac_16;
                                double temp_var_for_const_25;
                                temp_var_for_tac_16 = one + x;

                                temp_var_for_ext_4 = temp_var_for_tac_16;

                                AssignD({(Addr)&temp_var_for_ext_4}, (Addr) & (temp_var_for_tac_16 = one + x),
                                        "/home/shijia/Public/testprogram/e_exp.c_e.c:184:28");
                                ;
                                callExpStack.push(
                                    getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));

                                callExp++; /*identify the function is  add move tmpShadow*/
                                return temp_var_for_ext_4;
                        }
                        /* trigger inexact */
                        double temp_var_for_ext_5;
                        double temp_var_for_const_26;
                        temp_var_for_ext_5 = one;
                        AssignD({(Addr)&temp_var_for_ext_5}, (Addr) & (temp_var_for_const_26 = one),
                                "/home/shijia/Public/testprogram/e_exp.c_e.c:192:26");
                        ;
                        callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
                        callExp++; /*identify the function is  add move tmpShadow*/
                        return temp_var_for_ext_5;
                }
                else
                {
                        k = 0;
                        double temp_var_for_ext_6;
                        double temp_var_for_const_27;
                        temp_var_for_ext_6 = 0;
                        AssignD({(Addr)&temp_var_for_ext_6}, (Addr) & (temp_var_for_const_27 = 0),
                                "/home/shijia/Public/testprogram/e_exp.c_e.c:200:26");
                        ; // lo
                        /*(lo)(hi)(x)(hugeval)(4)(tem)(0)*/
                        lo = temp_var_for_ext_6;
                        AssignD({(Addr)&lo}, (Addr)&temp_var_for_ext_6,
                                "/home/shijia/Public/testprogram/e_exp.c_e.c:202:10");
                        ;
                        double temp_var_for_const_28;
                        hi = 0;
                        AssignD({(Addr)&hi}, (Addr) & (temp_var_for_const_28 = 0),
                                "/home/shijia/Public/testprogram/e_exp.c_e.c:203:10");
                        ;
                }
        }

        /* x is now in primary range */
        double temp_var_for_tac_17;
        temp_var_for_tac_17 = x * x;

        t = temp_var_for_tac_17;
        computeDMul((Addr)&temp_var_for_tac_17, {(Addr)&x, (Addr)&x},
                    "/home/shijia/Public/testprogram/e_exp.c_e.c:208:9");
        AssignD({(Addr)&t}, (Addr)&temp_var_for_tac_17,
                "/home/shijia/Public/testprogram/e_exp.c_e.c:208:5");
        ;
        double temp_var_for_tac_18, temp_var_for_tac_19, temp_var_for_tac_20,
            temp_var_for_tac_21, temp_var_for_tac_22, temp_var_for_tac_23,
            temp_var_for_tac_24, temp_var_for_tac_25, temp_var_for_tac_26,
            temp_var_for_tac_27;
        double temp_var_for_const_29, temp_var_for_const_30, temp_var_for_const_31,
            temp_var_for_const_32, temp_var_for_const_33;
        temp_var_for_tac_18 = t * P5;

        temp_var_for_tac_19 = P4 + temp_var_for_tac_18;

        temp_var_for_tac_20 = t * temp_var_for_tac_19;

        temp_var_for_tac_21 = P3 + temp_var_for_tac_20;

        temp_var_for_tac_22 = t * temp_var_for_tac_21;

        temp_var_for_tac_23 = P2 + temp_var_for_tac_22;

        temp_var_for_tac_24 = t * temp_var_for_tac_23;

        temp_var_for_tac_25 = P1 + temp_var_for_tac_24;

        temp_var_for_tac_26 = t * temp_var_for_tac_25;

        temp_var_for_tac_27 = x - temp_var_for_tac_26;

        c = temp_var_for_tac_27;
        computeDMul((Addr)&temp_var_for_tac_18,
                    {(Addr)&t, (Addr) & (temp_var_for_const_29 = P5)},
                    "/home/shijia/Public/testprogram/e_exp.c_e.c:209:53");
        computeDAdd((Addr)&temp_var_for_tac_19,
                    {(Addr) & (temp_var_for_const_30 = P4), (Addr)&temp_var_for_tac_18},
                    "/home/shijia/Public/testprogram/e_exp.c_e.c:209:49");
        computeDMul((Addr)&temp_var_for_tac_20, {(Addr)&t, (Addr)&temp_var_for_tac_19},
                    "/home/shijia/Public/testprogram/e_exp.c_e.c:209:43");
        computeDAdd((Addr)&temp_var_for_tac_21,
                    {(Addr) & (temp_var_for_const_31 = P3), (Addr)&temp_var_for_tac_20},
                    "/home/shijia/Public/testprogram/e_exp.c_e.c:209:39");
        computeDMul((Addr)&temp_var_for_tac_22, {(Addr)&t, (Addr)&temp_var_for_tac_21},
                    "/home/shijia/Public/testprogram/e_exp.c_e.c:209:33");
        computeDAdd((Addr)&temp_var_for_tac_23,
                    {(Addr) & (temp_var_for_const_32 = P2), (Addr)&temp_var_for_tac_22},
                    "/home/shijia/Public/testprogram/e_exp.c_e.c:209:29");
        computeDMul((Addr)&temp_var_for_tac_24, {(Addr)&t, (Addr)&temp_var_for_tac_23},
                    "/home/shijia/Public/testprogram/e_exp.c_e.c:209:23");
        computeDAdd((Addr)&temp_var_for_tac_25,
                    {(Addr) & (temp_var_for_const_33 = P1), (Addr)&temp_var_for_tac_24},
                    "/home/shijia/Public/testprogram/e_exp.c_e.c:209:19");
        computeDMul((Addr)&temp_var_for_tac_26, {(Addr)&t, (Addr)&temp_var_for_tac_25},
                    "/home/shijia/Public/testprogram/e_exp.c_e.c:209:13");
        computeDSub((Addr)&temp_var_for_tac_27, {(Addr)&x, (Addr)&temp_var_for_tac_26},
                    "/home/shijia/Public/testprogram/e_exp.c_e.c:209:9");
        AssignD({(Addr)&c}, (Addr)&temp_var_for_tac_27,
                "/home/shijia/Public/testprogram/e_exp.c_e.c:209:5");
        ;

        if (k == 0)
        {
                double temp_var_for_ext_7;
                double temp_var_for_tac_28, temp_var_for_tac_29, temp_var_for_tac_30,
                    temp_var_for_tac_31, temp_var_for_tac_32;
                double temp_var_for_const_34, temp_var_for_const_35;
                temp_var_for_tac_28 = x * c;

                temp_var_for_tac_29 = c - 2.0;

                temp_var_for_tac_30 = temp_var_for_tac_28 / temp_var_for_tac_29;

                temp_var_for_tac_31 = temp_var_for_tac_30 - x;

                temp_var_for_tac_32 = one - temp_var_for_tac_31;

                temp_var_for_ext_7 = temp_var_for_tac_32;

                // computeDMul((Addr)&temp_var_for_tac_28, {(Addr)&x, (Addr)&c},
                //             "/home/shijia/Public/testprogram/e_exp.c_e.c:212:36");

                computeDSub((Addr)&temp_var_for_tac_29,
                            {(Addr)&c, (Addr) & (temp_var_for_const_34 = 2.0)},
                            "/home/shijia/Public/testprogram/e_exp.c_e.c:212:46");
                computeDDiv((Addr)&temp_var_for_tac_30,
                            {(Addr) & (temp_var_for_tac_28), (Addr)&temp_var_for_tac_29},
                            "/home/shijia/Public/testprogram/e_exp.c_e.c:212:41");

                // computeDSub((Addr)&temp_var_for_tac_31,
                //             {(Addr)&temp_var_for_tac_30, (Addr)&x},
                //             "/home/shijia/Public/testprogram/e_exp.c_e.c:212:53");
                computeDSub((Addr)&temp_var_for_tac_32,
                            {(Addr)&one, (Addr)&temp_var_for_tac_31},
                            "/home/shijia/Public/testprogram/e_exp.c_e.c:212:53");
                AssignD({(Addr)&temp_var_for_ext_7}, (Addr) & (temp_var_for_tac_32),
                        "/home/shijia/Public/testprogram/e_exp.c_e.c:212:24");
                ;

                callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
                callExp++; /*identify the function is  add move tmpShadow*/

                return temp_var_for_ext_7;
        }

        double temp_var_for_tac_33, temp_var_for_tac_34, temp_var_for_tac_35,
            temp_var_for_tac_36, temp_var_for_tac_37, temp_var_for_tac_38;
        double temp_var_for_const_36, temp_var_for_const_37;
        temp_var_for_tac_33 = x * c;

        temp_var_for_tac_34 = 2.0 - c;

        temp_var_for_tac_35 = temp_var_for_tac_33 / temp_var_for_tac_34;

        temp_var_for_tac_36 = lo - temp_var_for_tac_35;

        temp_var_for_tac_37 = temp_var_for_tac_36 - hi;

        temp_var_for_tac_38 = one - temp_var_for_tac_37;

        y = temp_var_for_tac_38;
        computeDMul((Addr)&temp_var_for_tac_33, {(Addr)&x, (Addr)&c},
                    "/home/shijia/Public/testprogram/e_exp.c_e.c:218:23");
        computeDSub((Addr)&temp_var_for_tac_34,
                    {(Addr) & (temp_var_for_const_36 = 2.0), (Addr)&c},
                    "/home/shijia/Public/testprogram/e_exp.c_e.c:218:35");
        computeDDiv((Addr)&temp_var_for_tac_35,
                    {(Addr)&temp_var_for_tac_33, (Addr)&temp_var_for_tac_34},
                    "/home/shijia/Public/testprogram/e_exp.c_e.c:218:28");
        computeDSub((Addr)&temp_var_for_tac_36, {(Addr)&lo, (Addr)&temp_var_for_tac_35},
                    "/home/shijia/Public/testprogram/e_exp.c_e.c:218:18");
        computeDSub((Addr)&temp_var_for_tac_37, {(Addr)&temp_var_for_tac_36, (Addr)&hi},
                    "/home/shijia/Public/testprogram/e_exp.c_e.c:218:41");
        computeDSub((Addr)&temp_var_for_tac_38,
                    {(Addr) & (temp_var_for_const_37 = one), (Addr)&temp_var_for_tac_37},
                    "/home/shijia/Public/testprogram/e_exp.c_e.c:218:11");

        AssignD({(Addr)&y}, (Addr)&temp_var_for_tac_38,
                "/home/shijia/Public/testprogram/e_exp.c_e.c:218:5");

        ;
        GET_HIGH_WORD(hx, y);
        if (k >= -1021)
        {
                hx += (k << IEEE754_DOUBLE_SHIFT); /* add k to y's exponent */
                SET_HIGH_WORD(y, hx);
                double temp_var_for_ext_8;
                double temp_var_for_const_38;
                temp_var_for_ext_8 = y;
                AssignD({(Addr)&temp_var_for_ext_8}, (Addr) & (temp_var_for_const_38 = y),
                        "/home/shijia/Public/testprogram/e_exp.c_e.c:224:24");
                ;

                callExpStack.push(getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
                callExp++; /*identify the function is  add move tmpShadow*/
                return temp_var_for_ext_8;
        }
        else
        {
                hx += ((k + 1000) << IEEE754_DOUBLE_SHIFT); /* add k to y's exponent */
                SET_HIGH_WORD(y, hx);
                double temp_var_for_ext_9;
                double temp_var_for_tac_39;
                double temp_var_for_const_38;
                double temp_var_for_const_39;
                temp_var_for_tac_39 = y * twom1000;
                // SET_HIGH_WORD(ShadowMap[(Addr) &y].value.z, hx);
                temp_var_for_ext_9 = temp_var_for_tac_39;
                computeDMul((Addr)&temp_var_for_tac_39,
                            {(Addr) &(y), (Addr) & (temp_var_for_const_38 = twom1000)},
                            "/home/shijia/Public/testprogram/e_exp.c_e.c:232:28");
                AssignD({(Addr)&temp_var_for_ext_9}, (Addr)&temp_var_for_tac_39,
                        "/home/shijia/Public/testprogram/e_exp.c_e.c:232:24");
                ;

                callExpStack.push(getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
                callExp++; /*identify the function is  add move tmpShadow*/
                return temp_var_for_ext_9;
        }
}

int main()
{
        std::ifstream inputFile("/home/shijia/Public/FpDebug-valgrind_3.12/valgrind/fpdebug/pso/exe-input/exp_t.txt", std::ios::in);
        double input;
        long double oracle, realError = 0.0, scError = 0.0, prealError = 0.0, pscError = 0.0;
        long double delta = 1.0e-20;
        int index, la = 0, eq = 0, sm = 0;
        std::ifstream inputOracle("/home/shijia/Public/FpDebug-valgrind_3.12/valgrind/fpdebug/pso/mpfr/mpfrresults/exp_out.txt", std::ios::in);
        while (inputFile >> input)
        {
                double a = __ieee754_expS(input);
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