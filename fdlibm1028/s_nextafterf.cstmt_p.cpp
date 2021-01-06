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
    return x + y;
  if (x == y) {
    float temp_var_for_ext_0;
    temp_var_for_ext_0 = y;
    AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&y,
            "/home/shijia/Public/testprogram/s_nextafterf.c_e.c:33:24");
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }
  /* x=y, return y */
  if (ix == 0) { /* x == 0 */
    float u;

    SET_FLOAT_WORD(x, (hy & IC(0x80000000)) | 1); /* return +-minsubnormal */
    u = math_opt_barrier(x);
    u = u * u;
    math_force_eval(u); /* raise underflow flag */
    return x;
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
    x = x + x; /* overflow  */
    math_force_eval(x);
    return x; /* overflow  */
  }
  if (hy < IC(0x00800000)) {
    float u = x * x;    /* underflow */
    math_force_eval(u); /* raise underflow flag */
  }
  SET_FLOAT_WORD(x, hx);
  float temp_var_for_ext_1;
  temp_var_for_ext_1 = x;
  AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&x,
          "/home/shijia/Public/testprogram/s_nextafterf.c_e.c:73:22");
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

__typeof(__nextafterf) nextafterf __attribute__((weak, alias("__nextafterf")));
