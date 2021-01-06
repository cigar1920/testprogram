#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;

int main(int argc, char const *argv[]) {
	double lower = atof(argv[1]);
	double upper = atof(argv[2]);
	double step = atof(argv[3]) / 2;
	int lower2 = atoi(argv[4]);
	int upper2 = atoi(argv[5]);
	int step2 = atoi(argv[6]) / 2;
	for(double i = lower; i <= upper; i += step) {
		for(int j = lower2; j <= upper2; j += step2) {
			printf("%.100le %d\n", i, j);
		}
	}
	return 0;
}
