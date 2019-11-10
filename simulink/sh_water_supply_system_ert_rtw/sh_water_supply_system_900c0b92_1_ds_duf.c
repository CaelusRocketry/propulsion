/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'sh_water_supply_system/Solver Configuration'.
 */

#include "ne_ds.h"
#include "sh_water_supply_system_900c0b92_1_ds_duf.h"
#include "sh_water_supply_system_900c0b92_1_ds_sys_struct.h"
#include "sh_water_supply_system_900c0b92_1_ds_externals.h"
#include "sh_water_supply_system_900c0b92_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T sh_water_supply_system_900c0b92_1_ds_duf(const NeDynamicSystem *sys,
  const NeDynamicSystemInput *t156, NeDsMethodOutput *t157)
{
  PmRealVector out;
  real_T nonscalar0[6];
  real_T nonscalar1[6];
  real_T nonscalar10[6];
  real_T nonscalar11[6];
  real_T nonscalar12[6];
  real_T nonscalar13[6];
  real_T nonscalar14[6];
  real_T nonscalar2[6];
  real_T nonscalar3[6];
  real_T nonscalar4[6];
  real_T nonscalar5[6];
  real_T nonscalar6[6];
  real_T nonscalar7[6];
  real_T nonscalar8[6];
  real_T nonscalar9[6];
  real_T intermediate_der72;
  boolean_T t15[2];
  boolean_T t19[2];
  boolean_T t20[2];
  boolean_T t21[2];
  boolean_T t22[2];
  boolean_T t23[2];
  boolean_T t24[2];
  boolean_T t25[2];
  boolean_T t26[2];
  boolean_T t27[2];
  boolean_T t28[2];
  boolean_T t29[2];
  boolean_T t30[2];
  boolean_T t31[2];
  boolean_T t32[2];
  boolean_T t33[2];
  boolean_T t34[2];
  boolean_T t35[2];
  boolean_T t36[2];
  boolean_T t37[2];
  boolean_T t38[2];
  boolean_T t39[2];
  boolean_T t40[2];
  boolean_T t41[2];
  real_T t68[1];
  real_T t80;
  real_T t93;
  real_T t95;
  real_T t104;
  real_T t105;
  real_T t107;
  real_T t108;
  real_T t111;
  real_T t113;
  real_T t114;
  real_T t116;
  real_T t117;
  real_T t121;
  ETTS0 efOut;
  size_t _in1ivar;
  ETTS0 b_efOut;
  ETTS0 c_efOut;
  ETTS0 d_efOut;
  ETTS0 e_efOut;
  ETTS0 f_efOut;
  real_T g_efOut[1];
  real_T h_efOut[1];
  real_T i_efOut[1];
  real_T j_efOut[1];
  real_T k_efOut[1];
  real_T l_efOut[1];
  real_T m_efOut[1];
  real_T n_efOut[1];
  real_T o_efOut[1];
  real_T p_efOut[1];
  real_T q_efOut[1];
  real_T r_efOut[1];
  real_T s_efOut[1];
  real_T t_efOut[1];
  real_T u_efOut[1];
  real_T v_efOut[1];
  real_T w_efOut[1];
  real_T x_efOut[1];
  real_T y_efOut[1];
  real_T ab_efOut[1];
  real_T bb_efOut[1];
  real_T cb_efOut[1];
  real_T db_efOut[1];
  real_T eb_efOut[1];
  real_T U_idx_0;
  real_T U_idx_1;
  real_T U_idx_2;
  real_T U_idx_3;
  real_T U_idx_4;
  real_T U_idx_5;
  real_T X_idx_8;
  real_T X_idx_9;
  real_T X_idx_12;
  real_T X_idx_13;
  real_T X_idx_17;
  real_T X_idx_18;
  U_idx_0 = t156->mU.mX[0];
  U_idx_1 = t156->mU.mX[1];
  U_idx_2 = t156->mU.mX[2];
  U_idx_3 = t156->mU.mX[3];
  U_idx_4 = t156->mU.mX[4];
  U_idx_5 = t156->mU.mX[5];
  X_idx_8 = t156->mX.mX[8];
  X_idx_9 = t156->mX.mX[9];
  X_idx_12 = t156->mX.mX[12];
  X_idx_13 = t156->mX.mX[13];
  X_idx_17 = t156->mX.mX[17];
  X_idx_18 = t156->mX.mX[18];
  out = t157->mDUF;
  nonscalar0[0] = 0.0;
  nonscalar0[1] = 3200.0;
  nonscalar0[2] = 6299.9999999999991;
  nonscalar0[3] = 9499.9999999999982;
  nonscalar0[4] = 12599.999999999998;
  nonscalar0[5] = 15800.0;
  nonscalar1[0] = 4.4851;
  nonscalar1[1] = 4.3655;
  nonscalar1[2] = 4.1413;
  nonscalar1[3] = 3.7376;
  nonscalar1[4] = 2.9901;
  nonscalar1[5] = 1.794;
  nonscalar10[0] = 0.0;
  nonscalar10[1] = 2799.9999999999995;
  nonscalar10[2] = 5699.9999999999991;
  nonscalar10[3] = 8500.0;
  nonscalar10[4] = 10099.999999999998;
  nonscalar10[5] = 12599.999999999998;
  nonscalar11[0] = 3.8348;
  nonscalar11[1] = 3.7682;
  nonscalar11[2] = 3.5653;
  nonscalar11[3] = 3.1885;
  nonscalar11[4] = 2.6088;
  nonscalar11[5] = 1.5433;
  nonscalar12[0] = -6.958128078802674E-7;
  nonscalar12[1] = -4.3035255752069856E-5;
  nonscalar12[2] = -8.0857305834350414E-5;
  nonscalar12[3] = -0.00024907861858697051;
  nonscalar12[4] = -0.00041220407142462245;
  nonscalar12[5] = -0.00045814374999999673;
  nonscalar13[0] = 0.0;
  nonscalar13[1] = 1.4845;
  nonscalar13[2] = 2.9032;
  nonscalar13[3] = 3.6136;
  nonscalar13[4] = 4.1306;
  nonscalar13[5] = 34.828;
  nonscalar14[0] = 0.00055066440886696944;
  nonscalar14[1] = 0.00052410661845309374;
  nonscalar14[2] = 0.00040179687797431413;
  nonscalar14[3] = 0.00025505505112139229;
  nonscalar14[4] = 0.00039213506989378656;
  nonscalar14[5] = 0.018256877499999775;
  nonscalar2[0] = -1.9901209677382073E-5;
  nonscalar2[1] = -5.1131659125093795E-5;
  nonscalar2[2] = -8.4871619780150536E-5;
  nonscalar2[3] = -0.00015934592907569176;
  nonscalar2[4] = -0.00030271972199654519;
  nonscalar2[5] = -0.000440107358870961;
  nonscalar3[0] = 0.0;
  nonscalar3[1] = 2.1166;
  nonscalar3[2] = 3.7272;
  nonscalar3[3] = 4.7343;
  nonscalar3[4] = 5.2327;
  nonscalar3[5] = 4.3609;
  nonscalar4[0] = 0.00073238205645160474;
  nonscalar4[1] = 0.00060337164587335871;
  nonscalar4[2] = 0.00042130704909308414;
  nonscalar4[3] = 0.00026529811513432327;
  nonscalar4[4] = 4.7191851517668425E-5;
  nonscalar4[5] = -0.00048904334677415679;
  nonscalar5[0] = 0.0;
  nonscalar5[1] = 2499.9999999999995;
  nonscalar5[2] = 4999.9999999999991;
  nonscalar5[3] = 7599.9999999999991;
  nonscalar5[4] = 10099.999999999998;
  nonscalar5[5] = 12599.999999999998;
  nonscalar6[0] = 5.797;
  nonscalar6[1] = 5.757;
  nonscalar6[2] = 5.392;
  nonscalar6[3] = 4.812;
  nonscalar6[4] = 3.855;
  nonscalar6[5] = 2.3189;
  nonscalar7[0] = 4.8999999999947828E-5;
  nonscalar7[1] = -9.7612184249536553E-5;
  nonscalar7[2] = -0.00018058474936278265;
  nonscalar7[3] = -0.00026295476064706251;
  nonscalar7[4] = -0.00047733690376042335;
  nonscalar7[5] = -0.00073025999999998888;
  nonscalar8[0] = 0.0;
  nonscalar8[1] = 2.1806;
  nonscalar8[2] = 3.8511;
  nonscalar8[3] = 4.8759;
  nonscalar8[4] = 6.104;
  nonscalar8[5] = 5.0659;
  nonscalar9[0] = 0.00097425999999998754;
  nonscalar9[1] = 0.00078515878824541154;
  nonscalar9[2] = 0.00048250913085241169;
  nonscalar9[3] = 0.000416691328247387;
  nonscalar9[4] = 0.00040354607329534496;
  nonscalar9[5] = -0.00086847999999993682;
  if (U_idx_1 >= 0.0) {
    t95 = pmf_sqrt(U_idx_1 * U_idx_1 + 1.0E-18);
  } else {
    t95 = -pmf_sqrt(U_idx_1 * U_idx_1 + 1.0E-18);
  }

  t93 = 185.35396656179779 / (t95 == 0.0 ? 1.0E-16 : t95);
  if (U_idx_2 >= 0.0) {
    t104 = pmf_sqrt(U_idx_2 * U_idx_2 + 1.0E-18);
  } else {
    t104 = -pmf_sqrt(U_idx_2 * U_idx_2 + 1.0E-18);
  }

  t105 = 185.35396656179779 / (t104 == 0.0 ? 1.0E-16 : t104);
  if (U_idx_3 >= 0.0) {
    t107 = pmf_sqrt(U_idx_3 * U_idx_3 + 1.0E-18);
  } else {
    t107 = -pmf_sqrt(U_idx_3 * U_idx_3 + 1.0E-18);
  }

  t108 = 185.35396656179779 / (t107 == 0.0 ? 1.0E-16 : t107);
  if (U_idx_4 >= 0.0) {
    intermediate_der72 = pmf_sqrt(U_idx_4 * U_idx_4 + 1.0E-18);
  } else {
    intermediate_der72 = -pmf_sqrt(U_idx_4 * U_idx_4 + 1.0E-18);
  }

  t111 = 185.35396656179779 / (intermediate_der72 == 0.0 ? 1.0E-16 :
    intermediate_der72);
  if (U_idx_5 >= 0.0) {
    t113 = pmf_sqrt(U_idx_5 * U_idx_5 + 1.0E-18);
  } else {
    t113 = -pmf_sqrt(U_idx_5 * U_idx_5 + 1.0E-18);
  }

  t114 = 185.35396656179779 / (t113 == 0.0 ? 1.0E-16 : t113);
  if (U_idx_0 >= 0.0) {
    t116 = pmf_sqrt(U_idx_0 * U_idx_0 + 1.0E-18);
  } else {
    t116 = -pmf_sqrt(U_idx_0 * U_idx_0 + 1.0E-18);
  }

  t117 = 185.35396656179779 / (t116 == 0.0 ? 1.0E-16 : t116);
  if (U_idx_1 >= 0.0) {
    t80 = pmf_sqrt(U_idx_1 * U_idx_1 + 1.0E-18) * 2.0;
    t80 = 1.0 / (t80 == 0.0 ? 1.0E-16 : t80) * U_idx_1 * 2.0;
  } else {
    t80 = pmf_sqrt(U_idx_1 * U_idx_1 + 1.0E-18) * 2.0;
    t80 = -(1.0 / (t80 == 0.0 ? 1.0E-16 : t80) * U_idx_1 * 2.0);
  }

  t121 = t95 * t95;
  t95 = -185.35396656179779 / (t121 == 0.0 ? 1.0E-16 : t121) * t80;
  if (U_idx_2 >= 0.0) {
    t121 = pmf_sqrt(U_idx_2 * U_idx_2 + 1.0E-18) * 2.0;
    t80 = 1.0 / (t121 == 0.0 ? 1.0E-16 : t121) * U_idx_2 * 2.0;
  } else {
    t80 = pmf_sqrt(U_idx_2 * U_idx_2 + 1.0E-18) * 2.0;
    t80 = -(1.0 / (t80 == 0.0 ? 1.0E-16 : t80) * U_idx_2 * 2.0);
  }

  t121 = t104 * t104;
  t104 = -185.35396656179779 / (t121 == 0.0 ? 1.0E-16 : t121) * t80;
  if (U_idx_3 >= 0.0) {
    t121 = pmf_sqrt(U_idx_3 * U_idx_3 + 1.0E-18) * 2.0;
    t80 = 1.0 / (t121 == 0.0 ? 1.0E-16 : t121) * U_idx_3 * 2.0;
  } else {
    t80 = pmf_sqrt(U_idx_3 * U_idx_3 + 1.0E-18) * 2.0;
    t80 = -(1.0 / (t80 == 0.0 ? 1.0E-16 : t80) * U_idx_3 * 2.0);
  }

  t121 = t107 * t107;
  t107 = -185.35396656179779 / (t121 == 0.0 ? 1.0E-16 : t121) * t80;
  if (U_idx_4 >= 0.0) {
    t121 = pmf_sqrt(U_idx_4 * U_idx_4 + 1.0E-18) * 2.0;
    t80 = 1.0 / (t121 == 0.0 ? 1.0E-16 : t121) * U_idx_4 * 2.0;
  } else {
    t80 = pmf_sqrt(U_idx_4 * U_idx_4 + 1.0E-18) * 2.0;
    t80 = -(1.0 / (t80 == 0.0 ? 1.0E-16 : t80) * U_idx_4 * 2.0);
  }

  t121 = intermediate_der72 * intermediate_der72;
  intermediate_der72 = -185.35396656179779 / (t121 == 0.0 ? 1.0E-16 : t121) *
    t80;
  if (U_idx_5 >= 0.0) {
    t121 = pmf_sqrt(U_idx_5 * U_idx_5 + 1.0E-18) * 2.0;
    t80 = 1.0 / (t121 == 0.0 ? 1.0E-16 : t121) * U_idx_5 * 2.0;
  } else {
    t80 = pmf_sqrt(U_idx_5 * U_idx_5 + 1.0E-18) * 2.0;
    t80 = -(1.0 / (t80 == 0.0 ? 1.0E-16 : t80) * U_idx_5 * 2.0);
  }

  t121 = t113 * t113;
  t113 = -185.35396656179779 / (t121 == 0.0 ? 1.0E-16 : t121) * t80;
  if (U_idx_0 >= 0.0) {
    t121 = pmf_sqrt(U_idx_0 * U_idx_0 + 1.0E-18) * 2.0;
    t80 = 1.0 / (t121 == 0.0 ? 1.0E-16 : t121) * U_idx_0 * 2.0;
  } else {
    t80 = pmf_sqrt(U_idx_0 * U_idx_0 + 1.0E-18) * 2.0;
    t80 = -(1.0 / (t80 == 0.0 ? 1.0E-16 : t80) * U_idx_0 * 2.0);
  }

  t121 = t116 * t116;
  t116 = -185.35396656179779 / (t121 == 0.0 ? 1.0E-16 : t121) * t80;
  t68[0ULL] = t117 * X_idx_8;
  t15[0ULL] = (t117 * X_idx_8 < 0.0);
  t15[1ULL] = (t117 * X_idx_8 <= 15800.0);
  _in1ivar = 6ULL;
  tlu2_akima_linear_prelookup((void *)&efOut.mField0, (void *)&efOut.mField1,
    (void *)&efOut.mField2, (void *)&efOut.mField3, (void *)&efOut.mField4,
    (void *)&efOut.mField5, (void *)nonscalar0, (void *)t68, (void *)t15, (void *)
    &_in1ivar);
  t68[0ULL] = t93 * X_idx_9;
  t15[0ULL] = (t93 * X_idx_9 < 0.0);
  t15[1ULL] = (t93 * X_idx_9 <= 15800.0);
  _in1ivar = 6ULL;
  tlu2_akima_linear_prelookup((void *)&b_efOut.mField0, (void *)&b_efOut.mField1,
    (void *)&b_efOut.mField2, (void *)&b_efOut.mField3, (void *)&b_efOut.mField4,
    (void *)&b_efOut.mField5, (void *)nonscalar0, (void *)t68, (void *)t15,
    (void *)&_in1ivar);
  t68[0ULL] = t105 * X_idx_12;
  t15[0ULL] = (t105 * X_idx_12 < 0.0);
  t15[1ULL] = (t105 * X_idx_12 <= 12599.999999999998);
  _in1ivar = 6ULL;
  tlu2_akima_linear_prelookup((void *)&c_efOut.mField0, (void *)&c_efOut.mField1,
    (void *)&c_efOut.mField2, (void *)&c_efOut.mField3, (void *)&c_efOut.mField4,
    (void *)&c_efOut.mField5, (void *)nonscalar5, (void *)t68, (void *)t15,
    (void *)&_in1ivar);
  t68[0ULL] = t108 * X_idx_13;
  t15[0ULL] = (t108 * X_idx_13 < 0.0);
  t15[1ULL] = (t108 * X_idx_13 <= 12599.999999999998);
  _in1ivar = 6ULL;
  tlu2_akima_linear_prelookup((void *)&d_efOut.mField0, (void *)&d_efOut.mField1,
    (void *)&d_efOut.mField2, (void *)&d_efOut.mField3, (void *)&d_efOut.mField4,
    (void *)&d_efOut.mField5, (void *)nonscalar5, (void *)t68, (void *)t15,
    (void *)&_in1ivar);
  t68[0ULL] = t111 * X_idx_17;
  t15[0ULL] = (t111 * X_idx_17 < 0.0);
  t15[1ULL] = (t111 * X_idx_17 <= 12599.999999999998);
  _in1ivar = 6ULL;
  tlu2_akima_linear_prelookup((void *)&e_efOut.mField0, (void *)&e_efOut.mField1,
    (void *)&e_efOut.mField2, (void *)&e_efOut.mField3, (void *)&e_efOut.mField4,
    (void *)&e_efOut.mField5, (void *)nonscalar10, (void *)t68, (void *)t15,
    (void *)&_in1ivar);
  t68[0ULL] = t114 * X_idx_18;
  t15[0ULL] = (t114 * X_idx_18 < 0.0);
  t15[1ULL] = (t114 * X_idx_18 <= 12599.999999999998);
  _in1ivar = 6ULL;
  tlu2_akima_linear_prelookup((void *)&f_efOut.mField0, (void *)&f_efOut.mField1,
    (void *)&f_efOut.mField2, (void *)&f_efOut.mField3, (void *)&f_efOut.mField4,
    (void *)&f_efOut.mField5, (void *)nonscalar10, (void *)t68, (void *)t15,
    (void *)&_in1ivar);
  t15[0ULL] = (t117 * X_idx_8 < 0.0);
  t15[1ULL] = (t117 * X_idx_8 <= 15800.0);
  t19[0ULL] = (t117 * X_idx_8 < 0.0);
  t19[1ULL] = (t117 * X_idx_8 <= 15800.0);
  t20[0ULL] = (t117 * X_idx_8 < 0.0);
  t20[1ULL] = (t117 * X_idx_8 <= 15800.0);
  t21[0ULL] = (t117 * X_idx_8 < 0.0);
  t21[1ULL] = (t117 * X_idx_8 <= 15800.0);
  t22[0ULL] = (t93 * X_idx_9 < 0.0);
  t22[1ULL] = (t93 * X_idx_9 <= 15800.0);
  t23[0ULL] = (t93 * X_idx_9 < 0.0);
  t23[1ULL] = (t93 * X_idx_9 <= 15800.0);
  t24[0ULL] = (t93 * X_idx_9 < 0.0);
  t24[1ULL] = (t93 * X_idx_9 <= 15800.0);
  t25[0ULL] = (t93 * X_idx_9 < 0.0);
  t25[1ULL] = (t93 * X_idx_9 <= 15800.0);
  t26[0ULL] = (t105 * X_idx_12 < 0.0);
  t26[1ULL] = (t105 * X_idx_12 <= 12599.999999999998);
  t27[0ULL] = (t105 * X_idx_12 < 0.0);
  t27[1ULL] = (t105 * X_idx_12 <= 12599.999999999998);
  t28[0ULL] = (t105 * X_idx_12 < 0.0);
  t28[1ULL] = (t105 * X_idx_12 <= 12599.999999999998);
  t29[0ULL] = (t105 * X_idx_12 < 0.0);
  t29[1ULL] = (t105 * X_idx_12 <= 12599.999999999998);
  t30[0ULL] = (t108 * X_idx_13 < 0.0);
  t30[1ULL] = (t108 * X_idx_13 <= 12599.999999999998);
  t31[0ULL] = (t108 * X_idx_13 < 0.0);
  t31[1ULL] = (t108 * X_idx_13 <= 12599.999999999998);
  t32[0ULL] = (t108 * X_idx_13 < 0.0);
  t32[1ULL] = (t108 * X_idx_13 <= 12599.999999999998);
  t33[0ULL] = (t108 * X_idx_13 < 0.0);
  t33[1ULL] = (t108 * X_idx_13 <= 12599.999999999998);
  t34[0ULL] = (t111 * X_idx_17 < 0.0);
  t34[1ULL] = (t111 * X_idx_17 <= 12599.999999999998);
  t35[0ULL] = (t111 * X_idx_17 < 0.0);
  t35[1ULL] = (t111 * X_idx_17 <= 12599.999999999998);
  t36[0ULL] = (t111 * X_idx_17 < 0.0);
  t36[1ULL] = (t111 * X_idx_17 <= 12599.999999999998);
  t37[0ULL] = (t111 * X_idx_17 < 0.0);
  t37[1ULL] = (t111 * X_idx_17 <= 12599.999999999998);
  t38[0ULL] = (t114 * X_idx_18 < 0.0);
  t38[1ULL] = (t114 * X_idx_18 <= 12599.999999999998);
  t39[0ULL] = (t114 * X_idx_18 < 0.0);
  t39[1ULL] = (t114 * X_idx_18 <= 12599.999999999998);
  t40[0ULL] = (t114 * X_idx_18 < 0.0);
  t40[1ULL] = (t114 * X_idx_18 <= 12599.999999999998);
  t41[0ULL] = (t114 * X_idx_18 < 0.0);
  t41[1ULL] = (t114 * X_idx_18 <= 12599.999999999998);
  _in1ivar = 6ULL;
  tlu2_1d_akima_linear_value((void *)&g_efOut, (void *)efOut.mField0, (void *)
    efOut.mField1, (void *)efOut.mField2, (void *)efOut.mField3, (void *)
    efOut.mField4, (void *)efOut.mField5, (void *)nonscalar1, (void *)nonscalar2,
    (void *)t15, (void *)&_in1ivar);
  _in1ivar = 6ULL;
  tlu2_1d_akima_linear_derivatives((void *)&h_efOut, (void *)efOut.mField0,
    (void *)efOut.mField1, (void *)efOut.mField2, (void *)efOut.mField3, (void *)
    efOut.mField4, (void *)efOut.mField5, (void *)nonscalar1, (void *)nonscalar2,
    (void *)t19, (void *)&_in1ivar);
  _in1ivar = 6ULL;
  tlu2_1d_akima_linear_value((void *)&i_efOut, (void *)efOut.mField0, (void *)
    efOut.mField1, (void *)efOut.mField2, (void *)efOut.mField3, (void *)
    efOut.mField4, (void *)efOut.mField5, (void *)nonscalar3, (void *)nonscalar4,
    (void *)t20, (void *)&_in1ivar);
  _in1ivar = 6ULL;
  tlu2_1d_akima_linear_derivatives((void *)&j_efOut, (void *)efOut.mField0,
    (void *)efOut.mField1, (void *)efOut.mField2, (void *)efOut.mField3, (void *)
    efOut.mField4, (void *)efOut.mField5, (void *)nonscalar3, (void *)nonscalar4,
    (void *)t21, (void *)&_in1ivar);
  _in1ivar = 6ULL;
  tlu2_1d_akima_linear_value((void *)&k_efOut, (void *)b_efOut.mField0, (void *)
    b_efOut.mField1, (void *)b_efOut.mField2, (void *)b_efOut.mField3, (void *)
    b_efOut.mField4, (void *)b_efOut.mField5, (void *)nonscalar1, (void *)
    nonscalar2, (void *)t22, (void *)&_in1ivar);
  _in1ivar = 6ULL;
  tlu2_1d_akima_linear_derivatives((void *)&l_efOut, (void *)b_efOut.mField0,
    (void *)b_efOut.mField1, (void *)b_efOut.mField2, (void *)b_efOut.mField3,
    (void *)b_efOut.mField4, (void *)b_efOut.mField5, (void *)nonscalar1, (void *)
    nonscalar2, (void *)t23, (void *)&_in1ivar);
  _in1ivar = 6ULL;
  tlu2_1d_akima_linear_value((void *)&m_efOut, (void *)b_efOut.mField0, (void *)
    b_efOut.mField1, (void *)b_efOut.mField2, (void *)b_efOut.mField3, (void *)
    b_efOut.mField4, (void *)b_efOut.mField5, (void *)nonscalar3, (void *)
    nonscalar4, (void *)t24, (void *)&_in1ivar);
  _in1ivar = 6ULL;
  tlu2_1d_akima_linear_derivatives((void *)&n_efOut, (void *)b_efOut.mField0,
    (void *)b_efOut.mField1, (void *)b_efOut.mField2, (void *)b_efOut.mField3,
    (void *)b_efOut.mField4, (void *)b_efOut.mField5, (void *)nonscalar3, (void *)
    nonscalar4, (void *)t25, (void *)&_in1ivar);
  _in1ivar = 6ULL;
  tlu2_1d_akima_linear_value((void *)&o_efOut, (void *)c_efOut.mField0, (void *)
    c_efOut.mField1, (void *)c_efOut.mField2, (void *)c_efOut.mField3, (void *)
    c_efOut.mField4, (void *)c_efOut.mField5, (void *)nonscalar6, (void *)
    nonscalar7, (void *)t26, (void *)&_in1ivar);
  _in1ivar = 6ULL;
  tlu2_1d_akima_linear_derivatives((void *)&p_efOut, (void *)c_efOut.mField0,
    (void *)c_efOut.mField1, (void *)c_efOut.mField2, (void *)c_efOut.mField3,
    (void *)c_efOut.mField4, (void *)c_efOut.mField5, (void *)nonscalar6, (void *)
    nonscalar7, (void *)t27, (void *)&_in1ivar);
  _in1ivar = 6ULL;
  tlu2_1d_akima_linear_value((void *)&q_efOut, (void *)c_efOut.mField0, (void *)
    c_efOut.mField1, (void *)c_efOut.mField2, (void *)c_efOut.mField3, (void *)
    c_efOut.mField4, (void *)c_efOut.mField5, (void *)nonscalar8, (void *)
    nonscalar9, (void *)t28, (void *)&_in1ivar);
  _in1ivar = 6ULL;
  tlu2_1d_akima_linear_derivatives((void *)&r_efOut, (void *)c_efOut.mField0,
    (void *)c_efOut.mField1, (void *)c_efOut.mField2, (void *)c_efOut.mField3,
    (void *)c_efOut.mField4, (void *)c_efOut.mField5, (void *)nonscalar8, (void *)
    nonscalar9, (void *)t29, (void *)&_in1ivar);
  _in1ivar = 6ULL;
  tlu2_1d_akima_linear_value((void *)&s_efOut, (void *)d_efOut.mField0, (void *)
    d_efOut.mField1, (void *)d_efOut.mField2, (void *)d_efOut.mField3, (void *)
    d_efOut.mField4, (void *)d_efOut.mField5, (void *)nonscalar6, (void *)
    nonscalar7, (void *)t30, (void *)&_in1ivar);
  _in1ivar = 6ULL;
  tlu2_1d_akima_linear_derivatives((void *)&t_efOut, (void *)d_efOut.mField0,
    (void *)d_efOut.mField1, (void *)d_efOut.mField2, (void *)d_efOut.mField3,
    (void *)d_efOut.mField4, (void *)d_efOut.mField5, (void *)nonscalar6, (void *)
    nonscalar7, (void *)t31, (void *)&_in1ivar);
  _in1ivar = 6ULL;
  tlu2_1d_akima_linear_value((void *)&u_efOut, (void *)d_efOut.mField0, (void *)
    d_efOut.mField1, (void *)d_efOut.mField2, (void *)d_efOut.mField3, (void *)
    d_efOut.mField4, (void *)d_efOut.mField5, (void *)nonscalar8, (void *)
    nonscalar9, (void *)t32, (void *)&_in1ivar);
  _in1ivar = 6ULL;
  tlu2_1d_akima_linear_derivatives((void *)&v_efOut, (void *)d_efOut.mField0,
    (void *)d_efOut.mField1, (void *)d_efOut.mField2, (void *)d_efOut.mField3,
    (void *)d_efOut.mField4, (void *)d_efOut.mField5, (void *)nonscalar8, (void *)
    nonscalar9, (void *)t33, (void *)&_in1ivar);
  _in1ivar = 6ULL;
  tlu2_1d_akima_linear_value((void *)&w_efOut, (void *)e_efOut.mField0, (void *)
    e_efOut.mField1, (void *)e_efOut.mField2, (void *)e_efOut.mField3, (void *)
    e_efOut.mField4, (void *)e_efOut.mField5, (void *)nonscalar11, (void *)
    nonscalar12, (void *)t34, (void *)&_in1ivar);
  _in1ivar = 6ULL;
  tlu2_1d_akima_linear_derivatives((void *)&x_efOut, (void *)e_efOut.mField0,
    (void *)e_efOut.mField1, (void *)e_efOut.mField2, (void *)e_efOut.mField3,
    (void *)e_efOut.mField4, (void *)e_efOut.mField5, (void *)nonscalar11, (void
    *)nonscalar12, (void *)t35, (void *)&_in1ivar);
  _in1ivar = 6ULL;
  tlu2_1d_akima_linear_value((void *)&y_efOut, (void *)e_efOut.mField0, (void *)
    e_efOut.mField1, (void *)e_efOut.mField2, (void *)e_efOut.mField3, (void *)
    e_efOut.mField4, (void *)e_efOut.mField5, (void *)nonscalar13, (void *)
    nonscalar14, (void *)t36, (void *)&_in1ivar);
  _in1ivar = 6ULL;
  tlu2_1d_akima_linear_derivatives((void *)&ab_efOut, (void *)e_efOut.mField0,
    (void *)e_efOut.mField1, (void *)e_efOut.mField2, (void *)e_efOut.mField3,
    (void *)e_efOut.mField4, (void *)e_efOut.mField5, (void *)nonscalar13, (void
    *)nonscalar14, (void *)t37, (void *)&_in1ivar);
  _in1ivar = 6ULL;
  tlu2_1d_akima_linear_value((void *)&bb_efOut, (void *)f_efOut.mField0, (void *)
    f_efOut.mField1, (void *)f_efOut.mField2, (void *)f_efOut.mField3, (void *)
    f_efOut.mField4, (void *)f_efOut.mField5, (void *)nonscalar11, (void *)
    nonscalar12, (void *)t38, (void *)&_in1ivar);
  _in1ivar = 6ULL;
  tlu2_1d_akima_linear_derivatives((void *)&cb_efOut, (void *)f_efOut.mField0,
    (void *)f_efOut.mField1, (void *)f_efOut.mField2, (void *)f_efOut.mField3,
    (void *)f_efOut.mField4, (void *)f_efOut.mField5, (void *)nonscalar11, (void
    *)nonscalar12, (void *)t39, (void *)&_in1ivar);
  _in1ivar = 6ULL;
  tlu2_1d_akima_linear_value((void *)&db_efOut, (void *)f_efOut.mField0, (void *)
    f_efOut.mField1, (void *)f_efOut.mField2, (void *)f_efOut.mField3, (void *)
    f_efOut.mField4, (void *)f_efOut.mField5, (void *)nonscalar13, (void *)
    nonscalar14, (void *)t40, (void *)&_in1ivar);
  _in1ivar = 6ULL;
  tlu2_1d_akima_linear_derivatives((void *)&eb_efOut, (void *)f_efOut.mField0,
    (void *)f_efOut.mField1, (void *)f_efOut.mField2, (void *)f_efOut.mField3,
    (void *)f_efOut.mField4, (void *)f_efOut.mField5, (void *)nonscalar13, (void
    *)nonscalar14, (void *)t41, (void *)&_in1ivar);
  out.mX[0] = -(g_efOut[0] * (U_idx_0 / 185.35396656179779 *
    0.010790165633348838) + h_efOut[0] * X_idx_8 * t116 * (U_idx_0 /
    185.35396656179779 * (U_idx_0 / 185.35396656179779) * 1000.0 / 1000.0));
  out.mX[1] = -((i_efOut[0] * (U_idx_0 * 3.140684727571903E-7) + j_efOut[0] *
                 X_idx_8 * t116 * (U_idx_0 * U_idx_0 / 6.3680380983232958E+6 *
    1000.0 / 1000.0)) * 1000.0);
  out.mX[2] = -(k_efOut[0] * (U_idx_1 / 185.35396656179779 *
    0.010790165633348838) + l_efOut[0] * X_idx_9 * t95 * (U_idx_1 /
    185.35396656179779 * (U_idx_1 / 185.35396656179779) * 1000.0 / 1000.0));
  out.mX[3] = -((m_efOut[0] * (U_idx_1 * 3.140684727571903E-7) + n_efOut[0] *
                 X_idx_9 * t95 * (U_idx_1 * U_idx_1 / 6.3680380983232958E+6 *
    1000.0 / 1000.0)) * 1000.0);
  out.mX[4] = -(o_efOut[0] * (U_idx_2 / 185.35396656179779 *
    0.010790165633348838) + p_efOut[0] * X_idx_12 * t104 * (U_idx_2 /
    185.35396656179779 * (U_idx_2 / 185.35396656179779) * 1000.0 / 1000.0));
  out.mX[5] = -((q_efOut[0] * (U_idx_2 * 3.140684727571903E-7) + r_efOut[0] *
                 X_idx_12 * t104 * (U_idx_2 * U_idx_2 / 6.3680380983232958E+6 *
    1000.0 / 1000.0)) * 1000.0);
  out.mX[6] = -(s_efOut[0] * (U_idx_3 / 185.35396656179779 *
    0.010790165633348838) + t_efOut[0] * X_idx_13 * t107 * (U_idx_3 /
    185.35396656179779 * (U_idx_3 / 185.35396656179779) * 1000.0 / 1000.0));
  out.mX[7] = -((u_efOut[0] * (U_idx_3 * 3.140684727571903E-7) + v_efOut[0] *
                 X_idx_13 * t107 * (U_idx_3 * U_idx_3 / 6.3680380983232958E+6 *
    1000.0 / 1000.0)) * 1000.0);
  out.mX[8] = -(w_efOut[0] * (U_idx_4 / 185.35396656179779 *
    0.010790165633348838) + x_efOut[0] * X_idx_17 * intermediate_der72 *
                (U_idx_4 / 185.35396656179779 * (U_idx_4 / 185.35396656179779) *
                 1000.0 / 1000.0));
  out.mX[9] = -((y_efOut[0] * (U_idx_4 * 3.140684727571903E-7) + ab_efOut[0] *
                 X_idx_17 * intermediate_der72 * (U_idx_4 * U_idx_4 /
    6.3680380983232958E+6 * 1000.0 / 1000.0)) * 1000.0);
  out.mX[10] = -(bb_efOut[0] * (U_idx_5 / 185.35396656179779 *
    0.010790165633348838) + cb_efOut[0] * X_idx_18 * t113 * (U_idx_5 /
    185.35396656179779 * (U_idx_5 / 185.35396656179779) * 1000.0 / 1000.0));
  out.mX[11] = -((db_efOut[0] * (U_idx_5 * 3.140684727571903E-7) + eb_efOut[0] *
                  X_idx_18 * t113 * (U_idx_5 * U_idx_5 / 6.3680380983232958E+6 *
    1000.0 / 1000.0)) * 1000.0);
  (void)sys;
  (void)t157;
  return 0;
}
