#include "../ScDebug/scdebug.h"
/*							logll.c
 *
 * Natural logarithm for 128-bit long double precision.
 *
 *
 *
 * SYNOPSIS:
 *
 * long double x, y, logl();
 *
 * y = logl( x );
 *
 *
 *
 * DESCRIPTION:
 *
 * Returns the base e (2.718...) logarithm of x.
 *
 * The argument is separated into its exponent and fractional
 * parts.  Use of a lookup table increases the speed of the routine.
 * The program uses logarithms tabulated at intervals of 1/128 to
 * cover the domain from approximately 0.7 to 1.4.
 *
 * On the interval [-1/128, +1/128] the logarithm of 1+x is approximated by
 *     log(1+x) = x - 0.5 x^2 + x^3 P(x) .
 *
 *
 *
 * ACCURACY:
 *
 *                      Relative error:
 * arithmetic   domain     # trials      peak         rms
 *    IEEE   0.875, 1.125   100000      1.2e-34    4.1e-35
 *    IEEE   0.125, 8       100000      1.2e-34    4.1e-35
 *
 *
 * WARNING:
 *
 * This program uses integer operations on bit fields of floating-point
 * numbers.  It does not work with data structures other than the
 * structure assumed.
 *
 */

/* Copyright 2001 by Stephen L. Moshier <moshier@na-net.ornl.gov>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, see
    <http://www.gnu.org/licenses/>.  */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

#ifndef __have_fpu_log

