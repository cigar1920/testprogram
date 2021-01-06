#include "../ScDebug/scdebug.h"
/* @(#)s_expm1.c 1.5 04/04/22 */
/*
 * ====================================================
 * Copyright (C) 2004 by Sun Microsystems, Inc. All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 */
/* Modified by Naohiko Shimizu/Tokai University, Japan 1997/08/25,
   for performance improvement on pipelined processors.
*/

/* expm1(x)
 * Returns exp(x)-1, the exponential of x minus 1.
 *
 * Method
 *       1. Argument reduction:
 *      Given x, find r and integer k such that
 *
 *                               x = k*ln2 + r,  |r| <= 0.5*ln2 ~ 0.34658
 *
 *        Here a correction term c will be computed to compensate
 *      the error in r when rounded to a floating-point number.
 *
 *       2. Approximating expm1(r) by a special rational function on
 *      the interval [0,0.34658]:
 *      Since
 *              r*(exp(r)+1)/(exp(r)-1) = 2+ r^2/6 - r^4/360 + ...
 *      we define R1(r*r) by
 *              r*(exp(r)+1)/(exp(r)-1) = 2+ r^2/6 * R1(r*r)
 *      That is,
 *              R1(r**2) = 6/r *((exp(r)+1)/(exp(r)-1) - 2/r)
 *                       = 6/r * ( 1 + 2.0*(1/(exp(r)-1) - 1/r))
 *                       = 1 - r^2/60 + r^4/2520 - r^6/100800 + ...
 *              We use a special Remes algorithm on [0,0.347] to generate
 *      a polynomial of degree 5 in r*r to approximate R1. The
 *      maximum error of this polynomial approximation is bounded
 *      by 2**-61. In other words,
 *              R1(z) ~ 1.0 + Q1*z + Q2*z**2 + Q3*z**3 + Q4*z**4 + Q5*z**5
 *      where   Q1      =  -1.6666666666666567384E-2,
 *              Q2      =       3.9682539681370365873E-4,
 *              Q3      =  -9.9206344733435987357E-6,
 *              Q4      =       2.5051361420808517002E-7,
 *              Q5      =  -6.2843505682382617102E-9;
 *      (where z=r*r, and the values of Q1 to Q5 are listed below)
 *      with error bounded by
 *              |                                  5               |     -61
 *              | 1.0+Q1*z+...+Q5*z   -  R1(z) | <= 2
 *              |                                                          |
 *
 *      expm1(r) = exp(r)-1 is then computed by the following
 *      specific way which minimize the accumulation rounding error:
 *                                 2     3
 *                                r     r        [ 3 - (R1 + R1*r/2)  ]
 *                expm1(r) = r + --- + --- * [--------------------]
 *                                2     2        [ 6 - r*(3 - R1*r/2) ]
 *
 *      To compensate the error in the argument reduction, we use
 *              expm1(r+c) = expm1(r) + c + expm1(r)*c
 *                         ~ expm1(r) + c + r*c
 *      Thus c+r*c will be added in as the correction terms for
 *      expm1(r+c). Now rearrange the term to avoid optimization
 *      screw up:
 *                      (          2                                    2 )
 *                      ({      ( r    [ R1 -  (3 - R1*r/2) ]  )  }    r  )
 *       expm1(r+c)~r - ({r*(--- * [--------------------]-c)-c} - --- )
 *                      ({      ( 2    [ 6 - r*(3 - R1*r/2) ]  )  }    2  )
 *                      (                                                 )
 *
 *                 = r - E
 *       3. Scale back to obtain expm1(x):
 *      From step 1, we have
 *         expm1(x) = either 2^k*[expm1(r)+1] - 1
 *                      = or     2^k*[expm1(r) + (1-2^-k)]
 *       4. Implementation notes:
 *      (A). To save one multiplication, we scale the coefficient Qi
 *               to Qi*2^i, and replace z by (x^2)/2.
 *      (B). To achieve maximum accuracy, we compute expm1(x) by
 *        (i)   if x < -56*ln2, return -1.0, (raise inexact if x!=inf)
 *        (ii)  if k=0, return r-E
 *        (iii) if k=-1, return 0.5*(r-E)-0.5
 *                (iv)  if k=1 if r < -0.25, return 2*((r+0.5)- E)
 *                         else          return  1.0+2.0*(r-E);
 *        (v)   if (k<-2||k>56) return 2^k(1-(E-r)) - 1 (or exp(x)-1)
 *        (vi)  if k <= 20, return 2^k((1-2^-k)-(E-r)), else
 *        (vii) return 2^k(1-((E+2^-k)-r))
 *
 * Special cases:
 *      expm1(INF) is INF, expm1(NaN) is NaN;
 *      expm1(-INF) is -1, and
 *      for finite argument, only expm1(0)=0 is exact.
 *
 * Accuracy:
 *      according to an error analysis, the error is always less than
 *      1 ulp (unit in the last place).
 *
 * Misc. info.
 *      For IEEE double
 *              if x >  7.09782712893383973096e+02 then expm1(x) overflow
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

#ifndef __have_fpu_expm1

double __ieee754_expm1(double x) {
  double y, hi, lo, c, t, e, hxs, hfx, r1, h2, h4, R1, R2, R3;
  int32_t k, xsb;
  uint32_t hx;

  static const double hugeval = 1.0e+300;
  static const double o_threshold =
      7.09782712893383973096e+02; /* 0x40862E42, 0xFEFA39EF */
  static const double ln2_hi =
      6.93147180369123816490e-01; /* 0x3fe62e42, 0xfee00000 */
  static const double ln2_lo =
      1.90821492927058770002e-10; /* 0x3dea39ef, 0x35793c76 */
  static const double invln2 =
      1.44269504088896338700e+00; /* 0x3ff71547, 0x652b82fe */
  /* scaled coefficients related to expm1 */
  static const double Q[] = {
      1.0,
#define one Q[0]
      (double temp_var_for_tac_0;
  double temp_var_for_const_0, temp_var_for_const_1;
  temp_var_for_tac_0 = 0.0 - 3.33333333333331316428e-02;

), /* BFA11111 111110F4 */
      1.58730158725481460165e-03,         /* 3F5A01A0 19FE5585 */
      (double temp_var_for_tac_1;double temp_var_for_const_2,temp_var_for_const_3;temp_var_for_tac_1 = 0.0 - 7.93650757867487942473e-05;

), /* BF14CE19 9EAADBB7 */
      4.00821782732936239552e-06,         /* 3ED0CFCA 86E65239 */
      (double temp_var_for_tac_2;double temp_var_for_const_4,temp_var_for_const_5;temp_var_for_tac_2 = 0.0 - 2.01099218183624371326e-07;

)  /* BE8AFDB7 6E09C32D */
};

