#!/bin/sh

g++ NormalInput.cpp -o NormalInput
g++ NormalInputInt.cpp -o NormalInputInt

./NormalInput -1 1 0.004 > acos_t.txt
./NormalInput 1 101 0.2 > acosh_t.txt
./NormalInput -1 1 0.004 > asin_t.txt
./NormalInput -50 50 0.2 > asinh_t.txt
./NormalInput -50 50 0.2 > atan_t.txt
./NormalInput -3 3 0.2 -3 3 0.2 > atan2_t.txt
./NormalInput -0.998 0.999 0.002 > atanh_t.txt
./NormalInput -3.1416 3.1415 0.01 > cos_t.txt
./NormalInput 1 101 0.2 > cosh_t.txt
./NormalInput -50 50 0.2 > exp_t.txt
./NormalInput -50 50 0.2 > exp2_t.txt
./NormalInput -50 50 0.2 > exp10_t.txt
./NormalInput 0.1 50 0.1 > gamma_t.txt
./NormalInput 0.002 10 0.004 > log_t.txt
./NormalInput 0.01 10 0.02 > log10_t.txt
./NormalInput 0.01 10 0.02 > log2_t.txt
./NormalInput 0.01 10 0.02 > log1p_t.txt
./NormalInput 1 5 0.2 1 5 0.2 > pow_t.txt
./NormalInput -3.1416 3.1415 0.01 > sin_t.txt
./NormalInput -3.1416 3.1415 0.01 > sincos_t.txt
./NormalInput -50 50 0.2 > sinh_t.txt
./NormalInput -3.1416 3.1415 0.01 > tan_t.txt
./NormalInput 0 100 0.2 > tanh_t.txt
./NormalInput 0.1 50 0.1 > cbrt_t.txt
./NormalInput -25 25 0.1 > erf_t.txt
./NormalInput -25 25 0.1 > erfc_t.txt
./NormalInput -25 25 0.1 > expm1_t.txt
./NormalInput -2.5 3 1 -2.5 3 1 -2.5 3 1 > fma_t.txt
./NormalInput -2.5 3 1 -2.5 3 1 -2.5 3 1 > fmaf_t.txt
./NormalInput -25 25 0.1 > frexp_t.txt
./NormalInput 1 5 0.2 1 5 0.2 > hypot_t.txt
./NormalInput -50 50 0.2 > ilogb_t.txt
./NormalInput 0.1 100 0.2 > j1_t.txt
./NormalInput 0.1 100 0.2 > j0_t.txt
./NormalInput 0.1 50 0.1 > lgamma_t.txt
./NormalInput -25 25 0.1 > llround_t.txt
./NormalInput -25 25 0.1 > logb_t.txt
./NormalInput -25 25 0.1 > lround_t.txt
./NormalInput -25 25 0.1 > modf_t.txt
./NormalInput -25 25 0.1 > round_t.txt
./NormalInput -25 25 0.1 > trunc_t.txt
./NormalInput 0.1 100 0.2 > y1_t.txt
./NormalInput 0.1 100 0.2 > y0_t.txt
./NormalInput 1 5 0.2 1 5 0.2 > remquo_t.txt

./NormalInputInt 0.1 20 0.4 0 10 2 > jn_t.txt
./NormalInputInt 0.1 20 0.4 0 10 2 > yn_t.txt
./NormalInputInt 0 20 0.4 0 10 2 > scalbln_t.txt
./NormalInputInt 0 20 0.4 0 10 2 > scalbn_t.txt

