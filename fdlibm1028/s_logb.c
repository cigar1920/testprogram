/* @(#)s_logb.c 1.3 95/01/18 */
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
 * double logb(x)
 * IEEE 754 logb. Included to pass IEEE test suite. Not recommend.
 * Use ilogb instead.
 */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif


double __logb(double x)
{
	int32_t lx, ix, rix;

	GET_DOUBLE_WORDS(ix, lx, x);
	ix &= IC(0x7fffffff);					/* high |x| */
	if ((ix | lx) == 0)
		{
return -1.0 / __ieee754_fabs(x);
}

	if (ix >= IC(0x7ff00000))
		{
return x * x;
}

	if ((rix = ix >> IEEE754_DOUBLE_SHIFT) == 0)
	{
		/* POSIX specifies that denormal number is treated as
		   though it were normalized.  */
		int32_t ma;

		if (ix == 0)
			{
ma = count_leading_zeros(lx) + 32;
}

		else
			{
ma = count_leading_zeros(ix);
}

		rix -= ma - 12;
	}
	return (double) (rix - IEEE754_DOUBLE_BIAS);
}

__typeof(__logb) logb __attribute__((weak, alias("__logb")));
#ifdef __NO_LONG_DOUBLE_MATH
__typeof(__logbl) __logbl __attribute__((alias("__logb")));
__typeof(__logbl) logbl __attribute__((weak, alias("__logb")));
#endif
