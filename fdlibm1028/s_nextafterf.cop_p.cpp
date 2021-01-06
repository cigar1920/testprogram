#include "../ScDebug/scdebug.h"
/* s_nextafterf.c -- float version of s_nextafter.c.
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

float __nextafterf(float x, float y) {
  int32_t hx, hy, ix, iy;

  GET_FLOAT_WORD(hx, x);
  GET_FLOAT_WORD(hy, y);
  ix = hx & IC(0x7fffffff); /* |x| */
  iy = hy & IC(0x7fffffff); /* |y| */

  if ((ix > IC(0x7f800000)) || /* x is nan */
      (iy > IC(0x7f800000)))   /* y is nan */
  {
    float temp_var_for_ext_0;
    float temp_var_for_tac_0;
    temp_var_for_tac_0 = x + y;

    temp_var_for_ext_0 = temp_var_for_tac_0;
    computeFAdd((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&y},
                "/home/shijia/Public/testprogram/s_nextafterf.c_e.c:32:28");
    AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_0,
            "/home/shijia/Public/testprogram/s_nextafterf.c_e.c:32:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  if (int temp_var_for_tac_1; temp_var_for_tac_1 = x == y;

      ) {
    float temp_var_for_ext_1;
    temp_var_for_ext_1 = y;
    compute((Addr)&temp_var_for_tac_1, {(Addr)&x, (Addr)&y},
            "/home/shijia/Public/testprogram/s_nextafterf.c_e.c:38:9");
    AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&y,
            "/home/shijia/Public/testprogram/s_nextafterf.c_e.c:40:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }
  /* x=y, return y */
  if (ix == 0) { /* x == 0 */
    float u;

    SET_FLOAT_WORD(x, (hy & IC(0x80000000)) | 1); /* return +-minsubnormal */
    float temp_var_for_const_0;
    u = math_opt_barrier(x);
    AssignF({(Addr)&u}, (Addr) &(temp_var_for_const_0 = math_opt_barrier(x)),
            "/home/shijia/Public/testprogram/s_nextafterf.c_e.c:50:7");
    ;
    float temp_var_for_ext_2;
    float temp_var_for_tac_2;
    temp_var_for_tac_2 = u * u;

    temp_var_for_ext_2 = temp_var_for_tac_2;
    computeFMul((Addr)&temp_var_for_tac_2, {(Addr)&u, (Addr)&u},
                "/home/shijia/Public/testprogram/s_nextafterf.c_e.c:52:28");
    AssignF({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_2,
            "/home/shijia/Public/testprogram/s_nextafterf.c_e.c:52:24");
    ; // u
    /*(u)(u)*/
    u = temp_var_for_ext_2;
    AssignF({(Addr)&u}, (Addr)&temp_var_for_ext_2,
            "/home/shijia/Public/testprogram/s_nextafterf.c_e.c:54:7");
    ;
    math_force_eval(u); /* raise underflow flag */
    float temp_var_for_ext_3;
    temp_var_for_ext_3 = x;
    AssignF({(Addr)&temp_var_for_ext_3}, (Addr)&x,
            "/home/shijia/Public/testprogram/s_nextafterf.c_e.c:57:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_3;
  }
  if (hx >= 0) {   /* x > 0 */
    if (hx > hy) { /* x > y, x -= ulp */
      hx -= 1;
    } else { /* x < y, x += ulp */
      hx += 1;
    }
  } else {                    /* x < 0 */
    if (hy >= 0 || hx > hy) { /* x < y, x -= ulp */
      hx -= 1;
    } else { /* x > y, x += ulp */
      hx += 1;
    }
  }
  hy = hx & IC(0x7f800000);
  if (hy >= IC(0x7f800000)) {
    float temp_var_for_ext_4;
    float temp_var_for_tac_3;
    temp_var_for_tac_3 = x + x;

    temp_var_for_ext_4 = temp_var_for_tac_3;
    computeFAdd((Addr)&temp_var_for_tac_3, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/s_nextafterf.c_e.c:78:28");
    AssignF({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_3,
            "/home/shijia/Public/testprogram/s_nextafterf.c_e.c:78:24");
    ; // x
    /*(u)(u)(x)(x)*/
    x = temp_var_for_ext_4;
    AssignF({(Addr)&x}, (Addr)&temp_var_for_ext_4,
            "/home/shijia/Public/testprogram/s_nextafterf.c_e.c:80:7");
    ; /* overflow  */
    math_force_eval(x);
    float temp_var_for_ext_5;
    temp_var_for_ext_5 = x;
    AssignF({(Addr)&temp_var_for_ext_5}, (Addr)&x,
            "/home/shijia/Public/testprogram/s_nextafterf.c_e.c:83:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
    callExp++;                 /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_5; /* overflow  */
  }
  if (hy < IC(0x00800000)) {
    float u = float temp_var_for_tac_4;
    temp_var_for_tac_4 = x * x;

    ;                   /* underflow */
    math_force_eval(u); /* raise underflow flag */
  }
  SET_FLOAT_WORD(x, hx);
  float temp_var_for_ext_6;
  temp_var_for_ext_6 = x;
  computeFMul((Addr)&temp_var_for_tac_4, {(Addr)&x, (Addr)&x},
              "/home/shijia/Public/testprogram/s_nextafterf.c_e.c:89:17");
  AssignF({(Addr)&temp_var_for_ext_6}, (Addr)&x,
          "/home/shijia/Public/testprogram/s_nextafterf.c_e.c:94:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_6;
}

__typeof(__nextafterf) nextafterf __attribute__((weak, alias("__nextafterf")));
