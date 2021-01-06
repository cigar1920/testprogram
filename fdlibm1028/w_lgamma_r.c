/* @(#)w_lgamma_r.c 1.3 95/01/18 */
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
 * wrapper double lgamma_r(double x, int *signgamp)
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

double __lgamma_r(double x, int *signgamp)
{
	double y = __ieee754_lgamma_r(x, signgamp);

	if (_LIB_VERSION != _IEEE_ && !isfinite(y) && isfinite(x))
		{
return __kernel_standard(x, x, y, __ieee754_floor(x) == x && x <= 0.0 ? KMATHERR_LGAMMA_MINUS	/* lgamma pole */
								 : KMATHERR_LGAMMA_OVERFLOW);
}
	/* lgamma overflow */

	return y;
}

__typeof(__lgamma_r) lgamma_r __attribute__((weak, alias("__lgamma_r")));
#ifdef __NO_LONG_DOUBLE_MATH
__typeof(__lgammal_r) __lgammal_r __attribute__((alias("__lgamma_r")));
__typeof(__lgammal_r) lgammal_r __attribute__((weak, alias("__lgamma_r")));
#endif
