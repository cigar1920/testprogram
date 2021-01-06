#include "../ScDebug/scdebug.h"
/*
 * ====================================================
 * Copyright (C) 2004 by Sun Microsystems, Inc. All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 */

/* __ieee754_pow(x,y) return x**y
 *
 *		      n
 * Method:  Let x =  2   * (1+f)
 *	1. Compute and return log2(x) in two pieces:
 *		log2(x) = w1 + w2,
 *	   where w1 has 53-24 = 29 bit trailing zeros.
 *	2. Perform y*log2(x) = n+y' by simulating multi-precision
 *	   arithmetic, where |y'|<=0.5.
 *	3. Return x**y = 2**n*exp(y'*log2)
 *
 * Special cases:
 *	1.  (anything) ** 0  is 1
 *	2.  (anything) ** 1  is itself
 *	3a. (anything) ** NAN is NAN except
 *	3b. +1         ** NAN is 1
 *	4.  NAN ** (anything except 0) is NAN
 *	5.  +-(|x| > 1) **  +INF is +INF
 *	6.  +-(|x| > 1) **  -INF is +0
 *	7.  +-(|x| < 1) **  +INF is +0
 *	8.  +-(|x| < 1) **  -INF is +INF
 *	9.  +-1         ** +-INF is 1
 *	10. +0 ** (+anything except 0, NAN)               is +0
 *	11. -0 ** (+anything except 0, NAN, odd integer)  is +0
 *	12. +0 ** (-anything except 0, NAN)               is +INF
 *	13. -0 ** (-anything except 0, NAN, odd integer)  is +INF
 *	14. -0 ** (odd integer) = -( +0 ** (odd integer) )
 *	15. +INF ** (+anything except 0,NAN) is +INF
 *	16. +INF ** (-anything except 0,NAN) is +0
 *	17. -INF ** (anything)  = -0 ** (-anything)
 *	18. (-anything) ** (integer) is (-1)**(integer)*(+anything**integer)
 *	19. (-anything except 0 and inf) ** (non-integer) is NAN
 *
 * Accuracy:
 *	pow(x,y) returns x**y nearly rounded. In particular
 *			pow(integer,integer)
 *	always returns the correct integer provided it is
 *	representable.
 *
 * Constants :
 * The hexadecimal values are the intended ones for the following
 * constants. The decimal values may be used, provided that the
 * compiler will convert from decimal to binary accurately enough
 * to produce the hexadecimal values shown.
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#include "s_issig.c"
#endif

double __ieee754_powS(double x, double y)
{
  double z, ax, z_h, z_l, p_h, p_l;
  double y1, t1, t2, r, s, t, u, v, w;
  int32_t i, j, k, yisint, n;
  int32_t hx, hy, ix, iy;
  uint32_t lx, ly;

  static const double bp[] = {1.0, 1.5};
  static const double dp_h[] = {0.0, 5.84962487220764160156e-01}; /* 0x3FE2B803, 0x40000000 */
  static const double dp_l[] = {0.0, 1.35003920212974897128e-08}; /* 0x3E4CFDEB, 0x43CFD006 */
  static const double zero = 0.0;
  static const double one = 1.0;
  static const double two = 2.0;
  static const double two53 = 9007199254740992.0; /* 0x43400000, 0x00000000 */
  /* poly coefs for (3/2)*(log(x)-2s-2/3*s**3 */
  static const double L1 = 5.99999999999994648725e-01;      /* 0x3FE33333, 0x33333303 */
  static const double L2 = 4.28571428578550184252e-01;      /* 0x3FDB6DB6, 0xDB6FABFF */
  static const double L3 = 3.33333329818377432918e-01;      /* 0x3FD55555, 0x518F264D */
  static const double L4 = 2.72728123808534006489e-01;      /* 0x3FD17460, 0xA91D4101 */
  static const double L5 = 2.30660745775561754067e-01;      /* 0x3FCD864A, 0x93C9DB65 */
  static const double L6 = 2.06975017800338417784e-01;      /* 0x3FCA7E28, 0x4A454EEF */
  static const double P1 = 1.66666666666666019037e-01;      /* 0x3FC55555, 0x5555553E */
  static const double P2 = -2.77777777770155933842e-03;     /* 0xBF66C16C, 0x16BEBD93 */
  static const double P3 = 6.61375632143793436117e-05;      /* 0x3F11566A, 0xAF25DE2C */
  static const double P4 = -1.65339022054652515390e-06;     /* 0xBEBBBD41, 0xC5D26BF1 */
  static const double P5 = 4.13813679705723846039e-08;      /* 0x3E663769, 0x72BEA4D0 */
  static const double lg2 = 6.93147180559945286227e-01;     /* 0x3FE62E42, 0xFEFA39EF */
  static const double lg2_h = 6.93147182464599609375e-01;   /* 0x3FE62E43, 0x00000000 */
  static const double lg2_l = -1.90465429995776804525e-09;  /* 0xBE205C61, 0x0CA86C39 */
  static const double ovt = 8.0085662595372944372e-0017;    /* -(1024-log2(ovfl+.5ulp)) */
  static const double cp = 9.61796693925975554329e-01;      /* 0x3FEEC709, 0xDC3A03FD =2/(3ln2) */
  static const double cp_h = 9.61796700954437255859e-01;    /* 0x3FEEC709, 0xE0000000 =(float)cp */
  static const double cp_l = -7.02846165095275826516e-09;   /* 0xBE3E2FE0, 0x145B01F5 =tail of cp_h */
  static const double ivln2 = 1.44269504088896338700e+00;   /* 0x3FF71547, 0x652B82FE =1/ln2 */
  static const double ivln2_h = 1.44269502162933349609e+00; /* 0x3FF71547, 0x60000000 =24b 1/ln2 */
  static const double ivln2_l = 1.92596299112661746887e-08; /* 0x3E54AE0B, 0xF85DDF44 =1/ln2 tail */

  GET_DOUBLE_WORDS(hx, lx, x);
  GET_DOUBLE_WORDS(hy, ly, y);
  ix = hx & IC(0x7fffffff);
  iy = hy & IC(0x7fffffff);

  /* y==zero: x**0 = 1 */
  if ((iy | ly) == 0)
  {
    /* unless x is signaling NaN */
    if (issignaling(x))
    {
      double temp_var_for_ext_0;
      double temp_var_for_const_8;
      double temp_var_for_callexp_0;

      temp_var_for_callexp_0 = __builtin_nan("");
      temp_var_for_ext_0 = temp_var_for_callexp_0;
      AssignD({(Addr)&temp_var_for_ext_0},
              (Addr) & (temp_var_for_const_8 = temp_var_for_callexp_0),
              "/home/shijia/Public/testprogram/e_pow.c_e.c:134:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_0;
    }

    double temp_var_for_ext_1;
    double temp_var_for_const_9;
    temp_var_for_ext_1 = one;
    AssignD({(Addr)&temp_var_for_ext_1}, (Addr) & (temp_var_for_const_9 = one),
            "/home/shijia/Public/testprogram/e_pow.c_e.c:142:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }

  /* x|y==NaN return NaN unless x==1 then return 1 */
  if (ix > IC(0x7ff00000) || ((ix == IC(0x7ff00000)) && (lx != 0)) ||
      iy > IC(0x7ff00000) || ((iy == IC(0x7ff00000)) && (ly != 0)))
  {
    if (((ix - IC(0x3ff00000)) | lx) == 0 && !(hx & UC(0x80000000)))
    {
      double temp_var_for_ext_2;
      double temp_var_for_const_10;
      temp_var_for_ext_2 = one;
      AssignD({(Addr)&temp_var_for_ext_2},
              (Addr) & (temp_var_for_const_10 = one),
              "/home/shijia/Public/testprogram/e_pow.c_e.c:153:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_2;
    }

    else
    {
      double temp_var_for_ext_3;
      double temp_var_for_const_11;
      double temp_var_for_callexp_1;

      temp_var_for_callexp_1 = __builtin_nan("");
      temp_var_for_ext_3 = temp_var_for_callexp_1;
      AssignD({(Addr)&temp_var_for_ext_3},
              (Addr) & (temp_var_for_const_11 = temp_var_for_callexp_1),
              "/home/shijia/Public/testprogram/e_pow.c_e.c:162:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_3;
    }
  }

  /* determine if y is an odd int when x < 0
   * yisint = 0   ... y is not an integer
   * yisint = 1   ... y is an odd int
   * yisint = 2   ... y is an even int
   */
  yisint = 0;
  if (hx < 0)
  {
    if (iy >= IC(0x43400000))
    {
      yisint = 2;
    }
    /* even integer y */
    else
    {
      if (iy >= IC(0x3ff00000))
      {
        k = (iy >> IEEE754_DOUBLE_SHIFT) - IEEE754_DOUBLE_BIAS; /* exponent */
        if (k > IEEE754_DOUBLE_SHIFT)
        {
          j = ly >> (52 - k);
          if ((j << (52 - k)) == (int32_t)ly)
          {
            yisint = 2 - (j & 1);
          }
        }
        else
        {
          if (ly == 0)
          {
            j = iy >> (IEEE754_DOUBLE_SHIFT - k);
            if ((j << (IEEE754_DOUBLE_SHIFT - k)) == iy)
            {
              yisint = 2 - (j & 1);
            }
          }
        }
      }
    }
  }

  /* special value of y */
  if (ly == 0)
  {
    if (iy == IC(0x7ff00000))
    { /* y is +-inf */
      if (((ix - IC(0x3ff00000)) | lx) == 0)
      {
        double temp_var_for_ext_4;
        double temp_var_for_const_12;
        temp_var_for_ext_4 = one;
        AssignD({(Addr)&temp_var_for_ext_4},
                (Addr) & (temp_var_for_const_12 = one),
                "/home/shijia/Public/testprogram/e_pow.c_e.c:207:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_4;
      }
      /* +-1**+-inf = 1 */
      else
      {
        if (ix >= IC(0x3ff00000)) /* (|x|>1)**+-inf = inf,0 */
        {
          double temp_var_for_ext_5;
          double temp_var_for_const_13;
          temp_var_for_ext_5 = (hy >= 0) ? y : zero;
          AssignD({(Addr)&temp_var_for_ext_5},
                  (Addr) & (temp_var_for_const_13 = (hy >= 0) ? y : zero),
                  "/home/shijia/Public/testprogram/e_pow.c_e.c:218:30");
          ;
          callExpStack.push(
              getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
          callExp++; /*identify the function is  add move tmpShadow*/
          return temp_var_for_ext_5;
        }

        else /* (|x|<1)**-,+inf = inf,0 */
        {
          double temp_var_for_ext_6;
          temp_var_for_ext_6 = (hy < 0) ? -y : zero;
          callExpStack.push(
              getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
          callExp++; /*identify the function is  add move tmpShadow*/
          return temp_var_for_ext_6;
        }
      }
    }
    if (iy == IC(0x3ff00000))
    { /* y is  +-1 */
      if (hy < 0)
      {
        double temp_var_for_ext_7;
        double temp_var_for_tac_4;
        double temp_var_for_const_14;
        temp_var_for_tac_4 = one / x;

        temp_var_for_ext_7 = temp_var_for_tac_4;
        computeDDiv((Addr)&temp_var_for_tac_4,
                    {(Addr) & (temp_var_for_const_14 = one), (Addr)&x},
                    "/home/shijia/Public/testprogram/e_pow.c_e.c:239:34");
        AssignD({(Addr)&temp_var_for_ext_7}, (Addr)&temp_var_for_tac_4,
                "/home/shijia/Public/testprogram/e_pow.c_e.c:239:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_7;
      }

      else
      {
        double temp_var_for_ext_8;
        temp_var_for_ext_8 = x;
        AssignD({(Addr)&temp_var_for_ext_8}, (Addr)&x,
                "/home/shijia/Public/testprogram/e_pow.c_e.c:248:28");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_8;
      }
    }
    if (hy == IC(0x40000000))
    {
      double temp_var_for_ext_9;
      double temp_var_for_tac_5;
      temp_var_for_tac_5 = x * x;

      temp_var_for_ext_9 = temp_var_for_tac_5;
      computeDMul((Addr)&temp_var_for_tac_5, {(Addr)&x, (Addr)&x},
                  "/home/shijia/Public/testprogram/e_pow.c_e.c:257:30");
      AssignD({(Addr)&temp_var_for_ext_9}, (Addr)&temp_var_for_tac_5,
              "/home/shijia/Public/testprogram/e_pow.c_e.c:257:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_9;
    }
    /* y is  2 */
    if (hy == IC(0x3fe00000))
    {              /* y is  0.5 */
      if (hx >= 0) /* x >= +0 */
      {
        double temp_var_for_ext_10;
        double temp_var_for_const_15;
        double temp_var_for_callexp_2;

        temp_var_for_callexp_2 = __ieee754_sqrt(x);
        temp_var_for_ext_10 = temp_var_for_callexp_2;
        AssignD({(Addr)&temp_var_for_ext_10},
                (Addr) & (temp_var_for_const_15 = temp_var_for_callexp_2),
                "/home/shijia/Public/testprogram/e_pow.c_e.c:268:29");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_10", (Addr)&temp_var_for_ext_10));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_10;
      }
    }
  }

  double temp_var_for_const_16;
  double temp_var_for_callexp_3;

  temp_var_for_callexp_3 = fabs(x);
  ax = temp_var_for_callexp_3;
  AssignD({(Addr)&ax}, (Addr) & (temp_var_for_const_16 = temp_var_for_callexp_3),
          "/home/shijia/Public/testprogram/e_pow.c_e.c:277:6");
  ;
  /* special value of x */
  if (lx == 0)
  {
    if (ix == IC(0x7ff00000) || ix == 0 || ix == IC(0x3ff00000))
    {
      z = ax;
      AssignD({(Addr)&z}, (Addr)&ax,
              "/home/shijia/Public/testprogram/e_pow.c_e.c:281:9");
      ; /*x is +-0,+-inf,+-1 */
      if (hy < 0)
      {
        double temp_var_for_ext_11;
        double temp_var_for_tac_6;
        double temp_var_for_const_17;
        temp_var_for_tac_6 = one / z;

        temp_var_for_ext_11 = temp_var_for_tac_6;
        computeDDiv((Addr)&temp_var_for_tac_6,
                    {(Addr) & (temp_var_for_const_17 = one), (Addr)&z},
                    "/home/shijia/Public/testprogram/e_pow.c_e.c:284:35");
        AssignD({(Addr)&temp_var_for_ext_11}, (Addr)&temp_var_for_tac_6,
                "/home/shijia/Public/testprogram/e_pow.c_e.c:284:29");
        ; // z
        /*(z)(one)*/
        z = temp_var_for_ext_11;
        AssignD({(Addr)&z}, (Addr)&temp_var_for_ext_11,
                "/home/shijia/Public/testprogram/e_pow.c_e.c:286:11");
        ;
      }
      /* z = (1/|x|) */
      if (hx < 0)
      {
        if (((ix - IC(0x3ff00000)) | yisint) == 0)
        {
          double temp_var_for_ext_12;
          double temp_var_for_tac_7, temp_var_for_tac_8, temp_var_for_tac_9;
          temp_var_for_tac_7 = z - z;

          temp_var_for_tac_8 = z - z;

          temp_var_for_tac_9 = temp_var_for_tac_7 / temp_var_for_tac_8;

          temp_var_for_ext_12 = temp_var_for_tac_9;
          computeDSub((Addr)&temp_var_for_tac_7, {(Addr)&z, (Addr)&z},
                      "/home/shijia/Public/testprogram/e_pow.c_e.c:292:36");
          computeDSub((Addr)&temp_var_for_tac_8, {(Addr)&z, (Addr)&z},
                      "/home/shijia/Public/testprogram/e_pow.c_e.c:292:46");
          computeDDiv((Addr)&temp_var_for_tac_9,
                      {(Addr)&temp_var_for_tac_7, (Addr)&temp_var_for_tac_8},
                      "/home/shijia/Public/testprogram/e_pow.c_e.c:292:41");
          AssignD({(Addr)&temp_var_for_ext_12}, (Addr)&temp_var_for_tac_9,
                  "/home/shijia/Public/testprogram/e_pow.c_e.c:292:31");
          ; // z
          /*(z)(one)(z)(z)(z)(z)*/
          z = temp_var_for_ext_12;
          AssignD({(Addr)&z}, (Addr)&temp_var_for_ext_12,
                  "/home/shijia/Public/testprogram/e_pow.c_e.c:294:13");
          ; /* (-1)**non-int is NaN */
        }
        else
        {
          if (yisint == 1)
          {
            double temp_var_for_ext_13;
            double temp_var_for_tac_10;
            double temp_var_for_const_18;
            temp_var_for_tac_10 = 0.0 - z;

            temp_var_for_ext_13 = temp_var_for_tac_10;
            computeDSub((Addr)&temp_var_for_tac_10,
                        {(Addr) & (temp_var_for_const_18 = 0.0), (Addr)&z},
                        "/home/shijia/Public/testprogram/e_pow.c_e.c:298:40");
            AssignD({(Addr)&temp_var_for_ext_13}, (Addr)&temp_var_for_tac_10,
                    "/home/shijia/Public/testprogram/e_pow.c_e.c:298:33");
            ; // z
            /*(z)(z)(z)(z)(z)(z)(z)(z)(z)(z)*/
            z = temp_var_for_ext_13;
            AssignD({(Addr)&z}, (Addr)&temp_var_for_ext_13,
                    "/home/shijia/Public/testprogram/e_pow.c_e.c:300:15");
            ;
          }
        }
        /* (x<0)**odd = -(|x|**odd) */
      }
      double temp_var_for_ext_14;
      temp_var_for_ext_14 = z;
      AssignD({(Addr)&temp_var_for_ext_14}, (Addr)&z,
              "/home/shijia/Public/testprogram/e_pow.c_e.c:306:27");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_14", (Addr)&temp_var_for_ext_14));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_14;
    }
  }

  /* (x<0)**(non-int) is NaN */
  if (((((uint32_t)hx >> 31) - 1) | yisint) == 0)
  {
    double temp_var_for_ext_15;
    double temp_var_for_tac_11, temp_var_for_tac_12, temp_var_for_tac_13;
    temp_var_for_tac_11 = x - x;

    temp_var_for_tac_12 = x - x;

    temp_var_for_tac_13 = temp_var_for_tac_11 / temp_var_for_tac_12;

    temp_var_for_ext_15 = temp_var_for_tac_13;
    computeDSub((Addr)&temp_var_for_tac_11, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:317:30");
    computeDSub((Addr)&temp_var_for_tac_12, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:317:40");
    computeDDiv((Addr)&temp_var_for_tac_13,
                {(Addr)&temp_var_for_tac_11, (Addr)&temp_var_for_tac_12},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:317:35");
    AssignD({(Addr)&temp_var_for_ext_15}, (Addr)&temp_var_for_tac_13,
            "/home/shijia/Public/testprogram/e_pow.c_e.c:317:25");
    ;
    callExpStack.push(
        getReal("temp_var_for_ext_15", (Addr)&temp_var_for_ext_15));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_15;
  }

  /* |y| is huge */
  if (iy > IC(0x41e00000))
  { /* if |y| > 2**31 */
    if (iy > IC(0x43f00000))
    { /* if |y| > 2**64, must o/uflow */
      if (ix <= IC(0x3fefffff))
      {
        if (hy < 0)
        {
          feraiseexcept(FE_OVERFLOW);
          double temp_var_for_ext_16;
          double temp_var_for_const_19;
          double temp_var_for_callexp_4;

          temp_var_for_callexp_4 = __builtin_huge_val();
          temp_var_for_ext_16 = temp_var_for_callexp_4;
          AssignD({(Addr)&temp_var_for_ext_16},
                  (Addr) & (temp_var_for_const_19 = temp_var_for_callexp_4),
                  "/home/shijia/Public/testprogram/e_pow.c_e.c:331:31");
          ;
          callExpStack.push(
              getReal("temp_var_for_ext_16", (Addr)&temp_var_for_ext_16));
          callExp++; /*identify the function is  add move tmpShadow*/
          return temp_var_for_ext_16;
        }
        feraiseexcept(FE_UNDERFLOW);
        double temp_var_for_ext_17;
        double temp_var_for_const_20;
        temp_var_for_ext_17 = 0;
        AssignD({(Addr)&temp_var_for_ext_17},
                (Addr) & (temp_var_for_const_20 = 0),
                "/home/shijia/Public/testprogram/e_pow.c_e.c:339:29");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_17", (Addr)&temp_var_for_ext_17));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_17;
      }
      if (ix >= IC(0x3ff00000))
      {
        if (hy > 0)
        {
          feraiseexcept(FE_OVERFLOW);
          double temp_var_for_ext_18;
          double temp_var_for_const_21;
          double temp_var_for_callexp_5;

          temp_var_for_callexp_5 = __builtin_huge_val();
          temp_var_for_ext_18 = temp_var_for_callexp_5;
          AssignD({(Addr)&temp_var_for_ext_18},
                  (Addr) & (temp_var_for_const_21 = temp_var_for_callexp_5),
                  "/home/shijia/Public/testprogram/e_pow.c_e.c:349:31");
          ;
          callExpStack.push(
              getReal("temp_var_for_ext_18", (Addr)&temp_var_for_ext_18));
          callExp++; /*identify the function is  add move tmpShadow*/
          return temp_var_for_ext_18;
        }
        feraiseexcept(FE_UNDERFLOW);
        double temp_var_for_ext_19;
        double temp_var_for_const_22;
        temp_var_for_ext_19 = 0;
        AssignD({(Addr)&temp_var_for_ext_19},
                (Addr) & (temp_var_for_const_22 = 0),
                "/home/shijia/Public/testprogram/e_pow.c_e.c:357:29");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_19", (Addr)&temp_var_for_ext_19));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_19;
      }
    }
    /* over/underflow if x is not close to one */
    if (ix < IC(0x3fefffff))
    {
      if (hy < 0)
      {
        feraiseexcept(FE_OVERFLOW);
        double temp_var_for_ext_20;
        double temp_var_for_const_23;
        double temp_var_for_callexp_6;

        temp_var_for_callexp_6 = __builtin_huge_val();
        temp_var_for_ext_20 = temp_var_for_callexp_6;
        AssignD({(Addr)&temp_var_for_ext_20},
                (Addr) & (temp_var_for_const_23 = temp_var_for_callexp_6),
                "/home/shijia/Public/testprogram/e_pow.c_e.c:369:29");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_20", (Addr)&temp_var_for_ext_20));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_20;
      }
      feraiseexcept(FE_UNDERFLOW);
      double temp_var_for_ext_21;
      double temp_var_for_const_24;
      temp_var_for_ext_21 = 0;
      AssignD({(Addr)&temp_var_for_ext_21}, (Addr) & (temp_var_for_const_24 = 0),
              "/home/shijia/Public/testprogram/e_pow.c_e.c:377:27");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_21", (Addr)&temp_var_for_ext_21));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_21;
    }
    if (ix > IC(0x3ff00000))
    {
      if (hy > 0)
      {
        feraiseexcept(FE_OVERFLOW);
        double temp_var_for_ext_22;
        double temp_var_for_const_25;
        double temp_var_for_callexp_7;

        temp_var_for_callexp_7 = __builtin_huge_val();
        temp_var_for_ext_22 = temp_var_for_callexp_7;
        AssignD({(Addr)&temp_var_for_ext_22},
                (Addr) & (temp_var_for_const_25 = temp_var_for_callexp_7),
                "/home/shijia/Public/testprogram/e_pow.c_e.c:387:29");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_22", (Addr)&temp_var_for_ext_22));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_22;
      }
      feraiseexcept(FE_UNDERFLOW);
      double temp_var_for_ext_23;
      double temp_var_for_const_26;
      temp_var_for_ext_23 = 0;
      AssignD({(Addr)&temp_var_for_ext_23}, (Addr) & (temp_var_for_const_26 = 0),
              "/home/shijia/Public/testprogram/e_pow.c_e.c:395:27");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_23", (Addr)&temp_var_for_ext_23));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_23;
    }
    /* now |1-x| is tiny <= 2**-20, suffice to compute
       log(x) by x-x^2/2+x^3/3-x^4/4 */
    double temp_var_for_tac_14;
    double temp_var_for_const_27;
    temp_var_for_tac_14 = ax - 1;

    t = temp_var_for_tac_14;
    computeDSub((Addr)&temp_var_for_tac_14,
                {(Addr)&ax, (Addr) & (temp_var_for_const_27 = 1)},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:403:12");
    AssignD({(Addr)&t}, (Addr)&temp_var_for_tac_14,
            "/home/shijia/Public/testprogram/e_pow.c_e.c:403:7");
    ; /* t has 20 trailing zeros */
    double temp_var_for_tac_15, temp_var_for_tac_16, temp_var_for_tac_17,
        temp_var_for_tac_18, temp_var_for_tac_19, temp_var_for_tac_20;
    double temp_var_for_const_28, temp_var_for_const_29, temp_var_for_const_30;
    temp_var_for_tac_15 = t * t;

    temp_var_for_tac_16 = t * 0.25;

    temp_var_for_tac_17 = 0.3333333333333333333333 - temp_var_for_tac_16;

    temp_var_for_tac_18 = t * temp_var_for_tac_17;

    temp_var_for_tac_19 = 0.5 - temp_var_for_tac_18;

    temp_var_for_tac_20 = temp_var_for_tac_15 * temp_var_for_tac_19;

    w = temp_var_for_tac_20;
    computeDMul((Addr)&temp_var_for_tac_15, {(Addr)&t, (Addr)&t},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:404:12");
    computeDMul((Addr)&temp_var_for_tac_16,
                {(Addr)&t, (Addr) & (temp_var_for_const_28 = 0.25)},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:404:60");
    computeDSub((Addr)&temp_var_for_tac_17,
                {(Addr) & (temp_var_for_const_29 = 0.3333333333333333333333),
                 (Addr)&temp_var_for_tac_16},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:404:56");
    computeDMul((Addr)&temp_var_for_tac_18,
                {(Addr)&t, (Addr)&temp_var_for_tac_17},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:404:28");
    computeDSub(
        (Addr)&temp_var_for_tac_19,
        {(Addr) & (temp_var_for_const_30 = 0.5), (Addr)&temp_var_for_tac_18},
        "/home/shijia/Public/testprogram/e_pow.c_e.c:404:24");
    computeDMul((Addr)&temp_var_for_tac_20,
                {(Addr)&temp_var_for_tac_15, (Addr)&temp_var_for_tac_19},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:404:17");
    AssignD({(Addr)&w}, (Addr)&temp_var_for_tac_20,
            "/home/shijia/Public/testprogram/e_pow.c_e.c:404:7");
    ;
    double temp_var_for_tac_21;
    double temp_var_for_const_31;
    temp_var_for_tac_21 = ivln2_h * t;

    u = temp_var_for_tac_21;
    computeDMul((Addr)&temp_var_for_tac_21,
                {(Addr) & (temp_var_for_const_31 = ivln2_h), (Addr)&t},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:405:17");
    AssignD({(Addr)&u}, (Addr)&temp_var_for_tac_21,
            "/home/shijia/Public/testprogram/e_pow.c_e.c:405:7");
    ; /* ivln2_h has 21 sig. bits */
    double temp_var_for_tac_22, temp_var_for_tac_23, temp_var_for_tac_24;
    double temp_var_for_const_32, temp_var_for_const_33;
    temp_var_for_tac_22 = t * ivln2_l;

    temp_var_for_tac_23 = w * ivln2;

    temp_var_for_tac_24 = temp_var_for_tac_22 - temp_var_for_tac_23;

    v = temp_var_for_tac_24;
    computeDMul((Addr)&temp_var_for_tac_22,
                {(Addr)&t, (Addr) & (temp_var_for_const_32 = ivln2_l)},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:406:11");
    computeDMul((Addr)&temp_var_for_tac_23,
                {(Addr)&w, (Addr) & (temp_var_for_const_33 = ivln2)},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:406:25");
    computeDSub((Addr)&temp_var_for_tac_24,
                {(Addr)&temp_var_for_tac_22, (Addr)&temp_var_for_tac_23},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:406:21");
    AssignD({(Addr)&v}, (Addr)&temp_var_for_tac_24,
            "/home/shijia/Public/testprogram/e_pow.c_e.c:406:7");
    ;
    double temp_var_for_tac_25;
    temp_var_for_tac_25 = u + v;

    t1 = temp_var_for_tac_25;
    computeDAdd((Addr)&temp_var_for_tac_25, {(Addr)&u, (Addr)&v},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:407:12");
    AssignD({(Addr)&t1}, (Addr)&temp_var_for_tac_25,
            "/home/shijia/Public/testprogram/e_pow.c_e.c:407:8");
    ;
    SET_LOW_WORD(t1, 0);
    ShadowMap[(Addr)&t1].value = Real(t1);
    double temp_var_for_tac_26, temp_var_for_tac_27;
    temp_var_for_tac_26 = t1 - u;

    temp_var_for_tac_27 = v - temp_var_for_tac_26;

    t2 = temp_var_for_tac_27;
    computeDSub((Addr)&temp_var_for_tac_26, {(Addr)&t1, (Addr)&u},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:409:18");
    computeDSub((Addr)&temp_var_for_tac_27,
                {(Addr)&v, (Addr)&temp_var_for_tac_26},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:409:12");
    AssignD({(Addr)&t2}, (Addr)&temp_var_for_tac_27,
            "/home/shijia/Public/testprogram/e_pow.c_e.c:409:8");
    ;
  }
  else
  {
    double s2, s_h, s_l, t_h, t_l;

    n = 0;
    /* take care subnormal number */
    if (ix < IC(0x00100000))
    {
      ax *= two53;
      ;
      n -= 53;
      GET_HIGH_WORD(ix, ax);
    }
    n += ((ix) >> IEEE754_DOUBLE_SHIFT) - IEEE754_DOUBLE_BIAS;
    j = ix & IC(0x000fffff);
    /* determine interval */
    ix = j | IC(0x3ff00000); /* normalize ix */
    if (j <= IC(0x3988E))
    {
      k = 0;
    }
    /* |x|<sqrt(3/2) */
    else
    {
      if (j < IC(0xBB67A))
      {
        k = 1;
      }
      /* |x|<sqrt(3)   */
      else
      {
        k = 0;
        n += 1;
        ix -= IC(0x00100000);
      }
    }

    SET_HIGH_WORD(ax, ix);

    ShadowMap[(Addr)&ax].value = Real(ax);
    /* compute s = s_h+s_l = (x-1)/(x+1) or (x-1.5)/(x+1.5) */
    double temp_var_for_ext_24;
    double temp_var_for_tac_29;
    double temp_var_for_const_34;
    temp_var_for_tac_29 = ax - bp[k];

    temp_var_for_ext_24 = temp_var_for_tac_29;
    computeDSub((Addr)&temp_var_for_tac_29,
                {(Addr)&ax, (Addr) & (temp_var_for_const_34 = bp[k])},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:444:30");
    AssignD({(Addr)&temp_var_for_ext_24}, (Addr)&temp_var_for_tac_29,
            "/home/shijia/Public/testprogram/e_pow.c_e.c:444:25");
    ; // u
    /*(u)(t1)(v)(u)(t1)(two53)(ax)(bp)(k)(bp[k])(ax)*/
    u = temp_var_for_ext_24;
    AssignD({(Addr)&u}, (Addr)&temp_var_for_ext_24,
            "/home/shijia/Public/testprogram/e_pow.c_e.c:446:7");
    ; /* bp[0]=1.0, bp[1]=1.5 */
    double temp_var_for_tac_30, temp_var_for_tac_31;
    double temp_var_for_const_35, temp_var_for_const_36;
    temp_var_for_tac_30 = ax + bp[k];

    temp_var_for_tac_31 = one / temp_var_for_tac_30;

    v = temp_var_for_tac_31;
    computeDAdd((Addr)&temp_var_for_tac_30,
                {(Addr)&ax, (Addr) & (temp_var_for_const_35 = bp[k])},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:447:19");
    computeDDiv(
        (Addr)&temp_var_for_tac_31,
        {(Addr) & (temp_var_for_const_36 = one), (Addr)&temp_var_for_tac_30},
        "/home/shijia/Public/testprogram/e_pow.c_e.c:447:13");
    AssignD({(Addr)&v}, (Addr)&temp_var_for_tac_31,
            "/home/shijia/Public/testprogram/e_pow.c_e.c:447:7");
    ;
    double temp_var_for_tac_32;
    temp_var_for_tac_32 = u * v;

    s = temp_var_for_tac_32;
    computeDMul((Addr)&temp_var_for_tac_32, {(Addr)&u, (Addr)&v},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:448:11");
    AssignD({(Addr)&s}, (Addr)&temp_var_for_tac_32,
            "/home/shijia/Public/testprogram/e_pow.c_e.c:448:7");
    ;
    s_h = s;
    AssignD({(Addr)&s_h}, (Addr)&s,
            "/home/shijia/Public/testprogram/e_pow.c_e.c:449:9");
    ;
    SET_LOW_WORD(s_h, 0);
    ShadowMap[(Addr)&s_h].value = Real(s_h);
    /* t_h=ax+bp[k] High */
    double temp_var_for_const_37;
    t_h = zero;
    AssignD({(Addr)&t_h}, (Addr) & (temp_var_for_const_37 = zero),
            "/home/shijia/Public/testprogram/e_pow.c_e.c:452:9");
    ;
    SET_HIGH_WORD(t_h,
                  ((ix >> 1) | IC(0x20000000)) + IC(0x00080000) + (k << 18));
    ShadowMap[(Addr)&t_h].value = Real(t_h);
    double temp_var_for_tac_33, temp_var_for_tac_34;
    double temp_var_for_const_38;
    temp_var_for_tac_33 = t_h - bp[k];

    temp_var_for_tac_34 = ax - temp_var_for_tac_33;

    t_l = temp_var_for_tac_34;
    computeDSub((Addr)&temp_var_for_tac_33,
                {(Addr)&t_h, (Addr) & (temp_var_for_const_38 = bp[k])},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:455:21");
    computeDSub((Addr)&temp_var_for_tac_34,
                {(Addr)&ax, (Addr)&temp_var_for_tac_33},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:455:14");
    AssignD({(Addr)&t_l}, (Addr)&temp_var_for_tac_34,
            "/home/shijia/Public/testprogram/e_pow.c_e.c:455:9");
    ;
    double temp_var_for_tac_35, temp_var_for_tac_36, temp_var_for_tac_37,
        temp_var_for_tac_38, temp_var_for_tac_39;
    temp_var_for_tac_35 = s_h * t_h;

    temp_var_for_tac_36 = u - temp_var_for_tac_35;

    temp_var_for_tac_37 = s_h * t_l;

    temp_var_for_tac_38 = temp_var_for_tac_36 - temp_var_for_tac_37;

    temp_var_for_tac_39 = v * temp_var_for_tac_38;

    s_l = temp_var_for_tac_39;
    computeDMul((Addr)&temp_var_for_tac_35, {(Addr)&s_h, (Addr)&t_h},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:456:25");
    computeDSub((Addr)&temp_var_for_tac_36,
                {(Addr)&u, (Addr)&temp_var_for_tac_35},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:456:19");
    computeDMul((Addr)&temp_var_for_tac_37, {(Addr)&s_h, (Addr)&t_l},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:456:38");
    computeDSub((Addr)&temp_var_for_tac_38,
                {(Addr)&temp_var_for_tac_36, (Addr)&temp_var_for_tac_37},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:456:32");
    computeDMul((Addr)&temp_var_for_tac_39,
                {(Addr)&v, (Addr)&temp_var_for_tac_38},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:456:13");
    AssignD({(Addr)&s_l}, (Addr)&temp_var_for_tac_39,
            "/home/shijia/Public/testprogram/e_pow.c_e.c:456:9");
    ;
    /* compute log(ax) */
    double temp_var_for_tac_40;
    temp_var_for_tac_40 = s * s;

    s2 = temp_var_for_tac_40;
    computeDMul((Addr)&temp_var_for_tac_40, {(Addr)&s, (Addr)&s},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:458:12");
    AssignD({(Addr)&s2}, (Addr)&temp_var_for_tac_40,
            "/home/shijia/Public/testprogram/e_pow.c_e.c:458:8");
    ;
    double temp_var_for_tac_41, temp_var_for_tac_42, temp_var_for_tac_43,
        temp_var_for_tac_44, temp_var_for_tac_45, temp_var_for_tac_46,
        temp_var_for_tac_47, temp_var_for_tac_48, temp_var_for_tac_49,
        temp_var_for_tac_50, temp_var_for_tac_51, temp_var_for_tac_52;
    double temp_var_for_const_39, temp_var_for_const_40, temp_var_for_const_41,
        temp_var_for_const_42, temp_var_for_const_43, temp_var_for_const_44;
    temp_var_for_tac_41 = s2 * s2;

    temp_var_for_tac_42 = s2 * L6;

    temp_var_for_tac_43 = L5 + temp_var_for_tac_42;

    temp_var_for_tac_44 = s2 * temp_var_for_tac_43;

    temp_var_for_tac_45 = L4 + temp_var_for_tac_44;

    temp_var_for_tac_46 = s2 * temp_var_for_tac_45;

    temp_var_for_tac_47 = L3 + temp_var_for_tac_46;

    temp_var_for_tac_48 = s2 * temp_var_for_tac_47;

    temp_var_for_tac_49 = L2 + temp_var_for_tac_48;

    temp_var_for_tac_50 = s2 * temp_var_for_tac_49;

    temp_var_for_tac_51 = L1 + temp_var_for_tac_50;

    temp_var_for_tac_52 = temp_var_for_tac_41 * temp_var_for_tac_51;

    r = temp_var_for_tac_52;
    computeDMul((Addr)&temp_var_for_tac_41, {(Addr)&s2, (Addr)&s2},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:459:12");
    computeDMul((Addr)&temp_var_for_tac_42,
                {(Addr)&s2, (Addr) & (temp_var_for_const_39 = L6)},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:460:62");
    computeDAdd(
        (Addr)&temp_var_for_tac_43,
        {(Addr) & (temp_var_for_const_40 = L5), (Addr)&temp_var_for_tac_42},
        "/home/shijia/Public/testprogram/e_pow.c_e.c:460:57");
    computeDMul((Addr)&temp_var_for_tac_44,
                {(Addr)&s2, (Addr)&temp_var_for_tac_43},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:460:51");
    computeDAdd(
        (Addr)&temp_var_for_tac_45,
        {(Addr) & (temp_var_for_const_41 = L4), (Addr)&temp_var_for_tac_44},
        "/home/shijia/Public/testprogram/e_pow.c_e.c:460:46");
    computeDMul((Addr)&temp_var_for_tac_46,
                {(Addr)&s2, (Addr)&temp_var_for_tac_45},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:460:40");
    computeDAdd(
        (Addr)&temp_var_for_tac_47,
        {(Addr) & (temp_var_for_const_42 = L3), (Addr)&temp_var_for_tac_46},
        "/home/shijia/Public/testprogram/e_pow.c_e.c:460:35");
    computeDMul((Addr)&temp_var_for_tac_48,
                {(Addr)&s2, (Addr)&temp_var_for_tac_47},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:460:29");
    computeDAdd(
        (Addr)&temp_var_for_tac_49,
        {(Addr) & (temp_var_for_const_43 = L2), (Addr)&temp_var_for_tac_48},
        "/home/shijia/Public/testprogram/e_pow.c_e.c:460:24");
    computeDMul((Addr)&temp_var_for_tac_50,
                {(Addr)&s2, (Addr)&temp_var_for_tac_49},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:460:18");
    computeDAdd(
        (Addr)&temp_var_for_tac_51,
        {(Addr) & (temp_var_for_const_44 = L1), (Addr)&temp_var_for_tac_50},
        "/home/shijia/Public/testprogram/e_pow.c_e.c:460:13");
    computeDMul((Addr)&temp_var_for_tac_52,
                {(Addr)&temp_var_for_tac_41, (Addr)&temp_var_for_tac_51},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:459:17");
    AssignD({(Addr)&r}, (Addr)&temp_var_for_tac_52,
            "/home/shijia/Public/testprogram/e_pow.c_e.c:459:7");
    ;
    double temp_var_for_tac_53, temp_var_for_tac_54;
    temp_var_for_tac_53 = s_h + s;

    temp_var_for_tac_54 = s_l * temp_var_for_tac_53;

    r += temp_var_for_tac_54;
    ;
    double temp_var_for_ext_25;
    double temp_var_for_tac_56;
    temp_var_for_tac_56 = s_h * s_h;

    temp_var_for_ext_25 = temp_var_for_tac_56;
    computeDAdd((Addr)&temp_var_for_tac_53, {(Addr)&s_h, (Addr)&s},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:461:21");
    computeDMul((Addr)&temp_var_for_tac_54,
                {(Addr)&s_l, (Addr)&temp_var_for_tac_53},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:461:14");
    computeDMul((Addr)&temp_var_for_tac_56, {(Addr)&s_h, (Addr)&s_h},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:463:31");
    AssignD({(Addr)&temp_var_for_ext_25}, (Addr)&temp_var_for_tac_56,
            "/home/shijia/Public/testprogram/e_pow.c_e.c:463:25");
    ; // s2
    /*(L6)(s2)(L5)(s2)(L4)(s2)(L3)(s2)(L2)(s2)(L1)(s2)(s2)(s2)(s2)(L6)(s2)(L5)(s2)(L4)(s2)(L3)(s2)(L2)(s2)(L1)(L6)(s2)(L5)(s2)(L4)(s2)(L3)(s2)(L2)(s2)(L6)(s2)(L5)(s2)(L4)(s2)(L3)(s2)(L2)(L6)(s2)(L5)(s2)(L4)(s2)(L3)(s2)(L6)(s2)(L5)(s2)(L4)(s2)(L3)(L6)(s2)(L5)(s2)(L4)(s2)(L6)(s2)(L5)(s2)(L4)(L6)(s2)(L5)(s2)(L6)(s2)(L5)(L6)(s2)(s)(s_h)(s_l)(r)(s)(s_h)(s_l)(s)(s_h)(s_h)(s_h)*/
    s2 = temp_var_for_ext_25;
    AssignD({(Addr)&s2}, (Addr)&temp_var_for_ext_25,
            "/home/shijia/Public/testprogram/e_pow.c_e.c:465:8");
    ;
    double temp_var_for_tac_57, temp_var_for_tac_58;
    double temp_var_for_const_45;
    temp_var_for_tac_57 = 3.0 + s2;

    temp_var_for_tac_58 = temp_var_for_tac_57 + r;

    t_h = temp_var_for_tac_58;
    computeDAdd((Addr)&temp_var_for_tac_57,
                {(Addr) & (temp_var_for_const_45 = 3.0), (Addr)&s2},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:466:15");
    computeDAdd((Addr)&temp_var_for_tac_58,
                {(Addr)&temp_var_for_tac_57, (Addr)&r},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:466:20");
    AssignD({(Addr)&t_h}, (Addr)&temp_var_for_tac_58,
            "/home/shijia/Public/testprogram/e_pow.c_e.c:466:9");
    ;
    SET_LOW_WORD(t_h, 0);
    ShadowMap[(Addr)&t_h].value = Real(t_h);
    double temp_var_for_tac_59, temp_var_for_tac_60, temp_var_for_tac_61;
    double temp_var_for_const_46;
    temp_var_for_tac_59 = t_h - 3.0;

    temp_var_for_tac_60 = temp_var_for_tac_59 - s2;

    temp_var_for_tac_61 = r - temp_var_for_tac_60;

    t_l = temp_var_for_tac_61;
    computeDSub((Addr)&temp_var_for_tac_59,
                {(Addr)&t_h, (Addr) & (temp_var_for_const_46 = 3.0)},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:468:21");
    computeDSub((Addr)&temp_var_for_tac_60,
                {(Addr)&temp_var_for_tac_59, (Addr)&s2},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:468:28");
    computeDSub((Addr)&temp_var_for_tac_61,
                {(Addr)&r, (Addr)&temp_var_for_tac_60},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:468:13");
    AssignD({(Addr)&t_l}, (Addr)&temp_var_for_tac_61,
            "/home/shijia/Public/testprogram/e_pow.c_e.c:468:9");
    ;
    /* u+v = s*(1+...) */
    double temp_var_for_tac_62;
    temp_var_for_tac_62 = s_h * t_h;

    u = temp_var_for_tac_62;
    computeDMul((Addr)&temp_var_for_tac_62, {(Addr)&s_h, (Addr)&t_h},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:470:13");
    AssignD({(Addr)&u}, (Addr)&temp_var_for_tac_62,
            "/home/shijia/Public/testprogram/e_pow.c_e.c:470:7");
    ;
    double temp_var_for_tac_63, temp_var_for_tac_64, temp_var_for_tac_65;
    temp_var_for_tac_63 = s_l * t_h;

    temp_var_for_tac_64 = t_l * s;

    temp_var_for_tac_65 = temp_var_for_tac_63 + temp_var_for_tac_64;

    v = temp_var_for_tac_65;
    computeDMul((Addr)&temp_var_for_tac_63, {(Addr)&s_l, (Addr)&t_h},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:471:13");
    computeDMul((Addr)&temp_var_for_tac_64, {(Addr)&t_l, (Addr)&s},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:471:25");
    computeDAdd((Addr)&temp_var_for_tac_65,
                {(Addr)&temp_var_for_tac_63, (Addr)&temp_var_for_tac_64},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:471:19");
    AssignD({(Addr)&v}, (Addr)&temp_var_for_tac_65,
            "/home/shijia/Public/testprogram/e_pow.c_e.c:471:7");
    ;
    /* 2/(3log2)*(s+...) */
    double temp_var_for_tac_66;
    temp_var_for_tac_66 = u + v;

    p_h = temp_var_for_tac_66;
    computeDAdd((Addr)&temp_var_for_tac_66, {(Addr)&u, (Addr)&v},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:473:13");
    AssignD({(Addr)&p_h}, (Addr)&temp_var_for_tac_66,
            "/home/shijia/Public/testprogram/e_pow.c_e.c:473:9");
    ;
    SET_LOW_WORD(p_h, 0);
    ShadowMap[(Addr)&p_h].value = Real(p_h);
    double temp_var_for_tac_67, temp_var_for_tac_68;
    temp_var_for_tac_67 = p_h - u;

    temp_var_for_tac_68 = v - temp_var_for_tac_67;

    p_l = temp_var_for_tac_68;
    computeDSub((Addr)&temp_var_for_tac_67, {(Addr)&p_h, (Addr)&u},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:475:20");
    computeDSub((Addr)&temp_var_for_tac_68,
                {(Addr)&v, (Addr)&temp_var_for_tac_67},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:475:13");
    AssignD({(Addr)&p_l}, (Addr)&temp_var_for_tac_68,
            "/home/shijia/Public/testprogram/e_pow.c_e.c:475:9");
    ;
    double temp_var_for_tac_69;
    double temp_var_for_const_47;
    temp_var_for_tac_69 = cp_h * p_h;

    z_h = temp_var_for_tac_69;
    computeDMul((Addr)&temp_var_for_tac_69,
                {(Addr) & (temp_var_for_const_47 = cp_h), (Addr)&p_h},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:476:16");
    AssignD({(Addr)&z_h}, (Addr)&temp_var_for_tac_69,
            "/home/shijia/Public/testprogram/e_pow.c_e.c:476:9");
    ; /* cp_h+cp_l = 2/(3*log2) */
    double temp_var_for_tac_70, temp_var_for_tac_71, temp_var_for_tac_72,
        temp_var_for_tac_73;
    double temp_var_for_const_48, temp_var_for_const_49, temp_var_for_const_50;
    temp_var_for_tac_70 = cp_l * p_h;

    temp_var_for_tac_71 = p_l * cp;

    temp_var_for_tac_72 = temp_var_for_tac_70 + temp_var_for_tac_71;

    temp_var_for_tac_73 = temp_var_for_tac_72 + dp_l[k];

    z_l = temp_var_for_tac_73;
    computeDMul((Addr)&temp_var_for_tac_70,
                {(Addr) & (temp_var_for_const_48 = cp_l), (Addr)&p_h},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:477:16");
    computeDMul((Addr)&temp_var_for_tac_71,
                {(Addr)&p_l, (Addr) & (temp_var_for_const_49 = cp)},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:477:28");
    computeDAdd((Addr)&temp_var_for_tac_72,
                {(Addr)&temp_var_for_tac_70, (Addr)&temp_var_for_tac_71},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:477:22");
    computeDAdd(
        (Addr)&temp_var_for_tac_73,
        {(Addr)&temp_var_for_tac_72, (Addr) & (temp_var_for_const_50 = dp_l[k])},
        "/home/shijia/Public/testprogram/e_pow.c_e.c:477:33");
    AssignD({(Addr)&z_l}, (Addr)&temp_var_for_tac_73,
            "/home/shijia/Public/testprogram/e_pow.c_e.c:477:9");
    ;
    /* log2(ax) = (s+..)*2/(3*log2) = n + dp_h + z_h + z_l */
    double temp_var_for_const_51;
    t = ((double)n);
    AssignD({(Addr)&t}, (Addr) & (temp_var_for_const_51 = ((double)n)),
            "/home/shijia/Public/testprogram/e_pow.c_e.c:479:7");
    ;
    double temp_var_for_tac_74, temp_var_for_tac_75, temp_var_for_tac_76;
    double temp_var_for_const_52;
    temp_var_for_tac_74 = z_h + z_l;

    temp_var_for_tac_75 = temp_var_for_tac_74 + dp_h[k];

    temp_var_for_tac_76 = temp_var_for_tac_75 + t;

    t1 = temp_var_for_tac_76;
    computeDAdd((Addr)&temp_var_for_tac_74, {(Addr)&z_h, (Addr)&z_l},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:480:17");
    computeDAdd(
        (Addr)&temp_var_for_tac_75,
        {(Addr)&temp_var_for_tac_74, (Addr) & (temp_var_for_const_52 = dp_h[k])},
        "/home/shijia/Public/testprogram/e_pow.c_e.c:480:24");
    computeDAdd((Addr)&temp_var_for_tac_76,
                {(Addr)&temp_var_for_tac_75, (Addr)&t},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:480:35");
    AssignD({(Addr)&t1}, (Addr)&temp_var_for_tac_76,
            "/home/shijia/Public/testprogram/e_pow.c_e.c:480:8");
    ;
    SET_LOW_WORD(t1, 0);
    ShadowMap[(Addr)&t1].value = Real(t1);
    double temp_var_for_tac_77, temp_var_for_tac_78, temp_var_for_tac_79,
        temp_var_for_tac_80;
    double temp_var_for_const_53;
    temp_var_for_tac_77 = t1 - t;

    temp_var_for_tac_78 = temp_var_for_tac_77 - dp_h[k];

    temp_var_for_tac_79 = temp_var_for_tac_78 - z_h;

    temp_var_for_tac_80 = z_l - temp_var_for_tac_79;

    t2 = temp_var_for_tac_80;
    computeDSub((Addr)&temp_var_for_tac_77, {(Addr)&t1, (Addr)&t},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:482:22");
    computeDSub(
        (Addr)&temp_var_for_tac_78,
        {(Addr)&temp_var_for_tac_77, (Addr) & (temp_var_for_const_53 = dp_h[k])},
        "/home/shijia/Public/testprogram/e_pow.c_e.c:482:27");
    computeDSub((Addr)&temp_var_for_tac_79,
                {(Addr)&temp_var_for_tac_78, (Addr)&z_h},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:482:38");
    computeDSub((Addr)&temp_var_for_tac_80,
                {(Addr)&z_l, (Addr)&temp_var_for_tac_79},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:482:14");
    AssignD({(Addr)&t2}, (Addr)&temp_var_for_tac_80,
            "/home/shijia/Public/testprogram/e_pow.c_e.c:482:8");
    ;
  }

  double temp_var_for_const_54;
  s = one;
  AssignD({(Addr)&s}, (Addr) & (temp_var_for_const_54 = one),
          "/home/shijia/Public/testprogram/e_pow.c_e.c:485:5");
  ; /* s (sign of result -ve**odd) = -1 else = 1 */
  if (((((uint32_t)hx >> 31) - 1) | (yisint - 1)) == 0)
  {
    double temp_var_for_tac_81;
    double temp_var_for_const_55, temp_var_for_const_56;
    temp_var_for_tac_81 = 0.0 - one;

    s = temp_var_for_tac_81;
    computeDSub((Addr)&temp_var_for_tac_81,
                {(Addr) & (temp_var_for_const_56 = 0.0),
                 (Addr) & (temp_var_for_const_55 = one)},
                "/home/shijia/Public/testprogram/e_pow.c_e.c:487:14");
    AssignD({(Addr)&s}, (Addr)&temp_var_for_tac_81,
            "/home/shijia/Public/testprogram/e_pow.c_e.c:487:7");
    ;
  }
  /* (-ve)**(odd int) */

  /* split up y into y1+y2 and compute (y1+y2)*(t1+t2) */
  y1 = y;
  AssignD({(Addr)&y1}, (Addr)&y,
          "/home/shijia/Public/testprogram/e_pow.c_e.c:492:6");
  ;
  SET_LOW_WORD(y1, 0);
  ShadowMap[(Addr)&y1].value = Real(y1);
  double temp_var_for_tac_82, temp_var_for_tac_83, temp_var_for_tac_84,
      temp_var_for_tac_85;
  temp_var_for_tac_82 = y - y1;

  temp_var_for_tac_83 = temp_var_for_tac_82 * t1;

  temp_var_for_tac_84 = y * t2;

  temp_var_for_tac_85 = temp_var_for_tac_83 + temp_var_for_tac_84;

  p_l = temp_var_for_tac_85;
  computeDSub((Addr)&temp_var_for_tac_82, {(Addr)&y, (Addr)&y1},
              "/home/shijia/Public/testprogram/e_pow.c_e.c:494:12");
  computeDMul((Addr)&temp_var_for_tac_83,
              {(Addr)&temp_var_for_tac_82, (Addr)&t1},
              "/home/shijia/Public/testprogram/e_pow.c_e.c:494:18");
  computeDMul((Addr)&temp_var_for_tac_84, {(Addr)&y, (Addr)&t2},
              "/home/shijia/Public/testprogram/e_pow.c_e.c:494:27");
  computeDAdd((Addr)&temp_var_for_tac_85,
              {(Addr)&temp_var_for_tac_83, (Addr)&temp_var_for_tac_84},
              "/home/shijia/Public/testprogram/e_pow.c_e.c:494:23");
  AssignD({(Addr)&p_l}, (Addr)&temp_var_for_tac_85,
          "/home/shijia/Public/testprogram/e_pow.c_e.c:494:7");
  ;
  double temp_var_for_tac_86;
  temp_var_for_tac_86 = y1 * t1;

  p_h = temp_var_for_tac_86;
  computeDMul((Addr)&temp_var_for_tac_86, {(Addr)&y1, (Addr)&t1},
              "/home/shijia/Public/testprogram/e_pow.c_e.c:495:12");
  AssignD({(Addr)&p_h}, (Addr)&temp_var_for_tac_86,
          "/home/shijia/Public/testprogram/e_pow.c_e.c:495:7");
  ;
  double temp_var_for_tac_87;
  temp_var_for_tac_87 = p_l + p_h;

  z = temp_var_for_tac_87;
  computeDAdd((Addr)&temp_var_for_tac_87, {(Addr)&p_l, (Addr)&p_h},
              "/home/shijia/Public/testprogram/e_pow.c_e.c:496:11");
  AssignD({(Addr)&z}, (Addr)&temp_var_for_tac_87,
          "/home/shijia/Public/testprogram/e_pow.c_e.c:496:5");
  ;
  GET_DOUBLE_WORDS(j, i, z);
  if (j >= IC(0x40900000))
  {                                      /* z >= 1024 */
    if (((j - IC(0x40900000)) | i) != 0) /* if z > 1024 */
    {
      feraiseexcept(FE_OVERFLOW);
      double temp_var_for_ext_26;
      double temp_var_for_const_57;
      double temp_var_for_callexp_8;

      /*embed fun has found*/
      double temp_var_for_callexp_9;

      temp_var_for_callexp_8 = __builtin_huge_val();
      temp_var_for_callexp_9 = copysign(temp_var_for_callexp_8, s);
      temp_var_for_ext_26 = temp_var_for_callexp_9;
      AssignD({(Addr)&temp_var_for_ext_26},
              (Addr) & (temp_var_for_const_57 = temp_var_for_callexp_9),
              "/home/shijia/Public/testprogram/e_pow.c_e.c:503:27");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_26", (Addr)&temp_var_for_ext_26));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_26;
    }
    if (p_l + ovt > z - p_h)
    {
      feraiseexcept(FE_OVERFLOW);
      double temp_var_for_ext_27;
      double temp_var_for_const_59;
      double temp_var_for_callexp_10;

      /*embed fun has found*/
      double temp_var_for_callexp_11;

      temp_var_for_callexp_10 = __builtin_huge_val();
      temp_var_for_callexp_11 = copysign(temp_var_for_callexp_10, s);
      temp_var_for_ext_27 = temp_var_for_callexp_11;
      AssignD({(Addr)&temp_var_for_ext_27},
              (Addr) & (temp_var_for_const_59 = temp_var_for_callexp_11),
              "/home/shijia/Public/testprogram/e_pow.c_e.c:512:27");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_27", (Addr)&temp_var_for_ext_27));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_27;
    }
  }
  else
  {
    if ((j & IC(0x7fffffff)) >= IC(0x4090cc00))
    {                                      /* z <= -1075 */
      if (((j - IC(0xc090cc00)) | i) != 0) /* z < -1075 */
      {
        feraiseexcept(FE_UNDERFLOW);
        double temp_var_for_ext_28;
        double temp_var_for_const_60;
        double temp_var_for_callexp_12;

        temp_var_for_callexp_12 = copysign(0.0, s);
        temp_var_for_ext_28 = temp_var_for_callexp_12;
        AssignD({(Addr)&temp_var_for_ext_28},
                (Addr) & (temp_var_for_const_60 = temp_var_for_callexp_12),
                "/home/shijia/Public/testprogram/e_pow.c_e.c:524:29");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_28", (Addr)&temp_var_for_ext_28));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_28;
      }
      if (p_l <= z - p_h)
      {
        feraiseexcept(FE_UNDERFLOW);
        double temp_var_for_ext_29;
        double temp_var_for_const_61;
        double temp_var_for_callexp_13;

        temp_var_for_callexp_13 = copysign(0.0, s);
        temp_var_for_ext_29 = temp_var_for_callexp_13;
        AssignD({(Addr)&temp_var_for_ext_29},
                (Addr) & (temp_var_for_const_61 = temp_var_for_callexp_13),
                "/home/shijia/Public/testprogram/e_pow.c_e.c:533:29");
        ;
        callExpStack.push(
            getReal("temp_var_for_ext_29", (Addr)&temp_var_for_ext_29));
        callExp++; /*identify the function is  add move tmpShadow*/
        return temp_var_for_ext_29;
      }
    }
  }

  /*
   * compute 2**(p_h+p_l)
   */
  i = j & IC(0x7fffffff);
  k = (i >> IEEE754_DOUBLE_SHIFT) - IEEE754_DOUBLE_BIAS;
  n = 0;
  if (i > IC(0x3fe00000))
  { /* if |z| > 0.5, set n = [z+0.5] */
    n = j + (IC(0x00100000) >> (k + 1));
    k = ((n & IC(0x7fffffff)) >> IEEE754_DOUBLE_SHIFT) -
        IEEE754_DOUBLE_BIAS; /* new k for n */
    double temp_var_for_const_62;
    t = zero;
    AssignD({(Addr)&t}, (Addr) & (temp_var_for_const_62 = zero),
            "/home/shijia/Public/testprogram/e_pow.c_e.c:552:7");
    ;
    SET_HIGH_WORD(t, n & ~(UC(0x000fffff) >> k));
    ShadowMap[(Addr)&t].value = Real(t);
    n = ((n & IC(0x000fffff)) | IC(0x00100000)) >> (IEEE754_DOUBLE_SHIFT - k);
    if (j < 0)
    {
      n = -n;
    }

    p_h -= t;
    ;
  }
  double temp_var_for_ext_30;
  double temp_var_for_tac_94;
  temp_var_for_tac_94 = p_l + p_h;

  temp_var_for_ext_30 = temp_var_for_tac_94;
  computeDAdd((Addr)&temp_var_for_tac_94, {(Addr)&p_l, (Addr)&p_h},
              "/home/shijia/Public/testprogram/e_pow.c_e.c:562:29");
  AssignD({(Addr)&temp_var_for_ext_30}, (Addr)&temp_var_for_tac_94,
          "/home/shijia/Public/testprogram/e_pow.c_e.c:562:23");
  ; // t
  /*(t)(p_h)(p_h)(p_l)*/
  t = temp_var_for_ext_30;
  AssignD({(Addr)&t}, (Addr)&temp_var_for_ext_30,
          "/home/shijia/Public/testprogram/e_pow.c_e.c:564:5");
  ;
  SET_LOW_WORD(t, 0);
  ShadowMap[(Addr)&t].value = Real(t);
  double temp_var_for_tac_95;
  double temp_var_for_const_63;
  temp_var_for_tac_95 = t * lg2_h;

  u = temp_var_for_tac_95;
  computeDMul((Addr)&temp_var_for_tac_95,
              {(Addr)&t, (Addr) & (temp_var_for_const_63 = lg2_h)},
              "/home/shijia/Public/testprogram/e_pow.c_e.c:566:9");
  AssignD({(Addr)&u}, (Addr)&temp_var_for_tac_95,
          "/home/shijia/Public/testprogram/e_pow.c_e.c:566:5");
  ;
  double temp_var_for_tac_96, temp_var_for_tac_97, temp_var_for_tac_98,
      temp_var_for_tac_99, temp_var_for_tac_100;
  double temp_var_for_const_64, temp_var_for_const_65;
  temp_var_for_tac_96 = t - p_h;

  temp_var_for_tac_97 = p_l - temp_var_for_tac_96;

  temp_var_for_tac_98 = temp_var_for_tac_97 * lg2;

  temp_var_for_tac_99 = t * lg2_l;

  temp_var_for_tac_100 = temp_var_for_tac_98 + temp_var_for_tac_99;

  v = temp_var_for_tac_100;
  computeDSub((Addr)&temp_var_for_tac_96, {(Addr)&t, (Addr)&p_h},
              "/home/shijia/Public/testprogram/e_pow.c_e.c:567:17");
  computeDSub((Addr)&temp_var_for_tac_97,
              {(Addr)&p_l, (Addr)&temp_var_for_tac_96},
              "/home/shijia/Public/testprogram/e_pow.c_e.c:567:12");
  computeDMul(
      (Addr)&temp_var_for_tac_98,
      {(Addr)&temp_var_for_tac_97, (Addr) & (temp_var_for_const_64 = lg2)},
      "/home/shijia/Public/testprogram/e_pow.c_e.c:567:25");
  computeDMul((Addr)&temp_var_for_tac_99,
              {(Addr)&t, (Addr) & (temp_var_for_const_65 = lg2_l)},
              "/home/shijia/Public/testprogram/e_pow.c_e.c:567:35");
  computeDAdd((Addr)&temp_var_for_tac_100,
              {(Addr)&temp_var_for_tac_98, (Addr)&temp_var_for_tac_99},
              "/home/shijia/Public/testprogram/e_pow.c_e.c:567:31");
  AssignD({(Addr)&v}, (Addr)&temp_var_for_tac_100,
          "/home/shijia/Public/testprogram/e_pow.c_e.c:567:5");
  ;
  double temp_var_for_tac_101;
  temp_var_for_tac_101 = u + v;

  z = temp_var_for_tac_101;
  computeDAdd((Addr)&temp_var_for_tac_101, {(Addr)&u, (Addr)&v},
              "/home/shijia/Public/testprogram/e_pow.c_e.c:568:9");
  AssignD({(Addr)&z}, (Addr)&temp_var_for_tac_101,
          "/home/shijia/Public/testprogram/e_pow.c_e.c:568:5");
  ;
  double temp_var_for_tac_102, temp_var_for_tac_103;
  temp_var_for_tac_102 = z - u;

  temp_var_for_tac_103 = v - temp_var_for_tac_102;

  w = temp_var_for_tac_103;
  computeDSub((Addr)&temp_var_for_tac_102, {(Addr)&z, (Addr)&u},
              "/home/shijia/Public/testprogram/e_pow.c_e.c:569:14");
  computeDSub((Addr)&temp_var_for_tac_103,
              {(Addr)&v, (Addr)&temp_var_for_tac_102},
              "/home/shijia/Public/testprogram/e_pow.c_e.c:569:9");
  AssignD({(Addr)&w}, (Addr)&temp_var_for_tac_103,
          "/home/shijia/Public/testprogram/e_pow.c_e.c:569:5");
  ;
  double temp_var_for_tac_104;
  temp_var_for_tac_104 = z * z;

  t = temp_var_for_tac_104;
  computeDMul((Addr)&temp_var_for_tac_104, {(Addr)&z, (Addr)&z},
              "/home/shijia/Public/testprogram/e_pow.c_e.c:570:9");
  AssignD({(Addr)&t}, (Addr)&temp_var_for_tac_104,
          "/home/shijia/Public/testprogram/e_pow.c_e.c:570:5");
  ;
  double temp_var_for_tac_105, temp_var_for_tac_106, temp_var_for_tac_107,
      temp_var_for_tac_108, temp_var_for_tac_109, temp_var_for_tac_110,
      temp_var_for_tac_111, temp_var_for_tac_112, temp_var_for_tac_113,
      temp_var_for_tac_114;
  double temp_var_for_const_66, temp_var_for_const_67, temp_var_for_const_68,
      temp_var_for_const_69, temp_var_for_const_70;
  temp_var_for_tac_105 = t * P5;

  temp_var_for_tac_106 = P4 + temp_var_for_tac_105;

  temp_var_for_tac_107 = t * temp_var_for_tac_106;

  temp_var_for_tac_108 = P3 + temp_var_for_tac_107;

  temp_var_for_tac_109 = t * temp_var_for_tac_108;

  temp_var_for_tac_110 = P2 + temp_var_for_tac_109;

  temp_var_for_tac_111 = t * temp_var_for_tac_110;

  temp_var_for_tac_112 = P1 + temp_var_for_tac_111;

  temp_var_for_tac_113 = t * temp_var_for_tac_112;

  temp_var_for_tac_114 = z - temp_var_for_tac_113;

  t1 = temp_var_for_tac_114;
  computeDMul((Addr)&temp_var_for_tac_105,
              {(Addr)&t, (Addr) & (temp_var_for_const_66 = P5)},
              "/home/shijia/Public/testprogram/e_pow.c_e.c:571:54");
  computeDAdd(
      (Addr)&temp_var_for_tac_106,
      {(Addr) & (temp_var_for_const_67 = P4), (Addr)&temp_var_for_tac_105},
      "/home/shijia/Public/testprogram/e_pow.c_e.c:571:50");
  computeDMul((Addr)&temp_var_for_tac_107,
              {(Addr)&t, (Addr)&temp_var_for_tac_106},
              "/home/shijia/Public/testprogram/e_pow.c_e.c:571:44");
  computeDAdd(
      (Addr)&temp_var_for_tac_108,
      {(Addr) & (temp_var_for_const_68 = P3), (Addr)&temp_var_for_tac_107},
      "/home/shijia/Public/testprogram/e_pow.c_e.c:571:40");
  computeDMul((Addr)&temp_var_for_tac_109,
              {(Addr)&t, (Addr)&temp_var_for_tac_108},
              "/home/shijia/Public/testprogram/e_pow.c_e.c:571:34");
  computeDAdd(
      (Addr)&temp_var_for_tac_110,
      {(Addr) & (temp_var_for_const_69 = P2), (Addr)&temp_var_for_tac_109},
      "/home/shijia/Public/testprogram/e_pow.c_e.c:571:30");
  computeDMul((Addr)&temp_var_for_tac_111,
              {(Addr)&t, (Addr)&temp_var_for_tac_110},
              "/home/shijia/Public/testprogram/e_pow.c_e.c:571:24");
  computeDAdd(
      (Addr)&temp_var_for_tac_112,
      {(Addr) & (temp_var_for_const_70 = P1), (Addr)&temp_var_for_tac_111},
      "/home/shijia/Public/testprogram/e_pow.c_e.c:571:20");
  computeDMul((Addr)&temp_var_for_tac_113,
              {(Addr)&t, (Addr)&temp_var_for_tac_112},
              "/home/shijia/Public/testprogram/e_pow.c_e.c:571:14");
  computeDSub((Addr)&temp_var_for_tac_114,
              {(Addr)&z, (Addr)&temp_var_for_tac_113},
              "/home/shijia/Public/testprogram/e_pow.c_e.c:571:10");
  AssignD({(Addr)&t1}, (Addr)&temp_var_for_tac_114,
          "/home/shijia/Public/testprogram/e_pow.c_e.c:571:6");
  ;
  double temp_var_for_tac_115, temp_var_for_tac_116, temp_var_for_tac_117,
      temp_var_for_tac_118, temp_var_for_tac_119, temp_var_for_tac_120;
  double temp_var_for_const_71;
  temp_var_for_tac_115 = z * t1;

  temp_var_for_tac_116 = t1 - two;

  temp_var_for_tac_117 = temp_var_for_tac_115 / temp_var_for_tac_116;

  temp_var_for_tac_118 = z * w;

  temp_var_for_tac_119 = w + temp_var_for_tac_118;

  temp_var_for_tac_120 = temp_var_for_tac_117 - temp_var_for_tac_119;

  r = temp_var_for_tac_120;
  computeDMul((Addr)&temp_var_for_tac_115, {(Addr)&z, (Addr)&t1},
              "/home/shijia/Public/testprogram/e_pow.c_e.c:572:10");
  computeDSub((Addr)&temp_var_for_tac_116,
              {(Addr)&t1, (Addr) & (temp_var_for_const_71 = two)},
              "/home/shijia/Public/testprogram/e_pow.c_e.c:572:22");
  computeDDiv((Addr)&temp_var_for_tac_117,
              {(Addr)&temp_var_for_tac_115, (Addr)&temp_var_for_tac_116},
              "/home/shijia/Public/testprogram/e_pow.c_e.c:572:16");
  computeDMul((Addr)&temp_var_for_tac_118, {(Addr)&z, (Addr)&w},
              "/home/shijia/Public/testprogram/e_pow.c_e.c:572:38");
  computeDAdd((Addr)&temp_var_for_tac_119,
              {(Addr)&w, (Addr)&temp_var_for_tac_118},
              "/home/shijia/Public/testprogram/e_pow.c_e.c:572:34");
  computeDSub((Addr)&temp_var_for_tac_120,
              {(Addr)&temp_var_for_tac_117, (Addr)&temp_var_for_tac_119},
              "/home/shijia/Public/testprogram/e_pow.c_e.c:572:29");
  AssignD({(Addr)&r}, (Addr)&temp_var_for_tac_120,
          "/home/shijia/Public/testprogram/e_pow.c_e.c:572:5");
  ;
  double temp_var_for_ext_31;
  double temp_var_for_tac_121, temp_var_for_tac_122;
  double temp_var_for_const_72;
  temp_var_for_tac_121 = r - z;

  temp_var_for_tac_122 = one - temp_var_for_tac_121;

  temp_var_for_ext_31 = temp_var_for_tac_122;
  computeDSub((Addr)&temp_var_for_tac_121, {(Addr)&r, (Addr)&z},
              "/home/shijia/Public/testprogram/e_pow.c_e.c:574:34");
  computeDSub(
      (Addr)&temp_var_for_tac_122,
      {(Addr) & (temp_var_for_const_72 = one), (Addr)&temp_var_for_tac_121},
      "/home/shijia/Public/testprogram/e_pow.c_e.c:574:29");
  AssignD({(Addr)&temp_var_for_ext_31}, (Addr)&temp_var_for_tac_122,
          "/home/shijia/Public/testprogram/e_pow.c_e.c:574:23");
  ; // z
  /*(w)(z)(w)(two)(t1)(t1)(z)(two)(t1)(t1)(z)(t1)(z)(two)(t1)(w)(z)(w)(w)(z)(z)(r)(one)*/
  z = temp_var_for_ext_31;
  AssignD({(Addr)&z}, (Addr)&temp_var_for_ext_31,
          "/home/shijia/Public/testprogram/e_pow.c_e.c:576:5");
  ;
  GET_HIGH_WORD(j, z);
  j += (n << IEEE754_DOUBLE_SHIFT);
  if ((j >> IEEE754_DOUBLE_SHIFT) <= 0)
  {
    double temp_var_for_ext_32;
    double temp_var_for_const_73;
    double temp_var_for_callexp_14;

    temp_var_for_callexp_14 = __ieee754_scalbn(z, ((int)n));
    temp_var_for_ext_32 = temp_var_for_callexp_14;
    AssignD({(Addr)&temp_var_for_ext_32},
            (Addr) & (temp_var_for_const_73 = temp_var_for_callexp_14),
            "/home/shijia/Public/testprogram/e_pow.c_e.c:581:25");
    ; // z
    /*(z)(r)(one)(z)(r)(__ieee754_scalbn(z, (int) n))*/
    z = temp_var_for_ext_32;
    AssignD({(Addr)&z}, (Addr)&temp_var_for_ext_32,
            "/home/shijia/Public/testprogram/e_pow.c_e.c:583:7");
    ; /* subnormal output */
  }
  else
  {
    SET_HIGH_WORD(z, j);
    SET_HIGH_WORD(ShadowMap[(Addr)&z].value.z, j);
    ShadowMap[(Addr)&z].value = Real(z);
  }
  double temp_var_for_ext_33;
  double temp_var_for_tac_123;
  temp_var_for_tac_123 = s * z;

  temp_var_for_ext_33 = temp_var_for_tac_123;
  computeDMul((Addr)&temp_var_for_tac_123, {(Addr)&s, (Addr)&z},
              "/home/shijia/Public/testprogram/e_pow.c_e.c:588:27");
  AssignD({(Addr)&temp_var_for_ext_33}, (Addr)&temp_var_for_tac_123,
          "/home/shijia/Public/testprogram/e_pow.c_e.c:588:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_33", (Addr)&temp_var_for_ext_33));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_33;
}

int main()
{
  std::ifstream inputFile("/home/shijia/Public/FpDebug-valgrind_3.12/valgrind/fpdebug/pso/exe-input/pow_t.txt", std::ios::in);
  double input, input1;
  long double oracle, realError = 0.0, scError = 0.0, prealError = 0.0, pscError = 0.0;
  long double delta = 1.0e-20;
  int index, la = 0, eq = 0, sm = 0;
  std::ifstream inputOracle("/home/shijia/Public/FpDebug-valgrind_3.12/valgrind/fpdebug/pso/mpfr/mpfrresults/pow_out.txt", std::ios::in);
  while (inputFile >> input >> input1)
  {
    double a = __ieee754_powS(input, input1);
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