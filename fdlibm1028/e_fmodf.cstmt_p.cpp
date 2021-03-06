#include "../ScDebug/scdebug.h"
/* e_fmodf.c -- float version of e_fmod.c.
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

/*
 * __ieee754_fmodf(x,y)
 * Return x mod y in exact arithmetic
 * Method: shift and subtract
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_fmod

float __ieee754_fmodf(float x, float y) {
  int32_t n, hx, hy, hz, ix, iy, sx, i;

  static const float one = 1.0;
  static const float Zero[] = { 0.0, (0.0 - 0.0);
  double temp_var_for_const_0, temp_var_for_const_1;
};

GET_FLOAT_WORD(hx, x);
GET_FLOAT_WORD(hy, y);
sx = hx & IC(0x80000000); /* sign of x */
hx ^= sx;                 /* |x| */
hy &= IC(0x7fffffff);     /* |y| */

/* purge off exception values */
if (hy == 0 || (hx >= IC(0x7f800000)) || /* y=0,or x not finite */
    (hy > IC(0x7f800000)))               /* or y is NaN */
  return (x * y) / (x * y);
if (hx < hy)
  return x; /* |x|<|y| return x */
if (hx == hy)
  return Zero[(uint32_t)sx >> 31]; /* |x|=|y| return x*0 */

/* determine ix = ilogb(x) */
if (hx < IC(0x00800000)) { /* subnormal x */
  for (ix = -126, i = (hx << 8); i > 0; i <<= 1)
    ix -= 1;
} else
  ix = (hx >> 23) - 127;

/* determine iy = ilogb(y) */
if (hy < IC(0x00800000)) { /* subnormal y */
  for (iy = -126, i = (hy << 8); i >= 0; i <<= 1)
    iy -= 1;
} else
  iy = (hy >> 23) - 127;

/* set up {hx,lx}, {hy,ly} and align y to x */
if (ix >= -126)
  hx = IC(0x00800000) | (IC(0x007fffff) & hx);
else { /* subnormal x, shift x to normal */
  n = -126 - ix;
  hx = hx << n;
}
if (iy >= -126)
  hy = IC(0x00800000) | (IC(0x007fffff) & hy);
else { /* subnormal y, shift y to normal */
  n = -126 - iy;
  hy = hy << n;
}

/* fix point fmod */
n = ix - iy;
while (n--) {
  hz = hx - hy;
  if (hz < 0) {
    hx = hx + hx;
  } else {
    if (hz == 0) /* return sign(x)*0 */
      return Zero[(uint32_t)sx >> 31];
    hx = hz + hz;
  }
}
hz = hx - hy;
if (hz >= 0) {
  hx = hz;
}

/* convert back to floating value and restore the sign */
if (hx == 0) /* return sign(x)*0 */
  return Zero[(uint32_t)sx >> 31];
while (hx < IC(0x00800000)) { /* normalize x */
  hx = hx + hx;
  iy -= 1;
}
if (iy >= -126) { /* normalize output */
  hx = ((hx - IC(0x00800000)) | ((iy + 127) << 23));
  SET_FLOAT_WORD(x, hx | sx);
} else { /* subnormal output */
  n = -126 - iy;
  hx >>= n;
  SET_FLOAT_WORD(x, hx | sx);
  x *= one; /* create necessary signal */
}
float temp_var_for_ext_0;
temp_var_for_ext_0 = x;
computeFSub((Addr)&temp_var_for_ext_0, {(Addr) &(temp_var_for_const_1 = 0.0),
                                        (Addr) &(temp_var_for_const_0 = 0.0)},
            "/home/shijia/Public/testprogram/e_fmodf.c_e.c:111:22");
callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
callExp++;                 /*identify the function is  add move tmpShadow*/
return temp_var_for_ext_0; /* exact output */
}

#endif

float __fmodf(float x, float y) {
  if ((isinf(x) || y == 0.0F) && _LIB_VERSION != _IEEE_ && !isunordered(x, y))
    /* fmod(+-Inf,y) or fmod(x,0) */
    return __kernel_standard_f(x, y, y, KMATHERRF_FMOD);
  float temp_var_for_ext_1;
  temp_var_for_ext_1 = __ieee754_fmodf(x, y);
  float temp_var_for_callexp_0 = __ieee754_fmodf(
      getFVbyShadow<float>((Addr)&x), getFVbyShadow<float>((Addr)&y));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_callexp_0,
          "/home/shijia/Public/testprogram/e_fmodf.c_e.c:124:22");
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

__typeof(__fmodf) fmodf __attribute__((weak, alias("__fmodf")));
