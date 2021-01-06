#include "../../ScDebug/scdebug.h"
/*	******************************************************************
        ** V_etd4_s.c
  ***
        ** This is four-order etd serial program for Vacancy model.
  ***
        ** run ./V_etd4_s N	TIME
  ***
        ** N is the maximum size of cluster.
  ***
        ** TIME is the totol time for evolving.
  ***
        ******************************************************************
*/

//#include <iostream>
//#include "iomanip"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define KB 8.625e-5
#define N 500
#define T 823
#define PI 3.141592
#define TIME 1000

int main(int argc, char *argv[]) {
  // int N = atoi(argv[1]);	//从运行命令中给参数N的值
  // double TIME = atoi(argv[2]);
  double start, end;
  double totaltime;
  start = clock();
  double temp_var_for_const_0;
  AssignD({(Addr)&start}, (Addr) &(temp_var_for_const_0 = clock()),
          "/home/shijia/Public/testprogram/ETD_S.c_e.c:31:8");
  int i;
  double sumalpha = 0.0, sumalpha_a = 0.0, sumalpha_b = 0.0, sumalpha_d = 0.0;
  double sumbeta = 0.0, sumbeta_a = 0.0, sumbeta_b = 0.0, sumbeta_d = 0.0;
  double dt = 1.0e-1;
  double t = 0.0, k = 0.0;

  double Vat = 1.205e-29; // m^3。1.205e-29m^3=1.205e-23cm^3
  // cout<<"Vat="<<Vat<<"\n"<<endl;
  double EFvac = 1.77; //空位的形成能eV
  double EMvac = 1.1;  //空位的迁移能eV
  double Dvac = 1.0e-6 * exp((0.0 - EMvac) / (KB * T));
  double temp_var_for_const_1, temp_var_for_const_2, temp_var_for_const_3,
      temp_var_for_const_4;
  double temp_var_for_tac_0, temp_var_for_tac_1, temp_var_for_tac_2;
  computeDDiv((Addr)&temp_var_for_tac_2,
              {(Addr)&temp_var_for_tac_0, (Addr)&temp_var_for_tac_1},
              "toString(biExpr->getExprLoc())");
  computeDSub((Addr)&temp_var_for_tac_0,
              {(Addr) &(temp_var_for_const_1 = 0.0), (Addr)&EMvac},
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:42:49");
  computeDMul((Addr)&temp_var_for_tac_1, {(Addr) &(temp_var_for_const_3 = KB),
                                          (Addr) &(temp_var_for_const_2 = T)},
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:42:43");
  double temp_var_for_callexp_0 =
      exp(getFVbyShadow<double>((Addr)&temp_var_for_tac_2));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  // m^2/s。1.0e-6*exp(-EMvac/(KB*T))m^2/s 空位的扩散系数,m^2/s=1.0e+4nm^2/s
  // cout<<"Dvac="<<Dvac<<endl;
  double Gama = 6.25e18; // eV/m^2。6.25e+18eV/m^2,eV/m^2=1.0e-4eV/nm^2
  // cout<<"Gama="<<Gama<<"\n"<<endl;
  double Cinit = 1.0e-7; // atom-1 初始浓度

  double *C = (double *)malloc(N * sizeof(double));
  double *a = (double *)malloc(N * sizeof(double));
  double *b = (double *)malloc(N * sizeof(double));
  double *d = (double *)malloc(N * sizeof(double));
  double *Fa = (double *)malloc(N * sizeof(double));
  double *Fb = (double *)malloc(N * sizeof(double));
  double *Fc = (double *)malloc(N * sizeof(double));
  double *Fd = (double *)malloc(N * sizeof(double));
  double *r = (double *)malloc(N * sizeof(double));
  double *EBvac = (double *)malloc(N * sizeof(double));
  double *Alpha = (double *)malloc(N * sizeof(double));
  double *alpha = (double *)malloc(N * sizeof(double));
  double *alpha_a = (double *)malloc(N * sizeof(double));
  double *alpha_b = (double *)malloc(N * sizeof(double));
  double *alpha_d = (double *)malloc(N * sizeof(double));
  double *Beta = (double *)malloc(N * sizeof(double));
  double *beta = (double *)malloc(N * sizeof(double));
  double *beta_a = (double *)malloc(N * sizeof(double));
  double *beta_b = (double *)malloc(N * sizeof(double));
  double *beta_d = (double *)malloc(N * sizeof(double));
  // va = (double *)malloc(N * sizeof(double));
  // vb = (double *)malloc(N * sizeof(double));
  double *L3 = (double *)malloc(N * sizeof(double));
  double *phi1 = (double *)malloc(N * sizeof(double));
  double *phi2 = (double *)malloc(N * sizeof(double));
  double *phi3 = (double *)malloc(N * sizeof(double));
  double *poly1 = (double *)malloc(N * sizeof(double));
  double *poly2 = (double *)malloc(N * sizeof(double));
  double *poly3 = (double *)malloc(N * sizeof(double));

  // double acons = 6.02e23;
  // double at2cb = 8.385e22;
  // double cb2at = 1./at2cb;
  /*for(i=0;i<N;i++){
          C[i]=0.0;
          //Fa[i]=Fb[i]=Fc[i]=Fd[i]=0.0;

  }*/
  C[0] = Cinit;
  computeDMul((Addr)&C[0], {(Addr) &(temp_var_for_const_4 = 1.0e-6),
                            (Addr)&temp_var_for_callexp_0},
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:86:7");
  // C[0] = Cinit*at2cb;                 //atom-1转换成cm

  double Alpha0, Beta0;
  Beta0 = Alpha0 = pow((48.0 * PI * PI / Vat / Vat), 1.0 / 3.0) * Dvac;
  double temp_var_for_const_5, temp_var_for_const_6, temp_var_for_const_7,
      temp_var_for_const_8, temp_var_for_const_9;
  double temp_var_for_tac_3, temp_var_for_tac_4, temp_var_for_tac_5,
      temp_var_for_tac_6;
  computeDDiv((Addr)&temp_var_for_tac_6, {(Addr) &(temp_var_for_const_9 = 1.0),
                                          (Addr) &(temp_var_for_const_8 = 3.0)},
              "toString(biExpr->getExprLoc())");
  computeDMul((Addr)&temp_var_for_tac_3, {(Addr) &(temp_var_for_const_6 = 48.0),
                                          (Addr) &(temp_var_for_const_5 = PI),
                                          (Addr) &(temp_var_for_const_7 = PI)},
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:90:39");
  computeDDiv((Addr)&temp_var_for_tac_4,
              {(Addr)&temp_var_for_tac_3, (Addr)&Vat},
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:90:45");
  computeDDiv((Addr)&temp_var_for_tac_5,
              {(Addr)&temp_var_for_tac_4, (Addr)&Vat},
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:90:57");
  double temp_var_for_callexp_1 =
      pow(getFVbyShadow<double>((Addr)&temp_var_for_tac_5),
          getFVbyShadow<double>((Addr)&temp_var_for_tac_6));
  CallStackPop((Addr)&temp_var_for_callexp_1, getTop(temp_var_for_callexp_1));
  computeDMul((Addr)&Alpha0, {(Addr)&temp_var_for_callexp_1, (Addr)&Dvac},
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:90:17");
  AssignD({(Addr)&Beta0}, (Addr)&Alpha0,
          "/home/shijia/Public/testprogram/ETD_S.c_e.c:90:8");
  for (i = 0; i < N; i++) {
    r[i] = pow((3.0 * (i + 1.0) * Vat / (4 * PI)), 1.0 / 3.0) * 1.0;
    double temp_var_for_const_10, temp_var_for_const_11, temp_var_for_const_12,
        temp_var_for_const_13, temp_var_for_const_14, temp_var_for_const_15,
        temp_var_for_const_16, temp_var_for_const_17;
    double temp_var_for_tac_7, temp_var_for_tac_8, temp_var_for_tac_9,
        temp_var_for_tac_10, temp_var_for_tac_11;
    computeDDiv((Addr)&temp_var_for_tac_11,
                {(Addr) &(temp_var_for_const_16 = 1.0),
                 (Addr) &(temp_var_for_const_15 = 3.0)},
                "toString(biExpr->getExprLoc())");
    computeDAdd((Addr)&temp_var_for_tac_7,
                {(Addr) &(temp_var_for_const_11 = i),
                 (Addr) &(temp_var_for_const_10 = 1.0)},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:93:19");
    computeDMul((Addr)&temp_var_for_tac_8,
                {(Addr) &(temp_var_for_const_12 = 3.0),
                 (Addr)&temp_var_for_tac_7, (Addr)&Vat},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:93:42");
    computeDMul((Addr)&temp_var_for_tac_9,
                {(Addr) &(temp_var_for_const_14 = 4),
                 (Addr) &(temp_var_for_const_13 = PI)},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:93:37");
    computeDDiv((Addr)&temp_var_for_tac_10,
                {(Addr)&temp_var_for_tac_8, (Addr)&temp_var_for_tac_9},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:93:54");
    double temp_var_for_callexp_2 =
        pow(getFVbyShadow<double>((Addr)&temp_var_for_tac_10),
            getFVbyShadow<double>((Addr)&temp_var_for_tac_11));
    CallStackPop((Addr)&temp_var_for_callexp_2, getTop(temp_var_for_callexp_2));
    computeDMul((Addr)&r[i], {(Addr)&temp_var_for_callexp_2,
                              (Addr) &(temp_var_for_const_17 = 1.0)},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:93:8"); // nm
    EBvac[i] = EFvac - 2.0 * Gama * Vat / r[i];
    double temp_var_for_const_18;
    double temp_var_for_tac_12, temp_var_for_tac_13;
    computeDMul(
        (Addr)&temp_var_for_tac_12,
        {(Addr) &(temp_var_for_const_18 = 2.0), (Addr)&Gama, (Addr)&Vat},
        "/home/shijia/Public/testprogram/ETD_S.c_e.c:94:38");
    computeDDiv((Addr)&temp_var_for_tac_13,
                {(Addr)&temp_var_for_tac_12, (Addr)&r[i]},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:94:20");
    computeDSub(
        (Addr)&EBvac[i], {(Addr)&EFvac, (Addr)&temp_var_for_tac_13},
        "/home/shijia/Public/testprogram/ETD_S.c_e.c:94:12"); // eV空位缺陷结合能
    Alpha[i] =
        Alpha0 * pow((i + 1.0), 1.0 / 3.0) * exp((0.0 - EBvac[i]) / (KB * T));
    double temp_var_for_const_19, temp_var_for_const_20, temp_var_for_const_21,
        temp_var_for_const_22, temp_var_for_const_23, temp_var_for_const_24,
        temp_var_for_const_25;
    double temp_var_for_tac_14, temp_var_for_tac_15, temp_var_for_tac_16,
        temp_var_for_tac_17, temp_var_for_tac_18, temp_var_for_tac_19;
    computeDDiv((Addr)&temp_var_for_tac_15,
                {(Addr) &(temp_var_for_const_22 = 1.0),
                 (Addr) &(temp_var_for_const_21 = 3.0)},
                "toString(biExpr->getExprLoc())");
    computeDDiv((Addr)&temp_var_for_tac_19,
                {(Addr)&temp_var_for_tac_17, (Addr)&temp_var_for_tac_18},
                "toString(biExpr->getExprLoc())");
    computeDAdd((Addr)&temp_var_for_tac_14,
                {(Addr) &(temp_var_for_const_20 = i),
                 (Addr) &(temp_var_for_const_19 = 1.0)},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:95:42");
    double temp_var_for_callexp_3 =
        pow(getFVbyShadow<double>((Addr)&temp_var_for_tac_14),
            getFVbyShadow<double>((Addr)&temp_var_for_tac_15));
    CallStackPop((Addr)&temp_var_for_callexp_3, getTop(temp_var_for_callexp_3));
    computeDMul((Addr)&temp_var_for_tac_16,
                {(Addr)&Alpha0, (Addr)&temp_var_for_callexp_3},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:95:60");
    computeDSub((Addr)&temp_var_for_tac_17,
                {(Addr) &(temp_var_for_const_23 = 0.0), (Addr)&EBvac[i]},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:95:78");
    computeDMul((Addr)&temp_var_for_tac_18,
                {(Addr) &(temp_var_for_const_25 = KB),
                 (Addr) &(temp_var_for_const_24 = T)},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:95:72");
    double temp_var_for_callexp_4 =
        exp(getFVbyShadow<double>((Addr)&temp_var_for_tac_19));
    CallStackPop((Addr)&temp_var_for_callexp_4, getTop(temp_var_for_callexp_4));
    computeDMul((Addr)&Alpha[i],
                {(Addr)&temp_var_for_tac_16, (Addr)&temp_var_for_callexp_4},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:95:12");
    Beta[i] = Beta0 * pow((i + 1.0), 1.0 / 3.0);
    double temp_var_for_const_26, temp_var_for_const_27, temp_var_for_const_28,
        temp_var_for_const_29;
    double temp_var_for_tac_20, temp_var_for_tac_21;
    computeDDiv((Addr)&temp_var_for_tac_21,
                {(Addr) &(temp_var_for_const_29 = 1.0),
                 (Addr) &(temp_var_for_const_28 = 3.0)},
                "toString(biExpr->getExprLoc())");
    computeDAdd((Addr)&temp_var_for_tac_20,
                {(Addr) &(temp_var_for_const_27 = i),
                 (Addr) &(temp_var_for_const_26 = 1.0)},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:96:40");
    double temp_var_for_callexp_5 =
        pow(getFVbyShadow<double>((Addr)&temp_var_for_tac_20),
            getFVbyShadow<double>((Addr)&temp_var_for_tac_21));
    CallStackPop((Addr)&temp_var_for_callexp_5, getTop(temp_var_for_callexp_5));
    computeDMul((Addr)&Beta[i], {(Addr)&Beta0, (Addr)&temp_var_for_callexp_5},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:96:11"); //公式2
    int temp_var_for_ext_0;
    temp_var_for_ext_0 = i == 0;
    if (temp_var_for_ext_0) {
      L3[0] = (0.0 - pow((1.0 + k), -3));
      double temp_var_for_const_30, temp_var_for_const_31;
      double temp_var_for_tac_22;
      computeDAdd((Addr)&temp_var_for_tac_22,
                  {(Addr) &(temp_var_for_const_30 = 1.0), (Addr)&k},
                  "toString(biExpr->getExprLoc())");
      double temp_var_for_callexp_6 =
          pow(getFVbyShadow<double>((Addr)&temp_var_for_tac_22), ((-(3))));
      CallStackPop((Addr)&temp_var_for_callexp_6,
                   getTop(temp_var_for_callexp_6));
      computeDSub((Addr)&L3[0], {(Addr) &(temp_var_for_const_31 = 0.0),
                                 (Addr)&temp_var_for_callexp_6},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:101:10");
      phi1[0] = exp((0.0 - dt) * (1.0 + k) / 2);
      double temp_var_for_const_32, temp_var_for_const_33,
          temp_var_for_const_34;
      double temp_var_for_tac_23, temp_var_for_tac_24, temp_var_for_tac_25,
          temp_var_for_tac_26;
      computeDDiv(
          (Addr)&temp_var_for_tac_26,
          {(Addr)&temp_var_for_tac_25, (Addr) &(temp_var_for_const_34 = 2)},
          "toString(biExpr->getExprLoc())");
      computeDSub((Addr)&temp_var_for_tac_23,
                  {(Addr) &(temp_var_for_const_32 = 0.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:102:36");
      computeDAdd((Addr)&temp_var_for_tac_24,
                  {(Addr) &(temp_var_for_const_33 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:102:29");
      computeDMul((Addr)&temp_var_for_tac_25,
                  {(Addr)&temp_var_for_tac_23, (Addr)&temp_var_for_tac_24},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:102:41");
      double temp_var_for_callexp_7 =
          exp(getFVbyShadow<double>((Addr)&temp_var_for_tac_26));
      CallStackPop((Addr)&temp_var_for_callexp_7,
                   getTop(temp_var_for_callexp_7));
      AssignD({(Addr)&phi1[0]}, (Addr)&temp_var_for_callexp_7,
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:102:12");
      phi2[0] = (1.0 - exp((0.0 - dt) * (1.0 + k) / 2)) / (1.0 + k);
      double temp_var_for_const_35, temp_var_for_const_36,
          temp_var_for_const_37, temp_var_for_const_38, temp_var_for_const_39;
      double temp_var_for_tac_27, temp_var_for_tac_28, temp_var_for_tac_29,
          temp_var_for_tac_30, temp_var_for_tac_31, temp_var_for_tac_32;
      computeDDiv(
          (Addr)&temp_var_for_tac_30,
          {(Addr)&temp_var_for_tac_29, (Addr) &(temp_var_for_const_37 = 2)},
          "toString(biExpr->getExprLoc())");
      computeDSub((Addr)&temp_var_for_tac_27,
                  {(Addr) &(temp_var_for_const_35 = 0.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:103:43");
      computeDAdd((Addr)&temp_var_for_tac_28,
                  {(Addr) &(temp_var_for_const_36 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:103:36");
      computeDMul((Addr)&temp_var_for_tac_29,
                  {(Addr)&temp_var_for_tac_27, (Addr)&temp_var_for_tac_28},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:103:48");
      double temp_var_for_callexp_8 =
          exp(getFVbyShadow<double>((Addr)&temp_var_for_tac_30));
      CallStackPop((Addr)&temp_var_for_callexp_8,
                   getTop(temp_var_for_callexp_8));
      computeDSub((Addr)&temp_var_for_tac_31,
                  {(Addr) &(temp_var_for_const_38 = 1.0),
                   (Addr)&temp_var_for_callexp_8},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:103:61");
      computeDAdd((Addr)&temp_var_for_tac_32,
                  {(Addr) &(temp_var_for_const_39 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:103:54");
      computeDDiv((Addr)&phi2[0],
                  {(Addr)&temp_var_for_tac_31, (Addr)&temp_var_for_tac_32},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:103:12");
      phi3[0] = exp((0.0 - dt) * (1.0 + k));
      double temp_var_for_const_40, temp_var_for_const_41;
      double temp_var_for_tac_33, temp_var_for_tac_34, temp_var_for_tac_35;
      computeDMul((Addr)&temp_var_for_tac_35,
                  {(Addr)&temp_var_for_tac_33, (Addr)&temp_var_for_tac_34},
                  "toString(biExpr->getExprLoc())");
      computeDSub((Addr)&temp_var_for_tac_33,
                  {(Addr) &(temp_var_for_const_40 = 0.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:104:36");
      computeDAdd((Addr)&temp_var_for_tac_34,
                  {(Addr) &(temp_var_for_const_41 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:104:29");
      double temp_var_for_callexp_9 =
          exp(getFVbyShadow<double>((Addr)&temp_var_for_tac_35));
      CallStackPop((Addr)&temp_var_for_callexp_9,
                   getTop(temp_var_for_callexp_9));
      AssignD({(Addr)&phi3[0]}, (Addr)&temp_var_for_callexp_9,
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:104:12");
      poly1[0] =
          (0.0 - 4.0) + dt * (1.0 + k) +
          exp((0.0 - dt) * (1.0 + k)) *
              (4 + 3.0 * dt * (1.0 + k) + dt * dt * (1.0 + k) * (1.0 + k));
      double temp_var_for_const_42, temp_var_for_const_43,
          temp_var_for_const_44, temp_var_for_const_45, temp_var_for_const_46,
          temp_var_for_const_47, temp_var_for_const_48, temp_var_for_const_49,
          temp_var_for_const_50, temp_var_for_const_51;
      double temp_var_for_tac_36, temp_var_for_tac_37, temp_var_for_tac_38,
          temp_var_for_tac_39, temp_var_for_tac_40, temp_var_for_tac_41,
          temp_var_for_tac_42, temp_var_for_tac_43, temp_var_for_tac_44,
          temp_var_for_tac_45, temp_var_for_tac_46, temp_var_for_tac_47,
          temp_var_for_tac_48, temp_var_for_tac_49, temp_var_for_tac_50,
          temp_var_for_tac_51, temp_var_for_tac_52, temp_var_for_tac_53;
      computeDMul((Addr)&temp_var_for_tac_42,
                  {(Addr)&temp_var_for_tac_40, (Addr)&temp_var_for_tac_41},
                  "toString(biExpr->getExprLoc())");
      computeDSub((Addr)&temp_var_for_tac_36,
                  {(Addr) &(temp_var_for_const_43 = 0.0),
                   (Addr) &(temp_var_for_const_42 = 4.0)},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:105:37");
      computeDAdd((Addr)&temp_var_for_tac_37,
                  {(Addr) &(temp_var_for_const_44 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:105:30");
      computeDMul((Addr)&temp_var_for_tac_38,
                  {(Addr)&dt, (Addr)&temp_var_for_tac_37},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:105:25");
      computeDAdd((Addr)&temp_var_for_tac_39,
                  {(Addr)&temp_var_for_tac_36, (Addr)&temp_var_for_tac_38},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:105:53");
      computeDSub((Addr)&temp_var_for_tac_40,
                  {(Addr) &(temp_var_for_const_45 = 0.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:105:66");
      computeDAdd((Addr)&temp_var_for_tac_41,
                  {(Addr) &(temp_var_for_const_46 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:105:59");
      computeDMul((Addr)&temp_var_for_tac_43,
                  {(Addr) &(temp_var_for_const_47 = 3.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:105:95");
      computeDAdd((Addr)&temp_var_for_tac_44,
                  {(Addr) &(temp_var_for_const_48 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:105:88");
      computeDMul((Addr)&temp_var_for_tac_45,
                  {(Addr)&temp_var_for_tac_43, (Addr)&temp_var_for_tac_44},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:105:77");
      computeDAdd(
          (Addr)&temp_var_for_tac_46,
          {(Addr) &(temp_var_for_const_49 = 4), (Addr)&temp_var_for_tac_45},
          "/home/shijia/Public/testprogram/ETD_S.c_e.c:105:105");
      computeDMul((Addr)&temp_var_for_tac_47, {(Addr)&dt, (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:105:117");
      computeDAdd((Addr)&temp_var_for_tac_48,
                  {(Addr) &(temp_var_for_const_50 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:105:110");
      computeDMul((Addr)&temp_var_for_tac_49,
                  {(Addr)&temp_var_for_tac_47, (Addr)&temp_var_for_tac_48},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:105:129");
      computeDAdd((Addr)&temp_var_for_tac_50,
                  {(Addr) &(temp_var_for_const_51 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:105:122");
      computeDMul((Addr)&temp_var_for_tac_51,
                  {(Addr)&temp_var_for_tac_49, (Addr)&temp_var_for_tac_50},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:105:100");
      double temp_var_for_callexp_10 =
          exp(getFVbyShadow<double>((Addr)&temp_var_for_tac_42));
      CallStackPop((Addr)&temp_var_for_callexp_10,
                   getTop(temp_var_for_callexp_10));
      computeDAdd((Addr)&temp_var_for_tac_52,
                  {(Addr)&temp_var_for_tac_46, (Addr)&temp_var_for_tac_51},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:105:72");
      computeDMul((Addr)&temp_var_for_tac_53,
                  {(Addr)&temp_var_for_callexp_10, (Addr)&temp_var_for_tac_52},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:105:42");
      computeDAdd((Addr)&poly1[0],
                  {(Addr)&temp_var_for_tac_39, (Addr)&temp_var_for_tac_53},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:105:13");
      poly2[0] = 4.0 - 2.0 * dt * (1.0 + k) +
                 exp((0.0 - dt) * (1.0 + k)) * (-4 - 2.0 * dt * (1.0 + k));
      double temp_var_for_const_52, temp_var_for_const_53,
          temp_var_for_const_54, temp_var_for_const_55, temp_var_for_const_56,
          temp_var_for_const_57, temp_var_for_const_58, temp_var_for_const_59;
      double temp_var_for_tac_54, temp_var_for_tac_55, temp_var_for_tac_56,
          temp_var_for_tac_57, temp_var_for_tac_58, temp_var_for_tac_59,
          temp_var_for_tac_60, temp_var_for_tac_61, temp_var_for_tac_62,
          temp_var_for_tac_63, temp_var_for_tac_64, temp_var_for_tac_65;
      computeDMul((Addr)&temp_var_for_tac_60,
                  {(Addr)&temp_var_for_tac_58, (Addr)&temp_var_for_tac_59},
                  "toString(biExpr->getExprLoc())");
      computeDMul((Addr)&temp_var_for_tac_54,
                  {(Addr) &(temp_var_for_const_52 = 2.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:34");
      computeDAdd((Addr)&temp_var_for_tac_55,
                  {(Addr) &(temp_var_for_const_53 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:27");
      computeDMul((Addr)&temp_var_for_tac_56,
                  {(Addr)&temp_var_for_tac_54, (Addr)&temp_var_for_tac_55},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:17");
      computeDSub(
          (Addr)&temp_var_for_tac_57,
          {(Addr) &(temp_var_for_const_54 = 4.0), (Addr)&temp_var_for_tac_56},
          "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:50");
      computeDSub((Addr)&temp_var_for_tac_58,
                  {(Addr) &(temp_var_for_const_55 = 0.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:63");
      computeDAdd((Addr)&temp_var_for_tac_59,
                  {(Addr) &(temp_var_for_const_56 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:56");
      computeDMul((Addr)&temp_var_for_tac_61,
                  {(Addr) &(temp_var_for_const_57 = 2.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:92");
      computeDAdd((Addr)&temp_var_for_tac_62,
                  {(Addr) &(temp_var_for_const_58 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:85");
      computeDMul((Addr)&temp_var_for_tac_63,
                  {(Addr)&temp_var_for_tac_61, (Addr)&temp_var_for_tac_62},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:75");
      double temp_var_for_callexp_11 =
          exp(getFVbyShadow<double>((Addr)&temp_var_for_tac_60));
      CallStackPop((Addr)&temp_var_for_callexp_11,
                   getTop(temp_var_for_callexp_11));
      computeDSub((Addr)&temp_var_for_tac_64,
                  {(Addr) &(temp_var_for_const_59 = (-(4))),
                   (Addr)&temp_var_for_tac_63},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:69");
      computeDMul((Addr)&temp_var_for_tac_65,
                  {(Addr)&temp_var_for_callexp_11, (Addr)&temp_var_for_tac_64},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:39");
      computeDAdd((Addr)&poly2[0],
                  {(Addr)&temp_var_for_tac_57, (Addr)&temp_var_for_tac_65},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:13");
      poly3[0] = (0.0 - 4.0) + 3.0 * dt * (1.0 + k) -
                 dt * dt * (1.0 + k) * (1.0 + k) +
                 exp((0.0 - dt) * (1.0 + k)) * (4 + dt * (1.0 + k));
      double temp_var_for_const_60, temp_var_for_const_61,
          temp_var_for_const_62, temp_var_for_const_63, temp_var_for_const_64,
          temp_var_for_const_65, temp_var_for_const_66, temp_var_for_const_67,
          temp_var_for_const_68, temp_var_for_const_69;
      double temp_var_for_tac_66, temp_var_for_tac_67, temp_var_for_tac_68,
          temp_var_for_tac_69, temp_var_for_tac_70, temp_var_for_tac_71,
          temp_var_for_tac_72, temp_var_for_tac_73, temp_var_for_tac_74,
          temp_var_for_tac_75, temp_var_for_tac_76, temp_var_for_tac_77,
          temp_var_for_tac_78, temp_var_for_tac_79, temp_var_for_tac_80,
          temp_var_for_tac_81, temp_var_for_tac_82, temp_var_for_tac_83;
      computeDMul((Addr)&temp_var_for_tac_79,
                  {(Addr)&temp_var_for_tac_77, (Addr)&temp_var_for_tac_78},
                  "toString(biExpr->getExprLoc())");
      computeDSub((Addr)&temp_var_for_tac_66,
                  {(Addr) &(temp_var_for_const_61 = 0.0),
                   (Addr) &(temp_var_for_const_60 = 4.0)},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:31");
      computeDMul((Addr)&temp_var_for_tac_67,
                  {(Addr) &(temp_var_for_const_62 = 3.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:43");
      computeDAdd((Addr)&temp_var_for_tac_68,
                  {(Addr) &(temp_var_for_const_63 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:36");
      computeDMul((Addr)&temp_var_for_tac_69,
                  {(Addr)&temp_var_for_tac_67, (Addr)&temp_var_for_tac_68},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:25");
      computeDAdd((Addr)&temp_var_for_tac_70,
                  {(Addr)&temp_var_for_tac_66, (Addr)&temp_var_for_tac_69},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:53");
      computeDMul((Addr)&temp_var_for_tac_71, {(Addr)&dt, (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:65");
      computeDAdd((Addr)&temp_var_for_tac_72,
                  {(Addr) &(temp_var_for_const_64 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:58");
      computeDMul((Addr)&temp_var_for_tac_73,
                  {(Addr)&temp_var_for_tac_71, (Addr)&temp_var_for_tac_72},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:77");
      computeDAdd((Addr)&temp_var_for_tac_74,
                  {(Addr) &(temp_var_for_const_65 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:70");
      computeDMul((Addr)&temp_var_for_tac_75,
                  {(Addr)&temp_var_for_tac_73, (Addr)&temp_var_for_tac_74},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:48");
      computeDSub((Addr)&temp_var_for_tac_76,
                  {(Addr)&temp_var_for_tac_70, (Addr)&temp_var_for_tac_75},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:93");
      computeDSub((Addr)&temp_var_for_tac_77,
                  {(Addr) &(temp_var_for_const_66 = 0.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:106");
      computeDAdd((Addr)&temp_var_for_tac_78,
                  {(Addr) &(temp_var_for_const_67 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:99");
      computeDAdd((Addr)&temp_var_for_tac_80,
                  {(Addr) &(temp_var_for_const_68 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:122");
      computeDMul((Addr)&temp_var_for_tac_81,
                  {(Addr)&dt, (Addr)&temp_var_for_tac_80},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:117");
      double temp_var_for_callexp_12 =
          exp(getFVbyShadow<double>((Addr)&temp_var_for_tac_79));
      CallStackPop((Addr)&temp_var_for_callexp_12,
                   getTop(temp_var_for_callexp_12));
      computeDAdd(
          (Addr)&temp_var_for_tac_82,
          {(Addr) &(temp_var_for_const_69 = 4), (Addr)&temp_var_for_tac_81},
          "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:112");
      computeDMul((Addr)&temp_var_for_tac_83,
                  {(Addr)&temp_var_for_callexp_12, (Addr)&temp_var_for_tac_82},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:82");
      computeDAdd((Addr)&poly3[0],
                  {(Addr)&temp_var_for_tac_76, (Addr)&temp_var_for_tac_83},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:13");
    } else {
      L3[i] = (0.0 - pow((Alpha[i] + k), -3));
      double temp_var_for_const_70;
      double temp_var_for_tac_84;
      computeDAdd((Addr)&temp_var_for_tac_84, {(Addr)&Alpha[i], (Addr)&k},
                  "toString(biExpr->getExprLoc())");
      double temp_var_for_callexp_13 =
          pow(getFVbyShadow<double>((Addr)&temp_var_for_tac_84), ((-(3))));
      CallStackPop((Addr)&temp_var_for_callexp_13,
                   getTop(temp_var_for_callexp_13));
      computeDSub((Addr)&L3[i], {(Addr) &(temp_var_for_const_70 = 0.0),
                                 (Addr)&temp_var_for_callexp_13},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:111:10");
      phi1[i] = exp((0.0 - dt) * (Alpha[i] + k) / 2);
      double temp_var_for_const_71, temp_var_for_const_72;
      double temp_var_for_tac_85, temp_var_for_tac_86, temp_var_for_tac_87,
          temp_var_for_tac_88;
      computeDDiv(
          (Addr)&temp_var_for_tac_88,
          {(Addr)&temp_var_for_tac_87, (Addr) &(temp_var_for_const_72 = 2)},
          "toString(biExpr->getExprLoc())");
      computeDSub((Addr)&temp_var_for_tac_85,
                  {(Addr) &(temp_var_for_const_71 = 0.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:112:41");
      computeDAdd((Addr)&temp_var_for_tac_86, {(Addr)&Alpha[i], (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:112:29");
      computeDMul((Addr)&temp_var_for_tac_87,
                  {(Addr)&temp_var_for_tac_85, (Addr)&temp_var_for_tac_86},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:112:46");
      double temp_var_for_callexp_14 =
          exp(getFVbyShadow<double>((Addr)&temp_var_for_tac_88));
      CallStackPop((Addr)&temp_var_for_callexp_14,
                   getTop(temp_var_for_callexp_14));
      AssignD({(Addr)&phi1[i]}, (Addr)&temp_var_for_callexp_14,
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:112:12");
      phi2[i] = (1.0 - exp((0.0 - dt) * (Alpha[i] + k) / 2)) / (Alpha[i] + k);
      double temp_var_for_const_73, temp_var_for_const_74,
          temp_var_for_const_75;
      double temp_var_for_tac_89, temp_var_for_tac_90, temp_var_for_tac_91,
          temp_var_for_tac_92, temp_var_for_tac_93, temp_var_for_tac_94;
      computeDDiv(
          (Addr)&temp_var_for_tac_92,
          {(Addr)&temp_var_for_tac_91, (Addr) &(temp_var_for_const_74 = 2)},
          "toString(biExpr->getExprLoc())");
      computeDSub((Addr)&temp_var_for_tac_89,
                  {(Addr) &(temp_var_for_const_73 = 0.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:113:48");
      computeDAdd((Addr)&temp_var_for_tac_90, {(Addr)&Alpha[i], (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:113:36");
      computeDMul((Addr)&temp_var_for_tac_91,
                  {(Addr)&temp_var_for_tac_89, (Addr)&temp_var_for_tac_90},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:113:53");
      double temp_var_for_callexp_15 =
          exp(getFVbyShadow<double>((Addr)&temp_var_for_tac_92));
      CallStackPop((Addr)&temp_var_for_callexp_15,
                   getTop(temp_var_for_callexp_15));
      computeDSub((Addr)&temp_var_for_tac_93,
                  {(Addr) &(temp_var_for_const_75 = 1.0),
                   (Addr)&temp_var_for_callexp_15},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:113:71");
      computeDAdd((Addr)&temp_var_for_tac_94, {(Addr)&Alpha[i], (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:113:59");
      computeDDiv((Addr)&phi2[i],
                  {(Addr)&temp_var_for_tac_93, (Addr)&temp_var_for_tac_94},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:113:12");
      phi3[i] = exp((0.0 - dt) * (Alpha[i] + k));
      double temp_var_for_const_76;
      double temp_var_for_tac_95, temp_var_for_tac_96, temp_var_for_tac_97;
      computeDMul((Addr)&temp_var_for_tac_97,
                  {(Addr)&temp_var_for_tac_95, (Addr)&temp_var_for_tac_96},
                  "toString(biExpr->getExprLoc())");
      computeDSub((Addr)&temp_var_for_tac_95,
                  {(Addr) &(temp_var_for_const_76 = 0.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:114:41");
      computeDAdd((Addr)&temp_var_for_tac_96, {(Addr)&Alpha[i], (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:114:29");
      double temp_var_for_callexp_16 =
          exp(getFVbyShadow<double>((Addr)&temp_var_for_tac_97));
      CallStackPop((Addr)&temp_var_for_callexp_16,
                   getTop(temp_var_for_callexp_16));
      AssignD({(Addr)&phi3[i]}, (Addr)&temp_var_for_callexp_16,
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:114:12");
      poly1[i] = (0.0 - 4.0) + dt * (Alpha[i] + k) +
                 exp((0.0 - dt) * (Alpha[i] + k)) *
                     (4 + 3.0 * dt * (Alpha[i] + k) +
                      dt * dt * (Alpha[i] + k) * (Alpha[i] + k));
      double temp_var_for_const_77, temp_var_for_const_78,
          temp_var_for_const_79, temp_var_for_const_80, temp_var_for_const_81;
      double temp_var_for_tac_98, temp_var_for_tac_99, temp_var_for_tac_100,
          temp_var_for_tac_101, temp_var_for_tac_102, temp_var_for_tac_103,
          temp_var_for_tac_104, temp_var_for_tac_105, temp_var_for_tac_106,
          temp_var_for_tac_107, temp_var_for_tac_108, temp_var_for_tac_109,
          temp_var_for_tac_110, temp_var_for_tac_111, temp_var_for_tac_112,
          temp_var_for_tac_113, temp_var_for_tac_114, temp_var_for_tac_115;
      computeDMul((Addr)&temp_var_for_tac_104,
                  {(Addr)&temp_var_for_tac_102, (Addr)&temp_var_for_tac_103},
                  "toString(biExpr->getExprLoc())");
      computeDSub((Addr)&temp_var_for_tac_98,
                  {(Addr) &(temp_var_for_const_78 = 0.0),
                   (Addr) &(temp_var_for_const_77 = 4.0)},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:42");
      computeDAdd((Addr)&temp_var_for_tac_99, {(Addr)&Alpha[i], (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:30");
      computeDMul((Addr)&temp_var_for_tac_100,
                  {(Addr)&dt, (Addr)&temp_var_for_tac_99},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:25");
      computeDAdd((Addr)&temp_var_for_tac_101,
                  {(Addr)&temp_var_for_tac_98, (Addr)&temp_var_for_tac_100},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:58");
      computeDSub((Addr)&temp_var_for_tac_102,
                  {(Addr) &(temp_var_for_const_79 = 0.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:76");
      computeDAdd((Addr)&temp_var_for_tac_103, {(Addr)&Alpha[i], (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:64");
      computeDMul((Addr)&temp_var_for_tac_105,
                  {(Addr) &(temp_var_for_const_80 = 3.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:110");
      computeDAdd((Addr)&temp_var_for_tac_106, {(Addr)&Alpha[i], (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:98");
      computeDMul((Addr)&temp_var_for_tac_107,
                  {(Addr)&temp_var_for_tac_105, (Addr)&temp_var_for_tac_106},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:87");
      computeDAdd(
          (Addr)&temp_var_for_tac_108,
          {(Addr) &(temp_var_for_const_81 = 4), (Addr)&temp_var_for_tac_107},
          "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:120");
      computeDMul((Addr)&temp_var_for_tac_109, {(Addr)&dt, (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:137");
      computeDAdd((Addr)&temp_var_for_tac_110, {(Addr)&Alpha[i], (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:125");
      computeDMul((Addr)&temp_var_for_tac_111,
                  {(Addr)&temp_var_for_tac_109, (Addr)&temp_var_for_tac_110},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:154");
      computeDAdd((Addr)&temp_var_for_tac_112, {(Addr)&Alpha[i], (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:142");
      computeDMul((Addr)&temp_var_for_tac_113,
                  {(Addr)&temp_var_for_tac_111, (Addr)&temp_var_for_tac_112},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:115");
      double temp_var_for_callexp_17 =
          exp(getFVbyShadow<double>((Addr)&temp_var_for_tac_104));
      CallStackPop((Addr)&temp_var_for_callexp_17,
                   getTop(temp_var_for_callexp_17));
      computeDAdd((Addr)&temp_var_for_tac_114,
                  {(Addr)&temp_var_for_tac_108, (Addr)&temp_var_for_tac_113},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:82");
      computeDMul((Addr)&temp_var_for_tac_115,
                  {(Addr)&temp_var_for_callexp_17, (Addr)&temp_var_for_tac_114},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:47");
      computeDAdd((Addr)&poly1[i],
                  {(Addr)&temp_var_for_tac_101, (Addr)&temp_var_for_tac_115},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:13");
      poly2[i] =
          4.0 - 2.0 * dt * (Alpha[i] + k) +
          exp((0.0 - dt) * (Alpha[i] + k)) * (-4 - 2.0 * dt * (Alpha[i] + k));
      double temp_var_for_const_82, temp_var_for_const_83,
          temp_var_for_const_84, temp_var_for_const_85, temp_var_for_const_86;
      double temp_var_for_tac_116, temp_var_for_tac_117, temp_var_for_tac_118,
          temp_var_for_tac_119, temp_var_for_tac_120, temp_var_for_tac_121,
          temp_var_for_tac_122, temp_var_for_tac_123, temp_var_for_tac_124,
          temp_var_for_tac_125, temp_var_for_tac_126, temp_var_for_tac_127;
      computeDMul((Addr)&temp_var_for_tac_122,
                  {(Addr)&temp_var_for_tac_120, (Addr)&temp_var_for_tac_121},
                  "toString(biExpr->getExprLoc())");
      computeDMul((Addr)&temp_var_for_tac_116,
                  {(Addr) &(temp_var_for_const_82 = 2.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:39");
      computeDAdd((Addr)&temp_var_for_tac_117, {(Addr)&Alpha[i], (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:27");
      computeDMul((Addr)&temp_var_for_tac_118,
                  {(Addr)&temp_var_for_tac_116, (Addr)&temp_var_for_tac_117},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:17");
      computeDSub(
          (Addr)&temp_var_for_tac_119,
          {(Addr) &(temp_var_for_const_83 = 4.0), (Addr)&temp_var_for_tac_118},
          "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:55");
      computeDSub((Addr)&temp_var_for_tac_120,
                  {(Addr) &(temp_var_for_const_84 = 0.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:73");
      computeDAdd((Addr)&temp_var_for_tac_121, {(Addr)&Alpha[i], (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:61");
      computeDMul((Addr)&temp_var_for_tac_123,
                  {(Addr) &(temp_var_for_const_85 = 2.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:107");
      computeDAdd((Addr)&temp_var_for_tac_124, {(Addr)&Alpha[i], (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:95");
      computeDMul((Addr)&temp_var_for_tac_125,
                  {(Addr)&temp_var_for_tac_123, (Addr)&temp_var_for_tac_124},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:85");
      double temp_var_for_callexp_18 =
          exp(getFVbyShadow<double>((Addr)&temp_var_for_tac_122));
      CallStackPop((Addr)&temp_var_for_callexp_18,
                   getTop(temp_var_for_callexp_18));
      computeDSub((Addr)&temp_var_for_tac_126,
                  {(Addr) &(temp_var_for_const_86 = (-(4))),
                   (Addr)&temp_var_for_tac_125},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:79");
      computeDMul((Addr)&temp_var_for_tac_127,
                  {(Addr)&temp_var_for_callexp_18, (Addr)&temp_var_for_tac_126},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:44");
      computeDAdd((Addr)&poly2[i],
                  {(Addr)&temp_var_for_tac_119, (Addr)&temp_var_for_tac_127},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:13");
      poly3[i] = (0.0 - 4.0) + 3.0 * dt * (Alpha[i] + k) -
                 dt * dt * (Alpha[i] + k) * (Alpha[i] + k) +
                 exp((0.0 - dt) * (Alpha[i] + k)) * (4 + dt * (Alpha[i] + k));
      double temp_var_for_const_87, temp_var_for_const_88,
          temp_var_for_const_89, temp_var_for_const_90, temp_var_for_const_91;
      double temp_var_for_tac_128, temp_var_for_tac_129, temp_var_for_tac_130,
          temp_var_for_tac_131, temp_var_for_tac_132, temp_var_for_tac_133,
          temp_var_for_tac_134, temp_var_for_tac_135, temp_var_for_tac_136,
          temp_var_for_tac_137, temp_var_for_tac_138, temp_var_for_tac_139,
          temp_var_for_tac_140, temp_var_for_tac_141, temp_var_for_tac_142,
          temp_var_for_tac_143, temp_var_for_tac_144, temp_var_for_tac_145;
      computeDMul((Addr)&temp_var_for_tac_141,
                  {(Addr)&temp_var_for_tac_139, (Addr)&temp_var_for_tac_140},
                  "toString(biExpr->getExprLoc())");
      computeDSub((Addr)&temp_var_for_tac_128,
                  {(Addr) &(temp_var_for_const_88 = 0.0),
                   (Addr) &(temp_var_for_const_87 = 4.0)},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:31");
      computeDMul((Addr)&temp_var_for_tac_129,
                  {(Addr) &(temp_var_for_const_89 = 3.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:48");
      computeDAdd((Addr)&temp_var_for_tac_130, {(Addr)&Alpha[i], (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:36");
      computeDMul((Addr)&temp_var_for_tac_131,
                  {(Addr)&temp_var_for_tac_129, (Addr)&temp_var_for_tac_130},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:25");
      computeDAdd((Addr)&temp_var_for_tac_132,
                  {(Addr)&temp_var_for_tac_128, (Addr)&temp_var_for_tac_131},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:58");
      computeDMul((Addr)&temp_var_for_tac_133, {(Addr)&dt, (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:75");
      computeDAdd((Addr)&temp_var_for_tac_134, {(Addr)&Alpha[i], (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:63");
      computeDMul((Addr)&temp_var_for_tac_135,
                  {(Addr)&temp_var_for_tac_133, (Addr)&temp_var_for_tac_134},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:92");
      computeDAdd((Addr)&temp_var_for_tac_136, {(Addr)&Alpha[i], (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:80");
      computeDMul((Addr)&temp_var_for_tac_137,
                  {(Addr)&temp_var_for_tac_135, (Addr)&temp_var_for_tac_136},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:53");
      computeDSub((Addr)&temp_var_for_tac_138,
                  {(Addr)&temp_var_for_tac_132, (Addr)&temp_var_for_tac_137},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:108");
      computeDSub((Addr)&temp_var_for_tac_139,
                  {(Addr) &(temp_var_for_const_90 = 0.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:126");
      computeDAdd((Addr)&temp_var_for_tac_140, {(Addr)&Alpha[i], (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:114");
      computeDAdd((Addr)&temp_var_for_tac_142, {(Addr)&Alpha[i], (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:142");
      computeDMul((Addr)&temp_var_for_tac_143,
                  {(Addr)&dt, (Addr)&temp_var_for_tac_142},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:137");
      double temp_var_for_callexp_19 =
          exp(getFVbyShadow<double>((Addr)&temp_var_for_tac_141));
      CallStackPop((Addr)&temp_var_for_callexp_19,
                   getTop(temp_var_for_callexp_19));
      computeDAdd(
          (Addr)&temp_var_for_tac_144,
          {(Addr) &(temp_var_for_const_91 = 4), (Addr)&temp_var_for_tac_143},
          "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:132");
      computeDMul((Addr)&temp_var_for_tac_145,
                  {(Addr)&temp_var_for_callexp_19, (Addr)&temp_var_for_tac_144},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:97");
      computeDAdd((Addr)&poly3[i],
                  {(Addr)&temp_var_for_tac_138, (Addr)&temp_var_for_tac_145},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:13");
    }
  }
  for (i = 0; i < N; i++) {
    // printf("phi3[%d]=%e\n",i,phi3[i]);
    // printf("C[%d]=%e\n",i,C[i]);
    // printf("L3[%d]=%e\n",i,L3[i]);
    // printf("poly1[%d]=%e\n",i,poly1[i]);
    // printf("poly2[%d]=%e\n",i,poly2[i]);
    // printf("poly3[%d]=%e\n",i,poly3[i]);
  }

  int temp_var_for_ext_1;
  temp_var_for_ext_1 = t < TIME;
  while (temp_var_for_ext_1) {
    // printf("t=%f******sumalpha=%e\tsumbeta=%e\n",t,sumalpha,sumbeta);
    for (i = 0; i < N; i++) {
      int temp_var_for_ext_2;
      temp_var_for_ext_2 = i == 0;
      if (temp_var_for_ext_2) {
        alpha[i] = 0.0;
        double temp_var_for_const_92;
        AssignD({(Addr)&alpha[i]}, (Addr) &(temp_var_for_const_92 = 0.0),
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:141:14");
        beta[i] = 0.0;
        double temp_var_for_const_93;
        AssignD({(Addr)&beta[i]}, (Addr) &(temp_var_for_const_93 = 0.0),
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:142:13");
      } else {
        alpha[i] = Alpha[i] * C[i];
        computeDMul((Addr)&alpha[i], {(Addr)&Alpha[i], (Addr)&C[i]},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:146:14");
        beta[i] = Beta[i] * C[i] * C[0];
        computeDMul((Addr)&beta[i], {(Addr)&Beta[i], (Addr)&C[i], (Addr)&C[0]},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:147:13");
      }
      sumbeta += beta[i];
      sumalpha += alpha[i];
    }
    // printf("t=%f******sumalpha=%e\tsumbeta=%e\n",t,sumalpha,sumbeta);
    Fc[0] = -2 * Beta[0] * C[0] * C[0] - sumbeta + sumalpha + Alpha[1] * C[1] +
            (1.0 + k) * C[0];
    double temp_var_for_const_94, temp_var_for_const_95;
    double temp_var_for_tac_146, temp_var_for_tac_147, temp_var_for_tac_148,
        temp_var_for_tac_149, temp_var_for_tac_150, temp_var_for_tac_151,
        temp_var_for_tac_152;
    computeDMul((Addr)&temp_var_for_tac_146,
                {(Addr) &(temp_var_for_const_94 = (-(2))), (Addr)&Beta[0],
                 (Addr)&C[0], (Addr)&C[0]},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:153:38");
    computeDSub((Addr)&temp_var_for_tac_147,
                {(Addr)&temp_var_for_tac_146, (Addr)&sumbeta},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:153:48");
    computeDAdd((Addr)&temp_var_for_tac_148,
                {(Addr)&temp_var_for_tac_147, (Addr)&sumalpha},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:153:70");
    computeDMul((Addr)&temp_var_for_tac_149, {(Addr)&Alpha[1], (Addr)&C[1]},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:153:59");
    computeDAdd((Addr)&temp_var_for_tac_150,
                {(Addr)&temp_var_for_tac_148, (Addr)&temp_var_for_tac_149},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:153:84");
    computeDAdd((Addr)&temp_var_for_tac_151,
                {(Addr) &(temp_var_for_const_95 = 1.0), (Addr)&k},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:153:89");
    computeDMul((Addr)&temp_var_for_tac_152,
                {(Addr)&temp_var_for_tac_151, (Addr)&C[0]},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:153:77");
    computeDAdd((Addr)&Fc[0],
                {(Addr)&temp_var_for_tac_150, (Addr)&temp_var_for_tac_152},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:153:9");
    for (i = 1; i <= N - 2; i++) {
      Fc[i] = Beta[i - 1] * C[i - 1] * C[0] - Beta[i] * C[i] * C[0] +
              Alpha[i + 1] * C[i + 1] + k * C[i];
      double temp_var_for_tac_153, temp_var_for_tac_154, temp_var_for_tac_155,
          temp_var_for_tac_156, temp_var_for_tac_157, temp_var_for_tac_158;
      computeDMul((Addr)&temp_var_for_tac_153,
                  {(Addr)&Beta[i - 1], (Addr)&C[i - 1], (Addr)&C[0]},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:156:52");
      computeDMul((Addr)&temp_var_for_tac_154,
                  {(Addr)&Beta[i], (Addr)&C[i], (Addr)&C[0]},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:156:42");
      computeDSub((Addr)&temp_var_for_tac_155,
                  {(Addr)&temp_var_for_tac_153, (Addr)&temp_var_for_tac_154},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:156:81");
      computeDMul((Addr)&temp_var_for_tac_156,
                  {(Addr)&Alpha[i + 1], (Addr)&C[i + 1]},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:156:66");
      computeDAdd((Addr)&temp_var_for_tac_157,
                  {(Addr)&temp_var_for_tac_155, (Addr)&temp_var_for_tac_156},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:156:96");
      computeDMul((Addr)&temp_var_for_tac_158, {(Addr)&k, (Addr)&C[i]},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:156:92");
      computeDAdd((Addr)&Fc[i],
                  {(Addr)&temp_var_for_tac_157, (Addr)&temp_var_for_tac_158},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:156:10");
    }
    Fc[N - 1] = Beta[N - 2] * C[N - 2] * C[0] - Beta[N - 1] * C[N - 1] * C[0] +
                k * C[N - 1];
    double temp_var_for_tac_159;
    computeDMul((Addr)&temp_var_for_tac_159,
                {(Addr)&Beta[N - 2], (Addr)&C[N - 2]},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:158:81");
    /*
    for(i=0;i<N;i++){
            printf("Fc[%d]=%e\n",i,Fc[i]);
    }*/

    for (i = 0; i < N; i++) {
      a[i] = phi1[i] * C[i] + phi2[i] * Fc[i];
      double temp_var_for_tac_160, temp_var_for_tac_161, temp_var_for_tac_162;
      computeDMul((Addr)&temp_var_for_tac_160, {(Addr)&k, (Addr)&C[N - 1]},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:166:19");
      computeDMul((Addr)&temp_var_for_tac_161, {(Addr)&phi1[i], (Addr)&C[i]},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:166:36");
      computeDMul((Addr)&temp_var_for_tac_162, {(Addr)&phi2[i], (Addr)&Fc[i]},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:166:26");
      int temp_var_for_ext_3;
      temp_var_for_ext_3 = i == 0;
      if (temp_var_for_ext_3) {
        alpha_a[i] = 0.0;
        computeDAdd((Addr)&alpha_a[i],
                    {(Addr)&temp_var_for_tac_161, (Addr)&temp_var_for_tac_162},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:171:16");
        beta_a[i] = 0.0;
        double temp_var_for_const_96;
        AssignD({(Addr)&beta_a[i]}, (Addr) &(temp_var_for_const_96 = 0.0),
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:172:15");
      } else {
        alpha_a[i] = Alpha[i] * a[i];
        computeDMul((Addr)&alpha_a[i], {(Addr)&Alpha[i], (Addr)&a[i]},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:176:16");
        beta_a[i] = Beta[i] * a[i] * a[0];
        computeDMul((Addr)&beta_a[i],
                    {(Addr)&Beta[i], (Addr)&a[i], (Addr)&a[0]},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:177:15");
      }
      sumalpha_a += alpha_a[i];
      sumbeta_a += beta_a[i];
    }
    Fa[0] = -2 * Beta[0] * a[0] * a[0] - sumbeta_a + sumalpha_a +
            Alpha[1] * a[1] + (1.0 + k) * a[0];
    double temp_var_for_const_97, temp_var_for_const_98;
    double temp_var_for_tac_163, temp_var_for_tac_164, temp_var_for_tac_165,
        temp_var_for_tac_166, temp_var_for_tac_167, temp_var_for_tac_168,
        temp_var_for_tac_169;
    computeDMul((Addr)&temp_var_for_tac_163,
                {(Addr) &(temp_var_for_const_97 = (-(2))), (Addr)&Beta[0],
                 (Addr)&a[0], (Addr)&a[0]},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:182:38");
    computeDSub((Addr)&temp_var_for_tac_164,
                {(Addr)&temp_var_for_tac_163, (Addr)&sumbeta_a},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:182:50");
    computeDAdd((Addr)&temp_var_for_tac_165,
                {(Addr)&temp_var_for_tac_164, (Addr)&sumalpha_a},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:182:74");
    computeDMul((Addr)&temp_var_for_tac_166, {(Addr)&Alpha[1], (Addr)&a[1]},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:182:63");
    computeDAdd((Addr)&temp_var_for_tac_167,
                {(Addr)&temp_var_for_tac_165, (Addr)&temp_var_for_tac_166},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:182:88");
    computeDAdd((Addr)&temp_var_for_tac_168,
                {(Addr) &(temp_var_for_const_98 = 1.0), (Addr)&k},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:182:93");
    computeDMul((Addr)&temp_var_for_tac_169,
                {(Addr)&temp_var_for_tac_168, (Addr)&a[0]},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:182:81");
    computeDAdd((Addr)&Fa[0],
                {(Addr)&temp_var_for_tac_167, (Addr)&temp_var_for_tac_169},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:182:9");
    for (i = 1; i <= N - 2; i++) {
      Fa[i] = Beta[i - 1] * a[i - 1] * a[0] - Beta[i] * a[i] * a[0] +
              Alpha[i + 1] * a[i + 1] + k * a[i];
      double temp_var_for_tac_170, temp_var_for_tac_171, temp_var_for_tac_172,
          temp_var_for_tac_173, temp_var_for_tac_174, temp_var_for_tac_175;
      computeDMul((Addr)&temp_var_for_tac_170,
                  {(Addr)&Beta[i - 1], (Addr)&a[i - 1], (Addr)&a[0]},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:185:52");
      computeDMul((Addr)&temp_var_for_tac_171,
                  {(Addr)&Beta[i], (Addr)&a[i], (Addr)&a[0]},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:185:42");
      computeDSub((Addr)&temp_var_for_tac_172,
                  {(Addr)&temp_var_for_tac_170, (Addr)&temp_var_for_tac_171},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:185:81");
      computeDMul((Addr)&temp_var_for_tac_173,
                  {(Addr)&Alpha[i + 1], (Addr)&a[i + 1]},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:185:66");
      computeDAdd((Addr)&temp_var_for_tac_174,
                  {(Addr)&temp_var_for_tac_172, (Addr)&temp_var_for_tac_173},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:185:96");
      computeDMul((Addr)&temp_var_for_tac_175, {(Addr)&k, (Addr)&a[i]},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:185:92");
      computeDAdd((Addr)&Fa[i],
                  {(Addr)&temp_var_for_tac_174, (Addr)&temp_var_for_tac_175},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:185:10");
    }
    Fa[N - 1] = Beta[N - 2] * a[N - 2] * a[0] - Beta[N - 1] * a[N - 1] * a[0] +
                k * a[N - 1];
    double temp_var_for_tac_176;
    computeDMul((Addr)&temp_var_for_tac_176,
                {(Addr)&Beta[N - 2], (Addr)&a[N - 2]},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:187:81");
    /*for(i=0;i<N;i++){
            printf("Fa[%d]=%e\n",i,Fa[i]);
    }*/

    for (i = 0; i < N; i++) {
      b[i] = phi1[i] * C[i] + phi2[i] * Fa[i];
      double temp_var_for_tac_177, temp_var_for_tac_178, temp_var_for_tac_179;
      computeDMul((Addr)&temp_var_for_tac_177, {(Addr)&k, (Addr)&a[N - 1]},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:194:19");
      computeDMul((Addr)&temp_var_for_tac_178, {(Addr)&phi1[i], (Addr)&C[i]},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:194:36");
      computeDMul((Addr)&temp_var_for_tac_179, {(Addr)&phi2[i], (Addr)&Fa[i]},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:194:26");
      int temp_var_for_ext_4;
      temp_var_for_ext_4 = i == 0;
      if (temp_var_for_ext_4) {
        alpha_b[i] = 0.0;
        computeDAdd((Addr)&alpha_b[i],
                    {(Addr)&temp_var_for_tac_178, (Addr)&temp_var_for_tac_179},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:199:16");
        beta_b[i] = 0.0;
        double temp_var_for_const_99;
        AssignD({(Addr)&beta_b[i]}, (Addr) &(temp_var_for_const_99 = 0.0),
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:200:15");
      } else {
        alpha_b[i] = Alpha[i] * b[i];
        computeDMul((Addr)&alpha_b[i], {(Addr)&Alpha[i], (Addr)&b[i]},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:204:16");
        beta_b[i] = Beta[i] * b[i] * b[0];
        computeDMul((Addr)&beta_b[i],
                    {(Addr)&Beta[i], (Addr)&b[i], (Addr)&b[0]},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:205:15");
      }
      sumalpha_b += alpha_b[i];
      sumbeta_b += beta_b[i];
    }
    Fb[0] = -2 * Beta[0] * b[0] * b[0] - sumbeta_b + sumalpha_b +
            Alpha[1] * b[1] + (1.0 + k) * b[0];
    double temp_var_for_const_100, temp_var_for_const_101;
    double temp_var_for_tac_180, temp_var_for_tac_181, temp_var_for_tac_182,
        temp_var_for_tac_183, temp_var_for_tac_184, temp_var_for_tac_185,
        temp_var_for_tac_186;
    computeDMul((Addr)&temp_var_for_tac_180,
                {(Addr) &(temp_var_for_const_100 = (-(2))), (Addr)&Beta[0],
                 (Addr)&b[0], (Addr)&b[0]},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:210:38");
    computeDSub((Addr)&temp_var_for_tac_181,
                {(Addr)&temp_var_for_tac_180, (Addr)&sumbeta_b},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:210:50");
    computeDAdd((Addr)&temp_var_for_tac_182,
                {(Addr)&temp_var_for_tac_181, (Addr)&sumalpha_b},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:210:74");
    computeDMul((Addr)&temp_var_for_tac_183, {(Addr)&Alpha[1], (Addr)&b[1]},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:210:63");
    computeDAdd((Addr)&temp_var_for_tac_184,
                {(Addr)&temp_var_for_tac_182, (Addr)&temp_var_for_tac_183},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:210:88");
    computeDAdd((Addr)&temp_var_for_tac_185,
                {(Addr) &(temp_var_for_const_101 = 1.0), (Addr)&k},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:210:93");
    computeDMul((Addr)&temp_var_for_tac_186,
                {(Addr)&temp_var_for_tac_185, (Addr)&b[0]},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:210:81");
    computeDAdd((Addr)&Fb[0],
                {(Addr)&temp_var_for_tac_184, (Addr)&temp_var_for_tac_186},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:210:9");
    for (i = 1; i <= N - 2; i++) {
      Fb[i] = Beta[i - 1] * b[i - 1] * b[0] - Beta[i] * b[i] * b[0] +
              Alpha[i + 1] * b[i + 1] + k * b[i];
      double temp_var_for_tac_187, temp_var_for_tac_188, temp_var_for_tac_189,
          temp_var_for_tac_190, temp_var_for_tac_191, temp_var_for_tac_192;
      computeDMul((Addr)&temp_var_for_tac_187,
                  {(Addr)&Beta[i - 1], (Addr)&b[i - 1], (Addr)&b[0]},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:213:52");
      computeDMul((Addr)&temp_var_for_tac_188,
                  {(Addr)&Beta[i], (Addr)&b[i], (Addr)&b[0]},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:213:42");
      computeDSub((Addr)&temp_var_for_tac_189,
                  {(Addr)&temp_var_for_tac_187, (Addr)&temp_var_for_tac_188},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:213:81");
      computeDMul((Addr)&temp_var_for_tac_190,
                  {(Addr)&Alpha[i + 1], (Addr)&b[i + 1]},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:213:66");
      computeDAdd((Addr)&temp_var_for_tac_191,
                  {(Addr)&temp_var_for_tac_189, (Addr)&temp_var_for_tac_190},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:213:96");
      computeDMul((Addr)&temp_var_for_tac_192, {(Addr)&k, (Addr)&b[i]},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:213:92");
      computeDAdd((Addr)&Fb[i],
                  {(Addr)&temp_var_for_tac_191, (Addr)&temp_var_for_tac_192},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:213:10");
    }
    Fb[N - 1] = Beta[N - 2] * b[N - 2] * b[0] - Beta[N - 1] * b[N - 1] * b[0] +
                k * b[N - 1];
    double temp_var_for_tac_193;
    computeDMul((Addr)&temp_var_for_tac_193,
                {(Addr)&Beta[N - 2], (Addr)&b[N - 2]},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:215:81");
    /*for(i=0;i<N;i++){
            printf("Fb[%d]=%e\n",i,Fb[i]);
    }*/

    for (i = 0; i < N; i++) {
      d[i] = phi1[i] * a[i] + phi2[i] * (2 * Fb[i] - Fc[i]);
      double temp_var_for_const_102;
      double temp_var_for_tac_194, temp_var_for_tac_195, temp_var_for_tac_196,
          temp_var_for_tac_197, temp_var_for_tac_198;
      computeDMul((Addr)&temp_var_for_tac_194, {(Addr)&k, (Addr)&b[N - 1]},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:222:19");
      computeDMul((Addr)&temp_var_for_tac_195, {(Addr)&phi1[i], (Addr)&a[i]},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:222:41");
      computeDMul((Addr)&temp_var_for_tac_196,
                  {(Addr) &(temp_var_for_const_102 = 2), (Addr)&Fb[i]},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:222:49");
      computeDSub((Addr)&temp_var_for_tac_197,
                  {(Addr)&temp_var_for_tac_196, (Addr)&Fc[i]},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:222:36");
      computeDMul((Addr)&temp_var_for_tac_198,
                  {(Addr)&phi2[i], (Addr)&temp_var_for_tac_197},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:222:26");
      int temp_var_for_ext_5;
      temp_var_for_ext_5 = i == 0;
      if (temp_var_for_ext_5) {
        alpha_d[i] = 0.0;
        computeDAdd((Addr)&alpha_d[i],
                    {(Addr)&temp_var_for_tac_195, (Addr)&temp_var_for_tac_198},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:227:16");
        beta_d[i] = 0.0;
        double temp_var_for_const_103;
        AssignD({(Addr)&beta_d[i]}, (Addr) &(temp_var_for_const_103 = 0.0),
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:228:15");
      } else {
        alpha_d[i] = Alpha[i] * d[i];
        computeDMul((Addr)&alpha_d[i], {(Addr)&Alpha[i], (Addr)&d[i]},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:232:16");
        beta_d[i] = Beta[i] * d[i] * d[0];
        computeDMul((Addr)&beta_d[i],
                    {(Addr)&Beta[i], (Addr)&d[i], (Addr)&d[0]},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:233:15");
      }
      sumalpha_d += alpha_d[i];
      sumbeta_d += beta_d[i];
    }
    Fd[0] = -2 * Beta[0] * d[0] * d[0] - sumbeta_d + sumalpha_d +
            Alpha[1] * d[1] + (1.0 + k) * d[0];
    double temp_var_for_const_104, temp_var_for_const_105;
    double temp_var_for_tac_199, temp_var_for_tac_200, temp_var_for_tac_201,
        temp_var_for_tac_202, temp_var_for_tac_203, temp_var_for_tac_204,
        temp_var_for_tac_205;
    computeDMul((Addr)&temp_var_for_tac_199,
                {(Addr) &(temp_var_for_const_104 = (-(2))), (Addr)&Beta[0],
                 (Addr)&d[0], (Addr)&d[0]},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:238:38");
    computeDSub((Addr)&temp_var_for_tac_200,
                {(Addr)&temp_var_for_tac_199, (Addr)&sumbeta_d},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:238:50");
    computeDAdd((Addr)&temp_var_for_tac_201,
                {(Addr)&temp_var_for_tac_200, (Addr)&sumalpha_d},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:238:74");
    computeDMul((Addr)&temp_var_for_tac_202, {(Addr)&Alpha[1], (Addr)&d[1]},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:238:63");
    computeDAdd((Addr)&temp_var_for_tac_203,
                {(Addr)&temp_var_for_tac_201, (Addr)&temp_var_for_tac_202},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:238:88");
    computeDAdd((Addr)&temp_var_for_tac_204,
                {(Addr) &(temp_var_for_const_105 = 1.0), (Addr)&k},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:238:93");
    computeDMul((Addr)&temp_var_for_tac_205,
                {(Addr)&temp_var_for_tac_204, (Addr)&d[0]},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:238:81");
    computeDAdd((Addr)&Fd[0],
                {(Addr)&temp_var_for_tac_203, (Addr)&temp_var_for_tac_205},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:238:9");
    for (i = 1; i <= N - 2; i++) {
      Fd[i] = Beta[i - 1] * d[i - 1] * d[0] - Beta[i] * d[i] * d[0] +
              Alpha[i + 1] * d[i + 1] + k * d[i];
      double temp_var_for_tac_206, temp_var_for_tac_207, temp_var_for_tac_208,
          temp_var_for_tac_209, temp_var_for_tac_210, temp_var_for_tac_211;
      computeDMul((Addr)&temp_var_for_tac_206,
                  {(Addr)&Beta[i - 1], (Addr)&d[i - 1], (Addr)&d[0]},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:241:52");
      computeDMul((Addr)&temp_var_for_tac_207,
                  {(Addr)&Beta[i], (Addr)&d[i], (Addr)&d[0]},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:241:42");
      computeDSub((Addr)&temp_var_for_tac_208,
                  {(Addr)&temp_var_for_tac_206, (Addr)&temp_var_for_tac_207},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:241:81");
      computeDMul((Addr)&temp_var_for_tac_209,
                  {(Addr)&Alpha[i + 1], (Addr)&d[i + 1]},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:241:66");
      computeDAdd((Addr)&temp_var_for_tac_210,
                  {(Addr)&temp_var_for_tac_208, (Addr)&temp_var_for_tac_209},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:241:96");
      computeDMul((Addr)&temp_var_for_tac_211, {(Addr)&k, (Addr)&d[i]},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:241:92");
      computeDAdd((Addr)&Fd[i],
                  {(Addr)&temp_var_for_tac_210, (Addr)&temp_var_for_tac_211},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:241:10");
    }
    Fd[N - 1] = Beta[N - 2] * d[N - 2] * d[0] - Beta[N - 1] * d[N - 1] * d[0] +
                k * d[N - 1];
    double temp_var_for_tac_212;
    computeDMul((Addr)&temp_var_for_tac_212,
                {(Addr)&Beta[N - 2], (Addr)&d[N - 2]},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:243:81");
    /*for(i=0;i<N;i++){
            printf("Fd[%d]=%e\n",i,Fd[i]);
    }*/

    for (i = 0; i < N; i++) {
      C[i] =
          phi3[i] * C[i] +
          pow(dt, -2) * L3[i] * (poly1[i] * Fc[i] + poly2[i] * (Fa[i] + Fb[i]) +
                                 poly3[i] * Fd[i]);
      double temp_var_for_tac_213, temp_var_for_tac_214, temp_var_for_tac_215,
          temp_var_for_tac_216, temp_var_for_tac_217, temp_var_for_tac_218,
          temp_var_for_tac_219, temp_var_for_tac_220, temp_var_for_tac_221,
          temp_var_for_tac_222;
      computeDMul((Addr)&temp_var_for_tac_214, {(Addr)&phi3[i], (Addr)&C[i]},
                  "toString(biExpr->getExprLoc())");
      computeDMul((Addr)&temp_var_for_tac_213, {(Addr)&k, (Addr)&d[N - 1]},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:250:19");
      double temp_var_for_callexp_20 =
          pow(getFVbyShadow<double>((Addr)&dt), ((-(2))));
      CallStackPop((Addr)&temp_var_for_callexp_20,
                   getTop(temp_var_for_callexp_20));
      computeDMul((Addr)&temp_var_for_tac_215,
                  {(Addr)&temp_var_for_callexp_20, (Addr)&L3[i]},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:250:62");
      computeDMul((Addr)&temp_var_for_tac_216, {(Addr)&poly1[i], (Addr)&Fc[i]},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:250:90");
      computeDAdd((Addr)&temp_var_for_tac_217, {(Addr)&Fa[i], (Addr)&Fb[i]},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:250:81");
      computeDMul((Addr)&temp_var_for_tac_218,
                  {(Addr)&poly2[i], (Addr)&temp_var_for_tac_217},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:250:70");
      computeDAdd((Addr)&temp_var_for_tac_219,
                  {(Addr)&temp_var_for_tac_216, (Addr)&temp_var_for_tac_218},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:250:110");
      computeDMul((Addr)&temp_var_for_tac_220, {(Addr)&poly3[i], (Addr)&Fd[i]},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:250:99");
      computeDAdd((Addr)&temp_var_for_tac_221,
                  {(Addr)&temp_var_for_tac_219, (Addr)&temp_var_for_tac_220},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:250:50");
      computeDMul((Addr)&temp_var_for_tac_222,
                  {(Addr)&temp_var_for_tac_215, (Addr)&temp_var_for_tac_221},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:250:26");
      double temp_var_for_tac_223;
      computeDAdd((Addr)&temp_var_for_tac_223,
                  {(Addr)&temp_var_for_tac_214, (Addr)&temp_var_for_tac_222},
                  "toString(biExpr->getExprLoc())");
    }
    t = t + dt;
    computeDAdd((Addr)&t, {(Addr)&t, (Addr)&dt},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:252:5");
    sumalpha = sumalpha_a = sumalpha_b = sumalpha_d = 0.0;
    double temp_var_for_const_106;
    AssignD({(Addr)&sumalpha_d, (Addr)&sumalpha_b, (Addr)&sumalpha_a,
             (Addr)&sumalpha},
            (Addr) &(temp_var_for_const_106 = 0.0),
            "/home/shijia/Public/testprogram/ETD_S.c_e.c:253:12");
    sumbeta = sumbeta_a = sumbeta_b = sumbeta_d = 0.0;
    double temp_var_for_const_107;
    AssignD(
        {(Addr)&sumbeta_d, (Addr)&sumbeta_b, (Addr)&sumbeta_a, (Addr)&sumbeta},
        (Addr) &(temp_var_for_const_107 = 0.0),
        "/home/shijia/Public/testprogram/ETD_S.c_e.c:254:11");
    temp_var_for_ext_1 = t < TIME;
  }

  for (i = 0; i < N; i++) {
    printf("C[%d]=%e\n", i, C[i]);
  }
  end = clock();
  double temp_var_for_const_108;
  AssignD({(Addr)&end}, (Addr) &(temp_var_for_const_108 = clock()),
          "/home/shijia/Public/testprogram/ETD_S.c_e.c:262:6");
  totaltime = (end - start) / CLOCKS_PER_SEC;
  double temp_var_for_const_109;
  double temp_var_for_tac_224;
  computeDSub((Addr)&temp_var_for_tac_224, {(Addr)&end, (Addr)&start},
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:263:28");
  computeDDiv((Addr)&totaltime,
              {(Addr)&temp_var_for_tac_224,
               (Addr) &(temp_var_for_const_109 = CLOCKS_PER_SEC)},
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:263:12");
  // for(i=0;i<N;i++)
  // printf("C[%d] = %e\n",i,C[i]);

  free(poly3);
  poly3 = NULL;
  free(poly2);
  poly2 = NULL;
  free(poly1);
  poly1 = NULL;
  free(phi3);
  phi3 = NULL;
  free(phi2);
  phi2 = NULL;
  free(phi1);
  phi1 = NULL;
  free(L3);
  L3 = NULL;
  free(beta_d);
  beta_d = NULL;
  free(beta_b);
  beta_b = NULL;
  free(beta_a);
  beta_a = NULL;
  free(beta);
  beta = NULL;
  free(Beta);
  Beta = NULL;
  free(alpha_d);
  alpha_d = NULL;
  free(alpha_b);
  alpha_b = NULL;
  free(alpha_a);
  alpha_a = NULL;
  free(alpha);
  alpha = NULL;
  free(Alpha);
  Alpha = NULL;
  free(EBvac);
  EBvac = NULL;
  free(r);
  r = NULL;
  free(Fd);
  Fd = NULL;
  free(Fc);
  Fc = NULL;
  free(Fb);
  Fb = NULL;
  free(Fa);
  Fa = NULL;
  free(d);
  d = NULL;
  free(b);
  b = NULL;
  free(a);
  a = NULL;
  free(C);
  C = NULL;

  // system("pause");
  printf("totaltime=%fs\n", totaltime);
  return 0;
}
