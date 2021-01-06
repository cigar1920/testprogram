#include "../ScDebug/scdebug.h"
/* Copyright (C) 2011-2013 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by Ulrich Drepper <drepper@gmail.com>, 2011.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

float __ieee754_scalbf(float x, float fn) {
  long ifn;

  if (isnan(x)) {
    float temp_var_for_ext_0;
    float temp_var_for_tac_0;
    temp_var_for_tac_0 = x * fn;

    temp_var_for_ext_0 = temp_var_for_tac_0;
    computeFMul((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&fn},
                "/home/shijia/Public/testprogram/e_scalbf.c_e.c:28:28");
    AssignF({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_0,
            "/home/shijia/Public/testprogram/e_scalbf.c_e.c:28:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  if (!isfinite(fn)) {
    if (isnan(fn) || int temp_var_for_tac_1; int temp_var_for_const_0;
        temp_var_for_tac_1 = fn > 0.0f;

        ) {
      float temp_var_for_ext_1;
      float temp_var_for_tac_2;
      temp_var_for_tac_2 = x * fn;

      temp_var_for_ext_1 = temp_var_for_tac_2;
      compute((Addr)&temp_var_for_tac_1,
              {(Addr)&fn, (Addr) &(temp_var_for_const_0 = 0.0f)},
              "/home/shijia/Public/testprogram/e_scalbf.c_e.c:35:25");
      computeFMul((Addr)&temp_var_for_tac_2, {(Addr)&x, (Addr)&fn},
                  "/home/shijia/Public/testprogram/e_scalbf.c_e.c:37:30");
      AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_2,
              "/home/shijia/Public/testprogram/e_scalbf.c_e.c:37:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_1;
    }

    if (int temp_var_for_tac_3; int temp_var_for_const_1;
        temp_var_for_tac_3 = x == 0.0f;

        ) {
      float temp_var_for_ext_2;
      temp_var_for_ext_2 = x;
      compute((Addr)&temp_var_for_tac_3,
              {(Addr)&x, (Addr) &(temp_var_for_const_1 = 0.0f)},
              "/home/shijia/Public/testprogram/e_scalbf.c_e.c:44:11");
      AssignF({(Addr)&temp_var_for_ext_2}, (Addr)&x,
              "/home/shijia/Public/testprogram/e_scalbf.c_e.c:46:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_2;
    }

    float temp_var_for_ext_3;
    float temp_var_for_tac_4;
    float temp_var_for_const_2;
    temp_var_for_tac_4 = x / (-(fn));

    temp_var_for_ext_3 = temp_var_for_tac_4;
    computeFDiv((Addr)&temp_var_for_tac_4,
                {(Addr)&x, (Addr) &(temp_var_for_const_2 = (-(fn)))},
                "/home/shijia/Public/testprogram/e_scalbf.c_e.c:54:28");
    AssignF({(Addr)&temp_var_for_ext_3}, (Addr)&temp_var_for_tac_4,
            "/home/shijia/Public/testprogram/e_scalbf.c_e.c:54:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ex(0.0 - _3);
  }
  ifn = (long)fn;
  if (int temp_var_for_tac_5; int temp_var_for_const_3;
      temp_var_for_tac_5 = ((float)ifn) != fn;

      ) {
    if (int temp_var_for_tac_6; int temp_var_for_const_4;
        float temp_var_for_callexp_0;

        temp_var_for_callexp_0 = __ieee754_rintf(fn);
        temp_var_for_tac_6 = temp_var_for_callexp_0 != fn;

        ) {
      feraiseexcept(FE_INVALID);
      float temp_var_for_ext_4;
      float temp_var_for_const_5;
      float temp_var_for_callexp_1;

      temp_var_for_callexp_1 = __builtin_nanf("");
      temp_var_for_ext_4 = temp_var_for_callexp_1;
      compute((Addr)&temp_var_for_tac_5,
              {(Addr) &(temp_var_for_const_3 = ((float)ifn)), (Addr)&fn},
              "/home/shijia/Public/testprogram/e_scalbf.c_e.c:60:18");
      compute(
          (Addr)&temp_var_for_tac_6,
          {(Addr) &(temp_var_for_const_4 = temp_var_for_callexp_0), (Addr)&fn},
          "/home/shijia/Public/testprogram/e_scalbf.c_e.c:61:29");
      AssignF({(Addr)&temp_var_for_ext_4},
              (Addr) &(temp_var_for_const_5 = temp_var_for_callexp_1),
              "/home/shijia/Public/testprogram/e_scalbf.c_e.c:64:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_4;
    }
    if (ifn > 65000l) {
      float temp_var_for_ext_5;
      float temp_var_for_const_6;
      float temp_var_for_callexp_2;

      temp_var_for_callexp_2 = __ieee754_scalblnf(x, 65000l);
      temp_var_for_ext_5 = temp_var_for_callexp_2;
      AssignF({(Addr)&temp_var_for_ext_5},
              (Addr) &(temp_var_for_const_6 = temp_var_for_callexp_2),
              "/home/shijia/Public/testprogram/e_scalbf.c_e.c:72:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_5;
    }

    float temp_var_for_ext_6;
    float temp_var_for_const_7;
    float temp_var_for_callexp_3;

    temp_var_for_callexp_3 = __ieee754_scalblnf(x, (-(65000l)));
    temp_var_for_ext_6 = temp_var_for_callexp_3;
    AssignF({(Addr)&temp_var_for_ext_6},
            (Addr) &(temp_var_for_const_7 = temp_var_for_callexp_3),
            "/home/shijia/Public/testprogram/e_scalbf.c_e.c:80:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_6;
  }

  float temp_var_for_ext_7;
  float temp_var_for_const_8;
  float temp_var_for_callexp_4;

  temp_var_for_callexp_4 = __ieee754_scalblnf(x, ifn);
  temp_var_for_ext_7 = temp_var_for_callexp_4;
  AssignF({(Addr)&temp_var_for_ext_7},
          (Addr) &(temp_var_for_const_8 = temp_var_for_callexp_4),
          "/home/shijia/Public/testprogram/e_scalbf.c_e.c:87:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_7;
}

static float __attribute__((noinline)) sysv_scalbf(float x, float fn) {
  float z = __ieee754_scalbf(x, fn);

  if (isinf(z)) {
    if (isfinite(x)) {
      float temp_var_for_ext_8;
      float temp_var_for_const_9;
      float temp_var_for_callexp_5;

      temp_var_for_callexp_5 =
          __kernel_standard_f(x, fn, z, KMATHERR_SCALB_OVERFLOW);
      temp_var_for_ext_8 = temp_var_for_callexp_5;
      AssignF({(Addr)&temp_var_for_ext_8},
              (Addr) &(temp_var_for_const_9 = temp_var_for_callexp_5),
              "/home/shijia/Public/testprogram/e_scalbf.c_e.c:99:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_8;
    }
    /* scalb overflow */
    else {
      __set_errno(ERANGE);
    }

  } else {
    if
  }
  (z == 0.0F && z != x) return __kernel_standard_f(
      x, fn, z, KMATHERRF_SCALB_UNDERFLOW); /* scalb underflow */

  float temp_var_for_ext_9;
  temp_var_for_ext_9 = z;
  AssignF({(Addr)&temp_var_for_ext_9}, (Addr)&z,
          "/home/shijia/Public/testprogram/e_scalbf.c_e.c:118:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_9;
}

/* Wrapper scalb */
float __scalbf(float x, float fn) {
  if (_LIB_VERSION == _SVID_) {
    return sysv_scalbf(x, fn);
  } else {
    float z = __ieee754_scalbf(x, fn);

    if (!isfinite(z) || z == 0.0F) {
      if (isnan(z)) {
        if (!isnan(x) && !isnan(fn))
          z = __kernel_standard_f(x, fn, z, KMATHERRF_SCALB_INVALID);
      } else if (isinf(z)) {
        if (!isinf(x) && !isinf(fn))
          z = __kernel_standard_f(x, fn, z, KMATHERRF_SCALB_OVERFLOW);
      } else {
        /* z == 0.  */
        if (x != 0.0F && !isinf(fn))
          z = __kernel_standard_f(x, fn, z, KMATHERRF_SCALB_UNDERFLOW);
      }
    }
    return z;
  }
}

__typeof(__scalbf) scalbf __attribute__((weak, alias("__scalbf")));
