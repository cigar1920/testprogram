#include "../ScDebug/scdebug.h"
/* e_powf.c -- float version of e_pow.c.
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

#ifndef __have_fpu_pow

float __ieee754_powf(float x, float y) {
  float z, ax, z_h, z_l, p_h, p_l;
  float y1, t1, t2, r, s, t, u, v, w;
  int32_t i, j, k, yisint, n;
  int32_t hx, hy, ix, iy, is;

  static const float bp[] = {1.0, 1.5};
  static const float dp_h[] = {0.0, 5.84960938e-01}; /* 0x3f15c000 */
  static const float dp_l[] = {0.0, 1.56322085e-06}; /* 0x35d1cfdc */
  static const float zero = 0.0;
  static const float one = 1.0;
  static const float two = 2.0;
  static const float two24 = 16777216.0; /* 0x4b800000 */
  /* poly coefs for (3/2)*(log(x)-2s-2/3*s**3 */
  static const float L1 = 6.0000002384e-01; /* 0x3f19999a */
  static const float L2 = 4.2857143283e-01; /* 0x3edb6db7 */
  static const float L3 = 3.3333334327e-01; /* 0x3eaaaaab */
  static const float L4 = 2.7272811532e-01; /* 0x3e8ba305 */
  static const float L5 = 2.3066075146e-01; /* 0x3e6c3255 */
  static const float L6 = 2.0697501302e-01; /* 0x3e53f142 */
  static const float P1 = 1.6666667163e-01; /* 0x3e2aaaab */
  static const float P2 = (0.0 - 2.7777778450e-03);
  double temp_var_for_const_0, temp_var_for_const_1;
  ;                                         /* 0xbb360b61 */
  static const float P3 = 6.6137559770e-05; /* 0x388ab355 */
  static const float P4 = (0.0 - 1.6533901999e-06);
  double temp_var_for_const_2, temp_var_for_const_3;
  double temp_var_for_tac_0;
  computeDSub((Addr)&temp_var_for_tac_0,
              {(Addr) &(temp_var_for_const_1 = 0.0),
               (Addr) &(temp_var_for_const_0 = 2.7777778450e-03)},
              "/home/shijia/Public/testprogram/e_powf.c_e.c:45:32");
  ;                                              /* 0xb5ddea0e */
  static const float P5 = 4.1381369442e-08;      /* 0x3331bb4c */
  static const float lg2 = 6.9314718246e-01;     /* 0x3f317218 */
  static const float lg2_h = 6.93145752e-01;     /* 0x3f317200 */
  static const float lg2_l = 1.42860654e-06;     /* 0x35bfbe8c */
  static const float ovt = 4.2995665694e-08;     /* -(128-log2(ovfl+.5ulp)) */
  static const float cp = 9.6179670095e-01;      /* 0x3f76384f =2/(3ln2) */
  static const float cp_h = 9.6179199219e-01;    /* 0x3f763800 =head of cp */
  static const float cp_l = 4.7017383622e-06;    /* 0x369dc3a0 =tail of cp_h */
  static const float ivln2 = 1.4426950216e+00;   /* 0x3fb8aa3b =1/ln2 */
  static const float ivln2_h = 1.4426879883e+00; /* 0x3fb8aa00 =16b 1/ln2 */
  static const float ivln2_l = 7.0526075433e-06; /* 0x36eca570 =1/ln2 tail */

  GET_FLOAT_WORD(hx, x);
  GET_FLOAT_WORD(hy, y);
  ix = hx & IC(0x7fffffff);
  iy = hy & IC(0x7fffffff);

  /* y==zero: x**0 = 1 */
  if (FLT_UWORD_IS_ZERO(iy)) {
    /* unless x is signaling NaN */
    if (issignalingf(x))
      return __builtin_nanf("");
    return one;
  }

  /* x==+-1 */
  if (x == 1.0F) {
    float temp_var_for_ext_0;
    temp_var_for_ext_0 = one;
    computeFSub((Addr)&temp_var_for_ext_0,
                {(Addr) &(temp_var_for_const_3 = 0.0),
                 (Addr) &(temp_var_for_const_2 = 1.6533901999e-06)},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:74:24");
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  if (x == (0.0 - 1.0F); double temp_var_for_const_4, temp_var_for_const_5;
      &&isinf(y)) {
    float temp_var_for_ext_1;
    temp_var_for_ext_1 = one;
    computeFSub((Addr)&temp_var_for_ext_1,
                {(Addr) &(temp_var_for_const_5 = 0.0),
                 (Addr) &(temp_var_for_const_4 = 1.0F)},
                "/home/shijia/Public/testprogram/e_powf.c_e.c:82:24");
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }

  /* +-NaN return x+y */
  if (FLT_UWORD_IS_NAN(ix) || FLT_UWORD_IS_NAN(iy))
    return x + y;

  /* determine if y is an odd int when x < 0
   * yisint = 0   ... y is not an integer
   * yisint = 1   ... y is an odd int
   * yisint = 2   ... y is an even int
   */
  yisint = 0;
  if (hx < 0) {
    if (iy >= IC(0x4b800000))      /* |y| >= 2**24 */
      yisint = 2;                  /* even integer y */
    else if (iy >= IC(0x3f800000)) /* |y| >= 2**0 */
    {
      k = (iy >> IEEE754_FLOAT_SHIFT) - IEEE754_FLOAT_BIAS; /* exponent */
      j = iy >> (IEEE754_FLOAT_SHIFT - k);
      if ((j << (IEEE754_FLOAT_SHIFT - k)) == iy)
        yisint = 2 - (j & 1);
    }
  }

  /* special value of y */
  if (FLT_UWORD_IS_INFINITE(iy)) { /* y is +-inf */
    if (ix == IC(0x3f800000))
      return one;                 /* +-1**+-inf = 1 */
    else if (ix > IC(0x3f800000)) /* (|x|>1)**+-inf = inf,0 */
      return (hy >= 0) ? y : zero;
    else /* (|x|<1)**-,+inf = inf,0 */
      return (hy < 0) ? -y : zero;
  }
  if (iy == IC(0x3f800000)) { /* y is  +-1 */
    if (hy < 0)
      return one / x;
    else
      return x;
  }
  if (hy == IC(0x40000000))
    return x * x;             /* y is  2 */
  if (hy == IC(0x3f000000)) { /* y is  0.5 */
    if (hx >= 0)              /* x >= +0 */
      return __ieee754_sqrtf(x);
  }

  ax = __ieee754_fabsf(x);
  float temp_var_for_const_6;AssignF({(Addr)&ax},(Addr)&(temp_var_for_const_6=__ieee754_fabsf(getFVbyShadow<int>((Addr)&x)),"/home/shijia/Public/testprogram/e_powf.c_e.c:132:6");
  /* special value of x */
  if (FLT_UWORD_IS_INFINITE(ix) || FLT_UWORD_IS_ZERO(ix) ||
      ix == IC(0x3f800000)) {
    z = ax; /*x is +-0,+-inf,+-1 */
    if (hy < 0)
      z = one / z; /* z = (1/|x|) */
    if (hx < 0) {
      if (((ix - IC(0x3f800000)) | yisint) == 0) {
        z = (z - z) / (z - z); /* (-1)**non-int is NaN */
      } else if (yisint == 1)
        z = -z; /* (x<0)**odd = -(|x|**odd) */
    }
    return z;
  }

  /* (x<0)**(non-int) is NaN */
  if (((((uint32_t)hx >> 31) - 1) | yisint) == 0)
    return (x - x) / (x - x);

  /* |y| is huge */
  if (iy > IC(0x4d000000)) { /* if |y| > 2**27 */
    /* over/underflow if x is not close to one */
    if (ix < IC(0x3f7ffff8)) {
      if (hy < 0) {
        feraiseexcept(FE_OVERFLOW);
        return HUGE_VALF;
      }
      feraiseexcept(FE_UNDERFLOW);
      return 0;
    }
    if (ix > IC(0x3f800007)) {
      if (hy > 0) {
        feraiseexcept(FE_OVERFLOW);
        return HUGE_VALF;
      }
      feraiseexcept(FE_UNDERFLOW);
      return 0;
    }
    /* now |1-x| is tiny <= 2**-20, suffice to compute
       log(x) by x-x^2/2+x^3/3-x^4/4 */
    t = ax - 1; /* t has 20 trailing zeros */
    w = (t * t) * ((float)0.5 - t * ((float)0.333333333333 - t * (float)0.25));
    u = ivln2_h * t; /* ivln2_h has 16 sig. bits */
    v = t * ivln2_l - w * ivln2;
    t1 = u + v;
    GET_FLOAT_WORD(is, t1);
    SET_FLOAT_WORD(t1, is & UC(0xfffff000));
    t2 = v - (t1 - u);
  } else {
    float s2, s_h, s_l, t_h, t_l;

    /* Avoid internal underflow for tiny y.  The exact value
       of y does not matter if |y| <= 2**-32.  */
    if (iy < IC(0x2f800000)) {
      SET_FLOAT_WORD(y, (hy & UC(0x80000000)) | UC(0x2f800000));
    }
    n = 0;
    /* take care subnormal number */
    if (FLT_UWORD_IS_SUBNORMAL(ix)) {
      ax *= two24;
      n -= 24;
      GET_FLOAT_WORD(ix, ax);
    }
    n += ((ix) >> 23) - 0x7f;
    j = ix & IC(0x007fffff);
    /* determine interval */
    ix = j | IC(0x3f800000); /* normalize ix */
    if (j <= IC(0x1cc471))
      k = 0; /* |x|<sqrt(3/2) */
    else if (j < IC(0x5db3d7))
      k = 1; /* |x|<sqrt(3)   */
    else {
      k = 0;
      n += 1;
      ix -= IC(0x00800000);
    }
    SET_FLOAT_WORD(ax, ix);

    /* compute s = s_h+s_l = (x-1)/(x+1) or (x-1.5)/(x+1.5) */
    u = ax - bp[k]; /* bp[0]=1.0, bp[1]=1.5 */
    v = one / (ax + bp[k]);
    s = u * v;
    s_h = s;
    GET_FLOAT_WORD(is, s_h);
    SET_FLOAT_WORD(s_h, is & UC(0xfffff000));
    /* t_h=ax+bp[k] High */
    SET_FLOAT_WORD(t_h,
                   ((ix >> 1) | IC(0x20000000)) + IC(0x0040000) + (k << 21));
    t_l = ax - (t_h - bp[k]);
    s_l = v * ((u - s_h * t_h) - s_h * t_l);
    /* compute log(ax) */
    s2 = s * s;
    r = s2 * s2 *
        (L1 + s2 * (L2 + s2 * (L3 + s2 * (L4 + s2 * (L5 + s2 * L6)))));
    r += s_l * (s_h + s);
    s2 = s_h * s_h;
    t_h = 3.0f + s2 + r;
    GET_FLOAT_WORD(is, t_h);
    SET_FLOAT_WORD(t_h, is & UC(0xfffff000));
    t_l = r - ((t_h - 3.0f) - s2);
    /* u+v = s*(1+...) */
    u = s_h * t_h;
    v = s_l * t_h + t_l * s;
    /* 2/(3log2)*(s+...) */
    p_h = u + v;
    GET_FLOAT_WORD(is, p_h);
    SET_FLOAT_WORD(p_h, is & UC(0xfffff000));
    p_l = v - (p_h - u);
    z_h = cp_h * p_h; /* cp_h+cp_l = 2/(3*log2) */
    z_l = cp_l * p_h + p_l * cp + dp_l[k];
    /* log2(ax) = (s+..)*2/(3*log2) = n + dp_h + z_h + z_l */
    t = (float)n;
    t1 = (((z_h + z_l) + dp_h[k]) + t);
    GET_FLOAT_WORD(is, t1);
    SET_FLOAT_WORD(t1, is & UC(0xfffff000));
    t2 = z_l - (((t1 - t) - dp_h[k]) - z_h);
  }

  s = one;float temp_var_for_const_7;AssignF({(Addr)&s},(Addr)&(temp_var_for_const_7=one),"/home/shijia/Public/testprogram/e_powf.c_e.c:251:5"); /* s (sign of result -ve**odd) = -1 else = 1 */
  if (((((uint32_t)hx >> 31) - 1) | (yisint - 1)) == 0)
    s = -one; /* (-ve)**(odd int) */

  /* split up y into y1+y2 and compute (y1+y2)*(t1+t2) */
  GET_FLOAT_WORD(is, y);
  SET_FLOAT_WORD(y1, is & UC(0xfffff000));
  p_l = (y - y1) * t1 + y * t2;float temp_var_for_tac_1,temp_var_for_tac_2,temp_var_for_tac_3;computeFSub((Addr)&temp_var_for_tac_1,{(Addr)&y,(Addr)&y1},"/home/shijia/Public/testprogram/e_powf.c_e.c:258:18");computeFMul((Addr)&temp_var_for_tac_2,{(Addr)&temp_var_for_tac_1,(Addr)&t1},"/home/shijia/Public/testprogram/e_powf.c_e.c:258:27");computeFMul((Addr)&temp_var_for_tac_3,{(Addr)&y,(Addr)&t2},"/home/shijia/Public/testprogram/e_powf.c_e.c:258:23");computeFAdd((Addr)&p_l,{(Addr)&temp_var_for_tac_2,(Addr)&temp_var_for_tac_3},"/home/shijia/Public/testprogram/e_powf.c_e.c:258:7");
  p_h = y1 * t1;computeFMul((Addr)&p_h,{(Addr)&y1,(Addr)&t1},"/home/shijia/Public/testprogram/e_powf.c_e.c:259:7");
  z = p_l + p_h;computeFAdd((Addr)&z,{(Addr)&p_l,(Addr)&p_h},"/home/shijia/Public/testprogram/e_powf.c_e.c:260:5");
  GET_FLOAT_WORD(j, z);
  i = j & IC(0x7fffffff);
  if (j > 0) {
    if (i > FLT_UWORD_EXP_MAX) {
      feraiseexcept(FE_OVERFLOW);
      return copysignf(HUGE_VALF, s);
    }
    if (i == FLT_UWORD_EXP_MAX)
      if (p_l + ovt > z - p_h) {
        feraiseexcept(FE_OVERFLOW);
        return copysignf(HUGE_VALF, s);
      }
  } else {
    if (i > FLT_UWORD_EXP_MIN) {
      feraiseexcept(FE_UNDERFLOW);
      return copysignf(0.0f, s);
    }
    if (i == FLT_UWORD_EXP_MIN)
      if (p_l <= z - p_h) {
        feraiseexcept(FE_UNDERFLOW);
        return copysignf(0.0f, s);
      }
  }
  /*
   * compute 2**(p_h+p_l)
   */
  k = (i >> 23) - 0x7f;

  n = 0;
  if (i > IC(0x3f000000)) { /* if |z| > 0.5, set n = [z+0.5] */
    n = j + (IC(0x00800000) >> (k + 1));
    k = ((n & IC(0x7fffffff)) >> 23) - 0x7f; /* new k for n */
    SET_FLOAT_WORD(t, n & ~(UC(0x007fffff) >> k));
    n = ((n & IC(0x007fffff)) | IC(0x00800000)) >> (23 - k);
    if (j < 0)
      n = -n;
    p_h -= t;
  }
  t = p_l + p_h;computeFAdd((Addr)&t,{(Addr)&p_l,(Addr)&p_h},"/home/shijia/Public/testprogram/e_powf.c_e.c:299:5");
  GET_FLOAT_WORD(is, t);
  SET_FLOAT_WORD(t, is & UC(0xfffff000));
  u = t * lg2_h;float temp_var_for_const_8;computeFMul((Addr)&u,{(Addr)&t,(Addr)&(temp_var_for_const_8=lg2_h)},"/home/shijia/Public/testprogram/e_powf.c_e.c:302:5");
  v = (p_l - (t - p_h)) * lg2 + t * lg2_l;float temp_var_for_const_9,temp_var_for_const_10;float temp_var_for_tac_4,temp_var_for_tac_5,temp_var_for_tac_6,temp_var_for_tac_7;computeFSub((Addr)&temp_var_for_tac_4,{(Addr)&t,(Addr)&p_h},"/home/shijia/Public/testprogram/e_powf.c_e.c:303:12");computeFSub((Addr)&temp_var_for_tac_5,{(Addr)&p_l,(Addr)&temp_var_for_tac_4},"/home/shijia/Public/testprogram/e_powf.c_e.c:303:25");computeFMul((Addr)&temp_var_for_tac_6,{(Addr)&temp_var_for_tac_5,(Addr)&(temp_var_for_const_9=lg2)},"/home/shijia/Public/testprogram/e_powf.c_e.c:303:35");computeFMul((Addr)&temp_var_for_tac_7,{(Addr)&t,(Addr)&(temp_var_for_const_10=lg2_l)},"/home/shijia/Public/testprogram/e_powf.c_e.c:303:31");computeFAdd((Addr)&v,{(Addr)&temp_var_for_tac_6,(Addr)&temp_var_for_tac_7},"/home/shijia/Public/testprogram/e_powf.c_e.c:303:5");
  z = u + v;computeFAdd((Addr)&z,{(Addr)&u,(Addr)&v},"/home/shijia/Public/testprogram/e_powf.c_e.c:304:5");
  w = v - (z - u);float temp_var_for_tac_8;computeFSub((Addr)&temp_var_for_tac_8,{(Addr)&z,(Addr)&u},"/home/shijia/Public/testprogram/e_powf.c_e.c:305:9");computeFSub((Addr)&w,{(Addr)&v,(Addr)&temp_var_for_tac_8},"/home/shijia/Public/testprogram/e_powf.c_e.c:305:5");
  t = z * z;computeFMul((Addr)&t,{(Addr)&z,(Addr)&z},"/home/shijia/Public/testprogram/e_powf.c_e.c:306:5");
  t1 = z - t * (P1 + t * (P2 + t * (P3 + t * (P4 + t * P5))));float temp_var_for_const_11,temp_var_for_const_12,temp_var_for_const_13,temp_var_for_const_14,temp_var_for_const_15;float temp_var_for_tac_9,temp_var_for_tac_10,temp_var_for_tac_11,temp_var_for_tac_12,temp_var_for_tac_13,temp_var_for_tac_14,temp_var_for_tac_15,temp_var_for_tac_16,temp_var_for_tac_17;computeFMul((Addr)&temp_var_for_tac_9,{(Addr)&t,(Addr)&(temp_var_for_const_11=P5)},"/home/shijia/Public/testprogram/e_powf.c_e.c:307:50");computeFAdd((Addr)&temp_var_for_tac_10,{(Addr)&(temp_var_for_const_12=P4),(Addr)&temp_var_for_tac_9},"/home/shijia/Public/testprogram/e_powf.c_e.c:307:44");computeFMul((Addr)&temp_var_for_tac_11,{(Addr)&t,(Addr)&temp_var_for_tac_10},"/home/shijia/Public/testprogram/e_powf.c_e.c:307:40");computeFAdd((Addr)&temp_var_for_tac_12,{(Addr)&(temp_var_for_const_13=P3),(Addr)&temp_var_for_tac_11},"/home/shijia/Public/testprogram/e_powf.c_e.c:307:34");computeFMul((Addr)&temp_var_for_tac_13,{(Addr)&t,(Addr)&temp_var_for_tac_12},"/home/shijia/Public/testprogram/e_powf.c_e.c:307:30");computeFAdd((Addr)&temp_var_for_tac_14,{(Addr)&(temp_var_for_const_14=P2),(Addr)&temp_var_for_tac_13},"/home/shijia/Public/testprogram/e_powf.c_e.c:307:24");computeFMul((Addr)&temp_var_for_tac_15,{(Addr)&t,(Addr)&temp_var_for_tac_14},"/home/shijia/Public/testprogram/e_powf.c_e.c:307:20");computeFAdd((Addr)&temp_var_for_tac_16,{(Addr)&(temp_var_for_const_15=P1),(Addr)&temp_var_for_tac_15},"/home/shijia/Public/testprogram/e_powf.c_e.c:307:14");computeFMul((Addr)&temp_var_for_tac_17,{(Addr)&t,(Addr)&temp_var_for_tac_16},"/home/shijia/Public/testprogram/e_powf.c_e.c:307:10");computeFSub((Addr)&t1,{(Addr)&z,(Addr)&temp_var_for_tac_17},"/home/shijia/Public/testprogram/e_powf.c_e.c:307:6");
  r = (z * t1) / (t1 - two) - (w + z * w);float temp_var_for_const_16;float temp_var_for_tac_18,temp_var_for_tac_19,temp_var_for_tac_20,temp_var_for_tac_21,temp_var_for_tac_22;computeFMul((Addr)&temp_var_for_tac_18,{(Addr)&z,(Addr)&t1},"/home/shijia/Public/testprogram/e_powf.c_e.c:308:22");computeFSub((Addr)&temp_var_for_tac_19,{(Addr)&t1,(Addr)&(temp_var_for_const_16=two)},"/home/shijia/Public/testprogram/e_powf.c_e.c:308:16");computeFDiv((Addr)&temp_var_for_tac_20,{(Addr)&temp_var_for_tac_18,(Addr)&temp_var_for_tac_19},"/home/shijia/Public/testprogram/e_powf.c_e.c:308:38");computeFMul((Addr)&temp_var_for_tac_21,{(Addr)&z,(Addr)&w},"/home/shijia/Public/testprogram/e_powf.c_e.c:308:34");computeFAdd((Addr)&temp_var_for_tac_22,{(Addr)&w,(Addr)&temp_var_for_tac_21},"/home/shijia/Public/testprogram/e_powf.c_e.c:308:29");computeFSub((Addr)&r,{(Addr)&temp_var_for_tac_20,(Addr)&temp_var_for_tac_22},"/home/shijia/Public/testprogram/e_powf.c_e.c:308:5");
  float temp_var_for_ext_2;
  temp_var_for_ext_2 = one - (r - z);float temp_var_for_const_17;float temp_var_for_tac_23;computeFSub((Addr)&temp_var_for_tac_23,{(Addr)&r,(Addr)&z},"/home/shijia/Public/testprogram/e_powf.c_e.c:310:28");computeFSub((Addr)&temp_var_for_ext_2,{(Addr)&(temp_var_for_const_17=one),(Addr)&temp_var_for_tac_23},"/home/shijia/Public/testprogram/e_powf.c_e.c:310:22"); // z
  /*(w)(z)(w)(two)(t1)(t1)(z)(two)(t1)(t1)(z)(t1)(z)(two)(t1)(w)(z)(w)(w)(z)(z)(r)(one)*/
  z = temp_var_for_ext_2;AssignF({(Addr)&z},(Addr)&temp_var_for_ext_2,"/home/shijia/Public/testprogram/e_powf.c_e.c:312:5");
  GET_FLOAT_WORD(j, z);
  j += (n << 23);
  if ((j >> 23) <= 0) {
    z = __ieee754_scalbnf(z, (int)n); /* subnormal output */
  } else {
    SET_FLOAT_WORD(z, j);
  }
  float temp_var_for_ext_3;
  temp_var_for_ext_3 = s * z;computeFMul((Addr)&temp_var_for_ext_3,{(Addr)&s,(Addr)&z},"/home/shijia/Public/testprogram/e_powf.c_e.c:321:22");
  callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_3;
}

#endif

/* wrapper powf */
float __powf(float x, float y) {
  float z = __ieee754_powf(x, y);

  if (!isfinite(z)) {
    if (_LIB_VERSION != _IEEE_) {
      if (isnan(x)) {
        if (y == 0.0f)
          /* pow(NaN,0.0) */
          return __kernel_standard_f(x, y, z, KMATHERRF_POW_NAN);
      } else if (isfinite(x) && isfinite(y)) {
        if (isnan(z)) {
          /* pow neg**non-int */
          return __kernel_standard_f(x, y, z, KMATHERRF_POW_NONINT);
        } else if (x == 0.0f && y < 0.0f) {
          if (signbit(x) && signbit(z))
            /* pow(-0.0,negative) */
            return __kernel_standard_f(x, y, z, KMATHERRF_POW_MINUS);
          else
            /* pow(+0.0,negative) */
            return __kernel_standard_f(x, y, z, KMATHERRF_POW_ZEROMINUS);
        } else {
          /* pow overflow */
          return __kernel_standard_f(x, y, z, KMATHERRF_POW_OVERFLOW);
        }
      }
    }
  } else {
    if
  }
  (z == 0.0f && isfinite(x) && isfinite(y) && _LIB_VERSION != _IEEE_) {
    if (x == 0.0f) {
      if (y == 0.0f)
        /* pow(0.0,0.0) */
        return __kernel_standard_f(x, y, z, KMATHERRF_POW_ZERO);
    } else {
      /* pow underflow */
      return __kernel_standard_f(x, y, z, KMATHERRF_POW_UNDERFLOW);
    }
  }

  return z;
}

__typeof(__powf) powf __attribute__((weak, alias("__powf")));
