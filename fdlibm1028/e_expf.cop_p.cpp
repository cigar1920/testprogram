#include "../ScDebug/scdebug.h"
/* Single-precision floating point e^x.
   Copyright (C) 1997-2013 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by Geoffrey Keating <geoffk@ozemail.com.au>

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/* How this works:

   The input value, x, is written as

   x = n * ln(2) + t/512 + delta[t] + x;

   where:
   - n is an integer, 127 >= n >= -150;
   - t is an integer, 177 >= t >= -177
   - delta is based on a table entry, delta[t] < 2^-28
   - x is whatever is left, |x| < 2^-10

   Then e^x is approximated as

   e^x = 2^n ( e^(t/512 + delta[t])
               + ( e^(t/512 + delta[t])
                   * ( p(x + delta[t] + n * ln(2)) - delta ) ) )

   where
   - p(x) is a polynomial approximating e(x)-1;
   - e^(t/512 + delta[t]) is obtained from a table.

   The table used is the same one as for the double precision version;
   since we have the table, we might as well use it.

   It turns out to be faster to do calculations in double precision than
   to perform an 'accurate table method' expf, because of the range reduction
   overhead (compare exp2f).
   */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_exp

float __ieee754_expf(float x) {
  static const float himark = 88.72283935546875f;
  static const float lomark =
      (double temp_var_for_tac_0;
       double temp_var_for_const_0, temp_var_for_const_1;
       temp_var_for_tac_0 = 0.0 - 103.972084045410f;

       );

#include "t_expf.h"

  /* Check for usual case.  */
  if (isless(x, himark) && isgreater(x, lomark)) {
    static const float THREEp42 = 13194139533312.0f;
    static const float THREEp22 = 12582912.0f;

    /* 1/ln(2).  */
    static const float m_1_ln2 = 1.44269502163f;

    /* ln(2) */
    static const double m_ln2 = .6931471805599452862;

    int tval;
    volatile double x22, t, result, dx;
    volatile float n, delta;
    double ex2_u;

    {
      int32_t exponent;
      SAVE_AND_SET_ROUND(FE_TONEAREST);

      /* Calculate n.  */
      n = float temp_var_for_tac_179, temp_var_for_tac_180;
      float temp_var_for_const_358, temp_var_for_const_359;
      temp_var_for_tac_179 = x * m_1_ln2;

      temp_var_for_tac_180 = temp_var_for_tac_179 + THREEp22;

      ;
      n -= THREEp22;
      dx = double temp_var_for_tac_181, temp_var_for_tac_182;
      double temp_var_for_const_360, temp_var_for_const_361;
      temp_var_for_tac_181 = n * m_ln2;

      temp_var_for_tac_182 = x - temp_var_for_tac_181;

      ;

      /* Calculate t/512.  */
      t = double temp_var_for_tac_183;
      double temp_var_for_const_362, temp_var_for_const_363;
      temp_var_for_tac_183 = dx + THREEp42;

      ;
      t -= THREEp42;
      dx -= t;

      /* Compute tval = t. */
      tval = (int)(double temp_var_for_tac_184;
                   double temp_var_for_const_364, temp_var_for_const_365;
                   temp_var_for_tac_184 = t * 512.0;

                   );

      if (int temp_var_for_tac_185;
          int temp_var_for_const_366, temp_var_for_const_367;
          temp_var_for_tac_185 = t >= 0;

          ) {
        delta = (double temp_var_for_tac_186;
                 double temp_var_for_const_368, temp_var_for_const_369;
                 temp_var_for_tac_186 = 0.0 - __exp_deltatable[tval];

                 );
      }

      else {
        delta = __exp_deltatable[-tval];
      }

      /* Compute ex2 = 2^n e^(t/512+delta[t]).  */
      double temp_var_for_const_370;
      ex2_u = __exp_atable[tval + 177];
      computeDSub((Addr)&temp_var_for_tac_0,
                  {(Addr) &(temp_var_for_const_1 = 0.0),
                   (Addr) &(temp_var_for_const_0 = 103.972084045410f)},
                  "/home/shijia/Public/testprogram/e_expf.c_e.c:58:36");
      computeDMul((Addr)&temp_var_for_tac_1,
                  {(Addr) &(temp_var_for_const_3 = 0),
                   (Addr) &(temp_var_for_const_2 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:32:4");
      computeDMul((Addr)&temp_var_for_tac_2,
                  {(Addr) &(temp_var_for_const_5 = ((int32_t))),
                   (Addr) &(temp_var_for_const_4 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:32:24");
      computeDMul((Addr)&temp_var_for_tac_3,
                  {(Addr) &(temp_var_for_const_7 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_6 = W59)},
                  "/home/shijia/Public/testprogram/t_expf.h:32:45");
      computeDMul((Addr)&temp_var_for_tac_4,
                  {(Addr) &(temp_var_for_const_9 = ((int32_t))),
                   (Addr) &(temp_var_for_const_8 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:32:64");
      computeDMul((Addr)&temp_var_for_tac_5,
                  {(Addr) &(temp_var_for_const_11 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_10 = W55)},
                  "/home/shijia/Public/testprogram/t_expf.h:33:16");
      computeDMul((Addr)&temp_var_for_tac_6,
                  {(Addr) &(temp_var_for_const_13 = ((int32_t))),
                   (Addr) &(temp_var_for_const_12 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:33:34");
      computeDMul((Addr)&temp_var_for_tac_7,
                  {(Addr) &(temp_var_for_const_15 = ((int32_t))),
                   (Addr) &(temp_var_for_const_14 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:33:53");
      computeDMul((Addr)&temp_var_for_tac_8,
                  {(Addr) &(temp_var_for_const_17 = ((int32_t))),
                   (Addr) &(temp_var_for_const_16 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:33:72");
      computeDMul((Addr)&temp_var_for_tac_9,
                  {(Addr) &(temp_var_for_const_19 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_18 = W58)},
                  "/home/shijia/Public/testprogram/t_expf.h:34:16");
      computeDMul((Addr)&temp_var_for_tac_10,
                  {(Addr) &(temp_var_for_const_21 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_20 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:34:36");
      computeDMul((Addr)&temp_var_for_tac_11,
                  {(Addr) &(temp_var_for_const_23 = ((int32_t))),
                   (Addr) &(temp_var_for_const_22 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:34:54");
      computeDMul((Addr)&temp_var_for_tac_12,
                  {(Addr) &(temp_var_for_const_25 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_24 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:34:74");
      computeDMul((Addr)&temp_var_for_tac_13,
                  {(Addr) &(temp_var_for_const_27 = ((int32_t))),
                   (Addr) &(temp_var_for_const_26 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:35:14");
      computeDMul((Addr)&temp_var_for_tac_14,
                  {(Addr) &(temp_var_for_const_29 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_28 = W58)},
                  "/home/shijia/Public/testprogram/t_expf.h:35:35");
      computeDMul((Addr)&temp_var_for_tac_15,
                  {(Addr) &(temp_var_for_const_31 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_30 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:35:54");
      computeDMul((Addr)&temp_var_for_tac_16,
                  {(Addr) &(temp_var_for_const_33 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_32 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:35:74");
      computeDMul((Addr)&temp_var_for_tac_17,
                  {(Addr) &(temp_var_for_const_35 = ((int32_t))),
                   (Addr) &(temp_var_for_const_34 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:36:14");
      computeDMul((Addr)&temp_var_for_tac_18,
                  {(Addr) &(temp_var_for_const_37 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_36 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:36:33");
      computeDMul((Addr)&temp_var_for_tac_19,
                  {(Addr) &(temp_var_for_const_39 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_38 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:36:53");
      computeDMul((Addr)&temp_var_for_tac_20,
                  {(Addr) &(temp_var_for_const_41 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_40 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:36:72");
      computeDMul((Addr)&temp_var_for_tac_21,
                  {(Addr) &(temp_var_for_const_43 = ((int32_t))),
                   (Addr) &(temp_var_for_const_42 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:37:14");
      computeDMul((Addr)&temp_var_for_tac_22,
                  {(Addr) &(temp_var_for_const_45 = ((int32_t))),
                   (Addr) &(temp_var_for_const_44 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:37:32");
      computeDMul((Addr)&temp_var_for_tac_23,
                  {(Addr) &(temp_var_for_const_47 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_46 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:37:51");
      computeDMul((Addr)&temp_var_for_tac_24,
                  {(Addr) &(temp_var_for_const_49 = ((int32_t))),
                   (Addr) &(temp_var_for_const_48 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:37:68");
      computeDMul((Addr)&temp_var_for_tac_25,
                  {(Addr) &(temp_var_for_const_51 = ((int32_t))),
                   (Addr) &(temp_var_for_const_50 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:38:13");
      computeDMul((Addr)&temp_var_for_tac_26,
                  {(Addr) &(temp_var_for_const_53 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_52 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:38:33");
      computeDMul((Addr)&temp_var_for_tac_27,
                  {(Addr) &(temp_var_for_const_55 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_54 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:38:49");
      computeDMul((Addr)&temp_var_for_tac_28,
                  {(Addr) &(temp_var_for_const_57 = ((int32_t))),
                   (Addr) &(temp_var_for_const_56 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:38:67");
      computeDMul((Addr)&temp_var_for_tac_29,
                  {(Addr) &(temp_var_for_const_59 = ((int32_t))),
                   (Addr) &(temp_var_for_const_58 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:39:13");
      computeDMul((Addr)&temp_var_for_tac_30,
                  {(Addr) &(temp_var_for_const_61 = ((int32_t))),
                   (Addr) &(temp_var_for_const_60 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:39:31");
      computeDMul((Addr)&temp_var_for_tac_31,
                  {(Addr) &(temp_var_for_const_63 = ((int32_t))),
                   (Addr) &(temp_var_for_const_62 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:39:49");
      computeDMul((Addr)&temp_var_for_tac_32,
                  {(Addr) &(temp_var_for_const_65 = ((int32_t))),
                   (Addr) &(temp_var_for_const_64 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:39:68");
      computeDMul((Addr)&temp_var_for_tac_33,
                  {(Addr) &(temp_var_for_const_67 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_66 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:40:15");
      computeDMul((Addr)&temp_var_for_tac_34,
                  {(Addr) &(temp_var_for_const_69 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_68 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:40:34");
      computeDMul((Addr)&temp_var_for_tac_35,
                  {(Addr) &(temp_var_for_const_71 = ((int32_t))),
                   (Addr) &(temp_var_for_const_70 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:40:53");
      computeDMul((Addr)&temp_var_for_tac_36,
                  {(Addr) &(temp_var_for_const_73 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_72 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:40:72");
      computeDMul((Addr)&temp_var_for_tac_37,
                  {(Addr) &(temp_var_for_const_75 = ((int32_t))),
                   (Addr) &(temp_var_for_const_74 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:41:13");
      computeDMul((Addr)&temp_var_for_tac_38,
                  {(Addr) &(temp_var_for_const_77 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_76 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:41:33");
      computeDMul((Addr)&temp_var_for_tac_39,
                  {(Addr) &(temp_var_for_const_79 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_78 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:41:52");
      computeDMul((Addr)&temp_var_for_tac_40,
                  {(Addr) &(temp_var_for_const_81 = ((int32_t))),
                   (Addr) &(temp_var_for_const_80 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:41:71");
      computeDMul((Addr)&temp_var_for_tac_41,
                  {(Addr) &(temp_var_for_const_83 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_82 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:42:15");
      computeDMul((Addr)&temp_var_for_tac_42,
                  {(Addr) &(temp_var_for_const_85 = ((int32_t))),
                   (Addr) &(temp_var_for_const_84 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:42:34");
      computeDMul((Addr)&temp_var_for_tac_43,
                  {(Addr) &(temp_var_for_const_87 = ((int32_t))),
                   (Addr) &(temp_var_for_const_86 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:42:52");
      computeDMul((Addr)&temp_var_for_tac_44,
                  {(Addr) &(temp_var_for_const_89 = ((int32_t))),
                   (Addr) &(temp_var_for_const_88 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:42:71");
      computeDMul((Addr)&temp_var_for_tac_45,
                  {(Addr) &(temp_var_for_const_91 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_90 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:43:14");
      computeDMul((Addr)&temp_var_for_tac_46,
                  {(Addr) &(temp_var_for_const_93 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_92 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:43:34");
      computeDMul((Addr)&temp_var_for_tac_47,
                  {(Addr) &(temp_var_for_const_95 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_94 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:43:54");
      computeDMul((Addr)&temp_var_for_tac_48,
                  {(Addr) &(temp_var_for_const_97 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_96 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:43:74");
      computeDMul((Addr)&temp_var_for_tac_49,
                  {(Addr) &(temp_var_for_const_99 = ((int32_t))),
                   (Addr) &(temp_var_for_const_98 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:44:14");
      computeDMul((Addr)&temp_var_for_tac_50,
                  {(Addr) &(temp_var_for_const_101 = ((int32_t))),
                   (Addr) &(temp_var_for_const_100 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:44:33");
      computeDMul((Addr)&temp_var_for_tac_51,
                  {(Addr) &(temp_var_for_const_103 = ((int32_t))),
                   (Addr) &(temp_var_for_const_102 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:44:52");
      computeDMul((Addr)&temp_var_for_tac_52,
                  {(Addr) &(temp_var_for_const_105 = ((int32_t))),
                   (Addr) &(temp_var_for_const_104 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:44:70");
      computeDMul((Addr)&temp_var_for_tac_53,
                  {(Addr) &(temp_var_for_const_107 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_106 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:45:15");
      computeDMul((Addr)&temp_var_for_tac_54,
                  {(Addr) &(temp_var_for_const_109 = ((int32_t))),
                   (Addr) &(temp_var_for_const_108 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:45:33");
      computeDMul((Addr)&temp_var_for_tac_55,
                  {(Addr) &(temp_var_for_const_111 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_110 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:45:53");
      computeDMul((Addr)&temp_var_for_tac_56,
                  {(Addr) &(temp_var_for_const_113 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_112 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:45:73");
      computeDMul((Addr)&temp_var_for_tac_57,
                  {(Addr) &(temp_var_for_const_115 = ((int32_t))),
                   (Addr) &(temp_var_for_const_114 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:46:15");
      computeDMul((Addr)&temp_var_for_tac_58,
                  {(Addr) &(temp_var_for_const_117 = ((int32_t))),
                   (Addr) &(temp_var_for_const_116 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:46:33");
      computeDMul((Addr)&temp_var_for_tac_59,
                  {(Addr) &(temp_var_for_const_119 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_118 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:46:53");
      computeDMul((Addr)&temp_var_for_tac_60,
                  {(Addr) &(temp_var_for_const_121 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_120 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:46:73");
      computeDMul((Addr)&temp_var_for_tac_61,
                  {(Addr) &(temp_var_for_const_123 = ((int32_t))),
                   (Addr) &(temp_var_for_const_122 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:47:13");
      computeDMul((Addr)&temp_var_for_tac_62,
                  {(Addr) &(temp_var_for_const_125 = ((int32_t))),
                   (Addr) &(temp_var_for_const_124 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:47:31");
      computeDMul((Addr)&temp_var_for_tac_63,
                  {(Addr) &(temp_var_for_const_127 = ((int32_t))),
                   (Addr) &(temp_var_for_const_126 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:47:49");
      computeDMul((Addr)&temp_var_for_tac_64,
                  {(Addr) &(temp_var_for_const_129 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_128 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:47:68");
      computeDMul((Addr)&temp_var_for_tac_65,
                  {(Addr) &(temp_var_for_const_131 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_130 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:48:15");
      computeDMul((Addr)&temp_var_for_tac_66,
                  {(Addr) &(temp_var_for_const_133 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_132 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:48:34");
      computeDMul((Addr)&temp_var_for_tac_67,
                  {(Addr) &(temp_var_for_const_135 = ((int32_t))),
                   (Addr) &(temp_var_for_const_134 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:48:51");
      computeDMul((Addr)&temp_var_for_tac_68,
                  {(Addr) &(temp_var_for_const_137 = ((int32_t))),
                   (Addr) &(temp_var_for_const_136 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:48:69");
      computeDMul((Addr)&temp_var_for_tac_69,
                  {(Addr) &(temp_var_for_const_139 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_138 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:49:14");
      computeDMul((Addr)&temp_var_for_tac_70,
                  {(Addr) &(temp_var_for_const_141 = ((int32_t))),
                   (Addr) &(temp_var_for_const_140 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:49:33");
      computeDMul((Addr)&temp_var_for_tac_71,
                  {(Addr) &(temp_var_for_const_143 = ((int32_t))),
                   (Addr) &(temp_var_for_const_142 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:49:51");
      computeDMul((Addr)&temp_var_for_tac_72,
                  {(Addr) &(temp_var_for_const_145 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_144 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:49:72");
      computeDMul((Addr)&temp_var_for_tac_73,
                  {(Addr) &(temp_var_for_const_147 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_146 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:50:15");
      computeDMul((Addr)&temp_var_for_tac_74,
                  {(Addr) &(temp_var_for_const_149 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_148 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:50:34");
      computeDMul((Addr)&temp_var_for_tac_75,
                  {(Addr) &(temp_var_for_const_151 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_150 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:50:54");
      computeDMul((Addr)&temp_var_for_tac_76,
                  {(Addr) &(temp_var_for_const_153 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_152 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:50:73");
      computeDMul((Addr)&temp_var_for_tac_77,
                  {(Addr) &(temp_var_for_const_155 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_154 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:51:14");
      computeDMul((Addr)&temp_var_for_tac_78,
                  {(Addr) &(temp_var_for_const_157 = ((int32_t))),
                   (Addr) &(temp_var_for_const_156 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:51:33");
      computeDMul((Addr)&temp_var_for_tac_79,
                  {(Addr) &(temp_var_for_const_159 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_158 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:51:53");
      computeDMul((Addr)&temp_var_for_tac_80,
                  {(Addr) &(temp_var_for_const_161 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_160 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:51:73");
      computeDMul((Addr)&temp_var_for_tac_81,
                  {(Addr) &(temp_var_for_const_163 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_162 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:52:15");
      computeDMul((Addr)&temp_var_for_tac_82,
                  {(Addr) &(temp_var_for_const_165 = ((int32_t))),
                   (Addr) &(temp_var_for_const_164 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:52:34");
      computeDMul((Addr)&temp_var_for_tac_83,
                  {(Addr) &(temp_var_for_const_167 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_166 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:52:53");
      computeDMul((Addr)&temp_var_for_tac_84,
                  {(Addr) &(temp_var_for_const_169 = ((int32_t))),
                   (Addr) &(temp_var_for_const_168 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:52:72");
      computeDMul((Addr)&temp_var_for_tac_85,
                  {(Addr) &(temp_var_for_const_171 = ((int32_t))),
                   (Addr) &(temp_var_for_const_170 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:53:13");
      computeDMul((Addr)&temp_var_for_tac_86,
                  {(Addr) &(temp_var_for_const_173 = ((int32_t))),
                   (Addr) &(temp_var_for_const_172 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:53:32");
      computeDMul((Addr)&temp_var_for_tac_87,
                  {(Addr) &(temp_var_for_const_175 = ((int32_t))),
                   (Addr) &(temp_var_for_const_174 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:53:50");
      computeDMul((Addr)&temp_var_for_tac_88,
                  {(Addr) &(temp_var_for_const_177 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_176 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:53:70");
      computeDMul((Addr)&temp_var_for_tac_89,
                  {(Addr) &(temp_var_for_const_179 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_178 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:54:15");
      computeDMul((Addr)&temp_var_for_tac_90,
                  {(Addr) &(temp_var_for_const_181 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_180 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:54:35");
      computeDMul((Addr)&temp_var_for_tac_91,
                  {(Addr) &(temp_var_for_const_183 = ((int32_t))),
                   (Addr) &(temp_var_for_const_182 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:54:54");
      computeDMul((Addr)&temp_var_for_tac_92,
                  {(Addr) &(temp_var_for_const_185 = ((int32_t))),
                   (Addr) &(temp_var_for_const_184 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:54:73");
      computeDMul((Addr)&temp_var_for_tac_93,
                  {(Addr) &(temp_var_for_const_187 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_186 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:55:15");
      computeDMul((Addr)&temp_var_for_tac_94,
                  {(Addr) &(temp_var_for_const_189 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_188 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:55:35");
      computeDMul((Addr)&temp_var_for_tac_95,
                  {(Addr) &(temp_var_for_const_191 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_190 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:55:55");
      computeDMul((Addr)&temp_var_for_tac_96,
                  {(Addr) &(temp_var_for_const_193 = ((int32_t))),
                   (Addr) &(temp_var_for_const_192 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:55:74");
      computeDMul((Addr)&temp_var_for_tac_97,
                  {(Addr) &(temp_var_for_const_195 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_194 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:56:15");
      computeDMul((Addr)&temp_var_for_tac_98,
                  {(Addr) &(temp_var_for_const_197 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_196 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:56:33");
      computeDMul((Addr)&temp_var_for_tac_99,
                  {(Addr) &(temp_var_for_const_199 = ((int32_t))),
                   (Addr) &(temp_var_for_const_198 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:56:51");
      computeDMul((Addr)&temp_var_for_tac_100,
                  {(Addr) &(temp_var_for_const_201 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_200 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:56:70");
      computeDMul((Addr)&temp_var_for_tac_101,
                  {(Addr) &(temp_var_for_const_203 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_202 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:57:15");
      computeDMul((Addr)&temp_var_for_tac_102,
                  {(Addr) &(temp_var_for_const_205 = ((int32_t))),
                   (Addr) &(temp_var_for_const_204 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:57:33");
      computeDMul((Addr)&temp_var_for_tac_103,
                  {(Addr) &(temp_var_for_const_207 = ((int32_t))),
                   (Addr) &(temp_var_for_const_206 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:57:51");
      computeDMul((Addr)&temp_var_for_tac_104,
                  {(Addr) &(temp_var_for_const_209 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_208 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:57:71");
      computeDMul((Addr)&temp_var_for_tac_105,
                  {(Addr) &(temp_var_for_const_211 = ((int32_t))),
                   (Addr) &(temp_var_for_const_210 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:58:13");
      computeDMul((Addr)&temp_var_for_tac_106,
                  {(Addr) &(temp_var_for_const_213 = ((int32_t))),
                   (Addr) &(temp_var_for_const_212 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:58:32");
      computeDMul((Addr)&temp_var_for_tac_107,
                  {(Addr) &(temp_var_for_const_215 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_214 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:58:51");
      computeDMul((Addr)&temp_var_for_tac_108,
                  {(Addr) &(temp_var_for_const_217 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_216 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:58:70");
      computeDMul((Addr)&temp_var_for_tac_109,
                  {(Addr) &(temp_var_for_const_219 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_218 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:59:14");
      computeDMul((Addr)&temp_var_for_tac_110,
                  {(Addr) &(temp_var_for_const_221 = ((int32_t))),
                   (Addr) &(temp_var_for_const_220 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:59:32");
      computeDMul((Addr)&temp_var_for_tac_111,
                  {(Addr) &(temp_var_for_const_223 = ((int32_t))),
                   (Addr) &(temp_var_for_const_222 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:59:50");
      computeDMul((Addr)&temp_var_for_tac_112,
                  {(Addr) &(temp_var_for_const_225 = ((int32_t))),
                   (Addr) &(temp_var_for_const_224 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:59:68");
      computeDMul((Addr)&temp_var_for_tac_113,
                  {(Addr) &(temp_var_for_const_227 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_226 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:60:15");
      computeDMul((Addr)&temp_var_for_tac_114,
                  {(Addr) &(temp_var_for_const_229 = ((int32_t))),
                   (Addr) &(temp_var_for_const_228 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:60:34");
      computeDMul((Addr)&temp_var_for_tac_115,
                  {(Addr) &(temp_var_for_const_231 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_230 = W52)},
                  "/home/shijia/Public/testprogram/t_expf.h:60:54");
      computeDMul((Addr)&temp_var_for_tac_116,
                  {(Addr) &(temp_var_for_const_233 = ((int32_t))),
                   (Addr) &(temp_var_for_const_232 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:60:73");
      computeDMul((Addr)&temp_var_for_tac_117,
                  {(Addr) &(temp_var_for_const_235 = ((int32_t))),
                   (Addr) &(temp_var_for_const_234 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:61:14");
      computeDMul((Addr)&temp_var_for_tac_118,
                  {(Addr) &(temp_var_for_const_237 = ((int32_t))),
                   (Addr) &(temp_var_for_const_236 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:61:32");
      computeDMul((Addr)&temp_var_for_tac_119,
                  {(Addr) &(temp_var_for_const_239 = ((int32_t))),
                   (Addr) &(temp_var_for_const_238 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:61:51");
      computeDMul((Addr)&temp_var_for_tac_120,
                  {(Addr) &(temp_var_for_const_241 = ((int32_t))),
                   (Addr) &(temp_var_for_const_240 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:61:70");
      computeDMul((Addr)&temp_var_for_tac_121,
                  {(Addr) &(temp_var_for_const_243 = ((int32_t))),
                   (Addr) &(temp_var_for_const_242 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:62:14");
      computeDMul((Addr)&temp_var_for_tac_122,
                  {(Addr) &(temp_var_for_const_245 = ((int32_t))),
                   (Addr) &(temp_var_for_const_244 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:62:33");
      computeDMul((Addr)&temp_var_for_tac_123,
                  {(Addr) &(temp_var_for_const_247 = ((int32_t))),
                   (Addr) &(temp_var_for_const_246 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:62:51");
      computeDMul((Addr)&temp_var_for_tac_124,
                  {(Addr) &(temp_var_for_const_249 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_248 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:62:69");
      computeDMul((Addr)&temp_var_for_tac_125,
                  {(Addr) &(temp_var_for_const_251 = ((int32_t))),
                   (Addr) &(temp_var_for_const_250 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:63:14");
      computeDMul((Addr)&temp_var_for_tac_126,
                  {(Addr) &(temp_var_for_const_253 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_252 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:63:34");
      computeDMul((Addr)&temp_var_for_tac_127,
                  {(Addr) &(temp_var_for_const_255 = ((int32_t))),
                   (Addr) &(temp_var_for_const_254 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:63:53");
      computeDMul((Addr)&temp_var_for_tac_128,
                  {(Addr) &(temp_var_for_const_257 = ((int32_t))),
                   (Addr) &(temp_var_for_const_256 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:63:72");
      computeDMul((Addr)&temp_var_for_tac_129,
                  {(Addr) &(temp_var_for_const_259 = ((int32_t))),
                   (Addr) &(temp_var_for_const_258 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:64:14");
      computeDMul((Addr)&temp_var_for_tac_130,
                  {(Addr) &(temp_var_for_const_261 = ((int32_t))),
                   (Addr) &(temp_var_for_const_260 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:64:32");
      computeDMul((Addr)&temp_var_for_tac_131,
                  {(Addr) &(temp_var_for_const_263 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_262 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:64:52");
      computeDMul((Addr)&temp_var_for_tac_132,
                  {(Addr) &(temp_var_for_const_265 = ((int32_t))),
                   (Addr) &(temp_var_for_const_264 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:64:71");
      computeDMul((Addr)&temp_var_for_tac_133,
                  {(Addr) &(temp_var_for_const_267 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_266 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:65:15");
      computeDMul((Addr)&temp_var_for_tac_134,
                  {(Addr) &(temp_var_for_const_269 = ((int32_t))),
                   (Addr) &(temp_var_for_const_268 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:65:34");
      computeDMul((Addr)&temp_var_for_tac_135,
                  {(Addr) &(temp_var_for_const_271 = ((int32_t))),
                   (Addr) &(temp_var_for_const_270 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:65:53");
      computeDMul((Addr)&temp_var_for_tac_136,
                  {(Addr) &(temp_var_for_const_273 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_272 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:65:72");
      computeDMul((Addr)&temp_var_for_tac_137,
                  {(Addr) &(temp_var_for_const_275 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_274 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:66:15");
      computeDMul((Addr)&temp_var_for_tac_138,
                  {(Addr) &(temp_var_for_const_277 = ((int32_t))),
                   (Addr) &(temp_var_for_const_276 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:66:34");
      computeDMul((Addr)&temp_var_for_tac_139,
                  {(Addr) &(temp_var_for_const_279 = ((int32_t))),
                   (Addr) &(temp_var_for_const_278 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:66:52");
      computeDMul((Addr)&temp_var_for_tac_140,
                  {(Addr) &(temp_var_for_const_281 = ((int32_t))),
                   (Addr) &(temp_var_for_const_280 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:66:71");
      computeDMul((Addr)&temp_var_for_tac_141,
                  {(Addr) &(temp_var_for_const_283 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_282 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:67:15");
      computeDMul((Addr)&temp_var_for_tac_142,
                  {(Addr) &(temp_var_for_const_285 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_284 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:67:36");
      computeDMul((Addr)&temp_var_for_tac_143,
                  {(Addr) &(temp_var_for_const_287 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_286 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:67:54");
      computeDMul((Addr)&temp_var_for_tac_144,
                  {(Addr) &(temp_var_for_const_289 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_288 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:67:74");
      computeDMul((Addr)&temp_var_for_tac_145,
                  {(Addr) &(temp_var_for_const_291 = ((int32_t))),
                   (Addr) &(temp_var_for_const_290 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:68:13");
      computeDMul((Addr)&temp_var_for_tac_146,
                  {(Addr) &(temp_var_for_const_293 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_292 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:68:33");
      computeDMul((Addr)&temp_var_for_tac_147,
                  {(Addr) &(temp_var_for_const_295 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_294 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:68:52");
      computeDMul((Addr)&temp_var_for_tac_148,
                  {(Addr) &(temp_var_for_const_297 = ((int32_t))),
                   (Addr) &(temp_var_for_const_296 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:68:71");
      computeDMul((Addr)&temp_var_for_tac_149,
                  {(Addr) &(temp_var_for_const_299 = ((int32_t))),
                   (Addr) &(temp_var_for_const_298 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:69:14");
      computeDMul((Addr)&temp_var_for_tac_150,
                  {(Addr) &(temp_var_for_const_301 = ((int32_t))),
                   (Addr) &(temp_var_for_const_300 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:69:33");
      computeDMul((Addr)&temp_var_for_tac_151,
                  {(Addr) &(temp_var_for_const_303 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_302 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:69:52");
      computeDMul((Addr)&temp_var_for_tac_152,
                  {(Addr) &(temp_var_for_const_305 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_304 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:69:72");
      computeDMul((Addr)&temp_var_for_tac_153,
                  {(Addr) &(temp_var_for_const_307 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_306 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:70:15");
      computeDMul((Addr)&temp_var_for_tac_154,
                  {(Addr) &(temp_var_for_const_309 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_308 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:70:35");
      computeDMul((Addr)&temp_var_for_tac_155,
                  {(Addr) &(temp_var_for_const_311 = ((int32_t))),
                   (Addr) &(temp_var_for_const_310 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:70:53");
      computeDMul((Addr)&temp_var_for_tac_156,
                  {(Addr) &(temp_var_for_const_313 = ((int32_t))),
                   (Addr) &(temp_var_for_const_312 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:70:71");
      computeDMul((Addr)&temp_var_for_tac_157,
                  {(Addr) &(temp_var_for_const_315 = ((int32_t))),
                   (Addr) &(temp_var_for_const_314 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:71:14");
      computeDMul((Addr)&temp_var_for_tac_158,
                  {(Addr) &(temp_var_for_const_317 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_316 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:71:34");
      computeDMul((Addr)&temp_var_for_tac_159,
                  {(Addr) &(temp_var_for_const_319 = ((int32_t))),
                   (Addr) &(temp_var_for_const_318 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:71:52");
      computeDMul((Addr)&temp_var_for_tac_160,
                  {(Addr) &(temp_var_for_const_321 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_320 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:71:73");
      computeDMul((Addr)&temp_var_for_tac_161,
                  {(Addr) &(temp_var_for_const_323 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_322 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:72:15");
      computeDMul((Addr)&temp_var_for_tac_162,
                  {(Addr) &(temp_var_for_const_325 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_324 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:72:34");
      computeDMul((Addr)&temp_var_for_tac_163,
                  {(Addr) &(temp_var_for_const_327 = ((int32_t))),
                   (Addr) &(temp_var_for_const_326 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:72:53");
      computeDMul((Addr)&temp_var_for_tac_164,
                  {(Addr) &(temp_var_for_const_329 = ((int32_t))),
                   (Addr) &(temp_var_for_const_328 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:72:72");
      computeDMul((Addr)&temp_var_for_tac_165,
                  {(Addr) &(temp_var_for_const_331 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_330 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:73:15");
      computeDMul((Addr)&temp_var_for_tac_166,
                  {(Addr) &(temp_var_for_const_333 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_332 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:73:35");
      computeDMul((Addr)&temp_var_for_tac_167,
                  {(Addr) &(temp_var_for_const_335 = ((int32_t))),
                   (Addr) &(temp_var_for_const_334 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:73:53");
      computeDMul((Addr)&temp_var_for_tac_168,
                  {(Addr) &(temp_var_for_const_337 = ((int32_t))),
                   (Addr) &(temp_var_for_const_336 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:73:72");
      computeDMul((Addr)&temp_var_for_tac_169,
                  {(Addr) &(temp_var_for_const_339 = ((int32_t))),
                   (Addr) &(temp_var_for_const_338 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:74:15");
      computeDMul((Addr)&temp_var_for_tac_170,
                  {(Addr) &(temp_var_for_const_341 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_340 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:74:36");
      computeDMul((Addr)&temp_var_for_tac_171,
                  {(Addr) &(temp_var_for_const_343 = ((int32_t))),
                   (Addr) &(temp_var_for_const_342 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:74:55");
      computeDMul((Addr)&temp_var_for_tac_172,
                  {(Addr) &(temp_var_for_const_345 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_344 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:74:75");
      computeDMul((Addr)&temp_var_for_tac_173,
                  {(Addr) &(temp_var_for_const_347 = ((int32_t))),
                   (Addr) &(temp_var_for_const_346 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:75:14");
      computeDMul((Addr)&temp_var_for_tac_174,
                  {(Addr) &(temp_var_for_const_349 = ((int32_t))),
                   (Addr) &(temp_var_for_const_348 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:75:33");
      computeDMul((Addr)&temp_var_for_tac_175,
                  {(Addr) &(temp_var_for_const_351 = ((int32_t))),
                   (Addr) &(temp_var_for_const_350 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:75:49");
      computeDMul((Addr)&temp_var_for_tac_176,
                  {(Addr) &(temp_var_for_const_353 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_352 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:75:68");
      computeDMul((Addr)&temp_var_for_tac_177,
                  {(Addr) &(temp_var_for_const_355 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_354 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:76:15");
      computeDMul((Addr)&temp_var_for_tac_178,
                  {(Addr) &(temp_var_for_const_357 = ((int32_t))),
                   (Addr) &(temp_var_for_const_356 = W60)},
                  "/home/shijia/Public/testprogram/t_expf.h:76:34");
      computeFMul((Addr)&temp_var_for_tac_179,
                  {(Addr)&x, (Addr) &(temp_var_for_const_358 = m_1_ln2)},
                  "/home/shijia/Public/testprogram/e_expf.c_e.c:83:13");
      computeFAdd((Addr)&temp_var_for_tac_180,
                  {(Addr)&temp_var_for_tac_179,
                   (Addr) &(temp_var_for_const_359 = THREEp22)},
                  "/home/shijia/Public/testprogram/e_expf.c_e.c:83:23");
      computeDMul((Addr)&temp_var_for_tac_181,
                  {(Addr) &(temp_var_for_const_361 = n),
                   (Addr) &(temp_var_for_const_360 = m_ln2)},
                  "/home/shijia/Public/testprogram/e_expf.c_e.c:85:18");
      computeDSub((Addr)&temp_var_for_tac_182,
                  {(Addr)&x, (Addr)&temp_var_for_tac_181},
                  "/home/shijia/Public/testprogram/e_expf.c_e.c:85:14");
      computeDAdd((Addr)&temp_var_for_tac_183,
                  {(Addr) &(temp_var_for_const_363 = dx),
                   (Addr) &(temp_var_for_const_362 = THREEp42)},
                  "/home/shijia/Public/testprogram/e_expf.c_e.c:88:14");
      computeDMul((Addr)&temp_var_for_tac_184,
                  {(Addr) &(temp_var_for_const_365 = t),
                   (Addr) &(temp_var_for_const_364 = 512.0)},
                  "/home/shijia/Public/testprogram/e_expf.c_e.c:93:22");
      compute((Addr)&temp_var_for_tac_185,
              {(Addr) &(temp_var_for_const_367 = t),
               (Addr) &(temp_var_for_const_366 = 0)},
              "/home/shijia/Public/testprogram/e_expf.c_e.c:95:13");
      computeDSub((Addr)&temp_var_for_tac_186,
                  {(Addr) &(temp_var_for_const_369 = 0.0),
                   (Addr) &(temp_var_for_const_368 = __exp_deltatable[tval])},
                  "/home/shijia/Public/testprogram/e_expf.c_e.c:96:22");
      AssignD({(Addr)&ex2_u},
              (Addr) &(temp_var_for_const_370 = __exp_atable[tval + 177]),
              "/home/shijia/Public/testprogram/e_expf.c_e.c:104:13");
      ;
      GET_HIGH_WORD(exponent, ex2_u);
      exponent += ((int32_t)n) << IEEE754_DOUBLE_SHIFT;
      SET_HIGH_WORD(ex2_u, exponent);

      /* Approximate e^(dx+delta) - 1, using a second-degree polynomial,
         with maximum error in [-2^-10-2^-28,2^-10+2^-28]
         less than 5e-11.  */
      x22 = double temp_var_for_tac_187, temp_var_for_tac_188,
      temp_var_for_tac_189, temp_var_for_tac_190;
      double temp_var_for_const_371, temp_var_for_const_372,
          temp_var_for_const_373, temp_var_for_const_374,
          temp_var_for_const_375;
      temp_var_for_tac_187 = 0.5000000496709180453 * dx;

      temp_var_for_tac_188 = temp_var_for_tac_187 + 1.0000001192102037084;

      temp_var_for_tac_189 = temp_var_for_tac_188 * dx;

      temp_var_for_tac_190 = temp_var_for_tac_189 + delta;

      ;
      RESTORE_ROUND();
    }
  }
}

/* Return result.  */
result = x22 * ex2_u + ex2_u;
return (float)result;
}
/* Exceptional cases:  */
if (isless(x, himark)) {
  if (isinf(x))
      /* e^-inf == 0, with no error.  */
      {
    return 0;
  }

  /* Underflow */
  feraiseexcept(FE_UNDERFLOW);
  return 0;
}
/* Return x, if x is a NaN or Inf; or overflow, otherwise.  */
if (isinf(x)) {
  return HUGE_VALF;
}

if (isnan(x)) {
  return x;
}

feraiseexcept(FE_OVERFLOW);
return HUGE_VALF;
}

#endif

/* wrapper exp */
float __expf(float x) {
  float z = __ieee754_expf(x);

  if ((!isfinite(z) || int temp_var_for_tac_191; int temp_var_for_const_376;
       temp_var_for_tac_191 = z == 0.0f;

       ) &&
      isfinite(x) && _LIB_VERSION != _IEEE_) {
    float temp_var_for_ext_0;
    float temp_var_for_const_377;
    float temp_var_for_callexp_0;

    temp_var_for_callexp_0 = __kernel_standard_f(
        x, x, z, signbit(x) ? KMATHERRF_EXP_UNDERFLOW : KMATHERRF_EXP_OVERFLOW);
    temp_var_for_ext_0 = temp_var_for_callexp_0;
    computeDMul((Addr)&temp_var_for_tac_187,
                {(Addr) &(temp_var_for_const_372 = 0.5000000496709180453),
                 (Addr) &(temp_var_for_const_371 = dx)},
                "/home/shijia/Public/testprogram/e_expf.c_e.c:112:36");
    computeDAdd((Addr)&temp_var_for_tac_188,
                {(Addr)&temp_var_for_tac_187,
                 (Addr) &(temp_var_for_const_373 = 1.0000001192102037084)},
                "/home/shijia/Public/testprogram/e_expf.c_e.c:112:41");
    computeDMul(
        (Addr)&temp_var_for_tac_189,
        {(Addr)&temp_var_for_tac_188, (Addr) &(temp_var_for_const_374 = dx)},
        "/home/shijia/Public/testprogram/e_expf.c_e.c:112:66");
    computeDAdd(
        (Addr)&temp_var_for_tac_190,
        {(Addr)&temp_var_for_tac_189, (Addr) &(temp_var_for_const_375 = delta)},
        "/home/shijia/Public/testprogram/e_expf.c_e.c:112:71");
    compute((Addr)&temp_var_for_tac_191,
            {(Addr)&z, (Addr) &(temp_var_for_const_376 = 0.0f)},
            "/home/shijia/Public/testprogram/e_expf.c_e.c:153:26");
    AssignF({(Addr)&temp_var_for_ext_0},
            (Addr) &(temp_var_for_const_377 = temp_var_for_callexp_0),
            "/home/shijia/Public/testprogram/e_expf.c_e.c:155:24");
    ;
    callExpStack.push(getReal("temp_var_for_ext_0", (Addr)&temp_var_for_ext_0));
    callExp++; /*identify the function is  add move tmpShadow*/
    return temp_var_for_ext_0;
  }

  float temp_var_for_ext_1;
  temp_var_for_ext_1 = z;
  callExpStack.push(getReal("temp_var_for_ext_1", (Addr)&temp_var_for_ext_1));
  callExp++; /*identify the function is  add move tmpShadow*/
  return temp_var_for_ext_1;
}

__typeof(__expf) expf __attribute__((weak, alias("__expf")));
