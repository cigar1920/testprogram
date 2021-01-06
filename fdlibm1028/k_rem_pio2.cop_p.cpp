#include "../ScDebug/scdebug.h"
/* @(#)k_rem_pio2.c 1.3 95/01/18 */
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

/*
 * __kernel_rem_pio2(x,y,e0,nx,prec,ipio2)
 * double x[],y[]; int e0,nx,prec; int ipio2[];
 *
 * __kernel_rem_pio2 return the last three digits of N with
 *		y = x - N*pi/2
 * so that |y| < pi/2.
 *
 * The method is to compute the integer (mod 8) and fraction parts of
 * (2/pi)*x without doing the full multiplication. In general we
 * skip the part of the product that are known to be a huge integer (
 * more accurately, = 0 mod 8 ). Thus the number of operations are
 * independent of the exponent of the input.
 *
 * (2/pi) is represented by an array of 24-bit integers in ipio2[].
 *
 * Input parameters:
 * 	x[]	The input value (must be positive) is broken into nx
 *		pieces of 24-bit integers in double precision format.
 *		x[i] will be the i-th 24 bit of x. The scaled exponent
 *		of x[0] is given in input parameter e0 (i.e., x[0]*2^e0
 *		match x's up to 24 bits.
 *
 *		Example of breaking a double positive z into x[0]+x[1]+x[2]:
 *			e0 = ilogb(z)-23
 *			z  = scalbn(z,-e0)
 *		for i = 0,1,2
 *			x[i] = floor(z)
 *			z    = (z-x[i])*2**24
 *
 *
 *	y[]	ouput result in an array of double precision numbers.
 *		The dimension of y[] is:
 *			24-bit  precision	1
 *			53-bit  precision	2
 *			64-bit  precision	2
 *			113-bit precision	3
 *		The actual value is the sum of them. Thus for 113-bit
 *		precision, one may have to do something like:
 *
 *		long double t,w,r_head, r_tail;
 *		t = (long double)y[2] + (long double)y[1];
 *		w = (long double)y[0];
 *		r_head = t+w;
 *		r_tail = w - (r_head - t);
 *
 *	e0	The exponent of x[0]
 *
 *	nx	dimension of x[]
 *
 *  	prec	an integer indicating the precision:
 *			0	24  bits (single)
 *			1	53  bits (double)
 *			2	64  bits (extended)
 *			3	113 bits (quad)
 *
 *	ipio2[]
 *		integer array, contains the (24*i)-th to (24*i+23)-th
 *		bit of 2/pi after binary point. The corresponding
 *		floating value is
 *
 *			ipio2[i] * 2^(-24(i+1)).
 *
 * External function:
 *	double scalbn(), floor();
 *
 *
 * Here is the description of some local variables:
 *
 * 	jk	jk+1 is the initial number of terms of ipio2[] needed
 *		in the computation. The recommended value is 2,3,4,
 *		6 for single, double, extended,and quad.
 *
 * 	jz	local integer variable indicating the number of
 *		terms of ipio2[] used.
 *
 *	jx	nx - 1
 *
 *	jv	index for pointing to the suitable ipio2[] for the
 *		computation. In general, we want
 *			( 2^e0*x[0] * ipio2[jv-1]*2^(-24jv) )/8
 *		is an integer. Thus
 *			e0-3-24*jv >= 0 or (e0-3)/24 >= jv
 *		Hence jv = max(0,(e0-3)/24).
 *
 *	jp	jp+1 is the number of terms in PIo2[] needed, jp = jk.
 *
 * 	q[]	double array with integral value, representing the
 *		24-bits chunk of the product of x and 2/pi.
 *
 *	q0	the corresponding exponent of q[0]. Note that the
 *		exponent for q[i] would be q0-24*i.
 *
 *	PIo2[]	double precision array, obtained by cutting pi/2
 *		into 24 bits chunks.
 *
 *	f[]	ipio2[] in floating point
 *
 *	iq[]	integer array by breaking up q[] in 24-bits chunk.
 *
 *	fq[]	final product of x*(2/pi) in fq[0],..,fq[jk]
 *
 *	ih	integer. If >0 it indicates q[] is >= 0.5, hence
 *		it also indicates the *sign* of the result.
 *
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

int32_t __kernel_rem_pio2(double *x, double *y, int32_t e0, int32_t nx,
                          int prec) {
  int32_t jz, jx, jv, jp, jk, carry, n, iq[20], i, j, k, m, q0, ih;
  double z, fw, f[20], fq[20], q[20];

  static const int init_jk[] = {2, 3, 4, 6}; /* initial value for jk */

  /*
   * Constants:
   * The hexadecimal values are the intended ones for the following
   * constants. The decimal values may be used, provided that the
   * compiler will convert from decimal to binary accurately enough
   * to produce the hexadecimal values shown.
   */

  static const double PIo2[] = {
      1.57079625129699707031e+00, /* 0x3FF921FB, 0x40000000 */
      7.54978941586159635335e-08, /* 0x3E74442D, 0x00000000 */
      5.39030252995776476554e-15, /* 0x3CF84698, 0x80000000 */
      3.28200341580791294123e-22, /* 0x3B78CC51, 0x60000000 */
      1.27065575308067607349e-29, /* 0x39F01B83, 0x80000000 */
      1.22933308981111328932e-36, /* 0x387A2520, 0x40000000 */
      2.73370053816464559624e-44, /* 0x36E38222, 0x80000000 */
      2.16741683877804819444e-51  /* 0x3569F31D, 0x00000000 */
  };

  /*
   * Table of constants for 2/pi, 396 Hex digits (476 decimal) of 2/pi
   */
  static const int32_t two_over_pi[] = {
      IC(0xA2F983), IC(0x6E4E44), IC(0x1529FC), IC(0x2757D1), IC(0xF534DD),
      IC(0xC0DB62), IC(0x95993C), IC(0x439041), IC(0xFE5163), IC(0xABDEBB),
      IC(0xC561B7), IC(0x246E3A), IC(0x424DD2), IC(0xE00649), IC(0x2EEA09),
      IC(0xD1921C), IC(0xFE1DEB), IC(0x1CB129), IC(0xA73EE8), IC(0x8235F5),
      IC(0x2EBB44), IC(0x84E99C), IC(0x7026B4), IC(0x5F7E41), IC(0x3991D6),
      IC(0x398353), IC(0x39F49C), IC(0x845F8B), IC(0xBDF928), IC(0x3B1FF8),
      IC(0x97FFDE), IC(0x05980F), IC(0xEF2F11), IC(0x8B5A0A), IC(0x6D1F6D),
      IC(0x367ECF), IC(0x27CB09), IC(0xB74F46), IC(0x3F669E), IC(0x5FEA2D),
      IC(0x7527BA), IC(0xC7EBE5), IC(0xF17B3D), IC(0x0739F7), IC(0x8A5292),
      IC(0xEA6BFB), IC(0x5FB11F), IC(0x8D5D08), IC(0x560330), IC(0x46FC7B),
      IC(0x6BABF0), IC(0xCFBC20), IC(0x9AF436), IC(0x1DA9E3), IC(0x91615E),
      IC(0xE61B08), IC(0x659985), IC(0x5F14A0), IC(0x68408D), IC(0xFFD880),
      IC(0x4D7327), IC(0x310606), IC(0x1556CA), IC(0x73A8C9), IC(0x60E27B),
      IC(0xC08C6B)};

  static const double zero = 0.0;
  static const double one = 1.0;
  static const double two24 =
      1.67772160000000000000e+07; /* 0x41700000, 0x00000000 */
  static const double twon24 =
      5.96046447753906250000e-08; /* 0x3E700000, 0x00000000 */

  /* initialize jk */
  jk = init_jk[prec];
  jp = jk;

  /* determine jx,jv,q0, note that 3>q0 */
  jx = nx - 1;
  jv = (e0 - 3) / 24;
  if (jv < 0) {
    jv = 0;
  }

  q0 = e0 - 24 * (jv + 1);

  /* set up f[0] to f[jx+jk] where f[jx+jk] = two_over_pi[jv+jk] */
  j = jv - jx;
  m = jx + jk;
  for (i = 0; i <= m; i++, j++) {
    double temp_var_for_const_0, temp_var_for_const_1;
    f[i] = (j < 0) ? zero : (double)two_over_pi[j];
    AssignD({(Addr) &(temp_var_for_const_1 = f[i])},
            (Addr) &(temp_var_for_const_0 =
                         (j < 0) ? zero : (double)two_over_pi[j]),
            "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:193:10");
    ;
  }

  /* compute q[0],q[1],...q[jk] */
  for (i = 0; i <= jk; i++) {
    for (j = 0, fw = 0.0; j <= jx; j++) {
      fw += double temp_var_for_tac_0;
      double temp_var_for_const_2, temp_var_for_const_3;
      temp_var_for_tac_0 = x[j] * f[jx + i - j];

      ;
    }

    double temp_var_for_const_4;
    q[i] = fw;
    computeDMul((Addr)&temp_var_for_tac_0,
                {(Addr) &(temp_var_for_const_3 = x[j]),
                 (Addr) &(temp_var_for_const_2 = f[jx + i - j])},
                "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:199:18");
    AssignD({(Addr) &(temp_var_for_const_4 = q[i])}, (Addr)&fw,
            "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:202:10");
    ;
  }

  jz = jk;
