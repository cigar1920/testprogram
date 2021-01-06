#include "../ScDebug/scdebug.h"
/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 */

/*
  Long double expansions are
  Copyright (C) 2001 Stephen L. Moshier <moshier@na-net.ornl.gov>
  and are incorporated herein by permission of the author.  The author
  reserves the right to distribute this material elsewhere under different
  copying permissions.  These modifications are distributed here under
  the following terms:

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, see
    <http://www.gnu.org/licenses/>.  */

/* __ieee754_asin(x)
 * Method :
 *	Since  asin(x) = x + x^3/6 + x^5*3/40 + x^7*15/336 + ...
 *	we approximate asin(x) on [0,0.5] by
 *		asin(x) = x + x*x^2*R(x^2)
 *
 *	For x in [0.5,1]
 *		asin(x) = pi/2-2*asin(sqrt((1-x)/2))
 *	Let y = (1-x), z = y/2, s := sqrt(z), and pio2_hi+pio2_lo=pi/2;
 *	then for x>0.98
 *		asin(x) = pi/2 - 2*(s+s*z*R(z))
 *			= pio2_hi - (2*(s+s*z*R(z)) - pio2_lo)
 *	For x<=0.98, let pio4_hi = pio2_hi/2, then
 *		f = hi part of s;
 *		c = sqrt(z) - f = (z-f*f)/(s+f)		...f+c=sqrt(z)
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

#ifndef __NO_LONG_DOUBLE_MATH

#ifndef __have_fpu_asin

long double __ieee754_asinl(long double x) {
  long double t, w, p, q, c, r, s;
  int32_t ix;
  uint32_t se, i0, i1, k;

  static const long double one = 1.0L;
  static const long double hugeval = 1.0e+4932L;
  static const long double pio2_hi =
      0x1.921fb54442d1846ap+0L; /* pi/2 rounded to nearest to 64 bits.  */
  static const long double pio2_lo =
      (long double temp_var_for_tac_0;
       long double temp_var_for_const_0, temp_var_for_const_1;
       temp_var_for_tac_0 = 0.0 - 0x7.6733ae8fe47c65d8p-68L;

       ); /* pi/2 - pio2_hi rounded to nearest to 64
                                             bits.  */
  static const long double pio4_hi =
      0xc.90fdaa22168c235p-4L; /* pi/4 rounded to nearest to 64 bits.  */
                               /* coefficient for R(x^2) */
                               /* asin(x) = x + x^3 pS(x^2) / qS(x^2)
                                  0 <= x <= 0.5
                                  peak relative error 1.9e-21  */
  static const long double pS0 =
      (long double temp_var_for_tac_1;
       long double temp_var_for_const_2, temp_var_for_const_3;
       temp_var_for_tac_1 = 0.0 - 1.008714657938491626019651170502036851607E1L;

       );
  static const long double pS1 = 2.331460313214179572063441834101394865259E1L;
  static const long double pS2 =
      (long double temp_var_for_tac_2;
       long double temp_var_for_const_4, temp_var_for_const_5;
       temp_var_for_tac_2 = 0.0 - 1.863169762159016144159202387315381830227E1L;

       );
  static const long double pS3 = 5.930399351579141771077475766877674661747E0L;
  static const long double pS4 =
      (long double temp_var_for_tac_3;
       long double temp_var_for_const_6, temp_var_for_const_7;
       temp_var_for_tac_3 = 0.0 - 6.121291917696920296944056882932695185001E-1L;

       );
  static const long double pS5 = 3.776934006243367487161248678019350338383E-3L;
  static const long double qS0 =
      (long double temp_var_for_tac_4;
       long double temp_var_for_const_8, temp_var_for_const_9;
       temp_var_for_tac_4 = 0.0 - 6.052287947630949712886794360635592886517E1L;

       );
  static const long double qS1 = 1.671229145571899593737596543114258558503E2L;
  static const long double qS2 =
      (long double temp_var_for_tac_5;
       long double temp_var_for_const_10, temp_var_for_const_11;
       temp_var_for_tac_5 = 0.0 - 1.707840117062586426144397688315411324388E2L;

       );
  static const long double qS3 = 7.870295154902110425886636075950077640623E1L;
  static const long double qS4 =
      (long double temp_var_for_tac_6;
       long double temp_var_for_const_12, temp_var_for_const_13;
       temp_var_for_tac_6 = 0.0 - 1.568433562487314651121702982333303458814E1L;

       );
  /* 1.000000000000000000000000000000000000000E0 */

  long double temp_var_for_const_14;
  ew_u.value = x;
  computeLdSub((Addr)&temp_var_for_tac_0,
               {(Addr) &(temp_var_for_const_1 = 0.0),
                (Addr) &(temp_var_for_const_0 = 0x7.6733ae8fe47c65d8p-68L)},
               "/home/shijia/Public/testprogram/e_asinl.c_e.c:78:12");
  computeLdSub((Addr)&temp_var_for_tac_1,
               {(Addr) &(temp_var_for_const_3 = 0.0),
                (Addr) &(temp_var_for_const_2 =
                             1.008714657938491626019651170502036851607E1L)},
               "/home/shijia/Public/testprogram/e_asinl.c_e.c:88:12");
  computeLdSub((Addr)&temp_var_for_tac_2,
               {(Addr) &(temp_var_for_const_5 = 0.0),
                (Addr) &(temp_var_for_const_4 =
                             1.863169762159016144159202387315381830227E1L)},
               "/home/shijia/Public/testprogram/e_asinl.c_e.c:91:12");
  computeLdSub((Addr)&temp_var_for_tac_3,
               {(Addr) &(temp_var_for_const_7 = 0.0),
                (Addr) &(temp_var_for_const_6 =
                             6.121291917696920296944056882932695185001E-1L)},
               "/home/shijia/Public/testprogram/e_asinl.c_e.c:94:12");
  computeLdSub((Addr)&temp_var_for_tac_4,
               {(Addr) &(temp_var_for_const_9 = 0.0),
                (Addr) &(temp_var_for_const_8 =
                             6.052287947630949712886794360635592886517E1L)},
               "/home/shijia/Public/testprogram/e_asinl.c_e.c:97:12");
  computeLdSub((Addr)&temp_var_for_tac_5,
               {(Addr) &(temp_var_for_const_11 = 0.0),
                (Addr) &(temp_var_for_const_10 =
                             1.707840117062586426144397688315411324388E2L)},
               "/home/shijia/Public/testprogram/e_asinl.c_e.c:100:12");
  computeLdSub((Addr)&temp_var_for_tac_6,
               {(Addr) &(temp_var_for_const_13 = 0.0),
                (Addr) &(temp_var_for_const_12 =
                             1.568433562487314651121702982333303458814E1L)},
               "/home/shijia/Public/testprogram/e_asinl.c_e.c:103:12");
  AssignLd({(Addr) &(temp_var_for_const_14 = ew_u.value)}, (Addr)&x,
           "/home/shijia/Public/testprogram/e_asinl.c_e.c:106:3 "
           "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
  ;
  ix = se & 0x7fff;
  ix = (ix << 16) | (i0 >> 16);
  if (ix >= IC(0x3fff8000)) { /* |x|>= 1 */
    if (ix == IC(0x3fff8000) && ((i0 - UC(0x80000000)) | i1) == 0)
    /* asin(1)=+-pi/2 with inexact */
    {
      long double temp_var_for_ext_0;
      long double temp_var_for_tac_7, temp_var_for_tac_8, temp_var_for_tac_9;
      long double temp_var_for_const_15, temp_var_for_const_16;
      temp_var_for_tac_7 = x * pio2_hi;

      temp_var_for_tac_8 = x * pio2_lo;

      temp_var_for_tac_9 = temp_var_for_tac_7 + temp_var_for_tac_8;

      temp_var_for_ext_0 = temp_var_for_tac_9;
      computeLdMul((Addr)&temp_var_for_tac_7,
                   {(Addr)&x, (Addr) &(temp_var_for_const_15 = pio2_hi)},
                   "/home/shijia/Public/testprogram/e_asinl.c_e.c:114:30");
      computeLdMul((Addr)&temp_var_for_tac_8,
                   {(Addr)&x, (Addr) &(temp_var_for_const_16 = pio2_lo)},
                   "/home/shijia/Public/testprogram/e_asinl.c_e.c:114:44");
      computeLdAdd((Addr)&temp_var_for_tac_9,
                   {(Addr)&temp_var_for_tac_7, (Addr)&temp_var_for_tac_8},
                   "/home/shijia/Public/testprogram/e_asinl.c_e.c:114:40");
      AssignLd({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_9,
               "/home/shijia/Public/testprogram/e_asinl.c_e.c:114:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_0;
    }

    long double temp_var_for_ext_1;
    long double temp_var_for_tac_10, temp_var_for_tac_11, temp_var_for_tac_12;
    temp_var_for_tac_10 = x - x;

    temp_var_for_tac_11 = x - x;

    temp_var_for_tac_12 = temp_var_for_tac_10 / temp_var_for_tac_11;

    temp_var_for_ext_1 = temp_var_for_tac_12;
    computeLdSub((Addr)&temp_var_for_tac_10, {(Addr)&x, (Addr)&x},
                 "/home/shijia/Public/testprogram/e_asinl.c_e.c:122:29");
    computeLdSub((Addr)&temp_var_for_tac_11, {(Addr)&x, (Addr)&x},
                 "/home/shijia/Public/testprogram/e_asinl.c_e.c:122:39");
    computeLdDiv((Addr)&temp_var_for_tac_12,
                 {(Addr)&temp_var_for_tac_10, (Addr)&temp_var_for_tac_11},
                 "/home/shijia/Public/testprogram/e_asinl.c_e.c:122:34");
    AssignLd({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_12,
             "/home/shijia/Public/testprogram/e_asinl.c_e.c:122:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++;                 /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1; /* asin(|x|>1) is NaN */
  } else {
    if (ix < IC(0x3ffe8000)) {   /* |x|<0.5 */
      if (ix < IC(0x3fde8000)) { /* if |x| < 2**-33 */
        if (int temp_var_for_tac_13, temp_var_for_tac_14;
            int temp_var_for_const_17, temp_var_for_const_18;
            temp_var_for_tac_13 = hugeval + x;

            temp_var_for_tac_14 = temp_var_for_tac_13 > one;

            ) {
          long double temp_var_for_ext_2;
          temp_var_for_ext_2 = x;
          computeLdAdd((Addr)&temp_var_for_tac_13,
                       {(Addr) &(temp_var_for_const_17 = hugeval), (Addr)&x},
                       "/home/shijia/Public/testprogram/e_asinl.c_e.c:129:21");
          compute((Addr)&temp_var_for_tac_14,
                  {(Addr)&temp_var_for_tac_13,
                   (Addr) &(temp_var_for_const_18 = one)},
                  "/home/shijia/Public/testprogram/e_asinl.c_e.c:129:25");
          AssignLd({(Addr)&temp_var_for_ext_2}, (Addr)&x,
                   "/home/shijia/Public/testprogram/e_asinl.c_e.c:131:30");
          ;
          callExpStack.push(
              getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
          callExp++; /*identify the function is  add move tmpShadow*/
          return temp_var_for_ext_2;
        }
        /* return x with inexact if x!=0 */
      } else {
        long double temp_var_for_ext_3;
        long double temp_var_for_tac_15;
        temp_var_for_tac_15 = x * x;

        temp_var_for_ext_3 = temp_var_for_tac_15;
        computeLdMul((Addr)&temp_var_for_tac_15, {(Addr)&x, (Addr)&x},
                     "/home/shijia/Public/testprogram/e_asinl.c_e.c:140:32");
        AssignLd({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_15,
                 "/home/shijia/Public/testprogram/e_asinl.c_e.c:140:28");
        ; // t
          /*(r_ext_0)(r)(rn temp)(t)(rn
           * temp)(t)(r_ext_0)(r)(_)(_)(a)(m)(a)(m)(_)(_)(x)(hugeval)(x)(x)*/
        t = temp_var_for_ext_3;
        AssignLd({(Addr)&t}, (Addr)&temp_var_for_ext_3,
                 "/home/shijia/Public/testprogram/e_asinl.c_e.c:143:11");
        ;
        long double temp_var_for_tac_16, temp_var_for_tac_17,
            temp_var_for_tac_18, temp_var_for_tac_19, temp_var_for_tac_20,
            temp_var_for_tac_21, temp_var_for_tac_22, temp_var_for_tac_23,
            temp_var_for_tac_24, temp_var_for_tac_25, temp_var_for_tac_26;
        long double temp_var_for_const_19, temp_var_for_const_20,
            temp_var_for_const_21, temp_var_for_const_22, temp_var_for_const_23,
            temp_var_for_const_24;
        temp_var_for_tac_16 = t * pS5;

        temp_var_for_tac_17 = pS4 + temp_var_for_tac_16;

        temp_var_for_tac_18 = t * temp_var_for_tac_17;

        temp_var_for_tac_19 = pS3 + temp_var_for_tac_18;

        temp_var_for_tac_20 = t * temp_var_for_tac_19;

        temp_var_for_tac_21 = pS2 + temp_var_for_tac_20;

        temp_var_for_tac_22 = t * temp_var_for_tac_21;

        temp_var_for_tac_23 = pS1 + temp_var_for_tac_22;

        temp_var_for_tac_24 = t * temp_var_for_tac_23;

        temp_var_for_tac_25 = pS0 + temp_var_for_tac_24;

        temp_var_for_tac_26 = t * temp_var_for_tac_25;

        p = temp_var_for_tac_26;
        computeLdMul((Addr)&temp_var_for_tac_16,
                     {(Addr)&t, (Addr) &(temp_var_for_const_19 = pS5)},
                     "/home/shijia/Public/testprogram/e_asinl.c_e.c:144:70");
        computeLdAdd(
            (Addr)&temp_var_for_tac_17,
            {(Addr) &(temp_var_for_const_20 = pS4), (Addr)&temp_var_for_tac_16},
            "/home/shijia/Public/testprogram/e_asinl.c_e.c:144:66");
        computeLdMul((Addr)&temp_var_for_tac_18,
                     {(Addr)&t, (Addr)&temp_var_for_tac_17},
                     "/home/shijia/Public/testprogram/e_asinl.c_e.c:144:59");
        computeLdAdd(
            (Addr)&temp_var_for_tac_19,
            {(Addr) &(temp_var_for_const_21 = pS3), (Addr)&temp_var_for_tac_18},
            "/home/shijia/Public/testprogram/e_asinl.c_e.c:144:55");
        computeLdMul((Addr)&temp_var_for_tac_20,
                     {(Addr)&t, (Addr)&temp_var_for_tac_19},
                     "/home/shijia/Public/testprogram/e_asinl.c_e.c:144:48");
        computeLdAdd(
            (Addr)&temp_var_for_tac_21,
            {(Addr) &(temp_var_for_const_22 = pS2), (Addr)&temp_var_for_tac_20},
            "/home/shijia/Public/testprogram/e_asinl.c_e.c:144:44");
        computeLdMul((Addr)&temp_var_for_tac_22,
                     {(Addr)&t, (Addr)&temp_var_for_tac_21},
                     "/home/shijia/Public/testprogram/e_asinl.c_e.c:144:37");
        computeLdAdd(
            (Addr)&temp_var_for_tac_23,
            {(Addr) &(temp_var_for_const_23 = pS1), (Addr)&temp_var_for_tac_22},
            "/home/shijia/Public/testprogram/e_asinl.c_e.c:144:33");
        computeLdMul((Addr)&temp_var_for_tac_24,
                     {(Addr)&t, (Addr)&temp_var_for_tac_23},
                     "/home/shijia/Public/testprogram/e_asinl.c_e.c:144:26");
        computeLdAdd(
            (Addr)&temp_var_for_tac_25,
            {(Addr) &(temp_var_for_const_24 = pS0), (Addr)&temp_var_for_tac_24},
            "/home/shijia/Public/testprogram/e_asinl.c_e.c:144:22");
        computeLdMul((Addr)&temp_var_for_tac_26,
                     {(Addr)&t, (Addr)&temp_var_for_tac_25},
                     "/home/shijia/Public/testprogram/e_asinl.c_e.c:144:15");
        AssignLd({(Addr)&p}, (Addr)&temp_var_for_tac_26,
                 "/home/shijia/Public/testprogram/e_asinl.c_e.c:144:11");
        ;
        long double temp_var_for_tac_27, temp_var_for_tac_28,
            temp_var_for_tac_29, temp_var_for_tac_30, temp_var_for_tac_31,
            temp_var_for_tac_32, temp_var_for_tac_33, temp_var_for_tac_34,
            temp_var_for_tac_35;
        long double temp_var_for_const_25, temp_var_for_const_26,
            temp_var_for_const_27, temp_var_for_const_28, temp_var_for_const_29;
        temp_var_for_tac_27 = qS4 + t;

        temp_var_for_tac_28 = t * temp_var_for_tac_27;

        temp_var_for_tac_29 = qS3 + temp_var_for_tac_28;

        temp_var_for_tac_30 = t * temp_var_for_tac_29;

        temp_var_for_tac_31 = qS2 + temp_var_for_tac_30;

        temp_var_for_tac_32 = t * temp_var_for_tac_31;

        temp_var_for_tac_33 = qS1 + temp_var_for_tac_32;

        temp_var_for_tac_34 = t * temp_var_for_tac_33;

        temp_var_for_tac_35 = qS0 + temp_var_for_tac_34;

        q = temp_var_for_tac_35;
        computeLdAdd((Addr)&temp_var_for_tac_27,
                     {(Addr) &(temp_var_for_const_25 = qS4), (Addr)&t},
                     "/home/shijia/Public/testprogram/e_asinl.c_e.c:145:61");
        computeLdMul((Addr)&temp_var_for_tac_28,
                     {(Addr)&t, (Addr)&temp_var_for_tac_27},
                     "/home/shijia/Public/testprogram/e_asinl.c_e.c:145:54");
        computeLdAdd(
            (Addr)&temp_var_for_tac_29,
            {(Addr) &(temp_var_for_const_26 = qS3), (Addr)&temp_var_for_tac_28},
            "/home/shijia/Public/testprogram/e_asinl.c_e.c:145:50");
        computeLdMul((Addr)&temp_var_for_tac_30,
                     {(Addr)&t, (Addr)&temp_var_for_tac_29},
                     "/home/shijia/Public/testprogram/e_asinl.c_e.c:145:43");
        computeLdAdd(
            (Addr)&temp_var_for_tac_31,
            {(Addr) &(temp_var_for_const_27 = qS2), (Addr)&temp_var_for_tac_30},
            "/home/shijia/Public/testprogram/e_asinl.c_e.c:145:39");
        computeLdMul((Addr)&temp_var_for_tac_32,
                     {(Addr)&t, (Addr)&temp_var_for_tac_31},
                     "/home/shijia/Public/testprogram/e_asinl.c_e.c:145:32");
        computeLdAdd(
            (Addr)&temp_var_for_tac_33,
            {(Addr) &(temp_var_for_const_28 = qS1), (Addr)&temp_var_for_tac_32},
            "/home/shijia/Public/testprogram/e_asinl.c_e.c:145:28");
        computeLdMul((Addr)&temp_var_for_tac_34,
                     {(Addr)&t, (Addr)&temp_var_for_tac_33},
                     "/home/shijia/Public/testprogram/e_asinl.c_e.c:145:21");
        computeLdAdd(
            (Addr)&temp_var_for_tac_35,
            {(Addr) &(temp_var_for_const_29 = qS0), (Addr)&temp_var_for_tac_34},
            "/home/shijia/Public/testprogram/e_asinl.c_e.c:145:17");
        AssignLd({(Addr)&q}, (Addr)&temp_var_for_tac_35,
                 "/home/shijia/Public/testprogram/e_asinl.c_e.c:145:11");
        ;
        long double temp_var_for_tac_36;
        temp_var_for_tac_36 = p / q;

        w = temp_var_for_tac_36;
        computeLdDiv((Addr)&temp_var_for_tac_36, {(Addr)&p, (Addr)&q},
                     "/home/shijia/Public/testprogram/e_asinl.c_e.c:146:15");
        AssignLd({(Addr)&w}, (Addr)&temp_var_for_tac_36,
                 "/home/shijia/Public/testprogram/e_asinl.c_e.c:146:11");
        ;
        long double temp_var_for_ext_4;
        long double temp_var_for_tac_37, temp_var_for_tac_38;
        temp_var_for_tac_37 = x * w;

        temp_var_for_tac_38 = x + temp_var_for_tac_37;

        temp_var_for_ext_4 = temp_var_for_tac_38;
        computeLdMul((Addr)&temp_var_for_tac_37, {(Addr)&x, (Addr)&w},
                     "/home/shijia/Public/testprogram/e_asinl.c_e.c:148:36");
        computeLdAdd((Addr)&temp_var_for_tac_38,
                     {(Addr)&x, (Addr)&temp_var_for_tac_37},
                     "/home/shijia/Public/testprogram/e_asinl.c_e.c:148:32");
        AssignLd({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_38,
                 "/home/shijia/Public/testprogram/e_asinl.c_e.c:148:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_4;
      }
    }
  }

  /* 1> |x|>= 0.5 */
  long double temp_var_for_tac_39;
  long double temp_var_for_const_30, temp_var_for_const_31;
  long double temp_var_for_callexp_0;

  temp_var_for_callexp_0 = fabsl(x);
  temp_var_for_tac_39 = one - temp_var_for_callexp_0;

  w = temp_var_for_tac_39;
  computeLdSub((Addr)&temp_var_for_tac_39,
               {(Addr) &(temp_var_for_const_31 = one),
                (Addr) &(temp_var_for_const_30 = temp_var_for_callexp_0)},
               "/home/shijia/Public/testprogram/e_asinl.c_e.c:158:11");
  AssignLd({(Addr)&w}, (Addr)&temp_var_for_tac_39,
           "/home/shijia/Public/testprogram/e_asinl.c_e.c:158:5");
  ;
  long double temp_var_for_tac_40;
  long double temp_var_for_const_32;
  temp_var_for_tac_40 = w * 0.5;

  t = temp_var_for_tac_40;
  computeLdMul((Addr)&temp_var_for_tac_40,
               {(Addr)&w, (Addr) &(temp_var_for_const_32 = 0.5)},
               "/home/shijia/Public/testprogram/e_asinl.c_e.c:159:9");
  AssignLd({(Addr)&t}, (Addr)&temp_var_for_tac_40,
           "/home/shijia/Public/testprogram/e_asinl.c_e.c:159:5");
  ;
  long double temp_var_for_tac_41, temp_var_for_tac_42, temp_var_for_tac_43,
      temp_var_for_tac_44, temp_var_for_tac_45, temp_var_for_tac_46,
      temp_var_for_tac_47, temp_var_for_tac_48, temp_var_for_tac_49,
      temp_var_for_tac_50, temp_var_for_tac_51;
  long double temp_var_for_const_33, temp_var_for_const_34,
      temp_var_for_const_35, temp_var_for_const_36, temp_var_for_const_37,
      temp_var_for_const_38;
  temp_var_for_tac_41 = t * pS5;

  temp_var_for_tac_42 = pS4 + temp_var_for_tac_41;

  temp_var_for_tac_43 = t * temp_var_for_tac_42;

  temp_var_for_tac_44 = pS3 + temp_var_for_tac_43;

  temp_var_for_tac_45 = t * temp_var_for_tac_44;

  temp_var_for_tac_46 = pS2 + temp_var_for_tac_45;

  temp_var_for_tac_47 = t * temp_var_for_tac_46;

  temp_var_for_tac_48 = pS1 + temp_var_for_tac_47;

  temp_var_for_tac_49 = t * temp_var_for_tac_48;

  temp_var_for_tac_50 = pS0 + temp_var_for_tac_49;

  temp_var_for_tac_51 = t * temp_var_for_tac_50;

  p = temp_var_for_tac_51;
  computeLdMul((Addr)&temp_var_for_tac_41,
               {(Addr)&t, (Addr) &(temp_var_for_const_33 = pS5)},
               "/home/shijia/Public/testprogram/e_asinl.c_e.c:160:64");
  computeLdAdd(
      (Addr)&temp_var_for_tac_42,
      {(Addr) &(temp_var_for_const_34 = pS4), (Addr)&temp_var_for_tac_41},
      "/home/shijia/Public/testprogram/e_asinl.c_e.c:160:60");
  computeLdMul((Addr)&temp_var_for_tac_43,
               {(Addr)&t, (Addr)&temp_var_for_tac_42},
               "/home/shijia/Public/testprogram/e_asinl.c_e.c:160:53");
  computeLdAdd(
      (Addr)&temp_var_for_tac_44,
      {(Addr) &(temp_var_for_const_35 = pS3), (Addr)&temp_var_for_tac_43},
      "/home/shijia/Public/testprogram/e_asinl.c_e.c:160:49");
  computeLdMul((Addr)&temp_var_for_tac_45,
               {(Addr)&t, (Addr)&temp_var_for_tac_44},
               "/home/shijia/Public/testprogram/e_asinl.c_e.c:160:42");
  computeLdAdd(
      (Addr)&temp_var_for_tac_46,
      {(Addr) &(temp_var_for_const_36 = pS2), (Addr)&temp_var_for_tac_45},
      "/home/shijia/Public/testprogram/e_asinl.c_e.c:160:38");
  computeLdMul((Addr)&temp_var_for_tac_47,
               {(Addr)&t, (Addr)&temp_var_for_tac_46},
               "/home/shijia/Public/testprogram/e_asinl.c_e.c:160:31");
  computeLdAdd(
      (Addr)&temp_var_for_tac_48,
      {(Addr) &(temp_var_for_const_37 = pS1), (Addr)&temp_var_for_tac_47},
      "/home/shijia/Public/testprogram/e_asinl.c_e.c:160:27");
  computeLdMul((Addr)&temp_var_for_tac_49,
               {(Addr)&t, (Addr)&temp_var_for_tac_48},
               "/home/shijia/Public/testprogram/e_asinl.c_e.c:160:20");
  computeLdAdd(
      (Addr)&temp_var_for_tac_50,
      {(Addr) &(temp_var_for_const_38 = pS0), (Addr)&temp_var_for_tac_49},
      "/home/shijia/Public/testprogram/e_asinl.c_e.c:160:16");
  computeLdMul((Addr)&temp_var_for_tac_51,
               {(Addr)&t, (Addr)&temp_var_for_tac_50},
               "/home/shijia/Public/testprogram/e_asinl.c_e.c:160:9");
  AssignLd({(Addr)&p}, (Addr)&temp_var_for_tac_51,
           "/home/shijia/Public/testprogram/e_asinl.c_e.c:160:5");
  ;
  long double temp_var_for_tac_52, temp_var_for_tac_53, temp_var_for_tac_54,
      temp_var_for_tac_55, temp_var_for_tac_56, temp_var_for_tac_57,
      temp_var_for_tac_58, temp_var_for_tac_59, temp_var_for_tac_60;
  long double temp_var_for_const_39, temp_var_for_const_40,
      temp_var_for_const_41, temp_var_for_const_42, temp_var_for_const_43;
  temp_var_for_tac_52 = qS4 + t;

  temp_var_for_tac_53 = t * temp_var_for_tac_52;

  temp_var_for_tac_54 = qS3 + temp_var_for_tac_53;

  temp_var_for_tac_55 = t * temp_var_for_tac_54;

  temp_var_for_tac_56 = qS2 + temp_var_for_tac_55;

  temp_var_for_tac_57 = t * temp_var_for_tac_56;

  temp_var_for_tac_58 = qS1 + temp_var_for_tac_57;

  temp_var_for_tac_59 = t * temp_var_for_tac_58;

  temp_var_for_tac_60 = qS0 + temp_var_for_tac_59;

  q = temp_var_for_tac_60;
  computeLdAdd((Addr)&temp_var_for_tac_52,
               {(Addr) &(temp_var_for_const_39 = qS4), (Addr)&t},
               "/home/shijia/Public/testprogram/e_asinl.c_e.c:161:55");
  computeLdMul((Addr)&temp_var_for_tac_53,
               {(Addr)&t, (Addr)&temp_var_for_tac_52},
               "/home/shijia/Public/testprogram/e_asinl.c_e.c:161:48");
  computeLdAdd(
      (Addr)&temp_var_for_tac_54,
      {(Addr) &(temp_var_for_const_40 = qS3), (Addr)&temp_var_for_tac_53},
      "/home/shijia/Public/testprogram/e_asinl.c_e.c:161:44");
  computeLdMul((Addr)&temp_var_for_tac_55,
               {(Addr)&t, (Addr)&temp_var_for_tac_54},
               "/home/shijia/Public/testprogram/e_asinl.c_e.c:161:37");
  computeLdAdd(
      (Addr)&temp_var_for_tac_56,
      {(Addr) &(temp_var_for_const_41 = qS2), (Addr)&temp_var_for_tac_55},
      "/home/shijia/Public/testprogram/e_asinl.c_e.c:161:33");
  computeLdMul((Addr)&temp_var_for_tac_57,
               {(Addr)&t, (Addr)&temp_var_for_tac_56},
               "/home/shijia/Public/testprogram/e_asinl.c_e.c:161:26");
  computeLdAdd(
      (Addr)&temp_var_for_tac_58,
      {(Addr) &(temp_var_for_const_42 = qS1), (Addr)&temp_var_for_tac_57},
      "/home/shijia/Public/testprogram/e_asinl.c_e.c:161:22");
  computeLdMul((Addr)&temp_var_for_tac_59,
               {(Addr)&t, (Addr)&temp_var_for_tac_58},
               "/home/shijia/Public/testprogram/e_asinl.c_e.c:161:15");
  computeLdAdd(
      (Addr)&temp_var_for_tac_60,
      {(Addr) &(temp_var_for_const_43 = qS0), (Addr)&temp_var_for_tac_59},
      "/home/shijia/Public/testprogram/e_asinl.c_e.c:161:11");
  AssignLd({(Addr)&q}, (Addr)&temp_var_for_tac_60,
           "/home/shijia/Public/testprogram/e_asinl.c_e.c:161:5");
  ;
  long double temp_var_for_const_44;
  long double temp_var_for_callexp_1;

  temp_var_for_callexp_1 = __ieee754_sqrtl(t);
  s = temp_var_for_callexp_1;
  AssignLd({(Addr)&s}, (Addr) &(temp_var_for_const_44 = temp_var_for_callexp_1),
           "/home/shijia/Public/testprogram/e_asinl.c_e.c:162:5");
  ;
  if (ix >= IC(0x3ffef999)) { /* if |x| > 0.975 */
    long double temp_var_for_tac_61;
    temp_var_for_tac_61 = p / q;

    w = temp_var_for_tac_61;
    computeLdDiv((Addr)&temp_var_for_tac_61, {(Addr)&p, (Addr)&q},
                 "/home/shijia/Public/testprogram/e_asinl.c_e.c:164:11");
    AssignLd({(Addr)&w}, (Addr)&temp_var_for_tac_61,
             "/home/shijia/Public/testprogram/e_asinl.c_e.c:164:7");
    ;
    long double temp_var_for_tac_62, temp_var_for_tac_63, temp_var_for_tac_64,
        temp_var_for_tac_65, temp_var_for_tac_66;
    long double temp_var_for_const_45, temp_var_for_const_46,
        temp_var_for_const_47;
    temp_var_for_tac_62 = s * w;

    temp_var_for_tac_63 = s + temp_var_for_tac_62;

    temp_var_for_tac_64 = 2.0 * temp_var_for_tac_63;

    temp_var_for_tac_65 = temp_var_for_tac_64 - pio2_lo;

    temp_var_for_tac_66 = pio2_hi - temp_var_for_tac_65;

    t = temp_var_for_tac_66;
    computeLdMul((Addr)&temp_var_for_tac_62, {(Addr)&s, (Addr)&w},
                 "/home/shijia/Public/testprogram/e_asinl.c_e.c:165:33");
    computeLdAdd((Addr)&temp_var_for_tac_63,
                 {(Addr)&s, (Addr)&temp_var_for_tac_62},
                 "/home/shijia/Public/testprogram/e_asinl.c_e.c:165:29");
    computeLdMul(
        (Addr)&temp_var_for_tac_64,
        {(Addr) &(temp_var_for_const_45 = 2.0), (Addr)&temp_var_for_tac_63},
        "/home/shijia/Public/testprogram/e_asinl.c_e.c:165:24");
    computeLdSub(
        (Addr)&temp_var_for_tac_65,
        {(Addr)&temp_var_for_tac_64, (Addr) &(temp_var_for_const_46 = pio2_lo)},
        "/home/shijia/Public/testprogram/e_asinl.c_e.c:165:38");
    computeLdSub(
        (Addr)&temp_var_for_tac_66,
        {(Addr) &(temp_var_for_const_47 = pio2_hi), (Addr)&temp_var_for_tac_65},
        "/home/shijia/Public/testprogram/e_asinl.c_e.c:165:17");
    AssignLd({(Addr)&t}, (Addr)&temp_var_for_tac_66,
             "/home/shijia/Public/testprogram/e_asinl.c_e.c:165:7");
    ;
  } else {
    long double temp_var_for_const_48;
    ew_u.value = s;
    AssignLd({(Addr) &(temp_var_for_const_48 = ew_u.value)}, (Addr)&s,
             "/home/shijia/Public/testprogram/e_asinl.c_e.c:167:5 "
             "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
    ;
    i1 = 0;
    long double temp_var_for_ext_5;
    temp_var_for_ext_5;
    long double temp_var_for_tac_67, temp_var_for_tac_68, temp_var_for_tac_69,
        temp_var_for_tac_70;
    temp_var_for_tac_67 = w * w;

    temp_var_for_tac_68 = t - temp_var_for_tac_67;

    temp_var_for_tac_69 = s + w;

    temp_var_for_tac_70 = temp_var_for_tac_68 / temp_var_for_tac_69;

    c = temp_var_for_tac_70;
    computeLdMul((Addr)&temp_var_for_tac_67, {(Addr)&w, (Addr)&w},
                 "/home/shijia/Public/testprogram/e_asinl.c_e.c:171:16");
    computeLdSub((Addr)&temp_var_for_tac_68,
                 {(Addr)&t, (Addr)&temp_var_for_tac_67},
                 "/home/shijia/Public/testprogram/e_asinl.c_e.c:171:12");
    computeLdAdd((Addr)&temp_var_for_tac_69, {(Addr)&s, (Addr)&w},
                 "/home/shijia/Public/testprogram/e_asinl.c_e.c:171:26");
    computeLdDiv((Addr)&temp_var_for_tac_70,
                 {(Addr)&temp_var_for_tac_68, (Addr)&temp_var_for_tac_69},
                 "/home/shijia/Public/testprogram/e_asinl.c_e.c:171:21");
    AssignLd({(Addr)&c}, (Addr)&temp_var_for_tac_70,
             "/home/shijia/Public/testprogram/e_asinl.c_e.c:171:7");
    ;
    long double temp_var_for_tac_71;
    temp_var_for_tac_71 = p / q;

    r = temp_var_for_tac_71;
    computeLdDiv((Addr)&temp_var_for_tac_71, {(Addr)&p, (Addr)&q},
                 "/home/shijia/Public/testprogram/e_asinl.c_e.c:172:11");
    AssignLd({(Addr)&r}, (Addr)&temp_var_for_tac_71,
             "/home/shijia/Public/testprogram/e_asinl.c_e.c:172:7");
    ;
    long double temp_var_for_ext_6;
    long double temp_var_for_tac_72, temp_var_for_tac_73, temp_var_for_tac_74,
        temp_var_for_tac_75, temp_var_for_tac_76;
    long double temp_var_for_const_49, temp_var_for_const_50,
        temp_var_for_const_51;
    temp_var_for_tac_72 = 2.0 * s;

    temp_var_for_tac_73 = temp_var_for_tac_72 * r;

    temp_var_for_tac_74 = 2.0 * c;

    temp_var_for_tac_75 = pio2_lo - temp_var_for_tac_74;

    temp_var_for_tac_76 = temp_var_for_tac_73 - temp_var_for_tac_75;

    temp_var_for_ext_6 = temp_var_for_tac_76;
    computeLdMul((Addr)&temp_var_for_tac_72,
                 {(Addr) &(temp_var_for_const_49 = 2.0), (Addr)&s},
                 "/home/shijia/Public/testprogram/e_asinl.c_e.c:174:30");
    computeLdMul((Addr)&temp_var_for_tac_73,
                 {(Addr)&temp_var_for_tac_72, (Addr)&r},
                 "/home/shijia/Public/testprogram/e_asinl.c_e.c:174:34");
    computeLdMul((Addr)&temp_var_for_tac_74,
                 {(Addr) &(temp_var_for_const_50 = 2.0), (Addr)&c},
                 "/home/shijia/Public/testprogram/e_asinl.c_e.c:174:55");
    computeLdSub(
        (Addr)&temp_var_for_tac_75,
        {(Addr) &(temp_var_for_const_51 = pio2_lo), (Addr)&temp_var_for_tac_74},
        "/home/shijia/Public/testprogram/e_asinl.c_e.c:174:49");
    computeLdSub((Addr)&temp_var_for_tac_76,
                 {(Addr)&temp_var_for_tac_73, (Addr)&temp_var_for_tac_75},
                 "/home/shijia/Public/testprogram/e_asinl.c_e.c:174:38");
    AssignLd({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_76,
             "/home/shijia/Public/testprogram/e_asinl.c_e.c:174:24");
    ; // p
    /*(q)(p)(c)(2.0)(pio2_lo)(r)(s)(2.0)*/
    p = temp_var_for_ext_6;
    AssignLd({(Addr)&p}, (Addr)&temp_var_for_ext_6,
             "/home/shijia/Public/testprogram/e_asinl.c_e.c:176:7");
    ;
    long double temp_var_for_tac_77, temp_var_for_tac_78;
    long double temp_var_for_const_52, temp_var_for_const_53;
    temp_var_for_tac_77 = 2.0 * w;

    temp_var_for_tac_78 = pio4_hi - temp_var_for_tac_77;

    q = temp_var_for_tac_78;
    computeLdMul((Addr)&temp_var_for_tac_77,
                 {(Addr) &(temp_var_for_const_52 = 2.0), (Addr)&w},
                 "/home/shijia/Public/testprogram/e_asinl.c_e.c:177:23");
    computeLdSub(
        (Addr)&temp_var_for_tac_78,
        {(Addr) &(temp_var_for_const_53 = pio4_hi), (Addr)&temp_var_for_tac_77},
        "/home/shijia/Public/testprogram/e_asinl.c_e.c:177:17");
    AssignLd({(Addr)&q}, (Addr)&temp_var_for_tac_78,
             "/home/shijia/Public/testprogram/e_asinl.c_e.c:177:7");
    ;
    long double temp_var_for_tac_79, temp_var_for_tac_80;
    long double temp_var_for_const_54;
    temp_var_for_tac_79 = p - q;

    temp_var_for_tac_80 = pio4_hi - temp_var_for_tac_79;

    t = temp_var_for_tac_80;
    computeLdSub((Addr)&temp_var_for_tac_79, {(Addr)&p, (Addr)&q},
                 "/home/shijia/Public/testprogram/e_asinl.c_e.c:178:22");
    computeLdSub(
        (Addr)&temp_var_for_tac_80,
        {(Addr) &(temp_var_for_const_54 = pio4_hi), (Addr)&temp_var_for_tac_79},
        "/home/shijia/Public/testprogram/e_asinl.c_e.c:178:17");
    AssignLd({(Addr)&t}, (Addr)&temp_var_for_tac_80,
             "/home/shijia/Public/testprogram/e_asinl.c_e.c:178:7");
    ;
  }
  if ((se & 0x8000) == 0) {
    long double temp_var_for_ext_7;
    temp_var_for_ext_7 = t;
    AssignLd({(Addr)&temp_var_for_ext_7}, (Addr)&t,
             "/home/shijia/Public/testprogram/e_asinl.c_e.c:182:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_7;
  }

  long double temp_var_for_ext_8;
  long double temp_var_for_const_55;
  temp_var_for_ext_8 = (-(t));
  AssignLd({(Addr)&temp_var_for_ext_8},
           (Addr) &(temp_var_for_const_55 = (-(t))),
           "/home/shijia/Public/testprogram/e_asinl.c_e.c:189:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
  callExp++; /*identify the function is  add move tmpShadow*/
  return (double temp_var_for_tac_81;
          double temp_var_for_const_56, temp_var_for_const_57;
          temp_var_for_tac_81 = 0.0 - 8;

          );
}

#endif

/* wrapper asin */
long double __asinl(long double x) {
  if (isgreater(__ieee754_fabsl(x), 1.0) && _LIB_VERSION != _IEEE_) {
    /* asin(|x|>1) */
    feraiseexcept(FE_INVALID);
    long double temp_var_for_ext_9;
    long double temp_var_for_const_58;
    long double temp_var_for_callexp_2;

    /*embed fun has found*/
    long double temp_var_for_callexp_3;

    temp_var_for_callexp_2 = __builtin_nanl("");
    temp_var_for_callexp_3 =
        __kernel_standard_l(x, x, temp_var_for_callexp_2, KMATHERRL_ASIN);
    temp_var_for_ext_9 = temp_var_for_callexp_3;
    computeDSub((Addr)&temp_var_for_tac_81,
                {(Addr) &(temp_var_for_const_57 = 0.0),
                 (Addr) &(temp_var_for_const_56 = 8)},
                "/home/shijia/Public/testprogram/e_asinl.c_e.c:192:15");
    AssignLd({(Addr)&temp_var_for_ext_9},
             (Addr) &(temp_var_for_const_58 = temp_var_for_callexp_3),
             "/home/shijia/Public/testprogram/e_asinl.c_e.c:203:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_9;
  }

  long double temp_var_for_ext_10;
  long double temp_var_for_const_59;
  long double temp_var_for_callexp_4;

  temp_var_for_callexp_4 = __ieee754_asinl(x);
  temp_var_for_ext_10 = temp_var_for_callexp_4;
  AssignLd({(Addr)&temp_var_for_ext_10},
           (Addr) &(temp_var_for_const_59 = temp_var_for_callexp_4),
           "/home/shijia/Public/testprogram/e_asinl.c_e.c:211:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_10", (Addr)&temp_var_for_ext_10));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_10;
}

__typeof(__asinl) asinl __attribute__((weak, alias("__asinl")));

#endif
