/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'sh_water_supply_system/Solver Configuration'.
 */

#include "ne_ds.h"
#include "sh_water_supply_system_900c0b92_1_ds_dxf_p.h"
#include "sh_water_supply_system_900c0b92_1_ds_sys_struct.h"
#include "sh_water_supply_system_900c0b92_1_ds_externals.h"
#include "sh_water_supply_system_900c0b92_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T sh_water_supply_system_900c0b92_1_ds_dxf_p(const NeDynamicSystem *sys,
  const NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mDXF_P;
  out.mNumCol = 44ULL;
  out.mNumRow = 44ULL;
  out.mJc[0] = 0;
  out.mJc[1] = 0;
  out.mJc[2] = 0;
  out.mJc[3] = 0;
  out.mJc[4] = 0;
  out.mJc[5] = 0;
  out.mJc[6] = 0;
  out.mJc[7] = 0;
  out.mJc[8] = 0;
  out.mJc[9] = 10;
  out.mJc[10] = 20;
  out.mJc[11] = 20;
  out.mJc[12] = 20;
  out.mJc[13] = 29;
  out.mJc[14] = 38;
  out.mJc[15] = 38;
  out.mJc[16] = 38;
  out.mJc[17] = 38;
  out.mJc[18] = 46;
  out.mJc[19] = 54;
  out.mJc[20] = 56;
  out.mJc[21] = 56;
  out.mJc[22] = 56;
  out.mJc[23] = 56;
  out.mJc[24] = 56;
  out.mJc[25] = 56;
  out.mJc[26] = 58;
  out.mJc[27] = 58;
  out.mJc[28] = 58;
  out.mJc[29] = 58;
  out.mJc[30] = 58;
  out.mJc[31] = 58;
  out.mJc[32] = 58;
  out.mJc[33] = 58;
  out.mJc[34] = 60;
  out.mJc[35] = 60;
  out.mJc[36] = 60;
  out.mJc[37] = 60;
  out.mJc[38] = 60;
  out.mJc[39] = 60;
  out.mJc[40] = 60;
  out.mJc[41] = 60;
  out.mJc[42] = 62;
  out.mJc[43] = 62;
  out.mJc[44] = 62;
  out.mIr[0] = 4;
  out.mIr[1] = 5;
  out.mIr[2] = 7;
  out.mIr[3] = 9;
  out.mIr[4] = 10;
  out.mIr[5] = 11;
  out.mIr[6] = 12;
  out.mIr[7] = 15;
  out.mIr[8] = 16;
  out.mIr[9] = 17;
  out.mIr[10] = 4;
  out.mIr[11] = 5;
  out.mIr[12] = 7;
  out.mIr[13] = 9;
  out.mIr[14] = 10;
  out.mIr[15] = 13;
  out.mIr[16] = 14;
  out.mIr[17] = 15;
  out.mIr[18] = 18;
  out.mIr[19] = 19;
  out.mIr[20] = 6;
  out.mIr[21] = 7;
  out.mIr[22] = 9;
  out.mIr[23] = 20;
  out.mIr[24] = 21;
  out.mIr[25] = 24;
  out.mIr[26] = 25;
  out.mIr[27] = 26;
  out.mIr[28] = 29;
  out.mIr[29] = 6;
  out.mIr[30] = 7;
  out.mIr[31] = 9;
  out.mIr[32] = 22;
  out.mIr[33] = 23;
  out.mIr[34] = 24;
  out.mIr[35] = 27;
  out.mIr[36] = 28;
  out.mIr[37] = 29;
  out.mIr[38] = 8;
  out.mIr[39] = 9;
  out.mIr[40] = 30;
  out.mIr[41] = 31;
  out.mIr[42] = 32;
  out.mIr[43] = 35;
  out.mIr[44] = 36;
  out.mIr[45] = 37;
  out.mIr[46] = 8;
  out.mIr[47] = 9;
  out.mIr[48] = 30;
  out.mIr[49] = 33;
  out.mIr[50] = 34;
  out.mIr[51] = 35;
  out.mIr[52] = 38;
  out.mIr[53] = 39;
  out.mIr[54] = 3;
  out.mIr[55] = 43;
  out.mIr[56] = 0;
  out.mIr[57] = 40;
  out.mIr[58] = 1;
  out.mIr[59] = 41;
  out.mIr[60] = 2;
  out.mIr[61] = 42;
  (void)sys;
  (void)t2;
  return 0;
}
