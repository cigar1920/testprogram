#include "../ScDebug/scdebug.h"
/* @(#)s_nextafter.c 1.3 95/01/18 */
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

/* IEEE functions
 *	nextafter(x,y)
 *	return the next machine floating-point number of x in the
 *	direction toward y.
 *   Special cases:
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

double __nextafter(double x, double y) {
  int32_t hx, hy, ix, iy;
  uint32_t lx, ly;

  GET_DOUBLE_WORDS(hx, lx, x);
  GET_DOUBLE_WORDS(hy, ly, y);
  ix = hx & IC(0x7fffffff); /* |x| */
  iy = hy & IC(0x7fffffff); /* |y| */

  if (((ix >= IC(0x7ff00000)) &&
       ((ix - IC(0x7ff00000)) | lx) != 0) || /* x is nan */
      ((iy >= IC(0x7ff00000)) &&
       ((iy - IC(0x7ff00000)) | ly) != 0)) /* y is nan */
  {
    double temp_var_for_ext_0;
    double temp_var_for_tac_0;
    temp_var_for_tac_0 = x + y;

    temp_var_for_ext_0 = temp_var_for_tac_0;
    computeDAdd((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&y},
                "/home/shijia/Public/testprogram/s_nextafter.c_e.c:39:28");
    AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_0,
            "/home/shijia/Public/testprogram/s_nextafter.c_e.c:39:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  if (int temp_var_for_tac_1; temp_var_for_tac_1 = x == y;

      ) {
    double temp_var_for_ext_1;
    temp_var_for_ext_1 = x;
    compute((Addr)&temp_var_for_tac_1, {(Addr)&x, (Addr)&y},
            "/home/shijia/Public/testprogram/s_nextafter.c_e.c:45:9");
    AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&x,
            "/home/shijia/Public/testprogram/s_nextafter.c_e.c:47:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }
  /* x=y, return x */
  if ((ix | lx) == 0) { /* x == 0 */
    double u;

    INSERT_WORDS(x, hy & UC(0x80000000), 1); /* return +-minsubnormal */
    double temp_var_for_const_0;
    u = math_opt_barrier(x);
    AssignD({(Addr)&u}, (Addr) &(temp_var_for_const_0 = math_opt_barrier(x)),
            "/home/shijia/Public/testprogram/s_nextafter.c_e.c:57:7");
    ;
    double temp_var_for_ext_2;
    double temp_var_for_tac_2;
    temp_var_for_tac_2 = u * u;

    temp_var_for_ext_2 = temp_var_for_tac_2;
    computeDMul((Addr)&temp_var_for_tac_2, {(Addr)&u, (Addr)&u},
                "/home/shijia/Public/testprogram/s_nextafter.c_e.c:59:28");
    AssignD({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_2,
            "/home/shijia/Public/testprogram/s_nextafter.c_e.c:59:24");
    ; // u
    /*(u)(u)*/
    u = temp_var_for_ext_2;
    AssignD({(Addr)&u}, (Addr)&temp_var_for_ext_2,
            "/home/shijia/Public/testprogram/s_nextafter.c_e.c:61:7");
    ;
    math_force_eval(u); /* raise underflow flag */
    double temp_var_for_ext_3;
    temp_var_for_ext_3 = x;
    AssignD({(Addr)&temp_var_for_ext_3}, (Addr)&x,
            "/home/shijia/Public/testprogram/s_nextafter.c_e.c:64:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_3;
  }
  if (hx >= 0) {                                /* x > 0 */
    if (hx > hy || ((hx == hy) && (lx > ly))) { /* x > y, x -= ulp */
      if (lx == 0) {
        hx -= 1;
      }

      lx -= 1;
    } else { /* x < y, x += ulp */
      lx += 1;
      if (lx == 0) {
        hx += 1;
      }
    }
  } else {                                                 /* x < 0 */
    if (hy >= 0 || hx > hy || ((hx == hy) && (lx > ly))) { /* x < y, x -= ulp */
      if (lx == 0) {
        hx -= 1;
      }

      lx -= 1;
    } else { /* x > y, x += ulp */
      lx += 1;
      if (lx == 0) {
        hx += 1;
      }
    }
  }
  hy = hx & IC(0x7ff00000);
  if (hy >= IC(0x7ff00000)) {
    double temp_var_for_ext_4;
    double temp_var_for_tac_3;
    temp_var_for_tac_3 = x + x;

    temp_var_for_ext_4 = temp_var_for_tac_3;
    computeDAdd((Addr)&temp_var_for_tac_3, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/s_nextafter.c_e.c:99:28");
    AssignD({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_3,
            "/home/shijia/Public/testprogram/s_nextafter.c_e.c:99:24");
    ; // x
    /*(u)(u)(x)(x)*/
    x = temp_var_for_ext_4;
    AssignD({(Addr)&x}, (Addr)&temp_var_for_ext_4,
            "/home/shijia/Public/testprogram/s_nextafter.c_e.c:101:7");
    ; /* overflow  */
    math_force_eval(x);
    double temp_var_for_ext_5;
    temp_var_for_ext_5 = x;
    AssignD({(Addr)&temp_var_for_ext_5}, (Addr)&x,
            "/home/shijia/Public/testprogram/s_nextafter.c_e.c:104:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
    callExp++;                 /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_5; /* overflow  */
  }
  if (hy < IC(0x00100000)) {
    double u = double temp_var_for_tac_4;
    temp_var_for_tac_4 = x * x;

    ;                   /* underflow */
    math_force_eval(u); /* raise underflow flag */
  }
  INSERT_WORDS(x, hx, lx);
  double temp_var_for_ext_6;
  temp_var_for_ext_6 = x;
  computeDMul((Addr)&temp_var_for_tac_4, {(Addr)&x, (Addr)&x},
              "/home/shijia/Public/testprogram/s_nextafter.c_e.c:110:18");
  AssignD({(Addr)&temp_var_for_ext_6}, (Addr)&x,
          "/home/shijia/Public/testprogram/s_nextafter.c_e.c:115:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_6;
}

__typeof(__nextafter) nextafter __attribute__((weak, alias("__nextafter")));
#ifdef __NO_LONG_DOUBLE_MATH
__typeof(nextafterl) __nextafterl __attribute__((alias("__nextafter")));
__typeof(__nextafterl) nextafterl __attribute__((weak, alias("__nextafter")));
__typeof(__nexttoward) __nexttoward __attribute__((alias("__nextafter")));
__typeof(nexttoward) nexttoward __attribute__((weak, alias("__nextafter")));
__typeof(__nexttowardl) __nexttowardl __attribute__((alias("__nextafterl")));
__typeof(nexttowardl) nexttowardl __attribute__((weak, alias("__nextafterl")));
#endif
