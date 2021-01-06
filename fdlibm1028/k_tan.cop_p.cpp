#include "../ScDebug/scdebug.h"
/*
 * ====================================================
 * Copyright 2004 Sun Microsystems, Inc.  All Rights Reserved.
 *
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 */

/* __kernel_tan( x, y, k )
 * kernel tan function on [-pi/4, pi/4], pi/4 ~ 0.7854
 * Input x is assumed to be bounded by ~pi/4 in magnitude.
 * Input y is the tail of x.
 * Input k indicates whether tan (if k = 1) or -1/tan (if k = -1) is returned.
 *
 * Algorithm
 *	1. Since tan(-x) = -tan(x), we need only to consider positive x.
 *	2. if x < 2^-28 (hx<0x3e300000 0), return x with inexact if x!=0.
 *	3. tan(x) is approximated by a odd polynomial of degree 27 on
 *	   [0,0.67434]
 *		  	         3             27
 *	   	tan(x) ~ x + T1*x + ... + T13*x
 *	   where
 *
 * 	        |tan(x)         2     4            26   |     -59.2
 * 	        |----- - (1+T1*x +T2*x +.... +T13*x    )| <= 2
 * 	        |  x 					|
 *
 *	   Note: tan(x+y) = tan(x) + tan'(x)*y
 *		          ~ tan(x) + (1+x*x)*y
 *	   Therefore, for better accuracy in computing tan(x+y), let
 *		     3      2      2       2       2
 *		r = x *(T2+x *(T3+x *(...+x *(T12+x *T13))))
 *	   then
 *		 		    3    2
 *		tan(x+y) = x + (T1*x + (x *(r+y)+y))
 *
 *      4. For x in [0.67434,pi/4],  let y = pi/4 - x, then
 *		tan(x) = tan(pi/4-y) = (1-tan(y))/(1+tan(y))
 *		       = 1 - 2*(tan(y) - (tan(y)^2)/(1+tan(y)))
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

double __kernel_tanS(double x, double y, int iy)
{
        double z, r, v, w, s;
        int32_t ix, hx;

        static const double one =
            1.00000000000000000000e+00; /* 0x3FF00000, 0x00000000 */
        static const double pio4 =
            7.85398163397448278999e-01; /* 0x3FE921FB, 0x54442D18 */
        static const double pio4lo =
            3.06161699786838301793e-17; /* 0x3C81A626, 0x33145C07 */

        static const double T[] = {
            3.33333333333334091986e-01,  /* 0x3FD55555, 0x55555563 */
            1.33333333333201242699e-01,  /* 0x3FC11111, 0x1110FE7A */
            5.39682539762260521377e-02,  /* 0x3FABA1BA, 0x1BB341FE */
            2.18694882948595424599e-02,  /* 0x3F9664F4, 0x8406D637 */
            8.86323982359930005737e-03,  /* 0x3F8226E3, 0xE96E8493 */
            3.59207910759131235356e-03,  /* 0x3F6D6D22, 0xC9560328 */
            1.45620945432529025516e-03,  /* 0x3F57DBC8, 0xFEE08315 */
            5.88041240820264096874e-04,  /* 0x3F4344D8, 0xF2F26501 */
            2.46463134818469906812e-04,  /* 0x3F3026F7, 0x1A8D1068 */
            7.81794442939557092300e-05,  /* 0x3F147E88, 0xA03792A6 */
            7.14072491382608190305e-05,  /* 0x3F12B80F, 0x32F0A7E9 */
            -1.85586374855275456654e-05, /* 0xBEF375CB, 0xDB605373 */
            2.59073051863633712884e-05   /* 0x3EFB2A70, 0x74BF7AD4 */
        };

        GET_HIGH_WORD(hx, x);
        ix = hx & IC(0x7fffffff); /* high word of |x| */
        if (ix < IC(0x3e300000))  /* x < 2**-28 */
        {
                if ((int32_t)x == 0)
                { /* generate inexact */
                        uint32_t low;

                        GET_LOW_WORD(low, x);
                        if (((ix | low) | (iy + 1)) == 0)
                        {
                                double temp_var_for_ext_0;
                                double temp_var_for_tac_1;
                                double temp_var_for_const_2, temp_var_for_const_3;
                                double temp_var_for_callexp_0;

                                temp_var_for_callexp_0 = fabs(x);
                                temp_var_for_tac_1 = one / temp_var_for_callexp_0;

                                temp_var_for_ext_0 = temp_var_for_tac_1;
                                computeDDiv((Addr)&temp_var_for_tac_1,
                                            {(Addr) & (temp_var_for_const_3 = one),
                                             (Addr) & (temp_var_for_const_2 = temp_var_for_callexp_0)},
                                            "/home/shijia/Public/testprogram/k_tan.c_e.c:85:34");
                                AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_1,
                                        "/home/shijia/Public/testprogram/k_tan.c_e.c:85:28");
                                ;
                                callExpStack.push(
                                    getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
                                callExp++; /*identify the function is  add move tmpShadow*/
                                return temp_var_for_ext_0;
                        }

                        else
                        {
                                double temp_var_for_ext_1;
                                double temp_var_for_const_4;
                                temp_var_for_ext_1 = (iy == 1) ? x : -one / x;
                                AssignD({(Addr)&temp_var_for_ext_1},
                                        (Addr) & (temp_var_for_const_4 = (iy == 1) ? x : -one / x),
                                        "/home/shijia/Public/testprogram/k_tan.c_e.c:94:28");
                                ;
                                callExpStack.push(
                                    getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
                                callExp++; /*identify the function is  add move tmpShadow*/
                                return temp_var_for_ext_1;
                        }
                }
        }
        if (ix >= IC(0x3FE59428))
        { /* |x| >= 0.6744 */
                if (hx < 0)
                {
                        double temp_var_for_ext_2;
                        double temp_var_for_tac_2;
                        double temp_var_for_const_5;
                        temp_var_for_tac_2 = 0.0 - x;
                        temp_var_for_ext_2 = temp_var_for_tac_2;
                        // x
                        /*(emp_var_for_ext_0)(tem)(1)(r_e)(r_e)(x)(x)*/
                        x = temp_var_for_ext_2;
                        computeDSub((Addr)&temp_var_for_tac_2,
                                    {(Addr) & (temp_var_for_const_5 = 0.0), (Addr)&x},
                                    "/home/shijia/Public/testprogram/k_tan.c_e.c:105:33");
                        AssignD({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_2,
                                "/home/shijia/Public/testprogram/k_tan.c_e.c:107:9");
                        AssignD({(Addr)&x}, (Addr)&temp_var_for_ext_2,
                                "/home/shijia/Public/testprogram/k_tan.c_e.c:107:9");
                        ;

                        double temp_var_for_ext_3;
                        double temp_var_for_tac_3;
                        double temp_var_for_const_6;
                        temp_var_for_tac_3 = 0.0 - y;

                        temp_var_for_ext_3 = temp_var_for_tac_3;
                        computeDSub((Addr)&temp_var_for_tac_3,
                                    {(Addr) & (temp_var_for_const_6 = 0.0), (Addr)&y},
                                    "/home/shijia/Public/testprogram/k_tan.c_e.c:109:33");
                        AssignD({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_3,
                                "/home/shijia/Public/testprogram/k_tan.c_e.c:109:26");
                        ; // y
                        /*(y)(y)*/
                        y = temp_var_for_ext_3;
                        AssignD({(Addr)&y}, (Addr)&temp_var_for_ext_3,
                                "/home/shijia/Public/testprogram/k_tan.c_e.c:111:9");
                        ;
                }
                double temp_var_for_tac_4;
                double temp_var_for_const_7;
                temp_var_for_tac_4 = pio4 - x;

                z = temp_var_for_tac_4;
                computeDSub((Addr)&temp_var_for_tac_4,
                            {(Addr) & (temp_var_for_const_7 = pio4), (Addr)&x},
                            "/home/shijia/Public/testprogram/k_tan.c_e.c:113:14");
                AssignD({(Addr)&z}, (Addr)&temp_var_for_tac_4,
                        "/home/shijia/Public/testprogram/k_tan.c_e.c:113:7");
                ;
                double temp_var_for_tac_5;
                double temp_var_for_const_8;
                temp_var_for_tac_5 = pio4lo - y;

                w = temp_var_for_tac_5;
                computeDSub((Addr)&temp_var_for_tac_5,
                            {(Addr) & (temp_var_for_const_8 = pio4lo), (Addr)&y},
                            "/home/shijia/Public/testprogram/k_tan.c_e.c:114:16");
                AssignD({(Addr)&w}, (Addr)&temp_var_for_tac_5,
                        "/home/shijia/Public/testprogram/k_tan.c_e.c:114:7");
                ;
                double temp_var_for_tac_6;
                temp_var_for_tac_6 = z + w;

                x = temp_var_for_tac_6;
                computeDAdd((Addr)&temp_var_for_tac_6, {(Addr)&z, (Addr)&w},
                            "/home/shijia/Public/testprogram/k_tan.c_e.c:115:11");
                AssignD({(Addr)&x}, (Addr)&temp_var_for_tac_6,
                        "/home/shijia/Public/testprogram/k_tan.c_e.c:115:7");
                ;
                double temp_var_for_const_9;
                y = 0.0;
                AssignD({(Addr)&y}, (Addr) & (temp_var_for_const_9 = 0.0),
                        "/home/shijia/Public/testprogram/k_tan.c_e.c:116:7");
                ;
        }
        double temp_var_for_tac_7;
        temp_var_for_tac_7 = x * x;

        z = temp_var_for_tac_7;
        computeDMul((Addr)&temp_var_for_tac_7, {(Addr)&x, (Addr)&x},
                    "/home/shijia/Public/testprogram/k_tan.c_e.c:118:9");
        AssignD({(Addr)&z}, (Addr)&temp_var_for_tac_7,
                "/home/shijia/Public/testprogram/k_tan.c_e.c:118:5");
        ;
        double temp_var_for_tac_8;
        temp_var_for_tac_8 = z * z;

        w = temp_var_for_tac_8;
        computeDMul((Addr)&temp_var_for_tac_8, {(Addr)&z, (Addr)&z},
                    "/home/shijia/Public/testprogram/k_tan.c_e.c:119:9");
        AssignD({(Addr)&w}, (Addr)&temp_var_for_tac_8,
                "/home/shijia/Public/testprogram/k_tan.c_e.c:119:5");
        ;
        /*
 * Break x^5*(T[1]+x^2*T[2]+...) into
 * x^5(T[1]+x^4*T[3]+...+x^20*T[11]) +
 * x^5(x^2*(T[2]+x^4*T[4]+...+x^22*[T12]))
 */
        double temp_var_for_tac_9, temp_var_for_tac_10, temp_var_for_tac_11,
            temp_var_for_tac_12, temp_var_for_tac_13, temp_var_for_tac_14,
            temp_var_for_tac_15, temp_var_for_tac_16, temp_var_for_tac_17,
            temp_var_for_tac_18;
        double temp_var_for_const_10, temp_var_for_const_11, temp_var_for_const_12,
            temp_var_for_const_13, temp_var_for_const_14, temp_var_for_const_15;
        temp_var_for_tac_9 = w * T[11];

        temp_var_for_tac_10 = T[9] + temp_var_for_tac_9;

        temp_var_for_tac_11 = w * temp_var_for_tac_10;

        temp_var_for_tac_12 = T[7] + temp_var_for_tac_11;

        temp_var_for_tac_13 = w * temp_var_for_tac_12;

        temp_var_for_tac_14 = T[5] + temp_var_for_tac_13;

        temp_var_for_tac_15 = w * temp_var_for_tac_14;

        temp_var_for_tac_16 = T[3] + temp_var_for_tac_15;

        temp_var_for_tac_17 = w * temp_var_for_tac_16;

        temp_var_for_tac_18 = T[1] + temp_var_for_tac_17;

        r = temp_var_for_tac_18;
        computeDMul((Addr)&temp_var_for_tac_9,
                    {(Addr)&w, (Addr) & (temp_var_for_const_10 = T[11])},
                    "/home/shijia/Public/testprogram/k_tan.c_e.c:125:64");
        computeDAdd((Addr)&temp_var_for_tac_10,
                    {(Addr) & (temp_var_for_const_11 = T[9]), (Addr)&temp_var_for_tac_9},
                    "/home/shijia/Public/testprogram/k_tan.c_e.c:125:60");
        computeDMul((Addr)&temp_var_for_tac_11, {(Addr)&w, (Addr)&temp_var_for_tac_10},
                    "/home/shijia/Public/testprogram/k_tan.c_e.c:125:52");
        computeDAdd((Addr)&temp_var_for_tac_12, {(Addr) & (temp_var_for_const_12 = T[7]), (Addr)&temp_var_for_tac_11},
                    "/home/shijia/Public/testprogram/k_tan.c_e.c:125:48");
        computeDMul((Addr)&temp_var_for_tac_13, {(Addr)&w, (Addr)&temp_var_for_tac_12},
                    "/home/shijia/Public/testprogram/k_tan.c_e.c:125:40");
        computeDAdd((Addr)&temp_var_for_tac_14, {(Addr) & (temp_var_for_const_13 = T[5]), (Addr)&temp_var_for_tac_13},
                    "/home/shijia/Public/testprogram/k_tan.c_e.c:125:36");
        computeDMul((Addr)&temp_var_for_tac_15, {(Addr)&w, (Addr)&temp_var_for_tac_14},
                    "/home/shijia/Public/testprogram/k_tan.c_e.c:125:28");
        computeDAdd((Addr)&temp_var_for_tac_16, {(Addr) & (temp_var_for_const_14 = T[3]), (Addr)&temp_var_for_tac_15},
                    "/home/shijia/Public/testprogram/k_tan.c_e.c:125:24");
        computeDMul((Addr)&temp_var_for_tac_17, {(Addr)&w, (Addr)&temp_var_for_tac_16},
                    "/home/shijia/Public/testprogram/k_tan.c_e.c:125:16");
        computeDAdd((Addr)&temp_var_for_tac_18, {(Addr) & (temp_var_for_const_15 = T[1]), (Addr)&temp_var_for_tac_17},
                    "/home/shijia/Public/testprogram/k_tan.c_e.c:125:12");
        AssignD({(Addr)&r}, (Addr)&temp_var_for_tac_18,
                "/home/shijia/Public/testprogram/k_tan.c_e.c:125:5");
        ;
        double temp_var_for_tac_19, temp_var_for_tac_20, temp_var_for_tac_21,
            temp_var_for_tac_22, temp_var_for_tac_23, temp_var_for_tac_24,
            temp_var_for_tac_25, temp_var_for_tac_26, temp_var_for_tac_27,
            temp_var_for_tac_28, temp_var_for_tac_29;
        double temp_var_for_const_16, temp_var_for_const_17, temp_var_for_const_18,
            temp_var_for_const_19, temp_var_for_const_20, temp_var_for_const_21;
        temp_var_for_tac_19 = w * T[12];

        temp_var_for_tac_20 = T[10] + temp_var_for_tac_19;

        temp_var_for_tac_21 = w * temp_var_for_tac_20;

        temp_var_for_tac_22 = T[8] + temp_var_for_tac_21;

        temp_var_for_tac_23 = w * temp_var_for_tac_22;

        temp_var_for_tac_24 = T[6] + temp_var_for_tac_23;

        temp_var_for_tac_25 = w * temp_var_for_tac_24;

        temp_var_for_tac_26 = T[4] + temp_var_for_tac_25;

        temp_var_for_tac_27 = w * temp_var_for_tac_26;

        temp_var_for_tac_28 = T[2] + temp_var_for_tac_27;

        temp_var_for_tac_29 = z * temp_var_for_tac_28;

        v = temp_var_for_tac_29;
        computeDMul((Addr)&temp_var_for_tac_19,
                    {(Addr)&w, (Addr) & (temp_var_for_const_16 = T[12])},
                    "/home/shijia/Public/testprogram/k_tan.c_e.c:127:66");
        computeDAdd((Addr)&temp_var_for_tac_20,
                    {(Addr) & (temp_var_for_const_17 = T[10]),
                     (Addr)&temp_var_for_tac_19},
                    "/home/shijia/Public/testprogram/k_tan.c_e.c:127:62");
        computeDMul((Addr)&temp_var_for_tac_21, {(Addr)&w, (Addr)&temp_var_for_tac_20},
                    "/home/shijia/Public/testprogram/k_tan.c_e.c:127:53");
        computeDAdd((Addr)&temp_var_for_tac_22, {(Addr) & (temp_var_for_const_18 = T[8]), (Addr)&temp_var_for_tac_21},
                    "/home/shijia/Public/testprogram/k_tan.c_e.c:127:49");
        computeDMul((Addr)&temp_var_for_tac_23, {(Addr)&w, (Addr)&temp_var_for_tac_22},
                    "/home/shijia/Public/testprogram/k_tan.c_e.c:127:41");
        computeDAdd((Addr)&temp_var_for_tac_24, {(Addr) & (temp_var_for_const_19 = T[6]), (Addr)&temp_var_for_tac_23},
                    "/home/shijia/Public/testprogram/k_tan.c_e.c:127:37");
        computeDMul((Addr)&temp_var_for_tac_25, {(Addr)&w, (Addr)&temp_var_for_tac_24},
                    "/home/shijia/Public/testprogram/k_tan.c_e.c:127:29");
        computeDAdd((Addr)&temp_var_for_tac_26, {(Addr) & (temp_var_for_const_20 = T[4]), (Addr)&temp_var_for_tac_25},
                    "/home/shijia/Public/testprogram/k_tan.c_e.c:127:25");
        computeDMul((Addr)&temp_var_for_tac_27, {(Addr)&w, (Addr)&temp_var_for_tac_26},
                    "/home/shijia/Public/testprogram/k_tan.c_e.c:127:17");
        computeDAdd((Addr)&temp_var_for_tac_28, {(Addr) & (temp_var_for_const_21 = T[2]), (Addr)&temp_var_for_tac_27},
                    "/home/shijia/Public/testprogram/k_tan.c_e.c:127:13");
        computeDMul((Addr)&temp_var_for_tac_29, {(Addr)&z, (Addr)&temp_var_for_tac_28},
                    "/home/shijia/Public/testprogram/k_tan.c_e.c:126:9");
        AssignD({(Addr)&v}, (Addr)&temp_var_for_tac_29,
                "/home/shijia/Public/testprogram/k_tan.c_e.c:126:5");
        ;
        double temp_var_for_tac_30;
        temp_var_for_tac_30 = z * x;

        s = temp_var_for_tac_30;
        computeDMul((Addr)&temp_var_for_tac_30, {(Addr)&z, (Addr)&x},
                    "/home/shijia/Public/testprogram/k_tan.c_e.c:128:9");
        AssignD({(Addr)&s}, (Addr)&temp_var_for_tac_30,
                "/home/shijia/Public/testprogram/k_tan.c_e.c:128:5");
        ;
        double temp_var_for_ext_4;
        double temp_var_for_tac_31, temp_var_for_tac_32, temp_var_for_tac_33,
            temp_var_for_tac_34, temp_var_for_tac_35;
        temp_var_for_tac_31 = r + v;

        temp_var_for_tac_32 = s * temp_var_for_tac_31;

        temp_var_for_tac_33 = temp_var_for_tac_32 + y;

        temp_var_for_tac_34 = z * temp_var_for_tac_33;

        temp_var_for_tac_35 = y + temp_var_for_tac_34;

        temp_var_for_ext_4 = temp_var_for_tac_35;
        computeDAdd((Addr)&temp_var_for_tac_31, {(Addr)&r, (Addr)&v},
                    "/home/shijia/Public/testprogram/k_tan.c_e.c:130:40");
        computeDMul((Addr)&temp_var_for_tac_32, {(Addr)&s, (Addr)&temp_var_for_tac_31},
                    "/home/shijia/Public/testprogram/k_tan.c_e.c:130:35");
        computeDAdd((Addr)&temp_var_for_tac_33, {(Addr)&temp_var_for_tac_32, (Addr)&y},
                    "/home/shijia/Public/testprogram/k_tan.c_e.c:130:45");
        computeDMul((Addr)&temp_var_for_tac_34, {(Addr)&z, (Addr)&temp_var_for_tac_33},
                    "/home/shijia/Public/testprogram/k_tan.c_e.c:130:30");
        computeDAdd((Addr)&temp_var_for_tac_35, {(Addr)&y, (Addr)&temp_var_for_tac_34},
                    "/home/shijia/Public/testprogram/k_tan.c_e.c:130:26");
        AssignD({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_35,
                "/home/shijia/Public/testprogram/k_tan.c_e.c:130:22");
        ; // r
        /*(x)(z)(y)(v)(r)(s)(z)(y)*/
        r = temp_var_for_ext_4;
        AssignD({(Addr)&r}, (Addr)&temp_var_for_ext_4,
                "/home/shijia/Public/testprogram/k_tan.c_e.c:132:5");
        ;
        double temp_var_for_tac_36;
        double temp_var_for_const_22;
        temp_var_for_tac_36 = T[0] * s;

        r += temp_var_for_tac_36;
        ;
        double temp_var_for_tac_38;
        temp_var_for_tac_38 = x + r;

        w = temp_var_for_tac_38;
        computeDMul((Addr)&temp_var_for_tac_36,
                    {(Addr) & (temp_var_for_const_22 = T[0]), (Addr)&s},
                    "/home/shijia/Public/testprogram/k_tan.c_e.c:133:13");
        computeDAdd((Addr)&temp_var_for_tac_38, {(Addr)&x, (Addr)&r},
                    "/home/shijia/Public/testprogram/k_tan.c_e.c:134:9");
        AssignD({(Addr)&w}, (Addr)&temp_var_for_tac_38,
                "/home/shijia/Public/testprogram/k_tan.c_e.c:134:5");
        ;
        if (ix >= IC(0x3FE59428))
        {
                double temp_var_for_const_23;
                v = ((double)iy);
                AssignD({(Addr)&v}, (Addr) & (temp_var_for_const_23 = ((double)iy)),
                        "/home/shijia/Public/testprogram/k_tan.c_e.c:136:7");
                ;
                double temp_var_for_ext_5;
                double temp_var_for_tac_39, temp_var_for_tac_40, temp_var_for_tac_41,
                    temp_var_for_tac_42, temp_var_for_tac_43, temp_var_for_tac_44,
                    temp_var_for_tac_45, temp_var_for_tac_46, temp_var_for_tac_47,
                    temp_var_for_tac_48, temp_var_for_tac_49;
                double temp_var_for_const_24, temp_var_for_const_25, temp_var_for_const_26,
                    temp_var_for_const_27, temp_var_for_const_28, temp_var_for_const_29;

                temp_var_for_tac_41 = (1 - ((hx >> 30) & 2));

                temp_var_for_tac_42 = w * w;

                temp_var_for_tac_43 = w + v;

                temp_var_for_tac_44 = temp_var_for_tac_42 / temp_var_for_tac_43;

                temp_var_for_tac_45 = temp_var_for_tac_44 - r;

                temp_var_for_tac_46 = x - temp_var_for_tac_45;

                temp_var_for_tac_47 = 2.0 * temp_var_for_tac_46;

                temp_var_for_tac_48 = v - temp_var_for_tac_47;

                temp_var_for_tac_49 = ((double)temp_var_for_tac_41) * temp_var_for_tac_48;

                temp_var_for_ext_5 = temp_var_for_tac_49;

                computeDMul((Addr)&temp_var_for_tac_42, {(Addr)&w, (Addr)&w},
                            "/home/shijia/Public/testprogram/k_tan.c_e.c:139:45");
                computeDAdd((Addr)&temp_var_for_tac_43, {(Addr)&w, (Addr)&v},
                            "/home/shijia/Public/testprogram/k_tan.c_e.c:139:54");
                computeDDiv((Addr)&temp_var_for_tac_44,
                            {(Addr)&temp_var_for_tac_42, (Addr)&temp_var_for_tac_43},
                            "/home/shijia/Public/testprogram/k_tan.c_e.c:139:49");
                computeDSub((Addr)&temp_var_for_tac_45,
                            {(Addr)&temp_var_for_tac_44, (Addr)&r},
                            "/home/shijia/Public/testprogram/k_tan.c_e.c:139:59");
                computeDSub((Addr)&temp_var_for_tac_46,
                            {(Addr)&x, (Addr)&temp_var_for_tac_45},
                            "/home/shijia/Public/testprogram/k_tan.c_e.c:139:40");
                computeDMul(
                    (Addr)&temp_var_for_tac_47,
                    {(Addr) & (temp_var_for_const_28 = 2.0), (Addr)&temp_var_for_tac_46},
                    "/home/shijia/Public/testprogram/k_tan.c_e.c:139:35");
                computeDSub((Addr)&temp_var_for_tac_48,
                            {(Addr)&v, (Addr)&temp_var_for_tac_47},
                            "/home/shijia/Public/testprogram/k_tan.c_e.c:139:29");
                computeDMul((Addr)&temp_var_for_tac_49,
                            {(Addr) & (temp_var_for_const_29 = ((double)temp_var_for_tac_41)),
                             (Addr)&temp_var_for_tac_48},
                            "/home/shijia/Public/testprogram/k_tan.c_e.c:138:57");
                AssignD({(Addr)&temp_var_for_ext_5}, (Addr)&temp_var_for_tac_49,
                        "/home/shijia/Public/testprogram/k_tan.c_e.c:138:24");
                ;
                callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
                callExp++; /*identify the function is  add move tmpShadow*/
                return temp_var_for_ext_5;
        }
        if (iy == 1)
        {
                double temp_var_for_ext_6;
                temp_var_for_ext_6 = w;
                callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
                callExp++; /*identify the function is  add move tmpShadow*/
                return temp_var_for_ext_6;
        }

        else
        {
                /*
   * if allow error up to 2 ulp, simply return
   * -1.0 / (x+r) here
   */
                /* compute -1.0 / (x+r) accurately */
                double a, t;

                z = w;
                SET_LOW_WORD(z, 0);
                double temp_var_for_tac_50, temp_var_for_tac_51;
                temp_var_for_tac_50 = z - x;

                temp_var_for_tac_51 = r - temp_var_for_tac_50;
                v = temp_var_for_tac_51;
                computeDSub((Addr)&temp_var_for_tac_50, {(Addr)&z, (Addr)&x},
                            "/home/shijia/Public/testprogram/k_tan.c_e.c:162:16");
                computeDSub((Addr)&temp_var_for_tac_51,
                            {(Addr)&r, (Addr)&temp_var_for_tac_50},
                            "/home/shijia/Public/testprogram/k_tan.c_e.c:162:11");
                AssignD({(Addr)&v}, (Addr)&temp_var_for_tac_51,
                        "/home/shijia/Public/testprogram/k_tan.c_e.c:163:11");
                ; /* z+v = r+x */
                double temp_var_for_tac_52, temp_var_for_tac_53;
                double temp_var_for_const_30, temp_var_for_const_31;
                temp_var_for_tac_52 = 0.0 - 1.0;

                temp_var_for_tac_53 = temp_var_for_tac_52 / w;

                a = temp_var_for_tac_53;

                computeDSub((Addr)&temp_var_for_tac_52,
                            {(Addr) & (temp_var_for_const_31 = 0.0),
                             (Addr) & (temp_var_for_const_30 = 1.0)},
                            "/home/shijia/Public/testprogram/k_tan.c_e.c:163:18");
                computeDDiv((Addr)&temp_var_for_tac_53,
                            {(Addr)&temp_var_for_tac_52, (Addr)&w},
                            "/home/shijia/Public/testprogram/k_tan.c_e.c:163:25");
                AssignD({(Addr)&a}, (Addr)&temp_var_for_tac_53,
                        "/home/shijia/Public/testprogram/k_tan.c_e.c:163:11");
                t = a;
                AssignD({(Addr)&t}, (Addr)&a,
                        "/home/shijia/Public/testprogram/k_tan.c_e.c:163:7");
                ; /* a = -1.0/w */
                SET_LOW_WORD(t, 0);
                double temp_var_for_tac_54, temp_var_for_tac_55;
                double temp_var_for_const_32;
                temp_var_for_tac_54 = t * z;

                temp_var_for_tac_55 = 1.0 + temp_var_for_tac_54;

                s = temp_var_for_tac_55;
                computeDMul((Addr)&temp_var_for_tac_54, {(Addr)&t, (Addr)&z},
                            "/home/shijia/Public/testprogram/k_tan.c_e.c:165:17");
                computeDAdd(
                    (Addr)&temp_var_for_tac_55,
                    {(Addr) & (temp_var_for_const_32 = 1.0), (Addr)&temp_var_for_tac_54},
                    "/home/shijia/Public/testprogram/k_tan.c_e.c:165:13");
                AssignD({(Addr)&s}, (Addr)&temp_var_for_tac_55,
                        "/home/shijia/Public/testprogram/k_tan.c_e.c:165:7");
                ;
                double temp_var_for_ext_7;
                double temp_var_for_tac_56, temp_var_for_tac_57, temp_var_for_tac_58,
                    temp_var_for_tac_59;
                temp_var_for_tac_56 = t * v;

                temp_var_for_tac_57 = s + temp_var_for_tac_56;

                temp_var_for_tac_58 = a * temp_var_for_tac_57;

                temp_var_for_tac_59 = t + temp_var_for_tac_58;

                temp_var_for_ext_7 = temp_var_for_tac_59;
                computeDMul((Addr)&temp_var_for_tac_56, {(Addr)&t, (Addr)&v},
                            "/home/shijia/Public/testprogram/k_tan.c_e.c:167:41");
                computeDAdd((Addr)&temp_var_for_tac_57,
                            {(Addr)&s, (Addr)&temp_var_for_tac_56},
                            "/home/shijia/Public/testprogram/k_tan.c_e.c:167:37");
                computeDMul((Addr)&temp_var_for_tac_58,
                            {(Addr)&a, (Addr)&temp_var_for_tac_57},
                            "/home/shijia/Public/testprogram/k_tan.c_e.c:167:32");
                computeDAdd((Addr)&temp_var_for_tac_59,
                            {(Addr)&t, (Addr)&temp_var_for_tac_58},
                            "/home/shijia/Public/testprogram/k_tan.c_e.c:167:28");
                AssignD({(Addr)&temp_var_for_ext_7}, (Addr)&temp_var_for_tac_59,
                        "/home/shijia/Public/testprogram/k_tan.c_e.c:167:24");
                ;
                callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
                callExp++; /*identify the function is  add move tmpShadow*/
                return temp_var_for_ext_7;
        }
}
