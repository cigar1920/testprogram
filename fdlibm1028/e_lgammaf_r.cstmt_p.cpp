#include "../ScDebug/scdebug.h"
/* e_lgammaf_r.c -- float version of e_lgamma_r.c.
 * Conversion to float by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.
 */

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

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

static float sin_pif(float x) {
  float y, z;
  int32_t n, ix;

  static const float zero = 0.0000000000e+00;
  static const float one = 1.0000000000e+00;   /* 0x3f800000 */
  static const float pi = 3.1415927410e+00;    /* 0x40490fdb */
  static const float two23 = 8.3886080000e+06; /* 0x4b000000 */

  GET_FLOAT_WORD(ix, x);
  ix &= IC(0x7fffffff);

  if (ix < IC(0x3e800000))
#ifdef __have_fpu_sin
    return __ieee754_sinf(pi * x);
#else
    return __kernel_sinf(pi * x, zero, 0);
#endif
  y = (0.0 - x);
  float temp_var_for_const_0;
  computeFSub(
      (Addr)&y,
      {(Addr) &(temp_var_for_const_0 = 0.0), (Addr)&x}, "/home/shijia/Public/"
                                                        "testprogram/"
                                                        "e_lgammaf_r.c_e.c:38:"
                                                        "5"); /* x is assume
                                                                 negative */

  /*
   * argument reduction, make sure inexact flag not raised if input
   * is an integer
   */
  z = __ieee754_floorf(y);
  float temp_var_for_const_1;AssignF({(Addr)&z},(Addr)&(temp_var_for_const_1=__ieee754_floorf(getFVbyShadow<int>((Addr)&y)),"/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:44:5");
  if (z != y) { /* inexact anyway */
    y *= 0.5F;
    float temp_var_for_ext_0;
    temp_var_for_ext_0 = 2.0F * (y - __ieee754_floorf(y));
    float temp_var_for_const_2, temp_var_for_const_3;
    float temp_var_for_tac_0;computeFSub((Addr)&temp_var_for_tac_0,{(Addr)&y,(Addr)&(temp_var_for_const_2=__ieee754_floorf(getFVbyShadow<int>((Addr)&y))},"/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:48:31");
    computeFMul(
        (Addr)&temp_var_for_ext_0,
        {(Addr) &(temp_var_for_const_3 = 2.0F), (Addr)&temp_var_for_tac_0},
        "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:48:24"); // y
    /*(0.5F)(y)(__ieee754_floorf(y))(y)(2.0F)*/
    y = temp_var_for_ext_0;
    AssignF({(Addr)&y}, (Addr)&temp_var_for_ext_0,
            "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:50:7"); /* y =
                                                                          |x|
                                                                          mod
                                                                          2.0 */
    n = (int32_t)(y * 4.0F);
  } else {
    if (ix >= IC(0x4b800000)) {
      y = zero;
      n = 0; /* y must be even */
    } else {
      if (ix < IC(0x4b000000))
        z = y + two23; /* exact */
      GET_FLOAT_WORD(n, z);
      n &= 1;
      y = n;
      n <<= 2;
    }
  }
#ifdef __have_fpu_sin
  switch ((int)n) {
  case 0:
    y = __ieee754_sinf(pi * y);
    break;
  case 1:
  case 2:
    y = __ieee754_cosf(pi * (0.5F - y));
    break;
  case 3:
  case 4:
    y = __ieee754_sinf(pi * (one - y));
    break;
  case 5:
  case 6:
    y = -__ieee754_cosf(pi * (y - 1.5F));
    break;
  default:
    y = __ieee754_sinf(pi * (y - 2.0F));
    break;
  }
#else
  switch ((int)n) {
  case 0:
    y = __kernel_sinf(pi * y, zero, 0);
    break;
  case 1:
  case 2:
    y = __kernel_cosf(pi * (0.5F - y), zero);
    break;
  case 3:
  case 4:
    y = __kernel_sinf(pi * (one - y), zero, 0);
    break;
  case 5:
  case 6:
    y = -__kernel_cosf(pi * (y - 1.5F), zero);
    break;
  default:
    y = __kernel_sinf(pi * (y - 2.0F), zero, 0);
    break;
  }
#endif
  float temp_var_for_ext_1;
  temp_var_for_ext_1 = -y;AssignF({(Addr)&temp_var_for_ext_1},(Addr)&(-(y)),"/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:109:22");
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return (0.0 - 1);double temp_var_for_const_4,temp_var_for_const_5;;
double temp_var_for_tac_1 ;computeDSub((Addr)&temp_var_for_tac_1,{(Addr)&(temp_var_for_const_5=0.0),(Addr)&(temp_var_for_const_4=1)},"toString(biExpr->getExprLoc())");
}

float __ieee754_lgammaf_r(float x, int *signgamp) {
  float t, y, z, nadj = 0, p, p1, p2, p3, q, r, w;
  int32_t i, hx, ix;

  static const float zero = 0.0000000000e+00;

  static const float half = 5.0000000000e-01; /* 0x3f000000 */
  static const float one = 1.0000000000e+00;  /* 0x3f800000 */
  static const float pi = 3.1415927410e+00;   /* 0x40490fdb */
  static const float a0 = 7.7215664089e-02;   /* 0x3d9e233f */
  static const float a1 = 3.2246702909e-01;   /* 0x3ea51a66 */
  static const float a2 = 6.7352302372e-02;   /* 0x3d89f001 */
  static const float a3 = 2.0580807701e-02;   /* 0x3ca89915 */
  static const float a4 = 7.3855509982e-03;   /* 0x3bf2027e */
  static const float a5 = 2.8905137442e-03;   /* 0x3b3d6ec6 */
  static const float a6 = 1.1927076848e-03;   /* 0x3a9c54a1 */
  static const float a7 = 5.1006977446e-04;   /* 0x3a05b634 */
  static const float a8 = 2.2086278477e-04;   /* 0x39679767 */
  static const float a9 = 1.0801156895e-04;   /* 0x38e28445 */
  static const float a10 = 2.5214456400e-05;  /* 0x37d383a2 */
  static const float a11 = 4.4864096708e-05;  /* 0x383c2c75 */
  static const float tc = 1.4616321325e+00;   /* 0x3fbb16c3 */
  static const float tf = (0.0 - 1.2148628384e-01);
  double temp_var_for_const_6, temp_var_for_const_7;
  ; /* 0xbdf8cdcd */

  /* tt = -(tail of tf) */
  static const float tt = 6.6971006518e-09; /* 0x31e61c52 */
  static const float t0 = 4.8383611441e-01; /* 0x3ef7b95e */
  static const float t1 = (0.0 - 1.4758771658e-01);
  double temp_var_for_const_8, temp_var_for_const_9;
  double temp_var_for_tac_2;
  computeDSub((Addr)&temp_var_for_tac_2,
              {(Addr) &(temp_var_for_const_7 = 0.0),
               (Addr) &(temp_var_for_const_6 = 1.2148628384e-01)},
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:142:32");
  ;                                         /* 0xbe17213c */
  static const float t2 = 6.4624942839e-02; /* 0x3d845a15 */
  static const float t3 = (0.0 - 3.2788541168e-02);
  double temp_var_for_const_10, temp_var_for_const_11;
  double temp_var_for_tac_3;
  computeDSub((Addr)&temp_var_for_tac_3,
              {(Addr) &(temp_var_for_const_9 = 0.0),
               (Addr) &(temp_var_for_const_8 = 1.4758771658e-01)},
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:144:32");
  ;                                         /* 0xbd064d47 */
  static const float t4 = 1.7970675603e-02; /* 0x3c93373d */
  static const float t5 = (0.0 - 1.0314224288e-02);
  double temp_var_for_const_12, temp_var_for_const_13;
  double temp_var_for_tac_4;
  computeDSub((Addr)&temp_var_for_tac_4,
              {(Addr) &(temp_var_for_const_11 = 0.0),
               (Addr) &(temp_var_for_const_10 = 3.2788541168e-02)},
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:146:32");
  ;                                         /* 0xbc28fcfe */
  static const float t6 = 6.1005386524e-03; /* 0x3bc7e707 */
  static const float t7 = (0.0 - 3.6845202558e-03);
  double temp_var_for_const_14, temp_var_for_const_15;
  double temp_var_for_tac_5;
  computeDSub((Addr)&temp_var_for_tac_5,
              {(Addr) &(temp_var_for_const_13 = 0.0),
               (Addr) &(temp_var_for_const_12 = 1.0314224288e-02)},
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:148:32");
  ;                                         /* 0xbb7177fe */
  static const float t8 = 2.2596477065e-03; /* 0x3b141699 */
  static const float t9 = (0.0 - 1.4034647029e-03);
  double temp_var_for_const_16, temp_var_for_const_17;
  double temp_var_for_tac_6;
  computeDSub((Addr)&temp_var_for_tac_6,
              {(Addr) &(temp_var_for_const_15 = 0.0),
               (Addr) &(temp_var_for_const_14 = 3.6845202558e-03)},
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:150:32");
  ;                                          /* 0xbab7f476 */
  static const float t10 = 8.8108185446e-04; /* 0x3a66f867 */
  static const float t11 = (0.0 - 5.3859531181e-04);
  double temp_var_for_const_18, temp_var_for_const_19;
  double temp_var_for_tac_7;
  computeDSub((Addr)&temp_var_for_tac_7,
              {(Addr) &(temp_var_for_const_17 = 0.0),
               (Addr) &(temp_var_for_const_16 = 1.4034647029e-03)},
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:152:33");
  ;                                          /* 0xba0d3085 */
  static const float t12 = 3.1563205994e-04; /* 0x39a57b6b */
  static const float t13 = (0.0 - 3.1275415677e-04);
  double temp_var_for_const_20, temp_var_for_const_21;
  double temp_var_for_tac_8;
  computeDSub((Addr)&temp_var_for_tac_8,
              {(Addr) &(temp_var_for_const_19 = 0.0),
               (Addr) &(temp_var_for_const_18 = 5.3859531181e-04)},
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:154:33");
  ;                                          /* 0xb9a3f927 */
  static const float t14 = 3.3552918467e-04; /* 0x39afe9f7 */
  static const float u0 = (0.0 - 7.7215664089e-02);
  double temp_var_for_const_22, temp_var_for_const_23;
  double temp_var_for_tac_9;
  computeDSub((Addr)&temp_var_for_tac_9,
              {(Addr) &(temp_var_for_const_21 = 0.0),
               (Addr) &(temp_var_for_const_20 = 3.1275415677e-04)},
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:156:32");
  ;                                         /* 0xbd9e233f */
  static const float u1 = 6.3282704353e-01; /* 0x3f2200f4 */
  static const float u2 = 1.4549225569e+00; /* 0x3fba3ae7 */
  static const float u3 = 9.7771751881e-01; /* 0x3f7a4bb2 */
  static const float u4 = 2.2896373272e-01; /* 0x3e6a7578 */
  static const float u5 = 1.3381091878e-02; /* 0x3c5b3c5e */
  static const float v1 = 2.4559779167e+00; /* 0x401d2ebe */
  static const float v2 = 2.1284897327e+00; /* 0x4008392d */
  static const float v3 = 7.6928514242e-01; /* 0x3f44efdf */
  static const float v4 = 1.0422264785e-01; /* 0x3dd572af */
  static const float v5 = 3.2170924824e-03; /* 0x3b52d5db */
  static const float s0 = (0.0 - 7.7215664089e-02);
  double temp_var_for_const_24, temp_var_for_const_25;
  double temp_var_for_tac_10;
  computeDSub((Addr)&temp_var_for_tac_10,
              {(Addr) &(temp_var_for_const_23 = 0.0),
               (Addr) &(temp_var_for_const_22 = 7.7215664089e-02)},
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:167:32");
  ;                                         /* 0xbd9e233f */
  static const float s1 = 2.1498242021e-01; /* 0x3e5c245a */
  static const float s2 = 3.2577878237e-01; /* 0x3ea6cc7a */
  static const float s3 = 1.4635047317e-01; /* 0x3e15dce6 */
  static const float s4 = 2.6642270386e-02; /* 0x3cda40e4 */
  static const float s5 = 1.8402845599e-03; /* 0x3af135b4 */
  static const float s6 = 3.1947532989e-05; /* 0x3805ff67 */
  static const float r1 = 1.3920053244e+00; /* 0x3fb22d3b */
  static const float r2 = 7.2193557024e-01; /* 0x3f38d0c5 */
  static const float r3 = 1.7193385959e-01; /* 0x3e300f6e */
  static const float r4 = 1.8645919859e-02; /* 0x3c98bf54 */
  static const float r5 = 7.7794247773e-04; /* 0x3a4beed6 */
  static const float r6 = 7.3266842264e-06; /* 0x36f5d7bd */
  static const float w0 = 4.1893854737e-01; /* 0x3ed67f1d */
  static const float w1 = 8.3333335817e-02; /* 0x3daaaaab */
  static const float w2 = (0.0 - 2.7777778450e-03);
  double temp_var_for_const_26, temp_var_for_const_27;
  double temp_var_for_tac_11;
  computeDSub((Addr)&temp_var_for_tac_11,
              {(Addr) &(temp_var_for_const_25 = 0.0),
               (Addr) &(temp_var_for_const_24 = 7.7215664089e-02)},
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:182:32");
  ;                                         /* 0xbb360b61 */
  static const float w3 = 7.9365057172e-04; /* 0x3a500cfd */
  static const float w4 = (0.0 - 5.9518753551e-04);
  double temp_var_for_const_28, temp_var_for_const_29;
  double temp_var_for_tac_12;
  computeDSub((Addr)&temp_var_for_tac_12,
              {(Addr) &(temp_var_for_const_27 = 0.0),
               (Addr) &(temp_var_for_const_26 = 2.7777778450e-03)},
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:184:32");
  ;                                         /* 0xba1c065c */
  static const float w5 = 8.3633989561e-04; /* 0x3a5b3dd2 */
  static const float w6 = (0.0 - 1.6309292987e-03);
  double temp_var_for_const_30, temp_var_for_const_31;
  double temp_var_for_tac_13;
  computeDSub((Addr)&temp_var_for_tac_13,
              {(Addr) &(temp_var_for_const_29 = 0.0),
               (Addr) &(temp_var_for_const_28 = 5.9518753551e-04)},
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:186:32");
  ; /* 0xbad5c4e8 */

  GET_FLOAT_WORD(hx, x);

  /* purge off +-inf, NaN, +-0, and negative arguments */
  *signgamp = 1;
  ix = hx & IC(0x7fffffff);
  if (ix >= IC(0x7f800000))
    return x * x;
  if (ix == 0) {
    if (hx < 0)
      *signgamp = -1;
    return one / __ieee754_fabsf(x);
  }
  if (ix < IC(0x1c800000)) {
    /* |x|<2**-70, return -log(|x|) */
    if (hx < 0) {
      *signgamp = -1;
      return -__ieee754_logf(-x);
    } else
      return -__ieee754_logf(x);
  }
  if (hx < 0) {
    if (ix >= IC(0x4b000000)) /* |x|>=2**23, must be -integer */
      return x / zero;
    t = sin_pif(x);
    if (t == zero)
      return one / __ieee754_fabsf(t); /* -integer */
    nadj = __ieee754_logf(pi / __ieee754_fabsf(t * x));
    if (t < zero)
      *signgamp = -1;
    x = -x;
  }

  /* purge off 1 and 2 */
  if (ix == IC(0x3f800000) || ix == IC(0x40000000))
    r = 0;
  /* for x < 2.0 */
  else if (ix < IC(0x40000000)) {
    if (ix <= IC(0x3f666666)) { /* lgamma(x) = lgamma(x+1)-log(x) */
      r = -__ieee754_logf(x);
      if (ix >= IC(0x3f3b4a20)) {
        y = one - x;
        i = 0;
      } else if (ix >= IC(0x3e6d3308)) {
        y = x - (tc - one);
        i = 1;
      } else {
        y = x;
        i = 2;
      }
    } else {
      r = zero;
      if (ix >= IC(0x3fdda618)) {
        y = 2.0F - x;
        i = 0;
      } /* [1.7316,2] */
      else if (ix >= IC(0x3F9da620)) {
        y = x - tc;
        i = 1;
      } /* [1.23,1.73] */
      else {
        y = x - one;
        i = 2;
      }
    }
    switch ((int)i) {
    case 0:
      z = y * y;
      p1 = a0 + z * (a2 + z * (a4 + z * (a6 + z * (a8 + z * a10))));
      p2 = z * (a1 + z * (a3 + z * (a5 + z * (a7 + z * (a9 + z * a11)))));
      p = y * p1 + p2;
      r += (p - 0.5F * y);
      break;
    case 1:
      z = y * y;
      w = z * y;
      p1 = t0 + w * (t3 + w * (t6 + w * (t9 + w * t12))); /* parallel comp */
      p2 = t1 + w * (t4 + w * (t7 + w * (t10 + w * t13)));
      p3 = t2 + w * (t5 + w * (t8 + w * (t11 + w * t14)));
      p = z * p1 - (tt - w * (p2 + y * p3));
      r += (tf + p);
      break;
    case 2:
      p1 = y * (u0 + y * (u1 + y * (u2 + y * (u3 + y * (u4 + y * u5)))));
      p2 = one + y * (v1 + y * (v2 + y * (v3 + y * (v4 + y * v5))));
      r += (-0.5F * y + p1 / p2);
      break;
    }
  } else if (ix < IC(0x41000000)) { /* x < 8.0 */
    i = (int32_t)x;
    t = zero;
    y = x - (float)i;
    p = y *
        (s0 + y * (s1 + y * (s2 + y * (s3 + y * (s4 + y * (s5 + y * s6))))));
    q = one + y * (r1 + y * (r2 + y * (r3 + y * (r4 + y * (r5 + y * r6)))));
    r = half * y + p / q;
    z = one; /* lgamma(1+s) = log(s) + lgamma(s) */
    switch ((int)i) {
    case 7:
      z *= (y + 6.0F); /* FALLTHRU */
    case 6:
      z *= (y + 5.0F); /* FALLTHRU */
    case 5:
      z *= (y + 4.0F); /* FALLTHRU */
    case 4:
      z *= (y + 3.0F); /* FALLTHRU */
    case 3:
      z *= (y + 2.0F); /* FALLTHRU */
      r += __ieee754_logf(z);
      break;
    }
    /* 8.0 <= x < 2**58 */
  } else if (ix < IC(0x5c800000)) {
    t = __ieee754_logf(x);
    z = one / x;
    y = z * z;
    w = w0 + z * (w1 + y * (w2 + y * (w3 + y * (w4 + y * (w5 + y * w6)))));
    r = (x - half) * (t - one) + w;
  } else
    /* 2**58 <= x <= inf */
    r = x * (__ieee754_logf(x) - one);
  if (hx < 0)
    r = nadj - r;
  float temp_var_for_ext_2;
  temp_var_for_ext_2 = r;
  computeFSub((Addr)&temp_var_for_ext_2,
              {(Addr) &(temp_var_for_const_31 = 0.0),
               (Addr) &(temp_var_for_const_30 = 1.6309292987e-03)},
              "/home/shijia/Public/testprogram/e_lgammaf_r.c_e.c:311:22");
  callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_2;
}
