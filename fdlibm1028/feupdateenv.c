/* Install given floating-point environment and raise exceptions.
   Copyright (C) 1997-2013 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by Andreas Schwab <schwab@issan.informatik.uni-dortmund.de>

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library.  If not, see
   <http://www.gnu.org/licenses/>.  */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif
#include "fpu_ctrl.h"

int __feupdateenv(const fenv_t *envp)
{
	fexcept_t fpsr;

	/* Save current exceptions.  */
	_FPU_GETSR(fpsr);
	fpsr &= FE_ALL_EXCEPT;

	/* Install new environment.  */
	fesetenv(envp);

	/* Raise the saved exception.  Incidently for us the implementation
	   defined format of the values in objects of type fexcept_t is the
	   same as the ones specified using the FE_* constants.  */
	feraiseexcept((int) fpsr);

	/* Success.  */
	return 0;
}

__typeof(__feupdateenv) feupdateenv __attribute__((weak, alias("__feupdateenv")));
