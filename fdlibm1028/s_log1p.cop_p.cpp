#include "../ScDebug/scdebug.h"
/* @(#)s_log1p.c 1.3 95/01/18 */
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
/* Modified by Naohiko Shimizu/Tokai University, Japan 1997/08/25,
   for performance improvement on pipelined processors.
*/

/* double log1p(double x)
 *
 * Method :
 *   1. Argument Reduction: find k and f such that
 *			1+x = 2^k * (1+f),
 *	   where  sqrt(2)/2 < 1+f < sqrt(2) .
 *
 *      Note. If k=0, then f=x is exact. However, if k!=0, then f
 *	may not be representable exactly. In that case, a correction
 *	term is need. Let u=1+x rounded. Let c = (1+x)-u, then
 *	log(1+x) - log(u) ~ c/u. Thus, we proceed to compute log(u),
 *	and add back the correction term c/u.
 *	(Note: when x > 2**53, one can simply return log(x))
 *
 *   2. Approximation of log1p(f).
 *	Let s = f/(2+f) ; based on log(1+f) = log(1+s) - log(1-s)
 *		 = 2s + 2/3 s**3 + 2/5 s**5 + .....,
 *	     = 2s + s*R
 *      We use a special Reme algorithm on [0,0.1716] to generate
 *	a polynomial of degree 14 to approximate R The maximum error
 *	of this polynomial approximation is bounded by 2**-58.45. In
 *	other words,
 *		        2      4      6      8      10      12      14
 *	    R(z) ~ Lp1*s +Lp2*s +Lp3*s +Lp4*s +Lp5*s  +Lp6*s  +Lp7*s
 *  	(the values of Lp1 to Lp7 are listed in the program)
 *	and
 *	    |      2          14          |     -58.45
 *	    | Lp1*s +...+Lp7*s    -  R(z) | <= 2
 *	    |                             |
 *	Note that 2s = f - s*f = f - hfsq + s*hfsq, where hfsq = f*f/2.
 *	In order to guarantee error in log below 1ulp, we compute log
 *	by
 *		log1p(f) = f - (hfsq - s*(hfsq+R)).
 *
 *	3. Finally, log1p(x) = k*ln2 + log1p(f).
 *			     = k*ln2_hi+(f-(hfsq-(s*(hfsq+R)+k*ln2_lo)))
 *	   Here ln2 is split into two floating point number:
 *			ln2_hi + ln2_lo,
 *	   where n*ln2_hi is always exact for |n| < 2000.
 *
 * Special cases:
 *	log1p(x) is NaN with signal if x < -1 (including -INF) ;
 *	log1p(+INF) is +INF; log1p(-1) is -INF with signal;
 *	log1p(NaN) is that NaN with no signal.
 *
 * Accuracy:
 *	according to an error analysis, the error is always less than
 *	1 ulp (unit in the last place).
 *
 * Constants:
 * The hexadecimal values are the intended ones for the following
 * constants. The decimal values may be used, provided that the
 * compiler will convert from decimal to binary accurately enough
 * to produce the hexadecimal values shown.
 *
 * Note: Assuming log() return accurate answer, the following
 *	 algorithm can be used to compute log1p(x) to within a few ULP:
 *
 *		u = 1+x;
 *		if(u==1.0) return x ; else
 *			   return log(u)*(x/(u-1.0));
 *
 *	 See HP-15C Advanced Functions Handbook, p.193.
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_log1p

double __ieee754_log1p(double x) {
  double hfsq, f, c, s, z, R, u, z2, z4, z6, R1, R2, R3, R4;
  int32_t k, hx, hu, ax;

  static const double ln2_hi =
      6.93147180369123816490e-01; /* 3fe62e42 fee00000 */
  static const double ln2_lo =
      1.90821492927058770002e-10; /* 3dea39ef 35793c76 */
  static const double two54 =
      1.80143985094819840000e+16; /* 43500000 00000000 */
  static const double Lp[] = {
      0.0, 6.666666666666735130e-01, /* 3FE55555 55555593 */
      3.999999999940941908e-01,      /* 3FD99999 9997FA04 */
      2.857142874366239149e-01,      /* 3FD24924 94229359 */
      2.222219843214978396e-01,      /* 3FCC71C5 1D8E78AF */
      1.818357216161805012e-01,      /* 3FC74664 96CB03DE */
      1.531383769920937332e-01,      /* 3FC39A09 D078C69F */
      1.479819860511658591e-01       /* 3FC2F112 DF3E5244 */
  };
  static const double zero = 0.0;

  GET_HIGH_WORD(hx, x);
  ax = hx & IC(0x7fffffff);

  k = 1;
  if (hx < IC(0x3FDA827A)) {    /* x < 0.41422  */
    if (ax >= IC(0x3ff00000)) { /* x <= -1.0 */
      if (int temp_var_for_tac_0, temp_var_for_tac_1;
          int temp_var_for_const_0, temp_var_for_const_1;
          temp_var_for_tac_0 = 0.0 - 1.0;

          temp_var_for_tac_1 = x == temp_var_for_tac_0;

          ) {
        double temp_var_for_ext_0;
        double temp_var_for_tac_2;
        double temp_var_for_const_2, temp_var_for_const_3;
        temp_var_for_tac_2 = (-(two54)) / zero;

        temp_var_for_ext_0 = temp_var_for_tac_2;
        computeDSub((Addr)&temp_var_for_tac_0,
                    {(Addr) &(temp_var_for_const_1 = 0.0),
                     (Addr) &(temp_var_for_const_0 = 1.0)},
                    "/home/shijia/Public/testprogram/s_log1p.c_e.c:114:21");
        compute((Addr)&temp_var_for_tac_1,
                {(Addr)&x, (Addr)&temp_var_for_tac_0},
                "/home/shijia/Public/testprogram/s_log1p.c_e.c:114:13");
        computeDDiv((Addr)&temp_var_for_tac_2,
                    {(Addr) &(temp_var_for_const_3 = (-(two54))),
                     (Addr) &(temp_var_for_const_2 = zero)},
                    "/home/shijia/Public/testprogram/s_log1p.c_e.c:116:37");
        AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_2,
                "/home/shijia/Public/testprogram/s_log1p.c_e.c:116:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
        callExp++; /*identify the function is  add move tmpShadow*/
        return (0.0 - ar_fo)r_ext_0;
      }
      /* log1p(-1)=+inf */
      else {
        double temp_var_for_ext_1;
        double temp_var_for_tac_3, temp_var_for_tac_4, temp_var_for_tac_5;
        temp_var_for_tac_3 = x - x;

        temp_var_for_tac_4 = x - x;

        temp_var_for_tac_5 = temp_var_for_tac_3 / temp_var_for_tac_4;

        temp_var_for_ext_1 = temp_var_for_tac_5;
        computeDSub((Addr)&temp_var_for_tac_3, {(Addr)&x, (Addr)&x},
                    "/home/shijia/Public/testprogram/s_log1p.c_e.c:125:33");
        computeDSub((Addr)&temp_var_for_tac_4, {(Addr)&x, (Addr)&x},
                    "/home/shijia/Public/testprogram/s_log1p.c_e.c:125:43");
        computeDDiv((Addr)&temp_var_for_tac_5,
                    {(Addr)&temp_var_for_tac_3, (Addr)&temp_var_for_tac_4},
                    "/home/shijia/Public/testprogram/s_log1p.c_e.c:125:38");
        AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_5,
                "/home/shijia/Public/testprogram/s_log1p.c_e.c:125:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_1;
      }
      /* log1p(x<-1)=NaN */
    }
    if (ax < IC(0x3e200000)) {    /* |x| < 2**-29 */
      math_force_eval(two54 + x); /* raise inexact */
      if (ax < IC(0x3c900000))    /* |x| < 2**-54 */
      {
        double temp_var_for_ext_2;
        temp_var_for_ext_2 = x;
        computeDAdd((Addr)&temp_var_for_tac_6,
                    {(Addr) &(temp_var_for_const_4 = two54), (Addr)&x},
                    "/home/shijia/Public/testprogram/s_log1p.c_e.c:134:7 "
                    "<Spelling=/home/shijia/Public/testprogram/"
                    "s_log1p.c_e.c:134:29>");
        computeDAdd((Addr)&temp_var_for_tac_7,
                    {(Addr) &(temp_var_for_const_5 = two54), (Addr)&x},
                    "/home/shijia/Public/testprogram/s_log1p.c_e.c:134:7 "
                    "<Spelling=/home/shijia/Public/testprogram/"
                    "s_log1p.c_e.c:134:29>");
        AssignD({(Addr)&temp_var_for_ext_2}, (Addr)&x,
                "/home/shijia/Public/testprogram/s_log1p.c_e.c:138:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_2;
      }

      else {
        double temp_var_for_ext_3;
        double temp_var_for_tac_8, temp_var_for_tac_9, temp_var_for_tac_10;
        double temp_var_for_const_6;
        temp_var_for_tac_8 = x * x;

        temp_var_for_tac_9 = temp_var_for_tac_8 * 0.5;

        temp_var_for_tac_10 = x - temp_var_for_tac_9;

        temp_var_for_ext_3 = temp_var_for_tac_10;
        computeDMul((Addr)&temp_var_for_tac_8, {(Addr)&x, (Addr)&x},
                    "/home/shijia/Public/testprogram/s_log1p.c_e.c:147:36");
        computeDMul(
            (Addr)&temp_var_for_tac_9,
            {(Addr)&temp_var_for_tac_8, (Addr) &(temp_var_for_const_6 = 0.5)},
            "/home/shijia/Public/testprogram/s_log1p.c_e.c:147:40");
        computeDSub((Addr)&temp_var_for_tac_10,
                    {(Addr)&x, (Addr)&temp_var_for_tac_9},
                    "/home/shijia/Public/testprogram/s_log1p.c_e.c:147:32");
        AssignD({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_10,
                "/home/shijia/Public/testprogram/s_log1p.c_e.c:147:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_3;
      }
    }
    if (hx > 0 || hx <= IC(0xbfd2bec3)) {
      k = 0;
      f = x;
      AssignD({(Addr)&f}, (Addr)&x,
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:156:9");
      ;
      hu = 1;
      double temp_var_for_const_7;
      c = 0;
      AssignD({(Addr)&c}, (Addr) &(temp_var_for_const_7 = 0),
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:158:9");
      ;
    } /* -0.2929<x<0.41422 */
  } else {
    if (hx >= IC(0x7ff00000)) {
      double temp_var_for_ext_4;
      double temp_var_for_tac_11;
      temp_var_for_tac_11 = x + x;

      temp_var_for_ext_4 = temp_var_for_tac_11;
      computeDAdd((Addr)&temp_var_for_tac_11, {(Addr)&x, (Addr)&x},
                  "/home/shijia/Public/testprogram/s_log1p.c_e.c:163:30");
      AssignD({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_11,
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:163:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_4;
    }
  }

  if (k != 0) {
    if (hx < IC(0x43400000)) {
      double temp_var_for_tac_12;
      double temp_var_for_const_8;
      temp_var_for_tac_12 = 1.0 + x;

      u = temp_var_for_tac_12;
      computeDAdd((Addr)&temp_var_for_tac_12,
                  {(Addr) &(temp_var_for_const_8 = 1.0), (Addr)&x},
                  "/home/shijia/Public/testprogram/s_log1p.c_e.c:173:15");
      AssignD({(Addr)&u}, (Addr)&temp_var_for_tac_12,
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:173:9");
      ;
      GET_HIGH_WORD(hu, u);
      k = (hu >> 20) - 1023;
      double temp_var_for_const_9;
      c = (k > 0) ? 1.0 - (u - x) : x - (u - 1.0);
      AssignD({(Addr)&c}, (Addr) &(temp_var_for_const_9 =
                                       (k > 0) ? 1.0 - (u - x) : x - (u - 1.0)),
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:176:9");
      ; /* correction term */
      c /= u;
    } else {
      double temp_var_for_ext_5;
      temp_var_for_ext_5 = x;
      AssignD({(Addr)&temp_var_for_ext_5}, (Addr)&x,
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:180:26");
      ; // u
      /*(x)(u)(1.0)(x)(u)(1.0)(u)(x)(1.0)(u)(u)(c)(x)*/
      u = temp_var_for_ext_5;
      AssignD({(Addr)&u}, (Addr)&temp_var_for_ext_5,
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:182:9");
      ;
      GET_HIGH_WORD(hu, u);
      k = (hu >> 20) - 1023;
      double temp_var_for_const_10;
      c = 0;
      AssignD({(Addr)&c}, (Addr) &(temp_var_for_const_10 = 0),
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:185:9");
      ;
    }
    hu &= IC(0x000fffff);
    if (hu < IC(0x6a09e)) {
      SET_HIGH_WORD(u, hu | IC(0x3ff00000)); /* normalize u */
    } else {
      k += 1;
      SET_HIGH_WORD(u, hu | IC(0x3fe00000)); /* normalize u/2 */
      hu = (IC(0x00100000) - hu) >> 2;
    }
    double temp_var_for_tac_13;
    double temp_var_for_const_11;
    temp_var_for_tac_13 = u - 1.0;

    f = temp_var_for_tac_13;
    computeDSub((Addr)&temp_var_for_tac_13,
                {(Addr)&u, (Addr) &(temp_var_for_const_11 = 1.0)},
                "/home/shijia/Public/testprogram/s_log1p.c_e.c:195:11");
    AssignD({(Addr)&f}, (Addr)&temp_var_for_tac_13,
            "/home/shijia/Public/testprogram/s_log1p.c_e.c:195:7");
    ;
  }
  double temp_var_for_tac_14, temp_var_for_tac_15;
  double temp_var_for_const_12;
  temp_var_for_tac_14 = 0.5 * f;

  temp_var_for_tac_15 = temp_var_for_tac_14 * f;

  hfsq = temp_var_for_tac_15;
  computeDMul((Addr)&temp_var_for_tac_14,
              {(Addr) &(temp_var_for_const_12 = 0.5), (Addr)&f},
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:197:14");
  computeDMul((Addr)&temp_var_for_tac_15,
              {(Addr)&temp_var_for_tac_14, (Addr)&f},
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:197:18");
  AssignD({(Addr)&hfsq}, (Addr)&temp_var_for_tac_15,
          "/home/shijia/Public/testprogram/s_log1p.c_e.c:197:8");
  ;
  if (hu == 0) { /* |f| < 2**-20 */
    if (int temp_var_for_tac_16; int temp_var_for_const_13;
        temp_var_for_tac_16 = f == zero;

        ) {
      if (k == 0) {
        double temp_var_for_ext_6;
        double temp_var_for_const_14;
        temp_var_for_ext_6 = zero;
        compute((Addr)&temp_var_for_tac_16,
                {(Addr)&f, (Addr) &(temp_var_for_const_13 = zero)},
                "/home/shijia/Public/testprogram/s_log1p.c_e.c:199:11");
        AssignD({(Addr)&temp_var_for_ext_6},
                (Addr) &(temp_var_for_const_14 = zero),
                "/home/shijia/Public/testprogram/s_log1p.c_e.c:202:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_6;
      }

      else {
        double temp_var_for_tac_17;
        double temp_var_for_const_15, temp_var_for_const_16;
        temp_var_for_tac_17 = k * ln2_lo;

        c += temp_var_for_tac_17;
        ;
        double temp_var_for_ext_7;
        double temp_var_for_tac_19, temp_var_for_tac_20;
        double temp_var_for_const_17, temp_var_for_const_18;
        temp_var_for_tac_19 = k * ln2_hi;

        temp_var_for_tac_20 = temp_var_for_tac_19 + c;

        temp_var_for_ext_7 = temp_var_for_tac_20;
        computeDMul((Addr)&temp_var_for_tac_17,
                    {(Addr) &(temp_var_for_const_16 = k),
                     (Addr) &(temp_var_for_const_15 = ln2_lo)},
                    "/home/shijia/Public/testprogram/s_log1p.c_e.c:210:16");
        computeDMul((Addr)&temp_var_for_tac_19,
                    {(Addr) &(temp_var_for_const_18 = k),
                     (Addr) &(temp_var_for_const_17 = ln2_hi)},
                    "/home/shijia/Public/testprogram/s_log1p.c_e.c:212:32");
        computeDAdd((Addr)&temp_var_for_tac_20,
                    {(Addr)&temp_var_for_tac_19, (Addr)&c},
                    "/home/shijia/Public/testprogram/s_log1p.c_e.c:212:41");
        AssignD({(Addr)&temp_var_for_ext_7}, (Addr)&temp_var_for_tac_20,
                "/home/shijia/Public/testprogram/s_log1p.c_e.c:212:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_7;
      }
    }
    double temp_var_for_tac_21, temp_var_for_tac_22, temp_var_for_tac_23;
    double temp_var_for_const_19, temp_var_for_const_20;
    temp_var_for_tac_21 = 0.66666666666666666 * f;

    temp_var_for_tac_22 = 1.0 - temp_var_for_tac_21;

    temp_var_for_tac_23 = hfsq * temp_var_for_tac_22;

    R = temp_var_for_tac_23;
    computeDMul(
        (Addr)&temp_var_for_tac_21,
        {(Addr) &(temp_var_for_const_19 = 0.66666666666666666), (Addr)&f},
        "/home/shijia/Public/testprogram/s_log1p.c_e.c:219:43");
    computeDSub(
        (Addr)&temp_var_for_tac_22,
        {(Addr) &(temp_var_for_const_20 = 1.0), (Addr)&temp_var_for_tac_21},
        "/home/shijia/Public/testprogram/s_log1p.c_e.c:219:21");
    computeDMul((Addr)&temp_var_for_tac_23,
                {(Addr)&hfsq, (Addr)&temp_var_for_tac_22},
                "/home/shijia/Public/testprogram/s_log1p.c_e.c:219:14");
    AssignD({(Addr)&R}, (Addr)&temp_var_for_tac_23,
            "/home/shijia/Public/testprogram/s_log1p.c_e.c:219:7");
    ;
    if (k == 0) {
      double temp_var_for_ext_8;
      double temp_var_for_tac_24;
      temp_var_for_tac_24 = f - R;

      temp_var_for_ext_8 = temp_var_for_tac_24;
      computeDSub((Addr)&temp_var_for_tac_24, {(Addr)&f, (Addr)&R},
                  "/home/shijia/Public/testprogram/s_log1p.c_e.c:222:30");
      AssignD({(Addr)&temp_var_for_ext_8}, (Addr)&temp_var_for_tac_24,
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:222:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_8;
    }

    else {
      double temp_var_for_ext_9;
      double temp_var_for_tac_25, temp_var_for_tac_26, temp_var_for_tac_27,
          temp_var_for_tac_28, temp_var_for_tac_29, temp_var_for_tac_30;
      double temp_var_for_const_21, temp_var_for_const_22,
          temp_var_for_const_23, temp_var_for_const_24;
      temp_var_for_tac_25 = k * ln2_hi;

      temp_var_for_tac_26 = k * ln2_lo;

      temp_var_for_tac_27 = temp_var_for_tac_26 + c;

      temp_var_for_tac_28 = R - temp_var_for_tac_27;

      temp_var_for_tac_29 = temp_var_for_tac_28 - f;

      temp_var_for_tac_30 = temp_var_for_tac_25 - temp_var_for_tac_29;

      temp_var_for_ext_9 = temp_var_for_tac_30;
      computeDMul((Addr)&temp_var_for_tac_25,
                  {(Addr) &(temp_var_for_const_22 = k),
                   (Addr) &(temp_var_for_const_21 = ln2_hi)},
                  "/home/shijia/Public/testprogram/s_log1p.c_e.c:231:30");
      computeDMul((Addr)&temp_var_for_tac_26,
                  {(Addr) &(temp_var_for_const_24 = k),
                   (Addr) &(temp_var_for_const_23 = ln2_lo)},
                  "/home/shijia/Public/testprogram/s_log1p.c_e.c:231:50");
      computeDAdd((Addr)&temp_var_for_tac_27,
                  {(Addr)&temp_var_for_tac_26, (Addr)&c},
                  "/home/shijia/Public/testprogram/s_log1p.c_e.c:231:59");
      computeDSub((Addr)&temp_var_for_tac_28,
                  {(Addr)&R, (Addr)&temp_var_for_tac_27},
                  "/home/shijia/Public/testprogram/s_log1p.c_e.c:231:45");
      computeDSub((Addr)&temp_var_for_tac_29,
                  {(Addr)&temp_var_for_tac_28, (Addr)&f},
                  "/home/shijia/Public/testprogram/s_log1p.c_e.c:231:65");
      computeDSub((Addr)&temp_var_for_tac_30,
                  {(Addr)&temp_var_for_tac_25, (Addr)&temp_var_for_tac_29},
                  "/home/shijia/Public/testprogram/s_log1p.c_e.c:231:39");
      AssignD({(Addr)&temp_var_for_ext_9}, (Addr)&temp_var_for_tac_30,
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:231:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_9;
    }
  }
  double temp_var_for_tac_31, temp_var_for_tac_32;
  double temp_var_for_const_25;
  temp_var_for_tac_31 = 2.0 + f;

  temp_var_for_tac_32 = f / temp_var_for_tac_31;

  s = temp_var_for_tac_32;
  computeDAdd((Addr)&temp_var_for_tac_31,
              {(Addr) &(temp_var_for_const_25 = 2.0), (Addr)&f},
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:238:16");
  computeDDiv((Addr)&temp_var_for_tac_32,
              {(Addr)&f, (Addr)&temp_var_for_tac_31},
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:238:9");
  AssignD({(Addr)&s}, (Addr)&temp_var_for_tac_32,
          "/home/shijia/Public/testprogram/s_log1p.c_e.c:238:5");
  ;
  double temp_var_for_tac_33;
  temp_var_for_tac_33 = s * s;

  z = temp_var_for_tac_33;
  computeDMul((Addr)&temp_var_for_tac_33, {(Addr)&s, (Addr)&s},
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:239:9");
  AssignD({(Addr)&z}, (Addr)&temp_var_for_tac_33,
          "/home/shijia/Public/testprogram/s_log1p.c_e.c:239:5");
  ;
#ifdef DO_NOT_USE_THIS
  R = z * (Lp1 +
           z * (Lp2 + z * (Lp3 + z * (Lp4 + z * (Lp5 + z * (Lp6 + z * Lp7))))));
#else
  double temp_var_for_tac_34;
  double temp_var_for_const_26;
  temp_var_for_tac_34 = z * Lp[1];

  R1 = temp_var_for_tac_34;
  computeDMul((Addr)&temp_var_for_tac_34,
              {(Addr)&z, (Addr) &(temp_var_for_const_26 = Lp[1])},
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:244:10");
  AssignD({(Addr)&R1}, (Addr)&temp_var_for_tac_34,
          "/home/shijia/Public/testprogram/s_log1p.c_e.c:244:6");
  ;
  double temp_var_for_tac_35;
  temp_var_for_tac_35 = z * z;

  z2 = temp_var_for_tac_35;
  computeDMul((Addr)&temp_var_for_tac_35, {(Addr)&z, (Addr)&z},
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:245:10");
  AssignD({(Addr)&z2}, (Addr)&temp_var_for_tac_35,
          "/home/shijia/Public/testprogram/s_log1p.c_e.c:245:6");
  ;
  double temp_var_for_tac_36, temp_var_for_tac_37;
  double temp_var_for_const_27, temp_var_for_const_28;
  temp_var_for_tac_36 = z * Lp[3];

  temp_var_for_tac_37 = Lp[2] + temp_var_for_tac_36;

  R2 = temp_var_for_tac_37;
  computeDMul((Addr)&temp_var_for_tac_36,
              {(Addr)&z, (Addr) &(temp_var_for_const_27 = Lp[3])},
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:246:18");
  computeDAdd(
      (Addr)&temp_var_for_tac_37,
      {(Addr) &(temp_var_for_const_28 = Lp[2]), (Addr)&temp_var_for_tac_36},
      "/home/shijia/Public/testprogram/s_log1p.c_e.c:246:14");
  AssignD({(Addr)&R2}, (Addr)&temp_var_for_tac_37,
          "/home/shijia/Public/testprogram/s_log1p.c_e.c:246:6");
  ;
  double temp_var_for_tac_38;
  temp_var_for_tac_38 = z2 * z2;

  z4 = temp_var_for_tac_38;
  computeDMul((Addr)&temp_var_for_tac_38, {(Addr)&z2, (Addr)&z2},
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:247:11");
  AssignD({(Addr)&z4}, (Addr)&temp_var_for_tac_38,
          "/home/shijia/Public/testprogram/s_log1p.c_e.c:247:6");
  ;
  double temp_var_for_tac_39, temp_var_for_tac_40;
  double temp_var_for_const_29, temp_var_for_const_30;
  temp_var_for_tac_39 = z * Lp[5];

  temp_var_for_tac_40 = Lp[4] + temp_var_for_tac_39;

  R3 = temp_var_for_tac_40;
  computeDMul((Addr)&temp_var_for_tac_39,
              {(Addr)&z, (Addr) &(temp_var_for_const_29 = Lp[5])},
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:248:18");
  computeDAdd(
      (Addr)&temp_var_for_tac_40,
      {(Addr) &(temp_var_for_const_30 = Lp[4]), (Addr)&temp_var_for_tac_39},
      "/home/shijia/Public/testprogram/s_log1p.c_e.c:248:14");
  AssignD({(Addr)&R3}, (Addr)&temp_var_for_tac_40,
          "/home/shijia/Public/testprogram/s_log1p.c_e.c:248:6");
  ;
  double temp_var_for_tac_41;
  temp_var_for_tac_41 = z4 * z2;

  z6 = temp_var_for_tac_41;
  computeDMul((Addr)&temp_var_for_tac_41, {(Addr)&z4, (Addr)&z2},
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:249:11");
  AssignD({(Addr)&z6}, (Addr)&temp_var_for_tac_41,
          "/home/shijia/Public/testprogram/s_log1p.c_e.c:249:6");
  ;
  double temp_var_for_tac_42, temp_var_for_tac_43;
  double temp_var_for_const_31, temp_var_for_const_32;
  temp_var_for_tac_42 = z * Lp[7];

  temp_var_for_tac_43 = Lp[6] + temp_var_for_tac_42;

  R4 = temp_var_for_tac_43;
  computeDMul((Addr)&temp_var_for_tac_42,
              {(Addr)&z, (Addr) &(temp_var_for_const_31 = Lp[7])},
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:250:18");
  computeDAdd(
      (Addr)&temp_var_for_tac_43,
      {(Addr) &(temp_var_for_const_32 = Lp[6]), (Addr)&temp_var_for_tac_42},
      "/home/shijia/Public/testprogram/s_log1p.c_e.c:250:14");
  AssignD({(Addr)&R4}, (Addr)&temp_var_for_tac_43,
          "/home/shijia/Public/testprogram/s_log1p.c_e.c:250:6");
  ;
  double temp_var_for_tac_44, temp_var_for_tac_45, temp_var_for_tac_46,
      temp_var_for_tac_47, temp_var_for_tac_48, temp_var_for_tac_49;
  temp_var_for_tac_44 = z2 * R2;

  temp_var_for_tac_45 = R1 + temp_var_for_tac_44;

  temp_var_for_tac_46 = z4 * R3;

  temp_var_for_tac_47 = temp_var_for_tac_45 + temp_var_for_tac_46;

  temp_var_for_tac_48 = z6 * R4;

  temp_var_for_tac_49 = temp_var_for_tac_47 + temp_var_for_tac_48;

  R = temp_var_for_tac_49;
  computeDMul((Addr)&temp_var_for_tac_44, {(Addr)&z2, (Addr)&R2},
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:251:15");
  computeDAdd((Addr)&temp_var_for_tac_45,
              {(Addr)&R1, (Addr)&temp_var_for_tac_44},
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:251:10");
  computeDMul((Addr)&temp_var_for_tac_46, {(Addr)&z4, (Addr)&R3},
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:251:25");
  computeDAdd((Addr)&temp_var_for_tac_47,
              {(Addr)&temp_var_for_tac_45, (Addr)&temp_var_for_tac_46},
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:251:20");
  computeDMul((Addr)&temp_var_for_tac_48, {(Addr)&z6, (Addr)&R4},
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:251:35");
  computeDAdd((Addr)&temp_var_for_tac_49,
              {(Addr)&temp_var_for_tac_47, (Addr)&temp_var_for_tac_48},
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:251:30");
  AssignD({(Addr)&R}, (Addr)&temp_var_for_tac_49,
          "/home/shijia/Public/testprogram/s_log1p.c_e.c:251:5");
  ;
#endif
  if (k == 0) {
    double temp_var_for_ext_10;
    double temp_var_for_tac_50, temp_var_for_tac_51, temp_var_for_tac_52,
        temp_var_for_tac_53;
    temp_var_for_tac_50 = hfsq + R;

    temp_var_for_tac_51 = s * temp_var_for_tac_50;

    temp_var_for_tac_52 = hfsq - temp_var_for_tac_51;

    temp_var_for_tac_53 = f - temp_var_for_tac_52;

    temp_var_for_ext_10 = temp_var_for_tac_53;
    computeDAdd((Addr)&temp_var_for_tac_50, {(Addr)&hfsq, (Addr)&R},
                "/home/shijia/Public/testprogram/s_log1p.c_e.c:255:49");
    computeDMul((Addr)&temp_var_for_tac_51,
                {(Addr)&s, (Addr)&temp_var_for_tac_50},
                "/home/shijia/Public/testprogram/s_log1p.c_e.c:255:41");
    computeDSub((Addr)&temp_var_for_tac_52,
                {(Addr)&hfsq, (Addr)&temp_var_for_tac_51},
                "/home/shijia/Public/testprogram/s_log1p.c_e.c:255:37");
    computeDSub((Addr)&temp_var_for_tac_53,
                {(Addr)&f, (Addr)&temp_var_for_tac_52},
                "/home/shijia/Public/testprogram/s_log1p.c_e.c:255:29");
    AssignD({(Addr)&temp_var_for_ext_10}, (Addr)&temp_var_for_tac_53,
            "/home/shijia/Public/testprogram/s_log1p.c_e.c:255:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_10", (Addr)&temp_var_for_ext_10));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_10;
  }

  else {
    double temp_var_for_ext_11;
    double temp_var_for_tac_54, temp_var_for_tac_55, temp_var_for_tac_56,
        temp_var_for_tac_57, temp_var_for_tac_58, temp_var_for_tac_59,
        temp_var_for_tac_60, temp_var_for_tac_61, temp_var_for_tac_62;
    double temp_var_for_const_33, temp_var_for_const_34, temp_var_for_const_35,
        temp_var_for_const_36;
    temp_var_for_tac_54 = k * ln2_hi;

    temp_var_for_tac_55 = hfsq + R;

    temp_var_for_tac_56 = s * temp_var_for_tac_55;

    temp_var_for_tac_57 = k * ln2_lo;

    temp_var_for_tac_58 = temp_var_for_tac_57 + c;

    temp_var_for_tac_59 = temp_var_for_tac_56 + temp_var_for_tac_58;

    temp_var_for_tac_60 = hfsq - temp_var_for_tac_59;

    temp_var_for_tac_61 = temp_var_for_tac_60 - f;

    temp_var_for_tac_62 = temp_var_for_tac_54 - temp_var_for_tac_61;

    temp_var_for_ext_11 = temp_var_for_tac_62;
    computeDMul((Addr)&temp_var_for_tac_54,
                {(Addr) &(temp_var_for_const_34 = k),
                 (Addr) &(temp_var_for_const_33 = ln2_hi)},
                "/home/shijia/Public/testprogram/s_log1p.c_e.c:265:11");
    computeDAdd((Addr)&temp_var_for_tac_55, {(Addr)&hfsq, (Addr)&R},
                "/home/shijia/Public/testprogram/s_log1p.c_e.c:265:42");
    computeDMul((Addr)&temp_var_for_tac_56,
                {(Addr)&s, (Addr)&temp_var_for_tac_55},
                "/home/shijia/Public/testprogram/s_log1p.c_e.c:265:34");
    computeDMul((Addr)&temp_var_for_tac_57,
                {(Addr) &(temp_var_for_const_36 = k),
                 (Addr) &(temp_var_for_const_35 = ln2_lo)},
                "/home/shijia/Public/testprogram/s_log1p.c_e.c:265:52");
    computeDAdd((Addr)&temp_var_for_tac_58,
                {(Addr)&temp_var_for_tac_57, (Addr)&c},
                "/home/shijia/Public/testprogram/s_log1p.c_e.c:265:61");
    computeDAdd((Addr)&temp_var_for_tac_59,
                {(Addr)&temp_var_for_tac_56, (Addr)&temp_var_for_tac_58},
                "/home/shijia/Public/testprogram/s_log1p.c_e.c:265:47");
    computeDSub((Addr)&temp_var_for_tac_60,
                {(Addr)&hfsq, (Addr)&temp_var_for_tac_59},
                "/home/shijia/Public/testprogram/s_log1p.c_e.c:265:29");
    computeDSub((Addr)&temp_var_for_tac_61,
                {(Addr)&temp_var_for_tac_60, (Addr)&f},
                "/home/shijia/Public/testprogram/s_log1p.c_e.c:265:68");
    computeDSub((Addr)&temp_var_for_tac_62,
                {(Addr)&temp_var_for_tac_54, (Addr)&temp_var_for_tac_61},
                "/home/shijia/Public/testprogram/s_log1p.c_e.c:265:20");
    AssignD({(Addr)&temp_var_for_ext_11}, (Addr)&temp_var_for_tac_62,
            "/home/shijia/Public/testprogram/s_log1p.c_e.c:264:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_11", (Addr)&temp_var_for_ext_11));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_11;
  }
}

#endif

/* wrapper log1p(x) */
double __log1p(double x) {
  if (islessequal(x, -1.0) && _LIB_VERSION != _IEEE_) {
    if (int temp_var_for_tac_63, temp_var_for_tac_64;
        int temp_var_for_const_37, temp_var_for_const_38;
        temp_var_for_tac_63 = 0.0 - 1.0;

        temp_var_for_tac_64 = x == temp_var_for_tac_63;

        ) {
      feraiseexcept(FE_DIVBYZERO);
      double temp_var_for_ext_12;
      double temp_var_for_const_39;
      double temp_var_for_callexp_1;

      temp_var_for_callexp_0 = __builtin_huge_val();
      temp_var_for_callexp_1 = __kernel_standard(
          x, x, (-(temp_var_for_callexp_0)), KMATHERR_LOG_ZERO);
      temp_var_for_ext_12 = temp_var_for_callexp_1;
      computeDSub((Addr)&temp_var_for_tac_63,
                  {(Addr) &(temp_var_for_const_38 = 0.0),
                   (Addr) &(temp_var_for_const_37 = 1.0)},
                  "/home/shijia/Public/testprogram/s_log1p.c_e.c:278:19");
      compute((Addr)&temp_var_for_tac_64,
              {(Addr)&x, (Addr)&temp_var_for_tac_63},
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:278:11");
      AssignD({(Addr)&temp_var_for_ext_12},
              (Addr) &(temp_var_for_const_39 = temp_var_for_callexp_1),
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:281:27");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_12", (Addr)&temp_var_for_ext_12));
      callExp++; /*identify the function is  add move tmpShadow(0.0 - /
     return) temp_var_for_ext_12;	/* log(0) */
    } else {
      feraiseexcept(FE_INVALID);
      double temp_var_for_ext_13;
      double temp_var_for_const_40;
      double temp_var_for_callexp_2;

      /*embed fun has found*/
      double temp_var_for_callexp_3;

      temp_var_for_callexp_2 = __builtin_nan("");
      temp_var_for_callexp_3 =
          __kernel_standard(x, x, temp_var_for_callexp_2, KMATHERR_LOG_MINUS);
      temp_var_for_ext_13 = temp_var_for_callexp_3;
      AssignD({(Addr)&temp_var_for_ext_13},
              (Addr) &(temp_var_for_const_40 = temp_var_for_callexp_3),
              "/home/shijia/Public/testprogram/s_log1p.c_e.c:290:27");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_13", (Addr)&temp_var_for_ext_13));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_13; /* log(x<0) */
    }
  }

  double temp_var_for_ext_14;
  double temp_var_for_const_41;
  double temp_var_for_callexp_4;

  temp_var_for_callexp_4 = __ieee754_log1p(x);
  temp_var_for_ext_14 = temp_var_for_callexp_4;
  AssignD({(Addr)&temp_var_for_ext_14},
          (Addr) &(temp_var_for_const_41 = temp_var_for_callexp_4),
          "/home/shijia/Public/testprogram/s_log1p.c_e.c:300:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_14", (Addr)&temp_var_for_ext_14));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_14;
}

__typeof(__log1p) log1p __attribute__((weak, alias("__log1p")));
#ifdef __NO_LONG_DOUBLE_MATH
long double __log1pl(long double x) __attribute__((alias("__log1p")));
__typeof(__log1pl) log1pl __attribute__((weak, alias("__log1p")));
#endif
