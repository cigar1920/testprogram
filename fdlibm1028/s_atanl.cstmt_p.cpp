#include "../ScDebug/scdebug.h"
/*							s_atanl.c
 *
 *	Inverse circular tangent for 128-bit long double precision
 *      (arctangent)
 *
 *
 *
 * SYNOPSIS:
 *
 * long double x, y, atanl();
 *
 * y = atanl( x );
 *
 *
 *
 * DESCRIPTION:
 *
 * Returns radian angle between -pi/2 and +pi/2 whose tangent is x.
 *
 * The function uses a rational approximation of the form
 * t + t^3 P(t^2)/Q(t^2), optimized for |t| < 0.09375.
 *
 * The argument is reduced using the identity
 *    arctan x - arctan u  =  arctan ((x-u)/(1 + ux))
 * and an 83-entry lookup table for arctan u, with u = 0, 1/8, ..., 10.25.
 * Use of the table improves the execution speed of the routine.
 *
 *
 *
 * ACCURACY:
 *
 *                      Relative error:
 * arithmetic   domain     # trials      peak         rms
 *    IEEE      -19, 19       4e5       1.7e-34     5.4e-35
 *
 *
 * WARNING:
 *
 * This program uses integer operations on bit fields of floating-point
 * numbers.  It does not work with data structures other than the
 * structure assumed.
 *
 */

/* Copyright 2001 by Stephen L. Moshier <moshier@na-net.ornl.gov>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, see
    <http://www.gnu.org/licenses/>.  */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __NO_LONG_DOUBLE_MATH

#ifndef __have_fpu_atan

