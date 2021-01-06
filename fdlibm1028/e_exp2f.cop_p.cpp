#include "../ScDebug/scdebug.h"
/* Single-precision floating point 2^x.
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

/* The basic design here is from
   Shmuel Gal and Boris Bachelis, "An Accurate Elementary Mathematical
   Library for the IEEE Floating Point Standard", ACM Trans. Math. Soft.,
   17 (1), March 1991, pp. 26-45.
   It has been slightly modified to compute 2^x instead of e^x, and for
   single-precision.
   */

#ifndef __FDLIBM_H__
#include "fdlibm.h"
#endif

#ifndef __have_fpu_exp2

#undef abs
#define abs(x) ((x) < 0 ? -(x) : (x))

float __ieee754_exp2f(float x) {
  static const float himark = (float)FLT_MAX_EXP;
  static const float lomark = (float)(FLT_MIN_EXP - FLT_MANT_DIG - 1);

  static const volatile float TWOM100 = 7.88860905e-31;
  static const volatile float TWO127 = 1.7014118346e+38;

#include "t_exp2f.h"

  /* Check for usual case.  */
  if (isless(x, himark) && isgreaterequal(x, lomark)) {
    static const float THREEp14 = 49152.0;
    int32_t tval, unsafe;
    float rx, x22, result;
    float ex2_u, scale_u;
    uint32_t exp;

    if (__ieee754_fabsf(x) < FLT_EPSILON / 4.0f)
      return 1.0f + x;

    {
      SAVE_AND_SET_ROUND(FE_TONEAREST);

      /* 1. Argument reduction.
         Choose integers ex, -128 <= t < 128, and some real
         -1/512 <= x1 <= 1/512 so that
         x = ex + t/512 + x1.

         First, calculate rx = ex + t/256.  */
      float temp_var_for_tac_256;
      float temp_var_for_const_512;
      temp_var_for_tac_256 = x + THREEp14;

      rx = temp_var_for_tac_256;
      computeDMul((Addr)&temp_var_for_tac_0,
                  {(Addr) &(temp_var_for_const_1 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_0 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:28:15");
      computeDMul((Addr)&temp_var_for_tac_1,
                  {(Addr) &(temp_var_for_const_3 = ((int32_t))),
                   (Addr) &(temp_var_for_const_2 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:28:34");
      computeDMul((Addr)&temp_var_for_tac_2,
                  {(Addr) &(temp_var_for_const_5 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_4 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:28:53");
      computeDMul((Addr)&temp_var_for_tac_3,
                  {(Addr) &(temp_var_for_const_7 = ((int32_t))),
                   (Addr) &(temp_var_for_const_6 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:28:72");
      computeDMul((Addr)&temp_var_for_tac_4,
                  {(Addr) &(temp_var_for_const_9 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_8 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:29:15");
      computeDMul((Addr)&temp_var_for_tac_5,
                  {(Addr) &(temp_var_for_const_11 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_10 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:29:34");
      computeDMul((Addr)&temp_var_for_tac_6,
                  {(Addr) &(temp_var_for_const_13 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_12 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:29:53");
      computeDMul((Addr)&temp_var_for_tac_7,
                  {(Addr) &(temp_var_for_const_15 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_14 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:29:72");
      computeDMul((Addr)&temp_var_for_tac_8,
                  {(Addr) &(temp_var_for_const_17 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_16 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:30:15");
      computeDMul((Addr)&temp_var_for_tac_9,
                  {(Addr) &(temp_var_for_const_19 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_18 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:30:34");
      computeDMul((Addr)&temp_var_for_tac_10,
                  {(Addr) &(temp_var_for_const_21 = ((int32_t))),
                   (Addr) &(temp_var_for_const_20 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:30:53");
      computeDMul((Addr)&temp_var_for_tac_11,
                  {(Addr) &(temp_var_for_const_23 = ((int32_t))),
                   (Addr) &(temp_var_for_const_22 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:30:72");
      computeDMul((Addr)&temp_var_for_tac_12,
                  {(Addr) &(temp_var_for_const_25 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_24 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:31:15");
      computeDMul((Addr)&temp_var_for_tac_13,
                  {(Addr) &(temp_var_for_const_27 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_26 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:31:34");
      computeDMul((Addr)&temp_var_for_tac_14,
                  {(Addr) &(temp_var_for_const_29 = ((int32_t))),
                   (Addr) &(temp_var_for_const_28 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:31:53");
      computeDMul((Addr)&temp_var_for_tac_15,
                  {(Addr) &(temp_var_for_const_31 = ((int32_t))),
                   (Addr) &(temp_var_for_const_30 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:31:72");
      computeDMul((Addr)&temp_var_for_tac_16,
                  {(Addr) &(temp_var_for_const_33 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_32 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:32:15");
      computeDMul((Addr)&temp_var_for_tac_17,
                  {(Addr) &(temp_var_for_const_35 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_34 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:32:34");
      computeDMul((Addr)&temp_var_for_tac_18,
                  {(Addr) &(temp_var_for_const_37 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_36 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:32:53");
      computeDMul((Addr)&temp_var_for_tac_19,
                  {(Addr) &(temp_var_for_const_39 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_38 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:32:72");
      computeDMul((Addr)&temp_var_for_tac_20,
                  {(Addr) &(temp_var_for_const_41 = ((int32_t))),
                   (Addr) &(temp_var_for_const_40 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:33:15");
      computeDMul((Addr)&temp_var_for_tac_21,
                  {(Addr) &(temp_var_for_const_43 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_42 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:33:34");
      computeDMul((Addr)&temp_var_for_tac_22,
                  {(Addr) &(temp_var_for_const_45 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_44 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:33:53");
      computeDMul((Addr)&temp_var_for_tac_23,
                  {(Addr) &(temp_var_for_const_47 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_46 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:33:72");
      computeDMul((Addr)&temp_var_for_tac_24,
                  {(Addr) &(temp_var_for_const_49 = ((int32_t))),
                   (Addr) &(temp_var_for_const_48 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:34:15");
      computeDMul((Addr)&temp_var_for_tac_25,
                  {(Addr) &(temp_var_for_const_51 = ((int32_t))),
                   (Addr) &(temp_var_for_const_50 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:34:34");
      computeDMul((Addr)&temp_var_for_tac_26,
                  {(Addr) &(temp_var_for_const_53 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_52 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:34:53");
      computeDMul((Addr)&temp_var_for_tac_27,
                  {(Addr) &(temp_var_for_const_55 = ((int32_t))),
                   (Addr) &(temp_var_for_const_54 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:34:72");
      computeDMul((Addr)&temp_var_for_tac_28,
                  {(Addr) &(temp_var_for_const_57 = ((int32_t))),
                   (Addr) &(temp_var_for_const_56 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:35:15");
      computeDMul((Addr)&temp_var_for_tac_29,
                  {(Addr) &(temp_var_for_const_59 = ((int32_t))),
                   (Addr) &(temp_var_for_const_58 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:35:34");
      computeDMul((Addr)&temp_var_for_tac_30,
                  {(Addr) &(temp_var_for_const_61 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_60 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:35:53");
      computeDMul((Addr)&temp_var_for_tac_31,
                  {(Addr) &(temp_var_for_const_63 = ((int32_t))),
                   (Addr) &(temp_var_for_const_62 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:35:72");
      computeDMul((Addr)&temp_var_for_tac_32,
                  {(Addr) &(temp_var_for_const_65 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_64 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:36:15");
      computeDMul((Addr)&temp_var_for_tac_33,
                  {(Addr) &(temp_var_for_const_67 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_66 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:36:34");
      computeDMul((Addr)&temp_var_for_tac_34,
                  {(Addr) &(temp_var_for_const_69 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_68 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:36:53");
      computeDMul((Addr)&temp_var_for_tac_35,
                  {(Addr) &(temp_var_for_const_71 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_70 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:36:72");
      computeDMul((Addr)&temp_var_for_tac_36,
                  {(Addr) &(temp_var_for_const_73 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_72 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:37:15");
      computeDMul((Addr)&temp_var_for_tac_37,
                  {(Addr) &(temp_var_for_const_75 = ((int32_t))),
                   (Addr) &(temp_var_for_const_74 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:37:34");
      computeDMul((Addr)&temp_var_for_tac_38,
                  {(Addr) &(temp_var_for_const_77 = ((int32_t))),
                   (Addr) &(temp_var_for_const_76 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:37:53");
      computeDMul((Addr)&temp_var_for_tac_39,
                  {(Addr) &(temp_var_for_const_79 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_78 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:37:72");
      computeDMul((Addr)&temp_var_for_tac_40,
                  {(Addr) &(temp_var_for_const_81 = ((int32_t))),
                   (Addr) &(temp_var_for_const_80 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:38:15");
      computeDMul((Addr)&temp_var_for_tac_41,
                  {(Addr) &(temp_var_for_const_83 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_82 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:38:34");
      computeDMul((Addr)&temp_var_for_tac_42,
                  {(Addr) &(temp_var_for_const_85 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_84 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:38:53");
      computeDMul((Addr)&temp_var_for_tac_43,
                  {(Addr) &(temp_var_for_const_87 = ((int32_t))),
                   (Addr) &(temp_var_for_const_86 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:38:72");
      computeDMul((Addr)&temp_var_for_tac_44,
                  {(Addr) &(temp_var_for_const_89 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_88 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:39:15");
      computeDMul((Addr)&temp_var_for_tac_45,
                  {(Addr) &(temp_var_for_const_91 = ((int32_t))),
                   (Addr) &(temp_var_for_const_90 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:39:34");
      computeDMul((Addr)&temp_var_for_tac_46,
                  {(Addr) &(temp_var_for_const_93 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_92 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:39:53");
      computeDMul((Addr)&temp_var_for_tac_47,
                  {(Addr) &(temp_var_for_const_95 = ((int32_t))),
                   (Addr) &(temp_var_for_const_94 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:39:72");
      computeDMul((Addr)&temp_var_for_tac_48,
                  {(Addr) &(temp_var_for_const_97 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_96 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:40:15");
      computeDMul((Addr)&temp_var_for_tac_49,
                  {(Addr) &(temp_var_for_const_99 = ((int32_t))),
                   (Addr) &(temp_var_for_const_98 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:40:34");
      computeDMul((Addr)&temp_var_for_tac_50,
                  {(Addr) &(temp_var_for_const_101 = ((int32_t))),
                   (Addr) &(temp_var_for_const_100 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:40:53");
      computeDMul((Addr)&temp_var_for_tac_51,
                  {(Addr) &(temp_var_for_const_103 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_102 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:40:72");
      computeDMul((Addr)&temp_var_for_tac_52,
                  {(Addr) &(temp_var_for_const_105 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_104 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:41:15");
      computeDMul((Addr)&temp_var_for_tac_53,
                  {(Addr) &(temp_var_for_const_107 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_106 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:41:34");
      computeDMul((Addr)&temp_var_for_tac_54,
                  {(Addr) &(temp_var_for_const_109 = ((int32_t))),
                   (Addr) &(temp_var_for_const_108 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:41:53");
      computeDMul((Addr)&temp_var_for_tac_55,
                  {(Addr) &(temp_var_for_const_111 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_110 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:41:72");
      computeDMul((Addr)&temp_var_for_tac_56,
                  {(Addr) &(temp_var_for_const_113 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_112 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:42:15");
      computeDMul((Addr)&temp_var_for_tac_57,
                  {(Addr) &(temp_var_for_const_115 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_114 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:42:34");
      computeDMul((Addr)&temp_var_for_tac_58,
                  {(Addr) &(temp_var_for_const_117 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_116 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:42:53");
      computeDMul((Addr)&temp_var_for_tac_59,
                  {(Addr) &(temp_var_for_const_119 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_118 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:42:72");
      computeDMul((Addr)&temp_var_for_tac_60,
                  {(Addr) &(temp_var_for_const_121 = ((int32_t))),
                   (Addr) &(temp_var_for_const_120 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:43:15");
      computeDMul((Addr)&temp_var_for_tac_61,
                  {(Addr) &(temp_var_for_const_123 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_122 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:43:34");
      computeDMul((Addr)&temp_var_for_tac_62,
                  {(Addr) &(temp_var_for_const_125 = ((int32_t))),
                   (Addr) &(temp_var_for_const_124 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:43:53");
      computeDMul((Addr)&temp_var_for_tac_63,
                  {(Addr) &(temp_var_for_const_127 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_126 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:43:72");
      computeDMul((Addr)&temp_var_for_tac_64,
                  {(Addr) &(temp_var_for_const_129 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_128 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:44:15");
      computeDMul((Addr)&temp_var_for_tac_65,
                  {(Addr) &(temp_var_for_const_131 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_130 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:44:34");
      computeDMul((Addr)&temp_var_for_tac_66,
                  {(Addr) &(temp_var_for_const_133 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_132 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:44:53");
      computeDMul((Addr)&temp_var_for_tac_67,
                  {(Addr) &(temp_var_for_const_135 = ((int32_t))),
                   (Addr) &(temp_var_for_const_134 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:44:72");
      computeDMul((Addr)&temp_var_for_tac_68,
                  {(Addr) &(temp_var_for_const_137 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_136 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:45:15");
      computeDMul((Addr)&temp_var_for_tac_69,
                  {(Addr) &(temp_var_for_const_139 = ((int32_t))),
                   (Addr) &(temp_var_for_const_138 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:45:34");
      computeDMul((Addr)&temp_var_for_tac_70,
                  {(Addr) &(temp_var_for_const_141 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_140 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:45:53");
      computeDMul((Addr)&temp_var_for_tac_71,
                  {(Addr) &(temp_var_for_const_143 = ((int32_t))),
                   (Addr) &(temp_var_for_const_142 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:45:72");
      computeDMul((Addr)&temp_var_for_tac_72,
                  {(Addr) &(temp_var_for_const_145 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_144 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:46:15");
      computeDMul((Addr)&temp_var_for_tac_73,
                  {(Addr) &(temp_var_for_const_147 = ((int32_t))),
                   (Addr) &(temp_var_for_const_146 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:46:34");
      computeDMul((Addr)&temp_var_for_tac_74,
                  {(Addr) &(temp_var_for_const_149 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_148 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:46:53");
      computeDMul((Addr)&temp_var_for_tac_75,
                  {(Addr) &(temp_var_for_const_151 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_150 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:46:72");
      computeDMul((Addr)&temp_var_for_tac_76,
                  {(Addr) &(temp_var_for_const_153 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_152 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:47:15");
      computeDMul((Addr)&temp_var_for_tac_77,
                  {(Addr) &(temp_var_for_const_155 = ((int32_t))),
                   (Addr) &(temp_var_for_const_154 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:47:34");
      computeDMul((Addr)&temp_var_for_tac_78,
                  {(Addr) &(temp_var_for_const_157 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_156 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:47:53");
      computeDMul((Addr)&temp_var_for_tac_79,
                  {(Addr) &(temp_var_for_const_159 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_158 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:47:72");
      computeDMul((Addr)&temp_var_for_tac_80,
                  {(Addr) &(temp_var_for_const_161 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_160 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:48:15");
      computeDMul((Addr)&temp_var_for_tac_81,
                  {(Addr) &(temp_var_for_const_163 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_162 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:48:34");
      computeDMul((Addr)&temp_var_for_tac_82,
                  {(Addr) &(temp_var_for_const_165 = ((int32_t))),
                   (Addr) &(temp_var_for_const_164 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:48:53");
      computeDMul((Addr)&temp_var_for_tac_83,
                  {(Addr) &(temp_var_for_const_167 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_166 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:48:72");
      computeDMul((Addr)&temp_var_for_tac_84,
                  {(Addr) &(temp_var_for_const_169 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_168 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:49:15");
      computeDMul((Addr)&temp_var_for_tac_85,
                  {(Addr) &(temp_var_for_const_171 = ((int32_t))),
                   (Addr) &(temp_var_for_const_170 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:49:34");
      computeDMul((Addr)&temp_var_for_tac_86,
                  {(Addr) &(temp_var_for_const_173 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_172 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:49:53");
      computeDMul((Addr)&temp_var_for_tac_87,
                  {(Addr) &(temp_var_for_const_175 = ((int32_t))),
                   (Addr) &(temp_var_for_const_174 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:49:72");
      computeDMul((Addr)&temp_var_for_tac_88,
                  {(Addr) &(temp_var_for_const_177 = ((int32_t))),
                   (Addr) &(temp_var_for_const_176 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:50:15");
      computeDMul((Addr)&temp_var_for_tac_89,
                  {(Addr) &(temp_var_for_const_179 = ((int32_t))),
                   (Addr) &(temp_var_for_const_178 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:50:34");
      computeDMul((Addr)&temp_var_for_tac_90,
                  {(Addr) &(temp_var_for_const_181 = ((int32_t))),
                   (Addr) &(temp_var_for_const_180 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:50:53");
      computeDMul((Addr)&temp_var_for_tac_91,
                  {(Addr) &(temp_var_for_const_183 = ((int32_t))),
                   (Addr) &(temp_var_for_const_182 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:50:72");
      computeDMul((Addr)&temp_var_for_tac_92,
                  {(Addr) &(temp_var_for_const_185 = ((int32_t))),
                   (Addr) &(temp_var_for_const_184 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:51:15");
      computeDMul((Addr)&temp_var_for_tac_93,
                  {(Addr) &(temp_var_for_const_187 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_186 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:51:34");
      computeDMul((Addr)&temp_var_for_tac_94,
                  {(Addr) &(temp_var_for_const_189 = ((int32_t))),
                   (Addr) &(temp_var_for_const_188 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:51:53");
      computeDMul((Addr)&temp_var_for_tac_95,
                  {(Addr) &(temp_var_for_const_191 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_190 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:51:72");
      computeDMul((Addr)&temp_var_for_tac_96,
                  {(Addr) &(temp_var_for_const_193 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_192 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:52:15");
      computeDMul((Addr)&temp_var_for_tac_97,
                  {(Addr) &(temp_var_for_const_195 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_194 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:52:34");
      computeDMul((Addr)&temp_var_for_tac_98,
                  {(Addr) &(temp_var_for_const_197 = ((int32_t))),
                   (Addr) &(temp_var_for_const_196 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:52:53");
      computeDMul((Addr)&temp_var_for_tac_99,
                  {(Addr) &(temp_var_for_const_199 = ((int32_t))),
                   (Addr) &(temp_var_for_const_198 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:52:72");
      computeDMul((Addr)&temp_var_for_tac_100,
                  {(Addr) &(temp_var_for_const_201 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_200 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:53:15");
      computeDMul((Addr)&temp_var_for_tac_101,
                  {(Addr) &(temp_var_for_const_203 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_202 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:53:34");
      computeDMul((Addr)&temp_var_for_tac_102,
                  {(Addr) &(temp_var_for_const_205 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_204 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:53:53");
      computeDMul((Addr)&temp_var_for_tac_103,
                  {(Addr) &(temp_var_for_const_207 = ((int32_t))),
                   (Addr) &(temp_var_for_const_206 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:53:72");
      computeDMul((Addr)&temp_var_for_tac_104,
                  {(Addr) &(temp_var_for_const_209 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_208 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:54:15");
      computeDMul((Addr)&temp_var_for_tac_105,
                  {(Addr) &(temp_var_for_const_211 = ((int32_t))),
                   (Addr) &(temp_var_for_const_210 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:54:34");
      computeDMul((Addr)&temp_var_for_tac_106,
                  {(Addr) &(temp_var_for_const_213 = ((int32_t))),
                   (Addr) &(temp_var_for_const_212 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:54:53");
      computeDMul((Addr)&temp_var_for_tac_107,
                  {(Addr) &(temp_var_for_const_215 = ((int32_t))),
                   (Addr) &(temp_var_for_const_214 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:54:72");
      computeDMul((Addr)&temp_var_for_tac_108,
                  {(Addr) &(temp_var_for_const_217 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_216 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:55:15");
      computeDMul((Addr)&temp_var_for_tac_109,
                  {(Addr) &(temp_var_for_const_219 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_218 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:55:34");
      computeDMul((Addr)&temp_var_for_tac_110,
                  {(Addr) &(temp_var_for_const_221 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_220 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:55:53");
      computeDMul((Addr)&temp_var_for_tac_111,
                  {(Addr) &(temp_var_for_const_223 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_222 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:55:72");
      computeDMul((Addr)&temp_var_for_tac_112,
                  {(Addr) &(temp_var_for_const_225 = ((int32_t))),
                   (Addr) &(temp_var_for_const_224 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:56:15");
      computeDMul((Addr)&temp_var_for_tac_113,
                  {(Addr) &(temp_var_for_const_227 = ((int32_t))),
                   (Addr) &(temp_var_for_const_226 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:56:34");
      computeDMul((Addr)&temp_var_for_tac_114,
                  {(Addr) &(temp_var_for_const_229 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_228 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:56:53");
      computeDMul((Addr)&temp_var_for_tac_115,
                  {(Addr) &(temp_var_for_const_231 = ((int32_t))),
                   (Addr) &(temp_var_for_const_230 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:56:72");
      computeDMul((Addr)&temp_var_for_tac_116,
                  {(Addr) &(temp_var_for_const_233 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_232 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:57:15");
      computeDMul((Addr)&temp_var_for_tac_117,
                  {(Addr) &(temp_var_for_const_235 = ((int32_t))),
                   (Addr) &(temp_var_for_const_234 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:57:34");
      computeDMul((Addr)&temp_var_for_tac_118,
                  {(Addr) &(temp_var_for_const_237 = ((int32_t))),
                   (Addr) &(temp_var_for_const_236 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:57:53");
      computeDMul((Addr)&temp_var_for_tac_119,
                  {(Addr) &(temp_var_for_const_239 = ((int32_t))),
                   (Addr) &(temp_var_for_const_238 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:57:72");
      computeDMul((Addr)&temp_var_for_tac_120,
                  {(Addr) &(temp_var_for_const_241 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_240 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:58:15");
      computeDMul((Addr)&temp_var_for_tac_121,
                  {(Addr) &(temp_var_for_const_243 = ((int32_t))),
                   (Addr) &(temp_var_for_const_242 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:58:34");
      computeDMul((Addr)&temp_var_for_tac_122,
                  {(Addr) &(temp_var_for_const_245 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_244 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:58:53");
      computeDMul((Addr)&temp_var_for_tac_123,
                  {(Addr) &(temp_var_for_const_247 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_246 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:58:72");
      computeDMul((Addr)&temp_var_for_tac_124,
                  {(Addr) &(temp_var_for_const_249 = ((int32_t))),
                   (Addr) &(temp_var_for_const_248 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:59:15");
      computeDMul((Addr)&temp_var_for_tac_125,
                  {(Addr) &(temp_var_for_const_251 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_250 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:59:34");
      computeDMul((Addr)&temp_var_for_tac_126,
                  {(Addr) &(temp_var_for_const_253 = ((int32_t))),
                   (Addr) &(temp_var_for_const_252 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:59:53");
      computeDMul((Addr)&temp_var_for_tac_127,
                  {(Addr) &(temp_var_for_const_255 = ((int32_t))),
                   (Addr) &(temp_var_for_const_254 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:59:72");
      computeDMul((Addr)&temp_var_for_tac_128,
                  {(Addr) &(temp_var_for_const_257 = ((int32_t))),
                   (Addr) &(temp_var_for_const_256 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:60:15");
      computeDMul((Addr)&temp_var_for_tac_129,
                  {(Addr) &(temp_var_for_const_259 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_258 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:60:34");
      computeDMul((Addr)&temp_var_for_tac_130,
                  {(Addr) &(temp_var_for_const_261 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_260 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:60:53");
      computeDMul((Addr)&temp_var_for_tac_131,
                  {(Addr) &(temp_var_for_const_263 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_262 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:60:72");
      computeDMul((Addr)&temp_var_for_tac_132,
                  {(Addr) &(temp_var_for_const_265 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_264 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:61:15");
      computeDMul((Addr)&temp_var_for_tac_133,
                  {(Addr) &(temp_var_for_const_267 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_266 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:61:34");
      computeDMul((Addr)&temp_var_for_tac_134,
                  {(Addr) &(temp_var_for_const_269 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_268 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:61:53");
      computeDMul((Addr)&temp_var_for_tac_135,
                  {(Addr) &(temp_var_for_const_271 = ((int32_t))),
                   (Addr) &(temp_var_for_const_270 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:61:72");
      computeDMul((Addr)&temp_var_for_tac_136,
                  {(Addr) &(temp_var_for_const_273 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_272 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:62:15");
      computeDMul((Addr)&temp_var_for_tac_137,
                  {(Addr) &(temp_var_for_const_275 = ((int32_t))),
                   (Addr) &(temp_var_for_const_274 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:62:34");
      computeDMul((Addr)&temp_var_for_tac_138,
                  {(Addr) &(temp_var_for_const_277 = ((int32_t))),
                   (Addr) &(temp_var_for_const_276 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:62:53");
      computeDMul((Addr)&temp_var_for_tac_139,
                  {(Addr) &(temp_var_for_const_279 = ((int32_t))),
                   (Addr) &(temp_var_for_const_278 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:62:72");
      computeDMul((Addr)&temp_var_for_tac_140,
                  {(Addr) &(temp_var_for_const_281 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_280 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:63:15");
      computeDMul((Addr)&temp_var_for_tac_141,
                  {(Addr) &(temp_var_for_const_283 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_282 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:63:34");
      computeDMul((Addr)&temp_var_for_tac_142,
                  {(Addr) &(temp_var_for_const_285 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_284 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:63:53");
      computeDMul((Addr)&temp_var_for_tac_143,
                  {(Addr) &(temp_var_for_const_287 = ((int32_t))),
                   (Addr) &(temp_var_for_const_286 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:63:72");
      computeDMul((Addr)&temp_var_for_tac_144,
                  {(Addr) &(temp_var_for_const_289 = ((int32_t))),
                   (Addr) &(temp_var_for_const_288 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:64:15");
      computeDMul((Addr)&temp_var_for_tac_145,
                  {(Addr) &(temp_var_for_const_291 = ((int32_t))),
                   (Addr) &(temp_var_for_const_290 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:64:34");
      computeDMul((Addr)&temp_var_for_tac_146,
                  {(Addr) &(temp_var_for_const_293 = ((int32_t))),
                   (Addr) &(temp_var_for_const_292 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:64:53");
      computeDMul((Addr)&temp_var_for_tac_147,
                  {(Addr) &(temp_var_for_const_295 = ((int32_t))),
                   (Addr) &(temp_var_for_const_294 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:64:72");
      computeDMul((Addr)&temp_var_for_tac_148,
                  {(Addr) &(temp_var_for_const_297 = ((int32_t))),
                   (Addr) &(temp_var_for_const_296 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:65:15");
      computeDMul((Addr)&temp_var_for_tac_149,
                  {(Addr) &(temp_var_for_const_299 = ((int32_t))),
                   (Addr) &(temp_var_for_const_298 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:65:34");
      computeDMul((Addr)&temp_var_for_tac_150,
                  {(Addr) &(temp_var_for_const_301 = ((int32_t))),
                   (Addr) &(temp_var_for_const_300 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:65:53");
      computeDMul((Addr)&temp_var_for_tac_151,
                  {(Addr) &(temp_var_for_const_303 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_302 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:65:72");
      computeDMul((Addr)&temp_var_for_tac_152,
                  {(Addr) &(temp_var_for_const_305 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_304 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:66:15");
      computeDMul((Addr)&temp_var_for_tac_153,
                  {(Addr) &(temp_var_for_const_307 = ((int32_t))),
                   (Addr) &(temp_var_for_const_306 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:66:34");
      computeDMul((Addr)&temp_var_for_tac_154,
                  {(Addr) &(temp_var_for_const_309 = ((int32_t))),
                   (Addr) &(temp_var_for_const_308 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:66:53");
      computeDMul((Addr)&temp_var_for_tac_155,
                  {(Addr) &(temp_var_for_const_311 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_310 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:66:72");
      computeDMul((Addr)&temp_var_for_tac_156,
                  {(Addr) &(temp_var_for_const_313 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_312 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:67:15");
      computeDMul((Addr)&temp_var_for_tac_157,
                  {(Addr) &(temp_var_for_const_315 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_314 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:67:34");
      computeDMul((Addr)&temp_var_for_tac_158,
                  {(Addr) &(temp_var_for_const_317 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_316 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:67:53");
      computeDMul((Addr)&temp_var_for_tac_159,
                  {(Addr) &(temp_var_for_const_319 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_318 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:67:72");
      computeDMul((Addr)&temp_var_for_tac_160,
                  {(Addr) &(temp_var_for_const_321 = ((int32_t))),
                   (Addr) &(temp_var_for_const_320 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:68:15");
      computeDMul((Addr)&temp_var_for_tac_161,
                  {(Addr) &(temp_var_for_const_323 = ((int32_t))),
                   (Addr) &(temp_var_for_const_322 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:68:34");
      computeDMul((Addr)&temp_var_for_tac_162,
                  {(Addr) &(temp_var_for_const_325 = ((int32_t))),
                   (Addr) &(temp_var_for_const_324 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:68:53");
      computeDMul((Addr)&temp_var_for_tac_163,
                  {(Addr) &(temp_var_for_const_327 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_326 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:68:72");
      computeDMul((Addr)&temp_var_for_tac_164,
                  {(Addr) &(temp_var_for_const_329 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_328 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:69:15");
      computeDMul((Addr)&temp_var_for_tac_165,
                  {(Addr) &(temp_var_for_const_331 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_330 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:69:34");
      computeDMul((Addr)&temp_var_for_tac_166,
                  {(Addr) &(temp_var_for_const_333 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_332 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:69:53");
      computeDMul((Addr)&temp_var_for_tac_167,
                  {(Addr) &(temp_var_for_const_335 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_334 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:69:72");
      computeDMul((Addr)&temp_var_for_tac_168,
                  {(Addr) &(temp_var_for_const_337 = ((int32_t))),
                   (Addr) &(temp_var_for_const_336 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:70:15");
      computeDMul((Addr)&temp_var_for_tac_169,
                  {(Addr) &(temp_var_for_const_339 = ((int32_t))),
                   (Addr) &(temp_var_for_const_338 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:70:34");
      computeDMul((Addr)&temp_var_for_tac_170,
                  {(Addr) &(temp_var_for_const_341 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_340 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:70:53");
      computeDMul((Addr)&temp_var_for_tac_171,
                  {(Addr) &(temp_var_for_const_343 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_342 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:70:72");
      computeDMul((Addr)&temp_var_for_tac_172,
                  {(Addr) &(temp_var_for_const_345 = ((int32_t))),
                   (Addr) &(temp_var_for_const_344 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:71:15");
      computeDMul((Addr)&temp_var_for_tac_173,
                  {(Addr) &(temp_var_for_const_347 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_346 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:71:34");
      computeDMul((Addr)&temp_var_for_tac_174,
                  {(Addr) &(temp_var_for_const_349 = ((int32_t))),
                   (Addr) &(temp_var_for_const_348 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:71:53");
      computeDMul((Addr)&temp_var_for_tac_175,
                  {(Addr) &(temp_var_for_const_351 = ((int32_t))),
                   (Addr) &(temp_var_for_const_350 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:71:72");
      computeDMul((Addr)&temp_var_for_tac_176,
                  {(Addr) &(temp_var_for_const_353 = ((int32_t))),
                   (Addr) &(temp_var_for_const_352 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:72:15");
      computeDMul((Addr)&temp_var_for_tac_177,
                  {(Addr) &(temp_var_for_const_355 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_354 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:72:34");
      computeDMul((Addr)&temp_var_for_tac_178,
                  {(Addr) &(temp_var_for_const_357 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_356 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:72:53");
      computeDMul((Addr)&temp_var_for_tac_179,
                  {(Addr) &(temp_var_for_const_359 = ((int32_t))),
                   (Addr) &(temp_var_for_const_358 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:72:72");
      computeDMul((Addr)&temp_var_for_tac_180,
                  {(Addr) &(temp_var_for_const_361 = ((int32_t))),
                   (Addr) &(temp_var_for_const_360 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:73:15");
      computeDMul((Addr)&temp_var_for_tac_181,
                  {(Addr) &(temp_var_for_const_363 = ((int32_t))),
                   (Addr) &(temp_var_for_const_362 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:73:34");
      computeDMul((Addr)&temp_var_for_tac_182,
                  {(Addr) &(temp_var_for_const_365 = ((int32_t))),
                   (Addr) &(temp_var_for_const_364 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:73:53");
      computeDMul((Addr)&temp_var_for_tac_183,
                  {(Addr) &(temp_var_for_const_367 = ((int32_t))),
                   (Addr) &(temp_var_for_const_366 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:73:72");
      computeDMul((Addr)&temp_var_for_tac_184,
                  {(Addr) &(temp_var_for_const_369 = ((int32_t))),
                   (Addr) &(temp_var_for_const_368 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:74:15");
      computeDMul((Addr)&temp_var_for_tac_185,
                  {(Addr) &(temp_var_for_const_371 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_370 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:74:34");
      computeDMul((Addr)&temp_var_for_tac_186,
                  {(Addr) &(temp_var_for_const_373 = ((int32_t))),
                   (Addr) &(temp_var_for_const_372 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:74:53");
      computeDMul((Addr)&temp_var_for_tac_187,
                  {(Addr) &(temp_var_for_const_375 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_374 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:74:72");
      computeDMul((Addr)&temp_var_for_tac_188,
                  {(Addr) &(temp_var_for_const_377 = ((int32_t))),
                   (Addr) &(temp_var_for_const_376 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:75:15");
      computeDMul((Addr)&temp_var_for_tac_189,
                  {(Addr) &(temp_var_for_const_379 = ((int32_t))),
                   (Addr) &(temp_var_for_const_378 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:75:34");
      computeDMul((Addr)&temp_var_for_tac_190,
                  {(Addr) &(temp_var_for_const_381 = ((int32_t))),
                   (Addr) &(temp_var_for_const_380 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:75:53");
      computeDMul((Addr)&temp_var_for_tac_191,
                  {(Addr) &(temp_var_for_const_383 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_382 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:75:72");
      computeDMul((Addr)&temp_var_for_tac_192,
                  {(Addr) &(temp_var_for_const_385 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_384 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:76:15");
      computeDMul((Addr)&temp_var_for_tac_193,
                  {(Addr) &(temp_var_for_const_387 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_386 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:76:34");
      computeDMul((Addr)&temp_var_for_tac_194,
                  {(Addr) &(temp_var_for_const_389 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_388 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:76:53");
      computeDMul((Addr)&temp_var_for_tac_195,
                  {(Addr) &(temp_var_for_const_391 = ((int32_t))),
                   (Addr) &(temp_var_for_const_390 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:76:72");
      computeDMul((Addr)&temp_var_for_tac_196,
                  {(Addr) &(temp_var_for_const_393 = ((int32_t))),
                   (Addr) &(temp_var_for_const_392 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:77:15");
      computeDMul((Addr)&temp_var_for_tac_197,
                  {(Addr) &(temp_var_for_const_395 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_394 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:77:34");
      computeDMul((Addr)&temp_var_for_tac_198,
                  {(Addr) &(temp_var_for_const_397 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_396 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:77:53");
      computeDMul((Addr)&temp_var_for_tac_199,
                  {(Addr) &(temp_var_for_const_399 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_398 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:77:72");
      computeDMul((Addr)&temp_var_for_tac_200,
                  {(Addr) &(temp_var_for_const_401 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_400 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:78:15");
      computeDMul((Addr)&temp_var_for_tac_201,
                  {(Addr) &(temp_var_for_const_403 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_402 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:78:34");
      computeDMul((Addr)&temp_var_for_tac_202,
                  {(Addr) &(temp_var_for_const_405 = ((int32_t))),
                   (Addr) &(temp_var_for_const_404 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:78:53");
      computeDMul((Addr)&temp_var_for_tac_203,
                  {(Addr) &(temp_var_for_const_407 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_406 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:78:72");
      computeDMul((Addr)&temp_var_for_tac_204,
                  {(Addr) &(temp_var_for_const_409 = ((int32_t))),
                   (Addr) &(temp_var_for_const_408 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:79:15");
      computeDMul((Addr)&temp_var_for_tac_205,
                  {(Addr) &(temp_var_for_const_411 = ((int32_t))),
                   (Addr) &(temp_var_for_const_410 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:79:34");
      computeDMul((Addr)&temp_var_for_tac_206,
                  {(Addr) &(temp_var_for_const_413 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_412 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:79:53");
      computeDMul((Addr)&temp_var_for_tac_207,
                  {(Addr) &(temp_var_for_const_415 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_414 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:79:72");
      computeDMul((Addr)&temp_var_for_tac_208,
                  {(Addr) &(temp_var_for_const_417 = ((int32_t))),
                   (Addr) &(temp_var_for_const_416 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:80:15");
      computeDMul((Addr)&temp_var_for_tac_209,
                  {(Addr) &(temp_var_for_const_419 = ((int32_t))),
                   (Addr) &(temp_var_for_const_418 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:80:34");
      computeDMul((Addr)&temp_var_for_tac_210,
                  {(Addr) &(temp_var_for_const_421 = ((int32_t))),
                   (Addr) &(temp_var_for_const_420 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:80:53");
      computeDMul((Addr)&temp_var_for_tac_211,
                  {(Addr) &(temp_var_for_const_423 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_422 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:80:72");
      computeDMul((Addr)&temp_var_for_tac_212,
                  {(Addr) &(temp_var_for_const_425 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_424 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:81:15");
      computeDMul((Addr)&temp_var_for_tac_213,
                  {(Addr) &(temp_var_for_const_427 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_426 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:81:34");
      computeDMul((Addr)&temp_var_for_tac_214,
                  {(Addr) &(temp_var_for_const_429 = ((int32_t))),
                   (Addr) &(temp_var_for_const_428 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:81:53");
      computeDMul((Addr)&temp_var_for_tac_215,
                  {(Addr) &(temp_var_for_const_431 = ((int32_t))),
                   (Addr) &(temp_var_for_const_430 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:81:72");
      computeDMul((Addr)&temp_var_for_tac_216,
                  {(Addr) &(temp_var_for_const_433 = ((int32_t))),
                   (Addr) &(temp_var_for_const_432 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:82:15");
      computeDMul((Addr)&temp_var_for_tac_217,
                  {(Addr) &(temp_var_for_const_435 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_434 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:82:34");
      computeDMul((Addr)&temp_var_for_tac_218,
                  {(Addr) &(temp_var_for_const_437 = ((int32_t))),
                   (Addr) &(temp_var_for_const_436 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:82:53");
      computeDMul((Addr)&temp_var_for_tac_219,
                  {(Addr) &(temp_var_for_const_439 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_438 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:82:72");
      computeDMul((Addr)&temp_var_for_tac_220,
                  {(Addr) &(temp_var_for_const_441 = ((int32_t))),
                   (Addr) &(temp_var_for_const_440 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:83:15");
      computeDMul((Addr)&temp_var_for_tac_221,
                  {(Addr) &(temp_var_for_const_443 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_442 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:83:34");
      computeDMul((Addr)&temp_var_for_tac_222,
                  {(Addr) &(temp_var_for_const_445 = ((int32_t))),
                   (Addr) &(temp_var_for_const_444 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:83:53");
      computeDMul((Addr)&temp_var_for_tac_223,
                  {(Addr) &(temp_var_for_const_447 = ((int32_t))),
                   (Addr) &(temp_var_for_const_446 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:83:72");
      computeDMul((Addr)&temp_var_for_tac_224,
                  {(Addr) &(temp_var_for_const_449 = ((int32_t))),
                   (Addr) &(temp_var_for_const_448 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:84:15");
      computeDMul((Addr)&temp_var_for_tac_225,
                  {(Addr) &(temp_var_for_const_451 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_450 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:84:34");
      computeDMul((Addr)&temp_var_for_tac_226,
                  {(Addr) &(temp_var_for_const_453 = ((int32_t))),
                   (Addr) &(temp_var_for_const_452 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:84:53");
      computeDMul((Addr)&temp_var_for_tac_227,
                  {(Addr) &(temp_var_for_const_455 = ((int32_t))),
                   (Addr) &(temp_var_for_const_454 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:84:72");
      computeDMul((Addr)&temp_var_for_tac_228,
                  {(Addr) &(temp_var_for_const_457 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_456 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:85:15");
      computeDMul((Addr)&temp_var_for_tac_229,
                  {(Addr) &(temp_var_for_const_459 = ((int32_t))),
                   (Addr) &(temp_var_for_const_458 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:85:34");
      computeDMul((Addr)&temp_var_for_tac_230,
                  {(Addr) &(temp_var_for_const_461 = ((int32_t))),
                   (Addr) &(temp_var_for_const_460 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:85:53");
      computeDMul((Addr)&temp_var_for_tac_231,
                  {(Addr) &(temp_var_for_const_463 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_462 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:85:72");
      computeDMul((Addr)&temp_var_for_tac_232,
                  {(Addr) &(temp_var_for_const_465 = ((int32_t))),
                   (Addr) &(temp_var_for_const_464 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:86:15");
      computeDMul((Addr)&temp_var_for_tac_233,
                  {(Addr) &(temp_var_for_const_467 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_466 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:86:34");
      computeDMul((Addr)&temp_var_for_tac_234,
                  {(Addr) &(temp_var_for_const_469 = ((int32_t))),
                   (Addr) &(temp_var_for_const_468 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:86:53");
      computeDMul((Addr)&temp_var_for_tac_235,
                  {(Addr) &(temp_var_for_const_471 = ((int32_t))),
                   (Addr) &(temp_var_for_const_470 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:86:72");
      computeDMul((Addr)&temp_var_for_tac_236,
                  {(Addr) &(temp_var_for_const_473 = ((int32_t))),
                   (Addr) &(temp_var_for_const_472 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:87:15");
      computeDMul((Addr)&temp_var_for_tac_237,
                  {(Addr) &(temp_var_for_const_475 = ((int32_t))),
                   (Addr) &(temp_var_for_const_474 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:87:34");
      computeDMul((Addr)&temp_var_for_tac_238,
                  {(Addr) &(temp_var_for_const_477 = ((int32_t))),
                   (Addr) &(temp_var_for_const_476 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:87:53");
      computeDMul((Addr)&temp_var_for_tac_239,
                  {(Addr) &(temp_var_for_const_479 = ((int32_t))),
                   (Addr) &(temp_var_for_const_478 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:87:72");
      computeDMul((Addr)&temp_var_for_tac_240,
                  {(Addr) &(temp_var_for_const_481 = ((int32_t))),
                   (Addr) &(temp_var_for_const_480 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:88:15");
      computeDMul((Addr)&temp_var_for_tac_241,
                  {(Addr) &(temp_var_for_const_483 = ((int32_t))),
                   (Addr) &(temp_var_for_const_482 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:88:34");
      computeDMul((Addr)&temp_var_for_tac_242,
                  {(Addr) &(temp_var_for_const_485 = ((int32_t))),
                   (Addr) &(temp_var_for_const_484 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:88:53");
      computeDMul((Addr)&temp_var_for_tac_243,
                  {(Addr) &(temp_var_for_const_487 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_486 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:88:72");
      computeDMul((Addr)&temp_var_for_tac_244,
                  {(Addr) &(temp_var_for_const_489 = ((int32_t))),
                   (Addr) &(temp_var_for_const_488 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:89:15");
      computeDMul((Addr)&temp_var_for_tac_245,
                  {(Addr) &(temp_var_for_const_491 = ((int32_t))),
                   (Addr) &(temp_var_for_const_490 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:89:34");
      computeDMul((Addr)&temp_var_for_tac_246,
                  {(Addr) &(temp_var_for_const_493 = ((int32_t))),
                   (Addr) &(temp_var_for_const_492 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:89:53");
      computeDMul((Addr)&temp_var_for_tac_247,
                  {(Addr) &(temp_var_for_const_495 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_494 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:89:72");
      computeDMul((Addr)&temp_var_for_tac_248,
                  {(Addr) &(temp_var_for_const_497 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_496 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:90:15");
      computeDMul((Addr)&temp_var_for_tac_249,
                  {(Addr) &(temp_var_for_const_499 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_498 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:90:34");
      computeDMul((Addr)&temp_var_for_tac_250,
                  {(Addr) &(temp_var_for_const_501 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_500 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:90:53");
      computeDMul((Addr)&temp_var_for_tac_251,
                  {(Addr) &(temp_var_for_const_503 = ((int32_t))),
                   (Addr) &(temp_var_for_const_502 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:90:72");
      computeDMul((Addr)&temp_var_for_tac_252,
                  {(Addr) &(temp_var_for_const_505 = ((int32_t))),
                   (Addr) &(temp_var_for_const_504 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:91:15");
      computeDMul((Addr)&temp_var_for_tac_253,
                  {(Addr) &(temp_var_for_const_507 = ((int32_t))),
                   (Addr) &(temp_var_for_const_506 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:91:34");
      computeDMul((Addr)&temp_var_for_tac_254,
                  {(Addr) &(temp_var_for_const_509 = ((int32_t))),
                   (Addr) &(temp_var_for_const_508 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:91:53");
      computeDMul((Addr)&temp_var_for_tac_255,
                  {(Addr) &(temp_var_for_const_511 = ((int32_t)(-()))),
                   (Addr) &(temp_var_for_const_510 = W30)},
                  "/home/shijia/Public/testprogram/t_exp2f.h:91:72");
      computeFAdd((Addr)&temp_var_for_tac_256,
                  {(Addr)&x, (Addr) &(temp_var_for_const_512 = THREEp14)},
                  "/home/shijia/Public/testprogram/e_exp2f.c_e.c:66:14");
      AssignF({(Addr)&rx}, (Addr)&temp_var_for_tac_256,
              "/home/shijia/Public/testprogram/e_exp2f.c_e.c:66:10");
      ;
      rx -= THREEp14;
      ;
      x -= rx;
      ; /* Compute x=x1. */
        /* Compute tval = (ex*256 + t)+128.
           Now, t = (tval mod 256)-128 and ex=tval/256  [that's mod, NOT %;
           and /-round-to-nearest not the usual c integer /].  */
      tval = (int32_t)(float temp_var_for_tac_259, temp_var_for_tac_260;
                       float temp_var_for_const_513, temp_var_for_const_514;
                       temp_var_for_tac_259 = rx * 256.0f;

                       temp_var_for_tac_260 = temp_var_for_tac_259 + 128.0f;

                       );

      /* 2. Adjust for accurate table entry.
         Find e so that
         x = ex + t/256 + e + x2
         where -7e-4 < e < 7e-4, and
         (float)(2^(t/256+e))
         is accurate to one part in 2^-64.  */

      /* 'tval & 255' is the same as 'tval%256' except that it's always
         positive.
         Compute x = x2.  */
      x -= __exp2f_deltatable[tval & 255];
      ;

      /* 3. Compute ex2 = 2^(t/255+e+ex).  */
      float temp_var_for_const_515;
      ex2_u = __exp2f_atable[tval & 255];
      computeFMul((Addr)&temp_var_for_tac_259,
                  {(Addr)&rx, (Addr) &(temp_var_for_const_513 = 256.0f)},
                  "/home/shijia/Public/testprogram/e_exp2f.c_e.c:72:27");
      computeFAdd((Addr)&temp_var_for_tac_260,
                  {(Addr)&temp_var_for_tac_259,
                   (Addr) &(temp_var_for_const_514 = 128.0f)},
                  "/home/shijia/Public/testprogram/e_exp2f.c_e.c:72:36");
      AssignF({(Addr)&ex2_u},
              (Addr) &(temp_var_for_const_515 = __exp2f_atable[tval & 255]),
              "/home/shijia/Public/testprogram/e_exp2f.c_e.c:87:13");
      ;
      tval >>= 8;
      /* x2 is an integer multiple of 2^-30; avoid intermediate
         underflow from the calculation of x22 * x.  */
      unsafe = abs(tval) >= -FLT_MIN_EXP - 32;
      GET_FLOAT_WORD(exp, ex2_u);
      exp =
          ((exp & UC(0x7F800000)) + ((tval >> unsafe) << IEEE754_FLOAT_SHIFT)) |
          (exp & ~UC(0x7F800000));
      SET_FLOAT_WORD(ex2_u, exp);
      exp = UC(0x3f800000) + ((tval - (tval >> unsafe)) << IEEE754_FLOAT_SHIFT);
      SET_FLOAT_WORD(scale_u, exp);

      /* 4. Approximate 2^x2 - 1, using a second-degree polynomial,
         with maximum error in [-2^-9 - 2^-14, 2^-9 + 2^-14]
         less than 1.3e-10.  */

      float temp_var_for_tac_262, temp_var_for_tac_263, temp_var_for_tac_264;
      float temp_var_for_const_516, temp_var_for_const_517;
      temp_var_for_tac_262 = .24022656679f * x;

      temp_var_for_tac_263 = temp_var_for_tac_262 + .69314736128f;

      temp_var_for_tac_264 = temp_var_for_tac_263 * ex2_u;

      x22 = temp_var_for_tac_264;
      computeFMul((Addr)&temp_var_for_tac_262,
                  {(Addr) &(temp_var_for_const_516 = .24022656679f), (Addr)&x},
                  "/home/shijia/Public/testprogram/e_exp2f.c_e.c:104:28");
      computeFAdd((Addr)&temp_var_for_tac_263,
                  {(Addr)&temp_var_for_tac_262,
                   (Addr) &(temp_var_for_const_517 = .69314736128f)},
                  "/home/shijia/Public/testprogram/e_exp2f.c_e.c:104:32");
      computeFMul((Addr)&temp_var_for_tac_264,
                  {(Addr)&temp_var_for_tac_263, (Addr)&ex2_u},
                  "/home/shijia/Public/testprogram/e_exp2f.c_e.c:104:49");
      AssignF({(Addr)&x22}, (Addr)&temp_var_for_tac_264,
              "/home/shijia/Public/testprogram/e_exp2f.c_e.c:104:11");
      ;
      RESTORE_ROUND();
    }
  }
}

/* 5. Return (2^x2-1) * 2^(t/512+e+ex) + 2^(t/512+e+ex).  */
result = x22 * x + ex2_u;

if (!unsafe) {
  return result;
}

return result * scale_u;
}
/* Exceptional cases:  */
if (isless(x, himark)) {
  if (isinf(x))
      /* e^-inf == 0, with no error.  */
      {
    return 0;
  }

  /* Underflow */
  return TWOM100 * TWOM100;
}
/* Return x, if x is a NaN or Inf; or overflow, otherwise.  */
return TWO127 * x;
}

#undef abs

#endif

float __exp2f(float x) {
  float z = __ieee754_exp2f(x);

  if (!isfinite(z) && isfinite(x) && _LIB_VERSION != _IEEE_)
  /* exp2 overflow: 144, exp2 underflow: 145 */
  {
    float temp_var_for_ext_0;
    float temp_var_for_const_518;
    float temp_var_for_callexp_0;

    temp_var_for_callexp_0 =
        __kernel_standard_f(x, x, z, signbit(x) ? KMATHERRF_EXP2_UNDERFLOW
                                                : KMATHERRF_EXP2_OVERFLOW);
    temp_var_for_ext_0 = temp_var_for_callexp_0;
    AssignF({(Addr)&temp_var_for_ext_0},
            (Addr) &(temp_var_for_const_518 = temp_var_for_callexp_0),
            "/home/shijia/Public/testprogram/e_exp2f.c_e.c:145:24");
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

__typeof(__exp2f) exp2f __attribute__((weak, alias("__exp2f")));
__typeof(__exp2f) __pow2f __attribute__((alias("__exp2f")));
__typeof(__pow2f) pow2f __attribute__((weak, alias("__pow2f")));
