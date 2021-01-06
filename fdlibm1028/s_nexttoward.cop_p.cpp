#include "../ScDebug/scdebug.h"
/* s_nexttoward.c
 * Special i387 version
 * Conversion from s_nextafter.c by Ulrich Drepper, Cygnus Support,
 * drepper@cygnus.com.
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

/* IEEE functions
 *	nexttoward(x,y)
 *	return the next machine floating-point number of x in the
 *	direction toward y.
 *   Special cases:
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

double __nexttoward(double x, long double y) {
  int32_t hx, ix, iy;
  uint32_t lx, hy, ly, esy;

  GET_DOUBLE_WORDS(hx, lx, x);
  long double temp_var_for_const_0;
  ew_u.value = y;
  AssignLd({(Addr) &(temp_var_for_const_0 = ew_u.value)}, (Addr)&y,
           "/home/shijia/Public/testprogram/s_nexttoward.c_e.c:36:3 "
           "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
  ;
  ix = hx & IC(0x7fffffff);              /* |x| */
  iy = esy & IEEE854_LONG_DOUBLE_MAXEXP; /* |y| */

  /* Intel's extended format has the normally implicit 1 explicit
     present.  Sigh!  */
  if (((ix >= IC(0x7ff00000)) &&
       ((ix - IC(0x7ff00000)) | lx) != 0) || /* x is nan */
      ((iy >= IEEE854_LONG_DOUBLE_MAXEXP) &&
       ((hy & UC(0x7fffffff)) | ly) != 0)) /* y is nan */
  {
    double temp_var_for_ext_0;
    double temp_var_for_const_1;
    double temp_var_for_callexp_0;

    temp_var_for_callexp_0 = __builtin_nan("");
    temp_var_for_ext_0 = temp_var_for_callexp_0;
    AssignD({(Addr)&temp_var_for_ext_0},
            (Addr) &(temp_var_for_const_1 = temp_var_for_callexp_0),
            "/home/shijia/Public/testprogram/s_nexttoward.c_e.c:48:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  if (int temp_var_for_tac_0; int temp_var_for_const_2;
      temp_var_for_tac_0 = ((long double)x) == y;

      ) {
    double temp_var_for_ext_1;
    temp_var_for_ext_1 = y;
    compute((Addr)&temp_var_for_tac_0,
            {(Addr) &(temp_var_for_const_2 = ((long double)x)), (Addr)&y},
            "/home/shijia/Public/testprogram/s_nexttoward.c_e.c:54:22");
    AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&y,
            "/home/shijia/Public/testprogram/s_nexttoward.c_e.c:56:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }
  /* x=y, return y */
  if ((ix | lx) == 0) { /* x == 0 */
    double u;

    INSERT_WORDS(x, (esy & 0x8000) << 16, 1); /* return +-minsub */
    double temp_var_for_const_3;
    u = math_opt_barrier(x);
    AssignD({(Addr)&u}, (Addr) &(temp_var_for_const_3 = math_opt_barrier(x)),
            "/home/shijia/Public/testprogram/s_nexttoward.c_e.c:66:7");
    ;
    double temp_var_for_ext_2;
    double temp_var_for_tac_1;
    temp_var_for_tac_1 = u * u;

    temp_var_for_ext_2 = temp_var_for_tac_1;
    computeDMul((Addr)&temp_var_for_tac_1, {(Addr)&u, (Addr)&u},
                "/home/shijia/Public/testprogram/s_nexttoward.c_e.c:68:28");
    AssignD({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_1,
            "/home/shijia/Public/testprogram/s_nexttoward.c_e.c:68:24");
    ; // u
    /*(u)(u)*/
    u = temp_var_for_ext_2;
    AssignD({(Addr)&u}, (Addr)&temp_var_for_ext_2,
            "/home/shijia/Public/testprogram/s_nexttoward.c_e.c:70:7");
    ;
    math_force_eval(u); /* raise underflow flag */
    double temp_var_for_ext_3;
    temp_var_for_ext_3 = x;
    AssignD({(Addr)&temp_var_for_ext_3}, (Addr)&x,
            "/home/shijia/Public/testprogram/s_nexttoward.c_e.c:73:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_3;
  }
  if (hx >= 0) { /* x > 0 */
    if (int temp_var_for_tac_2; temp_var_for_tac_2 = x > y;

        ) { /* x -= ulp */
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
  } else { /* x < 0 */
    if (int temp_var_for_tac_3; temp_var_for_tac_3 = x < y;

        ) { /* x -= ulp */
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
  hy = hx & UC(0x7ff00000);
  if (hy >= UC(0x7ff00000)) {
    double temp_var_for_ext_4;
    double temp_var_for_tac_4;
    temp_var_for_tac_4 = x + x;

    temp_var_for_ext_4 = temp_var_for_tac_4;
    compute((Addr)&temp_var_for_tac_2, {(Addr)&x, (Addr)&y},
            "/home/shijia/Public/testprogram/s_nexttoward.c_e.c:79:11");
    compute((Addr)&temp_var_for_tac_3, {(Addr)&x, (Addr)&y},
            "/home/shijia/Public/testprogram/s_nexttoward.c_e.c:92:11");
    computeDAdd((Addr)&temp_var_for_tac_4, {(Addr)&x, (Addr)&x},
                "/home/shijia/Public/testprogram/s_nexttoward.c_e.c:108:28");
    AssignD({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_4,
            "/home/shijia/Public/testprogram/s_nexttoward.c_e.c:108:24");
    ; // x
    /*(u)(u)(x)(x)*/
    x = temp_var_for_ext_4;
    AssignD({(Addr)&x}, (Addr)&temp_var_for_ext_4,
            "/home/shijia/Public/testprogram/s_nexttoward.c_e.c:110:7");
    ; /* overflow  */
    /* Force conversion to double.  */
    math_force_eval(x);
    double temp_var_for_ext_5;
    temp_var_for_ext_5 = x;
    AssignD({(Addr)&temp_var_for_ext_5}, (Addr)&x,
            "/home/shijia/Public/testprogram/s_nexttoward.c_e.c:114:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_5;
  }
  if (hy < UC(0x00100000)) {
    double u = double temp_var_for_tac_5;
    temp_var_for_tac_5 = x * x;

    ;                   /* underflow */
    math_force_eval(u); /* raise underflow flag */
  }
  INSERT_WORDS(x, hx, lx);
  double temp_var_for_ext_6;
  temp_var_for_ext_6 = x;
  computeDMul((Addr)&temp_var_for_tac_5, {(Addr)&x, (Addr)&x},
              "/home/shijia/Public/testprogram/s_nexttoward.c_e.c:120:18");
  AssignD({(Addr)&temp_var_for_ext_6}, (Addr)&x,
          "/home/shijia/Public/testprogram/s_nexttoward.c_e.c:125:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_6;
}

__typeof(__nexttoward) nexttoward __attribute__((weak, alias("__nexttoward")));
/* aliases for long double versions already done in nextafter */

#endif
