#include "../ScDebug/scdebug.h"

#include <stdio.h>
#include <math.h>
#include <time.h>
double testFun(double var) {
  double c;
  c = var * 2.011;
  double temp_var_for_const_0;
  computeDMul((Addr)&c, {(Addr)&var, (Addr) &(temp_var_for_const_0 = 2.011)},
              "/home/shijia/Public/testprogram/testVar.c_e.c:8:7");
  double temp_var_for_ext_0;
  temp_var_for_ext_0 = c;
  AssignD({(Addr)&temp_var_for_ext_0}, (Addr)&c,
          "/home/shijia/Public/testprogram/testVar.c_e.c:10:20");
  callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_0;
}
int main() {
  double a = 1.0, b = 1.2, c, d, e, f, g, h;
  c = a * b;
  computeDMul((Addr)&c, {(Addr)&a, (Addr)&b},
              "/home/shijia/Public/testprogram/testVar.c_e.c:18:7");
  d = b = e = f = g = h = 1.1;
  double temp_var_for_const_1;
  AssignD({(Addr)&h, (Addr)&g, (Addr)&f, (Addr)&e, (Addr)&b, (Addr)&d},
          (Addr)&b, "/home/shijia/Public/testprogram/testVar.c_e.c:19:7");
  d = b = e = f = g = h = a * b;
  computeDMul((Addr)&h, {(Addr)&a, (Addr)&b},
              "/home/shijia/Public/testprogram/testVar.c_e.c:20:27");
  AssignD({(Addr)&g, (Addr)&f, (Addr)&e, (Addr)&b, (Addr)&d}, (Addr)&h,
          "/home/shijia/Public/testprogram/testVar.c_e.c:20:7");
  e = a * (b + c + d);
  double temp_var_for_tac_0;
  computeDAdd((Addr)&temp_var_for_tac_0, {(Addr)&b, (Addr)&c, (Addr)&d},
              "/home/shijia/Public/testprogram/testVar.c_e.c:21:11");
  computeDMul((Addr)&e, {(Addr)&a, (Addr)&temp_var_for_tac_0},
              "/home/shijia/Public/testprogram/testVar.c_e.c:21:7");
  printVarInfo("e",(Addr)&e);
  f = a + (b + c) + c * d * e;
  double temp_var_for_tac_1, temp_var_for_tac_2;
  computeDAdd((Addr)&temp_var_for_tac_1, {(Addr)&b, (Addr)&c, (Addr)&a},
              "/home/shijia/Public/testprogram/testVar.c_e.c:22:25");
  computeDMul((Addr)&temp_var_for_tac_2, {(Addr)&c, (Addr)&d, (Addr)&e},
              "/home/shijia/Public/testprogram/testVar.c_e.c:22:21");
  computeDAdd((Addr)&f, {(Addr)&temp_var_for_tac_1, (Addr)&temp_var_for_tac_2},
              "/home/shijia/Public/testprogram/testVar.c_e.c:22:7");
  printVarInfo("f",(Addr)&f);
  g = b + c / (d * e) + f;
  double temp_var_for_tac_3, temp_var_for_tac_4;
  computeDMul((Addr)&temp_var_for_tac_3, {(Addr)&d, (Addr)&e},
              "/home/shijia/Public/testprogram/testVar.c_e.c:23:15");
  computeDDiv((Addr)&temp_var_for_tac_4, {(Addr)&c, (Addr)&temp_var_for_tac_3},
              "/home/shijia/Public/testprogram/testVar.c_e.c:23:11");
  computeDAdd((Addr)&g, {(Addr)&b, (Addr)&temp_var_for_tac_4, (Addr)&f},
              "/home/shijia/Public/testprogram/testVar.c_e.c:23:7");
  printVarInfo("g",(Addr)&g);
  h = a + testFun(b) + c + d + e;
  double temp_var_for_callexp_0 = testFun(getFVbyShadow<double>((Addr)&b));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  computeDAdd((Addr)&h, {(Addr)&a, (Addr)&temp_var_for_callexp_0, (Addr)&c,
                         (Addr)&d, (Addr)&e},
              "/home/shijia/Public/testprogram/testVar.c_e.c:24:7");
  printVarInfo("h",(Addr)&h);
  g = a * b + c * d;
  double temp_var_for_tac_5, temp_var_for_tac_6;
  computeDMul((Addr)&temp_var_for_tac_5, {(Addr)&a, (Addr)&b},
              "/home/shijia/Public/testprogram/testVar.c_e.c:25:19");
  computeDMul((Addr)&temp_var_for_tac_6, {(Addr)&c, (Addr)&d},
              "/home/shijia/Public/testprogram/testVar.c_e.c:25:15");
  computeDAdd((Addr)&g, {(Addr)&temp_var_for_tac_5, (Addr)&temp_var_for_tac_6},
              "/home/shijia/Public/testprogram/testVar.c_e.c:25:7");
  printVarInfo("g",(Addr)&g);
  g = h / a / b + h / (a / b);
  double temp_var_for_tac_7, temp_var_for_tac_8, temp_var_for_tac_9,
      temp_var_for_tac_10;
  computeDDiv((Addr)&temp_var_for_tac_7, {(Addr)&h, (Addr)&a},
              "/home/shijia/Public/testprogram/testVar.c_e.c:26:15");
  computeDDiv((Addr)&temp_var_for_tac_8, {(Addr)&temp_var_for_tac_7, (Addr)&b},
              "/home/shijia/Public/testprogram/testVar.c_e.c:26:28");
  computeDDiv((Addr)&temp_var_for_tac_9, {(Addr)&a, (Addr)&b},
              "/home/shijia/Public/testprogram/testVar.c_e.c:26:23");
  computeDDiv((Addr)&temp_var_for_tac_10, {(Addr)&h, (Addr)&temp_var_for_tac_9},
              "/home/shijia/Public/testprogram/testVar.c_e.c:26:19");
  computeDAdd((Addr)&g, {(Addr)&temp_var_for_tac_8, (Addr)&temp_var_for_tac_10},
              "/home/shijia/Public/testprogram/testVar.c_e.c:26:7");
  printVarInfo("g",(Addr)&g);
  g = (a + b) * (c + d);
  double temp_var_for_tac_11, temp_var_for_tac_12;
  computeDAdd((Addr)&temp_var_for_tac_11, {(Addr)&a, (Addr)&b},
              "/home/shijia/Public/testprogram/testVar.c_e.c:27:22");
  computeDAdd((Addr)&temp_var_for_tac_12, {(Addr)&c, (Addr)&d},
              "/home/shijia/Public/testprogram/testVar.c_e.c:27:17");
  computeDMul((Addr)&g,
              {(Addr)&temp_var_for_tac_11, (Addr)&temp_var_for_tac_12},
              "/home/shijia/Public/testprogram/testVar.c_e.c:27:7");
  printVarInfo("g",(Addr)&g);
  g = (a + b) + (c + d);
  double temp_var_for_tac_13;
  computeDAdd((Addr)&temp_var_for_tac_13, {(Addr)&a, (Addr)&b},
              "/home/shijia/Public/testprogram/testVar.c_e.c:28:22");
  computeDAdd((Addr)&g, {(Addr)&temp_var_for_tac_13, (Addr)&c, (Addr)&d},
              "/home/shijia/Public/testprogram/testVar.c_e.c:28:7");
  printVarInfo("g",(Addr)&g);
  g = -4 + 3 * d * (c + b) - d * d * (c + b) * (c + b) +
      exp(-d * (c + b)) * (4 + d * (c + b));
  double temp_var_for_const_2, temp_var_for_const_3, temp_var_for_const_4,
      temp_var_for_const_5;
  double temp_var_for_tac_14, temp_var_for_tac_15, temp_var_for_tac_16,
      temp_var_for_tac_17, temp_var_for_tac_18, temp_var_for_tac_19,
      temp_var_for_tac_20, temp_var_for_tac_21, temp_var_for_tac_22,
      temp_var_for_tac_23, temp_var_for_tac_24, temp_var_for_tac_25,
      temp_var_for_tac_26, temp_var_for_tac_27, temp_var_for_tac_28,
      temp_var_for_tac_29;
  computeDMul((Addr)&temp_var_for_tac_14,
              {(Addr) &(temp_var_for_const_2 = 3), (Addr)&d},
              "/home/shijia/Public/testprogram/testVar.c_e.c:29:25");
  computeDAdd((Addr)&temp_var_for_tac_15, {(Addr)&c, (Addr)&b},
              "/home/shijia/Public/testprogram/testVar.c_e.c:29:20");
  computeDMul((Addr)&temp_var_for_tac_16,
              {(Addr)&temp_var_for_tac_14, (Addr)&temp_var_for_tac_15},
              "/home/shijia/Public/testprogram/testVar.c_e.c:29:12");
  computeDAdd(
      (Addr)&temp_var_for_tac_17,
      {(Addr) &(temp_var_for_const_3 = (-(4))), (Addr)&temp_var_for_tac_16},
      "/home/shijia/Public/testprogram/testVar.c_e.c:29:34");
  computeDMul((Addr)&temp_var_for_tac_18, {(Addr)&d, (Addr)&d},
              "/home/shijia/Public/testprogram/testVar.c_e.c:29:43");
  computeDAdd((Addr)&temp_var_for_tac_19, {(Addr)&c, (Addr)&b},
              "/home/shijia/Public/testprogram/testVar.c_e.c:29:38");
  computeDMul((Addr)&temp_var_for_tac_20,
              {(Addr)&temp_var_for_tac_18, (Addr)&temp_var_for_tac_19},
              "/home/shijia/Public/testprogram/testVar.c_e.c:29:53");
  computeDAdd((Addr)&temp_var_for_tac_21, {(Addr)&c, (Addr)&b},
              "/home/shijia/Public/testprogram/testVar.c_e.c:29:48");
  computeDMul((Addr)&temp_var_for_tac_22,
              {(Addr)&temp_var_for_tac_20, (Addr)&temp_var_for_tac_21},
              "/home/shijia/Public/testprogram/testVar.c_e.c:29:30");
  computeDSub((Addr)&temp_var_for_tac_23,
              {(Addr)&temp_var_for_tac_17, (Addr)&temp_var_for_tac_22},
              "/home/shijia/Public/testprogram/testVar.c_e.c:29:72");
  computeDAdd((Addr)&temp_var_for_tac_24, {(Addr)&c, (Addr)&b},
              "/home/shijia/Public/testprogram/testVar.c_e.c:29:67");
  computeDMul(
      (Addr)&temp_var_for_tac_25,
      {(Addr) &(temp_var_for_const_4 = (-(d))), (Addr)&temp_var_for_tac_24},
      "/home/shijia/Public/testprogram/testVar.c_e.c:29:92");
  computeDAdd((Addr)&temp_var_for_tac_26, {(Addr)&c, (Addr)&b},
              "/home/shijia/Public/testprogram/testVar.c_e.c:29:87");
  computeDMul((Addr)&temp_var_for_tac_27,
              {(Addr)&d, (Addr)&temp_var_for_tac_26},
              "/home/shijia/Public/testprogram/testVar.c_e.c:29:83");
  double temp_var_for_callexp_1 =
      exp(getFVbyShadow<double>((Addr)&temp_var_for_tac_25));
  CallStackPop((Addr)&temp_var_for_callexp_1, getTop(temp_var_for_callexp_1));
  computeDAdd((Addr)&temp_var_for_tac_28,
              {(Addr) &(temp_var_for_const_5 = 4), (Addr)&temp_var_for_tac_27},
              "/home/shijia/Public/testprogram/testVar.c_e.c:29:78");
  computeDMul((Addr)&temp_var_for_tac_29,
              {(Addr)&temp_var_for_callexp_1, (Addr)&temp_var_for_tac_28},
              "/home/shijia/Public/testprogram/testVar.c_e.c:29:58");
  computeDAdd((Addr)&g,
              {(Addr)&temp_var_for_tac_23, (Addr)&temp_var_for_tac_29},
              "/home/shijia/Public/testprogram/testVar.c_e.c:29:7");
  printVarInfo("g",(Addr)&g);
  int i = 3;
  g = g * h * i;
  double temp_var_for_const_6;
  computeDMul((Addr)&g,
              {(Addr)&g, (Addr)&h, (Addr) &(temp_var_for_const_6 = i)},
              "/home/shijia/Public/testprogram/testVar.c_e.c:31:7");
  printVarInfo("g",(Addr)&g);
  return 0;
}
