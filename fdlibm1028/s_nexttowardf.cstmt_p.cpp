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
  GET_LDOUBLE_WORDS(esy, hy, ly, y);
  ix = hx & IC(0x7fffffff);              /* |x| */
  iy = esy & IEEE854_LONG_DOUBLE_MAXEXP; /* |y| */

  /* Intel's extended format has the normally implicit 1 explicit
     present.  Sigh!  */
  if ((ix > IC(0x7f800000)) || /* x is nan */
      (iy >= IEEE854_LONG_DOUBLE_MAXEXP &&
       (((hy & UC(0x7fffffff)) | ly) != 0))) /* y is nan */
    return x + y;
  if ((long double)x == y) {
    float temp_var_for_ext_0;
    temp_var_for_ext_0 = y;
    AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&y,
            "/home/shijia/Public/testprogram/s_nexttowardf.c_e.c:39:24");
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }
  /* x=y, return y */
  if (ix == 0) { /* x == 0 */
    float u;

    SET_FLOAT_WORD(x, ((esy & 0x8000) << 16) | 1); /* return +-minsub */
    u = math_opt_barrier(x);
    u = u * u;
    math_force_eval(u); /* raise underflow flag */
    return x;
  }
  if (hx >= 0) { /* x > 0 */
    if (x > y) { /* x -= ulp */
      hx -= 1;
    } else { /* x < y, x += ulp */
      hx += 1;
    }
  } else {       /* x < 0 */
    if (x < y) { /* x -= ulp */
      hx -= 1;
    } else { /* x > y, x += ulp */
      hx += 1;
    }
  }
  hy = hx & UC(0x7f800000);
  if (hy >= UC(0x7f800000)) {
    x = x + x; /* overflow  */
    /* Force conversion to float.  */
    math_force_eval(x);
    return x;
  }
  if (hy < UC(0x00800000)) {
    float u = x * x; /* underflow */

    math_force_eval(u); /* raise underflow flag */
  }
  SET_FLOAT_WORD(x, hx);
  float temp_var_for_ext_1;
  temp_var_for_ext_1 = x;
  AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&x,
          "/home/shijia/Public/testprogram/s_nexttowardf.c_e.c:81:22");
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

__typeof(__nexttowardf) nexttowardf
    __attribute__((weak, alias("__nexttowardf")));

#endif
