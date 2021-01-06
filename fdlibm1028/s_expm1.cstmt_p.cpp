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
    (0.0 - 3.33333333333331316428e-02);
  double temp_var_for_const_0, temp_var_for_const_1;
  ,                               /* BFA11111 111110F4 */
      1.58730158725481460165e-03, /* 3F5A01A0 19FE5585 */
      (0.0 - 7.93650757867487942473e-05);
  double temp_var_for_const_2, temp_var_for_const_3;
  double temp_var_for_tac_0;
  computeDSub((Addr)&temp_var_for_tac_0,
              {(Addr) &(temp_var_for_const_1 = 0.0),
               (Addr) &(temp_var_for_const_0 = 3.33333333333331316428e-02)},
              "/home/shijia/Public/testprogram/s_expm1.c_e.c:136:12");
  ,                               /* BF14CE19 9EAADBB7 */
      4.00821782732936239552e-06, /* 3ED0CFCA 86E65239 */
      (0.0 - 2.01099218183624371326e-07);
  double temp_var_for_const_4, temp_var_for_const_5;
  double temp_var_for_tac_1;
  computeDSub(
      (Addr)&temp_var_for_tac_1,
      {(Addr) &(temp_var_for_const_3 = 0.0),
       (Addr) &(temp_var_for_const_2 = 7.93650757867487942473e-05)},
      "/home/shijia/Public/testprogram/s_expm1.c_e.c:138:12"); /* BE8AFDB7
                                                                  6E09C32D */
};

GET_HIGH_WORD(hx, x);
xsb = hx & IC(0x80000000); /* sign bit of x */
if (xsb == 0)
  y = x;
else
  y = -x;             /* y = |x| */
hx &= UC(0x7fffffff); /* high word of |x| */

/* filter out hugeval and non-finite argument */
if (hx >= UC(0x4043687A)) {   /* if |x|>=56*ln2 */
  if (hx >= UC(0x40862E42)) { /* if |x|>=709.78... */
    if (hx >= UC(0x7ff00000)) {
      uint32_t low;

      GET_LOW_WORD(low, x);
      if (((hx & UC(0xfffff)) | low) != 0)
        return x + x;               /* NaN */
      return (xsb == 0) ? x : -one; /* exp(+-inf)={inf,-1} */
    }
    if (x > o_threshold) {
      feraiseexcept(FE_OVERFLOW);
      return HUGE_VAL; /* overflow */
    }
  }
  if (xsb != 0) {              /* x < -56*ln2, return -1.0 with inexact */
    feraiseexcept(FE_INEXACT); /* raise inexact */
    return -one;               /* return -1 */
  }
}

/* argument reduction */
if (hx > UC(0x3fd62e42)) {   /* if  |x| > 0.5 ln2 */
  if (hx < UC(0x3FF0A2B2)) { /* and |x| < 1.5 ln2 */
    if (xsb == 0) {
      hi = x - ln2_hi;
      lo = ln2_lo;
      k = 1;
    } else {
      hi = x + ln2_hi;
      lo = -ln2_lo;
      k = -1;
    }
  } else {
    k = invln2 * x + ((xsb == 0) ? 0.5 : -0.5);
    t = k;
    hi = x - t * ln2_hi; /* t*ln2_hi is exact here */
    lo = t * ln2_lo;
  }
  x = hi - lo;
  c = (hi - x) - lo;
} else if (hx < UC(0x3c900000)) { /* when |x|<2**-54, return x */
  t = hugeval + x;                /* return x with inexact flags when x!=0 */
  return x - (t - (hugeval + x));
} else {
  k = 0;
  c = 0;
}