GET_HIGH_WORD(hx, x);
xsb = hx & IC(0x80000000); /* sign bit of x */
if (xsb == 0) {
  y = x;
  computeDSub((Addr)&temp_var_for_tac_0,
              {(Addr) &(temp_var_for_const_1 = 0.0),
               (Addr) &(temp_var_for_const_0 = 3.33333333333331316428e-02)},
              "/home/shijia/Public/testprogram/s_expm1.c_e.c:134:12");
  computeDSub((Addr)&temp_var_for_tac_1,
              {(Addr) &(temp_var_for_const_3 = 0.0),
               (Addr) &(temp_var_for_const_2 = 7.93650757867487942473e-05)},
              "/home/shijia/Public/testprogram/s_expm1.c_e.c:136:12");
  computeDSub((Addr)&temp_var_for_tac_2,
              {(Addr) &(temp_var_for_const_5 = 0.0),
               (Addr) &(temp_var_for_const_4 = 2.01099218183624371326e-07)},
              "/home/shijia/Public/testprogram/s_expm1.c_e.c:138:12");
  AssignD({(Addr)&y}, (Addr)&x,
          "/home/shijia/Public/testprogram/s_expm1.c_e.c:144:7");
  ;
}

else {
  double temp_var_for_tac_3;
  double temp_var_for_const_6;
  temp_var_for_tac_3 = 0.0 - x;

  y = temp_var_for_tac_3;
  computeDSub((Addr)&temp_var_for_tac_3,
              {(Addr) &(temp_var_for_const_6 = 0.0), (Addr)&x},
              "/home/shijia/Public/testprogram/s_expm1.c_e.c:148:14");
  AssignD({(Addr)&y}, (Addr)&temp_var_for_tac_3,
          "/home/shijia/Public/testprogram/s_expm1.c_e.c:148:7");
  ;
}
/* y = |x| */
hx &= UC(0x7fffffff); /* high word of |x| */

/* filter out hugeval and non-finite argument */
if (hx >= UC(0x4043687A)) {   /* if |x|>=56*ln2 */
  if (hx >= UC(0x40862E42)) { /* if |x|>=709.78... */
    if (hx >= UC(0x7ff00000)) {
      uint32_t low;

      GET_LOW_WORD(low, x);
      if (((hx & UC(0xfffff)) | low) != 0) {
        double temp_var_for_ext_0;
        double temp_var_for_tac_4;
        temp_var_for_tac_4 = x + x;

        temp_var_for_ext_0 = temp_var_for_tac_4;
        computeDAdd((Addr)&temp_var_for_tac_4, {(Addr)&x, (Addr)&x},
                    "/home/shijia/Public/testprogram/s_expm1.c_e.c:162:34");
        AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_4,
                "/home/shijia/Public/testprogram/s_expm1.c_e.c:162:30");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_0;
      }
      /* NaN */
      double temp_var_for_ext_1;
      double temp_var_for_const_7;
      temp_var_for_ext_1 = (xsb == 0) ? x : -one;
      AssignD({(Addr)&temp_var_for_ext_1},
              (Addr) &(temp_var_for_const_7 = (xsb == 0) ? x : -one),
              "/home/shijia/Public/testprogram/s_expm1.c_e.c:170:28");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_e(0.0 - t_1); /* exp(+-inf)={inf,-1} */
    }
    if (x > o_threshold) {
      feraiseexcept(FE_OVERFLOW);
      double temp_var_for_ext_2;
      double temp_var_for_const_8;
      double temp_var_for_callexp_0;

      temp_var_for_callexp_0 = __builtin_huge_val();
      temp_var_for_ext_2 = temp_var_for_callexp_0;
      AssignD({(Addr)&temp_var_for_ext_2},
              (Addr) &(temp_var_for_const_8 = temp_var_for_callexp_0),
              "/home/shijia/Public/testprogram/s_expm1.c_e.c:179:28");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_2; /* overflow */
    }
  }
  if (xsb != 0) {              /* x < -56*ln2, return -1.0 with inexact */
    feraiseexcept(FE_INEXACT); /* raise inexact */
    double temp_var_for_ext_3;
    double temp_var_for_const_9;
    temp_var_for_ext_3 = (-(one));
    AssignD({(Addr)&temp_var_for_ext_3},
            (Addr) &(temp_var_for_const_9 = (-(one))),
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:189:26");
    ;
    callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
    callExp++;          /*identify the function is  add move tmpShadow*/
    return (0.0 - t_3); /* return -1 */
  }
}