long double __ieee754_atanl(long double x) {
  int32_t k;
  int sign;
  long double t, u, p, q;
  uint32_t msw;

  /* arctan(k/8), k = 0, ..., 82 */
  static const long double atantbl[84] = {
      0.0000000000000000000000000000000000000000E0L,
      1.2435499454676143503135484916387102557317E-1L, /* arctan(0.125)  */
      2.4497866312686415417208248121127581091414E-1L,
      3.5877067027057222039592006392646049977698E-1L,
      4.6364760900080611621425623146121440202854E-1L,
      5.5859931534356243597150821640166127034645E-1L,
      6.4350110879328438680280922871732263804151E-1L,
      7.1882999962162450541701415152590465395142E-1L,
      7.8539816339744830961566084581987572104929E-1L,
      8.4415398611317100251784414827164750652594E-1L,
      8.9605538457134395617480071802993782702458E-1L,
      9.4200004037946366473793717053459358607166E-1L,
      9.8279372324732906798571061101466601449688E-1L,
      1.0191413442663497346383429170230636487744E0L,
      1.0516502125483736674598673120862998296302E0L,
      1.0808390005411683108871567292171998202703E0L,
      1.1071487177940905030170654601785370400700E0L,
      1.1309537439791604464709335155363278047493E0L,
      1.1525719972156675180401498626127513797495E0L,
      1.1722738811284763866005949441337046149712E0L,
      1.1902899496825317329277337748293183376012E0L,
      1.2068173702852525303955115800565576303133E0L,
      1.2220253232109896370417417439225704908830E0L,
      1.2360594894780819419094519711090786987027E0L,
      1.2490457723982544258299170772810901230778E0L,
      1.2610933822524404193139408812473357720101E0L,
      1.2722973952087173412961937498224804940684E0L,
      1.2827408797442707473628852511364955306249E0L,
      1.2924966677897852679030914214070816845853E0L,
      1.3016288340091961438047858503666855921414E0L,
      1.3101939350475556342564376891719053122733E0L,
      1.3182420510168370498593302023271362531155E0L,
      1.3258176636680324650592392104284756311844E0L,
      1.3329603993374458675538498697331558093700E0L,
      1.3397056595989995393283037525895557411039E0L,
      1.3460851583802539310489409282517796256512E0L,
      1.3521273809209546571891479413898128509842E0L,
      1.3578579772154994751124898859640585287459E0L,
      1.3633001003596939542892985278250991189943E0L,
      1.3684746984165928776366381936948529556191E0L,
      1.3734007669450158608612719264449611486510E0L,
      1.3780955681325110444536609641291551522494E0L,
      1.3825748214901258580599674177685685125566E0L,
      1.3868528702577214543289381097042486034883E0L,
      1.3909428270024183486427686943836432060856E0L,
      1.3948567013423687823948122092044222644895E0L,
      1.3986055122719575950126700816114282335732E0L,
      1.4021993871854670105330304794336492676944E0L,
      1.4056476493802697809521934019958079881002E0L,
      1.4089588955564736949699075250792569287156E0L,
      1.4121410646084952153676136718584891599630E0L,
      1.4152014988178669079462550975833894394929E0L,
      1.4181469983996314594038603039700989523716E0L,
      1.4209838702219992566633046424614466661176E0L,
      1.4237179714064941189018190466107297503086E0L,
      1.4263547484202526397918060597281265695725E0L,
      1.4288992721907326964184700745371983590908E0L,
      1.4313562697035588982240194668401779312122E0L,
      1.4337301524847089866404719096698873648610E0L,
      1.4360250423171655234964275337155008780675E0L,
      1.4382447944982225979614042479354815855386E0L,
      1.4403930189057632173997301031392126865694E0L,
      1.4424730991091018200252920599377292525125E0L,
      1.4444882097316563655148453598508037025938E0L,
      1.4464413322481351841999668424758804165254E0L,
      1.4483352693775551917970437843145232637695E0L,
      1.4501726582147939000905940595923466567576E0L,
      1.4519559822271314199339700039142990228105E0L,
      1.4536875822280323362423034480994649820285E0L,
      1.4553696664279718992423082296859928222270E0L,
      1.4570043196511885530074841089245667532358E0L,
      1.4585935117976422128825857356750737658039E0L,
      1.4601391056210009726721818194296893361233E0L,
      1.4616428638860188872060496086383008594310E0L,
      1.4631064559620759326975975316301202111560E0L,
      1.4645314639038178118428450961503371619177E0L,
      1.4659193880646627234129855241049975398470E0L,
      1.4672716522843522691530527207287398276197E0L,
      1.4685896086876430842559640450619880951144E0L,
      1.4698745421276027686510391411132998919794E0L,
      1.4711276743037345918528755717617308518553E0L,
      1.4723501675822635384916444186631899205983E0L,
      1.4735431285433308455179928682541563973416E0L, /* arctan(10.25) */
      1.5707963267948966192313216916397514420986E0L  /* pi/2 */
  };

  /* arctan t = t + t^3 p(t^2) / q(t^2)
     |t| <= 0.09375
     peak relative error 5.3e-37 */

  static const long double p0 =
      (0.0 - 4.283708356338736809269381409828726405572E1L);
  long double temp_var_for_const_0, temp_var_for_const_1;
  ;
  static const long double p1 =
      (0.0 - 8.636132499244548540964557273544599863825E1L);
  long double temp_var_for_const_2, temp_var_for_const_3;
  long double temp_var_for_tac_0;
  computeLdSub((Addr)&temp_var_for_tac_0,
               {(Addr) &(temp_var_for_const_1 = 0.0),
                (Addr) &(temp_var_for_const_0 =
                             4.283708356338736809269381409828726405572E1L)},
               "/home/shijia/Public/testprogram/s_atanl.c_e.c:170:12");
  ;
  static const long double p2 =
      (0.0 - 5.713554848244551350855604111031839613216E1L);
  long double temp_var_for_const_4, temp_var_for_const_5;
  long double temp_var_for_tac_1;
  computeLdSub((Addr)&temp_var_for_tac_1,
               {(Addr) &(temp_var_for_const_3 = 0.0),
                (Addr) &(temp_var_for_const_2 =
                             8.636132499244548540964557273544599863825E1L)},
               "/home/shijia/Public/testprogram/s_atanl.c_e.c:172:12");
  ;
  static const long double p3 =
      (0.0 - 1.371405711877433266573835355036413750118E1L);
  long double temp_var_for_const_6, temp_var_for_const_7;
  long double temp_var_for_tac_2;
  computeLdSub((Addr)&temp_var_for_tac_2,
               {(Addr) &(temp_var_for_const_5 = 0.0),
                (Addr) &(temp_var_for_const_4 =
                             5.713554848244551350855604111031839613216E1L)},
               "/home/shijia/Public/testprogram/s_atanl.c_e.c:174:12");
  ;
  static const long double p4 =
      (0.0 - 8.638214309119210906997318946650189640184E-1L);
  long double temp_var_for_const_8, temp_var_for_const_9;
  long double temp_var_for_tac_3;
  computeLdSub((Addr)&temp_var_for_tac_3,
               {(Addr) &(temp_var_for_const_7 = 0.0),
                (Addr) &(temp_var_for_const_6 =
                             1.371405711877433266573835355036413750118E1L)},
               "/home/shijia/Public/testprogram/s_atanl.c_e.c:176:12");
  ;
  static const long double q0 = 1.285112506901621042780814422948906537959E2L;
  static const long double q1 = 3.361907253914337187957855834229672347089E2L;
  static const long double q2 = 3.180448303864130128268191635189365331680E2L;
  static const long double q3 = 1.307244136980865800160844625025280344686E2L;
  static const long double q4 = 2.173623741810414221251136181221172551416E1L;
  /* static const long double q5 = 1.000000000000000000000000000000000000000E0
   */

  static const long double hugeval = 1.0e4930L;

  GET_LDOUBLE_EXP(k, x);
  if (k & 0x8000)
    sign = 1;
  else
    sign = 0;

  /* Check for IEEE special cases.  */
  k &= IEEE854_LONG_DOUBLE_MAXEXP;
  if (k >= IEEE854_LONG_DOUBLE_MAXEXP) {
    /* NaN. */
    if (isnan(x))
      return (x + x);

    /* Infinity. */
    if (sign)
      return -atantbl[83];
    else
      return atantbl[83];
  }

  if (k <= 0x3fc5) /* |x| < 2**-58 */
  {
    /* Raise inexact. */
    if (hugeval + x > 0.0)
      return x;
  }

  if (k >= 0x4072) /* |x| > 2**115 */
  {
    /* Saturate result to {-,+}pi/2 */
    if (sign)
      return -atantbl[83];
    else
      return atantbl[83];
  }

  if (sign) {
    long double temp_var_for_ext_0;
    temp_var_for_ext_0 = (0.0 - x);
    long double temp_var_for_const_10;
    long double temp_var_for_tac_4;
    computeLdSub((Addr)&temp_var_for_tac_4,
                 {(Addr) &(temp_var_for_const_9 = 0.0),
                  (Addr) &(temp_var_for_const_8 =
                               8.638214309119210906997318946650189640184E-1L)},
                 "/home/shijia/Public/testprogram/s_atanl.c_e.c:225:31");
    computeLdSub((Addr)&temp_var_for_ext_0,
                 {(Addr) &(temp_var_for_const_10 = 0.0), (Addr)&x},
                 "/home/shijia/Public/testprogram/s_atanl.c_e.c:225:24"); // x
    /*(x)(x)*/
    x = temp_var_for_ext_0;
    AssignLd({(Addr)&x}, (Addr)&temp_var_for_ext_0,
             "/home/shijia/Public/testprogram/s_atanl.c_e.c:227:7");
  }

  GET_LDOUBLE_MSW(msw, x);
  if (k > 0x4002 || (k == 0x4002 && msw >= UC(0x48000000))) /* 10.25 */
  {
    k = 83;
    t = -1.0 / x;
  } else {
    /* Index of nearest table element.
       Roundoff to integer is asymmetrical to avoid cancellation when t < 0
       (cf. fdlibm). */
    k = 8.0 * x + 0.25;
    u = 0.125 * k;
    /* Small arctan argument.  */
    t = (x - u) / (1.0 + x * u);
  }

  /* Arctan of small argument t.  */
  u = t * t;
  computeLdMul((Addr)&u, {(Addr)&t, (Addr)&t},
               "/home/shijia/Public/testprogram/s_atanl.c_e.c:246:5");
  p = ((((p4 * u) + p3) * u + p2) * u + p1) * u + p0;
  long double temp_var_for_const_11, temp_var_for_const_12,
      temp_var_for_const_13, temp_var_for_const_14, temp_var_for_const_15;
  long double temp_var_for_tac_5, temp_var_for_tac_6, temp_var_for_tac_7,
      temp_var_for_tac_8, temp_var_for_tac_9, temp_var_for_tac_10,
      temp_var_for_tac_11;
  computeLdMul((Addr)&temp_var_for_tac_5,
               {(Addr) &(temp_var_for_const_11 = p4), (Addr)&u},
               "/home/shijia/Public/testprogram/s_atanl.c_e.c:247:19");
  computeLdAdd(
      (Addr)&temp_var_for_tac_6,
      {(Addr)&temp_var_for_tac_5, (Addr) &(temp_var_for_const_12 = p3)},
      "/home/shijia/Public/testprogram/s_atanl.c_e.c:247:25");
  computeLdMul((Addr)&temp_var_for_tac_7, {(Addr)&temp_var_for_tac_6, (Addr)&u},
               "/home/shijia/Public/testprogram/s_atanl.c_e.c:247:29");
  computeLdAdd(
      (Addr)&temp_var_for_tac_8,
      {(Addr)&temp_var_for_tac_7, (Addr) &(temp_var_for_const_13 = p2)},
      "/home/shijia/Public/testprogram/s_atanl.c_e.c:247:35");
  computeLdMul((Addr)&temp_var_for_tac_9, {(Addr)&temp_var_for_tac_8, (Addr)&u},
               "/home/shijia/Public/testprogram/s_atanl.c_e.c:247:39");
  computeLdAdd(
      (Addr)&temp_var_for_tac_10,
      {(Addr)&temp_var_for_tac_9, (Addr) &(temp_var_for_const_14 = p1)},
      "/home/shijia/Public/testprogram/s_atanl.c_e.c:247:45");
  computeLdMul((Addr)&temp_var_for_tac_11,
               {(Addr)&temp_var_for_tac_10, (Addr)&u},
               "/home/shijia/Public/testprogram/s_atanl.c_e.c:247:49");
  computeLdAdd((Addr)&p, {(Addr)&temp_var_for_tac_11,
                          (Addr) &(temp_var_for_const_15 = p0)},
               "/home/shijia/Public/testprogram/s_atanl.c_e.c:247:5");
  q = ((((u + q4) * u + q3) * u + q2) * u + q1) * u + q0;
  long double temp_var_for_const_16, temp_var_for_const_17,
      temp_var_for_const_18, temp_var_for_const_19, temp_var_for_const_20;
  long double temp_var_for_tac_12, temp_var_for_tac_13, temp_var_for_tac_14,
      temp_var_for_tac_15, temp_var_for_tac_16, temp_var_for_tac_17,
      temp_var_for_tac_18, temp_var_for_tac_19;
  computeLdAdd((Addr)&temp_var_for_tac_12,
               {(Addr)&u, (Addr) &(temp_var_for_const_16 = q4)},
               "/home/shijia/Public/testprogram/s_atanl.c_e.c:248:19");
  computeLdMul((Addr)&temp_var_for_tac_13,
               {(Addr)&temp_var_for_tac_12, (Addr)&u},
               "/home/shijia/Public/testprogram/s_atanl.c_e.c:248:23");
  computeLdAdd(
      (Addr)&temp_var_for_tac_14,
      {(Addr)&temp_var_for_tac_13, (Addr) &(temp_var_for_const_17 = q3)},
      "/home/shijia/Public/testprogram/s_atanl.c_e.c:248:29");
  computeLdMul((Addr)&temp_var_for_tac_15,
               {(Addr)&temp_var_for_tac_14, (Addr)&u},
               "/home/shijia/Public/testprogram/s_atanl.c_e.c:248:33");
  computeLdAdd(
      (Addr)&temp_var_for_tac_16,
      {(Addr)&temp_var_for_tac_15, (Addr) &(temp_var_for_const_18 = q2)},
      "/home/shijia/Public/testprogram/s_atanl.c_e.c:248:39");
  computeLdMul((Addr)&temp_var_for_tac_17,
               {(Addr)&temp_var_for_tac_16, (Addr)&u},
               "/home/shijia/Public/testprogram/s_atanl.c_e.c:248:43");
  computeLdAdd(
      (Addr)&temp_var_for_tac_18,
      {(Addr)&temp_var_for_tac_17, (Addr) &(temp_var_for_const_19 = q1)},
      "/home/shijia/Public/testprogram/s_atanl.c_e.c:248:49");
  computeLdMul((Addr)&temp_var_for_tac_19,
               {(Addr)&temp_var_for_tac_18, (Addr)&u},
               "/home/shijia/Public/testprogram/s_atanl.c_e.c:248:53");
  computeLdAdd((Addr)&q, {(Addr)&temp_var_for_tac_19,
                          (Addr) &(temp_var_for_const_20 = q0)},
               "/home/shijia/Public/testprogram/s_atanl.c_e.c:248:5");
  long double temp_var_for_ext_1;
  temp_var_for_ext_1 = t * u * p / q + t;
  long double temp_var_for_tac_20, temp_var_for_tac_21;
  computeLdMul((Addr)&temp_var_for_tac_20, {(Addr)&t, (Addr)&u, (Addr)&p},
               "/home/shijia/Public/testprogram/s_atanl.c_e.c:250:34");
  computeLdDiv((Addr)&temp_var_for_tac_21,
               {(Addr)&temp_var_for_tac_20, (Addr)&q},
               "/home/shijia/Public/testprogram/s_atanl.c_e.c:250:38");
  computeLdAdd((Addr)&temp_var_for_ext_1,
               {(Addr)&temp_var_for_tac_21, (Addr)&t},
               "/home/shijia/Public/testprogram/s_atanl.c_e.c:250:22"); // u
  /*(q0)(u)(q1)(u)(q2)(u)(q3)(u)(q4)(u)(u)(q1)(u)(q2)(u)(q3)(u)(q4)(u)(q1)(u)(q2)(u)(q3)(u)(q4)(u)(u)(q2)(u)(q3)(u)(q4)(u)(q2)(u)(q3)(u)(q4)(u)(u)(q3)(u)(q4)(u)(q3)(u)(q4)(u)(u)(q4)(u)(q4)(u)(t)(q)(p)(u)(t)*/
  u = temp_var_for_ext_1;
  AssignLd({(Addr)&u}, (Addr)&temp_var_for_ext_1,
           "/home/shijia/Public/testprogram/s_atanl.c_e.c:252:5");

  /* arctan x = arctan u  +  arctan t */
  u = atantbl[k] + u;
  if (sign) {
    long double temp_var_for_ext_2;
    temp_var_for_ext_2 = -u;
    AssignLd({(Addr)&temp_var_for_ext_2}, (Addr) & (-(u)),
             "/home/shijia/Public/testprogram/s_atanl.c_e.c:258:24");
    callExpStack.push(getReal("temp_var_for_ext_2", (Addr)&temp_var_for_ext_2));
    callExp++; /*identify the function is  add move tmpShadow*/
    return (0.0 - 2);
    double temp_var_for_const_21, temp_var_for_const_22;
    ;
    double temp_var_for_tac_22;
    computeDSub((Addr)&temp_var_for_tac_22,
                {(Addr) &(temp_var_for_const_22 = 0.0),
                 (Addr) &(temp_var_for_const_21 = 2)},
                "toString(biExpr->getExprLoc())");
  }

  long double temp_var_for_ext_3;
  temp_var_for_ext_3 = u;
  AssignLd({(Addr)&temp_var_for_ext_3}, (Addr)&u,
           "/home/shijia/Public/testprogram/s_atanl.c_e.c:265:22");
  callExpStack.push(getReal("temp_var_for_ext_3", (Addr)&temp_var_for_ext_3));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_3;
}

#endif

long double __atanl(long double x) {
  long double temp_var_for_ext_4;
  temp_var_for_ext_4 = __ieee754_atanl(x);
  long double temp_var_for_callexp_0 =
      __ieee754_atanl(getFVbyShadow<long double>((Addr)&x));
  CallStackPop((Addr)&temp_var_for_callexp_0, getTop(temp_var_for_callexp_0));
  AssignLd({(Addr)&temp_var_for_ext_4}, ,
           "/home/shijia/Public/testprogram/s_atanl.c_e.c:275:22");
  callExpStack.push(getReal("temp_var_for_ext_4", (Addr)&temp_var_for_ext_4));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_4;
}

__typeof(__atanl) atanl __attribute__((weak, alias("__atanl")));

#endif