/* x is now in primary range */
hfx = 0.5 * x;
double temp_var_for_const_6;
double temp_var_for_tac_2;
computeDSub((Addr)&temp_var_for_tac_2,
            {(Addr) &(temp_var_for_const_5 = 0.0),
             (Addr) &(temp_var_for_const_4 = 2.01099218183624371326e-07)},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:200:13");
computeDMul((Addr)&hfx, {(Addr) &(temp_var_for_const_6 = 0.5), (Addr)&x},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:200:7");
hxs = x * hfx;
computeDMul((Addr)&hxs, {(Addr)&x, (Addr)&hfx},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:201:7");
#ifdef DO_NOT_USE_THIS
r1 = one + hxs * (Q1 + hxs * (Q2 + hxs * (Q3 + hxs * (Q4 + hxs * Q5))));
#else
R1 = one + hxs * Q[1];
double temp_var_for_const_7, temp_var_for_const_8;
double temp_var_for_tac_3;
computeDMul((Addr)&temp_var_for_tac_3,
            {(Addr)&hxs, (Addr) &(temp_var_for_const_7 = Q[1])},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:205:12");
computeDAdd((Addr)&R1, {(Addr) &(temp_var_for_const_8 = Q[one]),
                        (Addr)&temp_var_for_tac_3},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:205:6");
h2 = hxs * hxs;
computeDMul((Addr)&h2, {(Addr)&hxs, (Addr)&hxs},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:206:6");
R2 = Q[2] + hxs * Q[3];
double temp_var_for_const_9, temp_var_for_const_10;
double temp_var_for_tac_4;
computeDMul((Addr)&temp_var_for_tac_4,
            {(Addr)&hxs, (Addr) &(temp_var_for_const_9 = Q[3])},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:207:13");
computeDAdd((Addr)&R2,
            {(Addr) &(temp_var_for_const_10 = Q[2]), (Addr)&temp_var_for_tac_4},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:207:6");
h4 = h2 * h2;
computeDMul((Addr)&h4, {(Addr)&h2, (Addr)&h2},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:208:6");
R3 = Q[4] + hxs * Q[5];
double temp_var_for_const_11, temp_var_for_const_12;
double temp_var_for_tac_5;
computeDMul((Addr)&temp_var_for_tac_5,
            {(Addr)&hxs, (Addr) &(temp_var_for_const_11 = Q[5])},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:209:13");
computeDAdd((Addr)&R3,
            {(Addr) &(temp_var_for_const_12 = Q[4]), (Addr)&temp_var_for_tac_5},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:209:6");
r1 = R1 + h2 * R2 + h4 * R3;
double temp_var_for_tac_6, temp_var_for_tac_7, temp_var_for_tac_8;
computeDMul((Addr)&temp_var_for_tac_6, {(Addr)&h2, (Addr)&R2},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:210:11");
computeDAdd((Addr)&temp_var_for_tac_7, {(Addr)&R1, (Addr)&temp_var_for_tac_6},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:210:26");
computeDMul((Addr)&temp_var_for_tac_8, {(Addr)&h4, (Addr)&R3},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:210:21");
computeDAdd((Addr)&r1, {(Addr)&temp_var_for_tac_7, (Addr)&temp_var_for_tac_8},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:210:6");
#endif
t = 3.0 - r1 * hfx;
double temp_var_for_const_13;
double temp_var_for_tac_9;
computeDMul((Addr)&temp_var_for_tac_9, {(Addr)&r1, (Addr)&hfx},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:212:11");
computeDSub((Addr)&t,
            {(Addr) &(temp_var_for_const_13 = 3.0), (Addr)&temp_var_for_tac_9},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:212:5");
e = hxs * ((r1 - t) / (6.0 - x * t));
double temp_var_for_const_14;
double temp_var_for_tac_10, temp_var_for_tac_11, temp_var_for_tac_12,
    temp_var_for_tac_13;
computeDSub((Addr)&temp_var_for_tac_10, {(Addr)&r1, (Addr)&t},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:213:34");
computeDMul((Addr)&temp_var_for_tac_11, {(Addr)&x, (Addr)&t},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:213:30");
computeDSub((Addr)&temp_var_for_tac_12,
            {(Addr) &(temp_var_for_const_14 = 6.0), (Addr)&temp_var_for_tac_11},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:213:23");
computeDDiv((Addr)&temp_var_for_tac_13,
            {(Addr)&temp_var_for_tac_10, (Addr)&temp_var_for_tac_12},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:213:11");
computeDMul((Addr)&e, {(Addr)&hxs, (Addr)&temp_var_for_tac_13},
            "/home/shijia/Public/testprogram/s_expm1.c_e.c:213:5");
if (k == 0)
  return x - (x * e - hxs); /* c is 0 */
else {
  e = (x * (e - c) - c);
  e -= hxs;
  if (k == -1)
    return 0.5 * (x - e) - 0.5;
  if (k == 1) {
    if (x < -0.25)
      return -2.0 * (e - (x + 0.5));
    else
      return one + 2.0 * (x - e);
  }
  if (k <= -2 || k > 56) { /* suffice to return exp(x)-1 */
    uint32_t high;

    y = one - (e - x);
    GET_HIGH_WORD(high, y);
    SET_HIGH_WORD(y, high + (k << 20)); /* add k to y's exponent */
    return y - one;
  }
  t = one;
  if (k < 20) {
    uint32_t high;

    SET_HIGH_WORD(t, UC(0x3ff00000) - (UC(0x200000) >> k)); /* t=1-2^-k */
    y = t - (e - x);
    GET_HIGH_WORD(high, y);
    SET_HIGH_WORD(y, high + (k << 20)); /* add k to y's exponent */
  } else {
    uint32_t high;

    SET_HIGH_WORD(t, ((UC(0x3ff) - k) << 20)); /* 2^-k */
    y = x - (e + t);
    y += one;
    GET_HIGH_WORD(high, y);
    SET_HIGH_WORD(y, high + (k << 20)); /* add k to y's exponent */
  }
}
double temp_var_for_ext_0;
temp_var_for_ext_0 = y;
AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&y,
        "/home/shijia/Public/testprogram/s_expm1.c_e.c:254:22");
callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
callExp++; /*identify the function is  add move tmpShadow*/
return temp_var_for_ext_0;
#undef one
}

#endif

double __expm1(double x) {
  double z = __ieee754_expm1(x);

  if ((!isfinite(z) || z == -1.0) && isfinite(x) && _LIB_VERSION != _IEEE_)
    return __kernel_standard(x, x, z, signbit(x) ? KMATHERR_EXPM1_UNDERFLOW
                                                 : KMATHERR_EXPM1_OVERFLOW);

  double temp_var_for_ext_1;
  temp_var_for_ext_1 = z;
  AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&z,
          "/home/shijia/Public/testprogram/s_expm1.c_e.c:271:22");
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

__typeof(__expm1) expm1 __attribute__((weak, alias("__expm1")));
#ifdef __NO_LONG_DOUBLE_MATH
long double __expm1l(long double x) __attribute__((alias("__expm1")));
__typeof(__expm1l) expm1l __attribute__((weak, alias("__expm1")));
#endif
