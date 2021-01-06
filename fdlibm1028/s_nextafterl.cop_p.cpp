#include "../ScDebug/scdebug.h"
/* s_nextafterl.c -- long double version of s_nextafter.c.
 * Conversion to long double by Ulrich Drepper,
 * Cygnus Support, drepper@cygnus.com.
 * Fixed for m68k by Andreas Schwab <schwab@suse.de>.
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
 *	nextafterl(x,y)
 *	return the next machine floating-point number of x in the
 *	direction toward y.
 *   Special cases:
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

long double __nextafterl(long double x, long double y) {
  int32_t ix, iy;
  int32_t esx, esy;
  uint32_t hx, hy, lx, ly;

  long double temp_var_for_const_0;
  ew_u.value = x;
  AssignLd({(Addr) &(temp_var_for_const_0 = ew_u.value)}, (Addr)&x,
           "/home/shijia/Public/testprogram/s_nextafterl.c_e.c:36:3 "
           "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
  ;
  long double temp_var_for_const_1;
  ew_u.value = y;
  AssignLd({(Addr) &(temp_var_for_const_1 = ew_u.value)}, (Addr)&y,
           "/home/shijia/Public/testprogram/s_nextafterl.c_e.c:37:3 "
           "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
  ;
  ix = esx & IEEE854_LONG_DOUBLE_MAXEXP; /* |x| */
  iy = esy & IEEE854_LONG_DOUBLE_MAXEXP; /* |y| */

  /* Intel's extended format has the normally implicit 1 explicit
     present.  Sigh!  */
  if (((ix == IEEE854_LONG_DOUBLE_MAXEXP) &&
       (((hx & IC(0x7fffffff)) | lx) != 0)) || /* x is nan */
      ((iy == IEEE854_LONG_DOUBLE_MAXEXP) &&
       (((hy & IC(0x7fffffff)) | ly) != 0))) /* y is nan */
  {
    long double temp_var_for_ext_0;
    long double temp_var_for_tac_0;
    temp_var_for_tac_0 = x + y;

    temp_var_for_ext_0 = temp_var_for_tac_0;
    computeLdAdd((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&y},
                 "/home/shijia/Public/testprogram/s_nextafterl.c_e.c:49:28");
    AssignLd({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_0,
             "/home/shijia/Public/testprogram/s_nextafterl.c_e.c:49:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  if (int temp_var_for_tac_1; temp_var_for_tac_1 = x == y;

      ) {
    long double temp_var_for_ext_1;
    temp_var_for_ext_1 = y;
    compute((Addr)&temp_var_for_tac_1, {(Addr)&x, (Addr)&y},
            "/home/shijia/Public/testprogram/s_nextafterl.c_e.c:55:9");
    AssignLd({(Addr)&temp_var_for_ext_1}, (Addr)&y,
             "/home/shijia/Public/testprogram/s_nextafterl.c_e.c:57:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }
  /* x=y, return y */
  if ((ix | hx | lx) == 0) { /* x == 0 */
    long double u;

    long double temp_var_for_ext_2;
    temp_var_for_ext_2; /* return +-minsubnormal */
    long double temp_var_for_const_2;
    u = math_opt_barrier(x);
    AssignLd({(Addr)&u}, (Addr) &(temp_var_for_const_2 = math_opt_barrier(x)),
             "/home/shijia/Public/testprogram/s_nextafterl.c_e.c:68:7");
    ;
    long double temp_var_for_ext_3;
    long double temp_var_for_tac_2;
    temp_var_for_tac_2 = u * u;

    temp_var_for_ext_3 = temp_var_for_tac_2;
    computeLdMul((Addr)&temp_var_for_tac_2, {(Addr)&u, (Addr)&u},
                 "/home/shijia/Public/testprogram/s_nextafterl.c_e.c:70:28");
    AssignLd({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_2,
             "/home/shijia/Public/testprogram/s_nextafterl.c_e.c:70:24");
    ; // u
    /*(u)(u)*/
    u = temp_var_for_ext_3;
    AssignLd({(Addr)&u}, (Addr)&temp_var_for_ext_3,
             "/home/shijia/Public/testprogram/s_nextafterl.c_e.c:72:7");
    ;
    math_force_eval(u); /* raise underflow flag */
    long double temp_var_for_ext_4;
    temp_var_for_ext_4 = x;
    AssignLd({(Addr)&temp_var_for_ext_4}, (Addr)&x,
             "/home/shijia/Public/testprogram/s_nextafterl.c_e.c:75:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_4;
  }
  if (esx >= 0) { /* x > 0 */
    if (esx > esy || ((esx == esy) && (hx > hy || ((hx == hy) && (lx > ly))))) {
      /* x > y, x -= ulp */
      if (lx == 0) {
        if (hx <= UC(0x80000000)) {
          if (esx == 0) {
            --hx;
          } else {
            esx -= 1;
            hx = hx - 1;
            if (esx > 0) {
              hx |= UC(0x80000000);
            }
          }
        } else {
          hx -= 1;
        }
      }
      lx -= 1;
    } else { /* x < y, x += ulp */
      lx += 1;
      if (lx == 0) {
        hx += 1;
        if (hx == 0 || (esx == 0 && hx == UC(0x80000000))) {
          esx += 1;
          hx |= UC(0x80000000);
        }
      }
    }
  } else { /* x < 0 */
    if (esy >= 0 || (esx > esy || ((esx == esy) &&
                                   (hx > hy || ((hx == hy) && (lx > ly)))))) {
      /* x < y, x -= ulp */
      if (lx == 0) {
        if (hx <= UC(0x80000000)) {
          esx -= 1;
          hx = hx - 1;
          if ((esx & IEEE854_LONG_DOUBLE_MAXEXP) > 0) {
            hx |= UC(0x80000000);
          }

        } else {
          hx -= 1;
        }
      }
      lx -= 1;
    } else { /* x > y, x += ulp */
      lx += 1;
      if (lx == 0) {
        hx += 1;
        if (hx == 0 || (esx == IC(0xffff8000) && hx == UC(0x80000000))) {
          esx += 1;
          hx |= UC(0x80000000);
        }
      }
    }
  }
  esy = esx & IEEE854_LONG_DOUBLE_MAXEXP;
  if (esy == IEEE854_LONG_DOUBLE_MAXEXP) {
    long double temp_var_for_ext_5;
    long double temp_var_for_tac_3;
    temp_var_for_tac_3 = x + x;

    temp_var_for_ext_5 = temp_var_for_tac_3;
    computeLdAdd((Addr)&temp_var_for_tac_3, {(Addr)&x, (Addr)&x},
                 "/home/shijia/Public/testprogram/s_nextafterl.c_e.c:140:28");
    AssignLd({(Addr)&temp_var_for_ext_5}, (Addr)&temp_var_for_tac_3,
             "/home/shijia/Public/testprogram/s_nextafterl.c_e.c:140:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_5;
  }
  /* overflow  */
  if (esy == 0) {
    long double u = long double temp_var_for_tac_4;
    temp_var_for_tac_4 = x * x;

    ;                   /* underflow */
    math_force_eval(u); /* raise underflow flag */
  }
  long double temp_var_for_ext_6;
  temp_var_for_ext_6;
  long double temp_var_for_ext_7;
  temp_var_for_ext_7 = x;
  computeLdMul((Addr)&temp_var_for_tac_4, {(Addr)&x, (Addr)&x},
               "/home/shijia/Public/testprogram/s_nextafterl.c_e.c:147:23");
  AssignLd({(Addr)&temp_var_for_ext_7}, (Addr)&x,
           "/home/shijia/Public/testprogram/s_nextafterl.c_e.c:153:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_7;
}

__typeof(__nextafterl) nextafterl __attribute__((weak, alias("__nextafterl")));

__typeof(__nexttowardl) __nexttowardl __attribute__((alias("__nextafterl")));
__typeof(nexttowardl) nexttowardl __attribute__((weak, alias("__nextafterl")));

#endif
