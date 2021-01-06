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
  GET_LDOUBLE_WORDS(esy, hy, ly, y);
  ix = hx & IC(0x7fffffff);              /* |x| */
  iy = esy & IEEE854_LONG_DOUBLE_MAXEXP; /* |y| */

  /* Intel's extended format has the normally implicit 1 explicit
     present.  Sigh!  */
  if (((ix >= IC(0x7ff00000)) &&
       ((ix - IC(0x7ff00000)) | lx) != 0) || /* x is nan */
      ((iy >= IEEE854_LONG_DOUBLE_MAXEXP) &&
       ((hy & UC(0x7fffffff)) | ly) != 0)) /* y is nan */
    return __builtin_nan("");
  if ((long double)x == y) {
    double temp_var_for_ext_0;
    temp_var_for_ext_0 = y;
    AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&y,
            "/home/shijia/Public/testprogram/s_nexttoward.c_e.c:49:24");
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }
  /* x=y, return y */
  if ((ix | lx) == 0) { /* x == 0 */
    double u;

    INSERT_WORDS(x, (esy & 0x8000) << 16, 1); /* return +-minsub */
    u = math_opt_barrier(x);
    u = u * u;
    math_force_eval(u); /* raise underflow flag */
    return x;
  }
  if (hx >= 0) { /* x > 0 */
    if (x > y) { /* x -= ulp */
      if (lx == 0)
        hx -= 1;
      lx -= 1;
    } else { /* x < y, x += ulp */
      lx += 1;
      if (lx == 0)
        hx += 1;
    }
  } else {       /* x < 0 */
    if (x < y) { /* x -= ulp */
      if (lx == 0)
        hx -= 1;
      lx -= 1;
    } else { /* x > y, x += ulp */
      lx += 1;
      if (lx == 0)
        hx += 1;
    }
  }
  hy = hx & UC(0x7ff00000);
  if (hy >= UC(0x7ff00000)) {
    x = x + x; /* overflow  */
    /* Force conversion to double.  */
    math_force_eval(x);
    return x;
  }
  if (hy < UC(0x00100000)) {
    double u = x * x;   /* underflow */
    math_force_eval(u); /* raise underflow flag */
  }
  INSERT_WORDS(x, hx, lx);
  double temp_var_for_ext_1;
  temp_var_for_ext_1 = x;
  AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&x,
          "/home/shijia/Public/testprogram/s_nexttoward.c_e.c:98:22");
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

__typeof(__nexttoward) nexttoward __attribute__((weak, alias("__nexttoward")));
/* aliases for long double versions already done in nextafter */

#endif
