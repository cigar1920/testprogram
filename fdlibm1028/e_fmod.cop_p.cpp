#include "../ScDebug/scdebug.h"
/* @(#)e_fmod.c 1.3 95/01/18 */
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

/*
 * __ieee754_fmod(x,y)
 * Return x mod y in exact arithmetic
 * Method: shift and subtract
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_fmod

double __ieee754_fmod(double x, double y) {
  int32_t n, hx, hy, hz, ix, iy, sx, i;
  uint32_t lx, ly, lz;

  static const double one = 1.0;
  static const double Zero[] = {0.0, (double temp_var_for_tac_0;
  double temp_var_for_const_0, temp_var_for_const_1;
  temp_var_for_tac_0 = 0.0 - 0.0;

)
};

GET_DOUBLE_WORDS(hx, lx, x);
GET_DOUBLE_WORDS(hy, ly, y);
sx = hx & IC(0x80000000); /* sign of x */
hx ^= sx;                 /* |x| */
hy &= IC(0x7fffffff);     /* |y| */

/* purge off exception values */
if ((hy | ly) == 0 || (hx >= IC(0x7ff00000)) ||   /* y=0,or x not finite */
    ((hy | ((ly | -ly) >> 31)) > IC(0x7ff00000))) /* or y is NaN */
{
  double temp_var_for_ext_0;
  double temp_var_for_tac_1, temp_var_for_tac_2, temp_var_for_tac_3;
  temp_var_for_tac_1 = x * y;

  temp_var_for_tac_2 = x * y;

  temp_var_for_tac_3 = temp_var_for_tac_1 / temp_var_for_tac_2;

  temp_var_for_ext_0 = temp_var_for_tac_3;
  computeDSub((Addr)&temp_var_for_tac_0, {(Addr) &(temp_var_for_const_1 = 0.0),
                                          (Addr) &(temp_var_for_const_0 = 0.0)},
              "/home/shijia/Public/testprogram/e_fmod.c_e.c:30:43");
  computeDMul((Addr)&temp_var_for_tac_1, {(Addr)&x, (Addr)&y},
              "/home/shijia/Public/testprogram/e_fmod.c_e.c:43:29");
  computeDMul((Addr)&temp_var_for_tac_2, {(Addr)&x, (Addr)&y},
              "/home/shijia/Public/testprogram/e_fmod.c_e.c:43:39");
  computeDDiv((Addr)&temp_var_for_tac_3,
              {(Addr)&temp_var_for_tac_1, (Addr)&temp_var_for_tac_2},
              "/home/shijia/Public/testprogram/e_fmod.c_e.c:43:34");
  AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_3,
          "/home/shijia/Public/testprogram/e_fmod.c_e.c:43:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}

if (hx <= hy) {
  if ((hx < hy) || (lx < ly)) {
    double temp_var_for_ext_1;
    temp_var_for_ext_1 = x;
    AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&x,
            "/home/shijia/Public/testprogram/e_fmod.c_e.c:52:26");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }
  /* |x|<|y| return x */
  if (lx == ly) {
    double temp_var_for_ext_2;
    double temp_var_for_const_2;
    temp_var_for_ext_2 = Zero[(uint32_t)sx >> 31];
    AssignD({(Addr)&temp_var_for_ext_2},
            (Addr) &(temp_var_for_const_2 = Zero[(uint32_t)sx >> 31]),
            "/home/shijia/Public/testprogram/e_fmod.c_e.c:61:26");
    ;
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  }
  /* |x|=|y| return x*0 */
}

/* determine ix = ilogb(x) */
if (hx < IC(0x00100000)) { /* subnormal x */
  if (hx == 0) {
    for (ix = -1043, i = lx; i > 0; i <<= 1) {
      ix -= 1;
    }

  } else {
    for (ix = -1022, i = (hx << 11); i > 0; i <<= 1) {
      ix -= 1;
    }
  }
} else {
  ix = (hx >> 20) - 1023;
}

/* determine iy = ilogb(y) */
if (hy < IC(0x00100000)) { /* subnormal y */
  if (hy == 0) {
    for (iy = -1043, i = ly; i > 0; i <<= 1) {
      iy -= 1;
    }

  } else {
    for (iy = -1022, i = (hy << 11); i > 0; i <<= 1) {
      iy -= 1;
    }
  }
} else {
  iy = (hy >> 20) - 1023;
}

/* set up {hx,lx}, {hy,ly} and align y to x */
if (ix >= -1022) {
  hx = IC(0x00100000) | (IC(0x000fffff) & hx);
}

else { /* subnormal x, shift x to normal */
  n = -1022 - ix;
  if (n <= 31) {
    hx = (hx << n) | (lx >> (32 - n));
    lx <<= n;
  } else {
    hx = lx << (n - 32);
    lx = 0;
  }
}
if (iy >= -1022) {
  hy = IC(0x00100000) | (IC(0x000fffff) & hy);
}

else { /* subnormal y, shift y to normal */
  n = -1022 - iy;
  if (n <= 31) {
    hy = (hy << n) | (ly >> (32 - n));
    ly <<= n;
  } else {
    hy = ly << (n - 32);
    ly = 0;
  }
}

