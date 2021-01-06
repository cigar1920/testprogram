#include "../ScDebug/scdebug.h"
/* @(#)e_acos.c 1.3 95/01/18 */
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

/* __ieee754_acos(x)
 * Method :
 *	acos(x)  = pi/2 - asin(x)
 *	acos(-x) = pi/2 + asin(x)
 * For |x|<=0.5
 *	acos(x) = pi/2 - (x + x*x^2*R(x^2))	(see asin.c)
 * For x>0.5
 * 	acos(x) = pi/2 - (pi/2 - 2asin(sqrt((1-x)/2)))
 *		= 2asin(sqrt((1-x)/2))
 *		= 2s + 2s*z*R(z) 	...z=(1-x)/2, s=sqrt(z)
 *		= 2f + (2c + 2s*z*R(z))
 *     where f=hi part of s, and c = (z-f*f)/(s+f) is the correction term
 *     for f so that f+c ~ sqrt(z).
 * For x<-0.5
 *	acos(x) = pi - 2asin(sqrt((1-|x|)/2))
 *		= pi - 0.5*(s+s*z*R(z)), where z=(1-|x|)/2,s=sqrt(z)
 *
 * Special cases:
 *	if x is NaN, return x itself;
 *	if |x|>1, return NaN with invalid signal.
 *
 * Function needed: sqrt
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

double __ieee754_acosS(double x)
{
    double z, p, q, r, w, s, c, df;
    int32_t hx, ix;

    static const double one = 1.00000000000000000000e+00;     /* 0x3FF00000, 0x00000000 */
    static const double pi = 3.14159265358979311600e+00;      /* 0x400921FB, 0x54442D18 */
    static const double pio2_hi = 1.57079632679489655800e+00; /* 0x3FF921FB, 0x54442D18 */
    static const double pio2_lo = 6.12323399573676603587e-17; /* 0x3C91A626, 0x33145C07 */
    static const double pS0 = 1.66666666666666657415e-01;     /* 0x3FC55555, 0x55555555 */
    static const double pS1 = -3.25565818622400915405e-01;    /* 0xBFD4D612, 0x03EB6F7D */
    static const double pS2 = 2.01212532134862925881e-01;     /* 0x3FC9C155, 0x0E884455 */
    static const double pS3 = -4.00555345006794114027e-02;    /* 0xBFA48228, 0xB5688F3B */
    static const double pS4 = 7.91534994289814532176e-04;     /* 0x3F49EFE0, 0x7501B288 */
    static const double pS5 = 3.47933107596021167570e-05;     /* 0x3F023DE1, 0x0DFDF709 */
    static const double qS1 = -2.40339491173441421878e+00;    /* 0xC0033A27, 0x1C8A2D4B */
    static const double qS2 = 2.02094576023350569471e+00;     /* 0x40002AE5, 0x9C598AC8 */
    static const double qS3 = -6.88283971605453293030e-01;    /* 0xBFE6066C, 0x1B8D0159 */
    static const double qS4 = 7.70381505559019352791e-02;     /* 0x3FB3B8C5, 0xB12E9282 */

    GET_HIGH_WORD(hx, x);
    ix = hx & IC(0x7fffffff);
    if (ix >= IC(0x3ff00000))
    { /* |x| >= 1 */
        uint32_t lx;

        GET_LOW_WORD(lx, x);
        if (((ix - IC(0x3ff00000)) | lx) == 0)
        { /* |x|==1 */
            if (hx > 0)
            {
                double temp_var_for_ext_0;
                double temp_var_for_const_8;
                temp_var_for_ext_0 = 0.0;
                AssignD({(Addr)&temp_var_for_ext_0},
                        (Addr) & (temp_var_for_const_8 = 0.0),
                        "/home/shijia/Public/testprogram/e_acos.c_e.c:85:28");
                ;
                callExpStack.push(
                    getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
                callExp++; /*identify the function is  add move tmpShadow*/
                return temp_var_for_ext_0;
            }
            /* acos(1) = 0  */
            else
            {
                double temp_var_for_ext_1;
                double temp_var_for_tac_4, temp_var_for_tac_5;
                double temp_var_for_const_9, temp_var_for_const_10,
                    temp_var_for_const_11;
                temp_var_for_tac_4 = 2.0 * pio2_lo;

                temp_var_for_tac_5 = pi + temp_var_for_tac_4;

                temp_var_for_ext_1 = temp_var_for_tac_5;
                computeDMul((Addr)&temp_var_for_tac_4,
                            {(Addr) & (temp_var_for_const_10 = 2.0),
                             (Addr) & (temp_var_for_const_9 = pio2_lo)},
                            "/home/shijia/Public/testprogram/e_acos.c_e.c:94:39");
                computeDAdd(
                    (Addr)&temp_var_for_tac_5,
                    {(Addr) & (temp_var_for_const_11 = pi), (Addr)&temp_var_for_tac_4},
                    "/home/shijia/Public/testprogram/e_acos.c_e.c:94:33");
                AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_5,
                        "/home/shijia/Public/testprogram/e_acos.c_e.c:94:28");
                ;
                callExpStack.push(
                    getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
                callExp++; /*identify the function is  add move tmpShadow*/
                return temp_var_for_ext_1;
            }
            /* acos(-1)= pi */
        }
        double temp_var_for_ext_2;
        double temp_var_for_tac_6, temp_var_for_tac_7, temp_var_for_tac_8;
        temp_var_for_tac_6 = x - x;

        temp_var_for_tac_7 = x - x;

        temp_var_for_tac_8 = temp_var_for_tac_6 / temp_var_for_tac_7;

        temp_var_for_ext_2 = temp_var_for_tac_8;
        computeDSub((Addr)&temp_var_for_tac_6, {(Addr)&x, (Addr)&x},
                    "/home/shijia/Public/testprogram/e_acos.c_e.c:103:29");
        computeDSub((Addr)&temp_var_for_tac_7, {(Addr)&x, (Addr)&x},
                    "/home/shijia/Public/testprogram/e_acos.c_e.c:103:39");
        computeDDiv((Addr)&temp_var_for_tac_8,
                    {(Addr)&temp_var_for_tac_6, (Addr)&temp_var_for_tac_7},
                    "/home/shijia/Public/testprogram/e_acos.c_e.c:103:34");
        AssignD({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_8,
                "/home/shijia/Public/testprogram/e_acos.c_e.c:103:24");
        ;
        callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
        callExp++;                 /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_2; /* acos(|x|>1) is NaN */
    }

    if (ix < IC(0x3fe00000))
    { /* |x| < 0.5 */
        if (ix <= IC(0x3c600000))
        {
            double temp_var_for_ext_3;
            double temp_var_for_tac_9;
            double temp_var_for_const_12, temp_var_for_const_13;
            temp_var_for_tac_9 = pio2_hi + pio2_lo;

            temp_var_for_ext_3 = temp_var_for_tac_9;
            computeDAdd((Addr)&temp_var_for_tac_9,
                        {(Addr) & (temp_var_for_const_13 = pio2_hi),
                         (Addr) & (temp_var_for_const_12 = pio2_lo)},
                        "/home/shijia/Public/testprogram/e_acos.c_e.c:112:36");
            AssignD({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_9,
                    "/home/shijia/Public/testprogram/e_acos.c_e.c:112:26");
            ;
            callExpStack.push(
                getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
            callExp++; /*identify the function is  add move tmpShadow*/
            return temp_var_for_ext_3;
        }
        /*if|x|<2**-57 */
        double temp_var_for_tac_10;
        temp_var_for_tac_10 = x * x;

        z = temp_var_for_tac_10;
        computeDMul((Addr)&temp_var_for_tac_10, {(Addr)&x, (Addr)&x},
                    "/home/shijia/Public/testprogram/e_acos.c_e.c:119:11");
        AssignD({(Addr)&z}, (Addr)&temp_var_for_tac_10,
                "/home/shijia/Public/testprogram/e_acos.c_e.c:119:7");
        ;
        double temp_var_for_tac_11, temp_var_for_tac_12, temp_var_for_tac_13,
            temp_var_for_tac_14, temp_var_for_tac_15, temp_var_for_tac_16,
            temp_var_for_tac_17, temp_var_for_tac_18, temp_var_for_tac_19,
            temp_var_for_tac_20, temp_var_for_tac_21;
        double temp_var_for_const_14, temp_var_for_const_15, temp_var_for_const_16,
            temp_var_for_const_17, temp_var_for_const_18, temp_var_for_const_19;
        temp_var_for_tac_11 = z * pS5;

        temp_var_for_tac_12 = pS4 + temp_var_for_tac_11;

        temp_var_for_tac_13 = z * temp_var_for_tac_12;

        temp_var_for_tac_14 = pS3 + temp_var_for_tac_13;

        temp_var_for_tac_15 = z * temp_var_for_tac_14;

        temp_var_for_tac_16 = pS2 + temp_var_for_tac_15;

        temp_var_for_tac_17 = z * temp_var_for_tac_16;

        temp_var_for_tac_18 = pS1 + temp_var_for_tac_17;

        temp_var_for_tac_19 = z * temp_var_for_tac_18;

        temp_var_for_tac_20 = pS0 + temp_var_for_tac_19;

        temp_var_for_tac_21 = z * temp_var_for_tac_20;

        p = temp_var_for_tac_21;
        computeDMul((Addr)&temp_var_for_tac_11,
                    {(Addr)&z, (Addr) & (temp_var_for_const_14 = pS5)},
                    "/home/shijia/Public/testprogram/e_acos.c_e.c:120:66");
        computeDAdd(
            (Addr)&temp_var_for_tac_12,
            {(Addr) & (temp_var_for_const_15 = pS4), (Addr)&temp_var_for_tac_11},
            "/home/shijia/Public/testprogram/e_acos.c_e.c:120:62");
        computeDMul((Addr)&temp_var_for_tac_13,
                    {(Addr)&z, (Addr)&temp_var_for_tac_12},
                    "/home/shijia/Public/testprogram/e_acos.c_e.c:120:55");
        computeDAdd(
            (Addr)&temp_var_for_tac_14,
            {(Addr) & (temp_var_for_const_16 = pS3), (Addr)&temp_var_for_tac_13},
            "/home/shijia/Public/testprogram/e_acos.c_e.c:120:51");
        computeDMul((Addr)&temp_var_for_tac_15,
                    {(Addr)&z, (Addr)&temp_var_for_tac_14},
                    "/home/shijia/Public/testprogram/e_acos.c_e.c:120:44");
        computeDAdd(
            (Addr)&temp_var_for_tac_16,
            {(Addr) & (temp_var_for_const_17 = pS2), (Addr)&temp_var_for_tac_15},
            "/home/shijia/Public/testprogram/e_acos.c_e.c:120:40");
        computeDMul((Addr)&temp_var_for_tac_17,
                    {(Addr)&z, (Addr)&temp_var_for_tac_16},
                    "/home/shijia/Public/testprogram/e_acos.c_e.c:120:33");
        computeDAdd(
            (Addr)&temp_var_for_tac_18,
            {(Addr) & (temp_var_for_const_18 = pS1), (Addr)&temp_var_for_tac_17},
            "/home/shijia/Public/testprogram/e_acos.c_e.c:120:29");
        computeDMul((Addr)&temp_var_for_tac_19,
                    {(Addr)&z, (Addr)&temp_var_for_tac_18},
                    "/home/shijia/Public/testprogram/e_acos.c_e.c:120:22");
        computeDAdd(
            (Addr)&temp_var_for_tac_20,
            {(Addr) & (temp_var_for_const_19 = pS0), (Addr)&temp_var_for_tac_19},
            "/home/shijia/Public/testprogram/e_acos.c_e.c:120:18");
        computeDMul((Addr)&temp_var_for_tac_21,
                    {(Addr)&z, (Addr)&temp_var_for_tac_20},
                    "/home/shijia/Public/testprogram/e_acos.c_e.c:120:11");
        AssignD({(Addr)&p}, (Addr)&temp_var_for_tac_21,
                "/home/shijia/Public/testprogram/e_acos.c_e.c:120:7");
        ;
        double temp_var_for_tac_22, temp_var_for_tac_23, temp_var_for_tac_24,
            temp_var_for_tac_25, temp_var_for_tac_26, temp_var_for_tac_27,
            temp_var_for_tac_28, temp_var_for_tac_29;
        double temp_var_for_const_20, temp_var_for_const_21, temp_var_for_const_22,
            temp_var_for_const_23, temp_var_for_const_24;
        temp_var_for_tac_22 = z * qS4;

        temp_var_for_tac_23 = qS3 + temp_var_for_tac_22;

        temp_var_for_tac_24 = z * temp_var_for_tac_23;

        temp_var_for_tac_25 = qS2 + temp_var_for_tac_24;

        temp_var_for_tac_26 = z * temp_var_for_tac_25;

        temp_var_for_tac_27 = qS1 + temp_var_for_tac_26;

        temp_var_for_tac_28 = z * temp_var_for_tac_27;

        temp_var_for_tac_29 = one + temp_var_for_tac_28;

        q = temp_var_for_tac_29;
        computeDMul((Addr)&temp_var_for_tac_22,
                    {(Addr)&z, (Addr) & (temp_var_for_const_20 = qS4)},
                    "/home/shijia/Public/testprogram/e_acos.c_e.c:121:50");
        computeDAdd(
            (Addr)&temp_var_for_tac_23,
            {(Addr) & (temp_var_for_const_21 = qS3), (Addr)&temp_var_for_tac_22},
            "/home/shijia/Public/testprogram/e_acos.c_e.c:121:46");
        computeDMul((Addr)&temp_var_for_tac_24,
                    {(Addr)&z, (Addr)&temp_var_for_tac_23},
                    "/home/shijia/Public/testprogram/e_acos.c_e.c:121:39");
        computeDAdd(
            (Addr)&temp_var_for_tac_25,
            {(Addr) & (temp_var_for_const_22 = qS2), (Addr)&temp_var_for_tac_24},
            "/home/shijia/Public/testprogram/e_acos.c_e.c:121:35");
        computeDMul((Addr)&temp_var_for_tac_26,
                    {(Addr)&z, (Addr)&temp_var_for_tac_25},
                    "/home/shijia/Public/testprogram/e_acos.c_e.c:121:28");
        computeDAdd(
            (Addr)&temp_var_for_tac_27,
            {(Addr) & (temp_var_for_const_23 = qS1), (Addr)&temp_var_for_tac_26},
            "/home/shijia/Public/testprogram/e_acos.c_e.c:121:24");
        computeDMul((Addr)&temp_var_for_tac_28,
                    {(Addr)&z, (Addr)&temp_var_for_tac_27},
                    "/home/shijia/Public/testprogram/e_acos.c_e.c:121:17");
        computeDAdd(
            (Addr)&temp_var_for_tac_29,
            {(Addr) & (temp_var_for_const_24 = one), (Addr)&temp_var_for_tac_28},
            "/home/shijia/Public/testprogram/e_acos.c_e.c:121:13");
        AssignD({(Addr)&q}, (Addr)&temp_var_for_tac_29,
                "/home/shijia/Public/testprogram/e_acos.c_e.c:121:7");
        ;
        double temp_var_for_tac_30;
        temp_var_for_tac_30 = p / q;

        r = temp_var_for_tac_30;
        computeDDiv((Addr)&temp_var_for_tac_30, {(Addr)&p, (Addr)&q},
                    "/home/shijia/Public/testprogram/e_acos.c_e.c:122:11");
        AssignD({(Addr)&r}, (Addr)&temp_var_for_tac_30,
                "/home/shijia/Public/testprogram/e_acos.c_e.c:122:7");
        ;
        double temp_var_for_ext_4;
        double temp_var_for_tac_31, temp_var_for_tac_32, temp_var_for_tac_33,
            temp_var_for_tac_34;
        double temp_var_for_const_25, temp_var_for_const_26;
        temp_var_for_tac_31 = x * r;

        temp_var_for_tac_32 = pio2_lo - temp_var_for_tac_31;

        temp_var_for_tac_33 = x - temp_var_for_tac_32;

        temp_var_for_tac_34 = pio2_hi - temp_var_for_tac_33;

        temp_var_for_ext_4 = temp_var_for_tac_34;
        computeDMul((Addr)&temp_var_for_tac_31, {(Addr)&x, (Addr)&r},
                    "/home/shijia/Public/testprogram/e_acos.c_e.c:124:54");
        computeDSub(
            (Addr)&temp_var_for_tac_32,
            {(Addr) & (temp_var_for_const_25 = pio2_lo), (Addr)&temp_var_for_tac_31},
            "/home/shijia/Public/testprogram/e_acos.c_e.c:124:50");
        computeDSub((Addr)&temp_var_for_tac_33,
                    {(Addr)&x, (Addr)&temp_var_for_tac_32},
                    "/home/shijia/Public/testprogram/e_acos.c_e.c:124:39");
        computeDSub(
            (Addr)&temp_var_for_tac_34,
            {(Addr) & (temp_var_for_const_26 = pio2_hi), (Addr)&temp_var_for_tac_33},
            "/home/shijia/Public/testprogram/e_acos.c_e.c:124:34");
        AssignD({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_34,
                "/home/shijia/Public/testprogram/e_acos.c_e.c:124:24");
        ;
        callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_4;
    }
    else
    {
        if (hx < 0)
        { /* x < -0.5 */
            double temp_var_for_tac_35, temp_var_for_tac_36;
            double temp_var_for_const_27, temp_var_for_const_28;
            temp_var_for_tac_35 = one + x;

            temp_var_for_tac_36 = temp_var_for_tac_35 * 0.5;

            z = temp_var_for_tac_36;
            computeDAdd((Addr)&temp_var_for_tac_35,
                        {(Addr) & (temp_var_for_const_27 = one), (Addr)&x},
                        "/home/shijia/Public/testprogram/e_acos.c_e.c:130:16");
            computeDMul(
                (Addr)&temp_var_for_tac_36,
                {(Addr)&temp_var_for_tac_35, (Addr) & (temp_var_for_const_28 = 0.5)},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:130:21");
            AssignD({(Addr)&z}, (Addr)&temp_var_for_tac_36,
                    "/home/shijia/Public/testprogram/e_acos.c_e.c:130:9");
            ;
            double temp_var_for_tac_37, temp_var_for_tac_38, temp_var_for_tac_39,
                temp_var_for_tac_40, temp_var_for_tac_41, temp_var_for_tac_42,
                temp_var_for_tac_43, temp_var_for_tac_44, temp_var_for_tac_45,
                temp_var_for_tac_46, temp_var_for_tac_47;
            double temp_var_for_const_29, temp_var_for_const_30,
                temp_var_for_const_31, temp_var_for_const_32, temp_var_for_const_33,
                temp_var_for_const_34;
            temp_var_for_tac_37 = z * pS5;

            temp_var_for_tac_38 = pS4 + temp_var_for_tac_37;

            temp_var_for_tac_39 = z * temp_var_for_tac_38;

            temp_var_for_tac_40 = pS3 + temp_var_for_tac_39;

            temp_var_for_tac_41 = z * temp_var_for_tac_40;

            temp_var_for_tac_42 = pS2 + temp_var_for_tac_41;

            temp_var_for_tac_43 = z * temp_var_for_tac_42;

            temp_var_for_tac_44 = pS1 + temp_var_for_tac_43;

            temp_var_for_tac_45 = z * temp_var_for_tac_44;

            temp_var_for_tac_46 = pS0 + temp_var_for_tac_45;

            temp_var_for_tac_47 = z * temp_var_for_tac_46;

            p = temp_var_for_tac_47;
            computeDMul((Addr)&temp_var_for_tac_37,
                        {(Addr)&z, (Addr) & (temp_var_for_const_29 = pS5)},
                        "/home/shijia/Public/testprogram/e_acos.c_e.c:131:68");
            computeDAdd(
                (Addr)&temp_var_for_tac_38,
                {(Addr) & (temp_var_for_const_30 = pS4), (Addr)&temp_var_for_tac_37},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:131:64");
            computeDMul((Addr)&temp_var_for_tac_39,
                        {(Addr)&z, (Addr)&temp_var_for_tac_38},
                        "/home/shijia/Public/testprogram/e_acos.c_e.c:131:57");
            computeDAdd(
                (Addr)&temp_var_for_tac_40,
                {(Addr) & (temp_var_for_const_31 = pS3), (Addr)&temp_var_for_tac_39},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:131:53");
            computeDMul((Addr)&temp_var_for_tac_41,
                        {(Addr)&z, (Addr)&temp_var_for_tac_40},
                        "/home/shijia/Public/testprogram/e_acos.c_e.c:131:46");
            computeDAdd(
                (Addr)&temp_var_for_tac_42,
                {(Addr) & (temp_var_for_const_32 = pS2), (Addr)&temp_var_for_tac_41},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:131:42");
            computeDMul((Addr)&temp_var_for_tac_43,
                        {(Addr)&z, (Addr)&temp_var_for_tac_42},
                        "/home/shijia/Public/testprogram/e_acos.c_e.c:131:35");
            computeDAdd(
                (Addr)&temp_var_for_tac_44,
                {(Addr) & (temp_var_for_const_33 = pS1), (Addr)&temp_var_for_tac_43},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:131:31");
            computeDMul((Addr)&temp_var_for_tac_45,
                        {(Addr)&z, (Addr)&temp_var_for_tac_44},
                        "/home/shijia/Public/testprogram/e_acos.c_e.c:131:24");
            computeDAdd(
                (Addr)&temp_var_for_tac_46,
                {(Addr) & (temp_var_for_const_34 = pS0), (Addr)&temp_var_for_tac_45},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:131:20");
            computeDMul((Addr)&temp_var_for_tac_47,
                        {(Addr)&z, (Addr)&temp_var_for_tac_46},
                        "/home/shijia/Public/testprogram/e_acos.c_e.c:131:13");
            AssignD({(Addr)&p}, (Addr)&temp_var_for_tac_47,
                    "/home/shijia/Public/testprogram/e_acos.c_e.c:131:9");
            ;
            double temp_var_for_tac_48, temp_var_for_tac_49, temp_var_for_tac_50,
                temp_var_for_tac_51, temp_var_for_tac_52, temp_var_for_tac_53,
                temp_var_for_tac_54, temp_var_for_tac_55;
            double temp_var_for_const_35, temp_var_for_const_36,
                temp_var_for_const_37, temp_var_for_const_38, temp_var_for_const_39;
            temp_var_for_tac_48 = z * qS4;

            temp_var_for_tac_49 = qS3 + temp_var_for_tac_48;

            temp_var_for_tac_50 = z * temp_var_for_tac_49;

            temp_var_for_tac_51 = qS2 + temp_var_for_tac_50;

            temp_var_for_tac_52 = z * temp_var_for_tac_51;

            temp_var_for_tac_53 = qS1 + temp_var_for_tac_52;

            temp_var_for_tac_54 = z * temp_var_for_tac_53;

            temp_var_for_tac_55 = one + temp_var_for_tac_54;

            q = temp_var_for_tac_55;
            computeDMul((Addr)&temp_var_for_tac_48,
                        {(Addr)&z, (Addr) & (temp_var_for_const_35 = qS4)},
                        "/home/shijia/Public/testprogram/e_acos.c_e.c:132:52");
            computeDAdd(
                (Addr)&temp_var_for_tac_49,
                {(Addr) & (temp_var_for_const_36 = qS3), (Addr)&temp_var_for_tac_48},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:132:48");
            computeDMul((Addr)&temp_var_for_tac_50,
                        {(Addr)&z, (Addr)&temp_var_for_tac_49},
                        "/home/shijia/Public/testprogram/e_acos.c_e.c:132:41");
            computeDAdd(
                (Addr)&temp_var_for_tac_51,
                {(Addr) & (temp_var_for_const_37 = qS2), (Addr)&temp_var_for_tac_50},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:132:37");
            computeDMul((Addr)&temp_var_for_tac_52,
                        {(Addr)&z, (Addr)&temp_var_for_tac_51},
                        "/home/shijia/Public/testprogram/e_acos.c_e.c:132:30");
            computeDAdd(
                (Addr)&temp_var_for_tac_53,
                {(Addr) & (temp_var_for_const_38 = qS1), (Addr)&temp_var_for_tac_52},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:132:26");
            computeDMul((Addr)&temp_var_for_tac_54,
                        {(Addr)&z, (Addr)&temp_var_for_tac_53},
                        "/home/shijia/Public/testprogram/e_acos.c_e.c:132:19");
            computeDAdd(
                (Addr)&temp_var_for_tac_55,
                {(Addr) & (temp_var_for_const_39 = one), (Addr)&temp_var_for_tac_54},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:132:15");
            AssignD({(Addr)&q}, (Addr)&temp_var_for_tac_55,
                    "/home/shijia/Public/testprogram/e_acos.c_e.c:132:9");
            ;
            double temp_var_for_const_40;
            double temp_var_for_callexp_0;

            temp_var_for_callexp_0 = __ieee754_sqrt(z);
            s = temp_var_for_callexp_0;
            AssignD({(Addr)&s},
                    (Addr) & (temp_var_for_const_40 = temp_var_for_callexp_0),
                    "/home/shijia/Public/testprogram/e_acos.c_e.c:133:9");
            ;
            double temp_var_for_tac_56;
            temp_var_for_tac_56 = p / q;

            r = temp_var_for_tac_56;
            computeDDiv((Addr)&temp_var_for_tac_56, {(Addr)&p, (Addr)&q},
                        "/home/shijia/Public/testprogram/e_acos.c_e.c:134:13");
            AssignD({(Addr)&r}, (Addr)&temp_var_for_tac_56,
                    "/home/shijia/Public/testprogram/e_acos.c_e.c:134:9");
            ;
            double temp_var_for_tac_57, temp_var_for_tac_58;
            double temp_var_for_const_41;
            temp_var_for_tac_57 = r * s;

            temp_var_for_tac_58 = temp_var_for_tac_57 - pio2_lo;

            w = temp_var_for_tac_58;
            computeDMul((Addr)&temp_var_for_tac_57, {(Addr)&r, (Addr)&s},
                        "/home/shijia/Public/testprogram/e_acos.c_e.c:135:13");
            computeDSub((Addr)&temp_var_for_tac_58,
                        {(Addr)&temp_var_for_tac_57,
                         (Addr) & (temp_var_for_const_41 = pio2_lo)},
                        "/home/shijia/Public/testprogram/e_acos.c_e.c:135:17");
            AssignD({(Addr)&w}, (Addr)&temp_var_for_tac_58,
                    "/home/shijia/Public/testprogram/e_acos.c_e.c:135:9");
            ;
            double temp_var_for_ext_5;
            double temp_var_for_tac_59, temp_var_for_tac_60, temp_var_for_tac_61;
            double temp_var_for_const_42, temp_var_for_const_43;
            temp_var_for_tac_59 = s + w;

            temp_var_for_tac_60 = 2.0 * temp_var_for_tac_59;

            temp_var_for_tac_61 = pi - temp_var_for_tac_60;

            temp_var_for_ext_5 = temp_var_for_tac_61;
            computeDAdd((Addr)&temp_var_for_tac_59, {(Addr)&s, (Addr)&w},
                        "/home/shijia/Public/testprogram/e_acos.c_e.c:137:42");
            computeDMul(
                (Addr)&temp_var_for_tac_60,
                {(Addr) & (temp_var_for_const_42 = 2.0), (Addr)&temp_var_for_tac_59},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:137:37");
            computeDSub(
                (Addr)&temp_var_for_tac_61,
                {(Addr) & (temp_var_for_const_43 = pi), (Addr)&temp_var_for_tac_60},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:137:31");
            AssignD({(Addr)&temp_var_for_ext_5}, (Addr)&temp_var_for_tac_61,
                    "/home/shijia/Public/testprogram/e_acos.c_e.c:137:26");
            ;
            callExpStack.push(
                getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
            callExp++; /*identify the function is  add move tmpShadow*/
            return temp_var_for_ext_5;
        }
        else
        { /* x > 0.5 */
            double temp_var_for_tac_62, temp_var_for_tac_63;
            double temp_var_for_const_44, temp_var_for_const_45;
            temp_var_for_tac_62 = one - x;

            temp_var_for_tac_63 = temp_var_for_tac_62 * 0.5;

            z = temp_var_for_tac_63;
            computeDSub((Addr)&temp_var_for_tac_62,
                        {(Addr) & (temp_var_for_const_44 = one), (Addr)&x},
                        "/home/shijia/Public/testprogram/e_acos.c_e.c:143:16");
            computeDMul(
                (Addr)&temp_var_for_tac_63,
                {(Addr)&temp_var_for_tac_62, (Addr) & (temp_var_for_const_45 = 0.5)},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:143:21");
            AssignD({(Addr)&z}, (Addr)&temp_var_for_tac_63,
                    "/home/shijia/Public/testprogram/e_acos.c_e.c:143:9");
            ;
            double temp_var_for_const_46;
            double temp_var_for_callexp_1;

            temp_var_for_callexp_1 = __ieee754_sqrt(z);
            s = temp_var_for_callexp_1;
            AssignD({(Addr)&s},
                    (Addr) & (temp_var_for_const_46 = temp_var_for_callexp_1),
                    "/home/shijia/Public/testprogram/e_acos.c_e.c:144:9");
            ;
            df = s;
            AssignD({(Addr)&df}, (Addr)&s,
                    "/home/shijia/Public/testprogram/e_acos.c_e.c:145:10");
            ;
            SET_LOW_WORD(df, 0);
            double temp_var_for_tac_64, temp_var_for_tac_65, temp_var_for_tac_66,
                temp_var_for_tac_67;
            temp_var_for_tac_64 = df * df;

            temp_var_for_tac_65 = z - temp_var_for_tac_64;

            temp_var_for_tac_66 = s + df;

            temp_var_for_tac_67 = temp_var_for_tac_65 / temp_var_for_tac_66;

            c = temp_var_for_tac_67;
            computeDMul((Addr)&temp_var_for_tac_64, {(Addr)&df, (Addr)&df},
                        "/home/shijia/Public/testprogram/e_acos.c_e.c:147:19");
            computeDSub((Addr)&temp_var_for_tac_65,
                        {(Addr)&z, (Addr)&temp_var_for_tac_64},
                        "/home/shijia/Public/testprogram/e_acos.c_e.c:147:14");
            computeDAdd((Addr)&temp_var_for_tac_66, {(Addr)&s, (Addr)&df},
                        "/home/shijia/Public/testprogram/e_acos.c_e.c:147:30");
            computeDDiv((Addr)&temp_var_for_tac_67,
                        {(Addr)&temp_var_for_tac_65, (Addr)&temp_var_for_tac_66},
                        "/home/shijia/Public/testprogram/e_acos.c_e.c:147:25");
            AssignD({(Addr)&c}, (Addr)&temp_var_for_tac_67,
                    "/home/shijia/Public/testprogram/e_acos.c_e.c:147:9");
            ;
            double temp_var_for_tac_68, temp_var_for_tac_69, temp_var_for_tac_70,
                temp_var_for_tac_71, temp_var_for_tac_72, temp_var_for_tac_73,
                temp_var_for_tac_74, temp_var_for_tac_75, temp_var_for_tac_76,
                temp_var_for_tac_77, temp_var_for_tac_78;
            double temp_var_for_const_47, temp_var_for_const_48,
                temp_var_for_const_49, temp_var_for_const_50, temp_var_for_const_51,
                temp_var_for_const_52;
            temp_var_for_tac_68 = z * pS5;

            temp_var_for_tac_69 = pS4 + temp_var_for_tac_68;

            temp_var_for_tac_70 = z * temp_var_for_tac_69;

            temp_var_for_tac_71 = pS3 + temp_var_for_tac_70;

            temp_var_for_tac_72 = z * temp_var_for_tac_71;

            temp_var_for_tac_73 = pS2 + temp_var_for_tac_72;

            temp_var_for_tac_74 = z * temp_var_for_tac_73;

            temp_var_for_tac_75 = pS1 + temp_var_for_tac_74;

            temp_var_for_tac_76 = z * temp_var_for_tac_75;

            temp_var_for_tac_77 = pS0 + temp_var_for_tac_76;

            temp_var_for_tac_78 = z * temp_var_for_tac_77;

            p = temp_var_for_tac_78;
            computeDMul((Addr)&temp_var_for_tac_68,
                        {(Addr)&z, (Addr) & (temp_var_for_const_47 = pS5)},
                        "/home/shijia/Public/testprogram/e_acos.c_e.c:148:68");
            computeDAdd(
                (Addr)&temp_var_for_tac_69,
                {(Addr) & (temp_var_for_const_48 = pS4), (Addr)&temp_var_for_tac_68},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:148:64");
            computeDMul((Addr)&temp_var_for_tac_70,
                        {(Addr)&z, (Addr)&temp_var_for_tac_69},
                        "/home/shijia/Public/testprogram/e_acos.c_e.c:148:57");
            computeDAdd(
                (Addr)&temp_var_for_tac_71,
                {(Addr) & (temp_var_for_const_49 = pS3), (Addr)&temp_var_for_tac_70},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:148:53");
            computeDMul((Addr)&temp_var_for_tac_72,
                        {(Addr)&z, (Addr)&temp_var_for_tac_71},
                        "/home/shijia/Public/testprogram/e_acos.c_e.c:148:46");
            computeDAdd(
                (Addr)&temp_var_for_tac_73,
                {(Addr) & (temp_var_for_const_50 = pS2), (Addr)&temp_var_for_tac_72},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:148:42");
            computeDMul((Addr)&temp_var_for_tac_74,
                        {(Addr)&z, (Addr)&temp_var_for_tac_73},
                        "/home/shijia/Public/testprogram/e_acos.c_e.c:148:35");
            computeDAdd(
                (Addr)&temp_var_for_tac_75,
                {(Addr) & (temp_var_for_const_51 = pS1), (Addr)&temp_var_for_tac_74},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:148:31");
            computeDMul((Addr)&temp_var_for_tac_76,
                        {(Addr)&z, (Addr)&temp_var_for_tac_75},
                        "/home/shijia/Public/testprogram/e_acos.c_e.c:148:24");
            computeDAdd(
                (Addr)&temp_var_for_tac_77,
                {(Addr) & (temp_var_for_const_52 = pS0), (Addr)&temp_var_for_tac_76},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:148:20");
            computeDMul((Addr)&temp_var_for_tac_78,
                        {(Addr)&z, (Addr)&temp_var_for_tac_77},
                        "/home/shijia/Public/testprogram/e_acos.c_e.c:148:13");
            AssignD({(Addr)&p}, (Addr)&temp_var_for_tac_78,
                    "/home/shijia/Public/testprogram/e_acos.c_e.c:148:9");
            ;
            double temp_var_for_tac_79, temp_var_for_tac_80, temp_var_for_tac_81,
                temp_var_for_tac_82, temp_var_for_tac_83, temp_var_for_tac_84,
                temp_var_for_tac_85, temp_var_for_tac_86;
            double temp_var_for_const_53, temp_var_for_const_54,
                temp_var_for_const_55, temp_var_for_const_56, temp_var_for_const_57;
            temp_var_for_tac_79 = z * qS4;

            temp_var_for_tac_80 = qS3 + temp_var_for_tac_79;

            temp_var_for_tac_81 = z * temp_var_for_tac_80;

            temp_var_for_tac_82 = qS2 + temp_var_for_tac_81;

            temp_var_for_tac_83 = z * temp_var_for_tac_82;

            temp_var_for_tac_84 = qS1 + temp_var_for_tac_83;

            temp_var_for_tac_85 = z * temp_var_for_tac_84;

            temp_var_for_tac_86 = one + temp_var_for_tac_85;

            q = temp_var_for_tac_86;
            computeDMul((Addr)&temp_var_for_tac_79,
                        {(Addr)&z, (Addr) & (temp_var_for_const_53 = qS4)},
                        "/home/shijia/Public/testprogram/e_acos.c_e.c:149:52");
            computeDAdd(
                (Addr)&temp_var_for_tac_80,
                {(Addr) & (temp_var_for_const_54 = qS3), (Addr)&temp_var_for_tac_79},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:149:48");
            computeDMul((Addr)&temp_var_for_tac_81,
                        {(Addr)&z, (Addr)&temp_var_for_tac_80},
                        "/home/shijia/Public/testprogram/e_acos.c_e.c:149:41");
            computeDAdd(
                (Addr)&temp_var_for_tac_82,
                {(Addr) & (temp_var_for_const_55 = qS2), (Addr)&temp_var_for_tac_81},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:149:37");
            computeDMul((Addr)&temp_var_for_tac_83,
                        {(Addr)&z, (Addr)&temp_var_for_tac_82},
                        "/home/shijia/Public/testprogram/e_acos.c_e.c:149:30");
            computeDAdd(
                (Addr)&temp_var_for_tac_84,
                {(Addr) & (temp_var_for_const_56 = qS1), (Addr)&temp_var_for_tac_83},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:149:26");
            computeDMul((Addr)&temp_var_for_tac_85,
                        {(Addr)&z, (Addr)&temp_var_for_tac_84},
                        "/home/shijia/Public/testprogram/e_acos.c_e.c:149:19");
            computeDAdd(
                (Addr)&temp_var_for_tac_86,
                {(Addr) & (temp_var_for_const_57 = one), (Addr)&temp_var_for_tac_85},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:149:15");
            AssignD({(Addr)&q}, (Addr)&temp_var_for_tac_86,
                    "/home/shijia/Public/testprogram/e_acos.c_e.c:149:9");
            ;
            double temp_var_for_tac_87;
            temp_var_for_tac_87 = p / q;

            r = temp_var_for_tac_87;
            computeDDiv((Addr)&temp_var_for_tac_87, {(Addr)&p, (Addr)&q},
                        "/home/shijia/Public/testprogram/e_acos.c_e.c:150:13");
            AssignD({(Addr)&r}, (Addr)&temp_var_for_tac_87,
                    "/home/shijia/Public/testprogram/e_acos.c_e.c:150:9");
            ;
            double temp_var_for_tac_88, temp_var_for_tac_89;
            temp_var_for_tac_88 = r * s;

            temp_var_for_tac_89 = temp_var_for_tac_88 + c;

            w = temp_var_for_tac_89;
            computeDMul((Addr)&temp_var_for_tac_88, {(Addr)&r, (Addr)&s},
                        "/home/shijia/Public/testprogram/e_acos.c_e.c:151:13");
            computeDAdd((Addr)&temp_var_for_tac_89,
                        {(Addr)&temp_var_for_tac_88, (Addr)&c},
                        "/home/shijia/Public/testprogram/e_acos.c_e.c:151:17");
            AssignD({(Addr)&w}, (Addr)&temp_var_for_tac_89,
                    "/home/shijia/Public/testprogram/e_acos.c_e.c:151:9");
            ;
            double temp_var_for_ext_6;
            double temp_var_for_tac_90, temp_var_for_tac_91;
            double temp_var_for_const_58;
            temp_var_for_tac_90 = df + w;

            temp_var_for_tac_91 = 2.0 * temp_var_for_tac_90;

            temp_var_for_ext_6 = temp_var_for_tac_91;
            computeDAdd((Addr)&temp_var_for_tac_90, {(Addr)&df, (Addr)&w},
                        "/home/shijia/Public/testprogram/e_acos.c_e.c:153:38");
            computeDMul(
                (Addr)&temp_var_for_tac_91,
                {(Addr) & (temp_var_for_const_58 = 2.0), (Addr)&temp_var_for_tac_90},
                "/home/shijia/Public/testprogram/e_acos.c_e.c:153:32");
            AssignD({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_91,
                    "/home/shijia/Public/testprogram/e_acos.c_e.c:153:26");
            ;
            // printVarInfo("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6);
            callExpStack.push(
                getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
                printVarInfo("acos", (Addr)&temp_var_for_ext_6);
            callExp++; /*identify the function is  add move tmpShadow*/
            return temp_var_for_ext_6;
        }
    }
}

int main()
{
  std::ifstream inputFile("/home/shijia/Public/FpDebug-valgrind_3.12/valgrind/fpdebug/pso/exe-input/acos_t.txt", std::ios::in);
  double input;
  long double oracle, realError = 0.0, scError = 0.0, prealError = 0.0, pscError = 0.0;
  long double delta = 1.0e-20;
  int index,la=0,eq=0,sm=0;
  std::ifstream inputOracle("/home/shijia/Public/FpDebug-valgrind_3.12/valgrind/fpdebug/pso/mpfr/mpfrresults/acos_out.txt", std::ios::in);
  while (inputFile >> input)
  {
    double a = __ieee754_acosS(input);
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
    
    
    
    printf("%d %.20Le\n",index,prealError);
  }
  printf("%d %.20Le %.20Le ", index, realError / index, scError / index);
  printf("%d %d %d\n", la,eq,sm);
  return 0;
}