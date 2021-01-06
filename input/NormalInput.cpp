#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;

int main(int argc, char const *argv[]) {
	double lower = atof(argv[1]);
	double upper = atof(argv[2]);
	double step = atof(argv[3]) / 2;
	srand(time(0));
	if (argc <=4 ) {
		for(double i = lower; i <= upper; i += step) {
			printf("%.100le\n", i);
		}
	} else if (argc <= 7){
		double lower2 = atof(argv[4]);
		double upper2 = atof(argv[5]);
		double step2 = atof(argv[6]) / 2;
		for(double i = lower; i <= upper; i += step) {
			for(double j = lower2; j <= upper2; j += step2) {
				printf("%.100le %.100le\n", i, j);
			}
		}
	} else {
		double lower2 = atof(argv[4]);
                double upper2 = atof(argv[5]);
                double step2 = atof(argv[6]) / 2;
		double lower3 = atof(argv[7]);
		double upper3 = atof(argv[8]);
		double step3 = atof(argv[9]) / 2;
		for(double i = lower; i <= upper; i += step) {
			for(double j = lower2; j <= upper2; j += step2) {
				for(double k = lower3; k <= upper3; k += step3) {
					printf("%.100le %.100le %.100le\n", i, j, k);
				}
			}
		}
	}
	return 0;
}