/* argument reduction */
if (hx > UC(0x3fd62e42)) {   /* if  |x| > 0.5 ln2 */
  if (hx < UC(0x3FF0A2B2)) { /* and |x| < 1.5 ln2 */
    if (xsb == 0) {
      double temp_var_for_tac_5;
      double temp_var_for_const_10;
      temp_var_for_tac_5 = x - ln2_hi;

      hi = temp_var_for_tac_5;
      computeDSub((Addr)&temp_var_for_tac_5,
                  {(Addr)&x, (Addr) &(temp_var_for_const_10 = ln2_hi)},
                  "/home/shijia/Public/testprogram/s_expm1.c_e.c:201:16");
      AssignD({(Addr)&hi}, (Addr)&temp_var_for_tac_5,
              "/home/shijia/Public/testprogram/s_expm1.c_e.c:201:12");
      ;
      double temp_var_for_const_11;
      lo = ln2_lo;
      AssignD({(Addr)&lo}, (Addr) &(temp_var_for_const_11 = ln2_lo),
              "/home/shijia/Public/testprogram/s_expm1.c_e.c:202:12");
      ;
      k = 1;
    } else {
      double temp_var_for_tac_6;
      double temp_var_for_const_12;
      temp_var_for_tac_6 = x + ln2_hi;

      hi = temp_var_for_tac_6;
      computeDAdd((Addr)&temp_var_for_tac_6,
                  {(Addr)&x, (Addr) &(temp_var_for_const_12 = ln2_hi)},
                  "/home/shijia/Public/testprogram/s_expm1.c_e.c:205:16");
      AssignD({(Addr)&hi}, (Addr)&temp_var_for_tac_6,
              "/home/shijia/Public/testprogram/s_expm1.c_e.c:205:12");
      ;
      double temp_var_for_tac_7;
      double temp_var_for_const_13, temp_var_for_const_14;
      temp_var_for_tac_7 = 0.0 - ln2_lo;

      lo = temp_var_for_tac_7;
      computeDSub((Addr)&temp_var_for_tac_7,
                  {(Addr) &(temp_var_for_const_14 = 0.0),
                   (Addr) &(temp_var_for_const_13 = ln2_lo)},
                  "/home/shijia/Public/testprogram/s_expm1.c_e.c:206:19");
      AssignD({(Addr)&lo}, (Addr)&temp_var_for_tac_7,
              "/home/shijia/Public/testprogram/s_expm1.c_e.c:206:12");
      ;
      k = -1;
    }
  } else {
    k = double temp_var_for_tac_8, temp_var_for_tac_9;
    double temp_var_for_const_15, temp_var_for_const_16;
    temp_var_for_tac_8 = invln2 * x;

    temp_var_for_tac_9 = temp_var_for_tac_8 + (xsb == 0) ? 0.5 : (0.0 - 0.5);

    ;
    t = k;
    double temp_var_for_tac_10, temp_var_for_tac_11;
    double temp_var_for_const_17;
    temp_var_for_tac_10 = t * ln2_hi;

    temp_var_for_tac_11 = x - temp_var_for_tac_10;

    hi = temp_var_for_tac_11;
    computeDMul((Addr)&temp_var_for_tac_8,
                {(Addr) &(temp_var_for_const_15 = invln2), (Addr)&x},
                "/home/shijia/Public/testprogram/s_expm1.c_e.c:210:18");
    computeDAdd(
        (Addr)&temp_var_for_tac_9,
        {(Addr)&temp_var_for_tac_8,
         (Addr) &(temp_var_for_const_16 = (xsb == 0) ? 0.5 : (0.0 - 0.5))},
        "/home/shijia/Public/testprogram/s_expm1.c_e.c:210:22");
    computeDMul((Addr)&temp_var_for_tac_10,
                {(Addr)&t, (Addr) &(temp_var_for_const_17 = ln2_hi)},
                "/home/shijia/Public/testprogram/s_expm1.c_e.c:212:18");
    computeDSub((Addr)&temp_var_for_tac_11,
                {(Addr)&x, (Addr)&temp_var_for_tac_10},
                "/home/shijia/Public/testprogram/s_expm1.c_e.c:212:14");
    AssignD({(Addr)&hi}, (Addr)&temp_var_for_tac_11,
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:212:10");
    ; /* t*ln2_hi is exact here */
    double temp_var_for_tac_12;
    double temp_var_for_const_18;
    temp_var_for_tac_12 = t * ln2_lo;

    lo = temp_var_for_tac_12;
    computeDMul((Addr)&temp_var_for_tac_12,
                {(Addr)&t, (Addr) &(temp_var_for_const_18 = ln2_lo)},
                "/home/shijia/Public/testprogram/s_expm1.c_e.c:213:14");
    AssignD({(Addr)&lo}, (Addr)&temp_var_for_tac_12,
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:213:10");
    ;
  }
  double temp_var_for_tac_13;
  temp_var_for_tac_13 = hi - lo;

  x = temp_var_for_tac_13;
  computeDSub((Addr)&temp_var_for_tac_13, {(Addr)&hi, (Addr)&lo},
              "/home/shijia/Public/testprogram/s_expm1.c_e.c:215:12");
  AssignD({(Addr)&x}, (Addr)&temp_var_for_tac_13,
          "/home/shijia/Public/testprogram/s_expm1.c_e.c:215:7");
  ;
  double temp_var_for_tac_14, temp_var_for_tac_15;
  temp_var_for_tac_14 = hi - x;

  temp_var_for_tac_15 = temp_var_for_tac_14 - lo;

  c = temp_var_for_tac_15;
  computeDSub((Addr)&temp_var_for_tac_14, {(Addr)&hi, (Addr)&x},
              "/home/shijia/Public/testprogram/s_expm1.c_e.c:216:13");
  computeDSub((Addr)&temp_var_for_tac_15,
              {(Addr)&temp_var_for_tac_14, (Addr)&lo},
              "/home/shijia/Public/testprogram/s_expm1.c_e.c:216:18");
  AssignD({(Addr)&c}, (Addr)&temp_var_for_tac_15,
          "/home/shijia/Public/testprogram/s_expm1.c_e.c:216:7");
  ;
} else {
  if (hx < UC(0x3c900000)) { /* when |x|<2**-54, return x */
    double temp_var_for_tac_16;
    double temp_var_for_const_19;
    temp_var_for_tac_16 = hugeval + x;

    t = temp_var_for_tac_16;
    computeDAdd((Addr)&temp_var_for_tac_16,
                {(Addr) &(temp_var_for_const_19 = hugeval), (Addr)&x},
                "/home/shijia/Public/testprogram/s_expm1.c_e.c:219:19");
    AssignD({(Addr)&t}, (Addr)&temp_var_for_tac_16,
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:219:9");
    ; /* return x with inexact flags when x!=0 */
    double temp_var_for_ext_4;
    double temp_var_for_tac_17, temp_var_for_tac_18, temp_var_for_tac_19;
    double temp_var_for_const_20;
    temp_var_for_tac_17 = hugeval + x;

    temp_var_for_tac_18 = t - temp_var_for_tac_17;

    temp_var_for_tac_19 = x - temp_var_for_tac_18;

    temp_var_for_ext_4 = temp_var_for_tac_19;
    computeDAdd((Addr)&temp_var_for_tac_17,
                {(Addr) &(temp_var_for_const_20 = hugeval), (Addr)&x},
                "/home/shijia/Public/testprogram/s_expm1.c_e.c:221:46");
    computeDSub((Addr)&temp_var_for_tac_18,
                {(Addr)&t, (Addr)&temp_var_for_tac_17},
                "/home/shijia/Public/testprogram/s_expm1.c_e.c:221:35");
    computeDSub((Addr)&temp_var_for_tac_19,
                {(Addr)&x, (Addr)&temp_var_for_tac_18},
                "/home/shijia/Public/testprogram/s_expm1.c_e.c:221:30");
    AssignD({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_19,
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:221:26");
    ;
    callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_4;
  } else {
    k = 0;
    double temp_var_for_const_21;
    c = 0;
    AssignD({(Addr)&c}, (Addr) &(temp_var_for_const_21 = 0),
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:228:9");
    ;
  }
}

/* x is now in primary range */
double temp_var_for_tac_20;
double temp_var_for_const_22;
temp_var_for_tac_20 = 0.5 * x;

hfx = temp_var_for_tac_20;
computeDMul((Addr)&temp_var_for_tac_20,
            {(Addr) &(temp_var_for_const_22 = 0.5), (Addr)&x},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:233:13");
AssignD({(Addr)&hfx}, (Addr)&temp_var_for_tac_20,
        "/home/shijia/Public/testprogram/s_expm1.c_e.c:233:7");
;
double temp_var_for_tac_21;
temp_var_for_tac_21 = x * hfx;

hxs = temp_var_for_tac_21;
computeDMul((Addr)&temp_var_for_tac_21, {(Addr)&x, (Addr)&hfx},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:234:11");
AssignD({(Addr)&hxs}, (Addr)&temp_var_for_tac_21,
        "/home/shijia/Public/testprogram/s_expm1.c_e.c:234:7");
;
#ifdef DO_NOT_USE_THIS
r1 = one + hxs * (Q1 + hxs * (Q2 + hxs * (Q3 + hxs * (Q4 + hxs * Q5))));
#else
double temp_var_for_tac_22, temp_var_for_tac_23;
double temp_var_for_const_23, temp_var_for_const_24;
temp_var_for_tac_22 = hxs * Q[1];

temp_var_for_tac_23 = one + temp_var_for_tac_22;

R1 = temp_var_for_tac_23;
computeDMul((Addr)&temp_var_for_tac_22,
            {(Addr)&hxs, (Addr) &(temp_var_for_const_23 = Q[1])},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:238:18");
computeDAdd((Addr)&temp_var_for_tac_23,
            {(Addr) &(temp_var_for_const_24 = one), (Addr)&temp_var_for_tac_22},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:238:12");
AssignD({(Addr)&R1}, (Addr)&temp_var_for_tac_23,
        "/home/shijia/Public/testprogram/s_expm1.c_e.c:238:6");
;
double temp_var_for_tac_24;
temp_var_for_tac_24 = hxs * hxs;

h2 = temp_var_for_tac_24;
computeDMul((Addr)&temp_var_for_tac_24, {(Addr)&hxs, (Addr)&hxs},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:239:12");
AssignD({(Addr)&h2}, (Addr)&temp_var_for_tac_24,
        "/home/shijia/Public/testprogram/s_expm1.c_e.c:239:6");
;
double temp_var_for_tac_25, temp_var_for_tac_26;
double temp_var_for_const_25, temp_var_for_const_26;
temp_var_for_tac_25 = hxs * Q[3];

temp_var_for_tac_26 = Q[2] + temp_var_for_tac_25;

R2 = temp_var_for_tac_26;
computeDMul((Addr)&temp_var_for_tac_25,
            {(Addr)&hxs, (Addr) &(temp_var_for_const_25 = Q[3])},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:240:19");
computeDAdd((Addr)&temp_var_for_tac_26, {(Addr) &(temp_var_for_const_26 = Q[2]),
                                         (Addr)&temp_var_for_tac_25},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:240:13");
AssignD({(Addr)&R2}, (Addr)&temp_var_for_tac_26,
        "/home/shijia/Public/testprogram/s_expm1.c_e.c:240:6");
;
double temp_var_for_tac_27;
temp_var_for_tac_27 = h2 * h2;

h4 = temp_var_for_tac_27;
computeDMul((Addr)&temp_var_for_tac_27, {(Addr)&h2, (Addr)&h2},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:241:11");
AssignD({(Addr)&h4}, (Addr)&temp_var_for_tac_27,
        "/home/shijia/Public/testprogram/s_expm1.c_e.c:241:6");
;
double temp_var_for_tac_28, temp_var_for_tac_29;
double temp_var_for_const_27, temp_var_for_const_28;
temp_var_for_tac_28 = hxs * Q[5];

temp_var_for_tac_29 = Q[4] + temp_var_for_tac_28;

R3 = temp_var_for_tac_29;
computeDMul((Addr)&temp_var_for_tac_28,
            {(Addr)&hxs, (Addr) &(temp_var_for_const_27 = Q[5])},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:242:19");
computeDAdd((Addr)&temp_var_for_tac_29, {(Addr) &(temp_var_for_const_28 = Q[4]),
                                         (Addr)&temp_var_for_tac_28},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:242:13");
AssignD({(Addr)&R3}, (Addr)&temp_var_for_tac_29,
        "/home/shijia/Public/testprogram/s_expm1.c_e.c:242:6");
;
double temp_var_for_tac_30, temp_var_for_tac_31, temp_var_for_tac_32,
    temp_var_for_tac_33;
temp_var_for_tac_30 = h2 * R2;

temp_var_for_tac_31 = R1 + temp_var_for_tac_30;

temp_var_for_tac_32 = h4 * R3;

temp_var_for_tac_33 = temp_var_for_tac_31 + temp_var_for_tac_32;

r1 = temp_var_for_tac_33;
computeDMul((Addr)&temp_var_for_tac_30, {(Addr)&h2, (Addr)&R2},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:243:16");
computeDAdd((Addr)&temp_var_for_tac_31, {(Addr)&R1, (Addr)&temp_var_for_tac_30},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:243:11");
computeDMul((Addr)&temp_var_for_tac_32, {(Addr)&h4, (Addr)&R3},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:243:26");
computeDAdd((Addr)&temp_var_for_tac_33,
            {(Addr)&temp_var_for_tac_31, (Addr)&temp_var_for_tac_32},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:243:21");
AssignD({(Addr)&r1}, (Addr)&temp_var_for_tac_33,
        "/home/shijia/Public/testprogram/s_expm1.c_e.c:243:6");
;
#endif
double temp_var_for_tac_34, temp_var_for_tac_35;
double temp_var_for_const_29;
temp_var_for_tac_34 = r1 * hfx;

temp_var_for_tac_35 = 3.0 - temp_var_for_tac_34;

t = temp_var_for_tac_35;
computeDMul((Addr)&temp_var_for_tac_34, {(Addr)&r1, (Addr)&hfx},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:245:16");
computeDSub((Addr)&temp_var_for_tac_35,
            {(Addr) &(temp_var_for_const_29 = 3.0), (Addr)&temp_var_for_tac_34},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:245:11");
AssignD({(Addr)&t}, (Addr)&temp_var_for_tac_35,
        "/home/shijia/Public/testprogram/s_expm1.c_e.c:245:5");
;
double temp_var_for_tac_36, temp_var_for_tac_37, temp_var_for_tac_38,
    temp_var_for_tac_39, temp_var_for_tac_40;
double temp_var_for_const_30;
temp_var_for_tac_36 = r1 - t;

temp_var_for_tac_37 = x * t;

temp_var_for_tac_38 = 6.0 - temp_var_for_tac_37;

temp_var_for_tac_39 = temp_var_for_tac_36 / temp_var_for_tac_38;

temp_var_for_tac_40 = hxs * temp_var_for_tac_39;

e = temp_var_for_tac_40;
computeDSub((Addr)&temp_var_for_tac_36, {(Addr)&r1, (Addr)&t},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:246:18");
computeDMul((Addr)&temp_var_for_tac_37, {(Addr)&x, (Addr)&t},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:246:34");
computeDSub((Addr)&temp_var_for_tac_38,
            {(Addr) &(temp_var_for_const_30 = 6.0), (Addr)&temp_var_for_tac_37},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:246:30");
computeDDiv((Addr)&temp_var_for_tac_39,
            {(Addr)&temp_var_for_tac_36, (Addr)&temp_var_for_tac_38},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:246:23");
computeDMul((Addr)&temp_var_for_tac_40,
            {(Addr)&hxs, (Addr)&temp_var_for_tac_39},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:246:11");
AssignD({(Addr)&e}, (Addr)&temp_var_for_tac_40,
        "/home/shijia/Public/testprogram/s_expm1.c_e.c:246:5");
;
if (k == 0) {
  double temp_var_for_ext_5;
  double temp_var_for_tac_41, temp_var_for_tac_42, temp_var_for_tac_43;
  temp_var_for_tac_41 = x * e;

  temp_var_for_tac_42 = temp_var_for_tac_41 - hxs;

  temp_var_for_tac_43 = x - temp_var_for_tac_42;

  temp_var_for_ext_5 = temp_var_for_tac_43;
  computeDMul((Addr)&temp_var_for_tac_41, {(Addr)&x, (Addr)&e},
              "/home/shijia/Public/testprogram/s_expm1.c_e.c:249:33");
  computeDSub((Addr)&temp_var_for_tac_42,
              {(Addr)&temp_var_for_tac_41, (Addr)&hxs},
              "/home/shijia/Public/testprogram/s_expm1.c_e.c:249:37");
  computeDSub((Addr)&temp_var_for_tac_43,
              {(Addr)&x, (Addr)&temp_var_for_tac_42},
              "/home/shijia/Public/testprogram/s_expm1.c_e.c:249:28");
  AssignD({(Addr)&temp_var_for_ext_5}, (Addr)&temp_var_for_tac_43,
          "/home/shijia/Public/testprogram/s_expm1.c_e.c:249:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_5;
}
/* c is 0 */
else {
  double temp_var_for_ext_6;
  double temp_var_for_tac_44, temp_var_for_tac_45, temp_var_for_tac_46;
  temp_var_for_tac_44 = e - c;

  temp_var_for_tac_45 = x * temp_var_for_tac_44;

  temp_var_for_tac_46 = temp_var_for_tac_45 - c;

  temp_var_for_ext_6 = temp_var_for_tac_46;
  computeDSub((Addr)&temp_var_for_tac_44, {(Addr)&e, (Addr)&c},
              "/home/shijia/Public/testprogram/s_expm1.c_e.c:257:34");
  computeDMul((Addr)&temp_var_for_tac_45,
              {(Addr)&x, (Addr)&temp_var_for_tac_44},
              "/home/shijia/Public/testprogram/s_expm1.c_e.c:257:29");
  computeDSub((Addr)&temp_var_for_tac_46,
              {(Addr)&temp_var_for_tac_45, (Addr)&c},
              "/home/shijia/Public/testprogram/s_expm1.c_e.c:257:39");
  AssignD({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_46,
          "/home/shijia/Public/testprogram/s_expm1.c_e.c:257:24");
  ; // e
  /*(t)(x)(6.0)(t)(r1)(hxs)(t)(x)(6.0)(t)(r1)(t)(r1)(t)(x)(6.0)(t)(x)(xt_)(o)(a)(t)(xt_)(o)(a)(o)(a)(c)(c)(e)(x)*/
  e = temp_var_for_ext_6;
  AssignD({(Addr)&e}, (Addr)&temp_var_for_ext_6,
          "/home/shijia/Public/testprogram/s_expm1.c_e.c:259:7");
  ;
  e -= hxs;
  ;
  if (k == -1) {
    double temp_var_for_ext_7;
    double temp_var_for_tac_48, temp_var_for_tac_49, temp_var_for_tac_50;
    double temp_var_for_const_31, temp_var_for_const_32;
    temp_var_for_tac_48 = x - e;

    temp_var_for_tac_49 = 0.5 * temp_var_for_tac_48;

    temp_var_for_tac_50 = temp_var_for_tac_49 - 0.5;

    temp_var_for_ext_7 = temp_var_for_tac_50;
    computeDSub((Addr)&temp_var_for_tac_48, {(Addr)&x, (Addr)&e},
                "/home/shijia/Public/testprogram/s_expm1.c_e.c:263:37");
    computeDMul(
        (Addr)&temp_var_for_tac_49,
        {(Addr) &(temp_var_for_const_31 = 0.5), (Addr)&temp_var_for_tac_48},
        "/home/shijia/Public/testprogram/s_expm1.c_e.c:263:32");
    computeDSub(
        (Addr)&temp_var_for_tac_50,
        {(Addr)&temp_var_for_tac_49, (Addr) &(temp_var_for_const_32 = 0.5)},
        "/home/shijia/Public/testprogram/s_expm1.c_e.c:263:42");
    AssignD({(Addr)&temp_var_for_ext_7}, (Addr)&temp_var_for_tac_50,
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:263:26");
    ;
    callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_7;
  }

  if (k == 1) {
    if (int temp_var_for_tac_51, temp_var_for_tac_52;
        int temp_var_for_const_33, temp_var_for_const_34;
        temp_var_for_tac_51 = 0.0 - 0.25;

        temp_var_for_tac_52 = x < temp_var_for_tac_51;

        ) {
      double temp_var_for_ext_8;
      double temp_var_for_tac_53, temp_var_for_tac_54, temp_var_for_tac_55;
      double temp_var_for_const_35, temp_var_for_const_36;
      temp_var_for_tac_53 = x + 0.5;

      temp_var_for_tac_54 = e - temp_var_for_tac_53;

      temp_var_for_tac_55 = (-(2.0)) * temp_var_for_tac_54;

      temp_var_for_ext_8 = temp_var_for_tac_55;
      computeDSub((Addr)&temp_var_for_tac_51,
                  {(Addr) &(temp_var_for_const_34 = 0.0),
                   (Addr) &(temp_var_for_const_33 = 0.25)},
                  "/home/shijia/Public/testprogram/s_expm1.c_e.c:271:20");
      compute((Addr)&temp_var_for_tac_52,
              {(Addr)&x, (Addr)&temp_var_for_tac_51},
              "/home/shijia/Public/testprogram/s_expm1.c_e.c:271:13");
      computeDAdd((Addr)&temp_var_for_tac_53,
                  {(Addr)&x, (Addr) &(temp_var_for_const_35 = 0.5)},
                  "/home/shijia/Public/testprogram/s_expm1.c_e.c:273:45");
      computeDSub((Addr)&temp_var_for_tac_54,
                  {(Addr)&e, (Addr)&temp_var_for_tac_53},
                  "/home/shijia/Public/testprogram/s_expm1.c_e.c:273:40");
      computeDMul((Addr)&temp_var_for_tac_55,
                  {(Addr) &(temp_var_for_const_36 = (-(2.0))),
                   (Addr)&temp_var_for_tac_54},
                  "/home/shijia/Public/testprogram/s_expm1.c_e.c:273:35");
      AssignD({(Addr)&temp_var_for_ext_8}, (Addr)&temp_var_for_tac_55,
              "/home/shijia/Public/testprogram/s_expm1.c_e.c:273:28");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
      callExp++; /*identify the function is  add move tmpShadow*/
      return (0.0 - rn)temp_var_for_ext_8;
    }

    else {
      double temp_var_for_ext_9;
      double temp_var_for_tac_56, temp_var_for_tac_57, temp_var_for_tac_58;
      double temp_var_for_const_37, temp_var_for_const_38;
      temp_var_for_tac_56 = x - e;

      temp_var_for_tac_57 = 2.0 * temp_var_for_tac_56;

      temp_var_for_tac_58 = one + temp_var_for_tac_57;

      temp_var_for_ext_9 = temp_var_for_tac_58;
      computeDSub((Addr)&temp_var_for_tac_56, {(Addr)&x, (Addr)&e},
                  "/home/shijia/Public/testprogram/s_expm1.c_e.c:282:45");
      computeDMul(
          (Addr)&temp_var_for_tac_57,
          {(Addr) &(temp_var_for_const_37 = 2.0), (Addr)&temp_var_for_tac_56},
          "/home/shijia/Public/testprogram/s_expm1.c_e.c:282:40");
      computeDAdd(
          (Addr)&temp_var_for_tac_58,
          {(Addr) &(temp_var_for_const_38 = one), (Addr)&temp_var_for_tac_57},
          "/home/shijia/Public/testprogram/s_expm1.c_e.c:282:34");
      AssignD({(Addr)&temp_var_for_ext_9}, (Addr)&temp_var_for_tac_58,
              "/home/shijia/Public/testprogram/s_expm1.c_e.c:282:28");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_9;
    }
  }
  if (k <= -2 || k > 56) { /* suffice to return exp(x)-1 */
    uint32_t high;

    double temp_var_for_tac_59, temp_var_for_tac_60;
    double temp_var_for_const_39;
    temp_var_for_tac_59 = e - x;

    temp_var_for_tac_60 = one - temp_var_for_tac_59;

    y = temp_var_for_tac_60;
    computeDSub((Addr)&temp_var_for_tac_59, {(Addr)&e, (Addr)&x},
                "/home/shijia/Public/testprogram/s_expm1.c_e.c:292:20");
    computeDSub(
        (Addr)&temp_var_for_tac_60,
        {(Addr) &(temp_var_for_const_39 = one), (Addr)&temp_var_for_tac_59},
        "/home/shijia/Public/testprogram/s_expm1.c_e.c:292:15");
    AssignD({(Addr)&y}, (Addr)&temp_var_for_tac_60,
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:292:9");
    ;
    GET_HIGH_WORD(high, y);
    SET_HIGH_WORD(y, high + (k << 20)); /* add k to y's exponent */
    double temp_var_for_ext_10;
    double temp_var_for_tac_61;
    double temp_var_for_const_40;
    temp_var_for_tac_61 = y - one;

    temp_var_for_ext_10 = temp_var_for_tac_61;
    computeDSub((Addr)&temp_var_for_tac_61,
                {(Addr)&y, (Addr) &(temp_var_for_const_40 = one)},
                "/home/shijia/Public/testprogram/s_expm1.c_e.c:296:31");
    AssignD({(Addr)&temp_var_for_ext_10}, (Addr)&temp_var_for_tac_61,
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:296:27");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_10", (Addr)&temp_var_for_ext_10));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_10;
  }
  double temp_var_for_ext_11;
  double temp_var_for_const_41;
  temp_var_for_ext_11 = one;
  AssignD({(Addr)&temp_var_for_ext_11}, (Addr) &(temp_var_for_const_41 = one),
          "/home/shijia/Public/testprogram/s_expm1.c_e.c:303:25");
  ; // t
  /*(x)(e)(one)(one)(one[one])(x)(e)(_10)(_10)(_10[_10])(t)(one)(one)(one[one])*/
  t = temp_var_for_ext_11;
  AssignD({(Addr)&t}, (Addr)&temp_var_for_ext_11,
          "/home/shijia/Public/testprogram/s_expm1.c_e.c:305:7");
  ;
  if (k < 20) {
    uint32_t high;

    SET_HIGH_WORD(t, UC(0x3ff00000) - (UC(0x200000) >> k)); /* t=1-2^-k */
    double temp_var_for_tac_62, temp_var_for_tac_63;
    temp_var_for_tac_62 = e - x;

    temp_var_for_tac_63 = t - temp_var_for_tac_62;

    y = temp_var_for_tac_63;
    computeDSub((Addr)&temp_var_for_tac_62, {(Addr)&e, (Addr)&x},
                "/home/shijia/Public/testprogram/s_expm1.c_e.c:310:18");
    computeDSub((Addr)&temp_var_for_tac_63,
                {(Addr)&t, (Addr)&temp_var_for_tac_62},
                "/home/shijia/Public/testprogram/s_expm1.c_e.c:310:13");
    AssignD({(Addr)&y}, (Addr)&temp_var_for_tac_63,
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:310:9");
    ;
    GET_HIGH_WORD(high, y);
    SET_HIGH_WORD(y, high + (k << 20)); /* add k to y's exponent */
  } else {
    uint32_t high;

    SET_HIGH_WORD(t, ((UC(0x3ff) - k) << 20)); /* 2^-k */
    double temp_var_for_tac_64, temp_var_for_tac_65;
    temp_var_for_tac_64 = e + t;

    temp_var_for_tac_65 = x - temp_var_for_tac_64;

    y = temp_var_for_tac_65;
    computeDAdd((Addr)&temp_var_for_tac_64, {(Addr)&e, (Addr)&t},
                "/home/shijia/Public/testprogram/s_expm1.c_e.c:317:18");
    computeDSub((Addr)&temp_var_for_tac_65,
                {(Addr)&x, (Addr)&temp_var_for_tac_64},
                "/home/shijia/Public/testprogram/s_expm1.c_e.c:317:13");
    AssignD({(Addr)&y}, (Addr)&temp_var_for_tac_65,
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:317:9");
    ;
    y += one;
    ;
    GET_HIGH_WORD(high, y);
    SET_HIGH_WORD(y, high + (k << 20)); /* add k to y's exponent */
  }
}
double temp_var_for_ext_12;
temp_var_for_ext_12 = y;
AssignD({(Addr)&temp_var_for_ext_12}, (Addr)&y,
        "/home/shijia/Public/testprogram/s_expm1.c_e.c:324:23");
;
callExpStack.push(getReal("temp_var_for_ext_12", (Addr)&temp_var_for_ext_12));
callExp++; /*identify the function is  add move tmpShadow*/
return temp_var_for_ext_12;
#undef one
}

#endif

double __expm1(double x) {
  double z = __ieee754_expm1(x);

  if ((!isfinite(z) || int temp_var_for_tac_67, temp_var_for_tac_68;
       int temp_var_for_const_42, temp_var_for_const_43;
       temp_var_for_tac_67 = 0.0 - 1.0;

       temp_var_for_tac_68 = z == temp_var_for_tac_67;

       ) &&
      isfinite(x) && _LIB_VERSION != _IEEE_) {
    double temp_var_for_ext_13;
    double temp_var_for_const_44;
    double temp_var_for_callexp_1;

    temp_var_for_callexp_1 =
        __kernel_standard(x, x, z, signbit(x) ? KMATHERR_EXPM1_UNDERFLOW
                                              : KMATHERR_EXPM1_OVERFLOW);
    temp_var_for_ext_13 = temp_var_for_callexp_1;
    computeDSub((Addr)&temp_var_for_tac_67,
                {(Addr) &(temp_var_for_const_43 = 0.0),
                 (Addr) &(temp_var_for_const_42 = 1.0)},
                "/home/shijia/Public/testprogram/s_expm1.c_e.c:336:34");
    compute((Addr)&temp_var_for_tac_68, {(Addr)&z, (Addr)&temp_var_for_tac_67},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:336:26");
    AssignD({(Addr)&temp_var_for_ext_13},
            (Addr) &(temp_var_for_const_44 = temp_var_for_callexp_1),
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:339:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_13", (Addr)&temp_var_for_ext_13));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_13;
  }

  double temp_var_for_ext_14;
  temp_var_for_ext_14 = z;
  callExpStack.push(getReal("temp_var_for_ext_14", (Addr)&temp_var_for_ext_14));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_14;
}

__typeof(__expm1) expm1 __attribute__((weak, alias("__expm1")));
#ifdef __NO_LONG_DOUBLE_MATH
long double __expm1l(long double x) __attribute__((alias("__expm1")));
__typeof(__expm1l) expm1l __attribute__((weak, alias("__expm1")));
#endif
