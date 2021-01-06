#include "../ScDebug/scdebug.h"
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
#define TIME 100

int main(int argc, char *argv[])
{
    // int N = atoi(argv[1]);	//从运行命令中给参数N的值
    // double TIME = atoi(argv[2]);
    clock_t start, end;
    double totaltime;
    start = clock();
    int i;
    double sumalpha = 0.0, sumalpha_a = 0.0, sumalpha_b = 0.0, sumalpha_d = 0.0;
    double sumbeta = 0.0, sumbeta_a = 0.0, sumbeta_b = 0.0, sumbeta_d = 0.0;
    double dt = 1.0e-1;
    double t = 0.0, k = 0.0;

    double Vat = 1.205e-29; // m^3。1.205e-29m^3=1.205e-23cm^3
    // cout<<"Vat="<<Vat<<"\n"<<endl;
    double EFvac = 1.77; //空位的形成能eV
    double EMvac = 1.1;  //空位的迁移能eV
    double Dvac = 1.0e-6 * exp((0 - EMvac) / (KB * T));
    double temp_var_for_const_0, temp_var_for_const_1, temp_var_for_const_2,
        temp_var_for_const_3;
    double temp_var_for_tac_0, temp_var_for_tac_1, temp_var_for_tac_2;
    computeDSub((Addr)&temp_var_for_tac_0,
                {(Addr) & (temp_var_for_const_0 = 0), (Addr)&EMvac},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:42:47");
    computeDMul((Addr)&temp_var_for_tac_1, {(Addr) & (temp_var_for_const_2 = KB), (Addr) & (temp_var_for_const_1 = T)},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:42:41");
    double temp_var_for_callexp_0 =
        exp(getFVbyShadow<double>((Addr)&temp_var_for_tac_2));
    CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
    computeDDiv(
        (Addr)&temp_var_for_tac_2,
        {(Addr)&temp_var_for_tac_0, (Addr)&temp_var_for_tac_1},
        "/home/shijia/Public/testprogram/ETD_S.c_e.c:42:23"); // m^2/s。1.0e-6*exp(-EMvac/(KB*T))m^2/s
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
    C[0] = Cinit;
    computeDMul((Addr)&C[0], {(Addr) & (temp_var_for_const_3 = 1.0e-6), (Addr)&temp_var_for_callexp_0},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:86:7");
    // C[0] = Cinit*at2cb;                 //atom-1转换成cm

    double Alpha0, Beta0;
    Beta0 = Alpha0 = pow((48.0 * PI * PI / Vat / Vat), 1.0 / 3.0) * Dvac;
    double temp_var_for_const_4, temp_var_for_const_5, temp_var_for_const_6,
        temp_var_for_const_7, temp_var_for_const_8;
    double temp_var_for_tac_3, temp_var_for_tac_4, temp_var_for_tac_5,
        temp_var_for_tac_6;
    computeDMul((Addr)&temp_var_for_tac_3, {(Addr) & (temp_var_for_const_5 = 48.0), (Addr) & (temp_var_for_const_4 = PI), (Addr) & (temp_var_for_const_6 = PI)},
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
    computeDDiv((Addr)&temp_var_for_tac_6, {(Addr) & (temp_var_for_const_8 = 1.0), (Addr) & (temp_var_for_const_7 = 3.0)},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:90:64");
    computeDMul((Addr)&Alpha0, {(Addr)&temp_var_for_callexp_1, (Addr)&Dvac},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:90:17");
    AssignD({(Addr)&Beta0}, (Addr)&Alpha0,
            "/home/shijia/Public/testprogram/ETD_S.c_e.c:90:8");
    for (i = 0; i < N; i++)
    {
        r[i] = pow((3.0 * (i + 1.0) * Vat / (4 * PI)), 1.0 / 3.0) * 1.0;
        double temp_var_for_const_9, temp_var_for_const_10, temp_var_for_const_11,
            temp_var_for_const_12, temp_var_for_const_13, temp_var_for_const_14,
            temp_var_for_const_15, temp_var_for_const_16;
        double temp_var_for_tac_7, temp_var_for_tac_8, temp_var_for_tac_9,
            temp_var_for_tac_10, temp_var_for_tac_11;
        computeDAdd((Addr)&temp_var_for_tac_7,
                    {(Addr) & (temp_var_for_const_10 = i),
                     (Addr) & (temp_var_for_const_9 = 1.0)},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:93:19");
        computeDMul((Addr)&temp_var_for_tac_8,
                    {(Addr) & (temp_var_for_const_11 = 3.0),
                     (Addr)&temp_var_for_tac_7, (Addr)&Vat},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:93:42");
        computeDMul((Addr)&temp_var_for_tac_9,
                    {(Addr) & (temp_var_for_const_13 = 4),
                     (Addr) & (temp_var_for_const_12 = PI)},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:93:37");
        computeDDiv((Addr)&temp_var_for_tac_10,
                    {(Addr)&temp_var_for_tac_8, (Addr)&temp_var_for_tac_9},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:93:54");
        double temp_var_for_callexp_2 =
            pow(getFVbyShadow<double>((Addr)&temp_var_for_tac_10),
                getFVbyShadow<double>((Addr)&temp_var_for_tac_11));
        CallStackPop((Addr)&temp_var_for_callexp_2, getTop(temp_var_for_callexp_2));
        computeDDiv((Addr)&temp_var_for_tac_11,
                    {(Addr) & (temp_var_for_const_15 = 1.0),
                     (Addr) & (temp_var_for_const_14 = 3.0)},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:93:61");
        computeDMul((Addr)&r[i], {(Addr)&temp_var_for_callexp_2, (Addr) & (temp_var_for_const_16 = 1.0)},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:93:8"); // nm
        EBvac[i] = EFvac - 2.0 * Gama * Vat / r[i];
        double temp_var_for_const_17;
        double temp_var_for_tac_12, temp_var_for_tac_13;
        computeDMul(
            (Addr)&temp_var_for_tac_12,
            {(Addr) & (temp_var_for_const_17 = 2.0), (Addr)&Gama, (Addr)&Vat},
            "/home/shijia/Public/testprogram/ETD_S.c_e.c:94:38");
        computeDDiv((Addr)&temp_var_for_tac_13,
                    {(Addr)&temp_var_for_tac_12, (Addr)&r[i]},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:94:20");
        computeDSub(
            (Addr)&EBvac[i], {(Addr)&EFvac, (Addr)&temp_var_for_tac_13},
            "/home/shijia/Public/testprogram/ETD_S.c_e.c:94:12"); // eV空位缺陷结合能
        Alpha[i] =
            Alpha0 * pow((i + 1.0), 1.0 / 3.0) * exp((0 - EBvac[i]) / (KB * T));
        double temp_var_for_const_18, temp_var_for_const_19, temp_var_for_const_20,
            temp_var_for_const_21, temp_var_for_const_22, temp_var_for_const_23,
            temp_var_for_const_24;
        double temp_var_for_tac_14, temp_var_for_tac_15, temp_var_for_tac_16,
            temp_var_for_tac_17, temp_var_for_tac_18, temp_var_for_tac_19;
        computeDAdd((Addr)&temp_var_for_tac_14,
                    {(Addr) & (temp_var_for_const_19 = i),
                     (Addr) & (temp_var_for_const_18 = 1.0)},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:95:42");
        double temp_var_for_callexp_3 =
            pow(getFVbyShadow<double>((Addr)&temp_var_for_tac_14),
                getFVbyShadow<double>((Addr)&temp_var_for_tac_15));
        CallStackPop((Addr)&temp_var_for_callexp_3, getTop(temp_var_for_callexp_3));
        computeDDiv((Addr)&temp_var_for_tac_15,
                    {(Addr) & (temp_var_for_const_21 = 1.0),
                     (Addr) & (temp_var_for_const_20 = 3.0)},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:95:21");
        computeDMul((Addr)&temp_var_for_tac_16,
                    {(Addr)&Alpha0, (Addr)&temp_var_for_callexp_3},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:95:58");
        computeDSub((Addr)&temp_var_for_tac_17,
                    {(Addr) & (temp_var_for_const_22 = 0), (Addr)&EBvac[i]},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:95:76");
        computeDMul((Addr)&temp_var_for_tac_18,
                    {(Addr) & (temp_var_for_const_24 = KB),
                     (Addr) & (temp_var_for_const_23 = T)},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:95:70");
        double temp_var_for_callexp_4 =
            exp(getFVbyShadow<double>((Addr)&temp_var_for_tac_19));
        CallStackPop((Addr)&temp_var_for_callexp_4, getTop(temp_var_for_callexp_4));
        computeDDiv((Addr)&temp_var_for_tac_19,
                    {(Addr)&temp_var_for_tac_17, (Addr)&temp_var_for_tac_18},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:95:49");
        computeDMul((Addr)&Alpha[i],
                    {(Addr)&temp_var_for_tac_16, (Addr)&temp_var_for_callexp_4},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:95:12");
        Beta[i] = Beta0 * pow((i + 1.0), 1.0 / 3.0);
        double temp_var_for_const_25, temp_var_for_const_26, temp_var_for_const_27,
            temp_var_for_const_28;
        double temp_var_for_tac_20, temp_var_for_tac_21;
        computeDAdd((Addr)&temp_var_for_tac_20,
                    {(Addr) & (temp_var_for_const_26 = i),
                     (Addr) & (temp_var_for_const_25 = 1.0)},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:96:40");
        double temp_var_for_callexp_5 =
            pow(getFVbyShadow<double>((Addr)&temp_var_for_tac_20),
                getFVbyShadow<double>((Addr)&temp_var_for_tac_21));
        CallStackPop((Addr)&temp_var_for_callexp_5, getTop(temp_var_for_callexp_5));
        computeDDiv((Addr)&temp_var_for_tac_21,
                    {(Addr) & (temp_var_for_const_28 = 1.0),
                     (Addr) & (temp_var_for_const_27 = 3.0)},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:96:19");
        computeDMul((Addr)&Beta[i], {(Addr)&Beta0, (Addr)&temp_var_for_callexp_5},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:96:11"); //公式2
        int temp_var_for_ext_0;
        temp_var_for_ext_0 = i == 0;
        if (temp_var_for_ext_0)
        {
            L3[0] = (0 - pow((1.0 + k), -(0 - 3.0)));
            double temp_var_for_const_29, temp_var_for_const_30,
                temp_var_for_const_31, temp_var_for_const_32;
            double temp_var_for_tac_22, temp_var_for_tac_23;
            computeDAdd((Addr)&temp_var_for_tac_22,
                        {(Addr) & (temp_var_for_const_29 = 1.0), (Addr)&k},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:101:38");
            double temp_var_for_callexp_6 =
                pow(getFVbyShadow<double>((Addr)&temp_var_for_tac_22),
                    getFVbyShadow<double>((Addr) & ((temp_var_for_tac_23))));
            CallStackPop((Addr)&temp_var_for_callexp_6,
                         getTop(temp_var_for_callexp_6));
            computeDSub((Addr)&temp_var_for_tac_23,
                        {(Addr) & (temp_var_for_const_31 = 0),
                         (Addr) & (temp_var_for_const_30 = 3.0)},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:101:15");
            computeDSub((Addr)&L3[0], {(Addr) & (temp_var_for_const_32 = 0), (Addr)&temp_var_for_callexp_6},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:101:10");
            phi1[0] = exp((0 - dt) * (1.0 + k) / 2);
            double temp_var_for_const_33, temp_var_for_const_34,
                temp_var_for_const_35;
            double temp_var_for_tac_24, temp_var_for_tac_25, temp_var_for_tac_26;
            computeDSub((Addr)&temp_var_for_tac_24,
                        {(Addr) & (temp_var_for_const_33 = 0), (Addr)&dt},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:102:34");
            computeDAdd((Addr)&temp_var_for_tac_25,
                        {(Addr) & (temp_var_for_const_34 = 1.0), (Addr)&k},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:102:27");
            computeDMul((Addr)&temp_var_for_tac_26,
                        {(Addr)&temp_var_for_tac_24, (Addr)&temp_var_for_tac_25},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:102:39");

            computeDDiv((Addr)&phi1[0], {(Addr)&temp_var_for_tac_26, (Addr) & (temp_var_for_const_35 = 2)},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:102:12");
            phi2[0] = (1.0 - exp((0 - dt) * (1.0 + k) / 2)) / (1.0 + k);
            double temp_var_for_const_36, temp_var_for_const_37,
                temp_var_for_const_38, temp_var_for_const_39, temp_var_for_const_40;
            double temp_var_for_tac_27, temp_var_for_tac_28, temp_var_for_tac_29,
                temp_var_for_tac_30, temp_var_for_tac_31, temp_var_for_tac_32;
            computeDSub((Addr)&temp_var_for_tac_27,
                        {(Addr) & (temp_var_for_const_36 = 0), (Addr)&dt},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:103:41");
            double temp_var_for_callexp_7 =
                exp(getFVbyShadow<double>((Addr)&temp_var_for_tac_27));
            CallStackPop((Addr)&temp_var_for_callexp_7,
                         getTop(temp_var_for_callexp_7));
            computeDAdd((Addr)&temp_var_for_tac_28,
                        {(Addr) & (temp_var_for_const_37 = 1.0), (Addr)&k},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:103:34");
            computeDMul((Addr)&temp_var_for_tac_29,
                        {(Addr)&temp_var_for_tac_27, (Addr)&temp_var_for_tac_28},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:103:46");
            double temp_var_for_callexp_8 =
                exp(getFVbyShadow<double>((Addr)&temp_var_for_tac_30));
            CallStackPop((Addr)&temp_var_for_callexp_8,
                         getTop(temp_var_for_callexp_8));
            computeDDiv(
                (Addr)&temp_var_for_tac_30,
                {(Addr)&temp_var_for_tac_29, (Addr) & (temp_var_for_const_38 = 2)},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:103:19");
            computeDSub((Addr)&temp_var_for_tac_31,
                        {(Addr) & (temp_var_for_const_39 = 1.0),
                         (Addr)&temp_var_for_callexp_8},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:103:59");
            computeDAdd((Addr)&temp_var_for_tac_32,
                        {(Addr) & (temp_var_for_const_40 = 1.0), (Addr)&k},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:103:52");
            computeDDiv((Addr)&phi2[0],
                        {(Addr)&temp_var_for_tac_31, (Addr)&temp_var_for_tac_32},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:103:12");
            phi3[0] = exp((0 - dt) * (1.0 + k));
            double temp_var_for_const_41, temp_var_for_const_42;
            double temp_var_for_tac_33, temp_var_for_tac_34;
            computeDSub((Addr)&temp_var_for_tac_33,
                        {(Addr) & (temp_var_for_const_41 = 0), (Addr)&dt},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:104:34");
            computeDAdd((Addr)&temp_var_for_tac_34,
                        {(Addr) & (temp_var_for_const_42 = 1.0), (Addr)&k},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:104:27");

            computeDMul((Addr)&phi3[0],
                        {(Addr)&temp_var_for_tac_33, (Addr)&temp_var_for_tac_34},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:104:12");
            poly1[0] = (0 - 4.0) + dt * (1.0 + k) +
                       exp((0 - dt) * (1.0 + k)) * (4 + 3.0 * dt * (1.0 + k) +
                                                    dt * dt * (1.0 + k) * (1.0 + k));
            double temp_var_for_const_43, temp_var_for_const_44,
                temp_var_for_const_45, temp_var_for_const_46, temp_var_for_const_47,
                temp_var_for_const_48, temp_var_for_const_49, temp_var_for_const_50,
                temp_var_for_const_51, temp_var_for_const_52;
            double temp_var_for_tac_35, temp_var_for_tac_36, temp_var_for_tac_37,
                temp_var_for_tac_38, temp_var_for_tac_39, temp_var_for_tac_40,
                temp_var_for_tac_41, temp_var_for_tac_42, temp_var_for_tac_43,
                temp_var_for_tac_44, temp_var_for_tac_45, temp_var_for_tac_46,
                temp_var_for_tac_47, temp_var_for_tac_48, temp_var_for_tac_49,
                temp_var_for_tac_50, temp_var_for_tac_51, temp_var_for_tac_52;
            computeDSub((Addr)&temp_var_for_tac_35,
                        {(Addr) & (temp_var_for_const_44 = 0),
                         (Addr) & (temp_var_for_const_43 = 4.0)},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:105:35");
            double temp_var_for_callexp_9 =
                exp(getFVbyShadow<double>((Addr)&temp_var_for_tac_35));
            CallStackPop((Addr)&temp_var_for_callexp_9,
                         getTop(temp_var_for_callexp_9));
            computeDAdd((Addr)&temp_var_for_tac_36,
                        {(Addr) & (temp_var_for_const_45 = 1.0), (Addr)&k},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:105:28");
            computeDMul((Addr)&temp_var_for_tac_37,
                        {(Addr)&dt, (Addr)&temp_var_for_tac_36},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:105:23");
            computeDAdd((Addr)&temp_var_for_tac_38,
                        {(Addr)&temp_var_for_tac_35, (Addr)&temp_var_for_tac_37},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:105:49");
            computeDSub((Addr)&temp_var_for_tac_39,
                        {(Addr) & (temp_var_for_const_46 = 0), (Addr)&dt},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:105:62");
            computeDAdd((Addr)&temp_var_for_tac_40,
                        {(Addr) & (temp_var_for_const_47 = 1.0), (Addr)&k},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:105:55");
            computeDMul((Addr)&temp_var_for_tac_41,
                        {(Addr)&temp_var_for_tac_39, (Addr)&temp_var_for_tac_40},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:105:79");
            computeDMul((Addr)&temp_var_for_tac_42,
                        {(Addr) & (temp_var_for_const_48 = 3.0), (Addr)&dt},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:105:91");
            computeDAdd((Addr)&temp_var_for_tac_43,
                        {(Addr) & (temp_var_for_const_49 = 1.0), (Addr)&k},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:105:84");
            computeDMul((Addr)&temp_var_for_tac_44,
                        {(Addr)&temp_var_for_tac_42, (Addr)&temp_var_for_tac_43},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:105:73");
            computeDAdd(
                (Addr)&temp_var_for_tac_45,
                {(Addr) & (temp_var_for_const_50 = 4), (Addr)&temp_var_for_tac_44},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:105:101");
            computeDMul((Addr)&temp_var_for_tac_46, {(Addr)&dt, (Addr)&dt},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:105:113");
            computeDAdd((Addr)&temp_var_for_tac_47,
                        {(Addr) & (temp_var_for_const_51 = 1.0), (Addr)&k},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:105:106");
            computeDMul((Addr)&temp_var_for_tac_48,
                        {(Addr)&temp_var_for_tac_46, (Addr)&temp_var_for_tac_47},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:105:125");
            computeDAdd((Addr)&temp_var_for_tac_49,
                        {(Addr) & (temp_var_for_const_52 = 1.0), (Addr)&k},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:105:118");
            computeDMul((Addr)&temp_var_for_tac_50,
                        {(Addr)&temp_var_for_tac_48, (Addr)&temp_var_for_tac_49},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:105:96");
            double temp_var_for_callexp_10 =
                exp(getFVbyShadow<double>((Addr)&temp_var_for_tac_41));
            CallStackPop((Addr)&temp_var_for_callexp_10,
                         getTop(temp_var_for_callexp_10));
            computeDAdd((Addr)&temp_var_for_tac_51,
                        {(Addr)&temp_var_for_tac_45, (Addr)&temp_var_for_tac_50},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:105:68");
            computeDMul((Addr)&temp_var_for_tac_52,
                        {(Addr)&temp_var_for_callexp_10, (Addr)&temp_var_for_tac_51},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:105:40");
            computeDAdd((Addr)&poly1[0],
                        {(Addr)&temp_var_for_tac_38, (Addr)&temp_var_for_tac_52},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:105:13");
            poly2[0] = 4.0 - 2.0 * dt * (1.0 + k) +
                       exp((0 - dt) * (1.0 + k)) * (-4 - 2.0 * dt * (1.0 + k));
            double temp_var_for_const_53, temp_var_for_const_54,
                temp_var_for_const_55, temp_var_for_const_56, temp_var_for_const_57,
                temp_var_for_const_58, temp_var_for_const_59, temp_var_for_const_60;
            double temp_var_for_tac_53, temp_var_for_tac_54, temp_var_for_tac_55,
                temp_var_for_tac_56, temp_var_for_tac_57, temp_var_for_tac_58,
                temp_var_for_tac_59, temp_var_for_tac_60, temp_var_for_tac_61,
                temp_var_for_tac_62, temp_var_for_tac_63, temp_var_for_tac_64;
            computeDMul((Addr)&temp_var_for_tac_53,
                        {(Addr) & (temp_var_for_const_53 = 2.0), (Addr)&dt},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:34");
            computeDAdd((Addr)&temp_var_for_tac_54,
                        {(Addr) & (temp_var_for_const_54 = 1.0), (Addr)&k},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:27");
            computeDMul((Addr)&temp_var_for_tac_55,
                        {(Addr)&temp_var_for_tac_53, (Addr)&temp_var_for_tac_54},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:17");
            computeDSub(
                (Addr)&temp_var_for_tac_56,
                {(Addr) & (temp_var_for_const_55 = 4.0), (Addr)&temp_var_for_tac_55},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:48");
            computeDSub((Addr)&temp_var_for_tac_57,
                        {(Addr) & (temp_var_for_const_56 = 0), (Addr)&dt},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:61");
            computeDAdd((Addr)&temp_var_for_tac_58,
                        {(Addr) & (temp_var_for_const_57 = 1.0), (Addr)&k},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:54");
            computeDMul((Addr)&temp_var_for_tac_59,
                        {(Addr)&temp_var_for_tac_57, (Addr)&temp_var_for_tac_58},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:78");
            computeDMul((Addr)&temp_var_for_tac_60,
                        {(Addr) & (temp_var_for_const_58 = 2.0), (Addr)&dt},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:90");
            computeDAdd((Addr)&temp_var_for_tac_61,
                        {(Addr) & (temp_var_for_const_59 = 1.0), (Addr)&k},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:83");
            computeDMul((Addr)&temp_var_for_tac_62,
                        {(Addr)&temp_var_for_tac_60, (Addr)&temp_var_for_tac_61},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:73");
            double temp_var_for_callexp_11 =
                exp(getFVbyShadow<double>((Addr)&temp_var_for_tac_59));
            CallStackPop((Addr)&temp_var_for_callexp_11,
                         getTop(temp_var_for_callexp_11));
            computeDSub((Addr)&temp_var_for_tac_63,
                        {(Addr) & (temp_var_for_const_60 = (-(4))),
                         (Addr)&temp_var_for_tac_62},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:67");
            computeDMul((Addr)&temp_var_for_tac_64,
                        {(Addr)&temp_var_for_callexp_11, (Addr)&temp_var_for_tac_63},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:39");
            computeDAdd((Addr)&poly2[0],
                        {(Addr)&temp_var_for_tac_56, (Addr)&temp_var_for_tac_64},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:106:13");
            poly3[0] = (0 - 4.0) + 3.0 * dt * (1.0 + k) -
                       dt * dt * (1.0 + k) * (1.0 + k) +
                       exp((0 - dt) * (1.0 + k)) * (4 + dt * (1.0 + k));
            double temp_var_for_const_61, temp_var_for_const_62,
                temp_var_for_const_63, temp_var_for_const_64, temp_var_for_const_65,
                temp_var_for_const_66, temp_var_for_const_67, temp_var_for_const_68,
                temp_var_for_const_69, temp_var_for_const_70;
            double temp_var_for_tac_65, temp_var_for_tac_66, temp_var_for_tac_67,
                temp_var_for_tac_68, temp_var_for_tac_69, temp_var_for_tac_70,
                temp_var_for_tac_71, temp_var_for_tac_72, temp_var_for_tac_73,
                temp_var_for_tac_74, temp_var_for_tac_75, temp_var_for_tac_76,
                temp_var_for_tac_77, temp_var_for_tac_78, temp_var_for_tac_79,
                temp_var_for_tac_80, temp_var_for_tac_81, temp_var_for_tac_82;
            computeDSub((Addr)&temp_var_for_tac_65,
                        {(Addr) & (temp_var_for_const_62 = 0),
                         (Addr) & (temp_var_for_const_61 = 4.0)},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:29");
            computeDMul((Addr)&temp_var_for_tac_66,
                        {(Addr) & (temp_var_for_const_63 = 3.0), (Addr)&dt},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:41");
            computeDAdd((Addr)&temp_var_for_tac_67,
                        {(Addr) & (temp_var_for_const_64 = 1.0), (Addr)&k},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:34");
            computeDMul((Addr)&temp_var_for_tac_68,
                        {(Addr)&temp_var_for_tac_66, (Addr)&temp_var_for_tac_67},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:23");
            computeDAdd((Addr)&temp_var_for_tac_69,
                        {(Addr)&temp_var_for_tac_65, (Addr)&temp_var_for_tac_68},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:51");
            computeDMul((Addr)&temp_var_for_tac_70, {(Addr)&dt, (Addr)&dt},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:63");
            computeDAdd((Addr)&temp_var_for_tac_71,
                        {(Addr) & (temp_var_for_const_65 = 1.0), (Addr)&k},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:56");
            computeDMul((Addr)&temp_var_for_tac_72,
                        {(Addr)&temp_var_for_tac_70, (Addr)&temp_var_for_tac_71},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:75");
            computeDAdd((Addr)&temp_var_for_tac_73,
                        {(Addr) & (temp_var_for_const_66 = 1.0), (Addr)&k},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:68");
            computeDMul((Addr)&temp_var_for_tac_74,
                        {(Addr)&temp_var_for_tac_72, (Addr)&temp_var_for_tac_73},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:46");
            computeDSub((Addr)&temp_var_for_tac_75,
                        {(Addr)&temp_var_for_tac_69, (Addr)&temp_var_for_tac_74},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:89");
            computeDSub((Addr)&temp_var_for_tac_76,
                        {(Addr) & (temp_var_for_const_67 = 0), (Addr)&dt},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:102");
            computeDAdd((Addr)&temp_var_for_tac_77,
                        {(Addr) & (temp_var_for_const_68 = 1.0), (Addr)&k},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:95");
            computeDMul((Addr)&temp_var_for_tac_78,
                        {(Addr)&temp_var_for_tac_76, (Addr)&temp_var_for_tac_77},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:125");
            computeDAdd((Addr)&temp_var_for_tac_79,
                        {(Addr) & (temp_var_for_const_69 = 1.0), (Addr)&k},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:118");
            computeDMul((Addr)&temp_var_for_tac_80,
                        {(Addr)&dt, (Addr)&temp_var_for_tac_79},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:113");
            double temp_var_for_callexp_12 =
                exp(getFVbyShadow<double>((Addr)&temp_var_for_tac_78));
            CallStackPop((Addr)&temp_var_for_callexp_12,
                         getTop(temp_var_for_callexp_12));
            computeDAdd(
                (Addr)&temp_var_for_tac_81,
                {(Addr) & (temp_var_for_const_70 = 4), (Addr)&temp_var_for_tac_80},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:108");
            computeDMul((Addr)&temp_var_for_tac_82,
                        {(Addr)&temp_var_for_callexp_12, (Addr)&temp_var_for_tac_81},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:80");
            computeDAdd((Addr)&poly3[0],
                        {(Addr)&temp_var_for_tac_75, (Addr)&temp_var_for_tac_82},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:107:13");
        }
        else
        {
            L3[i] = (0 - pow((Alpha[i] + k), -3));
            double temp_var_for_const_71;
            double temp_var_for_tac_83;
            double temp_var_for_callexp_13 =
                pow(getFVbyShadow<double>((Addr)&temp_var_for_tac_83),
                    -3.0);
            CallStackPop((Addr)&temp_var_for_callexp_13,
                         getTop(temp_var_for_callexp_13));
            computeDAdd((Addr)&temp_var_for_tac_83, {(Addr)&Alpha[i], (Addr)&k},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:111:15");
            computeDSub((Addr)&L3[i], {(Addr) & (temp_var_for_const_71 = 0), (Addr)&temp_var_for_callexp_13},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:111:10");
            phi1[i] = exp((0 - dt) * (Alpha[i] + k) / 2);
            double temp_var_for_const_72, temp_var_for_const_73;
            double temp_var_for_tac_84, temp_var_for_tac_85, temp_var_for_tac_86;
            computeDSub((Addr)&temp_var_for_tac_84,
                        {(Addr) & (temp_var_for_const_72 = 0), (Addr)&dt},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:112:39");
            computeDAdd((Addr)&temp_var_for_tac_85, {(Addr)&Alpha[i], (Addr)&k},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:112:27");
            computeDMul((Addr)&temp_var_for_tac_86,
                        {(Addr)&temp_var_for_tac_84, (Addr)&temp_var_for_tac_85},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:112:44");

            computeDDiv((Addr)&phi1[i], {(Addr)&temp_var_for_tac_86, (Addr) & (temp_var_for_const_73 = 2)},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:112:12");
            phi2[i] = (1.0 - exp((0 - dt) * (Alpha[i] + k) / 2)) / (Alpha[i] + k);
            double temp_var_for_const_74, temp_var_for_const_75,
                temp_var_for_const_76;
            double temp_var_for_tac_87, temp_var_for_tac_88, temp_var_for_tac_89,
                temp_var_for_tac_90, temp_var_for_tac_91, temp_var_for_tac_92;
            computeDSub((Addr)&temp_var_for_tac_87,
                        {(Addr) & (temp_var_for_const_74 = 0), (Addr)&dt},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:113:46");
            double temp_var_for_callexp_14 =
                exp(getFVbyShadow<double>((Addr)&temp_var_for_tac_87));
            CallStackPop((Addr)&temp_var_for_callexp_14,
                         getTop(temp_var_for_callexp_14));
            computeDAdd((Addr)&temp_var_for_tac_88, {(Addr)&Alpha[i], (Addr)&k},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:113:34");
            computeDMul((Addr)&temp_var_for_tac_89,
                        {(Addr)&temp_var_for_tac_87, (Addr)&temp_var_for_tac_88},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:113:51");
            double temp_var_for_callexp_15 =
                exp(getFVbyShadow<double>((Addr)&temp_var_for_tac_90));
            CallStackPop((Addr)&temp_var_for_callexp_15,
                         getTop(temp_var_for_callexp_15));
            computeDDiv(
                (Addr)&temp_var_for_tac_90,
                {(Addr)&temp_var_for_tac_89, (Addr) & (temp_var_for_const_75 = 2)},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:113:19");
            computeDSub((Addr)&temp_var_for_tac_91,
                        {(Addr) & (temp_var_for_const_76 = 1.0),
                         (Addr)&temp_var_for_callexp_15},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:113:69");
            computeDAdd((Addr)&temp_var_for_tac_92, {(Addr)&Alpha[i], (Addr)&k},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:113:57");
            computeDDiv((Addr)&phi2[i],
                        {(Addr)&temp_var_for_tac_91, (Addr)&temp_var_for_tac_92},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:113:12");
            phi3[i] = exp((0 - dt) * (Alpha[i] + k));
            double temp_var_for_const_77;
            double temp_var_for_tac_93, temp_var_for_tac_94;
            computeDSub((Addr)&temp_var_for_tac_93,
                        {(Addr) & (temp_var_for_const_77 = 0), (Addr)&dt},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:114:39");
            computeDAdd((Addr)&temp_var_for_tac_94, {(Addr)&Alpha[i], (Addr)&k},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:114:27");

            computeDMul((Addr)&phi3[i],
                        {(Addr)&temp_var_for_tac_93, (Addr)&temp_var_for_tac_94},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:114:12");
            poly1[i] = (0 - 4.0) + dt * (Alpha[i] + k) +
                       exp((0 - dt) * (Alpha[i] + k)) *
                           (4 + 3.0 * dt * (Alpha[i] + k) +
                            dt * dt * (Alpha[i] + k) * (Alpha[i] + k));
            double temp_var_for_const_78, temp_var_for_const_79,
                temp_var_for_const_80, temp_var_for_const_81, temp_var_for_const_82;
            double temp_var_for_tac_95, temp_var_for_tac_96, temp_var_for_tac_97,
                temp_var_for_tac_98, temp_var_for_tac_99, temp_var_for_tac_100,
                temp_var_for_tac_101, temp_var_for_tac_102, temp_var_for_tac_103,
                temp_var_for_tac_104, temp_var_for_tac_105, temp_var_for_tac_106,
                temp_var_for_tac_107, temp_var_for_tac_108, temp_var_for_tac_109,
                temp_var_for_tac_110, temp_var_for_tac_111, temp_var_for_tac_112;
            computeDSub((Addr)&temp_var_for_tac_95,
                        {(Addr) & (temp_var_for_const_79 = 0),
                         (Addr) & (temp_var_for_const_78 = 4.0)},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:40");
            double temp_var_for_callexp_16 =
                exp(getFVbyShadow<double>((Addr)&temp_var_for_tac_95));
            CallStackPop((Addr)&temp_var_for_callexp_16,
                         getTop(temp_var_for_callexp_16));
            computeDAdd((Addr)&temp_var_for_tac_96, {(Addr)&Alpha[i], (Addr)&k},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:28");
            computeDMul((Addr)&temp_var_for_tac_97,
                        {(Addr)&dt, (Addr)&temp_var_for_tac_96},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:23");
            computeDAdd((Addr)&temp_var_for_tac_98,
                        {(Addr)&temp_var_for_tac_95, (Addr)&temp_var_for_tac_97},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:54");
            computeDSub((Addr)&temp_var_for_tac_99,
                        {(Addr) & (temp_var_for_const_80 = 0), (Addr)&dt},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:72");
            computeDAdd((Addr)&temp_var_for_tac_100, {(Addr)&Alpha[i], (Addr)&k},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:60");
            computeDMul((Addr)&temp_var_for_tac_101,
                        {(Addr)&temp_var_for_tac_99, (Addr)&temp_var_for_tac_100},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:89");
            computeDMul((Addr)&temp_var_for_tac_102,
                        {(Addr) & (temp_var_for_const_81 = 3.0), (Addr)&dt},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:106");
            computeDAdd((Addr)&temp_var_for_tac_103, {(Addr)&Alpha[i], (Addr)&k},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:94");
            computeDMul((Addr)&temp_var_for_tac_104,
                        {(Addr)&temp_var_for_tac_102, (Addr)&temp_var_for_tac_103},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:83");
            computeDAdd(
                (Addr)&temp_var_for_tac_105,
                {(Addr) & (temp_var_for_const_82 = 4), (Addr)&temp_var_for_tac_104},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:116");
            computeDMul((Addr)&temp_var_for_tac_106, {(Addr)&dt, (Addr)&dt},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:133");
            computeDAdd((Addr)&temp_var_for_tac_107, {(Addr)&Alpha[i], (Addr)&k},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:121");
            computeDMul((Addr)&temp_var_for_tac_108,
                        {(Addr)&temp_var_for_tac_106, (Addr)&temp_var_for_tac_107},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:150");
            computeDAdd((Addr)&temp_var_for_tac_109, {(Addr)&Alpha[i], (Addr)&k},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:138");
            computeDMul((Addr)&temp_var_for_tac_110,
                        {(Addr)&temp_var_for_tac_108, (Addr)&temp_var_for_tac_109},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:111");
            double temp_var_for_callexp_17 =
                exp(getFVbyShadow<double>((Addr)&temp_var_for_tac_101));
            CallStackPop((Addr)&temp_var_for_callexp_17,
                         getTop(temp_var_for_callexp_17));
            computeDAdd((Addr)&temp_var_for_tac_111,
                        {(Addr)&temp_var_for_tac_105, (Addr)&temp_var_for_tac_110},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:78");
            computeDMul((Addr)&temp_var_for_tac_112,
                        {(Addr)&temp_var_for_callexp_17, (Addr)&temp_var_for_tac_111},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:45");
            computeDAdd((Addr)&poly1[i],
                        {(Addr)&temp_var_for_tac_98, (Addr)&temp_var_for_tac_112},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:115:13");
            poly2[i] =
                4.0 - 2.0 * dt * (Alpha[i] + k) +
                exp((0 - dt) * (Alpha[i] + k)) * (-4 - 2.0 * dt * (Alpha[i] + k));
            double temp_var_for_const_83, temp_var_for_const_84,
                temp_var_for_const_85, temp_var_for_const_86, temp_var_for_const_87;
            double temp_var_for_tac_113, temp_var_for_tac_114, temp_var_for_tac_115,
                temp_var_for_tac_116, temp_var_for_tac_117, temp_var_for_tac_118,
                temp_var_for_tac_119, temp_var_for_tac_120, temp_var_for_tac_121,
                temp_var_for_tac_122, temp_var_for_tac_123, temp_var_for_tac_124;
            computeDMul((Addr)&temp_var_for_tac_113,
                        {(Addr) & (temp_var_for_const_83 = 2.0), (Addr)&dt},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:39");
            computeDAdd((Addr)&temp_var_for_tac_114, {(Addr)&Alpha[i], (Addr)&k},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:27");
            computeDMul((Addr)&temp_var_for_tac_115,
                        {(Addr)&temp_var_for_tac_113, (Addr)&temp_var_for_tac_114},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:17");
            computeDSub(
                (Addr)&temp_var_for_tac_116,
                {(Addr) & (temp_var_for_const_84 = 4.0), (Addr)&temp_var_for_tac_115},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:53");
            computeDSub((Addr)&temp_var_for_tac_117,
                        {(Addr) & (temp_var_for_const_85 = 0), (Addr)&dt},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:71");
            computeDAdd((Addr)&temp_var_for_tac_118, {(Addr)&Alpha[i], (Addr)&k},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:59");
            computeDMul((Addr)&temp_var_for_tac_119,
                        {(Addr)&temp_var_for_tac_117, (Addr)&temp_var_for_tac_118},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:88");
            computeDMul((Addr)&temp_var_for_tac_120,
                        {(Addr) & (temp_var_for_const_86 = 2.0), (Addr)&dt},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:105");
            computeDAdd((Addr)&temp_var_for_tac_121, {(Addr)&Alpha[i], (Addr)&k},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:93");
            computeDMul((Addr)&temp_var_for_tac_122,
                        {(Addr)&temp_var_for_tac_120, (Addr)&temp_var_for_tac_121},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:83");
            double temp_var_for_callexp_18 =
                exp(getFVbyShadow<double>((Addr)&temp_var_for_tac_119));
            CallStackPop((Addr)&temp_var_for_callexp_18,
                         getTop(temp_var_for_callexp_18));
            computeDSub((Addr)&temp_var_for_tac_123,
                        {(Addr) & (temp_var_for_const_87 = (-(4))),
                         (Addr)&temp_var_for_tac_122},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:77");
            computeDMul((Addr)&temp_var_for_tac_124,
                        {(Addr)&temp_var_for_callexp_18, (Addr)&temp_var_for_tac_123},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:44");
            computeDAdd((Addr)&poly2[i],
                        {(Addr)&temp_var_for_tac_116, (Addr)&temp_var_for_tac_124},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:116:13");
            poly3[i] = (0 - 4.0) + 3.0 * dt * (Alpha[i] + k) -
                       dt * dt * (Alpha[i] + k) * (Alpha[i] + k) +
                       exp((0 - dt) * (Alpha[i] + k)) * (4 + dt * (Alpha[i] + k));
            double temp_var_for_const_88, temp_var_for_const_89,
                temp_var_for_const_90, temp_var_for_const_91, temp_var_for_const_92;
            double temp_var_for_tac_125, temp_var_for_tac_126, temp_var_for_tac_127,
                temp_var_for_tac_128, temp_var_for_tac_129, temp_var_for_tac_130,
                temp_var_for_tac_131, temp_var_for_tac_132, temp_var_for_tac_133,
                temp_var_for_tac_134, temp_var_for_tac_135, temp_var_for_tac_136,
                temp_var_for_tac_137, temp_var_for_tac_138, temp_var_for_tac_139,
                temp_var_for_tac_140, temp_var_for_tac_141, temp_var_for_tac_142;
            computeDSub((Addr)&temp_var_for_tac_125,
                        {(Addr) & (temp_var_for_const_89 = 0),
                         (Addr) & (temp_var_for_const_88 = 4.0)},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:29");
            computeDMul((Addr)&temp_var_for_tac_126,
                        {(Addr) & (temp_var_for_const_90 = 3.0), (Addr)&dt},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:46");
            computeDAdd((Addr)&temp_var_for_tac_127, {(Addr)&Alpha[i], (Addr)&k},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:34");
            computeDMul((Addr)&temp_var_for_tac_128,
                        {(Addr)&temp_var_for_tac_126, (Addr)&temp_var_for_tac_127},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:23");
            computeDAdd((Addr)&temp_var_for_tac_129,
                        {(Addr)&temp_var_for_tac_125, (Addr)&temp_var_for_tac_128},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:56");
            computeDMul((Addr)&temp_var_for_tac_130, {(Addr)&dt, (Addr)&dt},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:73");
            computeDAdd((Addr)&temp_var_for_tac_131, {(Addr)&Alpha[i], (Addr)&k},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:61");
            computeDMul((Addr)&temp_var_for_tac_132,
                        {(Addr)&temp_var_for_tac_130, (Addr)&temp_var_for_tac_131},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:90");
            computeDAdd((Addr)&temp_var_for_tac_133, {(Addr)&Alpha[i], (Addr)&k},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:78");
            computeDMul((Addr)&temp_var_for_tac_134,
                        {(Addr)&temp_var_for_tac_132, (Addr)&temp_var_for_tac_133},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:51");
            computeDSub((Addr)&temp_var_for_tac_135,
                        {(Addr)&temp_var_for_tac_129, (Addr)&temp_var_for_tac_134},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:104");
            computeDSub((Addr)&temp_var_for_tac_136,
                        {(Addr) & (temp_var_for_const_91 = 0), (Addr)&dt},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:122");
            computeDAdd((Addr)&temp_var_for_tac_137, {(Addr)&Alpha[i], (Addr)&k},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:110");
            computeDMul((Addr)&temp_var_for_tac_138,
                        {(Addr)&temp_var_for_tac_136, (Addr)&temp_var_for_tac_137},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:150");
            computeDAdd((Addr)&temp_var_for_tac_139, {(Addr)&Alpha[i], (Addr)&k},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:138");
            computeDMul((Addr)&temp_var_for_tac_140,
                        {(Addr)&dt, (Addr)&temp_var_for_tac_139},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:133");
            double temp_var_for_callexp_19 =
                exp(getFVbyShadow<double>((Addr)&temp_var_for_tac_138));
            CallStackPop((Addr)&temp_var_for_callexp_19,
                         getTop(temp_var_for_callexp_19));
            computeDAdd(
                (Addr)&temp_var_for_tac_141,
                {(Addr) & (temp_var_for_const_92 = 4), (Addr)&temp_var_for_tac_140},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:128");
            computeDMul((Addr)&temp_var_for_tac_142,
                        {(Addr)&temp_var_for_callexp_19, (Addr)&temp_var_for_tac_141},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:95");
            computeDAdd((Addr)&poly3[i],
                        {(Addr)&temp_var_for_tac_135, (Addr)&temp_var_for_tac_142},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:117:13");
        }
    }
    for (i = 0; i < N; i++)
    {
        // printf("phi3[%d]=%e\n",i,phi3[i]);
        // printf("C[%d]=%e\n",i,C[i]);
        // printf("L3[%d]=%e\n",i,L3[i]);
        // printf("poly1[%d]=%e\n",i,poly1[i]);
        // printf("poly2[%d]=%e\n",i,poly2[i]);
        // printf("poly3[%d]=%e\n",i,poly3[i]);
    }

    int temp_var_for_ext_1;
    temp_var_for_ext_1 = t < TIME;
    while (temp_var_for_ext_1)
    {
        // printf("t=%f******sumalpha=%e\tsumbeta=%e\n",t,sumalpha,sumbeta);
        for (i = 0; i < N; i++)
        {
            int temp_var_for_ext_2;
            temp_var_for_ext_2 = i == 0;
            if (temp_var_for_ext_2)
            {
                alpha[i] = 0.0;
                double temp_var_for_const_93;
                AssignD({(Addr)&alpha[i]}, (Addr) & (temp_var_for_const_93 = 0.0),
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:141:14");
                beta[i] = 0.0;
                double temp_var_for_const_94;
                AssignD({(Addr)&beta[i]}, (Addr) & (temp_var_for_const_94 = 0.0),
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:142:13");
            }
            else
            {
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
        double temp_var_for_const_95, temp_var_for_const_96;
        double temp_var_for_tac_143, temp_var_for_tac_144, temp_var_for_tac_145,
            temp_var_for_tac_146, temp_var_for_tac_147, temp_var_for_tac_148,
            temp_var_for_tac_149;
        computeDMul((Addr)&temp_var_for_tac_143,
                    {(Addr) & (temp_var_for_const_95 = (-(2))), (Addr)&Beta[0],
                     (Addr)&C[0], (Addr)&C[0]},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:153:38");
        computeDSub((Addr)&temp_var_for_tac_144,
                    {(Addr)&temp_var_for_tac_143, (Addr)&sumbeta},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:153:48");
        computeDAdd((Addr)&temp_var_for_tac_145,
                    {(Addr)&temp_var_for_tac_144, (Addr)&sumalpha},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:153:70");
        computeDMul((Addr)&temp_var_for_tac_146, {(Addr)&Alpha[1], (Addr)&C[1]},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:153:59");
        computeDAdd((Addr)&temp_var_for_tac_147,
                    {(Addr)&temp_var_for_tac_145, (Addr)&temp_var_for_tac_146},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:153:84");
        computeDAdd((Addr)&temp_var_for_tac_148,
                    {(Addr) & (temp_var_for_const_96 = 1.0), (Addr)&k},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:153:89");
        computeDMul((Addr)&temp_var_for_tac_149,
                    {(Addr)&temp_var_for_tac_148, (Addr)&C[0]},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:153:77");
        computeDAdd((Addr)&Fc[0],
                    {(Addr)&temp_var_for_tac_147, (Addr)&temp_var_for_tac_149},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:153:9");
        for (i = 1; i <= N - 2; i++)
        {
            Fc[i] = Beta[i - 1] * C[i - 1] * C[0] - Beta[i] * C[i] * C[0] +
                    Alpha[i + 1] * C[i + 1] + k * C[i];
            double temp_var_for_tac_150, temp_var_for_tac_151, temp_var_for_tac_152,
                temp_var_for_tac_153, temp_var_for_tac_154, temp_var_for_tac_155;
            computeDMul((Addr)&temp_var_for_tac_150,
                        {(Addr)&Beta[i - 1],
                         (Addr)&C[i - 1], (Addr)&C[0]},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:156:52");
            computeDMul((Addr)&temp_var_for_tac_151,
                        {(Addr)&Beta[i], (Addr)&C[i], (Addr)&C[0]},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:156:42");
            computeDSub((Addr)&temp_var_for_tac_152,
                        {(Addr)&temp_var_for_tac_150, (Addr)&temp_var_for_tac_151},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:156:81");
            computeDMul(
                (Addr)&temp_var_for_tac_153,
                {(Addr)&Alpha[i + 1], (Addr)&C[i + 1]},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:156:66");
            computeDAdd((Addr)&temp_var_for_tac_154,
                        {(Addr)&temp_var_for_tac_152, (Addr)&temp_var_for_tac_153},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:156:96");
            computeDMul((Addr)&temp_var_for_tac_155, {(Addr)&k, (Addr)&C[i]},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:156:92");
            computeDAdd((Addr)&Fc[i],
                        {(Addr)&temp_var_for_tac_154, (Addr)&temp_var_for_tac_155},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:156:10");
        }
        Fc[N - 1] = Beta[N - 2] * C[N - 2] * C[0] - Beta[N - 1] * C[N - 1] * C[0] +
                    k * C[N - 1];
        /*
    for(i=0;i<N;i++){
            printf("Fc[%d]=%e\n",i,Fc[i]);
    }*/

        for (i = 0; i < N; i++)
        {
            a[i] = phi1[i] * C[i] + phi2[i] * Fc[i];
            double temp_var_for_tac_156, temp_var_for_tac_157;
            computeDMul((Addr)&temp_var_for_tac_156, {(Addr)&phi1[i], (Addr)&C[i]},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:166:36");
            computeDMul((Addr)&temp_var_for_tac_157, {(Addr)&phi2[i], (Addr)&Fc[i]},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:166:26");
            int temp_var_for_ext_3;
            temp_var_for_ext_3 = i == 0;
            if (temp_var_for_ext_3)
            {
                alpha_a[i] = 0.0;
                double temp_var_for_const_97;
                AssignD({(Addr)&alpha_a[i]}, (Addr) & (temp_var_for_const_97 = 0.0),
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:171:16");
                beta_a[i] = 0.0;
                double temp_var_for_const_98;
                AssignD({(Addr)&beta_a[i]}, (Addr) & (temp_var_for_const_98 = 0.0),
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:172:15");
            }
            else
            {
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
        double temp_var_for_const_99, temp_var_for_const_100;
        double temp_var_for_tac_158, temp_var_for_tac_159, temp_var_for_tac_160,
            temp_var_for_tac_161, temp_var_for_tac_162, temp_var_for_tac_163,
            temp_var_for_tac_164;
        computeDMul((Addr)&temp_var_for_tac_158,
                    {(Addr) & (temp_var_for_const_99 = (-(2))), (Addr)&Beta[0],
                     (Addr)&a[0], (Addr)&a[0]},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:182:38");
        computeDSub((Addr)&temp_var_for_tac_159,
                    {(Addr)&temp_var_for_tac_158, (Addr)&sumbeta_a},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:182:50");
        computeDAdd((Addr)&temp_var_for_tac_160,
                    {(Addr)&temp_var_for_tac_159, (Addr)&sumalpha_a},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:182:74");
        computeDMul((Addr)&temp_var_for_tac_161, {(Addr)&Alpha[1], (Addr)&a[1]},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:182:63");
        computeDAdd((Addr)&temp_var_for_tac_162,
                    {(Addr)&temp_var_for_tac_160, (Addr)&temp_var_for_tac_161},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:182:88");
        computeDAdd((Addr)&temp_var_for_tac_163,
                    {(Addr) & (temp_var_for_const_100 = 1.0), (Addr)&k},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:182:93");
        computeDMul((Addr)&temp_var_for_tac_164,
                    {(Addr)&temp_var_for_tac_163, (Addr)&a[0]},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:182:81");
        computeDAdd((Addr)&Fa[0],
                    {(Addr)&temp_var_for_tac_162, (Addr)&temp_var_for_tac_164},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:182:9");
        for (i = 1; i <= N - 2; i++)
        {
            Fa[i] = Beta[i - 1] * a[i - 1] * a[0] - Beta[i] * a[i] * a[0] +
                    Alpha[i + 1] * a[i + 1] + k * a[i];
            double temp_var_for_tac_165, temp_var_for_tac_166, temp_var_for_tac_167,
                temp_var_for_tac_168, temp_var_for_tac_169, temp_var_for_tac_170;
            computeDMul((Addr)&temp_var_for_tac_165,
                        {(Addr)&Beta[i - 1],
                         (Addr)&a[i - 1], (Addr)&a[0]},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:185:52");
            computeDMul((Addr)&temp_var_for_tac_166,
                        {(Addr)&Beta[i], (Addr)&a[i], (Addr)&a[0]},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:185:42");
            computeDSub((Addr)&temp_var_for_tac_167,
                        {(Addr)&temp_var_for_tac_165, (Addr)&temp_var_for_tac_166},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:185:81");
            computeDMul(
                (Addr)&temp_var_for_tac_168,
                {(Addr)&Alpha[i + 1], (Addr)&a[i + 1]},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:185:66");
            computeDAdd((Addr)&temp_var_for_tac_169,
                        {(Addr)&temp_var_for_tac_167, (Addr)&temp_var_for_tac_168},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:185:96");
            computeDMul((Addr)&temp_var_for_tac_170, {(Addr)&k, (Addr)&a[i]},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:185:92");
            computeDAdd((Addr)&Fa[i],
                        {(Addr)&temp_var_for_tac_169, (Addr)&temp_var_for_tac_170},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:185:10");
        }
        Fa[N - 1] = Beta[N - 2] * a[N - 2] * a[0] - Beta[N - 1] * a[N - 1] * a[0] +
                    k * a[N - 1];
        /*for(i=0;i<N;i++){
            printf("Fa[%d]=%e\n",i,Fa[i]);
    }*/

        for (i = 0; i < N; i++)
        {
            b[i] = phi1[i] * C[i] + phi2[i] * Fa[i];
            double temp_var_for_tac_171, temp_var_for_tac_172;
            computeDMul((Addr)&temp_var_for_tac_171, {(Addr)&phi1[i], (Addr)&C[i]},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:194:36");
            computeDMul((Addr)&temp_var_for_tac_172, {(Addr)&phi2[i], (Addr)&Fa[i]},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:194:26");
            int temp_var_for_ext_4;
            temp_var_for_ext_4 = i == 0;
            if (temp_var_for_ext_4)
            {
                alpha_b[i] = 0.0;
                double temp_var_for_const_101;
                AssignD({(Addr)&alpha_b[i]}, (Addr) & (temp_var_for_const_101 = 0.0),
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:199:16");
                beta_b[i] = 0.0;
                double temp_var_for_const_102;
                AssignD({(Addr)&beta_b[i]}, (Addr) & (temp_var_for_const_102 = 0.0),
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:200:15");
            }
            else
            {
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
        double temp_var_for_const_103, temp_var_for_const_104;
        double temp_var_for_tac_173, temp_var_for_tac_174, temp_var_for_tac_175,
            temp_var_for_tac_176, temp_var_for_tac_177, temp_var_for_tac_178,
            temp_var_for_tac_179;
        computeDMul((Addr)&temp_var_for_tac_173,
                    {(Addr) & (temp_var_for_const_103 = (-(2))), (Addr)&Beta[0],
                     (Addr)&b[0], (Addr)&b[0]},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:210:38");
        computeDSub((Addr)&temp_var_for_tac_174,
                    {(Addr)&temp_var_for_tac_173, (Addr)&sumbeta_b},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:210:50");
        computeDAdd((Addr)&temp_var_for_tac_175,
                    {(Addr)&temp_var_for_tac_174, (Addr)&sumalpha_b},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:210:74");
        computeDMul((Addr)&temp_var_for_tac_176, {(Addr)&Alpha[1], (Addr)&b[1]},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:210:63");
        computeDAdd((Addr)&temp_var_for_tac_177,
                    {(Addr)&temp_var_for_tac_175, (Addr)&temp_var_for_tac_176},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:210:88");
        computeDAdd((Addr)&temp_var_for_tac_178,
                    {(Addr) & (temp_var_for_const_104 = 1.0), (Addr)&k},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:210:93");
        computeDMul((Addr)&temp_var_for_tac_179,
                    {(Addr)&temp_var_for_tac_178, (Addr)&b[0]},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:210:81");
        computeDAdd((Addr)&Fb[0],
                    {(Addr)&temp_var_for_tac_177, (Addr)&temp_var_for_tac_179},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:210:9");
        for (i = 1; i <= N - 2; i++)
        {
            Fb[i] = Beta[i - 1] * b[i - 1] * b[0] - Beta[i] * b[i] * b[0] +
                    Alpha[i + 1] * b[i + 1] + k * b[i];
            double temp_var_for_tac_180, temp_var_for_tac_181, temp_var_for_tac_182,
                temp_var_for_tac_183, temp_var_for_tac_184, temp_var_for_tac_185;
            computeDMul((Addr)&temp_var_for_tac_180,
                        {(Addr)&Beta[i - 1],
                         (Addr)&b[i - 1], (Addr)&b[0]},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:213:52");
            computeDMul((Addr)&temp_var_for_tac_181,
                        {(Addr)&Beta[i], (Addr)&b[i], (Addr)&b[0]},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:213:42");
            computeDSub((Addr)&temp_var_for_tac_182,
                        {(Addr)&temp_var_for_tac_180, (Addr)&temp_var_for_tac_181},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:213:81");
            computeDMul(
                (Addr)&temp_var_for_tac_183,
                {(Addr)&Alpha[i + 1], (Addr)&b[i + 1]},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:213:66");
            computeDAdd((Addr)&temp_var_for_tac_184,
                        {(Addr)&temp_var_for_tac_182, (Addr)&temp_var_for_tac_183},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:213:96");
            computeDMul((Addr)&temp_var_for_tac_185, {(Addr)&k, (Addr)&b[i]},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:213:92");
            computeDAdd((Addr)&Fb[i],
                        {(Addr)&temp_var_for_tac_184, (Addr)&temp_var_for_tac_185},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:213:10");
        }
        Fb[N - 1] = Beta[N - 2] * b[N - 2] * b[0] - Beta[N - 1] * b[N - 1] * b[0] +
                    k * b[N - 1];
        /*for(i=0;i<N;i++){
            printf("Fb[%d]=%e\n",i,Fb[i]);
    }*/

        for (i = 0; i < N; i++)
        {
            d[i] = phi1[i] * a[i] + phi2[i] * (2 * Fb[i] - Fc[i]);
            double temp_var_for_const_105;
            double temp_var_for_tac_186, temp_var_for_tac_187, temp_var_for_tac_188,
                temp_var_for_tac_189;
            computeDMul((Addr)&temp_var_for_tac_186, {(Addr)&phi1[i], (Addr)&a[i]},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:222:41");
            computeDMul((Addr)&temp_var_for_tac_187,
                        {(Addr) & (temp_var_for_const_105 = 2), (Addr)&Fb[i]},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:222:49");
            computeDSub((Addr)&temp_var_for_tac_188,
                        {(Addr)&temp_var_for_tac_187, (Addr)&Fc[i]},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:222:36");
            computeDMul((Addr)&temp_var_for_tac_189,
                        {(Addr)&phi2[i], (Addr)&temp_var_for_tac_188},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:222:26");
            int temp_var_for_ext_5;
            temp_var_for_ext_5 = i == 0;
            if (temp_var_for_ext_5)
            {
                alpha_d[i] = 0.0;
                double temp_var_for_const_106;
                AssignD({(Addr)&alpha_d[i]}, (Addr) & (temp_var_for_const_106 = 0.0),
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:227:16");
                beta_d[i] = 0.0;
                double temp_var_for_const_107;
                AssignD({(Addr)&beta_d[i]}, (Addr) & (temp_var_for_const_107 = 0.0),
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:228:15");
            }
            else
            {
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
        double temp_var_for_const_108, temp_var_for_const_109;
        double temp_var_for_tac_190, temp_var_for_tac_191, temp_var_for_tac_192,
            temp_var_for_tac_193, temp_var_for_tac_194, temp_var_for_tac_195,
            temp_var_for_tac_196;
        computeDMul((Addr)&temp_var_for_tac_190,
                    {(Addr) & (temp_var_for_const_108 = (-(2))), (Addr)&Beta[0],
                     (Addr)&d[0], (Addr)&d[0]},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:238:38");
        computeDSub((Addr)&temp_var_for_tac_191,
                    {(Addr)&temp_var_for_tac_190, (Addr)&sumbeta_d},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:238:50");
        computeDAdd((Addr)&temp_var_for_tac_192,
                    {(Addr)&temp_var_for_tac_191, (Addr)&sumalpha_d},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:238:74");
        computeDMul((Addr)&temp_var_for_tac_193, {(Addr)&Alpha[1], (Addr)&d[1]},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:238:63");
        computeDAdd((Addr)&temp_var_for_tac_194,
                    {(Addr)&temp_var_for_tac_192, (Addr)&temp_var_for_tac_193},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:238:88");
        computeDAdd((Addr)&temp_var_for_tac_195,
                    {(Addr) & (temp_var_for_const_109 = 1.0), (Addr)&k},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:238:93");
        computeDMul((Addr)&temp_var_for_tac_196,
                    {(Addr)&temp_var_for_tac_195, (Addr)&d[0]},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:238:81");
        computeDAdd((Addr)&Fd[0],
                    {(Addr)&temp_var_for_tac_194, (Addr)&temp_var_for_tac_196},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:238:9");
        for (i = 1; i <= N - 2; i++)
        {
            Fd[i] = Beta[i - 1] * d[i - 1] * d[0] - Beta[i] * d[i] * d[0] +
                    Alpha[i + 1] * d[i + 1] + k * d[i];
            double temp_var_for_tac_197, temp_var_for_tac_198, temp_var_for_tac_199,
                temp_var_for_tac_200, temp_var_for_tac_201, temp_var_for_tac_202;
            computeDMul((Addr)&temp_var_for_tac_197,
                        {(Addr)&Beta[i - 1],
                         (Addr)&d[i - 1], (Addr)&d[0]},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:241:52");
            computeDMul((Addr)&temp_var_for_tac_198,
                        {(Addr)&Beta[i], (Addr)&d[i], (Addr)&d[0]},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:241:42");
            computeDSub((Addr)&temp_var_for_tac_199,
                        {(Addr)&temp_var_for_tac_197, (Addr)&temp_var_for_tac_198},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:241:81");
            computeDMul(
                (Addr)&temp_var_for_tac_200,
                {(Addr)&Alpha[i + 1], (Addr)&d[i + 1]},
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:241:66");
            computeDAdd((Addr)&temp_var_for_tac_201,
                        {(Addr)&temp_var_for_tac_199, (Addr)&temp_var_for_tac_200},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:241:96");
            computeDMul((Addr)&temp_var_for_tac_202, {(Addr)&k, (Addr)&d[i]},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:241:92");
            computeDAdd((Addr)&Fd[i],
                        {(Addr)&temp_var_for_tac_201, (Addr)&temp_var_for_tac_202},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:241:10");
        }
        Fd[N - 1] = Beta[N - 2] * d[N - 2] * d[0] - Beta[N - 1] * d[N - 1] * d[0] +
                    k * d[N - 1];
        /*for(i=0;i<N;i++){
            printf("Fd[%d]=%e\n",i,Fd[i]);
    }*/

        for (i = 0; i < N; i++)
        {
            C[i] =
                phi3[i] * C[i] +
                pow(dt, -2) * L3[i] * (poly1[i] * Fc[i] + poly2[i] * (Fa[i] + Fb[i]) + poly3[i] * Fd[i]);
            double temp_var_for_tac_203, temp_var_for_tac_204, temp_var_for_tac_205,
                temp_var_for_tac_206, temp_var_for_tac_207, temp_var_for_tac_208,
                temp_var_for_tac_209, temp_var_for_tac_210, temp_var_for_tac_211;
            double temp_var_for_callexp_20 =
                pow(getFVbyShadow<double>((Addr)&dt),
                    -(2));
            CallStackPop((Addr)&temp_var_for_callexp_20,
                         getTop(temp_var_for_callexp_20));
            computeDMul((Addr)&temp_var_for_tac_203, {(Addr)&phi3[i], (Addr)&C[i]},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:250:42");
            computeDMul((Addr)&temp_var_for_tac_204,
                        {(Addr)&temp_var_for_callexp_20, (Addr)&L3[i]},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:250:62");
            computeDMul((Addr)&temp_var_for_tac_205, {(Addr)&poly1[i], (Addr)&Fc[i]},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:250:90");
            computeDAdd((Addr)&temp_var_for_tac_206, {(Addr)&Fa[i], (Addr)&Fb[i]},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:250:81");
            computeDMul((Addr)&temp_var_for_tac_207,
                        {(Addr)&poly2[i], (Addr)&temp_var_for_tac_206},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:250:70");
            computeDAdd((Addr)&temp_var_for_tac_208,
                        {(Addr)&temp_var_for_tac_205, (Addr)&temp_var_for_tac_207},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:250:110");
            computeDMul((Addr)&temp_var_for_tac_209, {(Addr)&poly3[i], (Addr)&Fd[i]},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:250:99");
            computeDAdd((Addr)&temp_var_for_tac_210,
                        {(Addr)&temp_var_for_tac_208, (Addr)&temp_var_for_tac_209},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:250:50");
            computeDMul((Addr)&temp_var_for_tac_211,
                        {(Addr)&temp_var_for_tac_204, (Addr)&temp_var_for_tac_210},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:250:26");
            double temp_var_for_tac_212;
            computeDAdd((Addr)&temp_var_for_tac_212,
                        {(Addr)&temp_var_for_tac_203, (Addr)&temp_var_for_tac_211},
                        "/home/shijia/Public/testprogram/ETD_S.c_e.c:252:9");
        }
        t = t + dt;

        computeDAdd((Addr)&t, {(Addr)&t, (Addr)&dt},
                    "/home/shijia/Public/testprogram/ETD_S.c_e.c:252:5");
        sumalpha = sumalpha_a = sumalpha_b = sumalpha_d = 0.0;
        double temp_var_for_const_110;
        AssignD({(Addr)&sumalpha_d, (Addr)&sumalpha_b, (Addr)&sumalpha_a,
                 (Addr)&sumalpha},
                (Addr)&sumalpha_a,
                "/home/shijia/Public/testprogram/ETD_S.c_e.c:253:12");
        sumbeta = sumbeta_a = sumbeta_b = sumbeta_d = 0.0;
        double temp_var_for_const_111;
        AssignD(
            {(Addr)&sumbeta_d, (Addr)&sumbeta_b, (Addr)&sumbeta_a, (Addr)&sumbeta},
            (Addr)&sumbeta_a, "/home/shijia/Public/testprogram/ETD_S.c_e.c:254:11");
        temp_var_for_ext_1 = t < TIME;
    }

    for (i = 0; i < N; i++)
    {
        printf("C[%d]=%e\n", i, C[i]);
    }
    end = clock();
    totaltime = (end - start) / CLOCKS_PER_SEC;
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
