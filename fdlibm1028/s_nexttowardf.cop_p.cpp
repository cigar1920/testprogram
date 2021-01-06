#include "../ScDebug/scdebug.h"
/* s_nexttowardf.c -- float version of s_nextafter.c.
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

#ifndef __NO_LONG_DOUBLE_MATH

float __nexttowardf(float x, long double y) {
  int32_t hx, ix, iy;
  uint32_t hy, ly, esy;

  GET_FLOAT_WORD(hx, x);
  long double temp_var_for_const_0;
  ew_u.value = y;
  AssignLd({(Addr) &(temp_var_for_const_0 = ew_u.value)}, (Addr)&y,
           "/home/shijia/Public/testprogram/s_nexttowardf.c_e.c:27:3 "
           "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
  ;
  ix = hx & IC(0x7fffffff);              /* |x| */
  iy = esy & IEEE854_LONG_DOUBLE_MAXEXP; /* |y| */

  /* Intel's extended format has the normally implicit 1 explicit
     present.  Sigh!  */
  if ((ix > IC(0x7f800000)) || /* x is nan */
      (iy >= IEEE854_LONG_DOUBLE_MAXEXP &&
       (((hy & UC(0x7fffffff)) | ly) != 0))) /* y is nan */
  {
    float temp_var_for_ext_0;
    float temp_var_for_tac_0;
    temp_var_for_tac_0 = x + y;

    temp_var_for_ext_0 = temp_var_for_tac_0;
    computeLdAdd((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&y},
                 "/home/shijia/Public/testprogram/s_nexttowardf.c_e.c:38:28");
    AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_0,
            "/home/shijia/Public/testprogram/s_nexttowardf.c_e.c:38:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  if (int temp_var_for_tac_1; int temp_var_for_const_1;
      temp_var_for_tac_1 = ((long double)x) == y;

      ) {
    float temp_var_for_ext_1;
    temp_var_for_ext_1 = y;
    compute((Addr)&temp_var_for_tac_1,
            {(Addr) &(temp_var_for_const_1 = ((long double)x)), (Addr)&y},
            "/home/shijia/Public/testprogram/s_nexttowardf.c_e.c:44:22");
    AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&y,
            "/home/shijia/Public/testprogram/s_nexttowardf.c_e.c:46:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }
  /* x=y, return y */
  if (ix == 0) { /* x == 0 */
    float u;

    SET_FLOAT_WORD(x, ((esy & 0x8000) << 16) | 1); /* return +-minsub */
    float temp_var_for_const_2;
    u = math_opt_barrier(x);
    AssignF({(Addr)&u}, (Addr) &(temp_var_for_const_2 = math_opt_barrier(x)),
            "/home/shijia/Public/testprogram/s_nexttowardf.c_e.c:56:7");
    ;
    float temp_var_for_ext_2;
    float temp_var_for_tac_2;
    temp_var_for_tac_2 = u * u;

    temp_var_for_ext_2 = temp_var_for_tac_2;
    computeFMul((Addr)&temp_var_for_tac_2, {(Addr)&u, (Addr)&u},
                "/home/shijia/Public/testprogram/s_nexttowardf.c_e.c:58:28");
    AssignF({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_2,
            "/home/shijia/Public/testprogram/s_nexttowardf.c_e.c:58:24");
    ; // u
    /*(u)(u)*/
    u = temp_var_for_ext_2;
    AssignF({(Addr)&u}, (Addr)&temp_var_for_ext_2,
            "/home/shijia/Public/testprogram/s_nexttowardf.c_e.c:60:7");
    ;
    math_force_eval(u); /* raise underflow flag */
    float temp_var_for_ext_3;
    temp_var_for_ext_3 = x;
    AssignF({(Addr)&temp_var_for_ext_3}, (Addr)&x,
            "/home/shijia/Public/testprogram/s_nexttowardf.c_e.c:63:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_3;
  }
  if (hx >= 0) { /* x > 0 */
    if (int temp_var_for_tac_3; temp_var_for_tac_3 = x > y;

        ) { /* x -= ulp */
      hx -= 1;
    } else { /* x < y, x += ulp */
      hx += 1;
    }
  } else { /* x < 0 */
    if (int temp_var_for_tac_4; temp_var_for_tac_4 = x < y;

        ) { /* x -= ulp */
      hx -= 1;
    } else { /* x > y, x += ulp */
      hx += 1;
    }
  }
  hy = hx & UC(0x7f800000);
  if (hy >= UC(0x7f800000)) {
    float temp_var_for_ext_4;
    float temp_var_for_tac_5;
    temp_var_for_tac_5 = x + x;

    temp_var_for_ext_4 = temp_var_for_tac_5;
    compute((Addr)&temp_var_for_tac_3, {(Addr)&x, (Addr)&y},
            "/home/shijia/Public/testprogram/s_nexttowardf.c_e.c:69:11");
    compute((Addr)&temp_var_for_tac_4, {(Addr)&x, (Addr)&y},
            "/home/shijia/Public/testprogram/s_nexttowardf.c_e.c:75:11");
    computeFAdd((Addr)&temp_var_for_tac_5, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/s_nexttowardf.c_e.c:84:28");
    AssignF({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_5,
            "/home/shijia/Public/testprogram/s_nexttowardf.c_e.c:84:24");
    ; // x
    /*(u)(u)(x)(x)*/
    x = temp_var_for_ext_4;
    AssignF({(Addr)&x}, (Addr)&temp_var_for_ext_4,
            "/home/shijia/Public/testprogram/s_nexttowardf.c_e.c:86:7");
    ; /* overflow  */
    /* Force conversion to float.  */
    math_force_eval(x);
    float temp_var_for_ext_5;
    temp_var_for_ext_5 = x;
    AssignF({(Addr)&temp_var_for_ext_5}, (Addr)&x,
            "/home/shijia/Public/testprogram/s_nexttowardf.c_e.c:90:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_5;
  }
  if (hy < UC(0x00800000)) {
    float u = float temp_var_for_tac_6;
    temp_var_for_tac_6 = x * x;

    ; /* underflow */

    math_force_eval(u); /* raise underflow flag */
  }
  SET_FLOAT_WORD(x, hx);
  float temp_var_for_ext_6;
  temp_var_for_ext_6 = x;
  computeFMul((Addr)&temp_var_for_tac_6, {(Addr)&x, (Addr)&x},
              "/home/shijia/Public/testprogram/s_nexttowardf.c_e.c:96:17");
  AssignF({(Addr)&temp_var_for_ext_6}, (Addr)&x,
          "/home/shijia/Public/testprogram/s_nexttowardf.c_e.c:102:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_6;
}

__typeof(__nexttowardf) nexttowardf
    __attribute__((weak, alias("__nexttowardf")));

#endif
