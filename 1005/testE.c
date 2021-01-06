/*
 * testE.c
 *
 *  Created on: Sep 28, 2020
 *      Author: shijia
 */
#include <stdio.h>
#include <math.h>
//#include <time.h>
int main() {
	double fa = 1.2, fb = 2.1;
	for (int a = 1, b = 2; a <= 3; a++, b++) {
		printf("%d,%d\n", a, b);
		int c = a;
	}
	for (int c = 1; c < 10; c = c + 4)
		c = c - 2;
//	if (fa + fb > 0)
	{
		fa = fb + fb + fb + fb + fb;
		fa = fb + fa;
		fb++;
		fa = fa++;
		++fa;
		fa--;
		--fb;
		fb = fa + ++fa;
		printf("%le\n", fb);
		fa = -fa;
	}
	return 0;
}
