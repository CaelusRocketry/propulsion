/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'sh_water_supply_system/Solver Configuration'.
 */

#include "ne_ds.h"
#include "sh_water_supply_system_900c0b92_1_ds_dnf_p.h"
#include "sh_water_supply_system_900c0b92_1_ds_sys_struct.h"
#include "sh_water_supply_system_900c0b92_1_ds_externals.h"
#include "sh_water_supply_system_900c0b92_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T sh_water_supply_system_900c0b92_1_ds_dnf_p(const NeDynamicSystem *sys,
  const NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  int32_T b;
  static int32_T _cg_const_1[109] = { 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 3, 3, 4,
    4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 6, 7, 7, 8, 9, 9, 9, 9, 9, 11, 11, 11, 11,
    11, 11, 11, 11, 13, 13, 14, 14, 14, 14, 14, 14, 14, 14, 15, 15, 15, 15, 15,
    15, 15, 15, 15, 16, 16, 16, 16, 18, 18, 18, 18, 18, 19, 19, 20, 22, 22, 22,
    23, 23, 24, 24, 24, 24, 24, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
    26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 27, 28, 28, 28 };

  (void)t1;
  out = t2->mDNF_P;
  out.mNumCol = 108ULL;
  out.mNumRow = 44ULL;
  for (b = 0; b < 109; b++) {
    out.mJc[b] = _cg_const_1[b];
  }

  out.mIr[0] = 11;
  out.mIr[1] = 12;
  out.mIr[2] = 10;
  out.mIr[3] = 9;
  out.mIr[4] = 7;
  out.mIr[5] = 6;
  out.mIr[6] = 42;
  out.mIr[7] = 41;
  out.mIr[8] = 40;
  out.mIr[9] = 33;
  out.mIr[10] = 34;
  out.mIr[11] = 31;
  out.mIr[12] = 32;
  out.mIr[13] = 4;
  out.mIr[14] = 5;
  out.mIr[15] = 24;
  out.mIr[16] = 13;
  out.mIr[17] = 14;
  out.mIr[18] = 30;
  out.mIr[19] = 35;
  out.mIr[20] = 22;
  out.mIr[21] = 23;
  out.mIr[22] = 8;
  out.mIr[23] = 15;
  out.mIr[24] = 20;
  out.mIr[25] = 21;
  out.mIr[26] = 29;
  out.mIr[27] = 43;
  (void)sys;
  (void)t2;
  return 0;
}
