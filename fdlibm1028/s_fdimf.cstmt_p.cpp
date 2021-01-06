#include "../ScDebug/scdebug.h"
/* Return positive difference between arguments.
   Copyright (C) 1997-2013 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by Ulrich Drepper <drepper@cygnus.com>, 1997.

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

float __fdimf(float x, float y) {
  float r;

  if (islessequal(x, y)) {
    float temp_var_for_ext_0;
    temp_var_for_ext_0 = 0.0f;
    float temp_var_for_const_0;
    AssignF({(Addr)&temp_var_for_ext_0}, (Addr) &(temp_var_for_const_0 = 0.0f),
            "/home/shijia/Public/testprogram/s_fdimf.c_e.c:29:24");
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  r = x - y;
  computeFSub((Addr)&r, {(Addr)&x, (Addr)&y},
              "/home/shijia/Public/testprogram/s_fdimf.c_e.c:35:5");

  if (isinf(r) && !isinf(x) && !isinf(y))
    __set_errno(ERANGE);

  float temp_var_for_ext_1;
  temp_var_for_ext_1 = r;
  AssignF({(Addr)&temp_var_for_ext_1}, (Addr)&r,
          "/home/shijia/Public/testprogram/s_fdimf.c_e.c:41:22");
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

__typeof(__fdimf) fdimf __attribute__((weak, alias("__fdimf")));