long double __ieee754_logl(long double x) {
#if 0
	long double z, y, w;
	long double u, t;
	uint32_t m, k;
	int32_t e;
	uint32_t msw, lsw;
	
	/* log(1+x) = x - .5 x^2 + x^3 l(x)
	   -.0078125 <= x <= +.0078125
	   peak relative error 1.2e-37 */
	static const long double l3 = 3.333333333333333333333333333333336096926E-1L;
	static const long double l4 = -2.499999999999999999999999999486853077002E-1L;
	static const long double l5 = 1.999999999999999999999999998515277861905E-1L;
	static const long double l6 = -1.666666666666666666666798448356171665678E-1L;
	static const long double l7 = 1.428571428571428571428808945895490721564E-1L;
	static const long double l8 = -1.249999999999999987884655626377588149000E-1L;
	static const long double l9 = 1.111111111111111093947834982832456459186E-1L;
	static const long double l10 = -1.000000000000532974938900317952530453248E-1L;
	static const long double l11 = 9.090909090915566247008015301349979892689E-2L;
	static const long double l12 = -8.333333211818065121250921925397567745734E-2L;
	static const long double l13 = 7.692307559897661630807048686258659316091E-2L;
	static const long double l14 = -7.144242754190814657241902218399056829264E-2L;
	static const long double l15 = 6.668057591071739754844678883223432347481E-2L;
	
	/* Lookup table of ln(t) - (t-1)
	    t = 0.5 + (k+26)/128)
	    k = 0, ..., 91   */
	static const long double logtbl[92] = {
		-5.5345593589352099112142921677820359632418E-2L,
		-5.2108257402767124761784665198737642086148E-2L,
		-4.8991686870576856279407775480686721935120E-2L,
		-4.5993270766361228596215288742353061431071E-2L,
		-4.3110481649613269682442058976885699556950E-2L,
		-4.0340872319076331310838085093194799765520E-2L,
		-3.7682072451780927439219005993827431503510E-2L,
		-3.5131785416234343803903228503274262719586E-2L,
		-3.2687785249045246292687241862699949178831E-2L,
		-3.0347913785027239068190798397055267411813E-2L,
		-2.8110077931525797884641940838507561326298E-2L,
		-2.5972247078357715036426583294246819637618E-2L,
		-2.3932450635346084858612873953407168217307E-2L,
		-2.1988775689981395152022535153795155900240E-2L,
		-2.0139364778244501615441044267387667496733E-2L,
		-1.8382413762093794819267536615342902718324E-2L,
		-1.6716169807550022358923589720001638093023E-2L,
		-1.5138929457710992616226033183958974965355E-2L,
		-1.3649036795397472900424896523305726435029E-2L,
		-1.2244881690473465543308397998034325468152E-2L,
		-1.0924898127200937840689817557742469105693E-2L,
		-9.6875626072830301572839422532631079809328E-3L,
		-8.5313926245226231463436209313499745894157E-3L,
		-7.4549452072765973384933565912143044991706E-3L,
		-6.4568155251217050991200599386801665681310E-3L,
		-5.5356355563671005131126851708522185605193E-3L,
		-4.6900728132525199028885749289712348829878E-3L,
		-3.9188291218610470766469347968659624282519E-3L,
		-3.2206394539524058873423550293617843896540E-3L,
		-2.5942708080877805657374888909297113032132E-3L,
		-2.0385211375711716729239156839929281289086E-3L,
		-1.5522183228760777967376942769773768850872E-3L,
		-1.1342191863606077520036253234446621373191E-3L,
		-7.8340854719967065861624024730268350459991E-4L,
		-4.9869831458030115699628274852562992756174E-4L,
		-2.7902661731604211834685052867305795169688E-4L,
		-1.2335696813916860754951146082826952093496E-4L,
		-3.0677461025892873184042490943581654591817E-5L,
#define ZERO logtbl[38]
		0.0000000000000000000000000000000000000000E0L,
		-3.0359557945051052537099938863236321874198E-5L,
		-1.2081346403474584914595395755316412213151E-4L,
		-2.7044071846562177120083903771008342059094E-4L,
		-4.7834133324631162897179240322783590830326E-4L,
		-7.4363569786340080624467487620270965403695E-4L,
		-1.0654639687057968333207323853366578860679E-3L,
		-1.4429854811877171341298062134712230604279E-3L,
		-1.8753781835651574193938679595797367137975E-3L,
		-2.3618380914922506054347222273705859653658E-3L,
		-2.9015787624124743013946600163375853631299E-3L,
		-3.4938307889254087318399313316921940859043E-3L,
		-4.1378413103128673800485306215154712148146E-3L,
		-4.8328735414488877044289435125365629849599E-3L,
		-5.5782063183564351739381962360253116934243E-3L,
		-6.3731336597098858051938306767880719015261E-3L,
		-7.2169643436165454612058905294782949315193E-3L,
		-8.1090214990427641365934846191367315083867E-3L,
		-9.0486422112807274112838713105168375482480E-3L,
		-1.0035177140880864314674126398350812606841E-2L,
		-1.1067990155502102718064936259435676477423E-2L,
		-1.2146457974158024928196575103115488672416E-2L,
		-1.3269969823361415906628825374158424754308E-2L,
		-1.4437927104692837124388550722759686270765E-2L,
		-1.5649743073340777659901053944852735064621E-2L,
		-1.6904842527181702880599758489058031645317E-2L,
		-1.8202661505988007336096407340750378994209E-2L,
		-1.9542647000370545390701192438691126552961E-2L,
		-2.0924256670080119637427928803038530924742E-2L,
		-2.2346958571309108496179613803760727786257E-2L,
		-2.3810230892650362330447187267648486279460E-2L,
		-2.5313561699385640380910474255652501521033E-2L,
		-2.6856448685790244233704909690165496625399E-2L,
		-2.8438398935154170008519274953860128449036E-2L,
		-3.0058928687233090922411781058956589863039E-2L,
		-3.1717563112854831855692484086486099896614E-2L,
		-3.3413836095418743219397234253475252001090E-2L,
		-3.5147290019036555862676702093393332533702E-2L,
		-3.6917475563073933027920505457688955423688E-2L,
		-3.8723951502862058660874073462456610731178E-2L,
		-4.0566284516358241168330505467000838017425E-2L,
		-4.2444048996543693813649967076598766917965E-2L,
		-4.4356826869355401653098777649745233339196E-2L,
		-4.6304207416957323121106944474331029996141E-2L,
		-4.8285787106164123613318093945035804818364E-2L,
		-5.0301169421838218987124461766244507342648E-2L,
		-5.2349964705088137924875459464622098310997E-2L,
		-5.4431789996103111613753440311680967840214E-2L,
		-5.6546268881465384189752786409400404404794E-2L,
		-5.8693031345788023909329239565012647817664E-2L,
		-6.0871713627532018185577188079210189048340E-2L,
		-6.3081958078862169742820420185833800925568E-2L,
		-6.5323413029406789694910800219643791556918E-2L,
		-6.7595732653791419081537811574227049288168E-2L
	};
	
	/* ln(2) = ln2a + ln2b with extended precision. */
	static const long double ln2a = 6.93145751953125e-1L;
	static const long double ln2b = 1.4286068203094172321214581765680755001344E-6L;
	
	static const long double ldbl_epsilon = hexconstl(0x1p-106L, 1.2325951644078309459558e-32L, 0x3f95, UC(0x80000000), UC(0x00000000));

	u = x;
	GET_LDOUBLE_WORDS(m, msw, lsw, u);
	msw &= IC(0x7fffffff);
	
	/* Check for IEEE special cases.  */
	k = ((m & 0x7fff) << 16) | (msw >> 16);
	/* log(0) = -infinity. */
	if ((k | (msw & UC(0x7fffffff)) | lsw) == 0)
	{
		return -0.5L / ZERO;
	}
	/* log ( x < 0 ) = NaN */
	if (m & 0x8000)
	{
		return (x - x) / ZERO;
	}
	/* log (infinity or NaN) */
	if (k >= UC(0x7fff0000))
	{
		return x + x;
	}

	/* On this interval the table is not used due to cancellation error.  */
	if (x <= 1.0078125L && x >= 0.9921875L)
	{
		if (x == 1.0L)
			return 0.0L;
		z = x - 1.0L;
		k = 64;
		t = 1.0L;
		e = 0;
	} else
	{
		/* Extract exponent and reduce domain to 0.703125 <= u < 1.40625  */
		e = m - 0x3ffe;
		SET_LDOUBLE_EXP(u, 0x3ffe);
		m = (msw >> 16) | IC(0x10000);
		/* Find lookup table index k from high order bits of the significand. */
		if (m < UC(0x16800))
		{
			k = (m - UC(0xff00)) >> 9;
			/* t is the argument 0.5 + (k+26)/128
			   of the nearest item to u in the lookup table.  */
			SET_LDOUBLE_WORDS(t, 0x3fff, (k << 25) | UC(0x80000000), 0);
			SET_LDOUBLE_EXP(u, 0x3fff);
			e -= 1;
			k += 64;
		} else
		{
			k = (m - UC(0xfe00)) >> 10;
			SET_LDOUBLE_WORDS(t, 0x3ffe, (k << 26) | UC(0x80000000), 0);
		}
		/* log(u) = log( t u/t ) = log(t) + log(u/t)
		   log(t) is tabulated in the lookup table.
		   Express log(u/t) = log(1+z),  where z = u/t - 1 = (u-t)/t.
		   cf. Cody & Waite. */
		z = (u - t) / t;
	}
	/* Series expansion of log(1+z).  */
	w = z * z;
	/* Avoid spurious underflows.  */
	if (w <= ldbl_epsilon)
		y = 0.0L;
	else
	{
		y = ((((((((((((l15 * z
						+ l14) * z
					   + l13) * z
					  + l12) * z
					 + l11) * z
					+ l10) * z
				   + l9) * z
				  + l8) * z
				 + l7) * z
				+ l6) * z
			   + l5) * z
			  + l4) * z
			 + l3) * z * w;
		y -= 0.5 * w;
	}
	y += e * ln2b;						/* Base 2 exponent offset times ln(2).  */
	y += z;
	y += logtbl[k - 26];				/* log(t) - (t-1) */
	y += (t - 1.0L);
	y += e * ln2a;
	return y;
#undef ZERO
#else
  long double hfsq, f, s, z, R, w, t1, t2, dk;
  int32_t k, hx, i, j;
  uint32_t lx;
  uint32_t m;

  static const long double ln2_hi = 6.93145751953125e-1L;
  static const long double ln2_lo =
      1.4286068203094172321214581765680755001344E-6L;
  static const long double Lg1 =
      6.666666666666735130e-01L; /* 3FE55555 55555593 */
  static const long double Lg2 =
      3.999999999940941908e-01L; /* 3FD99999 9997FA04 */
  static const long double Lg3 =
      2.857142874366239149e-01L; /* 3FD24924 94229359 */
  static const long double Lg4 =
      2.222219843214978396e-01L; /* 3FCC71C5 1D8E78AF */
  static const long double Lg5 =
      1.818357216161805012e-01L; /* 3FC74664 96CB03DE */
  static const long double Lg6 =
      1.531383769920937332e-01L; /* 3FC39A09 D078C69F */
  static const long double Lg7 =
      1.479819860511658591e-01L; /* 3FC2F112 DF3E5244 */

  static const long double zero = 0.0;

  long double temp_var_for_const_0;
  ew_u.value = x;
  AssignLd({(Addr) &(temp_var_for_const_0 = ew_u.value)}, (Addr)&x,
           "/home/shijia/Public/testprogram/e_logl.c_e.c:312:3 "
           "<Spelling=/home/shijia/Public/testprogram/fdlibm.h:197:14>");
  ;
  k = m & 0x7fff;

  /* log(0) = -infinity. */
  if ((k | (hx & UC(0x7fffffff)) | lx) == 0) {
    long double temp_var_for_ext_0;
    long double temp_var_for_tac_0;
    long double temp_var_for_const_1, temp_var_for_const_2;
    temp_var_for_tac_0 = (-(0.5L)) / zero;

    temp_var_for_ext_0 = temp_var_for_tac_0;
    computeLdDiv((Addr)&temp_var_for_tac_0,
                 {(Addr) &(temp_var_for_const_2 = (-(0.5L))),
                  (Addr) &(temp_var_for_const_1 = zero)},
                 "/home/shijia/Public/testprogram/e_logl.c_e.c:318:32");
    AssignLd({(Addr)&temp_var_for_ext_0}, (Addr)&temp_var_for_tac_0,
             "/home/shijia/Public/testprogram/e_logl.c_e.c:318:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return (0.0 - r_fo)r_ext_0;
  }
  if (m & 0x8000) {
    long double temp_var_for_ext_1;
    long double temp_var_for_tac_1, temp_var_for_tac_2;
    long double temp_var_for_const_3;
    temp_var_for_tac_1 = x - x;

    temp_var_for_tac_2 = temp_var_for_tac_1 / zero;

    temp_var_for_ext_1 = temp_var_for_tac_2;
    computeLdSub((Addr)&temp_var_for_tac_1, {(Addr)&x, (Addr)&x},
                 "/home/shijia/Public/testprogram/e_logl.c_e.c:325:29");
    computeLdDiv(
        (Addr)&temp_var_for_tac_2,
        {(Addr)&temp_var_for_tac_1, (Addr) &(temp_var_for_const_3 = zero)},
        "/home/shijia/Public/testprogram/e_logl.c_e.c:325:34");
    AssignLd({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_2,
             "/home/shijia/Public/testprogram/e_logl.c_e.c:325:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_1;
  }
  /* log(-#) = NaN */
  /* log (infinity or NaN) */
  if (k >= 0x7fff) {
    long double temp_var_for_ext_2;
    long double temp_var_for_tac_3;
    temp_var_for_tac_3 = x + x;

    temp_var_for_ext_2 = temp_var_for_tac_3;
    computeLdAdd((Addr)&temp_var_for_tac_3, {(Addr)&x, (Addr)&x},
                 "/home/shijia/Public/testprogram/e_logl.c_e.c:334:28");
    AssignLd({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_3,
             "/home/shijia/Public/testprogram/e_logl.c_e.c:334:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_2;
  }

  k -= 0x3fff;
  hx &= IC(0x7fffffff);
  i = (((hx >> 11) + IC(0x95f64)) & IC(0x100000)) >> 20;
  long double temp_var_for_ext_3;
  temp_var_for_ext_3; /* normalize x or x/2 */
  k += i;
  long double temp_var_for_tac_4;
  long double temp_var_for_const_4;
  temp_var_for_tac_4 = x - 1.0;

  f = temp_var_for_tac_4;
  computeLdSub((Addr)&temp_var_for_tac_4,
               {(Addr)&x, (Addr) &(temp_var_for_const_4 = 1.0)},
               "/home/shijia/Public/testprogram/e_logl.c_e.c:346:9");
  AssignLd({(Addr)&f}, (Addr)&temp_var_for_tac_4,
           "/home/shijia/Public/testprogram/e_logl.c_e.c:346:5");
  ;
#if 0
	if ((IC(0x7fffffff) & (2 + hx)) < 3)
	{									/* |f| < 2**-20 */
		if (f == zero)
		{
			if (k == 0)
				return zero;
			dk = (long double) k;
			return dk * ln2_hi + dk * ln2_lo;
		}
		R = f * f * (0.5L - 0.33333333333333333333333333L * f);
		if (k == 0)
			return f - R;
		dk = (long double) k;
		return dk * ln2_hi - ((R - dk * ln2_lo) - f);
	}
#endif
  long double temp_var_for_tac_5, temp_var_for_tac_6;
  long double temp_var_for_const_5;
  temp_var_for_tac_5 = 2.0 + f;

  temp_var_for_tac_6 = f / temp_var_for_tac_5;

  s = temp_var_for_tac_6;
  computeLdAdd((Addr)&temp_var_for_tac_5,
               {(Addr) &(temp_var_for_const_5 = 2.0), (Addr)&f},
               "/home/shijia/Public/testprogram/e_logl.c_e.c:364:16");
  computeLdDiv((Addr)&temp_var_for_tac_6, {(Addr)&f, (Addr)&temp_var_for_tac_5},
               "/home/shijia/Public/testprogram/e_logl.c_e.c:364:9");
  AssignLd({(Addr)&s}, (Addr)&temp_var_for_tac_6,
           "/home/shijia/Public/testprogram/e_logl.c_e.c:364:5");
  ;
  long double temp_var_for_const_6;
  dk = ((long double)k);
  AssignLd({(Addr)&dk}, (Addr) &(temp_var_for_const_6 = ((long double)k)),
           "/home/shijia/Public/testprogram/e_logl.c_e.c:365:6");
  ;
  long double temp_var_for_tac_7;
  temp_var_for_tac_7 = s * s;

  z = temp_var_for_tac_7;
  computeLdMul((Addr)&temp_var_for_tac_7, {(Addr)&s, (Addr)&s},
               "/home/shijia/Public/testprogram/e_logl.c_e.c:366:9");
  AssignLd({(Addr)&z}, (Addr)&temp_var_for_tac_7,
           "/home/shijia/Public/testprogram/e_logl.c_e.c:366:5");
  ;
  i = hx - IC(0x6147a000);
  long double temp_var_for_tac_8;
  temp_var_for_tac_8 = z * z;

  w = temp_var_for_tac_8;
  computeLdMul((Addr)&temp_var_for_tac_8, {(Addr)&z, (Addr)&z},
               "/home/shijia/Public/testprogram/e_logl.c_e.c:368:9");
  AssignLd({(Addr)&w}, (Addr)&temp_var_for_tac_8,
           "/home/shijia/Public/testprogram/e_logl.c_e.c:368:5");
  ;
  j = IC(0x6b851000) - hx;
  long double temp_var_for_tac_9, temp_var_for_tac_10, temp_var_for_tac_11,
      temp_var_for_tac_12, temp_var_for_tac_13;
  long double temp_var_for_const_7, temp_var_for_const_8, temp_var_for_const_9;
  temp_var_for_tac_9 = w * Lg6;

  temp_var_for_tac_10 = Lg4 + temp_var_for_tac_9;

  temp_var_for_tac_11 = w * temp_var_for_tac_10;

  temp_var_for_tac_12 = Lg2 + temp_var_for_tac_11;

  temp_var_for_tac_13 = w * temp_var_for_tac_12;

  t1 = temp_var_for_tac_13;
  computeLdMul((Addr)&temp_var_for_tac_9,
               {(Addr)&w, (Addr) &(temp_var_for_const_7 = Lg6)},
               "/home/shijia/Public/testprogram/e_logl.c_e.c:370:32");
  computeLdAdd(
      (Addr)&temp_var_for_tac_10,
      {(Addr) &(temp_var_for_const_8 = Lg4), (Addr)&temp_var_for_tac_9},
      "/home/shijia/Public/testprogram/e_logl.c_e.c:370:28");
  computeLdMul((Addr)&temp_var_for_tac_11,
               {(Addr)&w, (Addr)&temp_var_for_tac_10},
               "/home/shijia/Public/testprogram/e_logl.c_e.c:370:21");
  computeLdAdd(
      (Addr)&temp_var_for_tac_12,
      {(Addr) &(temp_var_for_const_9 = Lg2), (Addr)&temp_var_for_tac_11},
      "/home/shijia/Public/testprogram/e_logl.c_e.c:370:17");
  computeLdMul((Addr)&temp_var_for_tac_13,
               {(Addr)&w, (Addr)&temp_var_for_tac_12},
               "/home/shijia/Public/testprogram/e_logl.c_e.c:370:10");
  AssignLd({(Addr)&t1}, (Addr)&temp_var_for_tac_13,
           "/home/shijia/Public/testprogram/e_logl.c_e.c:370:6");
  ;
  long double temp_var_for_tac_14, temp_var_for_tac_15, temp_var_for_tac_16,
      temp_var_for_tac_17, temp_var_for_tac_18, temp_var_for_tac_19,
      temp_var_for_tac_20;
  long double temp_var_for_const_10, temp_var_for_const_11,
      temp_var_for_const_12, temp_var_for_const_13;
  temp_var_for_tac_14 = w * Lg7;

  temp_var_for_tac_15 = Lg5 + temp_var_for_tac_14;

  temp_var_for_tac_16 = w * temp_var_for_tac_15;

  temp_var_for_tac_17 = Lg3 + temp_var_for_tac_16;

  temp_var_for_tac_18 = w * temp_var_for_tac_17;

  temp_var_for_tac_19 = Lg1 + temp_var_for_tac_18;

  temp_var_for_tac_20 = z * temp_var_for_tac_19;

  t2 = temp_var_for_tac_20;
  computeLdMul((Addr)&temp_var_for_tac_14,
               {(Addr)&w, (Addr) &(temp_var_for_const_10 = Lg7)},
               "/home/shijia/Public/testprogram/e_logl.c_e.c:371:43");
  computeLdAdd(
      (Addr)&temp_var_for_tac_15,
      {(Addr) &(temp_var_for_const_11 = Lg5), (Addr)&temp_var_for_tac_14},
      "/home/shijia/Public/testprogram/e_logl.c_e.c:371:39");
  computeLdMul((Addr)&temp_var_for_tac_16,
               {(Addr)&w, (Addr)&temp_var_for_tac_15},
               "/home/shijia/Public/testprogram/e_logl.c_e.c:371:32");
  computeLdAdd(
      (Addr)&temp_var_for_tac_17,
      {(Addr) &(temp_var_for_const_12 = Lg3), (Addr)&temp_var_for_tac_16},
      "/home/shijia/Public/testprogram/e_logl.c_e.c:371:28");
  computeLdMul((Addr)&temp_var_for_tac_18,
               {(Addr)&w, (Addr)&temp_var_for_tac_17},
               "/home/shijia/Public/testprogram/e_logl.c_e.c:371:21");
  computeLdAdd(
      (Addr)&temp_var_for_tac_19,
      {(Addr) &(temp_var_for_const_13 = Lg1), (Addr)&temp_var_for_tac_18},
      "/home/shijia/Public/testprogram/e_logl.c_e.c:371:17");
  computeLdMul((Addr)&temp_var_for_tac_20,
               {(Addr)&z, (Addr)&temp_var_for_tac_19},
               "/home/shijia/Public/testprogram/e_logl.c_e.c:371:10");
  AssignLd({(Addr)&t2}, (Addr)&temp_var_for_tac_20,
           "/home/shijia/Public/testprogram/e_logl.c_e.c:371:6");
  ;
  i |= j;
  long double temp_var_for_tac_21;
  temp_var_for_tac_21 = t2 + t1;

  R = temp_var_for_tac_21;
  computeLdAdd((Addr)&temp_var_for_tac_21, {(Addr)&t2, (Addr)&t1},
               "/home/shijia/Public/testprogram/e_logl.c_e.c:373:10");
  AssignLd({(Addr)&R}, (Addr)&temp_var_for_tac_21,
           "/home/shijia/Public/testprogram/e_logl.c_e.c:373:5");
  ;
  if (i > 0) {
    long double temp_var_for_tac_22, temp_var_for_tac_23;
    long double temp_var_for_const_14;
    temp_var_for_tac_22 = 0.5 * f;

    temp_var_for_tac_23 = temp_var_for_tac_22 * f;

    hfsq = temp_var_for_tac_23;
    computeLdMul((Addr)&temp_var_for_tac_22,
                 {(Addr) &(temp_var_for_const_14 = 0.5), (Addr)&f},
                 "/home/shijia/Public/testprogram/e_logl.c_e.c:375:16");
    computeLdMul((Addr)&temp_var_for_tac_23,
                 {(Addr)&temp_var_for_tac_22, (Addr)&f},
                 "/home/shijia/Public/testprogram/e_logl.c_e.c:375:20");
    AssignLd({(Addr)&hfsq}, (Addr)&temp_var_for_tac_23,
             "/home/shijia/Public/testprogram/e_logl.c_e.c:375:10");
    ;
    if (k == 0) {
      long double temp_var_for_ext_4;
      long double temp_var_for_tac_24, temp_var_for_tac_25, temp_var_for_tac_26,
          temp_var_for_tac_27;
      temp_var_for_tac_24 = hfsq + R;

      temp_var_for_tac_25 = s * temp_var_for_tac_24;

      temp_var_for_tac_26 = hfsq - temp_var_for_tac_25;

      temp_var_for_tac_27 = f - temp_var_for_tac_26;

      temp_var_for_ext_4 = temp_var_for_tac_27;
      computeLdAdd((Addr)&temp_var_for_tac_24, {(Addr)&hfsq, (Addr)&R},
                   "/home/shijia/Public/testprogram/e_logl.c_e.c:378:50");
      computeLdMul((Addr)&temp_var_for_tac_25,
                   {(Addr)&s, (Addr)&temp_var_for_tac_24},
                   "/home/shijia/Public/testprogram/e_logl.c_e.c:378:42");
      computeLdSub((Addr)&temp_var_for_tac_26,
                   {(Addr)&hfsq, (Addr)&temp_var_for_tac_25},
                   "/home/shijia/Public/testprogram/e_logl.c_e.c:378:38");
      computeLdSub((Addr)&temp_var_for_tac_27,
                   {(Addr)&f, (Addr)&temp_var_for_tac_26},
                   "/home/shijia/Public/testprogram/e_logl.c_e.c:378:30");
      AssignLd({(Addr)&temp_var_for_ext_4}, (Addr)&temp_var_for_tac_27,
               "/home/shijia/Public/testprogram/e_logl.c_e.c:378:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_4;
    }

    long double temp_var_for_ext_5;
    long double temp_var_for_tac_28, temp_var_for_tac_29, temp_var_for_tac_30,
        temp_var_for_tac_31, temp_var_for_tac_32, temp_var_for_tac_33,
        temp_var_for_tac_34, temp_var_for_tac_35;
    long double temp_var_for_const_15, temp_var_for_const_16;
    temp_var_for_tac_28 = dk * ln2_hi;

    temp_var_for_tac_29 = hfsq + R;

    temp_var_for_tac_30 = s * temp_var_for_tac_29;

    temp_var_for_tac_31 = dk * ln2_lo;

    temp_var_for_tac_32 = temp_var_for_tac_30 + temp_var_for_tac_31;

    temp_var_for_tac_33 = hfsq - temp_var_for_tac_32;

    temp_var_for_tac_34 = temp_var_for_tac_33 - f;

    temp_var_for_tac_35 = temp_var_for_tac_28 - temp_var_for_tac_34;

    temp_var_for_ext_5 = temp_var_for_tac_35;
    computeLdMul((Addr)&temp_var_for_tac_28,
                 {(Addr)&dk, (Addr) &(temp_var_for_const_15 = ln2_hi)},
                 "/home/shijia/Public/testprogram/e_logl.c_e.c:387:12");
    computeLdAdd((Addr)&temp_var_for_tac_29, {(Addr)&hfsq, (Addr)&R},
                 "/home/shijia/Public/testprogram/e_logl.c_e.c:387:43");
    computeLdMul((Addr)&temp_var_for_tac_30,
                 {(Addr)&s, (Addr)&temp_var_for_tac_29},
                 "/home/shijia/Public/testprogram/e_logl.c_e.c:387:35");
    computeLdMul((Addr)&temp_var_for_tac_31,
                 {(Addr)&dk, (Addr) &(temp_var_for_const_16 = ln2_lo)},
                 "/home/shijia/Public/testprogram/e_logl.c_e.c:387:53");
    computeLdAdd((Addr)&temp_var_for_tac_32,
                 {(Addr)&temp_var_for_tac_30, (Addr)&temp_var_for_tac_31},
                 "/home/shijia/Public/testprogram/e_logl.c_e.c:387:48");
    computeLdSub((Addr)&temp_var_for_tac_33,
                 {(Addr)&hfsq, (Addr)&temp_var_for_tac_32},
                 "/home/shijia/Public/testprogram/e_logl.c_e.c:387:30");
    computeLdSub((Addr)&temp_var_for_tac_34,
                 {(Addr)&temp_var_for_tac_33, (Addr)&f},
                 "/home/shijia/Public/testprogram/e_logl.c_e.c:387:64");
    computeLdSub((Addr)&temp_var_for_tac_35,
                 {(Addr)&temp_var_for_tac_28, (Addr)&temp_var_for_tac_34},
                 "/home/shijia/Public/testprogram/e_logl.c_e.c:387:21");
    AssignLd({(Addr)&temp_var_for_ext_5}, (Addr)&temp_var_for_tac_35,
             "/home/shijia/Public/testprogram/e_logl.c_e.c:386:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_5", (Addr)&temp_var_for_ext_5));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_5;
  }
  if (k == 0) {
    long double temp_var_for_ext_6;
    long double temp_var_for_tac_36, temp_var_for_tac_37, temp_var_for_tac_38;
    temp_var_for_tac_36 = f - R;

    temp_var_for_tac_37 = s * temp_var_for_tac_36;

    temp_var_for_tac_38 = f - temp_var_for_tac_37;

    temp_var_for_ext_6 = temp_var_for_tac_38;
    computeLdSub((Addr)&temp_var_for_tac_36, {(Addr)&f, (Addr)&R},
                 "/home/shijia/Public/testprogram/e_logl.c_e.c:394:37");
    computeLdMul((Addr)&temp_var_for_tac_37,
                 {(Addr)&s, (Addr)&temp_var_for_tac_36},
                 "/home/shijia/Public/testprogram/e_logl.c_e.c:394:32");
    computeLdSub((Addr)&temp_var_for_tac_38,
                 {(Addr)&f, (Addr)&temp_var_for_tac_37},
                 "/home/shijia/Public/testprogram/e_logl.c_e.c:394:28");
    AssignLd({(Addr)&temp_var_for_ext_6}, (Addr)&temp_var_for_tac_38,
             "/home/shijia/Public/testprogram/e_logl.c_e.c:394:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_6", (Addr)&temp_var_for_ext_6));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_6;
  }

  long double temp_var_for_ext_7;
  long double temp_var_for_tac_39, temp_var_for_tac_40, temp_var_for_tac_41,
      temp_var_for_tac_42, temp_var_for_tac_43, temp_var_for_tac_44,
      temp_var_for_tac_45;
  long double temp_var_for_const_17, temp_var_for_const_18;
  temp_var_for_tac_39 = dk * ln2_hi;

  temp_var_for_tac_40 = f - R;

  temp_var_for_tac_41 = s * temp_var_for_tac_40;

  temp_var_for_tac_42 = dk * ln2_lo;

  temp_var_for_tac_43 = temp_var_for_tac_41 - temp_var_for_tac_42;

  temp_var_for_tac_44 = temp_var_for_tac_43 - f;

  temp_var_for_tac_45 = temp_var_for_tac_39 - temp_var_for_tac_44;

  temp_var_for_ext_7 = temp_var_for_tac_45;
  computeLdMul((Addr)&temp_var_for_tac_39,
               {(Addr)&dk, (Addr) &(temp_var_for_const_17 = ln2_hi)},
               "/home/shijia/Public/testprogram/e_logl.c_e.c:401:27");
  computeLdSub((Addr)&temp_var_for_tac_40, {(Addr)&f, (Addr)&R},
               "/home/shijia/Public/testprogram/e_logl.c_e.c:401:47");
  computeLdMul((Addr)&temp_var_for_tac_41,
               {(Addr)&s, (Addr)&temp_var_for_tac_40},
               "/home/shijia/Public/testprogram/e_logl.c_e.c:401:42");
  computeLdMul((Addr)&temp_var_for_tac_42,
               {(Addr)&dk, (Addr) &(temp_var_for_const_18 = ln2_lo)},
               "/home/shijia/Public/testprogram/e_logl.c_e.c:401:57");
  computeLdSub((Addr)&temp_var_for_tac_43,
               {(Addr)&temp_var_for_tac_41, (Addr)&temp_var_for_tac_42},
               "/home/shijia/Public/testprogram/e_logl.c_e.c:401:52");
  computeLdSub((Addr)&temp_var_for_tac_44,
               {(Addr)&temp_var_for_tac_43, (Addr)&f},
               "/home/shijia/Public/testprogram/e_logl.c_e.c:401:67");
  computeLdSub((Addr)&temp_var_for_tac_45,
               {(Addr)&temp_var_for_tac_39, (Addr)&temp_var_for_tac_44},
               "/home/shijia/Public/testprogram/e_logl.c_e.c:401:36");
  AssignLd({(Addr)&temp_var_for_ext_7}, (Addr)&temp_var_for_tac_45,
           "/home/shijia/Public/testprogram/e_logl.c_e.c:401:22");
  ;
  callExpStack.push(getReal("temp_var_for_ext_7", (Addr)&temp_var_for_ext_7));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_7;
#endif
}

#endif

/* wrapper logl(x) */
long double __logl(long double x) {
  if (islessequal(x, 0.0L) && _LIB_VERSION != _IEEE_) {
    if (int temp_var_for_tac_46; int temp_var_for_const_19;
        temp_var_for_tac_46 = x == 0.0L;

        ) {
      feraiseexcept(FE_DIVBYZERO);
      long double temp_var_for_ext_8;
      long double temp_var_for_const_20;
      long double temp_var_for_callexp_1;

      temp_var_for_callexp_0 = __builtin_huge_vall();
      temp_var_for_callexp_1 = __kernel_standard_l(
          x, x, (-(temp_var_for_callexp_0)), KMATHERRL_LOG_ZERO);
      temp_var_for_ext_8 = temp_var_for_callexp_1;
      compute((Addr)&temp_var_for_tac_46,
              {(Addr)&x, (Addr) &(temp_var_for_const_19 = 0.0L)},
              "/home/shijia/Public/testprogram/e_logl.c_e.c:413:11");
      AssignLd({(Addr)&temp_var_for_ext_8},
               (Addr) &(temp_var_for_const_20 = temp_var_for_callexp_1),
               "/home/shijia/Public/testprogram/e_logl.c_e.c:416:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_8", (Addr)&temp_var_for_ext_8));
      callExp++; /*identify the function is  add move tmpSha(0.0 - ow*/
retu)rn temp_var_for_ext_8;	/* log(0) */
    } else {
      feraiseexcept(FE_INVALID);
      long double temp_var_for_ext_9;
      long double temp_var_for_const_21;
      long double temp_var_for_callexp_2;

      /*embed fun has found*/
      long double temp_var_for_callexp_3;

      temp_var_for_callexp_2 = __builtin_nanl("");
      temp_var_for_callexp_3 = __kernel_standard_l(x, x, temp_var_for_callexp_2,
                                                   KMATHERRL_LOG_MINUS);
      temp_var_for_ext_9 = temp_var_for_callexp_3;
      AssignLd({(Addr)&temp_var_for_ext_9},
               (Addr) &(temp_var_for_const_21 = temp_var_for_callexp_3),
               "/home/shijia/Public/testprogram/e_logl.c_e.c:425:26");
      ;
      callExpStack.push(
          getReal("temp_var_for_ext_9", (Addr)&temp_var_for_ext_9));
      callExp++; /*identify the function is  add move tmpShadow*/
      return temp_var_for_ext_9; /* log(x<0) */
    }
  }

  long double temp_var_for_ext_10;
  long double temp_var_for_const_22;
  long double temp_var_for_callexp_4;

  temp_var_for_callexp_4 = __ieee754_logl(x);
  temp_var_for_ext_10 = temp_var_for_callexp_4;
  AssignLd({(Addr)&temp_var_for_ext_10},
           (Addr) &(temp_var_for_const_22 = temp_var_for_callexp_4),
           "/home/shijia/Public/testprogram/e_logl.c_e.c:435:23");
  ;
  callExpStack.push(getReal("temp_var_for_ext_10", (Addr)&temp_var_for_ext_10));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_10;
}

__typeof(__logl) logl __attribute__((weak, alias("__logl")));

#endif