recompute:
  /* distill q[] into iq[] reversingly */
  {
    for (i = 0, j = jz, z = q[jz]; j > 0; i++, j--) {
      double temp_var_for_tac_1;
      double temp_var_for_const_5, temp_var_for_const_6;
      temp_var_for_tac_1 = twon24 * z;

      fw = ((double)((int32_t)temp_var_for_tac_1));
      computeDMul((Addr)&temp_var_for_tac_1,
                  {(Addr) &(temp_var_for_const_5 = twon24), (Addr)&z},
                  "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:210:38");
      AssignD({(Addr)&fw},
              (Addr) &(temp_var_for_const_6 =
                           ((double)((int32_t)temp_var_for_tac_1))),
              "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:210:10");
      ;
      iq[i] = (int32_t)(double temp_var_for_tac_2, temp_var_for_tac_3;
                        double temp_var_for_const_7;
                        temp_var_for_tac_2 = two24 * fw;

                        temp_var_for_tac_3 = z - temp_var_for_tac_2;

                        );
      double temp_var_for_ext_0;
      double temp_var_for_tac_4;
      double temp_var_for_const_8;
      temp_var_for_tac_4 = q[j - 1] + fw;

      temp_var_for_ext_0 = temp_var_for_tac_4;
      computeDMul((Addr)&temp_var_for_tac_2,
                  {(Addr) &(temp_var_for_const_7 = two24), (Addr)&fw},
                  "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:211:35");
      computeDSub((Addr)&temp_var_for_tac_3,
                  {(Addr)&z, (Addr)&temp_var_for_tac_2},
                  "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:211:27");
      computeDAdd((Addr)&temp_var_for_tac_4,
                  {(Addr) &(temp_var_for_const_8 = q[j - 1]), (Addr)&fw},
                  "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:213:37");
      AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_4,
              "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:213:26");
      ; // z
      /*(z)(twon24)(fw)(two24)(z)(fw)(two24)(fw)(q)(1)(j)(q[TempNull])*/
      z = temp_var_for_ext_0;
      AssignD({(Addr)&z}, (Addr)&temp_var_for_ext_0,
              "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:215:9");
      ;
    }
  }

  /* compute n */
  double temp_var_for_const_9;
  double temp_var_for_callexp_0;

  temp_var_for_callexp_0 = __ieee754_scalbn(z, ((int)q0));
  z = temp_var_for_callexp_0;
  AssignD({(Addr)&z}, (Addr) &(temp_var_for_const_9 = temp_var_for_callexp_0),
          "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:220:5");
  ; /* actual value of z */
  double temp_var_for_tac_5, temp_var_for_tac_6;
  double temp_var_for_const_10, temp_var_for_const_11, temp_var_for_const_12;
  double temp_var_for_callexp_1;

  temp_var_for_tac_5 = z * 0.125;

  temp_var_for_callexp_1 = __ieee754_floor(temp_var_for_tac_5);
  temp_var_for_tac_6 = 8.0 * temp_var_for_callexp_1;

  z -= temp_var_for_tac_6;
  ; /* trim off integer >= 8 */
  n = (int32_t)z;
  z -= ((double)n);
  ;
  ih = 0;
  if (q0 > 0) { /* need iq[jz-1] to determine n */
    i = (iq[jz - 1] >> (24 - q0));
    n += i;
    iq[jz - 1] -= i << (24 - q0);
    ih = iq[jz - 1] >> (23 - q0);
  } else {
    if (q0 == 0) {
      ih = iq[jz - 1] >> 23;
    } else {
      if (int temp_var_for_tac_9; int temp_var_for_const_13;
          temp_var_for_tac_9 = z >= 0.5;

          ) {
        ih = 2;
      }
    }
  }

  if (ih > 0) { /* q > 0.5 */
    n += 1;
    carry = 0;
    for (i = 0; i < jz; i++) { /* compute 1-q */
      j = iq[i];
      if (carry == 0) {
        if (j != 0) {
          carry = 1;
          iq[i] = IC(0x1000000) - j;
        }
      } else {
        iq[i] = IC(0xffffff) - j;
      }
    }
    if (q0 > 0) { /* rare case: chance is 1 in 12 */
      int temp_var_for_ext_1;
      temp_var_for_ext_1 = (int)q0;
      switch (temp_var_for_ext_1) {
      case 1: {
        iq[jz - 1] &= IC(0x7fffff);
      }

      break;
      case 2: {
        iq[jz - 1] &= IC(0x3fffff);
      }

      break;
      }
    }
    if (ih == 2) {
      double temp_var_for_ext_2;
      double temp_var_for_tac_10;
      double temp_var_for_const_14;
      temp_var_for_tac_10 = one - z;

      temp_var_for_ext_2 = temp_var_for_tac_10;
      computeDMul((Addr)&temp_var_for_tac_5,
                  {(Addr)&z, (Addr) &(temp_var_for_const_10 = 0.125)},
                  "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:221:32");
      computeDMul((Addr)&temp_var_for_tac_6,
                  {(Addr) &(temp_var_for_const_12 = 8.0),
                   (Addr) &(temp_var_for_const_11 = temp_var_for_callexp_1)},
                  "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:221:12");
      compute((Addr)&temp_var_for_tac_9,
              {(Addr)&z, (Addr) &(temp_var_for_const_13 = 0.5)},
              "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:234:13");
      computeDSub((Addr)&temp_var_for_tac_10,
                  {(Addr) &(temp_var_for_const_14 = one), (Addr)&z},
                  "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:272:32");
      AssignD({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_10,
              "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:272:26");
      ; // z
        /*(__ieee754_floor(z * 0.125))(8.0)(z)(__ieee754_floor(z *
         * 0.125))(8.0)(0.125)(z)(n)(n)(z)(z)(one)*/
      z = temp_var_for_ext_2;
      AssignD({(Addr)&z}, (Addr)&temp_var_for_ext_2,
              "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:275:9");
      ;
      if (carry != 0) {
        double temp_var_for_callexp_2;

        temp_var_for_callexp_2 = __ieee754_scalbn(one, ((int)q0));
        z -= temp_var_for_callexp_2;
        ;
      }
    }
  }

  /* check if recomputation is needed */
  if (int temp_var_for_tac_12; int temp_var_for_const_15;
      temp_var_for_tac_12 = z == zero;

      ) {
    j = 0;
    for (i = jz - 1; i >= jk; i--) {
      j |= iq[i];
    }

    if (j == 0) {                       /* need recomputation */
      for (k = 1; iq[jk - k] == 0; k++) /* k = no. of terms needed */
      {
        ;
      }

      for (i = jz + 1; i <= jz + k; i++) { /* add q[jz+1] to q[jz+k] */
        double temp_var_for_const_16, temp_var_for_const_17;
        f[jx + i] = ((double)two_over_pi[jv + i]);
        compute((Addr)&temp_var_for_tac_12,
                {(Addr)&z, (Addr) &(temp_var_for_const_15 = zero)},
                "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:283:9");
        AssignD({(Addr) &(temp_var_for_const_17 = f[jx + i])},
                (Addr) &(temp_var_for_const_16 = ((double)two_over_pi[jv + i])),
                "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:296:19");
        ;
        for (j = 0, fw = 0.0; j <= jx; j++) {
          double temp_var_for_tac_13;
          double temp_var_for_const_18, temp_var_for_const_19;
          temp_var_for_tac_13 = x[j] * f[jx + i - j];

          fw += temp_var_for_tac_13;
          ;
        }

        double temp_var_for_const_20;
        q[i] = fw;
        computeDMul((Addr)&temp_var_for_tac_13,
                    {(Addr) &(temp_var_for_const_19 = x[j]),
                     (Addr) &(temp_var_for_const_18 = f[jx + i - j])},
                    "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:298:22");
        AssignD({(Addr) &(temp_var_for_const_20 = q[i])}, (Addr)&fw,
                "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:301:14");
        ;
      }
      jz += k;
      goto recompute;
    }
  }

  /* chop off zero terms */
  if (int temp_var_for_tac_15; int temp_var_for_const_21;
      temp_var_for_tac_15 = z == 0.0;

      ) {
    jz -= 1;
    q0 -= 24;
    int temp_var_for_ext_3;
    temp_var_for_ext_3 = iq[jz] == 0;
    while (temp_var_for_ext_3) {
      jz--;
      q0 -= 24;
      temp_var_for_ext_3 = iq[jz] == 0;
    }
  } else { /* break z into 24-bit if necessary */
    double temp_var_for_const_22;
    double temp_var_for_callexp_3;

    temp_var_for_callexp_3 = __ieee754_scalbn(z, ((int)(-(q0))));
    z = temp_var_for_callexp_3;
    compute((Addr)&temp_var_for_tac_15,
            {(Addr)&z, (Addr) &(temp_var_for_const_21 = 0.0)},
            "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:309:9");
    AssignD({(Addr)&z},
            (Addr) &(temp_var_for_const_22 = temp_var_for_callexp_3),
            "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:320:7");
    ;
    if (int temp_var_for_tac_16; int temp_var_for_const_23;
        temp_var_for_tac_16 = z >= two24;

        ) {
      double temp_var_for_tac_17;
      double temp_var_for_const_24, temp_var_for_const_25;
      temp_var_for_tac_17 = twon24 * z;

      fw = ((double)((int32_t)temp_var_for_tac_17));
      compute((Addr)&temp_var_for_tac_16,
              {(Addr)&z, (Addr) &(temp_var_for_const_23 = two24)},
              "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:321:11");
      computeDMul((Addr)&temp_var_for_tac_17,
                  {(Addr) &(temp_var_for_const_24 = twon24), (Addr)&z},
                  "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:322:38");
      AssignD({(Addr)&fw},
              (Addr) &(temp_var_for_const_25 =
                           ((double)((int32_t)temp_var_for_tac_17))),
              "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:322:10");
      ;
      iq[jz] = (int32_t)(double temp_var_for_tac_18, temp_var_for_tac_19;
                         double temp_var_for_const_26;
                         temp_var_for_tac_18 = two24 * fw;

                         temp_var_for_tac_19 = z - temp_var_for_tac_18;

                         );
      jz += 1;
      q0 += 24;
      iq[jz] = (int32_t)fw;
    } else {
      iq[jz] = (int32_t)z;
    }
  }

  /* convert integer "bit" chunk to floating-point value */
  double temp_var_for_ext_4;
  double temp_var_for_const_27;
  double temp_var_for_callexp_4;

  temp_var_for_callexp_4 = __ieee754_scalbn(one, ((int)q0));
  temp_var_for_ext_4 = temp_var_for_callexp_4;
  computeDMul((Addr)&temp_var_for_tac_18,
              {(Addr) &(temp_var_for_const_26 = two24), (Addr)&fw},
              "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:323:36");
  computeDSub((Addr)&temp_var_for_tac_19,
              {(Addr)&z, (Addr)&temp_var_for_tac_18},
              "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:323:28");
  AssignD({(Addr)&temp_var_for_ext_4},
          (Addr) &(temp_var_for_const_27 = temp_var_for_callexp_4),
          "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:334:22");
  ; // fw
  /*(z)(twon24)(fw)(two24)(z)(fw)(two24)(__ieee754_scalbn(one, (int)q0))*/
  fw = temp_var_for_ext_4;
  AssignD({(Addr)&fw}, (Addr)&temp_var_for_ext_4,
          "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:336:6");
  ;
  for (i = jz; i >= 0; i--) {
    double temp_var_for_tac_20;
    double temp_var_for_const_28, temp_var_for_const_29;
    temp_var_for_tac_20 = fw * ((double)iq[i]);

    q[i] = temp_var_for_tac_20;
    computeDMul((Addr)&temp_var_for_tac_20,
                {(Addr)&fw, (Addr) &(temp_var_for_const_28 = ((double)iq[i]))},
                "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:338:15");
    AssignD({(Addr) &(temp_var_for_const_29 = q[i])},
            (Addr)&temp_var_for_tac_20,
            "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:338:10");
    ;
    fw *= twon24;
    ;
  }

  /* compute PIo2[0,...,jp]*q[jz,...,0] */
  for (i = jz; i >= 0; i--) {
    for (double temp_var_for_ext_5; temp_var_for_ext_5 = 0.0, k = 0;
         k <= jp && k <= jz - i; k++) {
      fw += PIo2[k] * q[i + k];
    }

    fq[jz - i] = fw;
  }

  /* compress fq[] into y[] */
  int temp_var_for_ext_6;
  temp_var_for_ext_6 = prec;
  switch (temp_var_for_ext_6) {
  case 0: {
    double temp_var_for_const_30;
    fw = 0.0;
    AssignD({(Addr)&fw}, (Addr) &(temp_var_for_const_30 = 0.0),
            "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:357:8");
    ;
  }

    for (i = jz; i >= 0; i--) {
      fw += fq[i];
      ;
    }

    double temp_var_for_const_31, temp_var_for_const_32;
    y[0] = (ih == 0) ? fw : (0.0 - fw);
    AssignD({(Addr) &(temp_var_for_const_32 = y[0])},
            (Addr) &(temp_var_for_const_31 = (ih == 0) ? fw : (0.0 - fw)),
            "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:364:10");
    ;
    break;
  case 1: {
  case 2: {
    volatile double fv = 0.0;

    for (i = jz; i >= 0; i--) {
      fv += fq[i];
    }

    y[0] =
        (ih == 0) ? fv : (double temp_var_for_tac_23;
                          double temp_var_for_const_33, temp_var_for_const_34;
                          temp_var_for_tac_23 = 0.0 - fv;

                          );
    double temp_var_for_ext_7;
    double temp_var_for_tac_24;
    double temp_var_for_const_35, temp_var_for_const_36;
    temp_var_for_tac_24 = fq[0] - fv;

    temp_var_for_ext_7 = temp_var_for_tac_24;
    computeDSub((Addr)&temp_var_for_tac_23,
                {(Addr) &(temp_var_for_const_34 = 0.0),
                 (Addr) &(temp_var_for_const_33 = fv)},
                "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:374:34");
    computeDSub((Addr)&temp_var_for_tac_24,
                {(Addr) &(temp_var_for_const_36 = fq[0]),
                 (Addr) &(temp_var_for_const_35 = fv)},
                "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:376:32");
    AssignD({(Addr)&temp_var_for_ext_7}, (Addr)&temp_var_for_tac_24,
            "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:376:24");
    ; // fv
    /*(fv)(fq)(0)(fq[0])*/
    fv = temp_var_for_ext_7;
    for (i = 1; i <= jz; i++) {
      fv += fq[i];
    }

    double temp_var_for_const_37, temp_var_for_const_38;
    y[1] = (ih == 0) ? fv : (0.0 - fv);
    AssignD({(Addr) &(temp_var_for_const_38 = y[1])},
            (Addr) &(temp_var_for_const_37 = (ih == 0) ? fv : (0.0 - fv)),
            "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:383:10");
    ;
  }
  }

  break;
  case 3: /* painful */
  {
    for (i = jz; i > 0; i--) {
      volatile double fv = (double)(fq[i - 1] + fq[i]);

      double temp_var_for_tac_25;
      double temp_var_for_const_39, temp_var_for_const_40;
      temp_var_for_tac_25 = fq[i - 1] - fv;

      fq[i] += temp_var_for_tac_25;
      ;
      double temp_var_for_const_41, temp_var_for_const_42;
      fq[i - 1] = fv;
      computeDSub((Addr)&temp_var_for_tac_25,
                  {(Addr) &(temp_var_for_const_40 = fq[i - 1]),
                   (Addr) &(temp_var_for_const_39 = fv)},
                  "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:393:26");
      AssignD({(Addr) &(temp_var_for_const_42 = fq[i - 1])},
              (Addr) &(temp_var_for_const_41 = fv),
              "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:394:17");
      ;
    }
  }

    for (i = jz; i > 1; i--) {
      volatile double fv =
          (double)(double temp_var_for_tac_27;
                   double temp_var_for_const_43, temp_var_for_const_44;
                   temp_var_for_tac_27 = fq[i - 1] + fq[i];

                   );

      double temp_var_for_tac_28;
      double temp_var_for_const_45, temp_var_for_const_46;
      temp_var_for_tac_28 = fq[i - 1] - fv;

      fq[i] += temp_var_for_tac_28;
      ;
      double temp_var_for_const_47, temp_var_for_const_48;
      fq[i - 1] = fv;
      computeDAdd((Addr)&temp_var_for_tac_27,
                  {(Addr) &(temp_var_for_const_44 = fq[i - 1]),
                   (Addr) &(temp_var_for_const_43 = fq[i])},
                  "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:399:47");
      computeDSub((Addr)&temp_var_for_tac_28,
                  {(Addr) &(temp_var_for_const_46 = fq[i - 1]),
                   (Addr) &(temp_var_for_const_45 = fv)},
                  "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:401:26");
      AssignD({(Addr) &(temp_var_for_const_48 = fq[i - 1])},
              (Addr) &(temp_var_for_const_47 = fv),
              "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:402:17");
      ;
    }
    for (fw = 0.0, i = jz; i >= 2; i--) {
      fw += fq[i];
      ;
    }

    if (ih == 0) {
      double temp_var_for_const_49, temp_var_for_const_50;
      y[0] = fq[0];
      AssignD({(Addr) &(temp_var_for_const_50 = y[0])},
              (Addr) &(temp_var_for_const_49 = fq[0]),
              "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:409:12");
      ;
      double temp_var_for_const_51, temp_var_for_const_52;
      y[1] = fq[1];
      AssignD({(Addr) &(temp_var_for_const_52 = y[1])},
              (Addr) &(temp_var_for_const_51 = fq[1]),
              "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:410:12");
      ;
      double temp_var_for_const_53;
      y[2] = fw;
      AssignD({(Addr) &(temp_var_for_const_53 = y[2])}, (Addr)&fw,
              "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:411:12");
      ;
    } else {
      double temp_var_for_tac_31;
      double temp_var_for_const_54, temp_var_for_const_55,
          temp_var_for_const_56;
      temp_var_for_tac_31 = 0.0 - fq[0];

      y[0] = temp_var_for_tac_31;
      computeDSub((Addr)&temp_var_for_tac_31,
                  {(Addr) &(temp_var_for_const_55 = 0.0),
                   (Addr) &(temp_var_for_const_54 = fq[0])},
                  "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:413:19");
      AssignD({(Addr) &(temp_var_for_const_56 = y[0])},
              (Addr)&temp_var_for_tac_31,
              "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:413:12");
      ;
      double temp_var_for_tac_32;
      double temp_var_for_const_57, temp_var_for_const_58,
          temp_var_for_const_59;
      temp_var_for_tac_32 = 0.0 - fq[1];

      y[1] = temp_var_for_tac_32;
      computeDSub((Addr)&temp_var_for_tac_32,
                  {(Addr) &(temp_var_for_const_58 = 0.0),
                   (Addr) &(temp_var_for_const_57 = fq[1])},
                  "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:414:19");
      AssignD({(Addr) &(temp_var_for_const_59 = y[1])},
              (Addr)&temp_var_for_tac_32,
              "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:414:12");
      ;
      double temp_var_for_tac_33;
      double temp_var_for_const_60, temp_var_for_const_61;
      temp_var_for_tac_33 = 0.0 - fw;

      y[2] = temp_var_for_tac_33;
      computeDSub((Addr)&temp_var_for_tac_33,
                  {(Addr) &(temp_var_for_const_60 = 0.0), (Addr)&fw},
                  "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:415:19");
      AssignD({(Addr) &(temp_var_for_const_61 = y[2])},
              (Addr)&temp_var_for_tac_33,
              "/home/shijia/Public/testprogram/k_rem_pio2.c_e.c:415:12");
      ;
    }
  }
  return n & 7;
}
