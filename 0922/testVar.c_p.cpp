#include "../ScDebug/scdebug.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
double testFun(double var) {
  double c;
  c = var * 2.011;
  ;
  double temp_var_for_ext_0;
  temp_var_for_ext_0 = c;
  ;
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}
// void testVoid()
// {
//     printf("ob\n");
// }
// int selfPlus(int var)
// {
//     return var++;
// }
int main() {
  double a = 1.0, b = 1.2, c, d, e, f, g, h;
  c = a * b;
  d = 1.1;
  double temp_var_for_tac_0 = b + c + d;
  e = a * temp_var_for_tac_0;
  double temp_var_for_tac_1 = b + c + a;
  double temp_var_for_tac_2 = c * d * e;
  f = temp_var_for_tac_1 + temp_var_for_tac_2;
  printf("f = %.20le\n", f);
  double temp_var_for_tac_3 = d * e;
  double temp_var_for_tac_4 = c / temp_var_for_tac_3;
  g = b + temp_var_for_tac_4 + f;
  printf("g = %.20le\n", g);
  double temp_var_for_callexp_0;
  temp_var_for_callexp_0 = testFun(b);
  // insert the stack option to get the real num (it need to free the top and
  // its shadow)
  h = a + temp_var_for_callexp_0 + c + d + e;
  ;
  double temp_var_for_tac_5 = a * b;
  double temp_var_for_tac_6 = c * d;
  g = temp_var_for_tac_5 + temp_var_for_tac_6;
  ;
  printf("g = %.20le\n", g);
  double temp_var_for_tac_7 = h / a;
  double temp_var_for_tac_8 = temp_var_for_tac_7 / b;
  double temp_var_for_tac_9 = a / b;
  double temp_var_for_tac_10 = h / temp_var_for_tac_9;
  g = temp_var_for_tac_8 + temp_var_for_tac_10;
  ;
  printf("g = %.20le\n", g);
  double temp_var_for_tac_11 = a + b;
  double temp_var_for_tac_12 = c + d;
  g = temp_var_for_tac_11 * temp_var_for_tac_12;
  ;
  printf("g = %.20le\n", g);
  double temp_var_for_tac_13 = a + b;
  g = temp_var_for_tac_13 + c + d;
  ;
  printf("g = %.20le\n", g);
  double temp_var_for_tac_14 = 3 * d;
  double temp_var_for_tac_15 = c + b;
  double temp_var_for_tac_16 = temp_var_for_tac_14 * temp_var_for_tac_15;
  double temp_var_for_tac_17 = (-(4)) + temp_var_for_tac_16;
  double temp_var_for_tac_18 = d * d;
  double temp_var_for_tac_19 = c + b;
  double temp_var_for_tac_20 = temp_var_for_tac_18 * temp_var_for_tac_19;
  double temp_var_for_tac_21 = c + b;
  double temp_var_for_tac_22 = temp_var_for_tac_20 * temp_var_for_tac_21;
  double temp_var_for_tac_23 = temp_var_for_tac_17 - temp_var_for_tac_22;
  double temp_var_for_tac_24 = c + b;
  double temp_var_for_tac_25 = (-(d)) * temp_var_for_tac_24;
  double temp_var_for_tac_26 = c + b;
  double temp_var_for_tac_27 = d * temp_var_for_tac_26;
  double temp_var_for_callexp_1;
  temp_var_for_callexp_1 = exp(temp_var_for_tac_25);
  // insert the stack option to get the real num (it need to free the top and
  // its shadow)
  double temp_var_for_tac_28 = 4 + temp_var_for_tac_27;
  double temp_var_for_tac_29 = temp_var_for_callexp_1 * temp_var_for_tac_28;
  g = temp_var_for_tac_23 + temp_var_for_tac_29;
  ;
  printf("g = %.20le\n", g);
  return 0;
}
