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

double __kernel_tan(double x, double y, int iy) {
  double z, r, v, w, s;
  int32_t ix, hx;

  static const double one =
      1.00000000000000000000e+00; /* 0x3FF00000, 0x00000000 */
  static const double pio4 =
      7.85398163397448278999e-01; /* 0x3FE921FB, 0x54442D18 */
  static const double pio4lo =
      3.06161699786838301793e-17; /* 0x3C81A626, 0x33145C07 */

  static const double T[] = {
    3.33333333333334091986e-01, /* 0x3FD55555, 0x55555563 */
    1.33333333333201242699e-01, /* 0x3FC11111, 0x1110FE7A */
    5.39682539762260521377e-02, /* 0x3FABA1BA, 0x1BB341FE */
    2.18694882948595424599e-02, /* 0x3F9664F4, 0x8406D637 */
    8.86323982359930005737e-03, /* 0x3F8226E3, 0xE96E8493 */
    3.59207910759131235356e-03, /* 0x3F6D6D22, 0xC9560328 */
    1.45620945432529025516e-03, /* 0x3F57DBC8, 0xFEE08315 */
    5.88041240820264096874e-04, /* 0x3F4344D8, 0xF2F26501 */
    2.46463134818469906812e-04, /* 0x3F3026F7, 0x1A8D1068 */
    7.81794442939557092300e-05, /* 0x3F147E88, 0xA03792A6 */
    7.14072491382608190305e-05, /* 0x3F12B80F, 0x32F0A7E9 */
    (0.0 - 1.85586374855275456654e-05);
  double temp_var_for_const_0, temp_var_for_const_1;
  ,                              /* 0xBEF375CB, 0xDB605373 */
      2.59073051863633712884e-05 /* 0x3EFB2A70, 0x74BF7AD4 */
};

GET_HIGH_WORD(hx, x);
ix = hx & IC(0x7fffffff); /* high word of |x| */
if (ix < IC(0x3e300000))  /* x < 2**-28 */
{
  if ((int32_t)x == 0) { /* generate inexact */
    uint32_t low;

    GET_LOW_WORD(low, x);
    if (((ix | low) | (iy + 1)) == 0)
      return one / __ieee754_fabs(x);
    else
      return (iy == 1) ? x : -one / x;
  }
}
if (ix >= IC(0x3FE59428)) { /* |x| >= 0.6744 */
  if (hx < 0) {
    x = -x;
    y = -y;
  }
  z = pio4 - x;
  w = pio4lo - y;
  x = z + w;
  y = 0.0;
}
z = x * x;
double temp_var_for_tac_0;
computeDSub((Addr)&temp_var_for_tac_0,
            {(Addr) &(temp_var_for_const_1 = 0.0),
             (Addr) &(temp_var_for_const_0 = 1.85586374855275456654e-05)},
            "/home/shijia/Public/testprogram/k_tan.c_e.c:99:9");
computeDMul((Addr)&z, {(Addr)&x, (Addr)&x},
            "/home/shijia/Public/testprogram/k_tan.c_e.c:99:5");
w = z * z;
computeDMul((Addr)&w, {(Addr)&z, (Addr)&z},
            "/home/shijia/Public/testprogram/k_tan.c_e.c:100:5");
/*
 * Break x^5*(T[1]+x^2*T[2]+...) into
 * x^5(T[1]+x^4*T[3]+...+x^20*T[11]) +
 * x^5(x^2*(T[2]+x^4*T[4]+...+x^22*[T12]))
 */
r = T[1] + w * (T[3] + w * (T[5] + w * (T[7] + w * (T[9] + w * T[11]))));
double temp_var_for_const_2, temp_var_for_const_3, temp_var_for_const_4,
    temp_var_for_const_5, temp_var_for_const_6, temp_var_for_const_7;
double temp_var_for_tac_1, temp_var_for_tac_2, temp_var_for_tac_3,
    temp_var_for_tac_4, temp_var_for_tac_5, temp_var_for_tac_6,
    temp_var_for_tac_7, temp_var_for_tac_8, temp_var_for_tac_9;
computeDMul((Addr)&temp_var_for_tac_1,
            {(Addr)&w, (Addr) &(temp_var_for_const_2 = T[11])},
            "/home/shijia/Public/testprogram/k_tan.c_e.c:106:60");
computeDAdd((Addr)&temp_var_for_tac_2,
            {(Addr) &(temp_var_for_const_3 = T[9]), (Addr)&temp_var_for_tac_1},
            "/home/shijia/Public/testprogram/k_tan.c_e.c:106:52");
computeDMul((Addr)&temp_var_for_tac_3, {(Addr)&w, (Addr)&temp_var_for_tac_2},
            "/home/shijia/Public/testprogram/k_tan.c_e.c:106:48");
computeDAdd((Addr)&temp_var_for_tac_4,
            {(Addr) &(temp_var_for_const_4 = T[7]), (Addr)&temp_var_for_tac_3},
            "/home/shijia/Public/testprogram/k_tan.c_e.c:106:40");
computeDMul((Addr)&temp_var_for_tac_5, {(Addr)&w, (Addr)&temp_var_for_tac_4},
            "/home/shijia/Public/testprogram/k_tan.c_e.c:106:36");
computeDAdd((Addr)&temp_var_for_tac_6,
            {(Addr) &(temp_var_for_const_5 = T[5]), (Addr)&temp_var_for_tac_5},
            "/home/shijia/Public/testprogram/k_tan.c_e.c:106:28");
computeDMul((Addr)&temp_var_for_tac_7, {(Addr)&w, (Addr)&temp_var_for_tac_6},
            "/home/shijia/Public/testprogram/k_tan.c_e.c:106:24");
computeDAdd((Addr)&temp_var_for_tac_8,
            {(Addr) &(temp_var_for_const_6 = T[3]), (Addr)&temp_var_for_tac_7},
            "/home/shijia/Public/testprogram/k_tan.c_e.c:106:16");
computeDMul((Addr)&temp_var_for_tac_9, {(Addr)&w, (Addr)&temp_var_for_tac_8},
            "/home/shijia/Public/testprogram/k_tan.c_e.c:106:12");
computeDAdd((Addr)&r,
            {(Addr) &(temp_var_for_const_7 = T[1]), (Addr)&temp_var_for_tac_9},
            "/home/shijia/Public/testprogram/k_tan.c_e.c:106:5");
v = z * (T[2] + w * (T[4] + w * (T[6] + w * (T[8] + w * (T[10] + w * T[12])))));
double temp_var_for_const_8, temp_var_for_const_9, temp_var_for_const_10,
    temp_var_for_const_11, temp_var_for_const_12, temp_var_for_const_13;
double temp_var_for_tac_10, temp_var_for_tac_11, temp_var_for_tac_12,
    temp_var_for_tac_13, temp_var_for_tac_14, temp_var_for_tac_15,
    temp_var_for_tac_16, temp_var_for_tac_17, temp_var_for_tac_18,
    temp_var_for_tac_19;
computeDMul((Addr)&temp_var_for_tac_10,
            {(Addr)&w, (Addr) &(temp_var_for_const_8 = T[12])},
            "/home/shijia/Public/testprogram/k_tan.c_e.c:108:62");
computeDAdd((Addr)&temp_var_for_tac_11, {(Addr) &(temp_var_for_const_9 = T[10]),
                                         (Addr)&temp_var_for_tac_10},
            "/home/shijia/Public/testprogram/k_tan.c_e.c:108:53");
computeDMul((Addr)&temp_var_for_tac_12, {(Addr)&w, (Addr)&temp_var_for_tac_11},
            "/home/shijia/Public/testprogram/k_tan.c_e.c:108:49");
computeDAdd((Addr)&temp_var_for_tac_13, {(Addr) &(temp_var_for_const_10 = T[8]),
                                         (Addr)&temp_var_for_tac_12},
            "/home/shijia/Public/testprogram/k_tan.c_e.c:108:41");
computeDMul((Addr)&temp_var_for_tac_14, {(Addr)&w, (Addr)&temp_var_for_tac_13},
            "/home/shijia/Public/testprogram/k_tan.c_e.c:108:37");
computeDAdd((Addr)&temp_var_for_tac_15, {(Addr) &(temp_var_for_const_11 = T[6]),
                                         (Addr)&temp_var_for_tac_14},
            "/home/shijia/Public/testprogram/k_tan.c_e.c:108:29");
computeDMul((Addr)&temp_var_for_tac_16, {(Addr)&w, (Addr)&temp_var_for_tac_15},
            "/home/shijia/Public/testprogram/k_tan.c_e.c:108:25");
computeDAdd((Addr)&temp_var_for_tac_17, {(Addr) &(temp_var_for_const_12 = T[4]),
                                         (Addr)&temp_var_for_tac_16},
            "/home/shijia/Public/testprogram/k_tan.c_e.c:108:17");
computeDMul((Addr)&temp_var_for_tac_18, {(Addr)&w, (Addr)&temp_var_for_tac_17},
            "/home/shijia/Public/testprogram/k_tan.c_e.c:108:13");
computeDAdd((Addr)&temp_var_for_tac_19, {(Addr) &(temp_var_for_const_13 = T[2]),
                                         (Addr)&temp_var_for_tac_18},
            "/home/shijia/Public/testprogram/k_tan.c_e.c:107:9");
computeDMul((Addr)&v, {(Addr)&z, (Addr)&temp_var_for_tac_19},
            "/home/shijia/Public/testprogram/k_tan.c_e.c:107:5");
s = z * x;
computeDMul((Addr)&s, {(Addr)&z, (Addr)&x},
            "/home/shijia/Public/testprogram/k_tan.c_e.c:109:5");
double temp_var_for_ext_0;
temp_var_for_ext_0 = y + z * (s * (r + v) + y);
double temp_var_for_tac_20, temp_var_for_tac_21, temp_var_for_tac_22,
    temp_var_for_tac_23;
computeDAdd((Addr)&temp_var_for_tac_20, {(Addr)&r, (Addr)&v},
            "/home/shijia/Public/testprogram/k_tan.c_e.c:111:35");
computeDMul((Addr)&temp_var_for_tac_21, {(Addr)&s, (Addr)&temp_var_for_tac_20},
            "/home/shijia/Public/testprogram/k_tan.c_e.c:111:45");
computeDAdd((Addr)&temp_var_for_tac_22, {(Addr)&temp_var_for_tac_21, (Addr)&y},
            "/home/shijia/Public/testprogram/k_tan.c_e.c:111:30");
computeDMul((Addr)&temp_var_for_tac_23, {(Addr)&z, (Addr)&temp_var_for_tac_22},
            "/home/shijia/Public/testprogram/k_tan.c_e.c:111:26");
computeDAdd((Addr)&temp_var_for_ext_0, {(Addr)&y, (Addr)&temp_var_for_tac_23},
            "/home/shijia/Public/testprogram/k_tan.c_e.c:111:22"); // r
/*(x)(z)(y)(v)(r)(s)(z)(y)*/
r = temp_var_for_ext_0;
AssignD({(Addr)&r}, (Addr)&temp_var_for_ext_0,
        "/home/shijia/Public/testprogram/k_tan.c_e.c:113:5");
r += T[0] * s;
double temp_var_for_const_14;
w = x + r;
double temp_var_for_tac_24;
computeDMul((Addr)&temp_var_for_tac_24,
            {(Addr) &(temp_var_for_const_14 = T[0]), (Addr)&s},
            "/home/shijia/Public/testprogram/k_tan.c_e.c:115:9");
computeDAdd((Addr)&w, {(Addr)&x, (Addr)&r},
            "/home/shijia/Public/testprogram/k_tan.c_e.c:115:5");
if (ix >= IC(0x3FE59428)) {
  v = (double)iy;
  return (double)(1 - ((hx >> 30) & 2)) *
         (v - 2.0 * (x - (w * w / (w + v) - r)));
}
if (iy == 1) {
  double temp_var_for_ext_1;
  temp_var_for_ext_1 = w;
  AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&w,
          "/home/shijia/Public/testprogram/k_tan.c_e.c:123:24");
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

else {
  /*
   * if allow error up to 2 ulp, simply return
   * -1.0 / (x+r) here
   */
  /* compute -1.0 / (x+r) accurately */
  double a, t;

  z = w;
  AssignD({(Addr)&z}, (Addr)&w,
          "/home/shijia/Public/testprogram/k_tan.c_e.c:137:7");
  SET_LOW_WORD(z, 0);
  v = r - (z - x);
  double temp_var_for_tac_25;
  computeDSub((Addr)&temp_var_for_tac_25, {(Addr)&z, (Addr)&x},
              "/home/shijia/Public/testprogram/k_tan.c_e.c:139:11");
  computeDSub(
      (Addr)&v, {(Addr)&r, (Addr)&temp_var_for_tac_25},
      "/home/shijia/Public/testprogram/k_tan.c_e.c:139:7"); /* z+v = r+x */
  t = a = (0.0 - 1.0) / w;
  double temp_var_for_const_15, temp_var_for_const_16;
  double temp_var_for_tac_26;
  computeDSub((Addr)&temp_var_for_tac_26,
              {(Addr) &(temp_var_for_const_16 = 0.0),
               (Addr) &(temp_var_for_const_15 = 1.0)},
              "/home/shijia/Public/testprogram/k_tan.c_e.c:140:25");
  computeDDiv((Addr)&a, {(Addr)&temp_var_for_tac_26, (Addr)&w},
              "/home/shijia/Public/testprogram/k_tan.c_e.c:140:11");
  AssignD({(Addr)&t}, (Addr)&a,
          "/home/shijia/Public/testprogram/k_tan.c_e.c:140:7"); /* a = -1.0/w */
  SET_LOW_WORD(t, 0);
  s = 1.0 + t * z;
  double temp_var_for_const_17;
  double temp_var_for_tac_27;
  computeDMul((Addr)&temp_var_for_tac_27, {(Addr)&t, (Addr)&z},
              "/home/shijia/Public/testprogram/k_tan.c_e.c:142:13");
  computeDAdd((Addr)&s, {(Addr) &(temp_var_for_const_17 = 1.0),
                         (Addr)&temp_var_for_tac_27},
              "/home/shijia/Public/testprogram/k_tan.c_e.c:142:7");
  double temp_var_for_ext_2;
  temp_var_for_ext_2 = t + a * (s + t * v);
  double temp_var_for_tac_28, temp_var_for_tac_29, temp_var_for_tac_30;
  computeDMul((Addr)&temp_var_for_tac_28, {(Addr)&t, (Addr)&v},
              "/home/shijia/Public/testprogram/k_tan.c_e.c:144:37");
  computeDAdd((Addr)&temp_var_for_tac_29,
              {(Addr)&s, (Addr)&temp_var_for_tac_28},
              "/home/shijia/Public/testprogram/k_tan.c_e.c:144:32");
  computeDMul((Addr)&temp_var_for_tac_30,
              {(Addr)&a, (Addr)&temp_var_for_tac_29},
              "/home/shijia/Public/testprogram/k_tan.c_e.c:144:28");
  computeDAdd((Addr)&temp_var_for_ext_2, {(Addr)&t, (Addr)&temp_var_for_tac_30},
              "/home/shijia/Public/testprogram/k_tan.c_e.c:144:24");
  callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_2;
}
}
