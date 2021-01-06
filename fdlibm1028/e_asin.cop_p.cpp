#include "../ScDebug/scdebug.h"
/* @(#)e_asin.c 1.3 95/01/18 */
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

/* __ieee754_asin(x)
 * Method :
 *	Since  asin(x) = x + x^3/6 + x^5*3/40 + x^7*15/336 + ...
 *	we approximate asin(x) on [0,0.5] by
 *		asin(x) = x + x*x^2*R(x^2)
 *	where
 *		R(x^2) is a rational approximation of (asin(x)-x)/x^3
 *	and its remez error is bounded by
 *		|(asin(x)-x)/x^3 - R(x^2)| < 2^(-58.75)
 *
 *	For x in [0.5,1]
 *		asin(x) = pi/2-2*asin(sqrt((1-x)/2))
 *	Let y = (1-x), z = y/2, s := sqrt(z), and pio2_hi+pio2_lo=pi/2;
 *	then for x>0.98
 *		asin(x) = pi/2 - 2*(s+s*z*R(z))
 *			= pio2_hi - (2*(s+s*z*R(z)) - pio2_lo)
 *	For x<=0.98, let pio4_hi = pio2_hi/2, then
 *		f = hi part of s;
 *		c = sqrt(z) - f = (z-f*f)/(s+f) 	...f+c=sqrt(z)
 *	and
 *		asin(x) = pi/2 - 2*(s+s*z*R(z))
 *			= pio4_hi+(pio4-2s)-(2s*z*R(z)-pio2_lo)
 *			= pio4_hi+(pio4-2f)-(2s*z*R(z)-(pio2_lo+2c))
 *
 * Special cases:
 *	if x is NaN, return x itself;
 *	if |x|>1, return NaN with invalid signal.
 *
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

double __ieee754_asinS(double x)
{
    double t, w, p, q, c, r, s;
    int32_t hx, ix;

    static const double one = 1.00000000000000000000e+00; /* 0x3FF00000, 0x00000000 */
    static const double hugeval = 1.000e+300;
    static const double pio2_hi = 1.57079632679489655800e+00; /* 0x3FF921FB, 0x54442D18 */
    static const double pio2_lo = 6.12323399573676603587e-17; /* 0x3C91A626, 0x33145C07 */
    static const double pio4_hi = 7.85398163397448278999e-01; /* 0x3FE921FB, 0x54442D18 */
    /* coefficient for R(x^2) */
    static const double pS0 = 1.66666666666666657415e-01;  /* 0x3FC55555, 0x55555555 */
    static const double pS1 = -3.25565818622400915405e-01; /* 0xBFD4D612, 0x03EB6F7D */
    static const double pS2 = 2.01212532134862925881e-01;  /* 0x3FC9C155, 0x0E884455 */
    static const double pS3 = -4.00555345006794114027e-02; /* 0xBFA48228, 0xB5688F3B */
    static const double pS4 = 7.91534994289814532176e-04;  /* 0x3F49EFE0, 0x7501B288 */
    static const double pS5 = 3.47933107596021167570e-05;  /* 0x3F023DE1, 0x0DFDF709 */
    static const double qS1 = -2.40339491173441421878e+00; /* 0xC0033A27, 0x1C8A2D4B */
    static const double qS2 = 2.02094576023350569471e+00;  /* 0x40002AE5, 0x9C598AC8 */
    static const double qS3 = -6.88283971605453293030e-01; /* 0xBFE6066C, 0x1B8D0159 */
    static const double qS4 = 7.70381505559019352791e-02;  /* 0x3FB3B8C5, 0xB12E9282 */

    GET_HIGH_WORD(hx, x);
    ix = hx & IC(0x7fffffff);
    if (ix >= IC(0x3ff00000))
    { /* |x|>= 1 */
        uint32_t lx;

        GET_LOW_WORD(lx, x);
        if (((ix - IC(0x3ff00000)) | lx) == 0)
        /* asin(1)=+-pi/2 with inexact */
        {
            double temp_var_for_ext_0;
            double temp_var_for_tac_4, temp_var_for_tac_5, temp_var_for_tac_6;
            double temp_var_for_const_8, temp_var_for_const_9;
            temp_var_for_tac_4 = x * pio2_hi;

            temp_var_for_tac_5 = x * pio2_lo;

            temp_var_for_tac_6 = temp_var_for_tac_4 + temp_var_for_tac_5;

            temp_var_for_ext_0 = temp_var_for_tac_6;

            computeDMul((Addr)&temp_var_for_tac_4,
                        {(Addr)&x, (Addr) & (temp_var_for_const_8 = pio2_hi)},
                        "/home/shijia/Public/testprogram/e_asin.c_e.c:94:30");
            computeDMul((Addr)&temp_var_for_tac_5,
                        {(Addr)&x, (Addr) & (temp_var_for_const_9 = pio2_lo)},
                        "/home/shijia/Public/testprogram/e_asin.c_e.c:94:44");
            computeDAdd((Addr)&temp_var_for_tac_6,
                        {(Addr)&temp_var_for_tac_4, (Addr)&temp_var_for_tac_5},
                        "/home/shijia/Public/testprogram/e_asin.c_e.c:94:40");
            AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_6,
                    "/home/shijia/Public/testprogram/e_asin.c_e.c:94:26");
            ;
            callExpStack.push(
                getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
            callExp++; /*identify the function is  add move tmpShadow*/
            return temp_var_for_ext_0;
        }

        double temp_var_for_ext_1;
        double temp_var_for_tac_7, temp_var_for_tac_8, temp_var_for_tac_9;
        temp_var_for_tac_7 = x - x;

        temp_var_for_tac_8 = x - x;

        temp_var_for_tac_9 = temp_var_for_tac_7 / temp_var_for_tac_8;

        temp_var_for_ext_1 = temp_var_for_tac_9;
        computeDSub((Addr)&temp_var_for_tac_7, {(Addr)&x, (Addr)&x},
                    "/home/shijia/Public/testprogram/e_asin.c_e.c:102:29");
        computeDSub((Addr)&temp_var_for_tac_8, {(Addr)&x, (Addr)&x},
                    "/home/shijia/Public/testprogram/e_asin.c_e.c:102:39");
        computeDDiv((Addr)&temp_var_for_tac_9,
                    {(Addr)&temp_var_for_tac_7, (Addr)&temp_var_for_tac_8},
                    "/home/shijia/Public/testprogram/e_asin.c_e.c:102:34");
        AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_9,
                "/home/shijia/Public/testprogram/e_asin.c_e.c:102:24");
        ;
        callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
        callExp++;                 /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_1; /* asin(|x|>1) is NaN */
    }
    else
    {
        if (ix < IC(0x3fe00000))
        { /* |x|<0.5 */
            if (ix < IC(0x3e400000))
            { /* if |x| < 2**-27 */
                if (hugeval + x > one)
                {
                    double temp_var_for_ext_2;
                    temp_var_for_ext_2 = x;
                   AssignD({(Addr)&temp_var_for_ext_2}, (Addr)&x,
                            "/home/shijia/Public/testprogram/e_asin.c_e.c:111:30");
                    ;
                    callExpStack.push(
                        getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
                    callExp++; /*identify the function is  add move tmpShadow*/
                    return temp_var_for_ext_2;
                }
                /* return x with inexact if x!=0 */
            }
            else
            {
                double temp_var_for_ext_3;
                double temp_var_for_tac_12;
                temp_var_for_tac_12 = x * x;

                temp_var_for_ext_3 = temp_var_for_tac_12;
                computeDMul((Addr)&temp_var_for_tac_12, {(Addr)&x, (Addr)&x},
                            "/home/shijia/Public/testprogram/e_asin.c_e.c:120:32");
                AssignD({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_12,
                        "/home/shijia/Public/testprogram/e_asin.c_e.c:120:28");
                ; // t
                  /*(r_ext_0)(r)(rn temp)(t)(rn
           * temp)(t)(r_ext_0)(r)(_)(_)(a)(m)(a)(m)(_)(_)(x)(hugeval)(x)(x)*/
                t = temp_var_for_ext_3;
                AssignD({(Addr)&t}, (Addr)&temp_var_for_ext_3,
                        "/home/shijia/Public/testprogram/e_asin.c_e.c:123:11");
                ;
                double temp_var_for_tac_13, temp_var_for_tac_14, temp_var_for_tac_15,
                    temp_var_for_tac_16, temp_var_for_tac_17, temp_var_for_tac_18,
                    temp_var_for_tac_19, temp_var_for_tac_20, temp_var_for_tac_21,
                    temp_var_for_tac_22, temp_var_for_tac_23;
                double temp_var_for_const_12, temp_var_for_const_13,
                    temp_var_for_const_14, temp_var_for_const_15, temp_var_for_const_16,
                    temp_var_for_const_17;
                temp_var_for_tac_13 = t * pS5;

                temp_var_for_tac_14 = pS4 + temp_var_for_tac_13;

                temp_var_for_tac_15 = t * temp_var_for_tac_14;

                temp_var_for_tac_16 = pS3 + temp_var_for_tac_15;

                temp_var_for_tac_17 = t * temp_var_for_tac_16;

                temp_var_for_tac_18 = pS2 + temp_var_for_tac_17;

                temp_var_for_tac_19 = t * temp_var_for_tac_18;

                temp_var_for_tac_20 = pS1 + temp_var_for_tac_19;

                temp_var_for_tac_21 = t * temp_var_for_tac_20;

                temp_var_for_tac_22 = pS0 + temp_var_for_tac_21;

                temp_var_for_tac_23 = t * temp_var_for_tac_22;

                p = temp_var_for_tac_23;
                computeDMul((Addr)&temp_var_for_tac_13,
                            {(Addr)&t, (Addr) & (temp_var_for_const_12 = pS5)},
                            "/home/shijia/Public/testprogram/e_asin.c_e.c:124:70");
                computeDAdd(
                    (Addr)&temp_var_for_tac_14,
                    {(Addr) & (temp_var_for_const_13 = pS4), (Addr)&temp_var_for_tac_13},
                    "/home/shijia/Public/testprogram/e_asin.c_e.c:124:66");
                computeDMul((Addr)&temp_var_for_tac_15,
                            {(Addr)&t, (Addr)&temp_var_for_tac_14},
                            "/home/shijia/Public/testprogram/e_asin.c_e.c:124:59");
                computeDAdd(
                    (Addr)&temp_var_for_tac_16,
                    {(Addr) & (temp_var_for_const_14 = pS3), (Addr)&temp_var_for_tac_15},
                    "/home/shijia/Public/testprogram/e_asin.c_e.c:124:55");
                computeDMul((Addr)&temp_var_for_tac_17,
                            {(Addr)&t, (Addr)&temp_var_for_tac_16},
                            "/home/shijia/Public/testprogram/e_asin.c_e.c:124:48");
                computeDAdd(
                    (Addr)&temp_var_for_tac_18,
                    {(Addr) & (temp_var_for_const_15 = pS2), (Addr)&temp_var_for_tac_17},
                    "/home/shijia/Public/testprogram/e_asin.c_e.c:124:44");
                computeDMul((Addr)&temp_var_for_tac_19,
                            {(Addr)&t, (Addr)&temp_var_for_tac_18},
                            "/home/shijia/Public/testprogram/e_asin.c_e.c:124:37");
                computeDAdd(
                    (Addr)&temp_var_for_tac_20,
                    {(Addr) & (temp_var_for_const_16 = pS1), (Addr)&temp_var_for_tac_19},
                    "/home/shijia/Public/testprogram/e_asin.c_e.c:124:33");
                computeDMul((Addr)&temp_var_for_tac_21,
                            {(Addr)&t, (Addr)&temp_var_for_tac_20},
                            "/home/shijia/Public/testprogram/e_asin.c_e.c:124:26");
                computeDAdd(
                    (Addr)&temp_var_for_tac_22,
                    {(Addr) & (temp_var_for_const_17 = pS0), (Addr)&temp_var_for_tac_21},
                    "/home/shijia/Public/testprogram/e_asin.c_e.c:124:22");
                computeDMul((Addr)&temp_var_for_tac_23,
                            {(Addr)&t, (Addr)&temp_var_for_tac_22},
                            "/home/shijia/Public/testprogram/e_asin.c_e.c:124:15");
                AssignD({(Addr)&p}, (Addr)&temp_var_for_tac_23,
                        "/home/shijia/Public/testprogram/e_asin.c_e.c:124:11");
                ;
                double temp_var_for_tac_24, temp_var_for_tac_25, temp_var_for_tac_26,
                    temp_var_for_tac_27, temp_var_for_tac_28, temp_var_for_tac_29,
                    temp_var_for_tac_30, temp_var_for_tac_31;
                double temp_var_for_const_18, temp_var_for_const_19,
                    temp_var_for_const_20, temp_var_for_const_21, temp_var_for_const_22;
                temp_var_for_tac_24 = t * qS4;

                temp_var_for_tac_25 = qS3 + temp_var_for_tac_24;

                temp_var_for_tac_26 = t * temp_var_for_tac_25;

                temp_var_for_tac_27 = qS2 + temp_var_for_tac_26;

                temp_var_for_tac_28 = t * temp_var_for_tac_27;

                temp_var_for_tac_29 = qS1 + temp_var_for_tac_28;

                temp_var_for_tac_30 = t * temp_var_for_tac_29;

                temp_var_for_tac_31 = one + temp_var_for_tac_30;

                q = temp_var_for_tac_31;
                computeDMul((Addr)&temp_var_for_tac_24,
                            {(Addr)&t, (Addr) & (temp_var_for_const_18 = qS4)},
                            "/home/shijia/Public/testprogram/e_asin.c_e.c:125:54");
                computeDAdd(
                    (Addr)&temp_var_for_tac_25,
                    {(Addr) & (temp_var_for_const_19 = qS3), (Addr)&temp_var_for_tac_24},
                    "/home/shijia/Public/testprogram/e_asin.c_e.c:125:50");
                computeDMul((Addr)&temp_var_for_tac_26,
                            {(Addr)&t, (Addr)&temp_var_for_tac_25},
                            "/home/shijia/Public/testprogram/e_asin.c_e.c:125:43");
                computeDAdd(
                    (Addr)&temp_var_for_tac_27,
                    {(Addr) & (temp_var_for_const_20 = qS2), (Addr)&temp_var_for_tac_26},
                    "/home/shijia/Public/testprogram/e_asin.c_e.c:125:39");
                computeDMul((Addr)&temp_var_for_tac_28,
                            {(Addr)&t, (Addr)&temp_var_for_tac_27},
                            "/home/shijia/Public/testprogram/e_asin.c_e.c:125:32");
                computeDAdd(
                    (Addr)&temp_var_for_tac_29,
                    {(Addr) & (temp_var_for_const_21 = qS1), (Addr)&temp_var_for_tac_28},
                    "/home/shijia/Public/testprogram/e_asin.c_e.c:125:28");
                computeDMul((Addr)&temp_var_for_tac_30,
                            {(Addr)&t, (Addr)&temp_var_for_tac_29},
                            "/home/shijia/Public/testprogram/e_asin.c_e.c:125:21");
                computeDAdd(
                    (Addr)&temp_var_for_tac_31,
                    {(Addr) & (temp_var_for_const_22 = one), (Addr)&temp_var_for_tac_30},
                    "/home/shijia/Public/testprogram/e_asin.c_e.c:125:17");
                AssignD({(Addr)&q}, (Addr)&temp_var_for_tac_31,
                        "/home/shijia/Public/testprogram/e_asin.c_e.c:125:11");
                ;
                double temp_var_for_tac_32;
                temp_var_for_tac_32 = p / q;

                w = temp_var_for_tac_32;
                computeDDiv((Addr)&temp_var_for_tac_32, {(Addr)&p, (Addr)&q},
                            "/home/shijia/Public/testprogram/e_asin.c_e.c:126:15");
                AssignD({(Addr)&w}, (Addr)&temp_var_for_tac_32,
                        "/home/shijia/Public/testprogram/e_asin.c_e.c:126:11");
                ;
                double temp_var_for_ext_4;
                double temp_var_for_tac_33, temp_var_for_tac_34;
                temp_var_for_tac_33 = x * w;

                temp_var_for_tac_34 = x + temp_var_for_tac_33;

                temp_var_for_ext_4 = temp_var_for_tac_34;
                computeDMul((Addr)&temp_var_for_tac_33, {(Addr)&x, (Addr)&w},
                            "/home/shijia/Public/testprogram/e_asin.c_e.c:128:36");
                computeDAdd((Addr)&temp_var_for_tac_34,
                            {(Addr)&x, (Addr)&temp_var_for_tac_33},
                            "/home/shijia/Public/testprogram/e_asin.c_e.c:128:32");
                AssignD({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_34,
                        "/home/shijia/Public/testprogram/e_asin.c_e.c:128:28");
                ;
                callExpStack.push(
                    getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
                callExp++; /*identify the function is  add move tmpShadow*/
                return temp_var_for_ext_4;
            }
        }
    }

    /* 1> |x|>= 0.5 */
    double temp_var_for_tac_35;
    double temp_var_for_const_23, temp_var_for_const_24;
    double temp_var_for_callexp_0;

    temp_var_for_callexp_0 = fabs(x);
    temp_var_for_tac_35 = one - temp_var_for_callexp_0;

    w = temp_var_for_tac_35;
    computeDSub((Addr)&temp_var_for_tac_35,
                {(Addr) & (temp_var_for_const_24 = one),
                 (Addr) & (temp_var_for_const_23 = temp_var_for_callexp_0)},
                "/home/shijia/Public/testprogram/e_asin.c_e.c:138:11");
    AssignD({(Addr)&w}, (Addr)&temp_var_for_tac_35,
            "/home/shijia/Public/testprogram/e_asin.c_e.c:138:5");
    ;
    double temp_var_for_tac_36;
    double temp_var_for_const_25;
    temp_var_for_tac_36 = w * 0.5;

    t = temp_var_for_tac_36;
    computeDMul((Addr)&temp_var_for_tac_36,
                {(Addr)&w, (Addr) & (temp_var_for_const_25 = 0.5)},
                "/home/shijia/Public/testprogram/e_asin.c_e.c:139:9");
    AssignD({(Addr)&t}, (Addr)&temp_var_for_tac_36,
            "/home/shijia/Public/testprogram/e_asin.c_e.c:139:5");
    ;
    double temp_var_for_tac_37, temp_var_for_tac_38, temp_var_for_tac_39,
        temp_var_for_tac_40, temp_var_for_tac_41, temp_var_for_tac_42,
        temp_var_for_tac_43, temp_var_for_tac_44, temp_var_for_tac_45,
        temp_var_for_tac_46, temp_var_for_tac_47;
    double temp_var_for_const_26, temp_var_for_const_27, temp_var_for_const_28,
        temp_var_for_const_29, temp_var_for_const_30, temp_var_for_const_31;
    temp_var_for_tac_37 = t * pS5;

    temp_var_for_tac_38 = pS4 + temp_var_for_tac_37;

    temp_var_for_tac_39 = t * temp_var_for_tac_38;

    temp_var_for_tac_40 = pS3 + temp_var_for_tac_39;

    temp_var_for_tac_41 = t * temp_var_for_tac_40;

    temp_var_for_tac_42 = pS2 + temp_var_for_tac_41;

    temp_var_for_tac_43 = t * temp_var_for_tac_42;

    temp_var_for_tac_44 = pS1 + temp_var_for_tac_43;

    temp_var_for_tac_45 = t * temp_var_for_tac_44;

    temp_var_for_tac_46 = pS0 + temp_var_for_tac_45;

    temp_var_for_tac_47 = t * temp_var_for_tac_46;

    p = temp_var_for_tac_47;
    computeDMul((Addr)&temp_var_for_tac_37,
                {(Addr)&t, (Addr) & (temp_var_for_const_26 = pS5)},
                "/home/shijia/Public/testprogram/e_asin.c_e.c:140:64");
    computeDAdd(
        (Addr)&temp_var_for_tac_38,
        {(Addr) & (temp_var_for_const_27 = pS4), (Addr)&temp_var_for_tac_37},
        "/home/shijia/Public/testprogram/e_asin.c_e.c:140:60");
    computeDMul((Addr)&temp_var_for_tac_39,
                {(Addr)&t, (Addr)&temp_var_for_tac_38},
                "/home/shijia/Public/testprogram/e_asin.c_e.c:140:53");
    computeDAdd(
        (Addr)&temp_var_for_tac_40,
        {(Addr) & (temp_var_for_const_28 = pS3), (Addr)&temp_var_for_tac_39},
        "/home/shijia/Public/testprogram/e_asin.c_e.c:140:49");
    computeDMul((Addr)&temp_var_for_tac_41,
                {(Addr)&t, (Addr)&temp_var_for_tac_40},
                "/home/shijia/Public/testprogram/e_asin.c_e.c:140:42");
    computeDAdd(
        (Addr)&temp_var_for_tac_42,
        {(Addr) & (temp_var_for_const_29 = pS2), (Addr)&temp_var_for_tac_41},
        "/home/shijia/Public/testprogram/e_asin.c_e.c:140:38");
    computeDMul((Addr)&temp_var_for_tac_43,
                {(Addr)&t, (Addr)&temp_var_for_tac_42},
                "/home/shijia/Public/testprogram/e_asin.c_e.c:140:31");
    computeDAdd(
        (Addr)&temp_var_for_tac_44,
        {(Addr) & (temp_var_for_const_30 = pS1), (Addr)&temp_var_for_tac_43},
        "/home/shijia/Public/testprogram/e_asin.c_e.c:140:27");
    computeDMul((Addr)&temp_var_for_tac_45,
                {(Addr)&t, (Addr)&temp_var_for_tac_44},
                "/home/shijia/Public/testprogram/e_asin.c_e.c:140:20");
    computeDAdd(
        (Addr)&temp_var_for_tac_46,
        {(Addr) & (temp_var_for_const_31 = pS0), (Addr)&temp_var_for_tac_45},
        "/home/shijia/Public/testprogram/e_asin.c_e.c:140:16");
    computeDMul((Addr)&temp_var_for_tac_47,
                {(Addr)&t, (Addr)&temp_var_for_tac_46},
                "/home/shijia/Public/testprogram/e_asin.c_e.c:140:9");
    AssignD({(Addr)&p}, (Addr)&temp_var_for_tac_47,
            "/home/shijia/Public/testprogram/e_asin.c_e.c:140:5");
    ;
    double temp_var_for_tac_48, temp_var_for_tac_49, temp_var_for_tac_50,
        temp_var_for_tac_51, temp_var_for_tac_52, temp_var_for_tac_53,
        temp_var_for_tac_54, temp_var_for_tac_55;
    double temp_var_for_const_32, temp_var_for_const_33, temp_var_for_const_34,
        temp_var_for_const_35, temp_var_for_const_36;
    temp_var_for_tac_48 = t * qS4;

    temp_var_for_tac_49 = qS3 + temp_var_for_tac_48;

    temp_var_for_tac_50 = t * temp_var_for_tac_49;

    temp_var_for_tac_51 = qS2 + temp_var_for_tac_50;

    temp_var_for_tac_52 = t * temp_var_for_tac_51;

    temp_var_for_tac_53 = qS1 + temp_var_for_tac_52;

    temp_var_for_tac_54 = t * temp_var_for_tac_53;

    temp_var_for_tac_55 = one + temp_var_for_tac_54;

    q = temp_var_for_tac_55;
    computeDMul((Addr)&temp_var_for_tac_48,
                {(Addr)&t, (Addr) & (temp_var_for_const_32 = qS4)},
                "/home/shijia/Public/testprogram/e_asin.c_e.c:141:48");
    computeDAdd(
        (Addr)&temp_var_for_tac_49,
        {(Addr) & (temp_var_for_const_33 = qS3), (Addr)&temp_var_for_tac_48},
        "/home/shijia/Public/testprogram/e_asin.c_e.c:141:44");
    computeDMul((Addr)&temp_var_for_tac_50,
                {(Addr)&t, (Addr)&temp_var_for_tac_49},
                "/home/shijia/Public/testprogram/e_asin.c_e.c:141:37");
    computeDAdd(
        (Addr)&temp_var_for_tac_51,
        {(Addr) & (temp_var_for_const_34 = qS2), (Addr)&temp_var_for_tac_50},
        "/home/shijia/Public/testprogram/e_asin.c_e.c:141:33");
    computeDMul((Addr)&temp_var_for_tac_52,
                {(Addr)&t, (Addr)&temp_var_for_tac_51},
                "/home/shijia/Public/testprogram/e_asin.c_e.c:141:26");
    computeDAdd(
        (Addr)&temp_var_for_tac_53,
        {(Addr) & (temp_var_for_const_35 = qS1), (Addr)&temp_var_for_tac_52},
        "/home/shijia/Public/testprogram/e_asin.c_e.c:141:22");
    computeDMul((Addr)&temp_var_for_tac_54,
                {(Addr)&t, (Addr)&temp_var_for_tac_53},
                "/home/shijia/Public/testprogram/e_asin.c_e.c:141:15");
    computeDAdd(
        (Addr)&temp_var_for_tac_55,
        {(Addr) & (temp_var_for_const_36 = one), (Addr)&temp_var_for_tac_54},
        "/home/shijia/Public/testprogram/e_asin.c_e.c:141:11");
    AssignD({(Addr)&q}, (Addr)&temp_var_for_tac_55,
            "/home/shijia/Public/testprogram/e_asin.c_e.c:141:5");
    ;
    double temp_var_for_const_37;
    double temp_var_for_callexp_1;

    temp_var_for_callexp_1 = __ieee754_sqrt(t);
    s = temp_var_for_callexp_1;
    AssignD({(Addr)&s}, (Addr) & (temp_var_for_const_37 = temp_var_for_callexp_1),
            "/home/shijia/Public/testprogram/e_asin.c_e.c:142:5");
    ;
    if (ix >= IC(0x3FEF3333))
    { /* if |x| > 0.975 */
        double temp_var_for_tac_56;
        temp_var_for_tac_56 = p / q;

        w = temp_var_for_tac_56;
        computeDDiv((Addr)&temp_var_for_tac_56, {(Addr)&p, (Addr)&q},
                    "/home/shijia/Public/testprogram/e_asin.c_e.c:144:11");
        AssignD({(Addr)&w}, (Addr)&temp_var_for_tac_56,
                "/home/shijia/Public/testprogram/e_asin.c_e.c:144:7");
        ;
        double temp_var_for_tac_57, temp_var_for_tac_58, temp_var_for_tac_59,
            temp_var_for_tac_60, temp_var_for_tac_61;
        double temp_var_for_const_38, temp_var_for_const_39, temp_var_for_const_40;
        temp_var_for_tac_57 = s * w;

        temp_var_for_tac_58 = s + temp_var_for_tac_57;

        temp_var_for_tac_59 = 2.0 * temp_var_for_tac_58;

        temp_var_for_tac_60 = temp_var_for_tac_59 - pio2_lo;

        temp_var_for_tac_61 = pio2_hi - temp_var_for_tac_60;

        t = temp_var_for_tac_61;
        computeDMul((Addr)&temp_var_for_tac_57, {(Addr)&s, (Addr)&w},
                    "/home/shijia/Public/testprogram/e_asin.c_e.c:145:33");
        computeDAdd((Addr)&temp_var_for_tac_58,
                    {(Addr)&s, (Addr)&temp_var_for_tac_57},
                    "/home/shijia/Public/testprogram/e_asin.c_e.c:145:29");
        computeDMul(
            (Addr)&temp_var_for_tac_59,
            {(Addr) & (temp_var_for_const_38 = 2.0), (Addr)&temp_var_for_tac_58},
            "/home/shijia/Public/testprogram/e_asin.c_e.c:145:24");
        computeDSub(
            (Addr)&temp_var_for_tac_60,
            {(Addr)&temp_var_for_tac_59, (Addr) & (temp_var_for_const_39 = pio2_lo)},
            "/home/shijia/Public/testprogram/e_asin.c_e.c:145:38");
        computeDSub(
            (Addr)&temp_var_for_tac_61,
            {(Addr) & (temp_var_for_const_40 = pio2_hi), (Addr)&temp_var_for_tac_60},
            "/home/shijia/Public/testprogram/e_asin.c_e.c:145:17");
        AssignD({(Addr)&t}, (Addr)&temp_var_for_tac_61,
                "/home/shijia/Public/testprogram/e_asin.c_e.c:145:7");
        ;
    }
    else
    {
        double temp_var_for_ext_5;
        temp_var_for_ext_5 = s;
        AssignD({(Addr)&temp_var_for_ext_5}, (Addr)&s,
                "/home/shijia/Public/testprogram/e_asin.c_e.c:148:24");
        ; // w
        /*(pio2_lo)(w)(s)(s)(2.0)(pio2_hi)(pio2_lo)(w)(s)(s)(2.0)(w)(s)(s)(2.0)(w)(s)(s)(w)(s)(s)*/
        w = temp_var_for_ext_5;
        AssignD({(Addr)&w}, (Addr)&temp_var_for_ext_5,
                "/home/shijia/Public/testprogram/e_asin.c_e.c:150:7");
        ;
        SET_LOW_WORD(w, 0);
        double temp_var_for_tac_62, temp_var_for_tac_63, temp_var_for_tac_64,
            temp_var_for_tac_65;
        temp_var_for_tac_62 = w * w;

        temp_var_for_tac_63 = t - temp_var_for_tac_62;

        temp_var_for_tac_64 = s + w;

        temp_var_for_tac_65 = temp_var_for_tac_63 / temp_var_for_tac_64;

        c = temp_var_for_tac_65;
        computeDMul((Addr)&temp_var_for_tac_62, {(Addr)&w, (Addr)&w},
                    "/home/shijia/Public/testprogram/e_asin.c_e.c:152:16");
        computeDSub((Addr)&temp_var_for_tac_63,
                    {(Addr)&t, (Addr)&temp_var_for_tac_62},
                    "/home/shijia/Public/testprogram/e_asin.c_e.c:152:12");
        computeDAdd((Addr)&temp_var_for_tac_64, {(Addr)&s, (Addr)&w},
                    "/home/shijia/Public/testprogram/e_asin.c_e.c:152:26");
        computeDDiv((Addr)&temp_var_for_tac_65,
                    {(Addr)&temp_var_for_tac_63, (Addr)&temp_var_for_tac_64},
                    "/home/shijia/Public/testprogram/e_asin.c_e.c:152:21");
        AssignD({(Addr)&c}, (Addr)&temp_var_for_tac_65,
                "/home/shijia/Public/testprogram/e_asin.c_e.c:152:7");
        ;
        double temp_var_for_tac_66;
        temp_var_for_tac_66 = p / q;

        r = temp_var_for_tac_66;
        computeDDiv((Addr)&temp_var_for_tac_66, {(Addr)&p, (Addr)&q},
                    "/home/shijia/Public/testprogram/e_asin.c_e.c:153:11");
        AssignD({(Addr)&r}, (Addr)&temp_var_for_tac_66,
                "/home/shijia/Public/testprogram/e_asin.c_e.c:153:7");
        ;
        double temp_var_for_ext_6;
        double temp_var_for_tac_67, temp_var_for_tac_68, temp_var_for_tac_69,
            temp_var_for_tac_70, temp_var_for_tac_71;
        double temp_var_for_const_41, temp_var_for_const_42, temp_var_for_const_43;
        temp_var_for_tac_67 = 2.0 * s;

        temp_var_for_tac_68 = temp_var_for_tac_67 * r;

        temp_var_for_tac_69 = 2.0 * c;

        temp_var_for_tac_70 = pio2_lo - temp_var_for_tac_69;

        temp_var_for_tac_71 = temp_var_for_tac_68 - temp_var_for_tac_70;

        temp_var_for_ext_6 = temp_var_for_tac_71;
        computeDMul((Addr)&temp_var_for_tac_67,
                    {(Addr) & (temp_var_for_const_41 = 2.0), (Addr)&s},
                    "/home/shijia/Public/testprogram/e_asin.c_e.c:155:30");
        computeDMul((Addr)&temp_var_for_tac_68,
                    {(Addr)&temp_var_for_tac_67, (Addr)&r},
                    "/home/shijia/Public/testprogram/e_asin.c_e.c:155:34");
        computeDMul((Addr)&temp_var_for_tac_69,
                    {(Addr) & (temp_var_for_const_42 = 2.0), (Addr)&c},
                    "/home/shijia/Public/testprogram/e_asin.c_e.c:155:55");
        computeDSub(
            (Addr)&temp_var_for_tac_70,
            {(Addr) & (temp_var_for_const_43 = pio2_lo), (Addr)&temp_var_for_tac_69},
            "/home/shijia/Public/testprogram/e_asin.c_e.c:155:49");
        computeDSub((Addr)&temp_var_for_tac_71,
                    {(Addr)&temp_var_for_tac_68, (Addr)&temp_var_for_tac_70},
                    "/home/shijia/Public/testprogram/e_asin.c_e.c:155:38");
        AssignD({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_71,
                "/home/shijia/Public/testprogram/e_asin.c_e.c:155:24");
        ; // p
        /*(q)(p)(c)(2.0)(pio2_lo)(r)(s)(2.0)*/
        p = temp_var_for_ext_6;
        AssignD({(Addr)&p}, (Addr)&temp_var_for_ext_6,
                "/home/shijia/Public/testprogram/e_asin.c_e.c:157:7");
        ;
        double temp_var_for_tac_72, temp_var_for_tac_73;
        double temp_var_for_const_44, temp_var_for_const_45;
        temp_var_for_tac_72 = 2.0 * w;

        temp_var_for_tac_73 = pio4_hi - temp_var_for_tac_72;

        q = temp_var_for_tac_73;
        computeDMul((Addr)&temp_var_for_tac_72,
                    {(Addr) & (temp_var_for_const_44 = 2.0), (Addr)&w},
                    "/home/shijia/Public/testprogram/e_asin.c_e.c:158:23");
        computeDSub(
            (Addr)&temp_var_for_tac_73,
            {(Addr) & (temp_var_for_const_45 = pio4_hi), (Addr)&temp_var_for_tac_72},
            "/home/shijia/Public/testprogram/e_asin.c_e.c:158:17");
        AssignD({(Addr)&q}, (Addr)&temp_var_for_tac_73,
                "/home/shijia/Public/testprogram/e_asin.c_e.c:158:7");
        ;
        double temp_var_for_tac_74, temp_var_for_tac_75;
        double temp_var_for_const_46;
        temp_var_for_tac_74 = p - q;

        temp_var_for_tac_75 = pio4_hi - temp_var_for_tac_74;

        t = temp_var_for_tac_75;
        computeDSub((Addr)&temp_var_for_tac_74, {(Addr)&p, (Addr)&q},
                    "/home/shijia/Public/testprogram/e_asin.c_e.c:159:22");
        computeDSub(
            (Addr)&temp_var_for_tac_75,
            {(Addr) & (temp_var_for_const_46 = pio4_hi), (Addr)&temp_var_for_tac_74},
            "/home/shijia/Public/testprogram/e_asin.c_e.c:159:17");
        AssignD({(Addr)&t}, (Addr)&temp_var_for_tac_75,
                "/home/shijia/Public/testprogram/e_asin.c_e.c:159:7");
        ;
    }
    if (hx > 0)
    {
        double temp_var_for_ext_7;
        temp_var_for_ext_7 = t;
        AssignD({(Addr)&temp_var_for_ext_7}, (Addr)&t,
                "/home/shijia/Public/testprogram/e_asin.c_e.c:163:24");
        ;
        callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_7;
    }

    double temp_var_for_ext_8;
    double temp_var_for_const_47;
    temp_var_for_ext_8 = (-(t));
    AssignD({(Addr)&temp_var_for_ext_8}, (Addr) & (temp_var_for_const_47 = (-(t))),
            "/home/shijia/Public/testprogram/e_asin.c_e.c:170:22");
    ;
    callExpStack.push(getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
    callExp++; /*identify the function is  add move tmpShadow*/
    return (temp_var_for_ext_8);
}
int main()
{
        std::ifstream inputFile("/home/shijia/Public/FpDebug-valgrind_3.12/valgrind/fpdebug/pso/exe-input/asin_t.txt", std::ios::in);
        double input;
        long double oracle, realError = 0.0, scError = 0.0, prealError = 0.0, pscError = 0.0;
        long double delta = 1.0e-20;
        int index, la = 0, eq = 0, sm = 0;
        std::ifstream inputOracle("/home/shijia/Public/FpDebug-valgrind_3.12/valgrind/fpdebug/pso/mpfr/mpfrresults/asin_out.txt", std::ios::in);
        while (inputFile >> input)
        {
                double a = __ieee754_asinS(input);
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