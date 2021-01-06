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
          "/home/shijia/Public/testprogram/ETD_S.c_e.c:35:9");
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
  double temp_var_for_tac_0, temp_var_for_tac_1, temp_var_for_tac_2,
      temp_var_for_tac_3;
  double temp_var_for_const_1, temp_var_for_const_2, temp_var_for_const_3,
      temp_var_for_const_4, temp_var_for_const_5;
  double temp_var_for_callexp_0;

  temp_var_for_tac_0 = 0.0 - EMvac;

  temp_var_for_tac_1 = KB * T;

  temp_var_for_tac_2 = temp_var_for_tac_0 / temp_var_for_tac_1;

  temp_var_for_callexp_0 = exp(temp_var_for_tac_2);
  temp_var_for_tac_3 = 1.0e-6 * temp_var_for_callexp_0;

  Dvac = temp_var_for_tac_3;
//   computeDSub((Addr)&temp_var_for_tac_0,
//               {(Addr) &(temp_var_for_const_1 = 0.0), (Addr)&EMvac},
//               "/home/shijia/Public/testprogram/ETD_S.c_e.c:48:19");
//   computeDMul((Addr)&temp_var_for_tac_1, {(Addr) &(temp_var_for_const_3 = KB),
//                                           (Addr) &(temp_var_for_const_2 = T)},
//               "/home/shijia/Public/testprogram/ETD_S.c_e.c:48:34");
//   computeDDiv((Addr)&temp_var_for_tac_2,
//               {(Addr)&temp_var_for_tac_0, (Addr)&temp_var_for_tac_1},
//               "/home/shijia/Public/testprogram/ETD_S.c_e.c:48:28");
//   computeDMul((Addr)&temp_var_for_tac_3,
//               {(Addr) &(temp_var_for_const_5 = 1.0e-6),
//                (Addr) &(temp_var_for_const_4 = temp_var_for_callexp_0)},
//               "/home/shijia/Public/testprogram/ETD_S.c_e.c:47:17");
//   AssignD({(Addr)&Dvac}, (Addr)&temp_var_for_tac_3,
//           "/home/shijia/Public/testprogram/ETD_S.c_e.c:47:8");
  ; // m^2/s。1.0e-6*exp(-EMvac/(KB*T))m^2/s
    // 空位的扩散系数,m^2/s=1.0e+4nm^2/s
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
  double temp_var_for_const_6;
  C[0] = Cinit;
  AssignD({(Addr) &(temp_var_for_const_6 = C[0])}, (Addr)&Cinit,
          "/home/shijia/Public/testprogram/ETD_S.c_e.c:93:8");
  ;
  // C[0] = Cinit*at2cb;                 //atom-1转换成cm

  double Alpha0, Beta0;
  double temp_var_for_tac_4, temp_var_for_tac_5, temp_var_for_tac_6,
      temp_var_for_tac_7, temp_var_for_tac_8, temp_var_for_tac_9;
  double temp_var_for_const_7, temp_var_for_const_8, temp_var_for_const_9,
      temp_var_for_const_10, temp_var_for_const_11, temp_var_for_const_12;
  double temp_var_for_callexp_1;

  temp_var_for_tac_4 = 48.0 * PI;

  temp_var_for_tac_5 = temp_var_for_tac_4 * PI;

  temp_var_for_tac_6 = temp_var_for_tac_5 / Vat;

  temp_var_for_tac_7 = temp_var_for_tac_6 / Vat;

  temp_var_for_tac_8 = 1.0 / 3.0;

  temp_var_for_callexp_1 = pow(temp_var_for_tac_7, temp_var_for_tac_8);
  temp_var_for_tac_9 = temp_var_for_callexp_1 * Dvac;

  Alpha0 = temp_var_for_tac_9;
  computeDMul((Addr)&temp_var_for_tac_4, {(Addr) &(temp_var_for_const_8 = 48.0),
                                          (Addr) &(temp_var_for_const_7 = PI)},
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:97:30");
  computeDMul((Addr)&temp_var_for_tac_5,
              {(Addr)&temp_var_for_tac_4, (Addr) &(temp_var_for_const_9 = PI)},
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:97:35");
  computeDDiv((Addr)&temp_var_for_tac_6,
              {(Addr)&temp_var_for_tac_5, (Addr)&Vat},
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:97:40");
  computeDDiv((Addr)&temp_var_for_tac_7,
              {(Addr)&temp_var_for_tac_6, (Addr)&Vat},
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:97:46");
  computeDDiv((Addr)&temp_var_for_tac_8,
              {(Addr) &(temp_var_for_const_11 = 1.0),
               (Addr) &(temp_var_for_const_10 = 3.0)},
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:97:58");
  computeDMul(
      (Addr)&temp_var_for_tac_9,
      {(Addr) &(temp_var_for_const_12 = temp_var_for_callexp_1), (Addr)&Dvac},
      "/home/shijia/Public/testprogram/ETD_S.c_e.c:97:65");
  AssignD({(Addr)&Alpha0}, (Addr)&temp_var_for_tac_9,
          "/home/shijia/Public/testprogram/ETD_S.c_e.c:97:18");
  Beta0 = Alpha0;
  AssignD({(Addr)&Beta0}, (Addr)&Alpha0,
          "/home/shijia/Public/testprogram/ETD_S.c_e.c:97:9");
  ;
  for (i = 0; i < N; i++) {
    double temp_var_for_tac_10, temp_var_for_tac_11, temp_var_for_tac_12,
        temp_var_for_tac_13, temp_var_for_tac_14, temp_var_for_tac_15,
        temp_var_for_tac_16;
    double temp_var_for_const_13, temp_var_for_const_14, temp_var_for_const_15,
        temp_var_for_const_16, temp_var_for_const_17, temp_var_for_const_18,
        temp_var_for_const_19, temp_var_for_const_20, temp_var_for_const_21,
        temp_var_for_const_22;
    double temp_var_for_callexp_2;

    temp_var_for_tac_10 = i + 1.0;

    temp_var_for_tac_11 = 3.0 * temp_var_for_tac_10;

    temp_var_for_tac_12 = temp_var_for_tac_11 * Vat;

    temp_var_for_tac_13 = 4 * PI;

    temp_var_for_tac_14 = temp_var_for_tac_12 / temp_var_for_tac_13;

    temp_var_for_tac_15 = 1.0 / 3.0;

    temp_var_for_callexp_2 = pow(temp_var_for_tac_14, temp_var_for_tac_15);
    temp_var_for_tac_16 = temp_var_for_callexp_2 * 1.0;

    r[i] = temp_var_for_tac_16;
    computeDAdd((Addr)&temp_var_for_tac_10,
                {(Addr) &(temp_var_for_const_14 = i),
                 (Addr) &(temp_var_for_const_13 = 1.0)},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:99:26");
    computeDMul(
        (Addr)&temp_var_for_tac_11,
        {(Addr) &(temp_var_for_const_15 = 3.0), (Addr)&temp_var_for_tac_10},
        "/home/shijia/Public/testprogram/ETD_S.c_e.c:99:21");
    computeDMul((Addr)&temp_var_for_tac_12,
                {(Addr)&temp_var_for_tac_11, (Addr)&Vat},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:99:33");
    computeDMul((Addr)&temp_var_for_tac_13,
                {(Addr) &(temp_var_for_const_17 = 4),
                 (Addr) &(temp_var_for_const_16 = PI)},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:99:44");
    computeDDiv((Addr)&temp_var_for_tac_14,
                {(Addr)&temp_var_for_tac_12, (Addr)&temp_var_for_tac_13},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:99:39");
    computeDDiv((Addr)&temp_var_for_tac_15,
                {(Addr) &(temp_var_for_const_19 = 1.0),
                 (Addr) &(temp_var_for_const_18 = 3.0)},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:99:56");
    computeDMul((Addr)&temp_var_for_tac_16,
                {(Addr) &(temp_var_for_const_21 = temp_var_for_callexp_2),
                 (Addr) &(temp_var_for_const_20 = 1.0)},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:99:63");
    AssignD({(Addr) &(temp_var_for_const_22 = r[i])},
            (Addr)&temp_var_for_tac_16,
            "/home/shijia/Public/testprogram/ETD_S.c_e.c:99:10");
    ; // nm
    double temp_var_for_tac_17, temp_var_for_tac_18, temp_var_for_tac_19,
        temp_var_for_tac_20;
    double temp_var_for_const_23, temp_var_for_const_24, temp_var_for_const_25;
    temp_var_for_tac_17 = 2.0 * Gama;

    temp_var_for_tac_18 = temp_var_for_tac_17 * Vat;

    temp_var_for_tac_19 = temp_var_for_tac_18 / r[i];

    temp_var_for_tac_20 = EFvac - temp_var_for_tac_19;

    EBvac[i] = temp_var_for_tac_20;
    computeDMul((Addr)&temp_var_for_tac_17,
                {(Addr) &(temp_var_for_const_23 = 2.0), (Addr)&Gama},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:100:28");
    computeDMul((Addr)&temp_var_for_tac_18,
                {(Addr)&temp_var_for_tac_17, (Addr)&Vat},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:100:35");
    computeDDiv(
        (Addr)&temp_var_for_tac_19,
        {(Addr)&temp_var_for_tac_18, (Addr) &(temp_var_for_const_24 = r[i])},
        "/home/shijia/Public/testprogram/ETD_S.c_e.c:100:41");
    computeDSub((Addr)&temp_var_for_tac_20,
                {(Addr)&EFvac, (Addr)&temp_var_for_tac_19},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:100:22");
    AssignD({(Addr) &(temp_var_for_const_25 = EBvac[i])},
            (Addr)&temp_var_for_tac_20,
            "/home/shijia/Public/testprogram/ETD_S.c_e.c:100:14");
    ; // eV空位缺陷结合能
    double temp_var_for_tac_21, temp_var_for_tac_22, temp_var_for_tac_23,
        temp_var_for_tac_24, temp_var_for_tac_25, temp_var_for_tac_26,
        temp_var_for_tac_27;
    double temp_var_for_const_26, temp_var_for_const_27, temp_var_for_const_28,
        temp_var_for_const_29, temp_var_for_const_30, temp_var_for_const_31,
        temp_var_for_const_32, temp_var_for_const_33, temp_var_for_const_34,
        temp_var_for_const_35, temp_var_for_const_36;
    double temp_var_for_callexp_3;

    double temp_var_for_callexp_4;

    temp_var_for_tac_21 = i + 1.0;

    temp_var_for_tac_22 = 1.0 / 3.0;

    temp_var_for_callexp_3 = pow(temp_var_for_tac_21, temp_var_for_tac_22);
    temp_var_for_tac_23 = Alpha0 * temp_var_for_callexp_3;

    temp_var_for_tac_24 = 0.0 - EBvac[i];

    temp_var_for_tac_25 = KB * T;

    temp_var_for_tac_26 = temp_var_for_tac_24 / temp_var_for_tac_25;

    temp_var_for_callexp_4 = exp(temp_var_for_tac_26);
    temp_var_for_tac_27 = temp_var_for_tac_23 * temp_var_for_callexp_4;

    Alpha[i] = temp_var_for_tac_27;
    computeDAdd((Addr)&temp_var_for_tac_21,
                {(Addr) &(temp_var_for_const_27 = i),
                 (Addr) &(temp_var_for_const_26 = 1.0)},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:102:25");
    computeDDiv((Addr)&temp_var_for_tac_22,
                {(Addr) &(temp_var_for_const_29 = 1.0),
                 (Addr) &(temp_var_for_const_28 = 3.0)},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:102:37");
    computeDMul((Addr)&temp_var_for_tac_23,
                {(Addr)&Alpha0,
                 (Addr) &(temp_var_for_const_30 = temp_var_for_callexp_3)},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:102:16");
    computeDSub((Addr)&temp_var_for_tac_24,
                {(Addr) &(temp_var_for_const_32 = 0.0),
                 (Addr) &(temp_var_for_const_31 = EBvac[i])},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:102:55");
    computeDMul((Addr)&temp_var_for_tac_25,
                {(Addr) &(temp_var_for_const_34 = KB),
                 (Addr) &(temp_var_for_const_33 = T)},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:102:73");
    computeDDiv((Addr)&temp_var_for_tac_26,
                {(Addr)&temp_var_for_tac_24, (Addr)&temp_var_for_tac_25},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:102:67");
    computeDMul((Addr)&temp_var_for_tac_27,
                {(Addr)&temp_var_for_tac_23,
                 (Addr) &(temp_var_for_const_35 = temp_var_for_callexp_4)},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:102:44");
    AssignD({(Addr) &(temp_var_for_const_36 = Alpha[i])},
            (Addr)&temp_var_for_tac_27,
            "/home/shijia/Public/testprogram/ETD_S.c_e.c:101:14");
    ;
    double temp_var_for_tac_28, temp_var_for_tac_29, temp_var_for_tac_30;
    double temp_var_for_const_37, temp_var_for_const_38, temp_var_for_const_39,
        temp_var_for_const_40, temp_var_for_const_41, temp_var_for_const_42;
    double temp_var_for_callexp_5;

    temp_var_for_tac_28 = i + 1.0;

    temp_var_for_tac_29 = 1.0 / 3.0;

    temp_var_for_callexp_5 = pow(temp_var_for_tac_28, temp_var_for_tac_29);
    temp_var_for_tac_30 = Beta0 * temp_var_for_callexp_5;

    Beta[i] = temp_var_for_tac_30;
    computeDAdd((Addr)&temp_var_for_tac_28,
                {(Addr) &(temp_var_for_const_38 = i),
                 (Addr) &(temp_var_for_const_37 = 1.0)},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:103:30");
    computeDDiv((Addr)&temp_var_for_tac_29,
                {(Addr) &(temp_var_for_const_40 = 1.0),
                 (Addr) &(temp_var_for_const_39 = 3.0)},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:103:42");
    computeDMul((Addr)&temp_var_for_tac_30,
                {(Addr)&Beta0,
                 (Addr) &(temp_var_for_const_41 = temp_var_for_callexp_5)},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:103:21");
    AssignD({(Addr) &(temp_var_for_const_42 = Beta[i])},
            (Addr)&temp_var_for_tac_30,
            "/home/shijia/Public/testprogram/ETD_S.c_e.c:103:13");
    ; //公式2
    if (i == 0) {
      double temp_var_for_tac_31, temp_var_for_tac_32;
      double temp_var_for_const_43, temp_var_for_const_44,
          temp_var_for_const_45, temp_var_for_const_46;
      double temp_var_for_callexp_6;

      temp_var_for_tac_31 = 1.0 + k;

      temp_var_for_callexp_6 = pow(temp_var_for_tac_31, (-(3)));
      temp_var_for_tac_32 = 0.0 - temp_var_for_callexp_6;

      L3[0] = temp_var_for_tac_32;
      computeDAdd((Addr)&temp_var_for_tac_31,
                  {(Addr) &(temp_var_for_const_43 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:105:31");
      computeDSub((Addr)&temp_var_for_tac_32,
                  {(Addr) &(temp_var_for_const_45 = 0.0),
                   (Addr) &(temp_var_for_const_44 = temp_var_for_callexp_6)},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:105:20");
      AssignD({(Addr) &(temp_var_for_const_46 = L3[0])},
              (Addr)&temp_var_for_tac_32,
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:105:13");
      ;
      double temp_var_for_tac_33, temp_var_for_tac_34, temp_var_for_tac_35,
          temp_var_for_tac_36;
      double temp_var_for_const_47, temp_var_for_const_48,
          temp_var_for_const_49, temp_var_for_const_50, temp_var_for_const_51;
      double temp_var_for_callexp_7;

      temp_var_for_tac_33 = 0.0 - dt;

      temp_var_for_tac_34 = 1.0 + k;

      temp_var_for_tac_35 = temp_var_for_tac_33 * temp_var_for_tac_34;

      temp_var_for_tac_36 = temp_var_for_tac_35 / 2;

      temp_var_for_callexp_7 = exp(temp_var_for_tac_36);
      phi1[0] = temp_var_for_callexp_7;
      computeDSub((Addr)&temp_var_for_tac_33,
                  {(Addr) &(temp_var_for_const_47 = 0.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:26");
      computeDAdd((Addr)&temp_var_for_tac_34,
                  {(Addr) &(temp_var_for_const_48 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:39");
      computeDMul((Addr)&temp_var_for_tac_35,
                  {(Addr)&temp_var_for_tac_33, (Addr)&temp_var_for_tac_34},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:32");
      computeDDiv(
          (Addr)&temp_var_for_tac_36,
          {(Addr)&temp_var_for_tac_35, (Addr) &(temp_var_for_const_49 = 2)},
          "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:44");
      AssignD({(Addr) &(temp_var_for_const_51 = phi1[0])},
              (Addr) &(temp_var_for_const_50 = temp_var_for_callexp_7),
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:15");
      ;
      double temp_var_for_tac_37, temp_var_for_tac_38, temp_var_for_tac_39,
          temp_var_for_tac_40, temp_var_for_tac_41, temp_var_for_tac_42,
          temp_var_for_tac_43;
      double temp_var_for_const_52, temp_var_for_const_53,
          temp_var_for_const_54, temp_var_for_const_55, temp_var_for_const_56,
          temp_var_for_const_57, temp_var_for_const_58;
      double temp_var_for_callexp_8;

      temp_var_for_tac_37 = 0.0 - dt;

      temp_var_for_tac_38 = 1.0 + k;

      temp_var_for_tac_39 = temp_var_for_tac_37 * temp_var_for_tac_38;

      temp_var_for_tac_40 = temp_var_for_tac_39 / 2;

      temp_var_for_callexp_8 = exp(temp_var_for_tac_40);
      temp_var_for_tac_41 = 1.0 - temp_var_for_callexp_8;

      temp_var_for_tac_42 = 1.0 + k;

      temp_var_for_tac_43 = temp_var_for_tac_41 / temp_var_for_tac_42;

      phi2[0] = temp_var_for_tac_43;
      computeDSub((Addr)&temp_var_for_tac_37,
                  {(Addr) &(temp_var_for_const_52 = 0.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:33");
      computeDAdd((Addr)&temp_var_for_tac_38,
                  {(Addr) &(temp_var_for_const_53 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:46");
      computeDMul((Addr)&temp_var_for_tac_39,
                  {(Addr)&temp_var_for_tac_37, (Addr)&temp_var_for_tac_38},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:39");
      computeDDiv(
          (Addr)&temp_var_for_tac_40,
          {(Addr)&temp_var_for_tac_39, (Addr) &(temp_var_for_const_54 = 2)},
          "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:51");
      computeDSub((Addr)&temp_var_for_tac_41,
                  {(Addr) &(temp_var_for_const_56 = 1.0),
                   (Addr) &(temp_var_for_const_55 = temp_var_for_callexp_8)},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:22");
      computeDAdd((Addr)&temp_var_for_tac_42,
                  {(Addr) &(temp_var_for_const_57 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:64");
      computeDDiv((Addr)&temp_var_for_tac_43,
                  {(Addr)&temp_var_for_tac_41, (Addr)&temp_var_for_tac_42},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:57");
      AssignD({(Addr) &(temp_var_for_const_58 = phi2[0])},
              (Addr)&temp_var_for_tac_43,
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:15");
      ;
      double temp_var_for_tac_44, temp_var_for_tac_45, temp_var_for_tac_46;
      double temp_var_for_const_59, temp_var_for_const_60,
          temp_var_for_const_61, temp_var_for_const_62;
      double temp_var_for_callexp_9;

      temp_var_for_tac_44 = 0.0 - dt;

      temp_var_for_tac_45 = 1.0 + k;

      temp_var_for_tac_46 = temp_var_for_tac_44 * temp_var_for_tac_45;

      temp_var_for_callexp_9 = exp(temp_var_for_tac_46);
      phi3[0] = temp_var_for_callexp_9;
      computeDSub((Addr)&temp_var_for_tac_44,
                  {(Addr) &(temp_var_for_const_59 = 0.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:108:26");
      computeDAdd((Addr)&temp_var_for_tac_45,
                  {(Addr) &(temp_var_for_const_60 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:108:39");
      computeDMul((Addr)&temp_var_for_tac_46,
                  {(Addr)&temp_var_for_tac_44, (Addr)&temp_var_for_tac_45},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:108:32");
      AssignD({(Addr) &(temp_var_for_const_62 = phi3[0])},
              (Addr) &(temp_var_for_const_61 = temp_var_for_callexp_9),
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:108:15");
      ;
      double temp_var_for_tac_47, temp_var_for_tac_48, temp_var_for_tac_49,
          temp_var_for_tac_50, temp_var_for_tac_51, temp_var_for_tac_52,
          temp_var_for_tac_53, temp_var_for_tac_54, temp_var_for_tac_55,
          temp_var_for_tac_56, temp_var_for_tac_57, temp_var_for_tac_58,
          temp_var_for_tac_59, temp_var_for_tac_60, temp_var_for_tac_61,
          temp_var_for_tac_62, temp_var_for_tac_63, temp_var_for_tac_64,
          temp_var_for_tac_65;
      double temp_var_for_const_63, temp_var_for_const_64,
          temp_var_for_const_65, temp_var_for_const_66, temp_var_for_const_67,
          temp_var_for_const_68, temp_var_for_const_69, temp_var_for_const_70,
          temp_var_for_const_71, temp_var_for_const_72, temp_var_for_const_73,
          temp_var_for_const_74;
      double temp_var_for_callexp_10;

      temp_var_for_tac_47 = 0.0 - 4.0;

      temp_var_for_tac_48 = 1.0 + k;

      temp_var_for_tac_49 = dt * temp_var_for_tac_48;

      temp_var_for_tac_50 = temp_var_for_tac_47 + temp_var_for_tac_49;

      temp_var_for_tac_51 = 0.0 - dt;

      temp_var_for_tac_52 = 1.0 + k;

      temp_var_for_tac_53 = temp_var_for_tac_51 * temp_var_for_tac_52;

      temp_var_for_callexp_10 = exp(temp_var_for_tac_53);
      temp_var_for_tac_54 = 3.0 * dt;

      temp_var_for_tac_55 = 1.0 + k;

      temp_var_for_tac_56 = temp_var_for_tac_54 * temp_var_for_tac_55;

      temp_var_for_tac_57 = 4 + temp_var_for_tac_56;

      temp_var_for_tac_58 = dt * dt;

      temp_var_for_tac_59 = 1.0 + k;

      temp_var_for_tac_60 = temp_var_for_tac_58 * temp_var_for_tac_59;

      temp_var_for_tac_61 = 1.0 + k;

      temp_var_for_tac_62 = temp_var_for_tac_60 * temp_var_for_tac_61;

      temp_var_for_tac_63 = temp_var_for_tac_57 + temp_var_for_tac_62;

      temp_var_for_tac_64 = temp_var_for_callexp_10 * temp_var_for_tac_63;

      temp_var_for_tac_65 = temp_var_for_tac_50 + temp_var_for_tac_64;

      poly1[0] = temp_var_for_tac_65;
      computeDSub((Addr)&temp_var_for_tac_47,
                  {(Addr) &(temp_var_for_const_64 = 0.0),
                   (Addr) &(temp_var_for_const_63 = 4.0)},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:110:16");
      computeDAdd((Addr)&temp_var_for_tac_48,
                  {(Addr) &(temp_var_for_const_65 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:110:35");
      computeDMul((Addr)&temp_var_for_tac_49,
                  {(Addr)&dt, (Addr)&temp_var_for_tac_48},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:110:28");
      computeDAdd((Addr)&temp_var_for_tac_50,
                  {(Addr)&temp_var_for_tac_47, (Addr)&temp_var_for_tac_49},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:110:23");
      computeDSub((Addr)&temp_var_for_tac_51,
                  {(Addr) &(temp_var_for_const_66 = 0.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:111:20");
      computeDAdd((Addr)&temp_var_for_tac_52,
                  {(Addr) &(temp_var_for_const_67 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:111:33");
      computeDMul((Addr)&temp_var_for_tac_53,
                  {(Addr)&temp_var_for_tac_51, (Addr)&temp_var_for_tac_52},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:111:26");
      computeDMul((Addr)&temp_var_for_tac_54,
                  {(Addr) &(temp_var_for_const_68 = 3.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:112:24");
      computeDAdd((Addr)&temp_var_for_tac_55,
                  {(Addr) &(temp_var_for_const_69 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:112:36");
      computeDMul((Addr)&temp_var_for_tac_56,
                  {(Addr)&temp_var_for_tac_54, (Addr)&temp_var_for_tac_55},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:112:29");
      computeDAdd(
          (Addr)&temp_var_for_tac_57,
          {(Addr) &(temp_var_for_const_70 = 4), (Addr)&temp_var_for_tac_56},
          "/home/shijia/Public/testprogram/ETD_S.c_e.c:112:18");
      computeDMul((Addr)&temp_var_for_tac_58, {(Addr)&dt, (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:112:46");
      computeDAdd((Addr)&temp_var_for_tac_59,
                  {(Addr) &(temp_var_for_const_71 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:112:58");
      computeDMul((Addr)&temp_var_for_tac_60,
                  {(Addr)&temp_var_for_tac_58, (Addr)&temp_var_for_tac_59},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:112:51");
      computeDAdd((Addr)&temp_var_for_tac_61,
                  {(Addr) &(temp_var_for_const_72 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:112:70");
      computeDMul((Addr)&temp_var_for_tac_62,
                  {(Addr)&temp_var_for_tac_60, (Addr)&temp_var_for_tac_61},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:112:63");
      computeDAdd((Addr)&temp_var_for_tac_63,
                  {(Addr)&temp_var_for_tac_57, (Addr)&temp_var_for_tac_62},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:112:41");
      computeDMul((Addr)&temp_var_for_tac_64,
                  {(Addr) &(temp_var_for_const_73 = temp_var_for_callexp_10),
                   (Addr)&temp_var_for_tac_63},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:111:39");
      computeDAdd((Addr)&temp_var_for_tac_65,
                  {(Addr)&temp_var_for_tac_50, (Addr)&temp_var_for_tac_64},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:110:40");
      AssignD({(Addr) &(temp_var_for_const_74 = poly1[0])},
              (Addr)&temp_var_for_tac_65,
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:109:16");
      ;
      double temp_var_for_tac_66, temp_var_for_tac_67, temp_var_for_tac_68,
          temp_var_for_tac_69, temp_var_for_tac_70, temp_var_for_tac_71,
          temp_var_for_tac_72, temp_var_for_tac_73, temp_var_for_tac_74,
          temp_var_for_tac_75, temp_var_for_tac_76, temp_var_for_tac_77,
          temp_var_for_tac_78;
      double temp_var_for_const_75, temp_var_for_const_76,
          temp_var_for_const_77, temp_var_for_const_78, temp_var_for_const_79,
          temp_var_for_const_80, temp_var_for_const_81, temp_var_for_const_82,
          temp_var_for_const_83, temp_var_for_const_84;
      double temp_var_for_callexp_11;

      temp_var_for_tac_66 = 2.0 * dt;

      temp_var_for_tac_67 = 1.0 + k;

      temp_var_for_tac_68 = temp_var_for_tac_66 * temp_var_for_tac_67;

      temp_var_for_tac_69 = 4.0 - temp_var_for_tac_68;

      temp_var_for_tac_70 = 0.0 - dt;

      temp_var_for_tac_71 = 1.0 + k;

      temp_var_for_tac_72 = temp_var_for_tac_70 * temp_var_for_tac_71;

      temp_var_for_callexp_11 = exp(temp_var_for_tac_72);
      temp_var_for_tac_73 = 2.0 * dt;

      temp_var_for_tac_74 = 1.0 + k;

      temp_var_for_tac_75 = temp_var_for_tac_73 * temp_var_for_tac_74;

      temp_var_for_tac_76 = (-(4)) - temp_var_for_tac_75;

      temp_var_for_tac_77 = temp_var_for_callexp_11 * temp_var_for_tac_76;

      temp_var_for_tac_78 = temp_var_for_tac_69 + temp_var_for_tac_77;

      poly2[0] = temp_var_for_tac_78;
      computeDMul((Addr)&temp_var_for_tac_66,
                  {(Addr) &(temp_var_for_const_75 = 2.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:113:28");
      computeDAdd((Addr)&temp_var_for_tac_67,
                  {(Addr) &(temp_var_for_const_76 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:113:40");
      computeDMul((Addr)&temp_var_for_tac_68,
                  {(Addr)&temp_var_for_tac_66, (Addr)&temp_var_for_tac_67},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:113:33");
      computeDSub(
          (Addr)&temp_var_for_tac_69,
          {(Addr) &(temp_var_for_const_77 = 4.0), (Addr)&temp_var_for_tac_68},
          "/home/shijia/Public/testprogram/ETD_S.c_e.c:113:22");
      computeDSub((Addr)&temp_var_for_tac_70,
                  {(Addr) &(temp_var_for_const_78 = 0.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:114:27");
      computeDAdd((Addr)&temp_var_for_tac_71,
                  {(Addr) &(temp_var_for_const_79 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:114:40");
      computeDMul((Addr)&temp_var_for_tac_72,
                  {(Addr)&temp_var_for_tac_70, (Addr)&temp_var_for_tac_71},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:114:33");
      computeDMul((Addr)&temp_var_for_tac_73,
                  {(Addr) &(temp_var_for_const_80 = 2.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:114:58");
      computeDAdd((Addr)&temp_var_for_tac_74,
                  {(Addr) &(temp_var_for_const_81 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:114:70");
      computeDMul((Addr)&temp_var_for_tac_75,
                  {(Addr)&temp_var_for_tac_73, (Addr)&temp_var_for_tac_74},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:114:63");
      computeDSub((Addr)&temp_var_for_tac_76,
                  {(Addr) &(temp_var_for_const_82 = (-(4))),
                   (Addr)&temp_var_for_tac_75},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:114:52");
      computeDMul((Addr)&temp_var_for_tac_77,
                  {(Addr) &(temp_var_for_const_83 = temp_var_for_callexp_11),
                   (Addr)&temp_var_for_tac_76},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:114:46");
      computeDAdd((Addr)&temp_var_for_tac_78,
                  {(Addr)&temp_var_for_tac_69, (Addr)&temp_var_for_tac_77},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:113:45");
      AssignD({(Addr) &(temp_var_for_const_84 = poly2[0])},
              (Addr)&temp_var_for_tac_78,
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:113:16");
      ;
      double temp_var_for_tac_79, temp_var_for_tac_80, temp_var_for_tac_81,
          temp_var_for_tac_82, temp_var_for_tac_83, temp_var_for_tac_84,
          temp_var_for_tac_85, temp_var_for_tac_86, temp_var_for_tac_87,
          temp_var_for_tac_88, temp_var_for_tac_89, temp_var_for_tac_90,
          temp_var_for_tac_91, temp_var_for_tac_92, temp_var_for_tac_93,
          temp_var_for_tac_94, temp_var_for_tac_95, temp_var_for_tac_96,
          temp_var_for_tac_97;
      double temp_var_for_const_85, temp_var_for_const_86,
          temp_var_for_const_87, temp_var_for_const_88, temp_var_for_const_89,
          temp_var_for_const_90, temp_var_for_const_91, temp_var_for_const_92,
          temp_var_for_const_93, temp_var_for_const_94, temp_var_for_const_95,
          temp_var_for_const_96;
      double temp_var_for_callexp_12;

      temp_var_for_tac_79 = 0.0 - 4.0;

      temp_var_for_tac_80 = 3.0 * dt;

      temp_var_for_tac_81 = 1.0 + k;

      temp_var_for_tac_82 = temp_var_for_tac_80 * temp_var_for_tac_81;

      temp_var_for_tac_83 = temp_var_for_tac_79 + temp_var_for_tac_82;

      temp_var_for_tac_84 = dt * dt;

      temp_var_for_tac_85 = 1.0 + k;

      temp_var_for_tac_86 = temp_var_for_tac_84 * temp_var_for_tac_85;

      temp_var_for_tac_87 = 1.0 + k;

      temp_var_for_tac_88 = temp_var_for_tac_86 * temp_var_for_tac_87;

      temp_var_for_tac_89 = temp_var_for_tac_83 - temp_var_for_tac_88;

      temp_var_for_tac_90 = 0.0 - dt;

      temp_var_for_tac_91 = 1.0 + k;

      temp_var_for_tac_92 = temp_var_for_tac_90 * temp_var_for_tac_91;

      temp_var_for_callexp_12 = exp(temp_var_for_tac_92);
      temp_var_for_tac_93 = 1.0 + k;

      temp_var_for_tac_94 = dt * temp_var_for_tac_93;

      temp_var_for_tac_95 = 4 + temp_var_for_tac_94;

      temp_var_for_tac_96 = temp_var_for_callexp_12 * temp_var_for_tac_95;

      temp_var_for_tac_97 = temp_var_for_tac_89 + temp_var_for_tac_96;

      poly3[0] = temp_var_for_tac_97;
      computeDSub((Addr)&temp_var_for_tac_79,
                  {(Addr) &(temp_var_for_const_86 = 0.0),
                   (Addr) &(temp_var_for_const_85 = 4.0)},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:23");
      computeDMul((Addr)&temp_var_for_tac_80,
                  {(Addr) &(temp_var_for_const_87 = 3.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:36");
      computeDAdd((Addr)&temp_var_for_tac_81,
                  {(Addr) &(temp_var_for_const_88 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:48");
      computeDMul((Addr)&temp_var_for_tac_82,
                  {(Addr)&temp_var_for_tac_80, (Addr)&temp_var_for_tac_81},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:41");
      computeDAdd((Addr)&temp_var_for_tac_83,
                  {(Addr)&temp_var_for_tac_79, (Addr)&temp_var_for_tac_82},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:30");
      computeDMul((Addr)&temp_var_for_tac_84, {(Addr)&dt, (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:21");
      computeDAdd((Addr)&temp_var_for_tac_85,
                  {(Addr) &(temp_var_for_const_89 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:33");
      computeDMul((Addr)&temp_var_for_tac_86,
                  {(Addr)&temp_var_for_tac_84, (Addr)&temp_var_for_tac_85},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:26");
      computeDAdd((Addr)&temp_var_for_tac_87,
                  {(Addr) &(temp_var_for_const_90 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:45");
      computeDMul((Addr)&temp_var_for_tac_88,
                  {(Addr)&temp_var_for_tac_86, (Addr)&temp_var_for_tac_87},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:38");
      computeDSub((Addr)&temp_var_for_tac_89,
                  {(Addr)&temp_var_for_tac_83, (Addr)&temp_var_for_tac_88},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:53");
      computeDSub((Addr)&temp_var_for_tac_90,
                  {(Addr) &(temp_var_for_const_91 = 0.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:27");
      computeDAdd((Addr)&temp_var_for_tac_91,
                  {(Addr) &(temp_var_for_const_92 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:40");
      computeDMul((Addr)&temp_var_for_tac_92,
                  {(Addr)&temp_var_for_tac_90, (Addr)&temp_var_for_tac_91},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:33");
      computeDAdd((Addr)&temp_var_for_tac_93,
                  {(Addr) &(temp_var_for_const_93 = 1.0), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:63");
      computeDMul((Addr)&temp_var_for_tac_94,
                  {(Addr)&dt, (Addr)&temp_var_for_tac_93},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:56");
      computeDAdd(
          (Addr)&temp_var_for_tac_95,
          {(Addr) &(temp_var_for_const_94 = 4), (Addr)&temp_var_for_tac_94},
          "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:51");
      computeDMul((Addr)&temp_var_for_tac_96,
                  {(Addr) &(temp_var_for_const_95 = temp_var_for_callexp_12),
                   (Addr)&temp_var_for_tac_95},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:46");
      computeDAdd((Addr)&temp_var_for_tac_97,
                  {(Addr)&temp_var_for_tac_89, (Addr)&temp_var_for_tac_96},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:50");
      AssignD({(Addr) &(temp_var_for_const_96 = poly3[0])},
              (Addr)&temp_var_for_tac_97,
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:16");
      ;
    } else {
      double temp_var_for_tac_98, temp_var_for_tac_99;
      double temp_var_for_const_97, temp_var_for_const_98,
          temp_var_for_const_99, temp_var_for_const_100;
      double temp_var_for_callexp_13;

      temp_var_for_tac_98 = Alpha[i] + k;

      temp_var_for_callexp_13 = pow(temp_var_for_tac_98, (-(3)));
      temp_var_for_tac_99 = 0.0 - temp_var_for_callexp_13;

      L3[i] = temp_var_for_tac_99;
      computeDAdd((Addr)&temp_var_for_tac_98,
                  {(Addr) &(temp_var_for_const_97 = Alpha[i]), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:119:36");
      computeDSub((Addr)&temp_var_for_tac_99,
                  {(Addr) &(temp_var_for_const_99 = 0.0),
                   (Addr) &(temp_var_for_const_98 = temp_var_for_callexp_13)},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:119:20");
      AssignD({(Addr) &(temp_var_for_const_100 = L3[i])},
              (Addr)&temp_var_for_tac_99,
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:119:13");
      ;
      double temp_var_for_tac_100, temp_var_for_tac_101, temp_var_for_tac_102,
          temp_var_for_tac_103;
      double temp_var_for_const_101, temp_var_for_const_102,
          temp_var_for_const_103, temp_var_for_const_104,
          temp_var_for_const_105;
      double temp_var_for_callexp_14;

      temp_var_for_tac_100 = 0.0 - dt;

      temp_var_for_tac_101 = Alpha[i] + k;

      temp_var_for_tac_102 = temp_var_for_tac_100 * temp_var_for_tac_101;

      temp_var_for_tac_103 = temp_var_for_tac_102 / 2;

      temp_var_for_callexp_14 = exp(temp_var_for_tac_103);
      phi1[i] = temp_var_for_callexp_14;
      computeDSub((Addr)&temp_var_for_tac_100,
                  {(Addr) &(temp_var_for_const_101 = 0.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:120:26");
      computeDAdd((Addr)&temp_var_for_tac_101,
                  {(Addr) &(temp_var_for_const_102 = Alpha[i]), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:120:44");
      computeDMul((Addr)&temp_var_for_tac_102,
                  {(Addr)&temp_var_for_tac_100, (Addr)&temp_var_for_tac_101},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:120:32");
      computeDDiv(
          (Addr)&temp_var_for_tac_103,
          {(Addr)&temp_var_for_tac_102, (Addr) &(temp_var_for_const_103 = 2)},
          "/home/shijia/Public/testprogram/ETD_S.c_e.c:120:49");
      AssignD({(Addr) &(temp_var_for_const_105 = phi1[i])},
              (Addr) &(temp_var_for_const_104 = temp_var_for_callexp_14),
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:120:15");
      ;
      double temp_var_for_tac_104, temp_var_for_tac_105, temp_var_for_tac_106,
          temp_var_for_tac_107, temp_var_for_tac_108, temp_var_for_tac_109,
          temp_var_for_tac_110;
      double temp_var_for_const_106, temp_var_for_const_107,
          temp_var_for_const_108, temp_var_for_const_109,
          temp_var_for_const_110, temp_var_for_const_111,
          temp_var_for_const_112;
      double temp_var_for_callexp_15;

      temp_var_for_tac_104 = 0.0 - dt;

      temp_var_for_tac_105 = Alpha[i] + k;

      temp_var_for_tac_106 = temp_var_for_tac_104 * temp_var_for_tac_105;

      temp_var_for_tac_107 = temp_var_for_tac_106 / 2;

      temp_var_for_callexp_15 = exp(temp_var_for_tac_107);
      temp_var_for_tac_108 = 1.0 - temp_var_for_callexp_15;

      temp_var_for_tac_109 = Alpha[i] + k;

      temp_var_for_tac_110 = temp_var_for_tac_108 / temp_var_for_tac_109;

      phi2[i] = temp_var_for_tac_110;
      computeDSub((Addr)&temp_var_for_tac_104,
                  {(Addr) &(temp_var_for_const_106 = 0.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:121:33");
      computeDAdd((Addr)&temp_var_for_tac_105,
                  {(Addr) &(temp_var_for_const_107 = Alpha[i]), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:121:51");
      computeDMul((Addr)&temp_var_for_tac_106,
                  {(Addr)&temp_var_for_tac_104, (Addr)&temp_var_for_tac_105},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:121:39");
      computeDDiv(
          (Addr)&temp_var_for_tac_107,
          {(Addr)&temp_var_for_tac_106, (Addr) &(temp_var_for_const_108 = 2)},
          "/home/shijia/Public/testprogram/ETD_S.c_e.c:121:56");
      computeDSub((Addr)&temp_var_for_tac_108,
                  {(Addr) &(temp_var_for_const_110 = 1.0),
                   (Addr) &(temp_var_for_const_109 = temp_var_for_callexp_15)},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:121:22");
      computeDAdd((Addr)&temp_var_for_tac_109,
                  {(Addr) &(temp_var_for_const_111 = Alpha[i]), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:121:74");
      computeDDiv((Addr)&temp_var_for_tac_110,
                  {(Addr)&temp_var_for_tac_108, (Addr)&temp_var_for_tac_109},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:121:62");
      AssignD({(Addr) &(temp_var_for_const_112 = phi2[i])},
              (Addr)&temp_var_for_tac_110,
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:121:15");
      ;
      double temp_var_for_tac_111, temp_var_for_tac_112, temp_var_for_tac_113;
      double temp_var_for_const_113, temp_var_for_const_114,
          temp_var_for_const_115, temp_var_for_const_116;
      double temp_var_for_callexp_16;

      temp_var_for_tac_111 = 0.0 - dt;

      temp_var_for_tac_112 = Alpha[i] + k;

      temp_var_for_tac_113 = temp_var_for_tac_111 * temp_var_for_tac_112;

      temp_var_for_callexp_16 = exp(temp_var_for_tac_113);
      phi3[i] = temp_var_for_callexp_16;
      computeDSub((Addr)&temp_var_for_tac_111,
                  {(Addr) &(temp_var_for_const_113 = 0.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:122:26");
      computeDAdd((Addr)&temp_var_for_tac_112,
                  {(Addr) &(temp_var_for_const_114 = Alpha[i]), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:122:44");
      computeDMul((Addr)&temp_var_for_tac_113,
                  {(Addr)&temp_var_for_tac_111, (Addr)&temp_var_for_tac_112},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:122:32");
      AssignD({(Addr) &(temp_var_for_const_116 = phi3[i])},
              (Addr) &(temp_var_for_const_115 = temp_var_for_callexp_16),
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:122:15");
      ;
      double temp_var_for_tac_114, temp_var_for_tac_115, temp_var_for_tac_116,
          temp_var_for_tac_117, temp_var_for_tac_118, temp_var_for_tac_119,
          temp_var_for_tac_120, temp_var_for_tac_121, temp_var_for_tac_122,
          temp_var_for_tac_123, temp_var_for_tac_124, temp_var_for_tac_125,
          temp_var_for_tac_126, temp_var_for_tac_127, temp_var_for_tac_128,
          temp_var_for_tac_129, temp_var_for_tac_130, temp_var_for_tac_131,
          temp_var_for_tac_132;
      double temp_var_for_const_117, temp_var_for_const_118,
          temp_var_for_const_119, temp_var_for_const_120,
          temp_var_for_const_121, temp_var_for_const_122,
          temp_var_for_const_123, temp_var_for_const_124,
          temp_var_for_const_125, temp_var_for_const_126,
          temp_var_for_const_127, temp_var_for_const_128;
      double temp_var_for_callexp_17;

      temp_var_for_tac_114 = 0.0 - 4.0;

      temp_var_for_tac_115 = Alpha[i] + k;

      temp_var_for_tac_116 = dt * temp_var_for_tac_115;

      temp_var_for_tac_117 = temp_var_for_tac_114 + temp_var_for_tac_116;

      temp_var_for_tac_118 = 0.0 - dt;

      temp_var_for_tac_119 = Alpha[i] + k;

      temp_var_for_tac_120 = temp_var_for_tac_118 * temp_var_for_tac_119;

      temp_var_for_callexp_17 = exp(temp_var_for_tac_120);
      temp_var_for_tac_121 = 3.0 * dt;

      temp_var_for_tac_122 = Alpha[i] + k;

      temp_var_for_tac_123 = temp_var_for_tac_121 * temp_var_for_tac_122;

      temp_var_for_tac_124 = 4 + temp_var_for_tac_123;

      temp_var_for_tac_125 = dt * dt;

      temp_var_for_tac_126 = Alpha[i] + k;

      temp_var_for_tac_127 = temp_var_for_tac_125 * temp_var_for_tac_126;

      temp_var_for_tac_128 = Alpha[i] + k;

      temp_var_for_tac_129 = temp_var_for_tac_127 * temp_var_for_tac_128;

      temp_var_for_tac_130 = temp_var_for_tac_124 + temp_var_for_tac_129;

      temp_var_for_tac_131 = temp_var_for_callexp_17 * temp_var_for_tac_130;

      temp_var_for_tac_132 = temp_var_for_tac_117 + temp_var_for_tac_131;

      poly1[i] = temp_var_for_tac_132;
      computeDSub((Addr)&temp_var_for_tac_114,
                  {(Addr) &(temp_var_for_const_118 = 0.0),
                   (Addr) &(temp_var_for_const_117 = 4.0)},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:123:23");
      computeDAdd((Addr)&temp_var_for_tac_115,
                  {(Addr) &(temp_var_for_const_119 = Alpha[i]), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:123:47");
      computeDMul((Addr)&temp_var_for_tac_116,
                  {(Addr)&dt, (Addr)&temp_var_for_tac_115},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:123:35");
      computeDAdd((Addr)&temp_var_for_tac_117,
                  {(Addr)&temp_var_for_tac_114, (Addr)&temp_var_for_tac_116},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:123:30");
      computeDSub((Addr)&temp_var_for_tac_118,
                  {(Addr) &(temp_var_for_const_120 = 0.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:124:27");
      computeDAdd((Addr)&temp_var_for_tac_119,
                  {(Addr) &(temp_var_for_const_121 = Alpha[i]), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:124:45");
      computeDMul((Addr)&temp_var_for_tac_120,
                  {(Addr)&temp_var_for_tac_118, (Addr)&temp_var_for_tac_119},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:124:33");
      computeDMul((Addr)&temp_var_for_tac_121,
                  {(Addr) &(temp_var_for_const_122 = 3.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:125:31");
      computeDAdd((Addr)&temp_var_for_tac_122,
                  {(Addr) &(temp_var_for_const_123 = Alpha[i]), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:125:48");
      computeDMul((Addr)&temp_var_for_tac_123,
                  {(Addr)&temp_var_for_tac_121, (Addr)&temp_var_for_tac_122},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:125:36");
      computeDAdd(
          (Addr)&temp_var_for_tac_124,
          {(Addr) &(temp_var_for_const_124 = 4), (Addr)&temp_var_for_tac_123},
          "/home/shijia/Public/testprogram/ETD_S.c_e.c:125:25");
      computeDMul((Addr)&temp_var_for_tac_125, {(Addr)&dt, (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:126:26");
      computeDAdd((Addr)&temp_var_for_tac_126,
                  {(Addr) &(temp_var_for_const_125 = Alpha[i]), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:126:43");
      computeDMul((Addr)&temp_var_for_tac_127,
                  {(Addr)&temp_var_for_tac_125, (Addr)&temp_var_for_tac_126},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:126:31");
      computeDAdd((Addr)&temp_var_for_tac_128,
                  {(Addr) &(temp_var_for_const_126 = Alpha[i]), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:126:60");
      computeDMul((Addr)&temp_var_for_tac_129,
                  {(Addr)&temp_var_for_tac_127, (Addr)&temp_var_for_tac_128},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:126:48");
      computeDAdd((Addr)&temp_var_for_tac_130,
                  {(Addr)&temp_var_for_tac_124, (Addr)&temp_var_for_tac_129},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:125:53");
      computeDMul((Addr)&temp_var_for_tac_131,
                  {(Addr) &(temp_var_for_const_127 = temp_var_for_callexp_17),
                   (Addr)&temp_var_for_tac_130},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:124:51");
      computeDAdd((Addr)&temp_var_for_tac_132,
                  {(Addr)&temp_var_for_tac_117, (Addr)&temp_var_for_tac_131},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:123:52");
      AssignD({(Addr) &(temp_var_for_const_128 = poly1[i])},
              (Addr)&temp_var_for_tac_132,
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:123:16");
      ;
      double temp_var_for_tac_133, temp_var_for_tac_134, temp_var_for_tac_135,
          temp_var_for_tac_136, temp_var_for_tac_137, temp_var_for_tac_138,
          temp_var_for_tac_139, temp_var_for_tac_140, temp_var_for_tac_141,
          temp_var_for_tac_142, temp_var_for_tac_143, temp_var_for_tac_144,
          temp_var_for_tac_145;
      double temp_var_for_const_129, temp_var_for_const_130,
          temp_var_for_const_131, temp_var_for_const_132,
          temp_var_for_const_133, temp_var_for_const_134,
          temp_var_for_const_135, temp_var_for_const_136,
          temp_var_for_const_137, temp_var_for_const_138;
      double temp_var_for_callexp_18;

      temp_var_for_tac_133 = 2.0 * dt;

      temp_var_for_tac_134 = Alpha[i] + k;

      temp_var_for_tac_135 = temp_var_for_tac_133 * temp_var_for_tac_134;

      temp_var_for_tac_136 = 4.0 - temp_var_for_tac_135;

      temp_var_for_tac_137 = 0.0 - dt;

      temp_var_for_tac_138 = Alpha[i] + k;

      temp_var_for_tac_139 = temp_var_for_tac_137 * temp_var_for_tac_138;

      temp_var_for_callexp_18 = exp(temp_var_for_tac_139);
      temp_var_for_tac_140 = 2.0 * dt;

      temp_var_for_tac_141 = Alpha[i] + k;

      temp_var_for_tac_142 = temp_var_for_tac_140 * temp_var_for_tac_141;

      temp_var_for_tac_143 = (-(4)) - temp_var_for_tac_142;

      temp_var_for_tac_144 = temp_var_for_callexp_18 * temp_var_for_tac_143;

      temp_var_for_tac_145 = temp_var_for_tac_136 + temp_var_for_tac_144;

      poly2[i] = temp_var_for_tac_145;
      computeDMul((Addr)&temp_var_for_tac_133,
                  {(Addr) &(temp_var_for_const_129 = 2.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:128:21");
      computeDAdd((Addr)&temp_var_for_tac_134,
                  {(Addr) &(temp_var_for_const_130 = Alpha[i]), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:128:38");
      computeDMul((Addr)&temp_var_for_tac_135,
                  {(Addr)&temp_var_for_tac_133, (Addr)&temp_var_for_tac_134},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:128:26");
      computeDSub(
          (Addr)&temp_var_for_tac_136,
          {(Addr) &(temp_var_for_const_131 = 4.0), (Addr)&temp_var_for_tac_135},
          "/home/shijia/Public/testprogram/ETD_S.c_e.c:128:15");
      computeDSub((Addr)&temp_var_for_tac_137,
                  {(Addr) &(temp_var_for_const_132 = 0.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:129:20");
      computeDAdd((Addr)&temp_var_for_tac_138,
                  {(Addr) &(temp_var_for_const_133 = Alpha[i]), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:129:38");
      computeDMul((Addr)&temp_var_for_tac_139,
                  {(Addr)&temp_var_for_tac_137, (Addr)&temp_var_for_tac_138},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:129:26");
      computeDMul((Addr)&temp_var_for_tac_140,
                  {(Addr) &(temp_var_for_const_134 = 2.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:129:56");
      computeDAdd((Addr)&temp_var_for_tac_141,
                  {(Addr) &(temp_var_for_const_135 = Alpha[i]), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:129:73");
      computeDMul((Addr)&temp_var_for_tac_142,
                  {(Addr)&temp_var_for_tac_140, (Addr)&temp_var_for_tac_141},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:129:61");
      computeDSub((Addr)&temp_var_for_tac_143,
                  {(Addr) &(temp_var_for_const_136 = (-(4))),
                   (Addr)&temp_var_for_tac_142},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:129:50");
      computeDMul((Addr)&temp_var_for_tac_144,
                  {(Addr) &(temp_var_for_const_137 = temp_var_for_callexp_18),
                   (Addr)&temp_var_for_tac_143},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:129:44");
      computeDAdd((Addr)&temp_var_for_tac_145,
                  {(Addr)&temp_var_for_tac_136, (Addr)&temp_var_for_tac_144},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:128:43");
      AssignD({(Addr) &(temp_var_for_const_138 = poly2[i])},
              (Addr)&temp_var_for_tac_145,
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:127:16");
      ;
      double temp_var_for_tac_146, temp_var_for_tac_147, temp_var_for_tac_148,
          temp_var_for_tac_149, temp_var_for_tac_150, temp_var_for_tac_151,
          temp_var_for_tac_152, temp_var_for_tac_153, temp_var_for_tac_154,
          temp_var_for_tac_155, temp_var_for_tac_156, temp_var_for_tac_157,
          temp_var_for_tac_158, temp_var_for_tac_159, temp_var_for_tac_160,
          temp_var_for_tac_161, temp_var_for_tac_162, temp_var_for_tac_163,
          temp_var_for_tac_164;
      double temp_var_for_const_139, temp_var_for_const_140,
          temp_var_for_const_141, temp_var_for_const_142,
          temp_var_for_const_143, temp_var_for_const_144,
          temp_var_for_const_145, temp_var_for_const_146,
          temp_var_for_const_147, temp_var_for_const_148,
          temp_var_for_const_149, temp_var_for_const_150;
      double temp_var_for_callexp_19;

      temp_var_for_tac_146 = 0.0 - 4.0;

      temp_var_for_tac_147 = 3.0 * dt;

      temp_var_for_tac_148 = Alpha[i] + k;

      temp_var_for_tac_149 = temp_var_for_tac_147 * temp_var_for_tac_148;

      temp_var_for_tac_150 = temp_var_for_tac_146 + temp_var_for_tac_149;

      temp_var_for_tac_151 = dt * dt;

      temp_var_for_tac_152 = Alpha[i] + k;

      temp_var_for_tac_153 = temp_var_for_tac_151 * temp_var_for_tac_152;

      temp_var_for_tac_154 = Alpha[i] + k;

      temp_var_for_tac_155 = temp_var_for_tac_153 * temp_var_for_tac_154;

      temp_var_for_tac_156 = temp_var_for_tac_150 - temp_var_for_tac_155;

      temp_var_for_tac_157 = 0.0 - dt;

      temp_var_for_tac_158 = Alpha[i] + k;

      temp_var_for_tac_159 = temp_var_for_tac_157 * temp_var_for_tac_158;

      temp_var_for_callexp_19 = exp(temp_var_for_tac_159);
      temp_var_for_tac_160 = Alpha[i] + k;

      temp_var_for_tac_161 = dt * temp_var_for_tac_160;

      temp_var_for_tac_162 = 4 + temp_var_for_tac_161;

      temp_var_for_tac_163 = temp_var_for_callexp_19 * temp_var_for_tac_162;

      temp_var_for_tac_164 = temp_var_for_tac_156 + temp_var_for_tac_163;

      poly3[i] = temp_var_for_tac_164;
      computeDSub((Addr)&temp_var_for_tac_146,
                  {(Addr) &(temp_var_for_const_140 = 0.0),
                   (Addr) &(temp_var_for_const_139 = 4.0)},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:130:23");
      computeDMul((Addr)&temp_var_for_tac_147,
                  {(Addr) &(temp_var_for_const_141 = 3.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:130:36");
      computeDAdd((Addr)&temp_var_for_tac_148,
                  {(Addr) &(temp_var_for_const_142 = Alpha[i]), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:130:53");
      computeDMul((Addr)&temp_var_for_tac_149,
                  {(Addr)&temp_var_for_tac_147, (Addr)&temp_var_for_tac_148},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:130:41");
      computeDAdd((Addr)&temp_var_for_tac_150,
                  {(Addr)&temp_var_for_tac_146, (Addr)&temp_var_for_tac_149},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:130:30");
      computeDMul((Addr)&temp_var_for_tac_151, {(Addr)&dt, (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:131:21");
      computeDAdd((Addr)&temp_var_for_tac_152,
                  {(Addr) &(temp_var_for_const_143 = Alpha[i]), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:131:38");
      computeDMul((Addr)&temp_var_for_tac_153,
                  {(Addr)&temp_var_for_tac_151, (Addr)&temp_var_for_tac_152},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:131:26");
      computeDAdd((Addr)&temp_var_for_tac_154,
                  {(Addr) &(temp_var_for_const_144 = Alpha[i]), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:131:55");
      computeDMul((Addr)&temp_var_for_tac_155,
                  {(Addr)&temp_var_for_tac_153, (Addr)&temp_var_for_tac_154},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:131:43");
      computeDSub((Addr)&temp_var_for_tac_156,
                  {(Addr)&temp_var_for_tac_150, (Addr)&temp_var_for_tac_155},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:130:58");
      computeDSub((Addr)&temp_var_for_tac_157,
                  {(Addr) &(temp_var_for_const_145 = 0.0), (Addr)&dt},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:132:27");
      computeDAdd((Addr)&temp_var_for_tac_158,
                  {(Addr) &(temp_var_for_const_146 = Alpha[i]), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:132:45");
      computeDMul((Addr)&temp_var_for_tac_159,
                  {(Addr)&temp_var_for_tac_157, (Addr)&temp_var_for_tac_158},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:132:33");
      computeDAdd((Addr)&temp_var_for_tac_160,
                  {(Addr) &(temp_var_for_const_147 = Alpha[i]), (Addr)&k},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:132:73");
      computeDMul((Addr)&temp_var_for_tac_161,
                  {(Addr)&dt, (Addr)&temp_var_for_tac_160},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:132:61");
      computeDAdd(
          (Addr)&temp_var_for_tac_162,
          {(Addr) &(temp_var_for_const_148 = 4), (Addr)&temp_var_for_tac_161},
          "/home/shijia/Public/testprogram/ETD_S.c_e.c:132:56");
      computeDMul((Addr)&temp_var_for_tac_163,
                  {(Addr) &(temp_var_for_const_149 = temp_var_for_callexp_19),
                   (Addr)&temp_var_for_tac_162},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:132:51");
      computeDAdd((Addr)&temp_var_for_tac_164,
                  {(Addr)&temp_var_for_tac_156, (Addr)&temp_var_for_tac_163},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:131:60");
      AssignD({(Addr) &(temp_var_for_const_150 = poly3[i])},
              (Addr)&temp_var_for_tac_164,
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:130:16");
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



  ;
  while ( t < TIME) {
    // printf("t=%f******sumalpha=%e\tsumbeta=%e\n",t,sumalpha,sumbeta);
    for (i = 0; i < N; i++) {
      if (i == 0) {
        double temp_var_for_const_152, temp_var_for_const_153;
        alpha[i] = 0.0;
        AssignD({(Addr) &(temp_var_for_const_153 = alpha[i])},
                (Addr) &(temp_var_for_const_152 = 0.0),
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:150:18");
        ;
        double temp_var_for_const_154, temp_var_for_const_155;
        beta[i] = 0.0;
        AssignD({(Addr) &(temp_var_for_const_155 = beta[i])},
                (Addr) &(temp_var_for_const_154 = 0.0),
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:151:17");
        ;
      } else {
        double temp_var_for_tac_166;
        double temp_var_for_const_156, temp_var_for_const_157,
            temp_var_for_const_158;
        temp_var_for_tac_166 = Alpha[i] * C[i];

        alpha[i] = temp_var_for_tac_166;
        computeDMul((Addr)&temp_var_for_tac_166,
                    {(Addr) &(temp_var_for_const_157 = Alpha[i]),
                     (Addr) &(temp_var_for_const_156 = C[i])},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:153:29");
        AssignD({(Addr) &(temp_var_for_const_158 = alpha[i])},
                (Addr)&temp_var_for_tac_166,
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:153:18");
        ;
        double temp_var_for_tac_167, temp_var_for_tac_168;
        double temp_var_for_const_159, temp_var_for_const_160,
            temp_var_for_const_161, temp_var_for_const_162;
        temp_var_for_tac_167 = Beta[i] * C[i];

        temp_var_for_tac_168 = temp_var_for_tac_167 * C[0];

        beta[i] = temp_var_for_tac_168;
        computeDMul((Addr)&temp_var_for_tac_167,
                    {(Addr) &(temp_var_for_const_160 = Beta[i]),
                     (Addr) &(temp_var_for_const_159 = C[i])},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:154:27");
        computeDMul((Addr)&temp_var_for_tac_168,
                    {(Addr)&temp_var_for_tac_167,
                     (Addr) &(temp_var_for_const_161 = C[0])},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:154:34");
        AssignD({(Addr) &(temp_var_for_const_162 = beta[i])},
                (Addr)&temp_var_for_tac_168,
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:154:17");
        ;
      }
      sumbeta += beta[i];
      ;
      sumalpha += alpha[i];
      ;
    }
    // printf("t=%f******sumalpha=%e\tsumbeta=%e\n",t,sumalpha,sumbeta);

    double temp_var_for_tac_171, temp_var_for_tac_172, temp_var_for_tac_173,
        temp_var_for_tac_174, temp_var_for_tac_175, temp_var_for_tac_176,
        temp_var_for_tac_177, temp_var_for_tac_178, temp_var_for_tac_179,
        temp_var_for_tac_180;
    double temp_var_for_const_163, temp_var_for_const_164,
        temp_var_for_const_165, temp_var_for_const_166, temp_var_for_const_167,
        temp_var_for_const_168, temp_var_for_const_169, temp_var_for_const_170,
        temp_var_for_const_171;
    temp_var_for_tac_171 = (-(2)) * Beta[0];

    temp_var_for_tac_172 = temp_var_for_tac_171 * C[0];

    temp_var_for_tac_173 = temp_var_for_tac_172 * C[0];

    temp_var_for_tac_174 = temp_var_for_tac_173 - sumbeta;

    temp_var_for_tac_175 = temp_var_for_tac_174 + sumalpha;

    temp_var_for_tac_176 = Alpha[1] * C[1];

    temp_var_for_tac_177 = temp_var_for_tac_175 + temp_var_for_tac_176;

    temp_var_for_tac_178 = 1.0 + k;

    temp_var_for_tac_179 = temp_var_for_tac_178 * C[0];

    temp_var_for_tac_180 = temp_var_for_tac_177 + temp_var_for_tac_179;

    Fc[0] = temp_var_for_tac_180;
    computeDMul((Addr)&temp_var_for_tac_171,
                {(Addr) &(temp_var_for_const_164 = (-(2))),
                 (Addr) &(temp_var_for_const_163 = Beta[0])},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:161:16");
    computeDMul(
        (Addr)&temp_var_for_tac_172,
        {(Addr)&temp_var_for_tac_171, (Addr) &(temp_var_for_const_165 = C[0])},
        "/home/shijia/Public/testprogram/ETD_S.c_e.c:161:26");
    computeDMul(
        (Addr)&temp_var_for_tac_173,
        {(Addr)&temp_var_for_tac_172, (Addr) &(temp_var_for_const_166 = C[0])},
        "/home/shijia/Public/testprogram/ETD_S.c_e.c:161:33");
    computeDSub((Addr)&temp_var_for_tac_174,
                {(Addr)&temp_var_for_tac_173, (Addr)&sumbeta},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:161:40");
    computeDAdd((Addr)&temp_var_for_tac_175,
                {(Addr)&temp_var_for_tac_174, (Addr)&sumalpha},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:161:50");
    computeDMul((Addr)&temp_var_for_tac_176,
                {(Addr) &(temp_var_for_const_168 = Alpha[1]),
                 (Addr) &(temp_var_for_const_167 = C[1])},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:161:72");
    computeDAdd((Addr)&temp_var_for_tac_177,
                {(Addr)&temp_var_for_tac_175, (Addr)&temp_var_for_tac_176},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:161:61");
    computeDAdd((Addr)&temp_var_for_tac_178,
                {(Addr) &(temp_var_for_const_169 = 1.0), (Addr)&k},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:162:18");
    computeDMul(
        (Addr)&temp_var_for_tac_179,
        {(Addr)&temp_var_for_tac_178, (Addr) &(temp_var_for_const_170 = C[0])},
        "/home/shijia/Public/testprogram/ETD_S.c_e.c:162:23");
    computeDAdd((Addr)&temp_var_for_tac_180,
                {(Addr)&temp_var_for_tac_177, (Addr)&temp_var_for_tac_179},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:161:79");
    AssignD({(Addr) &(temp_var_for_const_171 = Fc[0])},
            (Addr)&temp_var_for_tac_180,
            "/home/shijia/Public/testprogram/ETD_S.c_e.c:161:11");
    ;
    for (i = 1; i <= N - 2; i++) {
      double temp_var_for_tac_181, temp_var_for_tac_182, temp_var_for_tac_183,
          temp_var_for_tac_184, temp_var_for_tac_185, temp_var_for_tac_186,
          temp_var_for_tac_187, temp_var_for_tac_188, temp_var_for_tac_189;
      double temp_var_for_const_172, temp_var_for_const_173,
          temp_var_for_const_174, temp_var_for_const_175,
          temp_var_for_const_176, temp_var_for_const_177,
          temp_var_for_const_178, temp_var_for_const_179,
          temp_var_for_const_180, temp_var_for_const_181;
      temp_var_for_tac_181 = Beta[i - 1] * C[i - 1];

      temp_var_for_tac_182 = temp_var_for_tac_181 * C[0];

      temp_var_for_tac_183 = Beta[i] * C[i];

      temp_var_for_tac_184 = temp_var_for_tac_183 * C[0];

      temp_var_for_tac_185 = temp_var_for_tac_182 - temp_var_for_tac_184;

      temp_var_for_tac_186 = Alpha[i + 1] * C[i + 1];

      temp_var_for_tac_187 = temp_var_for_tac_185 + temp_var_for_tac_186;

      temp_var_for_tac_188 = k * C[i];

      temp_var_for_tac_189 = temp_var_for_tac_187 + temp_var_for_tac_188;

      Fc[i] = temp_var_for_tac_189;
      computeDMul((Addr)&temp_var_for_tac_181,
                  {(Addr) &(temp_var_for_const_173 = Beta[i - 1]),
                   (Addr) &(temp_var_for_const_172 = C[i - 1])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:164:27");
      computeDMul((Addr)&temp_var_for_tac_182,
                  {(Addr)&temp_var_for_tac_181,
                   (Addr) &(temp_var_for_const_174 = C[0])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:164:38");
      computeDMul((Addr)&temp_var_for_tac_183,
                  {(Addr) &(temp_var_for_const_176 = Beta[i]),
                   (Addr) &(temp_var_for_const_175 = C[i])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:164:55");
      computeDMul((Addr)&temp_var_for_tac_184,
                  {(Addr)&temp_var_for_tac_183,
                   (Addr) &(temp_var_for_const_177 = C[0])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:164:62");
      computeDSub((Addr)&temp_var_for_tac_185,
                  {(Addr)&temp_var_for_tac_182, (Addr)&temp_var_for_tac_184},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:164:45");
      computeDMul((Addr)&temp_var_for_tac_186,
                  {(Addr) &(temp_var_for_const_179 = Alpha[i + 1]),
                   (Addr) &(temp_var_for_const_178 = C[i + 1])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:165:28");
      computeDAdd((Addr)&temp_var_for_tac_187,
                  {(Addr)&temp_var_for_tac_185, (Addr)&temp_var_for_tac_186},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:164:69");
      computeDMul((Addr)&temp_var_for_tac_188,
                  {(Addr)&k, (Addr) &(temp_var_for_const_180 = C[i])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:165:43");
      computeDAdd((Addr)&temp_var_for_tac_189,
                  {(Addr)&temp_var_for_tac_187, (Addr)&temp_var_for_tac_188},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:165:39");
      AssignD({(Addr) &(temp_var_for_const_181 = Fc[i])},
              (Addr)&temp_var_for_tac_189,
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:164:13");
      ;
    }
    double temp_var_for_const_182, temp_var_for_const_183;
    Fc[N - 1] = 0.0;
    AssignD({(Addr) &(temp_var_for_const_183 = Fc[N - 1])},
            (Addr) &(temp_var_for_const_182 = 0.0),
            "/home/shijia/Public/testprogram/ETD_S.c_e.c:167:15");
    ;
    double temp_var_for_tac_190, temp_var_for_tac_191, temp_var_for_tac_192,
        temp_var_for_tac_193, temp_var_for_tac_194, temp_var_for_tac_195,
        temp_var_for_tac_196;
    double temp_var_for_const_184, temp_var_for_const_185,
        temp_var_for_const_186, temp_var_for_const_187, temp_var_for_const_188,
        temp_var_for_const_189, temp_var_for_const_190, temp_var_for_const_191;
    temp_var_for_tac_190 = Beta[N - 2] * C[N - 2];

    temp_var_for_tac_191 = temp_var_for_tac_190 * C[0];

    temp_var_for_tac_192 = Beta[N - 1] * C[N - 1];

    temp_var_for_tac_193 = temp_var_for_tac_192 * C[0];

    temp_var_for_tac_194 = temp_var_for_tac_191 - temp_var_for_tac_193;

    temp_var_for_tac_195 = k * C[N - 1];

    temp_var_for_tac_196 = temp_var_for_tac_194 + temp_var_for_tac_195;

    Fc[N - 1] = temp_var_for_tac_196;
    computeDMul((Addr)&temp_var_for_tac_190,
                {(Addr) &(temp_var_for_const_185 = Beta[N - 2]),
                 (Addr) &(temp_var_for_const_184 = C[N - 2])},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:168:29");
    computeDMul(
        (Addr)&temp_var_for_tac_191,
        {(Addr)&temp_var_for_tac_190, (Addr) &(temp_var_for_const_186 = C[0])},
        "/home/shijia/Public/testprogram/ETD_S.c_e.c:168:40");
    computeDMul((Addr)&temp_var_for_tac_192,
                {(Addr) &(temp_var_for_const_188 = Beta[N - 1]),
                 (Addr) &(temp_var_for_const_187 = C[N - 1])},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:168:61");
    computeDMul(
        (Addr)&temp_var_for_tac_193,
        {(Addr)&temp_var_for_tac_192, (Addr) &(temp_var_for_const_189 = C[0])},
        "/home/shijia/Public/testprogram/ETD_S.c_e.c:168:72");
    computeDSub((Addr)&temp_var_for_tac_194,
                {(Addr)&temp_var_for_tac_191, (Addr)&temp_var_for_tac_193},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:168:47");
    computeDMul((Addr)&temp_var_for_tac_195,
                {(Addr)&k, (Addr) &(temp_var_for_const_190 = C[N - 1])},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:169:19");
    computeDAdd((Addr)&temp_var_for_tac_196,
                {(Addr)&temp_var_for_tac_194, (Addr)&temp_var_for_tac_195},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:168:79");
    AssignD({(Addr) &(temp_var_for_const_191 = Fc[N - 1])},
            (Addr)&temp_var_for_tac_196,
            "/home/shijia/Public/testprogram/ETD_S.c_e.c:168:15");
    ;
    /*
    for(i=0;i<N;i++){
            printf("Fc[%d]=%e\n",i,Fc[i]);
    }*/

    for (i = 0; i < N; i++) {
      double temp_var_for_const_192, temp_var_for_const_193;
      a[i] = 0.0;
      AssignD({(Addr) &(temp_var_for_const_193 = a[i])},
              (Addr) &(temp_var_for_const_192 = 0.0),
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:176:12");
      ;
      double temp_var_for_tac_197, temp_var_for_tac_198, temp_var_for_tac_199;
      double temp_var_for_const_194, temp_var_for_const_195,
          temp_var_for_const_196, temp_var_for_const_197,
          temp_var_for_const_198;
      temp_var_for_tac_197 = phi1[i] * C[i];

      temp_var_for_tac_198 = phi2[i] * Fc[i];

      temp_var_for_tac_199 = temp_var_for_tac_197 + temp_var_for_tac_198;

      a[i] = temp_var_for_tac_199;
      computeDMul((Addr)&temp_var_for_tac_197,
                  {(Addr) &(temp_var_for_const_195 = phi1[i]),
                   (Addr) &(temp_var_for_const_194 = C[i])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:177:22");
      computeDMul((Addr)&temp_var_for_tac_198,
                  {(Addr) &(temp_var_for_const_197 = phi2[i]),
                   (Addr) &(temp_var_for_const_196 = Fc[i])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:177:39");
      computeDAdd((Addr)&temp_var_for_tac_199,
                  {(Addr)&temp_var_for_tac_197, (Addr)&temp_var_for_tac_198},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:177:29");
      AssignD({(Addr) &(temp_var_for_const_198 = a[i])},
              (Addr)&temp_var_for_tac_199,
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:177:12");
      ;
      if (i == 0) {
        double temp_var_for_const_199, temp_var_for_const_200;
        alpha_a[i] = 0.0;
        AssignD({(Addr) &(temp_var_for_const_200 = alpha_a[i])},
                (Addr) &(temp_var_for_const_199 = 0.0),
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:179:20");
        ;
        double temp_var_for_const_201, temp_var_for_const_202;
        beta_a[i] = 0.0;
        AssignD({(Addr) &(temp_var_for_const_202 = beta_a[i])},
                (Addr) &(temp_var_for_const_201 = 0.0),
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:180:19");
        ;
      } else {
        double temp_var_for_tac_200;
        double temp_var_for_const_203, temp_var_for_const_204,
            temp_var_for_const_205;
        temp_var_for_tac_200 = Alpha[i] * a[i];

        alpha_a[i] = temp_var_for_tac_200;
        computeDMul((Addr)&temp_var_for_tac_200,
                    {(Addr) &(temp_var_for_const_204 = Alpha[i]),
                     (Addr) &(temp_var_for_const_203 = a[i])},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:182:31");
        AssignD({(Addr) &(temp_var_for_const_205 = alpha_a[i])},
                (Addr)&temp_var_for_tac_200,
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:182:20");
        ;
        double temp_var_for_tac_201, temp_var_for_tac_202;
        double temp_var_for_const_206, temp_var_for_const_207,
            temp_var_for_const_208, temp_var_for_const_209;
        temp_var_for_tac_201 = Beta[i] * a[i];

        temp_var_for_tac_202 = temp_var_for_tac_201 * a[0];

        beta_a[i] = temp_var_for_tac_202;
        computeDMul((Addr)&temp_var_for_tac_201,
                    {(Addr) &(temp_var_for_const_207 = Beta[i]),
                     (Addr) &(temp_var_for_const_206 = a[i])},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:183:29");
        computeDMul((Addr)&temp_var_for_tac_202,
                    {(Addr)&temp_var_for_tac_201,
                     (Addr) &(temp_var_for_const_208 = a[0])},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:183:36");
        AssignD({(Addr) &(temp_var_for_const_209 = beta_a[i])},
                (Addr)&temp_var_for_tac_202,
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:183:19");
        ;
      }
      sumalpha_a += alpha_a[i];
      ;
      sumbeta_a += beta_a[i];
      ;
    }
    double temp_var_for_tac_205, temp_var_for_tac_206, temp_var_for_tac_207,
        temp_var_for_tac_208, temp_var_for_tac_209, temp_var_for_tac_210,
        temp_var_for_tac_211, temp_var_for_tac_212, temp_var_for_tac_213,
        temp_var_for_tac_214;
    double temp_var_for_const_210, temp_var_for_const_211,
        temp_var_for_const_212, temp_var_for_const_213, temp_var_for_const_214,
        temp_var_for_const_215, temp_var_for_const_216, temp_var_for_const_217,
        temp_var_for_const_218;
    temp_var_for_tac_205 = (-(2)) * Beta[0];

    temp_var_for_tac_206 = temp_var_for_tac_205 * a[0];

    temp_var_for_tac_207 = temp_var_for_tac_206 * a[0];

    temp_var_for_tac_208 = temp_var_for_tac_207 - sumbeta_a;

    temp_var_for_tac_209 = temp_var_for_tac_208 + sumalpha_a;

    temp_var_for_tac_210 = Alpha[1] * a[1];

    temp_var_for_tac_211 = temp_var_for_tac_209 + temp_var_for_tac_210;

    temp_var_for_tac_212 = 1.0 + k;

    temp_var_for_tac_213 = temp_var_for_tac_212 * a[0];

    temp_var_for_tac_214 = temp_var_for_tac_211 + temp_var_for_tac_213;

    Fa[0] = temp_var_for_tac_214;
    computeDMul((Addr)&temp_var_for_tac_205,
                {(Addr) &(temp_var_for_const_211 = (-(2))),
                 (Addr) &(temp_var_for_const_210 = Beta[0])},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:188:16");
    computeDMul(
        (Addr)&temp_var_for_tac_206,
        {(Addr)&temp_var_for_tac_205, (Addr) &(temp_var_for_const_212 = a[0])},
        "/home/shijia/Public/testprogram/ETD_S.c_e.c:188:26");
    computeDMul(
        (Addr)&temp_var_for_tac_207,
        {(Addr)&temp_var_for_tac_206, (Addr) &(temp_var_for_const_213 = a[0])},
        "/home/shijia/Public/testprogram/ETD_S.c_e.c:188:33");
    computeDSub((Addr)&temp_var_for_tac_208,
                {(Addr)&temp_var_for_tac_207, (Addr)&sumbeta_a},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:188:40");
    computeDAdd((Addr)&temp_var_for_tac_209,
                {(Addr)&temp_var_for_tac_208, (Addr)&sumalpha_a},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:188:52");
    computeDMul((Addr)&temp_var_for_tac_210,
                {(Addr) &(temp_var_for_const_215 = Alpha[1]),
                 (Addr) &(temp_var_for_const_214 = a[1])},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:189:22");
    computeDAdd((Addr)&temp_var_for_tac_211,
                {(Addr)&temp_var_for_tac_209, (Addr)&temp_var_for_tac_210},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:188:65");
    computeDAdd((Addr)&temp_var_for_tac_212,
                {(Addr) &(temp_var_for_const_216 = 1.0), (Addr)&k},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:189:36");
    computeDMul(
        (Addr)&temp_var_for_tac_213,
        {(Addr)&temp_var_for_tac_212, (Addr) &(temp_var_for_const_217 = a[0])},
        "/home/shijia/Public/testprogram/ETD_S.c_e.c:189:41");
    computeDAdd((Addr)&temp_var_for_tac_214,
                {(Addr)&temp_var_for_tac_211, (Addr)&temp_var_for_tac_213},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:189:29");
    AssignD({(Addr) &(temp_var_for_const_218 = Fa[0])},
            (Addr)&temp_var_for_tac_214,
            "/home/shijia/Public/testprogram/ETD_S.c_e.c:188:11");
    ;
    for (i = 1; i <= N - 2; i++) {
      double temp_var_for_tac_215, temp_var_for_tac_216, temp_var_for_tac_217,
          temp_var_for_tac_218, temp_var_for_tac_219, temp_var_for_tac_220,
          temp_var_for_tac_221, temp_var_for_tac_222, temp_var_for_tac_223;
      double temp_var_for_const_219, temp_var_for_const_220,
          temp_var_for_const_221, temp_var_for_const_222,
          temp_var_for_const_223, temp_var_for_const_224,
          temp_var_for_const_225, temp_var_for_const_226,
          temp_var_for_const_227, temp_var_for_const_228;
      temp_var_for_tac_215 = Beta[i - 1] * a[i - 1];

      temp_var_for_tac_216 = temp_var_for_tac_215 * a[0];

      temp_var_for_tac_217 = Beta[i] * a[i];

      temp_var_for_tac_218 = temp_var_for_tac_217 * a[0];

      temp_var_for_tac_219 = temp_var_for_tac_216 - temp_var_for_tac_218;

      temp_var_for_tac_220 = Alpha[i + 1] * a[i + 1];

      temp_var_for_tac_221 = temp_var_for_tac_219 + temp_var_for_tac_220;

      temp_var_for_tac_222 = k * a[i];

      temp_var_for_tac_223 = temp_var_for_tac_221 + temp_var_for_tac_222;

      Fa[i] = temp_var_for_tac_223;
      computeDMul((Addr)&temp_var_for_tac_215,
                  {(Addr) &(temp_var_for_const_220 = Beta[i - 1]),
                   (Addr) &(temp_var_for_const_219 = a[i - 1])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:191:27");
      computeDMul((Addr)&temp_var_for_tac_216,
                  {(Addr)&temp_var_for_tac_215,
                   (Addr) &(temp_var_for_const_221 = a[0])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:191:38");
      computeDMul((Addr)&temp_var_for_tac_217,
                  {(Addr) &(temp_var_for_const_223 = Beta[i]),
                   (Addr) &(temp_var_for_const_222 = a[i])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:191:55");
      computeDMul((Addr)&temp_var_for_tac_218,
                  {(Addr)&temp_var_for_tac_217,
                   (Addr) &(temp_var_for_const_224 = a[0])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:191:62");
      computeDSub((Addr)&temp_var_for_tac_219,
                  {(Addr)&temp_var_for_tac_216, (Addr)&temp_var_for_tac_218},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:191:45");
      computeDMul((Addr)&temp_var_for_tac_220,
                  {(Addr) &(temp_var_for_const_226 = Alpha[i + 1]),
                   (Addr) &(temp_var_for_const_225 = a[i + 1])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:192:28");
      computeDAdd((Addr)&temp_var_for_tac_221,
                  {(Addr)&temp_var_for_tac_219, (Addr)&temp_var_for_tac_220},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:191:69");
      computeDMul((Addr)&temp_var_for_tac_222,
                  {(Addr)&k, (Addr) &(temp_var_for_const_227 = a[i])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:192:43");
      computeDAdd((Addr)&temp_var_for_tac_223,
                  {(Addr)&temp_var_for_tac_221, (Addr)&temp_var_for_tac_222},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:192:39");
      AssignD({(Addr) &(temp_var_for_const_228 = Fa[i])},
              (Addr)&temp_var_for_tac_223,
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:191:13");
      ;
    }
    double temp_var_for_tac_224, temp_var_for_tac_225, temp_var_for_tac_226,
        temp_var_for_tac_227, temp_var_for_tac_228, temp_var_for_tac_229,
        temp_var_for_tac_230;
    double temp_var_for_const_229, temp_var_for_const_230,
        temp_var_for_const_231, temp_var_for_const_232, temp_var_for_const_233,
        temp_var_for_const_234, temp_var_for_const_235, temp_var_for_const_236;
    temp_var_for_tac_224 = Beta[N - 2] * a[N - 2];

    temp_var_for_tac_225 = temp_var_for_tac_224 * a[0];

    temp_var_for_tac_226 = Beta[N - 1] * a[N - 1];

    temp_var_for_tac_227 = temp_var_for_tac_226 * a[0];

    temp_var_for_tac_228 = temp_var_for_tac_225 - temp_var_for_tac_227;

    temp_var_for_tac_229 = k * a[N - 1];

    temp_var_for_tac_230 = temp_var_for_tac_228 + temp_var_for_tac_229;

    Fa[N - 1] = temp_var_for_tac_230;
    computeDMul((Addr)&temp_var_for_tac_224,
                {(Addr) &(temp_var_for_const_230 = Beta[N - 2]),
                 (Addr) &(temp_var_for_const_229 = a[N - 2])},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:194:29");
    computeDMul(
        (Addr)&temp_var_for_tac_225,
        {(Addr)&temp_var_for_tac_224, (Addr) &(temp_var_for_const_231 = a[0])},
        "/home/shijia/Public/testprogram/ETD_S.c_e.c:194:40");
    computeDMul((Addr)&temp_var_for_tac_226,
                {(Addr) &(temp_var_for_const_233 = Beta[N - 1]),
                 (Addr) &(temp_var_for_const_232 = a[N - 1])},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:194:61");
    computeDMul(
        (Addr)&temp_var_for_tac_227,
        {(Addr)&temp_var_for_tac_226, (Addr) &(temp_var_for_const_234 = a[0])},
        "/home/shijia/Public/testprogram/ETD_S.c_e.c:194:72");
    computeDSub((Addr)&temp_var_for_tac_228,
                {(Addr)&temp_var_for_tac_225, (Addr)&temp_var_for_tac_227},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:194:47");
    computeDMul((Addr)&temp_var_for_tac_229,
                {(Addr)&k, (Addr) &(temp_var_for_const_235 = a[N - 1])},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:195:19");
    computeDAdd((Addr)&temp_var_for_tac_230,
                {(Addr)&temp_var_for_tac_228, (Addr)&temp_var_for_tac_229},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:194:79");
    AssignD({(Addr) &(temp_var_for_const_236 = Fa[N - 1])},
            (Addr)&temp_var_for_tac_230,
            "/home/shijia/Public/testprogram/ETD_S.c_e.c:194:15");
    ;
    /*for(i=0;i<N;i++){
            printf("Fa[%d]=%e\n",i,Fa[i]);
    }*/

    for (i = 0; i < N; i++) {
      double temp_var_for_tac_231, temp_var_for_tac_232, temp_var_for_tac_233;
      double temp_var_for_const_237, temp_var_for_const_238,
          temp_var_for_const_239, temp_var_for_const_240,
          temp_var_for_const_241;
      temp_var_for_tac_231 = phi1[i] * C[i];

      temp_var_for_tac_232 = phi2[i] * Fa[i];

      temp_var_for_tac_233 = temp_var_for_tac_231 + temp_var_for_tac_232;

      b[i] = temp_var_for_tac_233;
      computeDMul((Addr)&temp_var_for_tac_231,
                  {(Addr) &(temp_var_for_const_238 = phi1[i]),
                   (Addr) &(temp_var_for_const_237 = C[i])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:201:22");
      computeDMul((Addr)&temp_var_for_tac_232,
                  {(Addr) &(temp_var_for_const_240 = phi2[i]),
                   (Addr) &(temp_var_for_const_239 = Fa[i])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:201:39");
      computeDAdd((Addr)&temp_var_for_tac_233,
                  {(Addr)&temp_var_for_tac_231, (Addr)&temp_var_for_tac_232},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:201:29");
      AssignD({(Addr) &(temp_var_for_const_241 = b[i])},
              (Addr)&temp_var_for_tac_233,
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:201:12");
      ;
      if (i == 0) {
        double temp_var_for_const_242, temp_var_for_const_243;
        alpha_b[i] = 0.0;
        AssignD({(Addr) &(temp_var_for_const_243 = alpha_b[i])},
                (Addr) &(temp_var_for_const_242 = 0.0),
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:203:20");
        ;
        double temp_var_for_const_244, temp_var_for_const_245;
        beta_b[i] = 0.0;
        AssignD({(Addr) &(temp_var_for_const_245 = beta_b[i])},
                (Addr) &(temp_var_for_const_244 = 0.0),
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:204:19");
        ;
      } else {
        double temp_var_for_tac_234;
        double temp_var_for_const_246, temp_var_for_const_247,
            temp_var_for_const_248;
        temp_var_for_tac_234 = Alpha[i] * b[i];

        alpha_b[i] = temp_var_for_tac_234;
        computeDMul((Addr)&temp_var_for_tac_234,
                    {(Addr) &(temp_var_for_const_247 = Alpha[i]),
                     (Addr) &(temp_var_for_const_246 = b[i])},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:206:31");
        AssignD({(Addr) &(temp_var_for_const_248 = alpha_b[i])},
                (Addr)&temp_var_for_tac_234,
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:206:20");
        ;
        double temp_var_for_tac_235, temp_var_for_tac_236;
        double temp_var_for_const_249, temp_var_for_const_250,
            temp_var_for_const_251, temp_var_for_const_252;
        temp_var_for_tac_235 = Beta[i] * b[i];

        temp_var_for_tac_236 = temp_var_for_tac_235 * b[0];

        beta_b[i] = temp_var_for_tac_236;
        computeDMul((Addr)&temp_var_for_tac_235,
                    {(Addr) &(temp_var_for_const_250 = Beta[i]),
                     (Addr) &(temp_var_for_const_249 = b[i])},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:207:29");
        computeDMul((Addr)&temp_var_for_tac_236,
                    {(Addr)&temp_var_for_tac_235,
                     (Addr) &(temp_var_for_const_251 = b[0])},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:207:36");
        AssignD({(Addr) &(temp_var_for_const_252 = beta_b[i])},
                (Addr)&temp_var_for_tac_236,
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:207:19");
        ;
      }
      sumalpha_b += alpha_b[i];
      ;
      sumbeta_b += beta_b[i];
      ;
    }
    double temp_var_for_tac_239, temp_var_for_tac_240, temp_var_for_tac_241,
        temp_var_for_tac_242, temp_var_for_tac_243, temp_var_for_tac_244,
        temp_var_for_tac_245, temp_var_for_tac_246, temp_var_for_tac_247,
        temp_var_for_tac_248;
    double temp_var_for_const_253, temp_var_for_const_254,
        temp_var_for_const_255, temp_var_for_const_256, temp_var_for_const_257,
        temp_var_for_const_258, temp_var_for_const_259, temp_var_for_const_260,
        temp_var_for_const_261;
    temp_var_for_tac_239 = (-(2)) * Beta[0];

    temp_var_for_tac_240 = temp_var_for_tac_239 * b[0];

    temp_var_for_tac_241 = temp_var_for_tac_240 * b[0];

    temp_var_for_tac_242 = temp_var_for_tac_241 - sumbeta_b;

    temp_var_for_tac_243 = temp_var_for_tac_242 + sumalpha_b;

    temp_var_for_tac_244 = Alpha[1] * b[1];

    temp_var_for_tac_245 = temp_var_for_tac_243 + temp_var_for_tac_244;

    temp_var_for_tac_246 = 1.0 + k;

    temp_var_for_tac_247 = temp_var_for_tac_246 * b[0];

    temp_var_for_tac_248 = temp_var_for_tac_245 + temp_var_for_tac_247;

    Fb[0] = temp_var_for_tac_248;
    computeDMul((Addr)&temp_var_for_tac_239,
                {(Addr) &(temp_var_for_const_254 = (-(2))),
                 (Addr) &(temp_var_for_const_253 = Beta[0])},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:212:16");
    computeDMul(
        (Addr)&temp_var_for_tac_240,
        {(Addr)&temp_var_for_tac_239, (Addr) &(temp_var_for_const_255 = b[0])},
        "/home/shijia/Public/testprogram/ETD_S.c_e.c:212:26");
    computeDMul(
        (Addr)&temp_var_for_tac_241,
        {(Addr)&temp_var_for_tac_240, (Addr) &(temp_var_for_const_256 = b[0])},
        "/home/shijia/Public/testprogram/ETD_S.c_e.c:212:33");
    computeDSub((Addr)&temp_var_for_tac_242,
                {(Addr)&temp_var_for_tac_241, (Addr)&sumbeta_b},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:212:40");
    computeDAdd((Addr)&temp_var_for_tac_243,
                {(Addr)&temp_var_for_tac_242, (Addr)&sumalpha_b},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:212:52");
    computeDMul((Addr)&temp_var_for_tac_244,
                {(Addr) &(temp_var_for_const_258 = Alpha[1]),
                 (Addr) &(temp_var_for_const_257 = b[1])},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:213:22");
    computeDAdd((Addr)&temp_var_for_tac_245,
                {(Addr)&temp_var_for_tac_243, (Addr)&temp_var_for_tac_244},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:212:65");
    computeDAdd((Addr)&temp_var_for_tac_246,
                {(Addr) &(temp_var_for_const_259 = 1.0), (Addr)&k},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:213:36");
    computeDMul(
        (Addr)&temp_var_for_tac_247,
        {(Addr)&temp_var_for_tac_246, (Addr) &(temp_var_for_const_260 = b[0])},
        "/home/shijia/Public/testprogram/ETD_S.c_e.c:213:41");
    computeDAdd((Addr)&temp_var_for_tac_248,
                {(Addr)&temp_var_for_tac_245, (Addr)&temp_var_for_tac_247},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:213:29");
    AssignD({(Addr) &(temp_var_for_const_261 = Fb[0])},
            (Addr)&temp_var_for_tac_248,
            "/home/shijia/Public/testprogram/ETD_S.c_e.c:212:11");
    ;
    for (i = 1; i <= N - 2; i++) {
      double temp_var_for_tac_249, temp_var_for_tac_250, temp_var_for_tac_251,
          temp_var_for_tac_252, temp_var_for_tac_253, temp_var_for_tac_254,
          temp_var_for_tac_255, temp_var_for_tac_256, temp_var_for_tac_257;
      double temp_var_for_const_262, temp_var_for_const_263,
          temp_var_for_const_264, temp_var_for_const_265,
          temp_var_for_const_266, temp_var_for_const_267,
          temp_var_for_const_268, temp_var_for_const_269,
          temp_var_for_const_270, temp_var_for_const_271;
      temp_var_for_tac_249 = Beta[i - 1] * b[i - 1];

      temp_var_for_tac_250 = temp_var_for_tac_249 * b[0];

      temp_var_for_tac_251 = Beta[i] * b[i];

      temp_var_for_tac_252 = temp_var_for_tac_251 * b[0];

      temp_var_for_tac_253 = temp_var_for_tac_250 - temp_var_for_tac_252;

      temp_var_for_tac_254 = Alpha[i + 1] * b[i + 1];

      temp_var_for_tac_255 = temp_var_for_tac_253 + temp_var_for_tac_254;

      temp_var_for_tac_256 = k * b[i];

      temp_var_for_tac_257 = temp_var_for_tac_255 + temp_var_for_tac_256;

      Fb[i] = temp_var_for_tac_257;
      computeDMul((Addr)&temp_var_for_tac_249,
                  {(Addr) &(temp_var_for_const_263 = Beta[i - 1]),
                   (Addr) &(temp_var_for_const_262 = b[i - 1])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:215:27");
      computeDMul((Addr)&temp_var_for_tac_250,
                  {(Addr)&temp_var_for_tac_249,
                   (Addr) &(temp_var_for_const_264 = b[0])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:215:38");
      computeDMul((Addr)&temp_var_for_tac_251,
                  {(Addr) &(temp_var_for_const_266 = Beta[i]),
                   (Addr) &(temp_var_for_const_265 = b[i])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:215:55");
      computeDMul((Addr)&temp_var_for_tac_252,
                  {(Addr)&temp_var_for_tac_251,
                   (Addr) &(temp_var_for_const_267 = b[0])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:215:62");
      computeDSub((Addr)&temp_var_for_tac_253,
                  {(Addr)&temp_var_for_tac_250, (Addr)&temp_var_for_tac_252},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:215:45");
      computeDMul((Addr)&temp_var_for_tac_254,
                  {(Addr) &(temp_var_for_const_269 = Alpha[i + 1]),
                   (Addr) &(temp_var_for_const_268 = b[i + 1])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:216:28");
      computeDAdd((Addr)&temp_var_for_tac_255,
                  {(Addr)&temp_var_for_tac_253, (Addr)&temp_var_for_tac_254},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:215:69");
      computeDMul((Addr)&temp_var_for_tac_256,
                  {(Addr)&k, (Addr) &(temp_var_for_const_270 = b[i])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:216:43");
      computeDAdd((Addr)&temp_var_for_tac_257,
                  {(Addr)&temp_var_for_tac_255, (Addr)&temp_var_for_tac_256},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:216:39");
      AssignD({(Addr) &(temp_var_for_const_271 = Fb[i])},
              (Addr)&temp_var_for_tac_257,
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:215:13");
      ;
    }
    double temp_var_for_tac_258, temp_var_for_tac_259, temp_var_for_tac_260,
        temp_var_for_tac_261, temp_var_for_tac_262, temp_var_for_tac_263,
        temp_var_for_tac_264;
    double temp_var_for_const_272, temp_var_for_const_273,
        temp_var_for_const_274, temp_var_for_const_275, temp_var_for_const_276,
        temp_var_for_const_277, temp_var_for_const_278, temp_var_for_const_279;
    temp_var_for_tac_258 = Beta[N - 2] * b[N - 2];

    temp_var_for_tac_259 = temp_var_for_tac_258 * b[0];

    temp_var_for_tac_260 = Beta[N - 1] * b[N - 1];

    temp_var_for_tac_261 = temp_var_for_tac_260 * b[0];

    temp_var_for_tac_262 = temp_var_for_tac_259 - temp_var_for_tac_261;

    temp_var_for_tac_263 = k * b[N - 1];

    temp_var_for_tac_264 = temp_var_for_tac_262 + temp_var_for_tac_263;

    Fb[N - 1] = temp_var_for_tac_264;
    computeDMul((Addr)&temp_var_for_tac_258,
                {(Addr) &(temp_var_for_const_273 = Beta[N - 2]),
                 (Addr) &(temp_var_for_const_272 = b[N - 2])},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:218:29");
    computeDMul(
        (Addr)&temp_var_for_tac_259,
        {(Addr)&temp_var_for_tac_258, (Addr) &(temp_var_for_const_274 = b[0])},
        "/home/shijia/Public/testprogram/ETD_S.c_e.c:218:40");
    computeDMul((Addr)&temp_var_for_tac_260,
                {(Addr) &(temp_var_for_const_276 = Beta[N - 1]),
                 (Addr) &(temp_var_for_const_275 = b[N - 1])},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:218:61");
    computeDMul(
        (Addr)&temp_var_for_tac_261,
        {(Addr)&temp_var_for_tac_260, (Addr) &(temp_var_for_const_277 = b[0])},
        "/home/shijia/Public/testprogram/ETD_S.c_e.c:218:72");
    computeDSub((Addr)&temp_var_for_tac_262,
                {(Addr)&temp_var_for_tac_259, (Addr)&temp_var_for_tac_261},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:218:47");
    computeDMul((Addr)&temp_var_for_tac_263,
                {(Addr)&k, (Addr) &(temp_var_for_const_278 = b[N - 1])},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:219:19");
    computeDAdd((Addr)&temp_var_for_tac_264,
                {(Addr)&temp_var_for_tac_262, (Addr)&temp_var_for_tac_263},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:218:79");
    AssignD({(Addr) &(temp_var_for_const_279 = Fb[N - 1])},
            (Addr)&temp_var_for_tac_264,
            "/home/shijia/Public/testprogram/ETD_S.c_e.c:218:15");
    ;
    /*for(i=0;i<N;i++){
            printf("Fb[%d]=%e\n",i,Fb[i]);
    }*/

    for (i = 0; i < N; i++) {
      double temp_var_for_tac_265, temp_var_for_tac_266, temp_var_for_tac_267,
          temp_var_for_tac_268, temp_var_for_tac_269;
      double temp_var_for_const_280, temp_var_for_const_281,
          temp_var_for_const_282, temp_var_for_const_283,
          temp_var_for_const_284, temp_var_for_const_285,
          temp_var_for_const_286;
      temp_var_for_tac_265 = phi1[i] * a[i];

      temp_var_for_tac_266 = 2 * Fb[i];

      temp_var_for_tac_267 = temp_var_for_tac_266 - Fc[i];

      temp_var_for_tac_268 = phi2[i] * temp_var_for_tac_267;

      temp_var_for_tac_269 = temp_var_for_tac_265 + temp_var_for_tac_268;

      d[i] = temp_var_for_tac_269;
      computeDMul((Addr)&temp_var_for_tac_265,
                  {(Addr) &(temp_var_for_const_281 = phi1[i]),
                   (Addr) &(temp_var_for_const_280 = a[i])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:225:22");
      computeDMul((Addr)&temp_var_for_tac_266,
                  {(Addr) &(temp_var_for_const_283 = 2),
                   (Addr) &(temp_var_for_const_282 = Fb[i])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:225:44");
      computeDSub((Addr)&temp_var_for_tac_267,
                  {(Addr)&temp_var_for_tac_266,
                   (Addr) &(temp_var_for_const_284 = Fc[i])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:225:52");
      computeDMul((Addr)&temp_var_for_tac_268,
                  {(Addr) &(temp_var_for_const_285 = phi2[i]),
                   (Addr)&temp_var_for_tac_267},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:225:39");
      computeDAdd((Addr)&temp_var_for_tac_269,
                  {(Addr)&temp_var_for_tac_265, (Addr)&temp_var_for_tac_268},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:225:29");
      AssignD({(Addr) &(temp_var_for_const_286 = d[i])},
              (Addr)&temp_var_for_tac_269,
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:225:12");
      ;
      if (i == 0) {
        double temp_var_for_const_287, temp_var_for_const_288;
        alpha_d[i] = 0.0;
        AssignD({(Addr) &(temp_var_for_const_288 = alpha_d[i])},
                (Addr) &(temp_var_for_const_287 = 0.0),
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:227:20");
        ;
        double temp_var_for_const_289, temp_var_for_const_290;
        beta_d[i] = 0.0;
        AssignD({(Addr) &(temp_var_for_const_290 = beta_d[i])},
                (Addr) &(temp_var_for_const_289 = 0.0),
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:228:19");
        ;
      } else {
        double temp_var_for_tac_270;
        double temp_var_for_const_291, temp_var_for_const_292,
            temp_var_for_const_293;
        temp_var_for_tac_270 = Alpha[i] * d[i];

        alpha_d[i] = temp_var_for_tac_270;
        computeDMul((Addr)&temp_var_for_tac_270,
                    {(Addr) &(temp_var_for_const_292 = Alpha[i]),
                     (Addr) &(temp_var_for_const_291 = d[i])},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:230:31");
        AssignD({(Addr) &(temp_var_for_const_293 = alpha_d[i])},
                (Addr)&temp_var_for_tac_270,
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:230:20");
        ;
        double temp_var_for_tac_271, temp_var_for_tac_272;
        double temp_var_for_const_294, temp_var_for_const_295,
            temp_var_for_const_296, temp_var_for_const_297;
        temp_var_for_tac_271 = Beta[i] * d[i];

        temp_var_for_tac_272 = temp_var_for_tac_271 * d[0];

        beta_d[i] = temp_var_for_tac_272;
        computeDMul((Addr)&temp_var_for_tac_271,
                    {(Addr) &(temp_var_for_const_295 = Beta[i]),
                     (Addr) &(temp_var_for_const_294 = d[i])},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:231:29");
        computeDMul((Addr)&temp_var_for_tac_272,
                    {(Addr)&temp_var_for_tac_271,
                     (Addr) &(temp_var_for_const_296 = d[0])},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:231:36");
        AssignD({(Addr) &(temp_var_for_const_297 = beta_d[i])},
                (Addr)&temp_var_for_tac_272,
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:231:19");
        ;
      }
      sumalpha_d += alpha_d[i];
      ;
      sumbeta_d += beta_d[i];
      ;
    }
    double temp_var_for_tac_275, temp_var_for_tac_276, temp_var_for_tac_277,
        temp_var_for_tac_278, temp_var_for_tac_279, temp_var_for_tac_280,
        temp_var_for_tac_281, temp_var_for_tac_282, temp_var_for_tac_283,
        temp_var_for_tac_284;
    double temp_var_for_const_298, temp_var_for_const_299,
        temp_var_for_const_300, temp_var_for_const_301, temp_var_for_const_302,
        temp_var_for_const_303, temp_var_for_const_304, temp_var_for_const_305,
        temp_var_for_const_306;
    temp_var_for_tac_275 = (-(2)) * Beta[0];

    temp_var_for_tac_276 = temp_var_for_tac_275 * d[0];

    temp_var_for_tac_277 = temp_var_for_tac_276 * d[0];

    temp_var_for_tac_278 = temp_var_for_tac_277 - sumbeta_d;

    temp_var_for_tac_279 = temp_var_for_tac_278 + sumalpha_d;

    temp_var_for_tac_280 = Alpha[1] * d[1];

    temp_var_for_tac_281 = temp_var_for_tac_279 + temp_var_for_tac_280;

    temp_var_for_tac_282 = 1.0 + k;

    temp_var_for_tac_283 = temp_var_for_tac_282 * d[0];

    temp_var_for_tac_284 = temp_var_for_tac_281 + temp_var_for_tac_283;

    Fd[0] = temp_var_for_tac_284;
    computeDMul((Addr)&temp_var_for_tac_275,
                {(Addr) &(temp_var_for_const_299 = (-(2))),
                 (Addr) &(temp_var_for_const_298 = Beta[0])},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:236:16");
    computeDMul(
        (Addr)&temp_var_for_tac_276,
        {(Addr)&temp_var_for_tac_275, (Addr) &(temp_var_for_const_300 = d[0])},
        "/home/shijia/Public/testprogram/ETD_S.c_e.c:236:26");
    computeDMul(
        (Addr)&temp_var_for_tac_277,
        {(Addr)&temp_var_for_tac_276, (Addr) &(temp_var_for_const_301 = d[0])},
        "/home/shijia/Public/testprogram/ETD_S.c_e.c:236:33");
    computeDSub((Addr)&temp_var_for_tac_278,
                {(Addr)&temp_var_for_tac_277, (Addr)&sumbeta_d},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:236:40");
    computeDAdd((Addr)&temp_var_for_tac_279,
                {(Addr)&temp_var_for_tac_278, (Addr)&sumalpha_d},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:236:52");
    computeDMul((Addr)&temp_var_for_tac_280,
                {(Addr) &(temp_var_for_const_303 = Alpha[1]),
                 (Addr) &(temp_var_for_const_302 = d[1])},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:237:22");
    computeDAdd((Addr)&temp_var_for_tac_281,
                {(Addr)&temp_var_for_tac_279, (Addr)&temp_var_for_tac_280},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:236:65");
    computeDAdd((Addr)&temp_var_for_tac_282,
                {(Addr) &(temp_var_for_const_304 = 1.0), (Addr)&k},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:237:36");
    computeDMul(
        (Addr)&temp_var_for_tac_283,
        {(Addr)&temp_var_for_tac_282, (Addr) &(temp_var_for_const_305 = d[0])},
        "/home/shijia/Public/testprogram/ETD_S.c_e.c:237:41");
    computeDAdd((Addr)&temp_var_for_tac_284,
                {(Addr)&temp_var_for_tac_281, (Addr)&temp_var_for_tac_283},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:237:29");
    AssignD({(Addr) &(temp_var_for_const_306 = Fd[0])},
            (Addr)&temp_var_for_tac_284,
            "/home/shijia/Public/testprogram/ETD_S.c_e.c:236:11");
    ;
    for (i = 1; i <= N - 2; i++) {
      double temp_var_for_tac_285, temp_var_for_tac_286, temp_var_for_tac_287,
          temp_var_for_tac_288, temp_var_for_tac_289, temp_var_for_tac_290,
          temp_var_for_tac_291, temp_var_for_tac_292, temp_var_for_tac_293;
      double temp_var_for_const_307, temp_var_for_const_308,
          temp_var_for_const_309, temp_var_for_const_310,
          temp_var_for_const_311, temp_var_for_const_312,
          temp_var_for_const_313, temp_var_for_const_314,
          temp_var_for_const_315, temp_var_for_const_316;
      temp_var_for_tac_285 = Beta[i - 1] * d[i - 1];

      temp_var_for_tac_286 = temp_var_for_tac_285 * d[0];

      temp_var_for_tac_287 = Beta[i] * d[i];

      temp_var_for_tac_288 = temp_var_for_tac_287 * d[0];

      temp_var_for_tac_289 = temp_var_for_tac_286 - temp_var_for_tac_288;

      temp_var_for_tac_290 = Alpha[i + 1] * d[i + 1];

      temp_var_for_tac_291 = temp_var_for_tac_289 + temp_var_for_tac_290;

      temp_var_for_tac_292 = k * d[i];

      temp_var_for_tac_293 = temp_var_for_tac_291 + temp_var_for_tac_292;

      Fd[i] = temp_var_for_tac_293;
      computeDMul((Addr)&temp_var_for_tac_285,
                  {(Addr) &(temp_var_for_const_308 = Beta[i - 1]),
                   (Addr) &(temp_var_for_const_307 = d[i - 1])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:239:27");
      computeDMul((Addr)&temp_var_for_tac_286,
                  {(Addr)&temp_var_for_tac_285,
                   (Addr) &(temp_var_for_const_309 = d[0])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:239:38");
      computeDMul((Addr)&temp_var_for_tac_287,
                  {(Addr) &(temp_var_for_const_311 = Beta[i]),
                   (Addr) &(temp_var_for_const_310 = d[i])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:239:55");
      computeDMul((Addr)&temp_var_for_tac_288,
                  {(Addr)&temp_var_for_tac_287,
                   (Addr) &(temp_var_for_const_312 = d[0])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:239:62");
      computeDSub((Addr)&temp_var_for_tac_289,
                  {(Addr)&temp_var_for_tac_286, (Addr)&temp_var_for_tac_288},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:239:45");
      computeDMul((Addr)&temp_var_for_tac_290,
                  {(Addr) &(temp_var_for_const_314 = Alpha[i + 1]),
                   (Addr) &(temp_var_for_const_313 = d[i + 1])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:240:28");
      computeDAdd((Addr)&temp_var_for_tac_291,
                  {(Addr)&temp_var_for_tac_289, (Addr)&temp_var_for_tac_290},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:239:69");
      computeDMul((Addr)&temp_var_for_tac_292,
                  {(Addr)&k, (Addr) &(temp_var_for_const_315 = d[i])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:240:43");
      computeDAdd((Addr)&temp_var_for_tac_293,
                  {(Addr)&temp_var_for_tac_291, (Addr)&temp_var_for_tac_292},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:240:39");
      AssignD({(Addr) &(temp_var_for_const_316 = Fd[i])},
              (Addr)&temp_var_for_tac_293,
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:239:13");
      ;
    }
    double temp_var_for_tac_294, temp_var_for_tac_295, temp_var_for_tac_296,
        temp_var_for_tac_297, temp_var_for_tac_298, temp_var_for_tac_299,
        temp_var_for_tac_300;
    double temp_var_for_const_317, temp_var_for_const_318,
        temp_var_for_const_319, temp_var_for_const_320, temp_var_for_const_321,
        temp_var_for_const_322, temp_var_for_const_323, temp_var_for_const_324;
    temp_var_for_tac_294 = Beta[N - 2] * d[N - 2];

    temp_var_for_tac_295 = temp_var_for_tac_294 * d[0];

    temp_var_for_tac_296 = Beta[N - 1] * d[N - 1];

    temp_var_for_tac_297 = temp_var_for_tac_296 * d[0];

    temp_var_for_tac_298 = temp_var_for_tac_295 - temp_var_for_tac_297;

    temp_var_for_tac_299 = k * d[N - 1];

    temp_var_for_tac_300 = temp_var_for_tac_298 + temp_var_for_tac_299;

    Fd[N - 1] = temp_var_for_tac_300;
    computeDMul((Addr)&temp_var_for_tac_294,
                {(Addr) &(temp_var_for_const_318 = Beta[N - 2]),
                 (Addr) &(temp_var_for_const_317 = d[N - 2])},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:242:29");
    computeDMul(
        (Addr)&temp_var_for_tac_295,
        {(Addr)&temp_var_for_tac_294, (Addr) &(temp_var_for_const_319 = d[0])},
        "/home/shijia/Public/testprogram/ETD_S.c_e.c:242:40");
    computeDMul((Addr)&temp_var_for_tac_296,
                {(Addr) &(temp_var_for_const_321 = Beta[N - 1]),
                 (Addr) &(temp_var_for_const_320 = d[N - 1])},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:242:61");
    computeDMul(
        (Addr)&temp_var_for_tac_297,
        {(Addr)&temp_var_for_tac_296, (Addr) &(temp_var_for_const_322 = d[0])},
        "/home/shijia/Public/testprogram/ETD_S.c_e.c:242:72");
    computeDSub((Addr)&temp_var_for_tac_298,
                {(Addr)&temp_var_for_tac_295, (Addr)&temp_var_for_tac_297},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:242:47");
    computeDMul((Addr)&temp_var_for_tac_299,
                {(Addr)&k, (Addr) &(temp_var_for_const_323 = d[N - 1])},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:243:19");
    computeDAdd((Addr)&temp_var_for_tac_300,
                {(Addr)&temp_var_for_tac_298, (Addr)&temp_var_for_tac_299},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:242:79");
    AssignD({(Addr) &(temp_var_for_const_324 = Fd[N - 1])},
            (Addr)&temp_var_for_tac_300,
            "/home/shijia/Public/testprogram/ETD_S.c_e.c:242:15");
    ;
    /*for(i=0;i<N;i++){
            printf("Fd[%d]=%e\n",i,Fd[i]);
    }*/

    for (i = 0; i < N; i++) {
      double temp_var_for_ext_1;
      double temp_var_for_tac_301, temp_var_for_tac_302, temp_var_for_tac_303,
          temp_var_for_tac_304, temp_var_for_tac_305, temp_var_for_tac_306,
          temp_var_for_tac_307, temp_var_for_tac_308, temp_var_for_tac_309,
          temp_var_for_tac_310;
      double temp_var_for_const_325, temp_var_for_const_326,
          temp_var_for_const_327, temp_var_for_const_328,
          temp_var_for_const_329, temp_var_for_const_330,
          temp_var_for_const_331, temp_var_for_const_332,
          temp_var_for_const_333, temp_var_for_const_334,
          temp_var_for_const_335;
      double temp_var_for_callexp_20;

      temp_var_for_tac_301 = phi3[i] * C[i];

      temp_var_for_callexp_20 = pow(dt, (-(2)));
      temp_var_for_tac_302 = temp_var_for_callexp_20 * L3[i];

      temp_var_for_tac_303 = poly1[i] * Fc[i];

      temp_var_for_tac_304 = Fa[i] + Fb[i];

      temp_var_for_tac_305 = poly2[i] * temp_var_for_tac_304;

      temp_var_for_tac_306 = temp_var_for_tac_303 + temp_var_for_tac_305;

      temp_var_for_tac_307 = poly3[i] * Fd[i];

      temp_var_for_tac_308 = temp_var_for_tac_306 + temp_var_for_tac_307;

      temp_var_for_tac_309 = temp_var_for_tac_302 * temp_var_for_tac_308;

      temp_var_for_tac_310 = temp_var_for_tac_301 + temp_var_for_tac_309;

      temp_var_for_ext_1 = temp_var_for_tac_310;
      computeDMul((Addr)&temp_var_for_tac_301,
                  {(Addr) &(temp_var_for_const_326 = phi3[i]),
                   (Addr) &(temp_var_for_const_325 = C[i])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:251:19");
      computeDMul((Addr)&temp_var_for_tac_302,
                  {(Addr) &(temp_var_for_const_328 = temp_var_for_callexp_20),
                   (Addr) &(temp_var_for_const_327 = L3[i])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:252:23");
      computeDMul((Addr)&temp_var_for_tac_303,
                  {(Addr) &(temp_var_for_const_330 = poly1[i]),
                   (Addr) &(temp_var_for_const_329 = Fc[i])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:252:43");
      computeDAdd((Addr)&temp_var_for_tac_304,
                  {(Addr) &(temp_var_for_const_332 = Fa[i]),
                   (Addr) &(temp_var_for_const_331 = Fb[i])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:252:71");
      computeDMul((Addr)&temp_var_for_tac_305,
                  {(Addr) &(temp_var_for_const_333 = poly2[i]),
                   (Addr)&temp_var_for_tac_304},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:252:62");
      computeDAdd((Addr)&temp_var_for_tac_306,
                  {(Addr)&temp_var_for_tac_303, (Addr)&temp_var_for_tac_305},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:252:51");
      computeDMul((Addr)&temp_var_for_tac_307,
                  {(Addr) &(temp_var_for_const_335 = poly3[i]),
                   (Addr) &(temp_var_for_const_334 = Fd[i])},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:253:43");
      computeDAdd((Addr)&temp_var_for_tac_308,
                  {(Addr)&temp_var_for_tac_306, (Addr)&temp_var_for_tac_307},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:252:80");
      computeDMul((Addr)&temp_var_for_tac_309,
                  {(Addr)&temp_var_for_tac_302, (Addr)&temp_var_for_tac_308},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:252:31");
      computeDAdd((Addr)&temp_var_for_tac_310,
                  {(Addr)&temp_var_for_tac_301, (Addr)&temp_var_for_tac_309},
                  "/home/shijia/Public/testprogram/ETD_S.c_e.c:251:26");
      AssignD({(Addr)&temp_var_for_ext_1}, (Addr)&temp_var_for_tac_310,
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:250:26");
      ; // C[i]
        /*(d)(1)(N)(d[TempNull])(k)(d)(0)(d[0])(d)(1)(N)(d[TempNull])(Beta)(1)(N)(Beta[TempNull])(d)(0)(d[0])(d)(2)(N)(d[TempNull])(Beta)(2)(N)(Beta[TempNull])(d)(0)(d[0])(d)(1)(N)(d[TempNull])(Beta)(1)(N)(Beta[TempNull])(d)(0)(d[0])(d)(2)(N)(d[TempNull])(Beta)(2)(N)(Beta[TempNull])(d)(0)(d[0])(d)(2)(N)(d[TempNull])(Beta)(2)(N)(Beta[TempNull])(d)(2)(N)(d[TempNull])(Beta)(2)(N)(Beta[TempNull])(d)(0)(d[0])(d)(1)(N)(d[TempNull])(Beta)(1)(N)(Beta[TempNull])(d)(1)(N)(d[TempNull])(Beta)(1)(N)(Beta[TempNull])(d)(1)(N)(d[TempNull])(k)(Fd)(i)(Fd[i])(poly3)(i)(poly3[i])(Fb)(i)(Fb[i])(Fa)(i)(Fa[i])(poly2)(i)(poly2[i])(Fc)(i)(Fc[i])(poly1)(i)(poly1[i])(L3)(i)(L3[i])(pow(
         * dt,  -2))(C)(i)(C[i])(phi3)(i)(phi3[i])*/
      double temp_var_for_const_336;
      C[i] = temp_var_for_ext_1;
      AssignD({(Addr) &(temp_var_for_const_336 = C[i])},
              (Addr)&temp_var_for_ext_1,
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:256:12");
      ;
    }
    double temp_var_for_ext_2;
    double temp_var_for_tac_311;
    temp_var_for_tac_311 = t + dt;

    temp_var_for_ext_2 = temp_var_for_tac_311;
    computeDAdd((Addr)&temp_var_for_tac_311, {(Addr)&t, (Addr)&dt},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:259:28");
    AssignD({(Addr)&temp_var_for_ext_2}, (Addr)&temp_var_for_tac_311,
            "/home/shijia/Public/testprogram/ETD_S.c_e.c:259:24");
    ; // t
      /*(Fd)(i)(Fd[i])(poly3)(i)(poly3[i])(Fb)(i)(Fb[i])(Fa)(i)(Fa[i])(poly2)(i)(poly2[i])(Fc)(i)(Fc[i])(poly1)(i)(poly1[i])(L3)(i)(L3[i])(pow(
       * dt,
       * -2))(C)(i)(C[i])(phi3)(i)(phi3[i])(C)(i)(C[i])(phi3)(i)(phi3[i])(Fd)(i)(Fd[i])(poly3)(i)(poly3[i])(Fb)(i)(Fb[i])(Fa)(i)(Fa[i])(poly2)(i)(poly2[i])(Fc)(i)(Fc[i])(poly1)(i)(poly1[i])(L3)(i)(L3[i])(pow(
       * dt,  -2))(L3)(i)(L3[i])(pow( dt,
       * -2))(Fd)(i)(Fd[i])(poly3)(i)(poly3[i])(Fb)(i)(Fb[i])(Fa)(i)(Fa[i])(poly2)(i)(poly2[i])(Fc)(i)(Fc[i])(poly1)(i)(poly1[i])(Fb)(i)(Fb[i])(Fa)(i)(Fa[i])(poly2)(i)(poly2[i])(Fc)(i)(Fc[i])(poly1)(i)(poly1[i])(Fc)(i)(Fc[i])(poly1)(i)(poly1[i])(Fb)(i)(Fb[i])(Fa)(i)(Fa[i])(poly2)(i)(poly2[i])(Fb)(i)(Fb[i])(Fa)(i)(Fa[i])(Fd)(i)(Fd[i])(poly3)(i)(poly3[i])(dt)(t)*/
    t = temp_var_for_ext_2;
    AssignD({(Addr)&t}, (Addr)&temp_var_for_ext_2,
            "/home/shijia/Public/testprogram/ETD_S.c_e.c:265:7");
    ;
    double temp_var_for_const_337;
    sumalpha_d = 0.0;
    AssignD({(Addr)&sumalpha_d}, (Addr) &(temp_var_for_const_337 = 0.0),
            "/home/shijia/Public/testprogram/ETD_S.c_e.c:266:53");
    sumalpha_b = sumalpha_d;
    AssignD({(Addr)&sumalpha_b}, (Addr)&sumalpha_d,
            "/home/shijia/Public/testprogram/ETD_S.c_e.c:266:40");
    sumalpha_a = sumalpha_b;
    AssignD({(Addr)&sumalpha_a}, (Addr)&sumalpha_b,
            "/home/shijia/Public/testprogram/ETD_S.c_e.c:266:27");
    sumalpha = sumalpha_a;
    AssignD({(Addr)&sumalpha}, (Addr)&sumalpha_a,
            "/home/shijia/Public/testprogram/ETD_S.c_e.c:266:14");
    ;
    double temp_var_for_const_338;
    sumbeta_d = 0.0;
    AssignD({(Addr)&sumbeta_d}, (Addr) &(temp_var_for_const_338 = 0.0),
            "/home/shijia/Public/testprogram/ETD_S.c_e.c:267:49");
    sumbeta_b = sumbeta_d;
    AssignD({(Addr)&sumbeta_b}, (Addr)&sumbeta_d,
            "/home/shijia/Public/testprogram/ETD_S.c_e.c:267:37");
    sumbeta_a = sumbeta_b;
    AssignD({(Addr)&sumbeta_a}, (Addr)&sumbeta_b,
            "/home/shijia/Public/testprogram/ETD_S.c_e.c:267:25");
    sumbeta = sumbeta_a;
    AssignD({(Addr)&sumbeta}, (Addr)&sumbeta_a,
            "/home/shijia/Public/testprogram/ETD_S.c_e.c:267:13");
    ;


    ;
  }

  for (i = 0; i < N; i++) {
    printf("C[%d]=%e\n", i, C[i]);
  }
  double temp_var_for_const_340;
  end = clock();
  AssignD({(Addr)&end}, (Addr) &(temp_var_for_const_340 = clock()),
          "/home/shijia/Public/testprogram/ETD_S.c_e.c:274:7");
  ;
  double temp_var_for_tac_313, temp_var_for_tac_314;
  double temp_var_for_const_341;
  temp_var_for_tac_313 = end - start;

  temp_var_for_tac_314 = temp_var_for_tac_313 / CLOCKS_PER_SEC;

  totaltime = temp_var_for_tac_314;
  computeDSub((Addr)&temp_var_for_tac_313, {(Addr)&end, (Addr)&start},
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:275:20");
  computeDDiv((Addr)&temp_var_for_tac_314,
              {(Addr)&temp_var_for_tac_313,
               (Addr) &(temp_var_for_const_341 = CLOCKS_PER_SEC)},
              "/home/shijia/Public/testprogram/ETD_S.c_e.c:275:29");
  AssignD({(Addr)&totaltime}, (Addr)&temp_var_for_tac_314,
          "/home/shijia/Public/testprogram/ETD_S.c_e.c:275:13");
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
