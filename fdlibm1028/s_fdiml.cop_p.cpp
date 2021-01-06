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

#ifndef __NO_LONG_DOUBLE_MATH
long double __fdiml(long double x, long double y) {
  long double r;

  if (islessequal(x, y)) {
    long double temp_var_for_ext_0;
    long double temp_var_for_const_0;
    temp_var_for_ext_0 = 0.0L;
    AssignLd({(Addr)&temp_var_for_ext_0}, (Addr) &(temp_var_for_const_0 = 0.0L),
             "/home/shijia/Public/testprogram/s_fdiml.c_e.c:30:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  long double temp_var_for_tac_0;
  temp_var_for_tac_0 = x - y;

  r = temp_var_for_tac_0;
  computeLdSub((Addr)&temp_var_for_tac_0, {(Addr)&x, (Addr)&y},
               "/home/shijia/Public/testprogram/s_fdiml.c_e.c:36:9");
  AssignLd({(Addr)&r}, (Addr)&temp_var_for_tac_0,
           "/home/shijia/Public/testprogram/s_fdiml.c_e.c:36:5");
  ;

  if (isinf(r) && !isinf(x) && !isinf(y)) {
    __set_errno(ERANGE);
  }

  long double temp_var_for_ext_1;
  temp_var_for_ext_1 = r;
  AssignLd({(Addr)&temp_var_for_ext_1}, (Addr)&r,
           "/home/shijia/Public/testprogram/s_fdiml.c_e.c:43:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

__typeof(__fdiml) fdiml __attribute__((weak, alias("__fdiml")));

#endif