/* fix point fmod */
n = ix - iy;
int32_t temp_var_for_ext_3;
temp_var_for_ext_3 = n--;
while (temp_var_for_ext_3) {
  hz = hx - hy;
  lz = lx - ly;
  if (lx < ly) {
    hz -= 1;
  }

  if (hz < 0) {
    hx = hx + hx + (lx >> 31);
    lx = lx + lx;
  } else {
    if ((hz | lz) == 0) /* return sign(x)*0 */
    {
      double temp_var_for_ext_4;
      double temp_var_for_const_3;
      temp_var_for_ext_4 = Zero[(uint32_t)sx >> 31];
      AssignD({(Addr)&temp_var_for_ext_4},
              (Addr) &(temp_var_for_const_3 = Zero[(uint32_t)sx >> 31]),
              "/home/shijia/Public/testprogram/e_fmod.c_e.c:150:28");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_4;
    }

    hx = hz + hz + (lz >> 31);
    lx = lz + lz;
  }
  temp_var_for_ext_3 = n--;
}
hz = hx - hy;
lz = lx - ly;
if (lx < ly) {
  hz -= 1;
}

if (hz >= 0) {
  hx = hz;
  lx = lz;
}

/* convert back to floating value and restore the sign */
if ((hx | lx) == 0) /* return sign(x)*0 */
{
  double temp_var_for_ext_5;
  double temp_var_for_const_4;
  temp_var_for_ext_5 = Zero[(uint32_t)sx >> 31];
  AssignD({(Addr)&temp_var_for_ext_5},
          (Addr) &(temp_var_for_const_4 = Zero[(uint32_t)sx >> 31]),
          "/home/shijia/Public/testprogram/e_fmod.c_e.c:177:24");
  ;
  callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_5;
}

int temp_var_for_ext_6;
temp_var_for_ext_6 = hx < IC(0x00100000);
while (temp_var_for_ext_6) { /* normalize x */
  hx = hx + hx + (lx >> 31);
  lx = lx + lx;
  iy -= 1;
  temp_var_for_ext_6 = hx < IC(0x00100000);
}
if (iy >= -1022) { /* normalize output */
  hx = ((hx - IC(0x00100000)) | ((iy + 1023) << 20));
  INSERT_WORDS(x, hx | sx, lx);
} else { /* subnormal output */
  n = -1022 - iy;
  if (n <= 20) {
    lx = (lx >> n) | ((uint32_t)hx << (32 - n));
    hx >>= n;
  } else {
    if (n <= 31) {
      lx = (hx << (32 - n)) | (lx >> n);
      hx = sx;
    } else {
      lx = hx >> (n - 32);
      hx = sx;
    }
  }

  INSERT_WORDS(x, hx | sx, lx);
  x *= one;
  ; /* create necessary signal */
}
double temp_var_for_ext_7;
temp_var_for_ext_7 = x;
AssignD({(Addr)&temp_var_for_ext_7}, (Addr)&x,
        "/home/shijia/Public/testprogram/e_fmod.c_e.c:213:22");
;
callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
callExp++;                 /*identify the function is  add move tmpShadow*/
return temp_var_for_ext_7; /* exact output */
}

#endif

double __fmod(double x, double y) {
  if (_LIB_VERSION != _IEEE_ &&
      (isinf(x) || int temp_var_for_tac_5; int temp_var_for_const_5;
       temp_var_for_tac_5 = y == 0.0;

       ) &&
      !isunordered(x, y))
  /* fmod(+-Inf,y) or fmod(x,0) */
  {
    double temp_var_for_ext_8;
    double temp_var_for_const_6;
    double temp_var_for_callexp_0;

    temp_var_for_callexp_0 = __kernel_standard(x, y, y, KMATHERR_FMOD);
    temp_var_for_ext_8 = temp_var_for_callexp_0;
    compute((Addr)&temp_var_for_tac_5,
            {(Addr)&y, (Addr) &(temp_var_for_const_5 = 0.0)},
            "/home/shijia/Public/testprogram/e_fmod.c_e.c:222:48");
    AssignD({(Addr)&temp_var_for_ext_8},
            (Addr) &(temp_var_for_const_6 = temp_var_for_callexp_0),
            "/home/shijia/Public/testprogram/e_fmod.c_e.c:226:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_8;
  }

  double temp_var_for_ext_9;
  double temp_var_for_const_7;
  double temp_var_for_callexp_1;

  temp_var_for_callexp_1 = __ieee754_fmod(x, y);
  temp_var_for_ext_9 = temp_var_for_callexp_1;
  AssignD({(Addr)&temp_var_for_ext_9},
          (Addr) &(temp_var_for_const_7 = temp_var_for_callexp_1),
          "/home/shijia/Public/testprogram/e_fmod.c_e.c:233:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_9;
}

__typeof(__fmod) fmod __attribute__((weak, alias("__fmod")));
#ifdef __NO_LONG_DOUBLE_MATH
__typeof(__fmodl) __fmodl __attribute__((alias("__fmod")));
__typeof(__fmodl) fmodl __attribute__((weak, alias("__fmod")));
#endif
