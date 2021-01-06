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
  static const float Zero[] = {0.0, (double temp_var_for_tac_0;
  double temp_var_for_const_0, temp_var_for_const_1;
  temp_var_for_tac_0 = 0.0 - 0.0;

)
};

GET_FLOAT_WORD(hx, x);
GET_FLOAT_WORD(hy, y);
sx = hx & IC(0x80000000); /* sign of x */
hx ^= sx;                 /* |x| */
hy &= IC(0x7fffffff);     /* |y| */

/* purge off exception values */
if (hy == 0 || (hx >= IC(0x7f800000)) || /* y=0,or x not finite */
    (hy > IC(0x7f800000)))               /* or y is NaN */
{
  float temp_var_for_ext_0;
  float temp_var_for_tac_1, temp_var_for_tac_2, temp_var_for_tac_3;
  temp_var_for_tac_1 = x * y;

  temp_var_for_tac_2 = x * y;

  temp_var_for_tac_3 = temp_var_for_tac_1 / temp_var_for_tac_2;

  temp_var_for_ext_0 = temp_var_for_tac_3;
  computeDSub((Addr)&temp_var_for_tac_0, {(Addr) &(temp_var_for_const_1 = 0.0),
                                          (Addr) &(temp_var_for_const_0 = 0.0)},
              "/home/shijia/Public/testprogram/e_fmodf.c_e.c:32:42");
  computeFMul((Addr)&temp_var_for_tac_1, {(Addr)&x, (Addr)&y},
              "/home/shijia/Public/testprogram/e_fmodf.c_e.c:45:29");
  computeFMul((Addr)&temp_var_for_tac_2, {(Addr)&x, (Addr)&y},
              "/home/shijia/Public/testprogram/e_fmodf.c_e.c:45:39");
  computeFDiv((Addr)&temp_var_for_tac_3,
              {(Addr)&temp_var_for_tac_1, (Addr)&temp_var_for_tac_2},
              "/home/shijia/Public/testprogram/e_fmodf.c_e.c:45:34");
  AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_3,
          "/home/shijia/Public/testprogram/e_fmodf.c_e.c:45:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

if (hx < hy) {
  float temp_var_for_ext_1;
  temp_var_for_ext_1 = x;
  AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&x,
          "/home/shijia/Public/testprogram/e_fmodf.c_e.c:53:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}
/* |x|<|y| return x */
if (hx == hy) {
  float temp_var_for_ext_2;
  float temp_var_for_const_2;
  temp_var_for_ext_2 = Zero[(uint32_t)sx >> 31];
  AssignF({(Addr)&temp_var_for_ext_2},
          (Addr) &(temp_var_for_const_2 = Zero[(uint32_t)sx >> 31]),
          "/home/shijia/Public/testprogram/e_fmodf.c_e.c:61:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_2;
}
/* |x|=|y| return x*0 */

/* determine ix = ilogb(x) */
if (hx < IC(0x00800000)) { /* subnormal x */
  for (ix = -126, i = (hx << 8); i > 0; i <<= 1) {
    ix -= 1;
  }

} else {
  ix = (hx >> 23) - 127;
}

/* determine iy = ilogb(y) */
if (hy < IC(0x00800000)) { /* subnormal y */
  for (iy = -126, i = (hy << 8); i >= 0; i <<= 1) {
    iy -= 1;
  }

} else {
  iy = (hy >> 23) - 127;
}

/* set up {hx,lx}, {hy,ly} and align y to x */
if (ix >= -126) {
  hx = IC(0x00800000) | (IC(0x007fffff) & hx);
}

else { /* subnormal x, shift x to normal */
  n = -126 - ix;
  hx = hx << n;
}
if (iy >= -126) {
  hy = IC(0x00800000) | (IC(0x007fffff) & hy);
}

else { /* subnormal y, shift y to normal */
  n = -126 - iy;
  hy = hy << n;
}

/* fix point fmod */
n = ix - iy;
int32_t temp_var_for_ext_3;
temp_var_for_ext_3 = n--;
while (temp_var_for_ext_3) {
  hz = hx - hy;
  if (hz < 0) {
    hx = hx + hx;
  } else {
    if (hz == 0) /* return sign(x)*0 */
    {
      float temp_var_for_ext_4;
      float temp_var_for_const_3;
      temp_var_for_ext_4 = Zero[(uint32_t)sx >> 31];
      AssignF({(Addr)&temp_var_for_ext_4},
              (Addr) &(temp_var_for_const_3 = Zero[(uint32_t)sx >> 31]),
              "/home/shijia/Public/testprogram/e_fmodf.c_e.c:118:28");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_4;
    }

    hx = hz + hz;
  }
  temp_var_for_ext_3 = n--;
}
hz = hx - hy;
if (hz >= 0) {
  hx = hz;
}

/* convert back to floating value and restore the sign */
if (hx == 0) /* return sign(x)*0 */
{
  float temp_var_for_ext_5;
  float temp_var_for_const_4;
  temp_var_for_ext_5 = Zero[(uint32_t)sx >> 31];
  AssignF({(Addr)&temp_var_for_ext_5},
          (Addr) &(temp_var_for_const_4 = Zero[(uint32_t)sx >> 31]),
          "/home/shijia/Public/testprogram/e_fmodf.c_e.c:138:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_5;
}

int temp_var_for_ext_6;
temp_var_for_ext_6 = hx < IC(0x00800000);
while (temp_var_for_ext_6) { /* normalize x */
  hx = hx + hx;
  iy -= 1;
  temp_var_for_ext_6 = hx < IC(0x00800000);
}
if (iy >= -126) { /* normalize output */
  hx = ((hx - IC(0x00800000)) | ((iy + 127) << 23));
  SET_FLOAT_WORD(x, hx | sx);
} else { /* subnormal output */
  n = -126 - iy;
  hx >>= n;
  SET_FLOAT_WORD(x, hx | sx);
  x *= one;
  ; /* create necessary signal */
}
float temp_var_for_ext_7;
temp_var_for_ext_7 = x;
AssignF({(Addr)&temp_var_for_ext_7}, (Addr)&x,
        "/home/shijia/Public/testprogram/e_fmodf.c_e.c:161:22");
;
callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
callExp++;                 /*identify the function is  add move tmpShadow*/
return temp_var_for_ext_7; /* exact output */
}

#endif

float __fmodf(float x, float y) {
  if ((isinf(x) || int temp_var_for_tac_5; int temp_var_for_const_5;
       temp_var_for_tac_5 = y == 0.0F;

       ) &&
      _LIB_VERSION != _IEEE_ && !isunordered(x, y))
  /* fmod(+-Inf,y) or fmod(x,0) */
  {
    float temp_var_for_ext_8;
    float temp_var_for_const_6;
    float temp_var_for_callexp_0;

    temp_var_for_callexp_0 = __kernel_standard_f(x, y, y, KMATHERRF_FMOD);
    temp_var_for_ext_8 = temp_var_for_callexp_0;
    compute((Addr)&temp_var_for_tac_5,
            {(Addr)&y, (Addr) &(temp_var_for_const_5 = 0.0F)},
            "/home/shijia/Public/testprogram/e_fmodf.c_e.c:170:22");
    AssignF({(Addr)&temp_var_for_ext_8},
            (Addr) &(temp_var_for_const_6 = temp_var_for_callexp_0),
            "/home/shijia/Public/testprogram/e_fmodf.c_e.c:174:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_8;
  }

  float temp_var_for_ext_9;
  float temp_var_for_const_7;
  float temp_var_for_callexp_1;

  temp_var_for_callexp_1 = __ieee754_fmodf(x, y);
  temp_var_for_ext_9 = temp_var_for_callexp_1;
  AssignF({(Addr)&temp_var_for_ext_9},
          (Addr) &(temp_var_for_const_7 = temp_var_for_callexp_1),
          "/home/shijia/Public/testprogram/e_fmodf.c_e.c:181:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_9;
}

__typeof(__fmodf) fmodf __attribute__((weak, alias("__fmodf")));
