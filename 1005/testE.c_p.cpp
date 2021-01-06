#include "../ScDebug/scdebug.h"
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
  int a = 1, b = 2;
  for (; a <= 3;) {
    printf("%d,%d\n", a, b);
    int c = a;
    a++, b++;
  }
  int c = 1;
  for (; c < 10;) {
    c = c - 2;
    c = c + 4;
  }

  //	if (fa + fb > 0)
  {
    fa = fb + fb + fb + fb + fb;
    computeDAdd((Addr)&fa,
                {(Addr)&fb, (Addr)&fb, (Addr)&fb, (Addr)&fb, (Addr)&fb},
                "/home/shijia/Public/testprogram/testE.c_e.c:26:6");
    double temp_var_for_ext_0;
    temp_var_for_ext_0 = fb + fa;
    computeDAdd((Addr)&temp_var_for_ext_0, {(Addr)&fb, (Addr)&fa},
                "/home/shijia/Public/testprogram/testE.c_e.c:27:49"); // fa
    /*(fb)(fb)(fb)(fb)(fb)(fb)(fb)(fb)(fb)(fb)(fb)(fb)(fb)(fb)(fa)(fb)*/
    fa = temp_var_for_ext_0;
    AssignD({(Addr)&fa}, (Addr)&temp_var_for_ext_0,
            "/home/shijia/Public/testprogram/testE.c_e.c:29:4");
    SC_DEBUG_POSTINC((Addr)&fb, fb);
    double temp_var_for_ext_1;
    temp_var_for_ext_1 = SC_DEBUG_POSTINC((Addr)&fa, fa); // fa
    /*(fa)(fb)(fa)(fa)*/
    fa = temp_var_for_ext_1;
    AssignD({(Addr)&fa}, (Addr)&temp_var_for_ext_1,
            "/home/shijia/Public/testprogram/testE.c_e.c:33:4");
    SC_DEBUG_PREINC((Addr)&fa, fa);
    SC_DEBUG_POSTFIX((Addr)&fa, fa);
    SC_DEBUG_PREFIX((Addr)&fb, fb);
    fb = fa + SC_DEBUG_PREINC((Addr)&fa, fa);
    printf("%le\n", fb);
    double temp_var_for_ext_2;
    temp_var_for_ext_2 = 0 - fa;
    double temp_var_for_const_0;
    computeDSub((Addr)&temp_var_for_ext_2,
                {(Addr) &(temp_var_for_const_0 = 0), (Addr)&fa},
                "/home/shijia/Public/testprogram/testE.c_e.c:39:49"); // fa
    /*(fa)(fa)(fa)(fa)(fa)*/
    fa = temp_var_for_ext_2;
    AssignD({(Addr)&fa}, (Addr)&temp_var_for_ext_2,
            "/home/shijia/Public/testprogram/testE.c_e.c:41:4");
  }
  return 0;
}
