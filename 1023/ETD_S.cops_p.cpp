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
  double temp_var_for_const_0;
  start = clock();
  AssignD({(Addr)&start}, (Addr) &(temp_var_for_const_0 = clock()),
          "/home/shijia/Public/testprogram/ETD_S.c_e.c:31:8");
  ;
  int i;
  double sumalpha = 0.0, sumalpha_a = 0.0, sumalpha_b = 0.0, sumalpha_d = 0.0;
  double sumbeta = 0.0, sumbeta_a = 0.0, sumbeta_b = 0.0, sumbeta_d = 0.0;
  double dt = 1.0e-1;
  double t = 0.0, k = 0.0;

  double Vat = 1.205e-29; // m^3。1.205e-29m^3=1.205e-23cm^3
  // cout<<"Vat="<<Vat<<"\n"<<endl;
  double EFvac = 1.77; //空位的形成能eV
  double EMvac = 1.1;  //空位的迁移能eV
  double Dvac;
  double temp_var_for_const_1, temp_var_for_const_2, temp_var_for_const_3,
      temp_var_for_const_4;
  double temp_var_for_tac_0 = 0.0 - EMvac;
  double temp_var_for_tac_1 = KB * T;
  double temp_var_for_tac_2 = temp_var_for_tac_0 / temp_var_for_tac_1;
  double temp_var_for_callexp_0;
  temp_var_for_callexp_0 = exp(temp_var_for_tac_2);
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));

  Dvac = 1.0e-6 * temp_var_for_callexp_0;
  computeDSub((Addr)&temp_var_for_tac_0,
              {(Addr) &(temp_var_for_const_1 = 0.0), (Addr)&EMvac},
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:43:42");
  computeDMul((Addr)&temp_var_for_tac_1, {(Addr) &(temp_var_for_const_3 = KB),
                                          (Addr) &(temp_var_for_const_2 = T)},
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:43:36");
  computeDDiv((Addr)&temp_var_for_tac_2,
              {(Addr)&temp_var_for_tac_0, (Addr)&temp_var_for_tac_1},
              "toString(biExpr->getExprLoc())");
  computeDMul((Addr)&Dvac, {(Addr) &(temp_var_for_const_4 = 1.0e-6),
                            (Addr)&temp_var_for_callexp_0},
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:43:7");
  ; // m^2/s。1.0e-6*exp(-EMvac/(KB*T))m^2/s 空位的扩散系数,m^2/s=1.0e+4nm^2/s
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
  AssignD({(Addr)&C[0]}, (Addr)&Cinit,
          "/home/shijia/Public/testprogram/ETD_S.c_e.c:87:7");
  ;
  // C[0] = Cinit*at2cb;                 //atom-1转换成cm

  double Alpha0, Beta0;
  double temp_var_for_const_5, temp_var_for_const_6, temp_var_for_const_7,
      temp_var_for_const_8, temp_var_for_const_9;
  double temp_var_for_tac_3 = 48.0 * PI * PI;
  double temp_var_for_tac_4 = temp_var_for_tac_3 / Vat;
  double temp_var_for_tac_5 = temp_var_for_tac_4 / Vat;
  double temp_var_for_tac_6 = 1.0 / 3.0;
  double temp_var_for_callexp_1;
  temp_var_for_callexp_1 = pow(temp_var_for_tac_5, temp_var_for_tac_6);
  CallStackPop((Addr)&temp_var_for_callexp_1, getTop(temp_var_for_callexp_1));

  Alpha0 = temp_var_for_callexp_1 * Dvac;
  computeDMul((Addr)&temp_var_for_tac_3, {(Addr) &(temp_var_for_const_6 = 48.0),
                                          (Addr) &(temp_var_for_const_5 = PI),
                                          (Addr) &(temp_var_for_const_7 = PI)},
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:91:39");
  computeDDiv((Addr)&temp_var_for_tac_4,
              {(Addr)&temp_var_for_tac_3, (Addr)&Vat},
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:91:45");
  computeDDiv((Addr)&temp_var_for_tac_5,
              {(Addr)&temp_var_for_tac_4, (Addr)&Vat},
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:91:57");
  computeDDiv((Addr)&temp_var_for_tac_6, {(Addr) &(temp_var_for_const_9 = 1.0),
                                          (Addr) &(temp_var_for_const_8 = 3.0)},
              "toString(biExpr->getExprLoc())");
  computeDMul((Addr)&Alpha0, {(Addr)&temp_var_for_callexp_1, (Addr)&Dvac},
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:91:17");
  Beta0 = Alpha0;
  AssignD({(Addr)&Beta0}, (Addr)&Alpha0,
          "/home/shijia/Public/testprogram/ETD_S.c_e.c:91:8");

  ;
  for (i = 0; i < N; i++) {
    double temp_var_for_const_10, temp_var_for_const_11, temp_var_for_const_12,
        temp_var_for_const_13, temp_var_for_const_14, temp_var_for_const_15,
        temp_var_for_const_16, temp_var_for_const_17;
    double temp_var_for_tac_7 = i + 1.0;
    double temp_var_for_tac_8 = 3.0 * temp_var_for_tac_7 * Vat;
    double temp_var_for_tac_9 = 4 * PI;
    double temp_var_for_tac_10 = temp_var_for_tac_8 / temp_var_for_tac_9;
    double temp_var_for_tac_11 = 1.0 / 3.0;
    double temp_var_for_callexp_2;
    temp_var_for_callexp_2 = pow(temp_var_for_tac_10, temp_var_for_tac_11);
    CallStackPop((Addr)&temp_var_for_callexp_2, getTop(temp_var_for_callexp_2));

    r[i] = temp_var_for_callexp_2 * 1.0;
    computeDAdd((Addr)&temp_var_for_tac_7,
                {(Addr) &(temp_var_for_const_11 = i),
                 (Addr) &(temp_var_for_const_10 = 1.0)},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:94:19");
    computeDMul((Addr)&temp_var_for_tac_8,
                {(Addr) &(temp_var_for_const_12 = 3.0),
                 (Addr)&temp_var_for_tac_7, (Addr)&Vat},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:94:42");
    computeDMul((Addr)&temp_var_for_tac_9,
                {(Addr) &(temp_var_for_const_14 = 4),
                 (Addr) &(temp_var_for_const_13 = PI)},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:94:37");
    computeDDiv((Addr)&temp_var_for_tac_10,
                {(Addr)&temp_var_for_tac_8, (Addr)&temp_var_for_tac_9},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:94:54");
    computeDDiv((Addr)&temp_var_for_tac_11,
                {(Addr) &(temp_var_for_const_16 = 1.0),
                 (Addr) &(temp_var_for_const_15 = 3.0)},
                "toString(biExpr->getExprLoc())");
    computeDMul((Addr)&r[i], {(Addr)&temp_var_for_callexp_2,
                              (Addr) &(temp_var_for_const_17 = 1.0)},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:94:8");
    ; // nm
    double temp_var_for_const_18, temp_var_for_const_19;
    double temp_var_for_tac_12 = 2.0 * Gama * Vat;
    double temp_var_for_tac_13 = temp_var_for_tac_12 / r[i];
    EBvac[i] = EFvac - temp_var_for_tac_13;
    computeDMul(
        (Addr)&temp_var_for_tac_12,
        {(Addr) &(temp_var_for_const_18 = 2.0), (Addr)&Gama, (Addr)&Vat},
        "/home/shijia/Public/testprogram/ETD_S.c_e.c:95:38");
    computeDDiv(
        (Addr)&temp_var_for_tac_13,
        {(Addr)&temp_var_for_tac_12, (Addr) &(temp_var_for_const_19 = r[i])},
        "/home/shijia/Public/testprogram/ETD_S.c_e.c:95:20");
    computeDSub((Addr)&EBvac[i], {(Addr)&EFvac, (Addr)&temp_var_for_tac_13},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:95:12");
    ; // eV空位缺陷结合能
    double temp_var_for_const_20, temp_var_for_const_21, temp_var_for_const_22,
        temp_var_for_const_23, temp_var_for_const_24, temp_var_for_const_25,
        temp_var_for_const_26, temp_var_for_const_27;
    double temp_var_for_tac_14 = i + 1.0;
    double temp_var_for_tac_15 = 1.0 / 3.0;
    double temp_var_for_callexp_3;
    temp_var_for_callexp_3 = pow(temp_var_for_tac_14, temp_var_for_tac_15);
    CallStackPop((Addr)&temp_var_for_callexp_3, getTop(temp_var_for_callexp_3));

    double temp_var_for_tac_16 = Alpha0 * temp_var_for_callexp_3;
    double temp_var_for_tac_17 = 0.0 - EBvac[i];
    double temp_var_for_tac_18 = KB * T;
    double temp_var_for_tac_19 = temp_var_for_tac_17 / temp_var_for_tac_18;
    double temp_var_for_callexp_4;
    temp_var_for_callexp_4 = exp(temp_var_for_tac_19);
    CallStackPop((Addr)&temp_var_for_callexp_4, getTop(temp_var_for_callexp_4));

    Alpha[i] = temp_var_for_tac_16 * temp_var_for_callexp_4;
    computeDAdd((Addr)&temp_var_for_tac_14,
                {(Addr) &(temp_var_for_const_21 = i),
                 (Addr) &(temp_var_for_const_20 = 1.0)},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:96:42");
    computeDDiv((Addr)&temp_var_for_tac_15,
                {(Addr) &(temp_var_for_const_23 = 1.0),
                 (Addr) &(temp_var_for_const_22 = 3.0)},
                "toString(biExpr->getExprLoc())");
    computeDMul((Addr)&temp_var_for_tac_16,
                {(Addr)&Alpha0, (Addr)&temp_var_for_callexp_3},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:96:60");
    computeDSub((Addr)&temp_var_for_tac_17,
                {(Addr) &(temp_var_for_const_25 = 0.0),
                 (Addr) &(temp_var_for_const_24 = EBvac[i])},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:96:78");
    computeDMul((Addr)&temp_var_for_tac_18,
                {(Addr) &(temp_var_for_const_27 = KB),
                 (Addr) &(temp_var_for_const_26 = T)},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:96:72");
    computeDDiv((Addr)&temp_var_for_tac_19,
                {(Addr)&temp_var_for_tac_17, (Addr)&temp_var_for_tac_18},
                "toString(biExpr->getExprLoc())");
    computeDMul((Addr)&Alpha[i],
                {(Addr)&temp_var_for_tac_16, (Addr)&temp_var_for_callexp_4},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:96:12");
    ;
    double temp_var_for_const_28, temp_var_for_const_29, temp_var_for_const_30,
        temp_var_for_const_31;
    double temp_var_for_tac_20 = i + 1.0;
    double temp_var_for_tac_21 = 1.0 / 3.0;
    double temp_var_for_callexp_5;
    temp_var_for_callexp_5 = pow(temp_var_for_tac_20, temp_var_for_tac_21);
    CallStackPop((Addr)&temp_var_for_callexp_5, getTop(temp_var_for_callexp_5));

    Beta[i] = Beta0 * temp_var_for_callexp_5;
    computeDAdd((Addr)&temp_var_for_tac_20,
                {(Addr) &(temp_var_for_const_29 = i),
                 (Addr) &(temp_var_for_const_28 = 1.0)},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:97:40");
    computeDDiv((Addr)&temp_var_for_tac_21,
                {(Addr) &(temp_var_for_const_31 = 1.0),
                 (Addr) &(temp_var_for_const_30 = 3.0)},
                "toString(biExpr->getExprLoc())");
    computeDMul((Addr)&Beta[i], {(Addr)&Beta0, (Addr)&temp_var_for_callexp_5},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:97:11");
    ; //公式2
    int temp_var_for_ext_0;
    temp_var_for_ext_0 = i == 0;
    if (temp_var_for_ext_0) {
      double temp_var_for_const_32, temp_var_for_const_33;
      double temp_var_for_tac_22 = 1.0 + k;
      double temp_var_for_callexp_6;
      temp_var_for_callexp_6 = pow(temp_var_for_tac_22, (-(3)));
      CallStackPop((Addr)&temp_var_for_callexp_6,
                   getTop(temp_var_for_callexp_6));

      L3[0] = 0.0 - temp_var_for_callexp_6;
      computeDAdd((Addr)&temp_var_for_tac_22,
                  {(Addr) &(temp_var_for_const_32 = 1.0), (Addr)&k},
                  "toString(biExpr->getExprLoc())");
      computeDSub((Addr)&L3[0], {(Addr) &(temp_var_for_const_33 = 0.0),
                                 (Addr)&temp_var_for_callexp_6},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:102:10");
      ;
      double temp_var_for_const_34, temp_var_for_const_35,
          temp_var_for_const_36;
      double temp_var_for_tac_23 = 0.0 - dt;
      double temp_var_for_tac_24 = 1.0 + k;
      double temp_var_for_tac_25 = temp_var_for_tac_23 * temp_var_for_tac_24;
      double temp_var_for_tac_26 = temp_var_for_tac_25 / 2;
      double temp_var_for_callexp_7;
      temp_var_for_callexp_7 = exp(temp_var_for_tac_26);
      CallStackPop((Addr)&temp_var_for_callexp_7,
                   getTop(temp_var_for_callexp_7));

      phi1[0] = temp_var_for_callexp_7;
      AssignD({(Addr)&phi1[0]}, (Addr)&temp_var_for_callexp_7,
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:103:12");
      ;
      double temp_var_for_const_37, temp_var_for_const_38,
          temp_var_for_const_39, temp_var_for_const_40, temp_var_for_const_41;
      double temp_var_for_tac_27 = 0.0 - dt;
      double temp_var_for_tac_28 = 1.0 + k;
      double temp_var_for_tac_29 = temp_var_for_tac_27 * temp_var_for_tac_28;
      double temp_var_for_tac_30 = temp_var_for_tac_29 / 2;
      double temp_var_for_callexp_8;
      temp_var_for_callexp_8 = exp(temp_var_for_tac_30);
      CallStackPop((Addr)&temp_var_for_callexp_8,
                   getTop(temp_var_for_callexp_8));

      double temp_var_for_tac_31 = 1.0 - temp_var_for_callexp_8;
      double temp_var_for_tac_32 = 1.0 + k;
      phi2[0] = temp_var_for_tac_31 / temp_var_for_tac_32;
      computeDSub((Addr)&temp_var_for_tac_23,
                  {(Addr) &(temp_var_for_const_34 = 0.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:103:36");
      computeDAdd((Addr)&temp_var_for_tac_24,
                  {(Addr) &(temp_var_for_const_35 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:103:29");
      computeDMul((Addr)&temp_var_for_tac_25,
                  {(Addr)&temp_var_for_tac_23, (Addr)&temp_var_for_tac_24},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:103:41");
      computeDDiv(
          (Addr)&temp_var_for_tac_26,
          {(Addr)&temp_var_for_tac_25, (Addr) &(temp_var_for_const_36 = 2)},
          "toString(biExpr->getExprLoc())");
      computeDSub((Addr)&temp_var_for_tac_27,
                  {(Addr) &(temp_var_for_const_37 = 0.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:104:43");
      computeDAdd((Addr)&temp_var_for_tac_28,
                  {(Addr) &(temp_var_for_const_38 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:104:36");
      computeDMul((Addr)&temp_var_for_tac_29,
                  {(Addr)&temp_var_for_tac_27, (Addr)&temp_var_for_tac_28},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:104:48");
      computeDDiv(
          (Addr)&temp_var_for_tac_30,
          {(Addr)&temp_var_for_tac_29, (Addr) &(temp_var_for_const_39 = 2)},
          "toString(biExpr->getExprLoc())");
      computeDSub((Addr)&temp_var_for_tac_31,
                  {(Addr) &(temp_var_for_const_40 = 1.0),
                   (Addr)&temp_var_for_callexp_8},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:104:61");
      computeDAdd((Addr)&temp_var_for_tac_32,
                  {(Addr) &(temp_var_for_const_41 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:104:54");
      computeDDiv((Addr)&phi2[0],
                  {(Addr)&temp_var_for_tac_31, (Addr)&temp_var_for_tac_32},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:104:12");
      ;
      double temp_var_for_const_42, temp_var_for_const_43;
      double temp_var_for_tac_33 = 0.0 - dt;
      double temp_var_for_tac_34 = 1.0 + k;
      double temp_var_for_tac_35 = temp_var_for_tac_33 * temp_var_for_tac_34;
      double temp_var_for_callexp_9;
      temp_var_for_callexp_9 = exp(temp_var_for_tac_35);
      CallStackPop((Addr)&temp_var_for_callexp_9,
                   getTop(temp_var_for_callexp_9));

      phi3[0] = temp_var_for_callexp_9;
      AssignD({(Addr)&phi3[0]}, (Addr)&temp_var_for_callexp_9,
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:105:12");
      ;
      double temp_var_for_const_44, temp_var_for_const_45,
          temp_var_for_const_46, temp_var_for_const_47, temp_var_for_const_48,
          temp_var_for_const_49, temp_var_for_const_50, temp_var_for_const_51,
          temp_var_for_const_52, temp_var_for_const_53;
      double temp_var_for_tac_36 = 0.0 - 4.0;
      double temp_var_for_tac_37 = 1.0 + k;
      double temp_var_for_tac_38 = dt * temp_var_for_tac_37;
      double temp_var_for_tac_39 = temp_var_for_tac_36 + temp_var_for_tac_38;
      double temp_var_for_tac_40 = 0.0 - dt;
      double temp_var_for_tac_41 = 1.0 + k;
      double temp_var_for_tac_42 = temp_var_for_tac_40 * temp_var_for_tac_41;
      double temp_var_for_tac_43 = 3.0 * dt;
      double temp_var_for_tac_44 = 1.0 + k;
      double temp_var_for_tac_45 = temp_var_for_tac_43 * temp_var_for_tac_44;
      double temp_var_for_tac_46 = 4 + temp_var_for_tac_45;
      double temp_var_for_tac_47 = dt * dt;
      double temp_var_for_tac_48 = 1.0 + k;
      double temp_var_for_tac_49 = temp_var_for_tac_47 * temp_var_for_tac_48;
      double temp_var_for_tac_50 = 1.0 + k;
      double temp_var_for_tac_51 = temp_var_for_tac_49 * temp_var_for_tac_50;
      double temp_var_for_callexp_10;
      temp_var_for_callexp_10 = exp(temp_var_for_tac_42);
      CallStackPop((Addr)&temp_var_for_callexp_10,
                   getTop(temp_var_for_callexp_10));

      double temp_var_for_tac_52 = temp_var_for_tac_46 + temp_var_for_tac_51;
      double temp_var_for_tac_53 =
          temp_var_for_callexp_10 * temp_var_for_tac_52;
      poly1[0] = temp_var_for_tac_39 + temp_var_for_tac_53;
      computeDSub((Addr)&temp_var_for_tac_33,
                  {(Addr) &(temp_var_for_const_42 = 0.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:105:36");
      computeDAdd((Addr)&temp_var_for_tac_34,
                  {(Addr) &(temp_var_for_const_43 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:105:29");
      computeDMul((Addr)&temp_var_for_tac_35,
                  {(Addr)&temp_var_for_tac_33, (Addr)&temp_var_for_tac_34},
                  "toString(biExpr->getExprLoc())");
      computeDSub((Addr)&temp_var_for_tac_36,
                  {(Addr) &(temp_var_for_const_45 = 0.0),
                   (Addr) &(temp_var_for_const_44 = 4.0)},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:37");
      computeDAdd((Addr)&temp_var_for_tac_37,
                  {(Addr) &(temp_var_for_const_46 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:30");
      computeDMul((Addr)&temp_var_for_tac_38,
                  {(Addr)&dt, (Addr)&temp_var_for_tac_37},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:25");
      computeDAdd((Addr)&temp_var_for_tac_39,
                  {(Addr)&temp_var_for_tac_36, (Addr)&temp_var_for_tac_38},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:53");
      computeDSub((Addr)&temp_var_for_tac_40,
                  {(Addr) &(temp_var_for_const_47 = 0.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:66");
      computeDAdd((Addr)&temp_var_for_tac_41,
                  {(Addr) &(temp_var_for_const_48 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:59");
      computeDMul((Addr)&temp_var_for_tac_42,
                  {(Addr)&temp_var_for_tac_40, (Addr)&temp_var_for_tac_41},
                  "toString(biExpr->getExprLoc())");
      computeDMul((Addr)&temp_var_for_tac_43,
                  {(Addr) &(temp_var_for_const_49 = 3.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:95");
      computeDAdd((Addr)&temp_var_for_tac_44,
                  {(Addr) &(temp_var_for_const_50 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:88");
      computeDMul((Addr)&temp_var_for_tac_45,
                  {(Addr)&temp_var_for_tac_43, (Addr)&temp_var_for_tac_44},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:77");
      computeDAdd(
          (Addr)&temp_var_for_tac_46,
          {(Addr) &(temp_var_for_const_51 = 4), (Addr)&temp_var_for_tac_45},
          "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:105");
      computeDMul((Addr)&temp_var_for_tac_47, {(Addr)&dt, (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:117");
      computeDAdd((Addr)&temp_var_for_tac_48,
                  {(Addr) &(temp_var_for_const_52 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:110");
      computeDMul((Addr)&temp_var_for_tac_49,
                  {(Addr)&temp_var_for_tac_47, (Addr)&temp_var_for_tac_48},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:129");
      computeDAdd((Addr)&temp_var_for_tac_50,
                  {(Addr) &(temp_var_for_const_53 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:122");
      computeDMul((Addr)&temp_var_for_tac_51,
                  {(Addr)&temp_var_for_tac_49, (Addr)&temp_var_for_tac_50},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:100");
      computeDAdd((Addr)&temp_var_for_tac_52,
                  {(Addr)&temp_var_for_tac_46, (Addr)&temp_var_for_tac_51},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:72");
      computeDMul((Addr)&temp_var_for_tac_53,
                  {(Addr)&temp_var_for_callexp_10, (Addr)&temp_var_for_tac_52},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:42");
      computeDAdd((Addr)&poly1[0],
                  {(Addr)&temp_var_for_tac_39, (Addr)&temp_var_for_tac_53},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:13");
      ;
      double temp_var_for_const_54, temp_var_for_const_55,
          temp_var_for_const_56, temp_var_for_const_57, temp_var_for_const_58,
          temp_var_for_const_59, temp_var_for_const_60, temp_var_for_const_61;
      double temp_var_for_tac_54 = 2.0 * dt;
      double temp_var_for_tac_55 = 1.0 + k;
      double temp_var_for_tac_56 = temp_var_for_tac_54 * temp_var_for_tac_55;
      double temp_var_for_tac_57 = 4.0 - temp_var_for_tac_56;
      double temp_var_for_tac_58 = 0.0 - dt;
      double temp_var_for_tac_59 = 1.0 + k;
      double temp_var_for_tac_60 = temp_var_for_tac_58 * temp_var_for_tac_59;
      double temp_var_for_tac_61 = 2.0 * dt;
      double temp_var_for_tac_62 = 1.0 + k;
      double temp_var_for_tac_63 = temp_var_for_tac_61 * temp_var_for_tac_62;
      double temp_var_for_callexp_11;
      temp_var_for_callexp_11 = exp(temp_var_for_tac_60);
      CallStackPop((Addr)&temp_var_for_callexp_11,
                   getTop(temp_var_for_callexp_11));

      double temp_var_for_tac_64 = (-(4)) - temp_var_for_tac_63;
      double temp_var_for_tac_65 =
          temp_var_for_callexp_11 * temp_var_for_tac_64;
      poly2[0] = temp_var_for_tac_57 + temp_var_for_tac_65;
      computeDMul((Addr)&temp_var_for_tac_54,
                  {(Addr) &(temp_var_for_const_54 = 2.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:34");
      computeDAdd((Addr)&temp_var_for_tac_55,
                  {(Addr) &(temp_var_for_const_55 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:27");
      computeDMul((Addr)&temp_var_for_tac_56,
                  {(Addr)&temp_var_for_tac_54, (Addr)&temp_var_for_tac_55},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:17");
      computeDSub(
          (Addr)&temp_var_for_tac_57,
          {(Addr) &(temp_var_for_const_56 = 4.0), (Addr)&temp_var_for_tac_56},
          "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:50");
      computeDSub((Addr)&temp_var_for_tac_58,
                  {(Addr) &(temp_var_for_const_57 = 0.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:63");
      computeDAdd((Addr)&temp_var_for_tac_59,
                  {(Addr) &(temp_var_for_const_58 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:56");
      computeDMul((Addr)&temp_var_for_tac_60,
                  {(Addr)&temp_var_for_tac_58, (Addr)&temp_var_for_tac_59},
                  "toString(biExpr->getExprLoc())");
      computeDMul((Addr)&temp_var_for_tac_61,
                  {(Addr) &(temp_var_for_const_59 = 2.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:92");
      computeDAdd((Addr)&temp_var_for_tac_62,
                  {(Addr) &(temp_var_for_const_60 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:85");
      computeDMul((Addr)&temp_var_for_tac_63,
                  {(Addr)&temp_var_for_tac_61, (Addr)&temp_var_for_tac_62},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:75");
      computeDSub((Addr)&temp_var_for_tac_64,
                  {(Addr) &(temp_var_for_const_61 = (-(4))),
                   (Addr)&temp_var_for_tac_63},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:69");
      computeDMul((Addr)&temp_var_for_tac_65,
                  {(Addr)&temp_var_for_callexp_11, (Addr)&temp_var_for_tac_64},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:39");
      computeDAdd((Addr)&poly2[0],
                  {(Addr)&temp_var_for_tac_57, (Addr)&temp_var_for_tac_65},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:13");
      ;
      double temp_var_for_const_62, temp_var_for_const_63,
          temp_var_for_const_64, temp_var_for_const_65, temp_var_for_const_66,
          temp_var_for_const_67, temp_var_for_const_68, temp_var_for_const_69,
          temp_var_for_const_70, temp_var_for_const_71;
      double temp_var_for_tac_66 = 0.0 - 4.0;
      double temp_var_for_tac_67 = 3.0 * dt;
      double temp_var_for_tac_68 = 1.0 + k;
      double temp_var_for_tac_69 = temp_var_for_tac_67 * temp_var_for_tac_68;
      double temp_var_for_tac_70 = temp_var_for_tac_66 + temp_var_for_tac_69;
      double temp_var_for_tac_71 = dt * dt;
      double temp_var_for_tac_72 = 1.0 + k;
      double temp_var_for_tac_73 = temp_var_for_tac_71 * temp_var_for_tac_72;
      double temp_var_for_tac_74 = 1.0 + k;
      double temp_var_for_tac_75 = temp_var_for_tac_73 * temp_var_for_tac_74;
      double temp_var_for_tac_76 = temp_var_for_tac_70 - temp_var_for_tac_75;
      double temp_var_for_tac_77 = 0.0 - dt;
      double temp_var_for_tac_78 = 1.0 + k;
      double temp_var_for_tac_79 = temp_var_for_tac_77 * temp_var_for_tac_78;
      double temp_var_for_tac_80 = 1.0 + k;
      double temp_var_for_tac_81 = dt * temp_var_for_tac_80;
      double temp_var_for_callexp_12;
      temp_var_for_callexp_12 = exp(temp_var_for_tac_79);
      CallStackPop((Addr)&temp_var_for_callexp_12,
                   getTop(temp_var_for_callexp_12));

      double temp_var_for_tac_82 = 4 + temp_var_for_tac_81;
      double temp_var_for_tac_83 =
          temp_var_for_callexp_12 * temp_var_for_tac_82;
      poly3[0] = temp_var_for_tac_76 + temp_var_for_tac_83;
      computeDSub((Addr)&temp_var_for_tac_66,
                  {(Addr) &(temp_var_for_const_63 = 0.0),
                   (Addr) &(temp_var_for_const_62 = 4.0)},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:108:31");
      computeDMul((Addr)&temp_var_for_tac_67,
                  {(Addr) &(temp_var_for_const_64 = 3.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:108:43");
      computeDAdd((Addr)&temp_var_for_tac_68,
                  {(Addr) &(temp_var_for_const_65 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:108:36");
      computeDMul((Addr)&temp_var_for_tac_69,
                  {(Addr)&temp_var_for_tac_67, (Addr)&temp_var_for_tac_68},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:108:25");
      computeDAdd((Addr)&temp_var_for_tac_70,
                  {(Addr)&temp_var_for_tac_66, (Addr)&temp_var_for_tac_69},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:108:53");
      computeDMul((Addr)&temp_var_for_tac_71, {(Addr)&dt, (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:108:65");
      computeDAdd((Addr)&temp_var_for_tac_72,
                  {(Addr) &(temp_var_for_const_66 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:108:58");
      computeDMul((Addr)&temp_var_for_tac_73,
                  {(Addr)&temp_var_for_tac_71, (Addr)&temp_var_for_tac_72},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:108:77");
      computeDAdd((Addr)&temp_var_for_tac_74,
                  {(Addr) &(temp_var_for_const_67 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:108:70");
      computeDMul((Addr)&temp_var_for_tac_75,
                  {(Addr)&temp_var_for_tac_73, (Addr)&temp_var_for_tac_74},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:108:48");
      computeDSub((Addr)&temp_var_for_tac_76,
                  {(Addr)&temp_var_for_tac_70, (Addr)&temp_var_for_tac_75},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:108:93");
      computeDSub((Addr)&temp_var_for_tac_77,
                  {(Addr) &(temp_var_for_const_68 = 0.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:108:106");
      computeDAdd((Addr)&temp_var_for_tac_78,
                  {(Addr) &(temp_var_for_const_69 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:108:99");
      computeDMul((Addr)&temp_var_for_tac_79,
                  {(Addr)&temp_var_for_tac_77, (Addr)&temp_var_for_tac_78},
                  "toString(biExpr->getExprLoc())");
      computeDAdd((Addr)&temp_var_for_tac_80,
                  {(Addr) &(temp_var_for_const_70 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:108:122");
      computeDMul((Addr)&temp_var_for_tac_81,
                  {(Addr)&dt, (Addr)&temp_var_for_tac_80},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:108:117");
      computeDAdd(
          (Addr)&temp_var_for_tac_82,
          {(Addr) &(temp_var_for_const_71 = 4), (Addr)&temp_var_for_tac_81},
          "/home/shijia/Public/testprogram/ETD_S.c_e.c:108:112");
      computeDMul((Addr)&temp_var_for_tac_83,
                  {(Addr)&temp_var_for_callexp_12, (Addr)&temp_var_for_tac_82},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:108:82");
      computeDAdd((Addr)&poly3[0],
                  {(Addr)&temp_var_for_tac_76, (Addr)&temp_var_for_tac_83},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:108:13");
      ;
    } else {
      double temp_var_for_const_72, temp_var_for_const_73;
      double temp_var_for_tac_84 = Alpha[i] + k;
      double temp_var_for_callexp_13;
      temp_var_for_callexp_13 = pow(temp_var_for_tac_84, (-(3)));
      CallStackPop((Addr)&temp_var_for_callexp_13,
                   getTop(temp_var_for_callexp_13));

      L3[i] = 0.0 - temp_var_for_callexp_13;
      computeDAdd((Addr)&temp_var_for_tac_84,
                  {(Addr) &(temp_var_for_const_72 = Alpha[i]), (Addr)&k},
                  "toString(biExpr->getExprLoc())");
      computeDSub((Addr)&L3[i], {(Addr) &(temp_var_for_const_73 = 0.0),
                                 (Addr)&temp_var_for_callexp_13},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:112:10");
      ;
      double temp_var_for_const_74, temp_var_for_const_75,
          temp_var_for_const_76;
      double temp_var_for_tac_85 = 0.0 - dt;
      double temp_var_for_tac_86 = Alpha[i] + k;
      double temp_var_for_tac_87 = temp_var_for_tac_85 * temp_var_for_tac_86;
      double temp_var_for_tac_88 = temp_var_for_tac_87 / 2;
      double temp_var_for_callexp_14;
      temp_var_for_callexp_14 = exp(temp_var_for_tac_88);
      CallStackPop((Addr)&temp_var_for_callexp_14,
                   getTop(temp_var_for_callexp_14));

      phi1[i] = temp_var_for_callexp_14;
      AssignD({(Addr)&phi1[i]}, (Addr)&temp_var_for_callexp_14,
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:113:12");
      ;
      double temp_var_for_const_77, temp_var_for_const_78,
          temp_var_for_const_79, temp_var_for_const_80, temp_var_for_const_81;
      double temp_var_for_tac_89 = 0.0 - dt;
      double temp_var_for_tac_90 = Alpha[i] + k;
      double temp_var_for_tac_91 = temp_var_for_tac_89 * temp_var_for_tac_90;
      double temp_var_for_tac_92 = temp_var_for_tac_91 / 2;
      double temp_var_for_callexp_15;
      temp_var_for_callexp_15 = exp(temp_var_for_tac_92);
      CallStackPop((Addr)&temp_var_for_callexp_15,
                   getTop(temp_var_for_callexp_15));

      double temp_var_for_tac_93 = 1.0 - temp_var_for_callexp_15;
      double temp_var_for_tac_94 = Alpha[i] + k;
      phi2[i] = temp_var_for_tac_93 / temp_var_for_tac_94;
      computeDSub((Addr)&temp_var_for_tac_85,
                  {(Addr) &(temp_var_for_const_74 = 0.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:113:41");
      computeDAdd((Addr)&temp_var_for_tac_86,
                  {(Addr) &(temp_var_for_const_75 = Alpha[i]), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:113:29");
      computeDMul((Addr)&temp_var_for_tac_87,
                  {(Addr)&temp_var_for_tac_85, (Addr)&temp_var_for_tac_86},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:113:46");
      computeDDiv(
          (Addr)&temp_var_for_tac_88,
          {(Addr)&temp_var_for_tac_87, (Addr) &(temp_var_for_const_76 = 2)},
          "toString(biExpr->getExprLoc())");
      computeDSub((Addr)&temp_var_for_tac_89,
                  {(Addr) &(temp_var_for_const_77 = 0.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:114:48");
      computeDAdd((Addr)&temp_var_for_tac_90,
                  {(Addr) &(temp_var_for_const_78 = Alpha[i]), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:114:36");
      computeDMul((Addr)&temp_var_for_tac_91,
                  {(Addr)&temp_var_for_tac_89, (Addr)&temp_var_for_tac_90},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:114:53");
      computeDDiv(
          (Addr)&temp_var_for_tac_92,
          {(Addr)&temp_var_for_tac_91, (Addr) &(temp_var_for_const_79 = 2)},
          "toString(biExpr->getExprLoc())");
      computeDSub((Addr)&temp_var_for_tac_93,
                  {(Addr) &(temp_var_for_const_80 = 1.0),
                   (Addr)&temp_var_for_callexp_15},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:114:71");
      computeDAdd((Addr)&temp_var_for_tac_94,
                  {(Addr) &(temp_var_for_const_81 = Alpha[i]), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:114:59");
      computeDDiv((Addr)&phi2[i],
                  {(Addr)&temp_var_for_tac_93, (Addr)&temp_var_for_tac_94},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:114:12");
      ;
      double temp_var_for_const_82, temp_var_for_const_83;
      double temp_var_for_tac_95 = 0.0 - dt;
      double temp_var_for_tac_96 = Alpha[i] + k;
      double temp_var_for_tac_97 = temp_var_for_tac_95 * temp_var_for_tac_96;
      double temp_var_for_callexp_16;
      temp_var_for_callexp_16 = exp(temp_var_for_tac_97);
      CallStackPop((Addr)&temp_var_for_callexp_16,
                   getTop(temp_var_for_callexp_16));

      phi3[i] = temp_var_for_callexp_16;
      AssignD({(Addr)&phi3[i]}, (Addr)&temp_var_for_callexp_16,
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:12");
      ;
      double temp_var_for_const_84, temp_var_for_const_85,
          temp_var_for_const_86, temp_var_for_const_87, temp_var_for_const_88,
          temp_var_for_const_89, temp_var_for_const_90, temp_var_for_const_91,
          temp_var_for_const_92, temp_var_for_const_93;
      double temp_var_for_tac_98 = 0.0 - 4.0;
      double temp_var_for_tac_99 = Alpha[i] + k;
      double temp_var_for_tac_100 = dt * temp_var_for_tac_99;
      double temp_var_for_tac_101 = temp_var_for_tac_98 + temp_var_for_tac_100;
      double temp_var_for_tac_102 = 0.0 - dt;
      double temp_var_for_tac_103 = Alpha[i] + k;
      double temp_var_for_tac_104 = temp_var_for_tac_102 * temp_var_for_tac_103;
      double temp_var_for_tac_105 = 3.0 * dt;
      double temp_var_for_tac_106 = Alpha[i] + k;
      double temp_var_for_tac_107 = temp_var_for_tac_105 * temp_var_for_tac_106;
      double temp_var_for_tac_108 = 4 + temp_var_for_tac_107;
      double temp_var_for_tac_109 = dt * dt;
      double temp_var_for_tac_110 = Alpha[i] + k;
      double temp_var_for_tac_111 = temp_var_for_tac_109 * temp_var_for_tac_110;
      double temp_var_for_tac_112 = Alpha[i] + k;
      double temp_var_for_tac_113 = temp_var_for_tac_111 * temp_var_for_tac_112;
      double temp_var_for_callexp_17;
      temp_var_for_callexp_17 = exp(temp_var_for_tac_104);
      CallStackPop((Addr)&temp_var_for_callexp_17,
                   getTop(temp_var_for_callexp_17));

      double temp_var_for_tac_114 = temp_var_for_tac_108 + temp_var_for_tac_113;
      double temp_var_for_tac_115 =
          temp_var_for_callexp_17 * temp_var_for_tac_114;
      poly1[i] = temp_var_for_tac_101 + temp_var_for_tac_115;
      computeDSub((Addr)&temp_var_for_tac_95,
                  {(Addr) &(temp_var_for_const_82 = 0.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:41");
      computeDAdd((Addr)&temp_var_for_tac_96,
                  {(Addr) &(temp_var_for_const_83 = Alpha[i]), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:29");
      computeDMul((Addr)&temp_var_for_tac_97,
                  {(Addr)&temp_var_for_tac_95, (Addr)&temp_var_for_tac_96},
                  "toString(biExpr->getExprLoc())");
      computeDSub((Addr)&temp_var_for_tac_98,
                  {(Addr) &(temp_var_for_const_85 = 0.0),
                   (Addr) &(temp_var_for_const_84 = 4.0)},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:42");
      computeDAdd((Addr)&temp_var_for_tac_99,
                  {(Addr) &(temp_var_for_const_86 = Alpha[i]), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:30");
      computeDMul((Addr)&temp_var_for_tac_100,
                  {(Addr)&dt, (Addr)&temp_var_for_tac_99},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:25");
      computeDAdd((Addr)&temp_var_for_tac_101,
                  {(Addr)&temp_var_for_tac_98, (Addr)&temp_var_for_tac_100},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:58");
      computeDSub((Addr)&temp_var_for_tac_102,
                  {(Addr) &(temp_var_for_const_87 = 0.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:76");
      computeDAdd((Addr)&temp_var_for_tac_103,
                  {(Addr) &(temp_var_for_const_88 = Alpha[i]), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:64");
      computeDMul((Addr)&temp_var_for_tac_104,
                  {(Addr)&temp_var_for_tac_102, (Addr)&temp_var_for_tac_103},
                  "toString(biExpr->getExprLoc())");
      computeDMul((Addr)&temp_var_for_tac_105,
                  {(Addr) &(temp_var_for_const_89 = 3.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:110");
      computeDAdd((Addr)&temp_var_for_tac_106,
                  {(Addr) &(temp_var_for_const_90 = Alpha[i]), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:98");
      computeDMul((Addr)&temp_var_for_tac_107,
                  {(Addr)&temp_var_for_tac_105, (Addr)&temp_var_for_tac_106},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:87");
      computeDAdd(
          (Addr)&temp_var_for_tac_108,
          {(Addr) &(temp_var_for_const_91 = 4), (Addr)&temp_var_for_tac_107},
          "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:120");
      computeDMul((Addr)&temp_var_for_tac_109, {(Addr)&dt, (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:137");
      computeDAdd((Addr)&temp_var_for_tac_110,
                  {(Addr) &(temp_var_for_const_92 = Alpha[i]), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:125");
      computeDMul((Addr)&temp_var_for_tac_111,
                  {(Addr)&temp_var_for_tac_109, (Addr)&temp_var_for_tac_110},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:154");
      computeDAdd((Addr)&temp_var_for_tac_112,
                  {(Addr) &(temp_var_for_const_93 = Alpha[i]), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:142");
      computeDMul((Addr)&temp_var_for_tac_113,
                  {(Addr)&temp_var_for_tac_111, (Addr)&temp_var_for_tac_112},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:115");
      computeDAdd((Addr)&temp_var_for_tac_114,
                  {(Addr)&temp_var_for_tac_108, (Addr)&temp_var_for_tac_113},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:82");
      computeDMul((Addr)&temp_var_for_tac_115,
                  {(Addr)&temp_var_for_callexp_17, (Addr)&temp_var_for_tac_114},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:47");
      computeDAdd((Addr)&poly1[i],
                  {(Addr)&temp_var_for_tac_101, (Addr)&temp_var_for_tac_115},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:13");
      ;
      double temp_var_for_const_94, temp_var_for_const_95,
          temp_var_for_const_96, temp_var_for_const_97, temp_var_for_const_98,
          temp_var_for_const_99, temp_var_for_const_100, temp_var_for_const_101;
      double temp_var_for_tac_116 = 2.0 * dt;
      double temp_var_for_tac_117 = Alpha[i] + k;
      double temp_var_for_tac_118 = temp_var_for_tac_116 * temp_var_for_tac_117;
      double temp_var_for_tac_119 = 4.0 - temp_var_for_tac_118;
      double temp_var_for_tac_120 = 0.0 - dt;
      double temp_var_for_tac_121 = Alpha[i] + k;
      double temp_var_for_tac_122 = temp_var_for_tac_120 * temp_var_for_tac_121;
      double temp_var_for_tac_123 = 2.0 * dt;
      double temp_var_for_tac_124 = Alpha[i] + k;
      double temp_var_for_tac_125 = temp_var_for_tac_123 * temp_var_for_tac_124;
      double temp_var_for_callexp_18;
      temp_var_for_callexp_18 = exp(temp_var_for_tac_122);
      CallStackPop((Addr)&temp_var_for_callexp_18,
                   getTop(temp_var_for_callexp_18));

      double temp_var_for_tac_126 = (-(4)) - temp_var_for_tac_125;
      double temp_var_for_tac_127 =
          temp_var_for_callexp_18 * temp_var_for_tac_126;
      poly2[i] = temp_var_for_tac_119 + temp_var_for_tac_127;
      computeDMul((Addr)&temp_var_for_tac_116,
                  {(Addr) &(temp_var_for_const_94 = 2.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:39");
      computeDAdd((Addr)&temp_var_for_tac_117,
                  {(Addr) &(temp_var_for_const_95 = Alpha[i]), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:27");
      computeDMul((Addr)&temp_var_for_tac_118,
                  {(Addr)&temp_var_for_tac_116, (Addr)&temp_var_for_tac_117},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:17");
      computeDSub(
          (Addr)&temp_var_for_tac_119,
          {(Addr) &(temp_var_for_const_96 = 4.0), (Addr)&temp_var_for_tac_118},
          "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:55");
      computeDSub((Addr)&temp_var_for_tac_120,
                  {(Addr) &(temp_var_for_const_97 = 0.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:73");
      computeDAdd((Addr)&temp_var_for_tac_121,
                  {(Addr) &(temp_var_for_const_98 = Alpha[i]), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:61");
      computeDMul((Addr)&temp_var_for_tac_122,
                  {(Addr)&temp_var_for_tac_120, (Addr)&temp_var_for_tac_121},
                  "toString(biExpr->getExprLoc())");
      computeDMul((Addr)&temp_var_for_tac_123,
                  {(Addr) &(temp_var_for_const_99 = 2.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:107");
      computeDAdd((Addr)&temp_var_for_tac_124,
                  {(Addr) &(temp_var_for_const_100 = Alpha[i]), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:95");
      computeDMul((Addr)&temp_var_for_tac_125,
                  {(Addr)&temp_var_for_tac_123, (Addr)&temp_var_for_tac_124},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:85");
      computeDSub((Addr)&temp_var_for_tac_126,
                  {(Addr) &(temp_var_for_const_101 = (-(4))),
                   (Addr)&temp_var_for_tac_125},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:79");
      computeDMul((Addr)&temp_var_for_tac_127,
                  {(Addr)&temp_var_for_callexp_18, (Addr)&temp_var_for_tac_126},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:44");
      computeDAdd((Addr)&poly2[i],
                  {(Addr)&temp_var_for_tac_119, (Addr)&temp_var_for_tac_127},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:13");
      ;
      double temp_var_for_const_102, temp_var_for_const_103,
          temp_var_for_const_104, temp_var_for_const_105,
          temp_var_for_const_106, temp_var_for_const_107,
          temp_var_for_const_108, temp_var_for_const_109,
          temp_var_for_const_110, temp_var_for_const_111;
      double temp_var_for_tac_128 = 0.0 - 4.0;
      double temp_var_for_tac_129 = 3.0 * dt;
      double temp_var_for_tac_130 = Alpha[i] + k;
      double temp_var_for_tac_131 = temp_var_for_tac_129 * temp_var_for_tac_130;
      double temp_var_for_tac_132 = temp_var_for_tac_128 + temp_var_for_tac_131;
      double temp_var_for_tac_133 = dt * dt;
      double temp_var_for_tac_134 = Alpha[i] + k;
      double temp_var_for_tac_135 = temp_var_for_tac_133 * temp_var_for_tac_134;
      double temp_var_for_tac_136 = Alpha[i] + k;
      double temp_var_for_tac_137 = temp_var_for_tac_135 * temp_var_for_tac_136;
      double temp_var_for_tac_138 = temp_var_for_tac_132 - temp_var_for_tac_137;
      double temp_var_for_tac_139 = 0.0 - dt;
      double temp_var_for_tac_140 = Alpha[i] + k;
      double temp_var_for_tac_141 = temp_var_for_tac_139 * temp_var_for_tac_140;
      double temp_var_for_tac_142 = Alpha[i] + k;
      double temp_var_for_tac_143 = dt * temp_var_for_tac_142;
      double temp_var_for_callexp_19;
      temp_var_for_callexp_19 = exp(temp_var_for_tac_141);
      CallStackPop((Addr)&temp_var_for_callexp_19,
                   getTop(temp_var_for_callexp_19));

      double temp_var_for_tac_144 = 4 + temp_var_for_tac_143;
      double temp_var_for_tac_145 =
          temp_var_for_callexp_19 * temp_var_for_tac_144;
      poly3[i] = temp_var_for_tac_138 + temp_var_for_tac_145;
      computeDSub((Addr)&temp_var_for_tac_128,
                  {(Addr) &(temp_var_for_const_103 = 0.0),
                   (Addr) &(temp_var_for_const_102 = 4.0)},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:118:31");
      computeDMul((Addr)&temp_var_for_tac_129,
                  {(Addr) &(temp_var_for_const_104 = 3.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:118:48");
      computeDAdd((Addr)&temp_var_for_tac_130,
                  {(Addr) &(temp_var_for_const_105 = Alpha[i]), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:118:36");
      computeDMul((Addr)&temp_var_for_tac_131,
                  {(Addr)&temp_var_for_tac_129, (Addr)&temp_var_for_tac_130},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:118:25");
      computeDAdd((Addr)&temp_var_for_tac_132,
                  {(Addr)&temp_var_for_tac_128, (Addr)&temp_var_for_tac_131},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:118:58");
      computeDMul((Addr)&temp_var_for_tac_133, {(Addr)&dt, (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:118:75");
      computeDAdd((Addr)&temp_var_for_tac_134,
                  {(Addr) &(temp_var_for_const_106 = Alpha[i]), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:118:63");
      computeDMul((Addr)&temp_var_for_tac_135,
                  {(Addr)&temp_var_for_tac_133, (Addr)&temp_var_for_tac_134},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:118:92");
      computeDAdd((Addr)&temp_var_for_tac_136,
                  {(Addr) &(temp_var_for_const_107 = Alpha[i]), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:118:80");
      computeDMul((Addr)&temp_var_for_tac_137,
                  {(Addr)&temp_var_for_tac_135, (Addr)&temp_var_for_tac_136},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:118:53");
      computeDSub((Addr)&temp_var_for_tac_138,
                  {(Addr)&temp_var_for_tac_132, (Addr)&temp_var_for_tac_137},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:118:108");
      computeDSub((Addr)&temp_var_for_tac_139,
                  {(Addr) &(temp_var_for_const_108 = 0.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:118:126");
      computeDAdd((Addr)&temp_var_for_tac_140,
                  {(Addr) &(temp_var_for_const_109 = Alpha[i]), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:118:114");
      computeDMul((Addr)&temp_var_for_tac_141,
                  {(Addr)&temp_var_for_tac_139, (Addr)&temp_var_for_tac_140},
                  "toString(biExpr->getExprLoc())");
      computeDAdd((Addr)&temp_var_for_tac_142,
                  {(Addr) &(temp_var_for_const_110 = Alpha[i]), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:118:142");
      computeDMul((Addr)&temp_var_for_tac_143,
                  {(Addr)&dt, (Addr)&temp_var_for_tac_142},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:118:137");
      computeDAdd(
          (Addr)&temp_var_for_tac_144,
          {(Addr) &(temp_var_for_const_111 = 4), (Addr)&temp_var_for_tac_143},
          "/home/shijia/Public/testprogram/ETD_S.c_e.c:118:132");
      computeDMul((Addr)&temp_var_for_tac_145,
                  {(Addr)&temp_var_for_callexp_19, (Addr)&temp_var_for_tac_144},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:118:97");
      computeDAdd((Addr)&poly3[i],
                  {(Addr)&temp_var_for_tac_138, (Addr)&temp_var_for_tac_145},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:118:13");
      ;
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

  while ( t < TIME) {
    // printf("t=%f******sumalpha=%e\tsumbeta=%e\n",t,sumalpha,sumbeta);
    for (i = 0; i < N; i++) {
      int temp_var_for_ext_2;
      temp_var_for_ext_2 = i == 0;
      if (temp_var_for_ext_2) {
        double temp_var_for_const_112;
        alpha[i] = 0.0;
        AssignD({(Addr)&alpha[i]}, (Addr) &(temp_var_for_const_112 = 0.0),
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:142:14");
        ;
        double temp_var_for_const_113;
        beta[i] = 0.0;
        AssignD({(Addr)&beta[i]}, (Addr) &(temp_var_for_const_113 = 0.0),
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:143:13");
        ;
      } else {
        double temp_var_for_const_114, temp_var_for_const_115;
        alpha[i] = Alpha[i] * C[i];
        computeDMul((Addr)&alpha[i],
                    {(Addr) &(temp_var_for_const_115 = Alpha[i]),
                     (Addr) &(temp_var_for_const_114 = C[i])},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:147:14");
        ;
        double temp_var_for_const_116, temp_var_for_const_117,
            temp_var_for_const_118;
        beta[i] = Beta[i] * C[i] * C[0];
        computeDMul((Addr)&beta[i], {(Addr) &(temp_var_for_const_117 = Beta[i]),
                                     (Addr) &(temp_var_for_const_116 = C[i]),
                                     (Addr) &(temp_var_for_const_118 = C[0])},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:148:13");
        ;
      }
      sumbeta += beta[i];
      ;
      sumalpha += alpha[i];
      ;
    }
    // printf("t=%f******sumalpha=%e\tsumbeta=%e\n",t,sumalpha,sumbeta);

    double temp_var_for_const_119, temp_var_for_const_120,
        temp_var_for_const_121, temp_var_for_const_122, temp_var_for_const_123,
        temp_var_for_const_124, temp_var_for_const_125, temp_var_for_const_126;
    double temp_var_for_tac_146 = (-(2)) * Beta[0] * C[0] * C[0];
    double temp_var_for_tac_147 = temp_var_for_tac_146 - sumbeta;
    double temp_var_for_tac_148 = temp_var_for_tac_147 + sumalpha;
    double temp_var_for_tac_149 = Alpha[1] * C[1];
    double temp_var_for_tac_150 = temp_var_for_tac_148 + temp_var_for_tac_149;
    double temp_var_for_tac_151 = 1.0 + k;
    double temp_var_for_tac_152 = temp_var_for_tac_151 * C[0];
    Fc[0] = temp_var_for_tac_150 + temp_var_for_tac_152;
    computeDMul((Addr)&temp_var_for_tac_146,
                {(Addr) &(temp_var_for_const_120 = (-(2))),
                 (Addr) &(temp_var_for_const_119 = Beta[0]),
                 (Addr) &(temp_var_for_const_121 = C[0]),
                 (Addr) &(temp_var_for_const_122 = C[0])},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:154:38");
    computeDSub((Addr)&temp_var_for_tac_147,{(Addr)&temp_var_for_tac_146, (Addr)&sumbeta},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:154:48");
    computeDAdd((Addr)&temp_var_for_tac_148,{(Addr)&temp_var_for_tac_147, (Addr)&sumalpha},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:154:70");
    computeDMul((Addr)&temp_var_for_tac_149,{(Addr) &(temp_var_for_const_124 = Alpha[1]),
                 (Addr) &(temp_var_for_const_123 = C[1])},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:154:59");
    computeDAdd((Addr)&temp_var_for_tac_150,{(Addr)&temp_var_for_tac_148, (Addr)&temp_var_for_tac_149},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:154:84");
    computeDAdd((Addr)&temp_var_for_tac_151,{(Addr) &(temp_var_for_const_125 = 1.0), (Addr)&k},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:154:89");
    computeDMul((Addr)&temp_var_for_tac_152,
        {(Addr)&temp_var_for_tac_151, (Addr) &(temp_var_for_const_126 = C[0])},
        "/home/shijia/Public/testprogram/ETD_S.c_e.c:154:77");
    computeDAdd((Addr)&Fc[0],
                {(Addr)&temp_var_for_tac_150, (Addr)&temp_var_for_tac_152},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:154:9");
    ;
    for (i = 1; i <= N - 2; i++) {
      double temp_var_for_const_127, temp_var_for_const_128,
          temp_var_for_const_129, temp_var_for_const_130,
          temp_var_for_const_131, temp_var_for_const_132,
          temp_var_for_const_133, temp_var_for_const_134,
          temp_var_for_const_135;
      double temp_var_for_tac_153 = Beta[i - 1] * C[i - 1] * C[0];
      double temp_var_for_tac_154 = Beta[i] * C[i] * C[0];
      double temp_var_for_tac_155 = temp_var_for_tac_153 - temp_var_for_tac_154;
      double temp_var_for_tac_156 = Alpha[i + 1] * C[i + 1];
      double temp_var_for_tac_157 = temp_var_for_tac_155 + temp_var_for_tac_156;
      double temp_var_for_tac_158 = k * C[i];
      Fc[i] = temp_var_for_tac_157 + temp_var_for_tac_158;
      computeDMul((Addr)&temp_var_for_tac_153,
                  {(Addr) &(temp_var_for_const_128 = Beta[i - 1]),
                   (Addr) &(temp_var_for_const_127 = C[i - 1]),
                   (Addr) &(temp_var_for_const_129 = C[0])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:157:52");
      computeDMul((Addr)&temp_var_for_tac_154,
                  {(Addr) &(temp_var_for_const_131 = Beta[i]),
                   (Addr) &(temp_var_for_const_130 = C[i]),
                   (Addr) &(temp_var_for_const_132 = C[0])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:157:42");
      computeDSub((Addr)&temp_var_for_tac_155,
                  {(Addr)&temp_var_for_tac_153, (Addr)&temp_var_for_tac_154},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:157:81");
      computeDMul((Addr)&temp_var_for_tac_156,
                  {(Addr) &(temp_var_for_const_134 = Alpha[i + 1]),
                   (Addr) &(temp_var_for_const_133 = C[i + 1])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:157:66");
      computeDAdd((Addr)&temp_var_for_tac_157,
                  {(Addr)&temp_var_for_tac_155, (Addr)&temp_var_for_tac_156},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:157:96");
      computeDMul((Addr)&temp_var_for_tac_158,
                  {(Addr)&k, (Addr) &(temp_var_for_const_135 = C[i])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:157:92");
      computeDAdd((Addr)&Fc[i],
                  {(Addr)&temp_var_for_tac_157, (Addr)&temp_var_for_tac_158},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:157:10");
      ;
    }
    double temp_var_for_const_136;
    Fc[N - 1] = 0.0;
    AssignD({(Addr)&Fc[N - 1]}, (Addr) &(temp_var_for_const_136 = 0.0),
            "/home/shijia/Public/testprogram/ETD_S.c_e.c:159:13");
    ;
    double temp_var_for_const_137, temp_var_for_const_138,
        temp_var_for_const_139, temp_var_for_const_140, temp_var_for_const_141,
        temp_var_for_const_142, temp_var_for_const_143;
    double temp_var_for_tac_159 = Beta[N - 2] * C[N - 2] * C[0];
    double temp_var_for_tac_160 = Beta[N - 1] * C[N - 1] * C[0];
    double temp_var_for_tac_161 = temp_var_for_tac_159 - temp_var_for_tac_160;
    double temp_var_for_tac_162 = k * C[N - 1];
    Fc[N - 1] = temp_var_for_tac_161 + temp_var_for_tac_162;
    computeDMul((Addr)&temp_var_for_tac_159,
                {(Addr) &(temp_var_for_const_138 = Beta[N - 2]),
                 (Addr) &(temp_var_for_const_137 = C[N - 2]),
                 (Addr) &(temp_var_for_const_139 = C[0])},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:160:59");
    computeDMul((Addr)&temp_var_for_tac_160,
                {(Addr) &(temp_var_for_const_141 = Beta[N - 1]),
                 (Addr) &(temp_var_for_const_140 = C[N - 1]),
                 (Addr) &(temp_var_for_const_142 = C[0])},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:160:45");
    computeDSub((Addr)&temp_var_for_tac_161,
                {(Addr)&temp_var_for_tac_159, (Addr)&temp_var_for_tac_160},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:160:81");
    computeDMul((Addr)&temp_var_for_tac_162,
                {(Addr)&k, (Addr) &(temp_var_for_const_143 = C[N - 1])},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:160:77");
    computeDAdd((Addr)&Fc[N - 1],
                {(Addr)&temp_var_for_tac_161, (Addr)&temp_var_for_tac_162},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:160:13");
    ;
    /*
    for(i=0;i<N;i++){
            printf("Fc[%d]=%e\n",i,Fc[i]);
    }*/

    for (i = 0; i < N; i++) {
      double temp_var_for_const_144;
      a[i] = 0.0;
      AssignD({(Addr)&a[i]}, (Addr) &(temp_var_for_const_144 = 0.0),
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:168:9");
      ;
      double temp_var_for_const_145, temp_var_for_const_146,
          temp_var_for_const_147, temp_var_for_const_148;
      double temp_var_for_tac_163 = phi1[i] * C[i];
      double temp_var_for_tac_164 = phi2[i] * Fc[i];
      a[i] = temp_var_for_tac_163 + temp_var_for_tac_164;
      computeDMul((Addr)&temp_var_for_tac_163,
                  {(Addr) &(temp_var_for_const_146 = phi1[i]),
                   (Addr) &(temp_var_for_const_145 = C[i])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:169:35");
      computeDMul((Addr)&temp_var_for_tac_164,
                  {(Addr) &(temp_var_for_const_148 = phi2[i]),
                   (Addr) &(temp_var_for_const_147 = Fc[i])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:169:25");
      computeDAdd((Addr)&a[i],
                  {(Addr)&temp_var_for_tac_163, (Addr)&temp_var_for_tac_164},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:169:8");
      ;
      int temp_var_for_ext_3;
      temp_var_for_ext_3 = i == 0;
      if (temp_var_for_ext_3) {
        double temp_var_for_const_149;
        alpha_a[i] = 0.0;
        AssignD({(Addr)&alpha_a[i]}, (Addr) &(temp_var_for_const_149 = 0.0),
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:174:16");
        ;
        double temp_var_for_const_150;
        beta_a[i] = 0.0;
        AssignD({(Addr)&beta_a[i]}, (Addr) &(temp_var_for_const_150 = 0.0),
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:175:15");
        ;
      } else {
        double temp_var_for_const_151, temp_var_for_const_152;
        alpha_a[i] = Alpha[i] * a[i];
        computeDMul((Addr)&alpha_a[i],
                    {(Addr) &(temp_var_for_const_152 = Alpha[i]),
                     (Addr) &(temp_var_for_const_151 = a[i])},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:179:16");
        ;
        double temp_var_for_const_153, temp_var_for_const_154,
            temp_var_for_const_155;
        beta_a[i] = Beta[i] * a[i] * a[0];
        computeDMul((Addr)&beta_a[i],
                    {(Addr) &(temp_var_for_const_154 = Beta[i]),
                     (Addr) &(temp_var_for_const_153 = a[i]),
                     (Addr) &(temp_var_for_const_155 = a[0])},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:180:15");
        ;
      }
      sumalpha_a += alpha_a[i];
      ;
      sumbeta_a += beta_a[i];
      ;
    }
    double temp_var_for_const_156, temp_var_for_const_157,
        temp_var_for_const_158, temp_var_for_const_159, temp_var_for_const_160,
        temp_var_for_const_161, temp_var_for_const_162, temp_var_for_const_163;
    double temp_var_for_tac_165 = (-(2)) * Beta[0] * a[0] * a[0];
    double temp_var_for_tac_166 = temp_var_for_tac_165 - sumbeta_a;
    double temp_var_for_tac_167 = temp_var_for_tac_166 + sumalpha_a;
    double temp_var_for_tac_168 = Alpha[1] * a[1];
    double temp_var_for_tac_169 = temp_var_for_tac_167 + temp_var_for_tac_168;
    double temp_var_for_tac_170 = 1.0 + k;
    double temp_var_for_tac_171 = temp_var_for_tac_170 * a[0];
    Fa[0] = temp_var_for_tac_169 + temp_var_for_tac_171;
    computeDMul((Addr)&temp_var_for_tac_165,
                {(Addr) &(temp_var_for_const_157 = (-(2))),
                 (Addr) &(temp_var_for_const_156 = Beta[0]),
                 (Addr) &(temp_var_for_const_158 = a[0]),
                 (Addr) &(temp_var_for_const_159 = a[0])},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:185:38");
    computeDSub((Addr)&temp_var_for_tac_166,
                {(Addr)&temp_var_for_tac_165, (Addr)&sumbeta_a},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:185:50");
    computeDAdd((Addr)&temp_var_for_tac_167,
                {(Addr)&temp_var_for_tac_166, (Addr)&sumalpha_a},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:185:74");
    computeDMul((Addr)&temp_var_for_tac_168,
                {(Addr) &(temp_var_for_const_161 = Alpha[1]),
                 (Addr) &(temp_var_for_const_160 = a[1])},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:185:63");
    computeDAdd((Addr)&temp_var_for_tac_169,
                {(Addr)&temp_var_for_tac_167, (Addr)&temp_var_for_tac_168},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:185:88");
    computeDAdd((Addr)&temp_var_for_tac_170,
                {(Addr) &(temp_var_for_const_162 = 1.0), (Addr)&k},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:185:93");
    computeDMul(
        (Addr)&temp_var_for_tac_171,
        {(Addr)&temp_var_for_tac_170, (Addr) &(temp_var_for_const_163 = a[0])},
        "/home/shijia/Public/testprogram/ETD_S.c_e.c:185:81");
    computeDAdd((Addr)&Fa[0],
                {(Addr)&temp_var_for_tac_169, (Addr)&temp_var_for_tac_171},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:185:9");
    ;
    for (i = 1; i <= N - 2; i++) {
      double temp_var_for_const_164, temp_var_for_const_165,
          temp_var_for_const_166, temp_var_for_const_167,
          temp_var_for_const_168, temp_var_for_const_169,
          temp_var_for_const_170, temp_var_for_const_171,
          temp_var_for_const_172;
      double temp_var_for_tac_172 = Beta[i - 1] * a[i - 1] * a[0];
      double temp_var_for_tac_173 = Beta[i] * a[i] * a[0];
      double temp_var_for_tac_174 = temp_var_for_tac_172 - temp_var_for_tac_173;
      double temp_var_for_tac_175 = Alpha[i + 1] * a[i + 1];
      double temp_var_for_tac_176 = temp_var_for_tac_174 + temp_var_for_tac_175;
      double temp_var_for_tac_177 = k * a[i];
      Fa[i] = temp_var_for_tac_176 + temp_var_for_tac_177;
      computeDMul((Addr)&temp_var_for_tac_172,
                  {(Addr) &(temp_var_for_const_165 = Beta[i - 1]),
                   (Addr) &(temp_var_for_const_164 = a[i - 1]),
                   (Addr) &(temp_var_for_const_166 = a[0])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:188:52");
      computeDMul((Addr)&temp_var_for_tac_173,
                  {(Addr) &(temp_var_for_const_168 = Beta[i]),
                   (Addr) &(temp_var_for_const_167 = a[i]),
                   (Addr) &(temp_var_for_const_169 = a[0])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:188:42");
      computeDSub((Addr)&temp_var_for_tac_174,
                  {(Addr)&temp_var_for_tac_172, (Addr)&temp_var_for_tac_173},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:188:81");
      computeDMul((Addr)&temp_var_for_tac_175,
                  {(Addr) &(temp_var_for_const_171 = Alpha[i + 1]),
                   (Addr) &(temp_var_for_const_170 = a[i + 1])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:188:66");
      computeDAdd((Addr)&temp_var_for_tac_176,
                  {(Addr)&temp_var_for_tac_174, (Addr)&temp_var_for_tac_175},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:188:96");
      computeDMul((Addr)&temp_var_for_tac_177,
                  {(Addr)&k, (Addr) &(temp_var_for_const_172 = a[i])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:188:92");
      computeDAdd((Addr)&Fa[i],
                  {(Addr)&temp_var_for_tac_176, (Addr)&temp_var_for_tac_177},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:188:10");
      ;
    }
    double temp_var_for_const_173, temp_var_for_const_174,
        temp_var_for_const_175, temp_var_for_const_176, temp_var_for_const_177,
        temp_var_for_const_178, temp_var_for_const_179;
    double temp_var_for_tac_178 = Beta[N - 2] * a[N - 2] * a[0];
    double temp_var_for_tac_179 = Beta[N - 1] * a[N - 1] * a[0];
    double temp_var_for_tac_180 = temp_var_for_tac_178 - temp_var_for_tac_179;
    double temp_var_for_tac_181 = k * a[N - 1];
    Fa[N - 1] = temp_var_for_tac_180 + temp_var_for_tac_181;
    computeDMul((Addr)&temp_var_for_tac_178,
                {(Addr) &(temp_var_for_const_174 = Beta[N - 2]),
                 (Addr) &(temp_var_for_const_173 = a[N - 2]),
                 (Addr) &(temp_var_for_const_175 = a[0])},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:190:59");
    computeDMul((Addr)&temp_var_for_tac_179,
                {(Addr) &(temp_var_for_const_177 = Beta[N - 1]),
                 (Addr) &(temp_var_for_const_176 = a[N - 1]),
                 (Addr) &(temp_var_for_const_178 = a[0])},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:190:45");
    computeDSub((Addr)&temp_var_for_tac_180,
                {(Addr)&temp_var_for_tac_178, (Addr)&temp_var_for_tac_179},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:190:81");
    computeDMul((Addr)&temp_var_for_tac_181,
                {(Addr)&k, (Addr) &(temp_var_for_const_179 = a[N - 1])},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:190:77");
    computeDAdd((Addr)&Fa[N - 1],
                {(Addr)&temp_var_for_tac_180, (Addr)&temp_var_for_tac_181},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:190:13");
    ;
    /*for(i=0;i<N;i++){
            printf("Fa[%d]=%e\n",i,Fa[i]);
    }*/

    for (i = 0; i < N; i++) {
      double temp_var_for_const_180, temp_var_for_const_181,
          temp_var_for_const_182, temp_var_for_const_183;
      double temp_var_for_tac_182 = phi1[i] * C[i];
      double temp_var_for_tac_183 = phi2[i] * Fa[i];
      b[i] = temp_var_for_tac_182 + temp_var_for_tac_183;
      computeDMul((Addr)&temp_var_for_tac_182,
                  {(Addr) &(temp_var_for_const_181 = phi1[i]),
                   (Addr) &(temp_var_for_const_180 = C[i])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:197:36");
      computeDMul((Addr)&temp_var_for_tac_183,
                  {(Addr) &(temp_var_for_const_183 = phi2[i]),
                   (Addr) &(temp_var_for_const_182 = Fa[i])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:197:26");
      computeDAdd((Addr)&b[i],
                  {(Addr)&temp_var_for_tac_182, (Addr)&temp_var_for_tac_183},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:197:9");
      ;
      int temp_var_for_ext_4;
      temp_var_for_ext_4 = i == 0;
      if (temp_var_for_ext_4) {
        double temp_var_for_const_184;
        alpha_b[i] = 0.0;
        AssignD({(Addr)&alpha_b[i]}, (Addr) &(temp_var_for_const_184 = 0.0),
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:202:16");
        ;
        double temp_var_for_const_185;
        beta_b[i] = 0.0;
        AssignD({(Addr)&beta_b[i]}, (Addr) &(temp_var_for_const_185 = 0.0),
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:203:15");
        ;
      } else {
        double temp_var_for_const_186, temp_var_for_const_187;
        alpha_b[i] = Alpha[i] * b[i];
        computeDMul((Addr)&alpha_b[i],
                    {(Addr) &(temp_var_for_const_187 = Alpha[i]),
                     (Addr) &(temp_var_for_const_186 = b[i])},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:207:16");
        ;
        double temp_var_for_const_188, temp_var_for_const_189,
            temp_var_for_const_190;
        beta_b[i] = Beta[i] * b[i] * b[0];
        computeDMul((Addr)&beta_b[i],
                    {(Addr) &(temp_var_for_const_189 = Beta[i]),
                     (Addr) &(temp_var_for_const_188 = b[i]),
                     (Addr) &(temp_var_for_const_190 = b[0])},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:208:15");
        ;
      }
      sumalpha_b += alpha_b[i];
      ;
      sumbeta_b += beta_b[i];
      ;
    }
    double temp_var_for_const_191, temp_var_for_const_192,
        temp_var_for_const_193, temp_var_for_const_194, temp_var_for_const_195,
        temp_var_for_const_196, temp_var_for_const_197, temp_var_for_const_198;
    double temp_var_for_tac_184 = (-(2)) * Beta[0] * b[0] * b[0];
    double temp_var_for_tac_185 = temp_var_for_tac_184 - sumbeta_b;
    double temp_var_for_tac_186 = temp_var_for_tac_185 + sumalpha_b;
    double temp_var_for_tac_187 = Alpha[1] * b[1];
    double temp_var_for_tac_188 = temp_var_for_tac_186 + temp_var_for_tac_187;
    double temp_var_for_tac_189 = 1.0 + k;
    double temp_var_for_tac_190 = temp_var_for_tac_189 * b[0];
    Fb[0] = temp_var_for_tac_188 + temp_var_for_tac_190;
    computeDMul((Addr)&temp_var_for_tac_184,
                {(Addr) &(temp_var_for_const_192 = (-(2))),
                 (Addr) &(temp_var_for_const_191 = Beta[0]),
                 (Addr) &(temp_var_for_const_193 = b[0]),
                 (Addr) &(temp_var_for_const_194 = b[0])},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:213:38");
    computeDSub((Addr)&temp_var_for_tac_185,
                {(Addr)&temp_var_for_tac_184, (Addr)&sumbeta_b},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:213:50");
    computeDAdd((Addr)&temp_var_for_tac_186,
                {(Addr)&temp_var_for_tac_185, (Addr)&sumalpha_b},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:213:74");
    computeDMul((Addr)&temp_var_for_tac_187,
                {(Addr) &(temp_var_for_const_196 = Alpha[1]),
                 (Addr) &(temp_var_for_const_195 = b[1])},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:213:63");
    computeDAdd((Addr)&temp_var_for_tac_188,
                {(Addr)&temp_var_for_tac_186, (Addr)&temp_var_for_tac_187},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:213:88");
    computeDAdd((Addr)&temp_var_for_tac_189,
                {(Addr) &(temp_var_for_const_197 = 1.0), (Addr)&k},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:213:93");
    computeDMul(
        (Addr)&temp_var_for_tac_190,
        {(Addr)&temp_var_for_tac_189, (Addr) &(temp_var_for_const_198 = b[0])},
        "/home/shijia/Public/testprogram/ETD_S.c_e.c:213:81");
    computeDAdd((Addr)&Fb[0],
                {(Addr)&temp_var_for_tac_188, (Addr)&temp_var_for_tac_190},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:213:9");
    ;
    for (i = 1; i <= N - 2; i++) {
      double temp_var_for_const_199, temp_var_for_const_200,
          temp_var_for_const_201, temp_var_for_const_202,
          temp_var_for_const_203, temp_var_for_const_204,
          temp_var_for_const_205, temp_var_for_const_206,
          temp_var_for_const_207;
      double temp_var_for_tac_191 = Beta[i - 1] * b[i - 1] * b[0];
      double temp_var_for_tac_192 = Beta[i] * b[i] * b[0];
      double temp_var_for_tac_193 = temp_var_for_tac_191 - temp_var_for_tac_192;
      double temp_var_for_tac_194 = Alpha[i + 1] * b[i + 1];
      double temp_var_for_tac_195 = temp_var_for_tac_193 + temp_var_for_tac_194;
      double temp_var_for_tac_196 = k * b[i];
      Fb[i] = temp_var_for_tac_195 + temp_var_for_tac_196;
      computeDMul((Addr)&temp_var_for_tac_191,
                  {(Addr) &(temp_var_for_const_200 = Beta[i - 1]),
                   (Addr) &(temp_var_for_const_199 = b[i - 1]),
                   (Addr) &(temp_var_for_const_201 = b[0])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:216:52");
      computeDMul((Addr)&temp_var_for_tac_192,
                  {(Addr) &(temp_var_for_const_203 = Beta[i]),
                   (Addr) &(temp_var_for_const_202 = b[i]),
                   (Addr) &(temp_var_for_const_204 = b[0])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:216:42");
      computeDSub((Addr)&temp_var_for_tac_193,
                  {(Addr)&temp_var_for_tac_191, (Addr)&temp_var_for_tac_192},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:216:81");
      computeDMul((Addr)&temp_var_for_tac_194,
                  {(Addr) &(temp_var_for_const_206 = Alpha[i + 1]),
                   (Addr) &(temp_var_for_const_205 = b[i + 1])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:216:66");
      computeDAdd((Addr)&temp_var_for_tac_195,
                  {(Addr)&temp_var_for_tac_193, (Addr)&temp_var_for_tac_194},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:216:96");
      computeDMul((Addr)&temp_var_for_tac_196,
                  {(Addr)&k, (Addr) &(temp_var_for_const_207 = b[i])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:216:92");
      computeDAdd((Addr)&Fb[i],
                  {(Addr)&temp_var_for_tac_195, (Addr)&temp_var_for_tac_196},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:216:10");
      ;
    }
    double temp_var_for_const_208, temp_var_for_const_209,
        temp_var_for_const_210, temp_var_for_const_211, temp_var_for_const_212,
        temp_var_for_const_213, temp_var_for_const_214;
    double temp_var_for_tac_197 = Beta[N - 2] * b[N - 2] * b[0];
    double temp_var_for_tac_198 = Beta[N - 1] * b[N - 1] * b[0];
    double temp_var_for_tac_199 = temp_var_for_tac_197 - temp_var_for_tac_198;
    double temp_var_for_tac_200 = k * b[N - 1];
    Fb[N - 1] = temp_var_for_tac_199 + temp_var_for_tac_200;
    computeDMul((Addr)&temp_var_for_tac_197,
                {(Addr) &(temp_var_for_const_209 = Beta[N - 2]),
                 (Addr) &(temp_var_for_const_208 = b[N - 2]),
                 (Addr) &(temp_var_for_const_210 = b[0])},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:218:59");
    computeDMul((Addr)&temp_var_for_tac_198,
                {(Addr) &(temp_var_for_const_212 = Beta[N - 1]),
                 (Addr) &(temp_var_for_const_211 = b[N - 1]),
                 (Addr) &(temp_var_for_const_213 = b[0])},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:218:45");
    computeDSub((Addr)&temp_var_for_tac_199,
                {(Addr)&temp_var_for_tac_197, (Addr)&temp_var_for_tac_198},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:218:81");
    computeDMul((Addr)&temp_var_for_tac_200,
                {(Addr)&k, (Addr) &(temp_var_for_const_214 = b[N - 1])},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:218:77");
    computeDAdd((Addr)&Fb[N - 1],
                {(Addr)&temp_var_for_tac_199, (Addr)&temp_var_for_tac_200},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:218:13");
    ;
    /*for(i=0;i<N;i++){
            printf("Fb[%d]=%e\n",i,Fb[i]);
    }*/

    for (i = 0; i < N; i++) {
      double temp_var_for_const_215, temp_var_for_const_216,
          temp_var_for_const_217, temp_var_for_const_218,
          temp_var_for_const_219, temp_var_for_const_220;
      double temp_var_for_tac_201 = phi1[i] * a[i];
      double temp_var_for_tac_202 = 2 * Fb[i];
      double temp_var_for_tac_203 = temp_var_for_tac_202 - Fc[i];
      double temp_var_for_tac_204 = phi2[i] * temp_var_for_tac_203;
      d[i] = temp_var_for_tac_201 + temp_var_for_tac_204;
      computeDMul((Addr)&temp_var_for_tac_201,
                  {(Addr) &(temp_var_for_const_216 = phi1[i]),
                   (Addr) &(temp_var_for_const_215 = a[i])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:225:41");
      computeDMul((Addr)&temp_var_for_tac_202,
                  {(Addr) &(temp_var_for_const_218 = 2),
                   (Addr) &(temp_var_for_const_217 = Fb[i])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:225:49");
      computeDSub((Addr)&temp_var_for_tac_203,
                  {(Addr)&temp_var_for_tac_202,
                   (Addr) &(temp_var_for_const_219 = Fc[i])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:225:36");
      computeDMul((Addr)&temp_var_for_tac_204,
                  {(Addr) &(temp_var_for_const_220 = phi2[i]),
                   (Addr)&temp_var_for_tac_203},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:225:26");
      computeDAdd((Addr)&d[i],
                  {(Addr)&temp_var_for_tac_201, (Addr)&temp_var_for_tac_204},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:225:9");
      ;
      int temp_var_for_ext_5;
      temp_var_for_ext_5 = i == 0;
      if (temp_var_for_ext_5) {
        double temp_var_for_const_221;
        alpha_d[i] = 0.0;
        AssignD({(Addr)&alpha_d[i]}, (Addr) &(temp_var_for_const_221 = 0.0),
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:230:16");
        ;
        double temp_var_for_const_222;
        beta_d[i] = 0.0;
        AssignD({(Addr)&beta_d[i]}, (Addr) &(temp_var_for_const_222 = 0.0),
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:231:15");
        ;
      } else {
        double temp_var_for_const_223, temp_var_for_const_224;
        alpha_d[i] = Alpha[i] * d[i];
        computeDMul((Addr)&alpha_d[i],
                    {(Addr) &(temp_var_for_const_224 = Alpha[i]),
                     (Addr) &(temp_var_for_const_223 = d[i])},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:235:16");
        ;
        double temp_var_for_const_225, temp_var_for_const_226,
            temp_var_for_const_227;
        beta_d[i] = Beta[i] * d[i] * d[0];
        computeDMul((Addr)&beta_d[i],
                    {(Addr) &(temp_var_for_const_226 = Beta[i]),
                     (Addr) &(temp_var_for_const_225 = d[i]),
                     (Addr) &(temp_var_for_const_227 = d[0])},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:236:15");
        ;
      }
      sumalpha_d += alpha_d[i];
      ;
      sumbeta_d += beta_d[i];
      ;
    }
    double temp_var_for_const_228, temp_var_for_const_229,
        temp_var_for_const_230, temp_var_for_const_231, temp_var_for_const_232,
        temp_var_for_const_233, temp_var_for_const_234, temp_var_for_const_235;
    double temp_var_for_tac_205 = (-(2)) * Beta[0] * d[0] * d[0];
    double temp_var_for_tac_206 = temp_var_for_tac_205 - sumbeta_d;
    double temp_var_for_tac_207 = temp_var_for_tac_206 + sumalpha_d;
    double temp_var_for_tac_208 = Alpha[1] * d[1];
    double temp_var_for_tac_209 = temp_var_for_tac_207 + temp_var_for_tac_208;
    double temp_var_for_tac_210 = 1.0 + k;
    double temp_var_for_tac_211 = temp_var_for_tac_210 * d[0];
    Fd[0] = temp_var_for_tac_209 + temp_var_for_tac_211;
    computeDMul((Addr)&temp_var_for_tac_205,
                {(Addr) &(temp_var_for_const_229 = (-(2))),
                 (Addr) &(temp_var_for_const_228 = Beta[0]),
                 (Addr) &(temp_var_for_const_230 = d[0]),
                 (Addr) &(temp_var_for_const_231 = d[0])},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:241:38");
    computeDSub((Addr)&temp_var_for_tac_206,
                {(Addr)&temp_var_for_tac_205, (Addr)&sumbeta_d},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:241:50");
    computeDAdd((Addr)&temp_var_for_tac_207,
                {(Addr)&temp_var_for_tac_206, (Addr)&sumalpha_d},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:241:74");
    computeDMul((Addr)&temp_var_for_tac_208,
                {(Addr) &(temp_var_for_const_233 = Alpha[1]),
                 (Addr) &(temp_var_for_const_232 = d[1])},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:241:63");
    computeDAdd((Addr)&temp_var_for_tac_209,
                {(Addr)&temp_var_for_tac_207, (Addr)&temp_var_for_tac_208},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:241:88");
    computeDAdd((Addr)&temp_var_for_tac_210,
                {(Addr) &(temp_var_for_const_234 = 1.0), (Addr)&k},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:241:93");
    computeDMul(
        (Addr)&temp_var_for_tac_211,
        {(Addr)&temp_var_for_tac_210, (Addr) &(temp_var_for_const_235 = d[0])},
        "/home/shijia/Public/testprogram/ETD_S.c_e.c:241:81");
    computeDAdd((Addr)&Fd[0],
                {(Addr)&temp_var_for_tac_209, (Addr)&temp_var_for_tac_211},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:241:9");
    ;
    for (i = 1; i <= N - 2; i++) {
      double temp_var_for_const_236, temp_var_for_const_237,
          temp_var_for_const_238, temp_var_for_const_239,
          temp_var_for_const_240, temp_var_for_const_241,
          temp_var_for_const_242, temp_var_for_const_243,
          temp_var_for_const_244;
      double temp_var_for_tac_212 = Beta[i - 1] * d[i - 1] * d[0];
      double temp_var_for_tac_213 = Beta[i] * d[i] * d[0];
      double temp_var_for_tac_214 = temp_var_for_tac_212 - temp_var_for_tac_213;
      double temp_var_for_tac_215 = Alpha[i + 1] * d[i + 1];
      double temp_var_for_tac_216 = temp_var_for_tac_214 + temp_var_for_tac_215;
      double temp_var_for_tac_217 = k * d[i];
      Fd[i] = temp_var_for_tac_216 + temp_var_for_tac_217;
      computeDMul((Addr)&temp_var_for_tac_212,
                  {(Addr) &(temp_var_for_const_237 = Beta[i - 1]),
                   (Addr) &(temp_var_for_const_236 = d[i - 1]),
                   (Addr) &(temp_var_for_const_238 = d[0])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:244:52");
      computeDMul((Addr)&temp_var_for_tac_213,
                  {(Addr) &(temp_var_for_const_240 = Beta[i]),
                   (Addr) &(temp_var_for_const_239 = d[i]),
                   (Addr) &(temp_var_for_const_241 = d[0])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:244:42");
      computeDSub((Addr)&temp_var_for_tac_214,
                  {(Addr)&temp_var_for_tac_212, (Addr)&temp_var_for_tac_213},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:244:81");
      computeDMul((Addr)&temp_var_for_tac_215,
                  {(Addr) &(temp_var_for_const_243 = Alpha[i + 1]),
                   (Addr) &(temp_var_for_const_242 = d[i + 1])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:244:66");
      computeDAdd((Addr)&temp_var_for_tac_216,
                  {(Addr)&temp_var_for_tac_214, (Addr)&temp_var_for_tac_215},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:244:96");
      computeDMul((Addr)&temp_var_for_tac_217,
                  {(Addr)&k, (Addr) &(temp_var_for_const_244 = d[i])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:244:92");
      computeDAdd((Addr)&Fd[i],
                  {(Addr)&temp_var_for_tac_216, (Addr)&temp_var_for_tac_217},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:244:10");
      ;
    }
    double temp_var_for_const_245, temp_var_for_const_246,
        temp_var_for_const_247, temp_var_for_const_248, temp_var_for_const_249,
        temp_var_for_const_250, temp_var_for_const_251;
    double temp_var_for_tac_218 = Beta[N - 2] * d[N - 2] * d[0];
    double temp_var_for_tac_219 = Beta[N - 1] * d[N - 1] * d[0];
    double temp_var_for_tac_220 = temp_var_for_tac_218 - temp_var_for_tac_219;
    double temp_var_for_tac_221 = k * d[N - 1];
    Fd[N - 1] = temp_var_for_tac_220 + temp_var_for_tac_221;
    computeDMul((Addr)&temp_var_for_tac_218,
                {(Addr) &(temp_var_for_const_246 = Beta[N - 2]),
                 (Addr) &(temp_var_for_const_245 = d[N - 2]),
                 (Addr) &(temp_var_for_const_247 = d[0])},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:246:59");
    computeDMul((Addr)&temp_var_for_tac_219,
                {(Addr) &(temp_var_for_const_249 = Beta[N - 1]),
                 (Addr) &(temp_var_for_const_248 = d[N - 1]),
                 (Addr) &(temp_var_for_const_250 = d[0])},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:246:45");
    computeDSub((Addr)&temp_var_for_tac_220,
                {(Addr)&temp_var_for_tac_218, (Addr)&temp_var_for_tac_219},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:246:81");
    computeDMul((Addr)&temp_var_for_tac_221,
                {(Addr)&k, (Addr) &(temp_var_for_const_251 = d[N - 1])},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:246:77");
    computeDAdd((Addr)&Fd[N - 1],
                {(Addr)&temp_var_for_tac_220, (Addr)&temp_var_for_tac_221},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:246:13");
    ;
    /*for(i=0;i<N;i++){
            printf("Fd[%d]=%e\n",i,Fd[i]);
    }*/

    for (i = 0; i < N; i++) {
      double temp_var_for_ext_6;
      double temp_var_for_const_252, temp_var_for_const_253,
          temp_var_for_const_254, temp_var_for_const_255,
          temp_var_for_const_256, temp_var_for_const_257,
          temp_var_for_const_258, temp_var_for_const_259,
          temp_var_for_const_260, temp_var_for_const_261;
      double temp_var_for_tac_222 = phi3[i] * C[i];
      double temp_var_for_callexp_20;
      temp_var_for_callexp_20 = pow(dt, (-(2)));
      CallStackPop((Addr)&temp_var_for_callexp_20,
                   getTop(temp_var_for_callexp_20));

      double temp_var_for_tac_223 = temp_var_for_callexp_20 * L3[i];
      double temp_var_for_tac_224 = poly1[i] * Fc[i];
      double temp_var_for_tac_225 = Fa[i] + Fb[i];
      double temp_var_for_tac_226 = poly2[i] * temp_var_for_tac_225;
      double temp_var_for_tac_227 = temp_var_for_tac_224 + temp_var_for_tac_226;
      double temp_var_for_tac_228 = poly3[i] * Fd[i];
      double temp_var_for_tac_229 = temp_var_for_tac_227 + temp_var_for_tac_228;
      double temp_var_for_tac_230 = temp_var_for_tac_223 * temp_var_for_tac_229;
      temp_var_for_ext_6 = temp_var_for_tac_222 + temp_var_for_tac_230;
      computeDMul((Addr)&temp_var_for_tac_222,
                  {(Addr) &(temp_var_for_const_253 = phi3[i]),
                   (Addr) &(temp_var_for_const_252 = C[i])},
                  "toString(biExpr->getExprLoc())");
      computeDMul((Addr)&temp_var_for_tac_223,
                  {(Addr)&temp_var_for_callexp_20,
                   (Addr) &(temp_var_for_const_254 = L3[i])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:253:103");
      computeDMul((Addr)&temp_var_for_tac_224,
                  {(Addr) &(temp_var_for_const_256 = poly1[i]),
                   (Addr) &(temp_var_for_const_255 = Fc[i])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:253:131");
      computeDAdd((Addr)&temp_var_for_tac_225,
                  {(Addr) &(temp_var_for_const_258 = Fa[i]),
                   (Addr) &(temp_var_for_const_257 = Fb[i])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:253:122");
      computeDMul((Addr)&temp_var_for_tac_226,
                  {(Addr) &(temp_var_for_const_259 = poly2[i]),
                   (Addr)&temp_var_for_tac_225},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:253:111");
      computeDAdd((Addr)&temp_var_for_tac_227,
                  {(Addr)&temp_var_for_tac_224, (Addr)&temp_var_for_tac_226},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:253:151");
      computeDMul((Addr)&temp_var_for_tac_228,
                  {(Addr) &(temp_var_for_const_261 = poly3[i]),
                   (Addr) &(temp_var_for_const_260 = Fd[i])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:253:140");
      computeDAdd((Addr)&temp_var_for_tac_229,
                  {(Addr)&temp_var_for_tac_227, (Addr)&temp_var_for_tac_228},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:253:91");
      computeDMul((Addr)&temp_var_for_tac_230,
                  {(Addr)&temp_var_for_tac_223, (Addr)&temp_var_for_tac_229},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:253:67");
      computeDAdd((Addr)&temp_var_for_ext_6,
                  {(Addr)&temp_var_for_tac_222, (Addr)&temp_var_for_tac_230},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:253:50");
      ; // C[i]
      /*(d)(1)(N)(d[TempNull])(k)(d)(0)(d[0])(d)(1)(N)(d[TempNull])(Beta)(1)(N)(Beta[TempNull])(d)(0)(d[0])(d)(2)(N)(d[TempNull])(Beta)(2)(N)(Beta[TempNull])(d)(0)(d[0])(d)(1)(N)(d[TempNull])(Beta)(1)(N)(Beta[TempNull])(d)(0)(d[0])(d)(2)(N)(d[TempNull])(Beta)(2)(N)(Beta[TempNull])(d)(0)(d[0])(d)(2)(N)(d[TempNull])(Beta)(2)(N)(Beta[TempNull])(d)(2)(N)(d[TempNull])(Beta)(2)(N)(Beta[TempNull])(d)(0)(d[0])(d)(1)(N)(d[TempNull])(Beta)(1)(N)(Beta[TempNull])(d)(1)(N)(d[TempNull])(Beta)(1)(N)(Beta[TempNull])(d)(1)(N)(d[TempNull])(k)(Fd)(i)(Fd[i])(poly3)(i)(poly3[i])(Fb)(i)(Fb[i])(Fa)(i)(Fa[i])(poly2)(i)(poly2[i])(Fc)(i)(Fc[i])(poly1)(i)(poly1[i])(L3)(i)(L3[i])(pow(
       * dt,  -2))(C)(i)(C[i])(phi3)(i)(phi3[i])*/
      C[i] = temp_var_for_ext_6;
      AssignD({(Addr)&C[i]}, (Addr)&temp_var_for_ext_6,
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:255:6");
      ;
    }
    double temp_var_for_ext_7;
    temp_var_for_ext_7 = t + dt;
    computeDAdd((Addr)&temp_var_for_ext_7, {(Addr)&t, (Addr)&dt},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:257:49");
    ; // t
    /*(Fd)(i)(Fd[i])(poly3)(i)(poly3[i])(Fb)(i)(Fb[i])(Fa)(i)(Fa[i])(poly2)(i)(poly2[i])(Fc)(i)(Fc[i])(poly1)(i)(poly1[i])(L3)(i)(L3[i])(pow(
     * dt,
     * -2))(C)(i)(C[i])(phi3)(i)(phi3[i])(C)(i)(C[i])(phi3)(i)(phi3[i])(Fd)(i)(Fd[i])(poly3)(i)(poly3[i])(Fb)(i)(Fb[i])(Fa)(i)(Fa[i])(poly2)(i)(poly2[i])(Fc)(i)(Fc[i])(poly1)(i)(poly1[i])(L3)(i)(L3[i])(pow(
     * dt,  -2))(L3)(i)(L3[i])(pow( dt,
     * -2))(Fd)(i)(Fd[i])(poly3)(i)(poly3[i])(Fb)(i)(Fb[i])(Fa)(i)(Fa[i])(poly2)(i)(poly2[i])(Fc)(i)(Fc[i])(poly1)(i)(poly1[i])(Fb)(i)(Fb[i])(Fa)(i)(Fa[i])(poly2)(i)(poly2[i])(Fc)(i)(Fc[i])(poly1)(i)(poly1[i])(Fc)(i)(Fc[i])(poly1)(i)(poly1[i])(Fb)(i)(Fb[i])(Fa)(i)(Fa[i])(poly2)(i)(poly2[i])(Fb)(i)(Fb[i])(Fa)(i)(Fa[i])(Fd)(i)(Fd[i])(poly3)(i)(poly3[i])(dt)(t)*/
    t = temp_var_for_ext_7;
    AssignD({(Addr)&t}, (Addr)&temp_var_for_ext_7,
            "/home/shijia/Public/testprogram/ETD_S.c_e.c:259:3");
    ;
    double temp_var_for_const_262;
    sumalpha = sumalpha_a = sumalpha_b = sumalpha_d = 0.0;
    AssignD({(Addr)&sumalpha_d, (Addr)&sumalpha_b, (Addr)&sumalpha_a,
             (Addr)&sumalpha},
            (Addr) &(temp_var_for_const_262 = 0.0),
            "/home/shijia/Public/testprogram/ETD_S.c_e.c:260:12");
    ;
    double temp_var_for_const_263;
    sumbeta = sumbeta_a = sumbeta_b = sumbeta_d = 0.0;
    AssignD(
        {(Addr)&sumbeta_d, (Addr)&sumbeta_b, (Addr)&sumbeta_a, (Addr)&sumbeta},
        (Addr) &(temp_var_for_const_263 = 0.0),
        "/home/shijia/Public/testprogram/ETD_S.c_e.c:261:11");
  }

  for (i = 0; i < N; i++) {
    printf("C[%d]=%e\n", i, C[i]);
  }
  double temp_var_for_const_264;
  end = clock();
  AssignD({(Addr)&end}, (Addr) &(temp_var_for_const_264 = clock()),
          "/home/shijia/Public/testprogram/ETD_S.c_e.c:269:6");
  ;
  double temp_var_for_const_265;
  double temp_var_for_tac_231 = end - start;
  totaltime = temp_var_for_tac_231 / CLOCKS_PER_SEC;
  computeDSub((Addr)&temp_var_for_tac_231, {(Addr)&end, (Addr)&start},
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:270:28");
  computeDDiv((Addr)&totaltime,
              {(Addr)&temp_var_for_tac_231,
               (Addr) &(temp_var_for_const_265 = CLOCKS_PER_SEC)},
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:270:12");
  ;
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
