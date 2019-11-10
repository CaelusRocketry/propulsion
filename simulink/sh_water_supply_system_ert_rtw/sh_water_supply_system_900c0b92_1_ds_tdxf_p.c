/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'sh_water_supply_system/Solver Configuration'.
 */

#include "ne_ds.h"
#include "sh_water_supply_system_900c0b92_1_ds_tdxf_p.h"
#include "sh_water_supply_system_900c0b92_1_ds_sys_struct.h"
#include "sh_water_supply_system_900c0b92_1_ds_externals.h"
#include "sh_water_supply_system_900c0b92_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T sh_water_supply_system_900c0b92_1_ds_tdxf_p(const NeDynamicSystem *sys,
  const NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  int32_T b;
  static int32_T _cg_const_2[140] = { 4, 11, 13, 4, 10, 4, 6, 7, 4, 5, 4, 5, 7,
    9, 10, 11, 12, 15, 16, 17, 40, 43, 4, 5, 7, 9, 10, 13, 14, 15, 18, 19, 40,
    43, 6, 20, 22, 6, 29, 6, 7, 9, 20, 21, 24, 25, 26, 29, 41, 43, 6, 7, 9, 22,
    23, 24, 27, 28, 29, 41, 43, 7, 8, 9, 8, 31, 33, 8, 30, 8, 9, 30, 31, 32, 35,
    36, 37, 42, 43, 8, 9, 30, 33, 34, 35, 38, 39, 42, 43, 3, 9, 43, 11, 13, 15,
    11, 12, 11, 16, 13, 14, 13, 18, 0, 15, 40, 17, 19, 20, 22, 24, 20, 21, 20,
    25, 22, 23, 22, 27, 1, 24, 41, 26, 28, 31, 33, 35, 31, 32, 31, 36, 33, 34,
    33, 38, 2, 35, 42, 37, 39 };

  (void)t1;
  out = t2->mTDXF_P;
  out.mNumCol = 44ULL;
  out.mNumRow = 44ULL;
  out.mJc[0] = 0;
  out.mJc[1] = 0;
  out.mJc[2] = 0;
  out.mJc[3] = 0;
  out.mJc[4] = 0;
  out.mJc[5] = 3;
  out.mJc[6] = 5;
  out.mJc[7] = 8;
  out.mJc[8] = 10;
  out.mJc[9] = 22;
  out.mJc[10] = 34;
  out.mJc[11] = 37;
  out.mJc[12] = 39;
  out.mJc[13] = 50;
  out.mJc[14] = 61;
  out.mJc[15] = 64;
  out.mJc[16] = 67;
  out.mJc[17] = 69;
  out.mJc[18] = 79;
  out.mJc[19] = 89;
  out.mJc[20] = 92;
  out.mJc[21] = 95;
  out.mJc[22] = 97;
  out.mJc[23] = 99;
  out.mJc[24] = 101;
  out.mJc[25] = 103;
  out.mJc[26] = 106;
  out.mJc[27] = 107;
  out.mJc[28] = 108;
  out.mJc[29] = 111;
  out.mJc[30] = 113;
  out.mJc[31] = 115;
  out.mJc[32] = 117;
  out.mJc[33] = 119;
  out.mJc[34] = 122;
  out.mJc[35] = 123;
  out.mJc[36] = 124;
  out.mJc[37] = 127;
  out.mJc[38] = 129;
  out.mJc[39] = 131;
  out.mJc[40] = 133;
  out.mJc[41] = 135;
  out.mJc[42] = 138;
  out.mJc[43] = 139;
  out.mJc[44] = 140;
  for (b = 0; b < 140; b++) {
    out.mIr[b] = _cg_const_2[b];
  }

  (void)sys;
  (void)t2;
  return 0;
}
